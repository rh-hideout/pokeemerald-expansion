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
    u16 targetSpecies;
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

extern const struct SpeciesInfo gSpeciesInfo[];

static inline bool32 IsSpeciesEnabled(u16 species)
{
    // This function should not use the GetSpeciesBaseHP function, as the included sanitation will result in an infinite loop
    return gSpeciesInfo[species].baseHP > 0 || species == SPECIES_EGG;
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
    return gSpeciesInfo[SanitizeSpeciesId(species)].baseHP;
}

static inline u32 GetSpeciesBaseAttack(u16 species)
{
    return gSpeciesInfo[SanitizeSpeciesId(species)].baseAttack;
}

static inline u32 GetSpeciesBaseDefense(u16 species)
{
    return gSpeciesInfo[SanitizeSpeciesId(species)].baseDefense;
}

static inline u32 GetSpeciesBaseSpAttack(u16 species)
{
    return gSpeciesInfo[SanitizeSpeciesId(species)].baseSpAttack;
}

static inline u32 GetSpeciesBaseSpDefense(u16 species)
{
    return gSpeciesInfo[SanitizeSpeciesId(species)].baseSpDefense;
}

static inline u32 GetSpeciesBaseSpeed(u16 species)
{
    return gSpeciesInfo[SanitizeSpeciesId(species)].baseSpeed;
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

static inline u32 GetSpeciesBaseStatTotal(u32 species)
{
    return GetSpeciesBaseHP(species)
         + GetSpeciesBaseAttack(species)
         + GetSpeciesBaseDefense(species)
         + GetSpeciesBaseSpeed(species)
         + GetSpeciesBaseSpAttack(species)
         + GetSpeciesBaseSpDefense(species);
}

static inline enum Type GetSpeciesType(u16 species, u8 slot)
{
    return gSpeciesInfo[SanitizeSpeciesId(species)].types[slot];
}

static inline u32 GetSpeciesCatchRate(u16 species)
{
    return gSpeciesInfo[SanitizeSpeciesId(species)].catchRate;
}

static inline u32 GetSpeciesForcedTeraType(u16 species)
{
    return gSpeciesInfo[SanitizeSpeciesId(species)].forceTeraType;
}

static inline u32 GetSpeciesExpYield(u16 species)
{
    return gSpeciesInfo[SanitizeSpeciesId(species)].expYield;
}

static inline u32 GetSpeciesEVYieldHP(u16 species)
{
    return gSpeciesInfo[SanitizeSpeciesId(species)].evYield_HP;
}

static inline u32 GetSpeciesEVYieldAttack(u16 species)
{
    return gSpeciesInfo[SanitizeSpeciesId(species)].evYield_Attack;
}

static inline u32 GetSpeciesEVYieldDefense(u16 species)
{
    return gSpeciesInfo[SanitizeSpeciesId(species)].evYield_Defense;
}

static inline u32 GetSpeciesEVYieldSpAttack(u16 species)
{
    return gSpeciesInfo[SanitizeSpeciesId(species)].evYield_SpAttack;
}

static inline u32 GetSpeciesEVYieldSpDefense(u16 species)
{
    return gSpeciesInfo[SanitizeSpeciesId(species)].evYield_SpDefense;
}

static inline u32 GetSpeciesEVYieldSpeed(u16 species)
{
    return gSpeciesInfo[SanitizeSpeciesId(species)].evYield_Speed;
}

static inline u32 GetSpeciesEVYield(u16 species, u32 statIndex)
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

static inline u32 GetSpeciesCommonItem(u16 species)
{
    return gSpeciesInfo[SanitizeSpeciesId(species)].itemCommon;
}

static inline u32 GetSpeciesRareItem(u16 species)
{
    return gSpeciesInfo[SanitizeSpeciesId(species)].itemRare;
}

static inline u32 GetSpeciesGenderRatio(u16 species)
{
    return gSpeciesInfo[SanitizeSpeciesId(species)].genderRatio;
}

static inline u32 GetSpeciesEggCycles(u16 species)
{
    return gSpeciesInfo[SanitizeSpeciesId(species)].eggCycles;
}

static inline u32 GetSpeciesBaseFriendship(u16 species)
{
    return gSpeciesInfo[SanitizeSpeciesId(species)].friendship;
}

static inline enum GrowthRate GetSpeciesGrowthRate(u16 species)
{
    return gSpeciesInfo[SanitizeSpeciesId(species)].growthRate;
}

static inline u32 GetSpeciesEggGroup(u16 species, u8 slot)
{
    return gSpeciesInfo[SanitizeSpeciesId(species)].eggGroups[slot];
}

static inline enum Ability GetSpeciesAbility(u16 species, u8 slot)
{
    return gSpeciesInfo[SanitizeSpeciesId(species)].abilities[slot];
}

static inline const u8 *GetSpeciesCategory(u16 species)
{
    species = SanitizeSpeciesId(species);
    if (gSpeciesInfo[species].categoryName[0] == 0)
        return gSpeciesInfo[SPECIES_NONE].categoryName;
    return gSpeciesInfo[species].categoryName;
}

static inline const u8 *GetSpeciesName(u16 species)
{
    species = SanitizeSpeciesId(species);
    if (gSpeciesInfo[species].speciesName[0] == 0)
        return gSpeciesInfo[SPECIES_NONE].speciesName;
    return gSpeciesInfo[species].speciesName;
}

static inline enum PokemonCry GetSpeciesCryId(u16 species)
{
    species = SanitizeSpeciesId(species);
    if (P_CRIES_ENABLED == FALSE || gSpeciesInfo[species].cryId >= CRY_COUNT)
        return CRY_NONE;
    return gSpeciesInfo[species].cryId;
}

static inline enum NationalDexOrder SpeciesToNationalPokedexNum(u16 species)
{
    return gSpeciesInfo[SanitizeSpeciesId(species)].natDexNum;
}

static inline u32 GetSpeciesHeight(u16 species)
{
    return gSpeciesInfo[SanitizeSpeciesId(species)].height;
}

static inline u32 GetSpeciesWeight(u16 species)
{
    return gSpeciesInfo[SanitizeSpeciesId(species)].weight;
}

static inline u32 GetSpeciesPokedexScale(u16 species)
{
    return gSpeciesInfo[SanitizeSpeciesId(species)].pokemonScale;
}

static inline u32 GetSpeciesPokedexOffset(u16 species)
{
    return gSpeciesInfo[SanitizeSpeciesId(species)].pokemonOffset;
}

static inline u32 GetSpeciesPokedexTrainerScale(u16 species)
{
    return gSpeciesInfo[SanitizeSpeciesId(species)].trainerScale;
}

static inline u32 GetSpeciesPokedexTrainerOffset(u16 species)
{
    return gSpeciesInfo[SanitizeSpeciesId(species)].trainerOffset;
}

static inline const u8 *GetSpeciesPokedexDescription(u16 species)
{
    species = SanitizeSpeciesId(species);
    if (gSpeciesInfo[species].description == NULL)
        return gSpeciesInfo[SPECIES_NONE].description;
    return gSpeciesInfo[species].description;
}

static inline enum BodyColor GetSpeciesBodyColor(u16 species)
{
    return gSpeciesInfo[SanitizeSpeciesId(species)].bodyColor;
}

static inline const u32 *GetSpeciesFrontPic(u16 species)
{
    species = SanitizeSpeciesId(species);
    if (gSpeciesInfo[species].frontPic == NULL)
        return gSpeciesInfo[SPECIES_NONE].frontPic;
    return gSpeciesInfo[species].frontPic;
}

static inline const u32 *GetSpeciesFrontPicFemale(u16 species)
{
#if P_GENDER_DIFFERENCES
    species = SanitizeSpeciesId(species);
    if (gSpeciesInfo[species].frontPicFemale != NULL)
        return gSpeciesInfo[species].frontPicFemale;
#endif
    return GetSpeciesFrontPic(species);
}

static inline u32 GetSpeciesFrontPicSize(u16 species)
{
    return gSpeciesInfo[SanitizeSpeciesId(species)].frontPicSize;
}

static inline u32 GetSpeciesFrontPicSizeFemale(u16 species)
{
#if P_GENDER_DIFFERENCES
    species = SanitizeSpeciesId(species);
    if (gSpeciesInfo[species].frontPicFemale != NULL)
        return gSpeciesInfo[species].frontPicSizeFemale;
#endif
    return GetSpeciesFrontPicSize(species);
}

static inline u32 GetSpeciesFrontPicYOffset(u16 species)
{
    return gSpeciesInfo[SanitizeSpeciesId(species)].frontPicYOffset;
}

static inline u32 GetSpeciesFrontAnimId(u16 species)
{
    return gSpeciesInfo[SanitizeSpeciesId(species)].frontAnimId;
}

static inline u32 GetSpeciesFrontAnimDelay(u16 species)
{
    return gSpeciesInfo[SanitizeSpeciesId(species)].frontAnimDelay;
}

static inline const union AnimCmd *const *GetSpeciesFrontAnimFrames(u16 species)
{
    species = SanitizeSpeciesId(species);
    if (gSpeciesInfo[species].frontAnimFrames != NULL)
        return gSpeciesInfo[species].frontAnimFrames;
    return gSpeciesInfo[SPECIES_NONE].frontAnimFrames;
}

static inline u32 GetSpeciesEnemyElevation(u16 species)
{
    return gSpeciesInfo[SanitizeSpeciesId(species)].enemyMonElevation;
}

static inline u32 GetSpeciesEnemyShadowXOffset(u16 species)
{
    return gSpeciesInfo[SanitizeSpeciesId(species)].enemyShadowXOffset;
}

static inline u32 GetSpeciesEnemyShadowYOffset(u16 species)
{
    return gSpeciesInfo[SanitizeSpeciesId(species)].enemyShadowYOffset;
}

static inline u32 GetSpeciesEnemyShadowSize(u16 species)
{
    return gSpeciesInfo[SanitizeSpeciesId(species)].enemyShadowSize;
}

static inline u32 IsSpeciesEnemyShadowSuppressed(u16 species)
{
    return gSpeciesInfo[SanitizeSpeciesId(species)].suppressEnemyShadow;
}

static inline bool32 IsMonSpriteNotFlipped(u16 species)
{
    return gSpeciesInfo[SanitizeSpeciesId(species)].noFlip;
}

static inline const u32 *GetSpeciesBackPic(u16 species)
{
    species = SanitizeSpeciesId(species);
    if (gSpeciesInfo[species].backPic == NULL)
        return gSpeciesInfo[SPECIES_NONE].backPic;
    return gSpeciesInfo[species].backPic;
}

static inline const u32 *GetSpeciesBackPicFemale(u16 species)
{
#if P_GENDER_DIFFERENCES
    species = SanitizeSpeciesId(species);
    if (gSpeciesInfo[species].backPicFemale != NULL)
        return gSpeciesInfo[species].backPicFemale;
#endif
    return GetSpeciesBackPic(species);
}

static inline u32 GetSpeciesBackPicSize(u16 species)
{
    return gSpeciesInfo[SanitizeSpeciesId(species)].backPicSize;
}

static inline u32 GetSpeciesBackPicSizeFemale(u16 species)
{
#if P_GENDER_DIFFERENCES
    species = SanitizeSpeciesId(species);
    if (gSpeciesInfo[species].backPicFemale != NULL)
        return gSpeciesInfo[species].backPicSizeFemale;
#endif
    return GetSpeciesBackPicSize(species);
}

static inline u32 GetSpeciesBackPicYOffset(u16 species)
{
    return gSpeciesInfo[SanitizeSpeciesId(species)].backPicYOffset;
}

static inline enum BackAnim GetSpeciesBackAnimSet(u16 species)
{
    if (gSpeciesInfo[species].backAnimId != BACK_ANIM_NONE)
        return gSpeciesInfo[species].backAnimId - 1;
    else
        return BACK_ANIM_NONE;
}

static inline const u16 *GetSpeciesPalette(u16 species)
{
    species = SanitizeSpeciesId(species);
    if (gSpeciesInfo[species].palette == NULL)
        return gSpeciesInfo[SPECIES_NONE].palette;
    return gSpeciesInfo[species].palette;
}

static inline const u16 *GetSpeciesPaletteFemale(u16 species)
{
#if P_GENDER_DIFFERENCES
    species = SanitizeSpeciesId(species);
    if (gSpeciesInfo[species].paletteFemale != NULL)
        return gSpeciesInfo[species].paletteFemale;
#endif
    return GetSpeciesPalette(species);
}

static inline const u16 *GetSpeciesShinyPalette(u16 species)
{
    species = SanitizeSpeciesId(species);
    if (gSpeciesInfo[species].shinyPalette == NULL)
        return gSpeciesInfo[SPECIES_NONE].shinyPalette;
    return gSpeciesInfo[species].shinyPalette;
}

static inline const u16 *GetSpeciesShinyPaletteFemale(u16 species)
{
#if P_GENDER_DIFFERENCES
    species = SanitizeSpeciesId(species);
    if (gSpeciesInfo[species].shinyPaletteFemale != NULL)
        return gSpeciesInfo[species].shinyPaletteFemale;
#endif
    return GetSpeciesShinyPalette(species);
}

static inline const u8 *GetSpeciesIconSprite(u16 species)
{
    species = SanitizeSpeciesId(species);
    if (gSpeciesInfo[species].iconSprite == NULL)
        return gSpeciesInfo[SPECIES_NONE].iconSprite;
    return gSpeciesInfo[species].iconSprite;
}

static inline const u8 *GetSpeciesIconSpriteFemale(u16 species)
{
#if P_GENDER_DIFFERENCES
    species = SanitizeSpeciesId(species);
    if (gSpeciesInfo[species].iconSpriteFemale != NULL)
        return gSpeciesInfo[species].iconSpriteFemale;
#endif
    return GetSpeciesIconSprite(species);
}

static inline u32 GetSpeciesIconPalIndex(u16 species)
{
    return gSpeciesInfo[SanitizeSpeciesId(species)].iconPalIndex;
}

static inline u32 GetSpeciesIconPalIndexFemale(u16 species)
{
#if P_GENDER_DIFFERENCES
    species = SanitizeSpeciesId(species);
    if (gSpeciesInfo[species].iconSpriteFemale != NULL)
        return gSpeciesInfo[species].iconPalIndexFemale;
#endif
    return GetSpeciesIconPalIndex(species);
}

static inline bool32 IsSpeciesRestrictedLegendary(u16 species)
{
    return gSpeciesInfo[SanitizeSpeciesId(species)].isRestrictedLegendary;
}

static inline bool32 IsSpeciesSubLegendary(u16 species)
{
    return gSpeciesInfo[SanitizeSpeciesId(species)].isSubLegendary;
}

static inline bool32 IsSpeciesMythical(u16 species)
{
    return gSpeciesInfo[SanitizeSpeciesId(species)].isMythical;
}

static inline bool32 IsSpeciesUltraBeast(u16 species)
{
    return gSpeciesInfo[SanitizeSpeciesId(species)].isUltraBeast;
}

static inline bool32 IsSpeciesParadox(u16 species)
{
    return gSpeciesInfo[SanitizeSpeciesId(species)].isParadox;
}

static inline bool32 IsSpeciesTotem(u16 species)
{
    return gSpeciesInfo[SanitizeSpeciesId(species)].isTotem;
}

static inline bool32 IsSpeciesMegaEvolution(u16 species)
{
    return gSpeciesInfo[SanitizeSpeciesId(species)].isMegaEvolution;
}

static inline bool32 IsSpeciesPrimalReversion(u16 species)
{
    return gSpeciesInfo[SanitizeSpeciesId(species)].isPrimalReversion;
}

static inline bool32 IsSpeciesUltraBurst(u16 species)
{
    return gSpeciesInfo[SanitizeSpeciesId(species)].isUltraBurst;
}

static inline bool32 IsSpeciesGigantamax(u16 species)
{
    return gSpeciesInfo[SanitizeSpeciesId(species)].isGigantamax;
}

static inline bool32 IsSpeciesTeraForm(u16 species)
{
    return gSpeciesInfo[SanitizeSpeciesId(species)].isTeraForm;
}

static inline bool32 IsSpeciesAlolanForm(u16 species)
{
    return gSpeciesInfo[SanitizeSpeciesId(species)].isAlolanForm;
}

static inline bool32 IsSpeciesGalarianForm(u16 species)
{
    return gSpeciesInfo[SanitizeSpeciesId(species)].isGalarianForm;
}

static inline bool32 IsSpeciesHisuianForm(u16 species)
{
    return gSpeciesInfo[SanitizeSpeciesId(species)].isHisuianForm;
}

static inline bool32 IsSpeciesPaldeanForm(u16 species)
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

static inline bool32 IsSpeciesTradeBanned(u16 species)
{
    return gSpeciesInfo[SanitizeSpeciesId(species)].cannotBeTraded;
}

static inline u32 GetSpeciesPerfectIVCount(u16 species)
{
    return gSpeciesInfo[SanitizeSpeciesId(species)].perfectIVCount;
}

static inline bool32 IsSpeciesDexForced(u16 species)
{
    return gSpeciesInfo[SanitizeSpeciesId(species)].dexForceRequired;
}

static inline bool32 IsSpeciesTMIlliterate(u16 species)
{
    return gSpeciesInfo[SanitizeSpeciesId(species)].tmIlliterate;
}

static inline bool32 IsSpeciesFrontierBanned(u16 species)
{
    return gSpeciesInfo[SanitizeSpeciesId(species)].isFrontierBanned;
}

static inline enum EggIds GetSpeciesEggId(u16 species)
{
    return gSpeciesInfo[SanitizeSpeciesId(species)].eggId;
}

static inline u32 GetSpeciesPokemonJumpType(u16 species)
{
    return gSpeciesInfo[SanitizeSpeciesId(species)].pokemonJumpType;
}

static inline bool32 IsSpeciesAllowedInPokemonJump(u16 species)
{
    return GetSpeciesPokemonJumpType(species) != PKMN_JUMP_TYPE_NONE;
}

static inline const struct LevelUpMove *GetSpeciesLevelUpLearnset(u16 species)
{
    const struct LevelUpMove *learnset = gSpeciesInfo[SanitizeSpeciesId(species)].levelUpLearnset;
    if (learnset == NULL)
        return gSpeciesInfo[SPECIES_NONE].levelUpLearnset;
    return learnset;
}

static inline const u16 *GetSpeciesTeachableLearnset(u16 species)
{
    const u16 *learnset = gSpeciesInfo[SanitizeSpeciesId(species)].teachableLearnset;
    if (learnset == NULL)
        return gSpeciesInfo[SPECIES_NONE].teachableLearnset;
    return learnset;
}

static inline const u16 *GetSpeciesEggMoves(u16 species)
{
    const u16 *learnset = gSpeciesInfo[SanitizeSpeciesId(species)].eggMoveLearnset;
    if (learnset == NULL)
        return gSpeciesInfo[SPECIES_NONE].eggMoveLearnset;
    return learnset;
}

static inline const struct Evolution *GetSpeciesEvolutions(u16 species)
{
    const struct Evolution *evolutions = gSpeciesInfo[SanitizeSpeciesId(species)].evolutions;
    if (evolutions == NULL)
        return gSpeciesInfo[SPECIES_NONE].evolutions;
    return evolutions;
}

static inline const u16 *GetSpeciesFormTable(u16 species)
{
    const u16 *formTable = gSpeciesInfo[SanitizeSpeciesId(species)].formSpeciesIdTable;
    if (formTable == NULL)
        return gSpeciesInfo[SPECIES_NONE].formSpeciesIdTable;
    return formTable;
}

static inline const struct FormChange *GetSpeciesFormChanges(u16 species)
{
    const struct FormChange *formChanges = gSpeciesInfo[SanitizeSpeciesId(species)].formChangeTable;
    if (formChanges == NULL)
        return gSpeciesInfo[SPECIES_NONE].formChangeTable;
    return formChanges;
}

static inline bool32 SpeciesHasGenderDifferences(u16 species)
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
static inline const u8 *GetSpeciesFootprint(u16 species)
{
    return gSpeciesInfo[SanitizeSpeciesId(species)].footprint;
}
#endif // P_FOOTPRINTS

#if OW_POKEMON_OBJECT_EVENTS
static inline const struct ObjectEventGraphicsInfo *GetSpeciesOverworldData(u16 species)
{
    return &gSpeciesInfo[SanitizeSpeciesId(species)].overworldData;
}

static inline const struct ObjectEventGraphicsInfo *GetSpeciesOverworldDataFemale(u16 species)
{
#if P_GENDER_DIFFERENCES
    species = SanitizeSpeciesId(species);
    if (gSpeciesInfo[species].overworldDataFemale.paletteTag == OBJ_EVENT_PAL_TAG_DYNAMIC)
        return &gSpeciesInfo[species].overworldDataFemale;
#endif
    return GetSpeciesOverworldData(species);
}

static inline const void *GetSpeciesOverworldPalette(u16 species)
{
    species = SanitizeSpeciesId(species);
    if (gSpeciesInfo[species].overworldPalette == NULL)
        return gSpeciesInfo[SPECIES_NONE].overworldPalette;
    return gSpeciesInfo[species].overworldPalette;
}

static inline const u16 *GetSpeciesOverworldPaletteFemale(u16 species)
{
#if P_GENDER_DIFFERENCES
    species = SanitizeSpeciesId(species);
    if (gSpeciesInfo[species].overworldPaletteFemale != NULL)
        return gSpeciesInfo[species].overworldPaletteFemale;
#endif
    return GetSpeciesOverworldPalette(species);
}

static inline const u16 *GetSpeciesOverworldShinyPalette(u16 species)
{
    species = SanitizeSpeciesId(species);
    if (gSpeciesInfo[species].overworldShinyPalette == NULL)
        return gSpeciesInfo[SPECIES_NONE].overworldShinyPalette;
    return gSpeciesInfo[species].overworldShinyPalette;
}

static inline const u16 *GetSpeciesOverworldShinyPaletteFemale(u16 species)
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
