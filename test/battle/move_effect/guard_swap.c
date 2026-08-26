#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Guard Swap switches the user's Defense and Sp. Def stat stages with the target")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_GUARD_SWAP) == EFFECT_GUARD_SWAP);
        ASSUME_STAT_CHANGE(MOVE_IRON_DEFENSE, defense: +2);
        ASSUME_STAT_CHANGE(MOVE_AMNESIA, spDef: +2);
        PLAYER(SPECIES_WOBBUFFET) { Speed(2); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(1); }
    } WHEN {
        TURN { MOVE(player, MOVE_IRON_DEFENSE); MOVE(opponent, MOVE_AMNESIA); }
        TURN { MOVE(player, MOVE_GUARD_SWAP); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_IRON_DEFENSE, player);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_AMNESIA, opponent);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_GUARD_SWAP, player);
    } THEN {
        EXPECT_EQ(player->statStages[STAT_DEF], DEFAULT_STAT_STAGE);
        EXPECT_EQ(player->statStages[STAT_SPDEF], DEFAULT_STAT_STAGE + 2);
        EXPECT_EQ(opponent->statStages[STAT_DEF], DEFAULT_STAT_STAGE + 2);
        EXPECT_EQ(opponent->statStages[STAT_SPDEF], DEFAULT_STAT_STAGE);
    }
}

SINGLE_BATTLE_TEST("Clear Amulet does not prevent Guard Swap from transferring lowered stat stages")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_GUARD_SWAP) == EFFECT_GUARD_SWAP);
        ASSUME_MOVE_EFFECT_STAT_CHANGE(MOVE_CLOSE_COMBAT, self: TRUE, defense: -1, spDef: -1);
        ASSUME(GetItemHoldEffect(ITEM_CLEAR_AMULET) == HOLD_EFFECT_CLEAR_AMULET);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET) { Item(ITEM_CLEAR_AMULET); }
    } WHEN {
        TURN { MOVE(player, MOVE_CLOSE_COMBAT); }
        TURN { MOVE(player, MOVE_GUARD_SWAP); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CLOSE_COMBAT, player);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_GUARD_SWAP, player);
    } THEN {
        EXPECT_EQ(player->statStages[STAT_DEF], DEFAULT_STAT_STAGE);
        EXPECT_EQ(player->statStages[STAT_SPDEF], DEFAULT_STAT_STAGE);
        EXPECT_EQ(opponent->statStages[STAT_DEF], DEFAULT_STAT_STAGE - 1);
        EXPECT_EQ(opponent->statStages[STAT_SPDEF], DEFAULT_STAT_STAGE - 1);
    }
}
