#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Rough Skin and Iron Barbs cause the attacker to take damage when using a contact move")
{
    u32 species;
    enum Ability ability;

    PARAMETRIZE { species = SPECIES_GARCHOMP; ability = ABILITY_ROUGH_SKIN; }
    PARAMETRIZE { species = SPECIES_FERROTHORN; ability = ABILITY_IRON_BARBS; }
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(species) { Ability(ability); }
    } WHEN {
        TURN { MOVE(player, MOVE_SCRATCH); }
    } SCENE {
        if (ability == ABILITY_ROUGH_SKIN)
            ABILITY_POPUP(opponent, ABILITY_ROUGH_SKIN);
        else
            ABILITY_POPUP(opponent, ABILITY_IRON_BARBS);
        MESSAGE("Wobbuffet was hurt!");
    }
}
