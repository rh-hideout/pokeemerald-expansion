#ifndef GUARD_BATTLE_RAID_H
#define GUARD_BATTLE_RAID_H

extern struct BattleRaid gBattleRaid;

enum RaidType
{
    RAID_TYPE_NONE,
    RAID_TYPE_DYNAMAX,
    RAID_TYPE_TERA,
};

struct BattleRaid
{
    enum RaidType type:2;
    u32 level:3;
    u32 timer:8;
    u32 faintCount:8;
    u32 partyType:3;
    u32 revive:1;
    u32 catchable:1;
    u32 setBarrier:1;
    u32 barrierSegments:3;
    u32 padding:2;
    // End of word
};

u32 GetRaidLevel(enum RaidType type, u32 monLevel);

static bool32 IsRaidBattle(void);
void AdjustRaidMoveDamage(enum BattlerId battler);
void SetBarrierActivation(enum BattlerId battler, u32 hpBeforeUpdate, u32 hpAfterUpdate);
bool32 HandleRaidBarrier(void);
bool32 TryRaidShockWave(void);
void SetRaidMon(void);

#endif  // GUARD_BATTLE_RAID_H
