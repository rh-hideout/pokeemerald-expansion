#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Marvel Scale boosts Defense while statused", s16 damage)
{
    enum Ability ability;
    PARAMETRIZE { ability = ABILITY_COMPETITIVE; }
    PARAMETRIZE { ability = ABILITY_MARVEL_SCALE; }
    GIVEN {
        PLAYER(SPECIES_MILOTIC) { Ability(ability); MaxHP(1000); HP(1000); Defense(100); SpDefense(100); Speed(100); Status1(STATUS1_POISON); }
        OPPONENT(SPECIES_WOBBUFFET) { Attack(200); SpAttack(200); Speed(50); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_SCRATCH); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, opponent);
        HP_BAR(player, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_MUL_EQ(results[1].damage, UQ_4_12(1.5), results[0].damage);
    }
}

SINGLE_BATTLE_TEST("Marvel Scale does not boost Special Defense", s16 damage)
{
    enum Ability ability;
    PARAMETRIZE { ability = ABILITY_COMPETITIVE; }
    PARAMETRIZE { ability = ABILITY_MARVEL_SCALE; }
    GIVEN {
        PLAYER(SPECIES_MILOTIC) { Ability(ability); MaxHP(1000); HP(1000); Defense(100); SpDefense(100); Speed(100); Status1(STATUS1_POISON); }
        OPPONENT(SPECIES_WOBBUFFET) { Attack(200); SpAttack(200); Speed(50); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_SWIFT); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SWIFT, opponent);
        HP_BAR(player, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_EQ(results[0].damage, results[1].damage);
    }
}

SINGLE_BATTLE_TEST("Marvel Scale does not reduce fixed damage", s16 damage)
{
    enum Ability ability;
    PARAMETRIZE { ability = ABILITY_COMPETITIVE; }
    PARAMETRIZE { ability = ABILITY_MARVEL_SCALE; }
    GIVEN {
        PLAYER(SPECIES_MILOTIC) { Ability(ability); MaxHP(1000); HP(1000); Defense(100); SpDefense(100); Speed(100); Status1(STATUS1_POISON); }
        OPPONENT(SPECIES_WOBBUFFET) { Attack(200); SpAttack(200); Speed(50); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_SONIC_BOOM); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SONIC_BOOM, opponent);
        HP_BAR(player, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_EQ(results[0].damage, results[1].damage);
        EXPECT_EQ(results[0].damage, 20);
    }
}

SINGLE_BATTLE_TEST("Marvel Scale activates immediately after Rest", s16 damage)
{
    enum Ability ability;
    PARAMETRIZE { ability = ABILITY_COMPETITIVE; }
    PARAMETRIZE { ability = ABILITY_MARVEL_SCALE; }
    GIVEN {
        PLAYER(SPECIES_MILOTIC) { Ability(ability); MaxHP(1000); HP(500); Defense(100); SpDefense(100); Speed(100); }
        OPPONENT(SPECIES_WOBBUFFET) { Attack(200); SpAttack(200); Speed(50); }
    } WHEN {
        TURN { MOVE(player, MOVE_REST); MOVE(opponent, MOVE_SCRATCH); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, opponent);
        HP_BAR(player, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_MUL_EQ(results[1].damage, UQ_4_12(1.5), results[0].damage);
    }
}

SINGLE_BATTLE_TEST("Marvel Scale stops boosting Defense when poison is cured", s16 damage)
{
    enum Ability ability;
    PARAMETRIZE { ability = ABILITY_COMPETITIVE; }
    PARAMETRIZE { ability = ABILITY_MARVEL_SCALE; }
    GIVEN {
        PLAYER(SPECIES_MILOTIC) { Ability(ability); MaxHP(1000); HP(1000); Defense(100); SpDefense(100); Speed(100); Status1(STATUS1_POISON); }
        OPPONENT(SPECIES_WOBBUFFET) { Attack(200); SpAttack(200); Speed(50); }
    } WHEN {
        TURN { MOVE(player, MOVE_HEAL_BELL); }
        TURN { MOVE(opponent, MOVE_SCRATCH); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, opponent);
        HP_BAR(player, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_EQ(results[0].damage, results[1].damage);
    }
}

SINGLE_BATTLE_TEST("Marvel Scale stops boosting Defense when suppressed", s16 damage)
{
    enum Ability ability;
    PARAMETRIZE { ability = ABILITY_COMPETITIVE; }
    PARAMETRIZE { ability = ABILITY_MARVEL_SCALE; }
    GIVEN {
        PLAYER(SPECIES_MILOTIC) { Ability(ability); MaxHP(1000); HP(1000); Defense(100); SpDefense(100); Speed(100); Status1(STATUS1_POISON); }
        OPPONENT(SPECIES_WOBBUFFET) { Attack(200); SpAttack(200); Speed(50); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_GASTRO_ACID); }
        TURN { MOVE(opponent, MOVE_SCRATCH); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, opponent);
        HP_BAR(player, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_EQ(results[0].damage, results[1].damage);
    }
}
