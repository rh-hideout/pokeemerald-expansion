#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Mega Sol multiplies the power of Fire-type moves by 1.5x", s16 damage)
{
    ASSUME(GetMoveType(MOVE_EMBER) == TYPE_FIRE);

    enum Ability ability;
    PARAMETRIZE { ability = ABILITY_FLAME_BODY;}
    PARAMETRIZE { ability = ABILITY_MEGA_SOL;}
    GIVEN {
        PLAYER(SPECIES_MEGANIUM) { Ability(ability);}
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

SINGLE_BATTLE_TEST("Mega Sol halves the power of the user's Water-type moves", s16 damage)
{

    enum Ability ability;
    PARAMETRIZE { ability = ABILITY_FLAME_BODY;}
    PARAMETRIZE { ability = ABILITY_MEGA_SOL;}

    GIVEN {
        ASSUME(GetMoveType(MOVE_WATER_GUN) == TYPE_WATER);
        PLAYER(SPECIES_MEGANIUM) { Ability(ability);}
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
        ASSUME(GetMoveEffect(MOVE_WEATHER_BALL) == EFFECT_WEATHER_BALL);
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
        ASSUME(GetMoveEffect(MOVE_SYNTHESIS) == EFFECT_SYNTHESIS);
        WITH_CONFIG(B_TIME_OF_DAY_HEALING_MOVES, GEN_3);
        PLAYER(SPECIES_MEGANIUM) { HP(1); MaxHP(300); Ability(ABILITY_MEGA_SOL);  }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_SYNTHESIS); }
    } SCENE {
        HP_BAR(player, damage: -(300 / 1.5));
    }
}

SINGLE_BATTLE_TEST("Mega Sol ignores Sandstorm's solarbeam power reduction, and its rock defense boost", s16 damage)
{
    enum Ability ability;
    PARAMETRIZE { ability = ABILITY_NONE;}
    PARAMETRIZE { ability = ABILITY_MEGA_SOL;}

    GIVEN {
        ASSUME(GetMoveEffect(MOVE_SOLARBEAM) == EFFECT_SOLAR_BEAM);
        ASSUME(GetMoveType(MOVE_SOLARBEAM) == TYPE_GRASS);
        PLAYER(SPECIES_SUNKERN) { Ability(ability);}
        OPPONENT(SPECIES_BASTIODON) { Ability(ABILITY_SAND_STREAM);}
    } WHEN {
        TURN {}
        TURN { MOVE(player, MOVE_SOLAR_BEAM); }
        if (ability == ABILITY_NONE) {
            TURN { SKIP_TURN(player); }
        }
    } SCENE {
        HP_BAR(player); // checking sandstorm occurred
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SOLAR_BEAM, player);
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_MUL_EQ(results[0].damage, Q_4_12(3), results[1].damage);
    }
}

SINGLE_BATTLE_TEST("Mega Sol doesn't trigger the foe's Leaf Guard", s16 damage)
{
    enum Move move;
    PARAMETRIZE { move = MOVE_CELEBRATE;}
    PARAMETRIZE { move = MOVE_SUNNY_DAY;}

    GIVEN {
	ASSUME(GetConfig(B_SANDSTORM_SOLAR_BEAM) >= GEN_3);
        ASSUME(GetMoveEffect(MOVE_WILL_O_WISP) == EFFECT_NON_VOLATILE_STATUS);
        ASSUME(GetMoveNonVolatileStatus(MOVE_WILL_O_WISP) == MOVE_EFFECT_BURN);
        PLAYER(SPECIES_SUNKERN) { Ability(ABILITY_MEGA_SOL);}
        OPPONENT(SPECIES_LEAFEON) { Ability(ABILITY_LEAF_GUARD);}
    } WHEN {
        TURN { MOVE(player, move); }
        TURN { MOVE(player, MOVE_WILL_O_WISP); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, move, player);
        if (move == MOVE_CELEBRATE) {
	    ANIMATION(ANIM_TYPE_MOVE, MOVE_WILL_O_WISP, player);
            STATUS_ICON(opponent, STATUS1_BURN);
        }
        else {
	    NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_WILL_O_WISP, player);
            ABILITY_POPUP(opponent, ABILITY_LEAF_GUARD);
            MESSAGE("It doesn't affect the opposing Leafeon…");
            NOT STATUS_ICON(opponent, STATUS1_BURN);
        }
    }
}


SINGLE_BATTLE_TEST("Mega Sol ignores Cloud Nine", s16 damage)
{
    ASSUME(GetMoveType(MOVE_EMBER) == TYPE_FIRE);

    enum Ability ability;
    PARAMETRIZE { ability = ABILITY_FLAME_BODY;}
    PARAMETRIZE { ability = ABILITY_MEGA_SOL;}
    GIVEN {
        PLAYER(SPECIES_MEGANIUM) { Ability(ability);}
        OPPONENT(SPECIES_WOBBUFFET)  { Ability(ABILITY_CLOUD_NINE);}
    } WHEN {
        TURN { MOVE(player, MOVE_EMBER); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_EMBER, player);
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_MUL_EQ(results[0].damage, Q_4_12(1.5), results[1].damage);
    }
}

SINGLE_BATTLE_TEST("Solar Beam does not need a charging turn if user has Mega Sol")
{
    enum Ability ability;

    PARAMETRIZE { ability = ABILITY_MEGA_SOL; }
    PARAMETRIZE { ability = ABILITY_LEAF_GUARD; }

    GIVEN {
        ASSUME(GetMoveEffect(MOVE_SOLARBEAM) == EFFECT_SOLAR_BEAM);
        ASSUME(GetMoveType(MOVE_SOLARBEAM) == TYPE_GRASS);
        PLAYER(SPECIES_MEGANIUM) { Ability(ability); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_SOLAR_BEAM); }
        if (ability == ABILITY_LEAF_GUARD) {
            TURN { SKIP_TURN(player); }
        }
    } SCENE {
        if (ability == ABILITY_LEAF_GUARD) {
            MESSAGE("Meganium used Solar Beam!");
	    NOT HP_BAR(opponent);
            ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, opponent);
        }
	else  {
            MESSAGE("Meganium used Solar Beam!");
            ANIMATION(ANIM_TYPE_MOVE, MOVE_SOLAR_BEAM, player);
            HP_BAR(opponent);
            ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, opponent);
        }
    }
}
