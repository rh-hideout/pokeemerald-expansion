#ifndef GUARD_REGIONS_H
#define GUARD_REGIONS_H

enum PokemonRegion GetPokemonRegionForSectionId(u32 sectionId);
enum PokemonRegion GetCurrentPokemonRegion(void);

const u8 *GetPokemonRegionName(enum PokemonRegion region);

#endif // GUARD_REGIONS_H
