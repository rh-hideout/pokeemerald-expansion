#include "global.h"
#include "main.h"
#include "malloc.h"
#include "battle.h"
#include "battle_ai_util.h"
#include "battle_ai_main.h"
#include "battle_ai_switch.h"
#include "battle_controllers.h"
#include "bxpy_ai.h"
#include "random.h"

static void BXPY_CalcAiBattlerDamage(struct AiLogicData *aiData, enum BattlerId battlerAtk, enum BattlerId battlerDef);
static u32 BXPY_GetNoOfHitsToKOCandidate(enum BattlerId battlerAtk, enum BattlerId battlerDef, u32 moveIndex, enum DamageCalcContext calcContext, struct AiLogicData *bxpyAiLogicData);
static bool32 BXPY_CanCandidateWin1v1(enum BattlerId battler, enum BattlerId opposingBattler, struct AiLogicData *bxpyAiLogicData);
static void BXPY_SetCandidateAiData(enum BattlerId battler, struct AiLogicData *aiData);
static void BXPY_SetOpponentAiData(enum BattlerId battler, struct AiLogicData *aiData);
static enum Ability BXPY_DecideOpposingAbility(enum BattlerId battler);
static enum Item BXPY_DecideOpposingItem(enum BattlerId battler);

void BXPY_SetupBattlers(u32 battleFlags)
{
    bool32 isLink = (battleFlags & BATTLE_TYPE_LINK);
    bool32 isDouble = !!(battleFlags & BATTLE_TYPE_MORE_THAN_TWO_BATTLERS); // IsDoubleBattle
    bool32 isMaster = (battleFlags & BATTLE_TYPE_IS_MASTER);
    bool32 isRecorded = (battleFlags & BATTLE_TYPE_RECORDED);
    bool32 isRecordedMaster = (battleFlags & BATTLE_TYPE_RECORDED_IS_MASTER);
    bool32 isRecordedLink = (battleFlags & BATTLE_TYPE_RECORDED_LINK);
    bool32 isMulti = (battleFlags & BATTLE_TYPE_MULTI);
    bool32 isInGamePartner = (battleFlags & BATTLE_TYPE_INGAME_PARTNER);

    if (!isDouble)
        gBattlersCount = 2;
    else
        gBattlersCount = MAX_BATTLERS_COUNT;

    if ((battleFlags & BATTLE_TYPE_BATTLE_TOWER)
        || !isMulti
        || (!isLink && !isRecorded)
        || (isLink && !isDouble))
    {
        bool32 isPlayerPrimary;
        if (isLink)
            isPlayerPrimary = (isMaster || (isDouble && isMulti));
        else if (!isRecorded)
            isPlayerPrimary = TRUE;
        else if (isDouble)
            isPlayerPrimary = (isInGamePartner || isMulti || isMaster);
        else
            isPlayerPrimary = (!isRecordedLink || isRecordedMaster);

        gBattlerPositions[B_BATTLER_0] = isPlayerPrimary ? B_POSITION_PLAYER_LEFT : B_POSITION_OPPONENT_LEFT;
        gBattlerPositions[B_BATTLER_1] = isPlayerPrimary ? B_POSITION_OPPONENT_LEFT : B_POSITION_PLAYER_LEFT;
        if (isDouble)
        {
            gBattlerPositions[B_BATTLER_2] = isPlayerPrimary ? B_POSITION_PLAYER_RIGHT : B_POSITION_OPPONENT_RIGHT;
            gBattlerPositions[B_BATTLER_3] = isPlayerPrimary ? B_POSITION_OPPONENT_RIGHT : B_POSITION_PLAYER_RIGHT;
        }
    }
}

void BXPY_ScorePartyMons(enum BattlerId battler, struct BXPYAiData *bxpyAiData, struct AiLogicData *bxpyAiLogicData)
{
    DebugPrintf("Computing battler index: %d", battler);
    // AI's party
    s32 lastId = GetAILastPartyIndex(battler);
    struct Pokemon *party = GetBattlerParty(battler);
    
    // Other's party
    s32 opposingLastId = 0;
    struct Pokemon *opposingParty;

    // Check all party mons
    for (u32 monIndex = 0; monIndex < lastId; monIndex++)
    {
        // bxpyAiData->partyScores[battler][monIndex] = 0;
        if (!IsValidForBattle(&party[monIndex]))
            continue;
        DebugPrintf("Computing for party index: %d", monIndex);
        // Convert party data to battler data
        PokemonToBattleMon(&party[monIndex], &gBattleMons[battler]);
        BXPY_SetCandidateAiData(battler, bxpyAiLogicData);

        // Legal targets get a point, so we can throw out all positions containing 0 later
        bxpyAiData->partyScores[battler][monIndex] += 1;

        // Check each party mon against every opposing mon in every opposing party
        for (enum BattlerId opposingBattler = 0; opposingBattler < gBattlersCount; opposingBattler++)
        {
            if (battler == opposingBattler)
                continue;
            if (GetBattlerSide(battler) == GetBattlerSide(opposingBattler)) // Don't care about matchup against allies
                continue;
            DebugPrintf("Computing for opponent index :%d", opposingBattler);
            opposingLastId = GetAILastPartyIndex(opposingBattler);
            opposingParty = GetBattlerParty(opposingBattler);
            // Check current mon against all player mons
            for (u32 opposingMonIndex = 0; opposingMonIndex < opposingLastId; opposingMonIndex++)
            {
                if (!IsValidForBattle(&opposingParty[opposingMonIndex]))
                    continue;
                DebugPrintf("Computing for opposing party index: %d", opposingMonIndex);
                // Convert party data to battler data
                PokemonToBattleMon(&opposingParty[opposingMonIndex], &gBattleMons[opposingBattler]);
                BXPY_SetOpponentAiData(opposingBattler, bxpyAiLogicData);
                // Run move calcs for the two battlers
                if (BXPY_OPEN_TEAM_SHEET_SHOW_PLAYER_MOVES && BXPY_OPEN_TEAM_SHEET_SHOW_PLAYER_STATS)
                {
                    BXPY_CalcAiBattlerDamage(bxpyAiLogicData, battler, opposingBattler);
                    BXPY_CalcAiBattlerDamage(bxpyAiLogicData, opposingBattler, battler);
                }
                // Do scoring
                if (BXPY_CanCandidateWin1v1(battler, opposingBattler, bxpyAiLogicData) && BXPY_OPEN_TEAM_SHEET_SHOW_PLAYER_MOVES && BXPY_OPEN_TEAM_SHEET_SHOW_PLAYER_STATS)
                    bxpyAiData->partyScores[battler][monIndex] += CAN_1V1_MATCHUP_POINTS;                    
                if (GetBattlerTypeMatchup(opposingBattler, battler) < UQ_4_12(2.0))
                    bxpyAiData->partyScores[battler][monIndex] += DEFENSIVE_MATCHUP_POINTS;
                if (GetBattlerTypeMatchup(battler, opposingBattler) > UQ_4_12(2.0))
                    bxpyAiData->partyScores[battler][monIndex] += OFFENSIVE_MATCHUP_POINTS;
                if (gSpeciesInfo[gBattleMons[battler].species].baseSpeed > gSpeciesInfo[gBattleMons[opposingBattler].species].baseSpeed && BXPY_OPEN_TEAM_SHEET_SHOW_PLAYER_STATS)
                    bxpyAiData->partyScores[battler][monIndex] += OUTSPEED_MATCHUP_POINTS;
                bxpyAiData->checkedMatchups += 1;
            }
        }
    }
    DebugPrintf("Total checked matchups: %d", bxpyAiData->checkedMatchups);
    for (u32 monIndex = 0; monIndex < lastId; monIndex++)
    {
        DebugPrintf("Party Mon Score: %d", bxpyAiData->partyScores[battler][monIndex]);
    }
}

void BXPY_GetChosenPartyMons(enum BattlerId battler, struct BXPYAiData *bxpyAiData, u32 monArray[], u32 monCount)
{
    // Make a new array that's a copy of bxpyAiData->partyScores[battler]
    u32 scores[PARTY_SIZE];
    memcpy(scores, bxpyAiData->partyScores[battler], sizeof(bxpyAiData->partyScores[battler]));

    // Create an array of indexes
    u32 monIndexes[PARTY_SIZE];
    for (u32 i = 0; i < PARTY_SIZE; i++)
        monIndexes[i] = i;

    bool32 shouldSwap;
    // Bubble sort indexes based on scores
    for (u32 i = 0; i < PARTY_SIZE - 1; i++)
    {
        for (u32 j = 0; j < PARTY_SIZE - i - 1; j++)
        {
            shouldSwap = 0;
            // Compares values at these indexes, randomly ordering ties
            if (scores[monIndexes[j]] < scores[monIndexes[j + 1]])
            {
                shouldSwap = TRUE;
            }
            else if (scores[monIndexes[j]] == scores[monIndexes[j + 1]])
            {
                shouldSwap = Random() % 2;
            }

            if (shouldSwap)
            {
                // Swap if needed
                u32 temp = monIndexes[j];
                monIndexes[j] = monIndexes[j + 1];
                monIndexes[j + 1] = temp;
            }
        }
    }

    for (u32 i = 0; i < PARTY_SIZE; i++)
    {
        if (i >= monCount)
            monIndexes[i] = PARTY_SIZE;
    }

    memcpy(monArray, monIndexes, sizeof(monIndexes));
}

static void BXPY_CalcAiBattlerDamage(struct AiLogicData *aiData, enum BattlerId battlerAtk, enum BattlerId battlerDef)
{
    enum Move move;
    u32 moveLimitations = aiData->moveLimitations[battlerAtk];

    for (u32 moveIndex = 0; moveIndex < MAX_MON_MOVES; moveIndex++)
    {
        move = gBattleMons[battlerAtk].moves[moveIndex];
        if (IsMoveUnusable(moveIndex, move, moveLimitations))
            continue;
        struct SimulatedDamage dmg = {0};
        uq4_12_t effectiveness = Q_4_12(0.0);
        dmg = AI_CalcDamage(move, battlerAtk, battlerDef, &effectiveness, USE_GIMMICK, NO_GIMMICK, B_WEATHER_NONE, 0);
        aiData->simulatedDmg[battlerAtk][battlerDef][moveIndex] = dmg;
    }
}

static u32 BXPY_GetNoOfHitsToKOCandidate(enum BattlerId battlerAtk, enum BattlerId battlerDef, u32 moveIndex, enum DamageCalcContext calcContext, struct AiLogicData *bxpyAiLogicData)
{
    u32 hitsToKO = GetNoOfHitsToKOBattlerDmg(AI_GetDamage(battlerAtk, battlerDef, moveIndex, calcContext, bxpyAiLogicData), battlerDef);

    if (CanEndureHit(battlerAtk, battlerDef, gBattleMons[battlerAtk].moves[moveIndex]) && hitsToKO == 1)
        hitsToKO += 1;

    return hitsToKO;
}

static bool32 BXPY_CanCandidateWin1v1(enum BattlerId battler, enum BattlerId opposingBattler, struct AiLogicData *bxpyAiLogicData)
{
    enum Move move, opposingMove, bestOpposingMove = MOVE_NONE, bestOpposingPriorityMove = MOVE_NONE;
    u32 hitsToKO = 0, hitsToKOOpponent = 0, minHitsToKO = gBattleMons[battler].hp, minHitsToKOPriority = gBattleMons[battler].hp;
    bool32 canBattlerWin1v1 = FALSE, isBattlerFirst, isBattlerFirstPriority;

    // Get max damage mon could take
    for (u32 moveIndex = 0; moveIndex < MAX_MON_MOVES; moveIndex++)
    {
        opposingMove = gBattleMons[opposingBattler].moves[moveIndex];
        if (opposingMove != MOVE_NONE && !IsBattleMoveStatus(opposingMove) && GetMoveEffect(opposingMove) != EFFECT_FOCUS_PUNCH && gBattleMons[opposingBattler].pp[moveIndex] > 0)
        {
            hitsToKO = BXPY_GetNoOfHitsToKOCandidate(opposingBattler, battler, moveIndex, AI_DEFENDING, bxpyAiLogicData);
            if (hitsToKO < minHitsToKO)
            {
                bestOpposingMove = opposingMove;
                minHitsToKO = hitsToKO;
            }
            if (GetBattleMovePriority(opposingBattler, gAiLogicData->abilities[opposingBattler], opposingMove) > 0 && hitsToKO < minHitsToKOPriority)
            {
                bestOpposingPriorityMove = opposingMove;
                minHitsToKOPriority = hitsToKO;
            }
        }
    }

    DebugPrintf("Min hits to KO: %d", minHitsToKO);
    DebugPrintf("Min hits to KO priority: %d", minHitsToKOPriority);

    for (u32 moveIndex = 0; moveIndex < MAX_MON_MOVES; moveIndex++)
    {
        move = gBattleMons[battler].moves[moveIndex];
        if (move != MOVE_NONE && gBattleMons[battler].pp[moveIndex] > 0)
        {
            // Only check damage if it's a damaging move
            if (!IsBattleMoveStatus(move))
            {
                // Check if can win 1v1
                hitsToKOOpponent = BXPY_GetNoOfHitsToKOCandidate(battler, opposingBattler, moveIndex, AI_ATTACKING, bxpyAiLogicData);
                if (!canBattlerWin1v1) // Once we can win a 1v1 we don't need to track this, but want to run the rest of the function to keep the runtime the same regardless of when we find the winning move
                {
                    isBattlerFirst = AI_IsFaster(battler, opposingBattler, move, bestOpposingMove, CONSIDER_PRIORITY);
                    isBattlerFirstPriority = AI_IsFaster(battler, opposingBattler, move, bestOpposingPriorityMove, CONSIDER_PRIORITY);
                    canBattlerWin1v1 = CanBattlerWin1v1(minHitsToKO, hitsToKOOpponent, isBattlerFirst) && CanBattlerWin1v1(minHitsToKOPriority, hitsToKOOpponent, isBattlerFirstPriority);
                }
            }
        }
    }

    DebugPrintf("Can mon win 1v1: %d", canBattlerWin1v1);
    return canBattlerWin1v1;
}

// AI has full knowledge of its own mons; we have no AI flags or battle controllers to check against, so this is its own function
static void BXPY_SetCandidateAiData(enum BattlerId battler, struct AiLogicData *aiData)
{
    enum Ability ability;
    enum HoldEffect holdEffect;

    ability = aiData->abilities[battler] = gBattleMons[battler].ability;
    aiData->items[battler] = gBattleMons[battler].item;
    holdEffect = aiData->holdEffects[battler] = GetItemHoldEffect(gBattleMons[battler].item);
    aiData->hpPercents[battler] = GetHealthPercentage(battler);
    aiData->moveLimitations[battler] = CheckMoveLimitations(battler, 0, MOVE_LIMITATIONS_ALL);
    aiData->speedStats[battler] = GetBattlerTotalSpeedStat(battler, ability, holdEffect);
}

// AI does not necessarily have full knowledge of opposing mons
static void BXPY_SetOpponentAiData(enum BattlerId battler, struct AiLogicData *aiData)
{
    enum Ability ability;
    enum HoldEffect holdEffect;

    ability = aiData->abilities[battler] = BXPY_DecideOpposingAbility(battler);
    aiData->items[battler] = BXPY_DecideOpposingItem(battler);
    holdEffect = aiData->holdEffects[battler] = GetItemHoldEffect(gBattleMons[battler].item);
    aiData->hpPercents[battler] = GetHealthPercentage(battler);
    aiData->moveLimitations[battler] = CheckMoveLimitations(battler, 0, MOVE_LIMITATIONS_ALL);
    aiData->speedStats[battler] = GetBattlerTotalSpeedStat(battler, ability, holdEffect);
}

static enum Ability BXPY_DecideOpposingAbility(enum BattlerId battler)
{
    enum Ability validAbilities[NUM_ABILITY_SLOTS];
    u8 numValidAbilities = 0;
    enum Ability indexAbility;

    if (BXPY_OPEN_TEAM_SHEET_SHOW_PLAYER_ABILITY)
        return gBattleMons[battler].ability;

    for (u32 abilityIndex = 0; abilityIndex < NUM_ABILITY_SLOTS; abilityIndex++)
    {
        indexAbility = GetSpeciesAbility(gBattleMons[battler].species, abilityIndex);
        if (indexAbility != ABILITY_NONE)
            validAbilities[numValidAbilities++] = indexAbility;
    }

    if (numValidAbilities > 0)
        return validAbilities[RandomUniform(RNG_AI_ABILITY, 0, numValidAbilities - 1)];

    return ABILITY_NONE;
}

static enum Item BXPY_DecideOpposingItem(enum BattlerId battler)
{
    if (BXPY_OPEN_TEAM_SHEET_SHOW_PLAYER_ITEM)
        return gBattleMons[battler].item;
    
    return ITEM_NONE;
}
