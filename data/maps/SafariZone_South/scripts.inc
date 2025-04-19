# 1 "data/maps/SafariZone_South/scripts.pory"

# 2 "data/maps/SafariZone_South/scripts.pory"
.set LOCALID_ATTENDANT, 1
# 3 "data/maps/SafariZone_South/scripts.pory"

# 4 "data/maps/SafariZone_South/scripts.pory"
SafariZone_South_MapScripts::
# 5 "data/maps/SafariZone_South/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, SafariZone_South_OnTransition
# 6 "data/maps/SafariZone_South/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, SafariZone_South_OnFrame
# 7 "data/maps/SafariZone_South/scripts.pory"
	.byte 0
# 8 "data/maps/SafariZone_South/scripts.pory"

# 9 "data/maps/SafariZone_South/scripts.pory"
SafariZone_South_OnFrame:
# 10 "data/maps/SafariZone_South/scripts.pory"
	map_script_2 VAR_SAFARI_ZONE_STATE, 2, SafariZone_South_EventScript_EnterSafariZone
# 11 "data/maps/SafariZone_South/scripts.pory"
	.2byte 0
# 12 "data/maps/SafariZone_South/scripts.pory"

# 13 "data/maps/SafariZone_South/scripts.pory"
SafariZone_South_EventScript_EnterSafariZone::
# 14 "data/maps/SafariZone_South/scripts.pory"
	lockall
# 15 "data/maps/SafariZone_South/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, SafariZone_South_Movement_PlayerEnter
# 16 "data/maps/SafariZone_South/scripts.pory"
	waitmovement 0
# 17 "data/maps/SafariZone_South/scripts.pory"
	applymovement LOCALID_ATTENDANT, SafariZone_South_Movement_ExitAttendantBlockDoor
# 18 "data/maps/SafariZone_South/scripts.pory"
	waitmovement 0
# 19 "data/maps/SafariZone_South/scripts.pory"
	setobjectxyperm LOCALID_ATTENDANT, 32, 34
# 20 "data/maps/SafariZone_South/scripts.pory"
	setvar VAR_SAFARI_ZONE_STATE, 0
# 21 "data/maps/SafariZone_South/scripts.pory"
	releaseall
# 22 "data/maps/SafariZone_South/scripts.pory"
	end
# 23 "data/maps/SafariZone_South/scripts.pory"

# 24 "data/maps/SafariZone_South/scripts.pory"
SafariZone_South_OnTransition:
# 25 "data/maps/SafariZone_South/scripts.pory"
	call_if_eq VAR_SAFARI_ZONE_STATE, 2, SafariZone_South_EventScript_SetExitAttendantAside
# 26 "data/maps/SafariZone_South/scripts.pory"
	end
# 27 "data/maps/SafariZone_South/scripts.pory"

# 28 "data/maps/SafariZone_South/scripts.pory"
SafariZone_South_EventScript_SetExitAttendantAside::
# 29 "data/maps/SafariZone_South/scripts.pory"
	setobjectxyperm LOCALID_ATTENDANT, 31, 34
# 30 "data/maps/SafariZone_South/scripts.pory"
	return
# 31 "data/maps/SafariZone_South/scripts.pory"

# 32 "data/maps/SafariZone_South/scripts.pory"
SafariZone_South_Movement_PlayerEnter:
# 33 "data/maps/SafariZone_South/scripts.pory"
	walk_down
# 34 "data/maps/SafariZone_South/scripts.pory"
	step_end
# 35 "data/maps/SafariZone_South/scripts.pory"

# 36 "data/maps/SafariZone_South/scripts.pory"
SafariZone_South_Movement_ExitAttendantBlockDoor:
# 37 "data/maps/SafariZone_South/scripts.pory"
	walk_right
# 38 "data/maps/SafariZone_South/scripts.pory"
	walk_in_place_faster_down
# 39 "data/maps/SafariZone_South/scripts.pory"
	step_end
# 40 "data/maps/SafariZone_South/scripts.pory"

# 41 "data/maps/SafariZone_South/scripts.pory"
SafariZone_South_EventScript_Boy::
# 42 "data/maps/SafariZone_South/scripts.pory"
	msgbox SafariZone_South_Text_Boy, MSGBOX_NPC
# 43 "data/maps/SafariZone_South/scripts.pory"
	end
# 44 "data/maps/SafariZone_South/scripts.pory"

# 45 "data/maps/SafariZone_South/scripts.pory"
SafariZone_South_EventScript_Man::
# 46 "data/maps/SafariZone_South/scripts.pory"
	msgbox SafariZone_South_Text_Man, MSGBOX_NPC
# 47 "data/maps/SafariZone_South/scripts.pory"
	end
# 48 "data/maps/SafariZone_South/scripts.pory"

# 49 "data/maps/SafariZone_South/scripts.pory"
SafariZone_South_EventScript_Youngster::
# 50 "data/maps/SafariZone_South/scripts.pory"
	msgbox SafariZone_South_Text_Youngster, MSGBOX_NPC
# 51 "data/maps/SafariZone_South/scripts.pory"
	end
# 52 "data/maps/SafariZone_South/scripts.pory"

# 53 "data/maps/SafariZone_South/scripts.pory"
SafariZone_South_EventScript_ExitAttendant::
# 54 "data/maps/SafariZone_South/scripts.pory"
	lock
# 55 "data/maps/SafariZone_South/scripts.pory"
	faceplayer
# 56 "data/maps/SafariZone_South/scripts.pory"
	goto_if_unset FLAG_GOOD_LUCK_SAFARI_ZONE, SafariZone_South_EventScript_GoodLuck
# 57 "data/maps/SafariZone_South/scripts.pory"
	msgbox SafariZone_South_Text_StillHaveTimeExit, MSGBOX_YESNO
# 58 "data/maps/SafariZone_South/scripts.pory"
	goto_if_eq VAR_RESULT, YES, SafariZone_South_EventScript_ExitEarly
# 59 "data/maps/SafariZone_South/scripts.pory"
	msgbox SafariZone_South_Text_EnjoyTheRestOfYourAdventure, MSGBOX_DEFAULT
# 60 "data/maps/SafariZone_South/scripts.pory"
	release
# 61 "data/maps/SafariZone_South/scripts.pory"
	end
# 62 "data/maps/SafariZone_South/scripts.pory"

# 63 "data/maps/SafariZone_South/scripts.pory"
SafariZone_South_EventScript_GoodLuck::
# 64 "data/maps/SafariZone_South/scripts.pory"
	setflag FLAG_GOOD_LUCK_SAFARI_ZONE
# 65 "data/maps/SafariZone_South/scripts.pory"
	msgbox SafariZone_South_Text_GoodLuck, MSGBOX_DEFAULT
# 66 "data/maps/SafariZone_South/scripts.pory"
	release
# 67 "data/maps/SafariZone_South/scripts.pory"
	end
# 68 "data/maps/SafariZone_South/scripts.pory"

# 69 "data/maps/SafariZone_South/scripts.pory"
SafariZone_South_EventScript_ExitEarly::
# 70 "data/maps/SafariZone_South/scripts.pory"
	msgbox SafariZone_South_Text_ExitEarlyThankYouForPlaying, MSGBOX_DEFAULT
# 71 "data/maps/SafariZone_South/scripts.pory"
	closemessage
# 72 "data/maps/SafariZone_South/scripts.pory"
	switch VAR_FACING
# 73 "data/maps/SafariZone_South/scripts.pory"
	case DIR_NORTH, SafariZone_South_EventScript_ExitEarlyNorth
# 74 "data/maps/SafariZone_South/scripts.pory"
	case DIR_EAST, SafariZone_South_EventScript_ExitEarlyEast
# 75 "data/maps/SafariZone_South/scripts.pory"
	end
# 76 "data/maps/SafariZone_South/scripts.pory"

# 77 "data/maps/SafariZone_South/scripts.pory"
SafariZone_South_EventScript_ExitEarlyNorth::
# 78 "data/maps/SafariZone_South/scripts.pory"
	applymovement LOCALID_ATTENDANT, SafariZone_South_Movement_MoveExitAttendantNorth
# 79 "data/maps/SafariZone_South/scripts.pory"
	waitmovement 0
# 80 "data/maps/SafariZone_South/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, SafariZone_South_Movement_PlayerExitNorth
# 81 "data/maps/SafariZone_South/scripts.pory"
	waitmovement 0
# 82 "data/maps/SafariZone_South/scripts.pory"
	goto SafariZone_South_EventScript_Exit
# 83 "data/maps/SafariZone_South/scripts.pory"
	end
# 84 "data/maps/SafariZone_South/scripts.pory"

# 85 "data/maps/SafariZone_South/scripts.pory"
SafariZone_South_EventScript_ExitEarlyEast::
# 86 "data/maps/SafariZone_South/scripts.pory"
	applymovement LOCALID_ATTENDANT, SafariZone_South_Movement_MoveExitAttendantEast
# 87 "data/maps/SafariZone_South/scripts.pory"
	waitmovement 0
# 88 "data/maps/SafariZone_South/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, SafariZone_South_Movement_PlayerExitEast
# 89 "data/maps/SafariZone_South/scripts.pory"
	waitmovement 0
# 90 "data/maps/SafariZone_South/scripts.pory"
	goto SafariZone_South_EventScript_Exit
# 91 "data/maps/SafariZone_South/scripts.pory"
	end
# 92 "data/maps/SafariZone_South/scripts.pory"

# 93 "data/maps/SafariZone_South/scripts.pory"
SafariZone_South_EventScript_Exit::
# 94 "data/maps/SafariZone_South/scripts.pory"
	setvar VAR_SAFARI_ZONE_STATE, 1
# 95 "data/maps/SafariZone_South/scripts.pory"
	special ExitSafariMode
# 96 "data/maps/SafariZone_South/scripts.pory"
	warpdoor MAP_ROUTE121_SAFARI_ZONE_ENTRANCE, 2, 5
# 97 "data/maps/SafariZone_South/scripts.pory"
	waitstate
# 98 "data/maps/SafariZone_South/scripts.pory"
	end
# 99 "data/maps/SafariZone_South/scripts.pory"

# 100 "data/maps/SafariZone_South/scripts.pory"
SafariZone_South_Movement_PlayerExitNorth:
# 101 "data/maps/SafariZone_South/scripts.pory"
	walk_up
# 102 "data/maps/SafariZone_South/scripts.pory"
	step_end
# 103 "data/maps/SafariZone_South/scripts.pory"

# 104 "data/maps/SafariZone_South/scripts.pory"
SafariZone_South_Movement_PlayerExitEast:
# 105 "data/maps/SafariZone_South/scripts.pory"
	walk_right
# 106 "data/maps/SafariZone_South/scripts.pory"
	walk_in_place_faster_up
# 107 "data/maps/SafariZone_South/scripts.pory"
	step_end
# 108 "data/maps/SafariZone_South/scripts.pory"

# 109 "data/maps/SafariZone_South/scripts.pory"
SafariZone_South_Movement_MoveExitAttendantNorth:
# 110 "data/maps/SafariZone_South/scripts.pory"
	walk_left
# 111 "data/maps/SafariZone_South/scripts.pory"
	walk_in_place_faster_right
# 112 "data/maps/SafariZone_South/scripts.pory"
	step_end
# 113 "data/maps/SafariZone_South/scripts.pory"

# 114 "data/maps/SafariZone_South/scripts.pory"
SafariZone_South_Movement_MoveExitAttendantEast:
# 115 "data/maps/SafariZone_South/scripts.pory"
	walk_down
# 116 "data/maps/SafariZone_South/scripts.pory"
	walk_in_place_faster_up
# 117 "data/maps/SafariZone_South/scripts.pory"
	step_end
# 118 "data/maps/SafariZone_South/scripts.pory"

# 119 "data/maps/SafariZone_South/scripts.pory"
SafariZone_South_EventScript_ConstructionWorker1::
# 120 "data/maps/SafariZone_South/scripts.pory"
	msgbox SafariZone_South_Text_AreaOffLimits1, MSGBOX_NPC
# 121 "data/maps/SafariZone_South/scripts.pory"
	end
# 122 "data/maps/SafariZone_South/scripts.pory"

# 123 "data/maps/SafariZone_South/scripts.pory"
SafariZone_Southeast_EventScript_ExpansionZoneAttendant::
# 124 "data/maps/SafariZone_South/scripts.pory"
	msgbox SafariZone_Southeast_Text_ExpansionIsFinished, MSGBOX_NPC
# 125 "data/maps/SafariZone_South/scripts.pory"
	end
# 126 "data/maps/SafariZone_South/scripts.pory"

# 127 "data/maps/SafariZone_South/scripts.pory"
SafariZone_South_EventScript_ConstructionWorker2::
# 128 "data/maps/SafariZone_South/scripts.pory"
	msgbox SafariZone_South_Text_AreaOffLimits2, MSGBOX_NPC
# 129 "data/maps/SafariZone_South/scripts.pory"
	end
# 130 "data/maps/SafariZone_South/scripts.pory"

# 131 "data/maps/SafariZone_South/scripts.pory"
SafariZone_Southeast_EventScript_LittleGirl::
# 132 "data/maps/SafariZone_South/scripts.pory"
	msgbox SafariZone_Southeast_Text_LittleGirl, MSGBOX_NPC
# 133 "data/maps/SafariZone_South/scripts.pory"
	end
# 134 "data/maps/SafariZone_South/scripts.pory"

# 135 "data/maps/SafariZone_South/scripts.pory"
SafariZone_Southeast_EventScript_FatMan::
# 136 "data/maps/SafariZone_South/scripts.pory"
	msgbox SafariZone_Southeast_Text_FatMan, MSGBOX_NPC
# 137 "data/maps/SafariZone_South/scripts.pory"
	end
# 138 "data/maps/SafariZone_South/scripts.pory"

# 139 "data/maps/SafariZone_South/scripts.pory"
SafariZone_Southeast_EventScript_RichBoy::
# 140 "data/maps/SafariZone_South/scripts.pory"
	msgbox SafariZone_Southeast_Text_RichBoy, MSGBOX_NPC
# 141 "data/maps/SafariZone_South/scripts.pory"
	end
# 142 "data/maps/SafariZone_South/scripts.pory"

# 143 "data/maps/SafariZone_South/scripts.pory"
SafariZone_Northeast_EventScript_Boy::
# 144 "data/maps/SafariZone_South/scripts.pory"
	msgbox SafariZone_Northeast_Text_Boy, MSGBOX_NPC
# 145 "data/maps/SafariZone_South/scripts.pory"
	end
# 146 "data/maps/SafariZone_South/scripts.pory"

# 147 "data/maps/SafariZone_South/scripts.pory"
SafariZone_Northeast_EventScript_Woman::
# 148 "data/maps/SafariZone_South/scripts.pory"
	msgbox SafariZone_Northeast_Text_Woman, MSGBOX_NPC
# 149 "data/maps/SafariZone_South/scripts.pory"
	end
# 150 "data/maps/SafariZone_South/scripts.pory"

# 151 "data/maps/SafariZone_South/scripts.pory"
SafariZone_Northeast_EventScript_Girl::
# 152 "data/maps/SafariZone_South/scripts.pory"
	msgbox SafariZone_Northeast_Text_Girl, MSGBOX_NPC
# 153 "data/maps/SafariZone_South/scripts.pory"
	end
