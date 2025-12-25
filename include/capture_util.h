#ifndef GUARD_CAPTURE_UTIL_H
#define GUARD_CAPTURE_UTIL_H

struct BallData
{
    u16     multiplier;
    u16     divider;
    bool8   guaranteedCapture;
    u8      flatBonus;
};

void ComputeBallData(struct BattlePokemon *mon, u32 ballId, struct BallData *ball);
u32 ComputeBadgeCapturePenalty(u32 enemyLevel, u32 playerLevel);
u32 ComputeCaptureOdds(struct BattlePokemon *mon, struct BallData *ball, u32 level);
bool32 CriticalCapture(u32 odds);

#endif // GUARD_CAPTURE_UTIL_H