#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Tough Claws boosts physical and special contact moves", s16 damage)
{
    enum Ability ability;
    enum Move move;
    PARAMETRIZE { move = MOVE_SCRATCH; ability = ABILITY_SNIPER; }
    PARAMETRIZE { move = MOVE_SCRATCH; ability = ABILITY_TOUGH_CLAWS; }
    PARAMETRIZE { move = MOVE_DRAINING_KISS; ability = ABILITY_SNIPER; }
    PARAMETRIZE { move = MOVE_DRAINING_KISS; ability = ABILITY_TOUGH_CLAWS; }
    GIVEN {
        ASSUME(MoveMakesContact(move));
        PLAYER(SPECIES_BINACLE) { Ability(ability); Level(50); Attack(200); SpAttack(200); Speed(100); Item(ITEM_NONE); }
        OPPONENT(SPECIES_CHANSEY) { Ability(ABILITY_NATURAL_CURE); HP(1000); Defense(100); SpDefense(100); Speed(50); }
    } WHEN {
        TURN { MOVE(player, move); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, move, player);
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        for (u32 j = 0; j < 4; j += 2)
            EXPECT_MUL_EQ(results[j].damage, UQ_4_12(1.3), results[j + 1].damage);
    }
}

SINGLE_BATTLE_TEST("Tough Claws does not boost non-contact attacks", s16 damage)
{
    enum Ability ability;
    enum Move move;
    PARAMETRIZE { move = MOVE_ROCK_THROW; ability = ABILITY_SNIPER; }
    PARAMETRIZE { move = MOVE_ROCK_THROW; ability = ABILITY_TOUGH_CLAWS; }
    PARAMETRIZE { move = MOVE_WATER_GUN; ability = ABILITY_SNIPER; }
    PARAMETRIZE { move = MOVE_WATER_GUN; ability = ABILITY_TOUGH_CLAWS; }
    GIVEN {
        ASSUME(!MoveMakesContact(move));
        PLAYER(SPECIES_BINACLE) { Ability(ability); Level(50); Attack(200); SpAttack(200); Speed(100); Item(ITEM_NONE); }
        OPPONENT(SPECIES_CHANSEY) { Ability(ABILITY_NATURAL_CURE); HP(1000); Defense(100); SpDefense(100); Speed(50); }
    } WHEN {
        TURN { MOVE(player, move); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, move, player);
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        for (u32 j = 0; j < 4; j += 2)
            EXPECT_EQ(results[j].damage, results[j + 1].damage);
    }
}

SINGLE_BATTLE_TEST("Tough Claws still boosts non-punching contact moves with Punching Glove", s16 damage)
{
    enum Ability ability;
    enum Move move;
    PARAMETRIZE { move = MOVE_SCRATCH; ability = ABILITY_SNIPER; }
    PARAMETRIZE { move = MOVE_SCRATCH; ability = ABILITY_TOUGH_CLAWS; }
    GIVEN {
        ASSUME(MoveMakesContact(move));
        PLAYER(SPECIES_BINACLE) { Ability(ability); Level(50); Attack(200); SpAttack(200); Speed(100); Item(ITEM_PUNCHING_GLOVE); }
        OPPONENT(SPECIES_CHANSEY) { Ability(ABILITY_NATURAL_CURE); HP(1000); Defense(100); SpDefense(100); Speed(50); }
    } WHEN {
        TURN { MOVE(player, move); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, move, player);
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        for (u32 j = 0; j < 2; j += 2)
            EXPECT_MUL_EQ(results[j].damage, UQ_4_12(1.3), results[j + 1].damage);
    }
}

SINGLE_BATTLE_TEST("Tough Claws stops boosting contact moves when suppressed", s16 damage)
{
    enum Ability ability;
    enum Move move;
    PARAMETRIZE { move = MOVE_SCRATCH; ability = ABILITY_SNIPER; }
    PARAMETRIZE { move = MOVE_SCRATCH; ability = ABILITY_TOUGH_CLAWS; }
    GIVEN {
        ASSUME(MoveMakesContact(move));
        PLAYER(SPECIES_BINACLE) { Ability(ability); Level(50); Attack(200); SpAttack(200); Speed(100); Item(ITEM_NONE); }
        OPPONENT(SPECIES_CHANSEY) { Ability(ABILITY_NATURAL_CURE); HP(1000); Defense(100); SpDefense(100); Speed(50); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_GASTRO_ACID); }
        TURN { MOVE(player, move); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, move, player);
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        for (u32 j = 0; j < 2; j += 2)
            EXPECT_EQ(results[j].damage, results[j + 1].damage);
    }
}

SINGLE_BATTLE_TEST("Tough Claws does not increase fixed damage from contact moves", s16 damage)
{
    enum Ability ability;
    enum Move move;
    PARAMETRIZE { move = MOVE_SEISMIC_TOSS; ability = ABILITY_SNIPER; }
    PARAMETRIZE { move = MOVE_SEISMIC_TOSS; ability = ABILITY_TOUGH_CLAWS; }
    GIVEN {
        ASSUME(MoveMakesContact(move));
        PLAYER(SPECIES_BINACLE) { Ability(ability); Level(50); Attack(200); SpAttack(200); Speed(100); Item(ITEM_NONE); }
        OPPONENT(SPECIES_CHANSEY) { Ability(ABILITY_NATURAL_CURE); HP(1000); Defense(100); SpDefense(100); Speed(50); }
    } WHEN {
        TURN { MOVE(player, move); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, move, player);
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        for (u32 j = 0; j < 2; j += 2)
            EXPECT_EQ(results[j].damage, results[j + 1].damage);
        EXPECT_EQ(results[0].damage, 50);
    }
}

SINGLE_BATTLE_TEST("Tough Claws boosts contact moves when user has Protective Pads, but not with Punching Glove", s16 damage)
{
    enum Item item;

    PARAMETRIZE { item = ITEM_PROTECTIVE_PADS; }
    PARAMETRIZE { item = ITEM_PUNCHING_GLOVE; }

    GIVEN {
        ASSUME(MoveMakesContact(MOVE_MACH_PUNCH));
        ASSUME(IsPunchingMove(MOVE_MACH_PUNCH));
        ASSUME(GetItemHoldEffect(ITEM_PROTECTIVE_PADS) == HOLD_EFFECT_PROTECTIVE_PADS);
        ASSUME(GetItemHoldEffect(ITEM_PUNCHING_GLOVE) == HOLD_EFFECT_PUNCHING_GLOVE);
        PLAYER(SPECIES_BARBARACLE) { Ability(ABILITY_TOUGH_CLAWS); Item(item); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_MACH_PUNCH); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_MACH_PUNCH, player);
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_MUL_EQ(results[1].damage, UQ_4_12(1.18), results[0].damage); // 1.3 / 1.1 ~= 1.18
    }
}
