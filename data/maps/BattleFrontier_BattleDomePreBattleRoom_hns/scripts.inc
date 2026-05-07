BattleFrontier_BattleDomePreBattleRoom_hns_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleFrontier_BattleDomePreBattleRoom_OnFrame_hns
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, BattleFrontier_BattleDomePreBattleRoom_OnWarp_hns
	.byte 0

BattleFrontier_BattleDomePreBattleRoom_OnWarp_hns:
	map_script_2 VAR_TEMP_1, 0, BattleFrontier_BattleDomePreBattleRoom_EventScript_TurnPlayerNorth_hns
	.2byte 0

BattleFrontier_BattleDomePreBattleRoom_EventScript_TurnPlayerNorth_hns::
	setvar VAR_TEMP_1, 1
	turnobject LOCALID_PLAYER, DIR_NORTH
	end

BattleFrontier_BattleDomePreBattleRoom_OnFrame_hns:
	map_script_2 VAR_TEMP_0, 0, BattleFrontier_BattleDomePreBattleRoom_EventScript_EnterRoom_hns
	.2byte 0

BattleFrontier_BattleDomePreBattleRoom_EventScript_EnterRoom_hns::
	goto_if_eq VAR_0x8006, 1, BattleFrontier_BattleDomePreBattleRoom_EventScript_ReturnFromBattle_hns
	delay 1
	frontier_set FRONTIER_DATA_RECORD_DISABLED, TRUE
	setvar VAR_TEMP_0, 1
	applymovement LOCALID_PLAYER, BattleFrontier_BattleDomePreBattleRoom_Movement_PlayerEnter_hns
	waitmovement 0
	lockall
BattleFrontier_BattleDomePreBattleRoom_EventScript_AskReadyForNextRound_hns::
	call BattleFrontier_BattleDomePreBattleRoom_EventScript_ReadyForNextRoundMessage_hns
	waitmessage
	switch VAR_RESULT  @ No case?
	call BattleFrontier_EventScript_GetCantRecordBattle
	goto_if_eq VAR_RESULT, TRUE, BattleFrontier_BattleDomePreBattleRoom_EventScript_AskReadyForNextRound_hnsNoRecord_hns
	multichoice 16, 0, MULTI_TOURNEY_WITH_RECORD, TRUE
	switch VAR_RESULT
	case 0, BattleFrontier_BattleDomePreBattleRoom_EventScript_ShowOpponentInfo_hns
	case 1, BattleFrontier_BattleDomePreBattleRoom_EventScript_ShowTourneyTree_hns
	case 2, BattleFrontier_BattleDomePreBattleRoom_EventScript_ContinueChallenge_hns
	case 3, BattleFrontier_BattleDomePreBattleRoom_EventScript_AskRecordBattle_hns
	case 4, BattleFrontier_BattleDomePreBattleRoom_EventScript_AskPauseChallenge_hns
	case 5, BattleFrontier_BattleDomePreBattleRoom_EventScript_AskRetireChallenge_hns
	case MULTI_B_PRESSED, BattleFrontier_BattleDomePreBattleRoom_EventScript_AskReadyForNextRound_hns

BattleFrontier_BattleDomePreBattleRoom_EventScript_AskReadyForNextRound_hnsNoRecord_hns::
	multichoice 16, 2, MULTI_TOURNEY_NO_RECORD, TRUE
	switch VAR_RESULT
	case 0, BattleFrontier_BattleDomePreBattleRoom_EventScript_ShowOpponentInfo_hns
	case 1, BattleFrontier_BattleDomePreBattleRoom_EventScript_ShowTourneyTree_hns
	case 2, BattleFrontier_BattleDomePreBattleRoom_EventScript_ContinueChallenge_hns
	case 3, BattleFrontier_BattleDomePreBattleRoom_EventScript_AskPauseChallenge_hns
	case 4, BattleFrontier_BattleDomePreBattleRoom_EventScript_AskRetireChallenge_hns
	case MULTI_B_PRESSED, BattleFrontier_BattleDomePreBattleRoom_EventScript_AskReadyForNextRound_hns

BattleFrontier_BattleDomePreBattleRoom_EventScript_AskRecordBattle_hns::
	message BattleFrontier_BattleDomePreBattleRoom_Text_RecordLastMatch_hns
	waitmessage
	multichoicedefault 20, 8, MULTI_YESNO, 1, FALSE
	switch VAR_RESULT
	case 1, BattleFrontier_BattleDomePreBattleRoom_EventScript_AskReadyForNextRound_hns
	case 0, BattleFrontier_BattleDomePreBattleRoom_EventScript_RecordBattle_hns
	case MULTI_B_PRESSED, BattleFrontier_BattleDomePreBattleRoom_EventScript_AskReadyForNextRound_hns

BattleFrontier_BattleDomePreBattleRoom_EventScript_RecordBattle_hns::
	call BattleFrontier_EventScript_SaveBattle
	goto BattleFrontier_BattleDomePreBattleRoom_EventScript_AskReadyForNextRound_hns

BattleFrontier_BattleDomePreBattleRoom_EventScript_AskPauseChallenge_hns::
	msgbox BattleFrontier_BattleDomePreBattleRoom_Text_SaveAndQuitGame_hns, MSGBOX_YESNO
	switch VAR_RESULT
	case NO, BattleFrontier_BattleDomePreBattleRoom_EventScript_AskReadyForNextRound_hns
	case YES, BattleFrontier_BattleDomePreBattleRoom_EventScript_PauseChallenge_hns
	case MULTI_B_PRESSED, BattleFrontier_BattleDomePreBattleRoom_EventScript_AskReadyForNextRound_hns

BattleFrontier_BattleDomePreBattleRoom_EventScript_AskRetireChallenge_hns::
	message BattleFrontier_BattleDomePreBattleRoom_Text_RetireYourChallenge_hns
	waitmessage
	multichoicedefault 20, 8, MULTI_YESNO, 1, FALSE
	switch VAR_RESULT
	case 1, BattleFrontier_BattleDomePreBattleRoom_EventScript_AskReadyForNextRound_hns
	case 0, BattleFrontier_BattleDomePreBattleRoom_EventScript_RetireChallenge_hns
	case MULTI_B_PRESSED, BattleFrontier_BattleDomePreBattleRoom_EventScript_AskReadyForNextRound_hns

BattleFrontier_BattleDomePreBattleRoom_EventScript_RetireChallenge_hns::
	dome_resolvewinners DOME_PLAYER_RETIRED
	goto BattleFrontier_BattleDomeBattleRoom_EventScript_WarpToLobby_hnsLost_hns

BattleFrontier_BattleDomePreBattleRoom_EventScript_PauseChallenge_hns::
	message BattleFrontier_BattleDomePreBattleRoom_Text_SavingDataPleaseWait_hns
	waitmessage
	dome_save CHALLENGE_STATUS_PAUSED
	playse SE_SAVE
	waitse
	fadescreen FADE_TO_BLACK
	frontier_reset
	end

BattleFrontier_BattleDomePreBattleRoom_EventScript_ShowOpponentInfo_hns::
	msgbox BattleFrontier_BattleDomePreBattleRoom_Text_PlayersNextOpponentIsTrainer_hns, MSGBOX_DEFAULT
	fadescreen FADE_TO_BLACK
	dome_showopponentinfo
	waitstate
	goto BattleFrontier_BattleDomePreBattleRoom_EventScript_AskReadyForNextRound_hns

BattleFrontier_BattleDomePreBattleRoom_EventScript_ShowTourneyTree_hns::
	call BattleFrontier_BattleDomePreBattleRoom_EventScript_ShowRoundMessage_hns
	fadescreen FADE_TO_BLACK
	dome_showtourneytree
	waitstate
	goto BattleFrontier_BattleDomePreBattleRoom_EventScript_AskReadyForNextRound_hns

BattleFrontier_BattleDomePreBattleRoom_EventScript_ShowRoundMessage_hns::
	frontier_get FRONTIER_DATA_BATTLE_NUM
	switch VAR_RESULT
	case DOME_ROUND1, BattleFrontier_BattleDomePreBattleRoom_EventScript_TourneyInRound1_hns
	case DOME_ROUND2, BattleFrontier_BattleDomePreBattleRoom_EventScript_TourneyInRound2_hns
	case DOME_SEMIFINAL, BattleFrontier_BattleDomePreBattleRoom_EventScript_TourneyInSemifinals_hns
	case DOME_FINAL, BattleFrontier_BattleDomePreBattleRoom_EventScript_TourneyInFinals_hns
	return

BattleFrontier_BattleDomePreBattleRoom_EventScript_TourneyInRound1_hns::
	msgbox BattleFrontier_BattleDomePreBattleRoom_Text_TourneyInRound1_hns, MSGBOX_DEFAULT
	return

BattleFrontier_BattleDomePreBattleRoom_EventScript_TourneyInRound2_hns::
	msgbox BattleFrontier_BattleDomePreBattleRoom_Text_TourneyInRound2_hns, MSGBOX_DEFAULT
	return

BattleFrontier_BattleDomePreBattleRoom_EventScript_TourneyInSemifinals_hns::
	msgbox BattleFrontier_BattleDomePreBattleRoom_Text_TourneyInSemifinals_hns, MSGBOX_DEFAULT
	return

BattleFrontier_BattleDomePreBattleRoom_EventScript_TourneyInFinals_hns::
	msgbox BattleFrontier_BattleDomePreBattleRoom_Text_TourneyInFinals_hns, MSGBOX_DEFAULT
	return

BattleFrontier_BattleDomePreBattleRoom_EventScript_ContinueChallenge_hns::
	message BattleFrontier_BattleDomePreBattleRoom_Text_ChooseTwoMons_hns
	waitmessage
	waitbuttonpress
	fadescreen FADE_TO_BLACK
	call BattleFrontier_EventScript_GetLvlMode
	copyvar VAR_0x8004, VAR_RESULT
	setvar VAR_0x8005, DOME_BATTLE_PARTY_SIZE  @ 2 of the 3 party mons are selected for battle
	special ChoosePartyForBattleFrontier
	waitstate
	frontier_resetsketch
	goto_if_eq VAR_RESULT, 0, BattleFrontier_BattleDomePreBattleRoom_EventScript_AskReadyForNextRound_hns
	dome_set DOME_DATA_SELECTED_MONS
	dome_reduceparty
	dome_setopponent
	msgbox BattleFrontier_BattleDomePreBattleRoom_Text_RightThisWay_hns, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_DOME_PRE_BATTLE_ATTENDANT, BattleFrontier_BattleDomePreBattleRoom_Movement_AttendantMoveAside_hns
	waitmovement 0
	applymovement LOCALID_PLAYER, BattleFrontier_BattleDomePreBattleRoom_Movement_PlayerWalkToDoor_hns
	waitmovement 0
	opendoor 5, 1
	waitdooranim
	applymovement LOCALID_PLAYER, BattleFrontier_BattleDomePreBattleRoom_Movement_PlayerEnter_hnsDoor_hns
	waitmovement 0
	closedoor 5, 1
	waitdooranim
	warp MAP_BATTLE_FRONTIER_BATTLE_DOME_BATTLE_ROOM_HNS, 9, 5
	setvar VAR_TEMP_0, 0
	waitstate
	end

BattleFrontier_BattleDomePreBattleRoom_EventScript_ReadyForNextRoundMessage_hns::
	frontier_get FRONTIER_DATA_BATTLE_NUM
	switch VAR_RESULT
	case DOME_ROUND1, BattleFrontier_BattleDomePreBattleRoom_EventScript_ReadyForRound1_hns
	case DOME_ROUND2, BattleFrontier_BattleDomePreBattleRoom_EventScript_ReadyForRound2_hns
	case DOME_SEMIFINAL, BattleFrontier_BattleDomePreBattleRoom_EventScript_ReadyForSemifinals_hns
	case DOME_FINAL, BattleFrontier_BattleDomePreBattleRoom_EventScript_ReadyForFinals_hns
	return

BattleFrontier_BattleDomePreBattleRoom_EventScript_ReadyForRound1_hns::
	message BattleFrontier_BattleDomePreBattleRoom_Text_ReadyForRound1_hns
	return

BattleFrontier_BattleDomePreBattleRoom_EventScript_ReadyForRound2_hns::
	message BattleFrontier_BattleDomePreBattleRoom_Text_ReadyForRound2_hns
	return

BattleFrontier_BattleDomePreBattleRoom_EventScript_ReadyForSemifinals_hns::
	message BattleFrontier_BattleDomePreBattleRoom_Text_ReadyForSemifinals_hns
	return

BattleFrontier_BattleDomePreBattleRoom_EventScript_ReadyForFinals_hns::
	frontier_getbrainstatus
	switch VAR_RESULT
	case FRONTIER_BRAIN_SILVER, BattleFrontier_BattleDomePreBattleRoom_EventScript_ReadyForTuckerSilver_hns
	case FRONTIER_BRAIN_GOLD, BattleFrontier_BattleDomePreBattleRoom_EventScript_ReadyForTuckerGold_hns
	case FRONTIER_BRAIN_STREAK, BattleFrontier_BattleDomePreBattleRoom_EventScript_ReadyForTuckerSilver_hns
	case FRONTIER_BRAIN_STREAK_LONG, BattleFrontier_BattleDomePreBattleRoom_EventScript_ReadyForTuckerGold_hns
	message BattleFrontier_BattleDomePreBattleRoom_Text_ReadyForFinals_hns
	return

BattleFrontier_BattleDomePreBattleRoom_EventScript_ReadyForTuckerSilver_hns::
	goto_if_set FLAG_TEMP_1, BattleFrontier_BattleDomePreBattleRoom_EventScript_ReadyForTuckerSilver_hnsShort_hns
	msgbox BattleFrontier_BattleDomePreBattleRoom_Text_ReadyForTuckerSilver_hns, MSGBOX_DEFAULT
	setflag FLAG_TEMP_1
	return

BattleFrontier_BattleDomePreBattleRoom_EventScript_ReadyForTuckerGold_hns::
	goto_if_set FLAG_TEMP_1, BattleFrontier_BattleDomePreBattleRoom_EventScript_ReadyForTuckerGold_hnsShort_hns
	msgbox BattleFrontier_BattleDomePreBattleRoom_Text_ReadyForTuckerGold_hns, MSGBOX_DEFAULT
	setflag FLAG_TEMP_1
	return

BattleFrontier_BattleDomePreBattleRoom_EventScript_ReadyForTuckerSilver_hnsShort_hns::
	msgbox BattleFrontier_BattleDomePreBattleRoom_Text_ReadyForTuckerSilver_hnsShort_hns, MSGBOX_DEFAULT
	return

BattleFrontier_BattleDomePreBattleRoom_EventScript_ReadyForTuckerGold_hnsShort_hns::
	msgbox BattleFrontier_BattleDomePreBattleRoom_Text_ReadyForTuckerGold_hnsShort_hns, MSGBOX_DEFAULT
	return

BattleFrontier_BattleDomePreBattleRoom_EventScript_ReturnFromBattle_hns::
	setvar VAR_TEMP_0, 1
	msgbox BattleFrontier_BattleDomePreBattleRoom_Text_RestoreMonsToFullHealth_hns, MSGBOX_DEFAULT
	special LoadPlayerParty
	frontier_setpartyorder FRONTIER_PARTY_SIZE
	playfanfare MUS_HEAL
	waitfanfare
	special HealPlayerParty
	call BattleFrontier_BattleDomePreBattleRoom_EventScript_RoundCompleteMessage_hns
	fadescreen FADE_TO_BLACK
	dome_showstatictourneytree
	waitstate
	goto BattleFrontier_BattleDomePreBattleRoom_EventScript_AskReadyForNextRound_hns

BattleFrontier_BattleDomePreBattleRoom_EventScript_RoundCompleteMessage_hns::
	frontier_get FRONTIER_DATA_BATTLE_NUM
	switch VAR_RESULT
	case DOME_ROUND2, BattleFrontier_BattleDomePreBattleRoom_EventScript_Round1Complete_hns
	case DOME_SEMIFINAL, BattleFrontier_BattleDomePreBattleRoom_EventScript_Round2Complete_hns
	case DOME_FINAL, BattleFrontier_BattleDomePreBattleRoom_EventScript_SemifinalsComplete_hns
	return

BattleFrontier_BattleDomePreBattleRoom_EventScript_Round1Complete_hns::
	msgbox BattleFrontier_BattleDomePreBattleRoom_Text_Round1Complete_hns, MSGBOX_DEFAULT
	return

BattleFrontier_BattleDomePreBattleRoom_EventScript_Round2Complete_hns::
	msgbox BattleFrontier_BattleDomePreBattleRoom_Text_Round2Complete_hns, MSGBOX_DEFAULT
	return

BattleFrontier_BattleDomePreBattleRoom_EventScript_SemifinalsComplete_hns::
	msgbox BattleFrontier_BattleDomePreBattleRoom_Text_SemifinalsComplete_hns, MSGBOX_DEFAULT
	return

BattleFrontier_BattleDomePreBattleRoom_Movement_AttendantMoveAside_hns:
	walk_right
	face_left
	step_end

BattleFrontier_BattleDomePreBattleRoom_Movement_PlayerEnter_hns:
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

BattleFrontier_BattleDomePreBattleRoom_Movement_PlayerWalkToDoor_hns:
	walk_up
	step_end

BattleFrontier_BattleDomePreBattleRoom_Movement_PlayerEnter_hnsDoor_hns:
	walk_up
	set_invisible
	step_end

BattleFrontier_BattleDomePreBattleRoom_Text_ReadyForRound1_hns:
	.string "Your 1st-round match is next.\n"
	.string "Are you ready?$"

BattleFrontier_BattleDomePreBattleRoom_Text_ReadyForRound2_hns:
	.string "Your 2nd-round match is next.\n"
	.string "Are you ready?$"

BattleFrontier_BattleDomePreBattleRoom_Text_ReadyForSemifinals_hns:
	.string "Your semifinal match is next.\n"
	.string "Are you ready?$"

BattleFrontier_BattleDomePreBattleRoom_Text_ReadyForFinals_hns:
	.string "Your final match is next.\n"
	.string "Are you ready?$"

BattleFrontier_BattleDomePreBattleRoom_Text_ChooseTwoMons_hns:
	.string "Please choose the two POKéMON\n"
	.string "that are to appear in battle.$"

BattleFrontier_BattleDomePreBattleRoom_Text_RightThisWay_hns:
	.string "Right this way, please.$"

BattleFrontier_BattleDomePreBattleRoom_Text_RestoreMonsToFullHealth_hns:
	.string "Thank you for competing!\p"
	.string "I'll restore your POKéMON to\n"
	.string "full health.$"

BattleFrontier_BattleDomePreBattleRoom_Text_Round1Complete_hns:
	.string "All 1st-round matches have been\n"
	.string "completed.\p"
	.string "These are the teams that advanced!$"

BattleFrontier_BattleDomePreBattleRoom_Text_Round2Complete_hns:
	.string "All 2nd-round matches have been\n"
	.string "completed.\p"
	.string "These are the teams that advanced!$"

BattleFrontier_BattleDomePreBattleRoom_Text_SemifinalsComplete_hns:
	.string "All semifinal matches have been\n"
	.string "completed.\p"
	.string "These are the teams that advanced!$"

@ Unused
BattleFrontier_BattleDomePreBattleRoom_Text_CongratsReadyForRound2_hns:
	.string "Congratulations for getting through\n"
	.string "the 1st round.\p"
	.string "The 2nd round is next.\n"
	.string "Are you ready?$"

@ Unused
BattleFrontier_BattleDomePreBattleRoom_Text_CongratsReadyForSemifinals_hns:
	.string "Congratulations for advancing\n"
	.string "to the semifinals.\p"
	.string "The best four teams meet in this round.\n"
	.string "Are you ready?$"

@ Unused
BattleFrontier_BattleDomePreBattleRoom_Text_CongratsReadyForFinals_hns:
	.string "Congratulations for advancing\n"
	.string "to the final match.\p"
	.string "You're one win from the championship.\n"
	.string "Are you ready?$"

BattleFrontier_BattleDomePreBattleRoom_Text_PlayersNextOpponentIsTrainer_hns:
	.string "{PLAYER}'s next opponent\n"
	.string "is this TRAINER.$"

BattleFrontier_BattleDomePreBattleRoom_Text_TourneyInRound1_hns:
	.string "The tournament is in the 1st round.$"

BattleFrontier_BattleDomePreBattleRoom_Text_TourneyInRound2_hns:
	.string "The tournament is in the 2nd round.$"

BattleFrontier_BattleDomePreBattleRoom_Text_TourneyInSemifinals_hns:
	.string "The tournament is in the semifinals.$"

BattleFrontier_BattleDomePreBattleRoom_Text_TourneyInFinals_hns:
	.string "The tournament is up to the final.$"

BattleFrontier_BattleDomePreBattleRoom_Text_SaveAndQuitGame_hns:
	.string "Would you like to save and\n"
	.string "quit the game?$"

BattleFrontier_BattleDomePreBattleRoom_Text_RetireYourChallenge_hns:
	.string "Would you like to retire from your\n"
	.string "Battle Tournament challenge?$"

BattleFrontier_BattleDomePreBattleRoom_Text_SavingDataPleaseWait_hns:
	.string "I am saving your data.\n"
	.string "Please wait.$"

BattleFrontier_BattleDomePreBattleRoom_Text_RecordLastMatch_hns:
	.string "Should I record your last match\n"
	.string "on your FRONTIER PASS?$"

BattleFrontier_BattleDomePreBattleRoom_Text_ReadyForTuckerSilver_hns:
	.string "Congratulations for advancing\n"
	.string "to the final match.\p"
	.string "For the final match, you will challenge\n"
	.string "the DOME ACE TUCKER.\p"
	.string "Are you ready?$"

@ Identical to ReadyForTuckerSilver
BattleFrontier_BattleDomePreBattleRoom_Text_ReadyForTuckerGold_hns:
	.string "Congratulations for advancing\n"
	.string "to the final match.\p"
	.string "For the final match, you will challenge\n"
	.string "the DOME ACE TUCKER.\p"
	.string "Are you ready?$"

BattleFrontier_BattleDomePreBattleRoom_Text_ReadyForTuckerSilver_hnsShort_hns:
	.string "Your final battle against TUCKER is\n"
	.string "next. Are you ready?$"

@ Identical again
BattleFrontier_BattleDomePreBattleRoom_Text_ReadyForTuckerGold_hnsShort_hns:
	.string "Your final battle against TUCKER is\n"
	.string "next. Are you ready?$"

