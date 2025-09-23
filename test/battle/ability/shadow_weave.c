#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(gMovesInfo[MOVE_AERIAL_ACE].category == DAMAGE_CATEGORY_PHYSICAL);
}

DOUBLE_BATTLE_TEST("Shadow Weave causes only the first move to miss in battle")
{

    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WYNAUT)
        OPPONENT(SPECIES_ABRA)
        OPPONENT(SPECIES_KADABRA)
        OPPONENT(SPECIES_NINJASK) { Ability(ABILITY_SHADOW_WEAVE); }
    } WHEN {
        TURN { SWITCH(opponentLeft, 2); }
        TURN { MOVE(playerLeft, MOVE_TACKLE, target: opponentLeft); }
        TURN { MOVE(playerRight, MOVE_HEADBUTT, target: opponentLeft);}
    } SCENE {
        NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_TACKLE, playerLeft);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_HEADBUTT, playerRight);
    }
}