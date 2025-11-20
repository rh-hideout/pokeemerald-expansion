#include "global.h"
#include "event_data.h"
#include "test/battle.h"

#if B_VAR_STARTING_STATUS != 0

SINGLE_BATTLE_TEST("B_VAR_STARTING_STATUS can start Spikes on the opposing side", s16 damage)
{
    u16 startingStatus;
    u32 divisor;

    PARAMETRIZE { startingStatus = STARTING_STATUS_SPIKES_OPPONENT_L1; divisor = 8; }
    PARAMETRIZE { startingStatus = STARTING_STATUS_SPIKES_OPPONENT_L3; divisor = 4; }

    VarSet(B_VAR_STARTING_STATUS, startingStatus);
    VarSet(B_VAR_STARTING_STATUS_TIMER, 0);

    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WYNAUT);
    } WHEN {
        TURN { SWITCH(opponent, 1); }
    } SCENE {
        MESSAGE("2 sent out Wynaut!");
        s32 maxHP = GetMonData(&OPPONENT_PARTY[1], MON_DATA_MAX_HP);
        HP_BAR(opponent, damage: maxHP / divisor);
        MESSAGE("The opposing Wynaut was hurt by the spikes!");
    } FINALLY {
        VarSet(B_VAR_STARTING_STATUS, 0);
    }
}

SINGLE_BATTLE_TEST("Starting Toxic Spikes poison the opposing switch-in")
{
    VarSet(B_VAR_STARTING_STATUS, STARTING_STATUS_TOXIC_SPIKES_OPPONENT_L1);
    VarSet(B_VAR_STARTING_STATUS_TIMER, 0);

    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WYNAUT);
    } WHEN {
        TURN { SWITCH(opponent, 1); }
    } SCENE {
        MESSAGE("2 sent out Wynaut!");
        MESSAGE("The opposing Wynaut was poisoned!");
        STATUS_ICON(opponent, poison: TRUE);
        NOT STATUS_ICON(opponent, badPoison: TRUE);
    } THEN {
        VarSet(B_VAR_STARTING_STATUS, 0);
    }
}

SINGLE_BATTLE_TEST("Starting Toxic Spikes badly poison the opposing switch-in")
{
    VarSet(B_VAR_STARTING_STATUS, STARTING_STATUS_TOXIC_SPIKES_OPPONENT_L2);
    VarSet(B_VAR_STARTING_STATUS_TIMER, 0);

    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WYNAUT);
    } WHEN {
        TURN { SWITCH(opponent, 1); }
    } SCENE {
        MESSAGE("2 sent out Wynaut!");
        MESSAGE("The opposing Wynaut was badly poisoned!");
        STATUS_ICON(opponent, badPoison: TRUE);
    } THEN {
        VarSet(B_VAR_STARTING_STATUS, 0);
    }
}

SINGLE_BATTLE_TEST("Starting Sticky Web lowers Speed on entry")
{
    VarSet(B_VAR_STARTING_STATUS, STARTING_STATUS_STICKY_WEB_OPPONENT);
    VarSet(B_VAR_STARTING_STATUS_TIMER, 0);

    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_RATICATE);
        OPPONENT(SPECIES_WYNAUT);
    } WHEN {
        TURN { SWITCH(opponent, 1); }
    } SCENE {
        MESSAGE("2 sent out Wynaut!");
        MESSAGE("The opposing Wynaut was caught in a sticky web!");
        MESSAGE("The opposing Wynaut's Speed fell!");
    } THEN {
        VarSet(B_VAR_STARTING_STATUS, 0);
    }
}

SINGLE_BATTLE_TEST("Starting Stealth Rock damages the opposing switch-in")
{
    VarSet(B_VAR_STARTING_STATUS, STARTING_STATUS_STEALTH_ROCK_OPPONENT);
    VarSet(B_VAR_STARTING_STATUS_TIMER, 0);

    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_CHARIZARD);
    } WHEN {
        TURN { SWITCH(opponent, 1); }
    } SCENE {
        MESSAGE("2 sent out Charizard!");
        s32 maxHP = GetMonData(&OPPONENT_PARTY[1], MON_DATA_MAX_HP);
        HP_BAR(opponent, damage: maxHP / 2);
        MESSAGE("Pointed stones dug into the opposing Charizard!");
    } THEN {
        VarSet(B_VAR_STARTING_STATUS, 0);
    }
}

SINGLE_BATTLE_TEST("Starting sharp steel damages the opposing switch-in")
{
    VarSet(B_VAR_STARTING_STATUS, STARTING_STATUS_SHARP_STEEL_OPPONENT);
    VarSet(B_VAR_STARTING_STATUS_TIMER, 0);

    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_SYLVEON);
    } WHEN {
        TURN { SWITCH(opponent, 1); }
    } SCENE {
        MESSAGE("2 sent out Sylveon!");
        s32 maxHP = GetMonData(&OPPONENT_PARTY[1], MON_DATA_MAX_HP);
        HP_BAR(opponent, damage: maxHP / 4);
        MESSAGE("The sharp steel bit into the opposing Sylveon!");
    } THEN {
        VarSet(B_VAR_STARTING_STATUS, 0);
    }
}

#endif // B_VAR_STARTING_STATUS
