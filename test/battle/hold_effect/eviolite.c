#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(gItemsInfo[ITEM_EVIOLITE].holdEffect == HOLD_EFFECT_EVIOLITE);
}

SINGLE_BATTLE_TEST("Eviolite boosts Defense for unevolved Pokemon", s16 damage)
{
    u32 item;

    PARAMETRIZE { item = ITEM_EVIOLITE; }
    PARAMETRIZE { item = ITEM_NONE; }

    GIVEN {
        ASSUME(GetMoveCategory(MOVE_SCRATCH) == DAMAGE_CATEGORY_PHYSICAL);
        PLAYER(SPECIES_PIKACHU) { Item(item); }
        OPPONENT(SPECIES_MAGIKARP) { Moves(MOVE_SCRATCH); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_SCRATCH); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, opponent);
        HP_BAR(player, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_MUL_EQ(results[0].damage, Q_4_12(1.5), results[1].damage);
    }
}

SINGLE_BATTLE_TEST("Eviolite boosts Sp. Def for unevolved Pokemon", s16 damage)
{
    u32 item;

    PARAMETRIZE { item = ITEM_EVIOLITE; }
    PARAMETRIZE { item = ITEM_NONE; }

    GIVEN {
        ASSUME(GetMoveCategory(MOVE_WATER_GUN) == DAMAGE_CATEGORY_SPECIAL);
        PLAYER(SPECIES_PIKACHU) { Item(item); }
        OPPONENT(SPECIES_MAGIKARP) { Moves(MOVE_WATER_GUN); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_WATER_GUN); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_WATER_GUN, opponent);
        HP_BAR(player, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_MUL_EQ(results[0].damage, Q_4_12(1.5), results[1].damage);
    }
}

SINGLE_BATTLE_TEST("Eviolite uses original species after Transform", s16 damage)
{
    u32 item;

    PARAMETRIZE { item = ITEM_EVIOLITE; }
    PARAMETRIZE { item = ITEM_NONE; }

    GIVEN {
        ASSUME(GetMoveEffect(MOVE_TRANSFORM) == EFFECT_TRANSFORM);
        PLAYER(SPECIES_PIKACHU) { Item(item); Moves(MOVE_TRANSFORM, MOVE_CELEBRATE); }
        OPPONENT(SPECIES_GYARADOS) { Moves(MOVE_SCRATCH, MOVE_CELEBRATE); }
    } WHEN {
        TURN { MOVE(player, MOVE_TRANSFORM); MOVE(opponent, MOVE_CELEBRATE); }
        TURN { MOVE(player, MOVE_CELEBRATE); MOVE(opponent, MOVE_SCRATCH); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_TRANSFORM, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, opponent);
        HP_BAR(player, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_MUL_EQ(results[0].damage, Q_4_12(1.5), results[1].damage);
    }
}
