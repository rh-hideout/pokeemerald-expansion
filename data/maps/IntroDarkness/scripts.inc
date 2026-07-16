IntroDarkness_MapScripts::
    map_script MAP_SCRIPT_ON_FRAME_TABLE, IntroDarkness_OnFrame
    .byte 0

IntroDarkness_OnFrame:
    map_script_2 VAR_TEMP_1, 0, IntroDarkness_EventScript_Begin
    .2byte 0

IntroDarkness_EventScript_Begin:
    setvar VAR_TEMP_1, 1
    lockall

    delay 45

    applymovement OBJ_EVENT_ID_PLAYER, IntroDarkness_PlayerFaceLeft
    waitmovement 0
    delay 35

    applymovement OBJ_EVENT_ID_PLAYER, IntroDarkness_PlayerFaceRight
    waitmovement 0
    delay 35

    applymovement OBJ_EVENT_ID_PLAYER, IntroDarkness_PlayerFaceDown
    waitmovement 0
    delay 35

    applymovement OBJ_EVENT_ID_PLAYER, IntroDarkness_PlayerFaceUp
    waitmovement 0
    delay 60

    msgbox IntroDarkness_Text1, MSGBOX_DEFAULT
    closemessage

    delay 60

    msgbox IntroDarkness_Text2, MSGBOX_DEFAULT
    closemessage

    delay 30

    multichoicedefault 20, 8, MULTI_PARENT_CHOICE, 0, FALSE
    switch VAR_RESULT
    case 0, IntroDarkness_EventScript_ChooseMom
    case 1, IntroDarkness_EventScript_ChooseDad


IntroDarkness_Text1:
    .string "...$"

IntroDarkness_Text2:
    .string "...?$"

IntroDarkness_PlayerFaceLeft:
    face_left
    step_end

IntroDarkness_PlayerFaceRight:
    face_right
    step_end

IntroDarkness_PlayerFaceDown:
    face_down
    step_end

IntroDarkness_PlayerFaceUp:
    face_up
    step_end

IntroDarkness_EventScript_ChooseMom:
    setvar VAR_PARENT_CHOICE, 1

    clearflag FLAG_HIDE_INTROFALL_MOM
    setflag FLAG_HIDE_INTROFALL_DAD

    goto IntroDarkness_EventScript_WarpToFall

IntroDarkness_EventScript_ChooseDad:
    setvar VAR_PARENT_CHOICE, 2

    setflag FLAG_HIDE_INTROFALL_MOM
    clearflag FLAG_HIDE_INTROFALL_DAD

    goto IntroDarkness_EventScript_WarpToFall

IntroDarkness_EventScript_WarpToFall:
    warp MAP_INTRO_FALL, 12, 18
    waitstate
    end
