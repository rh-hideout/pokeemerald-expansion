#ifndef GUARD_GENERATIONAL_CHANGES_H
#define GUARD_GENERATIONAL_CHANGES_H

#include "constants/generational_changes.h"
#include "config/battle.h"

#define UNPACK_CONFIG_STRUCT(_name, _field, _typeMaxValue, ...) INVOKE_WITH_(UNPACK_CONFIG_STRUCT_, _field, UNPACK_B(_typeMaxValue));
#define UNPACK_CONFIG_STRUCT_(_field, _type, ...) _type FIRST(__VA_OPT__(_field:BIT_SIZE(FIRST(__VA_ARGS__)),) _field)

struct GenChanges
{
    CONFIG_DEFINITIONS(UNPACK_CONFIG_STRUCT)
    // Expands to:
    // u32 critChance:4;
    // u32 critMultiplier:4;
    // ...
};

u32 GetGenConfig(enum GenConfigTag configTag);
void SetGenConfig(enum GenConfigTag configTag, u32 value);

#if TESTING
void TestInitConfigData(void);
void TestFreeConfigData(void);
#endif

#endif // GUARD_GENERATIONAL_CHANGES_H
