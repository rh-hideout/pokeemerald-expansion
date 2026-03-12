#ifndef GUARD_POKEDEX_H
#define GUARD_POKEDEX_H

extern u8 gUnusedPokedexU8;
extern void (*gPokedexVBlankCB)(void);

void ResetPokedex(void);
u16 GetNationalPokedexCount(u8 caseID);
u32 GetRegionalPokedexCount(u8 caseID);
u16 GetHoennPokedexCount(u8 caseID);
u16 GetKantoPokedexCount(u8 caseID);
u8 DisplayCaughtMonDexPage(u16 species, bool32 isShiny, u32 personality);
u32 Pokedex_CreateCaughtMonSprite(u32 species, s32 x, s32 y);
s8 GetSetPokedexFlag(enum NationalDexOrder nationalDexNo, u8 caseID);
void DrawFootprint(u8 windowId, u16 species);
u16 CreateMonSpriteFromNationalDexNumber(enum NationalDexOrder nationalNum, s16 x, s16 y, u16 paletteSlot);
bool16 HasAllRegionalMons(void);
bool16 HasAllHoennMons(void);
bool16 HasAllKantoMons(void);
void ResetPokedexScrollPositions(void);
bool16 HasAllMons(void);
void CB2_OpenPokedex(void);
void PrintMonMeasurements(u16 species, u32 owned);
u8* ConvertMonHeightToString(u32 height);
u8* ConvertMonWeightToString(u32 weight);

// Common Pokédex Definitions and Functions
#define MAX_MONS_ON_SCREEN          4

struct PokedexListItem
{
    u16 dexNum;
    u16 seen:1;
    u16 owned:1;
};

struct PokemonStats
{
    u16 species;
    u8  genderRatio;
    u8  baseHP;
    u8  baseSpeed;
    u8  baseAttack;
    u8  baseSpAttack;
    u8  baseDefense;
    u8  baseSpDefense;
    u8  differentEVs;
    u8  evYield_HP;
    u8  evYield_Speed;
    u8  evYield_Attack;
    u8  evYield_SpAttack;
    u8  evYield_Defense;
    u8  evYield_SpDefense;
    u8  catchRate;
    enum GrowthRate growthRate:8;
    u8  eggGroup1;
    u8  eggGroup2;
    u8  eggCycles;
    u16 expYield;
    u8  friendship;
    enum Ability ability0;
    enum Ability ability1;
    enum Ability abilityHidden;
};

struct EvoScreenData
{
    bool8 fromEvoPage;
    u8 numAllEvolutions;
    u16 targetSpecies[10];
    u8 numSeen;
    bool8 seen[10];
    u8 menuPos;
    u8 arrowSpriteId;
    bool8 isMega;
    u32 arrowSpriteDist[10];
};

struct FromScreenData
{
    u8 numForms;
    u16 formIds[30];
    bool8 inSubmenu;
    u8 menuPos;
    u8 arrowSpriteId;
};

struct PokedexView
{
    struct PokedexListItem pokedexList[NATIONAL_DEX_COUNT + 1];
    u16 pokemonListCount;
    u16 selectedPokemon;
    u16 selectedPokemonBackup;
    u16 dexMode;
    u16 dexModeBackup;
    u16 dexOrder;
    u16 dexOrderBackup;
    u16 seenCount;
    u16 ownCount;
    u16 monSpriteIds[MAX_MONS_ON_SCREEN];
    u16 selectedMonSpriteId;
    u16 pokeBallRotationStep;
    u16 pokeBallRotationBackup;
    u8 pokeBallRotation;
    u8 initialVOffset;
    u8 scrollTimer;
    u8 scrollDirection;
    s16 listVOffset;
    s16 listMovingVOffset;
    u16 scrollMonIncrement;
    u16 maxScrollTimer;
    u16 scrollSpeed;
    u16 unkArr1[4]; // Cleared, never read
    u8 filler[8];
    u8 currentPage;
    u8 currentPageBackup;
    bool8 isSearchResults:1;
    u8 selectedScreen;
    u8 screenSwitchState;
    u8 menuIsOpen;
    u16 menuCursorPos;
    s16 menuY;     //Menu Y position (inverted because we use REG_BG0VOFS for this)
    u8 unkArr2[8]; // Cleared, never read
    u8 unkArr3[8]; // Cleared, never read

    // HGSS
    u16 originalSearchSelectionNum;
    u8 typeIconSpriteIds[2];
    u16 moveSelected;
    u16 movesTotal;
    u8 statBarsSpriteId;
    u8 statBarsBgSpriteId;
    bool8 justScrolled;
    u8 categoryIconSpriteId; //Physical/Special/Status category
    u8 numEggMoves;
    u8 numLevelUpMoves;
    u16 numTeachableMoves;
    u8 numPreEvolutions;
    struct PokemonStats sPokemonStats;
    struct EvoScreenData sEvoScreenData;
    struct FromScreenData sFormScreenData;
    u16 formSpecies;
};

#endif // GUARD_POKEDEX_H
