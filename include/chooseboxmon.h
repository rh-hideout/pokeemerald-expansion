#ifndef GUARD_CHOOSEBOXMON_H
#define GUARD_CHOOSEBOXMON_H

enum
{
    PRINT_MESSAGE,
    PLAY_FANFARE,
    ASK_CONFIRMATION,
    WAIT_CONFIRMATION,
    CALL_MANAGER,
    END_TASK,
    SHOW_MOVE_LIST
};

u32 IsBoxMonExcluded(struct BoxPokemon *boxmon);
bool32 CanBoxMonBeSelected(struct BoxPokemon *boxmon);
const u32 *GetReplacementActions(u32 state, struct BoxPokemon *boxmon, u32 move);

#endif // GUARD_CHOOSEBOXMON_H
