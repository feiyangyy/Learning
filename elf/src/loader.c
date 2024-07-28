#include "z_asm.h"
#include "z_syscalls.h"
#include "z_utils.h"
#include "z_elf.h"

#define PAGE_SIZE	4096
#define ALIGN		(PAGE_SIZE - 1)
#define ROUND_PG(x)	(((x) + (ALIGN)) & ~(ALIGN))
#define TRUNC_PG(x)	((x) & ~(ALIGN))
#define PFLAGS(x)	((((x) & PF_R) ? PROT_READ : 0) | \
			 (((x) & PF_W) ? PROT_WRITE : 0) | \
			 (((x) & PF_X) ? PROT_EXEC : 0))
#define LOAD_ERR	((unsigned long)-1)

static void z_fini(void)
{
	z_printf("Fini at work\n");
}

// 投标检查
static int check_ehdr(Elf_Ehdr *ehdr)
{
	unsigned char *e_ident = ehdr->e_ident;
	return (e_ident[EI_MAG0] != ELFMAG0 || e_ident[EI_MAG1] != ELFMAG1 ||
		e_ident[EI_MAG2] != ELFMAG2 || e_ident[EI_MAG3] != ELFMAG3 ||
	    	e_ident[EI_CLASS] != ELFCLASS ||
		e_ident[EI_VERSION] != EV_CURRENT ||
		(ehdr->e_type != ET_EXEC && ehdr->e_type != ET_DYN)) ? 0 : 1;
}

static unsigned long loadelf_anon(int fd, Elf_Ehdr *ehdr, Elf_Phdr *phdr)
{
	unsigned long minva, maxva;
	Elf_Phdr *iter;
	ssize_t sz;
	// 检查是不是动态库
	int flags, dyn = ehdr->e_type == ET_DYN;
	unsigned char *p, *base, *hint;
	// 这里的va 应该是virtual address 的意思
	minva = (unsigned long)-1;
	maxva = 0;
	// 遍历，这里注意指针用法
	for (iter = phdr; iter < &phdr[ehdr->e_phnum]; iter++) {
		if (iter->p_type != PT_LOAD)
			continue;
		if (iter->p_vaddr < minva)
			minva = iter->p_vaddr;
		if (iter->p_vaddr + iter->p_memsz > maxva)
			maxva = iter->p_vaddr + iter->p_memsz;
	}
	// 向下取整
	minva = TRUNC_PG(minva);
	// 向上取整
	maxva = ROUND_PG(maxva);

	/* For dynamic ELF let the kernel chose the address. */	
	hint = dyn ? NULL : (void *)minva;
	flags = dyn ? 0 : MAP_FIXED;
	flags |= (MAP_PRIVATE | MAP_ANONYMOUS);

	/* Check that we can hold the whole image. */
	// 后面已经Unmap了，为什么还能用n呢
	
	base = z_mmap(hint, maxva - minva, PROT_NONE, flags, -1, 0);
	if (base == (void *)-1)
		return -1;
	z_munmap(base, maxva - minva);

	flags = MAP_FIXED | MAP_ANONYMOUS | MAP_PRIVATE;
	/* Now map each segment separately in precalculated address. */
	for (iter = phdr; iter < &phdr[ehdr->e_phnum]; iter++) {
		unsigned long off, start;
		if (iter->p_type != PT_LOAD)
			continue;
		off = iter->p_vaddr & ALIGN;
		start = dyn ? (unsigned long)base : 0;
		start += TRUNC_PG(iter->p_vaddr);
		sz = ROUND_PG(iter->p_memsz + off);

		p = z_mmap((void *)start, sz, PROT_WRITE, flags, -1, 0);
		if (p == (void *)-1)
			goto err;
		if (z_lseek(fd, iter->p_offset, SEEK_SET) < 0)
			goto err;
		if (z_read(fd, p + off, iter->p_filesz) !=
				(ssize_t)iter->p_filesz)
			goto err;
		z_mprotect(p, sz, PFLAGS(iter->p_flags));
	}

	return (unsigned long)base;
err:
	z_munmap(base, maxva - minva);
	return LOAD_ERR;
}

#define Z_PROG		0
#define Z_INTERP	1
#if 0
typedef struct
{
  unsigned char	e_ident[EI_NIDENT];	/* Magic number and other info 幻数*/ 
  Elf64_Half	e_type;			/* Object file type 文件类型*/
  Elf64_Half	e_machine;		/* Architecture 架构*/
  Elf64_Word	e_version;		/* Object file version 版本*/
  Elf64_Addr	e_entry;		/* Entry point virtual address 虚拟地址的入口点*/
  Elf64_Off	e_phoff;		/* Program header table file offset htb ofset*/
  Elf64_Off	e_shoff;		/* Section header table file offset */
  Elf64_Word	e_flags;		/* Processor-specific flags */
  Elf64_Half	e_ehsize;		/* ELF header size in bytes */
  Elf64_Half	e_phentsize;		/* Program header table entry size */
  Elf64_Half	e_phnum;		/* Program header table entry count */
  Elf64_Half	e_shentsize;		/* Section header table entry size */
  Elf64_Half	e_shnum;		/* Section header table entry count */
  Elf64_Half	e_shstrndx;		/* Section header string table index */
} Elf64_Ehdr;

e_ident:

类型: unsigned char[e_ident[EI_NIDENT]]
描述: 包含魔数和其他信息，用于标识 ELF 文件的类型和版本。前四个字节是魔数（0x7f, 'E', 'L', 'F'），后续字节包含文件的类（32位或64位）、数据编码（大端或小端）、版本等信息。
e_type:

类型: Elf64_Half
描述: 表示对象文件的类型，例如可执行文件、共享库、目标文件等。
e_machine:

类型: Elf64_Half
描述: 指定文件所支持的体系结构，例如 x86、ARM 等。
e_version:

类型: Elf64_Word
描述: 表示对象文件的版本，通常为 1。
e_entry:

类型: Elf64_Addr
描述: 程序的入口点虚拟地址，即程序开始执行的地址。
e_phoff:

类型: Elf64_Off
描述: 程序头表在文件中的偏移量，用于查找程序的各个段。
e_shoff:

类型: Elf64_Off
描述: 节头表在文件中的偏移量，用于查找文件的各个节。
e_flags:

类型: Elf64_Word
描述: 处理器特定的标志，表示文件的一些特性。
e_ehsize:

类型: Elf64_Half
描述: ELF 头部的大小（以字节为单位）。
e_phentsize:

类型: Elf64_Half
描述: 程序头表中每个条目的大小（以字节为单位）。
e_phnum:

类型: Elf64_Half
描述: 程序头表中的条目数量。
e_shentsize:

类型: Elf64_Half
描述: 节头表中每个条目的大小（以字节为单位）。
e_shnum:

类型: Elf64_Half
描述: 节头表中的条目数量。
e_shstrndx:

类型: Elf64_Half
描述: 字符串表的索引，用于存储节的名称。
#endif
// 这里的sp 和fini 比较特殊
#define ALIGNMENT 16 // 对齐要求
#define Z_STK_SIZE (8*1024*1024)

void* GetStk() {
	int flags = (MAP_PRIVATE | MAP_ANONYMOUS);
	// 映射之 ...
	void* ptr =  z_mmap(NULL, Z_STK_SIZE + ALIGNMENT - 1, PROT_READ|PROT_WRITE|PROT_EXEC, flags, -1, 0);
	unsigned long aligned_address = ((unsigned long )ptr + ALIGNMENT - 1) & ~(ALIGNMENT - 1);
	if(aligned_address == (unsigned long)ptr) {
		// ====》 走了这个branch, 说明已经align 了
		z_printf("Already align!\n");
	} else {
		z_printf("Done align!\n");
	}
	return (void*)(aligned_address);
}

void z_entry(unsigned long *sp, void (*fini)(void))
{

	// 这里为什么搞两个header?
	Elf_Ehdr ehdrs[2], *ehdr = ehdrs;
	Elf_Phdr *phdr, *iter;
	Elf_auxv_t *av;
	char **argv, **env, **p, *elf_interp = NULL;
	unsigned long base[2], entry[2];
	const char *file;
	ssize_t sz;
	int argc, fd, i;
	// no use
	(void)fini;
	void* cur_sp;
	int sz_total = sizeof(ehdrs) + sizeof(ehdr) + sizeof(phdr) + sizeof(iter) + sizeof(argv) + sizeof(env)+ sizeof(p)
	+ sizeof(elf_interp)+ sizeof(base)+ sizeof(entry)+ sizeof(file)+ sizeof(sz)+ sizeof(argc)+ sizeof(fd)+ sizeof(i)+ sizeof(cur_sp) + sizeof(int);
	int foo_1,foo_2;
	__asm__ volatile ("mov %%rsp, %0" : "=r" (cur_sp));
	int diff = (uint64_t)(sp) - (uint64_t)(cur_sp);
	// 注意这里不能搞void* 步长有问题
	// TODO: 验证下C的void* 步长有多少....
	unsigned long * stk = (unsigned long *)GetStk();
	if(stk == MAP_FAILED) {
		z_errx(-1, "Fucked!\n");
		stk = NULL;
	}
	unsigned long* p_stk = (unsigned long*) stk;
	// 这里的diff 有320字节
	// 不太清楚为什么一直是320B。。。
	z_printf("Cur sp:%x, parameter sp:%x, diff:%d, cur_stack_used=%d\n", (uint64_t)(cur_sp), (uint64_t)(sp), diff, sz_total);
	// 蛋痛
	// 这个是不是他自己在解析这些参数哦
	// 按照参数传递的layout来
	// 这里是最低字节，意味着是栈顶...
	argc = (int)*(sp);
	*(int*)(p_stk) = argc - 1;

	// 注意这里的argv 是Char** 二级指针
	// 所以这里造成一个问题，C++编写的loader 经过层层处理肯定是看不到（传进来的）sp这些东西了
	argv = (char **)(sp + 1);
	// argv的末尾，存储有环境, p的末尾是av
	env = p = (char **)&argv[argc + 1];
	// 该死的++，这里的p是char** 也就是一次迭代sizeof(void*) 个步长
	// 他这里主要是没有处理env， 如果要处理env的话可能更麻烦点
	// 默认一定有一个参数
	int idx = 0;
	// 这里的p 是ENV!!!! fuck!
	while (*p++ != NULL) {
		#if 0
		z_printf("env[%d]:%s\n", idx, env[idx]);
		#endif
		++idx;
	}
	z_printf("Total %d arguments!\n", idx);
	// p的下一个，是av table的地址了
	// Question av table的空间是否足够?
	av = (void *)p;

	(void)env;
	if (argc < 2)
		z_errx(1, "no input file");
		// 获取文件
	file = argv[1];

	for (i = 0;; i++, ehdr++) {
		/* Open file, read and than check ELF header.*/
		// 打开文件
		// 第二轮，重新打开file, 注意file 可能发生变化了
		if ((fd = z_open(file, O_RDONLY)) < 0)
			z_errx(1, "can't open %s", file);
		if (z_read(fd, ehdr, sizeof(*ehdr)) != sizeof(*ehdr))
			z_errx(1, "can't read ELF header %s", file);
		if (!check_ehdr(ehdr))
			z_errx(1, "bogus ELF header %s", file);

		/* Read the program header. */
		// 读取表头数量
		#if 0
		p_type: 段的类型，例如可执行代码、数据等。
		p_flags: 段的标志，指示该段的权限（如可读、可写、可执行）。
		p_offset: 段在文件中的偏移量，指向该段的起始位置。
		p_vaddr: 段在内存中的虚拟地址，程序运行时该段将加载到此地址。
		p_paddr: 段在物理内存中的地址（在许多系统中，这个字段不常用）。
		p_filesz: 段在文件中的大小，表示在文件中占用的字节数。
		p_memsz: 段在内存中的大小，表示在内存中实际使用的字节数。
		p_align: 段的对齐要求，通常是2的幂，用于内存对齐。
		#endif
		sz = ehdr->e_phnum * sizeof(Elf_Phdr);
		// 申请地址
		// p_hdrs 是一个header数组，都是program header
		phdr = z_alloca(sz);
		if (z_lseek(fd, ehdr->e_phoff, SEEK_SET) < 0)
			z_errx(1, "can't lseek to program header %s", file);
		if (z_read(fd, phdr, sz) != sz)
			z_errx(1, "can't read program header %s", file);
		/* Time to load ELF. */
		if ((base[i] = loadelf_anon(fd, ehdr, phdr)) == LOAD_ERR)
			z_errx(1, "can't load ELF %s", file);

		/* Set the entry point, if the file is dynamic than add bias. */
		// 这里是找entry_point
		entry[i] = ehdr->e_entry + (ehdr->e_type == ET_DYN ? base[i] : 0);
		/* The second round, we've loaded ELF interp. */
		// file 是一个j8指针
		if (file == elf_interp) {
			z_close(fd);
			break;
		}

		for (iter = phdr; iter < &phdr[ehdr->e_phnum]; iter++) {
			// 类型
			// 该类型主要用于linux 动态链接器的处理
			if (iter->p_type != PT_INTERP)
				continue;
				// 找到interpretor
			elf_interp = z_alloca(iter->p_filesz);
			// 读取段数据
			if (z_lseek(fd, iter->p_offset, SEEK_SET) < 0)
				z_errx(1, "can't lseek interp segment");
			if (z_read(fd, elf_interp, iter->p_filesz) !=
					(ssize_t)iter->p_filesz)
				z_errx(1, "can't read interp segment");
				// 数据有问题
			if (elf_interp[iter->p_filesz - 1] != '\0')
				z_errx(1, "bogus interp path");
				// 配置
				// 这里要注意，是不是会跑多次呢?
				// 更新file
			file = elf_interp;
		}

		z_close(fd);
		/* Looks like the ELF is static -- leave the loop. */
		// 如果没有interp 说明不需要shared lib，
		if (elf_interp == NULL) {
			z_printf("Got static!\n");
			break;
		}
	}

	/* Reassign some vectors that are important for
	 * the dynamic linker and for lib C. */
	// 配置一些KV键值对
	#if 0
typedef struct
{
  uint32_t a_type;		/* Entry type */
  union
    {
      uint32_t a_val;		/* Integer value */
      /* We use to have pointer elements added here.  We cannot do that,
	 though, since it does not work when using 32-bit definitions
	 on 64-bit platforms and vice versa.  */
    } a_un;
} Elf32_auxv_t;
	#endif

#define AVSET(t, v, expr) case (t): (v)->a_un.a_val = (expr); break
	//  根据av_type 做一些配置
	// 问题:av table 的空间是谁申请的，以及申请了多少呢? 这个会是一个问题，C++ 代码如何知道该申请多少个kv？
	// Answer: 有系统调用可以获取到这个av table
	idx = 0;
	while (av->a_type != AT_NULL) {
		switch (av->a_type) {
		AVSET(AT_PHDR, av, base[Z_PROG] + ehdrs[Z_PROG].e_phoff);
		AVSET(AT_PHNUM, av, ehdrs[Z_PROG].e_phnum);
		AVSET(AT_PHENT, av, ehdrs[Z_PROG].e_phentsize);
		AVSET(AT_ENTRY, av, entry[Z_PROG]);
		AVSET(AT_EXECFN, av, (unsigned long)argv[1]);
		AVSET(AT_BASE, av, elf_interp ?
				base[Z_INTERP] : av->a_un.a_val);
		}
		++idx;
		++av;
	}
#undef AVSET
	// 再往下迭代一个
	// 这里可能不包括av...
	// 这里的av 全是地址....
	++av;
	// 22个
	z_printf("There are %d av tables!\n", idx);

	/* Shift argv, env and av. */
	// 一般argv[0] 是程序自己的名字，这里应该是为了让argv[0]正确
	// 这里的字节数是怎么算的呢?
	// argv1 拷贝到argv0  包括env!
	// 这里的&argv[0] 是char**, 也就是拷贝一堆指针
	// 这里应该是从&argv[1] 一直拷贝到av(注意最后一个Pointer仍然有8B)
	int len = (unsigned long)av - (unsigned long)&argv[1];
	// 拷贝了1000 B， 为何这么多
	z_printf("Will copy %d\n", len);
	// 整个地址覆盖
	// 所以这里的memcpy 完成了整个内存区域的移动
	z_memcpy(&argv[0], &argv[1],
		 (unsigned long)av - (unsigned long)&argv[1]);
	// 拷贝argv, 注意这里argv[0]已经拷贝过了。。。
	z_memcpy((stk+1), &argv[0], len);
	#if 0
	int ret = z_memcmp((stk+1), &argv[0], len);
	if(ret) {
		z_printf("Mis match!\n");
	} else {
		// ===> 拷贝的OK，完全一致都不行，哈哈哈
		z_printf("Mached!\n");
	}
	#endif
	/* SP current points to argc. reduce it*/
	// 这个地方应该是 argc -= 1
	(*sp)--;
	*(unsigned long *)(stk) = (*sp);
	int ret = z_memcmp((stk), sp, len+sizeof(unsigned long));
	if(ret) {
		z_printf("Mis match! %d \n", ret);
	} else {
		// ===> 拷贝的OK，完全一致都不行，哈哈哈
		z_printf("Mached!\n");
	}
	
	// 这里做个试验，假设我自己申请一段空间给他做stack 不知道行不行...
	// 不过这个要copy 内容了, 相当于手动构造哪些参数
	// 使用C++开发的代码，

	// 三个参数, 分别是入口地址、sp 以及z_fini
	// 这里第一个参数是入口，第二个参数是sp 第一个参数用来跳转，第二个参数会被用来设置栈，第三个参数相当于abi标准，提供一个finished
	// 这里跳转过后可能就不会再回来了, 也不能再回来了，栈可能被破坏
	z_printf("Will jump!\n");
	#if 0
	z_trampo((void (*)(void))(elf_interp ?
			entry[Z_INTERP] : entry[Z_PROG]), sp, z_fini);
	#else 
	// 这里判断跳转哪个
	// 估计是和这个sp 本身有关
	// 可能还是少了什么东西 ... 
	z_trampo((void (*)(void))(elf_interp ?
			entry[Z_INTERP] : entry[Z_PROG]), stk, z_fini);
	#endif
	/* Should not reach. */
	z_exit(0);
}

