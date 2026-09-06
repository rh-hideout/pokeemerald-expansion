#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(gItemsInfo[ITEM_SNOWBALL].holdEffect == HOLD_EFFECT_SNOWBALL);
    ASSUME(GetMoveType(MOVE_ICE_SHARD) == TYPE_ICE);
}

SINGLE_BATTLE_TEST("Snowball raises Attack by one stage if hit by an Ice-type move")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) {};
        OPPONENT(SPECIES_WOBBUFFET) { Item(ITEM_SNOWBALL); }
    } WHEN {
        TURN {
            MOVE(player, MOVE_ICE_SHARD);
        }
    } SCENE {
        ITEM_POPUP(opponent, ITEM_SNOWBALL);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_EFFECT, opponent);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponent);
        MESSAGE("The Snowball boosted the opposing Wobbuffet's Attack!");
    } THEN {
        EXPECT_EQ(opponent->statStages[STAT_ATK], DEFAULT_STAT_STAGE + 1);
    }
}

SINGLE_BATTLE_TEST("Snowball doesn't activate if the holder protects")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) {};
        OPPONENT(SPECIES_WOBBUFFET) { Item(ITEM_SNOWBALL); }
    } WHEN {
        TURN {
            MOVE(opponent, MOVE_PROTECT);
            MOVE(player, MOVE_ICE_SHARD);
        }
    } SCENE {
        NONE_OF {
            ITEM_POPUP(opponent, ITEM_SNOWBALL);
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_EFFECT, opponent);
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponent);
            MESSAGE("The Snowball boosted the opposing Wobbuffet's Attack!");
        }
    } THEN {
        EXPECT_EQ(opponent->statStages[STAT_ATK], DEFAULT_STAT_STAGE);
    }
}
