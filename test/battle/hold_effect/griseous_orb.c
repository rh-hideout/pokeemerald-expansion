#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(GetItemHoldEffect(ITEM_GRISEOUS_ORB) == HOLD_EFFECT_GRISEOUS_ORB);
    ASSUME(GetItemHoldEffectParam(ITEM_GRISEOUS_ORB) == 20);
}

SINGLE_BATTLE_TEST("Griseous Orb boosts Giratina's Ghost- and Dragon-type move damage by 20%", s16 damage)
{
    enum Item item;
    enum Move move;

    PARAMETRIZE { item = ITEM_NONE;         move = MOVE_SHADOW_CLAW; }
    PARAMETRIZE { item = ITEM_GRISEOUS_ORB; move = MOVE_SHADOW_CLAW; }
    PARAMETRIZE { item = ITEM_NONE;         move = MOVE_DRAGON_BREATH; }
    PARAMETRIZE { item = ITEM_GRISEOUS_ORB; move = MOVE_DRAGON_BREATH; }

    GIVEN {
        ASSUME(GetMoveType(MOVE_SHADOW_CLAW) == TYPE_GHOST);
        ASSUME(GetMoveType(MOVE_DRAGON_BREATH) == TYPE_DRAGON);
        PLAYER(SPECIES_GIRATINA) { Attack(100); SpAttack(100); Item(item); Moves(move); }
        OPPONENT(SPECIES_WOBBUFFET) { Defense(200); SpDefense(200); }
    } WHEN {
        TURN { MOVE(player, move); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, move, player);
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_MUL_EQ(results[0].damage, Q_4_12(1.2), results[1].damage);
        EXPECT_MUL_EQ(results[2].damage, Q_4_12(1.2), results[3].damage);
    }
}
