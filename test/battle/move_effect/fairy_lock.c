#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(GetMoveEffect(MOVE_FAIRY_LOCK) == EFFECT_FAIRY_LOCK);
}

DOUBLE_BATTLE_TEST("Fairy Lock prevents all Pokémon from switching out on their next turn")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_FAIRY_LOCK); }
    } THEN {
        EXPECT_EQ(CanBattlerEscape(GetBattlerAtPosition(B_POSITION_PLAYER_LEFT)), FALSE);
        EXPECT_EQ(CanBattlerEscape(GetBattlerAtPosition(B_POSITION_PLAYER_RIGHT)), FALSE);
        EXPECT_EQ(CanBattlerEscape(GetBattlerAtPosition(B_POSITION_OPPONENT_LEFT)), FALSE);
        EXPECT_EQ(CanBattlerEscape(GetBattlerAtPosition(B_POSITION_OPPONENT_RIGHT)), FALSE);
    }
}

SINGLE_BATTLE_TEST("Fairy Lock does not prevent switch out via Dragon Tail")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_DRAGON_TAIL) == EFFECT_HIT_SWITCH_TARGET);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WYNAUT);
    } WHEN {
        TURN { MOVE(player, MOVE_FAIRY_LOCK); }
        TURN { MOVE(player, MOVE_DRAGON_TAIL); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_DRAGON_TAIL, player);
        MESSAGE("The opposing Wynaut was dragged out!");
    } THEN {
        EXPECT_EQ(opponent->species, SPECIES_WYNAUT);
    }
}

SINGLE_BATTLE_TEST("Fairy Lock does not prevent switch out via Whirlwind")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_WHIRLWIND) == EFFECT_ROAR);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WYNAUT);
    } WHEN {
        TURN { MOVE(player, MOVE_FAIRY_LOCK); }
        TURN { MOVE(player, MOVE_WHIRLWIND); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_WHIRLWIND, player);
        MESSAGE("The opposing Wynaut was dragged out!");
    } THEN {
        EXPECT_EQ(opponent->species, SPECIES_WYNAUT);
    }
}

SINGLE_BATTLE_TEST("Fairy Lock does not prevent switch out via Eject Button")
{
    GIVEN {
        ASSUME(gItemsInfo[ITEM_EJECT_BUTTON].holdEffect == HOLD_EFFECT_EJECT_BUTTON);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET) { Item(ITEM_EJECT_BUTTON); }
        OPPONENT(SPECIES_WYNAUT);
    } WHEN {
        TURN { MOVE(player, MOVE_FAIRY_LOCK); }
        TURN { MOVE(player, MOVE_SCRATCH); SEND_OUT(opponent, 1); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, player);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_EFFECT, opponent);
        MESSAGE("The opposing Wobbuffet is switched out with the Eject Button!");
        MESSAGE("2 sent out Wynaut!");
    } THEN {
        EXPECT_EQ(opponent->species, SPECIES_WYNAUT);
    }
}

SINGLE_BATTLE_TEST("Fairy Lock does not prevent switch out via Red Card")
{
    GIVEN {
        ASSUME(gItemsInfo[ITEM_RED_CARD].holdEffect == HOLD_EFFECT_RED_CARD);
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_WOBBUFFET) { Item(ITEM_RED_CARD); }
    } WHEN {
        TURN { MOVE(player, MOVE_FAIRY_LOCK); }
        TURN { MOVE(player, MOVE_SCRATCH); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, player);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_EFFECT, opponent);
        MESSAGE("The opposing Wobbuffet held up its Red Card against Wobbuffet!");
        MESSAGE("Wynaut was dragged out!");
    } THEN {
        EXPECT_EQ(player->species, SPECIES_WYNAUT);
        EXPECT_EQ(opponent->item, ITEM_NONE);
    }
}

SINGLE_BATTLE_TEST("Fairy Lock prevents a replacement for a fainted Pokémon from switching out on the following turn")
{
    GIVEN {
        PLAYER(SPECIES_KLEFKI) { HP(1); Speed(3); }
        PLAYER(SPECIES_WYNAUT) { Speed(2); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(1); }
    } WHEN {
        TURN { MOVE(player, MOVE_FAIRY_LOCK); MOVE(opponent, MOVE_SCRATCH); SEND_OUT(player, 1); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_FAIRY_LOCK, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, opponent);
        MESSAGE("Klefki fainted!");
        SEND_IN_MESSAGE("Wynaut");
    } THEN {
        EXPECT_EQ(CanBattlerEscape(GetBattlerAtPosition(B_POSITION_PLAYER_LEFT)), FALSE);
    }
}

SINGLE_BATTLE_TEST("Fairy Lock does not prevent switch out via Baton Pass")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_BATON_PASS) == EFFECT_BATON_PASS);
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_FAIRY_LOCK); }
        TURN { MOVE(player, MOVE_BATON_PASS); SEND_OUT(player, 1); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_BATON_PASS, player);
        SEND_IN_MESSAGE("Wynaut");
    } THEN {
        EXPECT_EQ(player->species, SPECIES_WYNAUT);
    }
}
