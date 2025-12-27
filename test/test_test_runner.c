#include "global.h"
#include "test/battle.h"
#include "test/test.h"

TEST("Tests resume after CRASH")
{
    KNOWN_CRASHING;
    void (*f)(void) = NULL;
    f();
}

SINGLE_BATTLE_TEST("Substitute hits are detected by SUB_HIT")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_SUBSTITUTE); MOVE(opponent, MOVE_SCRATCH); }
    } SCENE {
        SUB_HIT(player);
    }
}

SINGLE_BATTLE_TEST("Substitute hits are detected by SUB_HIT, break TRUE")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Level(1); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_SUBSTITUTE); MOVE(opponent, MOVE_SCRATCH); }
    } SCENE {
        SUB_HIT(player, subBreak: TRUE);
    }
}

SINGLE_BATTLE_TEST("Substitute hits are detected by SUB_HIT, break FALSE")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Level(100); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_SUBSTITUTE); MOVE(opponent, MOVE_SCRATCH); }
    } SCENE {
        SUB_HIT(player, subBreak: FALSE);
    }
}

SINGLE_BATTLE_TEST("Substitute hits are detected by SUB_HIT, records damage")
{
    u16 damage;
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_SUBSTITUTE); MOVE(opponent, MOVE_SCRATCH); }
    } SCENE {
        SUB_HIT(player, captureDamage: &damage);
    } THEN {
        EXPECT_GT(damage, 0);
    }
}

SINGLE_BATTLE_TEST("Substitute hits are detected by SUB_HIT, records damage, break FALSE")
{
    u16 damage;
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_SUBSTITUTE); MOVE(opponent, MOVE_SCRATCH); }
    } SCENE {
        SUB_HIT(player, captureDamage: &damage, subBreak: FALSE);
    } THEN {
        EXPECT_GT(damage, 0);
    }
}

SINGLE_BATTLE_TEST("Substitute hits are detected by SUB_HIT, records damage, break TRUE")
{
    u16 damage;
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Level(1); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_SUBSTITUTE); MOVE(opponent, MOVE_SCRATCH); }
    } SCENE {
        SUB_HIT(player, captureDamage: &damage, subBreak: TRUE);
    } THEN {
        EXPECT_GT(damage, 0);
    }
}

TEST("EXPECT_FAIL allows expected failing tests to pass")
{
    EXPECT_FAIL {
        // Test should fail but be considered a pass
        EXPECT_EQ(1, 2);
    }
}

AI_SINGLE_BATTLE_TEST("EXPECT_FAIL detects failures caused by EXPECT_MOVE")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET) { Item(ITEM_CHOICE_SCARF); Moves(MOVE_FAKE_OUT, MOVE_BODY_SLAM); }
    } WHEN {
        TURN { EXPECT_MOVE(opponent, MOVE_FAKE_OUT); }
        EXPECT_FAIL {
            TURN { EXPECT_MOVE(opponent, MOVE_BODY_SLAM); }
        }
    }
}

AI_SINGLE_BATTLE_TEST("EXPECT_FAIL detects failures caused by EXPECT_SWITCH")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET) { Item(ITEM_CHOICE_SCARF); Moves(MOVE_FAKE_OUT, MOVE_BODY_SLAM); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { EXPECT_MOVE(opponent, MOVE_FAKE_OUT); }
        EXPECT_FAIL {
            TURN { EXPECT_SWITCH(opponent, 1); }
        }
    }
}

SINGLE_BATTLE_TEST("EXPECT_FAIL: Incorrect use of SUB_HIT results in test failure, break TRUE")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Level(100); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_SUBSTITUTE); MOVE(opponent, MOVE_SCRATCH); }
    } EXPECT_FAIL {
        SCENE {
            SUB_HIT(player, subBreak: TRUE);
        }
    }
}

SINGLE_BATTLE_TEST("EXPECT_FAIL: Incorrect use of SUB_HIT results in test failure, break FALSE")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Level(1); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_SUBSTITUTE); MOVE(opponent, MOVE_SCRATCH); }
    } EXPECT_FAIL {
        SCENE {
            SUB_HIT(player, subBreak: FALSE);
        }
    }
}
