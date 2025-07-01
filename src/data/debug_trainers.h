//
// DO NOT MODIFY THIS FILE! It is auto-generated from src/data/debug_trainers.party
//
// If you want to modify this file set COMPETITIVE_PARTY_SYNTAX to FALSE
// in include/config/general.h and remove this notice.
// Use sed -i '/^#line/d' 'src/data/debug_trainers.h' to remove #line markers.
//

#line 1 "src/data/debug_trainers.party"

#line 14
    [DIFFICULTY_NORMAL][DEBUG_TRAINER_PLAYER] =
    {
#line 15
        .trainerName = _("Player"),
#line 16
        .trainerClass = TRAINER_CLASS_PKMN_TRAINER_1,
#line 17
        .trainerPic = TRAINER_PIC_BRENDAN,
        .encounterMusic_gender =
#line 19
            TRAINER_ENCOUNTER_MUSIC_MALE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 21
            .nickname = COMPOUND_STRING("Buffie"),
#line 21
            .species = SPECIES_WOBBUFFET,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 25
            .ev = TRAINER_PARTY_EVS(0, 252, 252, 0, 6, 0),
#line 24
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 23
            .lvl = 100,
#line 22
            .nature = NATURE_BRAVE,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 26
                MOVE_EARTHQUAKE,
                MOVE_FLAMETHROWER,
                MOVE_CELEBRATE,
                MOVE_CELEBRATE,
            },
            },
        },
    },
#line 31
    [DIFFICULTY_NORMAL][DEBUG_TRAINER_AI] =
    {
#line 32
        .trainerName = _("Debugger"),
#line 33
        .trainerClass = TRAINER_CLASS_RIVAL,
#line 35
        .trainerPic = TRAINER_PIC_STEVEN,
        .encounterMusic_gender =
#line 37
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 34
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 39
            .species = SPECIES_METANG,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 43
            .ev = TRAINER_PARTY_EVS(0, 252, 252, 0, 6, 0),
#line 42
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 41
            .lvl = 42,
#line 40
            .nature = NATURE_BRAVE,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 44
                MOVE_LIGHT_SCREEN,
                MOVE_PSYCHIC,
                MOVE_REFLECT,
                MOVE_METAL_CLAW,
            },
            },
            {
#line 49
            .species = SPECIES_SKARMORY,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 53
            .ev = TRAINER_PARTY_EVS(252, 0, 0, 0, 6, 252),
#line 52
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 51
            .lvl = 43,
#line 50
            .nature = NATURE_IMPISH,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 54
                MOVE_TOXIC,
                MOVE_AERIAL_ACE,
                MOVE_PROTECT,
                MOVE_STEEL_WING,
            },
            },
            {
#line 59
            .species = SPECIES_AGGRON,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 63
            .ev = TRAINER_PARTY_EVS(0, 252, 0, 0, 252, 6),
#line 62
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 61
            .lvl = 44,
#line 60
            .nature = NATURE_ADAMANT,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 64
                MOVE_THUNDER,
                MOVE_PROTECT,
                MOVE_SOLAR_BEAM,
                MOVE_DRAGON_CLAW,
            },
            },
        },
    },
