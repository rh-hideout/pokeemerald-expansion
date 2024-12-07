#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Liquid Ooze causes leech seedee to faint before seeder")
{
    u16 ability;
    PARAMETRIZE { ability = ABILITY_CLEAR_BODY; }
    PARAMETRIZE { ability = ABILITY_LIQUID_OOZE; }    
    GIVEN {
        PLAYER(SPECIES_BULBASAUR)   { HP(1); }
        OPPONENT(SPECIES_TENTACOOL) { HP(1); Ability(ability); }
    } WHEN {
        TURN { MOVE(player, MOVE_LEECH_SEED); }
    } SCENE {
        MESSAGE("Bulbasaur used Leech Seed!");
        // Drain at end of turn
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_LEECH_SEED_DRAIN, opponent);
        if (ability != ABILITY_LIQUID_OOZE) {
            MESSAGE("Foe Tentacool's health is sapped by LEECH SEED!");
            MESSAGE("Foe Tentacool fainted!");
        } else {
            ABILITY_POPUP(opponent, ABILITY_LIQUID_OOZE);
            MESSAGE("It sucked up the liquid ooze!");
            MESSAGE("Foe Tentacool fainted!");
            MESSAGE("Bulbasaur fainted!");
        }
    }
}
