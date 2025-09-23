#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Living Shield halves damage from super effective moves", s16 damage)
{
    u32 ability;
    PARAMETRIZE { ability = ABILITY_HYPER_CUTTER; }
    PARAMETRIZE { ability = ABILITY_LIVING_SHIELD; }
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_PARASECT) { Ability(ability); }
    } WHEN {
        TURN { MOVE(player, MOVE_ROCK_THROW); }
    } SCENE {
        MESSAGE("Wobbuffet used Rock Throw!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_ROCK_THROW, player);
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_MUL_EQ(results[0].damage, Q_4_12(0.5), results[1].damage);
    }
}

SINGLE_BATTLE_TEST("Living Shield halves damage from x4 effective moves", s16 damage)
{
    u32 ability;
    PARAMETRIZE { ability = ABILITY_HYPER_CUTTER; }
    PARAMETRIZE { ability = ABILITY_LIVING_SHIELD; }
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_PARASECT) { Ability(ability); }
    } WHEN {
        TURN { MOVE(player, MOVE_PECK); }
    } SCENE {
        MESSAGE("Wobbuffet used Peck!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_PECK, player);
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_MUL_EQ(results[0].damage, Q_4_12(0.5), results[1].damage);
    }
}
