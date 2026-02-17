Quadrate_MapScripts::
	.byte 0

@ =========================
@ Train (Entrance = Right)
@ =========================

Train_EventScript_BoardFromRight::
    lockall

    @ Nur erlauben, wenn Player von unten spricht (Player facing NORTH)
    getplayerfacing
    compare VAR_RESULT, DIR_NORTH
    ifne Train_EventScript_WrongSide

    msgbox Train_Text_AskTravel, MSGBOX_YESNO
    compare VAR_RESULT, 0 @ 0 = YES, 1 = NO
    ifne Train_EventScript_Cancel

    closemessage

    @ "Einsteigen" (optional 1 Schritt nach oben – nur wenn Tile passierbar!)
    applymovement LOCALID_PLAYER, Train_Movement_PlayerEnter
    waitmovement 0
	playse SE_DOOR
	waitse

    hideplayer

    @ Kamera auf Zug (rechter Teil = Eingang)
    setobjectasview LOCALID_ZUGRECHTS

    @ Beide Zugteile parallel bewegen
    applymovement LOCALID_ZUGLINKS,  Train_Movement_SlideLeft20
    applymovement LOCALID_ZUGRECHTS, Train_Movement_SlideLeft20
    waitmovement 0

    fadescreen FADE_TO_BLACK
    waitstate

    @ Warp nach Wasserturm: Warp-ID muss auf (x5,y8) liegen!
    warp MAP_GROUP(WASSERTURM), MAP_NUM(WASSERTURM), 0
    waitstate

    fadescreen FADE_FROM_BLACK
    waitstate

    showplayer
    setplayerfacing DIR_NORTH
    releaseall
    end


Train_EventScript_WrongSide::
    msgbox Train_Text_WrongSide, MSGBOX_DEFAULT
    releaseall
    end

Train_EventScript_Cancel::
    releaseall
    end


@ =========================
@ Text
@ =========================
Train_Text_AskTravel:
    .string "Do you want to travel to the Water Tower?$"

Train_Text_WrongSide:
    .string "The entrance is on the south side.$"


@ =========================
@ Movements
@ =========================
Train_Movement_PlayerEnter:
    walk_up
    step_end

Train_Movement_SlideLeft20:
    walk_right
    walk_right
    walk_right
    walk_right
    walk_right
    walk_right
    walk_right
    walk_right
    walk_right
    walk_right
    walk_right
    walk_right
    walk_right
    walk_right
    walk_right
    walk_right
    walk_right
    walk_right
    walk_right
    walk_right
    step_end




Quadrate_EventScript_LockedTrain::
	msgbox Quadrate_Text_LockedTrainMsg, MSGBOX_SIGN
	end

Quadrate_Text_LockedTrainMsg:
	.string "The train is not running at the\n"
	.string "moment. Please come back later.$"

