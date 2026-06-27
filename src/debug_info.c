#include "global.h"
#include <string.h>
#include "debug_info.h"

static const char *SkipString(const char *string)
{
    while (*string++ != '\0')
        ;
    return string;
}

static size_t CopyString(const char *string, char *out, size_t n)
{
    if (out)
    {
        size_t i;

        for (i = 0; i < n; i++)
        {
            out[i] = string[i];
            if (string[i] == '\0')
                return i;
        }

        out[n - 1] = '\0';

        while (string[i] != '\0')
            i++;

        return i;
    }
    else
    {
        return strlen(string);
    }
}

struct Symbol
{
    uintptr_t address;
    size_t size;
    const char *name;
};

extern const struct Symbol __postlink_symbols_start[];
extern const struct Symbol __postlink_symbols_end[];

const struct Symbol *LookupAddress(const void *p)
{
    uintptr_t address = (uintptr_t)p;

    // Un-mirror EWRAM/IWRAM/ROM addresses.
    switch (address & 0xF000000)
    {
    case 0x2000000: address = address & 0x203FFFF; break;
    case 0x3000000: address = address & 0x3007FFF; break;
    case 0x7000000: address = address & 0x70003FF; break;
    case 0xA000000: address = address & 0x9FFFFFF; break;
    case 0xB000000: address = address & 0x9FFFFFF; break;
    case 0xC000000: address = address & 0x9FFFFFF; break;
    case 0xD000000: address = address & 0x9FFFFFF; break;
    }

    size_t lo = 0, hi = __postlink_symbols_end - __postlink_symbols_start;
    while (lo < hi)
    {
        size_t mi =  lo + (hi - lo) / 2;
        const struct Symbol *symbol = &__postlink_symbols_start[mi];
        if (address < SymbolAddress(symbol))
            hi = mi;
        else if (address >= SymbolAddress(symbol) + SymbolSize(symbol))
            lo = mi + 1;
        else
            return symbol;
    }

    return NULL;
}

uintptr_t SymbolAddress(const struct Symbol *symbol)
{
    return symbol->address;
}

uintptr_t SymbolSize(const struct Symbol *symbol)
{
    return symbol->size;
}

size_t SymbolName(const struct Symbol *symbol, char *out, size_t n)
{
    return CopyString(symbol->name, out, n);
}

struct EnumeratorRange
{
    int value0;
    const char *name0;
    size_t count;
};

struct Enum
{
    const char *name;
    const struct EnumeratorRange *ranges;
    size_t rangesCount;
};

extern const struct Enum __postlink_enums_start[];
extern const struct Enum __postlink_enums_end[];

const struct Enum *LookupEnum(const char *name)
{
    size_t lo = 0, hi = __postlink_enums_end - __postlink_enums_start;
    while (lo < hi)
    {
        size_t mi = lo + (hi - lo) / 2;
        const struct Enum *enumeration = &__postlink_enums_start[mi];
        int cmp = strcmp(name, enumeration->name);
        if (cmp < 0)
            hi = mi;
        else if (cmp > 0)
            lo = mi + 1;
        else
            return enumeration;
    }
    return NULL;
}

bool32 LookupEnumerator(const struct Enum *enumeration, int value, struct Enumerator *out)
{
    for (size_t i = 0; i < enumeration->rangesCount; i++)
    {
        const struct EnumeratorRange *range = &enumeration->ranges[i];
        if (value < range->value0 || range->value0 + range->count <= value)
            continue;
        out->enumeration = enumeration;
        out->range = range;
        out->value = value;
        return TRUE;
    }

    return FALSE;
}

struct Enumerator EnumMinimum(const struct Enum *enumeration)
{
    const struct EnumeratorRange *range = &enumeration->ranges[0];
    return (struct Enumerator)
    {
        .enumeration = enumeration,
        .range = range,
        .value = range->value0,
    };
}

struct Enumerator EnumMaximum(const struct Enum *enumeration)
{
    const struct EnumeratorRange *range = &enumeration->ranges[enumeration->rangesCount - 1];
    return (struct Enumerator)
    {
        .enumeration = enumeration,
        .range = range,
        .value = range->value0 + range->count - 1,
    };
}

bool32 EnumeratorNext(struct Enumerator *enumerator)
{
    const struct EnumeratorRange *range = enumerator->range;
    if (enumerator->value < range->value0 + range->count - 1)
    {
        enumerator->value++;
        return TRUE;
    }

    const struct Enum *enumeration = enumerator->enumeration;
    if (enumerator->range < &enumeration->ranges[enumeration->rangesCount - 1])
    {
        enumerator->range++;
        enumerator->value = enumerator->range->value0;
        return TRUE;
    }

    return FALSE;
}

bool32 EnumeratorPrev(struct Enumerator *enumerator)
{
    const struct EnumeratorRange *range = enumerator->range;
    if (enumerator->value > range->value0)
    {
        enumerator->value--;
        return TRUE;
    }

    const struct Enum *enumeration = enumerator->enumeration;
    if (enumerator->range > &enumeration->ranges[0])
    {
        enumerator->range--;
        enumerator->value = enumerator->range->value0 + enumerator->range->count - 1;
        return TRUE;
    }

    return FALSE;
}

size_t EnumeratorName(const struct Enumerator *enumerator, char *out, size_t n)
{
    size_t nameIndex = enumerator->value - enumerator->range->value0;
    const char *name = enumerator->range->name0;
    for (size_t i = 0; i < nameIndex; i++)
        name = SkipString(name);
    return CopyString(name, out, n);
}
