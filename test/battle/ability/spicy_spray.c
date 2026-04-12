#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Spicy Spray burns the attacker")
{
    enum Move move;
    PARAMETRIZE { move = MOVE_SCRATCH; }
    PARAMETRIZE { move = MOVE_SWIFT; }
    GIVEN {
        ASSUME(MoveMakesContact(MOVE_SCRATCH));
        ASSUME(!MoveMakesContact(MOVE_SWIFT));
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_SCOVILLAIN) { Item(ITEM_SCOVILLAINITE); }
    } WHEN {
        TURN { MOVE(player, move); }
    } SCENE {
        ABILITY_POPUP(opponent, ABILITY_FLAME_BODY);
        ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_BRN, player);
        MESSAGE("Wobbuffet was burned!");
        STATUS_ICON(player, burn: TRUE);
    }
}
