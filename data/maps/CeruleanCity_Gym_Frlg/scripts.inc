CeruleanCity_Gym_Frlg_MapScripts::
    .byte 0


@ ============================================================
@ MISTY - WHY ARE YOU HERE?
@ ============================================================

CeruleanCity_Gym_Frlg_EventScript_Misty::
    lock
    faceplayer

    msgbox CeruleanCity_Gym_Frlg_Text_MistyIntro, MSGBOX_DEFAULT
    closemessage

    msgbox CeruleanCity_Gym_Frlg_Text_PlayerMission, MSGBOX_DEFAULT
    closemessage

    msgbox CeruleanCity_Gym_Frlg_Text_MistyConfused, MSGBOX_DEFAULT
    closemessage

    msgbox CeruleanCity_Gym_Frlg_Text_PlayerRealization, MSGBOX_DEFAULT
    closemessage

    msgbox CeruleanCity_Gym_Frlg_Text_MistyKickOut, MSGBOX_DEFAULT
    closemessage

    warp MAP_CERULEAN_CITY, 31, 22
    waitstate
    release
    end


@ ============================================================
@ TEXT
@ ============================================================

CeruleanCity_Gym_Frlg_Text_MistyIntro:
    .string "{PLAYER}: Misty?\p"
    .string "MISTY: Um... yeah?\p"
    .string "Who are you?$"


CeruleanCity_Gym_Frlg_Text_PlayerMission:
    .string "{PLAYER}: ...What?\p"
    .string "You gave me a whole mission!$"


CeruleanCity_Gym_Frlg_Text_MistyConfused:
    .string "MISTY: I did?\p"
    .string "...Oh.\p"
    .string "Wait.\p"
    .string "You seem like you've got a few\n"
    .string "screws loose, but...\p"
    .string "If I gave you a mission, shouldn't\n"
    .string "you be focused on maybe THAT\l"
    .string "instead of being HERE?$"


CeruleanCity_Gym_Frlg_Text_PlayerRealization:
    .string "{PLAYER}: ...\p"
    .string "James said he went back in time...\p"
    .string "He MEANT that?$"


CeruleanCity_Gym_Frlg_Text_MistyKickOut:
    .string "MISTY: Okay!\p"
    .string "Good talk!$"


CeruleanCity_Gym_Frlg_EventScript_NpcPlaceholder::
    end
