#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(GetMoveEffect(MOVE_HAZE) == EFFECT_HAZE);
}

SINGLE_BATTLE_TEST("Haze resets stat changes", s16 damage)
{
    bool32 haze;
    PARAMETRIZE { haze = FALSE; }
    PARAMETRIZE { haze = TRUE; }
    GIVEN {
        ASSUME_STAT_CHANGE(MOVE_MEDITATE, attack: +1);
        ASSUME(GetMoveCategory(MOVE_SCRATCH) == DAMAGE_CATEGORY_PHYSICAL);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        if (haze) TURN { MOVE(player, MOVE_MEDITATE); MOVE(opponent, MOVE_HAZE); }
        TURN { MOVE(player, MOVE_SCRATCH); }
    } SCENE {
        if (haze) {
            ANIMATION(ANIM_TYPE_MOVE, MOVE_HAZE, opponent);
            MESSAGE("All stat changes were eliminated!");
        }
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, player);
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_EQ(results[0].damage, results[1].damage);
    }
}

SINGLE_BATTLE_TEST("Haze resets Focus Energy (Gen 1 and 4)")
{
    u32 genConfig;
    PARAMETRIZE { genConfig = GEN_1; }
    PARAMETRIZE { genConfig = GEN_4; }
    GIVEN {
        WITH_CONFIG(B_HAZE_FOCUS_ENERGY, genConfig);
        WITH_CONFIG(B_CRIT_CHANCE, genConfig);
        WITH_CONFIG(B_FOCUS_ENERGY_CRIT_RATIO, genConfig);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_FOCUS_ENERGY); }
        TURN { MOVE(opponent, MOVE_HAZE); }
        TURN { MOVE(player, MOVE_FOCUS_ENERGY); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_FOCUS_ENERGY, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_HAZE, opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_FOCUS_ENERGY, player);
    }
}

SINGLE_BATTLE_TEST("Haze does not reset Focus Energy (Gen 2-3 and 5+)")
{
    u32 genConfig;
    PARAMETRIZE { genConfig = GEN_2; }
    PARAMETRIZE { genConfig = GEN_3; }
    PARAMETRIZE { genConfig = GEN_5; }
    PARAMETRIZE { genConfig = GEN_6; }
    PARAMETRIZE { genConfig = GEN_7; }
    PARAMETRIZE { genConfig = GEN_8; }
    PARAMETRIZE { genConfig = GEN_9; }
    GIVEN {
        WITH_CONFIG(B_HAZE_FOCUS_ENERGY, genConfig);
        WITH_CONFIG(B_CRIT_CHANCE, genConfig);
        WITH_CONFIG(B_FOCUS_ENERGY_CRIT_RATIO, genConfig);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_FOCUS_ENERGY); }
        TURN { MOVE(opponent, MOVE_HAZE); }
        TURN { MOVE(player, MOVE_FOCUS_ENERGY); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_FOCUS_ENERGY, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_HAZE, opponent);
        MESSAGE("But it failed!");
    }
}
