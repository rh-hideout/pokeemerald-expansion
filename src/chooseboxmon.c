#include "global.h"
#include "chooseboxmon.h"
#include "daycare.h"
#include "event_data.h"
#include "move.h"
#include "party_menu.h"
#include "pokemon.h"
#include "pokemon_summary_screen.h"
#include "string_util.h"
#include "strings.h"
#include "constants/party_menu.h"
#include "constants/songs.h"

#define VALID_MON 0

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

struct PcMonSelection
{
    void (*partyMonBackup)(void);
    u32 (*isMonInvalid)(struct BoxPokemon *);
};

static u32 NoFilter(struct BoxPokemon *boxmon);
static u32 CanLearnMoveFilter(struct BoxPokemon *boxmon);
static void SelectToLearnMove(struct BoxPokemon *boxmon);

static const struct PcMonSelection sPcMonSelectionTypes[] =
{
    [SELECT_PC_MON_NORMAL] = {ChoosePartyMon, NoFilter},
    [SELECT_PC_MON_MOVE_RELEARNER] = {ChooseMonForMoveRelearner, NoFilter},
    [SELECT_PC_MON_DAYCARE] = {ChooseSendDaycareMon, NoFilter},
    [SELECT_PC_MON_MOVE_TUTOR] = {ChooseMonForMoveTutor, CanLearnMoveFilter},
};

static u32 NoFilter(struct BoxPokemon *boxmon)
{
    return VALID_MON;
}

static u32 CanLearnMoveFilter(struct BoxPokemon *boxmon)
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
    return sPcMonSelectionTypes[gSpecialVar_0x8006].isMonInvalid(boxmon);
}

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
        else
            return sAskReplacementActions;
    case WANT_REPLACE:
        return sWantReplacementActions;
        break;
    case BACK_FROM_SUMMARY_SCREEN:
        if (GetMoveSlotToReplace() < MAX_MON_MOVES)
        {
            GetBoxMonNickname(boxmon, gStringVar1);
            StringCopy(gStringVar2, GetMoveName(GetBoxMonData(boxmon, MON_DATA_MOVE1 + GetMoveSlotToReplace())));
            return sForgotMoveActions;
        }
        else
        {
            return sRefuseNewMoveActions;
        }
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
