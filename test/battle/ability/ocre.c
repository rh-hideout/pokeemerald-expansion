#include "global.h"
#include "test/battle.h"

// Osatopia : Ocre donne +1 en priorité pendant le premier tour où le Pokémon est sur le terrain.

SINGLE_BATTLE_TEST("Ocre grants priority on the first turn only")
{
    GIVEN {
        PLAYER(SPECIES_KRALAMOURE_GEANT) { Ability(ABILITY_OCRE); Speed(1); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(100); }
    } WHEN {
        TURN { MOVE(player, MOVE_TACKLE); }
        TURN { MOVE(player, MOVE_TACKLE); }
    } SCENE {
        MESSAGE("Kralagéant used Tackle!");
        MESSAGE("The opposing Wobbuffet used Celebrate!");
        MESSAGE("The opposing Wobbuffet used Celebrate!");
        MESSAGE("Kralagéant used Tackle!");
    }
}

SINGLE_BATTLE_TEST("Ocre grants priority again after switching in")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Speed(1); }
        PLAYER(SPECIES_KRALAMOURE_GEANT) { Ability(ABILITY_OCRE); Speed(1); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(100); }
    } WHEN {
        TURN { SWITCH(player, 1); }
        TURN { MOVE(player, MOVE_TACKLE); }
    } SCENE {
        MESSAGE("Kralagéant used Tackle!");
        MESSAGE("The opposing Wobbuffet used Celebrate!");
    }
}

SINGLE_BATTLE_TEST("Kracheau drains HP and lowers the target's Speed")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_KRACHEAU) == EFFECT_ABSORB);
        PLAYER(SPECIES_KRALAMOURE_GEANT) { HP(1); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_KRACHEAU); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_KRACHEAU, player);
        HP_BAR(opponent);
    } THEN {
        EXPECT_GT(player->hp, 1);
        EXPECT_EQ(opponent->statStages[STAT_SPEED], DEFAULT_STAT_STAGE - 1);
    }
}
