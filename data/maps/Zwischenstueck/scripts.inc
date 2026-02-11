Zwischenstueck_MapScripts::
    map_script MAP_SCRIPT_ON_TRANSITION, Zwischenstueck_OnTransition
    .byte 0

Zwischenstueck_OnTransition:
    @ If already moved once, re-apply the move on every entry
    goto_if_set FLAG_ZWISCHENSTUECK_GUARD_MOVED, Zwischenstueck_ApplyMovedState
    end

Zwischenstueck_ApplyMovedState:
    applymovement LOCALID_PASSWORD_GUARD, Zwischenstueck_Movement_Guard_Right1FaceDown
    waitmovement 0
    end


@ =========================================================
@ Object: Password Guard
@ =========================================================

Zwischenstueck_EventScript_PasswordGuard::
    lock

    @ After moved -> always same line, keep facing down
    goto_if_set FLAG_ZWISCHENSTUECK_GUARD_MOVED, Zwischenstueck_Guard_After

    faceplayer

    @ If player hasn't done the tap yet -> get lost
    goto_if_unset FLAG_BLACKHANSA_SERVER_TAP_DONE, Zwischenstueck_Guard_NoPassword

    @ Success path (flag set): say the 3 lines
    msgbox Zwischenstueck_Text_Pass_Question, MSGBOX_DEFAULT
    msgbox Zwischenstueck_Text_Pass_Answer,   MSGBOX_DEFAULT
    msgbox Zwischenstueck_Text_Pass_Ok,       MSGBOX_DEFAULT
    closemessage

    @ Move 1 tile right, then face down
    applymovement LOCALID_PASSWORD_GUARD, Zwischenstueck_Movement_Guard_Right1FaceDown
    waitmovement 0

    @ Make it permanent for future visits
    setflag FLAG_ZWISCHENSTUECK_GUARD_MOVED

    release
    end

Zwischenstueck_Guard_NoPassword:
    msgbox Zwischenstueck_Text_NoPassword, MSGBOX_DEFAULT
    release
    end

Zwischenstueck_Guard_After:
    msgbox Zwischenstueck_Text_AfterMoved, MSGBOX_DEFAULT
    turnobject LOCALID_PASSWORD_GUARD, DIR_WEST
    release
    end


@ =========================================================
@ Movement
@ =========================================================

Zwischenstueck_Movement_Guard_Right1FaceDown:
    walk_right
    face_left
    step_end


@ =========================================================
@ Text
@ =========================================================

Zwischenstueck_Text_NoPassword:
    .string "Do you have the password?\n"
    .string "If not, get lost!$"

Zwischenstueck_Text_Pass_Question:
    .string "Do you have the password?$"

Zwischenstueck_Text_Pass_Answer:
    .string "Yes, it's CASSEROLE$"

Zwischenstueck_Text_Pass_Ok:
    .string "All right.$"

Zwischenstueck_Text_AfterMoved:
    .string "Mind your own business.$"



Zwischenstueck_EventScript_Sign::
	msgbox Zwischenstueck_Text_TownSign, MSGBOX_SIGN
	end

Zwischenstueck_EventScript_Lagerhaus::
	msgbox Zwischenstueck_Text_Lagerhaus, MSGBOX_SIGN
	end

Zwischenstueck_Text_TownSign::
	.string "Left: DHBW\n"
	.string "Right: JUNGBUSCH$"

Zwischenstueck_Text_Lagerhaus::
	.string " Old BLACKHANSA warehouse.$"

