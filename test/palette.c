#include "global.h"
#include "main.h"
#include "malloc.h"
#include "palette_util.h"
#include "random.h"
#include "sprite.h"
#include "test/test.h"
#include <string.h>

#define OLD_INDEX 9
#define NEW_INDEX 7

static const Tile4BPP sOriginalTile = 
{
    {
        0xB00B6969,
        0xB00B6969,
        0xB00B6969,
        0xB00B6969,
        0xB00B6969,
        0xB00B6969,
        0xB00B6969,
        0xB00B6969,
    },
};

static const Tile4BPP sTargetTile = 
{
    {
        0xB00B6767,
        0xB00B6767,
        0xB00B6767,
        0xB00B6767,
        0xB00B6767,
        0xB00B6767,
        0xB00B6767,
        0xB00B6767,
    },
};

// Naive version of ReplacePalIndexInTile for testing and benchmarking
static void ReplacePalIndexInTileNaive(void *tileAddress, u32 oldIndex, u32 newIndex)
{
    for (u32 i = 0; i < 64; i++)
    {
        // two pixels are packed into one byte
        u8 *byte = (u8*)tileAddress + i / 2;

        if (i & 1) // odd pixel
        {
            if (((*byte >> 4) & 0xF) == oldIndex)
            {
                *byte &= ~0xF0;
                *byte |= (newIndex << 4);
            }
        }
        else // even pixel
        {
            if ((*byte & 0xF) == oldIndex)
            {
                *byte &= ~0xF;
                *byte |= newIndex;
            }
        }
    }
}

TEST("ReplacePalIndexInTile works")
{
    Tile4BPP original = sOriginalTile;

    ReplacePalIndexInTile(&original, OLD_INDEX, NEW_INDEX);
    s32 res = memcmp(&original, &sTargetTile, sizeof(sOriginalTile));

    EXPECT_EQ(res, 0);
}

TEST("ReplacePalIndexInTile and ReplacePalIndexInTileNaive produce the same output")
{
    Tile4BPP naive = sOriginalTile;
    Tile4BPP optimised = sOriginalTile;

    ReplacePalIndexInTileNaive(&naive, OLD_INDEX, NEW_INDEX);
    ReplacePalIndexInTile(&optimised, OLD_INDEX, NEW_INDEX);

    s32 res = memcmp(&naive, &optimised, sizeof(Tile4BPP));

    EXPECT_EQ(res, 0);
}

TEST("ReplacePalIndexInTile is faster than ReplacePalIndexInTileNaive")
{
    struct Benchmark naive, optimised;

    Tile4BPP originalNaive = sOriginalTile;

    BENCHMARK(&naive)
    {
        ReplacePalIndexInTileNaive(&originalNaive, OLD_INDEX, NEW_INDEX);
    }

    Tile4BPP originalOptimised = sOriginalTile;

    BENCHMARK(&optimised)
    {
        ReplacePalIndexInTile(&originalOptimised, OLD_INDEX, NEW_INDEX);
    }

    EXPECT_FASTER(optimised, naive);
}
