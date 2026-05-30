#include "global.h"
#include "test/test.h"
#include "util.h"

TEST("SatAddS32")
{
    s32 addend1, addend2, min, max;
    s32 expectedResult, actualResult;
    bool32 expectedSaturated, actualSaturated;

    // No saturation.
    PARAMETRIZE { addend1 = 9; addend2 = 0; min = 1; max = 9; expectedResult = 9; expectedSaturated = FALSE; }
    PARAMETRIZE { addend1 = 8; addend2 = 1; min = 1; max = 9; expectedResult = 9; expectedSaturated = FALSE; }
    PARAMETRIZE { addend1 = 9; addend2 = -1; min = 1; max = 9; expectedResult = 8; expectedSaturated = FALSE; }

    // Saturate.
    PARAMETRIZE { addend1 = 9; addend2 = 1; min = 1; max = 9; expectedResult = 9; expectedSaturated = TRUE; }
    PARAMETRIZE { addend1 = 9; addend2 = 2; min = 1; max = 9; expectedResult = 9; expectedSaturated = TRUE; }
    PARAMETRIZE { addend1 = 9; addend2 = 10; min = 1; max = 9; expectedResult = 9; expectedSaturated = TRUE; }
    PARAMETRIZE { addend1 = 9; addend2 = INT32_MAX; min = 1; max = 9; expectedResult = 9; expectedSaturated = TRUE; }
    PARAMETRIZE { addend1 = 9; addend2 = -10; min = 1; max = 9; expectedResult = 1; expectedSaturated = TRUE; }
    PARAMETRIZE { addend1 = 9; addend2 = -20; min = 1; max = 9; expectedResult = 1; expectedSaturated = TRUE; }
    PARAMETRIZE { addend1 = 9; addend2 = INT32_MIN; min = 1; max = 9; expectedResult = 1; expectedSaturated = TRUE; }

    actualResult = SatAdd(addend1, addend2, min, max, &actualSaturated);
    EXPECT_EQ(expectedResult, actualResult);
    EXPECT_EQ(expectedSaturated, actualSaturated);

    actualSaturated = SatAddPtr(&addend1, addend2, min, max);
    EXPECT_EQ(expectedResult, addend1);
    EXPECT_EQ(expectedSaturated, actualSaturated);
}

TEST("SatSubS32")
{
    s32 minuend, subtrahend, min, max;
    s32 expectedResult, actualResult;
    bool32 expectedSaturated, actualSaturated;

    // No saturation.
    PARAMETRIZE { minuend = 9; subtrahend = 0; min = 1; max = 9; expectedResult = 9; expectedSaturated = FALSE; }
    PARAMETRIZE { minuend = 8; subtrahend = -1; min = 1; max = 9; expectedResult = 9; expectedSaturated = FALSE; }
    PARAMETRIZE { minuend = 9; subtrahend = 1; min = 1; max = 9; expectedResult = 8; expectedSaturated = FALSE; }

    // Saturate.
    PARAMETRIZE { minuend = 1; subtrahend = 1; min = 1; max = 9; expectedResult = 1; expectedSaturated = TRUE; }
    PARAMETRIZE { minuend = 1; subtrahend = 2; min = 1; max = 9; expectedResult = 1; expectedSaturated = TRUE; }
    PARAMETRIZE { minuend = 1; subtrahend = 10; min = 1; max = 9; expectedResult = 1; expectedSaturated = TRUE; }
    PARAMETRIZE { minuend = 1; subtrahend = INT32_MAX; min = 1; max = 9; expectedResult = 1; expectedSaturated = TRUE; }
    PARAMETRIZE { minuend = 1; subtrahend = -10; min = 1; max = 9; expectedResult = 9; expectedSaturated = TRUE; }
    PARAMETRIZE { minuend = 1; subtrahend = -20; min = 1; max = 9; expectedResult = 9; expectedSaturated = TRUE; }
    PARAMETRIZE { minuend = 1; subtrahend = INT32_MIN; min = 1; max = 9; expectedResult = 9; expectedSaturated = TRUE; }

    actualResult = SatSub(minuend, subtrahend, min, max, &actualSaturated);
    EXPECT_EQ(expectedResult, actualResult);
    EXPECT_EQ(expectedSaturated, actualSaturated);

    actualSaturated = SatSubPtr(&minuend, subtrahend, min, max);
    EXPECT_EQ(expectedResult, minuend);
    EXPECT_EQ(expectedSaturated, actualSaturated);
}

TEST("WrapAddS32")
{
    s32 addend1, addend2, min, max;
    s32 expectedResult, actualResult;
    bool32 expectedWrapped, actualWrapped;

    // No wrap.
    PARAMETRIZE { addend1 = 9; addend2 = 0; min = 1; max = 9; expectedResult = 9; expectedWrapped = FALSE; }
    PARAMETRIZE { addend1 = 8; addend2 = 1; min = 1; max = 9; expectedResult = 9; expectedWrapped = FALSE; }
    PARAMETRIZE { addend1 = 9; addend2 = -1; min = 1; max = 9; expectedResult = 8; expectedWrapped = FALSE; }

    // Wrap by 1.
    PARAMETRIZE { addend1 = 9; addend2 = 1; min = 1; max = 9; expectedResult = 1; expectedWrapped = TRUE; }
    PARAMETRIZE { addend1 = 8; addend2 = 2; min = 1; max = 9; expectedResult = 1; expectedWrapped = TRUE; }
    PARAMETRIZE { addend1 = 9; addend2 = 10; min = 1; max = 9; expectedResult = 1; expectedWrapped = TRUE; }
    PARAMETRIZE { addend1 = 1; addend2 = -1; min = 1; max = 9; expectedResult = 9; expectedWrapped = TRUE; }
    PARAMETRIZE { addend1 = 2; addend2 = -2; min = 1; max = 9; expectedResult = 9; expectedWrapped = TRUE; }
    PARAMETRIZE { addend1 = 1; addend2 = -10; min = 1; max = 9; expectedResult = 9; expectedWrapped = TRUE; }

    // Wrap by 2.
    PARAMETRIZE { addend1 = 9; addend2 = 2; min = 1; max = 9; expectedResult = 2; expectedWrapped = TRUE; }
    PARAMETRIZE { addend1 = 9; addend2 = 11; min = 1; max = 9; expectedResult = 2; expectedWrapped = TRUE; }
    PARAMETRIZE { addend1 = 1; addend2 = -2; min = 1; max = 9; expectedResult = 8; expectedWrapped = TRUE; }
    PARAMETRIZE { addend1 = 1; addend2 = -11; min = 1; max = 9; expectedResult = 8; expectedWrapped = TRUE; }

    // Near INT32_MIN/INT32_MAX.
    PARAMETRIZE { addend1 = INT32_MIN; addend2 = INT32_MIN; min = INT32_MIN; max = INT32_MAX; expectedResult = 0; expectedWrapped = TRUE; }
    PARAMETRIZE { addend1 = INT32_MIN; addend2 = 0; min = INT32_MIN; max = INT32_MAX; expectedResult = INT32_MIN; expectedWrapped = FALSE; }
    PARAMETRIZE { addend1 = INT32_MIN; addend2 = INT32_MAX; min = INT32_MIN; max = INT32_MAX; expectedResult = -1; expectedWrapped = FALSE; }
    PARAMETRIZE { addend1 = 0; addend2 = INT32_MIN; min = INT32_MIN; max = INT32_MAX; expectedResult = INT32_MIN; expectedWrapped = FALSE; }
    PARAMETRIZE { addend1 = 0; addend2 = INT32_MAX; min = INT32_MIN; max = INT32_MAX; expectedResult = INT32_MAX; expectedWrapped = FALSE; }
    PARAMETRIZE { addend1 = INT32_MAX; addend2 = INT32_MIN; min = INT32_MIN; max = INT32_MAX; expectedResult = -1; expectedWrapped = FALSE; }
    PARAMETRIZE { addend1 = INT32_MAX; addend2 = 0; min = INT32_MIN; max = INT32_MAX; expectedResult = INT32_MAX; expectedWrapped = FALSE; }
    PARAMETRIZE { addend1 = INT32_MAX; addend2 = INT32_MAX; min = INT32_MIN; max = INT32_MAX; expectedResult = -2; expectedWrapped = TRUE; }

    actualResult = WrapAdd(addend1, addend2, min, max, &actualWrapped);
    EXPECT_EQ(expectedResult, actualResult);
    EXPECT_EQ(expectedWrapped, actualWrapped);

    actualWrapped = WrapAddPtr(&addend1, addend2, min, max);
    EXPECT_EQ(expectedResult, addend1);
    EXPECT_EQ(expectedWrapped, actualWrapped);
}

TEST("WrapSubS32")
{
    s32 minuend, subtrahend, min, max;
    s32 expectedResult, actualResult;
    bool32 expectedWrapped, actualWrapped;

    // No wrap.
    PARAMETRIZE { minuend = 1; subtrahend = 0; min = 1; max = 9; expectedResult = 1; expectedWrapped = FALSE; }
    PARAMETRIZE { minuend = 2; subtrahend = 1; min = 1; max = 9; expectedResult = 1; expectedWrapped = FALSE; }
    PARAMETRIZE { minuend = 1; subtrahend = -1; min = 1; max = 9; expectedResult = 2; expectedWrapped = FALSE; }

    // Wrap by 1.
    PARAMETRIZE { minuend = 1; subtrahend = 1; min = 1; max = 9; expectedResult = 9; expectedWrapped = TRUE; }
    PARAMETRIZE { minuend = 2; subtrahend = 2; min = 1; max = 9; expectedResult = 9; expectedWrapped = TRUE; }
    PARAMETRIZE { minuend = 1; subtrahend = 10; min = 1; max = 9; expectedResult = 9; expectedWrapped = TRUE; }
    PARAMETRIZE { minuend = 9; subtrahend = -1; min = 1; max = 9; expectedResult = 1; expectedWrapped = TRUE; }
    PARAMETRIZE { minuend = 8; subtrahend = -2; min = 1; max = 9; expectedResult = 1; expectedWrapped = TRUE; }
    PARAMETRIZE { minuend = 9; subtrahend = -10; min = 1; max = 9; expectedResult = 1; expectedWrapped = TRUE; }

    // Wrap by 2.
    PARAMETRIZE { minuend = 1; subtrahend = 2; min = 1; max = 9; expectedResult = 8; expectedWrapped = TRUE; }
    PARAMETRIZE { minuend = 1; subtrahend = 11; min = 1; max = 9; expectedResult = 8; expectedWrapped = TRUE; }
    PARAMETRIZE { minuend = 9; subtrahend = -2; min = 1; max = 9; expectedResult = 2; expectedWrapped = TRUE; }
    PARAMETRIZE { minuend = 9; subtrahend = -11; min = 1; max = 9; expectedResult = 2; expectedWrapped = TRUE; }

    // Near INT32_MIN/INT32_MAX.
    PARAMETRIZE { minuend = INT32_MIN; subtrahend = INT32_MIN; min = INT32_MIN; max = INT32_MAX; expectedResult = 0; expectedWrapped = FALSE; }
    PARAMETRIZE { minuend = INT32_MIN; subtrahend = 0; min = INT32_MIN; max = INT32_MAX; expectedResult = INT32_MIN; expectedWrapped = FALSE; }
    PARAMETRIZE { minuend = INT32_MIN; subtrahend = INT32_MAX; min = INT32_MIN; max = INT32_MAX; expectedResult = 1; expectedWrapped = TRUE; }
    PARAMETRIZE { minuend = 0; subtrahend = INT32_MIN; min = INT32_MIN; max = INT32_MAX; expectedResult = INT32_MIN; expectedWrapped = TRUE; }
    PARAMETRIZE { minuend = 0; subtrahend = INT32_MAX; min = INT32_MIN; max = INT32_MAX; expectedResult = -INT32_MAX; expectedWrapped = FALSE; }
    PARAMETRIZE { minuend = INT32_MAX; subtrahend = INT32_MIN; min = INT32_MIN; max = INT32_MAX; expectedResult = -1; expectedWrapped = TRUE; }
    PARAMETRIZE { minuend = INT32_MAX; subtrahend = 0; min = INT32_MIN; max = INT32_MAX; expectedResult = INT32_MAX; expectedWrapped = FALSE; }
    PARAMETRIZE { minuend = INT32_MAX; subtrahend = INT32_MAX; min = INT32_MIN; max = INT32_MAX; expectedResult = 0; expectedWrapped = FALSE; }

    actualResult = WrapSub(minuend, subtrahend, min, max, &actualWrapped);
    EXPECT_EQ(expectedResult, actualResult);
    EXPECT_EQ(expectedWrapped, actualWrapped);

    actualWrapped = WrapSubPtr(&minuend, subtrahend, min, max);
    EXPECT_EQ(expectedResult, minuend);
    EXPECT_EQ(expectedWrapped, actualWrapped);
}

TEST("SatAddU32")
{
    u32 addend1, addend2, min, max;
    u32 expectedResult, actualResult;
    bool32 expectedSaturated, actualSaturated;

    // No saturation.
    PARAMETRIZE { addend1 = 9; addend2 = 0; min = 1; max = 9; expectedResult = 9; expectedSaturated = FALSE; }
    PARAMETRIZE { addend1 = 8; addend2 = 1; min = 1; max = 9; expectedResult = 9; expectedSaturated = FALSE; }

    // Saturate.
    PARAMETRIZE { addend1 = 9; addend2 = 1; min = 1; max = 9; expectedResult = 9; expectedSaturated = TRUE; }
    PARAMETRIZE { addend1 = 9; addend2 = 2; min = 1; max = 9; expectedResult = 9; expectedSaturated = TRUE; }
    PARAMETRIZE { addend1 = 9; addend2 = 10; min = 1; max = 9; expectedResult = 9; expectedSaturated = TRUE; }

    // Near UINT32_MAX.
    PARAMETRIZE { addend1 = UINT32_MAX; addend2 = 0; min = 0; max = UINT32_MAX; expectedResult = UINT32_MAX; expectedSaturated = FALSE; }
    PARAMETRIZE { addend1 = 0; addend2 = UINT32_MAX; min = 0; max = UINT32_MAX; expectedResult = UINT32_MAX; expectedSaturated = FALSE; }
    PARAMETRIZE { addend1 = UINT32_MAX; addend2 = 1; min = 0; max = UINT32_MAX; expectedResult = UINT32_MAX; expectedSaturated = TRUE; }
    PARAMETRIZE { addend1 = UINT32_MAX; addend2 = UINT32_MAX; min = 0; max = UINT32_MAX; expectedResult = UINT32_MAX; expectedSaturated = TRUE; }

    actualResult = SatAdd(addend1, addend2, min, max, &actualSaturated);
    EXPECT_EQ(expectedResult, actualResult);
    EXPECT_EQ(expectedSaturated, actualSaturated);

    actualSaturated = SatAddPtr(&addend1, addend2, min, max);
    EXPECT_EQ(expectedResult, addend1);
    EXPECT_EQ(expectedSaturated, actualSaturated);
}

TEST("SatSubU32")
{
    u32 minuend, subtrahend, min, max;
    u32 expectedResult, actualResult;
    bool32 expectedSaturated, actualSaturated;

    // No saturation.
    PARAMETRIZE { minuend = 1; subtrahend = 0; min = 1; max = 9; expectedResult = 1; expectedSaturated = FALSE; }
    PARAMETRIZE { minuend = 2; subtrahend = 1; min = 1; max = 9; expectedResult = 1; expectedSaturated = FALSE; }

    // Saturate.
    PARAMETRIZE { minuend = 1; subtrahend = 1; min = 1; max = 9; expectedResult = 1; expectedSaturated = TRUE; }
    PARAMETRIZE { minuend = 1; subtrahend = 2; min = 1; max = 9; expectedResult = 1; expectedSaturated = TRUE; }
    PARAMETRIZE { minuend = 1; subtrahend = 10; min = 1; max = 9; expectedResult = 1; expectedSaturated = TRUE; }

    // Near UINT32_MAX.
    PARAMETRIZE { minuend = UINT32_MAX; subtrahend = 0; min = 0; max = UINT32_MAX; expectedResult = UINT32_MAX; expectedSaturated = FALSE; }
    PARAMETRIZE { minuend = UINT32_MAX; subtrahend = UINT32_MAX; min = 0; max = UINT32_MAX; expectedResult = 0; expectedSaturated = FALSE; }
    PARAMETRIZE { minuend = UINT32_MAX - 1; subtrahend = UINT32_MAX; min = 0; max = UINT32_MAX; expectedResult = 0; expectedSaturated = TRUE; }
    PARAMETRIZE { minuend = 0; subtrahend = UINT32_MAX; min = 0; max = UINT32_MAX; expectedResult = 0; expectedSaturated = TRUE; }

    actualResult = SatSub(minuend, subtrahend, min, max, &actualSaturated);
    EXPECT_EQ(expectedResult, actualResult);
    EXPECT_EQ(expectedSaturated, actualSaturated);

    actualSaturated = SatSubPtr(&minuend, subtrahend, min, max);
    EXPECT_EQ(expectedResult, minuend);
    EXPECT_EQ(expectedSaturated, actualSaturated);
}

TEST("WrapAddU32")
{
    u32 addend1, addend2, min, max;
    u32 expectedResult, actualResult;
    bool32 expectedWrapped, actualWrapped;

    // No wrap.
    PARAMETRIZE { addend1 = 9; addend2 = 0; min = 1; max = 9; expectedResult = 9; expectedWrapped = FALSE; }
    PARAMETRIZE { addend1 = 8; addend2 = 1; min = 1; max = 9; expectedResult = 9; expectedWrapped = FALSE; }

    // Wrap by 1.
    PARAMETRIZE { addend1 = 9; addend2 = 1; min = 1; max = 9; expectedResult = 1; expectedWrapped = TRUE; }
    PARAMETRIZE { addend1 = 8; addend2 = 2; min = 1; max = 9; expectedResult = 1; expectedWrapped = TRUE; }
    PARAMETRIZE { addend1 = 9; addend2 = 10; min = 1; max = 9; expectedResult = 1; expectedWrapped = TRUE; }

    // Wrap by 2.
    PARAMETRIZE { addend1 = 9; addend2 = 2; min = 1; max = 9; expectedResult = 2; expectedWrapped = TRUE; }
    PARAMETRIZE { addend1 = 9; addend2 = 11; min = 1; max = 9; expectedResult = 2; expectedWrapped = TRUE; }

    // Near UINT32_MAX.
    PARAMETRIZE { addend1 = UINT32_MAX; addend2 = 0; min = 0; max = UINT32_MAX; expectedResult = UINT32_MAX; expectedWrapped = FALSE; }
    PARAMETRIZE { addend1 = UINT32_MAX; addend2 = 1; min = 0; max = UINT32_MAX; expectedResult = 0; expectedWrapped = TRUE; }
    PARAMETRIZE { addend1 = UINT32_MAX; addend2 = UINT32_MAX; min = 0; max = UINT32_MAX; expectedResult = UINT32_MAX - 1; expectedWrapped = TRUE; }

    actualResult = WrapAdd(addend1, addend2, min, max, &actualWrapped);
    EXPECT_EQ(expectedResult, actualResult);
    EXPECT_EQ(expectedWrapped, actualWrapped);

    actualWrapped = WrapAddPtr(&addend1, addend2, min, max);
    EXPECT_EQ(expectedResult, addend1);
    EXPECT_EQ(expectedWrapped, actualWrapped);
}

TEST("WrapSubU32")
{
    u32 minuend, subtrahend, min, max;
    u32 expectedResult, actualResult;
    bool32 expectedWrapped, actualWrapped;

    // No wrap.
    PARAMETRIZE { minuend = 1; subtrahend = 0; min = 1; max = 9; expectedResult = 1; expectedWrapped = FALSE; }
    PARAMETRIZE { minuend = 2; subtrahend = 1; min = 1; max = 9; expectedResult = 1; expectedWrapped = FALSE; }

    // Wrap by 1.
    PARAMETRIZE { minuend = 1; subtrahend = 1; min = 1; max = 9; expectedResult = 9; expectedWrapped = TRUE; }
    PARAMETRIZE { minuend = 2; subtrahend = 2; min = 1; max = 9; expectedResult = 9; expectedWrapped = TRUE; }
    PARAMETRIZE { minuend = 1; subtrahend = 10; min = 1; max = 9; expectedResult = 9; expectedWrapped = TRUE; }

    // Wrap by 2.
    PARAMETRIZE { minuend = 1; subtrahend = 2; min = 1; max = 9; expectedResult = 8; expectedWrapped = TRUE; }
    PARAMETRIZE { minuend = 1; subtrahend = 11; min = 1; max = 9; expectedResult = 8; expectedWrapped = TRUE; }

    // Near UINT32_MAX.
    PARAMETRIZE { minuend = 0; subtrahend = 0; min = 0; max = UINT32_MAX; expectedResult = 0; expectedWrapped = FALSE; }
    PARAMETRIZE { minuend = 0; subtrahend = 1; min = 0; max = UINT32_MAX; expectedResult = UINT32_MAX; expectedWrapped = TRUE; }
    PARAMETRIZE { minuend = UINT32_MAX - 1; subtrahend = UINT32_MAX; min = 0; max = UINT32_MAX; expectedResult = UINT32_MAX; expectedWrapped = TRUE; }

    actualResult = WrapSub(minuend, subtrahend, min, max, &actualWrapped);
    EXPECT_EQ(expectedResult, actualResult);
    EXPECT_EQ(expectedWrapped, actualWrapped);

    actualWrapped = WrapSubPtr(&minuend, subtrahend, min, max);
    EXPECT_EQ(expectedResult, minuend);
    EXPECT_EQ(expectedWrapped, actualWrapped);
}
