#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(GetMoveEffect(MOVE_JUNGLE_HEALING) == EFFECT_JUNGLE_HEALING);
}

DOUBLE_BATTLE_TEST("Jungle Healing fails if user and partner are both at full hp")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_JUNGLE_HEALING); }
    } SCENE {
        NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_JUNGLE_HEALING, playerLeft);
        MESSAGE("But it failed!");
    }
}

DOUBLE_BATTLE_TEST("Jungle Healing recovers 25% of hp and heals their non volatile for both user and partner")
{
    s16 healing[2];

    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Status1(STATUS1_BURN); HP(1); }
        PLAYER(SPECIES_WYNAUT) { Status1(STATUS1_POISON); HP(1); }
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_JUNGLE_HEALING); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_JUNGLE_HEALING, playerLeft);
        HP_BAR(playerLeft, captureDamage: &healing[0]);
        STATUS_ICON(playerLeft, none: TRUE);
        HP_BAR(playerRight, captureDamage: &healing[1]);
        STATUS_ICON(playerRight, none: TRUE);
    } THEN {
        EXPECT_EQ(playerLeft->maxHP / 4, -healing[0]);
        EXPECT_EQ(playerRight->maxHP / 4, -healing[1]);
    }
}

DOUBLE_BATTLE_TEST("Jungle Healing does not fail if at least one target can be healed")
{
    bool32 partner = FALSE;
    PARAMETRIZE { partner = FALSE; }
    PARAMETRIZE { partner = TRUE; }

    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { if (!partner){ HP(1); } }
        PLAYER(SPECIES_WOBBUFFET) { if (partner) { HP(1); } }
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_JUNGLE_HEALING); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_JUNGLE_HEALING, playerLeft);
        if (partner) {
            HP_BAR(playerRight);
        } else {
            HP_BAR(playerLeft);
        }
    }
}

DOUBLE_BATTLE_TEST("Jungle Healing will cure user and ally's non volatiles without healing hp")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Status1(STATUS1_BURN); }
        PLAYER(SPECIES_WYNAUT) { Status1(STATUS1_POISON); }
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_JUNGLE_HEALING); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_JUNGLE_HEALING, playerLeft);
        STATUS_ICON(playerLeft, none: TRUE);
        STATUS_ICON(playerRight, none: TRUE);
    }
}

