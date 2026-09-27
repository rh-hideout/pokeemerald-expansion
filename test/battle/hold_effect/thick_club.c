#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(GetItemHoldEffect(ITEM_THICK_CLUB) == HOLD_EFFECT_THICK_CLUB);
}

SINGLE_BATTLE_TEST("Thick Club doubles the physical damage of Cubone and Marowak", s16 damage)
{
    enum Item item;
    enum Species species;

    PARAMETRIZE { item = ITEM_NONE;       species = SPECIES_CUBONE; }
    PARAMETRIZE { item = ITEM_THICK_CLUB; species = SPECIES_CUBONE; }
    PARAMETRIZE { item = ITEM_NONE;       species = SPECIES_MAROWAK; }
    PARAMETRIZE { item = ITEM_THICK_CLUB; species = SPECIES_MAROWAK; }
    PARAMETRIZE { item = ITEM_NONE;       species = SPECIES_MAROWAK_ALOLA; }
    PARAMETRIZE { item = ITEM_THICK_CLUB; species = SPECIES_MAROWAK_ALOLA; }

    GIVEN {
        ASSUME(GetMoveCategory(MOVE_SCRATCH) == DAMAGE_CATEGORY_PHYSICAL);
        PLAYER(species) { Attack(100); Item(item); }
        OPPONENT(SPECIES_WOBBUFFET) { Defense(200); }
    } WHEN {
        TURN { MOVE(player, MOVE_SCRATCH); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, player);
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_MUL_EQ(results[0].damage, Q_4_12(2.0), results[1].damage);
        EXPECT_MUL_EQ(results[2].damage, Q_4_12(2.0), results[3].damage);
        EXPECT_MUL_EQ(results[4].damage, Q_4_12(2.0), results[5].damage);
    }
}

SINGLE_BATTLE_TEST("Thick Club does not boost special moves or unrelated species", s16 damage)
{
    enum Item item;
    enum Move move;
    enum Species species;

    PARAMETRIZE { item = ITEM_NONE;       move = MOVE_ROUND;   species = SPECIES_CUBONE; }
    PARAMETRIZE { item = ITEM_THICK_CLUB; move = MOVE_ROUND;   species = SPECIES_CUBONE; }
    PARAMETRIZE { item = ITEM_NONE;       move = MOVE_SCRATCH; species = SPECIES_WOBBUFFET; }
    PARAMETRIZE { item = ITEM_THICK_CLUB; move = MOVE_SCRATCH; species = SPECIES_WOBBUFFET; }

    GIVEN {
        ASSUME(GetMoveCategory(MOVE_ROUND) == DAMAGE_CATEGORY_SPECIAL);
        ASSUME(GetMoveCategory(MOVE_SCRATCH) == DAMAGE_CATEGORY_PHYSICAL);
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
