#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Motor Drive absorbs status moves")
{
    GIVEN {
        PLAYER(TEST_SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_EMOLGA) { Ability(ABILITY_MOTOR_DRIVE); }
    } WHEN {
        TURN { MOVE(player, MOVE_THUNDER_WAVE); }
    } SCENE {
        ABILITY_POPUP(opponent, ABILITY_MOTOR_DRIVE);
    }
}

DOUBLE_BATTLE_TEST("Motor Drive absorbs moves that target all battlers but does not redirect")
{
    GIVEN {
        ASSUME(GetMoveType(MOVE_DISCHARGE) == TYPE_ELECTRIC);
        PLAYER(TEST_SPECIES_WOBBUFFET);
        PLAYER(TEST_SPECIES_WOBBUFFET);
        OPPONENT(TEST_SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_EMOLGA) { Ability(ABILITY_MOTOR_DRIVE); }
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_DISCHARGE); }
    } SCENE {
        HP_BAR(opponentLeft);
        HP_BAR(playerRight);
        NOT HP_BAR(opponentRight);
        ABILITY_POPUP(opponentRight, ABILITY_MOTOR_DRIVE);
    }
}
