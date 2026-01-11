#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Disable prevents the target from using a random move (Gen 1)")
{
    PASSES_RANDOMLY(1, 3, RNG_DISABLE_MOVE);
    GIVEN {
        WITH_CONFIG(CONFIG_DISABLE_TURNS, GEN_1);
        PLAYER(SPECIES_WOBBUFFET) { Speed(2); }
        OPPONENT(SPECIES_WYNAUT) { Speed(1); Moves(MOVE_FLAMETHROWER, MOVE_THUNDERBOLT, MOVE_ICE_BEAM); }
    } WHEN {
        TURN { MOVE(player, MOVE_DISABLE); MOVE(opponent, MOVE_THUNDERBOLT); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_DISABLE, player);
        NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_THUNDERBOLT, opponent);
    }
}

SINGLE_BATTLE_TEST("Disable prevents the target from using the last move used (Gen 2+)")
{
    GIVEN {
        WITH_CONFIG(CONFIG_DISABLE_TURNS, GEN_2);
        PLAYER(SPECIES_WOBBUFFET) { Speed(2); }
        OPPONENT(SPECIES_WYNAUT) { Speed(1); Moves(MOVE_SCRATCH, MOVE_CELEBRATE); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_SCRATCH); }
        TURN { MOVE(player, MOVE_DISABLE); MOVE(opponent, MOVE_SCRATCH); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_DISABLE, player);
        MESSAGE("The opposing Wynaut's Scratch was disabled!");
        MESSAGE("The opposing Wynaut's Scratch is disabled!");
        NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, opponent);
    }
}

SINGLE_BATTLE_TEST("Disable fails if one of the target's moves is already disabled")
{
    u32 config = GEN_LATEST;

    PARAMETRIZE { config = GEN_1; }
    PARAMETRIZE { config = GEN_2; }

    GIVEN {
        WITH_CONFIG(CONFIG_DISABLE_TURNS, config);
        PLAYER(SPECIES_WOBBUFFET) { Speed(1); }
        OPPONENT(SPECIES_WYNAUT) { Speed(2); Moves(MOVE_CELEBRATE, MOVE_SCRATCH); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_SCRATCH); MOVE(player, MOVE_DISABLE); }
        TURN { MOVE(player, MOVE_DISABLE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_DISABLE, player);
        MESSAGE("The opposing Wynaut's Scratch was disabled!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, opponent);
        NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_DISABLE, player);
        MESSAGE("But it failed!");
    }
}

SINGLE_BATTLE_TEST("Disable fails if the target haven't used a move yet (Gen 2+)")
{
    GIVEN {
        WITH_CONFIG(CONFIG_DISABLE_TURNS, GEN_2);
        PLAYER(SPECIES_WOBBUFFET) { Speed(2); }
        OPPONENT(SPECIES_WYNAUT) { Speed(1); Moves(MOVE_CELEBRATE, MOVE_SCRATCH); }
    } WHEN {
        TURN { MOVE(player, MOVE_DISABLE); MOVE(opponent, MOVE_SCRATCH); }
        TURN { MOVE(player, MOVE_DISABLE); MOVE(opponent, MOVE_SCRATCH); }
    } SCENE {
        NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_DISABLE, player);
        MESSAGE("But it failed!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_DISABLE, player);
        MESSAGE("The opposing Wynaut's Scratch was disabled!");
        MESSAGE("The opposing Wynaut's Scratch is disabled!");
    }
}

SINGLE_BATTLE_TEST("Disable fails if the last move used was Struggle (Gen 2+)")
{
    GIVEN {
        WITH_CONFIG(CONFIG_DISABLE_TURNS, GEN_2);
        PLAYER(SPECIES_WOBBUFFET) { Speed(1); }
        OPPONENT(SPECIES_WYNAUT) { Speed(2); MovesWithPP({MOVE_SCRATCH, 1}, {MOVE_CELEBRATE, 40}); Item(ITEM_CHOICE_BAND); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_SCRATCH); MOVE(player, MOVE_CELEBRATE); }
        TURN { FORCED_MOVE(opponent); MOVE(player, MOVE_DISABLE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_STRUGGLE, opponent);
        NONE_OF {
            ANIMATION(ANIM_TYPE_MOVE, MOVE_DISABLE, player);
            MESSAGE("The opposing Wynaut's Scratch was disabled!");
        }
        MESSAGE("But it failed!");
    }
}

SINGLE_BATTLE_TEST("Disable fails if the last move used was a Max Move")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Speed(1); }
        OPPONENT(SPECIES_WYNAUT) { Speed(2); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_CELEBRATE, gimmick: GIMMICK_DYNAMAX); MOVE(player, MOVE_DISABLE); }
        TURN { MOVE(opponent, MOVE_SLEEP_TALK); MOVE(player, MOVE_SPORE); }
        TURN { MOVE(opponent, MOVE_SLEEP_TALK); }
    } SCENE {
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_DYNAMAX_GROWTH, opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_MAX_GUARD, opponent);
        MESSAGE("Wobbuffet used Disable!");
        NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_DISABLE, player);
        MESSAGE("But it failed!");
    }
}

SINGLE_BATTLE_TEST("Disabled moves can still be used via Sleep Talk")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Speed(1); }
        OPPONENT(SPECIES_WYNAUT) { Speed(2); Moves(MOVE_SLEEP_TALK, MOVE_SCRATCH); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_SCRATCH); MOVE(player, MOVE_DISABLE); }
        TURN { MOVE(opponent, MOVE_SLEEP_TALK); MOVE(player, MOVE_SPORE); }
        TURN { MOVE(opponent, MOVE_SLEEP_TALK); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_DISABLE, player);
        MESSAGE("The opposing Wynaut's Scratch was disabled!");
        NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_SLEEP_TALK, opponent);
        MESSAGE("But it failed!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SPORE, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SLEEP_TALK, opponent);
        NOT MESSAGE("The opposing Wynaut's Scratch is disabled!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, opponent);
    }
}

SINGLE_BATTLE_TEST("Disabled moves can still be used via Metronome")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Speed(1); }
        OPPONENT(SPECIES_WYNAUT) { Speed(2); Moves(MOVE_METRONOME, MOVE_SCRATCH); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_SCRATCH); MOVE(player, MOVE_DISABLE); }
        TURN { MOVE(opponent, MOVE_METRONOME, WITH_RNG(RNG_METRONOME, MOVE_SCRATCH)); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_DISABLE, player);
        MESSAGE("The opposing Wynaut used Metronome!");
        NOT MESSAGE("But it failed!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_METRONOME, opponent);
        MESSAGE("Waggling a finger let it use Scratch!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, opponent);
    }
}

SINGLE_BATTLE_TEST("Disabled moves can still be used via Mirror Move")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Speed(1); }
        OPPONENT(SPECIES_WYNAUT) { Speed(2); Moves(MOVE_DISABLE, MOVE_MIRROR_MOVE); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_DISABLE); MOVE(player, MOVE_DISABLE); }
        TURN { MOVE(opponent, MOVE_MIRROR_MOVE); MOVE(player, MOVE_DISABLE); }
    } SCENE {
        MESSAGE("The opposing Wynaut used Disable!");
        NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_DISABLE, opponent);
        MESSAGE("But it failed!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_DISABLE, player);
        MESSAGE("The opposing Wynaut's Disable was disabled!");
        MESSAGE("The opposing Wynaut used Mirror Move!");
        NOT MESSAGE("But it failed!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_MIRROR_MOVE, opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_DISABLE, opponent);
        MESSAGE("Wobbuffet's Disable was disabled!");
        NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_DISABLE, player);
        MESSAGE("Wobbuffet's Disable is disabled!");
    }
}

SINGLE_BATTLE_TEST("Disable lasts 0-7 turns (Gen 1)")
{
    PASSES_RANDOMLY(1, 8, RNG_DISABLE_TURNS);
    GIVEN {
        WITH_CONFIG(CONFIG_DISABLE_TURNS, GEN_1);
        PLAYER(SPECIES_WOBBUFFET) { Speed(2); }
        OPPONENT(SPECIES_WYNAUT) { Speed(1); Moves(MOVE_SCRATCH, MOVE_CELEBRATE); }
    } WHEN {
        TURN { MOVE(player, MOVE_DISABLE, WITH_RNG(RNG_DISABLE_MOVE, 0)); MOVE(opponent, MOVE_SCRATCH); }
        TURN {}
        TURN {}
        TURN {}
        TURN {}
        TURN {}
        TURN {}
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_DISABLE, player);
        MESSAGE("The opposing Wynaut's Scratch was disabled!");
        MESSAGE("The opposing Wynaut's Scratch is disabled!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, player);
        MESSAGE("The opposing Wynaut's move is no longer disabled!");
    }
}

SINGLE_BATTLE_TEST("Disable has a 1 in 8 chance for the target to still use its move (Gen 1)")
{
    PASSES_RANDOMLY(1, 8, RNG_DISABLE_TURNS);
    GIVEN {
        WITH_CONFIG(CONFIG_DISABLE_TURNS, GEN_1);
        PLAYER(SPECIES_WOBBUFFET) { Speed(2); }
        OPPONENT(SPECIES_WYNAUT) { Speed(1); Moves(MOVE_SCRATCH, MOVE_CELEBRATE); }
    } WHEN {
        TURN { MOVE(player, MOVE_DISABLE, WITH_RNG(RNG_DISABLE_MOVE, 0)); MOVE(opponent, MOVE_SCRATCH); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_DISABLE, player);
        MESSAGE("The opposing Wynaut's Scratch was disabled!");
        NOT MESSAGE("The opposing Wynaut's Scratch is disabled!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, opponent);
    }
}

SINGLE_BATTLE_TEST("Disable lasts 1-7 turns (Gen 2)")
{
    PASSES_RANDOMLY(1, 7, RNG_DISABLE_TURNS);
    GIVEN {
        WITH_CONFIG(CONFIG_DISABLE_TURNS, GEN_2);
        PLAYER(SPECIES_WOBBUFFET) { Speed(2); }
        OPPONENT(SPECIES_WYNAUT) { Speed(1); Moves(MOVE_SCRATCH, MOVE_CELEBRATE); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_SCRATCH); }
        TURN { MOVE(player, MOVE_DISABLE); MOVE(opponent, MOVE_SCRATCH); }
        TURN {}
        TURN {}
        TURN {}
        TURN {}
        TURN {}
        TURN {}
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_DISABLE, player);
        MESSAGE("The opposing Wynaut's Scratch was disabled!");
        NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, opponent); // 0 turns
        MESSAGE("The opposing Wynaut's Scratch is disabled!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, player);
        MESSAGE("The opposing Wynaut's move is no longer disabled!"); // 7 turns
    }
}

SINGLE_BATTLE_TEST("Disable lasts 2-5 turns (Gen 3)")
{
    PASSES_RANDOMLY(1, 4, RNG_DISABLE_TURNS);
    GIVEN {
        WITH_CONFIG(CONFIG_DISABLE_TURNS, GEN_3);
        PLAYER(SPECIES_WOBBUFFET) { Speed(2); }
        OPPONENT(SPECIES_WYNAUT) { Speed(1); Moves(MOVE_SCRATCH, MOVE_CELEBRATE); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_SCRATCH); }
        TURN { MOVE(player, MOVE_DISABLE); MOVE(opponent, MOVE_SCRATCH); }
        TURN {}
        TURN {}
        TURN {}
        TURN {}
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_DISABLE, player);
        MESSAGE("The opposing Wynaut's Scratch was disabled!");
        NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, opponent); // 0 turns
        MESSAGE("The opposing Wynaut's Scratch is disabled!");
        NOT MESSAGE("The opposing Wynaut's move is no longer disabled!"); // 1 turn
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, player);
        MESSAGE("The opposing Wynaut's move is no longer disabled!"); // 5 turns
    }
}

SINGLE_BATTLE_TEST("Disable lasts 4-7 turns (Gen 4)")
{
    PASSES_RANDOMLY(1, 4, RNG_DISABLE_TURNS);
    GIVEN {
        WITH_CONFIG(CONFIG_DISABLE_TURNS, GEN_4);
        PLAYER(SPECIES_WOBBUFFET) { Speed(2); }
        OPPONENT(SPECIES_WYNAUT) { Speed(1); Moves(MOVE_SCRATCH, MOVE_CELEBRATE); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_SCRATCH); }
        TURN { MOVE(player, MOVE_DISABLE); MOVE(opponent, MOVE_SCRATCH); }
        TURN {}
        TURN {}
        TURN {}
        TURN {}
        TURN {}
        TURN {}
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_DISABLE, player);
        MESSAGE("The opposing Wynaut's Scratch was disabled!");
        NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, opponent); // 0 turns
        MESSAGE("The opposing Wynaut's Scratch is disabled!");
        NOT MESSAGE("The opposing Wynaut's move is no longer disabled!"); // 1 turn
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, player);
        NOT MESSAGE("The opposing Wynaut's move is no longer disabled!"); // 2 turns
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, player);
        NOT MESSAGE("The opposing Wynaut's move is no longer disabled!"); // 3 turns
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, player);
        MESSAGE("The opposing Wynaut's move is no longer disabled!");
    }
}

SINGLE_BATTLE_TEST("Disable lasts 4 turns (Gen 5+)")
{
    PASSES_RANDOMLY(10, 10, RNG_DISABLE_TURNS);
    GIVEN {
        WITH_CONFIG(CONFIG_DISABLE_TURNS, GEN_5);
        PLAYER(SPECIES_WOBBUFFET) { Speed(2); }
        OPPONENT(SPECIES_WYNAUT) { Speed(1); Moves(MOVE_SCRATCH, MOVE_CELEBRATE); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_SCRATCH); }
        TURN { MOVE(player, MOVE_DISABLE); MOVE(opponent, MOVE_SCRATCH); }
        TURN {}
        TURN {}
        TURN {}
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_DISABLE, player);
        MESSAGE("The opposing Wynaut's Scratch was disabled!");
        NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, opponent); // 0 turns
        MESSAGE("The opposing Wynaut's Scratch is disabled!");
        NOT MESSAGE("The opposing Wynaut's move is no longer disabled!"); // 1 turn
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, player);
        NOT MESSAGE("The opposing Wynaut's move is no longer disabled!"); // 2 turns
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, player);
        NOT MESSAGE("The opposing Wynaut's move is no longer disabled!"); // 3 turns
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, player);
        MESSAGE("The opposing Wynaut's move is no longer disabled!");
    }
}

SINGLE_BATTLE_TEST("Disable's timer only counts down when trying to use a move (Gen 1-2)")
{
    u32 config = GEN_LATEST, move = MOVE_NONE;

    PARAMETRIZE { config = GEN_1; move = MOVE_SCRATCH;      }
    PARAMETRIZE { config = GEN_1; move = MOVE_ROCK_SLIDE;   }
    PARAMETRIZE { config = GEN_1; move = MOVE_SING;         }
    PARAMETRIZE { config = GEN_1; move = MOVE_ICE_BEAM;     }
    PARAMETRIZE { config = GEN_1; move = MOVE_THUNDERBOLT;  }
    //PARAMETRIZE { config = GEN_1; move = MOVE_WRAP;         } // TO DO: uncomment once Gen 1 Wrap is added
    PARAMETRIZE { config = GEN_2; move = MOVE_SCRATCH;      }
    PARAMETRIZE { config = GEN_2; move = MOVE_ROCK_SLIDE;   }
    PARAMETRIZE { config = GEN_2; move = MOVE_SING;         }
    PARAMETRIZE { config = GEN_2; move = MOVE_ICE_BEAM;     }
    PARAMETRIZE { config = GEN_2; move = MOVE_THUNDERBOLT;  }

    GIVEN {
        WITH_CONFIG(CONFIG_DISABLE_TURNS, config);
        PLAYER(SPECIES_WOBBUFFET) { Speed(2); Moves(move, MOVE_DISABLE, MOVE_CELEBRATE); }
        OPPONENT(SPECIES_WYNAUT) { Speed(1); Moves(MOVE_CELEBRATE, MOVE_SCRATCH); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_SCRATCH); }
        TURN { MOVE(player, MOVE_DISABLE, WITH_RNG(RNG_DISABLE_TURNS, 2)); MOVE(opponent, MOVE_SCRATCH); }
        switch (move)
        {
        case MOVE_ICE_BEAM:
            TURN { MOVE(player, move); MOVE(opponent, MOVE_CELEBRATE, WITH_RNG(RNG_FROZEN, FALSE)); }
            break;
        case MOVE_THUNDERBOLT:
            TURN { MOVE(player, move); MOVE(opponent, MOVE_CELEBRATE, WITH_RNG(RNG_PARALYSIS, FALSE)); }
            break;
        default:
            TURN { MOVE(player, move); MOVE(opponent, MOVE_CELEBRATE); }
            break;
        }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_DISABLE, player);
        MESSAGE("The opposing Wynaut's Scratch was disabled!");
        NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, opponent); // 0 turns
        MESSAGE("The opposing Wynaut's Scratch is disabled!");
        NOT MESSAGE("The opposing Wynaut's move is no longer disabled!"); // 1 turn
        ANIMATION(ANIM_TYPE_MOVE, move, player);
        if (move != MOVE_SCRATCH)
            NOT MESSAGE("The opposing Wynaut's move is no longer disabled!"); // 2 turns
        else
            MESSAGE("The opposing Wynaut's move is no longer disabled!"); // 2 turns
    }
}

SINGLE_BATTLE_TEST("Disable's timer counts down regardless of the action (Gen 3+)")
{
    u32 move = MOVE_NONE;

    PARAMETRIZE { move = MOVE_SCRATCH;      }
    PARAMETRIZE { move = MOVE_ROCK_SLIDE;   }
    PARAMETRIZE { move = MOVE_SING;         }
    PARAMETRIZE { move = MOVE_ICE_BEAM;     }
    PARAMETRIZE { move = MOVE_THUNDERBOLT;  }

    GIVEN {
        WITH_CONFIG(CONFIG_DISABLE_TURNS, GEN_3);
        PLAYER(SPECIES_WOBBUFFET) { Speed(2); Moves(move, MOVE_DISABLE, MOVE_CELEBRATE); }
        OPPONENT(SPECIES_WYNAUT) { Speed(1); Moves(MOVE_CELEBRATE, MOVE_SCRATCH); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_SCRATCH); }
        TURN { MOVE(player, MOVE_DISABLE, WITH_RNG(RNG_DISABLE_TURNS, 2)); MOVE(opponent, MOVE_SCRATCH); }
        switch (move)
        {
        case MOVE_ICE_BEAM:
            TURN { MOVE(player, move); MOVE(opponent, MOVE_CELEBRATE, WITH_RNG(RNG_FROZEN, FALSE)); }
            break;
        case MOVE_THUNDERBOLT:
            TURN { MOVE(player, move); MOVE(opponent, MOVE_CELEBRATE, WITH_RNG(RNG_PARALYSIS, FALSE)); }
            break;
        default:
            TURN { MOVE(player, move); MOVE(opponent, MOVE_CELEBRATE); }
            break;
        }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_DISABLE, player);
        MESSAGE("The opposing Wynaut's Scratch was disabled!");
        NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, opponent); // 0 turns
        MESSAGE("The opposing Wynaut's Scratch is disabled!");
        NOT MESSAGE("The opposing Wynaut's move is no longer disabled!"); // 1 turn
        ANIMATION(ANIM_TYPE_MOVE, move, player);
        MESSAGE("The opposing Wynaut's move is no longer disabled!"); // 2 turns
    }
}

SINGLE_BATTLE_TEST("Baton Pass doesn't pass Disable's effect")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Speed(1); Moves(MOVE_DISABLE, MOVE_CELEBRATE); }
        OPPONENT(SPECIES_WYNAUT) { Speed(2); Moves(MOVE_SCRATCH, MOVE_BATON_PASS); }
        OPPONENT(SPECIES_WYNAUT) { Speed(2); Moves(MOVE_SCRATCH, MOVE_BATON_PASS); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_SCRATCH); MOVE(player, MOVE_DISABLE); }
        TURN { MOVE(opponent, MOVE_BATON_PASS, partyIndex:1); }
        TURN { MOVE(opponent, MOVE_SCRATCH); }
        TURN { MOVE(opponent, MOVE_SCRATCH); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_DISABLE, player);
        MESSAGE("The opposing Wynaut's Scratch was disabled!");
        MESSAGE("The opposing Wynaut used Baton Pass!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_BATON_PASS, opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, player);
        MESSAGE("The opposing Wynaut used Scratch!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, player);
        MESSAGE("The opposing Wynaut used Scratch!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, player);
        NOT MESSAGE("The opposing Wynaut's move is no longer disabled!"); // 4 turns
    }
}

TO_DO_BATTLE_TEST("Disable's effect persists when an affected move is taught over following a level up (Gen1)");
