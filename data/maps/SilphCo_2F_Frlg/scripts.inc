SilphCo_2F_Frlg_MapScripts::
        .byte 0


@ =============================================================================
@ SILPH CO. 2F - LORELEI
@ =============================================================================

SilphCo_2F_Frlg_EventScript_Lorelei::
        lock
        faceplayer

        goto_if_set FLAG_SILPH_LORELEI_MET, SilphCo_2F_Frlg_EventScript_LoreleiRepeat

        setflag FLAG_SILPH_LORELEI_MET

        msgbox SilphCo_2F_Frlg_Text_PlayerFinallyPerson, MSGBOX_DEFAULT
        closemessage

        msgbox SilphCo_2F_Frlg_Text_LoreleiStrangeGreeting, MSGBOX_DEFAULT
        closemessage

        msgbox SilphCo_2F_Frlg_Text_PlayerBuildingEmpty, MSGBOX_DEFAULT
        closemessage

        msgbox SilphCo_2F_Frlg_Text_LoreleiWasnt, MSGBOX_DEFAULT
        closemessage

        msgbox SilphCo_2F_Frlg_Text_PlayerWhatHappened, MSGBOX_DEFAULT
        closemessage

        msgbox SilphCo_2F_Frlg_Text_LoreleiSplit, MSGBOX_DEFAULT
        closemessage

        msgbox SilphCo_2F_Frlg_Text_PlayerBothSides, MSGBOX_DEFAULT
        closemessage

        msgbox SilphCo_2F_Frlg_Text_LoreleiAgreement, MSGBOX_DEFAULT
        closemessage

        msgbox SilphCo_2F_Frlg_Text_PlayerSeenBefore, MSGBOX_DEFAULT
        closemessage

        msgbox SilphCo_2F_Frlg_Text_LoreleiNo, MSGBOX_DEFAULT
        closemessage

        msgbox SilphCo_2F_Frlg_Text_PlayerDojo, MSGBOX_DEFAULT
        closemessage

        msgbox SilphCo_2F_Frlg_Text_LoreleiCareful, MSGBOX_DEFAULT
        closemessage

        msgbox SilphCo_2F_Frlg_Text_PlayerWhoAreYou, MSGBOX_DEFAULT
        closemessage

        msgbox SilphCo_2F_Frlg_Text_LoreleiName, MSGBOX_DEFAULT
        closemessage

        msgbox SilphCo_2F_Frlg_Text_PlayerWhyHere, MSGBOX_DEFAULT
        closemessage

        msgbox SilphCo_2F_Frlg_Text_LoreleiWhatsLeft, MSGBOX_DEFAULT
        closemessage

        msgbox SilphCo_2F_Frlg_Text_PlayerOfWhat, MSGBOX_DEFAULT
        closemessage

        msgbox SilphCo_2F_Frlg_Text_LoreleiTwelve, MSGBOX_DEFAULT
        closemessage

        msgbox SilphCo_2F_Frlg_Text_PlayerTwelve, MSGBOX_DEFAULT
        closemessage

        msgbox SilphCo_2F_Frlg_Text_LoreleiDidntSay, MSGBOX_DEFAULT
        closemessage

        msgbox SilphCo_2F_Frlg_Text_PlayerKindaDid, MSGBOX_DEFAULT
        closemessage

        msgbox SilphCo_2F_Frlg_Text_LoreleiPretend, MSGBOX_DEFAULT
        closemessage

        release
        end


SilphCo_2F_Frlg_EventScript_LoreleiRepeat::
        msgbox SilphCo_2F_Frlg_Text_LoreleiRepeat, MSGBOX_DEFAULT
        closemessage

        release
        end


@ =============================================================================
@ TEXT
@ =============================================================================

SilphCo_2F_Frlg_Text_PlayerFinallyPerson:
        .string "{PLAYER}: Finally.\p"
        .string "A person.$"


SilphCo_2F_Frlg_Text_LoreleiStrangeGreeting:
        .string "LORELEI: ...That's an unusual\n"
        .string "greeting.$"


SilphCo_2F_Frlg_Text_PlayerBuildingEmpty:
        .string "{PLAYER}: Sorry.\p"
        .string "This whole building is empty.$"


SilphCo_2F_Frlg_Text_LoreleiWasnt:
        .string "LORELEI: It wasn't.$"


SilphCo_2F_Frlg_Text_PlayerWhatHappened:
        .string "{PLAYER}: What happened?$"


SilphCo_2F_Frlg_Text_LoreleiSplit:
        .string "LORELEI: Silph depended on work\n"
        .string "from both sides.\p"
        .string "When the split happened, projects\n"
        .string "stopped.\p"
        .string "Contracts disappeared.\p"
        .string "Eventually, the employees did too.$"


SilphCo_2F_Frlg_Text_PlayerBothSides:
        .string "{PLAYER}: Both sides of what?$"


SilphCo_2F_Frlg_Text_LoreleiAgreement:
        .string "LORELEI: An agreement that stopped\n"
        .string "being one.$"


SilphCo_2F_Frlg_Text_PlayerSeenBefore:
        .string "{PLAYER}: ...I've seen you before.$"


SilphCo_2F_Frlg_Text_LoreleiNo:
        .string "LORELEI: No.\p"
        .string "You haven't.$"


SilphCo_2F_Frlg_Text_PlayerDojo:
        .string "{PLAYER}: At the dojo--$"


SilphCo_2F_Frlg_Text_LoreleiCareful:
        .string "LORELEI: I would be very careful\n"
        .string "finishing that sentence.$"


SilphCo_2F_Frlg_Text_PlayerWhoAreYou:
        .string "{PLAYER}: ...Who are you?$"


SilphCo_2F_Frlg_Text_LoreleiName:
        .string "LORELEI: Lorelei.$"


SilphCo_2F_Frlg_Text_PlayerWhyHere:
        .string "{PLAYER}: Why are you still here?$"


SilphCo_2F_Frlg_Text_LoreleiWhatsLeft:
        .string "LORELEI: Someone should see what's\n"
        .string "left.$"


SilphCo_2F_Frlg_Text_PlayerOfWhat:
        .string "{PLAYER}: Left of what?$"


SilphCo_2F_Frlg_Text_LoreleiTwelve:
        .string "LORELEI: Twelve people can build\n"
        .string "a great deal when they agree.\p"
        .string "They can undo even more when\n"
        .string "they don't.$"


SilphCo_2F_Frlg_Text_PlayerTwelve:
        .string "{PLAYER}: ...The Twelve?$"


SilphCo_2F_Frlg_Text_LoreleiDidntSay:
        .string "LORELEI: I didn't say that.$"


SilphCo_2F_Frlg_Text_PlayerKindaDid:
        .string "{PLAYER}: You kinda did.$"


SilphCo_2F_Frlg_Text_LoreleiPretend:
        .string "LORELEI: Then pretend I didn't.$"


SilphCo_2F_Frlg_Text_LoreleiRepeat:
        .string "LORELEI: Still here?\p"
        .string "If you're determined to keep\n"
        .string "asking questions...\p"
        .string "There are more floors.$"

@ =============================================================================
@ OPTIONAL ENVIRONMENTAL LORE
@ =============================================================================

SilphCo_2F_Frlg_EventScript_SuspendedProjects::
        msgbox SilphCo_2F_Frlg_Text_SuspendedProjects, MSGBOX_SIGN
        end

SilphCo_2F_Frlg_EventScript_AuthorizationNote::
        msgbox SilphCo_2F_Frlg_Text_AuthorizationNote, MSGBOX_SIGN
        end

SilphCo_2F_Frlg_Text_SuspendedProjects:
        .string "Several project folders were\p"
        .string "left behind.\p"
        .string "Most are stamped: SUSPENDED.$"

SilphCo_2F_Frlg_Text_AuthorizationNote:
        .string "One folder is marked by hand:\p"
        .string "PENDING AUTHORIZATION.\p"
        .string "{PLAYER}: Authorization from who...?$"
