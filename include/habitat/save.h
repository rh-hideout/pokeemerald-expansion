#ifndef GUARD_HABITAT_SAVE_H
#define GUARD_HABITAT_SAVE_H

#include "config/habitat.h"

// Persistent habitat state. Lives in SaveBlock3 (see global.h); the save
// engine chunks it across sector spare bytes automatically and
// save.c static-asserts the total fits. Layout per spec §5:
// spotStates[i] packs 2b state | 2b hint stage | 4b spot-local flags,
// so all-zero == every spot DORMANT with nothing revealed.
// talk/placed counters exist only for spots listed in the slot maps in
// spot_state.c (§5: "only spots that need >15 counts get a real counter").
// A registered individual (spec §5: 4 bytes). Overflow beyond the cap is
// "befriended but non-individualized" — conditions run off dex caught flags,
// so overflow residents still count for them.
struct HabitatResident
{
    u16 species;
    u8 personalitySeed;   // dialogue pool selector (format open, spec §8)
    u8 assignment;        // Grove work assignment (phase 4); 0 = unassigned
};

// A Grove berry plot (§5: 8 bytes). berryItem is fixed at assignment from
// the worker's primary type (§4 rule 1); workers are registry indices
// (0xFF = none). Growth accrues in whole hours, event-driven only.
struct HabitatPlot
{
    u16 berryItem;
    u8 growthStage;      // 0..HABITAT_PLOT_STAGE_MATURE
    u8 worker1, worker2; // resident registry indices; 0xFF = empty
    u8 flags;            // bit0 reserved (mutation, §5)
    u16 hoursProgress;
};

struct HabitatSave
{
    u8 spotStates[HABITAT_SPOT_COUNT];
    u8 talkCounters[HABITAT_TALK_COUNTER_COUNT];
    u8 placedCounters[HABITAT_PLACED_COUNTER_COUNT];
    struct HabitatResident residents[HABITAT_RESIDENT_COUNT];
    struct HabitatPlot plots[HABITAT_PLOT_COUNT];
    u32 lastGrowthMinutes;  // RTC minutes at last growth credit (offline reconcile)
};

u8 Habitat_GetSpotState(u16 spotId);
void Habitat_SetSpotState(u16 spotId, u8 state);  // ratchet: never lowers
u8   Habitat_GetSpotLocalFlags(u16 spotId);
void Habitat_AddSpotLocalFlags(u16 spotId, u8 flags);  // OR-in, 4-bit masked
u8   Habitat_GetTalkCount(u16 spotId);                 // 0 if spot has no slot
void Habitat_IncrementTalkCount(u16 spotId);           // saturating; no-op without slot
u8   Habitat_GetPlacedCount(u16 spotId, u8 condIndex); // per ITEM_PLACED condition
void Habitat_AddPlacedCount(u16 spotId, u8 condIndex, u8 n);  // saturating; no-op without slot

// Resident registry (src/habitat/residents.c).
u32 Habitat_ResidentCount(void);
const struct HabitatResident *Habitat_GetResident(u32 index);  // NULL if empty slot
s32 Habitat_TryAddResident(u16 species);   // index, or -1 at the individual cap
s32 Habitat_FindResidentBySpecies(u16 species);  // first index, or -1

// Grove assignment & plots (src/habitat/grove.c). assignment: 0 = home,
// 1..HABITAT_PLOT_COUNT = working that plot. "Out" == assignment != 0.
bool32 Habitat_ResidentIsOut(u32 residentIdx);
u32 Habitat_OutCount(void);
bool32 Habitat_AssignResidentToPlot(u32 residentIdx, u32 plotIdx);  // six-out + slot checks
void Habitat_SendResidentHome(u32 residentIdx);
struct HabitatPlot *Habitat_GetPlot(u32 plotIdx);
u16 Habitat_BerryForSpecies(u16 species);  // §4 type-berry table, primary type
void Habitat_TickPlots(u32 hours);         // credit worker-tended plots
void Habitat_ReconcileGrowthFromRtc(void); // map-load offline catch-up
u32 Habitat_HarvestPlot(u32 plotIdx);      // -> berries added to bag (0 if not mature)

#endif // GUARD_HABITAT_SAVE_H
