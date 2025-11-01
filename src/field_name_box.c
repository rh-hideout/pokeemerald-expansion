#include "global.h"
#include "main.h"
#include "menu.h"
#include "bg.h"
#include "window.h"
#include "text.h"
#include "string_util.h"
#include "international_string_util.h"
#include "script_menu.h"
#include "field_message_box.h"
#include "graphics.h"
#include "script.h"
#include "field_name_box.h"
#include "event_data.h"
#include "constants/speaker_names.h"
#include "data/speaker_names.h"

#define NAME_BOX_BASE_TILE_NUM (STD_WINDOW_BASE_TILE_NUM + 9)

static EWRAM_INIT u8 sNameboxWindowId = WINDOW_NONE;
static EWRAM_DATA u8 sNameboxBuffer[32] = {0};
EWRAM_DATA const u8 *gSpeakerName = NULL;

static void WindowFunc_DrawNamebox(u8, u8, u8, u8, u8, u8);
static void WindowFunc_ClearNamebox(u8, u8, u8, u8, u8, u8);

void TrySpawnNamebox(void)
{
    if (gSpeakerName == NULL || (OW_FLAG_SUPPRESS_NAME_BOX != 0 && FlagGet(OW_FLAG_SUPPRESS_NAME_BOX)))
    {
        DestroyNamebox();
        return;
    }

    StringExpandPlaceholders(sNameboxBuffer, gSpeakerName);

    u32 fontId = FONT_SMALL;
    u32 winWidth = OW_NAME_BOX_DEFAULT_WIDTH;

    if (OW_NAME_BOX_USE_DYNAMIC_WIDTH)
    {
        winWidth = ConvertPixelWidthToTileWidth(GetStringWidth(fontId, sNameboxBuffer, -1));
        if (winWidth > OW_NAME_BOX_DEFAULT_WIDTH)
            winWidth = OW_NAME_BOX_DEFAULT_WIDTH;
    }

    if (sNameboxWindowId != WINDOW_NONE)
    {
        DestroyNamebox();
        RedrawDialogueFrame(0, TRUE);
    }

    struct WindowTemplate template =
    {
        .bg = 0,
        .tilemapLeft = 2,
        .tilemapTop = 13,
        .width = winWidth,
        .height = OW_NAME_BOX_DEFAULT_HEIGHT,
        .paletteNum = DLG_WINDOW_PALETTE_NUM,
        .baseBlock = 0x194 - (OW_NAME_BOX_DEFAULT_WIDTH * OW_NAME_BOX_DEFAULT_HEIGHT),
    };

    sNameboxWindowId = AddWindow(&template);
    FillNamebox();

    const u8 colors[3] = {TEXT_COLOR_TRANSPARENT, OW_NAME_BOX_FOREGROUND_COLOR, OW_NAME_BOX_SHADOW_COLOR};
    u8 bakColors[3];
    int strX = GetStringCenterAlignXOffset(fontId, sNameboxBuffer, (winWidth * 8));

    SaveTextColors(&bakColors[0], &bakColors[1], &bakColors[2]);
    AddTextPrinterParameterized3(sNameboxWindowId, fontId, strX, 0, colors, 0, sNameboxBuffer);
    RestoreTextColors(&bakColors[0], &bakColors[1], &bakColors[2]);
    PutWindowTilemap(sNameboxWindowId);
}

u32 GetNameboxWindowId(void)
{
    return sNameboxWindowId;
}

void DestroyNamebox(void)
{
    if (sNameboxWindowId == WINDOW_NONE)
        return;

    ClearNamebox(sNameboxWindowId, TRUE);
    ClearWindowTilemap(sNameboxWindowId);
    RemoveWindow(sNameboxWindowId);
    sNameboxWindowId = WINDOW_NONE;
    gSpeakerName = NULL;
}

u32 GetNameboxWidth(void)
{
    return gWindows[sNameboxWindowId].window.width;
}

void FillNamebox(void)
{
    u32 winSize = GetNameboxWidth();

    for (u32 i = 0; i < winSize; i++)
    {
        #define TILE(x) (8 * x)
        CopyToWindowPixelBuffer(sNameboxWindowId, &gNameBox_Gfx[TILE(1)], TILE_SIZE_4BPP, i);
        CopyToWindowPixelBuffer(sNameboxWindowId, &gNameBox_Gfx[TILE(4)], TILE_SIZE_4BPP, i + winSize);
        #undef TILE
    }
}

void DrawNamebox(u32 windowId, bool32 copyToVram)
{
    LoadBgTiles(GetWindowAttribute(sNameboxWindowId, WINDOW_BG), gNameBox_Gfx, 0x0C0, NAME_BOX_BASE_TILE_NUM);
    CallWindowFunction(windowId, WindowFunc_DrawNamebox);
    PutWindowTilemap(windowId);
    if (copyToVram == TRUE)
        CopyWindowToVram(windowId, COPYWIN_FULL);
}

void ClearNamebox(u32 windowId, bool32 copyToVram)
{
    CallWindowFunction(windowId, WindowFunc_ClearNamebox);
    ClearWindowTilemap(windowId);
    if (copyToVram == TRUE)
        CopyWindowToVram(windowId, COPYWIN_FULL);
}

static void WindowFunc_DrawNamebox(u8 bg, u8 L, u8 T, u8 w, u8 h, u8 p)
{
    // left-most
    FillBgTilemapBufferRect(bg, NAME_BOX_BASE_TILE_NUM,     L - 1, T,     1, 1, p);
    FillBgTilemapBufferRect(bg, NAME_BOX_BASE_TILE_NUM + 3, L - 1, T + 1, 1, 1, p);

    // right-most
    FillBgTilemapBufferRect(bg, NAME_BOX_BASE_TILE_NUM + 2, L + w, T,     1, 1, p);
    FillBgTilemapBufferRect(bg, NAME_BOX_BASE_TILE_NUM + 5, L + w, T + 1, 1, 1, p);
}

static void WindowFunc_ClearNamebox(u8 bg, u8 L, u8 T, u8 w, u8 h, u8 p)
{
    FillBgTilemapBufferRect(bg, 0, L - 1, T, w + 2, h, 0); // palette doesn't matter
}

void SetSpeaker(struct ScriptContext *ctx)
{
    u32 arg = ScriptReadWord(ctx);
    const u8 *speaker = NULL;

    if (arg < SP_NAME_COUNT)
        speaker = gSpeakerNamesTable[arg];
    else if (arg >= ROM_START && arg < ROM_END)
        speaker = (const u8 *)arg;

    gSpeakerName = speaker;
}
