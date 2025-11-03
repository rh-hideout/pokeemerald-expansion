# 1 "data/maps/SafariZone_South/scripts.pory"

# 2 "data/maps/SafariZone_South/scripts.pory"
SafariZone_South_MapScripts::
# 3 "data/maps/SafariZone_South/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, SafariZone_South_OnTransition
# 4 "data/maps/SafariZone_South/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, SafariZone_South_OnFrame
# 5 "data/maps/SafariZone_South/scripts.pory"
	.byte 0
# 6 "data/maps/SafariZone_South/scripts.pory"

# 7 "data/maps/SafariZone_South/scripts.pory"
SafariZone_South_OnFrame:
# 8 "data/maps/SafariZone_South/scripts.pory"
	map_script_2 VAR_SAFARI_ZONE_STATE, 2, SafariZone_South_EventScript_EnterSafariZone
# 9 "data/maps/SafariZone_South/scripts.pory"
	.2byte 0
# 10 "data/maps/SafariZone_South/scripts.pory"

# 11 "data/maps/SafariZone_South/scripts.pory"
SafariZone_South_EventScript_EnterSafariZone::
# 12 "data/maps/SafariZone_South/scripts.pory"
	lockall
# 13 "data/maps/SafariZone_South/scripts.pory"
	applymovement LOCALID_PLAYER, SafariZone_South_Movement_PlayerEnter
# 14 "data/maps/SafariZone_South/scripts.pory"
	waitmovement 0
# 15 "data/maps/SafariZone_South/scripts.pory"
	applymovement LOCALID_SAFARI_EXIT_ATTENDANT, SafariZone_South_Movement_ExitAttendantBlockDoor
# 16 "data/maps/SafariZone_South/scripts.pory"
	waitmovement 0
# 17 "data/maps/SafariZone_South/scripts.pory"
	setobjectxyperm LOCALID_SAFARI_EXIT_ATTENDANT, 32, 34
# 18 "data/maps/SafariZone_South/scripts.pory"
	setvar VAR_SAFARI_ZONE_STATE, 0
# 19 "data/maps/SafariZone_South/scripts.pory"
	releaseall
# 20 "data/maps/SafariZone_South/scripts.pory"
	end
# 21 "data/maps/SafariZone_South/scripts.pory"

# 22 "data/maps/SafariZone_South/scripts.pory"
SafariZone_South_OnTransition:
# 23 "data/maps/SafariZone_South/scripts.pory"
	call_if_eq VAR_SAFARI_ZONE_STATE, 2, SafariZone_South_EventScript_SetExitAttendantAside
# 24 "data/maps/SafariZone_South/scripts.pory"
	end
# 25 "data/maps/SafariZone_South/scripts.pory"

# 26 "data/maps/SafariZone_South/scripts.pory"
SafariZone_South_EventScript_SetExitAttendantAside::
# 27 "data/maps/SafariZone_South/scripts.pory"
	setobjectxyperm LOCALID_SAFARI_EXIT_ATTENDANT, 31, 34
# 28 "data/maps/SafariZone_South/scripts.pory"
	return
# 29 "data/maps/SafariZone_South/scripts.pory"

# 30 "data/maps/SafariZone_South/scripts.pory"
SafariZone_South_Movement_PlayerEnter:
# 31 "data/maps/SafariZone_South/scripts.pory"
	walk_down
# 32 "data/maps/SafariZone_South/scripts.pory"
	step_end
# 33 "data/maps/SafariZone_South/scripts.pory"

# 34 "data/maps/SafariZone_South/scripts.pory"
SafariZone_South_Movement_ExitAttendantBlockDoor:
# 35 "data/maps/SafariZone_South/scripts.pory"
	walk_right
# 36 "data/maps/SafariZone_South/scripts.pory"
	walk_in_place_faster_down
# 37 "data/maps/SafariZone_South/scripts.pory"
	step_end
# 38 "data/maps/SafariZone_South/scripts.pory"

# 39 "data/maps/SafariZone_South/scripts.pory"
SafariZone_South_EventScript_Boy::
# 40 "data/maps/SafariZone_South/scripts.pory"
	msgbox SafariZone_South_Text_Boy, MSGBOX_NPC
# 41 "data/maps/SafariZone_South/scripts.pory"
	end
# 42 "data/maps/SafariZone_South/scripts.pory"

# 43 "data/maps/SafariZone_South/scripts.pory"
SafariZone_South_EventScript_Man::
# 44 "data/maps/SafariZone_South/scripts.pory"
	msgbox SafariZone_South_Text_Man, MSGBOX_NPC
# 45 "data/maps/SafariZone_South/scripts.pory"
	end
# 46 "data/maps/SafariZone_South/scripts.pory"

# 47 "data/maps/SafariZone_South/scripts.pory"
SafariZone_South_EventScript_Youngster::
# 48 "data/maps/SafariZone_South/scripts.pory"
	msgbox SafariZone_South_Text_Youngster, MSGBOX_NPC
# 49 "data/maps/SafariZone_South/scripts.pory"
	end
# 50 "data/maps/SafariZone_South/scripts.pory"

# 51 "data/maps/SafariZone_South/scripts.pory"
SafariZone_South_EventScript_ExitAttendant::
# 52 "data/maps/SafariZone_South/scripts.pory"
	lock
# 53 "data/maps/SafariZone_South/scripts.pory"
	faceplayer
# 54 "data/maps/SafariZone_South/scripts.pory"
	goto_if_unset FLAG_GOOD_LUCK_SAFARI_ZONE, SafariZone_South_EventScript_GoodLuck
# 55 "data/maps/SafariZone_South/scripts.pory"
	msgbox SafariZone_South_Text_StillHaveTimeExit, MSGBOX_YESNO
# 56 "data/maps/SafariZone_South/scripts.pory"
	goto_if_eq VAR_RESULT, YES, SafariZone_South_EventScript_ExitEarly
# 57 "data/maps/SafariZone_South/scripts.pory"
	msgbox SafariZone_South_Text_EnjoyTheRestOfYourAdventure, MSGBOX_DEFAULT
# 58 "data/maps/SafariZone_South/scripts.pory"
	release
# 59 "data/maps/SafariZone_South/scripts.pory"
	end
# 60 "data/maps/SafariZone_South/scripts.pory"

# 61 "data/maps/SafariZone_South/scripts.pory"
SafariZone_South_EventScript_GoodLuck::
# 62 "data/maps/SafariZone_South/scripts.pory"
	setflag FLAG_GOOD_LUCK_SAFARI_ZONE
# 63 "data/maps/SafariZone_South/scripts.pory"
	msgbox SafariZone_South_Text_GoodLuck, MSGBOX_DEFAULT
# 64 "data/maps/SafariZone_South/scripts.pory"
	release
# 65 "data/maps/SafariZone_South/scripts.pory"
	end
# 66 "data/maps/SafariZone_South/scripts.pory"

# 67 "data/maps/SafariZone_South/scripts.pory"
SafariZone_South_EventScript_ExitEarly::
# 68 "data/maps/SafariZone_South/scripts.pory"
	msgbox SafariZone_South_Text_ExitEarlyThankYouForPlaying, MSGBOX_DEFAULT
# 69 "data/maps/SafariZone_South/scripts.pory"
	closemessage
# 70 "data/maps/SafariZone_South/scripts.pory"
	switch VAR_FACING
# 71 "data/maps/SafariZone_South/scripts.pory"
	case DIR_NORTH, SafariZone_South_EventScript_ExitEarlyNorth
# 72 "data/maps/SafariZone_South/scripts.pory"
	case DIR_EAST, SafariZone_South_EventScript_ExitEarlyEast
# 73 "data/maps/SafariZone_South/scripts.pory"
	end
# 74 "data/maps/SafariZone_South/scripts.pory"

# 75 "data/maps/SafariZone_South/scripts.pory"
SafariZone_South_EventScript_ExitEarlyNorth::
# 76 "data/maps/SafariZone_South/scripts.pory"
	applymovement LOCALID_SAFARI_EXIT_ATTENDANT, SafariZone_South_Movement_MoveExitAttendantNorth
# 77 "data/maps/SafariZone_South/scripts.pory"
	waitmovement 0
# 78 "data/maps/SafariZone_South/scripts.pory"
	applymovement LOCALID_PLAYER, SafariZone_South_Movement_PlayerExitNorth
# 79 "data/maps/SafariZone_South/scripts.pory"
	waitmovement 0
# 80 "data/maps/SafariZone_South/scripts.pory"
	goto SafariZone_South_EventScript_Exit
# 81 "data/maps/SafariZone_South/scripts.pory"
	end
# 82 "data/maps/SafariZone_South/scripts.pory"

# 83 "data/maps/SafariZone_South/scripts.pory"
SafariZone_South_EventScript_ExitEarlyEast::
# 84 "data/maps/SafariZone_South/scripts.pory"
	applymovement LOCALID_SAFARI_EXIT_ATTENDANT, SafariZone_South_Movement_MoveExitAttendantEast
# 85 "data/maps/SafariZone_South/scripts.pory"
	waitmovement 0
# 86 "data/maps/SafariZone_South/scripts.pory"
	applymovement LOCALID_PLAYER, SafariZone_South_Movement_PlayerExitEast
# 87 "data/maps/SafariZone_South/scripts.pory"
	waitmovement 0
# 88 "data/maps/SafariZone_South/scripts.pory"
	goto SafariZone_South_EventScript_Exit
# 89 "data/maps/SafariZone_South/scripts.pory"
	end
# 90 "data/maps/SafariZone_South/scripts.pory"

# 91 "data/maps/SafariZone_South/scripts.pory"
SafariZone_South_EventScript_Exit::
# 92 "data/maps/SafariZone_South/scripts.pory"
	setvar VAR_SAFARI_ZONE_STATE, 1
# 93 "data/maps/SafariZone_South/scripts.pory"
	special ExitSafariMode
# 94 "data/maps/SafariZone_South/scripts.pory"
	warpdoor MAP_ROUTE121_SAFARI_ZONE_ENTRANCE, 2, 5
# 95 "data/maps/SafariZone_South/scripts.pory"
	waitstate
# 96 "data/maps/SafariZone_South/scripts.pory"
	end
# 97 "data/maps/SafariZone_South/scripts.pory"

# 98 "data/maps/SafariZone_South/scripts.pory"
SafariZone_South_Movement_PlayerExitNorth:
# 99 "data/maps/SafariZone_South/scripts.pory"
	walk_up
# 100 "data/maps/SafariZone_South/scripts.pory"
	step_end
# 101 "data/maps/SafariZone_South/scripts.pory"

# 102 "data/maps/SafariZone_South/scripts.pory"
SafariZone_South_Movement_PlayerExitEast:
# 103 "data/maps/SafariZone_South/scripts.pory"
	walk_right
# 104 "data/maps/SafariZone_South/scripts.pory"
	walk_in_place_faster_up
# 105 "data/maps/SafariZone_South/scripts.pory"
	step_end
# 106 "data/maps/SafariZone_South/scripts.pory"

# 107 "data/maps/SafariZone_South/scripts.pory"
SafariZone_South_Movement_MoveExitAttendantNorth:
# 108 "data/maps/SafariZone_South/scripts.pory"
	walk_left
# 109 "data/maps/SafariZone_South/scripts.pory"
	walk_in_place_faster_right
# 110 "data/maps/SafariZone_South/scripts.pory"
	step_end
# 111 "data/maps/SafariZone_South/scripts.pory"

# 112 "data/maps/SafariZone_South/scripts.pory"
SafariZone_South_Movement_MoveExitAttendantEast:
# 113 "data/maps/SafariZone_South/scripts.pory"
	walk_down
# 114 "data/maps/SafariZone_South/scripts.pory"
	walk_in_place_faster_up
# 115 "data/maps/SafariZone_South/scripts.pory"
	step_end
# 116 "data/maps/SafariZone_South/scripts.pory"

# 117 "data/maps/SafariZone_South/scripts.pory"
SafariZone_South_EventScript_ConstructionWorker1::
# 118 "data/maps/SafariZone_South/scripts.pory"
	msgbox SafariZone_South_Text_AreaOffLimits1, MSGBOX_NPC
# 119 "data/maps/SafariZone_South/scripts.pory"
	end
# 120 "data/maps/SafariZone_South/scripts.pory"

# 121 "data/maps/SafariZone_South/scripts.pory"
SafariZone_Southeast_EventScript_ExpansionZoneAttendant::
# 122 "data/maps/SafariZone_South/scripts.pory"
	msgbox SafariZone_Southeast_Text_ExpansionIsFinished, MSGBOX_NPC
# 123 "data/maps/SafariZone_South/scripts.pory"
	end
# 124 "data/maps/SafariZone_South/scripts.pory"

# 125 "data/maps/SafariZone_South/scripts.pory"
SafariZone_South_EventScript_ConstructionWorker2::
# 126 "data/maps/SafariZone_South/scripts.pory"
	msgbox SafariZone_South_Text_AreaOffLimits2, MSGBOX_NPC
# 127 "data/maps/SafariZone_South/scripts.pory"
	end
# 128 "data/maps/SafariZone_South/scripts.pory"

# 129 "data/maps/SafariZone_South/scripts.pory"
SafariZone_Southeast_EventScript_LittleGirl::
# 130 "data/maps/SafariZone_South/scripts.pory"
	msgbox SafariZone_Southeast_Text_LittleGirl, MSGBOX_NPC
# 131 "data/maps/SafariZone_South/scripts.pory"
	end
# 132 "data/maps/SafariZone_South/scripts.pory"

# 133 "data/maps/SafariZone_South/scripts.pory"
SafariZone_Southeast_EventScript_FatMan::
# 134 "data/maps/SafariZone_South/scripts.pory"
	msgbox SafariZone_Southeast_Text_FatMan, MSGBOX_NPC
# 135 "data/maps/SafariZone_South/scripts.pory"
	end
# 136 "data/maps/SafariZone_South/scripts.pory"

# 137 "data/maps/SafariZone_South/scripts.pory"
SafariZone_Southeast_EventScript_RichBoy::
# 138 "data/maps/SafariZone_South/scripts.pory"
	msgbox SafariZone_Southeast_Text_RichBoy, MSGBOX_NPC
# 139 "data/maps/SafariZone_South/scripts.pory"
	end
# 140 "data/maps/SafariZone_South/scripts.pory"

# 141 "data/maps/SafariZone_South/scripts.pory"
SafariZone_Northeast_EventScript_Boy::
# 142 "data/maps/SafariZone_South/scripts.pory"
	msgbox SafariZone_Northeast_Text_Boy, MSGBOX_NPC
# 143 "data/maps/SafariZone_South/scripts.pory"
	end
# 144 "data/maps/SafariZone_South/scripts.pory"

# 145 "data/maps/SafariZone_South/scripts.pory"
SafariZone_Northeast_EventScript_Woman::
# 146 "data/maps/SafariZone_South/scripts.pory"
	msgbox SafariZone_Northeast_Text_Woman, MSGBOX_NPC
# 147 "data/maps/SafariZone_South/scripts.pory"
	end
# 148 "data/maps/SafariZone_South/scripts.pory"

# 149 "data/maps/SafariZone_South/scripts.pory"
SafariZone_Northeast_EventScript_Girl::
# 150 "data/maps/SafariZone_South/scripts.pory"
	msgbox SafariZone_Northeast_Text_Girl, MSGBOX_NPC
# 151 "data/maps/SafariZone_South/scripts.pory"
	end
