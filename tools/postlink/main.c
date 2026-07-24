#include <assert.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <unistd.h>
#include "elf.h"
#include "../../include/constants/postlink.h"

int main(int argc, char *argv[])
{
    const char *elf_path = NULL;
    int elffd;
    struct stat elfst;
    void *elf = NULL;
    struct PostlinkElf postlink_elf = {0};

    if (argc < 2)
    {
        fprintf(stderr, "usage %s elf\n", argv[0]);
        goto invalid;
    }

    elf_path = argv[1];

    if ((elffd = open(elf_path, O_RDONLY)) == -1)
    {
        perror("open elffd failed");
        goto invalid;
    }

    if (fstat(elffd, &elfst) == -1)
    {
        perror("stat elffd failed");
        goto invalid;
    }

    if ((elf = mmap(NULL, elfst.st_size, PROT_READ, MAP_PRIVATE, elffd, 0)) == MAP_FAILED)
    {
        perror("mmap elffd failed");
        goto invalid;
    }

    const char *postlink_elf_parse_error = parse_postlink_elf(elf, &postlink_elf);
    if (postlink_elf_parse_error)
    {
        fprintf(stderr, "%s\n", postlink_elf_parse_error);
        goto invalid;
    }

    uint32_t free_space = (0x9FFFFFF - 4) - postlink_elf.rom_end; // '- 4' to mimic alignment.
    uint32_t remaining_free_space = free_space;
    uint32_t discarded = 0;
    for (size_t i = 0; i < postlink_elf.gba_entries_count; i++)
    {
        switch (postlink_elf.gba_entries[i].type)
        {
        case POSTLINK_TYPE_SYMTAB:
        {
            struct Symbol *symbol = postlink_elf.gba_entries[i].as_symbol;
            uint32_t size = (4 + 4 + 4) + (strlen(symbol->name) + 1);
            if (size > remaining_free_space)
            {
                symbol->in_gba_entries = false;
                discarded++;
            }
            else
            {
                remaining_free_space -= size;
            }
            break;
        }

        case POSTLINK_TYPE_ENUMTAB:
        {
            struct Enum *enum_ = postlink_elf.gba_entries[i].as_enum;
            uint32_t size = (4 + 4) + (strlen(enum_->name) + 1) + (4 + 4 + 4);
            int prev_value = enum_->enumerators[0].value;
            for (size_t i = 1; i < enum_->enumerators_count; i++)
            {
                assert(prev_value <= enum_->enumerators[i].value);
                if (prev_value == enum_->enumerators[i].value) continue;
                if (prev_value + 1 != enum_->enumerators[i].value)
                    size += 4 + 4 + 4; // New 'EnumeratorRange'.
                size += strlen(enum_->enumerators[i].name) + 1;
            }
            if (size > remaining_free_space)
            {
                enum_->in_gba_entries = false;
                discarded++;
            }
            else
            {
                remaining_free_space -= size;
            }
            break;
        }

        default:
            fprintf(stderr, "error: unknown '.postlink.gba' entry type %02x\n", postlink_elf.gba_entries[i].type);
            goto invalid;
        }
    }

    if (discarded > 0)
    {
        fprintf(stderr, "warning: %u entries did not fit in the debug symbol table\n", discarded);
    }

    printf(".section .postlink.gba.symtab, \"aR\", %%progbits\n");
    printf(".section .postlink.gba.enumtab, \"aR\", %%progbits\n");
    printf(".section .postlink.gba.data, \"a\", %%progbits\n");
    printf(".section .postlink.gba.str, \"a\", %%progbits\n");

    for (size_t i = 0; i < postlink_elf.symbols_count; i++)
    {
        const struct Symbol *symbol = &postlink_elf.symbols[i];
        if (!symbol->in_gba_entries) continue;
        printf(".section .postlink.gba.symtab, \"aR\", %%progbits; .4byte 0x%08x, 0x%08x, .Lsymstr%zu\n", symbol->address, symbol->size, i);
        printf(".section .postlink.gba.str, \"a\", %%progbits; .Lsymstr%zu: .asciz \"%s\"\n", i, symbol->name);
    }

    for (size_t i = 0; i < postlink_elf.enums_count; i++)
    {
        const struct Enum *enum_ = &postlink_elf.enums[i];
        if (!enum_->in_gba_entries) continue;
        printf(".section .postlink.gba.enumtab, \"aR\", %%progbits; .4byte .Lenumstr%zu, .Lenumrange%zu\n", i, i);
        printf(".section .postlink.gba.str, \"a\", %%progbits; .Lenumstr%zu: .asciz \"%s\"\n", i, enum_->name);
        printf(".section .postlink.gba.data, \"a\", %%progbits; .Lenumrange%zu: .4byte %d, .Lenumstrs%zu.0\n", i, enum_->enumerators[0].value, i);
        printf(".section .postlink.gba.str, \"a\", %%progbits; .Lenumstrs%zu.0: .asciz \"%s\"", i, enum_->enumerators[0].name);
        int prev_value = enum_->enumerators[0].value;
        uint32_t names_count = 1;
        uint32_t ranges_count = 1;
        for (size_t j = 1; j < enum_->enumerators_count; j++)
        {
            if (prev_value + 1 == enum_->enumerators[j].value)
            {
                printf(", \"%s\"", enum_->enumerators[j].name);
                prev_value = enum_->enumerators[j].value;
                names_count++;
            }
            else
            {
                printf("\n");
                printf(".section .postlink.gba.data, \"a\", %%progbits; .4byte %u, %d, .Lenumstrs%zu.%zu\n", names_count, enum_->enumerators[j].value, i, j);
                printf(".section .postlink.gba.str, \"a\", %%progbits; .Lenumstrs%zu.%zu: .asciz \"%s\"", i, j, enum_->enumerators[j].name);
                prev_value = enum_->enumerators[j].value;
                names_count = 1;
                ranges_count++;
            }
        }
        printf("\n");
        printf(".section .postlink.gba.data, \"a\", %%progbits; .4byte %u\n", names_count);
        printf(".section .postlink.gba.enumtab, \"aR\", %%progbits; .4byte %u\n", ranges_count);
    }

    free_postlink_elf(&postlink_elf);
    return 0;

invalid:
    free_postlink_elf(&postlink_elf);
    if (elf != NULL && elf != MAP_FAILED) munmap(elf, elfst.st_size);
    return 2;
}
