#ifndef GUARD_MF_NUZLOCKE_H
#define GUARD_MF_NUZLOCKE_H

// S35 — per-mapsec Nuzlocke encounter locking.
// S36 — faint handling (cemetery / release) + whiteout rescue.
// Flags live in ModernRules.nuzlockeEncounterFlags (ADR 0012 / 0036).
// Death mark is MON_DATA_MF_NUZLOCKE_DEAD on the Pokémon (ADR 0037).

#include "gba/types.h"

struct Pokemon;
struct BoxPokemon;

// Sentinel: no living non-dead box mon available for whiteout rescue.
#define MF_NUZLOCKE_NO_BOX_MON 0xFFFF

enum MfNuzlockeFaintFate
{
    MF_NUZLOCKE_FAINT_SKIP = 0,     // rule off / battle excluded
    MF_NUZLOCKE_FAINT_CEMETERY,     // mark dead + send to PC, then purge party
    MF_NUZLOCKE_FAINT_RELEASE,      // purge party permanently
};

struct MfNuzlockeFaintPlan
{
    u8 slotMask; // bit i set → party slot i would be processed
    u8 count;
    u8 fate;     // MfNuzlockeFaintFate (cemetery or release when count > 0)
};

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
