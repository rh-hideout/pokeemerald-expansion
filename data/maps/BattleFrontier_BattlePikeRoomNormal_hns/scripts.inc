BattleFrontier_BattlePikeRoomNormal_hns_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, BattleFrontier_BattlePikeRoom_OnResume
	map_script MAP_SCRIPT_ON_TRANSITION, BattleFrontier_BattlePikeRoom_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleFrontier_BattlePikeRoomNormal_OnFrame_hns
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, BattleFrontier_BattlePikeRoom_OnWarp
	.byte 0

BattleFrontier_BattlePikeRoomNormal_OnFrame_hns:
	map_script_2 VAR_TEMP_0, 0, BattleFrontier_BattlePikeRoomNormal_EventScript_EnterRoom_hns
	.2byte 0

BattleFrontier_BattlePikeRoomNormal_EventScript_EnterRoom_hns::
	setvar VAR_TEMP_0, 1
	pike_getroomtype
	switch VAR_RESULT
	case PIKE_ROOM_SINGLE_BATTLE, BattleFrontier_BattlePikeRoomNormal_EventScript_EnterSingleBattleRoom_hns
	case PIKE_ROOM_HEAL_FULL, BattleFrontier_BattlePikeRoomNormal_EventScript_EnterFullHealRoom_hns
	case PIKE_ROOM_STATUS, BattleFrontier_BattlePikeRoomNormal_EventScript_EnterStatusRoom_hns
	case PIKE_ROOM_HARD_BATTLE, BattleFrontier_BattlePikeRoomNormal_EventScript_EnterHardBattleRoom_hns
	case PIKE_ROOM_DOUBLE_BATTLE, BattleFrontier_BattlePikeRoomNormal_EventScript_EnterDoubleBattleRoom_hns
	case PIKE_ROOM_BRAIN, BattleFrontier_BattlePikeRoomNormal_EventScript_EnterBrainRoom_hns
	end

BattleFrontier_BattlePikeRoomNormal_EventScript_EnterSingleBattleRoom_hns::
	lockall
	delay 16
	applymovement LOCALID_PIKE_ROOM_NPC_1, BattleFrontier_BattlePikeRoomNormal_Movement_ApproachPlayer_hns
	waitmovement 0
	pike_gettrainerintro 0
	msgbox gStringVar4, MSGBOX_DEFAULT
	waitmessage
	closemessage
	releaseall
	dofacilitytrainerbattle FACILITY_BATTLE_PIKE_SINGLE
	waitstate
	switch VAR_RESULT
	case 1, BattleFrontier_BattlePikeRoomNormal_EventScript_WonSingleBattle_hns
BattleFrontier_BattlePikeRoomNormal_EventScript_WarpToLobbyLost_hns::
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, CHALLENGE_STATUS_LOST
	warp MAP_BATTLE_FRONTIER_BATTLE_PIKE_LOBBY, 5, 6
	waitstate
	end

BattleFrontier_BattlePikeRoomNormal_EventScript_WonSingleBattle_hns::
	applymovement LOCALID_PIKE_ROOM_NPC_1, BattleFrontier_BattlePikeRoomNormal_Movement_NPCExit_hns
	waitmovement 0
	end

BattleFrontier_BattlePikeRoomNormal_EventScript_EnterHardBattleRoom_hns::
	lockall
	delay 16
	msgbox BattleFrontier_BattlePikeRoomNormal_Text_BattleSomewhatToughTrainer_hns, MSGBOX_DEFAULT
	waitmessage
	closemessage
	applymovement LOCALID_PIKE_ROOM_NPC_1, BattleFrontier_BattlePikeRoomNormal_Movement_ApproachPlayer_hns
	waitmovement 0
	pike_gettrainerintro 0
	msgbox gStringVar4, MSGBOX_DEFAULT
	waitmessage
	closemessage
	releaseall
	dofacilitytrainerbattle FACILITY_BATTLE_PIKE_SINGLE
	waitstate
	switch VAR_RESULT
	case 1, BattleFrontier_BattlePikeRoomNormal_EventScript_WonHardBattle_hns
	goto BattleFrontier_BattlePikeRoomNormal_EventScript_WarpToLobbyLost_hns
	end

BattleFrontier_BattlePikeRoomNormal_EventScript_WonHardBattle_hns::
	applymovement LOCALID_PIKE_ROOM_NPC_1, BattleFrontier_BattlePikeRoomNormal_Movement_NPCExit_hns
	waitmovement 0
	applymovement LOCALID_PIKE_ROOM_NPC_2, BattleFrontier_BattlePikeRoomNormal_Movement_HealNPCApproachPlayer_hns
	waitmovement 0
	lock
	faceplayer
	msgbox BattleFrontier_BattlePikeRoomNormal_Text_RestoreToFullHealth_hns, MSGBOX_DEFAULT
	playfanfare MUS_HEAL
	waitfanfare
	special HealPlayerParty
	msgbox BattleFrontier_BattlePikeRoomNormal_Text_EnjoyRestOfChallenge_hns2_hns, MSGBOX_DEFAULT
	closemessage
	release
	applymovement LOCALID_PIKE_ROOM_NPC_2, BattleFrontier_BattlePikeRoomNormal_Movement_NPCExit_hns
	waitmovement 0
	end

BattleFrontier_BattlePikeRoomNormal_EventScript_EnterBrainRoom_hns::
	delay 22
	lockall
	applymovement LOCALID_PIKE_ROOM_NPC_2, BattleFrontier_BattlePikeRoomNormal_Movement_PreQueenHealNPCApproachPlayer_hns
	waitmovement 0
	pike_prequeenheal
	switch VAR_RESULT
	case 0, BattleFrontier_BattlePikeRoomNormal_EventScript_PreQueenNoHeal_hns
	case 1, BattleFrontier_BattlePikeRoomNormal_EventScript_PreQueenHealOneMon_hns
	case 2, BattleFrontier_BattlePikeRoomNormal_EventScript_PreQueenHealTwoMons_hns

BattleFrontier_BattlePikeRoomNormal_EventScript_LucyEnter_hns::
	msgbox BattleFrontier_BattlePikeRoomNormal_Text_ShallFetchOurMaster_hns, MSGBOX_DEFAULT
	closemessage
	special SpawnCameraObject
	applymovement LOCALID_CAMERA, BattleFrontier_BattlePikeRoomNormal_Movement_CameraPanUp_hns
	applymovement LOCALID_PIKE_ROOM_NPC_2, BattleFrontier_BattlePikeRoomNormal_Movement_HealNPCExit_hnsForLucy_hns
	waitmovement 0
	playse SE_PIKE_CURTAIN_CLOSE
	call BattleFrontier_BattlePikeRoomNormal_EventScript_SetCurtainTilesLittleClosed_hns
	delay 4
	call BattleFrontier_BattlePikeRoomNormal_EventScript_SetCurtainTilesMostlyClosed_hns
	delay 4
	call BattleFrontier_BattlePikeRoomNormal_EventScript_SetCurtainTilesClosed_hns
	delay 4
	waitse
	delay 60
	playse SE_PIKE_CURTAIN_OPEN
	delay 65
	call BattleFrontier_BattlePikeRoomNormal_EventScript_SetCurtainTilesMostlyClosed_hns
	showobjectat LOCALID_PIKE_ROOM_NPC_1, MAP_BATTLE_FRONTIER_BATTLE_PIKE_ROOM_NORMAL
	delay 4
	call BattleFrontier_BattlePikeRoomNormal_EventScript_SetCurtainTilesLittleClosed_hns
	delay 4
	call BattleFrontier_BattlePikeRoomNormal_EventScript_SetCurtainTilesOpen_hns
	waitse
	applymovement LOCALID_PIKE_ROOM_NPC_1, BattleFrontier_BattlePikeRoomNormal_Movement_LucyEnter_hns
	waitmovement 0
	pike_getbrainstatus
	switch VAR_RESULT
	case FRONTIER_BRAIN_GOLD, BattleFrontier_BattlePikeRoomNormal_EventScript_IntroLucyGold_hns
	case FRONTIER_BRAIN_STREAK, BattleFrontier_BattlePikeRoomNormal_EventScript_BattleLucySilver_hns
	case FRONTIER_BRAIN_STREAK_LONG, BattleFrontier_BattlePikeRoomNormal_EventScript_BattleLucyGold_hns
	frontier_get FRONTIER_DATA_HEARD_BRAIN_SPEECH
	goto_if_ne VAR_RESULT, FALSE, BattleFrontier_BattlePikeRoomNormal_EventScript_BattleLucySilver_hns
	msgbox BattleFrontier_BattlePikeRoomNormal_Text_ImThePikeQueen_hns, MSGBOX_DEFAULT
	frontier_set FRONTIER_DATA_HEARD_BRAIN_SPEECH
BattleFrontier_BattlePikeRoomNormal_EventScript_BattleLucySilver_hns::
	msgbox BattleFrontier_BattlePikeRoomNormal_Text_HopeYouDidntUseUpLuck_hns, MSGBOX_DEFAULT
	call BattleFrontier_BattlePikeRoomNormal_EventScript_DoPikeQueenBattle_hns
	goto_if_eq VAR_RESULT, 1, BattleFrontier_BattlePikeRoomNormal_EventScript_DefeatedLucy_hnsSilver_hns
	goto BattleFrontier_BattlePikeRoomNormal_EventScript_WarpToLobbyLost_hns

BattleFrontier_BattlePikeRoomNormal_EventScript_DefeatedLucy_hnsSilver_hns::
	frontier_getsymbols
	goto_if_ne VAR_RESULT, 0, BattleFrontier_BattlePikeRoomNormal_EventScript_DefeatedLucy_hns
	msgbox BattleFrontier_BattlePikeRoomNormal_Text_LucyShowMeFrontierPass_hns, MSGBOX_DEFAULT
	waitmessage
	playfanfare MUS_OBTAIN_SYMBOL
	message BattleFrontier_BattlePikeRoomNormal_Text_ReceivedLuckSymbol_hns
	waitmessage
	waitfanfare
	frontier_givesymbol
	msgbox BattleFrontier_BattlePikeRoomNormal_Text_AllThereIsDisappear_hns, MSGBOX_DEFAULT
	closemessage
	goto BattleFrontier_BattlePikeRoomNormal_EventScript_DefeatedLucy_hns

BattleFrontier_BattlePikeRoomNormal_EventScript_IntroLucyGold_hns::
	frontier_get FRONTIER_DATA_HEARD_BRAIN_SPEECH
	goto_if_ne VAR_RESULT, FALSE, BattleFrontier_BattlePikeRoomNormal_EventScript_BattleLucyGold_hns
	msgbox BattleFrontier_BattlePikeRoomNormal_Text_LucyYouAgain_hns, MSGBOX_DEFAULT
	frontier_set FRONTIER_DATA_HEARD_BRAIN_SPEECH
BattleFrontier_BattlePikeRoomNormal_EventScript_BattleLucyGold_hns::
	msgbox BattleFrontier_BattlePikeRoomNormal_Text_NowComeOn_hns, MSGBOX_DEFAULT
	call BattleFrontier_BattlePikeRoomNormal_EventScript_DoPikeQueenBattle_hns
	goto_if_eq VAR_RESULT, 1, BattleFrontier_BattlePikeRoomNormal_EventScript_DefeatedLucy_hnsGold_hns
	goto BattleFrontier_BattlePikeRoomNormal_EventScript_WarpToLobbyLost_hns

BattleFrontier_BattlePikeRoomNormal_EventScript_DefeatedLucy_hnsGold_hns::
	frontier_getsymbols
	goto_if_eq VAR_RESULT, 2, BattleFrontier_BattlePikeRoomNormal_EventScript_DefeatedLucy_hns
	msgbox BattleFrontier_BattlePikeRoomNormal_Text_LucyFrontierPass_hns, MSGBOX_DEFAULT
	waitmessage
	playfanfare MUS_OBTAIN_SYMBOL
	message BattleFrontier_BattlePikeRoomNormal_Text_LuckSymbolTookGoldenShine_hns
	waitmessage
	waitfanfare
	frontier_givesymbol
	msgbox BattleFrontier_BattlePikeRoomNormal_Text_IWontForget_hns, MSGBOX_DEFAULT
	closemessage
	goto BattleFrontier_BattlePikeRoomNormal_EventScript_DefeatedLucy_hns
	end

BattleFrontier_BattlePikeRoomNormal_EventScript_DefeatedLucy_hns::
	applymovement LOCALID_PIKE_ROOM_NPC_1, BattleFrontier_BattlePikeRoomNormal_Movement_LucyMoveAside_hns
	waitmovement 0
	applymovement LOCALID_PLAYER, BattleFrontier_BattlePikeRoomNormal_Movement_PlayerWalkUp2_hns
	waitmovement 0
	pike_get PIKE_DATA_WIN_STREAK
	addvar VAR_RESULT, 1
	pike_set PIKE_DATA_WIN_STREAK, VAR_RESULT
	call BattleFrontier_BattlePikeRoom_EventScript_WarpToFinalRoom
	waitstate
	end

BattleFrontier_BattlePikeRoomNormal_EventScript_PreQueenNoHeal_hns::
	msgbox BattleFrontier_BattlePikeRoomNormal_Text_ChoseRoomNoHeal_hns, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePikeRoomNormal_EventScript_LucyEnter_hns
	end

BattleFrontier_BattlePikeRoomNormal_EventScript_PreQueenHealOneMon_hns::
	msgbox BattleFrontier_BattlePikeRoomNormal_Text_ChoseRoomHealOne_hns, MSGBOX_DEFAULT
	playfanfare MUS_HEAL
	waitfanfare
	goto BattleFrontier_BattlePikeRoomNormal_EventScript_LucyEnter_hns
	end

BattleFrontier_BattlePikeRoomNormal_EventScript_PreQueenHealTwoMons_hns::
	msgbox BattleFrontier_BattlePikeRoomNormal_Text_ChoseRoomHealTwo_hns, MSGBOX_DEFAULT
	playfanfare MUS_HEAL
	waitfanfare
	goto BattleFrontier_BattlePikeRoomNormal_EventScript_LucyEnter_hns
	end

BattleFrontier_BattlePikeRoomNormal_EventScript_EnterFullHealRoom_hns::
	lockall
	delay 16
	applymovement LOCALID_PIKE_ROOM_NPC_1, BattleFrontier_BattlePikeRoomNormal_Movement_ApproachPlayer_hns
	waitmovement 0
	message BattleFrontier_BattlePikeRoomNormal_Text_WillRestoreToFullHealth_hns
	waitmessage
	playfanfare MUS_HEAL
	waitfanfare
	special HealPlayerParty
	msgbox BattleFrontier_BattlePikeRoomNormal_Text_EnjoyRestOfChallenge_hns, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PIKE_ROOM_NPC_1, BattleFrontier_BattlePikeRoomNormal_Movement_NPCExit_hns
	waitmovement 0
	releaseall
	end

BattleFrontier_BattlePikeRoomNormal_EventScript_EnterDoubleBattleRoom_hns::
	lockall
	delay 16
	applymovement LOCALID_PIKE_ROOM_NPC_1, BattleFrontier_BattlePikeRoomNormal_Movement_Trainer1WalkRight_hns
	applymovement LOCALID_PIKE_ROOM_NPC_2, BattleFrontier_BattlePikeRoomNormal_Movement_Trainer2WalkLeft_hns
	waitmovement 0
	applymovement LOCALID_PIKE_ROOM_NPC_1, BattleFrontier_BattlePikeRoomNormal_Movement_DoubleTrainersWalkDown_hns
	applymovement LOCALID_PIKE_ROOM_NPC_2, BattleFrontier_BattlePikeRoomNormal_Movement_DoubleTrainersWalkDown_hns
	waitmovement 0
	applymovement LOCALID_PIKE_ROOM_NPC_1, BattleFrontier_BattlePikeRoomNormal_Movement_Trainer1FacePlayer_hns
	applymovement LOCALID_PIKE_ROOM_NPC_2, BattleFrontier_BattlePikeRoomNormal_Movement_Trainer2FacePlayer_hns
	waitmovement 0
	applymovement LOCALID_PLAYER, BattleFrontier_BattlePikeRoomNormal_Movement_PlayerFaceTrainer1_hns
	waitmovement 0
	pike_gettrainerintro 0
	msgbox gStringVar4, MSGBOX_DEFAULT
	closemessage
	delay 16
	applymovement LOCALID_PLAYER, BattleFrontier_BattlePikeRoomNormal_Movement_PlayerFaceTrainer2_hns
	waitmovement 0
	pike_gettrainerintro 1
	msgbox gStringVar4, MSGBOX_DEFAULT
	closemessage
	dofacilitytrainerbattle FACILITY_BATTLE_PIKE_DOUBLE
	waitstate
	switch VAR_RESULT
	case 1, BattleFrontier_BattlePikeRoomNormal_EventScript_WonDoubleBattle_hns
	goto BattleFrontier_BattlePikeRoomNormal_EventScript_WarpToLobbyLost_hns
	end

BattleFrontier_BattlePikeRoomNormal_EventScript_WonDoubleBattle_hns::
	applymovement LOCALID_PLAYER, BattleFrontier_BattlePikeRoomNormal_Movement_PlayerFaceTrainer2_hns
	waitmovement 0
	applymovement LOCALID_PIKE_ROOM_NPC_1, BattleFrontier_BattlePikeRoomNormal_Movement_Trainer1Exit_hns
	waitmovement 0
	applymovement LOCALID_PIKE_ROOM_NPC_2, BattleFrontier_BattlePikeRoomNormal_Movement_Trainer2Exit_hns
	waitmovement 0
	applymovement LOCALID_PLAYER, BattleFrontier_BattlePikeRoomNormal_Movement_PlayerFaceUp_hns
	waitmovement 0
	end

BattleFrontier_BattlePikeRoomNormal_EventScript_EnterStatusRoom_hns::
	lockall
	message BattleFrontier_BattlePikeRoomNormal_Text_WatchOut_hns
	applymovement LOCALID_PIKE_ROOM_NPC_2, BattleFrontier_BattlePikeRoomNormal_Movement_MonApproachPlayer_hns
	waitmovement 0
	pike_getstatusmon
	copyvar VAR_0x8004, VAR_RESULT
	call_if_eq VAR_0x8004, PIKE_STATUSMON_KIRLIA, BattleFrontier_BattlePikeRoomNormal_EventScript_KirliaAttack_hns
	call_if_eq VAR_0x8004, PIKE_STATUSMON_DUSCLOPS, BattleFrontier_BattlePikeRoomNormal_EventScript_DusclopsAttack_hns
	msgbox BattleFrontier_BattlePikeRoomNormal_Text_AttacksWhenStartled_hns, MSGBOX_DEFAULT
	closemessage
	releaseall
	end

BattleFrontier_BattlePikeRoomNormal_EventScript_KirliaAttack_hns::
	msgbox BattleFrontier_BattlePikeRoomNormal_Text_KirliaStop_hns, MSGBOX_DEFAULT
	closemessage
	waitse
	playmoncry SPECIES_KIRLIA, CRY_MODE_NORMAL
	waitmoncry
	pike_getstatus
	call_if_eq VAR_RESULT, PIKE_STATUS_TOXIC, BattleFrontier_BattlePikeRoomNormal_EventScript_KirliaUsedToxic_hns
	call_if_eq VAR_RESULT, PIKE_STATUS_BURN, BattleFrontier_BattlePikeRoomNormal_EventScript_KirliaUsedWillOWisp_hns
	call_if_eq VAR_RESULT, PIKE_STATUS_PARALYSIS, BattleFrontier_BattlePikeRoomNormal_EventScript_KirliaUsedThunderWave_hns
	call_if_eq VAR_RESULT, PIKE_STATUS_SLEEP, BattleFrontier_BattlePikeRoomNormal_EventScript_KirliaUsedHypnosis_hns
	pike_flashscreen
	waitstate
	applymovement LOCALID_PIKE_ROOM_NPC_1, BattleFrontier_BattlePikeRoomNormal_Movement_NPCApproachMon_hns
	waitmovement 0
	applymovement LOCALID_PIKE_ROOM_NPC_2, BattleFrontier_BattlePikeRoomNormal_Movement_MonFaceNPC_hns
	waitmovement 0
	waitse
	playmoncry SPECIES_KIRLIA, CRY_MODE_NORMAL
	waitmoncry
	msgbox BattleFrontier_BattlePikeRoomNormal_Text_ThatsEnough_hns, MSGBOX_DEFAULT
	waitse
	playmoncry SPECIES_KIRLIA, CRY_MODE_NORMAL
	waitmoncry
	closemessage
	applymovement LOCALID_PIKE_ROOM_NPC_2, BattleFrontier_BattlePikeRoomNormal_Movement_MonMoveAside_hns
	applymovement LOCALID_PIKE_ROOM_NPC_1, BattleFrontier_BattlePikeRoomNormal_Movement_StatusNPCApproachPlayer_hns
	waitmovement 0
	msgbox BattleFrontier_BattlePikeRoomNormal_Text_ApologizeForKirlia_hns, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePikeRoomNormal_EventScript_DusclopsAttack_hns::
	msgbox BattleFrontier_BattlePikeRoomNormal_Text_DusclopsStop_hns, MSGBOX_DEFAULT
	closemessage
	waitse
	playmoncry SPECIES_DUSCLOPS, CRY_MODE_NORMAL
	waitmoncry
	pike_getstatus
	call_if_eq VAR_RESULT, PIKE_STATUS_FREEZE, BattleFrontier_BattlePikeRoomNormal_EventScript_DusclopsUsedIceBeam_hns
	call_if_eq VAR_RESULT, PIKE_STATUS_BURN, BattleFrontier_BattlePikeRoomNormal_EventScript_DusclopsUsedWillOWisp_hns
	pike_flashscreen
	waitstate
	applymovement LOCALID_PIKE_ROOM_NPC_1, BattleFrontier_BattlePikeRoomNormal_Movement_NPCApproachMon_hns
	waitmovement 0
	applymovement LOCALID_PIKE_ROOM_NPC_2, BattleFrontier_BattlePikeRoomNormal_Movement_MonFaceNPC_hns
	waitmovement 0
	waitse
	playmoncry SPECIES_DUSCLOPS, CRY_MODE_NORMAL
	waitmoncry
	msgbox BattleFrontier_BattlePikeRoomNormal_Text_ThatsEnough_hns, MSGBOX_DEFAULT
	waitse
	playmoncry SPECIES_DUSCLOPS, CRY_MODE_NORMAL
	waitmoncry
	closemessage
	applymovement LOCALID_PIKE_ROOM_NPC_2, BattleFrontier_BattlePikeRoomNormal_Movement_MonMoveAside_hns
	applymovement LOCALID_PIKE_ROOM_NPC_1, BattleFrontier_BattlePikeRoomNormal_Movement_StatusNPCApproachPlayer_hns
	waitmovement 0
	msgbox BattleFrontier_BattlePikeRoomNormal_Text_ApologizeForDusclops_hns, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePikeRoomNormal_EventScript_KirliaUsedToxic_hns::
	message BattleFrontier_BattlePikeRoomNormal_Text_KirliaUsedToxic_hns
	waitmessage
	return

BattleFrontier_BattlePikeRoomNormal_EventScript_KirliaUsedWillOWisp_hns::
	message BattleFrontier_BattlePikeRoomNormal_Text_KirliaUsedWillOWisp_hns
	waitmessage
	return

BattleFrontier_BattlePikeRoomNormal_EventScript_KirliaUsedThunderWave_hns::
	message BattleFrontier_BattlePikeRoomNormal_Text_KirliaUsedThunderWave_hns
	waitmessage
	return

BattleFrontier_BattlePikeRoomNormal_EventScript_KirliaUsedHypnosis_hns::
	message BattleFrontier_BattlePikeRoomNormal_Text_KirliaUsedHypnosis_hns
	waitmessage
	return

BattleFrontier_BattlePikeRoomNormal_EventScript_DusclopsUsedIceBeam_hns::
	message BattleFrontier_BattlePikeRoomNormal_Text_DusclopsUsedIceBeam_hns
	waitmessage
	return

BattleFrontier_BattlePikeRoomNormal_EventScript_DusclopsUsedWillOWisp_hns::
	message BattleFrontier_BattlePikeRoomNormal_Text_DusclopsUsedWillOWisp_hns
	waitmessage
	return

BattleFrontier_BattlePikeRoomNormal_EventScript_DoPikeQueenBattle_hns::
	closemessage
	applymovement LOCALID_PLAYER, BattleFrontier_BattlePikeRoomNormal_Movement_PlayerWalkUp2_hns
	waitmovement 0
	dofacilitytrainerbattle FACILITY_BATTLE_PIKE_SINGLE
	waitstate
	return

BattleFrontier_BattlePikeRoomNormal_Movement_ApproachPlayer_hns:
	walk_down
	walk_down
	step_end

BattleFrontier_BattlePikeRoomNormal_Movement_NPCExit_hns:
	walk_up
	walk_up
	walk_up
	set_invisible
	walk_up
	step_end

BattleFrontier_BattlePikeRoomNormal_Movement_HealNPCExit_hns:
	walk_up
	set_invisible
	walk_up
	step_end

BattleFrontier_BattlePikeRoomNormal_Movement_NPCApproachMon_hns:
	walk_down
	step_end

BattleFrontier_BattlePikeRoomNormal_Movement_StatusNPCApproachPlayer_hns:
	walk_down
	face_left
	delay_16
	delay_16
	face_down
	step_end

BattleFrontier_BattlePikeRoomNormal_Movement_MonApproachPlayer_hns:
	walk_fast_down
	walk_fast_right
	walk_fast_right
	walk_fast_down
	walk_fast_left
	face_down
	step_end

BattleFrontier_BattlePikeRoomNormal_Movement_MonFaceNPC_hns:
	face_up
	step_end

BattleFrontier_BattlePikeRoomNormal_Movement_MonMoveAside_hns:
	walk_left
BattleFrontier_BattlePikeRoomNormal_Movement_MonFaceRight_hns:
	face_right
	step_end

BattleFrontier_BattlePikeRoomNormal_Movement_HealNPCApproachPlayer_hns:
	walk_down
	walk_down
	walk_right
	face_down
	step_end

BattleFrontier_BattlePikeRoomNormal_Movement_PlayerFaceTrainer1_hns:
	face_left
	step_end

BattleFrontier_BattlePikeRoomNormal_Movement_PlayerFaceTrainer2_hns:
	face_right
	step_end

BattleFrontier_BattlePikeRoomNormal_Movement_PlayerFaceUp_hns:
	face_up
	step_end

BattleFrontier_BattlePikeRoomNormal_Movement_Trainer1WalkRight_hns:
	walk_right
	step_end

BattleFrontier_BattlePikeRoomNormal_Movement_Trainer2WalkLeft_hns:
	walk_left
	step_end

BattleFrontier_BattlePikeRoomNormal_Movement_DoubleTrainersWalkDown_hns:
	walk_down
	walk_down
	step_end

BattleFrontier_BattlePikeRoomNormal_Movement_Trainer1FacePlayer_hns:
	face_right
	step_end

BattleFrontier_BattlePikeRoomNormal_Movement_Trainer2FacePlayer_hns:
	face_left
	step_end

BattleFrontier_BattlePikeRoomNormal_Movement_Trainer1Exit_hns:
	walk_up
	walk_up
	walk_up
	walk_right
	walk_up
	set_invisible
	walk_up
	step_end

BattleFrontier_BattlePikeRoomNormal_Movement_Trainer2Exit_hns:
	walk_up
	walk_up
	walk_up
	walk_left
	walk_up
	set_invisible
	walk_up
	step_end

@ For approaching Lucy and exiting room after defeating Lucy
BattleFrontier_BattlePikeRoomNormal_Movement_PlayerWalkUp2_hns:
	walk_up
	walk_up
	step_end

BattleFrontier_BattlePikeRoomNormal_Movement_PreQueenHealNPCApproachPlayer_hns:
	walk_down
	walk_down
	step_end

BattleFrontier_BattlePikeRoomNormal_Movement_HealNPCExit_hnsForLucy_hns:
	walk_up
	walk_up
	walk_up
	set_invisible
	step_end

BattleFrontier_BattlePikeRoomNormal_Movement_LucyEnter_hns:
	set_visible
	walk_down
	step_end

BattleFrontier_BattlePikeRoomNormal_Movement_LucyMoveAside_hns:
	walk_left
	face_right
	step_end

BattleFrontier_BattlePikeRoomNormal_EventScript_NPC_hns::
	pike_getroomtype
	switch VAR_RESULT
	case PIKE_ROOM_NPC, BattleFrontier_BattlePikeRoomNormal_EventScript_NormalNPC_hns
	case PIKE_ROOM_STATUS, BattleFrontier_BattlePikeRoomNormal_EventScript_StatusNPC_hns
	case PIKE_ROOM_HEAL_PART, BattleFrontier_BattlePikeRoomNormal_EventScript_HealNPC_hns
BattleFrontier_BattlePikeRoomNormal_EventScript_NormalNPC_hns::
	lock
	faceplayer
	pike_getnpcmsg
	msgbox gStringVar4, MSGBOX_DEFAULT
	waitmessage
	closemessage
	release
	end

BattleFrontier_BattlePikeRoomNormal_EventScript_StatusNPC_hns::
	lock
	faceplayer
	msgbox BattleFrontier_BattlePikeRoomNormal_Text_ApologizeHopeMonsAreFine_hns, MSGBOX_DEFAULT
	closemessage
	release
	end

BattleFrontier_BattlePikeRoomNormal_EventScript_HealNPC_hns::
	pike_healonetwomons
	call_if_eq VAR_RESULT, 2, BattleFrontier_BattlePikeRoomNormal_EventScript_WillRestoreTwoMons_hns
	call_if_eq VAR_RESULT, 1, BattleFrontier_BattlePikeRoomNormal_EventScript_WillRestoreOneMon_hns
	playfanfare MUS_HEAL
	waitfanfare
	msgbox BattleFrontier_BattlePikeRoomNormal_Text_BestOfLuckFarewell_hns, MSGBOX_DEFAULT
	closemessage
	release
	applymovement LOCALID_PIKE_ROOM_NPC_1, BattleFrontier_BattlePikeRoomNormal_Movement_HealNPCExit_hns
	waitmovement 0
	end

BattleFrontier_BattlePikeRoomNormal_EventScript_WillRestoreOneMon_hns::
	lock
	faceplayer
	msgbox BattleFrontier_BattlePikeRoomNormal_Text_WillRestoreOneMon_hns, MSGBOX_DEFAULT
	closemessage
	return

BattleFrontier_BattlePikeRoomNormal_EventScript_WillRestoreTwoMons_hns::
	lock
	faceplayer
	msgbox BattleFrontier_BattlePikeRoomNormal_Text_WillRestoreTwoMons_hns, MSGBOX_DEFAULT
	closemessage
	return

@ Dusclops or Kirlia
BattleFrontier_BattlePikeRoomNormal_EventScript_StatusMon_hns::
	lock
	faceplayer
	msgbox BattleFrontier_BattlePikeRoomNormal_Text_Silence_hns, MSGBOX_DEFAULT
	closemessage
	release
	applymovement LOCALID_PIKE_ROOM_NPC_2, BattleFrontier_BattlePikeRoomNormal_Movement_MonFaceRight_hns
	waitmovement 0
	end

BattleFrontier_BattlePikeRoomNormal_EventScript_SetCurtainTilesMostlyClosed_hns::
	setmetatile 4, 1, METATILE_BattlePike_Curtain_Stage1_Tile0, TRUE
	setmetatile 3, 2, METATILE_BattlePike_Curtain_Stage1_Tile1, TRUE
	setmetatile 4, 2, METATILE_BattlePike_Curtain_Stage1_Tile2, TRUE
	setmetatile 5, 2, METATILE_BattlePike_Curtain_Stage1_Tile3, TRUE
	setmetatile 3, 3, METATILE_BattlePike_Curtain_Stage1_Tile4, TRUE
	setmetatile 4, 3, METATILE_BattlePike_Curtain_Stage1_Tile5, FALSE
	setmetatile 5, 3, METATILE_BattlePike_Curtain_Stage1_Tile6, TRUE
	special DrawWholeMapView
	return

BattleFrontier_BattlePikeRoomNormal_EventScript_SetCurtainTilesLittleClosed_hns::
	setmetatile 4, 1, METATILE_BattlePike_Curtain_Stage2_Tile0, TRUE
	setmetatile 3, 2, METATILE_BattlePike_Curtain_Stage2_Tile1, TRUE
	setmetatile 4, 2, METATILE_BattlePike_Curtain_Stage2_Tile2, TRUE
	setmetatile 5, 2, METATILE_BattlePike_Curtain_Stage2_Tile3, TRUE
	setmetatile 3, 3, METATILE_BattlePike_Curtain_Stage2_Tile4, TRUE
	setmetatile 4, 3, METATILE_BattlePike_Curtain_Stage2_Tile5, FALSE
	setmetatile 5, 3, METATILE_BattlePike_Curtain_Stage2_Tile6, TRUE
	special DrawWholeMapView
	return

BattleFrontier_BattlePikeRoomNormal_EventScript_SetCurtainTilesOpen_hns::
	setmetatile 4, 1, METATILE_BattlePike_Curtain_Stage3_Tile0, TRUE
	setmetatile 3, 2, METATILE_BattlePike_Curtain_Stage3_Tile1, TRUE
	setmetatile 4, 2, METATILE_BattlePike_Curtain_Stage3_Tile2, TRUE
	setmetatile 5, 2, METATILE_BattlePike_Curtain_Stage3_Tile3, TRUE
	setmetatile 3, 3, METATILE_BattlePike_Curtain_Stage3_Tile4, TRUE
	setmetatile 4, 3, METATILE_BattlePike_Curtain_Stage3_Tile5, FALSE
	setmetatile 5, 3, METATILE_BattlePike_Curtain_Stage3_Tile6, TRUE
	special DrawWholeMapView
	return

BattleFrontier_BattlePikeRoomNormal_EventScript_SetCurtainTilesClosed_hns::
	setmetatile 4, 1, METATILE_BattlePike_Curtain_Stage0_Tile0, TRUE
	setmetatile 3, 2, METATILE_BattlePike_Curtain_Stage0_Tile1, TRUE
	setmetatile 4, 2, METATILE_BattlePike_Curtain_Stage0_Tile2, TRUE
	setmetatile 5, 2, METATILE_BattlePike_Curtain_Stage0_Tile3, TRUE
	setmetatile 3, 3, METATILE_BattlePike_Curtain_Stage0_Tile4, TRUE
	setmetatile 4, 3, METATILE_BattlePike_Curtain_Stage0_Tile5, FALSE
	setmetatile 5, 3, METATILE_BattlePike_Curtain_Stage0_Tile6, TRUE
	special DrawWholeMapView
	return

BattleFrontier_BattlePikeRoomNormal_Movement_CameraPanUp_hns:
	walk_up
	walk_up
	step_end

@ Unused
BattleFrontier_BattlePikeRoomNormal_Movement_CameraPanDown_hns:
	walk_down
	walk_down
	step_end

BattleFrontier_BattlePikeRoomNormal_Text_WillRestoreToFullHealth_hns:
	.string "Welcome…\n"
	.string "You must be commended for your luck…\p"
	.string "Your POKéMON shall be restored\n"
	.string "to full health…$"

BattleFrontier_BattlePikeRoomNormal_Text_EnjoyRestOfChallenge_hns:
	.string "I urge you to enjoy the rest of your\n"
	.string "Battle Choice challenge…$"

BattleFrontier_BattlePikeRoomNormal_Text_WillRestoreOneMon_hns:
	.string "Ah, you're a lucky one.\n"
	.string "I'm in somewhat-good spirits now.\p"
	.string "I will restore one of your POKéMON\n"
	.string "to full health.$"

BattleFrontier_BattlePikeRoomNormal_Text_BestOfLuckFarewell_hns:
	.string "The best of luck to you.\n"
	.string "Farewell.$"

@ Seems there was a planned room type where the player could choose to battle and would be healed if they won
@ Possibly replaced/superseded by the hard battle room, which is the same but the battle isnt optional
@ Unused
BattleFrontier_BattlePikeRoomNormal_Text_CareForBattleWillRestoreMons_hns:
	.string "Excuse me…\p"
	.string "Would you care for a battle?\n"
	.string "I'll restore your POKéMON if you win.$"

@ Unused
BattleFrontier_BattlePikeRoomNormal_Text_NowShallWe_hns:
	.string "Very well…\n"
	.string "Now, shall we?$"

@ Unused
BattleFrontier_BattlePikeRoomNormal_Text_HowUnsportingOfYou_hns:
	.string "I see…\n"
	.string "How unsporting of you…$"

@ Unused
BattleFrontier_BattlePikeRoomNormal_Text_WillRestoreMonsAsPromised_hns:
	.string "Magnificent…\p"
	.string "As promised, I shall restore your\n"
	.string "POKéMON to full health.$"

@ Unused
BattleFrontier_BattlePikeRoomNormal_Text_BestOfLuckFarewell_hns2_hns:
	.string "The best of luck to you.\n"
	.string "Farewell.$"

BattleFrontier_BattlePikeRoomNormal_Text_WatchOut_hns:
	.string "Oh, my!\p"
	.string "Watch out!$"

BattleFrontier_BattlePikeRoomNormal_Text_KirliaStop_hns:
	.string "Now, now!\n"
	.string "KIRLIA, stop that!$"

BattleFrontier_BattlePikeRoomNormal_Text_DusclopsStop_hns:
	.string "Now, now!\n"
	.string "DUSCLOPS, stop that!$"

BattleFrontier_BattlePikeRoomNormal_Text_KirliaUsedToxic_hns:
	.string "KIRLIA used TOXIC!$"

BattleFrontier_BattlePikeRoomNormal_Text_KirliaUsedHypnosis_hns:
	.string "KIRLIA used HYPNOSIS!$"

BattleFrontier_BattlePikeRoomNormal_Text_KirliaUsedThunderWave_hns:
	.string "KIRLIA used THUNDER WAVE!$"

BattleFrontier_BattlePikeRoomNormal_Text_KirliaUsedWillOWisp_hns:
	.string "KIRLIA used WILL-O-WISP!$"

BattleFrontier_BattlePikeRoomNormal_Text_DusclopsUsedWillOWisp_hns:
	.string "DUSCLOPS used WILL-O-WISP!$"

BattleFrontier_BattlePikeRoomNormal_Text_DusclopsUsedIceBeam_hns:
	.string "DUSCLOPS used ICE BEAM!$"

BattleFrontier_BattlePikeRoomNormal_Text_ThatsEnough_hns:
	.string "Look here!\n"
	.string "That's quite enough!$"

BattleFrontier_BattlePikeRoomNormal_Text_ApologizeForKirlia_hns:
	.string "I must apologize to you…\p"
	.string "My KIRLIA has a TIMID nature…$"

BattleFrontier_BattlePikeRoomNormal_Text_ApologizeForDusclops_hns:
	.string "I must apologize to you…\p"
	.string "My DUSCLOPS has a TIMID nature…$"

BattleFrontier_BattlePikeRoomNormal_Text_AttacksWhenStartled_hns:
	.string "It attacks without warning if it is\n"
	.string "startled by another person…\p"
	.string "Are you and your POKéMON all right?$"

BattleFrontier_BattlePikeRoomNormal_Text_ApologizeHopeMonsAreFine_hns:
	.string "I do apologize for what happened…\n"
	.string "I do hope your POKéMON are fine.$"

BattleFrontier_BattlePikeRoomNormal_Text_Silence_hns:
	.string "… … … … … …\n"
	.string "… … … … … …$"

BattleFrontier_BattlePikeRoomNormal_Text_BattleSomewhatToughTrainer_hns:
	.string "Welcome…\p"
	.string "Here, we will have you battle\n"
	.string "a somewhat-tough TRAINER…$"

BattleFrontier_BattlePikeRoomNormal_Text_RestoreToFullHealth_hns:
	.string "How wonderful…\p"
	.string "To honor your victory, your POKéMON\n"
	.string "shall be restored to full health…$"

BattleFrontier_BattlePikeRoomNormal_Text_EnjoyRestOfChallenge_hns2_hns:
	.string "I urge you to enjoy the rest of your\n"
	.string "Battle Choice challenge…$"

BattleFrontier_BattlePikeRoomNormal_Text_ImThePikeQueen_hns:
	.string "I am LUCY…\n"
	.string "I am the law here…\l"
	.string "For I am the PIKE QUEEN…\p"
	.string "You already know it, but to advance,\n"
	.string "you must defeat me…\p"
	.string "…I'm not one for idle chatter.\n"
	.string "Hurry. Come on…$"

BattleFrontier_BattlePikeRoomNormal_Text_HopeYouDidntUseUpLuck_hns:
	.string "Your luck…\n"
	.string "I hope you didn't use it all up here…$"

BattleFrontier_BattlePikeRoomNormal_Text_LucyShowMeFrontierPass_hns:
	.string "LUCY: … … … … … …\n"
	.string "Show me your FRONTIER PASS…$"

BattleFrontier_BattlePikeRoomNormal_Text_ReceivedLuckSymbol_hns:
	.string "The Luck Symbol was embossed on\n"
	.string "the FRONTIER PASS!$"

BattleFrontier_BattlePikeRoomNormal_Text_AllThereIsDisappear_hns:
	.string "…That's all there is…\n"
	.string "Disappear already…$"

BattleFrontier_BattlePikeRoomNormal_Text_LucyYouAgain_hns:
	.string "LUCY: …You again…\p"
	.string "… … … … … …\p"
	.string "…I've trampled flowers and braved\n"
	.string "storms to get to where I am…\p"
	.string "I don't feel any compulsion to keep\n"
	.string "losing to the same opponent…\p"
	.string "… … … … … …\n"
	.string "Fine… I'll do it…$"

BattleFrontier_BattlePikeRoomNormal_Text_NowComeOn_hns:
	.string "Now!\n"
	.string "Come on!$"

BattleFrontier_BattlePikeRoomNormal_Text_LucyFrontierPass_hns:
	.string "LUCY: … … … … … …\p"
	.string "…FRONTIER PASS…$"

BattleFrontier_BattlePikeRoomNormal_Text_LuckSymbolTookGoldenShine_hns:
	.string "The Luck Symbol took on\n"
	.string "a golden shine!$"

BattleFrontier_BattlePikeRoomNormal_Text_IWontForget_hns:
	.string "…You, I won't forget…\n"
	.string "…Ever…$"

BattleFrontier_BattlePikeRoomNormal_Text_ChoseRoomNoHeal_hns:
	.string "I welcome you…\p"
	.string "Giggle…\n"
	.string "You seem to be bereft of luck…\p"
	.string "If only you hadn't chosen this room,\n"
	.string "your POKéMON could have been healed…$"

BattleFrontier_BattlePikeRoomNormal_Text_ChoseRoomHealOne_hns:
	.string "I welcome you…\p"
	.string "Since you have chosen this room, I will\n"
	.string "restore one POKéMON to full health…$"

BattleFrontier_BattlePikeRoomNormal_Text_ChoseRoomHealTwo_hns:
	.string "I welcome you…\p"
	.string "Since you have chosen this room, I will\n"
	.string "restore two POKéMON to full health…$"

@ Unused
BattleFrontier_BattlePikeRoomNormal_Text_WillRestoreAllMons_hns:
	.string "I welcome you…\p"
	.string "Giggle…\n"
	.string "You should thank your lucky stars…\p"
	.string "Since you have chosen this room,\n"
	.string "all your POKéMON will be restored…$"

BattleFrontier_BattlePikeRoomNormal_Text_ShallFetchOurMaster_hns:
	.string "I shall go fetch our master…$"

BattleFrontier_BattlePikeRoomNormal_Text_WillRestoreTwoMons_hns:
	.string "Ah, you're a lucky one!\n"
	.string "I'm in good spirits now.\p"
	.string "I will restore two of your POKéMON\n"
	.string "to full health!$"

