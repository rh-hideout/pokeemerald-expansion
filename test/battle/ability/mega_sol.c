#include "global.h"
#include "test/battle.h"

#include "global.h"
#include "test/battle.h"


SINGLE_BATTLE_TEST("Mega Sol multiplies the power of Fire-type moves by 1.5x", s16 damage)
{
    enum Ability ability;
    PARAMETRIZE { ability = ABILITY_FLAME_BODY;}
    PARAMETRIZE { ability = ABILITY_MEGA_SOL;}
    GIVEN {
        PLAYER(SPECIES_LARVESTA) { Ability(ability);}
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_EMBER); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_EMBER, player);
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_MUL_EQ(results[0].damage, Q_4_12(1.5), results[1].damage);
    }
}

SINGLE_BATTLE_TEST("Mega Sol multiplies the power of Water-type moves by 0.5x", s16 damage)
{
    enum Ability ability;
    PARAMETRIZE { ability = ABILITY_FLAME_BODY;}
    PARAMETRIZE { ability = ABILITY_MEGA_SOL;}

    GIVEN {
        PLAYER(SPECIES_LARVESTA) { Ability(ability);}
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_WATER_GUN); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_WATER_GUN, player);
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_MUL_EQ(results[0].damage, Q_4_12(0.5), results[1].damage);
    }
}


SINGLE_BATTLE_TEST("Weather Ball doubles its power and turns to a Fire-type move if user has Mega Sol", s16 damage)
{
    enum Ability ability;
    PARAMETRIZE { ability = ABILITY_FLAME_BODY;}
    PARAMETRIZE { ability = ABILITY_MEGA_SOL;}

    GIVEN {
        PLAYER(SPECIES_DARUMAKA_GALAR) { Ability(ability);}
        OPPONENT(SPECIES_PINSIR);
    } WHEN {
        TURN { MOVE(player, MOVE_WEATHER_BALL); }
    } SCENE {
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_MUL_EQ(results[0].damage, Q_4_12(6.0), results[1].damage); // double base power + type effectiveness + sun 50% boost
    }
}


SINGLE_BATTLE_TEST("Synthesis recovers 2/3 of the user's max HP if user has Mega Sol (Gen3+)")
{
    GIVEN {
        WITH_CONFIG(B_TIME_OF_DAY_HEALING_MOVES, GEN_3);
        PLAYER(SPECIES_MEGANIUM) { HP(1); MaxHP(300); Ability(ABILITY_MEGA_SOL);  }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_SYNTHESIS); }
    } SCENE {
        HP_BAR(player, damage: -(300 / 1.5));
    }
}

SINGLE_BATTLE_TEST("Solar Beam does not need a charging turn if user has Mega Sol")
{
    enum Ability ability;

    PARAMETRIZE { ability = ABILITY_MEGA_SOL; }
    PARAMETRIZE { ability = ABILITY_FLAME_BODY; }

    GIVEN {
        PLAYER(SPECIES_LARVESTA) { Ability(ability); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_SOLAR_BEAM); }
        if (ability == ABILITY_NONE) {
            TURN { SKIP_TURN(player); }
        }
    } SCENE {
        if (ability == ABILITY_NONE) {
            MESSAGE("Larvesta used Solar Beam!");
            MESSAGE("Larvesta absorbed light!");
            ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, opponent);
        }
        MESSAGE("Larvesta used Solar Beam!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SOLAR_BEAM, player);
    }
}
