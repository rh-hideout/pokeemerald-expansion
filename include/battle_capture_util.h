#ifndef GUARD_CAPTURE_UTIL_H
#define GUARD_CAPTURE_UTIL_H

struct BallData
{
    u16 multiplier;
    u16 divider;
    bool8 guaranteedCapture;
    s8 flatBonus;
};

u32 ComputeCaptureOdds(u32 wildMonBattler, u32 playerBattler);
bool32 CriticalCapture(u32 odds);
u32 ComputeBallShakeOdds(u32 odds);

#define CAPTURE_GUARANTEED -1

#endif // GUARD_CAPTURE_UTIL_H
