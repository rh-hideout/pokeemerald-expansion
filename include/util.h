#ifndef GUARD_UTIL_H
#define GUARD_UTIL_H

#include "sprite.h"

#define HP_EMPTY 0

extern const u8 gMiscBlank_Gfx[]; // unused in Emerald

u8 CreateInvisibleSpriteWithCallback(void (*callback)(struct Sprite *));
void StoreWordInTwoHalfwords(u16 *h, u32 w);
void LoadWordFromTwoHalfwords(u16 *h, u32 *w);
int CountTrailingZeroBits(u32 value);
u16 CalcCRC16(const u8 *data, s32 length);
u16 CalcCRC16WithTable(const u8 *data, u32 length);
u32 CalcByteArraySum(const u8 *data, u32 length);
void BlendPalette(u16 palOffset, u16 numEntries, u8 coeff, u32 blendColor);
void DoBgAffineSet(struct BgAffineDstData *dest, u32 texX, u32 texY, s16 scrX, s16 scrY, s16 sx, s16 sy, u16 alpha);
void CopySpriteTiles(u8 shape, u8 size, u8 *tiles, u16 *tilemap, u8 *output);
s32 SubtractClamped(s32 lowestVal, s32 highestVal, s32 currentVal, s32 delta);

/* Clamp(s32 value, s32 min, s32 max)
 * Clamp(s32 value, s32 min, s32 max, bool32 *clamped)
 * Clamp(u32 value, u32 min, u32 max)
 * Clamp(u32 value, u32 min, u32 max, bool32 *clamped)
 *
 * If 'value' is between 'min' and 'max' (inclusive), returns 'value'
 * and sets 'clamped' to 'FALSE'. Otherwise, returns 'min' if
 * 'value < min' or 'max' if 'value > max' and sets 'clamped' to 'TRUE'. */
#define Clamp(value, min, max, ...) _Generic(value + min + max, int: ClampS32, s32: ClampS32, u32: ClampU32)(value, min, max, IF_EMPTY(&(bool32){0} __VA_OPT__(, __VA_ARGS__)))

s32 ClampS32(s32 value, s32 min, s32 max, bool32 *clamped);
u32 ClampU32(u32 value, u32 min, u32 max, bool32 *clamped);

/* If the mathematical result of 'addend1 + addend2' is between 'min'
 * and 'max' inclusive: 'sum = addend1 + addend2', 'saturated = FALSE'.
 * Otherwise, if 'addend2 > 0': 'sum = max', 'saturated = TRUE'.
 * Otherwise, 'addend2 < 0': 'sum = min', 'saturated = TRUE'.
 *
 * s32 SatAdd(s32 addend1, s32 addend2, s32 min, s32 max)
 * s32 SatAdd(s32 addend1, s32 addend2, s32 min, s32 max, bool32 *saturated)
 * u32 SatAdd(u32 addend1, u32 addend2, u32 min, u32 max)
 * u32 SatAdd(u32 addend1, u32 addend2, u32 min, u32 max, bool32 *saturated)
 * Returns 'sum' and stores 'saturated' (if passed).
 *
 * bool32 SatAddPtr(s8 *addend1, s32 addend2, s32 min, s32 max)
 * bool32 SatAddPtr(s16 *addend1, s32 addend2, s32 min, s32 max)
 * bool32 SatAddPtr(s32 *addend1, s32 addend2, s32 min, s32 max)
 * bool32 SatAddPtr(u8 *addend1, u32 addend2, u32 min, u32 max)
 * bool32 SatAddPtr(u16 *addend1, u32 addend2, u32 min, u32 max)
 * bool32 SatAddPtr(u32 *addend1, u32 addend2, u32 min, u32 max)
 * Returns 'saturated' and stores 'sum' in 'addend1'.
 *
 * Assumes 'min <= addend1 <= max'.
 *
 * e.g.
 *   SatAdd(99, 1, 1, 99) == 99
 *   SatAdd(95, 10, 1, 99) == 99 */
#define SatAdd(addend1, addend2, min, max, ...) _Generic(addend1 + addend2 + min + max, int: SatAddS32, s32: SatAddS32, u32: SatAddU32)(addend1, addend2, min, max, IF_EMPTY(&(bool32){0} __VA_OPT__(, __VA_ARGS__)))
#define SatAddPtr(addend1, addend2, min, max) ({ bool32 saturated; *addend1 = SatAdd(*addend1, addend2, min, max, &saturated); saturated; })

/* If the mathematical result of 'minuend - subtrahend' is between 'min'
 * and 'max' inclusive: 'difference = minuend - subtrahend', 
 * 'saturated = FALSE'.
 * Otherwise, if 'subtrahend > 0', 'difference = min', 'saturated = TRUE'.
 * Otherwise, 'subtrahend < 0', 'difference = max', 'saturated = TRUE'.
 *
 * s32 SatSub(s32 minuend, s32 subtrahend, s32 min, s32 max)
 * s32 SatSub(s32 minuend, s32 subtrahend, s32 min, s32 max, bool32 *saturated)
 * u32 SatSub(u32 minuend, u32 subtrahend, u32 min, u32 max)
 * u32 SatSub(u32 minuend, u32 subtrahend, u32 min, u32 max, bool32 *saturated)
 * Returns 'difference' and stores 'saturated' (if passed).
 *
 * bool32 SatSubPtr(s8 *minuend, s32 subtrahend, s32 min, s32 max)
 * bool32 SatSubPtr(s16 *minuend, s32 subtrahend, s32 min, s32 max)
 * bool32 SatSubPtr(s32 *minuend, s32 subtrahend, s32 min, s32 max)
 * bool32 SatSubPtr(u8 *minuend, u32 subtrahend, u32 min, u32 max)
 * bool32 SatSubPtr(u16 *minuend, u32 subtrahend, u32 min, u32 max)
 * bool32 SatSubPtr(u32 *minuend, u32 subtrahend, u32 min, u32 max)
 * Returns 'saturated' and stores 'difference' in 'minuend'.
 *
 * Assumes 'min <= minuend <= max'.
 *
 * e.g.
 *   SatSub(1, 1, 1, 99) == 1
 *   SatSub(5, 10, 1, 99) == 1 */
#define SatSub(minuend, subtrahend, min, max, ...) _Generic(minuend + subtrahend + min + max, int: SatSubS32, s32: SatSubS32, u32: SatSubU32)(minuend, subtrahend, min, max, IF_EMPTY(&(bool32){0} __VA_OPT__(, __VA_ARGS__)))
#define SatSubPtr(minuend, subtrahend, min, max) ({ bool32 saturated; *minuend = SatSub(*minuend, subtrahend, min, max, &saturated); saturated; })

/* If the mathematical result of 'addend1 + addend2' is between 'min'
 * and 'max' inclusive: 'sum = addend1 + addend2', 'wrapped = FALSE'.
 * Otherwise, adds or subtracts 'max - min + 1' until 'sum' is in range
 * and 'wrapped = TRUE'.
 *
 * s32 WrapAdd(s32 addend1, s32 addend2, s32 min, s32 max)
 * s32 WrapAdd(s32 addend1, s32 addend2, s32 min, s32 max, bool32 *wrapped)
 * u32 WrapAdd(u32 addend1, u32 addend2, u32 min, u32 max)
 * u32 WrapAdd(u32 addend1, u32 addend2, u32 min, u32 max, bool32 *wrapped)
 * Returns 'sum' and stores 'wrapped' (if passed).
 *
 * bool32 WrapAddPtr(s8 *addend1, s32 addend2, s32 min, s32 max)
 * bool32 WrapAddPtr(s16 *addend1, s32 addend2, s32 min, s32 max)
 * bool32 WrapAddPtr(s32 *addend1, s32 addend2, s32 min, s32 max)
 * bool32 WrapAddPtr(u8 *addend1, u32 addend2, u32 min, u32 max)
 * bool32 WrapAddPtr(u16 *addend1, u32 addend2, u32 min, u32 max)
 * bool32 WrapAddPtr(u32 *addend1, u32 addend2, u32 min, u32 max)
 * Returns 'wrapped' and stores 'sum' in 'addend1'.
 *
 * Assumes 'min <= addend1 <= max'.
 *
 * e.g.
 *   WrapAdd(99, 1, 1, 99) == 1
 *   WrapAdd(95, 10, 1, 99) == 6 */
#define WrapAdd(addend1, addend2, min, max, ...) _Generic(addend1 + addend2 + min + max, int: WrapAddS32, s32: WrapAddS32, u32: WrapAddU32)(addend1, addend2, min, max, IF_EMPTY(&(bool32){0} __VA_OPT__(, __VA_ARGS__)))
#define WrapAddPtr(addend1, addend2, min, max) ({ bool32 wrapped; *addend1 = WrapAdd(*addend1, addend2, min, max, &wrapped); wrapped; })

/* If the mathematical result of 'minuend - subtrahend' is between 'min'
 * and 'max' inclusive: 'difference = minuend - subtrahend',
 * 'wrapped = FALSE'.
 * Otherwise, adds or subtracts 'max - min + 1' until 'difference' is in
 * range and 'wrapped = TRUE'.
 *
 * s32 WrapSub(s32 minuend, s32 subtrahend, s32 min, s32 max)
 * s32 WrapSub(s32 minuend, s32 subtrahend, s32 min, s32 max, bool32 *wrapped)
 * u32 WrapSub(u32 minuend, u32 subtrahend, u32 min, u32 max)
 * u32 WrapSub(u32 minuend, u32 subtrahend, u32 min, u32 max, bool32 *wrapped)
 * Returns 'difference' and stores 'wrapped' (if passed).
 *
 * bool32 WrapSubPtr(s8 *minuend, s32 subtrahend, s32 min, s32 max)
 * bool32 WrapSubPtr(s16 *minuend, s32 subtrahend, s32 min, s32 max)
 * bool32 WrapSubPtr(s32 *minuend, s32 subtrahend, s32 min, s32 max)
 * bool32 WrapSubPtr(u8 *minuend, u32 subtrahend, u32 min, u32 max)
 * bool32 WrapSubPtr(u16 *minuend, u32 subtrahend, u32 min, u32 max)
 * bool32 WrapSubPtr(u32 *minuend, u32 subtrahend, u32 min, u32 max)
 * Returns 'wrapped' and stores 'difference' in 'minuend'.
 *
 * Assumes 'min <= minuend <= max'.
 *
 * e.g.
 *   WrapSub(1, 1, 1, 99) == 99
 *   WrapSub(5, 10, 1, 99) == 94 */
#define WrapSub(minuend, subtrahend, min, max, ...) _Generic(minuend + subtrahend + min + max, int: WrapSubS32, s32: WrapSubS32, u32: WrapSubU32)(minuend, subtrahend, min, max, IF_EMPTY(&(bool32){0} __VA_OPT__(, __VA_ARGS__)))
#define WrapSubPtr(minuend, subtrahend, min, max) ({ bool32 wrapped; *minuend = WrapSub(*minuend, subtrahend, min, max, &wrapped); wrapped; })

s32 SatAddS32(s32 addend1, s32 addend2, s32 min, s32 max, bool32 *saturated);
s32 SatSubS32(s32 minuend, s32 subtrahend, s32 min, s32 max, bool32 *saturated);
s32 WrapAddS32(s32 addend1, s32 addend2, s32 min, s32 max, bool32 *wrapped);
s32 WrapSubS32(s32 minuend, s32 subtrahend, s32 min, s32 max, bool32 *wrapped);

u32 SatAddU32(u32 addend1, u32 addend2, u32 min, u32 max, bool32 *saturated);
u32 SatSubU32(u32 minuend, u32 subtrahend, u32 min, u32 max, bool32 *saturated);
u32 WrapAddU32(u32 addend1, u32 addend2, u32 min, u32 max, bool32 *wrapped);
u32 WrapSubU32(u32 minuend, u32 subtrahend, u32 min, u32 max, bool32 *wrapped);

#endif // GUARD_UTIL_H
