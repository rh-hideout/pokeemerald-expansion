#ifndef GUARD_BXPY_H
#define GUARD_BXPY_H

#include "pokemon_summary_screen.h"
#include "constants/bxpy.h"

void BXPY_OverworldRun_ErrorCheck_BringSizeTooLarge(void);
void BXPY_OverworldRun_ErrorCheck_BringSizeNotEnough(void);
void BXPY_OverworldRun_ErrorCheck_ClauseSpecies(void);
void BXPY_OverworldRun_ErrorCheck_ClauseItem(void);
void BXPY_OverworldRun_ErrorCheck_ClauseUbers(void);
void BXPY_Init(enum BXPYBattleTypes battleType, u32 bringSize, u32 pickSize, u32 trainerA, const u8 *loseTextA, u32 trainerB, const u8* loseTextB, u32 partner);
void BXPY_TryHealAfterBattle(void);
void BXPY_TryHealBeforeBattle(void);

bool8 BXPY_ShouldHideEnemyAbility(enum PokemonSummaryScreenMode mode);
bool8 BXPY_ShouldHideEnemyNature(enum PokemonSummaryScreenMode mode);
bool8 BXPY_ShouldHideEnemyEffortValues(enum PokemonSummaryScreenMode mode, enum PokemonSummarySkillsMode stats);
bool8 BXPY_ShouldHideEnemyIndividualValues(enum PokemonSummaryScreenMode mode, enum PokemonSummarySkillsMode stats);
bool8 BXPY_ShouldHideEnemyTeraType(enum PokemonSummaryScreenMode mode);
bool8 BXPY_ShouldHideEnemyMoves(enum PokemonSummaryScreenMode mode);
enum BXPYTeamPreviewItemModes BXPY_GetEnemyItemVisibilityLevel(void);
bool8 BXPY_SummaryScreen_ItemVisibility(enum PokemonSummaryScreenMode mode);
const u8 *BXPY_ReturnItemText(enum Item item);
enum BXPYTeamPreviewSpeciesModes BXPY_GetEnemySpeciesVisibilityLevel(void);
enum BXPYTeamPreviewSpeciesModes BXPY_SummaryScreen_SpeciesVisibility(enum PokemonSummaryScreenMode mode);
bool8 BXPY_TeamPreview_ShouldHideEnemyGender(void);
bool8 BXPY_SummaryScreen_ShouldHideEnemyGender(enum PokemonSummaryScreenMode mode);
enum Type BXPY_TransformTypeIfHidden(enum PokemonSummaryScreenMode mode, enum Type originalTypeId, u32 spriteArrayId, u32 species, enum PokemonSummaryScreenPage page);
bool8 BXPY_SummaryScreen_ShowTrueSpecies(enum PokemonSummaryScreenMode mode);
bool8 BXPY_SummaryScreen_HideSpecies(enum PokemonSummaryScreenMode mode);
bool8 BXPY_SummaryScreen_ShowBaseSpecies(enum PokemonSummaryScreenMode mode);
u32 BXPY_SummaryScreen_TransformSpeciesId(enum PokemonSummaryScreenMode mode, u32 originalSpeciesId);
bool8 BXPY_SummaryScreen_ShouldShowFullItem(enum PokemonSummaryScreenMode mode);
bool8 BXPY_SummaryScreen_ShouldHideEnemyLevel(enum PokemonSummaryScreenMode mode);
u32 BXPY_TeamPreview_TransformSpeciesId(u32 originalSpeciesId);
bool8 BXPY_SummaryScreen_ShouldHideStats(enum PokemonSummaryScreenMode mode, enum PokemonSummarySkillsMode stats);
u32 IsDoingBringXPickYSelection(void);

#include "sprite.h"

struct BXPYState
{
    void* savedCallback;
    u8 position;
    u8 spriteId[BXPY_SPRITEID_COUNT];
    u8 selectedMons[PARTY_SIZE];
    u32 battleFlags;
    u8 bringSize;
    u8 pickSize;
};

struct BXPYSpriteSheet
{
    const struct SpriteSheet spriteSheet;
    const struct SpritePalette palette;
};


#endif // GUARD_BXPY_H
