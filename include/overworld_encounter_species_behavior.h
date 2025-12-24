#ifndef GUARD_OVERWORLD_ENCOUNTER_SPECIES_BEHAVIOR_H
#define GUARD_OVERWORLD_ENCOUNTER_SPECIES_BEHAVIOR_H

static const struct MonSpeciesOWEData sOWESpeciesBehaviors[OWE_SPECIES_BEHAVIOR_COUNT] = {
    [OWE_IGNORE_PLAYER] = {
        .behavior = OWE_BEHAVIOR_WANDER_AROUND,
    },
    [OWE_CHASE_PLAYER_SLOW] = {
        .behavior = OWE_BEHAVIOR_CHASE,
        .idleSpeed = OWE_SPEED_SLOW,
        .activeSpeed = OWE_SPEED_SLOW,
        .viewDistance = 5,
        .viewWidth = 3
    },
    [OWE_FLEE_PLAYER_NORMAL] = {
        .behavior = OWE_BEHAVIOR_FLEE,
        .idleSpeed = OWE_SPEED_NORMAL,
        .activeSpeed = OWE_SPEED_NORMAL,
        .viewDistance = 5,
        .viewWidth = 3
    }
};

#endif // GUARD_OVERWORLD_ENCOUNTER_SPECIES_BEHAVIOR_H
