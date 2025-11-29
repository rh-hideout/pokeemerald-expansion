#ifndef GUARD_EVEN_SPRITE_H
#define GUARD_EVEN_SPRITE_H

#include "gba/types.h"
#include "sprite.h"

struct Even_CreateSpriteStruct
{
    const u32 *sprite;
    const u16 *palette;
    u16 tileTag;
    u16 palTag;
    s16 posX;
    s16 posY;
    bool8 spriteCompressed;
    u8 subpriority;
    u8 spriteShape:2;
    u8 spriteSize:2;
    SpriteCallback callback;
};

u32 Even_CreateSprite(struct Even_CreateSpriteStruct *creteStruct);

void TestDrawSprite(void);

#endif
