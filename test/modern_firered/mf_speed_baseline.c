#include "global.h"
#include "test/test.h"
#include "config/battle.h"
#include "config/text.h"
#include "config/overworld.h"
#include "config/general.h"

// S11: lock Phase 1 battle / overworld speed baseline.
// Shared Emerald TESTELF path — same configs as the FireRed ROM.
// In-game pace: docs-mf/manual-qa-s11-battle-ow-speed.md

TEST("MF: speed battle configs — fast intro, bars, half wait multiplier")
{
    EXPECT(B_FAST_INTRO_PKMN_TEXT);
    EXPECT(B_FAST_INTRO_NO_SLIDE);
    EXPECT(B_FAST_HP_DRAIN);
    EXPECT(B_FAST_EXP_GROW);
    EXPECT_EQ(B_WAIT_TIME_MULTIPLIER, 8);
}

TEST("MF: speed text configs — Options menu remains authoritative")
{
    EXPECT(!TEXT_SPEED_INSTANT);
    EXPECT_EQ(TEXT_SPEED_SLOW_MODIFIER, 1);
    EXPECT_EQ(TEXT_SPEED_MEDIUM_MODIFIER, 1);
    EXPECT_EQ(TEXT_SPEED_FAST_MODIFIER, 1);
}

TEST("MF: speed overworld — indoor run Gen4+, poison compile baseline Gen5+")
{
    // OW_POISON_DAMAGE stays GEN_LATEST; S31 SURVIVE POISON runtime-gates
    // Gen3 faint vs Gen4 survive-at-1HP (see ADR 0031).
    EXPECT(OW_RUNNING_INDOORS != GEN_3);
    EXPECT(OW_POISON_DAMAGE >= GEN_5);
}
