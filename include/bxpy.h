#ifndef GUARD_BXPY_H
#define GUARD_BXPY_H

#include "pokemon_summary_screen.h"
#include "constants/bxpy.h"
#include "sprite.h"

u32 IsDoingBringXPickYSelection(void);
void BXPY_FadescreenAndExitGracefully(void);
void BXPY_SetupCallback(void);
bool8 BXPY_IsOpenTeamSheetOn(void);

void BXPY_OverworldRun_ErrorCheck_BringSizeTooLarge(void);
void BXPY_OverworldRun_ErrorCheck_BringSizeNotEnough(void);
void BXPY_OverworldRun_ErrorCheck_ClauseSpecies(void);
void BXPY_OverworldRun_ErrorCheck_ClauseItem(void);
void BXPY_OverworldRun_ErrorCheck_ClauseSpecialPokemon(void);
void BXPY_TryHealBeforeBattle(void);
void BXPY_TryHealAfterBattle(void);
void BXPY_Init(enum BXPYBattleTypes battleType, u32 bringSize, u32 pickSize, u32 trainerA, const u8 *loseTextA, u32 trainerB, const u8* loseTextB, u32 partnerId);
bool8 BXPY_IsSummaryScreenForEnemy(enum PokemonSummaryScreenMode mode);
bool8 BXPY_ShouldHideEnemyAbility(enum PokemonSummaryScreenMode mode);
bool8 BXPY_ShouldHideEnemyNature(enum PokemonSummaryScreenMode mode);
bool8 BXPY_ShouldHideEnemyIndividualValues(enum PokemonSummaryScreenMode mode, enum PokemonSummarySkillsMode stats);
bool8 BXPY_ShouldHideEnemyEffortValues(enum PokemonSummaryScreenMode mode, enum PokemonSummarySkillsMode stats);
bool8 BXPY_ShouldHideEnemyTeraType(enum PokemonSummaryScreenMode mode);
enum Type BXPY_TransformPageInfoType(enum PokemonSummaryScreenMode mode, enum Type originalTypeId, u32 spriteArrayId, u32 species);
enum Type BXPY_TransformType(enum BXPYTeamPreviewSpeciesModes mode, enum Type originalTypeId, u32 typeIndex, enum Species species);
enum Type BXPY_TransformPageBattleMoves(enum PokemonSummaryScreenMode mode, enum Type originalTypeId, u32 spriteArrayId);
enum Type BXPY_TransformTypeIfHidden(enum PokemonSummaryScreenMode mode, enum Type originalTypeId, u32 spriteArrayId, u32 species, enum PokemonSummaryScreenPage page);
bool8 BXPY_ShouldHideEnemyMoves(enum PokemonSummaryScreenMode mode);
enum BXPYTeamPreviewItemModes BXPY_GetEnemyItemVisibilityLevel(void);
bool8 BXPY_SummaryScreen_ItemVisibility(enum PokemonSummaryScreenMode mode);
bool8 BXPY_SummaryScreen_ShouldHideItem(enum PokemonSummaryScreenMode mode);
bool8 BXPY_SummaryScreen_ShouldShowHiddenItem(enum PokemonSummaryScreenMode mode);
bool8 BXPY_SummaryScreen_ShouldShowFullItem(enum PokemonSummaryScreenMode mode);
const u8 *BXPY_ReturnItemText(enum Item item);
enum BXPYTeamPreviewSpeciesModes BXPY_GetEnemySpeciesVisibilityLevel(void);
enum BXPYTeamPreviewSpeciesModes BXPY_SummaryScreen_SpeciesVisibility(enum PokemonSummaryScreenMode mode);
bool8 BXPY_SummaryScreen_ShowBaseSpecies(enum PokemonSummaryScreenMode mode);
bool8 BXPY_SummaryScreen_HideSpecies(enum PokemonSummaryScreenMode mode);
bool8 BXPY_SummaryScreen_ShowTrueSpecies(enum PokemonSummaryScreenMode mode);
bool8 BXPY_ShouldHideEnemyGender(void);
bool8 BXPY_TeamPreview_ShouldHideEnemyGender(enum BattleSide side);
bool8 BXPY_SummaryScreen_ShouldHideEnemyGender(enum PokemonSummaryScreenMode mode);
u32 BXPY_SummaryScreen_TransformSpeciesId(enum PokemonSummaryScreenMode mode, u32 originalSpeciesId);
u32 BXPY_TeamPreview_TransformSpeciesId(u32 originalSpeciesId, enum BattleSide side);
u32 BXPY_TransformSpeciesId(u32 originalSpeciesId);
bool8 BXPY_ShouldHideEnemyLevel(void);
bool8 BXPY_TeamPreview_ShouldHideEnemyLevel(enum BattleSide side);
bool8 BXPY_SummaryScreen_ShouldHideEnemyLevel(enum PokemonSummaryScreenMode mode);
bool8 BXPY_SummaryScreen_ShouldHideStats(enum PokemonSummaryScreenMode mode, enum PokemonSummarySkillsMode stats);
void BXPY_GetEnemyEnterMons(enum BattlerId battler, u8* enteredMons, u32 pickSize);
void BXPY_SelectPartyMembers(struct Pokemon *party, u8* enteredMons, enum BattleTrainer trainer);
void BXPY_PreparePartiesAndInit(u32 bringSize, u32 pickSize, u32 battleFlags, u8* playerEnteredMons, u32 position, enum BXPYPages page, bool32 isFirstTime);
void BXPY_InitializeAndSaveCallback(u32 bringSize, u32 pickSize, u32 battleFlags, u8* playerEnteredMons, u32 position, enum BXPYPages page, bool32 isFirstTime);
bool8 BXPY_BattleGreaterThanTwoTrainers(void);

struct BXPYState
{
    void* savedCallback;
    u8 position;

    u8 monSpriteId[NUM_BATTLE_SIDES][PARTY_SIZE];
    u8 playerHpSpriteId[PARTY_SIZE];
    u8 genderSpriteId[NUM_BATTLE_SIDES][PARTY_SIZE];
    u8 playerSelectedSpriteId[PARTY_SIZE];
    u8 playerSelectedTailSpriteId[PARTY_SIZE];
    u8 enemyTypeSpriteId[PARTY_SIZE][2];
    u8 cursorSpriteId;
    u8 highlightSpriteId[3];

    u8 selectedMons[PARTY_SIZE];
    u32 battleFlags;
    u8 bringSize;
    u8 pickSize;
    struct Pokemon tempParty[PARTY_SIZE];
    u8 page;
    bool32 musicFlag;
};

struct BXPYSpriteSheet
{
    const struct SpriteSheet spriteSheet;
    const struct SpritePalette palette;
};

#endif // GUARD_BXPY_H
