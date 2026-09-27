#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(GetItemHoldEffect(ITEM_ICY_ROCK) == HOLD_EFFECT_ICY_ROCK);
    ASSUME(GetMoveEffect(MOVE_HAIL) == EFFECT_WEATHER);
    ASSUME(GetMoveEffect(MOVE_SNOWSCAPE) == EFFECT_WEATHER);
    ASSUME(GetMoveEffect(MOVE_CHILLY_RECEPTION) == EFFECT_WEATHER_AND_SWITCH);
}

#if B_PREFERRED_ICE_WEATHER != B_ICE_WEATHER_SNOW
SINGLE_BATTLE_TEST("Icy Rock extends hail created by compatible moves to 8 turns")
{
    enum Move move;

    PARAMETRIZE { move = MOVE_HAIL; }
    if (GetConfig(B_PREFERRED_ICE_WEATHER) == B_ICE_WEATHER_HAIL) {
        PARAMETRIZE { move = MOVE_SNOWSCAPE; }
        PARAMETRIZE { move = MOVE_CHILLY_RECEPTION; }
    }

    GIVEN {
        PLAYER(SPECIES_GLACEON) { Item(ITEM_ICY_ROCK); }
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_GLACEON);
    } WHEN {
        if (move == MOVE_CHILLY_RECEPTION)
            TURN { MOVE(player, move); SEND_OUT(player, 1); }
        else
            TURN { MOVE(player, move); }
        TURN {}
        TURN {}
        TURN {}
        TURN {}
        TURN {}
        TURN {}
        TURN {}
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, move, player);
        MESSAGE("It started to hail!");
        MESSAGE("The hail is crashing down.");
        MESSAGE("The hail is crashing down.");
        MESSAGE("The hail is crashing down.");
        MESSAGE("The hail is crashing down.");
        MESSAGE("The hail is crashing down.");
        MESSAGE("The hail is crashing down.");
        MESSAGE("The hail is crashing down.");
        MESSAGE("The hail stopped.");
    }
}
#endif

#if B_PREFERRED_ICE_WEATHER != B_ICE_WEATHER_HAIL
SINGLE_BATTLE_TEST("Icy Rock extends snow created by compatible moves to 8 turns")
{
    enum Move move;

    if (GetConfig(B_PREFERRED_ICE_WEATHER) == B_ICE_WEATHER_SNOW) {
        PARAMETRIZE { move = MOVE_HAIL; }
    }
    PARAMETRIZE { move = MOVE_SNOWSCAPE; }
    PARAMETRIZE { move = MOVE_CHILLY_RECEPTION; }

    GIVEN {
        PLAYER(SPECIES_GLACEON) { Item(ITEM_ICY_ROCK); }
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_GLACEON);
    } WHEN {
        if (move == MOVE_CHILLY_RECEPTION)
            TURN { MOVE(player, move); SEND_OUT(player, 1); }
        else
            TURN { MOVE(player, move); }
        TURN {}
        TURN {}
        TURN {}
        TURN {}
        TURN {}
        TURN {}
        TURN {}
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, move, player);
        MESSAGE("It started to snow!");
        MESSAGE("Snow continues to fall.");
        MESSAGE("Snow continues to fall.");
        MESSAGE("Snow continues to fall.");
        MESSAGE("Snow continues to fall.");
        MESSAGE("Snow continues to fall.");
        MESSAGE("Snow continues to fall.");
        MESSAGE("Snow continues to fall.");
        MESSAGE("The snow stopped.");
    }
}
#endif
