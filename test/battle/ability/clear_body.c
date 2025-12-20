#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Clear Body, Full Metal Body, and White Smoke prevent intimidate")
{
    s16 turnOneHit;
    s16 turnTwoHit;
    enum Ability ability;

    PARAMETRIZE{ ability = ABILITY_CLEAR_BODY; }
    PARAMETRIZE{ ability = ABILITY_FULL_METAL_BODY; }
    PARAMETRIZE{ ability = ABILITY_WHITE_SMOKE; }
    GIVEN {
        PLAYER(TEST_SPECIES_WOBBUFFET) { Ability(ABILITY_SHED_SKIN); };
        PLAYER(TEST_SPECIES_WOBBUFFET) { Ability(ABILITY_INTIMIDATE); };
        OPPONENT(TEST_SPECIES_WOBBUFFET) { Ability(ability); };
    } WHEN {
        TURN { MOVE(opponent, MOVE_SCRATCH); }
        TURN { SWITCH(player, 1); MOVE(opponent, MOVE_SCRATCH); }

    } SCENE {
        HP_BAR(player, captureDamage: &turnOneHit);
        ABILITY_POPUP(player, ABILITY_INTIMIDATE);
        NONE_OF {
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponent);
        }
        ABILITY_POPUP(opponent, ability);
        if (ability == ABILITY_FULL_METAL_BODY)
            MESSAGE("The opposing Wobbuffet's Full Metal Body prevents stat loss!");
        else if (ability == ABILITY_WHITE_SMOKE)
            MESSAGE("The opposing Wobbuffet's White Smoke prevents stat loss!");
        else
            MESSAGE("The opposing Wobbuffet's Clear Body prevents stat loss!");
        HP_BAR(player, captureDamage: &turnTwoHit);
    } THEN {
        EXPECT_EQ(turnOneHit, turnTwoHit);
    }
}

SINGLE_BATTLE_TEST("Clear Body, Full Metal Body, and White Smoke prevent stat stage reduction from moves")
{
    u16 move = MOVE_NONE;
    u32 j;
    enum Ability ability = ABILITY_NONE;
    static const u16 statReductionMoves[] = {
        MOVE_GROWL,
        MOVE_LEER,
        MOVE_CONFIDE,
        MOVE_FAKE_TEARS,
        MOVE_SCARY_FACE,
        MOVE_SWEET_SCENT,
        MOVE_SAND_ATTACK,
    };
    for (j = 0; j < ARRAY_COUNT(statReductionMoves); j++)
        {
            PARAMETRIZE{ ability = ABILITY_CLEAR_BODY; move = statReductionMoves[j]; }
            PARAMETRIZE{ ability = ABILITY_FULL_METAL_BODY; move = statReductionMoves[j]; }
            PARAMETRIZE{ ability = ABILITY_WHITE_SMOKE; move = statReductionMoves[j]; }
        }

    GIVEN {
        ASSUME(GetMoveEffect(MOVE_GROWL) == EFFECT_ATTACK_DOWN);
        ASSUME(GetMoveEffect(MOVE_LEER) == EFFECT_DEFENSE_DOWN);
        ASSUME(GetMoveEffect(MOVE_CONFIDE) == EFFECT_SPECIAL_ATTACK_DOWN);
        ASSUME(GetMoveEffect(MOVE_FAKE_TEARS) == EFFECT_SPECIAL_DEFENSE_DOWN_2);
        ASSUME(GetMoveEffect(MOVE_SCARY_FACE) == EFFECT_SPEED_DOWN_2);
        ASSUME(GetMoveEffect(MOVE_SWEET_SCENT) == (B_UPDATED_MOVE_DATA >= GEN_6 ? EFFECT_EVASION_DOWN_2 : EFFECT_EVASION_DOWN));
        ASSUME(GetMoveEffect(MOVE_SAND_ATTACK) == EFFECT_ACCURACY_DOWN);
        PLAYER(TEST_SPECIES_WOBBUFFET)
        OPPONENT(TEST_SPECIES_WOBBUFFET) { Ability(ability); }
    } WHEN {
        TURN { MOVE(player, move); }
    } SCENE {
        NONE_OF {
            ANIMATION(ANIM_TYPE_MOVE, move, player);
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponent);
        }
        ABILITY_POPUP(opponent, ability);
        if (ability == ABILITY_FULL_METAL_BODY)
            MESSAGE("The opposing Wobbuffet's Full Metal Body prevents stat loss!");
        else if (ability == ABILITY_WHITE_SMOKE)
            MESSAGE("The opposing Wobbuffet's White Smoke prevents stat loss!");
        else
            MESSAGE("The opposing Wobbuffet's Clear Body prevents stat loss!");
    }
}

SINGLE_BATTLE_TEST("Clear Body, Full Metal Body, and White Smoke prevent Sticky Web effect on switchin")
{
    enum Ability ability;
    PARAMETRIZE{ ability = ABILITY_CLEAR_BODY; }
    PARAMETRIZE{ ability = ABILITY_FULL_METAL_BODY; }
    PARAMETRIZE{ ability = ABILITY_WHITE_SMOKE; }
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_STICKY_WEB) == EFFECT_STICKY_WEB);
        PLAYER(TEST_SPECIES_WOBBUFFET)
        OPPONENT(TEST_SPECIES_WOBBUFFET)
        OPPONENT(TEST_SPECIES_WOBBUFFET) { Ability(ability); }
    } WHEN {
        TURN { MOVE(player, MOVE_STICKY_WEB); }
        TURN { SWITCH(opponent, 1); }
    } SCENE {
        NONE_OF {
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponent);
        }
        ABILITY_POPUP(opponent, ability);
        if (ability == ABILITY_FULL_METAL_BODY)
            MESSAGE("The opposing Wobbuffet's Full Metal Body prevents stat loss!");
        else if (ability == ABILITY_WHITE_SMOKE)
            MESSAGE("The opposing Wobbuffet's White Smoke prevents stat loss!");
        else
            MESSAGE("The opposing Wobbuffet's Clear Body prevents stat loss!");
    }
}

SINGLE_BATTLE_TEST("Clear Body, Full Metal Body, and White Smoke don't prevent stat stage reduction from moves used by the user")
{
    enum Ability ability;
    PARAMETRIZE{ ability = ABILITY_CLEAR_BODY; }
    PARAMETRIZE{ ability = ABILITY_FULL_METAL_BODY; }
    PARAMETRIZE{ ability = ABILITY_WHITE_SMOKE; }
    GIVEN {
        ASSUME(MoveHasAdditionalEffectSelf(MOVE_SUPERPOWER, MOVE_EFFECT_ATK_DEF_DOWN) == TRUE);
        PLAYER(TEST_SPECIES_WOBBUFFET)
        OPPONENT(TEST_SPECIES_WOBBUFFET) { Ability(ability); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_SUPERPOWER); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SUPERPOWER, opponent);
        NONE_OF {
            ABILITY_POPUP(opponent, ability);
            MESSAGE("The opposing Wobbuffet's Full Metal Body prevents stat loss!");
            MESSAGE("The opposing Wobbuffet's White Smoke prevents stat loss!");
            MESSAGE("The opposing Wobbuffet's Clear Body prevents stat loss!");
        }
    }
}

SINGLE_BATTLE_TEST("Mold Breaker, Teravolt, and Turboblaze ignore Clear Body and White Smoke, but not Full Metal Body")
{
    u32 j, k = SPECIES_NONE;
    enum Ability ability = ABILITY_NONE;
    enum Ability breakerAbility = ABILITY_NONE;
    u16 move = ABILITY_NONE;
    static const u16 breakerAbilities[] = {
        ABILITY_MOLD_BREAKER,
        ABILITY_TERAVOLT,
        ABILITY_TURBOBLAZE,
    };
    static const u16 statReductionMoves[] = {
        MOVE_GROWL,
        MOVE_LEER,
        MOVE_CONFIDE,
        MOVE_FAKE_TEARS,
        MOVE_SCARY_FACE,
        MOVE_SWEET_SCENT,
        MOVE_SAND_ATTACK,
    };

    for (j = 0; j < ARRAY_COUNT(statReductionMoves); j++)
    {
        for (k = 0; k < ARRAY_COUNT(breakerAbilities); k++)
        {
            PARAMETRIZE{ ability = ABILITY_CLEAR_BODY; move = statReductionMoves[j]; breakerAbility = breakerAbilities[k]; }
            PARAMETRIZE{ ability = ABILITY_FULL_METAL_BODY; move = statReductionMoves[j]; breakerAbility = breakerAbilities[k]; }
            PARAMETRIZE{ ability = ABILITY_WHITE_SMOKE; move = statReductionMoves[j]; breakerAbility = breakerAbilities[k]; }
        }
    }

    GIVEN {
        ASSUME(GetMoveEffect(MOVE_GROWL) == EFFECT_ATTACK_DOWN);
        ASSUME(GetMoveEffect(MOVE_LEER) == EFFECT_DEFENSE_DOWN);
        ASSUME(GetMoveEffect(MOVE_CONFIDE) == EFFECT_SPECIAL_ATTACK_DOWN);
        ASSUME(GetMoveEffect(MOVE_FAKE_TEARS) == EFFECT_SPECIAL_DEFENSE_DOWN_2);
        ASSUME(GetMoveEffect(MOVE_SCARY_FACE) == EFFECT_SPEED_DOWN_2);
        ASSUME(GetMoveEffect(MOVE_SWEET_SCENT) == (B_UPDATED_MOVE_DATA >= GEN_6 ? EFFECT_EVASION_DOWN_2 : EFFECT_EVASION_DOWN));
        ASSUME(GetMoveEffect(MOVE_SAND_ATTACK) == EFFECT_ACCURACY_DOWN);
        PLAYER(TEST_SPECIES_WOBBUFFET) { Ability(breakerAbility); }
        OPPONENT(TEST_SPECIES_WOBBUFFET) { Ability(ability); }
    } WHEN {
        TURN { MOVE(player, move); }
    } SCENE {
        if (ability == ABILITY_FULL_METAL_BODY){ // Full Metal Body can't be ignored by breaker abilities
            NOT ANIMATION(ANIM_TYPE_MOVE, move, player);
            ABILITY_POPUP(opponent, ability);
            MESSAGE("The opposing Wobbuffet's Full Metal Body prevents stat loss!");
        }
        else{
            ANIMATION(ANIM_TYPE_MOVE, move, player);
            NONE_OF {
                ABILITY_POPUP(opponent, ability);
                MESSAGE("The opposing Wobbuffet's Full Metal Body prevents stat loss!");
                MESSAGE("The opposing Wobbuffet's White Smoke prevents stat loss!");
                MESSAGE("The opposing Wobbuffet's Clear Body prevents stat loss!");
            }
        }
    }
}

SINGLE_BATTLE_TEST("Clear Body, Full Metal Body, and White Smoke don't prevent Speed reduction from Iron Ball")
{
    u32 j;
    enum Ability ability = ABILITY_NONE;
    u16 heldItem = ITEM_NONE;
    static const u16 heldItems[] = {
        ITEM_NONE,
        ITEM_IRON_BALL,
    };
    for (j = 0; j < ARRAY_COUNT(heldItems); j++)
    {
        PARAMETRIZE{ ability = ABILITY_CLEAR_BODY; heldItem = heldItems[j]; }
        PARAMETRIZE{ ability = ABILITY_FULL_METAL_BODY; heldItem = heldItems[j]; }
        PARAMETRIZE{ ability = ABILITY_WHITE_SMOKE; heldItem = heldItems[j]; }
    }
    GIVEN {
        ASSUME(gItemsInfo[ITEM_IRON_BALL].holdEffect == HOLD_EFFECT_IRON_BALL);
        PLAYER(TEST_SPECIES_WOBBUFFET) { Speed(4); }
        OPPONENT(TEST_SPECIES_WOBBUFFET) { Speed(6); Ability(ability); Item(heldItem); }
    } WHEN {
        TURN { }
    } SCENE {
        NOT ABILITY_POPUP(opponent, ability);
        if (heldItem == ITEM_IRON_BALL) {
            MESSAGE("Wobbuffet used Celebrate!");
            MESSAGE("The opposing Wobbuffet used Celebrate!");
        } else {
            MESSAGE("The opposing Wobbuffet used Celebrate!");
            MESSAGE("Wobbuffet used Celebrate!");
        }
    }
}

SINGLE_BATTLE_TEST("Clear Body, Full Metal Body, and White Smoke don't prevent Speed reduction from paralysis")
{
    enum Ability ability;

    PARAMETRIZE{ ability = ABILITY_CLEAR_BODY; }
    PARAMETRIZE{ ability = ABILITY_FULL_METAL_BODY; }
    PARAMETRIZE{ ability = ABILITY_WHITE_SMOKE; }

    GIVEN {
        PLAYER(TEST_SPECIES_WOBBUFFET) { Speed(4); }
        OPPONENT(TEST_SPECIES_WOBBUFFET) { Speed(6); Ability(ability); }
    } WHEN {
        TURN { MOVE(player, MOVE_THUNDER_WAVE); }
        TURN { MOVE(player, MOVE_THUNDER_WAVE); }
    } SCENE {
        MESSAGE("The opposing Wobbuffet used Celebrate!");
        MESSAGE("Wobbuffet used Thunder Wave!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_THUNDER_WAVE, player);
        NOT ABILITY_POPUP(opponent, ability);
        MESSAGE("Wobbuffet used Thunder Wave!");
        ONE_OF {
            MESSAGE("The opposing Wobbuffet used Celebrate!");
            MESSAGE("The opposing Wobbuffet couldn't move because it's paralyzed!");
        }
    }
}

SINGLE_BATTLE_TEST("Clear Body, Full Metal Body, and White Smoke don't prevent Attack reduction from burn", s16 damage)
{
    bool32 burned = FALSE;
    enum Ability ability;
    PARAMETRIZE{ ability = ABILITY_CLEAR_BODY; burned = FALSE; }
    PARAMETRIZE{ ability = ABILITY_CLEAR_BODY; burned = TRUE; }
    PARAMETRIZE{ ability = ABILITY_FULL_METAL_BODY; burned = FALSE; }
    PARAMETRIZE{ ability = ABILITY_FULL_METAL_BODY; burned = TRUE; }
    PARAMETRIZE{ ability = ABILITY_WHITE_SMOKE; burned = FALSE; }
    PARAMETRIZE{ ability = ABILITY_WHITE_SMOKE; burned = TRUE; }
    GIVEN {
        ASSUME(GetMoveCategory(MOVE_SCRATCH) == DAMAGE_CATEGORY_PHYSICAL);
        PLAYER(TEST_SPECIES_WOBBUFFET)
        OPPONENT(TEST_SPECIES_WOBBUFFET) { Ability(ability); if (burned) Status1(STATUS1_BURN); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_SCRATCH); }
    } SCENE {
        NOT ABILITY_POPUP(opponent, ability);
        HP_BAR(player, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_MUL_EQ(results[0].damage, Q_4_12(0.5), results[1].damage);
    }
}

SINGLE_BATTLE_TEST("Clear Body, Full Metal Body, and White Smoke don't prevent receiving negative stat changes from Baton Pass")
{
    enum Ability ability;

    PARAMETRIZE{ ability = ABILITY_CLEAR_BODY; }
    PARAMETRIZE{ ability = ABILITY_FULL_METAL_BODY; }
    PARAMETRIZE{ ability = ABILITY_WHITE_SMOKE; }

    GIVEN {
        ASSUME(GetMoveEffect(MOVE_SCARY_FACE) == EFFECT_SPEED_DOWN_2);
        ASSUME(GetMoveEffect(MOVE_BATON_PASS) == EFFECT_BATON_PASS);
        PLAYER(TEST_SPECIES_WOBBUFFET) { Speed(4); }
        OPPONENT(TEST_SPECIES_WOBBUFFET) { Speed(3); }
        OPPONENT(TEST_SPECIES_WOBBUFFET) { Speed(6); Ability(ability); }
    } WHEN {
        TURN { MOVE(player, MOVE_SCARY_FACE); MOVE(opponent, MOVE_BATON_PASS); SEND_OUT(opponent, 1); }
        TURN { MOVE(player, MOVE_SCARY_FACE); }
    } SCENE {
        MESSAGE("Wobbuffet used Scary Face!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCARY_FACE, player);
        ABILITY_POPUP(opponent, ability);
        MESSAGE("The opposing Wobbuffet used Celebrate!");
    }
}

SINGLE_BATTLE_TEST("Clear Body, Full Metal Body, and White Smoke don't prevent Topsy-Turvy")
{
    enum Ability ability;

    PARAMETRIZE{ ability = ABILITY_CLEAR_BODY; }
    PARAMETRIZE{ ability = ABILITY_FULL_METAL_BODY; }
    PARAMETRIZE{ ability = ABILITY_WHITE_SMOKE; }

    GIVEN {
        ASSUME(GetMoveEffect(MOVE_TOPSY_TURVY) == EFFECT_TOPSY_TURVY);
        ASSUME(GetMoveEffect(MOVE_SCARY_FACE) == EFFECT_SPEED_DOWN_2);
        ASSUME(GetMoveEffect(MOVE_BATON_PASS) == EFFECT_BATON_PASS);
        PLAYER(TEST_SPECIES_WOBBUFFET) { Speed(4); }
        OPPONENT(TEST_SPECIES_WOBBUFFET) { Speed(3); }
        OPPONENT(TEST_SPECIES_WOBBUFFET) { Speed(6); Ability(ability); }
    } WHEN {
        TURN { MOVE(player, MOVE_SCARY_FACE); MOVE(opponent, MOVE_BATON_PASS); SEND_OUT(opponent, 1); }
        TURN { MOVE(player, MOVE_TOPSY_TURVY); }
        TURN { MOVE(player, MOVE_SCARY_FACE); }
    } SCENE {
        MESSAGE("Wobbuffet used Topsy-Turvy!");
        NOT ABILITY_POPUP(opponent, ability);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_TOPSY_TURVY, player);
        MESSAGE("The opposing Wobbuffet used Celebrate!");
        MESSAGE("The opposing Wobbuffet used Celebrate!");
        MESSAGE("Wobbuffet used Scary Face!");
        NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_SCARY_FACE, player);
        ABILITY_POPUP(opponent, ability);
    }
}

SINGLE_BATTLE_TEST("Clear Body, Full Metal Body, and White Smoke don't prevent Spectral Thief from resetting positive stat changes")
{
    enum Ability ability;

    PARAMETRIZE{ ability = ABILITY_CLEAR_BODY; }
    PARAMETRIZE{ ability = ABILITY_FULL_METAL_BODY; }
    PARAMETRIZE{ ability = ABILITY_WHITE_SMOKE; }

    GIVEN {
        ASSUME(GetMoveEffect(MOVE_SPECTRAL_THIEF) == EFFECT_SPECTRAL_THIEF);
        ASSUME(GetMoveEffect(MOVE_AGILITY) == EFFECT_SPEED_UP_2);
        PLAYER(TEST_SPECIES_WOBBUFFET) { Speed(4); }
        OPPONENT(TEST_SPECIES_WOBBUFFET) { Speed(5); Ability(ability); }
    } WHEN {
        TURN{ MOVE(opponent, MOVE_AGILITY); }
        TURN{ MOVE(player, MOVE_SPECTRAL_THIEF); }
        TURN{ }
    } SCENE {
        MESSAGE("The opposing Wobbuffet used Agility!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_AGILITY, opponent);
        MESSAGE("Wobbuffet used Celebrate!");
        MESSAGE("The opposing Wobbuffet used Celebrate!");
        MESSAGE("Wobbuffet used Spectral Thief!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SPECTRAL_THIEF, player);
        NOT ABILITY_POPUP(opponent, ability);
        MESSAGE("Wobbuffet used Celebrate!");
        MESSAGE("The opposing Wobbuffet used Celebrate!");
    }
}

SINGLE_BATTLE_TEST("Clear Body, Full Metal Body, and White Smoke protect from Protect's secondary effects")
{
    u32 move = MOVE_NONE;
    enum Ability ability = ABILITY_NONE;

    static const u32 moves[] = {
        MOVE_SPIKY_SHIELD,
        MOVE_KINGS_SHIELD,
        MOVE_SILK_TRAP,
        MOVE_OBSTRUCT,
    };

    for (u32 j = 0; j < ARRAY_COUNT(moves); j++)
    {
        PARAMETRIZE{ move = moves[j]; ability = ABILITY_CLEAR_BODY; }
        PARAMETRIZE{ move = moves[j]; ability = ABILITY_FULL_METAL_BODY; }
        PARAMETRIZE{ move = moves[j]; ability = ABILITY_WHITE_SMOKE; }
    }

    GIVEN {
        PLAYER(TEST_SPECIES_WOBBUFFET) { Ability(ability); }
        OPPONENT(TEST_SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, move); MOVE(player, MOVE_SCRATCH); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, move, opponent);
        NONE_OF {
            ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, player);
            if (move == MOVE_KINGS_SHIELD) {
                MESSAGE("Wobbuffet's Attack fell!");
            } else if (move == MOVE_SILK_TRAP) {
                MESSAGE("Wobbuffet's Speed fell!");
            } else if (move == MOVE_OBSTRUCT) {
                MESSAGE("Wobbuffet's Defense harshly fell!");
            }
        }
    }
}
