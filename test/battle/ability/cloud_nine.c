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
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SANDSTORM, opponent);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_SANDSTORM_CONTINUES);
        NONE_OF {
            HP_BAR(player);
            HP_BAR(opponent);
        }
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
        ASSUME(GetMoveType(MOVE_EMBER) == TYPE_FIRE);
        ASSUME(GetMoveCategory(MOVE_EMBER) == DAMAGE_CATEGORY_SPECIAL);
        PLAYER(species) { Ability(ability); }
        PLAYER(SPECIES_WOBBUFFET) { SpAttack(100); }
        OPPONENT(SPECIES_WOBBUFFET) { SpDefense(100); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(playerRight, MOVE_EMBER, target: opponentLeft); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_EMBER, playerRight);
        HP_BAR(opponentLeft, captureDamage: &results[i].damage);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_SUN_CONTINUES);
    } THEN {
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
        ASSUME(GetMoveType(MOVE_WATER_GUN) == TYPE_WATER);
        ASSUME(GetMoveCategory(MOVE_WATER_GUN) == DAMAGE_CATEGORY_SPECIAL);
        PLAYER(species) { Ability(ability); }
        PLAYER(SPECIES_WOBBUFFET) { SpAttack(100); }
        OPPONENT(SPECIES_WOBBUFFET) { SpDefense(100); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(playerRight, MOVE_WATER_GUN, target: opponentLeft); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_WATER_GUN, playerRight);
        HP_BAR(opponentLeft, captureDamage: &results[i].damage);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_RAIN_CONTINUES);
    } THEN {
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
        if (ability == ABILITY_DAMP) {
            HP_BAR(playerRight);
        } else {
            NONE_OF {
                HP_BAR(playerLeft);
                HP_BAR(playerRight);
                HP_BAR(opponentLeft);
                HP_BAR(opponentRight);
            }
        }
    } THEN {
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
        ASSUME(GetSpeciesType(SPECIES_GLACEON, 0) == TYPE_ICE);
        ASSUME(GetMoveCategory(MOVE_SCRATCH) == DAMAGE_CATEGORY_PHYSICAL);
        PLAYER(species) { Ability(ability); }
        PLAYER(SPECIES_WOBBUFFET) { Attack(100); }
        OPPONENT(SPECIES_GLACEON) { Defense(100); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(playerRight, MOVE_SCRATCH, target: opponentLeft); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, playerRight);
        HP_BAR(opponentLeft, captureDamage: &results[i].damage);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_SNOW_CONTINUES);
    } THEN {
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
    PASSES_RANDOMLY(100, 100, RNG_ACCURACY);
    SetStartingStatus(STARTING_STATUS_WEATHER_FOG);

    GIVEN {
        ASSUME(GetMoveAccuracy(MOVE_SCRATCH) == 100);
        PLAYER(species) { Ability(ability); }
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(playerRight, MOVE_SCRATCH, target: opponentLeft); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, playerRight);
        HP_BAR(opponentLeft);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_FOG_CONTINUES);
    } THEN {
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
        ASSUME(GetMoveType(MOVE_WATER_GUN) == TYPE_WATER);
        ASSUME(GetMoveCategory(MOVE_WATER_GUN) != DAMAGE_CATEGORY_STATUS);
        PLAYER(species) { Ability(ability); }
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_GROUDON) { Item(ITEM_RED_ORB); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(playerRight, MOVE_WATER_GUN, target: opponentLeft); }
    } SCENE {
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_PRIMAL_REVERSION, opponentLeft);
        ABILITY_POPUP(opponentLeft, ABILITY_DESOLATE_LAND);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_WATER_GUN, playerRight);
        HP_BAR(opponentLeft);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_SUN_CONTINUES);
    }
}

DOUBLE_BATTLE_TEST("Cloud Nine and Air Lock suppress heavy rain without removing it")
{
    enum Species species;
    enum Ability ability;

    PARAMETRIZE { species = SPECIES_PSYDUCK; ability = ABILITY_CLOUD_NINE; }
    PARAMETRIZE { species = SPECIES_RAYQUAZA; ability = ABILITY_AIR_LOCK; }

    GIVEN {
        ASSUME(GetMoveType(MOVE_EMBER) == TYPE_FIRE);
        ASSUME(GetMoveCategory(MOVE_EMBER) != DAMAGE_CATEGORY_STATUS);
        PLAYER(species) { Ability(ability); }
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_KYOGRE) { Item(ITEM_BLUE_ORB); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(playerRight, MOVE_EMBER, target: opponentLeft); }
    } SCENE {
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_PRIMAL_REVERSION, opponentLeft);
        ABILITY_POPUP(opponentLeft, ABILITY_PRIMORDIAL_SEA);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_EMBER, playerRight);
        HP_BAR(opponentLeft);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_RAIN_CONTINUES);
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
        ASSUME(GetMoveType(MOVE_THUNDERBOLT) == TYPE_ELECTRIC);
        ASSUME(GetMoveCategory(MOVE_THUNDERBOLT) == DAMAGE_CATEGORY_SPECIAL);
        ASSUME(GetSpeciesType(SPECIES_NOCTOWL, 1) == TYPE_FLYING);
        PLAYER(species) { Ability(ability); }
        PLAYER(SPECIES_WOBBUFFET) { SpAttack(100); }
        OPPONENT(SPECIES_NOCTOWL) { SpDefense(100); }
        OPPONENT(SPECIES_RAYQUAZA) { Moves(MOVE_DRAGON_ASCENT, MOVE_CELEBRATE); }
    } WHEN {
        TURN { MOVE(opponentRight, MOVE_CELEBRATE, gimmick: GIMMICK_MEGA); }
        TURN { MOVE(playerRight, MOVE_THUNDERBOLT, target: opponentLeft); }
    } SCENE {
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_MEGA_EVOLUTION, opponentRight);
        ABILITY_POPUP(opponentRight, ABILITY_DELTA_STREAM);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_THUNDERBOLT, playerRight);
        HP_BAR(opponentLeft, captureDamage: &results[i].damage);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STRONG_WINDS);
    } FINALLY {
        EXPECT_MUL_EQ(results[0].damage, Q_4_12(2.0), results[1].damage);
        EXPECT_EQ(results[1].damage, results[2].damage);
    }
}

// Weather-specific interactions belong with the affected move or Ability.
