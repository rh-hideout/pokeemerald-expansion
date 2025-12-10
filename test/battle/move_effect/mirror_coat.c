#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(GetMoveEffect(MOVE_MIRROR_COAT) == EFFECT_MIRROR_COAT);
    ASSUME(GetMoveCategory(MOVE_ROUND) == DAMAGE_CATEGORY_SPECIAL);
}

SINGLE_BATTLE_TEST("Mirror Coat will do twice as much damage received from the opponent")
{
    s16 normalDmg;
    s16 mirrorCoatDmg;
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_ROUND); MOVE(player, MOVE_MIRROR_COAT); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_ROUND, opponent);
        HP_BAR(player, captureDamage: &normalDmg);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_MIRROR_COAT, player);
        HP_BAR(opponent, captureDamage: &mirrorCoatDmg);
    } THEN {
        EXPECT_MUL_EQ(normalDmg, Q_4_12(2.0), mirrorCoatDmg);
    }
}

DOUBLE_BATTLE_TEST("Mirror Coat cannot affect ally Pokémon")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WYNAUT);
    } WHEN {
        TURN {
            MOVE(playerLeft, MOVE_ROUND, target: playerRight);
            MOVE(playerRight, MOVE_MIRROR_COAT, target: playerLeft);
        }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_ROUND, playerLeft);
        NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_MIRROR_COAT, playerRight);
    }
}

DOUBLE_BATTLE_TEST("Mirror Coat hits the last opponent that hit the user")
{
    s16 normalDmg;
    s16 mirrorCoatDmg;

    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WYNAUT);
    } WHEN {
        TURN {
            MOVE(opponentLeft, MOVE_ROUND, target: playerLeft);
            MOVE(opponentRight, MOVE_ROUND, target: playerLeft);
            MOVE(playerLeft, MOVE_MIRROR_COAT);
        }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_ROUND, opponentLeft);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_ROUND, opponentRight);
        HP_BAR(playerLeft, captureDamage: &normalDmg);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_MIRROR_COAT, playerLeft);
        HP_BAR(opponentRight, captureDamage: &mirrorCoatDmg);
    } THEN {
        EXPECT_MUL_EQ(normalDmg, Q_4_12(2.0), mirrorCoatDmg);
    }
}

DOUBLE_BATTLE_TEST("Mirror Coat respects Follow Me")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WYNAUT);
    } WHEN {
        TURN {
            MOVE(opponentRight, MOVE_FOLLOW_ME);
            MOVE(opponentLeft, MOVE_ROUND, target: playerLeft);
            MOVE(playerLeft, MOVE_MIRROR_COAT, target: opponentLeft);
        }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_FOLLOW_ME, opponentRight);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_ROUND, opponentLeft);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_MIRROR_COAT, playerLeft);
        HP_BAR(opponentRight);
    }
}

DOUBLE_BATTLE_TEST("Mirror Coat fails if mon that damaged Mirror Coat user is no longer on the field (Gen 1-4)")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_WOBBUFFET) { HP(1); };
        OPPONENT(SPECIES_WYNAUT);
    } WHEN {
        TURN {
            MOVE(opponentLeft, MOVE_ROUND, target: playerLeft);
            MOVE(playerRight, MOVE_ROUND, target: opponentLeft);
            MOVE(playerLeft, MOVE_MIRROR_COAT, target: opponentLeft);
        }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_ROUND, opponentLeft);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_ROUND, playerRight);
        NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_MIRROR_COAT, playerLeft);
    }
}

SINGLE_BATTLE_TEST("Mirror Coat deals 1 damage when the attack received is blocked by Disguise")
{
    s16 mirrorCoatDmg;
    GIVEN {
        ASSUME(GetMoveCategory(MOVE_HEX) == DAMAGE_CATEGORY_SPECIAL);
        PLAYER(SPECIES_MIMIKYU) { Ability(ABILITY_DISGUISE); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_HEX); MOVE(player, MOVE_MIRROR_COAT); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_HEX, opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_MIRROR_COAT, player);
        HP_BAR(opponent, captureDamage: &mirrorCoatDmg);
    } THEN {
        EXPECT_EQ(mirrorCoatDmg, 1);
    }
}
