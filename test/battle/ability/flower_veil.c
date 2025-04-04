#include "global.h"
#include "test/battle.h"

DOUBLE_BATTLE_TEST("Flower Veil prevents Toxic bad poison on partner - right target")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_TOXIC) == EFFECT_TOXIC);
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_COMFEY) { Ability(ABILITY_FLOWER_VEIL); }
        OPPONENT(SPECIES_CHIKORITA);
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_TOXIC, target: opponentRight); }
    } SCENE {
        MESSAGE("Wobbuffet used Toxic!");
        ABILITY_POPUP(opponentLeft, ABILITY_FLOWER_VEIL);
        MESSAGE("The opposing Chikorita surrounded itself with a veil of petals!");
        NOT STATUS_ICON(opponentRight, badPoison: TRUE);
    }
}

DOUBLE_BATTLE_TEST("Flower Veil prevents Toxic bad poison on partner - left target")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_TOXIC) == EFFECT_TOXIC);
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_CHIKORITA);
        OPPONENT(SPECIES_COMFEY) { Ability(ABILITY_FLOWER_VEIL); }
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_TOXIC, target: opponentLeft); }
    } SCENE {
        MESSAGE("Wobbuffet used Toxic!");
        ABILITY_POPUP(opponentRight, ABILITY_FLOWER_VEIL);
        MESSAGE("The opposing Chikorita surrounded itself with a veil of petals!");
        NOT STATUS_ICON(opponentLeft, badPoison: TRUE);
    }
}
