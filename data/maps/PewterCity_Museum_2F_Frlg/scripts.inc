PewterCity_Museum_2F_Frlg_MapScripts::
    .byte 0


@ ============================================================================
@ NPCs
@ ============================================================================

PewterCity_Museum_2F_Frlg_EventScript_Scientist::
    lock
    faceplayer
    msgbox PewterCity_Museum_2F_Frlg_Text_Scientist, MSGBOX_DEFAULT
    release
    end


PewterCity_Museum_2F_Frlg_EventScript_Man::
    lock
    faceplayer
    msgbox PewterCity_Museum_2F_Frlg_Text_Man, MSGBOX_DEFAULT
    release
    end


PewterCity_Museum_2F_Frlg_EventScript_OldMan::
    lock
    faceplayer
    msgbox PewterCity_Museum_2F_Frlg_Text_OldMan, MSGBOX_DEFAULT
    release
    end


PewterCity_Museum_2F_Frlg_EventScript_LittleGirl::
    lock
    faceplayer
    msgbox PewterCity_Museum_2F_Frlg_Text_LittleGirl, MSGBOX_DEFAULT
    release
    end


PewterCity_Museum_2F_Frlg_EventScript_BaldingMan::
    lock
    faceplayer
    msgbox PewterCity_Museum_2F_Frlg_Text_BaldingMan, MSGBOX_DEFAULT
    release
    end


@ ============================================================================
@ EXHIBITS
@ ============================================================================

PewterCity_Museum_2F_Frlg_EventScript_MoonStone::
    msgbox PewterCity_Museum_2F_Frlg_Text_MoonStone, MSGBOX_SIGN
    end


PewterCity_Museum_2F_Frlg_EventScript_SpaceShuttle::
    msgbox PewterCity_Museum_2F_Frlg_Text_SpaceShuttle, MSGBOX_SIGN
    end


@ ============================================================================
@ TEXT
@ ============================================================================

PewterCity_Museum_2F_Frlg_Text_Scientist:
    .string "This floor studies things beyond\n"
    .string "our world.\p"
    .string "The farther away you stand from\n"
    .string "something...\p"
    .string "the easier its shape can be to\n"
    .string "see.\p"
    .string "Sometimes you can't understand a\n"
    .string "system from inside it.$"


PewterCity_Museum_2F_Frlg_Text_Man:
    .string "A MOON STONE, huh?\p"
    .string "Looks like an ordinary rock to me.\p"
    .string "Guess appearances don't tell you\n"
    .string "everything.$"


PewterCity_Museum_2F_Frlg_Text_OldMan:
    .string "That record downstairs used to\n"
    .string "have a different date.\p"
    .string "I told them.\p"
    .string "They told me records get corrected.\p"
    .string "Maybe.\p"
    .string "Still bothers me.$"


PewterCity_Museum_2F_Frlg_Text_LittleGirl:
    .string "I want a PIKACHU!\p"
    .string "I asked my daddy to catch me one!$"


PewterCity_Museum_2F_Frlg_Text_BaldingMan:
    .string "Yeah, a PIKACHU soon.\p"
    .string "I promise.$"


PewterCity_Museum_2F_Frlg_Text_MoonStone:
    .string "METEORITE FROM MT. MOON\p"
    .string "Believed to contain material\n"
    .string "similar to a MOON STONE.$"


PewterCity_Museum_2F_Frlg_Text_SpaceShuttle:
    .string "SPACE SHUTTLE\p"
    .string "Built to carry people beyond the\n"
    .string "world they know.$"
