#include "global.h"
#include "generational_changes.h"
#include "malloc.h"
#include "constants/generational_changes.h"

#if TESTING
EWRAM_DATA u8 *gGenerationalChangesTestOverride = NULL;

void TestInitConfigData(void)
{
    gGenerationalChangesTestOverride = Alloc(sizeof(sGenerationalChanges));
    memcpy(gGenerationalChangesTestOverride, sGenerationalChanges, sizeof(sGenerationalChanges));
}

void TestFreeConfigData(void)
{
    TRY_FREE_AND_SET_NULL(gGenerationalChangesTestOverride)
}

EWRAM_DATA struct MoveDataOverride *gMoveDataTestOverrride = NULL;

void TestInitMoveDataOverride(void)
{
    gMoveDataTestOverrride = AllocZeroed(sizeof(struct MoveDataOverride));
}

void TestAddMoveDataOverride(u32 move, enum MoveDataType type, u8 value)
{
    struct MoveDataOverride *temp = NULL;
    u32 i = 0;
    for (; gMoveDataTestOverrride[i].moveId != 0; i++); // Count how big the array is.

    temp = AllocZeroed(sizeof(struct MoveDataOverride) * (i + 2));
    memcpy(temp, gMoveDataTestOverrride, sizeof(struct MoveDataOverride) * (i + 1));

    temp[i].moveId = move;
    temp[i].type = type;
    temp[i].data = value;

    TRY_FREE_AND_SET_NULL(gMoveDataTestOverrride);
    gMoveDataTestOverrride = temp;
}

void TestFreeMoveDataOverride(void)
{
    TRY_FREE_AND_SET_NULL(gMoveDataTestOverrride);
}
#endif
