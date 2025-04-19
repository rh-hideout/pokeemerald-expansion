# 1 "data/maps/SlateportCity_BattleTentBattleRoom/scripts.pory"

# 2 "data/maps/SlateportCity_BattleTentBattleRoom/scripts.pory"
.set LOCALID_OPPONENT, 2
# 3 "data/maps/SlateportCity_BattleTentBattleRoom/scripts.pory"
.set LOCALID_PLAYER, 3
# 4 "data/maps/SlateportCity_BattleTentBattleRoom/scripts.pory"

# 5 "data/maps/SlateportCity_BattleTentBattleRoom/scripts.pory"
SlateportCity_BattleTentBattleRoom_MapScripts::
# 6 "data/maps/SlateportCity_BattleTentBattleRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, SlateportCity_BattleTentBattleRoom_OnTransition
# 7 "data/maps/SlateportCity_BattleTentBattleRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, SlateportCity_BattleTentBattleRoom_OnWarp
# 8 "data/maps/SlateportCity_BattleTentBattleRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, SlateportCity_BattleTentBattleRoom_OnFrame
# 9 "data/maps/SlateportCity_BattleTentBattleRoom/scripts.pory"
	.byte 0
# 10 "data/maps/SlateportCity_BattleTentBattleRoom/scripts.pory"

# 11 "data/maps/SlateportCity_BattleTentBattleRoom/scripts.pory"
	@ On this map the player (OBJ_EVENT_ID_PLAYER) is hidden
# 12 "data/maps/SlateportCity_BattleTentBattleRoom/scripts.pory"
	@ The player is represented instead by LOCALID_PLAYER, which has the gfx id VAR_OBJ_GFX_ID_1
# 13 "data/maps/SlateportCity_BattleTentBattleRoom/scripts.pory"

# 14 "data/maps/SlateportCity_BattleTentBattleRoom/scripts.pory"
SlateportCity_BattleTentBattleRoom_OnTransition:
# 15 "data/maps/SlateportCity_BattleTentBattleRoom/scripts.pory"
	call SlateportCity_BattleTentBattleRoom_EventScript_SetPlayerGfx
# 16 "data/maps/SlateportCity_BattleTentBattleRoom/scripts.pory"
	end
# 17 "data/maps/SlateportCity_BattleTentBattleRoom/scripts.pory"

# 18 "data/maps/SlateportCity_BattleTentBattleRoom/scripts.pory"
SlateportCity_BattleTentBattleRoom_EventScript_SetPlayerGfx::
# 19 "data/maps/SlateportCity_BattleTentBattleRoom/scripts.pory"
	checkplayergender
# 20 "data/maps/SlateportCity_BattleTentBattleRoom/scripts.pory"
	goto_if_eq VAR_RESULT, MALE, SlateportCity_BattleTentBattleRoom_EventScript_SetPlayerGfxMale
# 21 "data/maps/SlateportCity_BattleTentBattleRoom/scripts.pory"
	goto_if_eq VAR_RESULT, FEMALE, SlateportCity_BattleTentBattleRoom_EventScript_SetPlayerGfxFemale
# 22 "data/maps/SlateportCity_BattleTentBattleRoom/scripts.pory"
	return
# 23 "data/maps/SlateportCity_BattleTentBattleRoom/scripts.pory"

# 24 "data/maps/SlateportCity_BattleTentBattleRoom/scripts.pory"
SlateportCity_BattleTentBattleRoom_EventScript_SetPlayerGfxMale::
# 25 "data/maps/SlateportCity_BattleTentBattleRoom/scripts.pory"
	setvar VAR_OBJ_GFX_ID_1, OBJ_EVENT_GFX_RIVAL_BRENDAN_NORMAL
# 26 "data/maps/SlateportCity_BattleTentBattleRoom/scripts.pory"
	return
# 27 "data/maps/SlateportCity_BattleTentBattleRoom/scripts.pory"

# 28 "data/maps/SlateportCity_BattleTentBattleRoom/scripts.pory"
SlateportCity_BattleTentBattleRoom_EventScript_SetPlayerGfxFemale::
# 29 "data/maps/SlateportCity_BattleTentBattleRoom/scripts.pory"
	setvar VAR_OBJ_GFX_ID_1, OBJ_EVENT_GFX_RIVAL_MAY_NORMAL
# 30 "data/maps/SlateportCity_BattleTentBattleRoom/scripts.pory"
	return
# 31 "data/maps/SlateportCity_BattleTentBattleRoom/scripts.pory"

# 32 "data/maps/SlateportCity_BattleTentBattleRoom/scripts.pory"
SlateportCity_BattleTentBattleRoom_OnWarp:
# 33 "data/maps/SlateportCity_BattleTentBattleRoom/scripts.pory"
	map_script_2 VAR_TEMP_1, 0, SlateportCity_BattleTentBattleRoom_EventScript_SetUpObjects
# 34 "data/maps/SlateportCity_BattleTentBattleRoom/scripts.pory"
	.2byte 0
# 35 "data/maps/SlateportCity_BattleTentBattleRoom/scripts.pory"

# 36 "data/maps/SlateportCity_BattleTentBattleRoom/scripts.pory"
SlateportCity_BattleTentBattleRoom_EventScript_SetUpObjects::
# 37 "data/maps/SlateportCity_BattleTentBattleRoom/scripts.pory"
	setvar VAR_TEMP_1, 1
# 38 "data/maps/SlateportCity_BattleTentBattleRoom/scripts.pory"
	hideobjectat OBJ_EVENT_ID_PLAYER, MAP_FALLARBOR_TOWN_BATTLE_TENT_BATTLE_ROOM
# 39 "data/maps/SlateportCity_BattleTentBattleRoom/scripts.pory"
	hideobjectat LOCALID_OPPONENT, MAP_SLATEPORT_CITY_BATTLE_TENT_BATTLE_ROOM
# 40 "data/maps/SlateportCity_BattleTentBattleRoom/scripts.pory"
	end
# 41 "data/maps/SlateportCity_BattleTentBattleRoom/scripts.pory"

# 42 "data/maps/SlateportCity_BattleTentBattleRoom/scripts.pory"
SlateportCity_BattleTentBattleRoom_OnFrame:
# 43 "data/maps/SlateportCity_BattleTentBattleRoom/scripts.pory"
	map_script_2 VAR_TEMP_0, 0, SlateportCity_BattleTentBattleRoom_EventScript_EnterRoom
# 44 "data/maps/SlateportCity_BattleTentBattleRoom/scripts.pory"
	.2byte 0
# 45 "data/maps/SlateportCity_BattleTentBattleRoom/scripts.pory"

# 46 "data/maps/SlateportCity_BattleTentBattleRoom/scripts.pory"
SlateportCity_BattleTentBattleRoom_EventScript_EnterRoom::
# 47 "data/maps/SlateportCity_BattleTentBattleRoom/scripts.pory"
	applymovement LOCALID_PLAYER, SlateportCity_BattleTentBattleRoom_Movement_PlayerEnter
# 48 "data/maps/SlateportCity_BattleTentBattleRoom/scripts.pory"
	waitmovement 0
# 49 "data/maps/SlateportCity_BattleTentBattleRoom/scripts.pory"
	factory_setopponentgfx
# 50 "data/maps/SlateportCity_BattleTentBattleRoom/scripts.pory"
	setobjectxyperm LOCALID_OPPONENT, 5, 1
# 51 "data/maps/SlateportCity_BattleTentBattleRoom/scripts.pory"
	removeobject LOCALID_OPPONENT
# 52 "data/maps/SlateportCity_BattleTentBattleRoom/scripts.pory"
	addobject LOCALID_OPPONENT
# 53 "data/maps/SlateportCity_BattleTentBattleRoom/scripts.pory"
	applymovement LOCALID_OPPONENT, SlateportCity_BattleTentBattleRoom_Movement_OpponentEnter
# 54 "data/maps/SlateportCity_BattleTentBattleRoom/scripts.pory"
	waitmovement 0
# 55 "data/maps/SlateportCity_BattleTentBattleRoom/scripts.pory"
	battletent_getopponentintro
# 56 "data/maps/SlateportCity_BattleTentBattleRoom/scripts.pory"
	lockall
# 57 "data/maps/SlateportCity_BattleTentBattleRoom/scripts.pory"
	msgbox gStringVar4, MSGBOX_DEFAULT
# 58 "data/maps/SlateportCity_BattleTentBattleRoom/scripts.pory"
	waitmessage
# 59 "data/maps/SlateportCity_BattleTentBattleRoom/scripts.pory"
	closemessage
# 60 "data/maps/SlateportCity_BattleTentBattleRoom/scripts.pory"
	special HealPlayerParty
# 61 "data/maps/SlateportCity_BattleTentBattleRoom/scripts.pory"
	setvar VAR_0x8004, SPECIAL_BATTLE_FACTORY
# 62 "data/maps/SlateportCity_BattleTentBattleRoom/scripts.pory"
	setvar VAR_0x8005, 0
# 63 "data/maps/SlateportCity_BattleTentBattleRoom/scripts.pory"
	special DoSpecialTrainerBattle
# 64 "data/maps/SlateportCity_BattleTentBattleRoom/scripts.pory"
	waitstate
# 65 "data/maps/SlateportCity_BattleTentBattleRoom/scripts.pory"
	switch VAR_RESULT
# 66 "data/maps/SlateportCity_BattleTentBattleRoom/scripts.pory"
	case 1, SlateportCity_BattleTentBattleRoom_EventScript_DefeatedOpponent
# 67 "data/maps/SlateportCity_BattleTentBattleRoom/scripts.pory"
SlateportCity_BattleTent_EventScript_WarpToLobbyLost::
# 68 "data/maps/SlateportCity_BattleTentBattleRoom/scripts.pory"
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, CHALLENGE_STATUS_LOST
# 69 "data/maps/SlateportCity_BattleTentBattleRoom/scripts.pory"
	special LoadPlayerParty
# 70 "data/maps/SlateportCity_BattleTentBattleRoom/scripts.pory"
	warp MAP_SLATEPORT_CITY_BATTLE_TENT_LOBBY, 6, 6
# 71 "data/maps/SlateportCity_BattleTentBattleRoom/scripts.pory"
	waitstate
# 72 "data/maps/SlateportCity_BattleTentBattleRoom/scripts.pory"
@ forced stop
# 73 "data/maps/SlateportCity_BattleTentBattleRoom/scripts.pory"

# 74 "data/maps/SlateportCity_BattleTentBattleRoom/scripts.pory"
SlateportCity_BattleTentBattleRoom_EventScript_DefeatedOpponent::
# 75 "data/maps/SlateportCity_BattleTentBattleRoom/scripts.pory"
	frontier_get FRONTIER_DATA_BATTLE_NUM
# 76 "data/maps/SlateportCity_BattleTentBattleRoom/scripts.pory"
	addvar VAR_RESULT, 1
# 77 "data/maps/SlateportCity_BattleTentBattleRoom/scripts.pory"
	frontier_set FRONTIER_DATA_BATTLE_NUM, VAR_RESULT
# 78 "data/maps/SlateportCity_BattleTentBattleRoom/scripts.pory"
	switch VAR_RESULT
# 79 "data/maps/SlateportCity_BattleTentBattleRoom/scripts.pory"
	case 3, SlateportCity_BattleTentBattleRoom_EventScript_WarpToLobbyWon
# 80 "data/maps/SlateportCity_BattleTentBattleRoom/scripts.pory"
	setvar VAR_0x8006, 1
# 81 "data/maps/SlateportCity_BattleTentBattleRoom/scripts.pory"
	warp MAP_SLATEPORT_CITY_BATTLE_TENT_CORRIDOR, 2, 3
# 82 "data/maps/SlateportCity_BattleTentBattleRoom/scripts.pory"
	waitstate
# 83 "data/maps/SlateportCity_BattleTentBattleRoom/scripts.pory"
@ forced stop
# 84 "data/maps/SlateportCity_BattleTentBattleRoom/scripts.pory"

# 85 "data/maps/SlateportCity_BattleTentBattleRoom/scripts.pory"
SlateportCity_BattleTentBattleRoom_EventScript_WarpToLobbyWon::
# 86 "data/maps/SlateportCity_BattleTentBattleRoom/scripts.pory"
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, CHALLENGE_STATUS_WON
# 87 "data/maps/SlateportCity_BattleTentBattleRoom/scripts.pory"
	special LoadPlayerParty
# 88 "data/maps/SlateportCity_BattleTentBattleRoom/scripts.pory"
	warp MAP_SLATEPORT_CITY_BATTLE_TENT_LOBBY, 6, 6
# 89 "data/maps/SlateportCity_BattleTentBattleRoom/scripts.pory"
	waitstate
# 90 "data/maps/SlateportCity_BattleTentBattleRoom/scripts.pory"
@ forced stop
# 91 "data/maps/SlateportCity_BattleTentBattleRoom/scripts.pory"

# 92 "data/maps/SlateportCity_BattleTentBattleRoom/scripts.pory"
SlateportCity_BattleTentBattleRoom_Movement_PlayerEnter:
# 93 "data/maps/SlateportCity_BattleTentBattleRoom/scripts.pory"
	walk_up
# 94 "data/maps/SlateportCity_BattleTentBattleRoom/scripts.pory"
	walk_up
# 95 "data/maps/SlateportCity_BattleTentBattleRoom/scripts.pory"
	walk_up
# 96 "data/maps/SlateportCity_BattleTentBattleRoom/scripts.pory"
	walk_in_place_faster_right
# 97 "data/maps/SlateportCity_BattleTentBattleRoom/scripts.pory"
	step_end
# 98 "data/maps/SlateportCity_BattleTentBattleRoom/scripts.pory"

# 99 "data/maps/SlateportCity_BattleTentBattleRoom/scripts.pory"
SlateportCity_BattleTentBattleRoom_Movement_OpponentEnter:
# 100 "data/maps/SlateportCity_BattleTentBattleRoom/scripts.pory"
	walk_down
# 101 "data/maps/SlateportCity_BattleTentBattleRoom/scripts.pory"
	walk_down
# 102 "data/maps/SlateportCity_BattleTentBattleRoom/scripts.pory"
	walk_down
# 103 "data/maps/SlateportCity_BattleTentBattleRoom/scripts.pory"
	walk_down
# 104 "data/maps/SlateportCity_BattleTentBattleRoom/scripts.pory"
	walk_in_place_faster_left
# 105 "data/maps/SlateportCity_BattleTentBattleRoom/scripts.pory"
	step_end
