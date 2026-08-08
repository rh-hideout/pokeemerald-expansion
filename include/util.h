#ifndef GUARD_UTIL_H
#define GUARD_UTIL_H

#include "sprite.h"

#define HP_EMPTY 0

extern const u8 gMiscBlank_Gfx[]; // unused in Emerald

static inline s32 Clamp(s32 min, s32 max, s32 value)
{
    if (value < min)
        return min;
    if (value > max)
        return max;
    return value;
}

u8 CreateInvisibleSpriteWithCallback(void (*callback)(struct Sprite *));
void StoreWordInTwoHalfwords(u16 *h, u32 w);
void LoadWordFromTwoHalfwords(u16 *h, u32 *w);
u16 CalcCRC16(const u8 *data, s32 length);
u16 CalcCRC16WithTable(const u8 *data, u32 length);
u32 CalcByteArraySum(const u8 *data, u32 length);
void BlendPalette(u16 palOffset, u16 numEntries, u8 coeff, u32 blendColor);
void DoBgAffineSet(struct BgAffineDstData *dest, u32 texX, u32 texY, s16 scrX, s16 scrY, s16 sx, s16 sy, u16 alpha);
void CopySpriteTiles(u8 shape, u8 size, u8 *tiles, u16 *tilemap, u8 *output);
s32 SubtractClamped(s32 min, s32 max, s32 value, s32 delta);
s32 AddClamped(s32 min, s32 max, s32 value, s32 delta);
void CopyTiles(const Tile4BPP* src, Tile4BPP* dest, u32 count);
void FillTiles(const Tile4BPP *src, Tile4BPP *dest, u32 count);

#endif // GUARD_UTIL_H
