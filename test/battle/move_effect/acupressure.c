#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(GetMoveEffect(MOVE_ACUPRESSURE) == EFFECT_ACUPRESSURE);
}

DOUBLE_BATTLE_TEST("Acupressure fails on the user if it targeted its ally but switched positions via Ally Switch")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_KADABRA);
        OPPONENT(SPECIES_ABRA);
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_ALLY_SWITCH); MOVE(playerRight, MOVE_ACUPRESSURE, target: playerLeft); }
    } SCENE {
        MESSAGE("Wobbuffet used Ally Switch!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_ALLY_SWITCH, playerLeft);
        MESSAGE("Wobbuffet and Wynaut switched places!");
        MESSAGE("Wynaut used Acupressure!");
        MESSAGE("But it failed!");
        NONE_OF {
            ANIMATION(ANIM_TYPE_MOVE, MOVE_ACUPRESSURE, playerLeft);
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, playerLeft);
        }
    }
}

DOUBLE_BATTLE_TEST("Acupressure works on the ally if it targeted itself but switched positions via Ally Switch")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_KADABRA);
        OPPONENT(SPECIES_ABRA);
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_ALLY_SWITCH); MOVE(playerRight, MOVE_ACUPRESSURE, target: playerRight); }
    } SCENE {
        MESSAGE("Wobbuffet used Ally Switch!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_ALLY_SWITCH, playerLeft);
        MESSAGE("Wobbuffet and Wynaut switched places!");
        MESSAGE("Wynaut used Acupressure!");
        NOT MESSAGE("But it failed!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_ACUPRESSURE, playerLeft);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, playerRight);
    }
}

DOUBLE_BATTLE_TEST("Acupressure will not try to raise partners stat if it already increased its own")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WYNAUT);
    } WHEN {
        TURN { MOVE(opponentRight, MOVE_ACUPRESSURE, target: opponentRight); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_ACUPRESSURE, opponentRight);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponentRight);
        NONE_OF {
            ANIMATION(ANIM_TYPE_MOVE, MOVE_ACUPRESSURE, opponentLeft);
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponentLeft);
        }
    }
}

DOUBLE_BATTLE_TEST("Acupressure works on the user if its side is protected by Crafty Shield")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_PROTECT) == EFFECT_PROTECT);
        ASSUME(GetMoveEffect(MOVE_CRAFTY_SHIELD) == EFFECT_PROTECT);
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WYNAUT);
    } WHEN {
        TURN {
            MOVE(opponentLeft, MOVE_CRAFTY_SHIELD);
            MOVE(opponentRight, MOVE_ACUPRESSURE, target: opponentRight);
        }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CRAFTY_SHIELD, opponentLeft);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_ACUPRESSURE, opponentRight);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponentRight);
    }
}

DOUBLE_BATTLE_TEST("Acupressure works on the ally if its side is protected by Crafty Shield")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_PROTECT) == EFFECT_PROTECT);
        ASSUME(GetMoveEffect(MOVE_CRAFTY_SHIELD) == EFFECT_PROTECT);
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WYNAUT);
    } WHEN {
        TURN {
            MOVE(opponentLeft, MOVE_CRAFTY_SHIELD);
            MOVE(opponentRight, MOVE_ACUPRESSURE, target: opponentLeft);
        }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CRAFTY_SHIELD, opponentLeft);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_ACUPRESSURE, opponentRight);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponentLeft);
    }
}

DOUBLE_BATTLE_TEST("Acupressure works on the user if it's behind a Substitute (Gen5+)")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_SUBSTITUTE) == EFFECT_SUBSTITUTE);
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WYNAUT);
    } WHEN {
        TURN { MOVE(opponentRight, MOVE_SUBSTITUTE); }
        TURN { MOVE(opponentRight, MOVE_ACUPRESSURE, target: opponentRight); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SUBSTITUTE, opponentRight);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_ACUPRESSURE, opponentRight);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponentRight);
    }
}

DOUBLE_BATTLE_TEST("Acupressure fails on its ally if it's behind a Substitute")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_SUBSTITUTE) == EFFECT_SUBSTITUTE);
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WYNAUT);
    } WHEN {
        TURN {
            MOVE(opponentLeft, MOVE_SUBSTITUTE);
            MOVE(opponentRight, MOVE_ACUPRESSURE, target: opponentLeft);
        }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SUBSTITUTE, opponentLeft);
        NONE_OF {
            ANIMATION(ANIM_TYPE_MOVE, MOVE_ACUPRESSURE, opponentRight);
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponentLeft);
        }
    }
}

DOUBLE_BATTLE_TEST("Acupressure will target self if both side allies fainted")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WYNAUT) { HP(1); }
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WYNAUT) { HP(1); }
    } WHEN {
        TURN {
            MOVE(playerRight, MOVE_POUND, target: opponentRight);
            MOVE(opponentLeft, MOVE_POUND, target: playerRight);
            MOVE(playerLeft, MOVE_ACUPRESSURE, target: playerRight);
        }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_ACUPRESSURE, playerLeft);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, playerLeft);
    }
}

SINGLE_BATTLE_TEST("Acupressure fails on the user if all of its stats are maximized")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_CLANGOROUS_SOUL) == EFFECT_CLANGOROUS_SOUL);
        ASSUME_STAT_CHANGE(MOVE_HONE_CLAWS, attack: +1, accuracy: +1);
        ASSUME_STAT_CHANGE(MOVE_DOUBLE_TEAM, evasion: +1);
        PLAYER(SPECIES_BIBAREL) { Ability(ABILITY_SIMPLE); HP(601); MaxHP(601); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_CLANGOROUS_SOUL); }
        TURN { MOVE(player, MOVE_CLANGOROUS_SOUL); }
        TURN { MOVE(player, MOVE_CLANGOROUS_SOUL); }
        for (u32 j = 0; j < 3; j++)
            TURN { MOVE(player, MOVE_HONE_CLAWS); }
        for (u32 j = 0; j < 3; j++)
            TURN { MOVE(player, MOVE_DOUBLE_TEAM); }
        TURN { MOVE(player, MOVE_ACUPRESSURE, target: player); }
    } SCENE {
        MESSAGE("Bibarel used Acupressure!");
        NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_ACUPRESSURE, player);
        MESSAGE("But it failed!");
    } THEN {
        for (enum Stat stat = STAT_ATK; stat < NUM_BATTLE_STATS; stat++)
            EXPECT_EQ(player->statStages[stat], MAX_STAT_STAGE);
    }
}

DOUBLE_BATTLE_TEST("Acupressure fails on the ally if all of its stats are maximized")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_CLANGOROUS_SOUL) == EFFECT_CLANGOROUS_SOUL);
        ASSUME_STAT_CHANGE(MOVE_HONE_CLAWS, attack: +1, accuracy: +1);
        ASSUME_STAT_CHANGE(MOVE_DOUBLE_TEAM, evasion: +1);
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_BIBAREL) { Ability(ABILITY_SIMPLE); HP(601); MaxHP(601); }
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WYNAUT);
    } WHEN {
        TURN { MOVE(playerRight, MOVE_CLANGOROUS_SOUL); }
        TURN { MOVE(playerRight, MOVE_CLANGOROUS_SOUL); }
        TURN { MOVE(playerRight, MOVE_CLANGOROUS_SOUL); }
        for (u32 j = 0; j < 3; j++)
            TURN { MOVE(playerRight, MOVE_HONE_CLAWS); }
        for (u32 j = 0; j < 3; j++)
            TURN { MOVE(playerRight, MOVE_DOUBLE_TEAM); }
        TURN { MOVE(playerLeft, MOVE_ACUPRESSURE, target: playerRight); }
    } SCENE {
        MESSAGE("Wobbuffet used Acupressure!");
        NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_ACUPRESSURE, playerLeft);
        MESSAGE("But it failed!");
    } THEN {
        for (enum Stat stat = STAT_ATK; stat < NUM_BATTLE_STATS; stat++)
            EXPECT_EQ(playerRight->statStages[stat], MAX_STAT_STAGE);
    }
}

SINGLE_BATTLE_TEST("Acupressure doesn't try to increase a stat that has been maximized")
{
    u32 boostedStats = 0;

    GIVEN {
        ASSUME(GetMoveEffect(MOVE_BELLY_DRUM) == EFFECT_BELLY_DRUM);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_BELLY_DRUM); }
        TURN { MOVE(player, MOVE_ACUPRESSURE, target: player); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_BELLY_DRUM, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_ACUPRESSURE, player);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, player);
    } THEN {
        EXPECT_EQ(player->statStages[STAT_ATK], MAX_STAT_STAGE);
        for (enum Stat stat = STAT_DEF; stat < NUM_BATTLE_STATS; stat++) {
            if (player->statStages[stat] == DEFAULT_STAT_STAGE + 2)
                boostedStats++;
            else
                EXPECT_EQ(player->statStages[stat], DEFAULT_STAT_STAGE);
        }
        EXPECT_EQ(boostedStats, 1);
    }
}

SINGLE_BATTLE_TEST("Acupressure increases one of its stats by 2 stages at random")
{
    u32 boostedStats = 0;

    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_ACUPRESSURE, target: player); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_ACUPRESSURE, player);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, player);
    } THEN {
        for (enum Stat stat = STAT_ATK; stat < NUM_BATTLE_STATS; stat++) {
            if (player->statStages[stat] == DEFAULT_STAT_STAGE + 2)
                boostedStats++;
            else
                EXPECT_EQ(player->statStages[stat], DEFAULT_STAT_STAGE);
        }
        EXPECT_EQ(boostedStats, 1);
    }
}

// Triple Battles required to test
//TO_DO_BATTLE_TEST("Acupressure works on the ally if the user targeted itself but switched positions via Triple Battle shift before execution");
//TO_DO_BATTLE_TEST("Acupressure fails on the user if it targeted its ally but switched positions via Triple Battle shift before execution");
