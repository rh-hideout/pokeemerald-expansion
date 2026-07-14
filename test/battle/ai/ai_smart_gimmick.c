#include "global.h"
#include "test/battle.h"
#include "battle_ai_util.h"

AI_SINGLE_BATTLE_TEST("AI_FLAG_SMART_GIMMICK: AI will tera if it enables a ko")
{
    GIVEN {
        ASSUME(GetMovePower(MOVE_SEED_BOMB) == 80);
        ASSUME(GetMovePower(MOVE_AQUA_TAIL) == 90);
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT | AI_FLAG_SMART_GIMMICK);
        PLAYER(SPECIES_WOBBUFFET) { HP(47); Speed(100); }
        PLAYER(SPECIES_WOBBUFFET) { Speed(100); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(1); Moves(MOVE_AQUA_TAIL, MOVE_SEED_BOMB); TeraType(TYPE_GRASS); }
        OPPONENT(SPECIES_WOBBUFFET) { HP(1); Speed(100); TeraType(TYPE_FIRE); }
    } WHEN {
        TURN { EXPECT_MOVE(opponent, MOVE_SEED_BOMB, gimmick: GIMMICK_TERA); SEND_OUT(player, 1); }
    } SCENE {
        MESSAGE("The opposing Wobbuffet terastallized into the Grass type!");
        MESSAGE("Wobbuffet fainted!");
    }
}

AI_SINGLE_BATTLE_TEST("AI_FLAG_SMART_GIMMICK: AI will not tera if it gets outsped and ko'd")
{
    GIVEN {
        ASSUME(GetMovePower(MOVE_SEED_BOMB) == 80);
        ASSUME(GetMovePower(MOVE_FLAMETHROWER) == 90);
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT | AI_FLAG_SMART_GIMMICK | AI_FLAG_OMNISCIENT );
        PLAYER(SPECIES_WOBBUFFET) { HP(47); Speed(100); Moves(MOVE_FLAMETHROWER, MOVE_CELEBRATE); }
        PLAYER(SPECIES_WOBBUFFET) { Speed(100); }
        OPPONENT(SPECIES_WOBBUFFET) { HP(60); Speed(1); Moves(MOVE_SEED_BOMB); TeraType(TYPE_GRASS); }
        OPPONENT(SPECIES_WOBBUFFET) { HP(1); Speed(100); TeraType(TYPE_FIRE); }
    } WHEN {
        TURN {}
    } SCENE {
        NOT MESSAGE("The opposing Wobbuffet terastallized into the Grass type!");
    }
}

AI_SINGLE_BATTLE_TEST("AI_FLAG_SMART_GIMMICK: AI will not tera if it gets ko'd by priority")
{
    GIVEN {
        ASSUME(GetMovePower(MOVE_SEED_BOMB) == 80);
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT | AI_FLAG_SMART_GIMMICK | AI_FLAG_OMNISCIENT );
        PLAYER(SPECIES_WOBBUFFET) { HP(47); Speed(1); Moves(MOVE_QUICK_ATTACK, MOVE_CELEBRATE); }
        PLAYER(SPECIES_WOBBUFFET) { Speed(100); }
        OPPONENT(SPECIES_WOBBUFFET) { HP(1); Speed(100); Moves(MOVE_SEED_BOMB, MOVE_AQUA_TAIL); TeraType(TYPE_GRASS); }
        OPPONENT(SPECIES_WOBBUFFET) { HP(1); Speed(100); TeraType(TYPE_FIRE); }
    } WHEN {
        TURN {  }
    } SCENE {
        NOT MESSAGE("The opposing Wobbuffet terastallized into the Grass type!");
    }
}

AI_SINGLE_BATTLE_TEST("AI_FLAG_SMART_GIMMICK: AI might tera if it gets saved from a ko")
{
    PASSES_RANDOMLY(90, 100, RNG_AI_CONSERVE_TERA);
    GIVEN {
        ASSUME(GetMovePower(MOVE_SEED_BOMB) == 80);
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT | AI_FLAG_SMART_GIMMICK | AI_FLAG_OMNISCIENT );
        PLAYER(SPECIES_WOBBUFFET) { HP(47); Speed(100); Moves(MOVE_SEED_BOMB); }
        PLAYER(SPECIES_WOBBUFFET) { Speed(100); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(100); HP(30); Moves(MOVE_SEED_BOMB); TeraType(TYPE_FIRE); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(100); TeraType(TYPE_FIRE); }
    } WHEN {
        TURN { MOVE(player, MOVE_SEED_BOMB); }
    } SCENE {
        MESSAGE("The opposing Wobbuffet terastallized into the Fire type!");
    }
}

AI_MULTI_BATTLE_TEST("AI sees its own Mega form on turn 1 (Multi)")
{
    GIVEN {
        AI_FLAGS(AI_FLAG_SMART_TRAINER | AI_FLAG_SMART_GIMMICK);
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

AI_ONE_VS_TWO_BATTLE_TEST("AI sees its own Mega form for switch-in calcs (1v2)")
{
    // The first Lopunny in each AI party should see itself outspeed but unable to damage
    // The second Lopunny should see it has scrappy and can therefore KO the Gengars
    GIVEN {
        AI_FLAGS(AI_FLAG_SMART_TRAINER | AI_FLAG_SMART_GIMMICK);
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
