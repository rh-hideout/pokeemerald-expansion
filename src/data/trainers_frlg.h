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
    [DIFFICULTY_NORMAL][TRAINER_BUG_CATCHER_BRENT] =
    {
#line 434
        .trainerName = _("BRENT"),
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
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 442
            .species = SPECIES_BEEDRILL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 444
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 443
            .lvl = 19,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 446
            .species = SPECIES_BEEDRILL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 448
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 447
            .lvl = 19,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 450
    [DIFFICULTY_NORMAL][TRAINER_BUG_CATCHER_CONNER] =
    {
#line 451
        .trainerName = _("CONNER"),
#line 452
        .trainerClass = TRAINER_CLASS_BUG_CATCHER,
#line 453
        .trainerPic = TRAINER_PIC_BUG_CATCHER,
        .encounterMusic_gender =
#line 455
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 456
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 457
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 459
            .species = SPECIES_CATERPIE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 461
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 460
            .lvl = 20,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 463
            .species = SPECIES_WEEDLE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 465
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 464
            .lvl = 20,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 467
            .species = SPECIES_VENONAT,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 469
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 468
            .lvl = 20,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 471
    [DIFFICULTY_NORMAL][TRAINER_LASS_JANICE] =
    {
#line 472
        .trainerName = _("JANICE"),
#line 473
        .trainerClass = TRAINER_CLASS_LASS,
#line 474
        .trainerPic = TRAINER_PIC_LASS,
        .encounterMusic_gender =
#line 476
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
#line 477
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 478
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 480
            .species = SPECIES_PIDGEY,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 482
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 481
            .lvl = 9,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 484
            .species = SPECIES_PIDGEY,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 486
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 485
            .lvl = 9,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 488
    [DIFFICULTY_NORMAL][TRAINER_LASS_SALLY] =
    {
#line 489
        .trainerName = _("SALLY"),
#line 490
        .trainerClass = TRAINER_CLASS_LASS,
#line 491
        .trainerPic = TRAINER_PIC_LASS,
        .encounterMusic_gender =
#line 493
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
#line 494
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 495
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 497
            .species = SPECIES_RATTATA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 499
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 498
            .lvl = 10,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 501
            .species = SPECIES_NIDORAN_F,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 503
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 502
            .lvl = 10,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 505
    [DIFFICULTY_NORMAL][TRAINER_LASS_ROBIN] =
    {
#line 506
        .trainerName = _("ROBIN"),
#line 507
        .trainerClass = TRAINER_CLASS_LASS,
#line 508
        .trainerPic = TRAINER_PIC_LASS,
        .encounterMusic_gender =
#line 510
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
#line 511
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 512
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 514
            .species = SPECIES_JIGGLYPUFF,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 516
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 515
            .lvl = 14,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 518
    [DIFFICULTY_NORMAL][TRAINER_LASS_CRISSY] =
    {
#line 519
        .trainerName = _("CRISSY"),
#line 520
        .trainerClass = TRAINER_CLASS_LASS,
#line 521
        .trainerPic = TRAINER_PIC_LASS,
        .encounterMusic_gender =
#line 523
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
#line 524
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 525
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 527
            .species = SPECIES_PARAS,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 529
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 528
            .lvl = 31,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 531
            .species = SPECIES_PARAS,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 533
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 532
            .lvl = 31,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 535
            .species = SPECIES_PARASECT,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 537
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 536
            .lvl = 31,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 539
    [DIFFICULTY_NORMAL][TRAINER_LASS_MIRIAM] =
    {
#line 540
        .trainerName = _("MIRIAM"),
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
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 548
            .species = SPECIES_ODDISH,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 550
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 549
            .lvl = 11,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 552
            .species = SPECIES_BELLSPROUT,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 554
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 553
            .lvl = 11,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 556
    [DIFFICULTY_NORMAL][TRAINER_LASS_IRIS] =
    {
#line 557
        .trainerName = _("IRIS"),
#line 558
        .trainerClass = TRAINER_CLASS_LASS,
#line 559
        .trainerPic = TRAINER_PIC_LASS,
        .encounterMusic_gender =
#line 561
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
#line 562
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 563
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 565
            .species = SPECIES_CLEFAIRY,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 567
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 566
            .lvl = 14,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 569
    [DIFFICULTY_NORMAL][TRAINER_LASS_RELI] =
    {
#line 570
        .trainerName = _("RELI"),
#line 571
        .trainerClass = TRAINER_CLASS_LASS,
#line 572
        .trainerPic = TRAINER_PIC_LASS,
        .encounterMusic_gender =
#line 574
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
#line 575
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 576
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 578
            .species = SPECIES_NIDORAN_M,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 580
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 579
            .lvl = 16,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 582
            .species = SPECIES_NIDORAN_F,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 584
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 583
            .lvl = 16,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 586
    [DIFFICULTY_NORMAL][TRAINER_LASS_ALI] =
    {
#line 587
        .trainerName = _("ALI"),
#line 588
        .trainerClass = TRAINER_CLASS_LASS,
#line 589
        .trainerPic = TRAINER_PIC_LASS,
        .encounterMusic_gender =
#line 591
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
#line 592
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 593
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 595
            .species = SPECIES_PIDGEY,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 597
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 596
            .lvl = 12,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 599
            .species = SPECIES_ODDISH,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 601
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 600
            .lvl = 12,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 603
            .species = SPECIES_BELLSPROUT,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 605
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 604
            .lvl = 12,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 607
    [DIFFICULTY_NORMAL][TRAINER_LASS_HALEY] =
    {
#line 608
        .trainerName = _("HALEY"),
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
            .species = SPECIES_ODDISH,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 618
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 617
            .lvl = 13,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 620
            .species = SPECIES_PIDGEY,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 622
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 621
            .lvl = 13,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 624
            .species = SPECIES_ODDISH,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 626
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 625
            .lvl = 13,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 628
    [DIFFICULTY_NORMAL][TRAINER_LASS_ANN] =
    {
#line 629
        .trainerName = _("ANN"),
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
            .species = SPECIES_PIDGEY,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 639
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 638
            .lvl = 18,
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
            .lvl = 18,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 645
    [DIFFICULTY_NORMAL][TRAINER_LASS_DAWN] =
    {
#line 646
        .trainerName = _("DAWN"),
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
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 654
            .species = SPECIES_RATTATA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 656
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 655
            .lvl = 18,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 658
            .species = SPECIES_PIKACHU,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 660
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 659
            .lvl = 18,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 662
    [DIFFICULTY_NORMAL][TRAINER_LASS_PAIGE] =
    {
#line 663
        .trainerName = _("PAIGE"),
#line 664
        .trainerClass = TRAINER_CLASS_LASS,
#line 665
        .trainerPic = TRAINER_PIC_LASS,
        .encounterMusic_gender =
#line 667
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
#line 668
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 669
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 671
            .species = SPECIES_NIDORAN_F,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 673
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 672
            .lvl = 23,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 675
            .species = SPECIES_NIDORINA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 677
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 676
            .lvl = 23,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 679
    [DIFFICULTY_NORMAL][TRAINER_LASS_ANDREA] =
    {
#line 680
        .trainerName = _("ANDREA"),
#line 681
        .trainerClass = TRAINER_CLASS_LASS,
#line 682
        .trainerPic = TRAINER_PIC_LASS,
        .encounterMusic_gender =
#line 684
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
#line 685
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 686
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 688
            .species = SPECIES_MEOWTH,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 690
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 689
            .lvl = 24,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 692
            .species = SPECIES_MEOWTH,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 694
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 693
            .lvl = 24,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 696
            .species = SPECIES_MEOWTH,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 698
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 697
            .lvl = 24,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 700
    [DIFFICULTY_NORMAL][TRAINER_LASS_MEGAN] =
    {
#line 701
        .trainerName = _("MEGAN"),
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
        .partySize = 5,
        .party = (const struct TrainerMon[])
        {
            {
#line 709
            .species = SPECIES_PIDGEY,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 711
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 710
            .lvl = 19,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 713
            .species = SPECIES_RATTATA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 715
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 714
            .lvl = 19,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 717
            .species = SPECIES_NIDORAN_M,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 719
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 718
            .lvl = 19,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 721
            .species = SPECIES_MEOWTH,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 723
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 722
            .lvl = 19,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 725
            .species = SPECIES_PIKACHU,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 727
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 726
            .lvl = 19,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 729
    [DIFFICULTY_NORMAL][TRAINER_LASS_JULIA] =
    {
#line 730
        .trainerName = _("JULIA"),
#line 731
        .trainerClass = TRAINER_CLASS_LASS,
#line 732
        .trainerPic = TRAINER_PIC_LASS,
        .encounterMusic_gender =
#line 734
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
#line 735
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 736
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 738
            .species = SPECIES_CLEFAIRY,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 740
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 739
            .lvl = 22,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 742
            .species = SPECIES_CLEFAIRY,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 744
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 743
            .lvl = 22,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 746
    [DIFFICULTY_NORMAL][TRAINER_LASS_KAY] =
    {
#line 747
        .trainerName = _("KAY"),
#line 748
        .trainerClass = TRAINER_CLASS_LASS,
#line 749
        .trainerPic = TRAINER_PIC_LASS,
        .encounterMusic_gender =
#line 751
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
#line 752
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 753
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 755
            .species = SPECIES_BELLSPROUT,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 757
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 756
            .lvl = 23,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 759
            .species = SPECIES_WEEPINBELL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 761
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 760
            .lvl = 23,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 763
    [DIFFICULTY_NORMAL][TRAINER_LASS_LISA] =
    {
#line 764
        .trainerName = _("LISA"),
#line 765
        .trainerClass = TRAINER_CLASS_LASS,
#line 766
        .trainerPic = TRAINER_PIC_LASS,
        .encounterMusic_gender =
#line 768
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
#line 769
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 770
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 772
            .species = SPECIES_ODDISH,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 774
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 773
            .lvl = 23,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 776
            .species = SPECIES_GLOOM,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 778
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 777
            .lvl = 23,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 780
    [DIFFICULTY_NORMAL][TRAINER_SAILOR_EDMOND] =
    {
#line 781
        .trainerName = _("EDMOND"),
#line 782
        .trainerClass = TRAINER_CLASS_SAILOR,
#line 783
        .trainerPic = TRAINER_PIC_SAILOR,
        .encounterMusic_gender =
#line 785
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 786
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 787
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 789
            .species = SPECIES_MACHOP,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 791
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 790
            .lvl = 18,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 793
            .species = SPECIES_SHELLDER,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 795
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 794
            .lvl = 18,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 797
    [DIFFICULTY_NORMAL][TRAINER_SAILOR_TREVOR] =
    {
#line 798
        .trainerName = _("TREVOR"),
#line 799
        .trainerClass = TRAINER_CLASS_SAILOR,
#line 800
        .trainerPic = TRAINER_PIC_SAILOR,
        .encounterMusic_gender =
#line 802
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 803
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 804
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 806
            .species = SPECIES_MACHOP,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 808
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 807
            .lvl = 17,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 810
            .species = SPECIES_TENTACOOL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 812
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 811
            .lvl = 17,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 814
    [DIFFICULTY_NORMAL][TRAINER_SAILOR_LEONARD] =
    {
#line 815
        .trainerName = _("LEONARD"),
#line 816
        .trainerClass = TRAINER_CLASS_SAILOR,
#line 817
        .trainerPic = TRAINER_PIC_SAILOR,
        .encounterMusic_gender =
#line 819
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 820
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 821
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 823
            .species = SPECIES_SHELLDER,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 825
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 824
            .lvl = 21,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 827
    [DIFFICULTY_NORMAL][TRAINER_SAILOR_DUNCAN] =
    {
#line 828
        .trainerName = _("DUNCAN"),
#line 829
        .trainerClass = TRAINER_CLASS_SAILOR,
#line 830
        .trainerPic = TRAINER_PIC_SAILOR,
        .encounterMusic_gender =
#line 832
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 833
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 834
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 836
            .species = SPECIES_HORSEA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 838
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 837
            .lvl = 17,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 840
            .species = SPECIES_SHELLDER,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 842
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 841
            .lvl = 17,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 844
            .species = SPECIES_TENTACOOL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 846
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 845
            .lvl = 17,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 848
    [DIFFICULTY_NORMAL][TRAINER_SAILOR_HUEY] =
    {
#line 849
        .trainerName = _("HUEY"),
#line 850
        .trainerClass = TRAINER_CLASS_SAILOR,
#line 851
        .trainerPic = TRAINER_PIC_SAILOR,
        .encounterMusic_gender =
#line 853
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 854
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 855
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 857
            .species = SPECIES_TENTACOOL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 859
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 858
            .lvl = 18,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 861
            .species = SPECIES_STARYU,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 863
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 862
            .lvl = 18,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 865
    [DIFFICULTY_NORMAL][TRAINER_SAILOR_DYLAN] =
    {
#line 866
        .trainerName = _("DYLAN"),
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
            .species = SPECIES_HORSEA,
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
            .species = SPECIES_HORSEA,
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
    [DIFFICULTY_NORMAL][TRAINER_SAILOR_PHILLIP] =
    {
#line 887
        .trainerName = _("PHILLIP"),
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
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 895
            .species = SPECIES_MACHOP,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 897
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 896
            .lvl = 20,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 899
    [DIFFICULTY_NORMAL][TRAINER_SAILOR_DWAYNE] =
    {
#line 900
        .trainerName = _("DWAYNE"),
#line 901
        .trainerClass = TRAINER_CLASS_SAILOR,
#line 902
        .trainerPic = TRAINER_PIC_SAILOR,
        .encounterMusic_gender =
#line 904
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 905
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 906
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 908
            .species = SPECIES_PIKACHU,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 910
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 909
            .lvl = 21,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 912
            .species = SPECIES_PIKACHU,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 914
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 913
            .lvl = 21,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 916
    [DIFFICULTY_NORMAL][TRAINER_CAMPER_LIAM] =
    {
#line 917
        .trainerName = _("LIAM"),
#line 918
        .trainerClass = TRAINER_CLASS_CAMPER,
#line 919
        .trainerPic = TRAINER_PIC_CAMPER,
        .encounterMusic_gender =
#line 921
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 922
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 923
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 925
            .species = SPECIES_GEODUDE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 927
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 926
            .lvl = 10,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 928
                MOVE_TACKLE,
                MOVE_DEFENSE_CURL,
            },
            },
            {
#line 931
            .species = SPECIES_SANDSHREW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 933
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 932
            .lvl = 11,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 934
                MOVE_SCRATCH,
                MOVE_DEFENSE_CURL,
                MOVE_SAND_ATTACK,
            },
            },
        },
    },
#line 938
    [DIFFICULTY_NORMAL][TRAINER_CAMPER_SHANE] =
    {
#line 939
        .trainerName = _("SHANE"),
#line 940
        .trainerClass = TRAINER_CLASS_CAMPER,
#line 941
        .trainerPic = TRAINER_PIC_CAMPER,
        .encounterMusic_gender =
#line 943
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 944
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 945
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 947
            .species = SPECIES_RATTATA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 949
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 948
            .lvl = 14,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 951
            .species = SPECIES_EKANS,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 953
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 952
            .lvl = 14,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 955
    [DIFFICULTY_NORMAL][TRAINER_CAMPER_ETHAN] =
    {
#line 956
        .trainerName = _("ETHAN"),
#line 957
        .trainerClass = TRAINER_CLASS_CAMPER,
#line 958
        .trainerPic = TRAINER_PIC_CAMPER,
        .encounterMusic_gender =
#line 960
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 961
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 962
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 964
            .species = SPECIES_MANKEY,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 966
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 965
            .lvl = 18,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 968
    [DIFFICULTY_NORMAL][TRAINER_CAMPER_RICKY] =
    {
#line 969
        .trainerName = _("RICKY"),
#line 970
        .trainerClass = TRAINER_CLASS_CAMPER,
#line 971
        .trainerPic = TRAINER_PIC_CAMPER,
        .encounterMusic_gender =
#line 973
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 974
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 975
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 977
            .species = SPECIES_SQUIRTLE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 979
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 978
            .lvl = 20,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 981
    [DIFFICULTY_NORMAL][TRAINER_CAMPER_JEFF] =
    {
#line 982
        .trainerName = _("JEFF"),
#line 983
        .trainerClass = TRAINER_CLASS_CAMPER,
#line 984
        .trainerPic = TRAINER_PIC_CAMPER,
        .encounterMusic_gender =
#line 986
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 987
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 988
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 990
            .species = SPECIES_SPEAROW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 992
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 991
            .lvl = 16,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 994
            .species = SPECIES_RATICATE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 996
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 995
            .lvl = 16,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 998
    [DIFFICULTY_NORMAL][TRAINER_CAMPER_CHRIS] =
    {
#line 999
        .trainerName = _("CHRIS"),
#line 1000
        .trainerClass = TRAINER_CLASS_CAMPER,
#line 1001
        .trainerPic = TRAINER_PIC_CAMPER,
        .encounterMusic_gender =
#line 1003
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 1004
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 1005
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 1007
            .species = SPECIES_GROWLITHE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1009
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 1008
            .lvl = 21,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 1011
            .species = SPECIES_CHARMANDER,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1013
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 1012
            .lvl = 21,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 1015
    [DIFFICULTY_NORMAL][TRAINER_CAMPER_DREW] =
    {
#line 1016
        .trainerName = _("DREW"),
#line 1017
        .trainerClass = TRAINER_CLASS_CAMPER,
#line 1018
        .trainerPic = TRAINER_PIC_CAMPER,
        .encounterMusic_gender =
#line 1020
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 1021
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 1022
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 4,
        .party = (const struct TrainerMon[])
        {
            {
#line 1024
            .species = SPECIES_RATTATA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1026
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 1025
            .lvl = 19,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 1028
            .species = SPECIES_SANDSHREW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1030
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 1029
            .lvl = 19,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 1032
            .species = SPECIES_EKANS,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1034
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 1033
            .lvl = 19,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 1036
            .species = SPECIES_SANDSHREW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1038
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 1037
            .lvl = 19,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 1040
    [DIFFICULTY_NORMAL][TRAINER_PICNICKER_DIANA] =
    {
#line 1041
        .trainerName = _("DIANA"),
#line 1042
        .trainerClass = TRAINER_CLASS_PICNICKER,
#line 1043
        .trainerPic = TRAINER_PIC_PICNICKER,
        .encounterMusic_gender =
#line 1045
            TRAINER_ENCOUNTER_MUSIC_GIRL,
#line 1046
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 1047
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 1049
            .species = SPECIES_GOLDEEN,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1051
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 1050
            .lvl = 19,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 1053
    [DIFFICULTY_NORMAL][TRAINER_PICNICKER_NANCY] =
    {
#line 1054
        .trainerName = _("NANCY"),
#line 1055
        .trainerClass = TRAINER_CLASS_PICNICKER,
#line 1056
        .trainerPic = TRAINER_PIC_PICNICKER,
        .encounterMusic_gender =
#line 1058
            TRAINER_ENCOUNTER_MUSIC_GIRL,
#line 1059
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 1060
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 1062
            .species = SPECIES_RATTATA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1064
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 1063
            .lvl = 16,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 1066
            .species = SPECIES_PIKACHU,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1068
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 1067
            .lvl = 16,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 1070
    [DIFFICULTY_NORMAL][TRAINER_PICNICKER_ISABELLE] =
    {
#line 1071
        .trainerName = _("ISABELLE"),
#line 1072
        .trainerClass = TRAINER_CLASS_PICNICKER,
#line 1073
        .trainerPic = TRAINER_PIC_PICNICKER,
        .encounterMusic_gender =
#line 1075
            TRAINER_ENCOUNTER_MUSIC_GIRL,
#line 1076
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 1077
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 1079
            .species = SPECIES_PIDGEY,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1081
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 1080
            .lvl = 16,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 1083
            .species = SPECIES_PIDGEY,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1085
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 1084
            .lvl = 16,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 1087
            .species = SPECIES_PIDGEY,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1089
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 1088
            .lvl = 16,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 1091
    [DIFFICULTY_NORMAL][TRAINER_PICNICKER_KELSEY] =
    {
#line 1092
        .trainerName = _("KELSEY"),
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
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 1100
            .species = SPECIES_NIDORAN_M,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1102
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 1101
            .lvl = 15,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 1104
            .species = SPECIES_NIDORAN_F,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1106
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 1105
            .lvl = 15,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 1108
    [DIFFICULTY_NORMAL][TRAINER_PICNICKER_ALICIA] =
    {
#line 1109
        .trainerName = _("ALICIA"),
#line 1110
        .trainerClass = TRAINER_CLASS_PICNICKER,
#line 1111
        .trainerPic = TRAINER_PIC_PICNICKER,
        .encounterMusic_gender =
#line 1113
            TRAINER_ENCOUNTER_MUSIC_GIRL,
#line 1114
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 1115
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 4,
        .party = (const struct TrainerMon[])
        {
            {
#line 1117
            .species = SPECIES_ODDISH,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1119
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 1118
            .lvl = 18,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 1121
            .species = SPECIES_BELLSPROUT,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1123
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 1122
            .lvl = 18,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 1125
            .species = SPECIES_ODDISH,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1127
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 1126
            .lvl = 18,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 1129
            .species = SPECIES_BELLSPROUT,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1131
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 1130
            .lvl = 18,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 1133
    [DIFFICULTY_NORMAL][TRAINER_PICNICKER_CAITLIN] =
    {
#line 1134
        .trainerName = _("CAITLIN"),
#line 1135
        .trainerClass = TRAINER_CLASS_PICNICKER,
#line 1136
        .trainerPic = TRAINER_PIC_PICNICKER,
        .encounterMusic_gender =
#line 1138
            TRAINER_ENCOUNTER_MUSIC_GIRL,
#line 1139
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 1140
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 1142
            .species = SPECIES_MEOWTH,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1144
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 1143
            .lvl = 23,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 1146
    [DIFFICULTY_NORMAL][TRAINER_PICNICKER_HEIDI] =
    {
#line 1147
        .trainerName = _("HEIDI"),
#line 1148
        .trainerClass = TRAINER_CLASS_PICNICKER,
#line 1149
        .trainerPic = TRAINER_PIC_PICNICKER,
        .encounterMusic_gender =
#line 1151
            TRAINER_ENCOUNTER_MUSIC_GIRL,
#line 1152
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 1153
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 1155
            .species = SPECIES_PIKACHU,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1157
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 1156
            .lvl = 20,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 1159
            .species = SPECIES_CLEFAIRY,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1161
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 1160
            .lvl = 20,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 1163
    [DIFFICULTY_NORMAL][TRAINER_PICNICKER_CAROL] =
    {
#line 1164
        .trainerName = _("CAROL"),
#line 1165
        .trainerClass = TRAINER_CLASS_PICNICKER,
#line 1166
        .trainerPic = TRAINER_PIC_PICNICKER,
        .encounterMusic_gender =
#line 1168
            TRAINER_ENCOUNTER_MUSIC_GIRL,
#line 1169
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 1170
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 1172
            .species = SPECIES_PIDGEY,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1174
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 1173
            .lvl = 21,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 1176
            .species = SPECIES_PIDGEOTTO,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1178
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 1177
            .lvl = 21,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 1180
    [DIFFICULTY_NORMAL][TRAINER_PICNICKER_SOFIA] =
    {
#line 1181
        .trainerName = _("SOFIA"),
#line 1182
        .trainerClass = TRAINER_CLASS_PICNICKER,
#line 1183
        .trainerPic = TRAINER_PIC_PICNICKER,
        .encounterMusic_gender =
#line 1185
            TRAINER_ENCOUNTER_MUSIC_GIRL,
#line 1186
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 1187
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 1189
            .species = SPECIES_JIGGLYPUFF,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1191
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 1190
            .lvl = 21,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 1193
            .species = SPECIES_PIDGEY,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1195
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 1194
            .lvl = 21,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 1197
            .species = SPECIES_MEOWTH,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1199
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 1198
            .lvl = 21,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 1201
    [DIFFICULTY_NORMAL][TRAINER_PICNICKER_MARTHA] =
    {
#line 1202
        .trainerName = _("MARTHA"),
#line 1203
        .trainerClass = TRAINER_CLASS_PICNICKER,
#line 1204
        .trainerPic = TRAINER_PIC_PICNICKER,
        .encounterMusic_gender =
#line 1206
            TRAINER_ENCOUNTER_MUSIC_GIRL,
#line 1207
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 1208
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 1210
            .species = SPECIES_ODDISH,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1212
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 1211
            .lvl = 22,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 1214
            .species = SPECIES_BULBASAUR,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1216
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 1215
            .lvl = 22,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 1218
    [DIFFICULTY_NORMAL][TRAINER_PICNICKER_TINA] =
    {
#line 1219
        .trainerName = _("TINA"),
#line 1220
        .trainerClass = TRAINER_CLASS_PICNICKER,
#line 1221
        .trainerPic = TRAINER_PIC_PICNICKER,
        .encounterMusic_gender =
#line 1223
            TRAINER_ENCOUNTER_MUSIC_GIRL,
#line 1224
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 1225
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 1227
            .species = SPECIES_BULBASAUR,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1229
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 1228
            .lvl = 24,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 1231
            .species = SPECIES_IVYSAUR,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1233
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 1232
            .lvl = 24,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 1235
    [DIFFICULTY_NORMAL][TRAINER_PICNICKER_HANNAH] =
    {
#line 1236
        .trainerName = _("HANNAH"),
#line 1237
        .trainerClass = TRAINER_CLASS_PICNICKER,
#line 1238
        .trainerPic = TRAINER_PIC_PICNICKER,
        .encounterMusic_gender =
#line 1240
            TRAINER_ENCOUNTER_MUSIC_GIRL,
#line 1241
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 1242
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 5,
        .party = (const struct TrainerMon[])
        {
            {
#line 1244
            .species = SPECIES_PIDGEY,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1246
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 1245
            .lvl = 24,
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
            .lvl = 24,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 1252
            .species = SPECIES_RATTATA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1254
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 1253
            .lvl = 24,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 1256
            .species = SPECIES_PIKACHU,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1258
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 1257
            .lvl = 24,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 1260
            .species = SPECIES_MEOWTH,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1262
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 1261
            .lvl = 24,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 1264
    [DIFFICULTY_NORMAL][TRAINER_POKEMANIAC_MARK] =
    {
#line 1265
        .trainerName = _("MARK"),
#line 1266
        .trainerClass = TRAINER_CLASS_POKEMANIAC,
#line 1267
        .trainerPic = TRAINER_PIC_POKEMANIAC,
        .encounterMusic_gender =
#line 1269
            TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
#line 1270
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 1271
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 1273
            .species = SPECIES_RHYHORN,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1275
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
#line 1274
            .lvl = 29,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 1277
            .species = SPECIES_LICKITUNG,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1279
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
#line 1278
            .lvl = 29,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 1281
    [DIFFICULTY_NORMAL][TRAINER_POKEMANIAC_HERMAN] =
    {
#line 1282
        .trainerName = _("HERMAN"),
#line 1283
        .trainerClass = TRAINER_CLASS_POKEMANIAC,
#line 1284
        .trainerPic = TRAINER_PIC_POKEMANIAC,
        .encounterMusic_gender =
#line 1286
            TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
#line 1287
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 1288
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 1290
            .species = SPECIES_CUBONE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1292
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
#line 1291
            .lvl = 20,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 1294
            .species = SPECIES_SLOWPOKE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1296
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
#line 1295
            .lvl = 20,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 1298
    [DIFFICULTY_NORMAL][TRAINER_POKEMANIAC_COOPER] =
    {
#line 1299
        .trainerName = _("COOPER"),
#line 1300
        .trainerClass = TRAINER_CLASS_POKEMANIAC,
#line 1301
        .trainerPic = TRAINER_PIC_POKEMANIAC,
        .encounterMusic_gender =
#line 1303
            TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
#line 1304
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 1305
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 1307
            .species = SPECIES_SLOWPOKE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1309
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
#line 1308
            .lvl = 20,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 1311
            .species = SPECIES_SLOWPOKE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1313
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
#line 1312
            .lvl = 20,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 1315
            .species = SPECIES_SLOWPOKE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1317
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
#line 1316
            .lvl = 20,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 1319
    [DIFFICULTY_NORMAL][TRAINER_POKEMANIAC_STEVE] =
    {
#line 1320
        .trainerName = _("STEVE"),
#line 1321
        .trainerClass = TRAINER_CLASS_POKEMANIAC,
#line 1322
        .trainerPic = TRAINER_PIC_POKEMANIAC,
        .encounterMusic_gender =
#line 1324
            TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
#line 1325
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 1326
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 1328
            .species = SPECIES_CHARMANDER,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1330
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
#line 1329
            .lvl = 22,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 1332
            .species = SPECIES_CUBONE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1334
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
#line 1333
            .lvl = 22,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 1336
    [DIFFICULTY_NORMAL][TRAINER_POKEMANIAC_WINSTON] =
    {
#line 1337
        .trainerName = _("WINSTON"),
#line 1338
        .trainerClass = TRAINER_CLASS_POKEMANIAC,
#line 1339
        .trainerPic = TRAINER_PIC_POKEMANIAC,
        .encounterMusic_gender =
#line 1341
            TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
#line 1342
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 1343
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 1345
            .species = SPECIES_SLOWPOKE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1347
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
#line 1346
            .lvl = 25,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 1349
    [DIFFICULTY_NORMAL][TRAINER_POKEMANIAC_DAWSON] =
    {
#line 1350
        .trainerName = _("DAWSON"),
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
            .species = SPECIES_CHARMELEON,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1360
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
#line 1359
            .lvl = 40,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 1362
            .species = SPECIES_LAPRAS,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1364
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
#line 1363
            .lvl = 40,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 1366
            .species = SPECIES_LICKITUNG,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1368
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
#line 1367
            .lvl = 40,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 1370
    [DIFFICULTY_NORMAL][TRAINER_POKEMANIAC_ASHTON] =
    {
#line 1371
        .trainerName = _("ASHTON"),
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
            .species = SPECIES_CUBONE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1381
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
#line 1380
            .lvl = 23,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 1383
            .species = SPECIES_SLOWPOKE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1385
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
#line 1384
            .lvl = 23,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 1387
    [DIFFICULTY_NORMAL][TRAINER_SUPER_NERD_JOVAN] =
    {
#line 1388
        .trainerName = _("JOVAN"),
#line 1389
        .trainerClass = TRAINER_CLASS_SUPER_NERD,
#line 1390
        .trainerPic = TRAINER_PIC_SUPER_NERD,
        .encounterMusic_gender =
#line 1392
            TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
#line 1393
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 1394
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 1396
            .species = SPECIES_MAGNEMITE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1398
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 1397
            .lvl = 11,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 1400
            .species = SPECIES_VOLTORB,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1402
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 1401
            .lvl = 11,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 1404
    [DIFFICULTY_NORMAL][TRAINER_SUPER_NERD_MIGUEL] =
    {
#line 1405
        .trainerName = _("MIGUEL"),
#line 1406
        .trainerClass = TRAINER_CLASS_SUPER_NERD,
#line 1407
        .trainerPic = TRAINER_PIC_SUPER_NERD,
        .encounterMusic_gender =
#line 1409
            TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
#line 1410
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 1411
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 1413
            .species = SPECIES_GRIMER,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1415
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 1414
            .lvl = 12,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 1417
            .species = SPECIES_VOLTORB,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1419
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 1418
            .lvl = 12,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 1421
            .species = SPECIES_KOFFING,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1423
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 1422
            .lvl = 12,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 1425
    [DIFFICULTY_NORMAL][TRAINER_SUPER_NERD_AIDAN] =
    {
#line 1426
        .trainerName = _("AIDAN"),
#line 1427
        .trainerClass = TRAINER_CLASS_SUPER_NERD,
#line 1428
        .trainerPic = TRAINER_PIC_SUPER_NERD,
        .encounterMusic_gender =
#line 1430
            TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
#line 1431
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 1432
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 4,
        .party = (const struct TrainerMon[])
        {
            {
#line 1434
            .species = SPECIES_VOLTORB,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1436
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 1435
            .lvl = 20,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 1437
                MOVE_SONIC_BOOM,
                MOVE_SCREECH,
                MOVE_TACKLE,
                MOVE_CHARGE,
            },
            },
            {
#line 1442
            .species = SPECIES_KOFFING,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1444
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 1443
            .lvl = 20,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 1445
                MOVE_SLUDGE,
                MOVE_SMOG,
                MOVE_TACKLE,
                MOVE_POISON_GAS,
            },
            },
            {
#line 1450
            .species = SPECIES_VOLTORB,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1452
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 1451
            .lvl = 20,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 1453
                MOVE_SONIC_BOOM,
                MOVE_SCREECH,
                MOVE_TACKLE,
                MOVE_CHARGE,
            },
            },
            {
#line 1458
            .species = SPECIES_MAGNEMITE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1460
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 1459
            .lvl = 20,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 1461
                MOVE_SONIC_BOOM,
                MOVE_SUPERSONIC,
                MOVE_THUNDER_SHOCK,
                MOVE_TACKLE,
            },
            },
        },
    },
#line 1466
    [DIFFICULTY_NORMAL][TRAINER_SUPER_NERD_GLENN] =
    {
#line 1467
        .trainerName = _("GLENN"),
#line 1468
        .trainerClass = TRAINER_CLASS_SUPER_NERD,
#line 1469
        .trainerPic = TRAINER_PIC_SUPER_NERD,
        .encounterMusic_gender =
#line 1471
            TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
#line 1472
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 1473
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 1475
            .species = SPECIES_GRIMER,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1477
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 1476
            .lvl = 22,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 1479
            .species = SPECIES_MUK,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1481
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 1480
            .lvl = 22,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 1483
            .species = SPECIES_GRIMER,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1485
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 1484
            .lvl = 22,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 1487
    [DIFFICULTY_NORMAL][TRAINER_SUPER_NERD_LESLIE] =
    {
#line 1488
        .trainerName = _("LESLIE"),
#line 1489
        .trainerClass = TRAINER_CLASS_SUPER_NERD,
#line 1490
        .trainerPic = TRAINER_PIC_SUPER_NERD,
        .encounterMusic_gender =
#line 1492
            TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
#line 1493
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 1494
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 1496
            .species = SPECIES_KOFFING,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1498
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 1497
            .lvl = 26,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 1499
                MOVE_SLUDGE,
                MOVE_SMOKESCREEN,
                MOVE_SMOG,
                MOVE_SELF_DESTRUCT,
            },
            },
        },
    },
#line 1504
    [DIFFICULTY_NORMAL][TRAINER_SUPER_NERD_ERIK] =
    {
#line 1505
        .trainerName = _("ERIK"),
#line 1506
        .trainerClass = TRAINER_CLASS_SUPER_NERD,
#line 1507
        .trainerPic = TRAINER_PIC_SUPER_NERD,
        .encounterMusic_gender =
#line 1509
            TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
#line 1510
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 1511
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 1513
            .species = SPECIES_VULPIX,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1515
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 1514
            .lvl = 36,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 1517
            .species = SPECIES_VULPIX,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1519
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 1518
            .lvl = 36,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 1521
            .species = SPECIES_NINETALES,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1523
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 1522
            .lvl = 36,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 1525
    [DIFFICULTY_NORMAL][TRAINER_SUPER_NERD_AVERY] =
    {
#line 1526
        .trainerName = _("AVERY"),
#line 1527
        .trainerClass = TRAINER_CLASS_SUPER_NERD,
#line 1528
        .trainerPic = TRAINER_PIC_SUPER_NERD,
        .encounterMusic_gender =
#line 1530
            TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
#line 1531
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 1532
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 4,
        .party = (const struct TrainerMon[])
        {
            {
#line 1534
            .species = SPECIES_PONYTA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1536
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 1535
            .lvl = 34,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 1538
            .species = SPECIES_CHARMANDER,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1540
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 1539
            .lvl = 34,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 1542
            .species = SPECIES_VULPIX,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1544
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 1543
            .lvl = 34,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 1546
            .species = SPECIES_GROWLITHE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1548
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 1547
            .lvl = 34,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 1550
    [DIFFICULTY_NORMAL][TRAINER_SUPER_NERD_DEREK] =
    {
#line 1551
        .trainerName = _("DEREK"),
#line 1552
        .trainerClass = TRAINER_CLASS_SUPER_NERD,
#line 1553
        .trainerPic = TRAINER_PIC_SUPER_NERD,
        .encounterMusic_gender =
#line 1555
            TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
#line 1556
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 1557
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 1559
            .species = SPECIES_RAPIDASH,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1561
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 1560
            .lvl = 41,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 1563
    [DIFFICULTY_NORMAL][TRAINER_SUPER_NERD_ZAC] =
    {
#line 1564
        .trainerName = _("ZAC"),
#line 1565
        .trainerClass = TRAINER_CLASS_SUPER_NERD,
#line 1566
        .trainerPic = TRAINER_PIC_SUPER_NERD,
        .encounterMusic_gender =
#line 1568
            TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
#line 1569
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 1570
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 1572
            .species = SPECIES_GROWLITHE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1574
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 1573
            .lvl = 37,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 1576
            .species = SPECIES_VULPIX,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1578
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 1577
            .lvl = 37,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 1580
    [DIFFICULTY_NORMAL][TRAINER_HIKER_MARCOS] =
    {
#line 1581
        .trainerName = _("MARCOS"),
#line 1582
        .trainerClass = TRAINER_CLASS_HIKER,
#line 1583
        .trainerPic = TRAINER_PIC_HIKER,
        .encounterMusic_gender =
#line 1585
            TRAINER_ENCOUNTER_MUSIC_HIKER,
#line 1586
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 1587
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 1589
            .species = SPECIES_GEODUDE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1591
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 1590
            .lvl = 10,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 1593
            .species = SPECIES_GEODUDE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1595
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 1594
            .lvl = 10,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 1597
            .species = SPECIES_ONIX,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1599
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 1598
            .lvl = 10,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 1601
    [DIFFICULTY_NORMAL][TRAINER_HIKER_FRANKLIN] =
    {
#line 1602
        .trainerName = _("FRANKLIN"),
#line 1603
        .trainerClass = TRAINER_CLASS_HIKER,
#line 1604
        .trainerPic = TRAINER_PIC_HIKER,
        .encounterMusic_gender =
#line 1606
            TRAINER_ENCOUNTER_MUSIC_HIKER,
#line 1607
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 1608
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 1610
            .species = SPECIES_MACHOP,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1612
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 1611
            .lvl = 15,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 1614
            .species = SPECIES_GEODUDE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1616
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 1615
            .lvl = 15,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 1618
    [DIFFICULTY_NORMAL][TRAINER_HIKER_NOB] =
    {
#line 1619
        .trainerName = _("NOB"),
#line 1620
        .trainerClass = TRAINER_CLASS_HIKER,
#line 1621
        .trainerPic = TRAINER_PIC_HIKER,
        .encounterMusic_gender =
#line 1623
            TRAINER_ENCOUNTER_MUSIC_HIKER,
#line 1624
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 1625
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 4,
        .party = (const struct TrainerMon[])
        {
            {
#line 1627
            .species = SPECIES_GEODUDE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1629
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 1628
            .lvl = 13,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 1631
            .species = SPECIES_GEODUDE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1633
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 1632
            .lvl = 13,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 1635
            .species = SPECIES_MACHOP,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1637
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 1636
            .lvl = 13,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 1639
            .species = SPECIES_GEODUDE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1641
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 1640
            .lvl = 13,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 1643
    [DIFFICULTY_NORMAL][TRAINER_HIKER_WAYNE] =
    {
#line 1644
        .trainerName = _("WAYNE"),
#line 1645
        .trainerClass = TRAINER_CLASS_HIKER,
#line 1646
        .trainerPic = TRAINER_PIC_HIKER,
        .encounterMusic_gender =
#line 1648
            TRAINER_ENCOUNTER_MUSIC_HIKER,
#line 1649
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 1650
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 1652
            .species = SPECIES_ONIX,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1654
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 1653
            .lvl = 17,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 1656
    [DIFFICULTY_NORMAL][TRAINER_HIKER_ALAN] =
    {
#line 1657
        .trainerName = _("ALAN"),
#line 1658
        .trainerClass = TRAINER_CLASS_HIKER,
#line 1659
        .trainerPic = TRAINER_PIC_HIKER,
        .encounterMusic_gender =
#line 1661
            TRAINER_ENCOUNTER_MUSIC_HIKER,
#line 1662
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 1663
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 1665
            .species = SPECIES_GEODUDE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1667
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 1666
            .lvl = 21,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 1668
                MOVE_MAGNITUDE,
                MOVE_ROCK_THROW,
                MOVE_MUD_SPORT,
                MOVE_DEFENSE_CURL,
            },
            },
            {
#line 1673
            .species = SPECIES_ONIX,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1675
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 1674
            .lvl = 21,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 1676
                MOVE_HARDEN,
                MOVE_ROCK_THROW,
                MOVE_BIND,
                MOVE_SCREECH,
            },
            },
        },
    },
#line 1681
    [DIFFICULTY_NORMAL][TRAINER_HIKER_BRICE] =
    {
#line 1682
        .trainerName = _("BRICE"),
#line 1683
        .trainerClass = TRAINER_CLASS_HIKER,
#line 1684
        .trainerPic = TRAINER_PIC_HIKER,
        .encounterMusic_gender =
#line 1686
            TRAINER_ENCOUNTER_MUSIC_HIKER,
#line 1687
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 1688
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 1690
            .species = SPECIES_GEODUDE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1692
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 1691
            .lvl = 20,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 1694
            .species = SPECIES_MACHOP,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1696
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 1695
            .lvl = 20,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 1698
            .species = SPECIES_GEODUDE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1700
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 1699
            .lvl = 20,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 1702
    [DIFFICULTY_NORMAL][TRAINER_HIKER_CLARK] =
    {
#line 1703
        .trainerName = _("CLARK"),
#line 1704
        .trainerClass = TRAINER_CLASS_HIKER,
#line 1705
        .trainerPic = TRAINER_PIC_HIKER,
        .encounterMusic_gender =
#line 1707
            TRAINER_ENCOUNTER_MUSIC_HIKER,
#line 1708
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 1709
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 1711
            .species = SPECIES_GEODUDE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1713
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 1712
            .lvl = 21,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 1714
                MOVE_MAGNITUDE,
                MOVE_ROCK_THROW,
                MOVE_MUD_SPORT,
                MOVE_DEFENSE_CURL,
            },
            },
            {
#line 1719
            .species = SPECIES_ONIX,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1721
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 1720
            .lvl = 21,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 1722
                MOVE_HARDEN,
                MOVE_ROCK_THROW,
                MOVE_BIND,
                MOVE_SCREECH,
            },
            },
        },
    },
#line 1727
    [DIFFICULTY_NORMAL][TRAINER_HIKER_TRENT] =
    {
#line 1728
        .trainerName = _("TRENT"),
#line 1729
        .trainerClass = TRAINER_CLASS_HIKER,
#line 1730
        .trainerPic = TRAINER_PIC_HIKER,
        .encounterMusic_gender =
#line 1732
            TRAINER_ENCOUNTER_MUSIC_HIKER,
#line 1733
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 1734
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 1736
            .species = SPECIES_ONIX,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1738
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 1737
            .lvl = 19,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 1740
            .species = SPECIES_GRAVELER,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1742
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 1741
            .lvl = 19,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 1744
    [DIFFICULTY_NORMAL][TRAINER_HIKER_DUDLEY] =
    {
#line 1745
        .trainerName = _("DUDLEY"),
#line 1746
        .trainerClass = TRAINER_CLASS_HIKER,
#line 1747
        .trainerPic = TRAINER_PIC_HIKER,
        .encounterMusic_gender =
#line 1749
            TRAINER_ENCOUNTER_MUSIC_HIKER,
#line 1750
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 1751
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 1753
            .species = SPECIES_GEODUDE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1755
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 1754
            .lvl = 21,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 1756
                MOVE_MAGNITUDE,
                MOVE_ROCK_THROW,
                MOVE_MUD_SPORT,
                MOVE_DEFENSE_CURL,
            },
            },
            {
#line 1761
            .species = SPECIES_GEODUDE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1763
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 1762
            .lvl = 21,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 1764
                MOVE_MAGNITUDE,
                MOVE_ROCK_THROW,
                MOVE_MUD_SPORT,
                MOVE_DEFENSE_CURL,
            },
            },
            {
#line 1769
            .species = SPECIES_GRAVELER,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1771
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 1770
            .lvl = 21,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 1772
                MOVE_MAGNITUDE,
                MOVE_ROCK_THROW,
                MOVE_MUD_SPORT,
                MOVE_DEFENSE_CURL,
            },
            },
        },
    },
#line 1777
    [DIFFICULTY_NORMAL][TRAINER_HIKER_ALLEN] =
    {
#line 1778
        .trainerName = _("ALLEN"),
#line 1779
        .trainerClass = TRAINER_CLASS_HIKER,
#line 1780
        .trainerPic = TRAINER_PIC_HIKER,
        .encounterMusic_gender =
#line 1782
            TRAINER_ENCOUNTER_MUSIC_HIKER,
#line 1783
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 1784
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 1786
            .species = SPECIES_GEODUDE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1788
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 1787
            .lvl = 25,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 1789
                MOVE_MAGNITUDE,
                MOVE_ROCK_THROW,
                MOVE_MUD_SPORT,
                MOVE_DEFENSE_CURL,
            },
            },
        },
    },
#line 1794
    [DIFFICULTY_NORMAL][TRAINER_HIKER_ERIC] =
    {
#line 1795
        .trainerName = _("ERIC"),
#line 1796
        .trainerClass = TRAINER_CLASS_HIKER,
#line 1797
        .trainerPic = TRAINER_PIC_HIKER,
        .encounterMusic_gender =
#line 1799
            TRAINER_ENCOUNTER_MUSIC_HIKER,
#line 1800
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 1801
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 1803
            .species = SPECIES_MACHOP,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1805
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 1804
            .lvl = 20,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 1807
            .species = SPECIES_ONIX,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1809
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 1808
            .lvl = 20,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 1811
    [DIFFICULTY_NORMAL][TRAINER_HIKER_LENNY] =
    {
#line 1812
        .trainerName = _("LENNY"),
#line 1813
        .trainerClass = TRAINER_CLASS_HIKER,
#line 1814
        .trainerPic = TRAINER_PIC_HIKER,
        .encounterMusic_gender =
#line 1816
            TRAINER_ENCOUNTER_MUSIC_HIKER,
#line 1817
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 1818
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 4,
        .party = (const struct TrainerMon[])
        {
            {
#line 1820
            .species = SPECIES_GEODUDE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1822
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 1821
            .lvl = 19,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 1824
            .species = SPECIES_MACHOP,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1826
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 1825
            .lvl = 19,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 1828
            .species = SPECIES_GEODUDE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1830
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 1829
            .lvl = 19,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 1832
            .species = SPECIES_GEODUDE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1834
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 1833
            .lvl = 19,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 1836
    [DIFFICULTY_NORMAL][TRAINER_HIKER_OLIVER] =
    {
#line 1837
        .trainerName = _("OLIVER"),
#line 1838
        .trainerClass = TRAINER_CLASS_HIKER,
#line 1839
        .trainerPic = TRAINER_PIC_HIKER,
        .encounterMusic_gender =
#line 1841
            TRAINER_ENCOUNTER_MUSIC_HIKER,
#line 1842
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 1843
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 1845
            .species = SPECIES_ONIX,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1847
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 1846
            .lvl = 20,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 1849
            .species = SPECIES_ONIX,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1851
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 1850
            .lvl = 20,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 1853
            .species = SPECIES_GEODUDE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1855
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 1854
            .lvl = 20,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 1857
    [DIFFICULTY_NORMAL][TRAINER_HIKER_LUCAS] =
    {
#line 1858
        .trainerName = _("LUCAS"),
#line 1859
        .trainerClass = TRAINER_CLASS_HIKER,
#line 1860
        .trainerPic = TRAINER_PIC_HIKER,
        .encounterMusic_gender =
#line 1862
            TRAINER_ENCOUNTER_MUSIC_HIKER,
#line 1863
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 1864
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 1866
            .species = SPECIES_GEODUDE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1868
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 1867
            .lvl = 21,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 1869
                MOVE_MAGNITUDE,
                MOVE_ROCK_THROW,
                MOVE_MUD_SPORT,
                MOVE_DEFENSE_CURL,
            },
            },
            {
#line 1874
            .species = SPECIES_GRAVELER,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1876
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 1875
            .lvl = 21,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 1877
                MOVE_MAGNITUDE,
                MOVE_ROCK_THROW,
                MOVE_MUD_SPORT,
                MOVE_DEFENSE_CURL,
            },
            },
        },
    },
#line 1882
    [DIFFICULTY_NORMAL][TRAINER_BIKER_JARED] =
    {
#line 1883
        .trainerName = _("JARED"),
#line 1884
        .trainerClass = TRAINER_CLASS_BIKER,
#line 1885
        .trainerPic = TRAINER_PIC_BIKER,
        .encounterMusic_gender =
#line 1887
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 1888
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 1889
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 1891
            .species = SPECIES_KOFFING,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1893
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 1892
            .lvl = 28,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 1894
                MOVE_SMOKESCREEN,
                MOVE_SLUDGE,
                MOVE_SMOG,
                MOVE_POISON_GAS,
            },
            },
            {
#line 1899
            .species = SPECIES_KOFFING,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1901
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 1900
            .lvl = 28,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 1902
                MOVE_SMOKESCREEN,
                MOVE_SLUDGE,
                MOVE_SMOG,
                MOVE_TACKLE,
            },
            },
            {
#line 1907
            .species = SPECIES_KOFFING,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1909
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 1908
            .lvl = 28,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 1910
                MOVE_SMOKESCREEN,
                MOVE_SLUDGE,
                MOVE_SMOG,
                MOVE_TACKLE,
            },
            },
        },
    },
#line 1915
    [DIFFICULTY_NORMAL][TRAINER_BIKER_MALIK] =
    {
#line 1916
        .trainerName = _("MALIK"),
#line 1917
        .trainerClass = TRAINER_CLASS_BIKER,
#line 1918
        .trainerPic = TRAINER_PIC_BIKER,
        .encounterMusic_gender =
#line 1920
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 1921
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 1922
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 1924
            .species = SPECIES_KOFFING,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1926
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 1925
            .lvl = 29,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 1927
                MOVE_SMOKESCREEN,
                MOVE_SLUDGE,
                MOVE_SMOG,
                MOVE_TACKLE,
            },
            },
            {
#line 1932
            .species = SPECIES_GRIMER,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1934
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 1933
            .lvl = 29,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 1935
                MOVE_SCREECH,
                MOVE_MINIMIZE,
                MOVE_SLUDGE,
                MOVE_DISABLE,
            },
            },
        },
    },
#line 1940
    [DIFFICULTY_NORMAL][TRAINER_BIKER_ERNEST] =
    {
#line 1941
        .trainerName = _("ERNEST"),
#line 1942
        .trainerClass = TRAINER_CLASS_BIKER,
#line 1943
        .trainerPic = TRAINER_PIC_BIKER,
        .encounterMusic_gender =
#line 1945
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 1946
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 1947
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 5,
        .party = (const struct TrainerMon[])
        {
            {
#line 1949
            .species = SPECIES_KOFFING,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1951
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 1950
            .lvl = 25,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 1952
                MOVE_SMOKESCREEN,
                MOVE_SLUDGE,
                MOVE_SMOG,
                MOVE_TACKLE,
            },
            },
            {
#line 1957
            .species = SPECIES_KOFFING,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1959
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 1958
            .lvl = 25,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 1960
                MOVE_SMOKESCREEN,
                MOVE_SLUDGE,
                MOVE_SMOG,
                MOVE_TACKLE,
            },
            },
            {
#line 1965
            .species = SPECIES_WEEZING,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1967
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 1966
            .lvl = 25,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 1968
                MOVE_SMOKESCREEN,
                MOVE_SLUDGE,
                MOVE_SMOG,
                MOVE_TACKLE,
            },
            },
            {
#line 1973
            .species = SPECIES_KOFFING,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1975
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 1974
            .lvl = 25,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 1976
                MOVE_SMOKESCREEN,
                MOVE_SLUDGE,
                MOVE_SMOG,
                MOVE_TACKLE,
            },
            },
            {
#line 1981
            .species = SPECIES_GRIMER,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1983
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 1982
            .lvl = 25,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 1984
                MOVE_MINIMIZE,
                MOVE_SLUDGE,
                MOVE_DISABLE,
                MOVE_POUND,
            },
            },
        },
    },
#line 1989
    [DIFFICULTY_NORMAL][TRAINER_BIKER_ALEX] =
    {
#line 1990
        .trainerName = _("ALEX"),
#line 1991
        .trainerClass = TRAINER_CLASS_BIKER,
#line 1992
        .trainerPic = TRAINER_PIC_BIKER,
        .encounterMusic_gender =
#line 1994
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 1995
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 1996
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 1998
            .species = SPECIES_KOFFING,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2000
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 1999
            .lvl = 28,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 2001
                MOVE_SMOKESCREEN,
                MOVE_SLUDGE,
                MOVE_SMOG,
                MOVE_TACKLE,
            },
            },
            {
#line 2006
            .species = SPECIES_GRIMER,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2008
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 2007
            .lvl = 28,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 2009
                MOVE_SCREECH,
                MOVE_MINIMIZE,
                MOVE_SLUDGE,
                MOVE_DISABLE,
            },
            },
            {
#line 2014
            .species = SPECIES_WEEZING,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2016
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 2015
            .lvl = 28,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 2017
                MOVE_SMOKESCREEN,
                MOVE_SLUDGE,
                MOVE_SMOG,
                MOVE_TACKLE,
            },
            },
        },
    },
#line 2022
    [DIFFICULTY_NORMAL][TRAINER_BIKER_LAO] =
    {
#line 2023
        .trainerName = _("LAO"),
#line 2024
        .trainerClass = TRAINER_CLASS_BIKER,
#line 2025
        .trainerPic = TRAINER_PIC_BIKER,
        .encounterMusic_gender =
#line 2027
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 2028
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 2029
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 2031
            .species = SPECIES_GRIMER,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2033
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 2032
            .lvl = 29,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 2034
                MOVE_SCREECH,
                MOVE_MINIMIZE,
                MOVE_SLUDGE,
                MOVE_DISABLE,
            },
            },
            {
#line 2039
            .species = SPECIES_KOFFING,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2041
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 2040
            .lvl = 29,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 2042
                MOVE_SMOKESCREEN,
                MOVE_SLUDGE,
                MOVE_SMOG,
                MOVE_TACKLE,
            },
            },
        },
    },
#line 2047
    [DIFFICULTY_NORMAL][TRAINER_BIKER_HIDEO] =
    {
#line 2048
        .trainerName = _("HIDEO"),
#line 2049
        .trainerClass = TRAINER_CLASS_BIKER,
#line 2050
        .trainerPic = TRAINER_PIC_BIKER,
        .encounterMusic_gender =
#line 2052
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 2053
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 2054
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 2056
            .species = SPECIES_WEEZING,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2058
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 2057
            .lvl = 33,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 2060
    [DIFFICULTY_NORMAL][TRAINER_BIKER_RUBEN] =
    {
#line 2061
        .trainerName = _("RUBEN"),
#line 2062
        .trainerClass = TRAINER_CLASS_BIKER,
#line 2063
        .trainerPic = TRAINER_PIC_BIKER,
        .encounterMusic_gender =
#line 2065
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 2066
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 2067
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 2069
            .species = SPECIES_WEEZING,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2071
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 2070
            .lvl = 28,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 2072
                MOVE_SMOKESCREEN,
                MOVE_SLUDGE,
                MOVE_SMOG,
                MOVE_TACKLE,
            },
            },
            {
#line 2077
            .species = SPECIES_KOFFING,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2079
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 2078
            .lvl = 28,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 2080
                MOVE_SMOKESCREEN,
                MOVE_SLUDGE,
                MOVE_SMOG,
                MOVE_TACKLE,
            },
            },
            {
#line 2085
            .species = SPECIES_WEEZING,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2087
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 2086
            .lvl = 28,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 2088
                MOVE_SMOKESCREEN,
                MOVE_SLUDGE,
                MOVE_SMOG,
                MOVE_TACKLE,
            },
            },
        },
    },
#line 2093
    [DIFFICULTY_NORMAL][TRAINER_BIKER_BILLY] =
    {
#line 2094
        .trainerName = _("BILLY"),
#line 2095
        .trainerClass = TRAINER_CLASS_BIKER,
#line 2096
        .trainerPic = TRAINER_PIC_BIKER,
        .encounterMusic_gender =
#line 2098
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 2099
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 2100
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 2102
            .species = SPECIES_MUK,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2104
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 2103
            .lvl = 33,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 2106
    [DIFFICULTY_NORMAL][TRAINER_BIKER_NIKOLAS] =
    {
#line 2107
        .trainerName = _("NIKOLAS"),
#line 2108
        .trainerClass = TRAINER_CLASS_BIKER,
#line 2109
        .trainerPic = TRAINER_PIC_BIKER,
        .encounterMusic_gender =
#line 2111
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 2112
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 2113
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 2115
            .species = SPECIES_VOLTORB,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2117
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 2116
            .lvl = 29,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 2118
                MOVE_SPARK,
                MOVE_SONIC_BOOM,
                MOVE_SCREECH,
                MOVE_CHARGE,
            },
            },
            {
#line 2123
            .species = SPECIES_VOLTORB,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2125
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 2124
            .lvl = 29,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 2126
                MOVE_SPARK,
                MOVE_SONIC_BOOM,
                MOVE_SCREECH,
                MOVE_CHARGE,
            },
            },
        },
    },
#line 2131
    [DIFFICULTY_NORMAL][TRAINER_BIKER_JAXON] =
    {
#line 2132
        .trainerName = _("JAXON"),
#line 2133
        .trainerClass = TRAINER_CLASS_BIKER,
#line 2134
        .trainerPic = TRAINER_PIC_BIKER,
        .encounterMusic_gender =
#line 2136
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 2137
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 2138
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 2140
            .species = SPECIES_WEEZING,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2142
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 2141
            .lvl = 29,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 2143
                MOVE_SLUDGE,
                MOVE_SMOKESCREEN,
                MOVE_SMOG,
                MOVE_TACKLE,
            },
            },
            {
#line 2148
            .species = SPECIES_MUK,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2150
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 2149
            .lvl = 29,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 2151
                MOVE_SCREECH,
                MOVE_MINIMIZE,
                MOVE_SLUDGE,
                MOVE_DISABLE,
            },
            },
        },
    },
#line 2156
    [DIFFICULTY_NORMAL][TRAINER_BIKER_WILLIAM] =
    {
#line 2157
        .trainerName = _("WILLIAM"),
#line 2158
        .trainerClass = TRAINER_CLASS_BIKER,
#line 2159
        .trainerPic = TRAINER_PIC_BIKER,
        .encounterMusic_gender =
#line 2161
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 2162
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 2163
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 5,
        .party = (const struct TrainerMon[])
        {
            {
#line 2165
            .species = SPECIES_KOFFING,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2167
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 2166
            .lvl = 25,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 2168
                MOVE_SMOKESCREEN,
                MOVE_SLUDGE,
                MOVE_SMOG,
                MOVE_TACKLE,
            },
            },
            {
#line 2173
            .species = SPECIES_WEEZING,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2175
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 2174
            .lvl = 25,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 2176
                MOVE_SMOKESCREEN,
                MOVE_SLUDGE,
                MOVE_SMOG,
                MOVE_TACKLE,
            },
            },
            {
#line 2181
            .species = SPECIES_KOFFING,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2183
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 2182
            .lvl = 25,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 2184
                MOVE_SMOKESCREEN,
                MOVE_SLUDGE,
                MOVE_SMOG,
                MOVE_TACKLE,
            },
            },
            {
#line 2189
            .species = SPECIES_KOFFING,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2191
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 2190
            .lvl = 25,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 2192
                MOVE_SMOKESCREEN,
                MOVE_SLUDGE,
                MOVE_SMOG,
                MOVE_TACKLE,
            },
            },
            {
#line 2197
            .species = SPECIES_WEEZING,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2199
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 2198
            .lvl = 25,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 2200
                MOVE_SMOKESCREEN,
                MOVE_SLUDGE,
                MOVE_SELF_DESTRUCT,
                MOVE_TACKLE,
            },
            },
        },
    },
#line 2205
    [DIFFICULTY_NORMAL][TRAINER_BIKER_LUKAS] =
    {
#line 2206
        .trainerName = _("LUKAS"),
#line 2207
        .trainerClass = TRAINER_CLASS_BIKER,
#line 2208
        .trainerPic = TRAINER_PIC_BIKER,
        .encounterMusic_gender =
#line 2210
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 2211
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 2212
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 4,
        .party = (const struct TrainerMon[])
        {
            {
#line 2214
            .species = SPECIES_KOFFING,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2216
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 2215
            .lvl = 26,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 2217
                MOVE_SMOKESCREEN,
                MOVE_SLUDGE,
                MOVE_SMOG,
                MOVE_TACKLE,
            },
            },
            {
#line 2222
            .species = SPECIES_KOFFING,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2224
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 2223
            .lvl = 26,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 2225
                MOVE_SMOKESCREEN,
                MOVE_SLUDGE,
                MOVE_SMOG,
                MOVE_TACKLE,
            },
            },
            {
#line 2230
            .species = SPECIES_GRIMER,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2232
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 2231
            .lvl = 26,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 2233
                MOVE_SCREECH,
                MOVE_MINIMIZE,
                MOVE_SLUDGE,
                MOVE_DISABLE,
            },
            },
            {
#line 2238
            .species = SPECIES_KOFFING,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2240
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 2239
            .lvl = 26,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 2241
                MOVE_SMOKESCREEN,
                MOVE_SLUDGE,
                MOVE_SMOG,
                MOVE_TACKLE,
            },
            },
        },
    },
#line 2246
    [DIFFICULTY_NORMAL][TRAINER_BIKER_ISAAC] =
    {
#line 2247
        .trainerName = _("ISAAC"),
#line 2248
        .trainerClass = TRAINER_CLASS_BIKER,
#line 2249
        .trainerPic = TRAINER_PIC_BIKER,
        .encounterMusic_gender =
#line 2251
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 2252
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 2253
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 2255
            .species = SPECIES_GRIMER,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2257
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 2256
            .lvl = 28,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 2258
                MOVE_SCREECH,
                MOVE_MINIMIZE,
                MOVE_SLUDGE,
                MOVE_DISABLE,
            },
            },
            {
#line 2263
            .species = SPECIES_GRIMER,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2265
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 2264
            .lvl = 28,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 2266
                MOVE_SCREECH,
                MOVE_MINIMIZE,
                MOVE_SLUDGE,
                MOVE_DISABLE,
            },
            },
            {
#line 2271
            .species = SPECIES_KOFFING,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2273
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 2272
            .lvl = 28,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 2274
                MOVE_SMOKESCREEN,
                MOVE_SLUDGE,
                MOVE_SMOG,
                MOVE_TACKLE,
            },
            },
        },
    },
#line 2279
    [DIFFICULTY_NORMAL][TRAINER_BIKER_GERALD] =
    {
#line 2280
        .trainerName = _("GERALD"),
#line 2281
        .trainerClass = TRAINER_CLASS_BIKER,
#line 2282
        .trainerPic = TRAINER_PIC_BIKER,
        .encounterMusic_gender =
#line 2284
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 2285
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 2286
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 2288
            .species = SPECIES_KOFFING,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2290
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 2289
            .lvl = 29,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 2291
                MOVE_SMOKESCREEN,
                MOVE_SLUDGE,
                MOVE_SMOG,
                MOVE_TACKLE,
            },
            },
            {
#line 2296
            .species = SPECIES_MUK,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2298
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 2297
            .lvl = 29,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 2299
                MOVE_SCREECH,
                MOVE_MINIMIZE,
                MOVE_SLUDGE,
                MOVE_DISABLE,
            },
            },
        },
    },
#line 2304
    [DIFFICULTY_NORMAL][TRAINER_BURGLAR_QUINN] =
    {
#line 2305
        .trainerName = _("QUINN"),
#line 2306
        .trainerClass = TRAINER_CLASS_BURGLAR,
#line 2307
        .trainerPic = TRAINER_PIC_BURGLAR,
        .encounterMusic_gender =
#line 2309
            TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
#line 2310
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 2311
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 2313
            .species = SPECIES_GROWLITHE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2315
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 2314
            .lvl = 36,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 2317
            .species = SPECIES_VULPIX,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2319
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 2318
            .lvl = 36,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 2321
            .species = SPECIES_NINETALES,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2323
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 2322
            .lvl = 36,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 2325
    [DIFFICULTY_NORMAL][TRAINER_BURGLAR_RAMON] =
    {
#line 2326
        .trainerName = _("RAMON"),
#line 2327
        .trainerClass = TRAINER_CLASS_BURGLAR,
#line 2328
        .trainerPic = TRAINER_PIC_BURGLAR,
        .encounterMusic_gender =
#line 2330
            TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
#line 2331
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 2332
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 2334
            .species = SPECIES_PONYTA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2336
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 2335
            .lvl = 41,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 2338
    [DIFFICULTY_NORMAL][TRAINER_BURGLAR_DUSTY] =
    {
#line 2339
        .trainerName = _("DUSTY"),
#line 2340
        .trainerClass = TRAINER_CLASS_BURGLAR,
#line 2341
        .trainerPic = TRAINER_PIC_BURGLAR,
        .encounterMusic_gender =
#line 2343
            TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
#line 2344
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 2345
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 2347
            .species = SPECIES_VULPIX,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2349
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 2348
            .lvl = 37,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 2351
            .species = SPECIES_GROWLITHE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2353
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 2352
            .lvl = 37,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 2355
    [DIFFICULTY_NORMAL][TRAINER_BURGLAR_ARNIE] =
    {
#line 2356
        .trainerName = _("ARNIE"),
#line 2357
        .trainerClass = TRAINER_CLASS_BURGLAR,
#line 2358
        .trainerPic = TRAINER_PIC_BURGLAR,
        .encounterMusic_gender =
#line 2360
            TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
#line 2361
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 2362
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 2364
            .species = SPECIES_CHARMANDER,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2366
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 2365
            .lvl = 34,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 2368
            .species = SPECIES_CHARMELEON,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2370
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 2369
            .lvl = 34,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 2372
    [DIFFICULTY_NORMAL][TRAINER_BURGLAR_SIMON] =
    {
#line 2373
        .trainerName = _("SIMON"),
#line 2374
        .trainerClass = TRAINER_CLASS_BURGLAR,
#line 2375
        .trainerPic = TRAINER_PIC_BURGLAR,
        .encounterMusic_gender =
#line 2377
            TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
#line 2378
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 2379
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 2381
            .species = SPECIES_NINETALES,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2383
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 2382
            .lvl = 38,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 2385
    [DIFFICULTY_NORMAL][TRAINER_BURGLAR_LEWIS] =
    {
#line 2386
        .trainerName = _("LEWIS"),
#line 2387
        .trainerClass = TRAINER_CLASS_BURGLAR,
#line 2388
        .trainerPic = TRAINER_PIC_BURGLAR,
        .encounterMusic_gender =
#line 2390
            TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
#line 2391
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 2392
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 2394
            .species = SPECIES_GROWLITHE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2396
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 2395
            .lvl = 34,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 2398
            .species = SPECIES_PONYTA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2400
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 2399
            .lvl = 34,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 2402
    [DIFFICULTY_NORMAL][TRAINER_ENGINEER_BAILY] =
    {
#line 2403
        .trainerName = _("BAILY"),
#line 2404
        .trainerClass = TRAINER_CLASS_ENGINEER,
#line 2405
        .trainerPic = TRAINER_PIC_ENGINEER,
        .encounterMusic_gender =
#line 2407
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 2408
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 2409
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 2411
            .species = SPECIES_VOLTORB,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2413
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 2412
            .lvl = 21,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 2415
            .species = SPECIES_MAGNEMITE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2417
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 2416
            .lvl = 21,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 2419
    [DIFFICULTY_NORMAL][TRAINER_ENGINEER_BRAXTON] =
    {
#line 2420
        .trainerName = _("BRAXTON"),
#line 2421
        .trainerClass = TRAINER_CLASS_ENGINEER,
#line 2422
        .trainerPic = TRAINER_PIC_ENGINEER,
        .encounterMusic_gender =
#line 2424
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 2425
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 2426
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 2428
            .species = SPECIES_MAGNEMITE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2430
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 2429
            .lvl = 21,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 2432
    [DIFFICULTY_NORMAL][TRAINER_ENGINEER_BERNIE] =
    {
#line 2433
        .trainerName = _("BERNIE"),
#line 2434
        .trainerClass = TRAINER_CLASS_ENGINEER,
#line 2435
        .trainerPic = TRAINER_PIC_ENGINEER,
        .encounterMusic_gender =
#line 2437
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 2438
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 2439
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 2441
            .species = SPECIES_MAGNEMITE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2443
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 2442
            .lvl = 18,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 2445
            .species = SPECIES_MAGNEMITE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2447
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 2446
            .lvl = 18,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 2449
            .species = SPECIES_MAGNETON,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2451
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 2450
            .lvl = 18,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 2453
    [DIFFICULTY_NORMAL][TRAINER_FISHERMAN_DALE] =
    {
#line 2454
        .trainerName = _("DALE"),
#line 2455
        .trainerClass = TRAINER_CLASS_FISHERMAN,
#line 2456
        .trainerPic = TRAINER_PIC_FISHERMAN,
        .encounterMusic_gender =
#line 2458
            TRAINER_ENCOUNTER_MUSIC_HIKER,
#line 2459
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 2460
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 2462
            .species = SPECIES_GOLDEEN,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2464
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 2463
            .lvl = 17,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 2466
            .species = SPECIES_TENTACOOL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2468
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 2467
            .lvl = 17,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 2470
            .species = SPECIES_GOLDEEN,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2472
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 2471
            .lvl = 17,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 2474
    [DIFFICULTY_NORMAL][TRAINER_FISHERMAN_BARNY] =
    {
#line 2475
        .trainerName = _("BARNY"),
#line 2476
        .trainerClass = TRAINER_CLASS_FISHERMAN,
#line 2477
        .trainerPic = TRAINER_PIC_FISHERMAN,
        .encounterMusic_gender =
#line 2479
            TRAINER_ENCOUNTER_MUSIC_HIKER,
#line 2480
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 2481
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 2483
            .species = SPECIES_TENTACOOL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2485
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 2484
            .lvl = 17,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 2487
            .species = SPECIES_STARYU,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2489
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 2488
            .lvl = 17,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 2491
            .species = SPECIES_SHELLDER,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2493
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 2492
            .lvl = 17,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 2495
    [DIFFICULTY_NORMAL][TRAINER_FISHERMAN_NED] =
    {
#line 2496
        .trainerName = _("NED"),
#line 2497
        .trainerClass = TRAINER_CLASS_FISHERMAN,
#line 2498
        .trainerPic = TRAINER_PIC_FISHERMAN,
        .encounterMusic_gender =
#line 2500
            TRAINER_ENCOUNTER_MUSIC_HIKER,
#line 2501
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 2502
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 2504
            .species = SPECIES_GOLDEEN,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2506
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 2505
            .lvl = 22,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 2508
            .species = SPECIES_POLIWAG,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2510
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 2509
            .lvl = 22,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 2512
            .species = SPECIES_GOLDEEN,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2514
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 2513
            .lvl = 22,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 2516
    [DIFFICULTY_NORMAL][TRAINER_FISHERMAN_CHIP] =
    {
#line 2517
        .trainerName = _("CHIP"),
#line 2518
        .trainerClass = TRAINER_CLASS_FISHERMAN,
#line 2519
        .trainerPic = TRAINER_PIC_FISHERMAN,
        .encounterMusic_gender =
#line 2521
            TRAINER_ENCOUNTER_MUSIC_HIKER,
#line 2522
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 2523
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 2525
            .species = SPECIES_TENTACOOL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2527
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 2526
            .lvl = 24,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 2529
            .species = SPECIES_GOLDEEN,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2531
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 2530
            .lvl = 24,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 2533
    [DIFFICULTY_NORMAL][TRAINER_FISHERMAN_HANK] =
    {
#line 2534
        .trainerName = _("HANK"),
#line 2535
        .trainerClass = TRAINER_CLASS_FISHERMAN,
#line 2536
        .trainerPic = TRAINER_PIC_FISHERMAN,
        .encounterMusic_gender =
#line 2538
            TRAINER_ENCOUNTER_MUSIC_HIKER,
#line 2539
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 2540
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 2542
            .species = SPECIES_GOLDEEN,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2544
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 2543
            .lvl = 27,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 2546
    [DIFFICULTY_NORMAL][TRAINER_FISHERMAN_ELLIOT] =
    {
#line 2547
        .trainerName = _("ELLIOT"),
#line 2548
        .trainerClass = TRAINER_CLASS_FISHERMAN,
#line 2549
        .trainerPic = TRAINER_PIC_FISHERMAN,
        .encounterMusic_gender =
#line 2551
            TRAINER_ENCOUNTER_MUSIC_HIKER,
#line 2552
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 2553
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 4,
        .party = (const struct TrainerMon[])
        {
            {
#line 2555
            .species = SPECIES_POLIWAG,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2557
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 2556
            .lvl = 21,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 2559
            .species = SPECIES_SHELLDER,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2561
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 2560
            .lvl = 21,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 2563
            .species = SPECIES_GOLDEEN,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2565
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 2564
            .lvl = 21,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 2567
            .species = SPECIES_HORSEA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2569
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 2568
            .lvl = 21,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 2571
    [DIFFICULTY_NORMAL][TRAINER_FISHERMAN_RONALD] =
    {
#line 2572
        .trainerName = _("RONALD"),
#line 2573
        .trainerClass = TRAINER_CLASS_FISHERMAN,
#line 2574
        .trainerPic = TRAINER_PIC_FISHERMAN,
        .encounterMusic_gender =
#line 2576
            TRAINER_ENCOUNTER_MUSIC_HIKER,
#line 2577
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 2578
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 4,
        .party = (const struct TrainerMon[])
        {
            {
#line 2580
            .species = SPECIES_SEAKING,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2582
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 2581
            .lvl = 28,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 2584
            .species = SPECIES_GOLDEEN,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2586
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 2585
            .lvl = 28,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 2588
            .species = SPECIES_SEAKING,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2590
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 2589
            .lvl = 28,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 2592
            .species = SPECIES_SEAKING,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2594
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 2593
            .lvl = 28,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 2596
    [DIFFICULTY_NORMAL][TRAINER_FISHERMAN_CLAUDE] =
    {
#line 2597
        .trainerName = _("CLAUDE"),
#line 2598
        .trainerClass = TRAINER_CLASS_FISHERMAN,
#line 2599
        .trainerPic = TRAINER_PIC_FISHERMAN,
        .encounterMusic_gender =
#line 2601
            TRAINER_ENCOUNTER_MUSIC_HIKER,
#line 2602
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 2603
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 2605
            .species = SPECIES_SHELLDER,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2607
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 2606
            .lvl = 31,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 2609
            .species = SPECIES_CLOYSTER,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2611
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 2610
            .lvl = 31,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 2613
    [DIFFICULTY_NORMAL][TRAINER_FISHERMAN_WADE] =
    {
#line 2614
        .trainerName = _("WADE"),
#line 2615
        .trainerClass = TRAINER_CLASS_FISHERMAN,
#line 2616
        .trainerPic = TRAINER_PIC_FISHERMAN,
        .encounterMusic_gender =
#line 2618
            TRAINER_ENCOUNTER_MUSIC_HIKER,
#line 2619
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 2620
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 6,
        .party = (const struct TrainerMon[])
        {
            {
#line 2622
            .species = SPECIES_MAGIKARP,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2624
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 2623
            .lvl = 27,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 2626
            .species = SPECIES_MAGIKARP,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2628
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 2627
            .lvl = 27,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 2630
            .species = SPECIES_MAGIKARP,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2632
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 2631
            .lvl = 27,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 2634
            .species = SPECIES_MAGIKARP,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2636
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 2635
            .lvl = 27,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 2638
            .species = SPECIES_MAGIKARP,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2640
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 2639
            .lvl = 27,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 2642
            .species = SPECIES_MAGIKARP,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2644
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 2643
            .lvl = 27,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 2646
    [DIFFICULTY_NORMAL][TRAINER_FISHERMAN_NOLAN] =
    {
#line 2647
        .trainerName = _("NOLAN"),
#line 2648
        .trainerClass = TRAINER_CLASS_FISHERMAN,
#line 2649
        .trainerPic = TRAINER_PIC_FISHERMAN,
        .encounterMusic_gender =
#line 2651
            TRAINER_ENCOUNTER_MUSIC_HIKER,
#line 2652
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 2653
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 2655
            .species = SPECIES_SEAKING,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2657
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 2656
            .lvl = 33,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 2659
            .species = SPECIES_GOLDEEN,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2661
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 2660
            .lvl = 33,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 2663
    [DIFFICULTY_NORMAL][TRAINER_FISHERMAN_ANDREW] =
    {
#line 2664
        .trainerName = _("ANDREW"),
#line 2665
        .trainerClass = TRAINER_CLASS_FISHERMAN,
#line 2666
        .trainerPic = TRAINER_PIC_FISHERMAN,
        .encounterMusic_gender =
#line 2668
            TRAINER_ENCOUNTER_MUSIC_HIKER,
#line 2669
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 2670
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 2672
            .species = SPECIES_MAGIKARP,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2674
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 2673
            .lvl = 24,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 2676
            .species = SPECIES_MAGIKARP,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2678
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 2677
            .lvl = 24,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 2680
    [DIFFICULTY_NORMAL][TRAINER_SWIMMER_MALE_LUIS] =
    {
#line 2681
        .trainerName = _("LUIS"),
#line 2682
        .trainerClass = TRAINER_CLASS_SWIMMER_M,
#line 2683
        .trainerPic = TRAINER_PIC_SWIMMER_M,
        .encounterMusic_gender =
#line 2685
            TRAINER_ENCOUNTER_MUSIC_SWIMMER,
#line 2686
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 2687
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 2689
            .species = SPECIES_HORSEA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2691
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 2690
            .lvl = 16,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 2693
            .species = SPECIES_SHELLDER,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2695
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 2694
            .lvl = 16,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 2697
    [DIFFICULTY_NORMAL][TRAINER_SWIMMER_MALE_RICHARD] =
    {
#line 2698
        .trainerName = _("RICHARD"),
#line 2699
        .trainerClass = TRAINER_CLASS_SWIMMER_M,
#line 2700
        .trainerPic = TRAINER_PIC_SWIMMER_M,
        .encounterMusic_gender =
#line 2702
            TRAINER_ENCOUNTER_MUSIC_SWIMMER,
#line 2703
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 2704
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 2706
            .species = SPECIES_TENTACOOL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2708
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 2707
            .lvl = 30,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 2710
            .species = SPECIES_SHELLDER,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2712
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 2711
            .lvl = 30,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 2714
    [DIFFICULTY_NORMAL][TRAINER_SWIMMER_MALE_REECE] =
    {
#line 2715
        .trainerName = _("REECE"),
#line 2716
        .trainerClass = TRAINER_CLASS_SWIMMER_M,
#line 2717
        .trainerPic = TRAINER_PIC_SWIMMER_M,
        .encounterMusic_gender =
#line 2719
            TRAINER_ENCOUNTER_MUSIC_SWIMMER,
#line 2720
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 2721
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 2723
            .species = SPECIES_GOLDEEN,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2725
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 2724
            .lvl = 29,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 2727
            .species = SPECIES_HORSEA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2729
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 2728
            .lvl = 29,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 2731
            .species = SPECIES_STARYU,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2733
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 2732
            .lvl = 29,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 2735
    [DIFFICULTY_NORMAL][TRAINER_SWIMMER_MALE_MATTHEW] =
    {
#line 2736
        .trainerName = _("MATTHEW"),
#line 2737
        .trainerClass = TRAINER_CLASS_SWIMMER_M,
#line 2738
        .trainerPic = TRAINER_PIC_SWIMMER_M,
        .encounterMusic_gender =
#line 2740
            TRAINER_ENCOUNTER_MUSIC_SWIMMER,
#line 2741
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 2742
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 2744
            .species = SPECIES_POLIWAG,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2746
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 2745
            .lvl = 30,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 2748
            .species = SPECIES_POLIWHIRL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2750
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 2749
            .lvl = 30,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 2752
    [DIFFICULTY_NORMAL][TRAINER_SWIMMER_MALE_DOUGLAS] =
    {
#line 2753
        .trainerName = _("DOUGLAS"),
#line 2754
        .trainerClass = TRAINER_CLASS_SWIMMER_M,
#line 2755
        .trainerPic = TRAINER_PIC_SWIMMER_M,
        .encounterMusic_gender =
#line 2757
            TRAINER_ENCOUNTER_MUSIC_SWIMMER,
#line 2758
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 2759
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 4,
        .party = (const struct TrainerMon[])
        {
            {
#line 2761
            .species = SPECIES_HORSEA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2763
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 2762
            .lvl = 27,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 2765
            .species = SPECIES_TENTACOOL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2767
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 2766
            .lvl = 27,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 2769
            .species = SPECIES_TENTACOOL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2771
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 2770
            .lvl = 27,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 2773
            .species = SPECIES_GOLDEEN,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2775
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 2774
            .lvl = 27,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 2777
    [DIFFICULTY_NORMAL][TRAINER_SWIMMER_MALE_DAVID] =
    {
#line 2778
        .trainerName = _("DAVID"),
#line 2779
        .trainerClass = TRAINER_CLASS_SWIMMER_M,
#line 2780
        .trainerPic = TRAINER_PIC_SWIMMER_M,
        .encounterMusic_gender =
#line 2782
            TRAINER_ENCOUNTER_MUSIC_SWIMMER,
#line 2783
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 2784
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 2786
            .species = SPECIES_GOLDEEN,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2788
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 2787
            .lvl = 29,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 2790
            .species = SPECIES_SHELLDER,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2792
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 2791
            .lvl = 29,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 2794
            .species = SPECIES_SEAKING,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2796
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 2795
            .lvl = 29,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 2798
    [DIFFICULTY_NORMAL][TRAINER_SWIMMER_MALE_TONY] =
    {
#line 2799
        .trainerName = _("TONY"),
#line 2800
        .trainerClass = TRAINER_CLASS_SWIMMER_M,
#line 2801
        .trainerPic = TRAINER_PIC_SWIMMER_M,
        .encounterMusic_gender =
#line 2803
            TRAINER_ENCOUNTER_MUSIC_SWIMMER,
#line 2804
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 2805
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 2807
            .species = SPECIES_HORSEA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2809
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 2808
            .lvl = 30,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 2811
            .species = SPECIES_HORSEA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2813
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 2812
            .lvl = 30,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 2815
    [DIFFICULTY_NORMAL][TRAINER_SWIMMER_MALE_AXLE] =
    {
#line 2816
        .trainerName = _("AXLE"),
#line 2817
        .trainerClass = TRAINER_CLASS_SWIMMER_M,
#line 2818
        .trainerPic = TRAINER_PIC_SWIMMER_M,
        .encounterMusic_gender =
#line 2820
            TRAINER_ENCOUNTER_MUSIC_SWIMMER,
#line 2821
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 2822
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 5,
        .party = (const struct TrainerMon[])
        {
            {
#line 2824
            .species = SPECIES_TENTACOOL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2826
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 2825
            .lvl = 27,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 2828
            .species = SPECIES_TENTACOOL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2830
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 2829
            .lvl = 27,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 2832
            .species = SPECIES_STARYU,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2834
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 2833
            .lvl = 27,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 2836
            .species = SPECIES_HORSEA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2838
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 2837
            .lvl = 27,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 2840
            .species = SPECIES_TENTACRUEL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2842
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 2841
            .lvl = 27,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 2844
    [DIFFICULTY_NORMAL][TRAINER_SWIMMER_MALE_BARRY] =
    {
#line 2845
        .trainerName = _("BARRY"),
#line 2846
        .trainerClass = TRAINER_CLASS_SWIMMER_M,
#line 2847
        .trainerPic = TRAINER_PIC_SWIMMER_M,
        .encounterMusic_gender =
#line 2849
            TRAINER_ENCOUNTER_MUSIC_SWIMMER,
#line 2850
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 2851
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 2853
            .species = SPECIES_SHELLDER,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2855
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 2854
            .lvl = 31,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 2857
            .species = SPECIES_CLOYSTER,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2859
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 2858
            .lvl = 31,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 2861
    [DIFFICULTY_NORMAL][TRAINER_SWIMMER_MALE_DEAN] =
    {
#line 2862
        .trainerName = _("DEAN"),
#line 2863
        .trainerClass = TRAINER_CLASS_SWIMMER_M,
#line 2864
        .trainerPic = TRAINER_PIC_SWIMMER_M,
        .encounterMusic_gender =
#line 2866
            TRAINER_ENCOUNTER_MUSIC_SWIMMER,
#line 2867
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 2868
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 2870
            .species = SPECIES_STARYU,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2872
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 2871
            .lvl = 35,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 2874
    [DIFFICULTY_NORMAL][TRAINER_SWIMMER_MALE_DARRIN] =
    {
#line 2875
        .trainerName = _("DARRIN"),
#line 2876
        .trainerClass = TRAINER_CLASS_SWIMMER_M,
#line 2877
        .trainerPic = TRAINER_PIC_SWIMMER_M,
        .encounterMusic_gender =
#line 2879
            TRAINER_ENCOUNTER_MUSIC_SWIMMER,
#line 2880
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 2881
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 4,
        .party = (const struct TrainerMon[])
        {
            {
#line 2883
            .species = SPECIES_HORSEA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2885
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 2884
            .lvl = 28,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 2887
            .species = SPECIES_HORSEA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2889
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 2888
            .lvl = 28,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 2891
            .species = SPECIES_SEADRA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2893
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 2892
            .lvl = 28,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 2895
            .species = SPECIES_HORSEA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2897
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 2896
            .lvl = 28,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 2899
    [DIFFICULTY_NORMAL][TRAINER_SWIMMER_MALE_SPENCER] =
    {
#line 2900
        .trainerName = _("SPENCER"),
#line 2901
        .trainerClass = TRAINER_CLASS_SWIMMER_M,
#line 2902
        .trainerPic = TRAINER_PIC_SWIMMER_M,
        .encounterMusic_gender =
#line 2904
            TRAINER_ENCOUNTER_MUSIC_SWIMMER,
#line 2905
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 2906
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 2908
            .species = SPECIES_SEADRA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2910
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 2909
            .lvl = 33,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 2912
            .species = SPECIES_TENTACRUEL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2914
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 2913
            .lvl = 33,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 2916
    [DIFFICULTY_NORMAL][TRAINER_SWIMMER_MALE_JACK] =
    {
#line 2917
        .trainerName = _("JACK"),
#line 2918
        .trainerClass = TRAINER_CLASS_SWIMMER_M,
#line 2919
        .trainerPic = TRAINER_PIC_SWIMMER_M,
        .encounterMusic_gender =
#line 2921
            TRAINER_ENCOUNTER_MUSIC_SWIMMER,
#line 2922
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 2923
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 2925
            .species = SPECIES_STARMIE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2927
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 2926
            .lvl = 37,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 2929
    [DIFFICULTY_NORMAL][TRAINER_SWIMMER_MALE_JEROME] =
    {
#line 2930
        .trainerName = _("JEROME"),
#line 2931
        .trainerClass = TRAINER_CLASS_SWIMMER_M,
#line 2932
        .trainerPic = TRAINER_PIC_SWIMMER_M,
        .encounterMusic_gender =
#line 2934
            TRAINER_ENCOUNTER_MUSIC_SWIMMER,
#line 2935
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 2936
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 2938
            .species = SPECIES_STARYU,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2940
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 2939
            .lvl = 33,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 2942
            .species = SPECIES_WARTORTLE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2944
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 2943
            .lvl = 33,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 2946
    [DIFFICULTY_NORMAL][TRAINER_SWIMMER_MALE_ROLAND] =
    {
#line 2947
        .trainerName = _("ROLAND"),
#line 2948
        .trainerClass = TRAINER_CLASS_SWIMMER_M,
#line 2949
        .trainerPic = TRAINER_PIC_SWIMMER_M,
        .encounterMusic_gender =
#line 2951
            TRAINER_ENCOUNTER_MUSIC_SWIMMER,
#line 2952
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 2953
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 2955
            .species = SPECIES_POLIWHIRL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2957
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 2956
            .lvl = 32,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 2959
            .species = SPECIES_TENTACOOL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2961
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 2960
            .lvl = 32,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 2963
            .species = SPECIES_SEADRA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2965
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 2964
            .lvl = 32,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 2967
    [DIFFICULTY_NORMAL][TRAINER_CUE_BALL_KOJI] =
    {
#line 2968
        .trainerName = _("KOJI"),
#line 2969
        .trainerClass = TRAINER_CLASS_CUE_BALL,
#line 2970
        .trainerPic = TRAINER_PIC_CUE_BALL,
        .encounterMusic_gender =
#line 2972
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 2973
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 2974
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 2976
            .species = SPECIES_MACHOP,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2978
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 2977
            .lvl = 28,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 2980
            .species = SPECIES_MANKEY,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2982
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 2981
            .lvl = 28,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 2984
            .species = SPECIES_MACHOP,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2986
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 2985
            .lvl = 28,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 2988
    [DIFFICULTY_NORMAL][TRAINER_CUE_BALL_LUKE] =
    {
#line 2989
        .trainerName = _("LUKE"),
#line 2990
        .trainerClass = TRAINER_CLASS_CUE_BALL,
#line 2991
        .trainerPic = TRAINER_PIC_CUE_BALL,
        .encounterMusic_gender =
#line 2993
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 2994
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 2995
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 2997
            .species = SPECIES_MANKEY,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2999
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 2998
            .lvl = 29,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 3001
            .species = SPECIES_MACHOP,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3003
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 3002
            .lvl = 29,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 3005
    [DIFFICULTY_NORMAL][TRAINER_CUE_BALL_CAMRON] =
    {
#line 3006
        .trainerName = _("CAMRON"),
#line 3007
        .trainerClass = TRAINER_CLASS_CUE_BALL,
#line 3008
        .trainerPic = TRAINER_PIC_CUE_BALL,
        .encounterMusic_gender =
#line 3010
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 3011
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 3012
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 3014
            .species = SPECIES_MANKEY,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3016
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 3015
            .lvl = 29,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 3018
            .species = SPECIES_MACHOP,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3020
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 3019
            .lvl = 29,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 3022
    [DIFFICULTY_NORMAL][TRAINER_CUE_BALL_RAUL] =
    {
#line 3023
        .trainerName = _("RAUL"),
#line 3024
        .trainerClass = TRAINER_CLASS_CUE_BALL,
#line 3025
        .trainerPic = TRAINER_PIC_CUE_BALL,
        .encounterMusic_gender =
#line 3027
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 3028
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 3029
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 3031
            .species = SPECIES_MANKEY,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3033
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 3032
            .lvl = 29,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 3035
            .species = SPECIES_PRIMEAPE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3037
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 3036
            .lvl = 29,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 3039
    [DIFFICULTY_NORMAL][TRAINER_CUE_BALL_ISAIAH] =
    {
#line 3040
        .trainerName = _("ISAIAH"),
#line 3041
        .trainerClass = TRAINER_CLASS_CUE_BALL,
#line 3042
        .trainerPic = TRAINER_PIC_CUE_BALL,
        .encounterMusic_gender =
#line 3044
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 3045
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 3046
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 3048
            .species = SPECIES_MACHOP,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3050
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 3049
            .lvl = 29,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 3052
            .species = SPECIES_MACHAMP,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3054
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 3053
            .lvl = 29,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 3056
    [DIFFICULTY_NORMAL][TRAINER_CUE_BALL_ZEEK] =
    {
#line 3057
        .trainerName = _("ZEEK"),
#line 3058
        .trainerClass = TRAINER_CLASS_CUE_BALL,
#line 3059
        .trainerPic = TRAINER_PIC_CUE_BALL,
        .encounterMusic_gender =
#line 3061
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 3062
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 3063
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 3065
            .species = SPECIES_MACHOKE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3067
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 3066
            .lvl = 33,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 3069
    [DIFFICULTY_NORMAL][TRAINER_CUE_BALL_JAMAL] =
    {
#line 3070
        .trainerName = _("JAMAL"),
#line 3071
        .trainerClass = TRAINER_CLASS_CUE_BALL,
#line 3072
        .trainerPic = TRAINER_PIC_CUE_BALL,
        .encounterMusic_gender =
#line 3074
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 3075
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 3076
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 4,
        .party = (const struct TrainerMon[])
        {
            {
#line 3078
            .species = SPECIES_MANKEY,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3080
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 3079
            .lvl = 26,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 3082
            .species = SPECIES_MANKEY,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3084
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 3083
            .lvl = 26,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 3086
            .species = SPECIES_MACHAMP,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3088
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 3087
            .lvl = 26,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 3090
            .species = SPECIES_MACHOP,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3092
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 3091
            .lvl = 26,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 3094
    [DIFFICULTY_NORMAL][TRAINER_CUE_BALL_COREY] =
    {
#line 3095
        .trainerName = _("COREY"),
#line 3096
        .trainerClass = TRAINER_CLASS_CUE_BALL,
#line 3097
        .trainerPic = TRAINER_PIC_CUE_BALL,
        .encounterMusic_gender =
#line 3099
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 3100
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 3101
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 3103
            .species = SPECIES_PRIMEAPE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3105
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 3104
            .lvl = 29,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 3107
            .species = SPECIES_MACHOKE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3109
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 3108
            .lvl = 29,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 3111
    [DIFFICULTY_NORMAL][TRAINER_CUE_BALL_CHASE] =
    {
#line 3112
        .trainerName = _("CHASE"),
#line 3113
        .trainerClass = TRAINER_CLASS_CUE_BALL,
#line 3114
        .trainerPic = TRAINER_PIC_CUE_BALL,
        .encounterMusic_gender =
#line 3116
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 3117
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 3118
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 3120
            .species = SPECIES_TENTACOOL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3122
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 3121
            .lvl = 31,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 3124
            .species = SPECIES_TENTACOOL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3126
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 3125
            .lvl = 31,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 3128
            .species = SPECIES_TENTACRUEL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3130
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 3129
            .lvl = 31,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 3132
    [DIFFICULTY_NORMAL][TRAINER_GAMER_HUGO] =
    {
#line 3133
        .trainerName = _("HUGO"),
#line 3134
        .trainerClass = TRAINER_CLASS_GAMER,
#line 3135
        .trainerPic = TRAINER_PIC_GAMER,
        .encounterMusic_gender =
#line 3137
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 3138
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 3139
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 3141
            .species = SPECIES_POLIWAG,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3143
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 3142
            .lvl = 18,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 3145
            .species = SPECIES_HORSEA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3147
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 3146
            .lvl = 18,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 3149
    [DIFFICULTY_NORMAL][TRAINER_GAMER_JASPER] =
    {
#line 3150
        .trainerName = _("JASPER"),
#line 3151
        .trainerClass = TRAINER_CLASS_GAMER,
#line 3152
        .trainerPic = TRAINER_PIC_GAMER,
        .encounterMusic_gender =
#line 3154
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 3155
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 3156
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 3158
            .species = SPECIES_BELLSPROUT,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3160
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 3159
            .lvl = 18,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 3162
            .species = SPECIES_ODDISH,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3164
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 3163
            .lvl = 18,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 3166
    [DIFFICULTY_NORMAL][TRAINER_GAMER_DIRK] =
    {
#line 3167
        .trainerName = _("DIRK"),
#line 3168
        .trainerClass = TRAINER_CLASS_GAMER,
#line 3169
        .trainerPic = TRAINER_PIC_GAMER,
        .encounterMusic_gender =
#line 3171
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 3172
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 3173
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 3175
            .species = SPECIES_VOLTORB,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3177
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 3176
            .lvl = 18,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 3179
            .species = SPECIES_MAGNEMITE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3181
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 3180
            .lvl = 18,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 3183
    [DIFFICULTY_NORMAL][TRAINER_GAMER_DARIAN] =
    {
#line 3184
        .trainerName = _("DARIAN"),
#line 3185
        .trainerClass = TRAINER_CLASS_GAMER,
#line 3186
        .trainerPic = TRAINER_PIC_GAMER,
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
            .species = SPECIES_GROWLITHE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3194
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 3193
            .lvl = 18,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 3196
            .species = SPECIES_VULPIX,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3198
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 3197
            .lvl = 18,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 3200
    [DIFFICULTY_NORMAL][TRAINER_GAMER_STAN] =
    {
#line 3201
        .trainerName = _("STAN"),
#line 3202
        .trainerClass = TRAINER_CLASS_GAMER,
#line 3203
        .trainerPic = TRAINER_PIC_GAMER,
        .encounterMusic_gender =
#line 3205
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 3206
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 3207
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 3209
            .species = SPECIES_POLIWAG,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3211
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 3210
            .lvl = 22,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 3213
            .species = SPECIES_POLIWAG,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3215
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 3214
            .lvl = 22,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 3217
            .species = SPECIES_POLIWHIRL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3219
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 3218
            .lvl = 22,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 3221
    [DIFFICULTY_NORMAL][TRAINER_GAMER_RICH] =
    {
#line 3222
        .trainerName = _("RICH"),
#line 3223
        .trainerClass = TRAINER_CLASS_GAMER,
#line 3224
        .trainerPic = TRAINER_PIC_GAMER,
        .encounterMusic_gender =
#line 3226
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 3227
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 3228
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 3230
            .species = SPECIES_GROWLITHE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3232
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 3231
            .lvl = 24,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 3234
            .species = SPECIES_VULPIX,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3236
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 3235
            .lvl = 24,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 3238
    [DIFFICULTY_NORMAL][TRAINER_BEAUTY_BRIDGET] =
    {
#line 3239
        .trainerName = _("BRIDGET"),
#line 3240
        .trainerClass = TRAINER_CLASS_BEAUTY,
#line 3241
        .trainerPic = TRAINER_PIC_BEAUTY,
        .encounterMusic_gender =
#line 3243
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
#line 3244
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 3245
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 4,
        .party = (const struct TrainerMon[])
        {
            {
#line 3247
            .species = SPECIES_ODDISH,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3249
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 3248
            .lvl = 21,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 3251
            .species = SPECIES_BELLSPROUT,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3253
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 3252
            .lvl = 21,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 3255
            .species = SPECIES_ODDISH,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3257
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 3256
            .lvl = 21,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 3259
            .species = SPECIES_BELLSPROUT,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3261
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 3260
            .lvl = 21,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 3263
    [DIFFICULTY_NORMAL][TRAINER_BEAUTY_TAMIA] =
    {
#line 3264
        .trainerName = _("TAMIA"),
#line 3265
        .trainerClass = TRAINER_CLASS_BEAUTY,
#line 3266
        .trainerPic = TRAINER_PIC_BEAUTY,
        .encounterMusic_gender =
#line 3268
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
#line 3269
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 3270
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 3272
            .species = SPECIES_BELLSPROUT,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3274
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 3273
            .lvl = 24,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 3276
            .species = SPECIES_BELLSPROUT,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3278
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 3277
            .lvl = 24,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 3280
    [DIFFICULTY_NORMAL][TRAINER_BEAUTY_LORI] =
    {
#line 3281
        .trainerName = _("LORI"),
#line 3282
        .trainerClass = TRAINER_CLASS_BEAUTY,
#line 3283
        .trainerPic = TRAINER_PIC_BEAUTY,
        .encounterMusic_gender =
#line 3285
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
#line 3286
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 3287
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 3289
            .species = SPECIES_EXEGGCUTE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3291
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 3290
            .lvl = 24,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 3293
    [DIFFICULTY_NORMAL][TRAINER_BEAUTY_LOLA] =
    {
#line 3294
        .trainerName = _("LOLA"),
#line 3295
        .trainerClass = TRAINER_CLASS_BEAUTY,
#line 3296
        .trainerPic = TRAINER_PIC_BEAUTY,
        .encounterMusic_gender =
#line 3298
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
#line 3299
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 3300
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 3302
            .species = SPECIES_RATTATA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3304
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 3303
            .lvl = 27,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 3306
            .species = SPECIES_PIKACHU,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3308
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 3307
            .lvl = 27,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 3310
            .species = SPECIES_RATTATA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3312
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 3311
            .lvl = 27,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 3314
    [DIFFICULTY_NORMAL][TRAINER_BEAUTY_SHEILA] =
    {
#line 3315
        .trainerName = _("SHEILA"),
#line 3316
        .trainerClass = TRAINER_CLASS_BEAUTY,
#line 3317
        .trainerPic = TRAINER_PIC_BEAUTY,
        .encounterMusic_gender =
#line 3319
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
#line 3320
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 3321
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 3323
            .species = SPECIES_CLEFAIRY,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3325
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 3324
            .lvl = 29,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 3327
            .species = SPECIES_MEOWTH,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3329
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 3328
            .lvl = 29,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 3331
    [DIFFICULTY_NORMAL][TRAINER_SWIMMER_FEMALE_TIFFANY] =
    {
#line 3332
        .trainerName = _("TIFFANY"),
#line 3333
        .trainerClass = TRAINER_CLASS_SWIMMER_F,
#line 3334
        .trainerPic = TRAINER_PIC_SWIMMER_F,
        .encounterMusic_gender =
#line 3336
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
#line 3337
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 3338
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 3340
            .species = SPECIES_SEAKING,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3342
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 3341
            .lvl = 35,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 3344
    [DIFFICULTY_NORMAL][TRAINER_SWIMMER_FEMALE_NORA] =
    {
#line 3345
        .trainerName = _("NORA"),
#line 3346
        .trainerClass = TRAINER_CLASS_SWIMMER_F,
#line 3347
        .trainerPic = TRAINER_PIC_SWIMMER_F,
        .encounterMusic_gender =
#line 3349
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
#line 3350
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 3351
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 3353
            .species = SPECIES_SHELLDER,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3355
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 3354
            .lvl = 30,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 3357
            .species = SPECIES_SHELLDER,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3359
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 3358
            .lvl = 30,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 3361
            .species = SPECIES_CLOYSTER,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3363
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 3362
            .lvl = 30,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 3365
    [DIFFICULTY_NORMAL][TRAINER_SWIMMER_FEMALE_MELISSA] =
    {
#line 3366
        .trainerName = _("MELISSA"),
#line 3367
        .trainerClass = TRAINER_CLASS_SWIMMER_F,
#line 3368
        .trainerPic = TRAINER_PIC_SWIMMER_F,
        .encounterMusic_gender =
#line 3370
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
#line 3371
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 3372
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 3374
            .species = SPECIES_POLIWAG,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3376
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 3375
            .lvl = 31,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 3378
            .species = SPECIES_SEAKING,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3380
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 3379
            .lvl = 31,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 3382
    [DIFFICULTY_NORMAL][TRAINER_BEAUTY_GRACE] =
    {
#line 3383
        .trainerName = _("GRACE"),
#line 3384
        .trainerClass = TRAINER_CLASS_BEAUTY,
#line 3385
        .trainerPic = TRAINER_PIC_BEAUTY,
        .encounterMusic_gender =
#line 3387
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
#line 3388
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 3389
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 3391
            .species = SPECIES_PIDGEOTTO,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3393
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 3392
            .lvl = 29,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 3395
            .species = SPECIES_WIGGLYTUFF,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3397
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 3396
            .lvl = 29,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 3399
    [DIFFICULTY_NORMAL][TRAINER_BEAUTY_OLIVIA] =
    {
#line 3400
        .trainerName = _("OLIVIA"),
#line 3401
        .trainerClass = TRAINER_CLASS_BEAUTY,
#line 3402
        .trainerPic = TRAINER_PIC_BEAUTY,
        .encounterMusic_gender =
#line 3404
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
#line 3405
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 3406
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 3408
            .species = SPECIES_BULBASAUR,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3410
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 3409
            .lvl = 29,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 3412
            .species = SPECIES_IVYSAUR,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3414
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 3413
            .lvl = 29,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 3416
    [DIFFICULTY_NORMAL][TRAINER_BEAUTY_LAUREN] =
    {
#line 3417
        .trainerName = _("LAUREN"),
#line 3418
        .trainerClass = TRAINER_CLASS_BEAUTY,
#line 3419
        .trainerPic = TRAINER_PIC_SWIMMER_F,
        .encounterMusic_gender =
#line 3421
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
#line 3422
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 3423
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 3425
            .species = SPECIES_WEEPINBELL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3427
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 3426
            .lvl = 33,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 3429
            .species = SPECIES_BELLSPROUT,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3431
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 3430
            .lvl = 33,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 3433
            .species = SPECIES_WEEPINBELL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3435
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 3434
            .lvl = 33,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 3437
    [DIFFICULTY_NORMAL][TRAINER_SWIMMER_FEMALE_ANYA] =
    {
#line 3438
        .trainerName = _("ANYA"),
#line 3439
        .trainerClass = TRAINER_CLASS_SWIMMER_F,
#line 3440
        .trainerPic = TRAINER_PIC_SWIMMER_F,
        .encounterMusic_gender =
#line 3442
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
#line 3443
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 3444
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 5,
        .party = (const struct TrainerMon[])
        {
            {
#line 3446
            .species = SPECIES_POLIWAG,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3448
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 3447
            .lvl = 27,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 3450
            .species = SPECIES_GOLDEEN,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3452
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 3451
            .lvl = 27,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 3454
            .species = SPECIES_SEAKING,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3456
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 3455
            .lvl = 27,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 3458
            .species = SPECIES_GOLDEEN,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3460
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 3459
            .lvl = 27,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 3462
            .species = SPECIES_POLIWAG,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3464
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 3463
            .lvl = 27,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 3466
    [DIFFICULTY_NORMAL][TRAINER_SWIMMER_FEMALE_ALICE] =
    {
#line 3467
        .trainerName = _("ALICE"),
#line 3468
        .trainerClass = TRAINER_CLASS_SWIMMER_F,
#line 3469
        .trainerPic = TRAINER_PIC_SWIMMER_F,
        .encounterMusic_gender =
#line 3471
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
#line 3472
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 3473
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 3475
            .species = SPECIES_GOLDEEN,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3477
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 3476
            .lvl = 30,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 3479
            .species = SPECIES_SEAKING,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3481
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 3480
            .lvl = 30,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 3483
    [DIFFICULTY_NORMAL][TRAINER_SWIMMER_FEMALE_CONNIE] =
    {
#line 3484
        .trainerName = _("CONNIE"),
#line 3485
        .trainerClass = TRAINER_CLASS_SWIMMER_F,
#line 3486
        .trainerPic = TRAINER_PIC_SWIMMER_F,
        .encounterMusic_gender =
#line 3488
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
#line 3489
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 3490
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 3492
            .species = SPECIES_STARYU,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3494
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 3493
            .lvl = 29,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 3496
            .species = SPECIES_STARYU,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3498
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 3497
            .lvl = 29,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 3500
            .species = SPECIES_STARYU,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3502
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 3501
            .lvl = 29,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 3504
    [DIFFICULTY_NORMAL][TRAINER_SWIMMER_FEMALE_SHIRLEY] =
    {
#line 3505
        .trainerName = _("SHIRLEY"),
#line 3506
        .trainerClass = TRAINER_CLASS_SWIMMER_F,
#line 3507
        .trainerPic = TRAINER_PIC_SWIMMER_F,
        .encounterMusic_gender =
#line 3509
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
#line 3510
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 3511
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 3513
            .species = SPECIES_SEADRA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3515
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 3514
            .lvl = 30,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 3517
            .species = SPECIES_HORSEA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3519
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 3518
            .lvl = 30,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 3521
            .species = SPECIES_SEADRA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3523
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 3522
            .lvl = 30,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 3525
    [DIFFICULTY_NORMAL][TRAINER_PSYCHIC_JOHAN] =
    {
#line 3526
        .trainerName = _("JOHAN"),
#line 3527
        .trainerClass = TRAINER_CLASS_PSYCHIC,
#line 3528
        .trainerPic = TRAINER_PIC_PSYCHIC_M,
        .encounterMusic_gender =
#line 3530
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
#line 3531
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 3532
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 4,
        .party = (const struct TrainerMon[])
        {
            {
#line 3534
            .species = SPECIES_KADABRA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3536
            .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
#line 3535
            .lvl = 31,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 3538
            .species = SPECIES_SLOWPOKE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3540
            .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
#line 3539
            .lvl = 31,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 3542
            .species = SPECIES_MR_MIME,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3544
            .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
#line 3543
            .lvl = 31,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 3546
            .species = SPECIES_KADABRA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3548
            .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
#line 3547
            .lvl = 31,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 3550
    [DIFFICULTY_NORMAL][TRAINER_PSYCHIC_TYRON] =
    {
#line 3551
        .trainerName = _("TYRON"),
#line 3552
        .trainerClass = TRAINER_CLASS_PSYCHIC,
#line 3553
        .trainerPic = TRAINER_PIC_PSYCHIC_M,
        .encounterMusic_gender =
#line 3555
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
#line 3556
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 3557
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 3559
            .species = SPECIES_MR_MIME,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3561
            .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
#line 3560
            .lvl = 34,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 3563
            .species = SPECIES_KADABRA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3565
            .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
#line 3564
            .lvl = 34,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 3567
    [DIFFICULTY_NORMAL][TRAINER_PSYCHIC_CAMERON] =
    {
#line 3568
        .trainerName = _("CAMERON"),
#line 3569
        .trainerClass = TRAINER_CLASS_PSYCHIC,
#line 3570
        .trainerPic = TRAINER_PIC_PSYCHIC_M,
        .encounterMusic_gender =
#line 3572
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
#line 3573
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 3574
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 3576
            .species = SPECIES_SLOWPOKE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3578
            .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
#line 3577
            .lvl = 33,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 3580
            .species = SPECIES_SLOWPOKE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3582
            .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
#line 3581
            .lvl = 33,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 3584
            .species = SPECIES_SLOWBRO,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3586
            .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
#line 3585
            .lvl = 33,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 3588
    [DIFFICULTY_NORMAL][TRAINER_PSYCHIC_PRESTON] =
    {
#line 3589
        .trainerName = _("PRESTON"),
#line 3590
        .trainerClass = TRAINER_CLASS_PSYCHIC,
#line 3591
        .trainerPic = TRAINER_PIC_PSYCHIC_M,
        .encounterMusic_gender =
#line 3593
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
#line 3594
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 3595
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 3597
            .species = SPECIES_SLOWBRO,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3599
            .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
#line 3598
            .lvl = 38,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 3601
    [DIFFICULTY_NORMAL][TRAINER_ROCKER_RANDALL] =
    {
#line 3602
        .trainerName = _("RANDALL"),
#line 3603
        .trainerClass = TRAINER_CLASS_ROCKER,
#line 3604
        .trainerPic = TRAINER_PIC_ROCKER,
        .encounterMusic_gender =
#line 3606
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 3607
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 3608
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 3610
            .species = SPECIES_VOLTORB,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3612
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 3611
            .lvl = 20,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 3614
            .species = SPECIES_MAGNEMITE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3616
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 3615
            .lvl = 20,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 3618
            .species = SPECIES_VOLTORB,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3620
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 3619
            .lvl = 20,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 3622
    [DIFFICULTY_NORMAL][TRAINER_ROCKER_LUCA] =
    {
#line 3623
        .trainerName = _("LUCA"),
#line 3624
        .trainerClass = TRAINER_CLASS_ROCKER,
#line 3625
        .trainerPic = TRAINER_PIC_ROCKER,
        .encounterMusic_gender =
#line 3627
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 3628
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 3629
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 3631
            .species = SPECIES_VOLTORB,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3633
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 3632
            .lvl = 29,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 3635
            .species = SPECIES_ELECTRODE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3637
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 3636
            .lvl = 29,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 3639
    [DIFFICULTY_NORMAL][TRAINER_JUGGLER_DALTON] =
    {
#line 3640
        .trainerName = _("DALTON"),
#line 3641
        .trainerClass = TRAINER_CLASS_JUGGLER,
#line 3642
        .trainerPic = TRAINER_PIC_JUGGLER,
        .encounterMusic_gender =
#line 3644
            TRAINER_ENCOUNTER_MUSIC_HIKER,
#line 3645
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 3646
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 3648
            .species = SPECIES_KADABRA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3650
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 3649
            .lvl = 29,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 3652
            .species = SPECIES_MR_MIME,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3654
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 3653
            .lvl = 29,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 3656
    [DIFFICULTY_NORMAL][TRAINER_JUGGLER_NELSON] =
    {
#line 3657
        .trainerName = _("NELSON"),
#line 3658
        .trainerClass = TRAINER_CLASS_JUGGLER,
#line 3659
        .trainerPic = TRAINER_PIC_JUGGLER,
        .encounterMusic_gender =
#line 3661
            TRAINER_ENCOUNTER_MUSIC_HIKER,
#line 3662
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 3663
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 4,
        .party = (const struct TrainerMon[])
        {
            {
#line 3665
            .species = SPECIES_DROWZEE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3667
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 3666
            .lvl = 41,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 3669
            .species = SPECIES_HYPNO,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3671
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 3670
            .lvl = 41,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 3673
            .species = SPECIES_KADABRA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3675
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 3674
            .lvl = 41,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 3677
            .species = SPECIES_KADABRA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3679
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 3678
            .lvl = 41,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 3681
    [DIFFICULTY_NORMAL][TRAINER_JUGGLER_KIRK] =
    {
#line 3682
        .trainerName = _("KIRK"),
#line 3683
        .trainerClass = TRAINER_CLASS_JUGGLER,
#line 3684
        .trainerPic = TRAINER_PIC_JUGGLER,
        .encounterMusic_gender =
#line 3686
            TRAINER_ENCOUNTER_MUSIC_HIKER,
#line 3687
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 3688
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 4,
        .party = (const struct TrainerMon[])
        {
            {
#line 3690
            .species = SPECIES_DROWZEE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3692
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 3691
            .lvl = 31,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 3694
            .species = SPECIES_DROWZEE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3696
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 3695
            .lvl = 31,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 3698
            .species = SPECIES_KADABRA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3700
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 3699
            .lvl = 31,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 3702
            .species = SPECIES_DROWZEE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3704
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 3703
            .lvl = 31,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 3706
    [DIFFICULTY_NORMAL][TRAINER_JUGGLER_SHAWN] =
    {
#line 3707
        .trainerName = _("SHAWN"),
#line 3708
        .trainerClass = TRAINER_CLASS_JUGGLER,
#line 3709
        .trainerPic = TRAINER_PIC_JUGGLER,
        .encounterMusic_gender =
#line 3711
            TRAINER_ENCOUNTER_MUSIC_HIKER,
#line 3712
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 3713
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 3715
            .species = SPECIES_DROWZEE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3717
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 3716
            .lvl = 34,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 3719
            .species = SPECIES_HYPNO,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3721
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 3720
            .lvl = 34,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 3723
    [DIFFICULTY_NORMAL][TRAINER_JUGGLER_GREGORY] =
    {
#line 3724
        .trainerName = _("GREGORY"),
#line 3725
        .trainerClass = TRAINER_CLASS_JUGGLER,
#line 3726
        .trainerPic = TRAINER_PIC_JUGGLER,
        .encounterMusic_gender =
#line 3728
            TRAINER_ENCOUNTER_MUSIC_HIKER,
#line 3729
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 3730
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 3732
            .species = SPECIES_MR_MIME,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3734
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 3733
            .lvl = 48,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 3735
                MOVE_PSYCHIC,
                MOVE_ROLE_PLAY,
                MOVE_DOUBLE_SLAP,
                MOVE_ENCORE,
            },
            },
        },
    },
#line 3740
    [DIFFICULTY_NORMAL][TRAINER_JUGGLER_EDWARD] =
    {
#line 3741
        .trainerName = _("EDWARD"),
#line 3742
        .trainerClass = TRAINER_CLASS_JUGGLER,
#line 3743
        .trainerPic = TRAINER_PIC_JUGGLER,
        .encounterMusic_gender =
#line 3745
            TRAINER_ENCOUNTER_MUSIC_HIKER,
#line 3746
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 3747
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 4,
        .party = (const struct TrainerMon[])
        {
            {
#line 3749
            .species = SPECIES_VOLTORB,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3751
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 3750
            .lvl = 46,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 3752
                MOVE_SWIFT,
                MOVE_LIGHT_SCREEN,
                MOVE_SPARK,
                MOVE_SONIC_BOOM,
            },
            },
            {
#line 3757
            .species = SPECIES_VOLTORB,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3759
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 3758
            .lvl = 46,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 3760
                MOVE_SWIFT,
                MOVE_LIGHT_SCREEN,
                MOVE_SPARK,
                MOVE_SONIC_BOOM,
            },
            },
            {
#line 3765
            .species = SPECIES_ELECTRODE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3767
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 3766
            .lvl = 47,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 3768
                MOVE_SWIFT,
                MOVE_SPARK,
                MOVE_SELF_DESTRUCT,
                MOVE_SONIC_BOOM,
            },
            },
            {
#line 3773
            .species = SPECIES_MR_MIME,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3775
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 3774
            .lvl = 48,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 3776
                MOVE_PSYCHIC,
                MOVE_ROLE_PLAY,
                MOVE_REFLECT,
                MOVE_ENCORE,
            },
            },
        },
    },
#line 3781
    [DIFFICULTY_NORMAL][TRAINER_JUGGLER_KAYDEN] =
    {
#line 3782
        .trainerName = _("KAYDEN"),
#line 3783
        .trainerClass = TRAINER_CLASS_JUGGLER,
#line 3784
        .trainerPic = TRAINER_PIC_JUGGLER,
        .encounterMusic_gender =
#line 3786
            TRAINER_ENCOUNTER_MUSIC_HIKER,
#line 3787
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 3788
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 3790
            .species = SPECIES_HYPNO,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3792
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 3791
            .lvl = 38,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 3794
    [DIFFICULTY_NORMAL][TRAINER_JUGGLER_NATE] =
    {
#line 3795
        .trainerName = _("NATE"),
#line 3796
        .trainerClass = TRAINER_CLASS_JUGGLER,
#line 3797
        .trainerPic = TRAINER_PIC_JUGGLER,
        .encounterMusic_gender =
#line 3799
            TRAINER_ENCOUNTER_MUSIC_HIKER,
#line 3800
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 3801
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 3803
            .species = SPECIES_DROWZEE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3805
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 3804
            .lvl = 34,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 3807
            .species = SPECIES_KADABRA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3809
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 3808
            .lvl = 34,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 3811
    [DIFFICULTY_NORMAL][TRAINER_TAMER_PHIL] =
    {
#line 3812
        .trainerName = _("PHIL"),
#line 3813
        .trainerClass = TRAINER_CLASS_TAMER,
#line 3814
        .trainerPic = TRAINER_PIC_TAMER,
        .encounterMusic_gender =
#line 3816
            TRAINER_ENCOUNTER_MUSIC_HIKER,
#line 3817
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 3818
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 3820
            .species = SPECIES_SANDSLASH,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3822
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
#line 3821
            .lvl = 34,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 3824
            .species = SPECIES_ARBOK,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3826
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
#line 3825
            .lvl = 34,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 3828
    [DIFFICULTY_NORMAL][TRAINER_TAMER_EDGAR] =
    {
#line 3829
        .trainerName = _("EDGAR"),
#line 3830
        .trainerClass = TRAINER_CLASS_TAMER,
#line 3831
        .trainerPic = TRAINER_PIC_TAMER,
        .encounterMusic_gender =
#line 3833
            TRAINER_ENCOUNTER_MUSIC_HIKER,
#line 3834
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 3835
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 3837
            .species = SPECIES_ARBOK,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3839
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
#line 3838
            .lvl = 33,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 3841
            .species = SPECIES_SANDSLASH,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3843
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
#line 3842
            .lvl = 33,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 3845
            .species = SPECIES_ARBOK,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3847
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
#line 3846
            .lvl = 33,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 3849
    [DIFFICULTY_NORMAL][TRAINER_TAMER_JASON] =
    {
#line 3850
        .trainerName = _("JASON"),
#line 3851
        .trainerClass = TRAINER_CLASS_TAMER,
#line 3852
        .trainerPic = TRAINER_PIC_TAMER,
        .encounterMusic_gender =
#line 3854
            TRAINER_ENCOUNTER_MUSIC_HIKER,
#line 3855
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 3856
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 3858
            .species = SPECIES_RHYHORN,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3860
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
#line 3859
            .lvl = 43,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 3862
    [DIFFICULTY_NORMAL][TRAINER_TAMER_COLE] =
    {
#line 3863
        .trainerName = _("COLE"),
#line 3864
        .trainerClass = TRAINER_CLASS_TAMER,
#line 3865
        .trainerPic = TRAINER_PIC_TAMER,
        .encounterMusic_gender =
#line 3867
            TRAINER_ENCOUNTER_MUSIC_HIKER,
#line 3868
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 3869
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 3871
            .species = SPECIES_ARBOK,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3873
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
#line 3872
            .lvl = 39,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 3875
            .species = SPECIES_TAUROS,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3877
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
#line 3876
            .lvl = 39,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 3879
    [DIFFICULTY_NORMAL][TRAINER_TAMER_VINCENT] =
    {
#line 3880
        .trainerName = _("VINCENT"),
#line 3881
        .trainerClass = TRAINER_CLASS_TAMER,
#line 3882
        .trainerPic = TRAINER_PIC_TAMER,
        .encounterMusic_gender =
#line 3884
            TRAINER_ENCOUNTER_MUSIC_HIKER,
#line 3885
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 3886
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 3888
            .species = SPECIES_PERSIAN,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3890
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
#line 3889
            .lvl = 44,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 3892
            .species = SPECIES_GOLDUCK,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3894
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
#line 3893
            .lvl = 44,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 3896
    [DIFFICULTY_NORMAL][TRAINER_TAMER_JOHN] =
    {
#line 3897
        .trainerName = _("JOHN"),
#line 3898
        .trainerClass = TRAINER_CLASS_TAMER,
#line 3899
        .trainerPic = TRAINER_PIC_TAMER,
        .encounterMusic_gender =
#line 3901
            TRAINER_ENCOUNTER_MUSIC_HIKER,
#line 3902
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 3903
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 4,
        .party = (const struct TrainerMon[])
        {
            {
#line 3905
            .species = SPECIES_RHYHORN,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3907
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
#line 3906
            .lvl = 42,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 3909
            .species = SPECIES_PRIMEAPE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3911
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
#line 3910
            .lvl = 42,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 3913
            .species = SPECIES_ARBOK,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3915
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
#line 3914
            .lvl = 42,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 3917
            .species = SPECIES_TAUROS,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3919
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
#line 3918
            .lvl = 42,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 3921
    [DIFFICULTY_NORMAL][TRAINER_BIRD_KEEPER_SEBASTIAN] =
    {
#line 3922
        .trainerName = _("SEBASTIAN"),
#line 3923
        .trainerClass = TRAINER_CLASS_BIRD_KEEPER,
#line 3924
        .trainerPic = TRAINER_PIC_BIRD_KEEPER,
        .encounterMusic_gender =
#line 3926
            TRAINER_ENCOUNTER_MUSIC_COOL,
#line 3927
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 3928
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 3930
            .species = SPECIES_PIDGEY,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3932
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 3931
            .lvl = 29,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 3934
            .species = SPECIES_PIDGEOTTO,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3936
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 3935
            .lvl = 29,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 3938
    [DIFFICULTY_NORMAL][TRAINER_BIRD_KEEPER_PERRY] =
    {
#line 3939
        .trainerName = _("PERRY"),
#line 3940
        .trainerClass = TRAINER_CLASS_BIRD_KEEPER,
#line 3941
        .trainerPic = TRAINER_PIC_BIRD_KEEPER,
        .encounterMusic_gender =
#line 3943
            TRAINER_ENCOUNTER_MUSIC_COOL,
#line 3944
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 3945
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 5,
        .party = (const struct TrainerMon[])
        {
            {
#line 3947
            .species = SPECIES_SPEAROW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3949
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 3948
            .lvl = 25,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 3951
            .species = SPECIES_PIDGEY,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3953
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 3952
            .lvl = 25,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 3955
            .species = SPECIES_PIDGEY,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3957
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 3956
            .lvl = 25,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 3959
            .species = SPECIES_SPEAROW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3961
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 3960
            .lvl = 25,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 3963
            .species = SPECIES_SPEAROW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3965
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 3964
            .lvl = 25,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 3967
    [DIFFICULTY_NORMAL][TRAINER_BIRD_KEEPER_ROBERT] =
    {
#line 3968
        .trainerName = _("ROBERT"),
#line 3969
        .trainerClass = TRAINER_CLASS_BIRD_KEEPER,
#line 3970
        .trainerPic = TRAINER_PIC_BIRD_KEEPER,
        .encounterMusic_gender =
#line 3972
            TRAINER_ENCOUNTER_MUSIC_COOL,
#line 3973
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 3974
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 4,
        .party = (const struct TrainerMon[])
        {
            {
#line 3976
            .species = SPECIES_PIDGEY,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3978
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 3977
            .lvl = 26,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 3980
            .species = SPECIES_PIDGEOTTO,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3982
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 3981
            .lvl = 26,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 3984
            .species = SPECIES_SPEAROW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3986
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 3985
            .lvl = 26,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 3988
            .species = SPECIES_FEAROW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3990
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 3989
            .lvl = 26,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 3992
    [DIFFICULTY_NORMAL][TRAINER_BIRD_KEEPER_DONALD] =
    {
#line 3993
        .trainerName = _("DONALD"),
#line 3994
        .trainerClass = TRAINER_CLASS_BIRD_KEEPER,
#line 3995
        .trainerPic = TRAINER_PIC_BIRD_KEEPER,
        .encounterMusic_gender =
#line 3997
            TRAINER_ENCOUNTER_MUSIC_COOL,
#line 3998
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 3999
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 4001
            .species = SPECIES_FARFETCHD,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4003
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 4002
            .lvl = 33,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 4005
    [DIFFICULTY_NORMAL][TRAINER_BIRD_KEEPER_BENNY] =
    {
#line 4006
        .trainerName = _("BENNY"),
#line 4007
        .trainerClass = TRAINER_CLASS_BIRD_KEEPER,
#line 4008
        .trainerPic = TRAINER_PIC_BIRD_KEEPER,
        .encounterMusic_gender =
#line 4010
            TRAINER_ENCOUNTER_MUSIC_COOL,
#line 4011
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 4012
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 4014
            .species = SPECIES_SPEAROW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4016
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 4015
            .lvl = 29,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 4018
            .species = SPECIES_FEAROW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4020
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 4019
            .lvl = 29,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 4022
    [DIFFICULTY_NORMAL][TRAINER_BIRD_KEEPER_EDWIN] =
    {
#line 4023
        .trainerName = _("EDWIN"),
#line 4024
        .trainerClass = TRAINER_CLASS_BIRD_KEEPER,
#line 4025
        .trainerPic = TRAINER_PIC_BIRD_KEEPER,
        .encounterMusic_gender =
#line 4027
            TRAINER_ENCOUNTER_MUSIC_COOL,
#line 4028
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 4029
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 4,
        .party = (const struct TrainerMon[])
        {
            {
#line 4031
            .species = SPECIES_PIDGEOTTO,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4033
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 4032
            .lvl = 26,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 4035
            .species = SPECIES_FARFETCHD,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4037
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 4036
            .lvl = 26,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 4039
            .species = SPECIES_DODUO,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4041
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 4040
            .lvl = 26,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 4043
            .species = SPECIES_PIDGEY,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4045
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 4044
            .lvl = 26,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 4047
    [DIFFICULTY_NORMAL][TRAINER_BIRD_KEEPER_CHESTER] =
    {
#line 4048
        .trainerName = _("CHESTER"),
#line 4049
        .trainerClass = TRAINER_CLASS_BIRD_KEEPER,
#line 4050
        .trainerPic = TRAINER_PIC_BIRD_KEEPER,
        .encounterMusic_gender =
#line 4052
            TRAINER_ENCOUNTER_MUSIC_COOL,
#line 4053
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 4054
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 4056
            .species = SPECIES_DODRIO,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4058
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 4057
            .lvl = 28,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 4060
            .species = SPECIES_DODUO,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4062
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 4061
            .lvl = 28,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 4064
            .species = SPECIES_DODUO,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4066
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 4065
            .lvl = 28,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 4068
    [DIFFICULTY_NORMAL][TRAINER_BIRD_KEEPER_WILTON] =
    {
#line 4069
        .trainerName = _("WILTON"),
#line 4070
        .trainerClass = TRAINER_CLASS_BIRD_KEEPER,
#line 4071
        .trainerPic = TRAINER_PIC_BIRD_KEEPER,
        .encounterMusic_gender =
#line 4073
            TRAINER_ENCOUNTER_MUSIC_COOL,
#line 4074
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 4075
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 4077
            .species = SPECIES_SPEAROW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4079
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 4078
            .lvl = 29,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 4081
            .species = SPECIES_FEAROW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4083
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 4082
            .lvl = 29,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 4085
    [DIFFICULTY_NORMAL][TRAINER_BIRD_KEEPER_RAMIRO] =
    {
#line 4086
        .trainerName = _("RAMIRO"),
#line 4087
        .trainerClass = TRAINER_CLASS_BIRD_KEEPER,
#line 4088
        .trainerPic = TRAINER_PIC_BIRD_KEEPER,
        .encounterMusic_gender =
#line 4090
            TRAINER_ENCOUNTER_MUSIC_COOL,
#line 4091
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 4092
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 4094
            .species = SPECIES_DODRIO,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4096
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 4095
            .lvl = 34,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 4098
    [DIFFICULTY_NORMAL][TRAINER_BIRD_KEEPER_JACOB] =
    {
#line 4099
        .trainerName = _("JACOB"),
#line 4100
        .trainerClass = TRAINER_CLASS_BIRD_KEEPER,
#line 4101
        .trainerPic = TRAINER_PIC_BIRD_KEEPER,
        .encounterMusic_gender =
#line 4103
            TRAINER_ENCOUNTER_MUSIC_COOL,
#line 4104
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 4105
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 4,
        .party = (const struct TrainerMon[])
        {
            {
#line 4107
            .species = SPECIES_SPEAROW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4109
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 4108
            .lvl = 26,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 4111
            .species = SPECIES_SPEAROW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4113
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 4112
            .lvl = 26,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 4115
            .species = SPECIES_FEAROW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4117
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 4116
            .lvl = 26,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 4119
            .species = SPECIES_SPEAROW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4121
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 4120
            .lvl = 26,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 4123
    [DIFFICULTY_NORMAL][TRAINER_BIRD_KEEPER_ROGER] =
    {
#line 4124
        .trainerName = _("ROGER"),
#line 4125
        .trainerClass = TRAINER_CLASS_BIRD_KEEPER,
#line 4126
        .trainerPic = TRAINER_PIC_BIRD_KEEPER,
        .encounterMusic_gender =
#line 4128
            TRAINER_ENCOUNTER_MUSIC_COOL,
#line 4129
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 4130
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 4132
            .species = SPECIES_FEAROW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4134
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 4133
            .lvl = 30,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 4136
            .species = SPECIES_FEAROW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4138
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 4137
            .lvl = 30,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 4140
            .species = SPECIES_PIDGEOTTO,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4142
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 4141
            .lvl = 30,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 4144
    [DIFFICULTY_NORMAL][TRAINER_BIRD_KEEPER_REED] =
    {
#line 4145
        .trainerName = _("REED"),
#line 4146
        .trainerClass = TRAINER_CLASS_BIRD_KEEPER,
#line 4147
        .trainerPic = TRAINER_PIC_BIRD_KEEPER,
        .encounterMusic_gender =
#line 4149
            TRAINER_ENCOUNTER_MUSIC_COOL,
#line 4150
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 4151
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 4,
        .party = (const struct TrainerMon[])
        {
            {
#line 4153
            .species = SPECIES_PIDGEOTTO,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4155
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 4154
            .lvl = 39,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 4157
            .species = SPECIES_PIDGEOTTO,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4159
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 4158
            .lvl = 39,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 4161
            .species = SPECIES_PIDGEY,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4163
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 4162
            .lvl = 39,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 4165
            .species = SPECIES_PIDGEOTTO,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4167
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 4166
            .lvl = 39,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 4169
    [DIFFICULTY_NORMAL][TRAINER_BIRD_KEEPER_KEITH] =
    {
#line 4170
        .trainerName = _("KEITH"),
#line 4171
        .trainerClass = TRAINER_CLASS_BIRD_KEEPER,
#line 4172
        .trainerPic = TRAINER_PIC_BIRD_KEEPER,
        .encounterMusic_gender =
#line 4174
            TRAINER_ENCOUNTER_MUSIC_COOL,
#line 4175
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 4176
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 4178
            .species = SPECIES_FARFETCHD,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4180
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 4179
            .lvl = 39,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 4182
            .species = SPECIES_FEAROW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4184
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 4183
            .lvl = 39,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 4186
    [DIFFICULTY_NORMAL][TRAINER_BIRD_KEEPER_CARTER] =
    {
#line 4187
        .trainerName = _("CARTER"),
#line 4188
        .trainerClass = TRAINER_CLASS_BIRD_KEEPER,
#line 4189
        .trainerPic = TRAINER_PIC_BIRD_KEEPER,
        .encounterMusic_gender =
#line 4191
            TRAINER_ENCOUNTER_MUSIC_COOL,
#line 4192
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 4193
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 4195
            .species = SPECIES_PIDGEY,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4197
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 4196
            .lvl = 28,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 4199
            .species = SPECIES_DODUO,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4201
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 4200
            .lvl = 28,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 4203
            .species = SPECIES_PIDGEOTTO,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4205
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 4204
            .lvl = 28,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 4207
    [DIFFICULTY_NORMAL][TRAINER_BIRD_KEEPER_MITCH] =
    {
#line 4208
        .trainerName = _("MITCH"),
#line 4209
        .trainerClass = TRAINER_CLASS_BIRD_KEEPER,
#line 4210
        .trainerPic = TRAINER_PIC_BIRD_KEEPER,
        .encounterMusic_gender =
#line 4212
            TRAINER_ENCOUNTER_MUSIC_COOL,
#line 4213
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 4214
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 4,
        .party = (const struct TrainerMon[])
        {
            {
#line 4216
            .species = SPECIES_PIDGEY,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4218
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 4217
            .lvl = 26,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 4220
            .species = SPECIES_SPEAROW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4222
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 4221
            .lvl = 26,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 4224
            .species = SPECIES_PIDGEY,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4226
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 4225
            .lvl = 26,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 4228
            .species = SPECIES_FEAROW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4230
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 4229
            .lvl = 26,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 4232
    [DIFFICULTY_NORMAL][TRAINER_BIRD_KEEPER_BECK] =
    {
#line 4233
        .trainerName = _("BECK"),
#line 4234
        .trainerClass = TRAINER_CLASS_BIRD_KEEPER,
#line 4235
        .trainerPic = TRAINER_PIC_BIRD_KEEPER,
        .encounterMusic_gender =
#line 4237
            TRAINER_ENCOUNTER_MUSIC_COOL,
#line 4238
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 4239
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 4241
            .species = SPECIES_PIDGEOTTO,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4243
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 4242
            .lvl = 29,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 4245
            .species = SPECIES_FEAROW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4247
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 4246
            .lvl = 29,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 4249
    [DIFFICULTY_NORMAL][TRAINER_BIRD_KEEPER_MARLON] =
    {
#line 4250
        .trainerName = _("MARLON"),
#line 4251
        .trainerClass = TRAINER_CLASS_BIRD_KEEPER,
#line 4252
        .trainerPic = TRAINER_PIC_BIRD_KEEPER,
        .encounterMusic_gender =
#line 4254
            TRAINER_ENCOUNTER_MUSIC_COOL,
#line 4255
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 4256
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 4258
            .species = SPECIES_SPEAROW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4260
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 4259
            .lvl = 28,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 4262
            .species = SPECIES_DODUO,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4264
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 4263
            .lvl = 28,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 4266
            .species = SPECIES_FEAROW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4268
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 4267
            .lvl = 28,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 4270
    [DIFFICULTY_NORMAL][TRAINER_BLACK_BELT_KOICHI] =
    {
#line 4271
        .trainerName = _("KOICHI"),
#line 4272
        .trainerClass = TRAINER_CLASS_BLACK_BELT,
#line 4273
        .trainerPic = TRAINER_PIC_BLACK_BELT,
        .encounterMusic_gender =
#line 4275
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
#line 4276
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 4277
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 4279
            .species = SPECIES_HITMONLEE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4279
            .heldItem = ITEM_BLACK_BELT,
#line 4281
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 4280
            .lvl = 37,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 4283
            .species = SPECIES_HITMONCHAN,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4283
            .heldItem = ITEM_BLACK_BELT,
#line 4285
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 4284
            .lvl = 37,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 4287
    [DIFFICULTY_NORMAL][TRAINER_BLACK_BELT_MIKE] =
    {
#line 4288
        .trainerName = _("MIKE"),
#line 4289
        .trainerClass = TRAINER_CLASS_BLACK_BELT,
#line 4290
        .trainerPic = TRAINER_PIC_BLACK_BELT,
        .encounterMusic_gender =
#line 4292
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
#line 4293
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 4294
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 4296
            .species = SPECIES_MANKEY,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4296
            .heldItem = ITEM_BLACK_BELT,
#line 4298
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 4297
            .lvl = 31,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 4300
            .species = SPECIES_MANKEY,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4300
            .heldItem = ITEM_BLACK_BELT,
#line 4302
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 4301
            .lvl = 31,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 4304
            .species = SPECIES_PRIMEAPE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4304
            .heldItem = ITEM_BLACK_BELT,
#line 4306
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 4305
            .lvl = 31,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 4308
    [DIFFICULTY_NORMAL][TRAINER_BLACK_BELT_HIDEKI] =
    {
#line 4309
        .trainerName = _("HIDEKI"),
#line 4310
        .trainerClass = TRAINER_CLASS_BLACK_BELT,
#line 4311
        .trainerPic = TRAINER_PIC_BLACK_BELT,
        .encounterMusic_gender =
#line 4313
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
#line 4314
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 4315
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 4317
            .species = SPECIES_MACHOP,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4317
            .heldItem = ITEM_BLACK_BELT,
#line 4319
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 4318
            .lvl = 32,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 4321
            .species = SPECIES_MACHOKE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4321
            .heldItem = ITEM_BLACK_BELT,
#line 4323
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 4322
            .lvl = 32,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 4325
    [DIFFICULTY_NORMAL][TRAINER_BLACK_BELT_AARON] =
    {
#line 4326
        .trainerName = _("AARON"),
#line 4327
        .trainerClass = TRAINER_CLASS_BLACK_BELT,
#line 4328
        .trainerPic = TRAINER_PIC_BLACK_BELT,
        .encounterMusic_gender =
#line 4330
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
#line 4331
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 4332
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 4334
            .species = SPECIES_PRIMEAPE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4334
            .heldItem = ITEM_BLACK_BELT,
#line 4336
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 4335
            .lvl = 36,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 4338
    [DIFFICULTY_NORMAL][TRAINER_BLACK_BELT_HITOSHI] =
    {
#line 4339
        .trainerName = _("HITOSHI"),
#line 4340
        .trainerClass = TRAINER_CLASS_BLACK_BELT,
#line 4341
        .trainerPic = TRAINER_PIC_BLACK_BELT,
        .encounterMusic_gender =
#line 4343
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
#line 4344
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 4345
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 4347
            .species = SPECIES_MACHOP,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4347
            .heldItem = ITEM_BLACK_BELT,
#line 4349
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 4348
            .lvl = 31,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 4351
            .species = SPECIES_MANKEY,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4351
            .heldItem = ITEM_BLACK_BELT,
#line 4353
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 4352
            .lvl = 31,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 4355
            .species = SPECIES_PRIMEAPE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4355
            .heldItem = ITEM_BLACK_BELT,
#line 4357
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 4356
            .lvl = 31,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 4359
    [DIFFICULTY_NORMAL][TRAINER_BLACK_BELT_ATSUSHI] =
    {
#line 4360
        .trainerName = _("ATSUSHI"),
#line 4361
        .trainerClass = TRAINER_CLASS_BLACK_BELT,
#line 4362
        .trainerPic = TRAINER_PIC_BLACK_BELT,
        .encounterMusic_gender =
#line 4364
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
#line 4365
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 4366
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 4368
            .species = SPECIES_MACHOP,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4368
            .heldItem = ITEM_BLACK_BELT,
#line 4370
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 4369
            .lvl = 40,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 4372
            .species = SPECIES_MACHOKE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4372
            .heldItem = ITEM_BLACK_BELT,
#line 4374
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 4373
            .lvl = 40,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 4376
    [DIFFICULTY_NORMAL][TRAINER_BLACK_BELT_KIYO] =
    {
#line 4377
        .trainerName = _("KIYO"),
#line 4378
        .trainerClass = TRAINER_CLASS_BLACK_BELT,
#line 4379
        .trainerPic = TRAINER_PIC_BLACK_BELT,
        .encounterMusic_gender =
#line 4381
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
#line 4382
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 4383
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 4385
            .species = SPECIES_MACHOKE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4385
            .heldItem = ITEM_BLACK_BELT,
#line 4387
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 4386
            .lvl = 43,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 4389
    [DIFFICULTY_NORMAL][TRAINER_BLACK_BELT_TAKASHI] =
    {
#line 4390
        .trainerName = _("TAKASHI"),
#line 4391
        .trainerClass = TRAINER_CLASS_BLACK_BELT,
#line 4392
        .trainerPic = TRAINER_PIC_BLACK_BELT,
        .encounterMusic_gender =
#line 4394
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
#line 4395
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 4396
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 4398
            .species = SPECIES_MACHOKE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4398
            .heldItem = ITEM_BLACK_BELT,
#line 4400
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 4399
            .lvl = 38,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 4402
            .species = SPECIES_MACHOP,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4402
            .heldItem = ITEM_BLACK_BELT,
#line 4404
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 4403
            .lvl = 38,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 4406
            .species = SPECIES_MACHOKE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4406
            .heldItem = ITEM_BLACK_BELT,
#line 4408
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 4407
            .lvl = 38,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 4410
    [DIFFICULTY_NORMAL][TRAINER_BLACK_BELT_DAISUKE] =
    {
#line 4411
        .trainerName = _("DAISUKE"),
#line 4412
        .trainerClass = TRAINER_CLASS_BLACK_BELT,
#line 4413
        .trainerPic = TRAINER_PIC_BLACK_BELT,
        .encounterMusic_gender =
#line 4415
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
#line 4416
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 4417
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 4419
            .species = SPECIES_MACHOKE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4419
            .heldItem = ITEM_BLACK_BELT,
#line 4421
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 4420
            .lvl = 43,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 4423
            .species = SPECIES_MACHOP,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4423
            .heldItem = ITEM_BLACK_BELT,
#line 4425
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 4424
            .lvl = 43,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 4427
            .species = SPECIES_MACHOKE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4427
            .heldItem = ITEM_BLACK_BELT,
#line 4429
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 4428
            .lvl = 43,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 4431
    [DIFFICULTY_NORMAL][TRAINER_RIVAL_OAKS_LAB_SQUIRTLE] =
    {
#line 4432
        .trainerName = _("TERRY"),
#line 4433
        .trainerClass = TRAINER_CLASS_RIVAL_EARLY,
#line 4434
        .trainerPic = TRAINER_PIC_RIVAL_EARLY,
        .encounterMusic_gender =
#line 4436
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 4437
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 4438
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 4440
            .species = SPECIES_SQUIRTLE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4442
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 4441
            .lvl = 5,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 4443
                MOVE_TACKLE,
                MOVE_TAIL_WHIP,
            },
            },
        },
    },
#line 4446
    [DIFFICULTY_NORMAL][TRAINER_RIVAL_OAKS_LAB_BULBASAUR] =
    {
#line 4447
        .trainerName = _("TERRY"),
#line 4448
        .trainerClass = TRAINER_CLASS_RIVAL_EARLY,
#line 4449
        .trainerPic = TRAINER_PIC_RIVAL_EARLY,
        .encounterMusic_gender =
#line 4451
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 4452
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 4453
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 4455
            .species = SPECIES_BULBASAUR,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4457
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 4456
            .lvl = 5,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 4458
                MOVE_TACKLE,
                MOVE_GROWL,
            },
            },
        },
    },
#line 4461
    [DIFFICULTY_NORMAL][TRAINER_RIVAL_OAKS_LAB_CHARMANDER] =
    {
#line 4462
        .trainerName = _("TERRY"),
#line 4463
        .trainerClass = TRAINER_CLASS_RIVAL_EARLY,
#line 4464
        .trainerPic = TRAINER_PIC_RIVAL_EARLY,
        .encounterMusic_gender =
#line 4466
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 4467
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 4468
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 4470
            .species = SPECIES_CHARMANDER,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4472
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 4471
            .lvl = 5,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 4473
                MOVE_SCRATCH,
                MOVE_GROWL,
            },
            },
        },
    },
#line 4476
    [DIFFICULTY_NORMAL][TRAINER_RIVAL_ROUTE22_EARLY_SQUIRTLE] =
    {
#line 4477
        .trainerName = _("TERRY"),
#line 4478
        .trainerClass = TRAINER_CLASS_RIVAL_EARLY,
#line 4479
        .trainerPic = TRAINER_PIC_RIVAL_EARLY,
        .encounterMusic_gender =
#line 4481
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 4482
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 4483
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 4485
            .species = SPECIES_PIDGEY,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4487
            .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
#line 4486
            .lvl = 9,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 4488
                MOVE_TACKLE,
                MOVE_SAND_ATTACK,
            },
            },
            {
#line 4491
            .species = SPECIES_SQUIRTLE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4493
            .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
#line 4492
            .lvl = 9,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 4494
                MOVE_TACKLE,
                MOVE_TAIL_WHIP,
            },
            },
        },
    },
#line 4497
    [DIFFICULTY_NORMAL][TRAINER_RIVAL_ROUTE22_EARLY_BULBASAUR] =
    {
#line 4498
        .trainerName = _("TERRY"),
#line 4499
        .trainerClass = TRAINER_CLASS_RIVAL_EARLY,
#line 4500
        .trainerPic = TRAINER_PIC_RIVAL_EARLY,
        .encounterMusic_gender =
#line 4502
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 4503
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 4504
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 4506
            .species = SPECIES_PIDGEY,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4508
            .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
#line 4507
            .lvl = 9,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 4509
                MOVE_TACKLE,
                MOVE_SAND_ATTACK,
            },
            },
            {
#line 4512
            .species = SPECIES_BULBASAUR,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4514
            .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
#line 4513
            .lvl = 9,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 4515
                MOVE_TACKLE,
                MOVE_GROWL,
            },
            },
        },
    },
#line 4518
    [DIFFICULTY_NORMAL][TRAINER_RIVAL_ROUTE22_EARLY_CHARMANDER] =
    {
#line 4519
        .trainerName = _("TERRY"),
#line 4520
        .trainerClass = TRAINER_CLASS_RIVAL_EARLY,
#line 4521
        .trainerPic = TRAINER_PIC_RIVAL_EARLY,
        .encounterMusic_gender =
#line 4523
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 4524
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 4525
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 4527
            .species = SPECIES_PIDGEY,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4529
            .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
#line 4528
            .lvl = 9,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 4530
                MOVE_TACKLE,
                MOVE_SAND_ATTACK,
            },
            },
            {
#line 4533
            .species = SPECIES_CHARMANDER,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4535
            .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
#line 4534
            .lvl = 9,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 4536
                MOVE_SCRATCH,
                MOVE_GROWL,
            },
            },
        },
    },
#line 4539
    [DIFFICULTY_NORMAL][TRAINER_RIVAL_CERULEAN_SQUIRTLE] =
    {
#line 4540
        .trainerName = _("TERRY"),
#line 4541
        .trainerClass = TRAINER_CLASS_RIVAL_EARLY,
#line 4542
        .trainerPic = TRAINER_PIC_RIVAL_EARLY,
        .encounterMusic_gender =
#line 4544
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 4545
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 4546
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .partySize = 4,
        .party = (const struct TrainerMon[])
        {
            {
#line 4548
            .species = SPECIES_PIDGEOTTO,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4550
            .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
#line 4549
            .lvl = 17,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 4551
                MOVE_TACKLE,
                MOVE_SAND_ATTACK,
                MOVE_GUST,
                MOVE_QUICK_ATTACK,
            },
            },
            {
#line 4556
            .species = SPECIES_ABRA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4558
            .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
#line 4557
            .lvl = 16,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 4559
                MOVE_TELEPORT,
            },
            },
            {
#line 4561
            .species = SPECIES_RATTATA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4563
            .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
#line 4562
            .lvl = 15,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 4564
                MOVE_TACKLE,
                MOVE_TAIL_WHIP,
                MOVE_QUICK_ATTACK,
            },
            },
            {
#line 4568
            .species = SPECIES_SQUIRTLE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4570
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 4569
            .lvl = 18,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 4571
                MOVE_TACKLE,
                MOVE_TAIL_WHIP,
                MOVE_WITHDRAW,
                MOVE_WATER_GUN,
            },
            },
        },
    },
#line 4576
    [DIFFICULTY_NORMAL][TRAINER_RIVAL_CERULEAN_BULBASAUR] =
    {
#line 4577
        .trainerName = _("TERRY"),
#line 4578
        .trainerClass = TRAINER_CLASS_RIVAL_EARLY,
#line 4579
        .trainerPic = TRAINER_PIC_RIVAL_EARLY,
        .encounterMusic_gender =
#line 4581
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 4582
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 4583
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .partySize = 4,
        .party = (const struct TrainerMon[])
        {
            {
#line 4585
            .species = SPECIES_PIDGEOTTO,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4587
            .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
#line 4586
            .lvl = 17,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 4588
                MOVE_TACKLE,
                MOVE_SAND_ATTACK,
                MOVE_GUST,
                MOVE_QUICK_ATTACK,
            },
            },
            {
#line 4593
            .species = SPECIES_ABRA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4595
            .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
#line 4594
            .lvl = 16,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 4596
                MOVE_TELEPORT,
            },
            },
            {
#line 4598
            .species = SPECIES_RATTATA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4600
            .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
#line 4599
            .lvl = 15,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 4601
                MOVE_TACKLE,
                MOVE_TAIL_WHIP,
                MOVE_QUICK_ATTACK,
            },
            },
            {
#line 4605
            .species = SPECIES_BULBASAUR,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4607
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 4606
            .lvl = 18,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 4608
                MOVE_SLEEP_POWDER,
                MOVE_POISON_POWDER,
                MOVE_VINE_WHIP,
                MOVE_LEECH_SEED,
            },
            },
        },
    },
#line 4613
    [DIFFICULTY_NORMAL][TRAINER_RIVAL_CERULEAN_CHARMANDER] =
    {
#line 4614
        .trainerName = _("TERRY"),
#line 4615
        .trainerClass = TRAINER_CLASS_RIVAL_EARLY,
#line 4616
        .trainerPic = TRAINER_PIC_RIVAL_EARLY,
        .encounterMusic_gender =
#line 4618
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 4619
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 4620
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .partySize = 4,
        .party = (const struct TrainerMon[])
        {
            {
#line 4622
            .species = SPECIES_PIDGEOTTO,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4624
            .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
#line 4623
            .lvl = 17,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 4625
                MOVE_TACKLE,
                MOVE_SAND_ATTACK,
                MOVE_GUST,
                MOVE_QUICK_ATTACK,
            },
            },
            {
#line 4630
            .species = SPECIES_ABRA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4632
            .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
#line 4631
            .lvl = 16,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 4633
                MOVE_TELEPORT,
            },
            },
            {
#line 4635
            .species = SPECIES_RATTATA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4637
            .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
#line 4636
            .lvl = 15,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 4638
                MOVE_TACKLE,
                MOVE_TAIL_WHIP,
                MOVE_QUICK_ATTACK,
            },
            },
            {
#line 4642
            .species = SPECIES_CHARMANDER,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4644
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 4643
            .lvl = 18,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 4645
                MOVE_METAL_CLAW,
                MOVE_EMBER,
                MOVE_GROWL,
                MOVE_SCRATCH,
            },
            },
        },
    },
#line 4650
    [DIFFICULTY_NORMAL][TRAINER_SCIENTIST_TED] =
    {
#line 4651
        .trainerName = _("TED"),
#line 4652
        .trainerClass = TRAINER_CLASS_SCIENTIST,
#line 4653
        .trainerPic = TRAINER_PIC_SCIENTIST,
        .encounterMusic_gender =
#line 4655
            TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
#line 4656
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 4657
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 4659
            .species = SPECIES_ELECTRODE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4661
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 4660
            .lvl = 29,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 4663
            .species = SPECIES_WEEZING,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4665
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 4664
            .lvl = 29,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 4667
    [DIFFICULTY_NORMAL][TRAINER_SCIENTIST_CONNOR] =
    {
#line 4668
        .trainerName = _("CONNOR"),
#line 4669
        .trainerClass = TRAINER_CLASS_SCIENTIST,
#line 4670
        .trainerPic = TRAINER_PIC_SCIENTIST,
        .encounterMusic_gender =
#line 4672
            TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
#line 4673
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 4674
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 4,
        .party = (const struct TrainerMon[])
        {
            {
#line 4676
            .species = SPECIES_GRIMER,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4678
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 4677
            .lvl = 26,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 4679
                MOVE_SCREECH,
                MOVE_MINIMIZE,
                MOVE_SLUDGE,
                MOVE_DISABLE,
            },
            },
            {
#line 4684
            .species = SPECIES_WEEZING,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4686
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 4685
            .lvl = 26,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 4687
                MOVE_SMOKESCREEN,
                MOVE_SLUDGE,
                MOVE_SMOG,
                MOVE_TACKLE,
            },
            },
            {
#line 4692
            .species = SPECIES_KOFFING,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4694
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 4693
            .lvl = 26,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 4695
                MOVE_SMOKESCREEN,
                MOVE_SLUDGE,
                MOVE_SMOG,
                MOVE_SELF_DESTRUCT,
            },
            },
            {
#line 4700
            .species = SPECIES_WEEZING,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4702
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 4701
            .lvl = 26,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 4703
                MOVE_SMOKESCREEN,
                MOVE_SLUDGE,
                MOVE_SMOG,
                MOVE_TACKLE,
            },
            },
        },
    },
#line 4708
    [DIFFICULTY_NORMAL][TRAINER_SCIENTIST_JERRY] =
    {
#line 4709
        .trainerName = _("JERRY"),
#line 4710
        .trainerClass = TRAINER_CLASS_SCIENTIST,
#line 4711
        .trainerPic = TRAINER_PIC_SCIENTIST,
        .encounterMusic_gender =
#line 4713
            TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
#line 4714
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 4715
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 4717
            .species = SPECIES_MAGNEMITE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4719
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 4718
            .lvl = 28,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 4721
            .species = SPECIES_VOLTORB,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4723
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 4722
            .lvl = 28,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 4725
            .species = SPECIES_MAGNETON,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4727
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 4726
            .lvl = 28,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 4729
    [DIFFICULTY_NORMAL][TRAINER_SCIENTIST_JOSE] =
    {
#line 4730
        .trainerName = _("JOSE"),
#line 4731
        .trainerClass = TRAINER_CLASS_SCIENTIST,
#line 4732
        .trainerPic = TRAINER_PIC_SCIENTIST,
        .encounterMusic_gender =
#line 4734
            TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
#line 4735
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 4736
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 4738
            .species = SPECIES_ELECTRODE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4740
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 4739
            .lvl = 29,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 4741
                MOVE_SPARK,
                MOVE_SONIC_BOOM,
                MOVE_SCREECH,
                MOVE_TACKLE,
            },
            },
            {
#line 4746
            .species = SPECIES_WEEZING,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4748
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 4747
            .lvl = 29,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 4749
                MOVE_SMOKESCREEN,
                MOVE_SLUDGE,
                MOVE_SMOG,
                MOVE_TACKLE,
            },
            },
        },
    },
#line 4754
    [DIFFICULTY_NORMAL][TRAINER_SCIENTIST_RODNEY] =
    {
#line 4755
        .trainerName = _("RODNEY"),
#line 4756
        .trainerClass = TRAINER_CLASS_SCIENTIST,
#line 4757
        .trainerPic = TRAINER_PIC_SCIENTIST,
        .encounterMusic_gender =
#line 4759
            TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
#line 4760
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 4761
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 4763
            .species = SPECIES_ELECTRODE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4765
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 4764
            .lvl = 33,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 4767
    [DIFFICULTY_NORMAL][TRAINER_SCIENTIST_BEAU] =
    {
#line 4768
        .trainerName = _("BEAU"),
#line 4769
        .trainerClass = TRAINER_CLASS_SCIENTIST,
#line 4770
        .trainerPic = TRAINER_PIC_SCIENTIST,
        .encounterMusic_gender =
#line 4772
            TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
#line 4773
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 4774
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 4,
        .party = (const struct TrainerMon[])
        {
            {
#line 4776
            .species = SPECIES_MAGNETON,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4778
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 4777
            .lvl = 26,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 4779
                MOVE_SPARK,
                MOVE_THUNDER_WAVE,
                MOVE_SONIC_BOOM,
                MOVE_SUPERSONIC,
            },
            },
            {
#line 4784
            .species = SPECIES_KOFFING,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4786
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 4785
            .lvl = 26,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 4787
                MOVE_SMOKESCREEN,
                MOVE_SLUDGE,
                MOVE_SMOG,
                MOVE_TACKLE,
            },
            },
            {
#line 4792
            .species = SPECIES_WEEZING,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4794
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 4793
            .lvl = 26,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 4795
                MOVE_SMOKESCREEN,
                MOVE_SLUDGE,
                MOVE_SMOG,
                MOVE_TACKLE,
            },
            },
            {
#line 4800
            .species = SPECIES_MAGNEMITE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4802
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 4801
            .lvl = 26,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 4803
                MOVE_SPARK,
                MOVE_THUNDER_WAVE,
                MOVE_SONIC_BOOM,
                MOVE_SUPERSONIC,
            },
            },
        },
    },
#line 4808
    [DIFFICULTY_NORMAL][TRAINER_SCIENTIST_TAYLOR] =
    {
#line 4809
        .trainerName = _("TAYLOR"),
#line 4810
        .trainerClass = TRAINER_CLASS_SCIENTIST,
#line 4811
        .trainerPic = TRAINER_PIC_SCIENTIST,
        .encounterMusic_gender =
#line 4813
            TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
#line 4814
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 4815
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 5,
        .party = (const struct TrainerMon[])
        {
            {
#line 4817
            .species = SPECIES_VOLTORB,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4819
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 4818
            .lvl = 25,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 4820
                MOVE_SPARK,
                MOVE_SONIC_BOOM,
                MOVE_SCREECH,
                MOVE_TACKLE,
            },
            },
            {
#line 4825
            .species = SPECIES_KOFFING,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4827
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 4826
            .lvl = 25,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 4828
                MOVE_SMOKESCREEN,
                MOVE_SLUDGE,
                MOVE_SMOG,
                MOVE_TACKLE,
            },
            },
            {
#line 4833
            .species = SPECIES_MAGNETON,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4835
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 4834
            .lvl = 25,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 4836
                MOVE_THUNDER_WAVE,
                MOVE_SONIC_BOOM,
                MOVE_SUPERSONIC,
                MOVE_THUNDER_SHOCK,
            },
            },
            {
#line 4841
            .species = SPECIES_MAGNEMITE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4843
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 4842
            .lvl = 25,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 4844
                MOVE_THUNDER_WAVE,
                MOVE_SONIC_BOOM,
                MOVE_SUPERSONIC,
                MOVE_THUNDER_SHOCK,
            },
            },
            {
#line 4849
            .species = SPECIES_KOFFING,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4851
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 4850
            .lvl = 25,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 4852
                MOVE_SMOKESCREEN,
                MOVE_SLUDGE,
                MOVE_SMOG,
                MOVE_SELF_DESTRUCT,
            },
            },
        },
    },
#line 4857
    [DIFFICULTY_NORMAL][TRAINER_SCIENTIST_JOSHUA] =
    {
#line 4858
        .trainerName = _("JOSHUA"),
#line 4859
        .trainerClass = TRAINER_CLASS_SCIENTIST,
#line 4860
        .trainerPic = TRAINER_PIC_SCIENTIST,
        .encounterMusic_gender =
#line 4862
            TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
#line 4863
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 4864
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 4866
            .species = SPECIES_ELECTRODE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4868
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 4867
            .lvl = 29,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 4870
            .species = SPECIES_MUK,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4872
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 4871
            .lvl = 29,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 4874
    [DIFFICULTY_NORMAL][TRAINER_SCIENTIST_PARKER] =
    {
#line 4875
        .trainerName = _("PARKER"),
#line 4876
        .trainerClass = TRAINER_CLASS_SCIENTIST,
#line 4877
        .trainerPic = TRAINER_PIC_SCIENTIST,
        .encounterMusic_gender =
#line 4879
            TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
#line 4880
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 4881
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 4883
            .species = SPECIES_GRIMER,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4885
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 4884
            .lvl = 29,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 4887
            .species = SPECIES_ELECTRODE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4889
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 4888
            .lvl = 29,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 4891
    [DIFFICULTY_NORMAL][TRAINER_SCIENTIST_ED] =
    {
#line 4892
        .trainerName = _("ED"),
#line 4893
        .trainerClass = TRAINER_CLASS_SCIENTIST,
#line 4894
        .trainerPic = TRAINER_PIC_SCIENTIST,
        .encounterMusic_gender =
#line 4896
            TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
#line 4897
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 4898
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 4900
            .species = SPECIES_VOLTORB,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4902
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 4901
            .lvl = 28,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 4903
                MOVE_SPARK,
                MOVE_SONIC_BOOM,
                MOVE_SCREECH,
                MOVE_TACKLE,
            },
            },
            {
#line 4908
            .species = SPECIES_KOFFING,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4910
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 4909
            .lvl = 28,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 4911
                MOVE_SMOKESCREEN,
                MOVE_SLUDGE,
                MOVE_TACKLE,
                MOVE_SMOG,
            },
            },
            {
#line 4916
            .species = SPECIES_MAGNETON,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4918
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 4917
            .lvl = 28,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 4919
                MOVE_SPARK,
                MOVE_THUNDER_WAVE,
                MOVE_SONIC_BOOM,
                MOVE_SUPERSONIC,
            },
            },
        },
    },
#line 4924
    [DIFFICULTY_NORMAL][TRAINER_SCIENTIST_TRAVIS] =
    {
#line 4925
        .trainerName = _("TRAVIS"),
#line 4926
        .trainerClass = TRAINER_CLASS_SCIENTIST,
#line 4927
        .trainerPic = TRAINER_PIC_SCIENTIST,
        .encounterMusic_gender =
#line 4929
            TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
#line 4930
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 4931
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 4933
            .species = SPECIES_MAGNEMITE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4935
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 4934
            .lvl = 29,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 4937
            .species = SPECIES_KOFFING,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4939
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 4938
            .lvl = 29,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 4941
    [DIFFICULTY_NORMAL][TRAINER_SCIENTIST_BRAYDON] =
    {
#line 4942
        .trainerName = _("BRAYDON"),
#line 4943
        .trainerClass = TRAINER_CLASS_SCIENTIST,
#line 4944
        .trainerPic = TRAINER_PIC_SCIENTIST,
        .encounterMusic_gender =
#line 4946
            TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
#line 4947
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 4948
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 4950
            .species = SPECIES_MAGNEMITE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4952
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 4951
            .lvl = 33,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 4954
            .species = SPECIES_MAGNETON,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4956
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 4955
            .lvl = 33,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 4958
            .species = SPECIES_VOLTORB,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4960
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 4959
            .lvl = 33,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 4962
    [DIFFICULTY_NORMAL][TRAINER_SCIENTIST_IVAN] =
    {
#line 4963
        .trainerName = _("IVAN"),
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
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 4971
            .species = SPECIES_MAGNEMITE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4973
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 4972
            .lvl = 34,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 4975
            .species = SPECIES_ELECTRODE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4977
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 4976
            .lvl = 34,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 4979
    [DIFFICULTY_NORMAL][TRAINER_BOSS_GIOVANNI] =
    {
#line 4980
        .trainerName = _("GIOVANNI"),
#line 4981
        .trainerClass = TRAINER_CLASS_BOSS,
#line 4982
        .trainerPic = TRAINER_PIC_LEADER_GIOVANNI,
        .encounterMusic_gender =
#line 4984
            TRAINER_ENCOUNTER_MUSIC_AQUA,
#line 4985
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 4986
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 4988
            .species = SPECIES_ONIX,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4990
            .iv = TRAINER_PARTY_IVS(30, 30, 30, 30, 30, 30),
#line 4989
            .lvl = 25,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 4992
            .species = SPECIES_RHYHORN,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4994
            .iv = TRAINER_PARTY_IVS(30, 30, 30, 30, 30, 30),
#line 4993
            .lvl = 24,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 4996
            .species = SPECIES_KANGASKHAN,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4998
            .iv = TRAINER_PARTY_IVS(30, 30, 30, 30, 30, 30),
#line 4997
            .lvl = 29,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 5000
    [DIFFICULTY_NORMAL][TRAINER_BOSS_GIOVANNI_2] =
    {
#line 5001
        .trainerName = _("GIOVANNI"),
#line 5002
        .trainerClass = TRAINER_CLASS_BOSS,
#line 5003
        .trainerPic = TRAINER_PIC_LEADER_GIOVANNI,
        .encounterMusic_gender =
#line 5005
            TRAINER_ENCOUNTER_MUSIC_AQUA,
#line 5006
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 5007
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 4,
        .party = (const struct TrainerMon[])
        {
            {
#line 5009
            .species = SPECIES_NIDORINO,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5011
            .iv = TRAINER_PARTY_IVS(30, 30, 30, 30, 30, 30),
#line 5010
            .lvl = 37,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 5013
            .species = SPECIES_KANGASKHAN,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5015
            .iv = TRAINER_PARTY_IVS(30, 30, 30, 30, 30, 30),
#line 5014
            .lvl = 35,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 5017
            .species = SPECIES_RHYHORN,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5019
            .iv = TRAINER_PARTY_IVS(30, 30, 30, 30, 30, 30),
#line 5018
            .lvl = 37,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 5021
            .species = SPECIES_NIDOQUEEN,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5023
            .iv = TRAINER_PARTY_IVS(30, 30, 30, 30, 30, 30),
#line 5022
            .lvl = 41,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 5025
    [DIFFICULTY_NORMAL][TRAINER_LEADER_GIOVANNI] =
    {
#line 5026
        .trainerName = _("GIOVANNI"),
#line 5027
        .trainerClass = TRAINER_CLASS_LEADER,
#line 5028
        .trainerPic = TRAINER_PIC_LEADER_GIOVANNI,
        .encounterMusic_gender =
#line 5030
            TRAINER_ENCOUNTER_MUSIC_AQUA,
#line 5031
        .items = { ITEM_HYPER_POTION, ITEM_HYPER_POTION, ITEM_FULL_HEAL },
#line 5032
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 5033
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .partySize = 5,
        .party = (const struct TrainerMon[])
        {
            {
#line 5035
            .species = SPECIES_RHYHORN,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5037
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 5036
            .lvl = 45,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 5038
                MOVE_TAKE_DOWN,
                MOVE_ROCK_BLAST,
                MOVE_SCARY_FACE,
                MOVE_EARTHQUAKE,
            },
            },
            {
#line 5043
            .species = SPECIES_DUGTRIO,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5045
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 5044
            .lvl = 42,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 5046
                MOVE_SLASH,
                MOVE_SAND_TOMB,
                MOVE_MUD_SLAP,
                MOVE_EARTHQUAKE,
            },
            },
            {
#line 5051
            .species = SPECIES_NIDOQUEEN,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5053
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 5052
            .lvl = 44,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 5054
                MOVE_BODY_SLAM,
                MOVE_DOUBLE_KICK,
                MOVE_POISON_STING,
                MOVE_EARTHQUAKE,
            },
            },
            {
#line 5059
            .species = SPECIES_NIDOKING,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5061
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 5060
            .lvl = 45,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 5062
                MOVE_THRASH,
                MOVE_DOUBLE_KICK,
                MOVE_POISON_STING,
                MOVE_EARTHQUAKE,
            },
            },
            {
#line 5067
            .species = SPECIES_RHYHORN,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5069
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 5068
            .lvl = 50,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 5070
                MOVE_TAKE_DOWN,
                MOVE_ROCK_BLAST,
                MOVE_SCARY_FACE,
                MOVE_EARTHQUAKE,
            },
            },
        },
    },
#line 5075
    [DIFFICULTY_NORMAL][TRAINER_TEAM_ROCKET_GRUNT] =
    {
#line 5076
        .trainerName = _("GRUNT"),
#line 5077
        .trainerClass = TRAINER_CLASS_TEAM_ROCKET,
#line 5078
        .trainerPic = TRAINER_PIC_ROCKET_GRUNT_M,
        .encounterMusic_gender =
#line 5080
            TRAINER_ENCOUNTER_MUSIC_AQUA,
#line 5081
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 5082
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 5084
            .species = SPECIES_RATTATA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5086
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 5085
            .lvl = 13,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 5088
            .species = SPECIES_ZUBAT,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5090
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 5089
            .lvl = 13,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 5092
    [DIFFICULTY_NORMAL][TRAINER_TEAM_ROCKET_GRUNT_2] =
    {
#line 5093
        .trainerName = _("GRUNT"),
#line 5094
        .trainerClass = TRAINER_CLASS_TEAM_ROCKET,
#line 5095
        .trainerPic = TRAINER_PIC_ROCKET_GRUNT_M,
        .encounterMusic_gender =
#line 5097
            TRAINER_ENCOUNTER_MUSIC_AQUA,
#line 5098
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 5099
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 5101
            .species = SPECIES_SANDSHREW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5103
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 5102
            .lvl = 11,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 5105
            .species = SPECIES_RATTATA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5107
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 5106
            .lvl = 11,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 5109
            .species = SPECIES_ZUBAT,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5111
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 5110
            .lvl = 11,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 5113
    [DIFFICULTY_NORMAL][TRAINER_TEAM_ROCKET_GRUNT_3] =
    {
#line 5114
        .trainerName = _("GRUNT"),
#line 5115
        .trainerClass = TRAINER_CLASS_TEAM_ROCKET,
#line 5116
        .trainerPic = TRAINER_PIC_ROCKET_GRUNT_M,
        .encounterMusic_gender =
#line 5118
            TRAINER_ENCOUNTER_MUSIC_AQUA,
#line 5119
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 5120
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 5122
            .species = SPECIES_ZUBAT,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5124
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 5123
            .lvl = 11,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 5126
            .species = SPECIES_EKANS,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5128
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 5127
            .lvl = 11,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 5130
    [DIFFICULTY_NORMAL][TRAINER_TEAM_ROCKET_GRUNT_4] =
    {
#line 5131
        .trainerName = _("GRUNT"),
#line 5132
        .trainerClass = TRAINER_CLASS_TEAM_ROCKET,
#line 5133
        .trainerPic = TRAINER_PIC_ROCKET_GRUNT_M,
        .encounterMusic_gender =
#line 5135
            TRAINER_ENCOUNTER_MUSIC_AQUA,
#line 5136
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 5137
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 5139
            .species = SPECIES_RATTATA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5141
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 5140
            .lvl = 13,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 5143
            .species = SPECIES_SANDSHREW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5145
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 5144
            .lvl = 13,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 5147
    [DIFFICULTY_NORMAL][TRAINER_TEAM_ROCKET_GRUNT_5] =
    {
#line 5148
        .trainerName = _("GRUNT"),
#line 5149
        .trainerClass = TRAINER_CLASS_TEAM_ROCKET,
#line 5150
        .trainerPic = TRAINER_PIC_ROCKET_GRUNT_M,
        .encounterMusic_gender =
#line 5152
            TRAINER_ENCOUNTER_MUSIC_AQUA,
#line 5153
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 5154
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 5156
            .species = SPECIES_MACHOP,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5158
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 5157
            .lvl = 17,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 5160
            .species = SPECIES_DROWZEE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5162
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 5161
            .lvl = 17,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 5164
    [DIFFICULTY_NORMAL][TRAINER_TEAM_ROCKET_GRUNT_6] =
    {
#line 5165
        .trainerName = _("GRUNT"),
#line 5166
        .trainerClass = TRAINER_CLASS_TEAM_ROCKET,
#line 5167
        .trainerPic = TRAINER_PIC_ROCKET_GRUNT_M,
        .encounterMusic_gender =
#line 5169
            TRAINER_ENCOUNTER_MUSIC_AQUA,
#line 5170
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 5171
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 5173
            .species = SPECIES_EKANS,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5175
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 5174
            .lvl = 15,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 5177
            .species = SPECIES_ZUBAT,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5179
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 5178
            .lvl = 15,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 5181
    [DIFFICULTY_NORMAL][TRAINER_TEAM_ROCKET_GRUNT_7] =
    {
#line 5182
        .trainerName = _("GRUNT"),
#line 5183
        .trainerClass = TRAINER_CLASS_TEAM_ROCKET,
#line 5184
        .trainerPic = TRAINER_PIC_ROCKET_GRUNT_M,
        .encounterMusic_gender =
#line 5186
            TRAINER_ENCOUNTER_MUSIC_AQUA,
#line 5187
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 5188
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 5190
            .species = SPECIES_RATICATE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5192
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 5191
            .lvl = 20,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 5194
            .species = SPECIES_ZUBAT,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5196
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 5195
            .lvl = 20,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 5198
    [DIFFICULTY_NORMAL][TRAINER_TEAM_ROCKET_GRUNT_8] =
    {
#line 5199
        .trainerName = _("GRUNT"),
#line 5200
        .trainerClass = TRAINER_CLASS_TEAM_ROCKET,
#line 5201
        .trainerPic = TRAINER_PIC_ROCKET_GRUNT_M,
        .encounterMusic_gender =
#line 5203
            TRAINER_ENCOUNTER_MUSIC_AQUA,
#line 5204
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 5205
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 5207
            .species = SPECIES_DROWZEE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5209
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 5208
            .lvl = 21,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 5211
            .species = SPECIES_MACHOP,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5213
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 5212
            .lvl = 21,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 5215
    [DIFFICULTY_NORMAL][TRAINER_TEAM_ROCKET_GRUNT_9] =
    {
#line 5216
        .trainerName = _("GRUNT"),
#line 5217
        .trainerClass = TRAINER_CLASS_TEAM_ROCKET,
#line 5218
        .trainerPic = TRAINER_PIC_ROCKET_GRUNT_M,
        .encounterMusic_gender =
#line 5220
            TRAINER_ENCOUNTER_MUSIC_AQUA,
#line 5221
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 5222
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 5224
            .species = SPECIES_RATICATE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5226
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 5225
            .lvl = 21,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 5228
            .species = SPECIES_RATICATE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5230
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 5229
            .lvl = 21,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 5232
    [DIFFICULTY_NORMAL][TRAINER_TEAM_ROCKET_GRUNT_10] =
    {
#line 5233
        .trainerName = _("GRUNT"),
#line 5234
        .trainerClass = TRAINER_CLASS_TEAM_ROCKET,
#line 5235
        .trainerPic = TRAINER_PIC_ROCKET_GRUNT_M,
        .encounterMusic_gender =
#line 5237
            TRAINER_ENCOUNTER_MUSIC_AQUA,
#line 5238
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 5239
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 5241
            .species = SPECIES_GRIMER,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5243
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 5242
            .lvl = 20,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 5244
                MOVE_MINIMIZE,
                MOVE_SLUDGE,
                MOVE_DISABLE,
                MOVE_HARDEN,
            },
            },
            {
#line 5249
            .species = SPECIES_KOFFING,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5251
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 5250
            .lvl = 20,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 5252
                MOVE_SMOG,
                MOVE_TACKLE,
                MOVE_POISON_GAS,
            },
            },
            {
#line 5256
            .species = SPECIES_KOFFING,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5258
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 5257
            .lvl = 20,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 5259
                MOVE_SMOG,
                MOVE_TACKLE,
                MOVE_POISON_GAS,
            },
            },
        },
    },
#line 5263
    [DIFFICULTY_NORMAL][TRAINER_TEAM_ROCKET_GRUNT_11] =
    {
#line 5264
        .trainerName = _("GRUNT"),
#line 5265
        .trainerClass = TRAINER_CLASS_TEAM_ROCKET,
#line 5266
        .trainerPic = TRAINER_PIC_ROCKET_GRUNT_M,
        .encounterMusic_gender =
#line 5268
            TRAINER_ENCOUNTER_MUSIC_AQUA,
#line 5269
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 5270
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 4,
        .party = (const struct TrainerMon[])
        {
            {
#line 5272
            .species = SPECIES_RATTATA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5274
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 5273
            .lvl = 19,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 5276
            .species = SPECIES_RATICATE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5278
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 5277
            .lvl = 19,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 5280
            .species = SPECIES_RATICATE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5282
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 5281
            .lvl = 19,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 5284
            .species = SPECIES_RATTATA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5286
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 5285
            .lvl = 19,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 5288
    [DIFFICULTY_NORMAL][TRAINER_TEAM_ROCKET_GRUNT_12] =
    {
#line 5289
        .trainerName = _("GRUNT"),
#line 5290
        .trainerClass = TRAINER_CLASS_TEAM_ROCKET,
#line 5291
        .trainerPic = TRAINER_PIC_ROCKET_GRUNT_M,
        .encounterMusic_gender =
#line 5293
            TRAINER_ENCOUNTER_MUSIC_AQUA,
#line 5294
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 5295
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 5297
            .species = SPECIES_GRIMER,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5299
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 5298
            .lvl = 22,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 5300
                MOVE_MINIMIZE,
                MOVE_SLUDGE,
                MOVE_DISABLE,
                MOVE_HARDEN,
            },
            },
            {
#line 5305
            .species = SPECIES_KOFFING,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5307
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 5306
            .lvl = 22,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 5308
                MOVE_SLUDGE,
                MOVE_SMOG,
                MOVE_TACKLE,
                MOVE_POISON_GAS,
            },
            },
        },
    },
#line 5313
    [DIFFICULTY_NORMAL][TRAINER_TEAM_ROCKET_GRUNT_13] =
    {
#line 5314
        .trainerName = _("GRUNT"),
#line 5315
        .trainerClass = TRAINER_CLASS_TEAM_ROCKET,
#line 5316
        .trainerPic = TRAINER_PIC_ROCKET_GRUNT_M,
        .encounterMusic_gender =
#line 5318
            TRAINER_ENCOUNTER_MUSIC_AQUA,
#line 5319
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 5320
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 5,
        .party = (const struct TrainerMon[])
        {
            {
#line 5322
            .species = SPECIES_ZUBAT,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5324
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 5323
            .lvl = 17,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 5325
                MOVE_BITE,
                MOVE_ASTONISH,
                MOVE_SUPERSONIC,
                MOVE_LEECH_LIFE,
            },
            },
            {
#line 5330
            .species = SPECIES_KOFFING,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5332
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 5331
            .lvl = 17,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 5333
                MOVE_SMOG,
                MOVE_TACKLE,
                MOVE_POISON_GAS,
            },
            },
            {
#line 5337
            .species = SPECIES_GRIMER,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5339
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 5338
            .lvl = 17,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 5340
                MOVE_SLUDGE,
                MOVE_DISABLE,
                MOVE_HARDEN,
                MOVE_POUND,
            },
            },
            {
#line 5345
            .species = SPECIES_ZUBAT,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5347
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 5346
            .lvl = 17,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 5348
                MOVE_BITE,
                MOVE_ASTONISH,
                MOVE_SUPERSONIC,
                MOVE_LEECH_LIFE,
            },
            },
            {
#line 5353
            .species = SPECIES_RATICATE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5355
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 5354
            .lvl = 17,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 5356
                MOVE_HYPER_FANG,
                MOVE_QUICK_ATTACK,
                MOVE_TAIL_WHIP,
                MOVE_TACKLE,
            },
            },
        },
    },
#line 5361
    [DIFFICULTY_NORMAL][TRAINER_TEAM_ROCKET_GRUNT_14] =
    {
#line 5362
        .trainerName = _("GRUNT"),
#line 5363
        .trainerClass = TRAINER_CLASS_TEAM_ROCKET,
#line 5364
        .trainerPic = TRAINER_PIC_ROCKET_GRUNT_M,
        .encounterMusic_gender =
#line 5366
            TRAINER_ENCOUNTER_MUSIC_AQUA,
#line 5367
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 5368
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 5370
            .species = SPECIES_RATTATA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5372
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 5371
            .lvl = 20,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 5374
            .species = SPECIES_RATICATE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5376
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 5375
            .lvl = 20,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 5378
            .species = SPECIES_DROWZEE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5380
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 5379
            .lvl = 20,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 5382
    [DIFFICULTY_NORMAL][TRAINER_TEAM_ROCKET_GRUNT_15] =
    {
#line 5383
        .trainerName = _("GRUNT"),
#line 5384
        .trainerClass = TRAINER_CLASS_TEAM_ROCKET,
#line 5385
        .trainerPic = TRAINER_PIC_ROCKET_GRUNT_M,
        .encounterMusic_gender =
#line 5387
            TRAINER_ENCOUNTER_MUSIC_AQUA,
#line 5388
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 5389
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 5391
            .species = SPECIES_MACHOP,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5393
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 5392
            .lvl = 21,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 5395
            .species = SPECIES_MACHOP,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5397
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 5396
            .lvl = 21,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 5399
    [DIFFICULTY_NORMAL][TRAINER_TEAM_ROCKET_GRUNT_16] =
    {
#line 5400
        .trainerName = _("GRUNT"),
#line 5401
        .trainerClass = TRAINER_CLASS_TEAM_ROCKET,
#line 5402
        .trainerPic = TRAINER_PIC_ROCKET_GRUNT_M,
        .encounterMusic_gender =
#line 5404
            TRAINER_ENCOUNTER_MUSIC_AQUA,
#line 5405
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 5406
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 5408
            .species = SPECIES_SANDSHREW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5410
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 5409
            .lvl = 23,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 5412
            .species = SPECIES_EKANS,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5414
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 5413
            .lvl = 23,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 5416
            .species = SPECIES_SANDSLASH,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5418
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 5417
            .lvl = 23,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 5420
    [DIFFICULTY_NORMAL][TRAINER_TEAM_ROCKET_GRUNT_17] =
    {
#line 5421
        .trainerName = _("GRUNT"),
#line 5422
        .trainerClass = TRAINER_CLASS_TEAM_ROCKET,
#line 5423
        .trainerPic = TRAINER_PIC_ROCKET_GRUNT_M,
        .encounterMusic_gender =
#line 5425
            TRAINER_ENCOUNTER_MUSIC_AQUA,
#line 5426
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 5427
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 5429
            .species = SPECIES_EKANS,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5431
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 5430
            .lvl = 23,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 5433
            .species = SPECIES_SANDSHREW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5435
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 5434
            .lvl = 23,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 5437
            .species = SPECIES_ARBOK,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5439
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 5438
            .lvl = 23,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 5441
    [DIFFICULTY_NORMAL][TRAINER_TEAM_ROCKET_GRUNT_18] =
    {
#line 5442
        .trainerName = _("GRUNT"),
#line 5443
        .trainerClass = TRAINER_CLASS_TEAM_ROCKET,
#line 5444
        .trainerPic = TRAINER_PIC_ROCKET_GRUNT_M,
        .encounterMusic_gender =
#line 5446
            TRAINER_ENCOUNTER_MUSIC_AQUA,
#line 5447
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 5448
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 5450
            .species = SPECIES_KOFFING,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5452
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 5451
            .lvl = 21,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 5454
            .species = SPECIES_ZUBAT,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5456
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 5455
            .lvl = 21,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 5458
    [DIFFICULTY_NORMAL][TRAINER_TEAM_ROCKET_GRUNT_19] =
    {
#line 5459
        .trainerName = _("GRUNT"),
#line 5460
        .trainerClass = TRAINER_CLASS_TEAM_ROCKET,
#line 5461
        .trainerPic = TRAINER_PIC_ROCKET_GRUNT_M,
        .encounterMusic_gender =
#line 5463
            TRAINER_ENCOUNTER_MUSIC_AQUA,
#line 5464
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 5465
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 5467
            .species = SPECIES_ZUBAT,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5469
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 5468
            .lvl = 25,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 5471
            .species = SPECIES_ZUBAT,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5473
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 5472
            .lvl = 25,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 5475
            .species = SPECIES_GOLBAT,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5477
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 5476
            .lvl = 25,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 5479
    [DIFFICULTY_NORMAL][TRAINER_TEAM_ROCKET_GRUNT_20] =
    {
#line 5480
        .trainerName = _("GRUNT"),
#line 5481
        .trainerClass = TRAINER_CLASS_TEAM_ROCKET,
#line 5482
        .trainerPic = TRAINER_PIC_ROCKET_GRUNT_M,
        .encounterMusic_gender =
#line 5484
            TRAINER_ENCOUNTER_MUSIC_AQUA,
#line 5485
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 5486
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 5488
            .species = SPECIES_KOFFING,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5490
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 5489
            .lvl = 26,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 5492
            .species = SPECIES_DROWZEE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5494
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 5493
            .lvl = 26,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 5496
    [DIFFICULTY_NORMAL][TRAINER_TEAM_ROCKET_GRUNT_21] =
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
        .partySize = 4,
        .party = (const struct TrainerMon[])
        {
            {
#line 5505
            .species = SPECIES_ZUBAT,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5507
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 5506
            .lvl = 23,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 5509
            .species = SPECIES_RATTATA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5511
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 5510
            .lvl = 23,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 5513
            .species = SPECIES_RATICATE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5515
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 5514
            .lvl = 23,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 5517
            .species = SPECIES_ZUBAT,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5519
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 5518
            .lvl = 23,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 5521
    [DIFFICULTY_NORMAL][TRAINER_TEAM_ROCKET_GRUNT_22] =
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
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 5530
            .species = SPECIES_DROWZEE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5532
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 5531
            .lvl = 26,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 5534
            .species = SPECIES_KOFFING,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5536
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 5535
            .lvl = 26,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 5538
    [DIFFICULTY_NORMAL][TRAINER_TEAM_ROCKET_GRUNT_23] =
    {
#line 5539
        .trainerName = _("GRUNT"),
#line 5540
        .trainerClass = TRAINER_CLASS_TEAM_ROCKET,
#line 5541
        .trainerPic = TRAINER_PIC_ROCKET_GRUNT_M,
        .encounterMusic_gender =
#line 5543
            TRAINER_ENCOUNTER_MUSIC_AQUA,
#line 5544
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 5545
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 5547
            .species = SPECIES_CUBONE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5549
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 5548
            .lvl = 29,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 5551
            .species = SPECIES_ZUBAT,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5553
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 5552
            .lvl = 29,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 5555
    [DIFFICULTY_NORMAL][TRAINER_TEAM_ROCKET_GRUNT_24] =
    {
#line 5556
        .trainerName = _("GRUNT"),
#line 5557
        .trainerClass = TRAINER_CLASS_TEAM_ROCKET,
#line 5558
        .trainerPic = TRAINER_PIC_ROCKET_GRUNT_M,
        .encounterMusic_gender =
#line 5560
            TRAINER_ENCOUNTER_MUSIC_AQUA,
#line 5561
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 5562
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 5,
        .party = (const struct TrainerMon[])
        {
            {
#line 5564
            .species = SPECIES_GOLBAT,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5566
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 5565
            .lvl = 25,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 5568
            .species = SPECIES_ZUBAT,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5570
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 5569
            .lvl = 25,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 5572
            .species = SPECIES_ZUBAT,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5574
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 5573
            .lvl = 25,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 5576
            .species = SPECIES_RATICATE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5578
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 5577
            .lvl = 25,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 5580
            .species = SPECIES_ZUBAT,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5582
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 5581
            .lvl = 25,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 5584
    [DIFFICULTY_NORMAL][TRAINER_TEAM_ROCKET_GRUNT_25] =
    {
#line 5585
        .trainerName = _("GRUNT"),
#line 5586
        .trainerClass = TRAINER_CLASS_TEAM_ROCKET,
#line 5587
        .trainerPic = TRAINER_PIC_ROCKET_GRUNT_M,
        .encounterMusic_gender =
#line 5589
            TRAINER_ENCOUNTER_MUSIC_AQUA,
#line 5590
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 5591
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 5593
            .species = SPECIES_RATICATE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5595
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 5594
            .lvl = 28,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 5597
            .species = SPECIES_HYPNO,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5599
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 5598
            .lvl = 28,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 5601
            .species = SPECIES_RATICATE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5603
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 5602
            .lvl = 28,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 5605
    [DIFFICULTY_NORMAL][TRAINER_TEAM_ROCKET_GRUNT_26] =
    {
#line 5606
        .trainerName = _("GRUNT"),
#line 5607
        .trainerClass = TRAINER_CLASS_TEAM_ROCKET,
#line 5608
        .trainerPic = TRAINER_PIC_ROCKET_GRUNT_M,
        .encounterMusic_gender =
#line 5610
            TRAINER_ENCOUNTER_MUSIC_AQUA,
#line 5611
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 5612
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 5614
            .species = SPECIES_MACHOP,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5616
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 5615
            .lvl = 29,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 5618
            .species = SPECIES_DROWZEE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5620
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 5619
            .lvl = 29,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 5622
    [DIFFICULTY_NORMAL][TRAINER_TEAM_ROCKET_GRUNT_27] =
    {
#line 5623
        .trainerName = _("GRUNT"),
#line 5624
        .trainerClass = TRAINER_CLASS_TEAM_ROCKET,
#line 5625
        .trainerPic = TRAINER_PIC_ROCKET_GRUNT_M,
        .encounterMusic_gender =
#line 5627
            TRAINER_ENCOUNTER_MUSIC_AQUA,
#line 5628
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 5629
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 5631
            .species = SPECIES_EKANS,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5633
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 5632
            .lvl = 28,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 5635
            .species = SPECIES_ZUBAT,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5637
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 5636
            .lvl = 28,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 5639
            .species = SPECIES_CUBONE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5641
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 5640
            .lvl = 28,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 5643
    [DIFFICULTY_NORMAL][TRAINER_TEAM_ROCKET_GRUNT_28] =
    {
#line 5644
        .trainerName = _("GRUNT"),
#line 5645
        .trainerClass = TRAINER_CLASS_TEAM_ROCKET,
#line 5646
        .trainerPic = TRAINER_PIC_ROCKET_GRUNT_M,
        .encounterMusic_gender =
#line 5648
            TRAINER_ENCOUNTER_MUSIC_AQUA,
#line 5649
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 5650
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 5652
            .species = SPECIES_ARBOK,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5654
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 5653
            .lvl = 33,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 5656
    [DIFFICULTY_NORMAL][TRAINER_TEAM_ROCKET_GRUNT_29] =
    {
#line 5657
        .trainerName = _("GRUNT"),
#line 5658
        .trainerClass = TRAINER_CLASS_TEAM_ROCKET,
#line 5659
        .trainerPic = TRAINER_PIC_ROCKET_GRUNT_M,
        .encounterMusic_gender =
#line 5661
            TRAINER_ENCOUNTER_MUSIC_AQUA,
#line 5662
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 5663
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 5665
            .species = SPECIES_HYPNO,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5667
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 5666
            .lvl = 33,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 5669
    [DIFFICULTY_NORMAL][TRAINER_TEAM_ROCKET_GRUNT_30] =
    {
#line 5670
        .trainerName = _("GRUNT"),
#line 5671
        .trainerClass = TRAINER_CLASS_TEAM_ROCKET,
#line 5672
        .trainerPic = TRAINER_PIC_ROCKET_GRUNT_M,
        .encounterMusic_gender =
#line 5674
            TRAINER_ENCOUNTER_MUSIC_AQUA,
#line 5675
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 5676
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 5678
            .species = SPECIES_MACHOP,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5680
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 5679
            .lvl = 29,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 5682
            .species = SPECIES_MACHOKE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5684
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 5683
            .lvl = 29,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 5686
    [DIFFICULTY_NORMAL][TRAINER_TEAM_ROCKET_GRUNT_31] =
    {
#line 5687
        .trainerName = _("GRUNT"),
#line 5688
        .trainerClass = TRAINER_CLASS_TEAM_ROCKET,
#line 5689
        .trainerPic = TRAINER_PIC_ROCKET_GRUNT_M,
        .encounterMusic_gender =
#line 5691
            TRAINER_ENCOUNTER_MUSIC_AQUA,
#line 5692
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 5693
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 5695
            .species = SPECIES_ZUBAT,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5697
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 5696
            .lvl = 28,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 5699
            .species = SPECIES_ZUBAT,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5701
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 5700
            .lvl = 28,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 5703
            .species = SPECIES_GOLBAT,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5705
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 5704
            .lvl = 28,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 5707
    [DIFFICULTY_NORMAL][TRAINER_TEAM_ROCKET_GRUNT_32] =
    {
#line 5708
        .trainerName = _("GRUNT"),
#line 5709
        .trainerClass = TRAINER_CLASS_TEAM_ROCKET,
#line 5710
        .trainerPic = TRAINER_PIC_ROCKET_GRUNT_M,
        .encounterMusic_gender =
#line 5712
            TRAINER_ENCOUNTER_MUSIC_AQUA,
#line 5713
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 5714
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 4,
        .party = (const struct TrainerMon[])
        {
            {
#line 5716
            .species = SPECIES_RATICATE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5718
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 5717
            .lvl = 26,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 5719
                MOVE_SCARY_FACE,
                MOVE_HYPER_FANG,
                MOVE_QUICK_ATTACK,
                MOVE_TAIL_WHIP,
            },
            },
            {
#line 5724
            .species = SPECIES_ARBOK,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5726
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 5725
            .lvl = 26,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 5727
                MOVE_GLARE,
                MOVE_BITE,
                MOVE_POISON_STING,
                MOVE_LEER,
            },
            },
            {
#line 5732
            .species = SPECIES_KOFFING,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5734
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 5733
            .lvl = 26,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 5735
                MOVE_SMOKESCREEN,
                MOVE_SLUDGE,
                MOVE_SMOG,
                MOVE_TACKLE,
            },
            },
            {
#line 5740
            .species = SPECIES_GOLBAT,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5742
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 5741
            .lvl = 26,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 5743
                MOVE_WING_ATTACK,
                MOVE_BITE,
                MOVE_ASTONISH,
                MOVE_SUPERSONIC,
            },
            },
        },
    },
#line 5748
    [DIFFICULTY_NORMAL][TRAINER_TEAM_ROCKET_GRUNT_33] =
    {
#line 5749
        .trainerName = _("GRUNT"),
#line 5750
        .trainerClass = TRAINER_CLASS_TEAM_ROCKET,
#line 5751
        .trainerPic = TRAINER_PIC_ROCKET_GRUNT_M,
        .encounterMusic_gender =
#line 5753
            TRAINER_ENCOUNTER_MUSIC_AQUA,
#line 5754
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 5755
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 5757
            .species = SPECIES_CUBONE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5759
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 5758
            .lvl = 29,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 5761
            .species = SPECIES_CUBONE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5763
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 5762
            .lvl = 29,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 5765
    [DIFFICULTY_NORMAL][TRAINER_TEAM_ROCKET_GRUNT_34] =
    {
#line 5766
        .trainerName = _("GRUNT"),
#line 5767
        .trainerClass = TRAINER_CLASS_TEAM_ROCKET,
#line 5768
        .trainerPic = TRAINER_PIC_ROCKET_GRUNT_M,
        .encounterMusic_gender =
#line 5770
            TRAINER_ENCOUNTER_MUSIC_AQUA,
#line 5771
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 5772
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 5774
            .species = SPECIES_SANDSHREW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5776
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 5775
            .lvl = 29,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 5778
            .species = SPECIES_SANDSLASH,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5780
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 5779
            .lvl = 29,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 5782
    [DIFFICULTY_NORMAL][TRAINER_TEAM_ROCKET_GRUNT_35] =
    {
#line 5783
        .trainerName = _("GRUNT"),
#line 5784
        .trainerClass = TRAINER_CLASS_TEAM_ROCKET,
#line 5785
        .trainerPic = TRAINER_PIC_ROCKET_GRUNT_M,
        .encounterMusic_gender =
#line 5787
            TRAINER_ENCOUNTER_MUSIC_AQUA,
#line 5788
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 5789
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 4,
        .party = (const struct TrainerMon[])
        {
            {
#line 5791
            .species = SPECIES_RATICATE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5793
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 5792
            .lvl = 26,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 5795
            .species = SPECIES_ZUBAT,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5797
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 5796
            .lvl = 26,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 5799
            .species = SPECIES_GOLBAT,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5801
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 5800
            .lvl = 26,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 5803
            .species = SPECIES_RATTATA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5805
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 5804
            .lvl = 26,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 5807
    [DIFFICULTY_NORMAL][TRAINER_TEAM_ROCKET_GRUNT_36] =
    {
#line 5808
        .trainerName = _("GRUNT"),
#line 5809
        .trainerClass = TRAINER_CLASS_TEAM_ROCKET,
#line 5810
        .trainerPic = TRAINER_PIC_ROCKET_GRUNT_M,
        .encounterMusic_gender =
#line 5812
            TRAINER_ENCOUNTER_MUSIC_AQUA,
#line 5813
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 5814
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 5816
            .species = SPECIES_WEEZING,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5818
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 5817
            .lvl = 28,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 5820
            .species = SPECIES_GOLBAT,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5822
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 5821
            .lvl = 28,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 5824
            .species = SPECIES_KOFFING,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5826
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 5825
            .lvl = 28,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 5828
    [DIFFICULTY_NORMAL][TRAINER_TEAM_ROCKET_GRUNT_37] =
    {
#line 5829
        .trainerName = _("GRUNT"),
#line 5830
        .trainerClass = TRAINER_CLASS_TEAM_ROCKET,
#line 5831
        .trainerPic = TRAINER_PIC_ROCKET_GRUNT_M,
        .encounterMusic_gender =
#line 5833
            TRAINER_ENCOUNTER_MUSIC_AQUA,
#line 5834
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 5835
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 5837
            .species = SPECIES_DROWZEE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5839
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 5838
            .lvl = 28,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 5841
            .species = SPECIES_GRIMER,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5843
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 5842
            .lvl = 28,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 5845
            .species = SPECIES_MACHOP,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5847
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 5846
            .lvl = 28,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 5849
    [DIFFICULTY_NORMAL][TRAINER_TEAM_ROCKET_GRUNT_38] =
    {
#line 5850
        .trainerName = _("GRUNT"),
#line 5851
        .trainerClass = TRAINER_CLASS_TEAM_ROCKET,
#line 5852
        .trainerPic = TRAINER_PIC_ROCKET_GRUNT_M,
        .encounterMusic_gender =
#line 5854
            TRAINER_ENCOUNTER_MUSIC_AQUA,
#line 5855
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 5856
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 5858
            .species = SPECIES_GOLBAT,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5860
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 5859
            .lvl = 28,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 5862
            .species = SPECIES_DROWZEE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5864
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 5863
            .lvl = 28,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 5866
            .species = SPECIES_HYPNO,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5868
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 5867
            .lvl = 28,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 5870
    [DIFFICULTY_NORMAL][TRAINER_TEAM_ROCKET_GRUNT_39] =
    {
#line 5871
        .trainerName = _("GRUNT"),
#line 5872
        .trainerClass = TRAINER_CLASS_TEAM_ROCKET,
#line 5873
        .trainerPic = TRAINER_PIC_ROCKET_GRUNT_M,
        .encounterMusic_gender =
#line 5875
            TRAINER_ENCOUNTER_MUSIC_AQUA,
#line 5876
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 5877
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 5879
            .species = SPECIES_MACHOKE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5881
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 5880
            .lvl = 33,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 5883
    [DIFFICULTY_NORMAL][TRAINER_TEAM_ROCKET_GRUNT_40] =
    {
#line 5884
        .trainerName = _("GRUNT"),
#line 5885
        .trainerClass = TRAINER_CLASS_TEAM_ROCKET,
#line 5886
        .trainerPic = TRAINER_PIC_ROCKET_GRUNT_M,
        .encounterMusic_gender =
#line 5888
            TRAINER_ENCOUNTER_MUSIC_AQUA,
#line 5889
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 5890
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 5,
        .party = (const struct TrainerMon[])
        {
            {
#line 5892
            .species = SPECIES_RATTATA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5894
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 5893
            .lvl = 25,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 5896
            .species = SPECIES_RATTATA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5898
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 5897
            .lvl = 25,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 5900
            .species = SPECIES_ZUBAT,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5902
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 5901
            .lvl = 25,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 5904
            .species = SPECIES_RATTATA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5906
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 5905
            .lvl = 25,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 5908
            .species = SPECIES_EKANS,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5910
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 5909
            .lvl = 25,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 5912
    [DIFFICULTY_NORMAL][TRAINER_TEAM_ROCKET_GRUNT_41] =
    {
#line 5913
        .trainerName = _("GRUNT"),
#line 5914
        .trainerClass = TRAINER_CLASS_TEAM_ROCKET,
#line 5915
        .trainerPic = TRAINER_PIC_ROCKET_GRUNT_M,
        .encounterMusic_gender =
#line 5917
            TRAINER_ENCOUNTER_MUSIC_AQUA,
#line 5918
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 5919
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 5921
            .species = SPECIES_CUBONE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5923
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 5922
            .lvl = 32,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 5925
            .species = SPECIES_DROWZEE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5927
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 5926
            .lvl = 32,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 5929
            .species = SPECIES_MAROWAK,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5931
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 5930
            .lvl = 32,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 5933
    [DIFFICULTY_NORMAL][TRAINER_COOLTRAINER_SAMUEL] =
    {
#line 5934
        .trainerName = _("SAMUEL"),
#line 5935
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
#line 5936
        .trainerPic = TRAINER_PIC_COOLTRAINER_M,
        .encounterMusic_gender =
#line 5938
            TRAINER_ENCOUNTER_MUSIC_COOL,
#line 5939
        .items = { ITEM_SUPER_POTION },
#line 5940
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 5941
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .partySize = 5,
        .party = (const struct TrainerMon[])
        {
            {
#line 5943
            .species = SPECIES_SANDSLASH,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5945
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 5944
            .lvl = 37,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 5946
                MOVE_SLASH,
                MOVE_SWIFT,
                MOVE_SAND_ATTACK,
                MOVE_POISON_STING,
            },
            },
            {
#line 5951
            .species = SPECIES_SANDSLASH,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5953
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 5952
            .lvl = 37,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 5954
                MOVE_SLASH,
                MOVE_SWIFT,
                MOVE_SAND_ATTACK,
                MOVE_POISON_STING,
            },
            },
            {
#line 5959
            .species = SPECIES_RHYHORN,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5961
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 5960
            .lvl = 38,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 5962
                MOVE_TAKE_DOWN,
                MOVE_ROCK_BLAST,
                MOVE_FURY_ATTACK,
                MOVE_SCARY_FACE,
            },
            },
            {
#line 5967
            .species = SPECIES_NIDORINO,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5969
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 5968
            .lvl = 39,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 5970
                MOVE_FURY_ATTACK,
                MOVE_HORN_ATTACK,
                MOVE_POISON_STING,
                MOVE_DOUBLE_KICK,
            },
            },
            {
#line 5975
            .species = SPECIES_NIDOKING,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5977
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 5976
            .lvl = 39,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 5978
                MOVE_THRASH,
                MOVE_DOUBLE_KICK,
                MOVE_POISON_STING,
                MOVE_FOCUS_ENERGY,
            },
            },
        },
    },
#line 5983
    [DIFFICULTY_NORMAL][TRAINER_COOLTRAINER_GEORGE] =
    {
#line 5984
        .trainerName = _("GEORGE"),
#line 5985
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
#line 5986
        .trainerPic = TRAINER_PIC_COOLTRAINER_M,
        .encounterMusic_gender =
#line 5988
            TRAINER_ENCOUNTER_MUSIC_COOL,
#line 5989
        .items = { ITEM_HYPER_POTION },
#line 5990
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 5991
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .partySize = 5,
        .party = (const struct TrainerMon[])
        {
            {
#line 5993
            .species = SPECIES_EXEGGUTOR,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5995
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 5994
            .lvl = 42,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 5996
                MOVE_EGG_BOMB,
                MOVE_CONFUSION,
                MOVE_STUN_SPORE,
                MOVE_SLEEP_POWDER,
            },
            },
            {
#line 6001
            .species = SPECIES_SANDSLASH,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6003
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 6002
            .lvl = 42,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 6004
                MOVE_FURY_SWIPES,
                MOVE_SWIFT,
                MOVE_POISON_STING,
                MOVE_SAND_ATTACK,
            },
            },
            {
#line 6009
            .species = SPECIES_CLOYSTER,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6011
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 6010
            .lvl = 42,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 6012
                MOVE_SPIKE_CANNON,
                MOVE_SPIKES,
                MOVE_AURORA_BEAM,
                MOVE_SUPERSONIC,
            },
            },
            {
#line 6017
            .species = SPECIES_ELECTRODE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6019
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 6018
            .lvl = 42,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 6020
                MOVE_SPARK,
                MOVE_SONIC_BOOM,
                MOVE_SCREECH,
                MOVE_LIGHT_SCREEN,
            },
            },
            {
#line 6025
            .species = SPECIES_ARCANINE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6027
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 6026
            .lvl = 42,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 6028
                MOVE_FLAME_WHEEL,
                MOVE_ROAR,
                MOVE_BITE,
                MOVE_TAKE_DOWN,
            },
            },
        },
    },
#line 6033
    [DIFFICULTY_NORMAL][TRAINER_COOLTRAINER_COLBY] =
    {
#line 6034
        .trainerName = _("COLBY"),
#line 6035
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
#line 6036
        .trainerPic = TRAINER_PIC_COOLTRAINER_M,
        .encounterMusic_gender =
#line 6038
            TRAINER_ENCOUNTER_MUSIC_COOL,
#line 6039
        .items = { ITEM_HYPER_POTION },
#line 6040
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 6041
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .partySize = 5,
        .party = (const struct TrainerMon[])
        {
            {
#line 6043
            .species = SPECIES_KINGLER,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6045
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 6044
            .lvl = 41,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 6046
                MOVE_GUILLOTINE,
                MOVE_STOMP,
                MOVE_MUD_SHOT,
                MOVE_BUBBLE,
            },
            },
            {
#line 6051
            .species = SPECIES_POLIWHIRL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6053
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 6052
            .lvl = 42,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 6054
                MOVE_BODY_SLAM,
                MOVE_DOUBLE_SLAP,
                MOVE_WATER_GUN,
                MOVE_HYPNOSIS,
            },
            },
            {
#line 6059
            .species = SPECIES_TENTACRUEL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6061
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 6060
            .lvl = 42,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 6062
                MOVE_BARRIER,
                MOVE_WRAP,
                MOVE_BUBBLE_BEAM,
                MOVE_ACID,
            },
            },
            {
#line 6067
            .species = SPECIES_SEADRA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6069
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 6068
            .lvl = 42,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 6070
                MOVE_WATER_GUN,
                MOVE_SMOKESCREEN,
                MOVE_TWISTER,
                MOVE_LEER,
            },
            },
            {
#line 6075
            .species = SPECIES_BLASTOISE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6077
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 6076
            .lvl = 43,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 6078
                MOVE_WATER_GUN,
                MOVE_BITE,
                MOVE_RAPID_SPIN,
                MOVE_RAIN_DANCE,
            },
            },
        },
    },
#line 6083
    [DIFFICULTY_NORMAL][TRAINER_COOLTRAINER_PAUL] =
    {
#line 6084
        .trainerName = _("PAUL"),
#line 6085
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
#line 6086
        .trainerPic = TRAINER_PIC_COOLTRAINER_M,
        .encounterMusic_gender =
#line 6088
            TRAINER_ENCOUNTER_MUSIC_COOL,
#line 6089
        .items = { ITEM_FULL_RESTORE },
#line 6090
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 6091
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .partySize = 5,
        .party = (const struct TrainerMon[])
        {
            {
#line 6093
            .species = SPECIES_SLOWPOKE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6095
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 6094
            .lvl = 42,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 6096
                MOVE_HEADBUTT,
                MOVE_CONFUSION,
                MOVE_WATER_GUN,
                MOVE_DISABLE,
            },
            },
            {
#line 6101
            .species = SPECIES_SHELLDER,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6103
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 6102
            .lvl = 42,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 6104
                MOVE_AURORA_BEAM,
                MOVE_CLAMP,
                MOVE_SUPERSONIC,
                MOVE_LEER,
            },
            },
            {
#line 6109
            .species = SPECIES_KINGLER,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6111
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 6110
            .lvl = 42,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 6112
                MOVE_GUILLOTINE,
                MOVE_STOMP,
                MOVE_MUD_SHOT,
                MOVE_BUBBLE,
            },
            },
            {
#line 6117
            .species = SPECIES_STARMIE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6119
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 6118
            .lvl = 42,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 6120
                MOVE_BUBBLE_BEAM,
                MOVE_SWIFT,
                MOVE_RECOVER,
                MOVE_RAPID_SPIN,
            },
            },
            {
#line 6125
            .species = SPECIES_GOLDUCK,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6127
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 6126
            .lvl = 42,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 6128
                MOVE_CONFUSION,
                MOVE_SCRATCH,
                MOVE_SCREECH,
                MOVE_DISABLE,
            },
            },
        },
    },
#line 6133
    [DIFFICULTY_NORMAL][TRAINER_COOLTRAINER_ROLANDO] =
    {
#line 6134
        .trainerName = _("ROLANDO"),
#line 6135
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
#line 6136
        .trainerPic = TRAINER_PIC_COOLTRAINER_M,
        .encounterMusic_gender =
#line 6138
            TRAINER_ENCOUNTER_MUSIC_COOL,
#line 6139
        .items = { ITEM_HYPER_POTION },
#line 6140
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 6141
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .partySize = 5,
        .party = (const struct TrainerMon[])
        {
            {
#line 6143
            .species = SPECIES_RATICATE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6145
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 6144
            .lvl = 42,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 6146
                MOVE_SUPER_FANG,
                MOVE_PURSUIT,
                MOVE_SCARY_FACE,
                MOVE_QUICK_ATTACK,
            },
            },
            {
#line 6151
            .species = SPECIES_IVYSAUR,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6153
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 6152
            .lvl = 42,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 6154
                MOVE_RAZOR_LEAF,
                MOVE_SLEEP_POWDER,
                MOVE_SWEET_SCENT,
                MOVE_SYNTHESIS,
            },
            },
            {
#line 6159
            .species = SPECIES_WARTORTLE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6161
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 6160
            .lvl = 42,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 6162
                MOVE_WATER_GUN,
                MOVE_BITE,
                MOVE_RAPID_SPIN,
                MOVE_TAIL_WHIP,
            },
            },
            {
#line 6167
            .species = SPECIES_CHARMELEON,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6169
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 6168
            .lvl = 42,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 6170
                MOVE_FLAMETHROWER,
                MOVE_SLASH,
                MOVE_SMOKESCREEN,
                MOVE_SCARY_FACE,
            },
            },
            {
#line 6175
            .species = SPECIES_CHARIZARD,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6177
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 6176
            .lvl = 42,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 6178
                MOVE_FLAMETHROWER,
                MOVE_WING_ATTACK,
                MOVE_SMOKESCREEN,
                MOVE_SCARY_FACE,
            },
            },
        },
    },
#line 6183
    [DIFFICULTY_NORMAL][TRAINER_COOLTRAINER_GILBERT] =
    {
#line 6184
        .trainerName = _("GILBERT"),
#line 6185
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
#line 6186
        .trainerPic = TRAINER_PIC_COOLTRAINER_M,
        .encounterMusic_gender =
#line 6188
            TRAINER_ENCOUNTER_MUSIC_COOL,
#line 6189
        .items = { ITEM_HYPER_POTION },
#line 6190
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 6191
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .partySize = 5,
        .party = (const struct TrainerMon[])
        {
            {
#line 6193
            .species = SPECIES_PIDGEOTTO,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6195
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 6194
            .lvl = 42,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 6196
                MOVE_WING_ATTACK,
                MOVE_FEATHER_DANCE,
                MOVE_WHIRLWIND,
                MOVE_QUICK_ATTACK,
            },
            },
            {
#line 6201
            .species = SPECIES_FEAROW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6203
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 6202
            .lvl = 42,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 6204
                MOVE_DRILL_PECK,
                MOVE_MIRROR_MOVE,
                MOVE_PURSUIT,
                MOVE_LEER,
            },
            },
            {
#line 6209
            .species = SPECIES_PERSIAN,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6211
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 6210
            .lvl = 42,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 6212
                MOVE_PAY_DAY,
                MOVE_FAINT_ATTACK,
                MOVE_SCREECH,
                MOVE_BITE,
            },
            },
            {
#line 6217
            .species = SPECIES_LICKITUNG,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6219
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 6218
            .lvl = 42,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 6220
                MOVE_SLAM,
                MOVE_DISABLE,
                MOVE_WRAP,
                MOVE_SUPERSONIC,
            },
            },
            {
#line 6225
            .species = SPECIES_TAUROS,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6227
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 6226
            .lvl = 42,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 6228
                MOVE_HORN_ATTACK,
                MOVE_SCARY_FACE,
                MOVE_SWAGGER,
                MOVE_TAIL_WHIP,
            },
            },
        },
    },
#line 6233
    [DIFFICULTY_NORMAL][TRAINER_COOLTRAINER_OWEN] =
    {
#line 6234
        .trainerName = _("OWEN"),
#line 6235
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
#line 6236
        .trainerPic = TRAINER_PIC_COOLTRAINER_M,
        .encounterMusic_gender =
#line 6238
            TRAINER_ENCOUNTER_MUSIC_COOL,
#line 6239
        .items = { ITEM_HYPER_POTION },
#line 6240
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 6241
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .partySize = 5,
        .party = (const struct TrainerMon[])
        {
            {
#line 6243
            .species = SPECIES_NIDORINO,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6245
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 6244
            .lvl = 42,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 6246
                MOVE_SCRATCH,
                MOVE_POISON_STING,
                MOVE_DOUBLE_KICK,
                MOVE_BITE,
            },
            },
            {
#line 6251
            .species = SPECIES_NIDORINA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6253
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 6252
            .lvl = 42,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 6254
                MOVE_HORN_ATTACK,
                MOVE_POISON_STING,
                MOVE_DOUBLE_KICK,
                MOVE_LEER,
            },
            },
            {
#line 6259
            .species = SPECIES_RATICATE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6261
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 6260
            .lvl = 42,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 6262
                MOVE_SUPER_FANG,
                MOVE_PURSUIT,
                MOVE_SCARY_FACE,
                MOVE_QUICK_ATTACK,
            },
            },
            {
#line 6267
            .species = SPECIES_SANDSLASH,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6269
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 6268
            .lvl = 42,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 6270
                MOVE_FURY_SWIPES,
                MOVE_SWIFT,
                MOVE_SLASH,
                MOVE_POISON_STING,
            },
            },
            {
#line 6275
            .species = SPECIES_RHYHORN,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6277
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 6276
            .lvl = 42,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 6278
                MOVE_ROCK_BLAST,
                MOVE_SCARY_FACE,
                MOVE_STOMP,
                MOVE_TAIL_WHIP,
            },
            },
        },
    },
#line 6283
    [DIFFICULTY_NORMAL][TRAINER_COOLTRAINER_BERKE] =
    {
#line 6284
        .trainerName = _("BERKE"),
#line 6285
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
#line 6286
        .trainerPic = TRAINER_PIC_COOLTRAINER_M,
        .encounterMusic_gender =
#line 6288
            TRAINER_ENCOUNTER_MUSIC_COOL,
#line 6289
        .items = { ITEM_FULL_RESTORE },
#line 6290
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 6291
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .partySize = 5,
        .party = (const struct TrainerMon[])
        {
            {
#line 6293
            .species = SPECIES_SEEL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6295
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 6294
            .lvl = 42,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 6296
                MOVE_TAKE_DOWN,
                MOVE_AURORA_BEAM,
                MOVE_ICY_WIND,
                MOVE_GROWL,
            },
            },
            {
#line 6301
            .species = SPECIES_GRAVELER,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6303
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 6302
            .lvl = 42,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 6304
                MOVE_ROCK_BLAST,
                MOVE_MAGNITUDE,
                MOVE_ROCK_THROW,
                MOVE_MUD_SPORT,
            },
            },
            {
#line 6309
            .species = SPECIES_KINGLER,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6311
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 6310
            .lvl = 42,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 6312
                MOVE_GUILLOTINE,
                MOVE_STOMP,
                MOVE_MUD_SHOT,
                MOVE_BUBBLE,
            },
            },
            {
#line 6317
            .species = SPECIES_ONIX,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6319
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 6318
            .lvl = 42,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 6320
                MOVE_SLAM,
                MOVE_SANDSTORM,
                MOVE_DRAGON_BREATH,
                MOVE_ROCK_THROW,
            },
            },
            {
#line 6325
            .species = SPECIES_CLOYSTER,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6327
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 6326
            .lvl = 42,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 6328
                MOVE_SPIKE_CANNON,
                MOVE_AURORA_BEAM,
                MOVE_SUPERSONIC,
                MOVE_PROTECT,
            },
            },
        },
    },
#line 6333
    [DIFFICULTY_NORMAL][TRAINER_COOLTRAINER_YUJI] =
    {
#line 6334
        .trainerName = _("YUJI"),
#line 6335
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
#line 6336
        .trainerPic = TRAINER_PIC_COOLTRAINER_M,
        .encounterMusic_gender =
#line 6338
            TRAINER_ENCOUNTER_MUSIC_COOL,
#line 6339
        .items = { ITEM_HYPER_POTION },
#line 6340
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 6341
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .partySize = 5,
        .party = (const struct TrainerMon[])
        {
            {
#line 6343
            .species = SPECIES_SANDSLASH,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6345
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 6344
            .lvl = 38,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 6346
                MOVE_SLASH,
                MOVE_SWIFT,
                MOVE_SAND_ATTACK,
                MOVE_POISON_STING,
            },
            },
            {
#line 6351
            .species = SPECIES_GRAVELER,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6353
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 6352
            .lvl = 38,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 6354
                MOVE_ROCK_BLAST,
                MOVE_MAGNITUDE,
                MOVE_MUD_SPORT,
                MOVE_DEFENSE_CURL,
            },
            },
            {
#line 6359
            .species = SPECIES_ONIX,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6361
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 6360
            .lvl = 38,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 6362
                MOVE_DRAGON_BREATH,
                MOVE_SANDSTORM,
                MOVE_ROCK_THROW,
                MOVE_BIND,
            },
            },
            {
#line 6367
            .species = SPECIES_GRAVELER,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6369
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 6368
            .lvl = 38,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 6370
                MOVE_ROCK_BLAST,
                MOVE_MAGNITUDE,
                MOVE_ROLLOUT,
                MOVE_DEFENSE_CURL,
            },
            },
            {
#line 6375
            .species = SPECIES_MAROWAK,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6377
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 6376
            .lvl = 38,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 6378
                MOVE_BONEMERANG,
                MOVE_HEADBUTT,
                MOVE_LEER,
                MOVE_GROWL,
            },
            },
        },
    },
#line 6383
    [DIFFICULTY_NORMAL][TRAINER_COOLTRAINER_WARREN] =
    {
#line 6384
        .trainerName = _("WARREN"),
#line 6385
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
#line 6386
        .trainerPic = TRAINER_PIC_COOLTRAINER_M,
        .encounterMusic_gender =
#line 6388
            TRAINER_ENCOUNTER_MUSIC_COOL,
#line 6389
        .items = { ITEM_HYPER_POTION },
#line 6390
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 6391
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .partySize = 5,
        .party = (const struct TrainerMon[])
        {
            {
#line 6393
            .species = SPECIES_MAROWAK,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6395
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 6394
            .lvl = 37,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 6396
                MOVE_BONEMERANG,
                MOVE_HEADBUTT,
                MOVE_LEER,
                MOVE_GROWL,
            },
            },
            {
#line 6401
            .species = SPECIES_MAROWAK,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6403
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 6402
            .lvl = 37,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 6404
                MOVE_BONEMERANG,
                MOVE_HEADBUTT,
                MOVE_LEER,
                MOVE_GROWL,
            },
            },
            {
#line 6409
            .species = SPECIES_RHYHORN,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6411
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 6410
            .lvl = 38,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 6412
                MOVE_TAKE_DOWN,
                MOVE_ROCK_BLAST,
                MOVE_FURY_ATTACK,
                MOVE_SCARY_FACE,
            },
            },
            {
#line 6417
            .species = SPECIES_NIDORINA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6419
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 6418
            .lvl = 39,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 6420
                MOVE_FURY_SWIPES,
                MOVE_BITE,
                MOVE_POISON_STING,
                MOVE_DOUBLE_KICK,
            },
            },
            {
#line 6425
            .species = SPECIES_NIDOQUEEN,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6427
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 6426
            .lvl = 39,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 6428
                MOVE_BODY_SLAM,
                MOVE_BITE,
                MOVE_POISON_STING,
                MOVE_DOUBLE_KICK,
            },
            },
        },
    },
#line 6433
    [DIFFICULTY_NORMAL][TRAINER_COOLTRAINER_MARY] =
    {
#line 6434
        .trainerName = _("MARY"),
#line 6435
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
#line 6436
        .trainerPic = TRAINER_PIC_COOLTRAINER_F,
        .encounterMusic_gender =
#line 6438
            TRAINER_ENCOUNTER_MUSIC_COOL,
#line 6439
        .items = { ITEM_SUPER_POTION },
#line 6440
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 6441
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .partySize = 5,
        .party = (const struct TrainerMon[])
        {
            {
#line 6443
            .species = SPECIES_BELLSPROUT,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6445
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 6444
            .lvl = 22,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 6446
                MOVE_WRAP,
                MOVE_STUN_SPORE,
                MOVE_POISON_POWDER,
                MOVE_GROWTH,
            },
            },
            {
#line 6451
            .species = SPECIES_ODDISH,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6453
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 6452
            .lvl = 22,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 6454
                MOVE_POISON_POWDER,
                MOVE_STUN_SPORE,
                MOVE_ABSORB,
                MOVE_SWEET_SCENT,
            },
            },
            {
#line 6459
            .species = SPECIES_WEEPINBELL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6461
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 6460
            .lvl = 22,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 6462
                MOVE_VINE_WHIP,
                MOVE_STUN_SPORE,
                MOVE_POISON_POWDER,
                MOVE_GROWTH,
            },
            },
            {
#line 6467
            .species = SPECIES_GLOOM,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6469
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 6468
            .lvl = 22,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 6470
                MOVE_ABSORB,
                MOVE_STUN_SPORE,
                MOVE_POISON_POWDER,
                MOVE_SWEET_SCENT,
            },
            },
            {
#line 6475
            .species = SPECIES_IVYSAUR,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6477
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 6476
            .lvl = 22,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 6478
                MOVE_RAZOR_LEAF,
                MOVE_SLEEP_POWDER,
                MOVE_VINE_WHIP,
                MOVE_LEECH_SEED,
            },
            },
        },
    },
#line 6483
    [DIFFICULTY_NORMAL][TRAINER_COOLTRAINER_CAROLINE] =
    {
#line 6484
        .trainerName = _("CAROLINE"),
#line 6485
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
#line 6486
        .trainerPic = TRAINER_PIC_COOLTRAINER_F,
        .encounterMusic_gender =
#line 6488
            TRAINER_ENCOUNTER_MUSIC_COOL,
#line 6489
        .items = { ITEM_HYPER_POTION },
#line 6490
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 6491
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .partySize = 5,
        .party = (const struct TrainerMon[])
        {
            {
#line 6493
            .species = SPECIES_BELLSPROUT,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6495
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 6494
            .lvl = 42,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 6496
                MOVE_RAZOR_LEAF,
                MOVE_ACID,
                MOVE_STUN_SPORE,
                MOVE_POISON_POWDER,
            },
            },
            {
#line 6501
            .species = SPECIES_WEEPINBELL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6503
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 6502
            .lvl = 42,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 6504
                MOVE_RAZOR_LEAF,
                MOVE_ACID,
                MOVE_SLEEP_POWDER,
                MOVE_POISON_POWDER,
            },
            },
            {
#line 6509
            .species = SPECIES_VICTREEBEL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6511
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 6510
            .lvl = 42,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 6512
                MOVE_RAZOR_LEAF,
                MOVE_ACID,
                MOVE_STUN_SPORE,
                MOVE_SLEEP_POWDER,
            },
            },
            {
#line 6517
            .species = SPECIES_PARAS,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6519
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 6518
            .lvl = 42,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 6520
                MOVE_GROWTH,
                MOVE_SLASH,
                MOVE_LEECH_LIFE,
                MOVE_STUN_SPORE,
            },
            },
            {
#line 6525
            .species = SPECIES_PARASECT,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6527
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 6526
            .lvl = 42,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 6528
                MOVE_SPORE,
                MOVE_SLASH,
                MOVE_LEECH_LIFE,
                MOVE_POISON_POWDER,
            },
            },
        },
    },
#line 6533
    [DIFFICULTY_NORMAL][TRAINER_COOLTRAINER_ALEXA] =
    {
#line 6534
        .trainerName = _("ALEXA"),
#line 6535
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
#line 6536
        .trainerPic = TRAINER_PIC_COOLTRAINER_F,
        .encounterMusic_gender =
#line 6538
            TRAINER_ENCOUNTER_MUSIC_COOL,
#line 6539
        .items = { ITEM_FULL_RESTORE },
#line 6540
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 6541
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .partySize = 5,
        .party = (const struct TrainerMon[])
        {
            {
#line 6543
            .species = SPECIES_CLEFAIRY,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6545
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 6544
            .lvl = 42,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 6546
                MOVE_LIGHT_SCREEN,
                MOVE_COSMIC_POWER,
                MOVE_DOUBLE_SLAP,
                MOVE_ENCORE,
            },
            },
            {
#line 6551
            .species = SPECIES_JIGGLYPUFF,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6553
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 6552
            .lvl = 42,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 6554
                MOVE_SING,
                MOVE_BODY_SLAM,
                MOVE_ROLLOUT,
                MOVE_DISABLE,
            },
            },
            {
#line 6559
            .species = SPECIES_PERSIAN,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6561
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 6560
            .lvl = 42,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 6562
                MOVE_PAY_DAY,
                MOVE_FAINT_ATTACK,
                MOVE_BITE,
                MOVE_SCREECH,
            },
            },
            {
#line 6567
            .species = SPECIES_DEWGONG,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6569
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 6568
            .lvl = 42,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 6570
                MOVE_SHEER_COLD,
                MOVE_TAKE_DOWN,
                MOVE_REST,
                MOVE_AURORA_BEAM,
            },
            },
            {
#line 6575
            .species = SPECIES_CHANSEY,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6577
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 6576
            .lvl = 42,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 6578
                MOVE_SING,
                MOVE_EGG_BOMB,
                MOVE_SOFT_BOILED,
                MOVE_MINIMIZE,
            },
            },
        },
    },
#line 6583
    [DIFFICULTY_NORMAL][TRAINER_COOLTRAINER_SHANNON] =
    {
#line 6584
        .trainerName = _("SHANNON"),
#line 6585
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
#line 6586
        .trainerPic = TRAINER_PIC_COOLTRAINER_F,
        .encounterMusic_gender =
#line 6588
            TRAINER_ENCOUNTER_MUSIC_COOL,
#line 6589
        .items = { ITEM_FULL_RESTORE },
#line 6590
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 6591
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .partySize = 5,
        .party = (const struct TrainerMon[])
        {
            {
#line 6593
            .species = SPECIES_BEEDRILL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6595
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 6594
            .lvl = 42,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 6596
                MOVE_PIN_MISSILE,
                MOVE_TWINEEDLE,
                MOVE_AGILITY,
                MOVE_PURSUIT,
            },
            },
            {
#line 6601
            .species = SPECIES_BUTTERFREE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6603
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 6602
            .lvl = 42,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 6604
                MOVE_SAFEGUARD,
                MOVE_PSYBEAM,
                MOVE_GUST,
                MOVE_SUPERSONIC,
            },
            },
            {
#line 6609
            .species = SPECIES_PARASECT,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6611
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 6610
            .lvl = 42,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 6612
                MOVE_SPORE,
                MOVE_LEECH_LIFE,
                MOVE_SLASH,
                MOVE_GROWTH,
            },
            },
            {
#line 6617
            .species = SPECIES_VENONAT,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6619
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 6618
            .lvl = 42,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 6620
                MOVE_PSYBEAM,
                MOVE_STUN_SPORE,
                MOVE_LEECH_LIFE,
                MOVE_DISABLE,
            },
            },
            {
#line 6625
            .species = SPECIES_VENOMOTH,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6627
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 6626
            .lvl = 42,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 6628
                MOVE_PSYBEAM,
                MOVE_GUST,
                MOVE_SUPERSONIC,
                MOVE_LEECH_LIFE,
            },
            },
        },
    },
#line 6633
    [DIFFICULTY_NORMAL][TRAINER_COOLTRAINER_NAOMI] =
    {
#line 6634
        .trainerName = _("NAOMI"),
#line 6635
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
#line 6636
        .trainerPic = TRAINER_PIC_COOLTRAINER_F,
        .encounterMusic_gender =
#line 6638
            TRAINER_ENCOUNTER_MUSIC_COOL,
#line 6639
        .items = { ITEM_HYPER_POTION },
#line 6640
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 6641
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .partySize = 5,
        .party = (const struct TrainerMon[])
        {
            {
#line 6643
            .species = SPECIES_PERSIAN,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6645
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 6644
            .lvl = 42,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 6646
                MOVE_FURY_SWIPES,
                MOVE_SCREECH,
                MOVE_FAINT_ATTACK,
                MOVE_PAY_DAY,
            },
            },
            {
#line 6651
            .species = SPECIES_PONYTA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6653
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 6652
            .lvl = 42,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 6654
                MOVE_AGILITY,
                MOVE_TAKE_DOWN,
                MOVE_FIRE_SPIN,
                MOVE_STOMP,
            },
            },
            {
#line 6659
            .species = SPECIES_RAPIDASH,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6661
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 6660
            .lvl = 42,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 6662
                MOVE_FURY_ATTACK,
                MOVE_FIRE_SPIN,
                MOVE_STOMP,
                MOVE_GROWL,
            },
            },
            {
#line 6667
            .species = SPECIES_VULPIX,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6669
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 6668
            .lvl = 42,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 6670
                MOVE_FLAMETHROWER,
                MOVE_CONFUSE_RAY,
                MOVE_QUICK_ATTACK,
                MOVE_IMPRISON,
            },
            },
            {
#line 6675
            .species = SPECIES_NINETALES,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6677
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 6676
            .lvl = 42,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 6678
                MOVE_SAFEGUARD,
                MOVE_WILL_O_WISP,
                MOVE_CONFUSE_RAY,
                MOVE_FIRE_SPIN,
            },
            },
        },
    },
#line 6683
    [DIFFICULTY_NORMAL][TRAINER_COOLTRAINER_BROOKE] =
    {
#line 6684
        .trainerName = _("BROOKE"),
#line 6685
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
#line 6686
        .trainerPic = TRAINER_PIC_COOLTRAINER_F,
        .encounterMusic_gender =
#line 6688
            TRAINER_ENCOUNTER_MUSIC_COOL,
#line 6689
        .items = { ITEM_FULL_RESTORE },
#line 6690
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 6691
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .partySize = 5,
        .party = (const struct TrainerMon[])
        {
            {
#line 6693
            .species = SPECIES_TANGELA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6695
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 6694
            .lvl = 42,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 6696
                MOVE_SLAM,
                MOVE_BIND,
                MOVE_MEGA_DRAIN,
                MOVE_INGRAIN,
            },
            },
            {
#line 6701
            .species = SPECIES_GLOOM,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6703
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 6702
            .lvl = 42,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 6704
                MOVE_ACID,
                MOVE_MOONLIGHT,
                MOVE_SLEEP_POWDER,
                MOVE_STUN_SPORE,
            },
            },
            {
#line 6709
            .species = SPECIES_VILEPLUME,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6711
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 6710
            .lvl = 42,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 6712
                MOVE_MEGA_DRAIN,
                MOVE_ACID,
                MOVE_STUN_SPORE,
                MOVE_AROMATHERAPY,
            },
            },
            {
#line 6717
            .species = SPECIES_IVYSAUR,
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
                MOVE_SWEET_SCENT,
                MOVE_GROWL,
                MOVE_LEECH_SEED,
            },
            },
            {
#line 6725
            .species = SPECIES_VENUSAUR,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6727
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 6726
            .lvl = 42,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 6728
                MOVE_RAZOR_LEAF,
                MOVE_GROWTH,
                MOVE_SLEEP_POWDER,
                MOVE_POISON_POWDER,
            },
            },
        },
    },
#line 6733
    [DIFFICULTY_NORMAL][TRAINER_COOLTRAINER_AUSTINA] =
    {
#line 6734
        .trainerName = _("AUSTINA"),
#line 6735
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
#line 6736
        .trainerPic = TRAINER_PIC_COOLTRAINER_F,
        .encounterMusic_gender =
#line 6738
            TRAINER_ENCOUNTER_MUSIC_COOL,
#line 6739
        .items = { ITEM_FULL_RESTORE },
#line 6740
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 6741
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .partySize = 5,
        .party = (const struct TrainerMon[])
        {
            {
#line 6743
            .species = SPECIES_RHYHORN,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6745
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 6744
            .lvl = 42,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 6746
                MOVE_HORN_DRILL,
                MOVE_ROCK_BLAST,
                MOVE_SCARY_FACE,
                MOVE_STOMP,
            },
            },
            {
#line 6751
            .species = SPECIES_NIDORINA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6753
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 6752
            .lvl = 42,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 6754
                MOVE_DOUBLE_KICK,
                MOVE_FURY_SWIPES,
                MOVE_BITE,
                MOVE_FLATTER,
            },
            },
            {
#line 6759
            .species = SPECIES_NIDOQUEEN,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6761
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 6760
            .lvl = 42,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 6762
                MOVE_BODY_SLAM,
                MOVE_DOUBLE_KICK,
                MOVE_BITE,
                MOVE_GROWL,
            },
            },
            {
#line 6767
            .species = SPECIES_NIDORINO,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6769
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 6768
            .lvl = 42,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 6770
                MOVE_HORN_ATTACK,
                MOVE_POISON_STING,
                MOVE_FOCUS_ENERGY,
                MOVE_LEER,
            },
            },
            {
#line 6775
            .species = SPECIES_NIDOKING,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6777
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 6776
            .lvl = 42,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 6778
                MOVE_THRASH,
                MOVE_DOUBLE_KICK,
                MOVE_POISON_STING,
                MOVE_PECK,
            },
            },
        },
    },
#line 6783
    [DIFFICULTY_NORMAL][TRAINER_COOLTRAINER_JULIE] =
    {
#line 6784
        .trainerName = _("JULIE"),
#line 6785
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
#line 6786
        .trainerPic = TRAINER_PIC_COOLTRAINER_F,
        .encounterMusic_gender =
#line 6788
            TRAINER_ENCOUNTER_MUSIC_COOL,
#line 6789
        .items = { ITEM_HYPER_POTION },
#line 6790
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 6791
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .partySize = 5,
        .party = (const struct TrainerMon[])
        {
            {
#line 6793
            .species = SPECIES_PERSIAN,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6795
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 6794
            .lvl = 42,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 6796
                MOVE_FURY_SWIPES,
                MOVE_BITE,
                MOVE_SCREECH,
                MOVE_FAINT_ATTACK,
            },
            },
            {
#line 6801
            .species = SPECIES_NINETALES,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6803
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 6802
            .lvl = 42,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 6804
                MOVE_FLAMETHROWER,
                MOVE_WILL_O_WISP,
                MOVE_CONFUSE_RAY,
                MOVE_GRUDGE,
            },
            },
            {
#line 6809
            .species = SPECIES_RAPIDASH,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6811
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 6810
            .lvl = 42,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 6812
                MOVE_FURY_ATTACK,
                MOVE_FIRE_SPIN,
                MOVE_TAKE_DOWN,
                MOVE_AGILITY,
            },
            },
            {
#line 6817
            .species = SPECIES_PIKACHU,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6819
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 6818
            .lvl = 42,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 6820
                MOVE_THUNDERBOLT,
                MOVE_THUNDER_WAVE,
                MOVE_DOUBLE_TEAM,
                MOVE_QUICK_ATTACK,
            },
            },
            {
#line 6825
            .species = SPECIES_RAICHU,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6827
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 6826
            .lvl = 42,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 6828
                MOVE_THUNDER,
                MOVE_THUNDER_WAVE,
                MOVE_SLAM,
                MOVE_DOUBLE_TEAM,
            },
            },
        },
    },
#line 6833
    [DIFFICULTY_NORMAL][TRAINER_ELITE_FOUR_LORELEI] =
    {
#line 6834
        .trainerName = _("LORELEI"),
#line 6835
        .trainerClass = TRAINER_CLASS_ELITE_FOUR,
#line 6836
        .trainerPic = TRAINER_PIC_ELITE_FOUR_LORELEI,
        .encounterMusic_gender =
#line 6838
            TRAINER_ENCOUNTER_MUSIC_ELITE_FOUR,
#line 6839
        .items = { ITEM_FULL_RESTORE, ITEM_FULL_RESTORE },
#line 6840
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 6841
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
#line 6842
        .mugshotColor = MUGSHOT_COLOR_PURPLE,
        .partySize = 5,
        .party = (const struct TrainerMon[])
        {
            {
#line 6844
            .species = SPECIES_DEWGONG,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6846
            .iv = TRAINER_PARTY_IVS(30, 30, 30, 30, 30, 30),
#line 6845
            .lvl = 52,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 6847
                MOVE_ICE_BEAM,
                MOVE_SURF,
                MOVE_HAIL,
                MOVE_SAFEGUARD,
            },
            },
            {
#line 6852
            .species = SPECIES_CLOYSTER,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6854
            .iv = TRAINER_PARTY_IVS(30, 30, 30, 30, 30, 30),
#line 6853
            .lvl = 51,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 6855
                MOVE_SPIKES,
                MOVE_PROTECT,
                MOVE_HAIL,
                MOVE_DIVE,
            },
            },
            {
#line 6860
            .species = SPECIES_SLOWBRO,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6862
            .iv = TRAINER_PARTY_IVS(30, 30, 30, 30, 30, 30),
#line 6861
            .lvl = 52,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 6863
                MOVE_ICE_BEAM,
                MOVE_SURF,
                MOVE_AMNESIA,
                MOVE_YAWN,
            },
            },
            {
#line 6868
            .species = SPECIES_JYNX,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6870
            .iv = TRAINER_PARTY_IVS(30, 30, 30, 30, 30, 30),
#line 6869
            .lvl = 54,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 6871
                MOVE_ICE_PUNCH,
                MOVE_DOUBLE_SLAP,
                MOVE_LOVELY_KISS,
                MOVE_ATTRACT,
            },
            },
            {
#line 6876
            .species = SPECIES_LAPRAS,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6876
            .heldItem = ITEM_SITRUS_BERRY,
#line 6878
            .iv = TRAINER_PARTY_IVS(30, 30, 30, 30, 30, 30),
#line 6877
            .lvl = 54,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 6879
                MOVE_CONFUSE_RAY,
                MOVE_ICE_BEAM,
                MOVE_SURF,
                MOVE_BODY_SLAM,
            },
            },
        },
    },
#line 6884
    [DIFFICULTY_NORMAL][TRAINER_ELITE_FOUR_BRUNO] =
    {
#line 6885
        .trainerName = _("BRUNO"),
#line 6886
        .trainerClass = TRAINER_CLASS_ELITE_FOUR,
#line 6887
        .trainerPic = TRAINER_PIC_ELITE_FOUR_BRUNO,
        .encounterMusic_gender =
#line 6889
            TRAINER_ENCOUNTER_MUSIC_ELITE_FOUR,
#line 6890
        .items = { ITEM_FULL_RESTORE, ITEM_FULL_RESTORE },
#line 6891
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 6892
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
#line 6893
        .mugshotColor = MUGSHOT_COLOR_GREEN,
        .partySize = 5,
        .party = (const struct TrainerMon[])
        {
            {
#line 6895
            .species = SPECIES_ONIX,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6897
            .iv = TRAINER_PARTY_IVS(30, 30, 30, 30, 30, 30),
#line 6896
            .lvl = 51,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 6898
                MOVE_EARTHQUAKE,
                MOVE_ROCK_TOMB,
                MOVE_IRON_TAIL,
                MOVE_ROAR,
            },
            },
            {
#line 6903
            .species = SPECIES_HITMONCHAN,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6905
            .iv = TRAINER_PARTY_IVS(30, 30, 30, 30, 30, 30),
#line 6904
            .lvl = 53,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 6906
                MOVE_SKY_UPPERCUT,
                MOVE_MACH_PUNCH,
                MOVE_ROCK_TOMB,
                MOVE_COUNTER,
            },
            },
            {
#line 6911
            .species = SPECIES_HITMONLEE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6913
            .iv = TRAINER_PARTY_IVS(30, 30, 30, 30, 30, 30),
#line 6912
            .lvl = 53,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 6914
                MOVE_MEGA_KICK,
                MOVE_FORESIGHT,
                MOVE_BRICK_BREAK,
                MOVE_FACADE,
            },
            },
            {
#line 6919
            .species = SPECIES_ONIX,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6921
            .iv = TRAINER_PARTY_IVS(30, 30, 30, 30, 30, 30),
#line 6920
            .lvl = 54,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 6922
                MOVE_DOUBLE_EDGE,
                MOVE_EARTHQUAKE,
                MOVE_IRON_TAIL,
                MOVE_SAND_TOMB,
            },
            },
            {
#line 6927
            .species = SPECIES_MACHAMP,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6927
            .heldItem = ITEM_SITRUS_BERRY,
#line 6929
            .iv = TRAINER_PARTY_IVS(30, 30, 30, 30, 30, 30),
#line 6928
            .lvl = 56,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 6930
                MOVE_CROSS_CHOP,
                MOVE_BULK_UP,
                MOVE_SCARY_FACE,
                MOVE_ROCK_TOMB,
            },
            },
        },
    },
#line 6935
    [DIFFICULTY_NORMAL][TRAINER_ELITE_FOUR_AGATHA] =
    {
#line 6936
        .trainerName = _("AGATHA"),
#line 6937
        .trainerClass = TRAINER_CLASS_ELITE_FOUR,
#line 6938
        .trainerPic = TRAINER_PIC_ELITE_FOUR_AGATHA,
        .encounterMusic_gender =
#line 6940
            TRAINER_ENCOUNTER_MUSIC_ELITE_FOUR,
#line 6941
        .items = { ITEM_FULL_RESTORE, ITEM_FULL_RESTORE },
#line 6942
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 6943
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
#line 6944
        .mugshotColor = MUGSHOT_COLOR_PINK,
        .partySize = 5,
        .party = (const struct TrainerMon[])
        {
            {
#line 6946
            .species = SPECIES_GENGAR,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6948
            .iv = TRAINER_PARTY_IVS(30, 30, 30, 30, 30, 30),
#line 6947
            .lvl = 54,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 6949
                MOVE_SHADOW_PUNCH,
                MOVE_CONFUSE_RAY,
                MOVE_TOXIC,
                MOVE_DOUBLE_TEAM,
            },
            },
            {
#line 6954
            .species = SPECIES_GOLBAT,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6956
            .iv = TRAINER_PARTY_IVS(30, 30, 30, 30, 30, 30),
#line 6955
            .lvl = 54,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 6957
                MOVE_CONFUSE_RAY,
                MOVE_POISON_FANG,
                MOVE_AIR_CUTTER,
                MOVE_BITE,
            },
            },
            {
#line 6962
            .species = SPECIES_HAUNTER,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6964
            .iv = TRAINER_PARTY_IVS(30, 30, 30, 30, 30, 30),
#line 6963
            .lvl = 53,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 6965
                MOVE_HYPNOSIS,
                MOVE_DREAM_EATER,
                MOVE_CURSE,
                MOVE_MEAN_LOOK,
            },
            },
            {
#line 6970
            .species = SPECIES_ARBOK,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6972
            .iv = TRAINER_PARTY_IVS(30, 30, 30, 30, 30, 30),
#line 6971
            .lvl = 56,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 6973
                MOVE_SLUDGE_BOMB,
                MOVE_SCREECH,
                MOVE_IRON_TAIL,
                MOVE_BITE,
            },
            },
            {
#line 6978
            .species = SPECIES_GENGAR,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6978
            .heldItem = ITEM_SITRUS_BERRY,
#line 6980
            .iv = TRAINER_PARTY_IVS(30, 30, 30, 30, 30, 30),
#line 6979
            .lvl = 58,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 6981
                MOVE_SHADOW_BALL,
                MOVE_SLUDGE_BOMB,
                MOVE_HYPNOSIS,
                MOVE_NIGHTMARE,
            },
            },
        },
    },
#line 6986
    [DIFFICULTY_NORMAL][TRAINER_ELITE_FOUR_LANCE] =
    {
#line 6987
        .trainerName = _("LANCE"),
#line 6988
        .trainerClass = TRAINER_CLASS_ELITE_FOUR,
#line 6989
        .trainerPic = TRAINER_PIC_ELITE_FOUR_LANCE,
        .encounterMusic_gender =
#line 6991
            TRAINER_ENCOUNTER_MUSIC_ELITE_FOUR,
#line 6992
        .items = { ITEM_FULL_RESTORE, ITEM_FULL_RESTORE },
#line 6993
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 6994
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
#line 6995
        .mugshotColor = MUGSHOT_COLOR_BLUE,
        .partySize = 5,
        .party = (const struct TrainerMon[])
        {
            {
#line 6997
            .species = SPECIES_GYARADOS,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6999
            .iv = TRAINER_PARTY_IVS(30, 30, 30, 30, 30, 30),
#line 6998
            .lvl = 56,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 7000
                MOVE_HYPER_BEAM,
                MOVE_DRAGON_RAGE,
                MOVE_TWISTER,
                MOVE_BITE,
            },
            },
            {
#line 7005
            .species = SPECIES_DRAGONAIR,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7007
            .iv = TRAINER_PARTY_IVS(30, 30, 30, 30, 30, 30),
#line 7006
            .lvl = 54,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 7008
                MOVE_HYPER_BEAM,
                MOVE_SAFEGUARD,
                MOVE_DRAGON_RAGE,
                MOVE_OUTRAGE,
            },
            },
            {
#line 7013
            .species = SPECIES_DRAGONAIR,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7015
            .iv = TRAINER_PARTY_IVS(30, 30, 30, 30, 30, 30),
#line 7014
            .lvl = 54,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 7016
                MOVE_HYPER_BEAM,
                MOVE_SAFEGUARD,
                MOVE_THUNDER_WAVE,
                MOVE_OUTRAGE,
            },
            },
            {
#line 7021
            .species = SPECIES_AERODACTYL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7023
            .iv = TRAINER_PARTY_IVS(30, 30, 30, 30, 30, 30),
#line 7022
            .lvl = 58,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 7024
                MOVE_HYPER_BEAM,
                MOVE_ANCIENT_POWER,
                MOVE_WING_ATTACK,
                MOVE_SCARY_FACE,
            },
            },
            {
#line 7029
            .species = SPECIES_DRAGONITE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7029
            .heldItem = ITEM_SITRUS_BERRY,
#line 7031
            .iv = TRAINER_PARTY_IVS(30, 30, 30, 30, 30, 30),
#line 7030
            .lvl = 60,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 7032
                MOVE_HYPER_BEAM,
                MOVE_SAFEGUARD,
                MOVE_OUTRAGE,
                MOVE_WING_ATTACK,
            },
            },
        },
    },
#line 7037
    [DIFFICULTY_NORMAL][TRAINER_LEADER_BROCK] =
    {
#line 7038
        .trainerName = _("BROCK"),
#line 7039
        .trainerClass = TRAINER_CLASS_LEADER,
#line 7040
        .trainerPic = TRAINER_PIC_LEADER_BROCK,
        .encounterMusic_gender =
#line 7042
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 7043
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 7044
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 7046
            .species = SPECIES_GEODUDE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7048
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 7047
            .lvl = 12,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 7049
                MOVE_TACKLE,
                MOVE_DEFENSE_CURL,
            },
            },
            {
#line 7052
            .species = SPECIES_ONIX,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7054
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 7053
            .lvl = 14,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 7055
                MOVE_TACKLE,
                MOVE_BIND,
                MOVE_ROCK_TOMB,
            },
            },
        },
    },
#line 7059
    [DIFFICULTY_NORMAL][TRAINER_LEADER_MISTY] =
    {
#line 7060
        .trainerName = _("MISTY"),
#line 7061
        .trainerClass = TRAINER_CLASS_LEADER,
#line 7062
        .trainerPic = TRAINER_PIC_LEADER_MISTY,
        .encounterMusic_gender =
#line 7064
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
#line 7065
        .items = { ITEM_SUPER_POTION },
#line 7066
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 7067
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 7069
            .species = SPECIES_STARYU,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7071
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 7070
            .lvl = 18,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 7072
                MOVE_TACKLE,
                MOVE_HARDEN,
                MOVE_RECOVER,
                MOVE_WATER_PULSE,
            },
            },
            {
#line 7077
            .species = SPECIES_STARMIE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7079
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 7078
            .lvl = 21,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 7080
                MOVE_SWIFT,
                MOVE_RECOVER,
                MOVE_RAPID_SPIN,
                MOVE_WATER_PULSE,
            },
            },
        },
    },
#line 7085
    [DIFFICULTY_NORMAL][TRAINER_LEADER_LT_SURGE] =
    {
#line 7086
        .trainerName = _("LT. SURGE"),
#line 7087
        .trainerClass = TRAINER_CLASS_LEADER,
#line 7088
        .trainerPic = TRAINER_PIC_LEADER_LT_SURGE,
        .encounterMusic_gender =
#line 7090
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 7091
        .items = { ITEM_SUPER_POTION, ITEM_FULL_HEAL },
#line 7092
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 7093
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 7095
            .species = SPECIES_VOLTORB,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7097
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 7096
            .lvl = 21,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 7098
                MOVE_SONIC_BOOM,
                MOVE_TACKLE,
                MOVE_SCREECH,
                MOVE_SHOCK_WAVE,
            },
            },
            {
#line 7103
            .species = SPECIES_PIKACHU,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7105
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 7104
            .lvl = 18,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 7106
                MOVE_QUICK_ATTACK,
                MOVE_THUNDER_WAVE,
                MOVE_DOUBLE_TEAM,
                MOVE_SHOCK_WAVE,
            },
            },
            {
#line 7111
            .species = SPECIES_RAICHU,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7113
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 7112
            .lvl = 24,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 7114
                MOVE_QUICK_ATTACK,
                MOVE_THUNDER_WAVE,
                MOVE_DOUBLE_TEAM,
                MOVE_SHOCK_WAVE,
            },
            },
        },
    },
#line 7119
    [DIFFICULTY_NORMAL][TRAINER_LEADER_ERIKA] =
    {
#line 7120
        .trainerName = _("ERIKA"),
#line 7121
        .trainerClass = TRAINER_CLASS_LEADER,
#line 7122
        .trainerPic = TRAINER_PIC_LEADER_ERIKA,
        .encounterMusic_gender =
#line 7124
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
#line 7125
        .items = { ITEM_HYPER_POTION, ITEM_FULL_HEAL },
#line 7126
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 7127
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 7129
            .species = SPECIES_VICTREEBEL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7131
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 7130
            .lvl = 29,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 7132
                MOVE_STUN_SPORE,
                MOVE_ACID,
                MOVE_POISON_POWDER,
                MOVE_GIGA_DRAIN,
            },
            },
            {
#line 7137
            .species = SPECIES_TANGELA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7139
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 7138
            .lvl = 24,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 7140
                MOVE_POISON_POWDER,
                MOVE_CONSTRICT,
                MOVE_INGRAIN,
                MOVE_GIGA_DRAIN,
            },
            },
            {
#line 7145
            .species = SPECIES_VILEPLUME,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7147
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 7146
            .lvl = 29,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 7148
                MOVE_SLEEP_POWDER,
                MOVE_ACID,
                MOVE_STUN_SPORE,
                MOVE_GIGA_DRAIN,
            },
            },
        },
    },
#line 7153
    [DIFFICULTY_NORMAL][TRAINER_LEADER_KOGA] =
    {
#line 7154
        .trainerName = _("KOGA"),
#line 7155
        .trainerClass = TRAINER_CLASS_LEADER,
#line 7156
        .trainerPic = TRAINER_PIC_LEADER_KOGA,
        .encounterMusic_gender =
#line 7158
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 7159
        .items = { ITEM_HYPER_POTION, ITEM_HYPER_POTION, ITEM_FULL_HEAL },
#line 7160
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 7161
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .partySize = 4,
        .party = (const struct TrainerMon[])
        {
            {
#line 7163
            .species = SPECIES_KOFFING,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7165
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 7164
            .lvl = 37,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 7166
                MOVE_SELF_DESTRUCT,
                MOVE_SLUDGE,
                MOVE_SMOKESCREEN,
                MOVE_TOXIC,
            },
            },
            {
#line 7171
            .species = SPECIES_MUK,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7173
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 7172
            .lvl = 39,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 7174
                MOVE_MINIMIZE,
                MOVE_SLUDGE,
                MOVE_ACID_ARMOR,
                MOVE_TOXIC,
            },
            },
            {
#line 7179
            .species = SPECIES_KOFFING,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7181
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 7180
            .lvl = 37,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 7182
                MOVE_SELF_DESTRUCT,
                MOVE_SLUDGE,
                MOVE_SMOKESCREEN,
                MOVE_TOXIC,
            },
            },
            {
#line 7187
            .species = SPECIES_WEEZING,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7189
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 7188
            .lvl = 43,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 7190
                MOVE_TACKLE,
                MOVE_SLUDGE,
                MOVE_SMOKESCREEN,
                MOVE_TOXIC,
            },
            },
        },
    },
#line 7195
    [DIFFICULTY_NORMAL][TRAINER_LEADER_BLAINE] =
    {
#line 7196
        .trainerName = _("BLAINE"),
#line 7197
        .trainerClass = TRAINER_CLASS_LEADER,
#line 7198
        .trainerPic = TRAINER_PIC_LEADER_BLAINE,
        .encounterMusic_gender =
#line 7200
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 7201
        .items = { ITEM_HYPER_POTION, ITEM_HYPER_POTION, ITEM_FULL_HEAL },
#line 7202
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 7203
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .partySize = 4,
        .party = (const struct TrainerMon[])
        {
            {
#line 7205
            .species = SPECIES_GROWLITHE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7207
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 7206
            .lvl = 42,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 7208
                MOVE_BITE,
                MOVE_ROAR,
                MOVE_TAKE_DOWN,
                MOVE_FIRE_BLAST,
            },
            },
            {
#line 7213
            .species = SPECIES_PONYTA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7215
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 7214
            .lvl = 40,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 7216
                MOVE_STOMP,
                MOVE_BOUNCE,
                MOVE_FIRE_SPIN,
                MOVE_FIRE_BLAST,
            },
            },
            {
#line 7221
            .species = SPECIES_RAPIDASH,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7223
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 7222
            .lvl = 42,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 7224
                MOVE_STOMP,
                MOVE_BOUNCE,
                MOVE_FIRE_SPIN,
                MOVE_FIRE_BLAST,
            },
            },
            {
#line 7229
            .species = SPECIES_ARCANINE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7231
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 7230
            .lvl = 47,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 7232
                MOVE_BITE,
                MOVE_ROAR,
                MOVE_TAKE_DOWN,
                MOVE_FIRE_BLAST,
            },
            },
        },
    },
#line 7237
    [DIFFICULTY_NORMAL][TRAINER_LEADER_SABRINA] =
    {
#line 7238
        .trainerName = _("SABRINA"),
#line 7239
        .trainerClass = TRAINER_CLASS_LEADER,
#line 7240
        .trainerPic = TRAINER_PIC_LEADER_SABRINA,
        .encounterMusic_gender =
#line 7242
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
#line 7243
        .items = { ITEM_HYPER_POTION, ITEM_HYPER_POTION, ITEM_FULL_HEAL },
#line 7244
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 7245
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .partySize = 4,
        .party = (const struct TrainerMon[])
        {
            {
#line 7247
            .species = SPECIES_KADABRA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7249
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 7248
            .lvl = 38,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 7250
                MOVE_PSYBEAM,
                MOVE_REFLECT,
                MOVE_FUTURE_SIGHT,
                MOVE_CALM_MIND,
            },
            },
            {
#line 7255
            .species = SPECIES_MR_MIME,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7257
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 7256
            .lvl = 37,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 7258
                MOVE_BARRIER,
                MOVE_PSYBEAM,
                MOVE_BATON_PASS,
                MOVE_CALM_MIND,
            },
            },
            {
#line 7263
            .species = SPECIES_VENOMOTH,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7265
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 7264
            .lvl = 38,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 7266
                MOVE_PSYBEAM,
                MOVE_GUST,
                MOVE_LEECH_LIFE,
                MOVE_SUPERSONIC,
            },
            },
            {
#line 7271
            .species = SPECIES_ALAKAZAM,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7273
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 7272
            .lvl = 43,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 7274
                MOVE_PSYCHIC,
                MOVE_RECOVER,
                MOVE_FUTURE_SIGHT,
                MOVE_CALM_MIND,
            },
            },
        },
    },
#line 7279
    [DIFFICULTY_NORMAL][TRAINER_GENTLEMAN_THOMAS] =
    {
#line 7280
        .trainerName = _("THOMAS"),
#line 7281
        .trainerClass = TRAINER_CLASS_GENTLEMAN,
#line 7282
        .trainerPic = TRAINER_PIC_GENTLEMAN,
        .encounterMusic_gender =
#line 7284
            TRAINER_ENCOUNTER_MUSIC_RICH,
#line 7285
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 7286
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 7288
            .species = SPECIES_GROWLITHE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7290
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 7289
            .lvl = 18,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 7292
            .species = SPECIES_GROWLITHE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7294
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 7293
            .lvl = 18,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 7296
    [DIFFICULTY_NORMAL][TRAINER_GENTLEMAN_ARTHUR] =
    {
#line 7297
        .trainerName = _("ARTHUR"),
#line 7298
        .trainerClass = TRAINER_CLASS_GENTLEMAN,
#line 7299
        .trainerPic = TRAINER_PIC_GENTLEMAN,
        .encounterMusic_gender =
#line 7301
            TRAINER_ENCOUNTER_MUSIC_RICH,
#line 7302
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 7303
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 7305
            .species = SPECIES_NIDORAN_M,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7307
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 7306
            .lvl = 19,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 7309
            .species = SPECIES_NIDORAN_F,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7311
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 7310
            .lvl = 19,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 7313
    [DIFFICULTY_NORMAL][TRAINER_GENTLEMAN_TUCKER] =
    {
#line 7314
        .trainerName = _("TUCKER"),
#line 7315
        .trainerClass = TRAINER_CLASS_GENTLEMAN,
#line 7316
        .trainerPic = TRAINER_PIC_GENTLEMAN,
        .encounterMusic_gender =
#line 7318
            TRAINER_ENCOUNTER_MUSIC_RICH,
#line 7319
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 7320
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 7322
            .species = SPECIES_PIKACHU,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7324
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 7323
            .lvl = 23,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 7326
    [DIFFICULTY_NORMAL][TRAINER_GENTLEMAN_NORTON] =
    {
#line 7327
        .trainerName = _("NORTON"),
#line 7328
        .trainerClass = TRAINER_CLASS_GENTLEMAN,
#line 7329
        .trainerPic = TRAINER_PIC_GENTLEMAN,
        .encounterMusic_gender =
#line 7331
            TRAINER_ENCOUNTER_MUSIC_RICH,
#line 7332
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 7333
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 7335
            .species = SPECIES_PERSIAN,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7337
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 7336
            .lvl = 48,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 7339
    [DIFFICULTY_NORMAL][TRAINER_GENTLEMAN_WALTER] =
    {
#line 7340
        .trainerName = _("WALTER"),
#line 7341
        .trainerClass = TRAINER_CLASS_GENTLEMAN,
#line 7342
        .trainerPic = TRAINER_PIC_GENTLEMAN,
        .encounterMusic_gender =
#line 7344
            TRAINER_ENCOUNTER_MUSIC_RICH,
#line 7345
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 7346
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 7348
            .species = SPECIES_GROWLITHE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7350
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 7349
            .lvl = 17,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 7352
            .species = SPECIES_PONYTA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7354
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 7353
            .lvl = 17,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 7356
    [DIFFICULTY_NORMAL][TRAINER_RIVAL_SS_ANNE_SQUIRTLE] =
    {
#line 7357
        .trainerName = _("TERRY"),
#line 7358
        .trainerClass = TRAINER_CLASS_RIVAL_LATE,
#line 7359
        .trainerPic = TRAINER_PIC_RIVAL_LATE,
        .encounterMusic_gender =
#line 7361
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 7362
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 7363
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .partySize = 4,
        .party = (const struct TrainerMon[])
        {
            {
#line 7365
            .species = SPECIES_PIDGEOTTO,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7367
            .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
#line 7366
            .lvl = 19,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 7369
            .species = SPECIES_RATICATE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7371
            .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
#line 7370
            .lvl = 16,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 7373
            .species = SPECIES_KADABRA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7375
            .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
#line 7374
            .lvl = 18,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 7377
            .species = SPECIES_WARTORTLE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7379
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 7378
            .lvl = 20,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 7381
    [DIFFICULTY_NORMAL][TRAINER_RIVAL_SS_ANNE_BULBASAUR] =
    {
#line 7382
        .trainerName = _("TERRY"),
#line 7383
        .trainerClass = TRAINER_CLASS_RIVAL_LATE,
#line 7384
        .trainerPic = TRAINER_PIC_RIVAL_LATE,
        .encounterMusic_gender =
#line 7386
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 7387
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 7388
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .partySize = 4,
        .party = (const struct TrainerMon[])
        {
            {
#line 7390
            .species = SPECIES_PIDGEOTTO,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7392
            .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
#line 7391
            .lvl = 19,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 7394
            .species = SPECIES_RATICATE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7396
            .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
#line 7395
            .lvl = 16,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 7398
            .species = SPECIES_KADABRA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7400
            .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
#line 7399
            .lvl = 18,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 7402
            .species = SPECIES_IVYSAUR,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7404
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 7403
            .lvl = 20,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 7406
    [DIFFICULTY_NORMAL][TRAINER_RIVAL_SS_ANNE_CHARMANDER] =
    {
#line 7407
        .trainerName = _("TERRY"),
#line 7408
        .trainerClass = TRAINER_CLASS_RIVAL_LATE,
#line 7409
        .trainerPic = TRAINER_PIC_RIVAL_LATE,
        .encounterMusic_gender =
#line 7411
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 7412
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 7413
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .partySize = 4,
        .party = (const struct TrainerMon[])
        {
            {
#line 7415
            .species = SPECIES_PIDGEOTTO,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7417
            .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
#line 7416
            .lvl = 19,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 7419
            .species = SPECIES_RATICATE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7421
            .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
#line 7420
            .lvl = 16,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 7423
            .species = SPECIES_KADABRA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7425
            .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
#line 7424
            .lvl = 18,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 7427
            .species = SPECIES_CHARMELEON,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7429
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 7428
            .lvl = 20,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 7431
    [DIFFICULTY_NORMAL][TRAINER_RIVAL_POKEMON_TOWER_SQUIRTLE] =
    {
#line 7432
        .trainerName = _("TERRY"),
#line 7433
        .trainerClass = TRAINER_CLASS_RIVAL_LATE,
#line 7434
        .trainerPic = TRAINER_PIC_RIVAL_LATE,
        .encounterMusic_gender =
#line 7436
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 7437
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 7438
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .partySize = 5,
        .party = (const struct TrainerMon[])
        {
            {
#line 7440
            .species = SPECIES_PIDGEOTTO,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7442
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 7441
            .lvl = 25,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 7444
            .species = SPECIES_GROWLITHE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7446
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 7445
            .lvl = 23,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 7448
            .species = SPECIES_EXEGGCUTE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7450
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 7449
            .lvl = 22,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 7452
            .species = SPECIES_KADABRA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7454
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 7453
            .lvl = 20,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 7456
            .species = SPECIES_WARTORTLE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7458
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 7457
            .lvl = 25,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 7460
    [DIFFICULTY_NORMAL][TRAINER_RIVAL_POKEMON_TOWER_BULBASAUR] =
    {
#line 7461
        .trainerName = _("TERRY"),
#line 7462
        .trainerClass = TRAINER_CLASS_RIVAL_LATE,
#line 7463
        .trainerPic = TRAINER_PIC_RIVAL_LATE,
        .encounterMusic_gender =
#line 7465
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 7466
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 7467
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .partySize = 5,
        .party = (const struct TrainerMon[])
        {
            {
#line 7469
            .species = SPECIES_PIDGEOTTO,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7471
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 7470
            .lvl = 25,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 7473
            .species = SPECIES_GYARADOS,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7475
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 7474
            .lvl = 23,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 7477
            .species = SPECIES_GROWLITHE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7479
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 7478
            .lvl = 22,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 7481
            .species = SPECIES_KADABRA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7483
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 7482
            .lvl = 20,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 7485
            .species = SPECIES_IVYSAUR,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7487
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 7486
            .lvl = 25,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 7489
    [DIFFICULTY_NORMAL][TRAINER_RIVAL_POKEMON_TOWER_CHARMANDER] =
    {
#line 7490
        .trainerName = _("TERRY"),
#line 7491
        .trainerClass = TRAINER_CLASS_RIVAL_LATE,
#line 7492
        .trainerPic = TRAINER_PIC_RIVAL_LATE,
        .encounterMusic_gender =
#line 7494
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 7495
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 7496
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .partySize = 5,
        .party = (const struct TrainerMon[])
        {
            {
#line 7498
            .species = SPECIES_PIDGEOTTO,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7500
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 7499
            .lvl = 25,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 7502
            .species = SPECIES_EXEGGCUTE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7504
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 7503
            .lvl = 23,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 7506
            .species = SPECIES_GYARADOS,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7508
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 7507
            .lvl = 22,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 7510
            .species = SPECIES_KADABRA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7512
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 7511
            .lvl = 20,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 7514
            .species = SPECIES_CHARMELEON,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7516
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 7515
            .lvl = 25,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 7518
    [DIFFICULTY_NORMAL][TRAINER_RIVAL_SILPH_SQUIRTLE] =
    {
#line 7519
        .trainerName = _("TERRY"),
#line 7520
        .trainerClass = TRAINER_CLASS_RIVAL_LATE,
#line 7521
        .trainerPic = TRAINER_PIC_RIVAL_LATE,
        .encounterMusic_gender =
#line 7523
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 7524
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 7525
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .partySize = 5,
        .party = (const struct TrainerMon[])
        {
            {
#line 7527
            .species = SPECIES_PIDGEOT,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7529
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 7528
            .lvl = 37,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 7531
            .species = SPECIES_GROWLITHE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7533
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 7532
            .lvl = 38,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 7535
            .species = SPECIES_EXEGGCUTE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7537
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 7536
            .lvl = 35,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 7539
            .species = SPECIES_ALAKAZAM,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7541
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 7540
            .lvl = 35,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 7543
            .species = SPECIES_BLASTOISE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7545
            .iv = TRAINER_PARTY_IVS(18, 18, 18, 18, 18, 18),
#line 7544
            .lvl = 40,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 7547
    [DIFFICULTY_NORMAL][TRAINER_RIVAL_SILPH_BULBASAUR] =
    {
#line 7548
        .trainerName = _("TERRY"),
#line 7549
        .trainerClass = TRAINER_CLASS_RIVAL_LATE,
#line 7550
        .trainerPic = TRAINER_PIC_RIVAL_LATE,
        .encounterMusic_gender =
#line 7552
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 7553
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 7554
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .partySize = 5,
        .party = (const struct TrainerMon[])
        {
            {
#line 7556
            .species = SPECIES_PIDGEOT,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7558
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 7557
            .lvl = 37,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 7560
            .species = SPECIES_GYARADOS,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7562
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 7561
            .lvl = 38,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 7564
            .species = SPECIES_GROWLITHE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7566
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 7565
            .lvl = 35,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 7568
            .species = SPECIES_ALAKAZAM,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7570
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 7569
            .lvl = 35,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 7572
            .species = SPECIES_VENUSAUR,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7574
            .iv = TRAINER_PARTY_IVS(18, 18, 18, 18, 18, 18),
#line 7573
            .lvl = 40,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 7576
    [DIFFICULTY_NORMAL][TRAINER_RIVAL_SILPH_CHARMANDER] =
    {
#line 7577
        .trainerName = _("TERRY"),
#line 7578
        .trainerClass = TRAINER_CLASS_RIVAL_LATE,
#line 7579
        .trainerPic = TRAINER_PIC_RIVAL_LATE,
        .encounterMusic_gender =
#line 7581
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 7582
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 7583
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .partySize = 5,
        .party = (const struct TrainerMon[])
        {
            {
#line 7585
            .species = SPECIES_PIDGEOT,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7587
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 7586
            .lvl = 37,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 7589
            .species = SPECIES_EXEGGCUTE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7591
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 7590
            .lvl = 38,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 7593
            .species = SPECIES_GYARADOS,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7595
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 7594
            .lvl = 35,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 7597
            .species = SPECIES_ALAKAZAM,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7599
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 7598
            .lvl = 35,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 7601
            .species = SPECIES_CHARIZARD,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7603
            .iv = TRAINER_PARTY_IVS(18, 18, 18, 18, 18, 18),
#line 7602
            .lvl = 40,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 7605
    [DIFFICULTY_NORMAL][TRAINER_RIVAL_ROUTE22_LATE_SQUIRTLE] =
    {
#line 7606
        .trainerName = _("TERRY"),
#line 7607
        .trainerClass = TRAINER_CLASS_RIVAL_LATE,
#line 7608
        .trainerPic = TRAINER_PIC_RIVAL_LATE,
        .encounterMusic_gender =
#line 7610
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 7611
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 7612
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .partySize = 6,
        .party = (const struct TrainerMon[])
        {
            {
#line 7614
            .species = SPECIES_PIDGEOT,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7616
            .iv = TRAINER_PARTY_IVS(18, 18, 18, 18, 18, 18),
#line 7615
            .lvl = 47,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 7617
                MOVE_FEATHER_DANCE,
                MOVE_WING_ATTACK,
                MOVE_GUST,
                MOVE_QUICK_ATTACK,
            },
            },
            {
#line 7622
            .species = SPECIES_RHYHORN,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7624
            .iv = TRAINER_PARTY_IVS(18, 18, 18, 18, 18, 18),
#line 7623
            .lvl = 45,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 7625
                MOVE_TAKE_DOWN,
                MOVE_HORN_DRILL,
                MOVE_ROCK_BLAST,
                MOVE_FURY_ATTACK,
            },
            },
            {
#line 7630
            .species = SPECIES_GROWLITHE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7632
            .iv = TRAINER_PARTY_IVS(18, 18, 18, 18, 18, 18),
#line 7631
            .lvl = 45,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 7633
                MOVE_FLAME_WHEEL,
                MOVE_TAKE_DOWN,
                MOVE_LEER,
                MOVE_AGILITY,
            },
            },
            {
#line 7638
            .species = SPECIES_EXEGGCUTE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7640
            .iv = TRAINER_PARTY_IVS(18, 18, 18, 18, 18, 18),
#line 7639
            .lvl = 45,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 7641
                MOVE_SOLAR_BEAM,
                MOVE_SLEEP_POWDER,
                MOVE_POISON_POWDER,
                MOVE_STUN_SPORE,
            },
            },
            {
#line 7646
            .species = SPECIES_ALAKAZAM,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7648
            .iv = TRAINER_PARTY_IVS(18, 18, 18, 18, 18, 18),
#line 7647
            .lvl = 47,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 7649
                MOVE_PSYCHIC,
                MOVE_CALM_MIND,
                MOVE_FUTURE_SIGHT,
                MOVE_DISABLE,
            },
            },
            {
#line 7654
            .species = SPECIES_BLASTOISE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7656
            .iv = TRAINER_PARTY_IVS(30, 30, 30, 30, 30, 30),
#line 7655
            .lvl = 53,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 7657
                MOVE_WATER_GUN,
                MOVE_RAIN_DANCE,
                MOVE_BITE,
                MOVE_RAPID_SPIN,
            },
            },
        },
    },
#line 7662
    [DIFFICULTY_NORMAL][TRAINER_RIVAL_ROUTE22_LATE_BULBASAUR] =
    {
#line 7663
        .trainerName = _("TERRY"),
#line 7664
        .trainerClass = TRAINER_CLASS_RIVAL_LATE,
#line 7665
        .trainerPic = TRAINER_PIC_RIVAL_LATE,
        .encounterMusic_gender =
#line 7667
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 7668
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 7669
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .partySize = 6,
        .party = (const struct TrainerMon[])
        {
            {
#line 7671
            .species = SPECIES_PIDGEOT,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7673
            .iv = TRAINER_PARTY_IVS(18, 18, 18, 18, 18, 18),
#line 7672
            .lvl = 47,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 7674
                MOVE_FEATHER_DANCE,
                MOVE_WING_ATTACK,
                MOVE_GUST,
                MOVE_QUICK_ATTACK,
            },
            },
            {
#line 7679
            .species = SPECIES_RHYHORN,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7681
            .iv = TRAINER_PARTY_IVS(18, 18, 18, 18, 18, 18),
#line 7680
            .lvl = 45,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 7682
                MOVE_TAKE_DOWN,
                MOVE_HORN_DRILL,
                MOVE_ROCK_BLAST,
                MOVE_FURY_ATTACK,
            },
            },
            {
#line 7687
            .species = SPECIES_GYARADOS,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7689
            .iv = TRAINER_PARTY_IVS(18, 18, 18, 18, 18, 18),
#line 7688
            .lvl = 45,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 7690
                MOVE_HYDRO_PUMP,
                MOVE_TWISTER,
                MOVE_LEER,
                MOVE_RAIN_DANCE,
            },
            },
            {
#line 7695
            .species = SPECIES_GROWLITHE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7697
            .iv = TRAINER_PARTY_IVS(18, 18, 18, 18, 18, 18),
#line 7696
            .lvl = 45,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 7698
                MOVE_FLAME_WHEEL,
                MOVE_TAKE_DOWN,
                MOVE_LEER,
                MOVE_AGILITY,
            },
            },
            {
#line 7703
            .species = SPECIES_ALAKAZAM,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7705
            .iv = TRAINER_PARTY_IVS(18, 18, 18, 18, 18, 18),
#line 7704
            .lvl = 47,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 7706
                MOVE_PSYCHIC,
                MOVE_CALM_MIND,
                MOVE_FUTURE_SIGHT,
                MOVE_DISABLE,
            },
            },
            {
#line 7711
            .species = SPECIES_VENUSAUR,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7713
            .iv = TRAINER_PARTY_IVS(30, 30, 30, 30, 30, 30),
#line 7712
            .lvl = 53,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 7714
                MOVE_RAZOR_LEAF,
                MOVE_SWEET_SCENT,
                MOVE_GROWTH,
                MOVE_SYNTHESIS,
            },
            },
        },
    },
#line 7719
    [DIFFICULTY_NORMAL][TRAINER_RIVAL_ROUTE22_LATE_CHARMANDER] =
    {
#line 7720
        .trainerName = _("TERRY"),
#line 7721
        .trainerClass = TRAINER_CLASS_RIVAL_LATE,
#line 7722
        .trainerPic = TRAINER_PIC_RIVAL_LATE,
        .encounterMusic_gender =
#line 7724
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 7725
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 7726
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .partySize = 6,
        .party = (const struct TrainerMon[])
        {
            {
#line 7728
            .species = SPECIES_PIDGEOT,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7730
            .iv = TRAINER_PARTY_IVS(18, 18, 18, 18, 18, 18),
#line 7729
            .lvl = 47,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 7731
                MOVE_FEATHER_DANCE,
                MOVE_WING_ATTACK,
                MOVE_GUST,
                MOVE_QUICK_ATTACK,
            },
            },
            {
#line 7736
            .species = SPECIES_RHYHORN,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7738
            .iv = TRAINER_PARTY_IVS(18, 18, 18, 18, 18, 18),
#line 7737
            .lvl = 45,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 7739
                MOVE_TAKE_DOWN,
                MOVE_HORN_DRILL,
                MOVE_ROCK_BLAST,
                MOVE_FURY_ATTACK,
            },
            },
            {
#line 7744
            .species = SPECIES_EXEGGCUTE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7746
            .iv = TRAINER_PARTY_IVS(18, 18, 18, 18, 18, 18),
#line 7745
            .lvl = 45,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 7747
                MOVE_SOLAR_BEAM,
                MOVE_SLEEP_POWDER,
                MOVE_POISON_POWDER,
                MOVE_STUN_SPORE,
            },
            },
            {
#line 7752
            .species = SPECIES_GYARADOS,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7754
            .iv = TRAINER_PARTY_IVS(18, 18, 18, 18, 18, 18),
#line 7753
            .lvl = 45,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 7755
                MOVE_HYDRO_PUMP,
                MOVE_TWISTER,
                MOVE_LEER,
                MOVE_RAIN_DANCE,
            },
            },
            {
#line 7760
            .species = SPECIES_ALAKAZAM,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7762
            .iv = TRAINER_PARTY_IVS(18, 18, 18, 18, 18, 18),
#line 7761
            .lvl = 47,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 7763
                MOVE_PSYCHIC,
                MOVE_CALM_MIND,
                MOVE_FUTURE_SIGHT,
                MOVE_DISABLE,
            },
            },
            {
#line 7768
            .species = SPECIES_CHARIZARD,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7770
            .iv = TRAINER_PARTY_IVS(30, 30, 30, 30, 30, 30),
#line 7769
            .lvl = 53,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 7771
                MOVE_FLAMETHROWER,
                MOVE_WING_ATTACK,
                MOVE_SLASH,
                MOVE_SCARY_FACE,
            },
            },
        },
    },
#line 7776
    [DIFFICULTY_NORMAL][TRAINER_CHAMPION_FIRST_SQUIRTLE] =
    {
#line 7777
        .trainerName = _("TERRY"),
#line 7778
        .trainerClass = TRAINER_CLASS_CHAMPION,
#line 7779
        .trainerPic = TRAINER_PIC_CHAMPION_RIVAL,
        .encounterMusic_gender =
#line 7781
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 7782
        .items = { ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_FULL_RESTORE },
#line 7783
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 7784
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
#line 7785
        .mugshotColor = MUGSHOT_COLOR_YELLOW,
        .partySize = 6,
        .party = (const struct TrainerMon[])
        {
            {
#line 7787
            .species = SPECIES_PIDGEOT,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7789
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 7788
            .lvl = 59,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 7790
                MOVE_AERIAL_ACE,
                MOVE_FEATHER_DANCE,
                MOVE_SAND_ATTACK,
                MOVE_WHIRLWIND,
            },
            },
            {
#line 7795
            .species = SPECIES_ALAKAZAM,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7797
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 7796
            .lvl = 57,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 7798
                MOVE_PSYCHIC,
                MOVE_FUTURE_SIGHT,
                MOVE_RECOVER,
                MOVE_REFLECT,
            },
            },
            {
#line 7803
            .species = SPECIES_RHYDON,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7805
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 7804
            .lvl = 59,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 7806
                MOVE_TAKE_DOWN,
                MOVE_EARTHQUAKE,
                MOVE_ROCK_TOMB,
                MOVE_SCARY_FACE,
            },
            },
            {
#line 7811
            .species = SPECIES_ARCANINE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7813
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 7812
            .lvl = 59,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 7814
                MOVE_EXTREME_SPEED,
                MOVE_FLAMETHROWER,
                MOVE_ROAR,
                MOVE_BITE,
            },
            },
            {
#line 7819
            .species = SPECIES_EXEGGUTOR,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7821
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 7820
            .lvl = 61,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 7822
                MOVE_GIGA_DRAIN,
                MOVE_EGG_BOMB,
                MOVE_SLEEP_POWDER,
                MOVE_LIGHT_SCREEN,
            },
            },
            {
#line 7827
            .species = SPECIES_BLASTOISE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7827
            .heldItem = ITEM_SITRUS_BERRY,
#line 7829
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 7828
            .lvl = 63,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 7830
                MOVE_HYDRO_PUMP,
                MOVE_RAIN_DANCE,
                MOVE_SKULL_BASH,
                MOVE_BITE,
            },
            },
        },
    },
#line 7835
    [DIFFICULTY_NORMAL][TRAINER_CHAMPION_FIRST_BULBASAUR] =
    {
#line 7836
        .trainerName = _("TERRY"),
#line 7837
        .trainerClass = TRAINER_CLASS_CHAMPION,
#line 7838
        .trainerPic = TRAINER_PIC_CHAMPION_RIVAL,
        .encounterMusic_gender =
#line 7840
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 7841
        .items = { ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_FULL_RESTORE },
#line 7842
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 7843
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
#line 7844
        .mugshotColor = MUGSHOT_COLOR_YELLOW,
        .partySize = 6,
        .party = (const struct TrainerMon[])
        {
            {
#line 7846
            .species = SPECIES_PIDGEOT,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7848
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 7847
            .lvl = 59,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 7849
                MOVE_AERIAL_ACE,
                MOVE_FEATHER_DANCE,
                MOVE_SAND_ATTACK,
                MOVE_WHIRLWIND,
            },
            },
            {
#line 7854
            .species = SPECIES_ALAKAZAM,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7856
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 7855
            .lvl = 57,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 7857
                MOVE_PSYCHIC,
                MOVE_FUTURE_SIGHT,
                MOVE_RECOVER,
                MOVE_REFLECT,
            },
            },
            {
#line 7862
            .species = SPECIES_RHYDON,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7864
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 7863
            .lvl = 59,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 7865
                MOVE_TAKE_DOWN,
                MOVE_EARTHQUAKE,
                MOVE_ROCK_TOMB,
                MOVE_SCARY_FACE,
            },
            },
            {
#line 7870
            .species = SPECIES_GYARADOS,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7872
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 7871
            .lvl = 59,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 7873
                MOVE_HYDRO_PUMP,
                MOVE_DRAGON_RAGE,
                MOVE_BITE,
                MOVE_THRASH,
            },
            },
            {
#line 7878
            .species = SPECIES_ARCANINE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7880
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 7879
            .lvl = 61,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 7881
                MOVE_EXTREME_SPEED,
                MOVE_FLAMETHROWER,
                MOVE_ROAR,
                MOVE_BITE,
            },
            },
            {
#line 7886
            .species = SPECIES_VENUSAUR,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7886
            .heldItem = ITEM_SITRUS_BERRY,
#line 7888
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 7887
            .lvl = 63,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 7889
                MOVE_SOLAR_BEAM,
                MOVE_SYNTHESIS,
                MOVE_SUNNY_DAY,
                MOVE_GROWTH,
            },
            },
        },
    },
#line 7894
    [DIFFICULTY_NORMAL][TRAINER_CHAMPION_FIRST_CHARMANDER] =
    {
#line 7895
        .trainerName = _("TERRY"),
#line 7896
        .trainerClass = TRAINER_CLASS_CHAMPION,
#line 7897
        .trainerPic = TRAINER_PIC_CHAMPION_RIVAL,
        .encounterMusic_gender =
#line 7899
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 7900
        .items = { ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_FULL_RESTORE },
#line 7901
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 7902
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
#line 7903
        .mugshotColor = MUGSHOT_COLOR_YELLOW,
        .partySize = 6,
        .party = (const struct TrainerMon[])
        {
            {
#line 7905
            .species = SPECIES_PIDGEOT,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7907
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 7906
            .lvl = 59,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 7908
                MOVE_AERIAL_ACE,
                MOVE_FEATHER_DANCE,
                MOVE_SAND_ATTACK,
                MOVE_WHIRLWIND,
            },
            },
            {
#line 7913
            .species = SPECIES_ALAKAZAM,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7915
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 7914
            .lvl = 57,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 7916
                MOVE_PSYCHIC,
                MOVE_FUTURE_SIGHT,
                MOVE_RECOVER,
                MOVE_REFLECT,
            },
            },
            {
#line 7921
            .species = SPECIES_RHYDON,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7923
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 7922
            .lvl = 59,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 7924
                MOVE_TAKE_DOWN,
                MOVE_EARTHQUAKE,
                MOVE_ROCK_TOMB,
                MOVE_SCARY_FACE,
            },
            },
            {
#line 7929
            .species = SPECIES_EXEGGUTOR,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7931
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 7930
            .lvl = 59,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 7932
                MOVE_GIGA_DRAIN,
                MOVE_EGG_BOMB,
                MOVE_SLEEP_POWDER,
                MOVE_LIGHT_SCREEN,
            },
            },
            {
#line 7937
            .species = SPECIES_GYARADOS,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7939
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 7938
            .lvl = 61,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 7940
                MOVE_HYDRO_PUMP,
                MOVE_DRAGON_RAGE,
                MOVE_BITE,
                MOVE_THRASH,
            },
            },
            {
#line 7945
            .species = SPECIES_CHARIZARD,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7945
            .heldItem = ITEM_SITRUS_BERRY,
#line 7947
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 7946
            .lvl = 63,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 7948
                MOVE_FIRE_BLAST,
                MOVE_AERIAL_ACE,
                MOVE_SLASH,
                MOVE_FIRE_SPIN,
            },
            },
        },
    },
#line 7953
    [DIFFICULTY_NORMAL][TRAINER_CHANNELER_PATRICIA] =
    {
#line 7954
        .trainerName = _("PATRICIA"),
#line 7955
        .trainerClass = TRAINER_CLASS_CHANNELER,
#line 7956
        .trainerPic = TRAINER_PIC_CHANNELER,
        .encounterMusic_gender =
#line 7958
            TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
#line 7959
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 7960
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 7962
            .species = SPECIES_GASTLY,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7964
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 7963
            .lvl = 22,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 7966
    [DIFFICULTY_NORMAL][TRAINER_CHANNELER_CARLY] =
    {
#line 7967
        .trainerName = _("CARLY"),
#line 7968
        .trainerClass = TRAINER_CLASS_CHANNELER,
#line 7969
        .trainerPic = TRAINER_PIC_CHANNELER,
        .encounterMusic_gender =
#line 7971
            TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
#line 7972
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 7973
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 7975
            .species = SPECIES_GASTLY,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7977
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 7976
            .lvl = 24,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 7979
    [DIFFICULTY_NORMAL][TRAINER_CHANNELER_HOPE] =
    {
#line 7980
        .trainerName = _("HOPE"),
#line 7981
        .trainerClass = TRAINER_CLASS_CHANNELER,
#line 7982
        .trainerPic = TRAINER_PIC_CHANNELER,
        .encounterMusic_gender =
#line 7984
            TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
#line 7985
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 7986
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 7988
            .species = SPECIES_GASTLY,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7990
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 7989
            .lvl = 23,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 7992
    [DIFFICULTY_NORMAL][TRAINER_CHANNELER_PAULA] =
    {
#line 7993
        .trainerName = _("PAULA"),
#line 7994
        .trainerClass = TRAINER_CLASS_CHANNELER,
#line 7995
        .trainerPic = TRAINER_PIC_CHANNELER,
        .encounterMusic_gender =
#line 7997
            TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
#line 7998
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 7999
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 8001
            .species = SPECIES_GASTLY,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8003
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 8002
            .lvl = 24,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 8005
    [DIFFICULTY_NORMAL][TRAINER_CHANNELER_LAUREL] =
    {
#line 8006
        .trainerName = _("LAUREL"),
#line 8007
        .trainerClass = TRAINER_CLASS_CHANNELER,
#line 8008
        .trainerPic = TRAINER_PIC_CHANNELER,
        .encounterMusic_gender =
#line 8010
            TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
#line 8011
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 8012
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 8014
            .species = SPECIES_GASTLY,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8016
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 8015
            .lvl = 23,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 8018
            .species = SPECIES_GASTLY,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8020
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 8019
            .lvl = 23,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 8022
    [DIFFICULTY_NORMAL][TRAINER_CHANNELER_JODY] =
    {
#line 8023
        .trainerName = _("JODY"),
#line 8024
        .trainerClass = TRAINER_CLASS_CHANNELER,
#line 8025
        .trainerPic = TRAINER_PIC_CHANNELER,
        .encounterMusic_gender =
#line 8027
            TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
#line 8028
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 8029
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 8031
            .species = SPECIES_GASTLY,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8033
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 8032
            .lvl = 22,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 8035
    [DIFFICULTY_NORMAL][TRAINER_CHANNELER_TAMMY] =
    {
#line 8036
        .trainerName = _("TAMMY"),
#line 8037
        .trainerClass = TRAINER_CLASS_CHANNELER,
#line 8038
        .trainerPic = TRAINER_PIC_CHANNELER,
        .encounterMusic_gender =
#line 8040
            TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
#line 8041
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 8042
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 8044
            .species = SPECIES_HAUNTER,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8046
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 8045
            .lvl = 23,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 8048
    [DIFFICULTY_NORMAL][TRAINER_CHANNELER_RUTH] =
    {
#line 8049
        .trainerName = _("RUTH"),
#line 8050
        .trainerClass = TRAINER_CLASS_CHANNELER,
#line 8051
        .trainerPic = TRAINER_PIC_CHANNELER,
        .encounterMusic_gender =
#line 8053
            TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
#line 8054
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 8055
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 8057
            .species = SPECIES_GASTLY,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8059
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 8058
            .lvl = 22,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 8061
    [DIFFICULTY_NORMAL][TRAINER_CHANNELER_KARINA] =
    {
#line 8062
        .trainerName = _("KARINA"),
#line 8063
        .trainerClass = TRAINER_CLASS_CHANNELER,
#line 8064
        .trainerPic = TRAINER_PIC_CHANNELER,
        .encounterMusic_gender =
#line 8066
            TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
#line 8067
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 8068
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 8070
            .species = SPECIES_GASTLY,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8072
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 8071
            .lvl = 24,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 8074
    [DIFFICULTY_NORMAL][TRAINER_CHANNELER_JANAE] =
    {
#line 8075
        .trainerName = _("JANAE"),
#line 8076
        .trainerClass = TRAINER_CLASS_CHANNELER,
#line 8077
        .trainerPic = TRAINER_PIC_CHANNELER,
        .encounterMusic_gender =
#line 8079
            TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
#line 8080
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 8081
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 8083
            .species = SPECIES_GASTLY,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8085
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 8084
            .lvl = 22,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 8087
    [DIFFICULTY_NORMAL][TRAINER_CHANNELER_ANGELICA] =
    {
#line 8088
        .trainerName = _("ANGELICA"),
#line 8089
        .trainerClass = TRAINER_CLASS_CHANNELER,
#line 8090
        .trainerPic = TRAINER_PIC_CHANNELER,
        .encounterMusic_gender =
#line 8092
            TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
#line 8093
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 8094
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 8096
            .species = SPECIES_GASTLY,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8098
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 8097
            .lvl = 22,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 8100
            .species = SPECIES_GASTLY,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8102
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 8101
            .lvl = 22,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 8104
            .species = SPECIES_GASTLY,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8106
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 8105
            .lvl = 22,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 8108
    [DIFFICULTY_NORMAL][TRAINER_CHANNELER_EMILIA] =
    {
#line 8109
        .trainerName = _("EMILIA"),
#line 8110
        .trainerClass = TRAINER_CLASS_CHANNELER,
#line 8111
        .trainerPic = TRAINER_PIC_CHANNELER,
        .encounterMusic_gender =
#line 8113
            TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
#line 8114
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 8115
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 8117
            .species = SPECIES_GASTLY,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8119
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 8118
            .lvl = 24,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 8121
    [DIFFICULTY_NORMAL][TRAINER_CHANNELER_JENNIFER] =
    {
#line 8122
        .trainerName = _("JENNIFER"),
#line 8123
        .trainerClass = TRAINER_CLASS_CHANNELER,
#line 8124
        .trainerPic = TRAINER_PIC_CHANNELER,
        .encounterMusic_gender =
#line 8126
            TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
#line 8127
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 8128
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 8130
            .species = SPECIES_GASTLY,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8132
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 8131
            .lvl = 24,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 8134
    [DIFFICULTY_NORMAL][TRAINER_CHANNELER_AMANDA] =
    {
#line 8135
        .trainerName = _("AMANDA"),
#line 8136
        .trainerClass = TRAINER_CLASS_CHANNELER,
#line 8137
        .trainerPic = TRAINER_PIC_CHANNELER,
        .encounterMusic_gender =
#line 8139
            TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
#line 8140
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 8141
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 8143
            .species = SPECIES_GASTLY,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8145
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 8144
            .lvl = 34,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 8147
            .species = SPECIES_HAUNTER,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8149
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 8148
            .lvl = 34,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 8151
    [DIFFICULTY_NORMAL][TRAINER_CHANNELER_STACY] =
    {
#line 8152
        .trainerName = _("STACY"),
#line 8153
        .trainerClass = TRAINER_CLASS_CHANNELER,
#line 8154
        .trainerPic = TRAINER_PIC_CHANNELER,
        .encounterMusic_gender =
#line 8156
            TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
#line 8157
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 8158
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 8160
            .species = SPECIES_HAUNTER,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8162
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 8161
            .lvl = 38,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 8164
    [DIFFICULTY_NORMAL][TRAINER_CHANNELER_TASHA] =
    {
#line 8165
        .trainerName = _("TASHA"),
#line 8166
        .trainerClass = TRAINER_CLASS_CHANNELER,
#line 8167
        .trainerPic = TRAINER_PIC_CHANNELER,
        .encounterMusic_gender =
#line 8169
            TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
#line 8170
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 8171
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 8173
            .species = SPECIES_GASTLY,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8175
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 8174
            .lvl = 33,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 8177
            .species = SPECIES_GASTLY,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8179
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 8178
            .lvl = 33,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 8181
            .species = SPECIES_HAUNTER,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8183
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 8182
            .lvl = 33,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 8185
    [DIFFICULTY_NORMAL][TRAINER_HIKER_JEREMY] =
    {
#line 8186
        .trainerName = _("JEREMY"),
#line 8187
        .trainerClass = TRAINER_CLASS_HIKER,
#line 8188
        .trainerPic = TRAINER_PIC_HIKER,
        .encounterMusic_gender =
#line 8190
            TRAINER_ENCOUNTER_MUSIC_HIKER,
#line 8191
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 8192
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 8194
            .species = SPECIES_MACHOP,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8196
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 8195
            .lvl = 20,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 8198
            .species = SPECIES_ONIX,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8200
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 8199
            .lvl = 20,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 8202
    [DIFFICULTY_NORMAL][TRAINER_PICNICKER_ALMA] =
    {
#line 8203
        .trainerName = _("ALMA"),
#line 8204
        .trainerClass = TRAINER_CLASS_PICNICKER,
#line 8205
        .trainerPic = TRAINER_PIC_PICNICKER,
        .encounterMusic_gender =
#line 8207
            TRAINER_ENCOUNTER_MUSIC_GIRL,
#line 8208
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 8209
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 8211
            .species = SPECIES_GOLDEEN,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8213
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 8212
            .lvl = 28,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 8215
            .species = SPECIES_POLIWAG,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8217
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 8216
            .lvl = 28,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 8219
            .species = SPECIES_HORSEA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8221
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 8220
            .lvl = 28,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 8223
    [DIFFICULTY_NORMAL][TRAINER_PICNICKER_SUSIE] =
    {
#line 8224
        .trainerName = _("SUSIE"),
#line 8225
        .trainerClass = TRAINER_CLASS_PICNICKER,
#line 8226
        .trainerPic = TRAINER_PIC_PICNICKER,
        .encounterMusic_gender =
#line 8228
            TRAINER_ENCOUNTER_MUSIC_GIRL,
#line 8229
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 8230
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 5,
        .party = (const struct TrainerMon[])
        {
            {
#line 8232
            .species = SPECIES_PIDGEY,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8234
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 8233
            .lvl = 24,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 8236
            .species = SPECIES_MEOWTH,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8238
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 8237
            .lvl = 24,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 8240
            .species = SPECIES_RATTATA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8242
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 8241
            .lvl = 24,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 8244
            .species = SPECIES_PIKACHU,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8246
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 8245
            .lvl = 24,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 8248
            .species = SPECIES_MEOWTH,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8250
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 8249
            .lvl = 24,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 8252
    [DIFFICULTY_NORMAL][TRAINER_PICNICKER_VALERIE] =
    {
#line 8253
        .trainerName = _("VALERIE"),
#line 8254
        .trainerClass = TRAINER_CLASS_PICNICKER,
#line 8255
        .trainerPic = TRAINER_PIC_PICNICKER,
        .encounterMusic_gender =
#line 8257
            TRAINER_ENCOUNTER_MUSIC_GIRL,
#line 8258
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 8259
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 8261
            .species = SPECIES_POLIWAG,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8263
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 8262
            .lvl = 30,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 8265
            .species = SPECIES_POLIWAG,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8267
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 8266
            .lvl = 30,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 8269
    [DIFFICULTY_NORMAL][TRAINER_PICNICKER_GWEN] =
    {
#line 8270
        .trainerName = _("GWEN"),
#line 8271
        .trainerClass = TRAINER_CLASS_PICNICKER,
#line 8272
        .trainerPic = TRAINER_PIC_PICNICKER,
        .encounterMusic_gender =
#line 8274
            TRAINER_ENCOUNTER_MUSIC_GIRL,
#line 8275
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 8276
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 4,
        .party = (const struct TrainerMon[])
        {
            {
#line 8278
            .species = SPECIES_PIDGEY,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8280
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 8279
            .lvl = 27,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 8282
            .species = SPECIES_MEOWTH,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8284
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 8283
            .lvl = 27,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 8286
            .species = SPECIES_PIDGEY,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8288
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 8287
            .lvl = 27,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 8290
            .species = SPECIES_PIDGEOTTO,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8292
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 8291
            .lvl = 27,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 8294
    [DIFFICULTY_NORMAL][TRAINER_BIKER_VIRGIL] =
    {
#line 8295
        .trainerName = _("VIRGIL"),
#line 8296
        .trainerClass = TRAINER_CLASS_BIKER,
#line 8297
        .trainerPic = TRAINER_PIC_BIKER,
        .encounterMusic_gender =
#line 8299
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 8300
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 8301
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 8303
            .species = SPECIES_WEEZING,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8305
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 8304
            .lvl = 28,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 8306
                MOVE_SMOKESCREEN,
                MOVE_SLUDGE,
                MOVE_SMOG,
                MOVE_TACKLE,
            },
            },
            {
#line 8311
            .species = SPECIES_KOFFING,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8313
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 8312
            .lvl = 28,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 8314
                MOVE_SMOKESCREEN,
                MOVE_SLUDGE,
                MOVE_SMOG,
                MOVE_TACKLE,
            },
            },
            {
#line 8319
            .species = SPECIES_WEEZING,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8321
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 8320
            .lvl = 28,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 8322
                MOVE_SMOKESCREEN,
                MOVE_SLUDGE,
                MOVE_SMOG,
                MOVE_TACKLE,
            },
            },
        },
    },
#line 8327
    [DIFFICULTY_NORMAL][TRAINER_CAMPER_FLINT] =
    {
#line 8328
        .trainerName = _("FLINT"),
#line 8329
        .trainerClass = TRAINER_CLASS_CAMPER,
#line 8330
        .trainerPic = TRAINER_PIC_CAMPER,
        .encounterMusic_gender =
#line 8332
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 8333
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 8334
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 8336
            .species = SPECIES_RATTATA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8338
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 8337
            .lvl = 14,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 8340
            .species = SPECIES_EKANS,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8342
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 8341
            .lvl = 14,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 8344
    [DIFFICULTY_NORMAL][TRAINER_PICNICKER_MISSY] =
    {
#line 8345
        .trainerName = _("MISSY"),
#line 8346
        .trainerClass = TRAINER_CLASS_PICNICKER,
#line 8347
        .trainerPic = TRAINER_PIC_PICNICKER,
        .encounterMusic_gender =
#line 8349
            TRAINER_ENCOUNTER_MUSIC_GIRL,
#line 8350
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 8351
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 8353
            .species = SPECIES_GOLDEEN,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8355
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 8354
            .lvl = 31,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 8357
            .species = SPECIES_SEAKING,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8359
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 8358
            .lvl = 31,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 8361
    [DIFFICULTY_NORMAL][TRAINER_PICNICKER_IRENE] =
    {
#line 8362
        .trainerName = _("IRENE"),
#line 8363
        .trainerClass = TRAINER_CLASS_PICNICKER,
#line 8364
        .trainerPic = TRAINER_PIC_PICNICKER,
        .encounterMusic_gender =
#line 8366
            TRAINER_ENCOUNTER_MUSIC_GIRL,
#line 8367
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 8368
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 8370
            .species = SPECIES_TENTACOOL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8372
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 8371
            .lvl = 30,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 8374
            .species = SPECIES_HORSEA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8376
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 8375
            .lvl = 30,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 8378
            .species = SPECIES_SEEL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8380
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 8379
            .lvl = 30,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 8382
    [DIFFICULTY_NORMAL][TRAINER_PICNICKER_DANA] =
    {
#line 8383
        .trainerName = _("DANA"),
#line 8384
        .trainerClass = TRAINER_CLASS_PICNICKER,
#line 8385
        .trainerPic = TRAINER_PIC_PICNICKER,
        .encounterMusic_gender =
#line 8387
            TRAINER_ENCOUNTER_MUSIC_GIRL,
#line 8388
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 8389
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 8391
            .species = SPECIES_MEOWTH,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8393
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 8392
            .lvl = 20,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 8395
            .species = SPECIES_ODDISH,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8397
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 8396
            .lvl = 20,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 8399
            .species = SPECIES_PIDGEY,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8401
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 8400
            .lvl = 20,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 8403
    [DIFFICULTY_NORMAL][TRAINER_PICNICKER_ARIANA] =
    {
#line 8404
        .trainerName = _("ARIANA"),
#line 8405
        .trainerClass = TRAINER_CLASS_PICNICKER,
#line 8406
        .trainerPic = TRAINER_PIC_PICNICKER,
        .encounterMusic_gender =
#line 8408
            TRAINER_ENCOUNTER_MUSIC_GIRL,
#line 8409
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 8410
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 4,
        .party = (const struct TrainerMon[])
        {
            {
#line 8412
            .species = SPECIES_PIDGEY,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8414
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 8413
            .lvl = 19,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 8416
            .species = SPECIES_RATTATA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8418
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 8417
            .lvl = 19,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 8420
            .species = SPECIES_RATTATA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8422
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 8421
            .lvl = 19,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 8424
            .species = SPECIES_BELLSPROUT,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8426
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 8425
            .lvl = 19,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 8428
    [DIFFICULTY_NORMAL][TRAINER_PICNICKER_LEAH] =
    {
#line 8429
        .trainerName = _("LEAH"),
#line 8430
        .trainerClass = TRAINER_CLASS_PICNICKER,
#line 8431
        .trainerPic = TRAINER_PIC_PICNICKER,
        .encounterMusic_gender =
#line 8433
            TRAINER_ENCOUNTER_MUSIC_GIRL,
#line 8434
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 8435
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 8437
            .species = SPECIES_BELLSPROUT,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8439
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 8438
            .lvl = 22,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 8441
            .species = SPECIES_CLEFAIRY,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8443
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 8442
            .lvl = 22,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 8445
    [DIFFICULTY_NORMAL][TRAINER_CAMPER_JUSTIN] =
    {
#line 8446
        .trainerName = _("JUSTIN"),
#line 8447
        .trainerClass = TRAINER_CLASS_CAMPER,
#line 8448
        .trainerPic = TRAINER_PIC_CAMPER,
        .encounterMusic_gender =
#line 8450
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 8451
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 8452
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 8454
            .species = SPECIES_NIDORAN_M,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8456
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 8455
            .lvl = 29,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 8458
            .species = SPECIES_NIDORINO,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8460
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 8459
            .lvl = 29,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 8462
    [DIFFICULTY_NORMAL][TRAINER_PICNICKER_YAZMIN] =
    {
#line 8463
        .trainerName = _("YAZMIN"),
#line 8464
        .trainerClass = TRAINER_CLASS_PICNICKER,
#line 8465
        .trainerPic = TRAINER_PIC_PICNICKER,
        .encounterMusic_gender =
#line 8467
            TRAINER_ENCOUNTER_MUSIC_GIRL,
#line 8468
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 8469
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 8471
            .species = SPECIES_BELLSPROUT,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8473
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 8472
            .lvl = 29,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 8475
            .species = SPECIES_ODDISH,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8477
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 8476
            .lvl = 29,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 8479
            .species = SPECIES_TANGELA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8481
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 8480
            .lvl = 29,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 8483
    [DIFFICULTY_NORMAL][TRAINER_PICNICKER_KINDRA] =
    {
#line 8484
        .trainerName = _("KINDRA"),
#line 8485
        .trainerClass = TRAINER_CLASS_PICNICKER,
#line 8486
        .trainerPic = TRAINER_PIC_PICNICKER,
        .encounterMusic_gender =
#line 8488
            TRAINER_ENCOUNTER_MUSIC_GIRL,
#line 8489
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 8490
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 8492
            .species = SPECIES_GLOOM,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8494
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 8493
            .lvl = 28,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 8496
            .species = SPECIES_ODDISH,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8498
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 8497
            .lvl = 28,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 8500
            .species = SPECIES_ODDISH,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8502
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 8501
            .lvl = 28,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 8504
    [DIFFICULTY_NORMAL][TRAINER_PICNICKER_BECKY] =
    {
#line 8505
        .trainerName = _("BECKY"),
#line 8506
        .trainerClass = TRAINER_CLASS_PICNICKER,
#line 8507
        .trainerPic = TRAINER_PIC_PICNICKER,
        .encounterMusic_gender =
#line 8509
            TRAINER_ENCOUNTER_MUSIC_GIRL,
#line 8510
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 8511
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 8513
            .species = SPECIES_PIKACHU,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8515
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 8514
            .lvl = 29,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 8517
            .species = SPECIES_RAICHU,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8519
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 8518
            .lvl = 29,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 8521
    [DIFFICULTY_NORMAL][TRAINER_PICNICKER_CELIA] =
    {
#line 8522
        .trainerName = _("CELIA"),
#line 8523
        .trainerClass = TRAINER_CLASS_PICNICKER,
#line 8524
        .trainerPic = TRAINER_PIC_PICNICKER,
        .encounterMusic_gender =
#line 8526
            TRAINER_ENCOUNTER_MUSIC_GIRL,
#line 8527
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 8528
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 8530
            .species = SPECIES_CLEFAIRY,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8532
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 8531
            .lvl = 33,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 8534
    [DIFFICULTY_NORMAL][TRAINER_GENTLEMAN_BROOKS] =
    {
#line 8535
        .trainerName = _("BROOKS"),
#line 8536
        .trainerClass = TRAINER_CLASS_GENTLEMAN,
#line 8537
        .trainerPic = TRAINER_PIC_GENTLEMAN,
        .encounterMusic_gender =
#line 8539
            TRAINER_ENCOUNTER_MUSIC_RICH,
#line 8540
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 8541
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 8543
            .species = SPECIES_PIKACHU,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8545
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 8544
            .lvl = 23,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 8547
    [DIFFICULTY_NORMAL][TRAINER_GENTLEMAN_LAMAR] =
    {
#line 8548
        .trainerName = _("LAMAR"),
#line 8549
        .trainerClass = TRAINER_CLASS_GENTLEMAN,
#line 8550
        .trainerPic = TRAINER_PIC_GENTLEMAN,
        .encounterMusic_gender =
#line 8552
            TRAINER_ENCOUNTER_MUSIC_RICH,
#line 8553
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 8554
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 8556
            .species = SPECIES_GROWLITHE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8558
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 8557
            .lvl = 17,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 8560
            .species = SPECIES_PONYTA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8562
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 8561
            .lvl = 17,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 8564
    [DIFFICULTY_NORMAL][TRAINER_TWINS_ELI_ANNE] =
    {
#line 8565
        .trainerName = _("ELI & ANNE"),
#line 8566
        .trainerClass = TRAINER_CLASS_TWINS,
#line 8567
        .trainerPic = TRAINER_PIC_TWINS,
        .encounterMusic_gender =
#line 8569
            TRAINER_ENCOUNTER_MUSIC_TWINS,
#line 8570
        .battleType = TRAINER_BATTLE_TYPE_DOUBLES,
#line 8571
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 8573
            .species = SPECIES_CLEFAIRY,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8575
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 8574
            .lvl = 22,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 8577
            .species = SPECIES_JIGGLYPUFF,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8579
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 8578
            .lvl = 22,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 8581
    [DIFFICULTY_NORMAL][TRAINER_COOL_COUPLE_RAY_TYRA] =
    {
#line 8582
        .trainerName = _("RAY & TYRA"),
#line 8583
        .trainerClass = TRAINER_CLASS_COOL_COUPLE,
#line 8584
        .trainerPic = TRAINER_PIC_COOL_COUPLE,
        .encounterMusic_gender =
#line 8586
            TRAINER_ENCOUNTER_MUSIC_COOL,
#line 8587
        .battleType = TRAINER_BATTLE_TYPE_DOUBLES,
#line 8588
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 8590
            .species = SPECIES_NIDOQUEEN,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8592
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 8591
            .lvl = 45,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 8593
                MOVE_SUPERPOWER,
                MOVE_BODY_SLAM,
                MOVE_DOUBLE_KICK,
                MOVE_POISON_STING,
            },
            },
            {
#line 8598
            .species = SPECIES_NIDOKING,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8600
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 8599
            .lvl = 45,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 8601
                MOVE_MEGAHORN,
                MOVE_THRASH,
                MOVE_DOUBLE_KICK,
                MOVE_POISON_STING,
            },
            },
        },
    },
#line 8606
    [DIFFICULTY_NORMAL][TRAINER_YOUNG_COUPLE_GIA_JES] =
    {
#line 8607
        .trainerName = _("GIA & JES"),
#line 8608
        .trainerClass = TRAINER_CLASS_YOUNG_COUPLE,
#line 8609
        .trainerPic = TRAINER_PIC_YOUNG_COUPLE,
        .encounterMusic_gender =
#line 8611
            TRAINER_ENCOUNTER_MUSIC_GIRL,
#line 8612
        .battleType = TRAINER_BATTLE_TYPE_DOUBLES,
#line 8613
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 8615
            .species = SPECIES_NIDORAN_M,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8617
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 8616
            .lvl = 24,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 8619
            .species = SPECIES_NIDORAN_F,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8621
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 8620
            .lvl = 24,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 8623
    [DIFFICULTY_NORMAL][TRAINER_TWINS_KIRI_JAN] =
    {
#line 8624
        .trainerName = _("KIRI & JAN"),
#line 8625
        .trainerClass = TRAINER_CLASS_TWINS,
#line 8626
        .trainerPic = TRAINER_PIC_TWINS,
        .encounterMusic_gender =
#line 8628
            TRAINER_ENCOUNTER_MUSIC_TWINS,
#line 8629
        .battleType = TRAINER_BATTLE_TYPE_DOUBLES,
#line 8630
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 8632
            .species = SPECIES_CHARMANDER,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8634
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 8633
            .lvl = 29,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 8636
            .species = SPECIES_SQUIRTLE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8638
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 8637
            .lvl = 29,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 8640
    [DIFFICULTY_NORMAL][TRAINER_CRUSH_KIN_RON_MYA] =
    {
#line 8641
        .trainerName = _("RON & MYA"),
#line 8642
        .trainerClass = TRAINER_CLASS_CRUSH_KIN,
#line 8643
        .trainerPic = TRAINER_PIC_CRUSH_KIN,
        .encounterMusic_gender =
#line 8645
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
#line 8646
        .battleType = TRAINER_BATTLE_TYPE_DOUBLES,
#line 8647
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 8649
            .species = SPECIES_HITMONCHAN,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8649
            .heldItem = ITEM_BLACK_BELT,
#line 8651
            .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
#line 8650
            .lvl = 29,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 8653
            .species = SPECIES_HITMONLEE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8653
            .heldItem = ITEM_BLACK_BELT,
#line 8655
            .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
#line 8654
            .lvl = 29,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 8657
    [DIFFICULTY_NORMAL][TRAINER_YOUNG_COUPLE_LEA_JED] =
    {
#line 8658
        .trainerName = _("LEA & JED"),
#line 8659
        .trainerClass = TRAINER_CLASS_YOUNG_COUPLE,
#line 8660
        .trainerPic = TRAINER_PIC_YOUNG_COUPLE,
        .encounterMusic_gender =
#line 8662
            TRAINER_ENCOUNTER_MUSIC_GIRL,
#line 8663
        .battleType = TRAINER_BATTLE_TYPE_DOUBLES,
#line 8664
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 8666
            .species = SPECIES_RAPIDASH,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8668
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 8667
            .lvl = 29,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 8670
            .species = SPECIES_NINETALES,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8672
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 8671
            .lvl = 29,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 8674
    [DIFFICULTY_NORMAL][TRAINER_SIS_AND_BRO_LIA_LUC] =
    {
#line 8675
        .trainerName = _("LIA & LUC"),
#line 8676
        .trainerClass = TRAINER_CLASS_SIS_AND_BRO,
#line 8677
        .trainerPic = TRAINER_PIC_SIS_AND_BRO,
        .encounterMusic_gender =
#line 8679
            TRAINER_ENCOUNTER_MUSIC_SWIMMER,
#line 8680
        .battleType = TRAINER_BATTLE_TYPE_DOUBLES,
#line 8681
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 8683
            .species = SPECIES_GOLDEEN,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8685
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 8684
            .lvl = 30,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 8687
            .species = SPECIES_SEAKING,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8689
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 8688
            .lvl = 30,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 8691
    [DIFFICULTY_NORMAL][TRAINER_SIS_AND_BRO_LIL_IAN] =
    {
#line 8692
        .trainerName = _("LIL & IAN"),
#line 8693
        .trainerClass = TRAINER_CLASS_SIS_AND_BRO,
#line 8694
        .trainerPic = TRAINER_PIC_SIS_AND_BRO,
        .encounterMusic_gender =
#line 8696
            TRAINER_ENCOUNTER_MUSIC_SWIMMER,
#line 8697
        .battleType = TRAINER_BATTLE_TYPE_DOUBLES,
#line 8698
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 8700
            .species = SPECIES_SEADRA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8702
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 8701
            .lvl = 33,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 8704
            .species = SPECIES_STARMIE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8706
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 8705
            .lvl = 33,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 8708
    [DIFFICULTY_NORMAL][TRAINER_YOUNGSTER_BEN_3] =
    {
#line 8709
        .trainerName = _("BEN"),
#line 8710
        .trainerClass = TRAINER_CLASS_YOUNGSTER,
#line 8711
        .trainerPic = TRAINER_PIC_YOUNGSTER,
        .encounterMusic_gender =
#line 8713
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 8714
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 8715
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 8717
            .species = SPECIES_RATICATE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8719
            .iv = TRAINER_PARTY_IVS(7, 7, 7, 7, 7, 7),
#line 8718
            .lvl = 28,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 8721
            .species = SPECIES_EKANS,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8723
            .iv = TRAINER_PARTY_IVS(7, 7, 7, 7, 7, 7),
#line 8722
            .lvl = 28,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 8725
    [DIFFICULTY_NORMAL][TRAINER_YOUNGSTER_BEN_4] =
    {
#line 8726
        .trainerName = _("BEN"),
#line 8727
        .trainerClass = TRAINER_CLASS_YOUNGSTER,
#line 8728
        .trainerPic = TRAINER_PIC_YOUNGSTER,
        .encounterMusic_gender =
#line 8730
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 8731
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 8732
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 8734
            .species = SPECIES_RATICATE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8736
            .iv = TRAINER_PARTY_IVS(14, 14, 14, 14, 14, 14),
#line 8735
            .lvl = 48,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 8738
            .species = SPECIES_ARBOK,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8740
            .iv = TRAINER_PARTY_IVS(14, 14, 14, 14, 14, 14),
#line 8739
            .lvl = 48,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 8742
    [DIFFICULTY_NORMAL][TRAINER_YOUNGSTER_CHAD_2] =
    {
#line 8743
        .trainerName = _("CHAD"),
#line 8744
        .trainerClass = TRAINER_CLASS_YOUNGSTER,
#line 8745
        .trainerPic = TRAINER_PIC_YOUNGSTER,
        .encounterMusic_gender =
#line 8747
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 8748
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 8749
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 8751
            .species = SPECIES_EKANS,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8753
            .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
#line 8752
            .lvl = 20,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 8755
            .species = SPECIES_SANDSHREW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8757
            .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
#line 8756
            .lvl = 20,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 8759
    [DIFFICULTY_NORMAL][TRAINER_LASS_RELI_2] =
    {
#line 8760
        .trainerName = _("RELI"),
#line 8761
        .trainerClass = TRAINER_CLASS_LASS,
#line 8762
        .trainerPic = TRAINER_PIC_LASS,
        .encounterMusic_gender =
#line 8764
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
#line 8765
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 8766
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 8768
            .species = SPECIES_PIDGEY,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8770
            .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
#line 8769
            .lvl = 20,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 8772
            .species = SPECIES_NIDORAN_F,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8774
            .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
#line 8773
            .lvl = 20,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 8776
    [DIFFICULTY_NORMAL][TRAINER_LASS_RELI_3] =
    {
#line 8777
        .trainerName = _("RELI"),
#line 8778
        .trainerClass = TRAINER_CLASS_LASS,
#line 8779
        .trainerPic = TRAINER_PIC_LASS,
        .encounterMusic_gender =
#line 8781
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
#line 8782
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 8783
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 8785
            .species = SPECIES_PIDGEOTTO,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8787
            .iv = TRAINER_PARTY_IVS(7, 7, 7, 7, 7, 7),
#line 8786
            .lvl = 28,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 8789
            .species = SPECIES_NIDORINA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8791
            .iv = TRAINER_PARTY_IVS(7, 7, 7, 7, 7, 7),
#line 8790
            .lvl = 28,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 8793
    [DIFFICULTY_NORMAL][TRAINER_YOUNGSTER_TIMMY_2] =
    {
#line 8794
        .trainerName = _("TIMMY"),
#line 8795
        .trainerClass = TRAINER_CLASS_YOUNGSTER,
#line 8796
        .trainerPic = TRAINER_PIC_YOUNGSTER,
        .encounterMusic_gender =
#line 8798
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 8799
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 8800
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 8802
            .species = SPECIES_RATICATE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8804
            .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
#line 8803
            .lvl = 19,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 8806
            .species = SPECIES_EKANS,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8808
            .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
#line 8807
            .lvl = 19,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 8810
            .species = SPECIES_ZUBAT,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8812
            .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
#line 8811
            .lvl = 19,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 8814
    [DIFFICULTY_NORMAL][TRAINER_YOUNGSTER_TIMMY_3] =
    {
#line 8815
        .trainerName = _("TIMMY"),
#line 8816
        .trainerClass = TRAINER_CLASS_YOUNGSTER,
#line 8817
        .trainerPic = TRAINER_PIC_YOUNGSTER,
        .encounterMusic_gender =
#line 8819
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 8820
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 8821
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 8823
            .species = SPECIES_RATICATE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8825
            .iv = TRAINER_PARTY_IVS(7, 7, 7, 7, 7, 7),
#line 8824
            .lvl = 27,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 8827
            .species = SPECIES_EKANS,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8829
            .iv = TRAINER_PARTY_IVS(7, 7, 7, 7, 7, 7),
#line 8828
            .lvl = 27,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 8831
            .species = SPECIES_GOLBAT,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8833
            .iv = TRAINER_PARTY_IVS(7, 7, 7, 7, 7, 7),
#line 8832
            .lvl = 27,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 8835
    [DIFFICULTY_NORMAL][TRAINER_YOUNGSTER_TIMMY_4] =
    {
#line 8836
        .trainerName = _("TIMMY"),
#line 8837
        .trainerClass = TRAINER_CLASS_YOUNGSTER,
#line 8838
        .trainerPic = TRAINER_PIC_YOUNGSTER,
        .encounterMusic_gender =
#line 8840
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 8841
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 8842
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 8844
            .species = SPECIES_RATICATE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8846
            .iv = TRAINER_PARTY_IVS(14, 14, 14, 14, 14, 14),
#line 8845
            .lvl = 52,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 8848
            .species = SPECIES_ARBOK,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8850
            .iv = TRAINER_PARTY_IVS(14, 14, 14, 14, 14, 14),
#line 8849
            .lvl = 52,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 8852
            .species = SPECIES_GOLBAT,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8854
            .iv = TRAINER_PARTY_IVS(14, 14, 14, 14, 14, 14),
#line 8853
            .lvl = 52,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 8856
    [DIFFICULTY_NORMAL][TRAINER_YOUNGSTER_CHAD_3] =
    {
#line 8857
        .trainerName = _("CHAD"),
#line 8858
        .trainerClass = TRAINER_CLASS_YOUNGSTER,
#line 8859
        .trainerPic = TRAINER_PIC_YOUNGSTER,
        .encounterMusic_gender =
#line 8861
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 8862
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 8863
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 8865
            .species = SPECIES_ARBOK,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8867
            .iv = TRAINER_PARTY_IVS(7, 7, 7, 7, 7, 7),
#line 8866
            .lvl = 28,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 8869
            .species = SPECIES_SANDSHREW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8871
            .iv = TRAINER_PARTY_IVS(7, 7, 7, 7, 7, 7),
#line 8870
            .lvl = 28,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 8873
    [DIFFICULTY_NORMAL][TRAINER_LASS_JANICE_2] =
    {
#line 8874
        .trainerName = _("JANICE"),
#line 8875
        .trainerClass = TRAINER_CLASS_LASS,
#line 8876
        .trainerPic = TRAINER_PIC_LASS,
        .encounterMusic_gender =
#line 8878
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
#line 8879
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 8880
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 8882
            .species = SPECIES_PIDGEOTTO,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8884
            .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
#line 8883
            .lvl = 20,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 8886
            .species = SPECIES_PIDGEOTTO,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8888
            .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
#line 8887
            .lvl = 20,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 8890
    [DIFFICULTY_NORMAL][TRAINER_LASS_JANICE_3] =
    {
#line 8891
        .trainerName = _("JANICE"),
#line 8892
        .trainerClass = TRAINER_CLASS_LASS,
#line 8893
        .trainerPic = TRAINER_PIC_LASS,
        .encounterMusic_gender =
#line 8895
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
#line 8896
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 8897
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 8899
            .species = SPECIES_PIDGEOTTO,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8901
            .iv = TRAINER_PARTY_IVS(7, 7, 7, 7, 7, 7),
#line 8900
            .lvl = 28,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 8903
            .species = SPECIES_PIDGEOTTO,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8905
            .iv = TRAINER_PARTY_IVS(7, 7, 7, 7, 7, 7),
#line 8904
            .lvl = 28,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 8907
    [DIFFICULTY_NORMAL][TRAINER_YOUNGSTER_CHAD_4] =
    {
#line 8908
        .trainerName = _("CHAD"),
#line 8909
        .trainerClass = TRAINER_CLASS_YOUNGSTER,
#line 8910
        .trainerPic = TRAINER_PIC_YOUNGSTER,
        .encounterMusic_gender =
#line 8912
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 8913
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 8914
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 8916
            .species = SPECIES_ARBOK,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8918
            .iv = TRAINER_PARTY_IVS(9, 9, 9, 9, 9, 9),
#line 8917
            .lvl = 48,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 8920
            .species = SPECIES_SANDSLASH,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8922
            .iv = TRAINER_PARTY_IVS(9, 9, 9, 9, 9, 9),
#line 8921
            .lvl = 48,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 8924
    [DIFFICULTY_NORMAL][TRAINER_HIKER_FRANKLIN_2] =
    {
#line 8925
        .trainerName = _("FRANKLIN"),
#line 8926
        .trainerClass = TRAINER_CLASS_HIKER,
#line 8927
        .trainerPic = TRAINER_PIC_HIKER,
        .encounterMusic_gender =
#line 8929
            TRAINER_ENCOUNTER_MUSIC_HIKER,
#line 8930
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 8931
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 8933
            .species = SPECIES_MACHOKE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8935
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
#line 8934
            .lvl = 25,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 8937
            .species = SPECIES_GRAVELER,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8939
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
#line 8938
            .lvl = 25,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 8941
    [DIFFICULTY_NORMAL][TRAINER_PKMN_PROF_PROF_OAK] =
    {
#line 8942
        .trainerName = _("PROF. OAK"),
#line 8943
        .trainerClass = TRAINER_CLASS_PKMN_PROF,
#line 8944
        .trainerPic = TRAINER_PIC_PROFESSOR_OAK,
        .encounterMusic_gender =
#line 8946
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 8947
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 8948
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 8950
            .species = SPECIES_EKANS,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8952
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 8951
            .lvl = 5,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 8954
    [DIFFICULTY_NORMAL][TRAINER_PLAYER_BRENDAN] =
    {
#line 8955
        .trainerName = _("BRENDAN"),
#line 8956
        .trainerClass = TRAINER_CLASS_PLAYER,
#line 8957
        .trainerPic = TRAINER_PIC_RS_BRENDAN_2,
        .encounterMusic_gender =
#line 8959
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 8960
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 8961
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 8963
            .species = SPECIES_EKANS,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8965
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 8964
            .lvl = 5,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 8967
    [DIFFICULTY_NORMAL][TRAINER_PLAYER_MAY] =
    {
#line 8968
        .trainerName = _("MAY"),
#line 8969
        .trainerClass = TRAINER_CLASS_PLAYER,
#line 8970
        .trainerPic = TRAINER_PIC_RS_MAY_2,
        .encounterMusic_gender =
#line 8972
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
#line 8973
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 8974
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 8976
            .species = SPECIES_EKANS,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8978
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 8977
            .lvl = 5,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 8980
    [DIFFICULTY_NORMAL][TRAINER_PLAYER_RED] =
    {
#line 8981
        .trainerName = _("RED"),
#line 8982
        .trainerClass = TRAINER_CLASS_PLAYER,
#line 8983
        .trainerPic = TRAINER_PIC_RED,
        .encounterMusic_gender =
#line 8985
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 8986
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 8987
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 8989
            .species = SPECIES_EKANS,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8991
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 8990
            .lvl = 5,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 8993
    [DIFFICULTY_NORMAL][TRAINER_PLAYER_LEAF] =
    {
#line 8994
        .trainerName = _("LEAF"),
#line 8995
        .trainerClass = TRAINER_CLASS_PLAYER,
#line 8996
        .trainerPic = TRAINER_PIC_LEAF,
        .encounterMusic_gender =
#line 8998
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
#line 8999
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 9000
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 9002
            .species = SPECIES_EKANS,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9004
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 9003
            .lvl = 5,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 9006
    [DIFFICULTY_NORMAL][TRAINER_TEAM_ROCKET_GRUNT_42] =
    {
#line 9007
        .trainerName = _("GRUNT"),
#line 9008
        .trainerClass = TRAINER_CLASS_TEAM_ROCKET,
#line 9009
        .trainerPic = TRAINER_PIC_ROCKET_GRUNT_F,
        .encounterMusic_gender =
#line 9011
            TRAINER_ENCOUNTER_MUSIC_AQUA,
#line 9012
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 9013
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 9015
            .species = SPECIES_HOUNDOUR,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9017
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 9016
            .lvl = 49,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 9019
            .species = SPECIES_HOUNDOUR,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9021
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 9020
            .lvl = 49,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 9023
    [DIFFICULTY_NORMAL][TRAINER_PSYCHIC_JACLYN] =
    {
#line 9024
        .trainerName = _("JACLYN"),
#line 9025
        .trainerClass = TRAINER_CLASS_PSYCHIC,
#line 9026
        .trainerPic = TRAINER_PIC_PSYCHIC_F,
        .encounterMusic_gender =
#line 9028
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
#line 9029
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 9030
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 9032
            .species = SPECIES_NATU,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9034
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 9033
            .lvl = 48,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 9035
                MOVE_NIGHT_SHADE,
                MOVE_CONFUSE_RAY,
                MOVE_FUTURE_SIGHT,
                MOVE_WISH,
            },
            },
            {
#line 9040
            .species = SPECIES_SLOWBRO,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9042
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 9041
            .lvl = 48,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 9043
                MOVE_PSYCHIC,
                MOVE_HEADBUTT,
                MOVE_AMNESIA,
                MOVE_YAWN,
            },
            },
            {
#line 9048
            .species = SPECIES_KADABRA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9050
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 9049
            .lvl = 49,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 9051
                MOVE_PSYCHIC,
                MOVE_FUTURE_SIGHT,
                MOVE_RECOVER,
                MOVE_REFLECT,
            },
            },
        },
    },
#line 9056
    [DIFFICULTY_NORMAL][TRAINER_CRUSH_GIRL_SHARON] =
    {
#line 9057
        .trainerName = _("SHARON"),
#line 9058
        .trainerClass = TRAINER_CLASS_CRUSH_GIRL,
#line 9059
        .trainerPic = TRAINER_PIC_CRUSH_GIRL,
        .encounterMusic_gender =
#line 9061
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
#line 9062
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 9063
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 9065
            .species = SPECIES_MANKEY,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9065
            .heldItem = ITEM_BLACK_BELT,
#line 9067
            .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
#line 9066
            .lvl = 37,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 9069
            .species = SPECIES_PRIMEAPE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9069
            .heldItem = ITEM_BLACK_BELT,
#line 9071
            .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
#line 9070
            .lvl = 37,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 9073
    [DIFFICULTY_NORMAL][TRAINER_TUBER_AMIRA] =
    {
#line 9074
        .trainerName = _("AMIRA"),
#line 9075
        .trainerClass = TRAINER_CLASS_TUBER,
#line 9076
        .trainerPic = TRAINER_PIC_TUBER_F,
        .encounterMusic_gender =
#line 9078
            TRAINER_ENCOUNTER_MUSIC_GIRL,
#line 9079
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 9080
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 9082
            .species = SPECIES_POLIWAG,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9084
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 9083
            .lvl = 34,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 9086
            .species = SPECIES_POLIWHIRL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9088
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 9087
            .lvl = 35,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 9090
            .species = SPECIES_POLIWAG,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9092
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 9091
            .lvl = 34,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 9094
    [DIFFICULTY_NORMAL][TRAINER_PKMN_BREEDER_ALIZE] =
    {
#line 9095
        .trainerName = _("ALIZE"),
#line 9096
        .trainerClass = TRAINER_CLASS_PKMN_BREEDER,
#line 9097
        .trainerPic = TRAINER_PIC_POKEMON_BREEDER,
        .encounterMusic_gender =
#line 9099
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
#line 9100
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 9101
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 9103
            .species = SPECIES_PIKACHU,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9105
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
#line 9104
            .lvl = 48,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 9107
            .species = SPECIES_CLEFAIRY,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9109
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
#line 9108
            .lvl = 48,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 9111
            .species = SPECIES_MARILL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9113
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
#line 9112
            .lvl = 48,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 9115
    [DIFFICULTY_NORMAL][TRAINER_PKMN_RANGER_NICOLAS] =
    {
#line 9116
        .trainerName = _("NICOLAS"),
#line 9117
        .trainerClass = TRAINER_CLASS_PKMN_RANGER,
#line 9118
        .trainerPic = TRAINER_PIC_POKEMON_RANGER_M,
        .encounterMusic_gender =
#line 9120
            TRAINER_ENCOUNTER_MUSIC_COOL,
#line 9121
        .items = { ITEM_FULL_RESTORE },
#line 9122
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 9123
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 9125
            .species = SPECIES_WEEPINBELL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9127
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 9126
            .lvl = 51,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 9128
                MOVE_RAZOR_LEAF,
                MOVE_ACID,
                MOVE_SWEET_SCENT,
                MOVE_WRAP,
            },
            },
            {
#line 9133
            .species = SPECIES_VICTREEBEL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9135
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 9134
            .lvl = 51,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 9136
                MOVE_RAZOR_LEAF,
                MOVE_ACID,
                MOVE_SLEEP_POWDER,
                MOVE_STUN_SPORE,
            },
            },
        },
    },
#line 9141
    [DIFFICULTY_NORMAL][TRAINER_PKMN_RANGER_MADELINE] =
    {
#line 9142
        .trainerName = _("MADELINE"),
#line 9143
        .trainerClass = TRAINER_CLASS_PKMN_RANGER,
#line 9144
        .trainerPic = TRAINER_PIC_POKEMON_RANGER_F,
        .encounterMusic_gender =
#line 9146
            TRAINER_ENCOUNTER_MUSIC_COOL,
#line 9147
        .items = { ITEM_FULL_RESTORE },
#line 9148
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 9149
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 9151
            .species = SPECIES_GLOOM,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9153
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 9152
            .lvl = 51,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 9154
                MOVE_PETAL_DANCE,
                MOVE_ACID,
                MOVE_SWEET_SCENT,
                MOVE_POISON_POWDER,
            },
            },
            {
#line 9159
            .species = SPECIES_VILEPLUME,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9161
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 9160
            .lvl = 51,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 9162
                MOVE_PETAL_DANCE,
                MOVE_MOONLIGHT,
                MOVE_ACID,
                MOVE_STUN_SPORE,
            },
            },
        },
    },
#line 9167
    [DIFFICULTY_NORMAL][TRAINER_AROMA_LADY_NIKKI] =
    {
#line 9168
        .trainerName = _("NIKKI"),
#line 9169
        .trainerClass = TRAINER_CLASS_AROMA_LADY,
#line 9170
        .trainerPic = TRAINER_PIC_AROMA_LADY,
        .encounterMusic_gender =
#line 9172
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
#line 9173
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 9174
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 9176
            .species = SPECIES_BELLSPROUT,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9178
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 9177
            .lvl = 37,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 9180
            .species = SPECIES_WEEPINBELL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9182
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 9181
            .lvl = 37,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 9184
    [DIFFICULTY_NORMAL][TRAINER_RUIN_MANIAC_STANLY] =
    {
#line 9185
        .trainerName = _("STANLY"),
#line 9186
        .trainerClass = TRAINER_CLASS_RUIN_MANIAC,
#line 9187
        .trainerPic = TRAINER_PIC_RUIN_MANIAC,
        .encounterMusic_gender =
#line 9189
            TRAINER_ENCOUNTER_MUSIC_HIKER,
#line 9190
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 9191
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 9193
            .species = SPECIES_GRAVELER,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9195
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 9194
            .lvl = 48,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 9197
            .species = SPECIES_ONIX,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9199
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 9198
            .lvl = 48,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 9201
            .species = SPECIES_GRAVELER,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9203
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 9202
            .lvl = 48,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 9205
    [DIFFICULTY_NORMAL][TRAINER_LADY_JACKI] =
    {
#line 9206
        .trainerName = _("JACKI"),
#line 9207
        .trainerClass = TRAINER_CLASS_LADY,
#line 9208
        .trainerPic = TRAINER_PIC_LADY,
        .encounterMusic_gender =
#line 9210
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
#line 9211
        .items = { ITEM_FULL_RESTORE },
#line 9212
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 9213
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 9215
            .species = SPECIES_HOPPIP,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9215
            .heldItem = ITEM_STARDUST,
#line 9217
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 9216
            .lvl = 48,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 9219
            .species = SPECIES_SKIPLOOM,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9219
            .heldItem = ITEM_STARDUST,
#line 9221
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 9220
            .lvl = 50,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 9223
    [DIFFICULTY_NORMAL][TRAINER_PAINTER_DAISY] =
    {
#line 9224
        .trainerName = _("DAISY"),
#line 9225
        .trainerClass = TRAINER_CLASS_PAINTER,
#line 9226
        .trainerPic = TRAINER_PIC_PAINTER,
        .encounterMusic_gender =
#line 9228
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
#line 9229
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 9230
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 9232
            .species = SPECIES_SMEARGLE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9234
            .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
#line 9233
            .lvl = 50,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 9235
                MOVE_DYNAMIC_PUNCH,
                MOVE_DIZZY_PUNCH,
                MOVE_FOCUS_PUNCH,
                MOVE_MEGA_PUNCH,
            },
            },
        },
    },
#line 9240
    [DIFFICULTY_NORMAL][TRAINER_BIKER_GOON] =
    {
#line 9241
        .trainerName = _("GOON"),
#line 9242
        .trainerClass = TRAINER_CLASS_BIKER,
#line 9243
        .trainerPic = TRAINER_PIC_BIKER,
        .encounterMusic_gender =
#line 9245
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 9246
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 9247
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 9249
            .species = SPECIES_KOFFING,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9251
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 9250
            .lvl = 37,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 9252
                MOVE_HAZE,
                MOVE_SMOKESCREEN,
                MOVE_SLUDGE,
                MOVE_TACKLE,
            },
            },
            {
#line 9257
            .species = SPECIES_GRIMER,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9259
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 9258
            .lvl = 37,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 9260
                MOVE_ACID_ARMOR,
                MOVE_SCREECH,
                MOVE_MINIMIZE,
                MOVE_SLUDGE,
            },
            },
        },
    },
#line 9265
    [DIFFICULTY_NORMAL][TRAINER_BIKER_GOON_2] =
    {
#line 9266
        .trainerName = _("GOON"),
#line 9267
        .trainerClass = TRAINER_CLASS_BIKER,
#line 9268
        .trainerPic = TRAINER_PIC_BIKER,
        .encounterMusic_gender =
#line 9270
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 9271
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 9272
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 9274
            .species = SPECIES_KOFFING,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9276
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 9275
            .lvl = 38,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 9277
                MOVE_HAZE,
                MOVE_SMOKESCREEN,
                MOVE_SLUDGE,
                MOVE_TACKLE,
            },
            },
        },
    },
#line 9282
    [DIFFICULTY_NORMAL][TRAINER_BIKER_GOON_3] =
    {
#line 9283
        .trainerName = _("GOON"),
#line 9284
        .trainerClass = TRAINER_CLASS_BIKER,
#line 9285
        .trainerPic = TRAINER_PIC_BIKER,
        .encounterMusic_gender =
#line 9287
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 9288
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 9289
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 9291
            .species = SPECIES_GRIMER,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9293
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 9292
            .lvl = 38,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 9295
    [DIFFICULTY_NORMAL][TRAINER_BUG_CATCHER_ANTHONY] =
    {
#line 9296
        .trainerName = _("ANTHONY"),
#line 9297
        .trainerClass = TRAINER_CLASS_BUG_CATCHER,
#line 9298
        .trainerPic = TRAINER_PIC_BUG_CATCHER,
        .encounterMusic_gender =
#line 9300
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 9301
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 9302
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 9304
            .species = SPECIES_CATERPIE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9306
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 9305
            .lvl = 7,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 9308
            .species = SPECIES_CATERPIE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9310
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 9309
            .lvl = 8,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 9312
    [DIFFICULTY_NORMAL][TRAINER_BUG_CATCHER_CHARLIE] =
    {
#line 9313
        .trainerName = _("CHARLIE"),
#line 9314
        .trainerClass = TRAINER_CLASS_BUG_CATCHER,
#line 9315
        .trainerPic = TRAINER_PIC_BUG_CATCHER,
        .encounterMusic_gender =
#line 9317
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 9318
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 9319
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 9321
            .species = SPECIES_METAPOD,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9323
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 9322
            .lvl = 7,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 9325
            .species = SPECIES_CATERPIE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9327
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 9326
            .lvl = 7,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 9329
            .species = SPECIES_METAPOD,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9331
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 9330
            .lvl = 7,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 9333
    [DIFFICULTY_NORMAL][TRAINER_TWINS_ELI_ANNE_2] =
    {
#line 9334
        .trainerName = _("ELI & ANNE"),
#line 9335
        .trainerClass = TRAINER_CLASS_TWINS,
#line 9336
        .trainerPic = TRAINER_PIC_TWINS,
        .encounterMusic_gender =
#line 9338
            TRAINER_ENCOUNTER_MUSIC_TWINS,
#line 9339
        .battleType = TRAINER_BATTLE_TYPE_DOUBLES,
#line 9340
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 9342
            .species = SPECIES_CLEFAIRY,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9344
            .iv = TRAINER_PARTY_IVS(7, 7, 7, 7, 7, 7),
#line 9343
            .lvl = 28,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 9346
            .species = SPECIES_JIGGLYPUFF,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9348
            .iv = TRAINER_PARTY_IVS(7, 7, 7, 7, 7, 7),
#line 9347
            .lvl = 28,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 9350
    [DIFFICULTY_NORMAL][TRAINER_YOUNGSTER_JOHNSON] =
    {
#line 9351
        .trainerName = _("JOHNSON"),
#line 9352
        .trainerClass = TRAINER_CLASS_YOUNGSTER,
#line 9353
        .trainerPic = TRAINER_PIC_YOUNGSTER,
        .encounterMusic_gender =
#line 9355
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 9356
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 9357
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 9359
            .species = SPECIES_EKANS,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9361
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 9360
            .lvl = 33,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 9363
            .species = SPECIES_EKANS,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9365
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 9364
            .lvl = 33,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 9367
            .species = SPECIES_RATICATE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9369
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 9368
            .lvl = 34,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 9371
    [DIFFICULTY_NORMAL][TRAINER_BIKER_RICARDO] =
    {
#line 9372
        .trainerName = _("RICARDO"),
#line 9373
        .trainerClass = TRAINER_CLASS_BIKER,
#line 9374
        .trainerPic = TRAINER_PIC_BIKER,
        .encounterMusic_gender =
#line 9376
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 9377
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 9378
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 9380
            .species = SPECIES_KOFFING,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9382
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 9381
            .lvl = 22,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 9383
                MOVE_SLUDGE,
                MOVE_SMOG,
                MOVE_TACKLE,
                MOVE_POISON_GAS,
            },
            },
            {
#line 9388
            .species = SPECIES_KOFFING,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9390
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 9389
            .lvl = 22,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 9391
                MOVE_SLUDGE,
                MOVE_SMOG,
                MOVE_TACKLE,
                MOVE_POISON_GAS,
            },
            },
            {
#line 9396
            .species = SPECIES_GRIMER,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9398
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 9397
            .lvl = 23,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 9399
                MOVE_MINIMIZE,
                MOVE_SLUDGE,
                MOVE_DISABLE,
                MOVE_POUND,
            },
            },
        },
    },
#line 9404
    [DIFFICULTY_NORMAL][TRAINER_BIKER_JAREN] =
    {
#line 9405
        .trainerName = _("JAREN"),
#line 9406
        .trainerClass = TRAINER_CLASS_BIKER,
#line 9407
        .trainerPic = TRAINER_PIC_BIKER,
        .encounterMusic_gender =
#line 9409
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 9410
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 9411
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 9413
            .species = SPECIES_GRIMER,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9415
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 9414
            .lvl = 24,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 9417
            .species = SPECIES_GRIMER,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9419
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 9418
            .lvl = 24,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 9421
    [DIFFICULTY_NORMAL][TRAINER_TEAM_ROCKET_GRUNT_43] =
    {
#line 9422
        .trainerName = _("GRUNT"),
#line 9423
        .trainerClass = TRAINER_CLASS_TEAM_ROCKET,
#line 9424
        .trainerPic = TRAINER_PIC_ROCKET_GRUNT_M,
        .encounterMusic_gender =
#line 9426
            TRAINER_ENCOUNTER_MUSIC_AQUA,
#line 9427
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 9428
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 9430
            .species = SPECIES_CUBONE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9432
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 9431
            .lvl = 37,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 9434
            .species = SPECIES_MAROWAK,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9436
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 9435
            .lvl = 37,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 9438
    [DIFFICULTY_NORMAL][TRAINER_TEAM_ROCKET_GRUNT_44] =
    {
#line 9439
        .trainerName = _("GRUNT"),
#line 9440
        .trainerClass = TRAINER_CLASS_TEAM_ROCKET,
#line 9441
        .trainerPic = TRAINER_PIC_ROCKET_GRUNT_M,
        .encounterMusic_gender =
#line 9443
            TRAINER_ENCOUNTER_MUSIC_AQUA,
#line 9444
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 9445
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 4,
        .party = (const struct TrainerMon[])
        {
            {
#line 9447
            .species = SPECIES_RATTATA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9449
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 9448
            .lvl = 35,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 9451
            .species = SPECIES_RATICATE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9453
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 9452
            .lvl = 35,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 9455
            .species = SPECIES_SANDSHREW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9457
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 9456
            .lvl = 35,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 9459
            .species = SPECIES_SANDSLASH,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9461
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 9460
            .lvl = 35,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 9463
    [DIFFICULTY_NORMAL][TRAINER_TEAM_ROCKET_GRUNT_45] =
    {
#line 9464
        .trainerName = _("GRUNT"),
#line 9465
        .trainerClass = TRAINER_CLASS_TEAM_ROCKET,
#line 9466
        .trainerPic = TRAINER_PIC_ROCKET_GRUNT_M,
        .encounterMusic_gender =
#line 9468
            TRAINER_ENCOUNTER_MUSIC_AQUA,
#line 9469
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 9470
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 9472
            .species = SPECIES_ZUBAT,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9474
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 9473
            .lvl = 38,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 9476
            .species = SPECIES_ZUBAT,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9478
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 9477
            .lvl = 38,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 9480
            .species = SPECIES_GOLBAT,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9482
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 9481
            .lvl = 38,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 9484
    [DIFFICULTY_NORMAL][TRAINER_TEAM_ROCKET_GRUNT_46] =
    {
#line 9485
        .trainerName = _("GRUNT"),
#line 9486
        .trainerClass = TRAINER_CLASS_TEAM_ROCKET,
#line 9487
        .trainerPic = TRAINER_PIC_ROCKET_GRUNT_M,
        .encounterMusic_gender =
#line 9489
            TRAINER_ENCOUNTER_MUSIC_AQUA,
#line 9490
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 9491
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 9493
            .species = SPECIES_MUK,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9495
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 9494
            .lvl = 48,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 9497
            .species = SPECIES_GOLBAT,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9499
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 9498
            .lvl = 48,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 9501
            .species = SPECIES_RATICATE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9503
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 9502
            .lvl = 48,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 9505
    [DIFFICULTY_NORMAL][TRAINER_TEAM_ROCKET_GRUNT_47] =
    {
#line 9506
        .trainerName = _("GRUNT"),
#line 9507
        .trainerClass = TRAINER_CLASS_TEAM_ROCKET,
#line 9508
        .trainerPic = TRAINER_PIC_ROCKET_GRUNT_M,
        .encounterMusic_gender =
#line 9510
            TRAINER_ENCOUNTER_MUSIC_AQUA,
#line 9511
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 9512
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 9514
            .species = SPECIES_MACHOP,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9516
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 9515
            .lvl = 48,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 9518
            .species = SPECIES_MACHOP,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9520
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 9519
            .lvl = 48,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 9522
            .species = SPECIES_MACHOKE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9524
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 9523
            .lvl = 48,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 9526
    [DIFFICULTY_NORMAL][TRAINER_TEAM_ROCKET_GRUNT_48] =
    {
#line 9527
        .trainerName = _("GRUNT"),
#line 9528
        .trainerClass = TRAINER_CLASS_TEAM_ROCKET,
#line 9529
        .trainerPic = TRAINER_PIC_ROCKET_GRUNT_M,
        .encounterMusic_gender =
#line 9531
            TRAINER_ENCOUNTER_MUSIC_AQUA,
#line 9532
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 9533
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 9535
            .species = SPECIES_HYPNO,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9537
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 9536
            .lvl = 49,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 9539
            .species = SPECIES_HYPNO,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9541
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 9540
            .lvl = 49,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 9543
    [DIFFICULTY_NORMAL][TRAINER_TEAM_ROCKET_ADMIN] =
    {
#line 9544
        .trainerName = _("ADMIN"),
#line 9545
        .trainerClass = TRAINER_CLASS_TEAM_ROCKET,
#line 9546
        .trainerPic = TRAINER_PIC_ROCKET_GRUNT_F,
        .encounterMusic_gender =
#line 9548
            TRAINER_ENCOUNTER_MUSIC_AQUA,
#line 9549
        .items = { ITEM_HYPER_POTION },
#line 9550
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 9551
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 9553
            .species = SPECIES_MUK,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9555
            .iv = TRAINER_PARTY_IVS(18, 18, 18, 18, 18, 18),
#line 9554
            .lvl = 52,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 9556
                MOVE_SLUDGE_BOMB,
                MOVE_SCREECH,
                MOVE_MINIMIZE,
                MOVE_ROCK_TOMB,
            },
            },
            {
#line 9561
            .species = SPECIES_ARBOK,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9563
            .iv = TRAINER_PARTY_IVS(18, 18, 18, 18, 18, 18),
#line 9562
            .lvl = 53,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 9564
                MOVE_SLUDGE_BOMB,
                MOVE_BITE,
                MOVE_EARTHQUAKE,
                MOVE_IRON_TAIL,
            },
            },
            {
#line 9569
            .species = SPECIES_VILEPLUME,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9571
            .iv = TRAINER_PARTY_IVS(18, 18, 18, 18, 18, 18),
#line 9570
            .lvl = 54,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 9572
                MOVE_SLUDGE_BOMB,
                MOVE_GIGA_DRAIN,
                MOVE_SLEEP_POWDER,
                MOVE_STUN_SPORE,
            },
            },
        },
    },
#line 9577
    [DIFFICULTY_NORMAL][TRAINER_TEAM_ROCKET_ADMIN_2] =
    {
#line 9578
        .trainerName = _("ADMIN"),
#line 9579
        .trainerClass = TRAINER_CLASS_TEAM_ROCKET,
#line 9580
        .trainerPic = TRAINER_PIC_ROCKET_GRUNT_M,
        .encounterMusic_gender =
#line 9582
            TRAINER_ENCOUNTER_MUSIC_AQUA,
#line 9583
        .items = { ITEM_HYPER_POTION },
#line 9584
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 9585
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 9587
            .species = SPECIES_GOLBAT,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9589
            .iv = TRAINER_PARTY_IVS(24, 24, 24, 24, 24, 24),
#line 9588
            .lvl = 53,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 9590
                MOVE_CONFUSE_RAY,
                MOVE_SLUDGE_BOMB,
                MOVE_AIR_CUTTER,
                MOVE_SHADOW_BALL,
            },
            },
            {
#line 9595
            .species = SPECIES_WEEZING,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9597
            .iv = TRAINER_PARTY_IVS(24, 24, 24, 24, 24, 24),
#line 9596
            .lvl = 54,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 9598
                MOVE_SLUDGE_BOMB,
                MOVE_THUNDERBOLT,
                MOVE_EXPLOSION,
                MOVE_SHADOW_BALL,
            },
            },
            {
#line 9603
            .species = SPECIES_HOUNDOOM,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9605
            .iv = TRAINER_PARTY_IVS(24, 24, 24, 24, 24, 24),
#line 9604
            .lvl = 55,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 9606
                MOVE_FLAMETHROWER,
                MOVE_CRUNCH,
                MOVE_IRON_TAIL,
                MOVE_SHADOW_BALL,
            },
            },
        },
    },
#line 9611
    [DIFFICULTY_NORMAL][TRAINER_SCIENTIST_GIDEON] =
    {
#line 9612
        .trainerName = _("GIDEON"),
#line 9613
        .trainerClass = TRAINER_CLASS_SCIENTIST,
#line 9614
        .trainerPic = TRAINER_PIC_SCIENTIST,
        .encounterMusic_gender =
#line 9616
            TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
#line 9617
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 9618
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 5,
        .party = (const struct TrainerMon[])
        {
            {
#line 9620
            .species = SPECIES_VOLTORB,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9622
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 9621
            .lvl = 46,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 9623
                MOVE_SWIFT,
                MOVE_SCREECH,
                MOVE_SPARK,
                MOVE_SONIC_BOOM,
            },
            },
            {
#line 9628
            .species = SPECIES_ELECTRODE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9630
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 9629
            .lvl = 46,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 9631
                MOVE_SPARK,
                MOVE_SONIC_BOOM,
                MOVE_SCREECH,
                MOVE_CHARGE,
            },
            },
            {
#line 9636
            .species = SPECIES_MAGNEMITE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9638
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 9637
            .lvl = 46,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 9639
                MOVE_SCREECH,
                MOVE_SWIFT,
                MOVE_SPARK,
                MOVE_THUNDER_WAVE,
            },
            },
            {
#line 9644
            .species = SPECIES_MAGNETON,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9646
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 9645
            .lvl = 46,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 9647
                MOVE_TRI_ATTACK,
                MOVE_SPARK,
                MOVE_THUNDER_WAVE,
                MOVE_SONIC_BOOM,
            },
            },
            {
#line 9652
            .species = SPECIES_PORYGON,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9654
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 9653
            .lvl = 46,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 9655
                MOVE_TRI_ATTACK,
                MOVE_CONVERSION,
                MOVE_RECOVER,
                MOVE_PSYBEAM,
            },
            },
        },
    },
#line 9660
    [DIFFICULTY_NORMAL][TRAINER_SWIMMER_FEMALE_AMARA] =
    {
#line 9661
        .trainerName = _("AMARA"),
#line 9662
        .trainerClass = TRAINER_CLASS_SWIMMER_F,
#line 9663
        .trainerPic = TRAINER_PIC_SWIMMER_F,
        .encounterMusic_gender =
#line 9665
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
#line 9666
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 9667
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 9669
            .species = SPECIES_SEEL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9671
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 9670
            .lvl = 36,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 9673
            .species = SPECIES_SEEL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9675
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 9674
            .lvl = 36,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 9677
            .species = SPECIES_DEWGONG,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9679
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 9678
            .lvl = 36,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 9681
    [DIFFICULTY_NORMAL][TRAINER_SWIMMER_FEMALE_MARIA] =
    {
#line 9682
        .trainerName = _("MARIA"),
#line 9683
        .trainerClass = TRAINER_CLASS_SWIMMER_F,
#line 9684
        .trainerPic = TRAINER_PIC_SWIMMER_F,
        .encounterMusic_gender =
#line 9686
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
#line 9687
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 9688
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 9690
            .species = SPECIES_SEADRA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9692
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 9691
            .lvl = 37,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 9694
            .species = SPECIES_SEADRA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9696
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 9695
            .lvl = 37,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 9698
    [DIFFICULTY_NORMAL][TRAINER_SWIMMER_FEMALE_ABIGAIL] =
    {
#line 9699
        .trainerName = _("ABIGAIL"),
#line 9700
        .trainerClass = TRAINER_CLASS_SWIMMER_F,
#line 9701
        .trainerPic = TRAINER_PIC_SWIMMER_F,
        .encounterMusic_gender =
#line 9703
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
#line 9704
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 9705
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 9707
            .species = SPECIES_PSYDUCK,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9709
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 9708
            .lvl = 35,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 9711
            .species = SPECIES_PSYDUCK,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9713
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 9712
            .lvl = 36,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 9715
            .species = SPECIES_GOLDUCK,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9717
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 9716
            .lvl = 37,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 9719
    [DIFFICULTY_NORMAL][TRAINER_SWIMMER_MALE_FINN] =
    {
#line 9720
        .trainerName = _("FINN"),
#line 9721
        .trainerClass = TRAINER_CLASS_SWIMMER_M,
#line 9722
        .trainerPic = TRAINER_PIC_SWIMMER_M,
        .encounterMusic_gender =
#line 9724
            TRAINER_ENCOUNTER_MUSIC_SWIMMER,
#line 9725
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 9726
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 9728
            .species = SPECIES_STARMIE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9730
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 9729
            .lvl = 38,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 9732
    [DIFFICULTY_NORMAL][TRAINER_SWIMMER_MALE_GARRETT] =
    {
#line 9733
        .trainerName = _("GARRETT"),
#line 9734
        .trainerClass = TRAINER_CLASS_SWIMMER_M,
#line 9735
        .trainerPic = TRAINER_PIC_SWIMMER_M,
        .encounterMusic_gender =
#line 9737
            TRAINER_ENCOUNTER_MUSIC_SWIMMER,
#line 9738
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 9739
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 9741
            .species = SPECIES_SHELLDER,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9743
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 9742
            .lvl = 35,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 9745
            .species = SPECIES_CLOYSTER,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9747
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 9746
            .lvl = 35,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 9749
            .species = SPECIES_WARTORTLE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9751
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 9750
            .lvl = 38,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 9753
    [DIFFICULTY_NORMAL][TRAINER_FISHERMAN_TOMMY] =
    {
#line 9754
        .trainerName = _("TOMMY"),
#line 9755
        .trainerClass = TRAINER_CLASS_FISHERMAN,
#line 9756
        .trainerPic = TRAINER_PIC_FISHERMAN,
        .encounterMusic_gender =
#line 9758
            TRAINER_ENCOUNTER_MUSIC_HIKER,
#line 9759
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 9760
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 5,
        .party = (const struct TrainerMon[])
        {
            {
#line 9762
            .species = SPECIES_GOLDEEN,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9764
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 9763
            .lvl = 33,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 9766
            .species = SPECIES_GOLDEEN,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9768
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 9767
            .lvl = 33,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 9770
            .species = SPECIES_SEAKING,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9772
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 9771
            .lvl = 35,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 9774
            .species = SPECIES_SEAKING,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9776
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 9775
            .lvl = 35,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 9778
            .species = SPECIES_SEAKING,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9780
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 9779
            .lvl = 35,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 9782
    [DIFFICULTY_NORMAL][TRAINER_CRUSH_GIRL_TANYA] =
    {
#line 9783
        .trainerName = _("TANYA"),
#line 9784
        .trainerClass = TRAINER_CLASS_CRUSH_GIRL,
#line 9785
        .trainerPic = TRAINER_PIC_CRUSH_GIRL,
        .encounterMusic_gender =
#line 9787
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
#line 9788
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 9789
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 9791
            .species = SPECIES_HITMONLEE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9791
            .heldItem = ITEM_BLACK_BELT,
#line 9793
            .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
#line 9792
            .lvl = 38,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 9795
            .species = SPECIES_HITMONCHAN,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9795
            .heldItem = ITEM_BLACK_BELT,
#line 9797
            .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
#line 9796
            .lvl = 38,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 9799
    [DIFFICULTY_NORMAL][TRAINER_BLACK_BELT_SHEA] =
    {
#line 9800
        .trainerName = _("SHEA"),
#line 9801
        .trainerClass = TRAINER_CLASS_BLACK_BELT,
#line 9802
        .trainerPic = TRAINER_PIC_BLACK_BELT,
        .encounterMusic_gender =
#line 9804
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
#line 9805
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 9806
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 9808
            .species = SPECIES_MACHOP,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9808
            .heldItem = ITEM_BLACK_BELT,
#line 9810
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 9809
            .lvl = 38,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 9812
            .species = SPECIES_MACHOKE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9812
            .heldItem = ITEM_BLACK_BELT,
#line 9814
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 9813
            .lvl = 38,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 9816
    [DIFFICULTY_NORMAL][TRAINER_BLACK_BELT_HUGH] =
    {
#line 9817
        .trainerName = _("HUGH"),
#line 9818
        .trainerClass = TRAINER_CLASS_BLACK_BELT,
#line 9819
        .trainerPic = TRAINER_PIC_BLACK_BELT,
        .encounterMusic_gender =
#line 9821
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
#line 9822
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 9823
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 9825
            .species = SPECIES_MACHOP,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9825
            .heldItem = ITEM_BLACK_BELT,
#line 9827
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 9826
            .lvl = 37,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 9829
            .species = SPECIES_MACHOKE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9829
            .heldItem = ITEM_BLACK_BELT,
#line 9831
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 9830
            .lvl = 37,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 9833
    [DIFFICULTY_NORMAL][TRAINER_CAMPER_BRYCE] =
    {
#line 9834
        .trainerName = _("BRYCE"),
#line 9835
        .trainerClass = TRAINER_CLASS_CAMPER,
#line 9836
        .trainerPic = TRAINER_PIC_CAMPER,
        .encounterMusic_gender =
#line 9838
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 9839
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 9840
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 9842
            .species = SPECIES_NIDORINO,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9844
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 9843
            .lvl = 36,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 9846
            .species = SPECIES_RATICATE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9848
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 9847
            .lvl = 36,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 9850
            .species = SPECIES_SANDSLASH,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9852
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 9851
            .lvl = 36,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 9854
    [DIFFICULTY_NORMAL][TRAINER_PICNICKER_CLAIRE] =
    {
#line 9855
        .trainerName = _("CLAIRE"),
#line 9856
        .trainerClass = TRAINER_CLASS_PICNICKER,
#line 9857
        .trainerPic = TRAINER_PIC_PICNICKER,
        .encounterMusic_gender =
#line 9859
            TRAINER_ENCOUNTER_MUSIC_GIRL,
#line 9860
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 9861
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 4,
        .party = (const struct TrainerMon[])
        {
            {
#line 9863
            .species = SPECIES_MEOWTH,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9865
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 9864
            .lvl = 35,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 9867
            .species = SPECIES_MEOWTH,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9869
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 9868
            .lvl = 35,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 9871
            .species = SPECIES_PIKACHU,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9873
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 9872
            .lvl = 35,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 9875
            .species = SPECIES_CLEFAIRY,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9877
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 9876
            .lvl = 35,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 9879
    [DIFFICULTY_NORMAL][TRAINER_CRUSH_KIN_MIK_KIA] =
    {
#line 9880
        .trainerName = _("MIK & KIA"),
#line 9881
        .trainerClass = TRAINER_CLASS_CRUSH_KIN,
#line 9882
        .trainerPic = TRAINER_PIC_CRUSH_KIN,
        .encounterMusic_gender =
#line 9884
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
#line 9885
        .battleType = TRAINER_BATTLE_TYPE_DOUBLES,
#line 9886
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 9888
            .species = SPECIES_MACHOKE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9888
            .heldItem = ITEM_BLACK_BELT,
#line 9890
            .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
#line 9889
            .lvl = 39,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 9892
            .species = SPECIES_PRIMEAPE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9892
            .heldItem = ITEM_BLACK_BELT,
#line 9894
            .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
#line 9893
            .lvl = 39,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 9896
    [DIFFICULTY_NORMAL][TRAINER_AROMA_LADY_VIOLET] =
    {
#line 9897
        .trainerName = _("VIOLET"),
#line 9898
        .trainerClass = TRAINER_CLASS_AROMA_LADY,
#line 9899
        .trainerPic = TRAINER_PIC_AROMA_LADY,
        .encounterMusic_gender =
#line 9901
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
#line 9902
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 9903
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 9905
            .species = SPECIES_BULBASAUR,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9907
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 9906
            .lvl = 36,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 9909
            .species = SPECIES_IVYSAUR,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9911
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 9910
            .lvl = 36,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 9913
            .species = SPECIES_IVYSAUR,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9915
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 9914
            .lvl = 36,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 9917
    [DIFFICULTY_NORMAL][TRAINER_TUBER_ALEXIS] =
    {
#line 9918
        .trainerName = _("ALEXIS"),
#line 9919
        .trainerClass = TRAINER_CLASS_TUBER,
#line 9920
        .trainerPic = TRAINER_PIC_TUBER_F,
        .encounterMusic_gender =
#line 9922
            TRAINER_ENCOUNTER_MUSIC_GIRL,
#line 9923
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 9924
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 4,
        .party = (const struct TrainerMon[])
        {
            {
#line 9926
            .species = SPECIES_STARYU,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9928
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 9927
            .lvl = 34,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 9930
            .species = SPECIES_STARYU,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9932
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 9931
            .lvl = 34,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 9934
            .species = SPECIES_KRABBY,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9936
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 9935
            .lvl = 34,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 9938
            .species = SPECIES_KRABBY,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9940
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 9939
            .lvl = 34,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 9942
    [DIFFICULTY_NORMAL][TRAINER_TWINS_JOY_MEG] =
    {
#line 9943
        .trainerName = _("JOY & MEG"),
#line 9944
        .trainerClass = TRAINER_CLASS_TWINS,
#line 9945
        .trainerPic = TRAINER_PIC_TWINS,
        .encounterMusic_gender =
#line 9947
            TRAINER_ENCOUNTER_MUSIC_TWINS,
#line 9948
        .battleType = TRAINER_BATTLE_TYPE_DOUBLES,
#line 9949
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 9951
            .species = SPECIES_CLEFAIRY,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9953
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 9952
            .lvl = 37,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 9955
            .species = SPECIES_CLEFAIRY,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9957
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 9956
            .lvl = 37,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 9959
    [DIFFICULTY_NORMAL][TRAINER_SWIMMER_FEMALE_TISHA] =
    {
#line 9960
        .trainerName = _("TISHA"),
#line 9961
        .trainerClass = TRAINER_CLASS_SWIMMER_F,
#line 9962
        .trainerPic = TRAINER_PIC_SWIMMER_F,
        .encounterMusic_gender =
#line 9964
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
#line 9965
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 9966
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 9968
            .species = SPECIES_KINGLER,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9970
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 9969
            .lvl = 38,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 9972
    [DIFFICULTY_NORMAL][TRAINER_PAINTER_CELINA] =
    {
#line 9973
        .trainerName = _("CELINA"),
#line 9974
        .trainerClass = TRAINER_CLASS_PAINTER,
#line 9975
        .trainerPic = TRAINER_PIC_PAINTER,
        .encounterMusic_gender =
#line 9977
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
#line 9978
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 9979
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 9981
            .species = SPECIES_SMEARGLE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9983
            .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
#line 9982
            .lvl = 50,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 9984
                MOVE_FLY,
                MOVE_DIG,
                MOVE_DIVE,
                MOVE_BOUNCE,
            },
            },
        },
    },
#line 9989
    [DIFFICULTY_NORMAL][TRAINER_PAINTER_RAYNA] =
    {
#line 9990
        .trainerName = _("RAYNA"),
#line 9991
        .trainerClass = TRAINER_CLASS_PAINTER,
#line 9992
        .trainerPic = TRAINER_PIC_PAINTER,
        .encounterMusic_gender =
#line 9994
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
#line 9995
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 9996
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 9998
            .species = SPECIES_SMEARGLE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10000
            .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
#line 9999
            .lvl = 50,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 10001
                MOVE_CROSS_CHOP,
                MOVE_MEGAHORN,
                MOVE_DOUBLE_EDGE,
                MOVE_SELF_DESTRUCT,
            },
            },
        },
    },
#line 10006
    [DIFFICULTY_NORMAL][TRAINER_LADY_GILLIAN] =
    {
#line 10007
        .trainerName = _("GILLIAN"),
#line 10008
        .trainerClass = TRAINER_CLASS_LADY,
#line 10009
        .trainerPic = TRAINER_PIC_LADY,
        .encounterMusic_gender =
#line 10011
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
#line 10012
        .items = { ITEM_FULL_RESTORE },
#line 10013
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 10014
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 10016
            .species = SPECIES_MAREEP,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10016
            .heldItem = ITEM_STARDUST,
#line 10018
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 10017
            .lvl = 47,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 10020
            .species = SPECIES_MAREEP,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10020
            .heldItem = ITEM_STARDUST,
#line 10022
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 10021
            .lvl = 48,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 10024
            .species = SPECIES_FLAAFFY,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10024
            .heldItem = ITEM_NUGGET,
#line 10026
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 10025
            .lvl = 49,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 10028
    [DIFFICULTY_NORMAL][TRAINER_YOUNGSTER_DESTIN] =
    {
#line 10029
        .trainerName = _("DESTIN"),
#line 10030
        .trainerClass = TRAINER_CLASS_YOUNGSTER,
#line 10031
        .trainerPic = TRAINER_PIC_YOUNGSTER,
        .encounterMusic_gender =
#line 10033
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 10034
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 10035
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 10037
            .species = SPECIES_RATICATE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10039
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 10038
            .lvl = 48,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 10041
            .species = SPECIES_PIDGEOTTO,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10043
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 10042
            .lvl = 48,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 10045
    [DIFFICULTY_NORMAL][TRAINER_SWIMMER_MALE_TOBY] =
    {
#line 10046
        .trainerName = _("TOBY"),
#line 10047
        .trainerClass = TRAINER_CLASS_SWIMMER_M,
#line 10048
        .trainerPic = TRAINER_PIC_SWIMMER_M,
        .encounterMusic_gender =
#line 10050
            TRAINER_ENCOUNTER_MUSIC_SWIMMER,
#line 10051
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 10052
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 10054
            .species = SPECIES_POLIWHIRL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10056
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 10055
            .lvl = 48,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 10058
            .species = SPECIES_TENTACOOL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10060
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 10059
            .lvl = 48,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 10062
            .species = SPECIES_TENTACRUEL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10064
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 10063
            .lvl = 48,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 10066
    [DIFFICULTY_NORMAL][TRAINER_TEAM_ROCKET_GRUNT_49] =
    {
#line 10067
        .trainerName = _("GRUNT"),
#line 10068
        .trainerClass = TRAINER_CLASS_TEAM_ROCKET,
#line 10069
        .trainerPic = TRAINER_PIC_ROCKET_GRUNT_M,
        .encounterMusic_gender =
#line 10071
            TRAINER_ENCOUNTER_MUSIC_AQUA,
#line 10072
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 10073
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 10075
            .species = SPECIES_RATTATA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10077
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 10076
            .lvl = 48,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 10079
            .species = SPECIES_GRIMER,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10081
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 10080
            .lvl = 48,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 10083
            .species = SPECIES_MUK,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10085
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 10084
            .lvl = 48,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 10087
    [DIFFICULTY_NORMAL][TRAINER_TEAM_ROCKET_GRUNT_50] =
    {
#line 10088
        .trainerName = _("GRUNT"),
#line 10089
        .trainerClass = TRAINER_CLASS_TEAM_ROCKET,
#line 10090
        .trainerPic = TRAINER_PIC_ROCKET_GRUNT_M,
        .encounterMusic_gender =
#line 10092
            TRAINER_ENCOUNTER_MUSIC_AQUA,
#line 10093
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 10094
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 10096
            .species = SPECIES_KOFFING,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10098
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 10097
            .lvl = 49,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 10099
                MOVE_MEMENTO,
                MOVE_HAZE,
                MOVE_SMOKESCREEN,
                MOVE_SLUDGE,
            },
            },
            {
#line 10104
            .species = SPECIES_WEEZING,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10106
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 10105
            .lvl = 49,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 10107
                MOVE_HAZE,
                MOVE_SMOKESCREEN,
                MOVE_SLUDGE,
                MOVE_SELF_DESTRUCT,
            },
            },
        },
    },
#line 10112
    [DIFFICULTY_NORMAL][TRAINER_TEAM_ROCKET_GRUNT_51] =
    {
#line 10113
        .trainerName = _("GRUNT"),
#line 10114
        .trainerClass = TRAINER_CLASS_TEAM_ROCKET,
#line 10115
        .trainerPic = TRAINER_PIC_ROCKET_GRUNT_F,
        .encounterMusic_gender =
#line 10117
            TRAINER_ENCOUNTER_MUSIC_AQUA,
#line 10118
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 10119
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 10121
            .species = SPECIES_EKANS,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10123
            .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
#line 10122
            .lvl = 48,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 10125
            .species = SPECIES_GLOOM,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10127
            .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
#line 10126
            .lvl = 48,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 10129
            .species = SPECIES_GLOOM,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10131
            .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
#line 10130
            .lvl = 48,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 10133
    [DIFFICULTY_NORMAL][TRAINER_BIRD_KEEPER_MILO] =
    {
#line 10134
        .trainerName = _("MILO"),
#line 10135
        .trainerClass = TRAINER_CLASS_BIRD_KEEPER,
#line 10136
        .trainerPic = TRAINER_PIC_BIRD_KEEPER,
        .encounterMusic_gender =
#line 10138
            TRAINER_ENCOUNTER_MUSIC_COOL,
#line 10139
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 10140
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 10142
            .species = SPECIES_PIDGEY,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10144
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 10143
            .lvl = 47,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 10146
            .species = SPECIES_PIDGEOTTO,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10148
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 10147
            .lvl = 49,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 10150
    [DIFFICULTY_NORMAL][TRAINER_BIRD_KEEPER_CHAZ] =
    {
#line 10151
        .trainerName = _("CHAZ"),
#line 10152
        .trainerClass = TRAINER_CLASS_BIRD_KEEPER,
#line 10153
        .trainerPic = TRAINER_PIC_BIRD_KEEPER,
        .encounterMusic_gender =
#line 10155
            TRAINER_ENCOUNTER_MUSIC_COOL,
#line 10156
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 10157
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 10159
            .species = SPECIES_SPEAROW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10161
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 10160
            .lvl = 47,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 10163
            .species = SPECIES_FEAROW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10165
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 10164
            .lvl = 49,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 10167
    [DIFFICULTY_NORMAL][TRAINER_BIRD_KEEPER_HAROLD] =
    {
#line 10168
        .trainerName = _("HAROLD"),
#line 10169
        .trainerClass = TRAINER_CLASS_BIRD_KEEPER,
#line 10170
        .trainerPic = TRAINER_PIC_BIRD_KEEPER,
        .encounterMusic_gender =
#line 10172
            TRAINER_ENCOUNTER_MUSIC_COOL,
#line 10173
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 10174
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 10176
            .species = SPECIES_HOOTHOOT,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10178
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 10177
            .lvl = 47,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 10180
            .species = SPECIES_NOCTOWL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10182
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 10181
            .lvl = 49,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 10184
    [DIFFICULTY_NORMAL][TRAINER_FISHERMAN_TYLOR] =
    {
#line 10185
        .trainerName = _("TYLOR"),
#line 10186
        .trainerClass = TRAINER_CLASS_FISHERMAN,
#line 10187
        .trainerPic = TRAINER_PIC_FISHERMAN,
        .encounterMusic_gender =
#line 10189
            TRAINER_ENCOUNTER_MUSIC_HIKER,
#line 10190
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 10191
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 10193
            .species = SPECIES_QWILFISH,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10195
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 10194
            .lvl = 49,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 10197
            .species = SPECIES_QWILFISH,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10199
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 10198
            .lvl = 49,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 10201
    [DIFFICULTY_NORMAL][TRAINER_SWIMMER_MALE_MYMO] =
    {
#line 10202
        .trainerName = _("MYMO"),
#line 10203
        .trainerClass = TRAINER_CLASS_SWIMMER_M,
#line 10204
        .trainerPic = TRAINER_PIC_SWIMMER_M,
        .encounterMusic_gender =
#line 10206
            TRAINER_ENCOUNTER_MUSIC_SWIMMER,
#line 10207
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 10208
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 10210
            .species = SPECIES_KINGLER,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10212
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 10211
            .lvl = 49,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 10214
            .species = SPECIES_WARTORTLE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10216
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 10215
            .lvl = 49,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 10218
    [DIFFICULTY_NORMAL][TRAINER_SWIMMER_FEMALE_NICOLE] =
    {
#line 10219
        .trainerName = _("NICOLE"),
#line 10220
        .trainerClass = TRAINER_CLASS_SWIMMER_F,
#line 10221
        .trainerPic = TRAINER_PIC_SWIMMER_F,
        .encounterMusic_gender =
#line 10223
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
#line 10224
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 10225
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 10227
            .species = SPECIES_MARILL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10229
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 10228
            .lvl = 50,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 10231
    [DIFFICULTY_NORMAL][TRAINER_SIS_AND_BRO_AVA_GEB] =
    {
#line 10232
        .trainerName = _("AVA & GEB"),
#line 10233
        .trainerClass = TRAINER_CLASS_SIS_AND_BRO,
#line 10234
        .trainerPic = TRAINER_PIC_SIS_AND_BRO,
        .encounterMusic_gender =
#line 10236
            TRAINER_ENCOUNTER_MUSIC_SWIMMER,
#line 10237
        .battleType = TRAINER_BATTLE_TYPE_DOUBLES,
#line 10238
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 10240
            .species = SPECIES_POLIWHIRL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10242
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 10241
            .lvl = 50,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 10244
            .species = SPECIES_STARMIE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10246
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 10245
            .lvl = 50,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 10248
    [DIFFICULTY_NORMAL][TRAINER_AROMA_LADY_ROSE] =
    {
#line 10249
        .trainerName = _("ROSE"),
#line 10250
        .trainerClass = TRAINER_CLASS_AROMA_LADY,
#line 10251
        .trainerPic = TRAINER_PIC_AROMA_LADY,
        .encounterMusic_gender =
#line 10253
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
#line 10254
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 10255
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 10257
            .species = SPECIES_SUNKERN,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10259
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 10258
            .lvl = 49,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 10261
            .species = SPECIES_SUNFLORA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10263
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 10262
            .lvl = 49,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 10265
    [DIFFICULTY_NORMAL][TRAINER_SWIMMER_MALE_SAMIR] =
    {
#line 10266
        .trainerName = _("SAMIR"),
#line 10267
        .trainerClass = TRAINER_CLASS_SWIMMER_M,
#line 10268
        .trainerPic = TRAINER_PIC_SWIMMER_M,
        .encounterMusic_gender =
#line 10270
            TRAINER_ENCOUNTER_MUSIC_SWIMMER,
#line 10271
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 10272
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 10274
            .species = SPECIES_GYARADOS,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10276
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 10275
            .lvl = 50,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 10278
    [DIFFICULTY_NORMAL][TRAINER_SWIMMER_FEMALE_DENISE] =
    {
#line 10279
        .trainerName = _("DENISE"),
#line 10280
        .trainerClass = TRAINER_CLASS_SWIMMER_F,
#line 10281
        .trainerPic = TRAINER_PIC_SWIMMER_F,
        .encounterMusic_gender =
#line 10283
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
#line 10284
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 10285
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 10287
            .species = SPECIES_CHINCHOU,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10289
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 10288
            .lvl = 49,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 10291
            .species = SPECIES_LANTURN,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10293
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 10292
            .lvl = 49,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 10295
    [DIFFICULTY_NORMAL][TRAINER_TWINS_MIU_MIA] =
    {
#line 10296
        .trainerName = _("MIU & MIA"),
#line 10297
        .trainerClass = TRAINER_CLASS_TWINS,
#line 10298
        .trainerPic = TRAINER_PIC_TWINS,
        .encounterMusic_gender =
#line 10300
            TRAINER_ENCOUNTER_MUSIC_TWINS,
#line 10301
        .battleType = TRAINER_BATTLE_TYPE_DOUBLES,
#line 10302
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 10304
            .species = SPECIES_PIKACHU,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10306
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 10305
            .lvl = 50,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 10308
            .species = SPECIES_PIKACHU,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10310
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 10309
            .lvl = 50,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 10312
    [DIFFICULTY_NORMAL][TRAINER_HIKER_EARL] =
    {
#line 10313
        .trainerName = _("EARL"),
#line 10314
        .trainerClass = TRAINER_CLASS_HIKER,
#line 10315
        .trainerPic = TRAINER_PIC_HIKER,
        .encounterMusic_gender =
#line 10317
            TRAINER_ENCOUNTER_MUSIC_HIKER,
#line 10318
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 10319
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 10321
            .species = SPECIES_ONIX,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10323
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 10322
            .lvl = 49,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 10325
            .species = SPECIES_MACHOKE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10327
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 10326
            .lvl = 49,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 10329
    [DIFFICULTY_NORMAL][TRAINER_RUIN_MANIAC_FOSTER] =
    {
#line 10330
        .trainerName = _("FOSTER"),
#line 10331
        .trainerClass = TRAINER_CLASS_RUIN_MANIAC,
#line 10332
        .trainerPic = TRAINER_PIC_RUIN_MANIAC,
        .encounterMusic_gender =
#line 10334
            TRAINER_ENCOUNTER_MUSIC_HIKER,
#line 10335
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 10336
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 10338
            .species = SPECIES_GOLEM,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10340
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 10339
            .lvl = 50,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 10342
    [DIFFICULTY_NORMAL][TRAINER_RUIN_MANIAC_LARRY] =
    {
#line 10343
        .trainerName = _("LARRY"),
#line 10344
        .trainerClass = TRAINER_CLASS_RUIN_MANIAC,
#line 10345
        .trainerPic = TRAINER_PIC_RUIN_MANIAC,
        .encounterMusic_gender =
#line 10347
            TRAINER_ENCOUNTER_MUSIC_HIKER,
#line 10348
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 10349
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 10351
            .species = SPECIES_MACHOKE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10353
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 10352
            .lvl = 49,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 10355
            .species = SPECIES_MACHOKE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10357
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 10356
            .lvl = 49,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 10359
    [DIFFICULTY_NORMAL][TRAINER_HIKER_DARYL] =
    {
#line 10360
        .trainerName = _("DARYL"),
#line 10361
        .trainerClass = TRAINER_CLASS_HIKER,
#line 10362
        .trainerPic = TRAINER_PIC_HIKER,
        .encounterMusic_gender =
#line 10364
            TRAINER_ENCOUNTER_MUSIC_HIKER,
#line 10365
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 10366
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 10368
            .species = SPECIES_SUDOWOODO,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10370
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 10369
            .lvl = 50,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 10372
    [DIFFICULTY_NORMAL][TRAINER_POKEMANIAC_HECTOR] =
    {
#line 10373
        .trainerName = _("HECTOR"),
#line 10374
        .trainerClass = TRAINER_CLASS_POKEMANIAC,
#line 10375
        .trainerPic = TRAINER_PIC_POKEMANIAC,
        .encounterMusic_gender =
#line 10377
            TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
#line 10378
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 10379
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 10381
            .species = SPECIES_RHYHORN,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10383
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
#line 10382
            .lvl = 49,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 10385
            .species = SPECIES_KANGASKHAN,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10387
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
#line 10386
            .lvl = 49,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 10389
    [DIFFICULTY_NORMAL][TRAINER_PSYCHIC_DARIO] =
    {
#line 10390
        .trainerName = _("DARIO"),
#line 10391
        .trainerClass = TRAINER_CLASS_PSYCHIC,
#line 10392
        .trainerPic = TRAINER_PIC_PSYCHIC_M,
        .encounterMusic_gender =
#line 10394
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
#line 10395
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 10396
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 10398
            .species = SPECIES_GIRAFARIG,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10400
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 10399
            .lvl = 52,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 10401
                MOVE_CRUNCH,
                MOVE_PSYBEAM,
                MOVE_ODOR_SLEUTH,
                MOVE_AGILITY,
            },
            },
        },
    },
#line 10406
    [DIFFICULTY_NORMAL][TRAINER_PSYCHIC_RODETTE] =
    {
#line 10407
        .trainerName = _("RODETTE"),
#line 10408
        .trainerClass = TRAINER_CLASS_PSYCHIC,
#line 10409
        .trainerPic = TRAINER_PIC_PSYCHIC_F,
        .encounterMusic_gender =
#line 10411
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
#line 10412
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 10413
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 10415
            .species = SPECIES_NATU,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10417
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 10416
            .lvl = 48,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 10418
                MOVE_NIGHT_SHADE,
                MOVE_CONFUSE_RAY,
                MOVE_WISH,
                MOVE_FUTURE_SIGHT,
            },
            },
            {
#line 10423
            .species = SPECIES_DROWZEE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10425
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 10424
            .lvl = 48,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 10426
                MOVE_PSYCHIC,
                MOVE_DISABLE,
                MOVE_PSYCH_UP,
                MOVE_FUTURE_SIGHT,
            },
            },
            {
#line 10431
            .species = SPECIES_HYPNO,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10433
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 10432
            .lvl = 50,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 10434
                MOVE_PSYCHIC,
                MOVE_HYPNOSIS,
                MOVE_PSYCH_UP,
                MOVE_FUTURE_SIGHT,
            },
            },
        },
    },
#line 10439
    [DIFFICULTY_NORMAL][TRAINER_AROMA_LADY_MIAH] =
    {
#line 10440
        .trainerName = _("MIAH"),
#line 10441
        .trainerClass = TRAINER_CLASS_AROMA_LADY,
#line 10442
        .trainerPic = TRAINER_PIC_AROMA_LADY,
        .encounterMusic_gender =
#line 10444
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
#line 10445
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 10446
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 10448
            .species = SPECIES_BELLOSSOM,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10450
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 10449
            .lvl = 50,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 10452
            .species = SPECIES_BELLOSSOM,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10454
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 10453
            .lvl = 50,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 10456
    [DIFFICULTY_NORMAL][TRAINER_YOUNG_COUPLE_EVE_JON] =
    {
#line 10457
        .trainerName = _("EVE & JON"),
#line 10458
        .trainerClass = TRAINER_CLASS_YOUNG_COUPLE,
#line 10459
        .trainerPic = TRAINER_PIC_YOUNG_COUPLE,
        .encounterMusic_gender =
#line 10461
            TRAINER_ENCOUNTER_MUSIC_GIRL,
#line 10462
        .battleType = TRAINER_BATTLE_TYPE_DOUBLES,
#line 10463
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 10465
            .species = SPECIES_GOLDUCK,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10467
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 10466
            .lvl = 50,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 10469
            .species = SPECIES_PSYDUCK,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10471
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 10470
            .lvl = 50,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 10473
    [DIFFICULTY_NORMAL][TRAINER_JUGGLER_MASON] =
    {
#line 10474
        .trainerName = _("MASON"),
#line 10475
        .trainerClass = TRAINER_CLASS_JUGGLER,
#line 10476
        .trainerPic = TRAINER_PIC_JUGGLER,
        .encounterMusic_gender =
#line 10478
            TRAINER_ENCOUNTER_MUSIC_HIKER,
#line 10479
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 10480
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 4,
        .party = (const struct TrainerMon[])
        {
            {
#line 10482
            .species = SPECIES_VOLTORB,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10484
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 10483
            .lvl = 47,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 10485
                MOVE_SWIFT,
                MOVE_LIGHT_SCREEN,
                MOVE_SPARK,
                MOVE_SONIC_BOOM,
            },
            },
            {
#line 10490
            .species = SPECIES_PINECO,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10492
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 10491
            .lvl = 47,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 10493
                MOVE_SPIKES,
                MOVE_BIDE,
                MOVE_RAPID_SPIN,
                MOVE_TAKE_DOWN,
            },
            },
            {
#line 10498
            .species = SPECIES_VOLTORB,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10500
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 10499
            .lvl = 47,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 10501
                MOVE_SWIFT,
                MOVE_LIGHT_SCREEN,
                MOVE_SPARK,
                MOVE_SONIC_BOOM,
            },
            },
            {
#line 10506
            .species = SPECIES_PINECO,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10508
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 10507
            .lvl = 47,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 10509
                MOVE_SPIKES,
                MOVE_BIDE,
                MOVE_RAPID_SPIN,
                MOVE_EXPLOSION,
            },
            },
        },
    },
#line 10514
    [DIFFICULTY_NORMAL][TRAINER_CRUSH_GIRL_CYNDY] =
    {
#line 10515
        .trainerName = _("CYNDY"),
#line 10516
        .trainerClass = TRAINER_CLASS_CRUSH_GIRL,
#line 10517
        .trainerPic = TRAINER_PIC_CRUSH_GIRL,
        .encounterMusic_gender =
#line 10519
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
#line 10520
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 10521
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 10523
            .species = SPECIES_PRIMEAPE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10523
            .heldItem = ITEM_BLACK_BELT,
#line 10525
            .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
#line 10524
            .lvl = 48,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 10527
            .species = SPECIES_HITMONTOP,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10527
            .heldItem = ITEM_BLACK_BELT,
#line 10529
            .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
#line 10528
            .lvl = 48,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 10531
            .species = SPECIES_MACHOKE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10531
            .heldItem = ITEM_BLACK_BELT,
#line 10533
            .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
#line 10532
            .lvl = 48,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 10535
    [DIFFICULTY_NORMAL][TRAINER_CRUSH_GIRL_JOCELYN] =
    {
#line 10536
        .trainerName = _("JOCELYN"),
#line 10537
        .trainerClass = TRAINER_CLASS_CRUSH_GIRL,
#line 10538
        .trainerPic = TRAINER_PIC_CRUSH_GIRL,
        .encounterMusic_gender =
#line 10540
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
#line 10541
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 10542
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 10544
            .species = SPECIES_HITMONCHAN,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10544
            .heldItem = ITEM_BLACK_BELT,
#line 10546
            .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
#line 10545
            .lvl = 38,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 10548
            .species = SPECIES_HITMONCHAN,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10548
            .heldItem = ITEM_BLACK_BELT,
#line 10550
            .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
#line 10549
            .lvl = 38,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 10552
    [DIFFICULTY_NORMAL][TRAINER_TAMER_EVAN] =
    {
#line 10553
        .trainerName = _("EVAN"),
#line 10554
        .trainerClass = TRAINER_CLASS_TAMER,
#line 10555
        .trainerPic = TRAINER_PIC_TAMER,
        .encounterMusic_gender =
#line 10557
            TRAINER_ENCOUNTER_MUSIC_HIKER,
#line 10558
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 10559
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 10561
            .species = SPECIES_SANDSLASH,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10563
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
#line 10562
            .lvl = 48,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 10565
            .species = SPECIES_LICKITUNG,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10567
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
#line 10566
            .lvl = 48,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 10569
            .species = SPECIES_URSARING,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10571
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
#line 10570
            .lvl = 49,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 10573
    [DIFFICULTY_NORMAL][TRAINER_POKEMANIAC_MARK_2] =
    {
#line 10574
        .trainerName = _("MARK"),
#line 10575
        .trainerClass = TRAINER_CLASS_POKEMANIAC,
#line 10576
        .trainerPic = TRAINER_PIC_POKEMANIAC,
        .encounterMusic_gender =
#line 10578
            TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
#line 10579
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 10580
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 10582
            .species = SPECIES_RHYHORN,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10584
            .iv = TRAINER_PARTY_IVS(10, 10, 10, 10, 10, 10),
#line 10583
            .lvl = 33,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 10586
            .species = SPECIES_LICKITUNG,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10588
            .iv = TRAINER_PARTY_IVS(10, 10, 10, 10, 10, 10),
#line 10587
            .lvl = 33,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 10590
    [DIFFICULTY_NORMAL][TRAINER_PKMN_RANGER_LOGAN] =
    {
#line 10591
        .trainerName = _("LOGAN"),
#line 10592
        .trainerClass = TRAINER_CLASS_PKMN_RANGER,
#line 10593
        .trainerPic = TRAINER_PIC_POKEMON_RANGER_M,
        .encounterMusic_gender =
#line 10595
            TRAINER_ENCOUNTER_MUSIC_COOL,
#line 10596
        .items = { ITEM_FULL_RESTORE },
#line 10597
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 10598
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 10600
            .species = SPECIES_EXEGGCUTE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10602
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 10601
            .lvl = 37,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 10603
                MOVE_SLEEP_POWDER,
                MOVE_POISON_POWDER,
                MOVE_STUN_SPORE,
                MOVE_CONFUSION,
            },
            },
            {
#line 10608
            .species = SPECIES_EXEGGUTOR,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10610
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 10609
            .lvl = 40,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 10611
                MOVE_EGG_BOMB,
                MOVE_STOMP,
                MOVE_CONFUSION,
                MOVE_HYPNOSIS,
            },
            },
        },
    },
#line 10616
    [DIFFICULTY_NORMAL][TRAINER_PKMN_RANGER_JACKSON] =
    {
#line 10617
        .trainerName = _("JACKSON"),
#line 10618
        .trainerClass = TRAINER_CLASS_PKMN_RANGER,
#line 10619
        .trainerPic = TRAINER_PIC_POKEMON_RANGER_M,
        .encounterMusic_gender =
#line 10621
            TRAINER_ENCOUNTER_MUSIC_COOL,
#line 10622
        .items = { ITEM_FULL_RESTORE },
#line 10623
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 10624
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 10626
            .species = SPECIES_TANGELA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10628
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 10627
            .lvl = 49,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 10629
                MOVE_SLAM,
                MOVE_MEGA_DRAIN,
                MOVE_BIND,
                MOVE_INGRAIN,
            },
            },
            {
#line 10634
            .species = SPECIES_EXEGGCUTE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10636
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 10635
            .lvl = 49,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 10637
                MOVE_CONFUSION,
                MOVE_POISON_POWDER,
                MOVE_BARRAGE,
                MOVE_REFLECT,
            },
            },
            {
#line 10642
            .species = SPECIES_EXEGGUTOR,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10644
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 10643
            .lvl = 49,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 10645
                MOVE_CONFUSION,
                MOVE_EGG_BOMB,
                MOVE_SLEEP_POWDER,
                MOVE_STOMP,
            },
            },
        },
    },
#line 10650
    [DIFFICULTY_NORMAL][TRAINER_PKMN_RANGER_BETH] =
    {
#line 10651
        .trainerName = _("BETH"),
#line 10652
        .trainerClass = TRAINER_CLASS_PKMN_RANGER,
#line 10653
        .trainerPic = TRAINER_PIC_POKEMON_RANGER_F,
        .encounterMusic_gender =
#line 10655
            TRAINER_ENCOUNTER_MUSIC_COOL,
#line 10656
        .items = { ITEM_FULL_RESTORE },
#line 10657
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 10658
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 10660
            .species = SPECIES_BELLSPROUT,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10662
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 10661
            .lvl = 38,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 10664
            .species = SPECIES_GLOOM,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10666
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 10665
            .lvl = 38,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 10668
            .species = SPECIES_GLOOM,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10670
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 10669
            .lvl = 38,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 10672
    [DIFFICULTY_NORMAL][TRAINER_PKMN_RANGER_KATELYN] =
    {
#line 10673
        .trainerName = _("KATELYN"),
#line 10674
        .trainerClass = TRAINER_CLASS_PKMN_RANGER,
#line 10675
        .trainerPic = TRAINER_PIC_POKEMON_RANGER_F,
        .encounterMusic_gender =
#line 10677
            TRAINER_ENCOUNTER_MUSIC_COOL,
#line 10678
        .items = { ITEM_FULL_RESTORE },
#line 10679
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 10680
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 10682
            .species = SPECIES_CHANSEY,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10684
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 10683
            .lvl = 52,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 10685
                MOVE_EGG_BOMB,
                MOVE_DEFENSE_CURL,
                MOVE_MINIMIZE,
                MOVE_SOFT_BOILED,
            },
            },
        },
    },
#line 10690
    [DIFFICULTY_NORMAL][TRAINER_COOLTRAINER_LEROY] =
    {
#line 10691
        .trainerName = _("LEROY"),
#line 10692
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
#line 10693
        .trainerPic = TRAINER_PIC_COOLTRAINER_M,
        .encounterMusic_gender =
#line 10695
            TRAINER_ENCOUNTER_MUSIC_COOL,
#line 10696
        .items = { ITEM_FULL_RESTORE },
#line 10697
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 10698
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .partySize = 5,
        .party = (const struct TrainerMon[])
        {
            {
#line 10700
            .species = SPECIES_RHYDON,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10702
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 10701
            .lvl = 47,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 10703
                MOVE_TAKE_DOWN,
                MOVE_HORN_DRILL,
                MOVE_ROCK_BLAST,
                MOVE_SCARY_FACE,
            },
            },
            {
#line 10708
            .species = SPECIES_SLOWBRO,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10710
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 10709
            .lvl = 48,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 10711
                MOVE_PSYCHIC,
                MOVE_HEADBUTT,
                MOVE_AMNESIA,
                MOVE_DISABLE,
            },
            },
            {
#line 10716
            .species = SPECIES_KANGASKHAN,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10718
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 10717
            .lvl = 47,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 10719
                MOVE_DIZZY_PUNCH,
                MOVE_BITE,
                MOVE_ENDURE,
                MOVE_REVERSAL,
            },
            },
            {
#line 10724
            .species = SPECIES_MACHOKE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10726
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 10725
            .lvl = 48,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 10727
                MOVE_CROSS_CHOP,
                MOVE_VITAL_THROW,
                MOVE_REVENGE,
                MOVE_SEISMIC_TOSS,
            },
            },
            {
#line 10732
            .species = SPECIES_URSARING,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10734
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 10733
            .lvl = 50,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 10735
                MOVE_SLASH,
                MOVE_FAINT_ATTACK,
                MOVE_SNORE,
                MOVE_REST,
            },
            },
        },
    },
#line 10740
    [DIFFICULTY_NORMAL][TRAINER_COOLTRAINER_MICHELLE] =
    {
#line 10741
        .trainerName = _("MICHELLE"),
#line 10742
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
#line 10743
        .trainerPic = TRAINER_PIC_COOLTRAINER_F,
        .encounterMusic_gender =
#line 10745
            TRAINER_ENCOUNTER_MUSIC_COOL,
#line 10746
        .items = { ITEM_HYPER_POTION },
#line 10747
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 10748
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .partySize = 5,
        .party = (const struct TrainerMon[])
        {
            {
#line 10750
            .species = SPECIES_PERSIAN,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10752
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 10751
            .lvl = 47,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 10753
                MOVE_SLASH,
                MOVE_SCREECH,
                MOVE_FAINT_ATTACK,
                MOVE_BITE,
            },
            },
            {
#line 10758
            .species = SPECIES_DEWGONG,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10760
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 10759
            .lvl = 47,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 10761
                MOVE_ICE_BEAM,
                MOVE_TAKE_DOWN,
                MOVE_ICY_WIND,
                MOVE_GROWL,
            },
            },
            {
#line 10766
            .species = SPECIES_NINETALES,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10768
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 10767
            .lvl = 48,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 10769
                MOVE_FLAMETHROWER,
                MOVE_CONFUSE_RAY,
                MOVE_WILL_O_WISP,
                MOVE_GRUDGE,
            },
            },
            {
#line 10774
            .species = SPECIES_RAPIDASH,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10776
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 10775
            .lvl = 48,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 10777
                MOVE_BOUNCE,
                MOVE_AGILITY,
                MOVE_FIRE_SPIN,
                MOVE_TAKE_DOWN,
            },
            },
            {
#line 10782
            .species = SPECIES_GIRAFARIG,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10784
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 10783
            .lvl = 50,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 10785
                MOVE_CRUNCH,
                MOVE_PSYBEAM,
                MOVE_STOMP,
                MOVE_ODOR_SLEUTH,
            },
            },
        },
    },
#line 10790
    [DIFFICULTY_NORMAL][TRAINER_COOL_COUPLE_LEX_NYA] =
    {
#line 10791
        .trainerName = _("LEX & NYA"),
#line 10792
        .trainerClass = TRAINER_CLASS_COOL_COUPLE,
#line 10793
        .trainerPic = TRAINER_PIC_COOL_COUPLE,
        .encounterMusic_gender =
#line 10795
            TRAINER_ENCOUNTER_MUSIC_COOL,
#line 10796
        .items = { ITEM_FULL_RESTORE, ITEM_FULL_RESTORE },
#line 10797
        .battleType = TRAINER_BATTLE_TYPE_DOUBLES,
#line 10798
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 10800
            .species = SPECIES_MILTANK,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10802
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 10801
            .lvl = 52,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 10803
                MOVE_BODY_SLAM,
                MOVE_MILK_DRINK,
                MOVE_GROWL,
                MOVE_DEFENSE_CURL,
            },
            },
            {
#line 10808
            .species = SPECIES_TAUROS,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10810
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 10809
            .lvl = 52,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 10811
                MOVE_THRASH,
                MOVE_HORN_ATTACK,
                MOVE_PURSUIT,
                MOVE_SWAGGER,
            },
            },
        },
    },
#line 10816
    [DIFFICULTY_NORMAL][TRAINER_RUIN_MANIAC_BRANDON] =
    {
#line 10817
        .trainerName = _("BRANDON"),
#line 10818
        .trainerClass = TRAINER_CLASS_RUIN_MANIAC,
#line 10819
        .trainerPic = TRAINER_PIC_RUIN_MANIAC,
        .encounterMusic_gender =
#line 10821
            TRAINER_ENCOUNTER_MUSIC_HIKER,
#line 10822
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 10823
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 10825
            .species = SPECIES_ONIX,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10827
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 10826
            .lvl = 50,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 10829
    [DIFFICULTY_NORMAL][TRAINER_RUIN_MANIAC_BENJAMIN] =
    {
#line 10830
        .trainerName = _("BENJAMIN"),
#line 10831
        .trainerClass = TRAINER_CLASS_RUIN_MANIAC,
#line 10832
        .trainerPic = TRAINER_PIC_RUIN_MANIAC,
        .encounterMusic_gender =
#line 10834
            TRAINER_ENCOUNTER_MUSIC_HIKER,
#line 10835
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 10836
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 10838
            .species = SPECIES_GEODUDE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10840
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 10839
            .lvl = 48,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 10841
                MOVE_EARTHQUAKE,
                MOVE_ROCK_BLAST,
                MOVE_ROLLOUT,
                MOVE_SELF_DESTRUCT,
            },
            },
            {
#line 10846
            .species = SPECIES_GRAVELER,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10848
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 10847
            .lvl = 48,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 10849
                MOVE_EARTHQUAKE,
                MOVE_ROCK_BLAST,
                MOVE_ROCK_THROW,
                MOVE_SELF_DESTRUCT,
            },
            },
            {
#line 10854
            .species = SPECIES_GRAVELER,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10856
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 10855
            .lvl = 48,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 10857
                MOVE_EARTHQUAKE,
                MOVE_ROCK_BLAST,
                MOVE_ROCK_THROW,
                MOVE_SELF_DESTRUCT,
            },
            },
        },
    },
#line 10862
    [DIFFICULTY_NORMAL][TRAINER_PAINTER_EDNA] =
    {
#line 10863
        .trainerName = _("EDNA"),
#line 10864
        .trainerClass = TRAINER_CLASS_PAINTER,
#line 10865
        .trainerPic = TRAINER_PIC_PAINTER,
        .encounterMusic_gender =
#line 10867
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
#line 10868
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 10869
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 10871
            .species = SPECIES_SMEARGLE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10873
            .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
#line 10872
            .lvl = 50,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 10874
                MOVE_FAKE_OUT,
                MOVE_EXTREME_SPEED,
                MOVE_PROTECT,
                MOVE_QUICK_ATTACK,
            },
            },
        },
    },
#line 10879
    [DIFFICULTY_NORMAL][TRAINER_GENTLEMAN_CLIFFORD] =
    {
#line 10880
        .trainerName = _("CLIFFORD"),
#line 10881
        .trainerClass = TRAINER_CLASS_GENTLEMAN,
#line 10882
        .trainerPic = TRAINER_PIC_GENTLEMAN,
        .encounterMusic_gender =
#line 10884
            TRAINER_ENCOUNTER_MUSIC_RICH,
#line 10885
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 10886
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 10888
            .species = SPECIES_MAROWAK,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10890
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 10889
            .lvl = 49,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 10892
            .species = SPECIES_GOLDUCK,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10894
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 10893
            .lvl = 49,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 10896
    [DIFFICULTY_NORMAL][TRAINER_LADY_SELPHY] =
    {
#line 10897
        .trainerName = _("SELPHY"),
#line 10898
        .trainerClass = TRAINER_CLASS_LADY,
#line 10899
        .trainerPic = TRAINER_PIC_LADY,
        .encounterMusic_gender =
#line 10901
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
#line 10902
        .items = { ITEM_FULL_RESTORE },
#line 10903
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 10904
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 10906
            .species = SPECIES_PERSIAN,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10906
            .heldItem = ITEM_NUGGET,
#line 10908
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 10907
            .lvl = 49,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 10909
                MOVE_PAY_DAY,
                MOVE_BITE,
                MOVE_TAUNT,
                MOVE_TORMENT,
            },
            },
            {
#line 10914
            .species = SPECIES_PERSIAN,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10914
            .heldItem = ITEM_NUGGET,
#line 10916
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 10915
            .lvl = 49,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 10917
                MOVE_PAY_DAY,
                MOVE_SCRATCH,
                MOVE_TORMENT,
                MOVE_TAUNT,
            },
            },
        },
    },
#line 10922
    [DIFFICULTY_NORMAL][TRAINER_RUIN_MANIAC_LAWSON] =
    {
#line 10923
        .trainerName = _("LAWSON"),
#line 10924
        .trainerClass = TRAINER_CLASS_RUIN_MANIAC,
#line 10925
        .trainerPic = TRAINER_PIC_RUIN_MANIAC,
        .encounterMusic_gender =
#line 10927
            TRAINER_ENCOUNTER_MUSIC_HIKER,
#line 10928
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 10929
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 10931
            .species = SPECIES_ONIX,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10933
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 10932
            .lvl = 47,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 10935
            .species = SPECIES_GRAVELER,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10937
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 10936
            .lvl = 48,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 10939
            .species = SPECIES_MAROWAK,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10941
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 10940
            .lvl = 49,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 10943
    [DIFFICULTY_NORMAL][TRAINER_PSYCHIC_LAURA] =
    {
#line 10944
        .trainerName = _("LAURA"),
#line 10945
        .trainerClass = TRAINER_CLASS_PSYCHIC,
#line 10946
        .trainerPic = TRAINER_PIC_PSYCHIC_F,
        .encounterMusic_gender =
#line 10948
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
#line 10949
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 10950
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 10952
            .species = SPECIES_NATU,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10954
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 10953
            .lvl = 48,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 10956
            .species = SPECIES_NATU,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10958
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 10957
            .lvl = 48,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 10960
            .species = SPECIES_XATU,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10962
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 10961
            .lvl = 49,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 10964
    [DIFFICULTY_NORMAL][TRAINER_PKMN_BREEDER_BETHANY] =
    {
#line 10965
        .trainerName = _("BETHANY"),
#line 10966
        .trainerClass = TRAINER_CLASS_PKMN_BREEDER,
#line 10967
        .trainerPic = TRAINER_PIC_POKEMON_BREEDER,
        .encounterMusic_gender =
#line 10969
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
#line 10970
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 10971
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 10973
            .species = SPECIES_CHANSEY,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10975
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
#line 10974
            .lvl = 50,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 10977
    [DIFFICULTY_NORMAL][TRAINER_PKMN_BREEDER_ALLISON] =
    {
#line 10978
        .trainerName = _("ALLISON"),
#line 10979
        .trainerClass = TRAINER_CLASS_PKMN_BREEDER,
#line 10980
        .trainerPic = TRAINER_PIC_POKEMON_BREEDER,
        .encounterMusic_gender =
#line 10982
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
#line 10983
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 10984
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 10986
            .species = SPECIES_CLEFAIRY,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10988
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
#line 10987
            .lvl = 48,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 10990
            .species = SPECIES_CLEFAIRY,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10992
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
#line 10991
            .lvl = 48,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 10994
            .species = SPECIES_CLEFABLE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10996
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
#line 10995
            .lvl = 48,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 10998
    [DIFFICULTY_NORMAL][TRAINER_BUG_CATCHER_GARRET] =
    {
#line 10999
        .trainerName = _("GARRET"),
#line 11000
        .trainerClass = TRAINER_CLASS_BUG_CATCHER,
#line 11001
        .trainerPic = TRAINER_PIC_BUG_CATCHER,
        .encounterMusic_gender =
#line 11003
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 11004
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 11005
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 11007
            .species = SPECIES_HERACROSS,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11009
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 11008
            .lvl = 49,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 11011
    [DIFFICULTY_NORMAL][TRAINER_BUG_CATCHER_JONAH] =
    {
#line 11012
        .trainerName = _("JONAH"),
#line 11013
        .trainerClass = TRAINER_CLASS_BUG_CATCHER,
#line 11014
        .trainerPic = TRAINER_PIC_BUG_CATCHER,
        .encounterMusic_gender =
#line 11016
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 11017
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 11018
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 4,
        .party = (const struct TrainerMon[])
        {
            {
#line 11020
            .species = SPECIES_YANMA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11022
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 11021
            .lvl = 45,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 11024
            .species = SPECIES_BEEDRILL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11026
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 11025
            .lvl = 45,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 11028
            .species = SPECIES_YANMA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11030
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 11029
            .lvl = 46,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 11032
            .species = SPECIES_BEEDRILL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11034
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 11033
            .lvl = 47,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 11036
    [DIFFICULTY_NORMAL][TRAINER_BUG_CATCHER_VANCE] =
    {
#line 11037
        .trainerName = _("VANCE"),
#line 11038
        .trainerClass = TRAINER_CLASS_BUG_CATCHER,
#line 11039
        .trainerPic = TRAINER_PIC_BUG_CATCHER,
        .encounterMusic_gender =
#line 11041
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 11042
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 11043
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 11045
            .species = SPECIES_VENONAT,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11047
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 11046
            .lvl = 48,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 11049
            .species = SPECIES_VENOMOTH,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11051
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 11050
            .lvl = 48,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 11053
    [DIFFICULTY_NORMAL][TRAINER_YOUNGSTER_NASH] =
    {
#line 11054
        .trainerName = _("NASH"),
#line 11055
        .trainerClass = TRAINER_CLASS_YOUNGSTER,
#line 11056
        .trainerPic = TRAINER_PIC_YOUNGSTER,
        .encounterMusic_gender =
#line 11058
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 11059
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 11060
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 11062
            .species = SPECIES_WEEPINBELL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11064
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 11063
            .lvl = 47,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 11066
            .species = SPECIES_WEEPINBELL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11068
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 11067
            .lvl = 47,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 11070
            .species = SPECIES_VICTREEBEL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11072
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 11071
            .lvl = 49,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 11074
    [DIFFICULTY_NORMAL][TRAINER_YOUNGSTER_CORDELL] =
    {
#line 11075
        .trainerName = _("CORDELL"),
#line 11076
        .trainerClass = TRAINER_CLASS_YOUNGSTER,
#line 11077
        .trainerPic = TRAINER_PIC_YOUNGSTER,
        .encounterMusic_gender =
#line 11079
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 11080
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 11081
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 11083
            .species = SPECIES_FARFETCHD,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11085
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 11084
            .lvl = 48,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 11087
            .species = SPECIES_FARFETCHD,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11089
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 11088
            .lvl = 48,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 11091
    [DIFFICULTY_NORMAL][TRAINER_LASS_DALIA] =
    {
#line 11092
        .trainerName = _("DALIA"),
#line 11093
        .trainerClass = TRAINER_CLASS_LASS,
#line 11094
        .trainerPic = TRAINER_PIC_LASS,
        .encounterMusic_gender =
#line 11096
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
#line 11097
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 11098
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 4,
        .party = (const struct TrainerMon[])
        {
            {
#line 11100
            .species = SPECIES_HOPPIP,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11102
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 11101
            .lvl = 46,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 11104
            .species = SPECIES_HOPPIP,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11106
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 11105
            .lvl = 47,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 11108
            .species = SPECIES_SKIPLOOM,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11110
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 11109
            .lvl = 47,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 11112
            .species = SPECIES_SKIPLOOM,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11114
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 11113
            .lvl = 48,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 11116
    [DIFFICULTY_NORMAL][TRAINER_LASS_JOANA] =
    {
#line 11117
        .trainerName = _("JOANA"),
#line 11118
        .trainerClass = TRAINER_CLASS_LASS,
#line 11119
        .trainerPic = TRAINER_PIC_LASS,
        .encounterMusic_gender =
#line 11121
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
#line 11122
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 11123
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 11125
            .species = SPECIES_SNUBBULL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11127
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 11126
            .lvl = 49,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 11129
    [DIFFICULTY_NORMAL][TRAINER_CAMPER_RILEY] =
    {
#line 11130
        .trainerName = _("RILEY"),
#line 11131
        .trainerClass = TRAINER_CLASS_CAMPER,
#line 11132
        .trainerPic = TRAINER_PIC_CAMPER,
        .encounterMusic_gender =
#line 11134
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 11135
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 11136
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 11138
            .species = SPECIES_PINSIR,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11140
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 11139
            .lvl = 49,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 11142
            .species = SPECIES_HERACROSS,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11144
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 11143
            .lvl = 50,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 11146
    [DIFFICULTY_NORMAL][TRAINER_PICNICKER_MARCY] =
    {
#line 11147
        .trainerName = _("MARCY"),
#line 11148
        .trainerClass = TRAINER_CLASS_PICNICKER,
#line 11149
        .trainerPic = TRAINER_PIC_PICNICKER,
        .encounterMusic_gender =
#line 11151
            TRAINER_ENCOUNTER_MUSIC_GIRL,
#line 11152
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 11153
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 11155
            .species = SPECIES_PARAS,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11157
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 11156
            .lvl = 48,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 11159
            .species = SPECIES_PARAS,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11161
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 11160
            .lvl = 48,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 11163
            .species = SPECIES_PARASECT,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11165
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 11164
            .lvl = 49,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 11167
    [DIFFICULTY_NORMAL][TRAINER_RUIN_MANIAC_LAYTON] =
    {
#line 11168
        .trainerName = _("LAYTON"),
#line 11169
        .trainerClass = TRAINER_CLASS_RUIN_MANIAC,
#line 11170
        .trainerPic = TRAINER_PIC_RUIN_MANIAC,
        .encounterMusic_gender =
#line 11172
            TRAINER_ENCOUNTER_MUSIC_HIKER,
#line 11173
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 11174
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 11176
            .species = SPECIES_SANDSLASH,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11178
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 11177
            .lvl = 48,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 11180
            .species = SPECIES_ONIX,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11182
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 11181
            .lvl = 48,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 11184
            .species = SPECIES_SANDSLASH,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11186
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 11185
            .lvl = 48,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 11188
    [DIFFICULTY_NORMAL][TRAINER_PICNICKER_KELSEY_2] =
    {
#line 11189
        .trainerName = _("KELSEY"),
#line 11190
        .trainerClass = TRAINER_CLASS_PICNICKER,
#line 11191
        .trainerPic = TRAINER_PIC_PICNICKER,
        .encounterMusic_gender =
#line 11193
            TRAINER_ENCOUNTER_MUSIC_GIRL,
#line 11194
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 11195
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 11197
            .species = SPECIES_NIDORAN_M,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11199
            .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
#line 11198
            .lvl = 21,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 11201
            .species = SPECIES_NIDORAN_F,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11203
            .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
#line 11202
            .lvl = 21,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 11205
    [DIFFICULTY_NORMAL][TRAINER_PICNICKER_KELSEY_3] =
    {
#line 11206
        .trainerName = _("KELSEY"),
#line 11207
        .trainerClass = TRAINER_CLASS_PICNICKER,
#line 11208
        .trainerPic = TRAINER_PIC_PICNICKER,
        .encounterMusic_gender =
#line 11210
            TRAINER_ENCOUNTER_MUSIC_GIRL,
#line 11211
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 11212
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 11214
            .species = SPECIES_NIDORINO,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11216
            .iv = TRAINER_PARTY_IVS(7, 7, 7, 7, 7, 7),
#line 11215
            .lvl = 29,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 11218
            .species = SPECIES_NIDORINA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11220
            .iv = TRAINER_PARTY_IVS(7, 7, 7, 7, 7, 7),
#line 11219
            .lvl = 29,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 11222
    [DIFFICULTY_NORMAL][TRAINER_PICNICKER_KELSEY_4] =
    {
#line 11223
        .trainerName = _("KELSEY"),
#line 11224
        .trainerClass = TRAINER_CLASS_PICNICKER,
#line 11225
        .trainerPic = TRAINER_PIC_PICNICKER,
        .encounterMusic_gender =
#line 11227
            TRAINER_ENCOUNTER_MUSIC_GIRL,
#line 11228
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 11229
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 11231
            .species = SPECIES_NIDORINO,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11233
            .iv = TRAINER_PARTY_IVS(9, 9, 9, 9, 9, 9),
#line 11232
            .lvl = 49,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 11235
            .species = SPECIES_NIDORINA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11237
            .iv = TRAINER_PARTY_IVS(9, 9, 9, 9, 9, 9),
#line 11236
            .lvl = 49,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 11239
    [DIFFICULTY_NORMAL][TRAINER_CAMPER_RICKY_2] =
    {
#line 11240
        .trainerName = _("RICKY"),
#line 11241
        .trainerClass = TRAINER_CLASS_CAMPER,
#line 11242
        .trainerPic = TRAINER_PIC_CAMPER,
        .encounterMusic_gender =
#line 11244
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 11245
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 11246
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 11248
            .species = SPECIES_SQUIRTLE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11250
            .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
#line 11249
            .lvl = 22,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 11252
    [DIFFICULTY_NORMAL][TRAINER_CAMPER_RICKY_3] =
    {
#line 11253
        .trainerName = _("RICKY"),
#line 11254
        .trainerClass = TRAINER_CLASS_CAMPER,
#line 11255
        .trainerPic = TRAINER_PIC_CAMPER,
        .encounterMusic_gender =
#line 11257
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 11258
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 11259
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 11261
            .species = SPECIES_WARTORTLE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11263
            .iv = TRAINER_PARTY_IVS(7, 7, 7, 7, 7, 7),
#line 11262
            .lvl = 30,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 11265
    [DIFFICULTY_NORMAL][TRAINER_CAMPER_RICKY_4] =
    {
#line 11266
        .trainerName = _("RICKY"),
#line 11267
        .trainerClass = TRAINER_CLASS_CAMPER,
#line 11268
        .trainerPic = TRAINER_PIC_CAMPER,
        .encounterMusic_gender =
#line 11270
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 11271
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 11272
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 11274
            .species = SPECIES_WARTORTLE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11276
            .iv = TRAINER_PARTY_IVS(14, 14, 14, 14, 14, 14),
#line 11275
            .lvl = 55,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 11278
    [DIFFICULTY_NORMAL][TRAINER_CAMPER_JEFF_2] =
    {
#line 11279
        .trainerName = _("JEFF"),
#line 11280
        .trainerClass = TRAINER_CLASS_CAMPER,
#line 11281
        .trainerPic = TRAINER_PIC_CAMPER,
        .encounterMusic_gender =
#line 11283
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 11284
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 11285
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 11287
            .species = SPECIES_SPEAROW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11289
            .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
#line 11288
            .lvl = 21,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 11291
            .species = SPECIES_RATICATE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11293
            .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
#line 11292
            .lvl = 21,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 11295
    [DIFFICULTY_NORMAL][TRAINER_CAMPER_JEFF_3] =
    {
#line 11296
        .trainerName = _("JEFF"),
#line 11297
        .trainerClass = TRAINER_CLASS_CAMPER,
#line 11298
        .trainerPic = TRAINER_PIC_CAMPER,
        .encounterMusic_gender =
#line 11300
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 11301
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 11302
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 11304
            .species = SPECIES_FEAROW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11306
            .iv = TRAINER_PARTY_IVS(7, 7, 7, 7, 7, 7),
#line 11305
            .lvl = 29,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 11308
            .species = SPECIES_RATICATE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11310
            .iv = TRAINER_PARTY_IVS(7, 7, 7, 7, 7, 7),
#line 11309
            .lvl = 29,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 11312
    [DIFFICULTY_NORMAL][TRAINER_CAMPER_JEFF_4] =
    {
#line 11313
        .trainerName = _("JEFF"),
#line 11314
        .trainerClass = TRAINER_CLASS_CAMPER,
#line 11315
        .trainerPic = TRAINER_PIC_CAMPER,
        .encounterMusic_gender =
#line 11317
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 11318
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 11319
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 11321
            .species = SPECIES_FEAROW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11323
            .iv = TRAINER_PARTY_IVS(14, 14, 14, 14, 14, 14),
#line 11322
            .lvl = 54,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 11325
            .species = SPECIES_RATICATE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11327
            .iv = TRAINER_PARTY_IVS(14, 14, 14, 14, 14, 14),
#line 11326
            .lvl = 54,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 11329
    [DIFFICULTY_NORMAL][TRAINER_PICNICKER_ISABELLE_2] =
    {
#line 11330
        .trainerName = _("ISABELLE"),
#line 11331
        .trainerClass = TRAINER_CLASS_PICNICKER,
#line 11332
        .trainerPic = TRAINER_PIC_PICNICKER,
        .encounterMusic_gender =
#line 11334
            TRAINER_ENCOUNTER_MUSIC_GIRL,
#line 11335
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 11336
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 11338
            .species = SPECIES_PIDGEOTTO,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11340
            .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
#line 11339
            .lvl = 21,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 11342
            .species = SPECIES_PIDGEOTTO,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11344
            .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
#line 11343
            .lvl = 21,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 11346
            .species = SPECIES_PIDGEY,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11348
            .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
#line 11347
            .lvl = 18,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 11350
    [DIFFICULTY_NORMAL][TRAINER_PICNICKER_ISABELLE_3] =
    {
#line 11351
        .trainerName = _("ISABELLE"),
#line 11352
        .trainerClass = TRAINER_CLASS_PICNICKER,
#line 11353
        .trainerPic = TRAINER_PIC_PICNICKER,
        .encounterMusic_gender =
#line 11355
            TRAINER_ENCOUNTER_MUSIC_GIRL,
#line 11356
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 11357
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 11359
            .species = SPECIES_PIDGEOTTO,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11361
            .iv = TRAINER_PARTY_IVS(7, 7, 7, 7, 7, 7),
#line 11360
            .lvl = 29,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 11363
            .species = SPECIES_PIDGEOTTO,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11365
            .iv = TRAINER_PARTY_IVS(7, 7, 7, 7, 7, 7),
#line 11364
            .lvl = 29,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 11367
            .species = SPECIES_PIDGEOTTO,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11369
            .iv = TRAINER_PARTY_IVS(7, 7, 7, 7, 7, 7),
#line 11368
            .lvl = 26,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 11371
    [DIFFICULTY_NORMAL][TRAINER_PICNICKER_ISABELLE_4] =
    {
#line 11372
        .trainerName = _("ISABELLE"),
#line 11373
        .trainerClass = TRAINER_CLASS_PICNICKER,
#line 11374
        .trainerPic = TRAINER_PIC_PICNICKER,
        .encounterMusic_gender =
#line 11376
            TRAINER_ENCOUNTER_MUSIC_GIRL,
#line 11377
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 11378
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 11380
            .species = SPECIES_PIDGEOTTO,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11382
            .iv = TRAINER_PARTY_IVS(9, 9, 9, 9, 9, 9),
#line 11381
            .lvl = 47,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 11384
            .species = SPECIES_PIDGEOTTO,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11386
            .iv = TRAINER_PARTY_IVS(9, 9, 9, 9, 9, 9),
#line 11385
            .lvl = 47,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 11388
            .species = SPECIES_PIDGEOT,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11390
            .iv = TRAINER_PARTY_IVS(9, 9, 9, 9, 9, 9),
#line 11389
            .lvl = 50,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 11392
    [DIFFICULTY_NORMAL][TRAINER_YOUNGSTER_YASU_2] =
    {
#line 11393
        .trainerName = _("YASU"),
#line 11394
        .trainerClass = TRAINER_CLASS_YOUNGSTER,
#line 11395
        .trainerPic = TRAINER_PIC_YOUNGSTER,
        .encounterMusic_gender =
#line 11397
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 11398
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 11399
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 11401
            .species = SPECIES_RATTATA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11403
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
#line 11402
            .lvl = 22,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 11405
            .species = SPECIES_RATICATE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11407
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
#line 11406
            .lvl = 22,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 11409
            .species = SPECIES_RATICATE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11411
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
#line 11410
            .lvl = 22,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 11413
    [DIFFICULTY_NORMAL][TRAINER_YOUNGSTER_YASU_3] =
    {
#line 11414
        .trainerName = _("YASU"),
#line 11415
        .trainerClass = TRAINER_CLASS_YOUNGSTER,
#line 11416
        .trainerPic = TRAINER_PIC_YOUNGSTER,
        .encounterMusic_gender =
#line 11418
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 11419
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 11420
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 11422
            .species = SPECIES_RATICATE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11424
            .iv = TRAINER_PARTY_IVS(9, 9, 9, 9, 9, 9),
#line 11423
            .lvl = 47,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 11426
            .species = SPECIES_RATICATE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11428
            .iv = TRAINER_PARTY_IVS(9, 9, 9, 9, 9, 9),
#line 11427
            .lvl = 47,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 11430
            .species = SPECIES_RATICATE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11432
            .iv = TRAINER_PARTY_IVS(9, 9, 9, 9, 9, 9),
#line 11431
            .lvl = 47,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 11434
    [DIFFICULTY_NORMAL][TRAINER_ENGINEER_BERNIE_2] =
    {
#line 11435
        .trainerName = _("BERNIE"),
#line 11436
        .trainerClass = TRAINER_CLASS_ENGINEER,
#line 11437
        .trainerPic = TRAINER_PIC_ENGINEER,
        .encounterMusic_gender =
#line 11439
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 11440
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 11441
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 11443
            .species = SPECIES_MAGNETON,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11445
            .iv = TRAINER_PARTY_IVS(7, 7, 7, 7, 7, 7),
#line 11444
            .lvl = 28,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 11447
            .species = SPECIES_MAGNETON,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11449
            .iv = TRAINER_PARTY_IVS(7, 7, 7, 7, 7, 7),
#line 11448
            .lvl = 28,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 11451
            .species = SPECIES_MAGNETON,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11453
            .iv = TRAINER_PARTY_IVS(7, 7, 7, 7, 7, 7),
#line 11452
            .lvl = 28,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 11455
    [DIFFICULTY_NORMAL][TRAINER_GAMER_DARIAN_2] =
    {
#line 11456
        .trainerName = _("DARIAN"),
#line 11457
        .trainerClass = TRAINER_CLASS_GAMER,
#line 11458
        .trainerPic = TRAINER_PIC_GAMER,
        .encounterMusic_gender =
#line 11460
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 11461
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 11462
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 11464
            .species = SPECIES_GROWLITHE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11466
            .iv = TRAINER_PARTY_IVS(7, 7, 7, 7, 7, 7),
#line 11465
            .lvl = 29,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 11468
            .species = SPECIES_VULPIX,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11470
            .iv = TRAINER_PARTY_IVS(7, 7, 7, 7, 7, 7),
#line 11469
            .lvl = 29,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 11472
    [DIFFICULTY_NORMAL][TRAINER_CAMPER_CHRIS_2] =
    {
#line 11473
        .trainerName = _("CHRIS"),
#line 11474
        .trainerClass = TRAINER_CLASS_CAMPER,
#line 11475
        .trainerPic = TRAINER_PIC_CAMPER,
        .encounterMusic_gender =
#line 11477
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 11478
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 11479
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 11481
            .species = SPECIES_GROWLITHE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11483
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
#line 11482
            .lvl = 24,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 11485
            .species = SPECIES_CHARMANDER,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11487
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
#line 11486
            .lvl = 24,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 11489
    [DIFFICULTY_NORMAL][TRAINER_CAMPER_CHRIS_3] =
    {
#line 11490
        .trainerName = _("CHRIS"),
#line 11491
        .trainerClass = TRAINER_CLASS_CAMPER,
#line 11492
        .trainerPic = TRAINER_PIC_CAMPER,
        .encounterMusic_gender =
#line 11494
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 11495
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 11496
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 11498
            .species = SPECIES_GROWLITHE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11500
            .iv = TRAINER_PARTY_IVS(7, 7, 7, 7, 7, 7),
#line 11499
            .lvl = 29,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 11502
            .species = SPECIES_CHARMELEON,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11504
            .iv = TRAINER_PARTY_IVS(7, 7, 7, 7, 7, 7),
#line 11503
            .lvl = 29,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 11506
    [DIFFICULTY_NORMAL][TRAINER_CAMPER_CHRIS_4] =
    {
#line 11507
        .trainerName = _("CHRIS"),
#line 11508
        .trainerClass = TRAINER_CLASS_CAMPER,
#line 11509
        .trainerPic = TRAINER_PIC_CAMPER,
        .encounterMusic_gender =
#line 11511
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 11512
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 11513
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 11515
            .species = SPECIES_ARCANINE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11517
            .iv = TRAINER_PARTY_IVS(14, 14, 14, 14, 14, 14),
#line 11516
            .lvl = 54,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 11519
            .species = SPECIES_CHARMELEON,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11521
            .iv = TRAINER_PARTY_IVS(14, 14, 14, 14, 14, 14),
#line 11520
            .lvl = 54,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 11523
    [DIFFICULTY_NORMAL][TRAINER_PICNICKER_ALICIA_2] =
    {
#line 11524
        .trainerName = _("ALICIA"),
#line 11525
        .trainerClass = TRAINER_CLASS_PICNICKER,
#line 11526
        .trainerPic = TRAINER_PIC_PICNICKER,
        .encounterMusic_gender =
#line 11528
            TRAINER_ENCOUNTER_MUSIC_GIRL,
#line 11529
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 11530
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 11532
            .species = SPECIES_MEOWTH,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11534
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
#line 11533
            .lvl = 25,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 11536
    [DIFFICULTY_NORMAL][TRAINER_PICNICKER_ALICIA_3] =
    {
#line 11537
        .trainerName = _("ALICIA"),
#line 11538
        .trainerClass = TRAINER_CLASS_PICNICKER,
#line 11539
        .trainerPic = TRAINER_PIC_PICNICKER,
        .encounterMusic_gender =
#line 11541
            TRAINER_ENCOUNTER_MUSIC_GIRL,
#line 11542
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 11543
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 11545
            .species = SPECIES_PERSIAN,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11547
            .iv = TRAINER_PARTY_IVS(7, 7, 7, 7, 7, 7),
#line 11546
            .lvl = 30,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 11549
    [DIFFICULTY_NORMAL][TRAINER_PICNICKER_ALICIA_4] =
    {
#line 11550
        .trainerName = _("ALICIA"),
#line 11551
        .trainerClass = TRAINER_CLASS_PICNICKER,
#line 11552
        .trainerPic = TRAINER_PIC_PICNICKER,
        .encounterMusic_gender =
#line 11554
            TRAINER_ENCOUNTER_MUSIC_GIRL,
#line 11555
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 11556
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 11558
            .species = SPECIES_PERSIAN,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11560
            .iv = TRAINER_PARTY_IVS(14, 14, 14, 14, 14, 14),
#line 11559
            .lvl = 55,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 11562
    [DIFFICULTY_NORMAL][TRAINER_HIKER_JEREMY_2] =
    {
#line 11563
        .trainerName = _("JEREMY"),
#line 11564
        .trainerClass = TRAINER_CLASS_HIKER,
#line 11565
        .trainerPic = TRAINER_PIC_HIKER,
        .encounterMusic_gender =
#line 11567
            TRAINER_ENCOUNTER_MUSIC_HIKER,
#line 11568
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 11569
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 11571
            .species = SPECIES_MACHOKE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11573
            .iv = TRAINER_PARTY_IVS(7, 7, 7, 7, 7, 7),
#line 11572
            .lvl = 30,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 11575
            .species = SPECIES_ONIX,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11577
            .iv = TRAINER_PARTY_IVS(7, 7, 7, 7, 7, 7),
#line 11576
            .lvl = 28,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 11579
    [DIFFICULTY_NORMAL][TRAINER_POKEMANIAC_MARK_3] =
    {
#line 11580
        .trainerName = _("MARK"),
#line 11581
        .trainerClass = TRAINER_CLASS_POKEMANIAC,
#line 11582
        .trainerPic = TRAINER_PIC_POKEMANIAC,
        .encounterMusic_gender =
#line 11584
            TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
#line 11585
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 11586
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 11588
            .species = SPECIES_RHYDON,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11590
            .iv = TRAINER_PARTY_IVS(18, 18, 18, 18, 18, 18),
#line 11589
            .lvl = 54,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 11592
            .species = SPECIES_LICKITUNG,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11594
            .iv = TRAINER_PARTY_IVS(18, 18, 18, 18, 18, 18),
#line 11593
            .lvl = 54,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 11596
    [DIFFICULTY_NORMAL][TRAINER_POKEMANIAC_HERMAN_2] =
    {
#line 11597
        .trainerName = _("HERMAN"),
#line 11598
        .trainerClass = TRAINER_CLASS_POKEMANIAC,
#line 11599
        .trainerPic = TRAINER_PIC_POKEMANIAC,
        .encounterMusic_gender =
#line 11601
            TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
#line 11602
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 11603
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 11605
            .species = SPECIES_MAROWAK,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11607
            .iv = TRAINER_PARTY_IVS(10, 10, 10, 10, 10, 10),
#line 11606
            .lvl = 29,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 11609
            .species = SPECIES_SLOWBRO,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11611
            .iv = TRAINER_PARTY_IVS(10, 10, 10, 10, 10, 10),
#line 11610
            .lvl = 29,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 11613
    [DIFFICULTY_NORMAL][TRAINER_POKEMANIAC_HERMAN_3] =
    {
#line 11614
        .trainerName = _("HERMAN"),
#line 11615
        .trainerClass = TRAINER_CLASS_POKEMANIAC,
#line 11616
        .trainerPic = TRAINER_PIC_POKEMANIAC,
        .encounterMusic_gender =
#line 11618
            TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
#line 11619
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 11620
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 11622
            .species = SPECIES_MAROWAK,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11624
            .iv = TRAINER_PARTY_IVS(18, 18, 18, 18, 18, 18),
#line 11623
            .lvl = 54,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 11626
            .species = SPECIES_SLOWBRO,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11628
            .iv = TRAINER_PARTY_IVS(18, 18, 18, 18, 18, 18),
#line 11627
            .lvl = 54,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 11630
    [DIFFICULTY_NORMAL][TRAINER_HIKER_TRENT_2] =
    {
#line 11631
        .trainerName = _("TRENT"),
#line 11632
        .trainerClass = TRAINER_CLASS_HIKER,
#line 11633
        .trainerPic = TRAINER_PIC_HIKER,
        .encounterMusic_gender =
#line 11635
            TRAINER_ENCOUNTER_MUSIC_HIKER,
#line 11636
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 11637
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 11639
            .species = SPECIES_ONIX,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11641
            .iv = TRAINER_PARTY_IVS(7, 7, 7, 7, 7, 7),
#line 11640
            .lvl = 31,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 11643
            .species = SPECIES_GRAVELER,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11645
            .iv = TRAINER_PARTY_IVS(7, 7, 7, 7, 7, 7),
#line 11644
            .lvl = 31,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 11647
    [DIFFICULTY_NORMAL][TRAINER_LASS_MEGAN_2] =
    {
#line 11648
        .trainerName = _("MEGAN"),
#line 11649
        .trainerClass = TRAINER_CLASS_LASS,
#line 11650
        .trainerPic = TRAINER_PIC_LASS,
        .encounterMusic_gender =
#line 11652
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
#line 11653
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 11654
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 5,
        .party = (const struct TrainerMon[])
        {
            {
#line 11656
            .species = SPECIES_PIDGEOTTO,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11658
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
#line 11657
            .lvl = 22,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 11660
            .species = SPECIES_RATICATE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11662
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
#line 11661
            .lvl = 22,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 11664
            .species = SPECIES_NIDORAN_M,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11666
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
#line 11665
            .lvl = 23,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 11668
            .species = SPECIES_MEOWTH,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11670
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
#line 11669
            .lvl = 21,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 11672
            .species = SPECIES_PIKACHU,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11674
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
#line 11673
            .lvl = 22,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 11676
    [DIFFICULTY_NORMAL][TRAINER_LASS_MEGAN_3] =
    {
#line 11677
        .trainerName = _("MEGAN"),
#line 11678
        .trainerClass = TRAINER_CLASS_LASS,
#line 11679
        .trainerPic = TRAINER_PIC_LASS,
        .encounterMusic_gender =
#line 11681
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
#line 11682
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 11683
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 5,
        .party = (const struct TrainerMon[])
        {
            {
#line 11685
            .species = SPECIES_PIDGEOT,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11687
            .iv = TRAINER_PARTY_IVS(9, 9, 9, 9, 9, 9),
#line 11686
            .lvl = 46,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 11689
            .species = SPECIES_RATICATE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11691
            .iv = TRAINER_PARTY_IVS(9, 9, 9, 9, 9, 9),
#line 11690
            .lvl = 47,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 11693
            .species = SPECIES_NIDORINO,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11695
            .iv = TRAINER_PARTY_IVS(9, 9, 9, 9, 9, 9),
#line 11694
            .lvl = 47,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 11697
            .species = SPECIES_PERSIAN,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11699
            .iv = TRAINER_PARTY_IVS(9, 9, 9, 9, 9, 9),
#line 11698
            .lvl = 47,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 11701
            .species = SPECIES_RAICHU,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11703
            .iv = TRAINER_PARTY_IVS(9, 9, 9, 9, 9, 9),
#line 11702
            .lvl = 48,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 11705
    [DIFFICULTY_NORMAL][TRAINER_SUPER_NERD_GLENN_2] =
    {
#line 11706
        .trainerName = _("GLENN"),
#line 11707
        .trainerClass = TRAINER_CLASS_SUPER_NERD,
#line 11708
        .trainerPic = TRAINER_PIC_SUPER_NERD,
        .encounterMusic_gender =
#line 11710
            TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
#line 11711
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 11712
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 11714
            .species = SPECIES_MUK,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11716
            .iv = TRAINER_PARTY_IVS(7, 7, 7, 7, 7, 7),
#line 11715
            .lvl = 28,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 11718
            .species = SPECIES_MUK,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11720
            .iv = TRAINER_PARTY_IVS(7, 7, 7, 7, 7, 7),
#line 11719
            .lvl = 28,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 11722
            .species = SPECIES_MUK,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11724
            .iv = TRAINER_PARTY_IVS(7, 7, 7, 7, 7, 7),
#line 11723
            .lvl = 28,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 11726
    [DIFFICULTY_NORMAL][TRAINER_GAMER_RICH_2] =
    {
#line 11727
        .trainerName = _("RICH"),
#line 11728
        .trainerClass = TRAINER_CLASS_GAMER,
#line 11729
        .trainerPic = TRAINER_PIC_GAMER,
        .encounterMusic_gender =
#line 11731
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 11732
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 11733
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 11735
            .species = SPECIES_GROWLITHE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11737
            .iv = TRAINER_PARTY_IVS(7, 7, 7, 7, 7, 7),
#line 11736
            .lvl = 30,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 11739
            .species = SPECIES_VULPIX,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11741
            .iv = TRAINER_PARTY_IVS(7, 7, 7, 7, 7, 7),
#line 11740
            .lvl = 30,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 11743
    [DIFFICULTY_NORMAL][TRAINER_BIKER_JAREN_2] =
    {
#line 11744
        .trainerName = _("JAREN"),
#line 11745
        .trainerClass = TRAINER_CLASS_BIKER,
#line 11746
        .trainerPic = TRAINER_PIC_BIKER,
        .encounterMusic_gender =
#line 11748
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 11749
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 11750
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 11752
            .species = SPECIES_MUK,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11754
            .iv = TRAINER_PARTY_IVS(7, 7, 7, 7, 7, 7),
#line 11753
            .lvl = 28,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 11756
            .species = SPECIES_MUK,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11758
            .iv = TRAINER_PARTY_IVS(7, 7, 7, 7, 7, 7),
#line 11757
            .lvl = 30,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 11760
    [DIFFICULTY_NORMAL][TRAINER_FISHERMAN_ELLIOT_2] =
    {
#line 11761
        .trainerName = _("ELLIOT"),
#line 11762
        .trainerClass = TRAINER_CLASS_FISHERMAN,
#line 11763
        .trainerPic = TRAINER_PIC_FISHERMAN,
        .encounterMusic_gender =
#line 11765
            TRAINER_ENCOUNTER_MUSIC_HIKER,
#line 11766
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 11767
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 4,
        .party = (const struct TrainerMon[])
        {
            {
#line 11769
            .species = SPECIES_POLIWHIRL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11771
            .iv = TRAINER_PARTY_IVS(7, 7, 7, 7, 7, 7),
#line 11770
            .lvl = 28,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 11773
            .species = SPECIES_CLOYSTER,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11775
            .iv = TRAINER_PARTY_IVS(7, 7, 7, 7, 7, 7),
#line 11774
            .lvl = 28,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 11777
            .species = SPECIES_SEAKING,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11779
            .iv = TRAINER_PARTY_IVS(7, 7, 7, 7, 7, 7),
#line 11778
            .lvl = 28,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 11781
            .species = SPECIES_SEADRA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11783
            .iv = TRAINER_PARTY_IVS(7, 7, 7, 7, 7, 7),
#line 11782
            .lvl = 28,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 11785
    [DIFFICULTY_NORMAL][TRAINER_ROCKER_LUCA_2] =
    {
#line 11786
        .trainerName = _("LUCA"),
#line 11787
        .trainerClass = TRAINER_CLASS_ROCKER,
#line 11788
        .trainerPic = TRAINER_PIC_ROCKER,
        .encounterMusic_gender =
#line 11790
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 11791
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 11792
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 11794
            .species = SPECIES_ELECTRODE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11796
            .iv = TRAINER_PARTY_IVS(7, 7, 7, 7, 7, 7),
#line 11795
            .lvl = 33,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 11798
            .species = SPECIES_ELECTRODE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11800
            .iv = TRAINER_PARTY_IVS(7, 7, 7, 7, 7, 7),
#line 11799
            .lvl = 33,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 11802
    [DIFFICULTY_NORMAL][TRAINER_BEAUTY_SHEILA_2] =
    {
#line 11803
        .trainerName = _("SHEILA"),
#line 11804
        .trainerClass = TRAINER_CLASS_BEAUTY,
#line 11805
        .trainerPic = TRAINER_PIC_BEAUTY,
        .encounterMusic_gender =
#line 11807
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
#line 11808
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 11809
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 11811
            .species = SPECIES_CLEFAIRY,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11813
            .iv = TRAINER_PARTY_IVS(9, 9, 9, 9, 9, 9),
#line 11812
            .lvl = 49,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 11815
            .species = SPECIES_PERSIAN,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11817
            .iv = TRAINER_PARTY_IVS(9, 9, 9, 9, 9, 9),
#line 11816
            .lvl = 49,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 11819
    [DIFFICULTY_NORMAL][TRAINER_BIRD_KEEPER_ROBERT_2] =
    {
#line 11820
        .trainerName = _("ROBERT"),
#line 11821
        .trainerClass = TRAINER_CLASS_BIRD_KEEPER,
#line 11822
        .trainerPic = TRAINER_PIC_BIRD_KEEPER,
        .encounterMusic_gender =
#line 11824
            TRAINER_ENCOUNTER_MUSIC_COOL,
#line 11825
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 11826
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 4,
        .party = (const struct TrainerMon[])
        {
            {
#line 11828
            .species = SPECIES_PIDGEOTTO,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11830
            .iv = TRAINER_PARTY_IVS(7, 7, 7, 7, 7, 7),
#line 11829
            .lvl = 28,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 11832
            .species = SPECIES_PIDGEOTTO,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11834
            .iv = TRAINER_PARTY_IVS(7, 7, 7, 7, 7, 7),
#line 11833
            .lvl = 28,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 11836
            .species = SPECIES_FEAROW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11838
            .iv = TRAINER_PARTY_IVS(7, 7, 7, 7, 7, 7),
#line 11837
            .lvl = 28,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 11840
            .species = SPECIES_FEAROW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11842
            .iv = TRAINER_PARTY_IVS(7, 7, 7, 7, 7, 7),
#line 11841
            .lvl = 28,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 11844
    [DIFFICULTY_NORMAL][TRAINER_BIRD_KEEPER_ROBERT_3] =
    {
#line 11845
        .trainerName = _("ROBERT"),
#line 11846
        .trainerClass = TRAINER_CLASS_BIRD_KEEPER,
#line 11847
        .trainerPic = TRAINER_PIC_BIRD_KEEPER,
        .encounterMusic_gender =
#line 11849
            TRAINER_ENCOUNTER_MUSIC_COOL,
#line 11850
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 11851
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 4,
        .party = (const struct TrainerMon[])
        {
            {
#line 11853
            .species = SPECIES_PIDGEOT,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11855
            .iv = TRAINER_PARTY_IVS(9, 9, 9, 9, 9, 9),
#line 11854
            .lvl = 47,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 11857
            .species = SPECIES_PIDGEOT,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11859
            .iv = TRAINER_PARTY_IVS(9, 9, 9, 9, 9, 9),
#line 11858
            .lvl = 47,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 11861
            .species = SPECIES_FEAROW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11863
            .iv = TRAINER_PARTY_IVS(9, 9, 9, 9, 9, 9),
#line 11862
            .lvl = 47,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 11865
            .species = SPECIES_FEAROW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11867
            .iv = TRAINER_PARTY_IVS(9, 9, 9, 9, 9, 9),
#line 11866
            .lvl = 47,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 11869
    [DIFFICULTY_NORMAL][TRAINER_PICNICKER_SUSIE_2] =
    {
#line 11870
        .trainerName = _("SUSIE"),
#line 11871
        .trainerClass = TRAINER_CLASS_PICNICKER,
#line 11872
        .trainerPic = TRAINER_PIC_PICNICKER,
        .encounterMusic_gender =
#line 11874
            TRAINER_ENCOUNTER_MUSIC_GIRL,
#line 11875
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 11876
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 5,
        .party = (const struct TrainerMon[])
        {
            {
#line 11878
            .species = SPECIES_PIDGEOTTO,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11880
            .iv = TRAINER_PARTY_IVS(7, 7, 7, 7, 7, 7),
#line 11879
            .lvl = 27,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 11882
            .species = SPECIES_MEOWTH,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11884
            .iv = TRAINER_PARTY_IVS(7, 7, 7, 7, 7, 7),
#line 11883
            .lvl = 27,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 11886
            .species = SPECIES_RATICATE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11888
            .iv = TRAINER_PARTY_IVS(7, 7, 7, 7, 7, 7),
#line 11887
            .lvl = 27,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 11890
            .species = SPECIES_PIKACHU,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11892
            .iv = TRAINER_PARTY_IVS(7, 7, 7, 7, 7, 7),
#line 11891
            .lvl = 27,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 11894
            .species = SPECIES_MEOWTH,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11896
            .iv = TRAINER_PARTY_IVS(7, 7, 7, 7, 7, 7),
#line 11895
            .lvl = 27,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 11898
    [DIFFICULTY_NORMAL][TRAINER_PICNICKER_SUSIE_3] =
    {
#line 11899
        .trainerName = _("SUSIE"),
#line 11900
        .trainerClass = TRAINER_CLASS_PICNICKER,
#line 11901
        .trainerPic = TRAINER_PIC_PICNICKER,
        .encounterMusic_gender =
#line 11903
            TRAINER_ENCOUNTER_MUSIC_GIRL,
#line 11904
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 11905
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 5,
        .party = (const struct TrainerMon[])
        {
            {
#line 11907
            .species = SPECIES_PIDGEOTTO,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11909
            .iv = TRAINER_PARTY_IVS(9, 9, 9, 9, 9, 9),
#line 11908
            .lvl = 47,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 11911
            .species = SPECIES_PERSIAN,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11913
            .iv = TRAINER_PARTY_IVS(9, 9, 9, 9, 9, 9),
#line 11912
            .lvl = 47,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 11915
            .species = SPECIES_RATICATE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11917
            .iv = TRAINER_PARTY_IVS(9, 9, 9, 9, 9, 9),
#line 11916
            .lvl = 47,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 11919
            .species = SPECIES_PIKACHU,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11921
            .iv = TRAINER_PARTY_IVS(9, 9, 9, 9, 9, 9),
#line 11920
            .lvl = 47,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 11923
            .species = SPECIES_PERSIAN,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11925
            .iv = TRAINER_PARTY_IVS(9, 9, 9, 9, 9, 9),
#line 11924
            .lvl = 47,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 11927
    [DIFFICULTY_NORMAL][TRAINER_PICNICKER_SUSIE_4] =
    {
#line 11928
        .trainerName = _("SUSIE"),
#line 11929
        .trainerClass = TRAINER_CLASS_PICNICKER,
#line 11930
        .trainerPic = TRAINER_PIC_PICNICKER,
        .encounterMusic_gender =
#line 11932
            TRAINER_ENCOUNTER_MUSIC_GIRL,
#line 11933
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 11934
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 5,
        .party = (const struct TrainerMon[])
        {
            {
#line 11936
            .species = SPECIES_PIDGEOT,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11938
            .iv = TRAINER_PARTY_IVS(14, 14, 14, 14, 14, 14),
#line 11937
            .lvl = 52,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 11940
            .species = SPECIES_PERSIAN,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11942
            .iv = TRAINER_PARTY_IVS(14, 14, 14, 14, 14, 14),
#line 11941
            .lvl = 52,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 11944
            .species = SPECIES_RATICATE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11946
            .iv = TRAINER_PARTY_IVS(14, 14, 14, 14, 14, 14),
#line 11945
            .lvl = 52,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 11948
            .species = SPECIES_RAICHU,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11950
            .iv = TRAINER_PARTY_IVS(14, 14, 14, 14, 14, 14),
#line 11949
            .lvl = 52,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 11952
            .species = SPECIES_PERSIAN,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11954
            .iv = TRAINER_PARTY_IVS(14, 14, 14, 14, 14, 14),
#line 11953
            .lvl = 52,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 11956
    [DIFFICULTY_NORMAL][TRAINER_BIKER_LUKAS_2] =
    {
#line 11957
        .trainerName = _("LUKAS"),
#line 11958
        .trainerClass = TRAINER_CLASS_BIKER,
#line 11959
        .trainerPic = TRAINER_PIC_BIKER,
        .encounterMusic_gender =
#line 11961
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 11962
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 11963
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 4,
        .party = (const struct TrainerMon[])
        {
            {
#line 11965
            .species = SPECIES_KOFFING,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11967
            .iv = TRAINER_PARTY_IVS(9, 9, 9, 9, 9, 9),
#line 11966
            .lvl = 47,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 11969
            .species = SPECIES_KOFFING,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11971
            .iv = TRAINER_PARTY_IVS(9, 9, 9, 9, 9, 9),
#line 11970
            .lvl = 47,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 11973
            .species = SPECIES_MUK,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11975
            .iv = TRAINER_PARTY_IVS(9, 9, 9, 9, 9, 9),
#line 11974
            .lvl = 47,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 11977
            .species = SPECIES_WEEZING,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11979
            .iv = TRAINER_PARTY_IVS(9, 9, 9, 9, 9, 9),
#line 11978
            .lvl = 47,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 11981
    [DIFFICULTY_NORMAL][TRAINER_BIRD_KEEPER_BENNY_2] =
    {
#line 11982
        .trainerName = _("BENNY"),
#line 11983
        .trainerClass = TRAINER_CLASS_BIRD_KEEPER,
#line 11984
        .trainerPic = TRAINER_PIC_BIRD_KEEPER,
        .encounterMusic_gender =
#line 11986
            TRAINER_ENCOUNTER_MUSIC_COOL,
#line 11987
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 11988
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 11990
            .species = SPECIES_FEAROW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11992
            .iv = TRAINER_PARTY_IVS(7, 7, 7, 7, 7, 7),
#line 11991
            .lvl = 32,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 11994
            .species = SPECIES_FEAROW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11996
            .iv = TRAINER_PARTY_IVS(7, 7, 7, 7, 7, 7),
#line 11995
            .lvl = 32,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 11998
    [DIFFICULTY_NORMAL][TRAINER_BIRD_KEEPER_BENNY_3] =
    {
#line 11999
        .trainerName = _("BENNY"),
#line 12000
        .trainerClass = TRAINER_CLASS_BIRD_KEEPER,
#line 12001
        .trainerPic = TRAINER_PIC_BIRD_KEEPER,
        .encounterMusic_gender =
#line 12003
            TRAINER_ENCOUNTER_MUSIC_COOL,
#line 12004
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 12005
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 12007
            .species = SPECIES_FEAROW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12009
            .iv = TRAINER_PARTY_IVS(9, 9, 9, 9, 9, 9),
#line 12008
            .lvl = 49,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 12011
            .species = SPECIES_FEAROW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12013
            .iv = TRAINER_PARTY_IVS(9, 9, 9, 9, 9, 9),
#line 12012
            .lvl = 49,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 12015
    [DIFFICULTY_NORMAL][TRAINER_BIRD_KEEPER_MARLON_2] =
    {
#line 12016
        .trainerName = _("MARLON"),
#line 12017
        .trainerClass = TRAINER_CLASS_BIRD_KEEPER,
#line 12018
        .trainerPic = TRAINER_PIC_BIRD_KEEPER,
        .encounterMusic_gender =
#line 12020
            TRAINER_ENCOUNTER_MUSIC_COOL,
#line 12021
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 12022
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 12024
            .species = SPECIES_FEAROW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12026
            .iv = TRAINER_PARTY_IVS(7, 7, 7, 7, 7, 7),
#line 12025
            .lvl = 30,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 12028
            .species = SPECIES_DODUO,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12030
            .iv = TRAINER_PARTY_IVS(7, 7, 7, 7, 7, 7),
#line 12029
            .lvl = 30,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 12032
            .species = SPECIES_FEAROW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12034
            .iv = TRAINER_PARTY_IVS(7, 7, 7, 7, 7, 7),
#line 12033
            .lvl = 30,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 12036
    [DIFFICULTY_NORMAL][TRAINER_BIRD_KEEPER_MARLON_3] =
    {
#line 12037
        .trainerName = _("MARLON"),
#line 12038
        .trainerClass = TRAINER_CLASS_BIRD_KEEPER,
#line 12039
        .trainerPic = TRAINER_PIC_BIRD_KEEPER,
        .encounterMusic_gender =
#line 12041
            TRAINER_ENCOUNTER_MUSIC_COOL,
#line 12042
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 12043
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 12045
            .species = SPECIES_FEAROW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12047
            .iv = TRAINER_PARTY_IVS(9, 9, 9, 9, 9, 9),
#line 12046
            .lvl = 48,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 12049
            .species = SPECIES_DODRIO,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12051
            .iv = TRAINER_PARTY_IVS(9, 9, 9, 9, 9, 9),
#line 12050
            .lvl = 48,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 12053
            .species = SPECIES_FEAROW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12055
            .iv = TRAINER_PARTY_IVS(9, 9, 9, 9, 9, 9),
#line 12054
            .lvl = 48,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 12057
    [DIFFICULTY_NORMAL][TRAINER_BEAUTY_GRACE_2] =
    {
#line 12058
        .trainerName = _("GRACE"),
#line 12059
        .trainerClass = TRAINER_CLASS_BEAUTY,
#line 12060
        .trainerPic = TRAINER_PIC_BEAUTY,
        .encounterMusic_gender =
#line 12062
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
#line 12063
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 12064
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 12066
            .species = SPECIES_PIDGEOT,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12068
            .iv = TRAINER_PARTY_IVS(9, 9, 9, 9, 9, 9),
#line 12067
            .lvl = 49,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 12070
            .species = SPECIES_WIGGLYTUFF,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12072
            .iv = TRAINER_PARTY_IVS(9, 9, 9, 9, 9, 9),
#line 12071
            .lvl = 49,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 12074
    [DIFFICULTY_NORMAL][TRAINER_BIRD_KEEPER_CHESTER_2] =
    {
#line 12075
        .trainerName = _("CHESTER"),
#line 12076
        .trainerClass = TRAINER_CLASS_BIRD_KEEPER,
#line 12077
        .trainerPic = TRAINER_PIC_BIRD_KEEPER,
        .encounterMusic_gender =
#line 12079
            TRAINER_ENCOUNTER_MUSIC_COOL,
#line 12080
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 12081
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 12083
            .species = SPECIES_DODRIO,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12085
            .iv = TRAINER_PARTY_IVS(7, 7, 7, 7, 7, 7),
#line 12084
            .lvl = 30,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 12087
            .species = SPECIES_DODRIO,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12089
            .iv = TRAINER_PARTY_IVS(7, 7, 7, 7, 7, 7),
#line 12088
            .lvl = 30,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 12091
            .species = SPECIES_DODUO,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12093
            .iv = TRAINER_PARTY_IVS(7, 7, 7, 7, 7, 7),
#line 12092
            .lvl = 30,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 12095
    [DIFFICULTY_NORMAL][TRAINER_BIRD_KEEPER_CHESTER_3] =
    {
#line 12096
        .trainerName = _("CHESTER"),
#line 12097
        .trainerClass = TRAINER_CLASS_BIRD_KEEPER,
#line 12098
        .trainerPic = TRAINER_PIC_BIRD_KEEPER,
        .encounterMusic_gender =
#line 12100
            TRAINER_ENCOUNTER_MUSIC_COOL,
#line 12101
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 12102
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 12104
            .species = SPECIES_DODRIO,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12106
            .iv = TRAINER_PARTY_IVS(9, 9, 9, 9, 9, 9),
#line 12105
            .lvl = 48,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 12108
            .species = SPECIES_DODRIO,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12110
            .iv = TRAINER_PARTY_IVS(9, 9, 9, 9, 9, 9),
#line 12109
            .lvl = 48,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 12112
            .species = SPECIES_DODRIO,
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
    [DIFFICULTY_NORMAL][TRAINER_PICNICKER_BECKY_2] =
    {
#line 12117
        .trainerName = _("BECKY"),
#line 12118
        .trainerClass = TRAINER_CLASS_PICNICKER,
#line 12119
        .trainerPic = TRAINER_PIC_PICNICKER,
        .encounterMusic_gender =
#line 12121
            TRAINER_ENCOUNTER_MUSIC_GIRL,
#line 12122
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 12123
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 12125
            .species = SPECIES_PIKACHU,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12127
            .iv = TRAINER_PARTY_IVS(7, 7, 7, 7, 7, 7),
#line 12126
            .lvl = 32,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 12129
            .species = SPECIES_RAICHU,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12131
            .iv = TRAINER_PARTY_IVS(7, 7, 7, 7, 7, 7),
#line 12130
            .lvl = 32,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 12133
    [DIFFICULTY_NORMAL][TRAINER_PICNICKER_BECKY_3] =
    {
#line 12134
        .trainerName = _("BECKY"),
#line 12135
        .trainerClass = TRAINER_CLASS_PICNICKER,
#line 12136
        .trainerPic = TRAINER_PIC_PICNICKER,
        .encounterMusic_gender =
#line 12138
            TRAINER_ENCOUNTER_MUSIC_GIRL,
#line 12139
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 12140
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 12142
            .species = SPECIES_PIKACHU,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12144
            .iv = TRAINER_PARTY_IVS(9, 9, 9, 9, 9, 9),
#line 12143
            .lvl = 49,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 12146
            .species = SPECIES_RAICHU,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12148
            .iv = TRAINER_PARTY_IVS(9, 9, 9, 9, 9, 9),
#line 12147
            .lvl = 49,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 12150
    [DIFFICULTY_NORMAL][TRAINER_PICNICKER_BECKY_4] =
    {
#line 12151
        .trainerName = _("BECKY"),
#line 12152
        .trainerClass = TRAINER_CLASS_PICNICKER,
#line 12153
        .trainerPic = TRAINER_PIC_PICNICKER,
        .encounterMusic_gender =
#line 12155
            TRAINER_ENCOUNTER_MUSIC_GIRL,
#line 12156
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 12157
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 12159
            .species = SPECIES_RAICHU,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12161
            .iv = TRAINER_PARTY_IVS(14, 14, 14, 14, 14, 14),
#line 12160
            .lvl = 54,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 12163
            .species = SPECIES_RAICHU,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12165
            .iv = TRAINER_PARTY_IVS(14, 14, 14, 14, 14, 14),
#line 12164
            .lvl = 54,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 12167
    [DIFFICULTY_NORMAL][TRAINER_CRUSH_KIN_RON_MYA_2] =
    {
#line 12168
        .trainerName = _("RON & MYA"),
#line 12169
        .trainerClass = TRAINER_CLASS_CRUSH_KIN,
#line 12170
        .trainerPic = TRAINER_PIC_CRUSH_KIN,
        .encounterMusic_gender =
#line 12172
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
#line 12173
        .battleType = TRAINER_BATTLE_TYPE_DOUBLES,
#line 12174
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 12176
            .species = SPECIES_HITMONCHAN,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12176
            .heldItem = ITEM_BLACK_BELT,
#line 12178
            .iv = TRAINER_PARTY_IVS(13, 13, 13, 13, 13, 13),
#line 12177
            .lvl = 33,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 12180
            .species = SPECIES_HITMONLEE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12180
            .heldItem = ITEM_BLACK_BELT,
#line 12182
            .iv = TRAINER_PARTY_IVS(13, 13, 13, 13, 13, 13),
#line 12181
            .lvl = 33,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 12184
    [DIFFICULTY_NORMAL][TRAINER_CRUSH_KIN_RON_MYA_3] =
    {
#line 12185
        .trainerName = _("RON & MYA"),
#line 12186
        .trainerClass = TRAINER_CLASS_CRUSH_KIN,
#line 12187
        .trainerPic = TRAINER_PIC_CRUSH_KIN,
        .encounterMusic_gender =
#line 12189
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
#line 12190
        .battleType = TRAINER_BATTLE_TYPE_DOUBLES,
#line 12191
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 12193
            .species = SPECIES_HITMONCHAN,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12193
            .heldItem = ITEM_BLACK_BELT,
#line 12195
            .iv = TRAINER_PARTY_IVS(15, 15, 15, 15, 15, 15),
#line 12194
            .lvl = 51,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 12197
            .species = SPECIES_HITMONLEE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12197
            .heldItem = ITEM_BLACK_BELT,
#line 12199
            .iv = TRAINER_PARTY_IVS(15, 15, 15, 15, 15, 15),
#line 12198
            .lvl = 51,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 12201
    [DIFFICULTY_NORMAL][TRAINER_CRUSH_KIN_RON_MYA_4] =
    {
#line 12202
        .trainerName = _("RON & MYA"),
#line 12203
        .trainerClass = TRAINER_CLASS_CRUSH_KIN,
#line 12204
        .trainerPic = TRAINER_PIC_CRUSH_KIN,
        .encounterMusic_gender =
#line 12206
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
#line 12207
        .battleType = TRAINER_BATTLE_TYPE_DOUBLES,
#line 12208
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 12210
            .species = SPECIES_HITMONCHAN,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12210
            .heldItem = ITEM_BLACK_BELT,
#line 12212
            .iv = TRAINER_PARTY_IVS(20, 20, 20, 20, 20, 20),
#line 12211
            .lvl = 56,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 12214
            .species = SPECIES_HITMONLEE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12214
            .heldItem = ITEM_BLACK_BELT,
#line 12216
            .iv = TRAINER_PARTY_IVS(20, 20, 20, 20, 20, 20),
#line 12215
            .lvl = 56,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 12218
    [DIFFICULTY_NORMAL][TRAINER_BIKER_RUBEN_2] =
    {
#line 12219
        .trainerName = _("RUBEN"),
#line 12220
        .trainerClass = TRAINER_CLASS_BIKER,
#line 12221
        .trainerPic = TRAINER_PIC_BIKER,
        .encounterMusic_gender =
#line 12223
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 12224
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 12225
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 12227
            .species = SPECIES_WEEZING,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12229
            .iv = TRAINER_PARTY_IVS(9, 9, 9, 9, 9, 9),
#line 12228
            .lvl = 48,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 12231
            .species = SPECIES_WEEZING,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12233
            .iv = TRAINER_PARTY_IVS(9, 9, 9, 9, 9, 9),
#line 12232
            .lvl = 48,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 12235
            .species = SPECIES_WEEZING,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12237
            .iv = TRAINER_PARTY_IVS(9, 9, 9, 9, 9, 9),
#line 12236
            .lvl = 48,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 12239
    [DIFFICULTY_NORMAL][TRAINER_CUE_BALL_CAMRON_2] =
    {
#line 12240
        .trainerName = _("CAMRON"),
#line 12241
        .trainerClass = TRAINER_CLASS_CUE_BALL,
#line 12242
        .trainerPic = TRAINER_PIC_CUE_BALL,
        .encounterMusic_gender =
#line 12244
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 12245
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 12246
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 12248
            .species = SPECIES_PRIMEAPE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12250
            .iv = TRAINER_PARTY_IVS(9, 9, 9, 9, 9, 9),
#line 12249
            .lvl = 49,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 12252
            .species = SPECIES_MACHOKE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12254
            .iv = TRAINER_PARTY_IVS(9, 9, 9, 9, 9, 9),
#line 12253
            .lvl = 49,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 12256
    [DIFFICULTY_NORMAL][TRAINER_BIKER_JAXON_2] =
    {
#line 12257
        .trainerName = _("JAXON"),
#line 12258
        .trainerClass = TRAINER_CLASS_BIKER,
#line 12259
        .trainerPic = TRAINER_PIC_BIKER,
        .encounterMusic_gender =
#line 12261
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 12262
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 12263
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 12265
            .species = SPECIES_WEEZING,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12267
            .iv = TRAINER_PARTY_IVS(9, 9, 9, 9, 9, 9),
#line 12266
            .lvl = 49,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 12269
            .species = SPECIES_MUK,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12271
            .iv = TRAINER_PARTY_IVS(9, 9, 9, 9, 9, 9),
#line 12270
            .lvl = 49,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 12273
    [DIFFICULTY_NORMAL][TRAINER_CUE_BALL_ISAIAH_2] =
    {
#line 12274
        .trainerName = _("ISAIAH"),
#line 12275
        .trainerClass = TRAINER_CLASS_CUE_BALL,
#line 12276
        .trainerPic = TRAINER_PIC_CUE_BALL,
        .encounterMusic_gender =
#line 12278
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 12279
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 12280
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 12282
            .species = SPECIES_MACHOKE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12284
            .iv = TRAINER_PARTY_IVS(9, 9, 9, 9, 9, 9),
#line 12283
            .lvl = 49,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 12286
            .species = SPECIES_MACHAMP,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12288
            .iv = TRAINER_PARTY_IVS(9, 9, 9, 9, 9, 9),
#line 12287
            .lvl = 49,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 12290
    [DIFFICULTY_NORMAL][TRAINER_CUE_BALL_COREY_2] =
    {
#line 12291
        .trainerName = _("COREY"),
#line 12292
        .trainerClass = TRAINER_CLASS_CUE_BALL,
#line 12293
        .trainerPic = TRAINER_PIC_CUE_BALL,
        .encounterMusic_gender =
#line 12295
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 12296
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 12297
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 12299
            .species = SPECIES_PRIMEAPE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12301
            .iv = TRAINER_PARTY_IVS(9, 9, 9, 9, 9, 9),
#line 12300
            .lvl = 49,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 12303
            .species = SPECIES_MACHAMP,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12305
            .iv = TRAINER_PARTY_IVS(9, 9, 9, 9, 9, 9),
#line 12304
            .lvl = 49,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 12307
    [DIFFICULTY_NORMAL][TRAINER_BIRD_KEEPER_JACOB_2] =
    {
#line 12308
        .trainerName = _("JACOB"),
#line 12309
        .trainerClass = TRAINER_CLASS_BIRD_KEEPER,
#line 12310
        .trainerPic = TRAINER_PIC_BIRD_KEEPER,
        .encounterMusic_gender =
#line 12312
            TRAINER_ENCOUNTER_MUSIC_COOL,
#line 12313
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 12314
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 4,
        .party = (const struct TrainerMon[])
        {
            {
#line 12316
            .species = SPECIES_FEAROW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12318
            .iv = TRAINER_PARTY_IVS(7, 7, 7, 7, 7, 7),
#line 12317
            .lvl = 28,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 12320
            .species = SPECIES_SPEAROW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12322
            .iv = TRAINER_PARTY_IVS(7, 7, 7, 7, 7, 7),
#line 12321
            .lvl = 28,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 12324
            .species = SPECIES_FEAROW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12326
            .iv = TRAINER_PARTY_IVS(7, 7, 7, 7, 7, 7),
#line 12325
            .lvl = 28,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 12328
            .species = SPECIES_SPEAROW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12330
            .iv = TRAINER_PARTY_IVS(7, 7, 7, 7, 7, 7),
#line 12329
            .lvl = 28,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 12332
    [DIFFICULTY_NORMAL][TRAINER_BIRD_KEEPER_JACOB_3] =
    {
#line 12333
        .trainerName = _("JACOB"),
#line 12334
        .trainerClass = TRAINER_CLASS_BIRD_KEEPER,
#line 12335
        .trainerPic = TRAINER_PIC_BIRD_KEEPER,
        .encounterMusic_gender =
#line 12337
            TRAINER_ENCOUNTER_MUSIC_COOL,
#line 12338
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 12339
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 4,
        .party = (const struct TrainerMon[])
        {
            {
#line 12341
            .species = SPECIES_FEAROW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12343
            .iv = TRAINER_PARTY_IVS(9, 9, 9, 9, 9, 9),
#line 12342
            .lvl = 47,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 12345
            .species = SPECIES_FEAROW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12347
            .iv = TRAINER_PARTY_IVS(9, 9, 9, 9, 9, 9),
#line 12346
            .lvl = 47,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 12349
            .species = SPECIES_FEAROW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12351
            .iv = TRAINER_PARTY_IVS(9, 9, 9, 9, 9, 9),
#line 12350
            .lvl = 47,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 12353
            .species = SPECIES_FEAROW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12355
            .iv = TRAINER_PARTY_IVS(9, 9, 9, 9, 9, 9),
#line 12354
            .lvl = 47,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 12357
    [DIFFICULTY_NORMAL][TRAINER_SWIMMER_FEMALE_ALICE_2] =
    {
#line 12358
        .trainerName = _("ALICE"),
#line 12359
        .trainerClass = TRAINER_CLASS_SWIMMER_F,
#line 12360
        .trainerPic = TRAINER_PIC_SWIMMER_F,
        .encounterMusic_gender =
#line 12362
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
#line 12363
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 12364
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 12366
            .species = SPECIES_SEAKING,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12368
            .iv = TRAINER_PARTY_IVS(9, 9, 9, 9, 9, 9),
#line 12367
            .lvl = 49,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 12370
            .species = SPECIES_SEAKING,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12372
            .iv = TRAINER_PARTY_IVS(9, 9, 9, 9, 9, 9),
#line 12371
            .lvl = 49,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 12374
    [DIFFICULTY_NORMAL][TRAINER_SWIMMER_MALE_DARRIN_2] =
    {
#line 12375
        .trainerName = _("DARRIN"),
#line 12376
        .trainerClass = TRAINER_CLASS_SWIMMER_M,
#line 12377
        .trainerPic = TRAINER_PIC_SWIMMER_M,
        .encounterMusic_gender =
#line 12379
            TRAINER_ENCOUNTER_MUSIC_SWIMMER,
#line 12380
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 12381
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 4,
        .party = (const struct TrainerMon[])
        {
            {
#line 12383
            .species = SPECIES_SEADRA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12385
            .iv = TRAINER_PARTY_IVS(14, 14, 14, 14, 14, 14),
#line 12384
            .lvl = 52,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 12387
            .species = SPECIES_SEADRA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12389
            .iv = TRAINER_PARTY_IVS(14, 14, 14, 14, 14, 14),
#line 12388
            .lvl = 52,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 12391
            .species = SPECIES_SEADRA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12393
            .iv = TRAINER_PARTY_IVS(14, 14, 14, 14, 14, 14),
#line 12392
            .lvl = 52,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 12395
            .species = SPECIES_SEADRA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12397
            .iv = TRAINER_PARTY_IVS(14, 14, 14, 14, 14, 14),
#line 12396
            .lvl = 52,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 12399
    [DIFFICULTY_NORMAL][TRAINER_PICNICKER_MISSY_2] =
    {
#line 12400
        .trainerName = _("MISSY"),
#line 12401
        .trainerClass = TRAINER_CLASS_PICNICKER,
#line 12402
        .trainerPic = TRAINER_PIC_PICNICKER,
        .encounterMusic_gender =
#line 12404
            TRAINER_ENCOUNTER_MUSIC_GIRL,
#line 12405
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 12406
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 12408
            .species = SPECIES_SEAKING,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12410
            .iv = TRAINER_PARTY_IVS(9, 9, 9, 9, 9, 9),
#line 12409
            .lvl = 49,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 12412
            .species = SPECIES_SEAKING,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12414
            .iv = TRAINER_PARTY_IVS(9, 9, 9, 9, 9, 9),
#line 12413
            .lvl = 49,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 12416
    [DIFFICULTY_NORMAL][TRAINER_PICNICKER_MISSY_3] =
    {
#line 12417
        .trainerName = _("MISSY"),
#line 12418
        .trainerClass = TRAINER_CLASS_PICNICKER,
#line 12419
        .trainerPic = TRAINER_PIC_PICNICKER,
        .encounterMusic_gender =
#line 12421
            TRAINER_ENCOUNTER_MUSIC_GIRL,
#line 12422
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 12423
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 12425
            .species = SPECIES_SEAKING,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12427
            .iv = TRAINER_PARTY_IVS(14, 14, 14, 14, 14, 14),
#line 12426
            .lvl = 54,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 12429
            .species = SPECIES_SEAKING,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12431
            .iv = TRAINER_PARTY_IVS(14, 14, 14, 14, 14, 14),
#line 12430
            .lvl = 54,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 12433
    [DIFFICULTY_NORMAL][TRAINER_FISHERMAN_WADE_2] =
    {
#line 12434
        .trainerName = _("WADE"),
#line 12435
        .trainerClass = TRAINER_CLASS_FISHERMAN,
#line 12436
        .trainerPic = TRAINER_PIC_FISHERMAN,
        .encounterMusic_gender =
#line 12438
            TRAINER_ENCOUNTER_MUSIC_HIKER,
#line 12439
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 12440
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 6,
        .party = (const struct TrainerMon[])
        {
            {
#line 12442
            .species = SPECIES_MAGIKARP,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12444
            .iv = TRAINER_PARTY_IVS(9, 9, 9, 9, 9, 9),
#line 12443
            .lvl = 47,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 12446
            .species = SPECIES_MAGIKARP,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12448
            .iv = TRAINER_PARTY_IVS(9, 9, 9, 9, 9, 9),
#line 12447
            .lvl = 47,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 12450
            .species = SPECIES_MAGIKARP,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12452
            .iv = TRAINER_PARTY_IVS(9, 9, 9, 9, 9, 9),
#line 12451
            .lvl = 47,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 12454
            .species = SPECIES_MAGIKARP,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12456
            .iv = TRAINER_PARTY_IVS(9, 9, 9, 9, 9, 9),
#line 12455
            .lvl = 47,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 12458
            .species = SPECIES_MAGIKARP,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12460
            .iv = TRAINER_PARTY_IVS(9, 9, 9, 9, 9, 9),
#line 12459
            .lvl = 47,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 12462
            .species = SPECIES_MAGIKARP,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12464
            .iv = TRAINER_PARTY_IVS(9, 9, 9, 9, 9, 9),
#line 12463
            .lvl = 47,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 12466
    [DIFFICULTY_NORMAL][TRAINER_SWIMMER_MALE_JACK_2] =
    {
#line 12467
        .trainerName = _("JACK"),
#line 12468
        .trainerClass = TRAINER_CLASS_SWIMMER_M,
#line 12469
        .trainerPic = TRAINER_PIC_SWIMMER_M,
        .encounterMusic_gender =
#line 12471
            TRAINER_ENCOUNTER_MUSIC_SWIMMER,
#line 12472
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 12473
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 12475
            .species = SPECIES_STARMIE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12477
            .iv = TRAINER_PARTY_IVS(9, 9, 9, 9, 9, 9),
#line 12476
            .lvl = 50,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 12479
    [DIFFICULTY_NORMAL][TRAINER_SIS_AND_BRO_LIL_IAN_2] =
    {
#line 12480
        .trainerName = _("LIL & IAN"),
#line 12481
        .trainerClass = TRAINER_CLASS_SIS_AND_BRO,
#line 12482
        .trainerPic = TRAINER_PIC_SIS_AND_BRO,
        .encounterMusic_gender =
#line 12484
            TRAINER_ENCOUNTER_MUSIC_SWIMMER,
#line 12485
        .battleType = TRAINER_BATTLE_TYPE_DOUBLES,
#line 12486
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 12488
            .species = SPECIES_SEADRA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12490
            .iv = TRAINER_PARTY_IVS(9, 9, 9, 9, 9, 9),
#line 12489
            .lvl = 50,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 12492
            .species = SPECIES_STARMIE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12494
            .iv = TRAINER_PARTY_IVS(9, 9, 9, 9, 9, 9),
#line 12493
            .lvl = 50,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 12496
    [DIFFICULTY_NORMAL][TRAINER_SIS_AND_BRO_LIL_IAN_3] =
    {
#line 12497
        .trainerName = _("LIL & IAN"),
#line 12498
        .trainerClass = TRAINER_CLASS_SIS_AND_BRO,
#line 12499
        .trainerPic = TRAINER_PIC_SIS_AND_BRO,
        .encounterMusic_gender =
#line 12501
            TRAINER_ENCOUNTER_MUSIC_SWIMMER,
#line 12502
        .battleType = TRAINER_BATTLE_TYPE_DOUBLES,
#line 12503
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 12505
            .species = SPECIES_SEADRA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12507
            .iv = TRAINER_PARTY_IVS(14, 14, 14, 14, 14, 14),
#line 12506
            .lvl = 55,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 12509
            .species = SPECIES_STARMIE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12511
            .iv = TRAINER_PARTY_IVS(14, 14, 14, 14, 14, 14),
#line 12510
            .lvl = 55,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 12513
    [DIFFICULTY_NORMAL][TRAINER_SWIMMER_MALE_FINN_2] =
    {
#line 12514
        .trainerName = _("FINN"),
#line 12515
        .trainerClass = TRAINER_CLASS_SWIMMER_M,
#line 12516
        .trainerPic = TRAINER_PIC_SWIMMER_M,
        .encounterMusic_gender =
#line 12518
            TRAINER_ENCOUNTER_MUSIC_SWIMMER,
#line 12519
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 12520
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 12522
            .species = SPECIES_STARMIE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12524
            .iv = TRAINER_PARTY_IVS(9, 9, 9, 9, 9, 9),
#line 12523
            .lvl = 50,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 12526
    [DIFFICULTY_NORMAL][TRAINER_CRUSH_GIRL_SHARON_2] =
    {
#line 12527
        .trainerName = _("SHARON"),
#line 12528
        .trainerClass = TRAINER_CLASS_CRUSH_GIRL,
#line 12529
        .trainerPic = TRAINER_PIC_CRUSH_GIRL,
        .encounterMusic_gender =
#line 12531
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
#line 12532
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 12533
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 12535
            .species = SPECIES_MANKEY,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12535
            .heldItem = ITEM_BLACK_BELT,
#line 12537
            .iv = TRAINER_PARTY_IVS(15, 15, 15, 15, 15, 15),
#line 12536
            .lvl = 50,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 12539
            .species = SPECIES_PRIMEAPE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12539
            .heldItem = ITEM_BLACK_BELT,
#line 12541
            .iv = TRAINER_PARTY_IVS(15, 15, 15, 15, 15, 15),
#line 12540
            .lvl = 50,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 12543
    [DIFFICULTY_NORMAL][TRAINER_CRUSH_GIRL_SHARON_3] =
    {
#line 12544
        .trainerName = _("SHARON"),
#line 12545
        .trainerClass = TRAINER_CLASS_CRUSH_GIRL,
#line 12546
        .trainerPic = TRAINER_PIC_CRUSH_GIRL,
        .encounterMusic_gender =
#line 12548
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
#line 12549
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 12550
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 12552
            .species = SPECIES_PRIMEAPE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12552
            .heldItem = ITEM_BLACK_BELT,
#line 12554
            .iv = TRAINER_PARTY_IVS(20, 20, 20, 20, 20, 20),
#line 12553
            .lvl = 55,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 12556
            .species = SPECIES_PRIMEAPE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12556
            .heldItem = ITEM_BLACK_BELT,
#line 12558
            .iv = TRAINER_PARTY_IVS(20, 20, 20, 20, 20, 20),
#line 12557
            .lvl = 55,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 12560
    [DIFFICULTY_NORMAL][TRAINER_CRUSH_GIRL_TANYA_2] =
    {
#line 12561
        .trainerName = _("TANYA"),
#line 12562
        .trainerClass = TRAINER_CLASS_CRUSH_GIRL,
#line 12563
        .trainerPic = TRAINER_PIC_CRUSH_GIRL,
        .encounterMusic_gender =
#line 12565
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
#line 12566
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 12567
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 12569
            .species = SPECIES_HITMONLEE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12569
            .heldItem = ITEM_BLACK_BELT,
#line 12571
            .iv = TRAINER_PARTY_IVS(15, 15, 15, 15, 15, 15),
#line 12570
            .lvl = 50,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 12573
            .species = SPECIES_HITMONCHAN,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12573
            .heldItem = ITEM_BLACK_BELT,
#line 12575
            .iv = TRAINER_PARTY_IVS(15, 15, 15, 15, 15, 15),
#line 12574
            .lvl = 50,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 12577
    [DIFFICULTY_NORMAL][TRAINER_CRUSH_GIRL_TANYA_3] =
    {
#line 12578
        .trainerName = _("TANYA"),
#line 12579
        .trainerClass = TRAINER_CLASS_CRUSH_GIRL,
#line 12580
        .trainerPic = TRAINER_PIC_CRUSH_GIRL,
        .encounterMusic_gender =
#line 12582
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
#line 12583
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 12584
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 12586
            .species = SPECIES_HITMONLEE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12586
            .heldItem = ITEM_BLACK_BELT,
#line 12588
            .iv = TRAINER_PARTY_IVS(20, 20, 20, 20, 20, 20),
#line 12587
            .lvl = 55,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 12590
            .species = SPECIES_HITMONCHAN,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12590
            .heldItem = ITEM_BLACK_BELT,
#line 12592
            .iv = TRAINER_PARTY_IVS(20, 20, 20, 20, 20, 20),
#line 12591
            .lvl = 55,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 12594
    [DIFFICULTY_NORMAL][TRAINER_BLACK_BELT_SHEA_2] =
    {
#line 12595
        .trainerName = _("SHEA"),
#line 12596
        .trainerClass = TRAINER_CLASS_BLACK_BELT,
#line 12597
        .trainerPic = TRAINER_PIC_BLACK_BELT,
        .encounterMusic_gender =
#line 12599
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
#line 12600
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 12601
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 12603
            .species = SPECIES_MACHOKE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12603
            .heldItem = ITEM_BLACK_BELT,
#line 12605
            .iv = TRAINER_PARTY_IVS(21, 21, 21, 21, 21, 21),
#line 12604
            .lvl = 50,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 12607
            .species = SPECIES_MACHOKE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12607
            .heldItem = ITEM_BLACK_BELT,
#line 12609
            .iv = TRAINER_PARTY_IVS(21, 21, 21, 21, 21, 21),
#line 12608
            .lvl = 50,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 12611
    [DIFFICULTY_NORMAL][TRAINER_BLACK_BELT_SHEA_3] =
    {
#line 12612
        .trainerName = _("SHEA"),
#line 12613
        .trainerClass = TRAINER_CLASS_BLACK_BELT,
#line 12614
        .trainerPic = TRAINER_PIC_BLACK_BELT,
        .encounterMusic_gender =
#line 12616
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
#line 12617
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 12618
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 12620
            .species = SPECIES_MACHOKE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12620
            .heldItem = ITEM_BLACK_BELT,
#line 12622
            .iv = TRAINER_PARTY_IVS(26, 26, 26, 26, 26, 26),
#line 12621
            .lvl = 55,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 12624
            .species = SPECIES_MACHAMP,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12624
            .heldItem = ITEM_BLACK_BELT,
#line 12626
            .iv = TRAINER_PARTY_IVS(26, 26, 26, 26, 26, 26),
#line 12625
            .lvl = 55,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 12628
    [DIFFICULTY_NORMAL][TRAINER_BLACK_BELT_HUGH_2] =
    {
#line 12629
        .trainerName = _("HUGH"),
#line 12630
        .trainerClass = TRAINER_CLASS_BLACK_BELT,
#line 12631
        .trainerPic = TRAINER_PIC_BLACK_BELT,
        .encounterMusic_gender =
#line 12633
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
#line 12634
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 12635
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 12637
            .species = SPECIES_MACHOKE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12637
            .heldItem = ITEM_BLACK_BELT,
#line 12639
            .iv = TRAINER_PARTY_IVS(21, 21, 21, 21, 21, 21),
#line 12638
            .lvl = 50,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 12641
            .species = SPECIES_MACHOKE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12641
            .heldItem = ITEM_BLACK_BELT,
#line 12643
            .iv = TRAINER_PARTY_IVS(21, 21, 21, 21, 21, 21),
#line 12642
            .lvl = 50,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 12645
    [DIFFICULTY_NORMAL][TRAINER_BLACK_BELT_HUGH_3] =
    {
#line 12646
        .trainerName = _("HUGH"),
#line 12647
        .trainerClass = TRAINER_CLASS_BLACK_BELT,
#line 12648
        .trainerPic = TRAINER_PIC_BLACK_BELT,
        .encounterMusic_gender =
#line 12650
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
#line 12651
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 12652
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 12654
            .species = SPECIES_MACHOKE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12654
            .heldItem = ITEM_BLACK_BELT,
#line 12656
            .iv = TRAINER_PARTY_IVS(26, 26, 26, 26, 26, 26),
#line 12655
            .lvl = 55,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 12658
            .species = SPECIES_MACHAMP,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12658
            .heldItem = ITEM_BLACK_BELT,
#line 12660
            .iv = TRAINER_PARTY_IVS(26, 26, 26, 26, 26, 26),
#line 12659
            .lvl = 55,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 12662
    [DIFFICULTY_NORMAL][TRAINER_CRUSH_KIN_MIK_KIA_2] =
    {
#line 12663
        .trainerName = _("MIK & KIA"),
#line 12664
        .trainerClass = TRAINER_CLASS_CRUSH_KIN,
#line 12665
        .trainerPic = TRAINER_PIC_CRUSH_KIN,
        .encounterMusic_gender =
#line 12667
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
#line 12668
        .battleType = TRAINER_BATTLE_TYPE_DOUBLES,
#line 12669
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 12671
            .species = SPECIES_MACHOKE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12671
            .heldItem = ITEM_BLACK_BELT,
#line 12673
            .iv = TRAINER_PARTY_IVS(15, 15, 15, 15, 15, 15),
#line 12672
            .lvl = 51,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 12675
            .species = SPECIES_PRIMEAPE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12675
            .heldItem = ITEM_BLACK_BELT,
#line 12677
            .iv = TRAINER_PARTY_IVS(15, 15, 15, 15, 15, 15),
#line 12676
            .lvl = 51,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 12679
    [DIFFICULTY_NORMAL][TRAINER_CRUSH_KIN_MIK_KIA_3] =
    {
#line 12680
        .trainerName = _("MIK & KIA"),
#line 12681
        .trainerClass = TRAINER_CLASS_CRUSH_KIN,
#line 12682
        .trainerPic = TRAINER_PIC_CRUSH_KIN,
        .encounterMusic_gender =
#line 12684
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
#line 12685
        .battleType = TRAINER_BATTLE_TYPE_DOUBLES,
#line 12686
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 12688
            .species = SPECIES_MACHAMP,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12688
            .heldItem = ITEM_BLACK_BELT,
#line 12690
            .iv = TRAINER_PARTY_IVS(20, 20, 20, 20, 20, 20),
#line 12689
            .lvl = 56,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 12692
            .species = SPECIES_PRIMEAPE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12692
            .heldItem = ITEM_BLACK_BELT,
#line 12694
            .iv = TRAINER_PARTY_IVS(20, 20, 20, 20, 20, 20),
#line 12693
            .lvl = 56,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 12696
    [DIFFICULTY_NORMAL][TRAINER_TUBER_AMIRA_2] =
    {
#line 12697
        .trainerName = _("AMIRA"),
#line 12698
        .trainerClass = TRAINER_CLASS_TUBER,
#line 12699
        .trainerPic = TRAINER_PIC_TUBER_F,
        .encounterMusic_gender =
#line 12701
            TRAINER_ENCOUNTER_MUSIC_GIRL,
#line 12702
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 12703
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 12705
            .species = SPECIES_POLIWHIRL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12707
            .iv = TRAINER_PARTY_IVS(9, 9, 9, 9, 9, 9),
#line 12706
            .lvl = 47,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 12709
            .species = SPECIES_POLIWHIRL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12711
            .iv = TRAINER_PARTY_IVS(9, 9, 9, 9, 9, 9),
#line 12710
            .lvl = 47,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 12713
            .species = SPECIES_POLIWHIRL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12715
            .iv = TRAINER_PARTY_IVS(9, 9, 9, 9, 9, 9),
#line 12714
            .lvl = 47,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 12717
    [DIFFICULTY_NORMAL][TRAINER_TWINS_JOY_MEG_2] =
    {
#line 12718
        .trainerName = _("JOY & MEG"),
#line 12719
        .trainerClass = TRAINER_CLASS_TWINS,
#line 12720
        .trainerPic = TRAINER_PIC_TWINS,
        .encounterMusic_gender =
#line 12722
            TRAINER_ENCOUNTER_MUSIC_TWINS,
#line 12723
        .battleType = TRAINER_BATTLE_TYPE_DOUBLES,
#line 12724
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 12726
            .species = SPECIES_CLEFAIRY,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12728
            .iv = TRAINER_PARTY_IVS(9, 9, 9, 9, 9, 9),
#line 12727
            .lvl = 49,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 12730
            .species = SPECIES_CLEFAIRY,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12732
            .iv = TRAINER_PARTY_IVS(9, 9, 9, 9, 9, 9),
#line 12731
            .lvl = 49,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 12734
    [DIFFICULTY_NORMAL][TRAINER_PAINTER_RAYNA_2] =
    {
#line 12735
        .trainerName = _("RAYNA"),
#line 12736
        .trainerClass = TRAINER_CLASS_PAINTER,
#line 12737
        .trainerPic = TRAINER_PIC_PAINTER,
        .encounterMusic_gender =
#line 12739
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
#line 12740
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 12741
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 12743
            .species = SPECIES_SMEARGLE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12745
            .iv = TRAINER_PARTY_IVS(14, 14, 14, 14, 14, 14),
#line 12744
            .lvl = 54,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 12746
                MOVE_CROSS_CHOP,
                MOVE_MEGAHORN,
                MOVE_DOUBLE_EDGE,
                MOVE_SELF_DESTRUCT,
            },
            },
        },
    },
#line 12751
    [DIFFICULTY_NORMAL][TRAINER_YOUNGSTER_DESTIN_2] =
    {
#line 12752
        .trainerName = _("DESTIN"),
#line 12753
        .trainerClass = TRAINER_CLASS_YOUNGSTER,
#line 12754
        .trainerPic = TRAINER_PIC_YOUNGSTER,
        .encounterMusic_gender =
#line 12756
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 12757
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 12758
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 12760
            .species = SPECIES_RATICATE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12762
            .iv = TRAINER_PARTY_IVS(14, 14, 14, 14, 14, 14),
#line 12761
            .lvl = 53,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 12764
            .species = SPECIES_PIDGEOT,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12766
            .iv = TRAINER_PARTY_IVS(14, 14, 14, 14, 14, 14),
#line 12765
            .lvl = 53,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 12768
    [DIFFICULTY_NORMAL][TRAINER_PKMN_BREEDER_ALIZE_2] =
    {
#line 12769
        .trainerName = _("ALIZE"),
#line 12770
        .trainerClass = TRAINER_CLASS_PKMN_BREEDER,
#line 12771
        .trainerPic = TRAINER_PIC_POKEMON_BREEDER,
        .encounterMusic_gender =
#line 12773
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
#line 12774
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 12775
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 12777
            .species = SPECIES_PIKACHU,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12779
            .iv = TRAINER_PARTY_IVS(18, 18, 18, 18, 18, 18),
#line 12778
            .lvl = 53,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 12781
            .species = SPECIES_CLEFAIRY,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12783
            .iv = TRAINER_PARTY_IVS(18, 18, 18, 18, 18, 18),
#line 12782
            .lvl = 53,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 12785
            .species = SPECIES_MARILL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12787
            .iv = TRAINER_PARTY_IVS(18, 18, 18, 18, 18, 18),
#line 12786
            .lvl = 53,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 12789
    [DIFFICULTY_NORMAL][TRAINER_YOUNG_COUPLE_GIA_JES_2] =
    {
#line 12790
        .trainerName = _("GIA & JES"),
#line 12791
        .trainerClass = TRAINER_CLASS_YOUNG_COUPLE,
#line 12792
        .trainerPic = TRAINER_PIC_YOUNG_COUPLE,
        .encounterMusic_gender =
#line 12794
            TRAINER_ENCOUNTER_MUSIC_GIRL,
#line 12795
        .battleType = TRAINER_BATTLE_TYPE_DOUBLES,
#line 12796
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 12798
            .species = SPECIES_NIDORINA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12800
            .iv = TRAINER_PARTY_IVS(7, 7, 7, 7, 7, 7),
#line 12799
            .lvl = 30,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 12802
            .species = SPECIES_NIDORINO,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12804
            .iv = TRAINER_PARTY_IVS(7, 7, 7, 7, 7, 7),
#line 12803
            .lvl = 30,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 12806
    [DIFFICULTY_NORMAL][TRAINER_YOUNG_COUPLE_GIA_JES_3] =
    {
#line 12807
        .trainerName = _("GIA & JES"),
#line 12808
        .trainerClass = TRAINER_CLASS_YOUNG_COUPLE,
#line 12809
        .trainerPic = TRAINER_PIC_YOUNG_COUPLE,
        .encounterMusic_gender =
#line 12811
            TRAINER_ENCOUNTER_MUSIC_GIRL,
#line 12812
        .battleType = TRAINER_BATTLE_TYPE_DOUBLES,
#line 12813
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 12815
            .species = SPECIES_NIDOKING,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12817
            .iv = TRAINER_PARTY_IVS(14, 14, 14, 14, 14, 14),
#line 12816
            .lvl = 55,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 12819
            .species = SPECIES_NIDOQUEEN,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12821
            .iv = TRAINER_PARTY_IVS(14, 14, 14, 14, 14, 14),
#line 12820
            .lvl = 55,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 12823
    [DIFFICULTY_NORMAL][TRAINER_BIRD_KEEPER_MILO_2] =
    {
#line 12824
        .trainerName = _("MILO"),
#line 12825
        .trainerClass = TRAINER_CLASS_BIRD_KEEPER,
#line 12826
        .trainerPic = TRAINER_PIC_BIRD_KEEPER,
        .encounterMusic_gender =
#line 12828
            TRAINER_ENCOUNTER_MUSIC_COOL,
#line 12829
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 12830
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 12832
            .species = SPECIES_PIDGEOTTO,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12834
            .iv = TRAINER_PARTY_IVS(14, 14, 14, 14, 14, 14),
#line 12833
            .lvl = 53,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 12836
            .species = SPECIES_PIDGEOT,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12838
            .iv = TRAINER_PARTY_IVS(14, 14, 14, 14, 14, 14),
#line 12837
            .lvl = 55,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 12840
    [DIFFICULTY_NORMAL][TRAINER_BIRD_KEEPER_CHAZ_2] =
    {
#line 12841
        .trainerName = _("CHAZ"),
#line 12842
        .trainerClass = TRAINER_CLASS_BIRD_KEEPER,
#line 12843
        .trainerPic = TRAINER_PIC_BIRD_KEEPER,
        .encounterMusic_gender =
#line 12845
            TRAINER_ENCOUNTER_MUSIC_COOL,
#line 12846
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 12847
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 12849
            .species = SPECIES_FEAROW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12851
            .iv = TRAINER_PARTY_IVS(14, 14, 14, 14, 14, 14),
#line 12850
            .lvl = 53,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 12853
            .species = SPECIES_FEAROW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12855
            .iv = TRAINER_PARTY_IVS(14, 14, 14, 14, 14, 14),
#line 12854
            .lvl = 55,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 12857
    [DIFFICULTY_NORMAL][TRAINER_BIRD_KEEPER_HAROLD_2] =
    {
#line 12858
        .trainerName = _("HAROLD"),
#line 12859
        .trainerClass = TRAINER_CLASS_BIRD_KEEPER,
#line 12860
        .trainerPic = TRAINER_PIC_BIRD_KEEPER,
        .encounterMusic_gender =
#line 12862
            TRAINER_ENCOUNTER_MUSIC_COOL,
#line 12863
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 12864
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 12866
            .species = SPECIES_NOCTOWL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12868
            .iv = TRAINER_PARTY_IVS(14, 14, 14, 14, 14, 14),
#line 12867
            .lvl = 53,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 12870
            .species = SPECIES_NOCTOWL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12872
            .iv = TRAINER_PARTY_IVS(14, 14, 14, 14, 14, 14),
#line 12871
            .lvl = 55,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 12874
    [DIFFICULTY_NORMAL][TRAINER_SWIMMER_FEMALE_NICOLE_2] =
    {
#line 12875
        .trainerName = _("NICOLE"),
#line 12876
        .trainerClass = TRAINER_CLASS_SWIMMER_F,
#line 12877
        .trainerPic = TRAINER_PIC_SWIMMER_F,
        .encounterMusic_gender =
#line 12879
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
#line 12880
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 12881
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 12883
            .species = SPECIES_MARILL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12885
            .iv = TRAINER_PARTY_IVS(14, 14, 14, 14, 14, 14),
#line 12884
            .lvl = 54,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 12887
    [DIFFICULTY_NORMAL][TRAINER_PSYCHIC_JACLYN_2] =
    {
#line 12888
        .trainerName = _("JACLYN"),
#line 12889
        .trainerClass = TRAINER_CLASS_PSYCHIC,
#line 12890
        .trainerPic = TRAINER_PIC_PSYCHIC_F,
        .encounterMusic_gender =
#line 12892
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
#line 12893
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 12894
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 12896
            .species = SPECIES_NATU,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12898
            .iv = TRAINER_PARTY_IVS(26, 26, 26, 26, 26, 26),
#line 12897
            .lvl = 52,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 12899
                MOVE_PSYCHIC,
                MOVE_CONFUSE_RAY,
                MOVE_FUTURE_SIGHT,
                MOVE_WISH,
            },
            },
            {
#line 12904
            .species = SPECIES_SLOWBRO,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12906
            .iv = TRAINER_PARTY_IVS(26, 26, 26, 26, 26, 26),
#line 12905
            .lvl = 52,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 12907
                MOVE_PSYCHIC,
                MOVE_HEADBUTT,
                MOVE_AMNESIA,
                MOVE_YAWN,
            },
            },
            {
#line 12912
            .species = SPECIES_KADABRA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12914
            .iv = TRAINER_PARTY_IVS(26, 26, 26, 26, 26, 26),
#line 12913
            .lvl = 54,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 12915
                MOVE_PSYCHIC,
                MOVE_FUTURE_SIGHT,
                MOVE_RECOVER,
                MOVE_REFLECT,
            },
            },
        },
    },
#line 12920
    [DIFFICULTY_NORMAL][TRAINER_SWIMMER_MALE_SAMIR_2] =
    {
#line 12921
        .trainerName = _("SAMIR"),
#line 12922
        .trainerClass = TRAINER_CLASS_SWIMMER_M,
#line 12923
        .trainerPic = TRAINER_PIC_SWIMMER_M,
        .encounterMusic_gender =
#line 12925
            TRAINER_ENCOUNTER_MUSIC_SWIMMER,
#line 12926
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 12927
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 12929
            .species = SPECIES_GYARADOS,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12931
            .iv = TRAINER_PARTY_IVS(14, 14, 14, 14, 14, 14),
#line 12930
            .lvl = 55,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 12933
    [DIFFICULTY_NORMAL][TRAINER_HIKER_EARL_2] =
    {
#line 12934
        .trainerName = _("EARL"),
#line 12935
        .trainerClass = TRAINER_CLASS_HIKER,
#line 12936
        .trainerPic = TRAINER_PIC_HIKER,
        .encounterMusic_gender =
#line 12938
            TRAINER_ENCOUNTER_MUSIC_HIKER,
#line 12939
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 12940
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 12942
            .species = SPECIES_ONIX,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12944
            .iv = TRAINER_PARTY_IVS(14, 14, 14, 14, 14, 14),
#line 12943
            .lvl = 54,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 12946
            .species = SPECIES_MACHAMP,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12948
            .iv = TRAINER_PARTY_IVS(14, 14, 14, 14, 14, 14),
#line 12947
            .lvl = 54,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 12950
    [DIFFICULTY_NORMAL][TRAINER_RUIN_MANIAC_LARRY_2] =
    {
#line 12951
        .trainerName = _("LARRY"),
#line 12952
        .trainerClass = TRAINER_CLASS_RUIN_MANIAC,
#line 12953
        .trainerPic = TRAINER_PIC_RUIN_MANIAC,
        .encounterMusic_gender =
#line 12955
            TRAINER_ENCOUNTER_MUSIC_HIKER,
#line 12956
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 12957
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 12959
            .species = SPECIES_MACHOKE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12961
            .iv = TRAINER_PARTY_IVS(14, 14, 14, 14, 14, 14),
#line 12960
            .lvl = 54,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 12963
            .species = SPECIES_MACHOKE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12965
            .iv = TRAINER_PARTY_IVS(14, 14, 14, 14, 14, 14),
#line 12964
            .lvl = 54,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 12967
    [DIFFICULTY_NORMAL][TRAINER_POKEMANIAC_HECTOR_2] =
    {
#line 12968
        .trainerName = _("HECTOR"),
#line 12969
        .trainerClass = TRAINER_CLASS_POKEMANIAC,
#line 12970
        .trainerPic = TRAINER_PIC_POKEMANIAC,
        .encounterMusic_gender =
#line 12972
            TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
#line 12973
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 12974
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 12976
            .species = SPECIES_RHYDON,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12978
            .iv = TRAINER_PARTY_IVS(18, 18, 18, 18, 18, 18),
#line 12977
            .lvl = 55,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 12980
            .species = SPECIES_KANGASKHAN,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12982
            .iv = TRAINER_PARTY_IVS(18, 18, 18, 18, 18, 18),
#line 12981
            .lvl = 55,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 12984
    [DIFFICULTY_NORMAL][TRAINER_PSYCHIC_DARIO_2] =
    {
#line 12985
        .trainerName = _("DARIO"),
#line 12986
        .trainerClass = TRAINER_CLASS_PSYCHIC,
#line 12987
        .trainerPic = TRAINER_PIC_PSYCHIC_M,
        .encounterMusic_gender =
#line 12989
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
#line 12990
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 12991
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 12993
            .species = SPECIES_GIRAFARIG,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12995
            .iv = TRAINER_PARTY_IVS(26, 26, 26, 26, 26, 26),
#line 12994
            .lvl = 56,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 12996
                MOVE_CRUNCH,
                MOVE_PSYBEAM,
                MOVE_ODOR_SLEUTH,
                MOVE_AGILITY,
            },
            },
        },
    },
#line 13001
    [DIFFICULTY_NORMAL][TRAINER_PSYCHIC_RODETTE_2] =
    {
#line 13002
        .trainerName = _("RODETTE"),
#line 13003
        .trainerClass = TRAINER_CLASS_PSYCHIC,
#line 13004
        .trainerPic = TRAINER_PIC_PSYCHIC_F,
        .encounterMusic_gender =
#line 13006
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
#line 13007
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 13008
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 13010
            .species = SPECIES_NATU,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13012
            .iv = TRAINER_PARTY_IVS(26, 26, 26, 26, 26, 26),
#line 13011
            .lvl = 53,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 13013
                MOVE_PSYCHIC,
                MOVE_CONFUSE_RAY,
                MOVE_WISH,
                MOVE_FUTURE_SIGHT,
            },
            },
            {
#line 13018
            .species = SPECIES_HYPNO,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13020
            .iv = TRAINER_PARTY_IVS(26, 26, 26, 26, 26, 26),
#line 13019
            .lvl = 53,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 13021
                MOVE_PSYCHIC,
                MOVE_DISABLE,
                MOVE_PSYCH_UP,
                MOVE_FUTURE_SIGHT,
            },
            },
            {
#line 13026
            .species = SPECIES_HYPNO,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13028
            .iv = TRAINER_PARTY_IVS(26, 26, 26, 26, 26, 26),
#line 13027
            .lvl = 53,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 13029
                MOVE_PSYCHIC,
                MOVE_HYPNOSIS,
                MOVE_PSYCH_UP,
                MOVE_FUTURE_SIGHT,
            },
            },
        },
    },
#line 13034
    [DIFFICULTY_NORMAL][TRAINER_JUGGLER_MASON_2] =
    {
#line 13035
        .trainerName = _("MASON"),
#line 13036
        .trainerClass = TRAINER_CLASS_JUGGLER,
#line 13037
        .trainerPic = TRAINER_PIC_JUGGLER,
        .encounterMusic_gender =
#line 13039
            TRAINER_ENCOUNTER_MUSIC_HIKER,
#line 13040
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 13041
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 4,
        .party = (const struct TrainerMon[])
        {
            {
#line 13043
            .species = SPECIES_ELECTRODE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13045
            .iv = TRAINER_PARTY_IVS(14, 14, 14, 14, 14, 14),
#line 13044
            .lvl = 52,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 13047
            .species = SPECIES_PINECO,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13049
            .iv = TRAINER_PARTY_IVS(14, 14, 14, 14, 14, 14),
#line 13048
            .lvl = 52,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 13051
            .species = SPECIES_ELECTRODE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13053
            .iv = TRAINER_PARTY_IVS(14, 14, 14, 14, 14, 14),
#line 13052
            .lvl = 52,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 13055
            .species = SPECIES_PINECO,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13057
            .iv = TRAINER_PARTY_IVS(14, 14, 14, 14, 14, 14),
#line 13056
            .lvl = 52,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 13059
    [DIFFICULTY_NORMAL][TRAINER_PKMN_RANGER_NICOLAS_2] =
    {
#line 13060
        .trainerName = _("NICOLAS"),
#line 13061
        .trainerClass = TRAINER_CLASS_PKMN_RANGER,
#line 13062
        .trainerPic = TRAINER_PIC_POKEMON_RANGER_M,
        .encounterMusic_gender =
#line 13064
            TRAINER_ENCOUNTER_MUSIC_COOL,
#line 13065
        .items = { ITEM_FULL_RESTORE },
#line 13066
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 13067
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 13069
            .species = SPECIES_VICTREEBEL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13071
            .iv = TRAINER_PARTY_IVS(26, 26, 26, 26, 26, 26),
#line 13070
            .lvl = 55,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 13072
                MOVE_RAZOR_LEAF,
                MOVE_ACID,
                MOVE_STUN_SPORE,
                MOVE_WRAP,
            },
            },
            {
#line 13077
            .species = SPECIES_VICTREEBEL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13079
            .iv = TRAINER_PARTY_IVS(26, 26, 26, 26, 26, 26),
#line 13078
            .lvl = 55,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 13080
                MOVE_RAZOR_LEAF,
                MOVE_ACID,
                MOVE_SLEEP_POWDER,
                MOVE_SLAM,
            },
            },
        },
    },
#line 13085
    [DIFFICULTY_NORMAL][TRAINER_PKMN_RANGER_MADELINE_2] =
    {
#line 13086
        .trainerName = _("MADELINE"),
#line 13087
        .trainerClass = TRAINER_CLASS_PKMN_RANGER,
#line 13088
        .trainerPic = TRAINER_PIC_POKEMON_RANGER_F,
        .encounterMusic_gender =
#line 13090
            TRAINER_ENCOUNTER_MUSIC_COOL,
#line 13091
        .items = { ITEM_FULL_RESTORE },
#line 13092
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 13093
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 13095
            .species = SPECIES_VILEPLUME,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13097
            .iv = TRAINER_PARTY_IVS(26, 26, 26, 26, 26, 26),
#line 13096
            .lvl = 55,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 13098
                MOVE_PETAL_DANCE,
                MOVE_MOONLIGHT,
                MOVE_ACID,
                MOVE_SLEEP_POWDER,
            },
            },
            {
#line 13103
            .species = SPECIES_VILEPLUME,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13105
            .iv = TRAINER_PARTY_IVS(26, 26, 26, 26, 26, 26),
#line 13104
            .lvl = 55,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 13106
                MOVE_PETAL_DANCE,
                MOVE_MOONLIGHT,
                MOVE_ACID,
                MOVE_STUN_SPORE,
            },
            },
        },
    },
#line 13111
    [DIFFICULTY_NORMAL][TRAINER_CRUSH_GIRL_CYNDY_2] =
    {
#line 13112
        .trainerName = _("CYNDY"),
#line 13113
        .trainerClass = TRAINER_CLASS_CRUSH_GIRL,
#line 13114
        .trainerPic = TRAINER_PIC_CRUSH_GIRL,
        .encounterMusic_gender =
#line 13116
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
#line 13117
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 13118
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 13120
            .species = SPECIES_PRIMEAPE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13120
            .heldItem = ITEM_BLACK_BELT,
#line 13122
            .iv = TRAINER_PARTY_IVS(20, 20, 20, 20, 20, 20),
#line 13121
            .lvl = 54,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 13124
            .species = SPECIES_HITMONTOP,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13124
            .heldItem = ITEM_BLACK_BELT,
#line 13126
            .iv = TRAINER_PARTY_IVS(20, 20, 20, 20, 20, 20),
#line 13125
            .lvl = 54,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 13128
            .species = SPECIES_MACHAMP,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13128
            .heldItem = ITEM_BLACK_BELT,
#line 13130
            .iv = TRAINER_PARTY_IVS(20, 20, 20, 20, 20, 20),
#line 13129
            .lvl = 54,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 13132
    [DIFFICULTY_NORMAL][TRAINER_TAMER_EVAN_2] =
    {
#line 13133
        .trainerName = _("EVAN"),
#line 13134
        .trainerClass = TRAINER_CLASS_TAMER,
#line 13135
        .trainerPic = TRAINER_PIC_TAMER,
        .encounterMusic_gender =
#line 13137
            TRAINER_ENCOUNTER_MUSIC_HIKER,
#line 13138
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 13139
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 13141
            .species = SPECIES_SANDSLASH,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13143
            .iv = TRAINER_PARTY_IVS(19, 19, 19, 19, 19, 19),
#line 13142
            .lvl = 52,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 13145
            .species = SPECIES_LICKITUNG,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13147
            .iv = TRAINER_PARTY_IVS(19, 19, 19, 19, 19, 19),
#line 13146
            .lvl = 52,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 13149
            .species = SPECIES_URSARING,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13151
            .iv = TRAINER_PARTY_IVS(19, 19, 19, 19, 19, 19),
#line 13150
            .lvl = 55,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 13153
    [DIFFICULTY_NORMAL][TRAINER_PKMN_RANGER_JACKSON_2] =
    {
#line 13154
        .trainerName = _("JACKSON"),
#line 13155
        .trainerClass = TRAINER_CLASS_PKMN_RANGER,
#line 13156
        .trainerPic = TRAINER_PIC_POKEMON_RANGER_M,
        .encounterMusic_gender =
#line 13158
            TRAINER_ENCOUNTER_MUSIC_COOL,
#line 13159
        .items = { ITEM_FULL_RESTORE },
#line 13160
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 13161
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 13163
            .species = SPECIES_TANGELA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13165
            .iv = TRAINER_PARTY_IVS(26, 26, 26, 26, 26, 26),
#line 13164
            .lvl = 53,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 13166
                MOVE_SLAM,
                MOVE_MEGA_DRAIN,
                MOVE_BIND,
                MOVE_INGRAIN,
            },
            },
            {
#line 13171
            .species = SPECIES_EXEGGUTOR,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13173
            .iv = TRAINER_PARTY_IVS(26, 26, 26, 26, 26, 26),
#line 13172
            .lvl = 54,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 13174
                MOVE_CONFUSION,
                MOVE_EGG_BOMB,
                MOVE_STUN_SPORE,
                MOVE_REFLECT,
            },
            },
            {
#line 13179
            .species = SPECIES_EXEGGUTOR,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13181
            .iv = TRAINER_PARTY_IVS(26, 26, 26, 26, 26, 26),
#line 13180
            .lvl = 55,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 13182
                MOVE_CONFUSION,
                MOVE_EGG_BOMB,
                MOVE_SLEEP_POWDER,
                MOVE_STOMP,
            },
            },
        },
    },
#line 13187
    [DIFFICULTY_NORMAL][TRAINER_PKMN_RANGER_KATELYN_2] =
    {
#line 13188
        .trainerName = _("KATELYN"),
#line 13189
        .trainerClass = TRAINER_CLASS_PKMN_RANGER,
#line 13190
        .trainerPic = TRAINER_PIC_POKEMON_RANGER_F,
        .encounterMusic_gender =
#line 13192
            TRAINER_ENCOUNTER_MUSIC_COOL,
#line 13193
        .items = { ITEM_FULL_RESTORE },
#line 13194
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 13195
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 13197
            .species = SPECIES_CHANSEY,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13199
            .iv = TRAINER_PARTY_IVS(26, 26, 26, 26, 26, 26),
#line 13198
            .lvl = 56,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 13200
                MOVE_EGG_BOMB,
                MOVE_DEFENSE_CURL,
                MOVE_MINIMIZE,
                MOVE_SOFT_BOILED,
            },
            },
        },
    },
#line 13205
    [DIFFICULTY_NORMAL][TRAINER_COOLTRAINER_LEROY_2] =
    {
#line 13206
        .trainerName = _("LEROY"),
#line 13207
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
#line 13208
        .trainerPic = TRAINER_PIC_COOLTRAINER_M,
        .encounterMusic_gender =
#line 13210
            TRAINER_ENCOUNTER_MUSIC_COOL,
#line 13211
        .items = { ITEM_FULL_RESTORE },
#line 13212
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 13213
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .partySize = 5,
        .party = (const struct TrainerMon[])
        {
            {
#line 13215
            .species = SPECIES_RHYDON,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13217
            .iv = TRAINER_PARTY_IVS(26, 26, 26, 26, 26, 26),
#line 13216
            .lvl = 52,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 13218
                MOVE_EARTHQUAKE,
                MOVE_HORN_DRILL,
                MOVE_ROCK_BLAST,
                MOVE_SCARY_FACE,
            },
            },
            {
#line 13223
            .species = SPECIES_SLOWBRO,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13225
            .iv = TRAINER_PARTY_IVS(26, 26, 26, 26, 26, 26),
#line 13224
            .lvl = 54,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 13226
                MOVE_PSYCHIC,
                MOVE_HEADBUTT,
                MOVE_AMNESIA,
                MOVE_DISABLE,
            },
            },
            {
#line 13231
            .species = SPECIES_KANGASKHAN,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13233
            .iv = TRAINER_PARTY_IVS(26, 26, 26, 26, 26, 26),
#line 13232
            .lvl = 52,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 13234
                MOVE_DIZZY_PUNCH,
                MOVE_BITE,
                MOVE_ENDURE,
                MOVE_REVERSAL,
            },
            },
            {
#line 13239
            .species = SPECIES_MACHAMP,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13241
            .iv = TRAINER_PARTY_IVS(26, 26, 26, 26, 26, 26),
#line 13240
            .lvl = 52,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 13242
                MOVE_CROSS_CHOP,
                MOVE_VITAL_THROW,
                MOVE_REVENGE,
                MOVE_SEISMIC_TOSS,
            },
            },
            {
#line 13247
            .species = SPECIES_URSARING,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13249
            .iv = TRAINER_PARTY_IVS(26, 26, 26, 26, 26, 26),
#line 13248
            .lvl = 55,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 13250
                MOVE_SLASH,
                MOVE_FAINT_ATTACK,
                MOVE_SNORE,
                MOVE_REST,
            },
            },
        },
    },
#line 13255
    [DIFFICULTY_NORMAL][TRAINER_COOLTRAINER_MICHELLE_2] =
    {
#line 13256
        .trainerName = _("MICHELLE"),
#line 13257
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
#line 13258
        .trainerPic = TRAINER_PIC_COOLTRAINER_F,
        .encounterMusic_gender =
#line 13260
            TRAINER_ENCOUNTER_MUSIC_COOL,
#line 13261
        .items = { ITEM_HYPER_POTION },
#line 13262
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 13263
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .partySize = 5,
        .party = (const struct TrainerMon[])
        {
            {
#line 13265
            .species = SPECIES_PERSIAN,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13267
            .iv = TRAINER_PARTY_IVS(26, 26, 26, 26, 26, 26),
#line 13266
            .lvl = 53,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 13268
                MOVE_SLASH,
                MOVE_SCREECH,
                MOVE_FAINT_ATTACK,
                MOVE_BITE,
            },
            },
            {
#line 13273
            .species = SPECIES_DEWGONG,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13275
            .iv = TRAINER_PARTY_IVS(26, 26, 26, 26, 26, 26),
#line 13274
            .lvl = 53,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 13276
                MOVE_ICE_BEAM,
                MOVE_TAKE_DOWN,
                MOVE_ICY_WIND,
                MOVE_SHEER_COLD,
            },
            },
            {
#line 13281
            .species = SPECIES_NINETALES,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13283
            .iv = TRAINER_PARTY_IVS(26, 26, 26, 26, 26, 26),
#line 13282
            .lvl = 54,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 13284
                MOVE_FLAMETHROWER,
                MOVE_CONFUSE_RAY,
                MOVE_WILL_O_WISP,
                MOVE_GRUDGE,
            },
            },
            {
#line 13289
            .species = SPECIES_RAPIDASH,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13291
            .iv = TRAINER_PARTY_IVS(26, 26, 26, 26, 26, 26),
#line 13290
            .lvl = 54,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 13292
                MOVE_BOUNCE,
                MOVE_AGILITY,
                MOVE_FIRE_SPIN,
                MOVE_TAKE_DOWN,
            },
            },
            {
#line 13297
            .species = SPECIES_GIRAFARIG,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13299
            .iv = TRAINER_PARTY_IVS(26, 26, 26, 26, 26, 26),
#line 13298
            .lvl = 56,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 13300
                MOVE_CRUNCH,
                MOVE_PSYBEAM,
                MOVE_STOMP,
                MOVE_ODOR_SLEUTH,
            },
            },
        },
    },
#line 13305
    [DIFFICULTY_NORMAL][TRAINER_COOL_COUPLE_LEX_NYA_2] =
    {
#line 13306
        .trainerName = _("LEX & NYA"),
#line 13307
        .trainerClass = TRAINER_CLASS_COOL_COUPLE,
#line 13308
        .trainerPic = TRAINER_PIC_COOL_COUPLE,
        .encounterMusic_gender =
#line 13310
            TRAINER_ENCOUNTER_MUSIC_COOL,
#line 13311
        .items = { ITEM_FULL_RESTORE, ITEM_FULL_RESTORE },
#line 13312
        .battleType = TRAINER_BATTLE_TYPE_DOUBLES,
#line 13313
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 13315
            .species = SPECIES_MILTANK,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13317
            .iv = TRAINER_PARTY_IVS(26, 26, 26, 26, 26, 26),
#line 13316
            .lvl = 57,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 13318
                MOVE_BODY_SLAM,
                MOVE_MILK_DRINK,
                MOVE_GROWL,
                MOVE_DEFENSE_CURL,
            },
            },
            {
#line 13323
            .species = SPECIES_TAUROS,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13325
            .iv = TRAINER_PARTY_IVS(26, 26, 26, 26, 26, 26),
#line 13324
            .lvl = 57,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 13326
                MOVE_TAKE_DOWN,
                MOVE_SCARY_FACE,
                MOVE_PURSUIT,
                MOVE_SWAGGER,
            },
            },
        },
    },
#line 13331
    [DIFFICULTY_NORMAL][TRAINER_BUG_CATCHER_COLTON_2] =
    {
#line 13332
        .trainerName = _("COLTON"),
#line 13333
        .trainerClass = TRAINER_CLASS_BUG_CATCHER,
#line 13334
        .trainerPic = TRAINER_PIC_BUG_CATCHER,
        .encounterMusic_gender =
#line 13336
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 13337
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 13338
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 13340
            .species = SPECIES_METAPOD,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13342
            .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
#line 13341
            .lvl = 19,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 13344
            .species = SPECIES_WEEDLE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13346
            .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
#line 13345
            .lvl = 19,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 13348
            .species = SPECIES_METAPOD,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13350
            .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
#line 13349
            .lvl = 19,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 13352
    [DIFFICULTY_NORMAL][TRAINER_BUG_CATCHER_COLTON_3] =
    {
#line 13353
        .trainerName = _("COLTON"),
#line 13354
        .trainerClass = TRAINER_CLASS_BUG_CATCHER,
#line 13355
        .trainerPic = TRAINER_PIC_BUG_CATCHER,
        .encounterMusic_gender =
#line 13357
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 13358
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 13359
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 13361
            .species = SPECIES_BUTTERFREE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13363
            .iv = TRAINER_PARTY_IVS(7, 7, 7, 7, 7, 7),
#line 13362
            .lvl = 27,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 13365
            .species = SPECIES_KAKUNA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13367
            .iv = TRAINER_PARTY_IVS(7, 7, 7, 7, 7, 7),
#line 13366
            .lvl = 27,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 13369
            .species = SPECIES_BUTTERFREE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13371
            .iv = TRAINER_PARTY_IVS(7, 7, 7, 7, 7, 7),
#line 13370
            .lvl = 27,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 13373
    [DIFFICULTY_NORMAL][TRAINER_BUG_CATCHER_COLTON_4] =
    {
#line 13374
        .trainerName = _("COLTON"),
#line 13375
        .trainerClass = TRAINER_CLASS_BUG_CATCHER,
#line 13376
        .trainerPic = TRAINER_PIC_BUG_CATCHER,
        .encounterMusic_gender =
#line 13378
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 13379
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 13380
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 13382
            .species = SPECIES_BUTTERFREE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13384
            .iv = TRAINER_PARTY_IVS(14, 14, 14, 14, 14, 14),
#line 13383
            .lvl = 51,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 13386
            .species = SPECIES_BEEDRILL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13388
            .iv = TRAINER_PARTY_IVS(14, 14, 14, 14, 14, 14),
#line 13387
            .lvl = 54,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 13390
            .species = SPECIES_BUTTERFREE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13392
            .iv = TRAINER_PARTY_IVS(14, 14, 14, 14, 14, 14),
#line 13391
            .lvl = 51,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 13394
    [DIFFICULTY_NORMAL][TRAINER_SWIMMER_MALE_MATTHEW_2] =
    {
#line 13395
        .trainerName = _("MATTHEW"),
#line 13396
        .trainerClass = TRAINER_CLASS_SWIMMER_M,
#line 13397
        .trainerPic = TRAINER_PIC_SWIMMER_M,
        .encounterMusic_gender =
#line 13399
            TRAINER_ENCOUNTER_MUSIC_SWIMMER,
#line 13400
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 13401
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 13403
            .species = SPECIES_POLIWHIRL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13405
            .iv = TRAINER_PARTY_IVS(9, 9, 9, 9, 9, 9),
#line 13404
            .lvl = 49,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 13407
            .species = SPECIES_POLIWRATH,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13409
            .iv = TRAINER_PARTY_IVS(9, 9, 9, 9, 9, 9),
#line 13408
            .lvl = 49,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 13411
    [DIFFICULTY_NORMAL][TRAINER_SWIMMER_MALE_TONY_2] =
    {
#line 13412
        .trainerName = _("TONY"),
#line 13413
        .trainerClass = TRAINER_CLASS_SWIMMER_M,
#line 13414
        .trainerPic = TRAINER_PIC_SWIMMER_M,
        .encounterMusic_gender =
#line 13416
            TRAINER_ENCOUNTER_MUSIC_SWIMMER,
#line 13417
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 13418
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 13420
            .species = SPECIES_SEADRA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13422
            .iv = TRAINER_PARTY_IVS(9, 9, 9, 9, 9, 9),
#line 13421
            .lvl = 49,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 13424
            .species = SPECIES_SEADRA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13426
            .iv = TRAINER_PARTY_IVS(9, 9, 9, 9, 9, 9),
#line 13425
            .lvl = 49,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 13428
    [DIFFICULTY_NORMAL][TRAINER_SWIMMER_FEMALE_MELISSA_2] =
    {
#line 13429
        .trainerName = _("MELISSA"),
#line 13430
        .trainerClass = TRAINER_CLASS_SWIMMER_F,
#line 13431
        .trainerPic = TRAINER_PIC_SWIMMER_F,
        .encounterMusic_gender =
#line 13433
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
#line 13434
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 13435
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 13437
            .species = SPECIES_POLIWHIRL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13439
            .iv = TRAINER_PARTY_IVS(9, 9, 9, 9, 9, 9),
#line 13438
            .lvl = 49,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 13441
            .species = SPECIES_SEAKING,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13443
            .iv = TRAINER_PARTY_IVS(9, 9, 9, 9, 9, 9),
#line 13442
            .lvl = 49,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 13445
    [DIFFICULTY_NORMAL][TRAINER_ELITE_FOUR_LORELEI_2] =
    {
#line 13446
        .trainerName = _("LORELEI"),
#line 13447
        .trainerClass = TRAINER_CLASS_ELITE_FOUR,
#line 13448
        .trainerPic = TRAINER_PIC_ELITE_FOUR_LORELEI,
        .encounterMusic_gender =
#line 13450
            TRAINER_ENCOUNTER_MUSIC_ELITE_FOUR,
#line 13451
        .items = { ITEM_FULL_RESTORE, ITEM_FULL_RESTORE },
#line 13452
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 13453
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
#line 13454
        .mugshotColor = MUGSHOT_COLOR_PURPLE,
        .partySize = 5,
        .party = (const struct TrainerMon[])
        {
            {
#line 13456
            .species = SPECIES_DEWGONG,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13458
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 13457
            .lvl = 64,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 13459
                MOVE_ICE_BEAM,
                MOVE_SURF,
                MOVE_SIGNAL_BEAM,
                MOVE_DOUBLE_TEAM,
            },
            },
            {
#line 13464
            .species = SPECIES_CLOYSTER,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13466
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 13465
            .lvl = 63,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 13467
                MOVE_ICE_BEAM,
                MOVE_SURF,
                MOVE_SUPERSONIC,
                MOVE_RAIN_DANCE,
            },
            },
            {
#line 13472
            .species = SPECIES_PILOSWINE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13474
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 13473
            .lvl = 63,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 13475
                MOVE_BLIZZARD,
                MOVE_EARTHQUAKE,
                MOVE_DOUBLE_EDGE,
                MOVE_ROCK_SLIDE,
            },
            },
            {
#line 13480
            .species = SPECIES_JYNX,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13482
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 13481
            .lvl = 66,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 13483
                MOVE_ICE_BEAM,
                MOVE_PSYCHIC,
                MOVE_LOVELY_KISS,
                MOVE_ATTRACT,
            },
            },
            {
#line 13488
            .species = SPECIES_LAPRAS,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13488
            .heldItem = ITEM_CHERI_BERRY,
#line 13490
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 13489
            .lvl = 66,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 13491
                MOVE_ICE_BEAM,
                MOVE_SURF,
                MOVE_PSYCHIC,
                MOVE_THUNDER,
            },
            },
        },
    },
#line 13496
    [DIFFICULTY_NORMAL][TRAINER_ELITE_FOUR_BRUNO_2] =
    {
#line 13497
        .trainerName = _("BRUNO"),
#line 13498
        .trainerClass = TRAINER_CLASS_ELITE_FOUR,
#line 13499
        .trainerPic = TRAINER_PIC_ELITE_FOUR_BRUNO,
        .encounterMusic_gender =
#line 13501
            TRAINER_ENCOUNTER_MUSIC_ELITE_FOUR,
#line 13502
        .items = { ITEM_FULL_RESTORE, ITEM_FULL_RESTORE },
#line 13503
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 13504
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
#line 13505
        .mugshotColor = MUGSHOT_COLOR_GREEN,
        .partySize = 5,
        .party = (const struct TrainerMon[])
        {
            {
#line 13507
            .species = SPECIES_STEELIX,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13509
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 13508
            .lvl = 65,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 13510
                MOVE_EARTHQUAKE,
                MOVE_IRON_TAIL,
                MOVE_CRUNCH,
                MOVE_ROCK_TOMB,
            },
            },
            {
#line 13515
            .species = SPECIES_HITMONCHAN,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13517
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 13516
            .lvl = 65,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 13518
                MOVE_SKY_UPPERCUT,
                MOVE_MACH_PUNCH,
                MOVE_ROCK_SLIDE,
                MOVE_COUNTER,
            },
            },
            {
#line 13523
            .species = SPECIES_HITMONLEE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13525
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 13524
            .lvl = 65,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 13526
                MOVE_MEGA_KICK,
                MOVE_FORESIGHT,
                MOVE_EARTHQUAKE,
                MOVE_ROCK_SLIDE,
            },
            },
            {
#line 13531
            .species = SPECIES_STEELIX,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13533
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 13532
            .lvl = 66,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 13534
                MOVE_EARTHQUAKE,
                MOVE_IRON_TAIL,
                MOVE_CRUNCH,
                MOVE_DRAGON_BREATH,
            },
            },
            {
#line 13539
            .species = SPECIES_MACHAMP,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13539
            .heldItem = ITEM_PERSIM_BERRY,
#line 13541
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 13540
            .lvl = 68,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 13542
                MOVE_CROSS_CHOP,
                MOVE_EARTHQUAKE,
                MOVE_BRICK_BREAK,
                MOVE_ROCK_SLIDE,
            },
            },
        },
    },
#line 13547
    [DIFFICULTY_NORMAL][TRAINER_ELITE_FOUR_AGATHA_2] =
    {
#line 13548
        .trainerName = _("AGATHA"),
#line 13549
        .trainerClass = TRAINER_CLASS_ELITE_FOUR,
#line 13550
        .trainerPic = TRAINER_PIC_ELITE_FOUR_AGATHA,
        .encounterMusic_gender =
#line 13552
            TRAINER_ENCOUNTER_MUSIC_ELITE_FOUR,
#line 13553
        .items = { ITEM_FULL_RESTORE, ITEM_FULL_RESTORE },
#line 13554
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 13555
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
#line 13556
        .mugshotColor = MUGSHOT_COLOR_PINK,
        .partySize = 5,
        .party = (const struct TrainerMon[])
        {
            {
#line 13558
            .species = SPECIES_GENGAR,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13560
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 13559
            .lvl = 66,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 13561
                MOVE_SHADOW_BALL,
                MOVE_PSYCHIC,
                MOVE_CONFUSE_RAY,
                MOVE_HYPNOSIS,
            },
            },
            {
#line 13566
            .species = SPECIES_CROBAT,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13568
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 13567
            .lvl = 66,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 13569
                MOVE_SLUDGE_BOMB,
                MOVE_AIR_CUTTER,
                MOVE_SHADOW_BALL,
                MOVE_CONFUSE_RAY,
            },
            },
            {
#line 13574
            .species = SPECIES_MISDREAVUS,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13576
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 13575
            .lvl = 65,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 13577
                MOVE_SHADOW_BALL,
                MOVE_PSYCHIC,
                MOVE_THUNDERBOLT,
                MOVE_ATTRACT,
            },
            },
            {
#line 13582
            .species = SPECIES_ARBOK,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13584
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 13583
            .lvl = 68,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 13585
                MOVE_SLUDGE_BOMB,
                MOVE_EARTHQUAKE,
                MOVE_GIGA_DRAIN,
                MOVE_DOUBLE_TEAM,
            },
            },
            {
#line 13590
            .species = SPECIES_GENGAR,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13590
            .heldItem = ITEM_CHESTO_BERRY,
#line 13592
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 13591
            .lvl = 70,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 13593
                MOVE_SHADOW_BALL,
                MOVE_PSYCHIC,
                MOVE_THUNDERBOLT,
                MOVE_SLUDGE_BOMB,
            },
            },
        },
    },
#line 13598
    [DIFFICULTY_NORMAL][TRAINER_ELITE_FOUR_LANCE_2] =
    {
#line 13599
        .trainerName = _("LANCE"),
#line 13600
        .trainerClass = TRAINER_CLASS_ELITE_FOUR,
#line 13601
        .trainerPic = TRAINER_PIC_ELITE_FOUR_LANCE,
        .encounterMusic_gender =
#line 13603
            TRAINER_ENCOUNTER_MUSIC_ELITE_FOUR,
#line 13604
        .items = { ITEM_FULL_RESTORE, ITEM_FULL_RESTORE },
#line 13605
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 13606
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
#line 13607
        .mugshotColor = MUGSHOT_COLOR_BLUE,
        .partySize = 5,
        .party = (const struct TrainerMon[])
        {
            {
#line 13609
            .species = SPECIES_GYARADOS,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13611
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 13610
            .lvl = 68,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 13612
                MOVE_HYPER_BEAM,
                MOVE_DRAGON_DANCE,
                MOVE_EARTHQUAKE,
                MOVE_THUNDER_WAVE,
            },
            },
            {
#line 13617
            .species = SPECIES_DRAGONITE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13619
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 13618
            .lvl = 66,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 13620
                MOVE_HYPER_BEAM,
                MOVE_EARTHQUAKE,
                MOVE_DRAGON_CLAW,
                MOVE_FLAMETHROWER,
            },
            },
            {
#line 13625
            .species = SPECIES_KINGDRA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13627
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 13626
            .lvl = 66,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 13628
                MOVE_HYPER_BEAM,
                MOVE_DRAGON_DANCE,
                MOVE_SURF,
                MOVE_ICE_BEAM,
            },
            },
            {
#line 13633
            .species = SPECIES_AERODACTYL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13635
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 13634
            .lvl = 70,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 13636
                MOVE_HYPER_BEAM,
                MOVE_ANCIENT_POWER,
                MOVE_AERIAL_ACE,
                MOVE_EARTHQUAKE,
            },
            },
            {
#line 13641
            .species = SPECIES_DRAGONITE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13641
            .heldItem = ITEM_PERSIM_BERRY,
#line 13643
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 13642
            .lvl = 72,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 13644
                MOVE_HYPER_BEAM,
                MOVE_OUTRAGE,
                MOVE_THUNDERBOLT,
                MOVE_ICE_BEAM,
            },
            },
        },
    },
#line 13649
    [DIFFICULTY_NORMAL][TRAINER_CHAMPION_REMATCH_SQUIRTLE] =
    {
#line 13650
        .trainerName = _("TERRY"),
#line 13651
        .trainerClass = TRAINER_CLASS_CHAMPION,
#line 13652
        .trainerPic = TRAINER_PIC_CHAMPION_RIVAL,
        .encounterMusic_gender =
#line 13654
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 13655
        .items = { ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_FULL_RESTORE },
#line 13656
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 13657
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
#line 13658
        .mugshotColor = MUGSHOT_COLOR_YELLOW,
        .partySize = 6,
        .party = (const struct TrainerMon[])
        {
            {
#line 13660
            .species = SPECIES_HERACROSS,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13662
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 13661
            .lvl = 72,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 13663
                MOVE_MEGAHORN,
                MOVE_EARTHQUAKE,
                MOVE_COUNTER,
                MOVE_ROCK_TOMB,
            },
            },
            {
#line 13668
            .species = SPECIES_ALAKAZAM,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13670
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 13669
            .lvl = 73,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 13671
                MOVE_PSYCHIC,
                MOVE_SHADOW_BALL,
                MOVE_CALM_MIND,
                MOVE_REFLECT,
            },
            },
            {
#line 13676
            .species = SPECIES_TYRANITAR,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13678
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 13677
            .lvl = 72,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 13679
                MOVE_CRUNCH,
                MOVE_EARTHQUAKE,
                MOVE_THUNDERBOLT,
                MOVE_AERIAL_ACE,
            },
            },
            {
#line 13684
            .species = SPECIES_ARCANINE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13686
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 13685
            .lvl = 73,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 13687
                MOVE_EXTREME_SPEED,
                MOVE_OVERHEAT,
                MOVE_AERIAL_ACE,
                MOVE_IRON_TAIL,
            },
            },
            {
#line 13692
            .species = SPECIES_EXEGGUTOR,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13694
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 13693
            .lvl = 73,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 13695
                MOVE_GIGA_DRAIN,
                MOVE_PSYCHIC,
                MOVE_SLEEP_POWDER,
                MOVE_LIGHT_SCREEN,
            },
            },
            {
#line 13700
            .species = SPECIES_BLASTOISE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13700
            .heldItem = ITEM_SITRUS_BERRY,
#line 13702
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 13701
            .lvl = 75,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 13703
                MOVE_HYDRO_PUMP,
                MOVE_ICE_BEAM,
                MOVE_EARTHQUAKE,
                MOVE_RAIN_DANCE,
            },
            },
        },
    },
#line 13708
    [DIFFICULTY_NORMAL][TRAINER_CHAMPION_REMATCH_BULBASAUR] =
    {
#line 13709
        .trainerName = _("TERRY"),
#line 13710
        .trainerClass = TRAINER_CLASS_CHAMPION,
#line 13711
        .trainerPic = TRAINER_PIC_CHAMPION_RIVAL,
        .encounterMusic_gender =
#line 13713
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 13714
        .items = { ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_FULL_RESTORE },
#line 13715
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 13716
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
#line 13717
        .mugshotColor = MUGSHOT_COLOR_YELLOW,
        .partySize = 6,
        .party = (const struct TrainerMon[])
        {
            {
#line 13719
            .species = SPECIES_HERACROSS,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13721
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 13720
            .lvl = 72,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 13722
                MOVE_MEGAHORN,
                MOVE_EARTHQUAKE,
                MOVE_COUNTER,
                MOVE_ROCK_TOMB,
            },
            },
            {
#line 13727
            .species = SPECIES_ALAKAZAM,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13729
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 13728
            .lvl = 73,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 13730
                MOVE_PSYCHIC,
                MOVE_SHADOW_BALL,
                MOVE_CALM_MIND,
                MOVE_REFLECT,
            },
            },
            {
#line 13735
            .species = SPECIES_TYRANITAR,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13737
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 13736
            .lvl = 72,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 13738
                MOVE_CRUNCH,
                MOVE_EARTHQUAKE,
                MOVE_THUNDERBOLT,
                MOVE_AERIAL_ACE,
            },
            },
            {
#line 13743
            .species = SPECIES_GYARADOS,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13745
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 13744
            .lvl = 73,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 13746
                MOVE_HYDRO_PUMP,
                MOVE_DRAGON_DANCE,
                MOVE_EARTHQUAKE,
                MOVE_HYPER_BEAM,
            },
            },
            {
#line 13751
            .species = SPECIES_ARCANINE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13753
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 13752
            .lvl = 73,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 13754
                MOVE_EXTREME_SPEED,
                MOVE_OVERHEAT,
                MOVE_AERIAL_ACE,
                MOVE_IRON_TAIL,
            },
            },
            {
#line 13759
            .species = SPECIES_VENUSAUR,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13759
            .heldItem = ITEM_SITRUS_BERRY,
#line 13761
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 13760
            .lvl = 75,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 13762
                MOVE_SOLAR_BEAM,
                MOVE_SLUDGE_BOMB,
                MOVE_EARTHQUAKE,
                MOVE_SUNNY_DAY,
            },
            },
        },
    },
#line 13767
    [DIFFICULTY_NORMAL][TRAINER_CHAMPION_REMATCH_CHARMANDER] =
    {
#line 13768
        .trainerName = _("TERRY"),
#line 13769
        .trainerClass = TRAINER_CLASS_CHAMPION,
#line 13770
        .trainerPic = TRAINER_PIC_CHAMPION_RIVAL,
        .encounterMusic_gender =
#line 13772
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 13773
        .items = { ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_FULL_RESTORE },
#line 13774
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 13775
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
#line 13776
        .mugshotColor = MUGSHOT_COLOR_YELLOW,
        .partySize = 6,
        .party = (const struct TrainerMon[])
        {
            {
#line 13778
            .species = SPECIES_HERACROSS,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13780
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 13779
            .lvl = 72,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 13781
                MOVE_MEGAHORN,
                MOVE_EARTHQUAKE,
                MOVE_COUNTER,
                MOVE_ROCK_TOMB,
            },
            },
            {
#line 13786
            .species = SPECIES_ALAKAZAM,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13788
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 13787
            .lvl = 73,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 13789
                MOVE_PSYCHIC,
                MOVE_SHADOW_BALL,
                MOVE_CALM_MIND,
                MOVE_REFLECT,
            },
            },
            {
#line 13794
            .species = SPECIES_TYRANITAR,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13796
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 13795
            .lvl = 72,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 13797
                MOVE_CRUNCH,
                MOVE_EARTHQUAKE,
                MOVE_THUNDERBOLT,
                MOVE_AERIAL_ACE,
            },
            },
            {
#line 13802
            .species = SPECIES_EXEGGUTOR,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13804
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 13803
            .lvl = 73,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 13805
                MOVE_GIGA_DRAIN,
                MOVE_PSYCHIC,
                MOVE_SLEEP_POWDER,
                MOVE_LIGHT_SCREEN,
            },
            },
            {
#line 13810
            .species = SPECIES_GYARADOS,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13812
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 13811
            .lvl = 73,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 13813
                MOVE_HYDRO_PUMP,
                MOVE_DRAGON_DANCE,
                MOVE_EARTHQUAKE,
                MOVE_HYPER_BEAM,
            },
            },
            {
#line 13818
            .species = SPECIES_CHARIZARD,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13818
            .heldItem = ITEM_SITRUS_BERRY,
#line 13820
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 13819
            .lvl = 75,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 13821
                MOVE_FIRE_BLAST,
                MOVE_DRAGON_CLAW,
                MOVE_AERIAL_ACE,
                MOVE_EARTHQUAKE,
            },
            },
        },
    },
#line 13826
    [DIFFICULTY_NORMAL][TRAINER_CUE_BALL_PAXTON] =
    {
#line 13827
        .trainerName = _("PAXTON"),
#line 13828
        .trainerClass = TRAINER_CLASS_CUE_BALL,
#line 13829
        .trainerPic = TRAINER_PIC_CUE_BALL,
        .encounterMusic_gender =
#line 13831
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 13832
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 13833
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 13835
            .species = SPECIES_WEEZING,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13837
            .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
#line 13836
            .lvl = 39,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 13839
            .species = SPECIES_MUK,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13841
            .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
#line 13840
            .lvl = 39,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
