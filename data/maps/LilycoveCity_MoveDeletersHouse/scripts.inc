# 1 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"

# 2 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
LilycoveCity_MoveDeletersHouse_MapScripts::
# 3 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	.byte 0
# 4 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"

# 5 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
LilycoveCity_MoveDeletersHouse_EventScript_MoveDeleter::
# 6 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	lockall
# 7 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	applymovement LOCALID_MOVE_DELETER, Common_Movement_FacePlayer
# 8 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	waitmovement 0
# 9 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	msgbox LilycoveCity_MoveDeletersHouse_Text_ICanMakeMonForgetMove, MSGBOX_YESNO
# 10 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	switch VAR_RESULT
# 11 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	case YES, LilycoveCity_MoveDeletersHouse_EventScript_ChooseMonAndMoveToForget
# 12 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	case NO, LilycoveCity_MoveDeletersHouse_EventScript_ComeAgain
# 13 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	releaseall
# 14 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	end
# 15 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"

# 16 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
LilycoveCity_MoveDeletersHouse_EventScript_ChooseMonAndMoveToForget::
# 17 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	msgbox LilycoveCity_MoveDeletersHouse_Text_WhichMonShouldForget, MSGBOX_DEFAULT
# 18 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	special ChoosePartyMon
# 19 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	waitstate
# 20 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, LilycoveCity_MoveDeletersHouse_EventScript_ComeAgain
# 21 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	special IsSelectedMonEgg
# 22 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, LilycoveCity_MoveDeletersHouse_EventScript_EggCantForgetMoves
# 23 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	special GetNumMovesSelectedMonHas
# 24 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	goto_if_eq VAR_RESULT, 1, LilycoveCity_MoveDeletersHouse_EventScript_MonOnlyKnowsOneMove
# 25 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	msgbox LilycoveCity_MoveDeletersHouse_Text_WhichMoveShouldBeForgotten, MSGBOX_DEFAULT
# 26 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	fadescreen FADE_TO_BLACK
# 27 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	special MoveDeleterChooseMoveToForget
# 28 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	fadescreen FADE_FROM_BLACK
# 29 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	goto_if_eq VAR_0x8005, MAX_MON_MOVES, LilycoveCity_MoveDeletersHouse_EventScript_ChooseMonAndMoveToForget
# 30 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	special BufferMoveDeleterNicknameAndMove
# 31 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	msgbox LilycoveCity_MoveDeletersHouse_Text_MonsMoveShouldBeForgotten, MSGBOX_YESNO
# 32 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	switch VAR_RESULT
# 33 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	case YES, LilycoveCity_MoveDeletersHouse_EventScript_TryForgetMove
# 34 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	case NO, LilycoveCity_MoveDeletersHouse_EventScript_ComeAgain
# 35 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	releaseall
# 36 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	end
# 37 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"

# 38 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
LilycoveCity_MoveDeletersHouse_EventScript_TryForgetMove::
# 39 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	special IsLastMonThatKnowsSurf
# 40 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, LilycoveCity_MoveDeletersHouse_EventScript_LastMonWithSurf
# 41 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	special MoveDeleterForgetMove
# 42 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	playfanfare MUS_MOVE_DELETED
# 43 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	waitfanfare
# 44 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	msgbox LilycoveCity_MoveDeletersHouse_Text_MonHasForgottenMove, MSGBOX_DEFAULT
# 45 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	releaseall
# 46 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	end
# 47 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"

# 48 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
LilycoveCity_MoveDeletersHouse_EventScript_MonOnlyKnowsOneMove::
# 49 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	special BufferMoveDeleterNicknameAndMove
# 50 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	msgbox LilycoveCity_MoveDeletersHouse_Text_MonOnlyKnowsOneMove, MSGBOX_DEFAULT
# 51 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	releaseall
# 52 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	end
# 53 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"

# 54 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
LilycoveCity_MoveDeletersHouse_EventScript_EggCantForgetMoves::
# 55 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	msgbox LilycoveCity_MoveDeletersHouse_Text_EggCantForgetMoves, MSGBOX_DEFAULT
# 56 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	releaseall
# 57 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	end
# 58 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"

# 59 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
LilycoveCity_MoveDeletersHouse_EventScript_ComeAgain::
# 60 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	msgbox LilycoveCity_MoveDeletersHouse_Text_ComeAgain, MSGBOX_DEFAULT
# 61 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	releaseall
# 62 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	end
# 63 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"

# 64 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
LilycoveCity_MoveDeletersHouse_EventScript_LastMonWithSurf::
# 65 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	special BufferMoveDeleterNicknameAndMove
# 66 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	msgbox LilycoveCity_MoveDeletersHouse_Text_CantForgetSurf, MSGBOX_DEFAULT
# 67 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	releaseall
# 68 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	end
# 69 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"

# 70 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
LilycoveCity_MoveDeletersHouse_Text_ICanMakeMonForgetMove:
# 71 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	.string "Uh…\n"
# 72 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	.string "Oh, yes, I'm the MOVE DELETER.\p"
# 73 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	.string "I can make POKéMON forget their moves.\p"
# 74 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	.string "Would you like me to do that?$"
# 75 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"

# 76 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
LilycoveCity_MoveDeletersHouse_Text_WhichMonShouldForget:
# 77 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	.string "Which POKéMON should forget a move?$"
# 78 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"

# 79 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
LilycoveCity_MoveDeletersHouse_Text_WhichMoveShouldBeForgotten:
# 80 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	.string "Which move should be forgotten?$"
# 81 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"

# 82 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
LilycoveCity_MoveDeletersHouse_Text_MonOnlyKnowsOneMove:
# 83 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	.string "{STR_VAR_1} knows only one move\n"
# 84 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	.string "so it can't be forgotten…$"
# 85 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"

# 86 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
LilycoveCity_MoveDeletersHouse_Text_MonsMoveShouldBeForgotten:
# 87 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	.string "Hm! {STR_VAR_1}'s {STR_VAR_2}?\n"
# 88 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	.string "That move should be forgotten?$"
# 89 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"

# 90 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
LilycoveCity_MoveDeletersHouse_Text_MonHasForgottenMove:
# 91 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	.string "It worked to perfection!\p"
# 92 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	.string "{STR_VAR_1} has forgotten\n"
# 93 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	.string "{STR_VAR_2} completely.$"
# 94 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"

# 95 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
LilycoveCity_MoveDeletersHouse_Text_ComeAgain:
# 96 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	.string "Come again if there are moves that\n"
# 97 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	.string "need to be forgotten.$"
# 98 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"

# 99 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
LilycoveCity_MoveDeletersHouse_Text_EggCantForgetMoves:
# 100 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	.string "What?\n"
# 101 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	.string "No EGG should know any moves.$"
# 102 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"

# 103 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
LilycoveCity_MoveDeletersHouse_Text_CantForgetSurf:
# 104 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	.string "Hm!\p"
# 105 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	.string "Your {STR_VAR_1} doesn't seem willing\n"
# 106 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	.string "to forget SURF.$"
