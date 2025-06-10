#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(GetMoveEffect(MOVE_CALM_MIND) == EFFECT_CALM_MIND);
}

SINGLE_BATTLE_TEST("Calm Mind increases the user's Sp. Attack and Sp. Defense by 1 stage each")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_CALM_MIND); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CALM_MIND, player);
        MESSAGE("Wobbuffet's Sp. Atk rose!");
        MESSAGE("Wobbuffet's Sp. Def rose!");
    }
}
