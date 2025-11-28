#include "global.h"
#include "test/battle.h"

TO_DO_BATTLE_TEST("TODO: Write Heat Crash (Move Effect) test titles")

SINGLE_BATTLE_TEST("Dynamax: Dynamaxed Pokemon cannot be hit by weight-based moves")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_HEAVY_SLAM) == EFFECT_HEAT_CRASH);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_SCRATCH, gimmick: GIMMICK_DYNAMAX); MOVE(opponent, MOVE_HEAVY_SLAM); }
    } SCENE {
        MESSAGE("Wobbuffet used Max Strike!");
        MESSAGE("The opposing Wobbuffet used Heavy Slam!");
        MESSAGE("The move was blocked by the power of Dynamax!");
        NONE_OF { HP_BAR(player); }
    }
}
