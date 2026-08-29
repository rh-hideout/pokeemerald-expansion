MistysHouse_MapScripts::
    map_script MAP_SCRIPT_ON_FRAME_TABLE, MistysHouse_OnFrame
    map_script MAP_SCRIPT_ON_LOAD, MistysHouse_OnLoad
    .byte 0


MistysHouse_OnLoad:
    call MistysHouse_SetCounterpartGraphics
    end



@ ============================================================
@ DYNAMIC COUNTERPART GRAPHICS
@ ============================================================

MistysHouse_SetCounterpartGraphics:
    goto_if_eq VAR_COUNTERPART_ID, COUNTERPART_BRENDAN, MistysHouse_SetCounterpartBrendan
    goto_if_eq VAR_COUNTERPART_ID, COUNTERPART_MAY, MistysHouse_SetCounterpartMay
    goto_if_eq VAR_COUNTERPART_ID, COUNTERPART_LEXY, MistysHouse_SetCounterpartLexy
    goto_if_eq VAR_COUNTERPART_ID, COUNTERPART_JUSTIN, MistysHouse_SetCounterpartJustin
    goto_if_eq VAR_COUNTERPART_ID, COUNTERPART_MAAM, MistysHouse_SetCounterpartMaam
    goto_if_eq VAR_COUNTERPART_ID, COUNTERPART_SIR, MistysHouse_SetCounterpartSir

    setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_BRENDAN_NORMAL
    return

MistysHouse_SetCounterpartBrendan:
    setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_BRENDAN_NORMAL
    return

MistysHouse_SetCounterpartMay:
    setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_MAY_NORMAL
    return

MistysHouse_SetCounterpartLexy:
    setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_LEXY_NORMAL
    return

MistysHouse_SetCounterpartJustin:
    setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_JUSTIN_NORMAL
    return

MistysHouse_SetCounterpartMaam:
    setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_MAAM_NORMAL
    return

MistysHouse_SetCounterpartSir:
    setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_SIR_NORMAL
    return


@ ============================================================
@ CERULEAN RETURN — FRAME HANDOFF
@ ============================================================

MistysHouse_OnFrame:
    map_script_2 VAR_TEMP_F, 0, MistysHouse_EventScript_TryReturnWalk
    .2byte 0


MistysHouse_EventScript_TryReturnWalk::
    @ Prevent this frame hook from repeating.
    setvar VAR_TEMP_F, 1

    goto_if_unset FLAG_CERULEAN_LAB_COMPLETE, MistysHouse_EventScript_ReturnWalkEnd
    goto_if_set FLAG_CERULEAN_MISSION_COMPLETE, MistysHouse_EventScript_ReturnWalkEnd

    lockall

    applymovement LOCALID_PLAYER, MistysHouse_Movement_ReturnToGroup
    waitmovement 0

    goto MistysHouse_EventScript_CeruleanFinale


MistysHouse_EventScript_ReturnWalkEnd::
    end


MistysHouse_Movement_ReturnToGroup:
    walk_down
    walk_down
    walk_down
    walk_down
    walk_down
    walk_down
    walk_right
    walk_right
    face_up
    step_end


@ ============================================================
@ CERULEAN MISSION FINALE
@ ============================================================

MistysHouse_EventScript_CeruleanFinale::
    lockall

    @ Only run after the lab was completed.
    goto_if_unset FLAG_CERULEAN_LAB_COMPLETE, MistysHouse_EventScript_FinaleEnd

    @ Never replay after completion.
    goto_if_set FLAG_CERULEAN_MISSION_COMPLETE, MistysHouse_EventScript_FinaleEnd


    @ Cast already exists normally on the map.
    applymovement LOCALID_PLAYER, Common_Movement_FaceUp
    waitmovement 0

    msgbox MistysHouse_Text_MistyRewardIntro, MSGBOX_DEFAULT
    closemessage

    checkitemspace ITEM_EXP_SHARE
    goto_if_eq VAR_RESULT, FALSE, MistysHouse_EventScript_NoRoomForExpShare

    giveitem ITEM_EXP_SHARE
    setflag FLAG_RECEIVED_EXP_SHARE

    msgbox MistysHouse_Text_MistyTimeTravel, MSGBOX_DEFAULT
    closemessage

    msgbox MistysHouse_Text_MistyEricaReveal, MSGBOX_DEFAULT
    closemessage

    msgbox MistysHouse_Text_RoxanneInvitation, MSGBOX_DEFAULT
    closemessage

    @ Cerulean mission is officially finished.
    setflag FLAG_CERULEAN_MISSION_COMPLETE

    releaseall
    end


MistysHouse_EventScript_NoRoomForExpShare:
    msgbox MistysHouse_Text_NoRoom, MSGBOX_DEFAULT
    releaseall
    end


MistysHouse_EventScript_FinaleEnd:
    releaseall
    end


@ ============================================================
@ CERULEAN DOOR
@
@ We preserve the actual warp.
@ After mission completion, this tile stops the player before
@ reaching it.
@ ============================================================

MistysHouse_EventScript_CeruleanDoorLocked::
    lockall

    @ Once the Cerulean lab mission has been completed,
    @ do not allow immediate return through the portal.
    goto_if_unset FLAG_CERULEAN_LAB_COMPLETE, MistysHouse_EventScript_DoorUnlocked

    msgbox MistysHouse_Text_CeruleanDoorLocked, MSGBOX_DEFAULT
    closemessage

    @ Push player away from the portal.
    applymovement LOCALID_PLAYER, MistysHouse_Movement_StepDown
    waitmovement 0

    releaseall
    end


MistysHouse_EventScript_DoorUnlocked:
    releaseall
    end


MistysHouse_Movement_StepDown:
    walk_down
    step_end


@ ============================================================
@ POST-MISSION NPC DIALOGUE
@ ============================================================

MistysHouse_EventScript_Misty::
    lock
    faceplayer

    goto_if_unset FLAG_CERULEAN_MISSION_COMPLETE, MistysHouse_EventScript_MistyBeforeFinale

    msgbox MistysHouse_Text_MistyAfterFinale, MSGBOX_DEFAULT
    release
    end


MistysHouse_EventScript_MistyBeforeFinale:
    msgbox MistysHouse_Text_MistyBeforeFinale, MSGBOX_DEFAULT
    release
    end


MistysHouse_EventScript_Roxanne::
    lock
    faceplayer

    goto_if_unset FLAG_CERULEAN_MISSION_COMPLETE, MistysHouse_EventScript_RoxanneBeforeFinale

    msgbox MistysHouse_Text_RoxanneAfterFinale, MSGBOX_DEFAULT
    release
    end


MistysHouse_EventScript_RoxanneBeforeFinale:
    msgbox MistysHouse_Text_RoxanneBeforeFinale, MSGBOX_DEFAULT
    release
    end


MistysHouse_EventScript_Counterpart::
    lock
    faceplayer

    goto_if_unset FLAG_CERULEAN_MISSION_COMPLETE, MistysHouse_EventScript_CounterpartBeforeFinale

    msgbox MistysHouse_Text_CounterpartAfterFinale, MSGBOX_DEFAULT
    release
    end


MistysHouse_EventScript_CounterpartBeforeFinale:
    msgbox MistysHouse_Text_CounterpartBeforeFinale, MSGBOX_DEFAULT
    release
    end


@ ============================================================
@ TEXT
@ ============================================================

MistysHouse_Text_MistyRewardIntro:
    .string "MISTY: Okay...\p"
    .string "After everything that just\n"
    .string "happened, you definitely earned\l"
    .string "this.$"


MistysHouse_Text_MistyTimeTravel:
    .string "MISTY: Before you go, there's\n"
    .string "something you should understand.\p"
    .string "Going back isn't the same as\n"
    .string "visiting another place.\p"
    .string "Things may not always be exactly\n"
    .string "how you remember them.\p"
    .string "People aren't always where you'd\n"
    .string "expect them to be.\p"
    .string "And not everyone you meet there\n"
    .string "stayed there.\p"
    .string "Some of us came from the past.\p"
    .string "Some have traveled here from it.\p"
    .string "You'll know one when you meet one.$"


MistysHouse_Text_MistyEricaReveal:
    .string "MISTY: Actually...\p"
    .string "I think you already have.\p"
    .string "Remember ERICA from PETALBURG?\p"
    .string "She's an exception in more ways\n"
    .string "than one...\p"
    .string "But she's one of us.$"


MistysHouse_Text_RoxanneInvitation:
    .string "ROXANNE: And with that matter\n"
    .string "resolved, we can return to why\l"
    .string "you're here.\p"
    .string "MISTY: Translation...\p"
    .string "She wants you to fight her.\p"
    .string "ROXANNE: ...At the shrine.\p"
    .string "When you're ready, meet me there.$"


MistysHouse_Text_NoRoom:
    .string "MISTY: Your BAG is full.\p"
    .string "Make some room and come back.$"


MistysHouse_Text_CeruleanDoorLocked:
    .string "{PLAYER}: ...Probably best not to\n"
    .string "go back right now.$"


MistysHouse_Text_MistyBeforeFinale:
    .string "MISTY: We should talk first.$"


MistysHouse_Text_RoxanneBeforeFinale:
    .string "ROXANNE: Let's finish discussing\n"
    .string "what happened.$"


MistysHouse_Text_CounterpartBeforeFinale:
    .string "{RIVAL}: You survived.\p"
    .string "That's a good start.$"


MistysHouse_Text_MistyAfterFinale:
    .string "MISTY: Good luck with ROXIE.$"


MistysHouse_Text_RoxanneAfterFinale:
    .string "ROXANNE: I'll be waiting at the\n"
    .string "SHRINE.$"


MistysHouse_Text_CounterpartAfterFinale:
    .string "{RIVAL}: Well...\p"
    .string "Have fun with that.$"
