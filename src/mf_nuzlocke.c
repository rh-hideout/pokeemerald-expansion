#include "global.h"
#include "daycare.h"
#include "event_data.h"
#include "item.h"
#include "main.h"
#include "mf_nuzlocke.h"
#include "mf_rules.h"
#include "overworld.h"
#include "party_menu.h"
#include "pokedex.h"
#include "pokemon.h"
#include "pokemon_storage_system.h"
#include "region_map.h"
#include "string_util.h"
#include "constants/battle.h"
#include "constants/flags.h"
#include "constants/items.h"
#include "constants/party_menu.h"
#include "constants/region_map_sections.h"
#include "gba/isagbprint.h"

#if MF_NUZLOCKE && MF_RULES_ENGINE
static bool8 sMfNuzlockeFaintDryRun;
// S37: set in OnWildMonCreated; if TRUE, battle-end must not consume the area
// (dupe under DUPES CLAUSE). Cached so a successful catch can't flip the check
// after the species is written to the Pokédex.
static bool8 sMfNuzlockeDupesPreventConsume;
#endif

// ---------------------------------------------------------------------------
// S35 — encounter flags
// ---------------------------------------------------------------------------

bool8 MfNuzlockeFlagGetFrom(const u8 *flags, u16 mapsec)
{
    if (flags == NULL || mapsec >= MAPSEC_COUNT)
        return FALSE;
    return (flags[mapsec / 8] >> (mapsec & 7)) & 1;
}

void MfNuzlockeFlagSetIn(u8 *flags, u16 mapsec)
{
    if (flags == NULL || mapsec >= MAPSEC_COUNT)
        return;
    flags[mapsec / 8] |= (u8)(1 << (mapsec & 7));
}

void MfNuzlockeFlagClearIn(u8 *flags, u16 mapsec)
{
    if (flags == NULL || mapsec >= MAPSEC_COUNT)
        return;
    flags[mapsec / 8] &= (u8)~(1 << (mapsec & 7));
}

u16 MfNuzlockeCountUsedFrom(const u8 *flags)
{
    u16 mapsec;
    u16 count = 0;

    if (flags == NULL)
        return 0;

    for (mapsec = 0; mapsec < MAPSEC_COUNT; mapsec++)
    {
        if (MfNuzlockeFlagGetFrom(flags, mapsec))
            count++;
    }
    return count;
}

bool8 MfNuzlockeFlagGet(u16 mapsec)
{
    return MfNuzlockeFlagGetFrom(MfRules_GetActiveRules()->nuzlockeEncounterFlags, mapsec);
}

void MfNuzlockeFlagSet(u16 mapsec)
{
#if MF_RULES_ENGINE
    MfNuzlockeFlagSetIn(MfRules_GetSaveRules()->nuzlockeEncounterFlags, mapsec);
#else
    (void)mapsec;
#endif
}

void MfNuzlockeFlagClear(u16 mapsec)
{
#if MF_RULES_ENGINE
    MfNuzlockeFlagClearIn(MfRules_GetSaveRules()->nuzlockeEncounterFlags, mapsec);
#else
    (void)mapsec;
#endif
}

u16 MfNuzlockeCountUsedAreas(void)
{
    return MfNuzlockeCountUsedFrom(MfRules_GetActiveRules()->nuzlockeEncounterFlags);
}

u16 MfNuzlocke_GetCurrentMapsec(void)
{
    // FR Kanto Safari is one MAPSEC_KANTO_SAFARI_ZONE for all zones (unlike
    // ME's Hoenn per-area split). Use the live map header section as-is.
    return GetCurrentRegionMapSectionId();
}

bool32 MfNuzlocke_IsEncounterLockActive(void)
{
#if !MF_NUZLOCKE || !MF_RULES_ENGINE
    return FALSE;
#else
    // Easy mini-mode sets nuzlockeEasy only — no area lock (ADR 0022 / 0036).
    if (!MfRules_IsNuzlocke())
        return FALSE;
    if (!FlagGet(FLAG_SYS_POKEMON_GET))
        return FALSE;
    // ME gates on FLAG_ADVENTURE_STARTED (Pokédex). On FRLG that symbol is a
    // stub (= 0); FlagGet(0) is always FALSE — use FLAG_SYS_POKEDEX_GET.
#if IS_FRLG
    if (!FlagGet(FLAG_SYS_POKEDEX_GET))
        return FALSE;
#else
    if (!FlagGet(FLAG_ADVENTURE_STARTED))
        return FALSE;
#endif
    // ME stops after champion; FR uses game-clear (beat Elite Four).
    if (FlagGet(FLAG_SYS_GAME_CLEAR))
        return FALSE;
    return TRUE;
#endif
}

bool32 MfNuzlocke_WildBattleConsumesEncounter(u32 battleTypeFlags)
{
    // Mirror ME's end-of-battle mask: trainers, tutorial, legendaries, and
    // link/frontier do not consume. Script gifts / fossils / starter never
    // reach this path. Statics that use BATTLE_TYPE_LEGENDARY are excluded.
    if (battleTypeFlags & (BATTLE_TYPE_TRAINER
                         | BATTLE_TYPE_FIRST_BATTLE
                         | BATTLE_TYPE_LINK
                         | BATTLE_TYPE_RECORDED_LINK
                         | BATTLE_TYPE_FRONTIER
                         | BATTLE_TYPE_EREADER_TRAINER
                         | BATTLE_TYPE_CATCH_TUTORIAL
                         | BATTLE_TYPE_LEGENDARY
                         | BATTLE_TYPE_GHOST
                         | BATTLE_TYPE_INGAME_PARTNER
                         | BATTLE_TYPE_RECORDED
                         | BATTLE_TYPE_TRAINER_HILL))
        return FALSE;

    return TRUE;
}

bool32 MfNuzlocke_IsAreaCaptureBlocked(void)
{
    if (!MfNuzlocke_IsEncounterLockActive())
        return FALSE;
    // S37 shiny clause: shinies stay catchable even in a used area.
    if (MfNuzlocke_WildMonBypassesClauses(&gParties[B_TRAINER_OPPONENT_A][0]))
        return FALSE;
    return MfNuzlockeFlagGet(MfNuzlocke_GetCurrentMapsec());
}

bool32 MfNuzlocke_ShouldShowFirstEncounterIcon(void)
{
    // ME: show red "1" when Nuzlocke is on, the area is still unused, and this
    // wild mon is not blocked by DUPES. Species-clause / monotype hide it.
    if (!MfNuzlocke_IsEncounterLockActive())
        return FALSE;
    if (MfNuzlocke_IsAreaCaptureBlocked())
        return FALSE;
    if (MfNuzlocke_GetActiveSpeciesClauseBlock() != MF_NUZLOCKE_SPECIES_OK)
        return FALSE;
    return TRUE;
}

void MfNuzlocke_OnWildBattleEnd(u32 battleTypeFlags)
{
    if (!MfNuzlocke_IsEncounterLockActive())
    {
#if MF_NUZLOCKE && MF_RULES_ENGINE
        sMfNuzlockeDupesPreventConsume = FALSE;
#endif
        return;
    }
    if (!MfNuzlocke_WildBattleConsumesEncounter(battleTypeFlags))
    {
#if MF_NUZLOCKE && MF_RULES_ENGINE
        sMfNuzlockeDupesPreventConsume = FALSE;
#endif
        return;
    }

#if MF_NUZLOCKE && MF_RULES_ENGINE
    // ME: if (!NuzlockeIsSpeciesClauseActive) NuzlockeFlagSet(...).
    // Dupes do not consume the area (cached at CreateWildMon so a catch cannot
    // flip the check after the species is written to the Pokédex).
    if (sMfNuzlockeDupesPreventConsume)
    {
        sMfNuzlockeDupesPreventConsume = FALSE;
        return;
    }
#endif

    MfNuzlockeFlagSet(MfNuzlocke_GetCurrentMapsec());
}

void MfNuzlocke_DebugDumpUsedAreas(void)
{
#ifndef NDEBUG
    u16 mapsec;
    u16 count = 0;
    u8 name[32];

    DebugPrintfLevel(MGBA_LOG_WARN, "=== MF Nuzlocke used areas ===");
    DebugPrintfLevel(MGBA_LOG_WARN, "lockActive=%u nuzlocke=%u used=%u",
        MfNuzlocke_IsEncounterLockActive(),
        MfRules_IsNuzlocke(),
        MfNuzlockeCountUsedAreas());
    DebugPrintfLevel(MGBA_LOG_WARN, "gates: pokemon=%u pokedex=%u gameClear=%u mapsec=%u blocked=%u",
        FlagGet(FLAG_SYS_POKEMON_GET),
#if IS_FRLG
        FlagGet(FLAG_SYS_POKEDEX_GET),
#else
        FlagGet(FLAG_ADVENTURE_STARTED),
#endif
        FlagGet(FLAG_SYS_GAME_CLEAR),
        MfNuzlocke_GetCurrentMapsec(),
        MfNuzlocke_IsAreaCaptureBlocked());
    DebugPrintfLevel(MGBA_LOG_WARN, "clauses: species=%u shinyBypass=%u dupesSkipConsume=%u",
        MfNuzlocke_GetActiveSpeciesClauseBlock(),
        MfNuzlocke_WildMonBypassesClauses(&gParties[B_TRAINER_OPPONENT_A][0]),
#if MF_NUZLOCKE && MF_RULES_ENGINE
        sMfNuzlockeDupesPreventConsume
#else
        0
#endif
    );

    for (mapsec = 0; mapsec < MAPSEC_COUNT; mapsec++)
    {
        if (!MfNuzlockeFlagGet(mapsec))
            continue;
        GetMapName(name, mapsec, 0);
        DebugPrintfLevel(MGBA_LOG_WARN, "  [%u] %s", mapsec, name);
        count++;
    }
    if (count == 0)
        DebugPrintfLevel(MGBA_LOG_WARN, "  (none)");
#else
    (void)0;
#endif
}

// ---------------------------------------------------------------------------
// S37 — DUPES (species) + SHINY clauses
// ---------------------------------------------------------------------------

enum MfNuzlockeSpeciesClauseResult MfNuzlocke_ClassifySpeciesClause(bool8 clauseEnabled, bool32 exactCaught, bool32 lineCaught)
{
    if (!clauseEnabled)
        return MF_NUZLOCKE_SPECIES_OK;
    if (exactCaught)
        return MF_NUZLOCKE_SPECIES_SAME;
    if (lineCaught)
        return MF_NUZLOCKE_SPECIES_LINE;
    return MF_NUZLOCKE_SPECIES_OK;
}

bool32 MfNuzlocke_ShouldConsumeEncounterAfterClause(bool32 speciesClauseBlocks)
{
    // ME: set area flag only when species clause is inactive for this encounter.
    return !speciesClauseBlocks;
}

bool32 MfNuzlocke_IsSpeciesCaught(enum Species species)
{
    species = SanitizeSpeciesId(species);
    if (species == SPECIES_NONE)
        return FALSE;
    return GetSetPokedexFlag(SpeciesToNationalPokedexNum(species), FLAG_GET_CAUGHT);
}

static bool32 MfNuzlocke_EvoTreeHasCaught(enum Species species, u8 depth)
{
    const struct Evolution *evolutions;
    u32 i;

    if (depth > 6)
        return FALSE;

    species = SanitizeSpeciesId(species);
    if (species == SPECIES_NONE)
        return FALSE;

    if (MfNuzlocke_IsSpeciesCaught(species))
        return TRUE;

    evolutions = GetSpeciesEvolutions(species);
    if (evolutions == NULL)
        return FALSE;

    for (i = 0; evolutions[i].method != EVOLUTIONS_END; i++)
    {
        enum Species target = SanitizeSpeciesId(evolutions[i].targetSpecies);
        if (target == SPECIES_NONE || target == species)
            continue;
        if (MfNuzlocke_EvoTreeHasCaught(target, depth + 1))
            return TRUE;
    }
    return FALSE;
}

bool32 MfNuzlocke_IsEvoLineCaught(enum Species species)
{
    species = GET_BASE_SPECIES_ID(SanitizeSpeciesId(species));
    if (species == SPECIES_NONE)
        return FALSE;
    return MfNuzlocke_EvoTreeHasCaught(GetEggSpecies(species), 0);
}

enum MfNuzlockeSpeciesClauseResult MfNuzlocke_GetSpeciesClauseResult(enum Species species)
{
#if !MF_NUZLOCKE || !MF_RULES_ENGINE
    (void)species;
    return MF_NUZLOCKE_SPECIES_OK;
#else
    bool32 exact;
    bool32 line;

    if (!MfRules_HasNuzlockeSpeciesClause())
        return MF_NUZLOCKE_SPECIES_OK;
    if (!MfNuzlocke_IsEncounterLockActive())
        return MF_NUZLOCKE_SPECIES_OK;

    exact = MfNuzlocke_IsSpeciesCaught(species);
    // Exact catch implies line catch; skip the tree walk when exact is set.
    line = exact ? TRUE : MfNuzlocke_IsEvoLineCaught(species);
    return MfNuzlocke_ClassifySpeciesClause(TRUE, exact, line);
#endif
}

bool32 MfNuzlocke_WildMonBypassesClauses(struct Pokemon *mon)
{
#if !MF_NUZLOCKE || !MF_RULES_ENGINE
    (void)mon;
    return FALSE;
#else
    if (mon == NULL)
        return FALSE;
    if (!MfRules_HasNuzlockeShinyClause())
        return FALSE;
    if (!MfNuzlocke_IsEncounterLockActive())
        return FALSE;
    if (!GetMonData(mon, MON_DATA_SANITY_HAS_SPECIES))
        return FALSE;
    return IsMonShiny(mon);
#endif
}

enum MfNuzlockeSpeciesClauseResult MfNuzlocke_GetActiveSpeciesClauseBlock(void)
{
#if !MF_NUZLOCKE || !MF_RULES_ENGINE
    return MF_NUZLOCKE_SPECIES_OK;
#else
    struct Pokemon *wild = &gParties[B_TRAINER_OPPONENT_A][0];

    if (MfNuzlocke_WildMonBypassesClauses(wild))
        return MF_NUZLOCKE_SPECIES_OK;
    if (!GetMonData(wild, MON_DATA_SANITY_HAS_SPECIES))
        return MF_NUZLOCKE_SPECIES_OK;
    return MfNuzlocke_GetSpeciesClauseResult(GetMonData(wild, MON_DATA_SPECIES));
#endif
}

void MfNuzlocke_OnWildMonCreated(void)
{
#if MF_NUZLOCKE && MF_RULES_ENGINE
    sMfNuzlockeDupesPreventConsume = FALSE;
    if (!MfNuzlocke_IsEncounterLockActive())
        return;
    // Shiny clause clears the species block inside GetActiveSpeciesClauseBlock.
    if (MfNuzlocke_GetActiveSpeciesClauseBlock() != MF_NUZLOCKE_SPECIES_OK)
        sMfNuzlockeDupesPreventConsume = TRUE;
#endif
}

// ---------------------------------------------------------------------------
// S36 — faint handling (pure helpers)
// ---------------------------------------------------------------------------

enum MfNuzlockeFaintFate MfNuzlocke_ResolveFaintFate(bool8 nuzlocke, bool8 easy, bool8 deletion, bool8 nuzlockeRuntimeActive)
{
    // Easy mini-mode: always Cemetery, even without full Nuzlocke gates (ME).
    if (easy && !nuzlocke)
        return MF_NUZLOCKE_FAINT_CEMETERY;

    // Full Nuzlocke only while runtime-active (starter+Pokédex, pre-clear).
    if (!nuzlocke || !nuzlockeRuntimeActive)
        return MF_NUZLOCKE_FAINT_SKIP;

    // FAINTING: Cemetery (false) / Release (true). Easy under full Nuzlocke
    // still honors the FAINTING toggle (ME: Easy path only when !IsNuzlockeActive).
    if (deletion)
        return MF_NUZLOCKE_FAINT_RELEASE;
    return MF_NUZLOCKE_FAINT_CEMETERY;
}

bool32 MfNuzlocke_BattleAllowsFaintHandling(u32 battleTypeFlags)
{
    // ME excludes link / tutorial / frontier / partner — not trainers/wilds.
    if (battleTypeFlags & (BATTLE_TYPE_LINK
                         | BATTLE_TYPE_RECORDED_LINK
                         | BATTLE_TYPE_FIRST_BATTLE
                         | BATTLE_TYPE_CATCH_TUTORIAL
                         | BATTLE_TYPE_INGAME_PARTNER
                         | BATTLE_TYPE_FRONTIER
                         | BATTLE_TYPE_RECORDED))
        return FALSE;
    return TRUE;
}

bool32 MfNuzlocke_PartySlotIsFaintedVictim(bool32 hasSpecies, bool32 isEgg, u32 hp)
{
    if (!hasSpecies || isEgg)
        return FALSE;
    return hp == 0;
}

bool32 MfNuzlocke_BoxSlotIsUsableReplacement(bool32 hasSpecies, bool32 isEgg, bool32 isDead)
{
    return hasSpecies && !isEgg && !isDead;
}

void MfNuzlocke_PlanFaintedPartyFrom(struct Pokemon *party, enum MfNuzlockeFaintFate fate, struct MfNuzlockeFaintPlan *out)
{
    u8 i;

    out->slotMask = 0;
    out->count = 0;
    out->fate = (u8)fate;

    if (party == NULL || fate == MF_NUZLOCKE_FAINT_SKIP)
        return;

    for (i = 0; i < PARTY_SIZE; i++)
    {
        struct Pokemon *mon = &party[i];
        if (!MfNuzlocke_PartySlotIsFaintedVictim(
                GetMonData(mon, MON_DATA_SANITY_HAS_SPECIES),
                GetMonData(mon, MON_DATA_IS_EGG),
                GetMonData(mon, MON_DATA_HP)))
            continue;
        out->slotMask |= (u8)(1 << i);
        out->count++;
    }
}

// ---------------------------------------------------------------------------
// S36 — live wrappers
// ---------------------------------------------------------------------------

bool32 MfNuzlocke_IsFaintHandlingActive(void)
{
#if !MF_NUZLOCKE || !MF_RULES_ENGINE
    return FALSE;
#else
    if (MfRules_IsNuzlockeEasy() && !MfRules_IsNuzlocke())
        return TRUE;
    return MfNuzlocke_IsEncounterLockActive(); // same gates as full Nuzlocke
#endif
}

enum MfNuzlockeFaintFate MfNuzlocke_GetActiveFaintFate(void)
{
#if !MF_NUZLOCKE || !MF_RULES_ENGINE
    return MF_NUZLOCKE_FAINT_SKIP;
#else
    const struct ModernRules *r = MfRules_GetActiveRules();
    return MfNuzlocke_ResolveFaintFate(
        r->nuzlocke,
        r->nuzlockeEasy,
        r->nuzlockeDeletion,
        MfNuzlocke_IsEncounterLockActive());
#endif
}

bool32 MfNuzlocke_IsMonDead(struct Pokemon *mon)
{
    if (mon == NULL)
        return FALSE;
    return GetMonData(mon, MON_DATA_MF_NUZLOCKE_DEAD);
}

bool32 MfNuzlocke_IsBoxMonDead(struct BoxPokemon *boxMon)
{
    if (boxMon == NULL)
        return FALSE;
    return GetBoxMonData(boxMon, MON_DATA_MF_NUZLOCKE_DEAD);
}

bool32 MfNuzlocke_IsCemeteryLocked(bool32 isDead)
{
    if (!isDead)
        return FALSE;
    // ME unlocks cemetery mons after champion; FR uses game-clear.
    if (FlagGet(FLAG_SYS_GAME_CLEAR))
        return FALSE;
    return TRUE;
}

bool32 MfNuzlocke_GetFaintDryRun(void)
{
#if MF_NUZLOCKE && MF_RULES_ENGINE
    return sMfNuzlockeFaintDryRun;
#else
    return FALSE;
#endif
}

void MfNuzlocke_SetFaintDryRun(bool32 enabled)
{
#if MF_NUZLOCKE && MF_RULES_ENGINE
    sMfNuzlockeFaintDryRun = enabled ? TRUE : FALSE;
#ifndef NDEBUG
    DebugPrintfLevel(MGBA_LOG_WARN, "MF Nuzlocke faint dry-run=%u", sMfNuzlockeFaintDryRun);
#endif
#else
    (void)enabled;
#endif
}

static void MfNuzlocke_ReturnHeldItemToBag(struct Pokemon *mon)
{
    u32 monItem = GetMonData(mon, MON_DATA_HELD_ITEM);
    u16 none = ITEM_NONE;

    if (monItem != ITEM_NONE)
    {
        AddBagItem(monItem, 1);
        SetMonData(mon, MON_DATA_HELD_ITEM, &none);
    }
}

void MfNuzlocke_DeletePartyMon(u8 position, enum MfNuzlockeFaintFate fate)
{
    struct Pokemon *pokemon;
    u8 dead = TRUE;

    if (position >= PARTY_SIZE || fate == MF_NUZLOCKE_FAINT_SKIP)
        return;

    pokemon = &gParties[B_TRAINER_PLAYER][position];
    if (!GetMonData(pokemon, MON_DATA_SANITY_HAS_SPECIES))
        return;

    if (MfNuzlocke_GetFaintDryRun())
    {
#ifndef NDEBUG
        u8 nick[POKEMON_NAME_LENGTH + 1];
        GetMonData(pokemon, MON_DATA_NICKNAME, nick);
        StringGet_Nickname(nick);
        DebugPrintfLevel(MGBA_LOG_WARN,
            "MF Nuzlocke DRY-RUN: would %s party[%u] species=%u nick=%s",
            fate == MF_NUZLOCKE_FAINT_RELEASE ? "RELEASE" : "CEMETERY",
            position,
            GetMonData(pokemon, MON_DATA_SPECIES),
            nick);
#endif
        return;
    }

    if (fate == MF_NUZLOCKE_FAINT_CEMETERY)
    {
        SetMonData(pokemon, MON_DATA_MF_NUZLOCKE_DEAD, &dead);
        // ME still purges the party slot even if PC is full — mon is lost.
        CopyMonToPC(pokemon);
    }

    ZeroMonData(pokemon);
}

void MfNuzlocke_DeleteFaintedPartyPokemon(void)
{
    u8 i;
    enum MfNuzlockeFaintFate fate = MfNuzlocke_GetActiveFaintFate();
    struct MfNuzlockeFaintPlan plan;

    if (fate == MF_NUZLOCKE_FAINT_SKIP)
        return;

    MfNuzlocke_PlanFaintedPartyFrom(gParties[B_TRAINER_PLAYER], fate, &plan);
    if (plan.count == 0)
        return;

#ifndef NDEBUG
    if (MfNuzlocke_GetFaintDryRun())
    {
        DebugPrintfLevel(MGBA_LOG_WARN,
            "MF Nuzlocke DRY-RUN: %u fainted slot(s) fate=%u mask=0x%02X",
            plan.count, plan.fate, plan.slotMask);
    }
#endif

    for (i = 0; i < PARTY_SIZE; i++)
    {
        struct Pokemon *pokemon;
        if (!(plan.slotMask & (1 << i)))
            continue;

        pokemon = &gParties[B_TRAINER_PLAYER][i];
        MfNuzlocke_ReturnHeldItemToBag(pokemon);
        MfNuzlocke_DeletePartyMon(i, fate);
    }

    if (!MfNuzlocke_GetFaintDryRun())
    {
        CompactPartySlots();
        CalculatePlayerPartyCount();
    }
}

void MfNuzlocke_OnBattleEnd(u32 battleTypeFlags)
{
    if (!MfNuzlocke_IsFaintHandlingActive())
        return;
    if (!MfNuzlocke_BattleAllowsFaintHandling(battleTypeFlags))
        return;
    MfNuzlocke_DeleteFaintedPartyPokemon();
}

u16 MfNuzlocke_FindFirstLivingBoxIndex(void)
{
    u16 boxId;
    u16 boxPos;

    for (boxId = 0; boxId < TOTAL_BOXES_COUNT; boxId++)
    {
        for (boxPos = 0; boxPos < IN_BOX_COUNT; boxPos++)
        {
            struct BoxPokemon *boxMon = GetBoxedMonPtr(boxId, boxPos);
            if (MfNuzlocke_BoxSlotIsUsableReplacement(
                    GetBoxMonData(boxMon, MON_DATA_SPECIES) != SPECIES_NONE,
                    GetBoxMonData(boxMon, MON_DATA_IS_EGG),
                    GetBoxMonData(boxMon, MON_DATA_MF_NUZLOCKE_DEAD)))
            {
                return (u16)(boxId * IN_BOX_COUNT + boxPos);
            }
        }
    }
    return MF_NUZLOCKE_NO_BOX_MON;
}

void MfNuzlocke_MoveFirstLivingBoxPokemon(void)
{
    u16 position = MfNuzlocke_FindFirstLivingBoxIndex();
    u16 boxNum;
    u16 boxIndex;

    if (position == MF_NUZLOCKE_NO_BOX_MON)
        return;

    boxNum = position / IN_BOX_COUNT;
    boxIndex = position - (boxNum * IN_BOX_COUNT);
    BoxMonAtToMon(boxNum, boxIndex, &gParties[B_TRAINER_PLAYER][0]);
    ZeroBoxMonAt(boxNum, boxIndex);
    CalculatePlayerPartyCount();
}

void MfNuzlocke_OnWhiteOut(void)
{
#if !MF_NUZLOCKE || !MF_RULES_ENGINE
    return;
#else
    if (!MfNuzlocke_IsFaintHandlingActive())
        return;

    // Soft-reset when no living non-dead replacement exists (ME parity),
    // covering the empty-party whiteout after last-mon deletion.
    if (MfNuzlocke_FindFirstLivingBoxIndex() == MF_NUZLOCKE_NO_BOX_MON)
    {
#ifndef NDEBUG
        DebugPrintfLevel(MGBA_LOG_WARN, "MF Nuzlocke: no box replacement — soft reset");
#endif
        DoSoftReset();
        return;
    }

    // ME only auto-fills on full Nuzlocke; Easy would softlock with an empty
    // party. Always pull a living box mon when faint handling is active (ADR 0037).
    MfNuzlocke_MoveFirstLivingBoxPokemon();
#endif
}

void MfNuzlocke_DebugDumpFaintPlan(void)
{
#ifndef NDEBUG
    enum MfNuzlockeFaintFate fate = MfNuzlocke_GetActiveFaintFate();
    struct MfNuzlockeFaintPlan plan;
    u8 i;

    MfNuzlocke_PlanFaintedPartyFrom(gParties[B_TRAINER_PLAYER], fate, &plan);
    DebugPrintfLevel(MGBA_LOG_WARN, "=== MF Nuzlocke faint plan ===");
    DebugPrintfLevel(MGBA_LOG_WARN, "active=%u fate=%u dryRun=%u count=%u mask=0x%02X",
        MfNuzlocke_IsFaintHandlingActive(),
        fate,
        MfNuzlocke_GetFaintDryRun(),
        plan.count,
        plan.slotMask);
    for (i = 0; i < PARTY_SIZE; i++)
    {
        struct Pokemon *mon = &gParties[B_TRAINER_PLAYER][i];
        if (!GetMonData(mon, MON_DATA_SANITY_HAS_SPECIES))
            continue;
        DebugPrintfLevel(MGBA_LOG_WARN,
            "  party[%u] species=%u hp=%u/%u egg=%u dead=%u victim=%u",
            i,
            GetMonData(mon, MON_DATA_SPECIES),
            GetMonData(mon, MON_DATA_HP),
            GetMonData(mon, MON_DATA_MAX_HP),
            GetMonData(mon, MON_DATA_IS_EGG),
            GetMonData(mon, MON_DATA_MF_NUZLOCKE_DEAD),
            (plan.slotMask >> i) & 1);
    }
#else
    (void)0;
#endif
}
