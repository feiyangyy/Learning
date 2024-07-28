#ifndef __H_ELFLOADER__
#define __H_ELFLOADER__
#include <stdint.h>

typedef void (*void_func_t)(void);

#define ELF_CLASS_32 1
#define ELF_CLASS_64 2

#define ELF_DATA_LITTLE 1
#define ELF_DATA_BIG 2

#define ELF_FILE_NONE 0
#define ELF_FILE_REL 1
#define ELF_FILE_EXEC 2
#define ELF_FILE_DYN 3
#define ELF_FILE_CORE 4

typedef struct {
    uint32_t magic;
    uint8_t file_class;
    uint8_t encoding;
    uint8_t file_version;
    uint8_t os_abi;
    uint8_t abi_version;
    uint8_t padding[6];
    uint8_t ident_size;
    uint16_t file_type;
    uint16_t machine_type;
    uint32_t version;
    uint64_t entry_point;
    uint64_t program_header_offset;
    uint64_t section_header_offset;
    uint32_t flags;
    uint16_t header_size;
    uint16_t program_header_size;
    uint16_t program_header_count;
    uint16_t section_header_size;
    uint16_t section_header_count;
    uint16_t string_table_index;
} elf64_header_t;

#define ELF_SECTION_NULL 0
#define ELF_SECTION_PROGBITS 1
#define ELF_SECTION_SYMTAB 2
#define ELF_SECTION_STRTAB 3
#define ELF_SECTION_RELA 4
#define ELF_SECTION_HASH 5
#define ELF_SECTION_DYNAMIC 6
#define ELF_SECTION_NOTE 7
#define ELF_SECTION_NOBITS 8
#define ELF_SECTION_REL 9
#define ELF_SECTION_DYNSYM 11

const char *ELF_SECTION_TYPE[] = {
    "NULL",
    "PROGBITS",
    "SYMTAB",
    "STRTAB",
    "RELA",
    "HASH",
    "DYNAMIC",
    "NOTE",
    "NOBITS",
    "REL",
    "",
    "DYNSYM"
};

#define ELF_FLAG_WRITE 0x01
#define ELF_FLAG_ALLOC 0x02
#define ELF_FLAG_EXEC 0x04

typedef struct {
    uint32_t name_index;
    uint32_t type;
    uint64_t flags;
    uint64_t address;
    uint64_t offset;
    uint64_t size;
    uint32_t link;
    uint32_t info;
    uint64_t alignment;
    uint64_t entry_size;
} elf64_section_header_t;

#define ELF_REL_TYPE_64 1

typedef struct {
    uint64_t offset;
    uint32_t type;
    uint32_t symbol;
    int64_t addend;
} elf64_rela_entry_t;

typedef struct {
    uint32_t name_index;
    uint8_t info;
    uint8_t other;
    uint16_t section;
    uint64_t value;
    uint64_t size;
} elf64_symbol_t;

#endif