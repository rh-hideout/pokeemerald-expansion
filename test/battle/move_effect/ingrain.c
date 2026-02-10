#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(GetMoveEffect(MOVE_INGRAIN) == EFFECT_INGRAIN);
    ASSUME(GetMoveEffect(MOVE_BATON_PASS) == EFFECT_BATON_PASS);
    ASSUME(gItemsInfo[ITEM_BIG_ROOT].holdEffect == HOLD_EFFECT_BIG_ROOT);
}

TO_DO_BATTLE_TEST("TODO: Write Ingrain (Move Effect) test titles")

SINGLE_BATTLE_TEST("Ingrain restores 1/16th HP at the end of turn")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { HP(50); MaxHP(128); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_INGRAIN); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_INGRAIN, player);
    } THEN {
        EXPECT_EQ(player->hp, 58);
    }
}

SINGLE_BATTLE_TEST("Ingrain restores 30% more HP when holding Big Root")
{
    u32 item;
    u16 expectedHp;
    PARAMETRIZE { item = ITEM_NONE; expectedHp = 58; }
    PARAMETRIZE { item = ITEM_BIG_ROOT; expectedHp = 60; }

    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { HP(50); MaxHP(128); Item(item); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_INGRAIN); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_INGRAIN, player);
    } THEN {
        EXPECT_EQ(player->hp, expectedHp);
    }
}

SINGLE_BATTLE_TEST("Ingrain fails if already rooted")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_INGRAIN); }
        TURN { MOVE(player, MOVE_INGRAIN); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_INGRAIN, player);
        MESSAGE("Wobbuffet planted its roots!");
        NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_INGRAIN, player);
        MESSAGE("But it failed!");
    }
}

SINGLE_BATTLE_TEST("Ingrain prevents the user from switching out")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Moves(MOVE_INGRAIN, MOVE_BATON_PASS); }
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_INGRAIN); }
        TURN { MOVE(player, MOVE_BATON_PASS); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_INGRAIN, player);
        NONE_OF {
            ANIMATION(ANIM_TYPE_MOVE, MOVE_BATON_PASS, player);
            SEND_IN_MESSAGE("Wynaut");
        }
        MESSAGE("But it failed!");
    } THEN {
        EXPECT_EQ(player->species, SPECIES_WOBBUFFET);
    }
}
