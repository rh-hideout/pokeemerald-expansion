#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(GetMoveEffect(MOVE_FACADE) == EFFECT_FACADE);
}

SINGLE_BATTLE_TEST("Facade doubles in power when the user is paralyzed or poisoned", s16 damage)
{
    u32 status;

    PARAMETRIZE { status = STATUS1_NONE; }
    PARAMETRIZE { status = STATUS1_PARALYSIS; }
    PARAMETRIZE { status = STATUS1_POISON; }
    PARAMETRIZE { status = STATUS1_TOXIC_POISON; }

    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Status1(status); Attack(100); }
        OPPONENT(SPECIES_WOBBUFFET) { MaxHP(500); HP(500); Defense(100); }
    } WHEN {
        TURN { MOVE(player, MOVE_FACADE, WITH_RNG(RNG_PARALYSIS, FALSE)); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_FACADE, player);
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_MUL_EQ(results[0].damage, Q_4_12(2.0), results[1].damage);
        EXPECT_EQ(results[1].damage, results[2].damage);
        EXPECT_EQ(results[2].damage, results[3].damage);
    }
}

SINGLE_BATTLE_TEST("Facade stacks its boost with Guts when the user is burned", s16 damage)
{
    u32 status;

    PARAMETRIZE { status = STATUS1_NONE; }
    PARAMETRIZE { status = STATUS1_BURN; }

    GIVEN {
        WITH_CONFIG(B_BURN_FACADE_DMG, GEN_6);
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_GUTS); Status1(status); Attack(100); }
        OPPONENT(SPECIES_WOBBUFFET) { MaxHP(500); HP(500); Defense(100); }
    } WHEN {
        TURN { MOVE(player, MOVE_FACADE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_FACADE, player);
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_MUL_EQ(results[0].damage, Q_4_12(3.0), results[1].damage);
    }
}

SINGLE_BATTLE_TEST("Facade does not ignore burn's Attack reduction in Gen 3-5", s16 damage)
{
    u32 status;

    PARAMETRIZE { status = STATUS1_NONE; }
    PARAMETRIZE { status = STATUS1_BURN; }

    GIVEN {
        WITH_CONFIG(B_BURN_FACADE_DMG, GEN_5);
        PLAYER(SPECIES_WOBBUFFET) { Status1(status); Attack(100); }
        OPPONENT(SPECIES_WOBBUFFET) { MaxHP(500); HP(500); Defense(100); }
    } WHEN {
        TURN { MOVE(player, MOVE_FACADE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_FACADE, player);
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_LE(results[0].damage, results[1].damage + 1);
        EXPECT_LE(results[1].damage, results[0].damage + 1);
    }
}

SINGLE_BATTLE_TEST("Facade ignores burn's Attack reduction in Gen 6+", s16 damage)
{
    u32 status;

    PARAMETRIZE { status = STATUS1_NONE; }
    PARAMETRIZE { status = STATUS1_BURN; }

    GIVEN {
        WITH_CONFIG(B_BURN_FACADE_DMG, GEN_6);
        PLAYER(SPECIES_WOBBUFFET) { Status1(status); Attack(100); }
        OPPONENT(SPECIES_WOBBUFFET) { MaxHP(500); HP(500); Defense(100); }
    } WHEN {
        TURN { MOVE(player, MOVE_FACADE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_FACADE, player);
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_MUL_EQ(results[0].damage, Q_4_12(2.0), results[1].damage);
    }
}
