#include "global.h"
#include "test/battle.h"

DOUBLE_BATTLE_TEST("Costar copies an ally's stat stages upon entering battle")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WYNAUT);
        OPPONENT(SPECIES_FLAMIGO) { Ability(ABILITY_COSTAR); }
    } WHEN {
        TURN { MOVE(opponentLeft, MOVE_SWORDS_DANCE); }
        TURN { SWITCH(opponentRight, 2); MOVE(playerLeft, MOVE_CELEBRATE); }
    } SCENE {
        // Turn 1 - buff up
        MESSAGE("The opposing Wobbuffet used Swords Dance!");
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponentLeft);
        // Turn 2 - Switch into Flamigo
        MESSAGE("2 sent out Flamigo!");
        ABILITY_POPUP(opponentRight, ABILITY_COSTAR);
        MESSAGE("The opposing Flamigo copied the opposing Wobbuffet's stat changes!");
    } THEN {
        EXPECT_EQ(opponentRight->statStages[STAT_ATK], DEFAULT_STAT_STAGE + 2);
    }
}

DOUBLE_BATTLE_TEST("Costar copies an ally's stat stages after their ability activates upon entering battle")
{
    u32 speedLeft, speedRight = 0;

    PARAMETRIZE { speedLeft = 200; speedRight = 150; }
    PARAMETRIZE { speedLeft = 150; speedRight = 200; }

    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Speed(100); }
        PLAYER(SPECIES_WOBBUFFET) { Speed(110); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(10); HP(1); };
        OPPONENT(SPECIES_WYNAUT) { Speed(10); HP(1); };
        OPPONENT(SPECIES_FLAMIGO) { Speed(speedLeft); Ability(ABILITY_COSTAR); }
        OPPONENT(SPECIES_ZACIAN) { Speed(speedRight); Ability(ABILITY_INTREPID_SWORD); }
    } WHEN {
        TURN {
            MOVE(playerLeft, MOVE_HYPER_VOICE);
            SEND_OUT(opponentLeft, 2);
            SEND_OUT(opponentRight, 3);
        }
    } SCENE {
        ABILITY_POPUP(opponentRight, ABILITY_INTREPID_SWORD);
        ABILITY_POPUP(opponentLeft, ABILITY_COSTAR);
    } THEN {
        EXPECT_EQ(opponentRight->statStages[STAT_ATK], DEFAULT_STAT_STAGE + 1);
        EXPECT_EQ(opponentLeft->statStages[STAT_ATK], DEFAULT_STAT_STAGE + 1);
    }
}

// Copy from Ruin ability tests
TO_DO_BATTLE_TEST("Costar's message displays correctly after all battlers fainted - Player");
TO_DO_BATTLE_TEST("Costar's message displays correctly after all battlers fainted - Opponent");

TO_DO_BATTLE_TEST("Costar can copy an ally's critical hit ratio");
