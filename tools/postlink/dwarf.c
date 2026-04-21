#include <assert.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "elf.h"
#include "vendor/dwarf.h"

uint64_t fnv1a_string(const char *string)
{
    uint64_t hash = 0xcbf29ce484222325;
    for (size_t i = 0; string[i] != '\0'; i++)
        hash = (hash ^ string[i]) * 0x00000100000001b3;
    return hash;
}

struct Parser {
    const uint8_t *begin;
    const uint8_t *current;
    const uint8_t *end;
};

static uint8_t parse_u8(struct Parser *p)
{
    assert(p->current < p->end);
    return *p->current++;
}

static uint16_t parse_u16(struct Parser *p)
{
    uint16_t result;
    assert(p->current + sizeof(result) <= p->end);
    memcpy(&result, p->current, sizeof(result)); // XXX: Assumes host-endianess.
    p->current += sizeof(result);
    return result;
}

static uint32_t parse_u32(struct Parser *p)
{
    uint32_t result;
    assert(p->current + sizeof(result) <= p->end);
    memcpy(&result, p->current, sizeof(result)); // XXX: Assumes host-endianess.
    p->current += sizeof(result);
    return result;
}

static uint64_t parse_uleb128(struct Parser *p)
{
    uint64_t result = 0;
    int shift = 0;
    while (true)
    {
        assert(p->current < p->end);
        uint8_t byte = *p->current++;
        result |= (byte & 0x7F) << shift;
        if ((byte & 0x80) == 0)
            break;
        shift += 7;
        assert(shift < 64 - 7); // TODO: Support 128-bit numbers.
    }
    return result;
}

static int64_t parse_sleb128(struct Parser *p)
{
    int64_t result = 0;
    int shift = 0;
    uint8_t byte = 0;
    while (true)
    {
        assert(p->current < p->end);
        uint8_t byte = *p->current++;
        result |= (byte & 0x7F) << shift;
        shift += 7;
        assert(shift < 63 - 7); // TODO: Support 128-bit numbers.
        if ((byte & 0x80) == 0)
            break;
    }
    if (shift < 64 && byte & 0x40)
        result |= -(1 << shift);
    return result;
}

static const char *parse_string(struct Parser *p)
{
    const char *str = (const char *)p->current;
    while (true)
    {
        assert(p->current < p->end);
        if (*p->current++ == '\0') break;
    }
    return str;
}

static void skip_size(struct Parser *p, size_t size)
{
    assert(p->current + size <= p->end);
    p->current += size;
}

struct Attribute {
    uint16_t name; // NOTE: Could be 128-bit.
    uint16_t form; // NOTE: Could be 128-bit.
    // TODO: Store the value for 'DW_FORM_implicit_const'.
};

struct Abbreviation {
    uint16_t tag; // NOTE: Could be 128-bit.
    bool has_children;
    size_t attributes_count;
    struct Attribute attributes[];
};

struct AbbreviationEntry {
    uint32_t debug_abbrev_offset;
    uint64_t code; // NOTE: Should be 128-bit.
    size_t abbreviation_bump_offset; // Offset into 'abbreviation_bump'.
};

struct EnumeratorEntry {
    const char *enumeration_name;
    const char *enumerator_name;
    int32_t enumerator_value;
    uint32_t debug_info_offset;
    // TUs can declare enumerations with the same name, but different
    // enumerators; in those cases we simply exclude that enumeration
    // from 'elf'. 'count' is used to track this.
    int32_t count;
};

struct Dwarf {
    const char *debug_str;
    size_t debug_str_size;

    uint8_t *abbreviation_bump;
    size_t abbreviation_bump_size;
    size_t abbreviation_bump_capacity;

    struct AbbreviationEntry *abbreviation_table;
    size_t abbreviation_table_count;
    size_t abbreviation_table_capacity;

    struct EnumeratorEntry *enumerator_table;
    size_t enumerator_table_count;
    size_t enumerator_table_capacity;
};

static size_t push_abbreviation(struct Dwarf *dwarf, uint32_t debug_abbrev_offset, uint64_t code, uint16_t tag, bool has_children)
{
    // Round up to 'max_align_t'.
    dwarf->abbreviation_bump_size = (dwarf->abbreviation_bump_size + sizeof(max_align_t) - 1) & ~(sizeof(max_align_t) - 1);

    // Rehash at/above a 50% load factor.
    if (dwarf->abbreviation_table_count * 2 >= dwarf->abbreviation_table_capacity)
    {
        size_t abbreviation_table_capacity = 2 * dwarf->abbreviation_table_capacity;
        struct AbbreviationEntry *abbreviation_table = calloc(abbreviation_table_capacity, sizeof(*abbreviation_table));
        assert(abbreviation_table != NULL);
        for (size_t i = 0; i < dwarf->abbreviation_table_capacity; i++)
        {
            if (dwarf->abbreviation_table[i].code == 0) continue;
            uint64_t hash = dwarf->abbreviation_table[i].debug_abbrev_offset ^ dwarf->abbreviation_table[i].code;
            size_t j = hash & (abbreviation_table_capacity - 1);
            while (true)
            {
                if (abbreviation_table[j].code == 0)
                {
                    abbreviation_table[j] = dwarf->abbreviation_table[i];
                    break;
                }
                j = (j + 1) & (abbreviation_table_capacity - 1);
            }
        }
        free(dwarf->abbreviation_table);
        dwarf->abbreviation_table = abbreviation_table;
        dwarf->abbreviation_table_capacity = abbreviation_table_capacity;
    }

    // Linear probing.
    uint64_t hash = debug_abbrev_offset ^ code;
    size_t i = hash & (dwarf->abbreviation_table_capacity - 1);
    while (true)
    {
        if (dwarf->abbreviation_table[i].code == 0)
        {
            dwarf->abbreviation_table[i].debug_abbrev_offset = debug_abbrev_offset;
            dwarf->abbreviation_table[i].code = code;
            dwarf->abbreviation_table[i].abbreviation_bump_offset = dwarf->abbreviation_bump_size;
            dwarf->abbreviation_table_count++;
            break;
        }
        assert(dwarf->abbreviation_table[i].debug_abbrev_offset != debug_abbrev_offset || dwarf->abbreviation_table[i].code != code);
        i = (i + 1) & (dwarf->abbreviation_table_capacity - 1);
    }

    if (dwarf->abbreviation_bump_size + sizeof(struct Abbreviation) > dwarf->abbreviation_bump_capacity)
    {
        dwarf->abbreviation_bump_capacity *= 2;
        dwarf->abbreviation_bump = realloc(dwarf->abbreviation_bump, dwarf->abbreviation_bump_capacity);
        assert(dwarf->abbreviation_bump != NULL);
    }

    size_t abbreviation_bump_offset = dwarf->abbreviation_bump_size;

    struct Abbreviation *abbreviation = (struct Abbreviation *)(dwarf->abbreviation_bump + dwarf->abbreviation_bump_size);
    dwarf->abbreviation_bump_size += sizeof(*abbreviation);

    abbreviation->tag = tag;
    abbreviation->has_children = has_children;
    abbreviation->attributes_count = 0;

    return abbreviation_bump_offset;
}

static void push_attribute(struct Dwarf *dwarf, size_t abbreviation_bump_offset, uint16_t name, uint16_t form)
{
    if (dwarf->abbreviation_bump_size + sizeof(struct Attribute) > dwarf->abbreviation_bump_capacity)
    {
        dwarf->abbreviation_bump_capacity *= 2;
        dwarf->abbreviation_bump = realloc(dwarf->abbreviation_bump, dwarf->abbreviation_bump_capacity);
        assert(dwarf->abbreviation_bump != NULL);
    }

    struct Attribute *attribute = (struct Attribute *)(dwarf->abbreviation_bump + dwarf->abbreviation_bump_size);
    dwarf->abbreviation_bump_size += sizeof(*attribute);

    attribute->name = name;
    attribute->form = form;

    struct Abbreviation *abbreviation = (struct Abbreviation *)(dwarf->abbreviation_bump + abbreviation_bump_offset);
    abbreviation->attributes_count++;
}

const struct Abbreviation *lookup_abbreviation(const struct Dwarf *dwarf, uint32_t debug_abbrev_offset, uint64_t code)
{
    uint64_t hash = debug_abbrev_offset ^ code;
    size_t i = hash & (dwarf->abbreviation_table_capacity - 1);
    while (true)
    {
        // Should never happen in well-formed DWARF.
        if (dwarf->abbreviation_table[i].code == 0) return NULL;

        if (dwarf->abbreviation_table[i].debug_abbrev_offset == debug_abbrev_offset
         && dwarf->abbreviation_table[i].code == code)
        {
            assert(dwarf->abbreviation_table[i].abbreviation_bump_offset < dwarf->abbreviation_bump_size);
            return (const struct Abbreviation *)(dwarf->abbreviation_bump + dwarf->abbreviation_table[i].abbreviation_bump_offset);
        }

        i = (i + 1) & (dwarf->abbreviation_table_capacity - 1);
    }
}

static void add_enumerator(struct Dwarf *dwarf, const char *enumeration_name, const char *enumerator_name, int32_t enumerator_value, uint32_t debug_info_offset)
{
    // Rehash at/above a 50% load factor.
    if (dwarf->enumerator_table_count * 2 >= dwarf->enumerator_table_capacity)
    {
        size_t enumerator_table_capacity = 2 * dwarf->enumerator_table_capacity;
        struct EnumeratorEntry *enumerator_table = calloc(enumerator_table_capacity, sizeof(*enumerator_table));
        assert(enumerator_table != NULL);
        for (size_t i = 0; i < dwarf->enumerator_table_capacity; i++)
        {
            if (dwarf->enumerator_table[i].count == 0) continue;
            uint64_t hash = fnv1a_string(dwarf->enumerator_table[i].enumeration_name) ^ fnv1a_string(dwarf->enumerator_table[i].enumerator_name);
            size_t j = hash & (enumerator_table_capacity - 1);
            while (true)
            {
                if (enumerator_table[j].count == 0)
                {
                    enumerator_table[j] = dwarf->enumerator_table[i];
                    break;
                }
                j = (j + 1) & (enumerator_table_capacity - 1);
            }
        }
        free(dwarf->enumerator_table);
        dwarf->enumerator_table = enumerator_table;
        dwarf->enumerator_table_capacity = enumerator_table_capacity;
    }

    // Linear probing.
    uint64_t hash = fnv1a_string(enumeration_name) ^ fnv1a_string(enumerator_name);
    size_t i = hash & (dwarf->enumerator_table_capacity - 1);
    while (true)
    {
        if (dwarf->enumerator_table[i].count == 0)
        {
            dwarf->enumerator_table[i].enumeration_name = enumeration_name;
            dwarf->enumerator_table[i].enumerator_name = enumerator_name;
            dwarf->enumerator_table[i].enumerator_value = enumerator_value;
            dwarf->enumerator_table[i].debug_info_offset = debug_info_offset;
            dwarf->enumerator_table[i].count = 1;
            dwarf->enumerator_table_count++;
            break;
        }

        if (strcmp(dwarf->enumerator_table[i].enumeration_name, enumeration_name) == 0
         && strcmp(dwarf->enumerator_table[i].enumerator_name, enumerator_name) == 0)
        {
            if (dwarf->enumerator_table[i].count < 0)
                ;
            else if (dwarf->enumerator_table[i].enumerator_value != enumerator_value)
                dwarf->enumerator_table[i].count = -1;
            else
                dwarf->enumerator_table[i].count++;
            break;
        }

        i = (i + 1) & (dwarf->enumerator_table_capacity - 1);
    }
}

static const char *skip_form(struct Parser *pi, uint16_t form)
{
    size_t size = 0;
    switch (form)
    {
    case DW_FORM_addr: skip_size(pi, 4); return NULL;
    case DW_FORM_addrx: parse_uleb128(pi); return NULL;
    case DW_FORM_addrx1: skip_size(pi, 1); return NULL;
    case DW_FORM_addrx2: skip_size(pi, 2); return NULL;
    case DW_FORM_addrx3: skip_size(pi, 3); return NULL;
    case DW_FORM_addrx4: skip_size(pi, 4); return NULL;
    case DW_FORM_sec_offset: skip_size(pi, 4); return NULL;
    case DW_FORM_block1: size = parse_u8(pi); skip_size(pi, size); return NULL;
    case DW_FORM_block2: size = parse_u16(pi); skip_size(pi, size); return NULL;
    case DW_FORM_block4: size = parse_u32(pi); skip_size(pi, size); return NULL;
    case DW_FORM_block: size = parse_uleb128(pi); skip_size(pi, size); return NULL;
    case DW_FORM_data1: skip_size(pi, 1); return NULL;
    case DW_FORM_data2: skip_size(pi, 2); return NULL;
    case DW_FORM_data4: skip_size(pi, 4); return NULL;
    case DW_FORM_data8: skip_size(pi, 8); return NULL;
    case DW_FORM_data16: skip_size(pi, 16); return NULL;
    case DW_FORM_udata: parse_uleb128(pi); return NULL;
    case DW_FORM_sdata: parse_sleb128(pi); return NULL;
    case DW_FORM_implicit_const: return NULL;
    case DW_FORM_exprloc: size = parse_uleb128(pi); skip_size(pi, size); return NULL;
    case DW_FORM_flag: skip_size(pi, 1); return NULL;
    case DW_FORM_flag_present: return NULL;
    case DW_FORM_loclistx: parse_uleb128(pi); return NULL;
    case DW_FORM_rnglistx: parse_uleb128(pi); return NULL;
    case DW_FORM_ref1: skip_size(pi, 1); return NULL;
    case DW_FORM_ref2: skip_size(pi, 2); return NULL;
    case DW_FORM_ref4: skip_size(pi, 4); return NULL;
    case DW_FORM_ref8: skip_size(pi, 8); return NULL;
    case DW_FORM_ref_udata: parse_uleb128(pi); return NULL;
    case DW_FORM_ref_addr: skip_size(pi, 4); return NULL;
    case DW_FORM_ref_sig8: skip_size(pi, 8); return NULL;
    case DW_FORM_ref_sup4: skip_size(pi, 4); return NULL;
    case DW_FORM_ref_sup8: skip_size(pi, 8); return NULL;
    case DW_FORM_string: parse_string(pi); return NULL;
    case DW_FORM_strp: skip_size(pi, 4); return NULL;
    case DW_FORM_line_strp: skip_size(pi, 4); return NULL;
    case DW_FORM_strp_sup: skip_size(pi, 4); return NULL;
    case DW_FORM_strx: parse_uleb128(pi); return NULL;
    case DW_FORM_strx1: skip_size(pi, 1); return NULL;
    case DW_FORM_strx2: skip_size(pi, 2); return NULL;
    case DW_FORM_strx3: skip_size(pi, 3); return NULL;
    case DW_FORM_strx4: skip_size(pi, 4); return NULL;
    default: return "unknown form";
    }
}

static const char *parse_sint_form(struct Parser *p, uint16_t form, int32_t *out)
{
    switch (form)
    {
    case DW_FORM_data1: *out = parse_u8(p); return NULL;
    case DW_FORM_data2: *out = parse_u16(p); return NULL;
    case DW_FORM_data4: *out = parse_u32(p); return NULL; // TODO: Check for overflow.
    case DW_FORM_udata: *out = parse_uleb128(p); return NULL; // TODO: Check for overflow.
    case DW_FORM_sdata: *out = parse_sleb128(p); return NULL; // TODO: Check for overflow.
    default: return "unsupported sint form";
    }
}

static const char *parse_string_form(const struct Dwarf *dwarf, struct Parser *pi, uint16_t form, const char **string)
{
    switch (form)
    {
    case DW_FORM_string: *string = parse_string(pi); return NULL;
    case DW_FORM_strp: *string = dwarf->debug_str + parse_u32(pi); return NULL;
    default: return "unsupported string form";
    }
}

static const char *skip_attributes(struct Parser *pi, const struct Abbreviation *abbreviation)
{
    const char *error;
    for (size_t i = 0; i < abbreviation->attributes_count; i++)
    {
        error = skip_form(pi, abbreviation->attributes[i].form);
        if (error) return error;
    }
    return NULL;
}

static const char *skip_die(const struct Dwarf *dwarf, struct Parser *pi, uint32_t debug_abbrev_offset, const struct Abbreviation *abbreviation);

static const char *skip_children(const struct Dwarf *dwarf, struct Parser *pi, uint32_t debug_abbrev_offset)
{
    const char *error;
    while (true)
    {
        uint64_t code = parse_uleb128(pi);
        if (code == 0) return NULL;
        const struct Abbreviation *abbreviation = lookup_abbreviation(dwarf, debug_abbrev_offset, code);
        if (abbreviation == NULL) return "unknown abbreviation";
        error = skip_die(dwarf, pi, debug_abbrev_offset, abbreviation);
        if (error) return error;
    }
    return NULL;
}

static const char *skip_die(const struct Dwarf *dwarf, struct Parser *pi, uint32_t debug_abbrev_offset, const struct Abbreviation *abbreviation)
{
    const char *error;

    error = skip_attributes(pi, abbreviation);
    if (error) return error;

    if (abbreviation->has_children)
    {
        error = skip_children(dwarf, pi, debug_abbrev_offset);
        if (error) return error;
    }

    return NULL;
}

static const char *parse_enumerator(struct Dwarf *dwarf, struct Parser *pi, uint32_t debug_abbrev_offset, const struct Abbreviation *abbreviation, const char *enumeration_name)
{
    const char *error;
    const char *name = NULL;
    int32_t value = 0;
    bool has_value = false;
    uint32_t debug_info_offset = pi->current - pi->begin;

    for (size_t i = 0; i < abbreviation->attributes_count; i++)
    {
        switch (abbreviation->attributes[i].name)
        {
        case DW_AT_name:
            error = parse_string_form(dwarf, pi, abbreviation->attributes[i].form, &name);
            if (error) return error;
            break;

        case DW_AT_const_value:
            error = parse_sint_form(pi, abbreviation->attributes[i].form, &value);
            if (error) return error;
            has_value = true;
            break;

        default:
            error = skip_form(pi, abbreviation->attributes[i].form);
            if (error) return error;
            break;
        }
    }

    if (name != NULL && has_value)
    {
        add_enumerator(dwarf, enumeration_name, name, value, debug_info_offset);
    }

    if (abbreviation->has_children)
    {
        error = skip_children(dwarf, pi, debug_abbrev_offset);
        if (error) return error;
    }

    return NULL;
}

static const char *parse_enumeration_type(struct Dwarf *dwarf, struct Parser *pi, uint32_t debug_abbrev_offset, const struct Abbreviation *abbreviation)
{
    const char *error;
    const char *name = NULL;

    for (size_t i = 0; i < abbreviation->attributes_count; i++)
    {
        switch (abbreviation->attributes[i].name)
        {
        case DW_AT_name:
            error = parse_string_form(dwarf, pi, abbreviation->attributes[i].form, &name);
            if (error) return error;
            break;

        default:
            error = skip_form(pi, abbreviation->attributes[i].form);
            if (error) return error;
            break;
        }
    }

    if (abbreviation->has_children)
    {
        while (true)
        {
            uint64_t code = parse_uleb128(pi);
            if (code == 0) return NULL;
            const struct Abbreviation *abbreviation = lookup_abbreviation(dwarf, debug_abbrev_offset, code);
            if (abbreviation == NULL) return "unknown abbreviation";
            if (name != NULL && abbreviation->tag == DW_TAG_enumerator)
            {
                error = parse_enumerator(dwarf, pi, debug_abbrev_offset, abbreviation, name);
                if (error) return error;
            }
            else
            {
                error = skip_die(dwarf, pi, debug_abbrev_offset, abbreviation);
                if (error) return error;
            }
        }
    }

    return NULL;
}

static const char *parse_dies(struct Dwarf *dwarf, struct Parser *pi, uint32_t debug_abbrev_offset);

static const char *parse_die(struct Dwarf *dwarf, struct Parser *pi, uint32_t debug_abbrev_offset, const struct Abbreviation *abbreviation)
{
    const char *error;
    switch (abbreviation->tag)
    {
    case DW_TAG_compile_unit:
        error = skip_attributes(pi, abbreviation);
        if (error) return error;
        if (abbreviation->has_children)
        {
            error = parse_dies(dwarf, pi, debug_abbrev_offset);
            if (error) return error;
        }
        return NULL;

    case DW_TAG_enumeration_type:
        return parse_enumeration_type(dwarf, pi, debug_abbrev_offset, abbreviation);

    default:
        return skip_die(dwarf, pi, debug_abbrev_offset, abbreviation);
    }
}

static const char *parse_dies(struct Dwarf *dwarf, struct Parser *pi, uint32_t debug_abbrev_offset)
{
    while (pi->current < pi->end)
    {
        uint64_t code = parse_uleb128(pi);
        if (code == 0) return NULL;

        const struct Abbreviation *abbreviation = lookup_abbreviation(dwarf, debug_abbrev_offset, code);
        if (abbreviation == NULL) return "unknown abbreviation";

        const char *error = parse_die(dwarf, pi, debug_abbrev_offset, abbreviation);
        if (error) return error;
    }

    return NULL;
}

const char *parse_postlink_dwarf(const void *debug_info, size_t debug_info_size, const void *debug_abbrev, size_t debug_abbrev_size, const char *debug_str, size_t debug_str_size, struct PostlinkElf *elf)
{
    struct Dwarf dwarf = {0};
    dwarf.debug_str = debug_str;
    dwarf.debug_str_size = debug_str_size;

    dwarf.abbreviation_bump_capacity = 4096;
    dwarf.abbreviation_bump = malloc(dwarf.abbreviation_bump_capacity);
    assert(dwarf.abbreviation_bump != NULL);

    dwarf.abbreviation_table_capacity = 128;
    dwarf.abbreviation_table = calloc(dwarf.abbreviation_table_capacity, sizeof(*dwarf.abbreviation_table));
    assert(dwarf.abbreviation_table != NULL);

    dwarf.enumerator_table_capacity = 4096;
    dwarf.enumerator_table = calloc(dwarf.enumerator_table_capacity, sizeof(*dwarf.enumerator_table));
    assert(dwarf.enumerator_table != NULL);

    struct Parser pa = { .begin = debug_abbrev, .current = debug_abbrev, .end = (const uint8_t *)debug_abbrev + debug_abbrev_size };
    while (pa.current < pa.end)
    {
        uint32_t debug_abbrev_offset = pa.current - pa.begin;
        while (true)
        {
            uint64_t code = parse_uleb128(&pa);
            if (code == 0) break;

            uint64_t tag = parse_uleb128(&pa);
            if (tag > UINT16_MAX) return "unsupported abbreviation tag";

            uint8_t has_children = parse_u8(&pa);
            if (has_children != DW_CHILDREN_yes && has_children != DW_CHILDREN_no) return "unsupported abbreviation has_children";

            size_t abbreviation_bump_offset = push_abbreviation(&dwarf, debug_abbrev_offset, code, tag, has_children);

            while (true)
            {
                uint64_t name = parse_uleb128(&pa);
                if (name > UINT16_MAX) return "unsupported attribute name";
                uint64_t form = parse_uleb128(&pa);
                if (form > UINT16_MAX) return "unsupported attribute form";
                if (name == 0 && form == 0) break;

                if (form == DW_FORM_implicit_const)
                    parse_sleb128(&pa); // TODO: Store the value.

                push_attribute(&dwarf, abbreviation_bump_offset, name, form);
            }
        }
    }

    struct Parser pi = { .begin = debug_info, .current = debug_info, .end = (const uint8_t *)debug_info + debug_info_size };
    while (pi.current < pi.end)
    {
        uint32_t length = parse_u32(&pi);
        assert(length < 0xFFFFFFF0); // 32-bit DWARF.
        const void *end = pi.current + length;

        uint16_t version = parse_u16(&pi);
        uint8_t unit_type;
        uint8_t addr_size;
        uint32_t debug_abbrev_offset;
        if (version >= 5)
        {
            unit_type = parse_u8(&pi);
            addr_size = parse_u8(&pi);
            debug_abbrev_offset = parse_u32(&pi);
        }
        else
        {
            unit_type = DW_UT_compile;
            debug_abbrev_offset = parse_u32(&pi);
            addr_size = parse_u8(&pi);
        }

        assert(debug_abbrev_offset < debug_abbrev_size);

        if (version < 5 || (unit_type != DW_UT_compile && unit_type != DW_UT_partial) || addr_size != 4)
        {
            pi.current = end;
        }
        else
        {
            struct Parser pi_ = { .begin = pi.current, .current = pi.current, .end = end };
            const char *error = parse_dies(&dwarf, &pi_, debug_abbrev_offset);
            if (error) return error;
            pi.current = pi_.current;
            assert(pi.current == end);
        }
    }

    // Copy 'enum' definitions to 'elf'.
    // TODO: A linear(-ish) implementation rather than this quadratic one.
    size_t enums_capacity = 64;
    elf->enums = malloc(enums_capacity * sizeof(*elf->enums));
    assert(elf->enums != NULL);
    for (size_t i = 0; i < dwarf.enumerator_table_capacity; i++)
    {
        if (dwarf.enumerator_table[i].count == 0) continue;
        int32_t count = dwarf.enumerator_table[i].count;

        struct Enum enum_ = {0};
        enum_.name = dwarf.enumerator_table[i].enumeration_name;
        size_t enum_enumerators_capacity = 8;
        enum_.enumerators = malloc(enum_enumerators_capacity * sizeof(*enum_.enumerators));
        assert(enum_.enumerators != NULL);
        enum_.enumerators_count = 0;

        for (size_t j = i; j < dwarf.enumerator_table_capacity; j++)
        {
            if (dwarf.enumerator_table[j].count == 0) continue;
            if (strcmp(enum_.name, dwarf.enumerator_table[j].enumeration_name) != 0) continue;
            if (count != dwarf.enumerator_table[j].count) count = -1;
            dwarf.enumerator_table[j].count = 0;
            if (count > 0)
            {
                if (enum_.enumerators_count == enum_enumerators_capacity)
                {
                    enum_enumerators_capacity *= 2;
                    enum_.enumerators = realloc(enum_.enumerators, enum_enumerators_capacity * sizeof(*enum_.enumerators));
                    assert(enum_.enumerators != NULL);
                }
                enum_.enumerators[enum_.enumerators_count].name = dwarf.enumerator_table[j].enumerator_name;
                enum_.enumerators[enum_.enumerators_count].value = dwarf.enumerator_table[j].enumerator_value;
                enum_.enumerators[enum_.enumerators_count].debug_info_offset = dwarf.enumerator_table[j].debug_info_offset;
                enum_.enumerators_count++;
            }
        }

        if (count > 0)
        {
            if (elf->enums_count == enums_capacity)
            {
                enums_capacity *= 2;
                elf->enums = realloc(elf->enums, enums_capacity * sizeof(*elf->enums));
                assert(elf->enums != NULL);
            }
            elf->enums[elf->enums_count++] = enum_;
        }
        else
        {
            fprintf(stderr, "info: ignoring 'enum %s': inconsistent definitions\n", enum_.name);
            free(enum_.enumerators);
        }
    }

    free(dwarf.abbreviation_bump);
    free(dwarf.abbreviation_table);
    free(dwarf.enumerator_table);

    return NULL;
}
