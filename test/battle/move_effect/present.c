#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(GetMoveEffect(MOVE_PRESENT) == EFFECT_PRESENT);
    ASSUME(GetMoveEffect(MOVE_MIRROR_MOVE) == EFFECT_MIRROR_MOVE);
}

SINGLE_BATTLE_TEST("Present healing through Wonder Guard is still considered to have affected the target")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Speed(1); }
        OPPONENT(SPECIES_SHEDINJA) { Ability(ABILITY_WONDER_GUARD); HP(1); MaxHP(100); Speed(100); }
    } WHEN {
        TURN { MOVE(player, MOVE_PRESENT, WITH_RNG(RNG_PRESENT, 254)); }
        TURN { MOVE(opponent, MOVE_MIRROR_MOVE, WITH_RNG(RNG_PRESENT, 1)); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_PRESENT, player);
        HP_BAR(opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_MIRROR_MOVE, opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_PRESENT, opponent);
        HP_BAR(player);
    }
}

DOUBLE_BATTLE_TEST("Present healing through Telepathy is still considered to have affected the ally target")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Speed(1); }
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_TELEPATHY); HP(50); MaxHP(100); Speed(100); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(2); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(3); }
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_PRESENT, target: playerRight, WITH_RNG(RNG_PRESENT, 254)); }
        TURN { MOVE(playerRight, MOVE_MIRROR_MOVE, target: opponentLeft, WITH_RNG(RNG_PRESENT, 1)); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_PRESENT, playerLeft);
        HP_BAR(playerRight);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_MIRROR_MOVE, playerRight);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_PRESENT, playerRight);
        ONE_OF { HP_BAR(opponentLeft); HP_BAR(opponentRight); }
    }
}
