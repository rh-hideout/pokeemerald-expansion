#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(GetMoveCategory(MOVE_SCRATCH) == DAMAGE_CATEGORY_PHYSICAL);
    ASSUME(GetMoveCategory(MOVE_WATER_GUN) == DAMAGE_CATEGORY_SPECIAL);
    ASSUME(GetMoveEffect(MOVE_SEISMIC_TOSS) == EFFECT_LEVEL_DAMAGE);
}

SINGLE_BATTLE_TEST("Huge Power doubles the user's Attack", s16 damage)
{
    enum Ability ability;
    u16 attack;
    PARAMETRIZE { ability = ABILITY_THICK_FAT;  attack = 100; }
    PARAMETRIZE { ability = ABILITY_THICK_FAT;  attack = 200; }
    PARAMETRIZE { ability = ABILITY_HUGE_POWER; attack = 100; }
    GIVEN {
        PLAYER(SPECIES_AZUMARILL) { Ability(ability); Attack(attack); Level(50); }
        OPPONENT(SPECIES_WOBBUFFET) { Defense(100); HP(1000); }
    } WHEN {
        TURN { MOVE(player, MOVE_SCRATCH); }
    } SCENE {
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_GT(results[1].damage, results[0].damage);
        EXPECT_EQ(results[1].damage, results[2].damage);
    }
}

SINGLE_BATTLE_TEST("Huge Power does not increase special damage", s16 damage)
{
    enum Ability ability;
    PARAMETRIZE { ability = ABILITY_THICK_FAT; }
    PARAMETRIZE { ability = ABILITY_HUGE_POWER; }
    GIVEN {
        PLAYER(SPECIES_AZUMARILL) { Ability(ability); SpAttack(200); Level(50); }
        OPPONENT(SPECIES_WOBBUFFET) { SpDefense(100); HP(1000); }
    } WHEN {
        TURN { MOVE(player, MOVE_WATER_GUN); }
    } SCENE {
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_EQ(results[0].damage, results[1].damage);
    }
}

SINGLE_BATTLE_TEST("Huge Power does not increase fixed damage", s16 damage)
{
    enum Ability ability;
    PARAMETRIZE { ability = ABILITY_THICK_FAT; }
    PARAMETRIZE { ability = ABILITY_HUGE_POWER; }
    GIVEN {
        PLAYER(SPECIES_AZUMARILL) { Ability(ability); Level(50); }
        OPPONENT(SPECIES_WOBBUFFET) { HP(1000); }
    } WHEN {
        TURN { MOVE(player, MOVE_SEISMIC_TOSS); }
    } SCENE {
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_EQ(results[0].damage, 50);
        EXPECT_EQ(results[1].damage, 50);
    }
}

SINGLE_BATTLE_TEST("Huge Power stops doubling Attack when suppressed", s16 damage)
{
    enum Ability ability;
    PARAMETRIZE { ability = ABILITY_THICK_FAT; }
    PARAMETRIZE { ability = ABILITY_HUGE_POWER; }
    GIVEN {
        PLAYER(SPECIES_AZUMARILL) { Ability(ability); Attack(200); Level(50); Speed(50); }
        OPPONENT(SPECIES_WOBBUFFET) { Defense(100); HP(1000); Speed(100); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_GASTRO_ACID); }
        TURN { MOVE(player, MOVE_SCRATCH); }
    } SCENE {
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_EQ(results[0].damage, results[1].damage);
    }
}

SINGLE_BATTLE_TEST("Huge Power stacks with Choice Band", s16 damage)
{
    enum Ability ability;
    enum Item item;
    u16 attack;
    PARAMETRIZE { ability = ABILITY_THICK_FAT;  item = ITEM_NONE;        attack = 300; }
    PARAMETRIZE { ability = ABILITY_HUGE_POWER; item = ITEM_CHOICE_BAND; attack = 100; }
    GIVEN {
        PLAYER(SPECIES_AZUMARILL) { Ability(ability); Item(item); Attack(attack); Level(50); }
        OPPONENT(SPECIES_WOBBUFFET) { Defense(100); HP(1000); }
    } WHEN {
        TURN { MOVE(player, MOVE_SCRATCH); }
    } SCENE {
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_EQ(results[0].damage, results[1].damage);
    }
}

SINGLE_BATTLE_TEST("Burn halves the Attack doubled by Huge Power", s16 damage)
{
    u32 status;
    PARAMETRIZE { status = STATUS1_NONE; }
    PARAMETRIZE { status = STATUS1_BURN; }
    GIVEN {
        PLAYER(SPECIES_AZUMARILL) { Ability(ABILITY_HUGE_POWER); Status1(status); Attack(200); Level(50); }
        OPPONENT(SPECIES_WOBBUFFET) { Defense(100); HP(1000); }
    } WHEN {
        TURN { MOVE(player, MOVE_SCRATCH); }
    } SCENE {
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_MUL_EQ(results[0].damage, UQ_4_12(0.5), results[1].damage);
    }
}
