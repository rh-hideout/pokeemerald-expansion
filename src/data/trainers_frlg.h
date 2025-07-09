//
// DO NOT MODIFY THIS FILE! It is auto-generated from src/data/trainers_frlg.party
//
// If you want to modify this file set COMPETITIVE_PARTY_SYNTAX to FALSE
// in include/config/general.h and remove this notice.
// Use sed -i '/^#line/d' 'src/data/trainers_frlg.h' to remove #line markers.
//

#line 1 "src/data/trainers_frlg.party"

#line 1
    [DIFFICULTY_NORMAL][TRAINER_NONE] =
    {
#line 2
        .trainerName = _("PH"),
#line 3
        .trainerClass = TRAINER_CLASS_PKMN_TRAINER_1,
#line 4
        .trainerPic = TRAINER_PIC_HIKER,
        .encounterMusic_gender =
#line 6
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 7
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
        .partySize = 0,
        .party = (const struct TrainerMon[])
        {
        },
    },
#line 9
    [DIFFICULTY_NORMAL][TRAINER_YOUNGSTER_BEN] =
    {
#line 10
        .trainerName = _("BEN"),
#line 11
        .trainerClass = TRAINER_CLASS_YOUNGSTER,
#line 12
        .trainerPic = TRAINER_PIC_YOUNGSTER,
        .encounterMusic_gender =
#line 14
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 15
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 16
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 18
            .species = SPECIES_RATTATA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 20
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 19
            .lvl = 11,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 22
            .species = SPECIES_EKANS,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 24
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 23
            .lvl = 11,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 26
    [DIFFICULTY_NORMAL][TRAINER_YOUNGSTER_CALVIN] =
    {
#line 27
        .trainerName = _("CALVIN"),
#line 28
        .trainerClass = TRAINER_CLASS_YOUNGSTER,
#line 29
        .trainerPic = TRAINER_PIC_YOUNGSTER,
        .encounterMusic_gender =
#line 31
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 32
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 33
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 35
            .species = SPECIES_SPEAROW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 37
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 36
            .lvl = 14,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 39
    [DIFFICULTY_NORMAL][TRAINER_YOUNGSTER_JOSH] =
    {
#line 40
        .trainerName = _("JOSH"),
#line 41
        .trainerClass = TRAINER_CLASS_YOUNGSTER,
#line 42
        .trainerPic = TRAINER_PIC_YOUNGSTER,
        .encounterMusic_gender =
#line 44
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 45
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 46
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 48
            .species = SPECIES_RATTATA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 50
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 49
            .lvl = 10,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 52
            .species = SPECIES_RATTATA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 54
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 53
            .lvl = 10,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 56
            .species = SPECIES_ZUBAT,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 58
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 57
            .lvl = 10,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 60
    [DIFFICULTY_NORMAL][TRAINER_YOUNGSTER_TIMMY] =
    {
#line 61
        .trainerName = _("TIMMY"),
#line 62
        .trainerClass = TRAINER_CLASS_YOUNGSTER,
#line 63
        .trainerPic = TRAINER_PIC_YOUNGSTER,
        .encounterMusic_gender =
#line 65
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 66
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 67
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 69
            .species = SPECIES_SANDSHREW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 71
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 70
            .lvl = 14,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 73
            .species = SPECIES_EKANS,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 75
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 74
            .lvl = 14,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 77
    [DIFFICULTY_NORMAL][TRAINER_YOUNGSTER_JOEY] =
    {
#line 78
        .trainerName = _("JOEY"),
#line 79
        .trainerClass = TRAINER_CLASS_YOUNGSTER,
#line 80
        .trainerPic = TRAINER_PIC_YOUNGSTER,
        .encounterMusic_gender =
#line 82
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 83
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 84
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 86
            .species = SPECIES_RATTATA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 88
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 87
            .lvl = 15,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 90
            .species = SPECIES_SPEAROW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 92
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 91
            .lvl = 15,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 94
    [DIFFICULTY_NORMAL][TRAINER_YOUNGSTER_DAN] =
    {
#line 95
        .trainerName = _("DAN"),
#line 96
        .trainerClass = TRAINER_CLASS_YOUNGSTER,
#line 97
        .trainerPic = TRAINER_PIC_YOUNGSTER,
        .encounterMusic_gender =
#line 99
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 100
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 101
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 103
            .species = SPECIES_SLOWPOKE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 105
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 104
            .lvl = 17,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 107
    [DIFFICULTY_NORMAL][TRAINER_YOUNGSTER_CHAD] =
    {
#line 108
        .trainerName = _("CHAD"),
#line 109
        .trainerClass = TRAINER_CLASS_YOUNGSTER,
#line 110
        .trainerPic = TRAINER_PIC_YOUNGSTER,
        .encounterMusic_gender =
#line 112
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 113
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 114
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 116
            .species = SPECIES_EKANS,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 118
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 117
            .lvl = 14,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 120
            .species = SPECIES_SANDSHREW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 122
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 121
            .lvl = 14,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 124
    [DIFFICULTY_NORMAL][TRAINER_YOUNGSTER_TYLER] =
    {
#line 125
        .trainerName = _("TYLER"),
#line 126
        .trainerClass = TRAINER_CLASS_YOUNGSTER,
#line 127
        .trainerPic = TRAINER_PIC_YOUNGSTER,
        .encounterMusic_gender =
#line 129
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 130
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 131
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 133
            .species = SPECIES_NIDORAN_M,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 135
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 134
            .lvl = 21,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 137
    [DIFFICULTY_NORMAL][TRAINER_YOUNGSTER_EDDIE] =
    {
#line 138
        .trainerName = _("EDDIE"),
#line 139
        .trainerClass = TRAINER_CLASS_YOUNGSTER,
#line 140
        .trainerPic = TRAINER_PIC_YOUNGSTER,
        .encounterMusic_gender =
#line 142
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 143
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 144
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 146
            .species = SPECIES_EKANS,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 148
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 147
            .lvl = 21,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 150
    [DIFFICULTY_NORMAL][TRAINER_YOUNGSTER_DILLON] =
    {
#line 151
        .trainerName = _("DILLON"),
#line 152
        .trainerClass = TRAINER_CLASS_YOUNGSTER,
#line 153
        .trainerPic = TRAINER_PIC_YOUNGSTER,
        .encounterMusic_gender =
#line 155
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 156
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 157
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 159
            .species = SPECIES_SANDSHREW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 161
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 160
            .lvl = 19,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 163
            .species = SPECIES_ZUBAT,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 165
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 164
            .lvl = 19,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 167
    [DIFFICULTY_NORMAL][TRAINER_YOUNGSTER_YASU] =
    {
#line 168
        .trainerName = _("YASU"),
#line 169
        .trainerClass = TRAINER_CLASS_YOUNGSTER,
#line 170
        .trainerPic = TRAINER_PIC_YOUNGSTER,
        .encounterMusic_gender =
#line 172
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 173
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 174
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 176
            .species = SPECIES_RATTATA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 178
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 177
            .lvl = 17,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 180
            .species = SPECIES_RATTATA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 182
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 181
            .lvl = 17,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 184
            .species = SPECIES_RATICATE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 186
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 185
            .lvl = 17,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 188
    [DIFFICULTY_NORMAL][TRAINER_YOUNGSTER_DAVE] =
    {
#line 189
        .trainerName = _("DAVE"),
#line 190
        .trainerClass = TRAINER_CLASS_YOUNGSTER,
#line 191
        .trainerPic = TRAINER_PIC_YOUNGSTER,
        .encounterMusic_gender =
#line 193
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 194
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 195
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 197
            .species = SPECIES_NIDORAN_M,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 199
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 198
            .lvl = 18,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 201
            .species = SPECIES_NIDORINO,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 203
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 202
            .lvl = 18,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 205
    [DIFFICULTY_NORMAL][TRAINER_YOUNGSTER_BEN_2] =
    {
#line 206
        .trainerName = _("BEN"),
#line 207
        .trainerClass = TRAINER_CLASS_YOUNGSTER,
#line 208
        .trainerPic = TRAINER_PIC_YOUNGSTER,
        .encounterMusic_gender =
#line 210
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 211
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 212
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 214
            .species = SPECIES_RATTATA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 216
            .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
#line 215
            .lvl = 17,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 218
            .species = SPECIES_EKANS,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 220
            .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
#line 219
            .lvl = 17,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 222
    [DIFFICULTY_NORMAL][TRAINER_BUG_CATCHER_RICK] =
    {
#line 223
        .trainerName = _("RICK"),
#line 224
        .trainerClass = TRAINER_CLASS_BUG_CATCHER,
#line 225
        .trainerPic = TRAINER_PIC_BUG_CATCHER,
        .encounterMusic_gender =
#line 227
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 228
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 229
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 231
            .species = SPECIES_WEEDLE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 233
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 232
            .lvl = 6,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 235
            .species = SPECIES_CATERPIE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 237
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 236
            .lvl = 6,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 239
    [DIFFICULTY_NORMAL][TRAINER_BUG_CATCHER_DOUG] =
    {
#line 240
        .trainerName = _("DOUG"),
#line 241
        .trainerClass = TRAINER_CLASS_BUG_CATCHER,
#line 242
        .trainerPic = TRAINER_PIC_BUG_CATCHER,
        .encounterMusic_gender =
#line 244
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 245
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 246
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 248
            .species = SPECIES_WEEDLE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 250
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 249
            .lvl = 7,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 252
            .species = SPECIES_KAKUNA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 254
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 253
            .lvl = 7,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 256
            .species = SPECIES_WEEDLE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 258
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 257
            .lvl = 7,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 260
    [DIFFICULTY_NORMAL][TRAINER_BUG_CATCHER_SAMMY] =
    {
#line 261
        .trainerName = _("SAMMY"),
#line 262
        .trainerClass = TRAINER_CLASS_BUG_CATCHER,
#line 263
        .trainerPic = TRAINER_PIC_BUG_CATCHER,
        .encounterMusic_gender =
#line 265
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 266
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 267
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 269
            .species = SPECIES_WEEDLE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 271
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 270
            .lvl = 9,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 273
    [DIFFICULTY_NORMAL][TRAINER_BUG_CATCHER_COLTON] =
    {
#line 274
        .trainerName = _("COLTON"),
#line 275
        .trainerClass = TRAINER_CLASS_BUG_CATCHER,
#line 276
        .trainerPic = TRAINER_PIC_BUG_CATCHER,
        .encounterMusic_gender =
#line 278
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 279
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 280
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 282
            .species = SPECIES_CATERPIE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 284
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 283
            .lvl = 10,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 286
            .species = SPECIES_WEEDLE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 288
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 287
            .lvl = 10,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 290
            .species = SPECIES_CATERPIE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 292
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 291
            .lvl = 10,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 294
    [DIFFICULTY_NORMAL][TRAINER_BUG_CATCHER_GREG] =
    {
#line 295
        .trainerName = _("GREG"),
#line 296
        .trainerClass = TRAINER_CLASS_BUG_CATCHER,
#line 297
        .trainerPic = TRAINER_PIC_BUG_CATCHER,
        .encounterMusic_gender =
#line 299
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 300
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 301
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 4,
        .party = (const struct TrainerMon[])
        {
            {
#line 303
            .species = SPECIES_WEEDLE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 305
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 304
            .lvl = 9,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 307
            .species = SPECIES_KAKUNA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 309
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 308
            .lvl = 9,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 311
            .species = SPECIES_CATERPIE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 313
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 312
            .lvl = 9,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 315
            .species = SPECIES_METAPOD,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 317
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 316
            .lvl = 9,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 319
    [DIFFICULTY_NORMAL][TRAINER_BUG_CATCHER_JAMES] =
    {
#line 320
        .trainerName = _("JAMES"),
#line 321
        .trainerClass = TRAINER_CLASS_BUG_CATCHER,
#line 322
        .trainerPic = TRAINER_PIC_BUG_CATCHER,
        .encounterMusic_gender =
#line 324
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 325
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 326
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 328
            .species = SPECIES_CATERPIE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 330
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 329
            .lvl = 11,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 332
            .species = SPECIES_METAPOD,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 334
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 333
            .lvl = 11,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 336
    [DIFFICULTY_NORMAL][TRAINER_BUG_CATCHER_KENT] =
    {
#line 337
        .trainerName = _("KENT"),
#line 338
        .trainerClass = TRAINER_CLASS_BUG_CATCHER,
#line 339
        .trainerPic = TRAINER_PIC_BUG_CATCHER,
        .encounterMusic_gender =
#line 341
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 342
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 343
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 345
            .species = SPECIES_WEEDLE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 347
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 346
            .lvl = 11,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 349
            .species = SPECIES_KAKUNA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 351
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 350
            .lvl = 11,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 353
    [DIFFICULTY_NORMAL][TRAINER_BUG_CATCHER_ROBBY] =
    {
#line 354
        .trainerName = _("ROBBY"),
#line 355
        .trainerClass = TRAINER_CLASS_BUG_CATCHER,
#line 356
        .trainerPic = TRAINER_PIC_BUG_CATCHER,
        .encounterMusic_gender =
#line 358
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 359
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 360
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 362
            .species = SPECIES_CATERPIE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 364
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 363
            .lvl = 10,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 366
            .species = SPECIES_METAPOD,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 368
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 367
            .lvl = 10,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 370
            .species = SPECIES_CATERPIE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 372
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 371
            .lvl = 10,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 374
    [DIFFICULTY_NORMAL][TRAINER_BUG_CATCHER_CALE] =
    {
#line 375
        .trainerName = _("CALE"),
#line 376
        .trainerClass = TRAINER_CLASS_BUG_CATCHER,
#line 377
        .trainerPic = TRAINER_PIC_BUG_CATCHER,
        .encounterMusic_gender =
#line 379
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 380
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 381
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 4,
        .party = (const struct TrainerMon[])
        {
            {
#line 383
            .species = SPECIES_CATERPIE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 385
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 384
            .lvl = 10,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 387
            .species = SPECIES_WEEDLE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 389
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 388
            .lvl = 10,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 391
            .species = SPECIES_METAPOD,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 393
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 392
            .lvl = 10,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 395
            .species = SPECIES_KAKUNA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 397
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 396
            .lvl = 10,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 399
    [DIFFICULTY_NORMAL][TRAINER_BUG_CATCHER_KEIGO] =
    {
#line 400
        .trainerName = _("KEIGO"),
#line 401
        .trainerClass = TRAINER_CLASS_BUG_CATCHER,
#line 402
        .trainerPic = TRAINER_PIC_BUG_CATCHER,
        .encounterMusic_gender =
#line 404
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 405
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 406
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 408
            .species = SPECIES_WEEDLE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 410
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 409
            .lvl = 16,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 412
            .species = SPECIES_CATERPIE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 414
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 413
            .lvl = 16,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 416
            .species = SPECIES_WEEDLE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 418
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 417
            .lvl = 16,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 420
    [DIFFICULTY_NORMAL][TRAINER_BUG_CATCHER_ELIJAH] =
    {
#line 421
        .trainerName = _("ELIJAH"),
#line 422
        .trainerClass = TRAINER_CLASS_BUG_CATCHER,
#line 423
        .trainerPic = TRAINER_PIC_BUG_CATCHER,
        .encounterMusic_gender =
#line 425
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 426
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 427
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 429
            .species = SPECIES_BUTTERFREE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 431
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 430
            .lvl = 20,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 433
    [DIFFICULTY_NORMAL][TRAINER_BUG_CATCHER_2] =
    {
#line 434
        .trainerName = _("PH"),
#line 435
        .trainerClass = TRAINER_CLASS_BUG_CATCHER,
#line 436
        .trainerPic = TRAINER_PIC_BUG_CATCHER,
        .encounterMusic_gender =
#line 438
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 439
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 440
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 442
            .species = SPECIES_METAPOD,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 444
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 443
            .lvl = 18,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 446
            .species = SPECIES_CATERPIE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 448
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 447
            .lvl = 18,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 450
            .species = SPECIES_VENONAT,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 452
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 451
            .lvl = 18,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 454
    [DIFFICULTY_NORMAL][TRAINER_BUG_CATCHER_BRENT] =
    {
#line 455
        .trainerName = _("BRENT"),
#line 456
        .trainerClass = TRAINER_CLASS_BUG_CATCHER,
#line 457
        .trainerPic = TRAINER_PIC_BUG_CATCHER,
        .encounterMusic_gender =
#line 459
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 460
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 461
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 463
            .species = SPECIES_BEEDRILL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 465
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 464
            .lvl = 19,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 467
            .species = SPECIES_BEEDRILL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 469
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 468
            .lvl = 19,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 471
    [DIFFICULTY_NORMAL][TRAINER_BUG_CATCHER_CONNER] =
    {
#line 472
        .trainerName = _("CONNER"),
#line 473
        .trainerClass = TRAINER_CLASS_BUG_CATCHER,
#line 474
        .trainerPic = TRAINER_PIC_BUG_CATCHER,
        .encounterMusic_gender =
#line 476
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 477
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 478
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 480
            .species = SPECIES_CATERPIE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 482
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 481
            .lvl = 20,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 484
            .species = SPECIES_WEEDLE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 486
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 485
            .lvl = 20,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 488
            .species = SPECIES_VENONAT,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 490
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 489
            .lvl = 20,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 492
    [DIFFICULTY_NORMAL][TRAINER_LASS_JANICE] =
    {
#line 493
        .trainerName = _("JANICE"),
#line 494
        .trainerClass = TRAINER_CLASS_LASS,
#line 495
        .trainerPic = TRAINER_PIC_LASS,
        .encounterMusic_gender =
#line 497
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
#line 498
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 499
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 501
            .species = SPECIES_PIDGEY,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 503
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 502
            .lvl = 9,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 505
            .species = SPECIES_PIDGEY,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 507
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 506
            .lvl = 9,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 509
    [DIFFICULTY_NORMAL][TRAINER_LASS_SALLY] =
    {
#line 510
        .trainerName = _("SALLY"),
#line 511
        .trainerClass = TRAINER_CLASS_LASS,
#line 512
        .trainerPic = TRAINER_PIC_LASS,
        .encounterMusic_gender =
#line 514
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
#line 515
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 516
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 518
            .species = SPECIES_RATTATA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 520
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 519
            .lvl = 10,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 522
            .species = SPECIES_NIDORAN_F,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 524
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 523
            .lvl = 10,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 526
    [DIFFICULTY_NORMAL][TRAINER_LASS_ROBIN] =
    {
#line 527
        .trainerName = _("ROBIN"),
#line 528
        .trainerClass = TRAINER_CLASS_LASS,
#line 529
        .trainerPic = TRAINER_PIC_LASS,
        .encounterMusic_gender =
#line 531
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
#line 532
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 533
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 535
            .species = SPECIES_JIGGLYPUFF,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 537
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 536
            .lvl = 14,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 539
    [DIFFICULTY_NORMAL][TRAINER_LASS_CRISSY] =
    {
#line 540
        .trainerName = _("CRISSY"),
#line 541
        .trainerClass = TRAINER_CLASS_LASS,
#line 542
        .trainerPic = TRAINER_PIC_LASS,
        .encounterMusic_gender =
#line 544
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
#line 545
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 546
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 548
            .species = SPECIES_PARAS,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 550
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 549
            .lvl = 31,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 552
            .species = SPECIES_PARAS,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 554
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 553
            .lvl = 31,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 556
            .species = SPECIES_PARASECT,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 558
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 557
            .lvl = 31,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 560
    [DIFFICULTY_NORMAL][TRAINER_LASS_MIRIAM] =
    {
#line 561
        .trainerName = _("MIRIAM"),
#line 562
        .trainerClass = TRAINER_CLASS_LASS,
#line 563
        .trainerPic = TRAINER_PIC_LASS,
        .encounterMusic_gender =
#line 565
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
#line 566
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 567
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 569
            .species = SPECIES_ODDISH,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 571
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 570
            .lvl = 11,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 573
            .species = SPECIES_BELLSPROUT,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 575
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 574
            .lvl = 11,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 577
    [DIFFICULTY_NORMAL][TRAINER_LASS_IRIS] =
    {
#line 578
        .trainerName = _("IRIS"),
#line 579
        .trainerClass = TRAINER_CLASS_LASS,
#line 580
        .trainerPic = TRAINER_PIC_LASS,
        .encounterMusic_gender =
#line 582
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
#line 583
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 584
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 586
            .species = SPECIES_CLEFAIRY,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 588
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 587
            .lvl = 14,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 590
    [DIFFICULTY_NORMAL][TRAINER_LASS_RELI] =
    {
#line 591
        .trainerName = _("RELI"),
#line 592
        .trainerClass = TRAINER_CLASS_LASS,
#line 593
        .trainerPic = TRAINER_PIC_LASS,
        .encounterMusic_gender =
#line 595
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
#line 596
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 597
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 599
            .species = SPECIES_NIDORAN_M,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 601
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 600
            .lvl = 16,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 603
            .species = SPECIES_NIDORAN_F,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 605
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 604
            .lvl = 16,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 607
    [DIFFICULTY_NORMAL][TRAINER_LASS_ALI] =
    {
#line 608
        .trainerName = _("ALI"),
#line 609
        .trainerClass = TRAINER_CLASS_LASS,
#line 610
        .trainerPic = TRAINER_PIC_LASS,
        .encounterMusic_gender =
#line 612
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
#line 613
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 614
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 616
            .species = SPECIES_PIDGEY,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 618
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 617
            .lvl = 12,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 620
            .species = SPECIES_ODDISH,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 622
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 621
            .lvl = 12,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 624
            .species = SPECIES_BELLSPROUT,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 626
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 625
            .lvl = 12,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 628
    [DIFFICULTY_NORMAL][TRAINER_LASS_2] =
    {
#line 629
        .trainerName = _("PH"),
#line 630
        .trainerClass = TRAINER_CLASS_LASS,
#line 631
        .trainerPic = TRAINER_PIC_LASS,
        .encounterMusic_gender =
#line 633
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
#line 634
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 635
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 637
            .species = SPECIES_NIDORAN_M,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 639
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 638
            .lvl = 15,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 641
            .species = SPECIES_NIDORAN_F,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 643
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 642
            .lvl = 15,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 645
    [DIFFICULTY_NORMAL][TRAINER_LASS_HALEY] =
    {
#line 646
        .trainerName = _("HALEY"),
#line 647
        .trainerClass = TRAINER_CLASS_LASS,
#line 648
        .trainerPic = TRAINER_PIC_LASS,
        .encounterMusic_gender =
#line 650
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
#line 651
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 652
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 654
            .species = SPECIES_ODDISH,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 656
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 655
            .lvl = 13,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 658
            .species = SPECIES_PIDGEY,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 660
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 659
            .lvl = 13,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 662
            .species = SPECIES_ODDISH,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 664
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 663
            .lvl = 13,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 666
    [DIFFICULTY_NORMAL][TRAINER_LASS_ANN] =
    {
#line 667
        .trainerName = _("ANN"),
#line 668
        .trainerClass = TRAINER_CLASS_LASS,
#line 669
        .trainerPic = TRAINER_PIC_LASS,
        .encounterMusic_gender =
#line 671
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
#line 672
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 673
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 675
            .species = SPECIES_PIDGEY,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 677
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 676
            .lvl = 18,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 679
            .species = SPECIES_NIDORAN_F,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 681
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 680
            .lvl = 18,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 683
    [DIFFICULTY_NORMAL][TRAINER_LASS_DAWN] =
    {
#line 684
        .trainerName = _("DAWN"),
#line 685
        .trainerClass = TRAINER_CLASS_LASS,
#line 686
        .trainerPic = TRAINER_PIC_LASS,
        .encounterMusic_gender =
#line 688
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
#line 689
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 690
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 692
            .species = SPECIES_RATTATA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 694
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 693
            .lvl = 18,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 696
            .species = SPECIES_PIKACHU,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 698
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 697
            .lvl = 18,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 700
    [DIFFICULTY_NORMAL][TRAINER_LASS_PAIGE] =
    {
#line 701
        .trainerName = _("PAIGE"),
#line 702
        .trainerClass = TRAINER_CLASS_LASS,
#line 703
        .trainerPic = TRAINER_PIC_LASS,
        .encounterMusic_gender =
#line 705
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
#line 706
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 707
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 709
            .species = SPECIES_NIDORAN_F,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 711
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 710
            .lvl = 23,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 713
            .species = SPECIES_NIDORINA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 715
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 714
            .lvl = 23,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 717
    [DIFFICULTY_NORMAL][TRAINER_LASS_ANDREA] =
    {
#line 718
        .trainerName = _("ANDREA"),
#line 719
        .trainerClass = TRAINER_CLASS_LASS,
#line 720
        .trainerPic = TRAINER_PIC_LASS,
        .encounterMusic_gender =
#line 722
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
#line 723
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 724
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 726
            .species = SPECIES_MEOWTH,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 728
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 727
            .lvl = 24,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 730
            .species = SPECIES_MEOWTH,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 732
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 731
            .lvl = 24,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 734
            .species = SPECIES_MEOWTH,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 736
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 735
            .lvl = 24,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 738
    [DIFFICULTY_NORMAL][TRAINER_LASS_MEGAN] =
    {
#line 739
        .trainerName = _("MEGAN"),
#line 740
        .trainerClass = TRAINER_CLASS_LASS,
#line 741
        .trainerPic = TRAINER_PIC_LASS,
        .encounterMusic_gender =
#line 743
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
#line 744
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 745
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 5,
        .party = (const struct TrainerMon[])
        {
            {
#line 747
            .species = SPECIES_PIDGEY,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 749
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 748
            .lvl = 19,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 751
            .species = SPECIES_RATTATA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 753
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 752
            .lvl = 19,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 755
            .species = SPECIES_NIDORAN_M,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 757
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 756
            .lvl = 19,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 759
            .species = SPECIES_MEOWTH,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 761
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 760
            .lvl = 19,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 763
            .species = SPECIES_PIKACHU,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 765
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 764
            .lvl = 19,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 767
    [DIFFICULTY_NORMAL][TRAINER_LASS_JULIA] =
    {
#line 768
        .trainerName = _("JULIA"),
#line 769
        .trainerClass = TRAINER_CLASS_LASS,
#line 770
        .trainerPic = TRAINER_PIC_LASS,
        .encounterMusic_gender =
#line 772
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
#line 773
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 774
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 776
            .species = SPECIES_CLEFAIRY,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 778
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 777
            .lvl = 22,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 780
            .species = SPECIES_CLEFAIRY,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 782
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 781
            .lvl = 22,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 784
    [DIFFICULTY_NORMAL][TRAINER_LASS_KAY] =
    {
#line 785
        .trainerName = _("KAY"),
#line 786
        .trainerClass = TRAINER_CLASS_LASS,
#line 787
        .trainerPic = TRAINER_PIC_LASS,
        .encounterMusic_gender =
#line 789
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
#line 790
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 791
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 793
            .species = SPECIES_BELLSPROUT,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 795
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 794
            .lvl = 23,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 797
            .species = SPECIES_WEEPINBELL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 799
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 798
            .lvl = 23,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 801
    [DIFFICULTY_NORMAL][TRAINER_LASS_LISA] =
    {
#line 802
        .trainerName = _("LISA"),
#line 803
        .trainerClass = TRAINER_CLASS_LASS,
#line 804
        .trainerPic = TRAINER_PIC_LASS,
        .encounterMusic_gender =
#line 806
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
#line 807
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 808
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 810
            .species = SPECIES_ODDISH,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 812
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 811
            .lvl = 23,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 814
            .species = SPECIES_GLOOM,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 816
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 815
            .lvl = 23,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 818
    [DIFFICULTY_NORMAL][TRAINER_SAILOR_EDMOND] =
    {
#line 819
        .trainerName = _("EDMOND"),
#line 820
        .trainerClass = TRAINER_CLASS_SAILOR,
#line 821
        .trainerPic = TRAINER_PIC_SAILOR,
        .encounterMusic_gender =
#line 823
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 824
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 825
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 827
            .species = SPECIES_MACHOP,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 829
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 828
            .lvl = 18,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 831
            .species = SPECIES_SHELLDER,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 833
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 832
            .lvl = 18,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 835
    [DIFFICULTY_NORMAL][TRAINER_SAILOR_TREVOR] =
    {
#line 836
        .trainerName = _("TREVOR"),
#line 837
        .trainerClass = TRAINER_CLASS_SAILOR,
#line 838
        .trainerPic = TRAINER_PIC_SAILOR,
        .encounterMusic_gender =
#line 840
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 841
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 842
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 844
            .species = SPECIES_MACHOP,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 846
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 845
            .lvl = 17,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 848
            .species = SPECIES_TENTACOOL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 850
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 849
            .lvl = 17,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 852
    [DIFFICULTY_NORMAL][TRAINER_SAILOR_LEONARD] =
    {
#line 853
        .trainerName = _("LEONARD"),
#line 854
        .trainerClass = TRAINER_CLASS_SAILOR,
#line 855
        .trainerPic = TRAINER_PIC_SAILOR,
        .encounterMusic_gender =
#line 857
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 858
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 859
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 861
            .species = SPECIES_SHELLDER,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 863
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 862
            .lvl = 21,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 865
    [DIFFICULTY_NORMAL][TRAINER_SAILOR_DUNCAN] =
    {
#line 866
        .trainerName = _("DUNCAN"),
#line 867
        .trainerClass = TRAINER_CLASS_SAILOR,
#line 868
        .trainerPic = TRAINER_PIC_SAILOR,
        .encounterMusic_gender =
#line 870
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 871
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 872
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 874
            .species = SPECIES_HORSEA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 876
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 875
            .lvl = 17,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 878
            .species = SPECIES_SHELLDER,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 880
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 879
            .lvl = 17,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 882
            .species = SPECIES_TENTACOOL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 884
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 883
            .lvl = 17,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 886
    [DIFFICULTY_NORMAL][TRAINER_SAILOR_HUEY] =
    {
#line 887
        .trainerName = _("HUEY"),
#line 888
        .trainerClass = TRAINER_CLASS_SAILOR,
#line 889
        .trainerPic = TRAINER_PIC_SAILOR,
        .encounterMusic_gender =
#line 891
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 892
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 893
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 895
            .species = SPECIES_TENTACOOL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 897
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 896
            .lvl = 18,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 899
            .species = SPECIES_STARYU,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 901
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 900
            .lvl = 18,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 903
    [DIFFICULTY_NORMAL][TRAINER_SAILOR_DYLAN] =
    {
#line 904
        .trainerName = _("DYLAN"),
#line 905
        .trainerClass = TRAINER_CLASS_SAILOR,
#line 906
        .trainerPic = TRAINER_PIC_SAILOR,
        .encounterMusic_gender =
#line 908
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 909
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 910
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 912
            .species = SPECIES_HORSEA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 914
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 913
            .lvl = 17,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 916
            .species = SPECIES_HORSEA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 918
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 917
            .lvl = 17,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 920
            .species = SPECIES_HORSEA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 922
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 921
            .lvl = 17,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 924
    [DIFFICULTY_NORMAL][TRAINER_SAILOR_PHILLIP] =
    {
#line 925
        .trainerName = _("PHILLIP"),
#line 926
        .trainerClass = TRAINER_CLASS_SAILOR,
#line 927
        .trainerPic = TRAINER_PIC_SAILOR,
        .encounterMusic_gender =
#line 929
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 930
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 931
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 933
            .species = SPECIES_MACHOP,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 935
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 934
            .lvl = 20,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 937
    [DIFFICULTY_NORMAL][TRAINER_SAILOR_DWAYNE] =
    {
#line 938
        .trainerName = _("DWAYNE"),
#line 939
        .trainerClass = TRAINER_CLASS_SAILOR,
#line 940
        .trainerPic = TRAINER_PIC_SAILOR,
        .encounterMusic_gender =
#line 942
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 943
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 944
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 946
            .species = SPECIES_PIKACHU,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 948
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 947
            .lvl = 21,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 950
            .species = SPECIES_PIKACHU,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 952
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 951
            .lvl = 21,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 954
    [DIFFICULTY_NORMAL][TRAINER_CAMPER_LIAM] =
    {
#line 955
        .trainerName = _("LIAM"),
#line 956
        .trainerClass = TRAINER_CLASS_CAMPER,
#line 957
        .trainerPic = TRAINER_PIC_CAMPER,
        .encounterMusic_gender =
#line 959
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 960
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 961
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 963
            .species = SPECIES_GEODUDE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 965
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 964
            .lvl = 10,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 966
                MOVE_TACKLE,
                MOVE_DEFENSE_CURL,
            },
            },
            {
#line 969
            .species = SPECIES_SANDSHREW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 971
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 970
            .lvl = 11,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 972
                MOVE_SCRATCH,
                MOVE_DEFENSE_CURL,
                MOVE_SAND_ATTACK,
            },
            },
        },
    },
#line 976
    [DIFFICULTY_NORMAL][TRAINER_CAMPER_SHANE] =
    {
#line 977
        .trainerName = _("SHANE"),
#line 978
        .trainerClass = TRAINER_CLASS_CAMPER,
#line 979
        .trainerPic = TRAINER_PIC_CAMPER,
        .encounterMusic_gender =
#line 981
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 982
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 983
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 985
            .species = SPECIES_RATTATA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 987
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 986
            .lvl = 14,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 989
            .species = SPECIES_EKANS,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 991
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 990
            .lvl = 14,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 993
    [DIFFICULTY_NORMAL][TRAINER_CAMPER_ETHAN] =
    {
#line 994
        .trainerName = _("ETHAN"),
#line 995
        .trainerClass = TRAINER_CLASS_CAMPER,
#line 996
        .trainerPic = TRAINER_PIC_CAMPER,
        .encounterMusic_gender =
#line 998
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 999
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 1000
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 1002
            .species = SPECIES_MANKEY,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1004
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 1003
            .lvl = 18,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 1006
    [DIFFICULTY_NORMAL][TRAINER_CAMPER_RICKY] =
    {
#line 1007
        .trainerName = _("RICKY"),
#line 1008
        .trainerClass = TRAINER_CLASS_CAMPER,
#line 1009
        .trainerPic = TRAINER_PIC_CAMPER,
        .encounterMusic_gender =
#line 1011
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 1012
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 1013
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 1015
            .species = SPECIES_SQUIRTLE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1017
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 1016
            .lvl = 20,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 1019
    [DIFFICULTY_NORMAL][TRAINER_CAMPER_JEFF] =
    {
#line 1020
        .trainerName = _("JEFF"),
#line 1021
        .trainerClass = TRAINER_CLASS_CAMPER,
#line 1022
        .trainerPic = TRAINER_PIC_CAMPER,
        .encounterMusic_gender =
#line 1024
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 1025
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 1026
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 1028
            .species = SPECIES_SPEAROW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1030
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 1029
            .lvl = 16,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 1032
            .species = SPECIES_RATICATE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1034
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 1033
            .lvl = 16,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 1036
    [DIFFICULTY_NORMAL][TRAINER_CAMPER_2] =
    {
#line 1037
        .trainerName = _("PH"),
#line 1038
        .trainerClass = TRAINER_CLASS_CAMPER,
#line 1039
        .trainerPic = TRAINER_PIC_CAMPER,
        .encounterMusic_gender =
#line 1041
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 1042
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 1043
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 1045
            .species = SPECIES_EKANS,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1047
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 1046
            .lvl = 5,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 1049
    [DIFFICULTY_NORMAL][TRAINER_CAMPER_CHRIS] =
    {
#line 1050
        .trainerName = _("CHRIS"),
#line 1051
        .trainerClass = TRAINER_CLASS_CAMPER,
#line 1052
        .trainerPic = TRAINER_PIC_CAMPER,
        .encounterMusic_gender =
#line 1054
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 1055
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 1056
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 1058
            .species = SPECIES_GROWLITHE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1060
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 1059
            .lvl = 21,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 1062
            .species = SPECIES_CHARMANDER,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1064
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 1063
            .lvl = 21,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 1066
    [DIFFICULTY_NORMAL][TRAINER_CAMPER_DREW] =
    {
#line 1067
        .trainerName = _("DREW"),
#line 1068
        .trainerClass = TRAINER_CLASS_CAMPER,
#line 1069
        .trainerPic = TRAINER_PIC_CAMPER,
        .encounterMusic_gender =
#line 1071
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 1072
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 1073
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 4,
        .party = (const struct TrainerMon[])
        {
            {
#line 1075
            .species = SPECIES_RATTATA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1077
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 1076
            .lvl = 19,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 1079
            .species = SPECIES_SANDSHREW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1081
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 1080
            .lvl = 19,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 1083
            .species = SPECIES_EKANS,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1085
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 1084
            .lvl = 19,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 1087
            .species = SPECIES_SANDSHREW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1089
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 1088
            .lvl = 19,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 1091
    [DIFFICULTY_NORMAL][TRAINER_PICNICKER_DIANA] =
    {
#line 1092
        .trainerName = _("DIANA"),
#line 1093
        .trainerClass = TRAINER_CLASS_PICNICKER,
#line 1094
        .trainerPic = TRAINER_PIC_PICNICKER,
        .encounterMusic_gender =
#line 1096
            TRAINER_ENCOUNTER_MUSIC_GIRL,
#line 1097
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 1098
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 1100
            .species = SPECIES_GOLDEEN,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1102
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 1101
            .lvl = 19,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 1104
    [DIFFICULTY_NORMAL][TRAINER_PICNICKER_NANCY] =
    {
#line 1105
        .trainerName = _("NANCY"),
#line 1106
        .trainerClass = TRAINER_CLASS_PICNICKER,
#line 1107
        .trainerPic = TRAINER_PIC_PICNICKER,
        .encounterMusic_gender =
#line 1109
            TRAINER_ENCOUNTER_MUSIC_GIRL,
#line 1110
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 1111
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 1113
            .species = SPECIES_RATTATA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1115
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 1114
            .lvl = 16,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 1117
            .species = SPECIES_PIKACHU,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1119
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 1118
            .lvl = 16,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 1121
    [DIFFICULTY_NORMAL][TRAINER_PICNICKER_ISABELLE] =
    {
#line 1122
        .trainerName = _("ISABELLE"),
#line 1123
        .trainerClass = TRAINER_CLASS_PICNICKER,
#line 1124
        .trainerPic = TRAINER_PIC_PICNICKER,
        .encounterMusic_gender =
#line 1126
            TRAINER_ENCOUNTER_MUSIC_GIRL,
#line 1127
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 1128
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 1130
            .species = SPECIES_PIDGEY,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1132
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 1131
            .lvl = 16,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 1134
            .species = SPECIES_PIDGEY,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1136
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 1135
            .lvl = 16,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 1138
            .species = SPECIES_PIDGEY,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1140
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 1139
            .lvl = 16,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 1142
    [DIFFICULTY_NORMAL][TRAINER_PICNICKER_KELSEY] =
    {
#line 1143
        .trainerName = _("KELSEY"),
#line 1144
        .trainerClass = TRAINER_CLASS_PICNICKER,
#line 1145
        .trainerPic = TRAINER_PIC_PICNICKER,
        .encounterMusic_gender =
#line 1147
            TRAINER_ENCOUNTER_MUSIC_GIRL,
#line 1148
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 1149
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 1151
            .species = SPECIES_NIDORAN_M,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1153
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 1152
            .lvl = 15,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 1155
            .species = SPECIES_NIDORAN_F,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1157
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 1156
            .lvl = 15,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 1159
    [DIFFICULTY_NORMAL][TRAINER_PICNICKER_ALICIA] =
    {
#line 1160
        .trainerName = _("ALICIA"),
#line 1161
        .trainerClass = TRAINER_CLASS_PICNICKER,
#line 1162
        .trainerPic = TRAINER_PIC_PICNICKER,
        .encounterMusic_gender =
#line 1164
            TRAINER_ENCOUNTER_MUSIC_GIRL,
#line 1165
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 1166
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 4,
        .party = (const struct TrainerMon[])
        {
            {
#line 1168
            .species = SPECIES_ODDISH,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1170
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 1169
            .lvl = 18,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 1172
            .species = SPECIES_BELLSPROUT,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1174
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 1173
            .lvl = 18,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 1176
            .species = SPECIES_ODDISH,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1178
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 1177
            .lvl = 18,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 1180
            .species = SPECIES_BELLSPROUT,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1182
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 1181
            .lvl = 18,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 1184
    [DIFFICULTY_NORMAL][TRAINER_PICNICKER_CAITLIN] =
    {
#line 1185
        .trainerName = _("CAITLIN"),
#line 1186
        .trainerClass = TRAINER_CLASS_PICNICKER,
#line 1187
        .trainerPic = TRAINER_PIC_PICNICKER,
        .encounterMusic_gender =
#line 1189
            TRAINER_ENCOUNTER_MUSIC_GIRL,
#line 1190
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 1191
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 1193
            .species = SPECIES_MEOWTH,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1195
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 1194
            .lvl = 23,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 1197
    [DIFFICULTY_NORMAL][TRAINER_PICNICKER_HEIDI] =
    {
#line 1198
        .trainerName = _("HEIDI"),
#line 1199
        .trainerClass = TRAINER_CLASS_PICNICKER,
#line 1200
        .trainerPic = TRAINER_PIC_PICNICKER,
        .encounterMusic_gender =
#line 1202
            TRAINER_ENCOUNTER_MUSIC_GIRL,
#line 1203
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 1204
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 1206
            .species = SPECIES_PIKACHU,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1208
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 1207
            .lvl = 20,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 1210
            .species = SPECIES_CLEFAIRY,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1212
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 1211
            .lvl = 20,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 1214
    [DIFFICULTY_NORMAL][TRAINER_PICNICKER_CAROL] =
    {
#line 1215
        .trainerName = _("CAROL"),
#line 1216
        .trainerClass = TRAINER_CLASS_PICNICKER,
#line 1217
        .trainerPic = TRAINER_PIC_PICNICKER,
        .encounterMusic_gender =
#line 1219
            TRAINER_ENCOUNTER_MUSIC_GIRL,
#line 1220
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 1221
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 1223
            .species = SPECIES_PIDGEY,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1225
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 1224
            .lvl = 21,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 1227
            .species = SPECIES_PIDGEOTTO,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1229
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 1228
            .lvl = 21,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 1231
    [DIFFICULTY_NORMAL][TRAINER_PICNICKER_SOFIA] =
    {
#line 1232
        .trainerName = _("SOFIA"),
#line 1233
        .trainerClass = TRAINER_CLASS_PICNICKER,
#line 1234
        .trainerPic = TRAINER_PIC_PICNICKER,
        .encounterMusic_gender =
#line 1236
            TRAINER_ENCOUNTER_MUSIC_GIRL,
#line 1237
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 1238
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 1240
            .species = SPECIES_JIGGLYPUFF,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1242
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 1241
            .lvl = 21,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 1244
            .species = SPECIES_PIDGEY,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1246
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 1245
            .lvl = 21,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 1248
            .species = SPECIES_MEOWTH,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1250
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 1249
            .lvl = 21,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 1252
    [DIFFICULTY_NORMAL][TRAINER_PICNICKER_MARTHA] =
    {
#line 1253
        .trainerName = _("MARTHA"),
#line 1254
        .trainerClass = TRAINER_CLASS_PICNICKER,
#line 1255
        .trainerPic = TRAINER_PIC_PICNICKER,
        .encounterMusic_gender =
#line 1257
            TRAINER_ENCOUNTER_MUSIC_GIRL,
#line 1258
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 1259
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 1261
            .species = SPECIES_ODDISH,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1263
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 1262
            .lvl = 22,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 1265
            .species = SPECIES_BULBASAUR,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1267
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 1266
            .lvl = 22,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 1269
    [DIFFICULTY_NORMAL][TRAINER_PICNICKER_TINA] =
    {
#line 1270
        .trainerName = _("TINA"),
#line 1271
        .trainerClass = TRAINER_CLASS_PICNICKER,
#line 1272
        .trainerPic = TRAINER_PIC_PICNICKER,
        .encounterMusic_gender =
#line 1274
            TRAINER_ENCOUNTER_MUSIC_GIRL,
#line 1275
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 1276
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 1278
            .species = SPECIES_BULBASAUR,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1280
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 1279
            .lvl = 24,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 1282
            .species = SPECIES_IVYSAUR,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1284
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 1283
            .lvl = 24,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 1286
    [DIFFICULTY_NORMAL][TRAINER_PICNICKER_HANNAH] =
    {
#line 1287
        .trainerName = _("HANNAH"),
#line 1288
        .trainerClass = TRAINER_CLASS_PICNICKER,
#line 1289
        .trainerPic = TRAINER_PIC_PICNICKER,
        .encounterMusic_gender =
#line 1291
            TRAINER_ENCOUNTER_MUSIC_GIRL,
#line 1292
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 1293
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 5,
        .party = (const struct TrainerMon[])
        {
            {
#line 1295
            .species = SPECIES_PIDGEY,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1297
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 1296
            .lvl = 24,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 1299
            .species = SPECIES_MEOWTH,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1301
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 1300
            .lvl = 24,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 1303
            .species = SPECIES_RATTATA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1305
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 1304
            .lvl = 24,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 1307
            .species = SPECIES_PIKACHU,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1309
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 1308
            .lvl = 24,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 1311
            .species = SPECIES_MEOWTH,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1313
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 1312
            .lvl = 24,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 1315
    [DIFFICULTY_NORMAL][TRAINER_POKEMANIAC_MARK] =
    {
#line 1316
        .trainerName = _("MARK"),
#line 1317
        .trainerClass = TRAINER_CLASS_POKEMANIAC,
#line 1318
        .trainerPic = TRAINER_PIC_POKEMANIAC,
        .encounterMusic_gender =
#line 1320
            TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
#line 1321
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 1322
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 1324
            .species = SPECIES_RHYHORN,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1326
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
#line 1325
            .lvl = 29,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 1328
            .species = SPECIES_LICKITUNG,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1330
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
#line 1329
            .lvl = 29,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 1332
    [DIFFICULTY_NORMAL][TRAINER_POKEMANIAC_HERMAN] =
    {
#line 1333
        .trainerName = _("HERMAN"),
#line 1334
        .trainerClass = TRAINER_CLASS_POKEMANIAC,
#line 1335
        .trainerPic = TRAINER_PIC_POKEMANIAC,
        .encounterMusic_gender =
#line 1337
            TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
#line 1338
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 1339
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 1341
            .species = SPECIES_CUBONE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1343
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
#line 1342
            .lvl = 20,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 1345
            .species = SPECIES_SLOWPOKE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1347
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
#line 1346
            .lvl = 20,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 1349
    [DIFFICULTY_NORMAL][TRAINER_POKEMANIAC_COOPER] =
    {
#line 1350
        .trainerName = _("COOPER"),
#line 1351
        .trainerClass = TRAINER_CLASS_POKEMANIAC,
#line 1352
        .trainerPic = TRAINER_PIC_POKEMANIAC,
        .encounterMusic_gender =
#line 1354
            TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
#line 1355
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 1356
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 1358
            .species = SPECIES_SLOWPOKE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1360
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
#line 1359
            .lvl = 20,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 1362
            .species = SPECIES_SLOWPOKE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1364
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
#line 1363
            .lvl = 20,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 1366
            .species = SPECIES_SLOWPOKE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1368
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
#line 1367
            .lvl = 20,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 1370
    [DIFFICULTY_NORMAL][TRAINER_POKEMANIAC_STEVE] =
    {
#line 1371
        .trainerName = _("STEVE"),
#line 1372
        .trainerClass = TRAINER_CLASS_POKEMANIAC,
#line 1373
        .trainerPic = TRAINER_PIC_POKEMANIAC,
        .encounterMusic_gender =
#line 1375
            TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
#line 1376
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 1377
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 1379
            .species = SPECIES_CHARMANDER,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1381
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
#line 1380
            .lvl = 22,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 1383
            .species = SPECIES_CUBONE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1385
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
#line 1384
            .lvl = 22,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 1387
    [DIFFICULTY_NORMAL][TRAINER_POKEMANIAC_WINSTON] =
    {
#line 1388
        .trainerName = _("WINSTON"),
#line 1389
        .trainerClass = TRAINER_CLASS_POKEMANIAC,
#line 1390
        .trainerPic = TRAINER_PIC_POKEMANIAC,
        .encounterMusic_gender =
#line 1392
            TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
#line 1393
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 1394
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 1396
            .species = SPECIES_SLOWPOKE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1398
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
#line 1397
            .lvl = 25,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 1400
    [DIFFICULTY_NORMAL][TRAINER_POKEMANIAC_DAWSON] =
    {
#line 1401
        .trainerName = _("DAWSON"),
#line 1402
        .trainerClass = TRAINER_CLASS_POKEMANIAC,
#line 1403
        .trainerPic = TRAINER_PIC_POKEMANIAC,
        .encounterMusic_gender =
#line 1405
            TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
#line 1406
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 1407
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 1409
            .species = SPECIES_CHARMELEON,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1411
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
#line 1410
            .lvl = 40,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 1413
            .species = SPECIES_LAPRAS,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1415
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
#line 1414
            .lvl = 40,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 1417
            .species = SPECIES_LICKITUNG,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1419
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
#line 1418
            .lvl = 40,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 1421
    [DIFFICULTY_NORMAL][TRAINER_POKEMANIAC_ASHTON] =
    {
#line 1422
        .trainerName = _("ASHTON"),
#line 1423
        .trainerClass = TRAINER_CLASS_POKEMANIAC,
#line 1424
        .trainerPic = TRAINER_PIC_POKEMANIAC,
        .encounterMusic_gender =
#line 1426
            TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
#line 1427
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 1428
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 1430
            .species = SPECIES_CUBONE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1432
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
#line 1431
            .lvl = 23,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 1434
            .species = SPECIES_SLOWPOKE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1436
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
#line 1435
            .lvl = 23,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 1438
    [DIFFICULTY_NORMAL][TRAINER_SUPER_NERD_JOVAN] =
    {
#line 1439
        .trainerName = _("JOVAN"),
#line 1440
        .trainerClass = TRAINER_CLASS_SUPER_NERD,
#line 1441
        .trainerPic = TRAINER_PIC_SUPER_NERD,
        .encounterMusic_gender =
#line 1443
            TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
#line 1444
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 1445
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 1447
            .species = SPECIES_MAGNEMITE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1449
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 1448
            .lvl = 11,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 1451
            .species = SPECIES_VOLTORB,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1453
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 1452
            .lvl = 11,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 1455
    [DIFFICULTY_NORMAL][TRAINER_SUPER_NERD_MIGUEL] =
    {
#line 1456
        .trainerName = _("MIGUEL"),
#line 1457
        .trainerClass = TRAINER_CLASS_SUPER_NERD,
#line 1458
        .trainerPic = TRAINER_PIC_SUPER_NERD,
        .encounterMusic_gender =
#line 1460
            TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
#line 1461
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 1462
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 1464
            .species = SPECIES_GRIMER,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1466
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 1465
            .lvl = 12,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 1468
            .species = SPECIES_VOLTORB,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1470
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 1469
            .lvl = 12,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 1472
            .species = SPECIES_KOFFING,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1474
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 1473
            .lvl = 12,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 1476
    [DIFFICULTY_NORMAL][TRAINER_SUPER_NERD_AIDAN] =
    {
#line 1477
        .trainerName = _("AIDAN"),
#line 1478
        .trainerClass = TRAINER_CLASS_SUPER_NERD,
#line 1479
        .trainerPic = TRAINER_PIC_SUPER_NERD,
        .encounterMusic_gender =
#line 1481
            TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
#line 1482
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 1483
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 4,
        .party = (const struct TrainerMon[])
        {
            {
#line 1485
            .species = SPECIES_VOLTORB,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1487
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 1486
            .lvl = 20,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 1488
                MOVE_SONIC_BOOM,
                MOVE_SCREECH,
                MOVE_TACKLE,
                MOVE_CHARGE,
            },
            },
            {
#line 1493
            .species = SPECIES_KOFFING,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1495
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 1494
            .lvl = 20,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 1496
                MOVE_SLUDGE,
                MOVE_SMOG,
                MOVE_TACKLE,
                MOVE_POISON_GAS,
            },
            },
            {
#line 1501
            .species = SPECIES_VOLTORB,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1503
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 1502
            .lvl = 20,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 1504
                MOVE_SONIC_BOOM,
                MOVE_SCREECH,
                MOVE_TACKLE,
                MOVE_CHARGE,
            },
            },
            {
#line 1509
            .species = SPECIES_MAGNEMITE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1511
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 1510
            .lvl = 20,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 1512
                MOVE_SONIC_BOOM,
                MOVE_SUPERSONIC,
                MOVE_THUNDER_SHOCK,
                MOVE_TACKLE,
            },
            },
        },
    },
#line 1517
    [DIFFICULTY_NORMAL][TRAINER_SUPER_NERD_GLENN] =
    {
#line 1518
        .trainerName = _("GLENN"),
#line 1519
        .trainerClass = TRAINER_CLASS_SUPER_NERD,
#line 1520
        .trainerPic = TRAINER_PIC_SUPER_NERD,
        .encounterMusic_gender =
#line 1522
            TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
#line 1523
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 1524
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 1526
            .species = SPECIES_GRIMER,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1528
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 1527
            .lvl = 22,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 1530
            .species = SPECIES_MUK,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1532
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 1531
            .lvl = 22,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 1534
            .species = SPECIES_GRIMER,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1536
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 1535
            .lvl = 22,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 1538
    [DIFFICULTY_NORMAL][TRAINER_SUPER_NERD_LESLIE] =
    {
#line 1539
        .trainerName = _("LESLIE"),
#line 1540
        .trainerClass = TRAINER_CLASS_SUPER_NERD,
#line 1541
        .trainerPic = TRAINER_PIC_SUPER_NERD,
        .encounterMusic_gender =
#line 1543
            TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
#line 1544
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 1545
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 1547
            .species = SPECIES_KOFFING,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1549
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 1548
            .lvl = 26,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 1550
                MOVE_SLUDGE,
                MOVE_SMOKESCREEN,
                MOVE_SMOG,
                MOVE_SELF_DESTRUCT,
            },
            },
        },
    },
#line 1555
    [DIFFICULTY_NORMAL][TRAINER_SUPER_NERD_1] =
    {
#line 1556
        .trainerName = _("PH"),
#line 1557
        .trainerClass = TRAINER_CLASS_SUPER_NERD,
#line 1558
        .trainerPic = TRAINER_PIC_SUPER_NERD,
        .encounterMusic_gender =
#line 1560
            TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
#line 1561
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 1562
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 1564
            .species = SPECIES_KOFFING,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1566
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 1565
            .lvl = 22,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 1568
            .species = SPECIES_MAGNEMITE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1570
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 1569
            .lvl = 22,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 1572
            .species = SPECIES_WEEZING,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1574
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 1573
            .lvl = 22,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 1576
    [DIFFICULTY_NORMAL][TRAINER_SUPER_NERD_2] =
    {
#line 1577
        .trainerName = _("PH"),
#line 1578
        .trainerClass = TRAINER_CLASS_SUPER_NERD,
#line 1579
        .trainerPic = TRAINER_PIC_SUPER_NERD,
        .encounterMusic_gender =
#line 1581
            TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
#line 1582
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 1583
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 4,
        .party = (const struct TrainerMon[])
        {
            {
#line 1585
            .species = SPECIES_MAGNEMITE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1587
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 1586
            .lvl = 20,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 1589
            .species = SPECIES_MAGNEMITE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1591
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 1590
            .lvl = 20,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 1593
            .species = SPECIES_KOFFING,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1595
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 1594
            .lvl = 20,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 1597
            .species = SPECIES_MAGNEMITE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1599
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 1598
            .lvl = 20,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 1601
    [DIFFICULTY_NORMAL][TRAINER_SUPER_NERD_3] =
    {
#line 1602
        .trainerName = _("PH"),
#line 1603
        .trainerClass = TRAINER_CLASS_SUPER_NERD,
#line 1604
        .trainerPic = TRAINER_PIC_SUPER_NERD,
        .encounterMusic_gender =
#line 1606
            TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
#line 1607
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 1608
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 1610
            .species = SPECIES_MAGNEMITE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1612
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 1611
            .lvl = 24,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 1614
            .species = SPECIES_VOLTORB,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1616
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 1615
            .lvl = 24,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 1618
    [DIFFICULTY_NORMAL][TRAINER_SUPER_NERD_ERIK] =
    {
#line 1619
        .trainerName = _("ERIK"),
#line 1620
        .trainerClass = TRAINER_CLASS_SUPER_NERD,
#line 1621
        .trainerPic = TRAINER_PIC_SUPER_NERD,
        .encounterMusic_gender =
#line 1623
            TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
#line 1624
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 1625
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 1627
            .species = SPECIES_VULPIX,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1629
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 1628
            .lvl = 36,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 1631
            .species = SPECIES_VULPIX,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1633
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 1632
            .lvl = 36,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 1635
            .species = SPECIES_NINETALES,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1637
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 1636
            .lvl = 36,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 1639
    [DIFFICULTY_NORMAL][TRAINER_SUPER_NERD_AVERY] =
    {
#line 1640
        .trainerName = _("AVERY"),
#line 1641
        .trainerClass = TRAINER_CLASS_SUPER_NERD,
#line 1642
        .trainerPic = TRAINER_PIC_SUPER_NERD,
        .encounterMusic_gender =
#line 1644
            TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
#line 1645
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 1646
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 4,
        .party = (const struct TrainerMon[])
        {
            {
#line 1648
            .species = SPECIES_PONYTA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1650
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 1649
            .lvl = 34,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 1652
            .species = SPECIES_CHARMANDER,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1654
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 1653
            .lvl = 34,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 1656
            .species = SPECIES_VULPIX,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1658
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 1657
            .lvl = 34,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 1660
            .species = SPECIES_GROWLITHE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1662
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 1661
            .lvl = 34,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 1664
    [DIFFICULTY_NORMAL][TRAINER_SUPER_NERD_DEREK] =
    {
#line 1665
        .trainerName = _("DEREK"),
#line 1666
        .trainerClass = TRAINER_CLASS_SUPER_NERD,
#line 1667
        .trainerPic = TRAINER_PIC_SUPER_NERD,
        .encounterMusic_gender =
#line 1669
            TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
#line 1670
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 1671
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 1673
            .species = SPECIES_RAPIDASH,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1675
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 1674
            .lvl = 41,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 1677
    [DIFFICULTY_NORMAL][TRAINER_SUPER_NERD_ZAC] =
    {
#line 1678
        .trainerName = _("ZAC"),
#line 1679
        .trainerClass = TRAINER_CLASS_SUPER_NERD,
#line 1680
        .trainerPic = TRAINER_PIC_SUPER_NERD,
        .encounterMusic_gender =
#line 1682
            TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
#line 1683
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 1684
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 1686
            .species = SPECIES_GROWLITHE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1688
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 1687
            .lvl = 37,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 1690
            .species = SPECIES_VULPIX,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1692
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 1691
            .lvl = 37,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 1694
    [DIFFICULTY_NORMAL][TRAINER_HIKER_MARCOS] =
    {
#line 1695
        .trainerName = _("MARCOS"),
#line 1696
        .trainerClass = TRAINER_CLASS_HIKER,
#line 1697
        .trainerPic = TRAINER_PIC_HIKER,
        .encounterMusic_gender =
#line 1699
            TRAINER_ENCOUNTER_MUSIC_HIKER,
#line 1700
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 1701
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 1703
            .species = SPECIES_GEODUDE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1705
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 1704
            .lvl = 10,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 1707
            .species = SPECIES_GEODUDE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1709
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 1708
            .lvl = 10,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 1711
            .species = SPECIES_ONIX,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1713
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 1712
            .lvl = 10,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 1715
    [DIFFICULTY_NORMAL][TRAINER_HIKER_FRANKLIN] =
    {
#line 1716
        .trainerName = _("FRANKLIN"),
#line 1717
        .trainerClass = TRAINER_CLASS_HIKER,
#line 1718
        .trainerPic = TRAINER_PIC_HIKER,
        .encounterMusic_gender =
#line 1720
            TRAINER_ENCOUNTER_MUSIC_HIKER,
#line 1721
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 1722
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 1724
            .species = SPECIES_MACHOP,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1726
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 1725
            .lvl = 15,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 1728
            .species = SPECIES_GEODUDE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1730
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 1729
            .lvl = 15,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 1732
    [DIFFICULTY_NORMAL][TRAINER_HIKER_NOB] =
    {
#line 1733
        .trainerName = _("NOB"),
#line 1734
        .trainerClass = TRAINER_CLASS_HIKER,
#line 1735
        .trainerPic = TRAINER_PIC_HIKER,
        .encounterMusic_gender =
#line 1737
            TRAINER_ENCOUNTER_MUSIC_HIKER,
#line 1738
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 1739
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 4,
        .party = (const struct TrainerMon[])
        {
            {
#line 1741
            .species = SPECIES_GEODUDE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1743
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 1742
            .lvl = 13,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 1745
            .species = SPECIES_GEODUDE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1747
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 1746
            .lvl = 13,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 1749
            .species = SPECIES_MACHOP,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1751
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 1750
            .lvl = 13,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 1753
            .species = SPECIES_GEODUDE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1755
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 1754
            .lvl = 13,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 1757
    [DIFFICULTY_NORMAL][TRAINER_HIKER_WAYNE] =
    {
#line 1758
        .trainerName = _("WAYNE"),
#line 1759
        .trainerClass = TRAINER_CLASS_HIKER,
#line 1760
        .trainerPic = TRAINER_PIC_HIKER,
        .encounterMusic_gender =
#line 1762
            TRAINER_ENCOUNTER_MUSIC_HIKER,
#line 1763
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 1764
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 1766
            .species = SPECIES_ONIX,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1768
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 1767
            .lvl = 17,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 1770
    [DIFFICULTY_NORMAL][TRAINER_HIKER_ALAN] =
    {
#line 1771
        .trainerName = _("ALAN"),
#line 1772
        .trainerClass = TRAINER_CLASS_HIKER,
#line 1773
        .trainerPic = TRAINER_PIC_HIKER,
        .encounterMusic_gender =
#line 1775
            TRAINER_ENCOUNTER_MUSIC_HIKER,
#line 1776
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 1777
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 1779
            .species = SPECIES_GEODUDE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1781
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 1780
            .lvl = 21,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 1782
                MOVE_MAGNITUDE,
                MOVE_ROCK_THROW,
                MOVE_MUD_SPORT,
                MOVE_DEFENSE_CURL,
            },
            },
            {
#line 1787
            .species = SPECIES_ONIX,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1789
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 1788
            .lvl = 21,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 1790
                MOVE_HARDEN,
                MOVE_ROCK_THROW,
                MOVE_BIND,
                MOVE_SCREECH,
            },
            },
        },
    },
#line 1795
    [DIFFICULTY_NORMAL][TRAINER_HIKER_BRICE] =
    {
#line 1796
        .trainerName = _("BRICE"),
#line 1797
        .trainerClass = TRAINER_CLASS_HIKER,
#line 1798
        .trainerPic = TRAINER_PIC_HIKER,
        .encounterMusic_gender =
#line 1800
            TRAINER_ENCOUNTER_MUSIC_HIKER,
#line 1801
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 1802
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 1804
            .species = SPECIES_GEODUDE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1806
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 1805
            .lvl = 20,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 1808
            .species = SPECIES_MACHOP,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1810
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 1809
            .lvl = 20,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 1812
            .species = SPECIES_GEODUDE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1814
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 1813
            .lvl = 20,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 1816
    [DIFFICULTY_NORMAL][TRAINER_HIKER_CLARK] =
    {
#line 1817
        .trainerName = _("CLARK"),
#line 1818
        .trainerClass = TRAINER_CLASS_HIKER,
#line 1819
        .trainerPic = TRAINER_PIC_HIKER,
        .encounterMusic_gender =
#line 1821
            TRAINER_ENCOUNTER_MUSIC_HIKER,
#line 1822
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 1823
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 1825
            .species = SPECIES_GEODUDE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1827
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 1826
            .lvl = 21,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 1828
                MOVE_MAGNITUDE,
                MOVE_ROCK_THROW,
                MOVE_MUD_SPORT,
                MOVE_DEFENSE_CURL,
            },
            },
            {
#line 1833
            .species = SPECIES_ONIX,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1835
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 1834
            .lvl = 21,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 1836
                MOVE_HARDEN,
                MOVE_ROCK_THROW,
                MOVE_BIND,
                MOVE_SCREECH,
            },
            },
        },
    },
#line 1841
    [DIFFICULTY_NORMAL][TRAINER_HIKER_TRENT] =
    {
#line 1842
        .trainerName = _("TRENT"),
#line 1843
        .trainerClass = TRAINER_CLASS_HIKER,
#line 1844
        .trainerPic = TRAINER_PIC_HIKER,
        .encounterMusic_gender =
#line 1846
            TRAINER_ENCOUNTER_MUSIC_HIKER,
#line 1847
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 1848
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 1850
            .species = SPECIES_ONIX,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1852
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 1851
            .lvl = 19,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 1854
            .species = SPECIES_GRAVELER,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1856
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 1855
            .lvl = 19,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 1858
    [DIFFICULTY_NORMAL][TRAINER_HIKER_DUDLEY] =
    {
#line 1859
        .trainerName = _("DUDLEY"),
#line 1860
        .trainerClass = TRAINER_CLASS_HIKER,
#line 1861
        .trainerPic = TRAINER_PIC_HIKER,
        .encounterMusic_gender =
#line 1863
            TRAINER_ENCOUNTER_MUSIC_HIKER,
#line 1864
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 1865
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 1867
            .species = SPECIES_GEODUDE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1869
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 1868
            .lvl = 21,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 1870
                MOVE_MAGNITUDE,
                MOVE_ROCK_THROW,
                MOVE_MUD_SPORT,
                MOVE_DEFENSE_CURL,
            },
            },
            {
#line 1875
            .species = SPECIES_GEODUDE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1877
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 1876
            .lvl = 21,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 1878
                MOVE_MAGNITUDE,
                MOVE_ROCK_THROW,
                MOVE_MUD_SPORT,
                MOVE_DEFENSE_CURL,
            },
            },
            {
#line 1883
            .species = SPECIES_GRAVELER,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1885
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 1884
            .lvl = 21,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 1886
                MOVE_MAGNITUDE,
                MOVE_ROCK_THROW,
                MOVE_MUD_SPORT,
                MOVE_DEFENSE_CURL,
            },
            },
        },
    },
#line 1891
    [DIFFICULTY_NORMAL][TRAINER_HIKER_ALLEN] =
    {
#line 1892
        .trainerName = _("ALLEN"),
#line 1893
        .trainerClass = TRAINER_CLASS_HIKER,
#line 1894
        .trainerPic = TRAINER_PIC_HIKER,
        .encounterMusic_gender =
#line 1896
            TRAINER_ENCOUNTER_MUSIC_HIKER,
#line 1897
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 1898
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 1900
            .species = SPECIES_GEODUDE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1902
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 1901
            .lvl = 25,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 1903
                MOVE_MAGNITUDE,
                MOVE_ROCK_THROW,
                MOVE_MUD_SPORT,
                MOVE_DEFENSE_CURL,
            },
            },
        },
    },
#line 1908
    [DIFFICULTY_NORMAL][TRAINER_HIKER_ERIC] =
    {
#line 1909
        .trainerName = _("ERIC"),
#line 1910
        .trainerClass = TRAINER_CLASS_HIKER,
#line 1911
        .trainerPic = TRAINER_PIC_HIKER,
        .encounterMusic_gender =
#line 1913
            TRAINER_ENCOUNTER_MUSIC_HIKER,
#line 1914
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 1915
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 1917
            .species = SPECIES_MACHOP,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1919
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 1918
            .lvl = 20,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 1921
            .species = SPECIES_ONIX,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1923
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 1922
            .lvl = 20,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 1925
    [DIFFICULTY_NORMAL][TRAINER_HIKER_LENNY] =
    {
#line 1926
        .trainerName = _("LENNY"),
#line 1927
        .trainerClass = TRAINER_CLASS_HIKER,
#line 1928
        .trainerPic = TRAINER_PIC_HIKER,
        .encounterMusic_gender =
#line 1930
            TRAINER_ENCOUNTER_MUSIC_HIKER,
#line 1931
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 1932
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 4,
        .party = (const struct TrainerMon[])
        {
            {
#line 1934
            .species = SPECIES_GEODUDE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1936
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 1935
            .lvl = 19,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 1938
            .species = SPECIES_MACHOP,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1940
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 1939
            .lvl = 19,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 1942
            .species = SPECIES_GEODUDE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1944
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 1943
            .lvl = 19,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 1946
            .species = SPECIES_GEODUDE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1948
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 1947
            .lvl = 19,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 1950
    [DIFFICULTY_NORMAL][TRAINER_HIKER_OLIVER] =
    {
#line 1951
        .trainerName = _("OLIVER"),
#line 1952
        .trainerClass = TRAINER_CLASS_HIKER,
#line 1953
        .trainerPic = TRAINER_PIC_HIKER,
        .encounterMusic_gender =
#line 1955
            TRAINER_ENCOUNTER_MUSIC_HIKER,
#line 1956
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 1957
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 1959
            .species = SPECIES_ONIX,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1961
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 1960
            .lvl = 20,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 1963
            .species = SPECIES_ONIX,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1965
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 1964
            .lvl = 20,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 1967
            .species = SPECIES_GEODUDE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1969
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 1968
            .lvl = 20,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 1971
    [DIFFICULTY_NORMAL][TRAINER_HIKER_LUCAS] =
    {
#line 1972
        .trainerName = _("LUCAS"),
#line 1973
        .trainerClass = TRAINER_CLASS_HIKER,
#line 1974
        .trainerPic = TRAINER_PIC_HIKER,
        .encounterMusic_gender =
#line 1976
            TRAINER_ENCOUNTER_MUSIC_HIKER,
#line 1977
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 1978
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 1980
            .species = SPECIES_GEODUDE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1982
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 1981
            .lvl = 21,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 1983
                MOVE_MAGNITUDE,
                MOVE_ROCK_THROW,
                MOVE_MUD_SPORT,
                MOVE_DEFENSE_CURL,
            },
            },
            {
#line 1988
            .species = SPECIES_GRAVELER,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1990
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 1989
            .lvl = 21,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 1991
                MOVE_MAGNITUDE,
                MOVE_ROCK_THROW,
                MOVE_MUD_SPORT,
                MOVE_DEFENSE_CURL,
            },
            },
        },
    },
#line 1996
    [DIFFICULTY_NORMAL][TRAINER_BIKER_JARED] =
    {
#line 1997
        .trainerName = _("JARED"),
#line 1998
        .trainerClass = TRAINER_CLASS_BIKER,
#line 1999
        .trainerPic = TRAINER_PIC_BIKER,
        .encounterMusic_gender =
#line 2001
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 2002
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 2003
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 2005
            .species = SPECIES_KOFFING,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2007
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 2006
            .lvl = 28,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 2008
                MOVE_SMOKESCREEN,
                MOVE_SLUDGE,
                MOVE_SMOG,
                MOVE_POISON_GAS,
            },
            },
            {
#line 2013
            .species = SPECIES_KOFFING,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2015
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 2014
            .lvl = 28,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 2016
                MOVE_SMOKESCREEN,
                MOVE_SLUDGE,
                MOVE_SMOG,
                MOVE_TACKLE,
            },
            },
            {
#line 2021
            .species = SPECIES_KOFFING,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2023
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 2022
            .lvl = 28,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 2024
                MOVE_SMOKESCREEN,
                MOVE_SLUDGE,
                MOVE_SMOG,
                MOVE_TACKLE,
            },
            },
        },
    },
#line 2029
    [DIFFICULTY_NORMAL][TRAINER_BIKER_MALIK] =
    {
#line 2030
        .trainerName = _("MALIK"),
#line 2031
        .trainerClass = TRAINER_CLASS_BIKER,
#line 2032
        .trainerPic = TRAINER_PIC_BIKER,
        .encounterMusic_gender =
#line 2034
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 2035
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 2036
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 2038
            .species = SPECIES_KOFFING,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2040
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 2039
            .lvl = 29,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 2041
                MOVE_SMOKESCREEN,
                MOVE_SLUDGE,
                MOVE_SMOG,
                MOVE_TACKLE,
            },
            },
            {
#line 2046
            .species = SPECIES_GRIMER,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2048
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 2047
            .lvl = 29,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 2049
                MOVE_SCREECH,
                MOVE_MINIMIZE,
                MOVE_SLUDGE,
                MOVE_DISABLE,
            },
            },
        },
    },
#line 2054
    [DIFFICULTY_NORMAL][TRAINER_BIKER_ERNEST] =
    {
#line 2055
        .trainerName = _("ERNEST"),
#line 2056
        .trainerClass = TRAINER_CLASS_BIKER,
#line 2057
        .trainerPic = TRAINER_PIC_BIKER,
        .encounterMusic_gender =
#line 2059
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 2060
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 2061
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 5,
        .party = (const struct TrainerMon[])
        {
            {
#line 2063
            .species = SPECIES_KOFFING,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2065
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 2064
            .lvl = 25,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 2066
                MOVE_SMOKESCREEN,
                MOVE_SLUDGE,
                MOVE_SMOG,
                MOVE_TACKLE,
            },
            },
            {
#line 2071
            .species = SPECIES_KOFFING,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2073
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 2072
            .lvl = 25,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 2074
                MOVE_SMOKESCREEN,
                MOVE_SLUDGE,
                MOVE_SMOG,
                MOVE_TACKLE,
            },
            },
            {
#line 2079
            .species = SPECIES_WEEZING,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2081
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 2080
            .lvl = 25,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 2082
                MOVE_SMOKESCREEN,
                MOVE_SLUDGE,
                MOVE_SMOG,
                MOVE_TACKLE,
            },
            },
            {
#line 2087
            .species = SPECIES_KOFFING,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2089
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 2088
            .lvl = 25,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 2090
                MOVE_SMOKESCREEN,
                MOVE_SLUDGE,
                MOVE_SMOG,
                MOVE_TACKLE,
            },
            },
            {
#line 2095
            .species = SPECIES_GRIMER,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2097
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 2096
            .lvl = 25,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 2098
                MOVE_MINIMIZE,
                MOVE_SLUDGE,
                MOVE_DISABLE,
                MOVE_POUND,
            },
            },
        },
    },
#line 2103
    [DIFFICULTY_NORMAL][TRAINER_BIKER_ALEX] =
    {
#line 2104
        .trainerName = _("ALEX"),
#line 2105
        .trainerClass = TRAINER_CLASS_BIKER,
#line 2106
        .trainerPic = TRAINER_PIC_BIKER,
        .encounterMusic_gender =
#line 2108
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 2109
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 2110
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 2112
            .species = SPECIES_KOFFING,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2114
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 2113
            .lvl = 28,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 2115
                MOVE_SMOKESCREEN,
                MOVE_SLUDGE,
                MOVE_SMOG,
                MOVE_TACKLE,
            },
            },
            {
#line 2120
            .species = SPECIES_GRIMER,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2122
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 2121
            .lvl = 28,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 2123
                MOVE_SCREECH,
                MOVE_MINIMIZE,
                MOVE_SLUDGE,
                MOVE_DISABLE,
            },
            },
            {
#line 2128
            .species = SPECIES_WEEZING,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2130
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 2129
            .lvl = 28,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 2131
                MOVE_SMOKESCREEN,
                MOVE_SLUDGE,
                MOVE_SMOG,
                MOVE_TACKLE,
            },
            },
        },
    },
#line 2136
    [DIFFICULTY_NORMAL][TRAINER_BIKER_LAO] =
    {
#line 2137
        .trainerName = _("LAO"),
#line 2138
        .trainerClass = TRAINER_CLASS_BIKER,
#line 2139
        .trainerPic = TRAINER_PIC_BIKER,
        .encounterMusic_gender =
#line 2141
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 2142
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 2143
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 2145
            .species = SPECIES_GRIMER,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2147
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 2146
            .lvl = 29,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 2148
                MOVE_SCREECH,
                MOVE_MINIMIZE,
                MOVE_SLUDGE,
                MOVE_DISABLE,
            },
            },
            {
#line 2153
            .species = SPECIES_KOFFING,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2155
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 2154
            .lvl = 29,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 2156
                MOVE_SMOKESCREEN,
                MOVE_SLUDGE,
                MOVE_SMOG,
                MOVE_TACKLE,
            },
            },
        },
    },
#line 2161
    [DIFFICULTY_NORMAL][TRAINER_BIKER_1] =
    {
#line 2162
        .trainerName = _("PH"),
#line 2163
        .trainerClass = TRAINER_CLASS_BIKER,
#line 2164
        .trainerPic = TRAINER_PIC_BIKER,
        .encounterMusic_gender =
#line 2166
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 2167
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 2168
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 2170
            .species = SPECIES_EKANS,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2172
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 2171
            .lvl = 5,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 2174
    [DIFFICULTY_NORMAL][TRAINER_BIKER_HIDEO] =
    {
#line 2175
        .trainerName = _("HIDEO"),
#line 2176
        .trainerClass = TRAINER_CLASS_BIKER,
#line 2177
        .trainerPic = TRAINER_PIC_BIKER,
        .encounterMusic_gender =
#line 2179
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 2180
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 2181
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 2183
            .species = SPECIES_WEEZING,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2185
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 2184
            .lvl = 33,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 2187
    [DIFFICULTY_NORMAL][TRAINER_BIKER_RUBEN] =
    {
#line 2188
        .trainerName = _("RUBEN"),
#line 2189
        .trainerClass = TRAINER_CLASS_BIKER,
#line 2190
        .trainerPic = TRAINER_PIC_BIKER,
        .encounterMusic_gender =
#line 2192
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 2193
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 2194
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 2196
            .species = SPECIES_WEEZING,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2198
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 2197
            .lvl = 28,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 2199
                MOVE_SMOKESCREEN,
                MOVE_SLUDGE,
                MOVE_SMOG,
                MOVE_TACKLE,
            },
            },
            {
#line 2204
            .species = SPECIES_KOFFING,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2206
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 2205
            .lvl = 28,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 2207
                MOVE_SMOKESCREEN,
                MOVE_SLUDGE,
                MOVE_SMOG,
                MOVE_TACKLE,
            },
            },
            {
#line 2212
            .species = SPECIES_WEEZING,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2214
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 2213
            .lvl = 28,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 2215
                MOVE_SMOKESCREEN,
                MOVE_SLUDGE,
                MOVE_SMOG,
                MOVE_TACKLE,
            },
            },
        },
    },
#line 2220
    [DIFFICULTY_NORMAL][TRAINER_BIKER_BILLY] =
    {
#line 2221
        .trainerName = _("BILLY"),
#line 2222
        .trainerClass = TRAINER_CLASS_BIKER,
#line 2223
        .trainerPic = TRAINER_PIC_BIKER,
        .encounterMusic_gender =
#line 2225
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 2226
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 2227
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 2229
            .species = SPECIES_MUK,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2231
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 2230
            .lvl = 33,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 2233
    [DIFFICULTY_NORMAL][TRAINER_BIKER_NIKOLAS] =
    {
#line 2234
        .trainerName = _("NIKOLAS"),
#line 2235
        .trainerClass = TRAINER_CLASS_BIKER,
#line 2236
        .trainerPic = TRAINER_PIC_BIKER,
        .encounterMusic_gender =
#line 2238
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 2239
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 2240
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 2242
            .species = SPECIES_VOLTORB,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2244
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 2243
            .lvl = 29,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 2245
                MOVE_SPARK,
                MOVE_SONIC_BOOM,
                MOVE_SCREECH,
                MOVE_CHARGE,
            },
            },
            {
#line 2250
            .species = SPECIES_VOLTORB,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2252
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 2251
            .lvl = 29,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 2253
                MOVE_SPARK,
                MOVE_SONIC_BOOM,
                MOVE_SCREECH,
                MOVE_CHARGE,
            },
            },
        },
    },
#line 2258
    [DIFFICULTY_NORMAL][TRAINER_BIKER_JAXON] =
    {
#line 2259
        .trainerName = _("JAXON"),
#line 2260
        .trainerClass = TRAINER_CLASS_BIKER,
#line 2261
        .trainerPic = TRAINER_PIC_BIKER,
        .encounterMusic_gender =
#line 2263
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 2264
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 2265
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 2267
            .species = SPECIES_WEEZING,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2269
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 2268
            .lvl = 29,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 2270
                MOVE_SLUDGE,
                MOVE_SMOKESCREEN,
                MOVE_SMOG,
                MOVE_TACKLE,
            },
            },
            {
#line 2275
            .species = SPECIES_MUK,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2277
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 2276
            .lvl = 29,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 2278
                MOVE_SCREECH,
                MOVE_MINIMIZE,
                MOVE_SLUDGE,
                MOVE_DISABLE,
            },
            },
        },
    },
#line 2283
    [DIFFICULTY_NORMAL][TRAINER_BIKER_WILLIAM] =
    {
#line 2284
        .trainerName = _("WILLIAM"),
#line 2285
        .trainerClass = TRAINER_CLASS_BIKER,
#line 2286
        .trainerPic = TRAINER_PIC_BIKER,
        .encounterMusic_gender =
#line 2288
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 2289
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 2290
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 5,
        .party = (const struct TrainerMon[])
        {
            {
#line 2292
            .species = SPECIES_KOFFING,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2294
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 2293
            .lvl = 25,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 2295
                MOVE_SMOKESCREEN,
                MOVE_SLUDGE,
                MOVE_SMOG,
                MOVE_TACKLE,
            },
            },
            {
#line 2300
            .species = SPECIES_WEEZING,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2302
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 2301
            .lvl = 25,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 2303
                MOVE_SMOKESCREEN,
                MOVE_SLUDGE,
                MOVE_SMOG,
                MOVE_TACKLE,
            },
            },
            {
#line 2308
            .species = SPECIES_KOFFING,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2310
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 2309
            .lvl = 25,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 2311
                MOVE_SMOKESCREEN,
                MOVE_SLUDGE,
                MOVE_SMOG,
                MOVE_TACKLE,
            },
            },
            {
#line 2316
            .species = SPECIES_KOFFING,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2318
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 2317
            .lvl = 25,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 2319
                MOVE_SMOKESCREEN,
                MOVE_SLUDGE,
                MOVE_SMOG,
                MOVE_TACKLE,
            },
            },
            {
#line 2324
            .species = SPECIES_WEEZING,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2326
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 2325
            .lvl = 25,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 2327
                MOVE_SMOKESCREEN,
                MOVE_SLUDGE,
                MOVE_SELF_DESTRUCT,
                MOVE_TACKLE,
            },
            },
        },
    },
#line 2332
    [DIFFICULTY_NORMAL][TRAINER_BIKER_LUKAS] =
    {
#line 2333
        .trainerName = _("LUKAS"),
#line 2334
        .trainerClass = TRAINER_CLASS_BIKER,
#line 2335
        .trainerPic = TRAINER_PIC_BIKER,
        .encounterMusic_gender =
#line 2337
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 2338
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 2339
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 4,
        .party = (const struct TrainerMon[])
        {
            {
#line 2341
            .species = SPECIES_KOFFING,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2343
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 2342
            .lvl = 26,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 2344
                MOVE_SMOKESCREEN,
                MOVE_SLUDGE,
                MOVE_SMOG,
                MOVE_TACKLE,
            },
            },
            {
#line 2349
            .species = SPECIES_KOFFING,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2351
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 2350
            .lvl = 26,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 2352
                MOVE_SMOKESCREEN,
                MOVE_SLUDGE,
                MOVE_SMOG,
                MOVE_TACKLE,
            },
            },
            {
#line 2357
            .species = SPECIES_GRIMER,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2359
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 2358
            .lvl = 26,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 2360
                MOVE_SCREECH,
                MOVE_MINIMIZE,
                MOVE_SLUDGE,
                MOVE_DISABLE,
            },
            },
            {
#line 2365
            .species = SPECIES_KOFFING,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2367
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 2366
            .lvl = 26,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 2368
                MOVE_SMOKESCREEN,
                MOVE_SLUDGE,
                MOVE_SMOG,
                MOVE_TACKLE,
            },
            },
        },
    },
#line 2373
    [DIFFICULTY_NORMAL][TRAINER_BIKER_ISAAC] =
    {
#line 2374
        .trainerName = _("ISAAC"),
#line 2375
        .trainerClass = TRAINER_CLASS_BIKER,
#line 2376
        .trainerPic = TRAINER_PIC_BIKER,
        .encounterMusic_gender =
#line 2378
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 2379
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 2380
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 2382
            .species = SPECIES_GRIMER,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2384
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 2383
            .lvl = 28,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 2385
                MOVE_SCREECH,
                MOVE_MINIMIZE,
                MOVE_SLUDGE,
                MOVE_DISABLE,
            },
            },
            {
#line 2390
            .species = SPECIES_GRIMER,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2392
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 2391
            .lvl = 28,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 2393
                MOVE_SCREECH,
                MOVE_MINIMIZE,
                MOVE_SLUDGE,
                MOVE_DISABLE,
            },
            },
            {
#line 2398
            .species = SPECIES_KOFFING,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2400
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 2399
            .lvl = 28,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 2401
                MOVE_SMOKESCREEN,
                MOVE_SLUDGE,
                MOVE_SMOG,
                MOVE_TACKLE,
            },
            },
        },
    },
#line 2406
    [DIFFICULTY_NORMAL][TRAINER_BIKER_GERALD] =
    {
#line 2407
        .trainerName = _("GERALD"),
#line 2408
        .trainerClass = TRAINER_CLASS_BIKER,
#line 2409
        .trainerPic = TRAINER_PIC_BIKER,
        .encounterMusic_gender =
#line 2411
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 2412
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 2413
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 2415
            .species = SPECIES_KOFFING,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2417
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 2416
            .lvl = 29,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 2418
                MOVE_SMOKESCREEN,
                MOVE_SLUDGE,
                MOVE_SMOG,
                MOVE_TACKLE,
            },
            },
            {
#line 2423
            .species = SPECIES_MUK,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2425
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 2424
            .lvl = 29,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 2426
                MOVE_SCREECH,
                MOVE_MINIMIZE,
                MOVE_SLUDGE,
                MOVE_DISABLE,
            },
            },
        },
    },
#line 2431
    [DIFFICULTY_NORMAL][TRAINER_BURGLAR_1] =
    {
#line 2432
        .trainerName = _("PH"),
#line 2433
        .trainerClass = TRAINER_CLASS_BURGLAR,
#line 2434
        .trainerPic = TRAINER_PIC_BURGLAR,
        .encounterMusic_gender =
#line 2436
            TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
#line 2437
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 2438
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 2440
            .species = SPECIES_GROWLITHE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2442
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 2441
            .lvl = 29,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 2444
            .species = SPECIES_VULPIX,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2446
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 2445
            .lvl = 29,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 2448
    [DIFFICULTY_NORMAL][TRAINER_BURGLAR_2] =
    {
#line 2449
        .trainerName = _("PH"),
#line 2450
        .trainerClass = TRAINER_CLASS_BURGLAR,
#line 2451
        .trainerPic = TRAINER_PIC_BURGLAR,
        .encounterMusic_gender =
#line 2453
            TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
#line 2454
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 2455
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 2457
            .species = SPECIES_GROWLITHE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2459
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 2458
            .lvl = 33,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 2461
    [DIFFICULTY_NORMAL][TRAINER_BURGLAR_3] =
    {
#line 2462
        .trainerName = _("PH"),
#line 2463
        .trainerClass = TRAINER_CLASS_BURGLAR,
#line 2464
        .trainerPic = TRAINER_PIC_BURGLAR,
        .encounterMusic_gender =
#line 2466
            TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
#line 2467
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 2468
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 2470
            .species = SPECIES_VULPIX,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2472
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 2471
            .lvl = 28,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 2474
            .species = SPECIES_CHARMANDER,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2476
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 2475
            .lvl = 28,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 2478
            .species = SPECIES_PONYTA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2480
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 2479
            .lvl = 28,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 2482
    [DIFFICULTY_NORMAL][TRAINER_BURGLAR_QUINN] =
    {
#line 2483
        .trainerName = _("QUINN"),
#line 2484
        .trainerClass = TRAINER_CLASS_BURGLAR,
#line 2485
        .trainerPic = TRAINER_PIC_BURGLAR,
        .encounterMusic_gender =
#line 2487
            TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
#line 2488
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 2489
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 2491
            .species = SPECIES_GROWLITHE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2493
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 2492
            .lvl = 36,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 2495
            .species = SPECIES_VULPIX,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2497
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 2496
            .lvl = 36,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 2499
            .species = SPECIES_NINETALES,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2501
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 2500
            .lvl = 36,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 2503
    [DIFFICULTY_NORMAL][TRAINER_BURGLAR_RAMON] =
    {
#line 2504
        .trainerName = _("RAMON"),
#line 2505
        .trainerClass = TRAINER_CLASS_BURGLAR,
#line 2506
        .trainerPic = TRAINER_PIC_BURGLAR,
        .encounterMusic_gender =
#line 2508
            TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
#line 2509
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 2510
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 2512
            .species = SPECIES_PONYTA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2514
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 2513
            .lvl = 41,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 2516
    [DIFFICULTY_NORMAL][TRAINER_BURGLAR_DUSTY] =
    {
#line 2517
        .trainerName = _("DUSTY"),
#line 2518
        .trainerClass = TRAINER_CLASS_BURGLAR,
#line 2519
        .trainerPic = TRAINER_PIC_BURGLAR,
        .encounterMusic_gender =
#line 2521
            TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
#line 2522
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 2523
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 2525
            .species = SPECIES_VULPIX,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2527
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 2526
            .lvl = 37,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 2529
            .species = SPECIES_GROWLITHE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2531
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 2530
            .lvl = 37,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 2533
    [DIFFICULTY_NORMAL][TRAINER_BURGLAR_ARNIE] =
    {
#line 2534
        .trainerName = _("ARNIE"),
#line 2535
        .trainerClass = TRAINER_CLASS_BURGLAR,
#line 2536
        .trainerPic = TRAINER_PIC_BURGLAR,
        .encounterMusic_gender =
#line 2538
            TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
#line 2539
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 2540
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 2542
            .species = SPECIES_CHARMANDER,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2544
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 2543
            .lvl = 34,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 2546
            .species = SPECIES_CHARMELEON,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2548
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 2547
            .lvl = 34,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 2550
    [DIFFICULTY_NORMAL][TRAINER_BURGLAR_4] =
    {
#line 2551
        .trainerName = _("PH"),
#line 2552
        .trainerClass = TRAINER_CLASS_BURGLAR,
#line 2553
        .trainerPic = TRAINER_PIC_BURGLAR,
        .encounterMusic_gender =
#line 2555
            TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
#line 2556
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 2557
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 2559
            .species = SPECIES_CHARMANDER,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2561
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 2560
            .lvl = 34,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 2563
            .species = SPECIES_CHARMELEON,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2565
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 2564
            .lvl = 34,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 2567
    [DIFFICULTY_NORMAL][TRAINER_BURGLAR_SIMON] =
    {
#line 2568
        .trainerName = _("SIMON"),
#line 2569
        .trainerClass = TRAINER_CLASS_BURGLAR,
#line 2570
        .trainerPic = TRAINER_PIC_BURGLAR,
        .encounterMusic_gender =
#line 2572
            TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
#line 2573
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 2574
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 2576
            .species = SPECIES_NINETALES,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2578
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 2577
            .lvl = 38,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 2580
    [DIFFICULTY_NORMAL][TRAINER_BURGLAR_LEWIS] =
    {
#line 2581
        .trainerName = _("LEWIS"),
#line 2582
        .trainerClass = TRAINER_CLASS_BURGLAR,
#line 2583
        .trainerPic = TRAINER_PIC_BURGLAR,
        .encounterMusic_gender =
#line 2585
            TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
#line 2586
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 2587
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 2589
            .species = SPECIES_GROWLITHE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2591
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 2590
            .lvl = 34,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 2593
            .species = SPECIES_PONYTA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2595
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 2594
            .lvl = 34,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 2597
    [DIFFICULTY_NORMAL][TRAINER_ENGINEER_BAILY] =
    {
#line 2598
        .trainerName = _("BAILY"),
#line 2599
        .trainerClass = TRAINER_CLASS_ENGINEER,
#line 2600
        .trainerPic = TRAINER_PIC_ENGINEER,
        .encounterMusic_gender =
#line 2602
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 2603
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 2604
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 2606
            .species = SPECIES_VOLTORB,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2608
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 2607
            .lvl = 21,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 2610
            .species = SPECIES_MAGNEMITE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2612
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 2611
            .lvl = 21,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 2614
    [DIFFICULTY_NORMAL][TRAINER_ENGINEER_BRAXTON] =
    {
#line 2615
        .trainerName = _("BRAXTON"),
#line 2616
        .trainerClass = TRAINER_CLASS_ENGINEER,
#line 2617
        .trainerPic = TRAINER_PIC_ENGINEER,
        .encounterMusic_gender =
#line 2619
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 2620
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 2621
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 2623
            .species = SPECIES_MAGNEMITE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2625
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 2624
            .lvl = 21,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 2627
    [DIFFICULTY_NORMAL][TRAINER_ENGINEER_BERNIE] =
    {
#line 2628
        .trainerName = _("BERNIE"),
#line 2629
        .trainerClass = TRAINER_CLASS_ENGINEER,
#line 2630
        .trainerPic = TRAINER_PIC_ENGINEER,
        .encounterMusic_gender =
#line 2632
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 2633
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 2634
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 2636
            .species = SPECIES_MAGNEMITE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2638
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 2637
            .lvl = 18,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 2640
            .species = SPECIES_MAGNEMITE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2642
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 2641
            .lvl = 18,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 2644
            .species = SPECIES_MAGNETON,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2646
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 2645
            .lvl = 18,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 2648
    [DIFFICULTY_NORMAL][TRAINER_FISHERMAN_DALE] =
    {
#line 2649
        .trainerName = _("DALE"),
#line 2650
        .trainerClass = TRAINER_CLASS_FISHERMAN,
#line 2651
        .trainerPic = TRAINER_PIC_FISHERMAN,
        .encounterMusic_gender =
#line 2653
            TRAINER_ENCOUNTER_MUSIC_HIKER,
#line 2654
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 2655
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 2657
            .species = SPECIES_GOLDEEN,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2659
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 2658
            .lvl = 17,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 2661
            .species = SPECIES_TENTACOOL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2663
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 2662
            .lvl = 17,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 2665
            .species = SPECIES_GOLDEEN,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2667
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 2666
            .lvl = 17,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 2669
    [DIFFICULTY_NORMAL][TRAINER_FISHERMAN_BARNY] =
    {
#line 2670
        .trainerName = _("BARNY"),
#line 2671
        .trainerClass = TRAINER_CLASS_FISHERMAN,
#line 2672
        .trainerPic = TRAINER_PIC_FISHERMAN,
        .encounterMusic_gender =
#line 2674
            TRAINER_ENCOUNTER_MUSIC_HIKER,
#line 2675
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 2676
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 2678
            .species = SPECIES_TENTACOOL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2680
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 2679
            .lvl = 17,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 2682
            .species = SPECIES_STARYU,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2684
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 2683
            .lvl = 17,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 2686
            .species = SPECIES_SHELLDER,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2688
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 2687
            .lvl = 17,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 2690
    [DIFFICULTY_NORMAL][TRAINER_FISHERMAN_NED] =
    {
#line 2691
        .trainerName = _("NED"),
#line 2692
        .trainerClass = TRAINER_CLASS_FISHERMAN,
#line 2693
        .trainerPic = TRAINER_PIC_FISHERMAN,
        .encounterMusic_gender =
#line 2695
            TRAINER_ENCOUNTER_MUSIC_HIKER,
#line 2696
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 2697
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 2699
            .species = SPECIES_GOLDEEN,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2701
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 2700
            .lvl = 22,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 2703
            .species = SPECIES_POLIWAG,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2705
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 2704
            .lvl = 22,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 2707
            .species = SPECIES_GOLDEEN,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2709
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 2708
            .lvl = 22,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 2711
    [DIFFICULTY_NORMAL][TRAINER_FISHERMAN_CHIP] =
    {
#line 2712
        .trainerName = _("CHIP"),
#line 2713
        .trainerClass = TRAINER_CLASS_FISHERMAN,
#line 2714
        .trainerPic = TRAINER_PIC_FISHERMAN,
        .encounterMusic_gender =
#line 2716
            TRAINER_ENCOUNTER_MUSIC_HIKER,
#line 2717
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 2718
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 2720
            .species = SPECIES_TENTACOOL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2722
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 2721
            .lvl = 24,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 2724
            .species = SPECIES_GOLDEEN,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2726
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 2725
            .lvl = 24,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 2728
    [DIFFICULTY_NORMAL][TRAINER_FISHERMAN_HANK] =
    {
#line 2729
        .trainerName = _("HANK"),
#line 2730
        .trainerClass = TRAINER_CLASS_FISHERMAN,
#line 2731
        .trainerPic = TRAINER_PIC_FISHERMAN,
        .encounterMusic_gender =
#line 2733
            TRAINER_ENCOUNTER_MUSIC_HIKER,
#line 2734
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 2735
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 2737
            .species = SPECIES_GOLDEEN,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2739
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 2738
            .lvl = 27,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 2741
    [DIFFICULTY_NORMAL][TRAINER_FISHERMAN_ELLIOT] =
    {
#line 2742
        .trainerName = _("ELLIOT"),
#line 2743
        .trainerClass = TRAINER_CLASS_FISHERMAN,
#line 2744
        .trainerPic = TRAINER_PIC_FISHERMAN,
        .encounterMusic_gender =
#line 2746
            TRAINER_ENCOUNTER_MUSIC_HIKER,
#line 2747
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 2748
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 4,
        .party = (const struct TrainerMon[])
        {
            {
#line 2750
            .species = SPECIES_POLIWAG,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2752
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 2751
            .lvl = 21,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 2754
            .species = SPECIES_SHELLDER,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2756
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 2755
            .lvl = 21,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 2758
            .species = SPECIES_GOLDEEN,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2760
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 2759
            .lvl = 21,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 2762
            .species = SPECIES_HORSEA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2764
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 2763
            .lvl = 21,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 2766
    [DIFFICULTY_NORMAL][TRAINER_FISHERMAN_RONALD] =
    {
#line 2767
        .trainerName = _("RONALD"),
#line 2768
        .trainerClass = TRAINER_CLASS_FISHERMAN,
#line 2769
        .trainerPic = TRAINER_PIC_FISHERMAN,
        .encounterMusic_gender =
#line 2771
            TRAINER_ENCOUNTER_MUSIC_HIKER,
#line 2772
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 2773
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 4,
        .party = (const struct TrainerMon[])
        {
            {
#line 2775
            .species = SPECIES_SEAKING,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2777
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 2776
            .lvl = 28,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 2779
            .species = SPECIES_GOLDEEN,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2781
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 2780
            .lvl = 28,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 2783
            .species = SPECIES_SEAKING,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2785
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 2784
            .lvl = 28,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 2787
            .species = SPECIES_SEAKING,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2789
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 2788
            .lvl = 28,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 2791
    [DIFFICULTY_NORMAL][TRAINER_FISHERMAN_CLAUDE] =
    {
#line 2792
        .trainerName = _("CLAUDE"),
#line 2793
        .trainerClass = TRAINER_CLASS_FISHERMAN,
#line 2794
        .trainerPic = TRAINER_PIC_FISHERMAN,
        .encounterMusic_gender =
#line 2796
            TRAINER_ENCOUNTER_MUSIC_HIKER,
#line 2797
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 2798
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 2800
            .species = SPECIES_SHELLDER,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2802
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 2801
            .lvl = 31,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 2804
            .species = SPECIES_CLOYSTER,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2806
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 2805
            .lvl = 31,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 2808
    [DIFFICULTY_NORMAL][TRAINER_FISHERMAN_WADE] =
    {
#line 2809
        .trainerName = _("WADE"),
#line 2810
        .trainerClass = TRAINER_CLASS_FISHERMAN,
#line 2811
        .trainerPic = TRAINER_PIC_FISHERMAN,
        .encounterMusic_gender =
#line 2813
            TRAINER_ENCOUNTER_MUSIC_HIKER,
#line 2814
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 2815
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 6,
        .party = (const struct TrainerMon[])
        {
            {
#line 2817
            .species = SPECIES_MAGIKARP,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2819
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 2818
            .lvl = 27,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 2821
            .species = SPECIES_MAGIKARP,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2823
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 2822
            .lvl = 27,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 2825
            .species = SPECIES_MAGIKARP,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2827
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 2826
            .lvl = 27,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 2829
            .species = SPECIES_MAGIKARP,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2831
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 2830
            .lvl = 27,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 2833
            .species = SPECIES_MAGIKARP,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2835
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 2834
            .lvl = 27,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 2837
            .species = SPECIES_MAGIKARP,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2839
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 2838
            .lvl = 27,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 2841
    [DIFFICULTY_NORMAL][TRAINER_FISHERMAN_NOLAN] =
    {
#line 2842
        .trainerName = _("NOLAN"),
#line 2843
        .trainerClass = TRAINER_CLASS_FISHERMAN,
#line 2844
        .trainerPic = TRAINER_PIC_FISHERMAN,
        .encounterMusic_gender =
#line 2846
            TRAINER_ENCOUNTER_MUSIC_HIKER,
#line 2847
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 2848
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 2850
            .species = SPECIES_SEAKING,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2852
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 2851
            .lvl = 33,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 2854
            .species = SPECIES_GOLDEEN,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2856
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 2855
            .lvl = 33,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 2858
    [DIFFICULTY_NORMAL][TRAINER_FISHERMAN_ANDREW] =
    {
#line 2859
        .trainerName = _("ANDREW"),
#line 2860
        .trainerClass = TRAINER_CLASS_FISHERMAN,
#line 2861
        .trainerPic = TRAINER_PIC_FISHERMAN,
        .encounterMusic_gender =
#line 2863
            TRAINER_ENCOUNTER_MUSIC_HIKER,
#line 2864
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 2865
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 2867
            .species = SPECIES_MAGIKARP,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2869
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 2868
            .lvl = 24,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 2871
            .species = SPECIES_MAGIKARP,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2873
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 2872
            .lvl = 24,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 2875
    [DIFFICULTY_NORMAL][TRAINER_SWIMMER_MALE_LUIS] =
    {
#line 2876
        .trainerName = _("LUIS"),
#line 2877
        .trainerClass = TRAINER_CLASS_SWIMMER_M,
#line 2878
        .trainerPic = TRAINER_PIC_SWIMMER_M,
        .encounterMusic_gender =
#line 2880
            TRAINER_ENCOUNTER_MUSIC_SWIMMER,
#line 2881
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 2882
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 2884
            .species = SPECIES_HORSEA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2886
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 2885
            .lvl = 16,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 2888
            .species = SPECIES_SHELLDER,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2890
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 2889
            .lvl = 16,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 2892
    [DIFFICULTY_NORMAL][TRAINER_SWIMMER_MALE_RICHARD] =
    {
#line 2893
        .trainerName = _("RICHARD"),
#line 2894
        .trainerClass = TRAINER_CLASS_SWIMMER_M,
#line 2895
        .trainerPic = TRAINER_PIC_SWIMMER_M,
        .encounterMusic_gender =
#line 2897
            TRAINER_ENCOUNTER_MUSIC_SWIMMER,
#line 2898
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 2899
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 2901
            .species = SPECIES_TENTACOOL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2903
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 2902
            .lvl = 30,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 2905
            .species = SPECIES_SHELLDER,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2907
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 2906
            .lvl = 30,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 2909
    [DIFFICULTY_NORMAL][TRAINER_SWIMMER_MALE_REECE] =
    {
#line 2910
        .trainerName = _("REECE"),
#line 2911
        .trainerClass = TRAINER_CLASS_SWIMMER_M,
#line 2912
        .trainerPic = TRAINER_PIC_SWIMMER_M,
        .encounterMusic_gender =
#line 2914
            TRAINER_ENCOUNTER_MUSIC_SWIMMER,
#line 2915
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 2916
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 2918
            .species = SPECIES_GOLDEEN,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2920
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 2919
            .lvl = 29,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 2922
            .species = SPECIES_HORSEA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2924
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 2923
            .lvl = 29,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 2926
            .species = SPECIES_STARYU,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2928
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 2927
            .lvl = 29,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 2930
    [DIFFICULTY_NORMAL][TRAINER_SWIMMER_MALE_MATTHEW] =
    {
#line 2931
        .trainerName = _("MATTHEW"),
#line 2932
        .trainerClass = TRAINER_CLASS_SWIMMER_M,
#line 2933
        .trainerPic = TRAINER_PIC_SWIMMER_M,
        .encounterMusic_gender =
#line 2935
            TRAINER_ENCOUNTER_MUSIC_SWIMMER,
#line 2936
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 2937
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 2939
            .species = SPECIES_POLIWAG,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2941
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 2940
            .lvl = 30,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 2943
            .species = SPECIES_POLIWHIRL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2945
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 2944
            .lvl = 30,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 2947
    [DIFFICULTY_NORMAL][TRAINER_SWIMMER_MALE_DOUGLAS] =
    {
#line 2948
        .trainerName = _("DOUGLAS"),
#line 2949
        .trainerClass = TRAINER_CLASS_SWIMMER_M,
#line 2950
        .trainerPic = TRAINER_PIC_SWIMMER_M,
        .encounterMusic_gender =
#line 2952
            TRAINER_ENCOUNTER_MUSIC_SWIMMER,
#line 2953
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 2954
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 4,
        .party = (const struct TrainerMon[])
        {
            {
#line 2956
            .species = SPECIES_HORSEA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2958
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 2957
            .lvl = 27,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 2960
            .species = SPECIES_TENTACOOL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2962
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 2961
            .lvl = 27,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 2964
            .species = SPECIES_TENTACOOL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2966
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 2965
            .lvl = 27,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 2968
            .species = SPECIES_GOLDEEN,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2970
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 2969
            .lvl = 27,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 2972
    [DIFFICULTY_NORMAL][TRAINER_SWIMMER_MALE_DAVID] =
    {
#line 2973
        .trainerName = _("DAVID"),
#line 2974
        .trainerClass = TRAINER_CLASS_SWIMMER_M,
#line 2975
        .trainerPic = TRAINER_PIC_SWIMMER_M,
        .encounterMusic_gender =
#line 2977
            TRAINER_ENCOUNTER_MUSIC_SWIMMER,
#line 2978
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 2979
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 2981
            .species = SPECIES_GOLDEEN,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2983
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 2982
            .lvl = 29,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 2985
            .species = SPECIES_SHELLDER,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2987
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 2986
            .lvl = 29,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 2989
            .species = SPECIES_SEAKING,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2991
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 2990
            .lvl = 29,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 2993
    [DIFFICULTY_NORMAL][TRAINER_SWIMMER_MALE_TONY] =
    {
#line 2994
        .trainerName = _("TONY"),
#line 2995
        .trainerClass = TRAINER_CLASS_SWIMMER_M,
#line 2996
        .trainerPic = TRAINER_PIC_SWIMMER_M,
        .encounterMusic_gender =
#line 2998
            TRAINER_ENCOUNTER_MUSIC_SWIMMER,
#line 2999
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 3000
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 3002
            .species = SPECIES_HORSEA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3004
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 3003
            .lvl = 30,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 3006
            .species = SPECIES_HORSEA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3008
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 3007
            .lvl = 30,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 3010
    [DIFFICULTY_NORMAL][TRAINER_SWIMMER_MALE_AXLE] =
    {
#line 3011
        .trainerName = _("AXLE"),
#line 3012
        .trainerClass = TRAINER_CLASS_SWIMMER_M,
#line 3013
        .trainerPic = TRAINER_PIC_SWIMMER_M,
        .encounterMusic_gender =
#line 3015
            TRAINER_ENCOUNTER_MUSIC_SWIMMER,
#line 3016
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 3017
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 5,
        .party = (const struct TrainerMon[])
        {
            {
#line 3019
            .species = SPECIES_TENTACOOL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3021
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 3020
            .lvl = 27,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 3023
            .species = SPECIES_TENTACOOL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3025
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 3024
            .lvl = 27,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 3027
            .species = SPECIES_STARYU,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3029
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 3028
            .lvl = 27,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 3031
            .species = SPECIES_HORSEA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3033
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 3032
            .lvl = 27,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 3035
            .species = SPECIES_TENTACRUEL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3037
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 3036
            .lvl = 27,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 3039
    [DIFFICULTY_NORMAL][TRAINER_SWIMMER_MALE_BARRY] =
    {
#line 3040
        .trainerName = _("BARRY"),
#line 3041
        .trainerClass = TRAINER_CLASS_SWIMMER_M,
#line 3042
        .trainerPic = TRAINER_PIC_SWIMMER_M,
        .encounterMusic_gender =
#line 3044
            TRAINER_ENCOUNTER_MUSIC_SWIMMER,
#line 3045
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 3046
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 3048
            .species = SPECIES_SHELLDER,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3050
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 3049
            .lvl = 31,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 3052
            .species = SPECIES_CLOYSTER,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3054
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 3053
            .lvl = 31,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 3056
    [DIFFICULTY_NORMAL][TRAINER_SWIMMER_MALE_DEAN] =
    {
#line 3057
        .trainerName = _("DEAN"),
#line 3058
        .trainerClass = TRAINER_CLASS_SWIMMER_M,
#line 3059
        .trainerPic = TRAINER_PIC_SWIMMER_M,
        .encounterMusic_gender =
#line 3061
            TRAINER_ENCOUNTER_MUSIC_SWIMMER,
#line 3062
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 3063
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 3065
            .species = SPECIES_STARYU,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3067
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 3066
            .lvl = 35,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 3069
    [DIFFICULTY_NORMAL][TRAINER_SWIMMER_MALE_DARRIN] =
    {
#line 3070
        .trainerName = _("DARRIN"),
#line 3071
        .trainerClass = TRAINER_CLASS_SWIMMER_M,
#line 3072
        .trainerPic = TRAINER_PIC_SWIMMER_M,
        .encounterMusic_gender =
#line 3074
            TRAINER_ENCOUNTER_MUSIC_SWIMMER,
#line 3075
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 3076
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 4,
        .party = (const struct TrainerMon[])
        {
            {
#line 3078
            .species = SPECIES_HORSEA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3080
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 3079
            .lvl = 28,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 3082
            .species = SPECIES_HORSEA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3084
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 3083
            .lvl = 28,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 3086
            .species = SPECIES_SEADRA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3088
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 3087
            .lvl = 28,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 3090
            .species = SPECIES_HORSEA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3092
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 3091
            .lvl = 28,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 3094
    [DIFFICULTY_NORMAL][TRAINER_SWIMMER_MALE_SPENCER] =
    {
#line 3095
        .trainerName = _("SPENCER"),
#line 3096
        .trainerClass = TRAINER_CLASS_SWIMMER_M,
#line 3097
        .trainerPic = TRAINER_PIC_SWIMMER_M,
        .encounterMusic_gender =
#line 3099
            TRAINER_ENCOUNTER_MUSIC_SWIMMER,
#line 3100
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 3101
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 3103
            .species = SPECIES_SEADRA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3105
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 3104
            .lvl = 33,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 3107
            .species = SPECIES_TENTACRUEL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3109
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 3108
            .lvl = 33,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 3111
    [DIFFICULTY_NORMAL][TRAINER_SWIMMER_MALE_JACK] =
    {
#line 3112
        .trainerName = _("JACK"),
#line 3113
        .trainerClass = TRAINER_CLASS_SWIMMER_M,
#line 3114
        .trainerPic = TRAINER_PIC_SWIMMER_M,
        .encounterMusic_gender =
#line 3116
            TRAINER_ENCOUNTER_MUSIC_SWIMMER,
#line 3117
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 3118
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 3120
            .species = SPECIES_STARMIE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3122
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 3121
            .lvl = 37,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 3124
    [DIFFICULTY_NORMAL][TRAINER_SWIMMER_MALE_JEROME] =
    {
#line 3125
        .trainerName = _("JEROME"),
#line 3126
        .trainerClass = TRAINER_CLASS_SWIMMER_M,
#line 3127
        .trainerPic = TRAINER_PIC_SWIMMER_M,
        .encounterMusic_gender =
#line 3129
            TRAINER_ENCOUNTER_MUSIC_SWIMMER,
#line 3130
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 3131
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 3133
            .species = SPECIES_STARYU,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3135
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 3134
            .lvl = 33,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 3137
            .species = SPECIES_WARTORTLE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3139
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 3138
            .lvl = 33,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 3141
    [DIFFICULTY_NORMAL][TRAINER_SWIMMER_MALE_ROLAND] =
    {
#line 3142
        .trainerName = _("ROLAND"),
#line 3143
        .trainerClass = TRAINER_CLASS_SWIMMER_M,
#line 3144
        .trainerPic = TRAINER_PIC_SWIMMER_M,
        .encounterMusic_gender =
#line 3146
            TRAINER_ENCOUNTER_MUSIC_SWIMMER,
#line 3147
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 3148
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 3150
            .species = SPECIES_POLIWHIRL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3152
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 3151
            .lvl = 32,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 3154
            .species = SPECIES_TENTACOOL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3156
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 3155
            .lvl = 32,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 3158
            .species = SPECIES_SEADRA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3160
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 3159
            .lvl = 32,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 3162
    [DIFFICULTY_NORMAL][TRAINER_CUE_BALL_KOJI] =
    {
#line 3163
        .trainerName = _("KOJI"),
#line 3164
        .trainerClass = TRAINER_CLASS_CUE_BALL,
#line 3165
        .trainerPic = TRAINER_PIC_CUE_BALL,
        .encounterMusic_gender =
#line 3167
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 3168
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 3169
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 3171
            .species = SPECIES_MACHOP,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3173
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 3172
            .lvl = 28,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 3175
            .species = SPECIES_MANKEY,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3177
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 3176
            .lvl = 28,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 3179
            .species = SPECIES_MACHOP,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3181
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 3180
            .lvl = 28,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 3183
    [DIFFICULTY_NORMAL][TRAINER_CUE_BALL_LUKE] =
    {
#line 3184
        .trainerName = _("LUKE"),
#line 3185
        .trainerClass = TRAINER_CLASS_CUE_BALL,
#line 3186
        .trainerPic = TRAINER_PIC_CUE_BALL,
        .encounterMusic_gender =
#line 3188
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 3189
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 3190
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 3192
            .species = SPECIES_MANKEY,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3194
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 3193
            .lvl = 29,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 3196
            .species = SPECIES_MACHOP,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3198
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 3197
            .lvl = 29,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 3200
    [DIFFICULTY_NORMAL][TRAINER_CUE_BALL_CAMRON] =
    {
#line 3201
        .trainerName = _("CAMRON"),
#line 3202
        .trainerClass = TRAINER_CLASS_CUE_BALL,
#line 3203
        .trainerPic = TRAINER_PIC_CUE_BALL,
        .encounterMusic_gender =
#line 3205
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 3206
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 3207
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 3209
            .species = SPECIES_MANKEY,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3211
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 3210
            .lvl = 29,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 3213
            .species = SPECIES_MACHOP,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3215
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 3214
            .lvl = 29,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 3217
    [DIFFICULTY_NORMAL][TRAINER_CUE_BALL_RAUL] =
    {
#line 3218
        .trainerName = _("RAUL"),
#line 3219
        .trainerClass = TRAINER_CLASS_CUE_BALL,
#line 3220
        .trainerPic = TRAINER_PIC_CUE_BALL,
        .encounterMusic_gender =
#line 3222
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 3223
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 3224
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 3226
            .species = SPECIES_MANKEY,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3228
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 3227
            .lvl = 29,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 3230
            .species = SPECIES_PRIMEAPE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3232
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 3231
            .lvl = 29,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 3234
    [DIFFICULTY_NORMAL][TRAINER_CUE_BALL_ISAIAH] =
    {
#line 3235
        .trainerName = _("ISAIAH"),
#line 3236
        .trainerClass = TRAINER_CLASS_CUE_BALL,
#line 3237
        .trainerPic = TRAINER_PIC_CUE_BALL,
        .encounterMusic_gender =
#line 3239
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 3240
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 3241
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 3243
            .species = SPECIES_MACHOP,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3245
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 3244
            .lvl = 29,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 3247
            .species = SPECIES_MACHAMP,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3249
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 3248
            .lvl = 29,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 3251
    [DIFFICULTY_NORMAL][TRAINER_CUE_BALL_ZEEK] =
    {
#line 3252
        .trainerName = _("ZEEK"),
#line 3253
        .trainerClass = TRAINER_CLASS_CUE_BALL,
#line 3254
        .trainerPic = TRAINER_PIC_CUE_BALL,
        .encounterMusic_gender =
#line 3256
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 3257
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 3258
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 3260
            .species = SPECIES_MACHOKE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3262
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 3261
            .lvl = 33,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 3264
    [DIFFICULTY_NORMAL][TRAINER_CUE_BALL_JAMAL] =
    {
#line 3265
        .trainerName = _("JAMAL"),
#line 3266
        .trainerClass = TRAINER_CLASS_CUE_BALL,
#line 3267
        .trainerPic = TRAINER_PIC_CUE_BALL,
        .encounterMusic_gender =
#line 3269
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 3270
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 3271
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 4,
        .party = (const struct TrainerMon[])
        {
            {
#line 3273
            .species = SPECIES_MANKEY,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3275
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 3274
            .lvl = 26,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 3277
            .species = SPECIES_MANKEY,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3279
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 3278
            .lvl = 26,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 3281
            .species = SPECIES_MACHAMP,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3283
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 3282
            .lvl = 26,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 3285
            .species = SPECIES_MACHOP,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3287
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 3286
            .lvl = 26,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 3289
    [DIFFICULTY_NORMAL][TRAINER_CUE_BALL_COREY] =
    {
#line 3290
        .trainerName = _("COREY"),
#line 3291
        .trainerClass = TRAINER_CLASS_CUE_BALL,
#line 3292
        .trainerPic = TRAINER_PIC_CUE_BALL,
        .encounterMusic_gender =
#line 3294
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 3295
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 3296
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 3298
            .species = SPECIES_PRIMEAPE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3300
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 3299
            .lvl = 29,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 3302
            .species = SPECIES_MACHOKE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3304
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 3303
            .lvl = 29,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 3306
    [DIFFICULTY_NORMAL][TRAINER_CUE_BALL_CHASE] =
    {
#line 3307
        .trainerName = _("CHASE"),
#line 3308
        .trainerClass = TRAINER_CLASS_CUE_BALL,
#line 3309
        .trainerPic = TRAINER_PIC_CUE_BALL,
        .encounterMusic_gender =
#line 3311
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 3312
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 3313
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 3315
            .species = SPECIES_TENTACOOL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3317
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 3316
            .lvl = 31,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 3319
            .species = SPECIES_TENTACOOL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3321
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 3320
            .lvl = 31,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 3323
            .species = SPECIES_TENTACRUEL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3325
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 3324
            .lvl = 31,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 3327
    [DIFFICULTY_NORMAL][TRAINER_GAMER_HUGO] =
    {
#line 3328
        .trainerName = _("HUGO"),
#line 3329
        .trainerClass = TRAINER_CLASS_GAMER,
#line 3330
        .trainerPic = TRAINER_PIC_GAMER,
        .encounterMusic_gender =
#line 3332
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 3333
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 3334
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 3336
            .species = SPECIES_POLIWAG,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3338
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 3337
            .lvl = 18,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 3340
            .species = SPECIES_HORSEA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3342
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 3341
            .lvl = 18,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 3344
    [DIFFICULTY_NORMAL][TRAINER_GAMER_JASPER] =
    {
#line 3345
        .trainerName = _("JASPER"),
#line 3346
        .trainerClass = TRAINER_CLASS_GAMER,
#line 3347
        .trainerPic = TRAINER_PIC_GAMER,
        .encounterMusic_gender =
#line 3349
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 3350
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 3351
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 3353
            .species = SPECIES_BELLSPROUT,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3355
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 3354
            .lvl = 18,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 3357
            .species = SPECIES_ODDISH,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3359
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 3358
            .lvl = 18,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 3361
    [DIFFICULTY_NORMAL][TRAINER_GAMER_DIRK] =
    {
#line 3362
        .trainerName = _("DIRK"),
#line 3363
        .trainerClass = TRAINER_CLASS_GAMER,
#line 3364
        .trainerPic = TRAINER_PIC_GAMER,
        .encounterMusic_gender =
#line 3366
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 3367
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 3368
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 3370
            .species = SPECIES_VOLTORB,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3372
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 3371
            .lvl = 18,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 3374
            .species = SPECIES_MAGNEMITE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3376
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 3375
            .lvl = 18,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 3378
    [DIFFICULTY_NORMAL][TRAINER_GAMER_DARIAN] =
    {
#line 3379
        .trainerName = _("DARIAN"),
#line 3380
        .trainerClass = TRAINER_CLASS_GAMER,
#line 3381
        .trainerPic = TRAINER_PIC_GAMER,
        .encounterMusic_gender =
#line 3383
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 3384
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 3385
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 3387
            .species = SPECIES_GROWLITHE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3389
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 3388
            .lvl = 18,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 3391
            .species = SPECIES_VULPIX,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3393
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 3392
            .lvl = 18,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 3395
    [DIFFICULTY_NORMAL][TRAINER_GAMER_STAN] =
    {
#line 3396
        .trainerName = _("STAN"),
#line 3397
        .trainerClass = TRAINER_CLASS_GAMER,
#line 3398
        .trainerPic = TRAINER_PIC_GAMER,
        .encounterMusic_gender =
#line 3400
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 3401
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 3402
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 3404
            .species = SPECIES_POLIWAG,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3406
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 3405
            .lvl = 22,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 3408
            .species = SPECIES_POLIWAG,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3410
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 3409
            .lvl = 22,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 3412
            .species = SPECIES_POLIWHIRL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3414
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 3413
            .lvl = 22,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 3416
    [DIFFICULTY_NORMAL][TRAINER_GAMER_1] =
    {
#line 3417
        .trainerName = _("PH"),
#line 3418
        .trainerClass = TRAINER_CLASS_GAMER,
#line 3419
        .trainerPic = TRAINER_PIC_GAMER,
        .encounterMusic_gender =
#line 3421
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 3422
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 3423
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 3425
            .species = SPECIES_EKANS,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3427
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 3426
            .lvl = 5,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 3429
    [DIFFICULTY_NORMAL][TRAINER_GAMER_RICH] =
    {
#line 3430
        .trainerName = _("RICH"),
#line 3431
        .trainerClass = TRAINER_CLASS_GAMER,
#line 3432
        .trainerPic = TRAINER_PIC_GAMER,
        .encounterMusic_gender =
#line 3434
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 3435
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 3436
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 3438
            .species = SPECIES_GROWLITHE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3440
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 3439
            .lvl = 24,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 3442
            .species = SPECIES_VULPIX,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3444
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 3443
            .lvl = 24,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 3446
    [DIFFICULTY_NORMAL][TRAINER_BEAUTY_BRIDGET] =
    {
#line 3447
        .trainerName = _("BRIDGET"),
#line 3448
        .trainerClass = TRAINER_CLASS_BEAUTY,
#line 3449
        .trainerPic = TRAINER_PIC_BEAUTY,
        .encounterMusic_gender =
#line 3451
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
#line 3452
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 3453
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 4,
        .party = (const struct TrainerMon[])
        {
            {
#line 3455
            .species = SPECIES_ODDISH,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3457
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 3456
            .lvl = 21,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 3459
            .species = SPECIES_BELLSPROUT,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3461
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 3460
            .lvl = 21,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 3463
            .species = SPECIES_ODDISH,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3465
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 3464
            .lvl = 21,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 3467
            .species = SPECIES_BELLSPROUT,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3469
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 3468
            .lvl = 21,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 3471
    [DIFFICULTY_NORMAL][TRAINER_BEAUTY_TAMIA] =
    {
#line 3472
        .trainerName = _("TAMIA"),
#line 3473
        .trainerClass = TRAINER_CLASS_BEAUTY,
#line 3474
        .trainerPic = TRAINER_PIC_BEAUTY,
        .encounterMusic_gender =
#line 3476
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
#line 3477
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 3478
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 3480
            .species = SPECIES_BELLSPROUT,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3482
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 3481
            .lvl = 24,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 3484
            .species = SPECIES_BELLSPROUT,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3486
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 3485
            .lvl = 24,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 3488
    [DIFFICULTY_NORMAL][TRAINER_BEAUTY_LORI] =
    {
#line 3489
        .trainerName = _("LORI"),
#line 3490
        .trainerClass = TRAINER_CLASS_BEAUTY,
#line 3491
        .trainerPic = TRAINER_PIC_BEAUTY,
        .encounterMusic_gender =
#line 3493
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
#line 3494
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 3495
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 3497
            .species = SPECIES_EXEGGCUTE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3499
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 3498
            .lvl = 24,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 3501
    [DIFFICULTY_NORMAL][TRAINER_BEAUTY_LOLA] =
    {
#line 3502
        .trainerName = _("LOLA"),
#line 3503
        .trainerClass = TRAINER_CLASS_BEAUTY,
#line 3504
        .trainerPic = TRAINER_PIC_BEAUTY,
        .encounterMusic_gender =
#line 3506
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
#line 3507
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 3508
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 3510
            .species = SPECIES_RATTATA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3512
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 3511
            .lvl = 27,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 3514
            .species = SPECIES_PIKACHU,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3516
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 3515
            .lvl = 27,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 3518
            .species = SPECIES_RATTATA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3520
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 3519
            .lvl = 27,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 3522
    [DIFFICULTY_NORMAL][TRAINER_BEAUTY_SHEILA] =
    {
#line 3523
        .trainerName = _("SHEILA"),
#line 3524
        .trainerClass = TRAINER_CLASS_BEAUTY,
#line 3525
        .trainerPic = TRAINER_PIC_BEAUTY,
        .encounterMusic_gender =
#line 3527
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
#line 3528
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 3529
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 3531
            .species = SPECIES_CLEFAIRY,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3533
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 3532
            .lvl = 29,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 3535
            .species = SPECIES_MEOWTH,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3537
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 3536
            .lvl = 29,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 3539
    [DIFFICULTY_NORMAL][TRAINER_SWIMMER_FEMALE_TIFFANY] =
    {
#line 3540
        .trainerName = _("TIFFANY"),
#line 3541
        .trainerClass = TRAINER_CLASS_SWIMMER_F,
#line 3542
        .trainerPic = TRAINER_PIC_SWIMMER_F,
        .encounterMusic_gender =
#line 3544
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
#line 3545
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 3546
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 3548
            .species = SPECIES_SEAKING,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3550
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 3549
            .lvl = 35,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 3552
    [DIFFICULTY_NORMAL][TRAINER_SWIMMER_FEMALE_NORA] =
    {
#line 3553
        .trainerName = _("NORA"),
#line 3554
        .trainerClass = TRAINER_CLASS_SWIMMER_F,
#line 3555
        .trainerPic = TRAINER_PIC_SWIMMER_F,
        .encounterMusic_gender =
#line 3557
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
#line 3558
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 3559
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 3561
            .species = SPECIES_SHELLDER,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3563
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 3562
            .lvl = 30,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 3565
            .species = SPECIES_SHELLDER,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3567
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 3566
            .lvl = 30,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 3569
            .species = SPECIES_CLOYSTER,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3571
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 3570
            .lvl = 30,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 3573
    [DIFFICULTY_NORMAL][TRAINER_SWIMMER_FEMALE_MELISSA] =
    {
#line 3574
        .trainerName = _("MELISSA"),
#line 3575
        .trainerClass = TRAINER_CLASS_SWIMMER_F,
#line 3576
        .trainerPic = TRAINER_PIC_SWIMMER_F,
        .encounterMusic_gender =
#line 3578
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
#line 3579
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 3580
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 3582
            .species = SPECIES_POLIWAG,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3584
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 3583
            .lvl = 31,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 3586
            .species = SPECIES_SEAKING,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3588
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 3587
            .lvl = 31,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 3590
    [DIFFICULTY_NORMAL][TRAINER_BEAUTY_GRACE] =
    {
#line 3591
        .trainerName = _("GRACE"),
#line 3592
        .trainerClass = TRAINER_CLASS_BEAUTY,
#line 3593
        .trainerPic = TRAINER_PIC_BEAUTY,
        .encounterMusic_gender =
#line 3595
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
#line 3596
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 3597
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 3599
            .species = SPECIES_PIDGEOTTO,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3601
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 3600
            .lvl = 29,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 3603
            .species = SPECIES_WIGGLYTUFF,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3605
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 3604
            .lvl = 29,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 3607
    [DIFFICULTY_NORMAL][TRAINER_BEAUTY_OLIVIA] =
    {
#line 3608
        .trainerName = _("OLIVIA"),
#line 3609
        .trainerClass = TRAINER_CLASS_BEAUTY,
#line 3610
        .trainerPic = TRAINER_PIC_BEAUTY,
        .encounterMusic_gender =
#line 3612
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
#line 3613
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 3614
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 3616
            .species = SPECIES_BULBASAUR,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3618
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 3617
            .lvl = 29,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 3620
            .species = SPECIES_IVYSAUR,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3622
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 3621
            .lvl = 29,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 3624
    [DIFFICULTY_NORMAL][TRAINER_BEAUTY_LAUREN] =
    {
#line 3625
        .trainerName = _("LAUREN"),
#line 3626
        .trainerClass = TRAINER_CLASS_BEAUTY,
#line 3627
        .trainerPic = TRAINER_PIC_SWIMMER_F,
        .encounterMusic_gender =
#line 3629
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
#line 3630
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 3631
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 3633
            .species = SPECIES_WEEPINBELL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3635
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 3634
            .lvl = 33,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 3637
            .species = SPECIES_BELLSPROUT,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3639
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 3638
            .lvl = 33,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 3641
            .species = SPECIES_WEEPINBELL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3643
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 3642
            .lvl = 33,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 3645
    [DIFFICULTY_NORMAL][TRAINER_SWIMMER_FEMALE_ANYA] =
    {
#line 3646
        .trainerName = _("ANYA"),
#line 3647
        .trainerClass = TRAINER_CLASS_SWIMMER_F,
#line 3648
        .trainerPic = TRAINER_PIC_SWIMMER_F,
        .encounterMusic_gender =
#line 3650
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
#line 3651
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 3652
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 5,
        .party = (const struct TrainerMon[])
        {
            {
#line 3654
            .species = SPECIES_POLIWAG,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3656
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 3655
            .lvl = 27,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 3658
            .species = SPECIES_GOLDEEN,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3660
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 3659
            .lvl = 27,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 3662
            .species = SPECIES_SEAKING,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3664
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 3663
            .lvl = 27,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 3666
            .species = SPECIES_GOLDEEN,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3668
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 3667
            .lvl = 27,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 3670
            .species = SPECIES_POLIWAG,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3672
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 3671
            .lvl = 27,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 3674
    [DIFFICULTY_NORMAL][TRAINER_SWIMMER_FEMALE_ALICE] =
    {
#line 3675
        .trainerName = _("ALICE"),
#line 3676
        .trainerClass = TRAINER_CLASS_SWIMMER_F,
#line 3677
        .trainerPic = TRAINER_PIC_SWIMMER_F,
        .encounterMusic_gender =
#line 3679
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
#line 3680
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 3681
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 3683
            .species = SPECIES_GOLDEEN,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3685
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 3684
            .lvl = 30,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 3687
            .species = SPECIES_SEAKING,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3689
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 3688
            .lvl = 30,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 3691
    [DIFFICULTY_NORMAL][TRAINER_SWIMMER_FEMALE_CONNIE] =
    {
#line 3692
        .trainerName = _("CONNIE"),
#line 3693
        .trainerClass = TRAINER_CLASS_SWIMMER_F,
#line 3694
        .trainerPic = TRAINER_PIC_SWIMMER_F,
        .encounterMusic_gender =
#line 3696
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
#line 3697
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 3698
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 3700
            .species = SPECIES_STARYU,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3702
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 3701
            .lvl = 29,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 3704
            .species = SPECIES_STARYU,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3706
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 3705
            .lvl = 29,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 3708
            .species = SPECIES_STARYU,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3710
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 3709
            .lvl = 29,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 3712
    [DIFFICULTY_NORMAL][TRAINER_SWIMMER_FEMALE_SHIRLEY] =
    {
#line 3713
        .trainerName = _("SHIRLEY"),
#line 3714
        .trainerClass = TRAINER_CLASS_SWIMMER_F,
#line 3715
        .trainerPic = TRAINER_PIC_SWIMMER_F,
        .encounterMusic_gender =
#line 3717
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
#line 3718
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 3719
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 3721
            .species = SPECIES_SEADRA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3723
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 3722
            .lvl = 30,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 3725
            .species = SPECIES_HORSEA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3727
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 3726
            .lvl = 30,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 3729
            .species = SPECIES_SEADRA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3731
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 3730
            .lvl = 30,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 3733
    [DIFFICULTY_NORMAL][TRAINER_PSYCHIC_JOHAN] =
    {
#line 3734
        .trainerName = _("JOHAN"),
#line 3735
        .trainerClass = TRAINER_CLASS_PSYCHIC,
#line 3736
        .trainerPic = TRAINER_PIC_PSYCHIC_M,
        .encounterMusic_gender =
#line 3738
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
#line 3739
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 3740
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 4,
        .party = (const struct TrainerMon[])
        {
            {
#line 3742
            .species = SPECIES_KADABRA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3744
            .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
#line 3743
            .lvl = 31,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 3746
            .species = SPECIES_SLOWPOKE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3748
            .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
#line 3747
            .lvl = 31,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 3750
            .species = SPECIES_MR_MIME,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3752
            .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
#line 3751
            .lvl = 31,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 3754
            .species = SPECIES_KADABRA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3756
            .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
#line 3755
            .lvl = 31,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 3758
    [DIFFICULTY_NORMAL][TRAINER_PSYCHIC_TYRON] =
    {
#line 3759
        .trainerName = _("TYRON"),
#line 3760
        .trainerClass = TRAINER_CLASS_PSYCHIC,
#line 3761
        .trainerPic = TRAINER_PIC_PSYCHIC_M,
        .encounterMusic_gender =
#line 3763
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
#line 3764
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 3765
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 3767
            .species = SPECIES_MR_MIME,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3769
            .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
#line 3768
            .lvl = 34,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 3771
            .species = SPECIES_KADABRA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3773
            .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
#line 3772
            .lvl = 34,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 3775
    [DIFFICULTY_NORMAL][TRAINER_PSYCHIC_CAMERON] =
    {
#line 3776
        .trainerName = _("CAMERON"),
#line 3777
        .trainerClass = TRAINER_CLASS_PSYCHIC,
#line 3778
        .trainerPic = TRAINER_PIC_PSYCHIC_M,
        .encounterMusic_gender =
#line 3780
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
#line 3781
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 3782
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 3784
            .species = SPECIES_SLOWPOKE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3786
            .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
#line 3785
            .lvl = 33,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 3788
            .species = SPECIES_SLOWPOKE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3790
            .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
#line 3789
            .lvl = 33,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 3792
            .species = SPECIES_SLOWBRO,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3794
            .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
#line 3793
            .lvl = 33,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 3796
    [DIFFICULTY_NORMAL][TRAINER_PSYCHIC_PRESTON] =
    {
#line 3797
        .trainerName = _("PRESTON"),
#line 3798
        .trainerClass = TRAINER_CLASS_PSYCHIC,
#line 3799
        .trainerPic = TRAINER_PIC_PSYCHIC_M,
        .encounterMusic_gender =
#line 3801
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
#line 3802
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 3803
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 3805
            .species = SPECIES_SLOWBRO,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3807
            .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
#line 3806
            .lvl = 38,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 3809
    [DIFFICULTY_NORMAL][TRAINER_ROCKER_RANDALL] =
    {
#line 3810
        .trainerName = _("RANDALL"),
#line 3811
        .trainerClass = TRAINER_CLASS_ROCKER,
#line 3812
        .trainerPic = TRAINER_PIC_ROCKER,
        .encounterMusic_gender =
#line 3814
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 3815
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 3816
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 3818
            .species = SPECIES_VOLTORB,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3820
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 3819
            .lvl = 20,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 3822
            .species = SPECIES_MAGNEMITE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3824
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 3823
            .lvl = 20,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 3826
            .species = SPECIES_VOLTORB,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3828
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 3827
            .lvl = 20,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 3830
    [DIFFICULTY_NORMAL][TRAINER_ROCKER_LUCA] =
    {
#line 3831
        .trainerName = _("LUCA"),
#line 3832
        .trainerClass = TRAINER_CLASS_ROCKER,
#line 3833
        .trainerPic = TRAINER_PIC_ROCKER,
        .encounterMusic_gender =
#line 3835
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 3836
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 3837
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 3839
            .species = SPECIES_VOLTORB,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3841
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 3840
            .lvl = 29,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 3843
            .species = SPECIES_ELECTRODE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3845
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 3844
            .lvl = 29,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 3847
    [DIFFICULTY_NORMAL][TRAINER_JUGGLER_DALTON] =
    {
#line 3848
        .trainerName = _("DALTON"),
#line 3849
        .trainerClass = TRAINER_CLASS_JUGGLER,
#line 3850
        .trainerPic = TRAINER_PIC_JUGGLER,
        .encounterMusic_gender =
#line 3852
            TRAINER_ENCOUNTER_MUSIC_HIKER,
#line 3853
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 3854
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 3856
            .species = SPECIES_KADABRA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3858
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 3857
            .lvl = 29,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 3860
            .species = SPECIES_MR_MIME,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3862
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 3861
            .lvl = 29,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 3864
    [DIFFICULTY_NORMAL][TRAINER_JUGGLER_NELSON] =
    {
#line 3865
        .trainerName = _("NELSON"),
#line 3866
        .trainerClass = TRAINER_CLASS_JUGGLER,
#line 3867
        .trainerPic = TRAINER_PIC_JUGGLER,
        .encounterMusic_gender =
#line 3869
            TRAINER_ENCOUNTER_MUSIC_HIKER,
#line 3870
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 3871
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 4,
        .party = (const struct TrainerMon[])
        {
            {
#line 3873
            .species = SPECIES_DROWZEE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3875
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 3874
            .lvl = 41,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 3877
            .species = SPECIES_HYPNO,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3879
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 3878
            .lvl = 41,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 3881
            .species = SPECIES_KADABRA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3883
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 3882
            .lvl = 41,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 3885
            .species = SPECIES_KADABRA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3887
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 3886
            .lvl = 41,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 3889
    [DIFFICULTY_NORMAL][TRAINER_JUGGLER_KIRK] =
    {
#line 3890
        .trainerName = _("KIRK"),
#line 3891
        .trainerClass = TRAINER_CLASS_JUGGLER,
#line 3892
        .trainerPic = TRAINER_PIC_JUGGLER,
        .encounterMusic_gender =
#line 3894
            TRAINER_ENCOUNTER_MUSIC_HIKER,
#line 3895
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 3896
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 4,
        .party = (const struct TrainerMon[])
        {
            {
#line 3898
            .species = SPECIES_DROWZEE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3900
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 3899
            .lvl = 31,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 3902
            .species = SPECIES_DROWZEE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3904
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 3903
            .lvl = 31,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 3906
            .species = SPECIES_KADABRA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3908
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 3907
            .lvl = 31,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 3910
            .species = SPECIES_DROWZEE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3912
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 3911
            .lvl = 31,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 3914
    [DIFFICULTY_NORMAL][TRAINER_JUGGLER_SHAWN] =
    {
#line 3915
        .trainerName = _("SHAWN"),
#line 3916
        .trainerClass = TRAINER_CLASS_JUGGLER,
#line 3917
        .trainerPic = TRAINER_PIC_JUGGLER,
        .encounterMusic_gender =
#line 3919
            TRAINER_ENCOUNTER_MUSIC_HIKER,
#line 3920
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 3921
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 3923
            .species = SPECIES_DROWZEE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3925
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 3924
            .lvl = 34,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 3927
            .species = SPECIES_HYPNO,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3929
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 3928
            .lvl = 34,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 3931
    [DIFFICULTY_NORMAL][TRAINER_JUGGLER_GREGORY] =
    {
#line 3932
        .trainerName = _("GREGORY"),
#line 3933
        .trainerClass = TRAINER_CLASS_JUGGLER,
#line 3934
        .trainerPic = TRAINER_PIC_JUGGLER,
        .encounterMusic_gender =
#line 3936
            TRAINER_ENCOUNTER_MUSIC_HIKER,
#line 3937
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 3938
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 3940
            .species = SPECIES_MR_MIME,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3942
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 3941
            .lvl = 48,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 3943
                MOVE_PSYCHIC,
                MOVE_ROLE_PLAY,
                MOVE_DOUBLE_SLAP,
                MOVE_ENCORE,
            },
            },
        },
    },
#line 3948
    [DIFFICULTY_NORMAL][TRAINER_JUGGLER_EDWARD] =
    {
#line 3949
        .trainerName = _("EDWARD"),
#line 3950
        .trainerClass = TRAINER_CLASS_JUGGLER,
#line 3951
        .trainerPic = TRAINER_PIC_JUGGLER,
        .encounterMusic_gender =
#line 3953
            TRAINER_ENCOUNTER_MUSIC_HIKER,
#line 3954
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 3955
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 4,
        .party = (const struct TrainerMon[])
        {
            {
#line 3957
            .species = SPECIES_VOLTORB,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3959
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 3958
            .lvl = 46,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 3960
                MOVE_SWIFT,
                MOVE_LIGHT_SCREEN,
                MOVE_SPARK,
                MOVE_SONIC_BOOM,
            },
            },
            {
#line 3965
            .species = SPECIES_VOLTORB,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3967
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 3966
            .lvl = 46,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 3968
                MOVE_SWIFT,
                MOVE_LIGHT_SCREEN,
                MOVE_SPARK,
                MOVE_SONIC_BOOM,
            },
            },
            {
#line 3973
            .species = SPECIES_ELECTRODE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3975
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 3974
            .lvl = 47,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 3976
                MOVE_SWIFT,
                MOVE_SPARK,
                MOVE_SELF_DESTRUCT,
                MOVE_SONIC_BOOM,
            },
            },
            {
#line 3981
            .species = SPECIES_MR_MIME,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3983
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 3982
            .lvl = 48,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 3984
                MOVE_PSYCHIC,
                MOVE_ROLE_PLAY,
                MOVE_REFLECT,
                MOVE_ENCORE,
            },
            },
        },
    },
#line 3989
    [DIFFICULTY_NORMAL][TRAINER_JUGGLER_KAYDEN] =
    {
#line 3990
        .trainerName = _("KAYDEN"),
#line 3991
        .trainerClass = TRAINER_CLASS_JUGGLER,
#line 3992
        .trainerPic = TRAINER_PIC_JUGGLER,
        .encounterMusic_gender =
#line 3994
            TRAINER_ENCOUNTER_MUSIC_HIKER,
#line 3995
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 3996
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 3998
            .species = SPECIES_HYPNO,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4000
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 3999
            .lvl = 38,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 4002
    [DIFFICULTY_NORMAL][TRAINER_JUGGLER_NATE] =
    {
#line 4003
        .trainerName = _("NATE"),
#line 4004
        .trainerClass = TRAINER_CLASS_JUGGLER,
#line 4005
        .trainerPic = TRAINER_PIC_JUGGLER,
        .encounterMusic_gender =
#line 4007
            TRAINER_ENCOUNTER_MUSIC_HIKER,
#line 4008
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 4009
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 4011
            .species = SPECIES_DROWZEE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4013
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 4012
            .lvl = 34,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 4015
            .species = SPECIES_KADABRA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4017
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 4016
            .lvl = 34,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 4019
    [DIFFICULTY_NORMAL][TRAINER_TAMER_PHIL] =
    {
#line 4020
        .trainerName = _("PHIL"),
#line 4021
        .trainerClass = TRAINER_CLASS_TAMER,
#line 4022
        .trainerPic = TRAINER_PIC_TAMER,
        .encounterMusic_gender =
#line 4024
            TRAINER_ENCOUNTER_MUSIC_HIKER,
#line 4025
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 4026
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 4028
            .species = SPECIES_SANDSLASH,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4030
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
#line 4029
            .lvl = 34,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 4032
            .species = SPECIES_ARBOK,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4034
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
#line 4033
            .lvl = 34,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 4036
    [DIFFICULTY_NORMAL][TRAINER_TAMER_EDGAR] =
    {
#line 4037
        .trainerName = _("EDGAR"),
#line 4038
        .trainerClass = TRAINER_CLASS_TAMER,
#line 4039
        .trainerPic = TRAINER_PIC_TAMER,
        .encounterMusic_gender =
#line 4041
            TRAINER_ENCOUNTER_MUSIC_HIKER,
#line 4042
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 4043
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 4045
            .species = SPECIES_ARBOK,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4047
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
#line 4046
            .lvl = 33,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 4049
            .species = SPECIES_SANDSLASH,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4051
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
#line 4050
            .lvl = 33,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 4053
            .species = SPECIES_ARBOK,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4055
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
#line 4054
            .lvl = 33,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 4057
    [DIFFICULTY_NORMAL][TRAINER_TAMER_JASON] =
    {
#line 4058
        .trainerName = _("JASON"),
#line 4059
        .trainerClass = TRAINER_CLASS_TAMER,
#line 4060
        .trainerPic = TRAINER_PIC_TAMER,
        .encounterMusic_gender =
#line 4062
            TRAINER_ENCOUNTER_MUSIC_HIKER,
#line 4063
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 4064
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 4066
            .species = SPECIES_RHYHORN,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4068
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
#line 4067
            .lvl = 43,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 4070
    [DIFFICULTY_NORMAL][TRAINER_TAMER_COLE] =
    {
#line 4071
        .trainerName = _("COLE"),
#line 4072
        .trainerClass = TRAINER_CLASS_TAMER,
#line 4073
        .trainerPic = TRAINER_PIC_TAMER,
        .encounterMusic_gender =
#line 4075
            TRAINER_ENCOUNTER_MUSIC_HIKER,
#line 4076
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 4077
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 4079
            .species = SPECIES_ARBOK,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4081
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
#line 4080
            .lvl = 39,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 4083
            .species = SPECIES_TAUROS,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4085
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
#line 4084
            .lvl = 39,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 4087
    [DIFFICULTY_NORMAL][TRAINER_TAMER_VINCENT] =
    {
#line 4088
        .trainerName = _("VINCENT"),
#line 4089
        .trainerClass = TRAINER_CLASS_TAMER,
#line 4090
        .trainerPic = TRAINER_PIC_TAMER,
        .encounterMusic_gender =
#line 4092
            TRAINER_ENCOUNTER_MUSIC_HIKER,
#line 4093
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 4094
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 4096
            .species = SPECIES_PERSIAN,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4098
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
#line 4097
            .lvl = 44,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 4100
            .species = SPECIES_GOLDUCK,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4102
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
#line 4101
            .lvl = 44,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 4104
    [DIFFICULTY_NORMAL][TRAINER_TAMER_JOHN] =
    {
#line 4105
        .trainerName = _("JOHN"),
#line 4106
        .trainerClass = TRAINER_CLASS_TAMER,
#line 4107
        .trainerPic = TRAINER_PIC_TAMER,
        .encounterMusic_gender =
#line 4109
            TRAINER_ENCOUNTER_MUSIC_HIKER,
#line 4110
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 4111
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 4,
        .party = (const struct TrainerMon[])
        {
            {
#line 4113
            .species = SPECIES_RHYHORN,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4115
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
#line 4114
            .lvl = 42,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 4117
            .species = SPECIES_PRIMEAPE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4119
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
#line 4118
            .lvl = 42,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 4121
            .species = SPECIES_ARBOK,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4123
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
#line 4122
            .lvl = 42,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 4125
            .species = SPECIES_TAUROS,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4127
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
#line 4126
            .lvl = 42,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 4129
    [DIFFICULTY_NORMAL][TRAINER_BIRD_KEEPER_SEBASTIAN] =
    {
#line 4130
        .trainerName = _("SEBASTIAN"),
#line 4131
        .trainerClass = TRAINER_CLASS_BIRD_KEEPER,
#line 4132
        .trainerPic = TRAINER_PIC_BIRD_KEEPER,
        .encounterMusic_gender =
#line 4134
            TRAINER_ENCOUNTER_MUSIC_COOL,
#line 4135
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 4136
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 4138
            .species = SPECIES_PIDGEY,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4140
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 4139
            .lvl = 29,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 4142
            .species = SPECIES_PIDGEOTTO,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4144
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 4143
            .lvl = 29,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 4146
    [DIFFICULTY_NORMAL][TRAINER_BIRD_KEEPER_PERRY] =
    {
#line 4147
        .trainerName = _("PERRY"),
#line 4148
        .trainerClass = TRAINER_CLASS_BIRD_KEEPER,
#line 4149
        .trainerPic = TRAINER_PIC_BIRD_KEEPER,
        .encounterMusic_gender =
#line 4151
            TRAINER_ENCOUNTER_MUSIC_COOL,
#line 4152
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 4153
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 5,
        .party = (const struct TrainerMon[])
        {
            {
#line 4155
            .species = SPECIES_SPEAROW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4157
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 4156
            .lvl = 25,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 4159
            .species = SPECIES_PIDGEY,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4161
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 4160
            .lvl = 25,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 4163
            .species = SPECIES_PIDGEY,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4165
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 4164
            .lvl = 25,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 4167
            .species = SPECIES_SPEAROW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4169
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 4168
            .lvl = 25,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 4171
            .species = SPECIES_SPEAROW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4173
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 4172
            .lvl = 25,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 4175
    [DIFFICULTY_NORMAL][TRAINER_BIRD_KEEPER_ROBERT] =
    {
#line 4176
        .trainerName = _("ROBERT"),
#line 4177
        .trainerClass = TRAINER_CLASS_BIRD_KEEPER,
#line 4178
        .trainerPic = TRAINER_PIC_BIRD_KEEPER,
        .encounterMusic_gender =
#line 4180
            TRAINER_ENCOUNTER_MUSIC_COOL,
#line 4181
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 4182
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 4,
        .party = (const struct TrainerMon[])
        {
            {
#line 4184
            .species = SPECIES_PIDGEY,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4186
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 4185
            .lvl = 26,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 4188
            .species = SPECIES_PIDGEOTTO,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4190
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 4189
            .lvl = 26,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 4192
            .species = SPECIES_SPEAROW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4194
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 4193
            .lvl = 26,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 4196
            .species = SPECIES_FEAROW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4198
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 4197
            .lvl = 26,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 4200
    [DIFFICULTY_NORMAL][TRAINER_BIRD_KEEPER_DONALD] =
    {
#line 4201
        .trainerName = _("DONALD"),
#line 4202
        .trainerClass = TRAINER_CLASS_BIRD_KEEPER,
#line 4203
        .trainerPic = TRAINER_PIC_BIRD_KEEPER,
        .encounterMusic_gender =
#line 4205
            TRAINER_ENCOUNTER_MUSIC_COOL,
#line 4206
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 4207
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 4209
            .species = SPECIES_FARFETCHD,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4211
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 4210
            .lvl = 33,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 4213
    [DIFFICULTY_NORMAL][TRAINER_BIRD_KEEPER_BENNY] =
    {
#line 4214
        .trainerName = _("BENNY"),
#line 4215
        .trainerClass = TRAINER_CLASS_BIRD_KEEPER,
#line 4216
        .trainerPic = TRAINER_PIC_BIRD_KEEPER,
        .encounterMusic_gender =
#line 4218
            TRAINER_ENCOUNTER_MUSIC_COOL,
#line 4219
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 4220
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 4222
            .species = SPECIES_SPEAROW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4224
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 4223
            .lvl = 29,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 4226
            .species = SPECIES_FEAROW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4228
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 4227
            .lvl = 29,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 4230
    [DIFFICULTY_NORMAL][TRAINER_BIRD_KEEPER_EDWIN] =
    {
#line 4231
        .trainerName = _("EDWIN"),
#line 4232
        .trainerClass = TRAINER_CLASS_BIRD_KEEPER,
#line 4233
        .trainerPic = TRAINER_PIC_BIRD_KEEPER,
        .encounterMusic_gender =
#line 4235
            TRAINER_ENCOUNTER_MUSIC_COOL,
#line 4236
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 4237
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 4,
        .party = (const struct TrainerMon[])
        {
            {
#line 4239
            .species = SPECIES_PIDGEOTTO,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4241
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 4240
            .lvl = 26,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 4243
            .species = SPECIES_FARFETCHD,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4245
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 4244
            .lvl = 26,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 4247
            .species = SPECIES_DODUO,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4249
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 4248
            .lvl = 26,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 4251
            .species = SPECIES_PIDGEY,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4253
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 4252
            .lvl = 26,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 4255
    [DIFFICULTY_NORMAL][TRAINER_BIRD_KEEPER_CHESTER] =
    {
#line 4256
        .trainerName = _("CHESTER"),
#line 4257
        .trainerClass = TRAINER_CLASS_BIRD_KEEPER,
#line 4258
        .trainerPic = TRAINER_PIC_BIRD_KEEPER,
        .encounterMusic_gender =
#line 4260
            TRAINER_ENCOUNTER_MUSIC_COOL,
#line 4261
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 4262
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 4264
            .species = SPECIES_DODRIO,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4266
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 4265
            .lvl = 28,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 4268
            .species = SPECIES_DODUO,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4270
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 4269
            .lvl = 28,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 4272
            .species = SPECIES_DODUO,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4274
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 4273
            .lvl = 28,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 4276
    [DIFFICULTY_NORMAL][TRAINER_BIRD_KEEPER_WILTON] =
    {
#line 4277
        .trainerName = _("WILTON"),
#line 4278
        .trainerClass = TRAINER_CLASS_BIRD_KEEPER,
#line 4279
        .trainerPic = TRAINER_PIC_BIRD_KEEPER,
        .encounterMusic_gender =
#line 4281
            TRAINER_ENCOUNTER_MUSIC_COOL,
#line 4282
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 4283
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 4285
            .species = SPECIES_SPEAROW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4287
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 4286
            .lvl = 29,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 4289
            .species = SPECIES_FEAROW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4291
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 4290
            .lvl = 29,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 4293
    [DIFFICULTY_NORMAL][TRAINER_BIRD_KEEPER_RAMIRO] =
    {
#line 4294
        .trainerName = _("RAMIRO"),
#line 4295
        .trainerClass = TRAINER_CLASS_BIRD_KEEPER,
#line 4296
        .trainerPic = TRAINER_PIC_BIRD_KEEPER,
        .encounterMusic_gender =
#line 4298
            TRAINER_ENCOUNTER_MUSIC_COOL,
#line 4299
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 4300
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 4302
            .species = SPECIES_DODRIO,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4304
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 4303
            .lvl = 34,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 4306
    [DIFFICULTY_NORMAL][TRAINER_BIRD_KEEPER_JACOB] =
    {
#line 4307
        .trainerName = _("JACOB"),
#line 4308
        .trainerClass = TRAINER_CLASS_BIRD_KEEPER,
#line 4309
        .trainerPic = TRAINER_PIC_BIRD_KEEPER,
        .encounterMusic_gender =
#line 4311
            TRAINER_ENCOUNTER_MUSIC_COOL,
#line 4312
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 4313
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 4,
        .party = (const struct TrainerMon[])
        {
            {
#line 4315
            .species = SPECIES_SPEAROW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4317
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 4316
            .lvl = 26,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 4319
            .species = SPECIES_SPEAROW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4321
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 4320
            .lvl = 26,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 4323
            .species = SPECIES_FEAROW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4325
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 4324
            .lvl = 26,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 4327
            .species = SPECIES_SPEAROW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4329
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 4328
            .lvl = 26,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 4331
    [DIFFICULTY_NORMAL][TRAINER_BIRD_KEEPER_ROGER] =
    {
#line 4332
        .trainerName = _("ROGER"),
#line 4333
        .trainerClass = TRAINER_CLASS_BIRD_KEEPER,
#line 4334
        .trainerPic = TRAINER_PIC_BIRD_KEEPER,
        .encounterMusic_gender =
#line 4336
            TRAINER_ENCOUNTER_MUSIC_COOL,
#line 4337
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 4338
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 4340
            .species = SPECIES_FEAROW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4342
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 4341
            .lvl = 30,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 4344
            .species = SPECIES_FEAROW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4346
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 4345
            .lvl = 30,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 4348
            .species = SPECIES_PIDGEOTTO,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4350
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 4349
            .lvl = 30,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 4352
    [DIFFICULTY_NORMAL][TRAINER_BIRD_KEEPER_REED] =
    {
#line 4353
        .trainerName = _("REED"),
#line 4354
        .trainerClass = TRAINER_CLASS_BIRD_KEEPER,
#line 4355
        .trainerPic = TRAINER_PIC_BIRD_KEEPER,
        .encounterMusic_gender =
#line 4357
            TRAINER_ENCOUNTER_MUSIC_COOL,
#line 4358
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 4359
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 4,
        .party = (const struct TrainerMon[])
        {
            {
#line 4361
            .species = SPECIES_PIDGEOTTO,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4363
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 4362
            .lvl = 39,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 4365
            .species = SPECIES_PIDGEOTTO,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4367
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 4366
            .lvl = 39,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 4369
            .species = SPECIES_PIDGEY,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4371
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 4370
            .lvl = 39,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 4373
            .species = SPECIES_PIDGEOTTO,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4375
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 4374
            .lvl = 39,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 4377
    [DIFFICULTY_NORMAL][TRAINER_BIRD_KEEPER_KEITH] =
    {
#line 4378
        .trainerName = _("KEITH"),
#line 4379
        .trainerClass = TRAINER_CLASS_BIRD_KEEPER,
#line 4380
        .trainerPic = TRAINER_PIC_BIRD_KEEPER,
        .encounterMusic_gender =
#line 4382
            TRAINER_ENCOUNTER_MUSIC_COOL,
#line 4383
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 4384
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 4386
            .species = SPECIES_FARFETCHD,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4388
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 4387
            .lvl = 39,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 4390
            .species = SPECIES_FEAROW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4392
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 4391
            .lvl = 39,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 4394
    [DIFFICULTY_NORMAL][TRAINER_BIRD_KEEPER_CARTER] =
    {
#line 4395
        .trainerName = _("CARTER"),
#line 4396
        .trainerClass = TRAINER_CLASS_BIRD_KEEPER,
#line 4397
        .trainerPic = TRAINER_PIC_BIRD_KEEPER,
        .encounterMusic_gender =
#line 4399
            TRAINER_ENCOUNTER_MUSIC_COOL,
#line 4400
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 4401
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 4403
            .species = SPECIES_PIDGEY,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4405
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 4404
            .lvl = 28,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 4407
            .species = SPECIES_DODUO,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4409
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 4408
            .lvl = 28,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 4411
            .species = SPECIES_PIDGEOTTO,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4413
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 4412
            .lvl = 28,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 4415
    [DIFFICULTY_NORMAL][TRAINER_BIRD_KEEPER_MITCH] =
    {
#line 4416
        .trainerName = _("MITCH"),
#line 4417
        .trainerClass = TRAINER_CLASS_BIRD_KEEPER,
#line 4418
        .trainerPic = TRAINER_PIC_BIRD_KEEPER,
        .encounterMusic_gender =
#line 4420
            TRAINER_ENCOUNTER_MUSIC_COOL,
#line 4421
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 4422
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 4,
        .party = (const struct TrainerMon[])
        {
            {
#line 4424
            .species = SPECIES_PIDGEY,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4426
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 4425
            .lvl = 26,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 4428
            .species = SPECIES_SPEAROW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4430
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 4429
            .lvl = 26,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 4432
            .species = SPECIES_PIDGEY,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4434
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 4433
            .lvl = 26,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 4436
            .species = SPECIES_FEAROW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4438
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 4437
            .lvl = 26,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 4440
    [DIFFICULTY_NORMAL][TRAINER_BIRD_KEEPER_BECK] =
    {
#line 4441
        .trainerName = _("BECK"),
#line 4442
        .trainerClass = TRAINER_CLASS_BIRD_KEEPER,
#line 4443
        .trainerPic = TRAINER_PIC_BIRD_KEEPER,
        .encounterMusic_gender =
#line 4445
            TRAINER_ENCOUNTER_MUSIC_COOL,
#line 4446
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 4447
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 4449
            .species = SPECIES_PIDGEOTTO,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4451
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 4450
            .lvl = 29,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 4453
            .species = SPECIES_FEAROW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4455
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 4454
            .lvl = 29,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 4457
    [DIFFICULTY_NORMAL][TRAINER_BIRD_KEEPER_MARLON] =
    {
#line 4458
        .trainerName = _("MARLON"),
#line 4459
        .trainerClass = TRAINER_CLASS_BIRD_KEEPER,
#line 4460
        .trainerPic = TRAINER_PIC_BIRD_KEEPER,
        .encounterMusic_gender =
#line 4462
            TRAINER_ENCOUNTER_MUSIC_COOL,
#line 4463
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 4464
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 4466
            .species = SPECIES_SPEAROW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4468
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 4467
            .lvl = 28,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 4470
            .species = SPECIES_DODUO,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4472
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 4471
            .lvl = 28,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 4474
            .species = SPECIES_FEAROW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4476
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 4475
            .lvl = 28,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 4478
    [DIFFICULTY_NORMAL][TRAINER_BLACK_BELT_KOICHI] =
    {
#line 4479
        .trainerName = _("KOICHI"),
#line 4480
        .trainerClass = TRAINER_CLASS_BLACK_BELT,
#line 4481
        .trainerPic = TRAINER_PIC_BLACK_BELT,
        .encounterMusic_gender =
#line 4483
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
#line 4484
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 4485
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 4487
            .species = SPECIES_HITMONLEE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4487
            .heldItem = ITEM_BLACK_BELT,
#line 4489
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 4488
            .lvl = 37,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 4491
            .species = SPECIES_HITMONCHAN,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4491
            .heldItem = ITEM_BLACK_BELT,
#line 4493
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 4492
            .lvl = 37,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 4495
    [DIFFICULTY_NORMAL][TRAINER_BLACK_BELT_MIKE] =
    {
#line 4496
        .trainerName = _("MIKE"),
#line 4497
        .trainerClass = TRAINER_CLASS_BLACK_BELT,
#line 4498
        .trainerPic = TRAINER_PIC_BLACK_BELT,
        .encounterMusic_gender =
#line 4500
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
#line 4501
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 4502
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 4504
            .species = SPECIES_MANKEY,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4504
            .heldItem = ITEM_BLACK_BELT,
#line 4506
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 4505
            .lvl = 31,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 4508
            .species = SPECIES_MANKEY,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4508
            .heldItem = ITEM_BLACK_BELT,
#line 4510
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 4509
            .lvl = 31,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 4512
            .species = SPECIES_PRIMEAPE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4512
            .heldItem = ITEM_BLACK_BELT,
#line 4514
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 4513
            .lvl = 31,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 4516
    [DIFFICULTY_NORMAL][TRAINER_BLACK_BELT_HIDEKI] =
    {
#line 4517
        .trainerName = _("HIDEKI"),
#line 4518
        .trainerClass = TRAINER_CLASS_BLACK_BELT,
#line 4519
        .trainerPic = TRAINER_PIC_BLACK_BELT,
        .encounterMusic_gender =
#line 4521
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
#line 4522
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 4523
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 4525
            .species = SPECIES_MACHOP,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4525
            .heldItem = ITEM_BLACK_BELT,
#line 4527
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 4526
            .lvl = 32,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 4529
            .species = SPECIES_MACHOKE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4529
            .heldItem = ITEM_BLACK_BELT,
#line 4531
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 4530
            .lvl = 32,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 4533
    [DIFFICULTY_NORMAL][TRAINER_BLACK_BELT_AARON] =
    {
#line 4534
        .trainerName = _("AARON"),
#line 4535
        .trainerClass = TRAINER_CLASS_BLACK_BELT,
#line 4536
        .trainerPic = TRAINER_PIC_BLACK_BELT,
        .encounterMusic_gender =
#line 4538
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
#line 4539
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 4540
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 4542
            .species = SPECIES_PRIMEAPE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4542
            .heldItem = ITEM_BLACK_BELT,
#line 4544
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 4543
            .lvl = 36,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 4546
    [DIFFICULTY_NORMAL][TRAINER_BLACK_BELT_HITOSHI] =
    {
#line 4547
        .trainerName = _("HITOSHI"),
#line 4548
        .trainerClass = TRAINER_CLASS_BLACK_BELT,
#line 4549
        .trainerPic = TRAINER_PIC_BLACK_BELT,
        .encounterMusic_gender =
#line 4551
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
#line 4552
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 4553
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 4555
            .species = SPECIES_MACHOP,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4555
            .heldItem = ITEM_BLACK_BELT,
#line 4557
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 4556
            .lvl = 31,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 4559
            .species = SPECIES_MANKEY,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4559
            .heldItem = ITEM_BLACK_BELT,
#line 4561
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 4560
            .lvl = 31,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 4563
            .species = SPECIES_PRIMEAPE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4563
            .heldItem = ITEM_BLACK_BELT,
#line 4565
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 4564
            .lvl = 31,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 4567
    [DIFFICULTY_NORMAL][TRAINER_BLACK_BELT_ATSUSHI] =
    {
#line 4568
        .trainerName = _("ATSUSHI"),
#line 4569
        .trainerClass = TRAINER_CLASS_BLACK_BELT,
#line 4570
        .trainerPic = TRAINER_PIC_BLACK_BELT,
        .encounterMusic_gender =
#line 4572
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
#line 4573
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 4574
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 4576
            .species = SPECIES_MACHOP,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4576
            .heldItem = ITEM_BLACK_BELT,
#line 4578
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 4577
            .lvl = 40,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 4580
            .species = SPECIES_MACHOKE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4580
            .heldItem = ITEM_BLACK_BELT,
#line 4582
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 4581
            .lvl = 40,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 4584
    [DIFFICULTY_NORMAL][TRAINER_BLACK_BELT_KIYO] =
    {
#line 4585
        .trainerName = _("KIYO"),
#line 4586
        .trainerClass = TRAINER_CLASS_BLACK_BELT,
#line 4587
        .trainerPic = TRAINER_PIC_BLACK_BELT,
        .encounterMusic_gender =
#line 4589
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
#line 4590
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 4591
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 4593
            .species = SPECIES_MACHOKE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4593
            .heldItem = ITEM_BLACK_BELT,
#line 4595
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 4594
            .lvl = 43,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 4597
    [DIFFICULTY_NORMAL][TRAINER_BLACK_BELT_TAKASHI] =
    {
#line 4598
        .trainerName = _("TAKASHI"),
#line 4599
        .trainerClass = TRAINER_CLASS_BLACK_BELT,
#line 4600
        .trainerPic = TRAINER_PIC_BLACK_BELT,
        .encounterMusic_gender =
#line 4602
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
#line 4603
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 4604
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 4606
            .species = SPECIES_MACHOKE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4606
            .heldItem = ITEM_BLACK_BELT,
#line 4608
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 4607
            .lvl = 38,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 4610
            .species = SPECIES_MACHOP,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4610
            .heldItem = ITEM_BLACK_BELT,
#line 4612
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 4611
            .lvl = 38,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 4614
            .species = SPECIES_MACHOKE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4614
            .heldItem = ITEM_BLACK_BELT,
#line 4616
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 4615
            .lvl = 38,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 4618
    [DIFFICULTY_NORMAL][TRAINER_BLACK_BELT_DAISUKE] =
    {
#line 4619
        .trainerName = _("DAISUKE"),
#line 4620
        .trainerClass = TRAINER_CLASS_BLACK_BELT,
#line 4621
        .trainerPic = TRAINER_PIC_BLACK_BELT,
        .encounterMusic_gender =
#line 4623
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
#line 4624
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 4625
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 4627
            .species = SPECIES_MACHOKE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4627
            .heldItem = ITEM_BLACK_BELT,
#line 4629
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 4628
            .lvl = 43,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 4631
            .species = SPECIES_MACHOP,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4631
            .heldItem = ITEM_BLACK_BELT,
#line 4633
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 4632
            .lvl = 43,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 4635
            .species = SPECIES_MACHOKE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4635
            .heldItem = ITEM_BLACK_BELT,
#line 4637
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 4636
            .lvl = 43,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 4639
    [DIFFICULTY_NORMAL][TRAINER_RIVAL_OAKS_LAB_SQUIRTLE] =
    {
#line 4640
        .trainerName = _("TERRY"),
#line 4641
        .trainerClass = TRAINER_CLASS_RIVAL_EARLY,
#line 4642
        .trainerPic = TRAINER_PIC_RIVAL_EARLY,
        .encounterMusic_gender =
#line 4644
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 4645
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 4646
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 4648
            .species = SPECIES_SQUIRTLE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4650
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 4649
            .lvl = 5,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 4651
                MOVE_TACKLE,
                MOVE_TAIL_WHIP,
            },
            },
        },
    },
#line 4654
    [DIFFICULTY_NORMAL][TRAINER_RIVAL_OAKS_LAB_BULBASAUR] =
    {
#line 4655
        .trainerName = _("TERRY"),
#line 4656
        .trainerClass = TRAINER_CLASS_RIVAL_EARLY,
#line 4657
        .trainerPic = TRAINER_PIC_RIVAL_EARLY,
        .encounterMusic_gender =
#line 4659
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 4660
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 4661
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 4663
            .species = SPECIES_BULBASAUR,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4665
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 4664
            .lvl = 5,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 4666
                MOVE_TACKLE,
                MOVE_GROWL,
            },
            },
        },
    },
#line 4669
    [DIFFICULTY_NORMAL][TRAINER_RIVAL_OAKS_LAB_CHARMANDER] =
    {
#line 4670
        .trainerName = _("TERRY"),
#line 4671
        .trainerClass = TRAINER_CLASS_RIVAL_EARLY,
#line 4672
        .trainerPic = TRAINER_PIC_RIVAL_EARLY,
        .encounterMusic_gender =
#line 4674
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 4675
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 4676
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 4678
            .species = SPECIES_CHARMANDER,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4680
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 4679
            .lvl = 5,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 4681
                MOVE_SCRATCH,
                MOVE_GROWL,
            },
            },
        },
    },
#line 4684
    [DIFFICULTY_NORMAL][TRAINER_RIVAL_ROUTE22_EARLY_SQUIRTLE] =
    {
#line 4685
        .trainerName = _("TERRY"),
#line 4686
        .trainerClass = TRAINER_CLASS_RIVAL_EARLY,
#line 4687
        .trainerPic = TRAINER_PIC_RIVAL_EARLY,
        .encounterMusic_gender =
#line 4689
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 4690
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 4691
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 4693
            .species = SPECIES_PIDGEY,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4695
            .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
#line 4694
            .lvl = 9,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 4696
                MOVE_TACKLE,
                MOVE_SAND_ATTACK,
            },
            },
            {
#line 4699
            .species = SPECIES_SQUIRTLE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4701
            .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
#line 4700
            .lvl = 9,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 4702
                MOVE_TACKLE,
                MOVE_TAIL_WHIP,
            },
            },
        },
    },
#line 4705
    [DIFFICULTY_NORMAL][TRAINER_RIVAL_ROUTE22_EARLY_BULBASAUR] =
    {
#line 4706
        .trainerName = _("TERRY"),
#line 4707
        .trainerClass = TRAINER_CLASS_RIVAL_EARLY,
#line 4708
        .trainerPic = TRAINER_PIC_RIVAL_EARLY,
        .encounterMusic_gender =
#line 4710
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 4711
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 4712
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 4714
            .species = SPECIES_PIDGEY,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4716
            .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
#line 4715
            .lvl = 9,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 4717
                MOVE_TACKLE,
                MOVE_SAND_ATTACK,
            },
            },
            {
#line 4720
            .species = SPECIES_BULBASAUR,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4722
            .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
#line 4721
            .lvl = 9,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 4723
                MOVE_TACKLE,
                MOVE_GROWL,
            },
            },
        },
    },
#line 4726
    [DIFFICULTY_NORMAL][TRAINER_RIVAL_ROUTE22_EARLY_CHARMANDER] =
    {
#line 4727
        .trainerName = _("TERRY"),
#line 4728
        .trainerClass = TRAINER_CLASS_RIVAL_EARLY,
#line 4729
        .trainerPic = TRAINER_PIC_RIVAL_EARLY,
        .encounterMusic_gender =
#line 4731
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 4732
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 4733
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 4735
            .species = SPECIES_PIDGEY,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4737
            .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
#line 4736
            .lvl = 9,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 4738
                MOVE_TACKLE,
                MOVE_SAND_ATTACK,
            },
            },
            {
#line 4741
            .species = SPECIES_CHARMANDER,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4743
            .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
#line 4742
            .lvl = 9,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 4744
                MOVE_SCRATCH,
                MOVE_GROWL,
            },
            },
        },
    },
#line 4747
    [DIFFICULTY_NORMAL][TRAINER_RIVAL_CERULEAN_SQUIRTLE] =
    {
#line 4748
        .trainerName = _("TERRY"),
#line 4749
        .trainerClass = TRAINER_CLASS_RIVAL_EARLY,
#line 4750
        .trainerPic = TRAINER_PIC_RIVAL_EARLY,
        .encounterMusic_gender =
#line 4752
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 4753
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 4754
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .partySize = 4,
        .party = (const struct TrainerMon[])
        {
            {
#line 4756
            .species = SPECIES_PIDGEOTTO,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4758
            .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
#line 4757
            .lvl = 17,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 4759
                MOVE_TACKLE,
                MOVE_SAND_ATTACK,
                MOVE_GUST,
                MOVE_QUICK_ATTACK,
            },
            },
            {
#line 4764
            .species = SPECIES_ABRA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4766
            .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
#line 4765
            .lvl = 16,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 4767
                MOVE_TELEPORT,
            },
            },
            {
#line 4769
            .species = SPECIES_RATTATA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4771
            .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
#line 4770
            .lvl = 15,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 4772
                MOVE_TACKLE,
                MOVE_TAIL_WHIP,
                MOVE_QUICK_ATTACK,
            },
            },
            {
#line 4776
            .species = SPECIES_SQUIRTLE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4778
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 4777
            .lvl = 18,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 4779
                MOVE_TACKLE,
                MOVE_TAIL_WHIP,
                MOVE_WITHDRAW,
                MOVE_WATER_GUN,
            },
            },
        },
    },
#line 4784
    [DIFFICULTY_NORMAL][TRAINER_RIVAL_CERULEAN_BULBASAUR] =
    {
#line 4785
        .trainerName = _("TERRY"),
#line 4786
        .trainerClass = TRAINER_CLASS_RIVAL_EARLY,
#line 4787
        .trainerPic = TRAINER_PIC_RIVAL_EARLY,
        .encounterMusic_gender =
#line 4789
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 4790
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 4791
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .partySize = 4,
        .party = (const struct TrainerMon[])
        {
            {
#line 4793
            .species = SPECIES_PIDGEOTTO,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4795
            .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
#line 4794
            .lvl = 17,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 4796
                MOVE_TACKLE,
                MOVE_SAND_ATTACK,
                MOVE_GUST,
                MOVE_QUICK_ATTACK,
            },
            },
            {
#line 4801
            .species = SPECIES_ABRA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4803
            .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
#line 4802
            .lvl = 16,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 4804
                MOVE_TELEPORT,
            },
            },
            {
#line 4806
            .species = SPECIES_RATTATA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4808
            .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
#line 4807
            .lvl = 15,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 4809
                MOVE_TACKLE,
                MOVE_TAIL_WHIP,
                MOVE_QUICK_ATTACK,
            },
            },
            {
#line 4813
            .species = SPECIES_BULBASAUR,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4815
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 4814
            .lvl = 18,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 4816
                MOVE_SLEEP_POWDER,
                MOVE_POISON_POWDER,
                MOVE_VINE_WHIP,
                MOVE_LEECH_SEED,
            },
            },
        },
    },
#line 4821
    [DIFFICULTY_NORMAL][TRAINER_RIVAL_CERULEAN_CHARMANDER] =
    {
#line 4822
        .trainerName = _("TERRY"),
#line 4823
        .trainerClass = TRAINER_CLASS_RIVAL_EARLY,
#line 4824
        .trainerPic = TRAINER_PIC_RIVAL_EARLY,
        .encounterMusic_gender =
#line 4826
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 4827
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 4828
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .partySize = 4,
        .party = (const struct TrainerMon[])
        {
            {
#line 4830
            .species = SPECIES_PIDGEOTTO,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4832
            .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
#line 4831
            .lvl = 17,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 4833
                MOVE_TACKLE,
                MOVE_SAND_ATTACK,
                MOVE_GUST,
                MOVE_QUICK_ATTACK,
            },
            },
            {
#line 4838
            .species = SPECIES_ABRA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4840
            .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
#line 4839
            .lvl = 16,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 4841
                MOVE_TELEPORT,
            },
            },
            {
#line 4843
            .species = SPECIES_RATTATA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4845
            .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
#line 4844
            .lvl = 15,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 4846
                MOVE_TACKLE,
                MOVE_TAIL_WHIP,
                MOVE_QUICK_ATTACK,
            },
            },
            {
#line 4850
            .species = SPECIES_CHARMANDER,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4852
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 4851
            .lvl = 18,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 4853
                MOVE_METAL_CLAW,
                MOVE_EMBER,
                MOVE_GROWL,
                MOVE_SCRATCH,
            },
            },
        },
    },
#line 4858
    [DIFFICULTY_NORMAL][TRAINER_SCIENTIST_TED] =
    {
#line 4859
        .trainerName = _("TED"),
#line 4860
        .trainerClass = TRAINER_CLASS_SCIENTIST,
#line 4861
        .trainerPic = TRAINER_PIC_SCIENTIST,
        .encounterMusic_gender =
#line 4863
            TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
#line 4864
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 4865
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 4867
            .species = SPECIES_ELECTRODE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4869
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 4868
            .lvl = 29,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 4871
            .species = SPECIES_WEEZING,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4873
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 4872
            .lvl = 29,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 4875
    [DIFFICULTY_NORMAL][TRAINER_SCIENTIST_CONNOR] =
    {
#line 4876
        .trainerName = _("CONNOR"),
#line 4877
        .trainerClass = TRAINER_CLASS_SCIENTIST,
#line 4878
        .trainerPic = TRAINER_PIC_SCIENTIST,
        .encounterMusic_gender =
#line 4880
            TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
#line 4881
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 4882
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 4,
        .party = (const struct TrainerMon[])
        {
            {
#line 4884
            .species = SPECIES_GRIMER,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4886
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 4885
            .lvl = 26,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 4887
                MOVE_SCREECH,
                MOVE_MINIMIZE,
                MOVE_SLUDGE,
                MOVE_DISABLE,
            },
            },
            {
#line 4892
            .species = SPECIES_WEEZING,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4894
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 4893
            .lvl = 26,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 4895
                MOVE_SMOKESCREEN,
                MOVE_SLUDGE,
                MOVE_SMOG,
                MOVE_TACKLE,
            },
            },
            {
#line 4900
            .species = SPECIES_KOFFING,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4902
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 4901
            .lvl = 26,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 4903
                MOVE_SMOKESCREEN,
                MOVE_SLUDGE,
                MOVE_SMOG,
                MOVE_SELF_DESTRUCT,
            },
            },
            {
#line 4908
            .species = SPECIES_WEEZING,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4910
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 4909
            .lvl = 26,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 4911
                MOVE_SMOKESCREEN,
                MOVE_SLUDGE,
                MOVE_SMOG,
                MOVE_TACKLE,
            },
            },
        },
    },
#line 4916
    [DIFFICULTY_NORMAL][TRAINER_SCIENTIST_JERRY] =
    {
#line 4917
        .trainerName = _("JERRY"),
#line 4918
        .trainerClass = TRAINER_CLASS_SCIENTIST,
#line 4919
        .trainerPic = TRAINER_PIC_SCIENTIST,
        .encounterMusic_gender =
#line 4921
            TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
#line 4922
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 4923
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 4925
            .species = SPECIES_MAGNEMITE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4927
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 4926
            .lvl = 28,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 4929
            .species = SPECIES_VOLTORB,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4931
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 4930
            .lvl = 28,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 4933
            .species = SPECIES_MAGNETON,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4935
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 4934
            .lvl = 28,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 4937
    [DIFFICULTY_NORMAL][TRAINER_SCIENTIST_JOSE] =
    {
#line 4938
        .trainerName = _("JOSE"),
#line 4939
        .trainerClass = TRAINER_CLASS_SCIENTIST,
#line 4940
        .trainerPic = TRAINER_PIC_SCIENTIST,
        .encounterMusic_gender =
#line 4942
            TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
#line 4943
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 4944
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 4946
            .species = SPECIES_ELECTRODE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4948
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 4947
            .lvl = 29,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 4949
                MOVE_SPARK,
                MOVE_SONIC_BOOM,
                MOVE_SCREECH,
                MOVE_TACKLE,
            },
            },
            {
#line 4954
            .species = SPECIES_WEEZING,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4956
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 4955
            .lvl = 29,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 4957
                MOVE_SMOKESCREEN,
                MOVE_SLUDGE,
                MOVE_SMOG,
                MOVE_TACKLE,
            },
            },
        },
    },
#line 4962
    [DIFFICULTY_NORMAL][TRAINER_SCIENTIST_RODNEY] =
    {
#line 4963
        .trainerName = _("RODNEY"),
#line 4964
        .trainerClass = TRAINER_CLASS_SCIENTIST,
#line 4965
        .trainerPic = TRAINER_PIC_SCIENTIST,
        .encounterMusic_gender =
#line 4967
            TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
#line 4968
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 4969
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 4971
            .species = SPECIES_ELECTRODE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4973
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 4972
            .lvl = 33,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 4975
    [DIFFICULTY_NORMAL][TRAINER_SCIENTIST_BEAU] =
    {
#line 4976
        .trainerName = _("BEAU"),
#line 4977
        .trainerClass = TRAINER_CLASS_SCIENTIST,
#line 4978
        .trainerPic = TRAINER_PIC_SCIENTIST,
        .encounterMusic_gender =
#line 4980
            TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
#line 4981
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 4982
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 4,
        .party = (const struct TrainerMon[])
        {
            {
#line 4984
            .species = SPECIES_MAGNETON,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4986
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 4985
            .lvl = 26,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 4987
                MOVE_SPARK,
                MOVE_THUNDER_WAVE,
                MOVE_SONIC_BOOM,
                MOVE_SUPERSONIC,
            },
            },
            {
#line 4992
            .species = SPECIES_KOFFING,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4994
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 4993
            .lvl = 26,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 4995
                MOVE_SMOKESCREEN,
                MOVE_SLUDGE,
                MOVE_SMOG,
                MOVE_TACKLE,
            },
            },
            {
#line 5000
            .species = SPECIES_WEEZING,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5002
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 5001
            .lvl = 26,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 5003
                MOVE_SMOKESCREEN,
                MOVE_SLUDGE,
                MOVE_SMOG,
                MOVE_TACKLE,
            },
            },
            {
#line 5008
            .species = SPECIES_MAGNEMITE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5010
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 5009
            .lvl = 26,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 5011
                MOVE_SPARK,
                MOVE_THUNDER_WAVE,
                MOVE_SONIC_BOOM,
                MOVE_SUPERSONIC,
            },
            },
        },
    },
#line 5016
    [DIFFICULTY_NORMAL][TRAINER_SCIENTIST_TAYLOR] =
    {
#line 5017
        .trainerName = _("TAYLOR"),
#line 5018
        .trainerClass = TRAINER_CLASS_SCIENTIST,
#line 5019
        .trainerPic = TRAINER_PIC_SCIENTIST,
        .encounterMusic_gender =
#line 5021
            TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
#line 5022
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 5023
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 5,
        .party = (const struct TrainerMon[])
        {
            {
#line 5025
            .species = SPECIES_VOLTORB,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5027
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 5026
            .lvl = 25,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 5028
                MOVE_SPARK,
                MOVE_SONIC_BOOM,
                MOVE_SCREECH,
                MOVE_TACKLE,
            },
            },
            {
#line 5033
            .species = SPECIES_KOFFING,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5035
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 5034
            .lvl = 25,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 5036
                MOVE_SMOKESCREEN,
                MOVE_SLUDGE,
                MOVE_SMOG,
                MOVE_TACKLE,
            },
            },
            {
#line 5041
            .species = SPECIES_MAGNETON,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5043
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 5042
            .lvl = 25,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 5044
                MOVE_THUNDER_WAVE,
                MOVE_SONIC_BOOM,
                MOVE_SUPERSONIC,
                MOVE_THUNDER_SHOCK,
            },
            },
            {
#line 5049
            .species = SPECIES_MAGNEMITE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5051
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 5050
            .lvl = 25,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 5052
                MOVE_THUNDER_WAVE,
                MOVE_SONIC_BOOM,
                MOVE_SUPERSONIC,
                MOVE_THUNDER_SHOCK,
            },
            },
            {
#line 5057
            .species = SPECIES_KOFFING,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5059
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 5058
            .lvl = 25,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 5060
                MOVE_SMOKESCREEN,
                MOVE_SLUDGE,
                MOVE_SMOG,
                MOVE_SELF_DESTRUCT,
            },
            },
        },
    },
#line 5065
    [DIFFICULTY_NORMAL][TRAINER_SCIENTIST_JOSHUA] =
    {
#line 5066
        .trainerName = _("JOSHUA"),
#line 5067
        .trainerClass = TRAINER_CLASS_SCIENTIST,
#line 5068
        .trainerPic = TRAINER_PIC_SCIENTIST,
        .encounterMusic_gender =
#line 5070
            TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
#line 5071
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 5072
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 5074
            .species = SPECIES_ELECTRODE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5076
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 5075
            .lvl = 29,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 5078
            .species = SPECIES_MUK,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5080
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 5079
            .lvl = 29,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 5082
    [DIFFICULTY_NORMAL][TRAINER_SCIENTIST_PARKER] =
    {
#line 5083
        .trainerName = _("PARKER"),
#line 5084
        .trainerClass = TRAINER_CLASS_SCIENTIST,
#line 5085
        .trainerPic = TRAINER_PIC_SCIENTIST,
        .encounterMusic_gender =
#line 5087
            TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
#line 5088
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 5089
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 5091
            .species = SPECIES_GRIMER,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5093
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 5092
            .lvl = 29,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 5095
            .species = SPECIES_ELECTRODE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5097
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 5096
            .lvl = 29,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 5099
    [DIFFICULTY_NORMAL][TRAINER_SCIENTIST_ED] =
    {
#line 5100
        .trainerName = _("ED"),
#line 5101
        .trainerClass = TRAINER_CLASS_SCIENTIST,
#line 5102
        .trainerPic = TRAINER_PIC_SCIENTIST,
        .encounterMusic_gender =
#line 5104
            TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
#line 5105
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 5106
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 5108
            .species = SPECIES_VOLTORB,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5110
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 5109
            .lvl = 28,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 5111
                MOVE_SPARK,
                MOVE_SONIC_BOOM,
                MOVE_SCREECH,
                MOVE_TACKLE,
            },
            },
            {
#line 5116
            .species = SPECIES_KOFFING,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5118
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 5117
            .lvl = 28,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 5119
                MOVE_SMOKESCREEN,
                MOVE_SLUDGE,
                MOVE_TACKLE,
                MOVE_SMOG,
            },
            },
            {
#line 5124
            .species = SPECIES_MAGNETON,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5126
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 5125
            .lvl = 28,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 5127
                MOVE_SPARK,
                MOVE_THUNDER_WAVE,
                MOVE_SONIC_BOOM,
                MOVE_SUPERSONIC,
            },
            },
        },
    },
#line 5132
    [DIFFICULTY_NORMAL][TRAINER_SCIENTIST_TRAVIS] =
    {
#line 5133
        .trainerName = _("TRAVIS"),
#line 5134
        .trainerClass = TRAINER_CLASS_SCIENTIST,
#line 5135
        .trainerPic = TRAINER_PIC_SCIENTIST,
        .encounterMusic_gender =
#line 5137
            TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
#line 5138
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 5139
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 5141
            .species = SPECIES_MAGNEMITE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5143
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 5142
            .lvl = 29,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 5145
            .species = SPECIES_KOFFING,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5147
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 5146
            .lvl = 29,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 5149
    [DIFFICULTY_NORMAL][TRAINER_SCIENTIST_BRAYDON] =
    {
#line 5150
        .trainerName = _("BRAYDON"),
#line 5151
        .trainerClass = TRAINER_CLASS_SCIENTIST,
#line 5152
        .trainerPic = TRAINER_PIC_SCIENTIST,
        .encounterMusic_gender =
#line 5154
            TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
#line 5155
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 5156
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 5158
            .species = SPECIES_MAGNEMITE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5160
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 5159
            .lvl = 33,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 5162
            .species = SPECIES_MAGNETON,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5164
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 5163
            .lvl = 33,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 5166
            .species = SPECIES_VOLTORB,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5168
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 5167
            .lvl = 33,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 5170
    [DIFFICULTY_NORMAL][TRAINER_SCIENTIST_IVAN] =
    {
#line 5171
        .trainerName = _("IVAN"),
#line 5172
        .trainerClass = TRAINER_CLASS_SCIENTIST,
#line 5173
        .trainerPic = TRAINER_PIC_SCIENTIST,
        .encounterMusic_gender =
#line 5175
            TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
#line 5176
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 5177
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 5179
            .species = SPECIES_MAGNEMITE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5181
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 5180
            .lvl = 34,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 5183
            .species = SPECIES_ELECTRODE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5185
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 5184
            .lvl = 34,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 5187
    [DIFFICULTY_NORMAL][TRAINER_BOSS_GIOVANNI] =
    {
#line 5188
        .trainerName = _("GIOVANNI"),
#line 5189
        .trainerClass = TRAINER_CLASS_BOSS,
#line 5190
        .trainerPic = TRAINER_PIC_LEADER_GIOVANNI,
        .encounterMusic_gender =
#line 5192
            TRAINER_ENCOUNTER_MUSIC_AQUA,
#line 5193
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 5194
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 5196
            .species = SPECIES_ONIX,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5198
            .iv = TRAINER_PARTY_IVS(30, 30, 30, 30, 30, 30),
#line 5197
            .lvl = 25,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 5200
            .species = SPECIES_RHYHORN,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5202
            .iv = TRAINER_PARTY_IVS(30, 30, 30, 30, 30, 30),
#line 5201
            .lvl = 24,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 5204
            .species = SPECIES_KANGASKHAN,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5206
            .iv = TRAINER_PARTY_IVS(30, 30, 30, 30, 30, 30),
#line 5205
            .lvl = 29,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 5208
    [DIFFICULTY_NORMAL][TRAINER_BOSS_GIOVANNI_2] =
    {
#line 5209
        .trainerName = _("GIOVANNI"),
#line 5210
        .trainerClass = TRAINER_CLASS_BOSS,
#line 5211
        .trainerPic = TRAINER_PIC_LEADER_GIOVANNI,
        .encounterMusic_gender =
#line 5213
            TRAINER_ENCOUNTER_MUSIC_AQUA,
#line 5214
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 5215
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 4,
        .party = (const struct TrainerMon[])
        {
            {
#line 5217
            .species = SPECIES_NIDORINO,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5219
            .iv = TRAINER_PARTY_IVS(30, 30, 30, 30, 30, 30),
#line 5218
            .lvl = 37,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 5221
            .species = SPECIES_KANGASKHAN,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5223
            .iv = TRAINER_PARTY_IVS(30, 30, 30, 30, 30, 30),
#line 5222
            .lvl = 35,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 5225
            .species = SPECIES_RHYHORN,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5227
            .iv = TRAINER_PARTY_IVS(30, 30, 30, 30, 30, 30),
#line 5226
            .lvl = 37,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 5229
            .species = SPECIES_NIDOQUEEN,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5231
            .iv = TRAINER_PARTY_IVS(30, 30, 30, 30, 30, 30),
#line 5230
            .lvl = 41,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 5233
    [DIFFICULTY_NORMAL][TRAINER_LEADER_GIOVANNI] =
    {
#line 5234
        .trainerName = _("GIOVANNI"),
#line 5235
        .trainerClass = TRAINER_CLASS_LEADER,
#line 5236
        .trainerPic = TRAINER_PIC_LEADER_GIOVANNI,
        .encounterMusic_gender =
#line 5238
            TRAINER_ENCOUNTER_MUSIC_AQUA,
#line 5239
        .items = { ITEM_HYPER_POTION, ITEM_HYPER_POTION, ITEM_FULL_HEAL },
#line 5240
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 5241
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .partySize = 5,
        .party = (const struct TrainerMon[])
        {
            {
#line 5243
            .species = SPECIES_RHYHORN,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5245
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 5244
            .lvl = 45,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 5246
                MOVE_TAKE_DOWN,
                MOVE_ROCK_BLAST,
                MOVE_SCARY_FACE,
                MOVE_EARTHQUAKE,
            },
            },
            {
#line 5251
            .species = SPECIES_DUGTRIO,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5253
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 5252
            .lvl = 42,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 5254
                MOVE_SLASH,
                MOVE_SAND_TOMB,
                MOVE_MUD_SLAP,
                MOVE_EARTHQUAKE,
            },
            },
            {
#line 5259
            .species = SPECIES_NIDOQUEEN,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5261
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 5260
            .lvl = 44,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 5262
                MOVE_BODY_SLAM,
                MOVE_DOUBLE_KICK,
                MOVE_POISON_STING,
                MOVE_EARTHQUAKE,
            },
            },
            {
#line 5267
            .species = SPECIES_NIDOKING,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5269
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 5268
            .lvl = 45,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 5270
                MOVE_THRASH,
                MOVE_DOUBLE_KICK,
                MOVE_POISON_STING,
                MOVE_EARTHQUAKE,
            },
            },
            {
#line 5275
            .species = SPECIES_RHYHORN,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5277
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 5276
            .lvl = 50,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 5278
                MOVE_TAKE_DOWN,
                MOVE_ROCK_BLAST,
                MOVE_SCARY_FACE,
                MOVE_EARTHQUAKE,
            },
            },
        },
    },
#line 5283
    [DIFFICULTY_NORMAL][TRAINER_TEAM_ROCKET_GRUNT] =
    {
#line 5284
        .trainerName = _("GRUNT"),
#line 5285
        .trainerClass = TRAINER_CLASS_TEAM_ROCKET,
#line 5286
        .trainerPic = TRAINER_PIC_ROCKET_GRUNT_M,
        .encounterMusic_gender =
#line 5288
            TRAINER_ENCOUNTER_MUSIC_AQUA,
#line 5289
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 5290
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 5292
            .species = SPECIES_RATTATA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5294
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 5293
            .lvl = 13,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 5296
            .species = SPECIES_ZUBAT,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5298
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 5297
            .lvl = 13,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 5300
    [DIFFICULTY_NORMAL][TRAINER_TEAM_ROCKET_GRUNT_2] =
    {
#line 5301
        .trainerName = _("GRUNT"),
#line 5302
        .trainerClass = TRAINER_CLASS_TEAM_ROCKET,
#line 5303
        .trainerPic = TRAINER_PIC_ROCKET_GRUNT_M,
        .encounterMusic_gender =
#line 5305
            TRAINER_ENCOUNTER_MUSIC_AQUA,
#line 5306
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 5307
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 5309
            .species = SPECIES_SANDSHREW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5311
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 5310
            .lvl = 11,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 5313
            .species = SPECIES_RATTATA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5315
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 5314
            .lvl = 11,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 5317
            .species = SPECIES_ZUBAT,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5319
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 5318
            .lvl = 11,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 5321
    [DIFFICULTY_NORMAL][TRAINER_TEAM_ROCKET_GRUNT_3] =
    {
#line 5322
        .trainerName = _("GRUNT"),
#line 5323
        .trainerClass = TRAINER_CLASS_TEAM_ROCKET,
#line 5324
        .trainerPic = TRAINER_PIC_ROCKET_GRUNT_M,
        .encounterMusic_gender =
#line 5326
            TRAINER_ENCOUNTER_MUSIC_AQUA,
#line 5327
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 5328
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 5330
            .species = SPECIES_ZUBAT,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5332
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 5331
            .lvl = 11,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 5334
            .species = SPECIES_EKANS,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5336
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 5335
            .lvl = 11,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 5338
    [DIFFICULTY_NORMAL][TRAINER_TEAM_ROCKET_GRUNT_4] =
    {
#line 5339
        .trainerName = _("GRUNT"),
#line 5340
        .trainerClass = TRAINER_CLASS_TEAM_ROCKET,
#line 5341
        .trainerPic = TRAINER_PIC_ROCKET_GRUNT_M,
        .encounterMusic_gender =
#line 5343
            TRAINER_ENCOUNTER_MUSIC_AQUA,
#line 5344
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 5345
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 5347
            .species = SPECIES_RATTATA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5349
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 5348
            .lvl = 13,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 5351
            .species = SPECIES_SANDSHREW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5353
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 5352
            .lvl = 13,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 5355
    [DIFFICULTY_NORMAL][TRAINER_TEAM_ROCKET_GRUNT_5] =
    {
#line 5356
        .trainerName = _("GRUNT"),
#line 5357
        .trainerClass = TRAINER_CLASS_TEAM_ROCKET,
#line 5358
        .trainerPic = TRAINER_PIC_ROCKET_GRUNT_M,
        .encounterMusic_gender =
#line 5360
            TRAINER_ENCOUNTER_MUSIC_AQUA,
#line 5361
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 5362
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 5364
            .species = SPECIES_MACHOP,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5366
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 5365
            .lvl = 17,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 5368
            .species = SPECIES_DROWZEE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5370
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 5369
            .lvl = 17,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 5372
    [DIFFICULTY_NORMAL][TRAINER_TEAM_ROCKET_GRUNT_6] =
    {
#line 5373
        .trainerName = _("GRUNT"),
#line 5374
        .trainerClass = TRAINER_CLASS_TEAM_ROCKET,
#line 5375
        .trainerPic = TRAINER_PIC_ROCKET_GRUNT_M,
        .encounterMusic_gender =
#line 5377
            TRAINER_ENCOUNTER_MUSIC_AQUA,
#line 5378
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 5379
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 5381
            .species = SPECIES_EKANS,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5383
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 5382
            .lvl = 15,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 5385
            .species = SPECIES_ZUBAT,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5387
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 5386
            .lvl = 15,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 5389
    [DIFFICULTY_NORMAL][TRAINER_TEAM_ROCKET_GRUNT_7] =
    {
#line 5390
        .trainerName = _("GRUNT"),
#line 5391
        .trainerClass = TRAINER_CLASS_TEAM_ROCKET,
#line 5392
        .trainerPic = TRAINER_PIC_ROCKET_GRUNT_M,
        .encounterMusic_gender =
#line 5394
            TRAINER_ENCOUNTER_MUSIC_AQUA,
#line 5395
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 5396
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 5398
            .species = SPECIES_RATICATE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5400
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 5399
            .lvl = 20,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 5402
            .species = SPECIES_ZUBAT,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5404
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 5403
            .lvl = 20,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 5406
    [DIFFICULTY_NORMAL][TRAINER_TEAM_ROCKET_GRUNT_8] =
    {
#line 5407
        .trainerName = _("GRUNT"),
#line 5408
        .trainerClass = TRAINER_CLASS_TEAM_ROCKET,
#line 5409
        .trainerPic = TRAINER_PIC_ROCKET_GRUNT_M,
        .encounterMusic_gender =
#line 5411
            TRAINER_ENCOUNTER_MUSIC_AQUA,
#line 5412
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 5413
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 5415
            .species = SPECIES_DROWZEE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5417
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 5416
            .lvl = 21,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 5419
            .species = SPECIES_MACHOP,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5421
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 5420
            .lvl = 21,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 5423
    [DIFFICULTY_NORMAL][TRAINER_TEAM_ROCKET_GRUNT_9] =
    {
#line 5424
        .trainerName = _("GRUNT"),
#line 5425
        .trainerClass = TRAINER_CLASS_TEAM_ROCKET,
#line 5426
        .trainerPic = TRAINER_PIC_ROCKET_GRUNT_M,
        .encounterMusic_gender =
#line 5428
            TRAINER_ENCOUNTER_MUSIC_AQUA,
#line 5429
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 5430
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 5432
            .species = SPECIES_RATICATE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5434
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 5433
            .lvl = 21,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 5436
            .species = SPECIES_RATICATE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5438
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 5437
            .lvl = 21,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 5440
    [DIFFICULTY_NORMAL][TRAINER_TEAM_ROCKET_GRUNT_10] =
    {
#line 5441
        .trainerName = _("GRUNT"),
#line 5442
        .trainerClass = TRAINER_CLASS_TEAM_ROCKET,
#line 5443
        .trainerPic = TRAINER_PIC_ROCKET_GRUNT_M,
        .encounterMusic_gender =
#line 5445
            TRAINER_ENCOUNTER_MUSIC_AQUA,
#line 5446
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 5447
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 5449
            .species = SPECIES_GRIMER,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5451
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 5450
            .lvl = 20,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 5452
                MOVE_MINIMIZE,
                MOVE_SLUDGE,
                MOVE_DISABLE,
                MOVE_HARDEN,
            },
            },
            {
#line 5457
            .species = SPECIES_KOFFING,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5459
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 5458
            .lvl = 20,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 5460
                MOVE_SMOG,
                MOVE_TACKLE,
                MOVE_POISON_GAS,
            },
            },
            {
#line 5464
            .species = SPECIES_KOFFING,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5466
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 5465
            .lvl = 20,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 5467
                MOVE_SMOG,
                MOVE_TACKLE,
                MOVE_POISON_GAS,
            },
            },
        },
    },
#line 5471
    [DIFFICULTY_NORMAL][TRAINER_TEAM_ROCKET_GRUNT_11] =
    {
#line 5472
        .trainerName = _("GRUNT"),
#line 5473
        .trainerClass = TRAINER_CLASS_TEAM_ROCKET,
#line 5474
        .trainerPic = TRAINER_PIC_ROCKET_GRUNT_M,
        .encounterMusic_gender =
#line 5476
            TRAINER_ENCOUNTER_MUSIC_AQUA,
#line 5477
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 5478
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 4,
        .party = (const struct TrainerMon[])
        {
            {
#line 5480
            .species = SPECIES_RATTATA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5482
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 5481
            .lvl = 19,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 5484
            .species = SPECIES_RATICATE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5486
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 5485
            .lvl = 19,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 5488
            .species = SPECIES_RATICATE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5490
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 5489
            .lvl = 19,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 5492
            .species = SPECIES_RATTATA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5494
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 5493
            .lvl = 19,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 5496
    [DIFFICULTY_NORMAL][TRAINER_TEAM_ROCKET_GRUNT_12] =
    {
#line 5497
        .trainerName = _("GRUNT"),
#line 5498
        .trainerClass = TRAINER_CLASS_TEAM_ROCKET,
#line 5499
        .trainerPic = TRAINER_PIC_ROCKET_GRUNT_M,
        .encounterMusic_gender =
#line 5501
            TRAINER_ENCOUNTER_MUSIC_AQUA,
#line 5502
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 5503
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 5505
            .species = SPECIES_GRIMER,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5507
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 5506
            .lvl = 22,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 5508
                MOVE_MINIMIZE,
                MOVE_SLUDGE,
                MOVE_DISABLE,
                MOVE_HARDEN,
            },
            },
            {
#line 5513
            .species = SPECIES_KOFFING,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5515
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 5514
            .lvl = 22,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 5516
                MOVE_SLUDGE,
                MOVE_SMOG,
                MOVE_TACKLE,
                MOVE_POISON_GAS,
            },
            },
        },
    },
#line 5521
    [DIFFICULTY_NORMAL][TRAINER_TEAM_ROCKET_GRUNT_13] =
    {
#line 5522
        .trainerName = _("GRUNT"),
#line 5523
        .trainerClass = TRAINER_CLASS_TEAM_ROCKET,
#line 5524
        .trainerPic = TRAINER_PIC_ROCKET_GRUNT_M,
        .encounterMusic_gender =
#line 5526
            TRAINER_ENCOUNTER_MUSIC_AQUA,
#line 5527
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 5528
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 5,
        .party = (const struct TrainerMon[])
        {
            {
#line 5530
            .species = SPECIES_ZUBAT,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5532
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 5531
            .lvl = 17,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 5533
                MOVE_BITE,
                MOVE_ASTONISH,
                MOVE_SUPERSONIC,
                MOVE_LEECH_LIFE,
            },
            },
            {
#line 5538
            .species = SPECIES_KOFFING,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5540
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 5539
            .lvl = 17,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 5541
                MOVE_SMOG,
                MOVE_TACKLE,
                MOVE_POISON_GAS,
            },
            },
            {
#line 5545
            .species = SPECIES_GRIMER,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5547
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 5546
            .lvl = 17,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 5548
                MOVE_SLUDGE,
                MOVE_DISABLE,
                MOVE_HARDEN,
                MOVE_POUND,
            },
            },
            {
#line 5553
            .species = SPECIES_ZUBAT,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5555
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 5554
            .lvl = 17,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 5556
                MOVE_BITE,
                MOVE_ASTONISH,
                MOVE_SUPERSONIC,
                MOVE_LEECH_LIFE,
            },
            },
            {
#line 5561
            .species = SPECIES_RATICATE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5563
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 5562
            .lvl = 17,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 5564
                MOVE_HYPER_FANG,
                MOVE_QUICK_ATTACK,
                MOVE_TAIL_WHIP,
                MOVE_TACKLE,
            },
            },
        },
    },
#line 5569
    [DIFFICULTY_NORMAL][TRAINER_TEAM_ROCKET_GRUNT_14] =
    {
#line 5570
        .trainerName = _("GRUNT"),
#line 5571
        .trainerClass = TRAINER_CLASS_TEAM_ROCKET,
#line 5572
        .trainerPic = TRAINER_PIC_ROCKET_GRUNT_M,
        .encounterMusic_gender =
#line 5574
            TRAINER_ENCOUNTER_MUSIC_AQUA,
#line 5575
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 5576
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 5578
            .species = SPECIES_RATTATA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5580
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 5579
            .lvl = 20,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 5582
            .species = SPECIES_RATICATE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5584
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 5583
            .lvl = 20,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 5586
            .species = SPECIES_DROWZEE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5588
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 5587
            .lvl = 20,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 5590
    [DIFFICULTY_NORMAL][TRAINER_TEAM_ROCKET_GRUNT_15] =
    {
#line 5591
        .trainerName = _("GRUNT"),
#line 5592
        .trainerClass = TRAINER_CLASS_TEAM_ROCKET,
#line 5593
        .trainerPic = TRAINER_PIC_ROCKET_GRUNT_M,
        .encounterMusic_gender =
#line 5595
            TRAINER_ENCOUNTER_MUSIC_AQUA,
#line 5596
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 5597
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 5599
            .species = SPECIES_MACHOP,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5601
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 5600
            .lvl = 21,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 5603
            .species = SPECIES_MACHOP,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5605
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 5604
            .lvl = 21,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 5607
    [DIFFICULTY_NORMAL][TRAINER_TEAM_ROCKET_GRUNT_16] =
    {
#line 5608
        .trainerName = _("GRUNT"),
#line 5609
        .trainerClass = TRAINER_CLASS_TEAM_ROCKET,
#line 5610
        .trainerPic = TRAINER_PIC_ROCKET_GRUNT_M,
        .encounterMusic_gender =
#line 5612
            TRAINER_ENCOUNTER_MUSIC_AQUA,
#line 5613
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 5614
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 5616
            .species = SPECIES_SANDSHREW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5618
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 5617
            .lvl = 23,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 5620
            .species = SPECIES_EKANS,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5622
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 5621
            .lvl = 23,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 5624
            .species = SPECIES_SANDSLASH,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5626
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 5625
            .lvl = 23,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 5628
    [DIFFICULTY_NORMAL][TRAINER_TEAM_ROCKET_GRUNT_17] =
    {
#line 5629
        .trainerName = _("GRUNT"),
#line 5630
        .trainerClass = TRAINER_CLASS_TEAM_ROCKET,
#line 5631
        .trainerPic = TRAINER_PIC_ROCKET_GRUNT_M,
        .encounterMusic_gender =
#line 5633
            TRAINER_ENCOUNTER_MUSIC_AQUA,
#line 5634
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 5635
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 5637
            .species = SPECIES_EKANS,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5639
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 5638
            .lvl = 23,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 5641
            .species = SPECIES_SANDSHREW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5643
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 5642
            .lvl = 23,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 5645
            .species = SPECIES_ARBOK,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5647
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 5646
            .lvl = 23,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 5649
    [DIFFICULTY_NORMAL][TRAINER_TEAM_ROCKET_GRUNT_18] =
    {
#line 5650
        .trainerName = _("GRUNT"),
#line 5651
        .trainerClass = TRAINER_CLASS_TEAM_ROCKET,
#line 5652
        .trainerPic = TRAINER_PIC_ROCKET_GRUNT_M,
        .encounterMusic_gender =
#line 5654
            TRAINER_ENCOUNTER_MUSIC_AQUA,
#line 5655
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 5656
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 5658
            .species = SPECIES_KOFFING,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5660
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 5659
            .lvl = 21,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 5662
            .species = SPECIES_ZUBAT,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5664
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 5663
            .lvl = 21,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 5666
    [DIFFICULTY_NORMAL][TRAINER_TEAM_ROCKET_GRUNT_19] =
    {
#line 5667
        .trainerName = _("GRUNT"),
#line 5668
        .trainerClass = TRAINER_CLASS_TEAM_ROCKET,
#line 5669
        .trainerPic = TRAINER_PIC_ROCKET_GRUNT_M,
        .encounterMusic_gender =
#line 5671
            TRAINER_ENCOUNTER_MUSIC_AQUA,
#line 5672
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 5673
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 5675
            .species = SPECIES_ZUBAT,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5677
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 5676
            .lvl = 25,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 5679
            .species = SPECIES_ZUBAT,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5681
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 5680
            .lvl = 25,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 5683
            .species = SPECIES_GOLBAT,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5685
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 5684
            .lvl = 25,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 5687
    [DIFFICULTY_NORMAL][TRAINER_TEAM_ROCKET_GRUNT_20] =
    {
#line 5688
        .trainerName = _("GRUNT"),
#line 5689
        .trainerClass = TRAINER_CLASS_TEAM_ROCKET,
#line 5690
        .trainerPic = TRAINER_PIC_ROCKET_GRUNT_M,
        .encounterMusic_gender =
#line 5692
            TRAINER_ENCOUNTER_MUSIC_AQUA,
#line 5693
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 5694
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 5696
            .species = SPECIES_KOFFING,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5698
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 5697
            .lvl = 26,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 5700
            .species = SPECIES_DROWZEE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5702
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 5701
            .lvl = 26,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 5704
    [DIFFICULTY_NORMAL][TRAINER_TEAM_ROCKET_GRUNT_21] =
    {
#line 5705
        .trainerName = _("GRUNT"),
#line 5706
        .trainerClass = TRAINER_CLASS_TEAM_ROCKET,
#line 5707
        .trainerPic = TRAINER_PIC_ROCKET_GRUNT_M,
        .encounterMusic_gender =
#line 5709
            TRAINER_ENCOUNTER_MUSIC_AQUA,
#line 5710
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 5711
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 4,
        .party = (const struct TrainerMon[])
        {
            {
#line 5713
            .species = SPECIES_ZUBAT,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5715
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 5714
            .lvl = 23,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 5717
            .species = SPECIES_RATTATA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5719
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 5718
            .lvl = 23,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 5721
            .species = SPECIES_RATICATE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5723
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 5722
            .lvl = 23,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 5725
            .species = SPECIES_ZUBAT,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5727
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 5726
            .lvl = 23,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 5729
    [DIFFICULTY_NORMAL][TRAINER_TEAM_ROCKET_GRUNT_22] =
    {
#line 5730
        .trainerName = _("GRUNT"),
#line 5731
        .trainerClass = TRAINER_CLASS_TEAM_ROCKET,
#line 5732
        .trainerPic = TRAINER_PIC_ROCKET_GRUNT_M,
        .encounterMusic_gender =
#line 5734
            TRAINER_ENCOUNTER_MUSIC_AQUA,
#line 5735
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 5736
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 5738
            .species = SPECIES_DROWZEE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5740
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 5739
            .lvl = 26,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 5742
            .species = SPECIES_KOFFING,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5744
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 5743
            .lvl = 26,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 5746
    [DIFFICULTY_NORMAL][TRAINER_TEAM_ROCKET_GRUNT_23] =
    {
#line 5747
        .trainerName = _("GRUNT"),
#line 5748
        .trainerClass = TRAINER_CLASS_TEAM_ROCKET,
#line 5749
        .trainerPic = TRAINER_PIC_ROCKET_GRUNT_M,
        .encounterMusic_gender =
#line 5751
            TRAINER_ENCOUNTER_MUSIC_AQUA,
#line 5752
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 5753
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 5755
            .species = SPECIES_CUBONE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5757
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 5756
            .lvl = 29,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 5759
            .species = SPECIES_ZUBAT,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5761
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 5760
            .lvl = 29,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 5763
    [DIFFICULTY_NORMAL][TRAINER_TEAM_ROCKET_GRUNT_24] =
    {
#line 5764
        .trainerName = _("GRUNT"),
#line 5765
        .trainerClass = TRAINER_CLASS_TEAM_ROCKET,
#line 5766
        .trainerPic = TRAINER_PIC_ROCKET_GRUNT_M,
        .encounterMusic_gender =
#line 5768
            TRAINER_ENCOUNTER_MUSIC_AQUA,
#line 5769
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 5770
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 5,
        .party = (const struct TrainerMon[])
        {
            {
#line 5772
            .species = SPECIES_GOLBAT,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5774
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 5773
            .lvl = 25,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 5776
            .species = SPECIES_ZUBAT,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5778
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 5777
            .lvl = 25,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 5780
            .species = SPECIES_ZUBAT,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5782
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 5781
            .lvl = 25,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 5784
            .species = SPECIES_RATICATE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5786
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 5785
            .lvl = 25,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 5788
            .species = SPECIES_ZUBAT,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5790
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 5789
            .lvl = 25,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 5792
    [DIFFICULTY_NORMAL][TRAINER_TEAM_ROCKET_GRUNT_25] =
    {
#line 5793
        .trainerName = _("GRUNT"),
#line 5794
        .trainerClass = TRAINER_CLASS_TEAM_ROCKET,
#line 5795
        .trainerPic = TRAINER_PIC_ROCKET_GRUNT_M,
        .encounterMusic_gender =
#line 5797
            TRAINER_ENCOUNTER_MUSIC_AQUA,
#line 5798
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 5799
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 5801
            .species = SPECIES_RATICATE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5803
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 5802
            .lvl = 28,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 5805
            .species = SPECIES_HYPNO,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5807
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 5806
            .lvl = 28,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 5809
            .species = SPECIES_RATICATE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5811
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 5810
            .lvl = 28,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 5813
    [DIFFICULTY_NORMAL][TRAINER_TEAM_ROCKET_GRUNT_26] =
    {
#line 5814
        .trainerName = _("GRUNT"),
#line 5815
        .trainerClass = TRAINER_CLASS_TEAM_ROCKET,
#line 5816
        .trainerPic = TRAINER_PIC_ROCKET_GRUNT_M,
        .encounterMusic_gender =
#line 5818
            TRAINER_ENCOUNTER_MUSIC_AQUA,
#line 5819
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 5820
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 5822
            .species = SPECIES_MACHOP,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5824
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 5823
            .lvl = 29,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 5826
            .species = SPECIES_DROWZEE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5828
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 5827
            .lvl = 29,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 5830
    [DIFFICULTY_NORMAL][TRAINER_TEAM_ROCKET_GRUNT_27] =
    {
#line 5831
        .trainerName = _("GRUNT"),
#line 5832
        .trainerClass = TRAINER_CLASS_TEAM_ROCKET,
#line 5833
        .trainerPic = TRAINER_PIC_ROCKET_GRUNT_M,
        .encounterMusic_gender =
#line 5835
            TRAINER_ENCOUNTER_MUSIC_AQUA,
#line 5836
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 5837
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 5839
            .species = SPECIES_EKANS,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5841
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 5840
            .lvl = 28,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 5843
            .species = SPECIES_ZUBAT,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5845
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 5844
            .lvl = 28,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 5847
            .species = SPECIES_CUBONE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5849
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 5848
            .lvl = 28,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 5851
    [DIFFICULTY_NORMAL][TRAINER_TEAM_ROCKET_GRUNT_28] =
    {
#line 5852
        .trainerName = _("GRUNT"),
#line 5853
        .trainerClass = TRAINER_CLASS_TEAM_ROCKET,
#line 5854
        .trainerPic = TRAINER_PIC_ROCKET_GRUNT_M,
        .encounterMusic_gender =
#line 5856
            TRAINER_ENCOUNTER_MUSIC_AQUA,
#line 5857
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 5858
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 5860
            .species = SPECIES_ARBOK,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5862
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 5861
            .lvl = 33,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 5864
    [DIFFICULTY_NORMAL][TRAINER_TEAM_ROCKET_GRUNT_29] =
    {
#line 5865
        .trainerName = _("GRUNT"),
#line 5866
        .trainerClass = TRAINER_CLASS_TEAM_ROCKET,
#line 5867
        .trainerPic = TRAINER_PIC_ROCKET_GRUNT_M,
        .encounterMusic_gender =
#line 5869
            TRAINER_ENCOUNTER_MUSIC_AQUA,
#line 5870
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 5871
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 5873
            .species = SPECIES_HYPNO,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5875
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 5874
            .lvl = 33,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 5877
    [DIFFICULTY_NORMAL][TRAINER_TEAM_ROCKET_GRUNT_30] =
    {
#line 5878
        .trainerName = _("GRUNT"),
#line 5879
        .trainerClass = TRAINER_CLASS_TEAM_ROCKET,
#line 5880
        .trainerPic = TRAINER_PIC_ROCKET_GRUNT_M,
        .encounterMusic_gender =
#line 5882
            TRAINER_ENCOUNTER_MUSIC_AQUA,
#line 5883
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 5884
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 5886
            .species = SPECIES_MACHOP,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5888
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 5887
            .lvl = 29,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 5890
            .species = SPECIES_MACHOKE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5892
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 5891
            .lvl = 29,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 5894
    [DIFFICULTY_NORMAL][TRAINER_TEAM_ROCKET_GRUNT_31] =
    {
#line 5895
        .trainerName = _("GRUNT"),
#line 5896
        .trainerClass = TRAINER_CLASS_TEAM_ROCKET,
#line 5897
        .trainerPic = TRAINER_PIC_ROCKET_GRUNT_M,
        .encounterMusic_gender =
#line 5899
            TRAINER_ENCOUNTER_MUSIC_AQUA,
#line 5900
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 5901
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 5903
            .species = SPECIES_ZUBAT,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5905
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 5904
            .lvl = 28,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 5907
            .species = SPECIES_ZUBAT,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5909
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 5908
            .lvl = 28,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 5911
            .species = SPECIES_GOLBAT,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5913
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 5912
            .lvl = 28,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 5915
    [DIFFICULTY_NORMAL][TRAINER_TEAM_ROCKET_GRUNT_32] =
    {
#line 5916
        .trainerName = _("GRUNT"),
#line 5917
        .trainerClass = TRAINER_CLASS_TEAM_ROCKET,
#line 5918
        .trainerPic = TRAINER_PIC_ROCKET_GRUNT_M,
        .encounterMusic_gender =
#line 5920
            TRAINER_ENCOUNTER_MUSIC_AQUA,
#line 5921
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 5922
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 4,
        .party = (const struct TrainerMon[])
        {
            {
#line 5924
            .species = SPECIES_RATICATE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5926
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 5925
            .lvl = 26,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 5927
                MOVE_SCARY_FACE,
                MOVE_HYPER_FANG,
                MOVE_QUICK_ATTACK,
                MOVE_TAIL_WHIP,
            },
            },
            {
#line 5932
            .species = SPECIES_ARBOK,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5934
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 5933
            .lvl = 26,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 5935
                MOVE_GLARE,
                MOVE_BITE,
                MOVE_POISON_STING,
                MOVE_LEER,
            },
            },
            {
#line 5940
            .species = SPECIES_KOFFING,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5942
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 5941
            .lvl = 26,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 5943
                MOVE_SMOKESCREEN,
                MOVE_SLUDGE,
                MOVE_SMOG,
                MOVE_TACKLE,
            },
            },
            {
#line 5948
            .species = SPECIES_GOLBAT,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5950
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 5949
            .lvl = 26,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 5951
                MOVE_WING_ATTACK,
                MOVE_BITE,
                MOVE_ASTONISH,
                MOVE_SUPERSONIC,
            },
            },
        },
    },
#line 5956
    [DIFFICULTY_NORMAL][TRAINER_TEAM_ROCKET_GRUNT_33] =
    {
#line 5957
        .trainerName = _("GRUNT"),
#line 5958
        .trainerClass = TRAINER_CLASS_TEAM_ROCKET,
#line 5959
        .trainerPic = TRAINER_PIC_ROCKET_GRUNT_M,
        .encounterMusic_gender =
#line 5961
            TRAINER_ENCOUNTER_MUSIC_AQUA,
#line 5962
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 5963
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 5965
            .species = SPECIES_CUBONE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5967
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 5966
            .lvl = 29,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 5969
            .species = SPECIES_CUBONE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5971
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 5970
            .lvl = 29,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 5973
    [DIFFICULTY_NORMAL][TRAINER_TEAM_ROCKET_GRUNT_34] =
    {
#line 5974
        .trainerName = _("GRUNT"),
#line 5975
        .trainerClass = TRAINER_CLASS_TEAM_ROCKET,
#line 5976
        .trainerPic = TRAINER_PIC_ROCKET_GRUNT_M,
        .encounterMusic_gender =
#line 5978
            TRAINER_ENCOUNTER_MUSIC_AQUA,
#line 5979
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 5980
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 5982
            .species = SPECIES_SANDSHREW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5984
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 5983
            .lvl = 29,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 5986
            .species = SPECIES_SANDSLASH,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5988
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 5987
            .lvl = 29,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 5990
    [DIFFICULTY_NORMAL][TRAINER_TEAM_ROCKET_GRUNT_35] =
    {
#line 5991
        .trainerName = _("GRUNT"),
#line 5992
        .trainerClass = TRAINER_CLASS_TEAM_ROCKET,
#line 5993
        .trainerPic = TRAINER_PIC_ROCKET_GRUNT_M,
        .encounterMusic_gender =
#line 5995
            TRAINER_ENCOUNTER_MUSIC_AQUA,
#line 5996
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 5997
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 4,
        .party = (const struct TrainerMon[])
        {
            {
#line 5999
            .species = SPECIES_RATICATE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6001
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 6000
            .lvl = 26,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 6003
            .species = SPECIES_ZUBAT,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6005
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 6004
            .lvl = 26,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 6007
            .species = SPECIES_GOLBAT,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6009
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 6008
            .lvl = 26,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 6011
            .species = SPECIES_RATTATA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6013
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 6012
            .lvl = 26,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 6015
    [DIFFICULTY_NORMAL][TRAINER_TEAM_ROCKET_GRUNT_36] =
    {
#line 6016
        .trainerName = _("GRUNT"),
#line 6017
        .trainerClass = TRAINER_CLASS_TEAM_ROCKET,
#line 6018
        .trainerPic = TRAINER_PIC_ROCKET_GRUNT_M,
        .encounterMusic_gender =
#line 6020
            TRAINER_ENCOUNTER_MUSIC_AQUA,
#line 6021
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 6022
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 6024
            .species = SPECIES_WEEZING,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6026
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 6025
            .lvl = 28,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 6028
            .species = SPECIES_GOLBAT,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6030
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 6029
            .lvl = 28,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 6032
            .species = SPECIES_KOFFING,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6034
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 6033
            .lvl = 28,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 6036
    [DIFFICULTY_NORMAL][TRAINER_TEAM_ROCKET_GRUNT_37] =
    {
#line 6037
        .trainerName = _("GRUNT"),
#line 6038
        .trainerClass = TRAINER_CLASS_TEAM_ROCKET,
#line 6039
        .trainerPic = TRAINER_PIC_ROCKET_GRUNT_M,
        .encounterMusic_gender =
#line 6041
            TRAINER_ENCOUNTER_MUSIC_AQUA,
#line 6042
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 6043
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 6045
            .species = SPECIES_DROWZEE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6047
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 6046
            .lvl = 28,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 6049
            .species = SPECIES_GRIMER,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6051
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 6050
            .lvl = 28,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 6053
            .species = SPECIES_MACHOP,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6055
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 6054
            .lvl = 28,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 6057
    [DIFFICULTY_NORMAL][TRAINER_TEAM_ROCKET_GRUNT_38] =
    {
#line 6058
        .trainerName = _("GRUNT"),
#line 6059
        .trainerClass = TRAINER_CLASS_TEAM_ROCKET,
#line 6060
        .trainerPic = TRAINER_PIC_ROCKET_GRUNT_M,
        .encounterMusic_gender =
#line 6062
            TRAINER_ENCOUNTER_MUSIC_AQUA,
#line 6063
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 6064
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 6066
            .species = SPECIES_GOLBAT,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6068
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 6067
            .lvl = 28,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 6070
            .species = SPECIES_DROWZEE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6072
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 6071
            .lvl = 28,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 6074
            .species = SPECIES_HYPNO,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6076
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 6075
            .lvl = 28,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 6078
    [DIFFICULTY_NORMAL][TRAINER_TEAM_ROCKET_GRUNT_39] =
    {
#line 6079
        .trainerName = _("GRUNT"),
#line 6080
        .trainerClass = TRAINER_CLASS_TEAM_ROCKET,
#line 6081
        .trainerPic = TRAINER_PIC_ROCKET_GRUNT_M,
        .encounterMusic_gender =
#line 6083
            TRAINER_ENCOUNTER_MUSIC_AQUA,
#line 6084
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 6085
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 6087
            .species = SPECIES_MACHOKE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6089
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 6088
            .lvl = 33,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 6091
    [DIFFICULTY_NORMAL][TRAINER_TEAM_ROCKET_GRUNT_40] =
    {
#line 6092
        .trainerName = _("GRUNT"),
#line 6093
        .trainerClass = TRAINER_CLASS_TEAM_ROCKET,
#line 6094
        .trainerPic = TRAINER_PIC_ROCKET_GRUNT_M,
        .encounterMusic_gender =
#line 6096
            TRAINER_ENCOUNTER_MUSIC_AQUA,
#line 6097
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 6098
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 5,
        .party = (const struct TrainerMon[])
        {
            {
#line 6100
            .species = SPECIES_RATTATA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6102
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 6101
            .lvl = 25,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 6104
            .species = SPECIES_RATTATA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6106
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 6105
            .lvl = 25,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 6108
            .species = SPECIES_ZUBAT,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6110
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 6109
            .lvl = 25,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 6112
            .species = SPECIES_RATTATA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6114
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 6113
            .lvl = 25,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 6116
            .species = SPECIES_EKANS,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6118
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 6117
            .lvl = 25,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 6120
    [DIFFICULTY_NORMAL][TRAINER_TEAM_ROCKET_GRUNT_41] =
    {
#line 6121
        .trainerName = _("GRUNT"),
#line 6122
        .trainerClass = TRAINER_CLASS_TEAM_ROCKET,
#line 6123
        .trainerPic = TRAINER_PIC_ROCKET_GRUNT_M,
        .encounterMusic_gender =
#line 6125
            TRAINER_ENCOUNTER_MUSIC_AQUA,
#line 6126
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 6127
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 6129
            .species = SPECIES_CUBONE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6131
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 6130
            .lvl = 32,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 6133
            .species = SPECIES_DROWZEE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6135
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 6134
            .lvl = 32,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 6137
            .species = SPECIES_MAROWAK,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6139
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 6138
            .lvl = 32,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 6141
    [DIFFICULTY_NORMAL][TRAINER_COOLTRAINER_SAMUEL] =
    {
#line 6142
        .trainerName = _("SAMUEL"),
#line 6143
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
#line 6144
        .trainerPic = TRAINER_PIC_COOLTRAINER_M,
        .encounterMusic_gender =
#line 6146
            TRAINER_ENCOUNTER_MUSIC_COOL,
#line 6147
        .items = { ITEM_SUPER_POTION },
#line 6148
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 6149
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .partySize = 5,
        .party = (const struct TrainerMon[])
        {
            {
#line 6151
            .species = SPECIES_SANDSLASH,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6153
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 6152
            .lvl = 37,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 6154
                MOVE_SLASH,
                MOVE_SWIFT,
                MOVE_SAND_ATTACK,
                MOVE_POISON_STING,
            },
            },
            {
#line 6159
            .species = SPECIES_SANDSLASH,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6161
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 6160
            .lvl = 37,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 6162
                MOVE_SLASH,
                MOVE_SWIFT,
                MOVE_SAND_ATTACK,
                MOVE_POISON_STING,
            },
            },
            {
#line 6167
            .species = SPECIES_RHYHORN,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6169
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 6168
            .lvl = 38,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 6170
                MOVE_TAKE_DOWN,
                MOVE_ROCK_BLAST,
                MOVE_FURY_ATTACK,
                MOVE_SCARY_FACE,
            },
            },
            {
#line 6175
            .species = SPECIES_NIDORINO,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6177
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 6176
            .lvl = 39,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 6178
                MOVE_FURY_ATTACK,
                MOVE_HORN_ATTACK,
                MOVE_POISON_STING,
                MOVE_DOUBLE_KICK,
            },
            },
            {
#line 6183
            .species = SPECIES_NIDOKING,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6185
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 6184
            .lvl = 39,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 6186
                MOVE_THRASH,
                MOVE_DOUBLE_KICK,
                MOVE_POISON_STING,
                MOVE_FOCUS_ENERGY,
            },
            },
        },
    },
#line 6191
    [DIFFICULTY_NORMAL][TRAINER_COOLTRAINER_GEORGE] =
    {
#line 6192
        .trainerName = _("GEORGE"),
#line 6193
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
#line 6194
        .trainerPic = TRAINER_PIC_COOLTRAINER_M,
        .encounterMusic_gender =
#line 6196
            TRAINER_ENCOUNTER_MUSIC_COOL,
#line 6197
        .items = { ITEM_HYPER_POTION },
#line 6198
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 6199
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .partySize = 5,
        .party = (const struct TrainerMon[])
        {
            {
#line 6201
            .species = SPECIES_EXEGGUTOR,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6203
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 6202
            .lvl = 42,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 6204
                MOVE_EGG_BOMB,
                MOVE_CONFUSION,
                MOVE_STUN_SPORE,
                MOVE_SLEEP_POWDER,
            },
            },
            {
#line 6209
            .species = SPECIES_SANDSLASH,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6211
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 6210
            .lvl = 42,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 6212
                MOVE_FURY_SWIPES,
                MOVE_SWIFT,
                MOVE_POISON_STING,
                MOVE_SAND_ATTACK,
            },
            },
            {
#line 6217
            .species = SPECIES_CLOYSTER,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6219
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 6218
            .lvl = 42,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 6220
                MOVE_SPIKE_CANNON,
                MOVE_SPIKES,
                MOVE_AURORA_BEAM,
                MOVE_SUPERSONIC,
            },
            },
            {
#line 6225
            .species = SPECIES_ELECTRODE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6227
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 6226
            .lvl = 42,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 6228
                MOVE_SPARK,
                MOVE_SONIC_BOOM,
                MOVE_SCREECH,
                MOVE_LIGHT_SCREEN,
            },
            },
            {
#line 6233
            .species = SPECIES_ARCANINE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6235
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 6234
            .lvl = 42,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 6236
                MOVE_FLAME_WHEEL,
                MOVE_ROAR,
                MOVE_BITE,
                MOVE_TAKE_DOWN,
            },
            },
        },
    },
#line 6241
    [DIFFICULTY_NORMAL][TRAINER_COOLTRAINER_COLBY] =
    {
#line 6242
        .trainerName = _("COLBY"),
#line 6243
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
#line 6244
        .trainerPic = TRAINER_PIC_COOLTRAINER_M,
        .encounterMusic_gender =
#line 6246
            TRAINER_ENCOUNTER_MUSIC_COOL,
#line 6247
        .items = { ITEM_HYPER_POTION },
#line 6248
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 6249
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .partySize = 5,
        .party = (const struct TrainerMon[])
        {
            {
#line 6251
            .species = SPECIES_KINGLER,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6253
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 6252
            .lvl = 41,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 6254
                MOVE_GUILLOTINE,
                MOVE_STOMP,
                MOVE_MUD_SHOT,
                MOVE_BUBBLE,
            },
            },
            {
#line 6259
            .species = SPECIES_POLIWHIRL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6261
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 6260
            .lvl = 42,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 6262
                MOVE_BODY_SLAM,
                MOVE_DOUBLE_SLAP,
                MOVE_WATER_GUN,
                MOVE_HYPNOSIS,
            },
            },
            {
#line 6267
            .species = SPECIES_TENTACRUEL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6269
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 6268
            .lvl = 42,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 6270
                MOVE_BARRIER,
                MOVE_WRAP,
                MOVE_BUBBLE_BEAM,
                MOVE_ACID,
            },
            },
            {
#line 6275
            .species = SPECIES_SEADRA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6277
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 6276
            .lvl = 42,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 6278
                MOVE_WATER_GUN,
                MOVE_SMOKESCREEN,
                MOVE_TWISTER,
                MOVE_LEER,
            },
            },
            {
#line 6283
            .species = SPECIES_BLASTOISE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6285
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 6284
            .lvl = 43,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 6286
                MOVE_WATER_GUN,
                MOVE_BITE,
                MOVE_RAPID_SPIN,
                MOVE_RAIN_DANCE,
            },
            },
        },
    },
#line 6291
    [DIFFICULTY_NORMAL][TRAINER_COOLTRAINER_PAUL] =
    {
#line 6292
        .trainerName = _("PAUL"),
#line 6293
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
#line 6294
        .trainerPic = TRAINER_PIC_COOLTRAINER_M,
        .encounterMusic_gender =
#line 6296
            TRAINER_ENCOUNTER_MUSIC_COOL,
#line 6297
        .items = { ITEM_FULL_RESTORE },
#line 6298
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 6299
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .partySize = 5,
        .party = (const struct TrainerMon[])
        {
            {
#line 6301
            .species = SPECIES_SLOWPOKE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6303
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 6302
            .lvl = 42,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 6304
                MOVE_HEADBUTT,
                MOVE_CONFUSION,
                MOVE_WATER_GUN,
                MOVE_DISABLE,
            },
            },
            {
#line 6309
            .species = SPECIES_SHELLDER,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6311
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 6310
            .lvl = 42,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 6312
                MOVE_AURORA_BEAM,
                MOVE_CLAMP,
                MOVE_SUPERSONIC,
                MOVE_LEER,
            },
            },
            {
#line 6317
            .species = SPECIES_KINGLER,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6319
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 6318
            .lvl = 42,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 6320
                MOVE_GUILLOTINE,
                MOVE_STOMP,
                MOVE_MUD_SHOT,
                MOVE_BUBBLE,
            },
            },
            {
#line 6325
            .species = SPECIES_STARMIE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6327
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 6326
            .lvl = 42,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 6328
                MOVE_BUBBLE_BEAM,
                MOVE_SWIFT,
                MOVE_RECOVER,
                MOVE_RAPID_SPIN,
            },
            },
            {
#line 6333
            .species = SPECIES_GOLDUCK,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6335
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 6334
            .lvl = 42,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 6336
                MOVE_CONFUSION,
                MOVE_SCRATCH,
                MOVE_SCREECH,
                MOVE_DISABLE,
            },
            },
        },
    },
#line 6341
    [DIFFICULTY_NORMAL][TRAINER_COOLTRAINER_ROLANDO] =
    {
#line 6342
        .trainerName = _("ROLANDO"),
#line 6343
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
#line 6344
        .trainerPic = TRAINER_PIC_COOLTRAINER_M,
        .encounterMusic_gender =
#line 6346
            TRAINER_ENCOUNTER_MUSIC_COOL,
#line 6347
        .items = { ITEM_HYPER_POTION },
#line 6348
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 6349
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .partySize = 5,
        .party = (const struct TrainerMon[])
        {
            {
#line 6351
            .species = SPECIES_RATICATE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6353
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 6352
            .lvl = 42,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 6354
                MOVE_SUPER_FANG,
                MOVE_PURSUIT,
                MOVE_SCARY_FACE,
                MOVE_QUICK_ATTACK,
            },
            },
            {
#line 6359
            .species = SPECIES_IVYSAUR,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6361
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 6360
            .lvl = 42,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 6362
                MOVE_RAZOR_LEAF,
                MOVE_SLEEP_POWDER,
                MOVE_SWEET_SCENT,
                MOVE_SYNTHESIS,
            },
            },
            {
#line 6367
            .species = SPECIES_WARTORTLE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6369
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 6368
            .lvl = 42,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 6370
                MOVE_WATER_GUN,
                MOVE_BITE,
                MOVE_RAPID_SPIN,
                MOVE_TAIL_WHIP,
            },
            },
            {
#line 6375
            .species = SPECIES_CHARMELEON,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6377
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 6376
            .lvl = 42,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 6378
                MOVE_FLAMETHROWER,
                MOVE_SLASH,
                MOVE_SMOKESCREEN,
                MOVE_SCARY_FACE,
            },
            },
            {
#line 6383
            .species = SPECIES_CHARIZARD,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6385
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 6384
            .lvl = 42,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 6386
                MOVE_FLAMETHROWER,
                MOVE_WING_ATTACK,
                MOVE_SMOKESCREEN,
                MOVE_SCARY_FACE,
            },
            },
        },
    },
#line 6391
    [DIFFICULTY_NORMAL][TRAINER_COOLTRAINER_GILBERT] =
    {
#line 6392
        .trainerName = _("GILBERT"),
#line 6393
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
#line 6394
        .trainerPic = TRAINER_PIC_COOLTRAINER_M,
        .encounterMusic_gender =
#line 6396
            TRAINER_ENCOUNTER_MUSIC_COOL,
#line 6397
        .items = { ITEM_HYPER_POTION },
#line 6398
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 6399
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .partySize = 5,
        .party = (const struct TrainerMon[])
        {
            {
#line 6401
            .species = SPECIES_PIDGEOTTO,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6403
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 6402
            .lvl = 42,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 6404
                MOVE_WING_ATTACK,
                MOVE_FEATHER_DANCE,
                MOVE_WHIRLWIND,
                MOVE_QUICK_ATTACK,
            },
            },
            {
#line 6409
            .species = SPECIES_FEAROW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6411
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 6410
            .lvl = 42,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 6412
                MOVE_DRILL_PECK,
                MOVE_MIRROR_MOVE,
                MOVE_PURSUIT,
                MOVE_LEER,
            },
            },
            {
#line 6417
            .species = SPECIES_PERSIAN,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6419
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 6418
            .lvl = 42,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 6420
                MOVE_PAY_DAY,
                MOVE_FAINT_ATTACK,
                MOVE_SCREECH,
                MOVE_BITE,
            },
            },
            {
#line 6425
            .species = SPECIES_LICKITUNG,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6427
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 6426
            .lvl = 42,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 6428
                MOVE_SLAM,
                MOVE_DISABLE,
                MOVE_WRAP,
                MOVE_SUPERSONIC,
            },
            },
            {
#line 6433
            .species = SPECIES_TAUROS,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6435
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 6434
            .lvl = 42,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 6436
                MOVE_HORN_ATTACK,
                MOVE_SCARY_FACE,
                MOVE_SWAGGER,
                MOVE_TAIL_WHIP,
            },
            },
        },
    },
#line 6441
    [DIFFICULTY_NORMAL][TRAINER_COOLTRAINER_OWEN] =
    {
#line 6442
        .trainerName = _("OWEN"),
#line 6443
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
#line 6444
        .trainerPic = TRAINER_PIC_COOLTRAINER_M,
        .encounterMusic_gender =
#line 6446
            TRAINER_ENCOUNTER_MUSIC_COOL,
#line 6447
        .items = { ITEM_HYPER_POTION },
#line 6448
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 6449
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .partySize = 5,
        .party = (const struct TrainerMon[])
        {
            {
#line 6451
            .species = SPECIES_NIDORINO,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6453
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 6452
            .lvl = 42,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 6454
                MOVE_SCRATCH,
                MOVE_POISON_STING,
                MOVE_DOUBLE_KICK,
                MOVE_BITE,
            },
            },
            {
#line 6459
            .species = SPECIES_NIDORINA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6461
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 6460
            .lvl = 42,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 6462
                MOVE_HORN_ATTACK,
                MOVE_POISON_STING,
                MOVE_DOUBLE_KICK,
                MOVE_LEER,
            },
            },
            {
#line 6467
            .species = SPECIES_RATICATE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6469
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 6468
            .lvl = 42,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 6470
                MOVE_SUPER_FANG,
                MOVE_PURSUIT,
                MOVE_SCARY_FACE,
                MOVE_QUICK_ATTACK,
            },
            },
            {
#line 6475
            .species = SPECIES_SANDSLASH,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6477
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 6476
            .lvl = 42,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 6478
                MOVE_FURY_SWIPES,
                MOVE_SWIFT,
                MOVE_SLASH,
                MOVE_POISON_STING,
            },
            },
            {
#line 6483
            .species = SPECIES_RHYHORN,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6485
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 6484
            .lvl = 42,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 6486
                MOVE_ROCK_BLAST,
                MOVE_SCARY_FACE,
                MOVE_STOMP,
                MOVE_TAIL_WHIP,
            },
            },
        },
    },
#line 6491
    [DIFFICULTY_NORMAL][TRAINER_COOLTRAINER_BERKE] =
    {
#line 6492
        .trainerName = _("BERKE"),
#line 6493
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
#line 6494
        .trainerPic = TRAINER_PIC_COOLTRAINER_M,
        .encounterMusic_gender =
#line 6496
            TRAINER_ENCOUNTER_MUSIC_COOL,
#line 6497
        .items = { ITEM_FULL_RESTORE },
#line 6498
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 6499
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .partySize = 5,
        .party = (const struct TrainerMon[])
        {
            {
#line 6501
            .species = SPECIES_SEEL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6503
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 6502
            .lvl = 42,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 6504
                MOVE_TAKE_DOWN,
                MOVE_AURORA_BEAM,
                MOVE_ICY_WIND,
                MOVE_GROWL,
            },
            },
            {
#line 6509
            .species = SPECIES_GRAVELER,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6511
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 6510
            .lvl = 42,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 6512
                MOVE_ROCK_BLAST,
                MOVE_MAGNITUDE,
                MOVE_ROCK_THROW,
                MOVE_MUD_SPORT,
            },
            },
            {
#line 6517
            .species = SPECIES_KINGLER,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6519
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 6518
            .lvl = 42,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 6520
                MOVE_GUILLOTINE,
                MOVE_STOMP,
                MOVE_MUD_SHOT,
                MOVE_BUBBLE,
            },
            },
            {
#line 6525
            .species = SPECIES_ONIX,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6527
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 6526
            .lvl = 42,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 6528
                MOVE_SLAM,
                MOVE_SANDSTORM,
                MOVE_DRAGON_BREATH,
                MOVE_ROCK_THROW,
            },
            },
            {
#line 6533
            .species = SPECIES_CLOYSTER,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6535
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 6534
            .lvl = 42,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 6536
                MOVE_SPIKE_CANNON,
                MOVE_AURORA_BEAM,
                MOVE_SUPERSONIC,
                MOVE_PROTECT,
            },
            },
        },
    },
#line 6541
    [DIFFICULTY_NORMAL][TRAINER_COOLTRAINER_YUJI] =
    {
#line 6542
        .trainerName = _("YUJI"),
#line 6543
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
#line 6544
        .trainerPic = TRAINER_PIC_COOLTRAINER_M,
        .encounterMusic_gender =
#line 6546
            TRAINER_ENCOUNTER_MUSIC_COOL,
#line 6547
        .items = { ITEM_HYPER_POTION },
#line 6548
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 6549
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .partySize = 5,
        .party = (const struct TrainerMon[])
        {
            {
#line 6551
            .species = SPECIES_SANDSLASH,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6553
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 6552
            .lvl = 38,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 6554
                MOVE_SLASH,
                MOVE_SWIFT,
                MOVE_SAND_ATTACK,
                MOVE_POISON_STING,
            },
            },
            {
#line 6559
            .species = SPECIES_GRAVELER,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6561
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 6560
            .lvl = 38,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 6562
                MOVE_ROCK_BLAST,
                MOVE_MAGNITUDE,
                MOVE_MUD_SPORT,
                MOVE_DEFENSE_CURL,
            },
            },
            {
#line 6567
            .species = SPECIES_ONIX,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6569
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 6568
            .lvl = 38,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 6570
                MOVE_DRAGON_BREATH,
                MOVE_SANDSTORM,
                MOVE_ROCK_THROW,
                MOVE_BIND,
            },
            },
            {
#line 6575
            .species = SPECIES_GRAVELER,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6577
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 6576
            .lvl = 38,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 6578
                MOVE_ROCK_BLAST,
                MOVE_MAGNITUDE,
                MOVE_ROLLOUT,
                MOVE_DEFENSE_CURL,
            },
            },
            {
#line 6583
            .species = SPECIES_MAROWAK,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6585
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 6584
            .lvl = 38,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 6586
                MOVE_BONEMERANG,
                MOVE_HEADBUTT,
                MOVE_LEER,
                MOVE_GROWL,
            },
            },
        },
    },
#line 6591
    [DIFFICULTY_NORMAL][TRAINER_COOLTRAINER_WARREN] =
    {
#line 6592
        .trainerName = _("WARREN"),
#line 6593
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
#line 6594
        .trainerPic = TRAINER_PIC_COOLTRAINER_M,
        .encounterMusic_gender =
#line 6596
            TRAINER_ENCOUNTER_MUSIC_COOL,
#line 6597
        .items = { ITEM_HYPER_POTION },
#line 6598
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 6599
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .partySize = 5,
        .party = (const struct TrainerMon[])
        {
            {
#line 6601
            .species = SPECIES_MAROWAK,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6603
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 6602
            .lvl = 37,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 6604
                MOVE_BONEMERANG,
                MOVE_HEADBUTT,
                MOVE_LEER,
                MOVE_GROWL,
            },
            },
            {
#line 6609
            .species = SPECIES_MAROWAK,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6611
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 6610
            .lvl = 37,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 6612
                MOVE_BONEMERANG,
                MOVE_HEADBUTT,
                MOVE_LEER,
                MOVE_GROWL,
            },
            },
            {
#line 6617
            .species = SPECIES_RHYHORN,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6619
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 6618
            .lvl = 38,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 6620
                MOVE_TAKE_DOWN,
                MOVE_ROCK_BLAST,
                MOVE_FURY_ATTACK,
                MOVE_SCARY_FACE,
            },
            },
            {
#line 6625
            .species = SPECIES_NIDORINA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6627
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 6626
            .lvl = 39,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 6628
                MOVE_FURY_SWIPES,
                MOVE_BITE,
                MOVE_POISON_STING,
                MOVE_DOUBLE_KICK,
            },
            },
            {
#line 6633
            .species = SPECIES_NIDOQUEEN,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6635
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 6634
            .lvl = 39,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 6636
                MOVE_BODY_SLAM,
                MOVE_BITE,
                MOVE_POISON_STING,
                MOVE_DOUBLE_KICK,
            },
            },
        },
    },
#line 6641
    [DIFFICULTY_NORMAL][TRAINER_COOLTRAINER_MARY] =
    {
#line 6642
        .trainerName = _("MARY"),
#line 6643
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
#line 6644
        .trainerPic = TRAINER_PIC_COOLTRAINER_F,
        .encounterMusic_gender =
#line 6646
            TRAINER_ENCOUNTER_MUSIC_COOL,
#line 6647
        .items = { ITEM_SUPER_POTION },
#line 6648
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 6649
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .partySize = 5,
        .party = (const struct TrainerMon[])
        {
            {
#line 6651
            .species = SPECIES_BELLSPROUT,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6653
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 6652
            .lvl = 22,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 6654
                MOVE_WRAP,
                MOVE_STUN_SPORE,
                MOVE_POISON_POWDER,
                MOVE_GROWTH,
            },
            },
            {
#line 6659
            .species = SPECIES_ODDISH,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6661
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 6660
            .lvl = 22,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 6662
                MOVE_POISON_POWDER,
                MOVE_STUN_SPORE,
                MOVE_ABSORB,
                MOVE_SWEET_SCENT,
            },
            },
            {
#line 6667
            .species = SPECIES_WEEPINBELL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6669
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 6668
            .lvl = 22,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 6670
                MOVE_VINE_WHIP,
                MOVE_STUN_SPORE,
                MOVE_POISON_POWDER,
                MOVE_GROWTH,
            },
            },
            {
#line 6675
            .species = SPECIES_GLOOM,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6677
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 6676
            .lvl = 22,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 6678
                MOVE_ABSORB,
                MOVE_STUN_SPORE,
                MOVE_POISON_POWDER,
                MOVE_SWEET_SCENT,
            },
            },
            {
#line 6683
            .species = SPECIES_IVYSAUR,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6685
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 6684
            .lvl = 22,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 6686
                MOVE_RAZOR_LEAF,
                MOVE_SLEEP_POWDER,
                MOVE_VINE_WHIP,
                MOVE_LEECH_SEED,
            },
            },
        },
    },
#line 6691
    [DIFFICULTY_NORMAL][TRAINER_COOLTRAINER_CAROLINE] =
    {
#line 6692
        .trainerName = _("CAROLINE"),
#line 6693
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
#line 6694
        .trainerPic = TRAINER_PIC_COOLTRAINER_F,
        .encounterMusic_gender =
#line 6696
            TRAINER_ENCOUNTER_MUSIC_COOL,
#line 6697
        .items = { ITEM_HYPER_POTION },
#line 6698
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 6699
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .partySize = 5,
        .party = (const struct TrainerMon[])
        {
            {
#line 6701
            .species = SPECIES_BELLSPROUT,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6703
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 6702
            .lvl = 42,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 6704
                MOVE_RAZOR_LEAF,
                MOVE_ACID,
                MOVE_STUN_SPORE,
                MOVE_POISON_POWDER,
            },
            },
            {
#line 6709
            .species = SPECIES_WEEPINBELL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6711
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 6710
            .lvl = 42,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 6712
                MOVE_RAZOR_LEAF,
                MOVE_ACID,
                MOVE_SLEEP_POWDER,
                MOVE_POISON_POWDER,
            },
            },
            {
#line 6717
            .species = SPECIES_VICTREEBEL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6719
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 6718
            .lvl = 42,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 6720
                MOVE_RAZOR_LEAF,
                MOVE_ACID,
                MOVE_STUN_SPORE,
                MOVE_SLEEP_POWDER,
            },
            },
            {
#line 6725
            .species = SPECIES_PARAS,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6727
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 6726
            .lvl = 42,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 6728
                MOVE_GROWTH,
                MOVE_SLASH,
                MOVE_LEECH_LIFE,
                MOVE_STUN_SPORE,
            },
            },
            {
#line 6733
            .species = SPECIES_PARASECT,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6735
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 6734
            .lvl = 42,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 6736
                MOVE_SPORE,
                MOVE_SLASH,
                MOVE_LEECH_LIFE,
                MOVE_POISON_POWDER,
            },
            },
        },
    },
#line 6741
    [DIFFICULTY_NORMAL][TRAINER_COOLTRAINER_ALEXA] =
    {
#line 6742
        .trainerName = _("ALEXA"),
#line 6743
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
#line 6744
        .trainerPic = TRAINER_PIC_COOLTRAINER_F,
        .encounterMusic_gender =
#line 6746
            TRAINER_ENCOUNTER_MUSIC_COOL,
#line 6747
        .items = { ITEM_FULL_RESTORE },
#line 6748
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 6749
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .partySize = 5,
        .party = (const struct TrainerMon[])
        {
            {
#line 6751
            .species = SPECIES_CLEFAIRY,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6753
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 6752
            .lvl = 42,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 6754
                MOVE_LIGHT_SCREEN,
                MOVE_COSMIC_POWER,
                MOVE_DOUBLE_SLAP,
                MOVE_ENCORE,
            },
            },
            {
#line 6759
            .species = SPECIES_JIGGLYPUFF,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6761
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 6760
            .lvl = 42,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 6762
                MOVE_SING,
                MOVE_BODY_SLAM,
                MOVE_ROLLOUT,
                MOVE_DISABLE,
            },
            },
            {
#line 6767
            .species = SPECIES_PERSIAN,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6769
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 6768
            .lvl = 42,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 6770
                MOVE_PAY_DAY,
                MOVE_FAINT_ATTACK,
                MOVE_BITE,
                MOVE_SCREECH,
            },
            },
            {
#line 6775
            .species = SPECIES_DEWGONG,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6777
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 6776
            .lvl = 42,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 6778
                MOVE_SHEER_COLD,
                MOVE_TAKE_DOWN,
                MOVE_REST,
                MOVE_AURORA_BEAM,
            },
            },
            {
#line 6783
            .species = SPECIES_CHANSEY,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6785
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 6784
            .lvl = 42,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 6786
                MOVE_SING,
                MOVE_EGG_BOMB,
                MOVE_SOFT_BOILED,
                MOVE_MINIMIZE,
            },
            },
        },
    },
#line 6791
    [DIFFICULTY_NORMAL][TRAINER_COOLTRAINER_SHANNON] =
    {
#line 6792
        .trainerName = _("SHANNON"),
#line 6793
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
#line 6794
        .trainerPic = TRAINER_PIC_COOLTRAINER_F,
        .encounterMusic_gender =
#line 6796
            TRAINER_ENCOUNTER_MUSIC_COOL,
#line 6797
        .items = { ITEM_FULL_RESTORE },
#line 6798
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 6799
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .partySize = 5,
        .party = (const struct TrainerMon[])
        {
            {
#line 6801
            .species = SPECIES_BEEDRILL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6803
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 6802
            .lvl = 42,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 6804
                MOVE_PIN_MISSILE,
                MOVE_TWINEEDLE,
                MOVE_AGILITY,
                MOVE_PURSUIT,
            },
            },
            {
#line 6809
            .species = SPECIES_BUTTERFREE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6811
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 6810
            .lvl = 42,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 6812
                MOVE_SAFEGUARD,
                MOVE_PSYBEAM,
                MOVE_GUST,
                MOVE_SUPERSONIC,
            },
            },
            {
#line 6817
            .species = SPECIES_PARASECT,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6819
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 6818
            .lvl = 42,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 6820
                MOVE_SPORE,
                MOVE_LEECH_LIFE,
                MOVE_SLASH,
                MOVE_GROWTH,
            },
            },
            {
#line 6825
            .species = SPECIES_VENONAT,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6827
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 6826
            .lvl = 42,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 6828
                MOVE_PSYBEAM,
                MOVE_STUN_SPORE,
                MOVE_LEECH_LIFE,
                MOVE_DISABLE,
            },
            },
            {
#line 6833
            .species = SPECIES_VENOMOTH,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6835
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 6834
            .lvl = 42,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 6836
                MOVE_PSYBEAM,
                MOVE_GUST,
                MOVE_SUPERSONIC,
                MOVE_LEECH_LIFE,
            },
            },
        },
    },
#line 6841
    [DIFFICULTY_NORMAL][TRAINER_COOLTRAINER_NAOMI] =
    {
#line 6842
        .trainerName = _("NAOMI"),
#line 6843
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
#line 6844
        .trainerPic = TRAINER_PIC_COOLTRAINER_F,
        .encounterMusic_gender =
#line 6846
            TRAINER_ENCOUNTER_MUSIC_COOL,
#line 6847
        .items = { ITEM_HYPER_POTION },
#line 6848
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 6849
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .partySize = 5,
        .party = (const struct TrainerMon[])
        {
            {
#line 6851
            .species = SPECIES_PERSIAN,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6853
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 6852
            .lvl = 42,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 6854
                MOVE_FURY_SWIPES,
                MOVE_SCREECH,
                MOVE_FAINT_ATTACK,
                MOVE_PAY_DAY,
            },
            },
            {
#line 6859
            .species = SPECIES_PONYTA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6861
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 6860
            .lvl = 42,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 6862
                MOVE_AGILITY,
                MOVE_TAKE_DOWN,
                MOVE_FIRE_SPIN,
                MOVE_STOMP,
            },
            },
            {
#line 6867
            .species = SPECIES_RAPIDASH,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6869
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 6868
            .lvl = 42,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 6870
                MOVE_FURY_ATTACK,
                MOVE_FIRE_SPIN,
                MOVE_STOMP,
                MOVE_GROWL,
            },
            },
            {
#line 6875
            .species = SPECIES_VULPIX,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6877
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 6876
            .lvl = 42,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 6878
                MOVE_FLAMETHROWER,
                MOVE_CONFUSE_RAY,
                MOVE_QUICK_ATTACK,
                MOVE_IMPRISON,
            },
            },
            {
#line 6883
            .species = SPECIES_NINETALES,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6885
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 6884
            .lvl = 42,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 6886
                MOVE_SAFEGUARD,
                MOVE_WILL_O_WISP,
                MOVE_CONFUSE_RAY,
                MOVE_FIRE_SPIN,
            },
            },
        },
    },
#line 6891
    [DIFFICULTY_NORMAL][TRAINER_COOLTRAINER_BROOKE] =
    {
#line 6892
        .trainerName = _("BROOKE"),
#line 6893
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
#line 6894
        .trainerPic = TRAINER_PIC_COOLTRAINER_F,
        .encounterMusic_gender =
#line 6896
            TRAINER_ENCOUNTER_MUSIC_COOL,
#line 6897
        .items = { ITEM_FULL_RESTORE },
#line 6898
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 6899
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .partySize = 5,
        .party = (const struct TrainerMon[])
        {
            {
#line 6901
            .species = SPECIES_TANGELA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6903
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 6902
            .lvl = 42,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 6904
                MOVE_SLAM,
                MOVE_BIND,
                MOVE_MEGA_DRAIN,
                MOVE_INGRAIN,
            },
            },
            {
#line 6909
            .species = SPECIES_GLOOM,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6911
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 6910
            .lvl = 42,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 6912
                MOVE_ACID,
                MOVE_MOONLIGHT,
                MOVE_SLEEP_POWDER,
                MOVE_STUN_SPORE,
            },
            },
            {
#line 6917
            .species = SPECIES_VILEPLUME,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6919
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 6918
            .lvl = 42,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 6920
                MOVE_MEGA_DRAIN,
                MOVE_ACID,
                MOVE_STUN_SPORE,
                MOVE_AROMATHERAPY,
            },
            },
            {
#line 6925
            .species = SPECIES_IVYSAUR,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6927
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 6926
            .lvl = 42,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 6928
                MOVE_RAZOR_LEAF,
                MOVE_SWEET_SCENT,
                MOVE_GROWL,
                MOVE_LEECH_SEED,
            },
            },
            {
#line 6933
            .species = SPECIES_VENUSAUR,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6935
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 6934
            .lvl = 42,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 6936
                MOVE_RAZOR_LEAF,
                MOVE_GROWTH,
                MOVE_SLEEP_POWDER,
                MOVE_POISON_POWDER,
            },
            },
        },
    },
#line 6941
    [DIFFICULTY_NORMAL][TRAINER_COOLTRAINER_AUSTINA] =
    {
#line 6942
        .trainerName = _("AUSTINA"),
#line 6943
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
#line 6944
        .trainerPic = TRAINER_PIC_COOLTRAINER_F,
        .encounterMusic_gender =
#line 6946
            TRAINER_ENCOUNTER_MUSIC_COOL,
#line 6947
        .items = { ITEM_FULL_RESTORE },
#line 6948
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 6949
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .partySize = 5,
        .party = (const struct TrainerMon[])
        {
            {
#line 6951
            .species = SPECIES_RHYHORN,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6953
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 6952
            .lvl = 42,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 6954
                MOVE_HORN_DRILL,
                MOVE_ROCK_BLAST,
                MOVE_SCARY_FACE,
                MOVE_STOMP,
            },
            },
            {
#line 6959
            .species = SPECIES_NIDORINA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6961
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 6960
            .lvl = 42,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 6962
                MOVE_DOUBLE_KICK,
                MOVE_FURY_SWIPES,
                MOVE_BITE,
                MOVE_FLATTER,
            },
            },
            {
#line 6967
            .species = SPECIES_NIDOQUEEN,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6969
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 6968
            .lvl = 42,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 6970
                MOVE_BODY_SLAM,
                MOVE_DOUBLE_KICK,
                MOVE_BITE,
                MOVE_GROWL,
            },
            },
            {
#line 6975
            .species = SPECIES_NIDORINO,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6977
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 6976
            .lvl = 42,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 6978
                MOVE_HORN_ATTACK,
                MOVE_POISON_STING,
                MOVE_FOCUS_ENERGY,
                MOVE_LEER,
            },
            },
            {
#line 6983
            .species = SPECIES_NIDOKING,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6985
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 6984
            .lvl = 42,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 6986
                MOVE_THRASH,
                MOVE_DOUBLE_KICK,
                MOVE_POISON_STING,
                MOVE_PECK,
            },
            },
        },
    },
#line 6991
    [DIFFICULTY_NORMAL][TRAINER_COOLTRAINER_JULIE] =
    {
#line 6992
        .trainerName = _("JULIE"),
#line 6993
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
#line 6994
        .trainerPic = TRAINER_PIC_COOLTRAINER_F,
        .encounterMusic_gender =
#line 6996
            TRAINER_ENCOUNTER_MUSIC_COOL,
#line 6997
        .items = { ITEM_HYPER_POTION },
#line 6998
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 6999
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .partySize = 5,
        .party = (const struct TrainerMon[])
        {
            {
#line 7001
            .species = SPECIES_PERSIAN,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7003
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 7002
            .lvl = 42,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 7004
                MOVE_FURY_SWIPES,
                MOVE_BITE,
                MOVE_SCREECH,
                MOVE_FAINT_ATTACK,
            },
            },
            {
#line 7009
            .species = SPECIES_NINETALES,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7011
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 7010
            .lvl = 42,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 7012
                MOVE_FLAMETHROWER,
                MOVE_WILL_O_WISP,
                MOVE_CONFUSE_RAY,
                MOVE_GRUDGE,
            },
            },
            {
#line 7017
            .species = SPECIES_RAPIDASH,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7019
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 7018
            .lvl = 42,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 7020
                MOVE_FURY_ATTACK,
                MOVE_FIRE_SPIN,
                MOVE_TAKE_DOWN,
                MOVE_AGILITY,
            },
            },
            {
#line 7025
            .species = SPECIES_PIKACHU,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7027
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 7026
            .lvl = 42,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 7028
                MOVE_THUNDERBOLT,
                MOVE_THUNDER_WAVE,
                MOVE_DOUBLE_TEAM,
                MOVE_QUICK_ATTACK,
            },
            },
            {
#line 7033
            .species = SPECIES_RAICHU,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7035
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 7034
            .lvl = 42,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 7036
                MOVE_THUNDER,
                MOVE_THUNDER_WAVE,
                MOVE_SLAM,
                MOVE_DOUBLE_TEAM,
            },
            },
        },
    },
#line 7041
    [DIFFICULTY_NORMAL][TRAINER_ELITE_FOUR_LORELEI] =
    {
#line 7042
        .trainerName = _("LORELEI"),
#line 7043
        .trainerClass = TRAINER_CLASS_ELITE_FOUR,
#line 7044
        .trainerPic = TRAINER_PIC_ELITE_FOUR_LORELEI,
        .encounterMusic_gender =
#line 7046
            TRAINER_ENCOUNTER_MUSIC_ELITE_FOUR,
#line 7047
        .items = { ITEM_FULL_RESTORE, ITEM_FULL_RESTORE },
#line 7048
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 7049
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
#line 7050
        .mugshotColor = MUGSHOT_COLOR_PURPLE,
        .partySize = 5,
        .party = (const struct TrainerMon[])
        {
            {
#line 7052
            .species = SPECIES_DEWGONG,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7054
            .iv = TRAINER_PARTY_IVS(30, 30, 30, 30, 30, 30),
#line 7053
            .lvl = 52,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 7055
                MOVE_ICE_BEAM,
                MOVE_SURF,
                MOVE_HAIL,
                MOVE_SAFEGUARD,
            },
            },
            {
#line 7060
            .species = SPECIES_CLOYSTER,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7062
            .iv = TRAINER_PARTY_IVS(30, 30, 30, 30, 30, 30),
#line 7061
            .lvl = 51,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 7063
                MOVE_SPIKES,
                MOVE_PROTECT,
                MOVE_HAIL,
                MOVE_DIVE,
            },
            },
            {
#line 7068
            .species = SPECIES_SLOWBRO,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7070
            .iv = TRAINER_PARTY_IVS(30, 30, 30, 30, 30, 30),
#line 7069
            .lvl = 52,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 7071
                MOVE_ICE_BEAM,
                MOVE_SURF,
                MOVE_AMNESIA,
                MOVE_YAWN,
            },
            },
            {
#line 7076
            .species = SPECIES_JYNX,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7078
            .iv = TRAINER_PARTY_IVS(30, 30, 30, 30, 30, 30),
#line 7077
            .lvl = 54,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 7079
                MOVE_ICE_PUNCH,
                MOVE_DOUBLE_SLAP,
                MOVE_LOVELY_KISS,
                MOVE_ATTRACT,
            },
            },
            {
#line 7084
            .species = SPECIES_LAPRAS,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7084
            .heldItem = ITEM_SITRUS_BERRY,
#line 7086
            .iv = TRAINER_PARTY_IVS(30, 30, 30, 30, 30, 30),
#line 7085
            .lvl = 54,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 7087
                MOVE_CONFUSE_RAY,
                MOVE_ICE_BEAM,
                MOVE_SURF,
                MOVE_BODY_SLAM,
            },
            },
        },
    },
#line 7092
    [DIFFICULTY_NORMAL][TRAINER_ELITE_FOUR_BRUNO] =
    {
#line 7093
        .trainerName = _("BRUNO"),
#line 7094
        .trainerClass = TRAINER_CLASS_ELITE_FOUR,
#line 7095
        .trainerPic = TRAINER_PIC_ELITE_FOUR_BRUNO,
        .encounterMusic_gender =
#line 7097
            TRAINER_ENCOUNTER_MUSIC_ELITE_FOUR,
#line 7098
        .items = { ITEM_FULL_RESTORE, ITEM_FULL_RESTORE },
#line 7099
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 7100
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
#line 7101
        .mugshotColor = MUGSHOT_COLOR_GREEN,
        .partySize = 5,
        .party = (const struct TrainerMon[])
        {
            {
#line 7103
            .species = SPECIES_ONIX,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7105
            .iv = TRAINER_PARTY_IVS(30, 30, 30, 30, 30, 30),
#line 7104
            .lvl = 51,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 7106
                MOVE_EARTHQUAKE,
                MOVE_ROCK_TOMB,
                MOVE_IRON_TAIL,
                MOVE_ROAR,
            },
            },
            {
#line 7111
            .species = SPECIES_HITMONCHAN,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7113
            .iv = TRAINER_PARTY_IVS(30, 30, 30, 30, 30, 30),
#line 7112
            .lvl = 53,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 7114
                MOVE_SKY_UPPERCUT,
                MOVE_MACH_PUNCH,
                MOVE_ROCK_TOMB,
                MOVE_COUNTER,
            },
            },
            {
#line 7119
            .species = SPECIES_HITMONLEE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7121
            .iv = TRAINER_PARTY_IVS(30, 30, 30, 30, 30, 30),
#line 7120
            .lvl = 53,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 7122
                MOVE_MEGA_KICK,
                MOVE_FORESIGHT,
                MOVE_BRICK_BREAK,
                MOVE_FACADE,
            },
            },
            {
#line 7127
            .species = SPECIES_ONIX,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7129
            .iv = TRAINER_PARTY_IVS(30, 30, 30, 30, 30, 30),
#line 7128
            .lvl = 54,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 7130
                MOVE_DOUBLE_EDGE,
                MOVE_EARTHQUAKE,
                MOVE_IRON_TAIL,
                MOVE_SAND_TOMB,
            },
            },
            {
#line 7135
            .species = SPECIES_MACHAMP,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7135
            .heldItem = ITEM_SITRUS_BERRY,
#line 7137
            .iv = TRAINER_PARTY_IVS(30, 30, 30, 30, 30, 30),
#line 7136
            .lvl = 56,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 7138
                MOVE_CROSS_CHOP,
                MOVE_BULK_UP,
                MOVE_SCARY_FACE,
                MOVE_ROCK_TOMB,
            },
            },
        },
    },
#line 7143
    [DIFFICULTY_NORMAL][TRAINER_ELITE_FOUR_AGATHA] =
    {
#line 7144
        .trainerName = _("AGATHA"),
#line 7145
        .trainerClass = TRAINER_CLASS_ELITE_FOUR,
#line 7146
        .trainerPic = TRAINER_PIC_ELITE_FOUR_AGATHA,
        .encounterMusic_gender =
#line 7148
            TRAINER_ENCOUNTER_MUSIC_ELITE_FOUR,
#line 7149
        .items = { ITEM_FULL_RESTORE, ITEM_FULL_RESTORE },
#line 7150
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 7151
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
#line 7152
        .mugshotColor = MUGSHOT_COLOR_PINK,
        .partySize = 5,
        .party = (const struct TrainerMon[])
        {
            {
#line 7154
            .species = SPECIES_GENGAR,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7156
            .iv = TRAINER_PARTY_IVS(30, 30, 30, 30, 30, 30),
#line 7155
            .lvl = 54,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 7157
                MOVE_SHADOW_PUNCH,
                MOVE_CONFUSE_RAY,
                MOVE_TOXIC,
                MOVE_DOUBLE_TEAM,
            },
            },
            {
#line 7162
            .species = SPECIES_GOLBAT,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7164
            .iv = TRAINER_PARTY_IVS(30, 30, 30, 30, 30, 30),
#line 7163
            .lvl = 54,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 7165
                MOVE_CONFUSE_RAY,
                MOVE_POISON_FANG,
                MOVE_AIR_CUTTER,
                MOVE_BITE,
            },
            },
            {
#line 7170
            .species = SPECIES_HAUNTER,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7172
            .iv = TRAINER_PARTY_IVS(30, 30, 30, 30, 30, 30),
#line 7171
            .lvl = 53,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 7173
                MOVE_HYPNOSIS,
                MOVE_DREAM_EATER,
                MOVE_CURSE,
                MOVE_MEAN_LOOK,
            },
            },
            {
#line 7178
            .species = SPECIES_ARBOK,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7180
            .iv = TRAINER_PARTY_IVS(30, 30, 30, 30, 30, 30),
#line 7179
            .lvl = 56,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 7181
                MOVE_SLUDGE_BOMB,
                MOVE_SCREECH,
                MOVE_IRON_TAIL,
                MOVE_BITE,
            },
            },
            {
#line 7186
            .species = SPECIES_GENGAR,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7186
            .heldItem = ITEM_SITRUS_BERRY,
#line 7188
            .iv = TRAINER_PARTY_IVS(30, 30, 30, 30, 30, 30),
#line 7187
            .lvl = 58,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 7189
                MOVE_SHADOW_BALL,
                MOVE_SLUDGE_BOMB,
                MOVE_HYPNOSIS,
                MOVE_NIGHTMARE,
            },
            },
        },
    },
#line 7194
    [DIFFICULTY_NORMAL][TRAINER_ELITE_FOUR_LANCE] =
    {
#line 7195
        .trainerName = _("LANCE"),
#line 7196
        .trainerClass = TRAINER_CLASS_ELITE_FOUR,
#line 7197
        .trainerPic = TRAINER_PIC_ELITE_FOUR_LANCE,
        .encounterMusic_gender =
#line 7199
            TRAINER_ENCOUNTER_MUSIC_ELITE_FOUR,
#line 7200
        .items = { ITEM_FULL_RESTORE, ITEM_FULL_RESTORE },
#line 7201
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 7202
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
#line 7203
        .mugshotColor = MUGSHOT_COLOR_BLUE,
        .partySize = 5,
        .party = (const struct TrainerMon[])
        {
            {
#line 7205
            .species = SPECIES_GYARADOS,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7207
            .iv = TRAINER_PARTY_IVS(30, 30, 30, 30, 30, 30),
#line 7206
            .lvl = 56,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 7208
                MOVE_HYPER_BEAM,
                MOVE_DRAGON_RAGE,
                MOVE_TWISTER,
                MOVE_BITE,
            },
            },
            {
#line 7213
            .species = SPECIES_DRAGONAIR,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7215
            .iv = TRAINER_PARTY_IVS(30, 30, 30, 30, 30, 30),
#line 7214
            .lvl = 54,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 7216
                MOVE_HYPER_BEAM,
                MOVE_SAFEGUARD,
                MOVE_DRAGON_RAGE,
                MOVE_OUTRAGE,
            },
            },
            {
#line 7221
            .species = SPECIES_DRAGONAIR,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7223
            .iv = TRAINER_PARTY_IVS(30, 30, 30, 30, 30, 30),
#line 7222
            .lvl = 54,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 7224
                MOVE_HYPER_BEAM,
                MOVE_SAFEGUARD,
                MOVE_THUNDER_WAVE,
                MOVE_OUTRAGE,
            },
            },
            {
#line 7229
            .species = SPECIES_AERODACTYL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7231
            .iv = TRAINER_PARTY_IVS(30, 30, 30, 30, 30, 30),
#line 7230
            .lvl = 58,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 7232
                MOVE_HYPER_BEAM,
                MOVE_ANCIENT_POWER,
                MOVE_WING_ATTACK,
                MOVE_SCARY_FACE,
            },
            },
            {
#line 7237
            .species = SPECIES_DRAGONITE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7237
            .heldItem = ITEM_SITRUS_BERRY,
#line 7239
            .iv = TRAINER_PARTY_IVS(30, 30, 30, 30, 30, 30),
#line 7238
            .lvl = 60,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 7240
                MOVE_HYPER_BEAM,
                MOVE_SAFEGUARD,
                MOVE_OUTRAGE,
                MOVE_WING_ATTACK,
            },
            },
        },
    },
#line 7245
    [DIFFICULTY_NORMAL][TRAINER_LEADER_BROCK] =
    {
#line 7246
        .trainerName = _("BROCK"),
#line 7247
        .trainerClass = TRAINER_CLASS_LEADER,
#line 7248
        .trainerPic = TRAINER_PIC_LEADER_BROCK,
        .encounterMusic_gender =
#line 7250
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 7251
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 7252
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 7254
            .species = SPECIES_GEODUDE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7256
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 7255
            .lvl = 12,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 7257
                MOVE_TACKLE,
                MOVE_DEFENSE_CURL,
            },
            },
            {
#line 7260
            .species = SPECIES_ONIX,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7262
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 7261
            .lvl = 14,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 7263
                MOVE_TACKLE,
                MOVE_BIND,
                MOVE_ROCK_TOMB,
            },
            },
        },
    },
#line 7267
    [DIFFICULTY_NORMAL][TRAINER_LEADER_MISTY] =
    {
#line 7268
        .trainerName = _("MISTY"),
#line 7269
        .trainerClass = TRAINER_CLASS_LEADER,
#line 7270
        .trainerPic = TRAINER_PIC_LEADER_MISTY,
        .encounterMusic_gender =
#line 7272
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
#line 7273
        .items = { ITEM_SUPER_POTION },
#line 7274
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 7275
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 7277
            .species = SPECIES_STARYU,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7279
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 7278
            .lvl = 18,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 7280
                MOVE_TACKLE,
                MOVE_HARDEN,
                MOVE_RECOVER,
                MOVE_WATER_PULSE,
            },
            },
            {
#line 7285
            .species = SPECIES_STARMIE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7287
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 7286
            .lvl = 21,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 7288
                MOVE_SWIFT,
                MOVE_RECOVER,
                MOVE_RAPID_SPIN,
                MOVE_WATER_PULSE,
            },
            },
        },
    },
#line 7293
    [DIFFICULTY_NORMAL][TRAINER_LEADER_LT_SURGE] =
    {
#line 7294
        .trainerName = _("LT. SURGE"),
#line 7295
        .trainerClass = TRAINER_CLASS_LEADER,
#line 7296
        .trainerPic = TRAINER_PIC_LEADER_LT_SURGE,
        .encounterMusic_gender =
#line 7298
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 7299
        .items = { ITEM_SUPER_POTION, ITEM_FULL_HEAL },
#line 7300
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 7301
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 7303
            .species = SPECIES_VOLTORB,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7305
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 7304
            .lvl = 21,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 7306
                MOVE_SONIC_BOOM,
                MOVE_TACKLE,
                MOVE_SCREECH,
                MOVE_SHOCK_WAVE,
            },
            },
            {
#line 7311
            .species = SPECIES_PIKACHU,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7313
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 7312
            .lvl = 18,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 7314
                MOVE_QUICK_ATTACK,
                MOVE_THUNDER_WAVE,
                MOVE_DOUBLE_TEAM,
                MOVE_SHOCK_WAVE,
            },
            },
            {
#line 7319
            .species = SPECIES_RAICHU,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7321
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 7320
            .lvl = 24,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 7322
                MOVE_QUICK_ATTACK,
                MOVE_THUNDER_WAVE,
                MOVE_DOUBLE_TEAM,
                MOVE_SHOCK_WAVE,
            },
            },
        },
    },
#line 7327
    [DIFFICULTY_NORMAL][TRAINER_LEADER_ERIKA] =
    {
#line 7328
        .trainerName = _("ERIKA"),
#line 7329
        .trainerClass = TRAINER_CLASS_LEADER,
#line 7330
        .trainerPic = TRAINER_PIC_LEADER_ERIKA,
        .encounterMusic_gender =
#line 7332
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
#line 7333
        .items = { ITEM_HYPER_POTION, ITEM_FULL_HEAL },
#line 7334
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 7335
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 7337
            .species = SPECIES_VICTREEBEL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7339
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 7338
            .lvl = 29,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 7340
                MOVE_STUN_SPORE,
                MOVE_ACID,
                MOVE_POISON_POWDER,
                MOVE_GIGA_DRAIN,
            },
            },
            {
#line 7345
            .species = SPECIES_TANGELA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7347
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 7346
            .lvl = 24,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 7348
                MOVE_POISON_POWDER,
                MOVE_CONSTRICT,
                MOVE_INGRAIN,
                MOVE_GIGA_DRAIN,
            },
            },
            {
#line 7353
            .species = SPECIES_VILEPLUME,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7355
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 7354
            .lvl = 29,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 7356
                MOVE_SLEEP_POWDER,
                MOVE_ACID,
                MOVE_STUN_SPORE,
                MOVE_GIGA_DRAIN,
            },
            },
        },
    },
#line 7361
    [DIFFICULTY_NORMAL][TRAINER_LEADER_KOGA] =
    {
#line 7362
        .trainerName = _("KOGA"),
#line 7363
        .trainerClass = TRAINER_CLASS_LEADER,
#line 7364
        .trainerPic = TRAINER_PIC_LEADER_KOGA,
        .encounterMusic_gender =
#line 7366
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 7367
        .items = { ITEM_HYPER_POTION, ITEM_HYPER_POTION, ITEM_FULL_HEAL },
#line 7368
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 7369
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .partySize = 4,
        .party = (const struct TrainerMon[])
        {
            {
#line 7371
            .species = SPECIES_KOFFING,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7373
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 7372
            .lvl = 37,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 7374
                MOVE_SELF_DESTRUCT,
                MOVE_SLUDGE,
                MOVE_SMOKESCREEN,
                MOVE_TOXIC,
            },
            },
            {
#line 7379
            .species = SPECIES_MUK,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7381
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 7380
            .lvl = 39,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 7382
                MOVE_MINIMIZE,
                MOVE_SLUDGE,
                MOVE_ACID_ARMOR,
                MOVE_TOXIC,
            },
            },
            {
#line 7387
            .species = SPECIES_KOFFING,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7389
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 7388
            .lvl = 37,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 7390
                MOVE_SELF_DESTRUCT,
                MOVE_SLUDGE,
                MOVE_SMOKESCREEN,
                MOVE_TOXIC,
            },
            },
            {
#line 7395
            .species = SPECIES_WEEZING,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7397
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 7396
            .lvl = 43,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 7398
                MOVE_TACKLE,
                MOVE_SLUDGE,
                MOVE_SMOKESCREEN,
                MOVE_TOXIC,
            },
            },
        },
    },
#line 7403
    [DIFFICULTY_NORMAL][TRAINER_LEADER_BLAINE] =
    {
#line 7404
        .trainerName = _("BLAINE"),
#line 7405
        .trainerClass = TRAINER_CLASS_LEADER,
#line 7406
        .trainerPic = TRAINER_PIC_LEADER_BLAINE,
        .encounterMusic_gender =
#line 7408
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 7409
        .items = { ITEM_HYPER_POTION, ITEM_HYPER_POTION, ITEM_FULL_HEAL },
#line 7410
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 7411
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .partySize = 4,
        .party = (const struct TrainerMon[])
        {
            {
#line 7413
            .species = SPECIES_GROWLITHE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7415
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 7414
            .lvl = 42,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 7416
                MOVE_BITE,
                MOVE_ROAR,
                MOVE_TAKE_DOWN,
                MOVE_FIRE_BLAST,
            },
            },
            {
#line 7421
            .species = SPECIES_PONYTA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7423
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 7422
            .lvl = 40,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 7424
                MOVE_STOMP,
                MOVE_BOUNCE,
                MOVE_FIRE_SPIN,
                MOVE_FIRE_BLAST,
            },
            },
            {
#line 7429
            .species = SPECIES_RAPIDASH,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7431
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 7430
            .lvl = 42,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 7432
                MOVE_STOMP,
                MOVE_BOUNCE,
                MOVE_FIRE_SPIN,
                MOVE_FIRE_BLAST,
            },
            },
            {
#line 7437
            .species = SPECIES_ARCANINE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7439
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 7438
            .lvl = 47,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 7440
                MOVE_BITE,
                MOVE_ROAR,
                MOVE_TAKE_DOWN,
                MOVE_FIRE_BLAST,
            },
            },
        },
    },
#line 7445
    [DIFFICULTY_NORMAL][TRAINER_LEADER_SABRINA] =
    {
#line 7446
        .trainerName = _("SABRINA"),
#line 7447
        .trainerClass = TRAINER_CLASS_LEADER,
#line 7448
        .trainerPic = TRAINER_PIC_LEADER_SABRINA,
        .encounterMusic_gender =
#line 7450
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
#line 7451
        .items = { ITEM_HYPER_POTION, ITEM_HYPER_POTION, ITEM_FULL_HEAL },
#line 7452
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 7453
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .partySize = 4,
        .party = (const struct TrainerMon[])
        {
            {
#line 7455
            .species = SPECIES_KADABRA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7457
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 7456
            .lvl = 38,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 7458
                MOVE_PSYBEAM,
                MOVE_REFLECT,
                MOVE_FUTURE_SIGHT,
                MOVE_CALM_MIND,
            },
            },
            {
#line 7463
            .species = SPECIES_MR_MIME,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7465
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 7464
            .lvl = 37,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 7466
                MOVE_BARRIER,
                MOVE_PSYBEAM,
                MOVE_BATON_PASS,
                MOVE_CALM_MIND,
            },
            },
            {
#line 7471
            .species = SPECIES_VENOMOTH,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7473
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 7472
            .lvl = 38,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 7474
                MOVE_PSYBEAM,
                MOVE_GUST,
                MOVE_LEECH_LIFE,
                MOVE_SUPERSONIC,
            },
            },
            {
#line 7479
            .species = SPECIES_ALAKAZAM,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7481
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 7480
            .lvl = 43,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 7482
                MOVE_PSYCHIC,
                MOVE_RECOVER,
                MOVE_FUTURE_SIGHT,
                MOVE_CALM_MIND,
            },
            },
        },
    },
#line 7487
    [DIFFICULTY_NORMAL][TRAINER_GENTLEMAN_THOMAS] =
    {
#line 7488
        .trainerName = _("THOMAS"),
#line 7489
        .trainerClass = TRAINER_CLASS_GENTLEMAN,
#line 7490
        .trainerPic = TRAINER_PIC_GENTLEMAN,
        .encounterMusic_gender =
#line 7492
            TRAINER_ENCOUNTER_MUSIC_RICH,
#line 7493
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 7494
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 7496
            .species = SPECIES_GROWLITHE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7498
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 7497
            .lvl = 18,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 7500
            .species = SPECIES_GROWLITHE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7502
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 7501
            .lvl = 18,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 7504
    [DIFFICULTY_NORMAL][TRAINER_GENTLEMAN_ARTHUR] =
    {
#line 7505
        .trainerName = _("ARTHUR"),
#line 7506
        .trainerClass = TRAINER_CLASS_GENTLEMAN,
#line 7507
        .trainerPic = TRAINER_PIC_GENTLEMAN,
        .encounterMusic_gender =
#line 7509
            TRAINER_ENCOUNTER_MUSIC_RICH,
#line 7510
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 7511
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 7513
            .species = SPECIES_NIDORAN_M,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7515
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 7514
            .lvl = 19,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 7517
            .species = SPECIES_NIDORAN_F,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7519
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 7518
            .lvl = 19,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 7521
    [DIFFICULTY_NORMAL][TRAINER_GENTLEMAN_TUCKER] =
    {
#line 7522
        .trainerName = _("TUCKER"),
#line 7523
        .trainerClass = TRAINER_CLASS_GENTLEMAN,
#line 7524
        .trainerPic = TRAINER_PIC_GENTLEMAN,
        .encounterMusic_gender =
#line 7526
            TRAINER_ENCOUNTER_MUSIC_RICH,
#line 7527
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 7528
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 7530
            .species = SPECIES_PIKACHU,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7532
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 7531
            .lvl = 23,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 7534
    [DIFFICULTY_NORMAL][TRAINER_GENTLEMAN_NORTON] =
    {
#line 7535
        .trainerName = _("NORTON"),
#line 7536
        .trainerClass = TRAINER_CLASS_GENTLEMAN,
#line 7537
        .trainerPic = TRAINER_PIC_GENTLEMAN,
        .encounterMusic_gender =
#line 7539
            TRAINER_ENCOUNTER_MUSIC_RICH,
#line 7540
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 7541
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 7543
            .species = SPECIES_PERSIAN,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7545
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 7544
            .lvl = 48,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 7547
    [DIFFICULTY_NORMAL][TRAINER_GENTLEMAN_WALTER] =
    {
#line 7548
        .trainerName = _("WALTER"),
#line 7549
        .trainerClass = TRAINER_CLASS_GENTLEMAN,
#line 7550
        .trainerPic = TRAINER_PIC_GENTLEMAN,
        .encounterMusic_gender =
#line 7552
            TRAINER_ENCOUNTER_MUSIC_RICH,
#line 7553
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 7554
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 7556
            .species = SPECIES_GROWLITHE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7558
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 7557
            .lvl = 17,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 7560
            .species = SPECIES_PONYTA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7562
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 7561
            .lvl = 17,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 7564
    [DIFFICULTY_NORMAL][TRAINER_RIVAL_SS_ANNE_SQUIRTLE] =
    {
#line 7565
        .trainerName = _("TERRY"),
#line 7566
        .trainerClass = TRAINER_CLASS_RIVAL_LATE,
#line 7567
        .trainerPic = TRAINER_PIC_RIVAL_LATE,
        .encounterMusic_gender =
#line 7569
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 7570
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 7571
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .partySize = 4,
        .party = (const struct TrainerMon[])
        {
            {
#line 7573
            .species = SPECIES_PIDGEOTTO,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7575
            .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
#line 7574
            .lvl = 19,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 7577
            .species = SPECIES_RATICATE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7579
            .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
#line 7578
            .lvl = 16,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 7581
            .species = SPECIES_KADABRA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7583
            .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
#line 7582
            .lvl = 18,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 7585
            .species = SPECIES_WARTORTLE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7587
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 7586
            .lvl = 20,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 7589
    [DIFFICULTY_NORMAL][TRAINER_RIVAL_SS_ANNE_BULBASAUR] =
    {
#line 7590
        .trainerName = _("TERRY"),
#line 7591
        .trainerClass = TRAINER_CLASS_RIVAL_LATE,
#line 7592
        .trainerPic = TRAINER_PIC_RIVAL_LATE,
        .encounterMusic_gender =
#line 7594
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 7595
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 7596
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .partySize = 4,
        .party = (const struct TrainerMon[])
        {
            {
#line 7598
            .species = SPECIES_PIDGEOTTO,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7600
            .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
#line 7599
            .lvl = 19,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 7602
            .species = SPECIES_RATICATE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7604
            .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
#line 7603
            .lvl = 16,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 7606
            .species = SPECIES_KADABRA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7608
            .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
#line 7607
            .lvl = 18,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 7610
            .species = SPECIES_IVYSAUR,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7612
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 7611
            .lvl = 20,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 7614
    [DIFFICULTY_NORMAL][TRAINER_RIVAL_SS_ANNE_CHARMANDER] =
    {
#line 7615
        .trainerName = _("TERRY"),
#line 7616
        .trainerClass = TRAINER_CLASS_RIVAL_LATE,
#line 7617
        .trainerPic = TRAINER_PIC_RIVAL_LATE,
        .encounterMusic_gender =
#line 7619
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 7620
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 7621
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .partySize = 4,
        .party = (const struct TrainerMon[])
        {
            {
#line 7623
            .species = SPECIES_PIDGEOTTO,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7625
            .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
#line 7624
            .lvl = 19,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 7627
            .species = SPECIES_RATICATE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7629
            .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
#line 7628
            .lvl = 16,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 7631
            .species = SPECIES_KADABRA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7633
            .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
#line 7632
            .lvl = 18,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 7635
            .species = SPECIES_CHARMELEON,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7637
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 7636
            .lvl = 20,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 7639
    [DIFFICULTY_NORMAL][TRAINER_RIVAL_POKEMON_TOWER_SQUIRTLE] =
    {
#line 7640
        .trainerName = _("TERRY"),
#line 7641
        .trainerClass = TRAINER_CLASS_RIVAL_LATE,
#line 7642
        .trainerPic = TRAINER_PIC_RIVAL_LATE,
        .encounterMusic_gender =
#line 7644
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 7645
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 7646
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .partySize = 5,
        .party = (const struct TrainerMon[])
        {
            {
#line 7648
            .species = SPECIES_PIDGEOTTO,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7650
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 7649
            .lvl = 25,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 7652
            .species = SPECIES_GROWLITHE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7654
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 7653
            .lvl = 23,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 7656
            .species = SPECIES_EXEGGCUTE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7658
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 7657
            .lvl = 22,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 7660
            .species = SPECIES_KADABRA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7662
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 7661
            .lvl = 20,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 7664
            .species = SPECIES_WARTORTLE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7666
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 7665
            .lvl = 25,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 7668
    [DIFFICULTY_NORMAL][TRAINER_RIVAL_POKEMON_TOWER_BULBASAUR] =
    {
#line 7669
        .trainerName = _("TERRY"),
#line 7670
        .trainerClass = TRAINER_CLASS_RIVAL_LATE,
#line 7671
        .trainerPic = TRAINER_PIC_RIVAL_LATE,
        .encounterMusic_gender =
#line 7673
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 7674
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 7675
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .partySize = 5,
        .party = (const struct TrainerMon[])
        {
            {
#line 7677
            .species = SPECIES_PIDGEOTTO,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7679
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 7678
            .lvl = 25,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 7681
            .species = SPECIES_GYARADOS,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7683
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 7682
            .lvl = 23,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 7685
            .species = SPECIES_GROWLITHE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7687
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 7686
            .lvl = 22,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 7689
            .species = SPECIES_KADABRA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7691
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 7690
            .lvl = 20,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 7693
            .species = SPECIES_IVYSAUR,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7695
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 7694
            .lvl = 25,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 7697
    [DIFFICULTY_NORMAL][TRAINER_RIVAL_POKEMON_TOWER_CHARMANDER] =
    {
#line 7698
        .trainerName = _("TERRY"),
#line 7699
        .trainerClass = TRAINER_CLASS_RIVAL_LATE,
#line 7700
        .trainerPic = TRAINER_PIC_RIVAL_LATE,
        .encounterMusic_gender =
#line 7702
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 7703
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 7704
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .partySize = 5,
        .party = (const struct TrainerMon[])
        {
            {
#line 7706
            .species = SPECIES_PIDGEOTTO,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7708
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 7707
            .lvl = 25,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 7710
            .species = SPECIES_EXEGGCUTE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7712
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 7711
            .lvl = 23,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 7714
            .species = SPECIES_GYARADOS,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7716
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 7715
            .lvl = 22,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 7718
            .species = SPECIES_KADABRA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7720
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 7719
            .lvl = 20,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 7722
            .species = SPECIES_CHARMELEON,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7724
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 7723
            .lvl = 25,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 7726
    [DIFFICULTY_NORMAL][TRAINER_RIVAL_SILPH_SQUIRTLE] =
    {
#line 7727
        .trainerName = _("TERRY"),
#line 7728
        .trainerClass = TRAINER_CLASS_RIVAL_LATE,
#line 7729
        .trainerPic = TRAINER_PIC_RIVAL_LATE,
        .encounterMusic_gender =
#line 7731
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 7732
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 7733
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .partySize = 5,
        .party = (const struct TrainerMon[])
        {
            {
#line 7735
            .species = SPECIES_PIDGEOT,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7737
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 7736
            .lvl = 37,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 7739
            .species = SPECIES_GROWLITHE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7741
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 7740
            .lvl = 38,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 7743
            .species = SPECIES_EXEGGCUTE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7745
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 7744
            .lvl = 35,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 7747
            .species = SPECIES_ALAKAZAM,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7749
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 7748
            .lvl = 35,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 7751
            .species = SPECIES_BLASTOISE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7753
            .iv = TRAINER_PARTY_IVS(18, 18, 18, 18, 18, 18),
#line 7752
            .lvl = 40,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 7755
    [DIFFICULTY_NORMAL][TRAINER_RIVAL_SILPH_BULBASAUR] =
    {
#line 7756
        .trainerName = _("TERRY"),
#line 7757
        .trainerClass = TRAINER_CLASS_RIVAL_LATE,
#line 7758
        .trainerPic = TRAINER_PIC_RIVAL_LATE,
        .encounterMusic_gender =
#line 7760
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 7761
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 7762
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .partySize = 5,
        .party = (const struct TrainerMon[])
        {
            {
#line 7764
            .species = SPECIES_PIDGEOT,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7766
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 7765
            .lvl = 37,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 7768
            .species = SPECIES_GYARADOS,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7770
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 7769
            .lvl = 38,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 7772
            .species = SPECIES_GROWLITHE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7774
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 7773
            .lvl = 35,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 7776
            .species = SPECIES_ALAKAZAM,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7778
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 7777
            .lvl = 35,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 7780
            .species = SPECIES_VENUSAUR,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7782
            .iv = TRAINER_PARTY_IVS(18, 18, 18, 18, 18, 18),
#line 7781
            .lvl = 40,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 7784
    [DIFFICULTY_NORMAL][TRAINER_RIVAL_SILPH_CHARMANDER] =
    {
#line 7785
        .trainerName = _("TERRY"),
#line 7786
        .trainerClass = TRAINER_CLASS_RIVAL_LATE,
#line 7787
        .trainerPic = TRAINER_PIC_RIVAL_LATE,
        .encounterMusic_gender =
#line 7789
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 7790
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 7791
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .partySize = 5,
        .party = (const struct TrainerMon[])
        {
            {
#line 7793
            .species = SPECIES_PIDGEOT,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7795
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 7794
            .lvl = 37,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 7797
            .species = SPECIES_EXEGGCUTE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7799
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 7798
            .lvl = 38,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 7801
            .species = SPECIES_GYARADOS,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7803
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 7802
            .lvl = 35,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 7805
            .species = SPECIES_ALAKAZAM,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7807
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 7806
            .lvl = 35,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 7809
            .species = SPECIES_CHARIZARD,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7811
            .iv = TRAINER_PARTY_IVS(18, 18, 18, 18, 18, 18),
#line 7810
            .lvl = 40,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 7813
    [DIFFICULTY_NORMAL][TRAINER_RIVAL_ROUTE22_LATE_SQUIRTLE] =
    {
#line 7814
        .trainerName = _("TERRY"),
#line 7815
        .trainerClass = TRAINER_CLASS_RIVAL_LATE,
#line 7816
        .trainerPic = TRAINER_PIC_RIVAL_LATE,
        .encounterMusic_gender =
#line 7818
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 7819
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 7820
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .partySize = 6,
        .party = (const struct TrainerMon[])
        {
            {
#line 7822
            .species = SPECIES_PIDGEOT,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7824
            .iv = TRAINER_PARTY_IVS(18, 18, 18, 18, 18, 18),
#line 7823
            .lvl = 47,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 7825
                MOVE_FEATHER_DANCE,
                MOVE_WING_ATTACK,
                MOVE_GUST,
                MOVE_QUICK_ATTACK,
            },
            },
            {
#line 7830
            .species = SPECIES_RHYHORN,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7832
            .iv = TRAINER_PARTY_IVS(18, 18, 18, 18, 18, 18),
#line 7831
            .lvl = 45,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 7833
                MOVE_TAKE_DOWN,
                MOVE_HORN_DRILL,
                MOVE_ROCK_BLAST,
                MOVE_FURY_ATTACK,
            },
            },
            {
#line 7838
            .species = SPECIES_GROWLITHE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7840
            .iv = TRAINER_PARTY_IVS(18, 18, 18, 18, 18, 18),
#line 7839
            .lvl = 45,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 7841
                MOVE_FLAME_WHEEL,
                MOVE_TAKE_DOWN,
                MOVE_LEER,
                MOVE_AGILITY,
            },
            },
            {
#line 7846
            .species = SPECIES_EXEGGCUTE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7848
            .iv = TRAINER_PARTY_IVS(18, 18, 18, 18, 18, 18),
#line 7847
            .lvl = 45,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 7849
                MOVE_SOLAR_BEAM,
                MOVE_SLEEP_POWDER,
                MOVE_POISON_POWDER,
                MOVE_STUN_SPORE,
            },
            },
            {
#line 7854
            .species = SPECIES_ALAKAZAM,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7856
            .iv = TRAINER_PARTY_IVS(18, 18, 18, 18, 18, 18),
#line 7855
            .lvl = 47,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 7857
                MOVE_PSYCHIC,
                MOVE_CALM_MIND,
                MOVE_FUTURE_SIGHT,
                MOVE_DISABLE,
            },
            },
            {
#line 7862
            .species = SPECIES_BLASTOISE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7864
            .iv = TRAINER_PARTY_IVS(30, 30, 30, 30, 30, 30),
#line 7863
            .lvl = 53,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 7865
                MOVE_WATER_GUN,
                MOVE_RAIN_DANCE,
                MOVE_BITE,
                MOVE_RAPID_SPIN,
            },
            },
        },
    },
#line 7870
    [DIFFICULTY_NORMAL][TRAINER_RIVAL_ROUTE22_LATE_BULBASAUR] =
    {
#line 7871
        .trainerName = _("TERRY"),
#line 7872
        .trainerClass = TRAINER_CLASS_RIVAL_LATE,
#line 7873
        .trainerPic = TRAINER_PIC_RIVAL_LATE,
        .encounterMusic_gender =
#line 7875
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 7876
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 7877
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .partySize = 6,
        .party = (const struct TrainerMon[])
        {
            {
#line 7879
            .species = SPECIES_PIDGEOT,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7881
            .iv = TRAINER_PARTY_IVS(18, 18, 18, 18, 18, 18),
#line 7880
            .lvl = 47,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 7882
                MOVE_FEATHER_DANCE,
                MOVE_WING_ATTACK,
                MOVE_GUST,
                MOVE_QUICK_ATTACK,
            },
            },
            {
#line 7887
            .species = SPECIES_RHYHORN,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7889
            .iv = TRAINER_PARTY_IVS(18, 18, 18, 18, 18, 18),
#line 7888
            .lvl = 45,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 7890
                MOVE_TAKE_DOWN,
                MOVE_HORN_DRILL,
                MOVE_ROCK_BLAST,
                MOVE_FURY_ATTACK,
            },
            },
            {
#line 7895
            .species = SPECIES_GYARADOS,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7897
            .iv = TRAINER_PARTY_IVS(18, 18, 18, 18, 18, 18),
#line 7896
            .lvl = 45,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 7898
                MOVE_HYDRO_PUMP,
                MOVE_TWISTER,
                MOVE_LEER,
                MOVE_RAIN_DANCE,
            },
            },
            {
#line 7903
            .species = SPECIES_GROWLITHE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7905
            .iv = TRAINER_PARTY_IVS(18, 18, 18, 18, 18, 18),
#line 7904
            .lvl = 45,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 7906
                MOVE_FLAME_WHEEL,
                MOVE_TAKE_DOWN,
                MOVE_LEER,
                MOVE_AGILITY,
            },
            },
            {
#line 7911
            .species = SPECIES_ALAKAZAM,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7913
            .iv = TRAINER_PARTY_IVS(18, 18, 18, 18, 18, 18),
#line 7912
            .lvl = 47,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 7914
                MOVE_PSYCHIC,
                MOVE_CALM_MIND,
                MOVE_FUTURE_SIGHT,
                MOVE_DISABLE,
            },
            },
            {
#line 7919
            .species = SPECIES_VENUSAUR,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7921
            .iv = TRAINER_PARTY_IVS(30, 30, 30, 30, 30, 30),
#line 7920
            .lvl = 53,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 7922
                MOVE_RAZOR_LEAF,
                MOVE_SWEET_SCENT,
                MOVE_GROWTH,
                MOVE_SYNTHESIS,
            },
            },
        },
    },
#line 7927
    [DIFFICULTY_NORMAL][TRAINER_RIVAL_ROUTE22_LATE_CHARMANDER] =
    {
#line 7928
        .trainerName = _("TERRY"),
#line 7929
        .trainerClass = TRAINER_CLASS_RIVAL_LATE,
#line 7930
        .trainerPic = TRAINER_PIC_RIVAL_LATE,
        .encounterMusic_gender =
#line 7932
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 7933
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 7934
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .partySize = 6,
        .party = (const struct TrainerMon[])
        {
            {
#line 7936
            .species = SPECIES_PIDGEOT,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7938
            .iv = TRAINER_PARTY_IVS(18, 18, 18, 18, 18, 18),
#line 7937
            .lvl = 47,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 7939
                MOVE_FEATHER_DANCE,
                MOVE_WING_ATTACK,
                MOVE_GUST,
                MOVE_QUICK_ATTACK,
            },
            },
            {
#line 7944
            .species = SPECIES_RHYHORN,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7946
            .iv = TRAINER_PARTY_IVS(18, 18, 18, 18, 18, 18),
#line 7945
            .lvl = 45,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 7947
                MOVE_TAKE_DOWN,
                MOVE_HORN_DRILL,
                MOVE_ROCK_BLAST,
                MOVE_FURY_ATTACK,
            },
            },
            {
#line 7952
            .species = SPECIES_EXEGGCUTE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7954
            .iv = TRAINER_PARTY_IVS(18, 18, 18, 18, 18, 18),
#line 7953
            .lvl = 45,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 7955
                MOVE_SOLAR_BEAM,
                MOVE_SLEEP_POWDER,
                MOVE_POISON_POWDER,
                MOVE_STUN_SPORE,
            },
            },
            {
#line 7960
            .species = SPECIES_GYARADOS,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7962
            .iv = TRAINER_PARTY_IVS(18, 18, 18, 18, 18, 18),
#line 7961
            .lvl = 45,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 7963
                MOVE_HYDRO_PUMP,
                MOVE_TWISTER,
                MOVE_LEER,
                MOVE_RAIN_DANCE,
            },
            },
            {
#line 7968
            .species = SPECIES_ALAKAZAM,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7970
            .iv = TRAINER_PARTY_IVS(18, 18, 18, 18, 18, 18),
#line 7969
            .lvl = 47,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 7971
                MOVE_PSYCHIC,
                MOVE_CALM_MIND,
                MOVE_FUTURE_SIGHT,
                MOVE_DISABLE,
            },
            },
            {
#line 7976
            .species = SPECIES_CHARIZARD,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7978
            .iv = TRAINER_PARTY_IVS(30, 30, 30, 30, 30, 30),
#line 7977
            .lvl = 53,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 7979
                MOVE_FLAMETHROWER,
                MOVE_WING_ATTACK,
                MOVE_SLASH,
                MOVE_SCARY_FACE,
            },
            },
        },
    },
#line 7984
    [DIFFICULTY_NORMAL][TRAINER_CHAMPION_FIRST_SQUIRTLE] =
    {
#line 7985
        .trainerName = _("TERRY"),
#line 7986
        .trainerClass = TRAINER_CLASS_CHAMPION,
#line 7987
        .trainerPic = TRAINER_PIC_CHAMPION_RIVAL,
        .encounterMusic_gender =
#line 7989
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 7990
        .items = { ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_FULL_RESTORE },
#line 7991
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 7992
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
#line 7993
        .mugshotColor = MUGSHOT_COLOR_YELLOW,
        .partySize = 6,
        .party = (const struct TrainerMon[])
        {
            {
#line 7995
            .species = SPECIES_PIDGEOT,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7997
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 7996
            .lvl = 59,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 7998
                MOVE_AERIAL_ACE,
                MOVE_FEATHER_DANCE,
                MOVE_SAND_ATTACK,
                MOVE_WHIRLWIND,
            },
            },
            {
#line 8003
            .species = SPECIES_ALAKAZAM,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8005
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 8004
            .lvl = 57,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 8006
                MOVE_PSYCHIC,
                MOVE_FUTURE_SIGHT,
                MOVE_RECOVER,
                MOVE_REFLECT,
            },
            },
            {
#line 8011
            .species = SPECIES_RHYDON,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8013
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 8012
            .lvl = 59,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 8014
                MOVE_TAKE_DOWN,
                MOVE_EARTHQUAKE,
                MOVE_ROCK_TOMB,
                MOVE_SCARY_FACE,
            },
            },
            {
#line 8019
            .species = SPECIES_ARCANINE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8021
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 8020
            .lvl = 59,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 8022
                MOVE_EXTREME_SPEED,
                MOVE_FLAMETHROWER,
                MOVE_ROAR,
                MOVE_BITE,
            },
            },
            {
#line 8027
            .species = SPECIES_EXEGGUTOR,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8029
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 8028
            .lvl = 61,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 8030
                MOVE_GIGA_DRAIN,
                MOVE_EGG_BOMB,
                MOVE_SLEEP_POWDER,
                MOVE_LIGHT_SCREEN,
            },
            },
            {
#line 8035
            .species = SPECIES_BLASTOISE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8035
            .heldItem = ITEM_SITRUS_BERRY,
#line 8037
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 8036
            .lvl = 63,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 8038
                MOVE_HYDRO_PUMP,
                MOVE_RAIN_DANCE,
                MOVE_SKULL_BASH,
                MOVE_BITE,
            },
            },
        },
    },
#line 8043
    [DIFFICULTY_NORMAL][TRAINER_CHAMPION_FIRST_BULBASAUR] =
    {
#line 8044
        .trainerName = _("TERRY"),
#line 8045
        .trainerClass = TRAINER_CLASS_CHAMPION,
#line 8046
        .trainerPic = TRAINER_PIC_CHAMPION_RIVAL,
        .encounterMusic_gender =
#line 8048
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 8049
        .items = { ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_FULL_RESTORE },
#line 8050
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 8051
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
#line 8052
        .mugshotColor = MUGSHOT_COLOR_YELLOW,
        .partySize = 6,
        .party = (const struct TrainerMon[])
        {
            {
#line 8054
            .species = SPECIES_PIDGEOT,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8056
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 8055
            .lvl = 59,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 8057
                MOVE_AERIAL_ACE,
                MOVE_FEATHER_DANCE,
                MOVE_SAND_ATTACK,
                MOVE_WHIRLWIND,
            },
            },
            {
#line 8062
            .species = SPECIES_ALAKAZAM,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8064
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 8063
            .lvl = 57,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 8065
                MOVE_PSYCHIC,
                MOVE_FUTURE_SIGHT,
                MOVE_RECOVER,
                MOVE_REFLECT,
            },
            },
            {
#line 8070
            .species = SPECIES_RHYDON,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8072
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 8071
            .lvl = 59,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 8073
                MOVE_TAKE_DOWN,
                MOVE_EARTHQUAKE,
                MOVE_ROCK_TOMB,
                MOVE_SCARY_FACE,
            },
            },
            {
#line 8078
            .species = SPECIES_GYARADOS,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8080
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 8079
            .lvl = 59,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 8081
                MOVE_HYDRO_PUMP,
                MOVE_DRAGON_RAGE,
                MOVE_BITE,
                MOVE_THRASH,
            },
            },
            {
#line 8086
            .species = SPECIES_ARCANINE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8088
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 8087
            .lvl = 61,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 8089
                MOVE_EXTREME_SPEED,
                MOVE_FLAMETHROWER,
                MOVE_ROAR,
                MOVE_BITE,
            },
            },
            {
#line 8094
            .species = SPECIES_VENUSAUR,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8094
            .heldItem = ITEM_SITRUS_BERRY,
#line 8096
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 8095
            .lvl = 63,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 8097
                MOVE_SOLAR_BEAM,
                MOVE_SYNTHESIS,
                MOVE_SUNNY_DAY,
                MOVE_GROWTH,
            },
            },
        },
    },
#line 8102
    [DIFFICULTY_NORMAL][TRAINER_CHAMPION_FIRST_CHARMANDER] =
    {
#line 8103
        .trainerName = _("TERRY"),
#line 8104
        .trainerClass = TRAINER_CLASS_CHAMPION,
#line 8105
        .trainerPic = TRAINER_PIC_CHAMPION_RIVAL,
        .encounterMusic_gender =
#line 8107
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 8108
        .items = { ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_FULL_RESTORE },
#line 8109
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 8110
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
#line 8111
        .mugshotColor = MUGSHOT_COLOR_YELLOW,
        .partySize = 6,
        .party = (const struct TrainerMon[])
        {
            {
#line 8113
            .species = SPECIES_PIDGEOT,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8115
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 8114
            .lvl = 59,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 8116
                MOVE_AERIAL_ACE,
                MOVE_FEATHER_DANCE,
                MOVE_SAND_ATTACK,
                MOVE_WHIRLWIND,
            },
            },
            {
#line 8121
            .species = SPECIES_ALAKAZAM,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8123
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 8122
            .lvl = 57,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 8124
                MOVE_PSYCHIC,
                MOVE_FUTURE_SIGHT,
                MOVE_RECOVER,
                MOVE_REFLECT,
            },
            },
            {
#line 8129
            .species = SPECIES_RHYDON,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8131
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 8130
            .lvl = 59,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 8132
                MOVE_TAKE_DOWN,
                MOVE_EARTHQUAKE,
                MOVE_ROCK_TOMB,
                MOVE_SCARY_FACE,
            },
            },
            {
#line 8137
            .species = SPECIES_EXEGGUTOR,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8139
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 8138
            .lvl = 59,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 8140
                MOVE_GIGA_DRAIN,
                MOVE_EGG_BOMB,
                MOVE_SLEEP_POWDER,
                MOVE_LIGHT_SCREEN,
            },
            },
            {
#line 8145
            .species = SPECIES_GYARADOS,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8147
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 8146
            .lvl = 61,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 8148
                MOVE_HYDRO_PUMP,
                MOVE_DRAGON_RAGE,
                MOVE_BITE,
                MOVE_THRASH,
            },
            },
            {
#line 8153
            .species = SPECIES_CHARIZARD,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8153
            .heldItem = ITEM_SITRUS_BERRY,
#line 8155
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 8154
            .lvl = 63,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 8156
                MOVE_FIRE_BLAST,
                MOVE_AERIAL_ACE,
                MOVE_SLASH,
                MOVE_FIRE_SPIN,
            },
            },
        },
    },
#line 8161
    [DIFFICULTY_NORMAL][TRAINER_CHANNELER_PATRICIA] =
    {
#line 8162
        .trainerName = _("PATRICIA"),
#line 8163
        .trainerClass = TRAINER_CLASS_CHANNELER,
#line 8164
        .trainerPic = TRAINER_PIC_CHANNELER,
        .encounterMusic_gender =
#line 8166
            TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
#line 8167
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 8168
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 8170
            .species = SPECIES_GASTLY,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8172
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 8171
            .lvl = 22,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 8174
    [DIFFICULTY_NORMAL][TRAINER_CHANNELER_CARLY] =
    {
#line 8175
        .trainerName = _("CARLY"),
#line 8176
        .trainerClass = TRAINER_CLASS_CHANNELER,
#line 8177
        .trainerPic = TRAINER_PIC_CHANNELER,
        .encounterMusic_gender =
#line 8179
            TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
#line 8180
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 8181
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 8183
            .species = SPECIES_GASTLY,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8185
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 8184
            .lvl = 24,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 8187
    [DIFFICULTY_NORMAL][TRAINER_CHANNELER_HOPE] =
    {
#line 8188
        .trainerName = _("HOPE"),
#line 8189
        .trainerClass = TRAINER_CLASS_CHANNELER,
#line 8190
        .trainerPic = TRAINER_PIC_CHANNELER,
        .encounterMusic_gender =
#line 8192
            TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
#line 8193
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 8194
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 8196
            .species = SPECIES_GASTLY,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8198
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 8197
            .lvl = 23,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 8200
    [DIFFICULTY_NORMAL][TRAINER_CHANNELER_PAULA] =
    {
#line 8201
        .trainerName = _("PAULA"),
#line 8202
        .trainerClass = TRAINER_CLASS_CHANNELER,
#line 8203
        .trainerPic = TRAINER_PIC_CHANNELER,
        .encounterMusic_gender =
#line 8205
            TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
#line 8206
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 8207
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 8209
            .species = SPECIES_GASTLY,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8211
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 8210
            .lvl = 24,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 8213
    [DIFFICULTY_NORMAL][TRAINER_CHANNELER_LAUREL] =
    {
#line 8214
        .trainerName = _("LAUREL"),
#line 8215
        .trainerClass = TRAINER_CLASS_CHANNELER,
#line 8216
        .trainerPic = TRAINER_PIC_CHANNELER,
        .encounterMusic_gender =
#line 8218
            TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
#line 8219
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 8220
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 8222
            .species = SPECIES_GASTLY,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8224
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 8223
            .lvl = 23,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 8226
            .species = SPECIES_GASTLY,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8228
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 8227
            .lvl = 23,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 8230
    [DIFFICULTY_NORMAL][TRAINER_CHANNELER_JODY] =
    {
#line 8231
        .trainerName = _("JODY"),
#line 8232
        .trainerClass = TRAINER_CLASS_CHANNELER,
#line 8233
        .trainerPic = TRAINER_PIC_CHANNELER,
        .encounterMusic_gender =
#line 8235
            TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
#line 8236
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 8237
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 8239
            .species = SPECIES_GASTLY,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8241
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 8240
            .lvl = 22,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 8243
    [DIFFICULTY_NORMAL][TRAINER_CHANNELER_TAMMY] =
    {
#line 8244
        .trainerName = _("TAMMY"),
#line 8245
        .trainerClass = TRAINER_CLASS_CHANNELER,
#line 8246
        .trainerPic = TRAINER_PIC_CHANNELER,
        .encounterMusic_gender =
#line 8248
            TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
#line 8249
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 8250
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 8252
            .species = SPECIES_HAUNTER,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8254
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 8253
            .lvl = 23,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 8256
    [DIFFICULTY_NORMAL][TRAINER_CHANNELER_RUTH] =
    {
#line 8257
        .trainerName = _("RUTH"),
#line 8258
        .trainerClass = TRAINER_CLASS_CHANNELER,
#line 8259
        .trainerPic = TRAINER_PIC_CHANNELER,
        .encounterMusic_gender =
#line 8261
            TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
#line 8262
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 8263
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 8265
            .species = SPECIES_GASTLY,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8267
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 8266
            .lvl = 22,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 8269
    [DIFFICULTY_NORMAL][TRAINER_CHANNELER_KARINA] =
    {
#line 8270
        .trainerName = _("KARINA"),
#line 8271
        .trainerClass = TRAINER_CLASS_CHANNELER,
#line 8272
        .trainerPic = TRAINER_PIC_CHANNELER,
        .encounterMusic_gender =
#line 8274
            TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
#line 8275
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 8276
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 8278
            .species = SPECIES_GASTLY,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8280
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 8279
            .lvl = 24,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 8282
    [DIFFICULTY_NORMAL][TRAINER_CHANNELER_JANAE] =
    {
#line 8283
        .trainerName = _("JANAE"),
#line 8284
        .trainerClass = TRAINER_CLASS_CHANNELER,
#line 8285
        .trainerPic = TRAINER_PIC_CHANNELER,
        .encounterMusic_gender =
#line 8287
            TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
#line 8288
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 8289
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 8291
            .species = SPECIES_GASTLY,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8293
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 8292
            .lvl = 22,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 8295
    [DIFFICULTY_NORMAL][TRAINER_CHANNELER_ANGELICA] =
    {
#line 8296
        .trainerName = _("ANGELICA"),
#line 8297
        .trainerClass = TRAINER_CLASS_CHANNELER,
#line 8298
        .trainerPic = TRAINER_PIC_CHANNELER,
        .encounterMusic_gender =
#line 8300
            TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
#line 8301
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 8302
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 8304
            .species = SPECIES_GASTLY,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8306
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 8305
            .lvl = 22,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 8308
            .species = SPECIES_GASTLY,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8310
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 8309
            .lvl = 22,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 8312
            .species = SPECIES_GASTLY,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8314
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 8313
            .lvl = 22,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 8316
    [DIFFICULTY_NORMAL][TRAINER_CHANNELER_EMILIA] =
    {
#line 8317
        .trainerName = _("EMILIA"),
#line 8318
        .trainerClass = TRAINER_CLASS_CHANNELER,
#line 8319
        .trainerPic = TRAINER_PIC_CHANNELER,
        .encounterMusic_gender =
#line 8321
            TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
#line 8322
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 8323
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 8325
            .species = SPECIES_GASTLY,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8327
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 8326
            .lvl = 24,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 8329
    [DIFFICULTY_NORMAL][TRAINER_CHANNELER_JENNIFER] =
    {
#line 8330
        .trainerName = _("JENNIFER"),
#line 8331
        .trainerClass = TRAINER_CLASS_CHANNELER,
#line 8332
        .trainerPic = TRAINER_PIC_CHANNELER,
        .encounterMusic_gender =
#line 8334
            TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
#line 8335
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 8336
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 8338
            .species = SPECIES_GASTLY,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8340
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 8339
            .lvl = 24,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 8342
    [DIFFICULTY_NORMAL][TRAINER_CHANNELER_1] =
    {
#line 8343
        .trainerName = _("PH"),
#line 8344
        .trainerClass = TRAINER_CLASS_CHANNELER,
#line 8345
        .trainerPic = TRAINER_PIC_CHANNELER,
        .encounterMusic_gender =
#line 8347
            TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
#line 8348
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 8349
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 8351
            .species = SPECIES_HAUNTER,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8353
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 8352
            .lvl = 23,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 8355
    [DIFFICULTY_NORMAL][TRAINER_CHANNELER_2] =
    {
#line 8356
        .trainerName = _("PH"),
#line 8357
        .trainerClass = TRAINER_CLASS_CHANNELER,
#line 8358
        .trainerPic = TRAINER_PIC_CHANNELER,
        .encounterMusic_gender =
#line 8360
            TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
#line 8361
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 8362
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 8364
            .species = SPECIES_GASTLY,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8366
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 8365
            .lvl = 24,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 8368
    [DIFFICULTY_NORMAL][TRAINER_CHANNELER_3] =
    {
#line 8369
        .trainerName = _("PH"),
#line 8370
        .trainerClass = TRAINER_CLASS_CHANNELER,
#line 8371
        .trainerPic = TRAINER_PIC_CHANNELER,
        .encounterMusic_gender =
#line 8373
            TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
#line 8374
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 8375
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 8377
            .species = SPECIES_GASTLY,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8379
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 8378
            .lvl = 22,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 8381
    [DIFFICULTY_NORMAL][TRAINER_CHANNELER_4] =
    {
#line 8382
        .trainerName = _("PH"),
#line 8383
        .trainerClass = TRAINER_CLASS_CHANNELER,
#line 8384
        .trainerPic = TRAINER_PIC_CHANNELER,
        .encounterMusic_gender =
#line 8386
            TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
#line 8387
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 8388
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 8390
            .species = SPECIES_GASTLY,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8392
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 8391
            .lvl = 24,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 8394
    [DIFFICULTY_NORMAL][TRAINER_CHANNELER_5] =
    {
#line 8395
        .trainerName = _("PH"),
#line 8396
        .trainerClass = TRAINER_CLASS_CHANNELER,
#line 8397
        .trainerPic = TRAINER_PIC_CHANNELER,
        .encounterMusic_gender =
#line 8399
            TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
#line 8400
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 8401
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 8403
            .species = SPECIES_HAUNTER,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8405
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 8404
            .lvl = 22,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 8407
    [DIFFICULTY_NORMAL][TRAINER_CHANNELER_6] =
    {
#line 8408
        .trainerName = _("PH"),
#line 8409
        .trainerClass = TRAINER_CLASS_CHANNELER,
#line 8410
        .trainerPic = TRAINER_PIC_CHANNELER,
        .encounterMusic_gender =
#line 8412
            TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
#line 8413
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 8414
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 8416
            .species = SPECIES_GASTLY,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8418
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 8417
            .lvl = 22,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 8420
            .species = SPECIES_GASTLY,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8422
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 8421
            .lvl = 22,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 8424
            .species = SPECIES_GASTLY,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8426
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 8425
            .lvl = 22,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 8428
    [DIFFICULTY_NORMAL][TRAINER_CHANNELER_7] =
    {
#line 8429
        .trainerName = _("PH"),
#line 8430
        .trainerClass = TRAINER_CLASS_CHANNELER,
#line 8431
        .trainerPic = TRAINER_PIC_CHANNELER,
        .encounterMusic_gender =
#line 8433
            TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
#line 8434
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 8435
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 8437
            .species = SPECIES_GASTLY,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8439
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 8438
            .lvl = 24,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 8441
    [DIFFICULTY_NORMAL][TRAINER_CHANNELER_8] =
    {
#line 8442
        .trainerName = _("PH"),
#line 8443
        .trainerClass = TRAINER_CLASS_CHANNELER,
#line 8444
        .trainerPic = TRAINER_PIC_CHANNELER,
        .encounterMusic_gender =
#line 8446
            TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
#line 8447
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 8448
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 8450
            .species = SPECIES_GASTLY,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8452
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 8451
            .lvl = 24,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 8454
    [DIFFICULTY_NORMAL][TRAINER_CHANNELER_AMANDA] =
    {
#line 8455
        .trainerName = _("AMANDA"),
#line 8456
        .trainerClass = TRAINER_CLASS_CHANNELER,
#line 8457
        .trainerPic = TRAINER_PIC_CHANNELER,
        .encounterMusic_gender =
#line 8459
            TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
#line 8460
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 8461
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 8463
            .species = SPECIES_GASTLY,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8465
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 8464
            .lvl = 34,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 8467
            .species = SPECIES_HAUNTER,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8469
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 8468
            .lvl = 34,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 8471
    [DIFFICULTY_NORMAL][TRAINER_CHANNELER_STACY] =
    {
#line 8472
        .trainerName = _("STACY"),
#line 8473
        .trainerClass = TRAINER_CLASS_CHANNELER,
#line 8474
        .trainerPic = TRAINER_PIC_CHANNELER,
        .encounterMusic_gender =
#line 8476
            TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
#line 8477
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 8478
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 8480
            .species = SPECIES_HAUNTER,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8482
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 8481
            .lvl = 38,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 8484
    [DIFFICULTY_NORMAL][TRAINER_CHANNELER_TASHA] =
    {
#line 8485
        .trainerName = _("TASHA"),
#line 8486
        .trainerClass = TRAINER_CLASS_CHANNELER,
#line 8487
        .trainerPic = TRAINER_PIC_CHANNELER,
        .encounterMusic_gender =
#line 8489
            TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
#line 8490
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 8491
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 8493
            .species = SPECIES_GASTLY,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8495
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 8494
            .lvl = 33,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 8497
            .species = SPECIES_GASTLY,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8499
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 8498
            .lvl = 33,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 8501
            .species = SPECIES_HAUNTER,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8503
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 8502
            .lvl = 33,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 8505
    [DIFFICULTY_NORMAL][TRAINER_HIKER_JEREMY] =
    {
#line 8506
        .trainerName = _("JEREMY"),
#line 8507
        .trainerClass = TRAINER_CLASS_HIKER,
#line 8508
        .trainerPic = TRAINER_PIC_HIKER,
        .encounterMusic_gender =
#line 8510
            TRAINER_ENCOUNTER_MUSIC_HIKER,
#line 8511
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 8512
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 8514
            .species = SPECIES_MACHOP,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8516
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 8515
            .lvl = 20,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 8518
            .species = SPECIES_ONIX,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8520
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 8519
            .lvl = 20,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 8522
    [DIFFICULTY_NORMAL][TRAINER_PICNICKER_ALMA] =
    {
#line 8523
        .trainerName = _("ALMA"),
#line 8524
        .trainerClass = TRAINER_CLASS_PICNICKER,
#line 8525
        .trainerPic = TRAINER_PIC_PICNICKER,
        .encounterMusic_gender =
#line 8527
            TRAINER_ENCOUNTER_MUSIC_GIRL,
#line 8528
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 8529
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 8531
            .species = SPECIES_GOLDEEN,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8533
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 8532
            .lvl = 28,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 8535
            .species = SPECIES_POLIWAG,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8537
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 8536
            .lvl = 28,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 8539
            .species = SPECIES_HORSEA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8541
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 8540
            .lvl = 28,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 8543
    [DIFFICULTY_NORMAL][TRAINER_PICNICKER_SUSIE] =
    {
#line 8544
        .trainerName = _("SUSIE"),
#line 8545
        .trainerClass = TRAINER_CLASS_PICNICKER,
#line 8546
        .trainerPic = TRAINER_PIC_PICNICKER,
        .encounterMusic_gender =
#line 8548
            TRAINER_ENCOUNTER_MUSIC_GIRL,
#line 8549
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 8550
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 5,
        .party = (const struct TrainerMon[])
        {
            {
#line 8552
            .species = SPECIES_PIDGEY,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8554
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 8553
            .lvl = 24,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 8556
            .species = SPECIES_MEOWTH,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8558
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 8557
            .lvl = 24,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 8560
            .species = SPECIES_RATTATA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8562
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 8561
            .lvl = 24,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 8564
            .species = SPECIES_PIKACHU,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8566
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 8565
            .lvl = 24,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 8568
            .species = SPECIES_MEOWTH,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8570
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 8569
            .lvl = 24,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 8572
    [DIFFICULTY_NORMAL][TRAINER_PICNICKER_VALERIE] =
    {
#line 8573
        .trainerName = _("VALERIE"),
#line 8574
        .trainerClass = TRAINER_CLASS_PICNICKER,
#line 8575
        .trainerPic = TRAINER_PIC_PICNICKER,
        .encounterMusic_gender =
#line 8577
            TRAINER_ENCOUNTER_MUSIC_GIRL,
#line 8578
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 8579
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 8581
            .species = SPECIES_POLIWAG,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8583
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 8582
            .lvl = 30,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 8585
            .species = SPECIES_POLIWAG,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8587
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 8586
            .lvl = 30,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 8589
    [DIFFICULTY_NORMAL][TRAINER_PICNICKER_GWEN] =
    {
#line 8590
        .trainerName = _("GWEN"),
#line 8591
        .trainerClass = TRAINER_CLASS_PICNICKER,
#line 8592
        .trainerPic = TRAINER_PIC_PICNICKER,
        .encounterMusic_gender =
#line 8594
            TRAINER_ENCOUNTER_MUSIC_GIRL,
#line 8595
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 8596
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 4,
        .party = (const struct TrainerMon[])
        {
            {
#line 8598
            .species = SPECIES_PIDGEY,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8600
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 8599
            .lvl = 27,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 8602
            .species = SPECIES_MEOWTH,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8604
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 8603
            .lvl = 27,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 8606
            .species = SPECIES_PIDGEY,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8608
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 8607
            .lvl = 27,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 8610
            .species = SPECIES_PIDGEOTTO,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8612
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 8611
            .lvl = 27,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 8614
    [DIFFICULTY_NORMAL][TRAINER_BIKER_VIRGIL] =
    {
#line 8615
        .trainerName = _("VIRGIL"),
#line 8616
        .trainerClass = TRAINER_CLASS_BIKER,
#line 8617
        .trainerPic = TRAINER_PIC_BIKER,
        .encounterMusic_gender =
#line 8619
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 8620
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 8621
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 8623
            .species = SPECIES_WEEZING,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8625
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 8624
            .lvl = 28,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 8626
                MOVE_SMOKESCREEN,
                MOVE_SLUDGE,
                MOVE_SMOG,
                MOVE_TACKLE,
            },
            },
            {
#line 8631
            .species = SPECIES_KOFFING,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8633
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 8632
            .lvl = 28,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 8634
                MOVE_SMOKESCREEN,
                MOVE_SLUDGE,
                MOVE_SMOG,
                MOVE_TACKLE,
            },
            },
            {
#line 8639
            .species = SPECIES_WEEZING,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8641
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 8640
            .lvl = 28,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 8642
                MOVE_SMOKESCREEN,
                MOVE_SLUDGE,
                MOVE_SMOG,
                MOVE_TACKLE,
            },
            },
        },
    },
#line 8647
    [DIFFICULTY_NORMAL][TRAINER_CAMPER_FLINT] =
    {
#line 8648
        .trainerName = _("FLINT"),
#line 8649
        .trainerClass = TRAINER_CLASS_CAMPER,
#line 8650
        .trainerPic = TRAINER_PIC_CAMPER,
        .encounterMusic_gender =
#line 8652
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 8653
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 8654
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 8656
            .species = SPECIES_RATTATA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8658
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 8657
            .lvl = 14,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 8660
            .species = SPECIES_EKANS,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8662
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 8661
            .lvl = 14,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 8664
    [DIFFICULTY_NORMAL][TRAINER_PICNICKER_MISSY] =
    {
#line 8665
        .trainerName = _("MISSY"),
#line 8666
        .trainerClass = TRAINER_CLASS_PICNICKER,
#line 8667
        .trainerPic = TRAINER_PIC_PICNICKER,
        .encounterMusic_gender =
#line 8669
            TRAINER_ENCOUNTER_MUSIC_GIRL,
#line 8670
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 8671
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 8673
            .species = SPECIES_GOLDEEN,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8675
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 8674
            .lvl = 31,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 8677
            .species = SPECIES_SEAKING,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8679
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 8678
            .lvl = 31,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 8681
    [DIFFICULTY_NORMAL][TRAINER_PICNICKER_IRENE] =
    {
#line 8682
        .trainerName = _("IRENE"),
#line 8683
        .trainerClass = TRAINER_CLASS_PICNICKER,
#line 8684
        .trainerPic = TRAINER_PIC_PICNICKER,
        .encounterMusic_gender =
#line 8686
            TRAINER_ENCOUNTER_MUSIC_GIRL,
#line 8687
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 8688
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 8690
            .species = SPECIES_TENTACOOL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8692
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 8691
            .lvl = 30,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 8694
            .species = SPECIES_HORSEA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8696
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 8695
            .lvl = 30,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 8698
            .species = SPECIES_SEEL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8700
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 8699
            .lvl = 30,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 8702
    [DIFFICULTY_NORMAL][TRAINER_PICNICKER_DANA] =
    {
#line 8703
        .trainerName = _("DANA"),
#line 8704
        .trainerClass = TRAINER_CLASS_PICNICKER,
#line 8705
        .trainerPic = TRAINER_PIC_PICNICKER,
        .encounterMusic_gender =
#line 8707
            TRAINER_ENCOUNTER_MUSIC_GIRL,
#line 8708
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 8709
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 8711
            .species = SPECIES_MEOWTH,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8713
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 8712
            .lvl = 20,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 8715
            .species = SPECIES_ODDISH,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8717
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 8716
            .lvl = 20,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 8719
            .species = SPECIES_PIDGEY,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8721
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 8720
            .lvl = 20,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 8723
    [DIFFICULTY_NORMAL][TRAINER_PICNICKER_ARIANA] =
    {
#line 8724
        .trainerName = _("ARIANA"),
#line 8725
        .trainerClass = TRAINER_CLASS_PICNICKER,
#line 8726
        .trainerPic = TRAINER_PIC_PICNICKER,
        .encounterMusic_gender =
#line 8728
            TRAINER_ENCOUNTER_MUSIC_GIRL,
#line 8729
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 8730
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 4,
        .party = (const struct TrainerMon[])
        {
            {
#line 8732
            .species = SPECIES_PIDGEY,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8734
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 8733
            .lvl = 19,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 8736
            .species = SPECIES_RATTATA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8738
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 8737
            .lvl = 19,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 8740
            .species = SPECIES_RATTATA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8742
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 8741
            .lvl = 19,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 8744
            .species = SPECIES_BELLSPROUT,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8746
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 8745
            .lvl = 19,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 8748
    [DIFFICULTY_NORMAL][TRAINER_PICNICKER_LEAH] =
    {
#line 8749
        .trainerName = _("LEAH"),
#line 8750
        .trainerClass = TRAINER_CLASS_PICNICKER,
#line 8751
        .trainerPic = TRAINER_PIC_PICNICKER,
        .encounterMusic_gender =
#line 8753
            TRAINER_ENCOUNTER_MUSIC_GIRL,
#line 8754
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 8755
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 8757
            .species = SPECIES_BELLSPROUT,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8759
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 8758
            .lvl = 22,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 8761
            .species = SPECIES_CLEFAIRY,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8763
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 8762
            .lvl = 22,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 8765
    [DIFFICULTY_NORMAL][TRAINER_CAMPER_JUSTIN] =
    {
#line 8766
        .trainerName = _("JUSTIN"),
#line 8767
        .trainerClass = TRAINER_CLASS_CAMPER,
#line 8768
        .trainerPic = TRAINER_PIC_CAMPER,
        .encounterMusic_gender =
#line 8770
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 8771
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 8772
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 8774
            .species = SPECIES_NIDORAN_M,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8776
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 8775
            .lvl = 29,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 8778
            .species = SPECIES_NIDORINO,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8780
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 8779
            .lvl = 29,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 8782
    [DIFFICULTY_NORMAL][TRAINER_PICNICKER_YAZMIN] =
    {
#line 8783
        .trainerName = _("YAZMIN"),
#line 8784
        .trainerClass = TRAINER_CLASS_PICNICKER,
#line 8785
        .trainerPic = TRAINER_PIC_PICNICKER,
        .encounterMusic_gender =
#line 8787
            TRAINER_ENCOUNTER_MUSIC_GIRL,
#line 8788
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 8789
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 8791
            .species = SPECIES_BELLSPROUT,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8793
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 8792
            .lvl = 29,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 8795
            .species = SPECIES_ODDISH,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8797
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 8796
            .lvl = 29,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 8799
            .species = SPECIES_TANGELA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8801
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 8800
            .lvl = 29,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 8803
    [DIFFICULTY_NORMAL][TRAINER_PICNICKER_KINDRA] =
    {
#line 8804
        .trainerName = _("KINDRA"),
#line 8805
        .trainerClass = TRAINER_CLASS_PICNICKER,
#line 8806
        .trainerPic = TRAINER_PIC_PICNICKER,
        .encounterMusic_gender =
#line 8808
            TRAINER_ENCOUNTER_MUSIC_GIRL,
#line 8809
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 8810
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 8812
            .species = SPECIES_GLOOM,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8814
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 8813
            .lvl = 28,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 8816
            .species = SPECIES_ODDISH,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8818
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 8817
            .lvl = 28,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 8820
            .species = SPECIES_ODDISH,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8822
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 8821
            .lvl = 28,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 8824
    [DIFFICULTY_NORMAL][TRAINER_PICNICKER_BECKY] =
    {
#line 8825
        .trainerName = _("BECKY"),
#line 8826
        .trainerClass = TRAINER_CLASS_PICNICKER,
#line 8827
        .trainerPic = TRAINER_PIC_PICNICKER,
        .encounterMusic_gender =
#line 8829
            TRAINER_ENCOUNTER_MUSIC_GIRL,
#line 8830
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 8831
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 8833
            .species = SPECIES_PIKACHU,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8835
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 8834
            .lvl = 29,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 8837
            .species = SPECIES_RAICHU,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8839
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 8838
            .lvl = 29,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 8841
    [DIFFICULTY_NORMAL][TRAINER_PICNICKER_CELIA] =
    {
#line 8842
        .trainerName = _("CELIA"),
#line 8843
        .trainerClass = TRAINER_CLASS_PICNICKER,
#line 8844
        .trainerPic = TRAINER_PIC_PICNICKER,
        .encounterMusic_gender =
#line 8846
            TRAINER_ENCOUNTER_MUSIC_GIRL,
#line 8847
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 8848
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 8850
            .species = SPECIES_CLEFAIRY,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8852
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 8851
            .lvl = 33,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 8854
    [DIFFICULTY_NORMAL][TRAINER_GENTLEMAN_BROOKS] =
    {
#line 8855
        .trainerName = _("BROOKS"),
#line 8856
        .trainerClass = TRAINER_CLASS_GENTLEMAN,
#line 8857
        .trainerPic = TRAINER_PIC_GENTLEMAN,
        .encounterMusic_gender =
#line 8859
            TRAINER_ENCOUNTER_MUSIC_RICH,
#line 8860
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 8861
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 8863
            .species = SPECIES_PIKACHU,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8865
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 8864
            .lvl = 23,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 8867
    [DIFFICULTY_NORMAL][TRAINER_GENTLEMAN_LAMAR] =
    {
#line 8868
        .trainerName = _("LAMAR"),
#line 8869
        .trainerClass = TRAINER_CLASS_GENTLEMAN,
#line 8870
        .trainerPic = TRAINER_PIC_GENTLEMAN,
        .encounterMusic_gender =
#line 8872
            TRAINER_ENCOUNTER_MUSIC_RICH,
#line 8873
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 8874
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 8876
            .species = SPECIES_GROWLITHE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8878
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 8877
            .lvl = 17,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 8880
            .species = SPECIES_PONYTA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8882
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 8881
            .lvl = 17,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 8884
    [DIFFICULTY_NORMAL][TRAINER_TWINS_ELI_ANNE] =
    {
#line 8885
        .trainerName = _("ELI & ANNE"),
#line 8886
        .trainerClass = TRAINER_CLASS_TWINS,
#line 8887
        .trainerPic = TRAINER_PIC_TWINS,
        .encounterMusic_gender =
#line 8889
            TRAINER_ENCOUNTER_MUSIC_TWINS,
#line 8890
        .battleType = TRAINER_BATTLE_TYPE_DOUBLES,
#line 8891
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 8893
            .species = SPECIES_CLEFAIRY,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8895
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 8894
            .lvl = 22,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 8897
            .species = SPECIES_JIGGLYPUFF,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8899
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 8898
            .lvl = 22,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 8901
    [DIFFICULTY_NORMAL][TRAINER_COOL_COUPLE_RAY_TYRA] =
    {
#line 8902
        .trainerName = _("RAY & TYRA"),
#line 8903
        .trainerClass = TRAINER_CLASS_COOL_COUPLE,
#line 8904
        .trainerPic = TRAINER_PIC_COOL_COUPLE,
        .encounterMusic_gender =
#line 8906
            TRAINER_ENCOUNTER_MUSIC_COOL,
#line 8907
        .battleType = TRAINER_BATTLE_TYPE_DOUBLES,
#line 8908
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 8910
            .species = SPECIES_NIDOQUEEN,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8912
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 8911
            .lvl = 45,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 8913
                MOVE_SUPERPOWER,
                MOVE_BODY_SLAM,
                MOVE_DOUBLE_KICK,
                MOVE_POISON_STING,
            },
            },
            {
#line 8918
            .species = SPECIES_NIDOKING,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8920
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 8919
            .lvl = 45,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 8921
                MOVE_MEGAHORN,
                MOVE_THRASH,
                MOVE_DOUBLE_KICK,
                MOVE_POISON_STING,
            },
            },
        },
    },
#line 8926
    [DIFFICULTY_NORMAL][TRAINER_YOUNG_COUPLE_GIA_JES] =
    {
#line 8927
        .trainerName = _("GIA & JES"),
#line 8928
        .trainerClass = TRAINER_CLASS_YOUNG_COUPLE,
#line 8929
        .trainerPic = TRAINER_PIC_YOUNG_COUPLE,
        .encounterMusic_gender =
#line 8931
            TRAINER_ENCOUNTER_MUSIC_GIRL,
#line 8932
        .battleType = TRAINER_BATTLE_TYPE_DOUBLES,
#line 8933
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 8935
            .species = SPECIES_NIDORAN_M,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8937
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 8936
            .lvl = 24,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 8939
            .species = SPECIES_NIDORAN_F,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8941
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 8940
            .lvl = 24,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 8943
    [DIFFICULTY_NORMAL][TRAINER_TWINS_KIRI_JAN] =
    {
#line 8944
        .trainerName = _("KIRI & JAN"),
#line 8945
        .trainerClass = TRAINER_CLASS_TWINS,
#line 8946
        .trainerPic = TRAINER_PIC_TWINS,
        .encounterMusic_gender =
#line 8948
            TRAINER_ENCOUNTER_MUSIC_TWINS,
#line 8949
        .battleType = TRAINER_BATTLE_TYPE_DOUBLES,
#line 8950
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 8952
            .species = SPECIES_CHARMANDER,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8954
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 8953
            .lvl = 29,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 8956
            .species = SPECIES_SQUIRTLE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8958
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 8957
            .lvl = 29,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 8960
    [DIFFICULTY_NORMAL][TRAINER_CRUSH_KIN_RON_MYA] =
    {
#line 8961
        .trainerName = _("RON & MYA"),
#line 8962
        .trainerClass = TRAINER_CLASS_CRUSH_KIN,
#line 8963
        .trainerPic = TRAINER_PIC_CRUSH_KIN,
        .encounterMusic_gender =
#line 8965
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
#line 8966
        .battleType = TRAINER_BATTLE_TYPE_DOUBLES,
#line 8967
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 8969
            .species = SPECIES_HITMONCHAN,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8969
            .heldItem = ITEM_BLACK_BELT,
#line 8971
            .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
#line 8970
            .lvl = 29,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 8973
            .species = SPECIES_HITMONLEE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8973
            .heldItem = ITEM_BLACK_BELT,
#line 8975
            .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
#line 8974
            .lvl = 29,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 8977
    [DIFFICULTY_NORMAL][TRAINER_YOUNG_COUPLE_LEA_JED] =
    {
#line 8978
        .trainerName = _("LEA & JED"),
#line 8979
        .trainerClass = TRAINER_CLASS_YOUNG_COUPLE,
#line 8980
        .trainerPic = TRAINER_PIC_YOUNG_COUPLE,
        .encounterMusic_gender =
#line 8982
            TRAINER_ENCOUNTER_MUSIC_GIRL,
#line 8983
        .battleType = TRAINER_BATTLE_TYPE_DOUBLES,
#line 8984
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 8986
            .species = SPECIES_RAPIDASH,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8988
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 8987
            .lvl = 29,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 8990
            .species = SPECIES_NINETALES,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8992
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 8991
            .lvl = 29,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 8994
    [DIFFICULTY_NORMAL][TRAINER_SIS_AND_BRO_LIA_LUC] =
    {
#line 8995
        .trainerName = _("LIA & LUC"),
#line 8996
        .trainerClass = TRAINER_CLASS_SIS_AND_BRO,
#line 8997
        .trainerPic = TRAINER_PIC_SIS_AND_BRO,
        .encounterMusic_gender =
#line 8999
            TRAINER_ENCOUNTER_MUSIC_SWIMMER,
#line 9000
        .battleType = TRAINER_BATTLE_TYPE_DOUBLES,
#line 9001
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 9003
            .species = SPECIES_GOLDEEN,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9005
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 9004
            .lvl = 30,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 9007
            .species = SPECIES_SEAKING,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9009
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 9008
            .lvl = 30,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 9011
    [DIFFICULTY_NORMAL][TRAINER_SIS_AND_BRO_LIL_IAN] =
    {
#line 9012
        .trainerName = _("LIL & IAN"),
#line 9013
        .trainerClass = TRAINER_CLASS_SIS_AND_BRO,
#line 9014
        .trainerPic = TRAINER_PIC_SIS_AND_BRO,
        .encounterMusic_gender =
#line 9016
            TRAINER_ENCOUNTER_MUSIC_SWIMMER,
#line 9017
        .battleType = TRAINER_BATTLE_TYPE_DOUBLES,
#line 9018
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 9020
            .species = SPECIES_SEADRA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9022
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 9021
            .lvl = 33,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 9024
            .species = SPECIES_STARMIE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9026
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 9025
            .lvl = 33,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 9028
    [DIFFICULTY_NORMAL][TRAINER_BUG_CATCHER_3] =
    {
#line 9029
        .trainerName = _("PH"),
#line 9030
        .trainerClass = TRAINER_CLASS_BUG_CATCHER,
#line 9031
        .trainerPic = TRAINER_PIC_BUG_CATCHER,
        .encounterMusic_gender =
#line 9033
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 9034
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 9035
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 9037
            .species = SPECIES_EKANS,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9039
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 9038
            .lvl = 5,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 9041
    [DIFFICULTY_NORMAL][TRAINER_BUG_CATCHER_4] =
    {
#line 9042
        .trainerName = _("PH"),
#line 9043
        .trainerClass = TRAINER_CLASS_BUG_CATCHER,
#line 9044
        .trainerPic = TRAINER_PIC_BUG_CATCHER,
        .encounterMusic_gender =
#line 9046
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 9047
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 9048
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 9050
            .species = SPECIES_EKANS,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9052
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 9051
            .lvl = 5,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 9054
    [DIFFICULTY_NORMAL][TRAINER_BUG_CATCHER_5] =
    {
#line 9055
        .trainerName = _("PH"),
#line 9056
        .trainerClass = TRAINER_CLASS_BUG_CATCHER,
#line 9057
        .trainerPic = TRAINER_PIC_BUG_CATCHER,
        .encounterMusic_gender =
#line 9059
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 9060
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 9061
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 9063
            .species = SPECIES_EKANS,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9065
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 9064
            .lvl = 5,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 9067
    [DIFFICULTY_NORMAL][TRAINER_BUG_CATCHER_6] =
    {
#line 9068
        .trainerName = _("PH"),
#line 9069
        .trainerClass = TRAINER_CLASS_BUG_CATCHER,
#line 9070
        .trainerPic = TRAINER_PIC_BUG_CATCHER,
        .encounterMusic_gender =
#line 9072
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 9073
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 9074
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 9076
            .species = SPECIES_EKANS,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9078
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 9077
            .lvl = 5,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 9080
    [DIFFICULTY_NORMAL][TRAINER_BUG_CATCHER_7] =
    {
#line 9081
        .trainerName = _("PH"),
#line 9082
        .trainerClass = TRAINER_CLASS_BUG_CATCHER,
#line 9083
        .trainerPic = TRAINER_PIC_BUG_CATCHER,
        .encounterMusic_gender =
#line 9085
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 9086
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 9087
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 9089
            .species = SPECIES_EKANS,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9091
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 9090
            .lvl = 5,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 9093
    [DIFFICULTY_NORMAL][TRAINER_BUG_CATCHER_8] =
    {
#line 9094
        .trainerName = _("PH"),
#line 9095
        .trainerClass = TRAINER_CLASS_BUG_CATCHER,
#line 9096
        .trainerPic = TRAINER_PIC_BUG_CATCHER,
        .encounterMusic_gender =
#line 9098
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 9099
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 9100
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 9102
            .species = SPECIES_EKANS,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9104
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 9103
            .lvl = 5,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 9106
    [DIFFICULTY_NORMAL][TRAINER_YOUNGSTER_BEN_3] =
    {
#line 9107
        .trainerName = _("BEN"),
#line 9108
        .trainerClass = TRAINER_CLASS_YOUNGSTER,
#line 9109
        .trainerPic = TRAINER_PIC_YOUNGSTER,
        .encounterMusic_gender =
#line 9111
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 9112
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 9113
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 9115
            .species = SPECIES_RATICATE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9117
            .iv = TRAINER_PARTY_IVS(7, 7, 7, 7, 7, 7),
#line 9116
            .lvl = 28,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 9119
            .species = SPECIES_EKANS,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9121
            .iv = TRAINER_PARTY_IVS(7, 7, 7, 7, 7, 7),
#line 9120
            .lvl = 28,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 9123
    [DIFFICULTY_NORMAL][TRAINER_YOUNGSTER_BEN_4] =
    {
#line 9124
        .trainerName = _("BEN"),
#line 9125
        .trainerClass = TRAINER_CLASS_YOUNGSTER,
#line 9126
        .trainerPic = TRAINER_PIC_YOUNGSTER,
        .encounterMusic_gender =
#line 9128
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 9129
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 9130
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 9132
            .species = SPECIES_RATICATE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9134
            .iv = TRAINER_PARTY_IVS(14, 14, 14, 14, 14, 14),
#line 9133
            .lvl = 48,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 9136
            .species = SPECIES_ARBOK,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9138
            .iv = TRAINER_PARTY_IVS(14, 14, 14, 14, 14, 14),
#line 9137
            .lvl = 48,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 9140
    [DIFFICULTY_NORMAL][TRAINER_YOUNGSTER_CHAD_2] =
    {
#line 9141
        .trainerName = _("CHAD"),
#line 9142
        .trainerClass = TRAINER_CLASS_YOUNGSTER,
#line 9143
        .trainerPic = TRAINER_PIC_YOUNGSTER,
        .encounterMusic_gender =
#line 9145
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 9146
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 9147
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 9149
            .species = SPECIES_EKANS,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9151
            .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
#line 9150
            .lvl = 20,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 9153
            .species = SPECIES_SANDSHREW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9155
            .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
#line 9154
            .lvl = 20,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 9157
    [DIFFICULTY_NORMAL][TRAINER_LASS_RELI_2] =
    {
#line 9158
        .trainerName = _("RELI"),
#line 9159
        .trainerClass = TRAINER_CLASS_LASS,
#line 9160
        .trainerPic = TRAINER_PIC_LASS,
        .encounterMusic_gender =
#line 9162
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
#line 9163
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 9164
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 9166
            .species = SPECIES_PIDGEY,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9168
            .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
#line 9167
            .lvl = 20,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 9170
            .species = SPECIES_NIDORAN_F,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9172
            .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
#line 9171
            .lvl = 20,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 9174
    [DIFFICULTY_NORMAL][TRAINER_LASS_RELI_3] =
    {
#line 9175
        .trainerName = _("RELI"),
#line 9176
        .trainerClass = TRAINER_CLASS_LASS,
#line 9177
        .trainerPic = TRAINER_PIC_LASS,
        .encounterMusic_gender =
#line 9179
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
#line 9180
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 9181
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 9183
            .species = SPECIES_PIDGEOTTO,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9185
            .iv = TRAINER_PARTY_IVS(7, 7, 7, 7, 7, 7),
#line 9184
            .lvl = 28,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 9187
            .species = SPECIES_NIDORINA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9189
            .iv = TRAINER_PARTY_IVS(7, 7, 7, 7, 7, 7),
#line 9188
            .lvl = 28,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 9191
    [DIFFICULTY_NORMAL][TRAINER_YOUNGSTER_TIMMY_2] =
    {
#line 9192
        .trainerName = _("TIMMY"),
#line 9193
        .trainerClass = TRAINER_CLASS_YOUNGSTER,
#line 9194
        .trainerPic = TRAINER_PIC_YOUNGSTER,
        .encounterMusic_gender =
#line 9196
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 9197
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 9198
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 9200
            .species = SPECIES_RATICATE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9202
            .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
#line 9201
            .lvl = 19,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 9204
            .species = SPECIES_EKANS,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9206
            .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
#line 9205
            .lvl = 19,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 9208
            .species = SPECIES_ZUBAT,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9210
            .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
#line 9209
            .lvl = 19,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 9212
    [DIFFICULTY_NORMAL][TRAINER_YOUNGSTER_TIMMY_3] =
    {
#line 9213
        .trainerName = _("TIMMY"),
#line 9214
        .trainerClass = TRAINER_CLASS_YOUNGSTER,
#line 9215
        .trainerPic = TRAINER_PIC_YOUNGSTER,
        .encounterMusic_gender =
#line 9217
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 9218
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 9219
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 9221
            .species = SPECIES_RATICATE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9223
            .iv = TRAINER_PARTY_IVS(7, 7, 7, 7, 7, 7),
#line 9222
            .lvl = 27,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 9225
            .species = SPECIES_EKANS,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9227
            .iv = TRAINER_PARTY_IVS(7, 7, 7, 7, 7, 7),
#line 9226
            .lvl = 27,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 9229
            .species = SPECIES_GOLBAT,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9231
            .iv = TRAINER_PARTY_IVS(7, 7, 7, 7, 7, 7),
#line 9230
            .lvl = 27,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 9233
    [DIFFICULTY_NORMAL][TRAINER_YOUNGSTER_TIMMY_4] =
    {
#line 9234
        .trainerName = _("TIMMY"),
#line 9235
        .trainerClass = TRAINER_CLASS_YOUNGSTER,
#line 9236
        .trainerPic = TRAINER_PIC_YOUNGSTER,
        .encounterMusic_gender =
#line 9238
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 9239
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 9240
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 9242
            .species = SPECIES_RATICATE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9244
            .iv = TRAINER_PARTY_IVS(14, 14, 14, 14, 14, 14),
#line 9243
            .lvl = 52,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 9246
            .species = SPECIES_ARBOK,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9248
            .iv = TRAINER_PARTY_IVS(14, 14, 14, 14, 14, 14),
#line 9247
            .lvl = 52,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 9250
            .species = SPECIES_GOLBAT,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9252
            .iv = TRAINER_PARTY_IVS(14, 14, 14, 14, 14, 14),
#line 9251
            .lvl = 52,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 9254
    [DIFFICULTY_NORMAL][TRAINER_YOUNGSTER_CHAD_3] =
    {
#line 9255
        .trainerName = _("CHAD"),
#line 9256
        .trainerClass = TRAINER_CLASS_YOUNGSTER,
#line 9257
        .trainerPic = TRAINER_PIC_YOUNGSTER,
        .encounterMusic_gender =
#line 9259
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 9260
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 9261
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 9263
            .species = SPECIES_ARBOK,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9265
            .iv = TRAINER_PARTY_IVS(7, 7, 7, 7, 7, 7),
#line 9264
            .lvl = 28,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 9267
            .species = SPECIES_SANDSHREW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9269
            .iv = TRAINER_PARTY_IVS(7, 7, 7, 7, 7, 7),
#line 9268
            .lvl = 28,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 9271
    [DIFFICULTY_NORMAL][TRAINER_LASS_JANICE_2] =
    {
#line 9272
        .trainerName = _("JANICE"),
#line 9273
        .trainerClass = TRAINER_CLASS_LASS,
#line 9274
        .trainerPic = TRAINER_PIC_LASS,
        .encounterMusic_gender =
#line 9276
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
#line 9277
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 9278
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 9280
            .species = SPECIES_PIDGEOTTO,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9282
            .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
#line 9281
            .lvl = 20,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 9284
            .species = SPECIES_PIDGEOTTO,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9286
            .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
#line 9285
            .lvl = 20,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 9288
    [DIFFICULTY_NORMAL][TRAINER_LASS_JANICE_3] =
    {
#line 9289
        .trainerName = _("JANICE"),
#line 9290
        .trainerClass = TRAINER_CLASS_LASS,
#line 9291
        .trainerPic = TRAINER_PIC_LASS,
        .encounterMusic_gender =
#line 9293
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
#line 9294
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 9295
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 9297
            .species = SPECIES_PIDGEOTTO,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9299
            .iv = TRAINER_PARTY_IVS(7, 7, 7, 7, 7, 7),
#line 9298
            .lvl = 28,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 9301
            .species = SPECIES_PIDGEOTTO,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9303
            .iv = TRAINER_PARTY_IVS(7, 7, 7, 7, 7, 7),
#line 9302
            .lvl = 28,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 9305
    [DIFFICULTY_NORMAL][TRAINER_YOUNGSTER_CHAD_4] =
    {
#line 9306
        .trainerName = _("CHAD"),
#line 9307
        .trainerClass = TRAINER_CLASS_YOUNGSTER,
#line 9308
        .trainerPic = TRAINER_PIC_YOUNGSTER,
        .encounterMusic_gender =
#line 9310
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 9311
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 9312
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 9314
            .species = SPECIES_ARBOK,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9316
            .iv = TRAINER_PARTY_IVS(9, 9, 9, 9, 9, 9),
#line 9315
            .lvl = 48,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 9318
            .species = SPECIES_SANDSLASH,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9320
            .iv = TRAINER_PARTY_IVS(9, 9, 9, 9, 9, 9),
#line 9319
            .lvl = 48,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 9322
    [DIFFICULTY_NORMAL][TRAINER_HIKER_FRANKLIN_2] =
    {
#line 9323
        .trainerName = _("FRANKLIN"),
#line 9324
        .trainerClass = TRAINER_CLASS_HIKER,
#line 9325
        .trainerPic = TRAINER_PIC_HIKER,
        .encounterMusic_gender =
#line 9327
            TRAINER_ENCOUNTER_MUSIC_HIKER,
#line 9328
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 9329
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 9331
            .species = SPECIES_MACHOKE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9333
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
#line 9332
            .lvl = 25,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 9335
            .species = SPECIES_GRAVELER,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9337
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
#line 9336
            .lvl = 25,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 9339
    [DIFFICULTY_NORMAL][TRAINER_PKMN_PROF_PROF_OAK] =
    {
#line 9340
        .trainerName = _("PROF. OAK"),
#line 9341
        .trainerClass = TRAINER_CLASS_PKMN_PROF,
#line 9342
        .trainerPic = TRAINER_PIC_PROFESSOR_OAK,
        .encounterMusic_gender =
#line 9344
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 9345
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 9346
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 9348
            .species = SPECIES_EKANS,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9350
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 9349
            .lvl = 5,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 9352
    [DIFFICULTY_NORMAL][TRAINER_PLAYER_BRENDAN] =
    {
#line 9353
        .trainerName = _("BRENDAN"),
#line 9354
        .trainerClass = TRAINER_CLASS_PLAYER,
#line 9355
        .trainerPic = TRAINER_PIC_RS_BRENDAN_2,
        .encounterMusic_gender =
#line 9357
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 9358
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 9359
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 9361
            .species = SPECIES_EKANS,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9363
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 9362
            .lvl = 5,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 9365
    [DIFFICULTY_NORMAL][TRAINER_PLAYER_MAY] =
    {
#line 9366
        .trainerName = _("MAY"),
#line 9367
        .trainerClass = TRAINER_CLASS_PLAYER,
#line 9368
        .trainerPic = TRAINER_PIC_RS_MAY_2,
        .encounterMusic_gender =
#line 9370
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
#line 9371
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 9372
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 9374
            .species = SPECIES_EKANS,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9376
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 9375
            .lvl = 5,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 9378
    [DIFFICULTY_NORMAL][TRAINER_PLAYER_RED] =
    {
#line 9379
        .trainerName = _("RED"),
#line 9380
        .trainerClass = TRAINER_CLASS_PLAYER,
#line 9381
        .trainerPic = TRAINER_PIC_RED,
        .encounterMusic_gender =
#line 9383
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 9384
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 9385
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 9387
            .species = SPECIES_EKANS,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9389
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 9388
            .lvl = 5,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 9391
    [DIFFICULTY_NORMAL][TRAINER_PLAYER_LEAF] =
    {
#line 9392
        .trainerName = _("LEAF"),
#line 9393
        .trainerClass = TRAINER_CLASS_PLAYER,
#line 9394
        .trainerPic = TRAINER_PIC_LEAF,
        .encounterMusic_gender =
#line 9396
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
#line 9397
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 9398
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 9400
            .species = SPECIES_EKANS,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9402
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 9401
            .lvl = 5,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 9404
    [DIFFICULTY_NORMAL][TRAINER_TEAM_ROCKET_GRUNT_42] =
    {
#line 9405
        .trainerName = _("GRUNT"),
#line 9406
        .trainerClass = TRAINER_CLASS_TEAM_ROCKET,
#line 9407
        .trainerPic = TRAINER_PIC_ROCKET_GRUNT_F,
        .encounterMusic_gender =
#line 9409
            TRAINER_ENCOUNTER_MUSIC_AQUA,
#line 9410
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 9411
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 9413
            .species = SPECIES_HOUNDOUR,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9415
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 9414
            .lvl = 49,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 9417
            .species = SPECIES_HOUNDOUR,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9419
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 9418
            .lvl = 49,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 9421
    [DIFFICULTY_NORMAL][TRAINER_PSYCHIC_JACLYN] =
    {
#line 9422
        .trainerName = _("JACLYN"),
#line 9423
        .trainerClass = TRAINER_CLASS_PSYCHIC,
#line 9424
        .trainerPic = TRAINER_PIC_PSYCHIC_F,
        .encounterMusic_gender =
#line 9426
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
#line 9427
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 9428
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 9430
            .species = SPECIES_NATU,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9432
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 9431
            .lvl = 48,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 9433
                MOVE_NIGHT_SHADE,
                MOVE_CONFUSE_RAY,
                MOVE_FUTURE_SIGHT,
                MOVE_WISH,
            },
            },
            {
#line 9438
            .species = SPECIES_SLOWBRO,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9440
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 9439
            .lvl = 48,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 9441
                MOVE_PSYCHIC,
                MOVE_HEADBUTT,
                MOVE_AMNESIA,
                MOVE_YAWN,
            },
            },
            {
#line 9446
            .species = SPECIES_KADABRA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9448
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 9447
            .lvl = 49,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 9449
                MOVE_PSYCHIC,
                MOVE_FUTURE_SIGHT,
                MOVE_RECOVER,
                MOVE_REFLECT,
            },
            },
        },
    },
#line 9454
    [DIFFICULTY_NORMAL][TRAINER_CRUSH_GIRL_SHARON] =
    {
#line 9455
        .trainerName = _("SHARON"),
#line 9456
        .trainerClass = TRAINER_CLASS_CRUSH_GIRL,
#line 9457
        .trainerPic = TRAINER_PIC_CRUSH_GIRL,
        .encounterMusic_gender =
#line 9459
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
#line 9460
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 9461
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 9463
            .species = SPECIES_MANKEY,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9463
            .heldItem = ITEM_BLACK_BELT,
#line 9465
            .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
#line 9464
            .lvl = 37,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 9467
            .species = SPECIES_PRIMEAPE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9467
            .heldItem = ITEM_BLACK_BELT,
#line 9469
            .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
#line 9468
            .lvl = 37,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 9471
    [DIFFICULTY_NORMAL][TRAINER_TUBER_AMIRA] =
    {
#line 9472
        .trainerName = _("AMIRA"),
#line 9473
        .trainerClass = TRAINER_CLASS_TUBER,
#line 9474
        .trainerPic = TRAINER_PIC_TUBER_F,
        .encounterMusic_gender =
#line 9476
            TRAINER_ENCOUNTER_MUSIC_GIRL,
#line 9477
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 9478
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 9480
            .species = SPECIES_POLIWAG,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9482
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 9481
            .lvl = 34,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 9484
            .species = SPECIES_POLIWHIRL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9486
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 9485
            .lvl = 35,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 9488
            .species = SPECIES_POLIWAG,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9490
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 9489
            .lvl = 34,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 9492
    [DIFFICULTY_NORMAL][TRAINER_PKMN_BREEDER_ALIZE] =
    {
#line 9493
        .trainerName = _("ALIZE"),
#line 9494
        .trainerClass = TRAINER_CLASS_PKMN_BREEDER,
#line 9495
        .trainerPic = TRAINER_PIC_POKEMON_BREEDER,
        .encounterMusic_gender =
#line 9497
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
#line 9498
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 9499
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 9501
            .species = SPECIES_PIKACHU,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9503
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
#line 9502
            .lvl = 48,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 9505
            .species = SPECIES_CLEFAIRY,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9507
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
#line 9506
            .lvl = 48,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 9509
            .species = SPECIES_MARILL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9511
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
#line 9510
            .lvl = 48,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 9513
    [DIFFICULTY_NORMAL][TRAINER_PKMN_RANGER_NICOLAS] =
    {
#line 9514
        .trainerName = _("NICOLAS"),
#line 9515
        .trainerClass = TRAINER_CLASS_PKMN_RANGER,
#line 9516
        .trainerPic = TRAINER_PIC_POKEMON_RANGER_M,
        .encounterMusic_gender =
#line 9518
            TRAINER_ENCOUNTER_MUSIC_COOL,
#line 9519
        .items = { ITEM_FULL_RESTORE },
#line 9520
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 9521
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 9523
            .species = SPECIES_WEEPINBELL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9525
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 9524
            .lvl = 51,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 9526
                MOVE_RAZOR_LEAF,
                MOVE_ACID,
                MOVE_SWEET_SCENT,
                MOVE_WRAP,
            },
            },
            {
#line 9531
            .species = SPECIES_VICTREEBEL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9533
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 9532
            .lvl = 51,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 9534
                MOVE_RAZOR_LEAF,
                MOVE_ACID,
                MOVE_SLEEP_POWDER,
                MOVE_STUN_SPORE,
            },
            },
        },
    },
#line 9539
    [DIFFICULTY_NORMAL][TRAINER_PKMN_RANGER_MADELINE] =
    {
#line 9540
        .trainerName = _("MADELINE"),
#line 9541
        .trainerClass = TRAINER_CLASS_PKMN_RANGER,
#line 9542
        .trainerPic = TRAINER_PIC_POKEMON_RANGER_F,
        .encounterMusic_gender =
#line 9544
            TRAINER_ENCOUNTER_MUSIC_COOL,
#line 9545
        .items = { ITEM_FULL_RESTORE },
#line 9546
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 9547
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 9549
            .species = SPECIES_GLOOM,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9551
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 9550
            .lvl = 51,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 9552
                MOVE_PETAL_DANCE,
                MOVE_ACID,
                MOVE_SWEET_SCENT,
                MOVE_POISON_POWDER,
            },
            },
            {
#line 9557
            .species = SPECIES_VILEPLUME,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9559
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 9558
            .lvl = 51,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 9560
                MOVE_PETAL_DANCE,
                MOVE_MOONLIGHT,
                MOVE_ACID,
                MOVE_STUN_SPORE,
            },
            },
        },
    },
#line 9565
    [DIFFICULTY_NORMAL][TRAINER_AROMA_LADY_NIKKI] =
    {
#line 9566
        .trainerName = _("NIKKI"),
#line 9567
        .trainerClass = TRAINER_CLASS_AROMA_LADY,
#line 9568
        .trainerPic = TRAINER_PIC_AROMA_LADY,
        .encounterMusic_gender =
#line 9570
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
#line 9571
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 9572
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 9574
            .species = SPECIES_BELLSPROUT,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9576
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 9575
            .lvl = 37,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 9578
            .species = SPECIES_WEEPINBELL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9580
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 9579
            .lvl = 37,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 9582
    [DIFFICULTY_NORMAL][TRAINER_RUIN_MANIAC_STANLY] =
    {
#line 9583
        .trainerName = _("STANLY"),
#line 9584
        .trainerClass = TRAINER_CLASS_RUIN_MANIAC,
#line 9585
        .trainerPic = TRAINER_PIC_RUIN_MANIAC,
        .encounterMusic_gender =
#line 9587
            TRAINER_ENCOUNTER_MUSIC_HIKER,
#line 9588
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 9589
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 9591
            .species = SPECIES_GRAVELER,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9593
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 9592
            .lvl = 48,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 9595
            .species = SPECIES_ONIX,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9597
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 9596
            .lvl = 48,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 9599
            .species = SPECIES_GRAVELER,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9601
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 9600
            .lvl = 48,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 9603
    [DIFFICULTY_NORMAL][TRAINER_LADY_JACKI] =
    {
#line 9604
        .trainerName = _("JACKI"),
#line 9605
        .trainerClass = TRAINER_CLASS_LADY,
#line 9606
        .trainerPic = TRAINER_PIC_LADY,
        .encounterMusic_gender =
#line 9608
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
#line 9609
        .items = { ITEM_FULL_RESTORE },
#line 9610
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 9611
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 9613
            .species = SPECIES_HOPPIP,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9613
            .heldItem = ITEM_STARDUST,
#line 9615
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 9614
            .lvl = 48,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 9617
            .species = SPECIES_SKIPLOOM,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9617
            .heldItem = ITEM_STARDUST,
#line 9619
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 9618
            .lvl = 50,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 9621
    [DIFFICULTY_NORMAL][TRAINER_PAINTER_DAISY] =
    {
#line 9622
        .trainerName = _("DAISY"),
#line 9623
        .trainerClass = TRAINER_CLASS_PAINTER,
#line 9624
        .trainerPic = TRAINER_PIC_PAINTER,
        .encounterMusic_gender =
#line 9626
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
#line 9627
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 9628
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 9630
            .species = SPECIES_SMEARGLE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9632
            .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
#line 9631
            .lvl = 50,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 9633
                MOVE_DYNAMIC_PUNCH,
                MOVE_DIZZY_PUNCH,
                MOVE_FOCUS_PUNCH,
                MOVE_MEGA_PUNCH,
            },
            },
        },
    },
#line 9638
    [DIFFICULTY_NORMAL][TRAINER_BIKER_GOON] =
    {
#line 9639
        .trainerName = _("GOON"),
#line 9640
        .trainerClass = TRAINER_CLASS_BIKER,
#line 9641
        .trainerPic = TRAINER_PIC_BIKER,
        .encounterMusic_gender =
#line 9643
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 9644
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 9645
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 9647
            .species = SPECIES_KOFFING,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9649
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 9648
            .lvl = 37,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 9650
                MOVE_HAZE,
                MOVE_SMOKESCREEN,
                MOVE_SLUDGE,
                MOVE_TACKLE,
            },
            },
            {
#line 9655
            .species = SPECIES_GRIMER,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9657
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 9656
            .lvl = 37,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 9658
                MOVE_ACID_ARMOR,
                MOVE_SCREECH,
                MOVE_MINIMIZE,
                MOVE_SLUDGE,
            },
            },
        },
    },
#line 9663
    [DIFFICULTY_NORMAL][TRAINER_BIKER_GOON_2] =
    {
#line 9664
        .trainerName = _("GOON"),
#line 9665
        .trainerClass = TRAINER_CLASS_BIKER,
#line 9666
        .trainerPic = TRAINER_PIC_BIKER,
        .encounterMusic_gender =
#line 9668
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 9669
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 9670
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 9672
            .species = SPECIES_KOFFING,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9674
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 9673
            .lvl = 38,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 9675
                MOVE_HAZE,
                MOVE_SMOKESCREEN,
                MOVE_SLUDGE,
                MOVE_TACKLE,
            },
            },
        },
    },
#line 9680
    [DIFFICULTY_NORMAL][TRAINER_BIKER_GOON_3] =
    {
#line 9681
        .trainerName = _("GOON"),
#line 9682
        .trainerClass = TRAINER_CLASS_BIKER,
#line 9683
        .trainerPic = TRAINER_PIC_BIKER,
        .encounterMusic_gender =
#line 9685
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 9686
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 9687
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 9689
            .species = SPECIES_GRIMER,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9691
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 9690
            .lvl = 38,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 9693
    [DIFFICULTY_NORMAL][TRAINER_BIKER_2] =
    {
#line 9694
        .trainerName = _("PH"),
#line 9695
        .trainerClass = TRAINER_CLASS_BIKER,
#line 9696
        .trainerPic = TRAINER_PIC_BIKER,
        .encounterMusic_gender =
#line 9698
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 9699
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 9700
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 9702
            .species = SPECIES_EKANS,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9704
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 9703
            .lvl = 5,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 9706
    [DIFFICULTY_NORMAL][TRAINER_BUG_CATCHER_ANTHONY] =
    {
#line 9707
        .trainerName = _("ANTHONY"),
#line 9708
        .trainerClass = TRAINER_CLASS_BUG_CATCHER,
#line 9709
        .trainerPic = TRAINER_PIC_BUG_CATCHER,
        .encounterMusic_gender =
#line 9711
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 9712
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 9713
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 9715
            .species = SPECIES_CATERPIE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9717
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 9716
            .lvl = 7,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 9719
            .species = SPECIES_CATERPIE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9721
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 9720
            .lvl = 8,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 9723
    [DIFFICULTY_NORMAL][TRAINER_BUG_CATCHER_CHARLIE] =
    {
#line 9724
        .trainerName = _("CHARLIE"),
#line 9725
        .trainerClass = TRAINER_CLASS_BUG_CATCHER,
#line 9726
        .trainerPic = TRAINER_PIC_BUG_CATCHER,
        .encounterMusic_gender =
#line 9728
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 9729
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 9730
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 9732
            .species = SPECIES_METAPOD,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9734
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 9733
            .lvl = 7,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 9736
            .species = SPECIES_CATERPIE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9738
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 9737
            .lvl = 7,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 9740
            .species = SPECIES_METAPOD,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9742
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 9741
            .lvl = 7,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 9744
    [DIFFICULTY_NORMAL][TRAINER_TWINS_ELI_ANNE_2] =
    {
#line 9745
        .trainerName = _("ELI & ANNE"),
#line 9746
        .trainerClass = TRAINER_CLASS_TWINS,
#line 9747
        .trainerPic = TRAINER_PIC_TWINS,
        .encounterMusic_gender =
#line 9749
            TRAINER_ENCOUNTER_MUSIC_TWINS,
#line 9750
        .battleType = TRAINER_BATTLE_TYPE_DOUBLES,
#line 9751
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 9753
            .species = SPECIES_CLEFAIRY,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9755
            .iv = TRAINER_PARTY_IVS(7, 7, 7, 7, 7, 7),
#line 9754
            .lvl = 28,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 9757
            .species = SPECIES_JIGGLYPUFF,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9759
            .iv = TRAINER_PARTY_IVS(7, 7, 7, 7, 7, 7),
#line 9758
            .lvl = 28,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 9761
    [DIFFICULTY_NORMAL][TRAINER_YOUNGSTER_JOHNSON] =
    {
#line 9762
        .trainerName = _("JOHNSON"),
#line 9763
        .trainerClass = TRAINER_CLASS_YOUNGSTER,
#line 9764
        .trainerPic = TRAINER_PIC_YOUNGSTER,
        .encounterMusic_gender =
#line 9766
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 9767
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 9768
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 9770
            .species = SPECIES_EKANS,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9772
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 9771
            .lvl = 33,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 9774
            .species = SPECIES_EKANS,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9776
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 9775
            .lvl = 33,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 9778
            .species = SPECIES_RATICATE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9780
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 9779
            .lvl = 34,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 9782
    [DIFFICULTY_NORMAL][TRAINER_BIKER_RICARDO] =
    {
#line 9783
        .trainerName = _("RICARDO"),
#line 9784
        .trainerClass = TRAINER_CLASS_BIKER,
#line 9785
        .trainerPic = TRAINER_PIC_BIKER,
        .encounterMusic_gender =
#line 9787
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 9788
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 9789
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 9791
            .species = SPECIES_KOFFING,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9793
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 9792
            .lvl = 22,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 9794
                MOVE_SLUDGE,
                MOVE_SMOG,
                MOVE_TACKLE,
                MOVE_POISON_GAS,
            },
            },
            {
#line 9799
            .species = SPECIES_KOFFING,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9801
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 9800
            .lvl = 22,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 9802
                MOVE_SLUDGE,
                MOVE_SMOG,
                MOVE_TACKLE,
                MOVE_POISON_GAS,
            },
            },
            {
#line 9807
            .species = SPECIES_GRIMER,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9809
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 9808
            .lvl = 23,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 9810
                MOVE_MINIMIZE,
                MOVE_SLUDGE,
                MOVE_DISABLE,
                MOVE_POUND,
            },
            },
        },
    },
#line 9815
    [DIFFICULTY_NORMAL][TRAINER_BIKER_JAREN] =
    {
#line 9816
        .trainerName = _("JAREN"),
#line 9817
        .trainerClass = TRAINER_CLASS_BIKER,
#line 9818
        .trainerPic = TRAINER_PIC_BIKER,
        .encounterMusic_gender =
#line 9820
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 9821
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 9822
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 9824
            .species = SPECIES_GRIMER,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9826
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 9825
            .lvl = 24,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 9828
            .species = SPECIES_GRIMER,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9830
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 9829
            .lvl = 24,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 9832
    [DIFFICULTY_NORMAL][TRAINER_TEAM_ROCKET_GRUNT_43] =
    {
#line 9833
        .trainerName = _("GRUNT"),
#line 9834
        .trainerClass = TRAINER_CLASS_TEAM_ROCKET,
#line 9835
        .trainerPic = TRAINER_PIC_ROCKET_GRUNT_M,
        .encounterMusic_gender =
#line 9837
            TRAINER_ENCOUNTER_MUSIC_AQUA,
#line 9838
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 9839
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 9841
            .species = SPECIES_CUBONE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9843
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 9842
            .lvl = 37,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 9845
            .species = SPECIES_MAROWAK,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9847
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 9846
            .lvl = 37,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 9849
    [DIFFICULTY_NORMAL][TRAINER_TEAM_ROCKET_GRUNT_44] =
    {
#line 9850
        .trainerName = _("GRUNT"),
#line 9851
        .trainerClass = TRAINER_CLASS_TEAM_ROCKET,
#line 9852
        .trainerPic = TRAINER_PIC_ROCKET_GRUNT_M,
        .encounterMusic_gender =
#line 9854
            TRAINER_ENCOUNTER_MUSIC_AQUA,
#line 9855
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 9856
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 4,
        .party = (const struct TrainerMon[])
        {
            {
#line 9858
            .species = SPECIES_RATTATA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9860
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 9859
            .lvl = 35,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 9862
            .species = SPECIES_RATICATE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9864
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 9863
            .lvl = 35,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 9866
            .species = SPECIES_SANDSHREW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9868
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 9867
            .lvl = 35,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 9870
            .species = SPECIES_SANDSLASH,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9872
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 9871
            .lvl = 35,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 9874
    [DIFFICULTY_NORMAL][TRAINER_TEAM_ROCKET_GRUNT_45] =
    {
#line 9875
        .trainerName = _("GRUNT"),
#line 9876
        .trainerClass = TRAINER_CLASS_TEAM_ROCKET,
#line 9877
        .trainerPic = TRAINER_PIC_ROCKET_GRUNT_M,
        .encounterMusic_gender =
#line 9879
            TRAINER_ENCOUNTER_MUSIC_AQUA,
#line 9880
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 9881
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 9883
            .species = SPECIES_ZUBAT,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9885
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 9884
            .lvl = 38,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 9887
            .species = SPECIES_ZUBAT,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9889
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 9888
            .lvl = 38,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 9891
            .species = SPECIES_GOLBAT,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9893
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 9892
            .lvl = 38,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 9895
    [DIFFICULTY_NORMAL][TRAINER_TEAM_ROCKET_GRUNT_46] =
    {
#line 9896
        .trainerName = _("GRUNT"),
#line 9897
        .trainerClass = TRAINER_CLASS_TEAM_ROCKET,
#line 9898
        .trainerPic = TRAINER_PIC_ROCKET_GRUNT_M,
        .encounterMusic_gender =
#line 9900
            TRAINER_ENCOUNTER_MUSIC_AQUA,
#line 9901
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 9902
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 9904
            .species = SPECIES_MUK,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9906
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 9905
            .lvl = 48,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 9908
            .species = SPECIES_GOLBAT,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9910
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 9909
            .lvl = 48,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 9912
            .species = SPECIES_RATICATE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9914
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 9913
            .lvl = 48,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 9916
    [DIFFICULTY_NORMAL][TRAINER_TEAM_ROCKET_GRUNT_47] =
    {
#line 9917
        .trainerName = _("GRUNT"),
#line 9918
        .trainerClass = TRAINER_CLASS_TEAM_ROCKET,
#line 9919
        .trainerPic = TRAINER_PIC_ROCKET_GRUNT_M,
        .encounterMusic_gender =
#line 9921
            TRAINER_ENCOUNTER_MUSIC_AQUA,
#line 9922
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 9923
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 9925
            .species = SPECIES_MACHOP,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9927
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 9926
            .lvl = 48,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 9929
            .species = SPECIES_MACHOP,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9931
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 9930
            .lvl = 48,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 9933
            .species = SPECIES_MACHOKE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9935
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 9934
            .lvl = 48,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 9937
    [DIFFICULTY_NORMAL][TRAINER_TEAM_ROCKET_GRUNT_48] =
    {
#line 9938
        .trainerName = _("GRUNT"),
#line 9939
        .trainerClass = TRAINER_CLASS_TEAM_ROCKET,
#line 9940
        .trainerPic = TRAINER_PIC_ROCKET_GRUNT_M,
        .encounterMusic_gender =
#line 9942
            TRAINER_ENCOUNTER_MUSIC_AQUA,
#line 9943
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 9944
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 9946
            .species = SPECIES_HYPNO,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9948
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 9947
            .lvl = 49,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 9950
            .species = SPECIES_HYPNO,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9952
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 9951
            .lvl = 49,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 9954
    [DIFFICULTY_NORMAL][TRAINER_TEAM_ROCKET_ADMIN] =
    {
#line 9955
        .trainerName = _("ADMIN"),
#line 9956
        .trainerClass = TRAINER_CLASS_TEAM_ROCKET,
#line 9957
        .trainerPic = TRAINER_PIC_ROCKET_GRUNT_F,
        .encounterMusic_gender =
#line 9959
            TRAINER_ENCOUNTER_MUSIC_AQUA,
#line 9960
        .items = { ITEM_HYPER_POTION },
#line 9961
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 9962
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 9964
            .species = SPECIES_MUK,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9966
            .iv = TRAINER_PARTY_IVS(18, 18, 18, 18, 18, 18),
#line 9965
            .lvl = 52,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 9967
                MOVE_SLUDGE_BOMB,
                MOVE_SCREECH,
                MOVE_MINIMIZE,
                MOVE_ROCK_TOMB,
            },
            },
            {
#line 9972
            .species = SPECIES_ARBOK,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9974
            .iv = TRAINER_PARTY_IVS(18, 18, 18, 18, 18, 18),
#line 9973
            .lvl = 53,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 9975
                MOVE_SLUDGE_BOMB,
                MOVE_BITE,
                MOVE_EARTHQUAKE,
                MOVE_IRON_TAIL,
            },
            },
            {
#line 9980
            .species = SPECIES_VILEPLUME,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9982
            .iv = TRAINER_PARTY_IVS(18, 18, 18, 18, 18, 18),
#line 9981
            .lvl = 54,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 9983
                MOVE_SLUDGE_BOMB,
                MOVE_GIGA_DRAIN,
                MOVE_SLEEP_POWDER,
                MOVE_STUN_SPORE,
            },
            },
        },
    },
#line 9988
    [DIFFICULTY_NORMAL][TRAINER_TEAM_ROCKET_ADMIN_2] =
    {
#line 9989
        .trainerName = _("ADMIN"),
#line 9990
        .trainerClass = TRAINER_CLASS_TEAM_ROCKET,
#line 9991
        .trainerPic = TRAINER_PIC_ROCKET_GRUNT_M,
        .encounterMusic_gender =
#line 9993
            TRAINER_ENCOUNTER_MUSIC_AQUA,
#line 9994
        .items = { ITEM_HYPER_POTION },
#line 9995
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 9996
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 9998
            .species = SPECIES_GOLBAT,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10000
            .iv = TRAINER_PARTY_IVS(24, 24, 24, 24, 24, 24),
#line 9999
            .lvl = 53,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 10001
                MOVE_CONFUSE_RAY,
                MOVE_SLUDGE_BOMB,
                MOVE_AIR_CUTTER,
                MOVE_SHADOW_BALL,
            },
            },
            {
#line 10006
            .species = SPECIES_WEEZING,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10008
            .iv = TRAINER_PARTY_IVS(24, 24, 24, 24, 24, 24),
#line 10007
            .lvl = 54,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 10009
                MOVE_SLUDGE_BOMB,
                MOVE_THUNDERBOLT,
                MOVE_EXPLOSION,
                MOVE_SHADOW_BALL,
            },
            },
            {
#line 10014
            .species = SPECIES_HOUNDOOM,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10016
            .iv = TRAINER_PARTY_IVS(24, 24, 24, 24, 24, 24),
#line 10015
            .lvl = 55,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 10017
                MOVE_FLAMETHROWER,
                MOVE_CRUNCH,
                MOVE_IRON_TAIL,
                MOVE_SHADOW_BALL,
            },
            },
        },
    },
#line 10022
    [DIFFICULTY_NORMAL][TRAINER_SCIENTIST_GIDEON] =
    {
#line 10023
        .trainerName = _("GIDEON"),
#line 10024
        .trainerClass = TRAINER_CLASS_SCIENTIST,
#line 10025
        .trainerPic = TRAINER_PIC_SCIENTIST,
        .encounterMusic_gender =
#line 10027
            TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
#line 10028
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 10029
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 5,
        .party = (const struct TrainerMon[])
        {
            {
#line 10031
            .species = SPECIES_VOLTORB,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10033
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 10032
            .lvl = 46,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 10034
                MOVE_SWIFT,
                MOVE_SCREECH,
                MOVE_SPARK,
                MOVE_SONIC_BOOM,
            },
            },
            {
#line 10039
            .species = SPECIES_ELECTRODE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10041
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 10040
            .lvl = 46,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 10042
                MOVE_SPARK,
                MOVE_SONIC_BOOM,
                MOVE_SCREECH,
                MOVE_CHARGE,
            },
            },
            {
#line 10047
            .species = SPECIES_MAGNEMITE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10049
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 10048
            .lvl = 46,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 10050
                MOVE_SCREECH,
                MOVE_SWIFT,
                MOVE_SPARK,
                MOVE_THUNDER_WAVE,
            },
            },
            {
#line 10055
            .species = SPECIES_MAGNETON,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10057
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 10056
            .lvl = 46,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 10058
                MOVE_TRI_ATTACK,
                MOVE_SPARK,
                MOVE_THUNDER_WAVE,
                MOVE_SONIC_BOOM,
            },
            },
            {
#line 10063
            .species = SPECIES_PORYGON,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10065
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 10064
            .lvl = 46,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 10066
                MOVE_TRI_ATTACK,
                MOVE_CONVERSION,
                MOVE_RECOVER,
                MOVE_PSYBEAM,
            },
            },
        },
    },
#line 10071
    [DIFFICULTY_NORMAL][TRAINER_SWIMMER_FEMALE_AMARA] =
    {
#line 10072
        .trainerName = _("AMARA"),
#line 10073
        .trainerClass = TRAINER_CLASS_SWIMMER_F,
#line 10074
        .trainerPic = TRAINER_PIC_SWIMMER_F,
        .encounterMusic_gender =
#line 10076
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
#line 10077
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 10078
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 10080
            .species = SPECIES_SEEL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10082
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 10081
            .lvl = 36,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 10084
            .species = SPECIES_SEEL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10086
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 10085
            .lvl = 36,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 10088
            .species = SPECIES_DEWGONG,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10090
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 10089
            .lvl = 36,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 10092
    [DIFFICULTY_NORMAL][TRAINER_SWIMMER_FEMALE_MARIA] =
    {
#line 10093
        .trainerName = _("MARIA"),
#line 10094
        .trainerClass = TRAINER_CLASS_SWIMMER_F,
#line 10095
        .trainerPic = TRAINER_PIC_SWIMMER_F,
        .encounterMusic_gender =
#line 10097
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
#line 10098
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 10099
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 10101
            .species = SPECIES_SEADRA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10103
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 10102
            .lvl = 37,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 10105
            .species = SPECIES_SEADRA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10107
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 10106
            .lvl = 37,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 10109
    [DIFFICULTY_NORMAL][TRAINER_SWIMMER_FEMALE_ABIGAIL] =
    {
#line 10110
        .trainerName = _("ABIGAIL"),
#line 10111
        .trainerClass = TRAINER_CLASS_SWIMMER_F,
#line 10112
        .trainerPic = TRAINER_PIC_SWIMMER_F,
        .encounterMusic_gender =
#line 10114
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
#line 10115
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 10116
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 10118
            .species = SPECIES_PSYDUCK,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10120
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 10119
            .lvl = 35,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 10122
            .species = SPECIES_PSYDUCK,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10124
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 10123
            .lvl = 36,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 10126
            .species = SPECIES_GOLDUCK,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10128
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 10127
            .lvl = 37,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 10130
    [DIFFICULTY_NORMAL][TRAINER_SWIMMER_MALE_FINN] =
    {
#line 10131
        .trainerName = _("FINN"),
#line 10132
        .trainerClass = TRAINER_CLASS_SWIMMER_M,
#line 10133
        .trainerPic = TRAINER_PIC_SWIMMER_M,
        .encounterMusic_gender =
#line 10135
            TRAINER_ENCOUNTER_MUSIC_SWIMMER,
#line 10136
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 10137
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 10139
            .species = SPECIES_STARMIE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10141
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 10140
            .lvl = 38,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 10143
    [DIFFICULTY_NORMAL][TRAINER_SWIMMER_MALE_GARRETT] =
    {
#line 10144
        .trainerName = _("GARRETT"),
#line 10145
        .trainerClass = TRAINER_CLASS_SWIMMER_M,
#line 10146
        .trainerPic = TRAINER_PIC_SWIMMER_M,
        .encounterMusic_gender =
#line 10148
            TRAINER_ENCOUNTER_MUSIC_SWIMMER,
#line 10149
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 10150
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 10152
            .species = SPECIES_SHELLDER,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10154
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 10153
            .lvl = 35,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 10156
            .species = SPECIES_CLOYSTER,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10158
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 10157
            .lvl = 35,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 10160
            .species = SPECIES_WARTORTLE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10162
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 10161
            .lvl = 38,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 10164
    [DIFFICULTY_NORMAL][TRAINER_FISHERMAN_TOMMY] =
    {
#line 10165
        .trainerName = _("TOMMY"),
#line 10166
        .trainerClass = TRAINER_CLASS_FISHERMAN,
#line 10167
        .trainerPic = TRAINER_PIC_FISHERMAN,
        .encounterMusic_gender =
#line 10169
            TRAINER_ENCOUNTER_MUSIC_HIKER,
#line 10170
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 10171
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 5,
        .party = (const struct TrainerMon[])
        {
            {
#line 10173
            .species = SPECIES_GOLDEEN,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10175
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 10174
            .lvl = 33,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 10177
            .species = SPECIES_GOLDEEN,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10179
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 10178
            .lvl = 33,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 10181
            .species = SPECIES_SEAKING,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10183
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 10182
            .lvl = 35,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 10185
            .species = SPECIES_SEAKING,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10187
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 10186
            .lvl = 35,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 10189
            .species = SPECIES_SEAKING,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10191
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 10190
            .lvl = 35,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 10193
    [DIFFICULTY_NORMAL][TRAINER_CRUSH_GIRL_TANYA] =
    {
#line 10194
        .trainerName = _("TANYA"),
#line 10195
        .trainerClass = TRAINER_CLASS_CRUSH_GIRL,
#line 10196
        .trainerPic = TRAINER_PIC_CRUSH_GIRL,
        .encounterMusic_gender =
#line 10198
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
#line 10199
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 10200
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 10202
            .species = SPECIES_HITMONLEE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10202
            .heldItem = ITEM_BLACK_BELT,
#line 10204
            .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
#line 10203
            .lvl = 38,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 10206
            .species = SPECIES_HITMONCHAN,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10206
            .heldItem = ITEM_BLACK_BELT,
#line 10208
            .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
#line 10207
            .lvl = 38,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 10210
    [DIFFICULTY_NORMAL][TRAINER_BLACK_BELT_SHEA] =
    {
#line 10211
        .trainerName = _("SHEA"),
#line 10212
        .trainerClass = TRAINER_CLASS_BLACK_BELT,
#line 10213
        .trainerPic = TRAINER_PIC_BLACK_BELT,
        .encounterMusic_gender =
#line 10215
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
#line 10216
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 10217
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 10219
            .species = SPECIES_MACHOP,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10219
            .heldItem = ITEM_BLACK_BELT,
#line 10221
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 10220
            .lvl = 38,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 10223
            .species = SPECIES_MACHOKE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10223
            .heldItem = ITEM_BLACK_BELT,
#line 10225
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 10224
            .lvl = 38,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 10227
    [DIFFICULTY_NORMAL][TRAINER_BLACK_BELT_HUGH] =
    {
#line 10228
        .trainerName = _("HUGH"),
#line 10229
        .trainerClass = TRAINER_CLASS_BLACK_BELT,
#line 10230
        .trainerPic = TRAINER_PIC_BLACK_BELT,
        .encounterMusic_gender =
#line 10232
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
#line 10233
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 10234
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 10236
            .species = SPECIES_MACHOP,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10236
            .heldItem = ITEM_BLACK_BELT,
#line 10238
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 10237
            .lvl = 37,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 10240
            .species = SPECIES_MACHOKE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10240
            .heldItem = ITEM_BLACK_BELT,
#line 10242
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 10241
            .lvl = 37,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 10244
    [DIFFICULTY_NORMAL][TRAINER_CAMPER_BRYCE] =
    {
#line 10245
        .trainerName = _("BRYCE"),
#line 10246
        .trainerClass = TRAINER_CLASS_CAMPER,
#line 10247
        .trainerPic = TRAINER_PIC_CAMPER,
        .encounterMusic_gender =
#line 10249
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 10250
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 10251
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 10253
            .species = SPECIES_NIDORINO,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10255
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 10254
            .lvl = 36,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 10257
            .species = SPECIES_RATICATE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10259
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 10258
            .lvl = 36,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 10261
            .species = SPECIES_SANDSLASH,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10263
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 10262
            .lvl = 36,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 10265
    [DIFFICULTY_NORMAL][TRAINER_PICNICKER_CLAIRE] =
    {
#line 10266
        .trainerName = _("CLAIRE"),
#line 10267
        .trainerClass = TRAINER_CLASS_PICNICKER,
#line 10268
        .trainerPic = TRAINER_PIC_PICNICKER,
        .encounterMusic_gender =
#line 10270
            TRAINER_ENCOUNTER_MUSIC_GIRL,
#line 10271
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 10272
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 4,
        .party = (const struct TrainerMon[])
        {
            {
#line 10274
            .species = SPECIES_MEOWTH,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10276
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 10275
            .lvl = 35,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 10278
            .species = SPECIES_MEOWTH,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10280
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 10279
            .lvl = 35,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 10282
            .species = SPECIES_PIKACHU,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10284
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 10283
            .lvl = 35,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 10286
            .species = SPECIES_CLEFAIRY,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10288
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 10287
            .lvl = 35,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 10290
    [DIFFICULTY_NORMAL][TRAINER_CRUSH_KIN_MIK_KIA] =
    {
#line 10291
        .trainerName = _("MIK & KIA"),
#line 10292
        .trainerClass = TRAINER_CLASS_CRUSH_KIN,
#line 10293
        .trainerPic = TRAINER_PIC_CRUSH_KIN,
        .encounterMusic_gender =
#line 10295
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
#line 10296
        .battleType = TRAINER_BATTLE_TYPE_DOUBLES,
#line 10297
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 10299
            .species = SPECIES_MACHOKE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10299
            .heldItem = ITEM_BLACK_BELT,
#line 10301
            .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
#line 10300
            .lvl = 39,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 10303
            .species = SPECIES_PRIMEAPE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10303
            .heldItem = ITEM_BLACK_BELT,
#line 10305
            .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
#line 10304
            .lvl = 39,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 10307
    [DIFFICULTY_NORMAL][TRAINER_AROMA_LADY_VIOLET] =
    {
#line 10308
        .trainerName = _("VIOLET"),
#line 10309
        .trainerClass = TRAINER_CLASS_AROMA_LADY,
#line 10310
        .trainerPic = TRAINER_PIC_AROMA_LADY,
        .encounterMusic_gender =
#line 10312
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
#line 10313
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 10314
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 10316
            .species = SPECIES_BULBASAUR,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10318
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 10317
            .lvl = 36,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 10320
            .species = SPECIES_IVYSAUR,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10322
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 10321
            .lvl = 36,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 10324
            .species = SPECIES_IVYSAUR,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10326
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 10325
            .lvl = 36,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 10328
    [DIFFICULTY_NORMAL][TRAINER_TUBER_ALEXIS] =
    {
#line 10329
        .trainerName = _("ALEXIS"),
#line 10330
        .trainerClass = TRAINER_CLASS_TUBER,
#line 10331
        .trainerPic = TRAINER_PIC_TUBER_F,
        .encounterMusic_gender =
#line 10333
            TRAINER_ENCOUNTER_MUSIC_GIRL,
#line 10334
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 10335
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 4,
        .party = (const struct TrainerMon[])
        {
            {
#line 10337
            .species = SPECIES_STARYU,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10339
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 10338
            .lvl = 34,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 10341
            .species = SPECIES_STARYU,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10343
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 10342
            .lvl = 34,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 10345
            .species = SPECIES_KRABBY,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10347
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 10346
            .lvl = 34,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 10349
            .species = SPECIES_KRABBY,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10351
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 10350
            .lvl = 34,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 10353
    [DIFFICULTY_NORMAL][TRAINER_TWINS_JOY_MEG] =
    {
#line 10354
        .trainerName = _("JOY & MEG"),
#line 10355
        .trainerClass = TRAINER_CLASS_TWINS,
#line 10356
        .trainerPic = TRAINER_PIC_TWINS,
        .encounterMusic_gender =
#line 10358
            TRAINER_ENCOUNTER_MUSIC_TWINS,
#line 10359
        .battleType = TRAINER_BATTLE_TYPE_DOUBLES,
#line 10360
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 10362
            .species = SPECIES_CLEFAIRY,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10364
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 10363
            .lvl = 37,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 10366
            .species = SPECIES_CLEFAIRY,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10368
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 10367
            .lvl = 37,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 10370
    [DIFFICULTY_NORMAL][TRAINER_SWIMMER_FEMALE_TISHA] =
    {
#line 10371
        .trainerName = _("TISHA"),
#line 10372
        .trainerClass = TRAINER_CLASS_SWIMMER_F,
#line 10373
        .trainerPic = TRAINER_PIC_SWIMMER_F,
        .encounterMusic_gender =
#line 10375
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
#line 10376
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 10377
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 10379
            .species = SPECIES_KINGLER,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10381
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 10380
            .lvl = 38,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 10383
    [DIFFICULTY_NORMAL][TRAINER_PAINTER_CELINA] =
    {
#line 10384
        .trainerName = _("CELINA"),
#line 10385
        .trainerClass = TRAINER_CLASS_PAINTER,
#line 10386
        .trainerPic = TRAINER_PIC_PAINTER,
        .encounterMusic_gender =
#line 10388
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
#line 10389
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 10390
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 10392
            .species = SPECIES_SMEARGLE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10394
            .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
#line 10393
            .lvl = 50,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 10395
                MOVE_FLY,
                MOVE_DIG,
                MOVE_DIVE,
                MOVE_BOUNCE,
            },
            },
        },
    },
#line 10400
    [DIFFICULTY_NORMAL][TRAINER_PAINTER_RAYNA] =
    {
#line 10401
        .trainerName = _("RAYNA"),
#line 10402
        .trainerClass = TRAINER_CLASS_PAINTER,
#line 10403
        .trainerPic = TRAINER_PIC_PAINTER,
        .encounterMusic_gender =
#line 10405
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
#line 10406
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 10407
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 10409
            .species = SPECIES_SMEARGLE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10411
            .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
#line 10410
            .lvl = 50,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 10412
                MOVE_CROSS_CHOP,
                MOVE_MEGAHORN,
                MOVE_DOUBLE_EDGE,
                MOVE_SELF_DESTRUCT,
            },
            },
        },
    },
#line 10417
    [DIFFICULTY_NORMAL][TRAINER_LADY_GILLIAN] =
    {
#line 10418
        .trainerName = _("GILLIAN"),
#line 10419
        .trainerClass = TRAINER_CLASS_LADY,
#line 10420
        .trainerPic = TRAINER_PIC_LADY,
        .encounterMusic_gender =
#line 10422
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
#line 10423
        .items = { ITEM_FULL_RESTORE },
#line 10424
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 10425
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 10427
            .species = SPECIES_MAREEP,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10427
            .heldItem = ITEM_STARDUST,
#line 10429
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 10428
            .lvl = 47,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 10431
            .species = SPECIES_MAREEP,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10431
            .heldItem = ITEM_STARDUST,
#line 10433
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 10432
            .lvl = 48,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 10435
            .species = SPECIES_FLAAFFY,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10435
            .heldItem = ITEM_NUGGET,
#line 10437
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 10436
            .lvl = 49,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 10439
    [DIFFICULTY_NORMAL][TRAINER_YOUNGSTER_DESTIN] =
    {
#line 10440
        .trainerName = _("DESTIN"),
#line 10441
        .trainerClass = TRAINER_CLASS_YOUNGSTER,
#line 10442
        .trainerPic = TRAINER_PIC_YOUNGSTER,
        .encounterMusic_gender =
#line 10444
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 10445
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 10446
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 10448
            .species = SPECIES_RATICATE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10450
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 10449
            .lvl = 48,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 10452
            .species = SPECIES_PIDGEOTTO,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10454
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 10453
            .lvl = 48,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 10456
    [DIFFICULTY_NORMAL][TRAINER_SWIMMER_MALE_TOBY] =
    {
#line 10457
        .trainerName = _("TOBY"),
#line 10458
        .trainerClass = TRAINER_CLASS_SWIMMER_M,
#line 10459
        .trainerPic = TRAINER_PIC_SWIMMER_M,
        .encounterMusic_gender =
#line 10461
            TRAINER_ENCOUNTER_MUSIC_SWIMMER,
#line 10462
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 10463
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 10465
            .species = SPECIES_POLIWHIRL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10467
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 10466
            .lvl = 48,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 10469
            .species = SPECIES_TENTACOOL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10471
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 10470
            .lvl = 48,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 10473
            .species = SPECIES_TENTACRUEL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10475
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 10474
            .lvl = 48,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 10477
    [DIFFICULTY_NORMAL][TRAINER_TEAM_ROCKET_GRUNT_49] =
    {
#line 10478
        .trainerName = _("GRUNT"),
#line 10479
        .trainerClass = TRAINER_CLASS_TEAM_ROCKET,
#line 10480
        .trainerPic = TRAINER_PIC_ROCKET_GRUNT_M,
        .encounterMusic_gender =
#line 10482
            TRAINER_ENCOUNTER_MUSIC_AQUA,
#line 10483
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 10484
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 10486
            .species = SPECIES_RATTATA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10488
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 10487
            .lvl = 48,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 10490
            .species = SPECIES_GRIMER,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10492
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 10491
            .lvl = 48,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 10494
            .species = SPECIES_MUK,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10496
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 10495
            .lvl = 48,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 10498
    [DIFFICULTY_NORMAL][TRAINER_TEAM_ROCKET_GRUNT_50] =
    {
#line 10499
        .trainerName = _("GRUNT"),
#line 10500
        .trainerClass = TRAINER_CLASS_TEAM_ROCKET,
#line 10501
        .trainerPic = TRAINER_PIC_ROCKET_GRUNT_M,
        .encounterMusic_gender =
#line 10503
            TRAINER_ENCOUNTER_MUSIC_AQUA,
#line 10504
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 10505
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 10507
            .species = SPECIES_KOFFING,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10509
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 10508
            .lvl = 49,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 10510
                MOVE_MEMENTO,
                MOVE_HAZE,
                MOVE_SMOKESCREEN,
                MOVE_SLUDGE,
            },
            },
            {
#line 10515
            .species = SPECIES_WEEZING,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10517
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 10516
            .lvl = 49,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 10518
                MOVE_HAZE,
                MOVE_SMOKESCREEN,
                MOVE_SLUDGE,
                MOVE_SELF_DESTRUCT,
            },
            },
        },
    },
#line 10523
    [DIFFICULTY_NORMAL][TRAINER_TEAM_ROCKET_GRUNT_51] =
    {
#line 10524
        .trainerName = _("GRUNT"),
#line 10525
        .trainerClass = TRAINER_CLASS_TEAM_ROCKET,
#line 10526
        .trainerPic = TRAINER_PIC_ROCKET_GRUNT_F,
        .encounterMusic_gender =
#line 10528
            TRAINER_ENCOUNTER_MUSIC_AQUA,
#line 10529
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 10530
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 10532
            .species = SPECIES_EKANS,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10534
            .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
#line 10533
            .lvl = 48,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 10536
            .species = SPECIES_GLOOM,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10538
            .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
#line 10537
            .lvl = 48,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 10540
            .species = SPECIES_GLOOM,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10542
            .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
#line 10541
            .lvl = 48,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 10544
    [DIFFICULTY_NORMAL][TRAINER_BIRD_KEEPER_MILO] =
    {
#line 10545
        .trainerName = _("MILO"),
#line 10546
        .trainerClass = TRAINER_CLASS_BIRD_KEEPER,
#line 10547
        .trainerPic = TRAINER_PIC_BIRD_KEEPER,
        .encounterMusic_gender =
#line 10549
            TRAINER_ENCOUNTER_MUSIC_COOL,
#line 10550
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 10551
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 10553
            .species = SPECIES_PIDGEY,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10555
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 10554
            .lvl = 47,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 10557
            .species = SPECIES_PIDGEOTTO,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10559
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 10558
            .lvl = 49,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 10561
    [DIFFICULTY_NORMAL][TRAINER_BIRD_KEEPER_CHAZ] =
    {
#line 10562
        .trainerName = _("CHAZ"),
#line 10563
        .trainerClass = TRAINER_CLASS_BIRD_KEEPER,
#line 10564
        .trainerPic = TRAINER_PIC_BIRD_KEEPER,
        .encounterMusic_gender =
#line 10566
            TRAINER_ENCOUNTER_MUSIC_COOL,
#line 10567
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 10568
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 10570
            .species = SPECIES_SPEAROW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10572
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 10571
            .lvl = 47,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 10574
            .species = SPECIES_FEAROW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10576
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 10575
            .lvl = 49,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 10578
    [DIFFICULTY_NORMAL][TRAINER_BIRD_KEEPER_HAROLD] =
    {
#line 10579
        .trainerName = _("HAROLD"),
#line 10580
        .trainerClass = TRAINER_CLASS_BIRD_KEEPER,
#line 10581
        .trainerPic = TRAINER_PIC_BIRD_KEEPER,
        .encounterMusic_gender =
#line 10583
            TRAINER_ENCOUNTER_MUSIC_COOL,
#line 10584
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 10585
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 10587
            .species = SPECIES_HOOTHOOT,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10589
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 10588
            .lvl = 47,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 10591
            .species = SPECIES_NOCTOWL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10593
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 10592
            .lvl = 49,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 10595
    [DIFFICULTY_NORMAL][TRAINER_FISHERMAN_TYLOR] =
    {
#line 10596
        .trainerName = _("TYLOR"),
#line 10597
        .trainerClass = TRAINER_CLASS_FISHERMAN,
#line 10598
        .trainerPic = TRAINER_PIC_FISHERMAN,
        .encounterMusic_gender =
#line 10600
            TRAINER_ENCOUNTER_MUSIC_HIKER,
#line 10601
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 10602
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 10604
            .species = SPECIES_QWILFISH,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10606
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 10605
            .lvl = 49,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 10608
            .species = SPECIES_QWILFISH,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10610
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 10609
            .lvl = 49,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 10612
    [DIFFICULTY_NORMAL][TRAINER_SWIMMER_MALE_MYMO] =
    {
#line 10613
        .trainerName = _("MYMO"),
#line 10614
        .trainerClass = TRAINER_CLASS_SWIMMER_M,
#line 10615
        .trainerPic = TRAINER_PIC_SWIMMER_M,
        .encounterMusic_gender =
#line 10617
            TRAINER_ENCOUNTER_MUSIC_SWIMMER,
#line 10618
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 10619
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 10621
            .species = SPECIES_KINGLER,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10623
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 10622
            .lvl = 49,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 10625
            .species = SPECIES_WARTORTLE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10627
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 10626
            .lvl = 49,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 10629
    [DIFFICULTY_NORMAL][TRAINER_SWIMMER_FEMALE_NICOLE] =
    {
#line 10630
        .trainerName = _("NICOLE"),
#line 10631
        .trainerClass = TRAINER_CLASS_SWIMMER_F,
#line 10632
        .trainerPic = TRAINER_PIC_SWIMMER_F,
        .encounterMusic_gender =
#line 10634
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
#line 10635
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 10636
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 10638
            .species = SPECIES_MARILL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10640
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 10639
            .lvl = 50,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 10642
    [DIFFICULTY_NORMAL][TRAINER_SIS_AND_BRO_AVA_GEB] =
    {
#line 10643
        .trainerName = _("AVA & GEB"),
#line 10644
        .trainerClass = TRAINER_CLASS_SIS_AND_BRO,
#line 10645
        .trainerPic = TRAINER_PIC_SIS_AND_BRO,
        .encounterMusic_gender =
#line 10647
            TRAINER_ENCOUNTER_MUSIC_SWIMMER,
#line 10648
        .battleType = TRAINER_BATTLE_TYPE_DOUBLES,
#line 10649
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 10651
            .species = SPECIES_POLIWHIRL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10653
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 10652
            .lvl = 50,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 10655
            .species = SPECIES_STARMIE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10657
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 10656
            .lvl = 50,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 10659
    [DIFFICULTY_NORMAL][TRAINER_AROMA_LADY_ROSE] =
    {
#line 10660
        .trainerName = _("ROSE"),
#line 10661
        .trainerClass = TRAINER_CLASS_AROMA_LADY,
#line 10662
        .trainerPic = TRAINER_PIC_AROMA_LADY,
        .encounterMusic_gender =
#line 10664
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
#line 10665
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 10666
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 10668
            .species = SPECIES_SUNKERN,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10670
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 10669
            .lvl = 49,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 10672
            .species = SPECIES_SUNFLORA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10674
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 10673
            .lvl = 49,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 10676
    [DIFFICULTY_NORMAL][TRAINER_SWIMMER_MALE_SAMIR] =
    {
#line 10677
        .trainerName = _("SAMIR"),
#line 10678
        .trainerClass = TRAINER_CLASS_SWIMMER_M,
#line 10679
        .trainerPic = TRAINER_PIC_SWIMMER_M,
        .encounterMusic_gender =
#line 10681
            TRAINER_ENCOUNTER_MUSIC_SWIMMER,
#line 10682
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 10683
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 10685
            .species = SPECIES_GYARADOS,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10687
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 10686
            .lvl = 50,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 10689
    [DIFFICULTY_NORMAL][TRAINER_SWIMMER_FEMALE_DENISE] =
    {
#line 10690
        .trainerName = _("DENISE"),
#line 10691
        .trainerClass = TRAINER_CLASS_SWIMMER_F,
#line 10692
        .trainerPic = TRAINER_PIC_SWIMMER_F,
        .encounterMusic_gender =
#line 10694
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
#line 10695
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 10696
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 10698
            .species = SPECIES_CHINCHOU,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10700
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 10699
            .lvl = 49,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 10702
            .species = SPECIES_LANTURN,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10704
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 10703
            .lvl = 49,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 10706
    [DIFFICULTY_NORMAL][TRAINER_TWINS_MIU_MIA] =
    {
#line 10707
        .trainerName = _("MIU & MIA"),
#line 10708
        .trainerClass = TRAINER_CLASS_TWINS,
#line 10709
        .trainerPic = TRAINER_PIC_TWINS,
        .encounterMusic_gender =
#line 10711
            TRAINER_ENCOUNTER_MUSIC_TWINS,
#line 10712
        .battleType = TRAINER_BATTLE_TYPE_DOUBLES,
#line 10713
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 10715
            .species = SPECIES_PIKACHU,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10717
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 10716
            .lvl = 50,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 10719
            .species = SPECIES_PIKACHU,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10721
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 10720
            .lvl = 50,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 10723
    [DIFFICULTY_NORMAL][TRAINER_HIKER_EARL] =
    {
#line 10724
        .trainerName = _("EARL"),
#line 10725
        .trainerClass = TRAINER_CLASS_HIKER,
#line 10726
        .trainerPic = TRAINER_PIC_HIKER,
        .encounterMusic_gender =
#line 10728
            TRAINER_ENCOUNTER_MUSIC_HIKER,
#line 10729
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 10730
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 10732
            .species = SPECIES_ONIX,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10734
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 10733
            .lvl = 49,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 10736
            .species = SPECIES_MACHOKE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10738
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 10737
            .lvl = 49,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 10740
    [DIFFICULTY_NORMAL][TRAINER_RUIN_MANIAC_FOSTER] =
    {
#line 10741
        .trainerName = _("FOSTER"),
#line 10742
        .trainerClass = TRAINER_CLASS_RUIN_MANIAC,
#line 10743
        .trainerPic = TRAINER_PIC_RUIN_MANIAC,
        .encounterMusic_gender =
#line 10745
            TRAINER_ENCOUNTER_MUSIC_HIKER,
#line 10746
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 10747
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 10749
            .species = SPECIES_GOLEM,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10751
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 10750
            .lvl = 50,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 10753
    [DIFFICULTY_NORMAL][TRAINER_RUIN_MANIAC_LARRY] =
    {
#line 10754
        .trainerName = _("LARRY"),
#line 10755
        .trainerClass = TRAINER_CLASS_RUIN_MANIAC,
#line 10756
        .trainerPic = TRAINER_PIC_RUIN_MANIAC,
        .encounterMusic_gender =
#line 10758
            TRAINER_ENCOUNTER_MUSIC_HIKER,
#line 10759
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 10760
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 10762
            .species = SPECIES_MACHOKE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10764
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 10763
            .lvl = 49,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 10766
            .species = SPECIES_MACHOKE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10768
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 10767
            .lvl = 49,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 10770
    [DIFFICULTY_NORMAL][TRAINER_HIKER_DARYL] =
    {
#line 10771
        .trainerName = _("DARYL"),
#line 10772
        .trainerClass = TRAINER_CLASS_HIKER,
#line 10773
        .trainerPic = TRAINER_PIC_HIKER,
        .encounterMusic_gender =
#line 10775
            TRAINER_ENCOUNTER_MUSIC_HIKER,
#line 10776
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 10777
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 10779
            .species = SPECIES_SUDOWOODO,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10781
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 10780
            .lvl = 50,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 10783
    [DIFFICULTY_NORMAL][TRAINER_POKEMANIAC_HECTOR] =
    {
#line 10784
        .trainerName = _("HECTOR"),
#line 10785
        .trainerClass = TRAINER_CLASS_POKEMANIAC,
#line 10786
        .trainerPic = TRAINER_PIC_POKEMANIAC,
        .encounterMusic_gender =
#line 10788
            TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
#line 10789
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 10790
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 10792
            .species = SPECIES_RHYHORN,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10794
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
#line 10793
            .lvl = 49,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 10796
            .species = SPECIES_KANGASKHAN,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10798
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
#line 10797
            .lvl = 49,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 10800
    [DIFFICULTY_NORMAL][TRAINER_PSYCHIC_DARIO] =
    {
#line 10801
        .trainerName = _("DARIO"),
#line 10802
        .trainerClass = TRAINER_CLASS_PSYCHIC,
#line 10803
        .trainerPic = TRAINER_PIC_PSYCHIC_M,
        .encounterMusic_gender =
#line 10805
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
#line 10806
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 10807
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 10809
            .species = SPECIES_GIRAFARIG,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10811
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 10810
            .lvl = 52,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 10812
                MOVE_CRUNCH,
                MOVE_PSYBEAM,
                MOVE_ODOR_SLEUTH,
                MOVE_AGILITY,
            },
            },
        },
    },
#line 10817
    [DIFFICULTY_NORMAL][TRAINER_PSYCHIC_RODETTE] =
    {
#line 10818
        .trainerName = _("RODETTE"),
#line 10819
        .trainerClass = TRAINER_CLASS_PSYCHIC,
#line 10820
        .trainerPic = TRAINER_PIC_PSYCHIC_F,
        .encounterMusic_gender =
#line 10822
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
#line 10823
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 10824
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 10826
            .species = SPECIES_NATU,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10828
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 10827
            .lvl = 48,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 10829
                MOVE_NIGHT_SHADE,
                MOVE_CONFUSE_RAY,
                MOVE_WISH,
                MOVE_FUTURE_SIGHT,
            },
            },
            {
#line 10834
            .species = SPECIES_DROWZEE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10836
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 10835
            .lvl = 48,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 10837
                MOVE_PSYCHIC,
                MOVE_DISABLE,
                MOVE_PSYCH_UP,
                MOVE_FUTURE_SIGHT,
            },
            },
            {
#line 10842
            .species = SPECIES_HYPNO,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10844
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 10843
            .lvl = 50,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 10845
                MOVE_PSYCHIC,
                MOVE_HYPNOSIS,
                MOVE_PSYCH_UP,
                MOVE_FUTURE_SIGHT,
            },
            },
        },
    },
#line 10850
    [DIFFICULTY_NORMAL][TRAINER_AROMA_LADY_MIAH] =
    {
#line 10851
        .trainerName = _("MIAH"),
#line 10852
        .trainerClass = TRAINER_CLASS_AROMA_LADY,
#line 10853
        .trainerPic = TRAINER_PIC_AROMA_LADY,
        .encounterMusic_gender =
#line 10855
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
#line 10856
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 10857
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 10859
            .species = SPECIES_BELLOSSOM,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10861
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 10860
            .lvl = 50,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 10863
            .species = SPECIES_BELLOSSOM,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10865
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 10864
            .lvl = 50,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 10867
    [DIFFICULTY_NORMAL][TRAINER_YOUNG_COUPLE_EVE_JON] =
    {
#line 10868
        .trainerName = _("EVE & JON"),
#line 10869
        .trainerClass = TRAINER_CLASS_YOUNG_COUPLE,
#line 10870
        .trainerPic = TRAINER_PIC_YOUNG_COUPLE,
        .encounterMusic_gender =
#line 10872
            TRAINER_ENCOUNTER_MUSIC_GIRL,
#line 10873
        .battleType = TRAINER_BATTLE_TYPE_DOUBLES,
#line 10874
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 10876
            .species = SPECIES_GOLDUCK,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10878
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 10877
            .lvl = 50,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 10880
            .species = SPECIES_PSYDUCK,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10882
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 10881
            .lvl = 50,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 10884
    [DIFFICULTY_NORMAL][TRAINER_JUGGLER_MASON] =
    {
#line 10885
        .trainerName = _("MASON"),
#line 10886
        .trainerClass = TRAINER_CLASS_JUGGLER,
#line 10887
        .trainerPic = TRAINER_PIC_JUGGLER,
        .encounterMusic_gender =
#line 10889
            TRAINER_ENCOUNTER_MUSIC_HIKER,
#line 10890
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 10891
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 4,
        .party = (const struct TrainerMon[])
        {
            {
#line 10893
            .species = SPECIES_VOLTORB,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10895
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 10894
            .lvl = 47,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 10896
                MOVE_SWIFT,
                MOVE_LIGHT_SCREEN,
                MOVE_SPARK,
                MOVE_SONIC_BOOM,
            },
            },
            {
#line 10901
            .species = SPECIES_PINECO,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10903
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 10902
            .lvl = 47,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 10904
                MOVE_SPIKES,
                MOVE_BIDE,
                MOVE_RAPID_SPIN,
                MOVE_TAKE_DOWN,
            },
            },
            {
#line 10909
            .species = SPECIES_VOLTORB,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10911
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 10910
            .lvl = 47,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 10912
                MOVE_SWIFT,
                MOVE_LIGHT_SCREEN,
                MOVE_SPARK,
                MOVE_SONIC_BOOM,
            },
            },
            {
#line 10917
            .species = SPECIES_PINECO,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10919
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 10918
            .lvl = 47,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 10920
                MOVE_SPIKES,
                MOVE_BIDE,
                MOVE_RAPID_SPIN,
                MOVE_EXPLOSION,
            },
            },
        },
    },
#line 10925
    [DIFFICULTY_NORMAL][TRAINER_CRUSH_GIRL_CYNDY] =
    {
#line 10926
        .trainerName = _("CYNDY"),
#line 10927
        .trainerClass = TRAINER_CLASS_CRUSH_GIRL,
#line 10928
        .trainerPic = TRAINER_PIC_CRUSH_GIRL,
        .encounterMusic_gender =
#line 10930
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
#line 10931
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 10932
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 10934
            .species = SPECIES_PRIMEAPE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10934
            .heldItem = ITEM_BLACK_BELT,
#line 10936
            .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
#line 10935
            .lvl = 48,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 10938
            .species = SPECIES_HITMONTOP,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10938
            .heldItem = ITEM_BLACK_BELT,
#line 10940
            .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
#line 10939
            .lvl = 48,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 10942
            .species = SPECIES_MACHOKE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10942
            .heldItem = ITEM_BLACK_BELT,
#line 10944
            .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
#line 10943
            .lvl = 48,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 10946
    [DIFFICULTY_NORMAL][TRAINER_CRUSH_GIRL_JOCELYN] =
    {
#line 10947
        .trainerName = _("JOCELYN"),
#line 10948
        .trainerClass = TRAINER_CLASS_CRUSH_GIRL,
#line 10949
        .trainerPic = TRAINER_PIC_CRUSH_GIRL,
        .encounterMusic_gender =
#line 10951
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
#line 10952
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 10953
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 10955
            .species = SPECIES_HITMONCHAN,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10955
            .heldItem = ITEM_BLACK_BELT,
#line 10957
            .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
#line 10956
            .lvl = 38,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 10959
            .species = SPECIES_HITMONCHAN,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10959
            .heldItem = ITEM_BLACK_BELT,
#line 10961
            .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
#line 10960
            .lvl = 38,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 10963
    [DIFFICULTY_NORMAL][TRAINER_TAMER_EVAN] =
    {
#line 10964
        .trainerName = _("EVAN"),
#line 10965
        .trainerClass = TRAINER_CLASS_TAMER,
#line 10966
        .trainerPic = TRAINER_PIC_TAMER,
        .encounterMusic_gender =
#line 10968
            TRAINER_ENCOUNTER_MUSIC_HIKER,
#line 10969
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 10970
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 10972
            .species = SPECIES_SANDSLASH,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10974
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
#line 10973
            .lvl = 48,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 10976
            .species = SPECIES_LICKITUNG,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10978
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
#line 10977
            .lvl = 48,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 10980
            .species = SPECIES_URSARING,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10982
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
#line 10981
            .lvl = 49,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 10984
    [DIFFICULTY_NORMAL][TRAINER_POKEMANIAC_MARK_2] =
    {
#line 10985
        .trainerName = _("MARK"),
#line 10986
        .trainerClass = TRAINER_CLASS_POKEMANIAC,
#line 10987
        .trainerPic = TRAINER_PIC_POKEMANIAC,
        .encounterMusic_gender =
#line 10989
            TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
#line 10990
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 10991
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 10993
            .species = SPECIES_RHYHORN,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10995
            .iv = TRAINER_PARTY_IVS(10, 10, 10, 10, 10, 10),
#line 10994
            .lvl = 33,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 10997
            .species = SPECIES_LICKITUNG,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10999
            .iv = TRAINER_PARTY_IVS(10, 10, 10, 10, 10, 10),
#line 10998
            .lvl = 33,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 11001
    [DIFFICULTY_NORMAL][TRAINER_PKMN_RANGER_LOGAN] =
    {
#line 11002
        .trainerName = _("LOGAN"),
#line 11003
        .trainerClass = TRAINER_CLASS_PKMN_RANGER,
#line 11004
        .trainerPic = TRAINER_PIC_POKEMON_RANGER_M,
        .encounterMusic_gender =
#line 11006
            TRAINER_ENCOUNTER_MUSIC_COOL,
#line 11007
        .items = { ITEM_FULL_RESTORE },
#line 11008
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 11009
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 11011
            .species = SPECIES_EXEGGCUTE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11013
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 11012
            .lvl = 37,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 11014
                MOVE_SLEEP_POWDER,
                MOVE_POISON_POWDER,
                MOVE_STUN_SPORE,
                MOVE_CONFUSION,
            },
            },
            {
#line 11019
            .species = SPECIES_EXEGGUTOR,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11021
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 11020
            .lvl = 40,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 11022
                MOVE_EGG_BOMB,
                MOVE_STOMP,
                MOVE_CONFUSION,
                MOVE_HYPNOSIS,
            },
            },
        },
    },
#line 11027
    [DIFFICULTY_NORMAL][TRAINER_PKMN_RANGER_JACKSON] =
    {
#line 11028
        .trainerName = _("JACKSON"),
#line 11029
        .trainerClass = TRAINER_CLASS_PKMN_RANGER,
#line 11030
        .trainerPic = TRAINER_PIC_POKEMON_RANGER_M,
        .encounterMusic_gender =
#line 11032
            TRAINER_ENCOUNTER_MUSIC_COOL,
#line 11033
        .items = { ITEM_FULL_RESTORE },
#line 11034
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 11035
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 11037
            .species = SPECIES_TANGELA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11039
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 11038
            .lvl = 49,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 11040
                MOVE_SLAM,
                MOVE_MEGA_DRAIN,
                MOVE_BIND,
                MOVE_INGRAIN,
            },
            },
            {
#line 11045
            .species = SPECIES_EXEGGCUTE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11047
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 11046
            .lvl = 49,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 11048
                MOVE_CONFUSION,
                MOVE_POISON_POWDER,
                MOVE_BARRAGE,
                MOVE_REFLECT,
            },
            },
            {
#line 11053
            .species = SPECIES_EXEGGUTOR,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11055
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 11054
            .lvl = 49,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 11056
                MOVE_CONFUSION,
                MOVE_EGG_BOMB,
                MOVE_SLEEP_POWDER,
                MOVE_STOMP,
            },
            },
        },
    },
#line 11061
    [DIFFICULTY_NORMAL][TRAINER_PKMN_RANGER_BETH] =
    {
#line 11062
        .trainerName = _("BETH"),
#line 11063
        .trainerClass = TRAINER_CLASS_PKMN_RANGER,
#line 11064
        .trainerPic = TRAINER_PIC_POKEMON_RANGER_F,
        .encounterMusic_gender =
#line 11066
            TRAINER_ENCOUNTER_MUSIC_COOL,
#line 11067
        .items = { ITEM_FULL_RESTORE },
#line 11068
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 11069
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 11071
            .species = SPECIES_BELLSPROUT,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11073
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 11072
            .lvl = 38,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 11075
            .species = SPECIES_GLOOM,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11077
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 11076
            .lvl = 38,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 11079
            .species = SPECIES_GLOOM,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11081
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 11080
            .lvl = 38,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 11083
    [DIFFICULTY_NORMAL][TRAINER_PKMN_RANGER_KATELYN] =
    {
#line 11084
        .trainerName = _("KATELYN"),
#line 11085
        .trainerClass = TRAINER_CLASS_PKMN_RANGER,
#line 11086
        .trainerPic = TRAINER_PIC_POKEMON_RANGER_F,
        .encounterMusic_gender =
#line 11088
            TRAINER_ENCOUNTER_MUSIC_COOL,
#line 11089
        .items = { ITEM_FULL_RESTORE },
#line 11090
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 11091
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 11093
            .species = SPECIES_CHANSEY,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11095
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 11094
            .lvl = 52,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 11096
                MOVE_EGG_BOMB,
                MOVE_DEFENSE_CURL,
                MOVE_MINIMIZE,
                MOVE_SOFT_BOILED,
            },
            },
        },
    },
#line 11101
    [DIFFICULTY_NORMAL][TRAINER_COOLTRAINER_LEROY] =
    {
#line 11102
        .trainerName = _("LEROY"),
#line 11103
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
#line 11104
        .trainerPic = TRAINER_PIC_COOLTRAINER_M,
        .encounterMusic_gender =
#line 11106
            TRAINER_ENCOUNTER_MUSIC_COOL,
#line 11107
        .items = { ITEM_FULL_RESTORE },
#line 11108
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 11109
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .partySize = 5,
        .party = (const struct TrainerMon[])
        {
            {
#line 11111
            .species = SPECIES_RHYDON,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11113
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 11112
            .lvl = 47,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 11114
                MOVE_TAKE_DOWN,
                MOVE_HORN_DRILL,
                MOVE_ROCK_BLAST,
                MOVE_SCARY_FACE,
            },
            },
            {
#line 11119
            .species = SPECIES_SLOWBRO,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11121
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 11120
            .lvl = 48,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 11122
                MOVE_PSYCHIC,
                MOVE_HEADBUTT,
                MOVE_AMNESIA,
                MOVE_DISABLE,
            },
            },
            {
#line 11127
            .species = SPECIES_KANGASKHAN,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11129
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 11128
            .lvl = 47,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 11130
                MOVE_DIZZY_PUNCH,
                MOVE_BITE,
                MOVE_ENDURE,
                MOVE_REVERSAL,
            },
            },
            {
#line 11135
            .species = SPECIES_MACHOKE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11137
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 11136
            .lvl = 48,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 11138
                MOVE_CROSS_CHOP,
                MOVE_VITAL_THROW,
                MOVE_REVENGE,
                MOVE_SEISMIC_TOSS,
            },
            },
            {
#line 11143
            .species = SPECIES_URSARING,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11145
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 11144
            .lvl = 50,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 11146
                MOVE_SLASH,
                MOVE_FAINT_ATTACK,
                MOVE_SNORE,
                MOVE_REST,
            },
            },
        },
    },
#line 11151
    [DIFFICULTY_NORMAL][TRAINER_COOLTRAINER_MICHELLE] =
    {
#line 11152
        .trainerName = _("MICHELLE"),
#line 11153
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
#line 11154
        .trainerPic = TRAINER_PIC_COOLTRAINER_F,
        .encounterMusic_gender =
#line 11156
            TRAINER_ENCOUNTER_MUSIC_COOL,
#line 11157
        .items = { ITEM_HYPER_POTION },
#line 11158
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 11159
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .partySize = 5,
        .party = (const struct TrainerMon[])
        {
            {
#line 11161
            .species = SPECIES_PERSIAN,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11163
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 11162
            .lvl = 47,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 11164
                MOVE_SLASH,
                MOVE_SCREECH,
                MOVE_FAINT_ATTACK,
                MOVE_BITE,
            },
            },
            {
#line 11169
            .species = SPECIES_DEWGONG,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11171
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 11170
            .lvl = 47,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 11172
                MOVE_ICE_BEAM,
                MOVE_TAKE_DOWN,
                MOVE_ICY_WIND,
                MOVE_GROWL,
            },
            },
            {
#line 11177
            .species = SPECIES_NINETALES,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11179
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 11178
            .lvl = 48,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 11180
                MOVE_FLAMETHROWER,
                MOVE_CONFUSE_RAY,
                MOVE_WILL_O_WISP,
                MOVE_GRUDGE,
            },
            },
            {
#line 11185
            .species = SPECIES_RAPIDASH,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11187
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 11186
            .lvl = 48,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 11188
                MOVE_BOUNCE,
                MOVE_AGILITY,
                MOVE_FIRE_SPIN,
                MOVE_TAKE_DOWN,
            },
            },
            {
#line 11193
            .species = SPECIES_GIRAFARIG,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11195
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 11194
            .lvl = 50,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 11196
                MOVE_CRUNCH,
                MOVE_PSYBEAM,
                MOVE_STOMP,
                MOVE_ODOR_SLEUTH,
            },
            },
        },
    },
#line 11201
    [DIFFICULTY_NORMAL][TRAINER_COOL_COUPLE_LEX_NYA] =
    {
#line 11202
        .trainerName = _("LEX & NYA"),
#line 11203
        .trainerClass = TRAINER_CLASS_COOL_COUPLE,
#line 11204
        .trainerPic = TRAINER_PIC_COOL_COUPLE,
        .encounterMusic_gender =
#line 11206
            TRAINER_ENCOUNTER_MUSIC_COOL,
#line 11207
        .items = { ITEM_FULL_RESTORE, ITEM_FULL_RESTORE },
#line 11208
        .battleType = TRAINER_BATTLE_TYPE_DOUBLES,
#line 11209
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 11211
            .species = SPECIES_MILTANK,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11213
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 11212
            .lvl = 52,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 11214
                MOVE_BODY_SLAM,
                MOVE_MILK_DRINK,
                MOVE_GROWL,
                MOVE_DEFENSE_CURL,
            },
            },
            {
#line 11219
            .species = SPECIES_TAUROS,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11221
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 11220
            .lvl = 52,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 11222
                MOVE_THRASH,
                MOVE_HORN_ATTACK,
                MOVE_PURSUIT,
                MOVE_SWAGGER,
            },
            },
        },
    },
#line 11227
    [DIFFICULTY_NORMAL][TRAINER_RUIN_MANIAC_BRANDON] =
    {
#line 11228
        .trainerName = _("BRANDON"),
#line 11229
        .trainerClass = TRAINER_CLASS_RUIN_MANIAC,
#line 11230
        .trainerPic = TRAINER_PIC_RUIN_MANIAC,
        .encounterMusic_gender =
#line 11232
            TRAINER_ENCOUNTER_MUSIC_HIKER,
#line 11233
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 11234
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 11236
            .species = SPECIES_ONIX,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11238
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 11237
            .lvl = 50,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 11240
    [DIFFICULTY_NORMAL][TRAINER_RUIN_MANIAC_BENJAMIN] =
    {
#line 11241
        .trainerName = _("BENJAMIN"),
#line 11242
        .trainerClass = TRAINER_CLASS_RUIN_MANIAC,
#line 11243
        .trainerPic = TRAINER_PIC_RUIN_MANIAC,
        .encounterMusic_gender =
#line 11245
            TRAINER_ENCOUNTER_MUSIC_HIKER,
#line 11246
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 11247
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 11249
            .species = SPECIES_GEODUDE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11251
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 11250
            .lvl = 48,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 11252
                MOVE_EARTHQUAKE,
                MOVE_ROCK_BLAST,
                MOVE_ROLLOUT,
                MOVE_SELF_DESTRUCT,
            },
            },
            {
#line 11257
            .species = SPECIES_GRAVELER,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11259
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 11258
            .lvl = 48,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 11260
                MOVE_EARTHQUAKE,
                MOVE_ROCK_BLAST,
                MOVE_ROCK_THROW,
                MOVE_SELF_DESTRUCT,
            },
            },
            {
#line 11265
            .species = SPECIES_GRAVELER,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11267
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 11266
            .lvl = 48,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 11268
                MOVE_EARTHQUAKE,
                MOVE_ROCK_BLAST,
                MOVE_ROCK_THROW,
                MOVE_SELF_DESTRUCT,
            },
            },
        },
    },
#line 11273
    [DIFFICULTY_NORMAL][TRAINER_PAINTER_EDNA] =
    {
#line 11274
        .trainerName = _("EDNA"),
#line 11275
        .trainerClass = TRAINER_CLASS_PAINTER,
#line 11276
        .trainerPic = TRAINER_PIC_PAINTER,
        .encounterMusic_gender =
#line 11278
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
#line 11279
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 11280
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 11282
            .species = SPECIES_SMEARGLE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11284
            .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
#line 11283
            .lvl = 50,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 11285
                MOVE_FAKE_OUT,
                MOVE_EXTREME_SPEED,
                MOVE_PROTECT,
                MOVE_QUICK_ATTACK,
            },
            },
        },
    },
#line 11290
    [DIFFICULTY_NORMAL][TRAINER_GENTLEMAN_CLIFFORD] =
    {
#line 11291
        .trainerName = _("CLIFFORD"),
#line 11292
        .trainerClass = TRAINER_CLASS_GENTLEMAN,
#line 11293
        .trainerPic = TRAINER_PIC_GENTLEMAN,
        .encounterMusic_gender =
#line 11295
            TRAINER_ENCOUNTER_MUSIC_RICH,
#line 11296
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 11297
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 11299
            .species = SPECIES_MAROWAK,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11301
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 11300
            .lvl = 49,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 11303
            .species = SPECIES_GOLDUCK,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11305
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 11304
            .lvl = 49,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 11307
    [DIFFICULTY_NORMAL][TRAINER_LADY_SELPHY] =
    {
#line 11308
        .trainerName = _("SELPHY"),
#line 11309
        .trainerClass = TRAINER_CLASS_LADY,
#line 11310
        .trainerPic = TRAINER_PIC_LADY,
        .encounterMusic_gender =
#line 11312
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
#line 11313
        .items = { ITEM_FULL_RESTORE },
#line 11314
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 11315
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 11317
            .species = SPECIES_PERSIAN,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11317
            .heldItem = ITEM_NUGGET,
#line 11319
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 11318
            .lvl = 49,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 11320
                MOVE_PAY_DAY,
                MOVE_BITE,
                MOVE_TAUNT,
                MOVE_TORMENT,
            },
            },
            {
#line 11325
            .species = SPECIES_PERSIAN,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11325
            .heldItem = ITEM_NUGGET,
#line 11327
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 11326
            .lvl = 49,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 11328
                MOVE_PAY_DAY,
                MOVE_SCRATCH,
                MOVE_TORMENT,
                MOVE_TAUNT,
            },
            },
        },
    },
#line 11333
    [DIFFICULTY_NORMAL][TRAINER_RUIN_MANIAC_LAWSON] =
    {
#line 11334
        .trainerName = _("LAWSON"),
#line 11335
        .trainerClass = TRAINER_CLASS_RUIN_MANIAC,
#line 11336
        .trainerPic = TRAINER_PIC_RUIN_MANIAC,
        .encounterMusic_gender =
#line 11338
            TRAINER_ENCOUNTER_MUSIC_HIKER,
#line 11339
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 11340
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 11342
            .species = SPECIES_ONIX,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11344
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 11343
            .lvl = 47,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 11346
            .species = SPECIES_GRAVELER,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11348
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 11347
            .lvl = 48,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 11350
            .species = SPECIES_MAROWAK,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11352
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 11351
            .lvl = 49,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 11354
    [DIFFICULTY_NORMAL][TRAINER_PSYCHIC_LAURA] =
    {
#line 11355
        .trainerName = _("LAURA"),
#line 11356
        .trainerClass = TRAINER_CLASS_PSYCHIC,
#line 11357
        .trainerPic = TRAINER_PIC_PSYCHIC_F,
        .encounterMusic_gender =
#line 11359
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
#line 11360
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 11361
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 11363
            .species = SPECIES_NATU,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11365
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 11364
            .lvl = 48,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 11367
            .species = SPECIES_NATU,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11369
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 11368
            .lvl = 48,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 11371
            .species = SPECIES_XATU,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11373
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 11372
            .lvl = 49,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 11375
    [DIFFICULTY_NORMAL][TRAINER_PKMN_BREEDER_BETHANY] =
    {
#line 11376
        .trainerName = _("BETHANY"),
#line 11377
        .trainerClass = TRAINER_CLASS_PKMN_BREEDER,
#line 11378
        .trainerPic = TRAINER_PIC_POKEMON_BREEDER,
        .encounterMusic_gender =
#line 11380
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
#line 11381
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 11382
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 11384
            .species = SPECIES_CHANSEY,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11386
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
#line 11385
            .lvl = 50,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 11388
    [DIFFICULTY_NORMAL][TRAINER_PKMN_BREEDER_ALLISON] =
    {
#line 11389
        .trainerName = _("ALLISON"),
#line 11390
        .trainerClass = TRAINER_CLASS_PKMN_BREEDER,
#line 11391
        .trainerPic = TRAINER_PIC_POKEMON_BREEDER,
        .encounterMusic_gender =
#line 11393
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
#line 11394
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 11395
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 11397
            .species = SPECIES_CLEFAIRY,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11399
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
#line 11398
            .lvl = 48,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 11401
            .species = SPECIES_CLEFAIRY,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11403
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
#line 11402
            .lvl = 48,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 11405
            .species = SPECIES_CLEFABLE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11407
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
#line 11406
            .lvl = 48,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 11409
    [DIFFICULTY_NORMAL][TRAINER_BUG_CATCHER_GARRET] =
    {
#line 11410
        .trainerName = _("GARRET"),
#line 11411
        .trainerClass = TRAINER_CLASS_BUG_CATCHER,
#line 11412
        .trainerPic = TRAINER_PIC_BUG_CATCHER,
        .encounterMusic_gender =
#line 11414
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 11415
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 11416
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 11418
            .species = SPECIES_HERACROSS,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11420
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 11419
            .lvl = 49,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 11422
    [DIFFICULTY_NORMAL][TRAINER_BUG_CATCHER_JONAH] =
    {
#line 11423
        .trainerName = _("JONAH"),
#line 11424
        .trainerClass = TRAINER_CLASS_BUG_CATCHER,
#line 11425
        .trainerPic = TRAINER_PIC_BUG_CATCHER,
        .encounterMusic_gender =
#line 11427
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 11428
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 11429
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 4,
        .party = (const struct TrainerMon[])
        {
            {
#line 11431
            .species = SPECIES_YANMA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11433
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 11432
            .lvl = 45,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 11435
            .species = SPECIES_BEEDRILL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11437
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 11436
            .lvl = 45,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 11439
            .species = SPECIES_YANMA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11441
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 11440
            .lvl = 46,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 11443
            .species = SPECIES_BEEDRILL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11445
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 11444
            .lvl = 47,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 11447
    [DIFFICULTY_NORMAL][TRAINER_BUG_CATCHER_VANCE] =
    {
#line 11448
        .trainerName = _("VANCE"),
#line 11449
        .trainerClass = TRAINER_CLASS_BUG_CATCHER,
#line 11450
        .trainerPic = TRAINER_PIC_BUG_CATCHER,
        .encounterMusic_gender =
#line 11452
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 11453
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 11454
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 11456
            .species = SPECIES_VENONAT,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11458
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 11457
            .lvl = 48,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 11460
            .species = SPECIES_VENOMOTH,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11462
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 11461
            .lvl = 48,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 11464
    [DIFFICULTY_NORMAL][TRAINER_YOUNGSTER_NASH] =
    {
#line 11465
        .trainerName = _("NASH"),
#line 11466
        .trainerClass = TRAINER_CLASS_YOUNGSTER,
#line 11467
        .trainerPic = TRAINER_PIC_YOUNGSTER,
        .encounterMusic_gender =
#line 11469
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 11470
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 11471
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 11473
            .species = SPECIES_WEEPINBELL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11475
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 11474
            .lvl = 47,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 11477
            .species = SPECIES_WEEPINBELL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11479
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 11478
            .lvl = 47,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 11481
            .species = SPECIES_VICTREEBEL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11483
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 11482
            .lvl = 49,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 11485
    [DIFFICULTY_NORMAL][TRAINER_YOUNGSTER_CORDELL] =
    {
#line 11486
        .trainerName = _("CORDELL"),
#line 11487
        .trainerClass = TRAINER_CLASS_YOUNGSTER,
#line 11488
        .trainerPic = TRAINER_PIC_YOUNGSTER,
        .encounterMusic_gender =
#line 11490
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 11491
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 11492
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 11494
            .species = SPECIES_FARFETCHD,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11496
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 11495
            .lvl = 48,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 11498
            .species = SPECIES_FARFETCHD,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11500
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 11499
            .lvl = 48,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 11502
    [DIFFICULTY_NORMAL][TRAINER_LASS_DALIA] =
    {
#line 11503
        .trainerName = _("DALIA"),
#line 11504
        .trainerClass = TRAINER_CLASS_LASS,
#line 11505
        .trainerPic = TRAINER_PIC_LASS,
        .encounterMusic_gender =
#line 11507
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
#line 11508
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 11509
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 4,
        .party = (const struct TrainerMon[])
        {
            {
#line 11511
            .species = SPECIES_HOPPIP,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11513
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 11512
            .lvl = 46,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 11515
            .species = SPECIES_HOPPIP,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11517
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 11516
            .lvl = 47,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 11519
            .species = SPECIES_SKIPLOOM,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11521
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 11520
            .lvl = 47,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 11523
            .species = SPECIES_SKIPLOOM,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11525
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 11524
            .lvl = 48,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 11527
    [DIFFICULTY_NORMAL][TRAINER_LASS_JOANA] =
    {
#line 11528
        .trainerName = _("JOANA"),
#line 11529
        .trainerClass = TRAINER_CLASS_LASS,
#line 11530
        .trainerPic = TRAINER_PIC_LASS,
        .encounterMusic_gender =
#line 11532
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
#line 11533
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 11534
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 11536
            .species = SPECIES_SNUBBULL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11538
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 11537
            .lvl = 49,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 11540
    [DIFFICULTY_NORMAL][TRAINER_CAMPER_RILEY] =
    {
#line 11541
        .trainerName = _("RILEY"),
#line 11542
        .trainerClass = TRAINER_CLASS_CAMPER,
#line 11543
        .trainerPic = TRAINER_PIC_CAMPER,
        .encounterMusic_gender =
#line 11545
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 11546
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 11547
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 11549
            .species = SPECIES_PINSIR,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11551
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 11550
            .lvl = 49,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 11553
            .species = SPECIES_HERACROSS,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11555
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 11554
            .lvl = 50,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 11557
    [DIFFICULTY_NORMAL][TRAINER_PICNICKER_MARCY] =
    {
#line 11558
        .trainerName = _("MARCY"),
#line 11559
        .trainerClass = TRAINER_CLASS_PICNICKER,
#line 11560
        .trainerPic = TRAINER_PIC_PICNICKER,
        .encounterMusic_gender =
#line 11562
            TRAINER_ENCOUNTER_MUSIC_GIRL,
#line 11563
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 11564
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 11566
            .species = SPECIES_PARAS,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11568
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 11567
            .lvl = 48,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 11570
            .species = SPECIES_PARAS,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11572
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 11571
            .lvl = 48,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 11574
            .species = SPECIES_PARASECT,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11576
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 11575
            .lvl = 49,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 11578
    [DIFFICULTY_NORMAL][TRAINER_RUIN_MANIAC_LAYTON] =
    {
#line 11579
        .trainerName = _("LAYTON"),
#line 11580
        .trainerClass = TRAINER_CLASS_RUIN_MANIAC,
#line 11581
        .trainerPic = TRAINER_PIC_RUIN_MANIAC,
        .encounterMusic_gender =
#line 11583
            TRAINER_ENCOUNTER_MUSIC_HIKER,
#line 11584
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 11585
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 11587
            .species = SPECIES_SANDSLASH,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11589
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 11588
            .lvl = 48,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 11591
            .species = SPECIES_ONIX,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11593
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 11592
            .lvl = 48,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 11595
            .species = SPECIES_SANDSLASH,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11597
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 11596
            .lvl = 48,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 11599
    [DIFFICULTY_NORMAL][TRAINER_PICNICKER_KELSEY_2] =
    {
#line 11600
        .trainerName = _("KELSEY"),
#line 11601
        .trainerClass = TRAINER_CLASS_PICNICKER,
#line 11602
        .trainerPic = TRAINER_PIC_PICNICKER,
        .encounterMusic_gender =
#line 11604
            TRAINER_ENCOUNTER_MUSIC_GIRL,
#line 11605
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 11606
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 11608
            .species = SPECIES_NIDORAN_M,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11610
            .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
#line 11609
            .lvl = 21,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 11612
            .species = SPECIES_NIDORAN_F,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11614
            .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
#line 11613
            .lvl = 21,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 11616
    [DIFFICULTY_NORMAL][TRAINER_PICNICKER_KELSEY_3] =
    {
#line 11617
        .trainerName = _("KELSEY"),
#line 11618
        .trainerClass = TRAINER_CLASS_PICNICKER,
#line 11619
        .trainerPic = TRAINER_PIC_PICNICKER,
        .encounterMusic_gender =
#line 11621
            TRAINER_ENCOUNTER_MUSIC_GIRL,
#line 11622
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 11623
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 11625
            .species = SPECIES_NIDORINO,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11627
            .iv = TRAINER_PARTY_IVS(7, 7, 7, 7, 7, 7),
#line 11626
            .lvl = 29,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 11629
            .species = SPECIES_NIDORINA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11631
            .iv = TRAINER_PARTY_IVS(7, 7, 7, 7, 7, 7),
#line 11630
            .lvl = 29,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 11633
    [DIFFICULTY_NORMAL][TRAINER_PICNICKER_KELSEY_4] =
    {
#line 11634
        .trainerName = _("KELSEY"),
#line 11635
        .trainerClass = TRAINER_CLASS_PICNICKER,
#line 11636
        .trainerPic = TRAINER_PIC_PICNICKER,
        .encounterMusic_gender =
#line 11638
            TRAINER_ENCOUNTER_MUSIC_GIRL,
#line 11639
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 11640
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 11642
            .species = SPECIES_NIDORINO,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11644
            .iv = TRAINER_PARTY_IVS(9, 9, 9, 9, 9, 9),
#line 11643
            .lvl = 49,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 11646
            .species = SPECIES_NIDORINA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11648
            .iv = TRAINER_PARTY_IVS(9, 9, 9, 9, 9, 9),
#line 11647
            .lvl = 49,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 11650
    [DIFFICULTY_NORMAL][TRAINER_CAMPER_RICKY_2] =
    {
#line 11651
        .trainerName = _("RICKY"),
#line 11652
        .trainerClass = TRAINER_CLASS_CAMPER,
#line 11653
        .trainerPic = TRAINER_PIC_CAMPER,
        .encounterMusic_gender =
#line 11655
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 11656
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 11657
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 11659
            .species = SPECIES_SQUIRTLE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11661
            .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
#line 11660
            .lvl = 22,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 11663
    [DIFFICULTY_NORMAL][TRAINER_CAMPER_RICKY_3] =
    {
#line 11664
        .trainerName = _("RICKY"),
#line 11665
        .trainerClass = TRAINER_CLASS_CAMPER,
#line 11666
        .trainerPic = TRAINER_PIC_CAMPER,
        .encounterMusic_gender =
#line 11668
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 11669
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 11670
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 11672
            .species = SPECIES_WARTORTLE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11674
            .iv = TRAINER_PARTY_IVS(7, 7, 7, 7, 7, 7),
#line 11673
            .lvl = 30,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 11676
    [DIFFICULTY_NORMAL][TRAINER_CAMPER_RICKY_4] =
    {
#line 11677
        .trainerName = _("RICKY"),
#line 11678
        .trainerClass = TRAINER_CLASS_CAMPER,
#line 11679
        .trainerPic = TRAINER_PIC_CAMPER,
        .encounterMusic_gender =
#line 11681
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 11682
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 11683
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 11685
            .species = SPECIES_WARTORTLE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11687
            .iv = TRAINER_PARTY_IVS(14, 14, 14, 14, 14, 14),
#line 11686
            .lvl = 55,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 11689
    [DIFFICULTY_NORMAL][TRAINER_CAMPER_JEFF_2] =
    {
#line 11690
        .trainerName = _("JEFF"),
#line 11691
        .trainerClass = TRAINER_CLASS_CAMPER,
#line 11692
        .trainerPic = TRAINER_PIC_CAMPER,
        .encounterMusic_gender =
#line 11694
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 11695
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 11696
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 11698
            .species = SPECIES_SPEAROW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11700
            .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
#line 11699
            .lvl = 21,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 11702
            .species = SPECIES_RATICATE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11704
            .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
#line 11703
            .lvl = 21,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 11706
    [DIFFICULTY_NORMAL][TRAINER_CAMPER_JEFF_3] =
    {
#line 11707
        .trainerName = _("JEFF"),
#line 11708
        .trainerClass = TRAINER_CLASS_CAMPER,
#line 11709
        .trainerPic = TRAINER_PIC_CAMPER,
        .encounterMusic_gender =
#line 11711
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 11712
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 11713
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 11715
            .species = SPECIES_FEAROW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11717
            .iv = TRAINER_PARTY_IVS(7, 7, 7, 7, 7, 7),
#line 11716
            .lvl = 29,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 11719
            .species = SPECIES_RATICATE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11721
            .iv = TRAINER_PARTY_IVS(7, 7, 7, 7, 7, 7),
#line 11720
            .lvl = 29,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 11723
    [DIFFICULTY_NORMAL][TRAINER_CAMPER_JEFF_4] =
    {
#line 11724
        .trainerName = _("JEFF"),
#line 11725
        .trainerClass = TRAINER_CLASS_CAMPER,
#line 11726
        .trainerPic = TRAINER_PIC_CAMPER,
        .encounterMusic_gender =
#line 11728
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 11729
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 11730
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 11732
            .species = SPECIES_FEAROW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11734
            .iv = TRAINER_PARTY_IVS(14, 14, 14, 14, 14, 14),
#line 11733
            .lvl = 54,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 11736
            .species = SPECIES_RATICATE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11738
            .iv = TRAINER_PARTY_IVS(14, 14, 14, 14, 14, 14),
#line 11737
            .lvl = 54,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 11740
    [DIFFICULTY_NORMAL][TRAINER_PICNICKER_ISABELLE_2] =
    {
#line 11741
        .trainerName = _("ISABELLE"),
#line 11742
        .trainerClass = TRAINER_CLASS_PICNICKER,
#line 11743
        .trainerPic = TRAINER_PIC_PICNICKER,
        .encounterMusic_gender =
#line 11745
            TRAINER_ENCOUNTER_MUSIC_GIRL,
#line 11746
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 11747
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 11749
            .species = SPECIES_PIDGEOTTO,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11751
            .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
#line 11750
            .lvl = 21,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 11753
            .species = SPECIES_PIDGEOTTO,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11755
            .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
#line 11754
            .lvl = 21,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 11757
            .species = SPECIES_PIDGEY,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11759
            .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
#line 11758
            .lvl = 18,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 11761
    [DIFFICULTY_NORMAL][TRAINER_PICNICKER_ISABELLE_3] =
    {
#line 11762
        .trainerName = _("ISABELLE"),
#line 11763
        .trainerClass = TRAINER_CLASS_PICNICKER,
#line 11764
        .trainerPic = TRAINER_PIC_PICNICKER,
        .encounterMusic_gender =
#line 11766
            TRAINER_ENCOUNTER_MUSIC_GIRL,
#line 11767
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 11768
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 11770
            .species = SPECIES_PIDGEOTTO,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11772
            .iv = TRAINER_PARTY_IVS(7, 7, 7, 7, 7, 7),
#line 11771
            .lvl = 29,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 11774
            .species = SPECIES_PIDGEOTTO,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11776
            .iv = TRAINER_PARTY_IVS(7, 7, 7, 7, 7, 7),
#line 11775
            .lvl = 29,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 11778
            .species = SPECIES_PIDGEOTTO,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11780
            .iv = TRAINER_PARTY_IVS(7, 7, 7, 7, 7, 7),
#line 11779
            .lvl = 26,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 11782
    [DIFFICULTY_NORMAL][TRAINER_PICNICKER_ISABELLE_4] =
    {
#line 11783
        .trainerName = _("ISABELLE"),
#line 11784
        .trainerClass = TRAINER_CLASS_PICNICKER,
#line 11785
        .trainerPic = TRAINER_PIC_PICNICKER,
        .encounterMusic_gender =
#line 11787
            TRAINER_ENCOUNTER_MUSIC_GIRL,
#line 11788
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 11789
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 11791
            .species = SPECIES_PIDGEOTTO,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11793
            .iv = TRAINER_PARTY_IVS(9, 9, 9, 9, 9, 9),
#line 11792
            .lvl = 47,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 11795
            .species = SPECIES_PIDGEOTTO,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11797
            .iv = TRAINER_PARTY_IVS(9, 9, 9, 9, 9, 9),
#line 11796
            .lvl = 47,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 11799
            .species = SPECIES_PIDGEOT,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11801
            .iv = TRAINER_PARTY_IVS(9, 9, 9, 9, 9, 9),
#line 11800
            .lvl = 50,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 11803
    [DIFFICULTY_NORMAL][TRAINER_YOUNGSTER_YASU_2] =
    {
#line 11804
        .trainerName = _("YASU"),
#line 11805
        .trainerClass = TRAINER_CLASS_YOUNGSTER,
#line 11806
        .trainerPic = TRAINER_PIC_YOUNGSTER,
        .encounterMusic_gender =
#line 11808
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 11809
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 11810
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 11812
            .species = SPECIES_RATTATA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11814
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
#line 11813
            .lvl = 22,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 11816
            .species = SPECIES_RATICATE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11818
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
#line 11817
            .lvl = 22,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 11820
            .species = SPECIES_RATICATE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11822
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
#line 11821
            .lvl = 22,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 11824
    [DIFFICULTY_NORMAL][TRAINER_YOUNGSTER_YASU_3] =
    {
#line 11825
        .trainerName = _("YASU"),
#line 11826
        .trainerClass = TRAINER_CLASS_YOUNGSTER,
#line 11827
        .trainerPic = TRAINER_PIC_YOUNGSTER,
        .encounterMusic_gender =
#line 11829
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 11830
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 11831
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 11833
            .species = SPECIES_RATICATE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11835
            .iv = TRAINER_PARTY_IVS(9, 9, 9, 9, 9, 9),
#line 11834
            .lvl = 47,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 11837
            .species = SPECIES_RATICATE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11839
            .iv = TRAINER_PARTY_IVS(9, 9, 9, 9, 9, 9),
#line 11838
            .lvl = 47,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 11841
            .species = SPECIES_RATICATE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11843
            .iv = TRAINER_PARTY_IVS(9, 9, 9, 9, 9, 9),
#line 11842
            .lvl = 47,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 11845
    [DIFFICULTY_NORMAL][TRAINER_ENGINEER_BERNIE_2] =
    {
#line 11846
        .trainerName = _("BERNIE"),
#line 11847
        .trainerClass = TRAINER_CLASS_ENGINEER,
#line 11848
        .trainerPic = TRAINER_PIC_ENGINEER,
        .encounterMusic_gender =
#line 11850
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 11851
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 11852
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 11854
            .species = SPECIES_MAGNETON,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11856
            .iv = TRAINER_PARTY_IVS(7, 7, 7, 7, 7, 7),
#line 11855
            .lvl = 28,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 11858
            .species = SPECIES_MAGNETON,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11860
            .iv = TRAINER_PARTY_IVS(7, 7, 7, 7, 7, 7),
#line 11859
            .lvl = 28,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 11862
            .species = SPECIES_MAGNETON,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11864
            .iv = TRAINER_PARTY_IVS(7, 7, 7, 7, 7, 7),
#line 11863
            .lvl = 28,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 11866
    [DIFFICULTY_NORMAL][TRAINER_GAMER_DARIAN_2] =
    {
#line 11867
        .trainerName = _("DARIAN"),
#line 11868
        .trainerClass = TRAINER_CLASS_GAMER,
#line 11869
        .trainerPic = TRAINER_PIC_GAMER,
        .encounterMusic_gender =
#line 11871
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 11872
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 11873
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 11875
            .species = SPECIES_GROWLITHE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11877
            .iv = TRAINER_PARTY_IVS(7, 7, 7, 7, 7, 7),
#line 11876
            .lvl = 29,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 11879
            .species = SPECIES_VULPIX,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11881
            .iv = TRAINER_PARTY_IVS(7, 7, 7, 7, 7, 7),
#line 11880
            .lvl = 29,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 11883
    [DIFFICULTY_NORMAL][TRAINER_CAMPER_CHRIS_2] =
    {
#line 11884
        .trainerName = _("CHRIS"),
#line 11885
        .trainerClass = TRAINER_CLASS_CAMPER,
#line 11886
        .trainerPic = TRAINER_PIC_CAMPER,
        .encounterMusic_gender =
#line 11888
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 11889
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 11890
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 11892
            .species = SPECIES_GROWLITHE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11894
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
#line 11893
            .lvl = 24,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 11896
            .species = SPECIES_CHARMANDER,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11898
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
#line 11897
            .lvl = 24,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 11900
    [DIFFICULTY_NORMAL][TRAINER_CAMPER_CHRIS_3] =
    {
#line 11901
        .trainerName = _("CHRIS"),
#line 11902
        .trainerClass = TRAINER_CLASS_CAMPER,
#line 11903
        .trainerPic = TRAINER_PIC_CAMPER,
        .encounterMusic_gender =
#line 11905
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 11906
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 11907
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 11909
            .species = SPECIES_GROWLITHE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11911
            .iv = TRAINER_PARTY_IVS(7, 7, 7, 7, 7, 7),
#line 11910
            .lvl = 29,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 11913
            .species = SPECIES_CHARMELEON,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11915
            .iv = TRAINER_PARTY_IVS(7, 7, 7, 7, 7, 7),
#line 11914
            .lvl = 29,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 11917
    [DIFFICULTY_NORMAL][TRAINER_CAMPER_CHRIS_4] =
    {
#line 11918
        .trainerName = _("CHRIS"),
#line 11919
        .trainerClass = TRAINER_CLASS_CAMPER,
#line 11920
        .trainerPic = TRAINER_PIC_CAMPER,
        .encounterMusic_gender =
#line 11922
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 11923
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 11924
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 11926
            .species = SPECIES_ARCANINE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11928
            .iv = TRAINER_PARTY_IVS(14, 14, 14, 14, 14, 14),
#line 11927
            .lvl = 54,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 11930
            .species = SPECIES_CHARMELEON,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11932
            .iv = TRAINER_PARTY_IVS(14, 14, 14, 14, 14, 14),
#line 11931
            .lvl = 54,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 11934
    [DIFFICULTY_NORMAL][TRAINER_PICNICKER_ALICIA_2] =
    {
#line 11935
        .trainerName = _("ALICIA"),
#line 11936
        .trainerClass = TRAINER_CLASS_PICNICKER,
#line 11937
        .trainerPic = TRAINER_PIC_PICNICKER,
        .encounterMusic_gender =
#line 11939
            TRAINER_ENCOUNTER_MUSIC_GIRL,
#line 11940
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 11941
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 11943
            .species = SPECIES_MEOWTH,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11945
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
#line 11944
            .lvl = 25,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 11947
    [DIFFICULTY_NORMAL][TRAINER_PICNICKER_ALICIA_3] =
    {
#line 11948
        .trainerName = _("ALICIA"),
#line 11949
        .trainerClass = TRAINER_CLASS_PICNICKER,
#line 11950
        .trainerPic = TRAINER_PIC_PICNICKER,
        .encounterMusic_gender =
#line 11952
            TRAINER_ENCOUNTER_MUSIC_GIRL,
#line 11953
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 11954
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 11956
            .species = SPECIES_PERSIAN,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11958
            .iv = TRAINER_PARTY_IVS(7, 7, 7, 7, 7, 7),
#line 11957
            .lvl = 30,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 11960
    [DIFFICULTY_NORMAL][TRAINER_PICNICKER_ALICIA_4] =
    {
#line 11961
        .trainerName = _("ALICIA"),
#line 11962
        .trainerClass = TRAINER_CLASS_PICNICKER,
#line 11963
        .trainerPic = TRAINER_PIC_PICNICKER,
        .encounterMusic_gender =
#line 11965
            TRAINER_ENCOUNTER_MUSIC_GIRL,
#line 11966
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 11967
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 11969
            .species = SPECIES_PERSIAN,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11971
            .iv = TRAINER_PARTY_IVS(14, 14, 14, 14, 14, 14),
#line 11970
            .lvl = 55,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 11973
    [DIFFICULTY_NORMAL][TRAINER_HIKER_JEREMY_2] =
    {
#line 11974
        .trainerName = _("JEREMY"),
#line 11975
        .trainerClass = TRAINER_CLASS_HIKER,
#line 11976
        .trainerPic = TRAINER_PIC_HIKER,
        .encounterMusic_gender =
#line 11978
            TRAINER_ENCOUNTER_MUSIC_HIKER,
#line 11979
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 11980
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 11982
            .species = SPECIES_MACHOKE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11984
            .iv = TRAINER_PARTY_IVS(7, 7, 7, 7, 7, 7),
#line 11983
            .lvl = 30,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 11986
            .species = SPECIES_ONIX,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11988
            .iv = TRAINER_PARTY_IVS(7, 7, 7, 7, 7, 7),
#line 11987
            .lvl = 28,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 11990
    [DIFFICULTY_NORMAL][TRAINER_POKEMANIAC_MARK_3] =
    {
#line 11991
        .trainerName = _("MARK"),
#line 11992
        .trainerClass = TRAINER_CLASS_POKEMANIAC,
#line 11993
        .trainerPic = TRAINER_PIC_POKEMANIAC,
        .encounterMusic_gender =
#line 11995
            TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
#line 11996
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 11997
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 11999
            .species = SPECIES_RHYDON,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12001
            .iv = TRAINER_PARTY_IVS(18, 18, 18, 18, 18, 18),
#line 12000
            .lvl = 54,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 12003
            .species = SPECIES_LICKITUNG,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12005
            .iv = TRAINER_PARTY_IVS(18, 18, 18, 18, 18, 18),
#line 12004
            .lvl = 54,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 12007
    [DIFFICULTY_NORMAL][TRAINER_POKEMANIAC_HERMAN_2] =
    {
#line 12008
        .trainerName = _("HERMAN"),
#line 12009
        .trainerClass = TRAINER_CLASS_POKEMANIAC,
#line 12010
        .trainerPic = TRAINER_PIC_POKEMANIAC,
        .encounterMusic_gender =
#line 12012
            TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
#line 12013
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 12014
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 12016
            .species = SPECIES_MAROWAK,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12018
            .iv = TRAINER_PARTY_IVS(10, 10, 10, 10, 10, 10),
#line 12017
            .lvl = 29,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 12020
            .species = SPECIES_SLOWBRO,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12022
            .iv = TRAINER_PARTY_IVS(10, 10, 10, 10, 10, 10),
#line 12021
            .lvl = 29,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 12024
    [DIFFICULTY_NORMAL][TRAINER_POKEMANIAC_HERMAN_3] =
    {
#line 12025
        .trainerName = _("HERMAN"),
#line 12026
        .trainerClass = TRAINER_CLASS_POKEMANIAC,
#line 12027
        .trainerPic = TRAINER_PIC_POKEMANIAC,
        .encounterMusic_gender =
#line 12029
            TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
#line 12030
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 12031
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 12033
            .species = SPECIES_MAROWAK,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12035
            .iv = TRAINER_PARTY_IVS(18, 18, 18, 18, 18, 18),
#line 12034
            .lvl = 54,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 12037
            .species = SPECIES_SLOWBRO,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12039
            .iv = TRAINER_PARTY_IVS(18, 18, 18, 18, 18, 18),
#line 12038
            .lvl = 54,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 12041
    [DIFFICULTY_NORMAL][TRAINER_HIKER_TRENT_2] =
    {
#line 12042
        .trainerName = _("TRENT"),
#line 12043
        .trainerClass = TRAINER_CLASS_HIKER,
#line 12044
        .trainerPic = TRAINER_PIC_HIKER,
        .encounterMusic_gender =
#line 12046
            TRAINER_ENCOUNTER_MUSIC_HIKER,
#line 12047
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 12048
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 12050
            .species = SPECIES_ONIX,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12052
            .iv = TRAINER_PARTY_IVS(7, 7, 7, 7, 7, 7),
#line 12051
            .lvl = 31,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 12054
            .species = SPECIES_GRAVELER,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12056
            .iv = TRAINER_PARTY_IVS(7, 7, 7, 7, 7, 7),
#line 12055
            .lvl = 31,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 12058
    [DIFFICULTY_NORMAL][TRAINER_LASS_MEGAN_2] =
    {
#line 12059
        .trainerName = _("MEGAN"),
#line 12060
        .trainerClass = TRAINER_CLASS_LASS,
#line 12061
        .trainerPic = TRAINER_PIC_LASS,
        .encounterMusic_gender =
#line 12063
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
#line 12064
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 12065
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 5,
        .party = (const struct TrainerMon[])
        {
            {
#line 12067
            .species = SPECIES_PIDGEOTTO,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12069
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
#line 12068
            .lvl = 22,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 12071
            .species = SPECIES_RATICATE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12073
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
#line 12072
            .lvl = 22,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 12075
            .species = SPECIES_NIDORAN_M,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12077
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
#line 12076
            .lvl = 23,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 12079
            .species = SPECIES_MEOWTH,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12081
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
#line 12080
            .lvl = 21,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 12083
            .species = SPECIES_PIKACHU,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12085
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
#line 12084
            .lvl = 22,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 12087
    [DIFFICULTY_NORMAL][TRAINER_LASS_MEGAN_3] =
    {
#line 12088
        .trainerName = _("MEGAN"),
#line 12089
        .trainerClass = TRAINER_CLASS_LASS,
#line 12090
        .trainerPic = TRAINER_PIC_LASS,
        .encounterMusic_gender =
#line 12092
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
#line 12093
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 12094
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 5,
        .party = (const struct TrainerMon[])
        {
            {
#line 12096
            .species = SPECIES_PIDGEOT,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12098
            .iv = TRAINER_PARTY_IVS(9, 9, 9, 9, 9, 9),
#line 12097
            .lvl = 46,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 12100
            .species = SPECIES_RATICATE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12102
            .iv = TRAINER_PARTY_IVS(9, 9, 9, 9, 9, 9),
#line 12101
            .lvl = 47,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 12104
            .species = SPECIES_NIDORINO,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12106
            .iv = TRAINER_PARTY_IVS(9, 9, 9, 9, 9, 9),
#line 12105
            .lvl = 47,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 12108
            .species = SPECIES_PERSIAN,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12110
            .iv = TRAINER_PARTY_IVS(9, 9, 9, 9, 9, 9),
#line 12109
            .lvl = 47,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 12112
            .species = SPECIES_RAICHU,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12114
            .iv = TRAINER_PARTY_IVS(9, 9, 9, 9, 9, 9),
#line 12113
            .lvl = 48,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 12116
    [DIFFICULTY_NORMAL][TRAINER_SUPER_NERD_GLENN_2] =
    {
#line 12117
        .trainerName = _("GLENN"),
#line 12118
        .trainerClass = TRAINER_CLASS_SUPER_NERD,
#line 12119
        .trainerPic = TRAINER_PIC_SUPER_NERD,
        .encounterMusic_gender =
#line 12121
            TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
#line 12122
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 12123
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 12125
            .species = SPECIES_MUK,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12127
            .iv = TRAINER_PARTY_IVS(7, 7, 7, 7, 7, 7),
#line 12126
            .lvl = 28,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 12129
            .species = SPECIES_MUK,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12131
            .iv = TRAINER_PARTY_IVS(7, 7, 7, 7, 7, 7),
#line 12130
            .lvl = 28,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 12133
            .species = SPECIES_MUK,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12135
            .iv = TRAINER_PARTY_IVS(7, 7, 7, 7, 7, 7),
#line 12134
            .lvl = 28,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 12137
    [DIFFICULTY_NORMAL][TRAINER_GAMER_RICH_2] =
    {
#line 12138
        .trainerName = _("RICH"),
#line 12139
        .trainerClass = TRAINER_CLASS_GAMER,
#line 12140
        .trainerPic = TRAINER_PIC_GAMER,
        .encounterMusic_gender =
#line 12142
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 12143
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 12144
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 12146
            .species = SPECIES_GROWLITHE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12148
            .iv = TRAINER_PARTY_IVS(7, 7, 7, 7, 7, 7),
#line 12147
            .lvl = 30,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 12150
            .species = SPECIES_VULPIX,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12152
            .iv = TRAINER_PARTY_IVS(7, 7, 7, 7, 7, 7),
#line 12151
            .lvl = 30,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 12154
    [DIFFICULTY_NORMAL][TRAINER_BIKER_JAREN_2] =
    {
#line 12155
        .trainerName = _("JAREN"),
#line 12156
        .trainerClass = TRAINER_CLASS_BIKER,
#line 12157
        .trainerPic = TRAINER_PIC_BIKER,
        .encounterMusic_gender =
#line 12159
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 12160
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 12161
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 12163
            .species = SPECIES_MUK,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12165
            .iv = TRAINER_PARTY_IVS(7, 7, 7, 7, 7, 7),
#line 12164
            .lvl = 28,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 12167
            .species = SPECIES_MUK,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12169
            .iv = TRAINER_PARTY_IVS(7, 7, 7, 7, 7, 7),
#line 12168
            .lvl = 30,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 12171
    [DIFFICULTY_NORMAL][TRAINER_FISHERMAN_ELLIOT_2] =
    {
#line 12172
        .trainerName = _("ELLIOT"),
#line 12173
        .trainerClass = TRAINER_CLASS_FISHERMAN,
#line 12174
        .trainerPic = TRAINER_PIC_FISHERMAN,
        .encounterMusic_gender =
#line 12176
            TRAINER_ENCOUNTER_MUSIC_HIKER,
#line 12177
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 12178
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 4,
        .party = (const struct TrainerMon[])
        {
            {
#line 12180
            .species = SPECIES_POLIWHIRL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12182
            .iv = TRAINER_PARTY_IVS(7, 7, 7, 7, 7, 7),
#line 12181
            .lvl = 28,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 12184
            .species = SPECIES_CLOYSTER,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12186
            .iv = TRAINER_PARTY_IVS(7, 7, 7, 7, 7, 7),
#line 12185
            .lvl = 28,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 12188
            .species = SPECIES_SEAKING,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12190
            .iv = TRAINER_PARTY_IVS(7, 7, 7, 7, 7, 7),
#line 12189
            .lvl = 28,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 12192
            .species = SPECIES_SEADRA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12194
            .iv = TRAINER_PARTY_IVS(7, 7, 7, 7, 7, 7),
#line 12193
            .lvl = 28,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 12196
    [DIFFICULTY_NORMAL][TRAINER_ROCKER_LUCA_2] =
    {
#line 12197
        .trainerName = _("LUCA"),
#line 12198
        .trainerClass = TRAINER_CLASS_ROCKER,
#line 12199
        .trainerPic = TRAINER_PIC_ROCKER,
        .encounterMusic_gender =
#line 12201
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 12202
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 12203
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 12205
            .species = SPECIES_ELECTRODE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12207
            .iv = TRAINER_PARTY_IVS(7, 7, 7, 7, 7, 7),
#line 12206
            .lvl = 33,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 12209
            .species = SPECIES_ELECTRODE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12211
            .iv = TRAINER_PARTY_IVS(7, 7, 7, 7, 7, 7),
#line 12210
            .lvl = 33,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 12213
    [DIFFICULTY_NORMAL][TRAINER_BEAUTY_SHEILA_2] =
    {
#line 12214
        .trainerName = _("SHEILA"),
#line 12215
        .trainerClass = TRAINER_CLASS_BEAUTY,
#line 12216
        .trainerPic = TRAINER_PIC_BEAUTY,
        .encounterMusic_gender =
#line 12218
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
#line 12219
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 12220
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 12222
            .species = SPECIES_CLEFAIRY,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12224
            .iv = TRAINER_PARTY_IVS(9, 9, 9, 9, 9, 9),
#line 12223
            .lvl = 49,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 12226
            .species = SPECIES_PERSIAN,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12228
            .iv = TRAINER_PARTY_IVS(9, 9, 9, 9, 9, 9),
#line 12227
            .lvl = 49,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 12230
    [DIFFICULTY_NORMAL][TRAINER_BIRD_KEEPER_ROBERT_2] =
    {
#line 12231
        .trainerName = _("ROBERT"),
#line 12232
        .trainerClass = TRAINER_CLASS_BIRD_KEEPER,
#line 12233
        .trainerPic = TRAINER_PIC_BIRD_KEEPER,
        .encounterMusic_gender =
#line 12235
            TRAINER_ENCOUNTER_MUSIC_COOL,
#line 12236
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 12237
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 4,
        .party = (const struct TrainerMon[])
        {
            {
#line 12239
            .species = SPECIES_PIDGEOTTO,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12241
            .iv = TRAINER_PARTY_IVS(7, 7, 7, 7, 7, 7),
#line 12240
            .lvl = 28,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 12243
            .species = SPECIES_PIDGEOTTO,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12245
            .iv = TRAINER_PARTY_IVS(7, 7, 7, 7, 7, 7),
#line 12244
            .lvl = 28,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 12247
            .species = SPECIES_FEAROW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12249
            .iv = TRAINER_PARTY_IVS(7, 7, 7, 7, 7, 7),
#line 12248
            .lvl = 28,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 12251
            .species = SPECIES_FEAROW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12253
            .iv = TRAINER_PARTY_IVS(7, 7, 7, 7, 7, 7),
#line 12252
            .lvl = 28,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 12255
    [DIFFICULTY_NORMAL][TRAINER_BIRD_KEEPER_ROBERT_3] =
    {
#line 12256
        .trainerName = _("ROBERT"),
#line 12257
        .trainerClass = TRAINER_CLASS_BIRD_KEEPER,
#line 12258
        .trainerPic = TRAINER_PIC_BIRD_KEEPER,
        .encounterMusic_gender =
#line 12260
            TRAINER_ENCOUNTER_MUSIC_COOL,
#line 12261
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 12262
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 4,
        .party = (const struct TrainerMon[])
        {
            {
#line 12264
            .species = SPECIES_PIDGEOT,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12266
            .iv = TRAINER_PARTY_IVS(9, 9, 9, 9, 9, 9),
#line 12265
            .lvl = 47,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 12268
            .species = SPECIES_PIDGEOT,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12270
            .iv = TRAINER_PARTY_IVS(9, 9, 9, 9, 9, 9),
#line 12269
            .lvl = 47,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 12272
            .species = SPECIES_FEAROW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12274
            .iv = TRAINER_PARTY_IVS(9, 9, 9, 9, 9, 9),
#line 12273
            .lvl = 47,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 12276
            .species = SPECIES_FEAROW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12278
            .iv = TRAINER_PARTY_IVS(9, 9, 9, 9, 9, 9),
#line 12277
            .lvl = 47,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 12280
    [DIFFICULTY_NORMAL][TRAINER_PICNICKER_SUSIE_2] =
    {
#line 12281
        .trainerName = _("SUSIE"),
#line 12282
        .trainerClass = TRAINER_CLASS_PICNICKER,
#line 12283
        .trainerPic = TRAINER_PIC_PICNICKER,
        .encounterMusic_gender =
#line 12285
            TRAINER_ENCOUNTER_MUSIC_GIRL,
#line 12286
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 12287
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 5,
        .party = (const struct TrainerMon[])
        {
            {
#line 12289
            .species = SPECIES_PIDGEOTTO,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12291
            .iv = TRAINER_PARTY_IVS(7, 7, 7, 7, 7, 7),
#line 12290
            .lvl = 27,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 12293
            .species = SPECIES_MEOWTH,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12295
            .iv = TRAINER_PARTY_IVS(7, 7, 7, 7, 7, 7),
#line 12294
            .lvl = 27,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 12297
            .species = SPECIES_RATICATE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12299
            .iv = TRAINER_PARTY_IVS(7, 7, 7, 7, 7, 7),
#line 12298
            .lvl = 27,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 12301
            .species = SPECIES_PIKACHU,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12303
            .iv = TRAINER_PARTY_IVS(7, 7, 7, 7, 7, 7),
#line 12302
            .lvl = 27,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 12305
            .species = SPECIES_MEOWTH,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12307
            .iv = TRAINER_PARTY_IVS(7, 7, 7, 7, 7, 7),
#line 12306
            .lvl = 27,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 12309
    [DIFFICULTY_NORMAL][TRAINER_PICNICKER_SUSIE_3] =
    {
#line 12310
        .trainerName = _("SUSIE"),
#line 12311
        .trainerClass = TRAINER_CLASS_PICNICKER,
#line 12312
        .trainerPic = TRAINER_PIC_PICNICKER,
        .encounterMusic_gender =
#line 12314
            TRAINER_ENCOUNTER_MUSIC_GIRL,
#line 12315
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 12316
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 5,
        .party = (const struct TrainerMon[])
        {
            {
#line 12318
            .species = SPECIES_PIDGEOTTO,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12320
            .iv = TRAINER_PARTY_IVS(9, 9, 9, 9, 9, 9),
#line 12319
            .lvl = 47,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 12322
            .species = SPECIES_PERSIAN,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12324
            .iv = TRAINER_PARTY_IVS(9, 9, 9, 9, 9, 9),
#line 12323
            .lvl = 47,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 12326
            .species = SPECIES_RATICATE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12328
            .iv = TRAINER_PARTY_IVS(9, 9, 9, 9, 9, 9),
#line 12327
            .lvl = 47,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 12330
            .species = SPECIES_PIKACHU,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12332
            .iv = TRAINER_PARTY_IVS(9, 9, 9, 9, 9, 9),
#line 12331
            .lvl = 47,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 12334
            .species = SPECIES_PERSIAN,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12336
            .iv = TRAINER_PARTY_IVS(9, 9, 9, 9, 9, 9),
#line 12335
            .lvl = 47,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 12338
    [DIFFICULTY_NORMAL][TRAINER_PICNICKER_SUSIE_4] =
    {
#line 12339
        .trainerName = _("SUSIE"),
#line 12340
        .trainerClass = TRAINER_CLASS_PICNICKER,
#line 12341
        .trainerPic = TRAINER_PIC_PICNICKER,
        .encounterMusic_gender =
#line 12343
            TRAINER_ENCOUNTER_MUSIC_GIRL,
#line 12344
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 12345
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 5,
        .party = (const struct TrainerMon[])
        {
            {
#line 12347
            .species = SPECIES_PIDGEOT,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12349
            .iv = TRAINER_PARTY_IVS(14, 14, 14, 14, 14, 14),
#line 12348
            .lvl = 52,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 12351
            .species = SPECIES_PERSIAN,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12353
            .iv = TRAINER_PARTY_IVS(14, 14, 14, 14, 14, 14),
#line 12352
            .lvl = 52,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 12355
            .species = SPECIES_RATICATE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12357
            .iv = TRAINER_PARTY_IVS(14, 14, 14, 14, 14, 14),
#line 12356
            .lvl = 52,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 12359
            .species = SPECIES_RAICHU,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12361
            .iv = TRAINER_PARTY_IVS(14, 14, 14, 14, 14, 14),
#line 12360
            .lvl = 52,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 12363
            .species = SPECIES_PERSIAN,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12365
            .iv = TRAINER_PARTY_IVS(14, 14, 14, 14, 14, 14),
#line 12364
            .lvl = 52,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 12367
    [DIFFICULTY_NORMAL][TRAINER_BIKER_LUKAS_2] =
    {
#line 12368
        .trainerName = _("LUKAS"),
#line 12369
        .trainerClass = TRAINER_CLASS_BIKER,
#line 12370
        .trainerPic = TRAINER_PIC_BIKER,
        .encounterMusic_gender =
#line 12372
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 12373
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 12374
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 4,
        .party = (const struct TrainerMon[])
        {
            {
#line 12376
            .species = SPECIES_KOFFING,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12378
            .iv = TRAINER_PARTY_IVS(9, 9, 9, 9, 9, 9),
#line 12377
            .lvl = 47,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 12380
            .species = SPECIES_KOFFING,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12382
            .iv = TRAINER_PARTY_IVS(9, 9, 9, 9, 9, 9),
#line 12381
            .lvl = 47,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 12384
            .species = SPECIES_MUK,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12386
            .iv = TRAINER_PARTY_IVS(9, 9, 9, 9, 9, 9),
#line 12385
            .lvl = 47,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 12388
            .species = SPECIES_WEEZING,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12390
            .iv = TRAINER_PARTY_IVS(9, 9, 9, 9, 9, 9),
#line 12389
            .lvl = 47,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 12392
    [DIFFICULTY_NORMAL][TRAINER_BIRD_KEEPER_BENNY_2] =
    {
#line 12393
        .trainerName = _("BENNY"),
#line 12394
        .trainerClass = TRAINER_CLASS_BIRD_KEEPER,
#line 12395
        .trainerPic = TRAINER_PIC_BIRD_KEEPER,
        .encounterMusic_gender =
#line 12397
            TRAINER_ENCOUNTER_MUSIC_COOL,
#line 12398
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 12399
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 12401
            .species = SPECIES_FEAROW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12403
            .iv = TRAINER_PARTY_IVS(7, 7, 7, 7, 7, 7),
#line 12402
            .lvl = 32,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 12405
            .species = SPECIES_FEAROW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12407
            .iv = TRAINER_PARTY_IVS(7, 7, 7, 7, 7, 7),
#line 12406
            .lvl = 32,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 12409
    [DIFFICULTY_NORMAL][TRAINER_BIRD_KEEPER_BENNY_3] =
    {
#line 12410
        .trainerName = _("BENNY"),
#line 12411
        .trainerClass = TRAINER_CLASS_BIRD_KEEPER,
#line 12412
        .trainerPic = TRAINER_PIC_BIRD_KEEPER,
        .encounterMusic_gender =
#line 12414
            TRAINER_ENCOUNTER_MUSIC_COOL,
#line 12415
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 12416
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 12418
            .species = SPECIES_FEAROW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12420
            .iv = TRAINER_PARTY_IVS(9, 9, 9, 9, 9, 9),
#line 12419
            .lvl = 49,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 12422
            .species = SPECIES_FEAROW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12424
            .iv = TRAINER_PARTY_IVS(9, 9, 9, 9, 9, 9),
#line 12423
            .lvl = 49,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 12426
    [DIFFICULTY_NORMAL][TRAINER_BIRD_KEEPER_MARLON_2] =
    {
#line 12427
        .trainerName = _("MARLON"),
#line 12428
        .trainerClass = TRAINER_CLASS_BIRD_KEEPER,
#line 12429
        .trainerPic = TRAINER_PIC_BIRD_KEEPER,
        .encounterMusic_gender =
#line 12431
            TRAINER_ENCOUNTER_MUSIC_COOL,
#line 12432
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 12433
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 12435
            .species = SPECIES_FEAROW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12437
            .iv = TRAINER_PARTY_IVS(7, 7, 7, 7, 7, 7),
#line 12436
            .lvl = 30,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 12439
            .species = SPECIES_DODUO,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12441
            .iv = TRAINER_PARTY_IVS(7, 7, 7, 7, 7, 7),
#line 12440
            .lvl = 30,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 12443
            .species = SPECIES_FEAROW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12445
            .iv = TRAINER_PARTY_IVS(7, 7, 7, 7, 7, 7),
#line 12444
            .lvl = 30,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 12447
    [DIFFICULTY_NORMAL][TRAINER_BIRD_KEEPER_MARLON_3] =
    {
#line 12448
        .trainerName = _("MARLON"),
#line 12449
        .trainerClass = TRAINER_CLASS_BIRD_KEEPER,
#line 12450
        .trainerPic = TRAINER_PIC_BIRD_KEEPER,
        .encounterMusic_gender =
#line 12452
            TRAINER_ENCOUNTER_MUSIC_COOL,
#line 12453
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 12454
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 12456
            .species = SPECIES_FEAROW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12458
            .iv = TRAINER_PARTY_IVS(9, 9, 9, 9, 9, 9),
#line 12457
            .lvl = 48,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 12460
            .species = SPECIES_DODRIO,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12462
            .iv = TRAINER_PARTY_IVS(9, 9, 9, 9, 9, 9),
#line 12461
            .lvl = 48,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 12464
            .species = SPECIES_FEAROW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12466
            .iv = TRAINER_PARTY_IVS(9, 9, 9, 9, 9, 9),
#line 12465
            .lvl = 48,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 12468
    [DIFFICULTY_NORMAL][TRAINER_BEAUTY_GRACE_2] =
    {
#line 12469
        .trainerName = _("GRACE"),
#line 12470
        .trainerClass = TRAINER_CLASS_BEAUTY,
#line 12471
        .trainerPic = TRAINER_PIC_BEAUTY,
        .encounterMusic_gender =
#line 12473
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
#line 12474
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 12475
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 12477
            .species = SPECIES_PIDGEOT,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12479
            .iv = TRAINER_PARTY_IVS(9, 9, 9, 9, 9, 9),
#line 12478
            .lvl = 49,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 12481
            .species = SPECIES_WIGGLYTUFF,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12483
            .iv = TRAINER_PARTY_IVS(9, 9, 9, 9, 9, 9),
#line 12482
            .lvl = 49,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 12485
    [DIFFICULTY_NORMAL][TRAINER_BIRD_KEEPER_CHESTER_2] =
    {
#line 12486
        .trainerName = _("CHESTER"),
#line 12487
        .trainerClass = TRAINER_CLASS_BIRD_KEEPER,
#line 12488
        .trainerPic = TRAINER_PIC_BIRD_KEEPER,
        .encounterMusic_gender =
#line 12490
            TRAINER_ENCOUNTER_MUSIC_COOL,
#line 12491
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 12492
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 12494
            .species = SPECIES_DODRIO,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12496
            .iv = TRAINER_PARTY_IVS(7, 7, 7, 7, 7, 7),
#line 12495
            .lvl = 30,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 12498
            .species = SPECIES_DODRIO,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12500
            .iv = TRAINER_PARTY_IVS(7, 7, 7, 7, 7, 7),
#line 12499
            .lvl = 30,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 12502
            .species = SPECIES_DODUO,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12504
            .iv = TRAINER_PARTY_IVS(7, 7, 7, 7, 7, 7),
#line 12503
            .lvl = 30,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 12506
    [DIFFICULTY_NORMAL][TRAINER_BIRD_KEEPER_CHESTER_3] =
    {
#line 12507
        .trainerName = _("CHESTER"),
#line 12508
        .trainerClass = TRAINER_CLASS_BIRD_KEEPER,
#line 12509
        .trainerPic = TRAINER_PIC_BIRD_KEEPER,
        .encounterMusic_gender =
#line 12511
            TRAINER_ENCOUNTER_MUSIC_COOL,
#line 12512
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 12513
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 12515
            .species = SPECIES_DODRIO,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12517
            .iv = TRAINER_PARTY_IVS(9, 9, 9, 9, 9, 9),
#line 12516
            .lvl = 48,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 12519
            .species = SPECIES_DODRIO,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12521
            .iv = TRAINER_PARTY_IVS(9, 9, 9, 9, 9, 9),
#line 12520
            .lvl = 48,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 12523
            .species = SPECIES_DODRIO,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12525
            .iv = TRAINER_PARTY_IVS(9, 9, 9, 9, 9, 9),
#line 12524
            .lvl = 48,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 12527
    [DIFFICULTY_NORMAL][TRAINER_PICNICKER_BECKY_2] =
    {
#line 12528
        .trainerName = _("BECKY"),
#line 12529
        .trainerClass = TRAINER_CLASS_PICNICKER,
#line 12530
        .trainerPic = TRAINER_PIC_PICNICKER,
        .encounterMusic_gender =
#line 12532
            TRAINER_ENCOUNTER_MUSIC_GIRL,
#line 12533
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 12534
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 12536
            .species = SPECIES_PIKACHU,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12538
            .iv = TRAINER_PARTY_IVS(7, 7, 7, 7, 7, 7),
#line 12537
            .lvl = 32,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 12540
            .species = SPECIES_RAICHU,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12542
            .iv = TRAINER_PARTY_IVS(7, 7, 7, 7, 7, 7),
#line 12541
            .lvl = 32,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 12544
    [DIFFICULTY_NORMAL][TRAINER_PICNICKER_BECKY_3] =
    {
#line 12545
        .trainerName = _("BECKY"),
#line 12546
        .trainerClass = TRAINER_CLASS_PICNICKER,
#line 12547
        .trainerPic = TRAINER_PIC_PICNICKER,
        .encounterMusic_gender =
#line 12549
            TRAINER_ENCOUNTER_MUSIC_GIRL,
#line 12550
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 12551
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 12553
            .species = SPECIES_PIKACHU,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12555
            .iv = TRAINER_PARTY_IVS(9, 9, 9, 9, 9, 9),
#line 12554
            .lvl = 49,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 12557
            .species = SPECIES_RAICHU,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12559
            .iv = TRAINER_PARTY_IVS(9, 9, 9, 9, 9, 9),
#line 12558
            .lvl = 49,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 12561
    [DIFFICULTY_NORMAL][TRAINER_PICNICKER_BECKY_4] =
    {
#line 12562
        .trainerName = _("BECKY"),
#line 12563
        .trainerClass = TRAINER_CLASS_PICNICKER,
#line 12564
        .trainerPic = TRAINER_PIC_PICNICKER,
        .encounterMusic_gender =
#line 12566
            TRAINER_ENCOUNTER_MUSIC_GIRL,
#line 12567
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 12568
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 12570
            .species = SPECIES_RAICHU,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12572
            .iv = TRAINER_PARTY_IVS(14, 14, 14, 14, 14, 14),
#line 12571
            .lvl = 54,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 12574
            .species = SPECIES_RAICHU,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12576
            .iv = TRAINER_PARTY_IVS(14, 14, 14, 14, 14, 14),
#line 12575
            .lvl = 54,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 12578
    [DIFFICULTY_NORMAL][TRAINER_CRUSH_KIN_RON_MYA_2] =
    {
#line 12579
        .trainerName = _("RON & MYA"),
#line 12580
        .trainerClass = TRAINER_CLASS_CRUSH_KIN,
#line 12581
        .trainerPic = TRAINER_PIC_CRUSH_KIN,
        .encounterMusic_gender =
#line 12583
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
#line 12584
        .battleType = TRAINER_BATTLE_TYPE_DOUBLES,
#line 12585
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 12587
            .species = SPECIES_HITMONCHAN,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12587
            .heldItem = ITEM_BLACK_BELT,
#line 12589
            .iv = TRAINER_PARTY_IVS(13, 13, 13, 13, 13, 13),
#line 12588
            .lvl = 33,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 12591
            .species = SPECIES_HITMONLEE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12591
            .heldItem = ITEM_BLACK_BELT,
#line 12593
            .iv = TRAINER_PARTY_IVS(13, 13, 13, 13, 13, 13),
#line 12592
            .lvl = 33,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 12595
    [DIFFICULTY_NORMAL][TRAINER_CRUSH_KIN_RON_MYA_3] =
    {
#line 12596
        .trainerName = _("RON & MYA"),
#line 12597
        .trainerClass = TRAINER_CLASS_CRUSH_KIN,
#line 12598
        .trainerPic = TRAINER_PIC_CRUSH_KIN,
        .encounterMusic_gender =
#line 12600
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
#line 12601
        .battleType = TRAINER_BATTLE_TYPE_DOUBLES,
#line 12602
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 12604
            .species = SPECIES_HITMONCHAN,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12604
            .heldItem = ITEM_BLACK_BELT,
#line 12606
            .iv = TRAINER_PARTY_IVS(15, 15, 15, 15, 15, 15),
#line 12605
            .lvl = 51,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 12608
            .species = SPECIES_HITMONLEE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12608
            .heldItem = ITEM_BLACK_BELT,
#line 12610
            .iv = TRAINER_PARTY_IVS(15, 15, 15, 15, 15, 15),
#line 12609
            .lvl = 51,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 12612
    [DIFFICULTY_NORMAL][TRAINER_CRUSH_KIN_RON_MYA_4] =
    {
#line 12613
        .trainerName = _("RON & MYA"),
#line 12614
        .trainerClass = TRAINER_CLASS_CRUSH_KIN,
#line 12615
        .trainerPic = TRAINER_PIC_CRUSH_KIN,
        .encounterMusic_gender =
#line 12617
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
#line 12618
        .battleType = TRAINER_BATTLE_TYPE_DOUBLES,
#line 12619
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 12621
            .species = SPECIES_HITMONCHAN,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12621
            .heldItem = ITEM_BLACK_BELT,
#line 12623
            .iv = TRAINER_PARTY_IVS(20, 20, 20, 20, 20, 20),
#line 12622
            .lvl = 56,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 12625
            .species = SPECIES_HITMONLEE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12625
            .heldItem = ITEM_BLACK_BELT,
#line 12627
            .iv = TRAINER_PARTY_IVS(20, 20, 20, 20, 20, 20),
#line 12626
            .lvl = 56,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 12629
    [DIFFICULTY_NORMAL][TRAINER_BIKER_RUBEN_2] =
    {
#line 12630
        .trainerName = _("RUBEN"),
#line 12631
        .trainerClass = TRAINER_CLASS_BIKER,
#line 12632
        .trainerPic = TRAINER_PIC_BIKER,
        .encounterMusic_gender =
#line 12634
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 12635
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 12636
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 12638
            .species = SPECIES_WEEZING,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12640
            .iv = TRAINER_PARTY_IVS(9, 9, 9, 9, 9, 9),
#line 12639
            .lvl = 48,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 12642
            .species = SPECIES_WEEZING,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12644
            .iv = TRAINER_PARTY_IVS(9, 9, 9, 9, 9, 9),
#line 12643
            .lvl = 48,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 12646
            .species = SPECIES_WEEZING,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12648
            .iv = TRAINER_PARTY_IVS(9, 9, 9, 9, 9, 9),
#line 12647
            .lvl = 48,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 12650
    [DIFFICULTY_NORMAL][TRAINER_CUE_BALL_CAMRON_2] =
    {
#line 12651
        .trainerName = _("CAMRON"),
#line 12652
        .trainerClass = TRAINER_CLASS_CUE_BALL,
#line 12653
        .trainerPic = TRAINER_PIC_CUE_BALL,
        .encounterMusic_gender =
#line 12655
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 12656
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 12657
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 12659
            .species = SPECIES_PRIMEAPE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12661
            .iv = TRAINER_PARTY_IVS(9, 9, 9, 9, 9, 9),
#line 12660
            .lvl = 49,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 12663
            .species = SPECIES_MACHOKE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12665
            .iv = TRAINER_PARTY_IVS(9, 9, 9, 9, 9, 9),
#line 12664
            .lvl = 49,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 12667
    [DIFFICULTY_NORMAL][TRAINER_BIKER_JAXON_2] =
    {
#line 12668
        .trainerName = _("JAXON"),
#line 12669
        .trainerClass = TRAINER_CLASS_BIKER,
#line 12670
        .trainerPic = TRAINER_PIC_BIKER,
        .encounterMusic_gender =
#line 12672
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 12673
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 12674
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 12676
            .species = SPECIES_WEEZING,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12678
            .iv = TRAINER_PARTY_IVS(9, 9, 9, 9, 9, 9),
#line 12677
            .lvl = 49,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 12680
            .species = SPECIES_MUK,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12682
            .iv = TRAINER_PARTY_IVS(9, 9, 9, 9, 9, 9),
#line 12681
            .lvl = 49,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 12684
    [DIFFICULTY_NORMAL][TRAINER_CUE_BALL_ISAIAH_2] =
    {
#line 12685
        .trainerName = _("ISAIAH"),
#line 12686
        .trainerClass = TRAINER_CLASS_CUE_BALL,
#line 12687
        .trainerPic = TRAINER_PIC_CUE_BALL,
        .encounterMusic_gender =
#line 12689
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 12690
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 12691
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 12693
            .species = SPECIES_MACHOKE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12695
            .iv = TRAINER_PARTY_IVS(9, 9, 9, 9, 9, 9),
#line 12694
            .lvl = 49,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 12697
            .species = SPECIES_MACHAMP,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12699
            .iv = TRAINER_PARTY_IVS(9, 9, 9, 9, 9, 9),
#line 12698
            .lvl = 49,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 12701
    [DIFFICULTY_NORMAL][TRAINER_CUE_BALL_COREY_2] =
    {
#line 12702
        .trainerName = _("COREY"),
#line 12703
        .trainerClass = TRAINER_CLASS_CUE_BALL,
#line 12704
        .trainerPic = TRAINER_PIC_CUE_BALL,
        .encounterMusic_gender =
#line 12706
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 12707
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 12708
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 12710
            .species = SPECIES_PRIMEAPE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12712
            .iv = TRAINER_PARTY_IVS(9, 9, 9, 9, 9, 9),
#line 12711
            .lvl = 49,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 12714
            .species = SPECIES_MACHAMP,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12716
            .iv = TRAINER_PARTY_IVS(9, 9, 9, 9, 9, 9),
#line 12715
            .lvl = 49,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 12718
    [DIFFICULTY_NORMAL][TRAINER_BIRD_KEEPER_JACOB_2] =
    {
#line 12719
        .trainerName = _("JACOB"),
#line 12720
        .trainerClass = TRAINER_CLASS_BIRD_KEEPER,
#line 12721
        .trainerPic = TRAINER_PIC_BIRD_KEEPER,
        .encounterMusic_gender =
#line 12723
            TRAINER_ENCOUNTER_MUSIC_COOL,
#line 12724
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 12725
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 4,
        .party = (const struct TrainerMon[])
        {
            {
#line 12727
            .species = SPECIES_FEAROW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12729
            .iv = TRAINER_PARTY_IVS(7, 7, 7, 7, 7, 7),
#line 12728
            .lvl = 28,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 12731
            .species = SPECIES_SPEAROW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12733
            .iv = TRAINER_PARTY_IVS(7, 7, 7, 7, 7, 7),
#line 12732
            .lvl = 28,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 12735
            .species = SPECIES_FEAROW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12737
            .iv = TRAINER_PARTY_IVS(7, 7, 7, 7, 7, 7),
#line 12736
            .lvl = 28,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 12739
            .species = SPECIES_SPEAROW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12741
            .iv = TRAINER_PARTY_IVS(7, 7, 7, 7, 7, 7),
#line 12740
            .lvl = 28,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 12743
    [DIFFICULTY_NORMAL][TRAINER_BIRD_KEEPER_JACOB_3] =
    {
#line 12744
        .trainerName = _("JACOB"),
#line 12745
        .trainerClass = TRAINER_CLASS_BIRD_KEEPER,
#line 12746
        .trainerPic = TRAINER_PIC_BIRD_KEEPER,
        .encounterMusic_gender =
#line 12748
            TRAINER_ENCOUNTER_MUSIC_COOL,
#line 12749
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 12750
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 4,
        .party = (const struct TrainerMon[])
        {
            {
#line 12752
            .species = SPECIES_FEAROW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12754
            .iv = TRAINER_PARTY_IVS(9, 9, 9, 9, 9, 9),
#line 12753
            .lvl = 47,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 12756
            .species = SPECIES_FEAROW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12758
            .iv = TRAINER_PARTY_IVS(9, 9, 9, 9, 9, 9),
#line 12757
            .lvl = 47,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 12760
            .species = SPECIES_FEAROW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12762
            .iv = TRAINER_PARTY_IVS(9, 9, 9, 9, 9, 9),
#line 12761
            .lvl = 47,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 12764
            .species = SPECIES_FEAROW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12766
            .iv = TRAINER_PARTY_IVS(9, 9, 9, 9, 9, 9),
#line 12765
            .lvl = 47,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 12768
    [DIFFICULTY_NORMAL][TRAINER_SWIMMER_FEMALE_ALICE_2] =
    {
#line 12769
        .trainerName = _("ALICE"),
#line 12770
        .trainerClass = TRAINER_CLASS_SWIMMER_F,
#line 12771
        .trainerPic = TRAINER_PIC_SWIMMER_F,
        .encounterMusic_gender =
#line 12773
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
#line 12774
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 12775
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 12777
            .species = SPECIES_SEAKING,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12779
            .iv = TRAINER_PARTY_IVS(9, 9, 9, 9, 9, 9),
#line 12778
            .lvl = 49,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 12781
            .species = SPECIES_SEAKING,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12783
            .iv = TRAINER_PARTY_IVS(9, 9, 9, 9, 9, 9),
#line 12782
            .lvl = 49,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 12785
    [DIFFICULTY_NORMAL][TRAINER_SWIMMER_MALE_DARRIN_2] =
    {
#line 12786
        .trainerName = _("DARRIN"),
#line 12787
        .trainerClass = TRAINER_CLASS_SWIMMER_M,
#line 12788
        .trainerPic = TRAINER_PIC_SWIMMER_M,
        .encounterMusic_gender =
#line 12790
            TRAINER_ENCOUNTER_MUSIC_SWIMMER,
#line 12791
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 12792
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 4,
        .party = (const struct TrainerMon[])
        {
            {
#line 12794
            .species = SPECIES_SEADRA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12796
            .iv = TRAINER_PARTY_IVS(14, 14, 14, 14, 14, 14),
#line 12795
            .lvl = 52,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 12798
            .species = SPECIES_SEADRA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12800
            .iv = TRAINER_PARTY_IVS(14, 14, 14, 14, 14, 14),
#line 12799
            .lvl = 52,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 12802
            .species = SPECIES_SEADRA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12804
            .iv = TRAINER_PARTY_IVS(14, 14, 14, 14, 14, 14),
#line 12803
            .lvl = 52,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 12806
            .species = SPECIES_SEADRA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12808
            .iv = TRAINER_PARTY_IVS(14, 14, 14, 14, 14, 14),
#line 12807
            .lvl = 52,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 12810
    [DIFFICULTY_NORMAL][TRAINER_PICNICKER_MISSY_2] =
    {
#line 12811
        .trainerName = _("MISSY"),
#line 12812
        .trainerClass = TRAINER_CLASS_PICNICKER,
#line 12813
        .trainerPic = TRAINER_PIC_PICNICKER,
        .encounterMusic_gender =
#line 12815
            TRAINER_ENCOUNTER_MUSIC_GIRL,
#line 12816
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 12817
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 12819
            .species = SPECIES_SEAKING,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12821
            .iv = TRAINER_PARTY_IVS(9, 9, 9, 9, 9, 9),
#line 12820
            .lvl = 49,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 12823
            .species = SPECIES_SEAKING,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12825
            .iv = TRAINER_PARTY_IVS(9, 9, 9, 9, 9, 9),
#line 12824
            .lvl = 49,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 12827
    [DIFFICULTY_NORMAL][TRAINER_PICNICKER_MISSY_3] =
    {
#line 12828
        .trainerName = _("MISSY"),
#line 12829
        .trainerClass = TRAINER_CLASS_PICNICKER,
#line 12830
        .trainerPic = TRAINER_PIC_PICNICKER,
        .encounterMusic_gender =
#line 12832
            TRAINER_ENCOUNTER_MUSIC_GIRL,
#line 12833
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 12834
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 12836
            .species = SPECIES_SEAKING,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12838
            .iv = TRAINER_PARTY_IVS(14, 14, 14, 14, 14, 14),
#line 12837
            .lvl = 54,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 12840
            .species = SPECIES_SEAKING,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12842
            .iv = TRAINER_PARTY_IVS(14, 14, 14, 14, 14, 14),
#line 12841
            .lvl = 54,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 12844
    [DIFFICULTY_NORMAL][TRAINER_FISHERMAN_WADE_2] =
    {
#line 12845
        .trainerName = _("WADE"),
#line 12846
        .trainerClass = TRAINER_CLASS_FISHERMAN,
#line 12847
        .trainerPic = TRAINER_PIC_FISHERMAN,
        .encounterMusic_gender =
#line 12849
            TRAINER_ENCOUNTER_MUSIC_HIKER,
#line 12850
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 12851
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 6,
        .party = (const struct TrainerMon[])
        {
            {
#line 12853
            .species = SPECIES_MAGIKARP,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12855
            .iv = TRAINER_PARTY_IVS(9, 9, 9, 9, 9, 9),
#line 12854
            .lvl = 47,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 12857
            .species = SPECIES_MAGIKARP,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12859
            .iv = TRAINER_PARTY_IVS(9, 9, 9, 9, 9, 9),
#line 12858
            .lvl = 47,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 12861
            .species = SPECIES_MAGIKARP,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12863
            .iv = TRAINER_PARTY_IVS(9, 9, 9, 9, 9, 9),
#line 12862
            .lvl = 47,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 12865
            .species = SPECIES_MAGIKARP,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12867
            .iv = TRAINER_PARTY_IVS(9, 9, 9, 9, 9, 9),
#line 12866
            .lvl = 47,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 12869
            .species = SPECIES_MAGIKARP,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12871
            .iv = TRAINER_PARTY_IVS(9, 9, 9, 9, 9, 9),
#line 12870
            .lvl = 47,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 12873
            .species = SPECIES_MAGIKARP,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12875
            .iv = TRAINER_PARTY_IVS(9, 9, 9, 9, 9, 9),
#line 12874
            .lvl = 47,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 12877
    [DIFFICULTY_NORMAL][TRAINER_SWIMMER_MALE_JACK_2] =
    {
#line 12878
        .trainerName = _("JACK"),
#line 12879
        .trainerClass = TRAINER_CLASS_SWIMMER_M,
#line 12880
        .trainerPic = TRAINER_PIC_SWIMMER_M,
        .encounterMusic_gender =
#line 12882
            TRAINER_ENCOUNTER_MUSIC_SWIMMER,
#line 12883
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 12884
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 12886
            .species = SPECIES_STARMIE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12888
            .iv = TRAINER_PARTY_IVS(9, 9, 9, 9, 9, 9),
#line 12887
            .lvl = 50,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 12890
    [DIFFICULTY_NORMAL][TRAINER_SIS_AND_BRO_LIL_IAN_2] =
    {
#line 12891
        .trainerName = _("LIL & IAN"),
#line 12892
        .trainerClass = TRAINER_CLASS_SIS_AND_BRO,
#line 12893
        .trainerPic = TRAINER_PIC_SIS_AND_BRO,
        .encounterMusic_gender =
#line 12895
            TRAINER_ENCOUNTER_MUSIC_SWIMMER,
#line 12896
        .battleType = TRAINER_BATTLE_TYPE_DOUBLES,
#line 12897
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 12899
            .species = SPECIES_SEADRA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12901
            .iv = TRAINER_PARTY_IVS(9, 9, 9, 9, 9, 9),
#line 12900
            .lvl = 50,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 12903
            .species = SPECIES_STARMIE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12905
            .iv = TRAINER_PARTY_IVS(9, 9, 9, 9, 9, 9),
#line 12904
            .lvl = 50,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 12907
    [DIFFICULTY_NORMAL][TRAINER_SIS_AND_BRO_LIL_IAN_3] =
    {
#line 12908
        .trainerName = _("LIL & IAN"),
#line 12909
        .trainerClass = TRAINER_CLASS_SIS_AND_BRO,
#line 12910
        .trainerPic = TRAINER_PIC_SIS_AND_BRO,
        .encounterMusic_gender =
#line 12912
            TRAINER_ENCOUNTER_MUSIC_SWIMMER,
#line 12913
        .battleType = TRAINER_BATTLE_TYPE_DOUBLES,
#line 12914
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 12916
            .species = SPECIES_SEADRA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12918
            .iv = TRAINER_PARTY_IVS(14, 14, 14, 14, 14, 14),
#line 12917
            .lvl = 55,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 12920
            .species = SPECIES_STARMIE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12922
            .iv = TRAINER_PARTY_IVS(14, 14, 14, 14, 14, 14),
#line 12921
            .lvl = 55,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 12924
    [DIFFICULTY_NORMAL][TRAINER_SWIMMER_MALE_FINN_2] =
    {
#line 12925
        .trainerName = _("FINN"),
#line 12926
        .trainerClass = TRAINER_CLASS_SWIMMER_M,
#line 12927
        .trainerPic = TRAINER_PIC_SWIMMER_M,
        .encounterMusic_gender =
#line 12929
            TRAINER_ENCOUNTER_MUSIC_SWIMMER,
#line 12930
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 12931
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 12933
            .species = SPECIES_STARMIE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12935
            .iv = TRAINER_PARTY_IVS(9, 9, 9, 9, 9, 9),
#line 12934
            .lvl = 50,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 12937
    [DIFFICULTY_NORMAL][TRAINER_CRUSH_GIRL_SHARON_2] =
    {
#line 12938
        .trainerName = _("SHARON"),
#line 12939
        .trainerClass = TRAINER_CLASS_CRUSH_GIRL,
#line 12940
        .trainerPic = TRAINER_PIC_CRUSH_GIRL,
        .encounterMusic_gender =
#line 12942
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
#line 12943
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 12944
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 12946
            .species = SPECIES_MANKEY,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12946
            .heldItem = ITEM_BLACK_BELT,
#line 12948
            .iv = TRAINER_PARTY_IVS(15, 15, 15, 15, 15, 15),
#line 12947
            .lvl = 50,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 12950
            .species = SPECIES_PRIMEAPE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12950
            .heldItem = ITEM_BLACK_BELT,
#line 12952
            .iv = TRAINER_PARTY_IVS(15, 15, 15, 15, 15, 15),
#line 12951
            .lvl = 50,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 12954
    [DIFFICULTY_NORMAL][TRAINER_CRUSH_GIRL_SHARON_3] =
    {
#line 12955
        .trainerName = _("SHARON"),
#line 12956
        .trainerClass = TRAINER_CLASS_CRUSH_GIRL,
#line 12957
        .trainerPic = TRAINER_PIC_CRUSH_GIRL,
        .encounterMusic_gender =
#line 12959
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
#line 12960
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 12961
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 12963
            .species = SPECIES_PRIMEAPE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12963
            .heldItem = ITEM_BLACK_BELT,
#line 12965
            .iv = TRAINER_PARTY_IVS(20, 20, 20, 20, 20, 20),
#line 12964
            .lvl = 55,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 12967
            .species = SPECIES_PRIMEAPE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12967
            .heldItem = ITEM_BLACK_BELT,
#line 12969
            .iv = TRAINER_PARTY_IVS(20, 20, 20, 20, 20, 20),
#line 12968
            .lvl = 55,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 12971
    [DIFFICULTY_NORMAL][TRAINER_CRUSH_GIRL_TANYA_2] =
    {
#line 12972
        .trainerName = _("TANYA"),
#line 12973
        .trainerClass = TRAINER_CLASS_CRUSH_GIRL,
#line 12974
        .trainerPic = TRAINER_PIC_CRUSH_GIRL,
        .encounterMusic_gender =
#line 12976
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
#line 12977
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 12978
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 12980
            .species = SPECIES_HITMONLEE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12980
            .heldItem = ITEM_BLACK_BELT,
#line 12982
            .iv = TRAINER_PARTY_IVS(15, 15, 15, 15, 15, 15),
#line 12981
            .lvl = 50,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 12984
            .species = SPECIES_HITMONCHAN,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12984
            .heldItem = ITEM_BLACK_BELT,
#line 12986
            .iv = TRAINER_PARTY_IVS(15, 15, 15, 15, 15, 15),
#line 12985
            .lvl = 50,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 12988
    [DIFFICULTY_NORMAL][TRAINER_CRUSH_GIRL_TANYA_3] =
    {
#line 12989
        .trainerName = _("TANYA"),
#line 12990
        .trainerClass = TRAINER_CLASS_CRUSH_GIRL,
#line 12991
        .trainerPic = TRAINER_PIC_CRUSH_GIRL,
        .encounterMusic_gender =
#line 12993
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
#line 12994
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 12995
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 12997
            .species = SPECIES_HITMONLEE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12997
            .heldItem = ITEM_BLACK_BELT,
#line 12999
            .iv = TRAINER_PARTY_IVS(20, 20, 20, 20, 20, 20),
#line 12998
            .lvl = 55,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 13001
            .species = SPECIES_HITMONCHAN,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13001
            .heldItem = ITEM_BLACK_BELT,
#line 13003
            .iv = TRAINER_PARTY_IVS(20, 20, 20, 20, 20, 20),
#line 13002
            .lvl = 55,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 13005
    [DIFFICULTY_NORMAL][TRAINER_BLACK_BELT_SHEA_2] =
    {
#line 13006
        .trainerName = _("SHEA"),
#line 13007
        .trainerClass = TRAINER_CLASS_BLACK_BELT,
#line 13008
        .trainerPic = TRAINER_PIC_BLACK_BELT,
        .encounterMusic_gender =
#line 13010
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
#line 13011
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 13012
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 13014
            .species = SPECIES_MACHOKE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13014
            .heldItem = ITEM_BLACK_BELT,
#line 13016
            .iv = TRAINER_PARTY_IVS(21, 21, 21, 21, 21, 21),
#line 13015
            .lvl = 50,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 13018
            .species = SPECIES_MACHOKE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13018
            .heldItem = ITEM_BLACK_BELT,
#line 13020
            .iv = TRAINER_PARTY_IVS(21, 21, 21, 21, 21, 21),
#line 13019
            .lvl = 50,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 13022
    [DIFFICULTY_NORMAL][TRAINER_BLACK_BELT_SHEA_3] =
    {
#line 13023
        .trainerName = _("SHEA"),
#line 13024
        .trainerClass = TRAINER_CLASS_BLACK_BELT,
#line 13025
        .trainerPic = TRAINER_PIC_BLACK_BELT,
        .encounterMusic_gender =
#line 13027
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
#line 13028
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 13029
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 13031
            .species = SPECIES_MACHOKE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13031
            .heldItem = ITEM_BLACK_BELT,
#line 13033
            .iv = TRAINER_PARTY_IVS(26, 26, 26, 26, 26, 26),
#line 13032
            .lvl = 55,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 13035
            .species = SPECIES_MACHAMP,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13035
            .heldItem = ITEM_BLACK_BELT,
#line 13037
            .iv = TRAINER_PARTY_IVS(26, 26, 26, 26, 26, 26),
#line 13036
            .lvl = 55,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 13039
    [DIFFICULTY_NORMAL][TRAINER_BLACK_BELT_HUGH_2] =
    {
#line 13040
        .trainerName = _("HUGH"),
#line 13041
        .trainerClass = TRAINER_CLASS_BLACK_BELT,
#line 13042
        .trainerPic = TRAINER_PIC_BLACK_BELT,
        .encounterMusic_gender =
#line 13044
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
#line 13045
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 13046
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 13048
            .species = SPECIES_MACHOKE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13048
            .heldItem = ITEM_BLACK_BELT,
#line 13050
            .iv = TRAINER_PARTY_IVS(21, 21, 21, 21, 21, 21),
#line 13049
            .lvl = 50,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 13052
            .species = SPECIES_MACHOKE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13052
            .heldItem = ITEM_BLACK_BELT,
#line 13054
            .iv = TRAINER_PARTY_IVS(21, 21, 21, 21, 21, 21),
#line 13053
            .lvl = 50,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 13056
    [DIFFICULTY_NORMAL][TRAINER_BLACK_BELT_HUGH_3] =
    {
#line 13057
        .trainerName = _("HUGH"),
#line 13058
        .trainerClass = TRAINER_CLASS_BLACK_BELT,
#line 13059
        .trainerPic = TRAINER_PIC_BLACK_BELT,
        .encounterMusic_gender =
#line 13061
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
#line 13062
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 13063
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 13065
            .species = SPECIES_MACHOKE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13065
            .heldItem = ITEM_BLACK_BELT,
#line 13067
            .iv = TRAINER_PARTY_IVS(26, 26, 26, 26, 26, 26),
#line 13066
            .lvl = 55,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 13069
            .species = SPECIES_MACHAMP,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13069
            .heldItem = ITEM_BLACK_BELT,
#line 13071
            .iv = TRAINER_PARTY_IVS(26, 26, 26, 26, 26, 26),
#line 13070
            .lvl = 55,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 13073
    [DIFFICULTY_NORMAL][TRAINER_CRUSH_KIN_MIK_KIA_2] =
    {
#line 13074
        .trainerName = _("MIK & KIA"),
#line 13075
        .trainerClass = TRAINER_CLASS_CRUSH_KIN,
#line 13076
        .trainerPic = TRAINER_PIC_CRUSH_KIN,
        .encounterMusic_gender =
#line 13078
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
#line 13079
        .battleType = TRAINER_BATTLE_TYPE_DOUBLES,
#line 13080
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 13082
            .species = SPECIES_MACHOKE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13082
            .heldItem = ITEM_BLACK_BELT,
#line 13084
            .iv = TRAINER_PARTY_IVS(15, 15, 15, 15, 15, 15),
#line 13083
            .lvl = 51,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 13086
            .species = SPECIES_PRIMEAPE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13086
            .heldItem = ITEM_BLACK_BELT,
#line 13088
            .iv = TRAINER_PARTY_IVS(15, 15, 15, 15, 15, 15),
#line 13087
            .lvl = 51,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 13090
    [DIFFICULTY_NORMAL][TRAINER_CRUSH_KIN_MIK_KIA_3] =
    {
#line 13091
        .trainerName = _("MIK & KIA"),
#line 13092
        .trainerClass = TRAINER_CLASS_CRUSH_KIN,
#line 13093
        .trainerPic = TRAINER_PIC_CRUSH_KIN,
        .encounterMusic_gender =
#line 13095
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
#line 13096
        .battleType = TRAINER_BATTLE_TYPE_DOUBLES,
#line 13097
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 13099
            .species = SPECIES_MACHAMP,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13099
            .heldItem = ITEM_BLACK_BELT,
#line 13101
            .iv = TRAINER_PARTY_IVS(20, 20, 20, 20, 20, 20),
#line 13100
            .lvl = 56,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 13103
            .species = SPECIES_PRIMEAPE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13103
            .heldItem = ITEM_BLACK_BELT,
#line 13105
            .iv = TRAINER_PARTY_IVS(20, 20, 20, 20, 20, 20),
#line 13104
            .lvl = 56,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 13107
    [DIFFICULTY_NORMAL][TRAINER_TUBER_AMIRA_2] =
    {
#line 13108
        .trainerName = _("AMIRA"),
#line 13109
        .trainerClass = TRAINER_CLASS_TUBER,
#line 13110
        .trainerPic = TRAINER_PIC_TUBER_F,
        .encounterMusic_gender =
#line 13112
            TRAINER_ENCOUNTER_MUSIC_GIRL,
#line 13113
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 13114
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 13116
            .species = SPECIES_POLIWHIRL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13118
            .iv = TRAINER_PARTY_IVS(9, 9, 9, 9, 9, 9),
#line 13117
            .lvl = 47,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 13120
            .species = SPECIES_POLIWHIRL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13122
            .iv = TRAINER_PARTY_IVS(9, 9, 9, 9, 9, 9),
#line 13121
            .lvl = 47,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 13124
            .species = SPECIES_POLIWHIRL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13126
            .iv = TRAINER_PARTY_IVS(9, 9, 9, 9, 9, 9),
#line 13125
            .lvl = 47,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 13128
    [DIFFICULTY_NORMAL][TRAINER_TWINS_JOY_MEG_2] =
    {
#line 13129
        .trainerName = _("JOY & MEG"),
#line 13130
        .trainerClass = TRAINER_CLASS_TWINS,
#line 13131
        .trainerPic = TRAINER_PIC_TWINS,
        .encounterMusic_gender =
#line 13133
            TRAINER_ENCOUNTER_MUSIC_TWINS,
#line 13134
        .battleType = TRAINER_BATTLE_TYPE_DOUBLES,
#line 13135
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 13137
            .species = SPECIES_CLEFAIRY,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13139
            .iv = TRAINER_PARTY_IVS(9, 9, 9, 9, 9, 9),
#line 13138
            .lvl = 49,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 13141
            .species = SPECIES_CLEFAIRY,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13143
            .iv = TRAINER_PARTY_IVS(9, 9, 9, 9, 9, 9),
#line 13142
            .lvl = 49,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 13145
    [DIFFICULTY_NORMAL][TRAINER_PAINTER_RAYNA_2] =
    {
#line 13146
        .trainerName = _("RAYNA"),
#line 13147
        .trainerClass = TRAINER_CLASS_PAINTER,
#line 13148
        .trainerPic = TRAINER_PIC_PAINTER,
        .encounterMusic_gender =
#line 13150
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
#line 13151
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 13152
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 13154
            .species = SPECIES_SMEARGLE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13156
            .iv = TRAINER_PARTY_IVS(14, 14, 14, 14, 14, 14),
#line 13155
            .lvl = 54,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 13157
                MOVE_CROSS_CHOP,
                MOVE_MEGAHORN,
                MOVE_DOUBLE_EDGE,
                MOVE_SELF_DESTRUCT,
            },
            },
        },
    },
#line 13162
    [DIFFICULTY_NORMAL][TRAINER_YOUNGSTER_DESTIN_2] =
    {
#line 13163
        .trainerName = _("DESTIN"),
#line 13164
        .trainerClass = TRAINER_CLASS_YOUNGSTER,
#line 13165
        .trainerPic = TRAINER_PIC_YOUNGSTER,
        .encounterMusic_gender =
#line 13167
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 13168
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 13169
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 13171
            .species = SPECIES_RATICATE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13173
            .iv = TRAINER_PARTY_IVS(14, 14, 14, 14, 14, 14),
#line 13172
            .lvl = 53,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 13175
            .species = SPECIES_PIDGEOT,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13177
            .iv = TRAINER_PARTY_IVS(14, 14, 14, 14, 14, 14),
#line 13176
            .lvl = 53,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 13179
    [DIFFICULTY_NORMAL][TRAINER_PKMN_BREEDER_ALIZE_2] =
    {
#line 13180
        .trainerName = _("ALIZE"),
#line 13181
        .trainerClass = TRAINER_CLASS_PKMN_BREEDER,
#line 13182
        .trainerPic = TRAINER_PIC_POKEMON_BREEDER,
        .encounterMusic_gender =
#line 13184
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
#line 13185
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 13186
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 13188
            .species = SPECIES_PIKACHU,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13190
            .iv = TRAINER_PARTY_IVS(18, 18, 18, 18, 18, 18),
#line 13189
            .lvl = 53,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 13192
            .species = SPECIES_CLEFAIRY,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13194
            .iv = TRAINER_PARTY_IVS(18, 18, 18, 18, 18, 18),
#line 13193
            .lvl = 53,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 13196
            .species = SPECIES_MARILL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13198
            .iv = TRAINER_PARTY_IVS(18, 18, 18, 18, 18, 18),
#line 13197
            .lvl = 53,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 13200
    [DIFFICULTY_NORMAL][TRAINER_YOUNG_COUPLE_GIA_JES_2] =
    {
#line 13201
        .trainerName = _("GIA & JES"),
#line 13202
        .trainerClass = TRAINER_CLASS_YOUNG_COUPLE,
#line 13203
        .trainerPic = TRAINER_PIC_YOUNG_COUPLE,
        .encounterMusic_gender =
#line 13205
            TRAINER_ENCOUNTER_MUSIC_GIRL,
#line 13206
        .battleType = TRAINER_BATTLE_TYPE_DOUBLES,
#line 13207
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 13209
            .species = SPECIES_NIDORINA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13211
            .iv = TRAINER_PARTY_IVS(7, 7, 7, 7, 7, 7),
#line 13210
            .lvl = 30,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 13213
            .species = SPECIES_NIDORINO,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13215
            .iv = TRAINER_PARTY_IVS(7, 7, 7, 7, 7, 7),
#line 13214
            .lvl = 30,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 13217
    [DIFFICULTY_NORMAL][TRAINER_YOUNG_COUPLE_GIA_JES_3] =
    {
#line 13218
        .trainerName = _("GIA & JES"),
#line 13219
        .trainerClass = TRAINER_CLASS_YOUNG_COUPLE,
#line 13220
        .trainerPic = TRAINER_PIC_YOUNG_COUPLE,
        .encounterMusic_gender =
#line 13222
            TRAINER_ENCOUNTER_MUSIC_GIRL,
#line 13223
        .battleType = TRAINER_BATTLE_TYPE_DOUBLES,
#line 13224
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 13226
            .species = SPECIES_NIDOKING,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13228
            .iv = TRAINER_PARTY_IVS(14, 14, 14, 14, 14, 14),
#line 13227
            .lvl = 55,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 13230
            .species = SPECIES_NIDOQUEEN,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13232
            .iv = TRAINER_PARTY_IVS(14, 14, 14, 14, 14, 14),
#line 13231
            .lvl = 55,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 13234
    [DIFFICULTY_NORMAL][TRAINER_BIRD_KEEPER_MILO_2] =
    {
#line 13235
        .trainerName = _("MILO"),
#line 13236
        .trainerClass = TRAINER_CLASS_BIRD_KEEPER,
#line 13237
        .trainerPic = TRAINER_PIC_BIRD_KEEPER,
        .encounterMusic_gender =
#line 13239
            TRAINER_ENCOUNTER_MUSIC_COOL,
#line 13240
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 13241
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 13243
            .species = SPECIES_PIDGEOTTO,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13245
            .iv = TRAINER_PARTY_IVS(14, 14, 14, 14, 14, 14),
#line 13244
            .lvl = 53,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 13247
            .species = SPECIES_PIDGEOT,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13249
            .iv = TRAINER_PARTY_IVS(14, 14, 14, 14, 14, 14),
#line 13248
            .lvl = 55,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 13251
    [DIFFICULTY_NORMAL][TRAINER_BIRD_KEEPER_CHAZ_2] =
    {
#line 13252
        .trainerName = _("CHAZ"),
#line 13253
        .trainerClass = TRAINER_CLASS_BIRD_KEEPER,
#line 13254
        .trainerPic = TRAINER_PIC_BIRD_KEEPER,
        .encounterMusic_gender =
#line 13256
            TRAINER_ENCOUNTER_MUSIC_COOL,
#line 13257
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 13258
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 13260
            .species = SPECIES_FEAROW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13262
            .iv = TRAINER_PARTY_IVS(14, 14, 14, 14, 14, 14),
#line 13261
            .lvl = 53,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 13264
            .species = SPECIES_FEAROW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13266
            .iv = TRAINER_PARTY_IVS(14, 14, 14, 14, 14, 14),
#line 13265
            .lvl = 55,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 13268
    [DIFFICULTY_NORMAL][TRAINER_BIRD_KEEPER_HAROLD_2] =
    {
#line 13269
        .trainerName = _("HAROLD"),
#line 13270
        .trainerClass = TRAINER_CLASS_BIRD_KEEPER,
#line 13271
        .trainerPic = TRAINER_PIC_BIRD_KEEPER,
        .encounterMusic_gender =
#line 13273
            TRAINER_ENCOUNTER_MUSIC_COOL,
#line 13274
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 13275
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 13277
            .species = SPECIES_NOCTOWL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13279
            .iv = TRAINER_PARTY_IVS(14, 14, 14, 14, 14, 14),
#line 13278
            .lvl = 53,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 13281
            .species = SPECIES_NOCTOWL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13283
            .iv = TRAINER_PARTY_IVS(14, 14, 14, 14, 14, 14),
#line 13282
            .lvl = 55,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 13285
    [DIFFICULTY_NORMAL][TRAINER_SWIMMER_FEMALE_NICOLE_2] =
    {
#line 13286
        .trainerName = _("NICOLE"),
#line 13287
        .trainerClass = TRAINER_CLASS_SWIMMER_F,
#line 13288
        .trainerPic = TRAINER_PIC_SWIMMER_F,
        .encounterMusic_gender =
#line 13290
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
#line 13291
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 13292
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 13294
            .species = SPECIES_MARILL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13296
            .iv = TRAINER_PARTY_IVS(14, 14, 14, 14, 14, 14),
#line 13295
            .lvl = 54,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 13298
    [DIFFICULTY_NORMAL][TRAINER_PSYCHIC_JACLYN_2] =
    {
#line 13299
        .trainerName = _("JACLYN"),
#line 13300
        .trainerClass = TRAINER_CLASS_PSYCHIC,
#line 13301
        .trainerPic = TRAINER_PIC_PSYCHIC_F,
        .encounterMusic_gender =
#line 13303
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
#line 13304
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 13305
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 13307
            .species = SPECIES_NATU,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13309
            .iv = TRAINER_PARTY_IVS(26, 26, 26, 26, 26, 26),
#line 13308
            .lvl = 52,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 13310
                MOVE_PSYCHIC,
                MOVE_CONFUSE_RAY,
                MOVE_FUTURE_SIGHT,
                MOVE_WISH,
            },
            },
            {
#line 13315
            .species = SPECIES_SLOWBRO,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13317
            .iv = TRAINER_PARTY_IVS(26, 26, 26, 26, 26, 26),
#line 13316
            .lvl = 52,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 13318
                MOVE_PSYCHIC,
                MOVE_HEADBUTT,
                MOVE_AMNESIA,
                MOVE_YAWN,
            },
            },
            {
#line 13323
            .species = SPECIES_KADABRA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13325
            .iv = TRAINER_PARTY_IVS(26, 26, 26, 26, 26, 26),
#line 13324
            .lvl = 54,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 13326
                MOVE_PSYCHIC,
                MOVE_FUTURE_SIGHT,
                MOVE_RECOVER,
                MOVE_REFLECT,
            },
            },
        },
    },
#line 13331
    [DIFFICULTY_NORMAL][TRAINER_SWIMMER_MALE_SAMIR_2] =
    {
#line 13332
        .trainerName = _("SAMIR"),
#line 13333
        .trainerClass = TRAINER_CLASS_SWIMMER_M,
#line 13334
        .trainerPic = TRAINER_PIC_SWIMMER_M,
        .encounterMusic_gender =
#line 13336
            TRAINER_ENCOUNTER_MUSIC_SWIMMER,
#line 13337
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 13338
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 13340
            .species = SPECIES_GYARADOS,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13342
            .iv = TRAINER_PARTY_IVS(14, 14, 14, 14, 14, 14),
#line 13341
            .lvl = 55,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 13344
    [DIFFICULTY_NORMAL][TRAINER_HIKER_EARL_2] =
    {
#line 13345
        .trainerName = _("EARL"),
#line 13346
        .trainerClass = TRAINER_CLASS_HIKER,
#line 13347
        .trainerPic = TRAINER_PIC_HIKER,
        .encounterMusic_gender =
#line 13349
            TRAINER_ENCOUNTER_MUSIC_HIKER,
#line 13350
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 13351
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 13353
            .species = SPECIES_ONIX,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13355
            .iv = TRAINER_PARTY_IVS(14, 14, 14, 14, 14, 14),
#line 13354
            .lvl = 54,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 13357
            .species = SPECIES_MACHAMP,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13359
            .iv = TRAINER_PARTY_IVS(14, 14, 14, 14, 14, 14),
#line 13358
            .lvl = 54,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 13361
    [DIFFICULTY_NORMAL][TRAINER_RUIN_MANIAC_LARRY_2] =
    {
#line 13362
        .trainerName = _("LARRY"),
#line 13363
        .trainerClass = TRAINER_CLASS_RUIN_MANIAC,
#line 13364
        .trainerPic = TRAINER_PIC_RUIN_MANIAC,
        .encounterMusic_gender =
#line 13366
            TRAINER_ENCOUNTER_MUSIC_HIKER,
#line 13367
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 13368
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 13370
            .species = SPECIES_MACHOKE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13372
            .iv = TRAINER_PARTY_IVS(14, 14, 14, 14, 14, 14),
#line 13371
            .lvl = 54,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 13374
            .species = SPECIES_MACHOKE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13376
            .iv = TRAINER_PARTY_IVS(14, 14, 14, 14, 14, 14),
#line 13375
            .lvl = 54,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 13378
    [DIFFICULTY_NORMAL][TRAINER_POKEMANIAC_HECTOR_2] =
    {
#line 13379
        .trainerName = _("HECTOR"),
#line 13380
        .trainerClass = TRAINER_CLASS_POKEMANIAC,
#line 13381
        .trainerPic = TRAINER_PIC_POKEMANIAC,
        .encounterMusic_gender =
#line 13383
            TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
#line 13384
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 13385
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 13387
            .species = SPECIES_RHYDON,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13389
            .iv = TRAINER_PARTY_IVS(18, 18, 18, 18, 18, 18),
#line 13388
            .lvl = 55,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 13391
            .species = SPECIES_KANGASKHAN,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13393
            .iv = TRAINER_PARTY_IVS(18, 18, 18, 18, 18, 18),
#line 13392
            .lvl = 55,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 13395
    [DIFFICULTY_NORMAL][TRAINER_PSYCHIC_DARIO_2] =
    {
#line 13396
        .trainerName = _("DARIO"),
#line 13397
        .trainerClass = TRAINER_CLASS_PSYCHIC,
#line 13398
        .trainerPic = TRAINER_PIC_PSYCHIC_M,
        .encounterMusic_gender =
#line 13400
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
#line 13401
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 13402
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 13404
            .species = SPECIES_GIRAFARIG,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13406
            .iv = TRAINER_PARTY_IVS(26, 26, 26, 26, 26, 26),
#line 13405
            .lvl = 56,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 13407
                MOVE_CRUNCH,
                MOVE_PSYBEAM,
                MOVE_ODOR_SLEUTH,
                MOVE_AGILITY,
            },
            },
        },
    },
#line 13412
    [DIFFICULTY_NORMAL][TRAINER_PSYCHIC_RODETTE_2] =
    {
#line 13413
        .trainerName = _("RODETTE"),
#line 13414
        .trainerClass = TRAINER_CLASS_PSYCHIC,
#line 13415
        .trainerPic = TRAINER_PIC_PSYCHIC_F,
        .encounterMusic_gender =
#line 13417
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
#line 13418
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 13419
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 13421
            .species = SPECIES_NATU,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13423
            .iv = TRAINER_PARTY_IVS(26, 26, 26, 26, 26, 26),
#line 13422
            .lvl = 53,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 13424
                MOVE_PSYCHIC,
                MOVE_CONFUSE_RAY,
                MOVE_WISH,
                MOVE_FUTURE_SIGHT,
            },
            },
            {
#line 13429
            .species = SPECIES_HYPNO,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13431
            .iv = TRAINER_PARTY_IVS(26, 26, 26, 26, 26, 26),
#line 13430
            .lvl = 53,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 13432
                MOVE_PSYCHIC,
                MOVE_DISABLE,
                MOVE_PSYCH_UP,
                MOVE_FUTURE_SIGHT,
            },
            },
            {
#line 13437
            .species = SPECIES_HYPNO,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13439
            .iv = TRAINER_PARTY_IVS(26, 26, 26, 26, 26, 26),
#line 13438
            .lvl = 53,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 13440
                MOVE_PSYCHIC,
                MOVE_HYPNOSIS,
                MOVE_PSYCH_UP,
                MOVE_FUTURE_SIGHT,
            },
            },
        },
    },
#line 13445
    [DIFFICULTY_NORMAL][TRAINER_JUGGLER_MASON_2] =
    {
#line 13446
        .trainerName = _("MASON"),
#line 13447
        .trainerClass = TRAINER_CLASS_JUGGLER,
#line 13448
        .trainerPic = TRAINER_PIC_JUGGLER,
        .encounterMusic_gender =
#line 13450
            TRAINER_ENCOUNTER_MUSIC_HIKER,
#line 13451
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 13452
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 4,
        .party = (const struct TrainerMon[])
        {
            {
#line 13454
            .species = SPECIES_ELECTRODE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13456
            .iv = TRAINER_PARTY_IVS(14, 14, 14, 14, 14, 14),
#line 13455
            .lvl = 52,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 13458
            .species = SPECIES_PINECO,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13460
            .iv = TRAINER_PARTY_IVS(14, 14, 14, 14, 14, 14),
#line 13459
            .lvl = 52,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 13462
            .species = SPECIES_ELECTRODE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13464
            .iv = TRAINER_PARTY_IVS(14, 14, 14, 14, 14, 14),
#line 13463
            .lvl = 52,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 13466
            .species = SPECIES_PINECO,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13468
            .iv = TRAINER_PARTY_IVS(14, 14, 14, 14, 14, 14),
#line 13467
            .lvl = 52,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 13470
    [DIFFICULTY_NORMAL][TRAINER_PKMN_RANGER_NICOLAS_2] =
    {
#line 13471
        .trainerName = _("NICOLAS"),
#line 13472
        .trainerClass = TRAINER_CLASS_PKMN_RANGER,
#line 13473
        .trainerPic = TRAINER_PIC_POKEMON_RANGER_M,
        .encounterMusic_gender =
#line 13475
            TRAINER_ENCOUNTER_MUSIC_COOL,
#line 13476
        .items = { ITEM_FULL_RESTORE },
#line 13477
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 13478
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 13480
            .species = SPECIES_VICTREEBEL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13482
            .iv = TRAINER_PARTY_IVS(26, 26, 26, 26, 26, 26),
#line 13481
            .lvl = 55,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 13483
                MOVE_RAZOR_LEAF,
                MOVE_ACID,
                MOVE_STUN_SPORE,
                MOVE_WRAP,
            },
            },
            {
#line 13488
            .species = SPECIES_VICTREEBEL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13490
            .iv = TRAINER_PARTY_IVS(26, 26, 26, 26, 26, 26),
#line 13489
            .lvl = 55,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 13491
                MOVE_RAZOR_LEAF,
                MOVE_ACID,
                MOVE_SLEEP_POWDER,
                MOVE_SLAM,
            },
            },
        },
    },
#line 13496
    [DIFFICULTY_NORMAL][TRAINER_PKMN_RANGER_MADELINE_2] =
    {
#line 13497
        .trainerName = _("MADELINE"),
#line 13498
        .trainerClass = TRAINER_CLASS_PKMN_RANGER,
#line 13499
        .trainerPic = TRAINER_PIC_POKEMON_RANGER_F,
        .encounterMusic_gender =
#line 13501
            TRAINER_ENCOUNTER_MUSIC_COOL,
#line 13502
        .items = { ITEM_FULL_RESTORE },
#line 13503
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 13504
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 13506
            .species = SPECIES_VILEPLUME,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13508
            .iv = TRAINER_PARTY_IVS(26, 26, 26, 26, 26, 26),
#line 13507
            .lvl = 55,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 13509
                MOVE_PETAL_DANCE,
                MOVE_MOONLIGHT,
                MOVE_ACID,
                MOVE_SLEEP_POWDER,
            },
            },
            {
#line 13514
            .species = SPECIES_VILEPLUME,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13516
            .iv = TRAINER_PARTY_IVS(26, 26, 26, 26, 26, 26),
#line 13515
            .lvl = 55,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 13517
                MOVE_PETAL_DANCE,
                MOVE_MOONLIGHT,
                MOVE_ACID,
                MOVE_STUN_SPORE,
            },
            },
        },
    },
#line 13522
    [DIFFICULTY_NORMAL][TRAINER_CRUSH_GIRL_CYNDY_2] =
    {
#line 13523
        .trainerName = _("CYNDY"),
#line 13524
        .trainerClass = TRAINER_CLASS_CRUSH_GIRL,
#line 13525
        .trainerPic = TRAINER_PIC_CRUSH_GIRL,
        .encounterMusic_gender =
#line 13527
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
#line 13528
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 13529
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 13531
            .species = SPECIES_PRIMEAPE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13531
            .heldItem = ITEM_BLACK_BELT,
#line 13533
            .iv = TRAINER_PARTY_IVS(20, 20, 20, 20, 20, 20),
#line 13532
            .lvl = 54,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 13535
            .species = SPECIES_HITMONTOP,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13535
            .heldItem = ITEM_BLACK_BELT,
#line 13537
            .iv = TRAINER_PARTY_IVS(20, 20, 20, 20, 20, 20),
#line 13536
            .lvl = 54,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 13539
            .species = SPECIES_MACHAMP,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13539
            .heldItem = ITEM_BLACK_BELT,
#line 13541
            .iv = TRAINER_PARTY_IVS(20, 20, 20, 20, 20, 20),
#line 13540
            .lvl = 54,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 13543
    [DIFFICULTY_NORMAL][TRAINER_TAMER_EVAN_2] =
    {
#line 13544
        .trainerName = _("EVAN"),
#line 13545
        .trainerClass = TRAINER_CLASS_TAMER,
#line 13546
        .trainerPic = TRAINER_PIC_TAMER,
        .encounterMusic_gender =
#line 13548
            TRAINER_ENCOUNTER_MUSIC_HIKER,
#line 13549
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 13550
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 13552
            .species = SPECIES_SANDSLASH,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13554
            .iv = TRAINER_PARTY_IVS(19, 19, 19, 19, 19, 19),
#line 13553
            .lvl = 52,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 13556
            .species = SPECIES_LICKITUNG,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13558
            .iv = TRAINER_PARTY_IVS(19, 19, 19, 19, 19, 19),
#line 13557
            .lvl = 52,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 13560
            .species = SPECIES_URSARING,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13562
            .iv = TRAINER_PARTY_IVS(19, 19, 19, 19, 19, 19),
#line 13561
            .lvl = 55,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 13564
    [DIFFICULTY_NORMAL][TRAINER_PKMN_RANGER_JACKSON_2] =
    {
#line 13565
        .trainerName = _("JACKSON"),
#line 13566
        .trainerClass = TRAINER_CLASS_PKMN_RANGER,
#line 13567
        .trainerPic = TRAINER_PIC_POKEMON_RANGER_M,
        .encounterMusic_gender =
#line 13569
            TRAINER_ENCOUNTER_MUSIC_COOL,
#line 13570
        .items = { ITEM_FULL_RESTORE },
#line 13571
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 13572
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 13574
            .species = SPECIES_TANGELA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13576
            .iv = TRAINER_PARTY_IVS(26, 26, 26, 26, 26, 26),
#line 13575
            .lvl = 53,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 13577
                MOVE_SLAM,
                MOVE_MEGA_DRAIN,
                MOVE_BIND,
                MOVE_INGRAIN,
            },
            },
            {
#line 13582
            .species = SPECIES_EXEGGUTOR,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13584
            .iv = TRAINER_PARTY_IVS(26, 26, 26, 26, 26, 26),
#line 13583
            .lvl = 54,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 13585
                MOVE_CONFUSION,
                MOVE_EGG_BOMB,
                MOVE_STUN_SPORE,
                MOVE_REFLECT,
            },
            },
            {
#line 13590
            .species = SPECIES_EXEGGUTOR,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13592
            .iv = TRAINER_PARTY_IVS(26, 26, 26, 26, 26, 26),
#line 13591
            .lvl = 55,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 13593
                MOVE_CONFUSION,
                MOVE_EGG_BOMB,
                MOVE_SLEEP_POWDER,
                MOVE_STOMP,
            },
            },
        },
    },
#line 13598
    [DIFFICULTY_NORMAL][TRAINER_PKMN_RANGER_KATELYN_2] =
    {
#line 13599
        .trainerName = _("KATELYN"),
#line 13600
        .trainerClass = TRAINER_CLASS_PKMN_RANGER,
#line 13601
        .trainerPic = TRAINER_PIC_POKEMON_RANGER_F,
        .encounterMusic_gender =
#line 13603
            TRAINER_ENCOUNTER_MUSIC_COOL,
#line 13604
        .items = { ITEM_FULL_RESTORE },
#line 13605
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 13606
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 13608
            .species = SPECIES_CHANSEY,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13610
            .iv = TRAINER_PARTY_IVS(26, 26, 26, 26, 26, 26),
#line 13609
            .lvl = 56,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 13611
                MOVE_EGG_BOMB,
                MOVE_DEFENSE_CURL,
                MOVE_MINIMIZE,
                MOVE_SOFT_BOILED,
            },
            },
        },
    },
#line 13616
    [DIFFICULTY_NORMAL][TRAINER_COOLTRAINER_LEROY_2] =
    {
#line 13617
        .trainerName = _("LEROY"),
#line 13618
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
#line 13619
        .trainerPic = TRAINER_PIC_COOLTRAINER_M,
        .encounterMusic_gender =
#line 13621
            TRAINER_ENCOUNTER_MUSIC_COOL,
#line 13622
        .items = { ITEM_FULL_RESTORE },
#line 13623
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 13624
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .partySize = 5,
        .party = (const struct TrainerMon[])
        {
            {
#line 13626
            .species = SPECIES_RHYDON,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13628
            .iv = TRAINER_PARTY_IVS(26, 26, 26, 26, 26, 26),
#line 13627
            .lvl = 52,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 13629
                MOVE_EARTHQUAKE,
                MOVE_HORN_DRILL,
                MOVE_ROCK_BLAST,
                MOVE_SCARY_FACE,
            },
            },
            {
#line 13634
            .species = SPECIES_SLOWBRO,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13636
            .iv = TRAINER_PARTY_IVS(26, 26, 26, 26, 26, 26),
#line 13635
            .lvl = 54,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 13637
                MOVE_PSYCHIC,
                MOVE_HEADBUTT,
                MOVE_AMNESIA,
                MOVE_DISABLE,
            },
            },
            {
#line 13642
            .species = SPECIES_KANGASKHAN,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13644
            .iv = TRAINER_PARTY_IVS(26, 26, 26, 26, 26, 26),
#line 13643
            .lvl = 52,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 13645
                MOVE_DIZZY_PUNCH,
                MOVE_BITE,
                MOVE_ENDURE,
                MOVE_REVERSAL,
            },
            },
            {
#line 13650
            .species = SPECIES_MACHAMP,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13652
            .iv = TRAINER_PARTY_IVS(26, 26, 26, 26, 26, 26),
#line 13651
            .lvl = 52,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 13653
                MOVE_CROSS_CHOP,
                MOVE_VITAL_THROW,
                MOVE_REVENGE,
                MOVE_SEISMIC_TOSS,
            },
            },
            {
#line 13658
            .species = SPECIES_URSARING,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13660
            .iv = TRAINER_PARTY_IVS(26, 26, 26, 26, 26, 26),
#line 13659
            .lvl = 55,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 13661
                MOVE_SLASH,
                MOVE_FAINT_ATTACK,
                MOVE_SNORE,
                MOVE_REST,
            },
            },
        },
    },
#line 13666
    [DIFFICULTY_NORMAL][TRAINER_COOLTRAINER_MICHELLE_2] =
    {
#line 13667
        .trainerName = _("MICHELLE"),
#line 13668
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
#line 13669
        .trainerPic = TRAINER_PIC_COOLTRAINER_F,
        .encounterMusic_gender =
#line 13671
            TRAINER_ENCOUNTER_MUSIC_COOL,
#line 13672
        .items = { ITEM_HYPER_POTION },
#line 13673
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 13674
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .partySize = 5,
        .party = (const struct TrainerMon[])
        {
            {
#line 13676
            .species = SPECIES_PERSIAN,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13678
            .iv = TRAINER_PARTY_IVS(26, 26, 26, 26, 26, 26),
#line 13677
            .lvl = 53,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 13679
                MOVE_SLASH,
                MOVE_SCREECH,
                MOVE_FAINT_ATTACK,
                MOVE_BITE,
            },
            },
            {
#line 13684
            .species = SPECIES_DEWGONG,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13686
            .iv = TRAINER_PARTY_IVS(26, 26, 26, 26, 26, 26),
#line 13685
            .lvl = 53,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 13687
                MOVE_ICE_BEAM,
                MOVE_TAKE_DOWN,
                MOVE_ICY_WIND,
                MOVE_SHEER_COLD,
            },
            },
            {
#line 13692
            .species = SPECIES_NINETALES,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13694
            .iv = TRAINER_PARTY_IVS(26, 26, 26, 26, 26, 26),
#line 13693
            .lvl = 54,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 13695
                MOVE_FLAMETHROWER,
                MOVE_CONFUSE_RAY,
                MOVE_WILL_O_WISP,
                MOVE_GRUDGE,
            },
            },
            {
#line 13700
            .species = SPECIES_RAPIDASH,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13702
            .iv = TRAINER_PARTY_IVS(26, 26, 26, 26, 26, 26),
#line 13701
            .lvl = 54,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 13703
                MOVE_BOUNCE,
                MOVE_AGILITY,
                MOVE_FIRE_SPIN,
                MOVE_TAKE_DOWN,
            },
            },
            {
#line 13708
            .species = SPECIES_GIRAFARIG,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13710
            .iv = TRAINER_PARTY_IVS(26, 26, 26, 26, 26, 26),
#line 13709
            .lvl = 56,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 13711
                MOVE_CRUNCH,
                MOVE_PSYBEAM,
                MOVE_STOMP,
                MOVE_ODOR_SLEUTH,
            },
            },
        },
    },
#line 13716
    [DIFFICULTY_NORMAL][TRAINER_COOL_COUPLE_LEX_NYA_2] =
    {
#line 13717
        .trainerName = _("LEX & NYA"),
#line 13718
        .trainerClass = TRAINER_CLASS_COOL_COUPLE,
#line 13719
        .trainerPic = TRAINER_PIC_COOL_COUPLE,
        .encounterMusic_gender =
#line 13721
            TRAINER_ENCOUNTER_MUSIC_COOL,
#line 13722
        .items = { ITEM_FULL_RESTORE, ITEM_FULL_RESTORE },
#line 13723
        .battleType = TRAINER_BATTLE_TYPE_DOUBLES,
#line 13724
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 13726
            .species = SPECIES_MILTANK,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13728
            .iv = TRAINER_PARTY_IVS(26, 26, 26, 26, 26, 26),
#line 13727
            .lvl = 57,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 13729
                MOVE_BODY_SLAM,
                MOVE_MILK_DRINK,
                MOVE_GROWL,
                MOVE_DEFENSE_CURL,
            },
            },
            {
#line 13734
            .species = SPECIES_TAUROS,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13736
            .iv = TRAINER_PARTY_IVS(26, 26, 26, 26, 26, 26),
#line 13735
            .lvl = 57,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 13737
                MOVE_TAKE_DOWN,
                MOVE_SCARY_FACE,
                MOVE_PURSUIT,
                MOVE_SWAGGER,
            },
            },
        },
    },
#line 13742
    [DIFFICULTY_NORMAL][TRAINER_BUG_CATCHER_COLTON_2] =
    {
#line 13743
        .trainerName = _("COLTON"),
#line 13744
        .trainerClass = TRAINER_CLASS_BUG_CATCHER,
#line 13745
        .trainerPic = TRAINER_PIC_BUG_CATCHER,
        .encounterMusic_gender =
#line 13747
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 13748
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 13749
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 13751
            .species = SPECIES_METAPOD,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13753
            .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
#line 13752
            .lvl = 19,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 13755
            .species = SPECIES_WEEDLE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13757
            .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
#line 13756
            .lvl = 19,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 13759
            .species = SPECIES_METAPOD,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13761
            .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
#line 13760
            .lvl = 19,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 13763
    [DIFFICULTY_NORMAL][TRAINER_BUG_CATCHER_COLTON_3] =
    {
#line 13764
        .trainerName = _("COLTON"),
#line 13765
        .trainerClass = TRAINER_CLASS_BUG_CATCHER,
#line 13766
        .trainerPic = TRAINER_PIC_BUG_CATCHER,
        .encounterMusic_gender =
#line 13768
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 13769
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 13770
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 13772
            .species = SPECIES_BUTTERFREE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13774
            .iv = TRAINER_PARTY_IVS(7, 7, 7, 7, 7, 7),
#line 13773
            .lvl = 27,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 13776
            .species = SPECIES_KAKUNA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13778
            .iv = TRAINER_PARTY_IVS(7, 7, 7, 7, 7, 7),
#line 13777
            .lvl = 27,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 13780
            .species = SPECIES_BUTTERFREE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13782
            .iv = TRAINER_PARTY_IVS(7, 7, 7, 7, 7, 7),
#line 13781
            .lvl = 27,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 13784
    [DIFFICULTY_NORMAL][TRAINER_BUG_CATCHER_COLTON_4] =
    {
#line 13785
        .trainerName = _("COLTON"),
#line 13786
        .trainerClass = TRAINER_CLASS_BUG_CATCHER,
#line 13787
        .trainerPic = TRAINER_PIC_BUG_CATCHER,
        .encounterMusic_gender =
#line 13789
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 13790
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 13791
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 13793
            .species = SPECIES_BUTTERFREE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13795
            .iv = TRAINER_PARTY_IVS(14, 14, 14, 14, 14, 14),
#line 13794
            .lvl = 51,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 13797
            .species = SPECIES_BEEDRILL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13799
            .iv = TRAINER_PARTY_IVS(14, 14, 14, 14, 14, 14),
#line 13798
            .lvl = 54,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 13801
            .species = SPECIES_BUTTERFREE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13803
            .iv = TRAINER_PARTY_IVS(14, 14, 14, 14, 14, 14),
#line 13802
            .lvl = 51,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 13805
    [DIFFICULTY_NORMAL][TRAINER_SWIMMER_MALE_MATTHEW_2] =
    {
#line 13806
        .trainerName = _("MATTHEW"),
#line 13807
        .trainerClass = TRAINER_CLASS_SWIMMER_M,
#line 13808
        .trainerPic = TRAINER_PIC_SWIMMER_M,
        .encounterMusic_gender =
#line 13810
            TRAINER_ENCOUNTER_MUSIC_SWIMMER,
#line 13811
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 13812
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 13814
            .species = SPECIES_POLIWHIRL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13816
            .iv = TRAINER_PARTY_IVS(9, 9, 9, 9, 9, 9),
#line 13815
            .lvl = 49,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 13818
            .species = SPECIES_POLIWRATH,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13820
            .iv = TRAINER_PARTY_IVS(9, 9, 9, 9, 9, 9),
#line 13819
            .lvl = 49,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 13822
    [DIFFICULTY_NORMAL][TRAINER_SWIMMER_MALE_TONY_2] =
    {
#line 13823
        .trainerName = _("TONY"),
#line 13824
        .trainerClass = TRAINER_CLASS_SWIMMER_M,
#line 13825
        .trainerPic = TRAINER_PIC_SWIMMER_M,
        .encounterMusic_gender =
#line 13827
            TRAINER_ENCOUNTER_MUSIC_SWIMMER,
#line 13828
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 13829
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 13831
            .species = SPECIES_SEADRA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13833
            .iv = TRAINER_PARTY_IVS(9, 9, 9, 9, 9, 9),
#line 13832
            .lvl = 49,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 13835
            .species = SPECIES_SEADRA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13837
            .iv = TRAINER_PARTY_IVS(9, 9, 9, 9, 9, 9),
#line 13836
            .lvl = 49,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 13839
    [DIFFICULTY_NORMAL][TRAINER_SWIMMER_FEMALE_MELISSA_2] =
    {
#line 13840
        .trainerName = _("MELISSA"),
#line 13841
        .trainerClass = TRAINER_CLASS_SWIMMER_F,
#line 13842
        .trainerPic = TRAINER_PIC_SWIMMER_F,
        .encounterMusic_gender =
#line 13844
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
#line 13845
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 13846
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 13848
            .species = SPECIES_POLIWHIRL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13850
            .iv = TRAINER_PARTY_IVS(9, 9, 9, 9, 9, 9),
#line 13849
            .lvl = 49,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 13852
            .species = SPECIES_SEAKING,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13854
            .iv = TRAINER_PARTY_IVS(9, 9, 9, 9, 9, 9),
#line 13853
            .lvl = 49,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 13856
    [DIFFICULTY_NORMAL][TRAINER_ELITE_FOUR_LORELEI_2] =
    {
#line 13857
        .trainerName = _("LORELEI"),
#line 13858
        .trainerClass = TRAINER_CLASS_ELITE_FOUR,
#line 13859
        .trainerPic = TRAINER_PIC_ELITE_FOUR_LORELEI,
        .encounterMusic_gender =
#line 13861
            TRAINER_ENCOUNTER_MUSIC_ELITE_FOUR,
#line 13862
        .items = { ITEM_FULL_RESTORE, ITEM_FULL_RESTORE },
#line 13863
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 13864
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
#line 13865
        .mugshotColor = MUGSHOT_COLOR_PURPLE,
        .partySize = 5,
        .party = (const struct TrainerMon[])
        {
            {
#line 13867
            .species = SPECIES_DEWGONG,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13869
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 13868
            .lvl = 64,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 13870
                MOVE_ICE_BEAM,
                MOVE_SURF,
                MOVE_SIGNAL_BEAM,
                MOVE_DOUBLE_TEAM,
            },
            },
            {
#line 13875
            .species = SPECIES_CLOYSTER,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13877
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 13876
            .lvl = 63,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 13878
                MOVE_ICE_BEAM,
                MOVE_SURF,
                MOVE_SUPERSONIC,
                MOVE_RAIN_DANCE,
            },
            },
            {
#line 13883
            .species = SPECIES_PILOSWINE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13885
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 13884
            .lvl = 63,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 13886
                MOVE_BLIZZARD,
                MOVE_EARTHQUAKE,
                MOVE_DOUBLE_EDGE,
                MOVE_ROCK_SLIDE,
            },
            },
            {
#line 13891
            .species = SPECIES_JYNX,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13893
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 13892
            .lvl = 66,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 13894
                MOVE_ICE_BEAM,
                MOVE_PSYCHIC,
                MOVE_LOVELY_KISS,
                MOVE_ATTRACT,
            },
            },
            {
#line 13899
            .species = SPECIES_LAPRAS,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13899
            .heldItem = ITEM_CHERI_BERRY,
#line 13901
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 13900
            .lvl = 66,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 13902
                MOVE_ICE_BEAM,
                MOVE_SURF,
                MOVE_PSYCHIC,
                MOVE_THUNDER,
            },
            },
        },
    },
#line 13907
    [DIFFICULTY_NORMAL][TRAINER_ELITE_FOUR_BRUNO_2] =
    {
#line 13908
        .trainerName = _("BRUNO"),
#line 13909
        .trainerClass = TRAINER_CLASS_ELITE_FOUR,
#line 13910
        .trainerPic = TRAINER_PIC_ELITE_FOUR_BRUNO,
        .encounterMusic_gender =
#line 13912
            TRAINER_ENCOUNTER_MUSIC_ELITE_FOUR,
#line 13913
        .items = { ITEM_FULL_RESTORE, ITEM_FULL_RESTORE },
#line 13914
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 13915
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
#line 13916
        .mugshotColor = MUGSHOT_COLOR_GREEN,
        .partySize = 5,
        .party = (const struct TrainerMon[])
        {
            {
#line 13918
            .species = SPECIES_STEELIX,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13920
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 13919
            .lvl = 65,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 13921
                MOVE_EARTHQUAKE,
                MOVE_IRON_TAIL,
                MOVE_CRUNCH,
                MOVE_ROCK_TOMB,
            },
            },
            {
#line 13926
            .species = SPECIES_HITMONCHAN,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13928
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 13927
            .lvl = 65,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 13929
                MOVE_SKY_UPPERCUT,
                MOVE_MACH_PUNCH,
                MOVE_ROCK_SLIDE,
                MOVE_COUNTER,
            },
            },
            {
#line 13934
            .species = SPECIES_HITMONLEE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13936
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 13935
            .lvl = 65,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 13937
                MOVE_MEGA_KICK,
                MOVE_FORESIGHT,
                MOVE_EARTHQUAKE,
                MOVE_ROCK_SLIDE,
            },
            },
            {
#line 13942
            .species = SPECIES_STEELIX,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13944
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 13943
            .lvl = 66,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 13945
                MOVE_EARTHQUAKE,
                MOVE_IRON_TAIL,
                MOVE_CRUNCH,
                MOVE_DRAGON_BREATH,
            },
            },
            {
#line 13950
            .species = SPECIES_MACHAMP,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13950
            .heldItem = ITEM_PERSIM_BERRY,
#line 13952
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 13951
            .lvl = 68,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 13953
                MOVE_CROSS_CHOP,
                MOVE_EARTHQUAKE,
                MOVE_BRICK_BREAK,
                MOVE_ROCK_SLIDE,
            },
            },
        },
    },
#line 13958
    [DIFFICULTY_NORMAL][TRAINER_ELITE_FOUR_AGATHA_2] =
    {
#line 13959
        .trainerName = _("AGATHA"),
#line 13960
        .trainerClass = TRAINER_CLASS_ELITE_FOUR,
#line 13961
        .trainerPic = TRAINER_PIC_ELITE_FOUR_AGATHA,
        .encounterMusic_gender =
#line 13963
            TRAINER_ENCOUNTER_MUSIC_ELITE_FOUR,
#line 13964
        .items = { ITEM_FULL_RESTORE, ITEM_FULL_RESTORE },
#line 13965
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 13966
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
#line 13967
        .mugshotColor = MUGSHOT_COLOR_PINK,
        .partySize = 5,
        .party = (const struct TrainerMon[])
        {
            {
#line 13969
            .species = SPECIES_GENGAR,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13971
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 13970
            .lvl = 66,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 13972
                MOVE_SHADOW_BALL,
                MOVE_PSYCHIC,
                MOVE_CONFUSE_RAY,
                MOVE_HYPNOSIS,
            },
            },
            {
#line 13977
            .species = SPECIES_CROBAT,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13979
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 13978
            .lvl = 66,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 13980
                MOVE_SLUDGE_BOMB,
                MOVE_AIR_CUTTER,
                MOVE_SHADOW_BALL,
                MOVE_CONFUSE_RAY,
            },
            },
            {
#line 13985
            .species = SPECIES_MISDREAVUS,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13987
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 13986
            .lvl = 65,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 13988
                MOVE_SHADOW_BALL,
                MOVE_PSYCHIC,
                MOVE_THUNDERBOLT,
                MOVE_ATTRACT,
            },
            },
            {
#line 13993
            .species = SPECIES_ARBOK,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13995
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 13994
            .lvl = 68,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 13996
                MOVE_SLUDGE_BOMB,
                MOVE_EARTHQUAKE,
                MOVE_GIGA_DRAIN,
                MOVE_DOUBLE_TEAM,
            },
            },
            {
#line 14001
            .species = SPECIES_GENGAR,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 14001
            .heldItem = ITEM_CHESTO_BERRY,
#line 14003
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 14002
            .lvl = 70,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 14004
                MOVE_SHADOW_BALL,
                MOVE_PSYCHIC,
                MOVE_THUNDERBOLT,
                MOVE_SLUDGE_BOMB,
            },
            },
        },
    },
#line 14009
    [DIFFICULTY_NORMAL][TRAINER_ELITE_FOUR_LANCE_2] =
    {
#line 14010
        .trainerName = _("LANCE"),
#line 14011
        .trainerClass = TRAINER_CLASS_ELITE_FOUR,
#line 14012
        .trainerPic = TRAINER_PIC_ELITE_FOUR_LANCE,
        .encounterMusic_gender =
#line 14014
            TRAINER_ENCOUNTER_MUSIC_ELITE_FOUR,
#line 14015
        .items = { ITEM_FULL_RESTORE, ITEM_FULL_RESTORE },
#line 14016
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 14017
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
#line 14018
        .mugshotColor = MUGSHOT_COLOR_BLUE,
        .partySize = 5,
        .party = (const struct TrainerMon[])
        {
            {
#line 14020
            .species = SPECIES_GYARADOS,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 14022
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 14021
            .lvl = 68,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 14023
                MOVE_HYPER_BEAM,
                MOVE_DRAGON_DANCE,
                MOVE_EARTHQUAKE,
                MOVE_THUNDER_WAVE,
            },
            },
            {
#line 14028
            .species = SPECIES_DRAGONITE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 14030
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 14029
            .lvl = 66,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 14031
                MOVE_HYPER_BEAM,
                MOVE_EARTHQUAKE,
                MOVE_DRAGON_CLAW,
                MOVE_FLAMETHROWER,
            },
            },
            {
#line 14036
            .species = SPECIES_KINGDRA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 14038
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 14037
            .lvl = 66,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 14039
                MOVE_HYPER_BEAM,
                MOVE_DRAGON_DANCE,
                MOVE_SURF,
                MOVE_ICE_BEAM,
            },
            },
            {
#line 14044
            .species = SPECIES_AERODACTYL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 14046
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 14045
            .lvl = 70,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 14047
                MOVE_HYPER_BEAM,
                MOVE_ANCIENT_POWER,
                MOVE_AERIAL_ACE,
                MOVE_EARTHQUAKE,
            },
            },
            {
#line 14052
            .species = SPECIES_DRAGONITE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 14052
            .heldItem = ITEM_PERSIM_BERRY,
#line 14054
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 14053
            .lvl = 72,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 14055
                MOVE_HYPER_BEAM,
                MOVE_OUTRAGE,
                MOVE_THUNDERBOLT,
                MOVE_ICE_BEAM,
            },
            },
        },
    },
#line 14060
    [DIFFICULTY_NORMAL][TRAINER_CHAMPION_REMATCH_SQUIRTLE] =
    {
#line 14061
        .trainerName = _("TERRY"),
#line 14062
        .trainerClass = TRAINER_CLASS_CHAMPION,
#line 14063
        .trainerPic = TRAINER_PIC_CHAMPION_RIVAL,
        .encounterMusic_gender =
#line 14065
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 14066
        .items = { ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_FULL_RESTORE },
#line 14067
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 14068
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
#line 14069
        .mugshotColor = MUGSHOT_COLOR_YELLOW,
        .partySize = 6,
        .party = (const struct TrainerMon[])
        {
            {
#line 14071
            .species = SPECIES_HERACROSS,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 14073
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 14072
            .lvl = 72,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 14074
                MOVE_MEGAHORN,
                MOVE_EARTHQUAKE,
                MOVE_COUNTER,
                MOVE_ROCK_TOMB,
            },
            },
            {
#line 14079
            .species = SPECIES_ALAKAZAM,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 14081
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 14080
            .lvl = 73,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 14082
                MOVE_PSYCHIC,
                MOVE_SHADOW_BALL,
                MOVE_CALM_MIND,
                MOVE_REFLECT,
            },
            },
            {
#line 14087
            .species = SPECIES_TYRANITAR,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 14089
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 14088
            .lvl = 72,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 14090
                MOVE_CRUNCH,
                MOVE_EARTHQUAKE,
                MOVE_THUNDERBOLT,
                MOVE_AERIAL_ACE,
            },
            },
            {
#line 14095
            .species = SPECIES_ARCANINE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 14097
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 14096
            .lvl = 73,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 14098
                MOVE_EXTREME_SPEED,
                MOVE_OVERHEAT,
                MOVE_AERIAL_ACE,
                MOVE_IRON_TAIL,
            },
            },
            {
#line 14103
            .species = SPECIES_EXEGGUTOR,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 14105
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 14104
            .lvl = 73,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 14106
                MOVE_GIGA_DRAIN,
                MOVE_PSYCHIC,
                MOVE_SLEEP_POWDER,
                MOVE_LIGHT_SCREEN,
            },
            },
            {
#line 14111
            .species = SPECIES_BLASTOISE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 14111
            .heldItem = ITEM_SITRUS_BERRY,
#line 14113
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 14112
            .lvl = 75,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 14114
                MOVE_HYDRO_PUMP,
                MOVE_ICE_BEAM,
                MOVE_EARTHQUAKE,
                MOVE_RAIN_DANCE,
            },
            },
        },
    },
#line 14119
    [DIFFICULTY_NORMAL][TRAINER_CHAMPION_REMATCH_BULBASAUR] =
    {
#line 14120
        .trainerName = _("TERRY"),
#line 14121
        .trainerClass = TRAINER_CLASS_CHAMPION,
#line 14122
        .trainerPic = TRAINER_PIC_CHAMPION_RIVAL,
        .encounterMusic_gender =
#line 14124
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 14125
        .items = { ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_FULL_RESTORE },
#line 14126
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 14127
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
#line 14128
        .mugshotColor = MUGSHOT_COLOR_YELLOW,
        .partySize = 6,
        .party = (const struct TrainerMon[])
        {
            {
#line 14130
            .species = SPECIES_HERACROSS,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 14132
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 14131
            .lvl = 72,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 14133
                MOVE_MEGAHORN,
                MOVE_EARTHQUAKE,
                MOVE_COUNTER,
                MOVE_ROCK_TOMB,
            },
            },
            {
#line 14138
            .species = SPECIES_ALAKAZAM,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 14140
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 14139
            .lvl = 73,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 14141
                MOVE_PSYCHIC,
                MOVE_SHADOW_BALL,
                MOVE_CALM_MIND,
                MOVE_REFLECT,
            },
            },
            {
#line 14146
            .species = SPECIES_TYRANITAR,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 14148
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 14147
            .lvl = 72,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 14149
                MOVE_CRUNCH,
                MOVE_EARTHQUAKE,
                MOVE_THUNDERBOLT,
                MOVE_AERIAL_ACE,
            },
            },
            {
#line 14154
            .species = SPECIES_GYARADOS,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 14156
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 14155
            .lvl = 73,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 14157
                MOVE_HYDRO_PUMP,
                MOVE_DRAGON_DANCE,
                MOVE_EARTHQUAKE,
                MOVE_HYPER_BEAM,
            },
            },
            {
#line 14162
            .species = SPECIES_ARCANINE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 14164
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 14163
            .lvl = 73,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 14165
                MOVE_EXTREME_SPEED,
                MOVE_OVERHEAT,
                MOVE_AERIAL_ACE,
                MOVE_IRON_TAIL,
            },
            },
            {
#line 14170
            .species = SPECIES_VENUSAUR,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 14170
            .heldItem = ITEM_SITRUS_BERRY,
#line 14172
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 14171
            .lvl = 75,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 14173
                MOVE_SOLAR_BEAM,
                MOVE_SLUDGE_BOMB,
                MOVE_EARTHQUAKE,
                MOVE_SUNNY_DAY,
            },
            },
        },
    },
#line 14178
    [DIFFICULTY_NORMAL][TRAINER_CHAMPION_REMATCH_CHARMANDER] =
    {
#line 14179
        .trainerName = _("TERRY"),
#line 14180
        .trainerClass = TRAINER_CLASS_CHAMPION,
#line 14181
        .trainerPic = TRAINER_PIC_CHAMPION_RIVAL,
        .encounterMusic_gender =
#line 14183
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 14184
        .items = { ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_FULL_RESTORE },
#line 14185
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 14186
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
#line 14187
        .mugshotColor = MUGSHOT_COLOR_YELLOW,
        .partySize = 6,
        .party = (const struct TrainerMon[])
        {
            {
#line 14189
            .species = SPECIES_HERACROSS,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 14191
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 14190
            .lvl = 72,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 14192
                MOVE_MEGAHORN,
                MOVE_EARTHQUAKE,
                MOVE_COUNTER,
                MOVE_ROCK_TOMB,
            },
            },
            {
#line 14197
            .species = SPECIES_ALAKAZAM,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 14199
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 14198
            .lvl = 73,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 14200
                MOVE_PSYCHIC,
                MOVE_SHADOW_BALL,
                MOVE_CALM_MIND,
                MOVE_REFLECT,
            },
            },
            {
#line 14205
            .species = SPECIES_TYRANITAR,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 14207
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 14206
            .lvl = 72,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 14208
                MOVE_CRUNCH,
                MOVE_EARTHQUAKE,
                MOVE_THUNDERBOLT,
                MOVE_AERIAL_ACE,
            },
            },
            {
#line 14213
            .species = SPECIES_EXEGGUTOR,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 14215
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 14214
            .lvl = 73,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 14216
                MOVE_GIGA_DRAIN,
                MOVE_PSYCHIC,
                MOVE_SLEEP_POWDER,
                MOVE_LIGHT_SCREEN,
            },
            },
            {
#line 14221
            .species = SPECIES_GYARADOS,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 14223
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 14222
            .lvl = 73,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 14224
                MOVE_HYDRO_PUMP,
                MOVE_DRAGON_DANCE,
                MOVE_EARTHQUAKE,
                MOVE_HYPER_BEAM,
            },
            },
            {
#line 14229
            .species = SPECIES_CHARIZARD,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 14229
            .heldItem = ITEM_SITRUS_BERRY,
#line 14231
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 14230
            .lvl = 75,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 14232
                MOVE_FIRE_BLAST,
                MOVE_DRAGON_CLAW,
                MOVE_AERIAL_ACE,
                MOVE_EARTHQUAKE,
            },
            },
        },
    },
#line 14237
    [DIFFICULTY_NORMAL][TRAINER_CUE_BALL_PAXTON] =
    {
#line 14238
        .trainerName = _("PAXTON"),
#line 14239
        .trainerClass = TRAINER_CLASS_CUE_BALL,
#line 14240
        .trainerPic = TRAINER_PIC_CUE_BALL,
        .encounterMusic_gender =
#line 14242
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 14243
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 14244
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 14246
            .species = SPECIES_WEEZING,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 14248
            .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
#line 14247
            .lvl = 39,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 14250
            .species = SPECIES_MUK,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 14252
            .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
#line 14251
            .lvl = 39,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
