#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(gItemsInfo[ITEM_LUMINOUS_MOSS].holdEffect == HOLD_EFFECT_LUMINOUS_MOSS);
    ASSUME(GetMoveType(MOVE_WATER_GUN) == TYPE_WATER);
}

SINGLE_BATTLE_TEST("Luminous Moss raises Sp. Def by one stage if hit by an Water-type move")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) {};
        OPPONENT(SPECIES_WOBBUFFET) { Item(ITEM_LUMINOUS_MOSS); }
    } WHEN {
        TURN {
            MOVE(player, MOVE_WATER_GUN);
        }
    } SCENE {
        ITEM_POPUP(opponent, ITEM_LUMINOUS_MOSS);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_EFFECT, opponent);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponent);
        MESSAGE("The Luminous Moss boosted the opposing Wobbuffet's Sp. Def!");
    } THEN {
        EXPECT_EQ(opponent->statStages[STAT_SPDEF], DEFAULT_STAT_STAGE + 1);
    }
}

SINGLE_BATTLE_TEST("Luminous Moss doesn't activate if the holder protects")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) {};
        OPPONENT(SPECIES_WOBBUFFET) { Item(ITEM_LUMINOUS_MOSS); }
    } WHEN {
        TURN {
            MOVE(opponent, MOVE_PROTECT);
            MOVE(player, MOVE_WATER_GUN);
        }
    } SCENE {
        NONE_OF {
            ITEM_POPUP(opponent, ITEM_LUMINOUS_MOSS);
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_EFFECT, opponent);
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponent);
            MESSAGE("The Luminous Moss boosted the opposing Wobbuffet's Sp. Def!");
        }
    } THEN {
        EXPECT_EQ(opponent->statStages[STAT_SPDEF], DEFAULT_STAT_STAGE);
    }
}
