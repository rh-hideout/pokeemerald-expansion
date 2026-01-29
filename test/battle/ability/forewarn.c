#include "global.h"
#include "test/battle.h"

DOUBLE_BATTLE_TEST("Forewarn warns about the highest power move among all opposing battlers")
{
    GIVEN {
        PLAYER(SPECIES_MUSHARNA) { Ability(ABILITY_FOREWARN); }
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_ZUBAT) { Moves(MOVE_CRUNCH, MOVE_CELEBRATE); }
        OPPONENT(SPECIES_EXCADRILL) { Moves(MOVE_FISSURE, MOVE_CELEBRATE); }
    } WHEN {
        TURN {}
    } SCENE {
        ABILITY_POPUP(playerLeft, ABILITY_FOREWARN);
        MESSAGE("Forewarn alerted Musharna to the opposing Excadrill's Fissure!");
    }
}

DOUBLE_BATTLE_TEST("Forewarn does not trigger if a mon switches in while the opposing field is empty")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_U_TURN) == EFFECT_HIT_ESCAPE);
        ASSUME(GetMoveEffect(MOVE_HEALING_WISH) == EFFECT_HEALING_WISH);
        PLAYER(SPECIES_WYNAUT);
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_MUSHARNA) { Ability(ABILITY_FOREWARN); }
        OPPONENT(SPECIES_WYNAUT) { HP(1); }
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_TREECKO);
        OPPONENT(SPECIES_TORCHIC);
    } WHEN {
        TURN {
            MOVE(opponentRight, MOVE_HEALING_WISH);
            MOVE(playerLeft, MOVE_U_TURN, target: opponentLeft);
            SEND_OUT(playerLeft, 2);
            SEND_OUT(opponentLeft, 2);
            SEND_OUT(opponentRight, 3);
        }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, playerRight);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_HEALING_WISH, opponentRight);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_U_TURN, playerLeft);
        HP_BAR(opponentLeft);
        NOT ABILITY_POPUP(playerLeft, ABILITY_FOREWARN);
        MESSAGE("2 sent out Treecko!");
        MESSAGE("2 sent out Torchic!");
        NOT ABILITY_POPUP(playerLeft, ABILITY_FOREWARN);
    }
}
