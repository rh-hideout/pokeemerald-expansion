#include "global.h"
#include "test/battle.h"



SINGLE_BATTLE_TEST("Shock Threads lowers foe HP when their stats drop")
{

    GIVEN {
        PLAYER(SPECIES_GALVANTULA) { Ability(ABILITY_LIGHTNING_CHARGE);}
        OPPONENT(SPECIES_WOBBUFFET) ;
    } WHEN {
        TURN { MOVE(player, MOVE_GROWL); }
    } SCENE {
         {
            ANIMATION(ANIM_TYPE_MOVE, MOVE_GROWL, player);
            ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, opponent);
        }

    }
}

