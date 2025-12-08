#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Grudge depletes all PP of the move that fainted the target")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { HP(1); }
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET) { Moves(MOVE_CELEBRATE, MOVE_SCRATCH, MOVE_POUND, MOVE_SURF); };
    } WHEN {
        TURN {
            MOVE(player, MOVE_GRUDGE);
            MOVE(opponent, MOVE_SCRATCH);
            SEND_OUT(player, 1);
        }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_GRUDGE, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, opponent);
        MESSAGE("Wobbuffet fainted!");
    } THEN {
        EXPECT_GT(opponent->pp[0], 0);
        EXPECT_EQ(opponent->pp[1], 0);
        EXPECT_GT(opponent->pp[2], 0);
        EXPECT_GT(opponent->pp[3], 0);
    }
}

SINGLE_BATTLE_TEST("Grudge does not deplete PP of a Z-Move")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { HP(1); }
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET) { Item(ITEM_NORMALIUM_Z); Moves(MOVE_CELEBRATE, MOVE_SCRATCH, MOVE_POUND, MOVE_SURF); };
    } WHEN {
        TURN {
            MOVE(player, MOVE_GRUDGE);
            MOVE(opponent, MOVE_SCRATCH, gimmick: GIMMICK_Z_MOVE);
            SEND_OUT(player, 1);
        }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_GRUDGE, player);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_ZMOVE_ACTIVATE, opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_BREAKNECK_BLITZ, opponent);
        MESSAGE("Wobbuffet fainted!");
    } THEN {
        EXPECT_GT(opponent->pp[0], 0);
        EXPECT_GT(opponent->pp[1], 0);
        EXPECT_GT(opponent->pp[2], 0);
        EXPECT_GT(opponent->pp[3], 0);
    }
}

TO_DO_BATTLE_TEST("Grudge depletes all PP from a Max Move's base move")
TO_DO_BATTLE_TEST("Grudge does not activate for Struggle")
TO_DO_BATTLE_TEST("Grudge's effect disappears if the user takes a new turn - Move");
TO_DO_BATTLE_TEST("Grudge's effect disappears if the user takes a new turn - Sleep");
TO_DO_BATTLE_TEST("Grudge's effect disappears if the user takes a new turn - Paralysis");
TO_DO_BATTLE_TEST("Grudge's effect disappears if the user takes a new turn - Flinching");
TO_DO_BATTLE_TEST("Grudge's effect doesn't trigger on indirect damage - Sandstorm");
TO_DO_BATTLE_TEST("Grudge's effect doesn't trigger on indirect damage - Leech Seed");
TO_DO_BATTLE_TEST("Grudge's effect doesn't trigger on indirect damage - Future Sight");
