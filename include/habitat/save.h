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

struct HabitatSave
{
    u8 spotStates[HABITAT_SPOT_COUNT];
    u8 talkCounters[HABITAT_TALK_COUNTER_COUNT];
    u8 placedCounters[HABITAT_PLACED_COUNTER_COUNT];
    struct HabitatResident residents[HABITAT_RESIDENT_COUNT];
};

u8 Habitat_GetSpotState(u16 spotId);
void Habitat_SetSpotState(u16 spotId, u8 state);  // ratchet: never lowers
u8   Habitat_GetSpotLocalFlags(u16 spotId);
void Habitat_AddSpotLocalFlags(u16 spotId, u8 flags);  // OR-in, 4-bit masked
u8   Habitat_GetTalkCount(u16 spotId);                 // 0 if spot has no slot
void Habitat_IncrementTalkCount(u16 spotId);           // saturating; no-op without slot
u8   Habitat_GetPlacedCount(u16 spotId);
void Habitat_AddPlacedCount(u16 spotId, u8 n);         // saturating; no-op without slot

// Resident registry (src/habitat/residents.c).
u32 Habitat_ResidentCount(void);
const struct HabitatResident *Habitat_GetResident(u32 index);  // NULL if empty slot
s32 Habitat_TryAddResident(u16 species);   // index, or -1 at the individual cap
s32 Habitat_FindResidentBySpecies(u16 species);  // first index, or -1

#endif // GUARD_HABITAT_SAVE_H
