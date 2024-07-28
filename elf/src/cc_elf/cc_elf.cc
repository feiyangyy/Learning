#define __USE_MISC 1
#include <elf.h>
#include "cc_elf.h"
#include <stdlib.h>
#include <alloca.h>

#include <stdlib.h>
#include <stdarg.h>
#include <alloca.h>
#include <string.h>
#include <syscall.h>

#include <sys/mman.h>
#include <vector>

// 页大小
#define PAGE_SIZE	4096
// 对其字节
#define ALIGN		(PAGE_SIZE - 1)
// 应该是向上取整
#define ROUND_PG(x)	(((x) + (ALIGN)) & ~(ALIGN))
// 向下取整
#define TRUNC_PG(x)	((x) & ~(ALIGN))

#define PFLAGS(x)	((((x) & PF_R) ? PROT_READ : 0) | \
			 (((x) & PF_W) ? PROT_WRITE : 0) | \
			 (((x) & PF_X) ? PROT_EXEC : 0))
#define LOAD_ERR	((unsigned long)-1)


#define Elf_Ehdr Elf64_Ehdr
// 这个交程序头
#define Elf_Phdr Elf64_Phdr
// 辅助向量，是协助程序运行的一组kv 键值对
#define Elf_auxv_t Elf64_auxv_t
// ELF 类型
#define ELFCLASS ELFCLASS64

CCElf::CCElf(const std::string& name){
  file_name_ = name;
}

CCElf::~CCElf() {

}

bool CCElf::Open(){
#if 0
  f_pointer_ = fopen(file_name_.c_str(), "rb");
  if (!f_pointer_) {
    return false;
  }
#endif
  return true;
}

bool CCElf::CheckHeader(Elf_Ehdr* hdr, FILE* fp) {
  
  std::size_t header_size = sizeof(Elf_Ehdr);
  int64_t read_n = fread(hdr, header_size, 1, fp);
  if(read_n != header_size) {
    return false;
  }
  unsigned char *e_ident = hdr->e_ident;
  // 检查幻数和内容
  // 0x7f "elf" and xxx
  return (e_ident[EI_MAG0] != ELFMAG0 || e_ident[EI_MAG1] != ELFMAG1 ||
          e_ident[EI_MAG2] != ELFMAG2 || e_ident[EI_MAG3] != ELFMAG3 ||
          e_ident[EI_CLASS] != ELFCLASS ||
          e_ident[EI_VERSION] != EV_CURRENT ||
          (hdr->e_type != ET_EXEC && hdr->e_type != ET_DYN)) // 可执行文件或者动态库文件
             ? 0
             : 1;
  return true;
}

#ifndef __builtin_alloca
  #define __builtin_alloca malloc
#endif


#define SYSCALL(name, ...)  check_error(z_syscall(SYS_##name, __VA_ARGS__))

#define DEF_SYSCALL1(ret, name, t1, a1) \
ret z_##name(t1 a1) \
{ \
	return (ret)SYSCALL(name, a1); \
}
#define DEF_SYSCALL2(ret, name, t1, a1, t2, a2) \
ret z_##name(t1 a1, t2 a2) \
{ \
	return (ret)SYSCALL(name, a1, a2); \
}
#define DEF_SYSCALL3(ret, name, t1, a1, t2, a2, t3, a3) \
ret z_##name(t1 a1, t2 a2, t3 a3) \
{ \
	return (ret)SYSCALL(name, a1, a2, a3); \
}




bool CCElf::LoadElfAon(void* p_phdr, Elf_Ehdr* p_ehdr,FILE* fp, uint32_t nb_program_hdr, void*& pout) {
  Elf_Ehdr& header_ = *p_ehdr;
  bool is_dyn = header_.e_type == ET_DYN;
  uint64_t min_va, max_va;
  min_va = (uint64_t)-1;
  max_va = 0;
  Elf_Phdr* p_prog_hdr = reinterpret_cast<Elf_Phdr*>(p_phdr);
  for(int idx = 0; idx< header_.e_phnum; ++idx) {
    auto pp_prog = &p_prog_hdr[idx];
    if(pp_prog->p_type != PT_LOAD) {
      continue;
    }
    if(pp_prog->p_vaddr < min_va) {
      min_va = pp_prog->p_vaddr;
    }
    if (pp_prog->p_vaddr + pp_prog->p_memsz > max_va) {
      max_va = pp_prog->p_vaddr + pp_prog->p_memsz;
    }
  }
  min_va = TRUNC_PG(min_va);
  max_va = ROUND_PG(max_va);
  // 这里的hint 指向起始地址
  uint8_t* hint = is_dyn? nullptr : (uint8_t*)min_va;
  int flags = is_dyn? 0: MAP_FIXED;
  flags |= (MAP_PRIVATE | MAP_ANONYMOUS);
  uint64_t size = max_va - min_va;
  // PROT_NONE 是指没有任何权限
  // 这里映射一下，应该是检查一下能否申请那么大的空间
  // mmap 工作在内核太，向内核申请内存; 而Malloc 工作在用户态，在堆上申请内存, malloc的性能开销要更大一点
  // 这里的hint 是指从这个地方开始创建，如果创建失败就G
  // 这个做法可能不是太可靠。。。
  // 后面这个地址不一定给你用了
  uint8_t* base = (uint8_t*) mmap(hint, size, PROT_NONE, flags, -1, 0);
  if (base == MAP_FAILED) {
    return -1;
  }
  // 取消映射
  munmap(base, size);
  // 注意这里的几个flag 含义
  // MAP_ANONYMOUS == 不喝任何文件关联
  // fixed  在固定的地址创建，如果原始区域有人在用，就覆盖它
  // note: 如果一个东西的背后的机制特别复杂，那么学习曲线可能就会特别陡峭
  flags |= MAP_FIXED |MAP_ANONYMOUS | MAP_PRIVATE;
  uint64_t sz = 0;
  for(int idx = 0; idx < header_.e_phnum; ++idx){
    auto pp_ehdr = &p_prog_hdr[idx];
    if(pp_ehdr->p_type != PT_LOAD) {
      continue;
    }
    // 对齐
    uint64_t off = pp_ehdr->p_vaddr & ALIGN;
    // 如果是动态库要从基地址开始
    // 不过这个base 不是被取消映射了吗
    uint64_t start  = is_dyn? (uint64_t) base : 0;
    start += TRUNC_PG(pp_ehdr->p_vaddr);
    // 大小?
    sz += ROUND_PG(pp_ehdr->p_memsz + off);
    // 可写权限
    // 其实还是要知道这个mmap 映射了个什么东西
    uint8_t* p = (uint8_t*) mmap((uint8_t*) start, sz, PROT_WRITE, flags, -1, 0);
    if (p == (uint8_t*)(-1)) {
      // do something
    }
    if (fseek(fp, pp_ehdr->p_offset, SEEK_SET)< 0) {
      // do sth.
    }
    if (fread(p + off, pp_ehdr->p_filesz, 1, fp) != pp_ehdr->p_filesz) {
      // do sth.
    }
    // 更改映射区域的内存属性，这里的flags 是文件中指定的
    mprotect(p, sz, PFLAGS(pp_ehdr->p_flags));
  }
  // 返回内存区域?
  pout = base;
  return true;
err:
  munmap(base, max_va - min_va);
  return false;
}

#if 0
#define	PT_NULL		0		/* Program header table entry unused */
#define PT_LOAD		1		/* Loadable program segment */
#define PT_DYNAMIC	2		/* Dynamic linking information */
#define PT_INTERP	3		/* Program interpreter */
#define PT_NOTE		4		/* Auxiliary information */
#define PT_SHLIB	5		/* Reserved */
#define PT_PHDR		6		/* Entry for header table itself */
#define PT_TLS		7		/* Thread-local storage segment */
#define	PT_NUM		8		/* Number of defined types */
#define PT_LOOS		0x60000000	/* Start of OS-specific */
#define PT_GNU_EH_FRAME	0x6474e550	/* GCC .eh_frame_hdr segment */
#define PT_GNU_STACK	0x6474e551	/* Indicates stack executability */
#define PT_GNU_RELRO	0x6474e552	/* Read-only after relocation */
#define PT_GNU_PROPERTY	0x6474e553	/* GNU property */
#define PT_LOSUNW	0x6ffffffa
#define PT_SUNWBSS	0x6ffffffa	/* Sun Specific segment */
#define PT_SUNWSTACK	0x6ffffffb	/* Stack segment */
#define PT_HISUNW	0x6fffffff
#define PT_HIOS		0x6fffffff	/* End of OS-specific */
#define PT_LOPROC	0x70000000	/* Start of processor-specific */
#define PT_HIPROC	0x7fffffff	/* End of processor-specific */
#endif

bool CCElf::LoadProgramHeaders(const std::string& file_name) {
  FILE*  f_pointer_ = fopen(file_name_.c_str(), "rb");
  if (!f_pointer_) {
    return false;
  }
  Elf_Ehdr header_;
  if(!CheckHeader(&header_, f_pointer_)){
    printf("Check header failed!\n");
    fclose(f_pointer_);
    return false;
  }
  
  int nb_program_header = header_.e_phnum;
  // alloca_builtin 在栈上申请内存，使用完毕后，无需释放
  uint32_t  sz_mem_buffer = sizeof(Elf_Phdr) * nb_program_header;
  Elf_Phdr* p_phdr = static_cast<Elf_Phdr*>(__builtin_alloca(sz_mem_buffer));
  /*
    一共三个flag:
    SEEK_SET: 从头开始
    SEEK_CUR: 从当前开始
    SEEK_END: 从末尾
  */
  if (fseek(f_pointer_,  header_.e_phoff, SEEK_SET) < 0) {
    printf("Failed to seek to %x\n", header_.e_phoff);
    fclose(f_pointer_);
    return false;
  }
  if (fread(p_phdr, sz_mem_buffer, 1, f_pointer_) < sz_mem_buffer) {
    printf("Failed to read program headers!\n");
    fclose(f_pointer_);
    return false;
  }
  bool cur_loading_file = file_name == this->file_name_;
  void*& p_base = cur_loading_file ? file_base_ : interp_base_;
  void*& entry = cur_loading_file ? file_entry_ : interp_entry;

  LoadElfAon(p_phdr, &header_, f_pointer_, nb_program_header, p_base);
  entry = reinterpret_cast<void*>(header_.e_entry + (header_.e_type == ET_DYN ? (uint64_t)p_base : 0));
  // entry

  for(int idx = 0; idx< nb_program_header; ++idx) {
    auto ptr = &p_phdr[idx];
    if(ptr->p_type != PT_INTERP) {
      continue;
    }
    std::vector<char> file_name_buffer(ptr->p_filesz, 0x0);
    // this->inter_file_name_.resize(ptr->p_filesz);
    if(fseek(f_pointer_, ptr->p_offset, SEEK_SET) < 0) {
      printf("Seek for interp failed!\n");
    }
    if(fread(file_name_buffer.data(), ptr->p_filesz, 1, f_pointer_) != ptr->p_filesz) {
      printf("Failed to read interp name!\n");
    }
    if(file_name_buffer.back() != '\0') {
      printf("Invalid interp path!\n");
    }
    // copy it.
    this->inter_file_name_ =  file_name_buffer.data();
    printf("Found interp name:%s \n", inter_file_name_.c_str());
  }
  return true;
}

bool CCElf::Load(std::vector<std::string> args) {
  if(!LoadProgramHeaders(this->file_name_)) {
    printf("Load file %s failed!\n", file_name_.c_str());
    return false;
  }

  if(this->inter_file_name_ == "") {
    printf("Failed to find interp file!\n");
    return false;
  }

  if(!LoadProgramHeaders(this->inter_file_name_)) {
    printf("Load file %s failed!\n", inter_file_name_);
    return false;
  }
  int argc = static_cast<int>(args.size());
  char** p_argv = new char* [argc];
  #if 0
  for(int idx = 0; idx< argc;++idx) {
    p_argv[idx] = 
  }
  #endif
  char** argv = p_argv;
  
}