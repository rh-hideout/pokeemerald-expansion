static const struct {
    const u32 *tiles;
    const u32 *tilemap;
} sBXPY_BackgroundGraphics[BG_BXPY_COUNT] =
{
    [BG0_BXPY_TEXT] =
    {
        .tiles = NULL,
        .tilemap = NULL,
    },
    [BG1_BXPY_INFO] =
    {
        .tiles = NULL,
        .tilemap = NULL,
    },
    [BG2_BXPY_PARTY_BG] =
    {
        .tiles = (const u32[])INCBIN_U32("graphics/bxpy/champions/partyBg.4bpp.smol"),
        .tilemap = (const u32[])INCBIN_U32("graphics/bxpy/champions/partyBg.bin.smolTM"),
    },
    [BG3_BXPY_WALLPAPER] =
    {
        .tiles = (const u32[])INCBIN_U32("graphics/bxpy/champions/wallpaper.4bpp.smol"),
        .tilemap = (const u32[])INCBIN_U32("graphics/bxpy/champions/wallpaper.bin.smolTM"),
    },
};

static const struct BXPYSpriteSheet sBXPYSpriteSheets[BXPY_SPRITEID_COUNT] =
{
    [BXPY_SPRITEID_CURSOR] =
    {
        {
            .data = (const u16[])INCBIN_U16("graphics/bxpy/champions/cursor.4bpp"),
            .size = TILE_OFFSET_4BPP(4),
            .tag = BXPY_SPRITETAG_CURSOR,
        },
        {
            .data = (const u16[])INCBIN_U16("graphics/bxpy/champions/cursor.gbapal"),
            .tag = BXPY_PALTAG_SPRITE,
        },
    },
    [BXPY_SPRITEID_PLAYER_SEX_0] =
    {
        {
            .data = (const u16[])INCBIN_U16("graphics/bxpy/champions/sex.4bpp"),
            .size = TILE_OFFSET_4BPP(12),
            .tag = BXPY_SPRITETAG_SEX,
        },
    },
    [BXPY_SPRITEID_PLAYER_SELECTED_0] =
    {
        {
            .data = (const u16[])INCBIN_U16("graphics/bxpy/champions/selected.4bpp"),
            .size = TILE_OFFSET_4BPP(8),
            .tag = BXPY_SPRITETAG_SELECTED_0,
        },
    },
    [BXPY_SPRITEID_PLAYER_SELECTED_1] =
    {
        {
            .data = (const u16[])INCBIN_U16("graphics/bxpy/champions/selected.4bpp"),
            .size = TILE_OFFSET_4BPP(8),
            .tag = BXPY_SPRITETAG_SELECTED_1,
        },
    },
    [BXPY_SPRITEID_PLAYER_SELECTED_2] =
    {
        {
            .data = (const u16[])INCBIN_U16("graphics/bxpy/champions/selected.4bpp"),
            .size = TILE_OFFSET_4BPP(8),
            .tag = BXPY_SPRITETAG_SELECTED_2,
        },
    },
    [BXPY_SPRITEID_PLAYER_SELECTED_3] =
    {
        {
            .data = (const u16[])INCBIN_U16("graphics/bxpy/champions/selected.4bpp"),
            .size = TILE_OFFSET_4BPP(8),
            .tag = BXPY_SPRITETAG_SELECTED_3,
        },
    },
    [BXPY_SPRITEID_PLAYER_SELECTED_4] =
    {
        {
            .data = (const u16[])INCBIN_U16("graphics/bxpy/champions/selected.4bpp"),
            .size = TILE_OFFSET_4BPP(8),
            .tag = BXPY_SPRITETAG_SELECTED_4,
        },
    },
    [BXPY_SPRITEID_PLAYER_SELECTED_5] =
    {
        {
            .data = (const u16[])INCBIN_U16("graphics/bxpy/champions/selected.4bpp"),
            .size = TILE_OFFSET_4BPP(8),
            .tag = BXPY_SPRITETAG_SELECTED_5,
        },
    },
    [BXPY_SPRITEID_PLAYER_HP_0] =
    {
        {
            .data = (const u16[])INCBIN_U16("graphics/bxpy/champions/hp.4bpp"),
            .size = TILE_OFFSET_4BPP(128),
            .tag = BXPY_SPRITETAG_HP,
        },
    },
    [BXPY_SPRITEID_HIGHLIGHT_LEFT] =
    {
        {
            .data = (const u16[])INCBIN_U16("graphics/bxpy/champions/highlight.4bpp"),
            .size = TILE_OFFSET_4BPP(96),
            .tag = BXPY_SPRITETAG_HIGHLIGHT,
        },
        {
            .data = (const u16[])INCBIN_U16("graphics/bxpy/champions/highlight.gbapal"),
            .tag = BXPY_PALTAG_HIGHLIGHT,
        },
    },
    [BXPY_SPRITEID_ENEMY_TYPE_0_MON_0] =
    {
        {
            .data = (const u16[])INCBIN_U16("graphics/bxpy/champions/types.4bpp"),
            .size = TILE_OFFSET_4BPP(84),
            .tag = BXPY_SPRITETAG_TYPE,
        },
    },
    [BXPY_SPRITEID_PLAYER_SELECTED_TAIL_0] =
    {
        {
            .data = (const u16[])INCBIN_U16("graphics/bxpy/champions/selected_tail.4bpp"),
            .size = TILE_OFFSET_4BPP(8),
            .tag = BXPY_SPRITETAG_SELECTED_TAIL,
        },
    },
};

static const u16 bxpyPalettesText[] = INCBIN_U16("graphics/bxpy/champions/palettes/text.gbapal");
static const u16 bxpyPartyBackgroundPalette[] = INCBIN_U16("graphics/bxpy/champions/partyBg.gbapal");
static const u16 bxpyWallpaperPalette[] = INCBIN_U16("graphics/bxpy/champions/wallpaper.gbapal");
static const u16 bxpyTypesPalette[] = INCBIN_U16("graphics/bxpy/champions/types.gbapal");

