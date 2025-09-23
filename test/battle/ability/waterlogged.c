#include "global.h"
#include "test/battle.h"



SINGLE_BATTLE_TEST("Waterlogged raises speed in the sun")
{

    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Speed(30);}
        OPPONENT(SPECIES_SURSKIT) { Speed(20);};
    } WHEN {
        TURN { MOVE(player, MOVE_SUNNY_DAY);}
        TURN { MOVE(opponent, MOVE_CELEBRATE);}
        TURN { MOVE(player, MOVE_CELEBRATE);}
        TURN { MOVE(opponent, MOVE_CELEBRATE);}
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SUNNY_DAY);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, player);
    }
}

SINGLE_BATTLE_TEST("Waterlogged halves speed in the rain")
{

    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Speed(30);}
        OPPONENT(SPECIES_SURSKIT) { Speed(40);};
    } WHEN {
        TURN { MOVE(player, MOVE_RAIN_DANCE);}
        TURN { MOVE(opponent, MOVE_CELEBRATE);}
        TURN { MOVE(player, MOVE_CELEBRATE);}
        TURN { MOVE(opponent, MOVE_CELEBRATE);}
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_RAIN_DANCE);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, player);
    }
}

SINGLE_BATTLE_TEST("Waterlogged raises evasion two stages in the rain")
{

    PASSES_RANDOMLY(60, 100, RNG_ACCURACY);
    GIVEN {
        ASSUME(gMovesInfo[MOVE_POUND].accuracy == 100);
        PLAYER(SPECIES_SURSKIT) { Ability(ABILITY_WATERLOGGED); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_RAIN_DANCE); }
        TURN { MOVE(opponent, MOVE_POUND); }
    } SCENE {
        HP_BAR(player);
    }
}