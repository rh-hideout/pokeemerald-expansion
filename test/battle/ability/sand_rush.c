#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Sand Rush prevents damage from sandstorm")
{
    GIVEN {
        PLAYER(SPECIES_STOUTLAND) { Ability(ABILITY_SAND_RUSH); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_SANDSTORM); }
    } SCENE {
        NOT HP_BAR(player);
    }
}

SINGLE_BATTLE_TEST("Sand Rush doubles speed from sandstorm")
{
    GIVEN {
        PLAYER(SPECIES_SANDSLASH) { Ability(ABILITY_SAND_RUSH); Speed(100); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(199); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_CELEBRATE); MOVE(player, MOVE_SANDSTORM); }
        TURN { MOVE(player, MOVE_CELEBRATE); MOVE(opponent, MOVE_CELEBRATE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SANDSTORM, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, opponent);
    }
}

SINGLE_BATTLE_TEST("Sand Rush doesn't double speed if Cloud Nine/Air Lock is on the field")
{
    GIVEN {
        PLAYER(SPECIES_SANDSLASH) { Ability(ABILITY_SAND_RUSH); Speed(100); }
        OPPONENT(SPECIES_GOLDUCK) { Speed(199); Ability(ABILITY_CLOUD_NINE); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_CELEBRATE); MOVE(player, MOVE_SANDSTORM); }
        TURN { MOVE(opponent, MOVE_CELEBRATE); MOVE(player, MOVE_CELEBRATE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SANDSTORM, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, player);
    }
}
