#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(!IsBattleMoveStatus(MOVE_WATER_GUN));
    ASSUME(GetMoveType(MOVE_WATER_GUN) == TYPE_WATER);
}

SINGLE_BATTLE_TEST("Desolate Land blocks damaging Water-type moves")
{
    GIVEN {
        PLAYER(SPECIES_GROUDON) {Item(ITEM_RED_ORB);}
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_WATER_GUN); }
        TURN { MOVE(opponent, MOVE_WATER_GUN); }
    } SCENE {
        MESSAGE("The opposing Wobbuffet used Water Gun!");
        NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_WATER_GUN, opponent);
        MESSAGE("The Water-type attack evaporated in the extremely harsh sunlight!");
        NOT HP_BAR(player);
        MESSAGE("The opposing Wobbuffet used Water Gun!");
        NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_WATER_GUN, opponent);
        MESSAGE("The Water-type attack evaporated in the extremely harsh sunlight!");
        NOT HP_BAR(player);
    } THEN {
        EXPECT_EQ(player->hp, player->maxHP);
    }
}

DOUBLE_BATTLE_TEST("Desolate Land blocks damaging Water-type moves and prints the message only once with moves hitting multiple targets")
{
    GIVEN {
        ASSUME(!IsBattleMoveStatus(MOVE_SURF));
        ASSUME(GetMoveType(MOVE_SURF) == TYPE_WATER);
        ASSUME(GetMoveTarget(MOVE_SURF) == MOVE_TARGET_FOES_AND_ALLY);
        PLAYER(SPECIES_GROUDON) {Item(ITEM_RED_ORB); {Speed(5);}}
        PLAYER(SPECIES_WOBBUFFET) {Speed(5);}
        OPPONENT(SPECIES_WOBBUFFET) {Speed(10);}
        OPPONENT(SPECIES_WOBBUFFET) {Speed(8);}
    } WHEN {
        TURN { MOVE(opponentLeft, MOVE_SURF); }
    } SCENE {
        MESSAGE("The opposing Wobbuffet used Surf!");
        NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_SURF, opponentLeft);
        MESSAGE("The Water-type attack evaporated in the extremely harsh sunlight!");
        NOT MESSAGE("The Water-type attack evaporated in the extremely harsh sunlight!");
    } THEN {
        EXPECT_EQ(playerLeft->hp, playerLeft->maxHP);
        EXPECT_EQ(playerRight->hp, playerRight->maxHP);
        EXPECT_EQ(opponentRight->hp, opponentRight->maxHP);
    }
}

SINGLE_BATTLE_TEST("Desolate Land does not block a move if Pokémon is asleep and uses a Water-type move") // Sleep/confusion/paralysis all happen before the check for primal weather
{
    GIVEN {
        PLAYER(SPECIES_GROUDON) {Item(ITEM_RED_ORB);}
        OPPONENT(SPECIES_WOBBUFFET) {Status1(STATUS1_SLEEP);}
    } WHEN {
        TURN { MOVE(opponent, MOVE_WATER_GUN); }
    } SCENE {
        NOT MESSAGE("The Water-type attack evaporated in the extremely harsh sunlight!");
        MESSAGE("The opposing Wobbuffet is fast asleep.");
    }
}

SINGLE_BATTLE_TEST("Desolate Land will not create a softlock when move in semi invulnerable position is blocked")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_GROUDON) { Item(ITEM_RED_ORB); }
    } WHEN {
        TURN { MOVE(player, MOVE_DIVE); }
        TURN { SWITCH(opponent, 1); SKIP_TURN(player); }
        TURN { MOVE(player, MOVE_CELEBRATE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_DIVE, player);
        ABILITY_POPUP(opponent, ABILITY_DESOLATE_LAND);
        NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_DIVE, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, player);
    }
}

SINGLE_BATTLE_TEST("Desolate Land is removed immediately if user faints")
{
    GIVEN {
        PLAYER(SPECIES_GROUDON) { HP(1); Item(ITEM_RED_ORB); }
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_POUND); SEND_OUT(player, 1); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_POUND, opponent);
        NOT MESSAGE("The sunlight is strong.");
        MESSAGE("The extremely harsh sunlight faded!");
    }
}

SINGLE_BATTLE_TEST("Desolate Land makes Sunny Day fail")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_SUNNY_DAY) == EFFECT_SUNNY_DAY);
        PLAYER(SPECIES_GROUDON) { Item(ITEM_RED_ORB); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_SUNNY_DAY); }
    } SCENE {
        MESSAGE("The opposing Wobbuffet used Sunny Day!");
        NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_SUNNY_DAY, opponent);
        MESSAGE("The extremely harsh sunlight was not lessened at all!");
    }
}

SINGLE_BATTLE_TEST("Desolate Land makes Rain Dance fail")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_RAIN_DANCE) == EFFECT_RAIN_DANCE);
        PLAYER(SPECIES_GROUDON) { Item(ITEM_RED_ORB); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_RAIN_DANCE); }
    } SCENE {
        MESSAGE("The opposing Wobbuffet used Rain Dance!");
        NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_RAIN_DANCE, opponent);
        MESSAGE("The extremely harsh sunlight was not lessened at all!");
    }
}

SINGLE_BATTLE_TEST("Desolate Land makes Sandstorm fail")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_SANDSTORM) == EFFECT_SANDSTORM);
        PLAYER(SPECIES_GROUDON) { Item(ITEM_RED_ORB); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_SANDSTORM); }
    } SCENE {
        MESSAGE("The opposing Wobbuffet used Sandstorm!");
        NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_SANDSTORM, opponent);
        MESSAGE("The extremely harsh sunlight was not lessened at all!");
    }
}

SINGLE_BATTLE_TEST("Desolate Land makes Hail fail")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_HAIL) == EFFECT_HAIL);
        PLAYER(SPECIES_GROUDON) { Item(ITEM_RED_ORB); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_HAIL); }
    } SCENE {
        MESSAGE("The opposing Wobbuffet used Hail!");
        NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_HAIL, opponent);
        MESSAGE("The extremely harsh sunlight was not lessened at all!");
    }
}

SINGLE_BATTLE_TEST("Desolate Land makes Snowscape fail") // Extrapolation
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_SNOWSCAPE) == EFFECT_SNOWSCAPE);
        PLAYER(SPECIES_GROUDON) { Item(ITEM_RED_ORB); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_SNOWSCAPE); }
    } SCENE {
        MESSAGE("The opposing Wobbuffet used Snowscape!");
        NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_SNOWSCAPE, opponent);
        MESSAGE("The extremely harsh sunlight was not lessened at all!");
    }
}

SINGLE_BATTLE_TEST("Desolate Land makes Drought fail to activate")
{
    GIVEN {
        PLAYER(SPECIES_GROUDON) { Item(ITEM_RED_ORB); }
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_NINETALES) { Ability(ABILITY_DROUGHT); }
    } WHEN {
        TURN { SWITCH(opponent, 1); }
    } SCENE {
        ABILITY_POPUP(opponent, ABILITY_DROUGHT);
        MESSAGE("The extremely harsh sunlight was not lessened at all!");
    }
}

SINGLE_BATTLE_TEST("Desolate Land makes Drizzle fail to activate")
{
    GIVEN {
        PLAYER(SPECIES_GROUDON) { Item(ITEM_RED_ORB); }
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_POLITOED) { Ability(ABILITY_DRIZZLE); }
    } WHEN {
        TURN { SWITCH(opponent, 1); }
    } SCENE {
        ABILITY_POPUP(opponent, ABILITY_DRIZZLE);
        MESSAGE("The extremely harsh sunlight was not lessened at all!");
    }
}

SINGLE_BATTLE_TEST("Desolate Land makes Sand Stream fail to activate")
{
    GIVEN {
        PLAYER(SPECIES_GROUDON) { Item(ITEM_RED_ORB); }
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_HIPPOWDON) { Ability(ABILITY_SAND_STREAM); }
    } WHEN {
        TURN { SWITCH(opponent, 1); }
    } SCENE {
        ABILITY_POPUP(opponent, ABILITY_SAND_STREAM);
        MESSAGE("The extremely harsh sunlight was not lessened at all!");
    }
}

SINGLE_BATTLE_TEST("Desolate Land makes Snow Warning fail to activate")
{
    GIVEN {
        PLAYER(SPECIES_GROUDON) { Item(ITEM_RED_ORB); }
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_ABOMASNOW) { Ability(ABILITY_SNOW_WARNING); }
    } WHEN {
        TURN { SWITCH(opponent, 1); }
    } SCENE {
        ABILITY_POPUP(opponent, ABILITY_SNOW_WARNING);
        MESSAGE("The extremely harsh sunlight was not lessened at all!");
    }
}

SINGLE_BATTLE_TEST("Desolate Land can be replaced by Delta Stream")
{
    GIVEN {
        PLAYER(SPECIES_GROUDON) { Item(ITEM_RED_ORB); }
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_RAYQUAZA) { Ability(ABILITY_DELTA_STREAM); }
    } WHEN {
        TURN { SWITCH(opponent, 1); }
    } SCENE {
        ABILITY_POPUP(opponent, ABILITY_DELTA_STREAM);
        MESSAGE("Mysterious strong winds are protecting Flying-type Pokémon!");
    } THEN {
        EXPECT(gBattleWeather & B_WEATHER_STRONG_WINDS);
    }
}

SINGLE_BATTLE_TEST("Desolate Land can be replaced by Primordial Sea")
{
    GIVEN {
        PLAYER(SPECIES_GROUDON) { Item(ITEM_RED_ORB); }
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_KYOGRE) { Item(ITEM_BLUE_ORB); }
    } WHEN {
        TURN { SWITCH(opponent, 1); }
    } SCENE {
        ABILITY_POPUP(opponent, ABILITY_PRIMORDIAL_SEA);
        MESSAGE("A heavy rain began to fall!");
    } THEN {
        EXPECT(gBattleWeather & B_WEATHER_RAIN_PRIMAL);
    }
}
