#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Eviolite only boosts based on the original species", s16 damage)
{
    u16 species;
    enum Ability ability;
    enum Item item;
    PARAMETRIZE { species = SPECIES_WYNAUT; ability = ABILITY_NONE; item = ITEM_EVIOLITE; }
    PARAMETRIZE { species = SPECIES_DITTO; ability = ABILITY_IMPOSTER; item = ITEM_EVIOLITE; }

    GIVEN {
        PLAYER(SPECIES_WYNAUT) { Moves(MOVE_CELEBRATE, MOVE_PURSUIT); }
        OPPONENT(species) { Moves(MOVE_CELEBRATE); Ability(ability); Item(item); };
    } WHEN {
        TURN { MOVE(player, MOVE_PURSUIT); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_PURSUIT, player);
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_LE(results[0].damage, results[1].damage);
    }
}
