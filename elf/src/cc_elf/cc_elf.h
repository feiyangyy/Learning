#ifndef CC_ELF_H
#define CC_ELF_H
#include <string>
#include <list>
#include <vector>
#include <stdio.h>
// header definition
// note macros don't need see real implementation, it's just a replacement.
// 这个就叫elf header
#define Elf_Ehdr Elf64_Ehdr
// 这个交程序头
#define Elf_Phdr Elf64_Phdr
// 辅助向量，是协助程序运行的一组kv 键值对
#define Elf_auxv_t Elf64_auxv_t
// ELF 类型
#define ELFCLASS ELFCLASS64
class CCElf{
  public:
    CCElf(const std::string& name);
    ~CCElf();
    bool Load(std::vector<std::string> args);
    bool Open();
    bool CheckHeader(Elf_Ehdr* header, FILE* fp);
    // bool Load
    bool LoadProgramHeaders(const std::string& file_name);

    bool LoadElfAon(void* p_phdr, Elf_Ehdr* p_ehdr, FILE* fp, uint32_t nb_program_hdr, void*& p);
  private:
  #if 0
    FILE *f_pointer_ {nullptr};
    FILE *f_inter_pointer_ {nullptr};
  #endif
    std::string file_name_ {""};
    void* file_base_ {nullptr};
    void* file_entry_ {nullptr};
  
    std::string inter_file_name_{""};
    void* interp_base_ {nullptr};
    void* interp_entry {nullptr};
  #if 0
    Elf_Ehdr header_;
  #endif
};

#endif