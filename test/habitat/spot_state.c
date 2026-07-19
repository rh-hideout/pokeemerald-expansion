#include "global.h"
#include "habitat/save.h"
#include "habitat/spots.h"
#include "test/test.h"

TEST("Habitat spot state: transitions ratchet forward only")
{
    EXPECT_EQ(Habitat_GetSpotState(1), HABITAT_STATE_DORMANT);

    Habitat_SetSpotState(1, HABITAT_STATE_STIRRING);
    EXPECT_EQ(Habitat_GetSpotState(1), HABITAT_STATE_STIRRING);

    Habitat_SetSpotState(1, HABITAT_STATE_DORMANT);   // lapse must not regress
    EXPECT_EQ(Habitat_GetSpotState(1), HABITAT_STATE_STIRRING);

    Habitat_SetSpotState(1, HABITAT_STATE_ACTIVE);
    Habitat_SetSpotState(1, HABITAT_STATE_STIRRING);
    EXPECT_EQ(Habitat_GetSpotState(1), HABITAT_STATE_ACTIVE);

    Habitat_SetSpotState(1, HABITAT_STATE_BEFRIENDED);
    EXPECT_EQ(Habitat_GetSpotState(1), HABITAT_STATE_BEFRIENDED);
}

TEST("Habitat spot state: local flags are independent of state bits")
{
    Habitat_SetSpotState(2, HABITAT_STATE_ACTIVE);
    Habitat_AddSpotLocalFlags(2, HABITAT_SPOT_LOCAL_BATTLE_WON);
    EXPECT_EQ(Habitat_GetSpotLocalFlags(2), HABITAT_SPOT_LOCAL_BATTLE_WON);
    EXPECT_EQ(Habitat_GetSpotState(2), HABITAT_STATE_ACTIVE);

    Habitat_SetSpotState(2, HABITAT_STATE_BEFRIENDED);
    EXPECT_EQ(Habitat_GetSpotLocalFlags(2), HABITAT_SPOT_LOCAL_BATTLE_WON);
}

TEST("Habitat spot state: counters exist only for mapped spots")
{
    // Spot 1 (Skitty) has a placed slot; spot 2 does not; nobody has talk slots yet.
    EXPECT_EQ(Habitat_GetPlacedCount(1), 0);
    Habitat_AddPlacedCount(1, 3);
    EXPECT_EQ(Habitat_GetPlacedCount(1), 3);

    Habitat_AddPlacedCount(2, 3);
    EXPECT_EQ(Habitat_GetPlacedCount(2), 0);

    Habitat_IncrementTalkCount(1);
    EXPECT_EQ(Habitat_GetTalkCount(1), 0);
}

TEST("Habitat spot state: out-of-range spot ids are inert")
{
    Habitat_SetSpotState(HABITAT_SPOT_COUNT, HABITAT_STATE_ACTIVE);
    EXPECT_EQ(Habitat_GetSpotState(HABITAT_SPOT_COUNT), HABITAT_STATE_DORMANT);
    EXPECT_EQ(Habitat_GetSpotLocalFlags(0xFFFE), 0);
}
