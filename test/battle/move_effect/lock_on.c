#include "global.h"
#include "test/battle.h"

TO_DO_BATTLE_TEST("TODO: Write Lock-On/Mind Reader (Move Effect) test titles")

SINGLE_BATTLE_TEST("Lock-On volatile allows to hit through semi-invulnerability")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_LOCK_ON); MOVE(opponent, MOVE_FLY); }
        TURN { MOVE(player, MOVE_POUND); SKIP_TURN(opponent); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_LOCK_ON, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_FLY, opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_POUND, player);
        HP_BAR(opponent); // Pound hit
    }
}

SINGLE_BATTLE_TEST("Lock-On skips the accuracy check for 2 turns")
{
    PASSES_RANDOMLY(10, 10, RNG_ACCURACY);
    GIVEN {
        ASSUME(GetMoveAccuracy(MOVE_SKY_UPPERCUT) == 90);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_LOCK_ON); }
        TURN { MOVE(player, MOVE_SKY_UPPERCUT); }
        TURN { MOVE(player, MOVE_SKY_UPPERCUT); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_LOCK_ON, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SKY_UPPERCUT, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SKY_UPPERCUT, player);
    } THEN {
        EXPECT_EQ(gBattleStruct->battlerState[B_BATTLER_0].lockOn[B_BATTLER_1], 0);
    }
}

DOUBLE_BATTLE_TEST("Lock-On: Multiple Pokemon can lock-in into a single target (Gen5+)")
{
    u32 config;
    PARAMETRIZE { config = GEN_4; }
    PARAMETRIZE { config = GEN_5; }

    GIVEN {
        WITH_CONFIG(B_LOCK_ON, config);
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN {
            MOVE(playerLeft, MOVE_LOCK_ON, target: opponentLeft);
            MOVE(playerRight, MOVE_LOCK_ON, target: opponentLeft);
        }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_LOCK_ON, playerLeft);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_LOCK_ON, playerRight);
    } THEN {
        if (config == GEN_5) {
            EXPECT_EQ(gBattleStruct->battlerState[B_BATTLER_0].lockOn[B_BATTLER_1], 2);
            EXPECT_EQ(gBattleStruct->battlerState[B_BATTLER_2].lockOn[B_BATTLER_1], 2);
        } else {
            EXPECT_EQ(gBattleStruct->battlerState[B_BATTLER_0].lockOn[B_BATTLER_1], 0);
            EXPECT_EQ(gBattleStruct->battlerState[B_BATTLER_2].lockOn[B_BATTLER_1], 2);
        }
    }
}

SINGLE_BATTLE_TEST("Lock-On: Batton Pass transfers Lock-On volatile")
{
    PASSES_RANDOMLY(10, 10, RNG_ACCURACY);
    GIVEN {
        ASSUME(GetMoveAccuracy(MOVE_SKY_UPPERCUT) == 90);
        ASSUME(GetMoveEffect(MOVE_BATON_PASS) == EFFECT_BATON_PASS);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WYNAUT);
    } WHEN {
        TURN { MOVE(player, MOVE_LOCK_ON); MOVE(opponent, MOVE_BATON_PASS); SEND_OUT(opponent, 1); }
        TURN { MOVE(player, MOVE_SKY_UPPERCUT); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_LOCK_ON, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_BATON_PASS, opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SKY_UPPERCUT, player);
    }
}

SINGLE_BATTLE_TEST("Lock-On: When locked in attacker faints, the volatile will be removed")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { HP(1); }
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_LOCK_ON); MOVE(opponent, MOVE_POUND); SEND_OUT(player, 1); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_LOCK_ON, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_POUND, opponent);
    } THEN {
        EXPECT_EQ(gBattleStruct->battlerState[B_BATTLER_0].lockOn[B_BATTLER_1], 0);
    }
}

SINGLE_BATTLE_TEST("Lock-On: When locked in target faints, the volatile will be removed")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET) { HP(1); }
        OPPONENT(SPECIES_WYNAUT);
    } WHEN {
        TURN { MOVE(player, MOVE_LOCK_ON); }
        TURN { MOVE(player, MOVE_POUND); SEND_OUT(opponent, 1); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_LOCK_ON, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_POUND, player);
    } THEN {
        EXPECT_EQ(gBattleStruct->battlerState[B_BATTLER_0].lockOn[B_BATTLER_1], 0);
    }
}

