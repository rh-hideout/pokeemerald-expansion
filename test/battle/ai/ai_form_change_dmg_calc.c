#include "global.h"
#include "test/battle.h"
#include "battle_ai_util.h"

AI_SINGLE_BATTLE_TEST("Damage Calc Form Change: AI will see it's own new weather after form change")
{
    enum Item item = ITEM_NONE;

    PARAMETRIZE { item = ITEM_NONE; }
    PARAMETRIZE { item = ITEM_CHARIZARDITE_Y; }

    GIVEN {
        WITH_CONFIG(SHOULD_CALC_DMG_WITH_FORM_CHANGE, 1);
        ASSUME(GetMovePower(MOVE_SOLAR_BEAM) == 120);
        ASSUME(GetMovePower(MOVE_ENERGY_BALL) == 90);
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT);
        PLAYER(SPECIES_MILOTIC) { HP(211); }
        OPPONENT(SPECIES_CHARIZARD) { Moves(MOVE_SOLAR_BEAM, MOVE_ENERGY_BALL); Item(item); }
    } WHEN {
        if (item == ITEM_CHARIZARDITE_Y) {
            TURN { EXPECT_MOVE(opponent, MOVE_SOLAR_BEAM, gimmick: GIMMICK_MEGA); }
        } else {
            TURN { EXPECT_MOVE(opponent, MOVE_ENERGY_BALL); }
        }
    }
}

AI_SINGLE_BATTLE_TEST("Damage Calc Form Change: AI sees its own weather setting ability after Mega evolution when considering switchin candidates")
{
    enum Item item = ITEM_NONE;

    PARAMETRIZE { item = ITEM_NONE; }
    PARAMETRIZE { item = ITEM_CHARIZARDITE_Y; }

    GIVEN {
        WITH_CONFIG(SHOULD_CALC_DMG_WITH_FORM_CHANGE, 1);
        ASSUME(GetMovePower(MOVE_FIRE_BLAST) == 110);
        ASSUME(GetMoveType(MOVE_FIRE_BLAST) == TYPE_FIRE);
        ASSUME(GetMovePower(MOVE_SUPERPOWER) == 120);
        ASSUME(GetMoveType(MOVE_SUPERPOWER) == TYPE_FIGHTING);
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT | AI_FLAG_SMART_MON_CHOICES | AI_FLAG_OMNISCIENT);
        PLAYER(SPECIES_KANGASKHAN) { Moves(MOVE_SCRATCH); }
        OPPONENT(SPECIES_ZIGZAGOON) { Level(1); Moves(MOVE_SCRATCH); }
        OPPONENT(SPECIES_CHARIZARD) { Moves(MOVE_FIRE_BLAST); Item(item); }
        OPPONENT(SPECIES_CONKELDURR) { Ability(ABILITY_GUTS); Moves(MOVE_SUPERPOWER); }
    } WHEN {
        if (item == ITEM_CHARIZARDITE_Y)
            TURN { MOVE(player, MOVE_SCRATCH); EXPECT_MOVE(opponent, MOVE_SCRATCH); EXPECT_SEND_OUT(opponent, 1); }
        else
            TURN { MOVE(player, MOVE_SCRATCH); EXPECT_MOVE(opponent, MOVE_SCRATCH); EXPECT_SEND_OUT(opponent, 2); }
    }
}

AI_MULTI_BATTLE_TEST("Damage Calc Form Change: AI sees its own Mega form on turn 1 (Multi)")
{
    GIVEN {
        WITH_CONFIG(SHOULD_CALC_DMG_WITH_FORM_CHANGE, 1);
        AI_FLAGS(AI_FLAG_SMART_TRAINER);
        PLAYER(SPECIES_GENGAR) { Speed(4); Moves(MOVE_DRAGON_RAGE, MOVE_CELEBRATE); HP(3); Defense(999); }
        PARTNER(SPECIES_LOPUNNY) { Speed(1); Moves(MOVE_FAKE_OUT, MOVE_DRAGON_RAGE); HP(40); Attack(1); Item(ITEM_LOPUNNITE); }
        OPPONENT_A(SPECIES_LOPUNNY) { Speed(2); Moves(MOVE_FAKE_OUT, MOVE_DRAGON_RAGE); HP(40); Attack(1); Item(ITEM_LOPUNNITE); }
        OPPONENT_B(SPECIES_LOPUNNY) { Speed(3); Moves(MOVE_FAKE_OUT, MOVE_SHADOW_BALL); HP(40); Attack(1); Item(ITEM_LOPUNNITE); }
    } WHEN {
        TURN {
            MOVE(playerLeft, MOVE_CELEBRATE);
            EXPECT_MOVE(opponentLeft, MOVE_FAKE_OUT, target:playerLeft, gimmick: GIMMICK_MEGA);
            EXPECT_MOVE(playerRight, MOVE_FAKE_OUT, target:opponentLeft, gimmick: GIMMICK_MEGA);
            EXPECT_MOVE(opponentRight, MOVE_FAKE_OUT, target:playerLeft, gimmick: GIMMICK_MEGA);
        }
    }
}

AI_ONE_VS_TWO_BATTLE_TEST("Damage Calc Form Change: AI sees its own Mega form for switch-in calcs (1v2)")
{
    // The first Lopunny in each AI party should see itself outspeed but unable to damage
    // The second Lopunny should see it has scrappy and can therefore KO the Gengars
    GIVEN {
        WITH_CONFIG(SHOULD_CALC_DMG_WITH_FORM_CHANGE, 1);
        AI_FLAGS(AI_FLAG_SMART_TRAINER);
        TIE_BREAK_TARGET(TARGET_TIE_LO, 0);

        PLAYER(SPECIES_GENGAR_MEGA) { Speed(4); Moves(MOVE_AURA_SPHERE); HP(1); Ability(ABILITY_SHADOW_TAG); Item(ITEM_GENGARITE); }
        PLAYER(SPECIES_GENGAR) { Speed(1); Moves(MOVE_AURA_SPHERE); HP(1); }

        OPPONENT_A(SPECIES_TRAPINCH) { Speed(3); Moves(MOVE_MEMENTO); HP(1); Ability(ABILITY_ARENA_TRAP); }
        OPPONENT_A(SPECIES_LOPUNNY) { Speed(6); Moves(MOVE_FAKE_OUT); HP(1); Attack(1); }
        OPPONENT_A(SPECIES_LOPUNNY) { Speed(9); Moves(MOVE_FAKE_OUT); HP(1); Attack(1); Item(ITEM_LOPUNNITE); }

        OPPONENT_B(SPECIES_TRAPINCH) { Speed(2); Moves(MOVE_MEMENTO); HP(1); Ability(ABILITY_ARENA_TRAP); }
        OPPONENT_B(SPECIES_LOPUNNY) { Speed(7); Moves(MOVE_FAKE_OUT); HP(1); Attack(1); }
        OPPONENT_B(SPECIES_LOPUNNY) { Speed(10); Moves(MOVE_FAKE_OUT); HP(1); Attack(1); Item(ITEM_LOPUNNITE); }
    } WHEN {
        TURN {
            EXPECT_MOVE(opponentLeft, MOVE_MEMENTO);
            EXPECT_MOVE(opponentRight, MOVE_MEMENTO);
            EXPECT_SEND_OUT(opponentLeft, 2);
            EXPECT_SEND_OUT(opponentRight, 2);
        }
        TURN {
            EXPECT_MOVE(opponentLeft, MOVE_FAKE_OUT, gimmick: GIMMICK_MEGA);
            EXPECT_MOVE(opponentRight, MOVE_FAKE_OUT, gimmick: GIMMICK_MEGA);
        }
    }
}
