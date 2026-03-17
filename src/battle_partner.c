#include "global.h"
#include "main.h"
#include "battle.h"
#include "battle_partner.h"
#include "battle_frontier.h"
#include "data.h"
#include "frontier_util.h"
#include "difficulty.h"
#include "malloc.h"
#include "string_util.h"
#include "trainer_util.h"
#include "text.h"

#include "constants/abilities.h"
#include "constants/battle_ai.h"

#if !TESTING
const struct Trainer gBattlePartners[DIFFICULTY_COUNT][PARTNER_COUNT] =
{
#include "data/battle_partners.h"
};
#endif

#define STEVEN_OTID 61226

static void MakePartnerGenerator(struct TrainerGenerator *trainerGen, const struct Trainer *trainer)
{
    u32 otID;
    trainerGen->gender = trainer->gender;
    trainerGen->isFrontier = FALSE;
    StringCopyN(trainerGen->name, trainer->trainerName, TRAINER_NAME_LENGTH + 1);
    trainerGen->trainerClass = trainer->trainerClass;
    otID = Crc32B((const u8 *)trainer, sizeof(struct Trainer));
    trainerGen->otID = OTID_STRUCT_PRESET(otID);
    trainerGen->localRngState = LocalRandomSeed(otID);
}

void FillPartnerParty(u16 trainerId)
{
    s32 i, j;
    u32 ivs, level;
    u16 monId;

    u8 trainerName[(PLAYER_NAME_LENGTH * 3) + 1];
    SetFacilityPtrsGetLevel();

    if (trainerId > TRAINER_PARTNER(PARTNER_NONE))
    {
        for (i = 0; i < 3; i++)
            ZeroMonData(&gPlayerParty[i + 3]);

        const struct Trainer *partner = GetTrainerStructFromId(trainerId);
        struct TrainerGenerator *partnerGen = AllocZeroed(sizeof(struct TrainerGenerator));
        MakePartnerGenerator(partnerGen, partner);
        if (trainerId == TRAINER_PARTNER(PARTNER_STEVEN))
            partnerGen->otID = OTID_STRUCT_PRESET(STEVEN_OTID);
        for (i = 0; i < 3 && i < partner->partySize; i++)
        {
            GenerateMonFromTrainerMon(&gPlayerParty[i + 3], &partner->party[i], partnerGen);
        }
        Free(partnerGen);
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
        u32 otID = Random32();
        for (i = 0; i < FRONTIER_MULTI_PARTY_SIZE; i++)
        {
            monId = gSaveBlock2Ptr->frontier.trainerIds[i + 18];
            CreateFacilityMon(&gFacilityTrainerMons[monId], level, ivs, otID, 0, &gPlayerParty[MULTI_PARTY_SIZE + i]);
            for (j = 0; j < PLAYER_NAME_LENGTH + 1; j++)
                trainerName[j] = gFacilityTrainers[trainerId].trainerName[j];
            SetMonData(&gPlayerParty[MULTI_PARTY_SIZE + i], MON_DATA_OT_NAME, &trainerName);
            j = IsFrontierTrainerFemale(trainerId);
            SetMonData(&gPlayerParty[MULTI_PARTY_SIZE + i], MON_DATA_OT_GENDER, &j);
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
            CreateBattleTowerMon_HandleLevel(&gPlayerParty[MULTI_PARTY_SIZE + i], &monData, TRUE);
            SetMonData(&gPlayerParty[MULTI_PARTY_SIZE + i], MON_DATA_OT_NAME, trainerName);
            j = IsFrontierTrainerFemale(trainerId + TRAINER_RECORD_MIXING_FRIEND);
            SetMonData(&gPlayerParty[MULTI_PARTY_SIZE + i], MON_DATA_OT_GENDER, &j);
        }
    }
    else
    {
        trainerId -= TRAINER_RECORD_MIXING_APPRENTICE;
        for (i = 0; i < FRONTIER_MULTI_PARTY_SIZE; i++)
        {
            CreateApprenticeMon(&gPlayerParty[MULTI_PARTY_SIZE + i], &gSaveBlock2Ptr->apprentices[trainerId], gSaveBlock2Ptr->frontier.trainerIds[18 + i]);
            j = IsFrontierTrainerFemale(trainerId + TRAINER_RECORD_MIXING_APPRENTICE);
            SetMonData(&gPlayerParty[MULTI_PARTY_SIZE + i], MON_DATA_OT_GENDER, &j);
        }
    }
}
