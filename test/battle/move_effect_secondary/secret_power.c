#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(MoveHasAdditionalEffect(MOVE_SECRET_POWER, MOVE_EFFECT_SECRET_POWER) == TRUE);
}

SINGLE_BATTLE_TEST("Secret Power inflicts paralysis in Electric Terrain")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_ELECTRIC_TERRAIN) == EFFECT_TERRAIN);
        ASSUME(GetMoveTerrainType(MOVE_ELECTRIC_TERRAIN) == B_TERRAIN_ELECTRIC);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_ELECTRIC_TERRAIN); MOVE(player, MOVE_SECRET_POWER); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_ELECTRIC_TERRAIN, opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SECRET_POWER, player);
        STATUS_ICON(opponent, paralysis: TRUE);
    }
}

SINGLE_BATTLE_TEST("Secret Power inflicts sleep in Grassy Terrain")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_GRASSY_TERRAIN) == EFFECT_TERRAIN);
        ASSUME(GetMoveTerrainType(MOVE_GRASSY_TERRAIN) == B_TERRAIN_GRASSY);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_GRASSY_TERRAIN); MOVE(player, MOVE_SECRET_POWER); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_GRASSY_TERRAIN, opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SECRET_POWER, player);
        STATUS_ICON(opponent, sleep: TRUE);
    }
}

SINGLE_BATTLE_TEST("Secret Power lowers Speed in Psychic Terrain")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_PSYCHIC_TERRAIN) == EFFECT_TERRAIN);
        ASSUME(GetMoveTerrainType(MOVE_PSYCHIC_TERRAIN) == B_TERRAIN_PSYCHIC);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_PSYCHIC_TERRAIN); MOVE(player, MOVE_SECRET_POWER); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_PSYCHIC_TERRAIN, opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SECRET_POWER, player);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponent);
    } THEN {
        EXPECT_EQ(opponent->statStages[STAT_SPEED], DEFAULT_STAT_STAGE - 1);
    }
}

SINGLE_BATTLE_TEST("Secret Power lowers Sp. Atk in Misty Terrain")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_MISTY_TERRAIN) == EFFECT_TERRAIN);
        ASSUME(GetMoveTerrainType(MOVE_MISTY_TERRAIN) == B_TERRAIN_MISTY);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_MISTY_TERRAIN); MOVE(player, MOVE_SECRET_POWER); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_MISTY_TERRAIN, opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SECRET_POWER, player);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponent);
    } THEN {
        EXPECT_EQ(opponent->statStages[STAT_SPATK], DEFAULT_STAT_STAGE - 1);
    }
}

SINGLE_BATTLE_TEST("Secret Power does not inflict its secondary effect if the user faints")
{
    KNOWN_FAILING;
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_ELECTRIC_TERRAIN) == EFFECT_ELECTRIC_TERRAIN);
        ASSUME(GetMoveCategory(MOVE_SECRET_POWER) == DAMAGE_CATEGORY_PHYSICAL);
        ASSUME(gItemsInfo[ITEM_JABOCA_BERRY].holdEffect == HOLD_EFFECT_JABOCA_BERRY);
        PLAYER(SPECIES_WOBBUFFET) { HP(1); }
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_WOBBUFFET) { Item(ITEM_JABOCA_BERRY); }
    } WHEN {
        TURN { MOVE(player, MOVE_ELECTRIC_TERRAIN); }
        TURN { MOVE(player, MOVE_SECRET_POWER, WITH_RNG(RNG_SECONDARY_EFFECT, TRUE)); SEND_OUT(player, 1); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_ELECTRIC_TERRAIN, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SECRET_POWER, player);
        HP_BAR(opponent);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_BERRY, opponent);
        HP_BAR(player, hp: 0);
        MESSAGE("Wobbuffet was hurt by the opposing Wobbuffet's Jaboca Berry!");
        MESSAGE("Wobbuffet fainted!");
        NONE_OF {
            ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_PRZ, opponent);
            STATUS_ICON(opponent, paralysis: TRUE);
        }
    } THEN {
        EXPECT_EQ(opponent->status1, STATUS1_NONE);
    }
}
