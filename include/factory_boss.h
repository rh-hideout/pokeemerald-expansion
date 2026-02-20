#ifndef GUARD_FACTORY_BOSS_H
#define GUARD_FACTORY_BOSS_H

#include "global.h"
#include "constants/factory_boss.h"

struct FactoryBossProfile
{
    bool8 enabled;
    const u8 *debugMenuName;
    const struct FactoryBossTextSet *text;
    u16 trainerId;
    u8 objEventGfx;
    u16 battleBgm;
    u16 preBattleRoomBgm;
    bool8 awardSymbol;
    u8 acePolicy;
    u16 aceSpecies;
};

struct FactoryBossTextSet
{
    const u8 *preBattleCallText;
    const u8 *battleIntroText;
    const u8 *battleStartText;
    const u8 *lastSwitchInSlideText;
    const u8 *lastLowHpSlideText;
    const u8 *battlePostWinText;
    const u8 *battleSpeechPlayerWon;
    const u8 *battleSpeechPlayerLost;
};

u8 GetActiveFactoryBossId(void);
const struct FactoryBossProfile *GetFactoryBossProfile(u8 bossId);
const struct FactoryBossProfile *GetActiveFactoryBossProfile(void);

#endif // GUARD_FACTORY_BOSS_H
