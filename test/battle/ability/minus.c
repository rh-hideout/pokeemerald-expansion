#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(GetMoveCategory(MOVE_WATER_GUN) == DAMAGE_CATEGORY_SPECIAL);
    ASSUME(GetMoveCategory(MOVE_SCRATCH) == DAMAGE_CATEGORY_PHYSICAL);
}

DOUBLE_BATTLE_TEST("Minus boosts special damage with a Plus or Minus ally", s16 damage)
{
    enum Ability ability;
    PARAMETRIZE { ability = ABILITY_CLEAR_BODY; }
    PARAMETRIZE { ability = ABILITY_PLUS; }
    PARAMETRIZE { ability = ABILITY_MINUS; }
    GIVEN {
        PLAYER(SPECIES_MINUN) { Ability(ABILITY_MINUS); SpAttack(200); Attack(200); Speed(100); }
        PLAYER(SPECIES_KLINK) { Ability(ability); Speed(90); }
        OPPONENT(SPECIES_WOBBUFFET) { HP(1000); SpDefense(100); Defense(100); Speed(80); }
        OPPONENT(SPECIES_WYNAUT) { Speed(70); }
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_WATER_GUN, target: opponentLeft); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_WATER_GUN, playerLeft);
        HP_BAR(opponentLeft, captureDamage: &results[i].damage);
    } THEN {
        EXPECT_EQ(playerLeft->statStages[STAT_SPATK], DEFAULT_STAT_STAGE);
    } FINALLY {
        EXPECT_MUL_EQ(results[0].damage, UQ_4_12(1.5), results[1].damage);
        EXPECT_MUL_EQ(results[0].damage, UQ_4_12(1.5), results[2].damage);
    }
}

DOUBLE_BATTLE_TEST("Minus does not boost physical damage", s16 damage)
{
    enum Ability ability;
    PARAMETRIZE { ability = ABILITY_CLEAR_BODY; }
    PARAMETRIZE { ability = ABILITY_PLUS; }
    PARAMETRIZE { ability = ABILITY_MINUS; }
    GIVEN {
        PLAYER(SPECIES_MINUN) { Ability(ABILITY_MINUS); SpAttack(200); Attack(200); Speed(100); }
        PLAYER(SPECIES_KLINK) { Ability(ability); Speed(90); }
        OPPONENT(SPECIES_WOBBUFFET) { HP(1000); SpDefense(100); Defense(100); Speed(80); }
        OPPONENT(SPECIES_WYNAUT) { Speed(70); }
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_SCRATCH, target: opponentLeft); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, playerLeft);
        HP_BAR(opponentLeft, captureDamage: &results[i].damage);
    } THEN {
        EXPECT_EQ(playerLeft->statStages[STAT_SPATK], DEFAULT_STAT_STAGE);
    } FINALLY {
        EXPECT_EQ(results[0].damage, results[1].damage);
        EXPECT_EQ(results[0].damage, results[2].damage);
    }
}

DOUBLE_BATTLE_TEST("Minus stops boosting damage when the user's ability is suppressed", s16 damage)
{
    enum Ability ability;
    PARAMETRIZE { ability = ABILITY_CLEAR_BODY; }
    PARAMETRIZE { ability = ABILITY_PLUS; }
    PARAMETRIZE { ability = ABILITY_MINUS; }
    GIVEN {
        PLAYER(SPECIES_MINUN) { Ability(ABILITY_MINUS); SpAttack(200); Attack(200); Speed(100); }
        PLAYER(SPECIES_KLINK) { Ability(ability); Speed(90); }
        OPPONENT(SPECIES_WOBBUFFET) { HP(1000); SpDefense(100); Defense(100); Speed(80); }
        OPPONENT(SPECIES_WYNAUT) { Speed(70); }
    } WHEN {
        TURN { MOVE(opponentLeft, MOVE_GASTRO_ACID, target: playerLeft); }
        TURN { MOVE(playerLeft, MOVE_WATER_GUN, target: opponentLeft); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_WATER_GUN, playerLeft);
        HP_BAR(opponentLeft, captureDamage: &results[i].damage);
    } THEN {
        EXPECT_EQ(playerLeft->statStages[STAT_SPATK], DEFAULT_STAT_STAGE);
    } FINALLY {
        EXPECT_EQ(results[0].damage, results[1].damage);
        EXPECT_EQ(results[0].damage, results[2].damage);
    }
}

DOUBLE_BATTLE_TEST("Minus stops boosting damage when the ally's ability is suppressed", s16 damage)
{
    enum Ability ability;
    PARAMETRIZE { ability = ABILITY_CLEAR_BODY; }
    PARAMETRIZE { ability = ABILITY_PLUS; }
    PARAMETRIZE { ability = ABILITY_MINUS; }
    GIVEN {
        PLAYER(SPECIES_MINUN) { Ability(ABILITY_MINUS); SpAttack(200); Attack(200); Speed(100); }
        PLAYER(SPECIES_KLINK) { Ability(ability); Speed(90); }
        OPPONENT(SPECIES_WOBBUFFET) { HP(1000); SpDefense(100); Defense(100); Speed(80); }
        OPPONENT(SPECIES_WYNAUT) { Speed(70); }
    } WHEN {
        TURN { MOVE(opponentLeft, MOVE_GASTRO_ACID, target: playerRight); }
        TURN { MOVE(playerLeft, MOVE_WATER_GUN, target: opponentLeft); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_WATER_GUN, playerLeft);
        HP_BAR(opponentLeft, captureDamage: &results[i].damage);
    } THEN {
        EXPECT_EQ(playerLeft->statStages[STAT_SPATK], DEFAULT_STAT_STAGE);
    } FINALLY {
        EXPECT_EQ(results[0].damage, results[1].damage);
        EXPECT_EQ(results[0].damage, results[2].damage);
    }
}

SINGLE_BATTLE_TEST("Minus is not activated by an opposing Plus or Minus Pokemon", s16 damage)
{
    enum Ability ability;
    PARAMETRIZE { ability = ABILITY_CLEAR_BODY; }
    PARAMETRIZE { ability = ABILITY_PLUS; }
    PARAMETRIZE { ability = ABILITY_MINUS; }
    GIVEN {
        PLAYER(SPECIES_MINUN) { Ability(ABILITY_MINUS); SpAttack(200); }
        OPPONENT(SPECIES_KLINK) { Ability(ability); HP(1000); SpDefense(100); }
    } WHEN {
        TURN { MOVE(player, MOVE_WATER_GUN); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_WATER_GUN, player);
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_EQ(results[0].damage, results[1].damage);
        EXPECT_EQ(results[0].damage, results[2].damage);
    }
}

SINGLE_BATTLE_TEST("Minus is not activated by a benched Plus or Minus Pokemon", s16 damage)
{
    enum Ability ability;
    PARAMETRIZE { ability = ABILITY_CLEAR_BODY; }
    PARAMETRIZE { ability = ABILITY_PLUS; }
    PARAMETRIZE { ability = ABILITY_MINUS; }
    GIVEN {
        PLAYER(SPECIES_MINUN) { Ability(ABILITY_MINUS); SpAttack(200); }
        PLAYER(SPECIES_KLINK) { Ability(ability); }
        OPPONENT(SPECIES_WOBBUFFET) { HP(1000); SpDefense(100); }
    } WHEN {
        TURN { MOVE(player, MOVE_WATER_GUN); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_WATER_GUN, player);
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_EQ(results[0].damage, results[1].damage);
        EXPECT_EQ(results[0].damage, results[2].damage);
    }
}

DOUBLE_BATTLE_TEST("Minus does not boost fixed damage", s16 damage)
{
    enum Ability ability;
    PARAMETRIZE { ability = ABILITY_CLEAR_BODY; }
    PARAMETRIZE { ability = ABILITY_PLUS; }
    PARAMETRIZE { ability = ABILITY_MINUS; }
    GIVEN {
        PLAYER(SPECIES_MINUN) { Ability(ABILITY_MINUS); }
        PLAYER(SPECIES_KLINK) { Ability(ability); }
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WYNAUT);
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_SONIC_BOOM, target: opponentLeft); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SONIC_BOOM, playerLeft);
        HP_BAR(opponentLeft, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_EQ(results[0].damage, 20);
        EXPECT_EQ(results[1].damage, 20);
        EXPECT_EQ(results[2].damage, 20);
    }
}
