#ifndef GUARD_BATTLE_FRONTIER_H
#define GUARD_BATTLE_FRONTIER_H

#include "data.h"

struct BattleFrontierTrainer
{
    u8 facilityClass;
    u8 filler1[3];
    u8 trainerName[PLAYER_NAME_LENGTH + 1];
    u16 speechBefore[EASY_CHAT_BATTLE_WORDS_COUNT];
    u16 speechWin[EASY_CHAT_BATTLE_WORDS_COUNT];
    u16 speechLose[EASY_CHAT_BATTLE_WORDS_COUNT];
    const u16 *monSet;
};

// Temporary storage for monIds of the opponent team
// during team generation in battle factory and similar facilities.
extern u16 gFrontierTempParty[MAX_FRONTIER_PARTY_SIZE];

extern const struct BattleFrontierTrainer *gFacilityTrainers;
extern const struct TrainerMon *gFacilityTrainerMons;
extern const struct BattleFrontierTrainer gBattleFrontierTrainers[];
extern const struct TrainerMon gBattleFrontierMons[];

void DoFacilityTrainerBattle(struct ScriptContext *ctx);
void FillFrontierTrainerParty(u8 monsCount);
void FillFrontierTrainersParties(u8 monsCount);
void PickRandomFacilityMons(struct FacilityMonGenerator *generator, u16 trainerId, u16 *dest);
void CreateFacilityMon(struct Pokemon *dst, struct FacilityMonGenerator *generator, u16 monIndex);

#endif // GUARD_BATTLE_FRONTIER_H
