#include "global.h"
#include "generational_changes.h"
#include "malloc.h"
#include "constants/generational_changes.h"

#if TESTING
EWRAM_DATA u8 *gConfigChangesTestOverride = NULL;

void TestInitConfigData(void)
{
    gConfigChangesTestOverride = Alloc(sizeof(sConfigChanges));
    memcpy(gConfigChangesTestOverride, sConfigChanges, sizeof(sConfigChanges));
}

void TestFreeConfigData(void)
{
    TRY_FREE_AND_SET_NULL(gConfigChangesTestOverride)
}
#endif
