#ifndef GUARD_BATTLE_TOWER_H
#define GUARD_BATTLE_TOWER_H

#include "data.h"
#include "battle_frontier.h"

struct RSBattleTowerRecord
{
    /*0x00*/ u8 lvlMode; // 0 = level 50, 1 = level 100
    /*0x01*/ u8 facilityClass;
    /*0x02*/ u16 winStreak;
    /*0x04*/ u8 name[PLAYER_NAME_LENGTH + 1];
    /*0x0C*/ u8 trainerId[TRAINER_ID_LENGTH];
    /*0x10*/ u16 greeting[EASY_CHAT_BATTLE_WORDS_COUNT];
    /*0x1C*/ struct BattleTowerPokemon party[FRONTIER_PARTY_SIZE];
    /*0xA0*/ u32 checksum;
};

struct FacilitySingleClassData {
    enum TrainerClassID trainerClass;
    enum TrainerPicID trainerPic;
    enum TrainerApproachMusic approachMusic;
    u16 gfxId;
    enum Gender gender;
};

struct FacilityDoubleClassData {
    enum TrainerClassID trainerClass;
    enum TrainerPicID trainerPic;
    enum TrainerApproachMusic approachMusic;
    u16 gfxId1;
    u16 gfxId2;
    enum Gender gender1;
    enum Gender gender2;
};

extern const struct FacilitySingleClassData gFacilitySingleClassList[];
extern const struct FacilityDoubleClassData gFacilityDoubleClassList[];
extern const struct TrainerMon gSlateportBattleTentMons[];
extern const struct BattleFrontierTrainer gSlateportBattleTentTrainers[];

void CallBattleTowerFunc(void);
void PutNewBattleTowerRecord(struct EmeraldBattleTowerRecord *newRecordEm);
void CalcEmeraldBattleTowerChecksum(struct EmeraldBattleTowerRecord *record);
void CalcRubyBattleTowerChecksum(struct RSBattleTowerRecord *record);
u16 GetCurrentBattleTowerWinStreak(enum FrontierLevelMode lvlMode, u8 battleMode);
void TryHideBattleTowerReporter(void);
bool32 RubyBattleTowerRecordToEmerald(struct RSBattleTowerRecord *src, struct EmeraldBattleTowerRecord *dst);
bool32 EmeraldBattleTowerRecordToRuby(struct EmeraldBattleTowerRecord *src, struct RSBattleTowerRecord *dst);
void CalcApprenticeChecksum(struct Apprentice *apprentice);
void GetBattleTowerTrainerLanguage(u8 *dst, u16 trainerId);
u8 SetTentPtrsGetLevel(void);
void TrySetLinkBattleTowerEnemyPartyLevel(void);
void FillTentTrainerParty(u8 monsCount);


#endif //GUARD_BATTLE_TOWER_H
