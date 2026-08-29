FuchsiaCity_House2_Frlg_MapScripts::
    .byte 0


FuchsiaCity_House2_Frlg_EventScript_Fisher::
    lock
    faceplayer
    msgbox FuchsiaCity_House2_Frlg_Text_Fisher, MSGBOX_DEFAULT
    release
    end


FuchsiaCity_House2_Frlg_Text_Fisher:
    .string "You can learn a lot while fishing.\p"
    .string "Patience.\n"
    .string "Timing.\p"
    .string "And exactly how long you can stare\n"
    .string "at water before going crazy.$"
