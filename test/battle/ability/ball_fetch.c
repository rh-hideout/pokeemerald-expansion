#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(gItemsInfo[ITEM_SITRUS_BERRY].holdEffect == HOLD_EFFECT_RESTORE_PCT_HP);
}

WILD_BATTLE_TEST("Ball Fetch causes the Pokémon to pick up a failed Ball at the end of the turn")
{
    enum Item item = ITEM_NONE;

    PARAMETRIZE { item = ITEM_POKE_BALL; }
    PARAMETRIZE { item = ITEM_GREAT_BALL; }
    PARAMETRIZE { item = ITEM_ULTRA_BALL; }
    PARAMETRIZE { item = ITEM_STRANGE_BALL; }
    PARAMETRIZE { item = ITEM_X_ACCURACY; }

    GIVEN {
        PLAYER(SPECIES_YAMPER) { Ability(ABILITY_BALL_FETCH); }
        OPPONENT(SPECIES_METAGROSS);
    } WHEN {
        TURN { USE_ITEM(player, item, WITH_RNG(RNG_BALLTHROW_SHAKE, MAX_u16)); }
        TURN {}
    } SCENE {
        if (item != ITEM_X_ACCURACY)
            ABILITY_POPUP(player, ABILITY_BALL_FETCH);
        else
            NOT ABILITY_POPUP(player, ABILITY_BALL_FETCH);
    } THEN {
        if (item != ITEM_X_ACCURACY)
            EXPECT_EQ(player->item, item);
        else
            EXPECT_EQ(player->item, ITEM_NONE);
    }
}

WILD_BATTLE_TEST("Ball Fetch doesn't trigger if the Pokémon is already holding an item")
{
    enum Item item = ITEM_NONE;

    PARAMETRIZE { item = ITEM_NONE; }
    PARAMETRIZE { item = ITEM_NUGGET; }

    GIVEN {
        PLAYER(SPECIES_YAMPER) { Ability(ABILITY_BALL_FETCH); Item(item); }
        OPPONENT(SPECIES_METAGROSS);
    } WHEN {
        TURN { USE_ITEM(player, ITEM_GREAT_BALL, WITH_RNG(RNG_BALLTHROW_SHAKE, MAX_u16)); }
    } SCENE {
        if (item == ITEM_NONE)
        {
            MESSAGE("You used Great Ball!");
            ABILITY_POPUP(player, ABILITY_BALL_FETCH);
            MESSAGE("Yamper found a Great Ball!");
        }
        else
        {
            NONE_OF {
                ABILITY_POPUP(player, ABILITY_BALL_FETCH);
                MESSAGE("Yamper found a Great Ball!");
            }
        }
    } THEN {
        if (item == ITEM_NONE)
            EXPECT_EQ(player->item, ITEM_GREAT_BALL);
        else
            EXPECT_EQ(player->item, item);
    }
}

WILD_BATTLE_TEST("Ball Fetch triggers if its held item is consumed before the end of the turn")
{
    GIVEN {
        PLAYER(SPECIES_YAMPER) { Ability(ABILITY_BALL_FETCH); MaxHP(100); HP(51); Item(ITEM_SITRUS_BERRY); Status1(STATUS1_POISON); }
        OPPONENT(SPECIES_METAGROSS);
    } WHEN {
        TURN { USE_ITEM(player, ITEM_GREAT_BALL, WITH_RNG(RNG_BALLTHROW_SHAKE, MAX_u16)); }
    } SCENE {
        HP_BAR(player);
        ABILITY_POPUP(player, ABILITY_BALL_FETCH);
    } THEN {
        EXPECT_EQ(player->item, ITEM_GREAT_BALL);
    }
}

WILD_BATTLE_TEST("Ball Fetch only activates once per battle")
{
    enum Item item = ITEM_NONE;
    enum Item item2 = ITEM_NONE;

    PARAMETRIZE { item = ITEM_GREAT_BALL; item2 = ITEM_X_ACCURACY; }
    PARAMETRIZE { item = ITEM_GREAT_BALL; item2 = ITEM_ULTRA_BALL; }
    PARAMETRIZE { item = ITEM_GREAT_BALL; item2 = ITEM_FAST_BALL; }
    PARAMETRIZE { item = ITEM_GREAT_BALL; item2 = ITEM_STRANGE_BALL; }


    GIVEN {
        PLAYER(SPECIES_YAMPER) { Ability(ABILITY_BALL_FETCH); }
        OPPONENT(SPECIES_METAGROSS);
    } WHEN {
        TURN { USE_ITEM(player, item, WITH_RNG(RNG_BALLTHROW_SHAKE, MAX_u16)); }
        TURN { MOVE(player, MOVE_BESTOW); }
        TURN { USE_ITEM(player, item2, WITH_RNG(RNG_BALLTHROW_SHAKE, MAX_u16)); }
    } SCENE {
        MESSAGE("You used Great Ball!");
        ABILITY_POPUP(player, ABILITY_BALL_FETCH);
        MESSAGE("Yamper found a Great Ball!");
        MESSAGE("Yamper used Bestow!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_BESTOW, player);
        MESSAGE("The wild Metagross received Great Ball from Yamper!");
        NOT ABILITY_POPUP(player, ABILITY_BALL_FETCH);
    } THEN {
        EXPECT_EQ(player->item, ITEM_NONE);
    }
}

WILD_BATTLE_TEST("Ball Fetch can retrieve a Ball used before the Pokémon entered battle")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_YAMPER) { Ability(ABILITY_BALL_FETCH); }
        OPPONENT(SPECIES_METAGROSS);
    } WHEN {
        TURN { USE_ITEM(player, ITEM_GREAT_BALL, WITH_RNG(RNG_BALLTHROW_SHAKE, MAX_u16)); }
        TURN { SWITCH(player, 1); }
    } SCENE {
        ABILITY_POPUP(player, ABILITY_BALL_FETCH);
    } THEN {
        EXPECT_EQ(player->item, ITEM_GREAT_BALL);
    }
}

WILD_BATTLE_TEST("Ball Fetch retrieves the first failed Ball if it cannot activate immediately")
{
    GIVEN {
        PLAYER(SPECIES_YAMPER) { Ability(ABILITY_BALL_FETCH); Item(ITEM_NUGGET); }
        OPPONENT(SPECIES_METAGROSS);
    } WHEN {
        TURN { USE_ITEM(player, ITEM_GREAT_BALL, WITH_RNG(RNG_BALLTHROW_SHAKE, MAX_u16)); }
        TURN { USE_ITEM(player, ITEM_ULTRA_BALL, WITH_RNG(RNG_BALLTHROW_SHAKE, MAX_u16)); }
        TURN { MOVE(player, MOVE_BESTOW); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_BESTOW, player);
        ABILITY_POPUP(player, ABILITY_BALL_FETCH);
    } THEN {
        EXPECT_EQ(player->item, ITEM_GREAT_BALL);
    }
}

WILD_BATTLE_TEST("The fastest Ball Fetch user retrieves the Ball")
{
    u32 playerSpeed;
    u32 opponentSpeed;
    enum Item playerItem;
    enum Item opponentItem;

    PARAMETRIZE { playerSpeed = 2; opponentSpeed = 1; playerItem = ITEM_GREAT_BALL; opponentItem = ITEM_NONE; }
    PARAMETRIZE { playerSpeed = 1; opponentSpeed = 2; playerItem = ITEM_NONE; opponentItem = ITEM_GREAT_BALL; }

    GIVEN {
        PLAYER(SPECIES_YAMPER) { Ability(ABILITY_BALL_FETCH); Speed(playerSpeed); }
        OPPONENT(SPECIES_YAMPER) { Ability(ABILITY_BALL_FETCH); Speed(opponentSpeed); }
    } WHEN {
        TURN { USE_ITEM(player, ITEM_GREAT_BALL, WITH_RNG(RNG_BALLTHROW_SHAKE, MAX_u16)); }
    } SCENE {
        if (playerSpeed > opponentSpeed)
            ABILITY_POPUP(player, ABILITY_BALL_FETCH);
        else
            ABILITY_POPUP(opponent, ABILITY_BALL_FETCH);
    } THEN {
        EXPECT_EQ(player->item, playerItem);
        EXPECT_EQ(opponent->item, opponentItem);
    }
}

WILD_BATTLE_TEST("Ball Fetch doesn't trigger if the Pokémon faints from residual damage")
{
    GIVEN {
        PLAYER(SPECIES_YAMPER) { Ability(ABILITY_BALL_FETCH); HP(1); Status1(STATUS1_POISON); }
        OPPONENT(SPECIES_METAGROSS);
    } WHEN {
        TURN { USE_ITEM(player, ITEM_GREAT_BALL, WITH_RNG(RNG_BALLTHROW_SHAKE, MAX_u16)); }
    } SCENE {
        HP_BAR(player);
        NOT ABILITY_POPUP(player, ABILITY_BALL_FETCH);
    } THEN {
        EXPECT_EQ(player->hp, 0);
        EXPECT_EQ(player->item, ITEM_NONE);
    }
}

SINGLE_BATTLE_TEST("Ball Fetch doesn't trigger in Trainer Battles")
{
    enum Item item = ITEM_NONE;

    PARAMETRIZE { item = ITEM_POKE_BALL; }
    PARAMETRIZE { item = ITEM_GREAT_BALL; }
    PARAMETRIZE { item = ITEM_ULTRA_BALL; }
    PARAMETRIZE { item = ITEM_STRANGE_BALL; }
    PARAMETRIZE { item = ITEM_X_ACCURACY; }

    GIVEN {
        PLAYER(SPECIES_YAMPER) { Ability(ABILITY_BALL_FETCH); }
        OPPONENT(SPECIES_METAGROSS);
    } WHEN {
        TURN { USE_ITEM(player, item, WITH_RNG(RNG_BALLTHROW_SHAKE, 0)); }
    } SCENE {
        NOT ABILITY_POPUP(player, ABILITY_BALL_FETCH);
    } THEN {
        EXPECT_EQ(player->item, ITEM_NONE);
    }
}

WILD_BATTLE_TEST("Ball Fetch doesn't trigger in Max Raid Battles")
{
    GIVEN {
        gBattleTestRunnerState->data.recordedBattle.battleFlags |= BATTLE_TYPE_RAID;
        PLAYER(SPECIES_YAMPER) { Ability(ABILITY_BALL_FETCH); }
        OPPONENT(SPECIES_METAGROSS);
    } WHEN {
        TURN { USE_ITEM(player, ITEM_GREAT_BALL, WITH_RNG(RNG_BALLTHROW_SHAKE, MAX_u16)); }
    } SCENE {
        NOT ABILITY_POPUP(player, ABILITY_BALL_FETCH);
    } THEN {
        EXPECT_EQ(player->item, ITEM_NONE);
    }
}
