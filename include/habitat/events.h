#ifndef GUARD_HABITAT_EVENTS_H
#define GUARD_HABITAT_EVENTS_H

#include "habitat/conditions.h"

// A condition dependency is deliberately narrower than a generic "state
// changed" event.  Shared engine mutation boundaries publish one of these
// only after a real write.  The habitat dispatcher then visits just the
// current-map spots whose authored dependency mask contains that bit.
enum HabitatDependency
{
    HABITAT_DEP_MAP,
    HABITAT_DEP_TIME,
    HABITAT_DEP_WEATHER,
    HABITAT_DEP_INVENTORY,
    HABITAT_DEP_PARTY,
    HABITAT_DEP_STORY_FLAG,
    HABITAT_DEP_LIFETIME_STAT,
    HABITAT_DEP_RESIDENT,
    HABITAT_DEP_GROVE,
    HABITAT_DEP_PLACEMENT,
    HABITAT_DEP_TALK,
    HABITAT_DEP_COUNT,
};

#define HABITAT_DEP_MASK(dependency) (1u << (dependency))
#define HABITAT_DEP_MASK_ALL ((1u << HABITAT_DEP_COUNT) - 1)

void Habitat_NotifyDependency(enum HabitatDependency dependency);
void Habitat_CheckTimeTick(s32 hours);  // fires TIME on hour flips

// Kept public for authored-data validation.  A spot's mask must be exactly
// the union of the dependencies implied by its two condition lists.
u32 Habitat_GetConditionDependencyMask(const struct HabitatCondition *list);

#endif // GUARD_HABITAT_EVENTS_H
