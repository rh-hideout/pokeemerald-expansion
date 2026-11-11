#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Clangorous Soul cuts the user's HP by 1/3")
{
    s16 dmg;
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { HP(300); MaxHP(300); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_CLANGOROUS_SOUL); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CLANGOROUS_SOUL, player);
        HP_BAR(player, captureDamage: &dmg);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, player);
    } THEN {
        EXPECT_EQ(gBattleMons[0].maxHP / 3, dmg);
    }
}

SINGLE_BATTLE_TEST("Clangorous Soul raises the user's Atk, Def, Sp. Atk. Sp. Def and Speed by 1 stage")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { HP(300); MaxHP(300); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_CLANGOROUS_SOUL); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CLANGOROUS_SOUL, player);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, player);
    } THEN {
        EXPECT_EQ(player->statStages[STAT_ATK], DEFAULT_STAT_STAGE + 1);
        EXPECT_EQ(player->statStages[STAT_DEF], DEFAULT_STAT_STAGE + 1);
        EXPECT_EQ(player->statStages[STAT_SPATK], DEFAULT_STAT_STAGE + 1);
        EXPECT_EQ(player->statStages[STAT_SPDEF], DEFAULT_STAT_STAGE + 1);
        EXPECT_EQ(player->statStages[STAT_SPEED], DEFAULT_STAT_STAGE + 1);
    }
}

SINGLE_BATTLE_TEST("Clangorous Soul fails if the user's HP is less or equal than 1/3")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { HP(100); MaxHP(300); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_CLANGOROUS_SOUL); }
    } SCENE {
        NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_CLANGOROUS_SOUL, player);
    }
}

SINGLE_BATTLE_TEST("Clangorous Soul fails if Attack, Defense, Sp. Attack, Sp. Defense and Speed are all maxed out")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_CLANGOROUS_SOUL) == EFFECT_CLANGOROUS_SOUL);
        PLAYER(SPECIES_BIBAREL) { Ability(ABILITY_SIMPLE); HP(300); MaxHP(300); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        for (u32 j = 0; j < 3; j++)
        {
            TURN { MOVE(player, MOVE_CLANGOROUS_SOUL); }
            TURN { MOVE(player, MOVE_RECOVER); }
        }
        TURN { MOVE(player, MOVE_CLANGOROUS_SOUL); }
    } SCENE {
        for (u32 j = 0; j < 3; j++)
            ANIMATION(ANIM_TYPE_MOVE, MOVE_CLANGOROUS_SOUL, player);
        NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_CLANGOROUS_SOUL, player);
        MESSAGE("But it failed!");
    } THEN {
        EXPECT_EQ(player->hp, player->maxHP);
        EXPECT_EQ(player->statStages[STAT_ATK], MAX_STAT_STAGE);
        EXPECT_EQ(player->statStages[STAT_DEF], MAX_STAT_STAGE);
        EXPECT_EQ(player->statStages[STAT_SPATK], MAX_STAT_STAGE);
        EXPECT_EQ(player->statStages[STAT_SPDEF], MAX_STAT_STAGE);
        EXPECT_EQ(player->statStages[STAT_SPEED], MAX_STAT_STAGE);
    }
}
