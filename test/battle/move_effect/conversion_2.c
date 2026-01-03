#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Conversion 2 can change to a type that is immune to the move")
{
    GIVEN {
        WITH_CONFIG(CONFIG_UPDATED_CONVERSION_2, GEN_5);
        ASSUME(GetMoveType(MOVE_EARTHQUAKE) == TYPE_GROUND);
        PLAYER(SPECIES_SWADLOON);
        ASSUME(GetSpeciesType(SPECIES_SWADLOON, 0) == TYPE_BUG);
        ASSUME(GetSpeciesType(SPECIES_SWADLOON, 1) == TYPE_GRASS);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_EARTHQUAKE); MOVE(player, MOVE_CONVERSION_2); }
    } SCENE {
        MESSAGE("The opposing Wobbuffet used Earthquake!");
        MESSAGE("Swadloon used Conversion 2!");
        MESSAGE("Swadloon transformed into the Flying type!");
    }
}
SINGLE_BATTLE_TEST("Conversion 2's type change considers Inverse Battles")
{
    GIVEN {
        FLAG_SET(B_FLAG_INVERSE_BATTLE);
        WITH_CONFIG(CONFIG_UPDATED_CONVERSION_2, GEN_5);
        ASSUME(GetMoveType(MOVE_WATER_GUN) == TYPE_WATER);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_WATER_GUN); MOVE(player, MOVE_CONVERSION_2); }
    } SCENE {
        MESSAGE("The opposing Wobbuffet used Water Gun!");
        ONE_OF {
            MESSAGE("Wobbuffet transformed into the Ground type!");
            MESSAGE("Wobbuffet transformed into the Rock type!");
            MESSAGE("Wobbuffet transformed into the Fire type!");
        }
    }
}

SINGLE_BATTLE_TEST("Conversion 2 randomly changes the type of the user to a type that resists the last move that hit the user (Gen 1-4)")
{
    GIVEN {
        WITH_CONFIG(CONFIG_UPDATED_CONVERSION_2, GEN_4);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_OMINOUS_WIND); MOVE(opponent, MOVE_CONVERSION_2); }
    } SCENE {
        // turn 1
        MESSAGE("Wobbuffet used Ominous Wind!");
        // turn 1
        ONE_OF {
            MESSAGE("The opposing Wobbuffet transformed into the Normal type!");
            MESSAGE("The opposing Wobbuffet transformed into the Dark type!");
        }
    }
}

SINGLE_BATTLE_TEST("Conversion 2's type change considers Struggle to be Normal type (Gen 1-4)")
{
    GIVEN {
        WITH_CONFIG(CONFIG_UPDATED_CONVERSION_2, GEN_4);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_STRUGGLE); }
        TURN { MOVE(player, MOVE_CONVERSION_2); }
    } SCENE {
        // turn 1
        MESSAGE("The opposing Wobbuffet used Struggle!");
        // turn 2
        ONE_OF {
            MESSAGE("Wobbuffet transformed into the Steel type!");
            MESSAGE("Wobbuffet transformed into the Rock type!");
            MESSAGE("Wobbuffet transformed into the Ghost type!");
        }
    }
}

SINGLE_BATTLE_TEST("Conversion 2 randomly changes the type of the user to a type that resists the last used target's move (Gen 5+)")
{
    GIVEN {
        WITH_CONFIG(CONFIG_UPDATED_CONVERSION_2, GEN_5);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_OMINOUS_WIND); MOVE(opponent, MOVE_CONVERSION_2); }
    } SCENE {
        // turn 1
        MESSAGE("Wobbuffet used Ominous Wind!");
        // turn 1
        ONE_OF {
            MESSAGE("The opposing Wobbuffet transformed into the Normal type!");
            MESSAGE("The opposing Wobbuffet transformed into the Dark type!");
        }
    }
}

SINGLE_BATTLE_TEST("Conversion 2's type change considers status moves (Gen 5+)")
{
    GIVEN {
        WITH_CONFIG(CONFIG_UPDATED_CONVERSION_2, GEN_5);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_CURSE); }
        TURN { MOVE(player, MOVE_CONVERSION_2); }
    } SCENE {
        // turn 1
        MESSAGE("The opposing Wobbuffet used Curse!");
        // turn 2
        ONE_OF {
            MESSAGE("Wobbuffet transformed into the Normal type!");
            MESSAGE("Wobbuffet transformed into the Dark type!");
        }
    }
}

SINGLE_BATTLE_TEST("Conversion 2's type change considers the type of moves called by other moves")
{
    GIVEN {
        WITH_CONFIG(CONFIG_UPDATED_CONVERSION_2, GEN_5);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_OMINOUS_WIND); MOVE(opponent, MOVE_MIRROR_MOVE); }
        TURN { MOVE(player, MOVE_CONVERSION_2); }
    } SCENE {
        // turn 1
        MESSAGE("The opposing Wobbuffet used Mirror Move!");
        // turn 2
        ONE_OF {
            MESSAGE("Wobbuffet transformed into the Normal type!");
            MESSAGE("Wobbuffet transformed into the Dark type!");
        }
    }
}

SINGLE_BATTLE_TEST("Conversion 2's type change considers dynamic type moves")
{
    GIVEN {
        WITH_CONFIG(CONFIG_UPDATED_CONVERSION_2, GEN_5);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_HAIL); MOVE(opponent, MOVE_WEATHER_BALL); }
        TURN { MOVE(player, MOVE_CONVERSION_2); }
    } SCENE {
        // turn 1
        MESSAGE("The opposing Wobbuffet used Weather Ball!");
        // turn 2
        ONE_OF {
            MESSAGE("Wobbuffet transformed into the Steel type!");
            MESSAGE("Wobbuffet transformed into the Fire type!");
            MESSAGE("Wobbuffet transformed into the Water type!");
            MESSAGE("Wobbuffet transformed into the Ice type!");
        }
    }
}

SINGLE_BATTLE_TEST("Conversion 2's type change considers move types changed by Normalize and Electrify")
{
    GIVEN {
        WITH_CONFIG(CONFIG_UPDATED_CONVERSION_2, GEN_5);
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_NORMALIZE); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_ELECTRIFY); MOVE(opponent, MOVE_POUND); }
        TURN { MOVE(player, MOVE_CONVERSION_2); }
        TURN { MOVE(player, MOVE_WATER_GUN); MOVE(opponent, MOVE_CONVERSION_2); }
    } SCENE {
        // turn 1
        MESSAGE("Wobbuffet used Electrify!");
        MESSAGE("The opposing Wobbuffet used Pound!");
        // turn 2
        ONE_OF {
            MESSAGE("Wobbuffet transformed into the Ground type!");
            MESSAGE("Wobbuffet transformed into the Dragon type!");
            MESSAGE("Wobbuffet transformed into the Grass type!");
            MESSAGE("Wobbuffet transformed into the Electric type!");
        }
        // turn 3
        MESSAGE("Wobbuffet used Water Gun!");
        ONE_OF {
            MESSAGE("The opposing Wobbuffet transformed into the Steel type!");
            MESSAGE("The opposing Wobbuffet transformed into the Rock type!");
            MESSAGE("The opposing Wobbuffet transformed into the Ghost type!");
        }
    }
}

SINGLE_BATTLE_TEST("Conversion 2's type change fails targeting Struggle (Gen 5+)")
{
    GIVEN {
        WITH_CONFIG(CONFIG_UPDATED_CONVERSION_2, GEN_5);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_STRUGGLE); }
        TURN { MOVE(player, MOVE_CONVERSION_2); }
    } SCENE {
        // turn 1
        MESSAGE("The opposing Wobbuffet used Struggle!");
        // turn 2
        MESSAGE("Wobbuffet used Conversion 2!");
        MESSAGE("But it failed!");
    }
}

SINGLE_BATTLE_TEST("Conversion 2 fails if the move used is of typeless damage (Gen 5+)")
{
    GIVEN {
        WITH_CONFIG(CONFIG_UPDATED_CONVERSION_2, GEN_5);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_ENTEI);
    } WHEN {
        TURN { MOVE(opponent, MOVE_BURN_UP); }
        TURN { MOVE(opponent, MOVE_REVELATION_DANCE); }
        TURN { MOVE(player, MOVE_CONVERSION_2); }
    } SCENE {
        // turn 1
        MESSAGE("The opposing Entei used Burn Up!");
        // turn 2
        MESSAGE("The opposing Entei used Revelation Dance!");
        // turn 3
        MESSAGE("Wobbuffet used Conversion 2!");
        MESSAGE("But it failed!");
    }
}

SINGLE_BATTLE_TEST("Conversion 2 fails if the targeted move is Stellar Type")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { TeraType(TYPE_STELLAR); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_TERA_BLAST, gimmick: GIMMICK_TERA); MOVE(opponent, MOVE_CONVERSION_2); }
    } SCENE {
        // turn 1
        MESSAGE("Wobbuffet used Tera Blast!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_TERA_BLAST, player);
        // turn 1
        MESSAGE("The opposing Wobbuffet used Conversion 2!");
        MESSAGE("But it failed!");
    }
}

SINGLE_BATTLE_TEST("Conversion 2 fails if used by a Terastallized Pokemon")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { TeraType(TYPE_PSYCHIC); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_TACKLE); }
        TURN { MOVE(player, MOVE_CONVERSION_2, gimmick: GIMMICK_TERA); }
    } SCENE {
        MESSAGE("Wobbuffet used Conversion 2!");
        MESSAGE("But it failed!");
    }
}

SINGLE_BATTLE_TEST("Conversion 2 fails if last hit by a Stellar-type move (Gen 1-4)")
{
    GIVEN {
        WITH_CONFIG(CONFIG_UPDATED_CONVERSION_2, GEN_4);
        PLAYER(SPECIES_WOBBUFFET) { TeraType(TYPE_STELLAR); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_TERA_BLAST, gimmick: GIMMICK_TERA); MOVE(opponent, MOVE_CONVERSION_2); }
    } SCENE {
        // turn 1
        MESSAGE("Wobbuffet used Tera Blast!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_TERA_BLAST, player);
        // turn 2
        MESSAGE("The opposing Wobbuffet used Conversion 2!");
        MESSAGE("But it failed!");
    }
}

SINGLE_BATTLE_TEST("Conversion 2 fails if user already has all types that resist the move")
{
    GIVEN {
        WITH_CONFIG(CONFIG_UPDATED_CONVERSION_2, GEN_5);
        ASSUME(GetMoveType(MOVE_DRAGON_PULSE) == TYPE_DRAGON);
        ASSUME(GetSpeciesType(SPECIES_MAWILE, 0) == TYPE_STEEL);
        ASSUME(GetSpeciesType(SPECIES_MAWILE, 1) == TYPE_FAIRY);
        PLAYER(SPECIES_MAWILE);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_DRAGON_PULSE); MOVE(player, MOVE_CONVERSION_2); }
    } SCENE {
        MESSAGE("The opposing Wobbuffet used Dragon Pulse!");
        MESSAGE("Mawile used Conversion 2!");
        MESSAGE("But it failed!");
    }
}

SINGLE_BATTLE_TEST("Conversion 2 fails if the target is semi-invulnerable")
{
    u32 move;

    PARAMETRIZE { move = MOVE_FLY; }
    PARAMETRIZE { move = MOVE_DIG; }
    PARAMETRIZE { move = MOVE_DIVE; }
    PARAMETRIZE { move = MOVE_PHANTOM_FORCE; }

    GIVEN {
        WITH_CONFIG(CONFIG_UPDATED_CONVERSION_2, GEN_5);
        ASSUME(GetMoveEffect(move) == EFFECT_SEMI_INVULNERABLE);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, move); MOVE(player, MOVE_CONVERSION_2); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, move, opponent);
        MESSAGE("Wobbuffet used Conversion 2!");
        MESSAGE("But it failed!");
    }
}

SINGLE_BATTLE_TEST("Conversion 2 fails if no move has hit the user yet (Gen 1-4)")
{
    GIVEN {
        WITH_CONFIG(CONFIG_UPDATED_CONVERSION_2, GEN_4);
        ASSUME(GetMoveType(MOVE_POLTERGEIST) == TYPE_GHOST);
        PLAYER(SPECIES_WOBBUFFET) { Item(ITEM_CHILAN_BERRY); } ;
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_CONVERSION_2); }
    } SCENE {
        MESSAGE("Wobbuffet used Conversion 2!");
        MESSAGE("But it failed!");
    }
}

SINGLE_BATTLE_TEST("Conversion 2 fails if target has not used a move yet (Gen 5+)")
{
    GIVEN {
        WITH_CONFIG(CONFIG_UPDATED_CONVERSION_2, GEN_5);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_CONVERSION_2); }
    } SCENE {
        MESSAGE("Wobbuffet used Conversion 2!");
        MESSAGE("But it failed!");
    }
}

SINGLE_BATTLE_TEST("Conversion 2 fails if the move missed the user (Gen 1-4)")
{
    GIVEN {
        WITH_CONFIG(CONFIG_UPDATED_CONVERSION_2, GEN_4);
        ASSUME(GetMoveType(MOVE_POLTERGEIST) == TYPE_GHOST);
        PLAYER(SPECIES_WOBBUFFET) { Item(ITEM_CHILAN_BERRY); } ;
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_POLTERGEIST, hit: FALSE); MOVE(player, MOVE_CONVERSION_2); }
    } SCENE {
        MESSAGE("The opposing Wobbuffet used Poltergeist!");
        MESSAGE("The opposing Wobbuffet's attack missed!");
        MESSAGE("Wobbuffet used Conversion 2!");
        MESSAGE("But it failed!");
    }
}

SINGLE_BATTLE_TEST("Conversion 2 works even if the move missed (Gen 5+)")
{
    GIVEN {
        WITH_CONFIG(CONFIG_UPDATED_CONVERSION_2, GEN_5);
        ASSUME(GetMoveType(MOVE_POLTERGEIST) == TYPE_GHOST);
        PLAYER(SPECIES_WOBBUFFET) { Item(ITEM_CHILAN_BERRY); } ;
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_POLTERGEIST, hit: FALSE); MOVE(player, MOVE_CONVERSION_2); }
    } SCENE {
        MESSAGE("The opposing Wobbuffet used Poltergeist!");
        MESSAGE("The opposing Wobbuffet's attack missed!");
        MESSAGE("Wobbuffet used Conversion 2!");
        ONE_OF {
            MESSAGE("Wobbuffet transformed into the Normal type!");
            MESSAGE("Wobbuffet transformed into the Dark type!");
        }
    }
}

SINGLE_BATTLE_TEST("Conversion 2 considers Ion Deluge changing Normal moves to Electric")
{
    GIVEN {
        WITH_CONFIG(CONFIG_UPDATED_CONVERSION_2, GEN_5);
        ASSUME(GetMoveType(MOVE_TACKLE) == TYPE_NORMAL);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_ION_DELUGE); MOVE(opponent, MOVE_TACKLE); }
        TURN { MOVE(player, MOVE_CONVERSION_2); }
    } SCENE {
        MESSAGE("Wobbuffet used Ion Deluge!");
        MESSAGE("The opposing Wobbuffet used Tackle!");
        ONE_OF {
            MESSAGE("Wobbuffet transformed into the Electric type!");
            MESSAGE("Wobbuffet transformed into the Grass type!");
            MESSAGE("Wobbuffet transformed into the Dragon type!");
            MESSAGE("Wobbuffet transformed into the Ground type!");
        }
    }
}

SINGLE_BATTLE_TEST("Conversion 2 considers Pixilate changing Normal moves to Fairy")
{
    GIVEN {
        WITH_CONFIG(CONFIG_UPDATED_CONVERSION_2, GEN_5);
        ASSUME(GetMoveType(MOVE_TACKLE) == TYPE_NORMAL);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_SYLVEON) { Ability(ABILITY_PIXILATE); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_TACKLE); MOVE(player, MOVE_CONVERSION_2); }
    } SCENE {
        MESSAGE("The opposing Sylveon used Tackle!");
        ONE_OF {
            MESSAGE("Wobbuffet transformed into the Fire type!");
            MESSAGE("Wobbuffet transformed into the Poison type!");
            MESSAGE("Wobbuffet transformed into the Steel type!");
        }
    }
}

SINGLE_BATTLE_TEST("Conversion 2 considers Refrigerate changing Normal moves to Ice")
{
    GIVEN {
        WITH_CONFIG(CONFIG_UPDATED_CONVERSION_2, GEN_5);
        ASSUME(GetMoveType(MOVE_TACKLE) == TYPE_NORMAL);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_AURORUS) { Ability(ABILITY_REFRIGERATE); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_TACKLE); MOVE(player, MOVE_CONVERSION_2); }
    } SCENE {
        MESSAGE("The opposing Aurorus used Tackle!");
        ONE_OF {
            MESSAGE("Wobbuffet transformed into the Fire type!");
            MESSAGE("Wobbuffet transformed into the Water type!");
            MESSAGE("Wobbuffet transformed into the Ice type!");
            MESSAGE("Wobbuffet transformed into the Steel type!");
        }
    }
}

SINGLE_BATTLE_TEST("Conversion 2 considers Aerilate changing Normal moves to Flying")
{
    GIVEN {
        WITH_CONFIG(CONFIG_UPDATED_CONVERSION_2, GEN_5);
        ASSUME(GetMoveType(MOVE_TACKLE) == TYPE_NORMAL);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_SALAMENCE) { Ability(ABILITY_AERILATE); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_TACKLE); MOVE(player, MOVE_CONVERSION_2); }
    } SCENE {
        MESSAGE("The opposing Salamence used Tackle!");
        ONE_OF {
            MESSAGE("Wobbuffet transformed into the Electric type!");
            MESSAGE("Wobbuffet transformed into the Rock type!");
            MESSAGE("Wobbuffet transformed into the Steel type!");
        }
    }
}

SINGLE_BATTLE_TEST("Conversion 2 considers Galvanize changing Normal moves to Electric")
{
    GIVEN {
        WITH_CONFIG(CONFIG_UPDATED_CONVERSION_2, GEN_5);
        ASSUME(GetMoveType(MOVE_TACKLE) == TYPE_NORMAL);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_GOLEM_ALOLA) { Ability(ABILITY_GALVANIZE); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_TACKLE); MOVE(player, MOVE_CONVERSION_2); }
    } SCENE {
        MESSAGE("The opposing Golem used Tackle!");
        ONE_OF {
            MESSAGE("Wobbuffet transformed into the Electric type!");
            MESSAGE("Wobbuffet transformed into the Grass type!");
            MESSAGE("Wobbuffet transformed into the Dragon type!");
            MESSAGE("Wobbuffet transformed into the Ground type!");
        }
    }
}

DOUBLE_BATTLE_TEST("Conversion 2 targets the correct opponent in a double battle (Gen 5+)")
{
    GIVEN {
        WITH_CONFIG(CONFIG_UPDATED_CONVERSION_2, GEN_5);
        ASSUME(GetMoveType(MOVE_SHADOW_BALL) == TYPE_GHOST);
        ASSUME(GetMoveType(MOVE_MYSTICAL_FIRE) == TYPE_FIRE);
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_ALAKAZAM);
        OPPONENT(SPECIES_GARDEVOIR);
    } WHEN {
        TURN { MOVE(opponentLeft, MOVE_SHADOW_BALL, target: playerLeft); MOVE(opponentRight, MOVE_MYSTICAL_FIRE, target: playerRight); }
        TURN { MOVE(playerLeft, MOVE_CONVERSION_2, target: opponentRight); }
    } SCENE {
        MESSAGE("The opposing Alakazam used Shadow Ball!");
        MESSAGE("The opposing Gardevoir used Mystical Fire!");
        MESSAGE("Wobbuffet used Conversion 2!");
        ONE_OF {
            MESSAGE("Wobbuffet transformed into the Fire type!");
            MESSAGE("Wobbuffet transformed into the Water type!");
            MESSAGE("Wobbuffet transformed into the Rock type!");
            MESSAGE("Wobbuffet transformed into the Dragon type!");
        }
    }
}

DOUBLE_BATTLE_TEST("Conversion 2 considers the last move used by the targeted opponent (Gen 5+)")
{
    GIVEN {
        WITH_CONFIG(CONFIG_UPDATED_CONVERSION_2, GEN_5);
        ASSUME(GetMoveType(MOVE_SHADOW_BALL) == TYPE_GHOST);
        ASSUME(GetMoveType(MOVE_MYSTICAL_FIRE) == TYPE_FIRE);
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_ALAKAZAM);
        OPPONENT(SPECIES_GARDEVOIR);
    } WHEN {
        TURN { MOVE(opponentLeft, MOVE_SHADOW_BALL, target: playerLeft); MOVE(opponentRight, MOVE_MYSTICAL_FIRE, target: playerLeft); }
        TURN { MOVE(playerLeft, MOVE_CONVERSION_2, target: opponentLeft); }
    } SCENE {
        MESSAGE("The opposing Alakazam used Shadow Ball!");
        MESSAGE("The opposing Gardevoir used Mystical Fire!");
        MESSAGE("Wobbuffet used Conversion 2!");
        ONE_OF {
            MESSAGE("Wobbuffet transformed into the Normal type!");
            MESSAGE("Wobbuffet transformed into the Dark type!");
        }
    }
}
