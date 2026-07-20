#ifndef GUARD_HABITAT_AUTHORING_H
#define GUARD_HABITAT_AUTHORING_H

#include "global.h"
#include "habitat/conditions.h"

struct HabitatSpot;
struct HabitatMapSpan;

enum HabitatConditionUsage
{
    HABITAT_CONDITION_SPOT_APPEAR,
    HABITAT_CONDITION_SPOT_BEFRIEND,
    HABITAT_CONDITION_DEOXYS_FINALE,
};

bool32 Habitat_ConditionTypeIsSupported(u8 type);
bool32 Habitat_ValidateConditionList(const struct HabitatCondition *list,
                                     enum HabitatConditionUsage usage);
bool32 Habitat_ValidateSpotTable(const struct HabitatSpot *spots);
bool32 Habitat_ValidateMapSpans(const struct HabitatSpot *spots,
                                const struct HabitatMapSpan *spans);
bool32 Habitat_ValidateAuthoredData(void);

#endif // GUARD_HABITAT_AUTHORING_H
