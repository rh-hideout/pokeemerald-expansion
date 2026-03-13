#ifndef GUARD_POKEDEX_PLUS_HGSS_H
#define GUARD_POKEDEX_PLUS_HGSS_H

void CB2_OpenPokedexPlusHGSS(void);
void Task_DisplayCaughtMonDexPageHGSS(u8);

bool32 TryOpenPokedexPage_HGSS(u8, u8);
bool32 Task_TryLoadInfoScreen_HGSS(u8);
bool32 TryInitWindows_HGSS(void);

void TryDestroyStatBars(void);
void TryDestroyStatBarsBg(void);
void TryCreateStatBars(void);
void TryCreateStatBarsDPAD(void);
bool32 TryMoveMonForInfoScreen_HGSS(struct Sprite *sprite);
bool32 TryLoadSearchMenu_HGSS(u8 taskId);
bool32 TryLoadCryScreen_HGSS(u8 taskId);
bool32 TryLoadSizeScreen_HGSS(u8 taskId);
bool32 TryLoadAreaScreen_HGSS(u8 taskId);
bool32 TryCreateMonListEntry_HGSS(u8 position, u16 b, u16 ignored);

#endif // GUARD_POKEDEX_PLUS_HGSS_H
