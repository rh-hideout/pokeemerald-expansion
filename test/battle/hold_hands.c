#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(GetMoveTarget(MOVE_HOLD_HANDS) == TARGET_ALLY);
}

DOUBLE_BATTLE_TEST("Hold Hands fails if partner isn't alive")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WYNAUT) { HP(1); };
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponentRight, MOVE_POUND, target: playerRight); MOVE(playerLeft, MOVE_HOLD_HANDS); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_POUND, opponentRight);
        NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_HOLD_HANDS, playerLeft);
    }
}

