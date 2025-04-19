# 1 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"

# 2 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
.set LOCALID_MOVE_DELETER, 1
# 3 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"

# 4 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
LilycoveCity_MoveDeletersHouse_MapScripts::
# 5 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	.byte 0
# 6 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"

# 7 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
LilycoveCity_MoveDeletersHouse_EventScript_MoveDeleter::
# 8 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	lockall
# 9 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	applymovement LOCALID_MOVE_DELETER, Common_Movement_FacePlayer
# 10 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	waitmovement 0
# 11 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	msgbox LilycoveCity_MoveDeletersHouse_Text_ICanMakeMonForgetMove, MSGBOX_YESNO
# 12 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	switch VAR_RESULT
# 13 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	case YES, LilycoveCity_MoveDeletersHouse_EventScript_ChooseMonAndMoveToForget
# 14 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	case NO, LilycoveCity_MoveDeletersHouse_EventScript_ComeAgain
# 15 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	releaseall
# 16 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	end
# 17 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"

# 18 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
LilycoveCity_MoveDeletersHouse_EventScript_ChooseMonAndMoveToForget::
# 19 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	msgbox LilycoveCity_MoveDeletersHouse_Text_WhichMonShouldForget, MSGBOX_DEFAULT
# 20 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	special ChoosePartyMon
# 21 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	waitstate
# 22 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, LilycoveCity_MoveDeletersHouse_EventScript_ComeAgain
# 23 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	special IsSelectedMonEgg
# 24 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, LilycoveCity_MoveDeletersHouse_EventScript_EggCantForgetMoves
# 25 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	special GetNumMovesSelectedMonHas
# 26 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	goto_if_eq VAR_RESULT, 1, LilycoveCity_MoveDeletersHouse_EventScript_MonOnlyKnowsOneMove
# 27 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	msgbox LilycoveCity_MoveDeletersHouse_Text_WhichMoveShouldBeForgotten, MSGBOX_DEFAULT
# 28 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	fadescreen FADE_TO_BLACK
# 29 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	special MoveDeleterChooseMoveToForget
# 30 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	fadescreen FADE_FROM_BLACK
# 31 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	goto_if_eq VAR_0x8005, MAX_MON_MOVES, LilycoveCity_MoveDeletersHouse_EventScript_ChooseMonAndMoveToForget
# 32 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	special BufferMoveDeleterNicknameAndMove
# 33 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	msgbox LilycoveCity_MoveDeletersHouse_Text_MonsMoveShouldBeForgotten, MSGBOX_YESNO
# 34 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	switch VAR_RESULT
# 35 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	case YES, LilycoveCity_MoveDeletersHouse_EventScript_TryForgetMove
# 36 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	case NO, LilycoveCity_MoveDeletersHouse_EventScript_ComeAgain
# 37 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	releaseall
# 38 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	end
# 39 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"

# 40 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
LilycoveCity_MoveDeletersHouse_EventScript_TryForgetMove::
# 41 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	special IsLastMonThatKnowsSurf
# 42 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, LilycoveCity_MoveDeletersHouse_EventScript_LastMonWithSurf
# 43 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	special MoveDeleterForgetMove
# 44 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	playfanfare MUS_MOVE_DELETED
# 45 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	waitfanfare
# 46 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	msgbox LilycoveCity_MoveDeletersHouse_Text_MonHasForgottenMove, MSGBOX_DEFAULT
# 47 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	releaseall
# 48 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	end
# 49 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"

# 50 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
LilycoveCity_MoveDeletersHouse_EventScript_MonOnlyKnowsOneMove::
# 51 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	special BufferMoveDeleterNicknameAndMove
# 52 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	msgbox LilycoveCity_MoveDeletersHouse_Text_MonOnlyKnowsOneMove, MSGBOX_DEFAULT
# 53 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	releaseall
# 54 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	end
# 55 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"

# 56 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
LilycoveCity_MoveDeletersHouse_EventScript_EggCantForgetMoves::
# 57 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	msgbox LilycoveCity_MoveDeletersHouse_Text_EggCantForgetMoves, MSGBOX_DEFAULT
# 58 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	releaseall
# 59 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	end
# 60 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"

# 61 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
LilycoveCity_MoveDeletersHouse_EventScript_ComeAgain::
# 62 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	msgbox LilycoveCity_MoveDeletersHouse_Text_ComeAgain, MSGBOX_DEFAULT
# 63 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	releaseall
# 64 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	end
# 65 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"

# 66 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
LilycoveCity_MoveDeletersHouse_EventScript_LastMonWithSurf::
# 67 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	special BufferMoveDeleterNicknameAndMove
# 68 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	msgbox LilycoveCity_MoveDeletersHouse_Text_CantForgetSurf, MSGBOX_DEFAULT
# 69 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	releaseall
# 70 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	end
# 71 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"

# 72 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
LilycoveCity_MoveDeletersHouse_Text_ICanMakeMonForgetMove:
# 73 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	.string "Uh…\n"
# 74 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	.string "Oh, yes, I'm the MOVE DELETER.\p"
# 75 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	.string "I can make POKéMON forget their moves.\p"
# 76 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	.string "Would you like me to do that?$"
# 77 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"

# 78 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
LilycoveCity_MoveDeletersHouse_Text_WhichMonShouldForget:
# 79 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	.string "Which POKéMON should forget a move?$"
# 80 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"

# 81 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
LilycoveCity_MoveDeletersHouse_Text_WhichMoveShouldBeForgotten:
# 82 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	.string "Which move should be forgotten?$"
# 83 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"

# 84 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
LilycoveCity_MoveDeletersHouse_Text_MonOnlyKnowsOneMove:
# 85 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	.string "{STR_VAR_1} knows only one move\n"
# 86 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	.string "so it can't be forgotten…$"
# 87 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"

# 88 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
LilycoveCity_MoveDeletersHouse_Text_MonsMoveShouldBeForgotten:
# 89 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	.string "Hm! {STR_VAR_1}'s {STR_VAR_2}?\n"
# 90 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	.string "That move should be forgotten?$"
# 91 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"

# 92 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
LilycoveCity_MoveDeletersHouse_Text_MonHasForgottenMove:
# 93 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	.string "It worked to perfection!\p"
# 94 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	.string "{STR_VAR_1} has forgotten\n"
# 95 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	.string "{STR_VAR_2} completely.$"
# 96 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"

# 97 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
LilycoveCity_MoveDeletersHouse_Text_ComeAgain:
# 98 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	.string "Come again if there are moves that\n"
# 99 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	.string "need to be forgotten.$"
# 100 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"

# 101 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
LilycoveCity_MoveDeletersHouse_Text_EggCantForgetMoves:
# 102 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	.string "What?\n"
# 103 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	.string "No EGG should know any moves.$"
# 104 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"

# 105 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
LilycoveCity_MoveDeletersHouse_Text_CantForgetSurf:
# 106 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	.string "Hm!\p"
# 107 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	.string "Your {STR_VAR_1} doesn't seem willing\n"
# 108 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	.string "to forget SURF.$"
