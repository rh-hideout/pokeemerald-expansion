#include "global.h"
#include "mf_nuzlocke.h"
#include "mf_rules.h"
#include "constants/battle.h"
#include "constants/region_map_sections.h"
#include "test/test.h"

TEST("MF: nuzlocke encounter flag get/set/clear per mapsec")
{
    u8 flags[MF_NUZLOCKE_ENCOUNTER_FLAG_BYTES];
    u16 i;

    for (i = 0; i < MF_NUZLOCKE_ENCOUNTER_FLAG_BYTES; i++)
        flags[i] = 0;

    EXPECT(!MfNuzlockeFlagGetFrom(flags, MAPSEC_ROUTE_1));
    EXPECT(!MfNuzlockeFlagGetFrom(flags, MAPSEC_VIRIDIAN_CITY));
    EXPECT_EQ(MfNuzlockeCountUsedFrom(flags), 0);

    MfNuzlockeFlagSetIn(flags, MAPSEC_ROUTE_1);
    EXPECT(MfNuzlockeFlagGetFrom(flags, MAPSEC_ROUTE_1));
    EXPECT(!MfNuzlockeFlagGetFrom(flags, MAPSEC_ROUTE_2));
    EXPECT_EQ(MfNuzlockeCountUsedFrom(flags), 1);

    MfNuzlockeFlagSetIn(flags, MAPSEC_VIRIDIAN_FOREST);
    EXPECT(MfNuzlockeFlagGetFrom(flags, MAPSEC_VIRIDIAN_FOREST));
    EXPECT_EQ(MfNuzlockeCountUsedFrom(flags), 2);

    // Idempotent set.
    MfNuzlockeFlagSetIn(flags, MAPSEC_ROUTE_1);
    EXPECT_EQ(MfNuzlockeCountUsedFrom(flags), 2);

    MfNuzlockeFlagClearIn(flags, MAPSEC_ROUTE_1);
    EXPECT(!MfNuzlockeFlagGetFrom(flags, MAPSEC_ROUTE_1));
    EXPECT(MfNuzlockeFlagGetFrom(flags, MAPSEC_VIRIDIAN_FOREST));
    EXPECT_EQ(MfNuzlockeCountUsedFrom(flags), 1);

    // Out-of-range / NULL are no-ops.
    EXPECT(!MfNuzlockeFlagGetFrom(flags, MAPSEC_COUNT));
    EXPECT(!MfNuzlockeFlagGetFrom(NULL, MAPSEC_ROUTE_1));
    MfNuzlockeFlagSetIn(NULL, MAPSEC_ROUTE_1);
    MfNuzlockeFlagClearIn(flags, MAPSEC_COUNT);
    EXPECT(MfNuzlockeFlagGetFrom(flags, MAPSEC_VIRIDIAN_FOREST));
}

TEST("MF: nuzlocke flag covers first and last mapsec bits")
{
    u8 flags[MF_NUZLOCKE_ENCOUNTER_FLAG_BYTES];
    u16 i;
    u16 last = MAPSEC_COUNT - 1;

    for (i = 0; i < MF_NUZLOCKE_ENCOUNTER_FLAG_BYTES; i++)
        flags[i] = 0;

    MfNuzlockeFlagSetIn(flags, 0);
    MfNuzlockeFlagSetIn(flags, last);
    EXPECT(MfNuzlockeFlagGetFrom(flags, 0));
    EXPECT(MfNuzlockeFlagGetFrom(flags, last));
    EXPECT_EQ(MfNuzlockeCountUsedFrom(flags), 2);

    MfNuzlockeFlagClearIn(flags, 0);
    EXPECT(!MfNuzlockeFlagGetFrom(flags, 0));
    EXPECT(MfNuzlockeFlagGetFrom(flags, last));
}

TEST("MF: nuzlocke wild battles that consume an area")
{
    EXPECT(MfNuzlocke_WildBattleConsumesEncounter(0));
    EXPECT(MfNuzlocke_WildBattleConsumesEncounter(BATTLE_TYPE_DOUBLE));
    EXPECT(MfNuzlocke_WildBattleConsumesEncounter(BATTLE_TYPE_SAFARI));
    EXPECT(MfNuzlocke_WildBattleConsumesEncounter(BATTLE_TYPE_ROAMER));

    EXPECT(!MfNuzlocke_WildBattleConsumesEncounter(BATTLE_TYPE_TRAINER));
    EXPECT(!MfNuzlocke_WildBattleConsumesEncounter(BATTLE_TYPE_FIRST_BATTLE));
    EXPECT(!MfNuzlocke_WildBattleConsumesEncounter(BATTLE_TYPE_LEGENDARY));
    EXPECT(!MfNuzlocke_WildBattleConsumesEncounter(BATTLE_TYPE_GHOST));
    EXPECT(!MfNuzlocke_WildBattleConsumesEncounter(BATTLE_TYPE_LINK));
    EXPECT(!MfNuzlocke_WildBattleConsumesEncounter(BATTLE_TYPE_CATCH_TUTORIAL));
    EXPECT(!MfNuzlocke_WildBattleConsumesEncounter(BATTLE_TYPE_FRONTIER));
}

TEST("MF: nuzlocke first-encounter icon off when lock inactive")
{
    // Default phase-1 / empty-rules path: nuzlocke off → no red "1".
    EXPECT(!MfNuzlocke_ShouldShowFirstEncounterIcon());
}
