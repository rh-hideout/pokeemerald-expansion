FuchsiaCity_House1_Frlg_MapScripts::
    .byte 0


FuchsiaCity_House1_Frlg_EventScript_OldMan::
    lock
    faceplayer
    msgbox FuchsiaCity_House1_Frlg_Text_OldMan, MSGBOX_DEFAULT
    release
    end


FuchsiaCity_House1_Frlg_EventScript_Woman::
    lock
    faceplayer
    msgbox FuchsiaCity_House1_Frlg_Text_Woman, MSGBOX_DEFAULT
    release
    end


FuchsiaCity_House1_Frlg_EventScript_Boy::
    lock
    faceplayer
    msgbox FuchsiaCity_House1_Frlg_Text_Boy, MSGBOX_DEFAULT
    release
    end


FuchsiaCity_House1_Frlg_Text_OldMan:
    .string "I've lived in FUCHSIA longer than\n"
    .string "most of those trees have.\p"
    .string "The city changes.\n"
    .string "The POKéMON don't seem to mind.$"


FuchsiaCity_House1_Frlg_Text_Woman:
    .string "He says that like the trees\n"
    .string "haven't been here longer than him.$"


FuchsiaCity_House1_Frlg_Text_Boy:
    .string "They have this argument\n"
    .string "ALL the time.\p"
    .string "The trees never answer.$"
