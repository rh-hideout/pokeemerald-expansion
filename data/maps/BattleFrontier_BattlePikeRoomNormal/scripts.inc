# 1 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"

# 2 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
@ Objects in this room are set dynamically with OBJ_EVENT_GFX_VAR_0 and OBJ_EVENT_GFX_VAR_1
# 3 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
@ Note: LOCALIDs shared with data/scripts/battle_pike.inc
# 4 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
.equ LOCALID_OBJ_0, 1
# 5 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
.equ LOCALID_OBJ_1, 2
# 6 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"

# 7 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
BattleFrontier_BattlePikeRoomNormal_MapScripts::
# 8 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	map_script MAP_SCRIPT_ON_RESUME, BattleFrontier_BattlePikeRoom_OnResume
# 9 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, BattleFrontier_BattlePikeRoom_OnTransition
# 10 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleFrontier_BattlePikeRoomNormal_OnFrame
# 11 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, BattleFrontier_BattlePikeRoom_OnWarp
# 12 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	.byte 0
# 13 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"

# 14 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
BattleFrontier_BattlePikeRoomNormal_OnFrame:
# 15 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	map_script_2 VAR_TEMP_0, 0, BattleFrontier_BattlePikeRoomNormal_EventScript_EnterRoom
# 16 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	.2byte 0
# 17 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"

# 18 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
BattleFrontier_BattlePikeRoomNormal_EventScript_EnterRoom::
# 19 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	setvar VAR_TEMP_0, 1
# 20 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	pike_getroomtype
# 21 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	switch VAR_RESULT
# 22 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	case PIKE_ROOM_SINGLE_BATTLE, BattleFrontier_BattlePikeRoomNormal_EventScript_EnterSingleBattleRoom
# 23 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	case PIKE_ROOM_HEAL_FULL, BattleFrontier_BattlePikeRoomNormal_EventScript_EnterFullHealRoom
# 24 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	case PIKE_ROOM_STATUS, BattleFrontier_BattlePikeRoomNormal_EventScript_EnterStatusRoom
# 25 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	case PIKE_ROOM_HARD_BATTLE, BattleFrontier_BattlePikeRoomNormal_EventScript_EnterHardBattleRoom
# 26 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	case PIKE_ROOM_DOUBLE_BATTLE, BattleFrontier_BattlePikeRoomNormal_EventScript_EnterDoubleBattleRoom
# 27 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	case PIKE_ROOM_BRAIN, BattleFrontier_BattlePikeRoomNormal_EventScript_EnterBrainRoom
# 28 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	end
# 29 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"

# 30 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
BattleFrontier_BattlePikeRoomNormal_EventScript_EnterSingleBattleRoom::
# 31 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	lockall
# 32 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	delay 16
# 33 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	applymovement LOCALID_OBJ_0, BattleFrontier_BattlePikeRoomNormal_Movement_ApproachPlayer
# 34 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	waitmovement 0
# 35 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	pike_gettrainerintro 0
# 36 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	msgbox gStringVar4, MSGBOX_DEFAULT
# 37 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	waitmessage
# 38 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	closemessage
# 39 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	releaseall
# 40 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	setvar VAR_0x8004, SPECIAL_BATTLE_PIKE_SINGLE
# 41 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	setvar VAR_0x8005, 0
# 42 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	special DoSpecialTrainerBattle
# 43 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	waitstate
# 44 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	switch VAR_RESULT
# 45 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	case 1, BattleFrontier_BattlePikeRoomNormal_EventScript_WonSingleBattle
# 46 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
BattleFrontier_BattlePikeRoomNormal_EventScript_WarpToLobbyLost::
# 47 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, CHALLENGE_STATUS_LOST
# 48 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	warp MAP_BATTLE_FRONTIER_BATTLE_PIKE_LOBBY, 5, 6
# 49 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	waitstate
# 50 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	end
# 51 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"

# 52 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
BattleFrontier_BattlePikeRoomNormal_EventScript_WonSingleBattle::
# 53 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	applymovement LOCALID_OBJ_0, BattleFrontier_BattlePikeRoomNormal_Movement_NPCExit
# 54 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	waitmovement 0
# 55 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	end
# 56 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"

# 57 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
BattleFrontier_BattlePikeRoomNormal_EventScript_EnterHardBattleRoom::
# 58 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	lockall
# 59 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	delay 16
# 60 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	msgbox BattleFrontier_BattlePikeRoomNormal_Text_BattleSomewhatToughTrainer, MSGBOX_DEFAULT
# 61 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	waitmessage
# 62 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	closemessage
# 63 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	applymovement LOCALID_OBJ_0, BattleFrontier_BattlePikeRoomNormal_Movement_ApproachPlayer
# 64 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	waitmovement 0
# 65 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	pike_gettrainerintro 0
# 66 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	msgbox gStringVar4, MSGBOX_DEFAULT
# 67 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	waitmessage
# 68 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	closemessage
# 69 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	releaseall
# 70 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	setvar VAR_0x8004, SPECIAL_BATTLE_PIKE_SINGLE
# 71 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	setvar VAR_0x8005, 0
# 72 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	special DoSpecialTrainerBattle
# 73 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	waitstate
# 74 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	switch VAR_RESULT
# 75 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	case 1, BattleFrontier_BattlePikeRoomNormal_EventScript_WonHardBattle
# 76 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	goto BattleFrontier_BattlePikeRoomNormal_EventScript_WarpToLobbyLost
# 77 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	end
# 78 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"

# 79 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
BattleFrontier_BattlePikeRoomNormal_EventScript_WonHardBattle::
# 80 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	applymovement LOCALID_OBJ_0, BattleFrontier_BattlePikeRoomNormal_Movement_NPCExit
# 81 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	waitmovement 0
# 82 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	applymovement LOCALID_OBJ_1, BattleFrontier_BattlePikeRoomNormal_Movement_HealNPCApproachPlayer
# 83 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	waitmovement 0
# 84 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	lock
# 85 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	faceplayer
# 86 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	msgbox BattleFrontier_BattlePikeRoomNormal_Text_RestoreToFullHealth, MSGBOX_DEFAULT
# 87 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	playfanfare MUS_HEAL
# 88 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	waitfanfare
# 89 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	special HealPlayerParty
# 90 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	msgbox BattleFrontier_BattlePikeRoomNormal_Text_EnjoyRestOfChallenge2, MSGBOX_DEFAULT
# 91 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	closemessage
# 92 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	release
# 93 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	applymovement LOCALID_OBJ_1, BattleFrontier_BattlePikeRoomNormal_Movement_NPCExit
# 94 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	waitmovement 0
# 95 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	end
# 96 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"

# 97 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
BattleFrontier_BattlePikeRoomNormal_EventScript_EnterBrainRoom::
# 98 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	delay 22
# 99 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	lockall
# 100 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	applymovement LOCALID_OBJ_1, BattleFrontier_BattlePikeRoomNormal_Movement_PreQueenHealNPCApproachPlayer
# 101 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	waitmovement 0
# 102 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	pike_prequeenheal
# 103 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	switch VAR_RESULT
# 104 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	case 0, BattleFrontier_BattlePikeRoomNormal_EventScript_PreQueenNoHeal
# 105 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	case 1, BattleFrontier_BattlePikeRoomNormal_EventScript_PreQueenHealOneMon
# 106 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	case 2, BattleFrontier_BattlePikeRoomNormal_EventScript_PreQueenHealTwoMons
# 107 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"

# 108 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
BattleFrontier_BattlePikeRoomNormal_EventScript_LucyEnter::
# 109 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	msgbox BattleFrontier_BattlePikeRoomNormal_Text_ShallFetchOurMaster, MSGBOX_DEFAULT
# 110 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	closemessage
# 111 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	special SpawnCameraObject
# 112 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, BattleFrontier_BattlePikeRoomNormal_Movement_CameraPanUp
# 113 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	applymovement LOCALID_OBJ_1, BattleFrontier_BattlePikeRoomNormal_Movement_HealNPCExitForLucy
# 114 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	waitmovement 0
# 115 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	playse SE_PIKE_CURTAIN_CLOSE
# 116 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	call BattleFrontier_BattlePikeRoomNormal_EventScript_SetCurtainTilesLittleClosed
# 117 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	delay 4
# 118 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	call BattleFrontier_BattlePikeRoomNormal_EventScript_SetCurtainTilesMostlyClosed
# 119 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	delay 4
# 120 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	call BattleFrontier_BattlePikeRoomNormal_EventScript_SetCurtainTilesClosed
# 121 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	delay 4
# 122 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	waitse
# 123 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	delay 60
# 124 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	playse SE_PIKE_CURTAIN_OPEN
# 125 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	delay 65
# 126 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	call BattleFrontier_BattlePikeRoomNormal_EventScript_SetCurtainTilesMostlyClosed
# 127 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	showobjectat LOCALID_OBJ_0, MAP_BATTLE_FRONTIER_BATTLE_PIKE_ROOM_NORMAL
# 128 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	delay 4
# 129 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	call BattleFrontier_BattlePikeRoomNormal_EventScript_SetCurtainTilesLittleClosed
# 130 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	delay 4
# 131 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	call BattleFrontier_BattlePikeRoomNormal_EventScript_SetCurtainTilesOpen
# 132 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	waitse
# 133 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	applymovement LOCALID_OBJ_0, BattleFrontier_BattlePikeRoomNormal_Movement_LucyEnter
# 134 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	waitmovement 0
# 135 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	pike_getbrainstatus
# 136 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	switch VAR_RESULT
# 137 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	case FRONTIER_BRAIN_GOLD, BattleFrontier_BattlePikeRoomNormal_EventScript_IntroLucyGold
# 138 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	case FRONTIER_BRAIN_STREAK, BattleFrontier_BattlePikeRoomNormal_EventScript_BattleLucySilver
# 139 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	case FRONTIER_BRAIN_STREAK_LONG, BattleFrontier_BattlePikeRoomNormal_EventScript_BattleLucyGold
# 140 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	frontier_get FRONTIER_DATA_HEARD_BRAIN_SPEECH
# 141 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	goto_if_ne VAR_RESULT, FALSE, BattleFrontier_BattlePikeRoomNormal_EventScript_BattleLucySilver
# 142 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	msgbox BattleFrontier_BattlePikeRoomNormal_Text_ImThePikeQueen, MSGBOX_DEFAULT
# 143 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	frontier_set FRONTIER_DATA_HEARD_BRAIN_SPEECH
# 144 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
BattleFrontier_BattlePikeRoomNormal_EventScript_BattleLucySilver::
# 145 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	msgbox BattleFrontier_BattlePikeRoomNormal_Text_HopeYouDidntUseUpLuck, MSGBOX_DEFAULT
# 146 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	call BattleFrontier_BattlePikeRoomNormal_EventScript_DoPikeQueenBattle
# 147 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	goto_if_eq VAR_RESULT, 1, BattleFrontier_BattlePikeRoomNormal_EventScript_DefeatedLucySilver
# 148 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	goto BattleFrontier_BattlePikeRoomNormal_EventScript_WarpToLobbyLost
# 149 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"

# 150 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
BattleFrontier_BattlePikeRoomNormal_EventScript_DefeatedLucySilver::
# 151 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	frontier_getsymbols
# 152 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	goto_if_ne VAR_RESULT, 0, BattleFrontier_BattlePikeRoomNormal_EventScript_DefeatedLucy
# 153 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	msgbox BattleFrontier_BattlePikeRoomNormal_Text_LucyShowMeFrontierPass, MSGBOX_DEFAULT
# 154 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	waitmessage
# 155 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	playfanfare MUS_OBTAIN_SYMBOL
# 156 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	message BattleFrontier_BattlePikeRoomNormal_Text_ReceivedLuckSymbol
# 157 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	waitmessage
# 158 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	waitfanfare
# 159 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	frontier_givesymbol
# 160 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	msgbox BattleFrontier_BattlePikeRoomNormal_Text_AllThereIsDisappear, MSGBOX_DEFAULT
# 161 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	closemessage
# 162 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	goto BattleFrontier_BattlePikeRoomNormal_EventScript_DefeatedLucy
# 163 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"

# 164 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
BattleFrontier_BattlePikeRoomNormal_EventScript_IntroLucyGold::
# 165 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	frontier_get FRONTIER_DATA_HEARD_BRAIN_SPEECH
# 166 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	goto_if_ne VAR_RESULT, FALSE, BattleFrontier_BattlePikeRoomNormal_EventScript_BattleLucyGold
# 167 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	msgbox BattleFrontier_BattlePikeRoomNormal_Text_LucyYouAgain, MSGBOX_DEFAULT
# 168 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	frontier_set FRONTIER_DATA_HEARD_BRAIN_SPEECH
# 169 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
BattleFrontier_BattlePikeRoomNormal_EventScript_BattleLucyGold::
# 170 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	msgbox BattleFrontier_BattlePikeRoomNormal_Text_NowComeOn, MSGBOX_DEFAULT
# 171 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	call BattleFrontier_BattlePikeRoomNormal_EventScript_DoPikeQueenBattle
# 172 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	goto_if_eq VAR_RESULT, 1, BattleFrontier_BattlePikeRoomNormal_EventScript_DefeatedLucyGold
# 173 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	goto BattleFrontier_BattlePikeRoomNormal_EventScript_WarpToLobbyLost
# 174 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"

# 175 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
BattleFrontier_BattlePikeRoomNormal_EventScript_DefeatedLucyGold::
# 176 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	frontier_getsymbols
# 177 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	goto_if_eq VAR_RESULT, 2, BattleFrontier_BattlePikeRoomNormal_EventScript_DefeatedLucy
# 178 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	msgbox BattleFrontier_BattlePikeRoomNormal_Text_LucyFrontierPass, MSGBOX_DEFAULT
# 179 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	waitmessage
# 180 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	playfanfare MUS_OBTAIN_SYMBOL
# 181 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	message BattleFrontier_BattlePikeRoomNormal_Text_LuckSymbolTookGoldenShine
# 182 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	waitmessage
# 183 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	waitfanfare
# 184 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	frontier_givesymbol
# 185 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	msgbox BattleFrontier_BattlePikeRoomNormal_Text_IWontForget, MSGBOX_DEFAULT
# 186 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	closemessage
# 187 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	goto BattleFrontier_BattlePikeRoomNormal_EventScript_DefeatedLucy
# 188 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	end
# 189 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"

# 190 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
BattleFrontier_BattlePikeRoomNormal_EventScript_DefeatedLucy::
# 191 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	applymovement LOCALID_OBJ_0, BattleFrontier_BattlePikeRoomNormal_Movement_LucyMoveAside
# 192 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	waitmovement 0
# 193 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, BattleFrontier_BattlePikeRoomNormal_Movement_PlayerWalkUp2
# 194 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	waitmovement 0
# 195 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	pike_get PIKE_DATA_WIN_STREAK
# 196 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	addvar VAR_RESULT, 1
# 197 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	pike_set PIKE_DATA_WIN_STREAK, VAR_RESULT
# 198 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	call BattleFrontier_BattlePikeRoom_EventScript_WarpToFinalRoom
# 199 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	waitstate
# 200 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	end
# 201 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"

# 202 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
BattleFrontier_BattlePikeRoomNormal_EventScript_PreQueenNoHeal::
# 203 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	msgbox BattleFrontier_BattlePikeRoomNormal_Text_ChoseRoomNoHeal, MSGBOX_DEFAULT
# 204 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	goto BattleFrontier_BattlePikeRoomNormal_EventScript_LucyEnter
# 205 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	end
# 206 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"

# 207 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
BattleFrontier_BattlePikeRoomNormal_EventScript_PreQueenHealOneMon::
# 208 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	msgbox BattleFrontier_BattlePikeRoomNormal_Text_ChoseRoomHealOne, MSGBOX_DEFAULT
# 209 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	playfanfare MUS_HEAL
# 210 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	waitfanfare
# 211 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	goto BattleFrontier_BattlePikeRoomNormal_EventScript_LucyEnter
# 212 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	end
# 213 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"

# 214 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
BattleFrontier_BattlePikeRoomNormal_EventScript_PreQueenHealTwoMons::
# 215 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	msgbox BattleFrontier_BattlePikeRoomNormal_Text_ChoseRoomHealTwo, MSGBOX_DEFAULT
# 216 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	playfanfare MUS_HEAL
# 217 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	waitfanfare
# 218 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	goto BattleFrontier_BattlePikeRoomNormal_EventScript_LucyEnter
# 219 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	end
# 220 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"

# 221 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
BattleFrontier_BattlePikeRoomNormal_EventScript_EnterFullHealRoom::
# 222 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	lockall
# 223 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	delay 16
# 224 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	applymovement LOCALID_OBJ_0, BattleFrontier_BattlePikeRoomNormal_Movement_ApproachPlayer
# 225 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	waitmovement 0
# 226 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	message BattleFrontier_BattlePikeRoomNormal_Text_WillRestoreToFullHealth
# 227 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	waitmessage
# 228 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	playfanfare MUS_HEAL
# 229 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	waitfanfare
# 230 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	special HealPlayerParty
# 231 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	msgbox BattleFrontier_BattlePikeRoomNormal_Text_EnjoyRestOfChallenge, MSGBOX_DEFAULT
# 232 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	closemessage
# 233 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	applymovement LOCALID_OBJ_0, BattleFrontier_BattlePikeRoomNormal_Movement_NPCExit
# 234 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	waitmovement 0
# 235 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	releaseall
# 236 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	end
# 237 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"

# 238 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
BattleFrontier_BattlePikeRoomNormal_EventScript_EnterDoubleBattleRoom::
# 239 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	lockall
# 240 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	delay 16
# 241 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	applymovement LOCALID_OBJ_0, BattleFrontier_BattlePikeRoomNormal_Movement_Trainer1WalkRight
# 242 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	applymovement LOCALID_OBJ_1, BattleFrontier_BattlePikeRoomNormal_Movement_Trainer2WalkLeft
# 243 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	waitmovement 0
# 244 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	applymovement LOCALID_OBJ_0, BattleFrontier_BattlePikeRoomNormal_Movement_DoubleTrainersWalkDown
# 245 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	applymovement LOCALID_OBJ_1, BattleFrontier_BattlePikeRoomNormal_Movement_DoubleTrainersWalkDown
# 246 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	waitmovement 0
# 247 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	applymovement LOCALID_OBJ_0, BattleFrontier_BattlePikeRoomNormal_Movement_Trainer1FacePlayer
# 248 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	applymovement LOCALID_OBJ_1, BattleFrontier_BattlePikeRoomNormal_Movement_Trainer2FacePlayer
# 249 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	waitmovement 0
# 250 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, BattleFrontier_BattlePikeRoomNormal_Movement_PlayerFaceTrainer1
# 251 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	waitmovement 0
# 252 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	pike_gettrainerintro 0
# 253 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	msgbox gStringVar4, MSGBOX_DEFAULT
# 254 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	closemessage
# 255 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	delay 16
# 256 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, BattleFrontier_BattlePikeRoomNormal_Movement_PlayerFaceTrainer2
# 257 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	waitmovement 0
# 258 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	pike_gettrainerintro 1
# 259 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	msgbox gStringVar4, MSGBOX_DEFAULT
# 260 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	closemessage
# 261 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	setvar VAR_0x8004, SPECIAL_BATTLE_PIKE_DOUBLE
# 262 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	setvar VAR_0x8005, 0
# 263 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	special DoSpecialTrainerBattle
# 264 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	waitstate
# 265 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	switch VAR_RESULT
# 266 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	case 1, BattleFrontier_BattlePikeRoomNormal_EventScript_WonDoubleBattle
# 267 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	goto BattleFrontier_BattlePikeRoomNormal_EventScript_WarpToLobbyLost
# 268 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	end
# 269 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"

# 270 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
BattleFrontier_BattlePikeRoomNormal_EventScript_WonDoubleBattle::
# 271 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, BattleFrontier_BattlePikeRoomNormal_Movement_PlayerFaceTrainer2
# 272 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	waitmovement 0
# 273 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	applymovement LOCALID_OBJ_0, BattleFrontier_BattlePikeRoomNormal_Movement_Trainer1Exit
# 274 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	waitmovement 0
# 275 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	applymovement LOCALID_OBJ_1, BattleFrontier_BattlePikeRoomNormal_Movement_Trainer2Exit
# 276 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	waitmovement 0
# 277 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, BattleFrontier_BattlePikeRoomNormal_Movement_PlayerFaceUp
# 278 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	waitmovement 0
# 279 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	end
# 280 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"

# 281 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
BattleFrontier_BattlePikeRoomNormal_EventScript_EnterStatusRoom::
# 282 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	lockall
# 283 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	message BattleFrontier_BattlePikeRoomNormal_Text_WatchOut
# 284 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	applymovement LOCALID_OBJ_1, BattleFrontier_BattlePikeRoomNormal_Movement_MonApproachPlayer
# 285 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	waitmovement 0
# 286 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	pike_getstatusmon
# 287 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	copyvar VAR_0x8004, VAR_RESULT
# 288 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	call_if_eq VAR_0x8004, PIKE_STATUSMON_KIRLIA, BattleFrontier_BattlePikeRoomNormal_EventScript_KirliaAttack
# 289 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	call_if_eq VAR_0x8004, PIKE_STATUSMON_DUSCLOPS, BattleFrontier_BattlePikeRoomNormal_EventScript_DusclopsAttack
# 290 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	msgbox BattleFrontier_BattlePikeRoomNormal_Text_AttacksWhenStartled, MSGBOX_DEFAULT
# 291 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	closemessage
# 292 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	releaseall
# 293 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	end
# 294 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"

# 295 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
BattleFrontier_BattlePikeRoomNormal_EventScript_KirliaAttack::
# 296 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	msgbox BattleFrontier_BattlePikeRoomNormal_Text_KirliaStop, MSGBOX_DEFAULT
# 297 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	closemessage
# 298 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	waitse
# 299 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	playmoncry SPECIES_KIRLIA, CRY_MODE_NORMAL
# 300 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	waitmoncry
# 301 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	pike_getstatus
# 302 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	call_if_eq VAR_RESULT, PIKE_STATUS_TOXIC, BattleFrontier_BattlePikeRoomNormal_EventScript_KirliaUsedToxic
# 303 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	call_if_eq VAR_RESULT, PIKE_STATUS_BURN, BattleFrontier_BattlePikeRoomNormal_EventScript_KirliaUsedWillOWisp
# 304 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	call_if_eq VAR_RESULT, PIKE_STATUS_PARALYSIS, BattleFrontier_BattlePikeRoomNormal_EventScript_KirliaUsedThunderWave
# 305 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	call_if_eq VAR_RESULT, PIKE_STATUS_SLEEP, BattleFrontier_BattlePikeRoomNormal_EventScript_KirliaUsedHypnosis
# 306 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	pike_flashscreen
# 307 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	waitstate
# 308 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	applymovement LOCALID_OBJ_0, BattleFrontier_BattlePikeRoomNormal_Movement_NPCApproachMon
# 309 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	waitmovement 0
# 310 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	applymovement LOCALID_OBJ_1, BattleFrontier_BattlePikeRoomNormal_Movement_MonFaceNPC
# 311 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	waitmovement 0
# 312 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	waitse
# 313 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	playmoncry SPECIES_KIRLIA, CRY_MODE_NORMAL
# 314 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	waitmoncry
# 315 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	msgbox BattleFrontier_BattlePikeRoomNormal_Text_ThatsEnough, MSGBOX_DEFAULT
# 316 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	waitse
# 317 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	playmoncry SPECIES_KIRLIA, CRY_MODE_NORMAL
# 318 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	waitmoncry
# 319 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	closemessage
# 320 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	applymovement LOCALID_OBJ_1, BattleFrontier_BattlePikeRoomNormal_Movement_MonMoveAside
# 321 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	applymovement LOCALID_OBJ_0, BattleFrontier_BattlePikeRoomNormal_Movement_StatusNPCApproachPlayer
# 322 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	waitmovement 0
# 323 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	msgbox BattleFrontier_BattlePikeRoomNormal_Text_ApologizeForKirlia, MSGBOX_DEFAULT
# 324 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	return
# 325 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"

# 326 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
BattleFrontier_BattlePikeRoomNormal_EventScript_DusclopsAttack::
# 327 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	msgbox BattleFrontier_BattlePikeRoomNormal_Text_DusclopsStop, MSGBOX_DEFAULT
# 328 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	closemessage
# 329 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	waitse
# 330 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	playmoncry SPECIES_DUSCLOPS, CRY_MODE_NORMAL
# 331 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	waitmoncry
# 332 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	pike_getstatus
# 333 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	call_if_eq VAR_RESULT, PIKE_STATUS_FREEZE, BattleFrontier_BattlePikeRoomNormal_EventScript_DusclopsUsedIceBeam
# 334 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	call_if_eq VAR_RESULT, PIKE_STATUS_BURN, BattleFrontier_BattlePikeRoomNormal_EventScript_DusclopsUsedWillOWisp
# 335 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	pike_flashscreen
# 336 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	waitstate
# 337 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	applymovement LOCALID_OBJ_0, BattleFrontier_BattlePikeRoomNormal_Movement_NPCApproachMon
# 338 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	waitmovement 0
# 339 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	applymovement LOCALID_OBJ_1, BattleFrontier_BattlePikeRoomNormal_Movement_MonFaceNPC
# 340 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	waitmovement 0
# 341 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	waitse
# 342 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	playmoncry SPECIES_DUSCLOPS, CRY_MODE_NORMAL
# 343 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	waitmoncry
# 344 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	msgbox BattleFrontier_BattlePikeRoomNormal_Text_ThatsEnough, MSGBOX_DEFAULT
# 345 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	waitse
# 346 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	playmoncry SPECIES_DUSCLOPS, CRY_MODE_NORMAL
# 347 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	waitmoncry
# 348 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	closemessage
# 349 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	applymovement LOCALID_OBJ_1, BattleFrontier_BattlePikeRoomNormal_Movement_MonMoveAside
# 350 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	applymovement LOCALID_OBJ_0, BattleFrontier_BattlePikeRoomNormal_Movement_StatusNPCApproachPlayer
# 351 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	waitmovement 0
# 352 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	msgbox BattleFrontier_BattlePikeRoomNormal_Text_ApologizeForDusclops, MSGBOX_DEFAULT
# 353 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	return
# 354 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"

# 355 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
BattleFrontier_BattlePikeRoomNormal_EventScript_KirliaUsedToxic::
# 356 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	message BattleFrontier_BattlePikeRoomNormal_Text_KirliaUsedToxic
# 357 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	waitmessage
# 358 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	return
# 359 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"

# 360 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
BattleFrontier_BattlePikeRoomNormal_EventScript_KirliaUsedWillOWisp::
# 361 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	message BattleFrontier_BattlePikeRoomNormal_Text_KirliaUsedWillOWisp
# 362 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	waitmessage
# 363 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	return
# 364 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"

# 365 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
BattleFrontier_BattlePikeRoomNormal_EventScript_KirliaUsedThunderWave::
# 366 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	message BattleFrontier_BattlePikeRoomNormal_Text_KirliaUsedThunderWave
# 367 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	waitmessage
# 368 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	return
# 369 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"

# 370 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
BattleFrontier_BattlePikeRoomNormal_EventScript_KirliaUsedHypnosis::
# 371 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	message BattleFrontier_BattlePikeRoomNormal_Text_KirliaUsedHypnosis
# 372 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	waitmessage
# 373 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	return
# 374 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"

# 375 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
BattleFrontier_BattlePikeRoomNormal_EventScript_DusclopsUsedIceBeam::
# 376 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	message BattleFrontier_BattlePikeRoomNormal_Text_DusclopsUsedIceBeam
# 377 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	waitmessage
# 378 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	return
# 379 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"

# 380 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
BattleFrontier_BattlePikeRoomNormal_EventScript_DusclopsUsedWillOWisp::
# 381 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	message BattleFrontier_BattlePikeRoomNormal_Text_DusclopsUsedWillOWisp
# 382 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	waitmessage
# 383 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	return
# 384 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"

# 385 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
BattleFrontier_BattlePikeRoomNormal_EventScript_DoPikeQueenBattle::
# 386 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	closemessage
# 387 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, BattleFrontier_BattlePikeRoomNormal_Movement_PlayerWalkUp2
# 388 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	waitmovement 0
# 389 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	setvar VAR_0x8004, SPECIAL_BATTLE_PIKE_SINGLE
# 390 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	setvar VAR_0x8005, 0
# 391 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	special DoSpecialTrainerBattle
# 392 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	waitstate
# 393 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	return
# 394 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"

# 395 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
BattleFrontier_BattlePikeRoomNormal_Movement_ApproachPlayer:
# 396 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	walk_down
# 397 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	walk_down
# 398 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	step_end
# 399 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"

# 400 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
BattleFrontier_BattlePikeRoomNormal_Movement_NPCExit:
# 401 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	walk_up
# 402 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	walk_up
# 403 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	walk_up
# 404 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	set_invisible
# 405 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	walk_up
# 406 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	step_end
# 407 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"

# 408 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
BattleFrontier_BattlePikeRoomNormal_Movement_HealNPCExit:
# 409 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	walk_up
# 410 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	set_invisible
# 411 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	walk_up
# 412 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	step_end
# 413 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"

# 414 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
BattleFrontier_BattlePikeRoomNormal_Movement_NPCApproachMon:
# 415 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	walk_down
# 416 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	step_end
# 417 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"

# 418 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
BattleFrontier_BattlePikeRoomNormal_Movement_StatusNPCApproachPlayer:
# 419 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	walk_down
# 420 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	face_left
# 421 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	delay_16
# 422 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	delay_16
# 423 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	face_down
# 424 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	step_end
# 425 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"

# 426 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
BattleFrontier_BattlePikeRoomNormal_Movement_MonApproachPlayer:
# 427 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	walk_fast_down
# 428 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	walk_fast_right
# 429 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	walk_fast_right
# 430 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	walk_fast_down
# 431 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	walk_fast_left
# 432 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	face_down
# 433 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	step_end
# 434 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"

# 435 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
BattleFrontier_BattlePikeRoomNormal_Movement_MonFaceNPC:
# 436 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	face_up
# 437 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	step_end
# 438 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"

# 439 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
BattleFrontier_BattlePikeRoomNormal_Movement_MonMoveAside:
# 440 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	walk_left
# 441 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
BattleFrontier_BattlePikeRoomNormal_Movement_MonFaceRight:
# 442 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	face_right
# 443 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	step_end
# 444 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"

# 445 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
BattleFrontier_BattlePikeRoomNormal_Movement_HealNPCApproachPlayer:
# 446 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	walk_down
# 447 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	walk_down
# 448 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	walk_right
# 449 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	face_down
# 450 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	step_end
# 451 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"

# 452 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
BattleFrontier_BattlePikeRoomNormal_Movement_PlayerFaceTrainer1:
# 453 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	face_left
# 454 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	step_end
# 455 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"

# 456 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
BattleFrontier_BattlePikeRoomNormal_Movement_PlayerFaceTrainer2:
# 457 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	face_right
# 458 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	step_end
# 459 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"

# 460 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
BattleFrontier_BattlePikeRoomNormal_Movement_PlayerFaceUp:
# 461 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	face_up
# 462 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	step_end
# 463 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"

# 464 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
BattleFrontier_BattlePikeRoomNormal_Movement_Trainer1WalkRight:
# 465 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	walk_right
# 466 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	step_end
# 467 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"

# 468 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
BattleFrontier_BattlePikeRoomNormal_Movement_Trainer2WalkLeft:
# 469 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	walk_left
# 470 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	step_end
# 471 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"

# 472 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
BattleFrontier_BattlePikeRoomNormal_Movement_DoubleTrainersWalkDown:
# 473 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	walk_down
# 474 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	walk_down
# 475 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	step_end
# 476 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"

# 477 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
BattleFrontier_BattlePikeRoomNormal_Movement_Trainer1FacePlayer:
# 478 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	face_right
# 479 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	step_end
# 480 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"

# 481 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
BattleFrontier_BattlePikeRoomNormal_Movement_Trainer2FacePlayer:
# 482 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	face_left
# 483 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	step_end
# 484 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"

# 485 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
BattleFrontier_BattlePikeRoomNormal_Movement_Trainer1Exit:
# 486 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	walk_up
# 487 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	walk_up
# 488 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	walk_up
# 489 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	walk_right
# 490 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	walk_up
# 491 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	set_invisible
# 492 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	walk_up
# 493 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	step_end
# 494 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"

# 495 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
BattleFrontier_BattlePikeRoomNormal_Movement_Trainer2Exit:
# 496 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	walk_up
# 497 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	walk_up
# 498 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	walk_up
# 499 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	walk_left
# 500 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	walk_up
# 501 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	set_invisible
# 502 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	walk_up
# 503 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	step_end
# 504 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"

# 505 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
@ For approaching Lucy and exiting room after defeating Lucy
# 506 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
BattleFrontier_BattlePikeRoomNormal_Movement_PlayerWalkUp2:
# 507 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	walk_up
# 508 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	walk_up
# 509 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	step_end
# 510 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"

# 511 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
BattleFrontier_BattlePikeRoomNormal_Movement_PreQueenHealNPCApproachPlayer:
# 512 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	walk_down
# 513 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	walk_down
# 514 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	step_end
# 515 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"

# 516 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
BattleFrontier_BattlePikeRoomNormal_Movement_HealNPCExitForLucy:
# 517 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	walk_up
# 518 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	walk_up
# 519 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	walk_up
# 520 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	set_invisible
# 521 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	step_end
# 522 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"

# 523 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
BattleFrontier_BattlePikeRoomNormal_Movement_LucyEnter:
# 524 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	set_visible
# 525 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	walk_down
# 526 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	step_end
# 527 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"

# 528 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
BattleFrontier_BattlePikeRoomNormal_Movement_LucyMoveAside:
# 529 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	walk_left
# 530 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	face_right
# 531 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	step_end
# 532 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"

# 533 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
BattleFrontier_BattlePikeRoomNormal_EventScript_NPC::
# 534 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	pike_getroomtype
# 535 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	switch VAR_RESULT
# 536 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	case PIKE_ROOM_NPC, BattleFrontier_BattlePikeRoomNormal_EventScript_NormalNPC
# 537 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	case PIKE_ROOM_STATUS, BattleFrontier_BattlePikeRoomNormal_EventScript_StatusNPC
# 538 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	case PIKE_ROOM_HEAL_PART, BattleFrontier_BattlePikeRoomNormal_EventScript_HealNPC
# 539 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
BattleFrontier_BattlePikeRoomNormal_EventScript_NormalNPC::
# 540 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	lock
# 541 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	faceplayer
# 542 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	pike_getnpcmsg
# 543 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	msgbox gStringVar4, MSGBOX_DEFAULT
# 544 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	waitmessage
# 545 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	closemessage
# 546 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	release
# 547 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	end
# 548 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"

# 549 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
BattleFrontier_BattlePikeRoomNormal_EventScript_StatusNPC::
# 550 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	lock
# 551 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	faceplayer
# 552 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	msgbox BattleFrontier_BattlePikeRoomNormal_Text_ApologizeHopeMonsAreFine, MSGBOX_DEFAULT
# 553 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	closemessage
# 554 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	release
# 555 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	end
# 556 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"

# 557 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
BattleFrontier_BattlePikeRoomNormal_EventScript_HealNPC::
# 558 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	pike_healonetwomons
# 559 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	call_if_eq VAR_RESULT, 2, BattleFrontier_BattlePikeRoomNormal_EventScript_WillRestoreTwoMons
# 560 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	call_if_eq VAR_RESULT, 1, BattleFrontier_BattlePikeRoomNormal_EventScript_WillRestoreOneMon
# 561 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	playfanfare MUS_HEAL
# 562 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	waitfanfare
# 563 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	msgbox BattleFrontier_BattlePikeRoomNormal_Text_BestOfLuckFarewell, MSGBOX_DEFAULT
# 564 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	closemessage
# 565 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	release
# 566 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	applymovement LOCALID_OBJ_0, BattleFrontier_BattlePikeRoomNormal_Movement_HealNPCExit
# 567 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	waitmovement 0
# 568 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	end
# 569 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"

# 570 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
BattleFrontier_BattlePikeRoomNormal_EventScript_WillRestoreOneMon::
# 571 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	lock
# 572 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	faceplayer
# 573 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	msgbox BattleFrontier_BattlePikeRoomNormal_Text_WillRestoreOneMon, MSGBOX_DEFAULT
# 574 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	closemessage
# 575 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	return
# 576 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"

# 577 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
BattleFrontier_BattlePikeRoomNormal_EventScript_WillRestoreTwoMons::
# 578 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	lock
# 579 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	faceplayer
# 580 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	msgbox BattleFrontier_BattlePikeRoomNormal_Text_WillRestoreTwoMons, MSGBOX_DEFAULT
# 581 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	closemessage
# 582 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	return
# 583 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"

# 584 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
@ Dusclops or Kirlia
# 585 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
BattleFrontier_BattlePikeRoomNormal_EventScript_StatusMon::
# 586 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	lock
# 587 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	faceplayer
# 588 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	msgbox BattleFrontier_BattlePikeRoomNormal_Text_Silence, MSGBOX_DEFAULT
# 589 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	closemessage
# 590 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	release
# 591 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	applymovement LOCALID_OBJ_1, BattleFrontier_BattlePikeRoomNormal_Movement_MonFaceRight
# 592 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	waitmovement 0
# 593 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	end
# 594 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"

# 595 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
BattleFrontier_BattlePikeRoomNormal_EventScript_SetCurtainTilesMostlyClosed::
# 596 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	setmetatile 4, 1, METATILE_BattlePike_Curtain_Stage1_Tile0, TRUE
# 597 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	setmetatile 3, 2, METATILE_BattlePike_Curtain_Stage1_Tile1, TRUE
# 598 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	setmetatile 4, 2, METATILE_BattlePike_Curtain_Stage1_Tile2, TRUE
# 599 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	setmetatile 5, 2, METATILE_BattlePike_Curtain_Stage1_Tile3, TRUE
# 600 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	setmetatile 3, 3, METATILE_BattlePike_Curtain_Stage1_Tile4, TRUE
# 601 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	setmetatile 4, 3, METATILE_BattlePike_Curtain_Stage1_Tile5, FALSE
# 602 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	setmetatile 5, 3, METATILE_BattlePike_Curtain_Stage1_Tile6, TRUE
# 603 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	special DrawWholeMapView
# 604 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	return
# 605 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"

# 606 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
BattleFrontier_BattlePikeRoomNormal_EventScript_SetCurtainTilesLittleClosed::
# 607 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	setmetatile 4, 1, METATILE_BattlePike_Curtain_Stage2_Tile0, TRUE
# 608 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	setmetatile 3, 2, METATILE_BattlePike_Curtain_Stage2_Tile1, TRUE
# 609 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	setmetatile 4, 2, METATILE_BattlePike_Curtain_Stage2_Tile2, TRUE
# 610 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	setmetatile 5, 2, METATILE_BattlePike_Curtain_Stage2_Tile3, TRUE
# 611 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	setmetatile 3, 3, METATILE_BattlePike_Curtain_Stage2_Tile4, TRUE
# 612 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	setmetatile 4, 3, METATILE_BattlePike_Curtain_Stage2_Tile5, FALSE
# 613 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	setmetatile 5, 3, METATILE_BattlePike_Curtain_Stage2_Tile6, TRUE
# 614 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	special DrawWholeMapView
# 615 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	return
# 616 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"

# 617 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
BattleFrontier_BattlePikeRoomNormal_EventScript_SetCurtainTilesOpen::
# 618 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	setmetatile 4, 1, METATILE_BattlePike_Curtain_Stage3_Tile0, TRUE
# 619 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	setmetatile 3, 2, METATILE_BattlePike_Curtain_Stage3_Tile1, TRUE
# 620 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	setmetatile 4, 2, METATILE_BattlePike_Curtain_Stage3_Tile2, TRUE
# 621 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	setmetatile 5, 2, METATILE_BattlePike_Curtain_Stage3_Tile3, TRUE
# 622 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	setmetatile 3, 3, METATILE_BattlePike_Curtain_Stage3_Tile4, TRUE
# 623 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	setmetatile 4, 3, METATILE_BattlePike_Curtain_Stage3_Tile5, FALSE
# 624 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	setmetatile 5, 3, METATILE_BattlePike_Curtain_Stage3_Tile6, TRUE
# 625 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	special DrawWholeMapView
# 626 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	return
# 627 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"

# 628 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
BattleFrontier_BattlePikeRoomNormal_EventScript_SetCurtainTilesClosed::
# 629 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	setmetatile 4, 1, METATILE_BattlePike_Curtain_Stage0_Tile0, TRUE
# 630 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	setmetatile 3, 2, METATILE_BattlePike_Curtain_Stage0_Tile1, TRUE
# 631 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	setmetatile 4, 2, METATILE_BattlePike_Curtain_Stage0_Tile2, TRUE
# 632 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	setmetatile 5, 2, METATILE_BattlePike_Curtain_Stage0_Tile3, TRUE
# 633 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	setmetatile 3, 3, METATILE_BattlePike_Curtain_Stage0_Tile4, TRUE
# 634 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	setmetatile 4, 3, METATILE_BattlePike_Curtain_Stage0_Tile5, FALSE
# 635 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	setmetatile 5, 3, METATILE_BattlePike_Curtain_Stage0_Tile6, TRUE
# 636 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	special DrawWholeMapView
# 637 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	return
# 638 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"

# 639 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
BattleFrontier_BattlePikeRoomNormal_Movement_CameraPanUp:
# 640 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	walk_up
# 641 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	walk_up
# 642 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	step_end
# 643 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"

# 644 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
@ Unused
# 645 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
BattleFrontier_BattlePikeRoomNormal_Movement_CameraPanDown:
# 646 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	walk_down
# 647 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	walk_down
# 648 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	step_end
# 649 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"

# 650 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
BattleFrontier_BattlePikeRoomNormal_Text_WillRestoreToFullHealth:
# 651 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	.string "Welcome…\n"
# 652 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	.string "You must be commended for your luck…\p"
# 653 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	.string "Your POKéMON shall be restored\n"
# 654 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	.string "to full health…$"
# 655 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"

# 656 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
BattleFrontier_BattlePikeRoomNormal_Text_EnjoyRestOfChallenge:
# 657 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	.string "I urge you to enjoy the rest of your\n"
# 658 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	.string "Battle Choice challenge…$"
# 659 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"

# 660 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
BattleFrontier_BattlePikeRoomNormal_Text_WillRestoreOneMon:
# 661 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	.string "Ah, you're a lucky one.\n"
# 662 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	.string "I'm in somewhat-good spirits now.\p"
# 663 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	.string "I will restore one of your POKéMON\n"
# 664 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	.string "to full health.$"
# 665 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"

# 666 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
BattleFrontier_BattlePikeRoomNormal_Text_BestOfLuckFarewell:
# 667 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	.string "The best of luck to you.\n"
# 668 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	.string "Farewell.$"
# 669 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"

# 670 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
@ Seems there was a planned room type where the player could choose to battle and would be healed if they won
# 671 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
@ Possibly replaced/superseded by the hard battle room, which is the same but the battle isnt optional
# 672 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
@ Unused
# 673 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
BattleFrontier_BattlePikeRoomNormal_Text_CareForBattleWillRestoreMons:
# 674 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	.string "Excuse me…\p"
# 675 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	.string "Would you care for a battle?\n"
# 676 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	.string "I'll restore your POKéMON if you win.$"
# 677 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"

# 678 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
@ Unused
# 679 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
BattleFrontier_BattlePikeRoomNormal_Text_NowShallWe:
# 680 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	.string "Very well…\n"
# 681 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	.string "Now, shall we?$"
# 682 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"

# 683 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
@ Unused
# 684 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
BattleFrontier_BattlePikeRoomNormal_Text_HowUnsportingOfYou:
# 685 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	.string "I see…\n"
# 686 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	.string "How unsporting of you…$"
# 687 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"

# 688 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
@ Unused
# 689 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
BattleFrontier_BattlePikeRoomNormal_Text_WillRestoreMonsAsPromised:
# 690 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	.string "Magnificent…\p"
# 691 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	.string "As promised, I shall restore your\n"
# 692 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	.string "POKéMON to full health.$"
# 693 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"

# 694 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
@ Unused
# 695 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
BattleFrontier_BattlePikeRoomNormal_Text_BestOfLuckFarewell2:
# 696 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	.string "The best of luck to you.\n"
# 697 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	.string "Farewell.$"
# 698 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"

# 699 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
BattleFrontier_BattlePikeRoomNormal_Text_WatchOut:
# 700 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	.string "Oh, my!\p"
# 701 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	.string "Watch out!$"
# 702 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"

# 703 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
BattleFrontier_BattlePikeRoomNormal_Text_KirliaStop:
# 704 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	.string "Now, now!\n"
# 705 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	.string "KIRLIA, stop that!$"
# 706 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"

# 707 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
BattleFrontier_BattlePikeRoomNormal_Text_DusclopsStop:
# 708 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	.string "Now, now!\n"
# 709 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	.string "DUSCLOPS, stop that!$"
# 710 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"

# 711 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
BattleFrontier_BattlePikeRoomNormal_Text_KirliaUsedToxic:
# 712 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	.string "KIRLIA used TOXIC!$"
# 713 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"

# 714 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
BattleFrontier_BattlePikeRoomNormal_Text_KirliaUsedHypnosis:
# 715 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	.string "KIRLIA used HYPNOSIS!$"
# 716 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"

# 717 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
BattleFrontier_BattlePikeRoomNormal_Text_KirliaUsedThunderWave:
# 718 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	.string "KIRLIA used THUNDER WAVE!$"
# 719 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"

# 720 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
BattleFrontier_BattlePikeRoomNormal_Text_KirliaUsedWillOWisp:
# 721 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	.string "KIRLIA used WILL-O-WISP!$"
# 722 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"

# 723 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
BattleFrontier_BattlePikeRoomNormal_Text_DusclopsUsedWillOWisp:
# 724 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	.string "DUSCLOPS used WILL-O-WISP!$"
# 725 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"

# 726 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
BattleFrontier_BattlePikeRoomNormal_Text_DusclopsUsedIceBeam:
# 727 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	.string "DUSCLOPS used ICE BEAM!$"
# 728 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"

# 729 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
BattleFrontier_BattlePikeRoomNormal_Text_ThatsEnough:
# 730 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	.string "Look here!\n"
# 731 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	.string "That's quite enough!$"
# 732 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"

# 733 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
BattleFrontier_BattlePikeRoomNormal_Text_ApologizeForKirlia:
# 734 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	.string "I must apologize to you…\p"
# 735 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	.string "My KIRLIA has a TIMID nature…$"
# 736 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"

# 737 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
BattleFrontier_BattlePikeRoomNormal_Text_ApologizeForDusclops:
# 738 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	.string "I must apologize to you…\p"
# 739 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	.string "My DUSCLOPS has a TIMID nature…$"
# 740 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"

# 741 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
BattleFrontier_BattlePikeRoomNormal_Text_AttacksWhenStartled:
# 742 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	.string "It attacks without warning if it is\n"
# 743 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	.string "startled by another person…\p"
# 744 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	.string "Are you and your POKéMON all right?$"
# 745 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"

# 746 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
BattleFrontier_BattlePikeRoomNormal_Text_ApologizeHopeMonsAreFine:
# 747 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	.string "I do apologize for what happened…\n"
# 748 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	.string "I do hope your POKéMON are fine.$"
# 749 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"

# 750 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
BattleFrontier_BattlePikeRoomNormal_Text_Silence:
# 751 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	.string "… … … … … …\n"
# 752 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	.string "… … … … … …$"
# 753 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"

# 754 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
BattleFrontier_BattlePikeRoomNormal_Text_BattleSomewhatToughTrainer:
# 755 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	.string "Welcome…\p"
# 756 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	.string "Here, we will have you battle\n"
# 757 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	.string "a somewhat-tough TRAINER…$"
# 758 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"

# 759 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
BattleFrontier_BattlePikeRoomNormal_Text_RestoreToFullHealth:
# 760 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	.string "How wonderful…\p"
# 761 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	.string "To honor your victory, your POKéMON\n"
# 762 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	.string "shall be restored to full health…$"
# 763 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"

# 764 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
BattleFrontier_BattlePikeRoomNormal_Text_EnjoyRestOfChallenge2:
# 765 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	.string "I urge you to enjoy the rest of your\n"
# 766 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	.string "Battle Choice challenge…$"
# 767 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"

# 768 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
BattleFrontier_BattlePikeRoomNormal_Text_ImThePikeQueen:
# 769 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	.string "I am LUCY…\n"
# 770 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	.string "I am the law here…\l"
# 771 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	.string "For I am the PIKE QUEEN…\p"
# 772 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	.string "You already know it, but to advance,\n"
# 773 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	.string "you must defeat me…\p"
# 774 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	.string "…I'm not one for idle chatter.\n"
# 775 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	.string "Hurry. Come on…$"
# 776 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"

# 777 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
BattleFrontier_BattlePikeRoomNormal_Text_HopeYouDidntUseUpLuck:
# 778 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	.string "Your luck…\n"
# 779 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	.string "I hope you didn't use it all up here…$"
# 780 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"

# 781 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
BattleFrontier_BattlePikeRoomNormal_Text_LucyShowMeFrontierPass:
# 782 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	.string "LUCY: … … … … … …\n"
# 783 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	.string "Show me your FRONTIER PASS…$"
# 784 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"

# 785 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
BattleFrontier_BattlePikeRoomNormal_Text_ReceivedLuckSymbol:
# 786 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	.string "The Luck Symbol was embossed on\n"
# 787 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	.string "the FRONTIER PASS!$"
# 788 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"

# 789 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
BattleFrontier_BattlePikeRoomNormal_Text_AllThereIsDisappear:
# 790 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	.string "…That's all there is…\n"
# 791 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	.string "Disappear already…$"
# 792 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"

# 793 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
BattleFrontier_BattlePikeRoomNormal_Text_LucyYouAgain:
# 794 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	.string "LUCY: …You again…\p"
# 795 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	.string "… … … … … …\p"
# 796 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	.string "…I've trampled flowers and braved\n"
# 797 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	.string "storms to get to where I am…\p"
# 798 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	.string "I don't feel any compulsion to keep\n"
# 799 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	.string "losing to the same opponent…\p"
# 800 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	.string "… … … … … …\n"
# 801 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	.string "Fine… I'll do it…$"
# 802 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"

# 803 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
BattleFrontier_BattlePikeRoomNormal_Text_NowComeOn:
# 804 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	.string "Now!\n"
# 805 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	.string "Come on!$"
# 806 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"

# 807 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
BattleFrontier_BattlePikeRoomNormal_Text_LucyFrontierPass:
# 808 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	.string "LUCY: … … … … … …\p"
# 809 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	.string "…FRONTIER PASS…$"
# 810 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"

# 811 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
BattleFrontier_BattlePikeRoomNormal_Text_LuckSymbolTookGoldenShine:
# 812 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	.string "The Luck Symbol took on\n"
# 813 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	.string "a golden shine!$"
# 814 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"

# 815 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
BattleFrontier_BattlePikeRoomNormal_Text_IWontForget:
# 816 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	.string "…You, I won't forget…\n"
# 817 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	.string "…Ever…$"
# 818 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"

# 819 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
BattleFrontier_BattlePikeRoomNormal_Text_ChoseRoomNoHeal:
# 820 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	.string "I welcome you…\p"
# 821 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	.string "Giggle…\n"
# 822 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	.string "You seem to be bereft of luck…\p"
# 823 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	.string "If only you hadn't chosen this room,\n"
# 824 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	.string "your POKéMON could have been healed…$"
# 825 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"

# 826 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
BattleFrontier_BattlePikeRoomNormal_Text_ChoseRoomHealOne:
# 827 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	.string "I welcome you…\p"
# 828 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	.string "Since you have chosen this room, I will\n"
# 829 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	.string "restore one POKéMON to full health…$"
# 830 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"

# 831 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
BattleFrontier_BattlePikeRoomNormal_Text_ChoseRoomHealTwo:
# 832 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	.string "I welcome you…\p"
# 833 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	.string "Since you have chosen this room, I will\n"
# 834 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	.string "restore two POKéMON to full health…$"
# 835 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"

# 836 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
@ Unused
# 837 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
BattleFrontier_BattlePikeRoomNormal_Text_WillRestoreAllMons:
# 838 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	.string "I welcome you…\p"
# 839 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	.string "Giggle…\n"
# 840 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	.string "You should thank your lucky stars…\p"
# 841 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	.string "Since you have chosen this room,\n"
# 842 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	.string "all your POKéMON will be restored…$"
# 843 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"

# 844 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
BattleFrontier_BattlePikeRoomNormal_Text_ShallFetchOurMaster:
# 845 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	.string "I shall go fetch our master…$"
# 846 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"

# 847 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
BattleFrontier_BattlePikeRoomNormal_Text_WillRestoreTwoMons:
# 848 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	.string "Ah, you're a lucky one!\n"
# 849 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	.string "I'm in good spirits now.\p"
# 850 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	.string "I will restore two of your POKéMON\n"
# 851 "data//maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	.string "to full health!$"
