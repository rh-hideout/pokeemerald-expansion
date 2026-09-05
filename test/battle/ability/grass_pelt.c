#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(GetMoveCategory(MOVE_SCRATCH) == DAMAGE_CATEGORY_PHYSICAL);
    ASSUME(GetMoveCategory(MOVE_SWIFT) == DAMAGE_CATEGORY_SPECIAL);
}

SINGLE_BATTLE_TEST("Grass Pelt multiplies Defense by 1.5 on Grassy Terrain", s16 damage)
{
    enum Ability ability;
    PARAMETRIZE { ability = ABILITY_GRASS_PELT; }
    PARAMETRIZE { ability = ABILITY_SAP_SIPPER; }
    GIVEN {
        PLAYER(SPECIES_GOGOAT) { Ability(ability); HP(1000); Defense(100); SpDefense(100); Speed(100); }
        OPPONENT(SPECIES_WOBBUFFET) { Attack(200); SpAttack(200); Speed(50); }

    } WHEN {
        TURN { MOVE(player, MOVE_GRASSY_TERRAIN); MOVE(opponent, MOVE_SCRATCH); }
    } SCENE {
        HP_BAR(player, captureDamage: &results[i].damage);
    } THEN {
        EXPECT_EQ(player->statStages[STAT_DEF], DEFAULT_STAT_STAGE);
    } FINALLY {
        EXPECT_MUL_EQ(results[0].damage, UQ_4_12(1.5), results[1].damage);
    }
}

SINGLE_BATTLE_TEST("Grass Pelt does not activate without Grassy Terrain", s16 damage)
{
    enum Ability ability;
    enum Move move;
    PARAMETRIZE { ability = ABILITY_GRASS_PELT; move = MOVE_CELEBRATE; }
    PARAMETRIZE { ability = ABILITY_SAP_SIPPER; move = MOVE_CELEBRATE; }
    PARAMETRIZE { ability = ABILITY_GRASS_PELT; move = MOVE_ELECTRIC_TERRAIN; }
    PARAMETRIZE { ability = ABILITY_GRASS_PELT; move = MOVE_PSYCHIC_TERRAIN; }
    PARAMETRIZE { ability = ABILITY_GRASS_PELT; move = MOVE_MISTY_TERRAIN; }
    GIVEN {
        PLAYER(SPECIES_GOGOAT) { Ability(ability); HP(1000); Defense(100); SpDefense(100); Speed(100); }
        OPPONENT(SPECIES_WOBBUFFET) { Attack(200); SpAttack(200); Speed(50); }

    } WHEN {
        TURN { MOVE(player, move); MOVE(opponent, MOVE_SCRATCH); }
    } SCENE {
        HP_BAR(player, captureDamage: &results[i].damage);
    } FINALLY {
        for (u32 j = 1; j < 5; j++)
            EXPECT_EQ(results[0].damage, results[j].damage);
    }
}

SINGLE_BATTLE_TEST("Grass Pelt does not reduce special damage", s16 damage)
{
    enum Ability ability;
    PARAMETRIZE { ability = ABILITY_GRASS_PELT; }
    PARAMETRIZE { ability = ABILITY_SAP_SIPPER; }
    GIVEN {
        PLAYER(SPECIES_GOGOAT) { Ability(ability); HP(1000); Defense(100); SpDefense(100); Speed(100); }
        OPPONENT(SPECIES_WOBBUFFET) { Attack(200); SpAttack(200); Speed(50); }

    } WHEN {
        TURN { MOVE(player, MOVE_GRASSY_TERRAIN); MOVE(opponent, MOVE_SWIFT); }
    } SCENE {
        HP_BAR(player, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_EQ(results[0].damage, results[1].damage);
    }
}

SINGLE_BATTLE_TEST("Grass Pelt does not reduce fixed damage", s16 damage)
{
    enum Ability ability;
    PARAMETRIZE { ability = ABILITY_GRASS_PELT; }
    PARAMETRIZE { ability = ABILITY_SAP_SIPPER; }
    GIVEN {
        PLAYER(SPECIES_GOGOAT) { Ability(ability); HP(1000); Defense(100); SpDefense(100); Speed(100); }
        OPPONENT(SPECIES_WOBBUFFET) { Attack(200); SpAttack(200); Speed(50); }

    } WHEN {
        TURN { MOVE(player, MOVE_GRASSY_TERRAIN); MOVE(opponent, MOVE_SONIC_BOOM); }
    } SCENE {
        HP_BAR(player, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_EQ(results[0].damage, 20);
        EXPECT_EQ(results[1].damage, 20);
    }
}

SINGLE_BATTLE_TEST("Grass Pelt stops boosting Defense when Grassy Terrain is replaced", s16 damage)
{
    enum Ability ability;
    PARAMETRIZE { ability = ABILITY_GRASS_PELT; }
    PARAMETRIZE { ability = ABILITY_SAP_SIPPER; }
    GIVEN {
        PLAYER(SPECIES_GOGOAT) { Ability(ability); HP(1000); Defense(100); SpDefense(100); Speed(100); }
        OPPONENT(SPECIES_WOBBUFFET) { Attack(200); SpAttack(200); Speed(50); }

    } WHEN {
        TURN { MOVE(player, MOVE_GRASSY_TERRAIN); }
        TURN { MOVE(player, MOVE_ELECTRIC_TERRAIN); MOVE(opponent, MOVE_SCRATCH); }
    } SCENE {
        HP_BAR(player, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_EQ(results[0].damage, results[1].damage);
    }
}

SINGLE_BATTLE_TEST("Grass Pelt stops boosting Defense when Grassy Terrain expires", s16 damage)
{
    enum Ability ability;
    PARAMETRIZE { ability = ABILITY_GRASS_PELT; }
    PARAMETRIZE { ability = ABILITY_SAP_SIPPER; }
    GIVEN {
        PLAYER(SPECIES_GOGOAT) { Ability(ability); HP(1000); Defense(100); Speed(100); }
        OPPONENT(SPECIES_WOBBUFFET) { Attack(200); Speed(50); }
    } WHEN {
        TURN { MOVE(player, MOVE_GRASSY_TERRAIN); }
        TURN {}
        TURN {}
        TURN {}
        TURN {}
        TURN { MOVE(opponent, MOVE_SCRATCH); }
    } SCENE {
        HP_BAR(player, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_EQ(results[0].damage, results[1].damage);
    }
}

SINGLE_BATTLE_TEST("Grass Pelt stops boosting Defense when suppressed", s16 damage)
{
    enum Ability ability;
    PARAMETRIZE { ability = ABILITY_GRASS_PELT; }
    PARAMETRIZE { ability = ABILITY_SAP_SIPPER; }
    GIVEN {
        PLAYER(SPECIES_GOGOAT) { Ability(ability); HP(1000); Defense(100); SpDefense(100); Speed(100); }
        OPPONENT(SPECIES_WOBBUFFET) { Attack(200); SpAttack(200); Speed(50); }

    } WHEN {
        TURN { MOVE(player, MOVE_GRASSY_TERRAIN); MOVE(opponent, MOVE_GASTRO_ACID); }
        TURN { MOVE(opponent, MOVE_SCRATCH); }
    } SCENE {
        HP_BAR(player, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_EQ(results[0].damage, results[1].damage);
    }
}
