#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Destiny Bond faints the opposing mon if it fainted from the attack")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { HP(1); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_DESTINY_BOND); MOVE(opponent, MOVE_TACKLE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_DESTINY_BOND, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_TACKLE, opponent);
        MESSAGE("Wobbuffet took its attacker down with it!");
        MESSAGE("The opposing Wobbuffet fainted!");
    }
}

TO_DO_BATTLE_TEST("Destiny Bond's effect disappears if the user takes a new turn - Move");
TO_DO_BATTLE_TEST("Destiny Bond's effect disappears if the user takes a new turn - Sleep");
TO_DO_BATTLE_TEST("Destiny Bond's effect disappears if the user takes a new turn - Paralysis");
TO_DO_BATTLE_TEST("Destiny Bond's effect disappears if the user takes a new turn - Flinching");
TO_DO_BATTLE_TEST("Destiny Bond's effect doesn't trigger on indirect damage - Sandstorm");
TO_DO_BATTLE_TEST("Destiny Bond's effect doesn't trigger on indirect damage - Leech Seed");
TO_DO_BATTLE_TEST("Destiny Bond's effect doesn't trigger on indirect damage - Future Sight");
TO_DO_BATTLE_TEST("Destiny Bond's effect bypasses Focus Sash");
TO_DO_BATTLE_TEST("Destiny Bond's effect bypasses Sturdy");
TO_DO_BATTLE_TEST("Destiny Bond's effect bypasses Magic Guard");
TO_DO_BATTLE_TEST("Destiny Bond's effect can trigger on the next turn if the user hasn't moved yet");
TO_DO_BATTLE_TEST("Destiny Bond can be used multiple times in a row (Gen 2-6)");
TO_DO_BATTLE_TEST("Destiny Bond always fails if it was successfully used the previous turn (Gen 7+)");
TO_DO_BATTLE_TEST("Destiny Bond cannot be used in Raids");

// can't be used at all in Raid, see "Documenting Dynamax"
SINGLE_BATTLE_TEST("(DYNAMAX) Dynamaxed Pokemon are not affected by Destiny Bond")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Speed(50); };
        OPPONENT(SPECIES_WOBBUFFET) { HP(1); Speed(100); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_DESTINY_BOND); MOVE(player, MOVE_TACKLE, gimmick: GIMMICK_DYNAMAX); }
    } SCENE {
        MESSAGE("The opposing Wobbuffet used Destiny Bond!");
        MESSAGE("Wobbuffet used Max Strike!");
        MESSAGE("The opposing Wobbuffet fainted!");
        NONE_OF { HP_BAR(player); }
    }
}
