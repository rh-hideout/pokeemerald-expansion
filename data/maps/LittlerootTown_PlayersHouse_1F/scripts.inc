@ =============================================================================
@ PLAYER'S BEDROOM — MAP SCRIPTS
@ =============================================================================

LittlerootTown_PlayersHouse_1F_MapScripts::
    map_script MAP_SCRIPT_ON_TRANSITION, LittlerootTown_PlayersHouse_1F_OnTransition
    map_script MAP_SCRIPT_ON_FRAME_TABLE, LittlerootTown_PlayersHouse_1F_OnFrame
    .byte 0


@ =============================================================================
@ ON-FRAME TABLE
@ =============================================================================

LittlerootTown_PlayersHouse_1F_OnFrame:
    map_script_2 VAR_TEMP_0, 1, LittlerootTown_PlayersHouse_1F_EventScript_WakeUp
    .2byte 0


@ =============================================================================
@ MAP TRANSITION
@
@ VAR_RAISED_BY:
@     1 = Mom
@     2 = Dad
@
@ The flags are prepared here before the object events spawn.
@ =============================================================================

LittlerootTown_PlayersHouse_1F_OnTransition:
    @ Do nothing before the IntroFall sequence has happened.
    goto_if_unset FLAG_INTRO_FLASHBACK_COMPLETE, LittlerootTown_PlayersHouse_1F_OnTransition_End

    @ Once the wake-up scene is complete, neither parent should appear upstairs.
    goto_if_set FLAG_FLASHBACK_WAKE_COMPLETE, LittlerootTown_PlayersHouse_1F_OnTransition_HideBoth

    @ Choose the correct bedside parent using the Poochyena decision.
    goto_if_eq VAR_RAISED_BY, 1, LittlerootTown_PlayersHouse_1F_OnTransition_ShowMom
    goto_if_eq VAR_RAISED_BY, 2, LittlerootTown_PlayersHouse_1F_OnTransition_ShowDad

    @ Safe fallback.
    goto LittlerootTown_PlayersHouse_1F_OnTransition_ShowMom


LittlerootTown_PlayersHouse_1F_OnTransition_ShowMom:
    @ Show Mom and hide Dad upstairs.
    clearflag FLAG_HIDE_UPSTAIRS_MOM
    setflag FLAG_HIDE_UPSTAIRS_DAD

    setvar VAR_TEMP_0, 1
    end


LittlerootTown_PlayersHouse_1F_OnTransition_ShowDad:
    @ Hide Mom and show Dad upstairs.
    setflag FLAG_HIDE_UPSTAIRS_MOM
    clearflag FLAG_HIDE_UPSTAIRS_DAD

    setvar VAR_TEMP_0, 1
    end


LittlerootTown_PlayersHouse_1F_OnTransition_HideBoth:
    setflag FLAG_HIDE_UPSTAIRS_MOM
    setflag FLAG_HIDE_UPSTAIRS_DAD
    end


LittlerootTown_PlayersHouse_1F_OnTransition_End:
    end


@ =============================================================================
@ WAKE-UP CUTSCENE
@ =============================================================================

LittlerootTown_PlayersHouse_1F_EventScript_WakeUp:
    lockall

    @ Prevent the OnFrame script from repeating during this visit.
    setvar VAR_TEMP_0, 0

    delay 15

    applymovement OBJ_EVENT_ID_PLAYER, LittlerootTown_PlayersHouse_1F_Movement_WakeUp
    waitmovement 0

    delay 15

    msgbox LittlerootTown_PlayersHouse_1F_Text_WakeUp, MSGBOX_DEFAULT

    @ Use the Poochyena choice directly.
    goto_if_eq VAR_RAISED_BY, 1, LittlerootTown_PlayersHouse_1F_EventScript_TurnToMom
    goto_if_eq VAR_RAISED_BY, 2, LittlerootTown_PlayersHouse_1F_EventScript_TurnToDad

    @ Safe fallback.
    goto LittlerootTown_PlayersHouse_1F_EventScript_TurnToMom


@ =============================================================================
@ MOM BRANCH
@ =============================================================================

LittlerootTown_PlayersHouse_1F_EventScript_TurnToMom:
    applymovement OBJ_EVENT_ID_PLAYER, LittlerootTown_PlayersHouse_1F_Movement_FaceMom
    waitmovement 0

    applymovement LOCALID_WAKE_ROOM_MOM, LittlerootTown_PlayersHouse_1F_Movement_ParentFacePlayer
    waitmovement 0

    msgbox LittlerootTown_PlayersHouse_1F_Text_MomAfterDream, MSGBOX_DEFAULT

    @ On the next room entry, both upstairs parent copies will be hidden.
    setflag FLAG_FLASHBACK_WAKE_COMPLETE

    releaseall
    end


@ =============================================================================
@ DAD BRANCH
@ =============================================================================

LittlerootTown_PlayersHouse_1F_EventScript_TurnToDad:
    applymovement OBJ_EVENT_ID_PLAYER, LittlerootTown_PlayersHouse_1F_Movement_FaceDad
    waitmovement 0

    applymovement LOCALID_WAKE_ROOM_DAD, LittlerootTown_PlayersHouse_1F_Movement_ParentFacePlayer
    waitmovement 0

    msgbox LittlerootTown_PlayersHouse_1F_Text_DadAfterDream, MSGBOX_DEFAULT

    @ On the next room entry, both upstairs parent copies will be hidden.
    setflag FLAG_FLASHBACK_WAKE_COMPLETE

    releaseall
    end


@ =============================================================================
@ MANUAL PARENT INTERACTIONS
@ =============================================================================

LittlerootTown_PlayersHouse_1F_EventScript_Mom::
    lock
    faceplayer

    msgbox LittlerootTown_PlayersHouse_1F_Text_MomAfterDream, MSGBOX_NPC

    release
    end


LittlerootTown_PlayersHouse_1F_EventScript_Dad::
    lock
    faceplayer

    msgbox LittlerootTown_PlayersHouse_1F_Text_DadAfterDream, MSGBOX_NPC

    release
    end


@ =============================================================================
@ PLAYER MOVEMENTS
@ =============================================================================

LittlerootTown_PlayersHouse_1F_Movement_WakeUp:
    face_down
    delay_16
    step_end


LittlerootTown_PlayersHouse_1F_Movement_FaceMom:
    face_right
    step_end


LittlerootTown_PlayersHouse_1F_Movement_FaceDad:
    face_right
    step_end


@ =============================================================================
@ PARENT MOVEMENTS
@ =============================================================================

LittlerootTown_PlayersHouse_1F_Movement_ParentFacePlayer:
    face_left
    step_end


@ =============================================================================
@ TEXT
@ =============================================================================

LittlerootTown_PlayersHouse_1F_Text_WakeUp:
    .string "...That felt too real to be a\n"
    .string "dream.$"


LittlerootTown_PlayersHouse_1F_Text_MomAfterDream:
    .string "Good morning, sleepyhead.\p"
    .string "You looked like you were having\n"
    .string "quite a dream.\p"
    .string "Are you feeling okay?$"


LittlerootTown_PlayersHouse_1F_Text_DadAfterDream:
    .string "There you are.\p"
    .string "You were tossing and turning in\n"
    .string "your sleep.\p"
    .string "You feeling all right?$"
