#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(GetMoveEffect(MOVE_TRANSFORM) == EFFECT_TRANSFORM);
}

SINGLE_BATTLE_TEST("Transform fails on semi-invulnerable target in Gen2+")
{
    u32 genConfig;
    bool32 expectFail;

    // PARAMETRIZE { genConfig = GEN_1; expectFail = FALSE; } // Gen1 Setting broken by #9170
    PARAMETRIZE { genConfig = GEN_2; expectFail = TRUE; }

    GIVEN {
        WITH_CONFIG(B_TRANSFORM_SEMI_INV_FAIL, genConfig);
        PLAYER(SPECIES_WOBBUFFET) { Speed(50); Moves(MOVE_DIG); }
        OPPONENT(SPECIES_DITTO) { Speed(10); Moves(MOVE_TRANSFORM); }
    } WHEN {
        TURN { MOVE(player, MOVE_DIG); MOVE(opponent, MOVE_TRANSFORM); }
    } SCENE {
        if (expectFail)
            MESSAGE("Wobbuffet avoided the attack!");
        else
            MESSAGE("The opposing Ditto transformed into Wobbuffet!");
    }
}

SINGLE_BATTLE_TEST("Transform fails on transformed target in Gen2+")
{
    u32 genConfig;
    bool32 expectFail;

    PARAMETRIZE { genConfig = GEN_1; expectFail = FALSE; }
    PARAMETRIZE { genConfig = GEN_2; expectFail = TRUE; }

    GIVEN {
        WITH_CONFIG(B_TRANSFORM_TARGET_FAIL, genConfig);
        PLAYER(SPECIES_DITTO) { Speed(50); Moves(MOVE_TRANSFORM, MOVE_CELEBRATE); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(10); Moves(MOVE_TRANSFORM, MOVE_CELEBRATE); }
    } WHEN {
        TURN { MOVE(player, MOVE_TRANSFORM); MOVE(opponent, MOVE_CELEBRATE); }
        TURN { MOVE(player, MOVE_CELEBRATE); MOVE(opponent, MOVE_TRANSFORM); }
    } SCENE {
        MESSAGE("Ditto transformed into Wobbuffet!");
        if (expectFail)
            MESSAGE("But it failed!");
        else
            MESSAGE("The opposing Wobbuffet transformed into Wobbuffet!");
    }
}

SINGLE_BATTLE_TEST("Transform fails when the user is already transformed in Gen5+")
{
    u32 genConfig;
    bool32 expectFail;

    PARAMETRIZE { genConfig = GEN_4; expectFail = FALSE; }
    PARAMETRIZE { genConfig = GEN_5; expectFail = TRUE; }

    GIVEN {
        WITH_CONFIG(B_TRANSFORM_USER_FAIL, genConfig);
        PLAYER(SPECIES_WOBBUFFET) { Speed(50); Moves(MOVE_TRANSFORM, MOVE_CELEBRATE); }
        OPPONENT(SPECIES_DITTO) { Speed(10); Moves(MOVE_TRANSFORM, MOVE_CELEBRATE); }
    } WHEN {
        TURN { MOVE(player, MOVE_CELEBRATE); MOVE(opponent, MOVE_TRANSFORM); }
        TURN { MOVE(player, MOVE_CELEBRATE); MOVE(opponent, MOVE_TRANSFORM); }
    } SCENE {
        MESSAGE("The opposing Ditto transformed into Wobbuffet!");
        if (expectFail)
            MESSAGE("But it failed!");
        else
            MESSAGE("The opposing Ditto transformed into Wobbuffet!");
    }
}

SINGLE_BATTLE_TEST("Transform fails on target behind substitute in Gen5+")
{
    u32 genConfig;
    bool32 expectFail;

    PARAMETRIZE { genConfig = GEN_4; expectFail = FALSE; }
    PARAMETRIZE { genConfig = GEN_5; expectFail = TRUE; }

    GIVEN {
        WITH_CONFIG(B_TRANSFORM_SUBSTITUTE_FAIL, genConfig);
        PLAYER(SPECIES_WOBBUFFET) { Speed(50); Moves(MOVE_SUBSTITUTE); }
        OPPONENT(SPECIES_DITTO) { Speed(10); Moves(MOVE_TRANSFORM); }
    } WHEN {
        TURN { MOVE(player, MOVE_SUBSTITUTE); MOVE(opponent, MOVE_TRANSFORM); }
    } SCENE {
        if (expectFail)
            MESSAGE("But it failed!");
        else
            MESSAGE("The opposing Ditto transformed into Wobbuffet!");
    }
}

SINGLE_BATTLE_TEST("Transformed Pokemon cannot change forms in Gen5+")
{
    u32 genConfig;
    bool32 expectFormChange;

    PARAMETRIZE { genConfig = GEN_4; expectFormChange = TRUE; }
    PARAMETRIZE { genConfig = GEN_5; expectFormChange = FALSE; }

    GIVEN {
        WITH_CONFIG(B_TRANSFORM_FORM_CHANGES, genConfig);
        PLAYER(SPECIES_AEGISLASH) { Moves(MOVE_TACKLE, MOVE_CELEBRATE); }
        OPPONENT(SPECIES_DITTO) { Moves(MOVE_TACKLE, MOVE_TRANSFORM); }
    } WHEN {
        TURN { MOVE(player, MOVE_CELEBRATE); MOVE(opponent, MOVE_TRANSFORM); }
        TURN { MOVE(player, MOVE_CELEBRATE); MOVE(opponent, MOVE_TACKLE); }
    } SCENE {
        if (expectFormChange) {
            ABILITY_POPUP(opponent, ABILITY_STANCE_CHANGE);
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_FORM_CHANGE, opponent);
        } else {
            NONE_OF {
                ABILITY_POPUP(opponent, ABILITY_STANCE_CHANGE);
                ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_FORM_CHANGE, opponent);
            }
        }
    } THEN {
        if (expectFormChange)
            EXPECT_EQ(opponent->species, SPECIES_AEGISLASH_BLADE);
        else
            EXPECT_EQ(opponent->species, SPECIES_AEGISLASH);
    }
}

SINGLE_BATTLE_TEST("(TERA) Transform does not copy the target's Tera Type, and if the user is Terastallized it keeps its own Tera Type")
{
    u32 playerDoTera;
    PARAMETRIZE { playerDoTera = GIMMICK_TERA; }
    PARAMETRIZE { playerDoTera = GIMMICK_NONE; }
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Moves(MOVE_CELEBRATE, MOVE_SCRATCH, MOVE_EARTHQUAKE); TeraType(TYPE_GHOST); }
        OPPONENT(SPECIES_DITTO) { TeraType(TYPE_FLYING); }
    } WHEN {
        TURN { MOVE(player, MOVE_CELEBRATE, gimmick: playerDoTera); MOVE(opponent, MOVE_TRANSFORM); }
        TURN { MOVE(player, MOVE_SCRATCH); MOVE(opponent, moveSlot: 0); }
        TURN { MOVE(player, MOVE_EARTHQUAKE); MOVE(opponent, moveSlot: 0, gimmick: GIMMICK_TERA); }
    } SCENE {
        // turn 1
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_TRANSFORM, opponent);
        // turn 2
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, opponent);
        // turn 3
        MESSAGE("Wobbuffet used Earthquake!");
        MESSAGE("It doesn't affect the opposing Ditto…");
        NOT { HP_BAR(opponent); }
    }
}

SINGLE_BATTLE_TEST("Transform returns the user to normal at the end of the battle after fainting")
{
    GIVEN {
        PLAYER(SPECIES_DITTO) { HP(1); }
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_PIDGEOT) { Item(ITEM_PIDGEOTITE); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_CELEBRATE, gimmick: GIMMICK_MEGA); MOVE(player, MOVE_TRANSFORM); }
        TURN { MOVE(opponent, MOVE_SCRATCH); SEND_OUT(player, 1); }
    } THEN {
        EXPECT_EQ(GetMonData(&gParties[B_TRAINER_PLAYER][0], MON_DATA_SPECIES), SPECIES_DITTO);
    }
}

DOUBLE_BATTLE_TEST("Transform copies a target's Flying type but not its active Roost state")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_ROOST) == EFFECT_ROOST);
        ASSUME(GetMoveType(MOVE_MUD_SHOT) == TYPE_GROUND);
        ASSUME(GetSpeciesType(SPECIES_SWELLOW, 0) == TYPE_NORMAL);
        ASSUME(GetSpeciesType(SPECIES_SWELLOW, 1) == TYPE_FLYING);
        PLAYER(SPECIES_SWELLOW) { Speed(4); HP(1); }
        PLAYER(SPECIES_WOBBUFFET) { Speed(2); }
        OPPONENT(SPECIES_DITTO) { Ability(ABILITY_LIMBER); Speed(3); HP(100); MaxHP(100); }
        OPPONENT(SPECIES_WYNAUT) { Speed(1); }
    } WHEN {
        TURN {
            MOVE(playerLeft, MOVE_ROOST);
            MOVE(opponentLeft, MOVE_TRANSFORM, target: playerLeft);
            MOVE(playerRight, MOVE_MUD_SHOT, target: opponentLeft);
        }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_ROOST, playerLeft);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_TRANSFORM, opponentLeft);
        MESSAGE("The opposing Ditto transformed into Swellow!");
        MESSAGE("It doesn't affect the opposing Ditto…");
    } THEN {
        EXPECT_EQ(opponentLeft->types[0], TYPE_NORMAL);
        EXPECT_EQ(opponentLeft->types[1], TYPE_FLYING);
        EXPECT_EQ(opponentLeft->hp, opponentLeft->maxHP);
    }
}

SINGLE_BATTLE_TEST("Transform copies the target's species, stats, types, Ability, and moves but retains the user's HP")
{
    GIVEN {
        ASSUME(GetSpeciesType(SPECIES_SWELLOW, 0) == TYPE_NORMAL);
        ASSUME(GetSpeciesType(SPECIES_SWELLOW, 1) == TYPE_FLYING);
        PLAYER(SPECIES_DITTO) {
            MaxHP(100); HP(80);
            Attack(10); Defense(20); SpAttack(30); SpDefense(40); Speed(50);
            Ability(ABILITY_LIMBER);
            Moves(MOVE_TRANSFORM);
        }
        OPPONENT(SPECIES_SWELLOW) {
            MaxHP(300); HP(200);
            Attack(110); Defense(120); SpAttack(130); SpDefense(140); Speed(150);
            Ability(ABILITY_GUTS);
            Moves(MOVE_SCRATCH, MOVE_WATER_GUN, MOVE_GROWL, MOVE_CELEBRATE);
        }
    } WHEN {
        TURN { MOVE(player, MOVE_TRANSFORM); }
    } THEN {
        EXPECT_EQ(player->species, SPECIES_SWELLOW);
        EXPECT_EQ(player->attack, 110);
        EXPECT_EQ(player->defense, 120);
        EXPECT_EQ(player->spAttack, 130);
        EXPECT_EQ(player->spDefense, 140);
        EXPECT_EQ(player->speed, 150);
        EXPECT_EQ(player->types[0], TYPE_NORMAL);
        EXPECT_EQ(player->types[1], TYPE_FLYING);
        EXPECT_EQ(player->ability, ABILITY_GUTS);
        EXPECT_EQ(player->moves[0], MOVE_SCRATCH);
        EXPECT_EQ(player->moves[1], MOVE_WATER_GUN);
        EXPECT_EQ(player->moves[2], MOVE_GROWL);
        EXPECT_EQ(player->moves[3], MOVE_CELEBRATE);
        EXPECT_EQ(player->maxHP, 100);
        EXPECT_EQ(player->hp, 80);
    }
}

SINGLE_BATTLE_TEST("Transform copies the target's stat stages")
{
    GIVEN {
        PLAYER(SPECIES_DITTO) { Speed(1); Moves(MOVE_TRANSFORM); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(2); Moves(MOVE_SWORDS_DANCE); }
    } WHEN {
        TURN { MOVE(player, MOVE_TRANSFORM); MOVE(opponent, MOVE_SWORDS_DANCE); }
    } THEN {
        EXPECT_EQ(player->statStages[STAT_ATK], DEFAULT_STAT_STAGE + 2);
    }
}

SINGLE_BATTLE_TEST("Transform gives each copied move 5 PP regardless of the target's remaining PP")
{
    GIVEN {
        ASSUME(GetMovePP(MOVE_SCRATCH) >= 5);
        ASSUME(GetMovePP(MOVE_WATER_GUN) >= 5);
        ASSUME(GetMovePP(MOVE_GROWL) >= 5);
        ASSUME(GetMovePP(MOVE_CELEBRATE) >= 5);
        PLAYER(SPECIES_DITTO) { Moves(MOVE_TRANSFORM); }
        OPPONENT(SPECIES_WOBBUFFET) {
            MovesWithPP({MOVE_SCRATCH, 1}, {MOVE_WATER_GUN, 2}, {MOVE_GROWL, 3}, {MOVE_CELEBRATE, 4});
        }
    } WHEN {
        TURN { MOVE(player, MOVE_TRANSFORM); }
    } THEN {
        EXPECT_EQ(player->pp[0], 5);
        EXPECT_EQ(player->pp[1], 5);
        EXPECT_EQ(player->pp[2], 5);
        EXPECT_EQ(player->pp[3], 5);
    }
}

SINGLE_BATTLE_TEST("Transform fails against a target with an active Illusion")
{
    GIVEN {
        PLAYER(SPECIES_DITTO) { Moves(MOVE_TRANSFORM); }
        OPPONENT(SPECIES_ZOROARK) { Ability(ABILITY_ILLUSION); }
        OPPONENT(SPECIES_WYNAUT);
    } WHEN {
        TURN { MOVE(player, MOVE_TRANSFORM); }
    } SCENE {
        MESSAGE("But it failed!");
    } THEN {
        EXPECT_EQ(player->species, SPECIES_DITTO);
        EXPECT_EQ(gBattleStruct->illusion[B_POSITION_OPPONENT_LEFT].state, ILLUSION_ON);
    }
}

SINGLE_BATTLE_TEST("Transform copies the target's shiny state in Gen4+")
{
    bool32 targetIsShiny;

    PARAMETRIZE { targetIsShiny = FALSE; }
    PARAMETRIZE { targetIsShiny = TRUE; }

    GIVEN {
        WITH_CONFIG(B_TRANSFORM_SHINY, GEN_4);
        PLAYER(SPECIES_DITTO) { Moves(MOVE_TRANSFORM); Shiny(!targetIsShiny); }
        OPPONENT(SPECIES_WOBBUFFET) { Shiny(targetIsShiny); }
    } WHEN {
        TURN { MOVE(player, MOVE_TRANSFORM); }
    } THEN {
        EXPECT(player->volatiles.isTransformedMonShiny == targetIsShiny);
    }
}
