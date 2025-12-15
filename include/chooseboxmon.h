#ifndef GUARD_CHOOSEBOXMON_H
#define GUARD_CHOOSEBOXMON_H

struct MoveLearnUI {
    void (*askConfirmation)(void);
    s32 (*waitConfirmation)(void);
    void (*printMessage)(const u8 *message);
    void (*playFanfare)(u32 songId);
    void (*showMoveList)(u8 taskId);
    void (*endTask)(u8 taskId);
};

enum LearnMoveState
{
    LEARN_MOVE_END,

    LEARN_MOVE, //Start

    ASK_REPLACEMENT_1,
    ASK_REPLACEMENT_2,
    ASK_REPLACEMENT_3,

    REFUSE_REPLACE_1,
    REFUSE_REPLACE_2,
    REFUSE_REPLACE_3,

    WANT_REPLACE_1,
    WANT_REPLACE_2,
    WANT_REPLACE_3, //Return from Summary screen

    LEARNED_MOVE_1,
    LEARNED_MOVE_2,

    FORGOT_MOVE_1,

    REPLACE_MOVE_1,

    DID_NOT_LEARN_1,
};

u32 IsBoxMonExcluded(struct BoxPokemon *boxmon);
bool32 CanBoxMonBeSelected(struct BoxPokemon *boxmon);
s32 LearnMove(const struct MoveLearnUI *ui, u8 taskId);

#endif // GUARD_CHOOSEBOXMON_H
