#include "global.h"
#include "test/battle.h"
#include "battle_ai_util.h"

ASSUMPTIONS
{
    ASSUME(gMovesInfo[MOVE_WING_ATTACK].power > 0);
    ASSUME(gMovesInfo[MOVE_BOLT_BEAK].power > 0);
    ASSUME(gMovesInfo[MOVE_PROTECT].effect == EFFECT_PROTECT);
}

AI_DOUBLE_BATTLE_TEST("AI will not double target a pokemon when both AI mons see kill on the right player slot")
{
    GIVEN {
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT);
        PLAYER(SPECIES_REGIROCK) { Speed(10); }
        PLAYER(SPECIES_CLEFFA) { Speed(20); HP(1); }
        OPPONENT(SPECIES_ZAPDOS) { Speed(100); Moves(MOVE_BOLT_BEAK); }
        OPPONENT(SPECIES_SALAMENCE) { Speed(90); Moves(MOVE_WING_ATTACK); }
    } WHEN {
        TURN {
            MOVE(playerRight, MOVE_PROTECT);
            EXPECT_MOVE(opponentLeft, MOVE_BOLT_BEAK);
            EXPECT_MOVE(opponentRight, MOVE_WING_ATTACK);
        }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_PROTECT, playerRight);
        MESSAGE("Foe Zapdos used Bolt Beak!");
        MESSAGE("Cleffa protected itself!");
        NOT HP_BAR(playerRight);
        HP_BAR(playerLeft);
     }
}

AI_DOUBLE_BATTLE_TEST("AI will not double target a pokemon when both AI mons see kill on the left player slot")
{
    GIVEN {
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT);
        PLAYER(SPECIES_CLEFFA) { Speed(20); HP(1); }
        PLAYER(SPECIES_REGIROCK) { Speed(10); }
        OPPONENT(SPECIES_ZAPDOS) { Speed(100); Moves(MOVE_BOLT_BEAK); }
        OPPONENT(SPECIES_SALAMENCE) { Speed(90); Moves(MOVE_WING_ATTACK); }
    } WHEN {
        TURN {
            MOVE(playerLeft, MOVE_PROTECT);
            EXPECT_MOVE(opponentLeft, MOVE_BOLT_BEAK);
            EXPECT_MOVE(opponentRight, MOVE_WING_ATTACK);
        }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_PROTECT, playerLeft);
        MESSAGE("Foe Zapdos used Bolt Beak!");
        HP_BAR(playerRight);
        MESSAGE("Foe Salamence used Wing Attack!");
        MESSAGE("Cleffa protected itself!");
        NOT HP_BAR(playerLeft);
     }
}
