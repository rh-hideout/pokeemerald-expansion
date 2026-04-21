#ifndef ELF_H
#define ELF_H

#include <stdbool.h>
#include <stdint.h>

struct Symbol {
    const char *name;
    uint32_t address;
    uint32_t size;
    bool is_function;
    bool in_gba_entries;

    struct Symbol **references;
    struct Symbol **referrers;
};

struct Enumerator {
    const char *name;
    int32_t value;
    // WARNING: Assumes that GCC will list the enumerators in source order.
    uint32_t debug_info_offset;
};

struct Enum {
    const char *name;
    struct Enumerator *enumerators;
    size_t enumerators_count;
    bool in_gba_entries;
};

struct PostlinkGbaEntry {
    uint8_t type;
    uint8_t priority;
    union {
        void *as_ptr;
        struct Symbol *as_symbol;
        struct Enum *as_enum;
    };
};

struct PostlinkElf {
    uint32_t rom_end;

    struct Symbol *symbols;
    size_t symbols_count;

    struct Enum *enums;
    size_t enums_count;

    struct PostlinkGbaEntry *gba_entries;
    size_t gba_entries_count;
    size_t gba_entries_capacity;
};

const char *parse_postlink_elf(const void *file, struct PostlinkElf *elf);
void free_postlink_elf(struct PostlinkElf *elf);

#endif
