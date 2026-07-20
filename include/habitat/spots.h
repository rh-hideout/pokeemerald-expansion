#ifndef GUARD_HABITAT_SPOTS_H
#define GUARD_HABITAT_SPOTS_H

#include "global.h"
#include "habitat/conditions.h"
#include "habitat/roles.h"

// Spot state machine per spec §2 — transitions are MONOTONIC (ACTIVE
// "persists indefinitely"; lapsed appear conditions never regress a spot).
// State values live in constants/habitat.h so event scripts can switch on
// them; they are the 2-bit encoding stored in HabitatSave.spotStates.
#include "constants/habitat.h"

// Engine flags on the spot definition (not designer-authored semantics).
// (bit 0 was STAY_AMBIENT; dissolved by §3 home-by-default, 2026-07-19 —
// befriended residents render at their spot unless out at the Grove.)

struct HabitatZone
{
    u8 zoneId;                              // 0 terminates the table
    u8 berryTreeIdFirst, berryTreeIdLast;   // COND_BERRY_MATURE zone filter (inclusive; 0,0 = none)
};

struct HabitatSpot
{
    // ---- spec §2 authored fields (designer surface — do not reorder) ----
    u16 spotId;                                     // 0xFFFF terminates the table
    u16 species;                                    // SPECIES_*
    u8 tier;                                        // 1–4
    u8 zoneId;
    const struct HabitatCondition *appearConditions;
    const struct HabitatCondition *befriendConditions;
    const u8 *hintDormant;                          // vague flavor
    const u8 *hintStirring;                         // partial reveal
    const u8 *hintActive;                           // full befriend checklist
    u8 workerRole;                                  // enum HabitatWorkerRole
    const u8 *personalityId;                        // dialogue pool key (phase 3; NULL ok)
    // ---- engine bindings ----
    u16 hideFlag;                                   // object event flag: set = hidden (not ACTIVE)
    u8 mapGroup, mapNum, localId;                   // bound overworld object event
    u8 engineFlags;                                 // HABITAT_SPOTDEF_*
};

extern const struct HabitatSpot gHabitatSpots[];
extern const struct HabitatZone gHabitatZones[];

const struct HabitatSpot *Habitat_GetSpot(u16 spotId);
const struct HabitatSpot *Habitat_GetSpotByObject(u8 mapGroup, u8 mapNum, u8 localId);
const struct HabitatZone *Habitat_GetZone(u8 zoneId);

// Resident and condition truth read the active authored spot table. Tests can
// temporarily substitute a small table to exercise identity edge cases while
// production always uses gHabitatSpots.
const struct HabitatSpot *Habitat_GetSpotTable(void);
#if TESTING
void Habitat_SetSpotTableForTest(const struct HabitatSpot *spots);
#endif

// Spot manager (state machine + object visibility).
void Habitat_RecomputeSpot(const struct HabitatSpot *spot);
void Habitat_RecomputeCurrentMapSpots(void);
void Habitat_SyncSpotObjectFlag(const struct HabitatSpot *spot);
void Habitat_CompleteBefriendById(u16 spotId);

// Script specials (data/scripts/habitat_spot.inc, habitat_grove.inc).
void Habitat_OnInspectSpot(void);
void Habitat_OnInspectSpotById(void);
u16 Habitat_GetInteractionSpotId(void);
u16 Habitat_TryOffer(void);
u16 Habitat_TryPlaceItem(void);
void Habitat_PrepareGroveWorkers(void);
void Habitat_SyncGroveWorkersLive(void);
u16 Habitat_OnTalkWorker(void);
u16 Habitat_SendTalkedWorkerHome(void);
u16 Habitat_OnInspectPlot(void);
u16 Habitat_TryHarvestPlot(void);
u16 Habitat_CanRecruitToGrove(void);
void Habitat_TryRecruitToGrove(void);
#endif // GUARD_HABITAT_SPOTS_H
