#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(GetItemHoldEffect(ITEM_SMOOTH_ROCK) == HOLD_EFFECT_SMOOTH_ROCK);
    ASSUME(GetMoveEffect(MOVE_SANDSTORM) == EFFECT_WEATHER);
    ASSUME(GetMoveWeatherType(MOVE_SANDSTORM) == BATTLE_WEATHER_SANDSTORM);
}

SINGLE_BATTLE_TEST("Smooth Rock extends sandstorm created by Sandstorm to 8 turns")
{
    GIVEN {
        PLAYER(SPECIES_SANDSLASH) { Item(ITEM_SMOOTH_ROCK); }
        OPPONENT(SPECIES_SANDSLASH);
    } WHEN {
        TURN { MOVE(player, MOVE_SANDSTORM); }
        TURN {}
        TURN {}
        TURN {}
        TURN {}
        TURN {}
        TURN {}
        TURN {}
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SANDSTORM, player);
        MESSAGE("A sandstorm kicked up!");
        MESSAGE("The sandstorm is raging.");
        MESSAGE("The sandstorm is raging.");
        MESSAGE("The sandstorm is raging.");
        MESSAGE("The sandstorm is raging.");
        MESSAGE("The sandstorm is raging.");
        MESSAGE("The sandstorm is raging.");
        MESSAGE("The sandstorm is raging.");
        MESSAGE("The sandstorm subsided.");
    }
}
