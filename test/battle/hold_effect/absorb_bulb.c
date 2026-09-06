#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(gItemsInfo[ITEM_ABSORB_BULB].holdEffect == HOLD_EFFECT_ABSORB_BULB);
    ASSUME(GetMoveType(MOVE_WATER_GUN) == TYPE_WATER);
}

SINGLE_BATTLE_TEST("Absorb Bulb raises Sp. Atk by one stage if hit by an Water-type move")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) {};
        OPPONENT(SPECIES_WOBBUFFET) { Item(ITEM_ABSORB_BULB); }
    } WHEN {
        TURN {
            MOVE(player, MOVE_WATER_GUN);
        }
    } SCENE {
        ITEM_POPUP(opponent, ITEM_ABSORB_BULB);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_EFFECT, opponent);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponent);
        MESSAGE("The Absorb Bulb boosted the opposing Wobbuffet's Sp. Atk!");
    } THEN {
        EXPECT_EQ(opponent->statStages[STAT_SPATK], DEFAULT_STAT_STAGE + 1);
    }
}

SINGLE_BATTLE_TEST("Absorb Bulb doesn't activate if the holder protects")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) {};
        OPPONENT(SPECIES_WOBBUFFET) { Item(ITEM_ABSORB_BULB); }
    } WHEN {
        TURN {
            MOVE(opponent, MOVE_PROTECT);
            MOVE(player, MOVE_WATER_GUN);
        }
    } SCENE {
        NONE_OF {
            ITEM_POPUP(opponent, ITEM_ABSORB_BULB);
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_EFFECT, opponent);
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponent);
            MESSAGE("The Absorb Bulb boosted the opposing Wobbuffet's Sp. Atk!");
        }
    } THEN {
        EXPECT_EQ(opponent->statStages[STAT_SPATK], DEFAULT_STAT_STAGE);
    }
}
