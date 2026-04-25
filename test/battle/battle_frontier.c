#include "global.h"
#include "test/battle.h"

FRONTIER_BATTLE_TEST(SINGLE, TOWER, OPEN, "Battle Tower: FRONTIER_MODE_OPEN sets opponent team level to match highest player level (singles)")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Level(55); }
        PLAYER(SPECIES_WYNAUT) { Level(60); }
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WYNAUT);
    } WHEN {
        TURN {}
    } THEN {
        EXPECT_EQ(GetMonData(&gParties[B_TRAINER_1][0], MON_DATA_LEVEL), 60);
        EXPECT_EQ(GetMonData(&gParties[B_TRAINER_1][1], MON_DATA_LEVEL), 60);
    }
}
