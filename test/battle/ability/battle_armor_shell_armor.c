#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Battle Armor halves damage from Rock moves", s16 damage)
{
    u32 ability;
    PARAMETRIZE { ability = ABILITY_HYPER_CUTTER; }
    PARAMETRIZE { ability = ABILITY_BATTLE_ARMOR; }
    PARAMETRIZE { ability = ABILITY_SHELL_ARMOR; }
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_CRAWDAUNT) { Ability(ability); }
    } WHEN {
        TURN { MOVE(player, MOVE_ROCK_THROW); }
    } SCENE {
        MESSAGE("Wobbuffet used Rock Throw!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_ROCK_THROW, player);
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_MUL_EQ(results[0].damage, Q_4_12(0.5), results[1].damage);
        EXPECT_MUL_EQ(results[0].damage, Q_4_12(0.5), results[2].damage);
    }
}

SINGLE_BATTLE_TEST("Battle Armor halves damage from Steel moves", s16 damage)
{
    u32 ability;
    PARAMETRIZE { ability = ABILITY_HYPER_CUTTER; }
    PARAMETRIZE { ability = ABILITY_BATTLE_ARMOR; }
    PARAMETRIZE { ability = ABILITY_SHELL_ARMOR; }
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_CRAWDAUNT) { Ability(ability); }
    } WHEN {
        TURN { MOVE(player, MOVE_IRON_HEAD); }
    } SCENE {
        MESSAGE("Wobbuffet used Iron Head!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_IRON_HEAD, player);
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_MUL_EQ(results[0].damage, Q_4_12(0.5), results[1].damage);
        EXPECT_MUL_EQ(results[0].damage, Q_4_12(0.5), results[2].damage);
    }
}