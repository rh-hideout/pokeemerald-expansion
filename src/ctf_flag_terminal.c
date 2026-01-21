#include "global.h"
#include "ctf_flags.h"

#include "naming_screen.h"
#include "overworld.h"
#include "save.h"
#include "script.h"

// ============================================================================
// "Terminal" callable from scripts via `callnative Ctf_FlagTerminal`
// ============================================================================
//
// Usage in script (poryscript):
//   setvar VAR_0x8000, 1   // gymId 1..8
//   callnative Ctf_FlagTerminal
//   waitstate
//   compare VAR_RESULT, 1
//   if eq goto .success
//
// Result:
//   VAR_RESULT (gSpecialVar_Result) = 1 on success, 0 otherwise.

static bool8 sCtfTerminalActive;
static bool8 sCtfTerminalDone;
static u8 sCtfGymId;
static u8 sCtfInput[PLAYER_NAME_LENGTH + 1];

static void CB2_ReturnToFieldContinueScript_CtfTerminal(void)
{
    // Validate input and store result for the script.
    gSpecialVar_Result = Ctf_IsGymFlagCorrect(sCtfGymId, sCtfInput);

    // Mark terminal flow complete and continue the running script.
    sCtfTerminalDone = TRUE;
    CB2_ReturnToFieldContinueScript();
}

// Native script callback for `callnative`.
// Return TRUE to continue script execution, FALSE to keep waiting.
bool8 Ctf_FlagTerminal(void)
{
    if (!sCtfTerminalActive)
    {
        sCtfGymId = (u8)gSpecialVar_0x8000; // script passes gymId via 0x8000

        // Invalid gymId -> fail fast
        if (sCtfGymId == 0 || sCtfGymId > CTF_GYM_COUNT)
        {
            gSpecialVar_Result = 0;
            return TRUE;
        }

        sCtfTerminalActive = TRUE;
        sCtfTerminalDone = FALSE;
        sCtfInput[0] = EOS;

        // Open the vanilla player naming screen to enter the flag word.
        // Note: This limits input to PLAYER_NAME_LENGTH.
        DoNamingScreen(
            NAMING_SCREEN_PLAYER,
            sCtfInput,
            gSaveBlock2Ptr->playerGender,
            0,
            0,
            CB2_ReturnToFieldContinueScript_CtfTerminal
        );

        return FALSE; // script waits until naming screen returns
    }

    if (sCtfTerminalDone)
    {
        // Reset state for next terminal use.
        sCtfTerminalActive = FALSE;
        return TRUE;
    }

    return FALSE;
}
