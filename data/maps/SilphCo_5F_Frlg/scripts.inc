SilphCo_5F_Frlg_MapScripts::
        .byte 0


@ =============================================================================
@ SILPH CO. 5F - GIOVANNI
@ =============================================================================

SilphCo_5F_Frlg_EventScript_Giovanni::
        lock
        faceplayer

        goto_if_set FLAG_SILPH_GIOVANNI_MET, SilphCo_5F_Frlg_EventScript_GiovanniRepeat

        setflag FLAG_SILPH_GIOVANNI_MET

        msgbox SilphCo_5F_Frlg_Text_PlayerGuyUpstairs, MSGBOX_DEFAULT
        closemessage

        msgbox SilphCo_5F_Frlg_Text_GiovanniApparently, MSGBOX_DEFAULT
        closemessage

        msgbox SilphCo_5F_Frlg_Text_PlayerMistySaid, MSGBOX_DEFAULT
        closemessage

        msgbox SilphCo_5F_Frlg_Text_GiovanniDepends, MSGBOX_DEFAULT
        closemessage

        msgbox SilphCo_5F_Frlg_Text_PlayerWhoAreYou, MSGBOX_DEFAULT
        closemessage

        msgbox SilphCo_5F_Frlg_Text_GiovanniName, MSGBOX_DEFAULT
        closemessage

        msgbox SilphCo_5F_Frlg_Text_PlayerOkayGiovanni, MSGBOX_DEFAULT
        closemessage

        msgbox SilphCo_5F_Frlg_Text_GiovanniSilph, MSGBOX_DEFAULT
        closemessage

        msgbox SilphCo_5F_Frlg_Text_PlayerPermission, MSGBOX_DEFAULT
        closemessage

        msgbox SilphCo_5F_Frlg_Text_GiovanniAct, MSGBOX_DEFAULT
        closemessage

        msgbox SilphCo_5F_Frlg_Text_PlayerLorelei, MSGBOX_DEFAULT
        closemessage

        msgbox SilphCo_5F_Frlg_Text_GiovanniLorelei, MSGBOX_DEFAULT
        closemessage

        msgbox SilphCo_5F_Frlg_Text_PlayerTwelve, MSGBOX_DEFAULT
        closemessage

        msgbox SilphCo_5F_Frlg_Text_GiovanniTwelveControl, MSGBOX_DEFAULT
        closemessage

        msgbox SilphCo_5F_Frlg_Text_PlayerSixRight, MSGBOX_DEFAULT
        closemessage

        msgbox SilphCo_5F_Frlg_Text_GiovanniDidntSay, MSGBOX_DEFAULT
        closemessage

        msgbox SilphCo_5F_Frlg_Text_PlayerEveryoneDoesThat, MSGBOX_DEFAULT
        closemessage

        msgbox SilphCo_5F_Frlg_Text_GiovanniLearning, MSGBOX_DEFAULT
        closemessage

        msgbox SilphCo_5F_Frlg_Text_PlayerWhoShouldDecide, MSGBOX_DEFAULT
        closemessage

        msgbox SilphCo_5F_Frlg_Text_GiovanniWhoActs, MSGBOX_DEFAULT
        closemessage

        delay 10

        msgbox SilphCo_5F_Frlg_Text_PlayerThatSoundsDangerous, MSGBOX_DEFAULT
        closemessage

        msgbox SilphCo_5F_Frlg_Text_GiovanniSoDoesWaiting, MSGBOX_DEFAULT
        closemessage

        msgbox SilphCo_5F_Frlg_Text_PlayerAreYouSix, MSGBOX_DEFAULT
        closemessage

        msgbox SilphCo_5F_Frlg_Text_GiovanniNotAnswering, MSGBOX_DEFAULT
        closemessage

        msgbox SilphCo_5F_Frlg_Text_PlayerFigures, MSGBOX_DEFAULT
        closemessage

        msgbox SilphCo_5F_Frlg_Text_GiovanniUpperFloors, MSGBOX_DEFAULT
        closemessage

        msgbox SilphCo_5F_Frlg_Text_PlayerHowUpstairs, MSGBOX_DEFAULT
        closemessage

        msgbox SilphCo_5F_Frlg_Text_GiovanniYoullKnow, MSGBOX_DEFAULT
        closemessage

        msgbox SilphCo_5F_Frlg_Text_PlayerVague, MSGBOX_DEFAULT
        closemessage

        msgbox SilphCo_5F_Frlg_Text_GiovanniHabits, MSGBOX_DEFAULT
        closemessage

        release
        end


SilphCo_5F_Frlg_EventScript_GiovanniRepeat:
        msgbox SilphCo_5F_Frlg_Text_GiovanniRepeat, MSGBOX_DEFAULT
        closemessage

        release
        end


@ =============================================================================
@ TEXT
@ =============================================================================

SilphCo_5F_Frlg_Text_PlayerGuyUpstairs:
        .string "{PLAYER}: Let me guess.\p"
        .string "You're the guy upstairs.$"


SilphCo_5F_Frlg_Text_GiovanniApparently:
        .string "???: Apparently.$"


SilphCo_5F_Frlg_Text_PlayerMistySaid:
        .string "{PLAYER}: Misty said you might\n"
        .string "actually answer a question.$"


SilphCo_5F_Frlg_Text_GiovanniDepends:
        .string "???: That depends entirely on\n"
        .string "the question.$"


SilphCo_5F_Frlg_Text_PlayerWhoAreYou:
        .string "{PLAYER}: Who are you?$"


SilphCo_5F_Frlg_Text_GiovanniName:
        .string "GIOVANNI: Giovanni.$"


SilphCo_5F_Frlg_Text_PlayerOkayGiovanni:
        .string "{PLAYER}: Okay, Giovanni.\p"
        .string "What happened here?$"


SilphCo_5F_Frlg_Text_GiovanniSilph:
        .string "GIOVANNI: Silph was built on\n"
        .string "cooperation.\p"
        .string "Cooperation is useful...\p"
        .string "until it becomes permission.$"


SilphCo_5F_Frlg_Text_PlayerPermission:
        .string "{PLAYER}: Permission for what?$"


SilphCo_5F_Frlg_Text_GiovanniAct:
        .string "GIOVANNI: To act.$"


SilphCo_5F_Frlg_Text_PlayerLorelei:
        .string "{PLAYER}: Lorelei said twelve\n"
        .string "people built a lot of this.$"


SilphCo_5F_Frlg_Text_GiovanniLorelei:
        .string "GIOVANNI: Lorelei talks too\n"
        .string "much when she's trying not\p"
        .string "to say anything.$"


SilphCo_5F_Frlg_Text_PlayerTwelve:
        .string "{PLAYER}: So what's your version?$"


SilphCo_5F_Frlg_Text_GiovanniTwelveControl:
        .string "GIOVANNI: Twelve people were\n"
        .string "entrusted with things no\p"
        .string "small group should control.$"


SilphCo_5F_Frlg_Text_PlayerSixRight:
        .string "{PLAYER}: So the Six were right?$"


SilphCo_5F_Frlg_Text_GiovanniDidntSay:
        .string "GIOVANNI: I didn't say that.$"


SilphCo_5F_Frlg_Text_PlayerEveryoneDoesThat:
        .string "{PLAYER}: Everybody here does that.$"


SilphCo_5F_Frlg_Text_GiovanniLearning:
        .string "GIOVANNI: Does what?$"


SilphCo_5F_Frlg_Text_PlayerWhoShouldDecide:
        .string "{PLAYER}: Answers questions without\n"
        .string "answering them.\p"
        .string "If twelve people shouldn't decide,\n"
        .string "who should?$"


SilphCo_5F_Frlg_Text_GiovanniWhoActs:
        .string "GIOVANNI: Whoever is willing to act.$"


SilphCo_5F_Frlg_Text_PlayerThatSoundsDangerous:
        .string "{PLAYER}: That sounds dangerous.$"


SilphCo_5F_Frlg_Text_GiovanniSoDoesWaiting:
        .string "GIOVANNI: So does waiting.$"


SilphCo_5F_Frlg_Text_PlayerAreYouSix:
        .string "{PLAYER}: Are you one of the Six?$"


SilphCo_5F_Frlg_Text_GiovanniNotAnswering:
        .string "GIOVANNI: Now you're asking a\n"
        .string "better question.$"


SilphCo_5F_Frlg_Text_PlayerFigures:
        .string "{PLAYER}: ...That's not an answer.$"


SilphCo_5F_Frlg_Text_GiovanniRepeat:
        .string "GIOVANNI: Still looking for answers?\p"
        .string "Be careful.\p"
        .string "Most people prefer answers that\n"
        .string "agree with what they already believe.$"

@ =============================================================================
@ OPTIONAL ENVIRONMENTAL LORE
@ =============================================================================

SilphCo_5F_Frlg_EventScript_ActionProposal::
        msgbox SilphCo_5F_Frlg_Text_ActionProposal, MSGBOX_SIGN
        end

SilphCo_5F_Frlg_EventScript_MarginNote::
        msgbox SilphCo_5F_Frlg_Text_MarginNote, MSGBOX_SIGN
        end

SilphCo_5F_Frlg_Text_ActionProposal:
        .string "A proposal has been left here.\p"
        .string "INDEPENDENT ACTION WITHOUT\p"
        .string "UNANIMOUS AUTHORIZATION:\p"
        .string "PROHIBITED.$"

SilphCo_5F_Frlg_Text_MarginNote:
        .string "A note fills the margin:\p"
        .string "THEN NOTHING WILL EVER CHANGE.\p"
        .string "There is no signature.$"


SilphCo_5F_Frlg_Text_GiovanniUpperFloors:
        .string "GIOVANNI: Perhaps I'll give you\p"
        .string "more of the answer you want\p"
        .string "when you can reach beyond 5F.$"


SilphCo_5F_Frlg_Text_PlayerHowUpstairs:
        .string "{PLAYER}: And how do I do that?$"


SilphCo_5F_Frlg_Text_GiovanniYoullKnow:
        .string "GIOVANNI: You'll know when\n"
        .string "you're able.$"


SilphCo_5F_Frlg_Text_PlayerVague:
        .string "{PLAYER}: That's vague even\n"
        .string "for you.$"


SilphCo_5F_Frlg_Text_GiovanniHabits:
        .string "GIOVANNI: Then you're learning\n"
        .string "my habits.$"
