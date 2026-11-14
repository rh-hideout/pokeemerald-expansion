static const struct TrainerMon sBattleTowerSilverBrainParty[FRONTIER_PARTY_SIZE] =
{
    {
        .species = SPECIES_ALAKAZAM,
        .heldItem = ITEM_BRIGHT_POWDER,
        .iv = TRAINER_PARTY_FIXED_IVS(24),
        .nature = NATURE_MODEST,
        .ev = TRAINER_PARTY_EVS(106, 0, 152, 152, 100, 0),
        .moves = {MOVE_THUNDER_PUNCH, MOVE_FIRE_PUNCH, MOVE_ICE_PUNCH, MOVE_DISABLE},
        .ball = BALL_POKE
    },
    {
        .species = SPECIES_ENTEI,
        .heldItem = ITEM_LUM_BERRY,
        .iv = TRAINER_PARTY_FIXED_IVS(24),
        .nature = NATURE_LONELY,
        .ev = TRAINER_PARTY_EVS(100, 152, 152, 0, 100, 6),
        .moves = {MOVE_FIRE_BLAST, MOVE_CALM_MIND, MOVE_RETURN, MOVE_ROAR},
        .ball = BALL_POKE
    },
    {
        .species = SPECIES_SNORLAX,
        .heldItem = ITEM_QUICK_CLAW,
        .iv = TRAINER_PARTY_FIXED_IVS(24),
        .nature = NATURE_ADAMANT,
        .ev = TRAINER_PARTY_EVS(152, 152, 0, 0, 106, 100),
        .moves = {MOVE_BODY_SLAM, MOVE_BELLY_DRUM, MOVE_YAWN, MOVE_SHADOW_BALL},
        .ball = BALL_POKE
    },
};

static const struct TrainerMon sBattleTowerGoldBrainParty[FRONTIER_PARTY_SIZE] = {
    {
        .species = SPECIES_RAIKOU,
        .heldItem = ITEM_LUM_BERRY,
        .iv = TRAINER_PARTY_FIXED_IVS(MAX_PER_STAT_IVS),
        .nature = NATURE_MODEST,
        .ev = TRAINER_PARTY_EVS(158, 0, 252, 100, 0, 0),
        .moves = {MOVE_THUNDERBOLT, MOVE_CALM_MIND, MOVE_REFLECT, MOVE_REST},
        .ball = BALL_POKE
    },
    {
        .species = SPECIES_LATIOS,
        .heldItem = ITEM_BRIGHT_POWDER,
        .iv = TRAINER_PARTY_FIXED_IVS(MAX_PER_STAT_IVS),
        .nature = NATURE_MODEST,
        .ev = TRAINER_PARTY_EVS(252, 0, 252, 6, 0, 0),
        .moves = {MOVE_PSYCHIC, MOVE_CALM_MIND, MOVE_RECOVER, MOVE_DRAGON_CLAW},
        .ball = BALL_POKE
    },
    {
        .species = SPECIES_SNORLAX,
        .heldItem = ITEM_CHESTO_BERRY,
        .iv = TRAINER_PARTY_FIXED_IVS(MAX_PER_STAT_IVS),
        .nature = NATURE_ADAMANT,
        .ev = TRAINER_PARTY_EVS(252, 252, 0, 0, 6, 0),
        .moves = {MOVE_CURSE, MOVE_RETURN, MOVE_REST, MOVE_SHADOW_BALL},
        .ball = BALL_POKE
    },
};

static const struct TrainerMon sBattleDomeSilverBrainParty[FRONTIER_PARTY_SIZE] = {
    {
        .species = SPECIES_SWAMPERT,
        .heldItem = ITEM_FOCUS_BAND,
        .iv = TRAINER_PARTY_FIXED_IVS(20),
        .nature = NATURE_BRAVE,
        .ev = TRAINER_PARTY_EVS(152, 152, 106, 0, 100, 0),
        .moves = {MOVE_SURF, MOVE_EARTHQUAKE, MOVE_ICE_BEAM, MOVE_COUNTER},
        .ball = BALL_POKE
    },
    {
        .species = SPECIES_SALAMENCE,
        .heldItem = ITEM_LUM_BERRY,
        .iv = TRAINER_PARTY_FIXED_IVS(20),
        .nature = NATURE_ADAMANT,
        .ev = TRAINER_PARTY_EVS(152, 152, 106, 100, 0, 0),
        .moves = {MOVE_EARTHQUAKE, MOVE_BRICK_BREAK, MOVE_DRAGON_CLAW, MOVE_AERIAL_ACE},
        .ball = BALL_POKE
    },
    {
        .species = SPECIES_CHARIZARD,
        .heldItem = ITEM_WHITE_HERB,
        .iv = TRAINER_PARTY_FIXED_IVS(20),
        .nature = NATURE_QUIET,
        .ev = TRAINER_PARTY_EVS(100, 152, 106, 152, 0, 0),
        .moves = {MOVE_OVERHEAT, MOVE_ROCK_SLIDE, MOVE_AERIAL_ACE, MOVE_EARTHQUAKE},
        .ball = BALL_POKE
    },
};

static const struct TrainerMon sBattleDomeGoldBrainParty[FRONTIER_PARTY_SIZE] = {
    {
        .species = SPECIES_SWAMPERT,
        .heldItem = ITEM_LEFTOVERS,
        .iv = TRAINER_PARTY_FIXED_IVS(MAX_PER_STAT_IVS),
        .nature = NATURE_BRAVE,
        .ev = TRAINER_PARTY_EVS(252, 252, 6, 0, 0, 0),
        .moves = {MOVE_SURF, MOVE_EARTHQUAKE, MOVE_ICE_BEAM, MOVE_MIRROR_COAT},
        .ball = BALL_POKE
    },
    {
        .species = SPECIES_METAGROSS,
        .heldItem = ITEM_QUICK_CLAW,
        .iv = TRAINER_PARTY_FIXED_IVS(MAX_PER_STAT_IVS),
        .nature = NATURE_BRAVE,
        .ev = TRAINER_PARTY_EVS(252, 252, 6, 0, 0, 0),
        .moves = {MOVE_PSYCHIC, MOVE_METEOR_MASH, MOVE_EARTHQUAKE, MOVE_PROTECT},
        .ball = BALL_POKE
    },
    {
        .species = SPECIES_LATIAS,
        .heldItem = ITEM_CHESTO_BERRY,
        .iv = TRAINER_PARTY_FIXED_IVS(MAX_PER_STAT_IVS),
        .nature = NATURE_MODEST,
        .ev = TRAINER_PARTY_EVS(252, 0, 252, 6, 0, 0),
        .moves = {MOVE_THUNDERBOLT, MOVE_PSYCHIC, MOVE_CALM_MIND, MOVE_REST},
        .ball = BALL_POKE
    },
};

static const struct TrainerMon sBattlePalaceSilverBrainParty[FRONTIER_PARTY_SIZE] = {
    {
        .species = SPECIES_CROBAT,
        .heldItem = ITEM_BRIGHT_POWDER,
        .iv = TRAINER_PARTY_FIXED_IVS(16),
        .nature = NATURE_ADAMANT,
        .ev = TRAINER_PARTY_EVS(152, 0, 0, 152, 100, 106),
        .moves = {MOVE_CONFUSE_RAY, MOVE_DOUBLE_TEAM, MOVE_TOXIC, MOVE_FLY},
        .ball = BALL_POKE
    },
    {
        .species = SPECIES_SLAKING,
        .heldItem = ITEM_SCOPE_LENS,
        .iv = TRAINER_PARTY_FIXED_IVS(16),
        .nature = NATURE_HARDY,
        .ev = TRAINER_PARTY_EVS(152, 152, 0, 106, 100, 0),
        .moves = {MOVE_EARTHQUAKE, MOVE_SWAGGER, MOVE_SHADOW_BALL, MOVE_BRICK_BREAK},
        .ball = BALL_POKE
    },
    {
        .species = SPECIES_LAPRAS,
        .heldItem = ITEM_QUICK_CLAW,
        .iv = TRAINER_PARTY_FIXED_IVS(16),
        .nature = NATURE_QUIET,
        .ev = TRAINER_PARTY_EVS(0, 0, 252, 0, 106, 152),
        .moves = {MOVE_ICE_BEAM, MOVE_HORN_DRILL, MOVE_CONFUSE_RAY, MOVE_PROTECT},
        .ball = BALL_POKE
    },
};

static const struct TrainerMon sBattlePalaceGoldBrainParty[FRONTIER_PARTY_SIZE] = {
    {
        .species = SPECIES_ARCANINE,
        .heldItem = ITEM_WHITE_HERB,
        .iv = TRAINER_PARTY_FIXED_IVS(MAX_PER_STAT_IVS),
        .nature = NATURE_HASTY,
        .ev = TRAINER_PARTY_EVS(6, 252, 252, 0, 0, 0),
        .moves = {MOVE_OVERHEAT, MOVE_EXTREME_SPEED, MOVE_ROAR, MOVE_PROTECT},
        .ball = BALL_POKE
    },
    {
        .species = SPECIES_SLAKING,
        .heldItem = ITEM_SCOPE_LENS,
        .iv = TRAINER_PARTY_FIXED_IVS(MAX_PER_STAT_IVS),
        .nature = NATURE_HARDY,
        .ev = TRAINER_PARTY_EVS(6, 252, 0, 252, 0, 0),
        .moves = {MOVE_HYPER_BEAM, MOVE_EARTHQUAKE, MOVE_SHADOW_BALL, MOVE_YAWN},
        .ball = BALL_POKE
    },
    {
        .species = SPECIES_SUICUNE,
        .heldItem = ITEM_KINGS_ROCK,
        .iv = TRAINER_PARTY_FIXED_IVS(MAX_PER_STAT_IVS),
        .nature = NATURE_HASTY,
        .ev = TRAINER_PARTY_EVS(252, 0, 252, 6, 0, 0),
        .moves = {MOVE_BLIZZARD, MOVE_SURF, MOVE_BITE, MOVE_CALM_MIND},
        .ball = BALL_POKE
    }
};

static const struct TrainerMon sBattleArenaSilverBrainParty[FRONTIER_PARTY_SIZE] = {
    {
        .species = SPECIES_HERACROSS,
        .heldItem = ITEM_SALAC_BERRY,
        .iv = TRAINER_PARTY_FIXED_IVS(20),
        .nature = NATURE_JOLLY,
        .ev = TRAINER_PARTY_EVS(106, 152, 0, 152, 0, 100),
        .moves = {MOVE_MEGAHORN, MOVE_ROCK_TOMB, MOVE_ENDURE, MOVE_REVERSAL},
        .ball = BALL_POKE
    },
    {
        .species = SPECIES_UMBREON,
        .heldItem = ITEM_LEFTOVERS,
        .iv = TRAINER_PARTY_FIXED_IVS(20),
        .nature = NATURE_CALM,
        .ev = TRAINER_PARTY_EVS(152, 0, 100, 0, 152, 106),
        .moves = {MOVE_BODY_SLAM, MOVE_CONFUSE_RAY, MOVE_PSYCHIC, MOVE_FEINT_ATTACK},
        .ball = BALL_POKE
    },
    {
        .species = SPECIES_SHEDINJA,
        .heldItem = ITEM_BRIGHT_POWDER,
        .iv = TRAINER_PARTY_FIXED_IVS(20),
        .nature = NATURE_ADAMANT,
        .ev = TRAINER_PARTY_EVS(0, 252, 6, 252, 0, 0),
        .moves = {MOVE_SHADOW_BALL, MOVE_RETURN, MOVE_CONFUSE_RAY, MOVE_AERIAL_ACE},
        .ball = BALL_POKE
    },
};

static const struct TrainerMon sBattleArenaGoldBrainParty[FRONTIER_PARTY_SIZE] = {
    {
        .species = SPECIES_UMBREON,
        .heldItem = ITEM_CHESTO_BERRY,
        .iv = TRAINER_PARTY_FIXED_IVS(MAX_PER_STAT_IVS),
        .nature = NATURE_CALM,
        .ev = TRAINER_PARTY_EVS(252, 0, 0, 0, 252, 6),
        .moves = {MOVE_DOUBLE_EDGE, MOVE_CONFUSE_RAY, MOVE_REST, MOVE_PSYCHIC},
        .ball = BALL_POKE
    },
    {
        .species = SPECIES_GENGAR,
        .heldItem = ITEM_LEFTOVERS,
        .iv = TRAINER_PARTY_FIXED_IVS(MAX_PER_STAT_IVS),
        .nature = NATURE_MODEST,
        .ev = TRAINER_PARTY_EVS(252, 0, 252, 0, 6, 0),
        .moves = {MOVE_PSYCHIC, MOVE_HYPNOSIS, MOVE_DREAM_EATER, MOVE_DESTINY_BOND},
        .ball = BALL_POKE
    },
    {
        .species = SPECIES_BRELOOM,
        .heldItem = ITEM_LUM_BERRY,
        .iv = TRAINER_PARTY_FIXED_IVS(MAX_PER_STAT_IVS),
        .nature = NATURE_JOLLY,
        .ev = TRAINER_PARTY_EVS(6, 252, 0, 252, 0, 0),
        .moves = {MOVE_SPORE, MOVE_FOCUS_PUNCH, MOVE_GIGA_DRAIN, MOVE_HEADBUTT},
        .ball = BALL_POKE
    },
};

static const struct TrainerMon sBattlePikeSilverBrainParty[FRONTIER_PARTY_SIZE] = {
    {
        .species = SPECIES_SEVIPER,
        .heldItem = ITEM_QUICK_CLAW,
        .iv = TRAINER_PARTY_FIXED_IVS(16),
        .nature = NATURE_BRAVE,
        .ev = TRAINER_PARTY_EVS(252, 0, 252, 0, 6, 0),
        .moves = {MOVE_SWAGGER, MOVE_CRUNCH, MOVE_POISON_FANG, MOVE_GIGA_DRAIN},
        .ball = BALL_POKE
    },
    {
        .species = SPECIES_SHUCKLE,
        .heldItem = ITEM_CHESTO_BERRY,
        .iv = TRAINER_PARTY_FIXED_IVS(16),
        .nature = NATURE_BOLD,
        .ev = TRAINER_PARTY_EVS(252, 0, 0, 0, 106, 252),
        .moves = {MOVE_TOXIC, MOVE_SANDSTORM, MOVE_PROTECT, MOVE_REST},
        .ball = BALL_POKE
    },
    {
        .species = SPECIES_MILOTIC,
        .heldItem = ITEM_LEFTOVERS,
        .iv = TRAINER_PARTY_FIXED_IVS(16),
        .nature = NATURE_MODEST,
        .ev = TRAINER_PARTY_EVS(152, 0, 100, 0, 152, 106),
        .moves = {MOVE_ICE_BEAM, MOVE_MIRROR_COAT, MOVE_SURF, MOVE_RECOVER},
        .ball = BALL_POKE
    },
};

static const struct TrainerMon sBattlePikeGoldBrainParty[FRONTIER_PARTY_SIZE] = {
    {
        .species = SPECIES_SEVIPER,
        .heldItem = ITEM_FOCUS_BAND,
        .iv = TRAINER_PARTY_FIXED_IVS(MAX_PER_STAT_IVS),
        .nature = NATURE_BOLD,
        .ev = TRAINER_PARTY_EVS(252, 0, 0, 0, 252, 6),
        .moves = {MOVE_SWAGGER, MOVE_CRUNCH, MOVE_SLUDGE_BOMB, MOVE_GIGA_DRAIN},
        .ball = BALL_POKE
    },
    {
        .species = SPECIES_STEELIX,
        .heldItem = ITEM_BRIGHT_POWDER,
        .iv = TRAINER_PARTY_FIXED_IVS(MAX_PER_STAT_IVS),
        .nature = NATURE_BRAVE,
        .ev = TRAINER_PARTY_EVS(252, 0, 0, 0, 6, 252),
        .moves = {MOVE_EARTHQUAKE, MOVE_ROCK_SLIDE, MOVE_EXPLOSION, MOVE_SCREECH},
        .ball = BALL_POKE
    },
    {
        .species = SPECIES_GYARADOS,
        .heldItem = ITEM_CHESTO_BERRY,
        .iv = TRAINER_PARTY_FIXED_IVS(MAX_PER_STAT_IVS),
        .nature = NATURE_ADAMANT,
        .ev = TRAINER_PARTY_EVS(252, 6, 0, 0, 0, 252),
        .moves = {MOVE_DRAGON_DANCE, MOVE_RETURN, MOVE_ROAR, MOVE_REST},
        .ball = BALL_POKE
    },
};

static const struct TrainerMon sBattlePyramidSilverBrainParty[FRONTIER_PARTY_SIZE] = {
    {
        .species = SPECIES_REGIROCK,
        .heldItem = ITEM_QUICK_CLAW,
        .iv = TRAINER_PARTY_FIXED_IVS(16),
        .nature = NATURE_ADAMANT,
        .ev = TRAINER_PARTY_EVS(152, 152, 0, 0, 106, 100),
        .moves = {MOVE_EXPLOSION, MOVE_SUPERPOWER, MOVE_EARTHQUAKE, MOVE_ANCIENT_POWER},
        .ball = BALL_POKE
    },
    {
        .species = SPECIES_REGISTEEL,
        .heldItem = ITEM_LEFTOVERS,
        .iv = TRAINER_PARTY_FIXED_IVS(16),
        .nature = NATURE_ADAMANT,
        .ev = TRAINER_PARTY_EVS(152, 152, 0, 0, 6, 200),
        .moves = {MOVE_EARTHQUAKE, MOVE_METAL_CLAW, MOVE_TOXIC, MOVE_IRON_DEFENSE},
        .ball = BALL_POKE
    },
    {
        .species = SPECIES_REGICE,
        .heldItem = ITEM_CHESTO_BERRY,
        .iv = TRAINER_PARTY_FIXED_IVS(16),
        .nature = NATURE_MODEST,
        .ev = TRAINER_PARTY_EVS(106, 0, 152, 0, 100, 152),
        .moves = {MOVE_ICE_BEAM, MOVE_AMNESIA, MOVE_THUNDER, MOVE_REST},
        .ball = BALL_POKE
    },
};

static const struct TrainerMon sBattlePyramidGoldBrainParty[FRONTIER_PARTY_SIZE] = {
    {
        .species = SPECIES_ARTICUNO,
        .heldItem = ITEM_SCOPE_LENS,
        .iv = TRAINER_PARTY_FIXED_IVS(MAX_PER_STAT_IVS),
        .nature = NATURE_MILD,
        .ev = TRAINER_PARTY_EVS(6, 0, 252, 252, 0, 0),
        .moves = {MOVE_BLIZZARD, MOVE_WATER_PULSE, MOVE_AERIAL_ACE, MOVE_REFLECT},
        .ball = BALL_POKE
    },
    {
        .species = SPECIES_ZAPDOS,
        .heldItem = ITEM_LUM_BERRY,
        .iv = TRAINER_PARTY_FIXED_IVS(MAX_PER_STAT_IVS),
        .nature = NATURE_MILD,
        .ev = TRAINER_PARTY_EVS(6, 0, 252, 252, 0, 0),
        .moves = {MOVE_THUNDER, MOVE_DETECT, MOVE_DRILL_PECK, MOVE_LIGHT_SCREEN},
        .ball = BALL_POKE
    },
    {
        .species = SPECIES_MOLTRES,
        .heldItem = ITEM_BRIGHT_POWDER,
        .iv = TRAINER_PARTY_FIXED_IVS(MAX_PER_STAT_IVS),
        .nature = NATURE_MILD,
        .ev = TRAINER_PARTY_EVS(6, 0, 252, 252, 0, 0),
        .moves = {MOVE_FIRE_BLAST, MOVE_HYPER_BEAM, MOVE_AERIAL_ACE, MOVE_SAFEGUARD},
        .ball = BALL_POKE
    },
};

