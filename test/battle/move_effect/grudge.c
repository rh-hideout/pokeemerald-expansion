#include "global.h"
#include "test/battle.h"

TO_DO_BATTLE_TEST("TODO: Write Grudge (Move Effect) test titles")

SINGLE_BATTLE_TEST("Dynamax: Dynamaxed Pokemon are affected by Grudge")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Speed(50); };
        OPPONENT(SPECIES_WOBBUFFET) { HP(1); Speed(100); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_GRUDGE); MOVE(player, MOVE_SCRATCH, gimmick: GIMMICK_DYNAMAX); }
    } SCENE {
        MESSAGE("The opposing Wobbuffet used Grudge!");
        MESSAGE("Wobbuffet used Max Strike!");
        MESSAGE("Wobbuffet's Scratch lost all its PP due to the grudge!");
        MESSAGE("The opposing Wobbuffet fainted!");
    }
}
