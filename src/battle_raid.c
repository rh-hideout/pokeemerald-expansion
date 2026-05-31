#include "global.h"
#include "battle.h"
#include "battle_util.h"
#include "battle_raid.h"
#include "battle_scripts.h"
#include "random.h"

#define RAID_BOSS B_BATTLER_1

EWRAM_DATA struct BattleRaid gBattleRaid = {0};

u32 GetRaidLevel(enum RaidType type, u32 monLevel)
{
    if (type == RAID_TYPE_DYNAMAX)
    {
        switch (monLevel)
        {
        case 1 ... 20:  return 1;
        case 25 ... 34: return 2;
        case 35 ... 44: return 3;
        case 45 ... 54: return 4;
        default:        return 5;
        }
    }
    else // tera raid
    {
        switch (monLevel)
        {
        case 1 ... 12: return 1;
        case 13 ... 20: return 2;
        case 21 ... 35: return 3;
        case 36 ... 45: return 4;
        case 46 ... 75: return 5;
        case 76 ... 90: return 6;
        default: return 7;
        }
    }

    return 1;
}

void SetRaidMon(void)
{
    switch (gBattleRaid.type)
    {
    case RAID_TYPE_NONE:
        break;
    case RAID_TYPE_DYNAMAX:
        SetActiveGimmick(RAID_BOSS, GIMMICK_DYNAMAX);
        SetGimmickAsActivated(RAID_BOSS, GIMMICK_DYNAMAX);
        TryBattleFormChange(RAID_BOSS, FORM_CHANGE_BATTLE_GIGANTAMAX, GetBattlerAbility(RAID_BOSS));
        if (!IsGigantamaxed(RAID_BOSS)) // RecalcBattlerStats will get called on form change.
        {
            struct Pokemon *mon = GetBattlerMon(RAID_BOSS);
            RecalcBattlerStats(RAID_BOSS, mon, GetActiveGimmick(RAID_BOSS) == GIMMICK_DYNAMAX);
        }
        break;
    case RAID_TYPE_TERA:
        break;
    }
}

void AdjustRaidMoveDamage(enum BattlerId battler)
{
    if (!IsRaidBattle())
        return;

    if (battler != RAID_BOSS)
        return;

    u32 halfHp = gBattleMons[battler].hp / 2;
    if (gBattleStruct->moveDamage[battler] >= halfHp)
        gBattleStruct->moveDamage[battler] = halfHp;
}

// level 3 - 50%
// level 4 - 50%
// level 5 - 66% (the other variant is before first turn)
void SetBarrierActivation(enum BattlerId battler, u32 hpBeforeUpdate, u32 hpAfterUpdate)
{
    if (gBattleMons[battler].hp > gBattleMons[battler].maxHP / 2)
        gBattleStruct->battlerState[battler].wasAboveHalfHp = TRUE;

    u32 threshold = 0;

    switch (gBattleRaid.level)
    {
    case 3:
    case 4:
        threshold = gBattleMons[battler].maxHP / 2;
        if (hpBeforeUpdate > threshold && hpAfterUpdate < hpBeforeUpdate)
            gBattleRaid.setBarrier = TRUE;
        break;
    case 5: // Also needs to check if this variant was chosen
        threshold = gBattleMons[battler].maxHP / 3;
        if (hpBeforeUpdate > threshold && hpAfterUpdate < hpBeforeUpdate)
            gBattleRaid.setBarrier = TRUE;
        break;
    }
}

bool32 HandleRaidBarrier(void)
{
    if (!IsRaidBattle())
        return FALSE;

    if (gBattleRaid.barrierSegments == 0)
        return FALSE;

    if (!gBattleRaid.setBarrier)// && !gBattleRaid.handleSegment)
        return FALSE;

    // if (gBattleRaid.handleSegment)
    if (TRUE)
    {
        gBattleRaid.barrierSegments--;
        if (gBattleRaid.barrierSegments == 0)
            BattleScriptCall(BattleScript_BarrierRemoved);
        else
            BattleScriptCall(BattleScript_SegmentRevemod);
        return TRUE;
    }
    else if (gBattleRaid.setBarrier)
    {
        enum Species species = gBattleMons[RAID_BOSS].species;

        u32 firstTerm = gSpeciesInfo[species].baseDefense + gSpeciesInfo[species].baseDefense + gSpeciesInfo[species].baseHP;
        u32 secondTerm = (gBattleRaid.level + 5 - 1) / 5;
        u32 resultTerm = firstTerm * secondTerm * 8;

        u32 segmentCount = (resultTerm + 765 - 1) / 765;

        gBattleRaid.setBarrier = FALSE;
        gBattleRaid.barrierSegments = segmentCount ;
        BattleScriptCall(BattleScript_BarrierAppeared);
        return TRUE;
    }

    return FALSE;
}

bool32 TryRaidShockWave(void)
{
    gBattleStruct->raidBattleAbilitySupression = FALSE;

    if (gBattleRaid.type != RAID_TYPE_DYNAMAX)
        return FALSE;

    if (!RandomChance(RNG_RAID_SHOCK_WAVE, 1, 3))
        return FALSE;

    for (enum BattlerId battler = B_BATTLER_0; battler < gBattlersCount; battler++)
    {
        if (!IsBattlerPresent(battler))
            continue;

        if (IsOnPlayerSide(battler)) // All stat changes are reset for player side
        {
            for (enum Stat stat = STAT_ATK; stat < NUM_BATTLE_STATS; stat++)
            {
                gBattleMons[battler].statStages[stat] = DEFAULT_STAT_STAGE;
            }
        }
        else
        {
            // Negative stat changes are reset for dynamax raid boss
            for (enum Stat stat = STAT_ATK; stat < NUM_BATTLE_STATS; stat++)
            {
                if (gBattleMons[battler].statStages[stat] < DEFAULT_STAT_STAGE)
                    gBattleMons[battler].statStages[stat] = DEFAULT_STAT_STAGE;
            }

            gBattleMons[battler].status1 = 0; // Raid boss non volatile is healed
            RequestNonVolatileChange(battler);
        }
    }

    gBattleStruct->raidBattleAbilitySupression = TRUE;
    BattleScriptCall(BattleScript_RaidShockWave);
    return TRUE;
}

static bool32 IsRaidBattle(void)
{
    return gBattleRaid.type != RAID_TYPE_NONE;
}

#undef RAID_BOSS
