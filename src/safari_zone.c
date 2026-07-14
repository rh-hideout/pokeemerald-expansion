#include "global.h"
#include "battle.h"
#include "battle_scripts.h"
#include "event_data.h"
#include "field_player_avatar.h"
#include "main.h"
#include "malloc.h"
#include "overworld.h"
#include "pokeblock.h"
#include "safari_zone.h"
#include "script.h"
#include "sound.h"
#include "strings.h"
#include "string_util.h"
#include "tv.h"
#include "constants/game_stat.h"
#include "constants/map_groups.h"
#include "constants/songs.h"
#include "field_screen_effect.h"

struct PokeblockFeeder
{
    /*0x00*/ s16 x;
    /*0x02*/ s16 y;
    /*0x04*/ s8 mapNum;
    /*0x05*/ u8 stepCounter;
    /*0x08*/ struct Pokeblock pokeblock;
};

enum SafariRules
{
    RSE_SAFARI,
    FRLG_SAFARI,
};

struct SafariZone
{
    enum SafariRules rules;
    u8 startingBalls;
    u16 startingSteps;
    u16 catchMultiplier; // value will be divided by 100 so 150 is a 1.5 multiplier
    struct WarpData exitWarp;
};

#define DUMMY_WARP {                      \
    .mapGroup = MAP_GROUP(MAP_UNDEFINED), \
    .mapNum = MAP_NUM(MAP_UNDEFINED),     \
    .warpId = WARP_ID_NONE,               \
    .x = -1,                              \
    .y = -1,                              \
}

static const struct SafariZone sSafariZones[SAFARI_COUNT] = {
    [NONE_SAFARI] = {0},
    [ROUTE_121_HOENN_SAFARI] = {
        .rules = RSE_SAFARI,
        .startingBalls = 30,
        .startingSteps = 500,
        .catchMultiplier = 150,
        #if MAP_ROUTE121_SAFARI_ZONE_ENTRANCE
        .exitWarp = {
            .mapGroup = MAP_GROUP(MAP_ROUTE121_SAFARI_ZONE_ENTRANCE),
            .mapNum = MAP_NUM(MAP_ROUTE121_SAFARI_ZONE_ENTRANCE),
            .warpId = 0
        }
        #else
        .exitWarp = DUMMY_WARP
        #endif
    },
    [FUSCHIA_CITY_SAFARI] = {
        .rules = FRLG_SAFARI,
        .startingBalls = 30,
        .startingSteps = 600,
        .catchMultiplier = 150,
        #if MAP_FUCHSIA_CITY_SAFARI_ZONE_ENTRANCE
        .exitWarp = {
            .mapGroup = MAP_GROUP(MAP_FUCHSIA_CITY_SAFARI_ZONE_ENTRANCE),
            .mapNum = MAP_NUM(MAP_FUCHSIA_CITY_SAFARI_ZONE_ENTRANCE),
            .warpId = 0
        }
        #else
        .exitWarp = DUMMY_WARP
        #endif
    },
};

#define NUM_POKEBLOCK_FEEDERS 10

extern const u8 SafariZone_EventScript_TimesUp[];
extern const u8 SafariZone_EventScript_RetirePrompt[];
extern const u8 SafariZone_EventScript_OutOfBallsMidBattle[];
extern const u8 SafariZone_EventScript_OutOfBalls[];
extern const u8 *const gBattlescriptsForSafariActions[];

struct SafariData
{
    enum SafariIds id:8;
    u8  numBalls;
    u16 stepCounter;
    u8  caughtMons;
    u8  pokeblockUses;
    struct PokeblockFeeder feeders[NUM_POKEBLOCK_FEEDERS];
};

EWRAM_DATA struct SafariData sSafariData;
/*
EWRAM_DATA u8 gNumSafariBalls = 0;
EWRAM_DATA u16 gSafariZoneStepCounter = 0;
EWRAM_DATA static u8 sSafariZoneCaughtMons = 0;
EWRAM_DATA static u8 sSafariZonePkblkUses = 0;
EWRAM_DATA static struct PokeblockFeeder sPokeblockFeeders[NUM_POKEBLOCK_FEEDERS] = {0};
*/

static void DecrementFeederStepCounters(void);


bool32 GetSafariZoneFlag(void)
{
    return sSafariData.id != NONE_SAFARI;
}

void ResetSafariZoneFlag(void)
{
     memset(&sSafariData, 0, sizeof(sSafariData));
}


void EnterSafariMode(enum SafariIds safariId)
{
    assertf(!GetSafariZoneFlag(), "Game is already in a safari")
    {
        return;
    }
    assertf(safariId < SAFARI_COUNT, "Trying to enter undefined safari zone %d", safariId)
    {
        return;
    }
    struct WarpData warp = sSafariZones[safariId].exitWarp;
    assertf(!IsDummyWarp(&warp), "Safari is not exiting to a valid location")
    {
        return;
    }
    IncrementGameStat(GAME_STAT_ENTERED_SAFARI_ZONE);
    VarSet(VAR_SAFARI_ZONE_STATE, ENTERING_SAFARI_ZONE);
    sSafariData.id = safariId;
    sSafariData.numBalls = sSafariZones[safariId].startingBalls;
    sSafariData.stepCounter = sSafariZones[safariId].startingSteps;
}

void ExitSafariMode(void)
{
    TryPutSafariFanClubOnAir(sSafariData.caughtMons, sSafariData.pokeblockUses);
    SetWarpDestinationFromWarpData(sSafariZones[sSafariData.id].exitWarp);
    ResetSafariZoneFlag();
}

bool8 SafariZoneTakeStep(void)
{
    if (GetSafariZoneFlag() == FALSE)
    {
        return FALSE;
    }

    DecrementFeederStepCounters();
    sSafariData.stepCounter--;
    if (sSafariData.stepCounter == 0)
    {
        ScriptContext_SetupScript(SafariZone_EventScript_TimesUp);
        return TRUE;
    }
    return FALSE;
}

void SafariZoneRetirePrompt(void)
{
    ScriptContext_SetupScript(SafariZone_EventScript_RetirePrompt);
}

void CB2_EndSafariBattle(void)
{
    sSafariData.pokeblockUses += gBattleResults.pokeblockThrows;
    if (gBattleOutcome == B_OUTCOME_CAUGHT)
        sSafariData.caughtMons++;
    if (sSafariData.numBalls != 0)
    {
        SetMainCallback2(CB2_ReturnToField);
    }
    else if (gBattleOutcome == B_OUTCOME_NO_SAFARI_BALLS)
    {
        RunScriptImmediately(SafariZone_EventScript_OutOfBallsMidBattle);
        WarpIntoMap();
        gFieldCallback = FieldCB_ReturnToFieldNoScriptCheckMusic;
        SetMainCallback2(CB2_LoadMap);
    }
    else if (gBattleOutcome == B_OUTCOME_CAUGHT)
    {
        ScriptContext_SetupScript(SafariZone_EventScript_OutOfBalls);
        ScriptContext_Stop();
        SetMainCallback2(CB2_ReturnToFieldContinueScriptPlayMapMusic);
    }
}

static void ClearPokeblockFeeder(u8 index)
{
    memset(&sSafariData.feeders[index], 0, sizeof(struct PokeblockFeeder));
}

void GetPokeblockFeederInFront(void)
{
    s16 x, y;
    u16 i;

    GetXYCoordsOneStepInFrontOfPlayer(&x, &y);

    for (i = 0; i < NUM_POKEBLOCK_FEEDERS; i++)
    {
        if (gSaveBlock1Ptr->location.mapNum == sSafariData.feeders[i].mapNum
         && sSafariData.feeders[i].x == x
         && sSafariData.feeders[i].y == y)
        {
            gSpecialVar_Result = i;
            StringCopy(gStringVar1, gPokeblockNames[sSafariData.feeders[i].pokeblock.color]);
            return;
        }
    }

    gSpecialVar_Result = -1;
}

void GetPokeblockFeederWithinRange(void)
{
    s16 x, y;
    u16 i;

    PlayerGetDestCoords(&x, &y);

    for (i = 0; i < NUM_POKEBLOCK_FEEDERS; i++)
    {
        if (gSaveBlock1Ptr->location.mapNum == sSafariData.feeders[i].mapNum)
        {
            // Get absolute value of x and y distance from Pokeblock feeder on current map.
            x -= sSafariData.feeders[i].x;
            y -= sSafariData.feeders[i].y;
            if (x < 0)
                x *= -1;
            if (y < 0)
                y *= -1;
            if ((x + y) <= 5)
            {
                gSpecialVar_Result = i;
                return;
            }
        }
    }

    gSpecialVar_Result = -1;
}

struct Pokeblock *SafariZoneGetActivePokeblock(void)
{
    GetPokeblockFeederWithinRange();

    if (gSpecialVar_Result == 0xFFFF)
        return NULL;
    else
        return &sSafariData.feeders[gSpecialVar_Result].pokeblock;
}

void SafariZoneActivatePokeblockFeeder(u8 pkblId)
{
    s16 x, y;
    u8 i;

    for (i = 0; i < NUM_POKEBLOCK_FEEDERS; i++)
    {
        // Find free entry in sSafariData.feeders
        if (sSafariData.feeders[i].mapNum == 0
         && sSafariData.feeders[i].x == 0
         && sSafariData.feeders[i].y == 0)
        {
            // Initialize Pokeblock feeder
            GetXYCoordsOneStepInFrontOfPlayer(&x, &y);
            sSafariData.feeders[i].mapNum = gSaveBlock1Ptr->location.mapNum;
            sSafariData.feeders[i].pokeblock = gSaveBlock1Ptr->pokeblocks[pkblId];
            sSafariData.feeders[i].stepCounter = 100;
            sSafariData.feeders[i].x = x;
            sSafariData.feeders[i].y = y;
            break;
        }
    }
}

static void DecrementFeederStepCounters(void)
{
    u8 i;

    for (i = 0; i < NUM_POKEBLOCK_FEEDERS; i++)
    {
        if (sSafariData.feeders[i].stepCounter != 0)
        {
            sSafariData.feeders[i].stepCounter--;
            if (sSafariData.feeders[i].stepCounter == 0)
                ClearPokeblockFeeder(i);
        }
    }
}

void PrepareStartMenuSafariString()
{
    ConvertIntToDecimalStringN(gStringVar1, sSafariData.stepCounter, STR_CONV_MODE_RIGHT_ALIGN, 3);
    ConvertIntToDecimalStringN(gStringVar2, sSafariZones[sSafariData.id].startingSteps, STR_CONV_MODE_RIGHT_ALIGN, 3);
    ConvertIntToDecimalStringN(gStringVar3, sSafariData.numBalls, STR_CONV_MODE_RIGHT_ALIGN, 2);
    StringExpandPlaceholders(gStringVar4, gText_MenuSafariStats);
}

bool32 IsSafariEnding(void)
{
    if (!GetSafariZoneFlag())
        return FALSE;
    if (sSafariData.numBalls > 0)
        return FALSE;
    return TRUE;
}

bool32 InSafariThatDoesNotSendMons(void)
{
    enum SafariRules rules = sSafariZones[sSafariData.id].rules;
    return (rules == RSE_SAFARI || rules == FRLG_SAFARI);
}

u32 GetSafariZoneBallMultiplier(void)
{
    return sSafariZones[sSafariData.id].catchMultiplier;
}

u32 GetSafariBallCount(void)
{
    return sSafariData.numBalls;
}

static const u8 *sSafariControllerMenuString[] = {
    [RSE_SAFARI] = gText_SafariZoneMenu,
    [FRLG_SAFARI] = gText_SafariZoneMenuFrlg,
};

const u8 *GetSafariControllerMenu(void)
{
    return sSafariControllerMenuString[sSafariZones[sSafariData.id].rules];
}

static const u8 sSafariControllerActions[][4] = {
    [RSE_SAFARI] = {
        B_ACTION_SAFARI_BALL,
        B_ACTION_SAFARI_POKEBLOCK,
        B_ACTION_SAFARI_GO_NEAR,
        B_ACTION_SAFARI_RUN,
    },
    [FRLG_SAFARI] = {
        B_ACTION_SAFARI_BALL,
        B_ACTION_SAFARI_BAIT,
        B_ACTION_SAFARI_ROCK,
        B_ACTION_SAFARI_RUN,
    }
};

const u8 *GetSafariControllerActions(void)
{
    return sSafariControllerActions[sSafariZones[sSafariData.id].rules];
}

u32 GetInitialSafariCatchFactor(void)
{
    return gSpeciesInfo[GetMonData(&gParties[B_TRAINER_OPPONENT_A][0], MON_DATA_SPECIES)].catchRate * 100 / 1275;
}

static const u8 sPkblToEscapeFactor[][3] = {
    {
        [B_MSG_MON_CURIOUS]    = 0,
        [B_MSG_MON_ENTHRALLED] = 0,
        [B_MSG_MON_IGNORED]    = 0
    },{
        [B_MSG_MON_CURIOUS]    = 3,
        [B_MSG_MON_ENTHRALLED] = 5,
        [B_MSG_MON_IGNORED]    = 0
    },{
        [B_MSG_MON_CURIOUS]    = 2,
        [B_MSG_MON_ENTHRALLED] = 3,
        [B_MSG_MON_IGNORED]    = 0
    },{
        [B_MSG_MON_CURIOUS]    = 1,
        [B_MSG_MON_ENTHRALLED] = 2,
        [B_MSG_MON_IGNORED]    = 0
    },{
        [B_MSG_MON_CURIOUS]    = 1,
        [B_MSG_MON_ENTHRALLED] = 1,
        [B_MSG_MON_IGNORED]    = 0
    }
};
static const u8 sGoNearCounterToCatchFactor[] = {4, 3, 2, 1};
static const u8 sGoNearCounterToEscapeFactor[] = {4, 4, 4, 4};

#define safariBaitThrowCounter safariPkblThrowCounter
#define safariRockThrowCounter safariGoNearCounter

// B_ACTION_SAFARI_WATCH_CAREFULLY
void HandleAction_WatchesCarefully(void)

{
    gBattlerAttacker = gBattlerByTurnOrder[gCurrentTurnActionNumber];
    gBattle_BG0_X = 0;
    gBattle_BG0_Y = 0;

    gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_MON_WATCHING;
    if (sSafariZones[sSafariData.id].rules == FRLG_SAFARI)
    {
        if (gBattleStruct->safariRockThrowCounter > 0)
        {
            gBattleStruct->safariRockThrowCounter--;
            if (gBattleStruct->safariRockThrowCounter > 0)
                gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_MON_ANGRY;
            else
                gBattleStruct->safariCatchFactor = GetInitialSafariCatchFactor();
        }
        else if (gBattleStruct->safariBaitThrowCounter > 0)
        {
            gBattleStruct->safariBaitThrowCounter--;
            if (gBattleStruct->safariBaitThrowCounter > 0)
                gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_MON_EATING;
        }
        gBattlescriptCurrInstr = gBattlescriptsForSafariActions[0];
    }
    gBattlescriptCurrInstr = gBattlescriptsForSafariActions[0];
    gCurrentActionFuncId = B_ACTION_EXEC_SCRIPT;
}

// B_ACTION_SAFARI_BALL
void HandleAction_SafariZoneBallThrow(void)
{
    gBattlerAttacker = gBattlerByTurnOrder[gCurrentTurnActionNumber];
    gBattle_BG0_X = 0;
    gBattle_BG0_Y = 0;
    sSafariData.numBalls--;
    gLastUsedItem = ITEM_SAFARI_BALL;
    gBattlescriptCurrInstr = BattleScript_SafariBallThrow;
    gCurrentActionFuncId = B_ACTION_EXEC_SCRIPT;
}

// B_ACTION_SAFARI_POKEBLOCK
void HandleAction_ThrowPokeblock(void)
{
    gBattlerAttacker = gBattlerByTurnOrder[gCurrentTurnActionNumber];
    gBattle_BG0_X = 0;
    gBattle_BG0_Y = 0;

    gBattleCommunication[MULTISTRING_CHOOSER] = gBattleResources->bufferB[gBattlerAttacker][1] - 1;
    gLastUsedItem = gBattleResources->bufferB[gBattlerAttacker][2];

    if (gBattleResults.pokeblockThrows < 255)
        gBattleResults.pokeblockThrows++;
    if (gBattleStruct->safariPkblThrowCounter < 3)
        gBattleStruct->safariPkblThrowCounter++;
    if (gBattleStruct->safariEscapeFactor > 1)
    {
        // BUG: safariEscapeFactor can become 0 below. This causes the pokeblock throw glitch.
        #ifdef BUGFIX
        if (gBattleStruct->safariEscapeFactor <= sPkblToEscapeFactor[gBattleStruct->safariPkblThrowCounter][gBattleCommunication[MULTISTRING_CHOOSER]])
        #else
        if (gBattleStruct->safariEscapeFactor < sPkblToEscapeFactor[gBattleStruct->safariPkblThrowCounter][gBattleCommunication[MULTISTRING_CHOOSER]])
        #endif
            gBattleStruct->safariEscapeFactor = 1;
        else
            gBattleStruct->safariEscapeFactor -= sPkblToEscapeFactor[gBattleStruct->safariPkblThrowCounter][gBattleCommunication[MULTISTRING_CHOOSER]];
    }

    gBattlescriptCurrInstr = gBattlescriptsForSafariActions[2];

    gCurrentActionFuncId = B_ACTION_EXEC_SCRIPT;
}

// B_ACTION_SAFARI_GO_NEAR
void HandleAction_GoNear(void)
{
    gBattlerAttacker = gBattlerByTurnOrder[gCurrentTurnActionNumber];
    gBattle_BG0_X = 0;
    gBattle_BG0_Y = 0;

    gBattleStruct->safariCatchFactor += sGoNearCounterToCatchFactor[gBattleStruct->safariGoNearCounter];
    if (gBattleStruct->safariCatchFactor > 20)
        gBattleStruct->safariCatchFactor = 20;

    gBattleStruct->safariEscapeFactor += sGoNearCounterToEscapeFactor[gBattleStruct->safariGoNearCounter];
    if (gBattleStruct->safariEscapeFactor > 20)
        gBattleStruct->safariEscapeFactor = 20;

    if (gBattleStruct->safariGoNearCounter < 3)
    {
        gBattleStruct->safariGoNearCounter++;
        gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_CREPT_CLOSER;
    }
    else
    {
        gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_CANT_GET_CLOSER;
    }
    gBattlescriptCurrInstr = gBattlescriptsForSafariActions[1];

    gCurrentActionFuncId = B_ACTION_EXEC_SCRIPT;
}

// B_ACTION_SAFARI_BAIT
void HandleAction_ThrowBait(void)
{
    gBattlerAttacker = gBattlerByTurnOrder[gCurrentTurnActionNumber];
    gBattle_BG0_X = 0;
    gBattle_BG0_Y = 0;

    gBattleStruct->safariBaitThrowCounter += Random() % 5 + 2;
    if (gBattleStruct->safariBaitThrowCounter > 6)
        gBattleStruct->safariBaitThrowCounter = 6;

    gBattleStruct->safariRockThrowCounter = 0;
    gBattleStruct->safariCatchFactor >>= 1;

    if (gBattleStruct->safariCatchFactor <= 2)
        gBattleStruct->safariCatchFactor = 3;

    gBattlescriptCurrInstr = gBattlescriptsForSafariActions[5];

    gCurrentActionFuncId = B_ACTION_EXEC_SCRIPT;
}

// B_ACTION_SAFARI_ROCK
void HandleAction_ThrowRock(void)
{
    gBattlerAttacker = gBattlerByTurnOrder[gCurrentTurnActionNumber];
    gBattle_BG0_X = 0;
    gBattle_BG0_Y = 0;

    gBattleStruct->safariRockThrowCounter += Random() % 5 + 2;
    if (gBattleStruct->safariRockThrowCounter > 6)
        gBattleStruct->safariRockThrowCounter = 6;

    gBattleStruct->safariBaitThrowCounter = 0;
    gBattleStruct->safariCatchFactor <<= 1;

    if (gBattleStruct->safariCatchFactor > 20)
        gBattleStruct->safariCatchFactor = 20;

    gBattlescriptCurrInstr = gBattlescriptsForSafariActions[4];

    gCurrentActionFuncId = B_ACTION_EXEC_SCRIPT;
}

// B_ACTION_SAFARI_RUN
void HandleAction_SafariZoneRun(void)
{
    gBattlerAttacker = gBattlerByTurnOrder[gCurrentTurnActionNumber];
    PlaySE(SE_FLEE);
    gCurrentTurnActionNumber = gBattlersCount;
    gBattleOutcome = B_OUTCOME_RAN;
}

#undef safariBaitThrowCounter
#undef safariRockThrowCounter
