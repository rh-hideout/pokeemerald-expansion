//
// DO NOT MODIFY THIS FILE! It is auto-generated from test/battle/partner_control.party
//
// If you want to modify this file see expansion PR #7154
//

#line 1 "test/battle/partner_control.party"

#line 1
    [DIFFICULTY_NORMAL][PARTNER_NONE] =
    {
#line 3
        .trainerClass = TRAINER_CLASS_PKMN_TRAINER_1,
#line 4
        .trainerPic = TRAINER_PIC_FRONT_BRENDAN,
#line 5
        .gender = TRAINER_GENDER_MALE,
#line 6
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_MALE,
#line 7
        .trainerBackPic = TRAINER_PIC_BACK_BRENDAN,
        .partySize = 0,
        .party = (const struct TrainerMon[])
        {
        },
    },
#line 9
    [DIFFICULTY_NORMAL][PARTNER_STEVEN_TEST] =
    {
#line 10
        .trainerName = _("STEVEN"),
#line 11
        .trainerClass = TRAINER_CLASS_RIVAL,
#line 12
        .trainerPic = TRAINER_PIC_FRONT_STEVEN,
#line 13
        .gender = TRAINER_GENDER_MALE,
#line 14
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_MALE,
#line 16
        .aiFlags = AI_FLAG_BASIC_TRAINER,
#line 15
        .trainerBackPic = TRAINER_PIC_BACK_STEVEN,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 18
            .species = SPECIES_METANG,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 22
            .ev = TRAINER_PARTY_EVS(0, 252, 252, 0, 6, 0),
#line 21
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 20
            .lvl = 42,
            .ball = POKEBALL_COUNT,
#line 19
            .nature = NATURE_BRAVE,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 23
                MOVE_LIGHT_SCREEN,
                MOVE_PSYCHIC,
                MOVE_REFLECT,
                MOVE_METAL_CLAW,
            },
            },
            {
#line 28
            .species = SPECIES_SKARMORY,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 32
            .ev = TRAINER_PARTY_EVS(252, 0, 0, 0, 6, 252),
#line 31
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 30
            .lvl = 43,
            .ball = POKEBALL_COUNT,
#line 29
            .nature = NATURE_IMPISH,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 33
                MOVE_TOXIC,
                MOVE_AERIAL_ACE,
                MOVE_PROTECT,
                MOVE_STEEL_WING,
            },
            },
            {
#line 38
            .species = SPECIES_AGGRON,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 42
            .ev = TRAINER_PARTY_EVS(0, 252, 0, 0, 252, 6),
#line 41
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 40
            .lvl = 44,
            .ball = POKEBALL_COUNT,
#line 39
            .nature = NATURE_ADAMANT,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 43
                MOVE_THUNDER,
                MOVE_PROTECT,
                MOVE_SOLAR_BEAM,
                MOVE_DRAGON_CLAW,
            },
            },
        },
    },
#line 48
#line 55
    [DIFFICULTY_NORMAL][2] =
    {
#line 49
        .trainerName = _("Test2"),
#line 50
        .trainerClass = TRAINER_CLASS_RIVAL,
#line 51
        .trainerPic = TRAINER_PIC_FRONT_STEVEN,
#line 52
        .gender = TRAINER_GENDER_MALE,
#line 53
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_MALE,
#line 54
        .trainerBackPic = TRAINER_PIC_BACK_STEVEN,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 57
            .species = SPECIES_MEWTWO,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 59
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 58
            .lvl = 50,
            .ball = POKEBALL_COUNT,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 60
#line 68
    [DIFFICULTY_EASY][2] =
    {
#line 61
        .trainerName = _("Test2"),
#line 62
        .trainerClass = TRAINER_CLASS_RIVAL,
#line 63
        .trainerPic = TRAINER_PIC_FRONT_STEVEN,
#line 64
        .gender = TRAINER_GENDER_MALE,
#line 65
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_MALE,
#line 67
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 66
        .trainerBackPic = TRAINER_PIC_BACK_STEVEN,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 70
            .species = SPECIES_METAPOD,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 72
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 71
            .lvl = 1,
            .ball = POKEBALL_COUNT,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 73
#line 81
    [DIFFICULTY_HARD][2] =
    {
#line 74
        .trainerName = _("Test2"),
#line 75
        .trainerClass = TRAINER_CLASS_RIVAL,
#line 76
        .trainerPic = TRAINER_PIC_FRONT_STEVEN,
#line 77
        .gender = TRAINER_GENDER_MALE,
#line 78
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_MALE,
#line 80
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 79
        .trainerBackPic = TRAINER_PIC_BACK_STEVEN,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 83
            .species = SPECIES_ARCEUS,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 85
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 84
            .lvl = 99,
            .ball = POKEBALL_COUNT,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
