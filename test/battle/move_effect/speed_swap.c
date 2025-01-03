#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(GetMoveEffect(MOVE_SPEED_SWAP) == EFFECT_SPEED_SWAP);
}

SINGLE_BATTLE_TEST("Speed Swap swaps user and target's speed stats")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Speed(6); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(10); }
    }WHEN {
        TURN { MOVE(opponent, MOVE_TACKLE); MOVE(player, MOVE_SPEED_SWAP); }
        TURN { MOVE(opponent, MOVE_TACKLE); MOVE(player, MOVE_TACKLE); }
    } SCENE {
        // Turn 1
        ANIMATION(ANIM_TYPE_MOVE, MOVE_TACKLE, opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SPEED_SWAP, player);
        // Turn 2
        ANIMATION(ANIM_TYPE_MOVE, MOVE_TACKLE, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_TACKLE, opponent);
    } THEN {
        EXPECT_EQ(player->speed, 10);
        EXPECT_EQ(opponent->speed, 6);
    } 
}

SINGLE_BATTLE_TEST("Speed Swap doesn't swap user and target's speed modifiers")
{
    u32 speed, species, ability, move, item;
    PARAMETRIZE { speed = 10, species = SPECIES_WOBBUFFET;    ability = ABILITY_TELEPATHY;    move = MOVE_ROCK_POLISH;      item = ITEM_NONE; }      // x2.0
    PARAMETRIZE { speed = 10, species = SPECIES_PSYDUCK;      ability = ABILITY_SWIFT_SWIM;   move = MOVE_RAIN_DANCE;       item = ITEM_NONE; }      // x2.0
    PARAMETRIZE { speed = 10, species = SPECIES_BULBASAUR;    ability = ABILITY_CHLOROPHYLL;  move = MOVE_SUNNY_DAY;        item = ITEM_NONE; }      // x2.0
    PARAMETRIZE { speed = 10, species = SPECIES_HITMONLEE;    ability = ABILITY_UNBURDEN;     move = MOVE_BESTOW;           item = ITEM_NUGGET; }    // x2.0
    PARAMETRIZE { speed = 10, species = SPECIES_JOLTEON;      ability = ABILITY_QUICK_FEET;   move = MOVE_TACKLE;           item = ITEM_FLAME_ORB; } // x1.5
    PARAMETRIZE { speed = 10, species = SPECIES_DRILBUR;      ability = ABILITY_SAND_RUSH;    move = MOVE_SANDSTORM;        item = ITEM_NONE; }      // x2.0
    PARAMETRIZE { speed = 10, species = SPECIES_CETITAN;      ability = ABILITY_SLUSH_RUSH;   move = MOVE_SNOWSCAPE;        item = ITEM_NONE; }      // x2.0
    PARAMETRIZE { speed = 10, species = SPECIES_RAICHU_ALOLA; ability = ABILITY_SURGE_SURFER; move = MOVE_ELECTRIC_TERRAIN; item = ITEM_NONE; }      // x2.0
    PARAMETRIZE { speed = 18, species = SPECIES_REGIGIGAS;    ability = ABILITY_SLOW_START;   move = MOVE_TACKLE;           item = ITEM_NONE; }      // x0.5
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_ROCK_POLISH) == EFFECT_SPEED_UP_2);
        PLAYER(SPECIES_WOBBUFFET) { Speed(8); }
        OPPONENT(species) { Speed(speed); Ability(ability); Item(item); }
    }WHEN {
        TURN { MOVE(opponent, move); MOVE(player, MOVE_SPEED_SWAP); }
        TURN { MOVE(opponent, MOVE_TACKLE); MOVE(player, MOVE_TACKLE); }
    } SCENE {
        // Turn 1
        ANIMATION(ANIM_TYPE_MOVE, move, opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SPEED_SWAP, player);
        // Turn 2
        if (ability == ABILITY_SLOW_START) {
            ANIMATION(ANIM_TYPE_MOVE, MOVE_TACKLE, player);   // Player is now first
            ANIMATION(ANIM_TYPE_MOVE, MOVE_TACKLE, opponent);
        } else {
            ANIMATION(ANIM_TYPE_MOVE, MOVE_TACKLE, opponent); // Opponent is still first
            ANIMATION(ANIM_TYPE_MOVE, MOVE_TACKLE, player);
        }
    } THEN {
        EXPECT_EQ(player->speed, speed);
        EXPECT_EQ(opponent->speed, 8);
        if (move == MOVE_ROCK_POLISH) {
            EXPECT_EQ(player->statStages[STAT_SPEED], DEFAULT_STAT_STAGE);
            EXPECT_EQ(opponent->statStages[STAT_SPEED], DEFAULT_STAT_STAGE + 2);
        }
    } 
}
