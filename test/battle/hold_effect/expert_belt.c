#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(GetItemHoldEffect(ITEM_EXPERT_BELT) == HOLD_EFFECT_EXPERT_BELT);
    ASSUME(GetItemHoldEffectParam(ITEM_EXPERT_BELT) == 20);
}

SINGLE_BATTLE_TEST("Expert Belt boosts damage of 2x and 4x super-effective moves by 20%", s16 damage)
{
    enum Item item;
    enum Species species;

    PARAMETRIZE { item = ITEM_NONE;        species = SPECIES_VULPIX; }
    PARAMETRIZE { item = ITEM_EXPERT_BELT; species = SPECIES_VULPIX; }
    PARAMETRIZE { item = ITEM_NONE;        species = SPECIES_GEODUDE; }
    PARAMETRIZE { item = ITEM_EXPERT_BELT; species = SPECIES_GEODUDE; }

    GIVEN {
        ASSUME(GetMoveType(MOVE_WATER_GUN) == TYPE_WATER);
        ASSUME(GetSpeciesType(SPECIES_VULPIX, 0) == TYPE_FIRE);
        ASSUME(GetSpeciesType(SPECIES_GEODUDE, 0) == TYPE_ROCK);
        ASSUME(GetSpeciesType(SPECIES_GEODUDE, 1) == TYPE_GROUND);
        PLAYER(SPECIES_WOBBUFFET) { SpAttack(100); Item(item); }
        OPPONENT(species) { SpDefense(200); }
    } WHEN {
        TURN { MOVE(player, MOVE_WATER_GUN); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_WATER_GUN, player);
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_MUL_EQ(results[0].damage, Q_4_12(1.2), results[1].damage);
        EXPECT_MUL_EQ(results[2].damage, Q_4_12(1.2), results[3].damage);
    }
}

SINGLE_BATTLE_TEST("Expert Belt does not boost neutral or resisted damage", s16 damage)
{
    enum Item item;
    enum Species species;

    PARAMETRIZE { item = ITEM_NONE;        species = SPECIES_WOBBUFFET; }
    PARAMETRIZE { item = ITEM_EXPERT_BELT; species = SPECIES_WOBBUFFET; }
    PARAMETRIZE { item = ITEM_NONE;        species = SPECIES_BULBASAUR; }
    PARAMETRIZE { item = ITEM_EXPERT_BELT; species = SPECIES_BULBASAUR; }

    GIVEN {
        ASSUME(GetMoveType(MOVE_WATER_GUN) == TYPE_WATER);
        ASSUME(GetSpeciesType(SPECIES_WOBBUFFET, 0) == TYPE_PSYCHIC);
        ASSUME(GetSpeciesType(SPECIES_BULBASAUR, 0) == TYPE_GRASS);
        PLAYER(SPECIES_WOBBUFFET) { SpAttack(100); Item(item); }
        OPPONENT(species) { SpDefense(200); }
    } WHEN {
        TURN { MOVE(player, MOVE_WATER_GUN); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_WATER_GUN, player);
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_EQ(results[0].damage, results[1].damage);
        EXPECT_EQ(results[2].damage, results[3].damage);
    }
}
