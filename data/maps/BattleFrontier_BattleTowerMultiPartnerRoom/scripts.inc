# 1 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 2 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_MapScripts::
# 3 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_RESUME, BattleFrontier_BattleTowerMultiPartnerRoom_OnResume
# 4 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, BattleFrontier_BattleTowerMultiPartnerRoom_OnTransition
# 5 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, BattleFrontier_BattleTowerMultiPartnerRoom_OnWarp
# 6 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleFrontier_BattleTowerMultiPartnerRoom_OnFrame
# 7 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.byte 0
# 8 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 9 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_OnResume:
# 10 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	pyramid_resetparty
# 11 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	end
# 12 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 13 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_OnTransition:
# 14 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	goto_if_set FLAG_CHOSEN_MULTI_BATTLE_NPC_PARTNER, BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_ChosePartner
# 15 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	clearflag FLAG_HIDE_BATTLE_TOWER_MULTI_BATTLE_PARTNER_1
# 16 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	clearflag FLAG_HIDE_BATTLE_TOWER_MULTI_BATTLE_PARTNER_2
# 17 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	clearflag FLAG_HIDE_BATTLE_TOWER_MULTI_BATTLE_PARTNER_3
# 18 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	clearflag FLAG_HIDE_BATTLE_TOWER_MULTI_BATTLE_PARTNER_4
# 19 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	clearflag FLAG_HIDE_BATTLE_TOWER_MULTI_BATTLE_PARTNER_5
# 20 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	clearflag FLAG_HIDE_BATTLE_TOWER_MULTI_BATTLE_PARTNER_6
# 21 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	setflag FLAG_HIDE_BATTLE_TOWER_MULTI_BATTLE_PARTNER_ALT_1
# 22 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	setflag FLAG_HIDE_BATTLE_TOWER_MULTI_BATTLE_PARTNER_ALT_2
# 23 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	tower_loadpartners
# 24 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	end
# 25 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 26 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_ChosePartner::
# 27 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_BOY_1
# 28 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	setvar VAR_OBJ_GFX_ID_1, OBJ_EVENT_GFX_BOY_1
# 29 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	setvar VAR_OBJ_GFX_ID_2, OBJ_EVENT_GFX_BOY_1
# 30 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	setvar VAR_OBJ_GFX_ID_3, OBJ_EVENT_GFX_BOY_1
# 31 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	setvar VAR_OBJ_GFX_ID_4, OBJ_EVENT_GFX_BOY_1
# 32 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	setvar VAR_OBJ_GFX_ID_5, OBJ_EVENT_GFX_BOY_1
# 33 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	setvar VAR_OBJ_GFX_ID_6, OBJ_EVENT_GFX_BOY_1
# 34 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	setvar VAR_OBJ_GFX_ID_7, OBJ_EVENT_GFX_BOY_1
# 35 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	setvar VAR_TEMP_1, 1
# 36 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	setvar VAR_TEMP_3, 1
# 37 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	setobjectxyperm LOCALID_TOWER_PARTNER_ROOM_ATTENDANT, 10, 2
# 38 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	end
# 39 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 40 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_OnWarp:
# 41 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	map_script_2 VAR_TEMP_3, 1, BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_TurnPlayerNorth
# 42 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.2byte 0
# 43 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 44 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_TurnPlayerNorth::
# 45 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	turnobject LOCALID_PLAYER, DIR_NORTH
# 46 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	end
# 47 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 48 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_OnFrame:
# 49 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	map_script_2 VAR_TEMP_1, 0, BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_EnterRoom
# 50 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	map_script_2 VAR_TEMP_3, 1, BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_ExitRoom
# 51 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.2byte 0
# 52 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 53 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_ExitRoom::
# 54 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	lockall
# 55 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	setvar VAR_TEMP_3, 0
# 56 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	goto BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_EnterElevator
# 57 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	end
# 58 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 59 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_EnterRoom::
# 60 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	lockall
# 61 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	applymovement LOCALID_PLAYER, BattleFrontier_BattleTowerMultiPartnerRoom_Movement_PlayerEnterRoom
# 62 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	waitmovement 0
# 63 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	applymovement LOCALID_TOWER_PARTNER_ROOM_ATTENDANT, BattleFrontier_BattleTowerMultiPartnerRoom_Movement_AttendantBlockExit
# 64 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	waitmovement 0
# 65 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	copyobjectxytoperm LOCALID_TOWER_PARTNER_ROOM_ATTENDANT
# 66 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
# 67 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	waitmovement 0
# 68 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	msgbox BattleFrontier_BattleTowerMultiPartnerRoom_Text_PleaseFindPartner, MSGBOX_DEFAULT
# 69 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	special HealPlayerParty
# 70 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	setvar VAR_TEMP_1, 1
# 71 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	releaseall
# 72 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	end
# 73 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 74 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Movement_PlayerEnterRoom:
# 75 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	walk_down
# 76 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	step_end
# 77 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 78 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Movement_AttendantBlockExit:
# 79 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	walk_left
# 80 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	walk_in_place_faster_down
# 81 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	step_end
# 82 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 83 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_Attendant::
# 84 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	lock
# 85 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	faceplayer
# 86 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	message BattleFrontier_BattleTowerMultiPartnerRoom_Text_QuitLookingForPartner
# 87 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	waitmessage
# 88 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	multichoicedefault 20, 8, MULTI_YESNO, 1, FALSE
# 89 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	goto_if_eq VAR_RESULT, 0, BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_QuitChallenge
# 90 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	msgbox BattleFrontier_BattleTowerMultiPartnerRoom_Text_PleaseFindPartner2, MSGBOX_DEFAULT
# 91 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	release
# 92 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	end
# 93 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 94 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_QuitChallenge::
# 95 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	frontier_set FRONTIER_DATA_RECORD_DISABLED, TRUE
# 96 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	goto BattleFrontier_BattleTower_EventScript_WarpToLobbyLost
# 97 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	end
# 98 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 99 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_EnterElevator::
# 100 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	msgbox BattleFrontier_BattleTowerMultiPartnerRoom_Text_ThankYouForChoosingPartner, MSGBOX_DEFAULT
# 101 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	closemessage
# 102 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	applymovement LOCALID_TOWER_PARTNER_ROOM_ATTENDANT, Common_Movement_WalkInPlaceFasterUp
# 103 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	waitmovement 0
# 104 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	opendoor 10, 1
# 105 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	waitdooranim
# 106 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	call BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_MoveToElevator
# 107 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	closedoor 10, 1
# 108 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	waitdooranim
# 109 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	warp MAP_BATTLE_FRONTIER_BATTLE_TOWER_ELEVATOR, 1, 6
# 110 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	waitstate
# 111 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	releaseall
# 112 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	end
# 113 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 114 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_MoveToElevator::
# 115 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	applymovement LOCALID_TOWER_PARTNER_ROOM_ATTENDANT, BattleFrontier_BattleTowerMultiPartnerRoom_Movement_AttendantEnterElevator
# 116 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	applymovement LOCALID_PLAYER, BattleFrontier_BattleTowerMultiPartnerRoom_Movement_PlayerEnterElevator
# 117 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	waitmovement 0
# 118 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	return
# 119 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 120 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
@ Unused
# 121 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_MoveToElevatorEast:
# 122 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	applymovement LOCALID_TOWER_PARTNER_ROOM_ATTENDANT, BattleFrontier_BattleTowerMultiPartnerRoom_Movement_AttendantEnterElevator
# 123 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	applymovement LOCALID_PLAYER, BattleFrontier_BattleTowerMultiPartnerRoom_Movement_PlayerEnterElevatorEast
# 124 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	waitmovement 0
# 125 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	return
# 126 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 127 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
@ Unused
# 128 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_MoveToElevatorWest:
# 129 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	applymovement LOCALID_TOWER_PARTNER_ROOM_ATTENDANT, BattleFrontier_BattleTowerMultiPartnerRoom_Movement_AttendantEnterElevator
# 130 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	applymovement LOCALID_PLAYER, BattleFrontier_BattleTowerMultiPartnerRoom_Movement_PlayerEneterElevatorWest
# 131 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	waitmovement 0
# 132 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	return
# 133 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 134 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Movement_PlayerEnterElevator:
# 135 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	walk_up
# 136 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	walk_up
# 137 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	set_invisible
# 138 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	step_end
# 139 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 140 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
@ Functionally unused
# 141 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Movement_PlayerEnterElevatorEast:
# 142 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	walk_right
# 143 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	walk_up
# 144 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	set_invisible
# 145 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	step_end
# 146 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 147 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
@ Functionally unused
# 148 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Movement_PlayerEneterElevatorWest:
# 149 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	walk_left
# 150 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	walk_up
# 151 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	set_invisible
# 152 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	step_end
# 153 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 154 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Movement_AttendantEnterElevator:
# 155 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	walk_up
# 156 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	set_invisible
# 157 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	step_end
# 158 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 159 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_Partner1::
# 160 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	lock
# 161 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	faceplayer
# 162 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	setvar VAR_TEMP_2, 0
# 163 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	goto BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_TalkToPotentialPartner
# 164 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	end
# 165 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 166 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_TalkToPotentialPartner::
# 167 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	goto_if_set FLAG_CHOSEN_MULTI_BATTLE_NPC_PARTNER, BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_RejectPartner
# 168 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	tower_dopartnermsg PARTNER_MSGID_INTRO
# 169 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	waitmessage
# 170 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	waitbuttonpress
# 171 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	tower_dopartnermsg PARTNER_MSGID_MON1
# 172 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	waitmessage
# 173 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	waitbuttonpress
# 174 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	tower_dopartnermsg PARTNER_MSGID_MON2_ASK
# 175 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	waitmessage
# 176 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	multichoicedefault 20, 8, MULTI_YESNO, 1, FALSE
# 177 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	switch VAR_RESULT
# 178 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	case 1, BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_RejectPartner
# 179 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	case MULTI_B_PRESSED, BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_RejectPartner
# 180 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	tower_dopartnermsg PARTNER_MSGID_ACCEPT
# 181 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	waitmessage
# 182 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	waitbuttonpress
# 183 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	closemessage
# 184 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	call_if_ne VAR_FACING, DIR_SOUTH, BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_PartnerExit
# 185 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	call_if_eq VAR_FACING, DIR_SOUTH, BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_PartnerExitSouth
# 186 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	removeobject VAR_LAST_TALKED
# 187 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	setflag FLAG_CHOSEN_MULTI_BATTLE_NPC_PARTNER
# 188 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	warpsilent MAP_BATTLE_FRONTIER_BATTLE_TOWER_MULTI_PARTNER_ROOM, 10, 3
# 189 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	waitstate
# 190 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	release
# 191 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	end
# 192 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 193 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_RejectPartner::
# 194 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	tower_dopartnermsg PARTNER_MSGID_REJECT
# 195 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	waitmessage
# 196 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	waitbuttonpress
# 197 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	release
# 198 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	end
# 199 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 200 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_PartnerExit::
# 201 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	applymovement VAR_LAST_TALKED, BattleFrontier_BattleTowerMultiPartnerRoom_Movement_PartnerExit
# 202 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	waitmovement 0
# 203 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	return
# 204 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 205 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_PartnerExitSouth::
# 206 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	applymovement VAR_LAST_TALKED, BattleFrontier_BattleTowerMultiPartnerRoom_Movement_PartnerExitSouth
# 207 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	waitmovement 0
# 208 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	return
# 209 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 210 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Movement_PartnerExit:
# 211 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	walk_fast_up
# 212 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	walk_fast_up
# 213 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	walk_fast_up
# 214 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	walk_fast_up
# 215 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	walk_fast_up
# 216 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	walk_fast_up
# 217 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	walk_fast_up
# 218 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	step_end
# 219 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 220 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Movement_PartnerExitSouth:
# 221 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	walk_fast_left
# 222 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	walk_fast_up
# 223 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	walk_fast_up
# 224 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	walk_fast_up
# 225 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	walk_fast_up
# 226 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	walk_fast_up
# 227 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	walk_fast_up
# 228 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	walk_fast_up
# 229 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	step_end
# 230 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 231 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_Partner2::
# 232 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	lock
# 233 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	faceplayer
# 234 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	setvar VAR_TEMP_2, 1
# 235 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	goto BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_TalkToPotentialPartner
# 236 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	end
# 237 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 238 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_Partner3::
# 239 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	lock
# 240 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	faceplayer
# 241 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	setvar VAR_TEMP_2, 2
# 242 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	goto BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_TalkToPotentialPartner
# 243 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	end
# 244 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 245 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_Partner4::
# 246 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	lock
# 247 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	faceplayer
# 248 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	setvar VAR_TEMP_2, 3
# 249 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	goto BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_TalkToPotentialPartner
# 250 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	end
# 251 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 252 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_Partner5::
# 253 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	lock
# 254 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	faceplayer
# 255 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	setvar VAR_TEMP_2, 4
# 256 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	goto BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_TalkToPotentialPartner
# 257 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	end
# 258 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 259 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_Partner6::
# 260 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	lock
# 261 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	faceplayer
# 262 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	setvar VAR_TEMP_2, 5
# 263 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	goto BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_TalkToPotentialPartner
# 264 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	end
# 265 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 266 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_Partner7::
# 267 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	lock
# 268 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	faceplayer
# 269 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	setvar VAR_TEMP_2, 6
# 270 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	goto BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_TalkToPotentialPartner
# 271 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	end
# 272 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 273 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_Partner8::
# 274 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	lock
# 275 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	faceplayer
# 276 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	setvar VAR_TEMP_2, 7
# 277 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	goto BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_TalkToPotentialPartner
# 278 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	end
# 279 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 280 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_PleaseFindPartner:
# 281 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Please find a partner from out of\n"
# 282 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "the TRAINERS gathered here.$"
# 283 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 284 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_QuitLookingForPartner:
# 285 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "{PLAYER}, you have not found a partner\n"
# 286 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "for your tag team.\p"
# 287 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Would you like to quit looking and\n"
# 288 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "return to the reception counter?$"
# 289 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 290 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_PleaseFindPartner2:
# 291 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Then, please find a partner from\n"
# 292 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "the TRAINERS gathered here.$"
# 293 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 294 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_ThankYouForChoosingPartner::
# 295 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Thank you for choosing a partner.\p"
# 296 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I will now show you to your\n"
# 297 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "MULTI BATTLE ROOM.$"
# 298 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 299 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_UnusedApprentice1Intro::
# 300 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I'm {STR_VAR_1}'s no. {STR_VAR_2} apprentice.\n"
# 301 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "You can call me {STR_VAR_3}!$"
# 302 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 303 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_UnusedApprentice1Mon1::
# 304 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "On {STR_VAR_1}'s advice, I brought\n"
# 305 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "one {STR_VAR_3} with {STR_VAR_2} and$"
# 306 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 307 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_UnusedApprentice1Mon2Ask::
# 308 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "one {STR_VAR_2} with {STR_VAR_1}.\p"
# 309 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Please, let me join you as a tag team.$"
# 310 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 311 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_UnusedApprentice1Accept::
# 312 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Thank you!\n"
# 313 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I'll go register right now.$"
# 314 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 315 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_UnusedApprentice1Reject::
# 316 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I really wanted to form a tag team\n"
# 317 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "with you, {PLAYER}…$"
# 318 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 319 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_UnusedApprentice2Intro::
# 320 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I am {STR_VAR_1}'s no. {STR_VAR_2} apprentice.\n"
# 321 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "My name is {STR_VAR_3}.$"
# 322 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 323 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_UnusedApprentice2Mon1::
# 324 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I got advice from {STR_VAR_1} and chose\n"
# 325 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "one {STR_VAR_3} with {STR_VAR_2} and$"
# 326 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 327 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_UnusedApprentice2Mon2Ask::
# 328 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "one {STR_VAR_2} with {STR_VAR_1}.\p"
# 329 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Please, let's form a tag team!$"
# 330 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 331 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_UnusedApprentice2Accept::
# 332 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Thank you very much!\n"
# 333 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I'll be done with registration quickly!$"
# 334 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 335 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_UnusedApprentice2Reject::
# 336 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "{PLAYER}, I was hoping that I could\n"
# 337 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "partner up with you…$"
# 338 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 339 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice1Intro::
# 340 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Um, my name's {STR_VAR_3}, and I'm\n"
# 341 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "{STR_VAR_1}'s no. {STR_VAR_2} apprentice.\p"
# 342 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Snivel…\p"
# 343 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I'm sorry!\n"
# 344 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "This tension is making me cry…$"
# 345 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 346 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice1Mon1::
# 347 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "{STR_VAR_3} advised me, so I have\n"
# 348 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "one {STR_VAR_2} with {STR_VAR_1} and$"
# 349 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 350 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice1Mon2Ask::
# 351 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "one {STR_VAR_2} with {STR_VAR_1}.\p"
# 352 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Snivel…\n"
# 353 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Please, please team up with me!$"
# 354 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 355 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice1Accept::
# 356 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Oh, really? You will?\n"
# 357 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Awesome! Wicked! Awoooh!\p"
# 358 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Oh… I'm sorry…\n"
# 359 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I'm so happy, I'm crying…\p"
# 360 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I'll go register right away.\n"
# 361 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Please don't go away!$"
# 362 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 363 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice1Reject::
# 364 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Oh, b-but…\n"
# 365 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Sob… Waaaaah!$"
# 366 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 367 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice2Intro::
# 368 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Hi, there! I'm {STR_VAR_3}!\n"
# 369 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I'm {STR_VAR_1}'s no. {STR_VAR_2} apprentice!$"
# 370 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 371 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice2Mon1::
# 372 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "{STR_VAR_3} recommended my crew.\n"
# 373 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "One {STR_VAR_2} with {STR_VAR_1} and$"
# 374 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 375 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice2Mon2Ask::
# 376 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "one {STR_VAR_2} with {STR_VAR_1},\n"
# 377 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "that's what I have! Cool, huh?\p"
# 378 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "So come on!\n"
# 379 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Let's form a tag team!$"
# 380 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 381 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice2Accept::
# 382 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Yay! Great!\n"
# 383 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Okay, I'll go register, okay?$"
# 384 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 385 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice2Reject::
# 386 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Aww, why?\n"
# 387 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I wanted to team up, {PLAYER}!$"
# 388 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 389 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice3Intro::
# 390 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I'm {STR_VAR_3}, the no. {STR_VAR_2} apprentice\n"
# 391 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "of the famous {STR_VAR_1}!$"
# 392 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 393 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice3Mon1::
# 394 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I looked to {STR_VAR_3} for advice.\n"
# 395 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "One {STR_VAR_1}-using {STR_VAR_2}$"
# 396 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 397 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice3Mon2Ask::
# 398 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "and one {STR_VAR_2} with {STR_VAR_1},\n"
# 399 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "that's my pair.\p"
# 400 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Please, will you join me in\n"
# 401 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "a tag team?$"
# 402 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 403 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice3Accept::
# 404 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Thank you!\n"
# 405 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I'll register right away!$"
# 406 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 407 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice3Reject::
# 408 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "{PLAYER}, I had been hoping to join\n"
# 409 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "you in a tag team…$"
# 410 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 411 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice4Intro::
# 412 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Um… I'm sincerely happy that you\n"
# 413 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "would take the time to talk to me.\p"
# 414 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I'm {STR_VAR_3}.\n"
# 415 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I'm {STR_VAR_1}'s no. {STR_VAR_2} apprentice…$"
# 416 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 417 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice4Mon1::
# 418 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "{STR_VAR_3} gave me advice.\n"
# 419 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I'm very grateful for it.\p"
# 420 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I have a team of one {STR_VAR_2}\n"
# 421 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "with {STR_VAR_1} and$"
# 422 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 423 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice4Mon2Ask::
# 424 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "one {STR_VAR_2} with {STR_VAR_1}.\n"
# 425 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I know I'm asking a lot…\p"
# 426 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I don't think you'll be willing to,\n"
# 427 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "but may I join you as a partner?$"
# 428 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 429 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice4Accept::
# 430 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Really? I can't believe it!\n"
# 431 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I can't believe you'll let me join you!\l"
# 432 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I… I won't let you down!\p"
# 433 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Um… If it's really okay, I'll go register\n"
# 434 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "right this instant!$"
# 435 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 436 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice4Reject::
# 437 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Oh…\n"
# 438 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I didn't think I was good enough…$"
# 439 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 440 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice5Intro::
# 441 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Hi, I'm {STR_VAR_3}.\n"
# 442 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I'm {STR_VAR_1}'s no. {STR_VAR_2} apprentice!$"
# 443 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 444 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice5Mon1::
# 445 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "{STR_VAR_3} told me that it would be\n"
# 446 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "good to make this team:\l"
# 447 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "one {STR_VAR_1}-using {STR_VAR_2}$"
# 448 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 449 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice5Mon2Ask::
# 450 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "and one {STR_VAR_2} that knows how\n"
# 451 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "to use {STR_VAR_1}.\p"
# 452 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Not bad, huh?\n"
# 453 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Want me to team up with you?$"
# 454 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 455 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice5Accept::
# 456 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Okay, glad to join you!\n"
# 457 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I hope you won't mess things up for me!\l"
# 458 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I'll do my registration now.$"
# 459 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 460 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice5Reject::
# 461 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Huh? Why did you turn me down?\n"
# 462 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "You're no judge of character!$"
# 463 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 464 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice6Intro::
# 465 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I'm {STR_VAR_3} and I'm a TRIATHLETE.\n"
# 466 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I'm busy every day what with jogging,\l"
# 467 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "training, and rapping.\p"
# 468 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I also happen to be {STR_VAR_1}'s\n"
# 469 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "no. {STR_VAR_2} apprentice.$"
# 470 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 471 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice6Mon1::
# 472 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "This is what {STR_VAR_3} recommended.\n"
# 473 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "One {STR_VAR_1}-using {STR_VAR_2}$"
# 474 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 475 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice6Mon2Ask::
# 476 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "and one {STR_VAR_1}-using\n"
# 477 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "{STR_VAR_2}.\p"
# 478 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I put a lot of effort into raising\n"
# 479 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "them, even though I'm busy.\p"
# 480 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Let's form a tag team\n"
# 481 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "and give it a go!$"
# 482 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 483 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice6Accept::
# 484 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Thanks, that's the spirit!\n"
# 485 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Hang tight while I go register, okay?$"
# 486 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 487 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice6Reject::
# 488 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I took time from my busy schedule\n"
# 489 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "to be here! Give me a break!$"
# 490 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 491 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice7Intro::
# 492 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Hi!\n"
# 493 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "How's it going?\p"
# 494 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I'm {STR_VAR_3}, {STR_VAR_1}'s\n"
# 495 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "no. {STR_VAR_2} apprentice. Glad to meet you!$"
# 496 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 497 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice7Mon1::
# 498 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Listen, listen! You have to hear about\n"
# 499 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "the POKéMON {STR_VAR_3} recommended.\l"
# 500 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "One {STR_VAR_2} with {STR_VAR_1} and$"
# 501 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 502 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice7Mon2Ask::
# 503 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "one {STR_VAR_2} with {STR_VAR_1}.\n"
# 504 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Of course I raised them superbly!\p"
# 505 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "So, want to team up?\n"
# 506 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I'm sure it'll be a great combo!$"
# 507 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 508 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice7Accept::
# 509 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Yay, I think this will be fun!\n"
# 510 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I'll go register!$"
# 511 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 512 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice7Reject::
# 513 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Oh, you're mean!\n"
# 514 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I come recommended, you know.$"
# 515 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 516 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice8Intro::
# 517 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Please let me introduce myself.\n"
# 518 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I am {STR_VAR_3}.\p"
# 519 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I serve as {STR_VAR_1}'s\n"
# 520 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "no. {STR_VAR_2} apprentice.$"
# 521 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 522 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice8Mon1::
# 523 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I sought the sage advice of\n"
# 524 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "{STR_VAR_3} and raised my team\l"
# 525 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "of one {STR_VAR_2} with {STR_VAR_1}$"
# 526 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 527 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice8Mon2Ask::
# 528 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "and one {STR_VAR_2} with {STR_VAR_1}.\p"
# 529 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Please agree to a tag team with me!$"
# 530 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 531 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice8Accept::
# 532 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Oh… I'm delighted!\n"
# 533 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I promise to give you my best!\p"
# 534 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Of course I will register us!\n"
# 535 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Please wait!$"
# 536 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 537 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice8Reject::
# 538 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I had been hoping to join you,\n"
# 539 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "{PLAYER}…$"
# 540 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 541 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice9Intro::
# 542 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Eek! You spoke to me!\n"
# 543 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I… I'm overjoyed!\p"
# 544 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I'm {STR_VAR_3}! I'm {STR_VAR_1}'s\n"
# 545 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "no. {STR_VAR_2} apprentice!$"
# 546 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 547 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice9Mon1::
# 548 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "On {STR_VAR_3}'s advice, I trained\n"
# 549 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "one {STR_VAR_1}-using {STR_VAR_2}$"
# 550 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 551 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice9Mon2Ask::
# 552 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "and one {STR_VAR_1}-using\n"
# 553 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "{STR_VAR_2}.\p"
# 554 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Please, can you grant me my wish?\n"
# 555 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I want to be your tag-team partner!$"
# 556 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 557 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice9Accept::
# 558 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Eek! I… I feel giddy!\n"
# 559 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Thank you so much!\l"
# 560 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I'll go register us right away!$"
# 561 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 562 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice9Reject::
# 563 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Waaah! Don't you feel any pity?\n"
# 564 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "But that makes you cooler…$"
# 565 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 566 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice10Intro::
# 567 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Yeehaw! I'm {STR_VAR_1}'s\n"
# 568 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "no. {STR_VAR_2} apprentice!\p"
# 569 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "{STR_VAR_3}'s my name, hello, hello!$"
# 570 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 571 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice10Mon1::
# 572 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "My mentor {STR_VAR_3} recommended\n"
# 573 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "one {STR_VAR_1}-master {STR_VAR_2}$"
# 574 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 575 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice10Mon2Ask::
# 576 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "and one {STR_VAR_1}-master\n"
# 577 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "{STR_VAR_2}.\p"
# 578 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Good stuff, huh?\n"
# 579 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "You'll partner with me, won't you?$"
# 580 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 581 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice10Accept::
# 582 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Okay, excellent!\n"
# 583 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I'll get the registration done quickly!$"
# 584 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 585 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice10Reject::
# 586 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Gwaaah!\n"
# 587 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "You're a calculating one, {PLAYER}!$"
# 588 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 589 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice11Intro::
# 590 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Hey! There's big trouble! This is\n"
# 591 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "the BATTLE TOWER's last day!\p"
# 592 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "… … … … … …\n"
# 593 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I'm only joking!\p"
# 594 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "People call me {STR_VAR_3} and I do, too!\n"
# 595 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I'm {STR_VAR_1}'s 1,000th apprentice!\l"
# 596 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Actually, I'm no. {STR_VAR_2}!$"
# 597 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 598 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice11Mon1::
# 599 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "{STR_VAR_3} gave me some advice.\n"
# 600 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "{STR_VAR_2} with {STR_VAR_1} and$"
# 601 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 602 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice11Mon2Ask::
# 603 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "{STR_VAR_2} with {STR_VAR_1}.\n"
# 604 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I've got ten of each kind!\l"
# 605 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Actually, just one of each!\p"
# 606 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "How about it?\n"
# 607 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Want to try tag battles with me?$"
# 608 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 609 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice11Accept::
# 610 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Yippee!\n"
# 611 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I'll give you a POKéMON as my thanks!\p"
# 612 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Just joking! But I will really go do\n"
# 613 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "the registration, okay?$"
# 614 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 615 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice11Reject::
# 616 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Oh, that's so cold! I'll have to wreck\n"
# 617 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "the BATTLE TOWER for that!\p"
# 618 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Of course I won't!$"
# 619 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 620 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice12Intro::
# 621 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Hey, there, I'm rockin' and a-rollin'!\n"
# 622 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "POKéMON, I be controllin'!\p"
# 623 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I'm {STR_VAR_3} the rappin' SAILOR.\n"
# 624 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Don't be mistakin' me for no wailer!\p"
# 625 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I'm {STR_VAR_1}'s no. {STR_VAR_2} apprentice.\n"
# 626 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Me, you shouldn't be quick to dismiss!$"
# 627 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 628 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice12Mon1::
# 629 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "With the advice of {STR_VAR_3} I did\n"
# 630 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "abide, put together my team of pride!\l"
# 631 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "One {STR_VAR_1}-using {STR_VAR_2}$"
# 632 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 633 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice12Mon2Ask::
# 634 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "and one {STR_VAR_1}-using\n"
# 635 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "{STR_VAR_2}!\p"
# 636 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Our meeting we should commemorate,\n"
# 637 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "with a tag-team victory to celebrate!$"
# 638 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 639 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice12Accept::
# 640 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Hey, hey, I like your style!\n"
# 641 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Our registration, I will go file!$"
# 642 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 643 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice12Reject::
# 644 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Oh, hey, {PLAYER}, now that's cold!\n"
# 645 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "If I may be so bold!$"
# 646 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 647 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice13Intro::
# 648 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Yippee-yahoo!\n"
# 649 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Oh, don't run! I was just having fun!\p"
# 650 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Howdy! I'm {STR_VAR_3}!\n"
# 651 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I'm {STR_VAR_1}'s no. {STR_VAR_2} apprentice!$"
# 652 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 653 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice13Mon1::
# 654 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "{STR_VAR_3} told me what to do.\n"
# 655 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "So one {STR_VAR_1}-using {STR_VAR_2}$"
# 656 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 657 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice13Mon2Ask::
# 658 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "and one {STR_VAR_1}-using\n"
# 659 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "{STR_VAR_2}, I did choose.\p"
# 660 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "So, what do you say?\n"
# 661 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Come on, make my day!\p"
# 662 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Please, I'm begging you!\n"
# 663 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Let me join you, don't leave me blue!$"
# 664 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 665 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice13Accept::
# 666 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Yeahah! Luck is with me!\n"
# 667 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "It sure makes me happy!\p"
# 668 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Before we go join the fray,\n"
# 669 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I'll go register right away!$"
# 670 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 671 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice13Reject::
# 672 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "You're turning me down?\n"
# 673 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "{PLAYER}, you're making me frown!$"
# 674 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 675 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice14Intro::
# 676 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Cough!\p"
# 677 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Oh, sorry, I have a cold.\n"
# 678 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "My POKéMON are fine, though.\p"
# 679 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "My name's {STR_VAR_3}, {STR_VAR_1}'s\n"
# 680 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "no. {STR_VAR_2} apprentice. Cough!$"
# 681 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 682 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice14Mon1::
# 683 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I took {STR_VAR_3}'s advice to heart\n"
# 684 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "and put together my team of\l"
# 685 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "one {STR_VAR_2} with {STR_VAR_1} and$"
# 686 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 687 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice14Mon2Ask::
# 688 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "one {STR_VAR_2} with {STR_VAR_1}.\p"
# 689 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I trained them every day,\n"
# 690 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "even in wind and rain.\p"
# 691 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "That's why I have this cold,\n"
# 692 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I think.\p"
# 693 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "That's what I'm about.\n"
# 694 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Want to be my tag partner?$"
# 695 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 696 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice14Accept::
# 697 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Thanks, I appreciate this!\n"
# 698 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Cough, cough!\l"
# 699 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Hang on while I go register.$"
# 700 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 701 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice14Reject::
# 702 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Oh, you won't?\n"
# 703 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "{PLAYER}, I think we'd make a good pair.$"
# 704 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 705 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice15Intro::
# 706 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Oh, hello!\n"
# 707 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "This is nerve-racking.\p"
# 708 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I'm {STR_VAR_3}.\n"
# 709 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I'm the no. {STR_VAR_2} apprentice of {STR_VAR_1}.$"
# 710 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 711 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice15Mon1::
# 712 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "{STR_VAR_3} said this team'll be good--\n"
# 713 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "one {STR_VAR_2} with {STR_VAR_1} and$"
# 714 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 715 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice15Mon2Ask::
# 716 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "one {STR_VAR_2} with {STR_VAR_1}.\p"
# 717 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I'm feeling self-conscious about this,\n"
# 718 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "but will you let me join you?$"
# 719 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 720 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice15Accept::
# 721 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Oh, gee, thank you!\n"
# 722 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I feel bashful, but I'll do my best!\p"
# 723 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I'll go get the registration done.$"
# 724 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 725 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice15Reject::
# 726 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Oh, please don't say no!\n"
# 727 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I feel self-conscious enough already…$"
# 728 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 729 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice16Intro::
# 730 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I am {STR_VAR_3}, and that's no lie.\n"
# 731 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I am {STR_VAR_1}'s no. {STR_VAR_2} apprentice.$"
# 732 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 733 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice16Mon1::
# 734 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "{STR_VAR_3} recommended my team.\p"
# 735 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Since the advice sounded sincere,\n"
# 736 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I decided to bring with me\l"
# 737 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "my {STR_VAR_1}-using {STR_VAR_2} and$"
# 738 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 739 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice16Mon2Ask::
# 740 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "my {STR_VAR_1}-using {STR_VAR_2}.\p"
# 741 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "If possible, I would like you to accept\n"
# 742 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "me as your tag-team partner.$"
# 743 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 744 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice16Accept::
# 745 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "You really will accept me?\n"
# 746 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "It would be too terrible otherwise.\p"
# 747 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "But since you've agreed, this is fine.\n"
# 748 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I shall go register the both of us.$"
# 749 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 750 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice16Reject::
# 751 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Hm? Now why would you refuse?\n"
# 752 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Is this your idea of a joke?$"
# 753 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 754 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_LassIntro::
# 755 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I'm {STR_VAR_1}, and I'm a LASS!$"
# 756 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 757 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_LassMon1::
# 758 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "What I have are one {STR_VAR_2}\n"
# 759 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "that uses {STR_VAR_1} and one$"
# 760 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 761 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_LassMon2Ask::
# 762 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "{STR_VAR_2} that uses {STR_VAR_1}.\n"
# 763 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Those are what I have with me.\p"
# 764 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Will you be my partner?$"
# 765 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 766 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_LassAccept::
# 767 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Thank you!\n"
# 768 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I'll go do the registration!$"
# 769 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 770 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_LassReject::
# 771 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "You don't want to be my partner?\n"
# 772 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "You'll regret it later!$"
# 773 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 774 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_YoungsterIntro::
# 775 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Hello!\p"
# 776 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I'm YOUNGSTER {STR_VAR_1}!$"
# 777 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 778 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_YoungsterMon1::
# 779 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Want to know what I have?\n"
# 780 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "One {STR_VAR_2} with {STR_VAR_1} and$"
# 781 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 782 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_YoungsterMon2Ask::
# 783 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "one {STR_VAR_2} with {STR_VAR_1}!\p"
# 784 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "You'll be my tag-team partner,\n"
# 785 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "won't you?$"
# 786 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 787 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_YoungsterAccept::
# 788 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Yay!\n"
# 789 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I'll go and register, okay?$"
# 790 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 791 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_YoungsterReject::
# 792 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Aww! If you'd form a tag team with\n"
# 793 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "my POKéMON, we'd be unstoppable!$"
# 794 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 795 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_HikerIntro::
# 796 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Yahoo!\n"
# 797 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I'm HIKER {STR_VAR_1}!$"
# 798 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 799 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_HikerMon1::
# 800 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Know what I have with me?\n"
# 801 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "My {STR_VAR_1}-using {STR_VAR_2} and$"
# 802 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 803 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_HikerMon2Ask::
# 804 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "my {STR_VAR_1}-using {STR_VAR_2}!\p"
# 805 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Sounds good, eh?\n"
# 806 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Want to form a tag team?$"
# 807 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 808 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_HikerAccept::
# 809 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Yahoo!\n"
# 810 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I'll go do the registering, then.$"
# 811 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 812 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_HikerReject::
# 813 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I would've liked to battle with you\n"
# 814 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "at my side.$"
# 815 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 816 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_BeautyIntro::
# 817 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Hello!\n"
# 818 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I'm {STR_VAR_1}, and I'm a BEAUTY!$"
# 819 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 820 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_BeautyMon1::
# 821 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Do you know what I've been raising?\n"
# 822 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "One {STR_VAR_2} with {STR_VAR_1} and$"
# 823 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 824 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_BeautyMon2Ask::
# 825 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "one {STR_VAR_2} with {STR_VAR_1}!\p"
# 826 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "What do you think?\n"
# 827 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Want to make a tag team together?$"
# 828 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 829 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_BeautyAccept::
# 830 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Wonderful!\n"
# 831 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I'll get the registration done now!$"
# 832 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 833 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_BeautyReject::
# 834 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "How disappointing!\p"
# 835 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "We two together--we would've been\n"
# 836 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "the best!$"
# 837 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 838 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_FishermanIntro::
# 839 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Yo!\p"
# 840 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "You know who I am?\n"
# 841 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I'm {STR_VAR_1} the FISHERMAN!$"
# 842 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 843 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_FishermanMon1::
# 844 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I've got with me a team of one\n"
# 845 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "{STR_VAR_1}-using {STR_VAR_2} and$"
# 846 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 847 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_FishermanMon2Ask::
# 848 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "one {STR_VAR_1}-using {STR_VAR_2}.\p"
# 849 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "So, how about it?\n"
# 850 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Will you battle at my side?$"
# 851 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 852 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_FishermanAccept::
# 853 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Good, good!\n"
# 854 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Leave it up to me!\p"
# 855 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I'll go and register us now.$"
# 856 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 857 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_FishermanReject::
# 858 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "We matched up perfectly, too…$"
# 859 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 860 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_LadyIntro::
# 861 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Glad to make your acquaintance.\n"
# 862 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I am {STR_VAR_1}, a LADY.$"
# 863 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 864 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_LadyMon1::
# 865 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I am accompanied by a team of\n"
# 866 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "one {STR_VAR_2} with {STR_VAR_1} and$"
# 867 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 868 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_LadyMon2Ask::
# 869 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "one {STR_VAR_2} with {STR_VAR_1}.\p"
# 870 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I hope I meet your approval.\n"
# 871 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "For I wish to have you as my partner.$"
# 872 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 873 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_LadyAccept::
# 874 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I thank you sincerely.\n"
# 875 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I shall handle the registration.$"
# 876 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 877 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_LadyReject::
# 878 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I'm sure that you will regret not\n"
# 879 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "having me as your partner.$"
# 880 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 881 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_CyclingTriathleteFIntro::
# 882 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I'm TRIATHLETE {STR_VAR_1}!$"
# 883 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 884 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_CyclingTriathleteFMon1::
# 885 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "What I have…\n"
# 886 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "One {STR_VAR_2} with {STR_VAR_1} and$"
# 887 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 888 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_CyclingTriathleteFMon2Ask::
# 889 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "one {STR_VAR_2} with {STR_VAR_1}!\n"
# 890 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "That's my pair!\p"
# 891 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Please?\n"
# 892 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Will you form a tag team with me?$"
# 893 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 894 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_CyclingTriathleteFAccept::
# 895 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Gee, thanks!\n"
# 896 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I'll go register at the counter.$"
# 897 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 898 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_CyclingTriathleteFReject::
# 899 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "We two together, we would've been\n"
# 900 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "tough for certain!$"
# 901 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 902 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_BugCatcherIntro::
# 903 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Hiya!\n"
# 904 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I'm BUG CATCHER {STR_VAR_1}!$"
# 905 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 906 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_BugCatcherMon1::
# 907 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Check out what I have!\n"
# 908 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "One {STR_VAR_2} with {STR_VAR_1} and$"
# 909 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 910 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_BugCatcherMon2Ask::
# 911 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "one {STR_VAR_2} with {STR_VAR_1}!\p"
# 912 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "So, listen!\n"
# 913 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Do you want to form a tag team?$"
# 914 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 915 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_BugCatcherAccept::
# 916 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Gotcha!\p"
# 917 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I'll go do the registration stuff\n"
# 918 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "at the counter.$"
# 919 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 920 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_BugCatcherReject::
# 921 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Aww, my POKéMON are awesome.\n"
# 922 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I hope you won't regret this!$"
# 923 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 924 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_SchoolKidMIntro::
# 925 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Good day!\n"
# 926 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I'm SCHOOL KID {STR_VAR_1}!$"
# 927 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 928 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_SchoolKidMMon1::
# 929 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "What I've been raising are one\n"
# 930 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "{STR_VAR_2} that uses {STR_VAR_1}$"
# 931 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 932 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_SchoolKidMMon2Ask::
# 933 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "and one {STR_VAR_2} that uses\n"
# 934 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "{STR_VAR_1}.\p"
# 935 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Not too bad, don't you think?\n"
# 936 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Would you care to form a tag team?$"
# 937 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 938 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_SchoolKidMAccept::
# 939 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Thank you very much!\n"
# 940 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I'll get done with the registration.$"
# 941 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 942 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_SchoolKidMReject::
# 943 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "That's too bad…\p"
# 944 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I was hoping that I could learn\n"
# 945 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "from you as your partner…$"
# 946 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 947 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_RichBoyIntro::
# 948 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Yo! Let me tell you who I am!\n"
# 949 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I'm RICH BOY {STR_VAR_1}!$"
# 950 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 951 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_RichBoyMon1::
# 952 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Guess what I got!\n"
# 953 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "One {STR_VAR_2} with {STR_VAR_1} and$"
# 954 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 955 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_RichBoyMon2Ask::
# 956 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "one {STR_VAR_2} with {STR_VAR_1}!\p"
# 957 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I'm willing to offer you the chance\n"
# 958 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "to be in a tag team with me.$"
# 959 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 960 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_RichBoyAccept::
# 961 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Smart move!\p"
# 962 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I'll finish up the registration\n"
# 963 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "process quick!$"
# 964 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 965 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_RichBoyReject::
# 966 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "You'd turn me of all people down?\n"
# 967 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "You'll regret that decision for sure!$"
# 968 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 969 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_BlackBeltIntro::
# 970 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Hiyah!\n"
# 971 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I am BLACK BELT {STR_VAR_1}.$"
# 972 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 973 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_BlackBeltMon1::
# 974 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "As my companions, I have\n"
# 975 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "one {STR_VAR_2} using {STR_VAR_1}$"
# 976 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 977 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_BlackBeltMon2Ask::
# 978 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "and one {STR_VAR_2} using\n"
# 979 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "{STR_VAR_1}.\p"
# 980 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Please, grant me my wish!\n"
# 981 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Allow me to be your tag partner!$"
# 982 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 983 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_BlackBeltAccept::
# 984 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Hiyah!\n"
# 985 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I will go register forthwith!$"
# 986 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 987 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_BlackBeltReject::
# 988 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I see… I hope for an opportunity\n"
# 989 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "the next time we meet…$"
# 990 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 991 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_TuberFIntro::
# 992 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Hi, there!\n"
# 993 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I'm {STR_VAR_1}, and I'm a TUBER!$"
# 994 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 995 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_TuberFMon1::
# 996 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I'll tell you what I have.\n"
# 997 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "One {STR_VAR_2} with {STR_VAR_1} and$"
# 998 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 999 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_TuberFMon2Ask::
# 1000 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "one {STR_VAR_2} with {STR_VAR_1}!\n"
# 1001 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "May I please be on your tag team?$"
# 1002 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1003 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_TuberFAccept::
# 1004 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Thank you!\n"
# 1005 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I'll go register us now!$"
# 1006 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1007 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_TuberFReject::
# 1008 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "If we'd become partners, we could\n"
# 1009 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "have been so strong!$"
# 1010 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1011 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_HexManiacIntro::
# 1012 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Greetings…\n"
# 1013 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I am HEX MANIAC {STR_VAR_1}…$"
# 1014 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1015 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_HexManiacMon1::
# 1016 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I bear with me one {STR_VAR_1}-using\n"
# 1017 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "{STR_VAR_2} together with one$"
# 1018 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1019 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_HexManiacMon2Ask::
# 1020 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "{STR_VAR_1}-using {STR_VAR_2}…\p"
# 1021 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I beseech you…\n"
# 1022 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Join me in a tag team…$"
# 1023 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1024 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_HexManiacAccept::
# 1025 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I thank you…\n"
# 1026 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I shall register us…$"
# 1027 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1028 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_HexManiacReject::
# 1029 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I so longed to join you…$"
# 1030 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1031 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnBreederMIntro::
# 1032 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "How do you do? I'm {STR_VAR_1},\n"
# 1033 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "and I'm a POKéMON BREEDER!$"
# 1034 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1035 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnBreederMMon1::
# 1036 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I'm raising a couple good ones!\n"
# 1037 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "One {STR_VAR_2} with {STR_VAR_1} and$"
# 1038 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1039 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnBreederMMon2Ask::
# 1040 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "one {STR_VAR_2} with {STR_VAR_1}!\p"
# 1041 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "How about it?\n"
# 1042 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Feel like making a tag team with me?$"
# 1043 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1044 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnBreederMAccept::
# 1045 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Thank you kindly!\p"
# 1046 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I'll go take care of the registration\n"
# 1047 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "stuff, so you wait right here!$"
# 1048 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1049 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnBreederMReject::
# 1050 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I was looking forward to being\n"
# 1051 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "your partner…$"
# 1052 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1053 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_RunningTriathleteFIntro::
# 1054 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Well, hello!\n"
# 1055 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I'm TRIATHLETE {STR_VAR_1}!$"
# 1056 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1057 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_RunningTriathleteFMon1::
# 1058 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Want to know what I run with?\n"
# 1059 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "One {STR_VAR_2} with {STR_VAR_1} and$"
# 1060 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1061 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_RunningTriathleteFMon2Ask::
# 1062 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "one {STR_VAR_2} with {STR_VAR_1}!\p"
# 1063 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Well?\n"
# 1064 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Want to be in a tag team with me?$"
# 1065 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1066 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_RunningTriathleteFAccept::
# 1067 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Good going!\p"
# 1068 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I'll be quick and get the registration\n"
# 1069 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "all done!$"
# 1070 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1071 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_RunningTriathleteFReject::
# 1072 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "You and me, we would've been tops.\n"
# 1073 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "It's too bad…$"
# 1074 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1075 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_RunningTriathleteMIntro::
# 1076 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Hey, there! My name's {STR_VAR_1}!\n"
# 1077 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I'm a TRIATHLETE!$"
# 1078 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1079 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_RunningTriathleteMMon1::
# 1080 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I go on runs with my durable team--\n"
# 1081 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "one {STR_VAR_2} with {STR_VAR_1} and$"
# 1082 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1083 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_RunningTriathleteMMon2Ask::
# 1084 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "one {STR_VAR_2} with {STR_VAR_1}!\p"
# 1085 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Not too shabby, huh?\n"
# 1086 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "We should be in a tag team together!$"
# 1087 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1088 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_RunningTriathleteMAccept::
# 1089 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "All right!\n"
# 1090 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I'll go register in a flash!$"
# 1091 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1092 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_RunningTriathleteMReject::
# 1093 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I really wanted to battle as your\n"
# 1094 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "tag-team partner…$"
# 1095 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1096 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_BattleGirlIntro::
# 1097 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I'm BATTLE GIRL {STR_VAR_1}!$"
# 1098 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1099 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_BattleGirlMon1::
# 1100 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I've been toughening up one\n"
# 1101 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "{STR_VAR_1}-using {STR_VAR_2} and$"
# 1102 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1103 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_BattleGirlMon2Ask::
# 1104 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "one {STR_VAR_1}-using {STR_VAR_2}!\p"
# 1105 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Do you like that combo?\n"
# 1106 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "How about you and me join up?$"
# 1107 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1108 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_BattleGirlAccept::
# 1109 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Why, thanks!\p"
# 1110 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I'll get the registration done\n"
# 1111 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "right now!$"
# 1112 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1113 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_BattleGirlReject::
# 1114 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "With you, I thought we could form\n"
# 1115 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "the ultimate tag team…$"
# 1116 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1117 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_CyclingTriathleteMIntro::
# 1118 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I'm TRIATHLETE {STR_VAR_1}!$"
# 1119 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1120 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_CyclingTriathleteMMon1::
# 1121 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I've been running with one {STR_VAR_2}\n"
# 1122 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "that knows how to use {STR_VAR_1}$"
# 1123 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1124 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_CyclingTriathleteMMon2Ask::
# 1125 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "and one {STR_VAR_2} with {STR_VAR_1}!\p"
# 1126 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "We could be in a tag team.\n"
# 1127 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Wouldn't that be great?$"
# 1128 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1129 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_CyclingTriathleteMAccept::
# 1130 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Thank you!\p"
# 1131 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I'll go register us, and that's\n"
# 1132 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "right now!$"
# 1133 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1134 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_CyclingTriathleteMReject::
# 1135 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Aww, that's too bad. We would've been\n"
# 1136 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "the toughest tag team around!$"
# 1137 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1138 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_TuberMIntro::
# 1139 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Me?\n"
# 1140 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I'm TUBER {STR_VAR_1}!$"
# 1141 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1142 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_TuberMMon1::
# 1143 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "What do I have with me?\n"
# 1144 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "One {STR_VAR_2} with {STR_VAR_1} and$"
# 1145 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1146 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_TuberMMon2Ask::
# 1147 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "one {STR_VAR_2} with {STR_VAR_1}!\p"
# 1148 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Hey?\n"
# 1149 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "You'll team up with me, right?$"
# 1150 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1151 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_TuberMAccept::
# 1152 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Okay!\p"
# 1153 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I'll go register!\n"
# 1154 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Let's be excellent together!$"
# 1155 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1156 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_TuberMReject::
# 1157 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "My POKéMON are tough for sure…\n"
# 1158 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "It's too bad you don't want to team up.$"
# 1159 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1160 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_GuitaristIntro::
# 1161 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Yay-hey!\n"
# 1162 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Call me GUITARIST {STR_VAR_1}!$"
# 1163 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1164 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_GuitaristMon1::
# 1165 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Check out my entourage!\n"
# 1166 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "One {STR_VAR_2} with {STR_VAR_1} and$"
# 1167 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1168 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_GuitaristMon2Ask::
# 1169 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "one {STR_VAR_2} with {STR_VAR_1}!\p"
# 1170 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Yay-hey! Pretty wild, huh?\n"
# 1171 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "We'll have to do a duet in a tag team!$"
# 1172 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1173 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_GuitaristAccept::
# 1174 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Yay-hey! Right on!\n"
# 1175 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I'll do that registration stuff now!$"
# 1176 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1177 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_GuitaristReject::
# 1178 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "My POKéMON rock hard!\n"
# 1179 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "You'll be sorry, I tell you!$"
# 1180 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1181 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_GentlemanIntro::
# 1182 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Pleased to meet you.\n"
# 1183 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I am {STR_VAR_1}, a GENTLEMAN.$"
# 1184 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1185 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_GentlemanMon1::
# 1186 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I am accompanied by my trusted\n"
# 1187 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "{STR_VAR_1}-using {STR_VAR_2} and$"
# 1188 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1189 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_GentlemanMon2Ask::
# 1190 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "one {STR_VAR_1}-using {STR_VAR_2}.\p"
# 1191 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "May I ask you to join me in a tag-team\n"
# 1192 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "partnership arrangement?$"
# 1193 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1194 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_GentlemanAccept::
# 1195 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Ah, I thank you for your trust.\n"
# 1196 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I shall be done with the registration.$"
# 1197 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1198 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_GentlemanReject::
# 1199 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "That is most unfortunate…\p"
# 1200 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I shall look forward to the next\n"
# 1201 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "opportunity…$"
# 1202 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1203 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokefanMIntro::
# 1204 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Hello, I'm {STR_VAR_1},\n"
# 1205 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "and I'm a POKéFAN.$"
# 1206 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1207 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokefanMMon1::
# 1208 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I have with me now one {STR_VAR_2}\n"
# 1209 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "that knows the move {STR_VAR_1} and$"
# 1210 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1211 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokefanMMon2Ask::
# 1212 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "one {STR_VAR_2} with {STR_VAR_1}.\p"
# 1213 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Do you like what you see?\n"
# 1214 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Why don't you be my tag partner?$"
# 1215 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1216 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokefanMAccept::
# 1217 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Thank you!\n"
# 1218 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I'll look after the registration!$"
# 1219 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1220 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokefanMReject::
# 1221 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "My POKéMON are top grade…\n"
# 1222 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "It's too bad you can't appreciate that.$"
# 1223 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1224 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_ExpertMIntro::
# 1225 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Hm!\n"
# 1226 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I am {STR_VAR_1}, and an EXPERT am I!$"
# 1227 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1228 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_ExpertMMon1::
# 1229 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "The POKéMON that I've toughened up are\n"
# 1230 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "one {STR_VAR_2} with {STR_VAR_1} and$"
# 1231 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1232 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_ExpertMMon2Ask::
# 1233 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "one {STR_VAR_2} with {STR_VAR_1}!\p"
# 1234 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "What say you to a tag team with me?$"
# 1235 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1236 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_ExpertMAccept::
# 1237 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Hm!\n"
# 1238 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I shall register us right away!\l"
# 1239 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Let us both do our best!$"
# 1240 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1241 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_ExpertMReject::
# 1242 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I will hope that your choice is\n"
# 1243 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "indeed correct…$"
# 1244 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1245 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_ExpertFIntro::
# 1246 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Hello, hello.\n"
# 1247 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I'm {STR_VAR_1}, and I'm an EXPERT.$"
# 1248 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1249 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_ExpertFMon1::
# 1250 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I've raised my POKéMON thoroughly.\n"
# 1251 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "One {STR_VAR_2} with {STR_VAR_1} and$"
# 1252 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1253 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_ExpertFMon2Ask::
# 1254 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "one {STR_VAR_2} with {STR_VAR_1}--\n"
# 1255 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "they're what I have.\p"
# 1256 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Wouldn't you like to team up with me?$"
# 1257 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1258 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_ExpertFAccept::
# 1259 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Good, good.\n"
# 1260 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I'll see to the registration right away.$"
# 1261 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1262 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_ExpertFReject::
# 1263 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Perhaps we can form a team the next\n"
# 1264 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "time we meet.$"
# 1265 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1266 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_DragonTamerIntro::
# 1267 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I'm DRAGON TAMER {STR_VAR_1}!$"
# 1268 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1269 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_DragonTamerMon1::
# 1270 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "The team I've been toughening up is\n"
# 1271 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "one {STR_VAR_2} with {STR_VAR_1} and$"
# 1272 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1273 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_DragonTamerMon2Ask::
# 1274 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "one {STR_VAR_2} with {STR_VAR_1}!\p"
# 1275 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "How about it?\n"
# 1276 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Want to be my partner?$"
# 1277 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1278 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_DragonTamerAccept::
# 1279 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Okay, I'll give it my best!\n"
# 1280 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I'll go register now, all right?$"
# 1281 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1282 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_DragonTamerReject::
# 1283 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "You're not going to find many tougher\n"
# 1284 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "partners than me!$"
# 1285 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1286 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_BirdKeeperIntro::
# 1287 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I'm BIRD KEEPER {STR_VAR_1}!$"
# 1288 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1289 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_BirdKeeperMon1::
# 1290 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "What POKéMON do I have?\n"
# 1291 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "One {STR_VAR_2} with {STR_VAR_1} and$"
# 1292 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1293 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_BirdKeeperMon2Ask::
# 1294 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "one {STR_VAR_2} with {STR_VAR_1}.\p"
# 1295 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Don't you think we'd make a decent\n"
# 1296 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "tag team?$"
# 1297 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1298 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_BirdKeeperAccept::
# 1299 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Great, thanks!\n"
# 1300 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I'll look after the registration!$"
# 1301 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1302 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_BirdKeeperReject::
# 1303 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "My POKéMON and I are strong.\n"
# 1304 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "What a letdown.$"
# 1305 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1306 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_NinjaBoyIntro::
# 1307 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I'm NINJA BOY {STR_VAR_1}!$"
# 1308 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1309 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_NinjaBoyMon1::
# 1310 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "My POKéMON team consists of one\n"
# 1311 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "{STR_VAR_2} with {STR_VAR_1} and$"
# 1312 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1313 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_NinjaBoyMon2Ask::
# 1314 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "one {STR_VAR_2} with {STR_VAR_1}!\p"
# 1315 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Let's be in a tag team together!$"
# 1316 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1317 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_NinjaBoyAccept::
# 1318 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Yay!\n"
# 1319 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Let me go register!$"
# 1320 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1321 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_NinjaBoyReject::
# 1322 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "You'll regret not having my tough\n"
# 1323 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "POKéMON on your side!$"
# 1324 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1325 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_ParasolLadyIntro::
# 1326 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Hello!\n"
# 1327 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I'm PARASOL LADY {STR_VAR_1}!$"
# 1328 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1329 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_ParasolLadyMon1::
# 1330 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Escorting me now are my {STR_VAR_2}\n"
# 1331 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "that uses {STR_VAR_1} and$"
# 1332 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1333 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_ParasolLadyMon2Ask::
# 1334 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "one {STR_VAR_2} that uses\n"
# 1335 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "{STR_VAR_1}.\p"
# 1336 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Aren't they nice?\n"
# 1337 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Care to join us in a tag team?$"
# 1338 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1339 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_ParasolLadyAccept::
# 1340 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Thanks a bunch!\p"
# 1341 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I'll go register at the counter.\n"
# 1342 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Let's not disappoint each other!$"
# 1343 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1344 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_ParasolLadyReject::
# 1345 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "My POKéMON are tremendously strong.\n"
# 1346 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "How disappointing…$"
# 1347 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1348 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_BugManiacIntro::
# 1349 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Hello.\n"
# 1350 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I'm {STR_VAR_1}, and I'm a BUG MANIAC!$"
# 1351 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1352 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_BugManiacMon1::
# 1353 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I have found my POKéMON, yes.\n"
# 1354 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "One {STR_VAR_2} with {STR_VAR_1} and$"
# 1355 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1356 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_BugManiacMon2Ask::
# 1357 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "one {STR_VAR_2} with {STR_VAR_1}--\n"
# 1358 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "they are what I found.\p"
# 1359 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Could I interest you in forming\n"
# 1360 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "a tag team?$"
# 1361 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1362 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_BugManiacAccept::
# 1363 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Okay!\n"
# 1364 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Understood!\p"
# 1365 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I won't be long with the registration!$"
# 1366 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1367 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_BugManiacReject::
# 1368 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "With the POKéMON I found, we wouldn't\n"
# 1369 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "have lost…$"
# 1370 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1371 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_SailorIntro::
# 1372 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Ahoy, there!\n"
# 1373 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I'm SAILOR {STR_VAR_1}!$"
# 1374 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1375 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_SailorMon1::
# 1376 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Let me show you my pride and joy!\n"
# 1377 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "One {STR_VAR_2} with {STR_VAR_1} and$"
# 1378 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1379 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_SailorMon2Ask::
# 1380 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "one {STR_VAR_2} with {STR_VAR_1}!\p"
# 1381 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Of course you're not going to turn\n"
# 1382 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "me down. We will team up, right?$"
# 1383 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1384 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_SailorAccept::
# 1385 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I didn't expect any less!\n"
# 1386 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I'll go register now.$"
# 1387 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1388 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_SailorReject::
# 1389 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "We would've stormed through\n"
# 1390 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "the opposition! Too bad!$"
# 1391 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1392 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_CollectorIntro::
# 1393 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Hi, I'm {STR_VAR_1}.\n"
# 1394 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I'm a COLLECTOR.$"
# 1395 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1396 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_CollectorMon1::
# 1397 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "The jewels in my collection are\n"
# 1398 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "my {STR_VAR_2} with {STR_VAR_1} and$"
# 1399 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1400 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_CollectorMon2Ask::
# 1401 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "one {STR_VAR_2} with {STR_VAR_1}!\p"
# 1402 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Swell, huh?\n"
# 1403 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "We should be in a team together.$"
# 1404 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1405 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_CollectorAccept::
# 1406 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Oh, yeah!\p"
# 1407 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Well, let's not waste any time.\n"
# 1408 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I'll go register the two of us.$"
# 1409 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1410 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_CollectorReject::
# 1411 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Well, that's upsetting.\n"
# 1412 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "You don't appreciate my POKéMON.$"
# 1413 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1414 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnRangerMIntro::
# 1415 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Howdy, I'm {STR_VAR_1}.\n"
# 1416 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I'm a POKéMON RANGER.$"
# 1417 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1418 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnRangerMMon1::
# 1419 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Keeping me company are one\n"
# 1420 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "{STR_VAR_1}-using {STR_VAR_2} and$"
# 1421 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1422 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnRangerMMon2Ask::
# 1423 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "one {STR_VAR_2} with {STR_VAR_1}!\p"
# 1424 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Don't you think we'd make an impressive\n"
# 1425 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "tag team?$"
# 1426 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1427 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnRangerMAccept::
# 1428 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "That's super!\n"
# 1429 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I'll deal with the registration now.$"
# 1430 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1431 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnRangerMReject::
# 1432 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Next time, choose my POKéMON,\n"
# 1433 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "will you?$"
# 1434 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1435 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnRangerFIntro::
# 1436 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "My name's {STR_VAR_1}.\n"
# 1437 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I'm a POKéMON RANGER!$"
# 1438 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1439 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnRangerFMon1::
# 1440 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Let me tell you about my team. I have\n"
# 1441 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "one {STR_VAR_2} with {STR_VAR_1} and$"
# 1442 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1443 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnRangerFMon2Ask::
# 1444 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "one {STR_VAR_2} with {STR_VAR_1}!\p"
# 1445 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "How would you like to form a tag team\n"
# 1446 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "with my little posse?$"
# 1447 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1448 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnRangerFAccept::
# 1449 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "We'll be at our best!\n"
# 1450 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I'll get the registration done quick!$"
# 1451 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1452 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnRangerFReject::
# 1453 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I hope you'll choose my POKéMON\n"
# 1454 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "next time.$"
# 1455 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1456 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_AromaLadyIntro::
# 1457 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Pleased to meet you. I'm {STR_VAR_1}.\n"
# 1458 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I consider myself an AROMA LADY.$"
# 1459 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1460 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_AromaLadyMon1::
# 1461 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I travel with one {STR_VAR_2}\n"
# 1462 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "that uses {STR_VAR_1} and$"
# 1463 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1464 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_AromaLadyMon2Ask::
# 1465 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "one {STR_VAR_2} that uses\n"
# 1466 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "{STR_VAR_1}.\p"
# 1467 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I hope they strike your fancy.\n"
# 1468 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Would you care to be my partner?$"
# 1469 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1470 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_AromaLadyAccept::
# 1471 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I'm honored by your acceptance.\n"
# 1472 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I will go register right this instant.$"
# 1473 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1474 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_AromaLadyReject::
# 1475 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "It would be wonderful if we could form\n"
# 1476 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "a tag team the next time we meet.$"
# 1477 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1478 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_RuinManiacIntro::
# 1479 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Want to know who I am?\n"
# 1480 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I'm {STR_VAR_1}, the RUIN MANIAC!$"
# 1481 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1482 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_RuinManiacMon1::
# 1483 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "The POKéMON that I have with me are\n"
# 1484 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "one {STR_VAR_2} with {STR_VAR_1} and$"
# 1485 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1486 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_RuinManiacMon2Ask::
# 1487 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "one {STR_VAR_2} with {STR_VAR_1}!\p"
# 1488 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Intriguing, eh?\n"
# 1489 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "How about you and I partner up?$"
# 1490 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1491 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_RuinManiacAccept::
# 1492 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "That's a sound decision!\n"
# 1493 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I'll go do the registration paperwork.$"
# 1494 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1495 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_RuinManiacReject::
# 1496 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Hmm…\n"
# 1497 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I think my POKéMON are tough…$"
# 1498 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1499 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_CoolTrainerMIntro::
# 1500 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I'm COOLTRAINER {STR_VAR_1}!$"
# 1501 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1502 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_CoolTrainerMMon1::
# 1503 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "The POKéMON I have right now are one\n"
# 1504 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "{STR_VAR_2} with {STR_VAR_1} and$"
# 1505 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1506 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_CoolTrainerMMon2Ask::
# 1507 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "one {STR_VAR_2} with {STR_VAR_1}.\n"
# 1508 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Cool, huh?\p"
# 1509 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Don't you think it'd be pretty cool\n"
# 1510 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "if we made a tag team?$"
# 1511 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1512 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_CoolTrainerMAccept::
# 1513 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Cool!\n"
# 1514 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I'll go do the registration in a flash!$"
# 1515 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1516 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_CoolTrainerMReject::
# 1517 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I thought that we'd make just\n"
# 1518 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "the greatest team ever.$"
# 1519 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1520 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_CoolTrainerFIntro::
# 1521 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I'm COOLTRAINER {STR_VAR_1}!$"
# 1522 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1523 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_CoolTrainerFMon1::
# 1524 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "The team I've been raising has one\n"
# 1525 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "{STR_VAR_2} with {STR_VAR_1} and$"
# 1526 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1527 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_CoolTrainerFMon2Ask::
# 1528 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "one {STR_VAR_2} with {STR_VAR_1}.\p"
# 1529 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Does that sound okay?\n"
# 1530 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "How about we become tag partners?$"
# 1531 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1532 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_CoolTrainerFAccept::
# 1533 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Sounds A-OK!\n"
# 1534 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I'd better do the registration.$"
# 1535 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1536 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_CoolTrainerFReject::
# 1537 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I was thinking how we would be\n"
# 1538 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "one tough team…$"
# 1539 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1540 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokemaniacIntro::
# 1541 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Heyo!\n"
# 1542 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I'm {STR_VAR_1}, the POKéMANIAC!$"
# 1543 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1544 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokemaniacMon1::
# 1545 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "What does a guy like me have?\n"
# 1546 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "One {STR_VAR_2} with {STR_VAR_1} and$"
# 1547 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1548 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokemaniacMon2Ask::
# 1549 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "one {STR_VAR_2} with {STR_VAR_1},\n"
# 1550 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "that's what!\p"
# 1551 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Let's do it!\n"
# 1552 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "We'll stomp around as a tag team!$"
# 1553 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1554 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokemaniacAccept::
# 1555 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Good call!\n"
# 1556 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I'll register the both of us!$"
# 1557 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1558 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokemaniacReject::
# 1559 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "My POKéMON are brutal!\n"
# 1560 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "It's not my fault if you regret this!$"
# 1561 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1562 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_KindlerIntro::
# 1563 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Yo, there!\n"
# 1564 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I'm KINDLER {STR_VAR_1}!$"
# 1565 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1566 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_KindlerMon1::
# 1567 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "You know what my training cooked up?\n"
# 1568 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "One {STR_VAR_2} with {STR_VAR_1} and$"
# 1569 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1570 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_KindlerMon2Ask::
# 1571 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "one {STR_VAR_2} with {STR_VAR_1}!\p"
# 1572 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Well, what do you say?\n"
# 1573 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Want to form a tag team?$"
# 1574 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1575 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_KindlerAccept::
# 1576 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "All right!\n"
# 1577 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I'll get on with the registration.$"
# 1578 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1579 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_KindlerReject::
# 1580 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Promise you'll partner up with me\n"
# 1581 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "the next time we run into each other.$"
# 1582 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1583 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_CamperIntro::
# 1584 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I'm {STR_VAR_1}, and I'm a CAMPER!$"
# 1585 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1586 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_CamperMon1::
# 1587 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I've been raising one {STR_VAR_1}-\n"
# 1588 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "using {STR_VAR_2} and one$"
# 1589 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1590 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_CamperMon2Ask::
# 1591 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "{STR_VAR_1}-using {STR_VAR_2}.\p"
# 1592 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Do you think it'd be fun to team up?\n"
# 1593 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I bet it would be!$"
# 1594 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1595 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_CamperAccept::
# 1596 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Yeah!\n"
# 1597 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Off I go to register!$"
# 1598 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1599 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_CamperReject::
# 1600 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Next time, okay?\n"
# 1601 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I want to be on your team.$"
# 1602 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1603 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_PicnickerIntro::
# 1604 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Hello!\n"
# 1605 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I'm {STR_VAR_1}, and I'm a PICNICKER!$"
# 1606 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1607 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_PicnickerMon1::
# 1608 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "The POKéMON I've been taking are\n"
# 1609 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "one {STR_VAR_2} with {STR_VAR_1} and$"
# 1610 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1611 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_PicnickerMon2Ask::
# 1612 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "one {STR_VAR_2} with {STR_VAR_1}.\p"
# 1613 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Are you interested in joining me\n"
# 1614 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "on a tag team?$"
# 1615 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1616 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_PicnickerAccept::
# 1617 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Why, thank you!\n"
# 1618 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I will do the registration now.$"
# 1619 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1620 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_PicnickerReject::
# 1621 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "It would be nice if I could join you\n"
# 1622 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "some other time.$"
# 1623 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1624 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_PsychicMIntro::
# 1625 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I'm PSYCHIC {STR_VAR_1}!$"
# 1626 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1627 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_PsychicMMon1::
# 1628 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "The twosome I've been raising are\n"
# 1629 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "one {STR_VAR_2} with {STR_VAR_1} and$"
# 1630 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1631 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_PsychicMMon2Ask::
# 1632 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "one {STR_VAR_2} with {STR_VAR_1}.\p"
# 1633 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Would you like to form a tag team\n"
# 1634 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "with me?$"
# 1635 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1636 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_PsychicMAccept::
# 1637 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Sure thing!\n"
# 1638 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I'll take care of the registration!$"
# 1639 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1640 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_PsychicMReject::
# 1641 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "If we meet again, that's when I'd like\n"
# 1642 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "to team up with you.$"
# 1643 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1644 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_PsychicFIntro::
# 1645 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I'm {STR_VAR_1}.\n"
# 1646 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I'm a PSYCHIC.$"
# 1647 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1648 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_PsychicFMon1::
# 1649 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "One {STR_VAR_2} with {STR_VAR_1} and$"
# 1650 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1651 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_PsychicFMon2Ask::
# 1652 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "one {STR_VAR_2} with {STR_VAR_1}--\n"
# 1653 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "they're my disciples.\p"
# 1654 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Doesn't the idea of forming a tag-team\n"
# 1655 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "partnership intrigue you?$"
# 1656 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1657 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_PsychicFAccept::
# 1658 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Thank you.\n"
# 1659 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I'll go deal with the registration.$"
# 1660 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1661 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_PsychicFReject::
# 1662 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I hope there will be another chance\n"
# 1663 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "to forge an alliance.$"
# 1664 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1665 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_SchoolKidFIntro::
# 1666 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I'm SCHOOL KID {STR_VAR_1}!$"
# 1667 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1668 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_SchoolKidFMon1::
# 1669 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "One {STR_VAR_1}-using {STR_VAR_2}$"
# 1670 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1671 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_SchoolKidFMon2Ask::
# 1672 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "and one {STR_VAR_1}-using\n"
# 1673 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "{STR_VAR_2} are my POKéMON pair.\p"
# 1674 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "May I please be your partner on\n"
# 1675 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "a tag team?$"
# 1676 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1677 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_SchoolKidFAccept::
# 1678 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Ooh, thank you!\n"
# 1679 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I'll register at the counter right away!$"
# 1680 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1681 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_SchoolKidFReject::
# 1682 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Please?\n"
# 1683 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "May I join you the next time?$"
# 1684 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1685 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnBreederFIntro::
# 1686 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Hiya! The name's {STR_VAR_1}!\n"
# 1687 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I'm a POKéMON BREEDER!$"
# 1688 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1689 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnBreederFMon1::
# 1690 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "The POKéMON I've raised are one\n"
# 1691 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "{STR_VAR_1}-using {STR_VAR_2} and$"
# 1692 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1693 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnBreederFMon2Ask::
# 1694 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "one {STR_VAR_1}-using {STR_VAR_2}.\p"
# 1695 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Sound interesting?\n"
# 1696 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "How about we form a tag team, then?$"
# 1697 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1698 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnBreederFAccept::
# 1699 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "All righty!\n"
# 1700 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "You leave the registration to me!$"
# 1701 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1702 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnBreederFReject::
# 1703 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "You have to team up with me next time,\n"
# 1704 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "all right?$"
# 1705 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1706 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokefanFIntro::
# 1707 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I'm {STR_VAR_1}, and I'm proud to say\n"
# 1708 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "that I am a POKéFAN.$"
# 1709 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1710 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokefanFMon1::
# 1711 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "The darling POKéMON I've raised are\n"
# 1712 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "one {STR_VAR_2} with {STR_VAR_1} and$"
# 1713 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1714 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokefanFMon2Ask::
# 1715 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "one {STR_VAR_2} with {STR_VAR_1}.\p"
# 1716 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Aren't they just the cutest?\n"
# 1717 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "We ought to make a team!$"
# 1718 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1719 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokefanFAccept::
# 1720 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Thank you, dear!\n"
# 1721 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I'll be on my way to register!$"
# 1722 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1723 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokefanFReject::
# 1724 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "My darling POKéMON are the best,\n"
# 1725 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I'll have you know. How annoying!$"
# 1726 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1727 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmerFIntro::
# 1728 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Hi, I'm SWIMMER {STR_VAR_1}.$"
# 1729 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1730 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmerFMon1::
# 1731 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "One {STR_VAR_1}-using {STR_VAR_2}$"
# 1732 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1733 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmerFMon2Ask::
# 1734 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "and one {STR_VAR_1}-using\n"
# 1735 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "{STR_VAR_2} are what I've trained.\p"
# 1736 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "You and me, let's make a tag team.$"
# 1737 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1738 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmerFAccept::
# 1739 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "That's cool!\n"
# 1740 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I'll register the two of us.$"
# 1741 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1742 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmerFReject::
# 1743 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "If we meet again, you owe me\n"
# 1744 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "a tag team!$"
# 1745 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1746 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmingTriathleteMIntro::
# 1747 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "What's happening?\n"
# 1748 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I'm {STR_VAR_1}, and I'm a TRIATHLETE.$"
# 1749 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1750 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmingTriathleteMMon1::
# 1751 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I got a couple decent POKéMON.\n"
# 1752 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "One {STR_VAR_2} with {STR_VAR_1} and$"
# 1753 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1754 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmingTriathleteMMon2Ask::
# 1755 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "one {STR_VAR_2} with {STR_VAR_1}!\p"
# 1756 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "It'd be neat if we made a tag team\n"
# 1757 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "together, so how about it?$"
# 1758 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1759 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmingTriathleteMAccept::
# 1760 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Right on!\n"
# 1761 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "You wait while I register, okay?$"
# 1762 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1763 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmingTriathleteMReject::
# 1764 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I expect you'll let me join you\n"
# 1765 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "next time, how's that?$"
# 1766 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1767 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmingTriathleteFIntro::
# 1768 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I'm the TRIATHLETE {STR_VAR_1}!$"
# 1769 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1770 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmingTriathleteFMon1::
# 1771 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "One {STR_VAR_2} with {STR_VAR_1} and$"
# 1772 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1773 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmingTriathleteFMon2Ask::
# 1774 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "another {STR_VAR_2} that knows how\n"
# 1775 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "to use {STR_VAR_1}. That's my pair.\p"
# 1776 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "What do you think?\n"
# 1777 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "We'd make a good team, I'd say.$"
# 1778 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1779 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmingTriathleteFAccept::
# 1780 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I like that answer!\n"
# 1781 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I'll get done with registration fast!$"
# 1782 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1783 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmingTriathleteFReject::
# 1784 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "You'll give me another chance to form\n"
# 1785 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "a partnership, won't you?$"
# 1786 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1787 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmerMIntro::
# 1788 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Hi, there! Hello!\n"
# 1789 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I'm {STR_VAR_1}, and I'm a SWIMMER!$"
# 1790 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1791 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmerMMon1::
# 1792 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Check out what I've been raising!\n"
# 1793 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "One {STR_VAR_2} with {STR_VAR_1} and$"
# 1794 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1795 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmerMMon2Ask::
# 1796 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "one {STR_VAR_2} with {STR_VAR_1}!\p"
# 1797 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Sweet, huh?\n"
# 1798 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "It'd be sweet to form a team, too!$"
# 1799 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1800 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmerMAccept::
# 1801 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Much obliged!\n"
# 1802 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I'll get this registration thing done!$"
# 1803 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1804 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmerMReject::
# 1805 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "If we meet again, you have to team up\n"
# 1806 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "with me. You'll do that, right?$"
