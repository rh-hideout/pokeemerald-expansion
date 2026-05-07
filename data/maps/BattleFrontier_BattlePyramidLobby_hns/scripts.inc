BattleFrontier_BattlePyramidLobby_hns_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleFrontier_BattlePyramidLobby_OnFrame_hns
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, BattleFrontier_BattleDomeLobby_OnWarp
	.byte 0

@ Unused. Pyramid uses Dome's OnWarp (presumably by mistake). Their effects are identical
BattleFrontier_BattlePyramidLobby_OnWarp_hns:
	map_script_2 VAR_TEMP_1, 0, BattleFrontier_BattlePyramidLobby_EventScript_TurnPlayerNorth_hns
	.2byte 0

BattleFrontier_BattlePyramidLobby_EventScript_TurnPlayerNorth_hns:
	setvar VAR_TEMP_1, 1
	turnobject LOCALID_PLAYER, DIR_NORTH
	end

BattleFrontier_BattlePyramidLobby_OnFrame_hns:
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, 0, BattleFrontier_BattlePyramidLobby_EventScript_GetChallengeStatus_hns
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_SAVING, BattleFrontier_BattlePyramidLobby_EventScript_QuitWithoutSaving_hns
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_PAUSED, BattleFrontier_BattlePyramidLobby_EventScript_ResumeChallenge_hns
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_WON, BattleFrontier_BattlePyramidLobby_EventScript_WonChallenge_hns
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_LOST, BattleFrontier_BattlePyramidLobby_EventScript_LostChallenge_hns
	.2byte 0

BattleFrontier_BattlePyramidLobby_EventScript_GetChallengeStatus_hns::
	frontier_getstatus
	end

BattleFrontier_BattlePyramidLobby_EventScript_QuitWithoutSaving_hns::
	lockall
	message BattleFrontier_BattlePyramidLobby_Text_DidntSaveBeforeQuittingTakeBag_hns
	waitmessage
	playse SE_EXP_MAX
	waitse
	closemessage
	pyramid_set PYRAMID_DATA_WIN_STREAK, 0
	pyramid_set PYRAMID_DATA_WIN_STREAK_ACTIVE, FALSE
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	releaseall
	end

BattleFrontier_BattlePyramidLobby_EventScript_WonChallenge_hns::
	lockall
	frontier_isbrain
	goto_if_eq VAR_RESULT, TRUE, BattleFrontier_BattlePyramidLobby_EventScript_DefeatedKing_hns
	msgbox BattleFrontier_BattlePyramidLobby_Text_YouveConqueredPyramid_hns, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePyramidLobby_EventScript_GiveBattlePoints_hns

BattleFrontier_BattlePyramidLobby_EventScript_DefeatedKing_hns::
	msgbox BattleFrontier_BattlePyramidLobby_Text_YouveDefeatedPyramidKing_hns, MSGBOX_DEFAULT
BattleFrontier_BattlePyramidLobby_EventScript_GiveBattlePoints_hns::
	special DoBattlePyramidMonsHaveHeldItem
	call_if_eq VAR_RESULT, TRUE, BattleFrontier_BattlePyramidLobby_EventScript_StoreHeldItemsInPyramidBag_hns
	clearflag FLAG_STORING_ITEMS_IN_PYRAMID_BAG
	frontier_checkairshow
	special LoadPlayerParty
	pyramid_clearhelditems
	special HealPlayerParty
	callnative UpdateFollowingPokemon
	message BattleFrontier_BattlePyramidLobby_Text_UsedBattleBagWillBeKept_hns
	waitmessage
	playse SE_EXP_MAX
	waitse
	msgbox BattleFrontier_BattlePyramidLobby_Text_GiveYouTheseBattlePoints_hns, MSGBOX_DEFAULT
	frontier_givepoints
	msgbox BattleFrontier_Text_ObtainedXBattlePoints, MSGBOX_GETPOINTS
	message BattleFrontier_BattlePyramidLobby_Text_RecordResultsWait_hns
	waitmessage
	pyramid_setprize
	pyramid_save 0
	playse SE_SAVE
	waitse
	msgbox BattleFrontier_BattlePyramidLobby_Text_LookForwardToNextChallenge_hns, MSGBOX_DEFAULT
	closemessage
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	releaseall
	end

BattleFrontier_BattlePyramidLobby_EventScript_LostChallenge_hns::
	frontier_checkairshow
	special LoadPlayerParty
	pyramid_clearhelditems
	special HealPlayerParty
	callnative UpdateFollowingPokemon
	lockall
	message BattleFrontier_BattlePyramidLobby_Text_DisappointingHereIsBag_hns
	waitmessage
	playse SE_EXP_MAX
	waitse
	message BattleFrontier_BattlePyramidLobby_Text_RecordResultsWait_hns
	waitmessage
	pyramid_set PYRAMID_DATA_WIN_STREAK_ACTIVE, FALSE
	pyramid_save 0
	playse SE_SAVE
	waitse
	msgbox BattleFrontier_BattlePyramidLobby_Text_LookForwardToNextChallenge_hns, MSGBOX_DEFAULT
	closemessage
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	releaseall
	end

BattleFrontier_BattlePyramidLobby_EventScript_ResumeChallenge_hns::
	goto BattleFrontier_BattlePyramidLobby_EventScript_EnterChallenge_hns

BattleFrontier_BattlePyramidLobby_EventScript_Attendant_hns::
	lock
	faceplayer
	setvar VAR_FRONTIER_FACILITY, FRONTIER_FACILITY_PYRAMID
	setvar VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES
	special SavePlayerParty
	msgbox BattleFrontier_BattlePyramidLobby_Text_WelcomeToBattlePyramid_hns, MSGBOX_DEFAULT
BattleFrontier_BattlePyramidLobby_EventScript_AskTakeChallenge_hns::
	message BattleFrontier_BattlePyramidLobby_Text_EmbarkOnChallenge_hns
	waitmessage
	multichoice 17, 6, MULTI_CHALLENGEINFO, FALSE
	switch VAR_RESULT
	case 0, BattleFrontier_BattlePyramidLobby_EventScript_TryEnterChallenge_hns
	case 1, BattleFrontier_BattlePyramidLobby_EventScript_ExplainChallenge_hns
	case 2, BattleFrontier_BattlePyramidLobby_EventScript_CancelChallenge_hns
	case MULTI_B_PRESSED, BattleFrontier_BattlePyramidLobby_EventScript_CancelChallenge_hns

BattleFrontier_BattlePyramidLobby_EventScript_TryEnterChallenge_hns::
	message BattleFrontier_BattlePyramidLobby_Text_WhichLevelMode_hns
	waitmessage
	multichoice 17, 6, MULTI_LEVEL_MODE, FALSE
	switch VAR_RESULT
	case FRONTIER_LVL_TENT, BattleFrontier_BattlePyramidLobby_EventScript_CancelChallenge_hns
	case MULTI_B_PRESSED, BattleFrontier_BattlePyramidLobby_EventScript_CancelChallenge_hns
	frontier_checkineligible
	goto_if_eq VAR_0x8004, TRUE, BattleFrontier_BattlePyramidLobby_EventScript_NotEnoughValidMons_hns
	frontier_set FRONTIER_DATA_LVL_MODE, VAR_RESULT
	msgbox BattleFrontier_BattlePyramidLobby_Text_SelectThreeMons_hns, MSGBOX_DEFAULT
	fadescreen FADE_TO_BLACK
	callnative RemoveFollowingPokemon
	call BattleFrontier_EventScript_GetLvlMode
	copyvar VAR_0x8004, VAR_RESULT
	setvar VAR_0x8005, FRONTIER_PARTY_SIZE
	special ChoosePartyForBattleFrontier
	waitstate
	goto_if_eq VAR_RESULT, 0, BattleFrontier_BattlePyramidLobby_EventScript_LoadPartyAndCancelChallenge_hns
	msgbox BattleFrontier_BattlePyramidLobby_Text_OkayToSaveBeforeChallenge_hns, MSGBOX_YESNO
	switch VAR_RESULT
	case NO, BattleFrontier_BattlePyramidLobby_EventScript_LoadPartyAndCancelChallenge_hns
	case YES, BattleFrontier_BattlePyramidLobby_EventScript_SaveBeforeChallenge_hns
	case MULTI_B_PRESSED, BattleFrontier_BattlePyramidLobby_EventScript_LoadPartyAndCancelChallenge_hns

BattleFrontier_BattlePyramidLobby_EventScript_SaveBeforeChallenge_hns::
	setvar VAR_TEMP_CHALLENGE_STATUS, 0
	frontier_set FRONTIER_DATA_SELECTED_MON_ORDER
	pyramid_init
	pyramid_set PYRAMID_DATA_WIN_STREAK_ACTIVE, TRUE
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, CHALLENGE_STATUS_SAVING
	frontier_set FRONTIER_DATA_PAUSED, FALSE
	pyramid_seedfloor
	pyramid_settrainers
	special LoadPlayerParty
	closemessage
	delay 2
	call Common_EventScript_SaveGame
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	goto_if_eq VAR_RESULT, 0, BattleFrontier_BattlePyramidLobby_EventScript_CancelChallenge_hnsSaveFailed_hns
BattleFrontier_BattlePyramidLobby_EventScript_EnterChallenge_hns::
	special SavePlayerParty
	frontier_setpartyorder FRONTIER_PARTY_SIZE
	msgbox BattleFrontier_BattlePyramidLobby_Text_ShowYouIntoPyramid_hns, MSGBOX_DEFAULT
	closemessage
	call BattleFrontier_BattlePyramidLobby_EventScript_WalkToPanelAndReceiveBag_hns
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
	setvar VAR_RESULT, 0
	special HealPlayerParty
	warp MAP_BATTLE_FRONTIER_BATTLE_PYRAMID_FLOOR_HNS, 1, 1
	setvar VAR_TEMP_CHALLENGE_STATUS, 0
	waitstate
	end

BattleFrontier_BattlePyramidLobby_EventScript_ExplainChallenge_hns::
	msgbox BattleFrontier_BattlePyramidLobby_Text_ExplainBattlePyramid_hns, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePyramidLobby_EventScript_AskTakeChallenge_hns

BattleFrontier_BattlePyramidLobby_EventScript_NotEnoughValidMons_hns::
	switch VAR_RESULT
	case FRONTIER_LVL_50, BattleFrontier_BattlePyramidLobby_EventScript_NotEnoughValidMons_hnsLv50_hns
	case FRONTIER_LVL_OPEN, BattleFrontier_BattlePyramidLobby_EventScript_NotEnoughValidMons_hnsLvOpen_hns

BattleFrontier_BattlePyramidLobby_EventScript_NotEnoughValidMons_hnsLv50_hns::
	msgbox BattleFrontier_BattlePyramidLobby_Text_NotEnoughValidMonsLv50_hns, MSGBOX_DEFAULT
	call BattleFrontier_ShowCaughtBannedSpecies
	msgbox BattleFrontier_BattlePyramidLobby_Text_NotEnoughValidMonsEnd_hns, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePyramidLobby_EventScript_EndCancelChallenge_hns

BattleFrontier_BattlePyramidLobby_EventScript_NotEnoughValidMons_hnsLvOpen_hns::
	msgbox BattleFrontier_BattlePyramidLobby_Text_NotEnoughValidMonsLvOpen_hns, MSGBOX_DEFAULT
	call BattleFrontier_ShowCaughtBannedSpecies
	msgbox BattleFrontier_BattlePyramidLobby_Text_NotEnoughValidMonsEnd_hns, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePyramidLobby_EventScript_EndCancelChallenge_hns

BattleFrontier_BattlePyramidLobby_EventScript_CancelChallenge_hnsSaveFailed_hns::
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
	goto BattleFrontier_BattlePyramidLobby_EventScript_CancelChallenge_hns

BattleFrontier_BattlePyramidLobby_EventScript_LoadPartyAndCancelChallenge_hns::
	special LoadPlayerParty
	callnative UpdateFollowingPokemon
BattleFrontier_BattlePyramidLobby_EventScript_CancelChallenge_hns::
	msgbox BattleFrontier_BattlePyramidLobby_Text_AwaitFutureChallenge_hns, MSGBOX_DEFAULT
BattleFrontier_BattlePyramidLobby_EventScript_EndCancelChallenge_hns::
	release
	end

BattleFrontier_BattlePyramidLobby_EventScript_HintGiver_hns::
	lockall
	applymovement LOCALID_PYRAMID_LOBBY_HINT_GIVER, Common_Movement_FacePlayer
	waitmovement 0
	msgbox BattleFrontier_BattlePyramidLobby_Text_TellYouWhatMisfortunesAwait_hns, MSGBOX_DEFAULT
	call BattleFrontier_BattlePyramidLobby_EventScript_GiveHint_hns
	msgbox BattleFrontier_BattlePyramidLobby_Text_BelieveMyFortunesOrNot_hns, MSGBOX_DEFAULT
	releaseall
	end

BattleFrontier_BattlePyramidLobby_EventScript_GiveHint_hns::
	multichoice 17, 6, MULTI_LEVEL_MODE, FALSE
	switch VAR_RESULT
	case FRONTIER_LVL_50, BattleFrontier_BattlePyramidLobby_EventScript_GiveHint_hnsLv50_hns
	case FRONTIER_LVL_OPEN, BattleFrontier_BattlePyramidLobby_EventScript_GiveHint_hnsLvOpen_hns
	case FRONTIER_LVL_TENT, BattleFrontier_BattlePyramidLobby_EventScript_NoHint_hns
	case MULTI_B_PRESSED, BattleFrontier_BattlePyramidLobby_EventScript_NoHint_hns
	return

@ Shouldnt occur
BattleFrontier_BattlePyramidLobby_EventScript_NoHint_hns::
	return

BattleFrontier_BattlePyramidLobby_EventScript_GiveHint_hnsLv50_hns::
	msgbox BattleFrontier_BattlePyramidLobby_Text_Aah_hns, MSGBOX_DEFAULT
	pyramid_get PYRAMID_DATA_WIN_STREAK_ACTIVE_50
	goto_if_ne VAR_RESULT, FALSE, BattleFrontier_BattlePyramidLobby_EventScript_GiveHint_hnsGetLv50Streak_hns
	setvar VAR_RESULT, 0
	goto BattleFrontier_BattlePyramidLobby_EventScript_DoHintComment_hns
	return

BattleFrontier_BattlePyramidLobby_EventScript_GiveHint_hnsGetLv50Streak_hns::
	pyramid_get PYRAMID_DATA_WIN_STREAK_50
	goto BattleFrontier_BattlePyramidLobby_EventScript_DoHintComment_hns
	return

BattleFrontier_BattlePyramidLobby_EventScript_GiveHint_hnsLvOpen_hns::
	msgbox BattleFrontier_BattlePyramidLobby_Text_Aah_hns, MSGBOX_DEFAULT
	pyramid_get PYRAMID_DATA_WIN_STREAK_ACTIVE_OPEN
	goto_if_ne VAR_RESULT, FALSE, BattleFrontier_BattlePyramidLobby_EventScript_GiveHint_hnsGetLvOpenStreak_hns
	setvar VAR_RESULT, 0
	goto BattleFrontier_BattlePyramidLobby_EventScript_DoHintComment_hns
	return

BattleFrontier_BattlePyramidLobby_EventScript_GiveHint_hnsGetLvOpenStreak_hns::
	pyramid_get PYRAMID_DATA_WIN_STREAK_OPEN
	goto BattleFrontier_BattlePyramidLobby_EventScript_DoHintComment_hns
	return

BattleFrontier_BattlePyramidLobby_EventScript_DoHintComment_hns::
	copyvar VAR_0x8004, VAR_RESULT
	special GetBattlePyramidHint
	switch VAR_RESULT
	case 0, BattleFrontier_BattlePyramidLobby_EventScript_HintParalysis_hns
	case 1, BattleFrontier_BattlePyramidLobby_EventScript_HintPoison_hns
	case 2, BattleFrontier_BattlePyramidLobby_EventScript_HintBurn_hns
	case 3, BattleFrontier_BattlePyramidLobby_EventScript_HintPPWaste_hns
	case 4, BattleFrontier_BattlePyramidLobby_EventScript_HintLevitate_hns
	case 5, BattleFrontier_BattlePyramidLobby_EventScript_HintTrapAbility_hns
	case 6, BattleFrontier_BattlePyramidLobby_EventScript_HintIce_hns
	case 7, BattleFrontier_BattlePyramidLobby_EventScript_HintExplosion_hns
	case 8, BattleFrontier_BattlePyramidLobby_EventScript_HintPsychic_hns
	case 9, BattleFrontier_BattlePyramidLobby_EventScript_HintRock_hns
	case 10, BattleFrontier_BattlePyramidLobby_EventScript_HintFighting_hns
	case 11, BattleFrontier_BattlePyramidLobby_EventScript_HintWeather_hns
	case 12, BattleFrontier_BattlePyramidLobby_EventScript_HintBug_hns
	case 13, BattleFrontier_BattlePyramidLobby_EventScript_HintDark_hns
	case 14, BattleFrontier_BattlePyramidLobby_EventScript_HintWater_hns
	case 15, BattleFrontier_BattlePyramidLobby_EventScript_HintGhost_hns
	case 16, BattleFrontier_BattlePyramidLobby_EventScript_HintSteel_hns
	case 17, BattleFrontier_BattlePyramidLobby_EventScript_HintFlyingDragon_hns
	case 18, BattleFrontier_BattlePyramidLobby_EventScript_HintStoneEvolve_hns
	case 19, BattleFrontier_BattlePyramidLobby_EventScript_HintNormal_hns
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintParalysis_hns::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintParalysis_hns, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintPoison_hns::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintPoison_hns, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintBurn_hns::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintBurn_hns, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintPPWaste_hns::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintPPWaste_hns, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintLevitate_hns::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintLevitate_hns, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintTrapAbility_hns::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintTrapAbility_hns, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintIce_hns::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintIce_hns, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintExplosion_hns::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintExplosion_hns, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintPsychic_hns::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintPsychic_hns, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintRock_hns::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintRock_hns, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintFighting_hns::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintFighting_hns, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintWeather_hns::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintWeather_hns, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintBug_hns::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintBug_hns, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintDark_hns::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintDark_hns, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintWater_hns::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintWater_hns, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintGhost_hns::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintGhost_hns, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintSteel_hns::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintSteel_hns, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintFlyingDragon_hns::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintFlyingDragon_hns, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintStoneEvolve_hns::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintStoneEvolve_hns, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintNormal_hns::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintNormal_hns, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_ShowResults_hns::
	lockall
	frontier_results FRONTIER_FACILITY_PYRAMID
	waitbuttonpress
	special RemoveRecordsWindow
	releaseall
	end

BattleFrontier_BattlePyramidLobby_EventScript_WalkToPanelAndReceiveBag_hns::
	applymovement LOCALID_PYRAMID_LOBBY_ATTENDANT, BattleFrontier_BattlePyramidLobby_Movement_AttendantWalkToPanel_hns
	applymovement LOCALID_PLAYER, BattleFrontier_BattlePyramidLobby_Movement_PlayerWalkToPanel_hns
	waitmovement 0
	msgbox BattleFrontier_BattlePyramidLobby_Text_WeWillHoldBagForSafekeeping_hns, MSGBOX_DEFAULT
	pyramid_get PYRAMID_DATA_WIN_STREAK
	goto_if_eq VAR_RESULT, 0, BattleFrontier_BattlePyramidLobby_EventScript_ReceiveNewBattleBag_hns
	msgbox BattleFrontier_BattlePyramidLobby_Text_PleaseTakePreviousBattleBag_hns, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePyramidLobby_EventScript_ReceiveBattleBag_hns

BattleFrontier_BattlePyramidLobby_EventScript_ReceiveNewBattleBag_hns::
	msgbox BattleFrontier_BattlePyramidLobby_Text_PleaseTakeThisBattleBag_hns, MSGBOX_DEFAULT
BattleFrontier_BattlePyramidLobby_EventScript_ReceiveBattleBag_hns::
	message BattleFrontier_BattlePyramidLobby_Text_ExchangedBagForBattleBag_hns
	waitmessage
	playse SE_EXP_MAX
	waitse
	msgbox BattleFrontier_BattlePyramidLobby_Text_StepOnFloorPanel_hns, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PYRAMID_LOBBY_ATTENDANT, BattleFrontier_BattlePyramidLobby_Movement_AttendantMoveAside_hns
	waitmovement 0
	applymovement LOCALID_PLAYER, BattleFrontier_BattlePyramidLobby_Movement_PlayerStepOnPanel_hns
	waitmovement 0
	return

BattleFrontier_BattlePyramidLobby_Movement_AttendantWalkToPanel_hns:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	face_down
	step_end

BattleFrontier_BattlePyramidLobby_Movement_PlayerWalkToPanel_hns:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

BattleFrontier_BattlePyramidLobby_Movement_AttendantMoveAside_hns:
	walk_right
	face_left
	step_end

BattleFrontier_BattlePyramidLobby_Movement_PlayerStepOnPanel_hns:
	walk_up
	walk_up
	step_end

BattleFrontier_BattlePyramidLobby_EventScript_StoreHeldItemsInPyramidBag_hns::
	msgbox BattleFrontier_BattlePyramidLobby_Text_MonHoldingItemCannotTake_hns, MSGBOX_DEFAULT
	setflag FLAG_STORING_ITEMS_IN_PYRAMID_BAG
	special TryStoreHeldItemsInPyramidBag
	goto_if_eq VAR_RESULT, 0, BattleFrontier_BattlePyramidLobby_EventScript_HeldItemsStoredInPyramidBag_hns
	message BattleFrontier_BattlePyramidLobby_Text_BagCannotHoldPickItemsToKeep_hns
	waitmessage
	goto BattleFrontier_BattlePyramidLobby_EventScript_PickItemsToKeep_hns
	end

BattleFrontier_BattlePyramidLobby_EventScript_HeldItemsStoredInPyramidBag_hns::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HeldItemsMovedToBag_hns, MSGBOX_DEFAULT
	return

@ When exiting Battle Pyramid with a full pyramid bag and held items the player must select to keep/toss party held items and make room for any kept items by tossing from the pyramid bag
BattleFrontier_BattlePyramidLobby_EventScript_PickItemsToKeep_hns::
	multichoice 17, 6, MULTI_FRONTIER_ITEM_CHOOSE, FALSE
	switch VAR_RESULT
	case 0, BattleFrontier_BattlePyramidLobby_EventScript_PickItemsFromBag_hns
	case 1, BattleFrontier_BattlePyramidLobby_EventScript_PickItemsFromParty_hns
	case 2, BattleFrontier_BattlePyramidLobby_EventScript_ExitPickItems_hns
	case MULTI_B_PRESSED, BattleFrontier_BattlePyramidLobby_EventScript_ExitPickItems_hns
	end

BattleFrontier_BattlePyramidLobby_EventScript_PickItemsFromBag_hns::
	special ChooseItemsToTossFromPyramidBag
	waitstate
	message BattleFrontier_BattlePyramidLobby_Text_PickItemsToKeep_hns
	waitmessage
	goto BattleFrontier_BattlePyramidLobby_EventScript_PickItemsToKeep_hns
	end

BattleFrontier_BattlePyramidLobby_EventScript_PickItemsFromParty_hns::
	special BattlePyramidChooseMonHeldItems
	waitstate
	message BattleFrontier_BattlePyramidLobby_Text_PickItemsToKeep_hns
	waitmessage
	goto BattleFrontier_BattlePyramidLobby_EventScript_PickItemsToKeep_hns
	end

BattleFrontier_BattlePyramidLobby_EventScript_ExitPickItems_hns::
	special DoBattlePyramidMonsHaveHeldItem
	goto_if_eq VAR_RESULT, TRUE, BattleFrontier_BattlePyramidLobby_EventScript_PartyStillHasHeldItems_hns
	return

BattleFrontier_BattlePyramidLobby_EventScript_PartyStillHasHeldItems_hns::
	msgbox BattleFrontier_BattlePyramidLobby_Text_LeastOneMonHoldingItem_hns, MSGBOX_DEFAULT
	message BattleFrontier_BattlePyramidLobby_Text_PickItemsToKeep_hns
	waitmessage
	goto BattleFrontier_BattlePyramidLobby_EventScript_PickItemsToKeep_hns
	end

BattleFrontier_BattlePyramidLobby_EventScript_Woman_hns::
	msgbox BattleFrontier_BattlePyramidLobby_Text_TrainersNoticeRunning_hns, MSGBOX_NPC
	end

BattleFrontier_BattlePyramidLobby_EventScript_FatMan_hns::
	msgbox BattleFrontier_BattlePyramidLobby_Text_LostLotOfItems_hns, MSGBOX_NPC
	end

BattleFrontier_BattlePyramidLobby_EventScript_RulesBoard_hns::
	lockall
	msgbox BattleFrontier_BattlePyramidLobby_Text_RulesAreListed_hns, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePyramidLobby_EventScript_ReadRulesBoard_hns
	end

BattleFrontier_BattlePyramidLobby_EventScript_ReadRulesBoard_hns::
	message BattleFrontier_BattlePyramidLobby_Text_ReadWhichHeading_hns
	waitmessage
	multichoice 15, 2, MULTI_BATTLE_PYRAMID_RULES, FALSE
	switch VAR_RESULT
	case 0, BattleFrontier_BattlePyramidLobby_EventScript_RulesPokemon_hns
	case 1, BattleFrontier_BattlePyramidLobby_EventScript_RulesTrainers_hns
	case 2, BattleFrontier_BattlePyramidLobby_EventScript_RulesMaze_hns
	case 3, BattleFrontier_BattlePyramidLobby_EventScript_RulesBag_hns
	case 4, BattleFrontier_BattlePyramidLobby_EventScript_ExitRules_hns
	case MULTI_B_PRESSED, BattleFrontier_BattlePyramidLobby_EventScript_ExitRules_hns
	end

BattleFrontier_BattlePyramidLobby_EventScript_RulesPokemon_hns::
	msgbox BattleFrontier_BattlePyramidLobby_Text_ExplainMonRules_hns, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePyramidLobby_EventScript_ReadRulesBoard_hns
	end

BattleFrontier_BattlePyramidLobby_EventScript_RulesTrainers_hns::
	msgbox BattleFrontier_BattlePyramidLobby_Text_ExplainTrainerRules_hns, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePyramidLobby_EventScript_ReadRulesBoard_hns
	end

BattleFrontier_BattlePyramidLobby_EventScript_RulesMaze_hns::
	msgbox BattleFrontier_BattlePyramidLobby_Text_ExplainMazeRules_hns, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePyramidLobby_EventScript_ReadRulesBoard_hns
	end

BattleFrontier_BattlePyramidLobby_EventScript_RulesBag_hns::
	msgbox BattleFrontier_BattlePyramidLobby_Text_ExplainBagRules_hns, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePyramidLobby_EventScript_ReadRulesBoard_hns
	end

BattleFrontier_BattlePyramidLobby_EventScript_ExitRules_hns::
	releaseall
	end

BattleFrontier_BattlePyramidLobby_Text_WelcomeToBattlePyramid_hns:
	.string "Where the courage of TRAINERS\n"
	.string "is put to the test!\p"
	.string "Welcome to the BATTLE PYRAMID!\p"
	.string "I am your guide to\n"
	.string "the Battle Quest.$"

BattleFrontier_BattlePyramidLobby_Text_EmbarkOnChallenge_hns:
	.string "Have you the courage to embark on\n"
	.string "the Battle Quest challenge?$"

BattleFrontier_BattlePyramidLobby_Text_AwaitFutureChallenge_hns:
	.string "We await your challenge in the future!$"

BattleFrontier_BattlePyramidLobby_Text_ExplainBattlePyramid_hns:
	.string "The Battle Quest is a battling\n"
	.string "event in which you must explore\l"
	.string "the PYRAMID and try to reach the top.\p"
	.string "In the PYRAMID are seven floors of\n"
	.string "mazes, all of them filled with not only\l"
	.string "skilled TRAINERS but also wild POKéMON.\p"
	.string "You must enter with three POKéMON,\n"
	.string "none of them holding an item.\p"
	.string "On your ascent, you will be provided\n"
	.string "with a BATTLE BAG for items.\p"
	.string "If you fail in your challenge, any item\n"
	.string "placed in the BATTLE BAG disappears.\p"
	.string "If you want to interrupt your\n"
	.string "challenge, you must select “REST”\l"
	.string "and save the game.\p"
	.string "If you don't save before interrupting,\n"
	.string "you will be disqualified.$"

BattleFrontier_BattlePyramidLobby_Text_WhichLevelMode_hns:
	.string "The PYRAMID offers two courses,\n"
	.string "Level 50 and Open Level.\l"
	.string "Which will you enter?$"

BattleFrontier_BattlePyramidLobby_Text_SelectThreeMons_hns:
	.string "Very good. Now, please select the three\n"
	.string "POKéMON you wish to accompany you.$"

BattleFrontier_BattlePyramidLobby_Text_NotEnoughValidMonsLvOpen_hns:
	.string "A slight problem, adventurer!\p"
	.string "You seem to not have the three\n"
	.string "POKéMON qualified for the challenge.\p"
	.string "Please also remember to take all\n"
	.string "items from your POKéMON.\p"
	.string "EGGS{STR_VAR_1}.$"

BattleFrontier_BattlePyramidLobby_Text_NotEnoughValidMonsLv50_hns:
	.string "A slight problem, adventurer!\p"
	.string "You seem to not have the three\n"
	.string "POKéMON qualified for the challenge.\p"
	.string "The three POKéMON must be different\n"
	.string "and each no higher than Level 50.\p"
	.string "Please also remember to take all\n"
	.string "items from your POKéMON.\p"
	.string "EGGS{STR_VAR_1}.$"

BattleFrontier_BattlePyramidLobby_Text_NotEnoughValidMonsEnd_hns:
	.string "When you are ready, please have\n"
	.string "a word with me.$"

BattleFrontier_BattlePyramidLobby_Text_OkayToSaveBeforeChallenge_hns:
	.string "Before you enter the BATTLE PYRAMID,\n"
	.string "the game must be saved. Is that okay?$"

BattleFrontier_BattlePyramidLobby_Text_ShowYouIntoPyramid_hns:
	.string "Very good. I will now show you into\n"
	.string "the BATTLE PYRAMID.$"

BattleFrontier_BattlePyramidLobby_Text_WeWillHoldBagForSafekeeping_hns:
	.string "We will hold your BAG for safekeeping,\n"
	.string "{PLAYER}, while you are exploring.$"

BattleFrontier_BattlePyramidLobby_Text_PleaseTakePreviousBattleBag_hns:
	.string "In exchange, please take this BATTLE\n"
	.string "BAG, the one you used previously.$"

BattleFrontier_BattlePyramidLobby_Text_PleaseTakeThisBattleBag_hns:
	.string "In exchange, please take this\n"
	.string "BATTLE BAG.$"

BattleFrontier_BattlePyramidLobby_Text_ExchangedBagForBattleBag_hns:
	.string "{PLAYER} exchanged the BAG for\n"
	.string "the BATTLE BAG.$"

BattleFrontier_BattlePyramidLobby_Text_StepOnFloorPanel_hns:
	.string "When you step on this floor panel,\n"
	.string "you will be transported to a higher\l"
	.string "floor in the PYRAMID.\p"
	.string "I hope for your sake that your\n"
	.string "quest goes safely!$"

BattleFrontier_BattlePyramidLobby_Text_DidntSaveBeforeQuittingTakeBag_hns:
	.string "A major problem, explorer!\p"
	.string "You did not save before ending\n"
	.string "your challenge the last time.\p"
	.string "Consequently, your challenge has\n"
	.string "been disqualified, I'm sorry to say.\p"
	.string "Here is the BAG we've been holding\n"
	.string "for you.\p"
	.string "{PLAYER} got the BAG back.$"

BattleFrontier_BattlePyramidLobby_Text_YouveConqueredPyramid_hns:
	.string "Excellent to see you back!\p"
	.string "You've conquered the PYRAMID!\n"
	.string "How splendid!$"

BattleFrontier_BattlePyramidLobby_Text_MonHoldingItemCannotTake_hns:
	.string "Ah, a slight problem.\p"
	.string "At least one POKéMON is holding\n"
	.string "an item.\p"
	.string "I'm sorry to say, items obtained in\n"
	.string "the PYRAMID cannot be taken away.$"

BattleFrontier_BattlePyramidLobby_Text_HeldItemsMovedToBag_hns:
	.string "All items held by your POKéMON will be\n"
	.string "moved to your BATTLE BAG, {PLAYER}.$"

BattleFrontier_BattlePyramidLobby_Text_BagCannotHoldPickItemsToKeep_hns:
	.string "The BATTLE BAG cannot hold all your\n"
	.string "items, I'm sorry to say.\p"
	.string "Please pick the items you'll keep in the\n"
	.string "BATTLE BAG, and with your POKéMON.$"

BattleFrontier_BattlePyramidLobby_Text_LeastOneMonHoldingItem_hns:
	.string "At least one POKéMON is still\n"
	.string "holding an item.$"

BattleFrontier_BattlePyramidLobby_Text_PickItemsToKeep_hns:
	.string "Please pick the items you'll keep in the\n"
	.string "BATTLE BAG, and with your POKéMON.$"

@ Unused
BattleFrontier_BattlePyramidLobby_Text_ReturnedEverythingMonsHeld_hns:
	.string "{PLAYER} returned everything that\n"
	.string "the POKéMON held.$"

BattleFrontier_BattlePyramidLobby_Text_UsedBattleBagWillBeKept_hns:
	.string "The BATTLE BAG you used will be kept\n"
	.string "in readiness for your next challenge.\p"
	.string "{PLAYER} turned the BATTLE BAG over\n"
	.string "for the BAG's return.$"

BattleFrontier_BattlePyramidLobby_Text_RecordResultsWait_hns:
	.string "I must record your results.\n"
	.string "Please wait.$"

@ Unused
BattleFrontier_BattlePyramidLobby_Text_ForConqueringPyramidTakeThis_hns:
	.string "As a memento for conquering\n"
	.string "the BATTLE PYRAMID, please take this.$"

@ Unused
BattleFrontier_BattlePyramidLobby_Text_ReceivedPrizeItem_hns:
	.string "{PLAYER} received the prize\n"
	.string "{STR_VAR_1}.$"

@ Unused
BattleFrontier_BattlePyramidLobby_Text_BagIsFull_hns:
	.string "…Ah…\n"
	.string "Your BAG appears to be filled.\p"
	.string "Please return after you've organized\n"
	.string "your BAG's contents.$"

BattleFrontier_BattlePyramidLobby_Text_DisappointingHereIsBag_hns:
	.string "How disappointing for you…\p"
	.string "Here is the BAG we've been holding\n"
	.string "for you.\p"
	.string "{PLAYER} got the BAG back.$"

BattleFrontier_BattlePyramidLobby_Text_LookForwardToNextChallenge_hns:
	.string "We look forward to your\n"
	.string "next challenge!$"

@ Unused
BattleFrontier_BattlePyramidLobby_Text_HereIsPrize_hns:
	.string "We have been looking forward to\n"
	.string "your arrival!\p"
	.string "Here is your prize for conquering\n"
	.string "the PYRAMID.$"

BattleFrontier_BattlePyramidLobby_Text_TellYouWhatMisfortunesAwait_hns:
	.string "Welcome…\p"
	.string "I shall be pleased to tell you what\n"
	.string "misfortunes await in the PYRAMID…$"

BattleFrontier_BattlePyramidLobby_Text_Aah_hns:
	.string "… … … … … …\n"
	.string "… … … … … …\p"
	.string "… … … … … …\n"
	.string "Aah!$"

BattleFrontier_BattlePyramidLobby_Text_HintParalysis_hns:
	.string "I see a shower of sparks…\p"
	.string "…And in it, I see your POKéMON\n"
	.string "struggling with paralysis…$"

BattleFrontier_BattlePyramidLobby_Text_HintPoison_hns:
	.string "I see poison…\p"
	.string "…And, I see your POKéMON suffering\n"
	.string "from the effects of poison…$"

BattleFrontier_BattlePyramidLobby_Text_HintBurn_hns:
	.string "I see bright red flames…\p"
	.string "…And, I see your POKéMON suffering\n"
	.string "from burns…$"

BattleFrontier_BattlePyramidLobby_Text_HintPPWaste_hns:
	.string "I sense the tremendous pressure of\n"
	.string "unrequited anger…\p"
	.string "It is a curse…\p"
	.string "…And, I see your POKéMON drained of\n"
	.string "Power Points and having no recourse\l"
	.string "but to use STRUGGLE…$"

BattleFrontier_BattlePyramidLobby_Text_HintLevitate_hns:
	.string "I see POKéMON loftily airborne…\p"
	.string "…And, I see your POKéMON frustrated\n"
	.string "by powerless GROUND-type moves…$"

BattleFrontier_BattlePyramidLobby_Text_HintTrapAbility_hns:
	.string "I sense terrific energy rising from\n"
	.string "the ground below…\p"
	.string "…And, I see your POKéMON unable to\n"
	.string "escape the power's clutches…$"

BattleFrontier_BattlePyramidLobby_Text_HintIce_hns:
	.string "I see ICE-type POKéMON…\p"
	.string "…And, I see your POKéMON fighting\n"
	.string "the freezing effects of ice…$"

BattleFrontier_BattlePyramidLobby_Text_HintExplosion_hns:
	.string "I see a flurry of moves that imperil\n"
	.string "the user…\p"
	.string "…And, I see your POKéMON falling\n"
	.string "to them…$"

BattleFrontier_BattlePyramidLobby_Text_HintPsychic_hns:
	.string "I see PSYCHIC-type POKéMON…\p"
	.string "…And, I see your POKéMON in torment\n"
	.string "from PSYCHIC moves…$"

BattleFrontier_BattlePyramidLobby_Text_HintRock_hns:
	.string "I see ROCK-type POKéMON…\p"
	.string "…And, I see your POKéMON suffering\n"
	.string "from ROCK moves…$"

BattleFrontier_BattlePyramidLobby_Text_HintFighting_hns:
	.string "I see FIGHTING-type POKéMON…\p"
	.string "…And, I see your POKéMON pummeled\n"
	.string "by FIGHTING moves…$"

BattleFrontier_BattlePyramidLobby_Text_HintWeather_hns:
	.string "RAIN DANCE… SUNNY DAY…\n"
	.string "SANDSTORM… HAIL…\p"
	.string "I see POKéMON that become stronger\n"
	.string "with the weather…\p"
	.string "…And, I see your POKéMON confounded\n"
	.string "by different types of moves…$"

BattleFrontier_BattlePyramidLobby_Text_HintBug_hns:
	.string "I see BUG-type POKéMON…\p"
	.string "…And, I see your POKéMON suffering\n"
	.string "from different kinds of attacks…$"

BattleFrontier_BattlePyramidLobby_Text_HintDark_hns:
	.string "I see DARK-type POKéMON…\p"
	.string "…And, I see your POKéMON suffering\n"
	.string "from DARK-type moves…$"

BattleFrontier_BattlePyramidLobby_Text_HintWater_hns:
	.string "I see WATER-type POKéMON…\p"
	.string "…And, I see your POKéMON suffering\n"
	.string "from WATER-type moves…$"

BattleFrontier_BattlePyramidLobby_Text_HintGhost_hns:
	.string "I see GHOST-type POKéMON…\p"
	.string "…And, I see your POKéMON suffering\n"
	.string "from GHOST-type moves…$"

BattleFrontier_BattlePyramidLobby_Text_HintSteel_hns:
	.string "I see STEEL-type POKéMON…\p"
	.string "…And, I see your POKéMON suffering\n"
	.string "from enormously powerful moves…$"

BattleFrontier_BattlePyramidLobby_Text_HintFlyingDragon_hns:
	.string "I see flying POKéMON…\p"
	.string "…And, I see your POKéMON suffering\n"
	.string "from enormously powerful moves…$"

BattleFrontier_BattlePyramidLobby_Text_HintStoneEvolve_hns:
	.string "I see those that have evolved from\n"
	.string "the power of stones…\p"
	.string "I also sense fire, water,\n"
	.string "and electricity…\p"
	.string "…And, I see your POKéMON suffering\n"
	.string "from those three powers…$"

BattleFrontier_BattlePyramidLobby_Text_HintNormal_hns:
	.string "I see NORMAL-type POKéMON…\p"
	.string "…And, I see your POKéMON suffering\n"
	.string "from enormously powerful moves…$"

BattleFrontier_BattlePyramidLobby_Text_BelieveMyFortunesOrNot_hns:
	.string "Whether you believe my fortunes\n"
	.string "or not, the choice is yours…\p"
	.string "The future can be changed anytime…\n"
	.string "I wish you safe passage…$"

BattleFrontier_BattlePyramidLobby_Text_TrainersNoticeRunning_hns:
	.string "Did you know?\p"
	.string "If you run fast, TRAINERS may notice\n"
	.string "and come after you for a battle.\p"
	.string "So, if you want to avoid TRAINERS,\n"
	.string "don't catch their eyes, but sneak\l"
	.string "cautiously and quietly past them.$"

BattleFrontier_BattlePyramidLobby_Text_LostLotOfItems_hns:
	.string "Awaaaaaaarrrrgh!\p"
	.string "I had a whole lot of items, but I lost\n"
	.string "them all when I lost!\p"
	.string "Awaaaaaaarrrrgh!$"

BattleFrontier_BattlePyramidLobby_Text_YouveDefeatedPyramidKing_hns:
	.string "Welcome back!\n"
	.string "You've done the unthinkable!\p"
	.string "You've defeated the PYRAMID KING\n"
	.string "and conquered the BATTLE PYRAMID!$"

BattleFrontier_BattlePyramidLobby_Text_GiveYouTheseBattlePoints_hns:
	.string "Young explorer!\n"
	.string "In commendation of your courage,\l"
	.string "we give you these Battle Point(s)!$"

BattleFrontier_BattlePyramidLobby_Text_RulesAreListed_hns:
	.string "The Battle Quest rules are listed.$"

BattleFrontier_BattlePyramidLobby_Text_ReadWhichHeading_hns:
	.string "Which heading do you want to read?$"

BattleFrontier_BattlePyramidLobby_Text_ExplainMonRules_hns:
	.string "When the PYRAMID is conquered,\n"
	.string "the wild POKéMON that appear in it\l"
	.string "are replaced by different kinds.\p"
	.string "Explore, observe, and learn what kinds\n"
	.string "of wild POKéMON you may encounter.$"

BattleFrontier_BattlePyramidLobby_Text_ExplainTrainerRules_hns:
	.string "TRAINERS are lying in wait for you\n"
	.string "inside the PYRAMID.\p"
	.string "On each floor, there are up to\n"
	.string "eight TRAINERS.\p"
	.string "When you defeat a TRAINER, you will\n"
	.string "get a helpful hint for your adventure.$"

BattleFrontier_BattlePyramidLobby_Text_ExplainMazeRules_hns:
	.string "The mazes in the PYRAMID rearrange\n"
	.string "themselves every time you enter it.\p"
	.string "The mazes are poorly lit.\n"
	.string "You must advance with caution.\p"
	.string "The light grows brighter whenever you\n"
	.string "defeat a wild POKéMON or a TRAINER.$"

BattleFrontier_BattlePyramidLobby_Text_ExplainBagRules_hns:
	.string "The BATTLE BAG serves as your BAG\n"
	.string "while in the PYRAMID.\p"
	.string "There are two separate BATTLE BAGS--\n"
	.string "one each for the Level 50 and\l"
	.string "Open Level adventures.\p"
	.string "They each can hold up to 99 pieces\n"
	.string "of ten kinds of items.\p"
	.string "The contents of the BATTLE BAG are\n"
	.string "lost if you fail in your quest.$"

