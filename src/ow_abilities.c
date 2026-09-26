#include "global.h"
#include "ow_abilities.h"
#include "mf_rules.h"
#include "pokemon.h"
#include "random.h"
#include "constants/pokemon.h"

const static enum Ability sForceNatureAbilities[] = {ABILITY_SYNCHRONIZE, ABILITY_NONE};
const static enum Ability sForceOppositeGenderAbilities[] = {ABILITY_CUTE_CHARM, ABILITY_NONE};
const static enum Ability sIncreaseHatchingSpeedAbilities[] = {ABILITY_MAGMA_ARMOR, ABILITY_FLAME_BODY, ABILITY_STEAM_ENGINE, ABILITY_NONE};

static bool32 HasHalfChance(enum Species species);
static bool32 HasTwoThirdsChance(enum Species species);
static bool32 IsFalse(enum Species species);
static bool32 IsTrue(enum Species species);

// Gen III Synchronize: 50% on wild encounters only.
static const bool32 (*const sSynchronizeModesClassic[])(enum Species) =
{
    [WILDMON_ORIGIN] = HasHalfChance,
    [STATIC_WILDMON_ORIGIN] = IsFalse,
    [ROAMER_ORIGIN] = IsFalse,
    [GIFTMON_ORIGIN] = IsFalse,
};

// Gen VIII+ Synchronize: always on wild + roamers (compile baseline OW_SYNCHRONIZE_NATURE).
static const bool32 (*const sSynchronizeModesModern[])(enum Species) =
{
    [WILDMON_ORIGIN] = IsTrue,
    [STATIC_WILDMON_ORIGIN] = IsFalse,
    [ROAMER_ORIGIN] = IsTrue,
    [GIFTMON_ORIGIN] = IsFalse,
};

static const bool32 (*const sCuteCharmModes[])(enum Species) =
{
    [WILDMON_ORIGIN] = HasTwoThirdsChance,
    [STATIC_WILDMON_ORIGIN] = HasTwoThirdsChance,
    [ROAMER_ORIGIN] = IsFalse,
    [GIFTMON_ORIGIN] = IsFalse,
};

static bool32 HasHalfChance(enum Species species)
{
    (void)species;
    return Random() % 2;
}

static bool32 HasTwoThirdsChance(enum Species species)
{
    (void)species;
    return Random() % 3;
}

static bool32 IsFalse(enum Species species)
{
    (void)species;
    return FALSE;
}

static bool32 IsTrue(enum Species species)
{
    (void)species;
    return TRUE;
}

bool32 DoesLeadingMonHaveAbilityEffect(const enum Ability *abilityArray)
{
    if (GetMonData(&gParties[B_TRAINER_PLAYER][0], MON_DATA_SANITY_IS_EGG))
        return FALSE;
    enum Ability leadingMonAbility = GetMonAbility(&gParties[B_TRAINER_PLAYER][0]);
    for (u32 i = 0; abilityArray[i] != ABILITY_NONE; i++)
    {
        if (leadingMonAbility == abilityArray[i])
            return TRUE;
    }
    return FALSE;
}

bool32 DoesPartyMemberHaveAbilityEffect(const enum Ability *abilityArray)
{
    for (u32 j = 0; j < gPartiesCount[B_TRAINER_PLAYER]; j++)
    {
        if (GetMonData(&gParties[B_TRAINER_PLAYER][j], MON_DATA_SANITY_IS_EGG))
            continue;
        enum Ability monAbility = GetMonAbility(&gParties[B_TRAINER_PLAYER][j]);
        for (u32 i = 0; abilityArray[i] != ABILITY_NONE; i++)
        {
            if (monAbility == abilityArray[i])
                return TRUE;
        }
    }
    return FALSE;
}

u32 GetSynchronizedNature(enum GeneratedMonOrigin origin, enum Species species)
{
    const bool32 (*const *modes)(enum Species) = MfRules_HasSynchronize()
        ? sSynchronizeModesModern
        : sSynchronizeModesClassic;

    if (!DoesLeadingMonHaveAbilityEffect(sForceNatureAbilities))
        return NATURE_RANDOM;
    if (!(modes[origin](species)))
        return NATURE_RANDOM;
    return GetMonData(&gParties[B_TRAINER_PLAYER][0], MON_DATA_PERSONALITY) % NUM_NATURES;
}

u32 GetSynchronizedGender(enum GeneratedMonOrigin origin, enum Species species)
{
    if (!DoesLeadingMonHaveAbilityEffect(sForceOppositeGenderAbilities))
        return MON_GENDER_RANDOM;
    if (!(sCuteCharmModes[origin](species)))
        return MON_GENDER_RANDOM;
    u8 leadingMonGender = GetMonGender(&gParties[B_TRAINER_PLAYER][0]);
    // misses mon is genderless check, although no genderless mon can have cute charm as ability
    if (leadingMonGender == MON_FEMALE)
        return MON_MALE;
    else
        return MON_FEMALE;
}

bool32 DoesPartyHaveIncubatorMon(void)
{
    return DoesPartyMemberHaveAbilityEffect(sIncreaseHatchingSpeedAbilities);
}
