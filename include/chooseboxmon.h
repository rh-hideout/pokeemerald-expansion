#ifndef GUARD_CHOOSEBOXMON_H
#define GUARD_CHOOSEBOXMON_H

typedef u32 UIAction;
enum
{
    PRINT_MESSAGE,
    PLAY_FANFARE,
    ASK_CONFIRMATION,
    WAIT_CONFIRMATION,
    CHANGE_STEP,
    END_TASK,
    SHOW_MOVE_LIST
};

enum LearnMoveFlowchartStep
{
    TRY_LEARN_MOVE,
    BACK_FROM_SUMMARY_SCREEN,
    WANT_REPLACE,
    REFUSE_REPLACE,
    REPLACE_MOVE,
    DID_NOT_LEARN
};

u32 IsBoxMonExcluded(struct BoxPokemon *boxmon);
bool32 CanBoxMonBeSelected(struct BoxPokemon *boxmon);
const UIAction *GetReplacementActions(enum LearnMoveFlowchartStep state, struct BoxPokemon *boxmon, u32 move);

#endif // GUARD_CHOOSEBOXMON_H
