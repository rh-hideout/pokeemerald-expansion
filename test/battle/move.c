#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Accuracy controls the proportion of misses")
{
    u32 move;
    PARAMETRIZE { move = MOVE_DYNAMIC_PUNCH; }
    PARAMETRIZE { move = MOVE_THUNDER; }
    PARAMETRIZE { move = MOVE_HYDRO_PUMP; }
    PARAMETRIZE { move = MOVE_RAZOR_LEAF; }
    PARAMETRIZE { move = MOVE_SCRATCH; }
    ASSUME(0 < gMovesInfo[move].accuracy && gMovesInfo[move].accuracy <= 100);
    PASSES_RANDOMLY(gMovesInfo[move].accuracy, 100, RNG_ACCURACY);
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, move); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, move, player);
    }
}

SINGLE_BATTLE_TEST("AdditionalEffect.chance controls the proportion of secondary effects")
{
    u32 move, chance;
    PARAMETRIZE { move = MOVE_THUNDER_SHOCK; chance = 10; }
    PARAMETRIZE { move = MOVE_DISCHARGE; chance = 30; }
    PARAMETRIZE { move = MOVE_NUZZLE; chance = 100; }
    ASSUME(MoveHasAdditionalEffect(move, MOVE_EFFECT_PARALYSIS) == TRUE);
    PASSES_RANDOMLY(chance, 100, RNG_SECONDARY_EFFECT);
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, move); }
    } SCENE {
        STATUS_ICON(opponent, paralysis: TRUE);
    }
}

SINGLE_BATTLE_TEST("Turn order is determined by priority")
{
    GIVEN {
        ASSUME(gMovesInfo[MOVE_QUICK_ATTACK].priority > gMovesInfo[MOVE_TACKLE].priority);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_QUICK_ATTACK); MOVE(opponent, MOVE_TACKLE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_QUICK_ATTACK, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_TACKLE, opponent);
    }
}

SINGLE_BATTLE_TEST("Turn order is determined by Speed if priority ties")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Speed(2); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(1); }
    } WHEN {
        TURN { MOVE(player, MOVE_QUICK_ATTACK); MOVE(opponent, MOVE_QUICK_ATTACK); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_QUICK_ATTACK, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_QUICK_ATTACK, opponent);
    }
}

SINGLE_BATTLE_TEST("Turn order is determined randomly if priority and Speed tie [singles]")
{
    PASSES_RANDOMLY(1, 2, RNG_SPEED_TIE);
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Speed(1); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(1); }
    } WHEN {
        TURN { MOVE(player, MOVE_QUICK_ATTACK); MOVE(opponent, MOVE_QUICK_ATTACK); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_QUICK_ATTACK, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_QUICK_ATTACK, opponent);
    }
}

DOUBLE_BATTLE_TEST("Turn order is determined randomly if priority and Speed tie [doubles]")
{
    u16 hpMon1, hpMon2;

    PASSES_RANDOMLY(1, 24, RNG_SPEED_TIE);

    ASSUME(gMovesInfo[MOVE_ENDEAVOR].effect == EFFECT_ENDEAVOR);
    ASSUME(gMovesInfo[MOVE_LIFE_DEW].effect == EFFECT_JUNGLE_HEALING);
    ASSUME(gMovesInfo[MOVE_CRUSH_GRIP].effect == EFFECT_VARY_POWER_BASED_ON_HP);
    ASSUME(gMovesInfo[MOVE_SUPER_FANG].effect == EFFECT_SUPER_FANG);
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { MaxHP(480); HP(360); Defense(100); Speed(1); }
        PLAYER(SPECIES_WYNAUT) { Speed(1); }
        OPPONENT(SPECIES_WOBBUFFET) { Attack(100); Speed(1); }
        OPPONENT(SPECIES_WYNAUT) { Speed(1); }
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_ENDEAVOR, target: opponentLeft); MOVE(playerRight, MOVE_LIFE_DEW); MOVE(opponentLeft, MOVE_CRUSH_GRIP, target: playerLeft, WITH_RNG(RNG_DAMAGE_MODIFIER, 0)); MOVE(opponentRight, MOVE_SUPER_FANG, target: playerLeft); }
    } THEN {
        hpMon1 = playerLeft->hp;
        hpMon2 = opponentLeft->hp;
        switch (hpMon1*1000+hpMon2)
        {
            case 188360:
                gBattleTestRunnerState->occurenceCounter += 1;
                break;
            case 189360:
                gBattleTestRunnerState->occurenceCounter += 2;
                break;
            case 261360:
                gBattleTestRunnerState->occurenceCounter += 4;
                break;
            case 235360:
                gBattleTestRunnerState->occurenceCounter += 8;
                break;
            case 262360:
                gBattleTestRunnerState->occurenceCounter += 16;
                break;
            case 202360:
                gBattleTestRunnerState->occurenceCounter += 32;
                break;
            case 189378:
                gBattleTestRunnerState->occurenceCounter += 64;
                break;
            case 189189:
                gBattleTestRunnerState->occurenceCounter += 128;
                break;
            case 189480:
                gBattleTestRunnerState->occurenceCounter += 256;
                break;
            case 188480:
                gBattleTestRunnerState->occurenceCounter += 512;
                break;
            case 188240:
                gBattleTestRunnerState->occurenceCounter += 1024;
                break;
            case 188188:
                gBattleTestRunnerState->occurenceCounter += 2048;
                break;
            case 262262:
                gBattleTestRunnerState->occurenceCounter += 4096;
                break;
            case 262142:
                gBattleTestRunnerState->occurenceCounter += 8192;
                break;
            case 202403:
                gBattleTestRunnerState->occurenceCounter += 16384;
                break;
            case 202202:
                gBattleTestRunnerState->occurenceCounter += 32768;
                break;
            case 262283:
                gBattleTestRunnerState->occurenceCounter += 65536;
                break;
            case 202283:
                gBattleTestRunnerState->occurenceCounter += 131072;
                break;
            case 235180:
                gBattleTestRunnerState->occurenceCounter += 262144;
                break;
            case 261180:
                gBattleTestRunnerState->occurenceCounter += 524288;
                break;
            case 235235:
                gBattleTestRunnerState->occurenceCounter += 1048576;
                break;
            case 235300:
                gBattleTestRunnerState->occurenceCounter += 2097152;
                break;
            case 261141:
                gBattleTestRunnerState->occurenceCounter += 4194304;
                break;
            case 261261:
                gBattleTestRunnerState->occurenceCounter += 8388608;
                break;
        }
        EXPECT_EQ(gBattleTestRunnerState->occurenceCounter, 16777215);
        //  Any of the following pairs of hp values work:
        //  (188, 360), (189, 360), (261, 360), (235, 360), (262, 360), (202, 360),
        //  (189, 378), (189, 189), (189, 480), (188, 480), (188, 240), (188, 188),
        //  (262, 262), (262, 142), (202, 403), (202, 202), (262, 283), (202, 283),
        //  (235, 180), (261, 180), (235, 235), (235, 300), (261, 141), (261, 261)
    }
}

SINGLE_BATTLE_TEST("Critical hits occur at a 1/24 rate")
{
    ASSUME(B_CRIT_CHANCE >= GEN_7);
    PASSES_RANDOMLY(1, 24, RNG_CRITICAL_HIT);
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_SCRATCH); }
    } SCENE {
        MESSAGE("A critical hit!");
    }
}

SINGLE_BATTLE_TEST("Slash's critical hits occur at a 1/8 rate")
{
    ASSUME(B_CRIT_CHANCE >= GEN_7);
    ASSUME(gMovesInfo[MOVE_SLASH].criticalHitStage == 1);
    PASSES_RANDOMLY(1, 8, RNG_CRITICAL_HIT);
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_SLASH); }
    } SCENE {
        MESSAGE("A critical hit!");
    }
}

SINGLE_BATTLE_TEST("Critical hits deal 50% more damage", s16 damage)
{
    bool32 criticalHit;
    PARAMETRIZE { criticalHit = FALSE; }
    PARAMETRIZE { criticalHit = TRUE; }
    GIVEN {
        ASSUME(B_CRIT_MULTIPLIER >= GEN_6);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_SCRATCH, criticalHit: criticalHit); }
    } SCENE {
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_MUL_EQ(results[0].damage, Q_4_12(1.5), results[1].damage);
    }
}

SINGLE_BATTLE_TEST("Critical hits do not ignore positive stat stages", s16 damage)
{
    u32 move;
    PARAMETRIZE { move = MOVE_CELEBRATE; }
    PARAMETRIZE { move = MOVE_HOWL; }
    PARAMETRIZE { move = MOVE_TAIL_WHIP; }
    GIVEN {
        ASSUME(gMovesInfo[MOVE_SCRATCH].category == DAMAGE_CATEGORY_PHYSICAL);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, move); }
        TURN { MOVE(player, MOVE_SCRATCH, criticalHit: TRUE); }
    } SCENE {
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } THEN {
        if (i > 0)
            EXPECT_LT(results[0].damage, results[i].damage);
    }
}

SINGLE_BATTLE_TEST("Critical hits ignore negative stat stages", s16 damage)
{
    u32 move;
    PARAMETRIZE { move = MOVE_CELEBRATE; }
    PARAMETRIZE { move = MOVE_HARDEN; }
    PARAMETRIZE { move = MOVE_GROWL; }
    GIVEN {
        ASSUME(gMovesInfo[MOVE_SCRATCH].category == DAMAGE_CATEGORY_PHYSICAL);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, move); }
        TURN { MOVE(player, MOVE_SCRATCH, criticalHit: TRUE); }
    } SCENE {
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } THEN {
        if (i > 0)
            EXPECT_EQ(results[0].damage, results[i].damage);
    }
}
