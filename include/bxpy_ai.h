#ifndef GUARD_BXPY_AI_H
#define GUARD_BXPY_AI_H

#include "battle.h"
#include "battle_ai_main.h"

struct BXPYAiPartyData
{
    u32 scores[PARTY_SIZE];
    u32 checkedMatchups; // Convenient debugging tool
};

void BXPY_GetChosenPartyMons(struct BXPYAiPartyData *bxpyAiPartyData, u32 monArray[], u32 monCount);
void BXPY_ScorePartyMons(enum BattlerId battler, struct BXPYAiPartyData *bxpyAiPartyData);
void BXPY_ClearAIData(void);
void BXPY_SetupAIData(void);

#endif // GUARD_BXPY_AI_H
