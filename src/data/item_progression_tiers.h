// ============================================================================
// HELD ITEM PROGRESSION TIERS
// ============================================================================
//
// Tier classification for held items. Used by the level-scaling system to
// decide whether a trainer-defined held item may be carried by a scaled-down
// Pokémon at a given level. Mirrors src/data/move_progression_tiers.h.
//
// Tiers:
//   ITEM_TIER_DEFAULT  - No gate (always allowed). Items omitted below default to this.
//   ITEM_TIER_MID      - Available at >= B_SCALING_TIER_MID_MIN_LEVEL
//   ITEM_TIER_LATE     - Available at >= B_SCALING_TIER_LATE_MIN_LEVEL
//   ITEM_TIER_ENDGAME  - Available at >= B_SCALING_TIER_ENDGAME_MIN_LEVEL
//
// When .scaleItems is opted in and the held item's tier is above what the
// scaled level allows, the item is stripped (set to ITEM_NONE). Anything not
// listed here is ITEM_TIER_DEFAULT and is never stripped — basic berries,
// type-boost held items, and other low-impact items intentionally fall here.

#include "constants/items.h"

const u8 gItemProgressionTier[ITEMS_COUNT] =
{
    // Recovery berries
    [ITEM_ORAN_BERRY]        = ITEM_TIER_DEFAULT,
    [ITEM_CHERI_BERRY]       = ITEM_TIER_DEFAULT,
    [ITEM_CHESTO_BERRY]      = ITEM_TIER_DEFAULT,
    [ITEM_PECHA_BERRY]       = ITEM_TIER_DEFAULT,
    [ITEM_RAWST_BERRY]       = ITEM_TIER_DEFAULT,
    [ITEM_ASPEAR_BERRY]      = ITEM_TIER_DEFAULT,
    [ITEM_PERSIM_BERRY]      = ITEM_TIER_DEFAULT,
    [ITEM_LEPPA_BERRY]       = ITEM_TIER_DEFAULT,
    [ITEM_SITRUS_BERRY]      = ITEM_TIER_MID,
    [ITEM_LUM_BERRY]         = ITEM_TIER_MID,
    [ITEM_FIGY_BERRY]        = ITEM_TIER_MID,
    [ITEM_WIKI_BERRY]        = ITEM_TIER_MID,
    [ITEM_MAGO_BERRY]        = ITEM_TIER_MID,
    [ITEM_AGUAV_BERRY]       = ITEM_TIER_MID,
    [ITEM_IAPAPA_BERRY]      = ITEM_TIER_MID,

    // --- Pinch stat berries ---
    [ITEM_LIECHI_BERRY]      = ITEM_TIER_MID,
    [ITEM_GANLON_BERRY]      = ITEM_TIER_MID,
    [ITEM_SALAC_BERRY]       = ITEM_TIER_MID,
    [ITEM_PETAYA_BERRY]      = ITEM_TIER_MID,
    [ITEM_APICOT_BERRY]      = ITEM_TIER_MID,
    [ITEM_LANSAT_BERRY]      = ITEM_TIER_MID,
    [ITEM_MICLE_BERRY]       = ITEM_TIER_MID,
    [ITEM_KEE_BERRY]         = ITEM_TIER_MID,
    [ITEM_MARANGA_BERRY]     = ITEM_TIER_MID,
    [ITEM_STARF_BERRY]       = ITEM_TIER_MID,
    [ITEM_CUSTAP_BERRY]      = ITEM_TIER_MID,

    // --- Type resist berries ---
    [ITEM_CHILAN_BERRY]      = ITEM_TIER_MID,
    [ITEM_OCCA_BERRY]        = ITEM_TIER_MID,
    [ITEM_PASSHO_BERRY]      = ITEM_TIER_MID,
    [ITEM_WACAN_BERRY]       = ITEM_TIER_MID,
    [ITEM_RINDO_BERRY]       = ITEM_TIER_MID,
    [ITEM_YACHE_BERRY]       = ITEM_TIER_MID,
    [ITEM_CHOPLE_BERRY]      = ITEM_TIER_MID,
    [ITEM_KEBIA_BERRY]       = ITEM_TIER_MID,
    [ITEM_SHUCA_BERRY]       = ITEM_TIER_MID,
    [ITEM_COBA_BERRY]        = ITEM_TIER_MID,
    [ITEM_PAYAPA_BERRY]      = ITEM_TIER_MID,
    [ITEM_TANGA_BERRY]       = ITEM_TIER_MID,
    [ITEM_CHARTI_BERRY]      = ITEM_TIER_MID,
    [ITEM_KASIB_BERRY]       = ITEM_TIER_MID,
    [ITEM_HABAN_BERRY]       = ITEM_TIER_MID,
    [ITEM_COLBUR_BERRY]      = ITEM_TIER_MID,
    [ITEM_BABIRI_BERRY]      = ITEM_TIER_MID,
    [ITEM_ROSELI_BERRY]      = ITEM_TIER_MID,

    // Other berries
    [ITEM_ENIGMA_BERRY]      = ITEM_TIER_MID,
    [ITEM_JABOCA_BERRY]      = ITEM_TIER_MID,
    [ITEM_ROWAP_BERRY]       = ITEM_TIER_MID,

    // Type boosting items
    [ITEM_SILK_SCARF]        = ITEM_TIER_DEFAULT,
    [ITEM_CHARCOAL]          = ITEM_TIER_DEFAULT,
    [ITEM_MYSTIC_WATER]      = ITEM_TIER_DEFAULT,
    [ITEM_MAGNET]            = ITEM_TIER_DEFAULT,
    [ITEM_MIRACLE_SEED]      = ITEM_TIER_DEFAULT,
    [ITEM_NEVER_MELT_ICE]    = ITEM_TIER_DEFAULT,
    [ITEM_BLACK_BELT]        = ITEM_TIER_DEFAULT,
    [ITEM_POISON_BARB]       = ITEM_TIER_DEFAULT,
    [ITEM_SOFT_SAND]         = ITEM_TIER_DEFAULT,
    [ITEM_SHARP_BEAK]        = ITEM_TIER_DEFAULT,
    [ITEM_TWISTED_SPOON]     = ITEM_TIER_DEFAULT,
    [ITEM_SILVER_POWDER]     = ITEM_TIER_DEFAULT,
    [ITEM_HARD_STONE]        = ITEM_TIER_DEFAULT,
    [ITEM_SPELL_TAG]         = ITEM_TIER_DEFAULT,
    [ITEM_DRAGON_FANG]       = ITEM_TIER_DEFAULT,
    [ITEM_BLACK_GLASSES]     = ITEM_TIER_DEFAULT,
    [ITEM_METAL_COAT]        = ITEM_TIER_DEFAULT,

    // Gems
    [ITEM_NORMAL_GEM]        = ITEM_TIER_MID,
    [ITEM_FIRE_GEM]          = ITEM_TIER_MID,
    [ITEM_WATER_GEM]         = ITEM_TIER_MID,
    [ITEM_ELECTRIC_GEM]      = ITEM_TIER_MID,
    [ITEM_GRASS_GEM]         = ITEM_TIER_MID,
    [ITEM_ICE_GEM]           = ITEM_TIER_MID,
    [ITEM_FIGHTING_GEM]      = ITEM_TIER_MID,
    [ITEM_POISON_GEM]        = ITEM_TIER_MID,
    [ITEM_GROUND_GEM]        = ITEM_TIER_MID,
    [ITEM_FLYING_GEM]        = ITEM_TIER_MID,
    [ITEM_PSYCHIC_GEM]       = ITEM_TIER_MID,
    [ITEM_BUG_GEM]           = ITEM_TIER_MID,
    [ITEM_ROCK_GEM]          = ITEM_TIER_MID,
    [ITEM_GHOST_GEM]         = ITEM_TIER_MID,
    [ITEM_DRAGON_GEM]        = ITEM_TIER_MID,
    [ITEM_DARK_GEM]          = ITEM_TIER_MID,
    [ITEM_STEEL_GEM]         = ITEM_TIER_MID,
    [ITEM_FAIRY_GEM]         = ITEM_TIER_MID,

    // Recovery items
    [ITEM_BIG_ROOT]          = ITEM_TIER_MID,
    [ITEM_LEFTOVERS]         = ITEM_TIER_LATE,
    [ITEM_SHELL_BELL]        = ITEM_TIER_MID,
    [ITEM_BLACK_SLUDGE]      = ITEM_TIER_MID,

    // Defensive items
    [ITEM_SAFETY_GOGGLES]    = ITEM_TIER_MID,
    [ITEM_PROTECTIVE_PADS]   = ITEM_TIER_MID,
    [ITEM_SHED_SHELL]        = ITEM_TIER_MID,
    [ITEM_MENTAL_HERB]       = ITEM_TIER_MID,
    [ITEM_BRIGHT_POWDER]     = ITEM_TIER_MID,
    [ITEM_FOCUS_BAND]        = ITEM_TIER_MID,
    [ITEM_ROCKY_HELMET]      = ITEM_TIER_LATE,
    [ITEM_AIR_BALLOON]       = ITEM_TIER_MID,
    [ITEM_FOCUS_SASH]        = ITEM_TIER_MID,
    [ITEM_HEAVY_DUTY_BOOTS]  = ITEM_TIER_MID,
    [ITEM_LIGHT_CLAY]        = ITEM_TIER_MID,
    [ITEM_BINDING_BAND]      = ITEM_TIER_MID,
    [ITEM_GRIP_CLAW]         = ITEM_TIER_MID,
    [ITEM_EJECT_BUTTON]      = ITEM_TIER_MID,
    [ITEM_EJECT_PACK]        = ITEM_TIER_MID,
    [ITEM_ASSAULT_VEST]      = ITEM_TIER_LATE,
    [ITEM_EVIOLITE]          = ITEM_TIER_MID,

    // Offensive items
    [ITEM_FLAME_ORB]         = ITEM_TIER_LATE,
    [ITEM_TOXIC_ORB]         = ITEM_TIER_LATE,
    [ITEM_QUICK_CLAW]        = ITEM_TIER_MID,
    [ITEM_KINGS_ROCK]        = ITEM_TIER_MID,
    [ITEM_SCOPE_LENS]        = ITEM_TIER_MID,
    [ITEM_MUSCLE_BAND]       = ITEM_TIER_MID,
    [ITEM_WISE_GLASSES]      = ITEM_TIER_MID,
    [ITEM_EXPERT_BELT]       = ITEM_TIER_MID,
    [ITEM_POWER_HERB]        = ITEM_TIER_MID,
    [ITEM_WIDE_LENS]         = ITEM_TIER_MID,
    [ITEM_ZOOM_LENS]         = ITEM_TIER_MID,
    [ITEM_WHITE_HERB]        = ITEM_TIER_LATE,
    [ITEM_CHOICE_BAND]       = ITEM_TIER_LATE,
    [ITEM_CHOICE_SPECS]      = ITEM_TIER_LATE,
    [ITEM_CHOICE_SCARF]      = ITEM_TIER_LATE,
    [ITEM_LIFE_ORB]          = ITEM_TIER_LATE,
    [ITEM_WEAKNESS_POLICY]   = ITEM_TIER_LATE,

    

    // Misc items
    [ITEM_ABSORB_BULB]       = ITEM_TIER_MID,
    [ITEM_CELL_BATTERY]      = ITEM_TIER_MID,
    [ITEM_SNOWBALL]          = ITEM_TIER_MID,
    [ITEM_THROAT_SPRAY]      = ITEM_TIER_MID,
    [ITEM_BLUNDER_POLICY]    = ITEM_TIER_MID,
    [ITEM_LUMINOUS_MOSS]     = ITEM_TIER_MID,
    [ITEM_METRONOME]         = ITEM_TIER_MID,
    [ITEM_LAGGING_TAIL]      = ITEM_TIER_MID,
    [ITEM_RED_CARD]          = ITEM_TIER_MID,
    [ITEM_IRON_BALL]         = ITEM_TIER_MID,
    [ITEM_ROOM_SERVICE]      = ITEM_TIER_MID,
    [ITEM_ADRENALINE_ORB]    = ITEM_TIER_MID,
    [ITEM_STICKY_BARB]       = ITEM_TIER_MID,
    [ITEM_RING_TARGET]       = ITEM_TIER_MID,

    // Weather / terrain related
    [ITEM_DAMP_ROCK]         = ITEM_TIER_MID,
    [ITEM_HEAT_ROCK]         = ITEM_TIER_MID,
    [ITEM_SMOOTH_ROCK]       = ITEM_TIER_MID,
    [ITEM_ICY_ROCK]          = ITEM_TIER_MID,
    [ITEM_TERRAIN_EXTENDER]  = ITEM_TIER_MID,
    [ITEM_UTILITY_UMBRELLA]  = ITEM_TIER_MID,
    [ITEM_ELECTRIC_SEED]     = ITEM_TIER_MID,
    [ITEM_PSYCHIC_SEED]      = ITEM_TIER_MID,
    [ITEM_MISTY_SEED]        = ITEM_TIER_MID,
    [ITEM_GRASSY_SEED]       = ITEM_TIER_MID,


};
