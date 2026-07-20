#ifndef GUARD_HABITAT_FINALE_H
#define GUARD_HABITAT_FINALE_H

#include "global.h"
#include "habitat/conditions.h"

// Task 2 evaluates this gate from its dedicated finale completion flag.
struct HabitatFinaleGate
{
    u16 species;
    const struct HabitatCondition *conditions;
    u16 winFlag;
};

extern const struct HabitatFinaleGate gHabitatDeoxysFinale;

#endif // GUARD_HABITAT_FINALE_H
