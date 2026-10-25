#include "global.h"
#include "main.h"
#include "battle.h"
#include "battle_main.h"
#include "battle_frontier.h"
#include "battle_setup.h"
#include "battle_dome.h"
#include "battle_factory.h"
#include "battle_partner.h"
#include "battle_tent.h"
#include "battle_tower.h"
#include "battle_transition.h"
#include "event_data.h"
#include "frontier_util.h"
#include "overworld.h"
#include "script.h"
#include "string_util.h"
#include "task.h"
#include "text.h"
#include "trainer_util.h"
#include "constants/abilities.h"
#include "constants/battle_frontier.h"
#include "constants/battle_frontier_mons.h"
#include "constants/battle_tent_mons.h"

static void FillTrainerParty(u16 trainerId, enum BattleTrainer trainer, u8 monCount);

// EWRAM vars.
EWRAM_DATA const struct BattleFrontierTrainer *gFacilityTrainers = NULL;
EWRAM_DATA const struct TrainerMon *gFacilityTrainerMons = NULL;

// IWRAM common
COMMON_DATA u16 gFrontierTempParty[MAX_FRONTIER_PARTY_SIZE] = {0};

static void HandleFacilityTrainerBattleEnd(void)
{
    u8 facility = gBattleScripting.specialTrainerBattleType;
    switch (facility)
    {
    case FACILITY_BATTLE_TOWER:
    case FACILITY_BATTLE_DOME:
    case FACILITY_BATTLE_PALACE:
    case FACILITY_BATTLE_ARENA:
    case FACILITY_BATTLE_FACTORY:
    case FACILITY_BATTLE_PIKE_SINGLE:
    case FACILITY_BATTLE_PIKE_DOUBLE:
    case FACILITY_BATTLE_PYRAMID:
        if (gSaveBlock2Ptr->frontier.battlesCount < 0xFFFFFF)
        {
            gSaveBlock2Ptr->frontier.battlesCount++;
            if (gSaveBlock2Ptr->frontier.battlesCount % 20 == 0)
                UpdateGymLeaderRematch();
        }
        else
        {
            gSaveBlock2Ptr->frontier.battlesCount = 0xFFFFFF;
        }
        break;
    case FACILITY_BATTLE_TRAINER_HILL:
    default:
        break;
    }

    SetMainCallback2(CB2_ReturnToFieldContinueScriptPlayMapMusic);
}

static void Task_StartBattleAfterTransition(u8 taskId)
{
    if (IsBattleTransitionDone() == TRUE)
    {
        gMain.savedCallback = HandleFacilityTrainerBattleEnd;
        SetMainCallback2(CB2_InitBattle);
        DestroyTask(taskId);
    }
}

static void DoFacilityTrainerBattleInternal(u8 facility)
{
    gBattleScripting.specialTrainerBattleType = facility;

    switch (facility)
    {
    case FACILITY_BATTLE_TOWER:
        gBattleTypeFlags = BATTLE_TYPE_TRAINER | BATTLE_TYPE_BATTLE_TOWER;
        switch (VarGet(VAR_FRONTIER_BATTLE_MODE))
        {
        case FRONTIER_MODE_SINGLES:
            FillFrontierTrainerParty(FRONTIER_PARTY_SIZE);
            break;
        case FRONTIER_MODE_DOUBLES:
            FillFrontierTrainerParty(FRONTIER_DOUBLES_PARTY_SIZE);
            gBattleTypeFlags |= BATTLE_TYPE_DOUBLE;
            break;
        case FRONTIER_MODE_MULTIS:
            FillFrontierTrainersParties(FRONTIER_MULTI_PARTY_SIZE);
            gPartnerTrainerId = gSaveBlock2Ptr->frontier.trainerIds[17];
            FillPartnerParty(gPartnerTrainerId);
            gBattleTypeFlags |= BATTLE_TYPE_DOUBLE | BATTLE_TYPE_INGAME_PARTNER | BATTLE_TYPE_MULTI | BATTLE_TYPE_TWO_OPPONENTS;
            break;
        case FRONTIER_MODE_LINK_MULTIS:
            gBattleTypeFlags |= BATTLE_TYPE_DOUBLE | BATTLE_TYPE_LINK | BATTLE_TYPE_MULTI | BATTLE_TYPE_TOWER_LINK_MULTI;
            FillFrontierTrainersParties(FRONTIER_MULTI_PARTY_SIZE);
            break;
        }
        CreateTask(Task_StartBattleAfterTransition, 1);
        PlayMapChosenOrBattleBGM(0);
        BattleTransition_StartOnField(GetSpecialBattleTransition(B_TRANSITION_GROUP_B_TOWER));
        break;
    case FACILITY_BATTLE_DOME:
        gBattleTypeFlags = BATTLE_TYPE_TRAINER | BATTLE_TYPE_DOME;
        if (VarGet(VAR_FRONTIER_BATTLE_MODE) == FRONTIER_MODE_DOUBLES)
            gBattleTypeFlags |= BATTLE_TYPE_DOUBLE;
        FillFrontierTrainerParty(FRONTIER_PARTY_SIZE);
        CreateTask(Task_StartBattleAfterTransition, 1);
        CreateTask_PlayMapChosenOrBattleBGM(0);
        BattleTransition_StartOnField(GetSpecialBattleTransition(B_TRANSITION_GROUP_B_DOME));
        break;
    case FACILITY_BATTLE_PALACE:
        gBattleTypeFlags = BATTLE_TYPE_TRAINER | BATTLE_TYPE_PALACE;
        if (VarGet(VAR_FRONTIER_BATTLE_MODE) == FRONTIER_MODE_DOUBLES)
            gBattleTypeFlags |= BATTLE_TYPE_DOUBLE;
        FillFrontierTrainerParty(FRONTIER_PARTY_SIZE);
        CreateTask(Task_StartBattleAfterTransition, 1);
        PlayMapChosenOrBattleBGM(0);
        BattleTransition_StartOnField(GetSpecialBattleTransition(B_TRANSITION_GROUP_B_PALACE));
        break;
    case FACILITY_BATTLE_ARENA:
        gBattleTypeFlags = BATTLE_TYPE_TRAINER | BATTLE_TYPE_ARENA;
        FillFrontierTrainerParty(FRONTIER_PARTY_SIZE);
        CreateTask(Task_StartBattleAfterTransition, 1);
        PlayMapChosenOrBattleBGM(0);
        BattleTransition_StartOnField(GetSpecialBattleTransition(B_TRANSITION_GROUP_B_ARENA));
        break;
    case FACILITY_BATTLE_FACTORY:
        gBattleTypeFlags = BATTLE_TYPE_TRAINER | BATTLE_TYPE_FACTORY;
        if (VarGet(VAR_FRONTIER_BATTLE_MODE) == FRONTIER_MODE_DOUBLES)
            gBattleTypeFlags |= BATTLE_TYPE_DOUBLE;
        FillFrontierTrainerParty(FRONTIER_PARTY_SIZE);
        CreateTask(Task_StartBattleAfterTransition, 1);
        PlayMapChosenOrBattleBGM(0);
        BattleTransition_StartOnField(GetSpecialBattleTransition(B_TRANSITION_GROUP_B_FACTORY));
        break;
    case FACILITY_BATTLE_PIKE_SINGLE:
        gBattleTypeFlags = BATTLE_TYPE_TRAINER | BATTLE_TYPE_BATTLE_TOWER;
        FillFrontierTrainerParty(FRONTIER_PARTY_SIZE);
        CreateTask(Task_StartBattleAfterTransition, 1);
        PlayMapChosenOrBattleBGM(0);
        BattleTransition_StartOnField(GetSpecialBattleTransition(B_TRANSITION_GROUP_B_PIKE));
        break;
    case FACILITY_BATTLE_PIKE_DOUBLE:
        gBattleTypeFlags = BATTLE_TYPE_TRAINER | BATTLE_TYPE_BATTLE_TOWER | BATTLE_TYPE_DOUBLE | BATTLE_TYPE_TWO_OPPONENTS;
        FillFrontierTrainersParties(1);
        CreateTask(Task_StartBattleAfterTransition, 1);
        PlayMapChosenOrBattleBGM(0);
        BattleTransition_StartOnField(GetSpecialBattleTransition(B_TRANSITION_GROUP_B_PIKE));
        break;
    case FACILITY_BATTLE_PYRAMID:
        gBattleTypeFlags = BATTLE_TYPE_TRAINER | BATTLE_TYPE_PYRAMID;
        FillFrontierTrainerParty(FRONTIER_PARTY_SIZE);
        CreateTask(Task_StartBattleAfterTransition, 1);
        PlayMapChosenOrBattleBGM(0);
        BattleTransition_StartOnField(GetSpecialBattleTransition(B_TRANSITION_GROUP_B_PYRAMID));
        break;
    case FACILITY_BATTLE_TRAINER_HILL:
    default:
        break;
    }
}

void DoFacilityTrainerBattle(struct ScriptContext *ctx)
{
    u8 facility = ScriptReadByte(ctx);

    DoFacilityTrainerBattleInternal(facility);
}

void FacilityTrainerBattle(struct ScriptContext *ctx)
{
    u8 facility = ScriptReadByte(ctx);

    ConfigureFacilityTrainerBattle(facility, ctx->scriptPtr);
}

void FillFrontierTrainerParty(u8 monsCount)
{
    ZeroEnemyPartyMons();
    FillTrainerParty(TRAINER_BATTLE_PARAM.opponentA, B_TRAINER_OPPONENT_A, monsCount);
}

void FillFrontierTrainersParties(u8 monsCount)
{
    ZeroEnemyPartyMons();
    FillTrainerParty(TRAINER_BATTLE_PARAM.opponentA, B_TRAINER_OPPONENT_A, monsCount);
    FillTrainerParty(TRAINER_BATTLE_PARAM.opponentB, B_TRAINER_OPPONENT_B, monsCount);
}

void PickRandomFacilityMons(struct FacilityMonGenerator *generator, u16 trainerId, u16 *dest)
{
    u16 bfMonCount;
    const u16 *monSet = NULL;
    s32 i = 0;
    if (trainerId != 0xFFFF)
    {
        monSet = generator->frontierTrainerList[trainerId].monSet;
        for (bfMonCount = 0; monSet[bfMonCount] != 0xFFFF; bfMonCount++)
            ;
    }

    while (i != generator->partySize)
    {
        u16 monId;
        if (monSet == NULL)
        {
            if (generator->lvlMode != FRONTIER_LVL_TENT)
                monId = GetFactoryMonId(generator, i);
            else
                monId = RandomUniform(RNG_NONE, 0, NUM_SLATEPORT_TENT_MONS - 1);
        }
        else
        {
            monId = RandomUniform(RNG_NONE, 0, bfMonCount - 1);
            monId = monSet[monId];
        }

        bool32 isMonValid = TRUE;
        enum Species pairSpecies = SPECIES_NONE;
        for (u32 j = 0; j < i; j++)
        {
            if (generator->facilityMonList[dest[j]].species == generator->facilityMonList[monId].species)
            {
                if (trainerId != 0xFFFF || pairSpecies)
                {
                    isMonValid = FALSE;
                    break;
                }
                else
                {
                    pairSpecies = generator->facilityMonList[monId].species;
                }
            }
            if (!generator->facilityMonList[monId].heldItem)
                break;
            if (generator->facilityMonList[dest[j]].heldItem == generator->facilityMonList[monId].heldItem)
            {
                isMonValid = FALSE;
                break;
            }
        }
        if (generator->facility == FRONTIER_FACILITY_FACTORY)
        {
            if (generator->facilityMonList[monId].species == SPECIES_UNOWN)
                isMonValid = FALSE;

            for (u32 j = 0; j < 2 * FRONTIER_PARTY_SIZE; j++)
            {
                if (generator->facilityMonList[monId].species == generator->facilityMonList[gSaveBlock2Ptr->frontier.rentalMons[j].monId].species)
                {
                    isMonValid = FALSE;
                    break;
                }
            }
        }
        else
        {
            if (generator->lvlMode == FRONTIER_MAX_LEVEL_50 && monId > FRONTIER_MONS_HIGH_TIER)
                isMonValid = FALSE;
        }
        if (isMonValid)
        {
            dest[i] = monId;
            i++;
        }
        else if (pairSpecies == generator->facilityMonList[monId].species)
        {
            pairSpecies = SPECIES_NONE;
        }
    }
}

static void PickFacilityMons(struct FacilityMonGenerator *generator, u16 trainerId)
{
    if (generator->facility == FACILITY_BATTLE_FACTORY)
        return;
    if (generator->facility == FACILITY_BATTLE_DOME)
    {
        PickDomeFacilityMons(trainerId);
        return;
    }
    PickRandomFacilityMons(generator, trainerId, gFrontierTempParty);
}

static void ModifyPartyOrder(struct FacilityMonGenerator *generator, u16 trainerId)
{
    u16 tmp[MAX_FRONTIER_PARTY_SIZE];
    u32 monsCount = 0;
    if (generator->facility == FRONTIER_FACILITY_DOME)
    {
        u32 selectedMonBits = GetDomeTrainerSelectedMons(trainerId);
        for (u32 i = 0; i < FRONTIER_PARTY_SIZE; i++)
        {
            if (selectedMonBits & 1)
                tmp[monsCount++] = i;
            selectedMonBits >>= 1;
        }
        if (RandomPercentage(RNG_NONE, 60))
        {
            gFrontierTempParty[0] = gFrontierTempParty[tmp[0]];
            gFrontierTempParty[1] = gFrontierTempParty[tmp[1]];
        }
        else
        {
            gFrontierTempParty[0] = gFrontierTempParty[tmp[1]];
            gFrontierTempParty[1] = gFrontierTempParty[tmp[0]];
        }
        generator->partySize = DOME_BATTLE_PARTY_SIZE;
    }
}

static void FillTrainerParty(u16 trainerId, enum BattleTrainer trainer, u8 monCount)
{
    s32 i, j;

    struct FacilityMonGenerator generator = GetFacilityMonGenerator(trainerId);
    if (trainerId < FRONTIER_TRAINERS_COUNT)
    {
        ;
    }
    else if (trainerId == TRAINER_EREADER)
    {
    #if FREE_BATTLE_TOWER_E_READER == FALSE
        for (i = 0; i < FRONTIER_PARTY_SIZE; i++)
            CreateBattleTowerMon(&gParties[trainer][i], &gSaveBlock2Ptr->frontier.ereaderTrainer.party[i]);
    #endif //FREE_BATTLE_TOWER_E_READER
        return;
    }
    else if (trainerId == TRAINER_FRONTIER_BRAIN)
    {
        if (generator.facility != FACILITY_BATTLE_FACTORY)
        {
            CreateFrontierBrainPokemon();
            return;
        }
    }
    else if (trainerId < TRAINER_RECORD_MIXING_APPRENTICE)
    {
        // Record mixed player.
        for (j = 0, i = 0; i < monCount; j++, i++)
        {
            if (gSaveBlock2Ptr->frontier.towerRecords[trainerId - TRAINER_RECORD_MIXING_FRIEND].party[j].species != SPECIES_NONE
                && gSaveBlock2Ptr->frontier.towerRecords[trainerId - TRAINER_RECORD_MIXING_FRIEND].party[j].level <= generator.partyLevel)
            {
                CreateBattleTowerMon_HandleLevel(&gParties[trainer][i], &gSaveBlock2Ptr->frontier.towerRecords[trainerId - TRAINER_RECORD_MIXING_FRIEND].party[j], FALSE);
            }
        }
        return;
    }
    else
    {
        // Apprentice.
        for (i = 0; i < FRONTIER_PARTY_SIZE; i++)
            CreateApprenticeMon(&gParties[trainer][i], &gSaveBlock2Ptr->apprentices[trainerId - TRAINER_RECORD_MIXING_APPRENTICE], i);
        return;
    }

    generator.partySize = monCount;
    PickFacilityMons(&generator, trainerId);
    ModifyPartyOrder(&generator, trainerId);
    for (i = 0; i < generator.partySize; i++)
    {
        CreateFacilityMon(&gParties[trainer][i], &generator, gFrontierTempParty[i]);
    }
}

void CreateFacilityMon(struct Pokemon *dst, struct FacilityMonGenerator *generator, u16 monIndex)
{
    const struct TrainerMon *fmon = &generator->facilityMonList[monIndex];
    enum PokeBall ball = (fmon->ball == 0xFF) ? Random() % POKEBALL_COUNT : fmon->ball;
    enum Move move;
    u32 friendship, j, data;

    u32 personality = (Random32() & 0xFFFFDF00) + 0x1000;
    u32 genderValue = Random32();
    if (fmon->gender == TRAINER_MON_MALE)
        genderValue = GeneratePersonalityForGender(MON_MALE, fmon->species, genderValue);
    else if (fmon->gender == TRAINER_MON_FEMALE)
        genderValue = GeneratePersonalityForGender(MON_FEMALE, fmon->species, genderValue);
    else
        genderValue = genderValue & 0x000000FF;
    personality |= genderValue;

    ModifyPersonalityForNature(&personality, fmon->nature);
    CreateMonWithIVs(dst, fmon->species, generator->partyLevel, personality, OTID_STRUCT_PRESET(generator->otId), generator->fixedIV);

    friendship = MAX_FRIENDSHIP;
    // Give the chosen Pokémon its specified moves.
    for (j = 0; j < MAX_MON_MOVES; j++)
    {
        move = fmon->moves[j];
        if (generator->facility == FRONTIER_FACILITY_FACTORY && move == MOVE_RETURN)
            move = MOVE_FRUSTRATION;

        SetMonMoveSlot(dst, move, j);
        if (GetMoveEffect(move) == EFFECT_FRUSTRATION)
            friendship = 0;  // Frustration is more powerful the lower the Pokémon's friendship is.
    }

    SetMonData(dst, MON_DATA_FRIENDSHIP, &friendship);
    SetMonData(dst, MON_DATA_HELD_ITEM, &fmon->heldItem);

    // try to set ability. Otherwise, random of non-hidden as per vanilla
    if (fmon->ability)
    {
        SetCorrectAbilityNum(dst, fmon->species, fmon->ability);
    }

    if (fmon->ev != NULL)
    {
        SetMonData(dst, MON_DATA_HP_EV, &(fmon->ev[0]));
        SetMonData(dst, MON_DATA_ATK_EV, &(fmon->ev[1]));
        SetMonData(dst, MON_DATA_DEF_EV, &(fmon->ev[2]));
        SetMonData(dst, MON_DATA_SPATK_EV, &(fmon->ev[3]));
        SetMonData(dst, MON_DATA_SPDEF_EV, &(fmon->ev[4]));
        SetMonData(dst, MON_DATA_SPEED_EV, &(fmon->ev[5]));
    }

    if (fmon->isShiny)
    {
        data = TRUE;
        SetMonData(dst, MON_DATA_IS_SHINY, &data);
    }
    if (fmon->shouldUseDynamax)
    {
        data = fmon->dynamaxLevel;
    }
    else
    {
        data = BLOCK_AI_DYNAMAX;
    }
    SetMonData(dst, MON_DATA_DYNAMAX_LEVEL, &data);
    if (fmon->gigantamaxFactor)
    {
        data = fmon->gigantamaxFactor;
        SetMonData(dst, MON_DATA_GIGANTAMAX_FACTOR, &data);
    }
    if (fmon->teraType)
    {
        data = fmon->teraType;
        SetMonData(dst, MON_DATA_TERA_TYPE, &data);
    }
    else
    {
        data = TYPE_MYSTERY;
        SetMonData(dst, MON_DATA_TERA_TYPE, &data);
    }

    SetMonData(dst, MON_DATA_POKEBALL, &ball);
    CalculateMonStats(dst);
}
