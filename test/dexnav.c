#include "global.h"
#include "event_data.h"
#include "mass_outbreak.h"
#include "script.h"
#include "wild_encounter_ow.h"
#include "constants/event_objects.h"
#include "constants/trainer_types.h"
#include "test/test.h"

#if DEXNAV_ENABLED
TEST("DexNav suppresses outbreak encounters without resetting outbreak progress")
{
    FlagClear(DN_FLAG_SEARCHING);
    StartStaticMassOutbreak(OUTBREAK_ID_ROUTE102);
    gSaveBlock1Ptr->location.mapGroup = gSaveBlock1Ptr->outbreakLocationMapGroup;
    gSaveBlock1Ptr->location.mapNum = gSaveBlock1Ptr->outbreakLocationMapNum;
    gSaveBlock1Ptr->outbreakPokemonProbability = 100;
    gSaveBlock1Ptr->outbreakClearedCount = 60;
    EXPECT_EQ(DoMassOutbreakEncounterTest(), TRUE);

    FlagSet(DN_FLAG_SEARCHING);
    EXPECT_EQ(DoMassOutbreakEncounterTest(), FALSE);
    EXPECT_EQ(SetUpMassOutbreakEncounter(0), FALSE);
    EXPECT_EQ(GetMassOutbreakClearedCount(), 60);

    FlagClear(DN_FLAG_SEARCHING);
    EXPECT_EQ(DoMassOutbreakEncounterTest(), TRUE);
    EXPECT_EQ(GetMassOutbreakClearedCount(), 60);
}

TEST("DexNav blocks collision and interaction with outbreak overworld encounters")
{
    FlagClear(DN_FLAG_SEARCHING);
    StartStaticMassOutbreak(OUTBREAK_ID_ROUTE102);
    struct ObjectEvent savedObject = gObjectEvents[0];
    struct ObjectEvent player = {.isPlayer = TRUE};
    gObjectEvents[0] = (struct ObjectEvent){
        .active = TRUE,
        .trainerType = TRAINER_TYPE_OW_WILD_ENCOUNTER,
        .localId = LOCALID_OW_ENCOUNTER_END,
        // OWE stores its category here, with mass outbreaks immediately after the roamer categories.
        .warpArrowSpriteId = ROAMER_COUNT,
    };

    ScriptContext_Init();
    FlagSet(DN_FLAG_SEARCHING);
    EXPECT(GetOverworlWildEncounterScript(0) == NULL);
    TryTriggerOverworldWildEncounter(&gObjectEvents[0], &player);
    EXPECT_EQ(ScriptContext_IsEnabled(), FALSE);
    TryTriggerOverworldWildEncounter(&player, &gObjectEvents[0]);
    EXPECT_EQ(ScriptContext_IsEnabled(), FALSE);

    FlagClear(DN_FLAG_SEARCHING);
    EXPECT(GetOverworlWildEncounterScript(0) != NULL);
    gObjectEvents[0] = savedObject;
}
#endif
