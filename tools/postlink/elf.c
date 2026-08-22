#include <assert.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dwarf.h"
#include "elf.h"
#include "vendor/elf.h"
#include "../../include/constants/postlink.h"

struct PostlinkElfEntry {
    uint8_t type;
    uint8_t flags;
    uint8_t priority;
    uint8_t unused_03;
    uint32_t value;
};

static int compare_symbol_addresses_asc(const void *a, const void *b)
{
    const struct Symbol *sa = a, *sb = b;

    if (sa->address < sb->address)
        return -1;
    else if (sa->address > sb->address)
        return 1;

    return 0;
}

static struct Symbol *lookup_address(struct PostlinkElf *out, uint32_t address)
{
    int lo = 0, hi = out->symbols_count;
    while (lo < hi)
    {
        int mi = lo + (hi - lo) / 2;
        struct Symbol *symbol = &out->symbols[mi];
        if (address < symbol->address)
            hi = mi;
        else if (address >= symbol->address + symbol->size)
            lo = mi + 1;
        else
            return symbol;
    }
    return NULL;
}

static void push_symbol_reference(struct Symbol ***symbols, struct Symbol *symbol)
{
    if (*symbols == NULL)
    {
        *symbols = malloc(2 * sizeof(***symbols));
        assert(*symbols != NULL);
        (*symbols)[0] = symbol;
        (*symbols)[1] = NULL;
        return;
    }

    size_t count;

    // Skip already inserted.
    for (count = 0; (*symbols)[count] != NULL; count++)
    {
        if ((*symbols)[count] == symbol)
            return;
    }

    // Re-allocate if full.
    if (((count + 1) & count) == 0) {
        *symbols = realloc(*symbols, (count + 1) * 2 * sizeof(***symbols));
        assert(*symbols != NULL);
    }

    (*symbols)[count + 0] = symbol;
    (*symbols)[count + 1] = NULL;
}

static int compare_enum_names_asc(const void *a, const void *b)
{
    const struct Enum *ea = a, *eb = b;
    return strcmp(ea->name, eb->name);
}

static int compare_enumerator_values_offsets_asc(const void *a, const void *b)
{
    const struct Enumerator *ea = a, *eb = b;

    if (ea->value < eb->value)
        return -1;
    else if (ea->value > eb->value)
        return 1;

    if (ea->debug_info_offset < eb->debug_info_offset)
        return -1;
    else if (ea->debug_info_offset > eb->debug_info_offset)
        return 1;

    return 0;
}

static struct Enum *lookup_enum(struct PostlinkElf *out, const char *name)
{
    if (out->enums == NULL) return NULL;
    int lo = 0, hi = out->enums_count;
    while (lo < hi)
    {
        int mi = lo + (hi - lo) / 2;
        struct Enum *enum_ = &out->enums[mi];
        int cmp = strcmp(name, enum_->name);
        if (cmp < 0)
            hi = mi;
        else if (cmp > 0)
            lo = mi + 1;
        else
            return enum_;
    }
    return NULL;
}

static int compare_gba_entry_priorities_desc(const void *a, const void *b)
{
    const struct PostlinkGbaEntry *pgea = a, *pgeb = b;

    if (pgea->priority < pgeb->priority)
        return 1;
    else if (pgea->priority > pgeb->priority)
        return -1;

    return 0;
}

static void push_postlink_gba_entry(struct PostlinkElf *out, uint8_t type, uint8_t priority, void *ptr)
{
    if (out->gba_entries_count == out->gba_entries_capacity)
    {
        out->gba_entries_capacity *= 2;
        out->gba_entries = realloc(out->gba_entries, out->gba_entries_capacity * sizeof(*out->gba_entries));
        assert(out->gba_entries != NULL);
    }

    out->gba_entries[out->gba_entries_count].type = type;
    out->gba_entries[out->gba_entries_count].priority = priority;
    out->gba_entries[out->gba_entries_count].as_ptr = ptr;
    out->gba_entries_count++;
}

static void push_postlink_gba_symbol(struct PostlinkElf *out, uint8_t priority, bool if_function, struct Symbol *symbol)
{
    if (if_function && !symbol->is_function) return;
    if (symbol->in_gba_entries) return;
    symbol->in_gba_entries = true;
    push_postlink_gba_entry(out, POSTLINK_TYPE_SYMTAB, priority, symbol);
}

static const char *parse_postlink_elf_entries(const struct PostlinkElfEntry *elf_entries, size_t elf_entries_size, const void *elf_data, size_t elf_data_size, struct PostlinkElf *out)
{
    if (elf_entries_size % sizeof(*elf_entries) != 0) return "invalid '.postlink.elf' size";
    size_t elf_entries_count = elf_entries_size / sizeof(*elf_entries);

    out->gba_entries_capacity = 1024;
    out->gba_entries = malloc(out->gba_entries_capacity * sizeof(*out->gba_entries));

    for (size_t i = 0; i < elf_entries_count; i++)
    {
        switch (elf_entries[i].type)
        {
        case POSTLINK_TYPE_SYMTAB:
        {
            bool if_function = elf_entries[i].flags & POSTLINK_SYMTAB_IF_FUNCTION;
            struct Symbol *symbol = lookup_address(out, elf_entries[i].value);
            if (symbol)
            {
                if ((elf_entries[i].flags & POSTLINK_SYMTAB_ADD_SYMBOL))
                {
                    push_postlink_gba_symbol(out, elf_entries[i].priority, if_function, symbol);
                }
                if ((elf_entries[i].flags & POSTLINK_SYMTAB_ADD_REFERRERS)
                 && symbol->referrers)
                {
                    for (struct Symbol **referrers = symbol->referrers; *referrers != NULL; referrers++)
                    {
                        push_postlink_gba_symbol(out, elf_entries[i].priority, if_function, *referrers);
                    }
                }
                if ((elf_entries[i].flags & POSTLINK_SYMTAB_ADD_REFERENCES)
                 && symbol->references)
                {
                    for (struct Symbol **references = symbol->references; *references != NULL; references++)
                    {
                        push_postlink_gba_symbol(out, elf_entries[i].priority, if_function, *references);
                    }
                }
            }
            else
            {
                //fprintf(stderr, "info: ignoring 'postlink.elf' entry: no symbol contains 0x%07x\n", elf_entries[i].value);
            }
            break;
        }

        case POSTLINK_TYPE_ENUMTAB:
        {
            assert(elf_entries[i].value < elf_data_size);
            const char *name = (const char *)elf_data + elf_entries[i].value;
            struct Enum *enum_ = lookup_enum(out, name);
            if (enum_ && !enum_->in_gba_entries && enum_->enumerators_count > 0)
            {
                enum_->in_gba_entries = true;
                push_postlink_gba_entry(out, POSTLINK_TYPE_ENUMTAB, elf_entries[i].priority, enum_);
            }
            break;
        }

        default:
            // TODO: This should be fatal on rh-hideout's CI.
            fprintf(stderr, "warning: ignoring '.postlink.elf' entry: unknown entry type: %d\n", elf_entries[i].type);
            break;
        }
    }

    qsort(out->gba_entries, out->gba_entries_count, sizeof(*out->gba_entries), compare_gba_entry_priorities_desc);

    return NULL;
}

const char *parse_postlink_elf(const void *file, struct PostlinkElf *out)
{
    *out = (struct PostlinkElf) {};

    const char *error;

    const char *elf = file;
    if (memcmp(elf, ELFMAG, 4) != 0) return "not an ELF";

    const Elf32_Ehdr *ehdr = (const Elf32_Ehdr *)elf;
    const Elf32_Shdr *shdrs = (const Elf32_Shdr *)(elf + ehdr->e_shoff);

    if (ehdr->e_shstrndx == SHN_UNDEF) return "missing section '.shstrtab'";
    const char *shstr = (const char *)(elf + shdrs[ehdr->e_shstrndx].sh_offset);

    // Locate sections.
    const Elf32_Shdr *shdr_symtab = NULL, *shdr_strtab = NULL;
    const Elf32_Shdr *shdr_debug_abbrev = NULL, *shdr_debug_info = NULL, *shdr_debug_str = NULL;
    const Elf32_Shdr *shdr_postlink_elf = NULL, *shdr_postlink_elf_data = NULL;
    for (size_t i = 0; i < ehdr->e_shnum; i++)
    {
        const char *sh_name = shstr + shdrs[i].sh_name;
        if (strcmp(sh_name, ".symtab") == 0 && shdrs[i].sh_type == SHT_SYMTAB)
            shdr_symtab = &shdrs[i];
        else if (strcmp(sh_name, ".strtab") == 0 && shdrs[i].sh_type == SHT_STRTAB)
            shdr_strtab = &shdrs[i];
        else if (strcmp(sh_name, ".debug_abbrev") == 0 && shdrs[i].sh_type == SHT_PROGBITS)
            shdr_debug_abbrev = &shdrs[i];
        else if (strcmp(sh_name, ".debug_info") == 0 && shdrs[i].sh_type == SHT_PROGBITS)
            shdr_debug_info = &shdrs[i];
        else if (strcmp(sh_name, ".debug_str") == 0 && shdrs[i].sh_type == SHT_PROGBITS)
            shdr_debug_str = &shdrs[i];
        else if (strcmp(sh_name, ".postlink.elf") == 0 && shdrs[i].sh_type == SHT_PROGBITS)
            shdr_postlink_elf = &shdrs[i];
        else if (strcmp(sh_name, ".postlink.elf.data") == 0 && shdrs[i].sh_type == SHT_PROGBITS)
            shdr_postlink_elf_data = &shdrs[i];
    }
    if (shdr_symtab == NULL) return "missing section '.symtab'";
    if (shdr_strtab == NULL) return "missing section '.strtab'";

    // Parse symbol table.
    const Elf32_Sym *symtab = (const Elf32_Sym *)(elf + shdr_symtab->sh_offset);
    const char *strtab = (const char *)(elf + shdr_strtab->sh_offset);
    size_t symbols_capacity = 1024;
    out->symbols = malloc(symbols_capacity * sizeof(*out->symbols));
    assert(out->symbols != NULL);
    for (size_t i = 0; i < shdr_symtab->sh_size / shdr_symtab->sh_entsize; i++)
    {
        if (symtab[i].st_name == 0) continue;
        if (symtab[i].st_shndx > ehdr->e_shnum) continue;
        if (symtab[i].st_value < 0x02000000 || symtab[i].st_value > 0x0E000000) continue;

        const char *st_name = strtab + symtab[i].st_name;

        if (strcmp(st_name, "__rom_end") == 0)
        {
            out->rom_end = symtab[i].st_value;
            continue;
        }

        if (symtab[i].st_size == 0) continue;

        if (out->symbols_count == symbols_capacity) {
            symbols_capacity *= 2;
            out->symbols = realloc(out->symbols, symbols_capacity * sizeof(*out->symbols));
            assert(out->symbols != NULL);
        }
        bool is_function = ELF32_ST_TYPE(symtab[i].st_info) == STT_FUNC;
        out->symbols[out->symbols_count++] = (struct Symbol) {
            .name = st_name,
            .address = symtab[i].st_value & ~(is_function ? 0x1 : 0x0), // TODO: ARM functions should use an '0x3' mask.
            .size = symtab[i].st_size,
            .is_function = is_function,
            .references = NULL,
            .referrers = NULL,
        };
    }

    qsort(out->symbols, out->symbols_count, sizeof(*out->symbols), compare_symbol_addresses_asc);

    if (out->rom_end == 0)
    {
        fprintf(stderr, "warning: missing symbol '__rom_end'\n");
    }

    // Parse symbol-symbol references from relocations.
    for (int i = 0; i < ehdr->e_shnum; i++)
    {
        if (shdrs[i].sh_type != SHT_REL) continue;

        const Elf32_Rel *rels = (const Elf32_Rel *)(elf + shdrs[i].sh_offset);
        for (size_t j = 0; j < shdrs[i].sh_size / shdrs[i].sh_entsize; j++)
        {
            struct Symbol *from = lookup_address(out, rels[j].r_offset);
            if (!from) continue;
            int to_offset = ELF32_R_SYM(rels[j].r_info);
            const Elf32_Sym *to_sym = &symtab[to_offset];
            struct Symbol *to = lookup_address(out, to_sym->st_value);
            if (!to) continue;
            push_symbol_reference(&from->references, to);
            push_symbol_reference(&to->referrers, from);
        }
    }

    // Parse DWARF5.
    if (shdr_debug_abbrev != NULL && shdr_debug_info != NULL)
    {
        const char *debug_str = shdr_debug_str ? elf + shdr_debug_str->sh_offset : NULL;
        size_t debug_str_size = shdr_debug_str ? shdr_debug_str->sh_size : 0;
        error = parse_postlink_dwarf(elf + shdr_debug_info->sh_offset, shdr_debug_info->sh_size, elf + shdr_debug_abbrev->sh_offset, shdr_debug_abbrev->sh_size, debug_str, debug_str_size, out);
        if (error) return error;
        for (size_t i = 0; i < out->enums_count; i++)
            qsort(out->enums[i].enumerators, out->enums[i].enumerators_count, sizeof(*out->enums[i].enumerators), compare_enumerator_values_offsets_asc);
        qsort(out->enums, out->enums_count, sizeof(*out->enums), compare_enum_names_asc);
    }

    if (shdr_postlink_elf != NULL)
    {
        const void *postlink_elf_data = shdr_postlink_elf_data ? elf + shdr_postlink_elf_data->sh_offset : NULL;
        size_t postlink_elf_data_size = shdr_postlink_elf_data ? shdr_postlink_elf_data->sh_size : 0;
        error = parse_postlink_elf_entries((const struct PostlinkElfEntry *)(elf + shdr_postlink_elf->sh_offset), shdr_postlink_elf->sh_size, postlink_elf_data, postlink_elf_data_size, out);
        if (error) return error;
    }
    else
    {
        //fprintf(stderr, "info: missing section '.postlink.elf'\n");
    }

    // TODO: Warn if any entries reference symbols that overlap.

    return NULL;
}

void free_postlink_elf(struct PostlinkElf *elf)
{
    for (size_t i = 0; i < elf->symbols_count; i++)
    {
        free(elf->symbols[i].references);
        free(elf->symbols[i].referrers);
    }
    free(elf->symbols);

    for (size_t i = 0; i < elf->enums_count; i++)
    {
        free(elf->enums[i].enumerators);
    }
    free(elf->enums);

    free(elf->gba_entries);
}
