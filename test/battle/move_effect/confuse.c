#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(GetMoveEffect(MOVE_TEETER_DANCE) == EFFECT_CONFUSE);
}

SINGLE_BATTLE_TEST("Teeter Dance confuses target")
{
    GIVEN {
        PLAYER(TEST_SPECIES_WOBBUFFET);
        OPPONENT(TEST_SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_TEETER_DANCE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_TEETER_DANCE, player);
        ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_CONFUSION, opponent);
        MESSAGE("The opposing Wobbuffet became confused!");
    }
}

SINGLE_BATTLE_TEST("Teeter Dance confusion is blocked by Own Tempo")
{
    GIVEN {
        PLAYER(TEST_SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_SLOWPOKE) { Ability(ABILITY_OWN_TEMPO); }
    } WHEN {
        TURN { MOVE(player, MOVE_TEETER_DANCE); }
    } SCENE {
        ABILITY_POPUP(opponent, ABILITY_OWN_TEMPO);
        NONE_OF {
            ANIMATION(ANIM_TYPE_MOVE, MOVE_TEETER_DANCE, player);
            ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_CONFUSION, opponent);
            MESSAGE("The opposing Wobbuffet became confused!");
        }
    }
}

DOUBLE_BATTLE_TEST("Teeter Dance can confuse foes and allies")
{
    GIVEN {
        PLAYER(TEST_SPECIES_WOBBUFFET);
        PLAYER(TEST_SPECIES_WYNAUT);
        OPPONENT(TEST_SPECIES_WOBBUFFET);
        OPPONENT(TEST_SPECIES_WYNAUT);
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_TEETER_DANCE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_TEETER_DANCE, playerLeft);
        ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_CONFUSION, opponentLeft);
        MESSAGE("The opposing Wobbuffet became confused!");
        ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_CONFUSION, playerRight);
        MESSAGE("Wynaut became confused!");
        ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_CONFUSION, opponentRight);
        MESSAGE("The opposing Wynaut became confused!");
    }
}
