#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Cloud Nine/Air Lock prevent basic weather effects, but without them disappearing - Sandstorm")
{
    enum Species species = SPECIES_NONE;
    enum Ability ability = ABILITY_NONE;
    PARAMETRIZE { species = SPECIES_PSYDUCK;  ability = ABILITY_CLOUD_NINE; }
    PARAMETRIZE { species = SPECIES_RAYQUAZA; ability = ABILITY_AIR_LOCK; }
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_SANDSTORM) == EFFECT_WEATHER);
        ASSUME(GetMoveWeatherType(MOVE_SANDSTORM) == BATTLE_WEATHER_SANDSTORM);
        PLAYER(species) { Ability(ability); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_SANDSTORM); }
        TURN {}
    } SCENE {
        ABILITY_POPUP(player, ability);
        MESSAGE("The effects of the weather disappeared.");
        MESSAGE("The opposing Wobbuffet used Sandstorm!");
        MESSAGE("The sandstorm is raging.");
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_SANDSTORM_CONTINUES);
        NONE_OF {
            HP_BAR(player);
            HP_BAR(opponent);
            MESSAGE("The opposing Wobbuffet is buffeted by the sandstorm!");
        }
        MESSAGE("The sandstorm is raging.");
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_SANDSTORM_CONTINUES);
    }
}

DOUBLE_BATTLE_TEST("Cloud Nine and Air Lock suppress sunlight's Fire boost without removing sunlight", s16 damage)
{
    enum Species species;
    enum Ability ability;

    PARAMETRIZE { species = SPECIES_PSYDUCK; ability = ABILITY_DAMP; }
    PARAMETRIZE { species = SPECIES_PSYDUCK; ability = ABILITY_CLOUD_NINE; }
    PARAMETRIZE { species = SPECIES_RAYQUAZA; ability = ABILITY_AIR_LOCK; }
    SetStartingStatus(STARTING_STATUS_WEATHER_SUN);

    GIVEN {
        PLAYER(species) { Ability(ability); }
        PLAYER(SPECIES_WOBBUFFET) { SpAttack(100); }
        OPPONENT(SPECIES_WOBBUFFET) { SpDefense(100); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(playerRight, MOVE_EMBER, target: opponentLeft); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_EMBER, playerRight);
        HP_BAR(opponentLeft, captureDamage: &results[i].damage);
    } THEN {
        EXPECT(gBattleWeather & B_WEATHER_SUN);
        ResetStartingStatuses();
    } FINALLY {
        EXPECT_MUL_EQ(results[1].damage, Q_4_12(1.5), results[0].damage);
        EXPECT_EQ(results[1].damage, results[2].damage);
    }
}

DOUBLE_BATTLE_TEST("Cloud Nine and Air Lock suppress rain's Water boost without removing rain", s16 damage)
{
    enum Species species;
    enum Ability ability;

    PARAMETRIZE { species = SPECIES_PSYDUCK; ability = ABILITY_DAMP; }
    PARAMETRIZE { species = SPECIES_PSYDUCK; ability = ABILITY_CLOUD_NINE; }
    PARAMETRIZE { species = SPECIES_RAYQUAZA; ability = ABILITY_AIR_LOCK; }
    SetStartingStatus(STARTING_STATUS_WEATHER_RAIN);

    GIVEN {
        PLAYER(species) { Ability(ability); }
        PLAYER(SPECIES_WOBBUFFET) { SpAttack(100); }
        OPPONENT(SPECIES_WOBBUFFET) { SpDefense(100); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(playerRight, MOVE_WATER_GUN, target: opponentLeft); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_WATER_GUN, playerRight);
        HP_BAR(opponentLeft, captureDamage: &results[i].damage);
    } THEN {
        EXPECT(gBattleWeather & B_WEATHER_RAIN);
        ResetStartingStatuses();
    } FINALLY {
        EXPECT_MUL_EQ(results[1].damage, Q_4_12(1.5), results[0].damage);
        EXPECT_EQ(results[1].damage, results[2].damage);
    }
}

DOUBLE_BATTLE_TEST("Cloud Nine and Air Lock suppress hail damage without removing hail")
{
    enum Species species;
    enum Ability ability;

    PARAMETRIZE { species = SPECIES_PSYDUCK; ability = ABILITY_DAMP; }
    PARAMETRIZE { species = SPECIES_PSYDUCK; ability = ABILITY_CLOUD_NINE; }
    PARAMETRIZE { species = SPECIES_RAYQUAZA; ability = ABILITY_AIR_LOCK; }
    SetStartingStatus(STARTING_STATUS_WEATHER_HAIL);

    GIVEN {
        PLAYER(species) { Ability(ability); }
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { }
    } SCENE {
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HAIL_CONTINUES);
    } THEN {
        if (ability == ABILITY_DAMP)
            EXPECT_LT(playerRight->hp, playerRight->maxHP);
        else
            EXPECT_EQ(playerRight->hp, playerRight->maxHP);
        EXPECT(gBattleWeather & B_WEATHER_HAIL);
        ResetStartingStatuses();
    }
}

DOUBLE_BATTLE_TEST("Cloud Nine and Air Lock suppress snow's Defense boost without removing snow", s16 damage)
{
    enum Species species;
    enum Ability ability;

    PARAMETRIZE { species = SPECIES_PSYDUCK; ability = ABILITY_DAMP; }
    PARAMETRIZE { species = SPECIES_PSYDUCK; ability = ABILITY_CLOUD_NINE; }
    PARAMETRIZE { species = SPECIES_RAYQUAZA; ability = ABILITY_AIR_LOCK; }
    SetStartingStatus(STARTING_STATUS_WEATHER_SNOW);

    GIVEN {
        PLAYER(species) { Ability(ability); }
        PLAYER(SPECIES_WOBBUFFET) { Attack(100); }
        OPPONENT(SPECIES_GLACEON) { Defense(100); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(playerRight, MOVE_SCRATCH, target: opponentLeft); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, playerRight);
        HP_BAR(opponentLeft, captureDamage: &results[i].damage);
    } THEN {
        EXPECT(gBattleWeather & B_WEATHER_SNOW);
        ResetStartingStatuses();
    } FINALLY {
        EXPECT_MUL_EQ(results[0].damage, Q_4_12(1.5), results[1].damage);
        EXPECT_EQ(results[1].damage, results[2].damage);
    }
}

DOUBLE_BATTLE_TEST("Cloud Nine and Air Lock suppress fog's accuracy drop without removing fog")
{
    enum Species species;
    enum Ability ability;

    PARAMETRIZE { species = SPECIES_PSYDUCK; ability = ABILITY_CLOUD_NINE; }
    PARAMETRIZE { species = SPECIES_RAYQUAZA; ability = ABILITY_AIR_LOCK; }
    SetStartingStatus(STARTING_STATUS_WEATHER_FOG);

    GIVEN {
        PLAYER(species) { Ability(ability); }
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(playerRight, MOVE_SCRATCH, target: opponentLeft); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, playerRight);
        HP_BAR(opponentLeft);
    } THEN {
        EXPECT(gBattleWeather & B_WEATHER_FOG);
        ResetStartingStatuses();
    }
}

DOUBLE_BATTLE_TEST("Cloud Nine and Air Lock suppress extremely harsh sunlight without removing it")
{
    enum Species species;
    enum Ability ability;

    PARAMETRIZE { species = SPECIES_PSYDUCK; ability = ABILITY_CLOUD_NINE; }
    PARAMETRIZE { species = SPECIES_RAYQUAZA; ability = ABILITY_AIR_LOCK; }

    GIVEN {
        PLAYER(species) { Ability(ability); }
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_GROUDON_PRIMAL) { Ability(ABILITY_DESOLATE_LAND); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(playerRight, MOVE_WATER_GUN, target: opponentLeft); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_WATER_GUN, playerRight);
        HP_BAR(opponentLeft);
    } THEN {
        EXPECT(gBattleWeather & B_WEATHER_SUN_PRIMAL);
    }
}

DOUBLE_BATTLE_TEST("Cloud Nine and Air Lock suppress heavy rain without removing it")
{
    enum Species species;
    enum Ability ability;

    PARAMETRIZE { species = SPECIES_PSYDUCK; ability = ABILITY_CLOUD_NINE; }
    PARAMETRIZE { species = SPECIES_RAYQUAZA; ability = ABILITY_AIR_LOCK; }

    GIVEN {
        PLAYER(species) { Ability(ability); }
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_KYOGRE_PRIMAL) { Ability(ABILITY_PRIMORDIAL_SEA); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(playerRight, MOVE_EMBER, target: opponentLeft); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_EMBER, playerRight);
        HP_BAR(opponentLeft);
    } THEN {
        EXPECT(gBattleWeather & B_WEATHER_RAIN_PRIMAL);
    }
}

DOUBLE_BATTLE_TEST("Cloud Nine and Air Lock suppress strong winds without removing them", s16 damage)
{
    enum Species species;
    enum Ability ability;

    PARAMETRIZE { species = SPECIES_PSYDUCK; ability = ABILITY_DAMP; }
    PARAMETRIZE { species = SPECIES_PSYDUCK; ability = ABILITY_CLOUD_NINE; }
    PARAMETRIZE { species = SPECIES_RAYQUAZA; ability = ABILITY_AIR_LOCK; }

    GIVEN {
        PLAYER(species) { Ability(ability); }
        PLAYER(SPECIES_WOBBUFFET) { SpAttack(100); }
        OPPONENT(SPECIES_NOCTOWL) { SpDefense(100); }
        OPPONENT(SPECIES_RAYQUAZA_MEGA) { Ability(ABILITY_DELTA_STREAM); }
    } WHEN {
        TURN { MOVE(playerRight, MOVE_THUNDERBOLT, target: opponentLeft); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_THUNDERBOLT, playerRight);
        HP_BAR(opponentLeft, captureDamage: &results[i].damage);
    } THEN {
        EXPECT(gBattleWeather & B_WEATHER_STRONG_WINDS);
    } FINALLY {
        EXPECT_MUL_EQ(results[0].damage, Q_4_12(2.0), results[1].damage);
        EXPECT_EQ(results[1].damage, results[2].damage);
    }
}

// Moves and abilities that are affected by weather should have new tests that check for Clould Nine/Air Lock, like Mold-Breaker Abilities
