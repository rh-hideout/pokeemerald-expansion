#include "global.h"
#include "generational_changes.h"
#include "malloc.h"
#include "constants/generational_changes.h"

#if TESTING
EWRAM_DATA u8 *gGenerationalChangesTestOverride = NULL;
EWRAM_DATA struct MoveInfoOverride *gMovesInfoTestOverride = NULL;
EWRAM_DATA u8 gMoveInfoOverrideCount = 0;

void TestInitConfigData(void)
{
    gGenerationalChangesTestOverride = Alloc(sizeof(sGenerationalChanges));
    memcpy(gGenerationalChangesTestOverride, sGenerationalChanges, sizeof(sGenerationalChanges));
}

void TestFreeConfigData(void)
{
    TRY_FREE_AND_SET_NULL(gGenerationalChangesTestOverride)
}

void TestFreeMoveInfoOverrideData(void)
{
    gMoveInfoOverrideCount = 0;
    TRY_FREE_AND_SET_NULL(gMovesInfoTestOverride)
}

void TestAddMoveInfoOverrideData(u32 moveID, enum MoveDataID moveDataID, s32 data)
{
    if (gMoveInfoOverrideCount < 255)
    {
        gMoveInfoOverrideCount++;

        u32 size = gMoveInfoOverrideCount * sizeof(*gMovesInfoTestOverride);
        struct MoveInfoOverride *temp = Alloc(size);
        memcpy(temp, gMovesInfoTestOverride, size);
        TRY_FREE_AND_SET_NULL(gMovesInfoTestOverride)
        gMovesInfoTestOverride = Alloc(size);
        memcpy(gMovesInfoTestOverride, temp, size);
        Free(temp);

        gMovesInfoTestOverride[gMoveInfoOverrideCount - 1].moveID = moveID;
        gMovesInfoTestOverride[gMoveInfoOverrideCount - 1].moveDataID = moveDataID;
        gMovesInfoTestOverride[gMoveInfoOverrideCount - 1].data = data;
    }
}

#endif
