#include "global.h"
#include "habitat/save.h"
#include "habitat/spots.h"
#include "constants/berry.h"
#include "constants/flags.h"
#include "constants/items.h"
#include "constants/map_event_ids.h"
#include "constants/map_groups.h"
#include "constants/moves.h"
#include "constants/species.h"
#include "constants/vars.h"
#include "constants/weather.h"

#define DEP_SKITTY (HABITAT_DEP_MASK(HABITAT_DEP_PLACEMENT) | HABITAT_DEP_MASK(HABITAT_DEP_INVENTORY))
#define DEP_LOTAD (HABITAT_DEP_MASK(HABITAT_DEP_RESIDENT) | HABITAT_DEP_MASK(HABITAT_DEP_WEATHER) | HABITAT_DEP_MASK(HABITAT_DEP_TIME) | HABITAT_DEP_MASK(HABITAT_DEP_GROVE) | HABITAT_DEP_MASK(HABITAT_DEP_INVENTORY))
#define DEP_MACHOP HABITAT_DEP_MASK(HABITAT_DEP_INVENTORY)
#define DEP_VULPIX HABITAT_DEP_MASK(HABITAT_DEP_INVENTORY)
#define DEP_HERACROSS (HABITAT_DEP_MASK(HABITAT_DEP_RESIDENT) | HABITAT_DEP_MASK(HABITAT_DEP_TIME) | HABITAT_DEP_MASK(HABITAT_DEP_GROVE) | HABITAT_DEP_MASK(HABITAT_DEP_INVENTORY))
#define DEP_PINSIR (HABITAT_DEP_MASK(HABITAT_DEP_PLACEMENT) | HABITAT_DEP_MASK(HABITAT_DEP_INVENTORY))
#define DEP_FRAME HABITAT_DEP_MASK(HABITAT_DEP_PLACEMENT)

// ============================================================================
// Vertical-slice spot data (spec §7). ALL prose here is engine placeholder —
// hint/story text is authored by Jay and replaces these strings wholesale.
// Befriend wants follow spec §4's type-berry rule (Sleep mapping, verified
// 2026-07-19): a Pokémon's default want is its own type's berry. Characterful
// exceptions are Jay's to author.
// ============================================================================

// Object-visibility flags: claimed from the vanilla unused range. 0x020/0x021
// are habitat test scratch (test/habitat/conditions.c); spots start at 0x030.
#define FLAG_HABITAT_SPOT_SKITTY    FLAG_UNUSED_0x030
#define FLAG_HABITAT_SPOT_LOTAD     FLAG_UNUSED_0x031
#define FLAG_HABITAT_SPOT_MACHOP    FLAG_UNUSED_0x032
#define FLAG_HABITAT_SPOT_VULPIX    FLAG_UNUSED_0x033
#define FLAG_HABITAT_SPOT_HERACROSS FLAG_UNUSED_0x034
#define FLAG_HABITAT_SPOT_PINSIR    FLAG_UNUSED_0x035
#define FLAG_HABITAT_FRAME_TORCHIC  FLAG_UNUSED_0x040
#define FLAG_HABITAT_FRAME_TREECKO  FLAG_UNUSED_0x041
#define FLAG_HABITAT_FRAME_MUDKIP   FLAG_UNUSED_0x042

// Slice spot object events live on Route 103 (the slice zone) — see
// data/maps/Route103/map.json (LOCALID_HABITAT_SPOT_*, generated).
#define SLICE_MAP_GROUP  MAP_GROUP(MAP_ROUTE103)
#define SLICE_MAP_NUM    MAP_NUM(MAP_ROUTE103)

enum
{
    SPOT_SKITTY = 1,
    SPOT_LOTAD,
    SPOT_MACHOP,
    SPOT_VULPIX,
    SPOT_HERACROSS,
    SPOT_PINSIR,
    SPOT_FRAME_TORCHIC,   // 7 — §10 lab frames
    SPOT_FRAME_TREECKO,   // 8
    SPOT_FRAME_MUDKIP,    // 9
};

// --- Skitty: Tier 1, teaches the PLACE verb -------------------------------
static const struct HabitatCondition sSkittyAppear[] = {
    HABITAT_COND(COND_ITEM_PLACED, ITEM_POKE_DOLL, 1, 1, 0),
    HABITAT_CONDITIONS_END,
};
static const struct HabitatCondition sSkittyBefriend[] = {  // Normal type-want default (§4)
    HABITAT_COND(COND_ITEM_OFFERED, ITEM_PERSIM_BERRY, 1, 0, 0),
    HABITAT_CONDITIONS_END,
};

// --- Lotad: Tier 2, compound appear conditions (§7 recast 2026-07-19:
// resident Treecko, not party Bulbasaur — party layer deliberately deferred) -
static const struct HabitatCondition sLotadAppear[] = {
    HABITAT_COND(COND_RESIDENT_SPECIES, SPECIES_TREECKO, 0, 0, 0),
    HABITAT_COND(COND_WEATHER, WEATHER_RAIN, 0, 0, 0),
    HABITAT_COND(COND_BERRY_MATURE, ITEM_CHERI_BERRY, 1, 0, 0),  // zone 1 tree
    HABITAT_CONDITIONS_END,
};
static const struct HabitatCondition sLotadBefriend[] = {  // Water type-want default (§4)
    HABITAT_COND(COND_ITEM_OFFERED, ITEM_ORAN_BERRY, 1, 0, 0),
    HABITAT_CONDITIONS_END,
};

// --- Machop: Tier 2 ---------------------------------------------------------
static const struct HabitatCondition sMachopAppear[] = {
    HABITAT_CONDITIONS_END,  // empty = always eligible; Machop is just there
};
static const struct HabitatCondition sMachopBefriend[] = {
    // Narrative approval: willingness is the want; no bout attaches here.
    HABITAT_COND(COND_ITEM_OFFERED, ITEM_CHERI_BERRY, 1, 0, 0),
    HABITAT_CONDITIONS_END,
};

// --- Vulpix: Tier 2, proves the Grove product loop ------------------------
static const struct HabitatCondition sVulpixAppear[] = {
    HABITAT_CONDITIONS_END,  // PLACEHOLDER: Jay authors real appear conditions
};
static const struct HabitatCondition sVulpixBefriend[] = {
    // §7: offer a Leppa (Fire type-want) — proves the grow-then-spend circuit
    // once Torchic works a plot (phase 4).
    HABITAT_COND(COND_ITEM_OFFERED, ITEM_LEPPA_BERRY, 1, 0, 0),
    HABITAT_CONDITIONS_END,
};

// --- Heracross: Tier 3, proves chaining (resident + time + trees) ---------
static const struct HabitatCondition sHeracrossAppear[] = {
    HABITAT_COND(COND_RESIDENT_SPECIES, SPECIES_PINSIR, 0, 0, 0),  // unmet until phase 3
    HABITAT_COND(COND_TIME_OF_DAY, 20, 4, 0, 0),                   // night
    HABITAT_COND(COND_BERRY_MATURE, ITEM_LEPPA_BERRY, 1, 0, 0),    // "sap trees" placeholder
    HABITAT_CONDITIONS_END,
};
static const struct HabitatCondition sHeracrossBefriend[] = {  // Bug type-want default (§4)
    HABITAT_COND(COND_ITEM_OFFERED, ITEM_LUM_BERRY, 1, 0, 0),
    HABITAT_CONDITIONS_END,
};

// --- Pinsir: Tier 2, stated want (§7 recast; feeds Heracross's chain) -----
static const struct HabitatCondition sPinsirAppear[] = {
    // "a sap-slathered log" [placeholder want]: ITEM_HONEY stands in for sap
    // until Jay authors the real want.
    HABITAT_COND(COND_ITEM_PLACED, ITEM_HONEY, 1, 2, 0),
    HABITAT_CONDITIONS_END,
};
static const struct HabitatCondition sPinsirBefriend[] = {  // Bug type-want default (§4)
    HABITAT_COND(COND_ITEM_OFFERED, ITEM_LUM_BERRY, 1, 0, 0),
    HABITAT_CONDITIONS_END,
};

// ---- §10 lab frames. An element furnishing chooses its starter; the same
// choice table is attached to all three frames. The first (already furnished)
// frame needs only an element, while the two bare frames retain their
// scavenged requirements. Counter ids retain the former v2 mappings where
// they existed so old saves resolve to the same starter.
static const struct HabitatSpeciesChoice sStarterChoices[] = {
    { ITEM_HH_CAMPFIRE,    SPECIES_TORCHIC },
    { ITEM_HH_POTTED_PLANT, SPECIES_TREECKO },
    { ITEM_HH_WATER_BASIN, SPECIES_MUDKIP },
    { ITEM_NONE,           SPECIES_NONE },
};

#define STARTER_CHOICE_GROUP 1
#define STARTER_ELEMENT_FLAGS HABITAT_COND_OR_GROUP(1)

static const struct HabitatCondition sFrameTorchicAppear[] = {
    HABITAT_COND(COND_ITEM_PLACED, ITEM_HH_CAMPFIRE,    1, 3, STARTER_ELEMENT_FLAGS),
    HABITAT_COND(COND_ITEM_PLACED, ITEM_HH_POTTED_PLANT, 1, 9, STARTER_ELEMENT_FLAGS),
    HABITAT_COND(COND_ITEM_PLACED, ITEM_HH_WATER_BASIN,  1, 10, STARTER_ELEMENT_FLAGS),
    HABITAT_CONDITIONS_END,
};
static const struct HabitatCondition sFrameTreeckoAppear[] = {
    HABITAT_COND(COND_ITEM_PLACED, ITEM_HH_POTTED_PLANT, 1, 4, STARTER_ELEMENT_FLAGS),
    HABITAT_COND(COND_ITEM_PLACED, ITEM_HH_BOOKSHELF, 1, 5, 0),
    HABITAT_COND(COND_ITEM_PLACED, ITEM_HH_CAMPFIRE, 1, 11, STARTER_ELEMENT_FLAGS),
    HABITAT_COND(COND_ITEM_PLACED, ITEM_HH_WATER_BASIN, 1, 12, STARTER_ELEMENT_FLAGS),
    HABITAT_CONDITIONS_END,
};
static const struct HabitatCondition sFrameMudkipAppear[] = {
    HABITAT_COND(COND_ITEM_PLACED, ITEM_HH_WATER_BASIN, 1, 6, STARTER_ELEMENT_FLAGS),
    HABITAT_COND(COND_ITEM_PLACED, ITEM_HH_LAB_PC, 1, 7, 0),
    HABITAT_COND(COND_ITEM_PLACED, ITEM_HH_POKEBALL_HOLDER, 1, 8, 0),
    HABITAT_COND(COND_ITEM_PLACED, ITEM_HH_CAMPFIRE, 1, 13, STARTER_ELEMENT_FLAGS),
    HABITAT_COND(COND_ITEM_PLACED, ITEM_HH_POTTED_PLANT, 1, 14, STARTER_ELEMENT_FLAGS),
    HABITAT_CONDITIONS_END,
};
static const struct HabitatCondition sFrameAutoBefriend[] = {
    HABITAT_CONDITIONS_END,  // empty: comes home on completion (§10)
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
PLACEHOLDER_HINTS(Pinsir);
PLACEHOLDER_HINTS(FrameTorchic);
PLACEHOLDER_HINTS(FrameTreecko);
PLACEHOLDER_HINTS(FrameMudkip);

#define LAB_MAP_GROUP MAP_GROUP(MAP_LITTLEROOT_TOWN_PROFESSOR_BIRCHS_LAB)
#define LAB_MAP_NUM   MAP_NUM(MAP_LITTLEROOT_TOWN_PROFESSOR_BIRCHS_LAB)

#define SPOT_HINTS(name) sHintDormant_##name, sHintStirring_##name, sHintActive_##name

const struct HabitatSpot gHabitatSpots[] = {
    {
        .spotId = SPOT_SKITTY, .species = SPECIES_SKITTY, .tier = 1, .zoneId = 1,
        .appearConditions = sSkittyAppear, .befriendConditions = sSkittyBefriend,
        .hintDormant = sHintDormant_Skitty, .hintStirring = sHintStirring_Skitty, .hintActive = sHintActive_Skitty,
        .workerRole = ROLE_NONE, .personalityId = NULL,
        .hideFlag = FLAG_HABITAT_SPOT_SKITTY,
        .mapGroup = SLICE_MAP_GROUP, .mapNum = SLICE_MAP_NUM, .localId = LOCALID_HABITAT_SPOT_SKITTY,
        .engineFlags = 0, .dependencyMask = DEP_SKITTY,
    },
    {
        .spotId = SPOT_LOTAD, .species = SPECIES_LOTAD, .tier = 2, .zoneId = 1,
        .appearConditions = sLotadAppear, .befriendConditions = sLotadBefriend,
        .hintDormant = sHintDormant_Lotad, .hintStirring = sHintStirring_Lotad, .hintActive = sHintActive_Lotad,
        .workerRole = ROLE_IRRIGATE, .personalityId = NULL,
        .hideFlag = FLAG_HABITAT_SPOT_LOTAD,
        .mapGroup = SLICE_MAP_GROUP, .mapNum = SLICE_MAP_NUM, .localId = LOCALID_HABITAT_SPOT_LOTAD,
        .engineFlags = 0, .dependencyMask = DEP_LOTAD,
    },
    {
        .spotId = SPOT_MACHOP, .species = SPECIES_MACHOP, .tier = 2, .zoneId = 1,
        .appearConditions = sMachopAppear, .befriendConditions = sMachopBefriend,
        .hintDormant = sHintDormant_Machop, .hintStirring = sHintStirring_Machop, .hintActive = sHintActive_Machop,
        .workerRole = ROLE_DIG, .personalityId = NULL,
        .hideFlag = FLAG_HABITAT_SPOT_MACHOP,
        .mapGroup = SLICE_MAP_GROUP, .mapNum = SLICE_MAP_NUM, .localId = LOCALID_HABITAT_SPOT_MACHOP,
        .engineFlags = 0, .dependencyMask = DEP_MACHOP,
    },
    {
        .spotId = SPOT_VULPIX, .species = SPECIES_VULPIX, .tier = 2, .zoneId = 1,
        .appearConditions = sVulpixAppear, .befriendConditions = sVulpixBefriend,
        .hintDormant = sHintDormant_Vulpix, .hintStirring = sHintStirring_Vulpix, .hintActive = sHintActive_Vulpix,
        .workerRole = ROLE_WARM, .personalityId = NULL,
        .hideFlag = FLAG_HABITAT_SPOT_VULPIX,
        .mapGroup = SLICE_MAP_GROUP, .mapNum = SLICE_MAP_NUM, .localId = LOCALID_HABITAT_SPOT_VULPIX,
        .engineFlags = 0, .dependencyMask = DEP_VULPIX,
    },
    {
        .spotId = SPOT_HERACROSS, .species = SPECIES_HERACROSS, .tier = 3, .zoneId = 1,
        .appearConditions = sHeracrossAppear, .befriendConditions = sHeracrossBefriend,
        .hintDormant = sHintDormant_Heracross, .hintStirring = sHintStirring_Heracross, .hintActive = sHintActive_Heracross,
        .workerRole = ROLE_POLLINATE, .personalityId = NULL,
        .hideFlag = FLAG_HABITAT_SPOT_HERACROSS,
        .mapGroup = SLICE_MAP_GROUP, .mapNum = SLICE_MAP_NUM, .localId = LOCALID_HABITAT_SPOT_HERACROSS,
        .engineFlags = 0, .dependencyMask = DEP_HERACROSS,
    },
    {
        .spotId = SPOT_PINSIR, .species = SPECIES_PINSIR, .tier = 2, .zoneId = 1,
        .appearConditions = sPinsirAppear, .befriendConditions = sPinsirBefriend,
        .hintDormant = sHintDormant_Pinsir, .hintStirring = sHintStirring_Pinsir, .hintActive = sHintActive_Pinsir,
        .workerRole = ROLE_POLLINATE, .personalityId = NULL,
        .hideFlag = FLAG_HABITAT_SPOT_PINSIR,
        .mapGroup = SLICE_MAP_GROUP, .mapNum = SLICE_MAP_NUM, .localId = LOCALID_HABITAT_SPOT_PINSIR,
        .engineFlags = 0, .dependencyMask = DEP_PINSIR,
    },
    {
        .spotId = SPOT_FRAME_TORCHIC, .species = SPECIES_NONE,
        .speciesChoices = sStarterChoices, .speciesChoiceGroup = STARTER_CHOICE_GROUP,
        .tier = 1, .zoneId = 2,
        .appearConditions = sFrameTorchicAppear, .befriendConditions = sFrameAutoBefriend,
        .hintDormant = sHintDormant_FrameTorchic, .hintStirring = sHintStirring_FrameTorchic, .hintActive = sHintActive_FrameTorchic,
        .workerRole = ROLE_WARM, .personalityId = NULL,
        .hideFlag = FLAG_HABITAT_FRAME_TORCHIC,
        .mapGroup = LAB_MAP_GROUP, .mapNum = LAB_MAP_NUM, .localId = LOCALID_HABITAT_FRAME_TORCHIC,
        .graphicsVar = VAR_OBJ_GFX_ID_7,
        .engineFlags = 0, .dependencyMask = DEP_FRAME,
    },
    {
        .spotId = SPOT_FRAME_TREECKO, .species = SPECIES_NONE,
        .speciesChoices = sStarterChoices, .speciesChoiceGroup = STARTER_CHOICE_GROUP,
        .tier = 1, .zoneId = 2,
        .appearConditions = sFrameTreeckoAppear, .befriendConditions = sFrameAutoBefriend,
        .hintDormant = sHintDormant_FrameTreecko, .hintStirring = sHintStirring_FrameTreecko, .hintActive = sHintActive_FrameTreecko,
        .workerRole = ROLE_TEND, .personalityId = NULL,
        .hideFlag = FLAG_HABITAT_FRAME_TREECKO,
        .mapGroup = LAB_MAP_GROUP, .mapNum = LAB_MAP_NUM, .localId = LOCALID_HABITAT_FRAME_TREECKO,
        .graphicsVar = VAR_OBJ_GFX_ID_8,
        .engineFlags = 0, .dependencyMask = DEP_FRAME,
    },
    {
        .spotId = SPOT_FRAME_MUDKIP, .species = SPECIES_NONE,
        .speciesChoices = sStarterChoices, .speciesChoiceGroup = STARTER_CHOICE_GROUP,
        .tier = 1, .zoneId = 2,
        .appearConditions = sFrameMudkipAppear, .befriendConditions = sFrameAutoBefriend,
        .hintDormant = sHintDormant_FrameMudkip, .hintStirring = sHintStirring_FrameMudkip, .hintActive = sHintActive_FrameMudkip,
        .workerRole = ROLE_IRRIGATE, .personalityId = NULL,
        .hideFlag = FLAG_HABITAT_FRAME_MUDKIP,
        .mapGroup = LAB_MAP_GROUP, .mapNum = LAB_MAP_NUM, .localId = LOCALID_HABITAT_FRAME_MUDKIP,
        .graphicsVar = VAR_OBJ_GFX_ID_9,
        .engineFlags = 0, .dependencyMask = DEP_FRAME,
    },
    { .spotId = 0xFFFF },
};

const struct HabitatMapSpan gHabitatMapSpans[] = {
    { .mapGroup = SLICE_MAP_GROUP, .mapNum = SLICE_MAP_NUM, .firstSpot = 0, .count = 6 },
    { .mapGroup = LAB_MAP_GROUP, .mapNum = LAB_MAP_NUM, .firstSpot = 6, .count = 3 },
    { .count = 0 },
};

const struct HabitatZone gHabitatZones[] = {
    { .zoneId = 1, .berryTreeIdFirst = BERRY_TREE_ROUTE_103_CHERI_1, .berryTreeIdLast = BERRY_TREE_ROUTE_103_CHERI_2 },
    { .zoneId = 2 },  // the lab (§10); no berry trees
    { .zoneId = 0 },
};

const struct HabitatSpot *Habitat_GetSpot(u16 spotId)
{
    const struct HabitatSpot *spots = Habitat_GetSpotTable();
    u32 i;
    for (i = 0; spots[i].spotId != 0xFFFF; i++)
    {
        if (spots[i].spotId == spotId)
            return &spots[i];
    }
    return NULL;
}

u16 Habitat_GetResolvedSpotSpecies(const struct HabitatSpot *spot)
{
    const struct HabitatSpeciesChoice *choice;
    u32 i, j;

    if (spot == NULL)
        return SPECIES_NONE;
    if (spot->speciesChoices == NULL)
        return spot->species;
    for (i = 0; spot->speciesChoices[i].itemId != ITEM_NONE; i++)
    {
        choice = &spot->speciesChoices[i];
        for (j = 0; spot->appearConditions[j].type != COND_NONE && j < HABITAT_MAX_CONDITIONS; j++)
        {
            const struct HabitatCondition *condition = &spot->appearConditions[j];
            if (condition->type == COND_ITEM_PLACED
             && condition->paramA == choice->itemId
             && Habitat_GetPlacedCount(condition->paramC) >= max(1, condition->paramB))
                return choice->species;
        }
    }
    return SPECIES_NONE;
}

bool32 Habitat_IsSpeciesChoiceAvailable(const struct HabitatSpot *spot, u16 itemId)
{
    const struct HabitatSpot *spots = Habitat_GetSpotTable();
    u16 requestedSpecies = SPECIES_NONE;
    u32 i;

    if (spot == NULL || spot->speciesChoices == NULL || spot->speciesChoiceGroup == 0
     || Habitat_GetSpotState(spot->spotId) == HABITAT_STATE_BEFRIENDED)
        return FALSE;
    for (i = 0; spot->speciesChoices[i].itemId != ITEM_NONE; i++)
    {
        if (spot->speciesChoices[i].itemId == itemId)
        {
            requestedSpecies = spot->speciesChoices[i].species;
            break;
        }
    }
    if (requestedSpecies == SPECIES_NONE)
        return FALSE;

    for (i = 0; spots[i].spotId != 0xFFFF; i++)
    {
        u16 resolved;

        if (spots[i].speciesChoiceGroup != spot->speciesChoiceGroup)
            continue;
        resolved = Habitat_GetResolvedSpotSpecies(&spots[i]);
        if (resolved == requestedSpecies || (&spots[i] == spot && resolved != SPECIES_NONE))
            return FALSE;
    }
    return TRUE;
}

const struct HabitatSpot *Habitat_GetSpotByObject(u8 mapGroup, u8 mapNum, u8 localId)
{
    const struct HabitatSpot *spots = Habitat_GetSpotTable();
    u32 i;
    for (i = 0; spots[i].spotId != 0xFFFF; i++)
    {
        if (spots[i].mapGroup == mapGroup
         && spots[i].mapNum == mapNum
         && spots[i].localId == localId)
            return &spots[i];
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
