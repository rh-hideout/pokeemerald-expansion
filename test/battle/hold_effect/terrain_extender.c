#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(GetItemHoldEffect(ITEM_TERRAIN_EXTENDER) == HOLD_EFFECT_TERRAIN_EXTENDER);
    ASSUME(GetMoveEffect(MOVE_ELECTRIC_TERRAIN) == EFFECT_ELECTRIC_TERRAIN);
    ASSUME(GetMoveEffect(MOVE_GRASSY_TERRAIN) == EFFECT_GRASSY_TERRAIN);
    ASSUME(GetMoveEffect(MOVE_MISTY_TERRAIN) == EFFECT_MISTY_TERRAIN);
    ASSUME(GetMoveEffect(MOVE_PSYCHIC_TERRAIN) == EFFECT_PSYCHIC_TERRAIN);
}

SINGLE_BATTLE_TEST("Terrain Extender makes terrain created by moves last 8 turns")
{
    enum Move move;

    PARAMETRIZE { move = MOVE_ELECTRIC_TERRAIN; }
    PARAMETRIZE { move = MOVE_GRASSY_TERRAIN; }
    PARAMETRIZE { move = MOVE_MISTY_TERRAIN; }
    PARAMETRIZE { move = MOVE_PSYCHIC_TERRAIN; }

    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Speed(100); Item(ITEM_TERRAIN_EXTENDER); Moves(move); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(50); }
    } WHEN {
        TURN { MOVE(player, move); MOVE(opponent, MOVE_CELEBRATE); }
        TURN {}
        TURN {}
        TURN {}
        TURN {}
        TURN {}
        TURN {}
        TURN {}
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, move, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, opponent);
        for (u32 turn = 0; turn < 7; turn++)
        {
            ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, player);
            ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, opponent);
        }
        switch (move)
        {
        case MOVE_ELECTRIC_TERRAIN:
            MESSAGE("The electricity disappeared from the battlefield.");
            break;
        case MOVE_GRASSY_TERRAIN:
            MESSAGE("The grass disappeared from the battlefield.");
            break;
        case MOVE_MISTY_TERRAIN:
            MESSAGE("The mist disappeared from the battlefield.");
            break;
        case MOVE_PSYCHIC_TERRAIN:
            MESSAGE("The weirdness disappeared from the battlefield!");
            break;
        default:
            break;
        }
    }
}

SINGLE_BATTLE_TEST("Terrain Extender makes terrain created by abilities last 8 turns")
{
    enum Ability ability;
    enum Species species;

    PARAMETRIZE { ability = ABILITY_ELECTRIC_SURGE; species = SPECIES_PINCURCHIN; }
    PARAMETRIZE { ability = ABILITY_GRASSY_SURGE;   species = SPECIES_RILLABOOM; }
    PARAMETRIZE { ability = ABILITY_MISTY_SURGE;    species = SPECIES_TAPU_FINI; }
    PARAMETRIZE { ability = ABILITY_PSYCHIC_SURGE;  species = SPECIES_TAPU_LELE; }

    GIVEN {
        PLAYER(species) { Speed(100); Ability(ability); Item(ITEM_TERRAIN_EXTENDER); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(50); }
    } WHEN {
        TURN {}
        TURN {}
        TURN {}
        TURN {}
        TURN {}
        TURN {}
        TURN {}
        TURN {}
    } SCENE {
        ABILITY_POPUP(player, ability);
        for (u32 turn = 0; turn < 8; turn++)
        {
            ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, player);
            ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, opponent);
        }
        switch (ability)
        {
        case ABILITY_ELECTRIC_SURGE:
            MESSAGE("The electricity disappeared from the battlefield.");
            break;
        case ABILITY_GRASSY_SURGE:
            MESSAGE("The grass disappeared from the battlefield.");
            break;
        case ABILITY_MISTY_SURGE:
            MESSAGE("The mist disappeared from the battlefield.");
            break;
        case ABILITY_PSYCHIC_SURGE:
            MESSAGE("The weirdness disappeared from the battlefield!");
            break;
        default:
            break;
        }
    }
}
