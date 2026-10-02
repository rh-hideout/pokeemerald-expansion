#include "global.h"
#include "caps.h"
#include "event_data.h"
#include "mf_level_cap.h"
#include "mf_rules.h"
#include "test/test.h"

// First-clear Kanto parties. See src/mf_level_cap.c / ADR 0042.
static const u8 sExpectedNormal[MF_LEVEL_CAP_BADGE_STAGES] =
{
    14, 21, 24, 29, 43, 43, 47, 50, 63,
};

static const u8 sExpectedHard[MF_LEVEL_CAP_BADGE_STAGES] =
{
    12, 18, 18, 24, 37, 37, 40, 42, 57,
};

static void ClearBadgeAndClearFlags(void)
{
    u32 i;

    for (i = 0; i < NUM_BADGES; i++)
        FlagClear(FLAG_BADGE01_GET + i);
    FlagClear(FLAG_SYS_GAME_CLEAR);
}

static struct ModernRules *PrepareRules(void)
{
    struct ModernRules *save = MfRules_GetSaveRules();

    MfRules_ApplyDevDefaults(save);
    save->rulesLocked = TRUE;
    return save;
}

TEST("MF: level cap lookup per badge count")
{
    u32 badges;

    for (badges = 0; badges < MF_LEVEL_CAP_BADGE_STAGES; badges++)
    {
        EXPECT_EQ(MfResolvePartyLevelCap(MF_LEVEL_CAP_NORMAL, badges, FALSE), sExpectedNormal[badges]);
        EXPECT_EQ(MfResolvePartyLevelCap(MF_LEVEL_CAP_HARD, badges, FALSE), sExpectedHard[badges]);
        EXPECT_EQ(MfResolvePartyLevelCap(MF_LEVEL_CAP_OFF, badges, FALSE), MAX_LEVEL);
    }

    // Hall of Fame lifts Normal and Hard. Extra badges stay on the 8-badge row.
    EXPECT_EQ(MfResolvePartyLevelCap(MF_LEVEL_CAP_NORMAL, 0, TRUE), MAX_LEVEL);
    EXPECT_EQ(MfResolvePartyLevelCap(MF_LEVEL_CAP_HARD, 8, TRUE), MAX_LEVEL);
    EXPECT_EQ(MfResolvePartyLevelCap(MF_LEVEL_CAP_NORMAL, 9, FALSE), sExpectedNormal[8]);
    EXPECT_EQ(MfResolvePartyLevelCap(MF_LEVEL_CAP_HARD, 255, FALSE), sExpectedHard[8]);
    // 2-bit field can hold 3; only menu values 1 and 2 bind.
    EXPECT_EQ(MfResolvePartyLevelCap(3, 0, FALSE), MAX_LEVEL);
}

TEST("MF: level cap gate follows badges and stops exp at the cap")
{
    struct ModernRules *save = PrepareRules();
    u32 badges;

    ClearBadgeAndClearFlags();

    save->levelCap = MF_LEVEL_CAP_OFF;
    EXPECT_EQ(GetCurrentLevelCap(), (u32)MAX_LEVEL);
    EXPECT_EQ(GetSoftLevelCapExpValue(14, 40), 40u);
    EXPECT(!MfShouldClampExpItemsToLevelCap());
    EXPECT(!MfIsRareCandyBlockedByLevelCap(14));

    save->levelCap = MF_LEVEL_CAP_NORMAL;
    EXPECT(MfShouldClampExpItemsToLevelCap());
    EXPECT(MfIsRareCandyBlockedByLevelCap(14));
    EXPECT(!MfIsRareCandyBlockedByLevelCap(13));

    for (badges = 0; badges < NUM_BADGES; badges++)
    {
        EXPECT_EQ(GetCurrentLevelCap(), (u32)sExpectedNormal[badges]);
        EXPECT_EQ(GetSoftLevelCapExpValue(sExpectedNormal[badges], 25), 0u);
        EXPECT_EQ(GetSoftLevelCapExpValue(sExpectedNormal[badges] - 1, 25), 25u);
        FlagSet(FLAG_BADGE01_GET + badges);
    }

    // Eight badges: champion row, still binding.
    EXPECT_EQ(GetCurrentLevelCap(), (u32)sExpectedNormal[8]);
    EXPECT_EQ(GetSoftLevelCapExpValue(63, 25), 0u);
    EXPECT_EQ(GetSoftLevelCapExpValue(62, 25), 25u);

    FlagSet(FLAG_SYS_GAME_CLEAR);
    EXPECT_EQ(GetCurrentLevelCap(), (u32)MAX_LEVEL);
    EXPECT_EQ(GetSoftLevelCapExpValue(63, 25), 25u);
    EXPECT(!MfIsRareCandyBlockedByLevelCap(63));

    FlagClear(FLAG_SYS_GAME_CLEAR);
    save->levelCap = MF_LEVEL_CAP_HARD;
    EXPECT_EQ(GetCurrentLevelCap(), (u32)sExpectedHard[8]);
    EXPECT_EQ(GetSoftLevelCapExpValue(57, 10), 0u);
    EXPECT_EQ(GetSoftLevelCapExpValue(56, 10), 10u);
    EXPECT(MfIsRareCandyBlockedByLevelCap(57));
    EXPECT(!MfIsRareCandyBlockedByLevelCap(56));

    // Value 3 fits the 2-bit field but is not a menu choice.
    save->levelCap = 3;
    EXPECT(!MfIsPartyLevelCapEnabled());
    EXPECT_EQ(GetCurrentLevelCap(), (u32)MAX_LEVEL);
    EXPECT_EQ(GetSoftLevelCapExpValue(14, 40), 40u);

    save->version = 0;
}
