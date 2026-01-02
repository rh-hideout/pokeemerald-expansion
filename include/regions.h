#ifndef GUARD_REGIONS_H
#define GUARD_REGIONS_H

#include "global.h"
#include "strings.h"
#include "constants/regions.h"
#include "constants/region_map_sections.h"

static inline enum Region GetCurrentRegion(void)
{
    return gMapHeader.region;
}

static inline const u8 *GetCurrentRegionName(void)
{
    switch (GetCurrentRegion())
    {
    case REGION_HOENN:
        return gText_Hoenn;
    case REGION_KANTO:
        return gText_Kanto;
    case REGION_JOHTO:
        return gText_Johto;
    case REGION_SINNOH:
        return gText_Sinnoh;
    case REGION_UNOVA:
        return gText_Unova;
    case REGION_KALOS:
        return gText_Kalos;
    case REGION_ALOLA:
        return gText_Alola;
    case REGION_GALAR:
        return gText_Galar;
    case REGION_HISUI:
        return gText_Hisui;
    case REGION_PALDEA:
        return gText_Paldea;
    case REGION_NONE:
    case REGIONS_COUNT:
        return gText_RegionDefault;
    }
    return gText_Hoenn;
}

#endif // GUARD_REGIONS_H
