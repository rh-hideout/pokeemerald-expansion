#include "global.h"
#include "test/battle.h"

DOUBLE_BATTLE_TEST("Sweet Scent lowers both foes' evasion according to the configured move data")
{
    GIVEN {
        ASSUME_STAT_CHANGE(
            MOVE_SWEET_SCENT,
            evasion: -(B_UPDATED_MOVE_DATA >= GEN_6 ? 2 : 1)
        );
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WYNAUT);
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_SWEET_SCENT); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SWEET_SCENT, playerLeft);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponentLeft);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponentRight);
    } THEN {
        u32 stages = B_UPDATED_MOVE_DATA >= GEN_6 ? 2 : 1;
        EXPECT_EQ(opponentLeft->statStages[STAT_EVASION], DEFAULT_STAT_STAGE - stages);
        EXPECT_EQ(opponentRight->statStages[STAT_EVASION], DEFAULT_STAT_STAGE - stages);
    }
}
