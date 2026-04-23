#ifndef GUARD_LOAD_SAVE_H
#define GUARD_LOAD_SAVE_H

#include "pokemon_storage_system.h"
#include "save.h"

extern struct SaveBlock1 gSaveBlock1;
extern struct SaveBlock2 gSaveBlock2;
extern struct SaveBlock3 gSaveBlock3;
extern struct PokemonStorage gPokemonStorage;

#define gSaveBlock1Ptr (&gSaveBlock1)
#define gSaveBlock2Ptr (&gSaveBlock2)
#define gSaveBlock3Ptr (&gSaveBlock3)
#define gPokemonStoragePtr (&gPokemonStorage)

extern bool32 gFlashMemoryPresent;

void CheckForFlashMemory(void);
void ClearSav3(void);
void ClearSav2(void);
void ClearSav1(void);
void SetSaveBlocksPointers(u16 offset);
void RotateEncryptionKey_ResetHeap(void);
u32 UseContinueGameWarp(void);
void ClearContinueGameWarpStatus(void);
void SetContinueGameWarpStatus(void);
void SetContinueGameWarpStatusToDynamicWarp(void);
void ClearContinueGameWarpStatus2(void);
void SavePlayerParty(void);
void LoadPlayerParty(void);
void SaveObjectEvents(void);
void LoadObjectEvents(void);
void CopyPartyAndObjectsToSave(void);
void CopyPartyAndObjectsFromSave(void);
void LoadPlayerBag(void);
void SavePlayerBag(void);
void ApplyNewEncryptionKeyToHword(u16 *hWord, u32 newKey);
void ApplyNewEncryptionKeyToWord(u32 *word, u32 newKey);

#endif // GUARD_LOAD_SAVE_H
