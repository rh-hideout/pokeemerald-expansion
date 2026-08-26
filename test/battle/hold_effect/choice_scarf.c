#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(GetItemHoldEffect(ITEM_CHOICE_SCARF) == HOLD_EFFECT_CHOICE_SCARF);
}

SINGLE_BATTLE_TEST("Choice Scarf boosts Speed by 50%")
{
    enum Item item;
    u32 opponentSpeed;
    bool32 playerFirst;

    PARAMETRIZE { item = ITEM_NONE;         opponentSpeed = 149; playerFirst = FALSE; }
    PARAMETRIZE { item = ITEM_CHOICE_SCARF; opponentSpeed = 149; playerFirst = TRUE;  }
    PARAMETRIZE { item = ITEM_CHOICE_SCARF; opponentSpeed = 151; playerFirst = FALSE; }

    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Speed(100); Item(item); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(opponentSpeed); }
    } WHEN {
        TURN { MOVE(player, MOVE_SCRATCH); MOVE(opponent, MOVE_SCRATCH); }
    } SCENE {
        if (playerFirst) {
            ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, player);
            HP_BAR(opponent);
            ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, opponent);
            HP_BAR(player);
        } else {
            ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, opponent);
            HP_BAR(player);
            ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, player);
            HP_BAR(opponent);
        }
    }
}

SINGLE_BATTLE_TEST("Choice Scarf forces Struggle when its locked move becomes unusable")
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
        PLAYER(SPECIES_WOBBUFFET) { Speed(2); Item(ITEM_CHOICE_SCARF); Moves(selectedMove); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(1); }
    } WHEN {
        TURN { MOVE(player, selectedMove); MOVE(opponent, restrictingMove); }
        TURN { FORCED_MOVE(player); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_STRUGGLE, player);
    }
}

SINGLE_BATTLE_TEST("Magic Room and Embargo remove Choice Scarf's move lock")
{
    enum Move setupMove;

    PARAMETRIZE { setupMove = MOVE_MAGIC_ROOM; }
    PARAMETRIZE { setupMove = MOVE_EMBARGO; }

    GIVEN {
        ASSUME(GetMoveEffect(MOVE_MAGIC_ROOM) == EFFECT_MAGIC_ROOM);
        ASSUME(GetMoveEffect(MOVE_EMBARGO) == EFFECT_EMBARGO);
        PLAYER(SPECIES_WOBBUFFET) { Speed(2); Item(ITEM_CHOICE_SCARF); Moves(MOVE_SCRATCH, MOVE_WATER_GUN); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(1); }
    } WHEN {
        TURN { MOVE(player, MOVE_SCRATCH); MOVE(opponent, setupMove); }
        TURN { MOVE(player, MOVE_WATER_GUN); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_WATER_GUN, player);
    } THEN {
        EXPECT_EQ(player->item, ITEM_CHOICE_SCARF);
    }
}
