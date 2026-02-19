Stadium2_MapScripts::
    map_script MAP_SCRIPT_ON_LOAD, Stadium2_OnLoad
    map_script MAP_SCRIPT_ON_TRANSITION, Stadium2_OnTransition
    map_script MAP_SCRIPT_ON_FRAME_TABLE, Stadium2_OnFrame
    .byte 0

Stadium2_OnLoad:
    @ Tür/Tile-Änderungen, falls Terminal schon gelöst
    goto_if_unset FLAG_STADIUM2_TERMINAL_SOLVED, Stadium2_OnLoad_CheckScene
    setmetatile 7, 3, 0x347, FALSE
    setmetatile 7, 2, 0x346, FALSE
    special DrawWholeMapView

Stadium2_OnLoad_CheckScene:
    @ Wenn die Cutscene schon abgeschlossen ist, sollen die Rocket-Leute weg bleiben
    goto_if_unset FLAG_STADIUM2_SCENE_DONE, Stadium2_OnLoad_End
    setflag FLAG_HIDE_STADIUM2_JESSIE
    setflag FLAG_HIDE_STADIUM2_BOSS
    setflag FLAG_HIDE_STADIUM2_MISSINGNO

Stadium2_OnLoad_End:
    end

Stadium2_OnTransition:
    @ OnTransition nur vorbereiten (kein msgbox / keine Bewegungen)
    goto_if_set FLAG_STADIUM2_SCENE_DONE, Stadium2_OnTransition_End
    setvar VAR_TEMP_0, 0
    end

Stadium2_OnTransition_End:
    end

Stadium2_OnFrame:
    @ Cutscene erst starten, wenn Map sichtbar ist
    map_script_2 VAR_TEMP_0, 0, Stadium2_EventScript_Intro
    .2byte 0


@ =========================
@ Intro-Cutscene (erste Map-Betretung bis Sieg)
@ =========================
Stadium2_EventScript_Intro::
    @ sofort deaktivieren, damit es nicht mehrfach im Frame-Loop triggert
    setvar VAR_TEMP_0, 1

    lockall

    @ sicherstellen, dass die drei oben richtig schauen
    turnobject LOCALID_S_JESSIE, DIR_NORTH
    turnobject LOCALID_S_JAMES, DIR_NORTH
    turnobject LOCALID_S_BOSS, DIR_NORTH

    msgbox Stadium2_Text_JessieLockedIn, MSGBOX_DEFAULT
    closemessage

    applymovement LOCALID_PLAYER, Stadium2_Movement_PlayerUp7_FaceUp
    waitmovement 0

    @ 3x Klopfen
    playse SE_WALL_HIT
    waitse
    delay 10
    playse SE_WALL_HIT
    waitse
    delay 10
    playse SE_WALL_HIT
    waitse

    msgbox Stadium2_Text_ComeOut, MSGBOX_DEFAULT
    closemessage

    @ alle drei drehen sich nach Süden (zum Spieler)
    turnobject LOCALID_S_JESSIE, DIR_SOUTH
    turnobject LOCALID_S_JAMES, DIR_SOUTH
    turnobject LOCALID_S_BOSS, DIR_SOUTH

    msgbox Stadium2_Text_JamesPain, MSGBOX_DEFAULT
    closemessage

    msgbox Stadium2_Text_BossThreat, MSGBOX_DEFAULT
    closemessage

    @ dramatische Musik (Rocket Encounter)
    playbgm MUS_RG_ENCOUNTER_ROCKET, 0

    @ Missingno erscheint (Objekt muss in Porymap existieren + per Flag versteckt sein)
    clearflag FLAG_HIDE_STADIUM2_MISSINGNO
    special DrawWholeMapView
    playse SE_BALL_OPEN
    dofieldeffectsparkle 7, 6, 2

    @ Unfangbarer Wildkampf via B_FLAG_NO_CATCHING-Config-Flag
    setflag FLAG_STADIUM2_NO_CATCHING
    setwildbattle SPECIES_PIKACHU, 1, ITEM_NONE
    dowildbattle
    clearflag FLAG_STADIUM2_NO_CATCHING

    @ Nur bei Sieg weitermachen – bei Flucht/Niederlage: event soll beim nächsten Betreten wieder kommen
    goto_if_eq VAR_RESULT, 1, Stadium2_AfterBattle_Won
    releaseall
    end


Stadium2_AfterBattle_Won:
    @ Scene als erledigt markieren (damit beim nächsten Betreten nicht nochmal)
    setflag FLAG_STADIUM2_SCENE_DONE

    @ Missingno läuft weg und verschwindet
    applymovement LOCALID_S_MISSINGNO, Stadium2_Movement_Missingno_Leave
    waitmovement 0
    playse SE_DOOR
    removeobject LOCALID_S_MISSINGNO
    setflag FLAG_HIDE_STADIUM2_MISSINGNO
    special DrawWholeMapView

    msgbox Stadium2_Text_BossWhatHaveYouDone, MSGBOX_DEFAULT
    closemessage

    @ Jessie & James gleichzeitig abhauen
    applymovement LOCALID_S_JESSIE, Stadium2_Movement_Jessie_Leave
    applymovement LOCALID_S_JAMES, Stadium2_Movement_James_Leave
    waitmovement 0

    playse SE_DOOR
    removeobject LOCALID_S_JESSIE
    removeobject LOCALID_S_JAMES
    setflag FLAG_HIDE_STADIUM2_JESSIE
    special DrawWholeMapView

    @ Boss kommt runter, spricht, haut ab
    applymovement LOCALID_S_BOSS, Stadium2_Movement_Boss_Down2
    waitmovement 0

    msgbox Stadium2_Text_BossRegion, MSGBOX_DEFAULT
    closemessage

    applymovement LOCALID_S_BOSS, Stadium2_Movement_Boss_Leave
    waitmovement 0

    playse SE_DOOR
    removeobject LOCALID_S_BOSS
    setflag FLAG_HIDE_STADIUM2_BOSS
    special DrawWholeMapView

    fadedefaultbgm

    releaseall
    end


@ =========================
@ Terminal (Flag 8)
@ =========================
Stadium2_EventScript_Terminal::
    lock
    faceplayer

    goto_if_set FLAG_STADIUM2_TERMINAL_SOLVED, Stadium2_Terminal_AlreadySolved

    msgbox Stadium2_Text_TerminalPrompt, MSGBOX_DEFAULT
    closemessage

    setvar VAR_0x8000, 8
    callnative Ctf_FlagTerminal
    waitstate

    goto_if_eq VAR_RESULT, 1, Stadium2_Terminal_Correct
    goto Stadium2_Terminal_Wrong

Stadium2_Terminal_Wrong:
    msgbox Stadium2_Text_TerminalWrong, MSGBOX_DEFAULT
    release
    end

Stadium2_Terminal_AlreadySolved:
    msgbox Stadium2_Text_TerminalAlready, MSGBOX_DEFAULT
    release
    end

Stadium2_Terminal_Correct:
    msgbox Stadium2_Text_TerminalCorrect, MSGBOX_DEFAULT
    closemessage

    setflag FLAG_STADIUM2_TERMINAL_SOLVED

    @ Tiles ändern
    setmetatile 7, 3, 0x347, FALSE
    setmetatile 7, 2, 0x346, FALSE
    special DrawWholeMapView

    release
    end


@ =========================
@ Schild
@ =========================
Stadium2_EventScript_Sign::
    msgbox Stadium2_Text_Sign, MSGBOX_DEFAULT
    end


@ =========================
@ Movements
@ =========================
Stadium2_Movement_PlayerUp7_FaceUp:
    walk_up
    walk_up
    walk_up
    walk_up
    walk_up
    walk_up
    walk_up
    face_up
    step_end

Stadium2_Movement_Missingno_Leave:
    walk_left
    walk_down
    walk_down
    walk_down
    walk_down
    walk_down
    walk_down
    walk_down
    walk_down
    step_end

Stadium2_Movement_Jessie_Leave:
    walk_down
    walk_down
    walk_left
    walk_left
    walk_left
    walk_left
    walk_left
    walk_left
    step_end

Stadium2_Movement_James_Leave:
    walk_down
    walk_down
    walk_right
    walk_right
    walk_right
    walk_right
    walk_right
    walk_right
    step_end

Stadium2_Movement_Boss_Down2:
    walk_down
    walk_down
    step_end

Stadium2_Movement_Boss_Leave:
    walk_left
    walk_down
    walk_down
    walk_down
    walk_down
    walk_down
    walk_down
    walk_down
    walk_down
    step_end


@ =========================
@ Texte
@ =========================
Stadium2_Text_JessieLockedIn:
    .string "JESSIE: He has locked\n"
    .string "himself in.$"

Stadium2_Text_ComeOut:
    .string "Come out! Don't think your\n"
    .string "escape will change anything.\p"
    .string "We'll breed the POKéMON even\n"
    .string "without you!$"

Stadium2_Text_JamesPain:
    .string "JAMES: That little pain in the\n"
    .string "ass is back again!$"

Stadium2_Text_BossThreat:
    .string "BOSS: You won't escape us this\n"
    .string "time. Our experiment will\p"
    .string "destroy you.$"

Stadium2_Text_BossWhatHaveYouDone:
    .string "BOSS: NO, WHAT HAVE YOU DONE\n"
    .string "YOU LITTLE PRICK!$"

Stadium2_Text_BossRegion:
    .string "BOSS: You little rat won't stop\n"
    .string "us. I'll make sure of that.\p"
    .string "Soon BLACKHANSA will have\n"
    .string "control over the entire region!$"


Stadium2_Text_Sign:
    .string "01001001$"


Stadium2_Text_TerminalPrompt:
    .string "Enter the Flag.$"

Stadium2_Text_TerminalWrong:
    .string "ACCESS DENIED.$"

Stadium2_Text_TerminalAlready:
    .string "The terminal is already\n"
    .string "unlocked.$"

Stadium2_Text_TerminalCorrect:
    .string "Access granted.\n"
    .string "Door unlocked.$"
