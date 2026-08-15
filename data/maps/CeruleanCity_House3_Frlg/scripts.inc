CeruleanCity_House3_Frlg_MapScripts::
    .byte 0

CeruleanCity_House3_Frlg_EventScript_NpcPlaceholder::
    end


@ CERULEAN CUSTOM NPC CLEANUP

CeruleanCity_House3_Frlg_EventScript_OldMan::
    lock
    faceplayer
    msgbox CeruleanCity_House3_Frlg_Text_OldMan, MSGBOX_DEFAULT
    release
    end

CeruleanCity_House3_Frlg_Text_OldMan:
    .string "Young Trainers are always rushing\n"
    .string "off somewhere.\p"
    .string "Nobody knows how to sit still\n"
    .string "anymore.$"

CeruleanCity_House3_Frlg_EventScript_OldWoman::
    lock
    faceplayer
    msgbox CeruleanCity_House3_Frlg_Text_OldWoman, MSGBOX_DEFAULT
    release
    end

CeruleanCity_House3_Frlg_Text_OldWoman:
    .string "Don't mind him.\p"
    .string "He was exactly the same way when\n"
    .string "he was young.$"

