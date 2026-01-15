#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(GetMoveEffect(MOVE_PARTING_SHOT) == EFFECT_PARTING_SHOT);
}

SINGLE_BATTLE_TEST("Parting Shot: Protect blocks it and prevents switching")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Moves(MOVE_PARTING_SHOT, MOVE_CELEBRATE); }
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_WOBBUFFET) { Moves(MOVE_PROTECT, MOVE_CELEBRATE); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_PROTECT); MOVE(player, MOVE_PARTING_SHOT); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_PROTECT, opponent);
        MESSAGE("The opposing Wobbuffet protected itself!");
        NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_PARTING_SHOT, player);
    } THEN {
        EXPECT_EQ(opponent->statStages[STAT_ATK], DEFAULT_STAT_STAGE);
        EXPECT_EQ(opponent->statStages[STAT_SPATK], DEFAULT_STAT_STAGE);
        EXPECT_EQ(player->species, SPECIES_WOBBUFFET);
    }
}

SINGLE_BATTLE_TEST("Parting Shot: Passes Substitute and switches the user out")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Moves(MOVE_PARTING_SHOT, MOVE_CELEBRATE); }
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_WOBBUFFET) { Moves(MOVE_SUBSTITUTE, MOVE_CELEBRATE); }
    } WHEN {
        TURN { MOVE(player, MOVE_CELEBRATE); MOVE(opponent, MOVE_SUBSTITUTE); }
        TURN { MOVE(player, MOVE_PARTING_SHOT); MOVE(opponent, MOVE_CELEBRATE); SEND_OUT(player, 1); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_PARTING_SHOT, player);
        SEND_IN_MESSAGE("Wynaut");
    } THEN {
        EXPECT_EQ(opponent->statStages[STAT_ATK], DEFAULT_STAT_STAGE - 1);
        EXPECT_EQ(opponent->statStages[STAT_SPATK], DEFAULT_STAT_STAGE - 1);
        EXPECT_EQ(player->species, SPECIES_WYNAUT);
    }
}

SINGLE_BATTLE_TEST("Parting Shot: Throat Chop prevents using Parting Shot")
{
    GIVEN {
        ASSUME(IsSoundMove(MOVE_PARTING_SHOT));
        ASSUME(MoveHasAdditionalEffect(MOVE_THROAT_CHOP, MOVE_EFFECT_THROAT_CHOP) == TRUE);
        PLAYER(SPECIES_WOBBUFFET) { Speed(50); Moves(MOVE_PARTING_SHOT, MOVE_CELEBRATE); }
        PLAYER(SPECIES_WYNAUT) { Speed(10); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(100); Moves(MOVE_THROAT_CHOP, MOVE_CELEBRATE); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_THROAT_CHOP); MOVE(player, MOVE_PARTING_SHOT); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_THROAT_CHOP, opponent);
        MESSAGE("The effects of Throat Chop prevent Wobbuffet from using certain moves!");
        NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_PARTING_SHOT, player);
    } THEN {
        EXPECT_EQ(opponent->statStages[STAT_ATK], DEFAULT_STAT_STAGE);
        EXPECT_EQ(opponent->statStages[STAT_SPATK], DEFAULT_STAT_STAGE);
        EXPECT_EQ(player->species, SPECIES_WOBBUFFET);
    }
}

SINGLE_BATTLE_TEST("Parting Shot: Liquid Voice turns it into a Water-type move, so Water-immune abilities block it")
{
    u16 species, ability;

    PARAMETRIZE { species = SPECIES_VAPOREON;  ability = ABILITY_WATER_ABSORB; }
    PARAMETRIZE { species = SPECIES_TOXICROAK; ability = ABILITY_DRY_SKIN; }

    GIVEN {
        ASSUME(IsSoundMove(MOVE_PARTING_SHOT));
        PLAYER(SPECIES_PRIMARINA) { Ability(ABILITY_LIQUID_VOICE); Moves(MOVE_PARTING_SHOT); }
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(species) { Ability(ability); Moves(MOVE_CELEBRATE); }
    } WHEN {
        TURN { MOVE(player, MOVE_PARTING_SHOT); MOVE(opponent, MOVE_CELEBRATE); }
    } SCENE {
        ABILITY_POPUP(opponent, ability);
        if (species == SPECIES_VAPOREON)
            MESSAGE("The opposing Vaporeon's Water Absorb made Parting Shot useless!");
        else
            MESSAGE("The opposing Toxicroak's Dry Skin made Parting Shot useless!");
        NONE_OF {
            ANIMATION(ANIM_TYPE_MOVE, MOVE_PARTING_SHOT, player);
            HP_BAR(opponent);
        }
    } THEN {
        EXPECT_EQ(opponent->statStages[STAT_ATK], DEFAULT_STAT_STAGE);
        EXPECT_EQ(opponent->statStages[STAT_SPATK], DEFAULT_STAT_STAGE);
        EXPECT_EQ(player->species, SPECIES_PRIMARINA);
    }
}

SINGLE_BATTLE_TEST("Parting Shot: Electrify into Electric immunity prevents switching")
{
    u16 species, ability;

    PARAMETRIZE { species = SPECIES_SEAKING;    ability = ABILITY_LIGHTNING_ROD; }
    PARAMETRIZE { species = SPECIES_JOLTEON;    ability = ABILITY_VOLT_ABSORB; }
    PARAMETRIZE { species = SPECIES_ELECTIVIRE; ability = ABILITY_MOTOR_DRIVE; }

    GIVEN {
        ASSUME(GetMoveEffect(MOVE_ELECTRIFY) == EFFECT_ELECTRIFY);
        PLAYER(SPECIES_WOBBUFFET) { Moves(MOVE_PARTING_SHOT); Speed(33); }
        PLAYER(SPECIES_WYNAUT) { Speed(22); }
        OPPONENT(species) { Ability(ability); Speed(66); Moves(MOVE_ELECTRIFY, MOVE_CELEBRATE); HP(50); MaxHP(100); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_ELECTRIFY, target: player); MOVE(player, MOVE_PARTING_SHOT); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_ELECTRIFY, opponent);
        ABILITY_POPUP(opponent, ability);
        NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_PARTING_SHOT, player);
        if (ability == ABILITY_LIGHTNING_ROD) {
            MESSAGE("The opposing Seaking's Sp. Atk rose!");
        } else if (ability == ABILITY_MOTOR_DRIVE) {
            MESSAGE("The opposing Electivire's Speed rose!");
        } else {
            HP_BAR(opponent, damage: -25);
        }
    } THEN {
        EXPECT_EQ(opponent->statStages[STAT_ATK], DEFAULT_STAT_STAGE);
        if (ability == ABILITY_LIGHTNING_ROD)
            EXPECT_EQ(opponent->statStages[STAT_SPATK], DEFAULT_STAT_STAGE + 1);
        else
            EXPECT_EQ(opponent->statStages[STAT_SPATK], DEFAULT_STAT_STAGE);
        if (ability == ABILITY_MOTOR_DRIVE)
            EXPECT_EQ(opponent->statStages[STAT_SPEED], DEFAULT_STAT_STAGE + 1);
        else
            EXPECT_EQ(opponent->statStages[STAT_SPEED], DEFAULT_STAT_STAGE);
        EXPECT_EQ(player->species, SPECIES_WOBBUFFET);
    }
}

SINGLE_BATTLE_TEST("Parting Shot: Prankster priority blocking or Dark-type immunity prevents switching")
{
    u16 species, ability;
    bool8 isDarkType;

    PARAMETRIZE { species = SPECIES_TSAREENA;  ability = ABILITY_QUEENLY_MAJESTY; isDarkType = FALSE; }
    PARAMETRIZE { species = SPECIES_BRUXISH;   ability = ABILITY_DAZZLING;        isDarkType = FALSE; }
    PARAMETRIZE { species = SPECIES_FARIGIRAF; ability = ABILITY_ARMOR_TAIL;      isDarkType = FALSE; }
    PARAMETRIZE { species = SPECIES_UMBREON;   ability = ABILITY_SYNCHRONIZE;     isDarkType = TRUE; }

    GIVEN {
        ASSUME(GetSpeciesType(SPECIES_UMBREON, 0) == TYPE_DARK);
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_PRANKSTER); Moves(MOVE_PARTING_SHOT); }
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(species) { Ability(ability); Moves(MOVE_CELEBRATE); }
    } WHEN {
        TURN { MOVE(player, MOVE_PARTING_SHOT); MOVE(opponent, MOVE_CELEBRATE); }
    } SCENE {
        if (isDarkType) {
            NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_PARTING_SHOT, player);
            MESSAGE("It doesn't affect the opposing Umbreon…");
        } else {
            ABILITY_POPUP(opponent, ability);
            NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_PARTING_SHOT, player);
            MESSAGE("Wobbuffet cannot use Parting Shot!");
        }
    } THEN {
        EXPECT_EQ(opponent->statStages[STAT_ATK], DEFAULT_STAT_STAGE);
        EXPECT_EQ(opponent->statStages[STAT_SPATK], DEFAULT_STAT_STAGE);
        EXPECT_EQ(player->species, SPECIES_WOBBUFFET);
    }
}

SINGLE_BATTLE_TEST("Parting Shot: Soundproof and Good as Gold block Parting Shot")
{
    u16 species, ability;

    PARAMETRIZE { species = SPECIES_EXPLOUD;   ability = ABILITY_SOUNDPROOF; }
    PARAMETRIZE { species = SPECIES_GHOLDENGO; ability = ABILITY_GOOD_AS_GOLD; }

    GIVEN {
        ASSUME(IsSoundMove(MOVE_PARTING_SHOT));
        PLAYER(SPECIES_WOBBUFFET) { Moves(MOVE_PARTING_SHOT); }
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(species) { Ability(ability); Moves(MOVE_CELEBRATE); }
    } WHEN {
        TURN { MOVE(player, MOVE_PARTING_SHOT); MOVE(opponent, MOVE_CELEBRATE); }
    } SCENE {
        ABILITY_POPUP(opponent, ability);
        if (ability == ABILITY_SOUNDPROOF)
            MESSAGE("The opposing Exploud's Soundproof blocks Parting Shot!");
        NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_PARTING_SHOT, player);
    } THEN {
        EXPECT_EQ(opponent->statStages[STAT_ATK], DEFAULT_STAT_STAGE);
        EXPECT_EQ(opponent->statStages[STAT_SPATK], DEFAULT_STAT_STAGE);
        EXPECT_EQ(player->species, SPECIES_WOBBUFFET);
    }
}

SINGLE_BATTLE_TEST("Parting Shot: Hyper Cutter blocks Attack drop but still switches")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Moves(MOVE_PARTING_SHOT); }
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_KRABBY) { Ability(ABILITY_HYPER_CUTTER); }
    } WHEN {
        TURN { MOVE(player, MOVE_PARTING_SHOT); SEND_OUT(player, 1); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_PARTING_SHOT, player);
        SEND_IN_MESSAGE("Wynaut");
    } THEN {
        EXPECT_EQ(opponent->statStages[STAT_ATK], DEFAULT_STAT_STAGE);
        EXPECT_EQ(opponent->statStages[STAT_SPATK], DEFAULT_STAT_STAGE - 1);
        EXPECT_EQ(player->species, SPECIES_WYNAUT);
    }
}

SINGLE_BATTLE_TEST("Parting Shot: Magic Coat bounces it and switches the target out")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Moves(MOVE_PARTING_SHOT); }
        OPPONENT(SPECIES_WOBBUFFET) { Moves(MOVE_MAGIC_COAT); }
        OPPONENT(SPECIES_WYNAUT);
    } WHEN {
        TURN { MOVE(opponent, MOVE_MAGIC_COAT); MOVE(player, MOVE_PARTING_SHOT); SEND_OUT(opponent, 1); }
    } THEN {
        EXPECT_EQ(player->statStages[STAT_ATK], DEFAULT_STAT_STAGE - 1);
        EXPECT_EQ(player->statStages[STAT_SPATK], DEFAULT_STAT_STAGE - 1);
        EXPECT_EQ(opponent->species, SPECIES_WYNAUT);
    }
}

SINGLE_BATTLE_TEST("Parting Shot: Magic Bounce bounces it and switches the target out")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Moves(MOVE_PARTING_SHOT); }
        OPPONENT(SPECIES_ESPEON) { Ability(ABILITY_MAGIC_BOUNCE); }
        OPPONENT(SPECIES_WYNAUT);
    } WHEN {
        TURN { MOVE(player, MOVE_PARTING_SHOT); SEND_OUT(opponent, 1); }
    } SCENE {
        ABILITY_POPUP(opponent, ABILITY_MAGIC_BOUNCE);
    } THEN {
        EXPECT_EQ(player->statStages[STAT_ATK], DEFAULT_STAT_STAGE - 1);
        EXPECT_EQ(player->statStages[STAT_SPATK], DEFAULT_STAT_STAGE - 1);
        EXPECT_EQ(opponent->species, SPECIES_WYNAUT);
    }
}

SINGLE_BATTLE_TEST("Parting Shot: Mirror Armor switches the user even if reflected drops fail")
{
    u16 species, ability, item;

    PARAMETRIZE { species = SPECIES_METAGROSS; ability = ABILITY_CLEAR_BODY;      item = ITEM_NONE; }
    PARAMETRIZE { species = SPECIES_TORKOAL;   ability = ABILITY_WHITE_SMOKE;     item = ITEM_NONE; }
    PARAMETRIZE { species = SPECIES_SOLGALEO;  ability = ABILITY_FULL_METAL_BODY; item = ITEM_NONE; }
    PARAMETRIZE { species = SPECIES_LUCARIO;   ability = ABILITY_INNER_FOCUS;     item = ITEM_CLEAR_AMULET; }

    GIVEN {
        ASSUME(gItemsInfo[ITEM_CLEAR_AMULET].holdEffect == HOLD_EFFECT_CLEAR_AMULET);
        PLAYER(species) { Ability(ability); Item(item); Moves(MOVE_PARTING_SHOT); }
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_CORVIKNIGHT) { Ability(ABILITY_MIRROR_ARMOR); }
    } WHEN {
        TURN { MOVE(player, MOVE_PARTING_SHOT); SEND_OUT(player, 1); }
    } SCENE {
        ABILITY_POPUP(opponent, ABILITY_MIRROR_ARMOR);
        if (ability == ABILITY_CLEAR_BODY) {
            ABILITY_POPUP(player, ABILITY_CLEAR_BODY);
            MESSAGE("Metagross's Clear Body prevents stat loss!");
        } else if (ability == ABILITY_WHITE_SMOKE) {
            ABILITY_POPUP(player, ABILITY_WHITE_SMOKE);
            MESSAGE("Torkoal's White Smoke prevents stat loss!");
        } else if (ability == ABILITY_FULL_METAL_BODY) {
            ABILITY_POPUP(player, ABILITY_FULL_METAL_BODY);
            MESSAGE("Solgaleo's Full Metal Body prevents stat loss!");
        } else if (item == ITEM_CLEAR_AMULET) {
            MESSAGE("The effects of the Clear Amulet held by Lucario prevents its stats from being lowered!");
        }
    } THEN {
        EXPECT_EQ(opponent->statStages[STAT_ATK], DEFAULT_STAT_STAGE);
        EXPECT_EQ(opponent->statStages[STAT_SPATK], DEFAULT_STAT_STAGE);
        EXPECT_EQ(player->species, SPECIES_WYNAUT);
    }
}

SINGLE_BATTLE_TEST("Parting Shot: Mirror Armor switches even if reflected stats are at minimum")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Moves(MOVE_PARTING_SHOT, MOVE_SHELL_SMASH, MOVE_CELEBRATE); }
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_CORVIKNIGHT) { Ability(ABILITY_MIRROR_ARMOR); Moves(MOVE_TOPSY_TURVY, MOVE_CELEBRATE); }
    } WHEN {
        TURN { MOVE(player, MOVE_SHELL_SMASH); MOVE(opponent, MOVE_CELEBRATE); }
        TURN { MOVE(player, MOVE_SHELL_SMASH); MOVE(opponent, MOVE_CELEBRATE); }
        TURN { MOVE(player, MOVE_SHELL_SMASH); MOVE(opponent, MOVE_CELEBRATE); }
        TURN { MOVE(player, MOVE_CELEBRATE); MOVE(opponent, MOVE_TOPSY_TURVY); }
        TURN { MOVE(player, MOVE_PARTING_SHOT); SEND_OUT(player, 1); }
    } SCENE {
        ABILITY_POPUP(opponent, ABILITY_MIRROR_ARMOR);
    } THEN {
        EXPECT_EQ(opponent->statStages[STAT_ATK], DEFAULT_STAT_STAGE);
        EXPECT_EQ(opponent->statStages[STAT_SPATK], DEFAULT_STAT_STAGE);
        EXPECT_EQ(player->species, SPECIES_WYNAUT);
    }
}

SINGLE_BATTLE_TEST("Parting Shot: Does not switch if both stats are at minimum (Gen7+)")
{
    GIVEN {
        WITH_CONFIG(CONFIG_PARTING_SHOT_SWITCH, GEN_7);
        PLAYER(SPECIES_WOBBUFFET) { Moves(MOVE_PARTING_SHOT, MOVE_TOPSY_TURVY, MOVE_CELEBRATE); }
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_OMASTAR) { Moves(MOVE_SHELL_SMASH, MOVE_CELEBRATE); }
    } WHEN {
        TURN { MOVE(player, MOVE_CELEBRATE); MOVE(opponent, MOVE_SHELL_SMASH); }
        TURN { MOVE(player, MOVE_CELEBRATE); MOVE(opponent, MOVE_SHELL_SMASH); }
        TURN { MOVE(player, MOVE_CELEBRATE); MOVE(opponent, MOVE_SHELL_SMASH); }
        TURN { MOVE(player, MOVE_TOPSY_TURVY); MOVE(opponent, MOVE_CELEBRATE); }
        TURN { MOVE(player, MOVE_PARTING_SHOT); MOVE(opponent, MOVE_CELEBRATE); }
    } SCENE {
        MESSAGE("The opposing Omastar's stats won't go any lower!");
    } THEN {
        EXPECT_EQ(opponent->statStages[STAT_ATK], MIN_STAT_STAGE);
        EXPECT_EQ(opponent->statStages[STAT_SPATK], MIN_STAT_STAGE);
        EXPECT_EQ(player->species, SPECIES_WOBBUFFET);
    }
}

SINGLE_BATTLE_TEST("Parting Shot: Does not switch if Contrary is at maximum stats (Gen7+)")
{
    GIVEN {
        WITH_CONFIG(CONFIG_PARTING_SHOT_SWITCH, GEN_7);
        PLAYER(SPECIES_WOBBUFFET) { Moves(MOVE_PARTING_SHOT, MOVE_TOPSY_TURVY, MOVE_CELEBRATE); }
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_INKAY) { Ability(ABILITY_CONTRARY); Moves(MOVE_SHELL_SMASH, MOVE_CELEBRATE); }
    } WHEN {
        TURN { MOVE(player, MOVE_CELEBRATE); MOVE(opponent, MOVE_SHELL_SMASH); }
        TURN { MOVE(player, MOVE_CELEBRATE); MOVE(opponent, MOVE_SHELL_SMASH); }
        TURN { MOVE(player, MOVE_CELEBRATE); MOVE(opponent, MOVE_SHELL_SMASH); }
        TURN { MOVE(player, MOVE_TOPSY_TURVY); MOVE(opponent, MOVE_CELEBRATE); }
        TURN { MOVE(player, MOVE_PARTING_SHOT); MOVE(opponent, MOVE_CELEBRATE); }
    } SCENE {
        MESSAGE("The opposing Inkay's stats won't go any higher!");
    } THEN {
        EXPECT_EQ(opponent->statStages[STAT_ATK], MAX_STAT_STAGE);
        EXPECT_EQ(opponent->statStages[STAT_SPATK], MAX_STAT_STAGE);
        EXPECT_EQ(player->species, SPECIES_WOBBUFFET);
    }
}

SINGLE_BATTLE_TEST("Parting Shot: Stat drop prevention by abilities/items does not switch (Gen7+)")
{
    u16 species, ability, item;

    PARAMETRIZE { species = SPECIES_METAGROSS; ability = ABILITY_CLEAR_BODY;      item = ITEM_NONE; }
    PARAMETRIZE { species = SPECIES_TORKOAL;   ability = ABILITY_WHITE_SMOKE;     item = ITEM_NONE; }
    PARAMETRIZE { species = SPECIES_SOLGALEO;  ability = ABILITY_FULL_METAL_BODY; item = ITEM_NONE; }
    PARAMETRIZE { species = SPECIES_LUCARIO;   ability = ABILITY_INNER_FOCUS;     item = ITEM_CLEAR_AMULET; }

    GIVEN {
        WITH_CONFIG(CONFIG_PARTING_SHOT_SWITCH, GEN_7);
        ASSUME(gItemsInfo[ITEM_CLEAR_AMULET].holdEffect == HOLD_EFFECT_CLEAR_AMULET);
        PLAYER(SPECIES_WOBBUFFET) { Moves(MOVE_PARTING_SHOT); }
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(species) { Ability(ability); Item(item); }
    } WHEN {
        TURN { MOVE(player, MOVE_PARTING_SHOT); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_PARTING_SHOT, player);
    } THEN {
        EXPECT_EQ(opponent->statStages[STAT_ATK], DEFAULT_STAT_STAGE);
        EXPECT_EQ(opponent->statStages[STAT_SPATK], DEFAULT_STAT_STAGE);
        EXPECT_EQ(player->species, SPECIES_WOBBUFFET);
    }
}

SINGLE_BATTLE_TEST("Parting Shot: Mist prevents stat drops and does not switch (Gen7+)")
{
    GIVEN {
        WITH_CONFIG(CONFIG_PARTING_SHOT_SWITCH, GEN_7);
        PLAYER(SPECIES_WOBBUFFET) { Moves(MOVE_PARTING_SHOT, MOVE_CELEBRATE); }
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_WOBBUFFET) { Moves(MOVE_MIST, MOVE_CELEBRATE); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_MIST); MOVE(player, MOVE_CELEBRATE); }
        TURN { MOVE(opponent, MOVE_CELEBRATE); MOVE(player, MOVE_PARTING_SHOT); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_PARTING_SHOT, player);
    } THEN {
        EXPECT_EQ(opponent->statStages[STAT_ATK], DEFAULT_STAT_STAGE);
        EXPECT_EQ(opponent->statStages[STAT_SPATK], DEFAULT_STAT_STAGE);
        EXPECT_EQ(player->species, SPECIES_WOBBUFFET);
    }
}

DOUBLE_BATTLE_TEST("Parting Shot: Flower Veil prevents stat drops and does not switch (Gen7+)")
{
    GIVEN {
        ASSUME(GetSpeciesType(SPECIES_BULBASAUR, 0) == TYPE_GRASS);
        WITH_CONFIG(CONFIG_PARTING_SHOT_SWITCH, GEN_7);
        PLAYER(SPECIES_WOBBUFFET) { Moves(MOVE_PARTING_SHOT); }
        PLAYER(SPECIES_WYNAUT);
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_BULBASAUR);
        OPPONENT(SPECIES_COMFEY) { Ability(ABILITY_FLOWER_VEIL); }
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_PARTING_SHOT, target: opponentLeft); MOVE(playerRight, MOVE_CELEBRATE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_PARTING_SHOT, playerLeft);
    } THEN {
        EXPECT_EQ(opponentLeft->statStages[STAT_ATK], DEFAULT_STAT_STAGE);
        EXPECT_EQ(opponentLeft->statStages[STAT_SPATK], DEFAULT_STAT_STAGE);
        EXPECT_EQ(playerLeft->species, SPECIES_WOBBUFFET);
    }
}

SINGLE_BATTLE_TEST("Parting Shot: Switches if both stats are at minimum (Gen6)")
{
    GIVEN {
        WITH_CONFIG(CONFIG_PARTING_SHOT_SWITCH, GEN_6);
        PLAYER(SPECIES_WOBBUFFET) { Moves(MOVE_PARTING_SHOT, MOVE_TOPSY_TURVY, MOVE_CELEBRATE); }
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_OMASTAR) { Moves(MOVE_SHELL_SMASH, MOVE_CELEBRATE); }
    } WHEN {
        TURN { MOVE(player, MOVE_CELEBRATE); MOVE(opponent, MOVE_SHELL_SMASH); }
        TURN { MOVE(player, MOVE_CELEBRATE); MOVE(opponent, MOVE_SHELL_SMASH); }
        TURN { MOVE(player, MOVE_CELEBRATE); MOVE(opponent, MOVE_SHELL_SMASH); }
        TURN { MOVE(player, MOVE_TOPSY_TURVY); MOVE(opponent, MOVE_CELEBRATE); }
        TURN { MOVE(player, MOVE_PARTING_SHOT); MOVE(opponent, MOVE_CELEBRATE); SEND_OUT(player, 1); }
    } SCENE {
        MESSAGE("The opposing Omastar's stats won't go any lower!");
        SEND_IN_MESSAGE("Wynaut");
    } THEN {
        EXPECT_EQ(opponent->statStages[STAT_ATK], MIN_STAT_STAGE);
        EXPECT_EQ(opponent->statStages[STAT_SPATK], MIN_STAT_STAGE);
        EXPECT_EQ(player->species, SPECIES_WYNAUT);
    }
}

SINGLE_BATTLE_TEST("Parting Shot: Switches if Contrary is at maximum stats (Gen6)")
{
    GIVEN {
        WITH_CONFIG(CONFIG_PARTING_SHOT_SWITCH, GEN_6);
        PLAYER(SPECIES_WOBBUFFET) { Moves(MOVE_PARTING_SHOT, MOVE_TOPSY_TURVY, MOVE_CELEBRATE); }
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_INKAY) { Ability(ABILITY_CONTRARY); Moves(MOVE_SHELL_SMASH, MOVE_CELEBRATE); }
    } WHEN {
        TURN { MOVE(player, MOVE_CELEBRATE); MOVE(opponent, MOVE_SHELL_SMASH); }
        TURN { MOVE(player, MOVE_CELEBRATE); MOVE(opponent, MOVE_SHELL_SMASH); }
        TURN { MOVE(player, MOVE_CELEBRATE); MOVE(opponent, MOVE_SHELL_SMASH); }
        TURN { MOVE(player, MOVE_TOPSY_TURVY); MOVE(opponent, MOVE_CELEBRATE); }
        TURN { MOVE(player, MOVE_PARTING_SHOT); MOVE(opponent, MOVE_CELEBRATE); SEND_OUT(player, 1); }
    } SCENE {
        MESSAGE("The opposing Inkay's stats won't go any higher!");
        SEND_IN_MESSAGE("Wynaut");
    } THEN {
        EXPECT_EQ(opponent->statStages[STAT_ATK], MAX_STAT_STAGE);
        EXPECT_EQ(opponent->statStages[STAT_SPATK], MAX_STAT_STAGE);
        EXPECT_EQ(player->species, SPECIES_WYNAUT);
    }
}

SINGLE_BATTLE_TEST("Parting Shot: Stat drop prevention by abilities/items switches (Gen6)")
{
    u16 species, ability, item;

    PARAMETRIZE { species = SPECIES_METAGROSS; ability = ABILITY_CLEAR_BODY;      item = ITEM_NONE; }
    PARAMETRIZE { species = SPECIES_TORKOAL;   ability = ABILITY_WHITE_SMOKE;     item = ITEM_NONE; }
    PARAMETRIZE { species = SPECIES_SOLGALEO;  ability = ABILITY_FULL_METAL_BODY; item = ITEM_NONE; }
    PARAMETRIZE { species = SPECIES_LUCARIO;   ability = ABILITY_INNER_FOCUS;     item = ITEM_CLEAR_AMULET; }

    GIVEN {
        WITH_CONFIG(CONFIG_PARTING_SHOT_SWITCH, GEN_6);
        ASSUME(gItemsInfo[ITEM_CLEAR_AMULET].holdEffect == HOLD_EFFECT_CLEAR_AMULET);
        PLAYER(SPECIES_WOBBUFFET) { Moves(MOVE_PARTING_SHOT); }
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(species) { Ability(ability); Item(item); }
    } WHEN {
        TURN { MOVE(player, MOVE_PARTING_SHOT); SEND_OUT(player, 1); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_PARTING_SHOT, player);
        SEND_IN_MESSAGE("Wynaut");
    } THEN {
        EXPECT_EQ(opponent->statStages[STAT_ATK], DEFAULT_STAT_STAGE);
        EXPECT_EQ(opponent->statStages[STAT_SPATK], DEFAULT_STAT_STAGE);
        EXPECT_EQ(player->species, SPECIES_WYNAUT);
    }
}

SINGLE_BATTLE_TEST("Parting Shot: Mist prevents stat drops and switches (Gen6)")
{
    GIVEN {
        WITH_CONFIG(CONFIG_PARTING_SHOT_SWITCH, GEN_6);
        PLAYER(SPECIES_WOBBUFFET) { Moves(MOVE_PARTING_SHOT, MOVE_CELEBRATE); }
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_WOBBUFFET) { Moves(MOVE_MIST, MOVE_CELEBRATE); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_MIST); MOVE(player, MOVE_CELEBRATE); }
        TURN { MOVE(opponent, MOVE_CELEBRATE); MOVE(player, MOVE_PARTING_SHOT); SEND_OUT(player, 1); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_PARTING_SHOT, player);
        SEND_IN_MESSAGE("Wynaut");
    } THEN {
        EXPECT_EQ(opponent->statStages[STAT_ATK], DEFAULT_STAT_STAGE);
        EXPECT_EQ(opponent->statStages[STAT_SPATK], DEFAULT_STAT_STAGE);
        EXPECT_EQ(player->species, SPECIES_WYNAUT);
    }
}

DOUBLE_BATTLE_TEST("Parting Shot: Flower Veil prevents stat drops and switches (Gen6)")
{
    GIVEN {
        WITH_CONFIG(CONFIG_PARTING_SHOT_SWITCH, GEN_6);
        ASSUME(GetSpeciesType(SPECIES_BULBASAUR, 0) == TYPE_GRASS);
        PLAYER(SPECIES_WOBBUFFET) { Moves(MOVE_PARTING_SHOT); }
        PLAYER(SPECIES_WYNAUT);
        PLAYER(SPECIES_PIKACHU);
        OPPONENT(SPECIES_BULBASAUR);
        OPPONENT(SPECIES_COMFEY) { Ability(ABILITY_FLOWER_VEIL); }
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_PARTING_SHOT, target: opponentLeft); MOVE(playerRight, MOVE_CELEBRATE); SEND_OUT(playerLeft, 2); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_PARTING_SHOT, playerLeft);
        SEND_IN_MESSAGE("Pikachu");
    } THEN {
        EXPECT_EQ(opponentLeft->statStages[STAT_ATK], DEFAULT_STAT_STAGE);
        EXPECT_EQ(opponentLeft->statStages[STAT_SPATK], DEFAULT_STAT_STAGE);
        EXPECT_EQ(playerLeft->species, SPECIES_PIKACHU);
    }
}
