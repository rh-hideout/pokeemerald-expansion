SilphCo_1F_Frlg_MapScripts::
        .byte 0


@ =============================================================================
@ SILPH CO. 1F - EMPTY BUILDING REACTIONS
@ =============================================================================

SilphCo_1F_Frlg_EventScript_EntranceReaction::
        lockall

        msgbox SilphCo_1F_Frlg_Text_EntranceReaction, MSGBOX_DEFAULT
        closemessage

        setvar VAR_SILPH_1F_STATE, 1

        releaseall
        end


SilphCo_1F_Frlg_EventScript_MiddleReaction::
        lockall

        msgbox SilphCo_1F_Frlg_Text_MiddleReaction, MSGBOX_DEFAULT
        closemessage

        setvar VAR_SILPH_1F_STATE, 2

        releaseall
        end


SilphCo_1F_Frlg_EventScript_StairsReaction::
        lockall

        msgbox SilphCo_1F_Frlg_Text_StairsReaction, MSGBOX_DEFAULT
        closemessage

        setvar VAR_SILPH_1F_STATE, 3

        releaseall
        end


@ =============================================================================
@ TEXT
@ =============================================================================

SilphCo_1F_Frlg_Text_EntranceReaction:
        .string "{PLAYER}: ...Hello?\p"
        .string "This place is huge.\p"
        .string "...Where is everybody?$"


SilphCo_1F_Frlg_Text_MiddleReaction:
        .string "{PLAYER}: Nobody at reception either...\p"
        .string "But everything's still here.\p"
        .string "Computers... paperwork...\p"
        .string "This doesn't look abandoned.\n"
        .string "It looks like everyone just... left.$"

SilphCo_1F_Frlg_Text_StairsReaction:
        .string "{PLAYER}: ...Nothing.\p"
        .string "There's no way this whole place\n"
        .string "is empty.\p"
        .string "Someone has to be upstairs.$"


@ =============================================================================
@ POST-GIOVANNI RETURN
@ =============================================================================

SilphCo_1F_Frlg_EventScript_PostGiovanniReturn::
        goto_if_unset FLAG_SILPH_GIOVANNI_MET, SilphCo_1F_Frlg_EventScript_PostGiovanniReturnDone

        lockall

        msgbox SilphCo_1F_Frlg_Text_PostGiovanniReturn, MSGBOX_DEFAULT
        closemessage

        setvar VAR_SILPH_1F_STATE, 4

        releaseall
        end


SilphCo_1F_Frlg_EventScript_PostGiovanniReturnDone:
        end


SilphCo_1F_Frlg_Text_PostGiovanniReturn:
        .string "{PLAYER}: ...You know what?\p"
        .string "I think I liked this place better\p"
        .string "when I thought it was just empty.$"

@ =============================================================================
@ OPTIONAL ENVIRONMENTAL LORE
@ =============================================================================

SilphCo_1F_Frlg_EventScript_VisitorLog::
        msgbox SilphCo_1F_Frlg_Text_VisitorLog, MSGBOX_SIGN
        end

SilphCo_1F_Frlg_Text_VisitorLog:
        .string "A visitor log sits open.\p"
        .string "Several appointments are crossed\p"
        .string "out. The final page is blank.$"
