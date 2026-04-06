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
        .trainerPic = TRAINER_PIC_BRENDAN,
#line 5
        .gender = TRAINER_GENDER_MALE,
#line 6
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_MALE,
        .partySize = 0,
        .party = (const struct TrainerMon[])
        {
        },
    },
#line 8
#line 15
    [DIFFICULTY_NORMAL][PARTNER_STEVEN_TEST] =
    {
#line 9
        .trainerName = _("STEVEN"),
#line 10
        .trainerClass = TRAINER_CLASS_RIVAL,
#line 11
        .trainerPic = TRAINER_PIC_STEVEN,
#line 12
        .gender = TRAINER_GENDER_MALE,
#line 13
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_MALE,
#line 14
        .aiFlags = AI_FLAG_BASIC_TRAINER,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 17
            .species = SPECIES_METANG,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 21
            .ev = TRAINER_PARTY_EVS(0, 252, 252, 0, 6, 0),
#line 20
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 19
            .lvl = 42,
            .ball = POKEBALL_COUNT,
#line 18
            .nature = NATURE_BRAVE,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 22
                MOVE_LIGHT_SCREEN,
                MOVE_PSYCHIC,
                MOVE_REFLECT,
                MOVE_METAL_CLAW,
            },
            },
            {
#line 27
            .species = SPECIES_SKARMORY,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 31
            .ev = TRAINER_PARTY_EVS(252, 0, 0, 0, 6, 252),
#line 30
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 29
            .lvl = 43,
            .ball = POKEBALL_COUNT,
#line 28
            .nature = NATURE_IMPISH,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 32
                MOVE_TOXIC,
                MOVE_AERIAL_ACE,
                MOVE_PROTECT,
                MOVE_STEEL_WING,
            },
            },
            {
#line 37
            .species = SPECIES_AGGRON,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 41
            .ev = TRAINER_PARTY_EVS(0, 252, 0, 0, 252, 6),
#line 40
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 39
            .lvl = 44,
            .ball = POKEBALL_COUNT,
#line 38
            .nature = NATURE_ADAMANT,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 42
                MOVE_THUNDER,
                MOVE_PROTECT,
                MOVE_SOLAR_BEAM,
                MOVE_DRAGON_CLAW,
            },
            },
        },
    },
#line 47
#line 54
    [DIFFICULTY_EASY][PARTNER_STEVEN_TEST] =
    {
#line 48
        .trainerName = _("Test2"),
#line 49
        .trainerClass = TRAINER_CLASS_RIVAL,
#line 50
        .trainerPic = TRAINER_PIC_STEVEN,
#line 51
        .gender = TRAINER_GENDER_MALE,
#line 52
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_MALE,
#line 53
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 56
            .species = SPECIES_METAPOD,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 58
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 57
            .lvl = 1,
            .ball = POKEBALL_COUNT,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 59
#line 66
    [DIFFICULTY_HARD][PARTNER_STEVEN_TEST] =
    {
#line 60
        .trainerName = _("Test2"),
#line 61
        .trainerClass = TRAINER_CLASS_RIVAL,
#line 62
        .trainerPic = TRAINER_PIC_STEVEN,
#line 63
        .gender = TRAINER_GENDER_MALE,
#line 64
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_MALE,
#line 65
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 68
            .species = SPECIES_ARCEUS,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 70
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 69
            .lvl = 99,
            .ball = POKEBALL_COUNT,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
