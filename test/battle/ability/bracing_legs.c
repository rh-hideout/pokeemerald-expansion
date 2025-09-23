#include "global.h"
#include "test/battle.h"



SINGLE_BATTLE_TEST("Bracing Legs increases the priority of status moves")
{

    GIVEN {
        PLAYER(SPECIES_SIZZLIPEDE) { Speed(5); Ability(ABILITY_BRACING_LEGS);}
        OPPONENT(SPECIES_WOBBUFFET) { Speed(90);};
    } WHEN {
        TURN { MOVE(player, MOVE_HARDEN); MOVE(opponent, MOVE_CELEBRATE);}
    } SCENE {
         {
            ANIMATION(ANIM_TYPE_MOVE, MOVE_HARDEN, player);
            ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, opponent);
        }

    }
}

SINGLE_BATTLE_TEST("Bracing Legs does not increase the priority of non-self targeting status moves")
{

    GIVEN {
        PLAYER(SPECIES_SIZZLIPEDE) { Speed(5); Ability(ABILITY_BRACING_LEGS);}
        OPPONENT(SPECIES_WOBBUFFET) { Speed(90);};
    } WHEN {
        TURN { MOVE(player, MOVE_GROWL); MOVE(opponent, MOVE_CELEBRATE);}
    } SCENE {
         {
            ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, opponent);
            ANIMATION(ANIM_TYPE_MOVE, MOVE_GROWL, player);
        }
    }
}