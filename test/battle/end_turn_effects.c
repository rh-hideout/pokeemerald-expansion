#include "global.h"
#include "test/battle.h"



DOUBLE_BATTLE_TEST("Battler end turn effects are done per battler for each state")
{
    KNOWN_FAILING; // Passes in isolation. It does not pass when running in a batch because Charizard is not dynamixing
    GIVEN {
        PLAYER(SPECIES_VENUSAUR);
        PLAYER(SPECIES_CHARIZARD) { GigantamaxFactor(TRUE); }
        OPPONENT(SPECIES_BLASTOISE);
        OPPONENT(SPECIES_WYNAUT);
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_HAIL); MOVE(playerRight, MOVE_EMBER, target: opponentLeft, gimmick: GIMMICK_DYNAMAX); }
        TURN {}

    } SCENE {
        // Turn 1
        MESSAGE("Charizard is pelted by HAIL!");
        HP_BAR(playerRight);
        MESSAGE("Venusaur is pelted by HAIL!");
        HP_BAR(playerLeft);
        MESSAGE("Foe Blastoise is pelted by HAIL!");
        HP_BAR(opponentLeft);
        MESSAGE("Foe Wynaut is pelted by HAIL!");
        HP_BAR(opponentRight);
        MESSAGE("Foe Blastoise is burning up within G-Max Wildfire's flames!");
        HP_BAR(opponentLeft);
        MESSAGE("Foe Wynaut is burning up within G-Max Wildfire's flames!");
        HP_BAR(opponentRight);

        // Turn 2
        MESSAGE("Charizard is pelted by HAIL!");
        HP_BAR(playerRight);
        MESSAGE("Venusaur is pelted by HAIL!");
        HP_BAR(playerLeft);
        MESSAGE("Foe Blastoise is pelted by HAIL!");
        HP_BAR(opponentLeft);
        MESSAGE("Foe Wynaut is pelted by HAIL!");
        HP_BAR(opponentRight);
        MESSAGE("Foe Blastoise is burning up within G-Max Wildfire's flames!");
        HP_BAR(opponentLeft);
        MESSAGE("Foe Wynaut is burning up within G-Max Wildfire's flames!");
        HP_BAR(opponentRight);
   }
}

DOUBLE_BATTLE_TEST("Battler end turn effects are done per battler for each state - Second Test")
{
    GIVEN {
        PLAYER(SPECIES_VENUSAUR) { Speed(1); }
        PLAYER(SPECIES_CHARIZARD) { Speed(2); }
        OPPONENT(SPECIES_BLASTOISE) { Speed(4); }
        OPPONENT(SPECIES_WYNAUT) { Speed(3); }
    } WHEN {
        TURN { MOVE(playerRight, MOVE_HEAT_WAVE); MOVE(playerLeft, MOVE_HAIL); }
        TURN {}

    } SCENE {
        MESSAGE("Foe Blastoise is pelted by HAIL!");
        HP_BAR(opponentLeft);

        MESSAGE("Foe Wynaut is pelted by HAIL!");
        HP_BAR(opponentRight);

        MESSAGE("Charizard is pelted by HAIL!");
        HP_BAR(playerRight);

        MESSAGE("Venusaur is pelted by HAIL!");
        HP_BAR(playerLeft);

        MESSAGE("Foe Blastoise is hurt by its burn!");
        HP_BAR(opponentLeft);

        MESSAGE("Foe Wynaut is hurt by its burn!");
        HP_BAR(opponentRight);
   }
}

DOUBLE_BATTLE_TEST("End Turn Effects Test")
{
    GIVEN {
        PLAYER(SPECIES_WYNAUT)      { Speed(23); MaxHP(300); HP(151); Item(ITEM_ORAN_BERRY); Status1(STATUS1_TOXIC_POISON); }
        PLAYER(SPECIES_WOBBUFFET)   { Speed(2);  MaxHP(300); HP(151); Item(ITEM_ORAN_BERRY); Status1(STATUS1_BURN); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(1);  MaxHP(300); HP(151); Item(ITEM_ORAN_BERRY); Status1(STATUS1_BURN); }
        OPPONENT(SPECIES_WYNAUT)    { Speed(12); MaxHP(300); HP(151); Item(ITEM_ORAN_BERRY); Status1(STATUS1_POISON); }
    } WHEN {
        TURN {}
        TURN {}
        TURN {}
    } SCENE {
   }
}
