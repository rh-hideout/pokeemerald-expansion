#include "global.h"
#include "test/battle.h"



SINGLE_BATTLE_TEST("Lightning Charge doubles speed when using a piercing move")
{

    GIVEN {
        PLAYER(SPECIES_ESCAVALIER) { Speed(25); Ability(ABILITY_LIGHTNING_CHARGE);}
        OPPONENT(SPECIES_WOBBUFFET) { Speed(40);};
    } WHEN {
        TURN { MOVE(player, MOVE_CELEBRATE); MOVE(opponent, MOVE_CELEBRATE);}
    } SCENE {
         {
            ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, player);
            ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, opponent);
        }

    }
}

SINGLE_BATTLE_TEST("Lightning Charge only applies to piercing moves")
{

    GIVEN {
        PLAYER(SPECIES_ESCAVALIER) { Speed(25); Ability(ABILITY_LIGHTNING_CHARGE);}
        OPPONENT(SPECIES_WOBBUFFET) { Speed(40);};
    } WHEN {
        TURN { MOVE(player, MOVE_EARTHQUAKE); MOVE(opponent, MOVE_CELEBRATE);}
    } SCENE {
         {
            ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, opponent);
            ANIMATION(ANIM_TYPE_MOVE, MOVE_EARTHQUAKE, player);
        }

    }
}