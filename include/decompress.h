#ifndef GUARD_DECOMPRESS_H
#define GUARD_DECOMPRESS_H

#include "sprite.h"

#define TANS_TABLE_SIZE     64
#define PACKED_FREQ_MASK    0x3F
#define PARTIAL_FREQ_MASK   0xC0000000

#define FIRST_LO_MASK   0x7f
#define CONTINUE_BIT    0x80

#define SMOL_IMAGE_SIZE_MULTIPLIER 16


extern u8 ALIGNED(4) gDecompressionBuffer[0x4000];

struct LZ77Header {
    u32 lz77IdBits:5;
    u32 padding:3;
    u32 size:24;
};

struct SmolHeader {
    u32 mode:5;
    u32 imageSize:12;
    u32 symSize:15;
    u32 initialState:6;
    u32 bitstreamSize:13;
    u32 loSize:13;
};

union CompressionHeader {
    struct LZ77Header lz77;
    struct SmolHeader smol;
};

struct SpriteSheetHeader {
    u32 mode:5;
    u32 numComponents:11;
    u32 framesPerComponent:16;
};

struct DecodeYK {
    u8 yVal;
    u8 kVal;
};

enum CompressionMode {
    BASE_ONLY = 0,
    ENCODE_SYMS = 1,
    ENCODE_DELTA_SYMS = 2,
    ENCODE_LO = 3,
    ENCODE_BOTH = 4,
    ENCODE_BOTH_DELTA_SYMS = 5,
    IS_FRAME_CONTAINER = 6,
    MODE_LZ77 = 16,
};

extern struct DecodeYK ykTemplate[2*TANS_TABLE_SIZE];

void UnpackFrequencies(const u32 *packedFreqs, u32 *freqs);

void DecompressDataVram(const u32 *src, void *dest);
void DecompressDataWram(const u32 *src, void *dest);

//  For decompressing a single part of a multi-part spritesheet
//void DecompressSubFrame(const u32 *src, void *dest, u32 frameId);

void SmolDecompressData(const struct SmolHeader *header, const u32 *data, void *dest);

void BuildDecompressionTable(const u32 *freqs, struct DecodeYK *ykTable, u32 *symbolTable);

void DecodeLOtANS(const u32 *data, const u32 *pFreqs, u8 *resultVec, u32 count);

void DecodeSymtANS(const u32 *data, const u32 *pFreqs, u16 *resultVec, u32 count);

void DecodeSymDeltatANS(const u32 *data, const u32 *pFreqs, u16 *resultVec, u32 count);

void DecodeInstructions(u32 headerLoSize, u8 *loVec, u16 *symVec, void *dest);

bool32 isModeLoEncoded(enum CompressionMode mode);
bool32 isModeSymEncoded(enum CompressionMode mode);
bool32 isModeSymDelta(enum CompressionMode mode);

//  Default Decompression functions are below here
void LZDecompressWram(const u32 *src, void *dest);
void LZDecompressVram(const u32 *src, void *dest);

u32 IsLZ77Data(const void *ptr, u32 minSize, u32 maxSize);

u16 LoadCompressedSpriteSheet(const struct CompressedSpriteSheet *src);
u16 LoadCompressedSpriteSheetByTemplate(const struct SpriteTemplate *template, s32 offset);
void LoadCompressedSpriteSheetOverrideBuffer(const struct CompressedSpriteSheet *src, void *buffer);
bool8 LoadCompressedSpriteSheetUsingHeap(const struct CompressedSpriteSheet *src);

void LoadCompressedSpritePalette(const struct CompressedSpritePalette *src);
void LoadCompressedSpritePaletteWithTag(const u32 *pal, u16 tag);
void LoadCompressedSpritePaletteOverrideBuffer(const struct CompressedSpritePalette *src, void *buffer);
bool8 LoadCompressedSpritePaletteUsingHeap(const struct CompressedSpritePalette *src);

void DecompressPicFromTable(const struct CompressedSpriteSheet *src, void *buffer);

void HandleLoadSpecialPokePic(bool32 isFrontPic, void *dest, s32 species, u32 personality);

void LoadSpecialPokePic(void *dest, s32 species, u32 personality, bool8 isFrontPic);

u32 GetDecompressedDataSize(const u32 *ptr);

#endif // GUARD_DECOMPRESS_H
