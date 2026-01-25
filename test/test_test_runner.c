#include "global.h"
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
        MULTI_PLAYER(SPECIES_WOBBUFFET);
        MULTI_PARTNER(SPECIES_WOBBUFFET);
        MULTI_PARTNER(SPECIES_NINETALES_ALOLA) { Ability(ABILITY_DRIZZLE); }
        MULTI_OPPONENT_A(SPECIES_WOBBUFFET);
        MULTI_OPPONENT_A(SPECIES_NINETALES_ALOLA) { Ability(ABILITY_SAND_STREAM); }
        MULTI_OPPONENT_B(SPECIES_WYNAUT);
        MULTI_OPPONENT_B(SPECIES_NINETALES_ALOLA) { Ability(ABILITY_DROUGHT); }
    } WHEN {
        TURN { SWITCH(opponentLeft, 1); SWITCH(playerRight, 4); SWITCH(opponentRight, 4); }
    } SCENE {
        ABILITY_POPUP(opponentLeft, ABILITY_SAND_STREAM);
        ABILITY_POPUP(playerRight, ABILITY_DRIZZLE);
        ABILITY_POPUP(opponentRight, ABILITY_DROUGHT);
    }
}
