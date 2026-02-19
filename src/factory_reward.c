#include "global.h"
#include "factory_custom_mon.h"
#include "factory_reward.h"
#include "pokemon.h"
#include "constants/battle_frontier.h"
#include "constants/battle_tent.h"
#include "constants/factory_boss.h"
#include "constants/items.h"
#include "constants/moves.h"
#include "constants/pokemon.h"

#include "data/battle_factory/factory_boss_custom_mons.h"

bool8 BuildFactoryBossRewardMon(u8 bossId, u8 lvlMode, struct Pokemon *outMon)
{
    u8 level = FRONTIER_MAX_LEVEL_OPEN;
    u8 fixedIv = 31;

    switch (lvlMode)
    {
    case FRONTIER_LVL_TENT:
        level = TENT_MIN_LEVEL;
        break;
    case FRONTIER_LVL_50:
        level = FRONTIER_MAX_LEVEL_50;
        break;
    case FRONTIER_LVL_OPEN:
    default:
        level = FRONTIER_MAX_LEVEL_OPEN;
        break;
    }

    if (bossId >= FACTORY_BOSS_COUNT || sFactoryBossRewardMonBuilds[bossId] == NULL)
        return FALSE;

    CreateFactoryCustomMon(outMon, sFactoryBossRewardMonBuilds[bossId], level, fixedIv);
    return TRUE;
}

bool8 BuildFactoryBossAceMon(u8 bossId, u8 level, u8 fixedIV, struct Pokemon *outMon)
{
    if (bossId >= FACTORY_BOSS_COUNT || sFactoryBossAceMonBuilds[bossId] == NULL)
        return FALSE;

    CreateFactoryCustomMon(outMon, sFactoryBossAceMonBuilds[bossId], level, fixedIV);
    return TRUE;
}

u8 GetFactoryRewardBossId(u8 activeBossId, u8 lastGeneratedBossId)
{
    u8 bossId = activeBossId;

    if (bossId == FACTORY_BOSS_NONE)
        bossId = lastGeneratedBossId;

    if (bossId >= FACTORY_BOSS_COUNT)
        return FACTORY_BOSS_NONE;

    return bossId;
}

bool8 IsFactoryRewardMonValid(struct Pokemon *mon, u8 activeBossId)
{
    bool8 isBadEgg = GetMonData(mon, MON_DATA_SANITY_IS_BAD_EGG);
    bool8 hasSpecies = GetMonData(mon, MON_DATA_SANITY_HAS_SPECIES);

    if (!isBadEgg && hasSpecies)
        return TRUE;

    DebugPrintfLevel(MGBA_LOG_FATAL, "Factory reward mon failed sanity check (bossId=%d badEgg=%d hasSpecies=%d)", activeBossId, isBadEgg, hasSpecies);
    AGB_ASSERT(FALSE);
    return FALSE;
}

bool8 TryBuildFactoryRewardFromBoss(u8 activeBossId, u8 lastGeneratedBossId, u8 lvlMode, struct Pokemon *outMon, u8 *outBossId)
{
    u8 bossId = GetFactoryRewardBossId(activeBossId, lastGeneratedBossId);

    if (!BuildFactoryBossRewardMon(bossId, lvlMode, outMon))
        return FALSE;

    if (outBossId != NULL)
        *outBossId = bossId;
    return TRUE;
}

bool8 TryRebuildFactoryRewardForGrant(u8 activeBossId, u8 lastGeneratedBossId, u8 pendingBossId, u8 lvlMode, struct Pokemon *outMon, u8 *outPendingBossId, bool8 *outUsedBossBuild)
{
    u8 resolvedBossId = pendingBossId;
    bool8 builtFromBoss = FALSE;

    if (TryBuildFactoryRewardFromBoss(activeBossId, lastGeneratedBossId, lvlMode, outMon, &resolvedBossId))
    {
        builtFromBoss = TRUE;
    }
    else if (pendingBossId != FACTORY_BOSS_NONE && BuildFactoryBossRewardMon(pendingBossId, lvlMode, outMon))
    {
        resolvedBossId = pendingBossId;
        builtFromBoss = TRUE;
    }

    if (outPendingBossId != NULL)
        *outPendingBossId = resolvedBossId;
    if (outUsedBossBuild != NULL)
        *outUsedBossBuild = builtFromBoss;
    return builtFromBoss;
}
