BattleFrontier_Lounge3_hns_MapScripts::
	.byte 0

	.set BET_AMOUNT_5,  5
	.set BET_AMOUNT_10, 10
	.set BET_AMOUNT_15, 15

BattleFrontier_Lounge3_EventScript_Gambler_hns::
	lock
	faceplayer
	goto_if_set FLAG_MET_BATTLE_FRONTIER_GAMBLER, BattleFrontier_Lounge3_EventScript_AlreadyMetGambler_hns
	call BattleFrontier_Lounge3_EventScript_CountSilverSymbols_hns
	goto_if_le VAR_0x8004, 2, BattleFrontier_Lounge3_EventScript_NotEnoughSilverSymbols_hns
	setflag FLAG_MET_BATTLE_FRONTIER_GAMBLER
	msgbox BattleFrontier_Lounge3_Text_YouLookToughExplainGambling_hns, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge3_EventScript_AskToEnterChallenge_hns
	end

BattleFrontier_Lounge3_EventScript_AskToEnterChallenge_hns::
	special ShowFrontierGamblerLookingMessage
	waitmessage
	waitbuttonpress
	msgbox BattleFrontier_Lounge3_Text_HowAboutEnteringEventForMe_hns, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_Lounge3_EventScript_DeclineChallenge_hns
	msgbox BattleFrontier_Lounge3_Text_SpotMeSomeBattlePoints_hns, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_Lounge3_EventScript_DeclineChallenge_hns
	message BattleFrontier_Lounge3_Text_HowMuchCanYouSpot_hns
	waitmessage
	special ShowBattlePointsWindow
	goto BattleFrontier_Lounge3_EventScript_ChooseBetAmount_hns
	end

BattleFrontier_Lounge3_EventScript_ChooseBetAmount_hns::
	multichoice 20, 4, MULTI_FRONTIER_GAMBLER_BET, FALSE
	copyvar VAR_FRONTIER_GAMBLER_AMOUNT_BET, VAR_RESULT
	switch VAR_RESULT
	case FRONTIER_GAMBLER_BET_5, BattleFrontier_Lounge3_EventScript_Bet5_hns
	case FRONTIER_GAMBLER_BET_10, BattleFrontier_Lounge3_EventScript_Bet10_hns
	case FRONTIER_GAMBLER_BET_15, BattleFrontier_Lounge3_EventScript_Bet15_hns
	case FRONTIER_GAMBLER_BET_CANCEL, BattleFrontier_Lounge3_EventScript_CancelBet_hns
	case MULTI_B_PRESSED, BattleFrontier_Lounge3_EventScript_CancelBet_hns
	end

BattleFrontier_Lounge3_EventScript_Bet5_hns::
	setvar VAR_0x8008, BET_AMOUNT_5
	goto BattleFrontier_Lounge3_EventScript_TryPlaceBet_hns
	end

BattleFrontier_Lounge3_EventScript_Bet10_hns::
	setvar VAR_0x8008, BET_AMOUNT_10
	goto BattleFrontier_Lounge3_EventScript_TryPlaceBet_hns
	end

BattleFrontier_Lounge3_EventScript_Bet15_hns::
	setvar VAR_0x8008, BET_AMOUNT_15
	goto BattleFrontier_Lounge3_EventScript_TryPlaceBet_hns
	end

BattleFrontier_Lounge3_EventScript_TryPlaceBet_hns::
	specialvar VAR_TEMP_1, GetFrontierBattlePoints
	goto_if_ge VAR_TEMP_1, VAR_0x8008, BattleFrontier_Lounge3_EventScript_PlaceBet_hns
	msgbox BattleFrontier_Lounge3_Text_YouDontHaveEnoughPoints_hns, MSGBOX_DEFAULT
	message BattleFrontier_Lounge3_Text_HowMuchCanYouSpot_hns
	waitmessage
	goto BattleFrontier_Lounge3_EventScript_ChooseBetAmount_hns
	end

BattleFrontier_Lounge3_EventScript_PlaceBet_hns::
	copyvar VAR_0x8004, VAR_0x8008
	special TakeFrontierBattlePoints
	setvar VAR_FRONTIER_GAMBLER_STATE, FRONTIER_GAMBLER_PLACED_BET
	special UpdateBattlePointsWindow
	playse SE_SHOP
	msgbox BattleFrontier_Lounge3_Text_ThanksOffYouGo_hns, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge3_EventScript_FinishBet_hns
	end

BattleFrontier_Lounge3_EventScript_FinishBet_hns::
	special ShowFrontierGamblerGoMessage
	waitmessage
	waitbuttonpress
	special CloseBattlePointsWindow
	release
	end

BattleFrontier_Lounge3_EventScript_CountSilverSymbols_hns::
	setvar VAR_0x8004, 0
	call_if_set FLAG_SYS_TOWER_SILVER, BattleFrontier_Lounge3_EventScript_AddSilverSymbolCount_hns
	call_if_set FLAG_SYS_DOME_SILVER, BattleFrontier_Lounge3_EventScript_AddSilverSymbolCount_hns
	call_if_set FLAG_SYS_PALACE_SILVER, BattleFrontier_Lounge3_EventScript_AddSilverSymbolCount_hns
	call_if_set FLAG_SYS_ARENA_SILVER, BattleFrontier_Lounge3_EventScript_AddSilverSymbolCount_hns
	call_if_set FLAG_SYS_FACTORY_SILVER, BattleFrontier_Lounge3_EventScript_AddSilverSymbolCount_hns
	call_if_set FLAG_SYS_PIKE_SILVER, BattleFrontier_Lounge3_EventScript_AddSilverSymbolCount_hns
	call_if_set FLAG_SYS_PYRAMID_SILVER, BattleFrontier_Lounge3_EventScript_AddSilverSymbolCount_hns
	return

BattleFrontier_Lounge3_EventScript_AddSilverSymbolCount_hns::
	addvar VAR_0x8004, 1
	return

BattleFrontier_Lounge3_EventScript_NotEnoughSilverSymbols_hns::
	msgbox BattleFrontier_Lounge3_Text_CantYouSeeWereBusyHere_hns, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge3_EventScript_FaceOriginalDirection_hns
	end

BattleFrontier_Lounge3_EventScript_AlreadyMetGambler_hns::
	msgbox BattleFrontier_Lounge3_Text_Oh_hns, MSGBOX_DEFAULT
	goto_if_ge VAR_FRONTIER_GAMBLER_STATE, FRONTIER_GAMBLER_PLACED_BET, BattleFrontier_Lounge3_EventScript_CheckBetResults_hns
	goto BattleFrontier_Lounge3_EventScript_AskToEnterChallenge_hns
	end

BattleFrontier_Lounge3_EventScript_CheckBetResults_hns::
	goto_if_eq VAR_FRONTIER_GAMBLER_STATE, FRONTIER_GAMBLER_PLACED_BET, BattleFrontier_Lounge3_EventScript_ChallengeNotAttempted_hns
	goto_if_eq VAR_FRONTIER_GAMBLER_STATE, FRONTIER_GAMBLER_WON, BattleFrontier_Lounge3_EventScript_WonChallenge_hns
	goto BattleFrontier_Lounge3_EventScript_LostChallenge_hns
	end

BattleFrontier_Lounge3_EventScript_WonChallenge_hns::
	msgbox BattleFrontier_Lounge3_Text_HelloChampHeresYourPoints_hns, MSGBOX_DEFAULT
	call_if_eq VAR_FRONTIER_GAMBLER_AMOUNT_BET, FRONTIER_GAMBLER_BET_5, BattleFrontier_Lounge3_EventScript_RewardBet5_hns
	call_if_eq VAR_FRONTIER_GAMBLER_AMOUNT_BET, FRONTIER_GAMBLER_BET_10, BattleFrontier_Lounge3_EventScript_RewardBet10_hns
	call_if_eq VAR_FRONTIER_GAMBLER_AMOUNT_BET, FRONTIER_GAMBLER_BET_15, BattleFrontier_Lounge3_EventScript_RewardBet15_hns
	msgbox BattleFrontier_Lounge3_Text_ObtainedBattlePoints_hns, MSGBOX_GETPOINTS
	special GiveFrontierBattlePoints
	msgbox BattleFrontier_Lounge3_Text_ThinkOfMeForAnotherChallenge_hns, MSGBOX_DEFAULT
	setvar VAR_FRONTIER_GAMBLER_STATE, FRONTIER_GAMBLER_WAITING
	release
	end

BattleFrontier_Lounge3_EventScript_LostChallenge_hns::
	msgbox BattleFrontier_Lounge3_Text_NiceTryCantReturnPoints_hns, MSGBOX_DEFAULT
	setvar VAR_FRONTIER_GAMBLER_STATE, FRONTIER_GAMBLER_WAITING
	release
	end

BattleFrontier_Lounge3_EventScript_RewardBet5_hns::
	buffernumberstring STR_VAR_1, (BET_AMOUNT_5 * 2)
	setvar VAR_0x8004, (BET_AMOUNT_5 * 2)
	return

BattleFrontier_Lounge3_EventScript_RewardBet10_hns::
	buffernumberstring STR_VAR_1, (BET_AMOUNT_10 * 2)
	setvar VAR_0x8004, (BET_AMOUNT_10 * 2)
	return

BattleFrontier_Lounge3_EventScript_RewardBet15_hns::
	buffernumberstring STR_VAR_1, (BET_AMOUNT_15 * 2)
	setvar VAR_0x8004, (BET_AMOUNT_15 * 2)
	return

BattleFrontier_Lounge3_EventScript_ChallengeNotAttempted_hns::
	special ShowFrontierGamblerGoMessage
	waitmessage
	waitbuttonpress
	release
	end

BattleFrontier_Lounge3_EventScript_DeclineChallenge_hns::
	msgbox BattleFrontier_Lounge3_Text_NotInterested_hns, MSGBOX_DEFAULT
	release
	end

BattleFrontier_Lounge3_EventScript_CancelBet_hns::
	special CloseBattlePointsWindow
	goto BattleFrontier_Lounge3_EventScript_DeclineChallenge_hns
	end

BattleFrontier_Lounge3_EventScript_Man_hns::
	msgbox BattleFrontier_Lounge3_Text_ShouldBeTakingChallenges_hns, MSGBOX_NPC
	end

BattleFrontier_Lounge3_EventScript_Woman_hns::
	lock
	faceplayer
	msgbox BattleFrontier_Lounge3_Text_BackedWrongTrainer_hns, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge3_EventScript_FaceOriginalDirection_hns
	end

BattleFrontier_Lounge3_EventScript_PokefanF_hns::
	lock
	faceplayer
	msgbox BattleFrontier_Lounge3_Text_KnowWinnerWhenISeeOne_hns, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge3_EventScript_FaceOriginalDirection_hns
	end

BattleFrontier_Lounge3_EventScript_FatMan_hns::
	lock
	faceplayer
	msgbox BattleFrontier_Lounge3_Text_TrainerGoodButRattled_hns, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge3_EventScript_FaceOriginalDirection_hns
	end

BattleFrontier_Lounge3_EventScript_FaceOriginalDirection_hns::
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

BattleFrontier_Lounge3_Text_CantYouSeeWereBusyHere_hns::
	.string "…What's that you want?\p"
	.string "Can't you see we're kind of busy here?\n"
	.string "Can't your business wait till later?$"

BattleFrontier_Lounge3_Text_YouLookToughExplainGambling_hns::
	.string "…Huh?\n"
	.string "You look to me like a tough TRAINER.\p"
	.string "Heheh…\n"
	.string "Listen, I have this proposition.\p"
	.string "We have a little group going here,\n"
	.string "and we play a little game with what\l"
	.string "goes on in the BATTLE FRONTIER.\p"
	.string "The rules are really simple.\p"
	.string "First, we pick one of the facilities\n"
	.string "in the BATTLE FRONTIER.\p"
	.string "Then, we each pick a different TRAINER\n"
	.string "who's taking that facility's challenge,\l"
	.string "and bet with our Battle Points.\p"
	.string "The guy who bet on the TRAINER with\n"
	.string "the best record takes all the Battle\l"
	.string "Points in the pool.\p"
	.string "Sounds simple, huh?\n"
	.string "So, anyway…$"

BattleFrontier_Lounge3_Text_ChallengeBattleTowerSingle_hns::
	.string "What I'm looking for is a TRAINER who's\n"
	.string "going to be challenging the BATTLE\l"
	.string "TOWER's SINGLE BATTLE ROOMS.\p"
	.string "But so far, I haven't seen a TRAINER\n"
	.string "that has that winning quality.$"

BattleFrontier_Lounge3_Text_ChallengeBattleTowerDouble_hns::
	.string "What I'm looking for is a TRAINER who's\n"
	.string "going to be challenging the BATTLE\l"
	.string "TOWER's DOUBLE BATTLE ROOMS.\p"
	.string "But so far, I haven't seen a TRAINER\n"
	.string "that has that winning quality.$"

BattleFrontier_Lounge3_Text_ChallengeBattleTowerMulti_hns::
	.string "What I'm looking for is a TRAINER who's\n"
	.string "going to be challenging the BATTLE\l"
	.string "TOWER's MULTI BATTLE ROOMS.\p"
	.string "But so far, I haven't seen a TRAINER\n"
	.string "that has that winning quality.$"

BattleFrontier_Lounge3_Text_ChallengeBattleDomeSingle_hns::
	.string "What I'm looking for is a TRAINER who's\n"
	.string "going to be entering the BATTLE\l"
	.string "DOME's SINGLE BATTLE Tourney.\p"
	.string "But so far, I haven't seen a TRAINER\n"
	.string "that has that winning quality.$"

BattleFrontier_Lounge3_Text_ChallengeBattleDomeDouble_hns::
	.string "What I'm looking for is a TRAINER who's\n"
	.string "going to be entering the BATTLE\l"
	.string "DOME's DOUBLE BATTLE Tourney.\p"
	.string "But so far, I haven't seen a TRAINER\n"
	.string "that has that winning quality.$"

BattleFrontier_Lounge3_Text_ChallengeBattleFactorySingle_hns::
	.string "What I'm looking for is a TRAINER who's\n"
	.string "going to be entering the BATTLE\l"
	.string "FACTORY's Battle Swap Single Tourney.\p"
	.string "But so far, I haven't seen a TRAINER\n"
	.string "that has that winning quality.$"

BattleFrontier_Lounge3_Text_ChallengeBattleFactoryDouble_hns::
	.string "What I'm looking for is a TRAINER who's\n"
	.string "going to be entering the BATTLE\l"
	.string "FACTORY's Battle Swap Double Tourney.\p"
	.string "But so far, I haven't seen a TRAINER\n"
	.string "that has that winning quality.$"

BattleFrontier_Lounge3_Text_ChallengeBattlePalaceSingle_hns::
	.string "What I'm looking for is a TRAINER who's\n"
	.string "going to be challenging the BATTLE\l"
	.string "PALACE's SINGLE BATTLE HALLS.\p"
	.string "But so far, I haven't seen a TRAINER\n"
	.string "that has that winning quality.$"

BattleFrontier_Lounge3_Text_ChallengeBattlePalaceDouble_hns::
	.string "What I'm looking for is a TRAINER who's\n"
	.string "going to be challenging the BATTLE\l"
	.string "PALACE's DOUBLE BATTLE HALLS.\p"
	.string "But so far, I haven't seen a TRAINER\n"
	.string "that has that winning quality.$"

BattleFrontier_Lounge3_Text_ChallengeBattleArena_hns::
	.string "What I'm looking for is a TRAINER who's\n"
	.string "going to be entering the BATTLE\l"
	.string "ARENA's Set KO Tourney.\p"
	.string "But so far, I haven't seen a TRAINER\n"
	.string "that has that winning quality.$"

BattleFrontier_Lounge3_Text_ChallengeBattlePike_hns::
	.string "What I'm looking for is a TRAINER who's\n"
	.string "going to be entering the BATTLE PIKE's\l"
	.string "Battle Choice.\p"
	.string "But so far, I haven't seen a TRAINER\n"
	.string "that has that winning quality.$"

BattleFrontier_Lounge3_Text_ChallengeBattlePyramid_hns::
	.string "What I'm looking for is a TRAINER who's\n"
	.string "going to be entering the BATTLE\l"
	.string "PYRAMID's Battle Quest.\p"
	.string "But so far, I haven't seen a TRAINER\n"
	.string "that has that winning quality.$"

BattleFrontier_Lounge3_Text_HowAboutEnteringEventForMe_hns::
	.string "I'll see to it that you benefit, too.\n"
	.string "So how about it?\l"
	.string "How about entering that event for me?$"

BattleFrontier_Lounge3_Text_SpotMeSomeBattlePoints_hns::
	.string "All right, that's perfect.\n"
	.string "So, uh… How about spotting me some\l"
	.string "of your Battle Points?\p"
	.string "Trust me, I'll show you my gratitude\n"
	.string "afterward.$"

BattleFrontier_Lounge3_Text_HowMuchCanYouSpot_hns::
	.string "Great, great!\n"
	.string "So, how much can you spot me?$"

BattleFrontier_Lounge3_Text_YouDontHaveEnoughPoints_hns::
	.string "Oh, no, no, no!\n"
	.string "You don't have enough Battle Points!\p"
	.string "I wish you wouldn't monkey around and\n"
	.string "waste everyone's time!$"

BattleFrontier_Lounge3_Text_ThanksOffYouGo_hns::
	.string "Heheh! Thanks much!\n"
	.string "So, off you go!$"

BattleFrontier_Lounge3_Text_GetToBattleTowerSingle_hns::
	.string "Get to the BATTLE TOWER's\n"
	.string "SINGLE BATTLE ROOMS pronto!\p"
	.string "It's a must-win situation!\n"
	.string "Don't blow your chance!\l"
	.string "Both of our futures depend on you!$"

BattleFrontier_Lounge3_Text_GetToBattleTowerDouble_hns::
	.string "Get to the BATTLE TOWER's\n"
	.string "DOUBLE BATTLE ROOMS pronto!\p"
	.string "It's a must-win situation!\n"
	.string "Don't blow your chance!\l"
	.string "Both of our futures depend on you!$"

BattleFrontier_Lounge3_Text_GetToBattleTowerMulti_hns::
	.string "Get to the BATTLE TOWER's\n"
	.string "MULTI BATTLE ROOMS pronto!\p"
	.string "It's a must-win situation!\n"
	.string "Don't blow your chance!\l"
	.string "Both of our futures depend on you!$"

BattleFrontier_Lounge3_Text_GetToBattleDomeSingle_hns::
	.string "Get to the BATTLE DOME's\n"
	.string "SINGLE BATTLE Tourney pronto!\p"
	.string "It's a must-win situation!\n"
	.string "Don't blow your chance!\l"
	.string "Both of our futures depend on you!$"

BattleFrontier_Lounge3_Text_GetToBattleDomeDouble_hns::
	.string "Get to the BATTLE DOME's\n"
	.string "DOUBLE BATTLE Tourney pronto!\p"
	.string "It's a must-win situation!\n"
	.string "Don't blow your chance!\l"
	.string "Both of our futures depend on you!$"

BattleFrontier_Lounge3_Text_GetToBattleFactorySingle_hns::
	.string "Get to the BATTLE FACTORY's\n"
	.string "Battle Swap Single Tourney pronto!\p"
	.string "It's a must-win situation!\n"
	.string "Don't blow your chance!\l"
	.string "Both of our futures depend on you!$"

BattleFrontier_Lounge3_Text_GetToBattleFactoryDouble_hns::
	.string "Get to the BATTLE FACTORY's\n"
	.string "Battle Swap Double Tourney pronto!\p"
	.string "It's a must-win situation!\n"
	.string "Don't blow your chance!\l"
	.string "Both of our futures depend on you!$"

BattleFrontier_Lounge3_Text_GetToBattlePalaceSingle_hns::
	.string "Get to the BATTLE PALACE's\n"
	.string "SINGLE BATTLE HALLS pronto!\p"
	.string "It's a must-win situation!\n"
	.string "Don't blow your chance!\l"
	.string "Both of our futures depend on you!$"

BattleFrontier_Lounge3_Text_GetToBattlePalaceDouble_hns::
	.string "Get to the BATTLE PALACE's\n"
	.string "DOUBLE BATTLE HALLS pronto!\p"
	.string "It's a must-win situation!\n"
	.string "Don't blow your chance!\l"
	.string "Both of our futures depend on you!$"

BattleFrontier_Lounge3_Text_GetToBattleArena_hns::
	.string "Get to the BATTLE ARENA's\n"
	.string "Set KO Tourney pronto!\p"
	.string "It's a must-win situation!\n"
	.string "Don't blow your chance!\l"
	.string "Both of our futures depend on you!$"

BattleFrontier_Lounge3_Text_GetToBattlePike_hns::
	.string "Get to the BATTLE PIKE's\n"
	.string "Battle Choice pronto!\p"
	.string "It's a must-win situation!\n"
	.string "Don't blow your chance!\l"
	.string "Both of our futures depend on you!$"

BattleFrontier_Lounge3_Text_GetToBattlePyramid_hns::
	.string "Get to the BATTLE PYRAMID's\n"
	.string "Battle Quest pronto!\p"
	.string "It's a must-win situation!\n"
	.string "Don't blow your chance!\l"
	.string "Both of our futures depend on you!$"

BattleFrontier_Lounge3_Text_NiceTryCantReturnPoints_hns::
	.string "Oh, it's you…\n"
	.string "Nice try…\p"
	.string "I hate to break it to you, but I can't\n"
	.string "return your Battle Points…\p"
	.string "I guess we'll have to let it motivate\n"
	.string "us to try harder next time!$"

BattleFrontier_Lounge3_Text_HelloChampHeresYourPoints_hns::
	.string "Oh, yes!\n"
	.string "Hello there, champ!\p"
	.string "I knew you could!\n"
	.string "I knew you would!\l"
	.string "We're both big winners!\p"
	.string "I'll return your Battle Points and,\n"
	.string "of course, a little extra from me!$"

BattleFrontier_Lounge3_Text_ObtainedBattlePoints_hns::
	.string "{PLAYER} obtained\n"
	.string "{STR_VAR_1} Battle Points.$"

BattleFrontier_Lounge3_Text_ThinkOfMeForAnotherChallenge_hns::
	.string "If you're up for another challenge,\n"
	.string "please do think of me!$"

BattleFrontier_Lounge3_Text_NotInterested_hns::
	.string "Not interested?! You shouldn't be\n"
	.string "so afraid to take a chance!$"

BattleFrontier_Lounge3_Text_Oh_hns::
	.string "Oh…$"

BattleFrontier_Lounge3_Text_BackedWrongTrainer_hns::
	.string "I backed the wrong TRAINER again!\p"
	.string "Maybe I should be battling normally\n"
	.string "like everyone else…$"

BattleFrontier_Lounge3_Text_TrainerGoodButRattled_hns::
	.string "That TRAINER…\p"
	.string "He's good, but he gets rattled too\n"
	.string "easily to survive the BATTLE DOME…$"

BattleFrontier_Lounge3_Text_KnowWinnerWhenISeeOne_hns::
	.string "Giggle!\n"
	.string "I know a winner when I see one!$"

BattleFrontier_Lounge3_Text_ShouldBeTakingChallenges_hns::
	.string "Those TRAINERS…\n"
	.string "What are they doing?\l"
	.string "They should be taking challenges.$"
