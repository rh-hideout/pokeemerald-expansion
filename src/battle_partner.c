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

enum PartnerType
{
    PRESET_PARTNER,
    FRONTIER_PARTNER,
    FRIEND_RECORD_PARTNER,
    APPRENTICE_PARTNER,
    NO_PARTNER_FOUND
};

static enum PartnerType GetPartnerType(u16 trainerId)
{
    if (trainerId < FRONTIER_TRAINERS_COUNT)
        return FRONTIER_PARTNER;
    if (trainerId < TRAINER_RECORD_MIXING_APPRENTICE)
        return FRIEND_RECORD_PARTNER;
    if (trainerId < TRAINER_EREADER)
        return APPRENTICE_PARTNER;
    if (trainerId > TRAINER_PARTNER(PARTNER_NONE) && trainerId < TRAINER_PARTNER(PARTNER_COUNT))
        return PRESET_PARTNER;
    return NO_PARTNER_FOUND;
}

STATIC_ASSERT(TRAINER_PARTNER(PARTNER_NONE) >= TRAINER_EREADER, OverlappingPartnerIds);

static void FillPresetPartnerParty(u16 trainerId)
{
    s32 lastIndex = AreMultiPartiesFullTeams() ? PARTY_SIZE : MULTI_PARTY_SIZE;

    const struct Trainer *partner = GetTrainerStructFromId(trainerId);
    struct TrainerGenerator partnerGen;
    MakePartnerGenerator(&partnerGen, partner);
    if (trainerId == TRAINER_PARTNER(PARTNER_STEVEN))
        partnerGen.otID = OTID_STRUCT_PRESET(STEVEN_OTID);
    for (u32 i = 0; i < lastIndex && i < partner->partySize; i++)
    {
        GenerateMonFromTrainerMon(&gParties[B_TRAINER_PARTNER][i], &partner->party[i], &partnerGen);
    }
}

static void FillFrontierPartnerParty(u16 trainerId)
{
    u32 level = SetFacilityPtrsGetLevel();
    u32 ivs = GetFrontierTrainerFixedIvs(trainerId);
    u32 otID = Random32();
    for (u32 i = 0; i < FRONTIER_MULTI_PARTY_SIZE; i++)
    {
        u32 monId = gSaveBlock2Ptr->frontier.trainerIds[i + 18];
        CreateFacilityMon(&gFacilityTrainerMons[monId], level, ivs, otID, 0, &gParties[B_TRAINER_PARTNER][i]);
        SetMonData(&gParties[B_TRAINER_PARTNER][i], MON_DATA_OT_NAME, gFacilityTrainers[trainerId].trainerName);
        enum Gender gender = IsFrontierTrainerFemale(trainerId);
        SetMonData(&gParties[B_TRAINER_PARTNER][i], MON_DATA_OT_GENDER, &gender);
    }
}

static void FillFriendRecordPartnerParty(u16 friendRecordId)
{
    u8 trainerName[PLAYER_NAME_LENGTH + 1];
    struct EmeraldBattleTowerRecord *record = &gSaveBlock2Ptr->frontier.towerRecords[friendRecordId];
    for (u32 i = 0; i < FRONTIER_MULTI_PARTY_SIZE; i++)
    {
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
        CreateBattleTowerMon_HandleLevel(&gParties[B_TRAINER_PARTNER][i], &monData, TRUE);
        SetMonData(&gParties[B_TRAINER_PARTNER][i], MON_DATA_OT_NAME, trainerName);
        enum Gender gender = IsFrontierTrainerFemale(friendRecordId + TRAINER_RECORD_MIXING_FRIEND);
        SetMonData(&gParties[B_TRAINER_PARTNER][i], MON_DATA_OT_GENDER, &gender);
    }
}

static void FillApprenticePartnerParty(u16 apprenticeId)
{
    for (u32 i = 0; i < FRONTIER_MULTI_PARTY_SIZE; i++)
    {
        CreateApprenticeMon(&gParties[B_TRAINER_PARTNER][i], &gSaveBlock2Ptr->apprentices[apprenticeId], gSaveBlock2Ptr->frontier.trainerIds[18 + i]);
        enum Gender gender = IsFrontierTrainerFemale(apprenticeId + TRAINER_RECORD_MIXING_APPRENTICE);
        SetMonData(&gParties[B_TRAINER_PARTNER][i], MON_DATA_OT_GENDER, &gender);
    }
}

void FillPartnerParty(u16 trainerId)
{
    ZeroPartyMons(gParties[B_TRAINER_PARTNER]);

    switch(GetPartnerType(trainerId))
    {
        case PRESET_PARTNER:
            FillPresetPartnerParty(trainerId);
            break;
        case FRONTIER_PARTNER:
            FillFrontierPartnerParty(trainerId);
            break;
        case FRIEND_RECORD_PARTNER:
            FillFriendRecordPartnerParty(trainerId - TRAINER_RECORD_MIXING_FRIEND);
            break;
        case APPRENTICE_PARTNER:
            FillApprenticePartnerParty(trainerId - TRAINER_RECORD_MIXING_APPRENTICE);
            break;
        case NO_PARTNER_FOUND:
            errorf("trainerId %d is not a valid id for a partner", trainerId);
            break;
    }
}

enum TrainerClassID GetPartnerClass(u16 trainerId)
{
    enum TrainerClassID trainerClass;
    switch(GetPartnerType(trainerId))
    {
        case PRESET_PARTNER:
            trainerClass = GetTrainerClassFromId(trainerId);
        case FRONTIER_PARTNER:
        case FRIEND_RECORD_PARTNER:
        case APPRENTICE_PARTNER:
            trainerClass = GetFrontierOpponentClass(trainerId);
        case NO_PARTNER_FOUND:
            errorf("trainerId %d is not a valid id for a partner", trainerId);
            trainerClass = 0;
    }
    return trainerClass;
}
