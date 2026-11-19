#include "global.h"
#include "event_data.h"
#include "battle_setup.h"
#include "overworld.h"
#include "random.h"
#include "battle_tower.h"
#include "frontier_util.h"
#include "item.h"
#include "string_util.h"
#include "constants/items.h"
#include "constants/battle_frontier.h"
#include "constants/battle_palace.h"
#include "constants/frontier_util.h"
#include "constants/trainers.h"

// This file's functions.
static void Unused_InitPalaceChallenge(void);
static void Unused_GetPalaceData(void);
static void Unused_SetPalaceData(void);
static void GetPalaceCommentId(void);
static void SetPalaceOpponent(void);
static void BufferOpponentIntroSpeech(void);
static void Unused_IncrementPalaceStreak(void);
static void SavePalaceChallenge(void);
static void Unused_SetRandomPalacePrize(void);
static void Unused_GivePalacePrize(void);

// Const rom data.
static void (*const sBattlePalaceFunctions[])(void) =
{
    [BATTLE_PALACE_FUNC_INIT]               = Unused_InitPalaceChallenge,
    [BATTLE_PALACE_FUNC_GET_DATA]           = Unused_GetPalaceData,
    [BATTLE_PALACE_FUNC_SET_DATA]           = Unused_SetPalaceData,
    [BATTLE_PALACE_FUNC_GET_COMMENT_ID]     = GetPalaceCommentId,
    [BATTLE_PALACE_FUNC_SET_OPPONENT]       = SetPalaceOpponent,
    [BATTLE_PALACE_FUNC_GET_OPPONENT_INTRO] = BufferOpponentIntroSpeech,
    [BATTLE_PALACE_FUNC_INCREMENT_STREAK]   = Unused_IncrementPalaceStreak,
    [BATTLE_PALACE_FUNC_SAVE]               = SavePalaceChallenge,
    [BATTLE_PALACE_FUNC_SET_PRIZE]          = Unused_SetRandomPalacePrize,
    [BATTLE_PALACE_FUNC_GIVE_PRIZE]         = Unused_GivePalacePrize,
};

// code
void CallBattlePalaceFunction(void)
{
    sBattlePalaceFunctions[gSpecialVar_0x8004]();
}

static void Unused_InitPalaceChallenge(void)
{

}

static void Unused_GetPalaceData(void)
{

}

static void Unused_SetPalaceData(void)
{

}

static void GetPalaceCommentId(void)
{
    u32 battleMode = VarGet(VAR_FRONTIER_BATTLE_MODE);
    enum FrontierLevelMode lvlMode = gSaveBlock2Ptr->frontier.lvlMode;

    if (gSaveBlock2Ptr->frontier.palaceWinStreaks[battleMode][lvlMode] < 50)
        gSpecialVar_Result = Random() % 3;
    else if (gSaveBlock2Ptr->frontier.palaceWinStreaks[battleMode][lvlMode] < 99)
        gSpecialVar_Result = 3;
    else
        gSpecialVar_Result = 4;
}

static void SetPalaceOpponent(void)
{
    TRAINER_BATTLE_PARAM.opponentA = 5 *(Random() % 255) / 64u;
    SetBattleFacilityTrainerGfxId(TRAINER_BATTLE_PARAM.opponentA, 0);
}

static void BufferOpponentIntroSpeech(void)
{
    if (TRAINER_BATTLE_PARAM.opponentA < FRONTIER_TRAINERS_COUNT)
        FrontierSpeechToString(gFacilityTrainers[TRAINER_BATTLE_PARAM.opponentA].speechBefore);
}

static void Unused_IncrementPalaceStreak(void)
{

}

static void SavePalaceChallenge(void)
{
    ClearEnemyPartyAfterChallenge();
    gSaveBlock2Ptr->frontier.challengeStatus = gSpecialVar_0x8005;
    VarSet(VAR_TEMP_CHALLENGE_STATUS, 0);
    gSaveBlock2Ptr->frontier.challengePaused = TRUE;
    SaveGameFrontier();
}

static void Unused_SetRandomPalacePrize(void)
{

}

static void Unused_GivePalacePrize(void)
{

}
