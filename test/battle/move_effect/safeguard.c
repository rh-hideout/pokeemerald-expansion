#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
        ASSUME(GetMoveEffect(MOVE_SAFEGUARD) == EFFECT_SAFEGUARD);
}

SINGLE_BATTLE_TEST("Safeguard prevents paralysis")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_THUNDER_WAVE) == EFFECT_NON_VOLATILE_STATUS);
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_SAFEGUARD); MOVE(player, MOVE_THUNDER_WAVE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SAFEGUARD, opponent);
        NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_THUNDER_WAVE, player);
        MESSAGE("The opposing Wobbuffet is protected by Safeguard!");
    }
}
