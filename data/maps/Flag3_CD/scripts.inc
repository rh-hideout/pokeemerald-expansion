Flag3_CD_MapScripts::
    map_script MAP_SCRIPT_ON_TRANSITION, Flag3_CD_OnTransition
    .byte 0

@ ---------------------------------------------------------
@ OnTransition:
@ - Progress reset
@ - Boulder reset (immer)
@ - Exit-Tiles je nach Puzzle-Flag setzen
@ ---------------------------------------------------------
Flag3_CD_OnTransition:
    setvar VAR_TEMP_0, 0 @ progress: 0 = cd noch nicht korrekt, 1 = cd korrekt

    call Flag3_CD_ResetBoulders

    goto_if_set FLAG_FLAG3_CD_PUZZLE_SOLVED, Flag3_CD_OnTransition_Solved

    @ Puzzle nicht gelöst -> Ausgang wieder "zu" (0x218)
    call Flag3_CD_HideExit_NoRedraw
    end

Flag3_CD_OnTransition_Solved:
    @ Puzzle gelöst -> Ausgang offen halten
    call Flag3_CD_RevealExit_NoRedraw
    end


@ =========================================================
@ RESET: Boulder beim (Neu-)Betreten zurücksetzen
@ (remove + add -> spawnt wieder an map.json Startpositionen)
@ =========================================================
Flag3_CD_ResetBoulders:
    removeobject LOCALID_FLAG3_CD_BOULDER_CD
    removeobject LOCALID_FLAG3_CD_BOULDER_DOT1
    removeobject LOCALID_FLAG3_CD_BOULDER_DOT2

    addobject LOCALID_FLAG3_CD_BOULDER_CD
    addobject LOCALID_FLAG3_CD_BOULDER_DOT1
    addobject LOCALID_FLAG3_CD_BOULDER_DOT2
    return


@ =========================================================
@ EXIT-TILES: Metatiles tauschen
@ =========================================================

@ Ausgang "zu" (dein aktuelles 0x218 überall)
Flag3_CD_HideExit_NoRedraw:
    setmetatile 6, 0, 0x218, TRUE
    setmetatile 7, 0, 0x218, TRUE
    setmetatile 8, 0, 0x218, TRUE
    setmetatile 6, 1, 0x218, TRUE
    setmetatile 7, 1, 0x218, TRUE
    setmetatile 8, 1, 0x218, TRUE
    return

@ Ausgang "auf" (deine gewünschten Tiles)
Flag3_CD_RevealExit_NoRedraw:
    @ y=0 (oben) – bleibt blockierend
    setmetatile 6, 0, 0x20B, TRUE
    setmetatile 7, 0, 0x20C, TRUE
    setmetatile 8, 0, 0x20D, TRUE

    @ y=1 (unten) – begehbar
    setmetatile 6, 1, 0x213, FALSE
    setmetatile 7, 1, 0x214, FALSE
    setmetatile 8, 1, 0x215, FALSE
    return

@ Sofort sichtbar machen (für den Moment, wo das Puzzle gelöst wird)
Flag3_CD_RevealExit_Redraw:
    call Flag3_CD_RevealExit_NoRedraw
    special DrawWholeMapView
    return


@ =========================================================
@ PUSH-SCRIPTS (je Objekt ein Script, damit wir den LocalID fest haben)
@ =========================================================

Flag3_CD_EventScript_Push_CD::
    lock
    call Flag3_CD_TryPush_CD
    call Flag3_CD_CheckPuzzle
    release
    end

Flag3_CD_EventScript_Push_Dot1::
    lock
    call Flag3_CD_TryPush_Dot1
    call Flag3_CD_CheckPuzzle
    release
    end

Flag3_CD_EventScript_Push_Dot2::
    lock
    call Flag3_CD_TryPush_Dot2
    call Flag3_CD_CheckPuzzle
    release
    end


@ =========================================================
@ TRY-PUSH (je Objekt; bewegt 1 Feld in Blickrichtung)
@ =========================================================

Flag3_CD_TryPush_CD:
    specialvar VAR_RESULT, GetPlayerFacingDirection
    compare VAR_RESULT, DIR_NORTH
    goto_if_eq Flag3_CD_PushCD_N
    compare VAR_RESULT, DIR_SOUTH
    goto_if_eq Flag3_CD_PushCD_S
    compare VAR_RESULT, DIR_WEST
    goto_if_eq Flag3_CD_PushCD_W
    @ sonst EAST
Flag3_CD_PushCD_E:
    applymovement LOCALID_FLAG3_CD_BOULDER_CD, Flag3_CD_Movement_Push_E
    goto Flag3_CD_PushCD_Wait
Flag3_CD_PushCD_N:
    applymovement LOCALID_FLAG3_CD_BOULDER_CD, Flag3_CD_Movement_Push_N
    goto Flag3_CD_PushCD_Wait
Flag3_CD_PushCD_S:
    applymovement LOCALID_FLAG3_CD_BOULDER_CD, Flag3_CD_Movement_Push_S
    goto Flag3_CD_PushCD_Wait
Flag3_CD_PushCD_W:
    applymovement LOCALID_FLAG3_CD_BOULDER_CD, Flag3_CD_Movement_Push_W
Flag3_CD_PushCD_Wait:
    waitmovement 0
    return

Flag3_CD_TryPush_Dot1:
    specialvar VAR_RESULT, GetPlayerFacingDirection
    compare VAR_RESULT, DIR_NORTH
    goto_if_eq Flag3_CD_PushD1_N
    compare VAR_RESULT, DIR_SOUTH
    goto_if_eq Flag3_CD_PushD1_S
    compare VAR_RESULT, DIR_WEST
    goto_if_eq Flag3_CD_PushD1_W
Flag3_CD_PushD1_E:
    applymovement LOCALID_FLAG3_CD_BOULDER_DOT1, Flag3_CD_Movement_Push_E
    goto Flag3_CD_PushD1_Wait
Flag3_CD_PushD1_N:
    applymovement LOCALID_FLAG3_CD_BOULDER_DOT1, Flag3_CD_Movement_Push_N
    goto Flag3_CD_PushD1_Wait
Flag3_CD_PushD1_S:
    applymovement LOCALID_FLAG3_CD_BOULDER_DOT1, Flag3_CD_Movement_Push_S
    goto Flag3_CD_PushD1_Wait
Flag3_CD_PushD1_W:
    applymovement LOCALID_FLAG3_CD_BOULDER_DOT1, Flag3_CD_Movement_Push_W
Flag3_CD_PushD1_Wait:
    waitmovement 0
    return

Flag3_CD_TryPush_Dot2:
    specialvar VAR_RESULT, GetPlayerFacingDirection
    compare VAR_RESULT, DIR_NORTH
    goto_if_eq Flag3_CD_PushD2_N
    compare VAR_RESULT, DIR_SOUTH
    goto_if_eq Flag3_CD_PushD2_S
    compare VAR_RESULT, DIR_WEST
    goto_if_eq Flag3_CD_PushD2_W
Flag3_CD_PushD2_E:
    applymovement LOCALID_FLAG3_CD_BOULDER_DOT2, Flag3_CD_Movement_Push_E
    goto Flag3_CD_PushD2_Wait
Flag3_CD_PushD2_N:
    applymovement LOCALID_FLAG3_CD_BOULDER_DOT2, Flag3_CD_Movement_Push_N
    goto Flag3_CD_PushD2_Wait
Flag3_CD_PushD2_S:
    applymovement LOCALID_FLAG3_CD_BOULDER_DOT2, Flag3_CD_Movement_Push_S
    goto Flag3_CD_PushD2_Wait
Flag3_CD_PushD2_W:
    applymovement LOCALID_FLAG3_CD_BOULDER_DOT2, Flag3_CD_Movement_Push_W
Flag3_CD_PushD2_Wait:
    waitmovement 0
    return


@ =========================================================
@ PUZZLE-CHECK
@ Reihenfolge-Logik: CD muss korrekt sein, dann DOTs (egal welcher wo)
@ =========================================================

@ Ziel 1 (cd)
#define TARGET_CD_X        7
#define TARGET_CD_Y        4

@ Ziel 2 & 3 (die beiden .-Boulder, egal welcher welcher)
#define TARGET_DOT_A_X     8
#define TARGET_DOT_A_Y     4
#define TARGET_DOT_B_X     9
#define TARGET_DOT_B_Y     4

Flag3_CD_CheckPuzzle:
    goto_if_set FLAG_FLAG3_CD_PUZZLE_SOLVED, Flag3_CD_CheckPuzzle_End

    @ --- CD prüfen ---
    getobjectxy LOCALID_FLAG3_CD_BOULDER_CD, CURRENT_POSITION, VAR_0x8000, VAR_0x8001
    compare VAR_0x8000, TARGET_CD_X
    goto_if_ne Flag3_CD_CheckPuzzle_Reset
    compare VAR_0x8001, TARGET_CD_Y
    goto_if_ne Flag3_CD_CheckPuzzle_Reset

    @ CD liegt richtig -> DOTs prüfen
    setvar VAR_TEMP_0, 1

    getobjectxy LOCALID_FLAG3_CD_BOULDER_DOT1, CURRENT_POSITION, VAR_0x8002, VAR_0x8003
    getobjectxy LOCALID_FLAG3_CD_BOULDER_DOT2, CURRENT_POSITION, VAR_0x8004, VAR_0x8005

    call Flag3_CD_AreDotsCorrect
    compare VAR_RESULT, TRUE
    goto_if_eq Flag3_CD_PuzzleSolved

    goto Flag3_CD_CheckPuzzle_End

Flag3_CD_CheckPuzzle_Reset:
    setvar VAR_TEMP_0, 0
    goto Flag3_CD_CheckPuzzle_End

Flag3_CD_PuzzleSolved:
    setflag FLAG_FLAG3_CD_PUZZLE_SOLVED
    msgbox Flag3_CD_Text_DoorOpens, MSGBOX_DEFAULT
    closemessage

    @ Ausgang sofort sichtbar machen
    call Flag3_CD_RevealExit_Redraw
    return

Flag3_CD_CheckPuzzle_End:
    return


@ DOTs korrekt, egal welcher auf welchem Ziel
Flag3_CD_AreDotsCorrect:
    setvar VAR_RESULT, FALSE

    @ Combo 1: dot1=A, dot2=B
    compare VAR_0x8002, TARGET_DOT_A_X
    goto_if_ne Flag3_CD_AreDots_Combo2
    compare VAR_0x8003, TARGET_DOT_A_Y
    goto_if_ne Flag3_CD_AreDots_Combo2
    compare VAR_0x8004, TARGET_DOT_B_X
    goto_if_ne Flag3_CD_AreDots_Combo2
    compare VAR_0x8005, TARGET_DOT_B_Y
    goto_if_ne Flag3_CD_AreDots_Combo2
    setvar VAR_RESULT, TRUE
    return

Flag3_CD_AreDots_Combo2:
    @ Combo 2: dot1=B, dot2=A
    compare VAR_0x8002, TARGET_DOT_B_X
    goto_if_ne Flag3_CD_AreDots_End
    compare VAR_0x8003, TARGET_DOT_B_Y
    goto_if_ne Flag3_CD_AreDots_End
    compare VAR_0x8004, TARGET_DOT_A_X
    goto_if_ne Flag3_CD_AreDots_End
    compare VAR_0x8005, TARGET_DOT_A_Y
    goto_if_ne Flag3_CD_AreDots_End
    setvar VAR_RESULT, TRUE

Flag3_CD_AreDots_End:
    return


Flag3_CD_WallSign::
	lock
	msgbox Flag3_CD_Text_WallText, MSGBOX_DEFAULT
	closemessage
	release
	end


@ =========================================================
@ MOVEMENTS (1 Schritt)
@ =========================================================
Flag3_CD_Movement_Push_N::
    walk_up
    step_end

Flag3_CD_Movement_Push_S::
    walk_down
    step_end

Flag3_CD_Movement_Push_W::
    walk_left
    step_end

Flag3_CD_Movement_Push_E::
    walk_right
    step_end


@ =========================================================
@ TEXT
@ =========================================================
Flag3_CD_Text_DoorOpens:
    .string "You hear a loud click...\p"
    .string "A passage opened!$"

Flag3_CD_Text_WallText:
	.string "Sometimes you have to take a step\n"
	.string "back to come forward.$"
