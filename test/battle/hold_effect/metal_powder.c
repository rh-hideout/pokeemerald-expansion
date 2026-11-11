#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(GetItemHoldEffect(ITEM_METAL_POWDER) == HOLD_EFFECT_METAL_POWDER);
}

SINGLE_BATTLE_TEST("Metal Powder doubles an untransformed Ditto's Defense", s16 damage)
{
    enum Item item;
    enum Move move;

    PARAMETRIZE { item = ITEM_NONE;         move = MOVE_SCRATCH; }
    PARAMETRIZE { item = ITEM_METAL_POWDER; move = MOVE_SCRATCH; }
    PARAMETRIZE { item = ITEM_NONE;         move = MOVE_PSYSHOCK; }
    PARAMETRIZE { item = ITEM_METAL_POWDER; move = MOVE_PSYSHOCK; }

    GIVEN {
        ASSUME(GetMoveCategory(MOVE_SCRATCH) == DAMAGE_CATEGORY_PHYSICAL);
        ASSUME(GetMoveCategory(MOVE_PSYSHOCK) == DAMAGE_CATEGORY_SPECIAL);
        ASSUME(GetMoveEffect(MOVE_PSYSHOCK) == EFFECT_PSYSHOCK);
        PLAYER(SPECIES_WOBBUFFET) { Attack(200); SpAttack(200); Moves(move); }
        OPPONENT(SPECIES_DITTO) { Defense(100); Item(item); }
    } WHEN {
        TURN { MOVE(player, move); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, move, player);
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_MUL_EQ(results[1].damage, Q_4_12(2.0), results[0].damage);
        EXPECT_MUL_EQ(results[3].damage, Q_4_12(2.0), results[2].damage);
    }
}

SINGLE_BATTLE_TEST("Metal Powder does not boost Sp. Def or the Defense of non-Ditto holders", s16 damage)
{
    enum Item item;
    enum Move move;
    enum Species species;

    PARAMETRIZE { item = ITEM_NONE;         move = MOVE_ROUND;   species = SPECIES_DITTO; }
    PARAMETRIZE { item = ITEM_METAL_POWDER; move = MOVE_ROUND;   species = SPECIES_DITTO; }
    PARAMETRIZE { item = ITEM_NONE;         move = MOVE_SCRATCH; species = SPECIES_WOBBUFFET; }
    PARAMETRIZE { item = ITEM_METAL_POWDER; move = MOVE_SCRATCH; species = SPECIES_WOBBUFFET; }

    GIVEN {
        ASSUME(GetMoveCategory(MOVE_ROUND) == DAMAGE_CATEGORY_SPECIAL);
        ASSUME(GetMoveEffect(MOVE_ROUND) != EFFECT_PSYSHOCK);
        ASSUME(GetMoveCategory(MOVE_SCRATCH) == DAMAGE_CATEGORY_PHYSICAL);
        PLAYER(SPECIES_WOBBUFFET) { Attack(100); SpAttack(100); Moves(move); }
        OPPONENT(species) { Defense(200); SpDefense(200); Item(item); }
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

SINGLE_BATTLE_TEST("Metal Powder does not boost Ditto's Defense after it transforms", s16 damage)
{
    enum Item item;

    PARAMETRIZE { item = ITEM_NONE; }
    PARAMETRIZE { item = ITEM_METAL_POWDER; }

    GIVEN {
        ASSUME(GetMoveEffect(MOVE_TRANSFORM) == EFFECT_TRANSFORM);
        PLAYER(SPECIES_DITTO) { Attack(100); Defense(200); Speed(50); Moves(MOVE_CELEBRATE, MOVE_SCRATCH); }
        OPPONENT(SPECIES_DITTO) { Speed(100); Item(item); Moves(MOVE_TRANSFORM); }
    } WHEN {
        TURN { MOVE(player, MOVE_CELEBRATE); MOVE(opponent, MOVE_TRANSFORM); }
        TURN { MOVE(player, MOVE_SCRATCH); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_TRANSFORM, opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, player);
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_EQ(results[0].damage, results[1].damage);
    }
}
