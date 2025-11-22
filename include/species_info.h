#ifndef GUARD_SPECIES_INFO_H
#define GUARD_SPECIES_INFO_H

#include "constants/abilities.h"
#include "constants/cries.h"
#include "constants/egg_ids.h"

struct EvolutionParam
{
    u16 condition;
    u16 arg1;
    u16 arg2;
    u16 arg3;
};

struct Evolution
{
    u16 method;
    u16 param;
    u16 targetSpecies;
    const struct EvolutionParam *params;
};

#define USE_FUNC(name) __attribute__((deprecated("use " name " instead")))

struct SpeciesInfo /*0xC4*/
{
    u8 baseHP USE_FUNC("GetSpeciesBaseHP");
    u8 baseAttack USE_FUNC("GetSpeciesBaseAttack");
    u8 baseDefense USE_FUNC("GetSpeciesBaseDefense");
    u8 baseSpeed USE_FUNC("GetSpeciesBaseSpeed");
    u8 baseSpAttack USE_FUNC("GetSpeciesBaseSpAttack");
    u8 baseSpDefense USE_FUNC("GetSpeciesBaseSpDefense");
    enum Type types[2] USE_FUNC("GetSpeciesType or IsSpeciesOfType");
    u8 catchRate USE_FUNC("GetSpeciesCatchRate");
    u8 forceTeraType;
    u16 expYield; // expYield was changed from u8 to u16 for the new Exp System.
    u16 evYield_HP:2;
    u16 evYield_Attack:2;
    u16 evYield_Defense:2;
    u16 evYield_Speed:2;
    u16 evYield_SpAttack:2;
    u16 evYield_SpDefense:2;
    u16 padding2:4;
    u16 itemCommon;
    u16 itemRare;
    u8 genderRatio;
    u8 eggCycles;
    u8 friendship;
    u8 growthRate;
    u8 eggGroups[2];
    enum Ability abilities[NUM_ABILITY_SLOTS]; // 3 abilities, no longer u8 because we have over 255 abilities now.
    u8 safariZoneFleeRate;

    // Pokédex data
    u8 categoryName[13];
    u8 speciesName[POKEMON_NAME_LENGTH + 1];
    enum PokemonCry cryId:16;
    enum NationalDexOrder natDexNum:16;
    u16 height; //in decimeters
    u16 weight; //in hectograms
    u16 pokemonScale;
    u16 pokemonOffset;
    u16 trainerScale;
    u16 trainerOffset;
    const u8 *description;
    enum BodyColor bodyColor:7;
    // Graphical Data
    u8 noFlip:1;
    u8 frontAnimDelay;
    u8 frontAnimId;
    u8 backAnimId;
    const union AnimCmd *const *frontAnimFrames;
    const u32 *frontPic;
    const u32 *backPic;
    const u16 *palette;
    const u16 *shinyPalette;
    const u8 *iconSprite;
#if P_GENDER_DIFFERENCES
    const u32 *frontPicFemale;
    const u32 *backPicFemale;
    const u16 *paletteFemale;
    const u16 *shinyPaletteFemale;
    const u8 *iconSpriteFemale;
#endif //P_GENDER_DIFFERENCES
#if P_FOOTPRINTS
    const u8 *footprint;
#endif
    // All Pokémon pics are 64x64, but this data table defines where in this 64x64 frame the sprite's non-transparent pixels actually are.
    u8 frontPicSize; // The dimensions of this drawn pixel area.
    u8 frontPicYOffset; // The number of pixels between the drawn pixel area and the bottom edge.
    u8 backPicSize; // The dimensions of this drawn pixel area.
    u8 backPicYOffset; // The number of pixels between the drawn pixel area and the bottom edge.
#if P_GENDER_DIFFERENCES
    u8 frontPicSizeFemale; // The dimensions of this drawn pixel area.
    u8 backPicSizeFemale; // The dimensions of this drawn pixel area.
#endif //P_GENDER_DIFFERENCES
    u8 iconPalIndex:3;
#if P_GENDER_DIFFERENCES
    u8 iconPalIndexFemale:3;
#else
    u8 paddingF:3;
#endif //P_GENDER_DIFFERENCES
    u8 pokemonJumpType:2; // According to the clerk, the Pokémon allowed in Pokémon Jump are all <= 28 inches/71 cm, and do not only swim, burrow, or fly.
    u8 enemyMonElevation; // This determines how much higher above the usual position the enemy Pokémon is during battle. Species that float or fly have nonzero values.
    // Flags
    u32 isRestrictedLegendary:1;
    u32 isSubLegendary:1;
    u32 isMythical:1;
    u32 isUltraBeast:1;
    u32 isParadox:1;
    u32 isTotem:1;
    u32 isMegaEvolution:1;
    u32 isPrimalReversion:1;
    u32 isUltraBurst:1;
    u32 isGigantamax:1;
    u32 isTeraForm:1;
    u32 isAlolanForm:1;
    u32 isGalarianForm:1;
    u32 isHisuianForm:1;
    u32 isPaldeanForm:1;
    u32 cannotBeTraded:1;
    u32 perfectIVCount:3;   // This species will always generate with the specified amount of perfect IVs.
    u32 dexForceRequired:1; // This species will be taken into account for Pokédex ratings even if they have the "isMythical" flag set.
    u32 tmIlliterate:1;     // This species will be unable to learn the universal moves.
    u32 isFrontierBanned:1; // This species is not allowed to participate in Battle Frontier facilities.
    u32 padding4:10;
    // Shadow settings
    s8 enemyShadowXOffset; // This determines the X-offset for an enemy Pokémon's shadow during battle; negative values point left, positive values point right.
    s8 enemyShadowYOffset; // This determines the Y-offset for an enemy Pokémon's shadow during battle; negative values point up, positive values point down.
    u16 enemyShadowSize:3; // This determines the size of the shadow sprite used for an enemy Pokémon's front sprite during battle.
    u16 suppressEnemyShadow:1; // If set to true, then a shadow will not be drawn beneath an enemy Pokémon's front sprite during battle.
    enum EggIds eggId:12;
    // Move Data
    const struct LevelUpMove *levelUpLearnset;
    const u16 *teachableLearnset;
    const u16 *eggMoveLearnset;
    const struct Evolution *evolutions;
    const u16 *formSpeciesIdTable;
    const struct FormChange *formChangeTable;
#if OW_POKEMON_OBJECT_EVENTS
    struct ObjectEventGraphicsInfo overworldData;
#if P_GENDER_DIFFERENCES
    struct ObjectEventGraphicsInfo overworldDataFemale;
#endif //P_GENDER_DIFFERENCES
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const void* overworldPalette;
    const void* overworldShinyPalette;
#if P_GENDER_DIFFERENCES
    const void* overworldPaletteFemale;
    const void* overworldShinyPaletteFemale;
#endif //P_GENDER_DIFFERENCES
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS
};
#undef USE_FUNC

extern const struct SpeciesInfo gSpeciesInfo[];

static inline bool32 IsSpeciesEnabled(u16 species)
{
    // This function should not use the GetSpeciesBaseHP function, as the included sanitation will result in an infinite loop
    return GET_DEPRECATED(u32, gSpeciesInfo[species].baseHP) > 0 || species == SPECIES_EGG;
}

static inline u16 SanitizeSpeciesId(u16 species)
{
    assertf(species <= NUM_SPECIES && (species == SPECIES_NONE || IsSpeciesEnabled(species)), "invalid species: %d", species)
    {
        return SPECIES_NONE;
    }

    return species;
}

static inline u32 GetSpeciesBaseHP(u16 species)
{
    return GET_DEPRECATED(u32, gSpeciesInfo[SanitizeSpeciesId(species)].baseHP);
}

static inline u32 GetSpeciesBaseAttack(u16 species)
{
    return GET_DEPRECATED(u32, gSpeciesInfo[SanitizeSpeciesId(species)].baseAttack);
}

static inline u32 GetSpeciesBaseDefense(u16 species)
{
    return GET_DEPRECATED(u32, gSpeciesInfo[SanitizeSpeciesId(species)].baseDefense);
}

static inline u32 GetSpeciesBaseSpAttack(u16 species)
{
    return GET_DEPRECATED(u32, gSpeciesInfo[SanitizeSpeciesId(species)].baseSpAttack);
}

static inline u32 GetSpeciesBaseSpDefense(u16 species)
{
    return GET_DEPRECATED(u32, gSpeciesInfo[SanitizeSpeciesId(species)].baseSpDefense);
}

static inline u32 GetSpeciesBaseSpeed(u16 species)
{
    return GET_DEPRECATED(u32, gSpeciesInfo[SanitizeSpeciesId(species)].baseSpeed);
}

static inline u32 GetSpeciesBaseStat(u16 species, u32 statIndex)
{
    switch (statIndex)
    {
    case STAT_HP:
        return GetSpeciesBaseHP(species);
    case STAT_ATK:
        return GetSpeciesBaseAttack(species);
    case STAT_DEF:
        return GetSpeciesBaseDefense(species);
    case STAT_SPEED:
        return GetSpeciesBaseSpeed(species);
    case STAT_SPATK:
        return GetSpeciesBaseSpAttack(species);
    case STAT_SPDEF:
        return GetSpeciesBaseSpDefense(species);
    }
    return 0;
}

static inline enum Type GetSpeciesType(u16 species, u8 slot)
{
    return GET_DEPRECATED(u32, gSpeciesInfo[SanitizeSpeciesId(species)].types[slot]);
}

static inline u32 GetSpeciesCatchRate(u16 species)
{
    return GET_DEPRECATED(u32, gSpeciesInfo[SanitizeSpeciesId(species)].catchRate);
}

#endif // GUARD_SPECIES_INFO_H
