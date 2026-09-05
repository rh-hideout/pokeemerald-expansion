#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(GetMoveType(MOVE_HYPER_VOICE) == TYPE_NORMAL);
    ASSUME(GetMovePower(MOVE_HYPER_VOICE) > 0);
}

SINGLE_BATTLE_TEST("Liquid Voice allows Water Absorb to absorb Hyper Voice")
{
    enum Ability ability;
    PARAMETRIZE { ability = ABILITY_TORRENT; }
    PARAMETRIZE { ability = ABILITY_LIQUID_VOICE; }
    GIVEN {
        PLAYER(SPECIES_PRIMARINA) { Ability(ability); }
        OPPONENT(SPECIES_VAPOREON) { Ability(ABILITY_WATER_ABSORB); MaxHP(1000); HP(500); }
    } WHEN {
        TURN { MOVE(player, MOVE_HYPER_VOICE); }
    } THEN {
        if (ability == ABILITY_LIQUID_VOICE)
            EXPECT_EQ(opponent->hp, 750);
        else
            EXPECT_LT(opponent->hp, 500);
    }
}

SINGLE_BATTLE_TEST("Liquid Voice does not add a power boost to an already Water-type sound move", s16 damage)
{
    enum Ability ability;
    PARAMETRIZE { ability = ABILITY_TORRENT; }
    PARAMETRIZE { ability = ABILITY_LIQUID_VOICE; }
    GIVEN {
        ASSUME(GetMoveType(MOVE_SPARKLING_ARIA) == TYPE_WATER);
        PLAYER(SPECIES_PRIMARINA) { Ability(ability); }
        OPPONENT(SPECIES_WOBBUFFET) { HP(1000); }
    } WHEN {
        TURN { MOVE(player, MOVE_SPARKLING_ARIA); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SPARKLING_ARIA, player);
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_EQ(results[0].damage, results[1].damage);
    }
}

DOUBLE_BATTLE_TEST("Liquid Voice Perish Song is absorbed by Water Absorb and Storm Drain")
{
    enum Species species;
    enum Ability ability;
    PARAMETRIZE { species = SPECIES_VAPOREON; ability = ABILITY_WATER_ABSORB; }
    PARAMETRIZE { species = SPECIES_GASTRODON; ability = ABILITY_STORM_DRAIN; }
    GIVEN {
        PLAYER(SPECIES_PRIMARINA) { Ability(ABILITY_LIQUID_VOICE); Speed(100); }
        PLAYER(species) { Ability(ability); MaxHP(1000); HP(500); Speed(90); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(80); }
        OPPONENT(SPECIES_VOLTORB) { Ability(ABILITY_SOUNDPROOF); Speed(70); }
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_PERISH_SONG); }
        TURN {}
        TURN {}
        TURN {}
    } THEN {
        EXPECT_EQ(playerLeft->hp, 0);
        EXPECT_EQ(opponentLeft->hp, 0);
        EXPECT_GT(opponentRight->hp, 0);
        EXPECT_EQ(playerRight->hp, ability == ABILITY_WATER_ABSORB ? 750 : 500);
        EXPECT_EQ(playerRight->statStages[STAT_SPATK], DEFAULT_STAT_STAGE + (ability == ABILITY_STORM_DRAIN));
    }
}

SINGLE_BATTLE_TEST("Liquid voice turns a sound move into a Water-type move")
{
    GIVEN {
        PLAYER(SPECIES_TYPHLOSION);
        OPPONENT(SPECIES_PRIMARINA) { Ability(ABILITY_LIQUID_VOICE); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_HYPER_VOICE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_HYPER_VOICE, opponent);
        MESSAGE("It's super effective!");
    }
}
