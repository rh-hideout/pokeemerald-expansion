# 1 "data/maps/NavelRock_Top/scripts.pory"

# 2 "data/maps/NavelRock_Top/scripts.pory"
.set LOCALID_HO_OH, 1
# 3 "data/maps/NavelRock_Top/scripts.pory"

# 4 "data/maps/NavelRock_Top/scripts.pory"
NavelRock_Top_MapScripts::
# 5 "data/maps/NavelRock_Top/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, NavelRock_Top_OnTransition
# 6 "data/maps/NavelRock_Top/scripts.pory"
	map_script MAP_SCRIPT_ON_RESUME, NavelRock_Top_OnResume
# 7 "data/maps/NavelRock_Top/scripts.pory"
	.byte 0
# 8 "data/maps/NavelRock_Top/scripts.pory"

# 9 "data/maps/NavelRock_Top/scripts.pory"
NavelRock_Top_OnTransition:
# 10 "data/maps/NavelRock_Top/scripts.pory"
	call_if_set FLAG_CAUGHT_HO_OH, NavelRock_Top_EventScript_HideHoOh
# 11 "data/maps/NavelRock_Top/scripts.pory"
	call_if_unset FLAG_CAUGHT_HO_OH, NavelRock_Top_EventScript_TryShowHoOh
# 12 "data/maps/NavelRock_Top/scripts.pory"
	end
# 13 "data/maps/NavelRock_Top/scripts.pory"

# 14 "data/maps/NavelRock_Top/scripts.pory"
NavelRock_Top_EventScript_HideHoOh::
# 15 "data/maps/NavelRock_Top/scripts.pory"
	setvar VAR_TEMP_1, 1
# 16 "data/maps/NavelRock_Top/scripts.pory"
	setflag FLAG_HIDE_HO_OH
# 17 "data/maps/NavelRock_Top/scripts.pory"
	return
# 18 "data/maps/NavelRock_Top/scripts.pory"

# 19 "data/maps/NavelRock_Top/scripts.pory"
NavelRock_Top_EventScript_TryShowHoOh::
# 20 "data/maps/NavelRock_Top/scripts.pory"
	setvar VAR_TEMP_1, 1
# 21 "data/maps/NavelRock_Top/scripts.pory"
	goto_if_set FLAG_DEFEATED_HO_OH, Common_EventScript_NopReturn
# 22 "data/maps/NavelRock_Top/scripts.pory"
	setvar VAR_TEMP_1, 0
# 23 "data/maps/NavelRock_Top/scripts.pory"
	clearflag FLAG_HIDE_HO_OH
# 24 "data/maps/NavelRock_Top/scripts.pory"
	return
# 25 "data/maps/NavelRock_Top/scripts.pory"

# 26 "data/maps/NavelRock_Top/scripts.pory"
NavelRock_Top_OnResume:
# 27 "data/maps/NavelRock_Top/scripts.pory"
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, NavelRock_Top_EventScript_TryRemoveHoOh
# 28 "data/maps/NavelRock_Top/scripts.pory"
	end
# 29 "data/maps/NavelRock_Top/scripts.pory"

# 30 "data/maps/NavelRock_Top/scripts.pory"
NavelRock_Top_EventScript_TryRemoveHoOh::
# 31 "data/maps/NavelRock_Top/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 32 "data/maps/NavelRock_Top/scripts.pory"
	goto_if_ne VAR_RESULT, B_OUTCOME_CAUGHT, Common_EventScript_NopReturn
# 33 "data/maps/NavelRock_Top/scripts.pory"
	removeobject LOCALID_HO_OH
# 34 "data/maps/NavelRock_Top/scripts.pory"
	return
# 35 "data/maps/NavelRock_Top/scripts.pory"

# 36 "data/maps/NavelRock_Top/scripts.pory"
NavelRock_Top_EventScript_HoOh::
# 37 "data/maps/NavelRock_Top/scripts.pory"
	lockall
# 38 "data/maps/NavelRock_Top/scripts.pory"
	setvar VAR_TEMP_1, 1
# 39 "data/maps/NavelRock_Top/scripts.pory"
	special SpawnCameraObject
# 40 "data/maps/NavelRock_Top/scripts.pory"
	setvar VAR_0x8004, 3  @ num loops
# 41 "data/maps/NavelRock_Top/scripts.pory"
	setvar VAR_0x8005, 35 @ delay
# 42 "data/maps/NavelRock_Top/scripts.pory"
	special LoopWingFlapSE
# 43 "data/maps/NavelRock_Top/scripts.pory"
	applymovement LOCALID_HO_OH, NavelRock_Top_Movement_HoOhAppear
# 44 "data/maps/NavelRock_Top/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, NavelRock_Top_Movement_CameraPanUp
# 45 "data/maps/NavelRock_Top/scripts.pory"
	waitmovement 0
# 46 "data/maps/NavelRock_Top/scripts.pory"
	delay 50
# 47 "data/maps/NavelRock_Top/scripts.pory"
	setweather WEATHER_NONE
# 48 "data/maps/NavelRock_Top/scripts.pory"
	doweather
# 49 "data/maps/NavelRock_Top/scripts.pory"
	waitse
# 50 "data/maps/NavelRock_Top/scripts.pory"
	playmoncry SPECIES_HO_OH, CRY_MODE_ENCOUNTER
# 51 "data/maps/NavelRock_Top/scripts.pory"
	delay 30
# 52 "data/maps/NavelRock_Top/scripts.pory"
	waitmoncry
# 53 "data/maps/NavelRock_Top/scripts.pory"
	delay 60
# 54 "data/maps/NavelRock_Top/scripts.pory"
	setvar VAR_0x8004, 3  @ num loops
# 55 "data/maps/NavelRock_Top/scripts.pory"
	setvar VAR_0x8005, 35 @ delay
# 56 "data/maps/NavelRock_Top/scripts.pory"
	special LoopWingFlapSE
# 57 "data/maps/NavelRock_Top/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, NavelRock_Top_Movement_CameraPanDown
# 58 "data/maps/NavelRock_Top/scripts.pory"
	applymovement LOCALID_HO_OH, NavelRock_Top_Movement_HoOhApproach
# 59 "data/maps/NavelRock_Top/scripts.pory"
	waitmovement 0
# 60 "data/maps/NavelRock_Top/scripts.pory"
	special RemoveCameraObject
# 61 "data/maps/NavelRock_Top/scripts.pory"
	seteventmon SPECIES_HO_OH, 70
# 62 "data/maps/NavelRock_Top/scripts.pory"
	setflag FLAG_SYS_CTRL_OBJ_DELETE
# 63 "data/maps/NavelRock_Top/scripts.pory"
	special BattleSetup_StartLegendaryBattle
# 64 "data/maps/NavelRock_Top/scripts.pory"
	waitstate
# 65 "data/maps/NavelRock_Top/scripts.pory"
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
# 66 "data/maps/NavelRock_Top/scripts.pory"
	setvar VAR_LAST_TALKED, LOCALID_HO_OH
# 67 "data/maps/NavelRock_Top/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 68 "data/maps/NavelRock_Top/scripts.pory"
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, NavelRock_Top_EventScript_DefeatedHoOh
# 69 "data/maps/NavelRock_Top/scripts.pory"
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, NavelRock_Top_EventScript_RanFromHoOh
# 70 "data/maps/NavelRock_Top/scripts.pory"
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, NavelRock_Top_EventScript_RanFromHoOh
# 71 "data/maps/NavelRock_Top/scripts.pory"
	setflag FLAG_CAUGHT_HO_OH
# 72 "data/maps/NavelRock_Top/scripts.pory"
	releaseall
# 73 "data/maps/NavelRock_Top/scripts.pory"
	end
# 74 "data/maps/NavelRock_Top/scripts.pory"

# 75 "data/maps/NavelRock_Top/scripts.pory"
NavelRock_Top_EventScript_DefeatedHoOh::
# 76 "data/maps/NavelRock_Top/scripts.pory"
	setflag FLAG_DEFEATED_HO_OH
# 77 "data/maps/NavelRock_Top/scripts.pory"
	setvar VAR_0x8004, SPECIES_HO_OH
# 78 "data/maps/NavelRock_Top/scripts.pory"
	goto Common_EventScript_LegendaryFlewAway
# 79 "data/maps/NavelRock_Top/scripts.pory"
	end
# 80 "data/maps/NavelRock_Top/scripts.pory"

# 81 "data/maps/NavelRock_Top/scripts.pory"
NavelRock_Top_EventScript_RanFromHoOh::
# 82 "data/maps/NavelRock_Top/scripts.pory"
	setvar VAR_0x8004, SPECIES_HO_OH
# 83 "data/maps/NavelRock_Top/scripts.pory"
	goto Common_EventScript_LegendaryFlewAway
# 84 "data/maps/NavelRock_Top/scripts.pory"
	end
# 85 "data/maps/NavelRock_Top/scripts.pory"

# 86 "data/maps/NavelRock_Top/scripts.pory"
NavelRock_Top_Movement_CameraPanUp:
# 87 "data/maps/NavelRock_Top/scripts.pory"
	walk_up
# 88 "data/maps/NavelRock_Top/scripts.pory"
	walk_up
# 89 "data/maps/NavelRock_Top/scripts.pory"
	walk_up
# 90 "data/maps/NavelRock_Top/scripts.pory"
	step_end
# 91 "data/maps/NavelRock_Top/scripts.pory"

# 92 "data/maps/NavelRock_Top/scripts.pory"
NavelRock_Top_Movement_CameraPanDown:
# 93 "data/maps/NavelRock_Top/scripts.pory"
	delay_16
# 94 "data/maps/NavelRock_Top/scripts.pory"
	delay_16
# 95 "data/maps/NavelRock_Top/scripts.pory"
	walk_down
# 96 "data/maps/NavelRock_Top/scripts.pory"
	walk_down
# 97 "data/maps/NavelRock_Top/scripts.pory"
	walk_down
# 98 "data/maps/NavelRock_Top/scripts.pory"
	step_end
# 99 "data/maps/NavelRock_Top/scripts.pory"

# 100 "data/maps/NavelRock_Top/scripts.pory"
NavelRock_Top_Movement_HoOhApproach:
# 101 "data/maps/NavelRock_Top/scripts.pory"
	walk_down
# 102 "data/maps/NavelRock_Top/scripts.pory"
	walk_down
# 103 "data/maps/NavelRock_Top/scripts.pory"
	walk_down
# 104 "data/maps/NavelRock_Top/scripts.pory"
	walk_down
# 105 "data/maps/NavelRock_Top/scripts.pory"
	walk_down
# 106 "data/maps/NavelRock_Top/scripts.pory"
	walk_in_place_down
# 107 "data/maps/NavelRock_Top/scripts.pory"
	delay_16
# 108 "data/maps/NavelRock_Top/scripts.pory"
	delay_16
# 109 "data/maps/NavelRock_Top/scripts.pory"
	step_end
# 110 "data/maps/NavelRock_Top/scripts.pory"

# 111 "data/maps/NavelRock_Top/scripts.pory"
NavelRock_Top_Movement_HoOhAppear:
# 112 "data/maps/NavelRock_Top/scripts.pory"
	delay_16
# 113 "data/maps/NavelRock_Top/scripts.pory"
	delay_16
# 114 "data/maps/NavelRock_Top/scripts.pory"
	walk_in_place_down
# 115 "data/maps/NavelRock_Top/scripts.pory"
	walk_in_place_down
# 116 "data/maps/NavelRock_Top/scripts.pory"
	walk_in_place_down
# 117 "data/maps/NavelRock_Top/scripts.pory"
	walk_in_place_down
# 118 "data/maps/NavelRock_Top/scripts.pory"
	step_end
