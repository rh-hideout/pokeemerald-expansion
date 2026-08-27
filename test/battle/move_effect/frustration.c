#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(GetMoveEffect(MOVE_FRUSTRATION) == EFFECT_FRUSTRATION);
}

SINGLE_BATTLE_TEST("Frustration's power increases the lower the user's friendship is", s16 damage)
{
    u32 friendship;
    PARAMETRIZE { friendship = 255; }
    PARAMETRIZE { friendship = 200; }
    PARAMETRIZE { friendship = 100; }
    PARAMETRIZE { friendship = 0; }
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Friendship(friendship); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_FRUSTRATION); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_FRUSTRATION, player);
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } THEN {
        if (i > 0)
            EXPECT_GT(results[i].damage, results[i - 1].damage);
    }
}

SINGLE_BATTLE_TEST("Frustration does 0 damage at max Friendship (Gen 2)")
{
    s16 damage;

    GIVEN {
        WITH_CONFIG(B_UPDATED_MOVE_DATA, GEN_2);
        PLAYER(SPECIES_WOBBUFFET) { Friendship(255); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_FRUSTRATION); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_FRUSTRATION, player);
        HP_BAR(opponent, captureDamage: &damage);
    } THEN {
        EXPECT_EQ(damage, 0);
    }
}

SINGLE_BATTLE_TEST("Frustration does 1 damage at max Friendship (Gen 3+)")
{
    s16 damage;

    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Friendship(255); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_FRUSTRATION); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_FRUSTRATION, player);
        HP_BAR(opponent, captureDamage: &damage);
    } THEN {
        EXPECT_EQ(damage, 1);
    }
}
