#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(GetMoveEffect(MOVE_BULK_UP) == EFFECT_BULK_UP);
}

SINGLE_BATTLE_TEST("Bulk Up increases the user's Attack and Defense by 1 stage each")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_BULK_UP); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_BULK_UP, player);
        MESSAGE("Wobbuffet's Attack rose!");
        MESSAGE("Wobbuffet's Defense rose!");
    }
}
