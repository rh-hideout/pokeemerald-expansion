#ifndef GUARD_POSTLINK_H
#define GUARD_POSTLINK_H

#include "constants/postlink.h"

#define PostlinkReturnAddress(priority) ({ POSTLINK_SYMTAB(POSTLINK_SYMTAB_ADD_REFERRERS | POSTLINK_SYMTAB_IF_FUNCTION, priority, &&CAT(_, __LINE__)); CAT(_, __LINE__): __builtin_return_address(0); })

struct PostlinkEntry
{
    u8 type;
    u8 flags;
    u8 priority;
    u8 unused_03;
    uintptr_t value;
};

#define POSTLINK_SYMTAB(mode, priority, address) POSTLINK_ELF_ENTRY(sPostlinkSymtab_, POSTLINK_TYPE_SYMTAB, mode, priority, (uintptr_t)(address))

// HACK: '.postlink.elf.data' does not need to be allocated, so specify
// our own section by commenting out GCC's '.section' directive.
// WARNING: This will not work on Clang.
#define POSTLINK_ENUMTAB(type, priority) POSTLINK_ENUMTAB_(CAT(POSTLINK_ENUMTAB_STRIP_, type), priority)
#define POSTLINK_ENUMTAB_(name, priority) do { \
    __attribute__((section(".postlink.elf.data, \"\", %progbits @"), used)) static const enum name _value; \
    __attribute__((section(".postlink.elf.data, \"\", %progbits @"))) static const char _name[] = STR(name); \
    POSTLINK_ELF_ENTRY(CAT(sPostlinkEnumtab_, name), POSTLINK_TYPE_ENUMTAB, 0, priority, (uintptr_t)_name); \
} while (0)
#define POSTLINK_ENUMTAB_STRIP_enum

// HACK: '.postlink.elf' doesn't need to be allocated, but does need to
// be retained; so specify our own section by commenting out GCC's
// '.section' directive.
// WARNING: This will not work on Clang.
#define POSTLINK_ELF_ENTRY(slug, type, mode, priority, value) __attribute__((section(".postlink.elf, \"R\", %progbits @"), used)) static const struct PostlinkEntry CAT(slug, __LINE__) = { (type), (mode), (priority), 0, value }

#endif
