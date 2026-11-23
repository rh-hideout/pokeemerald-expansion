#include "global.h"
#include "battle.h"
#include "battle_setup.h"
#include "battle_controllers.h"
#include "battle_factory.h"
#include "battle_ai_record.h"
#include "constants/abilities.h"
#include "constants/hold_effects.h"
#include "constants/battle_ai.h"

void RecordLastUsedMoveBy(enum BattlerId battlerId, enum Move move)
{
    u8 *index = &gBattleHistory->moveHistoryIndex[battlerId];

    if (++(*index) >= AI_MOVE_HISTORY_COUNT)
        *index = 0;
    gBattleHistory->moveHistory[battlerId][*index] = move;
}

void RecordKnownMove(enum BattlerId battler, enum Move move)
{
    s32 moveIndex;

    for (moveIndex = 0; moveIndex < MAX_MON_MOVES; moveIndex++)
    {
        if (gBattleMons[battler].moves[moveIndex] == move)
            break;
    }

    if (moveIndex < MAX_MON_MOVES && gBattleHistory->usedMoves[battler][moveIndex] == MOVE_NONE)
    {
        gBattleHistory->usedMoves[battler][moveIndex] = move;
        GetRecordedPartyMonData(battler)->moves[moveIndex] = move;
    }
}

void RecordAllMoves(enum BattlerId battler)
{
    memcpy(GetRecordedPartyMonData(battler)->moves, gBattleMons[battler].moves, MAX_MON_MOVES * sizeof(u16));
}

void RecordAbilityBattle(enum BattlerId battlerId, enum Ability abilityId)
{
    gBattleHistory->abilities[battlerId] = abilityId;
    GetRecordedPartyMonData(battlerId)->ability = abilityId;
}

void RecordItemEffectBattle(enum BattlerId battlerId, enum HoldEffect itemEffect)
{
    gBattleHistory->itemEffects[battlerId] = itemEffect;
    GetRecordedPartyMonData(battlerId)->holdEffect = itemEffect;
}

void ClearBattlerAbilityHistory(enum BattlerId battlerId)
{
    gBattleHistory->abilities[battlerId] = ABILITY_NONE;
}

void ClearBattlerMoveHistory(enum BattlerId battlerId)
{
    memset(gBattleHistory->usedMoves[battlerId], 0, sizeof(gBattleHistory->usedMoves[battlerId]));
    memset(gBattleHistory->moveHistory[battlerId], 0, sizeof(gBattleHistory->moveHistory[battlerId]));
    gBattleHistory->moveHistoryIndex[battlerId] = 0;
}

void ClearBattlerItemEffectHistory(enum BattlerId battlerId)
{
    gBattleHistory->itemEffects[battlerId] = HOLD_EFFECT_NONE;
}

struct AiPartyMon *GetRecordedPartyMonData(enum BattlerId battler)
{
    return &gAiPartyData->mons[GetBattlerSide(battler)][gBattlerPartyIndexes[battler]];
}
