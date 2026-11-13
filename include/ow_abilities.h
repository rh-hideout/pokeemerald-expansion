#ifndef GUARD_OW_SYNCHRONIZE_H
#define GUARD_OW_SYNCHRONIZE_H

u32 GetSynchronizedNature(enum GeneratedMonOrigin origin, enum Species species);
u32 GetSynchronizedGender(enum GeneratedMonOrigin origin, enum Species species);
bool32 DoesLeadingMonHaveAbilityEffect(const enum Ability *abilityArray);
bool32 DoesPartyMemberHaveAbilityEffect(const enum Ability *abilityArray);
bool32 DoesPartyHaveIncubatorMon(void);
bool32 DoesRockSmashUserHaveIncreasedItemRarity(u8 partySlot);
bool32 DoesRockSmashUserHaveIncreasedItemLikelihood(u8 partySlot);

#endif // GUARD_OW_SYNCHRONIZE_H
