BugContest_EventScript_Start::
	end

BugContest_EventScript_WhiteOut::
	lockall
	delay 200
	msgbox BugContest_Text_WhiteOut, MSGBOX_DEFAULT
	closemessage
	goto BugContest_EventScript_End
	end

BugContest_EventScript_TimesUp::
	lockall
	playse SE_DING_DONG
	msgbox BugContest_Text_TimesUp, MSGBOX_DEFAULT
	closemessage
	waitse
	getpartysize
	goto_if_eq VAR_RESULT, 1, BugContest_EventScript_Didntcatch
	fadescreen FADE_TO_BLACK
	setvar VAR_BUG_CONTEST_STATE, 3

	msgbox BugContest_Text_Judging0, MSGBOX_DEFAULT
	closemessage
	BugContest_EventScript_TimesUp2::
	special ChoosePartyMon
	waitstate
	copyvar VAR_0x800A, VAR_0x8004
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, BugContest_EventScript_WrongChoiceMon
	goto_if_eq VAR_0x8004, 0, BugContest_EventScript_WrongChoiceMon
	fadescreen FADE_TO_BLACK
	warp MAP_NATIONAL_PARK_BUG_CONTEST_HNS, 5
	delay 90
	end

BugContest_EventScript_WrongChoiceMon::
	msgbox BugContest_Text_WrongChoiceMon, MSGBOX_DEFAULT
	goto BugContest_EventScript_TimesUp2
	end

BugContestEventScript_Judging::
	msgbox BugContest_Text_Judging1, MSGBOX_DEFAULT
	closemessage
	special JudgeBugContestMon
	call_if_eq VAR_RESULT, 1, BugContest_EventScript_First
	call_if_eq VAR_RESULT, 2, BugContest_EventScript_Second
	call_if_eq VAR_RESULT, 3, BugContest_EventScript_Third
	special TransferBugContestMon
	delay 20
	giveitem VAR_0x8005
	msgbox BugContest_Text_TransferAndReturn, MSGBOX_DEFAULT
	playse SE_SUCCESS
	waitse
	msgbox BugContest_Text_TakePartInFuture, MSGBOX_DEFAULT
	closemessage
	goto BugContest_EventScript_End
	end

BugContest_EventScript_Didntcatch::
	msgbox BugContest_Text_DidntCatch, MSGBOX_DEFAULT
	playse SE_SUCCESS
	closemessage
	fadescreen FADE_TO_BLACK
	goto BugContest_EventScript_End
	end

BugContest_EventScript_First::
	msgbox BugContest_Text_First1, MSGBOX_DEFAULT
	playfanfare MUS_OBTAIN_BERRY
	waitfanfare
	msgbox BugContest_Text_First2, MSGBOX_DEFAULT
	playfanfare MUS_OBTAIN_BERRY
	waitfanfare
	msgbox BugContest_Text_First3, MSGBOX_DEFAULT
	playfanfare MUS_OBTAIN_BADGE
	waitfanfare
	closemessage
	return

BugContest_EventScript_Second::
	msgbox BugContest_Text_Second1, MSGBOX_DEFAULT
	playfanfare MUS_OBTAIN_BERRY
	waitfanfare
	msgbox BugContest_Text_Second2, MSGBOX_DEFAULT
	playfanfare MUS_OBTAIN_BERRY
	waitfanfare
	msgbox BugContest_Text_Second3, MSGBOX_DEFAULT
	playfanfare MUS_OBTAIN_BADGE
	waitfanfare
	closemessage
	return

BugContest_EventScript_Third::
	msgbox BugContest_Text_Third1, MSGBOX_DEFAULT
	playfanfare MUS_OBTAIN_BERRY
	waitfanfare
	msgbox BugContest_Text_Third2, MSGBOX_DEFAULT
	playfanfare MUS_OBTAIN_BERRY
	waitfanfare
	msgbox BugContest_Text_Third3, MSGBOX_DEFAULT
	playfanfare MUS_OBTAIN_BADGE
	waitfanfare
	closemessage
	return

BugContest_EventScript_End::
	special HealPlayerParty
	special LoadPlayerParty
	special ExitBugContestMode
	setvar VAR_BUG_CONTEST_STATE, 0
	special RemoveSafariBalls
	goto_if_eq VAR_TEMP_1, 1, BugContest_EventScript_SideEnd
	warp MAP_GATE_NATIONAL_PARK_HNS, 7, 2
	releaseall
	end

BugContest_EventScript_SideEnd::
	warp MAP_GATE_NATIONAL_PARK_HNS, 35, 7
	releaseall
	end

BugContest_Text_Judging0::
	.string "The contest has now concluded.\n"
	.string "Please pick the POKéMON you would\l"
	.string "like to keep and have judged.$"

BugContest_Text_Judging1::
	.string "We will now judge the POKéMON\n"
	.string "you've caught.\p"
	.string "...................\n"
	.string "...................\p"
	.string "We have chosen the winners! Are\n"
	.string "ready for this?$"

BugContest_Text_WrongChoiceMon:
	.string "Please pick the POKéMON you would\n"
	.string "like to keep and have judged.$"

BugContest_Text_DidntCatch:
	.string "Oh no! You didn't catch a POKéMON.\n"
	.string "You've forfeited the competition.\p"
	.string "Your party will now be returned.$"

BugContest_Text_TimesUp:
	.string "Ding-dong! Time's up!$"

BugContest_Text_WhiteOut:
	.string "{PLAYER} is out of useable POKéMON.\n"
	.string "{PLAYER} forfeited the contest.$"

BugContest_Text_First1:
	.string "Placing third is the COOLTRAINER\n"
	.string "BELINDA, who caught a wriggling\l"
	.string "BUTTERFREE!$"
BugContest_Text_First2:
	.string "Placing second is the BUGCATCHER\n"
	.string "SHAUN, who caught a writhing\l"
	.string "PINSIR!$"
BugContest_Text_First3:
	.string "This Bug-Catching Contest Winner\n"
	.string "is...\p"
	.string "{PLAYER}, who caught a whopping\n"
	.string "{STR_VAR_1}!$"

BugContest_Text_Second1:
	.string "Placing second is the COOLTRAINER\n"
	.string "BELINDA, who caught a wriggling\l"
	.string "BUTTERFREE!$"
BugContest_Text_Second2:
	.string "Placing second is {PLAYER}, who\n"
	.string "caught a writhing {STR_VAR_1}!$"
BugContest_Text_Second3:
	.string "This Bug-Catching Contest Winner\n"
	.string "is...\p"
	.string "BUGCATCHER SHAUN, who caught a\n"
	.string "whopping PINSIR!$"

BugContest_Text_Third1:
	.string "Placing third is {PLAYER}, who\n"
	.string "caught a wriggling {STR_VAR_1}!$"
BugContest_Text_Third2:
	.string "Placing second is the COOLTRAINER\n"
	.string "BELINDA, who caught a writhing\l"
	.string "BUTTERFREE!$"
BugContest_Text_Third3:
	.string "This Bug-Catching Contest Winner\n"
	.string "is...\p"
	.string "BUGCATCHER SHAUN, who caught a\n"
	.string "whopping PINSIR!$"

BugContest_Text_TakePartInFuture:
	.string "Thank you for participating!\n"
	.string "We hope you'll take part in the\l"
	.string "future.$"

BugContest_Text_TransferAndReturn:
	.string "Your chosen BUG POKéMON will now\n"
	.string "be sent to the PC and your party\l"
	.string "will be returned to you.$"
