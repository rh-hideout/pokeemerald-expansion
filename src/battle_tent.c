#include "global.h"
#include "battle_tent.h"
#include "overworld.h"
#include "event_data.h"
#include "region_map.h"
#include "battle.h"
#include "battle_setup.h"
#include "battle_tower.h"
#include "random.h"
#include "item.h"
#include "battle_factory.h"
#include "battle_factory_screen.h"
#include "frontier_util.h"
#include "string_util.h"
#include "constants/battle_tent.h"
#include "constants/battle_tent_trainers.h"
#include "constants/battle_tent_mons.h"
#include "constants/items.h"
#include "constants/layouts.h"
#include "constants/region_map_sections.h"
#include "constants/trainers.h"

// This file's functions.
static void InitVerdanturfTentChallenge(void);
static void GetVerdanturfTentPrize(void);
static void SetVerdanturfTentPrize(void);
static void SetVerdanturfTentTrainerGfx(void);
static void BufferVerdanturfTentTrainerIntro(void);
static void SaveVerdanturfTentChallenge(void);
static void SetRandomVerdanturfTentPrize(void);
static void GiveVerdanturfTentPrize(void);
static void InitFallarborTentChallenge(void);
static void GetFallarborTentPrize(void);
static void SetFallarborTentPrize(void);
static void SaveFallarborTentChallenge(void);
static void SetRandomFallarborTentPrize(void);
static void GiveFallarborTentPrize(void);
static void BufferFallarborTentTrainerName(void);
static void InitSlateportTentChallenge(void);
static void GetSlateportTentPrize(void);
static void SetSlateportTentPrize(void);
static void SaveSlateportTentChallenge(void);
static void SetRandomSlateportTentPrize(void);
static void GiveSlateportTentPrize(void);
static void SelectInitialRentalMons(void);
static void SwapRentalMons(void);
static void GenerateOpponentMons(void);

/*
 * Battle Tents are mini versions of particular Battle Frontier facilities
 * As such they each share some scripts and functions with their counterpart
 *
 * Verdanturf Battle Tent: Battle Palace
 * Fallarbor Battle Tent:  Battle Arena
 * Slateport Battle Tent:  Battle Factory
 *
 */

void static (*const sVerdanturfTentFuncs[])(void) =
{
    [VERDANTURF_TENT_FUNC_INIT]               = InitVerdanturfTentChallenge,
    [VERDANTURF_TENT_FUNC_GET_PRIZE]          = GetVerdanturfTentPrize,
    [VERDANTURF_TENT_FUNC_SET_PRIZE]          = SetVerdanturfTentPrize,
    [VERDANTURF_TENT_FUNC_SET_OPPONENT_GFX]   = SetVerdanturfTentTrainerGfx,
    [VERDANTURF_TENT_FUNC_GET_OPPONENT_INTRO] = BufferVerdanturfTentTrainerIntro,
    [VERDANTURF_TENT_FUNC_SAVE]               = SaveVerdanturfTentChallenge,
    [VERDANTURF_TENT_FUNC_SET_RANDOM_PRIZE]   = SetRandomVerdanturfTentPrize,
    [VERDANTURF_TENT_FUNC_GIVE_PRIZE]         = GiveVerdanturfTentPrize
};

static const u16 sVerdanturfTentRewards[] = {ITEM_NEST_BALL};

void static (*const sFallarborTentFuncs[])(void) =
{
    [FALLARBOR_TENT_FUNC_INIT]              = InitFallarborTentChallenge,
    [FALLARBOR_TENT_FUNC_GET_PRIZE]         = GetFallarborTentPrize,
    [FALLARBOR_TENT_FUNC_SET_PRIZE]         = SetFallarborTentPrize,
    [FALLARBOR_TENT_FUNC_SAVE]              = SaveFallarborTentChallenge,
    [FALLARBOR_TENT_FUNC_SET_RANDOM_PRIZE]  = SetRandomFallarborTentPrize,
    [FALLARBOR_TENT_FUNC_GIVE_PRIZE]        = GiveFallarborTentPrize,
    [FALLARBOR_TENT_FUNC_GET_OPPONENT_NAME] = BufferFallarborTentTrainerName
};

static const u16 sFallarborTentRewards[] = {ITEM_HYPER_POTION};

void static (*const sSlateportTentFuncs[])(void) =
{
    [SLATEPORT_TENT_FUNC_INIT]                   = InitSlateportTentChallenge,
    [SLATEPORT_TENT_FUNC_GET_PRIZE]              = GetSlateportTentPrize,
    [SLATEPORT_TENT_FUNC_SET_PRIZE]              = SetSlateportTentPrize,
    [SLATEPORT_TENT_FUNC_SAVE]                   = SaveSlateportTentChallenge,
    [SLATEPORT_TENT_FUNC_SET_RANDOM_PRIZE]       = SetRandomSlateportTentPrize,
    [SLATEPORT_TENT_FUNC_GIVE_PRIZE]             = GiveSlateportTentPrize,
    [SLATEPORT_TENT_FUNC_SELECT_RENT_MONS]       = SelectInitialRentalMons,
    [SLATEPORT_TENT_FUNC_SWAP_RENT_MONS]         = SwapRentalMons,
    [SLATEPORT_TENT_FUNC_GENERATE_OPPONENT_MONS] = GenerateOpponentMons,
    [SLATEPORT_TENT_FUNC_GENERATE_RENTAL_MONS]   = FactoryGenerateInitialRentalMons
};

static const u16 sSlateportTentRewards[] = {ITEM_FULL_HEAL};

// code
void CallVerdanturfTentFunction(void)
{
    sVerdanturfTentFuncs[gSpecialVar_0x8004]();
}

static void InitVerdanturfTentChallenge(void)
{
    gSaveBlock2Ptr->frontier.challengeStatus = 0;
    gSaveBlock2Ptr->frontier.curChallengeBattleNum = 0;
    gSaveBlock2Ptr->frontier.challengePaused = FALSE;
    SetDynamicWarp(0, gSaveBlock1Ptr->location.mapGroup, gSaveBlock1Ptr->location.mapNum, WARP_ID_NONE);
}

static void GetVerdanturfTentPrize(void)
{
    gSpecialVar_Result = gSaveBlock2Ptr->frontier.verdanturfTentPrize;
}

static void SetVerdanturfTentPrize(void)
{
    gSaveBlock2Ptr->frontier.verdanturfTentPrize = gSpecialVar_0x8006;
}

static void SetVerdanturfTentTrainerGfx(void)
{
    TRAINER_BATTLE_PARAM.opponentA = (u32)((Random() % 255) * 5) / 64;
    SetBattleFacilityTrainerGfxId(TRAINER_BATTLE_PARAM.opponentA, 0);
}

static void BufferVerdanturfTentTrainerIntro(void)
{
    if (TRAINER_BATTLE_PARAM.opponentA < FRONTIER_TRAINERS_COUNT)
        FrontierSpeechToString(gFacilityTrainers[TRAINER_BATTLE_PARAM.opponentA].speechBefore);
}

static void SaveVerdanturfTentChallenge(void)
{
    ClearEnemyPartyAfterChallenge();
    gSaveBlock2Ptr->frontier.challengeStatus = gSpecialVar_0x8005;
    VarSet(VAR_TEMP_CHALLENGE_STATUS, 0);
    gSaveBlock2Ptr->frontier.challengePaused = TRUE;
    SaveGameFrontier();
}

static void SetRandomVerdanturfTentPrize(void)
{
    gSaveBlock2Ptr->frontier.verdanturfTentPrize = sVerdanturfTentRewards[Random() % ARRAY_COUNT(sVerdanturfTentRewards)];
}

static void GiveVerdanturfTentPrize(void)
{
    if (AddBagItem(gSaveBlock2Ptr->frontier.verdanturfTentPrize, 1) == TRUE)
    {
        CopyItemName(gSaveBlock2Ptr->frontier.verdanturfTentPrize, gStringVar1);
        gSaveBlock2Ptr->frontier.verdanturfTentPrize = ITEM_NONE;
        gSpecialVar_Result = TRUE;
    }
    else
    {
        gSpecialVar_Result = FALSE;
    }
}

void CallFallarborTentFunction(void)
{
    sFallarborTentFuncs[gSpecialVar_0x8004]();
}

static void InitFallarborTentChallenge(void)
{
    gSaveBlock2Ptr->frontier.challengeStatus = 0;
    gSaveBlock2Ptr->frontier.curChallengeBattleNum = 0;
    gSaveBlock2Ptr->frontier.challengePaused = FALSE;
    SetDynamicWarp(0, gSaveBlock1Ptr->location.mapGroup, gSaveBlock1Ptr->location.mapNum, WARP_ID_NONE);
}

static void GetFallarborTentPrize(void)
{
    gSpecialVar_Result = gSaveBlock2Ptr->frontier.fallarborTentPrize;
}

static void SetFallarborTentPrize(void)
{
    gSaveBlock2Ptr->frontier.fallarborTentPrize = gSpecialVar_0x8006;
}

static void SaveFallarborTentChallenge(void)
{
    ClearEnemyPartyAfterChallenge();
    gSaveBlock2Ptr->frontier.challengeStatus = gSpecialVar_0x8005;
    VarSet(VAR_TEMP_CHALLENGE_STATUS, 0);
    gSaveBlock2Ptr->frontier.challengePaused = TRUE;
    SaveGameFrontier();
}

static void SetRandomFallarborTentPrize(void)
{
    gSaveBlock2Ptr->frontier.fallarborTentPrize = sFallarborTentRewards[Random() % ARRAY_COUNT(sFallarborTentRewards)];
}

static void GiveFallarborTentPrize(void)
{
    if (AddBagItem(gSaveBlock2Ptr->frontier.fallarborTentPrize, 1) == TRUE)
    {
        CopyItemName(gSaveBlock2Ptr->frontier.fallarborTentPrize, gStringVar1);
        gSaveBlock2Ptr->frontier.fallarborTentPrize = ITEM_NONE;
        gSpecialVar_Result = TRUE;
    }
    else
    {
        gSpecialVar_Result = FALSE;
    }
}

static void BufferFallarborTentTrainerName(void)
{
    GetFrontierTrainerName(gStringVar1, TRAINER_BATTLE_PARAM.opponentA);
}

void CallSlateportTentFunction(void)
{
    sSlateportTentFuncs[gSpecialVar_0x8004]();
}

static void InitSlateportTentChallenge(void)
{
    gSaveBlock2Ptr->frontier.challengeStatus = 0;
    gSaveBlock2Ptr->frontier.curChallengeBattleNum = 0;
    gSaveBlock2Ptr->frontier.challengePaused = FALSE;
    SetDynamicWarp(0, gSaveBlock1Ptr->location.mapGroup, gSaveBlock1Ptr->location.mapNum, WARP_ID_NONE);
}

static void GetSlateportTentPrize(void)
{
    gSpecialVar_Result = gSaveBlock2Ptr->frontier.slateportTentPrize;
}

static void SetSlateportTentPrize(void)
{
    gSaveBlock2Ptr->frontier.slateportTentPrize = gSpecialVar_0x8006;
}

static void SaveSlateportTentChallenge(void)
{
    ClearEnemyPartyAfterChallenge();
    gSaveBlock2Ptr->frontier.challengeStatus = gSpecialVar_0x8005;
    VarSet(VAR_TEMP_CHALLENGE_STATUS, 0);
    gSaveBlock2Ptr->frontier.challengePaused = TRUE;
    SaveGameFrontier();
}

static void SetRandomSlateportTentPrize(void)
{
    gSaveBlock2Ptr->frontier.slateportTentPrize = sSlateportTentRewards[Random() % ARRAY_COUNT(sSlateportTentRewards)];
}

static void GiveSlateportTentPrize(void)
{
    if (AddBagItem(gSaveBlock2Ptr->frontier.slateportTentPrize, 1) == TRUE)
    {
        CopyItemName(gSaveBlock2Ptr->frontier.slateportTentPrize, gStringVar1);
        gSaveBlock2Ptr->frontier.slateportTentPrize = ITEM_NONE;
        gSpecialVar_Result = TRUE;
    }
    else
    {
        gSpecialVar_Result = FALSE;
    }
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

bool8 InSlateportBattleTent(void)
{
    return gMapHeader.regionMapSectionId == MAPSEC_SLATEPORT_CITY
           && (gMapHeader.mapLayoutId == LAYOUT_BATTLE_TENT_CORRIDOR || gMapHeader.mapLayoutId == LAYOUT_BATTLE_TENT_BATTLE_ROOM);
}

static void GenerateOpponentMons(void)
{
    u16 trainerId;
    s32 i;

    do
    {
        // Choose a random trainer, ensuring no repeats in this challenge
        trainerId = Random() % NUM_BATTLE_TENT_TRAINERS;
        for (i = 0; i < gSaveBlock2Ptr->frontier.curChallengeBattleNum; i++)
        {
            if (gSaveBlock2Ptr->frontier.trainerIds[i] == trainerId)
                break;
        }
    } while (i != gSaveBlock2Ptr->frontier.curChallengeBattleNum);

    if (gSaveBlock2Ptr->frontier.curChallengeBattleNum < TENT_STAGES_PER_CHALLENGE - 1)
        gSaveBlock2Ptr->frontier.trainerIds[gSaveBlock2Ptr->frontier.curChallengeBattleNum] = trainerId;
    TRAINER_BATTLE_PARAM.opponentA = trainerId;

    struct FacilityMonGenerator generator = GetFacilityMonGenerator(trainerId);
    generator.partySize = FRONTIER_PARTY_SIZE;
    PickRandomFacilityMons(&generator, trainerId, gFrontierTempParty);
}
