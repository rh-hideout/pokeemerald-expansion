#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(GetMoveEffect(MOVE_AUTOTOMIZE) == EFFECT_AUTOTOMIZE);
    ASSUME_STAT_CHANGE(MOVE_AUTOTOMIZE, speed: +2);
}

SINGLE_BATTLE_TEST("Autotomize increases Speed by 2 stages")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_AUTOTOMIZE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_AUTOTOMIZE, player);
    } THEN {
        EXPECT_EQ(player->statStages[STAT_SPEED], DEFAULT_STAT_STAGE + 2);
    }
}

SINGLE_BATTLE_TEST("Autotomize decreases weight by 100kg (220 lbs.) each time it's used")
{
    s16 damage[3];

    GIVEN {
        ASSUME(GetSpeciesWeight(SPECIES_METANG) == 2025);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_METANG);
    } WHEN {
        TURN { MOVE(player, MOVE_LOW_KICK); }
        TURN { MOVE(opponent, MOVE_AUTOTOMIZE); MOVE(player, MOVE_LOW_KICK); }
        TURN { MOVE(opponent, MOVE_AUTOTOMIZE); MOVE(player, MOVE_LOW_KICK); }
    } SCENE {
        // 200.0 kg or more (120 power)
        ANIMATION(ANIM_TYPE_MOVE, MOVE_LOW_KICK, player);
        HP_BAR(opponent, captureDamage: &damage[0]);

        // 100.0 - 199.9 kg (100 power)
        ANIMATION(ANIM_TYPE_MOVE, MOVE_AUTOTOMIZE, opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_LOW_KICK, player);
        HP_BAR(opponent, captureDamage: &damage[1]);

        //   0.1 - 9.9 kg   (20 power)
        ANIMATION(ANIM_TYPE_MOVE, MOVE_AUTOTOMIZE, opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_LOW_KICK, player);
        HP_BAR(opponent, captureDamage: &damage[2]);
    } THEN {
        EXPECT_MUL_EQ(damage[2], Q_4_12(6.0), damage[0]);
        EXPECT_MUL_EQ(damage[2], Q_4_12(5.0), damage[1]);
    }
}

SINGLE_BATTLE_TEST("Autotomize cannot decrease weight below 0.1kg (0.2 lbs)")
{
    GIVEN {
        ASSUME(GetSpeciesWeight(SPECIES_DURALUDON) == 400);
        PLAYER(SPECIES_DURALUDON) { Ability(ABILITY_STALWART); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_AUTOTOMIZE); }
        TURN { MOVE(player, MOVE_AUTOTOMIZE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_AUTOTOMIZE, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_AUTOTOMIZE, player);
    } THEN {
        EXPECT_EQ(GetBattlerWeight(GetBattlerAtPosition(B_POSITION_PLAYER_LEFT)), 1);
        EXPECT_EQ((u32)player->volatiles.autotomizeCount, 1);
    }
}

SINGLE_BATTLE_TEST("Autotomize's weight reduction cannot be Baton Passed")
{
    GIVEN {
        ASSUME(GetSpeciesWeight(SPECIES_DURALUDON) == 400);
        PLAYER(SPECIES_DURALUDON) { Ability(ABILITY_STALWART); }
        PLAYER(SPECIES_DURALUDON) { Ability(ABILITY_STALWART); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_AUTOTOMIZE); }
        TURN { MOVE(player, MOVE_BATON_PASS); SEND_OUT(player, 1); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_AUTOTOMIZE, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_BATON_PASS, player);
        SEND_IN_MESSAGE("Duraludon");
    } THEN {
        EXPECT_EQ(player->statStages[STAT_SPEED], DEFAULT_STAT_STAGE + 2);
        EXPECT_EQ(GetBattlerWeight(GetBattlerAtPosition(B_POSITION_PLAYER_LEFT)), 400);
        EXPECT_EQ((u32)player->volatiles.autotomizeCount, 0);
    }
}

SINGLE_BATTLE_TEST("Autotomize's weight reduction cannot be removed by Haze")
{
    GIVEN {
        ASSUME(GetSpeciesWeight(SPECIES_DURALUDON) == 400);
        PLAYER(SPECIES_DURALUDON) { Ability(ABILITY_STALWART); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_AUTOTOMIZE); }
        TURN { MOVE(opponent, MOVE_HAZE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_AUTOTOMIZE, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_HAZE, opponent);
    } THEN {
        EXPECT_EQ(player->statStages[STAT_SPEED], DEFAULT_STAT_STAGE);
        EXPECT_EQ(GetBattlerWeight(GetBattlerAtPosition(B_POSITION_PLAYER_LEFT)), 1);
        EXPECT_EQ((u32)player->volatiles.autotomizeCount, 1);
    }
}

TO_DO_BATTLE_TEST("Autotomize's weight reduction is reset upon form change (Gen6+)");

SINGLE_BATTLE_TEST("Autotomize's weight reduction is reset upon switch")
{
    GIVEN {
        ASSUME(GetSpeciesWeight(SPECIES_DURALUDON) == 400);
        PLAYER(SPECIES_DURALUDON) { Ability(ABILITY_STALWART); }
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_AUTOTOMIZE); }
        TURN { SWITCH(player, 1); }
        TURN { SWITCH(player, 0); }
    } THEN {
        EXPECT_EQ(GetBattlerWeight(GetBattlerAtPosition(B_POSITION_PLAYER_LEFT)), 400);
        EXPECT_EQ((u32)player->volatiles.autotomizeCount, 0);
    }
}

SINGLE_BATTLE_TEST("Autotomize's weight reduction is reset upon fainting")
{
    GIVEN {
        ASSUME(GetSpeciesWeight(SPECIES_DURALUDON) == 400);
        PLAYER(SPECIES_DURALUDON) { Ability(ABILITY_STALWART); HP(1); }
        PLAYER(SPECIES_RABSCA);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_AUTOTOMIZE); }
        TURN { MOVE(opponent, MOVE_SCRATCH); SEND_OUT(player, 1); }
        TURN { MOVE(player, MOVE_REVIVAL_BLESSING, partyIndex: 0); }
        TURN { SWITCH(player, 0); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_AUTOTOMIZE, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, opponent);
        MESSAGE("Duraludon fainted!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_REVIVAL_BLESSING, player);
    } THEN {
        EXPECT_EQ(GetBattlerWeight(GetBattlerAtPosition(B_POSITION_PLAYER_LEFT)), 400);
        EXPECT_EQ((u32)player->volatiles.autotomizeCount, 0);
    }
}

WILD_BATTLE_TEST("Autotomize doesn't affect Heavy Ball's multiplier", u32 catchingChance)
{
    bool32 usedAutotomize;
    PARAMETRIZE { usedAutotomize = FALSE; }
    PARAMETRIZE { usedAutotomize = TRUE; }

    GIVEN {
        ASSUME(GetSpeciesWeight(SPECIES_SCIZOR) == 1180);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_SCIZOR) { Ability(ABILITY_TECHNICIAN); }
    } WHEN {
        if (usedAutotomize)
            TURN { MOVE(opponent, MOVE_AUTOTOMIZE); }
        TURN { USE_ITEM(player, ITEM_HEAVY_BALL); }
    } SCENE {
        CATCHING_CHANCE(&results[i].catchingChance);
    } FINALLY {
        EXPECT_EQ(results[0].catchingChance, results[1].catchingChance);
    }
}
