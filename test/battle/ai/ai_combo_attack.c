#include "global.h"
#include "test/battle.h"
#include "battle_ai_util.h"

// Unsure why opponentRight scoring 105 when opponentLeft clicking TA
/*AI_DOUBLE_BATTLE_TEST("Combo Attack: Round will not be incentivised if partner does not choose Round")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_ROUND) == EFFECT_ROUND);
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT | AI_FLAG_POWERFUL_STATUS | AI_FLAG_CONSIDER_COMBO);
        //TIE_BREAK_TARGET(TARGET_TIE_LO,0); Target tie temporarily removed while thinking battler only chooses first best move...
        PLAYER(SPECIES_WOBBUFFET) { Speed(6); }
        PLAYER(SPECIES_WOBBUFFET) { Speed(5); }
        OPPONENT(SPECIES_WOBBUFFET) { Moves(MOVE_ROUND, MOVE_TRI_ATTACK); Speed(4); }
        OPPONENT(SPECIES_WOBBUFFET) { Moves(MOVE_ROUND, MOVE_TAILWIND); Speed(3); }
    } WHEN {
        TURN {
            EXPECT_MOVE(opponentLeft, MOVE_TRI_ATTACK);
            EXPECT_MOVE(opponentRight, MOVE_TAILWIND);
            SCORE_EQ_VAL(opponentLeft, MOVE_TRI_ATTACK, AI_SCORE_DEFAULT + BEST_DAMAGE_MOVE, target:playerLeft);
            SCORE_EQ_VAL(opponentRight, MOVE_TAILWIND, AI_SCORE_DEFAULT + POWERFUL_STATUS_MOVE + 4, target:playerLeft); // + 4 from "regular" Tailwind AI
            SCORE_EQ_VAL(opponentLeft, MOVE_ROUND, AI_SCORE_DEFAULT, target:playerLeft);
            SCORE_EQ_VAL(opponentRight, MOVE_ROUND, AI_SCORE_DEFAULT + BEST_DAMAGE_MOVE, target:playerLeft); // 
        }
    }
}*/

AI_DOUBLE_BATTLE_TEST("Combo Attack: Round is incentivised over higher damaging moves if present on both battlers")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_ROUND) == EFFECT_ROUND);
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CONSIDER_COMBO);
        //TIE_BREAK_TARGET(TARGET_TIE_LO,0); Target tie temporarily removed while thinking battler only chooses first best move...
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET) { Moves(MOVE_ROUND, MOVE_TRI_ATTACK); }
        OPPONENT(SPECIES_WOBBUFFET) { Moves(MOVE_ROUND, MOVE_TRI_ATTACK); }
    } WHEN {
        TURN {
            EXPECT_MOVE(opponentLeft, MOVE_ROUND);
            EXPECT_MOVE(opponentRight, MOVE_ROUND);
            SCORE_GT(opponentLeft, MOVE_ROUND, MOVE_TRI_ATTACK, target:playerLeft);
            SCORE_GT(opponentRight, MOVE_ROUND, MOVE_TRI_ATTACK, target:playerLeft);
            SCORE_EQ_VAL(opponentLeft, MOVE_ROUND, AI_SCORE_DEFAULT + BEST_EFFECT, target:playerLeft);
            SCORE_EQ_VAL(opponentRight, MOVE_ROUND, AI_SCORE_DEFAULT + BEST_EFFECT, target:playerLeft);
            SCORE_EQ_VAL(opponentLeft, MOVE_TRI_ATTACK, AI_SCORE_DEFAULT + BEST_DAMAGE_MOVE, target:playerLeft);
            SCORE_EQ_VAL(opponentRight, MOVE_TRI_ATTACK, AI_SCORE_DEFAULT + BEST_DAMAGE_MOVE, target:playerLeft);
        }
    }
}

AI_DOUBLE_BATTLE_TEST("Combo Attack: Round is not disincentivised due to partner not also having Round when Round is the best available move")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_ROUND) == EFFECT_ROUND);
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CONSIDER_COMBO);
        //TIE_BREAK_TARGET(TARGET_TIE_LO,0); Target tie temporarily removed while thinking battler only chooses first best move...
        PLAYER(SPECIES_WOBBUFFET) { Speed(1); }
        PLAYER(SPECIES_WOBBUFFET) { Speed(2); }
        OPPONENT(SPECIES_WOBBUFFET) { Moves(MOVE_ROUND, MOVE_SCRATCH); Speed(4); }
        OPPONENT(SPECIES_WOBBUFFET) { Moves(MOVE_SCRATCH); Speed(3); }
    } WHEN {
        TURN {
            EXPECT_MOVE(opponentLeft, MOVE_ROUND);
            EXPECT_MOVE(opponentRight, MOVE_SCRATCH);
            SCORE_EQ_VAL(opponentLeft, MOVE_ROUND, AI_SCORE_DEFAULT + BEST_DAMAGE_MOVE, target:playerLeft);
            SCORE_EQ_VAL(opponentRight, MOVE_SCRATCH, AI_SCORE_DEFAULT + BEST_DAMAGE_MOVE, target:playerLeft);
            SCORE_EQ_VAL(opponentLeft, MOVE_SCRATCH, AI_SCORE_DEFAULT, target:playerLeft);
        }
    }
}


AI_DOUBLE_BATTLE_TEST("Combo Attack: Fusion Flare will be chosen if partner acts directly before")
{
    u32 speed = 0;
    PARAMETRIZE { speed = 30; }
    PARAMETRIZE { speed = 11; }

    GIVEN {
        ASSUME(GetMoveEffect(MOVE_FUSION_FLARE) == EFFECT_FUSION_COMBO);
        ASSUME(GetMoveEffect(MOVE_FUSION_BOLT) == EFFECT_FUSION_COMBO);
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CONSIDER_COMBO);
        //TIE_BREAK_TARGET(TARGET_TIE_LO,0); Target tie temporarily removed while thinking battler only chooses first best move...
        PLAYER(SPECIES_WOBBUFFET) { Speed(10); }
        PLAYER(SPECIES_WOBBUFFET) { Speed(20); }
        OPPONENT(SPECIES_RESHIRAM) { Speed(speed); Moves(MOVE_FUSION_FLARE, MOVE_FLAMETHROWER); }
        OPPONENT(SPECIES_ZEKROM) { Speed(40); Moves(MOVE_FUSION_BOLT); }
    } WHEN {
        TURN {
            if (speed == 30) {
                EXPECT_MOVE(opponentLeft, MOVE_FUSION_FLARE);
                EXPECT_MOVE(opponentRight, MOVE_FUSION_BOLT);
            } else { // Flamethrower gets the best damage move
                EXPECT_MOVE(opponentLeft, MOVE_FLAMETHROWER);
                EXPECT_MOVE(opponentRight, MOVE_FUSION_BOLT);
            }
        }
    }
}
