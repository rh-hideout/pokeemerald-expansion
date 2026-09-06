#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(gItemsInfo[ITEM_CELL_BATTERY].holdEffect == HOLD_EFFECT_CELL_BATTERY);
    ASSUME(GetMoveType(MOVE_SHOCK_WAVE) == TYPE_ELECTRIC);
}

SINGLE_BATTLE_TEST("Cell Battery raises Attack by one stage if hit by an Electric-type move")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) {};
        OPPONENT(SPECIES_WOBBUFFET) { Item(ITEM_CELL_BATTERY); }
    } WHEN {
        TURN {
            MOVE(player, MOVE_SHOCK_WAVE);
        }
    } SCENE {
        ITEM_POPUP(opponent, ITEM_CELL_BATTERY);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_EFFECT, opponent);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponent);
        MESSAGE("The Cell Battery boosted the opposing Wobbuffet's Attack!");
    } THEN {
        EXPECT_EQ(opponent->statStages[STAT_ATK], DEFAULT_STAT_STAGE + 1);
    }
}

SINGLE_BATTLE_TEST("Cell Battery doesn't activate if the holder protects")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) {};
        OPPONENT(SPECIES_WOBBUFFET) { Item(ITEM_CELL_BATTERY); }
    } WHEN {
        TURN {
            MOVE(opponent, MOVE_PROTECT);
            MOVE(player, MOVE_SHOCK_WAVE);
        }
    } SCENE {
        NONE_OF {
            ITEM_POPUP(opponent, ITEM_CELL_BATTERY);
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_EFFECT, opponent);
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponent);
            MESSAGE("The Cell Battery boosted the opposing Wobbuffet's Attack!");
        }
    } THEN {
        EXPECT_EQ(opponent->statStages[STAT_SPDEF], DEFAULT_STAT_STAGE);
    }
}

