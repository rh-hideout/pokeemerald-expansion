FortreeCity_House2_MapScripts::
	.byte 0

FortreeCity_House2_EventScript_HiddenPowerGiver::
	lock
	faceplayer
	call_if_set FLAG_MET_HIDDEN_POWER_GIVER, FortreeCity_House2_EventScript_ExplainHiddenPower
	msgbox FortreeCity_House2_Text_CoinInWhichHand, MSGBOX_DEFAULT
	multichoice 21, 8, MULTI_RIGHTLEFT, TRUE
	switch VAR_RESULT
	case 1, FortreeCity_House2_EventScript_WrongGuess
	msgbox FortreeCity_House2_Text_CorrectTryAgainWhichHand, MSGBOX_DEFAULT
	multichoice 21, 8, MULTI_RIGHTLEFT, TRUE
	switch VAR_RESULT
	case 1, FortreeCity_House2_EventScript_WrongGuess
	msgbox FortreeCity_House2_Text_CorrectTryAgainWhichHand2, MSGBOX_DEFAULT
	multichoice 21, 8, MULTI_RIGHTLEFT, TRUE
	switch VAR_RESULT
	case 0, FortreeCity_House2_EventScript_WrongGuess
	setflag FLAG_MET_HIDDEN_POWER_GIVER
	giveitem ITEM_TM_FLING
	call FortreeCity_House2_EventScript_ExplainHiddenPower
	release
	end

FortreeCity_House2_EventScript_ExplainHiddenPower::
	msgbox FortreeCity_House2_Text_ExplainHiddenPower, MSGBOX_DEFAULT
	release
	end

FortreeCity_House2_EventScript_WrongGuess::
	msgbox FortreeCity_House2_Text_YouGuessedWrong, MSGBOX_DEFAULT
	release
	end

FortreeCity_House2_Text_HiddenPowersArousedByNature:
	.string "People… POKéMON…\p"
	.string "Their hidden powers are aroused by\n"
	.string "living in natural environments…$"

FortreeCity_House2_Text_CoinInWhichHand:
	.string "Let this old woman see if your hidden\n"
	.string "power has awoken…\p"
	.string "I hold a coin in my hand.\p"
	.string "Now, tell me, have I palmed it in\n"
	.string "the right hand? Or in the left?$"

FortreeCity_House2_Text_CorrectTryAgainWhichHand:
	.string "Oh! Yes, correct!\p"
	.string "We shall try again.\p"
	.string "In which hand have I palmed the coin?\n"
	.string "The right or left?$"

FortreeCity_House2_Text_CorrectTryAgainWhichHand2:
	.string "Oh! Yes, correct!\p"
	.string "We shall try again.\p"
	.string "In which hand have I palmed the coin?\n"
	.string "The right or left?$"

FortreeCity_House2_Text_ExplainHiddenPower:
	.string "IVs aren't used in this ROMHack,\n"
	.string "Hidden Power doesn't work.\p"
	.string "Instead I'm giving you this.\p"
	.string "I hope you still have a Big Nugget.$"

FortreeCity_House2_Text_YouGuessedWrong:
	.string "No, too bad.\n"
	.string "You guessed wrong.$"

