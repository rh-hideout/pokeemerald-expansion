#include "global.h"
#include "mf_rules.h"
#include "pokemon.h"
#include "test/battle.h"
#include "test/test.h"

static void SetFairyRule(bool8 enabled)
{
    struct ModernRules *save = MfRules_GetSaveRules();

    MfRules_ApplyDevDefaults(save);
    MfRules_ApplyGamemodePreset(save, MF_GAMEMODE_CUSTOM);
    save->fairyTypes = enabled;
    save->rulesLocked = TRUE;
}

// Leave save invalid so later MF tests fall back to Phase 1 defaults (Fairy on).
static void RestorePhase1Defaults(void)
{
    struct ModernRules *save = MfRules_GetSaveRules();

    save->version = 0;
}

TEST("MF: Fairy on keeps Gen-6 Fairy typings")
{
    SetFairyRule(TRUE);

    EXPECT_EQ(GetSpeciesType(SPECIES_CLEFAIRY, 0), TYPE_FAIRY);
    EXPECT_EQ(GetSpeciesType(SPECIES_CLEFAIRY, 1), TYPE_FAIRY);
    EXPECT_EQ(GetSpeciesType(SPECIES_JIGGLYPUFF, 0), TYPE_NORMAL);
    EXPECT_EQ(GetSpeciesType(SPECIES_JIGGLYPUFF, 1), TYPE_FAIRY);
    EXPECT_EQ(GetSpeciesType(SPECIES_MR_MIME, 0), TYPE_PSYCHIC);
    EXPECT_EQ(GetSpeciesType(SPECIES_MR_MIME, 1), TYPE_FAIRY);
    EXPECT_EQ(GetSpeciesType(SPECIES_GARDEVOIR, 0), TYPE_PSYCHIC);
    EXPECT_EQ(GetSpeciesType(SPECIES_GARDEVOIR, 1), TYPE_FAIRY);
    EXPECT_EQ(GetSpeciesType(SPECIES_MAWILE, 0), TYPE_STEEL);
    EXPECT_EQ(GetSpeciesType(SPECIES_MAWILE, 1), TYPE_FAIRY);
    EXPECT_EQ(GetSpeciesType(SPECIES_TOGETIC, 0), TYPE_FAIRY);
    EXPECT_EQ(GetSpeciesType(SPECIES_TOGETIC, 1), TYPE_FLYING);
    EXPECT_EQ(GetSpeciesType(SPECIES_AZURILL, 0), TYPE_NORMAL);
    EXPECT_EQ(GetSpeciesType(SPECIES_AZURILL, 1), TYPE_FAIRY);

    RestorePhase1Defaults();
}

TEST("MF: Fairy off reverts Gen-6 Fairy retypes to pre-Gen-6")
{
    SetFairyRule(FALSE);

    EXPECT_EQ(GetSpeciesType(SPECIES_CLEFAIRY, 0), TYPE_NORMAL);
    EXPECT_EQ(GetSpeciesType(SPECIES_CLEFAIRY, 1), TYPE_NORMAL);
    EXPECT_EQ(GetSpeciesType(SPECIES_CLEFABLE, 0), TYPE_NORMAL);
    EXPECT_EQ(GetSpeciesType(SPECIES_JIGGLYPUFF, 0), TYPE_NORMAL);
    EXPECT_EQ(GetSpeciesType(SPECIES_JIGGLYPUFF, 1), TYPE_NORMAL);
    EXPECT_EQ(GetSpeciesType(SPECIES_MR_MIME, 0), TYPE_PSYCHIC);
    EXPECT_EQ(GetSpeciesType(SPECIES_MR_MIME, 1), TYPE_PSYCHIC);
    EXPECT_EQ(GetSpeciesType(SPECIES_GARDEVOIR, 0), TYPE_PSYCHIC);
    EXPECT_EQ(GetSpeciesType(SPECIES_GARDEVOIR, 1), TYPE_PSYCHIC);
    EXPECT_EQ(GetSpeciesType(SPECIES_MAWILE, 0), TYPE_STEEL);
    EXPECT_EQ(GetSpeciesType(SPECIES_MAWILE, 1), TYPE_STEEL);
    EXPECT_EQ(GetSpeciesType(SPECIES_TOGETIC, 0), TYPE_NORMAL);
    EXPECT_EQ(GetSpeciesType(SPECIES_TOGETIC, 1), TYPE_FLYING);
    EXPECT_EQ(GetSpeciesType(SPECIES_MARILL, 0), TYPE_WATER);
    EXPECT_EQ(GetSpeciesType(SPECIES_MARILL, 1), TYPE_WATER);
    EXPECT_EQ(GetSpeciesType(SPECIES_SNUBBULL, 0), TYPE_NORMAL);
    EXPECT_EQ(GetSpeciesType(SPECIES_SNUBBULL, 1), TYPE_NORMAL);
    EXPECT_EQ(GetSpeciesType(SPECIES_AZURILL, 0), TYPE_NORMAL);
    EXPECT_EQ(GetSpeciesType(SPECIES_AZURILL, 1), TYPE_NORMAL);
#if P_FAMILY_COTTONEE
    EXPECT_EQ(GetSpeciesType(SPECIES_COTTONEE, 0), TYPE_GRASS);
    EXPECT_EQ(GetSpeciesType(SPECIES_COTTONEE, 1), TYPE_GRASS);
#endif

    RestorePhase1Defaults();
}

TEST("MF: Fairy off leaves Fairy-native species and chart alone")
{
    SetFairyRule(FALSE);

    // Sylveon was introduced as Fairy — no pre-Gen-6 typing.
    EXPECT_EQ(GetSpeciesType(SPECIES_SYLVEON, 0), TYPE_FAIRY);
    EXPECT_EQ(GetSpeciesType(SPECIES_SYLVEON, 1), TYPE_FAIRY);
    // Unrelated species unchanged.
    EXPECT_EQ(GetSpeciesType(SPECIES_CHARIZARD, 0), TYPE_FIRE);
    EXPECT_EQ(GetSpeciesType(SPECIES_CHARIZARD, 1), TYPE_FLYING);
    // Fairy chart entries stay in Gen VI+ and Improved (S28); Fairy moves still Fairy.
    EXPECT_EQ(gTypeEffectivenessTable[TYPE_DRAGON][TYPE_FAIRY], UQ_4_12(0.0));
    EXPECT_EQ(GetMoveType(MOVE_MOONBLAST), TYPE_FAIRY);

    RestorePhase1Defaults();
}

SINGLE_BATTLE_TEST("MF: Fairy off — Dragon Claw hits Clefairy (Normal)")
{
    GIVEN {
        SetFairyRule(FALSE);
        ASSUME(GetSpeciesType(SPECIES_CLEFAIRY, 0) == TYPE_NORMAL);
        ASSUME(GetMoveType(MOVE_DRAGON_CLAW) == TYPE_DRAGON);
        PLAYER(SPECIES_CLEFAIRY);
        OPPONENT(SPECIES_DRAGONITE);
    } WHEN {
        TURN { MOVE(opponent, MOVE_DRAGON_CLAW); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_DRAGON_CLAW, opponent);
        HP_BAR(player);
        NOT MESSAGE("It doesn't affect Clefairy…");
    } THEN {
        RestorePhase1Defaults();
    }
}

SINGLE_BATTLE_TEST("MF: Fairy on — Dragon Claw blocked by Clefairy (Fairy)")
{
    GIVEN {
        SetFairyRule(TRUE);
        ASSUME(GetSpeciesType(SPECIES_CLEFAIRY, 0) == TYPE_FAIRY);
        ASSUME(GetMoveType(MOVE_DRAGON_CLAW) == TYPE_DRAGON);
        ASSUME(gTypeEffectivenessTable[TYPE_DRAGON][TYPE_FAIRY] == UQ_4_12(0.0));
        PLAYER(SPECIES_CLEFAIRY);
        OPPONENT(SPECIES_DRAGONITE);
    } WHEN {
        TURN { MOVE(opponent, MOVE_DRAGON_CLAW); }
    } SCENE {
        NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_DRAGON_CLAW, opponent);
        MESSAGE("It doesn't affect Clefairy…");
    } THEN {
        RestorePhase1Defaults();
    }
}
