#include "global.h"
#include "test/battle.h"

DOUBLE_BATTLE_TEST("Friend Guard reduces physical attack damage dealt to an ally by 25%", s16 damage)
{
    enum Ability ability;
    PARAMETRIZE { ability = ABILITY_FRIEND_GUARD; }
    PARAMETRIZE { ability = ABILITY_CUTE_CHARM; }
    GIVEN {
        ASSUME(GetMoveCategory(MOVE_SCRATCH) == DAMAGE_CATEGORY_PHYSICAL);
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_CLEFAIRY) { Ability(ability); }
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WYNAUT);
    } WHEN {
        TURN { MOVE(opponentLeft, MOVE_SCRATCH, target: playerLeft); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, opponentLeft);
        HP_BAR(playerLeft, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_MUL_EQ(results[1].damage, UQ_4_12(0.75), results[0].damage);
    }
}

DOUBLE_BATTLE_TEST("Friend Guard reduces special attack damage dealt to an ally by 25%", s16 damage)
{
    enum Ability ability;
    PARAMETRIZE { ability = ABILITY_FRIEND_GUARD; }
    PARAMETRIZE { ability = ABILITY_CUTE_CHARM; }
    GIVEN {
        ASSUME(GetMoveCategory(MOVE_WATER_GUN) == DAMAGE_CATEGORY_SPECIAL);
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_CLEFAIRY) { Ability(ability); }
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WYNAUT);
    } WHEN {
        TURN { MOVE(opponentLeft, MOVE_WATER_GUN, target: playerLeft); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_WATER_GUN, opponentLeft);
        HP_BAR(playerLeft, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_MUL_EQ(results[1].damage, UQ_4_12(0.75), results[0].damage);
    }
}

DOUBLE_BATTLE_TEST("Friend Guard reduces critical hit damage dealt to an ally", s16 damage)
{
    enum Ability ability;
    PARAMETRIZE { ability = ABILITY_FRIEND_GUARD; }
    PARAMETRIZE { ability = ABILITY_CUTE_CHARM; }
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_CLEFAIRY) { Ability(ability); }
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WYNAUT);
    } WHEN {
        TURN { MOVE(opponentLeft, MOVE_SCRATCH, target: playerLeft, WITH_RNG(RNG_CRITICAL_HIT, TRUE)); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, opponentLeft);
        HP_BAR(playerLeft, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_MUL_EQ(results[1].damage, UQ_4_12(0.75), results[0].damage);
    }
}

DOUBLE_BATTLE_TEST("Friend Guard reduces each hit of a multi-hit move dealt to an ally", s16 firstHit, s16 secondHit)
{
    enum Ability ability;
    PARAMETRIZE { ability = ABILITY_FRIEND_GUARD; }
    PARAMETRIZE { ability = ABILITY_CUTE_CHARM; }
    GIVEN {
        ASSUME(GetMoveStrikeCount(MOVE_DOUBLE_HIT) == 2);
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_CLEFAIRY) { Ability(ability); }
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WYNAUT);
    } WHEN {
        TURN { MOVE(opponentLeft, MOVE_DOUBLE_HIT, target: playerLeft); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_DOUBLE_HIT, opponentLeft);
        HP_BAR(playerLeft, captureDamage: &results[i].firstHit);
        HP_BAR(playerLeft, captureDamage: &results[i].secondHit);
    } FINALLY {
        EXPECT_MUL_EQ(results[1].firstHit, UQ_4_12(0.75), results[0].firstHit);
        EXPECT_MUL_EQ(results[1].secondHit, UQ_4_12(0.75), results[0].secondHit);
    }
}

DOUBLE_BATTLE_TEST("Friend Guard reduces spread move damage dealt to an ally", s16 damage)
{
    enum Ability ability;
    PARAMETRIZE { ability = ABILITY_FRIEND_GUARD; }
    PARAMETRIZE { ability = ABILITY_CUTE_CHARM; }
    GIVEN {
        ASSUME(GetMoveTarget(MOVE_ROCK_SLIDE) == TARGET_BOTH);
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_CLEFAIRY) { Ability(ability); }
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WYNAUT);
    } WHEN {
        TURN { MOVE(opponentLeft, MOVE_ROCK_SLIDE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_ROCK_SLIDE, opponentLeft);
        HP_BAR(playerLeft, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_MUL_EQ(results[1].damage, UQ_4_12(0.75), results[0].damage);
    }
}

DOUBLE_BATTLE_TEST("Friend Guard reduces damage dealt to an ally's Substitute", u16 damage)
{
    enum Ability ability;
    PARAMETRIZE { ability = ABILITY_FRIEND_GUARD; }
    PARAMETRIZE { ability = ABILITY_CUTE_CHARM; }
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_SUBSTITUTE) == EFFECT_SUBSTITUTE);
        PLAYER(SPECIES_WOBBUFFET) { Speed(4); }
        PLAYER(SPECIES_CLEFAIRY) { Ability(ability); Speed(1); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(3); }
        OPPONENT(SPECIES_WYNAUT) { Speed(1); }
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_SUBSTITUTE); MOVE(opponentLeft, MOVE_SCRATCH, target: playerLeft); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SUBSTITUTE, playerLeft);
        HP_BAR(playerLeft);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, opponentLeft);
        SUB_HIT(playerLeft, captureDamage: &results[i].damage);
        NOT HP_BAR(playerLeft);
    } FINALLY {
        EXPECT_MUL_EQ(results[1].damage, UQ_4_12(0.75), results[0].damage);
    }
}

DOUBLE_BATTLE_TEST("Friend Guard does not reduce damage dealt to its holder", s16 damage)
{
    enum Ability ability;
    PARAMETRIZE { ability = ABILITY_FRIEND_GUARD; }
    PARAMETRIZE { ability = ABILITY_CUTE_CHARM; }
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_CLEFAIRY) { Ability(ability); }
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WYNAUT);
    } WHEN {
        TURN { MOVE(opponentLeft, MOVE_SCRATCH, target: playerRight); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, opponentLeft);
        HP_BAR(playerRight, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_EQ(results[0].damage, results[1].damage);
    }
}

DOUBLE_BATTLE_TEST("Friend Guard remains active while its holder uses Protect", s16 damage)
{
    enum Ability ability;
    PARAMETRIZE { ability = ABILITY_FRIEND_GUARD; }
    PARAMETRIZE { ability = ABILITY_CUTE_CHARM; }
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_CLEFAIRY) { Ability(ability); }
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WYNAUT);
    } WHEN {
        TURN { MOVE(playerRight, MOVE_PROTECT); MOVE(opponentLeft, MOVE_SCRATCH, target: playerLeft); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_PROTECT, playerRight);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, opponentLeft);
        HP_BAR(playerLeft, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_MUL_EQ(results[1].damage, UQ_4_12(0.75), results[0].damage);
    }
}

DOUBLE_BATTLE_TEST("Friend Guard remains active while its holder is behind a Substitute", s16 damage)
{
    enum Ability ability;
    PARAMETRIZE { ability = ABILITY_FRIEND_GUARD; }
    PARAMETRIZE { ability = ABILITY_CUTE_CHARM; }
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_SUBSTITUTE) == EFFECT_SUBSTITUTE);
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_CLEFAIRY) { Ability(ability); }
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WYNAUT);
    } WHEN {
        TURN { MOVE(playerRight, MOVE_SUBSTITUTE); }
        TURN { MOVE(opponentLeft, MOVE_SCRATCH, target: playerLeft); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SUBSTITUTE, playerRight);
        HP_BAR(playerRight);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, opponentLeft);
        HP_BAR(playerLeft, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_MUL_EQ(results[1].damage, UQ_4_12(0.75), results[0].damage);
    }
}

DOUBLE_BATTLE_TEST("Friend Guard does not reduce an ally's confusion damage", s16 damage)
{
    enum Ability ability;
    PARAMETRIZE { ability = ABILITY_FRIEND_GUARD; }
    PARAMETRIZE { ability = ABILITY_CUTE_CHARM; }
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_CONFUSE_RAY) == EFFECT_CONFUSE);
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_CLEFAIRY) { Ability(ability); }
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WYNAUT);
    } WHEN {
        TURN { MOVE(opponentLeft, MOVE_CONFUSE_RAY, target: playerLeft); MOVE(playerLeft, MOVE_CELEBRATE, WITH_RNG(RNG_CONFUSION, TRUE)); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CONFUSE_RAY, opponentLeft);
        ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_CONFUSION, playerLeft);
        HP_BAR(playerLeft, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_EQ(results[0].damage, results[1].damage);
    }
}

DOUBLE_BATTLE_TEST("Friend Guard does not reduce poison damage dealt to an ally", s16 damage)
{
    enum Ability ability;
    PARAMETRIZE { ability = ABILITY_FRIEND_GUARD; }
    PARAMETRIZE { ability = ABILITY_CUTE_CHARM; }
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Status1(STATUS1_POISON); MaxHP(800); HP(800); }
        PLAYER(SPECIES_CLEFAIRY) { Ability(ability); }
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WYNAUT);
    } WHEN {
        TURN {}
    } SCENE {
        ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_PSN, playerLeft);
        HP_BAR(playerLeft, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_EQ(results[0].damage, results[1].damage);
    }
}

DOUBLE_BATTLE_TEST("Friend Guard does not reduce burn damage dealt to an ally", s16 damage)
{
    enum Ability ability;
    PARAMETRIZE { ability = ABILITY_FRIEND_GUARD; }
    PARAMETRIZE { ability = ABILITY_CUTE_CHARM; }
    GIVEN {
        WITH_CONFIG(B_BURN_DAMAGE, GEN_7);
        PLAYER(SPECIES_WOBBUFFET) { Status1(STATUS1_BURN); MaxHP(800); HP(800); }
        PLAYER(SPECIES_CLEFAIRY) { Ability(ability); }
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WYNAUT);
    } WHEN {
        TURN {}
    } SCENE {
        ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_BRN, playerLeft);
        HP_BAR(playerLeft, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_EQ(results[0].damage, results[1].damage);
    }
}
