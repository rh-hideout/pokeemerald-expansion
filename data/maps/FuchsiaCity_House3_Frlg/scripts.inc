FuchsiaCity_House3_Frlg_MapScripts::
    .byte 0


FuchsiaCity_House3_Frlg_EventScript_Man::
    lock
    faceplayer
    msgbox FuchsiaCity_House3_Frlg_Text_Man, MSGBOX_DEFAULT
    release
    end


FuchsiaCity_House3_Frlg_Text_Man:
    .string "Tourists always ask where the\n"
    .string "interesting part of FUCHSIA is.\p"
    .string "I tell them to go outside.$"
