# 1 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"

# 2 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
BattleFrontier_BattlePikeRoomNormal_MapScripts::
# 3 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	map_script MAP_SCRIPT_ON_RESUME, BattleFrontier_BattlePikeRoom_OnResume
# 4 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, BattleFrontier_BattlePikeRoom_OnTransition
# 5 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleFrontier_BattlePikeRoomNormal_OnFrame
# 6 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, BattleFrontier_BattlePikeRoom_OnWarp
# 7 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	.byte 0
# 8 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"

# 9 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
BattleFrontier_BattlePikeRoomNormal_OnFrame:
# 10 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	map_script_2 VAR_TEMP_0, 0, BattleFrontier_BattlePikeRoomNormal_EventScript_EnterRoom
# 11 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	.2byte 0
# 12 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"

# 13 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
BattleFrontier_BattlePikeRoomNormal_EventScript_EnterRoom::
# 14 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	setvar VAR_TEMP_0, 1
# 15 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	pike_getroomtype
# 16 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	switch VAR_RESULT
# 17 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	case PIKE_ROOM_SINGLE_BATTLE, BattleFrontier_BattlePikeRoomNormal_EventScript_EnterSingleBattleRoom
# 18 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	case PIKE_ROOM_HEAL_FULL, BattleFrontier_BattlePikeRoomNormal_EventScript_EnterFullHealRoom
# 19 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	case PIKE_ROOM_STATUS, BattleFrontier_BattlePikeRoomNormal_EventScript_EnterStatusRoom
# 20 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	case PIKE_ROOM_HARD_BATTLE, BattleFrontier_BattlePikeRoomNormal_EventScript_EnterHardBattleRoom
# 21 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	case PIKE_ROOM_DOUBLE_BATTLE, BattleFrontier_BattlePikeRoomNormal_EventScript_EnterDoubleBattleRoom
# 22 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	case PIKE_ROOM_BRAIN, BattleFrontier_BattlePikeRoomNormal_EventScript_EnterBrainRoom
# 23 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	end
# 24 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"

# 25 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
BattleFrontier_BattlePikeRoomNormal_EventScript_EnterSingleBattleRoom::
# 26 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	lockall
# 27 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	delay 16
# 28 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	applymovement LOCALID_PIKE_ROOM_NPC_1, BattleFrontier_BattlePikeRoomNormal_Movement_ApproachPlayer
# 29 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	waitmovement 0
# 30 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	pike_gettrainerintro 0
# 31 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	msgbox gStringVar4, MSGBOX_DEFAULT
# 32 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	waitmessage
# 33 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	closemessage
# 34 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	releaseall
# 35 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	setvar VAR_0x8004, SPECIAL_BATTLE_PIKE_SINGLE
# 36 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	setvar VAR_0x8005, 0
# 37 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	special DoSpecialTrainerBattle
# 38 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	waitstate
# 39 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	switch VAR_RESULT
# 40 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	case 1, BattleFrontier_BattlePikeRoomNormal_EventScript_WonSingleBattle
# 41 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
BattleFrontier_BattlePikeRoomNormal_EventScript_WarpToLobbyLost::
# 42 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, CHALLENGE_STATUS_LOST
# 43 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	warp MAP_BATTLE_FRONTIER_BATTLE_PIKE_LOBBY, 5, 6
# 44 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	waitstate
# 45 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	end
# 46 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"

# 47 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
BattleFrontier_BattlePikeRoomNormal_EventScript_WonSingleBattle::
# 48 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	applymovement LOCALID_PIKE_ROOM_NPC_1, BattleFrontier_BattlePikeRoomNormal_Movement_NPCExit
# 49 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	waitmovement 0
# 50 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	end
# 51 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"

# 52 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
BattleFrontier_BattlePikeRoomNormal_EventScript_EnterHardBattleRoom::
# 53 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	lockall
# 54 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	delay 16
# 55 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	msgbox BattleFrontier_BattlePikeRoomNormal_Text_BattleSomewhatToughTrainer, MSGBOX_DEFAULT
# 56 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	waitmessage
# 57 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	closemessage
# 58 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	applymovement LOCALID_PIKE_ROOM_NPC_1, BattleFrontier_BattlePikeRoomNormal_Movement_ApproachPlayer
# 59 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	waitmovement 0
# 60 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	pike_gettrainerintro 0
# 61 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	msgbox gStringVar4, MSGBOX_DEFAULT
# 62 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	waitmessage
# 63 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	closemessage
# 64 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	releaseall
# 65 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	setvar VAR_0x8004, SPECIAL_BATTLE_PIKE_SINGLE
# 66 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	setvar VAR_0x8005, 0
# 67 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	special DoSpecialTrainerBattle
# 68 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	waitstate
# 69 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	switch VAR_RESULT
# 70 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	case 1, BattleFrontier_BattlePikeRoomNormal_EventScript_WonHardBattle
# 71 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	goto BattleFrontier_BattlePikeRoomNormal_EventScript_WarpToLobbyLost
# 72 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	end
# 73 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"

# 74 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
BattleFrontier_BattlePikeRoomNormal_EventScript_WonHardBattle::
# 75 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	applymovement LOCALID_PIKE_ROOM_NPC_1, BattleFrontier_BattlePikeRoomNormal_Movement_NPCExit
# 76 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	waitmovement 0
# 77 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	applymovement LOCALID_PIKE_ROOM_NPC_2, BattleFrontier_BattlePikeRoomNormal_Movement_HealNPCApproachPlayer
# 78 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	waitmovement 0
# 79 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	lock
# 80 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	faceplayer
# 81 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	msgbox BattleFrontier_BattlePikeRoomNormal_Text_RestoreToFullHealth, MSGBOX_DEFAULT
# 82 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	playfanfare MUS_HEAL
# 83 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	waitfanfare
# 84 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	special HealPlayerParty
# 85 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	msgbox BattleFrontier_BattlePikeRoomNormal_Text_EnjoyRestOfChallenge2, MSGBOX_DEFAULT
# 86 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	closemessage
# 87 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	release
# 88 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	applymovement LOCALID_PIKE_ROOM_NPC_2, BattleFrontier_BattlePikeRoomNormal_Movement_NPCExit
# 89 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	waitmovement 0
# 90 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	end
# 91 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"

# 92 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
BattleFrontier_BattlePikeRoomNormal_EventScript_EnterBrainRoom::
# 93 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	delay 22
# 94 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	lockall
# 95 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	applymovement LOCALID_PIKE_ROOM_NPC_2, BattleFrontier_BattlePikeRoomNormal_Movement_PreQueenHealNPCApproachPlayer
# 96 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	waitmovement 0
# 97 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	pike_prequeenheal
# 98 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	switch VAR_RESULT
# 99 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	case 0, BattleFrontier_BattlePikeRoomNormal_EventScript_PreQueenNoHeal
# 100 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	case 1, BattleFrontier_BattlePikeRoomNormal_EventScript_PreQueenHealOneMon
# 101 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	case 2, BattleFrontier_BattlePikeRoomNormal_EventScript_PreQueenHealTwoMons
# 102 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"

# 103 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
BattleFrontier_BattlePikeRoomNormal_EventScript_LucyEnter::
# 104 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	msgbox BattleFrontier_BattlePikeRoomNormal_Text_ShallFetchOurMaster, MSGBOX_DEFAULT
# 105 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	closemessage
# 106 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	special SpawnCameraObject
# 107 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	applymovement LOCALID_CAMERA, BattleFrontier_BattlePikeRoomNormal_Movement_CameraPanUp
# 108 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	applymovement LOCALID_PIKE_ROOM_NPC_2, BattleFrontier_BattlePikeRoomNormal_Movement_HealNPCExitForLucy
# 109 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	waitmovement 0
# 110 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	playse SE_PIKE_CURTAIN_CLOSE
# 111 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	call BattleFrontier_BattlePikeRoomNormal_EventScript_SetCurtainTilesLittleClosed
# 112 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	delay 4
# 113 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	call BattleFrontier_BattlePikeRoomNormal_EventScript_SetCurtainTilesMostlyClosed
# 114 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	delay 4
# 115 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	call BattleFrontier_BattlePikeRoomNormal_EventScript_SetCurtainTilesClosed
# 116 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	delay 4
# 117 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	waitse
# 118 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	delay 60
# 119 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	playse SE_PIKE_CURTAIN_OPEN
# 120 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	delay 65
# 121 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	call BattleFrontier_BattlePikeRoomNormal_EventScript_SetCurtainTilesMostlyClosed
# 122 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	showobjectat LOCALID_PIKE_ROOM_NPC_1, MAP_BATTLE_FRONTIER_BATTLE_PIKE_ROOM_NORMAL
# 123 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	delay 4
# 124 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	call BattleFrontier_BattlePikeRoomNormal_EventScript_SetCurtainTilesLittleClosed
# 125 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	delay 4
# 126 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	call BattleFrontier_BattlePikeRoomNormal_EventScript_SetCurtainTilesOpen
# 127 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	waitse
# 128 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	applymovement LOCALID_PIKE_ROOM_NPC_1, BattleFrontier_BattlePikeRoomNormal_Movement_LucyEnter
# 129 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	waitmovement 0
# 130 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	pike_getbrainstatus
# 131 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	switch VAR_RESULT
# 132 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	case FRONTIER_BRAIN_GOLD, BattleFrontier_BattlePikeRoomNormal_EventScript_IntroLucyGold
# 133 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	case FRONTIER_BRAIN_STREAK, BattleFrontier_BattlePikeRoomNormal_EventScript_BattleLucySilver
# 134 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	case FRONTIER_BRAIN_STREAK_LONG, BattleFrontier_BattlePikeRoomNormal_EventScript_BattleLucyGold
# 135 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	frontier_get FRONTIER_DATA_HEARD_BRAIN_SPEECH
# 136 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	goto_if_ne VAR_RESULT, FALSE, BattleFrontier_BattlePikeRoomNormal_EventScript_BattleLucySilver
# 137 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	msgbox BattleFrontier_BattlePikeRoomNormal_Text_ImThePikeQueen, MSGBOX_DEFAULT
# 138 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	frontier_set FRONTIER_DATA_HEARD_BRAIN_SPEECH
# 139 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
BattleFrontier_BattlePikeRoomNormal_EventScript_BattleLucySilver::
# 140 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	msgbox BattleFrontier_BattlePikeRoomNormal_Text_HopeYouDidntUseUpLuck, MSGBOX_DEFAULT
# 141 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	call BattleFrontier_BattlePikeRoomNormal_EventScript_DoPikeQueenBattle
# 142 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	goto_if_eq VAR_RESULT, 1, BattleFrontier_BattlePikeRoomNormal_EventScript_DefeatedLucySilver
# 143 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	goto BattleFrontier_BattlePikeRoomNormal_EventScript_WarpToLobbyLost
# 144 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"

# 145 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
BattleFrontier_BattlePikeRoomNormal_EventScript_DefeatedLucySilver::
# 146 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	frontier_getsymbols
# 147 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	goto_if_ne VAR_RESULT, 0, BattleFrontier_BattlePikeRoomNormal_EventScript_DefeatedLucy
# 148 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	msgbox BattleFrontier_BattlePikeRoomNormal_Text_LucyShowMeFrontierPass, MSGBOX_DEFAULT
# 149 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	waitmessage
# 150 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	playfanfare MUS_OBTAIN_SYMBOL
# 151 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	message BattleFrontier_BattlePikeRoomNormal_Text_ReceivedLuckSymbol
# 152 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	waitmessage
# 153 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	waitfanfare
# 154 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	frontier_givesymbol
# 155 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	msgbox BattleFrontier_BattlePikeRoomNormal_Text_AllThereIsDisappear, MSGBOX_DEFAULT
# 156 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	closemessage
# 157 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	goto BattleFrontier_BattlePikeRoomNormal_EventScript_DefeatedLucy
# 158 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"

# 159 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
BattleFrontier_BattlePikeRoomNormal_EventScript_IntroLucyGold::
# 160 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	frontier_get FRONTIER_DATA_HEARD_BRAIN_SPEECH
# 161 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	goto_if_ne VAR_RESULT, FALSE, BattleFrontier_BattlePikeRoomNormal_EventScript_BattleLucyGold
# 162 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	msgbox BattleFrontier_BattlePikeRoomNormal_Text_LucyYouAgain, MSGBOX_DEFAULT
# 163 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	frontier_set FRONTIER_DATA_HEARD_BRAIN_SPEECH
# 164 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
BattleFrontier_BattlePikeRoomNormal_EventScript_BattleLucyGold::
# 165 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	msgbox BattleFrontier_BattlePikeRoomNormal_Text_NowComeOn, MSGBOX_DEFAULT
# 166 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	call BattleFrontier_BattlePikeRoomNormal_EventScript_DoPikeQueenBattle
# 167 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	goto_if_eq VAR_RESULT, 1, BattleFrontier_BattlePikeRoomNormal_EventScript_DefeatedLucyGold
# 168 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	goto BattleFrontier_BattlePikeRoomNormal_EventScript_WarpToLobbyLost
# 169 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"

# 170 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
BattleFrontier_BattlePikeRoomNormal_EventScript_DefeatedLucyGold::
# 171 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	frontier_getsymbols
# 172 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	goto_if_eq VAR_RESULT, 2, BattleFrontier_BattlePikeRoomNormal_EventScript_DefeatedLucy
# 173 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	msgbox BattleFrontier_BattlePikeRoomNormal_Text_LucyFrontierPass, MSGBOX_DEFAULT
# 174 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	waitmessage
# 175 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	playfanfare MUS_OBTAIN_SYMBOL
# 176 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	message BattleFrontier_BattlePikeRoomNormal_Text_LuckSymbolTookGoldenShine
# 177 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	waitmessage
# 178 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	waitfanfare
# 179 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	frontier_givesymbol
# 180 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	msgbox BattleFrontier_BattlePikeRoomNormal_Text_IWontForget, MSGBOX_DEFAULT
# 181 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	closemessage
# 182 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	goto BattleFrontier_BattlePikeRoomNormal_EventScript_DefeatedLucy
# 183 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	end
# 184 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"

# 185 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
BattleFrontier_BattlePikeRoomNormal_EventScript_DefeatedLucy::
# 186 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	applymovement LOCALID_PIKE_ROOM_NPC_1, BattleFrontier_BattlePikeRoomNormal_Movement_LucyMoveAside
# 187 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	waitmovement 0
# 188 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	applymovement LOCALID_PLAYER, BattleFrontier_BattlePikeRoomNormal_Movement_PlayerWalkUp2
# 189 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	waitmovement 0
# 190 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	pike_get PIKE_DATA_WIN_STREAK
# 191 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	addvar VAR_RESULT, 1
# 192 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	pike_set PIKE_DATA_WIN_STREAK, VAR_RESULT
# 193 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	call BattleFrontier_BattlePikeRoom_EventScript_WarpToFinalRoom
# 194 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	waitstate
# 195 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	end
# 196 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"

# 197 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
BattleFrontier_BattlePikeRoomNormal_EventScript_PreQueenNoHeal::
# 198 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	msgbox BattleFrontier_BattlePikeRoomNormal_Text_ChoseRoomNoHeal, MSGBOX_DEFAULT
# 199 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	goto BattleFrontier_BattlePikeRoomNormal_EventScript_LucyEnter
# 200 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	end
# 201 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"

# 202 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
BattleFrontier_BattlePikeRoomNormal_EventScript_PreQueenHealOneMon::
# 203 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	msgbox BattleFrontier_BattlePikeRoomNormal_Text_ChoseRoomHealOne, MSGBOX_DEFAULT
# 204 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	playfanfare MUS_HEAL
# 205 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	waitfanfare
# 206 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	goto BattleFrontier_BattlePikeRoomNormal_EventScript_LucyEnter
# 207 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	end
# 208 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"

# 209 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
BattleFrontier_BattlePikeRoomNormal_EventScript_PreQueenHealTwoMons::
# 210 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	msgbox BattleFrontier_BattlePikeRoomNormal_Text_ChoseRoomHealTwo, MSGBOX_DEFAULT
# 211 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	playfanfare MUS_HEAL
# 212 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	waitfanfare
# 213 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	goto BattleFrontier_BattlePikeRoomNormal_EventScript_LucyEnter
# 214 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	end
# 215 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"

# 216 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
BattleFrontier_BattlePikeRoomNormal_EventScript_EnterFullHealRoom::
# 217 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	lockall
# 218 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	delay 16
# 219 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	applymovement LOCALID_PIKE_ROOM_NPC_1, BattleFrontier_BattlePikeRoomNormal_Movement_ApproachPlayer
# 220 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	waitmovement 0
# 221 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	message BattleFrontier_BattlePikeRoomNormal_Text_WillRestoreToFullHealth
# 222 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	waitmessage
# 223 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	playfanfare MUS_HEAL
# 224 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	waitfanfare
# 225 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	special HealPlayerParty
# 226 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	msgbox BattleFrontier_BattlePikeRoomNormal_Text_EnjoyRestOfChallenge, MSGBOX_DEFAULT
# 227 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	closemessage
# 228 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	applymovement LOCALID_PIKE_ROOM_NPC_1, BattleFrontier_BattlePikeRoomNormal_Movement_NPCExit
# 229 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	waitmovement 0
# 230 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	releaseall
# 231 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	end
# 232 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"

# 233 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
BattleFrontier_BattlePikeRoomNormal_EventScript_EnterDoubleBattleRoom::
# 234 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	lockall
# 235 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	delay 16
# 236 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	applymovement LOCALID_PIKE_ROOM_NPC_1, BattleFrontier_BattlePikeRoomNormal_Movement_Trainer1WalkRight
# 237 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	applymovement LOCALID_PIKE_ROOM_NPC_2, BattleFrontier_BattlePikeRoomNormal_Movement_Trainer2WalkLeft
# 238 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	waitmovement 0
# 239 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	applymovement LOCALID_PIKE_ROOM_NPC_1, BattleFrontier_BattlePikeRoomNormal_Movement_DoubleTrainersWalkDown
# 240 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	applymovement LOCALID_PIKE_ROOM_NPC_2, BattleFrontier_BattlePikeRoomNormal_Movement_DoubleTrainersWalkDown
# 241 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	waitmovement 0
# 242 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	applymovement LOCALID_PIKE_ROOM_NPC_1, BattleFrontier_BattlePikeRoomNormal_Movement_Trainer1FacePlayer
# 243 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	applymovement LOCALID_PIKE_ROOM_NPC_2, BattleFrontier_BattlePikeRoomNormal_Movement_Trainer2FacePlayer
# 244 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	waitmovement 0
# 245 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	applymovement LOCALID_PLAYER, BattleFrontier_BattlePikeRoomNormal_Movement_PlayerFaceTrainer1
# 246 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	waitmovement 0
# 247 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	pike_gettrainerintro 0
# 248 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	msgbox gStringVar4, MSGBOX_DEFAULT
# 249 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	closemessage
# 250 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	delay 16
# 251 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	applymovement LOCALID_PLAYER, BattleFrontier_BattlePikeRoomNormal_Movement_PlayerFaceTrainer2
# 252 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	waitmovement 0
# 253 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	pike_gettrainerintro 1
# 254 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	msgbox gStringVar4, MSGBOX_DEFAULT
# 255 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	closemessage
# 256 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	setvar VAR_0x8004, SPECIAL_BATTLE_PIKE_DOUBLE
# 257 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	setvar VAR_0x8005, 0
# 258 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	special DoSpecialTrainerBattle
# 259 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	waitstate
# 260 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	switch VAR_RESULT
# 261 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	case 1, BattleFrontier_BattlePikeRoomNormal_EventScript_WonDoubleBattle
# 262 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	goto BattleFrontier_BattlePikeRoomNormal_EventScript_WarpToLobbyLost
# 263 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	end
# 264 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"

# 265 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
BattleFrontier_BattlePikeRoomNormal_EventScript_WonDoubleBattle::
# 266 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	applymovement LOCALID_PLAYER, BattleFrontier_BattlePikeRoomNormal_Movement_PlayerFaceTrainer2
# 267 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	waitmovement 0
# 268 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	applymovement LOCALID_PIKE_ROOM_NPC_1, BattleFrontier_BattlePikeRoomNormal_Movement_Trainer1Exit
# 269 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	waitmovement 0
# 270 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	applymovement LOCALID_PIKE_ROOM_NPC_2, BattleFrontier_BattlePikeRoomNormal_Movement_Trainer2Exit
# 271 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	waitmovement 0
# 272 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	applymovement LOCALID_PLAYER, BattleFrontier_BattlePikeRoomNormal_Movement_PlayerFaceUp
# 273 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	waitmovement 0
# 274 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	end
# 275 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"

# 276 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
BattleFrontier_BattlePikeRoomNormal_EventScript_EnterStatusRoom::
# 277 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	lockall
# 278 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	message BattleFrontier_BattlePikeRoomNormal_Text_WatchOut
# 279 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	applymovement LOCALID_PIKE_ROOM_NPC_2, BattleFrontier_BattlePikeRoomNormal_Movement_MonApproachPlayer
# 280 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	waitmovement 0
# 281 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	pike_getstatusmon
# 282 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	copyvar VAR_0x8004, VAR_RESULT
# 283 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	call_if_eq VAR_0x8004, PIKE_STATUSMON_KIRLIA, BattleFrontier_BattlePikeRoomNormal_EventScript_KirliaAttack
# 284 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	call_if_eq VAR_0x8004, PIKE_STATUSMON_DUSCLOPS, BattleFrontier_BattlePikeRoomNormal_EventScript_DusclopsAttack
# 285 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	msgbox BattleFrontier_BattlePikeRoomNormal_Text_AttacksWhenStartled, MSGBOX_DEFAULT
# 286 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	closemessage
# 287 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	releaseall
# 288 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	end
# 289 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"

# 290 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
BattleFrontier_BattlePikeRoomNormal_EventScript_KirliaAttack::
# 291 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	msgbox BattleFrontier_BattlePikeRoomNormal_Text_KirliaStop, MSGBOX_DEFAULT
# 292 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	closemessage
# 293 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	waitse
# 294 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	playmoncry SPECIES_KIRLIA, CRY_MODE_NORMAL
# 295 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	waitmoncry
# 296 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	pike_getstatus
# 297 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	call_if_eq VAR_RESULT, PIKE_STATUS_TOXIC, BattleFrontier_BattlePikeRoomNormal_EventScript_KirliaUsedToxic
# 298 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	call_if_eq VAR_RESULT, PIKE_STATUS_BURN, BattleFrontier_BattlePikeRoomNormal_EventScript_KirliaUsedWillOWisp
# 299 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	call_if_eq VAR_RESULT, PIKE_STATUS_PARALYSIS, BattleFrontier_BattlePikeRoomNormal_EventScript_KirliaUsedThunderWave
# 300 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	call_if_eq VAR_RESULT, PIKE_STATUS_SLEEP, BattleFrontier_BattlePikeRoomNormal_EventScript_KirliaUsedHypnosis
# 301 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	pike_flashscreen
# 302 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	waitstate
# 303 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	applymovement LOCALID_PIKE_ROOM_NPC_1, BattleFrontier_BattlePikeRoomNormal_Movement_NPCApproachMon
# 304 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	waitmovement 0
# 305 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	applymovement LOCALID_PIKE_ROOM_NPC_2, BattleFrontier_BattlePikeRoomNormal_Movement_MonFaceNPC
# 306 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	waitmovement 0
# 307 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	waitse
# 308 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	playmoncry SPECIES_KIRLIA, CRY_MODE_NORMAL
# 309 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	waitmoncry
# 310 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	msgbox BattleFrontier_BattlePikeRoomNormal_Text_ThatsEnough, MSGBOX_DEFAULT
# 311 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	waitse
# 312 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	playmoncry SPECIES_KIRLIA, CRY_MODE_NORMAL
# 313 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	waitmoncry
# 314 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	closemessage
# 315 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	applymovement LOCALID_PIKE_ROOM_NPC_2, BattleFrontier_BattlePikeRoomNormal_Movement_MonMoveAside
# 316 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	applymovement LOCALID_PIKE_ROOM_NPC_1, BattleFrontier_BattlePikeRoomNormal_Movement_StatusNPCApproachPlayer
# 317 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	waitmovement 0
# 318 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	msgbox BattleFrontier_BattlePikeRoomNormal_Text_ApologizeForKirlia, MSGBOX_DEFAULT
# 319 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	return
# 320 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"

# 321 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
BattleFrontier_BattlePikeRoomNormal_EventScript_DusclopsAttack::
# 322 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	msgbox BattleFrontier_BattlePikeRoomNormal_Text_DusclopsStop, MSGBOX_DEFAULT
# 323 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	closemessage
# 324 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	waitse
# 325 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	playmoncry SPECIES_DUSCLOPS, CRY_MODE_NORMAL
# 326 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	waitmoncry
# 327 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	pike_getstatus
# 328 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	call_if_eq VAR_RESULT, PIKE_STATUS_FREEZE, BattleFrontier_BattlePikeRoomNormal_EventScript_DusclopsUsedIceBeam
# 329 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	call_if_eq VAR_RESULT, PIKE_STATUS_BURN, BattleFrontier_BattlePikeRoomNormal_EventScript_DusclopsUsedWillOWisp
# 330 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	pike_flashscreen
# 331 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	waitstate
# 332 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	applymovement LOCALID_PIKE_ROOM_NPC_1, BattleFrontier_BattlePikeRoomNormal_Movement_NPCApproachMon
# 333 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	waitmovement 0
# 334 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	applymovement LOCALID_PIKE_ROOM_NPC_2, BattleFrontier_BattlePikeRoomNormal_Movement_MonFaceNPC
# 335 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	waitmovement 0
# 336 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	waitse
# 337 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	playmoncry SPECIES_DUSCLOPS, CRY_MODE_NORMAL
# 338 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	waitmoncry
# 339 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	msgbox BattleFrontier_BattlePikeRoomNormal_Text_ThatsEnough, MSGBOX_DEFAULT
# 340 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	waitse
# 341 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	playmoncry SPECIES_DUSCLOPS, CRY_MODE_NORMAL
# 342 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	waitmoncry
# 343 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	closemessage
# 344 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	applymovement LOCALID_PIKE_ROOM_NPC_2, BattleFrontier_BattlePikeRoomNormal_Movement_MonMoveAside
# 345 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	applymovement LOCALID_PIKE_ROOM_NPC_1, BattleFrontier_BattlePikeRoomNormal_Movement_StatusNPCApproachPlayer
# 346 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	waitmovement 0
# 347 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	msgbox BattleFrontier_BattlePikeRoomNormal_Text_ApologizeForDusclops, MSGBOX_DEFAULT
# 348 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	return
# 349 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"

# 350 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
BattleFrontier_BattlePikeRoomNormal_EventScript_KirliaUsedToxic::
# 351 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	message BattleFrontier_BattlePikeRoomNormal_Text_KirliaUsedToxic
# 352 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	waitmessage
# 353 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	return
# 354 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"

# 355 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
BattleFrontier_BattlePikeRoomNormal_EventScript_KirliaUsedWillOWisp::
# 356 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	message BattleFrontier_BattlePikeRoomNormal_Text_KirliaUsedWillOWisp
# 357 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	waitmessage
# 358 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	return
# 359 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"

# 360 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
BattleFrontier_BattlePikeRoomNormal_EventScript_KirliaUsedThunderWave::
# 361 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	message BattleFrontier_BattlePikeRoomNormal_Text_KirliaUsedThunderWave
# 362 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	waitmessage
# 363 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	return
# 364 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"

# 365 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
BattleFrontier_BattlePikeRoomNormal_EventScript_KirliaUsedHypnosis::
# 366 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	message BattleFrontier_BattlePikeRoomNormal_Text_KirliaUsedHypnosis
# 367 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	waitmessage
# 368 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	return
# 369 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"

# 370 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
BattleFrontier_BattlePikeRoomNormal_EventScript_DusclopsUsedIceBeam::
# 371 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	message BattleFrontier_BattlePikeRoomNormal_Text_DusclopsUsedIceBeam
# 372 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	waitmessage
# 373 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	return
# 374 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"

# 375 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
BattleFrontier_BattlePikeRoomNormal_EventScript_DusclopsUsedWillOWisp::
# 376 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	message BattleFrontier_BattlePikeRoomNormal_Text_DusclopsUsedWillOWisp
# 377 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	waitmessage
# 378 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	return
# 379 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"

# 380 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
BattleFrontier_BattlePikeRoomNormal_EventScript_DoPikeQueenBattle::
# 381 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	closemessage
# 382 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	applymovement LOCALID_PLAYER, BattleFrontier_BattlePikeRoomNormal_Movement_PlayerWalkUp2
# 383 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	waitmovement 0
# 384 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	setvar VAR_0x8004, SPECIAL_BATTLE_PIKE_SINGLE
# 385 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	setvar VAR_0x8005, 0
# 386 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	special DoSpecialTrainerBattle
# 387 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	waitstate
# 388 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	return
# 389 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"

# 390 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
BattleFrontier_BattlePikeRoomNormal_Movement_ApproachPlayer:
# 391 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	walk_down
# 392 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	walk_down
# 393 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	step_end
# 394 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"

# 395 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
BattleFrontier_BattlePikeRoomNormal_Movement_NPCExit:
# 396 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	walk_up
# 397 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	walk_up
# 398 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	walk_up
# 399 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	set_invisible
# 400 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	walk_up
# 401 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	step_end
# 402 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"

# 403 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
BattleFrontier_BattlePikeRoomNormal_Movement_HealNPCExit:
# 404 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	walk_up
# 405 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	set_invisible
# 406 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	walk_up
# 407 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	step_end
# 408 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"

# 409 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
BattleFrontier_BattlePikeRoomNormal_Movement_NPCApproachMon:
# 410 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	walk_down
# 411 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	step_end
# 412 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"

# 413 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
BattleFrontier_BattlePikeRoomNormal_Movement_StatusNPCApproachPlayer:
# 414 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	walk_down
# 415 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	face_left
# 416 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	delay_16
# 417 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	delay_16
# 418 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	face_down
# 419 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	step_end
# 420 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"

# 421 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
BattleFrontier_BattlePikeRoomNormal_Movement_MonApproachPlayer:
# 422 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	walk_fast_down
# 423 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	walk_fast_right
# 424 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	walk_fast_right
# 425 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	walk_fast_down
# 426 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	walk_fast_left
# 427 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	face_down
# 428 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	step_end
# 429 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"

# 430 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
BattleFrontier_BattlePikeRoomNormal_Movement_MonFaceNPC:
# 431 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	face_up
# 432 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	step_end
# 433 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"

# 434 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
BattleFrontier_BattlePikeRoomNormal_Movement_MonMoveAside:
# 435 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	walk_left
# 436 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
BattleFrontier_BattlePikeRoomNormal_Movement_MonFaceRight:
# 437 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	face_right
# 438 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	step_end
# 439 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"

# 440 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
BattleFrontier_BattlePikeRoomNormal_Movement_HealNPCApproachPlayer:
# 441 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	walk_down
# 442 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	walk_down
# 443 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	walk_right
# 444 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	face_down
# 445 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	step_end
# 446 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"

# 447 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
BattleFrontier_BattlePikeRoomNormal_Movement_PlayerFaceTrainer1:
# 448 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	face_left
# 449 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	step_end
# 450 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"

# 451 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
BattleFrontier_BattlePikeRoomNormal_Movement_PlayerFaceTrainer2:
# 452 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	face_right
# 453 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	step_end
# 454 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"

# 455 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
BattleFrontier_BattlePikeRoomNormal_Movement_PlayerFaceUp:
# 456 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	face_up
# 457 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	step_end
# 458 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"

# 459 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
BattleFrontier_BattlePikeRoomNormal_Movement_Trainer1WalkRight:
# 460 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	walk_right
# 461 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	step_end
# 462 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"

# 463 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
BattleFrontier_BattlePikeRoomNormal_Movement_Trainer2WalkLeft:
# 464 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	walk_left
# 465 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	step_end
# 466 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"

# 467 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
BattleFrontier_BattlePikeRoomNormal_Movement_DoubleTrainersWalkDown:
# 468 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	walk_down
# 469 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	walk_down
# 470 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	step_end
# 471 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"

# 472 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
BattleFrontier_BattlePikeRoomNormal_Movement_Trainer1FacePlayer:
# 473 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	face_right
# 474 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	step_end
# 475 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"

# 476 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
BattleFrontier_BattlePikeRoomNormal_Movement_Trainer2FacePlayer:
# 477 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	face_left
# 478 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	step_end
# 479 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"

# 480 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
BattleFrontier_BattlePikeRoomNormal_Movement_Trainer1Exit:
# 481 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	walk_up
# 482 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	walk_up
# 483 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	walk_up
# 484 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	walk_right
# 485 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	walk_up
# 486 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	set_invisible
# 487 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	walk_up
# 488 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	step_end
# 489 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"

# 490 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
BattleFrontier_BattlePikeRoomNormal_Movement_Trainer2Exit:
# 491 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	walk_up
# 492 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	walk_up
# 493 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	walk_up
# 494 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	walk_left
# 495 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	walk_up
# 496 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	set_invisible
# 497 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	walk_up
# 498 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	step_end
# 499 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"

# 500 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
@ For approaching Lucy and exiting room after defeating Lucy
# 501 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
BattleFrontier_BattlePikeRoomNormal_Movement_PlayerWalkUp2:
# 502 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	walk_up
# 503 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	walk_up
# 504 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	step_end
# 505 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"

# 506 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
BattleFrontier_BattlePikeRoomNormal_Movement_PreQueenHealNPCApproachPlayer:
# 507 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	walk_down
# 508 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	walk_down
# 509 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	step_end
# 510 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"

# 511 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
BattleFrontier_BattlePikeRoomNormal_Movement_HealNPCExitForLucy:
# 512 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	walk_up
# 513 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	walk_up
# 514 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	walk_up
# 515 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	set_invisible
# 516 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	step_end
# 517 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"

# 518 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
BattleFrontier_BattlePikeRoomNormal_Movement_LucyEnter:
# 519 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	set_visible
# 520 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	walk_down
# 521 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	step_end
# 522 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"

# 523 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
BattleFrontier_BattlePikeRoomNormal_Movement_LucyMoveAside:
# 524 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	walk_left
# 525 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	face_right
# 526 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	step_end
# 527 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"

# 528 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
BattleFrontier_BattlePikeRoomNormal_EventScript_NPC::
# 529 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	pike_getroomtype
# 530 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	switch VAR_RESULT
# 531 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	case PIKE_ROOM_NPC, BattleFrontier_BattlePikeRoomNormal_EventScript_NormalNPC
# 532 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	case PIKE_ROOM_STATUS, BattleFrontier_BattlePikeRoomNormal_EventScript_StatusNPC
# 533 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	case PIKE_ROOM_HEAL_PART, BattleFrontier_BattlePikeRoomNormal_EventScript_HealNPC
# 534 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
BattleFrontier_BattlePikeRoomNormal_EventScript_NormalNPC::
# 535 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	lock
# 536 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	faceplayer
# 537 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	pike_getnpcmsg
# 538 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	msgbox gStringVar4, MSGBOX_DEFAULT
# 539 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	waitmessage
# 540 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	closemessage
# 541 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	release
# 542 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	end
# 543 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"

# 544 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
BattleFrontier_BattlePikeRoomNormal_EventScript_StatusNPC::
# 545 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	lock
# 546 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	faceplayer
# 547 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	msgbox BattleFrontier_BattlePikeRoomNormal_Text_ApologizeHopeMonsAreFine, MSGBOX_DEFAULT
# 548 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	closemessage
# 549 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	release
# 550 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	end
# 551 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"

# 552 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
BattleFrontier_BattlePikeRoomNormal_EventScript_HealNPC::
# 553 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	pike_healonetwomons
# 554 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	call_if_eq VAR_RESULT, 2, BattleFrontier_BattlePikeRoomNormal_EventScript_WillRestoreTwoMons
# 555 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	call_if_eq VAR_RESULT, 1, BattleFrontier_BattlePikeRoomNormal_EventScript_WillRestoreOneMon
# 556 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	playfanfare MUS_HEAL
# 557 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	waitfanfare
# 558 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	msgbox BattleFrontier_BattlePikeRoomNormal_Text_BestOfLuckFarewell, MSGBOX_DEFAULT
# 559 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	closemessage
# 560 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	release
# 561 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	applymovement LOCALID_PIKE_ROOM_NPC_1, BattleFrontier_BattlePikeRoomNormal_Movement_HealNPCExit
# 562 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	waitmovement 0
# 563 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	end
# 564 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"

# 565 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
BattleFrontier_BattlePikeRoomNormal_EventScript_WillRestoreOneMon::
# 566 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	lock
# 567 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	faceplayer
# 568 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	msgbox BattleFrontier_BattlePikeRoomNormal_Text_WillRestoreOneMon, MSGBOX_DEFAULT
# 569 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	closemessage
# 570 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	return
# 571 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"

# 572 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
BattleFrontier_BattlePikeRoomNormal_EventScript_WillRestoreTwoMons::
# 573 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	lock
# 574 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	faceplayer
# 575 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	msgbox BattleFrontier_BattlePikeRoomNormal_Text_WillRestoreTwoMons, MSGBOX_DEFAULT
# 576 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	closemessage
# 577 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	return
# 578 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"

# 579 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
@ Dusclops or Kirlia
# 580 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
BattleFrontier_BattlePikeRoomNormal_EventScript_StatusMon::
# 581 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	lock
# 582 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	faceplayer
# 583 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	msgbox BattleFrontier_BattlePikeRoomNormal_Text_Silence, MSGBOX_DEFAULT
# 584 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	closemessage
# 585 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	release
# 586 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	applymovement LOCALID_PIKE_ROOM_NPC_2, BattleFrontier_BattlePikeRoomNormal_Movement_MonFaceRight
# 587 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	waitmovement 0
# 588 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	end
# 589 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"

# 590 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
BattleFrontier_BattlePikeRoomNormal_EventScript_SetCurtainTilesMostlyClosed::
# 591 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	setmetatile 4, 1, METATILE_BattlePike_Curtain_Stage1_Tile0, TRUE
# 592 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	setmetatile 3, 2, METATILE_BattlePike_Curtain_Stage1_Tile1, TRUE
# 593 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	setmetatile 4, 2, METATILE_BattlePike_Curtain_Stage1_Tile2, TRUE
# 594 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	setmetatile 5, 2, METATILE_BattlePike_Curtain_Stage1_Tile3, TRUE
# 595 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	setmetatile 3, 3, METATILE_BattlePike_Curtain_Stage1_Tile4, TRUE
# 596 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	setmetatile 4, 3, METATILE_BattlePike_Curtain_Stage1_Tile5, FALSE
# 597 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	setmetatile 5, 3, METATILE_BattlePike_Curtain_Stage1_Tile6, TRUE
# 598 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	special DrawWholeMapView
# 599 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	return
# 600 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"

# 601 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
BattleFrontier_BattlePikeRoomNormal_EventScript_SetCurtainTilesLittleClosed::
# 602 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	setmetatile 4, 1, METATILE_BattlePike_Curtain_Stage2_Tile0, TRUE
# 603 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	setmetatile 3, 2, METATILE_BattlePike_Curtain_Stage2_Tile1, TRUE
# 604 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	setmetatile 4, 2, METATILE_BattlePike_Curtain_Stage2_Tile2, TRUE
# 605 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	setmetatile 5, 2, METATILE_BattlePike_Curtain_Stage2_Tile3, TRUE
# 606 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	setmetatile 3, 3, METATILE_BattlePike_Curtain_Stage2_Tile4, TRUE
# 607 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	setmetatile 4, 3, METATILE_BattlePike_Curtain_Stage2_Tile5, FALSE
# 608 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	setmetatile 5, 3, METATILE_BattlePike_Curtain_Stage2_Tile6, TRUE
# 609 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	special DrawWholeMapView
# 610 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	return
# 611 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"

# 612 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
BattleFrontier_BattlePikeRoomNormal_EventScript_SetCurtainTilesOpen::
# 613 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	setmetatile 4, 1, METATILE_BattlePike_Curtain_Stage3_Tile0, TRUE
# 614 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	setmetatile 3, 2, METATILE_BattlePike_Curtain_Stage3_Tile1, TRUE
# 615 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	setmetatile 4, 2, METATILE_BattlePike_Curtain_Stage3_Tile2, TRUE
# 616 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	setmetatile 5, 2, METATILE_BattlePike_Curtain_Stage3_Tile3, TRUE
# 617 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	setmetatile 3, 3, METATILE_BattlePike_Curtain_Stage3_Tile4, TRUE
# 618 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	setmetatile 4, 3, METATILE_BattlePike_Curtain_Stage3_Tile5, FALSE
# 619 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	setmetatile 5, 3, METATILE_BattlePike_Curtain_Stage3_Tile6, TRUE
# 620 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	special DrawWholeMapView
# 621 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	return
# 622 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"

# 623 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
BattleFrontier_BattlePikeRoomNormal_EventScript_SetCurtainTilesClosed::
# 624 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	setmetatile 4, 1, METATILE_BattlePike_Curtain_Stage0_Tile0, TRUE
# 625 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	setmetatile 3, 2, METATILE_BattlePike_Curtain_Stage0_Tile1, TRUE
# 626 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	setmetatile 4, 2, METATILE_BattlePike_Curtain_Stage0_Tile2, TRUE
# 627 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	setmetatile 5, 2, METATILE_BattlePike_Curtain_Stage0_Tile3, TRUE
# 628 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	setmetatile 3, 3, METATILE_BattlePike_Curtain_Stage0_Tile4, TRUE
# 629 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	setmetatile 4, 3, METATILE_BattlePike_Curtain_Stage0_Tile5, FALSE
# 630 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	setmetatile 5, 3, METATILE_BattlePike_Curtain_Stage0_Tile6, TRUE
# 631 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	special DrawWholeMapView
# 632 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	return
# 633 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"

# 634 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
BattleFrontier_BattlePikeRoomNormal_Movement_CameraPanUp:
# 635 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	walk_up
# 636 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	walk_up
# 637 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	step_end
# 638 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"

# 639 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
@ Unused
# 640 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
BattleFrontier_BattlePikeRoomNormal_Movement_CameraPanDown:
# 641 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	walk_down
# 642 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	walk_down
# 643 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	step_end
# 644 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"

# 645 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
BattleFrontier_BattlePikeRoomNormal_Text_WillRestoreToFullHealth:
# 646 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	.string "Welcome…\n"
# 647 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	.string "You must be commended for your luck…\p"
# 648 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	.string "Your POKéMON shall be restored\n"
# 649 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	.string "to full health…$"
# 650 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"

# 651 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
BattleFrontier_BattlePikeRoomNormal_Text_EnjoyRestOfChallenge:
# 652 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	.string "I urge you to enjoy the rest of your\n"
# 653 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	.string "Battle Choice challenge…$"
# 654 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"

# 655 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
BattleFrontier_BattlePikeRoomNormal_Text_WillRestoreOneMon:
# 656 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	.string "Ah, you're a lucky one.\n"
# 657 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	.string "I'm in somewhat-good spirits now.\p"
# 658 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	.string "I will restore one of your POKéMON\n"
# 659 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	.string "to full health.$"
# 660 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"

# 661 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
BattleFrontier_BattlePikeRoomNormal_Text_BestOfLuckFarewell:
# 662 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	.string "The best of luck to you.\n"
# 663 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	.string "Farewell.$"
# 664 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"

# 665 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
@ Seems there was a planned room type where the player could choose to battle and would be healed if they won
# 666 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
@ Possibly replaced/superseded by the hard battle room, which is the same but the battle isnt optional
# 667 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
@ Unused
# 668 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
BattleFrontier_BattlePikeRoomNormal_Text_CareForBattleWillRestoreMons:
# 669 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	.string "Excuse me…\p"
# 670 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	.string "Would you care for a battle?\n"
# 671 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	.string "I'll restore your POKéMON if you win.$"
# 672 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"

# 673 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
@ Unused
# 674 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
BattleFrontier_BattlePikeRoomNormal_Text_NowShallWe:
# 675 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	.string "Very well…\n"
# 676 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	.string "Now, shall we?$"
# 677 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"

# 678 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
@ Unused
# 679 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
BattleFrontier_BattlePikeRoomNormal_Text_HowUnsportingOfYou:
# 680 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	.string "I see…\n"
# 681 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	.string "How unsporting of you…$"
# 682 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"

# 683 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
@ Unused
# 684 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
BattleFrontier_BattlePikeRoomNormal_Text_WillRestoreMonsAsPromised:
# 685 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	.string "Magnificent…\p"
# 686 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	.string "As promised, I shall restore your\n"
# 687 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	.string "POKéMON to full health.$"
# 688 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"

# 689 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
@ Unused
# 690 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
BattleFrontier_BattlePikeRoomNormal_Text_BestOfLuckFarewell2:
# 691 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	.string "The best of luck to you.\n"
# 692 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	.string "Farewell.$"
# 693 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"

# 694 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
BattleFrontier_BattlePikeRoomNormal_Text_WatchOut:
# 695 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	.string "Oh, my!\p"
# 696 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	.string "Watch out!$"
# 697 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"

# 698 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
BattleFrontier_BattlePikeRoomNormal_Text_KirliaStop:
# 699 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	.string "Now, now!\n"
# 700 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	.string "KIRLIA, stop that!$"
# 701 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"

# 702 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
BattleFrontier_BattlePikeRoomNormal_Text_DusclopsStop:
# 703 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	.string "Now, now!\n"
# 704 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	.string "DUSCLOPS, stop that!$"
# 705 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"

# 706 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
BattleFrontier_BattlePikeRoomNormal_Text_KirliaUsedToxic:
# 707 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	.string "KIRLIA used TOXIC!$"
# 708 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"

# 709 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
BattleFrontier_BattlePikeRoomNormal_Text_KirliaUsedHypnosis:
# 710 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	.string "KIRLIA used HYPNOSIS!$"
# 711 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"

# 712 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
BattleFrontier_BattlePikeRoomNormal_Text_KirliaUsedThunderWave:
# 713 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	.string "KIRLIA used THUNDER WAVE!$"
# 714 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"

# 715 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
BattleFrontier_BattlePikeRoomNormal_Text_KirliaUsedWillOWisp:
# 716 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	.string "KIRLIA used WILL-O-WISP!$"
# 717 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"

# 718 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
BattleFrontier_BattlePikeRoomNormal_Text_DusclopsUsedWillOWisp:
# 719 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	.string "DUSCLOPS used WILL-O-WISP!$"
# 720 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"

# 721 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
BattleFrontier_BattlePikeRoomNormal_Text_DusclopsUsedIceBeam:
# 722 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	.string "DUSCLOPS used ICE BEAM!$"
# 723 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"

# 724 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
BattleFrontier_BattlePikeRoomNormal_Text_ThatsEnough:
# 725 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	.string "Look here!\n"
# 726 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	.string "That's quite enough!$"
# 727 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"

# 728 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
BattleFrontier_BattlePikeRoomNormal_Text_ApologizeForKirlia:
# 729 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	.string "I must apologize to you…\p"
# 730 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	.string "My KIRLIA has a TIMID nature…$"
# 731 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"

# 732 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
BattleFrontier_BattlePikeRoomNormal_Text_ApologizeForDusclops:
# 733 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	.string "I must apologize to you…\p"
# 734 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	.string "My DUSCLOPS has a TIMID nature…$"
# 735 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"

# 736 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
BattleFrontier_BattlePikeRoomNormal_Text_AttacksWhenStartled:
# 737 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	.string "It attacks without warning if it is\n"
# 738 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	.string "startled by another person…\p"
# 739 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	.string "Are you and your POKéMON all right?$"
# 740 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"

# 741 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
BattleFrontier_BattlePikeRoomNormal_Text_ApologizeHopeMonsAreFine:
# 742 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	.string "I do apologize for what happened…\n"
# 743 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	.string "I do hope your POKéMON are fine.$"
# 744 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"

# 745 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
BattleFrontier_BattlePikeRoomNormal_Text_Silence:
# 746 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	.string "… … … … … …\n"
# 747 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	.string "… … … … … …$"
# 748 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"

# 749 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
BattleFrontier_BattlePikeRoomNormal_Text_BattleSomewhatToughTrainer:
# 750 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	.string "Welcome…\p"
# 751 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	.string "Here, we will have you battle\n"
# 752 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	.string "a somewhat-tough TRAINER…$"
# 753 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"

# 754 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
BattleFrontier_BattlePikeRoomNormal_Text_RestoreToFullHealth:
# 755 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	.string "How wonderful…\p"
# 756 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	.string "To honor your victory, your POKéMON\n"
# 757 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	.string "shall be restored to full health…$"
# 758 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"

# 759 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
BattleFrontier_BattlePikeRoomNormal_Text_EnjoyRestOfChallenge2:
# 760 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	.string "I urge you to enjoy the rest of your\n"
# 761 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	.string "Battle Choice challenge…$"
# 762 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"

# 763 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
BattleFrontier_BattlePikeRoomNormal_Text_ImThePikeQueen:
# 764 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	.string "I am LUCY…\n"
# 765 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	.string "I am the law here…\l"
# 766 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	.string "For I am the PIKE QUEEN…\p"
# 767 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	.string "You already know it, but to advance,\n"
# 768 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	.string "you must defeat me…\p"
# 769 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	.string "…I'm not one for idle chatter.\n"
# 770 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	.string "Hurry. Come on…$"
# 771 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"

# 772 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
BattleFrontier_BattlePikeRoomNormal_Text_HopeYouDidntUseUpLuck:
# 773 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	.string "Your luck…\n"
# 774 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	.string "I hope you didn't use it all up here…$"
# 775 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"

# 776 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
BattleFrontier_BattlePikeRoomNormal_Text_LucyShowMeFrontierPass:
# 777 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	.string "LUCY: … … … … … …\n"
# 778 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	.string "Show me your FRONTIER PASS…$"
# 779 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"

# 780 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
BattleFrontier_BattlePikeRoomNormal_Text_ReceivedLuckSymbol:
# 781 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	.string "The Luck Symbol was embossed on\n"
# 782 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	.string "the FRONTIER PASS!$"
# 783 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"

# 784 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
BattleFrontier_BattlePikeRoomNormal_Text_AllThereIsDisappear:
# 785 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	.string "…That's all there is…\n"
# 786 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	.string "Disappear already…$"
# 787 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"

# 788 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
BattleFrontier_BattlePikeRoomNormal_Text_LucyYouAgain:
# 789 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	.string "LUCY: …You again…\p"
# 790 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	.string "… … … … … …\p"
# 791 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	.string "…I've trampled flowers and braved\n"
# 792 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	.string "storms to get to where I am…\p"
# 793 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	.string "I don't feel any compulsion to keep\n"
# 794 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	.string "losing to the same opponent…\p"
# 795 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	.string "… … … … … …\n"
# 796 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	.string "Fine… I'll do it…$"
# 797 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"

# 798 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
BattleFrontier_BattlePikeRoomNormal_Text_NowComeOn:
# 799 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	.string "Now!\n"
# 800 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	.string "Come on!$"
# 801 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"

# 802 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
BattleFrontier_BattlePikeRoomNormal_Text_LucyFrontierPass:
# 803 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	.string "LUCY: … … … … … …\p"
# 804 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	.string "…FRONTIER PASS…$"
# 805 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"

# 806 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
BattleFrontier_BattlePikeRoomNormal_Text_LuckSymbolTookGoldenShine:
# 807 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	.string "The Luck Symbol took on\n"
# 808 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	.string "a golden shine!$"
# 809 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"

# 810 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
BattleFrontier_BattlePikeRoomNormal_Text_IWontForget:
# 811 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	.string "…You, I won't forget…\n"
# 812 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	.string "…Ever…$"
# 813 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"

# 814 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
BattleFrontier_BattlePikeRoomNormal_Text_ChoseRoomNoHeal:
# 815 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	.string "I welcome you…\p"
# 816 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	.string "Giggle…\n"
# 817 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	.string "You seem to be bereft of luck…\p"
# 818 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	.string "If only you hadn't chosen this room,\n"
# 819 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	.string "your POKéMON could have been healed…$"
# 820 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"

# 821 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
BattleFrontier_BattlePikeRoomNormal_Text_ChoseRoomHealOne:
# 822 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	.string "I welcome you…\p"
# 823 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	.string "Since you have chosen this room, I will\n"
# 824 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	.string "restore one POKéMON to full health…$"
# 825 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"

# 826 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
BattleFrontier_BattlePikeRoomNormal_Text_ChoseRoomHealTwo:
# 827 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	.string "I welcome you…\p"
# 828 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	.string "Since you have chosen this room, I will\n"
# 829 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	.string "restore two POKéMON to full health…$"
# 830 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"

# 831 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
@ Unused
# 832 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
BattleFrontier_BattlePikeRoomNormal_Text_WillRestoreAllMons:
# 833 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	.string "I welcome you…\p"
# 834 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	.string "Giggle…\n"
# 835 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	.string "You should thank your lucky stars…\p"
# 836 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	.string "Since you have chosen this room,\n"
# 837 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	.string "all your POKéMON will be restored…$"
# 838 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"

# 839 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
BattleFrontier_BattlePikeRoomNormal_Text_ShallFetchOurMaster:
# 840 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	.string "I shall go fetch our master…$"
# 841 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"

# 842 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
BattleFrontier_BattlePikeRoomNormal_Text_WillRestoreTwoMons:
# 843 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	.string "Ah, you're a lucky one!\n"
# 844 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	.string "I'm in good spirits now.\p"
# 845 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	.string "I will restore two of your POKéMON\n"
# 846 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	.string "to full health!$"
