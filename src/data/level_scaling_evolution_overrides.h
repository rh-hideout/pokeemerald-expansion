// Evolution overrides for level scaling
// These specify minimum levels for Pokémon that evolve via non-level methods
// (trade, stones, friendship, etc.) to ensure they don't appear at very low levels

const struct EvolutionOverride gEvolutionOverrides[] =
{
    // Trade evolutions with minimum levels
    { .species = SPECIES_GENGAR, .minimumLevel = 30 },
    { .species = SPECIES_ALAKAZAM, .minimumLevel = 30 },
    { .species = SPECIES_MACHAMP, .minimumLevel = 30 },
    { .species = SPECIES_GOLEM, .minimumLevel = 30 },
    { .species = SPECIES_GOLEM_ALOLA, .minimumLevel = 30 },
    { .species = SPECIES_STEELIX, .minimumLevel = 35 },
    { .species = SPECIES_SCIZOR, .minimumLevel = 40 },
    { .species = SPECIES_KINGDRA, .minimumLevel = 40 },
    { .species = SPECIES_PORYGON2, .minimumLevel = 30 },
    { .species = SPECIES_POLITOED, .minimumLevel = 30 },
    { .species = SPECIES_SLOWKING, .minimumLevel = 30 },
    { .species = SPECIES_HUNTAIL, .minimumLevel = 35 },
    { .species = SPECIES_GOREBYSS, .minimumLevel = 35 },
    { .species = SPECIES_MILOTIC, .minimumLevel = 35 },
    { .species = SPECIES_DUSKNOIR, .minimumLevel = 45 },
    { .species = SPECIES_ELECTIVIRE, .minimumLevel = 45 },
    { .species = SPECIES_MAGMORTAR, .minimumLevel = 45 },
    { .species = SPECIES_PORYGON_Z, .minimumLevel = 40 },
    { .species = SPECIES_RHYPERIOR, .minimumLevel = 45 },
    { .species = SPECIES_GIGALITH, .minimumLevel = 30 },
    { .species = SPECIES_CONKELDURR, .minimumLevel = 30 },
    { .species = SPECIES_ESCAVALIER, .minimumLevel = 35 },
    { .species = SPECIES_ACCELGOR, .minimumLevel = 35 },
    { .species = SPECIES_GOURGEIST, .minimumLevel = 40 },         // alias = GOURGEIST_AVERAGE
    { .species = SPECIES_GOURGEIST_SMALL, .minimumLevel = 40 },
    { .species = SPECIES_GOURGEIST_LARGE, .minimumLevel = 40 },
    { .species = SPECIES_GOURGEIST_SUPER, .minimumLevel = 40 },
    { .species = SPECIES_TREVENANT, .minimumLevel = 40 },
    { .species = SPECIES_SLURPUFF, .minimumLevel = 35 },
    { .species = SPECIES_AROMATISSE, .minimumLevel = 35 },

    // Stone/item evolutions with minimum levels
    { .species = SPECIES_RAICHU, .minimumLevel = 30 },
    { .species = SPECIES_RAICHU_ALOLA, .minimumLevel = 30 },
    { .species = SPECIES_CLEFABLE, .minimumLevel = 30 },
    { .species = SPECIES_WIGGLYTUFF, .minimumLevel = 30 },
    { .species = SPECIES_NINETALES, .minimumLevel = 30 },
    { .species = SPECIES_NINETALES_ALOLA, .minimumLevel = 30 },
    { .species = SPECIES_VILEPLUME, .minimumLevel = 30 },
    { .species = SPECIES_VICTREEBEL, .minimumLevel = 30 },
    { .species = SPECIES_POLIWRATH, .minimumLevel = 30 },
    { .species = SPECIES_NIDOKING, .minimumLevel = 30 },
    { .species = SPECIES_NIDOQUEEN, .minimumLevel = 30 },
    { .species = SPECIES_VAPOREON, .minimumLevel = 25 },
    { .species = SPECIES_JOLTEON, .minimumLevel = 25 },
    { .species = SPECIES_FLAREON, .minimumLevel = 25 },
    { .species = SPECIES_CLOYSTER, .minimumLevel = 30 },
    { .species = SPECIES_EXEGGUTOR, .minimumLevel = 35 },
    { .species = SPECIES_EXEGGUTOR_ALOLA, .minimumLevel = 35 },
    { .species = SPECIES_ARCANINE, .minimumLevel = 35 },
    { .species = SPECIES_ARCANINE_HISUI, .minimumLevel = 35 },
    { .species = SPECIES_SANDSLASH_ALOLA, .minimumLevel = 22 },
    { .species = SPECIES_STARMIE, .minimumLevel = 30 },
    { .species = SPECIES_BELLOSSOM, .minimumLevel = 30 },
    { .species = SPECIES_SUNFLORA, .minimumLevel = 25 },
    { .species = SPECIES_MISMAGIUS, .minimumLevel = 30 },
    { .species = SPECIES_HONCHKROW, .minimumLevel = 30 },
    { .species = SPECIES_DELCATTY, .minimumLevel = 25 },
    { .species = SPECIES_MUSHARNA, .minimumLevel = 25 },
    { .species = SPECIES_SIMISAGE, .minimumLevel = 25 },
    { .species = SPECIES_SIMISEAR, .minimumLevel = 25 },
    { .species = SPECIES_SIMIPOUR, .minimumLevel = 25 },
    { .species = SPECIES_CINCCINO, .minimumLevel = 28 },
    { .species = SPECIES_ROSERADE, .minimumLevel = 35 },
    { .species = SPECIES_LUDICOLO, .minimumLevel = 30 },
    { .species = SPECIES_SHIFTRY, .minimumLevel = 30 },
    { .species = SPECIES_HELIOLISK, .minimumLevel = 30 },
    { .species = SPECIES_BELLIBOLT, .minimumLevel = 30 },
    { .species = SPECIES_TOGEKISS, .minimumLevel = 40 },
    { .species = SPECIES_LEAFEON, .minimumLevel = 30 },
    { .species = SPECIES_GLACEON, .minimumLevel = 30 },
    { .species = SPECIES_ELECTRODE_HISUI, .minimumLevel = 30 },
    { .species = SPECIES_EELEKTROSS, .minimumLevel = 35 },
    { .species = SPECIES_FROSLASS, .minimumLevel = 35 },
    { .species = SPECIES_GALLADE, .minimumLevel = 35 },
    { .species = SPECIES_WHIMSICOTT, .minimumLevel = 30 },
    { .species = SPECIES_LILLIGANT, .minimumLevel = 30 },
    { .species = SPECIES_LILLIGANT_HISUI, .minimumLevel = 30 },
    { .species = SPECIES_DARMANITAN_GALAR_STANDARD, .minimumLevel = 35 },
    { .species = SPECIES_CRABOMINABLE, .minimumLevel = 35 },
    { .species = SPECIES_APPLETUN, .minimumLevel = 28 },
    { .species = SPECIES_FLAPPLE, .minimumLevel = 28 },
    { .species = SPECIES_DIPPLIN, .minimumLevel = 25 },
    { .species = SPECIES_CHANDELURE, .minimumLevel = 40 },
    { .species = SPECIES_KLEAVOR, .minimumLevel = 40 },
    { .species = SPECIES_AEGISLASH, .minimumLevel = 40 },          // alias = AEGISLASH_SHIELD
    { .species = SPECIES_FLORGES, .minimumLevel = 35 },            // alias = FLORGES_RED
    { .species = SPECIES_FLORGES_YELLOW, .minimumLevel = 35 },
    { .species = SPECIES_FLORGES_ORANGE, .minimumLevel = 35 },
    { .species = SPECIES_FLORGES_BLUE, .minimumLevel = 35 },
    { .species = SPECIES_FLORGES_WHITE, .minimumLevel = 35 },
    { .species = SPECIES_ARMAROUGE, .minimumLevel = 35 },
    { .species = SPECIES_CERULEDGE, .minimumLevel = 35 },
    { .species = SPECIES_CETITAN, .minimumLevel = 35 },
    { .species = SPECIES_ARCHALUDON, .minimumLevel = 45 },
    { .species = SPECIES_URSALUNA, .minimumLevel = 40 },
    { .species = SPECIES_SCOVILLAIN, .minimumLevel = 28 },
    { .species = SPECIES_SLOWBRO_GALAR, .minimumLevel = 30 },
    { .species = SPECIES_SLOWKING_GALAR, .minimumLevel = 30 },
    { .species = SPECIES_POLTEAGEIST_PHONY, .minimumLevel = 35 },
    { .species = SPECIES_POLTEAGEIST_ANTIQUE, .minimumLevel = 35 },
    { .species = SPECIES_SINISTCHA_UNREMARKABLE, .minimumLevel = 35 },
    { .species = SPECIES_SINISTCHA_MASTERPIECE, .minimumLevel = 35 },

    // Friendship evolutions with minimum levels
    { .species = SPECIES_BLISSEY, .minimumLevel = 35 },
    { .species = SPECIES_CROBAT, .minimumLevel = 30 },
    { .species = SPECIES_ESPEON, .minimumLevel = 30 },
    { .species = SPECIES_UMBREON, .minimumLevel = 30 },
    { .species = SPECIES_LUCARIO, .minimumLevel = 35 },
    { .species = SPECIES_SYLVEON, .minimumLevel = 30 },

    // Special case evolutions - level up knowing a specific move
    { .species = SPECIES_MR_MIME, .minimumLevel = 25 },       // Mime Jr. knows Mimic
    { .species = SPECIES_MR_MIME_GALAR, .minimumLevel = 25 }, // Mime Jr. (Galar) knows Mimic
    { .species = SPECIES_SUDOWOODO, .minimumLevel = 25 },      // Bonsly knows Mimic
    { .species = SPECIES_AMBIPOM, .minimumLevel = 25 },        // Aipom knows Double Hit
    { .species = SPECIES_TANGROWTH, .minimumLevel = 30 },      // Tangela knows Ancient Power
    { .species = SPECIES_LICKILICKY, .minimumLevel = 30 },     // Lickitung knows Rollout
    { .species = SPECIES_YANMEGA, .minimumLevel = 33 },        // Yanma knows Ancient Power
    { .species = SPECIES_MAMOSWINE, .minimumLevel = 30 },      // Piloswine knows Ancient Power
    { .species = SPECIES_TSAREENA, .minimumLevel = 28 },       // Steenee knows Stomp
    { .species = SPECIES_GRAPPLOCT, .minimumLevel = 25 },      // Clobbopus knows Taunt
    { .species = SPECIES_NAGANADEL, .minimumLevel = 50 },      // Poipole knows Dragon Pulse
    { .species = SPECIES_OVERQWIL, .minimumLevel = 35 },       // Hisuian Qwilfish knows Barb Barrage
    { .species = SPECIES_WYRDEER, .minimumLevel = 35 },        // Stantler uses Psyshield Bash 20 times
    { .species = SPECIES_FARIGIRAF, .minimumLevel = 32 },      // Girafarig knows Twin Beam
    { .species = SPECIES_DUDUNSPARCE_TWO_SEGMENT, .minimumLevel = 32 },   // Dunsparce knows Hyper Drill
    { .species = SPECIES_DUDUNSPARCE_THREE_SEGMENT, .minimumLevel = 32 }, // Dunsparce knows Hyper Drill (rare form)
    { .species = SPECIES_HYDRAPPLE, .minimumLevel = 45 },      // Dipplin knows Dragon Cheer

    // Special case evolutions - level up holding an item
    { .species = SPECIES_CHANSEY, .minimumLevel = 25 },        // Happiny holds Oval Stone (daytime)
    { .species = SPECIES_GLISCOR, .minimumLevel = 35 },        // Gligar holds Razor Fang (night)
    { .species = SPECIES_WEAVILE, .minimumLevel = 35 },        // Sneasel holds Razor Claw (night)
    { .species = SPECIES_SNEASLER, .minimumLevel = 35 },       // Hisuian Sneasel holds Razor Claw (day)

    // Special case evolutions - battle usage conditions
    { .species = SPECIES_ANNIHILAPE, .minimumLevel = 40 },     // Primeape uses Rage Fist 20 times
    { .species = SPECIES_BASCULEGION_M, .minimumLevel = 40 },  // Basculin takes 294 recoil damage
    { .species = SPECIES_BASCULEGION_F, .minimumLevel = 40 },

    // Special case evolutions - level up in specific location
    { .species = SPECIES_MAGNEZONE, .minimumLevel = 35 },      // Magneton at magnetic field
    { .species = SPECIES_PROBOPASS, .minimumLevel = 35 },      // Nosepass at magnetic field
    { .species = SPECIES_VIKAVOLT, .minimumLevel = 30 },       // Charjabug at magnetic field

    // Special case evolutions - battle end condition
    { .species = SPECIES_SIRFETCHD, .minimumLevel = 30 },      // Galarian Farfetch'd, 3 critical hits

    // Special case evolutions - script trigger
    { .species = SPECIES_RUNERIGUS, .minimumLevel = 35 },      // Galarian Yamask takes 49 damage in Dusty Bowl
    { .species = SPECIES_URSHIFU_SINGLE_STRIKE, .minimumLevel = 45 }, // Kubfu via Tower of Darkness
    { .species = SPECIES_URSHIFU_RAPID_STRIKE, .minimumLevel = 45 },  // Kubfu via Tower of Waters

    // Special case evolutions - spin (Milcery → Alcremie, all forms)
    { .species = SPECIES_ALCREMIE_STRAWBERRY_VANILLA_CREAM, .minimumLevel = 30 },
    { .species = SPECIES_ALCREMIE_STRAWBERRY_RUBY_CREAM, .minimumLevel = 30 },
    { .species = SPECIES_ALCREMIE_STRAWBERRY_MATCHA_CREAM, .minimumLevel = 30 },
    { .species = SPECIES_ALCREMIE_STRAWBERRY_MINT_CREAM, .minimumLevel = 30 },
    { .species = SPECIES_ALCREMIE_STRAWBERRY_LEMON_CREAM, .minimumLevel = 30 },
    { .species = SPECIES_ALCREMIE_STRAWBERRY_SALTED_CREAM, .minimumLevel = 30 },
    { .species = SPECIES_ALCREMIE_STRAWBERRY_RUBY_SWIRL, .minimumLevel = 30 },
    { .species = SPECIES_ALCREMIE_STRAWBERRY_CARAMEL_SWIRL, .minimumLevel = 30 },
    { .species = SPECIES_ALCREMIE_STRAWBERRY_RAINBOW_SWIRL, .minimumLevel = 30 },
    { .species = SPECIES_ALCREMIE_BERRY_VANILLA_CREAM, .minimumLevel = 30 },
    { .species = SPECIES_ALCREMIE_BERRY_RUBY_CREAM, .minimumLevel = 30 },
    { .species = SPECIES_ALCREMIE_BERRY_MATCHA_CREAM, .minimumLevel = 30 },
    { .species = SPECIES_ALCREMIE_BERRY_MINT_CREAM, .minimumLevel = 30 },
    { .species = SPECIES_ALCREMIE_BERRY_LEMON_CREAM, .minimumLevel = 30 },
    { .species = SPECIES_ALCREMIE_BERRY_SALTED_CREAM, .minimumLevel = 30 },
    { .species = SPECIES_ALCREMIE_BERRY_RUBY_SWIRL, .minimumLevel = 30 },
    { .species = SPECIES_ALCREMIE_BERRY_CARAMEL_SWIRL, .minimumLevel = 30 },
    { .species = SPECIES_ALCREMIE_BERRY_RAINBOW_SWIRL, .minimumLevel = 30 },
    { .species = SPECIES_ALCREMIE_LOVE_VANILLA_CREAM, .minimumLevel = 30 },
    { .species = SPECIES_ALCREMIE_LOVE_RUBY_CREAM, .minimumLevel = 30 },
    { .species = SPECIES_ALCREMIE_LOVE_MATCHA_CREAM, .minimumLevel = 30 },
    { .species = SPECIES_ALCREMIE_LOVE_MINT_CREAM, .minimumLevel = 30 },
    { .species = SPECIES_ALCREMIE_LOVE_LEMON_CREAM, .minimumLevel = 30 },
    { .species = SPECIES_ALCREMIE_LOVE_SALTED_CREAM, .minimumLevel = 30 },
    { .species = SPECIES_ALCREMIE_LOVE_RUBY_SWIRL, .minimumLevel = 30 },
    { .species = SPECIES_ALCREMIE_LOVE_CARAMEL_SWIRL, .minimumLevel = 30 },
    { .species = SPECIES_ALCREMIE_LOVE_RAINBOW_SWIRL, .minimumLevel = 30 },
    { .species = SPECIES_ALCREMIE_STAR_VANILLA_CREAM, .minimumLevel = 30 },
    { .species = SPECIES_ALCREMIE_STAR_RUBY_CREAM, .minimumLevel = 30 },
    { .species = SPECIES_ALCREMIE_STAR_MATCHA_CREAM, .minimumLevel = 30 },
    { .species = SPECIES_ALCREMIE_STAR_MINT_CREAM, .minimumLevel = 30 },
    { .species = SPECIES_ALCREMIE_STAR_LEMON_CREAM, .minimumLevel = 30 },
    { .species = SPECIES_ALCREMIE_STAR_SALTED_CREAM, .minimumLevel = 30 },
    { .species = SPECIES_ALCREMIE_STAR_RUBY_SWIRL, .minimumLevel = 30 },
    { .species = SPECIES_ALCREMIE_STAR_CARAMEL_SWIRL, .minimumLevel = 30 },
    { .species = SPECIES_ALCREMIE_STAR_RAINBOW_SWIRL, .minimumLevel = 30 },
    { .species = SPECIES_ALCREMIE_CLOVER_VANILLA_CREAM, .minimumLevel = 30 },
    { .species = SPECIES_ALCREMIE_CLOVER_RUBY_CREAM, .minimumLevel = 30 },
    { .species = SPECIES_ALCREMIE_CLOVER_MATCHA_CREAM, .minimumLevel = 30 },
    { .species = SPECIES_ALCREMIE_CLOVER_MINT_CREAM, .minimumLevel = 30 },
    { .species = SPECIES_ALCREMIE_CLOVER_LEMON_CREAM, .minimumLevel = 30 },
    { .species = SPECIES_ALCREMIE_CLOVER_SALTED_CREAM, .minimumLevel = 30 },
    { .species = SPECIES_ALCREMIE_CLOVER_RUBY_SWIRL, .minimumLevel = 30 },
    { .species = SPECIES_ALCREMIE_CLOVER_CARAMEL_SWIRL, .minimumLevel = 30 },
    { .species = SPECIES_ALCREMIE_CLOVER_RAINBOW_SWIRL, .minimumLevel = 30 },
    { .species = SPECIES_ALCREMIE_FLOWER_VANILLA_CREAM, .minimumLevel = 30 },
    { .species = SPECIES_ALCREMIE_FLOWER_RUBY_CREAM, .minimumLevel = 30 },
    { .species = SPECIES_ALCREMIE_FLOWER_MATCHA_CREAM, .minimumLevel = 30 },
    { .species = SPECIES_ALCREMIE_FLOWER_MINT_CREAM, .minimumLevel = 30 },
    { .species = SPECIES_ALCREMIE_FLOWER_LEMON_CREAM, .minimumLevel = 30 },
    { .species = SPECIES_ALCREMIE_FLOWER_SALTED_CREAM, .minimumLevel = 30 },
    { .species = SPECIES_ALCREMIE_FLOWER_RUBY_SWIRL, .minimumLevel = 30 },
    { .species = SPECIES_ALCREMIE_FLOWER_CARAMEL_SWIRL, .minimumLevel = 30 },
    { .species = SPECIES_ALCREMIE_FLOWER_RAINBOW_SWIRL, .minimumLevel = 30 },
    { .species = SPECIES_ALCREMIE_RIBBON_VANILLA_CREAM, .minimumLevel = 30 },
    { .species = SPECIES_ALCREMIE_RIBBON_RUBY_CREAM, .minimumLevel = 30 },
    { .species = SPECIES_ALCREMIE_RIBBON_MATCHA_CREAM, .minimumLevel = 30 },
    { .species = SPECIES_ALCREMIE_RIBBON_MINT_CREAM, .minimumLevel = 30 },
    { .species = SPECIES_ALCREMIE_RIBBON_LEMON_CREAM, .minimumLevel = 30 },
    { .species = SPECIES_ALCREMIE_RIBBON_SALTED_CREAM, .minimumLevel = 30 },
    { .species = SPECIES_ALCREMIE_RIBBON_RUBY_SWIRL, .minimumLevel = 30 },
    { .species = SPECIES_ALCREMIE_RIBBON_CARAMEL_SWIRL, .minimumLevel = 30 },
    { .species = SPECIES_ALCREMIE_RIBBON_RAINBOW_SWIRL, .minimumLevel = 30 },

    // Sentinel - must be last
    { .species = SPECIES_NONE, .minimumLevel = 0 },
};
