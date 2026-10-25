#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Truant alternates between acting and loafing")
{
    GIVEN {
        PLAYER(SPECIES_SLAKING) { Ability(ABILITY_TRUANT); Speed(2); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(1); }
    } WHEN {
        TURN { MOVE(player, MOVE_SCRATCH); }
        TURN { MOVE(player, MOVE_TACKLE); }
        TURN { MOVE(player, MOVE_POUND); }
        TURN { MOVE(player, MOVE_EMBER); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, player);
        NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_TACKLE, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_POUND, player);
        NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_EMBER, player);
    }
}

SINGLE_BATTLE_TEST("Truant advances while asleep in Gen 3-4 but only after an action attempt in Gen 5+")
{
    u32 gen;
    PARAMETRIZE { gen = GEN_4; }
    PARAMETRIZE { gen = GEN_5; }

    GIVEN {
        WITH_CONFIG(B_TRUANT, gen);
        PLAYER(SPECIES_SLAKING) { Ability(ABILITY_TRUANT); Status1(STATUS1_SLEEP_TURN(3)); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_SNORE); }
        TURN { MOVE(player, MOVE_SCRATCH); }
        TURN { MOVE(player, MOVE_TACKLE); }
        TURN { MOVE(player, MOVE_POUND); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SNORE, player);
        if (gen == GEN_4) {
            NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, player);
            ANIMATION(ANIM_TYPE_MOVE, MOVE_TACKLE, player);
            NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_POUND, player);
        } else {
            NONE_OF {
                ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, player);
                ANIMATION(ANIM_TYPE_MOVE, MOVE_TACKLE, player);
            }
            ANIMATION(ANIM_TYPE_MOVE, MOVE_POUND, player);
        }
    }
}

SINGLE_BATTLE_TEST("Truant advances while frozen in Gen 3-4 but not in Gen 5+")
{
    u32 gen;
    PARAMETRIZE { gen = GEN_4; }
    PARAMETRIZE { gen = GEN_5; }

    GIVEN {
        WITH_CONFIG(B_TRUANT, gen);
        PLAYER(SPECIES_SLAKING) { Ability(ABILITY_TRUANT); Status1(STATUS1_FREEZE); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_SCRATCH, WITH_RNG(RNG_FROZEN, FALSE)); }
        TURN { MOVE(player, MOVE_TACKLE, WITH_RNG(RNG_FROZEN, TRUE)); }
        TURN { MOVE(player, MOVE_POUND); }
    } SCENE {
        if (gen == GEN_4) {
            NONE_OF {
                ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, player);
                ANIMATION(ANIM_TYPE_MOVE, MOVE_TACKLE, player);
            }
            ANIMATION(ANIM_TYPE_MOVE, MOVE_POUND, player);
        } else {
            NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, player);
            ANIMATION(ANIM_TYPE_MOVE, MOVE_TACKLE, player);
            NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_POUND, player);
        }
    }
}

SINGLE_BATTLE_TEST("A thawing move does not thaw its user on a Truant loafing turn")
{
    GIVEN {
        WITH_CONFIG(B_TRUANT, GEN_5);
        ASSUME(MoveThawsUser(MOVE_FLAME_WHEEL));
        PLAYER(SPECIES_SLAKING) { Ability(ABILITY_TRUANT); Speed(2); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(1); }
    } WHEN {
        TURN { MOVE(player, MOVE_SCRATCH); MOVE(opponent, MOVE_ICE_BEAM, WITH_RNG(RNG_SECONDARY_EFFECT, TRUE)); }
        TURN { MOVE(player, MOVE_FLAME_WHEEL); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_ICE_BEAM, opponent);
        STATUS_ICON(player, freeze: TRUE);
        NONE_OF {
            STATUS_ICON(player, none: TRUE);
            ANIMATION(ANIM_TYPE_MOVE, MOVE_FLAME_WHEEL, player);
        }
    } THEN {
        EXPECT(player->status1 & STATUS1_FREEZE);
    }
}

SINGLE_BATTLE_TEST("Truant is checked before paralysis and confusion, and either failure advances it")
{
    enum Move statusMove;
    PARAMETRIZE { statusMove = MOVE_THUNDER_WAVE; }
    PARAMETRIZE { statusMove = MOVE_CONFUSE_RAY; }

    GIVEN {
        WITH_CONFIG(B_TRUANT, GEN_5);
        ASSUME(GetMoveEffect(MOVE_THUNDER_WAVE) == EFFECT_NON_VOLATILE_STATUS);
        ASSUME(GetMoveNonVolatileStatus(MOVE_THUNDER_WAVE) == MOVE_EFFECT_PARALYSIS);
        ASSUME(GetMoveEffect(MOVE_CONFUSE_RAY) == EFFECT_CONFUSE);
        PLAYER(SPECIES_SLAKING) { Ability(ABILITY_TRUANT); Speed(2); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(1); }
    } WHEN {
        TURN { MOVE(player, MOVE_SCRATCH); MOVE(opponent, statusMove); }
        TURN { MOVE(player, MOVE_TACKLE); }
        if (statusMove == MOVE_CONFUSE_RAY)
            TURN { MOVE(player, MOVE_POUND, WITH_RNG(RNG_CONFUSION, TRUE)); }
        else
            TURN { MOVE(player, MOVE_POUND, WITH_RNG(RNG_PARALYSIS, TRUE)); }
        TURN { MOVE(player, MOVE_TACKLE); }
        if (statusMove == MOVE_CONFUSE_RAY)
            TURN { MOVE(player, MOVE_EMBER, WITH_RNG(RNG_CONFUSION, FALSE)); }
        else
            TURN { MOVE(player, MOVE_EMBER, WITH_RNG(RNG_PARALYSIS, FALSE)); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, player);
        ANIMATION(ANIM_TYPE_MOVE, statusMove, opponent);
        if (statusMove == MOVE_THUNDER_WAVE)
            STATUS_ICON(player, paralysis: TRUE);
        if (statusMove == MOVE_CONFUSE_RAY) {
            NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_TACKLE, player);
            HP_BAR(player);
            NONE_OF {
                ANIMATION(ANIM_TYPE_MOVE, MOVE_POUND, player);
                ANIMATION(ANIM_TYPE_MOVE, MOVE_TACKLE, player);
            }
        } else {
            NONE_OF {
                ANIMATION(ANIM_TYPE_MOVE, MOVE_TACKLE, player);
                ANIMATION(ANIM_TYPE_MOVE, MOVE_POUND, player);
            }
        }
        ANIMATION(ANIM_TYPE_MOVE, MOVE_EMBER, player);
    }
}

SINGLE_BATTLE_TEST("Flinching advances Truant")
{
    GIVEN {
        WITH_CONFIG(B_TRUANT, GEN_5);
        PLAYER(SPECIES_SLAKING) { Ability(ABILITY_TRUANT); Speed(1); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(2); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_FAKE_OUT); MOVE(player, MOVE_SCRATCH); }
        TURN { MOVE(player, MOVE_TACKLE); }
        TURN { MOVE(player, MOVE_POUND); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_FAKE_OUT, opponent);
        NONE_OF {
            ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, player);
            ANIMATION(ANIM_TYPE_MOVE, MOVE_TACKLE, player);
        }
        ANIMATION(ANIM_TYPE_MOVE, MOVE_POUND, player);
    }
}

SINGLE_BATTLE_TEST("A recharge turn advances Truant")
{
    GIVEN {
        WITH_CONFIG(B_TRUANT, GEN_5);
        PLAYER(SPECIES_SLAKING) { Ability(ABILITY_TRUANT); }
        OPPONENT(SPECIES_WOBBUFFET) { HP(1000); MaxHP(1000); }
    } WHEN {
        TURN { MOVE(player, MOVE_GIGA_IMPACT); }
        TURN { SKIP_TURN(player); }
        TURN { MOVE(player, MOVE_SCRATCH); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_GIGA_IMPACT, player);
        MESSAGE("Slaking must recharge!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, player);
    }
}

SINGLE_BATTLE_TEST("A two-turn move is canceled when its attack turn is a Truant loafing turn")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_SOLAR_BEAM) == EFFECT_SOLAR_BEAM);
        PLAYER(SPECIES_SLAKING) { Ability(ABILITY_TRUANT); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_SOLAR_BEAM); }
        TURN { SKIP_TURN(player); }
    } SCENE {
        MESSAGE("Slaking absorbed light!");
        MESSAGE("Slaking is loafing around!");
        NONE_OF {
            ANIMATION(ANIM_TYPE_MOVE, MOVE_SOLAR_BEAM, player);
            HP_BAR(opponent);
        }
    }
}

SINGLE_BATTLE_TEST("Power Herb lets a Truant user complete a two-turn move before loafing")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_SOLAR_BEAM) == EFFECT_SOLAR_BEAM);
        ASSUME(GetItemHoldEffect(ITEM_POWER_HERB) == HOLD_EFFECT_POWER_HERB);
        PLAYER(SPECIES_SLAKING) { Ability(ABILITY_TRUANT); Item(ITEM_POWER_HERB); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_SOLAR_BEAM); }
        TURN { MOVE(player, MOVE_TACKLE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SOLAR_BEAM, player);
        HP_BAR(opponent);
        NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_TACKLE, player);
    } THEN {
        EXPECT_EQ(player->item, ITEM_NONE);
    }
}

SINGLE_BATTLE_TEST("Focus-style setup is skipped on a Gen 3-4 loafing turn and occurs in Gen 5+")
{
    u32 gen, move, setupAnim;
    PARAMETRIZE { gen = GEN_4; move = MOVE_FOCUS_PUNCH; setupAnim = B_ANIM_FOCUS_PUNCH_SETUP; }
    PARAMETRIZE { gen = GEN_5; move = MOVE_FOCUS_PUNCH; setupAnim = B_ANIM_FOCUS_PUNCH_SETUP; }
    PARAMETRIZE { gen = GEN_4; move = MOVE_BEAK_BLAST;  setupAnim = B_ANIM_BEAK_BLAST_SETUP; }
    PARAMETRIZE { gen = GEN_5; move = MOVE_BEAK_BLAST;  setupAnim = B_ANIM_BEAK_BLAST_SETUP; }
    PARAMETRIZE { gen = GEN_4; move = MOVE_SHELL_TRAP;  setupAnim = B_ANIM_SHELL_TRAP_SETUP; }
    PARAMETRIZE { gen = GEN_5; move = MOVE_SHELL_TRAP;  setupAnim = B_ANIM_SHELL_TRAP_SETUP; }

    GIVEN {
        WITH_CONFIG(B_TRUANT, gen);
        ASSUME(GetMoveEffect(MOVE_BEAK_BLAST) == EFFECT_BEAK_BLAST);
        ASSUME(GetMoveEffect(MOVE_FOCUS_PUNCH) == EFFECT_FOCUS_PUNCH);
        ASSUME(GetMoveEffect(MOVE_SHELL_TRAP) == EFFECT_SHELL_TRAP);
        PLAYER(SPECIES_SLAKING) { Ability(ABILITY_TRUANT); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_CELEBRATE); }
        TURN { MOVE(player, move); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, player);
        if (gen == GEN_5) {
            ANIMATION(ANIM_TYPE_GENERAL, setupAnim, player);
        } else {
            NOT ANIMATION(ANIM_TYPE_GENERAL, setupAnim, player);
        }
        MESSAGE("Slaking is loafing around!");
        NOT ANIMATION(ANIM_TYPE_MOVE, move, player);
    }
}

SINGLE_BATTLE_TEST("Focus-style setup occurs before sleep prevents the move")
{
    u32 move, setupAnim;
    PARAMETRIZE { move = MOVE_FOCUS_PUNCH; setupAnim = B_ANIM_FOCUS_PUNCH_SETUP; }
    PARAMETRIZE { move = MOVE_BEAK_BLAST;  setupAnim = B_ANIM_BEAK_BLAST_SETUP; }
    PARAMETRIZE { move = MOVE_SHELL_TRAP;  setupAnim = B_ANIM_SHELL_TRAP_SETUP; }

    GIVEN {
        ASSUME(GetMoveEffect(MOVE_BEAK_BLAST) == EFFECT_BEAK_BLAST);
        ASSUME(GetMoveEffect(MOVE_FOCUS_PUNCH) == EFFECT_FOCUS_PUNCH);
        ASSUME(GetMoveEffect(MOVE_SHELL_TRAP) == EFFECT_SHELL_TRAP);
        PLAYER(SPECIES_SLAKING) { Ability(ABILITY_TRUANT); Status1(STATUS1_SLEEP_TURN(3)); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, move); }
    } SCENE {
        ANIMATION(ANIM_TYPE_GENERAL, setupAnim, player);
        MESSAGE("Slaking is fast asleep.");
        NOT ANIMATION(ANIM_TYPE_MOVE, move, player);
    }
}

SINGLE_BATTLE_TEST("Stomping Tantrum and Temper Flare deal double damage after a Truant loafing turn")
{
    enum Move move;
    s16 damage[2];
    PARAMETRIZE { move = MOVE_STOMPING_TANTRUM; }
    PARAMETRIZE { move = MOVE_TEMPER_FLARE; }

    GIVEN {
        ASSUME(GetMoveEffect(MOVE_STOMPING_TANTRUM) == EFFECT_STOMPING_TANTRUM);
        ASSUME(GetMoveEffect(MOVE_TEMPER_FLARE) == EFFECT_STOMPING_TANTRUM);
        PLAYER(SPECIES_SLAKING) { Ability(ABILITY_TRUANT); }
        OPPONENT(SPECIES_WOBBUFFET) { HP(1000); MaxHP(1000); }
    } WHEN {
        TURN { MOVE(player, move); }
        TURN { MOVE(player, MOVE_CELEBRATE); }
        TURN { MOVE(player, move); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, move, player);
        HP_BAR(opponent, captureDamage: &damage[0]);
        MESSAGE("Slaking is loafing around!");
        ANIMATION(ANIM_TYPE_MOVE, move, player);
        HP_BAR(opponent, captureDamage: &damage[1]);
    } THEN {
        EXPECT_MUL_EQ(damage[0], Q_4_12(2.0), damage[1]);
    }
}

DOUBLE_BATTLE_TEST("Instruct spends a pending Truant loaf and advances it to an acting turn")
{
    GIVEN {
        WITH_CONFIG(B_TRUANT, GEN_5);
        ASSUME(GetMoveEffect(MOVE_INSTRUCT) == EFFECT_INSTRUCT);
        PLAYER(SPECIES_SLAKING) { Ability(ABILITY_TRUANT); Speed(3); }
        PLAYER(SPECIES_ORANGURU) { Speed(2); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(1); }
        OPPONENT(SPECIES_WYNAUT) { Speed(1); }
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_SCRATCH, target: opponentLeft); MOVE(playerRight, MOVE_INSTRUCT, target: playerLeft); }
        TURN { MOVE(playerLeft, MOVE_TACKLE, target: opponentLeft); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, playerLeft);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_INSTRUCT, playerRight);
        NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, playerLeft);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_TACKLE, playerLeft);
    }
}

SINGLE_BATTLE_TEST("A battle item advances Truant in Gen 3-4 but not in Gen 5+")
{
    u32 gen;
    PARAMETRIZE { gen = GEN_4; }
    PARAMETRIZE { gen = GEN_5; }

    GIVEN {
        WITH_CONFIG(B_TRUANT, gen);
        PLAYER(SPECIES_SLAKING) { Ability(ABILITY_TRUANT); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { USE_ITEM(player, ITEM_X_ATTACK); }
        TURN { MOVE(player, MOVE_SCRATCH); }
    } SCENE {
        if (gen == GEN_4) {
            MESSAGE("Slaking is loafing around!");
            NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, player);
        } else {
            ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, player);
        }
    }
}

SINGLE_BATTLE_TEST("A native Truant user switched in during a turn acts on its first turn")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_SLAKING) { Ability(ABILITY_TRUANT); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_BATON_PASS); SEND_OUT(player, 1); }
        TURN { MOVE(player, MOVE_SCRATCH); }
        TURN { MOVE(player, MOVE_TACKLE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_BATON_PASS, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, player);
        NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_TACKLE, player);
    }
}

SINGLE_BATTLE_TEST("A native Truant user replacing an end-turn faint loafs first only in Gen 3")
{
    u32 gen;
    PARAMETRIZE { gen = GEN_3; }
    PARAMETRIZE { gen = GEN_4; }
    PARAMETRIZE { gen = GEN_5; }

    GIVEN {
        WITH_CONFIG(B_TRUANT, gen);
        PLAYER(SPECIES_WOBBUFFET) { HP(1); Status1(STATUS1_POISON); }
        PLAYER(SPECIES_SLAKING) { Ability(ABILITY_TRUANT); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { SEND_OUT(player, 1); }
        TURN { MOVE(player, MOVE_SCRATCH); }
    } SCENE {
        MESSAGE("Wobbuffet fainted!");
        if (gen == GEN_3) {
            MESSAGE("Slaking is loafing around!");
            NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, player);
        } else {
            ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, player);
        }
    }
}

SINGLE_BATTLE_TEST("Tracing Truant after a move switch loafs first only in Gen 3")
{
    u32 gen;
    PARAMETRIZE { gen = GEN_3; }
    PARAMETRIZE { gen = GEN_4; }
    PARAMETRIZE { gen = GEN_5; }

    GIVEN {
        WITH_CONFIG(B_TRUANT, gen);
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_PORYGON) { Ability(ABILITY_TRACE); }
        OPPONENT(SPECIES_SLAKING) { Ability(ABILITY_TRUANT); }
    } WHEN {
        TURN { MOVE(player, MOVE_BATON_PASS); SEND_OUT(player, 1); }
        TURN { MOVE(player, MOVE_SCRATCH); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_BATON_PASS, player);
        ABILITY_POPUP(player, ABILITY_TRACE);
        if (gen == GEN_3) {
            MESSAGE("Porygon is loafing around!");
            NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, player);
        } else {
            ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, player);
        }
    }
}

SINGLE_BATTLE_TEST("Tracing Truant after an end-turn faint acts first")
{
    u32 gen;
    PARAMETRIZE { gen = GEN_3; }
    PARAMETRIZE { gen = GEN_4; }

    GIVEN {
        WITH_CONFIG(B_TRUANT, gen);
        PLAYER(SPECIES_WOBBUFFET) { HP(1); Status1(STATUS1_POISON); }
        PLAYER(SPECIES_PORYGON) { Ability(ABILITY_TRACE); }
        OPPONENT(SPECIES_SLAKING) { Ability(ABILITY_TRUANT); }
    } WHEN {
        TURN { SEND_OUT(player, 1); }
        TURN { MOVE(player, MOVE_SCRATCH); }
    } SCENE {
        MESSAGE("Wobbuffet fainted!");
        ABILITY_POPUP(player, ABILITY_TRACE);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, player);
    }
}

SINGLE_BATTLE_TEST("Losing Truant preserves its counter in Gen 3 and resets it in Gen 4+")
{
    u32 gen;
    PARAMETRIZE { gen = GEN_3; }
    PARAMETRIZE { gen = GEN_4; }

    GIVEN {
        WITH_CONFIG(B_TRUANT, gen);
        ASSUME(GetMoveEffect(MOVE_SKILL_SWAP) == EFFECT_SKILL_SWAP);
        PLAYER(SPECIES_SLAKING) { Ability(ABILITY_TRUANT); Speed(1); }
        OPPONENT(SPECIES_WOBBUFFET) { Ability(ABILITY_SHADOW_TAG); Speed(2); }
    } WHEN {
        TURN { MOVE(player, MOVE_SCRATCH); }
        TURN { MOVE(opponent, MOVE_SKILL_SWAP); MOVE(player, MOVE_SCRATCH); }
        TURN { MOVE(player, MOVE_SKILL_SWAP); }
        TURN { MOVE(player, MOVE_SCRATCH); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SKILL_SWAP, opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, player);
        MESSAGE("The opposing Wobbuffet is loafing around!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SKILL_SWAP, player);
        if (gen == GEN_3) {
            ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, player);
        } else {
            MESSAGE("Slaking is loafing around!");
            NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, player);
        }
    }
}

SINGLE_BATTLE_TEST("Gaining Truant makes the next action loaf regardless of move order")
{
    bool32 playerMovedFirst;
    PARAMETRIZE { playerMovedFirst = FALSE; }
    PARAMETRIZE { playerMovedFirst = TRUE; }

    GIVEN {
        WITH_CONFIG(B_TRUANT, GEN_5);
        ASSUME(GetMoveEffect(MOVE_SKILL_SWAP) == EFFECT_SKILL_SWAP);
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_SHADOW_TAG); Speed(playerMovedFirst ? 2 : 1); }
        OPPONENT(SPECIES_SLAKING) { Ability(ABILITY_TRUANT); Speed(playerMovedFirst ? 1 : 2); }
    } WHEN {
        TURN { MOVE(player, MOVE_SCRATCH); MOVE(opponent, MOVE_SKILL_SWAP); }
        TURN { MOVE(player, MOVE_TACKLE); }
        TURN { MOVE(player, MOVE_POUND); }
    } SCENE {
        if (playerMovedFirst)
            ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SKILL_SWAP, opponent);
        if (!playerMovedFirst)
            ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, player);
        NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_TACKLE, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_POUND, player);
    }
}

DOUBLE_BATTLE_TEST("Neutralizing Gas ending before or after Truant acts makes its next turn loaf")
{
    bool32 gasEndsBeforeTruantActs;
    PARAMETRIZE { gasEndsBeforeTruantActs = TRUE; }
    PARAMETRIZE { gasEndsBeforeTruantActs = FALSE; }

    GIVEN {
        WITH_CONFIG(B_TRUANT, GEN_5);
        PLAYER(SPECIES_WOBBUFFET) { Speed(gasEndsBeforeTruantActs ? 4 : 3); }
        PLAYER(SPECIES_SLAKING) { Ability(ABILITY_TRUANT); Speed(gasEndsBeforeTruantActs ? 3 : 4); }
        OPPONENT(SPECIES_KOFFING) { Ability(ABILITY_NEUTRALIZING_GAS); HP(1); Speed(2); }
        OPPONENT(SPECIES_WYNAUT) { HP(1000); MaxHP(1000); Speed(1); }
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_SCRATCH, target: opponentLeft); MOVE(playerRight, MOVE_SCRATCH, target: opponentRight); }
        TURN { MOVE(playerRight, MOVE_TACKLE, target: opponentRight); }
        TURN { MOVE(playerRight, MOVE_POUND, target: opponentRight); }
    } SCENE {
        ABILITY_POPUP(opponentLeft, ABILITY_NEUTRALIZING_GAS);
        if (gasEndsBeforeTruantActs) {
            ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, playerLeft);
            ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, playerRight);
        } else {
            ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, playerRight);
            ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, playerLeft);
        }
        NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_TACKLE, playerRight);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_POUND, playerRight);
    }
}

SINGLE_BATTLE_TEST("A Truant user switched in while Neutralizing Gas is active acts after it ends")
{
    GIVEN {
        WITH_CONFIG(B_TRUANT, GEN_5);
        PLAYER(SPECIES_WOBBUFFET) { Speed(4); }
        PLAYER(SPECIES_SLAKING) { Ability(ABILITY_TRUANT); Speed(3); }
        OPPONENT(SPECIES_KOFFING) { Ability(ABILITY_NEUTRALIZING_GAS); Speed(2); }
        OPPONENT(SPECIES_WYNAUT) { Speed(1); }
    } WHEN {
        TURN { MOVE(player, MOVE_BATON_PASS); SEND_OUT(player, 1); MOVE(opponent, MOVE_MEMENTO); SEND_OUT(opponent, 1); }
        TURN { MOVE(player, MOVE_SCRATCH); }
        TURN { MOVE(player, MOVE_TACKLE); }
    } SCENE {
        ABILITY_POPUP(opponent, ABILITY_NEUTRALIZING_GAS);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_BATON_PASS, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_MEMENTO, opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, player);
        NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_TACKLE, player);
    }
}

DOUBLE_BATTLE_TEST("Truant loafs when Neutralizing Gas ends after Dynamax but before its action")
{
    GIVEN {
        WITH_CONFIG(B_TRUANT, GEN_5);
        PLAYER(SPECIES_WOBBUFFET) { Speed(3); }
        PLAYER(SPECIES_SLAKING) { Ability(ABILITY_TRUANT); Speed(2); }
        OPPONENT(SPECIES_KOFFING) { Ability(ABILITY_NEUTRALIZING_GAS); HP(1); Speed(1); }
        OPPONENT(SPECIES_WYNAUT) { Speed(1); }
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_SCRATCH, target: opponentLeft); MOVE(playerRight, MOVE_SCRATCH, gimmick: GIMMICK_DYNAMAX, target: opponentRight); }
        TURN { MOVE(playerRight, MOVE_EMBER, target: opponentRight); }
    } SCENE {
        ABILITY_POPUP(opponentLeft, ABILITY_NEUTRALIZING_GAS);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_DYNAMAX_GROWTH, playerRight);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, playerLeft);
        NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_MAX_STRIKE, playerRight);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_MAX_FLARE, playerRight);
    }
}

DOUBLE_BATTLE_TEST("Ability Shield preserves Truant's counter through Neutralizing Gas")
{
    GIVEN {
        WITH_CONFIG(B_TRUANT, GEN_5);
        ASSUME(GetItemHoldEffect(ITEM_ABILITY_SHIELD) == HOLD_EFFECT_ABILITY_SHIELD);
        PLAYER(SPECIES_WOBBUFFET) { Speed(3); }
        PLAYER(SPECIES_SLAKING) { Ability(ABILITY_TRUANT); Item(ITEM_ABILITY_SHIELD); Speed(2); }
        OPPONENT(SPECIES_KOFFING) { Ability(ABILITY_NEUTRALIZING_GAS); HP(1); Speed(1); }
        OPPONENT(SPECIES_WYNAUT) { Speed(1); }
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_CELEBRATE); MOVE(playerRight, MOVE_SCRATCH, target: opponentRight); }
        TURN { MOVE(playerLeft, MOVE_SCRATCH, target: opponentLeft); MOVE(playerRight, MOVE_SCRATCH, target: opponentRight); }
        TURN { MOVE(playerRight, MOVE_SCRATCH, target: opponentRight); }
    } SCENE {
        ABILITY_POPUP(opponentLeft, ABILITY_NEUTRALIZING_GAS);
        MESSAGE("Neutralizing gas filled the area!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, playerRight);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, playerLeft);
        MESSAGE("The effects of the neutralizing gas wore off!");
        MESSAGE("Slaking is loafing around!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, playerRight);
    }
}

DOUBLE_BATTLE_TEST("Ability Shield keeps Truant's counter running when Neutralizing Gas ends after it loafs")
{
    GIVEN {
        WITH_CONFIG(B_TRUANT, GEN_5);
        ASSUME(GetItemHoldEffect(ITEM_ABILITY_SHIELD) == HOLD_EFFECT_ABILITY_SHIELD);
        PLAYER(SPECIES_WOBBUFFET) { Speed(1); }
        PLAYER(SPECIES_SLAKING) { Ability(ABILITY_TRUANT); Item(ITEM_ABILITY_SHIELD); Speed(3); }
        OPPONENT(SPECIES_KOFFING) { Ability(ABILITY_NEUTRALIZING_GAS); HP(1); Speed(2); }
        OPPONENT(SPECIES_WYNAUT) { HP(1000); MaxHP(1000); Speed(1); }
    } WHEN {
        TURN { MOVE(playerRight, MOVE_SCRATCH, target: opponentRight); MOVE(playerLeft, MOVE_CELEBRATE); }
        TURN { MOVE(playerRight, MOVE_SCRATCH, target: opponentRight); MOVE(playerLeft, MOVE_SCRATCH, target: opponentLeft); }
        TURN { MOVE(playerRight, MOVE_SCRATCH, target: opponentRight); }
    } SCENE {
        ABILITY_POPUP(opponentLeft, ABILITY_NEUTRALIZING_GAS);
        MESSAGE("Neutralizing gas filled the area!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, playerRight);
        MESSAGE("Slaking is loafing around!");
        MESSAGE("The effects of the neutralizing gas wore off!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, playerRight);
    }
}

DOUBLE_BATTLE_TEST("Neutralizing Gas arriving and fainting on a loafing turn lets Truant act instead")
{
    GIVEN {
        WITH_CONFIG(B_TRUANT, GEN_5);
        PLAYER(SPECIES_WOBBUFFET) { Speed(4); }
        PLAYER(SPECIES_SLAKING) { Ability(ABILITY_TRUANT); Speed(3); }
        OPPONENT(SPECIES_WYNAUT) { HP(1000); MaxHP(1000); Speed(1); }
        OPPONENT(SPECIES_WOBBUFFET) { HP(1000); MaxHP(1000); Speed(1); }
        OPPONENT(SPECIES_WEEZING) { Ability(ABILITY_NEUTRALIZING_GAS); HP(1); Speed(1); }
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_CELEBRATE); MOVE(playerRight, MOVE_SCRATCH, target: opponentLeft); }
        TURN { SWITCH(opponentLeft, 2);
               MOVE(playerLeft, MOVE_SCRATCH, target: opponentLeft);
               MOVE(playerRight, MOVE_SCRATCH, target: opponentRight);
               SEND_OUT(opponentLeft, 0); }
        TURN { MOVE(playerRight, MOVE_SCRATCH, target: opponentRight); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, playerRight);
        ABILITY_POPUP(opponentLeft, ABILITY_NEUTRALIZING_GAS);
        MESSAGE("Neutralizing gas filled the area!");
        MESSAGE("The effects of the neutralizing gas wore off!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, playerRight);
        MESSAGE("Slaking is loafing around!");
    }
}

SINGLE_BATTLE_TEST("Neutralizing Gas resets rather than freezes Truant's counter")
{
    GIVEN {
        WITH_CONFIG(B_TRUANT, GEN_5);
        PLAYER(SPECIES_SLAKING) { Ability(ABILITY_TRUANT); }
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_KOFFING) { Ability(ABILITY_NEUTRALIZING_GAS); }
    } WHEN {
        TURN { MOVE(player, MOVE_SCRATCH); }
        TURN { SWITCH(opponent, 1); MOVE(player, MOVE_SCRATCH); }
        TURN { SWITCH(opponent, 0); MOVE(player, MOVE_SCRATCH); }
        TURN { MOVE(player, MOVE_SCRATCH); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, player);
        ABILITY_POPUP(opponent, ABILITY_NEUTRALIZING_GAS);
        MESSAGE("Neutralizing gas filled the area!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, player);
        MESSAGE("The effects of the neutralizing gas wore off!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, player);
        MESSAGE("Slaking is loafing around!");
    }
}

SINGLE_BATTLE_TEST("A battle item does not advance Truant when Neutralizing Gas wears off later that turn")
{
    GIVEN {
        WITH_CONFIG(B_TRUANT, GEN_5);
        PLAYER(SPECIES_SLAKING) { Ability(ABILITY_TRUANT); }
        OPPONENT(SPECIES_KOFFING) { Ability(ABILITY_NEUTRALIZING_GAS); }
        OPPONENT(SPECIES_WYNAUT);
    } WHEN {
        TURN { USE_ITEM(player, ITEM_X_ATTACK); MOVE(opponent, MOVE_MEMENTO); SEND_OUT(opponent, 1); }
        TURN { MOVE(player, MOVE_SCRATCH); }
    } SCENE {
        ABILITY_POPUP(opponent, ABILITY_NEUTRALIZING_GAS);
        MESSAGE("Neutralizing gas filled the area!");
        MESSAGE("The effects of the neutralizing gas wore off!");
        MESSAGE("The opposing Koffing fainted!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, player);
    }
}

SINGLE_BATTLE_TEST("Being held by Sky Drop does not advance Truant")
{
    GIVEN {
        WITH_CONFIG(B_TRUANT, GEN_5);
        ASSUME(GetMoveEffect(MOVE_SKY_DROP) == EFFECT_SKY_DROP);
        ASSUME(GetMovePriority(MOVE_QUICK_ATTACK) > GetMovePriority(MOVE_SKY_DROP));
        PLAYER(SPECIES_SLAKING) { Ability(ABILITY_TRUANT); Speed(1); }
        OPPONENT(SPECIES_AERODACTYL) { Speed(2); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_SKY_DROP); MOVE(player, MOVE_SCRATCH); }
        TURN { MOVE(player, MOVE_QUICK_ATTACK); SKIP_TURN(opponent); }
        TURN { MOVE(player, MOVE_SCRATCH); }
        TURN { MOVE(player, MOVE_TACKLE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SKY_DROP, opponent);
        NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_QUICK_ATTACK, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SKY_DROP, opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, player);
        NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_TACKLE, player);
    }
}

SINGLE_BATTLE_TEST("Gaining Truant after Mega Evolution causes an immediate loafing turn")
{
    GIVEN {
        WITH_CONFIG(B_TRUANT, GEN_5);
        ASSUME(GetMoveEffect(MOVE_SKILL_SWAP) == EFFECT_SKILL_SWAP);
        PLAYER(SPECIES_SALAMENCE) { Ability(ABILITY_INTIMIDATE); Item(ITEM_SALAMENCITE); Speed(1); }
        OPPONENT(SPECIES_SLAKING) { Ability(ABILITY_TRUANT); Speed(2); }
    } WHEN {
        TURN { MOVE(player, MOVE_SCRATCH, gimmick: GIMMICK_MEGA); MOVE(opponent, MOVE_SKILL_SWAP); }
        TURN { MOVE(player, MOVE_SCRATCH); }
    } SCENE {
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_MEGA_EVOLUTION, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SKILL_SWAP, opponent);
        MESSAGE("Salamence is loafing around!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, player);
    }
}

SINGLE_BATTLE_TEST("Gaining Truant after Terastallizing causes an immediate loafing turn")
{
    GIVEN {
        WITH_CONFIG(B_TRUANT, GEN_5);
        ASSUME(GetMoveEffect(MOVE_SKILL_SWAP) == EFFECT_SKILL_SWAP);
        PLAYER(SPECIES_WOBBUFFET) { TeraType(TYPE_WATER); Speed(1); }
        OPPONENT(SPECIES_SLAKING) { Ability(ABILITY_TRUANT); Speed(2); }
    } WHEN {
        TURN { MOVE(player, MOVE_SCRATCH, gimmick: GIMMICK_TERA); MOVE(opponent, MOVE_SKILL_SWAP); }
        TURN { MOVE(player, MOVE_SCRATCH); }
    } SCENE {
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_TERA_ACTIVATE, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SKILL_SWAP, opponent);
        MESSAGE("Wobbuffet is loafing around!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, player);
    }
}

SINGLE_BATTLE_TEST("Terastallizing with Truant does not affect its counter")
{
    GIVEN {
        WITH_CONFIG(B_TRUANT, GEN_5);
        PLAYER(SPECIES_SLAKING) { Ability(ABILITY_TRUANT); TeraType(TYPE_NORMAL); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_SCRATCH); }
        TURN { MOVE(player, MOVE_SCRATCH, gimmick: GIMMICK_TERA); }
        TURN { MOVE(player, MOVE_SCRATCH); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, player);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_TERA_ACTIVATE, player);
        MESSAGE("Slaking is loafing around!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, player);
    }
}

SINGLE_BATTLE_TEST("Truant cannot be overwritten by Simple Beam, Worry Seed or Entrainment")
{
    enum Move move;
    PARAMETRIZE { move = MOVE_SIMPLE_BEAM; }
    PARAMETRIZE { move = MOVE_WORRY_SEED; }
    PARAMETRIZE { move = MOVE_ENTRAINMENT; }

    GIVEN {
        ASSUME(GetMoveEffect(MOVE_ENTRAINMENT) == EFFECT_ENTRAINMENT);
        ASSUME(GetMoveEffect(MOVE_SIMPLE_BEAM) == EFFECT_OVERWRITE_ABILITY);
        ASSUME(GetMoveEffect(MOVE_WORRY_SEED) == EFFECT_OVERWRITE_ABILITY);
        ASSUME(gAbilitiesInfo[ABILITY_TRUANT].cantBeOverwritten);
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_SHADOW_TAG); }
        OPPONENT(SPECIES_SLAKING) { Ability(ABILITY_TRUANT); }
    } WHEN {
        TURN { MOVE(player, move); }
    } SCENE {
        MESSAGE("But it failed!");
    } THEN {
        EXPECT_EQ(opponent->ability, ABILITY_TRUANT);
    }
}

SINGLE_BATTLE_TEST("A Truant user can hand Truant over with Entrainment")
{
    GIVEN {
        WITH_CONFIG(B_TRUANT, GEN_5);
        ASSUME(GetMoveEffect(MOVE_ENTRAINMENT) == EFFECT_ENTRAINMENT);
        PLAYER(SPECIES_SLAKING) { Ability(ABILITY_TRUANT); Speed(2); }
        OPPONENT(SPECIES_WOBBUFFET) { Ability(ABILITY_SHADOW_TAG); Speed(1); }
    } WHEN {
        TURN { MOVE(player, MOVE_ENTRAINMENT); MOVE(opponent, MOVE_CELEBRATE); }
        TURN { MOVE(player, MOVE_CELEBRATE); MOVE(opponent, MOVE_CELEBRATE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_ENTRAINMENT, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, opponent);
        MESSAGE("Slaking is loafing around!");
        MESSAGE("The opposing Wobbuffet is loafing around!");
    } THEN {
        EXPECT_EQ(opponent->ability, ABILITY_TRUANT);
    }
}

SINGLE_BATTLE_TEST("Role Play copying Truant makes the user loaf on the following turn")
{
    GIVEN {
        WITH_CONFIG(B_TRUANT, GEN_5);
        ASSUME(GetMoveEffect(MOVE_ROLE_PLAY) == EFFECT_ROLE_PLAY);
        PLAYER(SPECIES_WOBBUFFET) { Speed(2); }
        OPPONENT(SPECIES_SLAKING) { Ability(ABILITY_TRUANT); Speed(1); }
    } WHEN {
        TURN { MOVE(player, MOVE_ROLE_PLAY); }
        TURN { MOVE(player, MOVE_CELEBRATE); }
        TURN { MOVE(player, MOVE_CELEBRATE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_ROLE_PLAY, player);
        MESSAGE("Wobbuffet is loafing around!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, player);
    } THEN {
        EXPECT_EQ(player->ability, ABILITY_TRUANT);
    }
}

SINGLE_BATTLE_TEST("Transforming into a Truant user makes the transformer loaf on the following turn")
{
    GIVEN {
        WITH_CONFIG(B_TRUANT, GEN_5);
        ASSUME(GetMoveEffect(MOVE_TRANSFORM) == EFFECT_TRANSFORM);
        PLAYER(SPECIES_DITTO) { Ability(ABILITY_LIMBER); Speed(2); }
        OPPONENT(SPECIES_SLAKING) { Ability(ABILITY_TRUANT); Moves(MOVE_CELEBRATE); Speed(1); }
    } WHEN {
        TURN { MOVE(player, MOVE_TRANSFORM); }
        TURN { MOVE(player, moveSlot: 0); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_TRANSFORM, player);
        MESSAGE("Ditto is loafing around!");
    } THEN {
        EXPECT_EQ(player->ability, ABILITY_TRUANT);
    }
}

SINGLE_BATTLE_TEST("Mummy overwrites Truant and clears its counter")
{
    GIVEN {
        WITH_CONFIG(B_TRUANT, GEN_5);
        ASSUME(MoveMakesContact(MOVE_SHADOW_PUNCH));
        PLAYER(SPECIES_SLAKING) { Ability(ABILITY_TRUANT); }
        OPPONENT(SPECIES_COFAGRIGUS) { Ability(ABILITY_MUMMY); HP(1000); MaxHP(1000); }
    } WHEN {
        TURN { MOVE(player, MOVE_SHADOW_PUNCH); }
        TURN { MOVE(player, MOVE_SHADOW_PUNCH); }
        TURN { MOVE(player, MOVE_SHADOW_PUNCH); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SHADOW_PUNCH, player);
        ABILITY_POPUP(opponent, ABILITY_MUMMY);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SHADOW_PUNCH, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SHADOW_PUNCH, player);
    } THEN {
        EXPECT_EQ(player->ability, ABILITY_MUMMY);
    }
}

SINGLE_BATTLE_TEST("Wandering Spirit hands Truant to the attacker")
{
    GIVEN {
        WITH_CONFIG(B_TRUANT, GEN_5);
        ASSUME(MoveMakesContact(MOVE_SHADOW_PUNCH));
        PLAYER(SPECIES_SLAKING) { Ability(ABILITY_TRUANT); Speed(2); }
        OPPONENT(SPECIES_RUNERIGUS) { Ability(ABILITY_WANDERING_SPIRIT); HP(1000); MaxHP(1000); Speed(1); }
    } WHEN {
        TURN { MOVE(player, MOVE_SHADOW_PUNCH); MOVE(opponent, MOVE_CELEBRATE); }
        TURN { MOVE(player, MOVE_SHADOW_PUNCH); MOVE(opponent, MOVE_CELEBRATE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SHADOW_PUNCH, player);
        ABILITY_POPUP(opponent, ABILITY_WANDERING_SPIRIT);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SHADOW_PUNCH, player);
        MESSAGE("The opposing Runerigus is loafing around!");
    } THEN {
        EXPECT_EQ(player->ability, ABILITY_WANDERING_SPIRIT);
        EXPECT_EQ(opponent->ability, ABILITY_TRUANT);
    }
}

SINGLE_BATTLE_TEST("Gastro Acid stops Truant from loafing")
{
    GIVEN {
        WITH_CONFIG(B_TRUANT, GEN_5);
        ASSUME(GetMoveEffect(MOVE_GASTRO_ACID) == EFFECT_GASTRO_ACID);
        PLAYER(SPECIES_WOBBUFFET) { Speed(2); }
        OPPONENT(SPECIES_SLAKING) { Ability(ABILITY_TRUANT); Speed(1); }
    } WHEN {
        TURN { MOVE(player, MOVE_CELEBRATE); MOVE(opponent, MOVE_SCRATCH); }
        TURN { MOVE(player, MOVE_GASTRO_ACID); MOVE(opponent, MOVE_SCRATCH); }
        TURN { MOVE(player, MOVE_CELEBRATE); MOVE(opponent, MOVE_SCRATCH); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_GASTRO_ACID, player);
        NOT MESSAGE("The opposing Slaking is loafing around!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, opponent);
    }
}

SINGLE_BATTLE_TEST("A Truant loafing turn does not consume a confusion turn")
{
    GIVEN {
        WITH_CONFIG(B_TRUANT, GEN_5);
        ASSUME(GetMoveEffect(MOVE_CONFUSE_RAY) == EFFECT_CONFUSE);
        PLAYER(SPECIES_SLAKING) { Ability(ABILITY_TRUANT); Speed(2); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(1); }
    } WHEN {
        TURN { MOVE(player, MOVE_SCRATCH); MOVE(opponent, MOVE_CONFUSE_RAY, WITH_RNG(RNG_CONFUSION_TURNS, 2)); }
        TURN { MOVE(player, MOVE_SCRATCH); }
        TURN { MOVE(player, MOVE_SCRATCH, WITH_RNG(RNG_CONFUSION, FALSE)); }
        TURN { MOVE(player, MOVE_SCRATCH); }
        TURN { MOVE(player, MOVE_SCRATCH); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CONFUSE_RAY, opponent);
        MESSAGE("Slaking is loafing around!");
        MESSAGE("Slaking is confused!");
        MESSAGE("Slaking is loafing around!");
        MESSAGE("Slaking snapped out of its confusion!");
    }
}

SINGLE_BATTLE_TEST("A Truant user can still switch out on a loafing turn")
{
    GIVEN {
        WITH_CONFIG(B_TRUANT, GEN_5);
        PLAYER(SPECIES_SLAKING) { Ability(ABILITY_TRUANT); }
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_SCRATCH); }
        TURN { SWITCH(player, 1); }
        TURN { MOVE(player, MOVE_CELEBRATE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, player);
        NOT MESSAGE("Slaking is loafing around!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, player);
    }
}

SINGLE_BATTLE_TEST("Using an item on a Gen 5+ loafing turn leaves the loafing turn pending")
{
    GIVEN {
        WITH_CONFIG(B_TRUANT, GEN_5);
        PLAYER(SPECIES_SLAKING) { Ability(ABILITY_TRUANT); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_SCRATCH); }
        TURN { USE_ITEM(player, ITEM_X_ATTACK); }
        TURN { MOVE(player, MOVE_SCRATCH); }
        TURN { MOVE(player, MOVE_SCRATCH); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, player);
        MESSAGE("Slaking is loafing around!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, player);
    }
}

SINGLE_BATTLE_TEST("A Truant user put to sleep on a loafing turn loafs when it wakes up")
{
    GIVEN {
        WITH_CONFIG(B_TRUANT, GEN_5);
        ASSUME(GetMoveNonVolatileStatus(MOVE_SPORE) == MOVE_EFFECT_SLEEP);
        PLAYER(SPECIES_SLAKING) { Ability(ABILITY_TRUANT); Speed(1); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(2); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_CELEBRATE); MOVE(player, MOVE_SCRATCH); }
        TURN { MOVE(opponent, MOVE_SPORE, WITH_RNG(RNG_SLEEP_TURNS, 2)); MOVE(player, MOVE_SCRATCH); }
        TURN { MOVE(player, MOVE_SCRATCH); }
        TURN { MOVE(player, MOVE_SCRATCH); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SPORE, opponent);
        MESSAGE("Slaking fell asleep!");
        MESSAGE("Slaking is fast asleep.");
        MESSAGE("Slaking woke up!");
        MESSAGE("Slaking is loafing around!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, player);
    }
}

SINGLE_BATTLE_TEST("A battler that gains Truant as it switches in loafs first before Gen 5")
{
    u32 gen;
    PARAMETRIZE { gen = GEN_3; }
    PARAMETRIZE { gen = GEN_4; }
    PARAMETRIZE { gen = GEN_5; }

    GIVEN {
        WITH_CONFIG(B_TRUANT, gen);
        ASSUME(GetMoveEffect(MOVE_SKILL_SWAP) == EFFECT_SKILL_SWAP);
        PLAYER(SPECIES_WOBBUFFET) { Speed(1); }
        PLAYER(SPECIES_WYNAUT) { Ability(ABILITY_SHADOW_TAG); Speed(1); }
        OPPONENT(SPECIES_SLAKING) { Ability(ABILITY_TRUANT); Speed(2); }
    } WHEN {
        TURN { SWITCH(player, 1); MOVE(opponent, MOVE_SKILL_SWAP); }
        TURN { MOVE(player, MOVE_SCRATCH); }
        TURN { MOVE(player, MOVE_SCRATCH); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SKILL_SWAP, opponent);
        if (gen <= GEN_4) {
            MESSAGE("Wynaut is loafing around!");
            ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, player);
        } else {
            ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, player);
            MESSAGE("Wynaut is loafing around!");
        }
    }
}
