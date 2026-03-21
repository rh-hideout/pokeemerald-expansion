#ifndef GUARD_SPECIES_INFO_H
#define GUARD_SPECIES_INFO_H

#include "constants/abilities.h"
#include "constants/cries.h"
#include "constants/egg_ids.h"
#include "constants/event_objects.h"
#include "constants/pokemon_animation.h"

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
    enum Species targetSpecies;
    const struct EvolutionParam *params;
};

struct SpeciesInfo /*0xC4*/
{
    u8 baseHP;
    u8 baseAttack;
    u8 baseDefense;
    u8 baseSpeed;
    u8 baseSpAttack;
    u8 baseSpDefense;
    enum Type types[2];
    u8 catchRate;
    u8 forceTeraType;
    u16 expYield; // expYield was changed from u8 to u16 for the new Exp System.
    u16 evYield_HP:2;
    u16 evYield_Attack:2;
    u16 evYield_Defense:2;
    u16 evYield_Speed:2;
    u16 evYield_SpAttack:2;
    u16 evYield_SpDefense:2;
    u16 padding2:4;
    enum Item itemCommon;
    enum Item itemRare;
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
    u32 teachingType:1; // Not used in the ROM but used in compilation (check constants/teaching_types.h for explanations)
    u32 isFrontierBanned:1; // This species is not allowed to participate in Battle Frontier facilities.
    u32 isSkyBattleBanned:1;
    u32 isTelekinesisBanned:1;
    u32 padding4:8;
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
    const enum Species *formSpeciesIdTable;
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

extern const struct SpeciesInfo gSpeciesInfo[];

static inline bool32 IsSpeciesEnabled(enum Species species)
{
    // This function should not use the GetSpeciesBaseHP function, as the included sanitation will result in an infinite loop
    return gSpeciesInfo[species].baseHP > 0 || species == SPECIES_EGG;
}

static inline enum Species SanitizeSpeciesId(enum Species species)
{
    assertf(species <= NUM_SPECIES && (species == SPECIES_NONE || IsSpeciesEnabled(species)), "invalid species: %d", species)
    {
        return SPECIES_NONE;
    }

    return species;
}

static inline u32 GetSpeciesBaseHP(enum Species species)
{
    return gSpeciesInfo[SanitizeSpeciesId(species)].baseHP;
}

static inline u32 GetSpeciesBaseAttack(enum Species species)
{
    return gSpeciesInfo[SanitizeSpeciesId(species)].baseAttack;
}

static inline u32 GetSpeciesBaseDefense(enum Species species)
{
    return gSpeciesInfo[SanitizeSpeciesId(species)].baseDefense;
}

static inline u32 GetSpeciesBaseSpAttack(enum Species species)
{
    return gSpeciesInfo[SanitizeSpeciesId(species)].baseSpAttack;
}

static inline u32 GetSpeciesBaseSpDefense(enum Species species)
{
    return gSpeciesInfo[SanitizeSpeciesId(species)].baseSpDefense;
}

static inline u32 GetSpeciesBaseSpeed(enum Species species)
{
    return gSpeciesInfo[SanitizeSpeciesId(species)].baseSpeed;
}

static inline u32 GetSpeciesBaseStat(enum Species species, u32 statIndex)
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

static inline u32 GetSpeciesBaseStatTotal(enum Species species)
{
    return GetSpeciesBaseHP(species)
         + GetSpeciesBaseAttack(species)
         + GetSpeciesBaseDefense(species)
         + GetSpeciesBaseSpeed(species)
         + GetSpeciesBaseSpAttack(species)
         + GetSpeciesBaseSpDefense(species);
}

static inline enum Type GetSpeciesType(enum Species species, u8 slot)
{
    return gSpeciesInfo[SanitizeSpeciesId(species)].types[slot];
}

static inline u32 GetSpeciesCatchRate(enum Species species)
{
    return gSpeciesInfo[SanitizeSpeciesId(species)].catchRate;
}

static inline u32 GetSpeciesForcedTeraType(enum Species species)
{
    return gSpeciesInfo[SanitizeSpeciesId(species)].forceTeraType;
}

static inline u32 GetSpeciesExpYield(enum Species species)
{
    return gSpeciesInfo[SanitizeSpeciesId(species)].expYield;
}

static inline u32 GetSpeciesEVYieldHP(enum Species species)
{
    return gSpeciesInfo[SanitizeSpeciesId(species)].evYield_HP;
}

static inline u32 GetSpeciesEVYieldAttack(enum Species species)
{
    return gSpeciesInfo[SanitizeSpeciesId(species)].evYield_Attack;
}

static inline u32 GetSpeciesEVYieldDefense(enum Species species)
{
    return gSpeciesInfo[SanitizeSpeciesId(species)].evYield_Defense;
}

static inline u32 GetSpeciesEVYieldSpAttack(enum Species species)
{
    return gSpeciesInfo[SanitizeSpeciesId(species)].evYield_SpAttack;
}

static inline u32 GetSpeciesEVYieldSpDefense(enum Species species)
{
    return gSpeciesInfo[SanitizeSpeciesId(species)].evYield_SpDefense;
}

static inline u32 GetSpeciesEVYieldSpeed(enum Species species)
{
    return gSpeciesInfo[SanitizeSpeciesId(species)].evYield_Speed;
}

static inline u32 GetSpeciesEVYield(enum Species species, u32 statIndex)
{
    switch (statIndex)
    {
    case STAT_HP:
        return GetSpeciesEVYieldHP(species);
    case STAT_ATK:
        return GetSpeciesEVYieldAttack(species);
    case STAT_DEF:
        return GetSpeciesEVYieldDefense(species);
    case STAT_SPEED:
        return GetSpeciesEVYieldSpeed(species);
    case STAT_SPATK:
        return GetSpeciesEVYieldSpAttack(species);
    case STAT_SPDEF:
        return GetSpeciesEVYieldSpDefense(species);
    }
    return 0;
}

static inline enum Item GetSpeciesCommonItem(enum Species species)
{
    return gSpeciesInfo[SanitizeSpeciesId(species)].itemCommon;
}

static inline enum Item GetSpeciesRareItem(enum Species species)
{
    return gSpeciesInfo[SanitizeSpeciesId(species)].itemRare;
}

static inline u32 GetSpeciesGenderRatio(enum Species species)
{
    return gSpeciesInfo[SanitizeSpeciesId(species)].genderRatio;
}

static inline u32 GetSpeciesEggCycles(enum Species species)
{
    return gSpeciesInfo[SanitizeSpeciesId(species)].eggCycles;
}

static inline u32 GetSpeciesBaseFriendship(enum Species species)
{
    return gSpeciesInfo[SanitizeSpeciesId(species)].friendship;
}

static inline enum GrowthRate GetSpeciesGrowthRate(enum Species species)
{
    return gSpeciesInfo[SanitizeSpeciesId(species)].growthRate;
}

static inline u32 GetSpeciesEggGroup(enum Species species, u8 slot)
{
    return gSpeciesInfo[SanitizeSpeciesId(species)].eggGroups[slot];
}

static inline enum Ability GetSpeciesAbility(enum Species species, u8 slot)
{
    return gSpeciesInfo[SanitizeSpeciesId(species)].abilities[slot];
}

static inline const u8 *GetSpeciesCategory(enum Species species)
{
    species = SanitizeSpeciesId(species);
    if (gSpeciesInfo[species].categoryName[0] == 0)
        return gSpeciesInfo[SPECIES_NONE].categoryName;
    return gSpeciesInfo[species].categoryName;
}

static inline const u8 *GetSpeciesName(enum Species species)
{
    species = SanitizeSpeciesId(species);
    if (gSpeciesInfo[species].speciesName[0] == 0)
        return gSpeciesInfo[SPECIES_NONE].speciesName;
    return gSpeciesInfo[species].speciesName;
}

static inline enum PokemonCry GetSpeciesCryId(enum Species species)
{
    species = SanitizeSpeciesId(species);
    if (P_CRIES_ENABLED == FALSE || gSpeciesInfo[species].cryId >= CRY_COUNT)
        return CRY_NONE;
    return gSpeciesInfo[species].cryId;
}

static inline enum NationalDexOrder SpeciesToNationalPokedexNum(enum Species species)
{
    return gSpeciesInfo[SanitizeSpeciesId(species)].natDexNum;
}

static inline u32 GetSpeciesHeight(enum Species species)
{
    return gSpeciesInfo[SanitizeSpeciesId(species)].height;
}

static inline u32 GetSpeciesWeight(enum Species species)
{
    return gSpeciesInfo[SanitizeSpeciesId(species)].weight;
}

static inline u32 GetSpeciesPokedexScale(enum Species species)
{
    return gSpeciesInfo[SanitizeSpeciesId(species)].pokemonScale;
}

static inline u32 GetSpeciesPokedexOffset(enum Species species)
{
    return gSpeciesInfo[SanitizeSpeciesId(species)].pokemonOffset;
}

static inline u32 GetSpeciesPokedexTrainerScale(enum Species species)
{
    return gSpeciesInfo[SanitizeSpeciesId(species)].trainerScale;
}

static inline u32 GetSpeciesPokedexTrainerOffset(enum Species species)
{
    return gSpeciesInfo[SanitizeSpeciesId(species)].trainerOffset;
}

static inline const u8 *GetSpeciesPokedexDescription(enum Species species)
{
    species = SanitizeSpeciesId(species);
    if (gSpeciesInfo[species].description == NULL)
        return gSpeciesInfo[SPECIES_NONE].description;
    return gSpeciesInfo[species].description;
}

static inline enum BodyColor GetSpeciesBodyColor(enum Species species)
{
    return gSpeciesInfo[SanitizeSpeciesId(species)].bodyColor;
}

static inline const u32 *GetSpeciesFrontPic(enum Species species)
{
    species = SanitizeSpeciesId(species);
    if (gSpeciesInfo[species].frontPic == NULL)
        return gSpeciesInfo[SPECIES_NONE].frontPic;
    return gSpeciesInfo[species].frontPic;
}

static inline const u32 *GetSpeciesFrontPicFemale(enum Species species)
{
#if P_GENDER_DIFFERENCES
    species = SanitizeSpeciesId(species);
    if (gSpeciesInfo[species].frontPicFemale != NULL)
        return gSpeciesInfo[species].frontPicFemale;
#endif
    return GetSpeciesFrontPic(species);
}

static inline u32 GetSpeciesFrontPicSize(enum Species species)
{
    return gSpeciesInfo[SanitizeSpeciesId(species)].frontPicSize;
}

static inline u32 GetSpeciesFrontPicSizeFemale(enum Species species)
{
#if P_GENDER_DIFFERENCES
    species = SanitizeSpeciesId(species);
    if (gSpeciesInfo[species].frontPicFemale != NULL)
        return gSpeciesInfo[species].frontPicSizeFemale;
#endif
    return GetSpeciesFrontPicSize(species);
}

static inline u32 GetSpeciesFrontPicYOffset(enum Species species)
{
    return gSpeciesInfo[SanitizeSpeciesId(species)].frontPicYOffset;
}

static inline u32 GetSpeciesFrontAnimId(enum Species species)
{
    return gSpeciesInfo[SanitizeSpeciesId(species)].frontAnimId;
}

static inline u32 GetSpeciesFrontAnimDelay(enum Species species)
{
    return gSpeciesInfo[SanitizeSpeciesId(species)].frontAnimDelay;
}

static inline const union AnimCmd *const *GetSpeciesFrontAnimFrames(enum Species species)
{
    species = SanitizeSpeciesId(species);
    if (gSpeciesInfo[species].frontAnimFrames != NULL)
        return gSpeciesInfo[species].frontAnimFrames;
    return gSpeciesInfo[SPECIES_NONE].frontAnimFrames;
}

static inline u32 GetSpeciesEnemyElevation(enum Species species)
{
    return gSpeciesInfo[SanitizeSpeciesId(species)].enemyMonElevation;
}

static inline u32 GetSpeciesEnemyShadowXOffset(enum Species species)
{
    return gSpeciesInfo[SanitizeSpeciesId(species)].enemyShadowXOffset;
}

static inline u32 GetSpeciesEnemyShadowYOffset(enum Species species)
{
    return gSpeciesInfo[SanitizeSpeciesId(species)].enemyShadowYOffset;
}

static inline u32 GetSpeciesEnemyShadowSize(enum Species species)
{
    return gSpeciesInfo[SanitizeSpeciesId(species)].enemyShadowSize;
}

static inline u32 IsSpeciesEnemyShadowSuppressed(enum Species species)
{
    return gSpeciesInfo[SanitizeSpeciesId(species)].suppressEnemyShadow;
}

static inline bool32 IsMonSpriteNotFlipped(enum Species species)
{
    return gSpeciesInfo[SanitizeSpeciesId(species)].noFlip;
}

static inline const u32 *GetSpeciesBackPic(enum Species species)
{
    species = SanitizeSpeciesId(species);
    if (gSpeciesInfo[species].backPic == NULL)
        return gSpeciesInfo[SPECIES_NONE].backPic;
    return gSpeciesInfo[species].backPic;
}

static inline const u32 *GetSpeciesBackPicFemale(enum Species species)
{
#if P_GENDER_DIFFERENCES
    species = SanitizeSpeciesId(species);
    if (gSpeciesInfo[species].backPicFemale != NULL)
        return gSpeciesInfo[species].backPicFemale;
#endif
    return GetSpeciesBackPic(species);
}

static inline u32 GetSpeciesBackPicSize(enum Species species)
{
    return gSpeciesInfo[SanitizeSpeciesId(species)].backPicSize;
}

static inline u32 GetSpeciesBackPicSizeFemale(enum Species species)
{
#if P_GENDER_DIFFERENCES
    species = SanitizeSpeciesId(species);
    if (gSpeciesInfo[species].backPicFemale != NULL)
        return gSpeciesInfo[species].backPicSizeFemale;
#endif
    return GetSpeciesBackPicSize(species);
}

static inline u32 GetSpeciesBackPicYOffset(enum Species species)
{
    return gSpeciesInfo[SanitizeSpeciesId(species)].backPicYOffset;
}

static inline enum BackAnim GetSpeciesBackAnimSet(enum Species species)
{
    if (gSpeciesInfo[species].backAnimId != BACK_ANIM_NONE)
        return gSpeciesInfo[species].backAnimId - 1;
    else
        return BACK_ANIM_NONE;
}

static inline const u16 *GetSpeciesPalette(enum Species species)
{
    species = SanitizeSpeciesId(species);
    if (gSpeciesInfo[species].palette == NULL)
        return gSpeciesInfo[SPECIES_NONE].palette;
    return gSpeciesInfo[species].palette;
}

static inline const u16 *GetSpeciesPaletteFemale(enum Species species)
{
#if P_GENDER_DIFFERENCES
    species = SanitizeSpeciesId(species);
    if (gSpeciesInfo[species].paletteFemale != NULL)
        return gSpeciesInfo[species].paletteFemale;
#endif
    return GetSpeciesPalette(species);
}

static inline const u16 *GetSpeciesShinyPalette(enum Species species)
{
    species = SanitizeSpeciesId(species);
    if (gSpeciesInfo[species].shinyPalette == NULL)
        return gSpeciesInfo[SPECIES_NONE].shinyPalette;
    return gSpeciesInfo[species].shinyPalette;
}

static inline const u16 *GetSpeciesShinyPaletteFemale(enum Species species)
{
#if P_GENDER_DIFFERENCES
    species = SanitizeSpeciesId(species);
    if (gSpeciesInfo[species].shinyPaletteFemale != NULL)
        return gSpeciesInfo[species].shinyPaletteFemale;
#endif
    return GetSpeciesShinyPalette(species);
}

static inline const u8 *GetSpeciesIconSprite(enum Species species)
{
    species = SanitizeSpeciesId(species);
    if (gSpeciesInfo[species].iconSprite == NULL)
        return gSpeciesInfo[SPECIES_NONE].iconSprite;
    return gSpeciesInfo[species].iconSprite;
}

static inline const u8 *GetSpeciesIconSpriteFemale(enum Species species)
{
#if P_GENDER_DIFFERENCES
    species = SanitizeSpeciesId(species);
    if (gSpeciesInfo[species].iconSpriteFemale != NULL)
        return gSpeciesInfo[species].iconSpriteFemale;
#endif
    return GetSpeciesIconSprite(species);
}

static inline u32 GetSpeciesIconPalIndex(enum Species species)
{
    return gSpeciesInfo[SanitizeSpeciesId(species)].iconPalIndex;
}

static inline u32 GetSpeciesIconPalIndexFemale(enum Species species)
{
#if P_GENDER_DIFFERENCES
    species = SanitizeSpeciesId(species);
    if (gSpeciesInfo[species].iconSpriteFemale != NULL)
        return gSpeciesInfo[species].iconPalIndexFemale;
#endif
    return GetSpeciesIconPalIndex(species);
}

static inline bool32 IsSpeciesRestrictedLegendary(enum Species species)
{
    return gSpeciesInfo[SanitizeSpeciesId(species)].isRestrictedLegendary;
}

static inline bool32 IsSpeciesSubLegendary(enum Species species)
{
    return gSpeciesInfo[SanitizeSpeciesId(species)].isSubLegendary;
}

static inline bool32 IsSpeciesMythical(enum Species species)
{
    return gSpeciesInfo[SanitizeSpeciesId(species)].isMythical;
}

static inline bool32 IsSpeciesUltraBeast(enum Species species)
{
    return gSpeciesInfo[SanitizeSpeciesId(species)].isUltraBeast;
}

static inline bool32 IsSpeciesParadox(enum Species species)
{
    return gSpeciesInfo[SanitizeSpeciesId(species)].isParadox;
}

static inline bool32 IsSpeciesTotem(enum Species species)
{
    return gSpeciesInfo[SanitizeSpeciesId(species)].isTotem;
}

static inline bool32 IsSpeciesMegaEvolution(enum Species species)
{
    return gSpeciesInfo[SanitizeSpeciesId(species)].isMegaEvolution;
}

static inline bool32 IsSpeciesPrimalReversion(enum Species species)
{
    return gSpeciesInfo[SanitizeSpeciesId(species)].isPrimalReversion;
}

static inline bool32 IsSpeciesUltraBurst(enum Species species)
{
    return gSpeciesInfo[SanitizeSpeciesId(species)].isUltraBurst;
}

static inline bool32 IsSpeciesGigantamax(enum Species species)
{
    return gSpeciesInfo[SanitizeSpeciesId(species)].isGigantamax;
}

static inline bool32 IsSpeciesTeraForm(enum Species species)
{
    return gSpeciesInfo[SanitizeSpeciesId(species)].isTeraForm;
}

static inline bool32 IsSpeciesAlolanForm(enum Species species)
{
    return gSpeciesInfo[SanitizeSpeciesId(species)].isAlolanForm;
}

static inline bool32 IsSpeciesGalarianForm(enum Species species)
{
    return gSpeciesInfo[SanitizeSpeciesId(species)].isGalarianForm;
}

static inline bool32 IsSpeciesHisuianForm(enum Species species)
{
    return gSpeciesInfo[SanitizeSpeciesId(species)].isHisuianForm;
}

static inline bool32 IsSpeciesPaldeanForm(enum Species species)
{
    return gSpeciesInfo[SanitizeSpeciesId(species)].isPaldeanForm;
}

static inline bool32 IsSpeciesRegionalForm(u32 species)
{
    species = SanitizeSpeciesId(species);
    return gSpeciesInfo[species].isAlolanForm
        || gSpeciesInfo[species].isGalarianForm
        || gSpeciesInfo[species].isHisuianForm
        || gSpeciesInfo[species].isPaldeanForm;
}

static inline bool32 IsSpeciesTradeBanned(enum Species species)
{
    return gSpeciesInfo[SanitizeSpeciesId(species)].cannotBeTraded;
}

static inline u32 GetSpeciesPerfectIVCount(enum Species species)
{
    return gSpeciesInfo[SanitizeSpeciesId(species)].perfectIVCount;
}

static inline bool32 IsSpeciesDexForced(enum Species species)
{
    return gSpeciesInfo[SanitizeSpeciesId(species)].dexForceRequired;
}

static inline bool32 IsSpeciesFrontierBanned(enum Species species)
{
    return gSpeciesInfo[SanitizeSpeciesId(species)].isFrontierBanned;
}

static inline bool32 IsSpeciesSkyBattleBanned(enum Species species)
{
    return gSpeciesInfo[SanitizeSpeciesId(species)].isSkyBattleBanned;
}

static inline bool32 IsSpeciesTelekinesisBanned(enum Species species)
{
    return gSpeciesInfo[SanitizeSpeciesId(species)].isTelekinesisBanned;
}

static inline enum EggIds GetSpeciesEggId(enum Species species)
{
    return gSpeciesInfo[SanitizeSpeciesId(species)].eggId;
}

static inline u32 GetSpeciesPokemonJumpType(enum Species species)
{
    return gSpeciesInfo[SanitizeSpeciesId(species)].pokemonJumpType;
}

static inline bool32 IsSpeciesAllowedInPokemonJump(enum Species species)
{
    return GetSpeciesPokemonJumpType(species) != PKMN_JUMP_TYPE_NONE;
}

static inline const struct LevelUpMove *GetSpeciesLevelUpLearnset(enum Species species)
{
    const struct LevelUpMove *learnset = gSpeciesInfo[SanitizeSpeciesId(species)].levelUpLearnset;
    if (learnset == NULL)
        return gSpeciesInfo[SPECIES_NONE].levelUpLearnset;
    return learnset;
}

static inline const u16 *GetSpeciesTeachableLearnset(enum Species species)
{
    const u16 *learnset = gSpeciesInfo[SanitizeSpeciesId(species)].teachableLearnset;
    if (learnset == NULL)
        return gSpeciesInfo[SPECIES_NONE].teachableLearnset;
    return learnset;
}

static inline const u16 *GetSpeciesEggMoves(enum Species species)
{
    const u16 *learnset = gSpeciesInfo[SanitizeSpeciesId(species)].eggMoveLearnset;
    if (learnset == NULL)
        return gSpeciesInfo[SPECIES_NONE].eggMoveLearnset;
    return learnset;
}

static inline const struct Evolution *GetSpeciesEvolutions(enum Species species)
{
    const struct Evolution *evolutions = gSpeciesInfo[SanitizeSpeciesId(species)].evolutions;
    if (evolutions == NULL)
        return gSpeciesInfo[SPECIES_NONE].evolutions;
    return evolutions;
}

static inline const enum Species *GetSpeciesFormTable(enum Species species)
{
    const enum Species *formTable = gSpeciesInfo[SanitizeSpeciesId(species)].formSpeciesIdTable;
    if (formTable == NULL)
        return gSpeciesInfo[SPECIES_NONE].formSpeciesIdTable;
    return formTable;
}

static inline enum Species GetFormSpeciesId(enum Species species, u8 formId)
{
    const enum Species *formTable = GetSpeciesFormTable(species);
    if (formTable != NULL)
        return formTable[formId];
    else
        return species;
}

static inline enum Species GetBaseSpeciesId(enum Species species)
{
    return GetFormSpeciesId(species, 0);
}

static inline const struct FormChange *GetSpeciesFormChanges(enum Species species)
{
    const struct FormChange *formChanges = gSpeciesInfo[SanitizeSpeciesId(species)].formChangeTable;
    if (formChanges == NULL)
        return gSpeciesInfo[SPECIES_NONE].formChangeTable;
    return formChanges;
}

static inline bool32 SpeciesHasGenderDifferences(enum Species species)
{
#if P_GENDER_DIFFERENCES
    if (gSpeciesInfo[species].frontPicFemale != NULL
     || gSpeciesInfo[species].backPicFemale != NULL
     || gSpeciesInfo[species].paletteFemale != NULL
     || gSpeciesInfo[species].shinyPaletteFemale != NULL
     || gSpeciesInfo[species].iconSpriteFemale != NULL)
        return TRUE;
#endif

    return FALSE;
}

#if P_FOOTPRINTS
static inline const u8 *GetSpeciesFootprint(enum Species species)
{
    return gSpeciesInfo[SanitizeSpeciesId(species)].footprint;
}
#endif // P_FOOTPRINTS

#if OW_POKEMON_OBJECT_EVENTS
static inline const struct ObjectEventGraphicsInfo *GetSpeciesOverworldData(enum Species species)
{
    return &gSpeciesInfo[SanitizeSpeciesId(species)].overworldData;
}

static inline const struct ObjectEventGraphicsInfo *GetSpeciesOverworldDataFemale(enum Species species)
{
#if P_GENDER_DIFFERENCES
    species = SanitizeSpeciesId(species);
    if (gSpeciesInfo[species].overworldDataFemale.paletteTag == OBJ_EVENT_PAL_TAG_DYNAMIC)
        return &gSpeciesInfo[species].overworldDataFemale;
#endif
    return GetSpeciesOverworldData(species);
}

static inline const void *GetSpeciesOverworldPalette(enum Species species)
{
    species = SanitizeSpeciesId(species);
    if (gSpeciesInfo[species].overworldPalette == NULL)
        return gSpeciesInfo[SPECIES_NONE].overworldPalette;
    return gSpeciesInfo[species].overworldPalette;
}

static inline const u16 *GetSpeciesOverworldPaletteFemale(enum Species species)
{
#if P_GENDER_DIFFERENCES
    species = SanitizeSpeciesId(species);
    if (gSpeciesInfo[species].overworldPaletteFemale != NULL)
        return gSpeciesInfo[species].overworldPaletteFemale;
#endif
    return GetSpeciesOverworldPalette(species);
}

static inline const u16 *GetSpeciesOverworldShinyPalette(enum Species species)
{
    species = SanitizeSpeciesId(species);
    if (gSpeciesInfo[species].overworldShinyPalette == NULL)
        return gSpeciesInfo[SPECIES_NONE].overworldShinyPalette;
    return gSpeciesInfo[species].overworldShinyPalette;
}

static inline const u16 *GetSpeciesOverworldShinyPaletteFemale(enum Species species)
{
#if P_GENDER_DIFFERENCES
    species = SanitizeSpeciesId(species);
    if (gSpeciesInfo[species].overworldShinyPaletteFemale != NULL)
        return gSpeciesInfo[species].overworldShinyPaletteFemale;
#endif
    return GetSpeciesOverworldShinyPalette(species);
}

#endif // OW_POKEMON_OBJECT_EVENTS

#define gSpeciesInfo \
_Pragma("GCC error \"Use getters instead of accessing gSpeciesInfo directly.\"") \
gSpeciesInfo

#endif // GUARD_SPECIES_INFO_H
