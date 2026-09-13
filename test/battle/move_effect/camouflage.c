#include "global.h"
#include "test/battle.h"
#include "battle_environment.h"

SINGLE_BATTLE_TEST("Camouflage changes the type of the user based on battle environment")
{
    u32 environment = 0;

    for (u32 j = 0; j < BATTLE_ENVIRONMENT_COUNT; j++)
        PARAMETRIZE { environment = j; }

    GIVEN {
        ASSUME(GetSpeciesType(SPECIES_EKANS, 0) == TYPE_POISON);
        PLAYER(SPECIES_EKANS);
        OPPONENT(SPECIES_WOBBUFFET);
        Environment(environment);
    } WHEN {
        TURN { MOVE(player, MOVE_CAMOUFLAGE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CAMOUFLAGE, player);
    } THEN {
        EXPECT_EQ(player->types[0], gBattleEnvironmentInfo[environment].camouflageType);
        EXPECT_EQ(player->types[1], gBattleEnvironmentInfo[environment].camouflageType);
        EXPECT_EQ(player->types[2], TYPE_MYSTERY);
    }
}

SINGLE_BATTLE_TEST("Camouflage changes the type of the user to Grass if Grassy Terrain is active")
{
    GIVEN {
        PLAYER(SPECIES_EKANS) { Speed(1); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(2); }
        Environment(BATTLE_ENVIRONMENT_BUILDING);
    } WHEN {
        TURN { MOVE(opponent, MOVE_GRASSY_TERRAIN); MOVE(player, MOVE_CAMOUFLAGE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CAMOUFLAGE, player);
    } THEN {
        EXPECT_EQ(player->types[0], TYPE_GRASS);
        EXPECT_EQ(player->types[1], TYPE_GRASS);
        EXPECT_EQ(player->types[2], TYPE_MYSTERY);
    }
}

SINGLE_BATTLE_TEST("Camouflage changes the type of the user to Electric if Electric Terrain is active")
{
    GIVEN {
        PLAYER(SPECIES_EKANS) { Speed(1); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(2); }
        Environment(BATTLE_ENVIRONMENT_BUILDING);
    } WHEN {
        TURN { MOVE(opponent, MOVE_ELECTRIC_TERRAIN); MOVE(player, MOVE_CAMOUFLAGE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CAMOUFLAGE, player);
    } THEN {
        EXPECT_EQ(player->types[0], TYPE_ELECTRIC);
        EXPECT_EQ(player->types[1], TYPE_ELECTRIC);
        EXPECT_EQ(player->types[2], TYPE_MYSTERY);
    }
}

SINGLE_BATTLE_TEST("Camouflage changes the type of the user to Psychic if Psychic Terrain is active")
{
    GIVEN {
        PLAYER(SPECIES_EKANS) { Speed(1); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(2); }
        Environment(BATTLE_ENVIRONMENT_BUILDING);
    } WHEN {
        TURN { MOVE(opponent, MOVE_PSYCHIC_TERRAIN); MOVE(player, MOVE_CAMOUFLAGE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CAMOUFLAGE, player);
    } THEN {
        EXPECT_EQ(player->types[0], TYPE_PSYCHIC);
        EXPECT_EQ(player->types[1], TYPE_PSYCHIC);
        EXPECT_EQ(player->types[2], TYPE_MYSTERY);
    }
}

SINGLE_BATTLE_TEST("Camouflage changes the type of the user to Fairy if Misty Terrain is active")
{
    GIVEN {
        PLAYER(SPECIES_EKANS) { Speed(1); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(2); }
        Environment(BATTLE_ENVIRONMENT_BUILDING);
    } WHEN {
        TURN { MOVE(opponent, MOVE_MISTY_TERRAIN); MOVE(player, MOVE_CAMOUFLAGE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CAMOUFLAGE, player);
    } THEN {
        EXPECT_EQ(player->types[0], TYPE_FAIRY);
        EXPECT_EQ(player->types[1], TYPE_FAIRY);
        EXPECT_EQ(player->types[2], TYPE_MYSTERY);
    }
}

SINGLE_BATTLE_TEST("Camouflage fails if the user already has the environment's type")
{
    GIVEN {
        ASSUME(GetSpeciesType(SPECIES_BULBASAUR, 0) == TYPE_GRASS);
        PLAYER(SPECIES_BULBASAUR);
        OPPONENT(SPECIES_WOBBUFFET);
        Environment(BATTLE_ENVIRONMENT_GRASS);
    } WHEN {
        TURN { MOVE(player, MOVE_CAMOUFLAGE); }
    } SCENE {
        NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_CAMOUFLAGE, player);
        MESSAGE("But it failed!");
    }
}

SINGLE_BATTLE_TEST("Camouflage fails if the user is Terastallized")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { TeraType(TYPE_PSYCHIC); }
        OPPONENT(SPECIES_WOBBUFFET);
        Environment(BATTLE_ENVIRONMENT_GRASS);
    } WHEN {
        TURN { MOVE(player, MOVE_CAMOUFLAGE, gimmick: GIMMICK_TERA); }
    } SCENE {
        NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_CAMOUFLAGE, player);
        MESSAGE("But it failed!");
    }
}
