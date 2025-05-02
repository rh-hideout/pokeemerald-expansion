#ifndef GUARD_BATTLE_ENVIRONMENT_H
#define GUARD_BATTLE_ENVIRONMENT_H

#include "constants/battle.h"
#include "battle_bg.h"

struct BattleEnvironment {
    u8 name[26];
    u16 naturePower;
    u16 secretPowerEffect;
    u8 camouflageType;
    struct BattleBackground background;
};

extern const struct BattleEnvironment gBattleEnvironmentInfo[BATTLE_ENVIRONMENT_COUNT];

#endif // GUARD_BATTLE_ENVIRONMENT_H
