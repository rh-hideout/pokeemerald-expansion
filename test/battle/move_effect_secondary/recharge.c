#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(MoveHasAdditionalEffectSelf(MOVE_METEOR_ASSAULT, MOVE_EFFECT_RECHARGE) == TRUE);
}

SINGLE_BATTLE_TEST("Recharge moves make the user unable to attack for exactly one turn")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { }
        OPPONENT(SPECIES_WOBBUFFET) { }
    } WHEN {
        TURN { MOVE(player, MOVE_METEOR_ASSAULT);}
        TURN { SKIP_TURN(player);}
        TURN { MOVE(player, MOVE_TACKLE);}
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_METEOR_ASSAULT, player);
        MESSAGE("Wobbuffet must recharge!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_TACKLE, player);
    }
}

SINGLE_BATTLE_TEST("Recharge moves don't timeout when all battlers are recharging")
{

    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { }
        OPPONENT(SPECIES_WOBBUFFET) { }
    } WHEN {
        TURN { MOVE(player, MOVE_METEOR_ASSAULT); MOVE(opponent, MOVE_METEOR_ASSAULT);}
    }
}
