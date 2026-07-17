#ifndef GUARD_OW_SYNCHRONIZE_H
#define GUARD_OW_SYNCHRONIZE_H

extern const enum Ability gForceNatureAbilities[];
extern const enum Ability gForceOppositeGenderAbilities[];

#define BLOCK_LOW_LEVEL_ABILITY_CHANCE 50
extern const enum Ability gBlockLowLevelEncounterAbilities[];

#define FORCE_MAX_LEVEL_ABILITY_CHANCE 50
extern const enum Ability gForceMaxLevelAbilities[];

extern const enum Ability gEncounterReducingAbilities[];
extern const enum Ability gEncounterIncreasingAbilities[];
extern const enum Ability gHiddenBySandstormAbilities[];
extern const enum Ability gHiddenBySnowAbilities[];

extern const enum Ability gIncreaseHatchingSpeedAbilities[];

u32 GetSynchronizedNature(enum GeneratedMonOrigin origin, enum Species species);
u32 GetSynchronizedGender(enum GeneratedMonOrigin origin, enum Species species);
enum Type GetWeightedTypeForWildmonEncounter(void);
bool32 DoesLeadingMonHaveAbilityEffect(const enum Ability *abilityArray);
bool32 DoesPartyMemberHaveAbilityEffect(const enum Ability *abilityArray);
bool32 DoesPartyHaveIncubatorMon(void);

#endif // GUARD_OW_SYNCHRONIZE_H
