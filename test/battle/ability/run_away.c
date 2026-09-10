#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Run Away allows switching out even when trapped by Mean Look")
{
    GIVEN {
        WITH_CONFIG(B_RUN_AWAY, GEN_CHAMPIONS);
        PLAYER(SPECIES_EEVEE) { Ability(ABILITY_RUN_AWAY); }
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_GASTLY);
    } WHEN {
        TURN { MOVE(player, MOVE_CELEBRATE); MOVE(opponent, MOVE_MEAN_LOOK); }
        TURN { SWITCH(player, 1); MOVE(opponent, MOVE_CELEBRATE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_MEAN_LOOK, opponent);
        SWITCH_OUT_MESSAGE("Eevee");
        SEND_IN_MESSAGE("Wynaut");
    }
}

SINGLE_BATTLE_TEST("Run Away allows switching out even when trapped by Shadow Tag")
{
    GIVEN {
        WITH_CONFIG(B_RUN_AWAY, GEN_CHAMPIONS);
        PLAYER(SPECIES_EEVEE) { Ability(ABILITY_RUN_AWAY); }
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_WOBBUFFET) { Ability(ABILITY_SHADOW_TAG); }
    } WHEN {
        TURN { SWITCH(player, 1); MOVE(opponent, MOVE_CELEBRATE); }
    } SCENE {
        SWITCH_OUT_MESSAGE("Eevee");
        SEND_IN_MESSAGE("Wynaut");
    }
}

SINGLE_BATTLE_TEST("Run Away allows switching out even when trapped by Arena Trap")
{
    GIVEN {
        WITH_CONFIG(B_RUN_AWAY, GEN_CHAMPIONS);
        PLAYER(SPECIES_EEVEE) { Ability(ABILITY_RUN_AWAY); } // Grounded
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_DIGLETT) { Ability(ABILITY_ARENA_TRAP); }
    } WHEN {
        TURN { SWITCH(player, 1); MOVE(opponent, MOVE_CELEBRATE); }
    } SCENE {
        SWITCH_OUT_MESSAGE("Eevee");
        SEND_IN_MESSAGE("Wynaut");
    }
}

