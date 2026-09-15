#include "global.h"
#include "mf_rules.h"
#include "mf_types.h"
#include "pokemon.h"
#include "battle_main.h"

#include "data/mf_type_effectiveness_improved.h"

// Pre-Gen-6 typings for species that gained Fairy via P_UPDATED_TYPES >= GEN_6.
// Spec: ME GetTypeBySpecies when tx_Mode_Fairy_Types == 0 (types_old). Cotonee /
// Whimsicott are the same official Gen-6 retype class and are included for
// TESTING builds that keep Gen 5 families. Pure Fairy introductions (Sylveon,
// Alolan Ninetales, megas that were always Fairy) are intentionally left alone.

struct MfTypePair
{
    u16 species;
    u8 types[2];
};

static const struct MfTypePair sFairyTypeFallbacks[] =
{
    { SPECIES_CLEFFA,     { TYPE_NORMAL,  TYPE_NORMAL  } },
    { SPECIES_CLEFAIRY,   { TYPE_NORMAL,  TYPE_NORMAL  } },
    { SPECIES_CLEFABLE,   { TYPE_NORMAL,  TYPE_NORMAL  } },
    { SPECIES_IGGLYBUFF,  { TYPE_NORMAL,  TYPE_NORMAL  } },
    { SPECIES_JIGGLYPUFF, { TYPE_NORMAL,  TYPE_NORMAL  } },
    { SPECIES_WIGGLYTUFF, { TYPE_NORMAL,  TYPE_NORMAL  } },
    { SPECIES_TOGEPI,     { TYPE_NORMAL,  TYPE_NORMAL  } },
    { SPECIES_TOGETIC,    { TYPE_NORMAL,  TYPE_FLYING  } },
    { SPECIES_TOGEKISS,   { TYPE_NORMAL,  TYPE_FLYING  } },
    { SPECIES_AZURILL,    { TYPE_NORMAL,  TYPE_NORMAL  } },
    { SPECIES_MARILL,     { TYPE_WATER,   TYPE_WATER   } },
    { SPECIES_AZUMARILL,  { TYPE_WATER,   TYPE_WATER   } },
    { SPECIES_SNUBBULL,   { TYPE_NORMAL,  TYPE_NORMAL  } },
    { SPECIES_GRANBULL,   { TYPE_NORMAL,  TYPE_NORMAL  } },
    { SPECIES_MIME_JR,    { TYPE_PSYCHIC, TYPE_PSYCHIC } },
    { SPECIES_MR_MIME,    { TYPE_PSYCHIC, TYPE_PSYCHIC } },
    { SPECIES_RALTS,      { TYPE_PSYCHIC, TYPE_PSYCHIC } },
    { SPECIES_KIRLIA,     { TYPE_PSYCHIC, TYPE_PSYCHIC } },
    { SPECIES_GARDEVOIR,  { TYPE_PSYCHIC, TYPE_PSYCHIC } },
    { SPECIES_MAWILE,     { TYPE_STEEL,   TYPE_STEEL   } },
    { SPECIES_COTTONEE,   { TYPE_GRASS,   TYPE_GRASS   } },
    { SPECIES_WHIMSICOTT, { TYPE_GRASS,   TYPE_GRASS   } },
};

// ME modern typings (tx_Mode_Modern_Types). Expansion keeps vanilla / Fairy-on
// types in gSpeciesInfo; when modernTypes is on we overlay ME's balance retypes.
// Snubbull/Granbull: ME uses types_new (Fairy/Normal) when modern is on, else
// Fairy/Fairy from species_info when Fairy is on.
static const struct MfTypePair sModernTypeOverlays[] =
{
    { SPECIES_ARBOK,      { TYPE_POISON,   TYPE_DARK     } },
    { SPECIES_PARASECT,   { TYPE_BUG,      TYPE_GHOST    } },
    { SPECIES_GOLDUCK,    { TYPE_WATER,    TYPE_PSYCHIC  } },
    { SPECIES_KINGLER,    { TYPE_WATER,    TYPE_STEEL    } },
    { SPECIES_MEGANIUM,   { TYPE_GRASS,    TYPE_FAIRY    } },
    { SPECIES_TYPHLOSION, { TYPE_FIRE,     TYPE_GROUND   } },
    { SPECIES_FERALIGATR, { TYPE_WATER,    TYPE_DRAGON   } },
    { SPECIES_NOCTOWL,    { TYPE_PSYCHIC,  TYPE_FLYING   } },
    { SPECIES_SUNFLORA,   { TYPE_GRASS,    TYPE_FIRE     } },
    { SPECIES_STANTLER,   { TYPE_NORMAL,   TYPE_PSYCHIC  } },
    { SPECIES_SNUBBULL,   { TYPE_FAIRY,    TYPE_NORMAL   } },
    { SPECIES_GRANBULL,   { TYPE_FAIRY,    TYPE_NORMAL   } },
    { SPECIES_GROVYLE,    { TYPE_GRASS,    TYPE_DRAGON   } },
    { SPECIES_SCEPTILE,   { TYPE_GRASS,    TYPE_DRAGON   } },
    { SPECIES_MASQUERAIN, { TYPE_BUG,      TYPE_WATER    } },
    { SPECIES_DELCATTY,   { TYPE_NORMAL,   TYPE_FAIRY    } },
    { SPECIES_GULPIN,     { TYPE_POISON,   TYPE_NORMAL   } },
    { SPECIES_SWALOT,     { TYPE_POISON,   TYPE_NORMAL   } },
    { SPECIES_LUVDISC,    { TYPE_WATER,    TYPE_FAIRY    } },
    { SPECIES_HUNTAIL,    { TYPE_WATER,    TYPE_DARK     } },
    { SPECIES_GOREBYSS,   { TYPE_WATER,    TYPE_PSYCHIC  } },
    { SPECIES_ELECTIVIRE, { TYPE_ELECTRIC, TYPE_FIGHTING } },
    { SPECIES_YANMEGA,    { TYPE_BUG,      TYPE_DRAGON   } },
};

static const u8 *FindTypePair(const struct MfTypePair *table, u32 count, enum Species species)
{
    u32 i;

    for (i = 0; i < count; i++)
    {
        if (table[i].species == species)
            return table[i].types;
    }
    return NULL;
}

enum Type MfGetSpeciesType(enum Species species, u8 slot)
{
    enum Species sanitized = SanitizeSpeciesId(species);
    const u8 *types;

    if (slot > 1)
        slot = 1;

    // Fairy-off first (ME order): official Gen-6 Fairy retypes revert even when
    // modernTypes would otherwise assign Fairy (e.g. Meganium is modern-only Fairy).
    if (!MfRules_HasFairyTypes())
    {
        types = FindTypePair(sFairyTypeFallbacks, ARRAY_COUNT(sFairyTypeFallbacks), sanitized);
        if (types != NULL)
            return types[slot];
    }

    if (MfRules_HasModernTypes())
    {
        types = FindTypePair(sModernTypeOverlays, ARRAY_COUNT(sModernTypeOverlays), sanitized);
        if (types != NULL)
            return types[slot];
    }

    return gSpeciesInfo[sanitized].types[slot];
}

const uq4_12_t (*MfGetTypeEffectivenessTable(void))[NUMBER_OF_MON_TYPES]
{
    if (MfRules_HasTypeEffectiveness())
        return sMfTypeEffectivenessImproved;
    return gTypeEffectivenessTable;
}
