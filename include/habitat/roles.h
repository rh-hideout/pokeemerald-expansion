#ifndef GUARD_HABITAT_ROLES_H
#define GUARD_HABITAT_ROLES_H

// Solo worker roles per spec §4. Assigned per spot (primary role) and
// consumed by the Grove worker system (M1 phase 4).
enum HabitatWorkerRole
{
    ROLE_NONE = 0,   // flavor resident; still counts for COND_RESIDENT_*
    ROLE_TEND,       // Grass: +growth speed
    ROLE_IRRIGATE,   // Water: water-hungry berries; rain-equivalent on plot
    ROLE_WARM,       // Fire: heat berries; frost protection
    ROLE_POLLINATE,  // Bug/Flying: rare mutations on adjacent plots
    ROLE_DIG,        // Ground/Rock: new soil; buried items
    ROLE_SPARK,      // Electric: faster harvest cycles; late-game fixtures
    ROLE_CHILL,      // Ice: preserved/frost berries
    ROLE_WEATHER,    // Legendary-only: zone-scale weather
    HABITAT_ROLES_COUNT,
};

#endif // GUARD_HABITAT_ROLES_H
