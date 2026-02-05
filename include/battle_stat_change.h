#ifndef GUARD_BATTLE_MOVE_STAT_CHANGE_H
#define GUARD_BATTLE_MOVE_STAT_CHANGE_H

#include "constants/battle_stat_change.h"

struct StatChange
{
    const u8 *battleScript;

    enum Stat stat;
    s8 stage;
    u16 stats;
    u16 additionalEffect;

    // Flags
    u32 silentFailure:1;
    u32 printStatCantChangeMsg:1;
    u32 passiveStatChange:1;
    u32 mirrorArmored:1;
    u32 onlyChecking:1;
    u32 notProtectAffected:1;
    u32 updateAdditionalEffectStats:1;
    u32 certain:1;
    // Some padding
};

u32 ChangeStatBuffs(enum BattlerId battler, s8 statValue, enum Stat statId, union StatChangeFlags flags, u32 stats, const u8 *BS_ptr);
bool32 CanAnyStatChange(enum BattlerId battler, enum Ability ability, enum Move move);
bool32 IsStatDecreaseEffect(u32 effect);
bool32 IsStatIncreaseEffect(u32 effect);
bool32 IsStatSet(u32 stat, const struct AdditionalEffect *additionalEffect);
bool32 CompareStat(enum BattlerId battler, enum Stat statId, u32 cmpTo, u32 cmpKind, enum Ability ability);

#endif // GUARD_BATTLE_MOVE_STAT_CHANGE_H
