#include "global.h"
#include "event_data.h"
#include "generational_changes.h"
#include "pokemon.h"
#include "pokerus.h"
#include "random.h"
#include "config/pokerus.h"

//Made a separate function in case someone wants to modify the behavior
u32 GetDaysLeftBasedOnStrain(u32 strain)
{
    u32 daysLeft = (strain % 4) + 1;
    return daysLeft;
}

static u32 GetRandomPokerusStrain(void)
{
    u32 strain;
    if (POKERUS_STRAIN_DISTRIBUTION < GEN_3) // Gen 1 - 2 (Gen 1 had no pokerus but we default it with gen 2)
        strain = RandomWeighted(RNG_POKERUS_STRAIN_DISTRIBUTION, 15, 30, 30, 30, 30, 30, 30, 30, 30, 1, 1, 1, 1, 1, 1, 1);
    else if (POKERUS_STRAIN_DISTRIBUTION < GEN_4) //Gen 3 (Ruby/Sapphire only)
        strain = RandomWeighted(RNG_POKERUS_STRAIN_DISTRIBUTION, 30, 31, 31, 31, 31, 31, 31, 31, 1, 1, 1, 1, 1, 1, 1, 1);
    else if (POKERUS_STRAIN_DISTRIBUTION < GEN_5) //Gen 4 (Including Emerald)
        strain = RandomWeighted(RNG_POKERUS_STRAIN_DISTRIBUTION, 0, 31, 31, 31, 31, 31, 31, 31, 1, 1, 1, 1, 1, 1, 1, 1);
    else // Gen 5+ (Pokerus was disabled in gen 9 but we default it here)
        strain = RandomWeighted(RNG_POKERUS_STRAIN_DISTRIBUTION, 0, 31, 31, 31, 31, 31, 31, 31, 0, 1, 1, 1, 1, 1, 1, 1);
    return strain;
}

void RandomlyGivePartyPokerus(void)
{
    if (!GetGenConfig(POKERUS_CONFIG_ENABLED))
        return;

    if (!GetGenConfig(POKERUS_CONFIG_INFECT_AGAIN) && IsPokerusInParty())
        return;

    if (POKERUS_FLAG_INFECTION && !FlagGet(POKERUS_FLAG_INFECTION))
        return;

    if (RandomUniform(RNG_POKERUS_INFECTION, 0, MAX_u16) < POKERUS_INFECTION_ODDS)
    {
        struct Pokemon *mon;
        u32 randomIndex;
        u32 validTargetsCount = 0;
        s32 validTargets[PARTY_SIZE];

        for (u32 i = 0; i < PARTY_SIZE; i++)
        {
            mon = &gPlayerParty[i];
            if (!GetMonData(mon, MON_DATA_SPECIES))
                continue;
            else if (!GetGenConfig(POKERUS_CONFIG_INFECT_EGG) && GetMonData(mon, MON_DATA_IS_EGG))
                continue;
            else if (!GetGenConfig(POKERUS_CONFIG_HERD_IMMUNITY) && CheckMonHasHadPokerus(mon))
                continue;
            validTargets[validTargetsCount] = i;
            validTargetsCount++;
        }

        if (validTargetsCount == 0)
            return;

        randomIndex = RandomUniform(RNG_POKERUS_PARTY_MEMBER, 0, validTargetsCount - 1);
        mon = &gPlayerParty[validTargets[randomIndex]];

        if (!(CheckMonHasHadPokerus(mon)))
        {
            u32 strain = GetRandomPokerusStrain();
            u32 daysLeft = GetDaysLeftBasedOnStrain(strain);

            SetMonData(mon, MON_DATA_POKERUS_STRAIN, &strain);
            SetMonData(mon, MON_DATA_POKERUS_DAYS_LEFT, &daysLeft);
        }
    }
}

bool8 IsPokerusInParty(void)
{
    if (!GetGenConfig(POKERUS_CONFIG_ENABLED))
        return FALSE;

    for (u32 i = 0; i < PARTY_SIZE; i++)
    {
        if (!GetMonData(&gPlayerParty[i], MON_DATA_SPECIES))
            continue;

        if (GetMonData(&gPlayerParty[i], MON_DATA_POKERUS_DAYS_LEFT))
            return TRUE;
    }

    return FALSE;
}

bool32 CheckMonPokerus(struct Pokemon *mon)
{
    if (!GetGenConfig(POKERUS_CONFIG_ENABLED))
        return FALSE;

    if (GetMonData(mon, MON_DATA_POKERUS_DAYS_LEFT))
        return TRUE;

    return FALSE;
}

bool32 CheckMonHasHadPokerus(struct Pokemon *mon)
{
    if (!GetGenConfig(POKERUS_CONFIG_ENABLED))
        return FALSE;

    if (GetMonData(mon, MON_DATA_POKERUS))
        return TRUE;

    return FALSE;
}

void UpdatePartyPokerusTime(u16 days)
{
    if (!GetGenConfig(POKERUS_CONFIG_ENABLED))
        return;

    for (u32 i = 0; i < PARTY_SIZE; i++)
    {
        if (!GetMonData(&gPlayerParty[i], MON_DATA_SPECIES))
            continue;

        u32 strain = GetMonData(&gPlayerParty[i], MON_DATA_POKERUS_STRAIN);
        u32 daysLeft = GetMonData(&gPlayerParty[i], MON_DATA_POKERUS_DAYS_LEFT);
        if (daysLeft)
        {
            if (daysLeft < days)
                daysLeft = 0;
            else
                daysLeft -= days;

            //If the strain was 0, we changed it to 1 when the pokerus disappear to remember the pokemon was infected by pokerus
            // (otherwise its data would look the same as unaffected pokemon)
            if (daysLeft == 0 && strain == 0)
            {
                strain = 1;
                SetMonData(&gPlayerParty[i], MON_DATA_POKERUS_STRAIN, &strain);
            }

            SetMonData(&gPlayerParty[i], MON_DATA_POKERUS_DAYS_LEFT, &daysLeft);
        }
    }
}

static void SpreadPokerusToSpecificMon(struct Pokemon *mon, u32 strain, u32 daysLeft)
{
    SetMonData(mon, MON_DATA_POKERUS_STRAIN, &strain);
    if (GetGenConfig(POKERUS_CONFIG_SPREAD_DAYS_LEFT) < GEN_3)
        daysLeft = GetDaysLeftBasedOnStrain(strain);
    SetMonData(mon, MON_DATA_POKERUS_DAYS_LEFT, &daysLeft);
}

static bool32 CanReceivePokerusFromSpread(struct Pokemon *mon)
{
    if (GetGenConfig(POKERUS_CONFIG_WEAK_VARIANT))
        return !GetMonData(mon, MON_DATA_POKERUS_STRAIN);
    return !GetMonData(mon, MON_DATA_POKERUS);
}

void PartySpreadPokerus(void)
{
    if (!GetGenConfig(POKERUS_CONFIG_ENABLED))
        return;

    if (RandomUniform(RNG_POKERUS_SPREAD, 0, MAX_u16) >= POKERUS_SPREAD_ODDS)
        return;

    for (u32 i = 0; i < PARTY_SIZE; i++)
    {
        if (!GetMonData(&gPlayerParty[i], MON_DATA_SPECIES))
            continue;

        u32 strain = GetMonData(&gPlayerParty[i], MON_DATA_POKERUS_STRAIN);
        u32 daysLeft = GetMonData(&gPlayerParty[i], MON_DATA_POKERUS_DAYS_LEFT);
        if (daysLeft)
        {
            bool32 spreadUp = TRUE, spreadDown = TRUE;
            if (GetGenConfig(POKERUS_CONFIG_SPREAD_ADJACENCY) < GEN_3)
            {
                if (i == (gPlayerPartyCount - 1))
                    spreadUp = FALSE;
                else if (RandomUniform(RNG_POKERUS_SPREAD_SIDE, 0, 1))
                    spreadDown = FALSE;
                else
                    spreadUp = FALSE;
            }
            if (spreadDown && i != 0 && CanReceivePokerusFromSpread(&gPlayerParty[i - 1]))
                SpreadPokerusToSpecificMon(&gPlayerParty[i - 1], strain, daysLeft);
            if (spreadUp && i != (PARTY_SIZE - 1) && CanReceivePokerusFromSpread(&gPlayerParty[i + 1]))
            {
                SpreadPokerusToSpecificMon(&gPlayerParty[i + 1], strain, daysLeft);
                i++;
            }
        }
    }
}
