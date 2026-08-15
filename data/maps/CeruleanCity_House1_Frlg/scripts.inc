CeruleanCity_House1_Frlg_MapScripts::
    .byte 0

CeruleanCity_House1_Frlg_EventScript_NpcPlaceholder::
    end


@ CERULEAN CUSTOM NPC CLEANUP

CeruleanCity_House1_Frlg_EventScript_Gentleman::
    lock
    faceplayer
    msgbox CeruleanCity_House1_Frlg_Text_Gentleman, MSGBOX_DEFAULT
    release
    end

CeruleanCity_House1_Frlg_Text_Gentleman:
    .string "CERULEAN'S a nice place.\p"
    .string "Usually a lot quieter than it has\n"
    .string "been today.$"

