#include "global.h"
#include "malloc.h"
#include "berry_powder.h"
#include "fake_rtc.h"
#include "follower_npc.h"
#include "item.h"
#include "load_save.h"
#include "main.h"
#include "overworld.h"
#include "pokemon.h"
#include "pokemon_storage_system.h"
#include "random.h"
#include "save_location.h"
#include "script_pokemon_util.h"
#include "trainer_hill.h"
#include "wild_encounter_ow.h"
#include "gba/flash_internal.h"
#include "decoration_inventory.h"
#include "agb_flash.h"
#include "event_data.h"
#include "constants/event_objects.h"

#define SAVEBLOCK_MOVE_RANGE    128

struct LoadedSaveData
{
 /*0x0000*/ struct Bag bag;
 /*0x02E8*/ struct Mail mail[MAIL_COUNT];
};

// EWRAM DATA
EWRAM_DATA struct SaveBlock3 gSaveBlock3 = {};
EWRAM_DATA struct SaveBlock2 gSaveBlock2 = {0};
EWRAM_DATA struct SaveBlock1 gSaveBlock1 = {0};
EWRAM_DATA struct PokemonStorage gPokemonStorage = {0};

EWRAM_DATA struct LoadedSaveData gLoadedSaveData = {0};

// IWRAM common
COMMON_DATA bool32 gFlashMemoryPresent = 0;

// code
void CheckForFlashMemory(void)
{
    if (!IdentifyFlash())
    {
        gFlashMemoryPresent = TRUE;
        InitFlashTimer();
    }
    else
    {
        gFlashMemoryPresent = FALSE;
    }
}

void ClearSav3(void)
{
    CpuFill16(0, &gSaveBlock3, sizeof(gSaveBlock3));
    FakeRtc_Reset();
}

void ClearSav2(void)
{
    CpuFill16(0, &gSaveBlock2, sizeof(gSaveBlock2));
}

void ClearSav1(void)
{
    CpuFill16(0, &gSaveBlock1, sizeof(gSaveBlock1));
}

void SetSaveBlocksPointers(void)
{
    SetDecorationInventoriesPointers();
}

u32 UseContinueGameWarp(void)
{
    return gSaveBlock2Ptr->specialSaveWarpFlags & CONTINUE_GAME_WARP;
}

void ClearContinueGameWarpStatus(void)
{
    gSaveBlock2Ptr->specialSaveWarpFlags &= ~CONTINUE_GAME_WARP;
}

void SetContinueGameWarpStatus(void)
{
    gSaveBlock2Ptr->specialSaveWarpFlags |= CONTINUE_GAME_WARP;
}

void SetContinueGameWarpStatusToDynamicWarp(void)
{
    SetContinueGameWarpToDynamicWarp(0);
    gSaveBlock2Ptr->specialSaveWarpFlags |= CONTINUE_GAME_WARP;
}

void ClearContinueGameWarpStatus2(void)
{
    gSaveBlock2Ptr->specialSaveWarpFlags &= ~CONTINUE_GAME_WARP;
}

void SavePlayerParty(void)
{
    int i;
    *GetSavedPlayerPartyCount() = gPartiesCount[B_TRAINER_PLAYER];

    for (i = 0; i < PARTY_SIZE; i++)
        SavePlayerPartyMon(i, &gParties[B_TRAINER_PLAYER][i]);
}

void LoadPlayerParty(void)
{
    int i;

    gPartiesCount[B_TRAINER_PLAYER] = *GetSavedPlayerPartyCount();

    for (i = 0; i < PARTY_SIZE; i++)
    {
        u32 data;
        gParties[B_TRAINER_PLAYER][i] = *GetSavedPlayerPartyMon(i);

        // TODO: Turn this into a save migration once those are available.
        // At which point we can remove hp and status from Pokemon entirely.
        data = gParties[B_TRAINER_PLAYER][i].maxHP - gParties[B_TRAINER_PLAYER][i].hp;
        SetBoxMonData(&gParties[B_TRAINER_PLAYER][i].box, MON_DATA_HP_LOST, &data);
        data = gParties[B_TRAINER_PLAYER][i].status;
        SetBoxMonData(&gParties[B_TRAINER_PLAYER][i].box, MON_DATA_STATUS, &data);
    }
}

void SaveObjectEvents(void)
{
    int i;
    u16 graphicsId;

    for (i = 0; i < OBJECT_EVENTS_COUNT; i++)
    {
        gSaveBlock1Ptr->objectEvents[i] = gObjectEvents[i];
        // Swap graphicsId bytes when saving and loading
        // This keeps compatibility with vanilla,
        // since the lower graphicsIds will be in the same place as vanilla
        graphicsId = gObjectEvents[i].graphicsId;
        gSaveBlock1Ptr->objectEvents[i].graphicsId = (graphicsId >> 8) | (graphicsId << 8);
        gSaveBlock1Ptr->objectEvents[i].spriteId = 127; // magic number
        // To avoid crash on vanilla, save follower as inactive
        if (gObjectEvents[i].localId == OBJ_EVENT_ID_FOLLOWER)
            gSaveBlock1Ptr->objectEvents[i].active = FALSE;
    }
}

void LoadObjectEvents(void)
{
    int i;
    u16 graphicsId;

    for (i = 0; i < OBJECT_EVENTS_COUNT; i++)
    {
        gObjectEvents[i] = gSaveBlock1Ptr->objectEvents[i];
        // Swap graphicsId bytes when saving and loading
        // This keeps compatibility with vanilla,
        // since the lower graphicsIds will be in the same place as vanilla
        graphicsId = gObjectEvents[i].graphicsId;
        gObjectEvents[i].graphicsId = (graphicsId >> 8) | (graphicsId << 8);
        if (gObjectEvents[i].spriteId != 127)
            gObjectEvents[i].graphicsId &= 0xFF;
        gObjectEvents[i].spriteId = 0;
        // Try to restore saved inactive follower
        if (gObjectEvents[i].localId == OBJ_EVENT_ID_FOLLOWER &&
            !gObjectEvents[i].active &&
            gObjectEvents[i].graphicsId & OBJ_EVENT_MON)
            gObjectEvents[i].active = TRUE;
    }
    SetMinimumOWESpawnTimer();
}

void CopyPartyAndObjectsToSave(void)
{
    SavePlayerParty();
    SaveObjectEvents();
}

void CopyPartyAndObjectsFromSave(void)
{
    LoadPlayerParty();
    LoadObjectEvents();
}

void LoadPlayerBag(void)
{
    memcpy(&gLoadedSaveData.bag, &gSaveBlock1Ptr->bag, sizeof(struct Bag));
    memcpy(gLoadedSaveData.mail, gSaveBlock1Ptr->mail, sizeof(gLoadedSaveData.mail));
}

void SavePlayerBag(void)
{
    memcpy(&gSaveBlock1Ptr->bag, &gLoadedSaveData.bag, sizeof(struct Bag));
    memcpy(gSaveBlock1Ptr->mail, gLoadedSaveData.mail, sizeof(gSaveBlock1Ptr->mail));
}

void ApplyNewEncryptionKeyToHword(u16 *hWord, u32 newKey)
{
    *hWord ^= gSaveBlock2Ptr->encryptionKey;
    *hWord ^= newKey;
}

void ApplyNewEncryptionKeyToWord(u32 *word, u32 newKey)
{
    *word ^= gSaveBlock2Ptr->encryptionKey;
    *word ^= newKey;
}

void EncryptSave(void)
{
    for (u32 i = 0; i < ARRAY_COUNT(gSaveBlock1Ptr->playerParty); i++)
        EncryptMon(&gSaveBlock1Ptr->playerParty[i]);
    for (u32 i = 0; i < ARRAY_COUNT(gSaveBlock1Ptr->daycare.mons); i++)
        EncryptBoxMon(&gSaveBlock1Ptr->daycare.mons[i].mon);
    #if IS_FRLG
    EncryptBoxMon(&gSaveBlock1Ptr->route5DayCareMon.mon);
    #endif

    for (u32 i = 0; i < TOTAL_BOXES_COUNT; i++)
    {
        for (u32 j = 0; j < IN_BOX_COUNT; j++)
            EncryptBoxMon(&gPokemonStoragePtr->boxes[i][j]);
    }
    for (u32 i = 0; i < ARRAY_COUNT(gPokemonStoragePtr->fusions); i++)
        EncryptMon(&gPokemonStoragePtr->fusions[i]);
}

void DecryptSave(void)
{
    // HINT: Setting the encyptionKey to 0 means that encrypting would
    // be a no-op, allowing us to skip decrypting them in the future.
    if (gSaveBlock2Ptr->encryptionKey != 0)
    {
        ApplyNewEncryptionKeyToGameStats(0);
        ApplyNewEncryptionKeyToBagItems(0);
        ApplyNewEncryptionKeyToBerryPowder(0);
        ApplyNewEncryptionKeyToWord(&gSaveBlock1Ptr->money, 0);
        ApplyNewEncryptionKeyToHword(&gSaveBlock1Ptr->coins, 0);

        gSaveBlock2Ptr->encryptionKey = 0;
    }

    for (u32 i = 0; i < ARRAY_COUNT(gSaveBlock1Ptr->playerParty); i++)
        EncryptMon(&gSaveBlock1Ptr->playerParty[i]);
    for (u32 i = 0; i < ARRAY_COUNT(gSaveBlock1Ptr->daycare.mons); i++)
        EncryptBoxMon(&gSaveBlock1Ptr->daycare.mons[i].mon);
    #if IS_FRLG
    EncryptBoxMon(&gSaveBlock1Ptr->route5DayCareMon.mon);
    #endif

    for (u32 i = 0; i < TOTAL_BOXES_COUNT; i++)
    {
        for (u32 j = 0; j < IN_BOX_COUNT; j++)
            DecryptBoxMon(&gPokemonStoragePtr->boxes[i][j]);
    }
    for (u32 i = 0; i < ARRAY_COUNT(gPokemonStoragePtr->fusions); i++)
        DecryptMon(&gPokemonStoragePtr->fusions[i]);
}
