//
// DO NOT MODIFY THIS FILE! It is auto-generated from src/data/battle_partners.party
//
// If you want to modify this file set COMPETITIVE_PARTY_SYNTAX to FALSE
// in include/config/general.h and remove this notice.
// Use sed -i '/^#line/d' 'src/data/battle_partners.h' to remove #line markers.
//

#line 1 "src/data/battle_partners.party"

#line 1
    [PARTNER_NONE] =
    {
#line 3
        .trainerClass = TRAINER_CLASS_PKMN_TRAINER_1,
#line 4
        .trainerPic = TRAINER_BACK_PIC_BRENDAN,
        .encounterMusic_gender = 
#line 6
            TRAINER_ENCOUNTER_MUSIC_MALE,
        .partySize = 0,
        .party = (const struct TrainerMon[])
        {
        },
    },
#line 8
    [PARTNER_STEVEN] =
    {
#line 9
        .trainerName = _("STEVEN"),
#line 10
        .trainerClass = TRAINER_CLASS_RIVAL,
#line 11
        .trainerPic = TRAINER_BACK_PIC_STEVEN,
        .encounterMusic_gender = 
#line 13
            TRAINER_ENCOUNTER_MUSIC_MALE,
        .partySize = 6,
        .party = (const struct TrainerMon[])
        {
            {
#line 15
            .species = SPECIES_EXCADRILL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 15
            .heldItem = ITEM_ASSAULT_VEST,
#line 19
            .ev = TRAINER_PARTY_EVS(28, 228, 0, 0, 0, 252),
#line 21
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 16
            .ability = ABILITY_MOLD_BREAKER,
#line 18
            .lvl = 88,
#line 20
            .nature = NATURE_ADAMANT,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
#line 17
            .teraType = TYPE_FIRE,
            .moves = {
#line 21
                MOVE_EARTHQUAKE,
                MOVE_ROCK_SLIDE,
                MOVE_IRON_HEAD,
                MOVE_POISON_JAB,
            },
            },
            {
#line 26
            .species = SPECIES_HEATRAN,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 26
            .heldItem = ITEM_AIR_BALLOON,
#line 29
            .ev = TRAINER_PARTY_EVS(248, 0, 0, 0, 252, 8),
#line 31
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 27
            .ability = ABILITY_FLASH_FIRE,
#line 28
            .lvl = 88,
#line 30
            .nature = NATURE_MODEST,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 31
                MOVE_ERUPTION,
                MOVE_EARTH_POWER,
                MOVE_SUBSTITUTE,
                MOVE_FLASH_CANNON,
            },
            },
            {
#line 36
            .species = SPECIES_BAXCALIBUR,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 36
            .heldItem = ITEM_ROSELI_BERRY,
#line 39
            .ev = TRAINER_PARTY_EVS(252, 248, 0, 8, 0, 0),
#line 41
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 37
            .ability = ABILITY_THERMAL_EXCHANGE,
#line 38
            .lvl = 88,
#line 40
            .nature = NATURE_ADAMANT,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 41
                MOVE_ICE_SHARD,
                MOVE_HIGH_HORSEPOWER,
                MOVE_IRON_HEAD,
                MOVE_DRAGON_DANCE,
            },
            },
            {
#line 46
            .species = SPECIES_DIALGA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 46
            .heldItem = ITEM_ASSAULT_VEST,
#line 49
            .ev = TRAINER_PARTY_EVS(248, 0, 244, 0, 16, 0),
#line 51
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 47
            .ability = ABILITY_TELEPATHY,
#line 48
            .lvl = 88,
#line 50
            .nature = NATURE_MODEST,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 51
                MOVE_DRACO_METEOR,
                MOVE_EARTH_POWER,
                MOVE_FLASH_CANNON,
                MOVE_THUNDERBOLT,
            },
            },
            {
#line 56
            .species = SPECIES_ARCHALUDON,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 56
            .heldItem = ITEM_ASSAULT_VEST,
#line 59
            .ev = TRAINER_PARTY_EVS(0, 0, 252, 0, 4, 252),
#line 61
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 57
            .ability = ABILITY_STAMINA,
#line 58
            .lvl = 88,
#line 60
            .nature = NATURE_CALM,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 61
                MOVE_BODY_PRESS,
                MOVE_METEOR_BEAM,
                MOVE_FLASH_CANNON,
                MOVE_DRACO_METEOR,
            },
            },
            {
#line 66
            .species = SPECIES_LANDORUS,
#line 66
            .gender = TRAINER_MON_MALE,
#line 66
            .heldItem = ITEM_LIFE_ORB,
#line 69
            .ev = TRAINER_PARTY_EVS(96, 0, 0, 152, 252, 8),
#line 71
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 67
            .ability = ABILITY_SHEER_FORCE,
#line 68
            .lvl = 88,
#line 70
            .nature = NATURE_TIMID,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 71
                MOVE_EARTH_POWER,
                MOVE_HURRICANE,
                MOVE_SANDSEAR_STORM,
                MOVE_SLUDGE_BOMB,
            },
            },
        },
    },
