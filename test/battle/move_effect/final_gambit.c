#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(GetMoveEffect(MOVE_FINAL_GAMBIT) == EFFECT_FINAL_GAMBIT);
}

SINGLE_BATTLE_TEST("Final Gambit faints the user, and the target receives damage equal to the user's HP")
{
    u32 hp;
    PARAMETRIZE { hp = 32; }
    PARAMETRIZE { hp = 40; }
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { HP(hp); }
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_WOBBUFFET) { MaxHP(400); HP(400); }
    } WHEN {
        TURN { MOVE(player, MOVE_FINAL_GAMBIT); SEND_OUT(player, 1); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_FINAL_GAMBIT, player);
        HP_BAR(opponent);
        HP_BAR(player);
    } THEN {
        EXPECT_EQ(GetMonData(&gParties[B_TRAINER_PLAYER][0], MON_DATA_HP), 0);
        EXPECT_EQ(opponent->hp, 400 - hp);
    }
}

SINGLE_BATTLE_TEST("Final Gambit faints user and target")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WYNAUT);
    } WHEN {
        TURN { MOVE(player, MOVE_FINAL_GAMBIT); SEND_OUT(player, 1); SEND_OUT(opponent, 1); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_FINAL_GAMBIT, player);
        HP_BAR(opponent);
        HP_BAR(player);
    } THEN {
        EXPECT_EQ(GetMonData(&gParties[B_TRAINER_PLAYER][0], MON_DATA_HP), 0);
        EXPECT_EQ(GetMonData(&gParties[B_TRAINER_OPPONENT_A][0], MON_DATA_HP), 0);
    }
}

SINGLE_BATTLE_TEST("Final Gambit does not faint user if target protects")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_PROTECT); MOVE(player, MOVE_FINAL_GAMBIT); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_PROTECT, opponent);
        NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_FINAL_GAMBIT, player);
    } THEN {
        EXPECT_NE(GetMonData(&gParties[B_TRAINER_PLAYER][0], MON_DATA_HP), 0);
        EXPECT_NE(GetMonData(&gParties[B_TRAINER_OPPONENT_A][0], MON_DATA_HP), 0);
    }
}

SINGLE_BATTLE_TEST("Final Gambit does not faint user if attacker fails to attack")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_CONFUSE_RAY) == EFFECT_CONFUSE);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_CONFUSE_RAY); MOVE(player, MOVE_FINAL_GAMBIT); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CONFUSE_RAY, opponent);
        NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_FINAL_GAMBIT, player);
    } THEN {
        EXPECT_NE(GetMonData(&gParties[B_TRAINER_PLAYER][0], MON_DATA_HP), 0);
        EXPECT_NE(GetMonData(&gParties[B_TRAINER_OPPONENT_A][0], MON_DATA_HP), 0);
    }
}

SINGLE_BATTLE_TEST("Final Gambit does not faint user if target is immune")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_GASTLY);
    } WHEN {
        TURN { MOVE(player, MOVE_FINAL_GAMBIT); }
    } SCENE {
        NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_FINAL_GAMBIT, player);
    } THEN {
        EXPECT_NE(GetMonData(&gParties[B_TRAINER_PLAYER][0], MON_DATA_HP), 0);
        EXPECT_NE(GetMonData(&gParties[B_TRAINER_OPPONENT_A][0], MON_DATA_HP), 0);
    }
}

// Using CONFIG_UPDATED_MOVE_FLAGS doesn't work yet, commented out so they don't cause surprise failures

// SINGLE_BATTLE_TEST("Final Gambit faints the user before abilities can activate (Gen 5)")
// {
//     GIVEN {
//         WITH_CONFIG(B_UPDATED_MOVE_FLAGS, GEN_5);
//         PLAYER(SPECIES_WOBBUFFET);
//         OPPONENT(SPECIES_PYUKUMUKU) { Ability(ABILITY_INNARDS_OUT); HP(1); }
//     } WHEN {
//         TURN { MOVE(player, MOVE_FINAL_GAMBIT); }
//     } SCENE {
//         NOT ABILITY_POPUP(opponent, ABILITY_INNARDS_OUT);
//         MESSAGE("Wobbuffet fainted!");
//         NOT ABILITY_POPUP(opponent, ABILITY_INNARDS_OUT);
//     }
// }

// SINGLE_BATTLE_TEST("Final Gambit faints the user after abilities can activate (Gen 6+)")
// {
//     GIVEN {
//         WITH_CONFIG(B_UPDATED_MOVE_FLAGS, GEN_6);
//         PLAYER(SPECIES_WOBBUFFET);
//         OPPONENT(SPECIES_PYUKUMUKU) { Ability(ABILITY_INNARDS_OUT); HP(1); }
//     } WHEN {
//         TURN { MOVE(player, MOVE_FINAL_GAMBIT); }
//     } SCENE {
//         ABILITY_POPUP(opponent, ABILITY_INNARDS_OUT);
//         MESSAGE("Wobbuffet fainted!");
//     }
// }

SINGLE_BATTLE_TEST("Final Gambit does not faint the user if it misses")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { MaxHP(10); HP(10); Speed(1); }
        OPPONENT(SPECIES_WOBBUFFET) { MaxHP(10); HP(10); Speed(2); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_SAND_ATTACK); MOVE(player, MOVE_FINAL_GAMBIT, hit: FALSE); }
    } THEN {
        EXPECT_EQ(player->hp, 10);
        EXPECT_EQ(opponent->hp, 10);
    }
}

SINGLE_BATTLE_TEST("Final Gambit does not trigger the user's Focus Band")
{
    GIVEN {
        ASSUME(GetItemHoldEffect(ITEM_FOCUS_BAND) == HOLD_EFFECT_FOCUS_BAND);
        PLAYER(SPECIES_WOBBUFFET) { MaxHP(3); HP(3); Item(ITEM_FOCUS_BAND); }
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_WOBBUFFET) { MaxHP(10); HP(10); }
    } WHEN {
        TURN { MOVE(player, MOVE_FINAL_GAMBIT); SEND_OUT(player, 1); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_FINAL_GAMBIT, player);
        HP_BAR(opponent, damage: 3);
        HP_BAR(player, hp: 0);
        NOT ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_EFFECT, player);
    } THEN {
        EXPECT_EQ(GetMonData(&gParties[B_TRAINER_PLAYER][0], MON_DATA_HP), 0);
        EXPECT_EQ(GetMonData(&gParties[B_TRAINER_PLAYER][0], MON_DATA_HELD_ITEM), ITEM_FOCUS_BAND);
    }
}

SINGLE_BATTLE_TEST("Final Gambit does not trigger the user's Focus Sash")
{
    GIVEN {
        ASSUME(GetItemHoldEffect(ITEM_FOCUS_SASH) == HOLD_EFFECT_FOCUS_SASH);
        PLAYER(SPECIES_WOBBUFFET) { MaxHP(3); HP(3); Item(ITEM_FOCUS_SASH); }
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_WOBBUFFET) { MaxHP(10); HP(10); }
    } WHEN {
        TURN { MOVE(player, MOVE_FINAL_GAMBIT); SEND_OUT(player, 1); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_FINAL_GAMBIT, player);
        HP_BAR(opponent, damage: 3);
        HP_BAR(player, hp: 0);
        NOT ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_EFFECT, player);
    } THEN {
        EXPECT_EQ(GetMonData(&gParties[B_TRAINER_PLAYER][0], MON_DATA_HP), 0);
        EXPECT_EQ(GetMonData(&gParties[B_TRAINER_PLAYER][0], MON_DATA_HELD_ITEM), ITEM_FOCUS_SASH);
    }
}

SINGLE_BATTLE_TEST("Final Gambit does not trigger the user's Sturdy")
{
    GIVEN {
        WITH_CONFIG(B_STURDY, GEN_5);
        PLAYER(SPECIES_GEODUDE) { MaxHP(3); HP(3); Ability(ABILITY_STURDY); }
        PLAYER(SPECIES_GRAVELER);
        OPPONENT(SPECIES_WOBBUFFET) { MaxHP(10); HP(10); }
    } WHEN {
        TURN { MOVE(player, MOVE_FINAL_GAMBIT); SEND_OUT(player, 1); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_FINAL_GAMBIT, player);
        HP_BAR(opponent, damage: 3);
        HP_BAR(player, hp: 0);
        NOT ABILITY_POPUP(player, ABILITY_STURDY);
    } THEN {
        EXPECT_EQ(GetMonData(&gParties[B_TRAINER_PLAYER][0], MON_DATA_HP), 0);
    }
}

SINGLE_BATTLE_TEST("Final Gambit triggers the target's Focus Band")
{
    GIVEN {
        ASSUME(GetItemHoldEffect(ITEM_FOCUS_BAND) == HOLD_EFFECT_FOCUS_BAND);
        RNGSeed(((rng_value_t){ .ctr = 1 })); // Force Focus Band's 10% check to succeed.
        PLAYER(SPECIES_WOBBUFFET) { MaxHP(3); HP(3); }
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_WOBBUFFET) { MaxHP(2); HP(2); Item(ITEM_FOCUS_BAND); }
    } WHEN {
        TURN { MOVE(player, MOVE_FINAL_GAMBIT); SEND_OUT(player, 1); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_FINAL_GAMBIT, player);
        HP_BAR(opponent, hp: 1);
        MESSAGE("The opposing Wobbuffet hung on using its Focus Band!");
        HP_BAR(player, hp: 0);
    } THEN {
        EXPECT_EQ(opponent->hp, 1);
    }
}

SINGLE_BATTLE_TEST("Final Gambit triggers the target's Focus Sash")
{
    GIVEN {
        ASSUME(GetItemHoldEffect(ITEM_FOCUS_SASH) == HOLD_EFFECT_FOCUS_SASH);
        PLAYER(SPECIES_WOBBUFFET) { MaxHP(3); HP(3); }
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_WOBBUFFET) { MaxHP(2); HP(2); Item(ITEM_FOCUS_SASH); }
    } WHEN {
        TURN { MOVE(player, MOVE_FINAL_GAMBIT); SEND_OUT(player, 1); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_FINAL_GAMBIT, player);
        HP_BAR(opponent, hp: 1);
        MESSAGE("The opposing Wobbuffet hung on using its Focus Sash!");
        HP_BAR(player, hp: 0);
    } THEN {
        EXPECT_EQ(opponent->hp, 1);
        EXPECT_EQ(opponent->item, ITEM_NONE);
    }
}

SINGLE_BATTLE_TEST("Final Gambit triggers the target's Sturdy")
{
    GIVEN {
        WITH_CONFIG(B_STURDY, GEN_5);
        PLAYER(SPECIES_WOBBUFFET) { MaxHP(3); HP(3); }
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_GEODUDE) { MaxHP(2); HP(2); Ability(ABILITY_STURDY); }
    } WHEN {
        TURN { MOVE(player, MOVE_FINAL_GAMBIT); SEND_OUT(player, 1); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_FINAL_GAMBIT, player);
        HP_BAR(opponent, hp: 1);
        ABILITY_POPUP(opponent, ABILITY_STURDY);
        HP_BAR(player, hp: 0);
    } THEN {
        EXPECT_EQ(opponent->hp, 1);
    }
}

SINGLE_BATTLE_TEST("Final Gambit triggers the target's Endure")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { MaxHP(3); HP(3); Speed(1); }
        PLAYER(SPECIES_WYNAUT) { Speed(1); }
        OPPONENT(SPECIES_WOBBUFFET) { MaxHP(2); HP(2); Speed(2); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_ENDURE); MOVE(player, MOVE_FINAL_GAMBIT); SEND_OUT(player, 1); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_ENDURE, opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_FINAL_GAMBIT, player);
        HP_BAR(opponent, hp: 1);
        MESSAGE("The opposing Wobbuffet endured the hit!");
        HP_BAR(player, hp: 0);
    } THEN {
        EXPECT_EQ(opponent->hp, 1);
    }
}

TO_DO_BATTLE_TEST("Final Gambit fails in Max Raids")
TO_DO_BATTLE_TEST("Final Gambit fails in Tera Raids")
