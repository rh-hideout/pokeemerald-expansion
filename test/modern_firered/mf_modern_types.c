#include "global.h"
#include "battle_util.h"
#include "mf_rules.h"
#include "mf_types.h"
#include "pokemon.h"
#include "test/battle.h"
#include "test/test.h"

static void SetTypeRules(bool8 modernTypes, bool8 typeEffectiveness, bool8 fairyTypes)
{
    struct ModernRules *save = MfRules_GetSaveRules();

    MfRules_ApplyDevDefaults(save);
    MfRules_ApplyGamemodePreset(save, MF_GAMEMODE_CUSTOM);
    save->modernTypes = modernTypes;
    save->typeEffectiveness = typeEffectiveness;
    save->fairyTypes = fairyTypes;
    save->rulesLocked = TRUE;
}

static void RestorePhase1Defaults(void)
{
    struct ModernRules *save = MfRules_GetSaveRules();

    save->version = 0;
}

TEST("MF: modern types off keeps vanilla species typings")
{
    SetTypeRules(FALSE, FALSE, TRUE);

    EXPECT_EQ(GetSpeciesType(SPECIES_ARBOK, 0), TYPE_POISON);
    EXPECT_EQ(GetSpeciesType(SPECIES_ARBOK, 1), TYPE_POISON);
    EXPECT_EQ(GetSpeciesType(SPECIES_PARASECT, 0), TYPE_BUG);
    EXPECT_EQ(GetSpeciesType(SPECIES_PARASECT, 1), TYPE_GRASS);
    EXPECT_EQ(GetSpeciesType(SPECIES_GOLDUCK, 0), TYPE_WATER);
    EXPECT_EQ(GetSpeciesType(SPECIES_GOLDUCK, 1), TYPE_WATER);
    EXPECT_EQ(GetSpeciesType(SPECIES_MEGANIUM, 0), TYPE_GRASS);
    EXPECT_EQ(GetSpeciesType(SPECIES_MEGANIUM, 1), TYPE_GRASS);
    EXPECT_EQ(GetSpeciesType(SPECIES_SNUBBULL, 0), TYPE_FAIRY);
    EXPECT_EQ(GetSpeciesType(SPECIES_SNUBBULL, 1), TYPE_FAIRY);

    RestorePhase1Defaults();
}

TEST("MF: modern types on applies ME balance retypes")
{
    SetTypeRules(TRUE, FALSE, TRUE);

    EXPECT_EQ(GetSpeciesType(SPECIES_ARBOK, 0), TYPE_POISON);
    EXPECT_EQ(GetSpeciesType(SPECIES_ARBOK, 1), TYPE_DARK);
    EXPECT_EQ(GetSpeciesType(SPECIES_PARASECT, 0), TYPE_BUG);
    EXPECT_EQ(GetSpeciesType(SPECIES_PARASECT, 1), TYPE_GHOST);
    EXPECT_EQ(GetSpeciesType(SPECIES_GOLDUCK, 0), TYPE_WATER);
    EXPECT_EQ(GetSpeciesType(SPECIES_GOLDUCK, 1), TYPE_PSYCHIC);
    EXPECT_EQ(GetSpeciesType(SPECIES_KINGLER, 0), TYPE_WATER);
    EXPECT_EQ(GetSpeciesType(SPECIES_KINGLER, 1), TYPE_STEEL);
    EXPECT_EQ(GetSpeciesType(SPECIES_MEGANIUM, 0), TYPE_GRASS);
    EXPECT_EQ(GetSpeciesType(SPECIES_MEGANIUM, 1), TYPE_FAIRY);
    EXPECT_EQ(GetSpeciesType(SPECIES_TYPHLOSION, 0), TYPE_FIRE);
    EXPECT_EQ(GetSpeciesType(SPECIES_TYPHLOSION, 1), TYPE_GROUND);
    EXPECT_EQ(GetSpeciesType(SPECIES_FERALIGATR, 0), TYPE_WATER);
    EXPECT_EQ(GetSpeciesType(SPECIES_FERALIGATR, 1), TYPE_DRAGON);
    EXPECT_EQ(GetSpeciesType(SPECIES_NOCTOWL, 0), TYPE_PSYCHIC);
    EXPECT_EQ(GetSpeciesType(SPECIES_NOCTOWL, 1), TYPE_FLYING);
    EXPECT_EQ(GetSpeciesType(SPECIES_SCEPTILE, 0), TYPE_GRASS);
    EXPECT_EQ(GetSpeciesType(SPECIES_SCEPTILE, 1), TYPE_DRAGON);
    EXPECT_EQ(GetSpeciesType(SPECIES_MASQUERAIN, 0), TYPE_BUG);
    EXPECT_EQ(GetSpeciesType(SPECIES_MASQUERAIN, 1), TYPE_WATER);
    // ME types_new when modern on (Fairy/Normal), not pure Fairy.
    EXPECT_EQ(GetSpeciesType(SPECIES_SNUBBULL, 0), TYPE_FAIRY);
    EXPECT_EQ(GetSpeciesType(SPECIES_SNUBBULL, 1), TYPE_NORMAL);
    EXPECT_EQ(GetSpeciesType(SPECIES_GRANBULL, 0), TYPE_FAIRY);
    EXPECT_EQ(GetSpeciesType(SPECIES_GRANBULL, 1), TYPE_NORMAL);
    EXPECT_EQ(GetSpeciesType(SPECIES_ELECTIVIRE, 0), TYPE_ELECTRIC);
    EXPECT_EQ(GetSpeciesType(SPECIES_ELECTIVIRE, 1), TYPE_FIGHTING);
    EXPECT_EQ(GetSpeciesType(SPECIES_YANMEGA, 0), TYPE_BUG);
    EXPECT_EQ(GetSpeciesType(SPECIES_YANMEGA, 1), TYPE_DRAGON);
    // Unrelated species unchanged.
    EXPECT_EQ(GetSpeciesType(SPECIES_CHARIZARD, 0), TYPE_FIRE);
    EXPECT_EQ(GetSpeciesType(SPECIES_CHARIZARD, 1), TYPE_FLYING);

    RestorePhase1Defaults();
}

TEST("MF: fairy off still wins over modern for Gen-6 Fairy retypes")
{
    SetTypeRules(TRUE, TRUE, FALSE);

    EXPECT_EQ(GetSpeciesType(SPECIES_SNUBBULL, 0), TYPE_NORMAL);
    EXPECT_EQ(GetSpeciesType(SPECIES_SNUBBULL, 1), TYPE_NORMAL);
    EXPECT_EQ(GetSpeciesType(SPECIES_CLEFAIRY, 0), TYPE_NORMAL);
    // Modern-only Fairy (not Gen-6 retype) still applies.
    EXPECT_EQ(GetSpeciesType(SPECIES_MEGANIUM, 0), TYPE_GRASS);
    EXPECT_EQ(GetSpeciesType(SPECIES_MEGANIUM, 1), TYPE_FAIRY);

    RestorePhase1Defaults();
}

TEST("MF: TYPE CHART Gen VI+ matches gTypeEffectivenessTable")
{
    const uq4_12_t (*table)[NUMBER_OF_MON_TYPES];

    SetTypeRules(FALSE, FALSE, TRUE);
    table = MfGetTypeEffectivenessTable();

    EXPECT(table == gTypeEffectivenessTable);
    EXPECT_EQ(GetTypeModifier(TYPE_GHOST, TYPE_STEEL), UQ_4_12(1.0));
    EXPECT_EQ(GetTypeModifier(TYPE_DARK, TYPE_STEEL), UQ_4_12(1.0));
    EXPECT_EQ(GetTypeModifier(TYPE_BUG, TYPE_FAIRY), UQ_4_12(0.5));
    EXPECT_EQ(GetTypeModifier(TYPE_WATER, TYPE_ICE), UQ_4_12(1.0));
    EXPECT_EQ(GetTypeModifier(TYPE_GROUND, TYPE_ROCK), UQ_4_12(2.0));
    EXPECT_EQ(GetTypeModifier(TYPE_DRAGON, TYPE_FAIRY), UQ_4_12(0.0));

    RestorePhase1Defaults();
}

TEST("MF: TYPE CHART Improved applies ME matchup diffs")
{
    const uq4_12_t (*table)[NUMBER_OF_MON_TYPES];

    SetTypeRules(FALSE, TRUE, TRUE);
    table = MfGetTypeEffectivenessTable();

    EXPECT(table != gTypeEffectivenessTable);
    EXPECT_EQ(GetTypeModifier(TYPE_BUG, TYPE_FAIRY), UQ_4_12(1.0));
    EXPECT_EQ(GetTypeModifier(TYPE_BUG, TYPE_GHOST), UQ_4_12(1.0));
    EXPECT_EQ(GetTypeModifier(TYPE_GROUND, TYPE_ROCK), UQ_4_12(1.0));
    EXPECT_EQ(GetTypeModifier(TYPE_ICE, TYPE_WATER), UQ_4_12(1.0));
    EXPECT_EQ(GetTypeModifier(TYPE_ROCK, TYPE_GROUND), UQ_4_12(1.0));
    EXPECT_EQ(GetTypeModifier(TYPE_ROCK, TYPE_ROCK), UQ_4_12(0.5));
    EXPECT_EQ(GetTypeModifier(TYPE_STEEL, TYPE_ICE), UQ_4_12(1.0));
    EXPECT_EQ(GetTypeModifier(TYPE_WATER, TYPE_ICE), UQ_4_12(0.5));
    // Unchanged Gen VI Fairy interaction still present.
    EXPECT_EQ(GetTypeModifier(TYPE_DRAGON, TYPE_FAIRY), UQ_4_12(0.0));
    EXPECT_EQ(GetTypeModifier(TYPE_GHOST, TYPE_STEEL), UQ_4_12(1.0));

    RestorePhase1Defaults();
}

SINGLE_BATTLE_TEST("MF: modern types — Psychic hits Golduck (Water/Psychic)")
{
    GIVEN {
        SetTypeRules(TRUE, FALSE, TRUE);
        ASSUME(GetSpeciesType(SPECIES_GOLDUCK, 1) == TYPE_PSYCHIC);
        ASSUME(GetMoveType(MOVE_PSYCHIC) == TYPE_PSYCHIC);
        PLAYER(SPECIES_GOLDUCK);
        OPPONENT(SPECIES_ALAKAZAM);
    } WHEN {
        TURN { MOVE(opponent, MOVE_PSYCHIC); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_PSYCHIC, opponent);
        HP_BAR(player);
        MESSAGE("It's not very effective…");
    } THEN {
        RestorePhase1Defaults();
    }
}

SINGLE_BATTLE_TEST("MF: Improved chart — Ground is neutral to Rock (not SE)")
{
    GIVEN {
        SetTypeRules(FALSE, TRUE, TRUE);
        ASSUME(GetTypeModifier(TYPE_GROUND, TYPE_ROCK) == UQ_4_12(1.0));
        ASSUME(gTypeEffectivenessTable[TYPE_GROUND][TYPE_ROCK] == UQ_4_12(2.0));
        ASSUME(GetMoveType(MOVE_EARTHQUAKE) == TYPE_GROUND);
        ASSUME(GetSpeciesType(SPECIES_GEODUDE, 0) == TYPE_ROCK);
        PLAYER(SPECIES_GEODUDE);
        OPPONENT(SPECIES_SANDSHREW);
    } WHEN {
        TURN { MOVE(opponent, MOVE_EARTHQUAKE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_EARTHQUAKE, opponent);
        HP_BAR(player);
        NOT MESSAGE("It's super effective!");
    } THEN {
        RestorePhase1Defaults();
    }
}
