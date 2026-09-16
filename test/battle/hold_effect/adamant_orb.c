#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(GetItemHoldEffect(ITEM_ADAMANT_ORB) == HOLD_EFFECT_ADAMANT_ORB);
    ASSUME(GetItemHoldEffectParam(ITEM_ADAMANT_ORB) == 20);
}

SINGLE_BATTLE_TEST("Adamant Orb boosts Dialga's Dragon- and Steel-type move damage by 20%", s16 damage)
{
    enum Item item;
    enum Move move;

    PARAMETRIZE { item = ITEM_NONE;        move = MOVE_DRAGON_CLAW; }
    PARAMETRIZE { item = ITEM_ADAMANT_ORB; move = MOVE_DRAGON_CLAW; }
    PARAMETRIZE { item = ITEM_NONE;        move = MOVE_FLASH_CANNON; }
    PARAMETRIZE { item = ITEM_ADAMANT_ORB; move = MOVE_FLASH_CANNON; }

    GIVEN {
        ASSUME(GetMoveType(MOVE_DRAGON_CLAW) == TYPE_DRAGON);
        ASSUME(GetMoveType(MOVE_FLASH_CANNON) == TYPE_STEEL);
        PLAYER(SPECIES_DIALGA) { Item(item); Moves(move); }
        OPPONENT(SPECIES_WOBBUFFET);
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
