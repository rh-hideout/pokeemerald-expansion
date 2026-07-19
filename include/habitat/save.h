#ifndef GUARD_HABITAT_SAVE_H
#define GUARD_HABITAT_SAVE_H

#include "config/habitat.h"

// Persistent habitat state. Lives in SaveBlock3 (see global.h); the save
// engine chunks it across sector spare bytes automatically and
// save.c static-asserts the total fits. Layout per spec §5:
// spotStates[i] packs 2b state | 2b hint stage | 4b spot-local flags,
// so all-zero == every spot DORMANT with nothing revealed.
struct HabitatSave
{
    u8 spotStates[HABITAT_SPOT_COUNT];
    u8 talkCounters[HABITAT_TALK_COUNTER_COUNT];
};

#endif // GUARD_HABITAT_SAVE_H
