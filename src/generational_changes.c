#include "global.h"
#include "generational_changes.h"
#include "malloc.h"
#include "constants/generational_changes.h"

#define UNPACK_CONFIG_GEN_CHANGES2(_name, _field, ...) ._field = B_##_name,

const struct GenChanges sGenerationalChanges =
{
    CONFIG_DEFINITIONS(UNPACK_CONFIG_GEN_CHANGES2)
    /* Expands to:
    .critChance     = B_CRIT_CHANCE,
    .critMultiplier = B_CRIT_MULTIPLIER,
    */
};

#if TESTING
EWRAM_DATA struct GenChanges *gGenerationalChangesTestOverride = NULL;
#define UNPACK_CONFIG_OVERRIDE_GETTERS(_name, _field, ...)   case GEN_CONFIG_##_name: return gGenerationalChangesTestOverride->_field;
#define UNPACK_CONFIG_GETTERS(_name, _field, ...) case GEN_CONFIG_##_name: return sGenerationalChanges._field;
#define UNPACK_CONFIG_CLAMPER(_name, _field, _typeMaxValue, ...) case GEN_CONFIG_##_name: clampedValue = min(GET_CONFIG_MAXIMUM(_typeMaxValue), newValue); break;
#define UNPACK_CONFIG_SETTERS(_name, _field, _typeMaxValue, ...) case GEN_CONFIG_##_name: gGenerationalChangesTestOverride->_field = clampedValue; break;

#else

#define UNPACK_CONFIG_OVERRIDE_GETTERS(_name, _field, ...) case GEN_CONFIG_##_name: return sGenerationalChanges._field;
#define UNPACK_CONFIG_GETTERS(_name, _field, ...) case GEN_CONFIG_##_name: return sGenerationalChanges._field;
#define UNPACK_CONFIG_CLAMPER(_name, _field, ...) case GEN_CONFIG_##_name: return 0;
#define UNPACK_CONFIG_SETTERS(_name, _field, ...) case GEN_CONFIG_##_name: return;
#endif

// Gets the value of a volatile status flag for a certain battler
// Primarily used for the debug menu and scripts. Outside of it explicit references are preferred
u32 GetGenConfig(enum GenConfigTag _genConfig)
{
#if TESTING
    if (gGenerationalChangesTestOverride == NULL)
    {
        switch (_genConfig)
        {
            CONFIG_DEFINITIONS(UNPACK_CONFIG_GETTERS)
        /* Expands to:
            case GEN_CONFIG_CRIT_CHANCE:
                return gGenerationalChangesTestOverride->critChance;
        */
            default:
                return 0;
        }
    }
    else
#endif
    {
        switch (_genConfig)
        {
            CONFIG_DEFINITIONS(UNPACK_CONFIG_OVERRIDE_GETTERS)
        /* Expands to:
            case GEN_CONFIG_CRIT_CHANCE:
                 return sGenerationalChanges.critChance;
        */
            default: // Invalid config tag
                return 0;
        }
     }
}

#if TESTING
u32 GetClampedValue(enum GenConfigTag _genConfig, u32 newValue)
{
    u32 clampedValue = 0;
    switch(_genConfig)
    {
        CONFIG_DEFINITIONS(UNPACK_CONFIG_CLAMPER)
        default:
            return 0;
    }
    return clampedValue;
}
#endif

void SetGenConfig(enum GenConfigTag _genConfig, u32 _value)
{
#if TESTING
    u32 clampedValue = GetClampedValue(_genConfig, _value);
    switch (_genConfig)
    {
        CONFIG_DEFINITIONS(UNPACK_CONFIG_SETTERS)
    /* Expands to:
    #if TESTING
        case GEN_CONFIG_CRIT_CHANCE:
            gGenerationalChangesTestOverride->critChance = min(MAX_BITS(GEN_9), newValue);
            return;
    #else
        case GEN_CONFIG_CRIT_CHANCE:
            return;
    #endif
    */
        default: // Invalid config tag
            return;
    }
#endif
}

#if TESTING
void TestInitConfigData(void)
{
    gGenerationalChangesTestOverride = Alloc(sizeof(sGenerationalChanges));
    memcpy(gGenerationalChangesTestOverride, &sGenerationalChanges, sizeof(sGenerationalChanges));
}

void TestFreeConfigData(void)
{
    TRY_FREE_AND_SET_NULL(gGenerationalChangesTestOverride)
}
#endif
