#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(GetItemHoldEffect(ITEM_BLACK_SLUDGE) == HOLD_EFFECT_BLACK_SLUDGE);
}

SINGLE_BATTLE_TEST("Black Sludge recovers 1/16 HP for Poison-type holders")
{
    GIVEN {
        ASSUME(GetSpeciesType(SPECIES_EKANS, 0) == TYPE_POISON);
        PLAYER(SPECIES_EKANS) { MaxHP(160); HP(1); Item(ITEM_BLACK_SLUDGE); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN {}
    } SCENE {
        ITEM_POPUP(player, ITEM_BLACK_SLUDGE);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_EFFECT, player);
        HP_BAR(player, damage: -10);
    }
}

SINGLE_BATTLE_TEST("Black Sludge deals 1/8 max HP to non-Poison-type holders")
{
    GIVEN {
        ASSUME(GetSpeciesType(SPECIES_WOBBUFFET, 0) != TYPE_POISON);
        ASSUME(GetSpeciesType(SPECIES_WOBBUFFET, 1) != TYPE_POISON);
        PLAYER(SPECIES_WOBBUFFET) { MaxHP(160); HP(160); Item(ITEM_BLACK_SLUDGE); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN {}
    } SCENE {
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_MON_HIT, player);
        HP_BAR(player, damage: 20);
    }
}

SINGLE_BATTLE_TEST("Black Sludge does nothing if a Poison-type holder is at full HP")
{
    GIVEN {
        ASSUME(GetSpeciesType(SPECIES_EKANS, 0) == TYPE_POISON);
        PLAYER(SPECIES_EKANS) { Item(ITEM_BLACK_SLUDGE); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN {}
    } SCENE {
        NONE_OF {
            ITEM_POPUP(player, ITEM_BLACK_SLUDGE);
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_EFFECT, player);
            HP_BAR(player);
        }
    }
}

SINGLE_BATTLE_TEST("Black Sludge does not heal a Poison-type holder under Heal Block (Gen 5+)")
{
    u32 genConfig;

    PARAMETRIZE { genConfig = GEN_4; }
    PARAMETRIZE { genConfig = GEN_5; }

    GIVEN {
        WITH_CONFIG(B_HEAL_BLOCKING, genConfig);
        ASSUME(GetSpeciesType(SPECIES_EKANS, 0) == TYPE_POISON);
        ASSUME(GetMoveEffect(MOVE_HEAL_BLOCK) == EFFECT_HEAL_BLOCK);
        PLAYER(SPECIES_EKANS) { MaxHP(160); HP(1); Item(ITEM_BLACK_SLUDGE); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_HEAL_BLOCK); }
    } SCENE {
        if (genConfig >= GEN_5) {
            NONE_OF {
                ITEM_POPUP(player, ITEM_BLACK_SLUDGE);
                ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_EFFECT, player);
                HP_BAR(player);
            }
        } else {
            ITEM_POPUP(player, ITEM_BLACK_SLUDGE);
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_EFFECT, player);
            HP_BAR(player, damage: -10);
        }
    }
}

SINGLE_BATTLE_TEST("Black Sludge does not damage a non-Poison-type holder with Magic Guard")
{
    GIVEN {
        ASSUME(GetSpeciesType(SPECIES_CLEFABLE, 0) != TYPE_POISON);
        PLAYER(SPECIES_CLEFABLE) { Ability(ABILITY_MAGIC_GUARD); MaxHP(160); HP(160); Item(ITEM_BLACK_SLUDGE); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN {}
    } SCENE {
        NONE_OF {
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_MON_HIT, player);
            HP_BAR(player);
        }
    }
}

SINGLE_BATTLE_TEST("Black Sludge has no effect if the holder has Klutz")
{
    GIVEN {
        ASSUME(GetSpeciesType(SPECIES_EKANS, 0) == TYPE_POISON);
        PLAYER(SPECIES_EKANS) { Ability(ABILITY_KLUTZ); MaxHP(160); HP(1); Item(ITEM_BLACK_SLUDGE); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN {}
    } SCENE {
        NONE_OF {
            ITEM_POPUP(player, ITEM_BLACK_SLUDGE);
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_EFFECT, player);
            HP_BAR(player);
        }
    }
}

SINGLE_BATTLE_TEST("Black Sludge has no effect while Magic Room is active")
{
    GIVEN {
        ASSUME(GetSpeciesType(SPECIES_EKANS, 0) == TYPE_POISON);
        ASSUME(GetMoveEffect(MOVE_MAGIC_ROOM) == EFFECT_MAGIC_ROOM);
        PLAYER(SPECIES_EKANS) { MaxHP(160); HP(1); Item(ITEM_BLACK_SLUDGE); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_MAGIC_ROOM); }
    } SCENE {
        NONE_OF {
            ITEM_POPUP(player, ITEM_BLACK_SLUDGE);
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_EFFECT, player);
            HP_BAR(player);
        }
    }
}

SINGLE_BATTLE_TEST("Black Sludge deals 1/8 max HP after its holder loses the Poison type")
{
    GIVEN {
        ASSUME(GetSpeciesType(SPECIES_EKANS, 0) == TYPE_POISON);
        ASSUME(GetMoveEffect(MOVE_SONIC_BOOM) == EFFECT_FIXED_HP_DAMAGE);
        ASSUME(GetMoveFixedHPDamage(MOVE_SONIC_BOOM) == 20);
        ASSUME(GetMoveEffect(MOVE_SOAK) == EFFECT_SOAK);
        PLAYER(SPECIES_EKANS) { MaxHP(160); HP(160); Item(ITEM_BLACK_SLUDGE); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_SONIC_BOOM); }
        TURN { MOVE(opponent, MOVE_SOAK); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SONIC_BOOM, opponent);
        HP_BAR(player, damage: 20);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_EFFECT, player);
        HP_BAR(player, damage: -10);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SOAK, opponent);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_MON_HIT, player);
        HP_BAR(player, damage: 20);
    } THEN {
        EXPECT_EQ(player->hp, 130);
    }
}
