static const struct SafariZone sSafariZones[SAFARI_COUNT] = {
    [NONE_SAFARI] = {0},
    [ROUTE_121_HOENN_SAFARI] = {
        .rules = RSE_SAFARI,
        .startingBalls = 30,
        .startingSteps = 500,
        .catchMultiplier = 150,
        .exitWarp = {
            .mapGroup = MAP_GROUP(MAP_ROUTE121_SAFARI_ZONE_ENTRANCE),
            .mapNum = MAP_NUM(MAP_ROUTE121_SAFARI_ZONE_ENTRANCE),
            .warpId = 0
        }
    },
    [FUSCHIA_CITY_SAFARI] = {
        .rules = FRLG_SAFARI,
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
