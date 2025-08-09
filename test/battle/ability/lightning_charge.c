#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Lightning Charge doubles speed when using a piercing move")
{
    GIVEN {
        ASSUME(gMovesInfo[MOVE_MEGAHORN].piercingMove);
        PLAYER(SPECIES_ESCAVALIER) { Ability(ABILITY_LIGHTNING_CHARGE);  Speed(45);}
        OPPONENT(SPECIES_WOBBUFFET) { Speed(40);};
    } WHEN {
        TURN { MOVE(player, MOVE_MEGAHORN); MOVE(opponent, MOVE_CELEBRATE);}
    } SCENE {
         {
            ANIMATION(ANIM_TYPE_MOVE, MOVE_MEGAHORN, player);
            ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, opponent);
        }

    }
}