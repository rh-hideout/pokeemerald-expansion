#include "global.h"
#include "test/battle.h"
SINGLE_BATTLE_TEST("Swords Dance test")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_SWORDS_DANCE); }
    } SCENE {
        // ANIMATION(ANIM_TYPE_MOVE, MOVE_SWORDS_DANCE, player);
        // ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, player);
    } THEN {
        // EXPECT_EQ(player->statStages[STAT_ATK], 8);
    }
}

#if 0
DOUBLE_BATTLE_TEST("Stat Change test 1")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_MAWILE) { Ability(ABILITY_HYPER_CUTTER); }
        OPPONENT(SPECIES_MAWILE) { Ability(ABILITY_HYPER_CUTTER); }
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_GROWL); }
    }
}

DOUBLE_BATTLE_TEST("Stat Change test 2")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_MAWILE) { Ability(ABILITY_HYPER_CUTTER); }
        OPPONENT(SPECIES_VOLTORB) { Ability(ABILITY_SOUNDPROOF); }
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_GROWL); }
    }
}

SINGLE_BATTLE_TEST("Stat Change test 3")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_FLAME_CHARGE); }
    }
}

SINGLE_BATTLE_TEST("Stat Change test 4")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_ICY_WIND); }
    }
}

DOUBLE_BATTLE_TEST("Stat Change test 5")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_G_MAX_FOAM_BURST, target: opponentRight); }
    }
}

SINGLE_BATTLE_TEST("Stat Change test 6")
{
    GIVEN {
        PLAYER(SPECIES_TERAPAGOS_TERASTAL);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_TERA_BLAST, gimmick: GIMMICK_TERA); }
    }
}

// Tests for On side changes if battler is not alive

DOUBLE_BATTLE_TEST("Stat Change test 7")
{
    GIVEN {
        PLAYER(SPECIES_ARCANINE) { Ability(ABILITY_INTIMIDATE); }
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_ARCANINE) { Ability(ABILITY_INTIMIDATE); }
        OPPONENT(SPECIES_MANKEY) { Ability(ABILITY_DEFIANT); }
    } WHEN {
        TURN {}
    }
}

DOUBLE_BATTLE_TEST("Stat Change test 8")
{
    GIVEN {
        ASSUME(gItemsInfo[ITEM_BRIGHT_POWDER].holdEffect == HOLD_EFFECT_EVASION_UP);
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET) { Item(ITEM_BRIGHT_POWDER); }
        OPPONENT(SPECIES_BELDUM) { Ability(ABILITY_CLEAR_BODY); }
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_GROWL, hit: FALSE); }
    } SCENE {
        NONE_OF {
            ANIMATION(ANIM_TYPE_MOVE, MOVE_GROWL, playerLeft);
            MESSAGE("But it failed!"); // Explicit string check was added because of a bugfix.
        }
        MESSAGE("The opposing Wobbuffet avoided the attack!");
    }
}

DOUBLE_BATTLE_TEST("Stat Change test 9")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_BELDUM) { Ability(ABILITY_CLEAR_BODY); }
        OPPONENT(SPECIES_BELDUM) { Ability(ABILITY_CLEAR_BODY); }
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_GROWL); }
    } SCENE {
        NONE_OF {
            ANIMATION(ANIM_TYPE_MOVE, MOVE_GROWL, playerLeft);
            ABILITY_POPUP(opponentLeft, ABILITY_CLEAR_BODY);
            ABILITY_POPUP(opponentRight, ABILITY_CLEAR_BODY);
        }
        MESSAGE("But it failed!");
    }
}

DOUBLE_BATTLE_TEST("Stat Change test 10")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_BELDUM) { Ability(ABILITY_CLEAR_BODY); }
        OPPONENT(SPECIES_VOLTORB) { Ability(ABILITY_SOUNDPROOF); }
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_GROWL); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_GROWL, playerLeft);
        ABILITY_POPUP(opponentRight, ABILITY_SOUNDPROOF);
        ABILITY_POPUP(opponentLeft, ABILITY_CLEAR_BODY);
    }
}

DOUBLE_BATTLE_TEST("Stat Change test 11")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_BELDUM) { Ability(ABILITY_CLEAR_BODY); }
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_CHARM, target: opponentLeft); }
        TURN { MOVE(playerLeft, MOVE_CHARM, target: opponentLeft); }
        TURN { MOVE(playerLeft, MOVE_CHARM, target: opponentLeft); }
        TURN { MOVE(playerLeft, MOVE_GROWL); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CHARM, playerLeft);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CHARM, playerLeft);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CHARM, playerLeft);
        NONE_OF {
            ANIMATION(ANIM_TYPE_MOVE, MOVE_GROWL, playerLeft);
            MESSAGE("The opposing Wobbuffet's Attack won't go any lower!");
            ABILITY_POPUP(opponentRight, ABILITY_CLEAR_BODY);
        }
        MESSAGE("But it failed!");
    }
}

SINGLE_BATTLE_TEST("Stat Change test 12")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_CHARM); }
        TURN { MOVE(player, MOVE_CHARM); }
        TURN { MOVE(player, MOVE_CHARM); }
        TURN { MOVE(player, MOVE_GROWL); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CHARM, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CHARM, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CHARM, player);
        NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_GROWL, player);
        MESSAGE("The opposing Wobbuffet's Attack won't go any lower!");
    }
}

DOUBLE_BATTLE_TEST("Stat Change test 13")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponentRight, MOVE_SUBSTITUTE); MOVE(playerLeft, MOVE_LEER); }
    } SCENE {
        // ANIMATION(ANIM_TYPE_MOVE, MOVE_SWORDS_DANCE, player);
        // ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, player);
    } THEN {
        // EXPECT_EQ(player->statStages[STAT_ATK], 8);
    }
}

SINGLE_BATTLE_TEST("Stat Change test 14")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET) { Ability(ABILITY_MIRROR_ARMOR); }
    } WHEN {
        TURN { MOVE(player, MOVE_LEER); }
    } SCENE {
        // ANIMATION(ANIM_TYPE_MOVE, MOVE_SWORDS_DANCE, player);
        // ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, player);
    } THEN {
        // EXPECT_EQ(player->statStages[STAT_ATK], 8);
    }
}

DOUBLE_BATTLE_TEST("Stat Change test 15")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_SWAGGER, target: opponentLeft); }
    } SCENE {
        // ANIMATION(ANIM_TYPE_MOVE, MOVE_SWORDS_DANCE, player);
        // ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, player);
    } THEN {
        // EXPECT_EQ(player->statStages[STAT_ATK], 8);
    }
}
#endif
