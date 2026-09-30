#include "global.h"
#include "mf_nuzlocke.h"
#include "mf_rules.h"
#include "pokedex.h"
#include "pokemon.h"
#include "pokemon_storage_system.h"
#include "constants/battle.h"
#include "constants/pokedex.h"
#include "constants/region_map_sections.h"
#include "constants/species.h"
#include "test/test.h"

TEST("MF: nuzlocke encounter flag get/set/clear per mapsec")
{
    u8 flags[MF_NUZLOCKE_ENCOUNTER_FLAG_BYTES];
    u16 i;

    for (i = 0; i < MF_NUZLOCKE_ENCOUNTER_FLAG_BYTES; i++)
        flags[i] = 0;

    EXPECT(!MfNuzlockeFlagGetFrom(flags, MAPSEC_ROUTE_1));
    EXPECT(!MfNuzlockeFlagGetFrom(flags, MAPSEC_VIRIDIAN_CITY));
    EXPECT_EQ(MfNuzlockeCountUsedFrom(flags), 0);

    MfNuzlockeFlagSetIn(flags, MAPSEC_ROUTE_1);
    EXPECT(MfNuzlockeFlagGetFrom(flags, MAPSEC_ROUTE_1));
    EXPECT(!MfNuzlockeFlagGetFrom(flags, MAPSEC_ROUTE_2));
    EXPECT_EQ(MfNuzlockeCountUsedFrom(flags), 1);

    MfNuzlockeFlagSetIn(flags, MAPSEC_VIRIDIAN_FOREST);
    EXPECT(MfNuzlockeFlagGetFrom(flags, MAPSEC_VIRIDIAN_FOREST));
    EXPECT_EQ(MfNuzlockeCountUsedFrom(flags), 2);

    // Idempotent set.
    MfNuzlockeFlagSetIn(flags, MAPSEC_ROUTE_1);
    EXPECT_EQ(MfNuzlockeCountUsedFrom(flags), 2);

    MfNuzlockeFlagClearIn(flags, MAPSEC_ROUTE_1);
    EXPECT(!MfNuzlockeFlagGetFrom(flags, MAPSEC_ROUTE_1));
    EXPECT(MfNuzlockeFlagGetFrom(flags, MAPSEC_VIRIDIAN_FOREST));
    EXPECT_EQ(MfNuzlockeCountUsedFrom(flags), 1);

    // Out-of-range / NULL are no-ops.
    EXPECT(!MfNuzlockeFlagGetFrom(flags, MAPSEC_COUNT));
    EXPECT(!MfNuzlockeFlagGetFrom(NULL, MAPSEC_ROUTE_1));
    MfNuzlockeFlagSetIn(NULL, MAPSEC_ROUTE_1);
    MfNuzlockeFlagClearIn(flags, MAPSEC_COUNT);
    EXPECT(MfNuzlockeFlagGetFrom(flags, MAPSEC_VIRIDIAN_FOREST));
}

TEST("MF: nuzlocke flag covers first and last mapsec bits")
{
    u8 flags[MF_NUZLOCKE_ENCOUNTER_FLAG_BYTES];
    u16 i;
    u16 last = MAPSEC_COUNT - 1;

    for (i = 0; i < MF_NUZLOCKE_ENCOUNTER_FLAG_BYTES; i++)
        flags[i] = 0;

    MfNuzlockeFlagSetIn(flags, 0);
    MfNuzlockeFlagSetIn(flags, last);
    EXPECT(MfNuzlockeFlagGetFrom(flags, 0));
    EXPECT(MfNuzlockeFlagGetFrom(flags, last));
    EXPECT_EQ(MfNuzlockeCountUsedFrom(flags), 2);

    MfNuzlockeFlagClearIn(flags, 0);
    EXPECT(!MfNuzlockeFlagGetFrom(flags, 0));
    EXPECT(MfNuzlockeFlagGetFrom(flags, last));
}

TEST("MF: nuzlocke wild battles that consume an area")
{
    EXPECT(MfNuzlocke_WildBattleConsumesEncounter(0));
    EXPECT(MfNuzlocke_WildBattleConsumesEncounter(BATTLE_TYPE_DOUBLE));
    EXPECT(MfNuzlocke_WildBattleConsumesEncounter(BATTLE_TYPE_SAFARI));
    EXPECT(MfNuzlocke_WildBattleConsumesEncounter(BATTLE_TYPE_ROAMER));

    EXPECT(!MfNuzlocke_WildBattleConsumesEncounter(BATTLE_TYPE_TRAINER));
    EXPECT(!MfNuzlocke_WildBattleConsumesEncounter(BATTLE_TYPE_FIRST_BATTLE));
    EXPECT(!MfNuzlocke_WildBattleConsumesEncounter(BATTLE_TYPE_LEGENDARY));
    EXPECT(!MfNuzlocke_WildBattleConsumesEncounter(BATTLE_TYPE_GHOST));
    EXPECT(!MfNuzlocke_WildBattleConsumesEncounter(BATTLE_TYPE_LINK));
    EXPECT(!MfNuzlocke_WildBattleConsumesEncounter(BATTLE_TYPE_CATCH_TUTORIAL));
    EXPECT(!MfNuzlocke_WildBattleConsumesEncounter(BATTLE_TYPE_FRONTIER));
}

TEST("MF: nuzlocke first-encounter icon off when lock inactive")
{
    // Default phase-1 / empty-rules path: nuzlocke off → no red "1".
    EXPECT(!MfNuzlocke_ShouldShowFirstEncounterIcon());
}

// --- S36 faint handling ----------------------------------------------------

TEST("MF: nuzlocke faint fate Easy is always Cemetery")
{
    EXPECT_EQ(MfNuzlocke_ResolveFaintFate(FALSE, TRUE, FALSE, FALSE), MF_NUZLOCKE_FAINT_CEMETERY);
    EXPECT_EQ(MfNuzlocke_ResolveFaintFate(FALSE, TRUE, TRUE, FALSE), MF_NUZLOCKE_FAINT_CEMETERY);
    EXPECT_EQ(MfNuzlocke_ResolveFaintFate(FALSE, TRUE, TRUE, TRUE), MF_NUZLOCKE_FAINT_CEMETERY);
}

TEST("MF: nuzlocke faint fate Off skips")
{
    EXPECT_EQ(MfNuzlocke_ResolveFaintFate(FALSE, FALSE, FALSE, FALSE), MF_NUZLOCKE_FAINT_SKIP);
    EXPECT_EQ(MfNuzlocke_ResolveFaintFate(FALSE, FALSE, TRUE, TRUE), MF_NUZLOCKE_FAINT_SKIP);
}

TEST("MF: nuzlocke faint fate Normal Cemetery vs Release")
{
    // Runtime-inactive full Nuzlocke → skip (pre-Pokédex / post-clear).
    EXPECT_EQ(MfNuzlocke_ResolveFaintFate(TRUE, FALSE, FALSE, FALSE), MF_NUZLOCKE_FAINT_SKIP);

    EXPECT_EQ(MfNuzlocke_ResolveFaintFate(TRUE, FALSE, FALSE, TRUE), MF_NUZLOCKE_FAINT_CEMETERY);
    EXPECT_EQ(MfNuzlocke_ResolveFaintFate(TRUE, FALSE, TRUE, TRUE), MF_NUZLOCKE_FAINT_RELEASE);
    // Hardcore uses same FAINTING bit.
    EXPECT_EQ(MfNuzlocke_ResolveFaintFate(TRUE, FALSE, FALSE, TRUE), MF_NUZLOCKE_FAINT_CEMETERY);
}

TEST("MF: nuzlocke faint handling battle exclusions")
{
    EXPECT(MfNuzlocke_BattleAllowsFaintHandling(0));
    EXPECT(MfNuzlocke_BattleAllowsFaintHandling(BATTLE_TYPE_TRAINER));
    EXPECT(MfNuzlocke_BattleAllowsFaintHandling(BATTLE_TYPE_DOUBLE));
    EXPECT(MfNuzlocke_BattleAllowsFaintHandling(BATTLE_TYPE_SAFARI));

    EXPECT(!MfNuzlocke_BattleAllowsFaintHandling(BATTLE_TYPE_LINK));
    EXPECT(!MfNuzlocke_BattleAllowsFaintHandling(BATTLE_TYPE_RECORDED_LINK));
    EXPECT(!MfNuzlocke_BattleAllowsFaintHandling(BATTLE_TYPE_FIRST_BATTLE));
    EXPECT(!MfNuzlocke_BattleAllowsFaintHandling(BATTLE_TYPE_CATCH_TUTORIAL));
    EXPECT(!MfNuzlocke_BattleAllowsFaintHandling(BATTLE_TYPE_INGAME_PARTNER));
    EXPECT(!MfNuzlocke_BattleAllowsFaintHandling(BATTLE_TYPE_FRONTIER));
    EXPECT(!MfNuzlocke_BattleAllowsFaintHandling(BATTLE_TYPE_RECORDED));
}

TEST("MF: nuzlocke faint victim predicate")
{
    EXPECT(MfNuzlocke_PartySlotIsFaintedVictim(TRUE, FALSE, 0));
    EXPECT(!MfNuzlocke_PartySlotIsFaintedVictim(TRUE, FALSE, 1));
    EXPECT(!MfNuzlocke_PartySlotIsFaintedVictim(FALSE, FALSE, 0));
    EXPECT(!MfNuzlocke_PartySlotIsFaintedVictim(TRUE, TRUE, 0)); // egg
}

TEST("MF: nuzlocke box replacement predicate skips dead and eggs")
{
    EXPECT(MfNuzlocke_BoxSlotIsUsableReplacement(TRUE, FALSE, FALSE));
    EXPECT(!MfNuzlocke_BoxSlotIsUsableReplacement(FALSE, FALSE, FALSE));
    EXPECT(!MfNuzlocke_BoxSlotIsUsableReplacement(TRUE, TRUE, FALSE));
    EXPECT(!MfNuzlocke_BoxSlotIsUsableReplacement(TRUE, FALSE, TRUE));
}

TEST("MF: nuzlocke cemetery lock clears after game-clear flag semantics")
{
    // Locked when dead; unlocked when not dead. Game-clear path needs FlagGet —
    // covered manually; here we only assert the dead=FALSE short-circuit.
    EXPECT(!MfNuzlocke_IsCemeteryLocked(FALSE));
}

static void MfNuzlockeTest_MakeFaintedPartyMon(struct Pokemon *mon, enum Species species)
{
    u16 hp = 0;
    CreateMon(mon, species, 5, 32, OTID_STRUCT_PRESET(0));
    SetMonData(mon, MON_DATA_HP, &hp);
}

TEST("MF: nuzlocke plan fainted party marks only HP0 non-eggs")
{
    struct Pokemon party[PARTY_SIZE];
    struct MfNuzlockeFaintPlan plan;
    u8 i;
    u16 hpAlive = 10;

    for (i = 0; i < PARTY_SIZE; i++)
        ZeroMonData(&party[i]);

    MfNuzlockeTest_MakeFaintedPartyMon(&party[0], SPECIES_BULBASAUR);
    CreateMon(&party[1], SPECIES_CHARMANDER, 5, 32, OTID_STRUCT_PRESET(1));
    SetMonData(&party[1], MON_DATA_HP, &hpAlive);
    MfNuzlockeTest_MakeFaintedPartyMon(&party[2], SPECIES_SQUIRTLE);

    MfNuzlocke_PlanFaintedPartyFrom(party, MF_NUZLOCKE_FAINT_RELEASE, &plan);
    EXPECT_EQ(plan.count, 2);
    EXPECT_EQ(plan.fate, MF_NUZLOCKE_FAINT_RELEASE);
    EXPECT(plan.slotMask & (1 << 0));
    EXPECT(!(plan.slotMask & (1 << 1)));
    EXPECT(plan.slotMask & (1 << 2));

    MfNuzlocke_PlanFaintedPartyFrom(party, MF_NUZLOCKE_FAINT_SKIP, &plan);
    EXPECT_EQ(plan.count, 0);
    EXPECT_EQ(plan.slotMask, 0);
}

TEST("MF: nuzlocke release path zeros a fainted party slot")
{
    u16 hp = 0;
    struct Pokemon *mon = &gParties[B_TRAINER_PLAYER][0];
    u8 i;

    for (i = 0; i < PARTY_SIZE; i++)
        ZeroMonData(&gParties[B_TRAINER_PLAYER][i]);

    CreateMon(mon, SPECIES_PIKACHU, 5, 32, OTID_STRUCT_PRESET(2));
    SetMonData(mon, MON_DATA_HP, &hp);
    EXPECT(GetMonData(mon, MON_DATA_SANITY_HAS_SPECIES));

    MfNuzlocke_SetFaintDryRun(FALSE);
    MfNuzlocke_DeletePartyMon(0, MF_NUZLOCKE_FAINT_RELEASE);
    EXPECT(!GetMonData(mon, MON_DATA_SANITY_HAS_SPECIES));
    EXPECT_EQ(GetMonData(mon, MON_DATA_SPECIES), SPECIES_NONE);
}

TEST("MF: nuzlocke last-Pokémon release empties the party")
{
    u16 hp = 0;
    u8 i;
    struct MfNuzlockeFaintPlan plan;

    for (i = 0; i < PARTY_SIZE; i++)
        ZeroMonData(&gParties[B_TRAINER_PLAYER][i]);

    CreateMon(&gParties[B_TRAINER_PLAYER][0], SPECIES_EEVEE, 5, 32, OTID_STRUCT_PRESET(3));
    SetMonData(&gParties[B_TRAINER_PLAYER][0], MON_DATA_HP, &hp);
    gPartiesCount[B_TRAINER_PLAYER] = 1;

    MfNuzlocke_PlanFaintedPartyFrom(gParties[B_TRAINER_PLAYER], MF_NUZLOCKE_FAINT_RELEASE, &plan);
    EXPECT_EQ(plan.count, 1);
    EXPECT(plan.slotMask & 1);

    MfNuzlocke_SetFaintDryRun(FALSE);
    MfNuzlocke_DeletePartyMon(0, MF_NUZLOCKE_FAINT_RELEASE);
    CompactPartySlots();
    CalculatePlayerPartyCount();

    EXPECT_EQ(CalculatePlayerPartyCount(), 0);
    EXPECT_EQ(GetMonData(&gParties[B_TRAINER_PLAYER][0], MON_DATA_SPECIES), SPECIES_NONE);
}

TEST("MF: nuzlocke cemetery path marks dead then clears party slot")
{
    u16 hp = 0;
    u8 dead;
    u8 i;
    struct Pokemon *mon = &gParties[B_TRAINER_PLAYER][0];

    for (i = 0; i < PARTY_SIZE; i++)
        ZeroMonData(&gParties[B_TRAINER_PLAYER][i]);
    ResetPokemonStorageSystem();

    CreateMon(mon, SPECIES_MEOWTH, 5, 32, OTID_STRUCT_PRESET(4));
    SetMonData(mon, MON_DATA_HP, &hp);
    EXPECT(!GetMonData(mon, MON_DATA_MF_NUZLOCKE_DEAD));

    MfNuzlocke_SetFaintDryRun(FALSE);
    MfNuzlocke_DeletePartyMon(0, MF_NUZLOCKE_FAINT_CEMETERY);

    // Party slot purged.
    EXPECT_EQ(GetMonData(mon, MON_DATA_SPECIES), SPECIES_NONE);

    // Cemetery copy lives in PC with the dead mark.
    dead = GetBoxMonDataAt(0, 0, MON_DATA_MF_NUZLOCKE_DEAD);
    EXPECT(dead);
    EXPECT_EQ(GetBoxMonDataAt(0, 0, MON_DATA_SPECIES), SPECIES_MEOWTH);
}

TEST("MF: nuzlocke dry-run does not delete party mon")
{
    u16 hp = 0;
    u8 i;
    struct Pokemon *mon = &gParties[B_TRAINER_PLAYER][0];

    for (i = 0; i < PARTY_SIZE; i++)
        ZeroMonData(&gParties[B_TRAINER_PLAYER][i]);

    CreateMon(mon, SPECIES_ABRA, 5, 32, OTID_STRUCT_PRESET(5));
    SetMonData(mon, MON_DATA_HP, &hp);

    MfNuzlocke_SetFaintDryRun(TRUE);
    MfNuzlocke_DeletePartyMon(0, MF_NUZLOCKE_FAINT_RELEASE);
    EXPECT_EQ(GetMonData(mon, MON_DATA_SPECIES), SPECIES_ABRA);
    EXPECT(GetMonData(mon, MON_DATA_SANITY_HAS_SPECIES));

    MfNuzlocke_SetFaintDryRun(FALSE);
    MfNuzlocke_DeletePartyMon(0, MF_NUZLOCKE_FAINT_RELEASE);
    EXPECT_EQ(GetMonData(mon, MON_DATA_SPECIES), SPECIES_NONE);
}

TEST("MF: nuzlocke multi-slot release leaves surviving mon compacted")
{
    u16 hp0 = 0;
    u16 hp1 = 20;
    u8 i;

    for (i = 0; i < PARTY_SIZE; i++)
        ZeroMonData(&gParties[B_TRAINER_PLAYER][i]);

    CreateMon(&gParties[B_TRAINER_PLAYER][0], SPECIES_ODDISH, 5, 32, OTID_STRUCT_PRESET(6));
    SetMonData(&gParties[B_TRAINER_PLAYER][0], MON_DATA_HP, &hp0);
    CreateMon(&gParties[B_TRAINER_PLAYER][1], SPECIES_BELLSPROUT, 5, 32, OTID_STRUCT_PRESET(7));
    SetMonData(&gParties[B_TRAINER_PLAYER][1], MON_DATA_HP, &hp1);
    CreateMon(&gParties[B_TRAINER_PLAYER][2], SPECIES_GLOOM, 5, 32, OTID_STRUCT_PRESET(8));
    SetMonData(&gParties[B_TRAINER_PLAYER][2], MON_DATA_HP, &hp0);
    gPartiesCount[B_TRAINER_PLAYER] = 3;

    MfNuzlocke_SetFaintDryRun(FALSE);
    MfNuzlocke_DeletePartyMon(0, MF_NUZLOCKE_FAINT_RELEASE);
    MfNuzlocke_DeletePartyMon(2, MF_NUZLOCKE_FAINT_RELEASE);
    CompactPartySlots();
    CalculatePlayerPartyCount();

    EXPECT_EQ(CalculatePlayerPartyCount(), 1);
    EXPECT_EQ(GetMonData(&gParties[B_TRAINER_PLAYER][0], MON_DATA_SPECIES), SPECIES_BELLSPROUT);
    EXPECT_EQ(GetMonData(&gParties[B_TRAINER_PLAYER][0], MON_DATA_HP), 20);
}

// --- S37 dupes / shiny clauses ---------------------------------------------

TEST("MF: nuzlocke species-clause classifier")
{
    EXPECT_EQ(MfNuzlocke_ClassifySpeciesClause(FALSE, TRUE, TRUE), MF_NUZLOCKE_SPECIES_OK);
    EXPECT_EQ(MfNuzlocke_ClassifySpeciesClause(TRUE, FALSE, FALSE), MF_NUZLOCKE_SPECIES_OK);
    EXPECT_EQ(MfNuzlocke_ClassifySpeciesClause(TRUE, TRUE, TRUE), MF_NUZLOCKE_SPECIES_SAME);
    EXPECT_EQ(MfNuzlocke_ClassifySpeciesClause(TRUE, TRUE, FALSE), MF_NUZLOCKE_SPECIES_SAME);
    EXPECT_EQ(MfNuzlocke_ClassifySpeciesClause(TRUE, FALSE, TRUE), MF_NUZLOCKE_SPECIES_LINE);
}

TEST("MF: nuzlocke dupes prevent area consume")
{
    EXPECT(MfNuzlocke_ShouldConsumeEncounterAfterClause(FALSE));
    EXPECT(!MfNuzlocke_ShouldConsumeEncounterAfterClause(TRUE));
}

// --- S38 forced nicknaming -------------------------------------------------

TEST("MF: nuzlocke nicknaming gate")
{
    EXPECT(!MfNuzlocke_ResolveNicknamingActive(FALSE, TRUE, FALSE));
    EXPECT(!MfNuzlocke_ResolveNicknamingActive(TRUE, FALSE, FALSE));
    EXPECT(!MfNuzlocke_ResolveNicknamingActive(TRUE, TRUE, TRUE));
    EXPECT(MfNuzlocke_ResolveNicknamingActive(TRUE, TRUE, FALSE));
}

TEST("MF: nuzlocke evo-line caught walks family")
{
    // Mark Ivysaur owned → Bulbasaur / Venusaur report as line-caught.
    GetSetPokedexFlag(NATIONAL_DEX_IVYSAUR, FLAG_SET_CAUGHT);
    EXPECT(MfNuzlocke_IsSpeciesCaught(SPECIES_IVYSAUR));
    EXPECT(MfNuzlocke_IsEvoLineCaught(SPECIES_BULBASAUR));
    EXPECT(MfNuzlocke_IsEvoLineCaught(SPECIES_VENUSAUR));
    EXPECT(MfNuzlocke_IsEvoLineCaught(SPECIES_IVYSAUR));

    EXPECT_EQ(MfNuzlocke_ClassifySpeciesClause(TRUE, TRUE, TRUE), MF_NUZLOCKE_SPECIES_SAME);
    EXPECT_EQ(MfNuzlocke_ClassifySpeciesClause(TRUE,
            MfNuzlocke_IsSpeciesCaught(SPECIES_BULBASAUR),
            MfNuzlocke_IsEvoLineCaught(SPECIES_BULBASAUR)),
        MfNuzlocke_IsSpeciesCaught(SPECIES_BULBASAUR)
            ? MF_NUZLOCKE_SPECIES_SAME
            : MF_NUZLOCKE_SPECIES_LINE);
}

TEST("MF: nuzlocke all-owned still classifies as blocked")
{
    // "Every species owned" → every encounter is SAME or LINE; no special escape hatch.
    EXPECT_EQ(MfNuzlocke_ClassifySpeciesClause(TRUE, TRUE, TRUE), MF_NUZLOCKE_SPECIES_SAME);
    EXPECT_EQ(MfNuzlocke_ClassifySpeciesClause(TRUE, FALSE, TRUE), MF_NUZLOCKE_SPECIES_LINE);
    EXPECT(!MfNuzlocke_ShouldConsumeEncounterAfterClause(TRUE));
}

// --- S39 difficulty tiers --------------------------------------------------

TEST("MF: nuzlocke Off tier bundle is empty")
{
    struct MfNuzlockeTierBundle b;

    MfNuzlocke_FillTierBundle(MF_NUZLOCKE_OFF, &b);
    EXPECT(!b.nuzlocke);
    EXPECT(!b.easy);
    EXPECT(!b.hardcore);
    EXPECT(!b.areaLock);
    EXPECT(!b.faintHandling);
    EXPECT(!b.clausesEditable);
    EXPECT(!b.endRunOnWhiteOut);
    EXPECT(!b.forceBattleStyleSet);
    EXPECT(!b.seedNoItemPlayer);
    EXPECT_EQ(b.seedLevelCapIfOff, 0);
}

TEST("MF: nuzlocke Easy mini-mode bundle is faint-only")
{
    struct MfNuzlockeTierBundle b;

    MfNuzlocke_FillTierBundle(MF_NUZLOCKE_EASY, &b);
    EXPECT(!b.nuzlocke);
    EXPECT(b.easy);
    EXPECT(!b.hardcore);
    EXPECT(!b.areaLock);
    EXPECT(b.faintHandling);
    EXPECT(!b.clausesEditable);
    EXPECT(!b.endRunOnWhiteOut);
    EXPECT(!b.forceBattleStyleSet);
    EXPECT(!b.seedNoItemPlayer);
    EXPECT_EQ(b.seedLevelCapIfOff, 0);
}

TEST("MF: nuzlocke Normal tier bundle")
{
    struct MfNuzlockeTierBundle b;

    MfNuzlocke_FillTierBundle(MF_NUZLOCKE_NORMAL, &b);
    EXPECT(b.nuzlocke);
    EXPECT(!b.easy);
    EXPECT(!b.hardcore);
    EXPECT(b.areaLock);
    EXPECT(b.faintHandling);
    EXPECT(b.clausesEditable);
    EXPECT(!b.endRunOnWhiteOut);
    EXPECT(!b.forceBattleStyleSet);
    EXPECT(!b.seedNoItemPlayer);
    EXPECT_EQ(b.seedLevelCapIfOff, 0);
}

TEST("MF: nuzlocke Hardcore tier bundle is Normal plus extras")
{
    struct MfNuzlockeTierBundle b;

    MfNuzlocke_FillTierBundle(MF_NUZLOCKE_HARDCORE, &b);
    EXPECT(b.nuzlocke);
    EXPECT(!b.easy);
    EXPECT(b.hardcore);
    EXPECT(b.areaLock);
    EXPECT(b.faintHandling);
    EXPECT(b.clausesEditable);
    EXPECT(b.endRunOnWhiteOut);
    EXPECT(b.forceBattleStyleSet);
    EXPECT(b.seedNoItemPlayer);
    EXPECT_EQ(b.seedLevelCapIfOff, MF_NUZLOCKE_HARDCORE_SEED_LEVEL_CAP);
}

TEST("MF: nuzlocke IsActive gate matches ME")
{
    EXPECT(!MfNuzlocke_ResolveIsActive(FALSE, TRUE, TRUE, FALSE));
    EXPECT(!MfNuzlocke_ResolveIsActive(TRUE, FALSE, TRUE, FALSE));
    EXPECT(!MfNuzlocke_ResolveIsActive(TRUE, TRUE, FALSE, FALSE));
    EXPECT(!MfNuzlocke_ResolveIsActive(TRUE, TRUE, TRUE, TRUE));
    EXPECT(MfNuzlocke_ResolveIsActive(TRUE, TRUE, TRUE, FALSE));
}

TEST("MF: nuzlocke Hardcore end-run whiteout gate")
{
    EXPECT(!MfNuzlocke_ResolveEndRunOnWhiteOut(FALSE, TRUE, FALSE));
    EXPECT(!MfNuzlocke_ResolveEndRunOnWhiteOut(TRUE, FALSE, FALSE));
    EXPECT(!MfNuzlocke_ResolveEndRunOnWhiteOut(TRUE, TRUE, TRUE));
    EXPECT(MfNuzlocke_ResolveEndRunOnWhiteOut(TRUE, TRUE, FALSE));
}

TEST("MF: nuzlocke Hardcore difficulty seeds")
{
    struct ModernRules rules;

    MfRules_ResetToEmpty(&rules);
    EXPECT_EQ((u32)rules.levelCap, (u32)0);
    EXPECT_EQ((u32)rules.noItemPlayer, (u32)FALSE);

    MfNuzlocke_ApplyHardcoreDifficultySeeds(&rules);
    EXPECT_EQ((u32)rules.levelCap, (u32)MF_NUZLOCKE_HARDCORE_SEED_LEVEL_CAP);
    EXPECT_EQ((u32)rules.noItemPlayer, (u32)TRUE);

    rules.levelCap = 2;
    rules.noItemPlayer = FALSE;
    MfNuzlocke_ApplyHardcoreDifficultySeeds(&rules);
    EXPECT_EQ((u32)rules.levelCap, (u32)2);
    EXPECT_EQ((u32)rules.noItemPlayer, (u32)TRUE);
}
