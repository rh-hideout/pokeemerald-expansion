#ifndef GUARD_CTF_FLAGS_H
#define GUARD_CTF_FLAGS_H

#include "global.h"

#define CTF_GYM_COUNT 8
#define CTF_FLAG_COUNT (CTF_GYM_COUNT + 2)

// Neue Flag-ID (für VAR_0x8000 am Terminal)
#define CTF_FLAG_TUTORIAL 9

// Neu: generische Prüfung für 1..CTF_FLAG_COUNT
bool8 Ctf_IsFlagCorrect(u8 flagId, const u8 *input);

// Alt lassen (Kompatibilität): prüft nur Gym 1..8
bool8 Ctf_IsGymFlagCorrect(u8 gymId, const u8 *input);

void Ctf_GetFlagWordUpper(u8 flagId, u8 *dst, u32 dstSize);

#endif // GUARD_CTF_FLAGS_H

