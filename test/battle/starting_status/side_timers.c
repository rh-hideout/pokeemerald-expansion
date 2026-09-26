#include "global.h"
#include "event_data.h"
#include "test/battle.h"

DOUBLE_BATTLE_TEST("Starting Status Tailwind names Tailwind as the trigger in the Wind Power activation message")
{
    u16 status = 0;

    PARAMETRIZE { status = STARTING_STATUS_TAILWIND_OPPONENT;           }
    PARAMETRIZE { status = STARTING_STATUS_TAILWIND_OPPONENT_TEMPORARY; }
    PARAMETRIZE { status = STARTING_STATUS_TAILWIND_PLAYER;             }
    PARAMETRIZE { status = STARTING_STATUS_TAILWIND_PLAYER_TEMPORARY;   }

    SetStartingStatus(status);

    GIVEN {
        PLAYER(SPECIES_WATTREL) { Ability(ABILITY_WIND_POWER); }
        PLAYER(SPECIES_KILOWATTREL) { Ability(ABILITY_WIND_POWER); }
        OPPONENT(SPECIES_WATTREL) { Ability(ABILITY_WIND_POWER); }
        OPPONENT(SPECIES_KILOWATTREL) { Ability(ABILITY_WIND_POWER); }
    } WHEN {
        TURN {}
    } SCENE {
        switch (status)
        {
        case STARTING_STATUS_TAILWIND_OPPONENT:
        case STARTING_STATUS_TAILWIND_OPPONENT_TEMPORARY:
            MESSAGE("A tailwind started blowing on the opposing side!");
            NONE_OF {
                ABILITY_POPUP(playerLeft, ABILITY_WIND_POWER);
                MESSAGE("Being hit by Tailwind charged Wattrel with power!");
                ABILITY_POPUP(playerRight, ABILITY_WIND_POWER);
                MESSAGE("Being hit by Tailwind charged Kilowattrel with power!");
            }
            ABILITY_POPUP(opponentLeft, ABILITY_WIND_POWER);
            MESSAGE("Being hit by Tailwind charged the opposing Wattrel with power!");
            NONE_OF {
                ABILITY_POPUP(playerLeft, ABILITY_WIND_POWER);
                MESSAGE("Being hit by Tailwind charged Wattrel with power!");
                ABILITY_POPUP(playerRight, ABILITY_WIND_POWER);
                MESSAGE("Being hit by Tailwind charged Kilowattrel with power!");
            }
            ABILITY_POPUP(opponentRight, ABILITY_WIND_POWER);
            MESSAGE("Being hit by Tailwind charged the opposing Kilowattrel with power!");
            NONE_OF {
                ABILITY_POPUP(playerLeft, ABILITY_WIND_POWER);
                MESSAGE("Being hit by Tailwind charged Wattrel with power!");
                ABILITY_POPUP(playerRight, ABILITY_WIND_POWER);
                MESSAGE("Being hit by Tailwind charged Kilowattrel with power!");
            }
            break;
        case STARTING_STATUS_TAILWIND_PLAYER:
        case STARTING_STATUS_TAILWIND_PLAYER_TEMPORARY:
            MESSAGE("A tailwind started blowing on your side!");
            NONE_OF {
                ABILITY_POPUP(opponentLeft, ABILITY_WIND_POWER);
                MESSAGE("Being hit by Tailwind charged the opposing Wattrel with power!");
                ABILITY_POPUP(opponentRight, ABILITY_WIND_POWER);
                MESSAGE("Being hit by Tailwind charged the opposing Kilowattrel with power!");
            }
            ABILITY_POPUP(playerLeft, ABILITY_WIND_POWER);
            MESSAGE("Being hit by Tailwind charged Wattrel with power!");
            NONE_OF {
                ABILITY_POPUP(opponentLeft, ABILITY_WIND_POWER);
                MESSAGE("Being hit by Tailwind charged the opposing Wattrel with power!");
                ABILITY_POPUP(opponentRight, ABILITY_WIND_POWER);
                MESSAGE("Being hit by Tailwind charged the opposing Kilowattrel with power!");
            }
            ABILITY_POPUP(playerRight, ABILITY_WIND_POWER);
            MESSAGE("Being hit by Tailwind charged Kilowattrel with power!");
            NONE_OF {
                ABILITY_POPUP(opponentLeft, ABILITY_WIND_POWER);
                MESSAGE("Being hit by Tailwind charged the opposing Wattrel with power!");
                ABILITY_POPUP(opponentRight, ABILITY_WIND_POWER);
                MESSAGE("Being hit by Tailwind charged the opposing Kilowattrel with power!");
            }
            break;
        default:
            break;
        }
    } THEN {
        ResetStartingStatuses();
    }
}

DOUBLE_BATTLE_TEST("Starting Status Tailwind only triggers Wind Rider once per battler")
{
    u16 status = 0;

    PARAMETRIZE { status = STARTING_STATUS_TAILWIND_OPPONENT;           }
    PARAMETRIZE { status = STARTING_STATUS_TAILWIND_OPPONENT_TEMPORARY; }
    PARAMETRIZE { status = STARTING_STATUS_TAILWIND_PLAYER;             }
    PARAMETRIZE { status = STARTING_STATUS_TAILWIND_PLAYER_TEMPORARY;   }

    SetStartingStatus(status);

    GIVEN {
        PLAYER(SPECIES_BRAMBLIN) { Ability(ABILITY_WIND_RIDER); }
        PLAYER(SPECIES_BRAMBLEGHAST) { Ability(ABILITY_WIND_RIDER); }
        OPPONENT(SPECIES_BRAMBLIN) { Ability(ABILITY_WIND_RIDER); }
        OPPONENT(SPECIES_BRAMBLEGHAST) { Ability(ABILITY_WIND_RIDER); }
    } WHEN {
        TURN {}
    } SCENE {
        switch (status)
        {
        case STARTING_STATUS_TAILWIND_OPPONENT:
        case STARTING_STATUS_TAILWIND_OPPONENT_TEMPORARY:
            MESSAGE("A tailwind started blowing on the opposing side!");
            NONE_OF {
                ABILITY_POPUP(playerLeft, ABILITY_WIND_RIDER);
                MESSAGE("Bramblin's Attack rose!");
                ABILITY_POPUP(playerRight, ABILITY_WIND_RIDER);
                MESSAGE("Brambleghast's Attack rose!");
            }
            ABILITY_POPUP(opponentLeft, ABILITY_WIND_RIDER);
            MESSAGE("The opposing Bramblin's Attack rose!");
            NONE_OF {
                ABILITY_POPUP(playerLeft, ABILITY_WIND_RIDER);
                MESSAGE("Bramblin's Attack rose!");
                ABILITY_POPUP(playerRight, ABILITY_WIND_RIDER);
                MESSAGE("Brambleghast's Attack rose!");
                ABILITY_POPUP(opponentLeft, ABILITY_WIND_RIDER);
                MESSAGE("The opposing Bramblin's Attack rose!");
            }
            ABILITY_POPUP(opponentRight, ABILITY_WIND_RIDER);
            MESSAGE("The opposing Brambleghast's Attack rose!");
            NONE_OF {
                ABILITY_POPUP(playerLeft, ABILITY_WIND_RIDER);
                MESSAGE("Bramblin's Attack rose!");
                ABILITY_POPUP(playerRight, ABILITY_WIND_RIDER);
                MESSAGE("Brambleghast's Attack rose!");
                ABILITY_POPUP(opponentLeft, ABILITY_WIND_RIDER);
                MESSAGE("The opposing Bramblin's Attack rose!");
                ABILITY_POPUP(opponentRight, ABILITY_WIND_RIDER);
                MESSAGE("The opposing Brambleghast's Attack rose!");
            }
            break;
        case STARTING_STATUS_TAILWIND_PLAYER:
        case STARTING_STATUS_TAILWIND_PLAYER_TEMPORARY:
            MESSAGE("A tailwind started blowing on your side!");
            NONE_OF {
                ABILITY_POPUP(opponentLeft, ABILITY_WIND_RIDER);
                MESSAGE("The opposing Bramblin's Attack rose!");
                ABILITY_POPUP(opponentRight, ABILITY_WIND_RIDER);
                MESSAGE("The opposing Brambleghast's Attack rose!");
            }
            ABILITY_POPUP(playerLeft, ABILITY_WIND_RIDER);
            MESSAGE("Bramblin's Attack rose!");
            NONE_OF {
                ABILITY_POPUP(opponentLeft, ABILITY_WIND_RIDER);
                MESSAGE("The opposing Bramblin's Attack rose!");
                ABILITY_POPUP(opponentRight, ABILITY_WIND_RIDER);
                MESSAGE("The opposing Brambleghast's Attack rose!");
                ABILITY_POPUP(playerLeft, ABILITY_WIND_RIDER);
                MESSAGE("Bramblin's Attack rose!");
            }
            ABILITY_POPUP(playerRight, ABILITY_WIND_RIDER);
            MESSAGE("Brambleghast's Attack rose!");
            NONE_OF {
                ABILITY_POPUP(opponentLeft, ABILITY_WIND_RIDER);
                MESSAGE("The opposing Bramblin's Attack rose!");
                ABILITY_POPUP(opponentRight, ABILITY_WIND_RIDER);
                MESSAGE("The opposing Brambleghast's Attack rose!");
                ABILITY_POPUP(playerLeft, ABILITY_WIND_RIDER);
                MESSAGE("Bramblin's Attack rose!");
                ABILITY_POPUP(playerRight, ABILITY_WIND_RIDER);
                MESSAGE("Brambleghast's Attack rose!");
            }
            break;
        default:
            break;
        }
    } THEN {
        ResetStartingStatuses();
    }
}
