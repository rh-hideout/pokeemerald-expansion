#include "global.h"
#include "battle.h"
#include "battle_scripts.h"
#include "safari_zone.h"
#include "sound.h"

#include "constants/songs.h"

static const u8 *sSafariControllerMenuString[] = {
    [SAFARI_ACTIONS_RSE] = gText_SafariZoneMenu,
    [SAFARI_ACTIONS_FRLG] = gText_SafariZoneMenuFrlg,
};

const u8 *GetSafariControllerMenu(void)
{
    return sSafariControllerMenuString[GetSafariActions()];
}

static const u8 sSafariControllerActions[][4] = {
    [SAFARI_ACTIONS_RSE] = {
        B_ACTION_SAFARI_BALL,
        B_ACTION_SAFARI_POKEBLOCK,
        B_ACTION_SAFARI_GO_NEAR,
        B_ACTION_SAFARI_RUN,
    },
    [SAFARI_ACTIONS_FRLG] = {
        B_ACTION_SAFARI_BALL,
        B_ACTION_SAFARI_BAIT,
        B_ACTION_SAFARI_ROCK,
        B_ACTION_SAFARI_RUN,
    }
};

const u8 *GetSafariControllerActions(void)
{
    return sSafariControllerActions[GetSafariActions()];
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
    if (GetSafariActions() == SAFARI_ACTIONS_FRLG)
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
    DecrementSafariBalls();
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
