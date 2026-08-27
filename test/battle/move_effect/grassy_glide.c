#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(GetMoveEffect(MOVE_GRASSY_GLIDE) == EFFECT_GRASSY_GLIDE);
    ASSUME(GetMovePriority(MOVE_GRASSY_GLIDE) == 0);
    ASSUME(GetMovePriority(MOVE_SCRATCH) == 0);
}

SINGLE_BATTLE_TEST("Grassy Glide's priority increases by 1 when the user is affected by Grassy Terrain")
{
    GIVEN {
        PLAYER(SPECIES_TAPU_BULU) { Ability(ABILITY_GRASSY_SURGE); Speed(1); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(2); }
    } WHEN {
        TURN { MOVE(player, MOVE_GRASSY_GLIDE); MOVE(opponent, MOVE_SCRATCH); }
    } SCENE {
        ABILITY_POPUP(player, ABILITY_GRASSY_SURGE);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_GRASSY_GLIDE, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, opponent);
    }
}

SINGLE_BATTLE_TEST("Dynamax: Grassy Glide's priority does not increase for the Max Move it becomes")
{
    GIVEN {
        PLAYER(SPECIES_TAPU_BULU) { Ability(ABILITY_GRASSY_SURGE); Speed(1); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(2); }
    } WHEN {
        TURN { MOVE(player, MOVE_GRASSY_GLIDE, gimmick: GIMMICK_DYNAMAX); MOVE(opponent, MOVE_SCRATCH); }
    } SCENE {
        ABILITY_POPUP(player, ABILITY_GRASSY_SURGE);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_MAX_OVERGROWTH, player);
    }
}
