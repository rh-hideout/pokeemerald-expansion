#include "global.h"
#include "test/battle.h"

DOUBLE_BATTLE_TEST("Illuminate raises accuracy for all battlers")
{

    PASSES_RANDOMLY(84, 100, RNG_ACCURACY);
    GIVEN {
        ASSUME(gMovesInfo[MOVE_THUNDER].accuracy == 70);
        PLAYER(SPECIES_PIKACHU); 
        PLAYER(SPECIES_PIKACHU);
        OPPONENT(SPECIES_PIKACHU) { Ability(ABILITY_ILLUMINATE);}
        OPPONENT(SPECIES_PIKACHU);
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_THUNDER, target: opponentLeft); }
        TURN { MOVE(playerRight, MOVE_THUNDER, target: opponentRight); }
        TURN { MOVE(opponentLeft, MOVE_THUNDER, target: playerLeft); }
        TURN { MOVE(opponentRight, MOVE_THUNDER, target: playerRight); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_THUNDER, playerLeft);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_THUNDER, playerRight);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_THUNDER, opponentLeft);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_THUNDER, opponentRight);
    }
}

SINGLE_BATTLE_TEST("Illuminate does not affect OHKO moves")
{
    PASSES_RANDOMLY(30, 100, RNG_ACCURACY);
    GIVEN {
        ASSUME(gMovesInfo[MOVE_FISSURE].accuracy == 30);
        ASSUME(gMovesInfo[MOVE_FISSURE].effect == EFFECT_OHKO);
        PLAYER(SPECIES_BUTTERFREE) { Ability(ABILITY_ILLUMINATE); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_FISSURE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_FISSURE, player);
        HP_BAR(opponent, hp: 0);
    }
}
