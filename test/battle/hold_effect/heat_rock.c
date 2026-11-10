#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(GetItemHoldEffect(ITEM_HEAT_ROCK) == HOLD_EFFECT_HEAT_ROCK);
    ASSUME(GetMoveEffect(MOVE_SUNNY_DAY) == EFFECT_WEATHER);
    ASSUME(GetMoveWeatherType(MOVE_SUNNY_DAY) == BATTLE_WEATHER_SUN);
}

SINGLE_BATTLE_TEST("Heat Rock extends sun created by Sunny Day to 8 turns")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Item(ITEM_HEAT_ROCK); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_SUNNY_DAY); }
        TURN {}
        TURN {}
        TURN {}
        TURN {}
        TURN {}
        TURN {}
        TURN {}
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SUNNY_DAY, player);
        MESSAGE("The sunlight turned harsh!");
        MESSAGE("The sunlight is strong.");
        MESSAGE("The sunlight is strong.");
        MESSAGE("The sunlight is strong.");
        MESSAGE("The sunlight is strong.");
        MESSAGE("The sunlight is strong.");
        MESSAGE("The sunlight is strong.");
        MESSAGE("The sunlight is strong.");
        MESSAGE("The sunlight faded.");
    }
}
