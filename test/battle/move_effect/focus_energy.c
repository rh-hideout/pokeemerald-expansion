#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(GetMoveEffect(MOVE_FOCUS_ENERGY) == EFFECT_FOCUS_ENERGY);
}

SINGLE_BATTLE_TEST("Focus Energy increases the user's critical hit ratio by 1 stage (Gen 1-2) or 2 stages (Gen 3+)")
{
    bool32 useFocusEnergy = 0;
    u32 genConfig = 0, chance = 0;
    for (u32 j = GEN_1; j <= GEN_9; j++) {
        PARAMETRIZE { genConfig = j; useFocusEnergy = FALSE; chance = j >= GEN_7 ? 24 : 16; } // ~4.16%/6.25% with Wobbuffet's base speed
        PARAMETRIZE { genConfig = j; useFocusEnergy = TRUE;
            if (j >= GEN_6)
                chance = 2; // 50% / 25%
            else if (j >= GEN_3)
                chance = 4; // 25%
            else
                chance = 8; // 12.5% with Wobbuffet's base speed
        }
    }
    PASSES_RANDOMLY(1, chance, RNG_CRITICAL_HIT);
    GIVEN {
        WITH_CONFIG(B_CRIT_CHANCE, (genConfig == GEN_1)? GEN_2 : genConfig);
        WITH_CONFIG(B_FOCUS_ENERGY_CRIT_RATIO, genConfig);
        ASSUME(GetSpeciesBaseSpeed(SPECIES_WOBBUFFET) == 33);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        if (useFocusEnergy)
            TURN { MOVE(player, MOVE_FOCUS_ENERGY); }
        TURN { MOVE(player, MOVE_SCRATCH); }
    } SCENE {
        if (useFocusEnergy)
            ANIMATION(ANIM_TYPE_MOVE, MOVE_FOCUS_ENERGY, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, player);
        MESSAGE("A critical hit!");
    }
}

SINGLE_BATTLE_TEST("Focus Energy multiplies crit chance by 4 with gen 1 crit chance")
{
    bool32 useFocusEnergy = 0;
    u32 genConfig = 0, chance = 0;
    for (u32 j = GEN_1; j <= GEN_9; j++) {
        PARAMETRIZE { genConfig = j; useFocusEnergy = FALSE; chance = 16; }
        PARAMETRIZE { genConfig = j; useFocusEnergy = TRUE; chance = 4; }
    }
    PASSES_RANDOMLY(1, chance, RNG_CRITICAL_HIT);
    GIVEN {
        WITH_CONFIG(B_CRIT_CHANCE, GEN_1);
        WITH_CONFIG(B_FOCUS_ENERGY_CRIT_RATIO, genConfig);
        ASSUME(GetSpeciesBaseSpeed(SPECIES_WOBBUFFET) == 33);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        if (useFocusEnergy)
            TURN { MOVE(player, MOVE_FOCUS_ENERGY); }
        TURN { MOVE(player, MOVE_SCRATCH); }
    } SCENE {
        if (useFocusEnergy)
            ANIMATION(ANIM_TYPE_MOVE, MOVE_FOCUS_ENERGY, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, player);
        MESSAGE("A critical hit!");
    }
}

DOUBLE_BATTLE_TEST("Focus Energy fails if critical hit stage was already increased by Dragon Cheer")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Speed(100); }
        PLAYER(SPECIES_WOBBUFFET) { Speed(50); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(25); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(20); }
    } WHEN {
        TURN {
            MOVE(playerLeft, MOVE_DRAGON_CHEER, target: playerRight);
            MOVE(playerRight, MOVE_FOCUS_ENERGY);
        }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_DRAGON_CHEER, playerLeft);
        MESSAGE("Wobbuffet is getting pumped!");
        NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_FOCUS_ENERGY, playerRight);
        MESSAGE("But it failed!");
    } THEN {
        EXPECT_EQ((u32)playerRight->volatiles.criticalHitBoost, CRIT_BOOST_ONE_STAGE);
    }
}

SINGLE_BATTLE_TEST("Baton Pass passes Focus Energy's effect")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_BATON_PASS) == EFFECT_BATON_PASS);
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_FOCUS_ENERGY); }
        TURN { MOVE(player, MOVE_BATON_PASS); SEND_OUT(player, 1); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_FOCUS_ENERGY, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_BATON_PASS, player);
        SEND_IN_MESSAGE("Wynaut");
    } THEN {
        EXPECT_EQ((u32)player->volatiles.criticalHitBoost, CRIT_BOOST_TWO_STAGES);
    }
}
