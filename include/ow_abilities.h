#ifndef GUARD_OW_SYNCHRONIZE_H
#define GUARD_OW_SYNCHRONIZE_H

enum GeneratedMonOrigin 
{
    WILDMON_ORIGIN,
    STATIC_WILDMON_ORIGIN,
    ROAMER_ORIGIN,
    GIFTMON_ORIGIN
};

u32 GetSynchronizedNature(enum GeneratedMonOrigin origin, enum Species species);
u32 GetSynchronizedGender(enum GeneratedMonOrigin origin, enum Species species);
bool32 DoesLeadingMonHaveAbilityEffect(const enum Ability *abilityArray);
bool32 DoesPartyMemberHaveAbilityEffect(const enum Ability *abilityArray);

#endif // GUARD_OW_SYNCHRONIZE_H
