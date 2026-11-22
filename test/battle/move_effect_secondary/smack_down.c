#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(GetMoveEffect(MOVE_SMACK_DOWN) == EFFECT_SMACK_DOWN);
}

SINGLE_BATTLE_TEST("Smack Down doesn't affect pokemon behind Substitute")
{
    GIVEN {
        ASSUME(IsSpeciesOfType(SPECIES_PIDGEY, TYPE_FLYING));
        ASSUME(GetMoveType(MOVE_EARTHQUAKE) == TYPE_GROUND);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_PIDGEY);
    } WHEN {
        TURN { MOVE(opponent, MOVE_SUBSTITUTE); MOVE(player, MOVE_SMACK_DOWN); }
        TURN { MOVE(player, MOVE_EARTHQUAKE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SUBSTITUTE, opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SMACK_DOWN, player);
        NONE_OF {
            MESSAGE("The opposing Pidgey fell straight down!");
            ANIMATION(ANIM_TYPE_MOVE, MOVE_EARTHQUAKE, player);
            HP_BAR(opponent);
        }
    }
}

SINGLE_BATTLE_TEST("Thousand Arrows does not ground mons behind substitutes")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_THOUSAND_ARROWS) == EFFECT_SMACK_DOWN);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_SKARMORY);
    } WHEN {
        TURN { MOVE(opponent, MOVE_SUBSTITUTE); MOVE(player, MOVE_THOUSAND_ARROWS); }
    } SCENE {
        NOT MESSAGE("The opposing Skarmory fell straight down!");
    }
}

SINGLE_BATTLE_TEST("Smack Down does not ground mons through Protect")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_SKARMORY);
    } WHEN {
        TURN { MOVE(opponent, MOVE_PROTECT); MOVE(player, MOVE_SMACK_DOWN); }
    } SCENE {
        NOT MESSAGE("The opposing Skarmory fell straight down!");
    }
}

SINGLE_BATTLE_TEST("Smack Down does not ground target if target is immune")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_ELECTRIFY) == EFFECT_ELECTRIFY);
        ASSUME(GetSpeciesType(SPECIES_GLISCOR, 0) == TYPE_GROUND || GetSpeciesType(SPECIES_GLISCOR, 1) == TYPE_GROUND);
        ASSUME(GetSpeciesType(SPECIES_GLISCOR, 0) == TYPE_FLYING || GetSpeciesType(SPECIES_GLISCOR, 1) == TYPE_FLYING);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_GLISCOR);
    } WHEN {
        TURN { MOVE(opponent, MOVE_ELECTRIFY); MOVE(player, MOVE_SMACK_DOWN); }
    } SCENE {
        NOT MESSAGE("The opposing Gliscor fell straight down!");
    }
}

SINGLE_BATTLE_TEST("Smack Down grounds flying type pokemon")
{
    GIVEN {
        ASSUME(IsSpeciesOfType(SPECIES_PIDGEY, TYPE_FLYING));
        ASSUME(GetMoveType(MOVE_EARTHQUAKE) == TYPE_GROUND);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_PIDGEY);
    } WHEN {
        TURN { MOVE(player, MOVE_SMACK_DOWN); }
        TURN { MOVE(player, MOVE_EARTHQUAKE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SMACK_DOWN, player);
        MESSAGE("The opposing Pidgey fell straight down!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_EARTHQUAKE, player);
        HP_BAR(opponent);
    }
}

SINGLE_BATTLE_TEST("Smack Down grounds pokemon with Levitate")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_FLYGON) { Ability(ABILITY_LEVITATE); };
    } WHEN {
        TURN { MOVE(player, MOVE_SMACK_DOWN); }
        TURN { MOVE(player, MOVE_EARTHQUAKE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SMACK_DOWN, player);
        MESSAGE("The opposing Flygon fell straight down!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_EARTHQUAKE, player);
        HP_BAR(opponent);
    }
}

SINGLE_BATTLE_TEST("Smack Down hits airborne pokemon and grounds them")
{
    GIVEN {
        ASSUME(IsSpeciesOfType(SPECIES_PIDGEY, TYPE_FLYING));
        ASSUME(GetMoveEffect(MOVE_FLY) == EFFECT_SEMI_INVULNERABLE);
        ASSUME(GetTwoTurnMoveSemiInvulnerability(MOVE_FLY) == STATE_ON_AIR);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_PIDGEY);
    } WHEN {
        TURN { MOVE(opponent, MOVE_FLY); MOVE(player, MOVE_SMACK_DOWN); }
        TURN { MOVE(player, MOVE_EARTHQUAKE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_FLY, opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SMACK_DOWN, player);
        HP_BAR(opponent);
        MESSAGE("The opposing Pidgey fell straight down!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_EARTHQUAKE, player);
        HP_BAR(opponent);
    }
}

DOUBLE_BATTLE_TEST("Smack Down does not bring down pokemon that are involved in a Sky Drop")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN {
            MOVE(playerLeft, MOVE_SKY_DROP, target: opponentLeft);
            MOVE(playerRight, MOVE_SMACK_DOWN, target: opponentLeft);
        }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SKY_DROP, playerLeft);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SMACK_DOWN, playerRight);
        NOT MESSAGE("The opposing Wobbuffet fell straight down!");
    }
}

SINGLE_BATTLE_TEST("Smack Down hitting into an underground pokemon with No Guard does not remove the invulnerable state")
{
    GIVEN {
        PLAYER(SPECIES_MACHAMP) { Ability(ABILITY_NO_GUARD); }
        OPPONENT(SPECIES_FLYGON) { Ability(ABILITY_LEVITATE); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_DIG); MOVE(player, MOVE_SMACK_DOWN); }
        TURN { SKIP_TURN(opponent); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_DIG, opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SMACK_DOWN, player);
        HP_BAR(opponent);
        MESSAGE("The opposing Flygon fell straight down!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_DIG, opponent);
        HP_BAR(player);
    }
}

DOUBLE_BATTLE_TEST("Thousand Arrows will ground both targets")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_THOUSAND_ARROWS) == EFFECT_SMACK_DOWN);
        ASSUME(IsSpeciesOfType(SPECIES_PIDGEY, TYPE_FLYING));
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_PIDGEY);
        OPPONENT(SPECIES_FLYGON) { Ability(ABILITY_LEVITATE); }
    } WHEN {
        TURN {
            MOVE(opponentRight, MOVE_CELEBRATE);
            MOVE(opponentLeft, MOVE_CELEBRATE);
            MOVE(playerLeft, MOVE_THOUSAND_ARROWS);
        }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_THOUSAND_ARROWS, playerLeft);
        MESSAGE("The opposing Pidgey fell straight down!");
        MESSAGE("The opposing Flygon fell straight down!");
    }
}

SINGLE_BATTLE_TEST("Smack Down move animation works when used 15 times in a row")
{
    u16 j, nTurns = 15;
    FORCE_MOVE_ANIM(TRUE);

    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        for (j = 0; j < nTurns; j++)
        {
            TURN { MOVE(player, MOVE_SMACK_DOWN); MOVE(opponent, MOVE_HELPING_HAND); } // Helping Hand, so there's no anim on the opponent's side.
        }
    } SCENE {
        for (j = 0; j < nTurns; j++)
        {
            ANIMATION(ANIM_TYPE_MOVE, MOVE_SMACK_DOWN, player);
        }
    } THEN {
        FORCE_MOVE_ANIM(FALSE);
    }
}
