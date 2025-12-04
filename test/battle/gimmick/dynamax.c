#include "global.h"
#include "test/battle.h"

// ============= DYNAMAX AND MAX MOVE INTERACTIONS ===================
SINGLE_BATTLE_TEST("Dynamax: Dynamax increases HP and max HP by 1.5x", u16 hp)
{
    u32 dynamax;
    PARAMETRIZE { dynamax = GIMMICK_NONE; }
    PARAMETRIZE { dynamax = GIMMICK_DYNAMAX; }
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_SCRATCH, gimmick: dynamax); MOVE(opponent, MOVE_CELEBRATE); }
    } SCENE {
        if (dynamax) {
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_DYNAMAX_GROWTH, player);
            MESSAGE("Wobbuffet used Max Strike!");
        }
        MESSAGE("The opposing Wobbuffet used Celebrate!");
    } THEN {
        results[i].hp = player->hp;
    } FINALLY {
        EXPECT_MUL_EQ(results[0].hp, Q_4_12(1.5), results[1].hp);
    }
}

SINGLE_BATTLE_TEST("Dynamax: Dynamax Level increases HP and max HP multipliers by 0.05 for each level", u16 hp)
{
    u32 dynamax, level;
    PARAMETRIZE { dynamax = GIMMICK_NONE; level = 0; }
    PARAMETRIZE { dynamax = GIMMICK_DYNAMAX; level = 0; }
    PARAMETRIZE { dynamax = GIMMICK_DYNAMAX; level = 1; }
    PARAMETRIZE { dynamax = GIMMICK_DYNAMAX; level = 2; }
    PARAMETRIZE { dynamax = GIMMICK_DYNAMAX; level = 3; }
    PARAMETRIZE { dynamax = GIMMICK_DYNAMAX; level = 4; }
    PARAMETRIZE { dynamax = GIMMICK_DYNAMAX; level = 5; }
    PARAMETRIZE { dynamax = GIMMICK_DYNAMAX; level = 6; }
    PARAMETRIZE { dynamax = GIMMICK_DYNAMAX; level = 7; }
    PARAMETRIZE { dynamax = GIMMICK_DYNAMAX; level = 8; }
    PARAMETRIZE { dynamax = GIMMICK_DYNAMAX; level = 9; }
    PARAMETRIZE { dynamax = GIMMICK_DYNAMAX; level = 10; }
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { DynamaxLevel(level); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_SCRATCH, gimmick: dynamax); MOVE(opponent, MOVE_CELEBRATE); }
    } SCENE {
        if (dynamax) {
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_DYNAMAX_GROWTH, player);
            MESSAGE("Wobbuffet used Max Strike!");
        }
        MESSAGE("The opposing Wobbuffet used Celebrate!");
    } THEN {
        results[i].hp = player->hp;
    } FINALLY {
        EXPECT_MUL_EQ(results[0].hp, Q_4_12(1.5), results[1].hp);
        EXPECT_MUL_EQ(results[0].hp, Q_4_12(1.55), results[2].hp);
        EXPECT_MUL_EQ(results[0].hp, Q_4_12(1.6), results[3].hp);
        EXPECT_MUL_EQ(results[0].hp, Q_4_12(1.65), results[4].hp);
        EXPECT_MUL_EQ(results[0].hp, Q_4_12(1.7), results[5].hp);
        EXPECT_MUL_EQ(results[0].hp, Q_4_12(1.75), results[6].hp);
        EXPECT_MUL_EQ(results[0].hp, Q_4_12(1.8), results[7].hp);
        EXPECT_MUL_EQ(results[0].hp, Q_4_12(1.85), results[8].hp);
        EXPECT_MUL_EQ(results[0].hp, Q_4_12(1.9), results[9].hp);
        EXPECT_MUL_EQ(results[0].hp, Q_4_12(1.95), results[10].hp);
        EXPECT_MUL_EQ(results[0].hp, Q_4_12(2.0), results[11].hp);
    }
}

SINGLE_BATTLE_TEST("Dynamax: Dynamax expires when fainted")
{
    u32 dynamax;
    PARAMETRIZE { dynamax = GIMMICK_NONE; }
    PARAMETRIZE { dynamax = GIMMICK_DYNAMAX; }
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { HP(1); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_SCRATCH, gimmick: dynamax); MOVE(opponent, MOVE_SCRATCH); }
    } SCENE {
        if (dynamax)
            MESSAGE("Wobbuffet used Max Strike!");
        else
            MESSAGE("Wobbuffet used Scratch!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, opponent);
        HP_BAR(player);
        if (dynamax) // Expect to have visual reversion when fainting.
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_FORM_CHANGE, player);
        MESSAGE("Wobbuffet fainted!");
    }
}

SINGLE_BATTLE_TEST("Dynamax: Dynamax expires after three turns", u16 hp)
{
    u32 dynamax;
    PARAMETRIZE { dynamax = GIMMICK_NONE; }
    PARAMETRIZE { dynamax = GIMMICK_DYNAMAX; }
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_SCRATCH, gimmick: dynamax); }   // 1st max move
        TURN { MOVE(player, MOVE_SCRATCH); }                     // 2nd max move
        TURN { MOVE(player, MOVE_SCRATCH); }                     // 3rd max move
    } SCENE {
        int j;
        for (j = 0; j < DYNAMAX_TURNS_COUNT; ++j) {
            if (dynamax)
                MESSAGE("Wobbuffet used Max Strike!");
            else
                MESSAGE("Wobbuffet used Scratch!");
            MESSAGE("The opposing Wobbuffet used Celebrate!");
        }
        if (dynamax) // Expect to have visual reversion at the end.
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_FORM_CHANGE, player);
    } THEN {
        results[i].hp = player->hp;
    } FINALLY {
        EXPECT_EQ(results[0].hp, results[1].hp);
    }
}

SINGLE_BATTLE_TEST("Dynamax: Dynamax expires after three turns and correctly converts HP according to Dynamax Level")
{
    u32 dynamaxLevel, dynamax;
    u16 capturedHP, finalHP;
    s16 capturedDamage;
    PARAMETRIZE { dynamaxLevel = 0; dynamax = GIMMICK_NONE; }
    PARAMETRIZE { dynamaxLevel = 0; dynamax = GIMMICK_DYNAMAX; }
    PARAMETRIZE { dynamaxLevel = 1; dynamax = GIMMICK_DYNAMAX; }
    PARAMETRIZE { dynamaxLevel = 2; dynamax = GIMMICK_DYNAMAX; }
    PARAMETRIZE { dynamaxLevel = 3; dynamax = GIMMICK_DYNAMAX; }
    PARAMETRIZE { dynamaxLevel = 4; dynamax = GIMMICK_DYNAMAX; }
    PARAMETRIZE { dynamaxLevel = 5; dynamax = GIMMICK_DYNAMAX; }
    PARAMETRIZE { dynamaxLevel = 6; dynamax = GIMMICK_DYNAMAX; }
    PARAMETRIZE { dynamaxLevel = 7; dynamax = GIMMICK_DYNAMAX; }
    PARAMETRIZE { dynamaxLevel = 8; dynamax = GIMMICK_DYNAMAX; }
    PARAMETRIZE { dynamaxLevel = 9; dynamax = GIMMICK_DYNAMAX; }
    PARAMETRIZE { dynamaxLevel = 10; dynamax = GIMMICK_DYNAMAX; }
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { DynamaxLevel(dynamaxLevel); HP(200); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_CELEBRATE, gimmick: dynamax); }
        TURN { MOVE(player, MOVE_SCRATCH); MOVE(opponent, MOVE_SCRATCH, WITH_RNG(RNG_DAMAGE_MODIFIER, 24)); }
        TURN { }
    } SCENE {
        if (dynamax)
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_DYNAMAX_GROWTH, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, opponent);
        if (dynamax)
            HP_BAR(player, captureHP: &capturedHP);
        else
            HP_BAR(player, captureDamage: &capturedDamage);
        if (dynamax)
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_FORM_CHANGE, player);
    } THEN {
        finalHP = player->hp;
        if (dynamax)
            EXPECT_MUL_EQ(finalHP, GetDynamaxLevelHPMultiplier(dynamaxLevel, FALSE), capturedHP);
        EXPECT_LE(finalHP, 200);
        EXPECT_GE(finalHP, 200 - capturedDamage);
    }
}

SINGLE_BATTLE_TEST("Dynamax: Dynamaxed Pokemon cannot be flinched")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_FAKE_OUT) == EFFECT_FIRST_TURN_ONLY);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_FAKE_OUT); MOVE(player, MOVE_SCRATCH, gimmick: GIMMICK_DYNAMAX); }
    } SCENE {
        MESSAGE("The opposing Wobbuffet used Fake Out!");
        NONE_OF { MESSAGE("Wobbuffet flinched and couldn't move!"); }
        MESSAGE("Wobbuffet used Max Strike!");
    }
}

SINGLE_BATTLE_TEST("Dynamax: Dynamaxed Pokemon can be switched out by Eject Button")
{
    GIVEN {
        ASSUME(gItemsInfo[ITEM_EJECT_BUTTON].holdEffect == HOLD_EFFECT_EJECT_BUTTON);
        PLAYER(SPECIES_WOBBUFFET) { Item(ITEM_EJECT_BUTTON); }
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_SCRATCH, gimmick: GIMMICK_DYNAMAX); MOVE(opponent, MOVE_SCRATCH); SEND_OUT(player, 1); }
    } SCENE {
        MESSAGE("Wobbuffet used Max Strike!");
        MESSAGE("The opposing Wobbuffet used Scratch!");
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_EFFECT, player);
        MESSAGE("Wobbuffet is switched out with the Eject Button!");
    } THEN {
        EXPECT_EQ(opponent->item, ITEM_NONE);
    }
}

SINGLE_BATTLE_TEST("Dynamax: Dynamaxed Pokemon cannot have their ability swapped to another Pokemon's")
{
    GIVEN {
        PLAYER(SPECIES_MILTANK) { Ability(ABILITY_SCRAPPY); }
        OPPONENT(SPECIES_RUNERIGUS) { Ability(ABILITY_WANDERING_SPIRIT); }
    } WHEN {
        TURN { MOVE(player, MOVE_SCRATCH, gimmick: GIMMICK_DYNAMAX); MOVE(opponent, MOVE_SKILL_SWAP); }
    } SCENE {
        MESSAGE("Miltank used Max Strike!");
        MESSAGE("The opposing Runerigus used Skill Swap!");
        MESSAGE("But it failed!");
    } THEN {
        EXPECT_EQ(player->ability, ABILITY_SCRAPPY);
    }
}

SINGLE_BATTLE_TEST("Dynamax: Dynamaxed Pokemon can have their ability changed or suppressed")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_SHADOW_TAG); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_SCRATCH, gimmick: GIMMICK_DYNAMAX); MOVE(opponent, MOVE_SIMPLE_BEAM); }
    } SCENE {
        MESSAGE("Wobbuffet used Max Strike!");
        MESSAGE("The opposing Wobbuffet used Simple Beam!");
        MESSAGE("Wobbuffet acquired Simple!");
    } THEN {
        EXPECT_EQ(player->ability, ABILITY_SIMPLE);
    }
}

SINGLE_BATTLE_TEST("Dynamax: Dynamaxed Pokemon can have base moves disabled on their first turn")
{
    GIVEN {
        ASSUME(B_DISABLE_TURNS >= GEN_5);
        PLAYER(SPECIES_WOBBUFFET) { Speed(50); };
        OPPONENT(SPECIES_WOBBUFFET) { Speed(100); };
    } WHEN {
        TURN { MOVE(opponent, MOVE_CELEBRATE); MOVE(player, MOVE_SCRATCH); }
        TURN { MOVE(opponent, MOVE_DISABLE); MOVE(player, MOVE_SCRATCH, gimmick: GIMMICK_DYNAMAX); }
        TURN {}
        TURN {}
        TURN { MOVE(player, MOVE_SCRATCH, allowed: FALSE); MOVE(player, MOVE_CELEBRATE); }
    } SCENE {
        MESSAGE("The opposing Wobbuffet used Celebrate!");
        MESSAGE("Wobbuffet used Scratch!");
        MESSAGE("The opposing Wobbuffet used Disable!");
        MESSAGE("Wobbuffet's Scratch was disabled!");
        MESSAGE("Wobbuffet used Max Strike!");
    }
}

// This is true for all item-removing moves.
SINGLE_BATTLE_TEST("Dynamax: Dynamaxed Pokemon are not immune to Knock Off")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Item(ITEM_POTION); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_SCRATCH, gimmick: GIMMICK_DYNAMAX); MOVE(opponent, MOVE_KNOCK_OFF); }
    } SCENE {
        MESSAGE("Wobbuffet used Max Strike!");
        MESSAGE("The opposing Wobbuffet used Knock Off!");
        MESSAGE("The opposing Wobbuffet knocked off Wobbuffet's Potion!");
    } THEN {
        EXPECT_EQ(player->item, ITEM_NONE);
    }
}

SINGLE_BATTLE_TEST("Dynamax: Dynamaxed Pokemon lose their substitutes")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_SUBSTITUTE); MOVE(opponent, MOVE_CELEBRATE); }
        TURN { MOVE(player, MOVE_SCRATCH, gimmick: GIMMICK_DYNAMAX); MOVE(opponent, MOVE_SCRATCH); }
    } SCENE {
        MESSAGE("Wobbuffet used Substitute!");
        MESSAGE("Wobbuffet put in a substitute!");
        MESSAGE("Wobbuffet used Max Strike!");
        MESSAGE("The opposing Wobbuffet used Scratch!");
        HP_BAR(player);
    }
}

SINGLE_BATTLE_TEST("Dynamax: Dynamaxed Pokemon that changes forms does not gain HP")
{
    u16 capturedHP, finalHP;
    GIVEN {
        WITH_CONFIG(CONFIG_BATTLE_BOND, GEN_8);
        PLAYER(SPECIES_GRENINJA_BATTLE_BOND) { Ability(ABILITY_BATTLE_BOND); HP(100); Speed(100); }
        OPPONENT(SPECIES_CATERPIE) { HP(1); Speed(1000); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(10); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_SCRATCH); MOVE(player, MOVE_SCRATCH, gimmick: GIMMICK_DYNAMAX); SEND_OUT(opponent, 1); }
    } SCENE {
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_DYNAMAX_GROWTH, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, opponent);
        HP_BAR(player, captureHP: &capturedHP);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_MAX_STRIKE, player);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_FORM_CHANGE, player);
    } THEN {
        finalHP = player->hp;
        EXPECT_EQ(capturedHP, finalHP);
    }
}

SINGLE_BATTLE_TEST("Dynamax: Dynamaxed Pokemon that changes forms does not gain HP unless the new form gains Max HP")
{
    u32 hp = 1, maxHP = 200;
    u32 species;
    PARAMETRIZE { species = SPECIES_ZYGARDE_10_POWER_CONSTRUCT; }
    PARAMETRIZE { species = SPECIES_ZYGARDE_50_POWER_CONSTRUCT; }
    GIVEN {
        PLAYER(species) { Ability(ABILITY_POWER_CONSTRUCT); HP(hp); MaxHP(maxHP); DynamaxLevel(0); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_SCRATCH, gimmick: GIMMICK_DYNAMAX); }
    } SCENE {
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_DYNAMAX_GROWTH, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_MAX_STRIKE, player);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_POWER_CONSTRUCT, player);
    } THEN {
        EXPECT_MUL_EQ(maxHP - hp, GetDynamaxLevelHPMultiplier(0, FALSE), player->maxHP - player->hp);
    }
}

SINGLE_BATTLE_TEST("Dynamax: Max Moves deal 1/4 damage through protect", s16 damage)
{
    bool32 protected;
    PARAMETRIZE { protected = TRUE; }
    PARAMETRIZE { protected = FALSE; }
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        if (protected)
            TURN { MOVE(player, MOVE_SCRATCH, gimmick: GIMMICK_DYNAMAX); MOVE(opponent, MOVE_PROTECT); }
        else
            TURN { MOVE(player, MOVE_SCRATCH, gimmick: GIMMICK_DYNAMAX); }
    } SCENE {
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_MUL_EQ(results[0].damage, Q_4_12(4), results[1].damage);
    }
}

SINGLE_BATTLE_TEST("Dynamax: Max Moves don't bypass Max Guard")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_SCRATCH, gimmick: GIMMICK_DYNAMAX); MOVE(opponent, MOVE_PROTECT, gimmick: GIMMICK_DYNAMAX); }
    } SCENE {
        NONE_OF { HP_BAR(opponent); }
    }
}

DOUBLE_BATTLE_TEST("Dynamax: Feint bypasses Max Guard but doesn't break it")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WYNAUT);
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_PROTECT, gimmick: GIMMICK_DYNAMAX);
               MOVE(opponentLeft, MOVE_FEINT, target: playerLeft);
               MOVE(opponentRight, MOVE_SCRATCH, target: playerLeft);
        }
    } SCENE {
        MESSAGE("Wobbuffet used Max Guard!");
        MESSAGE("The opposing Wobbuffet used Feint!");
        HP_BAR(playerLeft);
        MESSAGE("The opposing Wynaut used Scratch!");
        NONE_OF { HP_BAR(playerLeft); }
    }
}

SINGLE_BATTLE_TEST("Dynamax: Pokemon with Gigantamax forms change upon Dynamaxing")
{
    u32 species;
    bool32 gigantamaxFactor;
    PARAMETRIZE { gigantamaxFactor = FALSE; species = SPECIES_VENUSAUR; }
    PARAMETRIZE { gigantamaxFactor = TRUE; species = SPECIES_VENUSAUR_GMAX; }
    GIVEN {
        PLAYER(SPECIES_VENUSAUR) { GigantamaxFactor(gigantamaxFactor); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_SCRATCH, gimmick: GIMMICK_DYNAMAX); }
    } THEN {
        EXPECT_EQ(player->species, species);
    }
}

SINGLE_BATTLE_TEST("Dynamax: Pokemon with Gigantamax forms revert upon switching")
{
    GIVEN {
        PLAYER(SPECIES_VENUSAUR);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_SCRATCH, gimmick: GIMMICK_DYNAMAX); }
        TURN { SWITCH(player, 1); }
        TURN { SWITCH(player, 0); }
    } THEN {
        EXPECT_EQ(player->species, SPECIES_VENUSAUR);
    }
}

SINGLE_BATTLE_TEST("Dynamax: Dynamaxed Pokemon are not affected by Choice items", s16 damage)
{
    u16 item;
    PARAMETRIZE { item = ITEM_CHOICE_BAND; }
    PARAMETRIZE { item = ITEM_NONE; }
    GIVEN {
        ASSUME(gItemsInfo[ITEM_CHOICE_BAND].holdEffect == HOLD_EFFECT_CHOICE_BAND);
        PLAYER(SPECIES_WOBBUFFET) { Item(item); };
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_SCRATCH, gimmick: GIMMICK_DYNAMAX); }
        TURN { MOVE(player, MOVE_ARM_THRUST); }
    } SCENE {
        MESSAGE("Wobbuffet used Max Strike!");
        HP_BAR(opponent, captureDamage: &results[i].damage);
        MESSAGE("Wobbuffet used Max Knuckle!");
    } FINALLY {
        EXPECT_EQ(results[0].damage, results[1].damage);
    }
}

SINGLE_BATTLE_TEST("Dynamax: Dynamaxed Pokemon cannot use Max Guard while holding Assault Vest")
{
    GIVEN {
        ASSUME(gItemsInfo[ITEM_ASSAULT_VEST].holdEffect == HOLD_EFFECT_ASSAULT_VEST);
        PLAYER(SPECIES_WOBBUFFET) { Item(ITEM_ASSAULT_VEST); };
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_SCRATCH, gimmick: GIMMICK_DYNAMAX); }
        TURN { MOVE(player, MOVE_PROTECT, allowed: FALSE); MOVE(player, MOVE_SCRATCH); }
    } SCENE {
        MESSAGE("Wobbuffet used Max Strike!");
        MESSAGE("Wobbuffet used Max Strike!");
    }
}

SINGLE_BATTLE_TEST("Dynamax: Moxie clones can be triggered by Max Moves fainting opponents")
{
    GIVEN {
        ASSUME(GetMovePower(MOVE_WATERFALL) > 0);
        PLAYER(SPECIES_GYARADOS) { Ability(ABILITY_MOXIE); }
        OPPONENT(SPECIES_WOBBUFFET) { HP(1); }
        OPPONENT(SPECIES_WYNAUT);
    } WHEN {
        TURN { MOVE(opponent, MOVE_CELEBRATE); MOVE(player, MOVE_WATERFALL, gimmick: GIMMICK_DYNAMAX); SEND_OUT(opponent, 1); }
    } SCENE {
        MESSAGE("The opposing Wobbuffet fainted!");
        ABILITY_POPUP(player, ABILITY_MOXIE);
        MESSAGE("Gyarados's Attack rose!");
    }
}

SINGLE_BATTLE_TEST("Dynamax: Max Attacks prints a message when hitting into Max Guard")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_GROWL, gimmick: GIMMICK_DYNAMAX); MOVE(opponent, MOVE_SCRATCH, gimmick: GIMMICK_DYNAMAX); }
    } SCENE {
        MESSAGE("Wobbuffet used Max Guard!");
        MESSAGE("The opposing Wobbuffet used Max Strike!");
    }
}

SINGLE_BATTLE_TEST("Dynamax: Max Moves don't bypass absorbing abilities")
{
    u32 move, species;
    enum Ability ability;
    PARAMETRIZE { move = MOVE_SPARK; ability = ABILITY_VOLT_ABSORB; species = SPECIES_LANTURN; }
    PARAMETRIZE { move = MOVE_WATER_GUN; ability = ABILITY_WATER_ABSORB; species = SPECIES_LANTURN; }
    PARAMETRIZE { move = MOVE_EMBER; ability = ABILITY_FLASH_FIRE; species = SPECIES_HEATRAN; }
    PARAMETRIZE { move = MOVE_SPARK; ability = ABILITY_LIGHTNING_ROD; species = SPECIES_PIKACHU; }
    PARAMETRIZE { move = MOVE_WATER_GUN; ability = ABILITY_STORM_DRAIN; species = SPECIES_GASTRODON; }
    PARAMETRIZE { move = MOVE_EMBER; ability = ABILITY_WELL_BAKED_BODY; species = SPECIES_DACHSBUN; }
    PARAMETRIZE { move = MOVE_SPARK; ability = ABILITY_MOTOR_DRIVE; species = SPECIES_ELECTIVIRE; }
    PARAMETRIZE { move = MOVE_WATER_GUN; ability = ABILITY_DRY_SKIN; species = SPECIES_PARASECT; }
    PARAMETRIZE { move = MOVE_MUD_BOMB; ability = ABILITY_EARTH_EATER; species = SPECIES_ORTHWORM; }
    PARAMETRIZE { move = MOVE_VINE_WHIP; ability = ABILITY_SAP_SIPPER; species = SPECIES_MILTANK; }

    GIVEN {
        ASSUME(GetMoveType(MOVE_WATER_GUN) == TYPE_WATER);
        ASSUME(GetMoveType(MOVE_SPARK) == TYPE_ELECTRIC);
        ASSUME(GetMoveType(MOVE_EMBER) == TYPE_FIRE);
        ASSUME(GetMoveType(MOVE_MUD_BOMB) == TYPE_GROUND);
        ASSUME(GetMoveType(MOVE_VINE_WHIP) == TYPE_GRASS);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(species) { Ability(ability); }
    } WHEN {
        TURN { MOVE(player, move, gimmick: GIMMICK_DYNAMAX); }
    } SCENE {
        NONE_OF {
            ANIMATION(ANIM_TYPE_MOVE, MOVE_MAX_LIGHTNING, player);
            ANIMATION(ANIM_TYPE_MOVE, MOVE_MAX_FLARE, player);
            ANIMATION(ANIM_TYPE_MOVE, MOVE_MAX_GEYSER, player);
            ANIMATION(ANIM_TYPE_MOVE, MOVE_MAX_QUAKE, player);
            ANIMATION(ANIM_TYPE_MOVE, MOVE_MAX_OVERGROWTH, player);
            HP_BAR(opponent);
        }
        ABILITY_POPUP(opponent, ability);
    }
}

SINGLE_BATTLE_TEST("Dynamax: Dynamax is reverted before switch out")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Item(ITEM_EJECT_BUTTON); }
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_SCRATCH, gimmick: GIMMICK_DYNAMAX); MOVE(opponent, MOVE_SCRATCH); SEND_OUT(player, 1); }
        TURN { SWITCH(player, 0); }
        TURN { MOVE(player, MOVE_SCRATCH); }
    } SCENE {
        MESSAGE("Wobbuffet used Scratch!");
    }
}

TO_DO_BATTLE_TEST("Dynamax: Contrary inverts stat-lowering Max Moves, without showing a message")
TO_DO_BATTLE_TEST("Dynamax: Contrary inverts stat-increasing Max Moves, without showing a message")
