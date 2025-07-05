#ifndef GUARD_GENERATIONAL_CHANGES_H
#define GUARD_GENERATIONAL_CHANGES_H

#include "constants/generational_changes.h"
#include "config/battle.h"

static const u8 sConfigChanges[CONFIG_COUNT] =
{
    [CONFIG_CRIT_CHANCE]               = B_CRIT_CHANCE,
    [CONFIG_CRIT_MULTIPLIER]           = B_CRIT_MULTIPLIER,
    [CONFIG_FOCUS_ENERGY_CRIT_RATIO]   = B_FOCUS_ENERGY_CRIT_RATIO,
    [CONFIG_PARALYSIS_SPEED]           = B_PARALYSIS_SPEED,
    [CONFIG_CONFUSION_SELF_DMG_CHANCE] = B_CONFUSION_SELF_DMG_CHANCE,
    [CONFIG_MULTI_HIT_CHANCE]          = B_MULTI_HIT_CHANCE,
    [CONFIG_GALE_WINGS]                = B_GALE_WINGS,
    [CONFIG_HEAL_BELL_SOUNDPROOF]      = B_HEAL_BELL_SOUNDPROOF,
    [CONFIG_TELEPORT_BEHAVIOR]         = B_TELEPORT_BEHAVIOR,
    [CONFIG_ABILITY_WEATHER]           = B_ABILITY_WEATHER,
    [CONFIG_MOODY_STATS]               = B_MOODY_ACC_EVASION,
    [CONFIG_BATTLE_BOND]               = B_BATTLE_BOND,
    [CONFIG_FELL_STINGER_STAT_RAISE]   = B_FELL_STINGER_STAT_RAISE,
    [CONFIG_ATE_MULTIPLIER]            = B_ATE_MULTIPLIER,
};

#if TESTING
extern u8 *gConfigChangesTestOverride;
#endif

static inline u32 GetConfig(enum ConfigTag configTag)
{
    if (configTag >= CONFIG_COUNT)
        return GEN_LATEST;
#if TESTING
    if (gConfigChangesTestOverride == NULL)
        return sConfigChanges[configTag];
    return gConfigChangesTestOverride[configTag];
#else
    return sConfigChanges[configTag];
#endif
}

static inline void SetConfig(enum ConfigTag configTag, u32 value)
{
#if TESTING
    if (configTag >= CONFIG_COUNT)
        return;
    if (gConfigChangesTestOverride == NULL)
        return;
    gConfigChangesTestOverride[configTag] = value;
#endif
}

#if TESTING
void TestInitConfigData(void);
void TestFreeConfigData(void);
#endif

#endif // GUARD_GENERATIONAL_CHANGES_H
