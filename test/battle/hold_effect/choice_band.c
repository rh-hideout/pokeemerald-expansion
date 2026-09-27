#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(GetItemHoldEffect(ITEM_CHOICE_BAND) == HOLD_EFFECT_CHOICE_BAND);
}

SINGLE_BATTLE_TEST("Choice Band boosts physical damage by 50%", s16 damage)
{
    enum Item item;

    PARAMETRIZE { item = ITEM_NONE; }
    PARAMETRIZE { item = ITEM_CHOICE_BAND; }

    GIVEN {
        ASSUME(GetMoveCategory(MOVE_SCRATCH) == DAMAGE_CATEGORY_PHYSICAL);
        PLAYER(SPECIES_WOBBUFFET) { Item(item); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_SCRATCH); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, player);
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_MUL_EQ(results[0].damage, Q_4_12(1.5), results[1].damage);
    }
}

SINGLE_BATTLE_TEST("Choice Band forces Struggle when its locked move becomes unusable")
{
    enum Move selectedMove;
    enum Move restrictingMove;

    PARAMETRIZE { selectedMove = MOVE_CELEBRATE; restrictingMove = MOVE_TAUNT; }
    PARAMETRIZE { selectedMove = MOVE_SCRATCH;   restrictingMove = MOVE_TORMENT; }
    PARAMETRIZE { selectedMove = MOVE_SCRATCH;   restrictingMove = MOVE_DISABLE; }

    GIVEN {
        ASSUME(GetMoveEffect(MOVE_TAUNT) == EFFECT_TAUNT);
        ASSUME(GetMoveEffect(MOVE_TORMENT) == EFFECT_TORMENT);
        ASSUME(GetMoveEffect(MOVE_DISABLE) == EFFECT_DISABLE);
        PLAYER(SPECIES_WOBBUFFET) { Speed(2); Item(ITEM_CHOICE_BAND); Moves(selectedMove); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(1); }
    } WHEN {
        TURN { MOVE(player, selectedMove); MOVE(opponent, restrictingMove); }
        TURN { FORCED_MOVE(player); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_STRUGGLE, player);
    }
}

SINGLE_BATTLE_TEST("Magic Room and Embargo remove Choice Band's move lock")
{
    enum Move setupMove;

    PARAMETRIZE { setupMove = MOVE_MAGIC_ROOM; }
    PARAMETRIZE { setupMove = MOVE_EMBARGO; }

    GIVEN {
        ASSUME(GetMoveEffect(MOVE_MAGIC_ROOM) == EFFECT_MAGIC_ROOM);
        ASSUME(GetMoveEffect(MOVE_EMBARGO) == EFFECT_EMBARGO);
        PLAYER(SPECIES_WOBBUFFET) { Speed(2); Item(ITEM_CHOICE_BAND); Moves(MOVE_SCRATCH, MOVE_WATER_GUN); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(1); }
    } WHEN {
        TURN { MOVE(player, MOVE_SCRATCH); MOVE(opponent, setupMove); }
        TURN { MOVE(player, MOVE_WATER_GUN); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_WATER_GUN, player);
    } THEN {
        EXPECT_EQ(player->item, ITEM_CHOICE_BAND);
    }
}
