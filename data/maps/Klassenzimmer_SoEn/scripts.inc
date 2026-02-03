Klassenzimmer_SoEn_MapScripts::
    map_script MAP_SCRIPT_ON_TRANSITION, Klassenzimmer_SoEn_OnTransition
    map_script MAP_SCRIPT_ON_FRAME_TABLE, Klassenzimmer_SoEn_OnFrame
    .byte 0


@ =========================================================
@ On Transition
@ - VAR_TEMP_0: Intro (Raspberry) trigger (0 = trigger)
@ - VAR_TEMP_1: Strength/Powerglove trigger (0 = trigger)
@ =========================================================
Klassenzimmer_SoEn_OnTransition:
    @ Default: nichts automatisch triggern
    setvar VAR_TEMP_0, 1
    setvar VAR_TEMP_1, 1

    @ Wenn Intro noch NICHT passiert ist -> Intro im Frame triggern
    goto_if_set FLAG_CTF_CLASSROOM_APPLES_RASPBERRY, Klassenzimmer_SoEn_OnTransition_CheckStrength
    setvar VAR_TEMP_0, 0
    end

Klassenzimmer_SoEn_OnTransition_CheckStrength:
    @ Intro ist schon passiert -> ggf. Strength-Szene triggern (nur wenn Tap done & nicht schon done)
    goto_if_set FLAG_CLASSROOM_STRENGTH_TOOL_SCENE_DONE, Klassenzimmer_SoEn_OnTransition_End
    goto_if_set FLAG_BLACKHANSA_SERVER_TAP_DONE, Klassenzimmer_SoEn_OnTransition_EnableStrength
    end

Klassenzimmer_SoEn_OnTransition_EnableStrength:
    setvar VAR_TEMP_1, 0
    end

Klassenzimmer_SoEn_OnTransition_End:
    end


@ =========================================================
@ On Frame
@ =========================================================
Klassenzimmer_SoEn_OnFrame:
    map_script_2 VAR_TEMP_0, 0, Klassenzimmer_SoEn_EventScript_FirstEntry
    map_script_2 VAR_TEMP_1, 0, Klassenzimmer_SoEn_EventScript_StrengthToolScene
    .2byte 0


@ =========================================================
@ Erstes Betreten: Raspberry Pi Szene (einmalig)
@ =========================================================
Klassenzimmer_SoEn_EventScript_FirstEntry::
    @ sofort deaktivieren, damit es nicht mehrfach triggert
    setvar VAR_TEMP_0, 1
    setflag FLAG_CTF_CLASSROOM_APPLES_RASPBERRY

    lockall

    turnobject LOCALID_PROF_APPLES, DIR_SOUTH
    turnobject LOCALID_PLAYER, DIR_NORTH

    msgbox Klassenzimmer_SoEn_Text_ComeIn, MSGBOX_DEFAULT
    closemessage

    applymovement LOCALID_PLAYER, Klassenzimmer_SoEn_Movement_PlayerToSeat
    waitmovement 0

    msgbox Klassenzimmer_SoEn_Text_Story, MSGBOX_DEFAULT
    closemessage

    giveitem ITEM_RASPBERRY_PI, 1

    msgbox Klassenzimmer_SoEn_Text_StudentReceivesPi, MSGBOX_DEFAULT
    closemessage

    releaseall
    end


@ =========================================================
@ Powerglove/Strength-Tool Szene (einmalig, wenn TAP-Flag gesetzt)
@ - KEIN applymovement hier (Freeze-Schutz)
@ =========================================================
Klassenzimmer_SoEn_EventScript_StrengthToolScene::
    @ sofort deaktivieren, damit es nicht mehrfach triggert
    setvar VAR_TEMP_1, 1

    @ nur wenn Tap wirklich done ist
    goto_if_set FLAG_BLACKHANSA_SERVER_TAP_DONE, Klassenzimmer_SoEn_EventScript_StrengthToolScene_CheckOnce
    end

Klassenzimmer_SoEn_EventScript_StrengthToolScene_CheckOnce:
    @ nur einmal insgesamt
    goto_if_set FLAG_CLASSROOM_STRENGTH_TOOL_SCENE_DONE, Klassenzimmer_SoEn_EventScript_StrengthToolScene_End

    lockall

    turnobject LOCALID_PROF_APPLES, DIR_SOUTH
    turnobject LOCALID_PLAYER, DIR_NORTH

    msgbox Klassenzimmer_SoEn_Text_StrengthTool_Blabla, MSGBOX_DEFAULT
    closemessage

    giveitem ITEM_STRENGTH_TOOL, 1

    msgbox Klassenzimmer_SoEn_Text_StrengthTool_Thought, MSGBOX_DEFAULT
    closemessage

    setflag FLAG_CLASSROOM_STRENGTH_TOOL_SCENE_DONE

    releaseall
    end

Klassenzimmer_SoEn_EventScript_StrengthToolScene_End:
    end


@ =========================================================
@ Talk Script: PROF. APPLES
@ - Nach Raspberry, bevor Tap-Flag gesetzt: eigener Dialog
@ - Wenn Tap-Flag gesetzt, aber Szene noch nicht gelaufen: schaltet Szene frei (VAR_TEMP_1 = 0)
@ =========================================================
Klassenzimmer_SoEn_EventScript_ProfApples::
    lock
    faceplayer

    @ Wenn Intro noch nicht durch ist
    goto_if_set FLAG_CTF_CLASSROOM_INTRO_DONE, Klassenzimmer_SoEn_ProfApples_AfterIntro
    msgbox Klassenzimmer_SoEn_Text_ProfApples_BeforeIntro, MSGBOX_DEFAULT
    release
    end

Klassenzimmer_SoEn_ProfApples_AfterIntro:
    @ Nach Strength-Szene
    goto_if_set FLAG_CLASSROOM_STRENGTH_TOOL_SCENE_DONE, Klassenzimmer_SoEn_ProfApples_AfterStrengthDone

    @ Wenn Tap done: Szene fürs nächste Frame freischalten
    goto_if_set FLAG_BLACKHANSA_SERVER_TAP_DONE, Klassenzimmer_SoEn_ProfApples_EnableStrength

    @ Sonst: Raspberry bekommen, aber Tap noch nicht
    msgbox Klassenzimmer_SoEn_Text_ProfApples_AfterRaspberry_BeforeTap, MSGBOX_DEFAULT
    release
    end

Klassenzimmer_SoEn_ProfApples_EnableStrength:
	lockall

	applymovement LOCALID_PLAYER, Klassenzimmer_SoEn_Movement_PlayerToSeat
    waitmovement 0

    msgbox Klassenzimmer_SoEn_Text_ProfApples_TapDone_Hint, MSGBOX_DEFAULT
    closemessage
    setvar VAR_TEMP_1, 0
    releaseall
    end

Klassenzimmer_SoEn_ProfApples_AfterStrengthDone:
    msgbox Klassenzimmer_SoEn_Text_ProfApples_AfterStrengthDone, MSGBOX_DEFAULT
    release
    end


@ =========================================================
@ Movement
@ =========================================================
Klassenzimmer_SoEn_Movement_PlayerToSeat:
    walk_up
    walk_up
    walk_up
    walk_left
    walk_left
    face_up
    step_end


@ =========================================================
@ Text
@ =========================================================
Klassenzimmer_SoEn_Text_StudentReceivesPi:
    .string "{PLAYER}: Wow! A Raspberry Pi! \n"
    .string "Thank you, Mister Apples!$"

Klassenzimmer_SoEn_Text_ComeIn:
    .string "{PLAYER}: Sorry, the train \n"
    .string "was late.$"

Klassenzimmer_SoEn_Text_Story:
    .string "APPLES: For today's project, we\n"
    .string "are using a Raspberry Pi. We will\p"
    .string "use it to program a small script\n"
    .string "that allows us to record data. The\p"
    .string "best script wins a Powerglove!$"

Klassenzimmer_SoEn_Text_StrengthTool_Blabla:
    .string "APPLES: Excellent work {PLAYER}.\n"
    .string "This is some interesting data.\p"
    .string "I really hope you didn't make\n"
    .string "something illegal.$"

Klassenzimmer_SoEn_Text_StrengthTool_Thought:
    .string "{PLAYER}: <This allows me to move the\n"
    .string "entrance to this cave on the Rhein-\p"
    .string "promenade. I should test it immediately!>$"

@ --- Prof Apples Texte ---
Klassenzimmer_SoEn_Text_ProfApples_BeforeIntro:
    .string "APPLES: Now go and put a good\n"
    .string "use to it to learn something new!$"

Klassenzimmer_SoEn_Text_ProfApples_AfterRaspberry_BeforeTap:
    .string "APPLES: Now write a script that\p"
    .string "collects something measurable.\n"
    .string "Come back when you have real results.$"

Klassenzimmer_SoEn_Text_ProfApples_TapDone_Hint:
    .string "APPLES: Oh? You look like you found\p"
    .string "something important. Stay seated.$"

Klassenzimmer_SoEn_Text_ProfApples_AfterStrengthDone:
    .string "APPLES: Good work. Use the tool wisely.\p"
    .string "And please don't break anything.$"
