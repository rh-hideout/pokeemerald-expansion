#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(gItemsInfo[ITEM_SHELL_BELL].holdEffect == HOLD_EFFECT_SHELL_BELL);
}

#define HITS 5
SINGLE_BATTLE_TEST("Shell Bell recovers 1/8 of HP from after the last hit from all hits of a multi hit move")
{
    s16 multiHitDamage[HITS];
    s16 totalDamage = 0;
    s16 shellBellRecovery = 0;

    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { HP(1); Item(ITEM_SHELL_BELL); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_BULLET_SEED); }
    } SCENE {
        for (u32 i = 0; i < HITS; i++) {
            ANIMATION(ANIM_TYPE_MOVE, MOVE_BULLET_SEED, player);
            HP_BAR(opponent, captureDamage: &multiHitDamage[i]);
            totalDamage += multiHitDamage[i];
        }
        HP_BAR(player, captureDamage: &shellBellRecovery);
    } THEN {
        EXPECT_EQ(totalDamage / 8, -1 * shellBellRecovery);
    }
}
#undef HITS

SINGLE_BATTLE_TEST("Shell Bell recovers no HP if the move did no damage")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { HP(1); Item(ITEM_SHELL_BELL); }
        OPPONENT(SPECIES_WOBBUFFET) { HP(1); };
    } WHEN {
        TURN { MOVE(player, MOVE_FALSE_SWIPE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_FALSE_SWIPE, player);
        HP_BAR(opponent);
        NONE_OF {
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_EFFECT, player);
            HP_BAR(player);
        }
    }
}

SINGLE_BATTLE_TEST("Shell Bell activates if it hits a Substitute")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { HP(1); Item(ITEM_SHELL_BELL); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_SUBSTITUTE); MOVE(player, MOVE_TACKLE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SUBSTITUTE, opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_TACKLE, player);
        // HP_BAR(opponent); // When you hit a sub the hp bar check doesn't work. Not sure if this is a bug
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_EFFECT, player);
        HP_BAR(player);
    }
}

SINGLE_BATTLE_TEST("Shell Bell activates after Absorb")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { HP(1); Item(ITEM_SHELL_BELL); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_ABSORB); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_ABSORB, player);
        HP_BAR(opponent);
        HP_BAR(player);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_EFFECT, player);
        HP_BAR(player);
    }
}

SINGLE_BATTLE_TEST("Shell Bell activates after Rough Skin")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Item(ITEM_SHELL_BELL); }
        OPPONENT(SPECIES_GIBLE) { Ability(ABILITY_ROUGH_SKIN); }
    } WHEN {
        TURN { MOVE(player, MOVE_TACKLE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_TACKLE, player);
        HP_BAR(opponent);
        HP_BAR(player);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_EFFECT, player);
        HP_BAR(player);
    }
}

SINGLE_BATTLE_TEST("Shell Bell does not activate on Future Sight if the original user is on the field")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { HP(1); Item(ITEM_SHELL_BELL); }
        OPPONENT(SPECIES_WYNAUT);
    } WHEN {
        TURN { MOVE(player, MOVE_FUTURE_SIGHT); }
        TURN {}
        TURN {}
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_FUTURE_SIGHT, player);
        MESSAGE("The opposing Wynaut took the Future Sight attack!");
        HP_BAR(opponent);
        NONE_OF {
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_EFFECT, player);
            HP_BAR(player);
        }
    }
}

SINGLE_BATTLE_TEST("Shell Bell does not activate on Future Sight if the original user is not on the field")
{
    GIVEN {
        PLAYER(SPECIES_WYNAUT);
        PLAYER(SPECIES_WOBBUFFET) { HP(1); Item(ITEM_SHELL_BELL); }
        OPPONENT(SPECIES_WYNAUT);
    } WHEN {
        TURN { MOVE(player, MOVE_FUTURE_SIGHT); }
        TURN { SWITCH(player, 1); }
        TURN {}
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_FUTURE_SIGHT, player);
        MESSAGE("The opposing Wynaut took the Future Sight attack!");
        HP_BAR(opponent);
        NONE_OF {
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_EFFECT, player);
            HP_BAR(player);
        }
    }
}

TO_DO_BATTLE_TEST("If a Pokémon steals a Shell Bell with Thief or Covet, it will recover HP for the use of that move that stole the Shell Bell")
TO_DO_BATTLE_TEST("If a Pokémon steals a Shell Bell with Magician, it will recover HP for the use of that move that stole the Shell Bell")
