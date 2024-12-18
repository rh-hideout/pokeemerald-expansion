#include "global.h"
#include "main.h"
#include "malloc.h"
#include "random.h"
#include "sprite.h"
#include "test/test.h"

TEST("Compression test: tileset smol")
{
    static const u32 origFile[] = INCBIN_U32("test/compression/tilesetTest.4bpp");
    static const u32 compFile[] = INCBIN_U32("test/compression/tilesetTest.4bpp.smol");
    u32 imageSize = GetDecompressedDataSize(compFile);
    u32 *compBuffer = Alloc(imageSize);
    CycleCountStart();
    LZDecompressWram(compFile, compBuffer);
    u32 timeTaken = CycleCountEnd();
    DebugPrintf("Time Tileset Smol: %u", timeTaken);

    u32 val1 = 0;
    u32 val2 = 0;
    bool32 areEqual = TRUE;
    for (u32 i = 0; i < imageSize/4; i++)
    {
        val1 = origFile[i];
        val2 = compBuffer[i];
        if (val1 != val2)
        {
            areEqual = FALSE;
            break;
        }
    }

    EXPECT_EQ(areEqual, TRUE);

    Free(compBuffer);
}

TEST("Compression test: tileset LZ")
{
    static const u32 origFile[] = INCBIN_U32("test/compression/tilesetTest.4bpp");
    static const u32 compFile[] = INCBIN_U32("test/compression/tilesetTest.4bpp.lz");
    u32 imageSize = GetDecompressedDataSize(compFile);
    u32 *compBuffer = Alloc(imageSize);
    CycleCountStart();
    LZDecompressWram(compFile, compBuffer);
    u32 timeTaken = CycleCountEnd();
    DebugPrintf("Time Tileset LZ: %u", timeTaken);

    u32 val1 = 0;
    u32 val2 = 0;
    bool32 areEqual = TRUE;
    for (u32 i = 0; i < imageSize/4; i++)
    {
        val1 = origFile[i];
        val2 = compBuffer[i];
        if (val1 != val2)
        {
            areEqual = FALSE;
            break;
        }
    }

    EXPECT_EQ(areEqual, TRUE);

    Free(compBuffer);
}

TEST("Compression test: simple battle sprite smol")
{
    static const u32 origFile[] = INCBIN_U32("test/compression/simple_battle_sprite.4bpp");
    static const u32 compFile[] = INCBIN_U32("test/compression/simple_battle_sprite.4bpp.smol");
    u32 imageSize = GetDecompressedDataSize(compFile);
    u32 *compBuffer = Alloc(imageSize);
    CycleCountStart();
    LZDecompressWram(compFile, compBuffer);
    u32 timeTaken = CycleCountEnd();
    DebugPrintf("Time Simple Sprite smol: %u", timeTaken);

    u32 val1 = 0;
    u32 val2 = 0;
    bool32 areEqual = TRUE;
    for (u32 i = 0; i < imageSize/4; i++)
    {
        val1 = origFile[i];
        val2 = compBuffer[i];
        if (val1 != val2)
        {
            areEqual = FALSE;
            break;
        }
    }

    EXPECT_EQ(areEqual, TRUE);

    Free(compBuffer);
}

TEST("Compression test: simple battle sprite LZ")
{
    static const u32 origFile[] = INCBIN_U32("test/compression/simple_battle_sprite.4bpp");
    static const u32 compFile[] = INCBIN_U32("test/compression/simple_battle_sprite.4bpp.lz");
    u32 imageSize = GetDecompressedDataSize(compFile);
    u32 *compBuffer = Alloc(imageSize);
    CycleCountStart();
    LZDecompressWram(compFile, compBuffer);
    u32 timeTaken = CycleCountEnd();
    DebugPrintf("Time Simple Sprite LZ: %u", timeTaken);

    u32 val1 = 0;
    u32 val2 = 0;
    bool32 areEqual = TRUE;
    for (u32 i = 0; i < imageSize/4; i++)
    {
        val1 = origFile[i];
        val2 = compBuffer[i];
        if (val1 != val2)
        {
            areEqual = FALSE;
            break;
        }
    }

    EXPECT_EQ(areEqual, TRUE);

    Free(compBuffer);
}

TEST("Compression test: complex battle sprite")
{
    static const u32 origFile[] = INCBIN_U32("test/compression/complex_battle_sprite.4bpp");
    static const u32 compFile[] = INCBIN_U32("test/compression/complex_battle_sprite.4bpp.smol");
    u32 imageSize = GetDecompressedDataSize(compFile);
    u32 *compBuffer = Alloc(imageSize);
    CycleCountStart();
    LZDecompressWram(compFile, compBuffer);
    u32 timeTaken = CycleCountEnd();
    DebugPrintf("Time Complex Sprite smol: %u", timeTaken);

    u32 val1 = 0;
    u32 val2 = 0;
    bool32 areEqual = TRUE;
    for (u32 i = 0; i < imageSize/4; i++)
    {
        val1 = origFile[i];
        val2 = compBuffer[i];
        if (val1 != val2)
        {
            areEqual = FALSE;
            break;
        }
    }

    EXPECT_EQ(areEqual, TRUE);

    Free(compBuffer);
}

TEST("Compression test: complex battle sprite")
{
    static const u32 origFile[] = INCBIN_U32("test/compression/complex_battle_sprite.4bpp");
    static const u32 compFile[] = INCBIN_U32("test/compression/complex_battle_sprite.4bpp.lz");
    u32 imageSize = GetDecompressedDataSize(compFile);
    u32 *compBuffer = Alloc(imageSize);
    CycleCountStart();
    LZDecompressWram(compFile, compBuffer);
    u32 timeTaken = CycleCountEnd();
    DebugPrintf("Time Complex Sprite LZ: %u", timeTaken);

    u32 val1 = 0;
    u32 val2 = 0;
    bool32 areEqual = TRUE;
    for (u32 i = 0; i < imageSize/4; i++)
    {
        val1 = origFile[i];
        val2 = compBuffer[i];
        if (val1 != val2)
        {
            areEqual = FALSE;
            break;
        }
    }

    EXPECT_EQ(areEqual, TRUE);

    Free(compBuffer);
}

TEST("Compression test: Gossifleur")
{
    static const u32 origFile[] = INCBIN_U32("test/compression/gossifleur.4bpp");
    static const u32 compFile[] = INCBIN_U32("test/compression/gossifleur.4bpp.smol");
    u32 imageSize = GetDecompressedDataSize(compFile);
    u32 *compBuffer = Alloc(imageSize);
    CycleCountStart();
    LZDecompressWram(compFile, compBuffer);
    u32 timeTaken = CycleCountEnd();
    DebugPrintf("Gossifleur: %u", timeTaken);

    u32 val1 = 0;
    u32 val2 = 0;
    bool32 areEqual = TRUE;
    for (u32 i = 0; i < imageSize/4; i++)
    {
        val1 = origFile[i];
        val2 = compBuffer[i];
        if (val1 != val2)
        {
            areEqual = FALSE;
            break;
        }
    }

    EXPECT_EQ(areEqual, TRUE);

    Free(compBuffer);
}

TEST("Compression test: bubbles")
{
    static const u32 origFile[] = INCBIN_U32("test/compression/small_bubbles.4bpp");
    static const u32 compFile[] = INCBIN_U32("test/compression/small_bubbles.4bpp.smol");
    u32 imageSize = GetDecompressedDataSize(compFile);
    u32 *compBuffer = Alloc(imageSize);
    CycleCountStart();
    LZDecompressWram(compFile, compBuffer);
    u32 timeTaken = CycleCountEnd();
    DebugPrintf("Small Bubbles: %u", timeTaken);

    u32 val1 = 0;
    u32 val2 = 0;
    bool32 areEqual = TRUE;
    for (u32 i = 0; i < imageSize/4; i++)
    {
        val1 = origFile[i];
        val2 = compBuffer[i];
        if (val1 != val2)
        {
            areEqual = FALSE;
            break;
        }
    }

    EXPECT_EQ(areEqual, TRUE);

    Free(compBuffer);
}

TEST("Compression test: small mode 0")
{
    static const u32 origFile[] = INCBIN_U32("test/compression/small_mode_0.4bpp");
    static const u32 compFile[] = INCBIN_U32("test/compression/small_mode_0.4bpp.smol");
    u32 imageSize = GetDecompressedDataSize(compFile);
    u32 *compBuffer = Alloc(imageSize);
    CycleCountStart();
    LZDecompressWram(compFile, compBuffer);
    u32 timeTaken = CycleCountEnd();
    DebugPrintf("Small mode 0: %u", timeTaken);

    u32 val1 = 0;
    u32 val2 = 0;
    bool32 areEqual = TRUE;
    for (u32 i = 0; i < imageSize/4; i++)
    {
        val1 = origFile[i];
        val2 = compBuffer[i];
        if (val1 != val2)
        {
            areEqual = FALSE;
            break;
        }
    }

    EXPECT_EQ(areEqual, TRUE);

    Free(compBuffer);
}
TEST("Compression test: medium mode 0")
{
    static const u32 origFile[] = INCBIN_U32("test/compression/medium_mode_0.4bpp");
    static const u32 compFile[] = INCBIN_U32("test/compression/medium_mode_0.4bpp.smol");
    u32 imageSize = GetDecompressedDataSize(compFile);
    u32 *compBuffer = Alloc(imageSize);
    CycleCountStart();
    LZDecompressWram(compFile, compBuffer);
    u32 timeTaken = CycleCountEnd();
    DebugPrintf("Medium mode 0: %u", timeTaken);

    u32 val1 = 0;
    u32 val2 = 0;
    bool32 areEqual = TRUE;
    for (u32 i = 0; i < imageSize/4; i++)
    {
        val1 = origFile[i];
        val2 = compBuffer[i];
        if (val1 != val2)
        {
            areEqual = FALSE;
            break;
        }
    }

    EXPECT_EQ(areEqual, TRUE);

    Free(compBuffer);
}

TEST("Compression test: large mode 0")
{
    static const u32 origFile[] = INCBIN_U32("test/compression/large_mode_0.4bpp");
    static const u32 compFile[] = INCBIN_U32("test/compression/large_mode_0.4bpp.smol");
    u32 imageSize = GetDecompressedDataSize(compFile);
    u32 *compBuffer = Alloc(imageSize);
    CycleCountStart();
    LZDecompressWram(compFile, compBuffer);
    u32 timeTaken = CycleCountEnd();
    DebugPrintf("Large mode 0: %u", timeTaken);

    u32 val1 = 0;
    u32 val2 = 0;
    bool32 areEqual = TRUE;
    for (u32 i = 0; i < imageSize/4; i++)
    {
        val1 = origFile[i];
        val2 = compBuffer[i];
        if (val1 != val2)
        {
            areEqual = FALSE;
            break;
        }
    }

    EXPECT_EQ(areEqual, TRUE);

    Free(compBuffer);
}

TEST("Compression test: small mode 1")
{
    static const u32 origFile[] = INCBIN_U32("test/compression/small_mode_1.4bpp");
    static const u32 compFile[] = INCBIN_U32("test/compression/small_mode_1.4bpp.smol");
    u32 imageSize = GetDecompressedDataSize(compFile);
    u32 *compBuffer = Alloc(imageSize);
    CycleCountStart();
    LZDecompressWram(compFile, compBuffer);
    u32 timeTaken = CycleCountEnd();
    DebugPrintf("Small mode 1: %u", timeTaken);

    u32 val1 = 0;
    u32 val2 = 0;
    bool32 areEqual = TRUE;
    for (u32 i = 0; i < imageSize/4; i++)
    {
        val1 = origFile[i];
        val2 = compBuffer[i];
        if (val1 != val2)
        {
            areEqual = FALSE;
            break;
        }
    }

    EXPECT_EQ(areEqual, TRUE);

    Free(compBuffer);
}

TEST("Compression test: medium mode 1")
{
    static const u32 origFile[] = INCBIN_U32("test/compression/medium_mode_1.4bpp");
    static const u32 compFile[] = INCBIN_U32("test/compression/medium_mode_1.4bpp.smol");
    u32 imageSize = GetDecompressedDataSize(compFile);
    u32 *compBuffer = Alloc(imageSize);
    CycleCountStart();
    LZDecompressWram(compFile, compBuffer);
    u32 timeTaken = CycleCountEnd();
    DebugPrintf("Medium mode 1: %u", timeTaken);

    u32 val1 = 0;
    u32 val2 = 0;
    bool32 areEqual = TRUE;
    for (u32 i = 0; i < imageSize/4; i++)
    {
        val1 = origFile[i];
        val2 = compBuffer[i];
        if (val1 != val2)
        {
            areEqual = FALSE;
            break;
        }
    }

    EXPECT_EQ(areEqual, TRUE);

    Free(compBuffer);
}

TEST("Compression test: large mode 1")
{
    static const u32 origFile[] = INCBIN_U32("test/compression/large_mode_1.4bpp");
    static const u32 compFile[] = INCBIN_U32("test/compression/large_mode_1.4bpp.smol");
    u32 imageSize = GetDecompressedDataSize(compFile);
    u32 *compBuffer = Alloc(imageSize);
    CycleCountStart();
    LZDecompressWram(compFile, compBuffer);
    u32 timeTaken = CycleCountEnd();
    DebugPrintf("Large mode 1: %u", timeTaken);

    u32 val1 = 0;
    u32 val2 = 0;
    bool32 areEqual = TRUE;
    for (u32 i = 0; i < imageSize/4; i++)
    {
        val1 = origFile[i];
        val2 = compBuffer[i];
        if (val1 != val2)
        {
            areEqual = FALSE;
            break;
        }
    }

    EXPECT_EQ(areEqual, TRUE);

    Free(compBuffer);
}

TEST("Compression test: small mode 2")
{
    static const u32 origFile[] = INCBIN_U32("test/compression/small_mode_2.4bpp");
    static const u32 compFile[] = INCBIN_U32("test/compression/small_mode_2.4bpp.smol");
    u32 imageSize = GetDecompressedDataSize(compFile);
    u32 *compBuffer = Alloc(imageSize);
    CycleCountStart();
    LZDecompressWram(compFile, compBuffer);
    u32 timeTaken = CycleCountEnd();
    DebugPrintf("Small mode 2: %u", timeTaken);

    u32 val1 = 0;
    u32 val2 = 0;
    bool32 areEqual = TRUE;
    for (u32 i = 0; i < imageSize/4; i++)
    {
        val1 = origFile[i];
        val2 = compBuffer[i];
        if (val1 != val2)
        {
            areEqual = FALSE;
            break;
        }
    }

    EXPECT_EQ(areEqual, TRUE);

    Free(compBuffer);
}

TEST("Compression test: medium mode 2")
{
    static const u32 origFile[] = INCBIN_U32("test/compression/medium_mode_2.4bpp");
    static const u32 compFile[] = INCBIN_U32("test/compression/medium_mode_2.4bpp.smol");
    u32 imageSize = GetDecompressedDataSize(compFile);
    u32 *compBuffer = Alloc(imageSize);
    CycleCountStart();
    LZDecompressWram(compFile, compBuffer);
    u32 timeTaken = CycleCountEnd();
    DebugPrintf("Medium mode 2: %u", timeTaken);

    u32 val1 = 0;
    u32 val2 = 0;
    bool32 areEqual = TRUE;
    for (u32 i = 0; i < imageSize/4; i++)
    {
        val1 = origFile[i];
        val2 = compBuffer[i];
        if (val1 != val2)
        {
            areEqual = FALSE;
            break;
        }
    }

    EXPECT_EQ(areEqual, TRUE);

    Free(compBuffer);
}

TEST("Compression test: large mode 2")
{
    static const u32 origFile[] = INCBIN_U32("test/compression/large_mode_2.4bpp");
    static const u32 compFile[] = INCBIN_U32("test/compression/large_mode_2.4bpp.smol");
    u32 imageSize = GetDecompressedDataSize(compFile);
    u32 *compBuffer = Alloc(imageSize);
    CycleCountStart();
    LZDecompressWram(compFile, compBuffer);
    u32 timeTaken = CycleCountEnd();
    DebugPrintf("Large mode 2: %u", timeTaken);

    u32 val1 = 0;
    u32 val2 = 0;
    bool32 areEqual = TRUE;
    for (u32 i = 0; i < imageSize/4; i++)
    {
        val1 = origFile[i];
        val2 = compBuffer[i];
        if (val1 != val2)
        {
            areEqual = FALSE;
            break;
        }
    }

    EXPECT_EQ(areEqual, TRUE);

    Free(compBuffer);
}

TEST("Compression test: small mode 3")
{
    static const u32 origFile[] = INCBIN_U32("test/compression/small_mode_3.4bpp");
    static const u32 compFile[] = INCBIN_U32("test/compression/small_mode_3.4bpp.smol");
    u32 imageSize = GetDecompressedDataSize(compFile);
    u32 *compBuffer = Alloc(imageSize);
    CycleCountStart();
    LZDecompressWram(compFile, compBuffer);
    u32 timeTaken = CycleCountEnd();
    DebugPrintf("Small mode 3: %u", timeTaken);

    u32 val1 = 0;
    u32 val2 = 0;
    bool32 areEqual = TRUE;
    for (u32 i = 0; i < imageSize/4; i++)
    {
        val1 = origFile[i];
        val2 = compBuffer[i];
        if (val1 != val2)
        {
            areEqual = FALSE;
            break;
        }
    }

    EXPECT_EQ(areEqual, TRUE);

    Free(compBuffer);
}

TEST("Compression test: medium mode 3")
{
    static const u32 origFile[] = INCBIN_U32("test/compression/medium_mode_3.4bpp");
    static const u32 compFile[] = INCBIN_U32("test/compression/medium_mode_3.4bpp.smol");
    u32 imageSize = GetDecompressedDataSize(compFile);
    u32 *compBuffer = Alloc(imageSize);
    CycleCountStart();
    LZDecompressWram(compFile, compBuffer);
    u32 timeTaken = CycleCountEnd();
    DebugPrintf("Medium mode 3: %u", timeTaken);

    u32 val1 = 0;
    u32 val2 = 0;
    bool32 areEqual = TRUE;
    for (u32 i = 0; i < imageSize/4; i++)
    {
        val1 = origFile[i];
        val2 = compBuffer[i];
        if (val1 != val2)
        {
            areEqual = FALSE;
            break;
        }
    }

    EXPECT_EQ(areEqual, TRUE);

    Free(compBuffer);
}

TEST("Compression test: large mode 3")
{
    static const u32 origFile[] = INCBIN_U32("test/compression/large_mode_3.4bpp");
    static const u32 compFile[] = INCBIN_U32("test/compression/large_mode_3.4bpp.smol");
    u32 imageSize = GetDecompressedDataSize(compFile);
    u32 *compBuffer = Alloc(imageSize);
    CycleCountStart();
    LZDecompressWram(compFile, compBuffer);
    u32 timeTaken = CycleCountEnd();
    DebugPrintf("Large mode 3: %u", timeTaken);

    u32 val1 = 0;
    u32 val2 = 0;
    bool32 areEqual = TRUE;
    for (u32 i = 0; i < imageSize/4; i++)
    {
        val1 = origFile[i];
        val2 = compBuffer[i];
        if (val1 != val2)
        {
            areEqual = FALSE;
            break;
        }
    }

    EXPECT_EQ(areEqual, TRUE);

    Free(compBuffer);
}

TEST("Compression test: small mode 4")
{
    static const u32 origFile[] = INCBIN_U32("test/compression/small_mode_4.4bpp");
    static const u32 compFile[] = INCBIN_U32("test/compression/small_mode_4.4bpp.smol");
    u32 imageSize = GetDecompressedDataSize(compFile);
    u32 *compBuffer = Alloc(imageSize);
    CycleCountStart();
    LZDecompressWram(compFile, compBuffer);
    u32 timeTaken = CycleCountEnd();
    DebugPrintf("Small mode 4: %u", timeTaken);

    u32 val1 = 0;
    u32 val2 = 0;
    bool32 areEqual = TRUE;
    for (u32 i = 0; i < imageSize/4; i++)
    {
        val1 = origFile[i];
        val2 = compBuffer[i];
        if (val1 != val2)
        {
            areEqual = FALSE;
            break;
        }
    }

    EXPECT_EQ(areEqual, TRUE);

    Free(compBuffer);
}

TEST("Compression test: medium mode 4")
{
    static const u32 origFile[] = INCBIN_U32("test/compression/medium_mode_4.4bpp");
    static const u32 compFile[] = INCBIN_U32("test/compression/medium_mode_4.4bpp.smol");
    u32 imageSize = GetDecompressedDataSize(compFile);
    u32 *compBuffer = Alloc(imageSize);
    CycleCountStart();
    LZDecompressWram(compFile, compBuffer);
    u32 timeTaken = CycleCountEnd();
    DebugPrintf("Medium mode 4: %u", timeTaken);

    u32 val1 = 0;
    u32 val2 = 0;
    bool32 areEqual = TRUE;
    for (u32 i = 0; i < imageSize/4; i++)
    {
        val1 = origFile[i];
        val2 = compBuffer[i];
        if (val1 != val2)
        {
            areEqual = FALSE;
            break;
        }
    }

    EXPECT_EQ(areEqual, TRUE);

    Free(compBuffer);
}

TEST("Compression test: large mode 4")
{
    static const u32 origFile[] = INCBIN_U32("test/compression/large_mode_4.4bpp");
    static const u32 compFile[] = INCBIN_U32("test/compression/large_mode_4.4bpp.smol");
    u32 imageSize = GetDecompressedDataSize(compFile);
    u32 *compBuffer = Alloc(imageSize);
    CycleCountStart();
    LZDecompressWram(compFile, compBuffer);
    u32 timeTaken = CycleCountEnd();
    DebugPrintf("Large mode 4: %u", timeTaken);

    u32 val1 = 0;
    u32 val2 = 0;
    bool32 areEqual = TRUE;
    for (u32 i = 0; i < imageSize/4; i++)
    {
        val1 = origFile[i];
        val2 = compBuffer[i];
        if (val1 != val2)
        {
            areEqual = FALSE;
            break;
        }
    }

    EXPECT_EQ(areEqual, TRUE);

    Free(compBuffer);
}

TEST("Compression test: small mode 5")
{
    static const u32 origFile[] = INCBIN_U32("test/compression/small_mode_5.4bpp");
    static const u32 compFile[] = INCBIN_U32("test/compression/small_mode_5.4bpp.smol");
    u32 imageSize = GetDecompressedDataSize(compFile);
    u32 *compBuffer = Alloc(imageSize);
    CycleCountStart();
    LZDecompressWram(compFile, compBuffer);
    u32 timeTaken = CycleCountEnd();
    DebugPrintf("Small mode 5: %u", timeTaken);

    u32 val1 = 0;
    u32 val2 = 0;
    bool32 areEqual = TRUE;
    for (u32 i = 0; i < imageSize/4; i++)
    {
        val1 = origFile[i];
        val2 = compBuffer[i];
        if (val1 != val2)
        {
            areEqual = FALSE;
            break;
        }
    }

    EXPECT_EQ(areEqual, TRUE);

    Free(compBuffer);
}

TEST("Compression test: medium mode 5")
{
    static const u32 origFile[] = INCBIN_U32("test/compression/medium_mode_5.4bpp");
    static const u32 compFile[] = INCBIN_U32("test/compression/medium_mode_5.4bpp.smol");
    u32 imageSize = GetDecompressedDataSize(compFile);
    u32 *compBuffer = Alloc(imageSize);
    CycleCountStart();
    LZDecompressWram(compFile, compBuffer);
    u32 timeTaken = CycleCountEnd();
    DebugPrintf("Medium mode 5: %u", timeTaken);

    u32 val1 = 0;
    u32 val2 = 0;
    bool32 areEqual = TRUE;
    for (u32 i = 0; i < imageSize/4; i++)
    {
        val1 = origFile[i];
        val2 = compBuffer[i];
        if (val1 != val2)
        {
            areEqual = FALSE;
            break;
        }
    }

    EXPECT_EQ(areEqual, TRUE);

    Free(compBuffer);
}

TEST("Compression test: large mode 5")
{
    static const u32 origFile[] = INCBIN_U32("test/compression/large_mode_5.4bpp");
    static const u32 compFile[] = INCBIN_U32("test/compression/large_mode_5.4bpp.smol");
    u32 imageSize = GetDecompressedDataSize(compFile);
    u32 *compBuffer = Alloc(imageSize);
    CycleCountStart();
    LZDecompressWram(compFile, compBuffer);
    u32 timeTaken = CycleCountEnd();
    DebugPrintf("Large mode 5: %u", timeTaken);

    u32 val1 = 0;
    u32 val2 = 0;
    bool32 areEqual = TRUE;
    for (u32 i = 0; i < imageSize/4; i++)
    {
        val1 = origFile[i];
        val2 = compBuffer[i];
        if (val1 != val2)
        {
            areEqual = FALSE;
            break;
        }
    }

    EXPECT_EQ(areEqual, TRUE);

    Free(compBuffer);
}
