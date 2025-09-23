#include "global.h"
#include "test/battle.h"



DOUBLE_BATTLE_TEST("ESP Waves causes single target status moves to hit both opponents in a double battle")
{

    GIVEN {
        PLAYER(SPECIES_DOTTLER) { Ability(ABILITY_ESP_WAVES);}
        PLAYER(SPECIES_CRAWDAUNT);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WYNAUT);
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_GROWL, target: opponentLeft);}
    } SCENE {
         {
            ANIMATION(ANIM_TYPE_MOVE, MOVE_GROWL, playerLeft);
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponentLeft);
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponentRight);
        }

    }
}