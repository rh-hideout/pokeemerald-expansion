#include "global.h"
#include "test/battle.h"

DOUBLE_BATTLE_TEST("Stalwart ignores redirection from Follow-Me")
{
    GIVEN {
        PLAYER(SPECIES_ARCHALUDON) { Ability(ABILITY_STALWART); }
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponentLeft, MOVE_FOLLOW_ME); MOVE(playerLeft, MOVE_DRACO_METEOR, target: opponentRight); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_FOLLOW_ME, opponentLeft);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_DRACO_METEOR, playerLeft);
        HP_BAR(opponentRight);
        NOT HP_BAR(opponentLeft);
    }
}

DOUBLE_BATTLE_TEST("Stalwart stops Lightning Rod and Storm Drain from redirecting moves")
{
    enum Ability ability;
    enum Species species;
    u32 config;
    PARAMETRIZE { ability = ABILITY_STORM_DRAIN; species = SPECIES_LUMINEON; config = GEN_4; }
    PARAMETRIZE { ability = ABILITY_STORM_DRAIN; species = SPECIES_LUMINEON; config = GEN_5; }
    PARAMETRIZE { ability = ABILITY_LIGHTNING_ROD; species = SPECIES_RAICHU; config = GEN_4; }
    PARAMETRIZE { ability = ABILITY_LIGHTNING_ROD; species = SPECIES_RAICHU; config = GEN_5; }
    GIVEN {
        WITH_CONFIG(B_REDIRECT_ABILITY_IMMUNITY, config);
        ASSUME(GetMoveType(MOVE_SPARK) == TYPE_ELECTRIC);
        ASSUME(GetMoveType(MOVE_WATER_GUN) == TYPE_WATER);
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_STALWART); }
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(species) { Ability(ability); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN {
            if (ability == ABILITY_LIGHTNING_ROD)
                MOVE(playerLeft, MOVE_SPARK, target: opponentRight);
            else
                MOVE(playerLeft, MOVE_WATER_GUN, target: opponentRight);
        }
    } SCENE {
        HP_BAR(opponentRight);
        if (config >= GEN_5) {
            NONE_OF {
                ABILITY_POPUP(opponentLeft, ability);
                ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponentLeft);
                MESSAGE("The opposing Raichu's Sp. Atk rose!");
            }
        } else {
            NONE_OF {
                HP_BAR(opponentLeft);
            }
        }
    }
}

SINGLE_BATTLE_TEST("Stalwart bypasses the opponent's Substitute (post-Champs 1.3.0)")
{
    u32 config;

    PARAMETRIZE { config = GEN_9; }
    PARAMETRIZE { config = GEN_CHAMPIONS; }

    GIVEN {
        WITH_CONFIG(B_STALWART_SUBSTITUTE, config);
        ASSUME(GetMoveEffect(MOVE_SUBSTITUTE) == EFFECT_SUBSTITUTE);
        ASSUME(!MoveIgnoresSubstitute(MOVE_SCRATCH));
        PLAYER(SPECIES_ARCHALUDON) { Ability(ABILITY_STALWART); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_SUBSTITUTE); MOVE(player, MOVE_SCRATCH); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SUBSTITUTE, opponent);
        if (config == GEN_CHAMPIONS) {
            NOT SUB_HIT(opponent);
        } else {
            SUB_HIT(opponent);
        }
    }
}
