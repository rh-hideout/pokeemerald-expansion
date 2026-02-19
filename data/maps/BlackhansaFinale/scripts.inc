BlackhansaFinale_MapScripts::
    map_script MAP_SCRIPT_ON_LOAD, BlackhansaFinale_OnLoad
    .byte 0

BlackhansaFinale_OnLoad:
    goto_if_unset FLAG_CTF_BLACKHANSA_FINALE_FLAG8_DONE, BlackhansaFinale_OnLoad_End
    call BlackhansaFinale_EventScript_ApplyFlag8Tiles
BlackhansaFinale_OnLoad_End:
    end


@ ---------------------------------------------------------
@ Coord Trigger: erstes Mal -> Intro, 7 Schritte vor, Kampf
@ ---------------------------------------------------------
BlackhansaFinale_EventScript_IntroTrigger::
    lockall
    goto_if_set FLAG_HIDE_BLACKHANSA_BOSS, BlackhansaFinale_End
    goto_if_set FLAG_BLACKHANSA_INTRO_DONE, BlackhansaFinale_End

    msgbox BlackhansaFinale_Text_Intro, MSGBOX_DEFAULT
    closemessage

    applymovement LOCALID_PLAYER, BlackhansaFinale_Movement_PlayerForward7
    waitmovement 0

    @ <<< Das hier ist der wichtige Teil >>>
    turnobject LOCALID_PLAYER, DIR_NORTH

    setflag FLAG_BLACKHANSA_INTRO_DONE
    goto BlackhansaFinale_EventScript_StartBattle



@ ---------------------------------------------------------
@ Boss ansprechen -> Kampf (Rematch möglich)
@ ---------------------------------------------------------
BlackhansaFinale_EventScript_BossTalk::
    lockall
    faceplayer
    goto_if_set FLAG_HIDE_BLACKHANSA_BOSS, BlackhansaFinale_End
    goto BlackhansaFinale_EventScript_StartBattle


@ ---------------------------------------------------------
@ Kampf + After-Win Branching
@ ---------------------------------------------------------
BlackhansaFinale_EventScript_StartBattle::
    cleartrainerflag TRAINER_MARLEY

    trainerbattle_single TRAINER_MARLEY, BlackhansaFinale_Text_PreBattle, BlackhansaFinale_Text_Defeat, BlackhansaFinale_EventScript_AfterWin
    goto BlackhansaFinale_End


BlackhansaFinale_EventScript_AfterWin::
    goto_if_set FLAG_BLACKHANSA_DITTO_COPIED, BlackhansaFinale_EventScript_FinalDefeat

    msgbox BlackhansaFinale_Text_NoCopyWin, MSGBOX_DEFAULT
    cleartrainerflag TRAINER_MARLEY
    goto BlackhansaFinale_End


@ ---------------------------------------------------------
@ Finale Cutscene (nach Copy-Flag + Sieg)
@ ---------------------------------------------------------
BlackhansaFinale_EventScript_FinalDefeat::
    turnobject LOCALID_BLACKHANSA_FINALE_BOSS, DIR_WEST
    msgbox BlackhansaFinale_Text_That1, MSGBOX_DEFAULT
    closemessage

    applymovement LOCALID_BLACKHANSA_FINALE_BOSS, BlackhansaFinale_Movement_BossWalkLeft1
    waitmovement 0

    msgbox BlackhansaFinale_Text_That2, MSGBOX_DEFAULT
    closemessage

    applymovement LOCALID_BLACKHANSA_FINALE_BOSS, BlackhansaFinale_Movement_BossWalkLeft1
    waitmovement 0

    msgbox BlackhansaFinale_Text_That3, MSGBOX_DEFAULT
    closemessage

    turnobject LOCALID_BLACKHANSA_FINALE_BOSS, DIR_SOUTH
    applymovement LOCALID_BLACKHANSA_FINALE_BOSS, BlackhansaFinale_Movement_BossSlideLeft3_FaceDown
    waitmovement 0

    setflag FLAG_HIDE_BLACKHANSA_BOSS
    removeobject LOCALID_BLACKHANSA_FINALE_BOSS

    goto BlackhansaFinale_End


BlackhansaFinale_End::
    releaseall
    end


@ ----------------
@ Bewegungen
@ ----------------
BlackhansaFinale_Movement_PlayerForward7:
    walk_up
    walk_up
    walk_up
    walk_up
    walk_up
    walk_up
    walk_up
    step_end

BlackhansaFinale_Movement_BossWalkLeft1:
    walk_left
    step_end

BlackhansaFinale_Movement_BossSlideLeft3_FaceDown:
    face_down
    slide_left
    slide_left
    slide_left
    step_end


@ ----------------
@ Texte
@ ----------------
BlackhansaFinale_Text_Intro:
    .string "You've come a long way, kid.\n"
    .string "But this is where it ends.\p"
    .string "Only my POKéMON knows the final flag,\n"
    .string "and it will never tell it to you.\p"
    .string "Now get ready to be destroyed.$"

BlackhansaFinale_Text_PreBattle:
    .string "Prepare to be destroyed!$"

BlackhansaFinale_Text_Defeat:
    .string "No..$"

BlackhansaFinale_Text_NoCopyWin:
    .string "You can't defeat us!$"

BlackhansaFinale_Text_That1:
    .string "That...$"

BlackhansaFinale_Text_That2:
    .string "that...$"

BlackhansaFinale_Text_That3:
    .string " can't be. Defeated by a child...\n"
    .string "everything gone...$"


@ =========================================================
@ CTF Terminal (Flag 8) - BlackhansaFinale
@ =========================================================

BlackhansaFinale_EventScript_CtfTerminal_Flag8::
    lock
    faceplayer

    goto_if_set FLAG_CTF_BLACKHANSA_FINALE_FLAG8_DONE, BlackhansaFinale_Terminal_AlreadySolved

    msgbox BlackhansaFinale_Text_TerminalPrompt, MSGBOX_DEFAULT
    closemessage

    setvar VAR_0x8000, 10
    callnative Ctf_FlagTerminal
    waitstate

    compare VAR_RESULT, TRUE
    goto_if_eq BlackhansaFinale_Terminal_Correct

    msgbox BlackhansaFinale_Text_TerminalWrong, MSGBOX_DEFAULT
    release
    end

BlackhansaFinale_Terminal_Correct:
    setflag FLAG_CTF_BLACKHANSA_FINALE_FLAG8_DONE
    call BlackhansaFinale_EventScript_ApplyFlag8Tiles
    msgbox BlackhansaFinale_Text_TerminalCorrect, MSGBOX_DEFAULT
    release
    end

BlackhansaFinale_Terminal_AlreadySolved:
    msgbox BlackhansaFinale_Text_TerminalAlreadySolved, MSGBOX_DEFAULT
    release
    end


@ =========================================================
@ Tile Swap (instant sichtbar + begehbar)
@ =========================================================

BlackhansaFinale_EventScript_ApplyFlag8Tiles::
    setmetatile 7, 1, 0x24E, FALSE
    special DrawWholeMapView
    return


@ =========================================================
@ Terminal Texte
@ =========================================================

BlackhansaFinale_Text_TerminalPrompt:
    .string "Bitte Flag 8 eingeben.$"

BlackhansaFinale_Text_TerminalWrong:
    .string "Falsche Eingabe.$"

BlackhansaFinale_Text_TerminalCorrect:
    .string "Zugriff gewährt.$"

BlackhansaFinale_Text_TerminalAlreadySolved:
    .string "Terminal ist bereits freigeschaltet.$"
