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
    { .species = SPECIES_GOURGEIST, .minimumLevel = 40 },
    { .species = SPECIES_TREVENANT, .minimumLevel = 40 },
    { .species = SPECIES_SLURPUFF, .minimumLevel = 35 },
    { .species = SPECIES_AROMATISSE, .minimumLevel = 35 },

    // Stone evolutions with minimum levels
    { .species = SPECIES_RAICHU, .minimumLevel = 25 },
    { .species = SPECIES_CLEFABLE, .minimumLevel = 30 },
    { .species = SPECIES_WIGGLYTUFF, .minimumLevel = 30 },
    { .species = SPECIES_NINETALES, .minimumLevel = 30 },
    { .species = SPECIES_VILEPLUME, .minimumLevel = 30 },
    { .species = SPECIES_VICTREEBEL, .minimumLevel = 30 },
    { .species = SPECIES_POLIWRATH, .minimumLevel = 30 },
    { .species = SPECIES_ARCANINE, .minimumLevel = 35 },
    { .species = SPECIES_EXEGGUTOR, .minimumLevel = 35 },
    { .species = SPECIES_STARMIE, .minimumLevel = 30 },
    { .species = SPECIES_BELLOSSOM, .minimumLevel = 30 },
    { .species = SPECIES_SUNFLORA, .minimumLevel = 25 },
    { .species = SPECIES_DELCATTY, .minimumLevel = 25 },
    { .species = SPECIES_ROSERADE, .minimumLevel = 35 },
    { .species = SPECIES_TOGEKISS, .minimumLevel = 40 },
    { .species = SPECIES_LEAFEON, .minimumLevel = 30 },
    { .species = SPECIES_GLACEON, .minimumLevel = 30 },
    { .species = SPECIES_FROSLASS, .minimumLevel = 35 },
    { .species = SPECIES_WHIMSICOTT, .minimumLevel = 30 },
    { .species = SPECIES_LILLIGANT, .minimumLevel = 30 },
    { .species = SPECIES_CHANDELURE, .minimumLevel = 40 },
    { .species = SPECIES_AEGISLASH, .minimumLevel = 40 },
    { .species = SPECIES_FLORGES, .minimumLevel = 30 },

    // Friendship evolutions with minimum levels
    { .species = SPECIES_BLISSEY, .minimumLevel = 35 },
    { .species = SPECIES_CROBAT, .minimumLevel = 30 },
    { .species = SPECIES_ESPEON, .minimumLevel = 30 },
    { .species = SPECIES_UMBREON, .minimumLevel = 30 },
    { .species = SPECIES_LUCARIO, .minimumLevel = 35 },
    { .species = SPECIES_SYLVEON, .minimumLevel = 30 },

    // Special case evolutions
    { .species = SPECIES_MR_MIME, .minimumLevel = 25 },
    { .species = SPECIES_GALLADE, .minimumLevel = 35 },

    // Sentinel - must be last
    { .species = SPECIES_NONE, .minimumLevel = 0 },
};
