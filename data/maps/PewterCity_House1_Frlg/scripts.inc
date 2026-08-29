PewterCity_House1_Frlg_MapScripts::
    .byte 0


PewterCity_House1_Frlg_EventScript_Man::
    lock
    faceplayer
    msgbox PewterCity_House1_Frlg_Text_Man, MSGBOX_DEFAULT
    release
    end


PewterCity_House1_Frlg_EventScript_Boy::
    lock
    faceplayer
    msgbox PewterCity_House1_Frlg_Text_Boy, MSGBOX_DEFAULT
    release
    end


PewterCity_House1_Frlg_EventScript_Nidoran::
    lock
    faceplayer
    msgbox PewterCity_House1_Frlg_Text_Nidoran, MSGBOX_DEFAULT
    release
    end


PewterCity_House1_Frlg_Text_Man:
    .string "That NIDORAN keeps digging up\n"
    .string "rocks in the yard.\p"
    .string "My son brings every single one\n"
    .string "inside.$"


PewterCity_House1_Frlg_Text_Boy:
    .string "NIDORAN keeps digging up rocks\n"
    .string "in the yard.\p"
    .string "SAVVY says one of them might be\n"
    .string "important.\p"
    .string "Dad says SAVVY says that about\n"
    .string "everything.$"


PewterCity_House1_Frlg_Text_Nidoran:
    .string "NIDORAN: Nido! Nidoran!$"
