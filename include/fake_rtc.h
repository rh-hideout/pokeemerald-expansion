#ifndef GUARD_FAKE_RTC_UTIL_H
#define GUARD_FAKE_RTC_UTIL_H

#include "siirtc.h"
#include "config/overworld.h"

static inline bool32 UseFakeRtc(void)
{
    if (OW_USE_FAKE_RTC)
        return TRUE;
    extern struct SaveBlock3 *gSaveBlock3Ptr;
    if (gSaveBlock3Ptr != NULL)
        return gSaveBlock3Ptr->challengeSettings.tx_Features_RTCType;
    return FALSE;
}

void FakeRtc_Reset(void);
struct SiiRtcInfo* FakeRtc_GetCurrentTime(void);
void FakeRtc_GetRawInfo(struct SiiRtcInfo *rtc);
void FakeRtc_AdvanceTimeBy(u32 days, u32 hours, u32 minutes, u32 seconds);
void FakeRtc_ManuallySetTime(u32 day, u32 hour, u32 minute, u32 second);
void FakeRtc_ForwardTimeTo(u32 hour, u32 minute, u32 second);
void FakeRtc_TickTimeForward(void);
u32 FakeRtc_GetSecondsRatio(void);
void Script_PauseFakeRtc(void);
void Script_ResumeFakeRtc(void);
void Script_ToggleFakeRtc(void);

#endif // GUARD_FAKE_RTC_UTIL_H
