#ifndef GUARD_POKEDEX_AREA_REGION_MAP_H
#define GUARD_POKEDEX_AREA_REGION_MAP_H

struct PokedexAreaMapTemplate
{
    u32 bg:2;
    u32 offset:8;
    u32 mode:2;
    u32 unk:20; // never read
};

void LoadPokedexAreaMapGfx(const struct PokedexAreaMapTemplate *);
bool32 TryShowPokedexAreaMap(void);
void PokedexAreaMapChangeBgY(u32);
void FreePokedexAreaMapBgNum(void);
void LoadAreaScreenAfterTimeChange(u8 taskId);

#endif // GUARD_POKEDEX_AREA_REGION_MAP_H
