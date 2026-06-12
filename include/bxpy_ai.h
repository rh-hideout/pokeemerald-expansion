#ifndef GUARD_BXPY_AI_H
#define GUARD_BXPY_AI_H

#include "battle.h"
#include "battle_ai_main.h"

struct BXPYAiData
{
    u32 partyScores[MAX_BATTLERS_COUNT][PARTY_SIZE];
    u32 checkedMatchups; // Convenient debugging tool
};

void BXPY_GetChosenPartyMons(enum BattlerId battler, struct BXPYAiData *bxpyAiData, u32 monArray[], u32 monCount);
void BXPY_ScorePartyMons(enum BattlerId battler, struct BXPYAiData *bxpyAiData, struct AiLogicData *bxpyAiLogicData);
void BXPY_SetupBattlers(u32 battleFlags);

#endif // GUARD_BXPY_AI_H
