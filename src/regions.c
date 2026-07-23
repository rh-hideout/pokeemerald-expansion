#include "global.h"
#include "regions.h"
#include "region_map.h"

static const u8 *sPokemonRegionNames[POKEMON_REGIONS_COUNT] =
{
    [POKEMON_REGION_NONE] = COMPOUND_STRING("???"),
    [POKEMON_REGION_KANTO] = COMPOUND_STRING("Kanto"),
    [POKEMON_REGION_JOHTO] = COMPOUND_STRING("Johto"),
    [POKEMON_REGION_HOENN] = COMPOUND_STRING("Hoenn"),
    [POKEMON_REGION_SINNOH] = COMPOUND_STRING("Sinnoh"),
    [POKEMON_REGION_UNOVA] = COMPOUND_STRING("Unova"),
    [POKEMON_REGION_KALOS] = COMPOUND_STRING("Kalos"),
    [POKEMON_REGION_ALOLA] = COMPOUND_STRING("Alola"),
    [POKEMON_REGION_GALAR] = COMPOUND_STRING("Galar"),
    [POKEMON_REGION_HISUI] = COMPOUND_STRING("Hisui"),
    [POKEMON_REGION_PALDEA] = COMPOUND_STRING("Paldea"),
};

enum PokemonRegion GetPokemonRegionForSectionId(u32 sectionId)
{
    return gMapSections[sectionId].pokemonRegion;
}

enum PokemonRegion GetCurrentPokemonRegion(void)
{
    return GetPokemonRegionForSectionId(gMapHeader.regionMapSectionId);
}

const u8 *GetPokemonRegionName(enum PokemonRegion region)
{
    assertf(region < POKEMON_REGIONS_COUNT, "Trying to get name of unknown pokemon region %d", region)
    {
        region = POKEMON_REGION_NONE;
    }
    return sPokemonRegionNames[region];
}
