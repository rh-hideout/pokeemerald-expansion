#include "global.h"
#include "ctf_flags.h"

#include "event_data.h"          // VarGet / VarSet
#include "script.h"              // ScriptContext2_Enable/Disable
#include "naming_screen.h"       // DoNamingScreen, NAMING_SCREEN_*
#include "constants/vars.h"      // VAR_0x8000, VAR_RESULT
#include "constants/characters.h"// EOS / CHAR_EOS (je nach Branch)
#include "overworld.h"           // CB2_ReturnToFieldContinueScript (oft hier deklariert)

// Größer als PLAYER_NAME_LENGTH, damit NAMING_SCREEN_CODE nicht overflowen kann
#define CTF_INPUT_BUF_SIZE 16

static u8 sCtfGymId;
static u8 sCtfInput[CTF_INPUT_BUF_SIZE];

static void CtfTerminal_ReturnFromNamingScreen(void)
{
    // Ergebnis setzen (1 = korrekt, 0 = falsch)
    VarSet(VAR_RESULT, Ctf_IsGymFlagCorrect(sCtfGymId, sCtfInput) ? 1 : 0);

    // waitstate freigeben und Script fortsetzen
    ScriptContext2_Disable();
    CB2_ReturnToFieldContinueScript();
}

// callnative Ctf_FlagTerminal
// Erwartet: VAR_0x8000 = gymId (1..8)
// Setzt:    VAR_RESULT = 1/0
bool8 Ctf_FlagTerminal(void)
{
    sCtfGymId = (u8)VarGet(VAR_0x8000);

    // Buffer leeren
    sCtfInput[0] = EOS;

    // Script soll per waitstate warten
    ScriptContext2_Enable();

    // Wichtig: NAMING_SCREEN_CODE zeigt nicht "Enter your name",
    // sondern den Code-Prompt (passt besser für Flags).
    DoNamingScreen(NAMING_SCREEN_CODE, sCtfInput, 0, 0, 0, CtfTerminal_ReturnFromNamingScreen);

    return TRUE; // One-shot native: der Script wartet über waitstate auf ScriptContext2_Disable()
}
