#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(GetMoveCategory(MOVE_SCRATCH) == DAMAGE_CATEGORY_PHYSICAL);
    ASSUME(GetMoveCategory(MOVE_SWIFT) == DAMAGE_CATEGORY_SPECIAL);
    ASSUME(GetMoveCategory(MOVE_WATER_GUN) == DAMAGE_CATEGORY_SPECIAL);
    ASSUME(GetMoveAccuracy(MOVE_SCRATCH) == 100);
    ASSUME(GetMoveAccuracy(MOVE_WATER_GUN) == 100);
    ASSUME(GetMoveAccuracy(MOVE_LEER) == 100);
    ASSUME(GetMoveAccuracy(MOVE_AERIAL_ACE) == 0);
}

SINGLE_BATTLE_TEST("Hustle multiplies physical damage by 1.5", s16 damage)
{
    enum Ability ability;
    PARAMETRIZE { ability = ABILITY_INNER_FOCUS; }
    PARAMETRIZE { ability = ABILITY_HUSTLE; }
    GIVEN {
        PLAYER(SPECIES_DARUMAKA) { Ability(ability); Level(50); Attack(200); Speed(100); }
        OPPONENT(SPECIES_WOBBUFFET) { HP(1000); Defense(100); Speed(50); }
    } WHEN {
        TURN { MOVE(player, MOVE_SCRATCH); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, player);
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_MUL_EQ(results[0].damage, UQ_4_12(1.5), results[1].damage);
    }
}

SINGLE_BATTLE_TEST("Hustle does not increase special damage", s16 damage)
{
    enum Ability ability;
    PARAMETRIZE { ability = ABILITY_INNER_FOCUS; }
    PARAMETRIZE { ability = ABILITY_HUSTLE; }
    GIVEN {
        PLAYER(SPECIES_DARUMAKA) { Ability(ability); Level(50); Attack(200); Speed(100); }
        OPPONENT(SPECIES_WOBBUFFET) { HP(1000); Defense(100); Speed(50); }
    } WHEN {
        TURN { MOVE(player, MOVE_SWIFT); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SWIFT, player);
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_EQ(results[0].damage, results[1].damage);
    }
}

SINGLE_BATTLE_TEST("Hustle does not increase fixed damage", s16 damage)
{
    enum Ability ability;
    PARAMETRIZE { ability = ABILITY_INNER_FOCUS; }
    PARAMETRIZE { ability = ABILITY_HUSTLE; }
    GIVEN {
        PLAYER(SPECIES_DARUMAKA) { Ability(ability); Level(50); Attack(200); Speed(100); }
        OPPONENT(SPECIES_WOBBUFFET) { HP(1000); Defense(100); Speed(50); }
    } WHEN {
        TURN { MOVE(player, MOVE_SEISMIC_TOSS); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SEISMIC_TOSS, player);
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_EQ(results[0].damage, 50);
        EXPECT_EQ(results[1].damage, 50);
    }
}

SINGLE_BATTLE_TEST("Hustle loses its damage boost when suppressed", s16 damage)
{
    enum Ability ability;
    PARAMETRIZE { ability = ABILITY_INNER_FOCUS; }
    PARAMETRIZE { ability = ABILITY_HUSTLE; }
    GIVEN {
        PLAYER(SPECIES_DARUMAKA) { Ability(ability); Level(50); Attack(200); Speed(100); }
        OPPONENT(SPECIES_WOBBUFFET) { HP(1000); Defense(100); Speed(50); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_GASTRO_ACID); }
        TURN { MOVE(player, MOVE_SCRATCH); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, player);
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_EQ(results[0].damage, results[1].damage);
    }
}

SINGLE_BATTLE_TEST("Hustle multiplies physical move accuracy by 0.8")
{
    PASSES_RANDOMLY(80, 100, RNG_ACCURACY);
    GIVEN {
        PLAYER(SPECIES_DARUMAKA) { Ability(ABILITY_HUSTLE); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_SCRATCH); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, player);
        HP_BAR(opponent);
    }
}

SINGLE_BATTLE_TEST("Hustle does not reduce special move accuracy")
{
    PASSES_RANDOMLY(100, 100, RNG_ACCURACY);
    GIVEN {
        PLAYER(SPECIES_DARUMAKA) { Ability(ABILITY_HUSTLE); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_WATER_GUN); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_WATER_GUN, player);
        HP_BAR(opponent);
    }
}

SINGLE_BATTLE_TEST("Hustle does not reduce status move accuracy")
{
    PASSES_RANDOMLY(100, 100, RNG_ACCURACY);
    GIVEN {
        PLAYER(SPECIES_DARUMAKA) { Ability(ABILITY_HUSTLE); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_LEER); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_LEER, player);
    } THEN {
        EXPECT_EQ(opponent->statStages[STAT_DEF], DEFAULT_STAT_STAGE - 1);
    }
}

SINGLE_BATTLE_TEST("Hustle does not make guaranteed-hit physical moves miss")
{
    PASSES_RANDOMLY(100, 100, RNG_ACCURACY);
    GIVEN {
        PLAYER(SPECIES_DARUMAKA) { Ability(ABILITY_HUSTLE); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_AERIAL_ACE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_AERIAL_ACE, player);
        HP_BAR(opponent);
    }
}
