PewterCity_Museum_1F_Frlg_MapScripts::
    .byte 0


@ ============================================================================
@ NPCs
@ ============================================================================

PewterCity_Museum_1F_Frlg_EventScript_Scientist1::
    lock
    faceplayer
    msgbox PewterCity_Museum_1F_Frlg_Text_Scientist1, MSGBOX_DEFAULT
    release
    end


PewterCity_Museum_1F_Frlg_EventScript_OldMan::
    lock
    faceplayer
    msgbox PewterCity_Museum_1F_Frlg_Text_OldMan, MSGBOX_DEFAULT
    release
    end


PewterCity_Museum_1F_Frlg_EventScript_OldAmberScientist::
    lock
    faceplayer
    msgbox PewterCity_Museum_1F_Frlg_Text_OldAmberScientist, MSGBOX_DEFAULT
    release
    end


PewterCity_Museum_1F_Frlg_EventScript_Scientist2::
    lock
    faceplayer
    msgbox PewterCity_Museum_1F_Frlg_Text_Scientist2, MSGBOX_DEFAULT
    release
    end


PewterCity_Museum_1F_Frlg_EventScript_Researcher::
    lock
    faceplayer
    msgbox PewterCity_Museum_1F_Frlg_Text_Researcher, MSGBOX_DEFAULT
    release
    end


@ ============================================================================
@ EXHIBITS
@ ============================================================================

PewterCity_Museum_1F_Frlg_EventScript_OldAmber::
    msgbox PewterCity_Museum_1F_Frlg_Text_OldAmber, MSGBOX_SIGN
    end


PewterCity_Museum_1F_Frlg_EventScript_AerodactylFossil::
    msgbox PewterCity_Museum_1F_Frlg_Text_AerodactylFossil, MSGBOX_SIGN
    end


PewterCity_Museum_1F_Frlg_EventScript_KabutopsFossil::
    msgbox PewterCity_Museum_1F_Frlg_Text_KabutopsFossil, MSGBOX_SIGN
    end


PewterCity_Museum_1F_Frlg_EventScript_ArchiveMay17::
    msgbox PewterCity_Museum_1F_Frlg_Text_ArchiveMay17, MSGBOX_SIGN
    end


PewterCity_Museum_1F_Frlg_EventScript_ArchiveMay14::
    msgbox PewterCity_Museum_1F_Frlg_Text_ArchiveMay14, MSGBOX_SIGN
    end


@ ============================================================================
@ TEXT
@ ============================================================================

PewterCity_Museum_1F_Frlg_Text_Scientist1:
    .string "People think history is a list\n"
    .string "of facts.\p"
    .string "It isn't.\p"
    .string "We find evidence first.\p"
    .string "Then we decide what the evidence\n"
    .string "means.$"


PewterCity_Museum_1F_Frlg_Text_OldMan:
    .string "I've been coming here longer than\n"
    .string "some of these researchers have\l"
    .string "been alive.\p"
    .string "Funny thing about history...\p"
    .string "The older I get, the more often\n"
    .string "they change it.$"


PewterCity_Museum_1F_Frlg_Text_OldAmberScientist:
    .string "AMBER can preserve traces of life\n"
    .string "for an extraordinary amount of\l"
    .string "time.\p"
    .string "Something can disappear...\p"
    .string "and still leave evidence that it\n"
    .string "was here.$"


PewterCity_Museum_1F_Frlg_Text_Scientist2:
    .string "These fossils belonged to POKéMON\n"
    .string "that lived long before us.\p"
    .string "We know they existed because they\n"
    .string "left something behind.$"


PewterCity_Museum_1F_Frlg_Text_Researcher:
    .string "The secrets of the past...\p"
    .string "There are so many things about\n"
    .string "which we know so little.\p"
    .string "That's why we keep looking.$"


PewterCity_Museum_1F_Frlg_Text_OldAmber:
    .string "OLD AMBER\p"
    .string "Ancient tree resin hardened over\n"
    .string "an immense span of time.$"


PewterCity_Museum_1F_Frlg_Text_AerodactylFossil:
    .string "AERODACTYL FOSSIL\p"
    .string "A primitive and rare POKéMON.$"


PewterCity_Museum_1F_Frlg_Text_KabutopsFossil:
    .string "KABUTOPS FOSSIL\p"
    .string "A primitive and rare POKéMON.$"


PewterCity_Museum_1F_Frlg_Text_ArchiveMay17:
    .string "ARCHIVAL RECORD\p"
    .string "Excavation completed:\n"
    .string "MAY 17.$"


PewterCity_Museum_1F_Frlg_Text_ArchiveMay14:
    .string "ARCHIVAL NOTE\p"
    .string "Previous catalog entry:\n"
    .string "MAY 14.\p"
    .string "Reason for correction:\n"
    .string "UNDOCUMENTED.$"
