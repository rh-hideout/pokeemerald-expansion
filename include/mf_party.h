#ifndef GUARD_MF_PARTY_H
#define GUARD_MF_PARTY_H

// S40 — runtime party-size cap (Difficulty PARTY LIMIT).
// ME: GetMaxPartySize() = 6 - tx_Challenges_PartyLimit.
// Enforcement lives at catch / gift / PC withdraw / daycare; see ADR 0041.

#include "gba/types.h"

// Pure helpers (unit-testable). partyLimit is the stored menu index:
// 0 = Off (max 6), 1 = max 5, …, 5 = max 1.
u8 MfResolveMaxPartySize(u8 partyLimit);
bool8 MfIsPartyCountAtLimit(u8 partyCount, u8 maxPartySize);

// Live wrappers over MfRules_GetMaxPartySize / CalculatePlayerPartyCount.
u8 MfGetMaxPartySize(void); // ME GetMaxPartySize; also a script special
bool8 MfIsPlayerPartyAtLimit(void);

#endif // GUARD_MF_PARTY_H
