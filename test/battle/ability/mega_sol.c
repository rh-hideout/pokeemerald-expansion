#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Mega Sol multiplies the power of Fire-type moves by 1.5x")
{
    s16 damage[2];

    GIVEN {
        ASSUME(GetMoveType(MOVE_EMBER) == TYPE_FIRE);
        PLAYER(SPECIES_MEGANIUM) { Item(ITEM_MEGANIUMITE); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_EMBER, gimmick: GIMMICK_MEGA); MOVE(opponent, MOVE_SKILL_SWAP); }
        TURN { MOVE(player, MOVE_EMBER); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_EMBER, player);
        HP_BAR(opponent, captureDamage: &damage[0]);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SKILL_SWAP, opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_EMBER, player);
        HP_BAR(opponent, captureDamage: &damage[1]);
    } THEN {
        EXPECT_MUL_EQ(damage[1], Q_4_12(1.5), damage[0]);
    }
}

SINGLE_BATTLE_TEST("Mega Sol halves the power of the user's Water-type moves")
{
    s16 damage[2];

    GIVEN {
        ASSUME(GetMoveType(MOVE_WATER_GUN) == TYPE_WATER);
        PLAYER(SPECIES_MEGANIUM) { Item(ITEM_MEGANIUMITE); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_WATER_GUN, gimmick: GIMMICK_MEGA); MOVE(opponent, MOVE_SKILL_SWAP); }
        TURN { MOVE(player, MOVE_WATER_GUN); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_WATER_GUN, player);
        HP_BAR(opponent, captureDamage: &damage[0]);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SKILL_SWAP, opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_WATER_GUN, player);
        HP_BAR(opponent, captureDamage: &damage[1]);
    } THEN {
        EXPECT_MUL_EQ(damage[1], Q_4_12(0.5), damage[0]);
    }
}

SINGLE_BATTLE_TEST("Weather Ball doubles its power and turns to a Fire-type move if user has Mega Sol")
{
    s16 damage[2];

    GIVEN {
        ASSUME(GetMoveEffect(MOVE_WEATHER_BALL) == EFFECT_WEATHER_BALL);
        PLAYER(SPECIES_MEGANIUM) { Item(ITEM_MEGANIUMITE); }
        OPPONENT(SPECIES_PINSIR){HP(9999); MaxHP(9999);}
    } WHEN {
        TURN { MOVE(player, MOVE_WEATHER_BALL, gimmick: GIMMICK_MEGA); MOVE(opponent, MOVE_SKILL_SWAP); }
        TURN { MOVE(player, MOVE_WEATHER_BALL); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_WEATHER_BALL, player);
        HP_BAR(opponent, captureDamage: &damage[0]);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SKILL_SWAP, opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_WEATHER_BALL, player);
        HP_BAR(opponent, captureDamage: &damage[1]);
    } THEN {
        EXPECT_MUL_EQ(damage[1], Q_4_12(6.0), damage[0]); // double base power + type effectiveness + sun 50% boost
    }
}

SINGLE_BATTLE_TEST("Synthesis recovers 2/3 of the user's max HP if user has Mega Sol (Gen3+)")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_SYNTHESIS) == EFFECT_SYNTHESIS);
        WITH_CONFIG(B_TIME_OF_DAY_HEALING_MOVES, GEN_3);
        PLAYER(SPECIES_MEGANIUM) { HP(1); MaxHP(300); Item(ITEM_MEGANIUMITE); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_SYNTHESIS, gimmick: GIMMICK_MEGA); }
    } SCENE {
        HP_BAR(player, damage: -(300 / 1.5));
    }
}

SINGLE_BATTLE_TEST("Mega Sol ignores Sandstorm's solarbeam power reduction, and its rock defense boost")
{
    s16 damage[2];

    GIVEN {
        ASSUME(GetMoveEffect(MOVE_SOLARBEAM) == EFFECT_SOLAR_BEAM);
        ASSUME(GetMoveType(MOVE_SOLARBEAM) == TYPE_GRASS);
        PLAYER(SPECIES_MEGANIUM) { Item(ITEM_MEGANIUMITE); }
        OPPONENT(SPECIES_BASTIODON) { Ability(ABILITY_SAND_STREAM);}
    } WHEN {
        TURN { MOVE(player, MOVE_SOLAR_BEAM, gimmick: GIMMICK_MEGA); MOVE(opponent, MOVE_SKILL_SWAP); }
        TURN { MOVE(player, MOVE_SOLAR_BEAM); }
        TURN { SKIP_TURN(player); }
    } SCENE {
        ABILITY_POPUP(opponent, ABILITY_SAND_STREAM);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SOLAR_BEAM, player);
        HP_BAR(opponent, captureDamage: &damage[0]);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SKILL_SWAP, opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SOLAR_BEAM, player);
        HP_BAR(opponent, captureDamage: &damage[1]);
    } THEN {
        EXPECT_MUL_EQ(damage[1], Q_4_12(3), damage[0]);
    }
}

SINGLE_BATTLE_TEST("Mega Sol doesn't trigger the foe's Leaf Guard", s16 damage)
{
    enum Move move;
    PARAMETRIZE { move = MOVE_CELEBRATE;}
    PARAMETRIZE { move = MOVE_SUNNY_DAY;}

    GIVEN {
        WITH_CONFIG(B_SANDSTORM_SOLAR_BEAM, GEN_3);
        ASSUME(GetMoveEffect(MOVE_WILL_O_WISP) == EFFECT_NON_VOLATILE_STATUS);
        ASSUME(GetMoveNonVolatileStatus(MOVE_WILL_O_WISP) == MOVE_EFFECT_BURN);
        PLAYER(SPECIES_MEGANIUM_MEGA) { Ability(ABILITY_MEGA_SOL);}
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
    PARAMETRIZE { ability = ABILITY_OVERGROW;}
    PARAMETRIZE { ability = ABILITY_MEGA_SOL;}
    GIVEN {
        PLAYER(SPECIES_MEGANIUM_MEGA) { Ability(ability);}
        OPPONENT(SPECIES_WOBBUFFET)  { Ability(ABILITY_CLOUD_NINE); HP(9999); }
    } WHEN {
        TURN { MOVE(player, MOVE_EMBER); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_EMBER, player);
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_MUL_EQ(results[0].damage, Q_4_12(1.5), results[1].damage);
    }
}

SINGLE_BATTLE_TEST("Mega Sol: Solar Beam does not need a charging turn if user has Mega Sol")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_SOLARBEAM) == EFFECT_SOLAR_BEAM);
        ASSUME(GetMoveType(MOVE_SOLARBEAM) == TYPE_GRASS);
        PLAYER(SPECIES_MEGANIUM) { Item(ITEM_MEGANIUMITE); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_SOLAR_BEAM, gimmick: GIMMICK_MEGA); MOVE(opponent, MOVE_CELEBRATE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SOLAR_BEAM, player);
        HP_BAR(opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, opponent);
    }
}

SINGLE_BATTLE_TEST("Mega Sol: Growth increases Attack and Sp. Atk by 2 stages under Mega Sol (Gen 5+)")
{
    GIVEN {
        WITH_CONFIG(B_GROWTH_STAT_RAISE, GEN_1);
        ASSUME(GetMoveEffect(MOVE_GROWTH) == EFFECT_GROWTH);
        PLAYER(SPECIES_MEGANIUM) { Item(ITEM_MEGANIUMITE); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_GROWTH, gimmick: GIMMICK_MEGA); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_GROWTH, player);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, player);
    } THEN {
        EXPECT_EQ(player->statStages[STAT_SPATK], DEFAULT_STAT_STAGE + 2);
        EXPECT_EQ(player->statStages[STAT_ATK], DEFAULT_STAT_STAGE + 2);
    }
}

SINGLE_BATTLE_TEST("Mega Sol ignores Sand Veil")
{
    PASSES_RANDOMLY(5, 5, RNG_ACCURACY);
    GIVEN {
        ASSUME(GetMoveAccuracy(MOVE_POUND) == 100);
        PLAYER(SPECIES_SANDSHREW) { Ability(ABILITY_SAND_VEIL); }
        OPPONENT(SPECIES_MEGANIUM) { Item(ITEM_MEGANIUMITE); }
    } WHEN {
        TURN { MOVE(player, MOVE_SANDSTORM); }
        TURN { MOVE(opponent, MOVE_POUND, gimmick: GIMMICK_MEGA); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SANDSTORM, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_POUND, opponent);
        HP_BAR(player);
    }
}

SINGLE_BATTLE_TEST("Mega Sol ignores Snow Cloak")
{
    PASSES_RANDOMLY(5, 5, RNG_ACCURACY);
    GIVEN {
        ASSUME(GetMoveAccuracy(MOVE_POUND) == 100);
        PLAYER(SPECIES_GLACEON) { Ability(ABILITY_SNOW_CLOAK); }
        OPPONENT(SPECIES_MEGANIUM) { Item(ITEM_MEGANIUMITE); }
    } WHEN {
        TURN { MOVE(player, MOVE_HAIL); }
        TURN { MOVE(opponent, MOVE_POUND, gimmick: GIMMICK_MEGA); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_HAIL, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_POUND, opponent);
        HP_BAR(player);
    }
}

// Not clear if this is a bug or not
SINGLE_BATTLE_TEST("Mega Sol doesn't prevent other weather based activations (Electro Shot)")
{
    GIVEN {
        ASSUME(GetMoveTwoTurnAttackWeather(MOVE_ELECTRO_SHOT) == B_WEATHER_RAIN);
        ASSUME(GetMoveEffect(MOVE_ELECTRO_SHOT) == EFFECT_TWO_TURNS_ATTACK);
        PLAYER(SPECIES_KYOGRE) { Ability(ABILITY_DRIZZLE); }
        OPPONENT(SPECIES_MEGANIUM) { Item(ITEM_MEGANIUMITE); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_ELECTRO_SHOT, gimmick: GIMMICK_MEGA); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_ELECTRO_SHOT, opponent);
        HP_BAR(player);
    }
}

// Not clear if this is a bug or not
SINGLE_BATTLE_TEST("Mega Sol doesn't prevent other weather based activations (Aurora Veil)")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_AURORA_VEIL) == EFFECT_AURORA_VEIL);
        PLAYER(SPECIES_ABOMASNOW) { Ability(ABILITY_SNOW_WARNING); }
        OPPONENT(SPECIES_MEGANIUM) { Item(ITEM_MEGANIUMITE); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_AURORA_VEIL, gimmick: GIMMICK_MEGA); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_AURORA_VEIL, opponent);
    }
}
