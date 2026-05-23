#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(MoveMakesContact(MOVE_SCRATCH));
    ASSUME(GetMoveEffect(MOVE_PROTECT) == EFFECT_PROTECT);
    ASSUME(GetMoveEffect(MOVE_KINGS_SHIELD) == EFFECT_PROTECT);
    ASSUME(GetMoveEffect(MOVE_SPIKY_SHIELD) == EFFECT_PROTECT);
    ASSUME(GetMoveEffect(MOVE_BANEFUL_BUNKER) == EFFECT_PROTECT);
    ASSUME(GetMoveEffect(MOVE_BURNING_BULWARK) == EFFECT_PROTECT);
    ASSUME(GetMoveEffect(MOVE_OBSTRUCT) == EFFECT_PROTECT);
    ASSUME(GetMoveEffect(MOVE_SILK_TRAP) == EFFECT_PROTECT);
}

TO_DO_BATTLE_TEST("TODO: Write Unseen Fist (Ability) test titles")

SINGLE_BATTLE_TEST("Unseen Fist ignores Protect when user has Protective Pads, but not with Punching Glove", s16 damage)
{
    u32 item;

    PARAMETRIZE { item = ITEM_PROTECTIVE_PADS; }
    PARAMETRIZE { item = ITEM_PUNCHING_GLOVE; }

    GIVEN {
        ASSUME(MoveMakesContact(MOVE_MACH_PUNCH));
        ASSUME(IsPunchingMove(MOVE_MACH_PUNCH));
        ASSUME(GetItemHoldEffect(ITEM_PROTECTIVE_PADS) == HOLD_EFFECT_PROTECTIVE_PADS);
        ASSUME(GetItemHoldEffect(ITEM_PUNCHING_GLOVE) == HOLD_EFFECT_PUNCHING_GLOVE);
        PLAYER(SPECIES_URSHIFU) { Ability(ABILITY_UNSEEN_FIST); Item(item); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_PROTECT); MOVE(player, MOVE_MACH_PUNCH); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_PROTECT, opponent);
        if (item != ITEM_PUNCHING_GLOVE)
            ANIMATION(ANIM_TYPE_MOVE, MOVE_MACH_PUNCH, player);
        else
            NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_MACH_PUNCH, player);
    }
}

SINGLE_BATTLE_TEST("Unseen Fist bypasses protect effects without triggering their contact effects")
{
    enum Move protectMove = MOVE_NONE;
    u8 loweredStat = 0;

    PARAMETRIZE { protectMove = MOVE_SPIKY_SHIELD;    loweredStat = 0; }
    PARAMETRIZE { protectMove = MOVE_KINGS_SHIELD;    loweredStat = STAT_ATK; }
    PARAMETRIZE { protectMove = MOVE_BANEFUL_BUNKER;  loweredStat = 0; }
    PARAMETRIZE { protectMove = MOVE_BURNING_BULWARK; loweredStat = 0; }
    PARAMETRIZE { protectMove = MOVE_OBSTRUCT;        loweredStat = STAT_DEF; }
    PARAMETRIZE { protectMove = MOVE_SILK_TRAP;       loweredStat = STAT_SPEED; }

    GIVEN {
        PLAYER(SPECIES_URSHIFU) { Ability(ABILITY_UNSEEN_FIST); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, protectMove); MOVE(player, MOVE_SCRATCH); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, protectMove, opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, player);
        HP_BAR(opponent);
        NONE_OF {
            HP_BAR(player);
            STATUS_ICON(player, STATUS1_POISON);
            STATUS_ICON(player, STATUS1_BURN);
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, player);
        }
    } THEN {
        EXPECT_EQ(player->hp, player->maxHP);
        EXPECT_EQ(player->status1, STATUS1_NONE);
        if (loweredStat != 0)
            EXPECT_EQ(player->statStages[loweredStat], DEFAULT_STAT_STAGE);
    }
}
