#include "global.h"
#include "ctf_save_flag.h"
#include "ctf_flags.h"
#include "constants/characters.h"

#include <string.h>

#define CTF_FLAG_ID            4
#define CTF_MAX_WORD_LEN       7
#define CTF_ASCII_BUF_SIZE     16

// Hier liegt unser Speicher im Save (umgewidmetes Padding in struct Pokedex)
#define CTF_SAVE_FLAG_PTR      (gSaveBlock2Ptr->pokedex.ctfAsciiFlag)

static u8 GameUpperToAscii(u8 c)
{
    // Flag4 sind laut dir immer Buchstaben, wir akzeptieren A-Z
    if (c >= CHAR_A && c <= CHAR_Z)
        return (u8)('A' + (c - CHAR_A));
    return 0;
}

static void BuildAsciiFlag(u8 *out, u32 outSize)
{
    u8 word[PLAYER_NAME_LENGTH + 1];
    u32 i, pos = 0;

    memset(out, 0, outSize);

    Ctf_GetFlagWordUpper(CTF_FLAG_ID, word, sizeof(word));

    // Prefix: "flag{"
    if (outSize < 8)
        return;

    out[pos++] = 'f';
    out[pos++] = 'l';
    out[pos++] = 'a';
    out[pos++] = 'g';
    out[pos++] = '{';

    // Inhalt: max 7 Buchstaben
    for (i = 0; i < CTF_MAX_WORD_LEN && word[i] != EOS; i++)
    {
        if (pos + 2 >= outSize) // Platz für '}' + '\0'
            break;

        u8 a = GameUpperToAscii(word[i]);
        if (a == 0)
            break;

        out[pos++] = a;
    }

    // Suffix: "}"
    if (pos + 1 < outSize)
        out[pos++] = '}';

    // '\0' ist durch memset schon drin
}

void CtfSaveFlag_EnsureBeforeSave(void)
{
    u8 tmp[CTF_ASCII_BUF_SIZE];

    BuildAsciiFlag(tmp, sizeof(tmp));

    if (memcmp(CTF_SAVE_FLAG_PTR, tmp, sizeof(tmp)) != 0)
        memcpy(CTF_SAVE_FLAG_PTR, tmp, sizeof(tmp));
}
