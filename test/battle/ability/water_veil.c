#include "global.h"
#include "test/battle.h"


SINGLE_BATTLE_TEST("Water Veil prevents Will-O-Wisp burns")
{
    enum Ability ability;
    PARAMETRIZE { ability = ABILITY_SWIFT_SWIM; }
    PARAMETRIZE { ability = ABILITY_WATER_VEIL; }
    GIVEN {
        PLAYER(SPECIES_BUIZEL) { Ability(ability); MaxHP(1000); HP(1000); }
        OPPONENT(SPECIES_VULPIX) { Ability(ABILITY_FLASH_FIRE); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_WILL_O_WISP); }
    } THEN {
        EXPECT_EQ(player->status1, ability == ABILITY_WATER_VEIL ? STATUS1_NONE : STATUS1_BURN);
    }
}

SINGLE_BATTLE_TEST("Water Veil prevents burns from physical and special attacks")
{
    enum Ability ability;
    enum Move move;
    PARAMETRIZE { ability = ABILITY_SWIFT_SWIM; move = MOVE_FIRE_PUNCH; }
    PARAMETRIZE { ability = ABILITY_WATER_VEIL; move = MOVE_FIRE_PUNCH; }
    PARAMETRIZE { ability = ABILITY_SWIFT_SWIM; move = MOVE_FLAMETHROWER; }
    PARAMETRIZE { ability = ABILITY_WATER_VEIL; move = MOVE_FLAMETHROWER; }
    GIVEN {
        PLAYER(SPECIES_BUIZEL) { Ability(ability); MaxHP(1000); HP(1000); Speed(100); }
        OPPONENT(SPECIES_MEW) { Ability(ABILITY_SYNCHRONIZE); Speed(50); }
    } WHEN {
        TURN { MOVE(opponent, move); }
    } SCENE {
        HP_BAR(player);
    } THEN {
        EXPECT_EQ(player->status1, ability == ABILITY_WATER_VEIL ? STATUS1_NONE : STATUS1_BURN);
    }
}

SINGLE_BATTLE_TEST("Water Veil cures an existing burn when gained through Skill Swap")
{
    GIVEN {
        PLAYER(SPECIES_BUIZEL) { Ability(ABILITY_WATER_VEIL); Speed(100); }
        OPPONENT(SPECIES_MEW) { Ability(ABILITY_SYNCHRONIZE); Status1(STATUS1_BURN); MaxHP(1000); HP(1000); Speed(50); }
    } WHEN {
        TURN { MOVE(player, MOVE_SKILL_SWAP); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SKILL_SWAP, player);
        STATUS_ICON(opponent, burn: FALSE);
    } THEN {
        EXPECT_EQ(opponent->ability, ABILITY_WATER_VEIL);
        EXPECT_EQ(opponent->status1, STATUS1_NONE);
        EXPECT_EQ(opponent->hp, 1000);
    }
}

SINGLE_BATTLE_TEST("Water Veil no longer prevents burns while suppressed")
{
    bool32 suppress;
    PARAMETRIZE { suppress = FALSE; }
    PARAMETRIZE { suppress = TRUE; }
    GIVEN {
        PLAYER(SPECIES_BUIZEL) { Ability(ABILITY_WATER_VEIL); MaxHP(1000); HP(1000); Speed(100); }
        OPPONENT(SPECIES_MEW) { Ability(ABILITY_SYNCHRONIZE); Speed(50); }
    } WHEN {
        if (suppress)
            TURN { MOVE(opponent, MOVE_GASTRO_ACID); }
        TURN { MOVE(opponent, MOVE_WILL_O_WISP); }
    } THEN {
        EXPECT_EQ(player->status1, suppress ? STATUS1_BURN : STATUS1_NONE);
    }
}

SINGLE_BATTLE_TEST("Water Veil prevents Flame Orb burns without consuming the item")
{
    enum Ability ability;
    PARAMETRIZE { ability = ABILITY_SWIFT_SWIM; }
    PARAMETRIZE { ability = ABILITY_WATER_VEIL; }
    GIVEN {
        PLAYER(SPECIES_BUIZEL) { Ability(ability); MaxHP(1000); HP(1000); Item(ITEM_FLAME_ORB); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN {}
    } THEN {
        EXPECT_EQ(player->status1, ability == ABILITY_WATER_VEIL ? STATUS1_NONE : STATUS1_BURN);
        EXPECT_EQ(player->item, ITEM_FLAME_ORB);
    }
}


SINGLE_BATTLE_TEST("Water Veil lets Rawst and Lum Berries cure Mold Breaker burns first")
{
    enum Item item;

    PARAMETRIZE { item = ITEM_RAWST_BERRY; }
    PARAMETRIZE { item = ITEM_LUM_BERRY; }

    GIVEN {
        ASSUME(GetMoveEffect(MOVE_WILL_O_WISP) == EFFECT_NON_VOLATILE_STATUS);
        ASSUME(GetMoveNonVolatileStatus(MOVE_WILL_O_WISP) == MOVE_EFFECT_BURN);
        ASSUME(gItemsInfo[ITEM_RAWST_BERRY].holdEffect == HOLD_EFFECT_CURE_BRN);
        ASSUME(gItemsInfo[ITEM_LUM_BERRY].holdEffect == HOLD_EFFECT_CURE_STATUS);
        PLAYER(SPECIES_BUIZEL) { Ability(ABILITY_WATER_VEIL); Item(item); }
        OPPONENT(SPECIES_VELUZA) { Ability(ABILITY_MOLD_BREAKER); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_WILL_O_WISP); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_WILL_O_WISP, opponent);
        STATUS_ICON(player, burn: TRUE);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_BERRY, player);
        STATUS_ICON(player, burn: FALSE);
        NOT ABILITY_POPUP(player, ABILITY_WATER_VEIL);
    } THEN {
        EXPECT_EQ(player->item, ITEM_NONE);
        EXPECT_EQ(player->status1, STATUS1_NONE);
    }
}
