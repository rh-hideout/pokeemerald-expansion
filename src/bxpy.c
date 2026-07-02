#include "global.h"
#include "battle.h"
#include "battle_main.h"
#include "battle_partner.h"
#include "battle_setup.h"
#include "bxpy.h"
#include "bxpy_ai.h"
#include "event_data.h"
#include "item.h"
#include "load_save.h"
#include "malloc.h"
#include "pokemon.h"
#include "pokemon_summary_screen.h"
#include "random.h"
#include "script_pokemon_util.h"
#include "string_util.h"
#include "task.h"
#include "tv.h"
#include "constants/battle.h"

static enum BXPYHealModes BXPY_GetHealMode(void);
static bool8 BXPY_ShouldHealBeforeBattle(void);
static bool8 BXPY_ShouldHealAfterBattle(void);
static void BXPY_ErrorCheck_BringSizeTooLarge(void);
static void BXPY_ErrorCheck_BringSizeNotEnough(void);
static void BXPY_FormatProblemListList(u32 *ids, u32 count, const u8 *(*getName)(u16));
static u32 BXPY_GetUniqueDuplicates(u32 *inputList, u32 inputCount, u32 *uniqueDuplicates);
static void BXPY_ErrorCheck_ClauseSpecies(void);
static void BXPY_ErrorCheck_ClauseItem(void);
static void BXPY_ErrorCheck_ClauseSpecialPokemon(void);
static void Debug_BXPY_PrintArguments(enum BXPYBattleTypes battleType, u32 bringSize, u32 pickSize, u32 trainerA, const u8 *loseTextA, u32 trainerB, const u8* loseTextB, u32 partnerId);
static void BXPY_InitTrainerBattleParams(u32 trainerA, const u8 *loseTextA, u32 trainerB, const u8* loseTextB, u32 partnerId);
static void BXPY_PrepareEnemyParty(u32 bringSize, u32 battleFlags);
static void BXPY_PrepareParty(u32 pickSize);
static void BXPY_DeleteNonAliveMons(void);
static u32 BXPY_ConvertBattleTypeToFlags(enum BXPYBattleTypes battleType);

static void (*const sBXPYErrorCheckFuncs[])(void) =
{
    [BXPY_ERROR_BRING_SIZE_TOO_LARGE] = BXPY_ErrorCheck_BringSizeTooLarge,
    [BXPY_ERROR_BRING_SIZE_NOT_ENOUGH] = BXPY_ErrorCheck_BringSizeNotEnough,
    [BXPY_ERROR_CLAUSE_SPECIES] = BXPY_ErrorCheck_ClauseSpecies,
    [BXPY_ERROR_CLAUSE_ITEM] = BXPY_ErrorCheck_ClauseItem,
    [BXPY_ERROR_CLAUSE_SPECIAL_POKEMON] = BXPY_ErrorCheck_ClauseSpecialPokemon,
};

STATIC_ASSERT((B_VAR_BXPY != 0 && B_VAR_BXPY <= VARS_END) || BXPY_RETAIN_CHANGES == FALSE, BVarSkyBattleMustBeSetForBXPYToRun);

void BXPY_OverworldRun_ErrorCheck_BringSizeTooLarge(void)
{
    sBXPYErrorCheckFuncs[BXPY_ERROR_BRING_SIZE_TOO_LARGE]();
}

void BXPY_OverworldRun_ErrorCheck_BringSizeNotEnough(void)
{
    sBXPYErrorCheckFuncs[BXPY_ERROR_BRING_SIZE_NOT_ENOUGH]();
}

void BXPY_OverworldRun_ErrorCheck_ClauseSpecies(void)
{
    sBXPYErrorCheckFuncs[BXPY_ERROR_CLAUSE_SPECIES]();
}

void BXPY_OverworldRun_ErrorCheck_ClauseItem(void)
{
    sBXPYErrorCheckFuncs[BXPY_ERROR_CLAUSE_ITEM]();
}

void BXPY_OverworldRun_ErrorCheck_ClauseSpecialPokemon(void)
{
    sBXPYErrorCheckFuncs[BXPY_ERROR_CLAUSE_SPECIAL_POKEMON]();
}

static enum BXPYHealModes BXPY_GetHealMode(void)
{
    return BXPY_HEAL;
}

static bool8 BXPY_ShouldHealBeforeBattle(void)
{
    enum BXPYHealModes mode = BXPY_GetHealMode();
    return (mode == BXPY_HEAL_BEFORE_BATTLE || mode == BXPY_HEAL_ALWAYS);
}

void BXPY_TryHealBeforeBattle(void)
{
    if (BXPY_ShouldHealBeforeBattle())
        HealPlayerParty();
}

static bool8 BXPY_ShouldHealAfterBattle(void)
{
    enum BXPYHealModes mode = BXPY_GetHealMode();
    return (mode == BXPY_HEAL_AFTER_BATTLE || mode == BXPY_HEAL_ALWAYS);
}

void BXPY_TryHealAfterBattle(void)
{
    if (!FlagGet(B_FLAG_BXPY))
        return;

    if (!BXPY_ShouldHealAfterBattle())
        return;

    HealPlayerParty();
}

static void BXPY_ErrorCheck_BringSizeTooLarge(void)
{
    gSpecialVar_Result = FALSE;

    u32 bringSize = VarGet(VAR_BXPY_BRING_SIZE);
    u32 maxSize = ((VarGet(VAR_BXPY_PARTNER) != PARTNER_NONE) && (B_MULTI_HALF_TEAMS == TRUE)) ? (bringSize / 2) : bringSize;
    u32 partyCount = CountPartyAliveNonEggMonsExcept(PARTY_SIZE);

    if (partyCount <=maxSize)
        return;

    gSpecialVar_Result = TRUE;

    ConvertIntToDecimalStringN(gStringVar1,maxSize,STR_CONV_MODE_LEFT_ALIGN,CountDigits(maxSize));
}

static void BXPY_ErrorCheck_BringSizeNotEnough(void)
{
    gSpecialVar_Result = FALSE;

    if (BXPY_FORCE_MINIMUM_MONS == FALSE)
        return;

    u32 bringSize = VarGet(VAR_BXPY_BRING_SIZE);
    u32 maxSize = ((VarGet(VAR_BXPY_PARTNER) != PARTNER_NONE) && (B_MULTI_HALF_TEAMS == TRUE)) ? (bringSize / 2) : bringSize;

    u32 partyCount = CountPartyAliveNonEggMonsExcept(PARTY_SIZE);

    if (partyCount >= maxSize)
        return;

    gSpecialVar_Result = TRUE;

    ConvertIntToDecimalStringN(gStringVar1,bringSize,STR_CONV_MODE_LEFT_ALIGN,CountDigits(bringSize));
}

static void BXPY_FormatProblemListList(u32 *ids, u32 count, const u8 *(*getName)(u16))
{
    StringCopy(gStringVar1,COMPOUND_STRING(""));

    for (u32 i = 0; i < count; i++)
    {
        if (i > 0)
        {
            if (i == count - 1)
                StringAppend(gStringVar1, COMPOUND_STRING(" & "));
            else
                StringAppend(gStringVar1, COMPOUND_STRING(",\l"));
        }

        StringAppend(gStringVar1, getName(ids[i]));
    }
}

static u32 BXPY_GetUniqueDuplicates(u32 *inputList, u32 inputCount, u32 *uniqueDuplicates)
{
    u32 duplicateCount = 0;

    for (u32 i = 0; i < inputCount; i++)
    {
        for (u32 j = i + 1; j < inputCount; j++)
        {

            if (inputList[i] == inputList[j])
            {
                bool32 alreadyFlagged = FALSE;
                for (u32 k = 0; k < duplicateCount; k++)
                {
                    if (uniqueDuplicates[k] == inputList[i])
                        alreadyFlagged = TRUE;
                }

                if (!alreadyFlagged)
                    uniqueDuplicates[duplicateCount++] = inputList[i];

                break;
            }
        }
    }
    return duplicateCount;
}

static void BXPY_ErrorCheck_ClauseSpecies(void)
{
    gSpecialVar_Result = FALSE;
    if (BXPY_CLAUSE_SPECIES == FALSE)
        return;

    u32 speciesList[PARTY_SIZE] = {0};
    u32 uniqueDuplicates[PARTY_SIZE] = {0};
    u32 partyCount = 0;

    for (u32 i = 0; i < PARTY_SIZE; i++)
    {
        u32 species = GetMonData(&gParties[B_TRAINER_PLAYER][i], MON_DATA_SPECIES_OR_EGG);
        if (species != SPECIES_NONE && species != SPECIES_EGG)
            speciesList[partyCount++] = species;
    }

    u32 duplicateCount = BXPY_GetUniqueDuplicates(speciesList, partyCount, uniqueDuplicates);

    if (duplicateCount == 0)
        return;

    gSpecialVar_Result = TRUE;
    BXPY_FormatProblemListList(uniqueDuplicates, duplicateCount, GetSpeciesName);
}

static void BXPY_ErrorCheck_ClauseItem(void)
{
    gSpecialVar_Result = FALSE;
    if (BXPY_CLAUSE_ITEMS == FALSE)
        return;
    u32 itemList[PARTY_SIZE] = {0};
    u32 uniqueDuplicates[PARTY_SIZE] = {0};
    u32 itemCount = 0;

    for (u32 i = 0; i < PARTY_SIZE; i++)
    {
        u32 item = GetMonData(&gParties[B_TRAINER_PLAYER][i], MON_DATA_HELD_ITEM);
        if (item != ITEM_NONE)
            itemList[itemCount++] = item;
    }

    u32 duplicateCount = BXPY_GetUniqueDuplicates(itemList, itemCount, uniqueDuplicates);

    if (duplicateCount == 0)
        return;

    gSpecialVar_Result = TRUE;
    BXPY_FormatProblemListList(uniqueDuplicates, duplicateCount, GetItemName);
}

static void BXPY_ErrorCheck_ClauseSpecialPokemon(void)
{
    gSpecialVar_Result = FALSE;
    if (BXPY_CLAUSE_SPECIAL_POKEMON == FALSE)
        return;

    u32 bannedMons[PARTY_SIZE];
    u32 bannedCount = 0;

    for (u32 i = 0; i < PARTY_SIZE; i++)
    {
        u32 species = GetMonData(&gParties[B_TRAINER_PLAYER][i], MON_DATA_SPECIES_OR_EGG);

        if (species == SPECIES_NONE || species == SPECIES_EGG)
            continue;

        if ((!gSpeciesInfo[species].isMythical) && (!gSpeciesInfo[species].isFrontierBanned))
            continue;

        bool32 alreadyAdded = FALSE;
        for (u32 k = 0; k < bannedCount; k++)
            if (bannedMons[k] == species)
                alreadyAdded = TRUE;

        if (!alreadyAdded)
            bannedMons[bannedCount++] = species;
    }

    if (bannedCount == 0)
        return;

    gSpecialVar_Result = TRUE;
    BXPY_FormatProblemListList(bannedMons, bannedCount, GetSpeciesName);
}

static void Debug_BXPY_PrintArguments(enum BXPYBattleTypes battleType, u32 bringSize, u32 pickSize, u32 trainerA, const u8 *loseTextA, u32 trainerB, const u8* loseTextB, u32 partnerId)
{
    return;
    DebugPrintf("battleType %d",battleType);
    DebugPrintf("bringSize %d",bringSize);
    DebugPrintf("pickSize %d",pickSize);
    DebugPrintf("trainerA %d",trainerA);
    DebugPrintf("loseTextA %S",loseTextA);
    DebugPrintf("trainerB %d",trainerB);
    if (loseTextB != NULL)
        DebugPrintf("loseTextB %S",loseTextB);
    DebugPrintf("partner %d",partnerId);
}

void BXPY_Init(enum BXPYBattleTypes battleType, u32 bringSize, u32 pickSize, u32 trainerA, const u8 *loseTextA, u32 trainerB, const u8* loseTextB, u32 partnerId)
{
    Debug_BXPY_PrintArguments(battleType,bringSize,pickSize,trainerA,loseTextA,trainerB,loseTextB,partnerId);
    BXPY_InitTrainerBattleParams(trainerA,loseTextA,trainerB,loseTextB,partnerId);
    u32 battleFlags = BXPY_ConvertBattleTypeToFlags(battleType);

    u8 playerEnteredMons[PARTY_SIZE];

    for (u32 monsIndex = 0; monsIndex < PARTY_SIZE; monsIndex++)
        playerEnteredMons[monsIndex] = BXPY_EMPTY_MON;

    BXPY_PreparePartiesAndInit(bringSize,pickSize,battleFlags,playerEnteredMons, 0, BXPY_PAGE_OPPONENT_A,TRUE);

}

void BXPY_PreparePartiesAndInit(u32 bringSize, u32 pickSize, u32 battleFlags, u8* playerEnteredMons, u32 position, enum BXPYPages page, bool32 isFirstTime)
{
    BXPY_PrepareEnemyParty(bringSize,battleFlags);
    BXPY_PrepareParty(pickSize);

    BXPY_InitializeAndSaveCallback(bringSize, pickSize, battleFlags,playerEnteredMons, position, page, isFirstTime);
}

static void BXPY_InitTrainerBattleParams(u32 trainerA, const u8 *loseTextA, u32 trainerB, const u8* loseTextB, u32 partnerId)
{
    InitTrainerBattleParameter();

    TRAINER_BATTLE_PARAM.opponentA = trainerA;
    TRAINER_BATTLE_PARAM.defeatTextA = (u8*)loseTextA;

    if (partnerId != PARTNER_NONE)
        gPartnerTrainerId = TRAINER_PARTNER(partnerId);

    if (trainerB == TRAINER_NONE)
        return;

    TRAINER_BATTLE_PARAM.opponentB = trainerB;
    TRAINER_BATTLE_PARAM.defeatTextB = (u8*)loseTextB;
}

static void BXPY_PrepareEnemyParty(u32 bringSize, u32 battleFlags)
{
    bool32 isMulti = BXPY_IsMultiBattle();

    ZeroEnemyPartyMons();
    CreateNPCTrainerPartyFromTrainer(&gParties[B_TRAINER_OPPONENT_A][0], &gTrainers[GetCurrentDifficultyLevel()][TRAINER_BATTLE_PARAM.opponentA]);

    if (isMulti == TRUE)
        CreateNPCTrainerPartyFromTrainer(&gParties[B_TRAINER_OPPONENT_B][0], &gTrainers[GetCurrentDifficultyLevel()][TRAINER_BATTLE_PARAM.opponentB]);
}

void BXPY_GetEnemyEnterMons(enum BattlerId battler, u8* enteredMons, u32 pickSize)
{
    for (u32 partyIndex = 0; partyIndex < PARTY_SIZE; partyIndex++)
        enteredMons[partyIndex] = BXPY_EMPTY_MON;

    for (u32 i = 0; i < PARTY_SIZE; i++)
        enteredMons[i] = PARTY_SIZE;

    struct BXPYAiPartyData *bxpyAiPartyData = Alloc(sizeof(struct BXPYAiPartyData));
    memset(bxpyAiPartyData, 0, sizeof(struct BXPYAiPartyData));

    // Do scoring
    BXPY_ScorePartyMons(battler, bxpyAiPartyData);

    // Store results
    u32 scoredMons[PARTY_SIZE];
    BXPY_GetChosenPartyMons(bxpyAiPartyData, scoredMons, pickSize);

    for (u32 i = 0; i < PARTY_SIZE; i++)
        enteredMons[i] = (i < pickSize) ? scoredMons[i] : PARTY_SIZE;

    Free(bxpyAiPartyData);
}

static void BXPY_PrepareParty(u32 pickSize)
{
    SavePlayerParty();
    BXPY_DeleteNonAliveMons();

    if (gPartnerTrainerId == PARTNER_NONE)
        return;

    FillPartnerParty(gPartnerTrainerId);
}

static void BXPY_DeleteNonAliveMons(void)
{
    for (u32 i = 0; i < PARTY_SIZE; i++)
    {
        u32 species = GetMonData(&gParties[B_TRAINER_PLAYER][i], MON_DATA_SPECIES_OR_EGG);
        if (species == SPECIES_NONE || species == SPECIES_EGG)
            ZeroMonData(&gParties[B_TRAINER_PLAYER][i]);

        u32 hp = GetMonData(&gParties[B_TRAINER_PLAYER][i], MON_DATA_HP);
        if (hp == 0)
            ZeroMonData(&gParties[B_TRAINER_PLAYER][i]);
    }
    CompactPartySlots();
}

void BXPY_SelectPartyMembers(struct Pokemon *party, u8* enteredMons, enum BattleTrainer trainer)
{
    struct Pokemon tempParty[PARTY_SIZE];
    u8 participatingPokemonSlot = 0;

    if (trainer == B_TRAINER_PLAYER)
        VarSet(B_VAR_SKY_BATTLE,0);

    for (u32 i = 0; i < PARTY_SIZE; i++)
        ZeroMonData(&tempParty[i]);

    for (u32 i = 0; i < PARTY_SIZE; i++)
    {
        u8 slot = enteredMons[i];
        if (slot == BXPY_EMPTY_MON)
            continue;

        if (trainer == B_TRAINER_PLAYER)
        {
            participatingPokemonSlot += 1 << slot;
            VarSet(B_VAR_SKY_BATTLE,participatingPokemonSlot);
        }

        CopyMon(&tempParty[i],&party[slot],sizeof(struct Pokemon));
    }

    for (u32 i = 0; i < PARTY_SIZE; i++)
        ZeroMonData(&party[i]);

    for (u32 i = 0; i < PARTY_SIZE; i++)
        CopyMon(&party[i],&tempParty[i],sizeof(struct Pokemon));
}

static u32 BXPY_ConvertBattleTypeToFlags(enum BXPYBattleTypes battleType)
{
    bool32 hasSecondEnemy = (TRAINER_BATTLE_PARAM.opponentB != TRAINER_NONE);
    bool32 hasPartner = (gPartnerTrainerId != PARTNER_NONE);

    if (hasSecondEnemy && hasPartner)
        return (BATTLE_TYPE_MULTI | BATTLE_TYPE_DOUBLE | BATTLE_TYPE_INGAME_PARTNER | BATTLE_TYPE_TWO_OPPONENTS | BATTLE_TYPE_TRAINER); // from battle_setup.c
    else if (hasSecondEnemy && !hasPartner)
        return (BATTLE_TYPE_DOUBLE | BATTLE_TYPE_TWO_OPPONENTS | BATTLE_TYPE_TRAINER); // from battle_setup.c
    else if (!hasSecondEnemy && hasPartner)
        return (BATTLE_TYPE_MULTI | BATTLE_TYPE_INGAME_PARTNER | BATTLE_TYPE_DOUBLE | BATTLE_TYPE_TRAINER); // from battle_setup.c
    else if (battleType == BXPY_BATTLE_SINGLE)
        return BATTLE_TYPE_TRAINER;
    else
        return (BATTLE_TYPE_DOUBLE | BATTLE_TYPE_TRAINER);
}

bool8 BXPY_IsSummaryScreenForEnemy(enum PokemonSummaryScreenMode mode)
{
    return (mode == SUMMARY_MODE_BXPY);
}

bool8 BXPY_ShouldHideEnemyAbility(enum PokemonSummaryScreenMode mode)
{
    if (BXPY_IsSummaryScreenForEnemy(mode) == FALSE)
        return FALSE;

    return (!BXPY_OPEN_TEAM_SHEET_SHOW_ENEMY_ABILITY);
}

bool8 BXPY_ShouldHideEnemyNature(enum PokemonSummaryScreenMode mode)
{
    if (BXPY_IsSummaryScreenForEnemy(mode) == FALSE)
        return FALSE;

    return (!BXPY_OPEN_TEAM_SHEET_SHOW_ENEMY_STAT_NATURE);
}

bool8 BXPY_ShouldHideEnemyIndividualValues(enum PokemonSummaryScreenMode mode, enum PokemonSummarySkillsMode stats)
{
    if (BXPY_IsSummaryScreenForEnemy(mode) == FALSE)
        return FALSE;

    if (stats != SUMMARY_SKILLS_MODE_IVS)
        return FALSE;

    return (!BXPY_OPEN_TEAM_SHEET_SHOW_ENEMY_STAT_IV);
}

bool8 BXPY_ShouldHideEnemyEffortValues(enum PokemonSummaryScreenMode mode, enum PokemonSummarySkillsMode stats)
{
    if (BXPY_IsSummaryScreenForEnemy(mode) == FALSE)
        return FALSE;

    if (stats != SUMMARY_SKILLS_MODE_EVS)
        return FALSE;

    return (!BXPY_OPEN_TEAM_SHEET_SHOW_ENEMY_STAT_EV);
}

bool8 BXPY_ShouldHideEnemyTeraType(enum PokemonSummaryScreenMode mode)
{
    if (BXPY_IsSummaryScreenForEnemy(mode) == FALSE)
        return FALSE;

    return (!BXPY_OPEN_TEAM_SHEET_SHOW_ENEMY_GIMMICK_TERA);
}

enum Type BXPY_TransformPageInfoType(enum PokemonSummaryScreenMode mode, enum Type originalTypeId, u32 spriteArrayId, u32 species)
{
    if (spriteArrayId == SUMMARY_SCREEN_SPRITE_ID_TYPE_TERA)
        return (BXPY_ShouldHideEnemyTeraType(mode)) ? TYPE_MYSTERY : originalTypeId;

    if (spriteArrayId != SUMMARY_SCREEN_SPRITE_ID_TYPE_1 && spriteArrayId != SUMMARY_SCREEN_SPRITE_ID_TYPE_2)
        return originalTypeId;

    enum BXPYTeamPreviewSpeciesModes speciesMode = BXPY_SummaryScreen_SpeciesVisibility(mode);
    u32 typeIndex = spriteArrayId - SPRITE_ARR_ID_TYPE;

    return BXPY_TransformType(speciesMode, originalTypeId, typeIndex, species);
}

enum Type BXPY_TransformType(enum BXPYTeamPreviewSpeciesModes mode, enum Type originalTypeId, u32 typeIndex, enum Species species)
{
    switch (mode)
    {
        case BXPY_SPECIES_HIDE:
            return TYPE_MYSTERY;
        case BXPY_SPECIES_SHOW_BASE:
            return GetSpeciesType(GET_BASE_SPECIES_ID(species), typeIndex);
        default:
        case BXPY_SPECIES_SHOW_TRUE:
            return originalTypeId;
    }
}

enum Type BXPY_TransformPageBattleMoves(enum PokemonSummaryScreenMode mode, enum Type originalTypeId, u32 spriteArrayId)
{
    if (spriteArrayId < SUMMARY_SCREEN_SPRITE_ID_TYPE_MOVE_1 || spriteArrayId > SUMMARY_SCREEN_SPRITE_ID_TYPE_MOVE_4)
        return originalTypeId;

    if (BXPY_ShouldHideEnemyMoves(mode))
        return TYPE_MYSTERY;

    return originalTypeId;
}

enum Type BXPY_TransformTypeIfHidden(enum PokemonSummaryScreenMode mode, enum Type originalTypeId, u32 spriteArrayId, u32 species, enum PokemonSummaryScreenPage page)
{
    if (!BXPY_IsSummaryScreenForEnemy(mode))
        return originalTypeId;

    switch (page)
    {
        case PSS_PAGE_INFO:
            return BXPY_TransformPageInfoType(mode, originalTypeId, spriteArrayId, species);
        case PSS_PAGE_BATTLE_MOVES:
            return BXPY_TransformPageBattleMoves(mode, originalTypeId, spriteArrayId);
        default:
            return originalTypeId;
    }
}

bool8 BXPY_ShouldHideEnemyMoves(enum PokemonSummaryScreenMode mode)
{
    if (BXPY_IsSummaryScreenForEnemy(mode) == FALSE)
        return FALSE;

    return (!BXPY_OPEN_TEAM_SHEET_SHOW_ENEMY_MOVE);
}

enum BXPYTeamPreviewItemModes BXPY_GetEnemyItemVisibilityLevel(void)
{
    return BXPY_OPEN_TEAM_SHEET_SHOW_ENEMY_ITEM;
}

bool8 BXPY_SummaryScreen_ItemVisibility(enum PokemonSummaryScreenMode mode)
{
    if (BXPY_IsSummaryScreenForEnemy(mode) == FALSE)
        return BXPY_ITEM_SHOW_ITEM;

    return BXPY_GetEnemyItemVisibilityLevel();
}

bool8 BXPY_SummaryScreen_ShouldHideItem(enum PokemonSummaryScreenMode mode)
{
    return (BXPY_GetEnemyItemVisibilityLevel() == BXPY_ITEM_NO_VISIBILITY);
}

bool8 BXPY_SummaryScreen_ShouldShowHiddenItem(enum PokemonSummaryScreenMode mode)
{
    return (BXPY_GetEnemyItemVisibilityLevel() == BXPY_ITEM_SHOW_POSSESSION);
}

bool8 BXPY_SummaryScreen_ShouldShowFullItem(enum PokemonSummaryScreenMode mode)
{
    return (BXPY_GetEnemyItemVisibilityLevel() == BXPY_ITEM_SHOW_ITEM);
}

const u8 *BXPY_ReturnItemText(enum Item item)
{
    static const u8 sText_Unknown[] = _("Unknown");
    static const u8 sText_Question[] = _("???");
    static const u8 sText_None[] = _("NONE");
    bool32 hasItem = (item != ITEM_NONE);

    switch (BXPY_GetEnemyItemVisibilityLevel())
    {
        default:
        case BXPY_ITEM_SHOW_ITEM:
            if (hasItem)
                return GetItemName(item);
            else
                return sText_None;
        case BXPY_ITEM_NO_VISIBILITY:
            return sText_Unknown;
        case BXPY_ITEM_SHOW_POSSESSION:
            if (hasItem)
                return sText_Question;
            else
                return sText_None;
    }
    return sText_Unknown;
}

enum BXPYTeamPreviewSpeciesModes BXPY_GetEnemySpeciesVisibilityLevel(void)
{
    return BXPY_TEAM_PREVIEW_SHOW_ENEMY_SPECIES;
}

enum BXPYTeamPreviewSpeciesModes BXPY_SummaryScreen_SpeciesVisibility(enum PokemonSummaryScreenMode mode)
{
    if (BXPY_IsSummaryScreenForEnemy(mode) == FALSE)
        return BXPY_SPECIES_SHOW_TRUE;

    return BXPY_GetEnemySpeciesVisibilityLevel();
}

bool8 BXPY_SummaryScreen_ShowBaseSpecies(enum PokemonSummaryScreenMode mode)
{
    if (BXPY_IsSummaryScreenForEnemy(mode) == FALSE)
        return FALSE;

    return (BXPY_GetEnemySpeciesVisibilityLevel() == BXPY_SPECIES_SHOW_BASE);
}

bool8 BXPY_SummaryScreen_HideSpecies(enum PokemonSummaryScreenMode mode)
{
    if (BXPY_IsSummaryScreenForEnemy(mode) == FALSE)
        return FALSE;

    return (BXPY_GetEnemySpeciesVisibilityLevel() == BXPY_SPECIES_HIDE);
}

bool8 BXPY_SummaryScreen_ShowTrueSpecies(enum PokemonSummaryScreenMode mode)
{
    if (BXPY_IsSummaryScreenForEnemy(mode) == FALSE)
        return TRUE;

    return (BXPY_GetEnemySpeciesVisibilityLevel() == BXPY_SPECIES_SHOW_TRUE);
}

bool8 BXPY_ShouldHideEnemyGender(void)
{
    return !(BXPY_TEAM_PREVIEW_SHOW_ENEMY_GENDER);
}

bool8 BXPY_TeamPreview_ShouldHideEnemyGender(enum BattleSide side)
{
    if (side == B_SIDE_PLAYER)
        return FALSE;

    return BXPY_ShouldHideEnemyGender();
}

bool8 BXPY_SummaryScreen_ShouldHideEnemyGender(enum PokemonSummaryScreenMode mode)
{
    if (BXPY_IsSummaryScreenForEnemy(mode) == FALSE)
        return FALSE;

    return BXPY_ShouldHideEnemyGender();
}

u32 BXPY_SummaryScreen_TransformSpeciesId(enum PokemonSummaryScreenMode mode, u32 originalSpeciesId)
{
    if (BXPY_IsSummaryScreenForEnemy(mode) == FALSE)
        return originalSpeciesId;

    return BXPY_TransformSpeciesId(originalSpeciesId);
}

u32 BXPY_TeamPreview_TransformSpeciesId(u32 originalSpeciesId, enum BattleSide side)
{
    if (side == B_SIDE_PLAYER)
        return originalSpeciesId;

    return BXPY_TransformSpeciesId(originalSpeciesId);
}

u32 BXPY_TransformSpeciesId(u32 originalSpeciesId)
{
    switch (BXPY_GetEnemySpeciesVisibilityLevel())
    {
    case BXPY_SPECIES_SHOW_TRUE:
        return originalSpeciesId;
    case BXPY_SPECIES_SHOW_BASE:
        return GET_BASE_SPECIES_ID(originalSpeciesId);
    default:
    case BXPY_SPECIES_HIDE:
        return SPECIES_NONE;
    }
}

bool8 BXPY_ShouldHideEnemyLevel(void)
{
    return !(BXPY_TEAM_PREVIEW_SHOW_ENEMY_LEVEL);
}

bool8 BXPY_TeamPreview_ShouldHideEnemyLevel(enum BattleSide side)
{
    if (side == B_SIDE_PLAYER)
        return FALSE;

    return BXPY_ShouldHideEnemyLevel();
}

bool8 BXPY_SummaryScreen_ShouldHideEnemyLevel(enum PokemonSummaryScreenMode mode)
{
    if (BXPY_IsSummaryScreenForEnemy(mode) == FALSE)
        return FALSE;

    return BXPY_ShouldHideEnemyLevel();
}

bool8 BXPY_SummaryScreen_ShouldHideStats(enum PokemonSummaryScreenMode mode, enum PokemonSummarySkillsMode stats)
{
    if (stats != SUMMARY_SKILLS_MODE_STATS)
        return FALSE;

    if (BXPY_IsSummaryScreenForEnemy(mode) == FALSE)
        return FALSE;

    if (BXPY_SummaryScreen_ShouldHideEnemyLevel(mode))
        return TRUE;

    if (BXPY_OPEN_TEAM_SHEET_SHOW_ENEMY_STAT_IV == FALSE)
        return TRUE;

    if (BXPY_OPEN_TEAM_SHEET_SHOW_ENEMY_STAT_EV == FALSE)
        return TRUE;

    return (BXPY_OPEN_TEAM_SHEET_SHOW_ENEMY_STAT_NATURE == FALSE);
}

