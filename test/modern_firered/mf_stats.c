#include "global.h"
#include "mf_rules.h"
#include "mf_stats.h"
#include "pokemon.h"
#include "test/test.h"

static void SetModernStats(bool8 modernStats)
{
    struct ModernRules *save = MfRules_GetSaveRules();

    MfRules_ApplyDevDefaults(save);
    MfRules_ApplyGamemodePreset(save, MF_GAMEMODE_CUSTOM);
    save->modernStats = modernStats;
    save->rulesLocked = TRUE;
}

static void RestorePhase1Defaults(void)
{
    struct ModernRules *save = MfRules_GetSaveRules();

    save->version = 0;
}

TEST("MF: modern stats on uses Gen-latest base stats")
{
    SetModernStats(TRUE);

    EXPECT_EQ(GetSpeciesBaseSpAttack(SPECIES_BUTTERFREE), 90u);
    EXPECT_EQ(GetSpeciesBaseAttack(SPECIES_ARBOK), 95u);
    EXPECT_EQ(GetSpeciesBaseAttack(SPECIES_BEEDRILL), 90u);
    EXPECT_EQ(GetSpeciesBaseSpeed(SPECIES_PIDGEOT), 101u);
    EXPECT_EQ(GetSpeciesBaseDefense(SPECIES_PIKACHU), 40u);
    EXPECT_EQ(GetSpeciesBaseSpDefense(SPECIES_PIKACHU), 50u);
    EXPECT_EQ(GetSpeciesBaseAttack(SPECIES_FARFETCHD), 90u);
    EXPECT_EQ(GetSpeciesBaseSpDefense(SPECIES_ALAKAZAM), 95u);
    EXPECT_EQ(GetSpeciesBaseAttack(SPECIES_GOLEM), 120u);
    EXPECT_EQ(GetSpeciesBaseSpAttack(SPECIES_SWELLOW), 75u);
    EXPECT_EQ(GetSpeciesBaseHP(SPECIES_LUNATONE), 90u);
    // Unchanged species still match species_info.
    EXPECT_EQ(GetSpeciesBaseHP(SPECIES_CHARIZARD), 78u);
    EXPECT_EQ(GetSpeciesBaseAttack(SPECIES_CHARIZARD), 84u);

    RestorePhase1Defaults();
}

TEST("MF: modern stats off uses Gen-3 classic base stats")
{
    SetModernStats(FALSE);

    EXPECT_EQ(GetSpeciesBaseSpAttack(SPECIES_BUTTERFREE), 80u);
    EXPECT_EQ(GetSpeciesBaseAttack(SPECIES_ARBOK), 85u);
    EXPECT_EQ(GetSpeciesBaseAttack(SPECIES_BEEDRILL), 80u);
    EXPECT_EQ(GetSpeciesBaseSpeed(SPECIES_PIDGEOT), 91u);
    EXPECT_EQ(GetSpeciesBaseDefense(SPECIES_PIKACHU), 30u);
    EXPECT_EQ(GetSpeciesBaseSpDefense(SPECIES_PIKACHU), 40u);
    EXPECT_EQ(GetSpeciesBaseAttack(SPECIES_FARFETCHD), 65u);
    EXPECT_EQ(GetSpeciesBaseSpDefense(SPECIES_ALAKAZAM), 85u);
    EXPECT_EQ(GetSpeciesBaseAttack(SPECIES_GOLEM), 110u);
    EXPECT_EQ(GetSpeciesBaseSpAttack(SPECIES_SWELLOW), 50u);
    EXPECT_EQ(GetSpeciesBaseHP(SPECIES_LUNATONE), 70u);
    // Unchanged species identical in both modes.
    EXPECT_EQ(GetSpeciesBaseHP(SPECIES_CHARIZARD), 78u);
    EXPECT_EQ(GetSpeciesBaseAttack(SPECIES_CHARIZARD), 84u);

    RestorePhase1Defaults();
}

TEST("MF: modern stats GetSpeciesBaseStat matches per-stat getters")
{
    u32 i;
    static const enum Species sSamples[] = {
        SPECIES_BUTTERFREE,
        SPECIES_ARBOK,
        SPECIES_PIKACHU,
        SPECIES_CHARIZARD,
        SPECIES_SWELLOW,
    };

    SetModernStats(FALSE);
    for (i = 0; i < ARRAY_COUNT(sSamples); i++)
    {
        enum Species sp = sSamples[i];
        EXPECT_EQ(GetSpeciesBaseStat(sp, STAT_HP), GetSpeciesBaseHP(sp));
        EXPECT_EQ(GetSpeciesBaseStat(sp, STAT_ATK), GetSpeciesBaseAttack(sp));
        EXPECT_EQ(GetSpeciesBaseStat(sp, STAT_DEF), GetSpeciesBaseDefense(sp));
        EXPECT_EQ(GetSpeciesBaseStat(sp, STAT_SPEED), GetSpeciesBaseSpeed(sp));
        EXPECT_EQ(GetSpeciesBaseStat(sp, STAT_SPATK), GetSpeciesBaseSpAttack(sp));
        EXPECT_EQ(GetSpeciesBaseStat(sp, STAT_SPDEF), GetSpeciesBaseSpDefense(sp));
    }

    SetModernStats(TRUE);
    for (i = 0; i < ARRAY_COUNT(sSamples); i++)
    {
        enum Species sp = sSamples[i];
        EXPECT_EQ(GetSpeciesBaseStat(sp, STAT_HP), GetSpeciesBaseHP(sp));
        EXPECT_EQ(GetSpeciesBaseStat(sp, STAT_ATK), GetSpeciesBaseAttack(sp));
        EXPECT_EQ(GetSpeciesBaseStat(sp, STAT_DEF), GetSpeciesBaseDefense(sp));
        EXPECT_EQ(GetSpeciesBaseStat(sp, STAT_SPEED), GetSpeciesBaseSpeed(sp));
        EXPECT_EQ(GetSpeciesBaseStat(sp, STAT_SPATK), GetSpeciesBaseSpAttack(sp));
        EXPECT_EQ(GetSpeciesBaseStat(sp, STAT_SPDEF), GetSpeciesBaseSpDefense(sp));
    }

    RestorePhase1Defaults();
}

TEST("MF: modern stats raise BST for officially buffed species")
{
    u32 classicTotal;
    u32 modernTotal;

    SetModernStats(FALSE);
    classicTotal = GetSpeciesBaseStatTotal(SPECIES_BUTTERFREE);
    SetModernStats(TRUE);
    modernTotal = GetSpeciesBaseStatTotal(SPECIES_BUTTERFREE);

    EXPECT(modernTotal > classicTotal);
    EXPECT_EQ(modernTotal - classicTotal, 10u); // SpAtk 80 → 90

    RestorePhase1Defaults();
}
