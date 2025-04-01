#include "global.h"
#include "event_data.h"
#include "heal_location.h"
#include "constants/heal_locations.h"
#include "constants/maps.h"

#include "data/heal_locations.h"
#include "data/heal_locations_pkm_centre.h"

u32 GetHealLocationIndexByMap(u16 mapGroup, u16 mapNum)
{
    u32 i;

    for (i = 0; i < ARRAY_COUNT(sHealLocations); i++)
    {
        if (sHealLocations[i].group == mapGroup && sHealLocations[i].map == mapNum)
            return i + 1;
    }
    return HEAL_LOCATION_NONE;
}

const struct HealLocation *GetHealLocationByMap(u16 mapGroup, u16 mapNum)
{
    u32 index = GetHealLocationIndexByMap(mapGroup, mapNum);

    if (index == HEAL_LOCATION_NONE)
        return NULL;
    else
        return &sHealLocations[index - 1];
}

u32 GetHealLocationIndexByWarpData(struct WarpData *warp)
{
    u32 i;
    for (i = 0; i < ARRAY_COUNT(sHealLocations); i++)
    {
        if (sHealLocations[i].group == warp->mapGroup
        && sHealLocations[i].map == warp->mapNum
        && sHealLocations[i].x == warp->x
        && sHealLocations[i].y == warp->y)
            return i + 1;
    }
    return HEAL_LOCATION_NONE;
}

const struct HealLocation *GetHealLocation(u32 index)
{
    if (index == HEAL_LOCATION_NONE)
        return NULL;
    else if (index > ARRAY_COUNT(sHealLocations))
        return NULL;
    else
        return &sHealLocations[index - 1];
}

static bool32 IsLastHealLocation(u32 healLocation)
{
    const struct HealLocation *loc = GetHealLocation(healLocation);
    const struct WarpData *warpData = &gSaveBlock1Ptr->lastHealLocation;

    return warpData->mapGroup == loc->group
        && warpData->mapNum == loc->map
        && warpData->warpId == WARP_ID_NONE
        && warpData->x == loc->x
        && warpData->y == loc->y;
}

bool32 IsLastHealLocationPlayerHouse()
{
    if (IsLastHealLocation(HEAL_LOCATION_LITTLEROOT_TOWN_MAYS_HOUSE)
        || IsLastHealLocation(HEAL_LOCATION_LITTLEROOT_TOWN_MAYS_HOUSE_2F)
        || IsLastHealLocation(HEAL_LOCATION_LITTLEROOT_TOWN_BRENDANS_HOUSE)
        || IsLastHealLocation(HEAL_LOCATION_LITTLEROOT_TOWN_BRENDANS_HOUSE_2F))
        return TRUE;

    return FALSE;
}

u32 GetHealNpcLocalId(u32 healLocationId)
{
    if (healLocationId == HEAL_LOCATION_NONE || healLocationId >= HEAL_LOCATION_COUNT)
        return 0;

    return sHealNpcLocalId[healLocationId - 1];
}

void SetWhiteoutRespawnWarpAndHealerNPC(struct WarpData *warp)
{
    u32 healLocationId = GetHealLocationIndexByWarpData(&gSaveBlock1Ptr->lastHealLocation);
    u32 healNpcLocalId = GetHealNpcLocalId(healLocationId);
    struct HealLocation pkmCentreHealLocation;

    if (!healNpcLocalId)
    {
        *(warp) = gSaveBlock1Ptr->lastHealLocation;
        return;
    }

    pkmCentreHealLocation = sHealLocationsPokemonCentre[healLocationId - 1];
    warp->mapGroup = pkmCentreHealLocation.group;
    warp->mapNum = pkmCentreHealLocation.map;
    warp->warpId = WARP_ID_NONE;
    warp->x = pkmCentreHealLocation.x;
    warp->y = pkmCentreHealLocation.y;
    gSpecialVar_LastTalked = healNpcLocalId;
}
