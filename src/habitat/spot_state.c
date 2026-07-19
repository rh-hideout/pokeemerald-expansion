// Accessors over HabitatSave — the only code that touches its raw bytes.
// spotStates[i]: bits 0–1 state, bits 2–3 hint stage (ratchets with state,
// reserved for finer staged-reveal control later), bits 4–7 local flags.
#include "global.h"
#include "habitat/save.h"
#include "habitat/spots.h"

#define STATE_MASK      0x03
#define HINT_SHIFT      2
#define HINT_MASK       0x0C
#define LOCAL_SHIFT     4
#define LOCAL_MASK      0xF0

// Counter slot maps (§5: only listed spots get a real counter).
// Terminated by 0xFFFF. Slot index == position in the list.
static const u16 sTalkCounterSpots[] = { 0xFFFF };

// Placed counters are per-(spot, ITEM_PLACED-condition-index) — bare lab
// frames (§10) need several distinct furnishings. 8 slots budgeted (§5).
struct PlacedSlot { u16 spotId; u8 condIndex; };
static const struct PlacedSlot sPlacedSlots[] = {
    { 1, 0 },  // Skitty: doll
    { 6, 0 },  // Pinsir: sap log
    { 7, 0 },  // Lab frame, furnished: element item
    { 8, 0 }, { 8, 1 },            // Lab frame 2: element + furnishing
    { 9, 0 }, { 9, 1 }, { 9, 2 },  // Lab frame 3: element + 2 furnishings
    { 0xFFFF, 0 },
};

static s32 SlotFor(const u16 *list, u16 spotId)
{
    s32 i;
    for (i = 0; list[i] != 0xFFFF; i++)
    {
        if (list[i] == spotId)
            return i;
    }
    return -1;
}

u8 Habitat_GetSpotState(u16 spotId)
{
    if (spotId >= HABITAT_SPOT_COUNT)
        return HABITAT_STATE_DORMANT;
    return gSaveBlock3Ptr->habitat.spotStates[spotId] & STATE_MASK;
}

void Habitat_SetSpotState(u16 spotId, u8 state)
{
    u8 *slot;
    if (spotId >= HABITAT_SPOT_COUNT)
        return;
    slot = &gSaveBlock3Ptr->habitat.spotStates[spotId];
    if ((u32)(*slot & STATE_MASK) >= (u32)state)
        return;  // monotonic: spec §2's "persists indefinitely"
    *slot = (*slot & ~(STATE_MASK | HINT_MASK))
          | ((u8)state & STATE_MASK)
          | (((u8)state << HINT_SHIFT) & HINT_MASK);  // hint stage ratchets with state
}

u8 Habitat_GetSpotLocalFlags(u16 spotId)
{
    if (spotId >= HABITAT_SPOT_COUNT)
        return 0;
    return gSaveBlock3Ptr->habitat.spotStates[spotId] >> LOCAL_SHIFT;
}

void Habitat_AddSpotLocalFlags(u16 spotId, u8 flags)
{
    if (spotId >= HABITAT_SPOT_COUNT)
        return;
    gSaveBlock3Ptr->habitat.spotStates[spotId] |= (flags << LOCAL_SHIFT) & LOCAL_MASK;
}

u8 Habitat_GetTalkCount(u16 spotId)
{
    s32 slot = SlotFor(sTalkCounterSpots, spotId);
    return slot < 0 ? 0 : gSaveBlock3Ptr->habitat.talkCounters[slot];
}

void Habitat_IncrementTalkCount(u16 spotId)
{
    s32 slot = SlotFor(sTalkCounterSpots, spotId);
    if (slot >= 0 && gSaveBlock3Ptr->habitat.talkCounters[slot] < 0xFF)
        gSaveBlock3Ptr->habitat.talkCounters[slot]++;
}

static s32 PlacedSlotFor(u16 spotId, u8 condIndex)
{
    s32 i;
    for (i = 0; sPlacedSlots[i].spotId != 0xFFFF; i++)
    {
        if (sPlacedSlots[i].spotId == spotId && sPlacedSlots[i].condIndex == condIndex)
            return i;
    }
    return -1;
}

u8 Habitat_GetPlacedCount(u16 spotId, u8 condIndex)
{
    s32 slot = PlacedSlotFor(spotId, condIndex);
    return slot < 0 ? 0 : gSaveBlock3Ptr->habitat.placedCounters[slot];
}

void Habitat_AddPlacedCount(u16 spotId, u8 condIndex, u8 n)
{
    s32 slot = PlacedSlotFor(spotId, condIndex);
    if (slot < 0)
        return;
    if (gSaveBlock3Ptr->habitat.placedCounters[slot] > 0xFF - n)
        gSaveBlock3Ptr->habitat.placedCounters[slot] = 0xFF;
    else
        gSaveBlock3Ptr->habitat.placedCounters[slot] += n;
}
