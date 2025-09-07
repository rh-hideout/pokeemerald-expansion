#include "global.h"
#include "test/battle.h"
#include "battle_ai_util.h"
#include "constants/battle_z_move_effects.h"

AI_SINGLE_BATTLE_TEST("AI uses Z-moves.")
{
    GIVEN {
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT | AI_FLAG_OMNISCIENT );
        ASSUME(GetMoveType(MOVE_QUICK_ATTACK) == TYPE_NORMAL);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET) { Item(ITEM_NORMALIUM_Z); Moves(MOVE_QUICK_ATTACK); }
    } WHEN {
        TURN { EXPECT_MOVE(opponent, MOVE_QUICK_ATTACK, gimmick: GIMMICK_Z_MOVE); }
    }
}

AI_SINGLE_BATTLE_TEST("AI does not use damaging Z-moves if the player would faint anyway.")
{
    u32 currentHP;
    PARAMETRIZE { currentHP = 1; }
    PARAMETRIZE { currentHP = 500; }
    GIVEN {
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT | AI_FLAG_OMNISCIENT );
        ASSUME(GetMoveType(MOVE_QUICK_ATTACK) == TYPE_NORMAL);
        PLAYER(SPECIES_WOBBUFFET) { HP(currentHP); }
        OPPONENT(SPECIES_WOBBUFFET) { Item(ITEM_NORMALIUM_Z); Moves(MOVE_QUICK_ATTACK); }
    } WHEN {
    if (currentHP != 1)
        TURN { EXPECT_MOVE(opponent, MOVE_QUICK_ATTACK, gimmick: GIMMICK_Z_MOVE); }
    else
        TURN { EXPECT_MOVE(opponent, MOVE_QUICK_ATTACK, gimmick: GIMMICK_NONE); }
    }
}
