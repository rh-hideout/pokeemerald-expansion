#include "global.h"
#include "mf_rules.h"
#include "mf_shiny.h"
#include "pokemon.h"
#include "test/test.h"
#include "constants/pokemon.h"

static void SetShinyChance(u8 tier)
{
    struct ModernRules *save = MfRules_GetSaveRules();

    MfRules_ApplyDevDefaults(save);
    MfRules_ApplyGamemodePreset(save, MF_GAMEMODE_CUSTOM);
    save->shinyChance = tier & 0xF;
    save->rulesLocked = TRUE;
}

static void RestorePhase1Defaults(void)
{
    struct ModernRules *save = MfRules_GetSaveRules();

    save->version = 0;
}

TEST("MF: shiny threshold doubles per SHINY CHANCE tier")
{
    EXPECT_EQ(MfShinyOddsThresholdForChance(MF_SHINY_CHANCE_8192), (u32)SHINY_ODDS);
    EXPECT_EQ(MfShinyOddsThresholdForChance(MF_SHINY_CHANCE_4096), (u32)SHINY_ODDS << 1);
    EXPECT_EQ(MfShinyOddsThresholdForChance(MF_SHINY_CHANCE_2048), (u32)SHINY_ODDS << 2);
    EXPECT_EQ(MfShinyOddsThresholdForChance(MF_SHINY_CHANCE_1024), (u32)SHINY_ODDS << 3);
    EXPECT_EQ(MfShinyOddsThresholdForChance(MF_SHINY_CHANCE_512), (u32)SHINY_ODDS << 4);
    // Out-of-range clamps to vanilla.
    EXPECT_EQ(MfShinyOddsThresholdForChance(15), (u32)SHINY_ODDS);
}

TEST("MF: shiny value check respects active SHINY CHANCE")
{
    SetShinyChance(MF_SHINY_CHANCE_8192);
    EXPECT_EQ(MfGetShinyOddsThreshold(), (u32)SHINY_ODDS);
    EXPECT(MfIsShinyValue(0));
    EXPECT(MfIsShinyValue(7));
    EXPECT(!MfIsShinyValue(8));

    SetShinyChance(MF_SHINY_CHANCE_512);
    EXPECT_EQ(MfGetShinyOddsThreshold(), 128u);
    EXPECT(MfIsShinyValue(127));
    EXPECT(!MfIsShinyValue(128));

    RestorePhase1Defaults();
}

TEST("MF: shiny higher tiers pass more of a uniform shinyValue sample")
{
    u32 i;
    u32 hitsVanilla = 0;
    u32 hitsBoosted = 0;
    // Spot-check: every 16th value in 0..65535 (4096 samples).
    const u32 samples = 4096;

    SetShinyChance(MF_SHINY_CHANCE_8192);
    for (i = 0; i < samples; i++)
    {
        if (MfIsShinyValue(i * 16))
            hitsVanilla++;
    }

    SetShinyChance(MF_SHINY_CHANCE_512);
    for (i = 0; i < samples; i++)
    {
        if (MfIsShinyValue(i * 16))
            hitsBoosted++;
    }

    // Vanilla 8/65536 ≈ 0.5 hits in this stride; 1/512 ≈ 8 hits. Require clear gap.
    EXPECT(hitsBoosted > hitsVanilla);
    EXPECT(hitsBoosted >= 4);
    EXPECT(hitsVanilla <= 2);

    RestorePhase1Defaults();
}

TEST("MF: shiny OtIdPersonality matches GET_SHINY_VALUE threshold")
{
    u32 otId = 0x12345678;
    u32 personality;
    u32 shinyValue;

    SetShinyChance(MF_SHINY_CHANCE_2048);

    for (personality = 0; personality < 64; personality++)
    {
        shinyValue = GET_SHINY_VALUE(otId, personality);
        EXPECT_EQ(MfIsShinyOtIdPersonality(otId, personality), shinyValue < 32u);
    }

    RestorePhase1Defaults();
}
