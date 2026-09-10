#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(GetItemHoldEffect(ITEM_SNOWBALL) == HOLD_EFFECT_SNOWBALL);
}

SINGLE_BATTLE_TEST("Snowball raises Attack by one stage and is consumed when its holder is hit by an Ice-type move")
{
    enum Species species;
    enum Ability ability;
    s32 expectedDelta;

    PARAMETRIZE { species = SPECIES_WOBBUFFET; ability = ABILITY_SHADOW_TAG; expectedDelta = 1; }
    PARAMETRIZE { species = SPECIES_BIBAREL;   ability = ABILITY_SIMPLE;     expectedDelta = 2; }
    PARAMETRIZE { species = SPECIES_INKAY;     ability = ABILITY_CONTRARY;   expectedDelta = -1; }

    GIVEN {
        ASSUME(GetMoveType(MOVE_ICE_BEAM) == TYPE_ICE);
        PLAYER(species) { Ability(ability); HP(400); MaxHP(400); SpDefense(400); Item(ITEM_SNOWBALL); }
        OPPONENT(SPECIES_WOBBUFFET) { SpAttack(1); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_ICE_BEAM); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_ICE_BEAM, opponent);
        HP_BAR(player);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_EFFECT, player);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, player);
    } THEN {
        EXPECT_EQ(player->statStages[STAT_ATK], DEFAULT_STAT_STAGE + expectedDelta);
        EXPECT_EQ(player->item, ITEM_NONE);
    }
}

SINGLE_BATTLE_TEST("Magic Room and Embargo prevent Snowball from activating")
{
    enum Move setupMove;

    PARAMETRIZE { setupMove = MOVE_MAGIC_ROOM; }
    PARAMETRIZE { setupMove = MOVE_EMBARGO; }

    GIVEN {
        ASSUME(GetMoveEffect(MOVE_MAGIC_ROOM) == EFFECT_MAGIC_ROOM);
        ASSUME(GetMoveEffect(MOVE_EMBARGO) == EFFECT_EMBARGO);
        ASSUME(GetMoveType(MOVE_ICE_BEAM) == TYPE_ICE);
        PLAYER(SPECIES_WOBBUFFET) { HP(400); MaxHP(400); SpDefense(400); Item(ITEM_SNOWBALL); }
        OPPONENT(SPECIES_WOBBUFFET) { SpAttack(1); }
    } WHEN {
        TURN { MOVE(opponent, setupMove); }
        TURN { MOVE(opponent, MOVE_ICE_BEAM); }
    } THEN {
        EXPECT_EQ(player->statStages[STAT_ATK], DEFAULT_STAT_STAGE);
        EXPECT_EQ(player->item, ITEM_SNOWBALL);
    }
}

SINGLE_BATTLE_TEST("Refrigerate activates Snowball unless the Ability is suppressed")
{
    enum Move setupMove;
    s32 expectedDelta;
    enum Item expectedItem;

    PARAMETRIZE { setupMove = MOVE_CELEBRATE;   expectedDelta = 1; expectedItem = ITEM_NONE; }
    PARAMETRIZE { setupMove = MOVE_GASTRO_ACID; expectedDelta = 0; expectedItem = ITEM_SNOWBALL; }

    GIVEN {
        ASSUME(GetMoveEffect(MOVE_GASTRO_ACID) == EFFECT_GASTRO_ACID);
        ASSUME(GetMoveType(MOVE_HYPER_VOICE) == TYPE_NORMAL);
        ASSUME(IsSoundMove(MOVE_HYPER_VOICE));
        PLAYER(SPECIES_WOBBUFFET) { Speed(2); HP(400); MaxHP(400); SpDefense(400); Item(ITEM_SNOWBALL); }
        OPPONENT(SPECIES_AMAURA) { Speed(1); SpAttack(1); Ability(ABILITY_REFRIGERATE); }
    } WHEN {
        TURN { MOVE(player, setupMove); MOVE(opponent, MOVE_HYPER_VOICE); }
    } THEN {
        EXPECT_EQ(player->statStages[STAT_ATK], DEFAULT_STAT_STAGE + expectedDelta);
        EXPECT_EQ(player->item, expectedItem);
    }
}
