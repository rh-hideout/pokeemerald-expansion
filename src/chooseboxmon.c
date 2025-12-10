#include "global.h"
#include "chooseboxmon.h"
#include "daycare.h"
#include "event_data.h"
#include "party_menu.h"
#include "pokemon.h"
#include "constants/party_menu.h"

#define VALID_MON 0

struct PcMonSelection
{
    void (*partyMonBackup)(void);
    u32 (*isMonInvalid)(struct BoxPokemon *);
    void (*onMonSelection)(struct BoxPokemon *);
};

static u32 NoFilter(struct BoxPokemon *boxmon);
static u32 CanLearnMoveFilter(struct BoxPokemon *boxmon);

static const struct PcMonSelection sPcMonSelectionTypes[] =
{
    [SELECT_PC_MON_NORMAL] = {ChoosePartyMon, NoFilter, NULL},
    [SELECT_PC_MON_MOVE_RELEARNER] = {ChooseMonForMoveRelearner, NoFilter, NULL},
    [SELECT_PC_MON_DAYCARE] = {ChooseSendDaycareMon, NoFilter, NULL},
    [SELECT_PC_MON_MOVE_TUTOR] = {ChooseMonForMoveTutor, CanLearnMoveFilter, NULL},
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

bool32 IsBoxMonExcluded(struct BoxPokemon *boxmon)
{
    //DebugPrintf("IsBoxMonExcluded %d", GetBoxMonData(boxmon, MON_DATA_SPECIES));
    return sPcMonSelectionTypes[gSpecialVar_0x8006].isMonInvalid(boxmon);
}