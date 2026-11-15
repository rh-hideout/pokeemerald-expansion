#ifndef GUARD_BATTLE_FACTORY_H
#define GUARD_BATTLE_FACTORY_H

void CallBattleFactoryFunction(void);
bool8 InBattleFactory(void);
u8 GetFactoryMonFixedIV(struct FacilityMonGenerator *generator, u32 trainerId);
u16 GetFactoryMonId(struct FacilityMonGenerator *generator, u32 rentalIndex);
void FillFactoryBrainParty(void);
u8 GetNumPastRentalsRank(u8 battleMode, enum FrontierLevelMode lvlMode);
u64 GetAiScriptsInBattleFactory(void);
void FillFactoryTrainerParty(void);

void FactoryGenerateOpponentMons(void);
void FactoryGenerateInitialRentalMons(void);

#endif // GUARD_BATTLE_FACTORY_H
