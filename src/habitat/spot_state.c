// Accessors over HabitatSave — the only code that touches its raw bytes.
// spotStates[i]: bits 0–1 state, bits 2–3 hint stage (ratchets with state,
// reserved for finer staged-reveal control later), bits 4–7 local flags.
#include "global.h"
#include "habitat/save.h"
#include "habitat/spots.h"

#undef Habitat_GetPlacedCount
#undef Habitat_AddPlacedCount

#define STATE_MASK      0x03
#define HINT_SHIFT      2
#define HINT_MASK       0x0C
#define LOCAL_SHIFT     4
#define LOCAL_MASK      0xF0

// Counter slot maps (§5: only listed spots get a real counter).
// Terminated by 0xFFFF. Slot index == position in the list.
static const u16 sTalkCounterSpots[] = { 0xFFFF };

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

static bool32 IsValidPlacedCounterId(u16 counterId)
{
    return counterId != 0 && counterId <= HABITAT_PLACED_CONDITION_CAP;
}

u8 Habitat_GetPlacedCount(u16 counterId)
{
    const u8 *slot;

    if (!IsValidPlacedCounterId(counterId))
        return 0;
    counterId--;
    slot = &gSaveBlock3Ptr->habitat.placedConditionCounters[counterId / 2];
    return (counterId & 1) ? (*slot >> 4) : (*slot & 0x0F);
}

void Habitat_AddPlacedCount(u16 counterId, u8 count)
{
    u8 *slot;
    u8 value;

    if (!IsValidPlacedCounterId(counterId) || count > 15)
        return;
    value = Habitat_GetPlacedCount(counterId);
    value = min(15, value + count);
    counterId--;
    slot = &gSaveBlock3Ptr->habitat.placedConditionCounters[counterId / 2];
    if (counterId & 1)
        *slot = (*slot & 0x0F) | (value << 4);
    else
        *slot = (*slot & 0xF0) | value;
}

static u16 LegacyPlacedCounterId(u16 spotId, u8 conditionIndex)
{
    const struct HabitatSpot *spot = Habitat_GetSpot(spotId);

    if (spot == NULL || spot->appearConditions[conditionIndex].type != COND_ITEM_PLACED)
        return 0;
    return spot->appearConditions[conditionIndex].paramC;
}

u8 Habitat_GetPlacedCountLegacy(u16 spotId, u8 conditionIndex)
{
    return Habitat_GetPlacedCount(LegacyPlacedCounterId(spotId, conditionIndex));
}

void Habitat_AddPlacedCountLegacy(u16 spotId, u8 conditionIndex, u8 count)
{
    Habitat_AddPlacedCount(LegacyPlacedCounterId(spotId, conditionIndex), count);
}
