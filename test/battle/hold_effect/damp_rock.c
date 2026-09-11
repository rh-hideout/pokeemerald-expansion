#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(GetItemHoldEffect(ITEM_DAMP_ROCK) == HOLD_EFFECT_DAMP_ROCK);
    ASSUME(GetMoveEffect(MOVE_RAIN_DANCE) == EFFECT_WEATHER);
    ASSUME(GetMoveWeatherType(MOVE_RAIN_DANCE) == BATTLE_WEATHER_RAIN);
}

SINGLE_BATTLE_TEST("Damp Rock extends rain created by Rain Dance to 8 turns")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Item(ITEM_DAMP_ROCK); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_RAIN_DANCE); }
        TURN {}
        TURN {}
        TURN {}
        TURN {}
        TURN {}
        TURN {}
        TURN {}
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_RAIN_DANCE, player);
        MESSAGE("It started to rain!");
        MESSAGE("Rain continues to fall.");
        MESSAGE("Rain continues to fall.");
        MESSAGE("Rain continues to fall.");
        MESSAGE("Rain continues to fall.");
        MESSAGE("Rain continues to fall.");
        MESSAGE("Rain continues to fall.");
        MESSAGE("Rain continues to fall.");
        MESSAGE("The rain stopped.");
    }
}
