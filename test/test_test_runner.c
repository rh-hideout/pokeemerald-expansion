#include "global.h"
#include "test/battle.h"
#include "test/test.h"
#include "test/battle.h"

TEST("Tests resume after CRASH")
{
    KNOWN_CRASHING;
    void (*f)(void) = NULL;
    f();
}

MULTI_BATTLE_TEST("Forced Abilities are set correctly in multi battle tests")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        PARTNER(SPECIES_WOBBUFFET);
        PARTNER(SPECIES_NINETALES_ALOLA) { Ability(ABILITY_DRIZZLE); }
        OPPONENT_A(SPECIES_WOBBUFFET);
        OPPONENT_A(SPECIES_NINETALES_ALOLA) { Ability(ABILITY_SAND_STREAM); }
        OPPONENT_B(SPECIES_WYNAUT);
        OPPONENT_B(SPECIES_NINETALES_ALOLA) { Ability(ABILITY_DROUGHT); }
    } WHEN {
        TURN { SWITCH(opponentLeft, 1); SWITCH(playerRight, 1); SWITCH(opponentRight, 1); }
    } SCENE {
        ABILITY_POPUP(opponentLeft, ABILITY_SAND_STREAM);
        ABILITY_POPUP(playerRight, ABILITY_DRIZZLE);
        ABILITY_POPUP(opponentRight, ABILITY_DROUGHT);
    }
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

MULTI_BATTLE_TEST("Celebrate does not need to be explicitly set in a non-AI test")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Speed(4); }
        PARTNER(SPECIES_WOBBUFFET) { Speed(2); }
        OPPONENT_A(SPECIES_WOBBUFFET) { Speed(3); }
        OPPONENT_B(SPECIES_WOBBUFFET) { Speed(1); }
    } WHEN {
        TURN {}
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, playerLeft);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, opponentLeft);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, playerRight);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, opponentRight);
    }
}
