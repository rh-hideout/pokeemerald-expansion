#ifndef GUARD_HABITAT_TEST_PROBE_H
#define GUARD_HABITAT_TEST_PROBE_H

#include "global.h"
#include "habitat/test_probe_schema.h"

#ifndef HABITAT_TEST_PROBE
#define HABITAT_TEST_PROBE 0
#endif

// Exported only by TESTING or explicit development verification builds. The
// host runner obtains its address from the link map and reads fields through
// test_probe_schema.h; it never observes incidental engine layouts.
#if TESTING || HABITAT_TEST_PROBE
struct HabitatTestProbe
{
    u16 version;
    u16 spotId;
    u8 spotState;
    u8 availableVerbs;
    u16 resolvedSpecies;
    u16 residentSpotId;
    u8 residentAssignment;
    u8 boutOutcome;
    u8 mapGroup;
    u8 mapNum;
};

extern struct HabitatTestProbe gHabitatTestProbe;
extern u16 gHabitatTestCommand;
void Habitat_TestProbeRefresh(void);
void Habitat_TestProbeOnBattleMainFrame(void);
#endif

#endif // GUARD_HABITAT_TEST_PROBE_H
