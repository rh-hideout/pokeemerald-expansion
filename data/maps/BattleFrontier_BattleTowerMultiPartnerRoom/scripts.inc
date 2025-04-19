# 1 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 2 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
.set LOCALID_ATTENDANT, 1
# 3 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 4 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_MapScripts::
# 5 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_RESUME, BattleFrontier_BattleTowerMultiPartnerRoom_OnResume
# 6 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, BattleFrontier_BattleTowerMultiPartnerRoom_OnTransition
# 7 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, BattleFrontier_BattleTowerMultiPartnerRoom_OnWarp
# 8 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleFrontier_BattleTowerMultiPartnerRoom_OnFrame
# 9 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.byte 0
# 10 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 11 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_OnResume:
# 12 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	pyramid_resetparty
# 13 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	end
# 14 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 15 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_OnTransition:
# 16 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	goto_if_set FLAG_CHOSEN_MULTI_BATTLE_NPC_PARTNER, BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_ChosePartner
# 17 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	clearflag FLAG_HIDE_BATTLE_TOWER_MULTI_BATTLE_PARTNER_1
# 18 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	clearflag FLAG_HIDE_BATTLE_TOWER_MULTI_BATTLE_PARTNER_2
# 19 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	clearflag FLAG_HIDE_BATTLE_TOWER_MULTI_BATTLE_PARTNER_3
# 20 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	clearflag FLAG_HIDE_BATTLE_TOWER_MULTI_BATTLE_PARTNER_4
# 21 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	clearflag FLAG_HIDE_BATTLE_TOWER_MULTI_BATTLE_PARTNER_5
# 22 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	clearflag FLAG_HIDE_BATTLE_TOWER_MULTI_BATTLE_PARTNER_6
# 23 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	setflag FLAG_HIDE_BATTLE_TOWER_MULTI_BATTLE_PARTNER_ALT_1
# 24 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	setflag FLAG_HIDE_BATTLE_TOWER_MULTI_BATTLE_PARTNER_ALT_2
# 25 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	tower_loadpartners
# 26 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	end
# 27 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 28 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_ChosePartner::
# 29 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_BOY_1
# 30 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	setvar VAR_OBJ_GFX_ID_1, OBJ_EVENT_GFX_BOY_1
# 31 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	setvar VAR_OBJ_GFX_ID_2, OBJ_EVENT_GFX_BOY_1
# 32 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	setvar VAR_OBJ_GFX_ID_3, OBJ_EVENT_GFX_BOY_1
# 33 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	setvar VAR_OBJ_GFX_ID_4, OBJ_EVENT_GFX_BOY_1
# 34 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	setvar VAR_OBJ_GFX_ID_5, OBJ_EVENT_GFX_BOY_1
# 35 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	setvar VAR_OBJ_GFX_ID_6, OBJ_EVENT_GFX_BOY_1
# 36 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	setvar VAR_OBJ_GFX_ID_7, OBJ_EVENT_GFX_BOY_1
# 37 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	setvar VAR_TEMP_1, 1
# 38 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	setvar VAR_TEMP_3, 1
# 39 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	setobjectxyperm LOCALID_ATTENDANT, 10, 2
# 40 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	end
# 41 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 42 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_OnWarp:
# 43 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	map_script_2 VAR_TEMP_3, 1, BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_TurnPlayerNorth
# 44 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.2byte 0
# 45 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 46 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_TurnPlayerNorth::
# 47 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
# 48 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	end
# 49 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 50 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_OnFrame:
# 51 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	map_script_2 VAR_TEMP_1, 0, BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_EnterRoom
# 52 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	map_script_2 VAR_TEMP_3, 1, BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_ExitRoom
# 53 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.2byte 0
# 54 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 55 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_ExitRoom::
# 56 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	lockall
# 57 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	setvar VAR_TEMP_3, 0
# 58 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	goto BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_EnterElevator
# 59 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	end
# 60 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 61 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_EnterRoom::
# 62 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	lockall
# 63 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, BattleFrontier_BattleTowerMultiPartnerRoom_Movement_PlayerEnterRoom
# 64 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	waitmovement 0
# 65 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	applymovement LOCALID_ATTENDANT, BattleFrontier_BattleTowerMultiPartnerRoom_Movement_AttendantBlockExit
# 66 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	waitmovement 0
# 67 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	copyobjectxytoperm LOCALID_ATTENDANT
# 68 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
# 69 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	waitmovement 0
# 70 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	msgbox BattleFrontier_BattleTowerMultiPartnerRoom_Text_PleaseFindPartner, MSGBOX_DEFAULT
# 71 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	special HealPlayerParty
# 72 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	setvar VAR_TEMP_1, 1
# 73 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	releaseall
# 74 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	end
# 75 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 76 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Movement_PlayerEnterRoom:
# 77 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	walk_down
# 78 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	step_end
# 79 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 80 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Movement_AttendantBlockExit:
# 81 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	walk_left
# 82 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	walk_in_place_faster_down
# 83 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	step_end
# 84 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 85 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_Attendant::
# 86 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	lock
# 87 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	faceplayer
# 88 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	message BattleFrontier_BattleTowerMultiPartnerRoom_Text_QuitLookingForPartner
# 89 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	waitmessage
# 90 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	multichoicedefault 20, 8, MULTI_YESNO, 1, FALSE
# 91 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	goto_if_eq VAR_RESULT, 0, BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_QuitChallenge
# 92 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	msgbox BattleFrontier_BattleTowerMultiPartnerRoom_Text_PleaseFindPartner2, MSGBOX_DEFAULT
# 93 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	release
# 94 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	end
# 95 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 96 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_QuitChallenge::
# 97 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	frontier_set FRONTIER_DATA_RECORD_DISABLED, TRUE
# 98 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	goto BattleFrontier_BattleTower_EventScript_WarpToLobbyLost
# 99 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	end
# 100 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 101 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_EnterElevator::
# 102 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	msgbox BattleFrontier_BattleTowerMultiPartnerRoom_Text_ThankYouForChoosingPartner, MSGBOX_DEFAULT
# 103 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	closemessage
# 104 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	applymovement LOCALID_ATTENDANT, Common_Movement_WalkInPlaceFasterUp
# 105 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	waitmovement 0
# 106 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	opendoor 10, 1
# 107 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	waitdooranim
# 108 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	call BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_MoveToElevator
# 109 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	closedoor 10, 1
# 110 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	waitdooranim
# 111 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	warp MAP_BATTLE_FRONTIER_BATTLE_TOWER_ELEVATOR, 1, 6
# 112 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	waitstate
# 113 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	releaseall
# 114 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	end
# 115 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 116 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_MoveToElevator::
# 117 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	applymovement LOCALID_ATTENDANT, BattleFrontier_BattleTowerMultiPartnerRoom_Movement_AttendantEnterElevator
# 118 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, BattleFrontier_BattleTowerMultiPartnerRoom_Movement_PlayerEnterElevator
# 119 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	waitmovement 0
# 120 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	return
# 121 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 122 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
@ Unused
# 123 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_MoveToElevatorEast:
# 124 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	applymovement LOCALID_ATTENDANT, BattleFrontier_BattleTowerMultiPartnerRoom_Movement_AttendantEnterElevator
# 125 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, BattleFrontier_BattleTowerMultiPartnerRoom_Movement_PlayerEnterElevatorEast
# 126 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	waitmovement 0
# 127 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	return
# 128 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 129 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
@ Unused
# 130 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_MoveToElevatorWest:
# 131 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	applymovement LOCALID_ATTENDANT, BattleFrontier_BattleTowerMultiPartnerRoom_Movement_AttendantEnterElevator
# 132 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, BattleFrontier_BattleTowerMultiPartnerRoom_Movement_PlayerEneterElevatorWest
# 133 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	waitmovement 0
# 134 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	return
# 135 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 136 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Movement_PlayerEnterElevator:
# 137 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	walk_up
# 138 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	walk_up
# 139 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	set_invisible
# 140 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	step_end
# 141 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 142 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
@ Functionally unused
# 143 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Movement_PlayerEnterElevatorEast:
# 144 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	walk_right
# 145 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	walk_up
# 146 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	set_invisible
# 147 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	step_end
# 148 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 149 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
@ Functionally unused
# 150 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Movement_PlayerEneterElevatorWest:
# 151 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	walk_left
# 152 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	walk_up
# 153 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	set_invisible
# 154 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	step_end
# 155 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 156 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Movement_AttendantEnterElevator:
# 157 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	walk_up
# 158 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	set_invisible
# 159 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	step_end
# 160 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 161 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_Partner1::
# 162 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	lock
# 163 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	faceplayer
# 164 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	setvar VAR_TEMP_2, 0
# 165 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	goto BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_TalkToPotentialPartner
# 166 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	end
# 167 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 168 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_TalkToPotentialPartner::
# 169 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	goto_if_set FLAG_CHOSEN_MULTI_BATTLE_NPC_PARTNER, BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_RejectPartner
# 170 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	tower_dopartnermsg PARTNER_MSGID_INTRO
# 171 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	waitmessage
# 172 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	waitbuttonpress
# 173 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	tower_dopartnermsg PARTNER_MSGID_MON1
# 174 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	waitmessage
# 175 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	waitbuttonpress
# 176 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	tower_dopartnermsg PARTNER_MSGID_MON2_ASK
# 177 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	waitmessage
# 178 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	multichoicedefault 20, 8, MULTI_YESNO, 1, FALSE
# 179 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	switch VAR_RESULT
# 180 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	case 1, BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_RejectPartner
# 181 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	case MULTI_B_PRESSED, BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_RejectPartner
# 182 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	tower_dopartnermsg PARTNER_MSGID_ACCEPT
# 183 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	waitmessage
# 184 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	waitbuttonpress
# 185 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	closemessage
# 186 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	call_if_ne VAR_FACING, DIR_SOUTH, BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_PartnerExit
# 187 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	call_if_eq VAR_FACING, DIR_SOUTH, BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_PartnerExitSouth
# 188 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	removeobject VAR_LAST_TALKED
# 189 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	setflag FLAG_CHOSEN_MULTI_BATTLE_NPC_PARTNER
# 190 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	warpsilent MAP_BATTLE_FRONTIER_BATTLE_TOWER_MULTI_PARTNER_ROOM, 10, 3
# 191 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	waitstate
# 192 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	release
# 193 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	end
# 194 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 195 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_RejectPartner::
# 196 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	tower_dopartnermsg PARTNER_MSGID_REJECT
# 197 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	waitmessage
# 198 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	waitbuttonpress
# 199 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	release
# 200 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	end
# 201 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 202 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_PartnerExit::
# 203 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	applymovement VAR_LAST_TALKED, BattleFrontier_BattleTowerMultiPartnerRoom_Movement_PartnerExit
# 204 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	waitmovement 0
# 205 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	return
# 206 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 207 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_PartnerExitSouth::
# 208 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	applymovement VAR_LAST_TALKED, BattleFrontier_BattleTowerMultiPartnerRoom_Movement_PartnerExitSouth
# 209 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	waitmovement 0
# 210 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	return
# 211 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 212 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Movement_PartnerExit:
# 213 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	walk_fast_up
# 214 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	walk_fast_up
# 215 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	walk_fast_up
# 216 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	walk_fast_up
# 217 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	walk_fast_up
# 218 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	walk_fast_up
# 219 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	walk_fast_up
# 220 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	step_end
# 221 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 222 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Movement_PartnerExitSouth:
# 223 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	walk_fast_left
# 224 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	walk_fast_up
# 225 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	walk_fast_up
# 226 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	walk_fast_up
# 227 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	walk_fast_up
# 228 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	walk_fast_up
# 229 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	walk_fast_up
# 230 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	walk_fast_up
# 231 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	step_end
# 232 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 233 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_Partner2::
# 234 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	lock
# 235 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	faceplayer
# 236 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	setvar VAR_TEMP_2, 1
# 237 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	goto BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_TalkToPotentialPartner
# 238 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	end
# 239 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 240 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_Partner3::
# 241 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	lock
# 242 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	faceplayer
# 243 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	setvar VAR_TEMP_2, 2
# 244 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	goto BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_TalkToPotentialPartner
# 245 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	end
# 246 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 247 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_Partner4::
# 248 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	lock
# 249 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	faceplayer
# 250 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	setvar VAR_TEMP_2, 3
# 251 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	goto BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_TalkToPotentialPartner
# 252 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	end
# 253 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 254 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_Partner5::
# 255 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	lock
# 256 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	faceplayer
# 257 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	setvar VAR_TEMP_2, 4
# 258 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	goto BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_TalkToPotentialPartner
# 259 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	end
# 260 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 261 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_Partner6::
# 262 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	lock
# 263 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	faceplayer
# 264 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	setvar VAR_TEMP_2, 5
# 265 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	goto BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_TalkToPotentialPartner
# 266 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	end
# 267 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 268 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_Partner7::
# 269 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	lock
# 270 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	faceplayer
# 271 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	setvar VAR_TEMP_2, 6
# 272 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	goto BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_TalkToPotentialPartner
# 273 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	end
# 274 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 275 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_Partner8::
# 276 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	lock
# 277 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	faceplayer
# 278 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	setvar VAR_TEMP_2, 7
# 279 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	goto BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_TalkToPotentialPartner
# 280 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	end
# 281 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 282 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_PleaseFindPartner:
# 283 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Please find a partner from out of\n"
# 284 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "the TRAINERS gathered here.$"
# 285 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 286 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_QuitLookingForPartner:
# 287 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "{PLAYER}, you have not found a partner\n"
# 288 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "for your tag team.\p"
# 289 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Would you like to quit looking and\n"
# 290 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "return to the reception counter?$"
# 291 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 292 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_PleaseFindPartner2:
# 293 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Then, please find a partner from\n"
# 294 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "the TRAINERS gathered here.$"
# 295 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 296 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_ThankYouForChoosingPartner::
# 297 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Thank you for choosing a partner.\p"
# 298 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I will now show you to your\n"
# 299 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "MULTI BATTLE ROOM.$"
# 300 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 301 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_UnusedApprentice1Intro::
# 302 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I'm {STR_VAR_1}'s no. {STR_VAR_2} apprentice.\n"
# 303 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "You can call me {STR_VAR_3}!$"
# 304 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 305 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_UnusedApprentice1Mon1::
# 306 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "On {STR_VAR_1}'s advice, I brought\n"
# 307 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "one {STR_VAR_3} with {STR_VAR_2} and$"
# 308 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 309 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_UnusedApprentice1Mon2Ask::
# 310 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "one {STR_VAR_2} with {STR_VAR_1}.\p"
# 311 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Please, let me join you as a tag team.$"
# 312 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 313 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_UnusedApprentice1Accept::
# 314 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Thank you!\n"
# 315 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I'll go register right now.$"
# 316 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 317 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_UnusedApprentice1Reject::
# 318 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I really wanted to form a tag team\n"
# 319 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "with you, {PLAYER}…$"
# 320 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 321 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_UnusedApprentice2Intro::
# 322 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I am {STR_VAR_1}'s no. {STR_VAR_2} apprentice.\n"
# 323 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "My name is {STR_VAR_3}.$"
# 324 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 325 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_UnusedApprentice2Mon1::
# 326 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I got advice from {STR_VAR_1} and chose\n"
# 327 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "one {STR_VAR_3} with {STR_VAR_2} and$"
# 328 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 329 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_UnusedApprentice2Mon2Ask::
# 330 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "one {STR_VAR_2} with {STR_VAR_1}.\p"
# 331 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Please, let's form a tag team!$"
# 332 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 333 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_UnusedApprentice2Accept::
# 334 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Thank you very much!\n"
# 335 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I'll be done with registration quickly!$"
# 336 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 337 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_UnusedApprentice2Reject::
# 338 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "{PLAYER}, I was hoping that I could\n"
# 339 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "partner up with you…$"
# 340 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 341 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice1Intro::
# 342 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Um, my name's {STR_VAR_3}, and I'm\n"
# 343 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "{STR_VAR_1}'s no. {STR_VAR_2} apprentice.\p"
# 344 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Snivel…\p"
# 345 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I'm sorry!\n"
# 346 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "This tension is making me cry…$"
# 347 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 348 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice1Mon1::
# 349 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "{STR_VAR_3} advised me, so I have\n"
# 350 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "one {STR_VAR_2} with {STR_VAR_1} and$"
# 351 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 352 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice1Mon2Ask::
# 353 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "one {STR_VAR_2} with {STR_VAR_1}.\p"
# 354 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Snivel…\n"
# 355 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Please, please team up with me!$"
# 356 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 357 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice1Accept::
# 358 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Oh, really? You will?\n"
# 359 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Awesome! Wicked! Awoooh!\p"
# 360 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Oh… I'm sorry…\n"
# 361 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I'm so happy, I'm crying…\p"
# 362 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I'll go register right away.\n"
# 363 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Please don't go away!$"
# 364 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 365 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice1Reject::
# 366 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Oh, b-but…\n"
# 367 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Sob… Waaaaah!$"
# 368 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 369 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice2Intro::
# 370 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Hi, there! I'm {STR_VAR_3}!\n"
# 371 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I'm {STR_VAR_1}'s no. {STR_VAR_2} apprentice!$"
# 372 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 373 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice2Mon1::
# 374 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "{STR_VAR_3} recommended my crew.\n"
# 375 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "One {STR_VAR_2} with {STR_VAR_1} and$"
# 376 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 377 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice2Mon2Ask::
# 378 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "one {STR_VAR_2} with {STR_VAR_1},\n"
# 379 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "that's what I have! Cool, huh?\p"
# 380 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "So come on!\n"
# 381 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Let's form a tag team!$"
# 382 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 383 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice2Accept::
# 384 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Yay! Great!\n"
# 385 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Okay, I'll go register, okay?$"
# 386 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 387 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice2Reject::
# 388 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Aww, why?\n"
# 389 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I wanted to team up, {PLAYER}!$"
# 390 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 391 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice3Intro::
# 392 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I'm {STR_VAR_3}, the no. {STR_VAR_2} apprentice\n"
# 393 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "of the famous {STR_VAR_1}!$"
# 394 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 395 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice3Mon1::
# 396 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I looked to {STR_VAR_3} for advice.\n"
# 397 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "One {STR_VAR_1}-using {STR_VAR_2}$"
# 398 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 399 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice3Mon2Ask::
# 400 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "and one {STR_VAR_2} with {STR_VAR_1},\n"
# 401 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "that's my pair.\p"
# 402 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Please, will you join me in\n"
# 403 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "a tag team?$"
# 404 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 405 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice3Accept::
# 406 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Thank you!\n"
# 407 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I'll register right away!$"
# 408 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 409 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice3Reject::
# 410 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "{PLAYER}, I had been hoping to join\n"
# 411 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "you in a tag team…$"
# 412 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 413 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice4Intro::
# 414 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Um… I'm sincerely happy that you\n"
# 415 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "would take the time to talk to me.\p"
# 416 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I'm {STR_VAR_3}.\n"
# 417 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I'm {STR_VAR_1}'s no. {STR_VAR_2} apprentice…$"
# 418 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 419 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice4Mon1::
# 420 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "{STR_VAR_3} gave me advice.\n"
# 421 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I'm very grateful for it.\p"
# 422 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I have a team of one {STR_VAR_2}\n"
# 423 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "with {STR_VAR_1} and$"
# 424 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 425 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice4Mon2Ask::
# 426 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "one {STR_VAR_2} with {STR_VAR_1}.\n"
# 427 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I know I'm asking a lot…\p"
# 428 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I don't think you'll be willing to,\n"
# 429 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "but may I join you as a partner?$"
# 430 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 431 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice4Accept::
# 432 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Really? I can't believe it!\n"
# 433 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I can't believe you'll let me join you!\l"
# 434 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I… I won't let you down!\p"
# 435 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Um… If it's really okay, I'll go register\n"
# 436 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "right this instant!$"
# 437 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 438 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice4Reject::
# 439 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Oh…\n"
# 440 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I didn't think I was good enough…$"
# 441 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 442 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice5Intro::
# 443 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Hi, I'm {STR_VAR_3}.\n"
# 444 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I'm {STR_VAR_1}'s no. {STR_VAR_2} apprentice!$"
# 445 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 446 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice5Mon1::
# 447 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "{STR_VAR_3} told me that it would be\n"
# 448 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "good to make this team:\l"
# 449 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "one {STR_VAR_1}-using {STR_VAR_2}$"
# 450 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 451 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice5Mon2Ask::
# 452 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "and one {STR_VAR_2} that knows how\n"
# 453 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "to use {STR_VAR_1}.\p"
# 454 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Not bad, huh?\n"
# 455 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Want me to team up with you?$"
# 456 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 457 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice5Accept::
# 458 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Okay, glad to join you!\n"
# 459 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I hope you won't mess things up for me!\l"
# 460 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I'll do my registration now.$"
# 461 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 462 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice5Reject::
# 463 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Huh? Why did you turn me down?\n"
# 464 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "You're no judge of character!$"
# 465 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 466 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice6Intro::
# 467 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I'm {STR_VAR_3} and I'm a TRIATHLETE.\n"
# 468 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I'm busy every day what with jogging,\l"
# 469 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "training, and rapping.\p"
# 470 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I also happen to be {STR_VAR_1}'s\n"
# 471 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "no. {STR_VAR_2} apprentice.$"
# 472 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 473 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice6Mon1::
# 474 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "This is what {STR_VAR_3} recommended.\n"
# 475 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "One {STR_VAR_1}-using {STR_VAR_2}$"
# 476 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 477 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice6Mon2Ask::
# 478 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "and one {STR_VAR_1}-using\n"
# 479 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "{STR_VAR_2}.\p"
# 480 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I put a lot of effort into raising\n"
# 481 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "them, even though I'm busy.\p"
# 482 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Let's form a tag team\n"
# 483 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "and give it a go!$"
# 484 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 485 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice6Accept::
# 486 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Thanks, that's the spirit!\n"
# 487 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Hang tight while I go register, okay?$"
# 488 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 489 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice6Reject::
# 490 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I took time from my busy schedule\n"
# 491 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "to be here! Give me a break!$"
# 492 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 493 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice7Intro::
# 494 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Hi!\n"
# 495 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "How's it going?\p"
# 496 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I'm {STR_VAR_3}, {STR_VAR_1}'s\n"
# 497 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "no. {STR_VAR_2} apprentice. Glad to meet you!$"
# 498 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 499 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice7Mon1::
# 500 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Listen, listen! You have to hear about\n"
# 501 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "the POKéMON {STR_VAR_3} recommended.\l"
# 502 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "One {STR_VAR_2} with {STR_VAR_1} and$"
# 503 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 504 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice7Mon2Ask::
# 505 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "one {STR_VAR_2} with {STR_VAR_1}.\n"
# 506 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Of course I raised them superbly!\p"
# 507 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "So, want to team up?\n"
# 508 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I'm sure it'll be a great combo!$"
# 509 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 510 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice7Accept::
# 511 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Yay, I think this will be fun!\n"
# 512 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I'll go register!$"
# 513 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 514 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice7Reject::
# 515 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Oh, you're mean!\n"
# 516 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I come recommended, you know.$"
# 517 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 518 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice8Intro::
# 519 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Please let me introduce myself.\n"
# 520 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I am {STR_VAR_3}.\p"
# 521 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I serve as {STR_VAR_1}'s\n"
# 522 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "no. {STR_VAR_2} apprentice.$"
# 523 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 524 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice8Mon1::
# 525 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I sought the sage advice of\n"
# 526 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "{STR_VAR_3} and raised my team\l"
# 527 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "of one {STR_VAR_2} with {STR_VAR_1}$"
# 528 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 529 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice8Mon2Ask::
# 530 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "and one {STR_VAR_2} with {STR_VAR_1}.\p"
# 531 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Please agree to a tag team with me!$"
# 532 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 533 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice8Accept::
# 534 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Oh… I'm delighted!\n"
# 535 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I promise to give you my best!\p"
# 536 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Of course I will register us!\n"
# 537 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Please wait!$"
# 538 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 539 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice8Reject::
# 540 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I had been hoping to join you,\n"
# 541 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "{PLAYER}…$"
# 542 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 543 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice9Intro::
# 544 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Eek! You spoke to me!\n"
# 545 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I… I'm overjoyed!\p"
# 546 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I'm {STR_VAR_3}! I'm {STR_VAR_1}'s\n"
# 547 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "no. {STR_VAR_2} apprentice!$"
# 548 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 549 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice9Mon1::
# 550 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "On {STR_VAR_3}'s advice, I trained\n"
# 551 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "one {STR_VAR_1}-using {STR_VAR_2}$"
# 552 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 553 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice9Mon2Ask::
# 554 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "and one {STR_VAR_1}-using\n"
# 555 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "{STR_VAR_2}.\p"
# 556 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Please, can you grant me my wish?\n"
# 557 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I want to be your tag-team partner!$"
# 558 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 559 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice9Accept::
# 560 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Eek! I… I feel giddy!\n"
# 561 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Thank you so much!\l"
# 562 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I'll go register us right away!$"
# 563 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 564 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice9Reject::
# 565 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Waaah! Don't you feel any pity?\n"
# 566 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "But that makes you cooler…$"
# 567 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 568 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice10Intro::
# 569 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Yeehaw! I'm {STR_VAR_1}'s\n"
# 570 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "no. {STR_VAR_2} apprentice!\p"
# 571 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "{STR_VAR_3}'s my name, hello, hello!$"
# 572 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 573 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice10Mon1::
# 574 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "My mentor {STR_VAR_3} recommended\n"
# 575 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "one {STR_VAR_1}-master {STR_VAR_2}$"
# 576 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 577 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice10Mon2Ask::
# 578 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "and one {STR_VAR_1}-master\n"
# 579 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "{STR_VAR_2}.\p"
# 580 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Good stuff, huh?\n"
# 581 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "You'll partner with me, won't you?$"
# 582 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 583 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice10Accept::
# 584 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Okay, excellent!\n"
# 585 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I'll get the registration done quickly!$"
# 586 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 587 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice10Reject::
# 588 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Gwaaah!\n"
# 589 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "You're a calculating one, {PLAYER}!$"
# 590 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 591 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice11Intro::
# 592 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Hey! There's big trouble! This is\n"
# 593 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "the BATTLE TOWER's last day!\p"
# 594 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "… … … … … …\n"
# 595 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I'm only joking!\p"
# 596 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "People call me {STR_VAR_3} and I do, too!\n"
# 597 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I'm {STR_VAR_1}'s 1,000th apprentice!\l"
# 598 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Actually, I'm no. {STR_VAR_2}!$"
# 599 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 600 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice11Mon1::
# 601 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "{STR_VAR_3} gave me some advice.\n"
# 602 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "{STR_VAR_2} with {STR_VAR_1} and$"
# 603 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 604 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice11Mon2Ask::
# 605 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "{STR_VAR_2} with {STR_VAR_1}.\n"
# 606 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I've got ten of each kind!\l"
# 607 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Actually, just one of each!\p"
# 608 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "How about it?\n"
# 609 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Want to try tag battles with me?$"
# 610 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 611 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice11Accept::
# 612 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Yippee!\n"
# 613 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I'll give you a POKéMON as my thanks!\p"
# 614 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Just joking! But I will really go do\n"
# 615 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "the registration, okay?$"
# 616 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 617 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice11Reject::
# 618 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Oh, that's so cold! I'll have to wreck\n"
# 619 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "the BATTLE TOWER for that!\p"
# 620 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Of course I won't!$"
# 621 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 622 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice12Intro::
# 623 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Hey, there, I'm rockin' and a-rollin'!\n"
# 624 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "POKéMON, I be controllin'!\p"
# 625 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I'm {STR_VAR_3} the rappin' SAILOR.\n"
# 626 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Don't be mistakin' me for no wailer!\p"
# 627 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I'm {STR_VAR_1}'s no. {STR_VAR_2} apprentice.\n"
# 628 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Me, you shouldn't be quick to dismiss!$"
# 629 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 630 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice12Mon1::
# 631 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "With the advice of {STR_VAR_3} I did\n"
# 632 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "abide, put together my team of pride!\l"
# 633 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "One {STR_VAR_1}-using {STR_VAR_2}$"
# 634 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 635 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice12Mon2Ask::
# 636 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "and one {STR_VAR_1}-using\n"
# 637 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "{STR_VAR_2}!\p"
# 638 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Our meeting we should commemorate,\n"
# 639 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "with a tag-team victory to celebrate!$"
# 640 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 641 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice12Accept::
# 642 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Hey, hey, I like your style!\n"
# 643 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Our registration, I will go file!$"
# 644 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 645 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice12Reject::
# 646 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Oh, hey, {PLAYER}, now that's cold!\n"
# 647 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "If I may be so bold!$"
# 648 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 649 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice13Intro::
# 650 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Yippee-yahoo!\n"
# 651 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Oh, don't run! I was just having fun!\p"
# 652 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Howdy! I'm {STR_VAR_3}!\n"
# 653 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I'm {STR_VAR_1}'s no. {STR_VAR_2} apprentice!$"
# 654 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 655 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice13Mon1::
# 656 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "{STR_VAR_3} told me what to do.\n"
# 657 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "So one {STR_VAR_1}-using {STR_VAR_2}$"
# 658 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 659 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice13Mon2Ask::
# 660 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "and one {STR_VAR_1}-using\n"
# 661 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "{STR_VAR_2}, I did choose.\p"
# 662 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "So, what do you say?\n"
# 663 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Come on, make my day!\p"
# 664 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Please, I'm begging you!\n"
# 665 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Let me join you, don't leave me blue!$"
# 666 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 667 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice13Accept::
# 668 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Yeahah! Luck is with me!\n"
# 669 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "It sure makes me happy!\p"
# 670 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Before we go join the fray,\n"
# 671 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I'll go register right away!$"
# 672 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 673 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice13Reject::
# 674 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "You're turning me down?\n"
# 675 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "{PLAYER}, you're making me frown!$"
# 676 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 677 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice14Intro::
# 678 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Cough!\p"
# 679 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Oh, sorry, I have a cold.\n"
# 680 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "My POKéMON are fine, though.\p"
# 681 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "My name's {STR_VAR_3}, {STR_VAR_1}'s\n"
# 682 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "no. {STR_VAR_2} apprentice. Cough!$"
# 683 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 684 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice14Mon1::
# 685 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I took {STR_VAR_3}'s advice to heart\n"
# 686 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "and put together my team of\l"
# 687 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "one {STR_VAR_2} with {STR_VAR_1} and$"
# 688 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 689 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice14Mon2Ask::
# 690 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "one {STR_VAR_2} with {STR_VAR_1}.\p"
# 691 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I trained them every day,\n"
# 692 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "even in wind and rain.\p"
# 693 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "That's why I have this cold,\n"
# 694 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I think.\p"
# 695 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "That's what I'm about.\n"
# 696 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Want to be my tag partner?$"
# 697 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 698 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice14Accept::
# 699 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Thanks, I appreciate this!\n"
# 700 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Cough, cough!\l"
# 701 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Hang on while I go register.$"
# 702 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 703 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice14Reject::
# 704 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Oh, you won't?\n"
# 705 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "{PLAYER}, I think we'd make a good pair.$"
# 706 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 707 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice15Intro::
# 708 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Oh, hello!\n"
# 709 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "This is nerve-racking.\p"
# 710 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I'm {STR_VAR_3}.\n"
# 711 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I'm the no. {STR_VAR_2} apprentice of {STR_VAR_1}.$"
# 712 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 713 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice15Mon1::
# 714 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "{STR_VAR_3} said this team'll be good--\n"
# 715 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "one {STR_VAR_2} with {STR_VAR_1} and$"
# 716 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 717 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice15Mon2Ask::
# 718 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "one {STR_VAR_2} with {STR_VAR_1}.\p"
# 719 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I'm feeling self-conscious about this,\n"
# 720 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "but will you let me join you?$"
# 721 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 722 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice15Accept::
# 723 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Oh, gee, thank you!\n"
# 724 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I feel bashful, but I'll do my best!\p"
# 725 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I'll go get the registration done.$"
# 726 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 727 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice15Reject::
# 728 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Oh, please don't say no!\n"
# 729 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I feel self-conscious enough already…$"
# 730 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 731 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice16Intro::
# 732 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I am {STR_VAR_3}, and that's no lie.\n"
# 733 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I am {STR_VAR_1}'s no. {STR_VAR_2} apprentice.$"
# 734 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 735 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice16Mon1::
# 736 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "{STR_VAR_3} recommended my team.\p"
# 737 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Since the advice sounded sincere,\n"
# 738 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I decided to bring with me\l"
# 739 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "my {STR_VAR_1}-using {STR_VAR_2} and$"
# 740 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 741 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice16Mon2Ask::
# 742 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "my {STR_VAR_1}-using {STR_VAR_2}.\p"
# 743 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "If possible, I would like you to accept\n"
# 744 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "me as your tag-team partner.$"
# 745 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 746 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice16Accept::
# 747 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "You really will accept me?\n"
# 748 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "It would be too terrible otherwise.\p"
# 749 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "But since you've agreed, this is fine.\n"
# 750 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I shall go register the both of us.$"
# 751 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 752 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice16Reject::
# 753 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Hm? Now why would you refuse?\n"
# 754 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Is this your idea of a joke?$"
# 755 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 756 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_LassIntro::
# 757 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I'm {STR_VAR_1}, and I'm a LASS!$"
# 758 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 759 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_LassMon1::
# 760 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "What I have are one {STR_VAR_2}\n"
# 761 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "that uses {STR_VAR_1} and one$"
# 762 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 763 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_LassMon2Ask::
# 764 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "{STR_VAR_2} that uses {STR_VAR_1}.\n"
# 765 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Those are what I have with me.\p"
# 766 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Will you be my partner?$"
# 767 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 768 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_LassAccept::
# 769 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Thank you!\n"
# 770 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I'll go do the registration!$"
# 771 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 772 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_LassReject::
# 773 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "You don't want to be my partner?\n"
# 774 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "You'll regret it later!$"
# 775 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 776 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_YoungsterIntro::
# 777 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Hello!\p"
# 778 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I'm YOUNGSTER {STR_VAR_1}!$"
# 779 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 780 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_YoungsterMon1::
# 781 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Want to know what I have?\n"
# 782 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "One {STR_VAR_2} with {STR_VAR_1} and$"
# 783 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 784 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_YoungsterMon2Ask::
# 785 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "one {STR_VAR_2} with {STR_VAR_1}!\p"
# 786 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "You'll be my tag-team partner,\n"
# 787 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "won't you?$"
# 788 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 789 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_YoungsterAccept::
# 790 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Yay!\n"
# 791 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I'll go and register, okay?$"
# 792 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 793 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_YoungsterReject::
# 794 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Aww! If you'd form a tag team with\n"
# 795 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "my POKéMON, we'd be unstoppable!$"
# 796 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 797 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_HikerIntro::
# 798 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Yahoo!\n"
# 799 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I'm HIKER {STR_VAR_1}!$"
# 800 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 801 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_HikerMon1::
# 802 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Know what I have with me?\n"
# 803 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "My {STR_VAR_1}-using {STR_VAR_2} and$"
# 804 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 805 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_HikerMon2Ask::
# 806 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "my {STR_VAR_1}-using {STR_VAR_2}!\p"
# 807 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Sounds good, eh?\n"
# 808 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Want to form a tag team?$"
# 809 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 810 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_HikerAccept::
# 811 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Yahoo!\n"
# 812 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I'll go do the registering, then.$"
# 813 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 814 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_HikerReject::
# 815 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I would've liked to battle with you\n"
# 816 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "at my side.$"
# 817 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 818 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_BeautyIntro::
# 819 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Hello!\n"
# 820 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I'm {STR_VAR_1}, and I'm a BEAUTY!$"
# 821 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 822 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_BeautyMon1::
# 823 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Do you know what I've been raising?\n"
# 824 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "One {STR_VAR_2} with {STR_VAR_1} and$"
# 825 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 826 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_BeautyMon2Ask::
# 827 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "one {STR_VAR_2} with {STR_VAR_1}!\p"
# 828 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "What do you think?\n"
# 829 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Want to make a tag team together?$"
# 830 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 831 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_BeautyAccept::
# 832 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Wonderful!\n"
# 833 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I'll get the registration done now!$"
# 834 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 835 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_BeautyReject::
# 836 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "How disappointing!\p"
# 837 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "We two together--we would've been\n"
# 838 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "the best!$"
# 839 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 840 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_FishermanIntro::
# 841 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Yo!\p"
# 842 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "You know who I am?\n"
# 843 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I'm {STR_VAR_1} the FISHERMAN!$"
# 844 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 845 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_FishermanMon1::
# 846 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I've got with me a team of one\n"
# 847 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "{STR_VAR_1}-using {STR_VAR_2} and$"
# 848 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 849 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_FishermanMon2Ask::
# 850 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "one {STR_VAR_1}-using {STR_VAR_2}.\p"
# 851 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "So, how about it?\n"
# 852 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Will you battle at my side?$"
# 853 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 854 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_FishermanAccept::
# 855 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Good, good!\n"
# 856 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Leave it up to me!\p"
# 857 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I'll go and register us now.$"
# 858 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 859 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_FishermanReject::
# 860 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "We matched up perfectly, too…$"
# 861 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 862 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_LadyIntro::
# 863 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Glad to make your acquaintance.\n"
# 864 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I am {STR_VAR_1}, a LADY.$"
# 865 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 866 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_LadyMon1::
# 867 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I am accompanied by a team of\n"
# 868 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "one {STR_VAR_2} with {STR_VAR_1} and$"
# 869 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 870 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_LadyMon2Ask::
# 871 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "one {STR_VAR_2} with {STR_VAR_1}.\p"
# 872 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I hope I meet your approval.\n"
# 873 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "For I wish to have you as my partner.$"
# 874 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 875 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_LadyAccept::
# 876 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I thank you sincerely.\n"
# 877 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I shall handle the registration.$"
# 878 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 879 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_LadyReject::
# 880 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I'm sure that you will regret not\n"
# 881 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "having me as your partner.$"
# 882 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 883 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_CyclingTriathleteFIntro::
# 884 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I'm TRIATHLETE {STR_VAR_1}!$"
# 885 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 886 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_CyclingTriathleteFMon1::
# 887 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "What I have…\n"
# 888 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "One {STR_VAR_2} with {STR_VAR_1} and$"
# 889 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 890 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_CyclingTriathleteFMon2Ask::
# 891 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "one {STR_VAR_2} with {STR_VAR_1}!\n"
# 892 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "That's my pair!\p"
# 893 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Please?\n"
# 894 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Will you form a tag team with me?$"
# 895 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 896 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_CyclingTriathleteFAccept::
# 897 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Gee, thanks!\n"
# 898 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I'll go register at the counter.$"
# 899 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 900 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_CyclingTriathleteFReject::
# 901 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "We two together, we would've been\n"
# 902 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "tough for certain!$"
# 903 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 904 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_BugCatcherIntro::
# 905 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Hiya!\n"
# 906 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I'm BUG CATCHER {STR_VAR_1}!$"
# 907 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 908 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_BugCatcherMon1::
# 909 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Check out what I have!\n"
# 910 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "One {STR_VAR_2} with {STR_VAR_1} and$"
# 911 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 912 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_BugCatcherMon2Ask::
# 913 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "one {STR_VAR_2} with {STR_VAR_1}!\p"
# 914 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "So, listen!\n"
# 915 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Do you want to form a tag team?$"
# 916 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 917 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_BugCatcherAccept::
# 918 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Gotcha!\p"
# 919 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I'll go do the registration stuff\n"
# 920 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "at the counter.$"
# 921 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 922 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_BugCatcherReject::
# 923 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Aww, my POKéMON are awesome.\n"
# 924 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I hope you won't regret this!$"
# 925 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 926 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_SchoolKidMIntro::
# 927 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Good day!\n"
# 928 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I'm SCHOOL KID {STR_VAR_1}!$"
# 929 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 930 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_SchoolKidMMon1::
# 931 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "What I've been raising are one\n"
# 932 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "{STR_VAR_2} that uses {STR_VAR_1}$"
# 933 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 934 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_SchoolKidMMon2Ask::
# 935 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "and one {STR_VAR_2} that uses\n"
# 936 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "{STR_VAR_1}.\p"
# 937 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Not too bad, don't you think?\n"
# 938 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Would you care to form a tag team?$"
# 939 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 940 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_SchoolKidMAccept::
# 941 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Thank you very much!\n"
# 942 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I'll get done with the registration.$"
# 943 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 944 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_SchoolKidMReject::
# 945 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "That's too bad…\p"
# 946 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I was hoping that I could learn\n"
# 947 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "from you as your partner…$"
# 948 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 949 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_RichBoyIntro::
# 950 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Yo! Let me tell you who I am!\n"
# 951 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I'm RICH BOY {STR_VAR_1}!$"
# 952 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 953 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_RichBoyMon1::
# 954 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Guess what I got!\n"
# 955 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "One {STR_VAR_2} with {STR_VAR_1} and$"
# 956 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 957 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_RichBoyMon2Ask::
# 958 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "one {STR_VAR_2} with {STR_VAR_1}!\p"
# 959 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I'm willing to offer you the chance\n"
# 960 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "to be in a tag team with me.$"
# 961 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 962 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_RichBoyAccept::
# 963 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Smart move!\p"
# 964 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I'll finish up the registration\n"
# 965 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "process quick!$"
# 966 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 967 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_RichBoyReject::
# 968 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "You'd turn me of all people down?\n"
# 969 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "You'll regret that decision for sure!$"
# 970 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 971 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_BlackBeltIntro::
# 972 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Hiyah!\n"
# 973 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I am BLACK BELT {STR_VAR_1}.$"
# 974 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 975 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_BlackBeltMon1::
# 976 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "As my companions, I have\n"
# 977 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "one {STR_VAR_2} using {STR_VAR_1}$"
# 978 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 979 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_BlackBeltMon2Ask::
# 980 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "and one {STR_VAR_2} using\n"
# 981 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "{STR_VAR_1}.\p"
# 982 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Please, grant me my wish!\n"
# 983 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Allow me to be your tag partner!$"
# 984 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 985 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_BlackBeltAccept::
# 986 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Hiyah!\n"
# 987 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I will go register forthwith!$"
# 988 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 989 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_BlackBeltReject::
# 990 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I see… I hope for an opportunity\n"
# 991 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "the next time we meet…$"
# 992 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 993 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_TuberFIntro::
# 994 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Hi, there!\n"
# 995 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I'm {STR_VAR_1}, and I'm a TUBER!$"
# 996 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 997 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_TuberFMon1::
# 998 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I'll tell you what I have.\n"
# 999 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "One {STR_VAR_2} with {STR_VAR_1} and$"
# 1000 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1001 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_TuberFMon2Ask::
# 1002 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "one {STR_VAR_2} with {STR_VAR_1}!\n"
# 1003 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "May I please be on your tag team?$"
# 1004 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1005 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_TuberFAccept::
# 1006 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Thank you!\n"
# 1007 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I'll go register us now!$"
# 1008 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1009 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_TuberFReject::
# 1010 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "If we'd become partners, we could\n"
# 1011 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "have been so strong!$"
# 1012 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1013 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_HexManiacIntro::
# 1014 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Greetings…\n"
# 1015 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I am HEX MANIAC {STR_VAR_1}…$"
# 1016 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1017 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_HexManiacMon1::
# 1018 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I bear with me one {STR_VAR_1}-using\n"
# 1019 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "{STR_VAR_2} together with one$"
# 1020 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1021 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_HexManiacMon2Ask::
# 1022 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "{STR_VAR_1}-using {STR_VAR_2}…\p"
# 1023 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I beseech you…\n"
# 1024 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Join me in a tag team…$"
# 1025 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1026 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_HexManiacAccept::
# 1027 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I thank you…\n"
# 1028 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I shall register us…$"
# 1029 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1030 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_HexManiacReject::
# 1031 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I so longed to join you…$"
# 1032 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1033 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnBreederMIntro::
# 1034 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "How do you do? I'm {STR_VAR_1},\n"
# 1035 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "and I'm a POKéMON BREEDER!$"
# 1036 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1037 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnBreederMMon1::
# 1038 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I'm raising a couple good ones!\n"
# 1039 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "One {STR_VAR_2} with {STR_VAR_1} and$"
# 1040 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1041 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnBreederMMon2Ask::
# 1042 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "one {STR_VAR_2} with {STR_VAR_1}!\p"
# 1043 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "How about it?\n"
# 1044 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Feel like making a tag team with me?$"
# 1045 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1046 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnBreederMAccept::
# 1047 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Thank you kindly!\p"
# 1048 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I'll go take care of the registration\n"
# 1049 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "stuff, so you wait right here!$"
# 1050 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1051 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnBreederMReject::
# 1052 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I was looking forward to being\n"
# 1053 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "your partner…$"
# 1054 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1055 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_RunningTriathleteFIntro::
# 1056 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Well, hello!\n"
# 1057 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I'm TRIATHLETE {STR_VAR_1}!$"
# 1058 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1059 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_RunningTriathleteFMon1::
# 1060 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Want to know what I run with?\n"
# 1061 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "One {STR_VAR_2} with {STR_VAR_1} and$"
# 1062 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1063 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_RunningTriathleteFMon2Ask::
# 1064 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "one {STR_VAR_2} with {STR_VAR_1}!\p"
# 1065 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Well?\n"
# 1066 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Want to be in a tag team with me?$"
# 1067 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1068 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_RunningTriathleteFAccept::
# 1069 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Good going!\p"
# 1070 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I'll be quick and get the registration\n"
# 1071 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "all done!$"
# 1072 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1073 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_RunningTriathleteFReject::
# 1074 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "You and me, we would've been tops.\n"
# 1075 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "It's too bad…$"
# 1076 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1077 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_RunningTriathleteMIntro::
# 1078 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Hey, there! My name's {STR_VAR_1}!\n"
# 1079 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I'm a TRIATHLETE!$"
# 1080 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1081 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_RunningTriathleteMMon1::
# 1082 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I go on runs with my durable team--\n"
# 1083 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "one {STR_VAR_2} with {STR_VAR_1} and$"
# 1084 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1085 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_RunningTriathleteMMon2Ask::
# 1086 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "one {STR_VAR_2} with {STR_VAR_1}!\p"
# 1087 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Not too shabby, huh?\n"
# 1088 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "We should be in a tag team together!$"
# 1089 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1090 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_RunningTriathleteMAccept::
# 1091 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "All right!\n"
# 1092 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I'll go register in a flash!$"
# 1093 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1094 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_RunningTriathleteMReject::
# 1095 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I really wanted to battle as your\n"
# 1096 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "tag-team partner…$"
# 1097 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1098 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_BattleGirlIntro::
# 1099 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I'm BATTLE GIRL {STR_VAR_1}!$"
# 1100 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1101 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_BattleGirlMon1::
# 1102 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I've been toughening up one\n"
# 1103 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "{STR_VAR_1}-using {STR_VAR_2} and$"
# 1104 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1105 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_BattleGirlMon2Ask::
# 1106 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "one {STR_VAR_1}-using {STR_VAR_2}!\p"
# 1107 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Do you like that combo?\n"
# 1108 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "How about you and me join up?$"
# 1109 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1110 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_BattleGirlAccept::
# 1111 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Why, thanks!\p"
# 1112 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I'll get the registration done\n"
# 1113 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "right now!$"
# 1114 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1115 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_BattleGirlReject::
# 1116 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "With you, I thought we could form\n"
# 1117 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "the ultimate tag team…$"
# 1118 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1119 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_CyclingTriathleteMIntro::
# 1120 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I'm TRIATHLETE {STR_VAR_1}!$"
# 1121 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1122 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_CyclingTriathleteMMon1::
# 1123 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I've been running with one {STR_VAR_2}\n"
# 1124 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "that knows how to use {STR_VAR_1}$"
# 1125 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1126 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_CyclingTriathleteMMon2Ask::
# 1127 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "and one {STR_VAR_2} with {STR_VAR_1}!\p"
# 1128 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "We could be in a tag team.\n"
# 1129 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Wouldn't that be great?$"
# 1130 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1131 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_CyclingTriathleteMAccept::
# 1132 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Thank you!\p"
# 1133 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I'll go register us, and that's\n"
# 1134 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "right now!$"
# 1135 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1136 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_CyclingTriathleteMReject::
# 1137 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Aww, that's too bad. We would've been\n"
# 1138 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "the toughest tag team around!$"
# 1139 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1140 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_TuberMIntro::
# 1141 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Me?\n"
# 1142 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I'm TUBER {STR_VAR_1}!$"
# 1143 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1144 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_TuberMMon1::
# 1145 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "What do I have with me?\n"
# 1146 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "One {STR_VAR_2} with {STR_VAR_1} and$"
# 1147 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1148 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_TuberMMon2Ask::
# 1149 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "one {STR_VAR_2} with {STR_VAR_1}!\p"
# 1150 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Hey?\n"
# 1151 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "You'll team up with me, right?$"
# 1152 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1153 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_TuberMAccept::
# 1154 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Okay!\p"
# 1155 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I'll go register!\n"
# 1156 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Let's be excellent together!$"
# 1157 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1158 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_TuberMReject::
# 1159 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "My POKéMON are tough for sure…\n"
# 1160 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "It's too bad you don't want to team up.$"
# 1161 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1162 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_GuitaristIntro::
# 1163 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Yay-hey!\n"
# 1164 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Call me GUITARIST {STR_VAR_1}!$"
# 1165 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1166 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_GuitaristMon1::
# 1167 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Check out my entourage!\n"
# 1168 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "One {STR_VAR_2} with {STR_VAR_1} and$"
# 1169 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1170 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_GuitaristMon2Ask::
# 1171 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "one {STR_VAR_2} with {STR_VAR_1}!\p"
# 1172 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Yay-hey! Pretty wild, huh?\n"
# 1173 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "We'll have to do a duet in a tag team!$"
# 1174 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1175 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_GuitaristAccept::
# 1176 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Yay-hey! Right on!\n"
# 1177 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I'll do that registration stuff now!$"
# 1178 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1179 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_GuitaristReject::
# 1180 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "My POKéMON rock hard!\n"
# 1181 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "You'll be sorry, I tell you!$"
# 1182 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1183 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_GentlemanIntro::
# 1184 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Pleased to meet you.\n"
# 1185 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I am {STR_VAR_1}, a GENTLEMAN.$"
# 1186 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1187 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_GentlemanMon1::
# 1188 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I am accompanied by my trusted\n"
# 1189 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "{STR_VAR_1}-using {STR_VAR_2} and$"
# 1190 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1191 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_GentlemanMon2Ask::
# 1192 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "one {STR_VAR_1}-using {STR_VAR_2}.\p"
# 1193 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "May I ask you to join me in a tag-team\n"
# 1194 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "partnership arrangement?$"
# 1195 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1196 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_GentlemanAccept::
# 1197 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Ah, I thank you for your trust.\n"
# 1198 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I shall be done with the registration.$"
# 1199 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1200 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_GentlemanReject::
# 1201 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "That is most unfortunate…\p"
# 1202 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I shall look forward to the next\n"
# 1203 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "opportunity…$"
# 1204 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1205 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokefanMIntro::
# 1206 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Hello, I'm {STR_VAR_1},\n"
# 1207 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "and I'm a POKéFAN.$"
# 1208 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1209 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokefanMMon1::
# 1210 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I have with me now one {STR_VAR_2}\n"
# 1211 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "that knows the move {STR_VAR_1} and$"
# 1212 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1213 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokefanMMon2Ask::
# 1214 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "one {STR_VAR_2} with {STR_VAR_1}.\p"
# 1215 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Do you like what you see?\n"
# 1216 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Why don't you be my tag partner?$"
# 1217 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1218 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokefanMAccept::
# 1219 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Thank you!\n"
# 1220 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I'll look after the registration!$"
# 1221 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1222 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokefanMReject::
# 1223 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "My POKéMON are top grade…\n"
# 1224 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "It's too bad you can't appreciate that.$"
# 1225 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1226 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_ExpertMIntro::
# 1227 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Hm!\n"
# 1228 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I am {STR_VAR_1}, and an EXPERT am I!$"
# 1229 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1230 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_ExpertMMon1::
# 1231 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "The POKéMON that I've toughened up are\n"
# 1232 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "one {STR_VAR_2} with {STR_VAR_1} and$"
# 1233 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1234 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_ExpertMMon2Ask::
# 1235 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "one {STR_VAR_2} with {STR_VAR_1}!\p"
# 1236 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "What say you to a tag team with me?$"
# 1237 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1238 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_ExpertMAccept::
# 1239 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Hm!\n"
# 1240 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I shall register us right away!\l"
# 1241 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Let us both do our best!$"
# 1242 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1243 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_ExpertMReject::
# 1244 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I will hope that your choice is\n"
# 1245 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "indeed correct…$"
# 1246 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1247 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_ExpertFIntro::
# 1248 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Hello, hello.\n"
# 1249 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I'm {STR_VAR_1}, and I'm an EXPERT.$"
# 1250 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1251 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_ExpertFMon1::
# 1252 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I've raised my POKéMON thoroughly.\n"
# 1253 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "One {STR_VAR_2} with {STR_VAR_1} and$"
# 1254 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1255 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_ExpertFMon2Ask::
# 1256 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "one {STR_VAR_2} with {STR_VAR_1}--\n"
# 1257 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "they're what I have.\p"
# 1258 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Wouldn't you like to team up with me?$"
# 1259 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1260 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_ExpertFAccept::
# 1261 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Good, good.\n"
# 1262 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I'll see to the registration right away.$"
# 1263 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1264 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_ExpertFReject::
# 1265 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Perhaps we can form a team the next\n"
# 1266 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "time we meet.$"
# 1267 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1268 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_DragonTamerIntro::
# 1269 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I'm DRAGON TAMER {STR_VAR_1}!$"
# 1270 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1271 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_DragonTamerMon1::
# 1272 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "The team I've been toughening up is\n"
# 1273 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "one {STR_VAR_2} with {STR_VAR_1} and$"
# 1274 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1275 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_DragonTamerMon2Ask::
# 1276 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "one {STR_VAR_2} with {STR_VAR_1}!\p"
# 1277 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "How about it?\n"
# 1278 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Want to be my partner?$"
# 1279 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1280 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_DragonTamerAccept::
# 1281 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Okay, I'll give it my best!\n"
# 1282 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I'll go register now, all right?$"
# 1283 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1284 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_DragonTamerReject::
# 1285 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "You're not going to find many tougher\n"
# 1286 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "partners than me!$"
# 1287 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1288 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_BirdKeeperIntro::
# 1289 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I'm BIRD KEEPER {STR_VAR_1}!$"
# 1290 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1291 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_BirdKeeperMon1::
# 1292 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "What POKéMON do I have?\n"
# 1293 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "One {STR_VAR_2} with {STR_VAR_1} and$"
# 1294 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1295 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_BirdKeeperMon2Ask::
# 1296 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "one {STR_VAR_2} with {STR_VAR_1}.\p"
# 1297 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Don't you think we'd make a decent\n"
# 1298 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "tag team?$"
# 1299 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1300 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_BirdKeeperAccept::
# 1301 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Great, thanks!\n"
# 1302 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I'll look after the registration!$"
# 1303 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1304 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_BirdKeeperReject::
# 1305 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "My POKéMON and I are strong.\n"
# 1306 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "What a letdown.$"
# 1307 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1308 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_NinjaBoyIntro::
# 1309 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I'm NINJA BOY {STR_VAR_1}!$"
# 1310 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1311 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_NinjaBoyMon1::
# 1312 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "My POKéMON team consists of one\n"
# 1313 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "{STR_VAR_2} with {STR_VAR_1} and$"
# 1314 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1315 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_NinjaBoyMon2Ask::
# 1316 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "one {STR_VAR_2} with {STR_VAR_1}!\p"
# 1317 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Let's be in a tag team together!$"
# 1318 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1319 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_NinjaBoyAccept::
# 1320 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Yay!\n"
# 1321 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Let me go register!$"
# 1322 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1323 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_NinjaBoyReject::
# 1324 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "You'll regret not having my tough\n"
# 1325 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "POKéMON on your side!$"
# 1326 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1327 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_ParasolLadyIntro::
# 1328 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Hello!\n"
# 1329 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I'm PARASOL LADY {STR_VAR_1}!$"
# 1330 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1331 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_ParasolLadyMon1::
# 1332 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Escorting me now are my {STR_VAR_2}\n"
# 1333 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "that uses {STR_VAR_1} and$"
# 1334 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1335 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_ParasolLadyMon2Ask::
# 1336 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "one {STR_VAR_2} that uses\n"
# 1337 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "{STR_VAR_1}.\p"
# 1338 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Aren't they nice?\n"
# 1339 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Care to join us in a tag team?$"
# 1340 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1341 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_ParasolLadyAccept::
# 1342 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Thanks a bunch!\p"
# 1343 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I'll go register at the counter.\n"
# 1344 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Let's not disappoint each other!$"
# 1345 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1346 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_ParasolLadyReject::
# 1347 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "My POKéMON are tremendously strong.\n"
# 1348 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "How disappointing…$"
# 1349 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1350 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_BugManiacIntro::
# 1351 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Hello.\n"
# 1352 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I'm {STR_VAR_1}, and I'm a BUG MANIAC!$"
# 1353 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1354 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_BugManiacMon1::
# 1355 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I have found my POKéMON, yes.\n"
# 1356 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "One {STR_VAR_2} with {STR_VAR_1} and$"
# 1357 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1358 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_BugManiacMon2Ask::
# 1359 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "one {STR_VAR_2} with {STR_VAR_1}--\n"
# 1360 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "they are what I found.\p"
# 1361 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Could I interest you in forming\n"
# 1362 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "a tag team?$"
# 1363 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1364 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_BugManiacAccept::
# 1365 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Okay!\n"
# 1366 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Understood!\p"
# 1367 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I won't be long with the registration!$"
# 1368 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1369 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_BugManiacReject::
# 1370 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "With the POKéMON I found, we wouldn't\n"
# 1371 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "have lost…$"
# 1372 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1373 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_SailorIntro::
# 1374 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Ahoy, there!\n"
# 1375 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I'm SAILOR {STR_VAR_1}!$"
# 1376 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1377 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_SailorMon1::
# 1378 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Let me show you my pride and joy!\n"
# 1379 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "One {STR_VAR_2} with {STR_VAR_1} and$"
# 1380 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1381 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_SailorMon2Ask::
# 1382 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "one {STR_VAR_2} with {STR_VAR_1}!\p"
# 1383 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Of course you're not going to turn\n"
# 1384 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "me down. We will team up, right?$"
# 1385 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1386 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_SailorAccept::
# 1387 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I didn't expect any less!\n"
# 1388 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I'll go register now.$"
# 1389 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1390 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_SailorReject::
# 1391 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "We would've stormed through\n"
# 1392 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "the opposition! Too bad!$"
# 1393 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1394 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_CollectorIntro::
# 1395 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Hi, I'm {STR_VAR_1}.\n"
# 1396 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I'm a COLLECTOR.$"
# 1397 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1398 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_CollectorMon1::
# 1399 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "The jewels in my collection are\n"
# 1400 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "my {STR_VAR_2} with {STR_VAR_1} and$"
# 1401 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1402 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_CollectorMon2Ask::
# 1403 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "one {STR_VAR_2} with {STR_VAR_1}!\p"
# 1404 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Swell, huh?\n"
# 1405 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "We should be in a team together.$"
# 1406 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1407 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_CollectorAccept::
# 1408 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Oh, yeah!\p"
# 1409 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Well, let's not waste any time.\n"
# 1410 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I'll go register the two of us.$"
# 1411 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1412 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_CollectorReject::
# 1413 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Well, that's upsetting.\n"
# 1414 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "You don't appreciate my POKéMON.$"
# 1415 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1416 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnRangerMIntro::
# 1417 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Howdy, I'm {STR_VAR_1}.\n"
# 1418 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I'm a POKéMON RANGER.$"
# 1419 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1420 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnRangerMMon1::
# 1421 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Keeping me company are one\n"
# 1422 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "{STR_VAR_1}-using {STR_VAR_2} and$"
# 1423 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1424 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnRangerMMon2Ask::
# 1425 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "one {STR_VAR_2} with {STR_VAR_1}!\p"
# 1426 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Don't you think we'd make an impressive\n"
# 1427 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "tag team?$"
# 1428 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1429 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnRangerMAccept::
# 1430 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "That's super!\n"
# 1431 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I'll deal with the registration now.$"
# 1432 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1433 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnRangerMReject::
# 1434 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Next time, choose my POKéMON,\n"
# 1435 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "will you?$"
# 1436 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1437 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnRangerFIntro::
# 1438 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "My name's {STR_VAR_1}.\n"
# 1439 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I'm a POKéMON RANGER!$"
# 1440 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1441 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnRangerFMon1::
# 1442 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Let me tell you about my team. I have\n"
# 1443 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "one {STR_VAR_2} with {STR_VAR_1} and$"
# 1444 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1445 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnRangerFMon2Ask::
# 1446 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "one {STR_VAR_2} with {STR_VAR_1}!\p"
# 1447 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "How would you like to form a tag team\n"
# 1448 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "with my little posse?$"
# 1449 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1450 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnRangerFAccept::
# 1451 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "We'll be at our best!\n"
# 1452 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I'll get the registration done quick!$"
# 1453 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1454 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnRangerFReject::
# 1455 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I hope you'll choose my POKéMON\n"
# 1456 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "next time.$"
# 1457 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1458 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_AromaLadyIntro::
# 1459 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Pleased to meet you. I'm {STR_VAR_1}.\n"
# 1460 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I consider myself an AROMA LADY.$"
# 1461 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1462 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_AromaLadyMon1::
# 1463 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I travel with one {STR_VAR_2}\n"
# 1464 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "that uses {STR_VAR_1} and$"
# 1465 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1466 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_AromaLadyMon2Ask::
# 1467 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "one {STR_VAR_2} that uses\n"
# 1468 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "{STR_VAR_1}.\p"
# 1469 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I hope they strike your fancy.\n"
# 1470 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Would you care to be my partner?$"
# 1471 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1472 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_AromaLadyAccept::
# 1473 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I'm honored by your acceptance.\n"
# 1474 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I will go register right this instant.$"
# 1475 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1476 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_AromaLadyReject::
# 1477 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "It would be wonderful if we could form\n"
# 1478 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "a tag team the next time we meet.$"
# 1479 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1480 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_RuinManiacIntro::
# 1481 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Want to know who I am?\n"
# 1482 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I'm {STR_VAR_1}, the RUIN MANIAC!$"
# 1483 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1484 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_RuinManiacMon1::
# 1485 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "The POKéMON that I have with me are\n"
# 1486 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "one {STR_VAR_2} with {STR_VAR_1} and$"
# 1487 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1488 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_RuinManiacMon2Ask::
# 1489 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "one {STR_VAR_2} with {STR_VAR_1}!\p"
# 1490 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Intriguing, eh?\n"
# 1491 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "How about you and I partner up?$"
# 1492 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1493 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_RuinManiacAccept::
# 1494 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "That's a sound decision!\n"
# 1495 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I'll go do the registration paperwork.$"
# 1496 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1497 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_RuinManiacReject::
# 1498 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Hmm…\n"
# 1499 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I think my POKéMON are tough…$"
# 1500 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1501 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_CoolTrainerMIntro::
# 1502 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I'm COOLTRAINER {STR_VAR_1}!$"
# 1503 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1504 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_CoolTrainerMMon1::
# 1505 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "The POKéMON I have right now are one\n"
# 1506 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "{STR_VAR_2} with {STR_VAR_1} and$"
# 1507 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1508 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_CoolTrainerMMon2Ask::
# 1509 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "one {STR_VAR_2} with {STR_VAR_1}.\n"
# 1510 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Cool, huh?\p"
# 1511 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Don't you think it'd be pretty cool\n"
# 1512 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "if we made a tag team?$"
# 1513 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1514 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_CoolTrainerMAccept::
# 1515 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Cool!\n"
# 1516 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I'll go do the registration in a flash!$"
# 1517 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1518 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_CoolTrainerMReject::
# 1519 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I thought that we'd make just\n"
# 1520 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "the greatest team ever.$"
# 1521 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1522 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_CoolTrainerFIntro::
# 1523 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I'm COOLTRAINER {STR_VAR_1}!$"
# 1524 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1525 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_CoolTrainerFMon1::
# 1526 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "The team I've been raising has one\n"
# 1527 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "{STR_VAR_2} with {STR_VAR_1} and$"
# 1528 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1529 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_CoolTrainerFMon2Ask::
# 1530 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "one {STR_VAR_2} with {STR_VAR_1}.\p"
# 1531 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Does that sound okay?\n"
# 1532 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "How about we become tag partners?$"
# 1533 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1534 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_CoolTrainerFAccept::
# 1535 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Sounds A-OK!\n"
# 1536 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I'd better do the registration.$"
# 1537 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1538 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_CoolTrainerFReject::
# 1539 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I was thinking how we would be\n"
# 1540 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "one tough team…$"
# 1541 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1542 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokemaniacIntro::
# 1543 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Heyo!\n"
# 1544 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I'm {STR_VAR_1}, the POKéMANIAC!$"
# 1545 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1546 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokemaniacMon1::
# 1547 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "What does a guy like me have?\n"
# 1548 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "One {STR_VAR_2} with {STR_VAR_1} and$"
# 1549 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1550 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokemaniacMon2Ask::
# 1551 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "one {STR_VAR_2} with {STR_VAR_1},\n"
# 1552 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "that's what!\p"
# 1553 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Let's do it!\n"
# 1554 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "We'll stomp around as a tag team!$"
# 1555 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1556 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokemaniacAccept::
# 1557 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Good call!\n"
# 1558 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I'll register the both of us!$"
# 1559 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1560 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokemaniacReject::
# 1561 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "My POKéMON are brutal!\n"
# 1562 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "It's not my fault if you regret this!$"
# 1563 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1564 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_KindlerIntro::
# 1565 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Yo, there!\n"
# 1566 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I'm KINDLER {STR_VAR_1}!$"
# 1567 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1568 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_KindlerMon1::
# 1569 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "You know what my training cooked up?\n"
# 1570 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "One {STR_VAR_2} with {STR_VAR_1} and$"
# 1571 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1572 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_KindlerMon2Ask::
# 1573 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "one {STR_VAR_2} with {STR_VAR_1}!\p"
# 1574 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Well, what do you say?\n"
# 1575 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Want to form a tag team?$"
# 1576 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1577 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_KindlerAccept::
# 1578 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "All right!\n"
# 1579 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I'll get on with the registration.$"
# 1580 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1581 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_KindlerReject::
# 1582 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Promise you'll partner up with me\n"
# 1583 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "the next time we run into each other.$"
# 1584 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1585 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_CamperIntro::
# 1586 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I'm {STR_VAR_1}, and I'm a CAMPER!$"
# 1587 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1588 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_CamperMon1::
# 1589 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I've been raising one {STR_VAR_1}-\n"
# 1590 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "using {STR_VAR_2} and one$"
# 1591 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1592 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_CamperMon2Ask::
# 1593 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "{STR_VAR_1}-using {STR_VAR_2}.\p"
# 1594 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Do you think it'd be fun to team up?\n"
# 1595 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I bet it would be!$"
# 1596 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1597 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_CamperAccept::
# 1598 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Yeah!\n"
# 1599 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Off I go to register!$"
# 1600 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1601 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_CamperReject::
# 1602 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Next time, okay?\n"
# 1603 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I want to be on your team.$"
# 1604 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1605 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_PicnickerIntro::
# 1606 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Hello!\n"
# 1607 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I'm {STR_VAR_1}, and I'm a PICNICKER!$"
# 1608 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1609 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_PicnickerMon1::
# 1610 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "The POKéMON I've been taking are\n"
# 1611 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "one {STR_VAR_2} with {STR_VAR_1} and$"
# 1612 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1613 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_PicnickerMon2Ask::
# 1614 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "one {STR_VAR_2} with {STR_VAR_1}.\p"
# 1615 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Are you interested in joining me\n"
# 1616 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "on a tag team?$"
# 1617 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1618 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_PicnickerAccept::
# 1619 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Why, thank you!\n"
# 1620 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I will do the registration now.$"
# 1621 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1622 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_PicnickerReject::
# 1623 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "It would be nice if I could join you\n"
# 1624 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "some other time.$"
# 1625 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1626 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_PsychicMIntro::
# 1627 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I'm PSYCHIC {STR_VAR_1}!$"
# 1628 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1629 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_PsychicMMon1::
# 1630 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "The twosome I've been raising are\n"
# 1631 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "one {STR_VAR_2} with {STR_VAR_1} and$"
# 1632 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1633 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_PsychicMMon2Ask::
# 1634 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "one {STR_VAR_2} with {STR_VAR_1}.\p"
# 1635 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Would you like to form a tag team\n"
# 1636 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "with me?$"
# 1637 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1638 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_PsychicMAccept::
# 1639 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Sure thing!\n"
# 1640 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I'll take care of the registration!$"
# 1641 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1642 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_PsychicMReject::
# 1643 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "If we meet again, that's when I'd like\n"
# 1644 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "to team up with you.$"
# 1645 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1646 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_PsychicFIntro::
# 1647 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I'm {STR_VAR_1}.\n"
# 1648 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I'm a PSYCHIC.$"
# 1649 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1650 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_PsychicFMon1::
# 1651 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "One {STR_VAR_2} with {STR_VAR_1} and$"
# 1652 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1653 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_PsychicFMon2Ask::
# 1654 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "one {STR_VAR_2} with {STR_VAR_1}--\n"
# 1655 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "they're my disciples.\p"
# 1656 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Doesn't the idea of forming a tag-team\n"
# 1657 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "partnership intrigue you?$"
# 1658 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1659 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_PsychicFAccept::
# 1660 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Thank you.\n"
# 1661 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I'll go deal with the registration.$"
# 1662 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1663 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_PsychicFReject::
# 1664 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I hope there will be another chance\n"
# 1665 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "to forge an alliance.$"
# 1666 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1667 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_SchoolKidFIntro::
# 1668 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I'm SCHOOL KID {STR_VAR_1}!$"
# 1669 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1670 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_SchoolKidFMon1::
# 1671 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "One {STR_VAR_1}-using {STR_VAR_2}$"
# 1672 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1673 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_SchoolKidFMon2Ask::
# 1674 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "and one {STR_VAR_1}-using\n"
# 1675 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "{STR_VAR_2} are my POKéMON pair.\p"
# 1676 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "May I please be your partner on\n"
# 1677 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "a tag team?$"
# 1678 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1679 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_SchoolKidFAccept::
# 1680 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Ooh, thank you!\n"
# 1681 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I'll register at the counter right away!$"
# 1682 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1683 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_SchoolKidFReject::
# 1684 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Please?\n"
# 1685 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "May I join you the next time?$"
# 1686 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1687 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnBreederFIntro::
# 1688 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Hiya! The name's {STR_VAR_1}!\n"
# 1689 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I'm a POKéMON BREEDER!$"
# 1690 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1691 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnBreederFMon1::
# 1692 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "The POKéMON I've raised are one\n"
# 1693 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "{STR_VAR_1}-using {STR_VAR_2} and$"
# 1694 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1695 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnBreederFMon2Ask::
# 1696 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "one {STR_VAR_1}-using {STR_VAR_2}.\p"
# 1697 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Sound interesting?\n"
# 1698 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "How about we form a tag team, then?$"
# 1699 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1700 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnBreederFAccept::
# 1701 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "All righty!\n"
# 1702 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "You leave the registration to me!$"
# 1703 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1704 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnBreederFReject::
# 1705 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "You have to team up with me next time,\n"
# 1706 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "all right?$"
# 1707 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1708 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokefanFIntro::
# 1709 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I'm {STR_VAR_1}, and I'm proud to say\n"
# 1710 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "that I am a POKéFAN.$"
# 1711 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1712 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokefanFMon1::
# 1713 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "The darling POKéMON I've raised are\n"
# 1714 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "one {STR_VAR_2} with {STR_VAR_1} and$"
# 1715 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1716 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokefanFMon2Ask::
# 1717 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "one {STR_VAR_2} with {STR_VAR_1}.\p"
# 1718 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Aren't they just the cutest?\n"
# 1719 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "We ought to make a team!$"
# 1720 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1721 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokefanFAccept::
# 1722 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Thank you, dear!\n"
# 1723 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I'll be on my way to register!$"
# 1724 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1725 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokefanFReject::
# 1726 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "My darling POKéMON are the best,\n"
# 1727 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I'll have you know. How annoying!$"
# 1728 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1729 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmerFIntro::
# 1730 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Hi, I'm SWIMMER {STR_VAR_1}.$"
# 1731 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1732 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmerFMon1::
# 1733 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "One {STR_VAR_1}-using {STR_VAR_2}$"
# 1734 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1735 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmerFMon2Ask::
# 1736 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "and one {STR_VAR_1}-using\n"
# 1737 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "{STR_VAR_2} are what I've trained.\p"
# 1738 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "You and me, let's make a tag team.$"
# 1739 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1740 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmerFAccept::
# 1741 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "That's cool!\n"
# 1742 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I'll register the two of us.$"
# 1743 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1744 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmerFReject::
# 1745 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "If we meet again, you owe me\n"
# 1746 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "a tag team!$"
# 1747 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1748 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmingTriathleteMIntro::
# 1749 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "What's happening?\n"
# 1750 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I'm {STR_VAR_1}, and I'm a TRIATHLETE.$"
# 1751 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1752 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmingTriathleteMMon1::
# 1753 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I got a couple decent POKéMON.\n"
# 1754 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "One {STR_VAR_2} with {STR_VAR_1} and$"
# 1755 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1756 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmingTriathleteMMon2Ask::
# 1757 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "one {STR_VAR_2} with {STR_VAR_1}!\p"
# 1758 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "It'd be neat if we made a tag team\n"
# 1759 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "together, so how about it?$"
# 1760 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1761 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmingTriathleteMAccept::
# 1762 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Right on!\n"
# 1763 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "You wait while I register, okay?$"
# 1764 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1765 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmingTriathleteMReject::
# 1766 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I expect you'll let me join you\n"
# 1767 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "next time, how's that?$"
# 1768 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1769 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmingTriathleteFIntro::
# 1770 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I'm the TRIATHLETE {STR_VAR_1}!$"
# 1771 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1772 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmingTriathleteFMon1::
# 1773 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "One {STR_VAR_2} with {STR_VAR_1} and$"
# 1774 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1775 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmingTriathleteFMon2Ask::
# 1776 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "another {STR_VAR_2} that knows how\n"
# 1777 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "to use {STR_VAR_1}. That's my pair.\p"
# 1778 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "What do you think?\n"
# 1779 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "We'd make a good team, I'd say.$"
# 1780 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1781 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmingTriathleteFAccept::
# 1782 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I like that answer!\n"
# 1783 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I'll get done with registration fast!$"
# 1784 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1785 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmingTriathleteFReject::
# 1786 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "You'll give me another chance to form\n"
# 1787 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "a partnership, won't you?$"
# 1788 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1789 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmerMIntro::
# 1790 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Hi, there! Hello!\n"
# 1791 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I'm {STR_VAR_1}, and I'm a SWIMMER!$"
# 1792 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1793 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmerMMon1::
# 1794 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Check out what I've been raising!\n"
# 1795 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "One {STR_VAR_2} with {STR_VAR_1} and$"
# 1796 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1797 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmerMMon2Ask::
# 1798 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "one {STR_VAR_2} with {STR_VAR_1}!\p"
# 1799 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Sweet, huh?\n"
# 1800 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "It'd be sweet to form a team, too!$"
# 1801 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1802 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmerMAccept::
# 1803 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Much obliged!\n"
# 1804 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I'll get this registration thing done!$"
# 1805 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1806 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmerMReject::
# 1807 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "If we meet again, you have to team up\n"
# 1808 "data//maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "with me. You'll do that, right?$"
