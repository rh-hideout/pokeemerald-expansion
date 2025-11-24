#include "even_sprite.h"
#include "gba/types.h"
#include "global.h"
#include "decompress.h"
#include "malloc.h"
#include "pokemon.h"
#include "item.h"
#include "sprite.h"
#include "task.h"

static const struct OamData sOamData_ItemIcon =
{
    .y = 0,
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .mosaic = FALSE,
    .bpp = ST_OAM_4BPP,
    .shape = 0,
    .x = 0,
    .matrixNum = 0,
    .size = 0,
    .tileNum = 0,
    .priority = 1,
    .paletteNum = 2,
    .affineParam = 0
};

static const union AnimCmd sSpriteAnim_ItemIcon[] =
{
    ANIMCMD_FRAME(0, 0),
    ANIMCMD_END
};

static const union AnimCmd *const sSpriteAnimTable_ItemIcon[] =
{
    sSpriteAnim_ItemIcon
};

const struct SpriteTemplate gTempSpriteTemplate =
{
    .tileTag = 0,
    .paletteTag = 0,
    .oam = NULL,
    .anims = sSpriteAnimTable_ItemIcon,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy,
};

u32 Even_CreateSprite(struct Even_CreateSpriteStruct *createStruct)
{
    u8 spriteId;
    struct SpriteSheet spriteSheet;
    struct SpriteTemplate *spriteTemplate;
    struct OamData oamData = sOamData_ItemIcon;
    oamData.size = createStruct->spriteSize;
    oamData.shape = createStruct->spriteShape;

    u32 *spriteSrc;
    if (createStruct->spriteCompressed)
    {
        spriteSrc = Alloc(GetDecompressedDataSize(createStruct->sprite));
        DecompressDataWithHeaderWram(createStruct->sprite, spriteSrc);
    }
    else
    {
        spriteSrc = (u32 *)createStruct->sprite;
    }

    if (createStruct->palette != NULL)
    {
        struct SpritePalette spritePalette;
        spritePalette.tag = createStruct->palTag;
        spritePalette.data = createStruct->palette;
        LoadSpritePalette(&spritePalette);
    }

    u32 byteSize = 0;
    switch (createStruct->spriteSize)
    {
    case ST_OAM_SIZE_0:
        if (createStruct->spriteShape == ST_OAM_SQUARE)
            byteSize = 32;
        else
            byteSize = 64;
        break;
    case ST_OAM_SIZE_1:
        byteSize = 128;
        break;
    case ST_OAM_SIZE_2:
        if (createStruct->spriteShape == ST_OAM_SQUARE)
            byteSize = 512;
        else
            byteSize = 256;
        break;
    case ST_OAM_SIZE_3:
        if (createStruct->spriteShape == ST_OAM_SQUARE)
            byteSize = 2048;
        else
            byteSize = 1024;
        break;
    }

    spriteSheet.data = spriteSrc;
    spriteSheet.size = byteSize;
    spriteSheet.tag = createStruct->tileTag;
    if (GetSpriteTileStartByTag(spriteSheet.tag) == 0xFFFF)
        LoadSpriteSheet(&spriteSheet);


    spriteTemplate = Alloc(sizeof(*spriteTemplate));
    CpuCopy16(&gTempSpriteTemplate, spriteTemplate, sizeof(*spriteTemplate));
    spriteTemplate->tileTag = createStruct->tileTag;
    spriteTemplate->paletteTag = createStruct->palTag;
    spriteTemplate->oam = &oamData;

    if (createStruct->callback == NULL)
        spriteTemplate->callback = SpriteCallbackDummy;
    else
        spriteTemplate->callback = createStruct->callback;

    spriteId = CreateSprite(spriteTemplate, createStruct->posX, createStruct->posY, createStruct->subpriority);

    Free(spriteTemplate);

    if (createStruct->spriteCompressed)
        Free(spriteSrc);
    return spriteId;
}

void TestDrawSprite(void)
{
    struct Even_CreateSpriteStruct createStruct = {0};
    createStruct.sprite = gSpeciesInfo[SPECIES_CALYREX].frontPic;
    createStruct.spriteCompressed = TRUE;
    createStruct.tileTag = 7823;
    createStruct.palette = gSpeciesInfo[SPECIES_CALYREX].palette;
    createStruct.palTag = 7823;
    createStruct.spriteSize = SPRITE_SIZE(64x64);
    createStruct.spriteShape = SPRITE_SHAPE(64x64);
    createStruct.posX = 32;
    createStruct.posY = 32;
    createStruct.subpriority = 0;
    Even_CreateSprite(&createStruct);
}
