MistysHouse_MapScripts::
    .byte 0


@ ============================================================
@ CERULEAN MISSION FINALE
@ ============================================================

MistysHouse_EventScript_CeruleanFinale::
    lockall

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

    setflag FLAG_CERULEAN_MISSION_COMPLETE

    releaseall
    end


MistysHouse_EventScript_NoRoomForExpShare:
    msgbox MistysHouse_Text_NoRoom, MSGBOX_DEFAULT
    releaseall
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
    .string "Make some room and talk to me\n"
    .string "again.$"
