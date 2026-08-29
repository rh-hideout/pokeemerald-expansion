PewterCity_PokemonCenter_1F_Frlg_MapScripts::
    .byte 0


PewterCity_PokemonCenter_1F_Frlg_EventScript_Nurse::
    lock
    faceplayer

    msgbox PewterCity_PokemonCenter_1F_Frlg_Text_NurseWelcome, MSGBOX_DEFAULT

    setvar VAR_0x800B, LOCALID_PEWTER_NURSE
    incrementgamestat GAME_STAT_USED_POKECENTER
    call EventScript_PkmnCenterNurse_TakeAndHealPkmn

    applymovement LOCALID_PEWTER_NURSE, Movement_PkmnCenterNurse_Bow
    waitmovement LOCALID_PEWTER_NURSE

    release
    end


PewterCity_PokemonCenter_1F_Frlg_EventScript_Jigglypuff::
    lock
    faceplayer
    msgbox PewterCity_PokemonCenter_1F_Frlg_Text_Jigglypuff, MSGBOX_DEFAULT
    release
    end


PewterCity_PokemonCenter_1F_Frlg_EventScript_Gentleman::
    lock
    faceplayer
    msgbox PewterCity_PokemonCenter_1F_Frlg_Text_Gentleman, MSGBOX_DEFAULT
    release
    end


PewterCity_PokemonCenter_1F_Frlg_EventScript_Youngster::
    lock
    faceplayer
    msgbox PewterCity_PokemonCenter_1F_Frlg_Text_Youngster, MSGBOX_DEFAULT
    release
    end


PewterCity_PokemonCenter_1F_Frlg_EventScript_Woman::
    lock
    faceplayer
    msgbox PewterCity_PokemonCenter_1F_Frlg_Text_Woman, MSGBOX_DEFAULT
    release
    end


PewterCity_PokemonCenter_1F_Frlg_EventScript_GbaKid1::
    lock
    faceplayer
    msgbox PewterCity_PokemonCenter_1F_Frlg_Text_GbaKid1, MSGBOX_DEFAULT
    release
    end


PewterCity_PokemonCenter_1F_Frlg_EventScript_GbaKid2::
    lock
    faceplayer
    msgbox PewterCity_PokemonCenter_1F_Frlg_Text_GbaKid2, MSGBOX_DEFAULT
    release
    end


PewterCity_PokemonCenter_1F_Frlg_Text_NurseWelcome:
    .string "Welcome to the POKéMON CENTER!\p"
    .string "I'll heal your POKéMON for you.$"


PewterCity_PokemonCenter_1F_Frlg_Text_Jigglypuff:
    .string "JIGGLYPUFF: Puuupuu!$"


PewterCity_PokemonCenter_1F_Frlg_Text_Gentleman:
    .string "PEWTER gets visitors from all\n"
    .string "over because of the museum.\p"
    .string "Most arrive looking for answers.\p"
    .string "They usually leave with more\n"
    .string "questions.$"


PewterCity_PokemonCenter_1F_Frlg_Text_Youngster:
    .string "Everyone talks about how old\n"
    .string "PEWTER is.\p"
    .string "I live here.\p"
    .string "It doesn't feel old to me.$"


PewterCity_PokemonCenter_1F_Frlg_Text_Woman:
    .string "The museum changes its exhibits\n"
    .string "when researchers learn something.\p"
    .string "Funny, isn't it?\p"
    .string "History can change without the\n"
    .string "past changing at all.$"


PewterCity_PokemonCenter_1F_Frlg_Text_GbaKid1:
    .string "I'm winning.$"


PewterCity_PokemonCenter_1F_Frlg_Text_GbaKid2:
    .string "No, you're not.$"
