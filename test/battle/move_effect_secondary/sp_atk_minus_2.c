#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(MoveHasAdditionalEffectSelf(MOVE_OVERHEAT, MOVE_EFFECT_SP_ATK_MINUS_2));
}

SINGLE_BATTLE_TEST("Overheat drops Sp. Atk by 2 stages - singles")
{
    GIVEN {
        PLAYER(TEST_SPECIES_WOBBUFFET)
        OPPONENT(TEST_SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_OVERHEAT); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_OVERHEAT, player);
        HP_BAR(opponent);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, player);
        MESSAGE("Wobbuffet's Sp. Atk harshly fell!");
    } THEN {
        EXPECT_EQ(player->statStages[STAT_SPATK], DEFAULT_STAT_STAGE - 2);
    }
}

DOUBLE_BATTLE_TEST("Overheat drops Sp. Atk by 2 stages - doubles")
{
    GIVEN {
        PLAYER(TEST_SPECIES_WOBBUFFET)
        PLAYER(TEST_SPECIES_WOBBUFFET);
        OPPONENT(TEST_SPECIES_WOBBUFFET);
        OPPONENT(TEST_SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_OVERHEAT, target: opponentLeft); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_OVERHEAT, playerLeft);
        HP_BAR(opponentLeft);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, playerLeft);
        MESSAGE("Wobbuffet's Sp. Atk harshly fell!");
    } THEN {
        EXPECT_EQ(playerLeft->statStages[STAT_SPATK], DEFAULT_STAT_STAGE - 2);
    }
}
