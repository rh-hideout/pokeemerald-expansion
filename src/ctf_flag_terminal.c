#include "global.h"
#include "ctf_flags.h"

#include "event_data.h"          // VarGet / VarSet
#include "script.h"              // ScriptContext_Enable
#include "naming_screen.h"       // DoNamingScreen, NAMING_SCREEN_*
#include "constants/vars.h"      // VAR_0x8000, VAR_RESULT
#include "constants/characters.h"// EOS / CHAR_EOS

// Falls dein Branch CB2_ReturnToFieldContinueScript nicht über Header findet,
// ist diese Forward-Declaration der simpelste Weg.
void CB2_ReturnToFieldContinueScript(void);

#define CTF_INPUT_BUF_SIZE 16

static u8 sCtfGymId;
static u8 sCtfInput[CTF_INPUT_BUF_SIZE];

static void CtfTerminal_ReturnFromNamingScreen(void)
{
    // Ergebnis setzen (1 = korrekt, 0 = falsch)
    VarSet(VAR_RESULT, Ctf_IsGymFlagCorrect(sCtfGymId, sCtfInput) ? 1 : 0);

    // Script/Field wieder aufnehmen (setzt intern den Script-Flow fort)
    CB2_ReturnToFieldContinueScript();
}

bool8 Ctf_FlagTerminal(void)
{
    sCtfGymId = (u8)VarGet(VAR_0x8000);

    // Buffer leeren
    sCtfInput[0] = EOS; // falls EOS nicht existiert -> unten Hinweis

    // Script “blocken”, bis Naming Screen zurückkommt
    ScriptContext_Enable();

    // Nimmt den Code-Prompt statt "Enter your name" (nur für diese Eingabe!)
    DoNamingScreen(NAMING_SCREEN_CODE, sCtfInput, 0, 0, 0, CtfTerminal_ReturnFromNamingScreen);

    return TRUE; // one-shot native
}
