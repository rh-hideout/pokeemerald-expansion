#include "global.h"
#include "main.h"
#include "malloc.h"
#include "battle.h"
#include "battle_util.h"
#include "battle_ai_util.h"
#include "battle_ai_main.h"
#include "battle_ai_switch.h"
#include "battle_setup.h"
#include "battle_controllers.h"
#include "bxpy_ai.h"
#include "field_weather.h"
#include "random.h"
#include "constants/battle_ai.h"

static void BXPY_CalcAiBattlerDamage(enum BattlerId battlerAtk, enum BattlerId battlerDef);
static bool32 BXPY_CanCandidateWin1v1(enum BattlerId battler, enum BattlerId opposingBattler);
static void BXPY_SetupBattlers(void);
static void BXPY_SetupAIFlags(void);
static void BXPY_InitializeAIStructs(void);
static u32 BXPY_GetWeather(void);
static u32 BXPY_GetFieldStatus(void);
static u32 BXPY_GetStartingWeather(void);
static u32 BXPY_GetStartingFieldStatus(void);

void BXPY_SetupAIData()
{
    BXPY_InitializeAIStructs();
    BXPY_SetupBattlers();
    BXPY_SetupAIFlags();
    InitializeStartingStatus();
}

void BXPY_SetupBattlers()
{
    bool32 isLink = (gBattleTypeFlags & BATTLE_TYPE_LINK);
    bool32 isDouble = IsDoubleBattle();
    bool32 isMaster =  (gBattleTypeFlags & BATTLE_TYPE_IS_MASTER);
    bool32 isRecorded = (gBattleTypeFlags & BATTLE_TYPE_RECORDED);
    bool32 isRecordedMaster = (gBattleTypeFlags & BATTLE_TYPE_RECORDED_IS_MASTER);
    bool32 isRecordedLink = (gBattleTypeFlags & BATTLE_TYPE_RECORDED_LINK);
    bool32 isMulti = (gBattleTypeFlags & BATTLE_TYPE_MULTI);
    bool32 isInGamePartner = (gBattleTypeFlags & BATTLE_TYPE_INGAME_PARTNER);

    if (!isDouble)
        gBattlersCount = 2;
    else
        gBattlersCount = MAX_BATTLERS_COUNT;

    if ((gBattleTypeFlags & BATTLE_TYPE_BATTLE_TOWER)
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

void BXPY_SetupAIFlags(void)
{
    gBattleStruct = AllocZeroed(sizeof(*gBattleStruct));
    memset(gAiThinkingStruct, 0, sizeof(struct AiThinkingStruct));
    gAiThinkingStruct->aiFlags[B_BATTLER_1] = GetAiFlags(TRAINER_BATTLE_PARAM.opponentA, B_BATTLER_1);
    if (TRAINER_BATTLE_PARAM.opponentB != TRAINER_NONE)
        gAiThinkingStruct->aiFlags[B_BATTLER_3] = GetAiFlags(TRAINER_BATTLE_PARAM.opponentB, B_BATTLER_3);
    else
        gAiThinkingStruct->aiFlags[B_BATTLER_3] = gAiThinkingStruct->aiFlags[B_BATTLER_1];

    if (gBattleTypeFlags & BATTLE_TYPE_INGAME_PARTNER)
    {
        gAiThinkingStruct->aiFlags[B_BATTLER_2] = GetAiFlags(gPartnerTrainerId, B_BATTLER_2);
    }
    else // Assign ai flags for player for prediction
    {
        u64 aiFlags = GetAiFlags(TRAINER_BATTLE_PARAM.opponentA, B_BATTLER_1)
                    | GetAiFlags(TRAINER_BATTLE_PARAM.opponentB, B_BATTLER_3);
        gAiThinkingStruct->aiFlags[B_BATTLER_2] = aiFlags;
        gAiThinkingStruct->aiFlags[B_BATTLER_0] = aiFlags;
    }
}

void BXPY_InitializeAIStructs(void)
{
    gAiThinkingStruct = AllocZeroed(sizeof(*gAiThinkingStruct));
    gAiLogicData = AllocZeroed(sizeof(*gAiLogicData));
    gBattleHistory = AllocZeroed(sizeof(*gBattleHistory));
}

void BXPY_ClearAIData(void)
{
    // Zero all AI globals used as a safety net
    gBattlersCount = 0;
    gBattleTypeFlags = 0;
    memset(gBattlerPositions, 0, sizeof(gBattlerPositions));
    ResetStartingStatuses();
    FREE_AND_SET_NULL(gAiThinkingStruct);
    FREE_AND_SET_NULL(gAiLogicData);
    FREE_AND_SET_NULL(gBattleHistory);
}

void BXPY_ScorePartyMons(enum BattlerId battler, struct BXPYAiPartyData *bxpyAiPartyData)
{
    // AI's party
    s32 lastId = GetAILastPartyIndex(battler);
    struct Pokemon *party = GetBattlerParty(battler);
    
    // Other's party
    s32 opposingLastId = 0;
    struct Pokemon *opposingParty;

    // Check all party mons
    for (u32 monIndex = 0; monIndex < lastId; monIndex++)
    {
        if (!IsValidForBattle(&party[monIndex]))
            continue;
        // Convert party data to battler data
        PokemonToBattleMon(&party[monIndex], &gBattleMons[battler]);
        SetBattlerAiData(battler, gAiLogicData);

        // Legal targets get a point, so we can throw out all positions containing 0 later
        bxpyAiPartyData->scores[monIndex] += 1;

        // Check each party mon against every opposing mon in every opposing party
        for (enum BattlerId opposingBattler = 0; opposingBattler < gBattlersCount; opposingBattler++)
        {
            if (battler == opposingBattler)
                continue;
            if (GetBattlerSide(battler) == GetBattlerSide(opposingBattler)) // Don't care about matchup against allies
                continue;
            opposingLastId = GetAILastPartyIndex(opposingBattler);
            opposingParty = GetBattlerParty(opposingBattler);
            // Check current mon against all player mons
            for (u32 opposingMonIndex = 0; opposingMonIndex < opposingLastId; opposingMonIndex++)
            {
                if (!IsValidForBattle(&opposingParty[opposingMonIndex]))
                    continue;
                // Convert party data to battler data
                PokemonToBattleMon(&opposingParty[opposingMonIndex], &gBattleMons[opposingBattler]);
                SetBattlerAiData(opposingBattler, gAiLogicData);
                // Run move calcs for the two battlers if needed
                BXPY_CalcAiBattlerDamage(battler, opposingBattler);
                BXPY_CalcAiBattlerDamage(opposingBattler, battler);
                // Do scoring
                if (BXPY_CanCandidateWin1v1(battler, opposingBattler))
                    bxpyAiPartyData->scores[monIndex] += CAN_1V1_MATCHUP_POINTS;
                if (GetBattlerTypeMatchup(opposingBattler, battler) < UQ_4_12(2.0))
                    bxpyAiPartyData->scores[monIndex] += DEFENSIVE_MATCHUP_POINTS;
                if (GetBattlerTypeMatchup(battler, opposingBattler) > UQ_4_12(2.0))
                    bxpyAiPartyData->scores[monIndex] += OFFENSIVE_MATCHUP_POINTS;
                if (gAiLogicData->speedStats[battler] >= gAiLogicData->speedStats[opposingBattler])
                    bxpyAiPartyData->scores[monIndex] += OUTSPEED_MATCHUP_POINTS;
                bxpyAiPartyData->checkedMatchups += 1;
            }
            if (BXPY_AI_DEBUG)
                DebugPrintf("%S, Index: %d, Score: %d", gSpeciesInfo[gBattleMons[battler].species].speciesName, monIndex, bxpyAiPartyData->scores[monIndex]);
        }
    }
    if (BXPY_AI_DEBUG)
        DebugPrintf("Battler %d checked %d matchups", battler, bxpyAiPartyData->checkedMatchups);
}

void BXPY_GetChosenPartyMons(struct BXPYAiPartyData *bxpyAiPartyData, u32 monArray[], u32 monCount)
{
    // Make a new array that's a copy of bxpyAiPartyData->scores
    u32 scores[PARTY_SIZE];
    memcpy(scores, bxpyAiPartyData->scores, sizeof(bxpyAiPartyData->scores));

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

static void BXPY_CalcAiBattlerDamage(enum BattlerId battlerAtk, enum BattlerId battlerDef)
{
    enum Move move;
    u32 moveLimitations = gAiLogicData->moveLimitations[battlerAtk];
    u32 weather = BXPY_GetWeather();
    u32 fieldStatus = BXPY_GetFieldStatus();

    for (u32 moveIndex = 0; moveIndex < MAX_MON_MOVES; moveIndex++)
    {
        move = gBattleMons[battlerAtk].moves[moveIndex];
        if (IsMoveUnusable(moveIndex, move, moveLimitations))
            continue;
        struct SimulatedDamage dmg = {0};
        uq4_12_t effectiveness = Q_4_12(0.0);
        dmg = AI_CalcDamage(move, battlerAtk, battlerDef, &effectiveness, USE_GIMMICK, NO_GIMMICK, weather, fieldStatus);
        gAiLogicData->simulatedDmg[battlerAtk][battlerDef][moveIndex] = dmg;
    }
}

static bool32 BXPY_CanCandidateWin1v1(enum BattlerId battler, enum BattlerId opposingBattler)
{
    enum Move move, opposingMove, bestOpposingMove = MOVE_NONE, bestOpposingPriorityMove = MOVE_NONE;
    u32 hitsToKO = gBattleMons[battler].hp;
    u32 hitsToKOOpponent = gBattleMons[opposingBattler].hp;
    u32 minHitsToKO = gBattleMons[battler].hp;
    u32 minHitsToKOPriority = gBattleMons[battler].hp;
    bool32 canBattlerWin1v1 = FALSE, isBattlerFirst, isBattlerFirstPriority;

    // Get max damage mon could take
    for (u32 moveIndex = 0; moveIndex < MAX_MON_MOVES; moveIndex++)
    {
        opposingMove = gBattleMons[opposingBattler].moves[moveIndex];
        if (opposingMove != MOVE_NONE && !IsBattleMoveStatus(opposingMove) && GetMoveEffect(opposingMove) != EFFECT_FOCUS_PUNCH && gBattleMons[opposingBattler].pp[moveIndex] > 0)
        {
            hitsToKO = GetNoOfHitsToKOBattler(opposingBattler, battler, moveIndex, AI_DEFENDING, CONSIDER_ENDURE);
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

    for (u32 moveIndex = 0; moveIndex < MAX_MON_MOVES; moveIndex++)
    {
        move = gBattleMons[battler].moves[moveIndex];
        if (move != MOVE_NONE && gBattleMons[battler].pp[moveIndex] > 0)
        {
            // Only check damage if it's a damaging move
            if (!IsBattleMoveStatus(move))
            {
                // Check if can win 1v1
                hitsToKOOpponent = GetNoOfHitsToKOBattler(battler, opposingBattler, moveIndex, AI_ATTACKING, CONSIDER_ENDURE);
                if (!canBattlerWin1v1) // Once we can win a 1v1 we don't need to track this, but want to run the rest of the function to keep the runtime the same regardless of when we find the winning move
                {
                    isBattlerFirst = AI_IsFaster(battler, opposingBattler, move, bestOpposingMove, CONSIDER_PRIORITY);
                    isBattlerFirstPriority = AI_IsFaster(battler, opposingBattler, move, bestOpposingPriorityMove, CONSIDER_PRIORITY);
                    canBattlerWin1v1 = CanBattlerWin1v1(minHitsToKO, hitsToKOOpponent, isBattlerFirst) && CanBattlerWin1v1(minHitsToKOPriority, hitsToKOOpponent, isBattlerFirstPriority);
                }
            }
        }
    }

    return canBattlerWin1v1;
}

static u32 BXPY_GetWeather()
{
    u32 startingWeather = BXPY_GetStartingWeather();
    if (startingWeather != B_WEATHER_NONE)
        return startingWeather;
    return GetBattleWeatherFromOverworldWeather(GetCurrentWeather());
}

static u32 BXPY_GetFieldStatus()
{
    u32 startingFieldStatus = GetBattleTerrainFromOverworldWeather(GetCurrentWeather());
    startingFieldStatus |= BXPY_GetStartingFieldStatus(); // Overrides overworld effects
    return startingFieldStatus;
}

static u32 BXPY_GetStartingWeather()
{
    u32 weather = B_WEATHER_NONE;
    if (gStartingStatuses.weatherSun || gStartingStatuses.weatherSunTemporary)
        weather = B_WEATHER_SUN;
    else if (gStartingStatuses.weatherRain || gStartingStatuses.weatherRainTemporary)
        weather = B_WEATHER_RAIN;
    else if (gStartingStatuses.weatherSandstorm || gStartingStatuses.weatherSandstormTemporary)
        weather = B_WEATHER_SANDSTORM;
    else if (gStartingStatuses.weatherHail || gStartingStatuses.weatherHailTemporary)
        weather = B_WEATHER_HAIL;
    else if (gStartingStatuses.weatherSnow || gStartingStatuses.weatherSnowTemporary)
        weather = B_WEATHER_SNOW;
    else if (gStartingStatuses.weatherFog || gStartingStatuses.weatherFogTemporary)
        weather = B_WEATHER_FOG;
    return weather;

}

static u32 BXPY_GetStartingFieldStatus()
{
    u32 fieldStatus = STATUS_FIELD_NONE;
    if (gStartingStatuses.electricTerrain || gStartingStatuses.electricTerrainTemporary)
        fieldStatus |= STATUS_FIELD_ELECTRIC_TERRAIN;
    else if (gStartingStatuses.mistyTerrain || gStartingStatuses.mistyTerrainTemporary)
        fieldStatus |= STATUS_FIELD_MISTY_TERRAIN;
    else if (gStartingStatuses.grassyTerrain || gStartingStatuses.grassyTerrainTemporary)
        fieldStatus |= STATUS_FIELD_GRASSY_TERRAIN;
    else if (gStartingStatuses.psychicTerrain || gStartingStatuses.psychicTerrainTemporary)
        fieldStatus |= STATUS_FIELD_PSYCHIC_TERRAIN;
    else if (gStartingStatuses.trickRoom || gStartingStatuses.trickRoomTemporary)
        fieldStatus |= STATUS_FIELD_TRICK_ROOM;
    else if (gStartingStatuses.magicRoom || gStartingStatuses.magicRoomTemporary)
        fieldStatus |= STATUS_FIELD_MAGIC_ROOM;
    else if (gStartingStatuses.wonderRoom || gStartingStatuses.wonderRoomTemporary)
        fieldStatus |= STATUS_FIELD_WONDER_ROOM;
    return fieldStatus;
}
