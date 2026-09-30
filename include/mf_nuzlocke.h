#ifndef GUARD_MF_NUZLOCKE_H
#define GUARD_MF_NUZLOCKE_H

// S35 — per-mapsec Nuzlocke encounter locking.
// S36 — faint handling (cemetery / release) + whiteout rescue.
// S37 — DUPES (species) + SHINY clauses.
// S38 — forced nicknaming on catch / hatch.
// S39 — Off/Easy/Normal/Hardcore tier bundles + IsNuzlockeActive.
// Flags live in ModernRules.nuzlockeEncounterFlags (ADR 0012 / 0036).
// Death mark is MON_DATA_MF_NUZLOCKE_DEAD on the Pokémon (ADR 0037).
// Tier semantics: ADR 0040.

#include "gba/types.h"
#include "constants/species.h"

struct Pokemon;
struct BoxPokemon;
struct ModernRules;

// Sentinel: no living non-dead box mon available for whiteout rescue.
#define MF_NUZLOCKE_NO_BOX_MON 0xFFFF

// Hardcore seeds LEVEL CAP Normal (1) when currently Off — enforced in S41.
#define MF_NUZLOCKE_HARDCORE_SEED_LEVEL_CAP 1

enum MfNuzlockeFaintFate
{
    MF_NUZLOCKE_FAINT_SKIP = 0,     // rule off / battle excluded
    MF_NUZLOCKE_FAINT_CEMETERY,     // mark dead + send to PC, then purge party
    MF_NUZLOCKE_FAINT_RELEASE,      // purge party permanently
};

// ME NuzlockeIsCaptureBlockedBySpeciesClause return codes.
enum MfNuzlockeSpeciesClauseResult
{
    MF_NUZLOCKE_SPECIES_OK = 0,     // not a dupe / clause off
    MF_NUZLOCKE_SPECIES_LINE = 1,   // another member of the evo line is owned
    MF_NUZLOCKE_SPECIES_SAME = 2,   // this exact species is already owned
};

struct MfNuzlockeFaintPlan
{
    u8 slotMask; // bit i set → party slot i would be processed
    u8 count;
    u8 fate;     // MfNuzlockeFaintFate (cemetery or release when count > 0)
};

// S39 — expected rule vector for a packed Off/Easy/Normal/Hardcore mode.
// mode uses MfNuzlockeMode values (mf_rules.h) without including that header.
struct MfNuzlockeTierBundle
{
    bool8 nuzlocke;
    bool8 easy;
    bool8 hardcore;
    bool8 areaLock;            // full Nuzlocke gates when progression allows
    bool8 faintHandling;       // Easy always; Normal/Hardcore when active
    bool8 clausesEditable;     // DUPES / SHINY / NICKNAMES / FAINTING
    bool8 endRunOnWhiteOut;    // ClearSaveData + soft reset (Hardcore)
    bool8 forceBattleStyleSet; // Options SET while Hardcore
    bool8 seedNoItemPlayer;    // ban player battle items (S43 enforces)
    u8 seedLevelCapIfOff;      // 0 = no seed; else LEVEL CAP when currently Off
};

// --- S39 tier bundles / IsNuzlockeActive -----------------------------------

void MfNuzlocke_FillTierBundle(u8 mode, struct MfNuzlockeTierBundle *out);
// Seed Difficulty extras when entering Hardcore (idempotent for levelCap>0).
void MfNuzlocke_ApplyHardcoreDifficultySeeds(struct ModernRules *r);

// Pure gate (unit-testable). ME: IsNuzlockeActive.
bool32 MfNuzlocke_ResolveIsActive(bool8 nuzlocke, bool32 hasStarter, bool32 hasPokedex, bool32 gameClear);
bool32 MfNuzlocke_IsActive(void); // ME IsNuzlockeActive equivalent

bool32 MfNuzlocke_ResolveEndRunOnWhiteOut(bool8 hardcore, bool32 nuzlockeActive, bool32 gameClear);
bool32 MfNuzlocke_ShouldEndRunOnWhiteOut(void);
bool32 MfNuzlocke_ForcesSetBattleStyle(void);

// --- S35 encounter flags ---------------------------------------------------

bool8 MfNuzlockeFlagGetFrom(const u8 *flags, u16 mapsec);
void MfNuzlockeFlagSetIn(u8 *flags, u16 mapsec);
void MfNuzlockeFlagClearIn(u8 *flags, u16 mapsec);
u16 MfNuzlockeCountUsedFrom(const u8 *flags);

bool8 MfNuzlockeFlagGet(u16 mapsec);
void MfNuzlockeFlagSet(u16 mapsec);
void MfNuzlockeFlagClear(u16 mapsec);
u16 MfNuzlockeCountUsedAreas(void);

u16 MfNuzlocke_GetCurrentMapsec(void);
bool32 MfNuzlocke_IsEncounterLockActive(void);
bool32 MfNuzlocke_WildBattleConsumesEncounter(u32 battleTypeFlags);
bool32 MfNuzlocke_IsAreaCaptureBlocked(void);
bool32 MfNuzlocke_ShouldShowFirstEncounterIcon(void);
void MfNuzlocke_OnWildBattleEnd(u32 battleTypeFlags);
void MfNuzlocke_DebugDumpUsedAreas(void);

// --- S38 forced nicknaming -------------------------------------------------

// Pure gate (unit-testable). ME: IsNuzlockeNicknamingActive.
bool32 MfNuzlocke_ResolveNicknamingActive(bool8 nuzlocke, bool8 nicknaming, bool32 gameClear);
bool32 MfNuzlocke_IsNicknamingActive(void);

// --- S37 dupes / shiny clauses ---------------------------------------------

// Pure classifier (unit-testable without dex / party).
enum MfNuzlockeSpeciesClauseResult MfNuzlocke_ClassifySpeciesClause(bool8 clauseEnabled, bool32 exactCaught, bool32 lineCaught);
bool32 MfNuzlocke_ShouldConsumeEncounterAfterClause(bool32 speciesClauseBlocks);

// Live dex / wild-mon helpers.
bool32 MfNuzlocke_IsSpeciesCaught(enum Species species);
bool32 MfNuzlocke_IsEvoLineCaught(enum Species species);
enum MfNuzlockeSpeciesClauseResult MfNuzlocke_GetSpeciesClauseResult(enum Species species);
bool32 MfNuzlocke_WildMonBypassesClauses(struct Pokemon *mon);
enum MfNuzlockeSpeciesClauseResult MfNuzlocke_GetActiveSpeciesClauseBlock(void);

// Cache dupe-consume skip when the wild mon is created (must precede battle-end).
void MfNuzlocke_OnWildMonCreated(void);

// --- S36 faint handling ----------------------------------------------------

// Pure helpers (unit-testable without a live save / party).
enum MfNuzlockeFaintFate MfNuzlocke_ResolveFaintFate(bool8 nuzlocke, bool8 easy, bool8 deletion, bool8 nuzlockeRuntimeActive);
bool32 MfNuzlocke_BattleAllowsFaintHandling(u32 battleTypeFlags);
bool32 MfNuzlocke_PartySlotIsFaintedVictim(bool32 hasSpecies, bool32 isEgg, u32 hp);
bool32 MfNuzlocke_BoxSlotIsUsableReplacement(bool32 hasSpecies, bool32 isEgg, bool32 isDead);
void MfNuzlocke_PlanFaintedPartyFrom(struct Pokemon *party, enum MfNuzlockeFaintFate fate, struct MfNuzlockeFaintPlan *out);

// Live-save wrappers.
bool32 MfNuzlocke_IsFaintHandlingActive(void);
enum MfNuzlockeFaintFate MfNuzlocke_GetActiveFaintFate(void);
bool32 MfNuzlocke_IsMonDead(struct Pokemon *mon);
bool32 MfNuzlocke_IsBoxMonDead(struct BoxPokemon *boxMon);
// True while a dead mon must stay locked out of the party (until game clear).
bool32 MfNuzlocke_IsCemeteryLocked(bool32 isDead);

void MfNuzlocke_DeletePartyMon(u8 position, enum MfNuzlockeFaintFate fate);
void MfNuzlocke_DeleteFaintedPartyPokemon(void);
void MfNuzlocke_OnBattleEnd(u32 battleTypeFlags);

// Whiteout: find/move first living non-dead box mon; soft-reset if none.
u16 MfNuzlocke_FindFirstLivingBoxIndex(void);
void MfNuzlocke_MoveFirstLivingBoxPokemon(void);
void MfNuzlocke_OnWhiteOut(void);

// Debug dry-run: log planned deletions without mutating party/PC.
bool32 MfNuzlocke_GetFaintDryRun(void);
void MfNuzlocke_SetFaintDryRun(bool32 enabled);
void MfNuzlocke_DebugDumpFaintPlan(void);

#endif // GUARD_MF_NUZLOCKE_H
