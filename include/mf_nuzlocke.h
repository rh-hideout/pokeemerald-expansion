#ifndef GUARD_MF_NUZLOCKE_H
#define GUARD_MF_NUZLOCKE_H

// S35 — per-mapsec Nuzlocke encounter locking. Flags live in
// ModernRules.nuzlockeEncounterFlags (ADR 0012 / 0036).

#include "gba/types.h"

// Pure bit helpers (unit-testable without a live save).
bool8 MfNuzlockeFlagGetFrom(const u8 *flags, u16 mapsec);
void MfNuzlockeFlagSetIn(u8 *flags, u16 mapsec);
void MfNuzlockeFlagClearIn(u8 *flags, u16 mapsec);
u16 MfNuzlockeCountUsedFrom(const u8 *flags);

// Save-backed wrappers (read active rules / write save rules).
bool8 MfNuzlockeFlagGet(u16 mapsec);
void MfNuzlockeFlagSet(u16 mapsec);
void MfNuzlockeFlagClear(u16 mapsec);
u16 MfNuzlockeCountUsedAreas(void);

// Current area id for locking (map header regionMapSectionId).
u16 MfNuzlocke_GetCurrentMapsec(void);

// Normal/Hardcore only; gated until starter+Pokédex, off after game clear.
bool32 MfNuzlocke_IsEncounterLockActive(void);

// True when a wild battle of this type should consume the area's encounter.
bool32 MfNuzlocke_WildBattleConsumesEncounter(u32 battleTypeFlags);

// True when balls must be refused for the current area (lock on + flag set).
bool32 MfNuzlocke_IsAreaCaptureBlocked(void);

// True when the healthbox should show ME's red "1" (catchable first encounter).
bool32 MfNuzlocke_ShouldShowFirstEncounterIcon(void);

// Call from wild-battle teardown when an encounter should consume the area.
void MfNuzlocke_OnWildBattleEnd(u32 battleTypeFlags);

// Non-release: list used mapsecs to the mGBA console.
void MfNuzlocke_DebugDumpUsedAreas(void);

#endif // GUARD_MF_NUZLOCKE_H
