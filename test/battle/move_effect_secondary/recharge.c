#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(MoveHasAdditionalEffectSelf(MOVE_METEOR_ASSAULT, MOVE_EFFECT_RECHARGE));
}

SINGLE_BATTLE_TEST("Recharge: Recharge moves make the user unable to attack for exactly one turn")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_METEOR_ASSAULT); }
        TURN { SKIP_TURN(player); }
        TURN { MOVE(player, MOVE_TACKLE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_METEOR_ASSAULT, player);
        MESSAGE("Wobbuffet must recharge!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_TACKLE, player);
    }
}

SINGLE_BATTLE_TEST("Recharge: Recharge moves don't timeout when all battlers are recharging")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_METEOR_ASSAULT); MOVE(opponent, MOVE_METEOR_ASSAULT); }
    }
}

DOUBLE_BATTLE_TEST("Recharge: Recharge moves don't timeout when all battlers are recharging (doubles)")
{

    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WYNAUT);
    } WHEN {
        TURN {
            MOVE(playerLeft, MOVE_METEOR_ASSAULT, target: opponentLeft);
            MOVE(playerRight, MOVE_METEOR_ASSAULT, target: opponentRight);
            MOVE(opponentLeft, MOVE_METEOR_ASSAULT, target: playerLeft);
            MOVE(opponentRight, MOVE_METEOR_ASSAULT, target: playerRight);
        }
    }
}

SINGLE_BATTLE_TEST("Recharge: Knocking out the target with Recharge moves causes the user to have to recharge on their next turn (Gen2+)")
{
    GIVEN {
        WITH_CONFIG(B_SKIP_RECHARGE, GEN_2);
        PLAYER(SPECIES_AGGRON) { Speed(2); HP(1); }
        PLAYER(SPECIES_AGGRON) { Speed(3); HP(1); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(4); Moves(MOVE_METEOR_ASSAULT); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_METEOR_ASSAULT); SEND_OUT(player, 1); }
        TURN { SKIP_TURN(opponent); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_METEOR_ASSAULT, opponent);
        MESSAGE("The opposing Wobbuffet must recharge!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, player);
    }
}

SINGLE_BATTLE_TEST("Recharge: Knocking out the target with Recharge moves does not cause the user to have to recharge on their next turn (Gen1)")
{
    GIVEN {
        WITH_CONFIG(B_SKIP_RECHARGE, GEN_1);
        PLAYER(SPECIES_AGGRON) { Speed(2); HP(1); }
        PLAYER(SPECIES_AGGRON) { Speed(3); HP(1); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(4); Moves(MOVE_METEOR_ASSAULT); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_METEOR_ASSAULT); SEND_OUT(player, 1); }
        TURN {}
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_METEOR_ASSAULT, opponent);
        NOT MESSAGE("The opposing Wobbuffet must recharge!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, player);
    }
}
