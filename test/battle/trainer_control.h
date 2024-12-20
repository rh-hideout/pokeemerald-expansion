//
// DO NOT MODIFY THIS FILE! It is auto-generated from test/battle/trainer_control.party
//
// If you want to modify this file set COMPETITIVE_PARTY_SYNTAX to FALSE
// in include/config/general.h and remove this notice.
// Use sed -i '/^#line/d' 'test/battle/trainer_control.h' to remove #line markers.
//

#line 1 "test/battle/trainer_control.party"

#line 1
    [DIFFICULTY_NORMAL][0] =
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
#line 40
    [DIFFICULTY_NORMAL][1] =
    {
#line 34
        .trainerName = _("Test2"),
#line 35
        .trainerClass = TRAINER_CLASS_PKMN_TRAINER_1,
#line 36
        .trainerPic = TRAINER_PIC_RED,
        .encounterMusic_gender = 
#line 38
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 39
        .doubleBattle = FALSE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 42
            .species = SPECIES_MEWTWO,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 44
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 43
            .lvl = 5,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 45
#line 52
    [DIFFICULTY_HARD][1] =
    {
#line 46
        .trainerName = _("Test2"),
#line 47
        .trainerClass = TRAINER_CLASS_PKMN_TRAINER_1,
#line 48
        .trainerPic = TRAINER_PIC_RED,
        .encounterMusic_gender = 
#line 50
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 51
        .doubleBattle = FALSE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 54
            .species = SPECIES_YVELTAL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 56
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 55
            .lvl = 99,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 57
#line 64
    [DIFFICULTY_NORMAL][2] =
    {
#line 58
        .trainerName = _("Test2"),
#line 59
        .trainerClass = TRAINER_CLASS_PKMN_TRAINER_1,
#line 60
        .trainerPic = TRAINER_PIC_RED,
        .encounterMusic_gender = 
#line 62
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 63
        .doubleBattle = FALSE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 66
            .species = SPECIES_MEWTWO,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 68
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 67
            .lvl = 50,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 69
#line 76
    [DIFFICULTY_EASY][2] =
    {
#line 70
        .trainerName = _("Test2"),
#line 71
        .trainerClass = TRAINER_CLASS_PKMN_TRAINER_1,
#line 72
        .trainerPic = TRAINER_PIC_RED,
        .encounterMusic_gender = 
#line 74
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 75
        .doubleBattle = FALSE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 78
            .species = SPECIES_METAPOD,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 80
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 79
            .lvl = 1,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 81
#line 88
    [DIFFICULTY_HARD][2] =
    {
#line 82
        .trainerName = _("Test2"),
#line 83
        .trainerClass = TRAINER_CLASS_PKMN_TRAINER_1,
#line 84
        .trainerPic = TRAINER_PIC_RED,
        .encounterMusic_gender = 
#line 86
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 87
        .doubleBattle = FALSE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 90
            .species = SPECIES_ARCEUS,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 92
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 91
            .lvl = 99,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
