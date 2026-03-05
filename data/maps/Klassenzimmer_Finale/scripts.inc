Klassenzimmer_Finale_MapScripts::
    map_script MAP_SCRIPT_ON_LOAD, Klassenzimmer_Finale_OnLoad
    map_script MAP_SCRIPT_ON_TRANSITION, Klassenzimmer_Finale_OnTransition
    map_script MAP_SCRIPT_ON_FRAME_TABLE, Klassenzimmer_Finale_OnFrame
    .byte 0


@ ---------------------------------------------------------
@ OnLoad: Jessie/James/Statics immer unsichtbar halten.
@ Professor nach Intro weg.
@ Ransom Letter Ball vor Intro verstecken.
@ ---------------------------------------------------------
Klassenzimmer_Finale_OnLoad::
    setflag FLAG_HIDE_KF_JESSIE
    setflag FLAG_HIDE_KF_JAMES
    setflag FLAG_HIDE_KF_MEOWTH
    setflag FLAG_HIDE_KF_ARBOK
    setflag FLAG_HIDE_KF_WEEZING

    goto_if_set FLAG_KF_INTRO_DONE, Klassenzimmer_Finale_OnLoad_AfterIntro

    setflag FLAG_HIDE_KF_RANSOM_LETTER_BALL
    end

Klassenzimmer_Finale_OnLoad_AfterIntro::
    setflag FLAG_HIDE_KF_PROFESSOR
    end


@ ---------------------------------------------------------
@ OnTransition: NUR vorbereiten! 
@ ---------------------------------------------------------
Klassenzimmer_Finale_OnTransition::
    goto_if_set FLAG_KF_INTRO_DONE, Klassenzimmer_Finale_OnTransition_Done

    @ Cutscene soll im Frame-Loop starten
    setvar VAR_TEMP_0, 0

    @ Teleporter initial deaktiviert
    setvar VAR_KF_STADIUM_SOLVED, 0
    end

Klassenzimmer_Finale_OnTransition_Done::
    @ Sicherheit: falls VAR_TEMP_0 noch 0 wäre
    setvar VAR_TEMP_0, 1
    end


@ ---------------------------------------------------------
@ OnFrame: Cutscene erst starten, wenn Map sichtbar ist
@ ---------------------------------------------------------
Klassenzimmer_Finale_OnFrame::
    map_script_2 VAR_TEMP_0, 0, Klassenzimmer_Finale_EventScript_Intro
    .2byte 0


@ ---------------------------------------------------------
@ Intro-Cutscene
@ ---------------------------------------------------------
Klassenzimmer_Finale_EventScript_Intro::
    @ sofort deaktivieren, damit es nicht mehrfach triggert
    setvar VAR_TEMP_0, 1
    setflag FLAG_KF_INTRO_DONE

    lockall

    msgbox Klassenzimmer_Finale_Text_BetterGoToMyDesk, MSGBOX_DEFAULT

    applymovement LOCALID_PLAYER, Klassenzimmer_Finale_Movement_PlayerToDesk
    waitmovement 0

    msgbox Klassenzimmer_Finale_Text_TodayInForensics, MSGBOX_DEFAULT

    playse SE_M_EXPLOSION
    waitse

    msgbox Klassenzimmer_Finale_Text_WhatWasThat, MSGBOX_DEFAULT

    playbgm MUS_RG_ENCOUNTER_ROCKET, TRUE

    msgbox Klassenzimmer_Finale_Text_JessieLine, MSGBOX_DEFAULT
    msgbox Klassenzimmer_Finale_Text_JamesLine, MSGBOX_DEFAULT
    msgbox Klassenzimmer_Finale_Text_PlayerLine, MSGBOX_DEFAULT

    @ Jessie & James spawnen auf x10y9 / x11y9
    clearflag FLAG_HIDE_KF_JESSIE
    clearflag FLAG_HIDE_KF_JAMES
    addobject LOCALID_KF_JESSIE
    addobject LOCALID_KF_JAMES
    setobjectxy LOCALID_KF_JESSIE, 10, 9
    setobjectxy LOCALID_KF_JAMES, 11, 9

    playse SE_BALL_OPEN
    dofieldeffectsparkle 10, 9, 0
    dofieldeffectsparkle 11, 9, 0
    waitfieldeffect FLDEFF_SPARKLE
    special DrawWholeMapView

    @ Beide laufen erst 2 hoch
    applymovement LOCALID_KF_JESSIE, Klassenzimmer_Finale_Movement_Jessie_Up2
    applymovement LOCALID_KF_JAMES,  Klassenzimmer_Finale_Movement_James_Up2
    waitmovement 0

    @ Nach 2 hoch: 3 statische Objekte aus Pokeball
    clearflag FLAG_HIDE_KF_MEOWTH
    clearflag FLAG_HIDE_KF_ARBOK
    clearflag FLAG_HIDE_KF_WEEZING
    addobject LOCALID_KF_MEOWTH
    addobject LOCALID_KF_ARBOK
    addobject LOCALID_KF_WEEZING
    setobjectxy LOCALID_KF_MEOWTH, 9, 7
    setobjectxy LOCALID_KF_ARBOK,  9, 9
    setobjectxy LOCALID_KF_WEEZING, 0, 5

    playse SE_BALL_OPEN
    dofieldeffectsparkle 9, 7, 0
    dofieldeffectsparkle 9, 9, 0
    dofieldeffectsparkle 0, 5, 0
    waitfieldeffect FLDEFF_SPARKLE
    special DrawWholeMapView

    @ Jessie: noch 3 hoch, dann links schauen
    @ James: noch 4 hoch + 1 links, dann links schauen
    applymovement LOCALID_KF_JESSIE, Klassenzimmer_Finale_Movement_Jessie_Rest
    applymovement LOCALID_KF_JAMES,  Klassenzimmer_Finale_Movement_James_Rest
    waitmovement 0

    msgbox Klassenzimmer_Finale_Text_Bounty, MSGBOX_DEFAULT

    @ Professor (x9y3) "einpacken" und weg
    playse SE_BALL_TRADE
    dofieldeffectsparkle 9, 3, 0
    waitfieldeffect FLDEFF_SPARKLE
    setflag FLAG_HIDE_KF_PROFESSOR
    removeobject LOCALID_KF_PROFESSOR
    special DrawWholeMapView

    @ Jessie & James fliehen gleichzeitig (Türsound)
    playse SE_DOOR
    applymovement LOCALID_KF_JESSIE, Klassenzimmer_Finale_Movement_Jessie_Exit
    applymovement LOCALID_KF_JAMES,  Klassenzimmer_Finale_Movement_James_Exit
    waitmovement 0

    setflag FLAG_HIDE_KF_JESSIE
    setflag FLAG_HIDE_KF_JAMES
    removeobject LOCALID_KF_JESSIE
    removeobject LOCALID_KF_JAMES
    special DrawWholeMapView

    @ Statics zurück in Pokeball
    playse SE_BALL_TRADE
    dofieldeffectsparkle 9, 7, 0
    dofieldeffectsparkle 9, 9, 0
    dofieldeffectsparkle 0, 5, 0
    waitfieldeffect FLDEFF_SPARKLE

    setflag FLAG_HIDE_KF_MEOWTH
    setflag FLAG_HIDE_KF_ARBOK
    setflag FLAG_HIDE_KF_WEEZING
    removeobject LOCALID_KF_MEOWTH
    removeobject LOCALID_KF_ARBOK
    removeobject LOCALID_KF_WEEZING
    special DrawWholeMapView

    @ Ransom Letter Ball spawnen (x10y4)
    clearflag FLAG_HIDE_KF_RANSOM_LETTER_BALL
    addobject LOCALID_KF_RANSOM_LETTER_BALL
    setobjectxy LOCALID_KF_RANSOM_LETTER_BALL, 10, 4
    playse SE_BALL_OPEN
    dofieldeffectsparkle 10, 4, 0
    waitfieldeffect FLDEFF_SPARKLE
    special DrawWholeMapView

    @ Classmate (gleichzeitig Clue NPC) läuft hin
    applymovement LOCALID_KF_CLASSMATE, Klassenzimmer_Finale_Movement_Classmate_ToLetter
    waitmovement 0
    msgbox Klassenzimmer_Finale_Text_WhatIsThis, MSGBOX_DEFAULT

    fadedefaultbgm

    releaseall
    end


@ ---------------------------------------------------------
@ Teleporter blockiert (Coord-Event auf x10y9 & x11y9 solange VAR==0)
@ ---------------------------------------------------------
Klassenzimmer_Finale_EventScript_TeleporterBlocked::
    lockall
    msgbox Klassenzimmer_Finale_Text_TeleporterBlocked, MSGBOX_DEFAULT
    applymovement LOCALID_PLAYER, Klassenzimmer_Finale_Movement_PlayerStepUp
    waitmovement 0
    releaseall
    end


@ ---------------------------------------------------------
@ Classmate == Clue
@ ---------------------------------------------------------
Klassenzimmer_Finale_EventScript_ClassmateClue::
    lock
    faceplayer

    goto_if_eq VAR_KF_STADIUM_SOLVED, 1, Klassenzimmer_Finale_Clue_AlreadySolved

    msgbox Klassenzimmer_Finale_Text_CluePrompt, MSGBOX_DEFAULT
    closemessage

    @ Einmalige Eingabe (kein Loop)
    setvar VAR_0x8000, 11
    callnative Ctf_FlagTerminal
    waitstate

    goto_if_eq VAR_RESULT, 1, Klassenzimmer_Finale_Clue_Correct

Klassenzimmer_Finale_Clue_Wrong:
    msgbox Klassenzimmer_Finale_Text_ClueWrong, MSGBOX_DEFAULT
    release
    end

Klassenzimmer_Finale_Clue_AlreadySolved:
    msgbox Klassenzimmer_Finale_Text_ClueAlreadySolved, MSGBOX_DEFAULT
    release
    end

Klassenzimmer_Finale_Clue_Correct:
    msgbox Klassenzimmer_Finale_Text_ClueCorrect, MSGBOX_DEFAULT
    closemessage

    giveitem ITEM_WATERFALL_TOOL, 1
    goto_if_eq VAR_RESULT, 0, Klassenzimmer_Finale_Clue_BagFull

    setvar VAR_KF_STADIUM_SOLVED, 1
    msgbox Klassenzimmer_Finale_Text_TeleportersNowWork, MSGBOX_DEFAULT
    release
    end

Klassenzimmer_Finale_Clue_BagFull:
    msgbox Klassenzimmer_Finale_Text_BagFull, MSGBOX_DEFAULT
    release
    end


@ ---------------------------------------------------------
@ Ransom Letter Ball (Pokéball-Objekt)
@ ---------------------------------------------------------
Klassenzimmer_Finale_EventScript_RansomLetterBall::
    finditem ITEM_GAME_BOY_CART, 1
    end


@ ---------------------------------------------------------
@ Movements
@ ---------------------------------------------------------
Klassenzimmer_Finale_Movement_PlayerToDesk:
    walk_up
    walk_up
    walk_up
    walk_left
    walk_left
    walk_left
    face_up
    step_end

Klassenzimmer_Finale_Movement_PlayerStepUp:
    walk_up
    step_end

Klassenzimmer_Finale_Movement_Jessie_Up2:
    walk_up
    walk_up
    step_end

Klassenzimmer_Finale_Movement_James_Up2:
    walk_up
    walk_up
    step_end

Klassenzimmer_Finale_Movement_Jessie_Rest:
    walk_up
    walk_up
    walk_up
    face_left
    step_end

Klassenzimmer_Finale_Movement_James_Rest:
    walk_up
    walk_up
    walk_up
    walk_up
    walk_left
    face_left
    step_end

Klassenzimmer_Finale_Movement_James_Exit:
    walk_right
    walk_down
    walk_down
    walk_down
    walk_down
    walk_down
    walk_down
    step_end

Klassenzimmer_Finale_Movement_Jessie_Exit:
    walk_down
    walk_down
    walk_down
    walk_down
    walk_down
    step_end

Klassenzimmer_Finale_Movement_Classmate_ToLetter:
    walk_right
    walk_up
    walk_up
    walk_up
    walk_up
    walk_up
    face_right
    step_end


@ ---------------------------------------------------------
@ Texte
@ ---------------------------------------------------------
Klassenzimmer_Finale_Text_BetterGoToMyDesk::
    .string "{PLAYER}: Better go to my desk.$"

Klassenzimmer_Finale_Text_TodayInForensics::
    .string "PROF. BAMBERGER: Today in \n"
    .string "Forensics, we...$"

Klassenzimmer_Finale_Text_WhatWasThat::
    .string "What was that?!$"

Klassenzimmer_Finale_Text_JessieLine::
    .string "JESSIE: Prepare for trouble...$"

Klassenzimmer_Finale_Text_JamesLine::
    .string "JAMES: and make it double!$"

Klassenzimmer_Finale_Text_PlayerLine::
    .string "{PLAYER}: Oh no, not again!$"

Klassenzimmer_Finale_Text_Bounty::
    .string "JESSIE: Time to collect our\n"
    .string "Bounty from BLACKHANSA.$"

Klassenzimmer_Finale_Text_WhatIsThis::
    .string "ADRIA: What is this?$"

Klassenzimmer_Finale_Text_CluePrompt::
    .string "ADRIA: Did you find a clue\n"
    .string "about their whereabouts?\p"
    .string "Why would TEAM ROCKET\n"
    .string "have a POKéMON GAME\p"
    .string "with them? Especially when\n"
    .string "kidnapping PROF BAMBERGER?!\p"
    .string "How strange...\n"
    .string "its even from the 3rd gen!\p"
    .string "That's sooo ooold!!$"

Klassenzimmer_Finale_Text_ClueWrong::
    .string "ADRIA: No... that can't be it.$"

Klassenzimmer_Finale_Text_ClueAlreadySolved::
    .string "ADRIA: We have to hurry.$"

Klassenzimmer_Finale_Text_ClueCorrect::
    .string "ADRIA: That's it. You have to surf\n"
    .string "down the Neckar on Route 101, to \p"
    .string "reach it.\p"
    .string "Here take this, you will need this\n"
    .string "to get over the waterfall.$"

Klassenzimmer_Finale_Text_TeleportersNowWork::
    .string "{PLAYER}: I should go now.$"

Klassenzimmer_Finale_Text_BagFull::
    .string "Your Bag is full.$"

Klassenzimmer_Finale_Text_TeleporterBlocked::
    .string "{PLAYER}: I have to find the \n"
    .string "clue first.$"

