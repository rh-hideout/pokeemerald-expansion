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
        .partySize = 4,
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
            {
#line 33
            .species = SPECIES_WOBBUFFET,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 33
            .heldItem = ITEM_STICKY_BARB,
#line 38
            .ev = TRAINER_PARTY_EVS(252, 0, 0, 252, 4, 0),
#line 37
            .iv = TRAINER_PARTY_IVS(25, 26, 27, 28, 29, 30),
#line 36
            .ability = ABILITY_TELEPATHY,
#line 35
            .lvl = 69,
#line 39
            .ball = ITEM_DUSK_BALL,
#line 34
            .nature = NATURE_HASTY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
#line 40
            .isShadow = TRUE,
#line 41
            .heartGauge = 3000,
            .moves = {
#line 42
                MOVE_AIR_SLASH,
                MOVE_BARRIER,
                MOVE_SOLAR_BEAM,
                MOVE_EXPLOSION,
            },
            },
        },
    },
#line 47
#line 54
    [DIFFICULTY_NORMAL][1] =
    {
#line 48
        .trainerName = _("Test2"),
#line 49
        .trainerClass = TRAINER_CLASS_PKMN_TRAINER_1,
#line 50
        .trainerPic = TRAINER_PIC_RED,
        .encounterMusic_gender =
#line 52
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 53
        .doubleBattle = FALSE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 56
            .species = SPECIES_MEWTWO,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 58
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 57
            .lvl = 5,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 59
#line 66
    [DIFFICULTY_NORMAL][2] =
    {
#line 60
        .trainerName = _("Test2"),
#line 61
        .trainerClass = TRAINER_CLASS_PKMN_TRAINER_1,
#line 62
        .trainerPic = TRAINER_PIC_RED,
        .encounterMusic_gender =
#line 64
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 65
        .doubleBattle = FALSE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 68
            .species = SPECIES_MEWTWO,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 70
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 69
            .lvl = 50,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 71
#line 78
    [DIFFICULTY_EASY][2] =
    {
#line 72
        .trainerName = _("Test2"),
#line 73
        .trainerClass = TRAINER_CLASS_PKMN_TRAINER_1,
#line 74
        .trainerPic = TRAINER_PIC_RED,
        .encounterMusic_gender =
#line 76
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 77
        .doubleBattle = FALSE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 80
            .species = SPECIES_METAPOD,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 82
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 81
            .lvl = 1,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 83
#line 90
    [DIFFICULTY_HARD][2] =
    {
#line 84
        .trainerName = _("Test2"),
#line 85
        .trainerClass = TRAINER_CLASS_PKMN_TRAINER_1,
#line 86
        .trainerPic = TRAINER_PIC_RED,
        .encounterMusic_gender =
#line 88
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 89
        .doubleBattle = FALSE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 92
            .species = SPECIES_ARCEUS,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 94
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 93
            .lvl = 99,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 95
    [DIFFICULTY_NORMAL][3] =
    {
#line 96
        .trainerName = _("Test3"),
#line 97
        .trainerClass = TRAINER_CLASS_PKMN_TRAINER_1,
#line 98
        .trainerPic = TRAINER_PIC_RED,
        .encounterMusic_gender =
#line 100
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 101
        .doubleBattle = FALSE,
#line 102
        .partySize = 1,
        .poolSize = 4,
        .party = (const struct TrainerMon[])
        {
            {
#line 104
            .species = SPECIES_WYNAUT,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 105
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 105
            .lvl = 100,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 106
            .species = SPECIES_WOBBUFFET,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 107
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 107
            .lvl = 100,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 108
            .species = SPECIES_EEVEE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 109
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 109
            .lvl = 100,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 110
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 111
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 111
            .lvl = 100,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 112
    [DIFFICULTY_NORMAL][4] =
    {
#line 113
        .trainerName = _("Test4"),
#line 114
        .trainerClass = TRAINER_CLASS_PKMN_TRAINER_1,
#line 115
        .trainerPic = TRAINER_PIC_RED,
        .encounterMusic_gender =
#line 117
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 118
        .doubleBattle = FALSE,
#line 119
        .partySize = 3,
        .poolSize = 6,
        .party = (const struct TrainerMon[])
        {
            {
#line 121
            .species = SPECIES_WYNAUT,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 122
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 122
            .lvl = 100,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 123
            .species = SPECIES_WOBBUFFET,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 125
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 125
            .lvl = 100,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
#line 124
            .tags = MON_POOL_TAG_LEAD,
            },
            {
#line 126
            .species = SPECIES_EEVEE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 128
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 128
            .lvl = 100,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
#line 127
            .tags = MON_POOL_TAG_ACE,
            },
            {
#line 129
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 130
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 130
            .lvl = 100,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 131
            .species = SPECIES_ODDISH,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 133
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 133
            .lvl = 100,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
#line 132
            .tags = MON_POOL_TAG_ACE,
            },
            {
#line 134
            .species = SPECIES_ARON,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 136
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 136
            .lvl = 100,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
#line 135
            .tags = MON_POOL_TAG_LEAD,
            },
        },
    },
#line 137
    [DIFFICULTY_NORMAL][5] =
    {
#line 138
        .trainerName = _("Test5"),
#line 139
        .trainerClass = TRAINER_CLASS_PKMN_TRAINER_1,
#line 140
        .trainerPic = TRAINER_PIC_RED,
        .encounterMusic_gender =
#line 142
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 143
        .doubleBattle = TRUE,
#line 145
        .poolRuleIndex = POOL_RULESET_WEATHER_DOUBLES,
#line 144
        .partySize = 3,
        .poolSize = 10,
        .party = (const struct TrainerMon[])
        {
            {
#line 147
            .species = SPECIES_WYNAUT,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 149
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 149
            .lvl = 100,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
#line 148
            .tags = MON_POOL_TAG_LEAD,
            },
            {
#line 150
            .species = SPECIES_WOBBUFFET,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 152
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 152
            .lvl = 100,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
#line 151
            .tags = MON_POOL_TAG_LEAD,
            },
            {
#line 153
            .species = SPECIES_VULPIX,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 155
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 155
            .lvl = 100,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
#line 154
            .tags = MON_POOL_TAG_LEAD | MON_POOL_TAG_WEATHER_SETTER,
            },
            {
#line 156
            .species = SPECIES_BULBASAUR,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 158
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 158
            .lvl = 100,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
#line 157
            .tags = MON_POOL_TAG_LEAD | MON_POOL_TAG_WEATHER_ABUSER,
            },
            {
#line 159
            .species = SPECIES_TORKOAL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 161
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 161
            .lvl = 100,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
#line 160
            .tags = MON_POOL_TAG_LEAD | MON_POOL_TAG_WEATHER_SETTER,
            },
            {
#line 162
            .species = SPECIES_CHERRIM,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 164
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 164
            .lvl = 100,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
#line 163
            .tags = MON_POOL_TAG_LEAD | MON_POOL_TAG_WEATHER_ABUSER,
            },
            {
#line 165
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 167
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 167
            .lvl = 100,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
#line 166
            .tags = MON_POOL_TAG_LEAD,
            },
            {
#line 168
            .species = SPECIES_ARON,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 170
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 170
            .lvl = 100,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
#line 169
            .tags = MON_POOL_TAG_LEAD,
            },
            {
#line 171
            .species = SPECIES_ODDISH,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 172
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 172
            .lvl = 100,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 173
            .species = SPECIES_EEVEE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 174
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 174
            .lvl = 100,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 175
    [DIFFICULTY_NORMAL][6] =
    {
#line 176
        .trainerName = _("Test6"),
#line 177
        .trainerClass = TRAINER_CLASS_PKMN_TRAINER_1,
#line 178
        .trainerPic = TRAINER_PIC_RED,
        .encounterMusic_gender =
#line 180
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 181
        .doubleBattle = FALSE,
#line 183
        .poolRuleIndex = POOL_RULESET_BASIC,
#line 182
        .partySize = 2,
        .poolSize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 185
            .species = SPECIES_WYNAUT,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 187
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 187
            .lvl = 100,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
#line 186
            .tags = MON_POOL_TAG_LEAD,
            },
            {
#line 188
            .species = SPECIES_WOBBUFFET,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 190
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 190
            .lvl = 100,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
#line 189
            .tags = MON_POOL_TAG_LEAD,
            },
            {
#line 191
            .species = SPECIES_EEVEE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 193
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 193
            .lvl = 100,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
#line 192
            .tags = MON_POOL_TAG_LEAD,
            },
        },
    },
#line 194
    [DIFFICULTY_NORMAL][7] =
    {
#line 195
        .trainerName = _("Test1"),
#line 196
        .trainerClass = TRAINER_CLASS_PKMN_TRAINER_1,
#line 197
        .trainerPic = TRAINER_PIC_RED,
        .encounterMusic_gender =
#line 199
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 200
        .doubleBattle = FALSE,
#line 202
        .poolRuleIndex = POOL_RULESET_BASIC,
#line 203
        .poolPruneIndex = POOL_PRUNE_TEST,
#line 201
        .partySize = 2,
        .poolSize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 205
            .species = SPECIES_WYNAUT,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 206
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 206
            .lvl = 100,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 207
            .species = SPECIES_WOBBUFFET,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 209
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 209
            .lvl = 100,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
#line 208
            .tags = MON_POOL_TAG_LEAD,
            },
            {
#line 210
            .species = SPECIES_EEVEE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 211
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 211
            .lvl = 100,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 212
    [DIFFICULTY_NORMAL][8] =
    {
#line 213
        .trainerName = _("Test1"),
#line 214
        .trainerClass = TRAINER_CLASS_PKMN_TRAINER_1,
#line 215
        .trainerPic = TRAINER_PIC_RED,
        .encounterMusic_gender =
#line 217
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 218
        .doubleBattle = FALSE,
#line 220
        .poolRuleIndex = POOL_RULESET_BASIC,
#line 221
        .poolPickIndex = POOL_PICK_LOWEST,
#line 219
        .partySize = 2,
        .poolSize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 223
            .species = SPECIES_WYNAUT,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 225
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 225
            .lvl = 100,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
#line 224
            .tags = MON_POOL_TAG_ACE,
            },
            {
#line 226
            .species = SPECIES_WOBBUFFET,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 227
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 227
            .lvl = 100,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 228
            .species = SPECIES_EEVEE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 230
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 230
            .lvl = 100,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
#line 229
            .tags = MON_POOL_TAG_LEAD,
            },
        },
    },
