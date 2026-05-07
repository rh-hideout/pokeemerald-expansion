BattleFrontier_BattleTowerBattleRoom_hns_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleFrontier_BattleTowerBattleRoom_OnFrame_hns
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, BattleFrontier_BattleTowerBattleRoom_OnWarp_hns
	.byte 0

BattleFrontier_BattleTowerBattleRoom_OnWarp_hns:
	map_script_2 VAR_TEMP_1, 0, BattleFrontier_BattleTowerBattleRoom_EventScript_SetUpObjects_hns
	.2byte 0

BattleFrontier_BattleTowerBattleRoom_EventScript_SetUpObjects_hns::
	setvar VAR_TEMP_1, 1
	applymovement LOCALID_TOWER_BATTLE_ATTENDANT_2, BattleFrontier_BattleTowerBattleRoom_Movement_SetInvisible_hns
	end

BattleFrontier_BattleTowerBattleRoom_OnFrame_hns:
	map_script_2 VAR_TEMP_0, 0, BattleFrontier_BattleTowerBattleRoom_EventScript_EnterRoom_hns
	.2byte 0

BattleFrontier_BattleTowerBattleRoom_EventScript_EnterRoom_hns::
	setvar VAR_TEMP_0, 1
	applymovement LOCALID_PLAYER, BattleFrontier_BattleTowerBattleRoom_Movement_PlayerEnter_hns
	waitmovement 0
	frontier_get FRONTIER_DATA_BATTLE_NUM
	goto_if_eq VAR_RESULT, 0, BattleFrontier_BattleTowerBattleRoom_EventScript_OpponentEnter_hns
	applymovement LOCALID_TOWER_BATTLE_ATTENDANT_1, BattleFrontier_BattleTowerBattleRoom_Movement_AttendantApproachPlayer_hns
	waitmovement 0
	applymovement LOCALID_PLAYER, BattleFrontier_BattleTowerBattleRoom_Movement_PlayerFaceAttendant_hns
	waitmovement 0
	setvar VAR_TEMP_2, 1
	frontier_set FRONTIER_DATA_RECORD_DISABLED, TRUE
	goto BattleFrontier_BattleTowerBattleRoom_EventScript_AskReadyForOpponent_hns

BattleFrontier_BattleTowerBattleRoom_EventScript_OpponentEnter_hns::
	tower_setopponent
	addobject LOCALID_TOWER_BATTLE_OPPONENT
	applymovement LOCALID_TOWER_BATTLE_OPPONENT, BattleFrontier_BattleTowerBattleRoom_Movement_OpponentEnter_hns
	waitmovement 0
	tower_getopponentintro 0
	msgbox gStringVar4, MSGBOX_DEFAULT
	waitmessage
	call BattleFrontier_BattleTowerBattleRoom_EventScript_DoTowerBattle_hns
	switch VAR_RESULT
	case B_OUTCOME_WON, BattleFrontier_BattleTowerBattleRoom_EventScript_DefeatedOpponent_hns
BattleFrontier_BattleTower_EventScript_WarpToLobbyLost_hns::
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, CHALLENGE_STATUS_LOST
	tower_set TOWER_DATA_LVL_MODE
	setvar VAR_0x8004, FANCOUNTER_USED_BATTLE_TOWER
	special Script_TryGainNewFanFromCounter
	goto BattleFrontier_BattleTowerBattleRoom_EventScript_WarpToLobby_hns

BattleFrontier_BattleTowerBattleRoom_EventScript_DefeatedOpponent_hns::
	call BattleFrontier_EventScript_IncrementWinStreak_hns
	tower_setbattlewon
	switch VAR_RESULT
	case 7, BattleFrontier_BattleTowerBattleRoom_EventScript_WarpToLobby_hnsWon_hns
	applymovement LOCALID_TOWER_BATTLE_OPPONENT, BattleFrontier_BattleTowerBattleRoom_Movement_OpponentExit_hns
	waitmovement 0
	removeobject LOCALID_TOWER_BATTLE_OPPONENT
	frontier_getbrainstatus
	call_if_ne VAR_RESULT, FRONTIER_BRAIN_NOT_READY, BattleFrontier_BattleTowerBattleRoom_EventScript_SecondAttendantEnter_hns
	applymovement LOCALID_TOWER_BATTLE_ATTENDANT_1, BattleFrontier_BattleTowerBattleRoom_Movement_AttendantApproachPlayer_hns
	waitmovement 0
	applymovement LOCALID_PLAYER, BattleFrontier_BattleTowerBattleRoom_Movement_PlayerFaceAttendant_hns
	waitmovement 0
	msgbox BattleFrontier_BattleTowerBattleRoom_Text_RestoreMonsToFullHealth_hns, MSGBOX_DEFAULT
	playfanfare MUS_HEAL
	waitfanfare
	special HealPlayerParty
BattleFrontier_BattleTowerBattleRoom_EventScript_AskReadyForOpponent_hns::
	frontier_getbrainstatus
	copyvar VAR_TEMP_F, VAR_RESULT
	goto_if_ne VAR_RESULT, FRONTIER_BRAIN_NOT_READY, BattleFrontier_BattleTowerBattleRoom_EventScript_MaidenUpNext_hns
	frontier_get FRONTIER_DATA_BATTLE_NUM
	call BattleFrontier_BattleTowerBattleRoom_EventScript_ReadyForOpponent_hns
	call BattleFrontier_EventScript_GetCantRecordBattle
	goto_if_eq VAR_RESULT, TRUE, BattleFrontier_BattleTowerBattleRoom_EventScript_AskReadyForOpponent_hnsNoRecord_hns
	multichoice 19, 4, MULTI_GO_ON_RECORD_REST_RETIRE, TRUE
	switch VAR_RESULT
	case 0, BattleFrontier_BattleTowerBattleRoom_EventScript_ContinueChallenge_hns
	case 1, BattleFrontier_BattleTowerBattleRoom_EventScript_AskRecordBattle_hns
	case 2, BattleFrontier_BattleTowerBattleRoom_EventScript_AskPauseChallenge_hns
	case 3, BattleFrontier_BattleTowerBattleRoom_EventScript_AskRetireChallenge_hns
	case MULTI_B_PRESSED, BattleFrontier_BattleTowerBattleRoom_EventScript_AskReadyForOpponent_hns

BattleFrontier_BattleTowerBattleRoom_EventScript_AskReadyForOpponent_hnsNoRecord_hns::
	multichoice 20, 6, MULTI_GO_ON_REST_RETIRE, TRUE
	switch VAR_RESULT
	case 0, BattleFrontier_BattleTowerBattleRoom_EventScript_ContinueChallenge_hns
	case 1, BattleFrontier_BattleTowerBattleRoom_EventScript_AskPauseChallenge_hns
	case 2, BattleFrontier_BattleTowerBattleRoom_EventScript_AskRetireChallenge_hns
	case MULTI_B_PRESSED, BattleFrontier_BattleTowerBattleRoom_EventScript_AskReadyForOpponent_hns

BattleFrontier_BattleTowerBattleRoom_EventScript_AskRecordBattle_hns::
	message BattleFrontier_BattleTowerBattleRoom_Text_RecordYourBattle_hns
	waitmessage
	multichoicedefault 20, 8, MULTI_YESNO, 1, FALSE
	switch VAR_RESULT
	case 1, BattleFrontier_BattleTowerBattleRoom_EventScript_AskReadyForOpponent_hns
	case 0, BattleFrontier_BattleTowerBattleRoom_EventScript_RecordBattle_hns
	case MULTI_B_PRESSED, BattleFrontier_BattleTowerBattleRoom_EventScript_AskReadyForOpponent_hns

BattleFrontier_BattleTowerBattleRoom_EventScript_RecordBattle_hns::
	call BattleFrontier_EventScript_SaveBattle
	goto BattleFrontier_BattleTowerBattleRoom_EventScript_AskReadyForOpponent_hns

BattleFrontier_BattleTowerBattleRoom_EventScript_AskPauseChallenge_hns::
	msgbox BattleFrontier_BattleTowerBattleRoom_Text_SaveAndQuitGame_hns, MSGBOX_YESNO
	switch VAR_RESULT
	case NO, BattleFrontier_BattleTowerBattleRoom_EventScript_AskReadyForOpponent_hns
	case YES, BattleFrontier_BattleTowerBattleRoom_EventScript_PauseChallenge_hns
	case MULTI_B_PRESSED, BattleFrontier_BattleTowerBattleRoom_EventScript_AskReadyForOpponent_hns

BattleFrontier_BattleTowerBattleRoom_EventScript_AskRetireChallenge_hns::
	message BattleFrontier_BattleTowerBattleRoom_Text_CancelYourChallenge_hns
	waitmessage
	multichoicedefault 20, 8, MULTI_YESNO, 1, FALSE
	switch VAR_RESULT
	case 1, BattleFrontier_BattleTowerBattleRoom_EventScript_AskReadyForOpponent_hns
	case 0, BattleFrontier_BattleTowerBattleRoom_EventScript_RetireChallenge_hns
	case MULTI_B_PRESSED, BattleFrontier_BattleTowerBattleRoom_EventScript_AskReadyForOpponent_hns

BattleFrontier_BattleTowerBattleRoom_EventScript_ContinueChallenge_hns::
	closemessage
	applymovement LOCALID_PLAYER, BattleFrontier_BattleTowerBattleRoom_Movement_PlayerFaceBattle_hns
	waitmovement 0
	applymovement LOCALID_TOWER_BATTLE_ATTENDANT_1, BattleFrontier_BattleTowerBattleRoom_Movement_AttendantReturnToPos_hns
	waitmovement 0
	goto BattleFrontier_BattleTowerBattleRoom_EventScript_OpponentEnter_hns

BattleFrontier_BattleTowerBattleRoom_EventScript_WarpToLobby_hnsWon_hns::
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, CHALLENGE_STATUS_WON
	tower_set TOWER_DATA_LVL_MODE
	setvar VAR_0x8004, FANCOUNTER_USED_BATTLE_TOWER
	special Script_TryGainNewFanFromCounter
	goto BattleFrontier_BattleTowerBattleRoom_EventScript_WarpToLobby_hns

BattleFrontier_BattleTowerBattleRoom_EventScript_PauseChallenge_hns::
	message BattleFrontier_BattleTowerBattleRoom_Text_SavingPleaseWait_hns
	waitmessage
	tower_save CHALLENGE_STATUS_PAUSED
	playse SE_SAVE
	waitse
	fadescreen FADE_TO_BLACK
	frontier_reset
	end

BattleFrontier_BattleTowerBattleRoom_EventScript_ReadyForOpponent_hns::
	copyvar VAR_TEMP_F, VAR_RESULT
	switch VAR_TEMP_F
	case 1, BattleFrontier_BattleTowerBattleRoom_EventScript_ReadyFor2ndOpponent_hns
	case 2, BattleFrontier_BattleTowerBattleRoom_EventScript_ReadyFor3rdOpponent_hns
	case 3, BattleFrontier_BattleTowerBattleRoom_EventScript_ReadyFor4thOpponent_hns
	case 4, BattleFrontier_BattleTowerBattleRoom_EventScript_ReadyFor5thOpponent_hns
	case 5, BattleFrontier_BattleTowerBattleRoom_EventScript_ReadyFor6thOpponent_hns
	case 6, BattleFrontier_BattleTowerBattleRoom_EventScript_ReadyFor7thOpponent_hns

BattleFrontier_BattleTowerBattleRoom_EventScript_ReadyFor2ndOpponent_hns::
	message BattleFrontier_BattleTowerBattleRoom_Text_ReadyFor2ndOpponent_hns
	waitmessage
	return

BattleFrontier_BattleTowerBattleRoom_EventScript_ReadyFor3rdOpponent_hns::
	message BattleFrontier_BattleTowerBattleRoom_Text_ReadyFor3rdOpponent_hns
	waitmessage
	return

BattleFrontier_BattleTowerBattleRoom_EventScript_ReadyFor4thOpponent_hns::
	message BattleFrontier_BattleTowerBattleRoom_Text_ReadyFor4thOpponent_hns
	waitmessage
	return

BattleFrontier_BattleTowerBattleRoom_EventScript_ReadyFor5thOpponent_hns::
	message BattleFrontier_BattleTowerBattleRoom_Text_ReadyFor5thOpponent_hns
	waitmessage
	return

BattleFrontier_BattleTowerBattleRoom_EventScript_ReadyFor6thOpponent_hns::
	message BattleFrontier_BattleTowerBattleRoom_Text_ReadyFor6thOpponent_hns
	waitmessage
	return

BattleFrontier_BattleTowerBattleRoom_EventScript_ReadyFor7thOpponent_hns::
	message BattleFrontier_BattleTowerBattleRoom_Text_ReadyFor7thOpponent_hns
	waitmessage
	return

BattleFrontier_EventScript_IncrementWinStreak_hns::
	frontier_incrementstreak
	return

BattleFrontier_BattleTowerBattleRoom_EventScript_SecondAttendantEnter_hns::
	applymovement LOCALID_TOWER_BATTLE_ATTENDANT_2, BattleFrontier_BattleTowerBattleRoom_Movement_SecondAttendantEnter_hns
	waitmovement 0
	applymovement LOCALID_TOWER_BATTLE_ATTENDANT_2, Common_Movement_WalkInPlaceLeft
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_TOWER_BATTLE_ATTENDANT_1, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_TOWER_BATTLE_ATTENDANT_1, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_TOWER_BATTLE_ATTENDANT_2, BattleFrontier_BattleTowerBattleRoom_Movement_SecondAttendantDelay_hns
	applymovement LOCALID_TOWER_BATTLE_ATTENDANT_1, BattleFrontier_BattleTowerBattleRoom_Movement_AttendantFaceSecondAttendant_hns
	waitmovement 0
	applymovement LOCALID_TOWER_BATTLE_ATTENDANT_2, BattleFrontier_BattleTowerBattleRoom_Movement_SecondAttendantExit_hns
	waitmovement 0
	return

BattleFrontier_BattleTowerBattleRoom_EventScript_MaidenUpNext_hns::
	goto_if_eq VAR_TEMP_2, 1, BattleFrontier_BattleTowerBattleRoom_EventScript_AskReadyForMaiden_hns
	msgbox BattleFrontier_BattleTowerBattleRoom_Text_SalonMaidenOnHerWay_hns, MSGBOX_DEFAULT
	setvar VAR_TEMP_2, 1
BattleFrontier_BattleTowerBattleRoom_EventScript_AskReadyForMaiden_hns::
	message BattleFrontier_BattleTowerBattleRoom_Text_ReadyForSalonMaiden_hns
	waitmessage
	call BattleFrontier_EventScript_GetCantRecordBattle
	goto_if_eq VAR_RESULT, TRUE, BattleFrontier_BattleTowerBattleRoom_EventScript_AskReadyForMaiden_hnsNoRecord_hns
	multichoice 19, 4, MULTI_GO_ON_RECORD_REST_RETIRE, TRUE
	switch VAR_RESULT
	case 0, BattleFrontier_BattleTowerBattleRoom_EventScript_BattleAnabel_hns
	case 1, BattleFrontier_BattleTowerBattleRoom_EventScript_AskRecordBattle_hns
	case 2, BattleFrontier_BattleTowerBattleRoom_EventScript_AskPauseChallenge_hns
	case 3, BattleFrontier_BattleTowerBattleRoom_EventScript_AskRetireChallenge_hns
	case MULTI_B_PRESSED, BattleFrontier_BattleTowerBattleRoom_EventScript_AskReadyForMaiden_hns

BattleFrontier_BattleTowerBattleRoom_EventScript_AskReadyForMaiden_hnsNoRecord_hns::
	multichoice 20, 6, MULTI_GO_ON_REST_RETIRE, TRUE
	switch VAR_RESULT
	case 0, BattleFrontier_BattleTowerBattleRoom_EventScript_BattleAnabel_hns
	case 1, BattleFrontier_BattleTowerBattleRoom_EventScript_AskPauseChallenge_hns
	case 2, BattleFrontier_BattleTowerBattleRoom_EventScript_AskRetireChallenge_hns
	case MULTI_B_PRESSED, BattleFrontier_BattleTowerBattleRoom_EventScript_AskReadyForMaiden_hns

BattleFrontier_BattleTowerBattleRoom_EventScript_BattleAnabel_hns::
	call BattleFrontier_EventScript_SetBrainObjectGfx_hns
	closemessage
	applymovement LOCALID_PLAYER, BattleFrontier_BattleTowerBattleRoom_Movement_PlayerFaceBattle_hns
	waitmovement 0
	applymovement LOCALID_TOWER_BATTLE_ATTENDANT_1, BattleFrontier_BattleTowerBattleRoom_Movement_AttendantReturnToPos_hns
	waitmovement 0
	addobject LOCALID_TOWER_BATTLE_OPPONENT
	applymovement LOCALID_TOWER_BATTLE_OPPONENT, BattleFrontier_BattleTowerBattleRoom_Movement_AnabelEnter_hns
	waitmovement 0
	switch VAR_TEMP_F
	case FRONTIER_BRAIN_GOLD, BattleFrontier_BattleTowerBattleRoom_EventScript_AnabelGoldIntro_hns
	case FRONTIER_BRAIN_STREAK, BattleFrontier_BattleTowerBattleRoom_EventScript_BattleAnabel_hnsSilver_hns
	case FRONTIER_BRAIN_STREAK_LONG, BattleFrontier_BattleTowerBattleRoom_EventScript_BattleAnabel_hnsGold_hns
	frontier_get FRONTIER_DATA_HEARD_BRAIN_SPEECH
	goto_if_ne VAR_RESULT, FALSE, BattleFrontier_BattleTowerBattleRoom_EventScript_BattleAnabel_hnsSilver_hns
	msgbox BattleFrontier_BattleTowerBattleRoom_Text_GreetingsImAnabel_hns, MSGBOX_DEFAULT
	frontier_set FRONTIER_DATA_HEARD_BRAIN_SPEECH
BattleFrontier_BattleTowerBattleRoom_EventScript_BattleAnabel_hnsSilver_hns::
	msgbox BattleFrontier_BattleTowerBattleRoom_Text_LetMeSeeYourTalent_hns, MSGBOX_DEFAULT
	call BattleFrontier_BattleTowerBattleRoom_EventScript_DoTowerBattle_hns
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, BattleFrontier_BattleTowerBattleRoom_EventScript_DefeatedAnabelSilver_hns
	goto BattleFrontier_BattleTower_EventScript_WarpToLobbyLost_hns

BattleFrontier_BattleTowerBattleRoom_EventScript_DefeatedAnabelSilver_hns::
	call BattleFrontier_EventScript_IncrementWinStreak_hns
	frontier_getsymbols
	goto_if_ne VAR_RESULT, 0, BattleFrontier_BattleTowerBattleRoom_EventScript_WarpToLobby_hnsWon_hns
	msgbox BattleFrontier_BattleTowerBattleRoom_Text_AnabelTalentShallBeRecognized_hns, MSGBOX_DEFAULT
	playfanfare MUS_OBTAIN_SYMBOL
	message BattleFrontier_BattleTowerBattleRoom_Text_ReceivedAbilitySymbol_hns
	waitmessage
	waitfanfare
	frontier_givesymbol
	msgbox BattleFrontier_BattleTowerBattleRoom_Text_UntilNextTime_hns, MSGBOX_DEFAULT
	goto BattleFrontier_BattleTowerBattleRoom_EventScript_WarpToLobby_hnsWon_hns

BattleFrontier_BattleTowerBattleRoom_EventScript_AnabelGoldIntro_hns::
	frontier_get FRONTIER_DATA_HEARD_BRAIN_SPEECH
	goto_if_ne VAR_RESULT, FALSE, BattleFrontier_BattleTowerBattleRoom_EventScript_BattleAnabel_hnsGold_hns
	msgbox BattleFrontier_BattleTowerBattleRoom_Text_AnabelYouCameBack_hns, MSGBOX_DEFAULT
	frontier_set FRONTIER_DATA_HEARD_BRAIN_SPEECH
BattleFrontier_BattleTowerBattleRoom_EventScript_BattleAnabel_hnsGold_hns::
	msgbox BattleFrontier_BattleTowerBattleRoom_Text_LetsBeginShallWe_hns, MSGBOX_DEFAULT
	call BattleFrontier_BattleTowerBattleRoom_EventScript_DoTowerBattle_hns
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, BattleFrontier_BattleTowerBattleRoom_EventScript_DefeatedAnabelGold_hns
	goto BattleFrontier_BattleTower_EventScript_WarpToLobbyLost_hns

BattleFrontier_BattleTowerBattleRoom_EventScript_DefeatedAnabelGold_hns::
	call BattleFrontier_EventScript_IncrementWinStreak_hns
	frontier_getsymbols
	goto_if_eq VAR_RESULT, 2, BattleFrontier_BattleTowerBattleRoom_EventScript_WarpToLobby_hnsWon_hns
	msgbox BattleFrontier_BattleTowerBattleRoom_Text_AnabelCongratsYourPassPlease_hns, MSGBOX_DEFAULT
	playfanfare MUS_OBTAIN_SYMBOL
	message BattleFrontier_BattleTowerBattleRoom_Text_AbilitySymbolTookGoldenShine_hns
	waitmessage
	waitfanfare
	frontier_givesymbol
	msgbox BattleFrontier_BattleTowerBattleRoom_Text_WishICouldBattleYouAgain_hns, MSGBOX_DEFAULT
	goto BattleFrontier_BattleTowerBattleRoom_EventScript_WarpToLobby_hnsWon_hns

BattleFrontier_BattleTowerBattleRoom_EventScript_DoTowerBattle_hns::
	closemessage
	setvar VAR_TEMP_2, 0
	frontier_set FRONTIER_DATA_RECORD_DISABLED, FALSE
	special HealPlayerParty
	dofacilitytrainerbattle FACILITY_BATTLE_TOWER
	waitstate
	copyvar VAR_0x8004, VAR_FRONTIER_BATTLE_MODE
	goto_if_eq VAR_0x8004, FRONTIER_MODE_LINK_MULTIS, BattleFrontier_BattleTowerBattleRoom_EventScript_EndTowerBattle_hns
	frontier_restorehelditems
	special HealPlayerParty
	frontier_resetsketch
BattleFrontier_BattleTowerBattleRoom_EventScript_EndTowerBattle_hns::
	tower_setinterviewdata
	frontier_get FRONTIER_DATA_BATTLE_OUTCOME
	return

BattleFrontier_EventScript_SetBrainObjectGfx_hns::
	frontier_setbrainobj
	return

BattleFrontier_BattleTowerBattleRoom_Movement_PlayerEnter_hns:
	walk_up
	walk_up
	walk_up
	face_right
	step_end

BattleFrontier_BattleTowerBattleRoom_Movement_PlayerFaceAttendant_hns:
	face_down
	step_end

BattleFrontier_BattleTowerBattleRoom_Movement_PlayerFaceBattle_hns:
	face_right
	step_end

BattleFrontier_BattleTowerBattleRoom_Movement_OpponentEnter_hns:
	walk_down
	walk_down
	walk_down
	walk_down
	face_left
	step_end

BattleFrontier_BattleTowerBattleRoom_Movement_OpponentExit_hns:
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

BattleFrontier_BattleTowerBattleRoom_Movement_AttendantApproachPlayer_hns:
	walk_right
	walk_right
	walk_right
	walk_up
	step_end

BattleFrontier_BattleTowerBattleRoom_Movement_AttendantReturnToPos_hns:
	walk_down
	walk_left
	walk_left
	walk_left
	face_right
	step_end

BattleFrontier_BattleTowerBattleRoom_Movement_SetInvisible_hns:
	set_invisible
	step_end

BattleFrontier_BattleTowerBattleRoom_Movement_SecondAttendantEnter_hns:
	set_visible
	delay_16
	walk_up
	walk_left
	walk_left
	delay_8
	step_end

BattleFrontier_BattleTowerBattleRoom_Movement_SecondAttendantExit_hns:
	walk_right
	walk_right
	walk_down
	set_invisible
	step_end

BattleFrontier_BattleTowerBattleRoom_Movement_SecondAttendantDelay_hns:
	delay_16
	delay_16
	delay_16
	delay_16
	step_end

BattleFrontier_BattleTowerBattleRoom_Movement_AttendantFaceSecondAttendant_hns:
	face_right
	delay_16
	delay_16
	delay_16
	delay_16
	walk_in_place_right
	step_end

BattleFrontier_BattleTowerBattleRoom_Movement_AnabelEnter_hns:
	walk_slow_down
	walk_slow_down
	walk_slow_down
	walk_slow_down
	face_left
	step_end

BattleFrontier_BattleTowerBattleRoom_EventScript_WarpToLobby_hns::
	copyvar VAR_RESULT, VAR_FRONTIER_BATTLE_MODE
	goto_if_eq VAR_RESULT, FRONTIER_MODE_DOUBLES, BattleFrontier_BattleTowerBattleRoom_EventScript_WarpToLobby_hnsDoubles_hns
	goto_if_eq VAR_RESULT, FRONTIER_MODE_MULTIS, BattleFrontier_BattleTowerBattleRoom_EventScript_WarpToLobby_hnsMultis_hns
	goto_if_eq VAR_RESULT, FRONTIER_MODE_LINK_MULTIS, BattleFrontier_BattleTowerBattleRoom_EventScript_WarpToLobby_hnsLinkMultis_hns
	warp MAP_BATTLE_FRONTIER_BATTLE_TOWER_LOBBY_HNS, 6, 6
	waitstate
	end

BattleFrontier_BattleTowerBattleRoom_EventScript_WarpToLobby_hnsDoubles_hns::
	warp MAP_BATTLE_FRONTIER_BATTLE_TOWER_LOBBY_HNS, 10, 6
	waitstate
	end

BattleFrontier_BattleTowerBattleRoom_EventScript_WarpToLobby_hnsMultis_hns::
	warp MAP_BATTLE_FRONTIER_BATTLE_TOWER_LOBBY_HNS, 14, 6
	waitstate
	end

BattleFrontier_BattleTowerBattleRoom_EventScript_WarpToLobby_hnsLinkMultis_hns::
	tower_closelink
	warp MAP_BATTLE_FRONTIER_BATTLE_TOWER_LOBBY_HNS, 18, 6
	waitstate
	end

BattleFrontier_BattleTowerBattleRoom_EventScript_RetireChallenge_hns::
	setflag FLAG_CANCEL_BATTLE_ROOM_CHALLENGE
	goto BattleFrontier_BattleTower_EventScript_WarpToLobbyLost_hns
	end

BattleFrontier_BattleTowerBattleRoom_Text_RestoreMonsToFullHealth_hns:
	.string "We will restore your POKéMON to\n"
	.string "full health.$"

@ Unused
BattleFrontier_BattleTowerBattleRoom_Text_ReadyForOpponent_hns:
	.string "You will be facing opponent no. {STR_VAR_1}.\n"
	.string "Are you ready?$"

BattleFrontier_BattleTowerBattleRoom_Text_ReadyFor2ndOpponent_hns:
	.string "You will be facing opponent no. 2.\n"
	.string "Are you ready?$"

BattleFrontier_BattleTowerBattleRoom_Text_ReadyFor3rdOpponent_hns:
	.string "You will be facing opponent no. 3.\n"
	.string "Are you ready?$"

BattleFrontier_BattleTowerBattleRoom_Text_ReadyFor4thOpponent_hns:
	.string "You will be facing opponent no. 4.\n"
	.string "Are you ready?$"

BattleFrontier_BattleTowerBattleRoom_Text_ReadyFor5thOpponent_hns:
	.string "You will be facing opponent no. 5.\n"
	.string "Are you ready?$"

BattleFrontier_BattleTowerBattleRoom_Text_ReadyFor6thOpponent_hns:
	.string "You will be facing opponent no. 6.\n"
	.string "Are you ready?$"

BattleFrontier_BattleTowerBattleRoom_Text_ReadyFor7thOpponent_hns:
	.string "You will be facing opponent no. 7.\n"
	.string "Are you ready?$"

BattleFrontier_BattleTowerBattleRoom_Text_RecordYourBattle_hns:
	.string "Record your battle on your\n"
	.string "FRONTIER PASS?$"

BattleFrontier_BattleTowerLobby_Text_BattleRecordedOnPass_hns:
	.string "{PLAYER}'s battle was recorded\n"
	.string "on the FRONTIER PASS.$"

BattleFrontier_BattleTowerBattleRoom_Text_SaveAndQuitGame_hns:
	.string "Would you like to save and\n"
	.string "quit the game?$"

BattleFrontier_BattleTowerBattleRoom_Text_SavingPleaseWait_hns:
	.string "Saving your battle data.\n"
	.string "Please wait.$"

BattleFrontier_BattleTowerBattleRoom_Text_CancelYourChallenge_hns:
	.string "Would you like to cancel your BATTLE\n"
	.string "ROOM challenge?$"

BattleFrontier_BattleTowerBattleRoom_Text_RecordCouldntBeSaved_hns::
	.string "There was an error of some sort.\n"
	.string "Your record could not be saved.$"

BattleFrontier_BattleTowerBattleRoom_Text_SalonMaidenOnHerWay_hns:
	.string "Excuse me, but…\p"
	.string "Our leader, the SALON MAIDEN, is on\n"
	.string "her way here in hopes of battling you.\p"
	.string "She should be arriving very shortly.$"

BattleFrontier_BattleTowerBattleRoom_Text_ReadyForSalonMaiden_hns:
	.string "You will be facing the SALON MAIDEN.\n"
	.string "Are you prepared?$"

BattleFrontier_BattleTowerBattleRoom_Text_GreetingsImAnabel_hns:
	.string "Greetings…\n"
	.string "My name is ANABEL.\p"
	.string "I am the SALON MAIDEN, and I am in\n"
	.string "charge of running the BATTLE TOWER…\p"
	.string "I have heard several rumors\n"
	.string "about you…\p"
	.string "In all honesty, what I have heard does\n"
	.string "not seem attractive in any way…\p"
	.string "The reason I've come to see you…\n"
	.string "Well, there is but one reason…$"

BattleFrontier_BattleTowerBattleRoom_Text_LetMeSeeYourTalent_hns:
	.string "Let me see your talent in\n"
	.string "its entirety…$"

BattleFrontier_BattleTowerBattleRoom_Text_AnabelTalentShallBeRecognized_hns:
	.string "ANABEL: Fufufu, nicely done…\p"
	.string "Your FRONTIER PASS, please…\n"
	.string "Your talent shall be recognized.$"

BattleFrontier_BattleTowerBattleRoom_Text_ReceivedAbilitySymbol_hns:
	.string "The Ability Symbol was embossed on\n"
	.string "the FRONTIER PASS!$"

BattleFrontier_BattleTowerBattleRoom_Text_UntilNextTime_hns:
	.string "… … … … … …\p"
	.string "You have confidence in your POKéMON\n"
	.string "battling talent, don't you?\p"
	.string "I urge you to keep battling and\n"
	.string "keep on winning.\p"
	.string "I will be waiting for you.\n"
	.string "Until the next time we meet…$"

BattleFrontier_BattleTowerBattleRoom_Text_AnabelYouCameBack_hns:
	.string "ANABEL: You really did come back to\n"
	.string "see me…\p"
	.string "… … … … … …\p"
	.string "You've won straight matches to see me…\n"
	.string "I won't have to hold back against you…\p"
	.string "It's been too long now…\p"
	.string "Too long since I've been able to battle\n"
	.string "without thinking about anything…$"

BattleFrontier_BattleTowerBattleRoom_Text_LetsBeginShallWe_hns:
	.string "Let's begin, shall we?$"

BattleFrontier_BattleTowerBattleRoom_Text_AnabelCongratsYourPassPlease_hns:
	.string "ANABEL: Fufu, congratulations…\n"
	.string "Your FRONTIER PASS, please…$"

BattleFrontier_BattleTowerBattleRoom_Text_AbilitySymbolTookGoldenShine_hns:
	.string "The Ability Symbol took on\n"
	.string "a golden shine!$"

BattleFrontier_BattleTowerBattleRoom_Text_WishICouldBattleYouAgain_hns:
	.string "That was fun…\p"
	.string "I have never had a POKéMON battle\n"
	.string "so enjoyable before…\p"
	.string "I wish I could battle with you again…$"

