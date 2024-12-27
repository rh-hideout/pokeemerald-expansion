#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(gMovesInfo[MOVE_COSMIC_POWER].effect == EFFECT_COSMIC_POWER);
}

SINGLE_BATTLE_TEST("Cosmic Power increases the user's Defense and Sp. Defense by 1 stage each")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_COSMIC_POWER); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_COSMIC_POWER, player);
        MESSAGE("Wobbuffet's Defense rose!");
        MESSAGE("Wobbuffet's Sp. Def rose!");
    }
}
