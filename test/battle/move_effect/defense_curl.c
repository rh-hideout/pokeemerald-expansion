#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME_STAT_CHANGE(MOVE_DEFENSE_CURL, defense: +1);
    ASSUME(GetMoveEffect(MOVE_ROLLOUT) == EFFECT_ROLLOUT);
    ASSUME(GetMoveEffect(MOVE_ICE_BALL) == EFFECT_ROLLOUT);
}

SINGLE_BATTLE_TEST("Defense Curl raises Defense by 1 stage", s16 damage)
{
    bool32 raiseDefense;
    PARAMETRIZE { raiseDefense = FALSE; }
    PARAMETRIZE { raiseDefense = TRUE; }
    GIVEN {
        ASSUME(GetMoveCategory(MOVE_SCRATCH) == DAMAGE_CATEGORY_PHYSICAL);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        if (raiseDefense) TURN { MOVE(player, MOVE_DEFENSE_CURL); }
        TURN { MOVE(opponent, MOVE_SCRATCH); }
    } SCENE {
        if (raiseDefense) {
            ANIMATION(ANIM_TYPE_MOVE, MOVE_DEFENSE_CURL, player);
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, player);
            MESSAGE("Wobbuffet's Defense rose!");
        }
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, opponent);
        HP_BAR(player, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_MUL_EQ(results[1].damage, Q_4_12(1.5), results[0].damage);
    }
}

SINGLE_BATTLE_TEST("Defense Curl doubles the power of Rollout even if stat couldn't be changed", s16 damage)
{
    bool32 acidArmor = FALSE;

    PARAMETRIZE { acidArmor = TRUE; }
    PARAMETRIZE { acidArmor = FALSE; }

    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        if (acidArmor) {
            TURN { MOVE(player, MOVE_ACID_ARMOR); }
            TURN { MOVE(player, MOVE_ACID_ARMOR); }
            TURN { MOVE(player, MOVE_ACID_ARMOR); }
        }
        TURN { MOVE(player, MOVE_DEFENSE_CURL); }
        TURN { MOVE(player, MOVE_ROLLOUT); }
    } SCENE {
        if (acidArmor) {
            ANIMATION(ANIM_TYPE_MOVE, MOVE_ACID_ARMOR, player);
            ANIMATION(ANIM_TYPE_MOVE, MOVE_ACID_ARMOR, player);
            ANIMATION(ANIM_TYPE_MOVE, MOVE_ACID_ARMOR, player);
        }

        if (acidArmor) {
            NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_DEFENSE_CURL, player);
        } else {
            ANIMATION(ANIM_TYPE_MOVE, MOVE_DEFENSE_CURL, player);
        }

        ANIMATION(ANIM_TYPE_MOVE, MOVE_ROLLOUT, player);
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_EQ(results[0].damage, results[1].damage);
    }
}

SINGLE_BATTLE_TEST("Defense Curl doubles the power of Rollout", s16 damage)
{
    bool32 defenseCurl;

    PARAMETRIZE { defenseCurl = FALSE; }
    PARAMETRIZE { defenseCurl = TRUE; }

    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        if (defenseCurl)
            TURN { MOVE(player, MOVE_DEFENSE_CURL); }
        TURN { MOVE(player, MOVE_ROLLOUT); }
    } SCENE {
        if (defenseCurl)
            ANIMATION(ANIM_TYPE_MOVE, MOVE_DEFENSE_CURL, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_ROLLOUT, player);
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_MUL_EQ(results[0].damage, Q_4_12(2.0), results[1].damage);
    }
}

SINGLE_BATTLE_TEST("Defense Curl doubles the power of Ice Ball", s16 damage)
{
    bool32 defenseCurl;

    PARAMETRIZE { defenseCurl = FALSE; }
    PARAMETRIZE { defenseCurl = TRUE; }

    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        if (defenseCurl)
            TURN { MOVE(player, MOVE_DEFENSE_CURL); }
        TURN { MOVE(player, MOVE_ICE_BALL); }
    } SCENE {
        if (defenseCurl)
            ANIMATION(ANIM_TYPE_MOVE, MOVE_DEFENSE_CURL, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_ICE_BALL, player);
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_MUL_EQ(results[0].damage, Q_4_12(2.0), results[1].damage);
    }
}

SINGLE_BATTLE_TEST("Defense Curl's effect cannot be stacked", s16 damage)
{
    u32 uses;

    PARAMETRIZE { uses = 1; }
    PARAMETRIZE { uses = 2; }

    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_DEFENSE_CURL); }
        if (uses == 2)
            TURN { MOVE(player, MOVE_DEFENSE_CURL); }
        TURN { MOVE(player, MOVE_ROLLOUT); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_DEFENSE_CURL, player);
        if (uses == 2)
            ANIMATION(ANIM_TYPE_MOVE, MOVE_DEFENSE_CURL, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_ROLLOUT, player);
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_EQ(results[0].damage, results[1].damage);
    }
}

SINGLE_BATTLE_TEST("Defense Curl's effect is removed when switching out", s16 damage)
{
    bool32 switchOut;

    PARAMETRIZE { switchOut = FALSE; }
    PARAMETRIZE { switchOut = TRUE; }

    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_DEFENSE_CURL); }
        if (switchOut) {
            TURN { SWITCH(player, 1); }
            TURN { SWITCH(player, 0); }
        }
        TURN { MOVE(player, MOVE_ROLLOUT); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_DEFENSE_CURL, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_ROLLOUT, player);
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_MUL_EQ(results[1].damage, Q_4_12(2.0), results[0].damage);
    }
}

SINGLE_BATTLE_TEST("Baton Pass doesn't pass Defense Curl's effect", s16 damage)
{
    bool32 defenseCurl;

    PARAMETRIZE { defenseCurl = FALSE; }
    PARAMETRIZE { defenseCurl = TRUE; }

    GIVEN {
        ASSUME(GetMoveEffect(MOVE_BATON_PASS) == EFFECT_BATON_PASS);
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        if (defenseCurl)
            TURN { MOVE(player, MOVE_DEFENSE_CURL); }
        TURN { MOVE(player, MOVE_BATON_PASS); SEND_OUT(player, 1); }
        TURN { MOVE(player, MOVE_ROLLOUT); }
    } SCENE {
        if (defenseCurl)
            ANIMATION(ANIM_TYPE_MOVE, MOVE_DEFENSE_CURL, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_BATON_PASS, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_ROLLOUT, player);
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_EQ(results[0].damage, results[1].damage);
    }
}
