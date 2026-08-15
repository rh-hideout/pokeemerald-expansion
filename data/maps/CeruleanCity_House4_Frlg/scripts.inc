CeruleanCity_House4_Frlg_MapScripts::
    .byte 0

CeruleanCity_House4_Frlg_EventScript_NpcPlaceholder::
    end


@ CERULEAN CUSTOM NPC CLEANUP

CeruleanCity_House4_Frlg_EventScript_BerryMan::
    lock
    faceplayer
    msgbox CeruleanCity_House4_Frlg_Text_BerryMan, MSGBOX_DEFAULT
    release
    end

CeruleanCity_House4_Frlg_Text_BerryMan:
    .string "BERRIES are remarkable things.\p"
    .string "Take care of them, and they'll\n"
    .string "take care of you.$"

