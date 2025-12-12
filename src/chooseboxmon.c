#include "global.h"
#include "chooseboxmon.h"
#include "daycare.h"
#include "event_data.h"
#include "event_scripts.h"
#include "field_weather.h"
#include "move.h"
#include "overworld.h"
#include "palette.h"
#include "party_menu.h"
#include "pokemon.h"
#include "pokemon_summary_screen.h"
#include "pokemon_storage_system.h"
#include "script.h"
#include "string_util.h"
#include "strings.h"
#include "constants/party_menu.h"
#include "constants/songs.h"

#define VALID_MON 0
#define INVALID_MON 1

struct PcMonSelection
{
    void      (*partyMonBackup)(void);
    u32       (*isMonInvalid)(struct BoxPokemon *);
    const u8* postSelectionScript;
    bool32    isStrict;
};

static EWRAM_DATA u8 sSelectionType = 0;

// All these filter functions return 0 when a mon is a valid or a number corresponding to the type of error
static u32 NoFilter(struct BoxPokemon *boxmon);
static u32 IsNotEgg(struct BoxPokemon *boxmon);
static u32 IsMatchingSpecies(struct BoxPokemon *boxmon);
static u32 CanMonDeleteMove(struct BoxPokemon *boxmon);
static u32 CanMonLearnMove(struct BoxPokemon *boxmon);

static const struct PcMonSelection sPcMonSelectionTypes[] =
{
    [SELECT_PC_MON_NORMAL] = {ChoosePartyMon, NoFilter, NULL, FALSE},
    [SELECT_PC_MON_TRADE] = {ChoosePartyMon, IsMatchingSpecies, NULL, FALSE},
    [SELECT_PC_MON_DAYCARE] = {ChooseSendDaycareMon, IsNotEgg, NULL, TRUE},
    [SELECT_PC_MON_MOVE_TUTOR] = {ChooseMonForMoveTutor, CanMonLearnMove, MoveTutor_AfterChooseBoxMon, FALSE},
    [SELECT_PC_MON_MOVE_DELETER] = {ChoosePartyMon, CanMonDeleteMove, NULL, FALSE},
    [SELECT_PC_MON_MOVE_RELEARNER] = {ChooseMonForMoveRelearner, IsNotEgg, NULL, TRUE}
};

static u32 NoFilter(struct BoxPokemon *boxmon)
{
    return VALID_MON;
}

static u32 IsNotEgg(struct BoxPokemon *boxmon)
{
    if (GetBoxMonData(boxmon, MON_DATA_IS_EGG))
        return INVALID_MON;
    return VALID_MON;
}

static u32 IsMatchingSpecies(struct BoxPokemon *boxmon)
{
    if (GetBoxMonData(boxmon, MON_DATA_SPECIES_OR_EGG) == gSpecialVar_0x8009)
        return VALID_MON;
    return INVALID_MON;
}

static u32 CanMonDeleteMove(struct BoxPokemon *boxmon)
{
    if (GetBoxMonData(boxmon, MON_DATA_IS_EGG))
        return INVALID_MON;
    if (GetBoxMonData(boxmon, MON_DATA_MOVE2) == MOVE_NONE) // Only has One move
        return INVALID_MON;
    return VALID_MON;
}

static u32 CanMonLearnMove(struct BoxPokemon *boxmon)
{
    if (GetBoxMonData(boxmon, MON_DATA_IS_EGG))
        return CANNOT_LEARN_MOVE_IS_EGG;
    if (BoxMonKnowsMove(boxmon, gSpecialVar_0x8005))
        return ALREADY_KNOWS_MOVE;
    if (CanLearnTeachableMove(GetBoxMonData(boxmon, MON_DATA_SPECIES), gSpecialVar_0x8005))
        return VALID_MON;
    return CANNOT_LEARN_MOVE;
}

u32 IsBoxMonExcluded(struct BoxPokemon *boxmon)
{
    return sPcMonSelectionTypes[sSelectionType].isMonInvalid(boxmon);
}

bool32 CanBoxMonBeSelected(struct BoxPokemon *boxmon)
{
    if (!sPcMonSelectionTypes[sSelectionType].isStrict)
        return TRUE;
    return IsBoxMonExcluded(boxmon);
}

static void Task_ChooseBoxMon(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        CleanupOverworldWindowsAndTilemaps();
        ChooseMonFromStorage();
        DestroyTask(taskId);
    }
}

// Used as a script special for showing a box mon to various npcs (e.g. in-game trades, move deleter)
void ChooseBoxMon(struct ScriptContext *ctx)
{
    sSelectionType = ScriptReadByte(ctx);
    if (!OW_CHOOSE_FROM_PC_AND_PARTY)
    {
        sPcMonSelectionTypes[sSelectionType].partyMonBackup();
        return;
    }
    LockPlayerFieldControls();
    FadeScreen(FADE_TO_BLACK, 0);
    CreateTask(Task_ChooseBoxMon, 10);
    if (sPcMonSelectionTypes[sSelectionType].postSelectionScript)
    {
        ctx->scriptPtr++;
        ScriptCall(ctx, sPcMonSelectionTypes[sSelectionType].postSelectionScript);
    }
}

enum
{
    TRY_LEARN_MOVE,
    BACK_FROM_SUMMARY_SCREEN,
    WANT_REPLACE,
    REFUSE_REPLACE,
    FORGOT_MOVE,
    REPLACE_MOVE,
    DID_NOT_LEARN
};

const u32 sLearnedMoveActions[] = {PRINT_MESSAGE, (u32)gText_PkmnLearnedMove4, PLAY_FANFARE, MUS_LEVEL_UP, END_TASK};
const u32 sAskReplacementActions[] = {PRINT_MESSAGE, (u32)gText_PkmnNeedsToReplaceMove, ASK_CONFIRMATION, WAIT_CONFIRMATION, WANT_REPLACE, REFUSE_REPLACE};
const u32 sWantReplacementActions[] = {PRINT_MESSAGE, (u32)gText_WhichMoveToForget, SHOW_MOVE_LIST};
const u32 sRefuseNewMoveActions[] = {PRINT_MESSAGE, (u32)gText_StopLearningMove2, ASK_CONFIRMATION, WAIT_CONFIRMATION, DID_NOT_LEARN, WANT_REPLACE};
const u32 sForgotMoveActions[] = {PRINT_MESSAGE, (u32)gText_12PoofForgotMove, CALL_MANAGER, REPLACE_MOVE};
const u32 sDidNotLearnActions[] = {PRINT_MESSAGE, (u32)gText_MoveNotLearned, END_TASK};
const u32 sReplaceMoveActions[] = {PRINT_MESSAGE, (u32)gText_PkmnLearnedMove4, END_TASK};

const u32 *GetReplacementActions(u32 state, struct BoxPokemon *boxmon, u32 move)
{
    switch(state)
    {
    case TRY_LEARN_MOVE:
        GetBoxMonNickname(boxmon, gStringVar1);
        StringCopy(gStringVar2, GetMoveName(move));
        if (GiveMoveToBoxMon(boxmon, move) != MON_HAS_MAX_MOVES)
            return sLearnedMoveActions;
        return sAskReplacementActions;
    case WANT_REPLACE:
        return sWantReplacementActions;
    case BACK_FROM_SUMMARY_SCREEN:
        if (GetMoveSlotToReplace() == MAX_MON_MOVES)
            return sRefuseNewMoveActions;
        GetBoxMonNickname(boxmon, gStringVar1);
        StringCopy(gStringVar2, GetMoveName(GetBoxMonData(boxmon, MON_DATA_MOVE1 + GetMoveSlotToReplace())));
        return sForgotMoveActions;
    case REFUSE_REPLACE:
        return sRefuseNewMoveActions;
    case REPLACE_MOVE:
        RemoveBoxMonPPBonus(boxmon, GetMoveSlotToReplace());
        SetBoxMonMoveSlot(boxmon, move, GetMoveSlotToReplace());
        StringCopy(gStringVar2, GetMoveName(move));
        return sReplaceMoveActions;
    case DID_NOT_LEARN:
        return sDidNotLearnActions;
    }
    return NULL;
}
