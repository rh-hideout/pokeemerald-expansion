#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Reckless boosts physical recoil moves by 20%", s16 damage)
{
    enum Ability ability;
    enum Move move;
    PARAMETRIZE { move = MOVE_DOUBLE_EDGE; ability = ABILITY_INNER_FOCUS; }
    PARAMETRIZE { move = MOVE_DOUBLE_EDGE; ability = ABILITY_RECKLESS; }
    PARAMETRIZE { move = MOVE_BRAVE_BIRD; ability = ABILITY_INNER_FOCUS; }
    PARAMETRIZE { move = MOVE_BRAVE_BIRD; ability = ABILITY_RECKLESS; }
    PARAMETRIZE { move = MOVE_HEAD_SMASH; ability = ABILITY_INNER_FOCUS; }
    PARAMETRIZE { move = MOVE_HEAD_SMASH; ability = ABILITY_RECKLESS; }
    PARAMETRIZE { move = MOVE_WILD_CHARGE; ability = ABILITY_INNER_FOCUS; }
    PARAMETRIZE { move = MOVE_WILD_CHARGE; ability = ABILITY_RECKLESS; }
    PARAMETRIZE { move = MOVE_FLARE_BLITZ; ability = ABILITY_INNER_FOCUS; }
    PARAMETRIZE { move = MOVE_FLARE_BLITZ; ability = ABILITY_RECKLESS; }
    PARAMETRIZE { move = MOVE_WOOD_HAMMER; ability = ABILITY_INNER_FOCUS; }
    PARAMETRIZE { move = MOVE_WOOD_HAMMER; ability = ABILITY_RECKLESS; }
    GIVEN {
        PLAYER(SPECIES_MIENFOO) { Ability(ability); MaxHP(1000); HP(1000); Attack(200); SpAttack(200); Speed(100); }
        OPPONENT(SPECIES_WOBBUFFET) { HP(1000); Defense(100); SpDefense(100); Speed(50); }
    } WHEN {
        TURN { MOVE(player, move); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, move, player);
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        for (u32 j = 0; j < 12; j += 2)
            EXPECT_MUL_EQ(results[j].damage, UQ_4_12(1.2), results[j + 1].damage);
    }
}

SINGLE_BATTLE_TEST("Reckless boosts special recoil moves by 20%", s16 damage)
{
    enum Ability ability;
    enum Move move;
    PARAMETRIZE { move = MOVE_LIGHT_OF_RUIN; ability = ABILITY_INNER_FOCUS; }
    PARAMETRIZE { move = MOVE_LIGHT_OF_RUIN; ability = ABILITY_RECKLESS; }
    GIVEN {
        PLAYER(SPECIES_MIENFOO) { Ability(ability); MaxHP(1000); HP(1000); Attack(200); SpAttack(200); Speed(100); }
        OPPONENT(SPECIES_WOBBUFFET) { HP(1000); Defense(100); SpDefense(100); Speed(50); }
    } WHEN {
        TURN { MOVE(player, move); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, move, player);
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        for (u32 j = 0; j < 2; j += 2)
            EXPECT_MUL_EQ(results[j].damage, UQ_4_12(1.2), results[j + 1].damage);
    }
}

SINGLE_BATTLE_TEST("Reckless boosts crash moves by 20%", s16 damage)
{
    enum Ability ability;
    enum Move move;
    PARAMETRIZE { move = MOVE_JUMP_KICK; ability = ABILITY_INNER_FOCUS; }
    PARAMETRIZE { move = MOVE_JUMP_KICK; ability = ABILITY_RECKLESS; }
    PARAMETRIZE { move = MOVE_HIGH_JUMP_KICK; ability = ABILITY_INNER_FOCUS; }
    PARAMETRIZE { move = MOVE_HIGH_JUMP_KICK; ability = ABILITY_RECKLESS; }
    GIVEN {
        PLAYER(SPECIES_MIENFOO) { Ability(ability); MaxHP(1000); HP(1000); Attack(200); SpAttack(200); Speed(100); }
        OPPONENT(SPECIES_WOBBUFFET) { HP(1000); Defense(100); SpDefense(100); Speed(50); }
    } WHEN {
        TURN { MOVE(player, move); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, move, player);
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        for (u32 j = 0; j < 4; j += 2)
            EXPECT_MUL_EQ(results[j].damage, UQ_4_12(1.2), results[j + 1].damage);
    }
}

SINGLE_BATTLE_TEST("Reckless does not boost Struggle", s16 damage)
{
    enum Ability ability;
    enum Move move;
    PARAMETRIZE { move = MOVE_STRUGGLE; ability = ABILITY_INNER_FOCUS; }
    PARAMETRIZE { move = MOVE_STRUGGLE; ability = ABILITY_RECKLESS; }
    GIVEN {
        PLAYER(SPECIES_MIENFOO) { Ability(ability); MaxHP(1000); HP(1000); Attack(200); SpAttack(200); Speed(100); }
        OPPONENT(SPECIES_WOBBUFFET) { HP(1000); Defense(100); SpDefense(100); Speed(50); }
    } WHEN {
        TURN { MOVE(player, move); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, move, player);
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        for (u32 j = 0; j < 2; j += 2)
            EXPECT_EQ(results[j].damage, results[j + 1].damage);
    }
}

SINGLE_BATTLE_TEST("Reckless does not boost ordinary attacks", s16 damage)
{
    enum Ability ability;
    enum Move move;
    PARAMETRIZE { move = MOVE_SCRATCH; ability = ABILITY_INNER_FOCUS; }
    PARAMETRIZE { move = MOVE_SCRATCH; ability = ABILITY_RECKLESS; }
    PARAMETRIZE { move = MOVE_WATER_GUN; ability = ABILITY_INNER_FOCUS; }
    PARAMETRIZE { move = MOVE_WATER_GUN; ability = ABILITY_RECKLESS; }
    GIVEN {
        PLAYER(SPECIES_MIENFOO) { Ability(ability); MaxHP(1000); HP(1000); Attack(200); SpAttack(200); Speed(100); }
        OPPONENT(SPECIES_WOBBUFFET) { HP(1000); Defense(100); SpDefense(100); Speed(50); }
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

SINGLE_BATTLE_TEST("Reckless does not boost moves that spend the user's HP", s16 damage)
{
    enum Ability ability;
    enum Move move;
    PARAMETRIZE { move = MOVE_STEEL_BEAM; ability = ABILITY_INNER_FOCUS; }
    PARAMETRIZE { move = MOVE_STEEL_BEAM; ability = ABILITY_RECKLESS; }
    PARAMETRIZE { move = MOVE_MIND_BLOWN; ability = ABILITY_INNER_FOCUS; }
    PARAMETRIZE { move = MOVE_MIND_BLOWN; ability = ABILITY_RECKLESS; }
    GIVEN {
        PLAYER(SPECIES_MIENFOO) { Ability(ability); MaxHP(1000); HP(1000); Attack(200); SpAttack(200); Speed(100); }
        OPPONENT(SPECIES_WOBBUFFET) { HP(1000); Defense(100); SpDefense(100); Speed(50); }
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

SINGLE_BATTLE_TEST("Reckless stops boosting recoil moves when suppressed", s16 damage)
{
    enum Ability ability;
    enum Move move;
    PARAMETRIZE { move = MOVE_DOUBLE_EDGE; ability = ABILITY_INNER_FOCUS; }
    PARAMETRIZE { move = MOVE_DOUBLE_EDGE; ability = ABILITY_RECKLESS; }
    GIVEN {
        PLAYER(SPECIES_MIENFOO) { Ability(ability); MaxHP(1000); HP(1000); Attack(200); SpAttack(200); Speed(100); }
        OPPONENT(SPECIES_WOBBUFFET) { HP(1000); Defense(100); SpDefense(100); Speed(50); }
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
