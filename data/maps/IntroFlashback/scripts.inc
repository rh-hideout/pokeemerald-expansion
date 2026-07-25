IntroFlashback_MapScripts::
    map_script MAP_SCRIPT_ON_FRAME_TABLE, IntroFlashback_OnFrame
    .byte 0


IntroFlashback_OnFrame:
    map_script_2 VAR_TEMP_1, 0, IntroFlashback_EventScript_Begin
    .2byte 0

IntroFlashback_EventScript_Begin:
    setvar VAR_TEMP_1, 1

    special SpawnCameraObject
    applymovement LOCALID_CAMERA, IntroFlashback_Movement_CameraPanUp
    waitmovement 0
    delay 30

    msgbox IntroFlashback_Text_MomOpening, MSGBOX_DEFAULT
    closemessage
    delay 20

    msgbox IntroFlashback_Text_DadOpening, MSGBOX_DEFAULT
    closemessage

    delay 45

    applymovement LOCALID_MOM, IntroFlashback_Movement_MomFacePlayer
    waitmovement 0

    delay 20

    msgbox IntroFlashback_Mom_Text, MSGBOX_DEFAULT
    closemessage

    delay 30

    applymovement LOCALID_MOM, IntroFlashback_Movement_MomApproaches
    waitmovement 0

    delay 20

    playbgm MUS_VERDANTURF, 0
    delay 30

    applymovement LOCALID_CAMERA, IntroFlashback_Movement_CameraPanDown
    waitmovement 0

    delay 20
    special RemoveCameraObject

    applymovement OBJ_EVENT_ID_PLAYER, IntroFlashback_Movement_PlayerEnterGarden
    waitmovement 0

    releaseall
    end
    
IntroFlashback_EventScript_TestWarpToCinnabar::
    warp MAP_CINNABAR_ISLAND, 14, 12
    waitstate
    end

IntroFlashback_Movement_PlayerFaceUp:
    face_up
    step_end

IntroFlashback_Movement_PlayerEnterGarden:
    walk_up
    walk_up
    step_end

IntroFlashback_Movement_CameraPanUp:
    walk_up
    walk_up
    walk_up
    walk_up
    walk_up
    walk_up
    walk_up
    walk_up
    walk_up
    walk_up
    walk_up
    walk_up
    walk_up
    walk_up
    step_end

IntroFlashback_Movement_CameraPanDown:
    walk_down
    walk_down
    walk_down
    walk_down
    walk_down
    walk_down
    walk_down
    walk_down
    walk_down
    walk_down
    walk_down
    walk_down
    walk_down
    walk_down
    step_end

IntroFlashback_Movement_MomFacePlayer:
    face_down
    step_end

IntroFlashback_Movement_MomApproaches:
    walk_down
    walk_down
    walk_down
    face_down
    step_end

IntroFlashback_Movement_MomFaceDad:
    face_right
    step_end   
    

IntroFlashback_Text_MomOpening:
    .string "...Do you think they remember?$"

IntroFlashback_Text_DadOpening:
    .string "No...and for now, that may be\n"
    .string "for the best.\n"
    .string "....$"

IntroFlashback_Mom_Text:
    .string "...There you are, little one.$"

IntroFlashback_Mom::
    lock
    faceplayer
    msgbox IntroFlashback_Mom_FirstText, MSGBOX_DEFAULT
    release
    end

IntroFlashback_Mom_FirstText:
    .string "Come now, little one.\n"
    .string "Your father is waiting.$"

IntroFlashback_Dad::
    lock
    faceplayer

    msgbox IntroFlashback_Dad_Text, MSGBOX_DEFAULT
    closemessage

    delay 20

    applymovement LOCALID_MOM, IntroFlashback_Movement_MomFaceDad
    waitmovement 0

    delay 15

    msgbox IntroFlashback_Mom_StopText1, MSGBOX_DEFAULT
    closemessage

    delay 20

    msgbox IntroFlashback_Mom_StopText2, MSGBOX_DEFAULT
    closemessage

    delay 15

    applymovement LOCALID_MOM, IntroFlashback_Movement_MomFacePlayer
    waitmovement 0

    release
    end

IntroFlashback_Mom_StopText1:
    .string "Elias...$"

IntroFlashback_Mom_StopText2:
    .string "Not in front of the little one.$"

IntroFlashback_Dad_Text:
    .string "The garden is almost...\n"
    .string "too quiet today.$"

IntroFlashback_EventScript_EnterFall::
    lockall

    warp MAP_INTRO_DARKNESS, 9, 9
    waitstate
    end

    
