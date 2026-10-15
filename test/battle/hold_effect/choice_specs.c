#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(GetItemHoldEffect(ITEM_CHOICE_SPECS) == HOLD_EFFECT_CHOICE_SPECS);
}

SINGLE_BATTLE_TEST("Choice Specs boost special damage by 50%", s16 damage)
{
    enum Item item;

    PARAMETRIZE { item = ITEM_NONE; }
    PARAMETRIZE { item = ITEM_CHOICE_SPECS; }

    GIVEN {
        ASSUME(GetMoveCategory(MOVE_WATER_GUN) == DAMAGE_CATEGORY_SPECIAL);
        PLAYER(SPECIES_WOBBUFFET) { Item(item); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_WATER_GUN); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_WATER_GUN, player);
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_MUL_EQ(results[0].damage, Q_4_12(1.5), results[1].damage);
    }
}

SINGLE_BATTLE_TEST("Choice Specs force Struggle when their locked move becomes unusable")
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
        PLAYER(SPECIES_WOBBUFFET) { Speed(2); Item(ITEM_CHOICE_SPECS); Moves(selectedMove); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(1); }
    } WHEN {
        TURN { MOVE(player, selectedMove); MOVE(opponent, restrictingMove); }
        TURN { FORCED_MOVE(player); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_STRUGGLE, player);
    }
}

SINGLE_BATTLE_TEST("Magic Room and Embargo remove Choice Specs' move lock")
{
    enum Move setupMove;

    PARAMETRIZE { setupMove = MOVE_MAGIC_ROOM; }
    PARAMETRIZE { setupMove = MOVE_EMBARGO; }

    GIVEN {
        ASSUME(GetMoveEffect(MOVE_MAGIC_ROOM) == EFFECT_MAGIC_ROOM);
        ASSUME(GetMoveEffect(MOVE_EMBARGO) == EFFECT_EMBARGO);
        PLAYER(SPECIES_WOBBUFFET) { Speed(2); Item(ITEM_CHOICE_SPECS); Moves(MOVE_SCRATCH, MOVE_WATER_GUN); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(1); }
    } WHEN {
        TURN { MOVE(player, MOVE_SCRATCH); MOVE(opponent, setupMove); }
        TURN { MOVE(player, MOVE_WATER_GUN); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_WATER_GUN, player);
    } THEN {
        EXPECT_EQ(player->item, ITEM_CHOICE_SPECS);
    }
}
