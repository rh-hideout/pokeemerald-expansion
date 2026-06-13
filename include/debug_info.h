#ifndef GUARD_DEBUG_INFO_H
#define GUARD_DEBUG_INFO_H

struct Symbol;

/* Looks up the symbol associated with 'p', if available in the
 * prioritized subset of the symbol table produced by 'postlink'. */
const struct Symbol *LookupAddress(const void *p);

/* Returns the address of a symbol. */
uintptr_t SymbolAddress(const struct Symbol *);

/* Returns the size (in bytes) of a symbol. */
size_t SymbolSize(const struct Symbol *);

/* Copies the name of a symbol plus a '\0' into out. Returns the length
 * of the name excluding the '\0'. */
size_t SymbolName(const struct Symbol *, char *out, size_t n);

struct Enum;

/* Looks up an 'enum' by 'name', if available in the prioritized subset
 * of the enum table produced by 'postlink'. */
const struct Enum *LookupEnum(const char *name);

struct Enumerator
{
    const struct Enum *enumeration;
    const struct EnumeratorRange *range;
    int value;
};

/* Looks up an enumerator by 'value', stores it in 'out', and returns
 * 'TRUE'. Otherwise returns 'FALSE'. */
bool32 LookupEnumerator(const struct Enum *, int value, struct Enumerator *out);

/* Returns an iterator starting at the minimum enumerator value. */
struct Enumerator EnumMinimum(const struct Enum *);

/* Returns an iterator starting at the maximum enumerator value. */
struct Enumerator EnumMaximum(const struct Enum *);

/* Advances to the next enumerator in value order and returns 'TRUE'.
 * Otherwise returns 'FALSE'.
 *
 * e.g. in 'enum { FOO = 1, BAR = 3 }', the next enumerator after 'FOO'
 * is 'BAR'. */
bool32 EnumeratorNext(struct Enumerator *);

/* Advances to the previous enumerator in value order and returns
 * 'TRUE'. Otherwise returns 'FALSE'.
 *
 * e.g. in 'enum { FOO = 1, BAR = 3 }', the previous enumerator before
 * 'BAR' is 'FOO'. */
bool32 EnumeratorPrev(struct Enumerator *);

/* Copies the name of the enumerator plus a '\0' into out. Returns the
 * length of the name excluding the '\0'. */
size_t EnumeratorName(const struct Enumerator *, char *out, size_t n);

#endif
