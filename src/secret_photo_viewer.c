#include "global.h"
#include "main.h"
#include "task.h"
#include "bg.h"
#include "decompress.h"
#include "gpu_regs.h"
#include "palette.h"
#include "sound.h"
#include "malloc.h"
#include "item_menu.h"
#include "constants/buttons.h"
#include "constants/songs.h"
#include "secret_photo_viewer.h"
#include "incbin.h"

// 8bpp (256 Farben)
static const u32 sSecretPhotoTiles[] = INCBIN_U32("graphics/photos/secret_photo.8bpp.lz");
static const u16 sSecretPhotoPal[]   = INCBIN_U16("graphics/photos/secret_photo.gbapal");

static EWRAM_DATA struct BagPosition sSavedBagPos;
static EWRAM_DATA u16 *sBg0TilemapBuffer = NULL;

static void CB2_SecretPhotoViewer(void);
static void VBlankCB_SecretPhotoViewer(void);
static void Task_SecretPhotoInput(u8 taskId);
static void Task_SecretPhotoReturnToBag(u8 taskId);

static const struct BgTemplate sBgTemplates[] =
{
    {
        .bg = 0,
        .charBaseIndex = 0,
        .mapBaseIndex = 31,
        .screenSize = BG_SCREEN_SIZE_256x256,
        .paletteMode = BG_PALETTE_MODE_256_COLORS, // <-- 8bpp
        .priority = 0,
        .baseTile = 0,
    },
};

static void FreeSecretPhotoBuffers(void)
{
    if (sBg0TilemapBuffer != NULL)
    {
        Free(sBg0TilemapBuffer);
        sBg0TilemapBuffer = NULL;
    }
}

// 30x20 Tiles (240x160) oben links in 32x32 BG-Map
static void BuildSecretPhotoTilemap(u16 *tilemap)
{
    u16 x, y;
    for (y = 0; y < 20; y++)
    {
        for (x = 0; x < 30; x++)
            tilemap[y * 32 + x] = (y * 30 + x);
    }
}

void ItemUseCB_SecretPhoto(u8 taskId)
{
    // komplette Bag-Position sichern (Pocket + Cursor + Scroll + exitCallback)
    sSavedBagPos = gBagPosition;

    // Bag schließen und danach direkt in unseren Viewer (Bag nutzt exitCallback genau dafür)
    gBagPosition.exitCallback = CB2_SecretPhotoViewer;
    Task_FadeAndCloseBagMenu(taskId);
}

static void VBlankCB_SecretPhotoViewer(void)
{
    TransferPlttBuffer();
}

static void CB2_ReturnToBagExact(void)
{
    gBagPosition = sSavedBagPos;
    GoToBagMenu(gBagPosition.location, gBagPosition.pocket, gBagPosition.exitCallback);
}

static void CB2_SecretPhotoViewer(void)
{
    switch (gMain.state)
    {
    case 0:
        SetVBlankCallback(NULL);
        ResetTasks();
        ResetSpriteData();
        FreeAllSpritePalettes();

        ResetBgsAndClearDma3BusyFlags(0);
        InitBgsFromTemplates(0, sBgTemplates, ARRAY_COUNT(sBgTemplates));

        sBg0TilemapBuffer = AllocZeroed(BG_SCREEN_SIZE);
        SetBgTilemapBuffer(0, sBg0TilemapBuffer);

        gMain.state++;
        break;

    case 1:
        // Tiles -> VRAM (LZ77)
        DecompressAndCopyTileDataToVram(0, sSecretPhotoTiles, 0, 0, 0);
        gMain.state++;
        break;

    case 2:
        if (!FreeTempTileDataBuffersIfPossible())
        {
            // 256-Farben-Palette: 0x200 Bytes
            LoadPalette(sSecretPhotoPal, 0, 0x200);

            BuildSecretPhotoTilemap(sBg0TilemapBuffer);
            CopyBgTilemapBufferToVram(0);

            ShowBg(0);
            SetVBlankCallback(VBlankCB_SecretPhotoViewer);

            FadeScreen(FADE_FROM_BLACK, 0);

            CreateTask(Task_SecretPhotoInput, 0);
            gMain.state++;
        }
        break;

    default:
        break;
    }
}

static void Task_SecretPhotoInput(u8 taskId)
{
    if (JOY_NEW(B_BUTTON))
    {
        PlaySE(SE_SELECT);
        FadeScreen(FADE_TO_BLACK, 0);
        gTasks[taskId].func = Task_SecretPhotoReturnToBag;
    }
}

static void Task_SecretPhotoReturnToBag(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        DestroyTask(taskId);
        FreeSecretPhotoBuffers();
        SetMainCallback2(CB2_ReturnToBagExact);
    }
}
