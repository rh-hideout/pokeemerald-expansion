#ifndef GUARD_HABITAT_BOUTS_H
#define GUARD_HABITAT_BOUTS_H

#include "global.h"

enum HabitatBoutOutcome {
    HABITAT_BOUT_NONE,
    HABITAT_BOUT_WIN,
    HABITAT_BOUT_LOSS,
    HABITAT_BOUT_FLED,
    HABITAT_BOUT_ABORTED,
};

struct HabitatBoutDefinition {
    u16 boutId;
    u16 playerSpecies;
    u8 playerLevel;
    u16 opponentSpecies;
    u8 opponentLevel;
    u16 winFlag;
};

bool32 Habitat_BoutBegin(const struct HabitatBoutDefinition *definition);
void Habitat_BoutFinish(enum HabitatBoutOutcome outcome);
void Habitat_BoutFinishFromBattleOutcome(u8 battleOutcome);
bool32 Habitat_BoutIsActive(void);
enum HabitatBoutOutcome Habitat_GetLastBoutOutcome(void);
bool32 Habitat_BoutIsApprovedFinaleDefinition(const struct HabitatBoutDefinition *definition);
enum HabitatBoutOutcome Habitat_BoutOutcomeFromBattleOutcome(u8 battleOutcome);
bool32 Habitat_BoutReturnsToField(enum HabitatBoutOutcome outcome);

#endif // GUARD_HABITAT_BOUTS_H
