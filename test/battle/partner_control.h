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
#line 17
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
#line 19
            .species = SPECIES_METANG,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 23
            .ev = TRAINER_PARTY_EVS(0, 252, 252, 0, 6, 0),
#line 22
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 21
            .lvl = 42,
            .ball = POKEBALL_COUNT,
#line 20
            .nature = NATURE_BRAVE,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 24
                MOVE_LIGHT_SCREEN,
                MOVE_PSYCHIC,
                MOVE_REFLECT,
                MOVE_METAL_CLAW,
            },
            },
            {
#line 29
            .species = SPECIES_SKARMORY,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 33
            .ev = TRAINER_PARTY_EVS(252, 0, 0, 0, 6, 252),
#line 32
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 31
            .lvl = 43,
            .ball = POKEBALL_COUNT,
#line 30
            .nature = NATURE_IMPISH,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 34
                MOVE_TOXIC,
                MOVE_AERIAL_ACE,
                MOVE_PROTECT,
                MOVE_STEEL_WING,
            },
            },
            {
#line 39
            .species = SPECIES_AGGRON,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 43
            .ev = TRAINER_PARTY_EVS(0, 252, 0, 0, 252, 6),
#line 42
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 41
            .lvl = 44,
            .ball = POKEBALL_COUNT,
#line 40
            .nature = NATURE_ADAMANT,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 44
                MOVE_THUNDER,
                MOVE_PROTECT,
                MOVE_SOLAR_BEAM,
                MOVE_DRAGON_CLAW,
            },
            },
        },
    },
#line 49
#line 57
    [DIFFICULTY_EASY][PARTNER_STEVEN_TEST] =
    {
#line 50
        .trainerName = _("Test2"),
#line 51
        .trainerClass = TRAINER_CLASS_RIVAL,
#line 52
        .trainerPic = TRAINER_PIC_FRONT_STEVEN,
#line 53
        .gender = TRAINER_GENDER_MALE,
#line 54
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_MALE,
#line 56
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 55
        .trainerBackPic = TRAINER_PIC_BACK_STEVEN,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 59
            .species = SPECIES_METAPOD,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 61
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 60
            .lvl = 1,
            .ball = POKEBALL_COUNT,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 62
#line 70
    [DIFFICULTY_HARD][PARTNER_STEVEN_TEST] =
    {
#line 63
        .trainerName = _("Test2"),
#line 64
        .trainerClass = TRAINER_CLASS_RIVAL,
#line 65
        .trainerPic = TRAINER_PIC_FRONT_STEVEN,
#line 66
        .gender = TRAINER_GENDER_MALE,
#line 67
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_MALE,
#line 69
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 68
        .trainerBackPic = TRAINER_PIC_BACK_STEVEN,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 72
            .species = SPECIES_ARCEUS,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 74
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 73
            .lvl = 99,
            .ball = POKEBALL_COUNT,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
