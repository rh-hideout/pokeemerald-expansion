#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Grassy Cloak, Sandy Cloak, and Trashy Cloak halve damage from super effective moves", s16 damage)
{
    u32 ability;
    PARAMETRIZE { ability = ABILITY_HYPER_CUTTER; }
    PARAMETRIZE { ability = ABILITY_GRASSY_CLOAK; }
    PARAMETRIZE { ability = ABILITY_SANDY_CLOAK; }
    PARAMETRIZE { ability = ABILITY_TRASHY_CLOAK; }
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_BURMY) { Ability(ability); }
    } WHEN {
        TURN { MOVE(player, MOVE_ROCK_THROW); }
    } SCENE {
        MESSAGE("Wobbuffet used Rock Throw!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_ROCK_THROW, player);
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_MUL_EQ(results[0].damage, Q_4_12(0.75), results[1].damage);
        EXPECT_MUL_EQ(results[0].damage, Q_4_12(0.75), results[2].damage);
        EXPECT_MUL_EQ(results[0].damage, Q_4_12(0.75), results[3].damage);
    }
}

SINGLE_BATTLE_TEST("Grassy Cloak absorbs Grass moves")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_BURMY) { Ability(ABILITY_GRASSY_CLOAK); HP(1); MaxHP(100); }
    } WHEN {
        TURN { MOVE(player, MOVE_ABSORB); }
    } SCENE {
        MESSAGE("Wobbuffet used Absorb!");
        HP_BAR(opponent, damage: -25);
    }
}

SINGLE_BATTLE_TEST("Sandy Cloak absorbs Ground moves")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_BURMY) { Ability(ABILITY_SANDY_CLOAK); HP(1); MaxHP(100); }
    } WHEN {
        TURN { MOVE(player, MOVE_EARTHQUAKE); }
    } SCENE {
        MESSAGE("Wobbuffet used Earthquake!");
        HP_BAR(opponent, damage: -25);
    }
}

SINGLE_BATTLE_TEST("Trashy Cloak absorbs Steel moves")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_BURMY) { Ability(ABILITY_TRASHY_CLOAK); HP(1); MaxHP(100); }
    } WHEN {
        TURN { MOVE(player, MOVE_IRON_HEAD); }
    } SCENE {
        MESSAGE("Wobbuffet used Iron Head!");
        HP_BAR(opponent, damage: -25);
    }
}

SINGLE_BATTLE_TEST("Grassy Cloak powers up Grass moves", s16 damage)
{
    u32 move;
    PARAMETRIZE{move = MOVE_POUND; }
    PARAMETRIZE{move = MOVE_VINE_WHIP; }
    GIVEN {
        PLAYER(SPECIES_WYNAUT) { Ability(ABILITY_GRASSY_CLOAK);}
        OPPONENT(SPECIES_WOBBUFFET){ Ability(ABILITY_SHADOW_TAG);}
    } WHEN {
        TURN { MOVE(player, move); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, move, player);
        HP_BAR(opponent, captureDamage: &results[i].damage);
        EXPECT_MUL_EQ(results[0].damage, Q_4_12(1.5), results[1].damage);
    }
}