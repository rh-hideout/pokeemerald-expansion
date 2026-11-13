#include "global.h"
#include "battle.h"
#include "battle_frontier.h"
#include "battle_factory.h"
#include "battle_factory_screen.h"
#include "event_data.h"
#include "battle_setup.h"
#include "overworld.h"
#include "frontier_util.h"
#include "battle_tower.h"
#include "random.h"
#include "constants/battle_ai.h"
#include "constants/battle_factory.h"
#include "constants/battle_frontier.h"
#include "constants/battle_frontier_mons.h"
#include "constants/battle_tent.h"
#include "constants/frontier_util.h"
#include "constants/layouts.h"
#include "constants/trainers.h"
#include "constants/moves.h"
#include "constants/items.h"

static bool8 sPerformedRentalSwap;

static void InitFactoryChallenge(void);
static void GetBattleFactoryData(void);
static void SetBattleFactoryData(void);
static void SaveFactoryChallenge(void);
static void FactoryDummy1(void);
static void FactoryDummy2(void);
static void SelectInitialRentalMons(void);
static void SwapRentalMons(void);
static void SetPerformedRentalSwap(void);
static void SetRentalsToOpponentParty(void);
static void SetPlayerAndOpponentParties(void);
static void SetOpponentGfxVar(void);
static void GenerateOpponentMons(void);
static void GetOpponentMostCommonMonType(void);
static void GetOpponentBattleStyle(void);
static void RestorePlayerPartyHeldItems(void);
static enum FactoryStyle GetMoveBattleStyle(enum Move move);

// Number of moves needed on the team to be considered using a certain battle style
static const u8 sRequiredMoveCounts[FACTORY_NUM_STYLES - 1] = {
    [FACTORY_STYLE_PREPARATION - 1]   = 3,
    [FACTORY_STYLE_SLOW_STEADY - 1]   = 3,
    [FACTORY_STYLE_ENDURANCE - 1]     = 3,
    [FACTORY_STYLE_HIGH_RISK - 1]     = 2,
    [FACTORY_STYLE_WEAKENING - 1]     = 2,
    [FACTORY_STYLE_UNPREDICTABLE - 1] = 2,
    [FACTORY_STYLE_WEATHER - 1]       = 2
};

static void (*const sBattleFactoryFunctions[])(void) =
{
    [BATTLE_FACTORY_FUNC_INIT]                   = InitFactoryChallenge,
    [BATTLE_FACTORY_FUNC_GET_DATA]               = GetBattleFactoryData,
    [BATTLE_FACTORY_FUNC_SET_DATA]               = SetBattleFactoryData,
    [BATTLE_FACTORY_FUNC_SAVE]                   = SaveFactoryChallenge,
    [BATTLE_FACTORY_FUNC_NULL]                   = FactoryDummy1,
    [BATTLE_FACTORY_FUNC_NULL2]                  = FactoryDummy2,
    [BATTLE_FACTORY_FUNC_SELECT_RENT_MONS]       = SelectInitialRentalMons,
    [BATTLE_FACTORY_FUNC_SWAP_RENT_MONS]         = SwapRentalMons,
    [BATTLE_FACTORY_FUNC_SET_SWAPPED]            = SetPerformedRentalSwap,
    [BATTLE_FACTORY_FUNC_SET_OPPONENT_MONS]      = SetRentalsToOpponentParty,
    [BATTLE_FACTORY_FUNC_SET_PARTIES]            = SetPlayerAndOpponentParties,
    [BATTLE_FACTORY_FUNC_SET_OPPONENT_GFX]       = SetOpponentGfxVar,
    [BATTLE_FACTORY_FUNC_GENERATE_OPPONENT_MONS] = GenerateOpponentMons,
    [BATTLE_FACTORY_FUNC_GENERATE_RENTAL_MONS]   = FactoryGenerateInitialRentalMons,
    [BATTLE_FACTORY_FUNC_GET_OPPONENT_MON_TYPE]  = GetOpponentMostCommonMonType,
    [BATTLE_FACTORY_FUNC_GET_OPPONENT_STYLE]     = GetOpponentBattleStyle,
    [BATTLE_FACTORY_FUNC_RESET_HELD_ITEMS]       = RestorePlayerPartyHeldItems,
};

static const u32 sWinStreakFlags[][2] =
{
    {STREAK_FACTORY_SINGLES_50, STREAK_FACTORY_SINGLES_OPEN},
    {STREAK_FACTORY_DOUBLES_50, STREAK_FACTORY_DOUBLES_OPEN},
};

static const u32 sWinStreakMasks[][2] =
{
    {~(STREAK_FACTORY_SINGLES_50), ~(STREAK_FACTORY_SINGLES_OPEN)},
    {~(STREAK_FACTORY_DOUBLES_50), ~(STREAK_FACTORY_DOUBLES_OPEN)},
};

static const u8 sFixedIVTable[][2] =
{
    {3, 6},
    {6, 9},
    {9, 12},
    {12, 15},
    {15, 18},
    {21, 31},
    {31, 31},
};

struct FrontierMonPool
{
    u16 begin;
    u16 end;
};

#define FRONTIER_MON_RANGE_POOL(a, b) {.begin = a, .end = b}

static const struct FrontierMonPool sInitialRentalMonPools[][FRONTIER_STAGES_PER_CHALLENGE + 1] =
{
    // Level 50
    [FRONTIER_LVL_50] =
    {
        FRONTIER_MON_RANGE_POOL(FRONTIER_MON_GRIMER,     FRONTIER_MON_FURRET_1),   // 110 - 199
        FRONTIER_MON_RANGE_POOL(FRONTIER_MON_DELCATTY_1, FRONTIER_MON_CLOYSTER_1), // 162 - 266
        FRONTIER_MON_RANGE_POOL(FRONTIER_MON_DELCATTY_2, FRONTIER_MON_CLOYSTER_2), // 267 - 371
        FRONTIER_MON_RANGE_POOL(FRONTIER_MON_DUGTRIO_1,  FRONTIER_MON_SLAKING_1),  // 372 - 467
        FRONTIER_MON_RANGE_POOL(FRONTIER_MON_DUGTRIO_2,  FRONTIER_MON_SLAKING_2),  // 468 - 563
        FRONTIER_MON_RANGE_POOL(FRONTIER_MON_DUGTRIO_3,  FRONTIER_MON_SLAKING_3),  // 564 - 659
        FRONTIER_MON_RANGE_POOL(FRONTIER_MON_DUGTRIO_4,  FRONTIER_MON_SLAKING_4),  // 660 - 755
        FRONTIER_MON_RANGE_POOL(FRONTIER_MON_DUGTRIO_1,  FRONTIER_MON_LATIOS_8),   // 372 - 849
    },

    // Open level
    [FRONTIER_LVL_OPEN] =
    {
        FRONTIER_MON_RANGE_POOL(FRONTIER_MON_DUGTRIO_1, FRONTIER_MON_SLAKING_1), // 372 - 467
        FRONTIER_MON_RANGE_POOL(FRONTIER_MON_DUGTRIO_2, FRONTIER_MON_SLAKING_2), // 468 - 563
        FRONTIER_MON_RANGE_POOL(FRONTIER_MON_DUGTRIO_3, FRONTIER_MON_SLAKING_3), // 564 - 659
        FRONTIER_MON_RANGE_POOL(FRONTIER_MON_DUGTRIO_4, FRONTIER_MON_SLAKING_4), // 660 - 755
        FRONTIER_MON_RANGE_POOL(FRONTIER_MON_DUGTRIO_1, NUM_FRONTIER_MONS - 1),  // 372 - 881
        FRONTIER_MON_RANGE_POOL(FRONTIER_MON_DUGTRIO_1, NUM_FRONTIER_MONS - 1),  // 372 - 881
        FRONTIER_MON_RANGE_POOL(FRONTIER_MON_DUGTRIO_1, NUM_FRONTIER_MONS - 1),  // 372 - 881
        FRONTIER_MON_RANGE_POOL(FRONTIER_MON_DUGTRIO_1, NUM_FRONTIER_MONS - 1),  // 372 - 881
    },
};

// code
void CallBattleFactoryFunction(void)
{
    sBattleFactoryFunctions[gSpecialVar_0x8004]();
}

static void InitFactoryChallenge(void)
{
    u8 i;
    enum FrontierLevelMode lvlMode = gSaveBlock2Ptr->frontier.lvlMode;
    u32 battleMode = VarGet(VAR_FRONTIER_BATTLE_MODE);

    gSaveBlock2Ptr->frontier.challengeStatus = 0;
    gSaveBlock2Ptr->frontier.curChallengeBattleNum = 0;
    gSaveBlock2Ptr->frontier.challengePaused = FALSE;
    gSaveBlock2Ptr->frontier.disableRecordBattle = FALSE;
    if (!(gSaveBlock2Ptr->frontier.winStreakActiveFlags & sWinStreakFlags[battleMode][lvlMode]))
    {
        gSaveBlock2Ptr->frontier.factoryWinStreaks[battleMode][lvlMode] = 0;
        gSaveBlock2Ptr->frontier.factoryRentsCount[battleMode][lvlMode] = 0;
    }

    sPerformedRentalSwap = FALSE;
    for (i = 0; i < ARRAY_COUNT(gSaveBlock2Ptr->frontier.rentalMons); i++)
        gSaveBlock2Ptr->frontier.rentalMons[i].monId = 0xFFFF;
    for (i = 0; i < FRONTIER_PARTY_SIZE; i++)
        gFrontierTempParty[i] = 0xFFFF;

    SetDynamicWarp(0, gSaveBlock1Ptr->location.mapGroup, gSaveBlock1Ptr->location.mapNum, WARP_ID_NONE);
    TRAINER_BATTLE_PARAM.opponentA = 0;
}

static void GetBattleFactoryData(void)
{
    int lvlMode = gSaveBlock2Ptr->frontier.lvlMode;
    int battleMode = VarGet(VAR_FRONTIER_BATTLE_MODE);

    switch (gSpecialVar_0x8005)
    {
    case FACTORY_DATA_WIN_STREAK:
        gSpecialVar_Result = gSaveBlock2Ptr->frontier.factoryWinStreaks[battleMode][lvlMode];
        break;
    case FACTORY_DATA_WIN_STREAK_ACTIVE:
        gSpecialVar_Result = ((gSaveBlock2Ptr->frontier.winStreakActiveFlags & sWinStreakFlags[battleMode][lvlMode]) != 0);
        break;
    case FACTORY_DATA_WIN_STREAK_SWAPS:
        gSpecialVar_Result = gSaveBlock2Ptr->frontier.factoryRentsCount[battleMode][lvlMode];
        break;
    }
}

static void SetBattleFactoryData(void)
{
    int lvlMode = gSaveBlock2Ptr->frontier.lvlMode;
    int battleMode = VarGet(VAR_FRONTIER_BATTLE_MODE);

    switch (gSpecialVar_0x8005)
    {
    case FACTORY_DATA_WIN_STREAK:
        gSaveBlock2Ptr->frontier.factoryWinStreaks[battleMode][lvlMode] = gSpecialVar_0x8006;
        break;
    case FACTORY_DATA_WIN_STREAK_ACTIVE:
        if (gSpecialVar_0x8006)
            gSaveBlock2Ptr->frontier.winStreakActiveFlags |= sWinStreakFlags[battleMode][lvlMode];
        else
            gSaveBlock2Ptr->frontier.winStreakActiveFlags &= sWinStreakMasks[battleMode][lvlMode];
        break;
    case FACTORY_DATA_WIN_STREAK_SWAPS:
        if (sPerformedRentalSwap == TRUE)
        {
            gSaveBlock2Ptr->frontier.factoryRentsCount[battleMode][lvlMode] = gSpecialVar_0x8006;
            sPerformedRentalSwap = FALSE;
        }
        break;
    }
}

static void SaveFactoryChallenge(void)
{
    ClearEnemyPartyAfterChallenge();
    gSaveBlock2Ptr->frontier.challengeStatus = gSpecialVar_0x8005;
    VarSet(VAR_TEMP_CHALLENGE_STATUS, 0);
    gSaveBlock2Ptr->frontier.challengePaused = TRUE;
    SaveGameFrontier();
}

static void FactoryDummy1(void)
{

}

static void FactoryDummy2(void)
{

}

static void SelectInitialRentalMons(void)
{
    ZeroPlayerPartyMons();
    DoBattleFactorySelectScreen();
}

static void SwapRentalMons(void)
{
    DoBattleFactorySwapScreen();
}

static void SetPerformedRentalSwap(void)
{
    sPerformedRentalSwap = TRUE;
}

static void GenerateOpponentMons(void)
{
    s32 i;
    struct FacilityMonGenerator generator = GetFacilityMonGenerator(0xFFFF);
    u16 trainerId = 0;
    u32 challengeNum = gSaveBlock2Ptr->frontier.factoryWinStreaks[generator.battleMode][generator.lvlMode] / FRONTIER_STAGES_PER_CHALLENGE;

    do
    {
        // Choose a random trainer, ensuring no repeats in this challenge
        trainerId = GetRandomScaledFrontierTrainerId(challengeNum, gSaveBlock2Ptr->frontier.curChallengeBattleNum);
        for (i = 0; i < gSaveBlock2Ptr->frontier.curChallengeBattleNum; i++)
        {
            if (gSaveBlock2Ptr->frontier.trainerIds[i] == trainerId)
                break;
        }
    } while (i != gSaveBlock2Ptr->frontier.curChallengeBattleNum);

    TRAINER_BATTLE_PARAM.opponentA = trainerId;
    if (gSaveBlock2Ptr->frontier.curChallengeBattleNum < FRONTIER_STAGES_PER_CHALLENGE - 1)
        gSaveBlock2Ptr->frontier.trainerIds[gSaveBlock2Ptr->frontier.curChallengeBattleNum] = trainerId;

    generator.partySize = FRONTIER_PARTY_SIZE;
    PickRandomFacilityMons(&generator, trainerId, gFrontierTempParty);
}

static void SetOpponentGfxVar(void)
{
    SetBattleFacilityTrainerGfxId(TRAINER_BATTLE_PARAM.opponentA, 0);
}

static void SetRentalsToOpponentParty(void)
{
    u8 i;

    if (gSaveBlock2Ptr->frontier.lvlMode != FRONTIER_LVL_TENT)
        gFacilityTrainerMons = gBattleFrontierMons;
    else
        gFacilityTrainerMons = gSlateportBattleTentMons;

    for (i = 0; i < FRONTIER_PARTY_SIZE; i++)
    {
        gSaveBlock2Ptr->frontier.rentalMons[i + FRONTIER_PARTY_SIZE].monId = gFrontierTempParty[i];
        gSaveBlock2Ptr->frontier.rentalMons[i + FRONTIER_PARTY_SIZE].ivs = GetBoxMonData(&gParties[B_TRAINER_OPPONENT_A][i].box, MON_DATA_ATK_IV);
        gSaveBlock2Ptr->frontier.rentalMons[i + FRONTIER_PARTY_SIZE].personality = GetMonData(&gParties[B_TRAINER_OPPONENT_A][i], MON_DATA_PERSONALITY);
        gSaveBlock2Ptr->frontier.rentalMons[i + FRONTIER_PARTY_SIZE].abilityNum = GetBoxMonData(&gParties[B_TRAINER_OPPONENT_A][i].box, MON_DATA_ABILITY_NUM);
        SetMonData(&gParties[B_TRAINER_OPPONENT_A][i], MON_DATA_HELD_ITEM, &gFacilityTrainerMons[gFrontierTempParty[i]].heldItem);
    }
}

static void CreateRentalMon(struct Pokemon *dst, struct RentalMon *rentalMon, u32 level)
{
    u32 data;
    const struct TrainerMon *fmon = &gFacilityTrainerMons[rentalMon->monId];
    CreateMonWithIVs(dst, fmon->species, level, rentalMon->personality, OTID_STRUCT_PLAYER_ID, rentalMon->ivs);
    SetMonData(dst, MON_DATA_ABILITY_NUM, &rentalMon->abilityNum);

    u32 friendship = MAX_FRIENDSHIP;
    for (u32 i = 0; i < MAX_MON_MOVES; i++)
    {
        enum Move move = fmon->moves[i];
        if (move == MOVE_RETURN)
            move = MOVE_FRUSTRATION;

        SetMonMoveSlot(dst, move, i);
        if (GetMoveEffect(move) == EFFECT_FRUSTRATION)
            friendship = 0;
    }

    SetMonData(dst, MON_DATA_FRIENDSHIP, &friendship);
    SetMonData(dst, MON_DATA_HELD_ITEM, &fmon->heldItem);

    if (fmon->ev != NULL)
    {
        SetMonData(dst, MON_DATA_HP_EV, &(fmon->ev[0]));
        SetMonData(dst, MON_DATA_ATK_EV, &(fmon->ev[1]));
        SetMonData(dst, MON_DATA_DEF_EV, &(fmon->ev[2]));
        SetMonData(dst, MON_DATA_SPATK_EV, &(fmon->ev[3]));
        SetMonData(dst, MON_DATA_SPDEF_EV, &(fmon->ev[4]));
        SetMonData(dst, MON_DATA_SPEED_EV, &(fmon->ev[5]));
    }

    if (fmon->isShiny)
    {
        data = TRUE;
        SetMonData(dst, MON_DATA_IS_SHINY, &data);
    }
    if (fmon->dynamaxLevel > 0)
    {
        data = fmon->dynamaxLevel;
        SetMonData(dst, MON_DATA_DYNAMAX_LEVEL, &data);
    }
    if (fmon->gigantamaxFactor)
    {
        data = fmon->gigantamaxFactor;
        SetMonData(dst, MON_DATA_GIGANTAMAX_FACTOR, &data);
    }
    if (fmon->teraType)
    {
        data = fmon->teraType;
        SetMonData(dst, MON_DATA_TERA_TYPE, &data);
    }

    if (fmon->ball < POKEBALL_COUNT)
    {
        data = fmon->ball;
        SetMonData(dst, MON_DATA_POKEBALL, &data);
    }
    CalculateMonStats(dst);
}

static void SetPlayerAndOpponentParties(void)
{
    u32 monLevel;
    if (gSaveBlock2Ptr->frontier.lvlMode == FRONTIER_LVL_TENT)
    {
        gFacilityTrainerMons = gSlateportBattleTentMons;
        monLevel = TENT_MIN_LEVEL;
    }
    else
    {
        gFacilityTrainerMons = gBattleFrontierMons;
        if (gSaveBlock2Ptr->frontier.lvlMode != FRONTIER_LVL_50)
            monLevel = FRONTIER_MAX_LEVEL_OPEN;
        else
            monLevel = FRONTIER_MAX_LEVEL_50;
    }

    ZeroPlayerPartyMons();
    for (u32 i = 0; i < FRONTIER_PARTY_SIZE; i++)
    {
        CreateRentalMon(&gParties[B_TRAINER_PLAYER][i], &gSaveBlock2Ptr->frontier.rentalMons[i], monLevel);
    }

    ZeroEnemyPartyMons();
    for (u32 i = 0; i < FRONTIER_PARTY_SIZE; i++)
    {
        CreateRentalMon(&gParties[B_TRAINER_OPPONENT_A][i], &gSaveBlock2Ptr->frontier.rentalMons[i + FRONTIER_PARTY_SIZE], monLevel);
    }
}

void FactoryGenerateInitialRentalMons(void)
{
    u16 tmp[2 * FRONTIER_PARTY_SIZE];
    struct FacilityMonGenerator generator = GetFacilityMonGenerator(0xFFFF);
    generator.partySize = 2 * FRONTIER_PARTY_SIZE;
    PickRandomFacilityMons(&generator, 0xFFFF, tmp);
    for (u32 i = 0; i < 2 * FRONTIER_PARTY_SIZE; i++)
    {
        gSaveBlock2Ptr->frontier.rentalMons[i].monId = tmp[i];
    }
}

// Determines if the upcoming opponent has a single most-common
// type in its party. If there are two different types that are
// tied, then the opponent is deemed to have no preferred type,
// and NUMBER_OF_MON_TYPES is the result.
static void GetOpponentMostCommonMonType(void)
{
    u8 i;
    u8 typeCounts[NUMBER_OF_MON_TYPES];
    u8 mostCommonTypes[2];

    gFacilityTrainerMons = gBattleFrontierMons;

    // Count the number of times each type occurs in the opponent's party.
    for (i = TYPE_NORMAL; i < NUMBER_OF_MON_TYPES; i++)
        typeCounts[i] = 0;
    for (i = 0; i < FRONTIER_PARTY_SIZE; i++)
    {
        enum Species species = gFacilityTrainerMons[gFrontierTempParty[i]].species;
        typeCounts[GetSpeciesType(species, 0)]++;
        if (GetSpeciesType(species, 0) != GetSpeciesType(species, 1))
            typeCounts[GetSpeciesType(species, 1)]++;
    }

    // Determine which are the two most-common types.
    // The second most-common type is only updated if
    // its count is equal to the most-common type.
    mostCommonTypes[0] = 0;
    mostCommonTypes[1] = 0;
    for (i = 1; i < NUMBER_OF_MON_TYPES; i++)
    {
        if (typeCounts[mostCommonTypes[0]] < typeCounts[i])
            mostCommonTypes[0] = i;
        else if (typeCounts[mostCommonTypes[0]] == typeCounts[i])
            mostCommonTypes[1] = i;
    }

    if (typeCounts[mostCommonTypes[0]] != 0)
    {
        // The most-common type must be strictly greater than
        // the second-most-common type, or the top two must be
        // the same type.
        if (typeCounts[mostCommonTypes[0]] > typeCounts[mostCommonTypes[1]])
            gSpecialVar_Result = mostCommonTypes[0];
        else if (mostCommonTypes[0] == mostCommonTypes[1])
            gSpecialVar_Result = mostCommonTypes[0];
        else
            gSpecialVar_Result = NUMBER_OF_MON_TYPES;
    }
    else
    {
        gSpecialVar_Result = NUMBER_OF_MON_TYPES;
    }
}

static void GetOpponentBattleStyle(void)
{
    u8 i, j, count;
    u8 stylePoints[FACTORY_NUM_STYLES];

    count = 0;
    gFacilityTrainerMons = gBattleFrontierMons;
    for (i = 0; i < FACTORY_NUM_STYLES; i++)
        stylePoints[i] = 0;

    for (i = 0; i < FRONTIER_PARTY_SIZE; i++)
    {
        u16 monId = gFrontierTempParty[i];
        for (j = 0; j < MAX_MON_MOVES; j++)
        {
            u8 battleStyle = GetMoveBattleStyle(gFacilityTrainerMons[monId].moves[j]);
            stylePoints[battleStyle]++;
        }
    }

    gSpecialVar_Result = FACTORY_STYLE_NONE;
    for (i = 1; i < FACTORY_NUM_STYLES; i++)
    {
        if (stylePoints[i] >= sRequiredMoveCounts[i - 1])
        {
            gSpecialVar_Result = i;
            count++;
        }
    }

    // Has no singular style
    if (count > 2)
        gSpecialVar_Result = FACTORY_NUM_STYLES;
}

static enum FactoryStyle GetMoveBattleStyle(enum Move move)
{
    enum FactoryStyle style = gBattleMoveEffects[GetMoveEffect(move)].battleFactoryStyle;

    if (style != FACTORY_STYLE_NONE)
        return style;

    // Conditional effects
    switch (GetMoveEffect(move))
    {
    case EFFECT_TWO_TURNS_ATTACK:
        // Potential to miss a two-turn move
        if (GetMoveAccuracy(move) < 100 && GetMoveAccuracy(move) != 0)
            return FACTORY_STYLE_HIGH_RISK;
        break;
    case EFFECT_RECOIL:
        // Only higher recoil moves are considered risky
        if (GetMoveRecoil(move) >= 33)
            return FACTORY_STYLE_HIGH_RISK;
        break;
    default:
        break;
    }
    // Bad secondary effects for the user
    if (MoveHasAdditionalEffectSelf(move, MOVE_EFFECT_RECHARGE)
     || MoveHasAdditionalEffectSelf(move, MOVE_EFFECT_STAT_MINUS))
        return FACTORY_STYLE_HIGH_RISK;

    // Non-volatile effects
    if (GetMoveNonVolatileStatus(move) != MOVE_EFFECT_NONE)
        return FACTORY_STYLE_SLOW_STEADY;

    if (IsExplosionMove(move))
        return FACTORY_STYLE_HIGH_RISK;

    return FACTORY_STYLE_NONE;
}

bool8 InBattleFactory(void)
{
    return gMapHeader.mapLayoutId == LAYOUT_BATTLE_FRONTIER_BATTLE_FACTORY_PRE_BATTLE_ROOM
        || gMapHeader.mapLayoutId == LAYOUT_BATTLE_FRONTIER_BATTLE_FACTORY_BATTLE_ROOM;
}

static void RestorePlayerPartyHeldItems(void)
{
    u8 i;

    if (gSaveBlock2Ptr->frontier.lvlMode != FRONTIER_LVL_TENT)
        gFacilityTrainerMons = gBattleFrontierMons;
    else
        gFacilityTrainerMons = gSlateportBattleTentMons;

    for (i = 0; i < FRONTIER_PARTY_SIZE; i++)
    {
        SetMonData(&gParties[B_TRAINER_PLAYER][i],
                   MON_DATA_HELD_ITEM,
                   &gFacilityTrainerMons[gSaveBlock2Ptr->frontier.rentalMons[i].monId].heldItem);
    }
}

u8 GetFactoryMonFixedIV(struct FacilityMonGenerator *generator, u32 trainerId)
{
    bool32 useHigherIV = FALSE;
    u32 challengeNum = gSaveBlock2Ptr->frontier.factoryWinStreaks[generator->battleMode][generator->lvlMode] / FRONTIER_STAGES_PER_CHALLENGE;
    if (trainerId == TRAINER_FRONTIER_BRAIN)
    {
        challengeNum += 2;
    }
    else if (gSaveBlock2Ptr->frontier.curChallengeBattleNum == FRONTIER_STAGES_PER_CHALLENGE - 1)
    {
        useHigherIV = TRUE;
    }

    if (challengeNum >= ARRAY_COUNT(sFixedIVTable))
        challengeNum = ARRAY_COUNT(sFixedIVTable) - 1;

    return sFixedIVTable[challengeNum][useHigherIV];
}

u16 GetFactoryMonId(struct FacilityMonGenerator *generator, u32 rentalIndex)
{
    u32 challengeNum = gSaveBlock2Ptr->frontier.factoryWinStreaks[generator->battleMode][generator->lvlMode] / FRONTIER_STAGES_PER_CHALLENGE;
    if (gSaveBlock2Ptr->frontier.curChallengeBattleNum == 0 && rentalIndex < GetNumPastRentalsRank(generator->battleMode, generator->lvlMode))
    {
        challengeNum += 1;
    }
    if (challengeNum > 7)
        challengeNum = 7;

    const struct FrontierMonPool rentalPool = sInitialRentalMonPools[generator->lvlMode][challengeNum];
    return RandomUniform(RNG_NONE, rentalPool.begin, rentalPool.end);
}

u8 GetNumPastRentalsRank(u8 battleMode, enum FrontierLevelMode lvlMode)
{
    u8 ret;
    u8 rents = gSaveBlock2Ptr->frontier.factoryRentsCount[battleMode][lvlMode];

    if (rents < 15)
        ret = 0;
    else if (rents < 22)
        ret = 1;
    else if (rents < 29)
        ret = 2;
    else if (rents < 36)
        ret = 3;
    else if (rents < 43)
        ret = 4;
    else
        ret = 5;

    return ret;
}

u64 GetAiScriptsInBattleFactory(void)
{
    int lvlMode = gSaveBlock2Ptr->frontier.lvlMode;

    if (lvlMode == FRONTIER_LVL_TENT)
    {
        return 0;
    }
    else
    {
        int battleMode = VarGet(VAR_FRONTIER_BATTLE_MODE);
        int challengeNum = gSaveBlock2Ptr->frontier.factoryWinStreaks[battleMode][lvlMode] / FRONTIER_STAGES_PER_CHALLENGE;

        if (TRAINER_BATTLE_PARAM.opponentA == TRAINER_FRONTIER_BRAIN)
            return AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY;
        else if (challengeNum < 2)
            return 0;
        else if (challengeNum < 4)
            return AI_FLAG_CHECK_BAD_MOVE;
        else
            return AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY;
    }
}
