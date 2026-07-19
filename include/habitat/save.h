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
struct HabitatSave
{
    u8 spotStates[HABITAT_SPOT_COUNT];
    u8 talkCounters[HABITAT_TALK_COUNTER_COUNT];
    u8 placedCounters[HABITAT_PLACED_COUNTER_COUNT];
};

u8 Habitat_GetSpotState(u16 spotId);
void Habitat_SetSpotState(u16 spotId, u8 state);  // ratchet: never lowers
u8   Habitat_GetSpotLocalFlags(u16 spotId);
void Habitat_AddSpotLocalFlags(u16 spotId, u8 flags);  // OR-in, 4-bit masked
u8   Habitat_GetTalkCount(u16 spotId);                 // 0 if spot has no slot
void Habitat_IncrementTalkCount(u16 spotId);           // saturating; no-op without slot
u8   Habitat_GetPlacedCount(u16 spotId);
void Habitat_AddPlacedCount(u16 spotId, u8 n);         // saturating; no-op without slot

#endif // GUARD_HABITAT_SAVE_H
