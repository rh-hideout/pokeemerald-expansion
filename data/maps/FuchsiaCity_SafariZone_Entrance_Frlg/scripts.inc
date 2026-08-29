FuchsiaCity_SafariZone_Entrance_Frlg_MapScripts::
    .byte 0


FuchsiaCity_SafariZone_Entrance_Frlg_EventScript_Worker1::
    lock
    faceplayer
    msgbox FuchsiaCity_SafariZone_Entrance_Frlg_Text_Worker1, MSGBOX_DEFAULT
    release
    end


FuchsiaCity_SafariZone_Entrance_Frlg_EventScript_Worker2::
    lock
    faceplayer
    msgbox FuchsiaCity_SafariZone_Entrance_Frlg_Text_Worker2, MSGBOX_DEFAULT
    release
    end


FuchsiaCity_SafariZone_Entrance_Frlg_Text_Worker1:
    .string "You'd be amazed how many people\n"
    .string "walk in here completely unprepared.\p"
    .string "Shoes matter.\n"
    .string "Trust me.$"


FuchsiaCity_SafariZone_Entrance_Frlg_Text_Worker2:
    .string "The POKéMON are unpredictable.\p"
    .string "The visitors are worse.$"
