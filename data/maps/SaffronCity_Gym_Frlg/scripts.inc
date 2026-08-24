SaffronCity_Gym_Frlg_MapScripts::
        .byte 0


@ =============================================================================
@ HISTORICAL SABRINA
@
@ This Sabrina belongs to the historical Saffron layer.
@ She can perceive Casey, but she does NOT know who Casey is.
@ =============================================================================

SaffronCity_Gym_Frlg_EventScript_HistoricalSabrina::
        lock
        faceplayer

        goto_if_set FLAG_SAFFRON_HISTORICAL_SABRINA_MET, SaffronCity_Gym_Frlg_EventScript_HistoricalSabrinaRepeat

        setflag FLAG_SAFFRON_HISTORICAL_SABRINA_MET

        @ Once historical Sabrina has perceived PLAYER,
        @ the mystery twin will be waiting outside when Saffron reloads.
        clearflag FLAG_HIDE_SAFFRON_MEMORY_TWIN

        msgbox SaffronCity_Gym_Frlg_Text_SabrinaNotFromSaffron, MSGBOX_DEFAULT
        closemessage

        msgbox SaffronCity_Gym_Frlg_Text_PlayerHowKnow, MSGBOX_DEFAULT
        closemessage

        msgbox SaffronCity_Gym_Frlg_Text_SabrinaSimpleAnswer, MSGBOX_DEFAULT
        closemessage

        msgbox SaffronCity_Gym_Frlg_Text_PlayerOh, MSGBOX_DEFAULT
        closemessage

        msgbox SaffronCity_Gym_Frlg_Text_SabrinaPsychicNotComplicated, MSGBOX_DEFAULT
        closemessage

        delay 10

        msgbox SaffronCity_Gym_Frlg_Text_SabrinaShouldntBeHere, MSGBOX_DEFAULT
        closemessage

        msgbox SaffronCity_Gym_Frlg_Text_PlayerInGym, MSGBOX_DEFAULT
        closemessage

        msgbox SaffronCity_Gym_Frlg_Text_SabrinaNoHere, MSGBOX_DEFAULT
        closemessage

        msgbox SaffronCity_Gym_Frlg_Text_PlayerWhatMean, MSGBOX_DEFAULT
        closemessage

        msgbox SaffronCity_Gym_Frlg_Text_SabrinaDoesntKnow, MSGBOX_DEFAULT
        closemessage

        msgbox SaffronCity_Gym_Frlg_Text_PlayerYourePsychic, MSGBOX_DEFAULT
        closemessage

        msgbox SaffronCity_Gym_Frlg_Text_SabrinaNotDictionary, MSGBOX_DEFAULT
        closemessage

        delay 10

        msgbox SaffronCity_Gym_Frlg_Text_SabrinaDisplaced, MSGBOX_DEFAULT
        closemessage

        msgbox SaffronCity_Gym_Frlg_Text_PlayerDisplaced, MSGBOX_DEFAULT
        closemessage

        msgbox SaffronCity_Gym_Frlg_Text_SabrinaRememberedBefore, MSGBOX_DEFAULT
        closemessage

        release
        end


SaffronCity_Gym_Frlg_EventScript_HistoricalSabrinaRepeat::
        @ Synchronize older/test saves with the current Saffron story state.
        setflag FLAG_SAFFRON_HISTORICAL_SABRINA_MET
        clearflag FLAG_HIDE_SAFFRON_MEMORY_TWIN
        @ Keep test/existing saves compatible:
        @ ensure the mystery twin is available when PLAYER exits the Gym.
        clearflag FLAG_HIDE_SAFFRON_MEMORY_TWIN

        msgbox SaffronCity_Gym_Frlg_Text_SabrinaStillHere, MSGBOX_DEFAULT
        closemessage

        msgbox SaffronCity_Gym_Frlg_Text_PlayerSoAreYou, MSGBOX_DEFAULT
        closemessage

        msgbox SaffronCity_Gym_Frlg_Text_SabrinaMyGym, MSGBOX_DEFAULT
        closemessage

        msgbox SaffronCity_Gym_Frlg_Text_PlayerFair, MSGBOX_DEFAULT
        release
        end


@ =============================================================================
@ DIALOGUE
@ =============================================================================

SaffronCity_Gym_Frlg_Text_SabrinaNotFromSaffron:
        .string "SABRINA: ...\p"
        .string "You're not from Saffron.$"


SaffronCity_Gym_Frlg_Text_PlayerHowKnow:
        .string "{PLAYER}: How do you know?$"


SaffronCity_Gym_Frlg_Text_SabrinaSimpleAnswer:
        .string "SABRINA: Because I've never seen\n"
        .string "you before.$"


SaffronCity_Gym_Frlg_Text_PlayerOh:
        .string "{PLAYER}: Oh.$"


SaffronCity_Gym_Frlg_Text_SabrinaPsychicNotComplicated:
        .string "SABRINA: Psychic doesn't mean\n"
        .string "everything has to be complicated.$"


SaffronCity_Gym_Frlg_Text_SabrinaShouldntBeHere:
        .string "SABRINA: Although...\p"
        .string "You shouldn't be here.$"


SaffronCity_Gym_Frlg_Text_PlayerInGym:
        .string "{PLAYER}: In your Gym?$"


SaffronCity_Gym_Frlg_Text_SabrinaNoHere:
        .string "SABRINA: No.\p"
        .string "Here.$"


SaffronCity_Gym_Frlg_Text_PlayerWhatMean:
        .string "{PLAYER}: ...What does that mean?$"


SaffronCity_Gym_Frlg_Text_SabrinaDoesntKnow:
        .string "SABRINA: I don't know.$"


SaffronCity_Gym_Frlg_Text_PlayerYourePsychic:
        .string "{PLAYER}: You're the psychic!$"


SaffronCity_Gym_Frlg_Text_SabrinaNotDictionary:
        .string "SABRINA: Yes.\p"
        .string "Not a dictionary.$"


SaffronCity_Gym_Frlg_Text_SabrinaDisplaced:
        .string "SABRINA: Something about you feels...\n"
        .string "displaced.$"


SaffronCity_Gym_Frlg_Text_PlayerDisplaced:
        .string "{PLAYER}: Displaced?$"


SaffronCity_Gym_Frlg_Text_SabrinaRememberedBefore:
        .string "SABRINA: Like a thought remembered\n"
        .string "before it happened.$"


SaffronCity_Gym_Frlg_Text_SabrinaStillHere:
        .string "SABRINA: You're still here.$"


SaffronCity_Gym_Frlg_Text_PlayerSoAreYou:
        .string "{PLAYER}: So are you.$"


SaffronCity_Gym_Frlg_Text_SabrinaMyGym:
        .string "SABRINA: It's my Gym.$"


SaffronCity_Gym_Frlg_Text_PlayerFair:
        .string "{PLAYER}: ...Fair.$"
