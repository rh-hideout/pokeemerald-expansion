#include "global.h"
#include "test/battle.h"

DOUBLE_BATTLE_TEST("Strong winds remove Flying-type weaknesses of all battlers") // Electric, Ice, Rock
{
    u16 move;
    bool32 targetPlayer;

    PARAMETRIZE { move = MOVE_THUNDER_SHOCK; targetPlayer = TRUE; }
    PARAMETRIZE { move = MOVE_ICE_BEAM; targetPlayer = TRUE; }
    PARAMETRIZE { move = MOVE_ROCK_THROW; targetPlayer = TRUE; }
    PARAMETRIZE { move = MOVE_THUNDER_SHOCK; targetPlayer = FALSE; }
    PARAMETRIZE { move = MOVE_ICE_BEAM; targetPlayer = FALSE; }
    PARAMETRIZE { move = MOVE_ROCK_THROW; targetPlayer = FALSE; }

    GIVEN {
        ASSUME(GetMoveType(MOVE_THUNDER_SHOCK) == TYPE_ELECTRIC);
        ASSUME(GetMoveType(MOVE_ICE_BEAM) == TYPE_ICE);
        ASSUME(GetMoveType(MOVE_ROCK_THROW) == TYPE_ROCK);
        ASSUME(GetSpeciesType(SPECIES_PIDGEY, 0) == TYPE_NORMAL);
        ASSUME(GetSpeciesType(SPECIES_PIDGEY, 1) == TYPE_FLYING);
        PLAYER(SPECIES_RAYQUAZA) { Ability(ABILITY_DELTA_STREAM); }
        PLAYER(SPECIES_PIDGEY);
        OPPONENT(SPECIES_PIDGEY);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        if (targetPlayer)
            TURN { MOVE(opponentLeft, move, target: playerRight); }
        else
            TURN { MOVE(playerRight, move, target: opponentLeft); }
    } SCENE {
        if (targetPlayer) {
            if (move == MOVE_THUNDER_SHOCK)
                MESSAGE("The opposing Pidgey used Thunder Shock!");
            else if (move == MOVE_ICE_BEAM)
                MESSAGE("The opposing Pidgey used Ice Beam!");
            else
                MESSAGE("The opposing Pidgey used Rock Throw!");
            MESSAGE("The mysterious strong winds weakened the attack!");
            ANIMATION(ANIM_TYPE_MOVE, move, opponentLeft);
        } else {
            if (move == MOVE_THUNDER_SHOCK)
                MESSAGE("Pidgey used Thunder Shock!");
            else if (move == MOVE_ICE_BEAM)
                MESSAGE("Pidgey used Ice Beam!");
            else
                MESSAGE("Pidgey used Rock Throw!");
            MESSAGE("The mysterious strong winds weakened the attack!");
            ANIMATION(ANIM_TYPE_MOVE, move, playerRight);
        }
    }
}

DOUBLE_BATTLE_TEST("Strong winds remove Flying-type weaknesses of all battlers - Inverse Battle", s16 damagePlayer, s16 damageOpponent) // Bug, Fighting, Grass
{
    u16 move;
    bool32 strongWinds;

    PARAMETRIZE { move = MOVE_BUG_BITE; strongWinds = FALSE; }
    PARAMETRIZE { move = MOVE_BUG_BITE; strongWinds = TRUE; }
    PARAMETRIZE { move = MOVE_KARATE_CHOP; strongWinds = FALSE; }
    PARAMETRIZE { move = MOVE_KARATE_CHOP; strongWinds = TRUE; }
    PARAMETRIZE { move = MOVE_VINE_WHIP; strongWinds = FALSE; }
    PARAMETRIZE { move = MOVE_VINE_WHIP; strongWinds = TRUE; }

    GIVEN {
        FLAG_SET(B_FLAG_INVERSE_BATTLE);
        ASSUME(GetMoveType(MOVE_BUG_BITE) == TYPE_BUG);
        ASSUME(GetMoveType(MOVE_KARATE_CHOP) == TYPE_FIGHTING);
        ASSUME(GetMoveType(MOVE_VINE_WHIP) == TYPE_GRASS);
        ASSUME(GetSpeciesType(SPECIES_TORNADUS, 0) == TYPE_FLYING);
        ASSUME(GetSpeciesType(SPECIES_TORNADUS, 1) == TYPE_FLYING);
        if (strongWinds)
            PLAYER(SPECIES_RAYQUAZA) { Ability(ABILITY_DELTA_STREAM); }
        else
            PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_TORNADUS);
        OPPONENT(SPECIES_TORNADUS);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN {
            MOVE(opponentLeft, move, target: playerRight);
            MOVE(playerRight, move, target: opponentLeft);
        }
    } SCENE {
        HP_BAR(playerRight, captureDamage: &results[i].damagePlayer);
        HP_BAR(opponentLeft, captureDamage: &results[i].damageOpponent);
    } FINALLY {
        EXPECT_GT(results[0].damagePlayer, results[1].damagePlayer);
        EXPECT_GT(results[0].damageOpponent, results[1].damageOpponent);
        EXPECT_GT(results[2].damagePlayer, results[3].damagePlayer);
        EXPECT_GT(results[2].damageOpponent, results[3].damageOpponent);
        EXPECT_GT(results[4].damagePlayer, results[5].damagePlayer);
        EXPECT_GT(results[4].damageOpponent, results[5].damageOpponent);
    }
}

SINGLE_BATTLE_TEST("Strong winds prevent Weakness Policy from activating on Flying-type weaknesses")
{
    GIVEN {
        ASSUME(GetItemHoldEffect(ITEM_WEAKNESS_POLICY) == HOLD_EFFECT_WEAKNESS_POLICY);
        ASSUME(GetMoveType(MOVE_THUNDER_SHOCK) == TYPE_ELECTRIC);
        ASSUME(GetSpeciesType(SPECIES_PIDGEY, 0) == TYPE_NORMAL);
        ASSUME(GetSpeciesType(SPECIES_PIDGEY, 1) == TYPE_FLYING);
        PLAYER(SPECIES_RAYQUAZA) { Ability(ABILITY_DELTA_STREAM); Moves(MOVE_THUNDER_SHOCK); }
        OPPONENT(SPECIES_PIDGEY) { Item(ITEM_WEAKNESS_POLICY); }
    } WHEN {
        TURN { MOVE(player, MOVE_THUNDER_SHOCK); }
    } SCENE {
        MESSAGE("Rayquaza used Thunder Shock!");
        MESSAGE("The mysterious strong winds weakened the attack!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_THUNDER_SHOCK, player);
        HP_BAR(opponent);
        NOT ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_EFFECT, opponent);
    }
}

SINGLE_BATTLE_TEST("Anticipation still triggers with Strong Winds active")
{
    GIVEN {
        ASSUME(GetMoveType(MOVE_THUNDER_SHOCK) == TYPE_ELECTRIC);
        ASSUME(GetSpeciesType(SPECIES_PIDGEY, 0) == TYPE_NORMAL);
        ASSUME(GetSpeciesType(SPECIES_PIDGEY, 1) == TYPE_FLYING);
        PLAYER(SPECIES_RAYQUAZA) { Ability(ABILITY_DELTA_STREAM); Moves(MOVE_THUNDER_SHOCK); }
        OPPONENT(SPECIES_PIDGEY) { Ability(ABILITY_ANTICIPATION); }
    } WHEN {
        TURN { }
    } SCENE {
        ABILITY_POPUP(opponent, ABILITY_ANTICIPATION);
    }
}

SINGLE_BATTLE_TEST("Anticipation still triggers with Strong Winds active in Inverse Battle")
{
    GIVEN {
        FLAG_SET(B_FLAG_INVERSE_BATTLE);
        ASSUME(GetMoveType(MOVE_VINE_WHIP) == TYPE_GRASS);
        ASSUME(GetSpeciesType(SPECIES_TORNADUS, 0) == TYPE_FLYING);
        ASSUME(GetSpeciesType(SPECIES_TORNADUS, 1) == TYPE_FLYING);
        PLAYER(SPECIES_RAYQUAZA) { Ability(ABILITY_DELTA_STREAM); Moves(MOVE_VINE_WHIP); }
        OPPONENT(SPECIES_TORNADUS) { Ability(ABILITY_ANTICIPATION); }
    } WHEN {
        TURN { }
    } SCENE {
        ABILITY_POPUP(opponent, ABILITY_ANTICIPATION);
    }
}

SINGLE_BATTLE_TEST("Strong winds don't affect Stealth Rock's damage")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_STEALTH_ROCK) == EFFECT_STEALTH_ROCK);
        ASSUME(GetSpeciesType(SPECIES_PIDGEY, 0) == TYPE_NORMAL);
        ASSUME(GetSpeciesType(SPECIES_PIDGEY, 1) == TYPE_FLYING);
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_PIDGEY);
        OPPONENT(SPECIES_RAYQUAZA) { Ability(ABILITY_DELTA_STREAM); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_STEALTH_ROCK); }
        TURN { SWITCH(player, 1); }
    } SCENE {
        s32 maxHP = GetMonData(&PLAYER_PARTY[1], MON_DATA_MAX_HP);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_STEALTH_ROCK, opponent);
        HP_BAR(player, damage: maxHP / 4);
    }
}

SINGLE_BATTLE_TEST("Strong winds makes Sunny Day fail")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_SUNNY_DAY) == EFFECT_SUNNY_DAY);
        PLAYER(SPECIES_RAYQUAZA) { Ability(ABILITY_DELTA_STREAM); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_SUNNY_DAY); }
    } SCENE {
        MESSAGE("The opposing Wobbuffet used Sunny Day!");
        NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_SUNNY_DAY, opponent);
        MESSAGE("The mysterious strong winds blow on regardless!");
    }
}

SINGLE_BATTLE_TEST("Strong winds makes Rain Dance fail")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_RAIN_DANCE) == EFFECT_RAIN_DANCE);
        PLAYER(SPECIES_RAYQUAZA) { Ability(ABILITY_DELTA_STREAM); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_RAIN_DANCE); }
    } SCENE {
        MESSAGE("The opposing Wobbuffet used Rain Dance!");
        NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_RAIN_DANCE, opponent);
        MESSAGE("The mysterious strong winds blow on regardless!");
    }
}

SINGLE_BATTLE_TEST("Strong winds makes Sandstorm fail")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_SANDSTORM) == EFFECT_SANDSTORM);
        PLAYER(SPECIES_RAYQUAZA) { Ability(ABILITY_DELTA_STREAM); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_SANDSTORM); }
    } SCENE {
        MESSAGE("The opposing Wobbuffet used Sandstorm!");
        NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_SANDSTORM, opponent);
        MESSAGE("The mysterious strong winds blow on regardless!");
    }
}

SINGLE_BATTLE_TEST("Strong winds makes Hail fail")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_HAIL) == EFFECT_HAIL);
        PLAYER(SPECIES_RAYQUAZA) { Ability(ABILITY_DELTA_STREAM); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_HAIL); }
    } SCENE {
        MESSAGE("The opposing Wobbuffet used Hail!");
        NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_HAIL, opponent);
        MESSAGE("The mysterious strong winds blow on regardless!");
    }
}

SINGLE_BATTLE_TEST("Strong winds makes Snowscape fail") // Extrapolation
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_SNOWSCAPE) == EFFECT_SNOWSCAPE);
        PLAYER(SPECIES_RAYQUAZA) { Ability(ABILITY_DELTA_STREAM); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_SNOWSCAPE); }
    } SCENE {
        MESSAGE("The opposing Wobbuffet used Snowscape!");
        NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_SNOWSCAPE, opponent);
        MESSAGE("The mysterious strong winds blow on regardless!");
    }
}

SINGLE_BATTLE_TEST("Strong winds makes Drought fail to activate")
{
    GIVEN {
        PLAYER(SPECIES_RAYQUAZA) { Ability(ABILITY_DELTA_STREAM); }
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_NINETALES) { Ability(ABILITY_DROUGHT); }
    } WHEN {
        TURN { SWITCH(opponent, 1); }
    } SCENE {
        ABILITY_POPUP(opponent, ABILITY_DROUGHT);
        MESSAGE("The mysterious strong winds blow on regardless!");
    }
}

SINGLE_BATTLE_TEST("Strong winds makes Drizzle fail to activate")
{
    GIVEN {
        PLAYER(SPECIES_RAYQUAZA) { Ability(ABILITY_DELTA_STREAM); }
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_POLITOED) { Ability(ABILITY_DRIZZLE); }
    } WHEN {
        TURN { SWITCH(opponent, 1); }
    } SCENE {
        ABILITY_POPUP(opponent, ABILITY_DRIZZLE);
        MESSAGE("The mysterious strong winds blow on regardless!");
    }
}

SINGLE_BATTLE_TEST("Strong winds makes Sand Stream fail to activate")
{
    GIVEN {
        PLAYER(SPECIES_RAYQUAZA) { Ability(ABILITY_DELTA_STREAM); }
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_HIPPOWDON) { Ability(ABILITY_SAND_STREAM); }
    } WHEN {
        TURN { SWITCH(opponent, 1); }
    } SCENE {
        ABILITY_POPUP(opponent, ABILITY_SAND_STREAM);
        MESSAGE("The mysterious strong winds blow on regardless!");
    }
}

SINGLE_BATTLE_TEST("Strong winds makes Snow Warning fail to activate")
{
    GIVEN {
        PLAYER(SPECIES_RAYQUAZA) { Ability(ABILITY_DELTA_STREAM); }
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_ABOMASNOW) { Ability(ABILITY_SNOW_WARNING); }
    } WHEN {
        TURN { SWITCH(opponent, 1); }
    } SCENE {
        ABILITY_POPUP(opponent, ABILITY_SNOW_WARNING);
        MESSAGE("The mysterious strong winds blow on regardless!");
    }
}

SINGLE_BATTLE_TEST("Strong winds can be replaced by Desolate Land")
{
    GIVEN {
        PLAYER(SPECIES_RAYQUAZA) { Ability(ABILITY_DELTA_STREAM); }
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_GROUDON) { Item(ITEM_RED_ORB); }
    } WHEN {
        TURN { SWITCH(opponent, 1); }
    } SCENE {
        ABILITY_POPUP(opponent, ABILITY_DESOLATE_LAND);
        MESSAGE("The sunlight turned extremely harsh!");
    } THEN {
        EXPECT(gBattleWeather & B_WEATHER_SUN_PRIMAL);
    }
}

SINGLE_BATTLE_TEST("Strong winds can be replaced by Primordial Sea")
{
    GIVEN {
        PLAYER(SPECIES_RAYQUAZA) { Ability(ABILITY_DELTA_STREAM); }
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_KYOGRE) { Item(ITEM_BLUE_ORB); }
    } WHEN {
        TURN { SWITCH(opponent, 1); }
    } SCENE {
        ABILITY_POPUP(opponent, ABILITY_PRIMORDIAL_SEA);
        MESSAGE("A heavy rain began to fall!");
    } THEN {
        EXPECT(gBattleWeather & B_WEATHER_RAIN_PRIMAL);
    }
}
