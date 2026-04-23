#include "global.h"
#include "test/battle.h"

FRONTIER_DOUBLE_BATTLE_TEST(TOWER, OPEN, MULTIS, "Battle Tower: first test")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        PARTNER(SPECIES_WYNAUT);
        OPPONENT_A(SPECIES_WOBBUFFET);
        OPPONENT_B(SPECIES_WYNAUT);
    } WHEN {
        TURN {}
    }
}
