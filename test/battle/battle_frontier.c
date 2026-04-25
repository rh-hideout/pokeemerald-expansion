#include "global.h"
#include "test/battle.h"

FRONTIER_BATTLE_TEST(TOWER, SINGLE, OPEN, "Frontier Battle Tower: FRONTIER_LVL_OPEN sets opponent team level to match highest player level (Singles)")
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

FRONTIER_BATTLE_TEST(TOWER, SINGLE, 50, "Frontier Battle Tower: FRONTIER_LVL_50 sets opponent team level to 50 regardless of player level (Singles)")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Level(35); }
        PLAYER(SPECIES_WYNAUT) { Level(40); }
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WYNAUT);
    } WHEN {
        TURN {}
    } THEN {
        EXPECT_EQ(GetMonData(&gParties[B_TRAINER_1][0], MON_DATA_LEVEL), 50);
        EXPECT_EQ(GetMonData(&gParties[B_TRAINER_1][1], MON_DATA_LEVEL), 50);
    }
}

FRONTIER_BATTLE_TEST(TOWER, DOUBLE, OPEN, "Frontier Battle Tower: FRONTIER_LVL_OPEN sets opponent team level to match highest player level (Double)")
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

FRONTIER_BATTLE_TEST(TOWER, DOUBLE, 50, "Frontier Battle Tower: FRONTIER_LVL_50 sets opponent team level to 50 regardless of player level (Double)")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Level(35); }
        PLAYER(SPECIES_WYNAUT) { Level(40); }
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WYNAUT);
    } WHEN {
        TURN {}
    } THEN {
        EXPECT_EQ(GetMonData(&gParties[B_TRAINER_1][0], MON_DATA_LEVEL), 50);
        EXPECT_EQ(GetMonData(&gParties[B_TRAINER_1][1], MON_DATA_LEVEL), 50);
    }
}

FRONTIER_BATTLE_TEST(TOWER, MULTI, OPEN, "Frontier Battle Tower: FRONTIER_LVL_OPEN sets opponent team level to match highest player level (Multi)")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Level(55); }
        PARTNER(SPECIES_WYNAUT);
        OPPONENT_A(SPECIES_WOBBUFFET);
        OPPONENT_B(SPECIES_WYNAUT);
    } WHEN {
        TURN {}
    } THEN {
        EXPECT_EQ(GetMonData(&gParties[B_TRAINER_1][0], MON_DATA_LEVEL), 55);
        EXPECT_EQ(GetMonData(&gParties[B_TRAINER_2][0], MON_DATA_LEVEL), 55);
        EXPECT_EQ(GetMonData(&gParties[B_TRAINER_3][0], MON_DATA_LEVEL), 55);
    }
}

// TODO partner mon coming in at L40; opponentB not sending out a mon
FRONTIER_BATTLE_TEST(TOWER, MULTI, 50, "Frontier Battle Tower: FRONTIER_LVL_50 sets opponent team level to 50 regardless of player level (Multi)")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Level(35); }
        PARTNER(SPECIES_WYNAUT);
        OPPONENT_A(SPECIES_WOBBUFFET);
        OPPONENT_B(SPECIES_WYNAUT);
    } WHEN {
        TURN {}
    } THEN {
        EXPECT_EQ(GetMonData(&gParties[B_TRAINER_1][0], MON_DATA_LEVEL), 50);
        EXPECT_EQ(GetMonData(&gParties[B_TRAINER_2][0], MON_DATA_LEVEL), 50);
        EXPECT_EQ(GetMonData(&gParties[B_TRAINER_3][0], MON_DATA_LEVEL), 50);
    }
}

FRONTIER_BATTLE_TEST(DOME, SINGLE, OPEN, "Frontier Battle Dome: FRONTIER_LVL_OPEN sets opponent team level to match highest player level (Singles)")
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

FRONTIER_BATTLE_TEST(DOME, SINGLE, 50, "Frontier Battle Dome: FRONTIER_LVL_50 sets opponent team level to 50 regardless of player level (Singles)")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Level(35); }
        PLAYER(SPECIES_WYNAUT) { Level(40); }
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WYNAUT);
    } WHEN {
        TURN {}
    } THEN {
        EXPECT_EQ(GetMonData(&gParties[B_TRAINER_1][0], MON_DATA_LEVEL), 50);
        EXPECT_EQ(GetMonData(&gParties[B_TRAINER_1][1], MON_DATA_LEVEL), 50);
    }
}

/* TODO Illegal battle record presumably as handing for Palace is not yet written
FRONTIER_BATTLE_TEST(PALACE, SINGLE, OPEN, "Frontier Battle Palace: FRONTIER_LVL_OPEN sets opponent team level to match highest player level (Singles)")
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

FRONTIER_BATTLE_TEST(PALACE, SINGLE, 50, "Frontier Battle Palace: FRONTIER_LVL_50 sets opponent team level to 50 regardless of player level (Singles)")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Level(35); }
        PLAYER(SPECIES_WYNAUT) { Level(40); }
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WYNAUT);
    } WHEN {
        TURN {}
    } THEN {
        EXPECT_EQ(GetMonData(&gParties[B_TRAINER_1][0], MON_DATA_LEVEL), 50);
        EXPECT_EQ(GetMonData(&gParties[B_TRAINER_1][1], MON_DATA_LEVEL), 50);
    }
}
*/

FRONTIER_BATTLE_TEST(ARENA, SINGLE, OPEN, "Frontier Battle Arena: FRONTIER_LVL_OPEN sets opponent team level to match highest player level (Singles)")
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

FRONTIER_BATTLE_TEST(ARENA, SINGLE, 50, "Frontier Battle Arena: FRONTIER_LVL_50 sets opponent team level to 50 regardless of player level (Singles)")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Level(35); }
        PLAYER(SPECIES_WYNAUT) { Level(40); }
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WYNAUT);
    } WHEN {
        TURN {}
    } THEN {
        EXPECT_EQ(GetMonData(&gParties[B_TRAINER_1][0], MON_DATA_LEVEL), 50);
        EXPECT_EQ(GetMonData(&gParties[B_TRAINER_1][1], MON_DATA_LEVEL), 50);
    }
}

// TODO pretty sure having levels other than 50 and 100 in Battle Factory is not possible
FRONTIER_BATTLE_TEST(FACTORY, SINGLE, OPEN, "Frontier Battle Factory: FRONTIER_LVL_OPEN sets opponent team level to match highest player level (Singles)")
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

FRONTIER_BATTLE_TEST(FACTORY, SINGLE, 50, "Frontier Battle Factory: FRONTIER_LVL_50 sets opponent team level to 50 regardless of player level (Singles)")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Level(35); }
        PLAYER(SPECIES_WYNAUT) { Level(40); }
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WYNAUT);
    } WHEN {
        TURN {}
    } THEN {
        EXPECT_EQ(GetMonData(&gParties[B_TRAINER_1][0], MON_DATA_LEVEL), 50);
        EXPECT_EQ(GetMonData(&gParties[B_TRAINER_1][1], MON_DATA_LEVEL), 50);
    }
}

FRONTIER_BATTLE_TEST(PIKE_SINGLE, SINGLE, OPEN, "Frontier Battle Pike: FRONTIER_LVL_OPEN sets opponent team level to match highest player level (Singles)")
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

FRONTIER_BATTLE_TEST(PIKE_SINGLE, SINGLE, 50, "Frontier Battle Pike: FRONTIER_LVL_50 sets opponent team level to 50 regardless of player level (Singles)")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Level(35); }
        PLAYER(SPECIES_WYNAUT) { Level(40); }
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WYNAUT);
    } WHEN {
        TURN {}
    } THEN {
        EXPECT_EQ(GetMonData(&gParties[B_TRAINER_1][0], MON_DATA_LEVEL), 50);
        EXPECT_EQ(GetMonData(&gParties[B_TRAINER_1][1], MON_DATA_LEVEL), 50);
    }
}

FRONTIER_BATTLE_TEST(PIKE_DOUBLE, DOUBLE, OPEN, "Frontier Battle Pike: FRONTIER_LVL_OPEN sets opponent team level to match highest player level (Double)")
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

FRONTIER_BATTLE_TEST(PIKE_DOUBLE, DOUBLE, 50, "Frontier Battle Pike: FRONTIER_LVL_50 sets opponent team level to 50 regardless of player level (Double)")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Level(35); }
        PLAYER(SPECIES_WYNAUT) { Level(40); }
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WYNAUT);
    } WHEN {
        TURN {}
    } THEN {
        EXPECT_EQ(GetMonData(&gParties[B_TRAINER_1][0], MON_DATA_LEVEL), 50);
        EXPECT_EQ(GetMonData(&gParties[B_TRAINER_1][1], MON_DATA_LEVEL), 50);
    }
}

FRONTIER_BATTLE_TEST(PYRAMID, SINGLE, OPEN, "Frontier Battle Pyramid: FRONTIER_LVL_OPEN sets opponent team level to match highest player level (Singles)")
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

FRONTIER_BATTLE_TEST(PYRAMID, SINGLE, 50, "Frontier Battle Pyramid: FRONTIER_LVL_50 sets opponent team level to 50 regardless of player level (Singles)")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Level(35); }
        PLAYER(SPECIES_WYNAUT) { Level(40); }
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WYNAUT);
    } WHEN {
        TURN {}
    } THEN {
        EXPECT_EQ(GetMonData(&gParties[B_TRAINER_1][0], MON_DATA_LEVEL), 50);
        EXPECT_EQ(GetMonData(&gParties[B_TRAINER_1][1], MON_DATA_LEVEL), 50);
    }
}
