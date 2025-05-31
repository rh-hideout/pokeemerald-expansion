#ifndef GUARD_POKEDEX_H
#define GUARD_POKEDEX_H

extern u8 gUnusedPokedexU8;
extern void (*gPokedexVBlankCB)(void);

void ResetPokedex(void);
u16 GetNationalPokedexCount(u8 caseID);
u16 GetHoennPokedexCount(u8 caseID);
u8 DisplayCaughtMonDexPage(u16 species, bool32 isShiny, u32 personality);
s8 GetSetPokedexFlag(u16 nationalDexNo, u8 caseID);
void DrawFootprint(u8 windowId, u16 species);
u16 CreateMonSpriteFromNationalDexNumber(u16 nationalNum, s16 x, s16 y, u16 paletteSlot);
bool16 HasAllHoennMons(void);
void ResetPokedexScrollPositions(void);
bool16 HasAllMons(void);
void CB2_OpenPokedex(void);
void PrintMonMeasurements(u16 species, u32 owned);
u8* ConvertMonHeightToString(u32 height);
u8* ConvertMonWeightToString(u32 weight);

#endif // GUARD_POKEDEX_H
