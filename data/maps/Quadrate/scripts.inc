@ =========================================================
@ Map: Quadrate
@ File: data/maps/Quadrate/scripts.inc
@ =========================================================

Quadrate_MapScripts::
    .byte 0

@ --- Koordinaten vom rechten Zugteil (Entrance) ---
@ Laut deinem Map-JSON:
@   LOCALID_ZUGRECHTS: x=8, y=11
@ "von unten ansprechen" => Player steht auf x=8, y=12
    .equ TRAIN_R_X,        8
    .equ TRAIN_R_Y,        11
    .equ TRAIN_R_Y_BELOW,  12


@ =========================================================
@ Zug Script (an LOCALID_ZUGRECHTS hängen!)
@ =========================================================
Quadrate_Train_EventScript_Board::
    lockall

    @ Nur wenn Player genau unter dem rechten Zugteil steht
    getplayerxy VAR_0x8004, VAR_0x8005
    compare VAR_0x8004, TRAIN_R_X
    goto_if 5, Quadrate_Train_EventScript_WrongSide
    compare VAR_0x8005, TRAIN_R_Y_BELOW
    goto_if 5, Quadrate_Train_EventScript_WrongSide

    msgbox Quadrate_Train_Text_AskTravel, MSGBOX_YESNO
    compare VAR_RESULT, 0
    goto_if 5, Quadrate_Train_EventScript_Cancel
    closemessage

    @ Einsteigen
    hideplayer

    @ Kamera folgt dem (unsichtbaren) Player -> Player parallel zum Zug bewegen
    applymovement LOCALID_PLAYER,     Quadrate_Train_Movement_SlideRight20
    applymovement LOCALID_ZUGLINKS,   Quadrate_Train_Movement_SlideRight20
    applymovement LOCALID_ZUGRECHTS,  Quadrate_Train_Movement_SlideRight20
    waitmovement 0

    fadescreen FADE_TO_BLACK
    waitstate

    @ Warp nach Wasserturm auf (5,8)
    warp MAP_WASSERTURM, 5, 8
    waitstate

    fadescreen FADE_FROM_BLACK
    waitstate

    showplayer
    applymovement LOCALID_PLAYER, Quadrate_Train_Movement_FaceNorth
    waitmovement 0

    releaseall
    end

Quadrate_Train_EventScript_WrongSide::
    msgbox Quadrate_Train_Text_WrongSide, MSGBOX_DEFAULT
    releaseall
    end

Quadrate_Train_EventScript_Cancel::
    releaseall
    end


@ =========================================================
@ Officer Script (blockt solange er da ist)
@ =========================================================
Quadrate_EventScript_LockedTrain::
    msgbox Quadrate_Text_LockedTrainMsg, MSGBOX_SIGN
    end


@ =========================================================
@ Text
@ =========================================================
Quadrate_Train_Text_AskTravel:
    .string "Do you want to travel\n"
    .string "to the Water Tower?$"

Quadrate_Train_Text_WrongSide:
    .string "The entrance is on the\n"
    .string "south side.$"

Quadrate_Text_LockedTrainMsg:
    .string "The train is not running at the\n"
    .string "moment. Please come back later.$"


@ =========================================================
@ Movements
@ =========================================================
Quadrate_Train_Movement_SlideRight20:
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

Quadrate_Train_Movement_FaceNorth:
    face_up
    step_end
