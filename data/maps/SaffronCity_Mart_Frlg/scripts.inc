SaffronCity_Mart_Frlg_MapScripts::
        .byte 0


SaffronCity_Mart_Frlg_EventScript_Clerk::
        msgbox SaffronCity_Mart_Frlg_Text_Clerk, MSGBOX_NPC
        end

SaffronCity_Mart_Frlg_EventScript_Youngster::
        msgbox SaffronCity_Mart_Frlg_Text_Youngster, MSGBOX_NPC
        end

SaffronCity_Mart_Frlg_EventScript_Lass::
        msgbox SaffronCity_Mart_Frlg_Text_Lass, MSGBOX_NPC
        end


SaffronCity_Mart_Frlg_Text_Clerk:
        .string "Welcome!\p"
        .string "Take your time looking around.$"

SaffronCity_Mart_Frlg_Text_Youngster:
        .string "I came in for one thing.\p"
        .string "I forgot what it was.$"

SaffronCity_Mart_Frlg_Text_Lass:
        .string "Saffron has everything.\p"
        .string "That's dangerous for my wallet.$"
