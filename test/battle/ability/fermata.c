#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Fermata converts Round into a two-strike move")
{
    GIVEN {
        ASSUME(gMovesInfo[MOVE_ROUND].soundMove);
        ASSUME(gMovesInfo[MOVE_ROUND].strikeCount < 2);
        PLAYER(SPECIES_CHATOT) {Ability(ABILITY_FERMATA); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_ROUND); MOVE(opponent, MOVE_CELEBRATE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_ROUND, player);
        HP_BAR(opponent);
        HP_BAR(opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, opponent);
}
}

SINGLE_BATTLE_TEST("Fermata causes status sound moves to move twice")
{
    GIVEN {
        ASSUME(gMovesInfo[MOVE_GROWL].soundMove);
        ASSUME(gMovesInfo[MOVE_GROWL].strikeCount < 2);
        PLAYER(SPECIES_CHATOT) {Ability(ABILITY_FERMATA); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_GROWL); MOVE(opponent, MOVE_CELEBRATE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_GROWL, player);
        MESSAGE("Foe Wobbuffet's Attack fell!");
        MESSAGE("Foe Wobbuffet's Attack fell!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, opponent);
}
}

DOUBLE_BATTLE_TEST("Fermata causes partner's sound moves to hit twice")
{
    GIVEN {
        ASSUME(gMovesInfo[MOVE_ROUND].soundMove);
        ASSUME(gMovesInfo[MOVE_ROUND].strikeCount < 2);
        PLAYER(SPECIES_CHATOT) {Ability(ABILITY_FERMATA);}
        PLAYER(SPECIES_KADABRA)
        OPPONENT(SPECIES_WOBBUFFET)
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN {MOVE(playerLeft, MOVE_CELEBRATE); MOVE(playerRight, MOVE_ROUND, target: opponentLeft); MOVE(opponentLeft, MOVE_CELEBRATE); MOVE(opponentRight, MOVE_CELEBRATE);}
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, playerLeft);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_ROUND, playerRight);
        HP_BAR(opponentLeft);
        HP_BAR(opponentLeft);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, opponentLeft);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, opponentRight);
}
}

