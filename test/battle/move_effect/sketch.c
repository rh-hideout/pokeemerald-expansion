#include "global.h"
#include "test/battle.h"

TO_DO_BATTLE_TEST("TODO: Write Sketch (Move Effect) test titles")

SINGLE_BATTLE_TEST("Sketch copies the last printed move even when it failed")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Moves(MOVE_LAST_RESORT, MOVE_CELEBRATE); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_LAST_RESORT); MOVE(opponent, MOVE_SKETCH); }
    } SCENE {
        NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_LAST_RESORT, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SKETCH, opponent);
    }
}

