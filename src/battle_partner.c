#include "global.h"
#include "main.h"
#include "battle.h"
#include "battle_partner.h"
#include "battle_frontier.h"
#include "data.h"
#include "frontier_util.h"
#include "difficulty.h"
#include "string_util.h"
#include "text.h"

#include "constants/abilities.h"
#include "constants/battle_ai.h"

#include "data/partner_parties.h"
const struct Trainer gBattlePartners[DIFFICULTY_COUNT][PARTNER_COUNT] =
{
#include "data/battle_partners.h"
};

#define STEVEN_OTID 61226

void FillPartnerParty(u16 trainerId)
{
    s32 i, j, k;
    u32 firstIdPart = 0, secondIdPart = 0, thirdIdPart = 0;
    u32 ivs, level, personality;
    u16 monId;
    u32 otID;
    u8 trainerName[(PLAYER_NAME_LENGTH * 3) + 1];
    enum DifficultyLevel difficulty = GetBattlePartnerDifficultyLevel(trainerId);
    SetFacilityPtrsGetLevel();
    ZeroPartnerPartyMons();

    if (trainerId > TRAINER_PARTNER(PARTNER_NONE))
    {
        s32 lastIndex = AreMultiPartiesFullTeams() ? PARTY_SIZE : MULTI_PARTY_SIZE;

        for (i = 0; i < lastIndex && i < gBattlePartners[difficulty][trainerId - TRAINER_PARTNER(PARTNER_NONE)].partySize; i++)
        {
            const struct TrainerMon *partyData = gBattlePartners[difficulty][trainerId - TRAINER_PARTNER(PARTNER_NONE)].party;
            const u8 *partnerName = gBattlePartners[difficulty][trainerId - TRAINER_PARTNER(PARTNER_NONE)].trainerName;

            for (k = 0; partnerName[k] != EOS && k < 3; k++)
            {
                if (k == 0)
                {
                    firstIdPart = partnerName[k];
                    secondIdPart = partnerName[k];
                    thirdIdPart = partnerName[k];
                }
                else if (k == 1)
                {
                    secondIdPart = partnerName[k];
                    thirdIdPart = partnerName[k];
                }
                else if (k == 2)
                {
                    thirdIdPart = partnerName[k];
                }
            }
            if (trainerId == TRAINER_PARTNER(PARTNER_STEVEN))
                otID = STEVEN_OTID;
            else
                otID = ((firstIdPart % 72) * 1000) + ((secondIdPart % 23) * 10) + (thirdIdPart % 37) % 65536;

            personality = Random32();
            if (partyData[i].gender == TRAINER_MON_MALE)
                personality = (personality & 0xFFFFFF00) | GeneratePersonalityForGender(MON_MALE, partyData[i].species);
            else if (partyData[i].gender == TRAINER_MON_FEMALE)
                personality = (personality & 0xFFFFFF00) | GeneratePersonalityForGender(MON_FEMALE, partyData[i].species);
            ModifyPersonalityForNature(&personality, partyData[i].nature);
            CreateMon(&gParties[B_TRAINER_2][i], partyData[i].species, partyData[i].lvl, personality, OTID_STRUCT_PRESET(otID));
            j = partyData[i].isShiny;
            SetMonData(&gParties[B_TRAINER_2][i], MON_DATA_IS_SHINY, &j);
            SetMonData(&gParties[B_TRAINER_2][i], MON_DATA_HELD_ITEM, &partyData[i].heldItem);
            CustomTrainerPartyAssignMoves(&gParties[B_TRAINER_2][i], &partyData[i]);

            SetMonData(&gParties[B_TRAINER_2][i], MON_DATA_IVS, &(partyData[i].iv));
            if (partyData[i].ev != NULL)
            {
                SetMonData(&gParties[B_TRAINER_2][i], MON_DATA_HP_EV, &(partyData[i].ev[0]));
                SetMonData(&gParties[B_TRAINER_2][i], MON_DATA_ATK_EV, &(partyData[i].ev[1]));
                SetMonData(&gParties[B_TRAINER_2][i], MON_DATA_DEF_EV, &(partyData[i].ev[2]));
                SetMonData(&gParties[B_TRAINER_2][i], MON_DATA_SPATK_EV, &(partyData[i].ev[3]));
                SetMonData(&gParties[B_TRAINER_2][i], MON_DATA_SPDEF_EV, &(partyData[i].ev[4]));
                SetMonData(&gParties[B_TRAINER_2][i], MON_DATA_SPEED_EV, &(partyData[i].ev[5]));
            }
            if (partyData[i].ability != ABILITY_NONE)
            {
                const struct SpeciesInfo *speciesInfo = &gSpeciesInfo[partyData[i].species];
                u32 maxAbilities = ARRAY_COUNT(speciesInfo->abilities);
                for (j = 0; j < maxAbilities; j++)
                {
                    if (speciesInfo->abilities[j] == partyData[i].ability)
                        break;
                }
                if (j < maxAbilities)
                    SetMonData(&gParties[B_TRAINER_2][i], MON_DATA_ABILITY_NUM, &j);
            }
            SetMonData(&gParties[B_TRAINER_2][i], MON_DATA_FRIENDSHIP, &(partyData[i].friendship));
            if (partyData[i].ball < POKEBALL_COUNT)
            {
                SetMonData(&gParties[B_TRAINER_2][i], MON_DATA_POKEBALL, &partyData[i].ball);
            }
            if (partyData[i].nickname != NULL)
            {
                SetMonData(&gParties[B_TRAINER_2][i], MON_DATA_NICKNAME, partyData[i].nickname);
            }
            CalculateMonStats(&gParties[B_TRAINER_2][i]);

            StringCopy(trainerName, gBattlePartners[difficulty][trainerId - TRAINER_PARTNER(PARTNER_NONE)].trainerName);
            SetMonData(&gParties[B_TRAINER_2][i], MON_DATA_OT_NAME, trainerName);
            j = gBattlePartners[difficulty][SanitizeTrainerId(trainerId - TRAINER_PARTNER(PARTNER_NONE))].gender;
            SetMonData(&gParties[B_TRAINER_2][i], MON_DATA_OT_GENDER, &j);
        }
    }
    else if (trainerId == TRAINER_EREADER)
    {
        // Scrapped, lol.
        trainerName[0] = gGameLanguage;
    }
    else if (trainerId < FRONTIER_TRAINERS_COUNT)
    {
        level = SetFacilityPtrsGetLevel();
        ivs = GetFrontierTrainerFixedIvs(trainerId);
        otID = Random32();
        for (i = 0; i < FRONTIER_MULTI_PARTY_SIZE; i++)
        {
            monId = gSaveBlock2Ptr->frontier.trainerIds[i + 18];
            CreateFacilityMon(&gFacilityTrainerMons[monId], level, ivs, otID, 0, &gParties[B_TRAINER_2][i]);
            for (j = 0; j < PLAYER_NAME_LENGTH + 1; j++)
                trainerName[j] = gFacilityTrainers[trainerId].trainerName[j];
            SetMonData(&gParties[B_TRAINER_2][i], MON_DATA_OT_NAME, &trainerName);
            j = IsFrontierTrainerFemale(trainerId);
            SetMonData(&gParties[B_TRAINER_2][i], MON_DATA_OT_GENDER, &j);
        }
    }
    else if (trainerId < TRAINER_RECORD_MIXING_APPRENTICE)
    {
        trainerId -= TRAINER_RECORD_MIXING_FRIEND;
        for (i = 0; i < FRONTIER_MULTI_PARTY_SIZE; i++)
        {
            struct EmeraldBattleTowerRecord *record = &gSaveBlock2Ptr->frontier.towerRecords[trainerId];
            struct BattleTowerPokemon monData = record->party[gSaveBlock2Ptr->frontier.trainerIds[18 + i]];
            StringCopy(trainerName, record->name);
            if (record->language == LANGUAGE_JAPANESE)
            {
                if (monData.nickname[0] != EXT_CTRL_CODE_BEGIN || monData.nickname[1] != EXT_CTRL_CODE_JPN)
                {
                    monData.nickname[5] = EOS;
                    ConvertInternationalString(monData.nickname, LANGUAGE_JAPANESE);
                }
            }
            else
            {
                if (monData.nickname[0] == EXT_CTRL_CODE_BEGIN && monData.nickname[1] == EXT_CTRL_CODE_JPN)
                    trainerName[5] = EOS;
            }
            CreateBattleTowerMon_HandleLevel(&gParties[B_TRAINER_2][i], &monData, TRUE);
            SetMonData(&gParties[B_TRAINER_2][i], MON_DATA_OT_NAME, trainerName);
            j = IsFrontierTrainerFemale(trainerId + TRAINER_RECORD_MIXING_FRIEND);
            SetMonData(&gParties[B_TRAINER_2][i], MON_DATA_OT_GENDER, &j);
        }
    }
    else
    {
        trainerId -= TRAINER_RECORD_MIXING_APPRENTICE;
        for (i = 0; i < FRONTIER_MULTI_PARTY_SIZE; i++)
        {
            CreateApprenticeMon(&gParties[B_TRAINER_2][i], &gSaveBlock2Ptr->apprentices[trainerId], gSaveBlock2Ptr->frontier.trainerIds[18 + i]);
            j = IsFrontierTrainerFemale(trainerId + TRAINER_RECORD_MIXING_APPRENTICE);
            SetMonData(&gParties[B_TRAINER_2][i], MON_DATA_OT_GENDER, &j);
        }
    }
}
