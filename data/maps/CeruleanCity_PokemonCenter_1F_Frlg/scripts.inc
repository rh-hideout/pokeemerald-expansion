CeruleanCity_PokemonCenter_1F_Frlg_MapScripts::
    .byte 0


CeruleanCity_PokemonCenter_1F_Frlg_EventScript_Nurse::
    lockall

    applymovement LOCALID_CERULEAN_NURSE, Common_Movement_FacePlayer
    waitmovement 0

    msgbox CeruleanCity_PokemonCenter_1F_Frlg_Text_NurseHeal, MSGBOX_DEFAULT
    closemessage

    fadescreen FADE_TO_WHITE
    special HealPlayerParty
    fadescreen FADE_FROM_WHITE

    releaseall
    end


CeruleanCity_PokemonCenter_1F_Frlg_EventScript_NpcPlaceholder::
    end


@ CERULEAN CUSTOM NPC CLEANUP

CeruleanCity_PokemonCenter_1F_Frlg_EventScript_Gentleman::
    lock
    faceplayer
    msgbox CeruleanCity_PokemonCenter_1F_Frlg_Text_Gentleman, MSGBOX_DEFAULT
    release
    end

CeruleanCity_PokemonCenter_1F_Frlg_Text_Gentleman:
    .string "You aren't from around here,\n"
    .string "are you?\p"
    .string "CERULEAN gets all kinds of\n"
    .string "Trainers passing through.$"

CeruleanCity_PokemonCenter_1F_Frlg_EventScript_Rocker::
    lock
    faceplayer
    msgbox CeruleanCity_PokemonCenter_1F_Frlg_Text_Rocker, MSGBOX_DEFAULT
    release
    end

CeruleanCity_PokemonCenter_1F_Frlg_Text_Rocker:
    .string "That MISTY kid is seriously\n"
    .string "something else.\p"
    .string "Don't let the age fool you.$"

CeruleanCity_PokemonCenter_1F_Frlg_EventScript_Youngster::
    lock
    faceplayer
    msgbox CeruleanCity_PokemonCenter_1F_Frlg_Text_Youngster, MSGBOX_DEFAULT
    release
    end

CeruleanCity_PokemonCenter_1F_Frlg_Text_Youngster:
    .string "Someday I'm gonna be strong enough\n"
    .string "to challenge everybody!$"

CeruleanCity_PokemonCenter_1F_Frlg_EventScript_Lass::
    lock
    faceplayer
    msgbox CeruleanCity_PokemonCenter_1F_Frlg_Text_Lass, MSGBOX_DEFAULT
    release
    end

CeruleanCity_PokemonCenter_1F_Frlg_Text_Lass:
    .string "Something feels weird around town\n"
    .string "today.\p"
    .string "Maybe it's just me.$"



CeruleanCity_PokemonCenter_1F_Frlg_Text_NurseHeal:
    .string "NURSE: I'll restore your POKéMON\n"
    .string "to full health.$"
