#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Sweet Scent lowers evasion according to the configured move data")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_SWEET_SCENT); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SWEET_SCENT, player);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponent);
    } THEN {
        EXPECT_EQ(opponent->statStages[STAT_EVASION], DEFAULT_STAT_STAGE - (GetConfig(B_UPDATED_MOVE_DATA) >= GEN_6 ? 2 : 1));
    }
}
