#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(GetMoveCategory(MOVE_SCRATCH) == DAMAGE_CATEGORY_PHYSICAL);
    ASSUME(GetMoveCategory(MOVE_WATER_GUN) == DAMAGE_CATEGORY_SPECIAL);
    ASSUME(GetMoveEffect(MOVE_SEISMIC_TOSS) == EFFECT_LEVEL_DAMAGE);
}

SINGLE_BATTLE_TEST("Multiscale halves physical damage at full HP", s16 damage)
{
    enum Ability ability;
    PARAMETRIZE { ability = ABILITY_INNER_FOCUS; }
    PARAMETRIZE { ability = ABILITY_MULTISCALE; }
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Attack(200); Level(50); }
        OPPONENT(SPECIES_DRAGONITE) { Ability(ability); Defense(100); MaxHP(1000); HP(1000); }
    } WHEN {
        TURN { MOVE(player, MOVE_SCRATCH); }
    } SCENE {
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_MUL_EQ(results[0].damage, UQ_4_12(0.5), results[1].damage);
    }
}

SINGLE_BATTLE_TEST("Multiscale halves special damage at full HP", s16 damage)
{
    enum Ability ability;
    PARAMETRIZE { ability = ABILITY_INNER_FOCUS; }
    PARAMETRIZE { ability = ABILITY_MULTISCALE; }
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { SpAttack(200); Level(50); }
        OPPONENT(SPECIES_DRAGONITE) { Ability(ability); SpDefense(100); MaxHP(1000); HP(1000); }
    } WHEN {
        TURN { MOVE(player, MOVE_WATER_GUN); }
    } SCENE {
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_MUL_EQ(results[0].damage, UQ_4_12(0.5), results[1].damage);
    }
}

SINGLE_BATTLE_TEST("Multiscale does not reduce damage below full HP", s16 damage)
{
    enum Ability ability;
    PARAMETRIZE { ability = ABILITY_INNER_FOCUS; }
    PARAMETRIZE { ability = ABILITY_MULTISCALE; }
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Attack(200); Level(50); }
        OPPONENT(SPECIES_DRAGONITE) { Ability(ability); Defense(100); MaxHP(1000); HP(999); }
    } WHEN {
        TURN { MOVE(player, MOVE_SCRATCH); }
    } SCENE {
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_EQ(results[0].damage, results[1].damage);
    }
}

SINGLE_BATTLE_TEST("Multiscale applies again after the user heals to full HP", s16 damage)
{
    enum Ability ability;
    PARAMETRIZE { ability = ABILITY_INNER_FOCUS; }
    PARAMETRIZE { ability = ABILITY_MULTISCALE; }
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Attack(200); Level(50); Speed(50); }
        OPPONENT(SPECIES_DRAGONITE) { Ability(ability); Defense(100); MaxHP(1000); HP(500); Speed(100); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_RECOVER); MOVE(player, MOVE_SCRATCH); }
    } SCENE {
        HP_BAR(opponent);
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_MUL_EQ(results[0].damage, UQ_4_12(0.5), results[1].damage);
    }
}

SINGLE_BATTLE_TEST("Multiscale only reduces the first strike of a multi-strike move", s16 damage[2])
{
    enum Ability ability;
    PARAMETRIZE { ability = ABILITY_INNER_FOCUS; }
    PARAMETRIZE { ability = ABILITY_MULTISCALE; }
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Attack(200); Level(50); }
        OPPONENT(SPECIES_DRAGONITE) { Ability(ability); Defense(100); MaxHP(1000); HP(1000); }
    } WHEN {
        TURN { MOVE(player, MOVE_COMET_PUNCH, WITH_RNG(RNG_HITS, 2)); }
    } SCENE {
        HP_BAR(opponent, captureDamage: &results[i].damage[0]);
        HP_BAR(opponent, captureDamage: &results[i].damage[1]);
    } FINALLY {
        EXPECT_MUL_EQ(results[0].damage[0], UQ_4_12(0.5), results[1].damage[0]);
        EXPECT_EQ(results[0].damage[1], results[1].damage[1]);
    }
}

SINGLE_BATTLE_TEST("Multiscale does not reduce fixed damage", s16 damage)
{
    enum Ability ability;
    PARAMETRIZE { ability = ABILITY_INNER_FOCUS; }
    PARAMETRIZE { ability = ABILITY_MULTISCALE; }
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Level(50); }
        OPPONENT(SPECIES_DRAGONITE) { Ability(ability); MaxHP(1000); HP(1000); }
    } WHEN {
        TURN { MOVE(player, MOVE_SEISMIC_TOSS); }
    } SCENE {
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_EQ(results[0].damage, 50);
        EXPECT_EQ(results[1].damage, 50);
    }
}

SINGLE_BATTLE_TEST("Multiscale does not reduce damage while suppressed", s16 damage)
{
    enum Ability ability;
    PARAMETRIZE { ability = ABILITY_INNER_FOCUS; }
    PARAMETRIZE { ability = ABILITY_MULTISCALE; }
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Attack(200); Level(50); Speed(100); }
        OPPONENT(SPECIES_DRAGONITE) { Ability(ability); Defense(100); MaxHP(1000); HP(1000); Speed(50); }
    } WHEN {
        TURN { MOVE(player, MOVE_GASTRO_ACID); }
        TURN { MOVE(player, MOVE_SCRATCH); }
    } SCENE {
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_EQ(results[0].damage, results[1].damage);
    }
}
