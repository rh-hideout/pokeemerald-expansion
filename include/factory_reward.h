#ifndef GUARD_FACTORY_REWARD_H
#define GUARD_FACTORY_REWARD_H

#include "global.h"

bool8 BuildFactoryBossRewardMon(u8 bossId, u8 lvlMode, struct Pokemon *outMon);
bool8 BuildFactoryBossAceMon(u8 bossId, u8 level, u8 fixedIV, struct Pokemon *outMon);
u8 GetFactoryRewardBossId(u8 activeBossId, u8 lastGeneratedBossId);
bool8 IsFactoryRewardMonValid(struct Pokemon *mon, u8 activeBossId);
bool8 TryBuildFactoryRewardFromBoss(u8 activeBossId, u8 lastGeneratedBossId, u8 lvlMode, struct Pokemon *outMon, u8 *outBossId);
bool8 TryRebuildFactoryRewardForGrant(u8 activeBossId, u8 lastGeneratedBossId, u8 pendingBossId, u8 lvlMode, struct Pokemon *outMon, u8 *outPendingBossId, bool8 *outUsedBossBuild);

#endif // GUARD_FACTORY_REWARD_H
