#include "global.h"
#include "mf_party.h"
#include "mf_rules.h"
#include "pokemon.h"

// Clamp to the Difficulty menu range (Off..1). Values 6–7 from the 3-bit
// field still resolve to a solo party rather than size 0.
u8 MfResolveMaxPartySize(u8 partyLimit)
{
    if (partyLimit > 5)
        partyLimit = 5;
    return 6 - partyLimit;
}

bool8 MfIsPartyCountAtLimit(u8 partyCount, u8 maxPartySize)
{
    return partyCount >= maxPartySize;
}

u8 MfGetMaxPartySize(void)
{
    return MfRules_GetMaxPartySize();
}

bool8 MfIsPlayerPartyAtLimit(void)
{
    return MfIsPartyCountAtLimit(CalculatePlayerPartyCount(), MfGetMaxPartySize());
}
