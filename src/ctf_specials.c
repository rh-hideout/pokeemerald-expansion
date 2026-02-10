// src/ctf_specials.c
#include "global.h"
#include "pokemon.h"
#include "event_data.h"       // VarGet
#include "constants/vars.h"   // VAR_0x8004

u32 Special_PartyContainsSpecies(void)
{
    u16 target = VarGet(VAR_0x8004);
    u8 i;

    for (i = 0; i < gPlayerPartyCount; i++)
    {
        u16 s = GetMonData(&gPlayerParty[i], MON_DATA_SPECIES);
        if (s == target)
            return 1;
    }
    return 0;
}
