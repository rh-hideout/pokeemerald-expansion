@ =========================================================
@ Konfiguration (keine LocalId-Zahlen im Script)
@ =========================================================

@ CTF Flag-ID (dein Terminal-Code erwartet: VAR_0x8000 = Flag-ID)
#define CTF_FLAG_ID_BATTLETENT_LOBBY        4

@ Tile-Positionen und Metatiles
#define CTF_TILE_X_TOP     6
#define CTF_TILE_Y_TOP     0
#define CTF_TILE_X_BOTTOM  6
#define CTF_TILE_Y_BOTTOM  1

#define CTF_METATILE_TOP       0x253
#define CTF_METATILE_BOTTOM    0x25B

@ =========================================================
@ Map Scripts
@ =========================================================

GlitchHaus_MapScripts::
    map_script MAP_SCRIPT_ON_TRANSITION, GlitchHaus_OnTransition
    .byte 0

GlitchHaus_OnTransition:
    @ Layout umschalten
    goto_if_set FLAG_CTF_GYM4_DEFEATED, GlitchHaus_OnTransition_UseLayout2
    setmaplayoutindex LAYOUT_GLITCHHAUS

    @ DOKTOR_AFTER (FLANNERY) verstecken, solange NICHT defeated
    setflag FLAG_CTF_GLITCHHAUS_DOKTOR_AFTER_HIDDEN
    goto GlitchHaus_OnTransition_AfterLayout

GlitchHaus_OnTransition_UseLayout2:
    setmaplayoutindex LAYOUT_GLITCHHAUS_LAYOUT_2

    @ DOKTOR_AFTER sichtbar machen, sobald defeated
    clearflag FLAG_CTF_GLITCHHAUS_DOKTOR_AFTER_HIDDEN

GlitchHaus_OnTransition_AfterLayout:
    goto_if_set FLAG_CTF_BATTLETENT_LOBBY_FLAG4_DONE, GlitchHaus_OnTransition_Apply
    end

GlitchHaus_OnTransition_Apply:
    call GlitchHaus_EventScript_ApplyFlag4Tiles
    end


@ =========================================================
@ NPCs / Board / Terminal
@ =========================================================

GlitchHaus_EventScript_Doc::
    lock
    faceplayer
    goto_if_set FLAG_CTF_GYM4_DEFEATED, GlitchHaus_EventScript_Doc_After
    msgbox GlitchHaus_Text_Doc, MSGBOX_DEFAULT
    release
    end

GlitchHaus_EventScript_Doc_After:
    msgbox GlitchHaus_Text_Doc_After, MSGBOX_DEFAULT
    release
    end


GlitchHaus_EventScript_Franziska::
    lock
    faceplayer
    goto_if_set FLAG_CTF_GYM4_DEFEATED, GlitchHaus_EventScript_Franziska_After
    msgbox GlitchHaus_Text_Franziska, MSGBOX_DEFAULT
    release
    end

GlitchHaus_EventScript_Franziska_After:
    msgbox GlitchHaus_Text_Franziska_After, MSGBOX_DEFAULT
    release
    end


GlitchHaus_EventScript_BulletinBoard::
    msgbox GlitchHaus_Text_BulletinBoard, MSGBOX_DEFAULT
    end


@ =========================================================
@ CTF Terminal (Flag 4)
@ =========================================================

GlitchHaus_EventScript_CtfTerminal::
    lock
    faceplayer

    goto_if_set FLAG_CTF_BATTLETENT_LOBBY_FLAG4_DONE, GlitchHaus_Terminal_AlreadySolved

    msgbox GlitchHaus_Text_TerminalPrompt, MSGBOX_DEFAULT
    closemessage

    setvar VAR_0x8000, CTF_FLAG_ID_BATTLETENT_LOBBY
    callnative Ctf_FlagTerminal
    waitstate

    compare VAR_RESULT, TRUE
    goto_if_eq GlitchHaus_Terminal_Correct

    msgbox GlitchHaus_Text_TerminalWrong, MSGBOX_DEFAULT
    release
    end

GlitchHaus_Terminal_Correct:
    setflag FLAG_CTF_BATTLETENT_LOBBY_FLAG4_DONE
    call GlitchHaus_EventScript_ApplyFlag4Tiles
    msgbox GlitchHaus_Text_TerminalCorrect, MSGBOX_DEFAULT
    release
    end

GlitchHaus_Terminal_AlreadySolved:
    msgbox GlitchHaus_Text_TerminalAlreadySolved, MSGBOX_DEFAULT
    release
    end


@ =========================================================
@ Tile Swap (instant sichtbar + begehbar)
@ =========================================================

GlitchHaus_EventScript_ApplyFlag4Tiles::
    @ impassable = FALSE -> begehbar
    setmetatile CTF_TILE_X_TOP,    CTF_TILE_Y_TOP,    CTF_METATILE_TOP,    FALSE
    setmetatile CTF_TILE_X_BOTTOM, CTF_TILE_Y_BOTTOM, CTF_METATILE_BOTTOM, FALSE

    @ sofort sichtbar
    special DrawWholeMapView
    return


@ =========================================================
@ Text
@ =========================================================

GlitchHaus_Text_Doc:
    .string "DOC: MPFH HM MPF PFH MPF$"

GlitchHaus_Text_Doc_After:
    .string "DOC: Ah! Finally stable again.\p"
    .string "You did this, right?! Thank you!$"

GlitchHaus_Text_Franziska:
    .string "FRANZISKA: Something went wrong\n"
    .string "with the experiment and now she's\p"
    .string "stuck in the ground. Maybe you can\n"
    .string "find clues on the bulletin board.$"

GlitchHaus_Text_Franziska_After:
    .string "FRANZISKA: The distortion is gone!\p"
    .string "This place feels… normal again.$"

GlitchHaus_Text_BulletinBoard:
    .string "You only recognize a lot of\n"
    .string "scribbles and confusion, something\p"
    .string "about saving and hexing.$"

GlitchHaus_Text_TerminalPrompt:
    .string "Enter the flag.$"

GlitchHaus_Text_TerminalWrong:
    .string "Nope. That doesn't seem right.$"

GlitchHaus_Text_TerminalCorrect:
    .string "Correct. Something changed!$"

GlitchHaus_Text_TerminalAlreadySolved:
    .string "The terminal is already unlocked.$"
