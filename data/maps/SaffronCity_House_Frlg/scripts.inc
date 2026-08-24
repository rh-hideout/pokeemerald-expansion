SaffronCity_House_Frlg_MapScripts::
        .byte 0


SaffronCity_House_Frlg_EventScript_Pidgey::
        msgbox SaffronCity_House_Frlg_Text_Pidgey, MSGBOX_NPC
        end

SaffronCity_House_Frlg_EventScript_Lass::
        msgbox SaffronCity_House_Frlg_Text_Lass, MSGBOX_NPC
        end

SaffronCity_House_Frlg_EventScript_Youngster::
        msgbox SaffronCity_House_Frlg_Text_Youngster, MSGBOX_NPC
        end

SaffronCity_House_Frlg_EventScript_Clipboard::
        msgbox SaffronCity_House_Frlg_Text_Clipboard, MSGBOX_SIGN
        end


SaffronCity_House_Frlg_Text_Pidgey:
        .string "PIDGEY: Pijji!$"

SaffronCity_House_Frlg_Text_Lass:
        .string "It's noisy outside.\p"
        .string "I like it better in here.$"

SaffronCity_House_Frlg_Text_Youngster:
        .string "PIDGEY keeps trying to steal\n"
        .string "food from the table.$"

SaffronCity_House_Frlg_Text_Clipboard:
        .string "A shopping list is clipped here.\p"
        .string "Half of it is crossed out.$"
