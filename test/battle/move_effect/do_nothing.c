#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Splash does nothing")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_SPLASH) == EFFECT_DO_NOTHING);
        ASSUME(GetItemHoldEffect(ITEM_NORMAL_GEM) == HOLD_EFFECT_GEMS);
        PLAYER(SPECIES_WOBBUFFET) { Item(ITEM_NORMAL_GEM); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_SPLASH); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SPLASH, player);
        MESSAGE("But nothing happened!");
    } THEN {
        EXPECT_EQ(player->hp, player->maxHP);
        EXPECT_EQ(player->item, ITEM_NORMAL_GEM);
        for (enum Stat stat = STAT_ATK; stat < NUM_BATTLE_STATS; stat++)
            EXPECT_EQ(player->statStages[stat], DEFAULT_STAT_STAGE);
        EXPECT_EQ(opponent->hp, opponent->maxHP);
        EXPECT_EQ(player->status1, STATUS1_NONE);
        EXPECT_EQ(opponent->status1, STATUS1_NONE);
    }
}
