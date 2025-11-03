# 1 "data/maps/FortreeCity_House2/scripts.pory"

# 2 "data/maps/FortreeCity_House2/scripts.pory"
FortreeCity_House2_MapScripts::
# 3 "data/maps/FortreeCity_House2/scripts.pory"
	.byte 0
# 4 "data/maps/FortreeCity_House2/scripts.pory"

# 5 "data/maps/FortreeCity_House2/scripts.pory"
FortreeCity_House2_EventScript_HiddenPowerGiver::
# 6 "data/maps/FortreeCity_House2/scripts.pory"
	lock
# 7 "data/maps/FortreeCity_House2/scripts.pory"
	faceplayer
# 8 "data/maps/FortreeCity_House2/scripts.pory"
	goto_if_set FLAG_RECEIVED_TM_HIDDEN_POWER, FortreeCity_House2_EventScript_ExplainHiddenPower
# 9 "data/maps/FortreeCity_House2/scripts.pory"
	call_if_unset FLAG_MET_HIDDEN_POWER_GIVER, FortreeCity_House2_EventScript_Greeting
# 10 "data/maps/FortreeCity_House2/scripts.pory"
	msgbox FortreeCity_House2_Text_CoinInWhichHand, MSGBOX_DEFAULT
# 11 "data/maps/FortreeCity_House2/scripts.pory"
	multichoice 21, 8, MULTI_RIGHTLEFT, TRUE
# 12 "data/maps/FortreeCity_House2/scripts.pory"
	switch VAR_RESULT
# 13 "data/maps/FortreeCity_House2/scripts.pory"
	case 1, FortreeCity_House2_EventScript_WrongGuess
# 14 "data/maps/FortreeCity_House2/scripts.pory"
	msgbox FortreeCity_House2_Text_CorrectTryAgainWhichHand, MSGBOX_DEFAULT
# 15 "data/maps/FortreeCity_House2/scripts.pory"
	multichoice 21, 8, MULTI_RIGHTLEFT, TRUE
# 16 "data/maps/FortreeCity_House2/scripts.pory"
	switch VAR_RESULT
# 17 "data/maps/FortreeCity_House2/scripts.pory"
	case 1, FortreeCity_House2_EventScript_WrongGuess
# 18 "data/maps/FortreeCity_House2/scripts.pory"
	msgbox FortreeCity_House2_Text_CorrectTryAgainWhichHand2, MSGBOX_DEFAULT
# 19 "data/maps/FortreeCity_House2/scripts.pory"
	multichoice 21, 8, MULTI_RIGHTLEFT, TRUE
# 20 "data/maps/FortreeCity_House2/scripts.pory"
	switch VAR_RESULT
# 21 "data/maps/FortreeCity_House2/scripts.pory"
	case 0, FortreeCity_House2_EventScript_WrongGuess
# 22 "data/maps/FortreeCity_House2/scripts.pory"
	msgbox FortreeCity_House2_Text_YourHiddenPowerHasAwoken, MSGBOX_DEFAULT
# 23 "data/maps/FortreeCity_House2/scripts.pory"
	giveitem ITEM_TM_HYPER_VOICE
# 24 "data/maps/FortreeCity_House2/scripts.pory"
	goto_if_eq VAR_RESULT, 0, Common_EventScript_ShowBagIsFull
# 25 "data/maps/FortreeCity_House2/scripts.pory"
	setflag FLAG_RECEIVED_TM_HIDDEN_POWER
# 26 "data/maps/FortreeCity_House2/scripts.pory"
	msgbox FortreeCity_House2_Text_ExplainHiddenPower, MSGBOX_DEFAULT
# 27 "data/maps/FortreeCity_House2/scripts.pory"
	release
# 28 "data/maps/FortreeCity_House2/scripts.pory"
	end
# 29 "data/maps/FortreeCity_House2/scripts.pory"

# 30 "data/maps/FortreeCity_House2/scripts.pory"
FortreeCity_House2_EventScript_Greeting::
# 31 "data/maps/FortreeCity_House2/scripts.pory"
	msgbox FortreeCity_House2_Text_HiddenPowersArousedByNature, MSGBOX_DEFAULT
# 32 "data/maps/FortreeCity_House2/scripts.pory"
	setflag FLAG_MET_HIDDEN_POWER_GIVER
# 33 "data/maps/FortreeCity_House2/scripts.pory"
	return
# 34 "data/maps/FortreeCity_House2/scripts.pory"

# 35 "data/maps/FortreeCity_House2/scripts.pory"
FortreeCity_House2_EventScript_ExplainHiddenPower::
# 36 "data/maps/FortreeCity_House2/scripts.pory"
	msgbox FortreeCity_House2_Text_ExplainHiddenPower, MSGBOX_DEFAULT
# 37 "data/maps/FortreeCity_House2/scripts.pory"
	release
# 38 "data/maps/FortreeCity_House2/scripts.pory"
	end
# 39 "data/maps/FortreeCity_House2/scripts.pory"

# 40 "data/maps/FortreeCity_House2/scripts.pory"
FortreeCity_House2_EventScript_WrongGuess::
# 41 "data/maps/FortreeCity_House2/scripts.pory"
	msgbox FortreeCity_House2_Text_YouGuessedWrong, MSGBOX_DEFAULT
# 42 "data/maps/FortreeCity_House2/scripts.pory"
	release
# 43 "data/maps/FortreeCity_House2/scripts.pory"
	end
# 44 "data/maps/FortreeCity_House2/scripts.pory"

# 45 "data/maps/FortreeCity_House2/scripts.pory"
FortreeCity_House2_Text_HiddenPowersArousedByNature:
# 46 "data/maps/FortreeCity_House2/scripts.pory"
	.string "People… POKéMON…\p"
# 47 "data/maps/FortreeCity_House2/scripts.pory"
	.string "Their hidden powers are aroused by\n"
# 48 "data/maps/FortreeCity_House2/scripts.pory"
	.string "living in natural environments…$"
# 49 "data/maps/FortreeCity_House2/scripts.pory"

# 50 "data/maps/FortreeCity_House2/scripts.pory"
FortreeCity_House2_Text_CoinInWhichHand:
# 51 "data/maps/FortreeCity_House2/scripts.pory"
	.string "Let this old woman see if your hidden\n"
# 52 "data/maps/FortreeCity_House2/scripts.pory"
	.string "power has awoken…\p"
# 53 "data/maps/FortreeCity_House2/scripts.pory"
	.string "I hold a coin in my hand.\p"
# 54 "data/maps/FortreeCity_House2/scripts.pory"
	.string "Now, tell me, have I palmed it in\n"
# 55 "data/maps/FortreeCity_House2/scripts.pory"
	.string "the right hand? Or in the left?$"
# 56 "data/maps/FortreeCity_House2/scripts.pory"

# 57 "data/maps/FortreeCity_House2/scripts.pory"
FortreeCity_House2_Text_CorrectTryAgainWhichHand:
# 58 "data/maps/FortreeCity_House2/scripts.pory"
	.string "Oh! Yes, correct!\p"
# 59 "data/maps/FortreeCity_House2/scripts.pory"
	.string "We shall try again.\p"
# 60 "data/maps/FortreeCity_House2/scripts.pory"
	.string "In which hand have I palmed the coin?\n"
# 61 "data/maps/FortreeCity_House2/scripts.pory"
	.string "The right or left?$"
# 62 "data/maps/FortreeCity_House2/scripts.pory"

# 63 "data/maps/FortreeCity_House2/scripts.pory"
FortreeCity_House2_Text_CorrectTryAgainWhichHand2:
# 64 "data/maps/FortreeCity_House2/scripts.pory"
	.string "Oh! Yes, correct!\p"
# 65 "data/maps/FortreeCity_House2/scripts.pory"
	.string "We shall try again.\p"
# 66 "data/maps/FortreeCity_House2/scripts.pory"
	.string "In which hand have I palmed the coin?\n"
# 67 "data/maps/FortreeCity_House2/scripts.pory"
	.string "The right or left?$"
# 68 "data/maps/FortreeCity_House2/scripts.pory"

# 69 "data/maps/FortreeCity_House2/scripts.pory"
FortreeCity_House2_Text_YourHiddenPowerHasAwoken:
# 70 "data/maps/FortreeCity_House2/scripts.pory"
	.string "Oh! Splendid!\n"
# 71 "data/maps/FortreeCity_House2/scripts.pory"
	.string "Your hidden power has awoken!\p"
# 72 "data/maps/FortreeCity_House2/scripts.pory"
	.string "Here, take this and awaken the hidden\n"
# 73 "data/maps/FortreeCity_House2/scripts.pory"
	.string "power of your POKéMON.$"
# 74 "data/maps/FortreeCity_House2/scripts.pory"

# 75 "data/maps/FortreeCity_House2/scripts.pory"
FortreeCity_House2_Text_ExplainHiddenPower:
# 76 "data/maps/FortreeCity_House2/scripts.pory"
	.string "HIDDEN POWER is a move that changes\n"
# 77 "data/maps/FortreeCity_House2/scripts.pory"
	.string "with the POKéMON.$"
# 78 "data/maps/FortreeCity_House2/scripts.pory"

# 79 "data/maps/FortreeCity_House2/scripts.pory"
FortreeCity_House2_Text_YouGuessedWrong:
# 80 "data/maps/FortreeCity_House2/scripts.pory"
	.string "No, too bad.\n"
# 81 "data/maps/FortreeCity_House2/scripts.pory"
	.string "You guessed wrong.$"

FortreeCity_HyperVoiceWoman::
# 85 "data/maps/FortreeCity_House2/scripts.pory"
	lockall
# 86 "data/maps/FortreeCity_House2/scripts.pory"
	faceplayer
# 87 "data/maps/FortreeCity_House2/scripts.pory"
	goto_if_set FLAG_RECEIVED_TM_HIDDEN_POWER, FortreeCity_HyperVoiceWoman_2
# 90 "data/maps/FortreeCity_House2/scripts.pory"
	msgbox FortreeCity_HyperVoiceWoman_Text_1
# 91 "data/maps/FortreeCity_House2/scripts.pory"
	msgbox FortreeCity_HyperVoiceWoman_Text_2
# 92 "data/maps/FortreeCity_House2/scripts.pory"
	giveitem ITEM_TM_HYPER_VOICE
# 93 "data/maps/FortreeCity_House2/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq FortreeCity_HyperVoiceWoman_6
FortreeCity_HyperVoiceWoman_5:
# 96 "data/maps/FortreeCity_House2/scripts.pory"
	setflag FLAG_RECEIVED_TM_HIDDEN_POWER
# 97 "data/maps/FortreeCity_House2/scripts.pory"
	msgbox FortreeCity_HyperVoiceWoman_Text_3
FortreeCity_HyperVoiceWoman_1:
# 99 "data/maps/FortreeCity_House2/scripts.pory"
	releaseall
	end

FortreeCity_HyperVoiceWoman_2:
# 88 "data/maps/FortreeCity_House2/scripts.pory"
	msgbox FortreeCity_HyperVoiceWoman_Text_0
	goto FortreeCity_HyperVoiceWoman_1

FortreeCity_HyperVoiceWoman_6:
# 94 "data/maps/FortreeCity_House2/scripts.pory"
	goto Common_EventScript_ShowBagIsFull
	goto FortreeCity_HyperVoiceWoman_5


FortreeCity_HyperVoiceWoman_Text_0:
# 88 "data/maps/FortreeCity_House2/scripts.pory"
	.string "HYPER VOICE LETS LOOSE A HORRIBLY\n"
	.string "LOUD CRY. IT'S A POWERFUL MOVE!$"

FortreeCity_HyperVoiceWoman_Text_1:
# 90 "data/maps/FortreeCity_House2/scripts.pory"
	.string "Do you have a hidden power? This old\n"
	.string "woman does…$"

FortreeCity_HyperVoiceWoman_Text_2:
# 91 "data/maps/FortreeCity_House2/scripts.pory"
	.string "I CAN SHOUT INCREDIBLY LOUD WITH MY\n"
	.string "HYPER VOICE!$"

FortreeCity_HyperVoiceWoman_Text_3:
# 97 "data/maps/FortreeCity_House2/scripts.pory"
	.string "AND YOUR POKéMON CAN NOW USE THEIR\n"
	.string "HYPER VOICES TOO!$"
