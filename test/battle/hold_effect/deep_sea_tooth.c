#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(GetItemHoldEffect(ITEM_DEEP_SEA_TOOTH) == HOLD_EFFECT_DEEP_SEA_TOOTH);
}

SINGLE_BATTLE_TEST("Deep Sea Tooth doubles Clamperl's special damage", s16 damage)
{
    enum Item item;

    PARAMETRIZE { item = ITEM_NONE; }
    PARAMETRIZE { item = ITEM_DEEP_SEA_TOOTH; }

    GIVEN {
        ASSUME(GetMoveCategory(MOVE_WATER_GUN) == DAMAGE_CATEGORY_SPECIAL);
        PLAYER(SPECIES_CLAMPERL) { SpAttack(100); Item(item); }
        OPPONENT(SPECIES_WOBBUFFET) { SpDefense(200); }
    } WHEN {
        TURN { MOVE(player, MOVE_WATER_GUN); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_WATER_GUN, player);
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_MUL_EQ(results[0].damage, Q_4_12(2.0), results[1].damage);
    }
}

SINGLE_BATTLE_TEST("Deep Sea Tooth does not boost physical moves or non-Clamperl holders", s16 damage)
{
    enum Item item;
    enum Move move;
    enum Species species;

    PARAMETRIZE { item = ITEM_NONE;           move = MOVE_SCRATCH;   species = SPECIES_CLAMPERL; }
    PARAMETRIZE { item = ITEM_DEEP_SEA_TOOTH; move = MOVE_SCRATCH;   species = SPECIES_CLAMPERL; }
    PARAMETRIZE { item = ITEM_NONE;           move = MOVE_WATER_GUN; species = SPECIES_WOBBUFFET; }
    PARAMETRIZE { item = ITEM_DEEP_SEA_TOOTH; move = MOVE_WATER_GUN; species = SPECIES_WOBBUFFET; }

    GIVEN {
        ASSUME(GetMoveCategory(MOVE_SCRATCH) == DAMAGE_CATEGORY_PHYSICAL);
        ASSUME(GetMoveCategory(MOVE_WATER_GUN) == DAMAGE_CATEGORY_SPECIAL);
        PLAYER(species) { Attack(100); SpAttack(100); Item(item); Moves(move); }
        OPPONENT(SPECIES_WOBBUFFET) { Defense(200); SpDefense(200); }
    } WHEN {
        TURN { MOVE(player, move); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, move, player);
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_EQ(results[0].damage, results[1].damage);
        EXPECT_EQ(results[2].damage, results[3].damage);
    }
}
