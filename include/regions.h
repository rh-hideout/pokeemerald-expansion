#ifndef GUARD_REGIONS_H
#define GUARD_REGIONS_H

#include "global.h"
#include "constants/regions.h"
#include "constants/region_map_sections.h"

enum KantoSubRegion GetKantoSubregion(u32 mapSecId);

static inline enum Region GetRegionForSectionId(u32 sectionId)
{
#if IS_HNS
    if (sectionId >= JOHTO_MAPSEC_START && sectionId <= JOHTO_MAPSEC_END)
        return REGION_JOHTO;
    if (sectionId >= KANTO_MAPSEC_START && sectionId <= KANTO_MAPSEC_END)
        return REGION_KANTO;
    return REGION_HOENN;
#else
    if (sectionId >= KANTO_MAPSEC_START && sectionId < MAPSEC_SPECIAL_AREA)
        return REGION_KANTO;
    return REGION_HOENN;
#endif
}

static inline enum Region GetCurrentRegion(void)
{
    return GetRegionForSectionId(gMapHeader.regionMapSectionId);
}

#endif // GUARD_REGIONS_H
