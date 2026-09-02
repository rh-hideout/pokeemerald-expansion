#include "global.h"
#include "test/battle.h"
#include "battle_ai_main.h"
#include "battle_stat_change.h"

ASSUMPTIONS
{
    // MOVE_SONIC_BOOM
    ASSUME(GetMoveEffect(MOVE_SONIC_BOOM) == EFFECT_FIXED_HP_DAMAGE);
    ASSUME(GetMoveType(MOVE_SONIC_BOOM) == TYPE_NORMAL);

    // MOVE_SAND_ATTACK
    ASSUME(GetMoveEffect(MOVE_SAND_ATTACK) == EFFECT_STAT_CHANGE);
    ASSUME(GetMoveAdditionalEffectById(MOVE_SAND_ATTACK, 0)->moveEffect == STAT_CHANGE_EFFECT_MINUS);
    ASSUME(GetStatStage(STAT_ACC, GetMoveAdditionalEffectById(MOVE_SAND_ATTACK, 0)) == 1);

    // MOVE_DOUBLE_TEAM
    ASSUME(GetMoveEffect(MOVE_DOUBLE_TEAM) == EFFECT_STAT_CHANGE);
    ASSUME(GetMoveAdditionalEffectById(MOVE_DOUBLE_TEAM, 0)->moveEffect == STAT_CHANGE_EFFECT_PLUS);
    ASSUME(GetStatStage(STAT_EVASION, GetMoveAdditionalEffectById(MOVE_DOUBLE_TEAM, 0)) == 1);

    // MOVE_MINIMIZE
    ASSUME(GetMoveEffect(MOVE_MINIMIZE) == EFFECT_MINIMIZE);
    ASSUME(GetMoveAdditionalEffectById(MOVE_MINIMIZE, 0)->moveEffect == STAT_CHANGE_EFFECT_PLUS);
    ASSUME(GetStatStage(STAT_EVASION, GetMoveAdditionalEffectById(MOVE_MINIMIZE, 0)) > 0);

    // MOVE_THUNDER
    ASSUME(GetMoveEffect(MOVE_THUNDER) == EFFECT_HIT);
    ASSUME(GetMoveCategory(MOVE_THUNDER) == DAMAGE_CATEGORY_SPECIAL);
    ASSUME(GetMovePower(MOVE_THUNDER) == (B_UPDATED_MOVE_DATA >= GEN_6 ? 110 : 120));
    ASSUME(GetMoveAccuracy(MOVE_THUNDER) == 70);

    // MOVE_ZAP_CANNON
    ASSUME(GetMoveEffect(MOVE_ZAP_CANNON) == EFFECT_HIT);
    ASSUME(GetMoveCategory(MOVE_ZAP_CANNON) == DAMAGE_CATEGORY_SPECIAL);
    ASSUME(GetMovePower(MOVE_ZAP_CANNON) == (B_UPDATED_MOVE_DATA >= GEN_4 ? 120 : 100));
    ASSUME(GetMoveAccuracy(MOVE_ZAP_CANNON) == 50);
}


AI_SINGLE_BATTLE_TEST("AI_FLAG_CONSIDER_STAT_CHANGES: AI will raise its accuracy if it increases its odds of winning (User Accuracy +1)")
{
    GIVEN
    {
        AI_FLAGS(AI_FLAG_SMART_TRAINER | AI_FLAG_CONSIDER_STAT_CHANGES);
        PLAYER(SPECIES_WOBBUFFET) {
            Speed(4);
            MaxHP(450);
            HP(450);
            Attack(71);
            Defense(134);
            SpAttack(71);
            SpDefense(123);
            Moves(MOVE_THUNDER);
        }
        OPPONENT(SPECIES_WOBBUFFET) {
            Speed(5);
            MaxHP(500);
            HP(400);
            Attack(71);
            Defense(134);
            SpAttack(71);
            SpDefense(123);
            Moves(MOVE_HONE_CLAWS, MOVE_THUNDER);
        }
        WITH_CONFIG(B_UPDATED_MOVE_DATA, GEN_6);
    } WHEN {
        TURN {
            EXPECT_MOVE(opponent, MOVE_HONE_CLAWS);
            SCORE_EQ_VAL(opponent, MOVE_HONE_CLAWS, AI_SCORE_DEFAULT + GOOD_EFFECT);
            SCORE_EQ_VAL(opponent, MOVE_THUNDER, AI_SCORE_DEFAULT + BEST_DAMAGE_MOVE);
        }
        TURN { 
            EXPECT_MOVE(opponent, MOVE_THUNDER);
            SCORE_EQ_VAL(opponent, MOVE_HONE_CLAWS, AI_SCORE_DEFAULT + NO_DAMAGE_OR_FAILS);
            SCORE_EQ_VAL(opponent, MOVE_THUNDER, AI_SCORE_DEFAULT + BEST_DAMAGE_MOVE);
        }
    }
}

AI_SINGLE_BATTLE_TEST("AI_FLAG_CONSIDER_STAT_CHANGES: AI will raise its accuracy if it increases its odds of winning (User Accuracy Simple +2)")
{
    GIVEN
    {
        AI_FLAGS(AI_FLAG_SMART_TRAINER | AI_FLAG_CONSIDER_STAT_CHANGES);
        PLAYER(SPECIES_WOBBUFFET) {
            Speed(4);
            MaxHP(500);
            HP(400);
            Attack(71);
            Defense(134);
            SpAttack(71);
            SpDefense(134);
            Moves(MOVE_ZAP_CANNON);
        }
        OPPONENT(SPECIES_BIDOOF) {
            Speed(5);
            MaxHP(500);
            HP(300);
            Attack(71);
            Defense(134);
            SpAttack(71);
            SpDefense(134);
            Moves(MOVE_HONE_CLAWS, MOVE_ZAP_CANNON);
            Ability(ABILITY_SIMPLE);
        }
        WITH_CONFIG(B_UPDATED_MOVE_DATA, GEN_6);
    } WHEN {
        TURN {
            EXPECT_MOVE(opponent, MOVE_HONE_CLAWS);
            SCORE_EQ_VAL(opponent, MOVE_HONE_CLAWS, AI_SCORE_DEFAULT + GOOD_EFFECT);
            SCORE_EQ_VAL(opponent, MOVE_ZAP_CANNON, AI_SCORE_DEFAULT + BEST_DAMAGE_MOVE);
        }
        TURN { 
            EXPECT_MOVE(opponent, MOVE_ZAP_CANNON);
            SCORE_EQ_VAL(opponent, MOVE_HONE_CLAWS, AI_SCORE_DEFAULT + NO_DAMAGE_OR_FAILS);
            SCORE_EQ_VAL(opponent, MOVE_ZAP_CANNON, AI_SCORE_DEFAULT + BEST_DAMAGE_MOVE);
        }
    }
}

AI_SINGLE_BATTLE_TEST("AI_FLAG_CONSIDER_STAT_CHANGES: AI will lower target accuracy if it increases its odds of winning (Target Accuracy -1)")
{
    GIVEN
    {
        AI_FLAGS(AI_FLAG_SMART_TRAINER | AI_FLAG_CONSIDER_STAT_CHANGES);
        PLAYER(SPECIES_WOBBUFFET) { Speed(4); MaxHP (200); HP(200); Moves(MOVE_SONIC_BOOM); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(5); MaxHP (200); HP(180); Moves(MOVE_SAND_ATTACK, MOVE_SONIC_BOOM); }
    } WHEN {
        TURN {
            EXPECT_MOVE(opponent, MOVE_SAND_ATTACK);
            SCORE_EQ_VAL(opponent, MOVE_SAND_ATTACK, AI_SCORE_DEFAULT + GOOD_EFFECT);
            SCORE_EQ_VAL(opponent, MOVE_SONIC_BOOM, AI_SCORE_DEFAULT + BEST_DAMAGE_MOVE);
        }
        TURN { 
            EXPECT_MOVE(opponent, MOVE_SONIC_BOOM);
            SCORE_EQ_VAL(opponent, MOVE_SAND_ATTACK, AI_SCORE_DEFAULT + NO_DAMAGE_OR_FAILS);
            SCORE_EQ_VAL(opponent, MOVE_SONIC_BOOM, AI_SCORE_DEFAULT + BEST_DAMAGE_MOVE);
        }
    }
}

AI_SINGLE_BATTLE_TEST("AI_FLAG_CONSIDER_STAT_CHANGES: AI with Contrary will not incorrectly lower its accuracy to increases its odds of winning (User Accuracy Contrary -1)")
{
    GIVEN
    {
        AI_FLAGS(AI_FLAG_SMART_TRAINER | AI_FLAG_CONSIDER_STAT_CHANGES);
        PLAYER(SPECIES_WOBBUFFET) { Speed(4); MaxHP (200); HP(200); Moves(MOVE_SONIC_BOOM); }
        OPPONENT(SPECIES_SERPERIOR) { Speed(5); MaxHP (200); HP(180); Moves(MOVE_COIL, MOVE_SONIC_BOOM); Ability(ABILITY_CONTRARY); }
    } WHEN {
        TURN {
            EXPECT_MOVE(opponent, MOVE_SONIC_BOOM);
            SCORE_EQ_VAL(opponent, MOVE_COIL, AI_SCORE_DEFAULT + NO_DAMAGE_OR_FAILS);
            SCORE_EQ_VAL(opponent, MOVE_SONIC_BOOM, AI_SCORE_DEFAULT + BEST_DAMAGE_MOVE);
        }
        TURN { 
            EXPECT_MOVE(opponent, MOVE_SONIC_BOOM);
            SCORE_EQ_VAL(opponent, MOVE_COIL, AI_SCORE_DEFAULT + NO_DAMAGE_OR_FAILS);
            SCORE_EQ_VAL(opponent, MOVE_SONIC_BOOM, AI_SCORE_DEFAULT + BEST_DAMAGE_MOVE);
        }
    }
}

AI_SINGLE_BATTLE_TEST("AI_FLAG_CONSIDER_STAT_CHANGES: AI will lower target accuracy if it increases its odds of winning (Target Accuracy Simple -2)")
{
    GIVEN
    {
        AI_FLAGS(AI_FLAG_SMART_TRAINER | AI_FLAG_CONSIDER_STAT_CHANGES);
        PLAYER(SPECIES_BIBAREL) { Speed(4); MaxHP (200); HP(200); Moves(MOVE_SONIC_BOOM); Ability(ABILITY_SIMPLE); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(5); MaxHP (200); HP(150); Moves(MOVE_SAND_ATTACK, MOVE_SONIC_BOOM); }
    } WHEN {
        TURN {
            EXPECT_MOVE(opponent, MOVE_SAND_ATTACK);
            SCORE_EQ_VAL(opponent, MOVE_SAND_ATTACK, AI_SCORE_DEFAULT + GOOD_EFFECT);
            SCORE_EQ_VAL(opponent, MOVE_SONIC_BOOM, AI_SCORE_DEFAULT + BEST_DAMAGE_MOVE);
        }
        TURN { 
            EXPECT_MOVE(opponent, MOVE_SONIC_BOOM);
            SCORE_EQ_VAL(opponent, MOVE_SAND_ATTACK, AI_SCORE_DEFAULT + NO_DAMAGE_OR_FAILS);
            SCORE_EQ_VAL(opponent, MOVE_SONIC_BOOM, AI_SCORE_DEFAULT + BEST_DAMAGE_MOVE);
        }
    }
}

AI_SINGLE_BATTLE_TEST("AI_FLAG_CONSIDER_STAT_CHANGES: AI will increase its evasion if it increases its odds of winning (User Evasion +1)")
{
    GIVEN
    {
        AI_FLAGS(AI_FLAG_SMART_TRAINER | AI_FLAG_CONSIDER_STAT_CHANGES);
        PLAYER(SPECIES_WOBBUFFET) { Speed(4); MaxHP (200); HP(200); Moves(MOVE_SONIC_BOOM); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(5); MaxHP (200); HP(180); Moves(MOVE_DOUBLE_TEAM, MOVE_SONIC_BOOM); }
    } WHEN {
        TURN {
            EXPECT_MOVE(opponent, MOVE_DOUBLE_TEAM);
            SCORE_EQ_VAL(opponent, MOVE_DOUBLE_TEAM, AI_SCORE_DEFAULT + GOOD_EFFECT);
            SCORE_EQ_VAL(opponent, MOVE_SONIC_BOOM, AI_SCORE_DEFAULT + BEST_DAMAGE_MOVE);
        }
        TURN { 
            EXPECT_MOVE(opponent, MOVE_SONIC_BOOM);
            SCORE_EQ_VAL(opponent, MOVE_DOUBLE_TEAM, AI_SCORE_DEFAULT + NO_DAMAGE_OR_FAILS);
            SCORE_EQ_VAL(opponent, MOVE_SONIC_BOOM, AI_SCORE_DEFAULT + BEST_DAMAGE_MOVE);
        }
    }
}

AI_SINGLE_BATTLE_TEST("AI_FLAG_CONSIDER_STAT_CHANGES: AI will increase its evasion if it increases its odds of winning (User Evasion +2)")
{
    GIVEN
    {
        AI_FLAGS(AI_FLAG_SMART_TRAINER | AI_FLAG_CONSIDER_STAT_CHANGES);
        PLAYER(SPECIES_WOBBUFFET) { Speed(4); MaxHP (200); HP(200); Moves(MOVE_SONIC_BOOM); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(5); MaxHP (200); HP(150); Moves(MOVE_MINIMIZE, MOVE_SONIC_BOOM); }
    } WHEN {
        TURN {
            EXPECT_MOVE(opponent, MOVE_MINIMIZE);
            SCORE_EQ_VAL(opponent, MOVE_MINIMIZE, AI_SCORE_DEFAULT + GOOD_EFFECT);
            SCORE_EQ_VAL(opponent, MOVE_SONIC_BOOM, AI_SCORE_DEFAULT + BEST_DAMAGE_MOVE);
        }
        TURN { 
            EXPECT_MOVE(opponent, MOVE_SONIC_BOOM);
            SCORE_EQ_VAL(opponent, MOVE_MINIMIZE, AI_SCORE_DEFAULT + NO_DAMAGE_OR_FAILS);
            SCORE_EQ_VAL(opponent, MOVE_SONIC_BOOM, AI_SCORE_DEFAULT + BEST_DAMAGE_MOVE);
        }
    }
}

AI_SINGLE_BATTLE_TEST("AI_FLAG_CONSIDER_STAT_CHANGES: AI will increase its evasion if it increases its odds of winning (User Evasion Simple +4 (Gen 5+))")
{
    GIVEN
    {
        AI_FLAGS(AI_FLAG_SMART_TRAINER | AI_FLAG_CONSIDER_STAT_CHANGES);
        PLAYER(SPECIES_WOBBUFFET) { Speed(4); MaxHP (200); HP(200); Moves(MOVE_SONIC_BOOM); }
        OPPONENT(SPECIES_BIBAREL) { Speed(5); MaxHP (200); HP(100); Moves(MOVE_MINIMIZE, MOVE_SONIC_BOOM); Ability(ABILITY_SIMPLE); }
        WITH_CONFIG(B_MINIMIZE_EVASION, GEN_5);
    } WHEN {
        TURN {
            EXPECT_MOVE(opponent, MOVE_MINIMIZE);
            SCORE_EQ_VAL(opponent, MOVE_MINIMIZE, AI_SCORE_DEFAULT + GOOD_EFFECT);
            SCORE_EQ_VAL(opponent, MOVE_SONIC_BOOM, AI_SCORE_DEFAULT + BEST_DAMAGE_MOVE);
        }
        TURN { 
            EXPECT_MOVE(opponent, MOVE_SONIC_BOOM);
            SCORE_EQ_VAL(opponent, MOVE_MINIMIZE, AI_SCORE_DEFAULT + NO_DAMAGE_OR_FAILS);
            SCORE_EQ_VAL(opponent, MOVE_SONIC_BOOM, AI_SCORE_DEFAULT + BEST_DAMAGE_MOVE);
        }
    }
}

AI_SINGLE_BATTLE_TEST("AI_FLAG_CONSIDER_STAT_CHANGES: AI will lower target evasion if it increases its odds of winning (Target Evasion -1)")
{
    GIVEN
    {
        AI_FLAGS(AI_FLAG_SMART_TRAINER | AI_FLAG_CONSIDER_STAT_CHANGES);
        PLAYER(SPECIES_WOBBUFFET) {
            Speed(4);
            MaxHP(450);
            HP(450);
            Attack(71);
            Defense(134);
            SpAttack(71);
            SpDefense(123);
            Moves(MOVE_SONIC_BOOM);
        }
        OPPONENT(SPECIES_WOBBUFFET) {
            Speed(5);
            MaxHP(180);
            HP(180);
            SpAttack(71);
            Moves(MOVE_SWEET_SCENT, MOVE_THUNDER);
        }
        WITH_CONFIG(B_UPDATED_MOVE_DATA, GEN_5);
    } WHEN {
        TURN {
            EXPECT_MOVE(opponent, MOVE_SWEET_SCENT);
            SCORE_EQ_VAL(opponent, MOVE_SWEET_SCENT, AI_SCORE_DEFAULT + GOOD_EFFECT);
            SCORE_EQ_VAL(opponent, MOVE_THUNDER, AI_SCORE_DEFAULT + BEST_DAMAGE_MOVE);
        }
        TURN { 
            EXPECT_MOVE(opponent, MOVE_THUNDER);
            SCORE_EQ_VAL(opponent, MOVE_SWEET_SCENT, AI_SCORE_DEFAULT + NO_DAMAGE_OR_FAILS);
            SCORE_EQ_VAL(opponent, MOVE_THUNDER, AI_SCORE_DEFAULT + BEST_DAMAGE_MOVE);
        }
    }
}

AI_SINGLE_BATTLE_TEST("AI_FLAG_CONSIDER_STAT_CHANGES: AI will lower target evasion if it increases its odds of winning (Target Evasion -2)")
{
    GIVEN
    {
        AI_FLAGS(AI_FLAG_SMART_TRAINER | AI_FLAG_CONSIDER_STAT_CHANGES);
        PLAYER(SPECIES_WOBBUFFET) {
            Speed(4);
            MaxHP(500);
            HP(400);
            Attack(71);
            Defense(134);
            SpAttack(71);
            SpDefense(134);
            Moves(MOVE_SONIC_BOOM);
        }
        OPPONENT(SPECIES_WOBBUFFET) {
            Speed(5);
            MaxHP(200);
            HP(200);
            SpAttack(71);
            Moves(MOVE_SWEET_SCENT, MOVE_ZAP_CANNON);
        }
        WITH_CONFIG(B_UPDATED_MOVE_DATA, GEN_6);
    } WHEN {
        TURN {
            EXPECT_MOVE(opponent, MOVE_SWEET_SCENT);
            SCORE_EQ_VAL(opponent, MOVE_SWEET_SCENT, AI_SCORE_DEFAULT + GOOD_EFFECT);
            SCORE_EQ_VAL(opponent, MOVE_ZAP_CANNON, AI_SCORE_DEFAULT + BEST_DAMAGE_MOVE);
        }
        TURN { 
            EXPECT_MOVE(opponent, MOVE_ZAP_CANNON);
            SCORE_EQ_VAL(opponent, MOVE_SWEET_SCENT, AI_SCORE_DEFAULT + NO_DAMAGE_OR_FAILS);
            SCORE_EQ_VAL(opponent, MOVE_ZAP_CANNON, AI_SCORE_DEFAULT + BEST_DAMAGE_MOVE);
        }
    }
}

AI_SINGLE_BATTLE_TEST("AI_FLAG_CONSIDER_STAT_CHANGES: AI will lower target evasion if it increases its odds of winning (Target Evasion Simple -4)")
{
    GIVEN
    {
        AI_FLAGS(AI_FLAG_SMART_TRAINER | AI_FLAG_CONSIDER_STAT_CHANGES);
        PLAYER(SPECIES_BIDOOF) {
            Speed(4);
            MaxHP(500);
            HP(400);
            Attack(71);
            Defense(134);
            SpAttack(71);
            SpDefense(134);
            Moves(MOVE_SONIC_BOOM);
            Ability(ABILITY_SIMPLE);
        }
        OPPONENT(SPECIES_WOBBUFFET) {
            Speed(5);
            MaxHP(160);
            HP(160);
            SpAttack(71);
            Moves(MOVE_SWEET_SCENT, MOVE_ZAP_CANNON);
        }
        WITH_CONFIG(B_UPDATED_MOVE_DATA, GEN_6);
    } WHEN {
        TURN {
            EXPECT_MOVE(opponent, MOVE_SWEET_SCENT);
            SCORE_EQ_VAL(opponent, MOVE_SWEET_SCENT, AI_SCORE_DEFAULT + GOOD_EFFECT);
            SCORE_EQ_VAL(opponent, MOVE_ZAP_CANNON, AI_SCORE_DEFAULT + BEST_DAMAGE_MOVE);
        }
        TURN { 
            EXPECT_MOVE(opponent, MOVE_ZAP_CANNON);
            SCORE_EQ_VAL(opponent, MOVE_SWEET_SCENT, AI_SCORE_DEFAULT + NO_DAMAGE_OR_FAILS);
            SCORE_EQ_VAL(opponent, MOVE_ZAP_CANNON, AI_SCORE_DEFAULT + BEST_DAMAGE_MOVE);
        }
    }
}

AI_SINGLE_BATTLE_TEST("AI_FLAG_CONSIDER_STAT_CHANGES: AI will not try to lower Contrary target evasion to increases its odds of winning (Target Evasion Contrary +1)")
{
    GIVEN
    {
        AI_FLAGS(AI_FLAG_SMART_TRAINER | AI_FLAG_CONSIDER_STAT_CHANGES);
        PLAYER(SPECIES_SPINDA) {
            Speed(4);
            MaxHP(450);
            HP(450);
            Attack(71);
            Defense(134);
            SpAttack(71);
            SpDefense(123);
            Moves(MOVE_SONIC_BOOM);
            Ability(ABILITY_CONTRARY);
        }
        OPPONENT(SPECIES_WOBBUFFET) {
            Speed(5);
            MaxHP(180);
            HP(180);
            SpAttack(71);
            Moves(MOVE_SWEET_SCENT, MOVE_THUNDER);
        }
        WITH_CONFIG(B_UPDATED_MOVE_DATA, GEN_5);
    } WHEN {
        TURN {
            EXPECT_MOVE(opponent, MOVE_THUNDER);
            SCORE_EQ_VAL(opponent, MOVE_SWEET_SCENT, AI_SCORE_DEFAULT + NO_DAMAGE_OR_FAILS);
            SCORE_EQ_VAL(opponent, MOVE_THUNDER, AI_SCORE_DEFAULT + BEST_DAMAGE_MOVE);
        }
    }
}
