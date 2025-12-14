#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Analytic increases the power of moves by 30% if it's the last one that uses its move", s16 damage)
{
    u32 speed;

    PARAMETRIZE { speed = 3; }
    PARAMETRIZE { speed = 1; }

    GIVEN {
        PLAYER(SPECIES_MAGNEMITE) { Ability(ABILITY_ANALYTIC); Speed(speed); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(2); }
    } WHEN {
        TURN { MOVE(player, MOVE_SCRATCH); }
    } SCENE {
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_MUL_EQ(results[0].damage, Q_4_12(1.3), results[1].damage);
    }
}

// Test that Analytic works correctly when a slot is empty after fainting
// This tests the fix for incorrect "last to move" check with absent battlers
DOUBLE_BATTLE_TEST("Analytic activates correctly with empty slot after fainting", s16 damage)
{
    u32 speed;

    PARAMETRIZE { speed = 50; } // Faster than opponentRight, doesn't get boost
    PARAMETRIZE { speed = 5; }  // Slower than opponentRight, gets boost

    GIVEN {
        PLAYER(SPECIES_MAGNEMITE) { Ability(ABILITY_ANALYTIC); Speed(speed); }
        PLAYER(SPECIES_WYNAUT) { HP(1); Speed(25); } // Will faint first turn
        OPPONENT(SPECIES_WOBBUFFET) { Speed(20); }
        OPPONENT(SPECIES_WYNAUT) { Speed(10); }
    } WHEN {
        // Turn 1: KO playerRight
        TURN {
            MOVE(opponentLeft, MOVE_TACKLE, target: playerRight);
        }
        // Turn 2: Check Analytic with empty slot
        TURN {
            MOVE(opponentRight, MOVE_CELEBRATE);
            MOVE(playerLeft, MOVE_SCRATCH, target: opponentLeft);
        }
    } SCENE {
        // Turn 2: Capture damage
        HP_BAR(opponentLeft, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_MUL_EQ(results[0].damage, Q_4_12(1.3), results[1].damage);
    }
}

DOUBLE_BATTLE_TEST("Analytic does not activate when not moving last with empty slot", s16 damage)
{
    u32 speed;

    PARAMETRIZE { speed = 50; } // Faster than both opponents, no boost
    PARAMETRIZE { speed = 15; } // Faster than opponentRight (10), no boost since opponentRight acts after

    GIVEN {
        PLAYER(SPECIES_MAGNEMITE) { Ability(ABILITY_ANALYTIC); Speed(speed); }
        PLAYER(SPECIES_WYNAUT) { HP(1); Speed(25); } // Will faint first turn
        OPPONENT(SPECIES_WOBBUFFET) { Speed(20); }
        OPPONENT(SPECIES_WYNAUT) { Speed(10); }
    } WHEN {
        // Turn 1: KO playerRight
        TURN {
            MOVE(opponentLeft, MOVE_TACKLE, target: playerRight);
        }
        // Turn 2: playerLeft (speed 15 or 50) should NOT get Analytic boost
        // because opponentRight (speed 10) will act after playerLeft in both cases
        TURN {
            MOVE(opponentLeft, MOVE_CELEBRATE);
            MOVE(opponentRight, MOVE_CELEBRATE);
            MOVE(playerLeft, MOVE_SCRATCH, target: opponentLeft);
        }
    } SCENE {
        // Turn 2: Capture damage - neither speed should get boost
        HP_BAR(opponentLeft, captureDamage: &results[i].damage);
    } FINALLY {
        // Both should do the same damage (no boost in either case)
        EXPECT_EQ(results[0].damage, results[1].damage);
    }
}

TO_DO_BATTLE_TEST("Analytic takes into account modifications to speeed an priority (Gen 5-8)");       //Eg. Paralysis, Power Weight, Stall
TO_DO_BATTLE_TEST("Analytic does not take into account modifications to speeed an priority (Gen 8)"); //Eg. Paralysis, Power Weight, Stall

// Triple Battles needed to test
//TO_DO_BATTLE_TEST("If the Pokémon with Analytic is targeting a Pokémon in a flank position that chooses to switch with its ally in the middle, its move's power will always be normal when it attacks the Pokémon that is shifted into the flank position");
//TO_DO_BATTLE_TEST("If the Pokémon with Analytic targets a Pokémon in the middle whose ally on a flank chooses to shift into the middle position, its move's power still depends on whether the Pokémon that was in the middle (and is now on a flank) has acted when the Pokémon with Analytic uses its move");
