SilphCo_4F_Frlg_MapScripts::
        .byte 0


@ =============================================================================
@ SILPH CO. 4F - PAST MISTY
@
@ FLAG_HIDE_HOME_MOM SET:
@   Elias raised PLAYER -> Misty complains about Elias.
@
@ FLAG_HIDE_HOME_MOM UNSET:
@   Tia raised PLAYER -> Misty complains about Tia.
@ =============================================================================

SilphCo_4F_Frlg_EventScript_Misty::
        lock
        faceplayer

        goto_if_set FLAG_SILPH_PAST_MISTY_MET, SilphCo_4F_Frlg_EventScript_MistyRepeat

        setflag FLAG_SILPH_PAST_MISTY_MET

        @ PLAYER recognizes Misty.
        @ Misty has never met PLAYER... yet.
        msgbox SilphCo_4F_Frlg_Text_PlayerMisty, MSGBOX_DEFAULT
        closemessage

        msgbox SilphCo_4F_Frlg_Text_MistyKnowYou, MSGBOX_DEFAULT
        closemessage

        msgbox SilphCo_4F_Frlg_Text_PlayerComeOn, MSGBOX_DEFAULT
        closemessage

        msgbox SilphCo_4F_Frlg_Text_MistyNotAnswer, MSGBOX_DEFAULT
        closemessage

        msgbox SilphCo_4F_Frlg_Text_PlayerGettingThat, MSGBOX_DEFAULT
        closemessage

        msgbox SilphCo_4F_Frlg_Text_MistyGettingWhat, MSGBOX_DEFAULT
        closemessage

        msgbox SilphCo_4F_Frlg_Text_PlayerGiveUp, MSGBOX_DEFAULT
        closemessage

        msgbox SilphCo_4F_Frlg_Text_MistySmart, MSGBOX_DEFAULT
        closemessage

        msgbox SilphCo_4F_Frlg_Text_PlayerNotCompliment, MSGBOX_DEFAULT
        closemessage

        msgbox SilphCo_4F_Frlg_Text_MistyWasnt, MSGBOX_DEFAULT
        closemessage

        @ Now Misty resumes her rant about the parent
        @ PLAYER actually grew up with.
        goto_if_set FLAG_HIDE_HOME_MOM, SilphCo_4F_Frlg_EventScript_MistyEliasRant
        goto SilphCo_4F_Frlg_EventScript_MistyTiaRant


@ =============================================================================
@ TIA RANT
@ =============================================================================

SilphCo_4F_Frlg_EventScript_MistyTiaRant:
        msgbox SilphCo_4F_Frlg_Text_MistyTiaRant1, MSGBOX_DEFAULT
        closemessage

        msgbox SilphCo_4F_Frlg_Text_MistyTiaRant2, MSGBOX_DEFAULT
        closemessage

        msgbox SilphCo_4F_Frlg_Text_PlayerTia, MSGBOX_DEFAULT
        closemessage

        msgbox SilphCo_4F_Frlg_Text_MistyWhyTia, MSGBOX_DEFAULT
        closemessage

        goto SilphCo_4F_Frlg_EventScript_MistyShared


@ =============================================================================
@ ELIAS RANT
@ =============================================================================

SilphCo_4F_Frlg_EventScript_MistyEliasRant:
        msgbox SilphCo_4F_Frlg_Text_MistyEliasRant1, MSGBOX_DEFAULT
        closemessage

        msgbox SilphCo_4F_Frlg_Text_MistyEliasRant2, MSGBOX_DEFAULT
        closemessage

        msgbox SilphCo_4F_Frlg_Text_PlayerElias, MSGBOX_DEFAULT
        closemessage

        msgbox SilphCo_4F_Frlg_Text_MistyWhyElias, MSGBOX_DEFAULT
        closemessage

        goto SilphCo_4F_Frlg_EventScript_MistyShared


@ =============================================================================
@ SHARED END
@ =============================================================================

SilphCo_4F_Frlg_EventScript_MistyShared:
        msgbox SilphCo_4F_Frlg_Text_PlayerYouKnowThem, MSGBOX_DEFAULT
        closemessage

        msgbox SilphCo_4F_Frlg_Text_MistyObviously, MSGBOX_DEFAULT
        closemessage

        msgbox SilphCo_4F_Frlg_Text_PlayerHow, MSGBOX_DEFAULT
        closemessage

        msgbox SilphCo_4F_Frlg_Text_MistyLongStory, MSGBOX_DEFAULT
        closemessage

        delay 10

        msgbox SilphCo_4F_Frlg_Text_MistyActuallyWho, MSGBOX_DEFAULT
        closemessage

        msgbox SilphCo_4F_Frlg_Text_PlayerAlreadyTried, MSGBOX_DEFAULT
        closemessage

        msgbox SilphCo_4F_Frlg_Text_MistyTriedWhat, MSGBOX_DEFAULT
        closemessage

        msgbox SilphCo_4F_Frlg_Text_PlayerUnderstanding, MSGBOX_DEFAULT
        closemessage

        msgbox SilphCo_4F_Frlg_Text_MistyInteresting, MSGBOX_DEFAULT
        closemessage

        msgbox SilphCo_4F_Frlg_Text_PlayerPleaseDont, MSGBOX_DEFAULT
        closemessage

        msgbox SilphCo_4F_Frlg_Text_MistyUpstairs, MSGBOX_DEFAULT
        closemessage

        release
        end


SilphCo_4F_Frlg_EventScript_MistyRepeat:
        msgbox SilphCo_4F_Frlg_Text_MistyRepeat, MSGBOX_DEFAULT
        closemessage

        release
        end


@ =============================================================================
@ RECOGNITION
@ =============================================================================

SilphCo_4F_Frlg_Text_PlayerMisty:
        .string "{PLAYER}: Misty?$"


SilphCo_4F_Frlg_Text_MistyKnowYou:
        .string "MISTY: ...Do I know you?$"


SilphCo_4F_Frlg_Text_PlayerComeOn:
        .string "{PLAYER}: Oh, come on.$"


SilphCo_4F_Frlg_Text_MistyNotAnswer:
        .string "MISTY: That's generally not\n"
        .string "an answer.$"


SilphCo_4F_Frlg_Text_PlayerGettingThat:
        .string "{PLAYER}: I've been getting that\n"
        .string "a lot today.$"


SilphCo_4F_Frlg_Text_MistyGettingWhat:
        .string "MISTY: Getting what?$"


SilphCo_4F_Frlg_Text_PlayerGiveUp:
        .string "{PLAYER}: Never mind.\p"
        .string "I think I'm officially giving up\n"
        .string "on making sense of any of this.$"


SilphCo_4F_Frlg_Text_MistySmart:
        .string "MISTY: Smart.$"


SilphCo_4F_Frlg_Text_PlayerNotCompliment:
        .string "{PLAYER}: Somehow I don't think\n"
        .string "you mean that as a compliment.$"


SilphCo_4F_Frlg_Text_MistyWasnt:
        .string "MISTY: I don't.$"


@ =============================================================================
@ TIA PATH
@ =============================================================================

SilphCo_4F_Frlg_Text_MistyTiaRant1:
        .string "MISTY: Anyway...\p"
        .string "Tia can spare me the whole\n"
        .string "Bookkeeper routine.$"


SilphCo_4F_Frlg_Text_MistyTiaRant2:
        .string "MISTY: Writing everything down\n"
        .string "doesn't suddenly mean she gets\n"
        .string "to decide what everybody does.$"


SilphCo_4F_Frlg_Text_PlayerTia:
        .string "{PLAYER}: ...Tia?$"


SilphCo_4F_Frlg_Text_MistyWhyTia:
        .string "MISTY: ...Why'd you say her name\n"
        .string "like that?$"


@ =============================================================================
@ ELIAS PATH
@ =============================================================================

SilphCo_4F_Frlg_Text_MistyEliasRant1:
        .string "MISTY: Anyway...\p"
        .string "Elias has the Key.\n"
        .string "Wonderful.$"


SilphCo_4F_Frlg_Text_MistyEliasRant2:
        .string "MISTY: Apparently possessing a key\n"
        .string "makes him the authority on every\n"
        .string "door in existence.$"


SilphCo_4F_Frlg_Text_PlayerElias:
        .string "{PLAYER}: ...Elias?$"


SilphCo_4F_Frlg_Text_MistyWhyElias:
        .string "MISTY: ...Why'd you say his name\n"
        .string "like that?$"


@ =============================================================================
@ SHARED END TEXT
@ =============================================================================

SilphCo_4F_Frlg_Text_PlayerYouKnowThem:
        .string "{PLAYER}: You know them?$"


SilphCo_4F_Frlg_Text_MistyObviously:
        .string "MISTY: Obviously.$"


SilphCo_4F_Frlg_Text_PlayerHow:
        .string "{PLAYER}: How?$"


SilphCo_4F_Frlg_Text_MistyLongStory:
        .string "MISTY: That's a long story.\p"
        .string "And I'm already annoyed with\n"
        .string "most of the people in it.$"


SilphCo_4F_Frlg_Text_MistyActuallyWho:
        .string "MISTY: Actually...\p"
        .string "Who ARE you?$"


SilphCo_4F_Frlg_Text_PlayerAlreadyTried:
        .string "{PLAYER}: I already tried figuring\n"
        .string "that out today.$"


SilphCo_4F_Frlg_Text_MistyTriedWhat:
        .string "MISTY: Figuring out who you are?$"


SilphCo_4F_Frlg_Text_PlayerUnderstanding:
        .string "{PLAYER}: Understanding literally\n"
        .string "anything that's happening.$"


SilphCo_4F_Frlg_Text_MistyInteresting:
        .string "MISTY: ...Interesting.$"


SilphCo_4F_Frlg_Text_PlayerPleaseDont:
        .string "{PLAYER}: Please don't start doing\n"
        .string "the mysterious thing too.$"


SilphCo_4F_Frlg_Text_MistyUpstairs:
        .string "MISTY: Fine.\p"
        .string "Go upstairs.\p"
        .string "Maybe he'll give you a straight\n"
        .string "answer.$"


SilphCo_4F_Frlg_Text_MistyRepeat:
        .string "MISTY: Still here?\p"
        .string "Go bother the guy upstairs.\p"
        .string "I've got enough people irritating\n"
        .string "me already.$"

@ =============================================================================
@ OPTIONAL ENVIRONMENTAL LORE
@ =============================================================================

SilphCo_4F_Frlg_EventScript_CrumpledMemo::
        msgbox SilphCo_4F_Frlg_Text_CrumpledMemo, MSGBOX_SIGN
        end

SilphCo_4F_Frlg_Text_CrumpledMemo:
        .string "A crumpled staff memo reads:\p"
        .string "DO NOT DISCUSS DISAGREEMENTS\p"
        .string "BETWEEN APPOINTED MEMBERS.\p"
        .string "Someone wrote underneath:\p"
        .string "THEN STOP ARGUING\p"
        .string "IN THE HALLWAY.\p"
        .string "{PLAYER}: ...Fair.$"
