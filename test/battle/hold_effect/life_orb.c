#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Life Orb activates if it hits a Substitute")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Item(ITEM_LIFE_ORB); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_SUBSTITUTE); MOVE(player, MOVE_TACKLE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SUBSTITUTE, opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_TACKLE, player);
        HP_BAR(player);
        MESSAGE("Wobbuffet was hurt by the Life Orb!");
    }
}
