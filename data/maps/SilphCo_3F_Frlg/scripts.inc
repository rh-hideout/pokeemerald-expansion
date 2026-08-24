SilphCo_3F_Frlg_MapScripts::
        map_script MAP_SCRIPT_ON_LOAD, SilphCo_3F_Frlg_SetStrangerGraphics
        .byte 0


@ =============================================================================
@ DYNAMIC FAMILIAR STRANGER
@ =============================================================================

SilphCo_3F_Frlg_SetStrangerGraphics:
        goto_if_set FLAG_HIDE_HOME_MOM, SilphCo_3F_Frlg_SetTiaGraphics

        @ Mom/Tia raised PLAYER -> stranger is Elias.
        setvar VAR_OBJ_GFX_ID_2, OBJ_EVENT_GFX_NORMAN
        return


SilphCo_3F_Frlg_SetTiaGraphics:
        @ Dad/Elias raised PLAYER -> stranger is Tia.
        setvar VAR_OBJ_GFX_ID_2, OBJ_EVENT_GFX_MOM
        return


@ =============================================================================
@ FAMILIAR STRANGER
@ =============================================================================

SilphCo_3F_Frlg_EventScript_FamiliarStranger::
        lock
        faceplayer

        goto_if_set FLAG_SILPH_FAMILIAR_STRANGER_MET, SilphCo_3F_Frlg_EventScript_FamiliarStrangerRepeat

        setflag FLAG_SILPH_FAMILIAR_STRANGER_MET

        msgbox SilphCo_3F_Frlg_Text_PlayerStares, MSGBOX_DEFAULT
        closemessage

        msgbox SilphCo_3F_Frlg_Text_StrangerHelpYou, MSGBOX_DEFAULT
        closemessage

        msgbox SilphCo_3F_Frlg_Text_PlayerKnowYou, MSGBOX_DEFAULT
        closemessage

        msgbox SilphCo_3F_Frlg_Text_StrangerDontBelieveSo, MSGBOX_DEFAULT
        closemessage

        msgbox SilphCo_3F_Frlg_Text_PlayerRememberYou, MSGBOX_DEFAULT
        closemessage

        msgbox SilphCo_3F_Frlg_Text_StrangerFromWhere, MSGBOX_DEFAULT
        closemessage

        msgbox SilphCo_3F_Frlg_Text_PlayerDoesntKnow, MSGBOX_DEFAULT
        closemessage

        msgbox SilphCo_3F_Frlg_Text_StrangerPerhapsNot, MSGBOX_DEFAULT
        closemessage

        delay 10

        msgbox SilphCo_3F_Frlg_Text_StrangerUncomfortable, MSGBOX_DEFAULT
        closemessage

        msgbox SilphCo_3F_Frlg_Text_PlayerWhoAreYou, MSGBOX_DEFAULT
        closemessage

        goto_if_set FLAG_HIDE_HOME_MOM, SilphCo_3F_Frlg_EventScript_TiaIntroduction
        goto SilphCo_3F_Frlg_EventScript_EliasIntroduction


SilphCo_3F_Frlg_EventScript_TiaIntroduction:
        msgbox SilphCo_3F_Frlg_Text_TiaName, MSGBOX_DEFAULT
        closemessage

        msgbox SilphCo_3F_Frlg_Text_PlayerDoesntHelp, MSGBOX_DEFAULT
        closemessage

        msgbox SilphCo_3F_Frlg_Text_PlayerWhatDoYouDo, MSGBOX_DEFAULT
        closemessage

        msgbox SilphCo_3F_Frlg_Text_TiaRecords, MSGBOX_DEFAULT
        closemessage

        msgbox SilphCo_3F_Frlg_Text_PlayerSecretary, MSGBOX_DEFAULT
        closemessage

        msgbox SilphCo_3F_Frlg_Text_TiaNo, MSGBOX_DEFAULT
        closemessage

        goto SilphCo_3F_Frlg_EventScript_FamiliarStrangerFinish


SilphCo_3F_Frlg_EventScript_EliasIntroduction:
        msgbox SilphCo_3F_Frlg_Text_EliasName, MSGBOX_DEFAULT
        closemessage

        msgbox SilphCo_3F_Frlg_Text_PlayerDoesntHelp, MSGBOX_DEFAULT
        closemessage

        msgbox SilphCo_3F_Frlg_Text_PlayerWhatDoYouDo, MSGBOX_DEFAULT
        closemessage

        msgbox SilphCo_3F_Frlg_Text_EliasAccess, MSGBOX_DEFAULT
        closemessage

        msgbox SilphCo_3F_Frlg_Text_PlayerSecurity, MSGBOX_DEFAULT
        closemessage

        msgbox SilphCo_3F_Frlg_Text_EliasNotExactly, MSGBOX_DEFAULT
        closemessage


SilphCo_3F_Frlg_EventScript_FamiliarStrangerFinish:
        msgbox SilphCo_3F_Frlg_Text_PlayerWhySilph, MSGBOX_DEFAULT
        closemessage

        msgbox SilphCo_3F_Frlg_Text_StrangerLooseEnds, MSGBOX_DEFAULT
        closemessage

        msgbox SilphCo_3F_Frlg_Text_PlayerEveryoneSaysThat, MSGBOX_DEFAULT
        closemessage

        msgbox SilphCo_3F_Frlg_Text_StrangerMaybeListen, MSGBOX_DEFAULT
        closemessage

        release
        end


SilphCo_3F_Frlg_EventScript_FamiliarStrangerRepeat:
        msgbox SilphCo_3F_Frlg_Text_StrangerRepeat, MSGBOX_DEFAULT
        closemessage

        release
        end


@ =============================================================================
@ SHARED TEXT
@ =============================================================================

SilphCo_3F_Frlg_Text_PlayerStares:
        .string "{PLAYER}: ...$"


SilphCo_3F_Frlg_Text_StrangerHelpYou:
        .string "???: Can I help you?$"


SilphCo_3F_Frlg_Text_PlayerKnowYou:
        .string "{PLAYER}: I know you.$"


SilphCo_3F_Frlg_Text_StrangerDontBelieveSo:
        .string "???: I don't believe you do.$"


SilphCo_3F_Frlg_Text_PlayerRememberYou:
        .string "{PLAYER}: No...\n"
        .string "I remember you.$"


SilphCo_3F_Frlg_Text_StrangerFromWhere:
        .string "???: From where?$"


SilphCo_3F_Frlg_Text_PlayerDoesntKnow:
        .string "{PLAYER}: I...\p"
        .string "I don't know.$"


SilphCo_3F_Frlg_Text_StrangerPerhapsNot:
        .string "???: Then perhaps you don't\n"
        .string "remember me.$"


SilphCo_3F_Frlg_Text_StrangerUncomfortable:
        .string "???: You're making this unusually\n"
        .string "uncomfortable.$"


SilphCo_3F_Frlg_Text_PlayerWhoAreYou:
        .string "{PLAYER}: Who ARE you?$"


SilphCo_3F_Frlg_Text_PlayerDoesntHelp:
        .string "{PLAYER}: ...That doesn't help.$"


SilphCo_3F_Frlg_Text_PlayerWhatDoYouDo:
        .string "{PLAYER}: What do you even do here?$"


SilphCo_3F_Frlg_Text_PlayerWhySilph:
        .string "{PLAYER}: Then why are you at Silph?$"


SilphCo_3F_Frlg_Text_StrangerLooseEnds:
        .string "???: Loose ends.$"


SilphCo_3F_Frlg_Text_PlayerEveryoneSaysThat:
        .string "{PLAYER}: Everybody here talks like\n"
        .string "they're hiding something.$"


SilphCo_3F_Frlg_Text_StrangerMaybeListen:
        .string "???: Perhaps you should listen\n"
        .string "to that instinct.$"


SilphCo_3F_Frlg_Text_StrangerRepeat:
        .string "???: Still trying to remember me?\p"
        .string "I wouldn't force it.$"


@ =============================================================================
@ TIA PATH
@ =============================================================================

SilphCo_3F_Frlg_Text_TiaName:
        .string "TIA: Tia.$"


SilphCo_3F_Frlg_Text_TiaRecords:
        .string "TIA: I'm responsible for records.$"


SilphCo_3F_Frlg_Text_PlayerSecretary:
        .string "{PLAYER}: Like a secretary?$"


SilphCo_3F_Frlg_Text_TiaNo:
        .string "TIA: ...No.$"


@ =============================================================================
@ ELIAS PATH
@ =============================================================================

SilphCo_3F_Frlg_Text_EliasName:
        .string "ELIAS: Elias.$"


SilphCo_3F_Frlg_Text_EliasAccess:
        .string "ELIAS: I'm responsible for access.$"


SilphCo_3F_Frlg_Text_PlayerSecurity:
        .string "{PLAYER}: Like security?$"


SilphCo_3F_Frlg_Text_EliasNotExactly:
        .string "ELIAS: ...Not exactly.$"

@ =============================================================================
@ OPTIONAL ENVIRONMENTAL LORE
@ =============================================================================

SilphCo_3F_Frlg_EventScript_BookkeeperMemo::
        msgbox SilphCo_3F_Frlg_Text_BookkeeperMemo, MSGBOX_SIGN
        end

SilphCo_3F_Frlg_EventScript_KeykeeperMemo::
        msgbox SilphCo_3F_Frlg_Text_KeykeeperMemo, MSGBOX_SIGN
        end

SilphCo_3F_Frlg_Text_BookkeeperMemo:
        .string "An internal notice reads:\p"
        .string "ARCHIVAL MATERIALS REQUIRE\p"
        .string "APPROVAL FROM THE BOOKKEEPER.$"

SilphCo_3F_Frlg_Text_KeykeeperMemo:
        .string "Another notice reads:\p"
        .string "RESTRICTED ACCESS REQUIRES\p"
        .string "THE KEEPER OF THE KEY.$"
