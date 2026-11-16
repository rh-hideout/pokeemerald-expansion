#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(MoveHasAdditionalEffect(MOVE_JAW_LOCK, MOVE_EFFECT_JAW_LOCK));
}

SINGLE_BATTLE_TEST("Jaw Lock traps both user and target")
{
    GIVEN {
        PLAYER(SPECIES_WYNAUT) { Ability(ABILITY_TELEPATHY); }
        OPPONENT(SPECIES_WOBBUFFET) { Ability(ABILITY_TELEPATHY); }
    } WHEN {
        TURN { MOVE(player, MOVE_JAW_LOCK); }
    } THEN {
        EXPECT(player->volatiles.jawLock & (1u << B_BATTLER_1));
    }
}

SINGLE_BATTLE_TEST("Jaw Lock traps both user and target until one leaves the field")
{
    GIVEN {
        PLAYER(SPECIES_WYNAUT) { Ability(ABILITY_TELEPATHY); }
        OPPONENT(SPECIES_WOBBUFFET) { Ability(ABILITY_TELEPATHY); }
        OPPONENT(SPECIES_WOBBUFFET) { Ability(ABILITY_TELEPATHY); }
    } WHEN {
        TURN { MOVE(player, MOVE_JAW_LOCK); }
        TURN { SWITCH(opponent, 1); }
    } THEN {
        EXPECT(player->volatiles.jawLock == 0);
    }
}

SINGLE_BATTLE_TEST("Jaw Lock fails to trap if user is already trapped")
{
    GIVEN {
        PLAYER(SPECIES_WYNAUT) { Ability(ABILITY_TELEPATHY); }
        OPPONENT(SPECIES_WOBBUFFET) { Ability(ABILITY_TELEPATHY); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_MEAN_LOOK); MOVE(player, MOVE_JAW_LOCK); }
    } THEN {
        EXPECT(player->volatiles.jawLock == 0);
    }
}

SINGLE_BATTLE_TEST("Jaw Lock fails to trap if target is already trapped")
{
    GIVEN {
        PLAYER(SPECIES_WYNAUT) { Ability(ABILITY_TELEPATHY); }
        OPPONENT(SPECIES_WOBBUFFET) { Ability(ABILITY_TELEPATHY); }
    } WHEN {
        TURN { MOVE(player, MOVE_MEAN_LOOK); }
        TURN { MOVE(player, MOVE_JAW_LOCK); }
    } THEN {
        EXPECT(player->volatiles.jawLock == 0);
    }
}
