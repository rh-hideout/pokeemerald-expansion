#include "global.h"
#include "main.h"
#include "task.h"
#include "bg.h"
#include "decompress.h"
#include "palette.h"
#include "sound.h"
#include "malloc.h"
#include "item_menu.h"
#include "constants/rgb.h"
#include "constants/songs.h"
#include "secret_photo_viewer.h"

// Falls BG_CHAR_ADDR in eurer Codebase nicht existiert, nutzen wir VRAM direkt.
#ifndef BG_CHAR_ADDR
#define BG_CHAR_ADDR(n) (void *)(0x06000000 + (n) * 0x4000)
#endif

// 8bpp (256 Farben)
static const u32 sSecretPhotoTiles[] = INCBIN_U32("graphics/photos/secret_photo.8bpp.lz");
static const u16 sSecretPhotoPal[]   = INCBIN_U16("graphics/photos/secret_photo.gbapal");

static EWRAM_DATA struct BagPosition sSavedBagPos;
static EWRAM_DATA u16 *sBg0TilemapBuffer = NULL;
static EWRAM_DATA u8 sSecretPhotoState = 0;

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
        .screenSize = 0,   // 256x256 (32x32 tiles)
        .paletteMode = 1,  // 8bpp / 256 colors
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

    // State für Viewer zurücksetzen (damit Start immer sauber ist)
    sSecretPhotoState = 0;

    // Bag schließen und danach direkt in unseren Viewer
    gBagPosition.exitCallback = CB2_SecretPhotoViewer;
    Task_FadeAndCloseBagMenu(taskId);
}

static void VBlankCB_SecretPhotoViewer(void)
{
    TransferPlttBuffer();
}

static void CB2_ReturnToBagExact(void)
{
    // Bag-Position exakt wiederherstellen
    gBagPosition = sSavedBagPos;

    // Zurück in die Bag: gleiche Location/Pocket + ExitCallback wie zuvor
    GoToBagMenu(gBagPosition.location, gBagPosition.pocket, gBagPosition.exitCallback);
}

static void CB2_SecretPhotoViewer(void)
{
    switch (sSecretPhotoState)
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

        sSecretPhotoState++;
        break;

    case 1:
        // Tiles (LZ77) direkt nach VRAM, Charblock 0
        LZ77UnCompVram(sSecretPhotoTiles, (void *)BG_CHAR_ADDR(0));

        sSecretPhotoState++;
        break;

    case 2:
        // 256-Farben-Palette: 0x200 Bytes
        LoadPalette(sSecretPhotoPal, 0, 0x200);

        BuildSecretPhotoTilemap(sBg0TilemapBuffer);
        CopyBgTilemapBufferToVram(0);

        ShowBg(0);
        SetVBlankCallback(VBlankCB_SecretPhotoViewer);

        // Fade IN (von schwarz -> normal)
        BeginNormalPaletteFade(PALETTES_ALL, 0, 16, 0, RGB_BLACK);

        CreateTask(Task_SecretPhotoInput, 0);

        sSecretPhotoState++;
        break;

    default:
        RunTasks();
        UpdatePaletteFade();
        break;
    }
}

static void Task_SecretPhotoInput(u8 taskId)
{
    if (JOY_NEW(B_BUTTON))
    {
        PlaySE(SE_SELECT);

        // Fade OUT (normal -> schwarz)
        BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 16, RGB_BLACK);

        gTasks[taskId].func = Task_SecretPhotoReturnToBag;
    }
}

static void Task_SecretPhotoReturnToBag(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        DestroyTask(taskId);
        FreeSecretPhotoBuffers();

        // zurück in die Bag mit exakt derselben Position
        SetMainCallback2(CB2_ReturnToBagExact);
    }
}
