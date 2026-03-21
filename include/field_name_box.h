#ifndef GUARD_FIELD_NAME_BOX_H
#define GUARD_FIELD_NAME_BOX_H

#include "config/name_box.h"

#define NAME_BOX_BASE_TILES_TOTAL (6) // Total tiles within the namebox's .png, best practice to make all images uses the same total tiles.
#define NAME_BOX_BASE_TILE_NUM    (0x194 - (OW_NAME_BOX_DEFAULT_WIDTH * OW_NAME_BOX_DEFAULT_HEIGHT))

extern EWRAM_DATA const u8 *gSpeakerName;
extern const u8 *const gSpeakerNamesTable[];

void TrySpawnNamebox(u32 tileNum);
u32 GetNameboxWindowId(void);
void ResetNameboxData(void);
void DestroyNamebox(void);
void FillNamebox(void);
void DrawNamebox(u32 windowId, u32 tileNum, bool32 copyToVram);
void ClearNamebox(u32 windowId, bool32 copyToVram);
u32 GetNameboxWidth(void);
void TrySpawnAndShowNamebox(const u8 *speaker, u32 tileNum);

#endif // GUARD_FIELD_NAME_BOX_H
