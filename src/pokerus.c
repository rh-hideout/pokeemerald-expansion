#include "global.h"
#include "event_data.h"
#include "pokemon.h"
#include "pokerus.h"
#include "random.h"

void RandomlyGivePartyPokerus(struct Pokemon *party)
{
    if (!P_POKERUS_ENABLED)
        return;

    if (!P_POKERUS_INFECT_AGAIN && CheckPartyPokerus(gPlayerParty, (1 << PARTY_SIZE) - 1))
        return;

    if (P_POKERUS_INFECTION_FLAG && !FlagGet(P_POKERUS_INFECTION_FLAG))
        return;

    u16 rnd = Random();
    if (rnd == 0x4000 || rnd == 0x8000 || rnd == 0xC000)
    {
        struct Pokemon *mon;

        do
        {
            rnd = Random() % PARTY_SIZE;
            mon = &party[rnd];
        }
        while (!GetMonData(mon, MON_DATA_SPECIES, 0) || GetMonData(mon, MON_DATA_IS_EGG, 0));

        if (!(CheckPartyHasHadPokerus(party, 1u << rnd)))
        {
            u32 strain;
            u32 daysLeft;

            if (P_POKERUS_STRAIN_DISTRIBUTION < GEN_3) // Gen 1 - 2 (Gen 1 had no pokerus but we default it with gen 2)
                strain = RandomWeighted(RNG_NONE, 15, 30, 30, 30, 30, 30, 30, 30, 30, 1, 1, 1, 1, 1, 1, 1);
            else if (P_POKERUS_STRAIN_DISTRIBUTION < GEN_5) //Gen 3 - 4
                strain = RandomWeighted(RNG_NONE, 30, 31, 31, 31, 31, 31, 31, 31, 1, 1, 1, 1, 1, 1, 1, 1);
            else // Gen 5+ (Pokerus was disabled in gen 9 but we default it here)
                strain = RandomWeighted(RNG_NONE, 0, 31, 31, 31, 31, 31, 31, 31, 0, 1, 1, 1, 1, 1, 1, 1);
            daysLeft = (strain % 4) + 1;

            SetMonData(&party[rnd], MON_DATA_POKERUS_STRAIN, &strain);
            SetMonData(&party[rnd], MON_DATA_POKERUS_DAYS_LEFT, &daysLeft);
        }
    }
}

u8 CheckPartyPokerus(struct Pokemon *party, u8 selection)
{
    if (!P_POKERUS_ENABLED)
        return FALSE;

    u8 retVal;
    int partyIndex = 0;
    unsigned curBit = 1;
    retVal = 0;

    if (selection)
    {
        do
        {
            if ((selection & 1) && GetMonData(&party[partyIndex], MON_DATA_POKERUS_DAYS_LEFT))
                retVal |= curBit;
            partyIndex++;
            curBit <<= 1;
            selection >>= 1;
        }
        while (selection);
    }
    else if (GetMonData(&party[0], MON_DATA_POKERUS_DAYS_LEFT, 0))
    {
        retVal = 1;
    }

    return retVal;
}

u8 CheckPartyHasHadPokerus(struct Pokemon *party, u8 selection)
{
    if (!P_POKERUS_ENABLED)
        return FALSE;

    u8 retVal;
    int partyIndex = 0;
    unsigned curBit = 1;
    retVal = 0;

    if (selection)
    {
        do
        {
            if ((selection & 1) && GetMonData(&party[partyIndex], MON_DATA_POKERUS_STRAIN))
                retVal |= curBit;
            partyIndex++;
            curBit <<= 1;
            selection >>= 1;
        }
        while (selection);
    }
    else if (GetMonData(&party[0], MON_DATA_POKERUS_STRAIN))
    {
        retVal = 1;
    }

    return retVal;
}

void UpdatePartyPokerusTime(u16 days)
{
    if (!P_POKERUS_ENABLED)
        return;

    int i;
    for (i = 0; i < PARTY_SIZE; i++)
    {
        if (GetMonData(&gPlayerParty[i], MON_DATA_SPECIES, 0))
        {
            u32 strain = GetMonData(&gPlayerParty[i], MON_DATA_POKERUS_STRAIN, 0);
            u32 daysLeft = GetMonData(&gPlayerParty[i], MON_DATA_POKERUS_DAYS_LEFT, 0);
            if (daysLeft)
            {
                if (daysLeft < days || days > 4)
                    daysLeft = 0;
                else
                    daysLeft -= days;

                //If the strain was 0, we changed it to 1 when the pokerus disappear to remember the pokemon was infected by pokerus
                // (otherwise its data would look the same as unaffected pokemon)
                if (daysLeft == 0 && strain == 0)
                {
                    strain = 1;
                    SetMonData(&gPlayerParty[i], MON_DATA_POKERUS, &strain);
                }

                SetMonData(&gPlayerParty[i], MON_DATA_POKERUS, &daysLeft);
            }
        }
    }
}

static void SpreadPokerusToSpecificMon(struct Pokemon *mon, u32 strain, u32 daysLeft)
{
    SetMonData(mon, MON_DATA_POKERUS_STRAIN, &strain);
    if (P_POKERUS_SPREAD_DAYS_LEFT < GEN_3)
        daysLeft = (strain % 4) + 1;
    SetMonData(mon, MON_DATA_POKERUS_DAYS_LEFT, &daysLeft);
}

void PartySpreadPokerus(struct Pokemon *party)
{
    if (!P_POKERUS_ENABLED)
        return;

    if ((Random() % 3) == 0)
    {
        int i;
        for (i = 0; i < PARTY_SIZE; i++)
        {
            if (GetMonData(&party[i], MON_DATA_SPECIES, 0))
            {
                u32 strain = GetMonData(&party[i], MON_DATA_POKERUS_STRAIN);
                u32 daysLeft = GetMonData(&party[i], MON_DATA_POKERUS_DAYS_LEFT);
                if (daysLeft)
                {
                    bool32 spreadUp = TRUE, spreadDown = TRUE;
                    if (P_POKERUS_SPREAD_ADJACENECY < GEN_3)
                    {
                        if (i == (CalculatePlayerPartyCount() - 1)
                            || (Random() % 2))
                            spreadUp = FALSE;
                        else
                            spreadDown = FALSE;
                    }
                    if (spreadDown && i != 0 && !GetMonData(&party[i - 1], MON_DATA_POKERUS_STRAIN))
                        SpreadPokerusToSpecificMon(&party[i - 1], strain, daysLeft);
                    if (spreadUp && i != (PARTY_SIZE - 1) && !GetMonData(&party[i + 1], MON_DATA_POKERUS_STRAIN))
                    {
                        SpreadPokerusToSpecificMon(&party[i + 1], strain, daysLeft);
                        i++;
                    }
                }
            }
        }
    }
}