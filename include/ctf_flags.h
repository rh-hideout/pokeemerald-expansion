#ifndef GUARD_CTF_FLAGS_H
#define GUARD_CTF_FLAGS_H

#include "global.h"

// 8 gyms -> 8 CTF flags (one per badge/gym in your concept).
#define CTF_GYM_COUNT 8

// Returns TRUE if `input` matches the flag for `gymId` (1..CTF_GYM_COUNT).
// Note: Using the vanilla player naming screen limits input to PLAYER_NAME_LENGTH (usually 7).
bool8 Ctf_IsGymFlagCorrect(u8 gymId, const u8 *input);

#endif // GUARD_CTF_FLAGS_H
