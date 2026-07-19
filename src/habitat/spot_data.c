#include "global.h"
#include "habitat/spots.h"
#include "constants/berry.h"
#include "constants/flags.h"
#include "constants/items.h"
#include "constants/map_groups.h"
#include "constants/moves.h"
#include "constants/species.h"
#include "constants/weather.h"

// ============================================================================
// Vertical-slice spot data (spec §7). ALL prose here is engine placeholder —
// hint/story text is authored by Jay and replaces these strings wholesale.
// Placeholder currencies too: Vulpix's Spicy Berry does not exist until the
// Grove pairing system (phase 4) mints flavor berries, so it costs a plain
// Oran for now — swap when ITEM_SPICY_* lands. LOUD placeholders, on purpose.
// ============================================================================

// Object-visibility flags: claimed from the vanilla unused range. 0x020/0x021
// are habitat test scratch (test/habitat/conditions.c); spots start at 0x030.
#define FLAG_HABITAT_SPOT_SKITTY    FLAG_UNUSED_0x030
#define FLAG_HABITAT_SPOT_LOTAD     FLAG_UNUSED_0x031
#define FLAG_HABITAT_SPOT_MACHOP    FLAG_UNUSED_0x032
#define FLAG_HABITAT_SPOT_VULPIX    FLAG_UNUSED_0x033
#define FLAG_HABITAT_SPOT_HERACROSS FLAG_UNUSED_0x034

// Slice spot object events live on Route 103 (the slice zone) — see
// data/maps/Route103/map.json local ids 100–104 (added in phase 2b).
#define SLICE_MAP_GROUP  MAP_GROUP(MAP_ROUTE103)
#define SLICE_MAP_NUM    MAP_NUM(MAP_ROUTE103)

enum
{
    SPOT_SKITTY = 1,
    SPOT_LOTAD,
    SPOT_MACHOP,
    SPOT_VULPIX,
    SPOT_HERACROSS,
};

// --- Skitty: Tier 1, teaches the PLACE verb -------------------------------
static const struct HabitatCondition sSkittyAppear[] = {
    HABITAT_COND(COND_ITEM_PLACED, ITEM_POKE_DOLL, 1, 0, 0),
    HABITAT_CONDITIONS_END,
};
static const struct HabitatCondition sSkittyBefriend[] = {  // PLACEHOLDER befriend cost
    HABITAT_COND(COND_ITEM_OFFERED, ITEM_ORAN_BERRY, 1, 0, 0),
    HABITAT_CONDITIONS_END,
};

// --- Lotad: Tier 2, compound appear conditions ----------------------------
static const struct HabitatCondition sLotadAppear[] = {
    HABITAT_COND(COND_PARTY_SPECIES, SPECIES_BULBASAUR, 1, 0, 0),
    HABITAT_COND(COND_WEATHER, WEATHER_RAIN, 0, 0, 0),
    HABITAT_COND(COND_BERRY_MATURE, ITEM_CHERI_BERRY, 1, 0, 0),  // zone 1 tree
    HABITAT_CONDITIONS_END,
};
static const struct HabitatCondition sLotadBefriend[] = {
    HABITAT_COND(COND_ITEM_OFFERED, ITEM_ORAN_BERRY, 1, 0, 0),
    HABITAT_CONDITIONS_END,
};

// --- Machop: Tier 2, battle-as-condition (bout trigger lands phase 5) -----
static const struct HabitatCondition sMachopAppear[] = {
    HABITAT_CONDITIONS_END,  // empty = always eligible; Machop is just there
};
static const struct HabitatCondition sMachopBefriend[] = {
    HABITAT_COND(COND_BATTLE_WIN, 0, 0, 0, 0),
    HABITAT_CONDITIONS_END,
};

// --- Vulpix: Tier 2, proves the Grove product loop ------------------------
static const struct HabitatCondition sVulpixAppear[] = {
    HABITAT_CONDITIONS_END,  // PLACEHOLDER: Jay authors real appear conditions
};
static const struct HabitatCondition sVulpixBefriend[] = {
    // PLACEHOLDER CURRENCY: wants a SPICY berry (Grass+Fire co-op product).
    // Swap ITEM_ORAN_BERRY -> the Spicy flavor berry when phase 4 mints it.
    HABITAT_COND(COND_ITEM_OFFERED, ITEM_ORAN_BERRY, 1, 0, 0),
    HABITAT_CONDITIONS_END,
};

// --- Heracross: Tier 3, proves chaining (resident + time + trees) ---------
static const struct HabitatCondition sHeracrossAppear[] = {
    HABITAT_COND(COND_RESIDENT_SPECIES, SPECIES_PINSIR, 0, 0, 0),  // unmet until phase 3
    HABITAT_COND(COND_TIME_OF_DAY, 20, 4, 0, 0),                   // night
    HABITAT_COND(COND_BERRY_MATURE, ITEM_LEPPA_BERRY, 1, 0, 0),    // "sap trees" placeholder
    HABITAT_CONDITIONS_END,
};
static const struct HabitatCondition sHeracrossBefriend[] = {  // PLACEHOLDER befriend cost
    HABITAT_COND(COND_ITEM_OFFERED, ITEM_SITRUS_BERRY, 1, 0, 0),
    HABITAT_CONDITIONS_END,
};

#define PLACEHOLDER_HINTS(name)                                                  \
    static const u8 sHintDormant_##name[]  =                                     \
        _("PLACEHOLDER {STR_VAR_1}: the air here\nremembers something. (dormant)");       \
    static const u8 sHintStirring_##name[] =                                     \
        _("PLACEHOLDER {STR_VAR_1}: it is close\nnow. Something is missing. (stirring)"); \
    static const u8 sHintActive_##name[]   =                                     \
        _("PLACEHOLDER {STR_VAR_1}: it watches\nyou. It wants something. (active)")

PLACEHOLDER_HINTS(Skitty);
PLACEHOLDER_HINTS(Lotad);
PLACEHOLDER_HINTS(Machop);
PLACEHOLDER_HINTS(Vulpix);
PLACEHOLDER_HINTS(Heracross);

#define SPOT_HINTS(name) sHintDormant_##name, sHintStirring_##name, sHintActive_##name

const struct HabitatSpot gHabitatSpots[] = {
    {
        .spotId = SPOT_SKITTY, .species = SPECIES_SKITTY, .tier = 1, .zoneId = 1,
        .appearConditions = sSkittyAppear, .befriendConditions = sSkittyBefriend,
        .hintDormant = sHintDormant_Skitty, .hintStirring = sHintStirring_Skitty, .hintActive = sHintActive_Skitty,
        .workerRole = ROLE_NONE, .personalityId = NULL,
        .hideFlag = FLAG_HABITAT_SPOT_SKITTY,
        .mapGroup = SLICE_MAP_GROUP, .mapNum = SLICE_MAP_NUM, .localId = 100,
        .engineFlags = HABITAT_SPOTDEF_STAY_AMBIENT,
    },
    {
        .spotId = SPOT_LOTAD, .species = SPECIES_LOTAD, .tier = 2, .zoneId = 1,
        .appearConditions = sLotadAppear, .befriendConditions = sLotadBefriend,
        .hintDormant = sHintDormant_Lotad, .hintStirring = sHintStirring_Lotad, .hintActive = sHintActive_Lotad,
        .workerRole = ROLE_IRRIGATE, .personalityId = NULL,
        .hideFlag = FLAG_HABITAT_SPOT_LOTAD,
        .mapGroup = SLICE_MAP_GROUP, .mapNum = SLICE_MAP_NUM, .localId = 101,
        .engineFlags = 0,
    },
    {
        .spotId = SPOT_MACHOP, .species = SPECIES_MACHOP, .tier = 2, .zoneId = 1,
        .appearConditions = sMachopAppear, .befriendConditions = sMachopBefriend,
        .hintDormant = sHintDormant_Machop, .hintStirring = sHintStirring_Machop, .hintActive = sHintActive_Machop,
        .workerRole = ROLE_DIG, .personalityId = NULL,
        .hideFlag = FLAG_HABITAT_SPOT_MACHOP,
        .mapGroup = SLICE_MAP_GROUP, .mapNum = SLICE_MAP_NUM, .localId = 102,
        .engineFlags = 0,
    },
    {
        .spotId = SPOT_VULPIX, .species = SPECIES_VULPIX, .tier = 2, .zoneId = 1,
        .appearConditions = sVulpixAppear, .befriendConditions = sVulpixBefriend,
        .hintDormant = sHintDormant_Vulpix, .hintStirring = sHintStirring_Vulpix, .hintActive = sHintActive_Vulpix,
        .workerRole = ROLE_WARM, .personalityId = NULL,
        .hideFlag = FLAG_HABITAT_SPOT_VULPIX,
        .mapGroup = SLICE_MAP_GROUP, .mapNum = SLICE_MAP_NUM, .localId = 103,
        .engineFlags = 0,
    },
    {
        .spotId = SPOT_HERACROSS, .species = SPECIES_HERACROSS, .tier = 3, .zoneId = 1,
        .appearConditions = sHeracrossAppear, .befriendConditions = sHeracrossBefriend,
        .hintDormant = sHintDormant_Heracross, .hintStirring = sHintStirring_Heracross, .hintActive = sHintActive_Heracross,
        .workerRole = ROLE_POLLINATE, .personalityId = NULL,
        .hideFlag = FLAG_HABITAT_SPOT_HERACROSS,
        .mapGroup = SLICE_MAP_GROUP, .mapNum = SLICE_MAP_NUM, .localId = 104,
        .engineFlags = 0,
    },
    { .spotId = 0xFFFF },
};

const struct HabitatZone gHabitatZones[] = {
    { .zoneId = 1, .berryTreeIdFirst = BERRY_TREE_ROUTE_103_CHERI_1, .berryTreeIdLast = BERRY_TREE_ROUTE_103_CHERI_2 },
    { .zoneId = 0 },
};

const struct HabitatSpot *Habitat_GetSpot(u16 spotId)
{
    u32 i;
    for (i = 0; gHabitatSpots[i].spotId != 0xFFFF; i++)
    {
        if (gHabitatSpots[i].spotId == spotId)
            return &gHabitatSpots[i];
    }
    return NULL;
}

const struct HabitatSpot *Habitat_GetSpotByObject(u8 mapGroup, u8 mapNum, u8 localId)
{
    u32 i;
    for (i = 0; gHabitatSpots[i].spotId != 0xFFFF; i++)
    {
        if (gHabitatSpots[i].mapGroup == mapGroup
         && gHabitatSpots[i].mapNum == mapNum
         && gHabitatSpots[i].localId == localId)
            return &gHabitatSpots[i];
    }
    return NULL;
}

const struct HabitatZone *Habitat_GetZone(u8 zoneId)
{
    u32 i;
    for (i = 0; gHabitatZones[i].zoneId != 0; i++)
    {
        if (gHabitatZones[i].zoneId == zoneId)
            return &gHabitatZones[i];
    }
    return NULL;
}
