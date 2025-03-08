#include "global.h"
#include "test/battle.h"

DOUBLE_BATTLE_TEST("End Turn Effects: First Event Block is executed correctly")
{
    GIVEN {
        PLAYER(SPECIES_WYNAUT) { HP(100); Speed(1); }
        PLAYER(SPECIES_EKANS) { HP(100); Ability(ABILITY_SHED_SKIN); Status1(STATUS1_BURN); Speed(2); }
        OPPONENT(SPECIES_WYNAUT) { HP(100); Item(ITEM_LEFTOVERS); Speed(3); }
        OPPONENT(SPECIES_WOBBUFFET) { HP(100); Item(ITEM_BLACK_SLUDGE); Speed(4); }
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_GRASSY_TERRAIN); }
    } SCENE {
        MESSAGE("The opposing Wobbuffet is healed by the grassy terrain!");
        MESSAGE("The opposing Wobbuffet was hurt by the Black Sludge!");
        MESSAGE("The opposing Wynaut is healed by the grassy terrain!");
        MESSAGE("The opposing Wynaut restored a little HP using its Leftovers!");
        MESSAGE("Ekans is healed by the grassy terrain!");
        MESSAGE("Ekans's Shed Skin cured its burn problem!");
        MESSAGE("Wynaut is healed by the grassy terrain!");
    }
}

