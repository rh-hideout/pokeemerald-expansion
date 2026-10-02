#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(GetItemHoldEffect(ITEM_CELL_BATTERY) == HOLD_EFFECT_CELL_BATTERY);
}

SINGLE_BATTLE_TEST("Cell Battery raises Attack by one stage and is consumed when its holder is hit by an Electric-type move")
{
    enum Species species;
    enum Ability ability;
    s32 expectedDelta;

    PARAMETRIZE { species = SPECIES_WOBBUFFET; ability = ABILITY_SHADOW_TAG; expectedDelta = 1; }
    PARAMETRIZE { species = SPECIES_BIBAREL;   ability = ABILITY_SIMPLE;     expectedDelta = 2; }
    PARAMETRIZE { species = SPECIES_INKAY;     ability = ABILITY_CONTRARY;   expectedDelta = -1; }

    GIVEN {
        ASSUME(GetMoveType(MOVE_THUNDER_SHOCK) == TYPE_ELECTRIC);
        PLAYER(species) { Ability(ability); HP(400); MaxHP(400); SpDefense(400); Item(ITEM_CELL_BATTERY); }
        OPPONENT(SPECIES_WOBBUFFET) { SpAttack(1); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_THUNDER_SHOCK); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_THUNDER_SHOCK, opponent);
        HP_BAR(player);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_EFFECT, player);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, player);
    } THEN {
        EXPECT_EQ(player->statStages[STAT_ATK], DEFAULT_STAT_STAGE + expectedDelta);
        EXPECT_EQ(player->item, ITEM_NONE);
    }
}

SINGLE_BATTLE_TEST("Magic Room and Embargo prevent Cell Battery from activating")
{
    enum Move setupMove;

    PARAMETRIZE { setupMove = MOVE_MAGIC_ROOM; }
    PARAMETRIZE { setupMove = MOVE_EMBARGO; }

    GIVEN {
        ASSUME(GetMoveEffect(MOVE_MAGIC_ROOM) == EFFECT_MAGIC_ROOM);
        ASSUME(GetMoveEffect(MOVE_EMBARGO) == EFFECT_EMBARGO);
        ASSUME(GetMoveType(MOVE_THUNDER_SHOCK) == TYPE_ELECTRIC);
        PLAYER(SPECIES_WOBBUFFET) { HP(400); MaxHP(400); SpDefense(400); Item(ITEM_CELL_BATTERY); }
        OPPONENT(SPECIES_WOBBUFFET) { SpAttack(1); }
    } WHEN {
        TURN { MOVE(opponent, setupMove); }
        TURN { MOVE(opponent, MOVE_THUNDER_SHOCK); }
    } THEN {
        EXPECT_EQ(player->statStages[STAT_ATK], DEFAULT_STAT_STAGE);
        EXPECT_EQ(player->item, ITEM_CELL_BATTERY);
    }
}

SINGLE_BATTLE_TEST("Galvanize activates Cell Battery unless the Ability is suppressed")
{
    enum Move setupMove;
    s32 expectedDelta;
    enum Item expectedItem;

    PARAMETRIZE { setupMove = MOVE_CELEBRATE;   expectedDelta = 1; expectedItem = ITEM_NONE; }
    PARAMETRIZE { setupMove = MOVE_GASTRO_ACID; expectedDelta = 0; expectedItem = ITEM_CELL_BATTERY; }

    GIVEN {
        ASSUME(GetMoveEffect(MOVE_GASTRO_ACID) == EFFECT_GASTRO_ACID);
        ASSUME(GetMoveType(MOVE_HYPER_VOICE) == TYPE_NORMAL);
        ASSUME(IsSoundMove(MOVE_HYPER_VOICE));
        PLAYER(SPECIES_WOBBUFFET) { Speed(2); HP(400); MaxHP(400); SpDefense(400); Item(ITEM_CELL_BATTERY); }
        OPPONENT(SPECIES_GEODUDE_ALOLA) { Speed(1); SpAttack(1); Ability(ABILITY_GALVANIZE); }
    } WHEN {
        TURN { MOVE(player, setupMove); MOVE(opponent, MOVE_HYPER_VOICE); }
    } THEN {
        EXPECT_EQ(player->statStages[STAT_ATK], DEFAULT_STAT_STAGE + expectedDelta);
        EXPECT_EQ(player->item, expectedItem);
    }
}
