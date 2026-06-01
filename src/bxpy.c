#include "global.h"
#include "battle_main.h"
#include "battle_partner.h"
#include "battle_setup.h"
#include "bxpy.h"
#include "event_data.h"
#include "item.h"
#include "load_save.h"
#include "pokemon.h"
#include "pokemon_summary_screen.h"
#include "random.h"
#include "script_pokemon_util.h"
#include "string_util.h"
#include "task.h"
#include "tv.h"
#include "constants/battle.h"

static bool8 BXPY_IsSpriteIndexMon(enum BXPYSpriteIds spriteIndex);
static void BXPY_RemoveAllSprites(void);
static void BXPY_DrawPage(void);
static void BXPY_TogglePage(void);
static bool8 BXPY_IsMultiBattle(void);
static void BXPY_PreparePartiesAndInit(u32 bringSize, u32 pickSize, u32 battleFlags, u8* playerEnteredMons, u32 position, enum BXPYPages page);
static void BXPY_InitializeAndSaveCallback(u32 bringSize, u32 pickSize, u32 battleFlags, u8* playerEnteredMons, u32 position, enum BXPYPages page);
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
static void BXPY_GetEnemyEnterMons(u8* enteredMons, u32 pickSize);
static void BXPY_PrepareParty(u32 pickSize);
static void BXPY_DeleteNonAliveMons(void);
static void BXPY_SelectPartyMembers(struct Pokemon *party, u8* enteredMons);
static u32 BXPY_ConvertBattleTypeToFlags(enum BXPYBattleTypes battleType);
static void Task_BXPY_PartySelection(u8 taskId);

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
    if (FlagGet(B_FLAG_BXPY))
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
    u32 maxSize = (VarGet(VAR_BXPY_PARTNER) == PARTNER_NONE) ? bringSize : (bringSize / 2);

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

    for (u32 monsIndex = 0; monsIndex < ARRAY_COUNT(playerEnteredMons); monsIndex++)
        playerEnteredMons[monsIndex] = BXPY_EMPTY_MON;

    BXPY_PreparePartiesAndInit(bringSize,pickSize,battleFlags,playerEnteredMons, 0, BXPY_PAGE_OPPONENT_A);

}

static void BXPY_PreparePartiesAndInit(u32 bringSize, u32 pickSize, u32 battleFlags, u8* playerEnteredMons, u32 position, enum BXPYPages page)
{
    BXPY_PrepareEnemyParty(bringSize,battleFlags);
    BXPY_PrepareParty(pickSize);

    BXPY_InitializeAndSaveCallback(bringSize, pickSize, battleFlags,playerEnteredMons, position, page);
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
    bool32 isHalf = (B_MULTI_HALF_TEAMS && isMulti);

    ZeroEnemyPartyMons();
    CreateNPCTrainerPartyFromTrainer(&gParties[B_TRAINER_OPPONENT_A][0], &gTrainers[GetCurrentDifficultyLevel()][TRAINER_BATTLE_PARAM.opponentA], isHalf, battleFlags);

    if (isMulti == TRUE)
        CreateNPCTrainerPartyFromTrainer(&gParties[B_TRAINER_OPPONENT_B][0], &gTrainers[GetCurrentDifficultyLevel()][TRAINER_BATTLE_PARAM.opponentB], isHalf, battleFlags);
}

static void BXPY_GetEnemyEnterMons(u8* enteredMons, u32 pickSize)
{
    for (u32 partyIndex = 0; partyIndex < PARTY_SIZE; partyIndex++)
        enteredMons[partyIndex] = BXPY_EMPTY_MON;

    u32 mons[PARTY_SIZE] = {0, 1, 2, 3, 4, 5};

    for (u32 i = 0; i < PARTY_SIZE; i++)
        enteredMons[i] = PARTY_SIZE;

    // Start BXPY TODO Replace with Pawkkie's logic and UI output
    Shuffle(mons, ARRAY_COUNT(mons), sizeof(mons[0]));

    for (u32 i = 0; i < PARTY_SIZE; i++)
        enteredMons[i] = (i < pickSize) ? mons[i] : PARTY_SIZE;
    // End BXPY TODO Replace with Pawkkie's logic and UI output
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

static void BXPY_SelectPartyMembers(struct Pokemon *party, u8* enteredMons)
{
    struct Pokemon tempParty[PARTY_SIZE];
    u32 participatingPokemonSlot = 0;
    VarSet(B_VAR_SKY_BATTLE,0);

    for (u32 i = 0; i < PARTY_SIZE; i++)
        ZeroMonData(&tempParty[i]);

    for (u32 i = 0; i < PARTY_SIZE; i++)
    {
        u32 slot = enteredMons[i];
        if (slot == PARTY_SIZE)
            continue;

        participatingPokemonSlot += 1 << slot;
        VarSet(B_VAR_SKY_BATTLE,participatingPokemonSlot);

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

    switch (BXPY_SummaryScreen_SpeciesVisibility(mode))
    {
        case BXPY_SPECIES_HIDE:
            return TYPE_MYSTERY;
        case BXPY_SPECIES_SHOW_BASE:
            u32 typeIndex = spriteArrayId - SPRITE_ARR_ID_TYPE;
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
    return BXPY_TEAM_PREVIEW_SHOW_ENEMY_ITEM;
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

    if (BXPY_OPEN_TEAM_SHEET_SHOW_ENEMY_STAT_IV == TRUE)
        return FALSE;

    if (BXPY_OPEN_TEAM_SHEET_SHOW_ENEMY_STAT_EV == TRUE)
        return FALSE;

    return (!BXPY_OPEN_TEAM_SHEET_SHOW_ENEMY_STAT_NATURE);
}

// Start BXPY User Interface

#include "bg.h"
#include "window.h"
#include "trig.h"
#include "constants/rgb.h"
#include "constants/songs.h"
#include "dma3.h"
#include "gpu_regs.h"
#include "sprite.h"
#include "palette.h"
#include "pokemon_icon.h"
#include "scanline_effect.h"
#include "sound.h"
#include "string_util.h"
#include "overworld.h"
#include "menu_helpers.h"
#include "malloc.h"
#include "task.h"
#include "international_string_util.h"
#include "text.h"
#include "text_window.h"
#include "menu.h"


static void Task_BXPY_PartySelection(u8 taskId);
static void BXPY_ChangePosition(s32 delta);
static struct Pokemon *BXPY_GetParty(void);
static u8 BXPY_GetBringSize(void);
static void BXPY_SetPosition(u32 position);
static u8 BXPY_GetPosition(void);
static void BXPY_SetSpriteId(u32 spriteIndex, u32 spriteId);
static u8 BXPY_GetSpriteId(u32 spriteIndex);
static void BXPY_SetSelectedMons(u32 monIndex, u32 order);
bool8 BXPY_IsOpenTeamSheetOn(void);
static u8 BXPY_GetSelectedMons(u32 monIndex);
u32 IsDoingBringXPickYSelection(void);
static void BXPY_InitializeBackgroundsAndLoadBackgroundGraphics(void);
static void CB2_ReturnToBXPYInterface(void);
static void BXPY_CreateMonMenu(void);
static enum BattleTrainer BXPY_DetermineTrainer(enum BattleSide side, enum BXPYPages page);
static void Task_LoadPokemonSummary(u8 taskId);
static void BXPY_GoToPokemonSummary(u8 taskId);
static void BXPY_VBlankCB(void);
static void BXPY_MainCB(void);
static bool8 BXPY_InitalizeBackgrounds(void);
static bool8 AllocZeroedTilemapBuffers(void);
static void HandleAndShowBgs(void);
static void SetScheduleBgs(enum BXPYBackgrounds backgroundId);
static void BXPY_DisplayPartyMonText(enum BXPYWindows windowId, struct Pokemon *mon, enum BattleSide side, u32 partyMonIndex);
static void BXPY_SetPage(enum BXPYPages page);
static u32 BXPY_GetPage(void);
static void BXPY_SelectMonAndShowMenu(u8 taskId);
static bool8 BXPY_ShouldHandleMonsWithFullMenu(void);
static void Task_HandleMonMenu(u8 taskId);
static bool8 AreTilesOrTilemapEmpty(enum BXPYBackgrounds backgroundId);
static bool8 BXPY_IsCursorOnSelectedMon(void);
static bool8 BXPY_IsMultiBattle(void);
static void BXPY_SelectMonAndShowMenu(u8 taskId);
static void BXPY_ClearMenuReturnToMainTask(u8 taskId);
static void BXPY_HandleMonClearMenu(u8 taskId);
static bool8 BXPY_IsMonAlreadySelected(u32 partyMonIndex);
static u8 BXPY_GetOrderForMon(u32 monIndex);
static u32 BXPY_CountNumberSelected(void);
static void BXPY_CreateHighlightSprite(void);
static void SpriteCB_HighlightSprite(struct Sprite *sprite);
static void SpriteCB_SelectionSprite(struct Sprite *sprite);
static void BXPY_DrawOrderOnSelectionSprite(u32 spriteId, u32 index);
static void LoadGraphics(void);
static void LoadBXPYPalettes(void);
static void PlaySoundStartFadeQuitApp(u8 taskId);
static bool8 BXPY_HasSelectedEnough(void);
static u32 BXPY_CalculateCursorMonValue(enum BattleSide side);
static bool8 BXPY_IsCursorOnEnemy(void);
static bool8 BXPY_IsCursorOnEmpty(void);
static bool8 BXPY_IsCursorOnPartner(void);
static void BXPY_ResetAllSpriteIds(void);
static void Task_WaitFadeAndExitGracefully(u8 taskId);
void BXPY_FadescreenAndExitGracefully(void);
static void BXPY_FreeResources(void);
static void BXPY_FreeStructs(void);
static void BXPY_FreeBackgrounds(void);
static bool8 BXPY_AllocateStructs(void);
void BXPY_SetupCallback(void);
static void BXPY_CreateCursorSprite(void);
static void SpriteCB_BXPYCursor(struct Sprite *sprite);
static void BXPY_InitWindows(void);
static void BXPY_DisplayPlayerParty(void);
static void BXPY_DisplayEnemyParty(void);
static void BXPY_DisplayEnemyName(void);
static void BXPY_PrintEnemyName(enum BXPYWindows windowId);
static void BXPY_DisplayHelpBar(enum BXPYWindows windowId);
static void BXPY_PrintHelpBarText(enum BXPYWindows windowId);
static bool8 BXPY_IsCursorOnEnemy(void);
static void BXPY_DisplayParty(enum BattleSide side, bool32 cursorMove);
static void BXPY_DisplayPlayerPartyCursorMove(void);
static void BXPY_DisplayPlayerParty(void);
static void BXPY_DisplayPartyMonIcons(enum BXPYWindows windowId, struct Pokemon *mon, u32 partyMonIndex, enum BattleSide side, u32 species);
static void BXPY_PrintNickname(enum BXPYWindows windowId, struct Pokemon *mon, enum BattleSide side, u32 partyMonIndex);
static void BXPY_PrintItemName(enum BXPYWindows windowId, struct Pokemon *mon, enum BattleSide side, u32 partyMonIndex);
static void BXPY_PrintLevel(enum BXPYWindows windowId, struct Pokemon *mon, enum BattleSide side, u32 partyMonIndex);
static void BXPY_PrintSex(enum BXPYWindows windowId, struct Pokemon *mon, enum BattleSide side, u32 partyMonIndex);
static void BXPY_PrintMonIcon(enum BXPYWindows windowId, struct Pokemon *mon, enum BattleSide side, u32 partyMonIndex, u32 species);
static void BXPY_PrintHP(enum BXPYWindows windowId, struct Pokemon *mon, enum BattleSide side, u32 partyMonIndex);
static void BXPY_RemoveIndexFromSelected(u32 currentIndex);
static void BXPY_AddRemoveSelectedMon(void);

struct BXPYState *sBXPYState = NULL;
static u8 *sBgTilemapBuffer[BG_BXPY_COUNT] = {NULL};

static void Task_BXPY_PartySelection(u8 taskId)
{
    if (gPaletteFade.active)
        return;

    if (JOY_NEW(DPAD_LEFT) || JOY_REPEAT(DPAD_LEFT))
    {
        BXPY_ChangePosition(-6);
        BXPY_DisplayHelpBar(WIN_BXPY_HELP_BAR);
        BXPY_DisplayPlayerPartyCursorMove();
        return;
    }

    if (JOY_NEW(DPAD_RIGHT) || JOY_REPEAT(DPAD_RIGHT))
    {
        BXPY_ChangePosition(6);
        BXPY_DisplayHelpBar(WIN_BXPY_HELP_BAR);
        BXPY_DisplayPlayerPartyCursorMove();
        return;
    }

    if (JOY_NEW(DPAD_UP) || JOY_REPEAT(DPAD_UP))
    {
        BXPY_ChangePosition(-1);
        BXPY_DisplayHelpBar(WIN_BXPY_HELP_BAR);
        BXPY_DisplayPlayerPartyCursorMove();
        return;
    }

    if (JOY_NEW(DPAD_DOWN) || JOY_REPEAT(DPAD_DOWN))
    {
        BXPY_ChangePosition(1);
        BXPY_DisplayHelpBar(WIN_BXPY_HELP_BAR);
        BXPY_DisplayPlayerPartyCursorMove();
        return;
    }

    if (JOY_NEW(A_BUTTON) || JOY_REPEAT(A_BUTTON))
    {
        if (BXPY_IsCursorOnEmpty())
            return;
        else if (BXPY_IsCursorOnEnemy() && BXPY_IsOpenTeamSheetOn() == TRUE)
            BXPY_GoToPokemonSummary(taskId);
        else if (BXPY_IsCursorOnPartner())
            BXPY_GoToPokemonSummary(taskId);
        else if (BXPY_IsCursorOnEnemy() && BXPY_IsOpenTeamSheetOn() == FALSE)
            return;
        else
            BXPY_SelectMonAndShowMenu(taskId);
        return;
    }

    if (JOY_NEW(START_BUTTON) || JOY_REPEAT(START_BUTTON))
    {
        if (BXPY_HasSelectedEnough() == FALSE)
            return;

        PlaySoundStartFadeQuitApp(taskId);
    }

    if (JOY_NEW(SELECT_BUTTON) || JOY_REPEAT(SELECT_BUTTON))
    {
        if (BXPY_IsMultiBattle() == FALSE)
            return;

        BXPY_TogglePage();
        BXPY_DrawPage();
    }
}

static void BXPY_AddRemoveSelectedMon(void)
{
    u32 currentIndex = BXPY_GetPosition();

    if (BXPY_IsCursorOnSelectedMon())
    {
        BXPY_RemoveIndexFromSelected(currentIndex);
    }
    else
    {
        if (BXPY_HasSelectedEnough() == FALSE)
            BXPY_SetSelectedMons(BXPY_CountNumberSelected(),currentIndex);
    }

    BXPY_DisplayHelpBar(WIN_BXPY_HELP_BAR);
}

static void BXPY_RemoveIndexFromSelected(u32 currentIndex)
{
    u32 bringSize = min(BXPY_GetBringSize(),NUM_BXPY_MAX_MONS_SHOWED);
    u32 selectedIndex = 0;
    s32 retVal = -1;

    for (selectedIndex = 0; selectedIndex < bringSize; selectedIndex++)
        if (BXPY_GetSelectedMons(selectedIndex) == currentIndex)
            BXPY_SetSelectedMons(selectedIndex,BXPY_EMPTY_MON);

    u32 i, last;
    for (i = 0, last = 0; i < bringSize; i++)
    {
        u32 mon = (BXPY_GetSelectedMons(i));

        if (mon != BXPY_EMPTY_MON)
        {
            if (i != last)
                BXPY_SetSelectedMons(last,mon);
            last++;
        }
        else if (retVal == -1)
        {
            retVal = i;
        }
    }

    for (; last < bringSize; last++)
        BXPY_SetSelectedMons(last,BXPY_EMPTY_MON);
}

static struct Pokemon *BXPY_GetParty(void)
{
    return sBXPYState->tempParty;
}

static void BXPY_ChangePosition(s32 delta)
{
    u32 current = BXPY_GetPosition();
    s32 new = delta + current;
    u32 max = (PARTY_SIZE * 2) - 1;

    if (delta == 6)
    {
        if (new > max)
            new = current - 6;
    }
    else if (delta == -6)
    {
        if (new < 0)
            new = current + 6;
    }

    if (new < 0)
        new = max;

    if (new > max)
        new = 0;

    BXPY_SetPosition(new);
}

static void BXPY_SetPosition(u32 position)
{
    sBXPYState->position = position;
}

static u8 BXPY_GetPosition(void)
{
    return sBXPYState->position;
}

static u8 BXPY_GetBringSize(void)
{
    return sBXPYState->bringSize;
}

static void BXPY_SetBringSize(u32 bringSize)
{
    sBXPYState->bringSize = bringSize;
}

static u8 BXPY_GetPickSize(void)
{
    return sBXPYState->pickSize;
}

static void BXPY_SetPickSize(u32 pickSize)
{
    sBXPYState->pickSize = pickSize;
}

static void BXPY_SetBattleFlags(u32 battleFlags)
{
    sBXPYState->battleFlags = battleFlags;
}

static u32 BXPY_GetBattleFlags(void)
{
    return sBXPYState->battleFlags;
}

static void BXPY_SetPage(enum BXPYPages page)
{
    sBXPYState->page = page;
}

static u32 BXPY_GetPage(void)
{
    return sBXPYState->page;
}

static bool8 BXPY_IsOnPartnerPage(void)
{
    return (BXPY_GetPage() == BXPY_PAGE_OPPONENT_B);
}

static void BXPY_TogglePage(void)
{
    u32 newPage = (BXPY_GetPage() == BXPY_PAGE_OPPONENT_A) ? BXPY_PAGE_OPPONENT_B : BXPY_PAGE_OPPONENT_A;

    BXPY_SetPage(newPage);
}

static void BXPY_SetSpriteId(u32 spriteIndex, u32 spriteId)
{
    sBXPYState->spriteId[spriteIndex] = spriteId;
}

static u8 BXPY_GetSpriteId(u32 spriteIndex)
{
    return sBXPYState->spriteId[spriteIndex];
}

static void BXPY_SetSelectedMons(u32 monIndex, u32 order)
{
    sBXPYState->selectedMons[monIndex] = order;
}

static u8 BXPY_GetSelectedMons(u32 monIndex)
{
    return sBXPYState->selectedMons[monIndex];
}

u32 IsDoingBringXPickYSelection(void)
{
    return (FindTaskIdByFunc(Task_BXPY_PartySelection) != TASK_NONE);
}

static const struct BgTemplate sBXPYBgTemplates[] =
{
    [BG0_BXPY_TEXT] =
    {
        .bg = BG0_BXPY_TEXT,
        .charBaseIndex = 0,
        .mapBaseIndex = 31,
        .priority = 0,
    },
    [BG1_BXPY_INFO] =
    {
        .bg = BG1_BXPY_INFO,
        .charBaseIndex = 1,
        .mapBaseIndex = 30,
        .priority = 1,
    },
    [BG2_BXPY_PARTY_BG] =
    {
        .bg = BG2_BXPY_PARTY_BG,
        .charBaseIndex = 2,
        .mapBaseIndex = 29,
        .priority = 2,
    },
    [BG3_BXPY_WALLPAPER] =
    {
        .bg = BG3_BXPY_WALLPAPER,
        .charBaseIndex = 3,
        .mapBaseIndex = 28,
        .priority = 2,
    },
};

static const struct {
    const u32 *tiles;
    const u32 *tilemap;
} sBXPY_BackgroundGraphics[BG_BXPY_COUNT] =
{
    [BG0_BXPY_TEXT] =
    {
        .tiles = NULL,
        .tilemap = NULL,
    },
    [BG1_BXPY_INFO] =
    {
        .tiles = NULL,
        .tilemap = NULL,
    },
    [BG2_BXPY_PARTY_BG] =
    {
        .tiles = (const u32[])INCBIN_U32("graphics/bxpy/partyBg.4bpp.smol"),
        .tilemap = (const u32[])INCBIN_U32("graphics/bxpy/partyBg.bin.smolTM"),
    },
    [BG3_BXPY_WALLPAPER] =
    {
        .tiles = (const u32[])INCBIN_U32("graphics/bxpy/wallpaper.4bpp.smol"),
        .tilemap = (const u32[])INCBIN_U32("graphics/bxpy/wallpaper.bin.smolTM"),
    },
};

static const struct WindowTemplate sBXPYWindows[] =
{
    [WIN_BXPY_PLAYER_INFO] =
    {
        .bg = BG1_BXPY_INFO,
        .tilemapLeft = 2,
        .tilemapTop = 0,
        .width = 11,
        .height = 18,
        .paletteNum = BXPY_PALETTE_TEXT_ID,
    },
    [WIN_BXPY_ENEMY_NAME] =
    {
        .bg = BG1_BXPY_INFO,
        .tilemapLeft = 19,
        .tilemapTop = 0,
        .width = 9,
        .height = 2,
        .paletteNum = BXPY_PALETTE_TEXT_ID,
    },
    [WIN_BXPY_ENEMY_LEVELS] =
    {
        .bg = BG1_BXPY_INFO,
        .tilemapLeft = 23,
        .tilemapTop = 2,
        .width = 4,
        .height = 16,
        .paletteNum = BXPY_PALETTE_TEXT_ID,
    },
    [WIN_BXPY_HELP_BAR] =
    {
        .bg = BG1_BXPY_INFO,
        .tilemapLeft = 0,
        .tilemapTop = 18,
        .width = 30,
        .height = 2,
        .paletteNum = BXPY_PALETTE_TEXT_ID,
    },
    [WIN_BXPY_MENU] =
    {
        .bg = BG0_BXPY_TEXT,
        .tilemapLeft = 21,
        .tilemapTop = 12,
        .width = 8,
        .height = 6,
        .paletteNum = BXPY_PALETTE_MENU_ID,
    },
    [WIN_BXPY_MENU_FULL]
    {
        .bg = BG0_BXPY_TEXT,
        .tilemapLeft = 21,
        .tilemapTop = 14,
        .width = 8,
        .height = 4,
        .paletteNum = BXPY_PALETTE_MENU_ID,
    },
    DUMMY_WIN_TEMPLATE
};

const u8 sBXPYWindowFontColors[BXPY_FONT_COLOR_COUNT][3] =
{
    [BXPY_FONT_COLOR_PLAYER] =
    {
        BXPY_TEXT_PALETTE_TRANSPERANT,
        BXPY_TEXT_PALETTE_WHITE,
        BXPY_TEXT_PALETTE_BLUE,
    },
    [BXPY_FONT_COLOR_PLAYER_SELECTED] =
    {
        BXPY_TEXT_PALETTE_TRANSPERANT,
        BXPY_TEXT_PALETTE_BLACK,
        BXPY_TEXT_PALETTE_YELLOW,
    },
    [BXPY_FONT_COLOR_ENEMY_NAME] =
    {
        BXPY_TEXT_PALETTE_TRANSPERANT,
        BXPY_TEXT_PALETTE_WHITE,
        BXPY_TEXT_PALETTE_RED,
    },
    [BXPY_FONT_COLOR_ENEMY] =
    {
        BXPY_TEXT_PALETTE_TRANSPERANT,
        BXPY_TEXT_PALETTE_BLACK,
        BXPY_TEXT_PALETTE_GRAY,
    },
    [BXPY_FONT_COLOR_HELP_BAR] =
    {
        BXPY_TEXT_PALETTE_TRANSPERANT,
        BXPY_TEXT_PALETTE_WHITE,
        BXPY_TEXT_PALETTE_LIGHT_BLUE,
    },

};

static const struct BXPYSpriteSheet sBXPYSpriteSheets[BXPY_SPRITEID_COUNT] =
{
    [BXPY_SPRITEID_CURSOR] =
    {
        {
            .data = (const u16[])INCBIN_U16("graphics/bxpy/cursor.4bpp"),
            .size = TILE_OFFSET_4BPP(4),
            .tag = BXPY_SPRITETAG_CURSOR,
        },
        {
            .data = (const u16[])INCBIN_U16("graphics/bxpy/cursor.gbapal"),
            .tag = BXPY_PALTAG_SPRITE,
        },
    },
    [BXPY_SPRITEID_PLAYER_SEX_0] =
    {
        {
            .data = (const u16[])INCBIN_U16("graphics/bxpy/sex.4bpp"),
            .size = TILE_OFFSET_4BPP(12),
            .tag = BXPY_SPRITETAG_SEX,
        },
    },
    [BXPY_SPRITEID_PLAYER_SELECTED_0] =
    {
        {
            .data = (const u16[])INCBIN_U16("graphics/bxpy/selected.4bpp"),
            .size = TILE_OFFSET_4BPP(4),
            .tag = BXPY_SPRITETAG_SELECTED_0,
        },
    },
    [BXPY_SPRITEID_PLAYER_SELECTED_1] =
    {
        {
            .data = (const u16[])INCBIN_U16("graphics/bxpy/selected.4bpp"),
            .size = TILE_OFFSET_4BPP(4),
            .tag = BXPY_SPRITETAG_SELECTED_1,
        },
    },
    [BXPY_SPRITEID_PLAYER_SELECTED_2] =
    {
        {
            .data = (const u16[])INCBIN_U16("graphics/bxpy/selected.4bpp"),
            .size = TILE_OFFSET_4BPP(4),
            .tag = BXPY_SPRITETAG_SELECTED_2,
        },
    },
    [BXPY_SPRITEID_PLAYER_SELECTED_3] =
    {
        {
            .data = (const u16[])INCBIN_U16("graphics/bxpy/selected.4bpp"),
            .size = TILE_OFFSET_4BPP(4),
            .tag = BXPY_SPRITETAG_SELECTED_3,
        },
    },
    [BXPY_SPRITEID_PLAYER_SELECTED_4] =
    {
        {
            .data = (const u16[])INCBIN_U16("graphics/bxpy/selected.4bpp"),
            .size = TILE_OFFSET_4BPP(4),
            .tag = BXPY_SPRITETAG_SELECTED_4,
        },
    },
    [BXPY_SPRITEID_PLAYER_SELECTED_5] =
    {
        {
            .data = (const u16[])INCBIN_U16("graphics/bxpy/selected.4bpp"),
            .size = TILE_OFFSET_4BPP(4),
            .tag = BXPY_SPRITETAG_SELECTED_5,
        },
    },
    [BXPY_SPRITEID_PLAYER_HP_0] =
    {
        {
            .data = (const u16[])INCBIN_U16("graphics/bxpy/hp.4bpp"),
            .size = TILE_OFFSET_4BPP(128),
            .tag = BXPY_SPRITETAG_HP,
        },
    },
    [BXPY_SPRITEID_HIGHLIGHT_LEFT] =
    {
        {
            .data = (const u16[])INCBIN_U16("graphics/bxpy/highlight.4bpp"),
            .size = TILE_OFFSET_4BPP(32),
            .tag = BXPY_SPRITETAG_HIGHLIGHT,
        },
    }
};

static void BXPY_VBlankCB(void)
{
    LoadOam();
    ProcessSpriteCopyRequests();
    TransferPlttBuffer();
}

static void BXPY_MainCB(void)
{
    RunTasks();
    AnimateSprites();
    BuildOamBuffer();
    DoScheduledBgTilemapCopiesToVram();
    UpdatePaletteFade();
}

static bool8 BXPY_InitalizeBackgrounds(void)
{
    ResetAllBgsCoordinates();

    if (!AllocZeroedTilemapBuffers())
        return FALSE;

    HandleAndShowBgs();

    return TRUE;
}

static bool8 AllocZeroedTilemapBuffers(void)
{
    for (enum BXPYBackgrounds backgroundId = 0; backgroundId < BG_BXPY_COUNT; backgroundId++)
    {
        sBgTilemapBuffer[backgroundId] = AllocZeroed(BG_SCREEN_SIZE);

        if (sBgTilemapBuffer[backgroundId] == NULL)
            return FALSE;

        memset(sBgTilemapBuffer[backgroundId],0,BG_SCREEN_SIZE);
    }
    return TRUE;
}

static void HandleAndShowBgs(void)
{
    ResetBgsAndClearDma3BusyFlags(0);
    InitBgsFromTemplates(0, sBXPYBgTemplates, NELEMS(sBXPYBgTemplates));

    for (enum BXPYBackgrounds backgroundId = 0; backgroundId < BG_BXPY_COUNT; backgroundId++)
    {
        SetScheduleBgs(backgroundId);
        ShowBg(backgroundId);
    }
}

static void SetScheduleBgs(enum BXPYBackgrounds backgroundId)
{
    SetBgTilemapBuffer(backgroundId, sBgTilemapBuffer[backgroundId]);
    ScheduleBgCopyTilemapToVram(backgroundId);
}

static const u16 bxpyPalettesText[] = INCBIN_U16("graphics/bxpy/palettes/text.gbapal");
static const u16 bxpyBackgroundPalette[] = INCBIN_U16("graphics/bxpy/wallpaper.gbapal");

static bool8 AreTilesOrTilemapEmpty(enum BXPYBackgrounds backgroundId)
{
    return (sBXPY_BackgroundGraphics[backgroundId].tiles == NULL || sBXPY_BackgroundGraphics[backgroundId].tilemap == NULL);
}

static void LoadGraphics(void)
{
    ResetTempTileDataBuffers();

    for (enum BXPYBackgrounds backgroundId = BG0_BXPY_TEXT; backgroundId < BG_BXPY_COUNT; backgroundId++)
    {
        if (AreTilesOrTilemapEmpty(backgroundId))
            continue;

        DecompressAndLoadBgGfxUsingHeap(backgroundId, sBXPY_BackgroundGraphics[backgroundId].tiles,0,0,0);
        CopyToBgTilemapBuffer(backgroundId, sBXPY_BackgroundGraphics[backgroundId].tilemap,0,0);
    }

    LoadBXPYPalettes();

    for (u32 spriteId = 0; spriteId < BXPY_SPRITEID_COUNT; spriteId++)
    {
        if (sBXPYSpriteSheets[spriteId].spriteSheet.tag == 0)
            continue;

        LoadSpriteSheet(&sBXPYSpriteSheets[spriteId].spriteSheet);

        if (sBXPYSpriteSheets[spriteId].palette.tag == 0)
            continue;

        LoadSpritePalette(&sBXPYSpriteSheets[spriteId].palette);
    }
    CpuFill32(RGB_BLACK, gPlttBufferFaded, PLTT_SIZE);
}

static void LoadBXPYPalettes(void)
{
    LoadMonIconPalettes();
    LoadPalette(bxpyBackgroundPalette, BXPY_PALETTE_BG_SLOT, PLTT_SIZE_4BPP);
    LoadPalette(bxpyPalettesText, BXPY_PALETTE_TEXT_SLOT, PLTT_SIZE_4BPP);
}

static void PlaySoundStartFadeQuitApp(u8 taskId)
{
    PlaySE(SE_PC_OFF);
    BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 16, RGB_BLACK);
    gTasks[taskId].func = Task_WaitFadeAndExitGracefully;
}

static void Task_WaitFadeAndExitGracefully(u8 taskId)
{
    if (gPaletteFade.active)
        return;

    u8 playerEnteredMons[PARTY_SIZE];

    for (u32 partyIndex = 0; partyIndex < PARTY_SIZE; partyIndex++)
        playerEnteredMons[partyIndex] = BXPY_EMPTY_MON;

    for (u32 partyIndex = 0; partyIndex < PARTY_SIZE; partyIndex++)
        playerEnteredMons[partyIndex] = BXPY_GetSelectedMons(partyIndex);

    u8 enemyEnteredMons[PARTY_SIZE];
    BXPY_GetEnemyEnterMons(enemyEnteredMons,BXPY_GetPickSize());
    BXPY_SelectPartyMembers(gParties[B_TRAINER_PLAYER],playerEnteredMons);
    BXPY_SelectPartyMembers(gParties[B_TRAINER_OPPONENT_A],enemyEnteredMons);

    u32 temp = BXPY_GetBattleFlags();
    BXPY_FreeResources();
    DestroyTask(taskId);
    BattleSetup_StartBXPYBattle(temp);
}

void BXPY_FadescreenAndExitGracefully(void)
{
    BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 16, RGB_BLACK);
    CreateTask(Task_WaitFadeAndExitGracefully,0);
    SetVBlankCallback(BXPY_VBlankCB);
    SetMainCallback2(BXPY_MainCB);
}

static void FreeSpritePalettesResetSpriteData(void)
{
    ResetSpriteData();
    FreeSpriteTileRanges();
    FreeAllSpritePalettes();
    ClearDma3Requests();

}

static void BXPY_FreeResources(void)
{
    FreeSpritePalettesResetSpriteData();
    BXPY_FreeStructs();
    BXPY_FreeBackgrounds();
    FreeAllWindowBuffers();
    ResetSpriteData();
}

static void BXPY_FreeStructs(void)
{
    TRY_FREE_AND_SET_NULL(sBXPYState);
}

static void BXPY_FreeBackgrounds(void)
{
    for (enum BXPYBackgrounds backgroundId = 0; backgroundId < BG_BXPY_COUNT; backgroundId++)
        if (sBgTilemapBuffer[backgroundId] != NULL)
            TRY_FREE_AND_SET_NULL(sBgTilemapBuffer[backgroundId]);
}

static bool8 BXPY_AllocateStructs(void)
{
    sBXPYState = AllocZeroed(sizeof(struct BXPYState));

    return (sBXPYState == NULL);
}


void BXPY_SetupCallback(void)
{
    switch (gMain.state)
    {
        case 0:
            /*
            SetGpuReg(REG_OFFSET_DISPCNT, 0);
            SetGpuReg(REG_OFFSET_BG3CNT, 0);
            SetGpuReg(REG_OFFSET_BG2CNT, 0);
            SetGpuReg(REG_OFFSET_BG1CNT, 0);
            SetGpuReg(REG_OFFSET_BG0CNT, 0);
            ChangeBgX(0, 0, BG_COORD_SET);
            ChangeBgY(0, 0, BG_COORD_SET);
            ChangeBgX(1, 0, BG_COORD_SET);
            ChangeBgY(1, 0, BG_COORD_SET);
            ChangeBgX(2, 0, BG_COORD_SET);
            ChangeBgY(2, 0, BG_COORD_SET);
            ChangeBgX(3, 0, BG_COORD_SET);
            ChangeBgY(3, 0, BG_COORD_SET);
            SetGpuReg(REG_OFFSET_BLDCNT, 0);
            SetGpuReg(REG_OFFSET_BLDY, 0);
            SetGpuReg(REG_OFFSET_BLDALPHA, 0);
            SetGpuReg(REG_OFFSET_WIN0H, 0);
            SetGpuReg(REG_OFFSET_WIN0V, 0);
            SetGpuReg(REG_OFFSET_WIN1H, 0);
            SetGpuReg(REG_OFFSET_WIN1V, 0);
            SetGpuReg(REG_OFFSET_WININ, 0);
            SetGpuReg(REG_OFFSET_WINOUT, 0);
            CpuFill16(0, (void *)VRAM, VRAM_SIZE);
            CpuFill32(0, (void *)OAM, OAM_SIZE);
            */

            DmaClearLarge16(3, (void *)VRAM, VRAM_SIZE, 0x1000);
            SetVBlankHBlankCallbacksToNull();
            ClearScheduledBgCopiesToVram();
            gMain.state++;
            break;
        case 1:
            ScanlineEffect_Stop();
            ResetPaletteFade();
            ResetTasks();
            FreeSpritePalettesResetSpriteData();
            BXPY_ResetAllSpriteIds();
            gMain.state++;
            break;
        case 2:
            BXPY_InitializeBackgroundsAndLoadBackgroundGraphics();
            gMain.state++;
            break;
        case 3:
            BXPY_CreateCursorSprite();
            BXPY_InitWindows();
            BXPY_DrawPage();
            BXPY_CreateHighlightSprite();
            gMain.state++;
            break;
        case 4:
            CreateTask(Task_BXPY_PartySelection,0);
            BeginNormalPaletteFade(PALETTES_ALL, 0, 16, 0, RGB_BLACK);
            SetVBlankCallback(BXPY_VBlankCB);
            SetMainCallback2(BXPY_MainCB);
            break;
    }
}

static void SpriteCB_BXPYCursor(struct Sprite *sprite)
{
    u32 position = BXPY_GetPosition();

    if (BXPY_IsCursorOnEnemy())
    {
        u32 enemyPos = position - BXPY_GetBringSize();
        sprite->y = 16 + (enemyPos * 23);
        sprite->x2 = (gSineTable[(u8)sprite->data[0]] / 128) + 140;
        sprite->data[0] += 8;
    }
    else
    {
        sprite->y = 15 + (position * 23);
        sprite->x2 = gSineTable[(u8)sprite->data[0]] / 128;
        sprite->data[0] += 8;
    }
}

static void BXPY_CreateCursorSprite(void)
{
    struct SpriteTemplate TempSpriteTemplate = gDummySpriteTemplate;

    TempSpriteTemplate.tileTag = BXPY_SPRITETAG_CURSOR;
    TempSpriteTemplate.callback = SpriteCB_BXPYCursor;
    TempSpriteTemplate.paletteTag = BXPY_PALTAG_SPRITE;

    u32 spriteId = CreateSprite(&TempSpriteTemplate, 6, 15, 0);
    gSprites[spriteId].oam.shape = SPRITE_SHAPE(16x16);
    gSprites[spriteId].oam.size = SPRITE_SIZE(16x16);
    gSprites[spriteId].invisible = FALSE;
    gSprites[spriteId].oam.priority = 0;
    gSprites[spriteId].subpriority = 0;

    BXPY_SetSpriteId(BXPY_SPRITEID_CURSOR,spriteId);
}

static void ClearWindowCopyToVram(u32 windowId)
{
    FillWindowPixelBuffer(windowId, PIXEL_FILL(TEXT_COLOR_TRANSPARENT));
    PutWindowTilemap(windowId);
    CopyWindowToVram(windowId, COPYWIN_FULL);
}

static void BXPY_InitWindows(void)
{
    const struct WindowTemplate *templates = sBXPYWindows;

    InitWindows(templates);

    u32 baseBlock = 1;
    for (enum BXPYWindows windowId = 0; windowId < WIN_BXPY_COUNT; windowId++)
    {
        SetWindowAttribute(windowId, WINDOW_BASE_BLOCK, baseBlock);
        ClearWindowCopyToVram(windowId);
        baseBlock += (templates[windowId].width * templates[windowId].height);
    }
    DeactivateAllTextPrinters();
}

static void BXPY_DisplayParty(enum BattleSide side, bool32 cursorMove)
{
    u32 bringSize = min(BXPY_GetBringSize(),NUM_BXPY_MAX_MONS_SHOWED);
    enum BXPYWindows windowId = (side == B_SIDE_PLAYER) ? WIN_BXPY_PLAYER_INFO : WIN_BXPY_ENEMY_LEVELS;

    enum BattleTrainer trainer = BXPY_DetermineTrainer(side, BXPY_GetPage());

    FillWindowPixelBuffer(windowId, PIXEL_FILL(TEXT_COLOR_TRANSPARENT));

    for (u32 partyMonIndex = 0; partyMonIndex < bringSize; partyMonIndex++)
    {
        struct Pokemon *mon = &gParties[trainer][partyMonIndex];

        u32 species = GetMonData(mon,MON_DATA_SPECIES_OR_EGG);

        if (species == SPECIES_NONE)
            continue;

        if (species == SPECIES_EGG)
            continue;

        BXPY_DisplayPartyMonText(windowId, mon, side, partyMonIndex);

        if (cursorMove == TRUE)
            continue;

        BXPY_DisplayPartyMonIcons(windowId, mon, partyMonIndex, side, species);
    }

    CopyWindowToVram(windowId, COPYWIN_GFX);
}

static void BXPY_CreateSelectionSprite(u32 partyMonIndex, enum BattleSide side)
{
    if (side == B_SIDE_OPPONENT)
        return;

    u32 spriteIndex = (BXPY_SPRITEID_PLAYER_SELECTED_0 + partyMonIndex);

    if (BXPY_GetSpriteId(spriteIndex) != SPRITE_NONE)
        return;

    struct SpriteTemplate TempSpriteTemplate = gDummySpriteTemplate;

    TempSpriteTemplate.tileTag = spriteIndex;
    TempSpriteTemplate.callback = SpriteCB_SelectionSprite;
    TempSpriteTemplate.paletteTag = BXPY_PALTAG_SPRITE;

    u32 y = 12 + (23 * partyMonIndex);
    u32 spriteId = CreateSprite(&TempSpriteTemplate, 134, y, 0);
    gSprites[spriteId].data[1] = spriteId;
    gSprites[spriteId].data[2] = partyMonIndex;
    gSprites[spriteId].oam.shape = SPRITE_SHAPE(16x16);
    gSprites[spriteId].oam.size = SPRITE_SIZE(16x16);
    gSprites[spriteId].invisible = FALSE;
    gSprites[spriteId].oam.priority = 0;
    gSprites[spriteId].subpriority = 0;

    BXPY_SetSpriteId(spriteIndex,spriteId);
}

static void SpriteCB_SelectionSprite(struct Sprite *sprite)
{
    if (BXPY_IsOnPartnerPage())
    {
        sprite->invisible = TRUE;
        return;
    }

    u32 mon = sprite->data[2];
    bool32 isAlreadySelected = BXPY_IsMonAlreadySelected(mon);
    sprite->invisible = (isAlreadySelected == FALSE);

    u32 spriteId = sprite->data[1];

    BXPY_DrawOrderOnSelectionSprite(spriteId,BXPY_GetOrderForMon(mon));
}

static void BXPY_DrawOrderOnSelectionSprite(u32 spriteId, u32 index)
{
    index++;

    u32 max = min(BXPY_GetBringSize(),NUM_BXPY_MAX_MONS_SHOWED);

    if (index > max)
        return;

    u8* orderString = Alloc(BXPY_ORDER_LENGTH_SIZE);
    ConvertIntToDecimalStringN(orderString,index,STR_CONV_MODE_LEFT_ALIGN,CountDigits(index));

    u32 fontId = FONT_BXPY_LEVEL;
    u32 x = 7;
    u32 y = 0;

    AddSpriteTextPrinterParametrerized(spriteId, fontId, orderString, x, y, TEXT_SKIP_DRAW, NULL);

    Free(orderString);
}

static u8 BXPY_GetOrderForMon(u32 monIndex)
{
    u32 bringSize = min(BXPY_GetBringSize(),NUM_BXPY_MAX_MONS_SHOWED);
    for (u32 selectedIndex = 0; selectedIndex < bringSize; selectedIndex++)
        if (BXPY_GetSelectedMons(selectedIndex) == monIndex)
            return selectedIndex;

    return bringSize;
}

static bool8 BXPY_IsMonAlreadySelected(u32 partyMonIndex)
{
    u32 bringSize = min(BXPY_GetBringSize(),NUM_BXPY_MAX_MONS_SHOWED);
    for (u32 selectedIndex = 0; selectedIndex < bringSize; selectedIndex++)
        if (BXPY_GetSelectedMons(selectedIndex) == partyMonIndex)
            return TRUE;

    return FALSE;
}

static void BXPY_DisplayPlayerParty(void)
{
    BXPY_DisplayParty(B_SIDE_PLAYER,FALSE);
}

static void BXPY_DisplayPlayerPartyCursorMove(void)
{
    BXPY_DisplayParty(B_SIDE_PLAYER,TRUE);
}

static void BXPY_DisplayPartyMonText(enum BXPYWindows windowId, struct Pokemon *mon, enum BattleSide side, u32 partyMonIndex)
{
    BXPY_PrintNickname(windowId, mon, side, partyMonIndex);
    BXPY_PrintItemName(windowId, mon, side, partyMonIndex);
    BXPY_PrintLevel(windowId, mon, side, partyMonIndex);
}

static void BXPY_DisplayPartyMonIcons(enum BXPYWindows windowId, struct Pokemon *mon, u32 partyMonIndex, enum BattleSide side, u32 species)
{
    BXPY_PrintSex(windowId, mon, side, partyMonIndex);
    BXPY_PrintMonIcon(windowId, mon, side, partyMonIndex,species);
    BXPY_PrintHP(windowId, mon, side, partyMonIndex);
    BXPY_CreateSelectionSprite(partyMonIndex, side);
}

static void BXPY_PrintNickname(enum BXPYWindows windowId, struct Pokemon *mon, enum BattleSide side, u32 partyMonIndex)
{
    if (side == B_SIDE_OPPONENT)
        return;

    u32 x = 2;
    u32 y = 7 + (partyMonIndex * 23);
    u32 fontId = FONT_BXPY_SPECIES_NAME;
    u32 letterSpacing = GetFontAttribute(fontId, FONTATTR_LETTER_SPACING);
    u32 lineSpacing = GetFontAttribute(fontId, FONTATTR_LINE_SPACING);
    u32 windowWidth = BXPY_SPECIES_NICKNAME_WIDTH * TILE_SIZE_1BPP;
    u32 color = (BXPY_GetPosition() == partyMonIndex) ? BXPY_FONT_COLOR_PLAYER_SELECTED : BXPY_FONT_COLOR_PLAYER;

    GetMonData(mon,MON_DATA_NICKNAME,gStringVar1);
    fontId = GetFontIdToFit(gStringVar1,fontId,letterSpacing,windowWidth);

    AddTextPrinterParameterized4(windowId, fontId, x, y, letterSpacing, lineSpacing, sBXPYWindowFontColors[color], TEXT_SKIP_DRAW, gStringVar1);
}

static void BXPY_PrintItemName(enum BXPYWindows windowId, struct Pokemon *mon, enum BattleSide side, u32 partyMonIndex)
{
    if (side == B_SIDE_OPPONENT)
        return;

    u32 heldItem = GetMonData(mon,MON_DATA_HELD_ITEM);
    if (heldItem == ITEM_NONE)
        return;

    u32 x = 2;
    u32 y = 17 + (partyMonIndex * 23);
    u32 fontId = FONT_BXPY_SPECIES_NAME;
    u32 letterSpacing = GetFontAttribute(fontId, FONTATTR_LETTER_SPACING);
    u32 lineSpacing = GetFontAttribute(fontId, FONTATTR_LINE_SPACING);
    u32 windowWidth = BXPY_SPECIES_ITEM_WIDTH * TILE_SIZE_1BPP;
    u32 color = (BXPY_GetPosition() == partyMonIndex) ? BXPY_FONT_COLOR_PLAYER_SELECTED : BXPY_FONT_COLOR_PLAYER;

    StringCopy(gStringVar1,GetItemName(heldItem));
    fontId = GetFontIdToFit(gStringVar1,fontId,letterSpacing,windowWidth);

    AddTextPrinterParameterized4(windowId, fontId, x, y, letterSpacing, lineSpacing, sBXPYWindowFontColors[color], TEXT_SKIP_DRAW, gStringVar1);
}

static void BXPY_PrintLevel(enum BXPYWindows windowId, struct Pokemon *mon, enum BattleSide side, u32 partyMonIndex)
{
    u32 x = (side == B_SIDE_PLAYER) ? 68 : 8;
    u32 y = (side == B_SIDE_PLAYER) ? 7 + (partyMonIndex * 23) : 0 + (partyMonIndex * 22);
    u32 fontId = FONT_BXPY_LEVEL;
    u32 letterSpacing = GetFontAttribute(fontId, FONTATTR_LETTER_SPACING);
    u32 lineSpacing = GetFontAttribute(fontId, FONTATTR_LINE_SPACING);
    u32 color = 0;

    if (side == B_SIDE_OPPONENT)
        color = BXPY_FONT_COLOR_ENEMY;
    else if (BXPY_GetPosition() == partyMonIndex)
        color = BXPY_FONT_COLOR_PLAYER_SELECTED;
    else
        color = BXPY_FONT_COLOR_PLAYER;

    if (BXPY_TeamPreview_ShouldHideEnemyLevel(side))
        StringCopy(gStringVar2,COMPOUND_STRING("?"));
    else
        ConvertIntToDecimalStringN(gStringVar2,GetMonData(mon,MON_DATA_LEVEL),STR_CONV_MODE_LEFT_ALIGN,CountDigits(MAX_LEVEL));

    StringExpandPlaceholders(gStringVar1,COMPOUND_STRING("{LV}{STR_VAR_2}"));

    AddTextPrinterParameterized4(windowId, fontId, x, y, letterSpacing, lineSpacing, sBXPYWindowFontColors[color], TEXT_SKIP_DRAW, gStringVar1);
}

static const union AnimCmd sAnim_MonSexFemale[] =
{
    ANIMCMD_FRAME(BXPY_SEX_FRAME_FEMALE,4),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_MonSexMale[] =
{
    ANIMCMD_FRAME(BXPY_SEX_FRAME_MALE,4),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_MonSexHidden[] =
{
    ANIMCMD_FRAME(BXPY_SEX_FRAME_HIDDEN,4),
    ANIMCMD_END,
};

static const union AnimCmd * const sSpriteAnimTable_MonSexIcon[] =
{
    sAnim_MonSexFemale,
    sAnim_MonSexMale,
    sAnim_MonSexHidden,
};

static void BXPY_PrintSex(enum BXPYWindows windowId, struct Pokemon *mon, enum BattleSide side, u32 partyMonIndex)
{
    u32 sex = GetMonGender(mon);

    struct SpriteTemplate TempSpriteTemplate = gDummySpriteTemplate;

    TempSpriteTemplate.tileTag = BXPY_SPRITETAG_SEX;
    TempSpriteTemplate.callback = SpriteCallbackDummy;
    TempSpriteTemplate.paletteTag = BXPY_PALTAG_SPRITE;
    TempSpriteTemplate.anims = sSpriteAnimTable_MonSexIcon;

    u32 x = (side == B_SIDE_PLAYER) ? 96 : 220;
    u32 y = (side == B_SIDE_PLAYER) ?  24 + (partyMonIndex * 23) : 23 + (partyMonIndex * 22);
    u32 spriteId = CreateSprite(&TempSpriteTemplate, x, y, 0);
    gSprites[spriteId].oam.shape = SPRITE_SHAPE(16x16);
    gSprites[spriteId].oam.size = SPRITE_SIZE(16x16);
    gSprites[spriteId].oam.priority = 1;

    u32 animState = 0;

    if (BXPY_TeamPreview_ShouldHideEnemyGender(side))
    {
        animState = BXPY_SEX_HIDDEN;
    }
    else
    {
        animState = (sex == MON_FEMALE) ? BXPY_SEX_FEMALE : BXPY_SEX_MALE;
        gSprites[spriteId].invisible = (sex == MON_GENDERLESS);
    }

    StartSpriteAnimIfDifferent(&gSprites[spriteId],animState);
    u32 spriteIdStart = (side == B_SIDE_PLAYER) ? BXPY_SPRITEID_PLAYER_SEX_0 : BXPY_SPRITEID_ENEMY_SEX_0;
    BXPY_SetSpriteId(spriteIdStart + partyMonIndex,spriteId);
}

static void BXPY_PrintMonIcon(enum BXPYWindows windowId, struct Pokemon *mon, enum BattleSide side, u32 partyMonIndex, u32 species)
{
    u32 x = (side == B_SIDE_PLAYER) ? 119: 172;
    u32 y = (side == B_SIDE_PLAYER) ? 15 + (partyMonIndex * 23) : 20 + (partyMonIndex * 22);
    species = BXPY_TeamPreview_TransformSpeciesId(species, side);

    u32 spriteId = CreateMonIcon(species,SpriteCB_MonIcon,x,y,0,0);
    u32 spriteIdStart = (side == B_SIDE_PLAYER) ? BXPY_SPRITEID_PLAYER_MON_0 : BXPY_SPRITEID_ENEMY_MON_0;
    BXPY_SetSpriteId(spriteIdStart + partyMonIndex,spriteId);
}

static const union AnimCmd sAnim_MonHP0[] =
{
    ANIMCMD_FRAME(BXPY_HP_FRAME_0,4),
    ANIMCMD_END,
};
static const union AnimCmd sAnim_MonHP1[] =
{
    ANIMCMD_FRAME(BXPY_HP_FRAME_1,4),
    ANIMCMD_END,
};
static const union AnimCmd sAnim_MonHP2[] =
{
    ANIMCMD_FRAME(BXPY_HP_FRAME_2,4),
    ANIMCMD_END,
};
static const union AnimCmd sAnim_MonHP3[] =
{
    ANIMCMD_FRAME(BXPY_HP_FRAME_3,4),
    ANIMCMD_END,
};
static const union AnimCmd sAnim_MonHP4[] =
{
    ANIMCMD_FRAME(BXPY_HP_FRAME_4,4),
    ANIMCMD_END,
};
static const union AnimCmd sAnim_MonHP5[] =
{
    ANIMCMD_FRAME(BXPY_HP_FRAME_5,4),
    ANIMCMD_END,
};
static const union AnimCmd sAnim_MonHP6[] =
{
    ANIMCMD_FRAME(BXPY_HP_FRAME_6,4),
    ANIMCMD_END,
};
static const union AnimCmd sAnim_MonHP7[] =
{
    ANIMCMD_FRAME(BXPY_HP_FRAME_7,4),
    ANIMCMD_END,
};
static const union AnimCmd sAnim_MonHP8[] =
{
    ANIMCMD_FRAME(BXPY_HP_FRAME_8,4),
    ANIMCMD_END,
};
static const union AnimCmd sAnim_MonHP9[] =
{
    ANIMCMD_FRAME(BXPY_HP_FRAME_9,4),
    ANIMCMD_END,
};
static const union AnimCmd sAnim_MonHP10[] =
{
    ANIMCMD_FRAME(BXPY_HP_FRAME_10,4),
    ANIMCMD_END,
};
static const union AnimCmd sAnim_MonHP11[] =
{
    ANIMCMD_FRAME(BXPY_HP_FRAME_11,4),
    ANIMCMD_END,
};
static const union AnimCmd sAnim_MonHP12[] =
{
    ANIMCMD_FRAME(BXPY_HP_FRAME_12,4),
    ANIMCMD_END,
};
static const union AnimCmd sAnim_MonHP13[] =
{
    ANIMCMD_FRAME(BXPY_HP_FRAME_13,4),
    ANIMCMD_END,
};
static const union AnimCmd sAnim_MonHP14[] =
{
    ANIMCMD_FRAME(BXPY_HP_FRAME_14,4),
    ANIMCMD_END,
};
static const union AnimCmd sAnim_MonHP15[] =
{
    ANIMCMD_FRAME(BXPY_HP_FRAME_15,4),
    ANIMCMD_END,
};
static const union AnimCmd sAnim_MonHP16[] =
{
    ANIMCMD_FRAME(BXPY_HP_FRAME_16,4),
    ANIMCMD_END,
};
static const union AnimCmd sAnim_MonHP17[] =
{
    ANIMCMD_FRAME(BXPY_HP_FRAME_17,4),
    ANIMCMD_END,
};
static const union AnimCmd sAnim_MonHP18[] =
{
    ANIMCMD_FRAME(BXPY_HP_FRAME_18,4),
    ANIMCMD_END,
};
static const union AnimCmd sAnim_MonHP19[] =
{
    ANIMCMD_FRAME(BXPY_HP_FRAME_19,4),
    ANIMCMD_END,
};
static const union AnimCmd sAnim_MonHP20[] =
{
    ANIMCMD_FRAME(BXPY_HP_FRAME_20,4),
    ANIMCMD_END,
};
static const union AnimCmd sAnim_MonHP21[] =
{
    ANIMCMD_FRAME(BXPY_HP_FRAME_21,4),
    ANIMCMD_END,
};
static const union AnimCmd sAnim_MonHP22[] =
{
    ANIMCMD_FRAME(BXPY_HP_FRAME_22,4),
    ANIMCMD_END,
};
static const union AnimCmd sAnim_MonHP23[] =
{
    ANIMCMD_FRAME(BXPY_HP_FRAME_23,4),
    ANIMCMD_END,
};
static const union AnimCmd sAnim_MonHP24[] =
{
    ANIMCMD_FRAME(BXPY_HP_FRAME_24,4),
    ANIMCMD_END,
};
static const union AnimCmd sAnim_MonHP25[] =
{
    ANIMCMD_FRAME(BXPY_HP_FRAME_25,4),
    ANIMCMD_END,
};
static const union AnimCmd sAnim_MonHP26[] =
{
    ANIMCMD_FRAME(BXPY_HP_FRAME_26,4),
    ANIMCMD_END,
};
static const union AnimCmd sAnim_MonHP27[] =
{
    ANIMCMD_FRAME(BXPY_HP_FRAME_27,4),
    ANIMCMD_END,
};
static const union AnimCmd sAnim_MonHP28[] =
{
    ANIMCMD_FRAME(BXPY_HP_FRAME_28,4),
    ANIMCMD_END,
};
static const union AnimCmd sAnim_MonHP29[] =
{
    ANIMCMD_FRAME(BXPY_HP_FRAME_29,4),
    ANIMCMD_END,
};
static const union AnimCmd sAnim_MonHP30[] =
{
    ANIMCMD_FRAME(BXPY_HP_FRAME_30,4),
    ANIMCMD_END,
};
static const union AnimCmd sAnim_MonHP31[] =
{
    ANIMCMD_FRAME(BXPY_HP_FRAME_31,4),
    ANIMCMD_END,
};

static const union AnimCmd * const sSpriteAnimTable_MonHP[] =
{
    sAnim_MonHP0,
    sAnim_MonHP1,
    sAnim_MonHP2,
    sAnim_MonHP3,
    sAnim_MonHP4,
    sAnim_MonHP5,
    sAnim_MonHP6,
    sAnim_MonHP7,
    sAnim_MonHP8,
    sAnim_MonHP9,
    sAnim_MonHP10,
    sAnim_MonHP11,
    sAnim_MonHP12,
    sAnim_MonHP13,
    sAnim_MonHP14,
    sAnim_MonHP15,
    sAnim_MonHP16,
    sAnim_MonHP17,
    sAnim_MonHP18,
    sAnim_MonHP19,
    sAnim_MonHP20,
    sAnim_MonHP21,
    sAnim_MonHP22,
    sAnim_MonHP23,
    sAnim_MonHP24,
    sAnim_MonHP25,
    sAnim_MonHP26,
    sAnim_MonHP27,
    sAnim_MonHP28,
    sAnim_MonHP29,
    sAnim_MonHP30,
    sAnim_MonHP31,
};

static void BXPY_PrintHP(enum BXPYWindows windowId, struct Pokemon *mon, enum BattleSide side, u32 partyMonIndex)
{
    if (side == B_SIDE_OPPONENT)
        return;

    u32 current = GetMonData(mon,MON_DATA_HP);
    u32 max = GetMonData(mon,MON_DATA_MAX_HP);
    u32 percent = (current * BXPY_HP_STEP_COUNT / max) - 1;

    struct SpriteTemplate TempSpriteTemplate = gDummySpriteTemplate;

    TempSpriteTemplate.tileTag = BXPY_SPRITETAG_HP;
    TempSpriteTemplate.callback = SpriteCallbackDummy;
    TempSpriteTemplate.paletteTag = BXPY_PALTAG_SPRITE;
    TempSpriteTemplate.anims = sSpriteAnimTable_MonHP;

    u32 y = 29 + (partyMonIndex * 23);
    u32 spriteId = CreateSprite(&TempSpriteTemplate, 106, y, 0);
    gSprites[spriteId].oam.shape = SPRITE_SHAPE(32x8);
    gSprites[spriteId].oam.size = SPRITE_SIZE(32x8);
    gSprites[spriteId].oam.priority = 1;

    StartSpriteAnimIfDifferent(&gSprites[spriteId],percent);
    BXPY_SetSpriteId(BXPY_SPRITEID_PLAYER_HP_0 + partyMonIndex,spriteId);
}

static void BXPY_DisplayEnemyParty(void)
{
    BXPY_DisplayEnemyName();
    BXPY_DisplayParty(B_SIDE_OPPONENT,FALSE);
}

static void BXPY_DisplayEnemyName(void)
{
    enum BXPYWindows windowId = WIN_BXPY_ENEMY_NAME;

    FillWindowPixelBuffer(windowId, PIXEL_FILL(TEXT_COLOR_TRANSPARENT));
    BXPY_PrintEnemyName(windowId);
    CopyWindowToVram(windowId, COPYWIN_GFX);
}

static void BXPY_PrintEnemyName(enum BXPYWindows windowId)
{
    u32 y = 0;
    u32 fontId = FONT_BXPY_LEVEL;
    u32 lineSpacing = GetFontAttribute(fontId, FONTATTR_LINE_SPACING);
    u32 letterSpacing = GetFontAttribute(fontId, FONTATTR_LETTER_SPACING);
    u32 windowWidth = TILE_SIZE_1BPP * GetWindowAttribute(windowId, WINDOW_WIDTH);
    u32 trainerId = BXPY_IsOnPartnerPage() ? TRAINER_BATTLE_PARAM.opponentB : TRAINER_BATTLE_PARAM.opponentA;

    StringCopy(gStringVar4, GetTrainerNameFromId(trainerId));
    fontId = GetFontIdToFit(gStringVar4,fontId,letterSpacing,windowWidth);
    u32 x = GetStringRightAlignXOffset(fontId,gStringVar4,windowWidth);

    AddTextPrinterParameterized4(windowId, fontId, x, y, letterSpacing, lineSpacing, sBXPYWindowFontColors[BXPY_FONT_COLOR_ENEMY_NAME], TEXT_SKIP_DRAW, gStringVar4);
}

static void BXPY_DisplayHelpBar(enum BXPYWindows windowId)
{
    FillWindowPixelBuffer(windowId, PIXEL_FILL(TEXT_COLOR_TRANSPARENT));
    BXPY_PrintHelpBarText(windowId);
    CopyWindowToVram(windowId, COPYWIN_GFX);
}

static void BXPY_PrintHelpBarText(enum BXPYWindows windowId)
{
    u32 x = 4;
    u32 y = 0;
    u32 fontId = FONT_BXPY_HELPBAR;
    u32 lineSpacing = GetFontAttribute(fontId, FONTATTR_LINE_SPACING);
    u32 letterSpacing = GetFontAttribute(fontId, FONTATTR_LETTER_SPACING);

    StringCopy(gStringVar4, COMPOUND_STRING(""));

    if (BXPY_HasSelectedEnough() == FALSE)
    {
        u32 pickSize = BXPY_GetPickSize();
        ConvertIntToDecimalStringN(gStringVar1,pickSize,STR_CONV_MODE_LEFT_ALIGN,CountDigits(pickSize));
        StringAppend(gStringVar4, COMPOUND_STRING(" Select {STR_VAR_1} Pokemon."));
    }
    else
    {
        StringAppend(gStringVar4, COMPOUND_STRING(" {START_BUTTON} Start Battle"));
    }

    if (BXPY_IsCursorOnEnemy() && BXPY_IsOpenTeamSheetOn() == TRUE)
        StringAppend(gStringVar4,COMPOUND_STRING(" {A_BUTTON} Summary"));
    else if (BXPY_IsOnPartnerPage())
        StringAppend(gStringVar4,COMPOUND_STRING(" {A_BUTTON} Summary"));
    else if (!BXPY_IsCursorOnEnemy())
        StringAppend(gStringVar4,COMPOUND_STRING(" {A_BUTTON} Select"));

    if (BXPY_IsMultiBattle() && BXPY_IsOnPartnerPage() == FALSE)
        StringAppend(gStringVar4,COMPOUND_STRING(" {SELECT_BUTTON} See Partners"));
    else if (BXPY_IsMultiBattle() && BXPY_IsOnPartnerPage() == TRUE)
        StringAppend(gStringVar4,COMPOUND_STRING(" {SELECT_BUTTON} See {PLAYER}"));

    StringExpandPlaceholders(gStringVar4,gStringVar4);

    AddTextPrinterParameterized4(windowId, fontId, x, y, letterSpacing, lineSpacing, sBXPYWindowFontColors[BXPY_FONT_COLOR_HELP_BAR], TEXT_SKIP_DRAW, gStringVar4);
}

static bool8 BXPY_HasSelectedEnough(void)
{
    return (BXPY_CountNumberSelected() == BXPY_GetPickSize());
}

static u32 BXPY_CalculateCursorMonValue(enum BattleSide side)
{
    u32 position = BXPY_GetPosition();
    return (BXPY_IsCursorOnEnemy()) ? position - PARTY_SIZE : position;
}

static bool8 BXPY_IsCursorOnEmpty(void)
{
    enum BattleSide side = BXPY_IsCursorOnEnemy() ? B_SIDE_OPPONENT : B_SIDE_PLAYER;
    enum BattleTrainer trainer = BXPY_DetermineTrainer(side, BXPY_GetPage());
    u32 cursorMon = BXPY_CalculateCursorMonValue(side);
    u32 species = GetMonData(&gParties[trainer][cursorMon],MON_DATA_SPECIES_OR_EGG);

    if (species == SPECIES_NONE)
        return TRUE;

    return (species == SPECIES_EGG);
}

static bool8 BXPY_IsCursorOnEnemy(void)
{
    return BXPY_GetPosition() >= PARTY_SIZE;
}

static bool8 BXPY_IsCursorOnPartner(void)
{
    if (BXPY_IsOnPartnerPage() == FALSE)
        return FALSE;

    return (BXPY_IsCursorOnEnemy() == FALSE);
}

static bool8 BXPY_IsMultiBattle(void)
{
    if (TRAINER_BATTLE_PARAM.opponentB != TRAINER_NONE)
        return TRUE;

    return (gPartnerTrainerId != TRAINER_NONE);
}

static void BXPY_ResetAllSpriteIds(void)
{
    for (u32 spriteIndex = 0; spriteIndex < BXPY_SPRITEID_COUNT; spriteIndex++)
        BXPY_SetSpriteId(spriteIndex,SPRITE_NONE);
}

static void BXPY_InitializeBackgroundsAndLoadBackgroundGraphics(void)
{
    if (BXPY_InitalizeBackgrounds())
        LoadGraphics();
    else
        BXPY_FadescreenAndExitGracefully();
}

static u32 BXPY_CountNumberSelected(void)
{
    u32 count = 0;
    u32 bringSize = min(BXPY_GetBringSize(),NUM_BXPY_MAX_MONS_SHOWED);
    for (u32 selectedIndex = 0; selectedIndex < bringSize; selectedIndex++)
        if (BXPY_GetSelectedMons(selectedIndex) != BXPY_EMPTY_MON)
            count++;

    return count;
}

static void SpriteCB_HighlightSprite(struct Sprite *sprite)
{
    sprite->invisible = BXPY_IsCursorOnEnemy();
    sprite->y = 12 + (23 * BXPY_GetPosition());
}

static void BXPY_CreateHighlightSprite(void)
{
    for (u32 highlightIndex = 0; highlightIndex < 2; highlightIndex++)
    {
        struct SpriteTemplate TempSpriteTemplate = gDummySpriteTemplate;

        TempSpriteTemplate.tileTag = BXPY_SPRITETAG_HIGHLIGHT;
        TempSpriteTemplate.callback = SpriteCB_HighlightSprite;
        TempSpriteTemplate.paletteTag = BXPY_PALTAG_SPRITE;

        u32 x = (highlightIndex) ? 76 : 12;
        u32 spriteId = CreateSprite(&TempSpriteTemplate, x, 12, 0);
        gSprites[spriteId].oam.shape = SPRITE_SHAPE(64x32);
        gSprites[spriteId].oam.size = SPRITE_SIZE(64x32);
        gSprites[spriteId].oam.priority = 2;
        gSprites[spriteId].subpriority = 0;

        if (highlightIndex)
        {
            gSprites[spriteId].oam.matrixNum = ST_OAM_HFLIP;
            gSprites[spriteId].hFlip = TRUE;
        }

        BXPY_SetSpriteId(BXPY_SPRITEID_HIGHLIGHT_LEFT + highlightIndex,spriteId);
    }
}

static void BXPY_GoToPokemonSummary(u8 taskId)
{
    BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 16, RGB_BLACK);
    CreateTask(Task_LoadPokemonSummary,0);
    DestroyTask(taskId);
}

static void Task_LoadPokemonSummary(u8 taskId)
{
    if (gPaletteFade.active)
        return;

    DestroyTask(taskId);
    FreeAllWindowBuffers();

    enum BattleSide side = BXPY_IsCursorOnEnemy() ? B_SIDE_OPPONENT : B_SIDE_PLAYER;
    enum BattleTrainer trainer = BXPY_DetermineTrainer(side, BXPY_GetPage());
    u32 cursorMon = BXPY_CalculateCursorMonValue(side);
    u32 mode = (side == B_SIDE_PLAYER) ? SUMMARY_MODE_LOCK_MOVES : SUMMARY_MODE_BXPY;
    u32 partySize = CalculatePartyCount(trainer) - 1;
    ShowPokemonSummaryScreen(mode, &gParties[trainer], cursorMon, partySize, CB2_ReturnToBXPYInterface);
}

static void CB2_ReturnToBXPYInterface(void)
{
    u32 bringSize = BXPY_GetBringSize();
    u32 pickSize = BXPY_GetPickSize();
    u32 battleFlags = BXPY_GetBattleFlags();
    enum BXPYPages page = BXPY_GetPage();

    u32 old = BXPY_GetPosition();
    u32 new = VarGet(VAR_BXPY_MON_INDEX);
    u32 position = (old >= PARTY_SIZE) ? (new + PARTY_SIZE) : new;

    u8 playerEnteredMons[PARTY_SIZE];
    for (u32 partyIndex = 0; partyIndex < ARRAY_COUNT(playerEnteredMons); partyIndex++)
        playerEnteredMons[partyIndex] = BXPY_GetSelectedMons(partyIndex);

    BXPY_FreeResources();
    BXPY_PreparePartiesAndInit(bringSize,pickSize,battleFlags,playerEnteredMons,position,page);
}

static void BXPY_InitializeAndSaveCallback(u32 bringSize, u32 pickSize, u32 battleFlags, u8* playerEnteredMons, u32 position, enum BXPYPages page)
{
    if (BXPY_AllocateStructs())
    {
        SetMainCallback2(CB2_ReturnToFieldContinueScriptPlayMapMusic);
        return;
    }

    BXPY_SetPickSize(pickSize);
    BXPY_SetBringSize(bringSize);
    BXPY_SetBattleFlags(battleFlags);
    BXPY_SetPosition(position);
    BXPY_SetPage(page);

    for (u32 partyIndex = 0; partyIndex < PARTY_SIZE; partyIndex++)
         BXPY_SetSelectedMons(partyIndex,playerEnteredMons[partyIndex]);

    SetMainCallback2(BXPY_SetupCallback);
}

static const u8 sText_RemoveMenu[] = _("Remove\nSummary\nCancel");
static const u8 sText_AddMenu[] = _("Add\nSummary\nCancel");
static const u8 sText_FullMenu[] = _("Summary\nCancel");

static bool8 BXPY_IsCursorOnSelectedMon(void)
{
    u32 currentIndex = BXPY_GetPosition();
    return BXPY_IsMonAlreadySelected(currentIndex);
}

static void BXPY_SelectMonAndShowMenu(u8 taskId)
{
    BXPY_CreateMonMenu();
    gTasks[taskId].func = Task_HandleMonMenu;
}

static void BXPY_HandleMonClearMenu(u8 taskId)
{
    BXPY_AddRemoveSelectedMon();
    BXPY_ClearMenuReturnToMainTask(taskId);
}

static void BXPY_ClearMenuReturnToMainTask(u8 taskId)
{
    ClearStdWindowAndFrameToTransparent(WIN_BXPY_MENU_FULL,TRUE);
    ClearStdWindowAndFrameToTransparent(WIN_BXPY_MENU,TRUE);
    gTasks[taskId].func = Task_BXPY_PartySelection;
}

static void Task_HandleMonMenu(u8 taskId)
{
    //s8 input = Menu_ProcessInputNoWrapClearOnChoose();
    s8 input = Menu_ProcessInput();

    if (input == MENU_B_PRESSED || input == BXPY_MENU_CANCEL)
    {
        BXPY_ClearMenuReturnToMainTask(taskId);
    }
    else if (input == BXPY_MENU_SUMMARY_MON)
    {
        if (BXPY_ShouldHandleMonsWithFullMenu())
            BXPY_ClearMenuReturnToMainTask(taskId);
        else
            BXPY_GoToPokemonSummary(taskId);
    }
    else if (input == BXPY_MENU_ADD_MON)
    {
        if (BXPY_ShouldHandleMonsWithFullMenu())
            BXPY_GoToPokemonSummary(taskId);
        else
            BXPY_HandleMonClearMenu(taskId);
    }
}

static bool8 BXPY_ShouldHandleMonsWithFullMenu(void)
{
    return ((BXPY_IsCursorOnSelectedMon() == FALSE) && (BXPY_HasSelectedEnough()));
}

static void BXPY_CreateMonMenu(void)
{
    struct TextPrinterTemplate printer;
    u32 baseTileNum = 1;
    u32 windowId = BXPY_ShouldHandleMonsWithFullMenu() ? WIN_BXPY_MENU_FULL : WIN_BXPY_MENU;

    LoadUserWindowBorderGfx(windowId,baseTileNum,BXPY_PALETTE_BORDER_SLOT);
    DrawStdFrameWithCustomTileAndPalette(windowId, TRUE, baseTileNum, BXPY_PALETTE_BORDER_ID);

    if (BXPY_IsCursorOnSelectedMon())
        printer.currentChar = sText_RemoveMenu;
    else if (BXPY_HasSelectedEnough())
        printer.currentChar = sText_FullMenu;
    else
        printer.currentChar = sText_AddMenu;

    printer.type = WINDOW_TEXT_PRINTER;
    printer.windowId = windowId;
    printer.fontId = FONT_NORMAL;
    printer.x = 8;
    printer.y = 1;
    printer.currentX = printer.x;
    printer.currentY = printer.y;
    printer.color.foreground = GetFontAttribute(FONT_NORMAL, FONTATTR_COLOR_FOREGROUND);
    printer.color.background = GetFontAttribute(FONT_NORMAL, FONTATTR_COLOR_BACKGROUND);
    printer.color.shadow = GetFontAttribute(FONT_NORMAL, FONTATTR_COLOR_SHADOW);
    printer.color.accent = GetFontAttribute(FONT_NORMAL, FONTATTR_COLOR_ACCENT);
    printer.letterSpacing = 0;
    printer.lineSpacing = 0;

    u32 menuCount = (BXPY_HasSelectedEnough()) ? BXPY_MENU_COUNT - 1 : BXPY_MENU_COUNT;
    AddTextPrinter(&printer, TEXT_SKIP_DRAW, NULL);
    InitMenuInUpperLeftCornerNormal(windowId, menuCount, 0);
}

bool8 BXPY_IsOpenTeamSheetOn(void)
{
    return BXPY_OPEN_TEAM_SHEET;
}

static enum BattleTrainer BXPY_DetermineTrainer(enum BattleSide side, enum BXPYPages page)
{
    if (side == B_SIDE_PLAYER)
    {
        if (page == BXPY_PAGE_OPPONENT_A)
            return B_TRAINER_PLAYER;
        else
            return B_TRAINER_PARTNER;
    }
    else
    {
        if (page == BXPY_PAGE_OPPONENT_A)
            return B_TRAINER_OPPONENT_A;
        else
            return B_TRAINER_OPPONENT_B;
    }
}

static void BXPY_DrawPage(void)
{

    BXPY_RemoveAllSprites();
    BXPY_DisplayPlayerParty();
    BXPY_DisplayEnemyParty();
    BXPY_DisplayHelpBar(WIN_BXPY_HELP_BAR);
}

static void BXPY_RemoveSprite(enum BXPYSpriteIds first, enum BXPYSpriteIds last)
{
    for (u32 spriteIndex = first; spriteIndex < last + 1; spriteIndex++)
    {
        u32 spriteId = (BXPY_GetSpriteId(spriteIndex));
        if (spriteId == SPRITE_NONE)
            continue;

        if (BXPY_IsSpriteIndexMon(spriteIndex))
            FreeAndDestroyMonIconSprite(&gSprites[spriteId]);
        else
            DestroySpriteAndFreeResources(&gSprites[spriteId]);

        BXPY_SetSpriteId(spriteIndex,SPRITE_NONE);
    }
}

static void BXPY_RemovePlayerMonSprites(void)
{
    BXPY_RemoveSprite(BXPY_SPRITEID_PLAYER_MON_0,BXPY_SPRITEID_PLAYER_MON_5);
}
static void BXPY_RemovePlayerHPSprites(void)
{
    BXPY_RemoveSprite(BXPY_SPRITEID_PLAYER_HP_0,BXPY_SPRITEID_PLAYER_HP_5);
}
static void BXPY_RemovePlayerSexSprites(void)
{
    BXPY_RemoveSprite(BXPY_SPRITEID_PLAYER_SEX_0,BXPY_SPRITEID_PLAYER_SEX_5);
}
static void BXPY_RemoveEnemyMonSprites(void)
{
    BXPY_RemoveSprite(BXPY_SPRITEID_ENEMY_MON_0,BXPY_SPRITEID_ENEMY_MON_5);
}
static void BXPY_RemoveEnemySexSprites(void)
{
    BXPY_RemoveSprite(BXPY_SPRITEID_ENEMY_SEX_0,BXPY_SPRITEID_ENEMY_SEX_5);
}

static void BXPY_RemoveAllSprites(void)
{
    BXPY_RemovePlayerMonSprites();
    BXPY_RemovePlayerHPSprites();
    BXPY_RemovePlayerSexSprites();
    BXPY_RemoveEnemyMonSprites();
    BXPY_RemoveEnemySexSprites();
}

static bool8 BXPY_IsSpriteIndexMon(enum BXPYSpriteIds spriteIndex)
{
    u32 monSpriteIds[] =
    {
        BXPY_SPRITEID_PLAYER_MON_0,
        BXPY_SPRITEID_PLAYER_MON_1,
        BXPY_SPRITEID_PLAYER_MON_2,
        BXPY_SPRITEID_PLAYER_MON_3,
        BXPY_SPRITEID_PLAYER_MON_4,
        BXPY_SPRITEID_PLAYER_MON_5,
        BXPY_SPRITEID_ENEMY_MON_0,
        BXPY_SPRITEID_ENEMY_MON_1,
        BXPY_SPRITEID_ENEMY_MON_2,
        BXPY_SPRITEID_ENEMY_MON_3,
        BXPY_SPRITEID_ENEMY_MON_4,
        BXPY_SPRITEID_ENEMY_MON_5,
    };

    for (u32 index = 0; index < ARRAY_COUNT(monSpriteIds); index++)
        if (spriteIndex == monSpriteIds[index])
            return TRUE;

    return FALSE;
}
