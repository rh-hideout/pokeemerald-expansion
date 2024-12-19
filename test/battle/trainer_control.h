//
// DO NOT MODIFY THIS FILE! It is auto-generated from test/battle/trainer_control.party
//
// If you want to modify this file set COMPETITIVE_PARTY_SYNTAX to FALSE
// in include/config/general.h and remove this notice.
// Use sed -i '/^#line/d' 'test/battle/trainer_control.h' to remove #line markers.
//

#line 1 "test/battle/trainer_control.party"

#line 1
    [0] =
    {
#line 2
        .trainerName = _("Test1"),
#line 3
        .trainerClass = TRAINER_CLASS_PKMN_TRAINER_1,
#line 4
        .trainerPic = TRAINER_PIC_RED,
        .encounterMusic_gender = 
#line 6
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 7
        .doubleBattle = FALSE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 9
            .nickname = COMPOUND_STRING("Bubbles"),
#line 9
            .species = SPECIES_WOBBUFFET,
#line 9
            .gender = TRAINER_MON_FEMALE,
#line 9
            .heldItem = ITEM_ASSAULT_VEST,
#line 14
            .ev = TRAINER_PARTY_EVS(252, 0, 0, 252, 4, 0),
#line 13
            .iv = TRAINER_PARTY_IVS(25, 26, 27, 28, 29, 30),
#line 12
            .ability = ABILITY_TELEPATHY,
#line 11
            .lvl = 67,
#line 17
            .ball = ITEM_MASTER_BALL,
#line 15
            .friendship = 42,
#line 10
            .nature = NATURE_HASTY,
#line 16
            .isShiny = TRUE,
#line 18
            .dynamaxLevel = 5,
            .shouldUseDynamax = TRUE,
            .moves = {
#line 19
                MOVE_AIR_SLASH,
                MOVE_BARRIER,
                MOVE_SOLAR_BEAM,
                MOVE_EXPLOSION,
            },
            },
            {
#line 24
            .species = SPECIES_WOBBUFFET,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 27
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 26
            .ability = ABILITY_SHADOW_TAG,
#line 25
            .lvl = 5,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 29
            .species = SPECIES_WYNAUT,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 31
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 30
            .lvl = 5,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 33
    [1] =
    {
#line 34
        .trainerName = _("Test1"),
#line 35
        .trainerClass = TRAINER_CLASS_PKMN_TRAINER_1,
#line 36
        .trainerPic = TRAINER_PIC_RED,
        .encounterMusic_gender = 
#line 38
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 39
        .doubleBattle = FALSE,
#line 40
        .partySize = 1,
        .poolSize = 4,
        .party = (const struct TrainerMon[])
        {
            {
#line 42
            .species = SPECIES_WYNAUT,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 43
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 43
            .lvl = 100,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 44
            .species = SPECIES_WOBBUFFET,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 45
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 45
            .lvl = 100,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 46
            .species = SPECIES_EEVEE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 47
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 47
            .lvl = 100,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 48
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 49
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 49
            .lvl = 100,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 50
    [2] =
    {
#line 51
        .trainerName = _("Test1"),
#line 52
        .trainerClass = TRAINER_CLASS_PKMN_TRAINER_1,
#line 53
        .trainerPic = TRAINER_PIC_RED,
        .encounterMusic_gender = 
#line 55
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 56
        .doubleBattle = FALSE,
#line 57
        .partySize = 3,
        .poolSize = 6,
        .party = (const struct TrainerMon[])
        {
            {
#line 59
            .species = SPECIES_WYNAUT,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 60
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 60
            .lvl = 100,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 61
            .species = SPECIES_WOBBUFFET,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 63
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 63
            .lvl = 100,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
#line 62
            .tags = MON_POOL_TAG_LEAD,
            },
            {
#line 64
            .species = SPECIES_EEVEE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 66
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 66
            .lvl = 100,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
#line 65
            .tags = MON_POOL_TAG_ACE,
            },
            {
#line 67
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 68
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 68
            .lvl = 100,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 69
            .species = SPECIES_ODDISH,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 71
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 71
            .lvl = 100,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
#line 70
            .tags = MON_POOL_TAG_ACE,
            },
            {
#line 72
            .species = SPECIES_ARON,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 74
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 74
            .lvl = 100,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
#line 73
            .tags = MON_POOL_TAG_LEAD,
            },
        },
    },
#line 75
    [3] =
    {
#line 76
        .trainerName = _("Test1"),
#line 77
        .trainerClass = TRAINER_CLASS_PKMN_TRAINER_1,
#line 78
        .trainerPic = TRAINER_PIC_RED,
        .encounterMusic_gender = 
#line 80
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 81
        .doubleBattle = TRUE,
#line 83
        .poolRuleIndex = POOL_RULESET_WEATHER_DOUBLES,
#line 82
        .partySize = 3,
        .poolSize = 10,
        .party = (const struct TrainerMon[])
        {
            {
#line 85
            .species = SPECIES_WYNAUT,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 87
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 87
            .lvl = 100,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
#line 86
            .tags = MON_POOL_TAG_LEAD,
            },
            {
#line 88
            .species = SPECIES_WOBBUFFET,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 90
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 90
            .lvl = 100,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
#line 89
            .tags = MON_POOL_TAG_LEAD,
            },
            {
#line 91
            .species = SPECIES_VULPIX,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 93
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 93
            .lvl = 100,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
#line 92
            .tags = MON_POOL_TAG_LEAD | MON_POOL_TAG_WEATHER_SETTER,
            },
            {
#line 94
            .species = SPECIES_BULBASAUR,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 96
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 96
            .lvl = 100,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
#line 95
            .tags = MON_POOL_TAG_LEAD | MON_POOL_TAG_WEATHER_ABUSER,
            },
            {
#line 97
            .species = SPECIES_TORKOAL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 99
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 99
            .lvl = 100,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
#line 98
            .tags = MON_POOL_TAG_LEAD | MON_POOL_TAG_WEATHER_SETTER,
            },
            {
#line 100
            .species = SPECIES_CHERRIM,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 102
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 102
            .lvl = 100,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
#line 101
            .tags = MON_POOL_TAG_LEAD | MON_POOL_TAG_WEATHER_ABUSER,
            },
            {
#line 103
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 105
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 105
            .lvl = 100,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
#line 104
            .tags = MON_POOL_TAG_LEAD,
            },
            {
#line 106
            .species = SPECIES_ARON,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 108
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 108
            .lvl = 100,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
#line 107
            .tags = MON_POOL_TAG_LEAD,
            },
            {
#line 109
            .species = SPECIES_ODDISH,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 110
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 110
            .lvl = 100,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 111
            .species = SPECIES_EEVEE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 112
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 112
            .lvl = 100,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
