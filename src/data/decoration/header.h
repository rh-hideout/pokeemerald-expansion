const struct Decoration gDecorations[] =
{
    [DECOR_NONE] =
    {
        .id = DECOR_NONE,
        .name = _("[Small Desk]"),
        .permission = DECORPERM_SOLID_FLOOR,
        .shape = DECORSHAPE_1x1,
        .category = DECORCAT_DESK,
        .price = 0,
        .description = COMPOUND_STRING(
            "A small desk built\n"
            "for one."),
        .tiles = DecorGfx_SMALL_DESK,
        .icon = {gItemIcon_QuestionMark, gItemIconPalette_QuestionMark},
    },

    [DECOR_SMALL_DESK] =
    {
        .id = DECOR_SMALL_DESK,
        .name = _("[Small Desk]"),
        .permission = DECORPERM_SOLID_FLOOR,
        .shape = DECORSHAPE_1x1,
        .category = DECORCAT_DESK,
        .price = 3000,
        .description = COMPOUND_STRING(
            "A small desk built\n"
            "for one."),
        .tiles = DecorGfx_SMALL_DESK,
        .icon = {NULL, NULL},
    },

    [DECOR_POKEMON_DESK] =
    {
        .id = DECOR_POKEMON_DESK,
        .name = _("[Pokémon Desk]"),
        .permission = DECORPERM_SOLID_FLOOR,
        .shape = DECORSHAPE_1x1,
        .category = DECORCAT_DESK,
        .price = 3000,
        .description = COMPOUND_STRING(
            "A small desk built in\n"
            "the shape of a [Poké]\n"
            "[Ball]."),
        .tiles = DecorGfx_POKEMON_DESK,
        .icon = {NULL, NULL},
    },

    [DECOR_HEAVY_DESK] =
    {
        .id = DECOR_HEAVY_DESK,
        .name = _("[Heavy Desk]"),
        .permission = DECORPERM_SOLID_FLOOR,
        .shape = DECORSHAPE_3x2,
        .category = DECORCAT_DESK,
        .price = 6000,
        .description = COMPOUND_STRING(
            "A large desk made\n"
            "of steel. Put some\n"
            "decorations on it."),
        .tiles = DecorGfx_HEAVY_DESK,
        .icon = {gDecorIcon_HeavyDesk, gDecorIconPalette_HeavyDesk},
    },

    [DECOR_RAGGED_DESK] =
    {
        .id = DECOR_RAGGED_DESK,
        .name = _("[Ragged Desk]"),
        .permission = DECORPERM_SOLID_FLOOR,
        .shape = DECORSHAPE_3x2,
        .category = DECORCAT_DESK,
        .price = 6000,
        .description = COMPOUND_STRING(
            "A large desk made\n"
            "of wood. Put some\n"
            "decorations on it."),
        .tiles = DecorGfx_RAGGED_DESK,
        .icon = {gDecorIcon_RaggedDesk, gDecorIconPalette_RaggedDesk},
    },

    [DECOR_COMFORT_DESK] =
    {
        .id = DECOR_COMFORT_DESK,
        .name = _("[Comfort Desk]"),
        .permission = DECORPERM_SOLID_FLOOR,
        .shape = DECORSHAPE_3x2,
        .category = DECORCAT_DESK,
        .price = 6000,
        .description = COMPOUND_STRING(
            "A large desk made\n"
            "of leaves. Put some\n"
            "decorations on it."),
        .tiles = DecorGfx_COMFORT_DESK,
        .icon = {gDecorIcon_ComfortDesk, gDecorIconPalette_ComfortDesk},
    },

    [DECOR_PRETTY_DESK] =
    {
        .id = DECOR_PRETTY_DESK,
        .name = _("[Pretty Desk]"),
        .permission = DECORPERM_SOLID_FLOOR,
        .shape = DECORSHAPE_3x3,
        .category = DECORCAT_DESK,
        .price = 9000,
        .description = COMPOUND_STRING(
            "A huge desk made\n"
            "of glass. Holds lots\n"
            "of decorations."),
        .tiles = DecorGfx_PRETTY_DESK,
        .icon = {gDecorIcon_PrettyDesk, gDecorIconPalette_PrettyDesk},
    },

    [DECOR_BRICK_DESK] =
    {
        .id = DECOR_BRICK_DESK,
        .name = _("[Brick Desk]"),
        .permission = DECORPERM_SOLID_FLOOR,
        .shape = DECORSHAPE_3x3,
        .category = DECORCAT_DESK,
        .price = 9000,
        .description = COMPOUND_STRING(
            "A huge desk made\n"
            "of brick. Holds lots\n"
            "of decorations."),
        .tiles = DecorGfx_BRICK_DESK,
        .icon = {gDecorIcon_BrickDesk, gDecorIconPalette_BrickDesk},
    },

    [DECOR_CAMP_DESK] =
    {
        .id = DECOR_CAMP_DESK,
        .name = _("[Camp Desk]"),
        .permission = DECORPERM_SOLID_FLOOR,
        .shape = DECORSHAPE_3x3,
        .category = DECORCAT_DESK,
        .price = 9000,
        .description = COMPOUND_STRING(
            "A huge desk made\n"
            "of logs. Put lots of\n"
            "decorations on it."),
        .tiles = DecorGfx_CAMP_DESK,
        .icon = {gDecorIcon_CampDesk, gDecorIconPalette_CampDesk},
    },

    [DECOR_HARD_DESK] =
    {
        .id = DECOR_HARD_DESK,
        .name = _("[Hard Desk]"),
        .permission = DECORPERM_SOLID_FLOOR,
        .shape = DECORSHAPE_3x3,
        .category = DECORCAT_DESK,
        .price = 9000,
        .description = COMPOUND_STRING(
            "A huge desk made\n"
            "of rocks. Holds\n"
            "many decorations."),
        .tiles = DecorGfx_HARD_DESK,
        .icon = {gDecorIcon_HardDesk, gDecorIconPalette_HardDesk},
    },

    [DECOR_SMALL_CHAIR] =
    {
        .id = DECOR_SMALL_CHAIR,
        .name = _("[Small Chair]"),
        .permission = DECORPERM_PASS_FLOOR,
        .shape = DECORSHAPE_1x1,
        .category = DECORCAT_CHAIR,
        .price = 2000,
        .description = COMPOUND_STRING(
            "A small chair made\n"
            "for one."),
        .tiles = DecorGfx_SMALL_CHAIR,
        .icon = {NULL, NULL},
    },

    [DECOR_POKEMON_CHAIR] =
    {
        .id = DECOR_POKEMON_CHAIR,
        .name = _("[Pokémon Chair]"),
        .permission = DECORPERM_PASS_FLOOR,
        .shape = DECORSHAPE_1x1,
        .category = DECORCAT_CHAIR,
        .price = 2000,
        .description = COMPOUND_STRING(
            "A small chair built\n"
            "in the shape of a\n"
            "[Poké Ball]."),
        .tiles = DecorGfx_POKEMON_CHAIR,
        .icon = {NULL, NULL},
    },

    [DECOR_HEAVY_CHAIR] =
    {
        .id = DECOR_HEAVY_CHAIR,
        .name = _("[Heavy Chair]"),
        .permission = DECORPERM_PASS_FLOOR,
        .shape = DECORSHAPE_1x1,
        .category = DECORCAT_CHAIR,
        .price = 2000,
        .description = COMPOUND_STRING(
            "A small chair made\n"
            "of steel."),
        .tiles = DecorGfx_HEAVY_CHAIR,
        .icon = {NULL, NULL},
    },

    [DECOR_PRETTY_CHAIR] =
    {
        .id = DECOR_PRETTY_CHAIR,
        .name = _("[Pretty Chair]"),
        .permission = DECORPERM_PASS_FLOOR,
        .shape = DECORSHAPE_1x1,
        .category = DECORCAT_CHAIR,
        .price = 2000,
        .description = COMPOUND_STRING(
            "A small chair made\n"
            "of glass."),
        .tiles = DecorGfx_PRETTY_CHAIR,
        .icon = {NULL, NULL},
    },

    [DECOR_COMFORT_CHAIR] =
    {
        .id = DECOR_COMFORT_CHAIR,
        .name = _("[Comfort Chair]"),
        .permission = DECORPERM_PASS_FLOOR,
        .shape = DECORSHAPE_1x1,
        .category = DECORCAT_CHAIR,
        .price = 2000,
        .description = COMPOUND_STRING(
            "A small chair made\n"
            "of leaves."),
        .tiles = DecorGfx_COMFORT_CHAIR,
        .icon = {NULL, NULL},
    },

    [DECOR_RAGGED_CHAIR] =
    {
        .id = DECOR_RAGGED_CHAIR,
        .name = _("[Ragged Chair]"),
        .permission = DECORPERM_PASS_FLOOR,
        .shape = DECORSHAPE_1x1,
        .category = DECORCAT_CHAIR,
        .price = 2000,
        .description = COMPOUND_STRING(
            "A small chair made\n"
            "of wood."),
        .tiles = DecorGfx_RAGGED_CHAIR,
        .icon = {NULL, NULL},
    },

    [DECOR_BRICK_CHAIR] =
    {
        .id = DECOR_BRICK_CHAIR,
        .name = _("[Brick Chair]"),
        .permission = DECORPERM_PASS_FLOOR,
        .shape = DECORSHAPE_1x1,
        .category = DECORCAT_CHAIR,
        .price = 2000,
        .description = COMPOUND_STRING(
            "A small chair made\n"
            "of brick."),
        .tiles = DecorGfx_BRICK_CHAIR,
        .icon = {NULL, NULL},
    },

    [DECOR_CAMP_CHAIR] =
    {
        .id = DECOR_CAMP_CHAIR,
        .name = _("[Camp Chair]"),
        .permission = DECORPERM_PASS_FLOOR,
        .shape = DECORSHAPE_1x1,
        .category = DECORCAT_CHAIR,
        .price = 2000,
        .description = COMPOUND_STRING(
            "A small chair made\n"
            "of logs."),
        .tiles = DecorGfx_CAMP_CHAIR,
        .icon = {NULL, NULL},
    },

    [DECOR_HARD_CHAIR] =
    {
        .id = DECOR_HARD_CHAIR,
        .name = _("[Hard Chair]"),
        .permission = DECORPERM_PASS_FLOOR,
        .shape = DECORSHAPE_1x1,
        .category = DECORCAT_CHAIR,
        .price = 2000,
        .description = COMPOUND_STRING(
            "A small chair made\n"
            "of rock."),
        .tiles = DecorGfx_HARD_CHAIR,
        .icon = {NULL, NULL},
    },

    [DECOR_RED_PLANT] =
    {
        .id = DECOR_RED_PLANT,
        .name = _("[Red Plant]"),
        .permission = DECORPERM_BEHIND_FLOOR,
        .shape = DECORSHAPE_1x2,
        .category = DECORCAT_PLANT,
        .price = 3000,
        .description = COMPOUND_STRING(
            "A vivid red potted\n"
            "plant."),
        .tiles = DecorGfx_RED_PLANT,
        .icon = {gDecorIcon_RedPlant, gDecorIconPalette_RedPlant},
    },

    [DECOR_TROPICAL_PLANT] =
    {
        .id = DECOR_TROPICAL_PLANT,
        .name = _("[Tropical Plant]"),
        .permission = DECORPERM_BEHIND_FLOOR,
        .shape = DECORSHAPE_1x2,
        .category = DECORCAT_PLANT,
        .price = 3000,
        .description = COMPOUND_STRING(
            "A flowering tropical\n"
            "plant in a pot."),
        .tiles = DecorGfx_TROPICAL_PLANT,
        .icon = {gDecorIcon_TropicalPlant, gDecorIconPalette_TropicalPlant},
    },

    [DECOR_PRETTY_FLOWERS] =
    {
        .id = DECOR_PRETTY_FLOWERS,
        .name = _("[Pretty Flowers]"),
        .permission = DECORPERM_BEHIND_FLOOR,
        .shape = DECORSHAPE_1x2,
        .category = DECORCAT_PLANT,
        .price = 3000,
        .description = COMPOUND_STRING(
            "A pot of cute\n"
            "flowers."),
        .tiles = DecorGfx_PRETTY_FLOWERS,
        .icon = {gDecorIcon_PrettyFlowers, gDecorIconPalette_PrettyFlowers},
    },

    [DECOR_COLORFUL_PLANT] =
    {
        .id = DECOR_COLORFUL_PLANT,
        .name = _("[Colorful Plant]"),
        .permission = DECORPERM_BEHIND_FLOOR,
        .shape = DECORSHAPE_2x2,
        .category = DECORCAT_PLANT,
        .price = 5000,
        .description = COMPOUND_STRING(
            "A large pot with\n"
            "many colorful\n"
            "flowers."),
        .tiles = DecorGfx_COLORFUL_PLANT,
        .icon = {gDecorIcon_ColorfulPlant, gDecorIconPalette_ColorfulPlant},
    },

    [DECOR_BIG_PLANT] =
    {
        .id = DECOR_BIG_PLANT,
        .name = _("[Big Plant]"),
        .permission = DECORPERM_BEHIND_FLOOR,
        .shape = DECORSHAPE_2x2,
        .category = DECORCAT_PLANT,
        .price = 5000,
        .description = COMPOUND_STRING(
            "A large, umbrella-\n"
            "shaped plant in a\n"
            "big pot."),
        .tiles = DecorGfx_BIG_PLANT,
        .icon = {gDecorIcon_BigPlant, gDecorIconPalette_BigPlant},
    },

    [DECOR_GORGEOUS_PLANT] =
    {
        .id = DECOR_GORGEOUS_PLANT,
        .name = _("[Gorgeous Plant]"),
        .permission = DECORPERM_BEHIND_FLOOR,
        .shape = DECORSHAPE_2x2,
        .category = DECORCAT_PLANT,
        .price = 5000,
        .description = COMPOUND_STRING(
            "A large, impressive\n"
            "plant in a big pot."),
        .tiles = DecorGfx_GORGEOUS_PLANT,
        .icon = {gDecorIcon_GorgeousPlant, gDecorIconPalette_GorgeousPlant},
    },

    [DECOR_RED_BRICK] =
    {
        .id = DECOR_RED_BRICK,
        .name = _("[Red Brick]"),
        .permission = DECORPERM_SOLID_FLOOR,
        .shape = DECORSHAPE_1x2,
        .category = DECORCAT_ORNAMENT,
        .price = 500,
        .description = COMPOUND_STRING(
            "A red-colored brick.\n"
            "Decorations can be\n"
            "placed on top."),
        .tiles = DecorGfx_RED_BRICK,
        .icon = {gDecorIcon_RedBrick, gDecorIconPalette_RedBrick},
    },

    [DECOR_YELLOW_BRICK] =
    {
        .id = DECOR_YELLOW_BRICK,
        .name = _("[Yellow Brick]"),
        .permission = DECORPERM_SOLID_FLOOR,
        .shape = DECORSHAPE_1x2,
        .category = DECORCAT_ORNAMENT,
        .price = 500,
        .description = COMPOUND_STRING(
            "A yellow-colored\n"
            "brick. Put some\n"
            "decorations on top."),
        .tiles = DecorGfx_YELLOW_BRICK,
        .icon = {gDecorIcon_YellowBrick, gDecorIconPalette_YellowBrick},
    },

    [DECOR_BLUE_BRICK] =
    {
        .id = DECOR_BLUE_BRICK,
        .name = _("[Blue Brick]"),
        .permission = DECORPERM_SOLID_FLOOR,
        .shape = DECORSHAPE_1x2,
        .category = DECORCAT_ORNAMENT,
        .price = 500,
        .description = COMPOUND_STRING(
            "A blue-colored\n"
            "brick. Put some\n"
            "decorations on top."),
        .tiles = DecorGfx_BLUE_BRICK,
        .icon = {gDecorIcon_BlueBrick, gDecorIconPalette_BlueBrick},
    },

    [DECOR_RED_BALLOON] =
    {
        .id = DECOR_RED_BALLOON,
        .name = _("[Red Balloon]"),
        .permission = DECORPERM_PASS_FLOOR,
        .shape = DECORSHAPE_1x1,
        .category = DECORCAT_ORNAMENT,
        .price = 500,
        .description = COMPOUND_STRING(
            "A red balloon filled\n"
            "with water. Bursts\n"
            "if stepped on."),
        .tiles = DecorGfx_RED_BALLOON,
        .icon = {NULL, NULL},
    },

    [DECOR_BLUE_BALLOON] =
    {
        .id = DECOR_BLUE_BALLOON,
        .name = _("[Blue Balloon]"),
        .permission = DECORPERM_PASS_FLOOR,
        .shape = DECORSHAPE_1x1,
        .category = DECORCAT_ORNAMENT,
        .price = 500,
        .description = COMPOUND_STRING(
            "A blue balloon filled\n"
            "with water. Bursts\n"
            "if stepped on."),
        .tiles = DecorGfx_BLUE_BALLOON,
        .icon = {NULL, NULL},
    },

    [DECOR_YELLOW_BALLOON] =
    {
        .id = DECOR_YELLOW_BALLOON,
        .name = _("[Yellow Balloon]"),
        .permission = DECORPERM_PASS_FLOOR,
        .shape = DECORSHAPE_1x1,
        .category = DECORCAT_ORNAMENT,
        .price = 500,
        .description = COMPOUND_STRING(
            "A yellow balloon\n"
            "filled with water.\n"
            "Pops if stepped on."),
        .tiles = DecorGfx_YELLOW_BALLOON,
        .icon = {NULL, NULL},
    },

    [DECOR_RED_TENT] =
    {
        .id = DECOR_RED_TENT,
        .name = _("[Red Tent]"),
        .permission = DECORPERM_PASS_FLOOR,
        .shape = DECORSHAPE_3x3,
        .category = DECORCAT_ORNAMENT,
        .price = 10000,
        .description = COMPOUND_STRING(
            "A large red tent.\n"
            "You can hide inside\n"
            "it."),
        .tiles = DecorGfx_RED_TENT,
        .icon = {gDecorIcon_RedTent, gDecorIconPalette_RedTent},
    },

    [DECOR_BLUE_TENT] =
    {
        .id = DECOR_BLUE_TENT,
        .name = _("[Blue Tent]"),
        .permission = DECORPERM_PASS_FLOOR,
        .shape = DECORSHAPE_3x3,
        .category = DECORCAT_ORNAMENT,
        .price = 10000,
        .description = COMPOUND_STRING(
            "A large blue tent.\n"
            "You can hide inside\n"
            "it."),
        .tiles = DecorGfx_BLUE_TENT,
        .icon = {gDecorIcon_BlueTent, gDecorIconPalette_BlueTent},
    },

    [DECOR_SOLID_BOARD] =
    {
        .id = DECOR_SOLID_BOARD,
        .name = _("[Solid Board]"),
        .permission = DECORPERM_PASS_FLOOR,
        .shape = DECORSHAPE_1x2,
        .category = DECORCAT_ORNAMENT,
        .price = 3000,
        .description = COMPOUND_STRING(
            "Place over a hole to\n"
            "cross to the other\n"
            "side."),
        .tiles = DecorGfx_SOLID_BOARD,
        .icon = {gDecorIcon_SolidBoard, gDecorIconPalette_SolidBoard},
    },

    [DECOR_SLIDE] =
    {
        .id = DECOR_SLIDE,
        .name = _("[Slide]"),
        .permission = DECORPERM_PASS_FLOOR,
        .shape = DECORSHAPE_2x4,
        .category = DECORCAT_ORNAMENT,
        .price = 8000,
        .description = COMPOUND_STRING(
            "Use to slide down\n"
            "from the platform."),
        .tiles = DecorGfx_SLIDE,
        .icon = {gDecorIcon_Slide, gDecorIconPalette_Slide},
    },

    [DECOR_FENCE_LENGTH] =
    {
        .id = DECOR_FENCE_LENGTH,
        .name = _("[Fence Length]"),
        .permission = DECORPERM_SOLID_FLOOR,
        .shape = DECORSHAPE_1x1,
        .category = DECORCAT_ORNAMENT,
        .price = 500,
        .description = COMPOUND_STRING(
            "A small fence that\n"
            "blocks passage."),
        .tiles = DecorGfx_FENCE_LENGTH,
        .icon = {NULL, NULL},
    },

    [DECOR_FENCE_WIDTH] =
    {
        .id = DECOR_FENCE_WIDTH,
        .name = _("[Fence Width]"),
        .permission = DECORPERM_SOLID_FLOOR,
        .shape = DECORSHAPE_1x1,
        .category = DECORCAT_ORNAMENT,
        .price = 500,
        .description = COMPOUND_STRING(
            "A small fence that\n"
            "blocks passage."),
        .tiles = DecorGfx_FENCE_WIDTH,
        .icon = {NULL, NULL},
    },

    [DECOR_TIRE] =
    {
        .id = DECOR_TIRE,
        .name = _("[Tire]"),
        .permission = DECORPERM_SOLID_FLOOR,
        .shape = DECORSHAPE_2x2,
        .category = DECORCAT_ORNAMENT,
        .price = 800,
        .description = COMPOUND_STRING(
            "An old large tire.\n"
            "Decorations can be\n"
            "placed on top."),
        .tiles = DecorGfx_TIRE,
        .icon = {gDecorIcon_Tire, gDecorIconPalette_Tire},
    },

    [DECOR_STAND] =
    {
        .id = DECOR_STAND,
        .name = _("[Stand]"),
        .permission = DECORPERM_PASS_FLOOR,
        .shape = DECORSHAPE_4x2,
        .category = DECORCAT_ORNAMENT,
        .price = 7000,
        .description = COMPOUND_STRING(
            "A large pedestal\n"
            "with steps."),
        .tiles = DecorGfx_STAND,
        .icon = {gDecorIcon_Stand, gDecorIconPalette_Stand},
    },

    [DECOR_MUD_BALL] =
    {
        .id = DECOR_MUD_BALL,
        .name = _("[Mud Ball]"),
        .permission = DECORPERM_PASS_FLOOR,
        .shape = DECORSHAPE_1x1,
        .category = DECORCAT_ORNAMENT,
        .price = 200,
        .description = COMPOUND_STRING(
            "A large ball of mud.\n"
            "Crumbles if stepped\n"
            "on."),
        .tiles = DecorGfx_MUD_BALL,
        .icon = {NULL, NULL},
    },

    [DECOR_BREAKABLE_DOOR] =
    {
        .id = DECOR_BREAKABLE_DOOR,
        .name = _("[Breakable Door]"),
        .permission = DECORPERM_PASS_FLOOR,
        .shape = DECORSHAPE_1x2,
        .category = DECORCAT_ORNAMENT,
        .price = 3000,
        .description = COMPOUND_STRING(
            "A weird door that\n"
            "people can walk\n"
            "right through."),
        .tiles = DecorGfx_BREAKABLE_DOOR,
        .icon = {gDecorIcon_BreakableDoor, gDecorIconPalette_BreakableDoor},
    },

    [DECOR_SAND_ORNAMENT] =
    {
        .id = DECOR_SAND_ORNAMENT,
        .name = _("[Sand Ornament]"),
        .permission = DECORPERM_BEHIND_FLOOR,
        .shape = DECORSHAPE_1x2,
        .category = DECORCAT_ORNAMENT,
        .price = 3000,
        .description = COMPOUND_STRING(
            "An ornament made\n"
            "of sand. Crumbles if\n"
            "touched."),
        .tiles = DecorGfx_SAND_ORNAMENT,
        .icon = {gDecorIcon_SandOrnament, gDecorIconPalette_SandOrnament},
    },

    [DECOR_SILVER_SHIELD] =
    {
        .id = DECOR_SILVER_SHIELD,
        .name = _("[Silver Shield]"),
        .permission = DECORPERM_BEHIND_FLOOR,
        .shape = DECORSHAPE_1x2,
        .category = DECORCAT_ORNAMENT,
        .price = 0,
        .description = COMPOUND_STRING(
            "Awarded for 50\n"
            "straight wins at\n"
            "the [Battle Tower]."),
        .tiles = DecorGfx_SILVER_SHIELD,
        .icon = {NULL, NULL},
    },

    [DECOR_GOLD_SHIELD] =
    {
        .id = DECOR_GOLD_SHIELD,
        .name = _("[Gold Shield]"),
        .permission = DECORPERM_BEHIND_FLOOR,
        .shape = DECORSHAPE_1x2,
        .category = DECORCAT_ORNAMENT,
        .price = 0,
        .description = COMPOUND_STRING(
            "Awarded for 100\n"
            "straight wins at\n"
            "the [Battle Tower]."),
        .tiles = DecorGfx_GOLD_SHIELD,
        .icon = {NULL, NULL},
    },

    [DECOR_GLASS_ORNAMENT] =
    {
        .id = DECOR_GLASS_ORNAMENT,
        .name = _("[Glass Ornament]"),
        .permission = DECORPERM_BEHIND_FLOOR,
        .shape = DECORSHAPE_1x2,
        .category = DECORCAT_ORNAMENT,
        .price = 0,
        .description = COMPOUND_STRING(
            "A glass replica of\n"
            "a famous sculpture\n"
            "at the [Art Museum]."),
        .tiles = DecorGfx_GLASS_ORNAMENT,
        .icon = {gDecorIcon_GlassOrnament, gDecorIconPalette_GlassOrnament},
    },

    [DECOR_TV] =
    {
        .id = DECOR_TV,
        .name = _("[Tv]"),
        .permission = DECORPERM_SOLID_FLOOR,
        .shape = DECORSHAPE_1x1,
        .category = DECORCAT_ORNAMENT,
        .price = 3000,
        .description = COMPOUND_STRING(
            "A small, gray-\n"
            "colored toy TV."),
        .tiles = DecorGfx_TV,
        .icon = {NULL, NULL},
    },

    [DECOR_ROUND_TV] =
    {
        .id = DECOR_ROUND_TV,
        .name = _("[Round Tv]"),
        .permission = DECORPERM_SOLID_FLOOR,
        .shape = DECORSHAPE_1x1,
        .category = DECORCAT_ORNAMENT,
        .price = 4000,
        .description = COMPOUND_STRING(
            "A toy TV modeled\n"
            "in the image of a\n"
            "[Seedot]."),
        .tiles = DecorGfx_ROUND_TV,
        .icon = {NULL, NULL},
    },

    [DECOR_CUTE_TV] =
    {
        .id = DECOR_CUTE_TV,
        .name = _("[Cute Tv]"),
        .permission = DECORPERM_SOLID_FLOOR,
        .shape = DECORSHAPE_1x1,
        .category = DECORCAT_ORNAMENT,
        .price = 4000,
        .description = COMPOUND_STRING(
            "A toy TV modeled\n"
            "in the image of a\n"
            "[Skitty]."),
        .tiles = DecorGfx_CUTE_TV,
        .icon = {NULL, NULL},
    },

    [DECOR_GLITTER_MAT] =
    {
        .id = DECOR_GLITTER_MAT,
        .name = _("[Glitter Mat]"),
        .permission = DECORPERM_PASS_FLOOR,
        .shape = DECORSHAPE_1x1,
        .category = DECORCAT_MAT,
        .price = 2000,
        .description = COMPOUND_STRING(
            "An odd mat that\n"
            "glitters if stepped\n"
            "on."),
        .tiles = DecorGfx_GLITTER_MAT,
        .icon = {NULL, NULL},
    },

    [DECOR_JUMP_MAT] =
    {
        .id = DECOR_JUMP_MAT,
        .name = _("[Jump Mat]"),
        .permission = DECORPERM_PASS_FLOOR,
        .shape = DECORSHAPE_1x1,
        .category = DECORCAT_MAT,
        .price = 2000,
        .description = COMPOUND_STRING(
            "A trick mat that\n"
            "jumps when it is\n"
            "stepped on."),
        .tiles = DecorGfx_JUMP_MAT,
        .icon = {NULL, NULL},
    },

    [DECOR_SPIN_MAT] =
    {
        .id = DECOR_SPIN_MAT,
        .name = _("[Spin Mat]"),
        .permission = DECORPERM_PASS_FLOOR,
        .shape = DECORSHAPE_1x1,
        .category = DECORCAT_MAT,
        .price = 2000,
        .description = COMPOUND_STRING(
            "A trick mat that\n"
            "spins around when\n"
            "stepped on."),
        .tiles = DecorGfx_SPIN_MAT,
        .icon = {NULL, NULL},
    },

    [DECOR_C_LOW_NOTE_MAT] =
    {
        .id = DECOR_C_LOW_NOTE_MAT,
        .name = _("[C Low Note Mat]"),
        .permission = DECORPERM_PASS_FLOOR,
        .shape = DECORSHAPE_1x1,
        .category = DECORCAT_MAT,
        .price = 500,
        .description = COMPOUND_STRING(
            "A mat that plays\n"
            "a low C note when\n"
            "stepped on."),
        .tiles = DecorGfx_C_LOW_NOTE_MAT,
        .icon = {NULL, NULL},
    },

    [DECOR_D_NOTE_MAT] =
    {
        .id = DECOR_D_NOTE_MAT,
        .name = _("[D Note Mat]"),
        .permission = DECORPERM_PASS_FLOOR,
        .shape = DECORSHAPE_1x1,
        .category = DECORCAT_MAT,
        .price = 500,
        .description = COMPOUND_STRING(
            "A mat that plays\n"
            "a D note when\n"
            "stepped on."),
        .tiles = DecorGfx_D_NOTE_MAT,
        .icon = {NULL, NULL},
    },

    [DECOR_E_NOTE_MAT] =
    {
        .id = DECOR_E_NOTE_MAT,
        .name = _("[E Note Mat]"),
        .permission = DECORPERM_PASS_FLOOR,
        .shape = DECORSHAPE_1x1,
        .category = DECORCAT_MAT,
        .price = 500,
        .description = COMPOUND_STRING(
            "A mat that plays\n"
            "an E note when\n"
            "stepped on."),
        .tiles = DecorGfx_E_NOTE_MAT,
        .icon = {NULL, NULL},
    },

    [DECOR_F_NOTE_MAT] =
    {
        .id = DECOR_F_NOTE_MAT,
        .name = _("[F Note Mat]"),
        .permission = DECORPERM_PASS_FLOOR,
        .shape = DECORSHAPE_1x1,
        .category = DECORCAT_MAT,
        .price = 500,
        .description = COMPOUND_STRING(
            "A mat that plays\n"
            "an F note when\n"
            "stepped on."),
        .tiles = DecorGfx_F_NOTE_MAT,
        .icon = {NULL, NULL},
    },

    [DECOR_G_NOTE_MAT] =
    {
        .id = DECOR_G_NOTE_MAT,
        .name = _("[G Note Mat]"),
        .permission = DECORPERM_PASS_FLOOR,
        .shape = DECORSHAPE_1x1,
        .category = DECORCAT_MAT,
        .price = 500,
        .description = COMPOUND_STRING(
            "A mat that plays\n"
            "a G note when\n"
            "stepped on."),
        .tiles = DecorGfx_G_NOTE_MAT,
        .icon = {NULL, NULL},
    },

    [DECOR_A_NOTE_MAT] =
    {
        .id = DECOR_A_NOTE_MAT,
        .name = _("[A Note Mat]"),
        .permission = DECORPERM_PASS_FLOOR,
        .shape = DECORSHAPE_1x1,
        .category = DECORCAT_MAT,
        .price = 500,
        .description = COMPOUND_STRING(
            "A mat that plays\n"
            "an A note when\n"
            "stepped on."),
        .tiles = DecorGfx_A_NOTE_MAT,
        .icon = {NULL, NULL},
    },

    [DECOR_B_NOTE_MAT] =
    {
        .id = DECOR_B_NOTE_MAT,
        .name = _("[B Note Mat]"),
        .permission = DECORPERM_PASS_FLOOR,
        .shape = DECORSHAPE_1x1,
        .category = DECORCAT_MAT,
        .price = 500,
        .description = COMPOUND_STRING(
            "A mat that plays\n"
            "a B note when\n"
            "stepped on."),
        .tiles = DecorGfx_B_NOTE_MAT,
        .icon = {NULL, NULL},
    },

    [DECOR_C_HIGH_NOTE_MAT] =
    {
        .id = DECOR_C_HIGH_NOTE_MAT,
        .name = _("[C High Note Mat]"),
        .permission = DECORPERM_PASS_FLOOR,
        .shape = DECORSHAPE_1x1,
        .category = DECORCAT_MAT,
        .price = 500,
        .description = COMPOUND_STRING(
            "A mat that plays\n"
            "a high C note when\n"
            "stepped on."),
        .tiles = DecorGfx_C_HIGH_NOTE_MAT,
        .icon = {NULL, NULL},
    },

    [DECOR_SURF_MAT] =
    {
        .id = DECOR_SURF_MAT,
        .name = _("[Surf Mat]"),
        .permission = DECORPERM_PASS_FLOOR,
        .shape = DECORSHAPE_3x3,
        .category = DECORCAT_MAT,
        .price = 4000,
        .description = COMPOUND_STRING(
            "A mat designed with\n"
            "a [Surf] image.\n"
            "Put items on top."),
        .tiles = DecorGfx_SURF_MAT,
        .icon = {gDecorIcon_SurfMat, gDecorIconPalette_SurfMat},
    },

    [DECOR_THUNDER_MAT] =
    {
        .id = DECOR_THUNDER_MAT,
        .name = _("[Thunder Mat]"),
        .permission = DECORPERM_PASS_FLOOR,
        .shape = DECORSHAPE_3x3,
        .category = DECORCAT_MAT,
        .price = 4000,
        .description = COMPOUND_STRING(
            "A mat designed with\n"
            "a [Thunder] image.\n"
            "Put items on top."),
        .tiles = DecorGfx_THUNDER_MAT,
        .icon = {gDecorIcon_ThunderMat, gDecorIconPalette_ThunderMat},
    },

    [DECOR_FIRE_BLAST_MAT] =
    {
        .id = DECOR_FIRE_BLAST_MAT,
        .name = _("[Fire Blast Mat]"),
        .permission = DECORPERM_PASS_FLOOR,
        .shape = DECORSHAPE_3x3,
        .category = DECORCAT_MAT,
        .price = 4000,
        .description = COMPOUND_STRING(
            "A mat designed with\n"
            "a [Fire Blast] image.\n"
            "Put items on top."),
        .tiles = DecorGfx_FIRE_BLAST_MAT,
        .icon = {gDecorIcon_FireBlastMat, gDecorIconPalette_FireBlastMat},
    },

    [DECOR_POWDER_SNOW_MAT] =
    {
        .id = DECOR_POWDER_SNOW_MAT,
        .name = _("[Powder Snow Mat]"),
        .permission = DECORPERM_PASS_FLOOR,
        .shape = DECORSHAPE_3x3,
        .category = DECORCAT_MAT,
        .price = 4000,
        .description = COMPOUND_STRING(
            "A mat with a [Powder]\n"
            "[Snow] image design.\n"
            "Put items on top."),
        .tiles = DecorGfx_POWDER_SNOW_MAT,
        .icon = {gDecorIcon_PowderSnowMat, gDecorIconPalette_PowderSnowMat},
    },

    [DECOR_ATTRACT_MAT] =
    {
        .id = DECOR_ATTRACT_MAT,
        .name = _("[Attract Mat]"),
        .permission = DECORPERM_PASS_FLOOR,
        .shape = DECORSHAPE_3x3,
        .category = DECORCAT_MAT,
        .price = 4000,
        .description = COMPOUND_STRING(
            "A mat designed with\n"
            "an [Attract] image.\n"
            "Put items on top."),
        .tiles = DecorGfx_ATTRACT_MAT,
        .icon = {gDecorIcon_AttractMat, gDecorIconPalette_AttractMat},
    },

    [DECOR_FISSURE_MAT] =
    {
        .id = DECOR_FISSURE_MAT,
        .name = _("[Fissure Mat]"),
        .permission = DECORPERM_PASS_FLOOR,
        .shape = DECORSHAPE_3x3,
        .category = DECORCAT_MAT,
        .price = 4000,
        .description = COMPOUND_STRING(
            "A mat designed with\n"
            "a [Fissure] image.\n"
            "Put items on top."),
        .tiles = DecorGfx_FISSURE_MAT,
        .icon = {gDecorIcon_FissureMat, gDecorIconPalette_FissureMat},
    },

    [DECOR_SPIKES_MAT] =
    {
        .id = DECOR_SPIKES_MAT,
        .name = _("[Spikes Mat]"),
        .permission = DECORPERM_PASS_FLOOR,
        .shape = DECORSHAPE_3x3,
        .category = DECORCAT_MAT,
        .price = 4000,
        .description = COMPOUND_STRING(
            "A mat designed with\n"
            "a [Spikes] image.\n"
            "Put items on top."),
        .tiles = DecorGfx_SPIKES_MAT,
        .icon = {gDecorIcon_SpikesMat, gDecorIconPalette_SpikesMat},
    },

    [DECOR_BALL_POSTER] =
    {
        .id = DECOR_BALL_POSTER,
        .name = _("[Ball Poster]"),
        .permission = DECORPERM_NA_WALL,
        .shape = DECORSHAPE_1x1,
        .category = DECORCAT_POSTER,
        .price = 1000,
        .description = COMPOUND_STRING(
            "A small poster\n"
            "printed with [Poké]\n"
            "[Balls]."),
        .tiles = DecorGfx_BALL_POSTER,
        .icon = {NULL, NULL},
    },

    [DECOR_GREEN_POSTER] =
    {
        .id = DECOR_GREEN_POSTER,
        .name = _("[Green Poster]"),
        .permission = DECORPERM_NA_WALL,
        .shape = DECORSHAPE_1x1,
        .category = DECORCAT_POSTER,
        .price = 1000,
        .description = COMPOUND_STRING(
            "A small poster with\n"
            "a [Treecko] print."),
        .tiles = DecorGfx_GREEN_POSTER,
        .icon = {NULL, NULL},
    },

    [DECOR_RED_POSTER] =
    {
        .id = DECOR_RED_POSTER,
        .name = _("[Red Poster]"),
        .permission = DECORPERM_NA_WALL,
        .shape = DECORSHAPE_1x1,
        .category = DECORCAT_POSTER,
        .price = 1000,
        .description = COMPOUND_STRING(
            "A small poster with\n"
            "a [Torchic] print."),
        .tiles = DecorGfx_RED_POSTER,
        .icon = {NULL, NULL},
    },

    [DECOR_BLUE_POSTER] =
    {
        .id = DECOR_BLUE_POSTER,
        .name = _("[Blue Poster]"),
        .permission = DECORPERM_NA_WALL,
        .shape = DECORSHAPE_1x1,
        .category = DECORCAT_POSTER,
        .price = 1000,
        .description = COMPOUND_STRING(
            "A small poster with\n"
            "a [Mudkip] print."),
        .tiles = DecorGfx_BLUE_POSTER,
        .icon = {NULL, NULL},
    },

    [DECOR_CUTE_POSTER] =
    {
        .id = DECOR_CUTE_POSTER,
        .name = _("[Cute Poster]"),
        .permission = DECORPERM_NA_WALL,
        .shape = DECORSHAPE_1x1,
        .category = DECORCAT_POSTER,
        .price = 1000,
        .description = COMPOUND_STRING(
            "A small poster with\n"
            "an [Azurill] print."),
        .tiles = DecorGfx_CUTE_POSTER,
        .icon = {NULL, NULL},
    },

    [DECOR_PIKA_POSTER] =
    {
        .id = DECOR_PIKA_POSTER,
        .name = _("[Pika Poster]"),
        .permission = DECORPERM_NA_WALL,
        .shape = DECORSHAPE_2x1,
        .category = DECORCAT_POSTER,
        .price = 1500,
        .description = COMPOUND_STRING(
            "A large poster with\n"
            "a [Pikachu] and\n"
            "[Pichu] print."),
        .tiles = DecorGfx_PIKA_POSTER,
        .icon = {NULL, NULL},
    },

    [DECOR_LONG_POSTER] =
    {
        .id = DECOR_LONG_POSTER,
        .name = _("[Long Poster]"),
        .permission = DECORPERM_NA_WALL,
        .shape = DECORSHAPE_2x1,
        .category = DECORCAT_POSTER,
        .price = 1500,
        .description = COMPOUND_STRING(
            "A large poster with\n"
            "a [Seviper] print."),
        .tiles = DecorGfx_LONG_POSTER,
        .icon = {NULL, NULL},
    },

    [DECOR_SEA_POSTER] =
    {
        .id = DECOR_SEA_POSTER,
        .name = _("[Sea Poster]"),
        .permission = DECORPERM_NA_WALL,
        .shape = DECORSHAPE_2x1,
        .category = DECORCAT_POSTER,
        .price = 1500,
        .description = COMPOUND_STRING(
            "A large poster with\n"
            "a [Relicanth] print."),
        .tiles = DecorGfx_SEA_POSTER,
        .icon = {NULL, NULL},
    },

    [DECOR_SKY_POSTER] =
    {
        .id = DECOR_SKY_POSTER,
        .name = _("[Sky Poster]"),
        .permission = DECORPERM_NA_WALL,
        .shape = DECORSHAPE_2x1,
        .category = DECORCAT_POSTER,
        .price = 1500,
        .description = COMPOUND_STRING(
            "A large poster with\n"
            "a [Wingull] print."),
        .tiles = DecorGfx_SKY_POSTER,
        .icon = {NULL, NULL},
    },

    [DECOR_KISS_POSTER] =
    {
        .id = DECOR_KISS_POSTER,
        .name = _("[Kiss Poster]"),
        .permission = DECORPERM_NA_WALL,
        .shape = DECORSHAPE_2x1,
        .category = DECORCAT_POSTER,
        .price = 1500,
        .description = COMPOUND_STRING(
            "A large poster with\n"
            "a [Smoochum] print."),
        .tiles = DecorGfx_KISS_POSTER,
        .icon = {NULL, NULL},
    },

    [DECOR_PICHU_DOLL] =
    {
        .id = DECOR_PICHU_DOLL,
        .name = _("[Pichu Doll]"),
        .permission = DECORPERM_SPRITE,
        .shape = DECORSHAPE_1x1,
        .category = DECORCAT_DOLL,
        .price = 3000,
        .description = COMPOUND_STRING(
            "A [Pichu] doll.\n"
            "Place it on a mat\n"
            "or a desk."),
        .tiles = DecorGfx_PICHU_DOLL,
        .icon = {NULL, NULL},
    },

    [DECOR_PIKACHU_DOLL] =
    {
        .id = DECOR_PIKACHU_DOLL,
        .name = _("[Pikachu Doll]"),
        .permission = DECORPERM_SPRITE,
        .shape = DECORSHAPE_1x1,
        .category = DECORCAT_DOLL,
        .price = 3000,
        .description = COMPOUND_STRING(
            "A [Pikachu] doll.\n"
            "Place it on a mat\n"
            "or a desk."),
        .tiles = DecorGfx_PIKACHU_DOLL,
        .icon = {NULL, NULL},
    },

    [DECOR_MARILL_DOLL] =
    {
        .id = DECOR_MARILL_DOLL,
        .name = _("[Marill Doll]"),
        .permission = DECORPERM_SPRITE,
        .shape = DECORSHAPE_1x1,
        .category = DECORCAT_DOLL,
        .price = 3000,
        .description = COMPOUND_STRING(
            "A [Marill] doll.\n"
            "Place it on a mat\n"
            "or a desk."),
        .tiles = DecorGfx_MARILL_DOLL,
        .icon = {NULL, NULL},
    },

    [DECOR_TOGEPI_DOLL] =
    {
        .id = DECOR_TOGEPI_DOLL,
        .name = _("[Togepi Doll]"),
        .permission = DECORPERM_SPRITE,
        .shape = DECORSHAPE_1x1,
        .category = DECORCAT_DOLL,
        .price = 3000,
        .description = COMPOUND_STRING(
            "A [Togepi] doll.\n"
            "Place it on a mat\n"
            "or a desk."),
        .tiles = DecorGfx_TOGEPI_DOLL,
        .icon = {NULL, NULL},
    },

    [DECOR_CYNDAQUIL_DOLL] =
    {
        .id = DECOR_CYNDAQUIL_DOLL,
        .name = _("[Cyndaquil Doll]"),
        .permission = DECORPERM_SPRITE,
        .shape = DECORSHAPE_1x1,
        .category = DECORCAT_DOLL,
        .price = 3000,
        .description = COMPOUND_STRING(
            "A [Cyndaquil] doll.\n"
            "Place it on a mat\n"
            "or a desk."),
        .tiles = DecorGfx_CYNDAQUIL_DOLL,
        .icon = {NULL, NULL},
    },

    [DECOR_CHIKORITA_DOLL] =
    {
        .id = DECOR_CHIKORITA_DOLL,
        .name = _("[Chikorita Doll]"),
        .permission = DECORPERM_SPRITE,
        .shape = DECORSHAPE_1x1,
        .category = DECORCAT_DOLL,
        .price = 3000,
        .description = COMPOUND_STRING(
            "A [Chikorita] doll.\n"
            "Place it on a mat\n"
            "or a desk."),
        .tiles = DecorGfx_CHIKORITA_DOLL,
        .icon = {NULL, NULL},
    },

    [DECOR_TOTODILE_DOLL] =
    {
        .id = DECOR_TOTODILE_DOLL,
        .name = _("[Totodile Doll]"),
        .permission = DECORPERM_SPRITE,
        .shape = DECORSHAPE_1x1,
        .category = DECORCAT_DOLL,
        .price = 3000,
        .description = COMPOUND_STRING(
            "A [Totodile] doll.\n"
            "Place it on a mat\n"
            "or a desk."),
        .tiles = DecorGfx_TOTODILE_DOLL,
        .icon = {NULL, NULL},
    },

    [DECOR_JIGGLYPUFF_DOLL] =
    {
        .id = DECOR_JIGGLYPUFF_DOLL,
        .name = _("[Jigglypuff Doll]"),
        .permission = DECORPERM_SPRITE,
        .shape = DECORSHAPE_1x1,
        .category = DECORCAT_DOLL,
        .price = 3000,
        .description = COMPOUND_STRING(
            "A [Jigglypuff] doll.\n"
            "Place it on a mat\n"
            "or a desk."),
        .tiles = DecorGfx_JIGGLYPUFF_DOLL,
        .icon = {NULL, NULL},
    },

    [DECOR_MEOWTH_DOLL] =
    {
        .id = DECOR_MEOWTH_DOLL,
        .name = _("[Meowth Doll]"),
        .permission = DECORPERM_SPRITE,
        .shape = DECORSHAPE_1x1,
        .category = DECORCAT_DOLL,
        .price = 3000,
        .description = COMPOUND_STRING(
            "A [Meowth] doll.\n"
            "Place it on a mat\n"
            "or a desk."),
        .tiles = DecorGfx_MEOWTH_DOLL,
        .icon = {NULL, NULL},
    },

    [DECOR_CLEFAIRY_DOLL] =
    {
        .id = DECOR_CLEFAIRY_DOLL,
        .name = _("[Clefairy Doll]"),
        .permission = DECORPERM_SPRITE,
        .shape = DECORSHAPE_1x1,
        .category = DECORCAT_DOLL,
        .price = 3000,
        .description = COMPOUND_STRING(
            "A [Clefairy] doll.\n"
            "Place it on a mat\n"
            "or a desk."),
        .tiles = DecorGfx_CLEFAIRY_DOLL,
        .icon = {NULL, NULL},
    },

    [DECOR_DITTO_DOLL] =
    {
        .id = DECOR_DITTO_DOLL,
        .name = _("[Ditto Doll]"),
        .permission = DECORPERM_SPRITE,
        .shape = DECORSHAPE_1x1,
        .category = DECORCAT_DOLL,
        .price = 3000,
        .description = COMPOUND_STRING(
            "A [Ditto] doll.\n"
            "Place it on a mat\n"
            "or a desk."),
        .tiles = DecorGfx_DITTO_DOLL,
        .icon = {NULL, NULL},
    },

    [DECOR_SMOOCHUM_DOLL] =
    {
        .id = DECOR_SMOOCHUM_DOLL,
        .name = _("[Smoochum Doll]"),
        .permission = DECORPERM_SPRITE,
        .shape = DECORSHAPE_1x1,
        .category = DECORCAT_DOLL,
        .price = 3000,
        .description = COMPOUND_STRING(
            "A [Smoochum] doll.\n"
            "Place it on a mat\n"
            "or a desk."),
        .tiles = DecorGfx_SMOOCHUM_DOLL,
        .icon = {NULL, NULL},
    },

    [DECOR_TREECKO_DOLL] =
    {
        .id = DECOR_TREECKO_DOLL,
        .name = _("[Treecko Doll]"),
        .permission = DECORPERM_SPRITE,
        .shape = DECORSHAPE_1x1,
        .category = DECORCAT_DOLL,
        .price = 3000,
        .description = COMPOUND_STRING(
            "A [Treecko] doll.\n"
            "Place it on a mat\n"
            "or a desk."),
        .tiles = DecorGfx_TREECKO_DOLL,
        .icon = {NULL, NULL},
    },

    [DECOR_TORCHIC_DOLL] =
    {
        .id = DECOR_TORCHIC_DOLL,
        .name = _("[Torchic Doll]"),
        .permission = DECORPERM_SPRITE,
        .shape = DECORSHAPE_1x1,
        .category = DECORCAT_DOLL,
        .price = 3000,
        .description = COMPOUND_STRING(
            "A [Torchic] doll.\n"
            "Place it on a mat\n"
            "or a desk."),
        .tiles = DecorGfx_TORCHIC_DOLL,
        .icon = {NULL, NULL},
    },

    [DECOR_MUDKIP_DOLL] =
    {
        .id = DECOR_MUDKIP_DOLL,
        .name = _("[Mudkip Doll]"),
        .permission = DECORPERM_SPRITE,
        .shape = DECORSHAPE_1x1,
        .category = DECORCAT_DOLL,
        .price = 3000,
        .description = COMPOUND_STRING(
            "A [Mudkip] doll.\n"
            "Place it on a mat\n"
            "or a desk."),
        .tiles = DecorGfx_MUDKIP_DOLL,
        .icon = {NULL, NULL},
    },

    [DECOR_DUSKULL_DOLL] =
    {
        .id = DECOR_DUSKULL_DOLL,
        .name = _("[Duskull Doll]"),
        .permission = DECORPERM_SPRITE,
        .shape = DECORSHAPE_1x1,
        .category = DECORCAT_DOLL,
        .price = 3000,
        .description = COMPOUND_STRING(
            "A [Duskull] doll.\n"
            "Place it on a mat\n"
            "or a desk."),
        .tiles = DecorGfx_DUSKULL_DOLL,
        .icon = {NULL, NULL},
    },

    [DECOR_WYNAUT_DOLL] =
    {
        .id = DECOR_WYNAUT_DOLL,
        .name = _("[Wynaut Doll]"),
        .permission = DECORPERM_SPRITE,
        .shape = DECORSHAPE_1x1,
        .category = DECORCAT_DOLL,
        .price = 3000,
        .description = COMPOUND_STRING(
            "A [Wynaut] doll.\n"
            "Place it on a mat\n"
            "or a desk."),
        .tiles = DecorGfx_WYNAUT_DOLL,
        .icon = {NULL, NULL},
    },

    [DECOR_BALTOY_DOLL] =
    {
        .id = DECOR_BALTOY_DOLL,
        .name = _("[Baltoy Doll]"),
        .permission = DECORPERM_SPRITE,
        .shape = DECORSHAPE_1x1,
        .category = DECORCAT_DOLL,
        .price = 3000,
        .description = COMPOUND_STRING(
            "A [Baltoy] doll.\n"
            "Place it on a mat\n"
            "or a desk."),
        .tiles = DecorGfx_BALTOY_DOLL,
        .icon = {NULL, NULL},
    },

    [DECOR_KECLEON_DOLL] =
    {
        .id = DECOR_KECLEON_DOLL,
        .name = _("[Kecleon Doll]"),
        .permission = DECORPERM_SPRITE,
        .shape = DECORSHAPE_1x1,
        .category = DECORCAT_DOLL,
        .price = 3000,
        .description = COMPOUND_STRING(
            "A [Kecleon] doll.\n"
            "Place it on a mat\n"
            "or a desk."),
        .tiles = DecorGfx_KECLEON_DOLL,
        .icon = {NULL, NULL},
    },

    [DECOR_AZURILL_DOLL] =
    {
        .id = DECOR_AZURILL_DOLL,
        .name = _("[Azurill Doll]"),
        .permission = DECORPERM_SPRITE,
        .shape = DECORSHAPE_1x1,
        .category = DECORCAT_DOLL,
        .price = 3000,
        .description = COMPOUND_STRING(
            "An [Azurill] doll.\n"
            "Place it on a mat\n"
            "or a desk."),
        .tiles = DecorGfx_AZURILL_DOLL,
        .icon = {NULL, NULL},
    },

    [DECOR_SKITTY_DOLL] =
    {
        .id = DECOR_SKITTY_DOLL,
        .name = _("[Skitty Doll]"),
        .permission = DECORPERM_SPRITE,
        .shape = DECORSHAPE_1x1,
        .category = DECORCAT_DOLL,
        .price = 3000,
        .description = COMPOUND_STRING(
            "A [Skitty] doll.\n"
            "Place it on a mat\n"
            "or a desk."),
        .tiles = DecorGfx_SKITTY_DOLL,
        .icon = {NULL, NULL},
    },

    [DECOR_SWABLU_DOLL] =
    {
        .id = DECOR_SWABLU_DOLL,
        .name = _("[Swablu Doll]"),
        .permission = DECORPERM_SPRITE,
        .shape = DECORSHAPE_1x1,
        .category = DECORCAT_DOLL,
        .price = 3000,
        .description = COMPOUND_STRING(
            "A [Swablu] doll.\n"
            "Place it on a mat\n"
            "or a desk."),
        .tiles = DecorGfx_SWABLU_DOLL,
        .icon = {NULL, NULL},
    },

    [DECOR_GULPIN_DOLL] =
    {
        .id = DECOR_GULPIN_DOLL,
        .name = _("[Gulpin Doll]"),
        .permission = DECORPERM_SPRITE,
        .shape = DECORSHAPE_1x1,
        .category = DECORCAT_DOLL,
        .price = 3000,
        .description = COMPOUND_STRING(
            "A [Gulpin] doll.\n"
            "Place it on a mat\n"
            "or a desk."),
        .tiles = DecorGfx_GULPIN_DOLL,
        .icon = {NULL, NULL},
    },

    [DECOR_LOTAD_DOLL] =
    {
        .id = DECOR_LOTAD_DOLL,
        .name = _("[Lotad Doll]"),
        .permission = DECORPERM_SPRITE,
        .shape = DECORSHAPE_1x1,
        .category = DECORCAT_DOLL,
        .price = 3000,
        .description = COMPOUND_STRING(
            "A [Lotad] doll.\n"
            "Place it on a mat\n"
            "or a desk."),
        .tiles = DecorGfx_LOTAD_DOLL,
        .icon = {NULL, NULL},
    },

    [DECOR_SEEDOT_DOLL] =
    {
        .id = DECOR_SEEDOT_DOLL,
        .name = _("[Seedot Doll]"),
        .permission = DECORPERM_SPRITE,
        .shape = DECORSHAPE_1x1,
        .category = DECORCAT_DOLL,
        .price = 3000,
        .description = COMPOUND_STRING(
            "A [Seedot] doll.\n"
            "Place it on a mat\n"
            "or a desk."),
        .tiles = DecorGfx_SEEDOT_DOLL,
        .icon = {NULL, NULL},
    },

    [DECOR_PIKA_CUSHION] =
    {
        .id = DECOR_PIKA_CUSHION,
        .name = _("[Pika Cushion]"),
        .permission = DECORPERM_SPRITE,
        .shape = DECORSHAPE_1x1,
        .category = DECORCAT_CUSHION,
        .price = 2000,
        .description = COMPOUND_STRING(
            "A [Pikachu] cushion.\n"
            "Place it on a mat\n"
            "or a desk."),
        .tiles = DecorGfx_PIKA_CUSHION,
        .icon = {NULL, NULL},
    },

    [DECOR_ROUND_CUSHION] =
    {
        .id = DECOR_ROUND_CUSHION,
        .name = _("[Round Cushion]"),
        .permission = DECORPERM_SPRITE,
        .shape = DECORSHAPE_1x1,
        .category = DECORCAT_CUSHION,
        .price = 2000,
        .description = COMPOUND_STRING(
            "A [Marill] cushion.\n"
            "Place it on a mat\n"
            "or a desk."),
        .tiles = DecorGfx_ROUND_CUSHION,
        .icon = {NULL, NULL},
    },

    [DECOR_KISS_CUSHION] =
    {
        .id = DECOR_KISS_CUSHION,
        .name = _("[Kiss Cushion]"),
        .permission = DECORPERM_SPRITE,
        .shape = DECORSHAPE_1x1,
        .category = DECORCAT_CUSHION,
        .price = 2000,
        .description = COMPOUND_STRING(
            "A [Smoochum]\n"
            "cushion. Place it on\n"
            "a mat or a desk."),
        .tiles = DecorGfx_KISS_CUSHION,
        .icon = {NULL, NULL},
    },

    [DECOR_ZIGZAG_CUSHION] =
    {
        .id = DECOR_ZIGZAG_CUSHION,
        .name = _("[Zigzag Cushion]"),
        .permission = DECORPERM_SPRITE,
        .shape = DECORSHAPE_1x1,
        .category = DECORCAT_CUSHION,
        .price = 2000,
        .description = COMPOUND_STRING(
            "A [Zigzagoon]\n"
            "cushion. Place it on\n"
            "a mat or a desk."),
        .tiles = DecorGfx_ZIGZAG_CUSHION,
        .icon = {NULL, NULL},
    },

    [DECOR_SPIN_CUSHION] =
    {
        .id = DECOR_SPIN_CUSHION,
        .name = _("[Spin Cushion]"),
        .permission = DECORPERM_SPRITE,
        .shape = DECORSHAPE_1x1,
        .category = DECORCAT_CUSHION,
        .price = 2000,
        .description = COMPOUND_STRING(
            "A [Spinda] cushion.\n"
            "Place it on a mat\n"
            "or a desk."),
        .tiles = DecorGfx_SPIN_CUSHION,
        .icon = {NULL, NULL},
    },

    [DECOR_DIAMOND_CUSHION] =
    {
        .id = DECOR_DIAMOND_CUSHION,
        .name = _("[Diamond Cushion]"),
        .permission = DECORPERM_SPRITE,
        .shape = DECORSHAPE_1x1,
        .category = DECORCAT_CUSHION,
        .price = 2000,
        .description = COMPOUND_STRING(
            "A [Sableye] cushion.\n"
            "Place it on a mat\n"
            "or a desk."),
        .tiles = DecorGfx_DIAMOND_CUSHION,
        .icon = {NULL, NULL},
    },

    [DECOR_BALL_CUSHION] =
    {
        .id = DECOR_BALL_CUSHION,
        .name = _("[Ball Cushion]"),
        .permission = DECORPERM_SPRITE,
        .shape = DECORSHAPE_1x1,
        .category = DECORCAT_CUSHION,
        .price = 2000,
        .description = COMPOUND_STRING(
            "A [Ball] cushion.\n"
            "Place it on a mat\n"
            "or a desk."),
        .tiles = DecorGfx_BALL_CUSHION,
        .icon = {NULL, NULL},
    },

    [DECOR_GRASS_CUSHION] =
    {
        .id = DECOR_GRASS_CUSHION,
        .name = _("[Grass Cushion]"),
        .permission = DECORPERM_SPRITE,
        .shape = DECORSHAPE_1x1,
        .category = DECORCAT_CUSHION,
        .price = 2000,
        .description = COMPOUND_STRING(
            "A grass-mark\n"
            "cushion. Place it on\n"
            "a mat or a desk."),
        .tiles = DecorGfx_GRASS_CUSHION,
        .icon = {NULL, NULL},
    },

    [DECOR_FIRE_CUSHION] =
    {
        .id = DECOR_FIRE_CUSHION,
        .name = _("[Fire Cushion]"),
        .permission = DECORPERM_SPRITE,
        .shape = DECORSHAPE_1x1,
        .category = DECORCAT_CUSHION,
        .price = 2000,
        .description = COMPOUND_STRING(
            "A fire-mark\n"
            "cushion. Place it on\n"
            "a mat or a desk."),
        .tiles = DecorGfx_FIRE_CUSHION,
        .icon = {NULL, NULL},
    },

    [DECOR_WATER_CUSHION] =
    {
        .id = DECOR_WATER_CUSHION,
        .name = _("[Water Cushion]"),
        .permission = DECORPERM_SPRITE,
        .shape = DECORSHAPE_1x1,
        .category = DECORCAT_CUSHION,
        .price = 2000,
        .description = COMPOUND_STRING(
            "A water-mark\n"
            "cushion. Place it on\n"
            "a mat or a desk."),
        .tiles = DecorGfx_WATER_CUSHION,
        .icon = {NULL, NULL},
    },

    [DECOR_SNORLAX_DOLL] =
    {
        .id = DECOR_SNORLAX_DOLL,
        .name = _("[Snorlax Doll]"),
        .permission = DECORPERM_SPRITE,
        .shape = DECORSHAPE_1x2,
        .category = DECORCAT_DOLL,
        .price = 10000,
        .description = COMPOUND_STRING(
            "A large doll.\n"
            "Place it on a mat\n"
            "or a desk."),
        .tiles = DecorGfx_SNORLAX_DOLL,
        .icon = {gDecorIcon_SnorlaxDoll, gDecorIconPalette_SnorlaxDoll},
    },

    [DECOR_RHYDON_DOLL] =
    {
        .id = DECOR_RHYDON_DOLL,
        .name = _("[Rhydon Doll]"),
        .permission = DECORPERM_SPRITE,
        .shape = DECORSHAPE_1x2,
        .category = DECORCAT_DOLL,
        .price = 10000,
        .description = COMPOUND_STRING(
            "A large doll.\n"
            "Place it on a mat\n"
            "or a desk."),
        .tiles = DecorGfx_RHYDON_DOLL,
        .icon = {gDecorIcon_RhydonDoll, gDecorIconPalette_RhydonDoll},
    },

    [DECOR_LAPRAS_DOLL] =
    {
        .id = DECOR_LAPRAS_DOLL,
        .name = _("[Lapras Doll]"),
        .permission = DECORPERM_SPRITE,
        .shape = DECORSHAPE_1x2,
        .category = DECORCAT_DOLL,
        .price = 10000,
        .description = COMPOUND_STRING(
            "A large doll.\n"
            "Place it on a mat\n"
            "or a desk."),
        .tiles = DecorGfx_LAPRAS_DOLL,
        .icon = {gDecorIcon_LaprasDoll, gDecorIconPalette_LaprasDoll},
    },

    [DECOR_VENUSAUR_DOLL] =
    {
        .id = DECOR_VENUSAUR_DOLL,
        .name = _("[Venusaur Doll]"),
        .permission = DECORPERM_SPRITE,
        .shape = DECORSHAPE_1x2,
        .category = DECORCAT_DOLL,
        .price = 10000,
        .description = COMPOUND_STRING(
            "A large doll.\n"
            "Place it on a mat\n"
            "or a desk."),
        .tiles = DecorGfx_VENUSAUR_DOLL,
        .icon = {gDecorIcon_VenusaurDoll, gDecorIconPalette_VenusaurDoll},
    },

    [DECOR_CHARIZARD_DOLL] =
    {
        .id = DECOR_CHARIZARD_DOLL,
        .name = _("[Charizard Doll]"),
        .permission = DECORPERM_SPRITE,
        .shape = DECORSHAPE_1x2,
        .category = DECORCAT_DOLL,
        .price = 10000,
        .description = COMPOUND_STRING(
            "A large doll.\n"
            "Place it on a mat\n"
            "or a desk."),
        .tiles = DecorGfx_CHARIZARD_DOLL,
        .icon = {gDecorIcon_CharizardDoll, gDecorIconPalette_CharizardDoll},
    },

    [DECOR_BLASTOISE_DOLL] =
    {
        .id = DECOR_BLASTOISE_DOLL,
        .name = _("[Blastoise Doll]"),
        .permission = DECORPERM_SPRITE,
        .shape = DECORSHAPE_1x2,
        .category = DECORCAT_DOLL,
        .price = 10000,
        .description = COMPOUND_STRING(
            "A large doll.\n"
            "Place it on a mat\n"
            "or a desk."),
        .tiles = DecorGfx_BLASTOISE_DOLL,
        .icon = {gDecorIcon_BlastoiseDoll, gDecorIconPalette_BlastoiseDoll},
    },

    [DECOR_WAILMER_DOLL] =
    {
        .id = DECOR_WAILMER_DOLL,
        .name = _("[Wailmer Doll]"),
        .permission = DECORPERM_SPRITE,
        .shape = DECORSHAPE_1x2,
        .category = DECORCAT_DOLL,
        .price = 10000,
        .description = COMPOUND_STRING(
            "A large doll.\n"
            "Place it on a mat\n"
            "or a desk."),
        .tiles = DecorGfx_WAILMER_DOLL,
        .icon = {gDecorIcon_WailmerDoll, gDecorIconPalette_WailmerDoll},
    },

    [DECOR_REGIROCK_DOLL] =
    {
        .id = DECOR_REGIROCK_DOLL,
        .name = _("[Regirock Doll]"),
        .permission = DECORPERM_SPRITE,
        .shape = DECORSHAPE_1x2,
        .category = DECORCAT_DOLL,
        .price = 10000,
        .description = COMPOUND_STRING(
            "A large doll.\n"
            "Place it on a mat\n"
            "or a desk."),
        .tiles = DecorGfx_REGIROCK_DOLL,
        .icon = {gDecorIcon_RegirockDoll, gDecorIconPalette_RegirockDoll},
    },

    [DECOR_REGICE_DOLL] =
    {
        .id = DECOR_REGICE_DOLL,
        .name = _("[Regice Doll]"),
        .permission = DECORPERM_SPRITE,
        .shape = DECORSHAPE_1x2,
        .category = DECORCAT_DOLL,
        .price = 10000,
        .description = COMPOUND_STRING(
            "A large doll.\n"
            "Place it on a mat\n"
            "or a desk."),
        .tiles = DecorGfx_REGICE_DOLL,
        .icon = {gDecorIcon_RegiceDoll, gDecorIconPalette_RegiceDoll},
    },

    [DECOR_REGISTEEL_DOLL] =
    {
        .id = DECOR_REGISTEEL_DOLL,
        .name = _("[Registeel Doll]"),
        .permission = DECORPERM_SPRITE,
        .shape = DECORSHAPE_1x2,
        .category = DECORCAT_DOLL,
        .price = 10000,
        .description = COMPOUND_STRING(
            "A large doll.\n"
            "Place it on a mat\n"
            "or a desk."),
        .tiles = DecorGfx_REGISTEEL_DOLL,
        .icon = {gDecorIcon_RegisteelDoll, gDecorIconPalette_RegisteelDoll},
    }
};
