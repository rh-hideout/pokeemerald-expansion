Ludwigshafen_MapScripts::
    .byte 0


@ Trigger: beim Drauftreten wird das Intro einmalig abgespielt
Ludwigshafen_EventScript_IntroTrigger::
    lockall
    goto_if_set FLAG_LUDWIGSHAFEN_INTRO_DONE, Ludwigshafen_Intro_Done

    msgbox Ludwigshafen_Text_PleaseWait, MSGBOX_DEFAULT
    closemessage

    @ NPCs laufen 6 Tiles nach rechts auf den Spieler zu
    applymovement LOCALID_WANDA,  Ludwigshafen_Movement_ApproachRight6
    applymovement LOCALID_AMANDA, Ludwigshafen_Movement_ApproachRight6
    waitmovement 0

    msgbox Ludwigshafen_Text_WandaAmanda_Intro, MSGBOX_DEFAULT
    closemessage

    @ Beide laufen 23 nach links, Spieler läuft hinterher
    applymovement LOCALID_WANDA,  Ludwigshafen_Movement_WalkLeft23
    applymovement LOCALID_AMANDA, Ludwigshafen_Movement_WalkLeft23

    applymovement LOCALID_PLAYER, Ludwigshafen_Movement_WalkLeft23

    waitmovement 0

    applymovement LOCALID_AMANDA, Ludwigshafen_Movement_FaceRight
    applymovement LOCALID_WANDA,  Ludwigshafen_Movement_FaceRight

    waitmovement 0

    msgbox Ludwigshafen_Text_Both_Glitchy, MSGBOX_DEFAULT

    setflag FLAG_LUDWIGSHAFEN_INTRO_DONE

Ludwigshafen_Movement_FaceRight:
    face_right
    step_end

Ludwigshafen_Intro_Done:
    releaseall
    end


@ Nach dem Intro: beide sagen nur noch "Please hurry!"
Ludwigshafen_EventScript_Wanda_After::
    lock
    faceplayer
    msgbox Ludwigshafen_Text_Both_PleaseHurry, MSGBOX_DEFAULT
    release
    end

Ludwigshafen_EventScript_Amanda_After::
    lock
    faceplayer
    msgbox Ludwigshafen_Text_Both_PleaseHurry, MSGBOX_DEFAULT
    release
    end


@ ----------------
@ Movements
@ ----------------

Ludwigshafen_Movement_ApproachRight6:
    walk_right
    walk_right
    walk_right
    walk_right
    walk_right
    walk_right
    step_end

Ludwigshafen_Movement_WalkLeft23:
    walk_left
    walk_left
    walk_left
    walk_left
    walk_left
    walk_left
    walk_left
    walk_left
    walk_left
    walk_left
    walk_left
    walk_left
    walk_left
    walk_left
    walk_left
    walk_left
    walk_left
    walk_left
    walk_left
    walk_left
    walk_left
    walk_left
    walk_left
    step_end


@ ----------------
@ Text
@ ----------------

Ludwigshafen_Text_PleaseWait:
    .string "Hey you, please wait!$"

Ludwigshafen_Text_WandaAmanda_Intro:
    .string "WANDA: Quick, you have to help us!\p"
	.string "{PLAYER}: Sure, what's up?\n"
    .string "AMANDA: The doctor is in danger!$"

Ludwigshafen_Text_Both_Glitchy:
    .string "BOTH: Everything is so glitchy,\n"
	.string "hurry up and go inside!$"

Ludwigshafen_Text_Both_PleaseHurry:
    .string "BOTH: Please hurry!$"

