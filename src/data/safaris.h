static const struct SafariData sSafariZones[SAFARI_EVENT_COUNT] = {
    [SAFARI_EVENT_NONE] = {0},
    [SAFARI_EVENT_HOENN] = {
        .actions = SAFARI_ACTIONS_RSE,
        .startingBalls = 30,
        .startingSteps = 500,
        .catchMultiplier = 150,
        .exitWarp = {
            .mapGroup = MAP_GROUP(MAP_ROUTE121_SAFARI_ZONE_ENTRANCE),
            .mapNum = MAP_NUM(MAP_ROUTE121_SAFARI_ZONE_ENTRANCE),
            .warpId = 0
        }
    },
    [SAFARI_EVENT_KANTO] = {
        .actions = SAFARI_ACTIONS_FRLG,
        .startingBalls = 30,
        .startingSteps = 600,
        .catchMultiplier = 150,
        .exitWarp = {
            .mapGroup = MAP_GROUP(MAP_FUCHSIA_CITY_SAFARI_ZONE_ENTRANCE),
            .mapNum = MAP_NUM(MAP_FUCHSIA_CITY_SAFARI_ZONE_ENTRANCE),
            .warpId = 0
        }
    },
};
