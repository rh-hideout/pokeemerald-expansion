# 1 "data/maps/NavelRock_Top/scripts.pory"

# 2 "data/maps/NavelRock_Top/scripts.pory"
NavelRock_Top_MapScripts::
# 3 "data/maps/NavelRock_Top/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, NavelRock_Top_OnTransition
# 4 "data/maps/NavelRock_Top/scripts.pory"
	map_script MAP_SCRIPT_ON_RESUME, NavelRock_Top_OnResume
# 5 "data/maps/NavelRock_Top/scripts.pory"
	.byte 0
# 6 "data/maps/NavelRock_Top/scripts.pory"

# 7 "data/maps/NavelRock_Top/scripts.pory"
NavelRock_Top_OnTransition:
# 8 "data/maps/NavelRock_Top/scripts.pory"
	call_if_set FLAG_CAUGHT_HO_OH, NavelRock_Top_EventScript_HideHoOh
# 9 "data/maps/NavelRock_Top/scripts.pory"
	call_if_unset FLAG_CAUGHT_HO_OH, NavelRock_Top_EventScript_TryShowHoOh
# 10 "data/maps/NavelRock_Top/scripts.pory"
	end
# 11 "data/maps/NavelRock_Top/scripts.pory"

# 12 "data/maps/NavelRock_Top/scripts.pory"
NavelRock_Top_EventScript_HideHoOh::
# 13 "data/maps/NavelRock_Top/scripts.pory"
	setvar VAR_TEMP_1, 1
# 14 "data/maps/NavelRock_Top/scripts.pory"
	setflag FLAG_HIDE_HO_OH
# 15 "data/maps/NavelRock_Top/scripts.pory"
	return
# 16 "data/maps/NavelRock_Top/scripts.pory"

# 17 "data/maps/NavelRock_Top/scripts.pory"
NavelRock_Top_EventScript_TryShowHoOh::
# 18 "data/maps/NavelRock_Top/scripts.pory"
	setvar VAR_TEMP_1, 1
# 19 "data/maps/NavelRock_Top/scripts.pory"
	goto_if_set FLAG_DEFEATED_HO_OH, Common_EventScript_NopReturn
# 20 "data/maps/NavelRock_Top/scripts.pory"
	setvar VAR_TEMP_1, 0
# 21 "data/maps/NavelRock_Top/scripts.pory"
	clearflag FLAG_HIDE_HO_OH
# 22 "data/maps/NavelRock_Top/scripts.pory"
	return
# 23 "data/maps/NavelRock_Top/scripts.pory"

# 24 "data/maps/NavelRock_Top/scripts.pory"
NavelRock_Top_OnResume:
# 25 "data/maps/NavelRock_Top/scripts.pory"
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, NavelRock_Top_EventScript_TryRemoveHoOh
# 26 "data/maps/NavelRock_Top/scripts.pory"
	end
# 27 "data/maps/NavelRock_Top/scripts.pory"

# 28 "data/maps/NavelRock_Top/scripts.pory"
NavelRock_Top_EventScript_TryRemoveHoOh::
# 29 "data/maps/NavelRock_Top/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 30 "data/maps/NavelRock_Top/scripts.pory"
	goto_if_ne VAR_RESULT, B_OUTCOME_CAUGHT, Common_EventScript_NopReturn
# 31 "data/maps/NavelRock_Top/scripts.pory"
	removeobject LOCALID_NAVEL_ROCK_HO_OH
# 32 "data/maps/NavelRock_Top/scripts.pory"
	return
# 33 "data/maps/NavelRock_Top/scripts.pory"

# 34 "data/maps/NavelRock_Top/scripts.pory"
NavelRock_Top_EventScript_HoOh::
# 35 "data/maps/NavelRock_Top/scripts.pory"
	lockall
# 36 "data/maps/NavelRock_Top/scripts.pory"
	setvar VAR_TEMP_1, 1
# 37 "data/maps/NavelRock_Top/scripts.pory"
	special SpawnCameraObject
# 38 "data/maps/NavelRock_Top/scripts.pory"
	setvar VAR_0x8004, 3  @ num loops
# 39 "data/maps/NavelRock_Top/scripts.pory"
	setvar VAR_0x8005, 35 @ delay
# 40 "data/maps/NavelRock_Top/scripts.pory"
	special LoopWingFlapSE
# 41 "data/maps/NavelRock_Top/scripts.pory"
	applymovement LOCALID_NAVEL_ROCK_HO_OH, NavelRock_Top_Movement_HoOhAppear
# 42 "data/maps/NavelRock_Top/scripts.pory"
	applymovement LOCALID_CAMERA, NavelRock_Top_Movement_CameraPanUp
# 43 "data/maps/NavelRock_Top/scripts.pory"
	waitmovement 0
# 44 "data/maps/NavelRock_Top/scripts.pory"
	delay 50
# 45 "data/maps/NavelRock_Top/scripts.pory"
	setweather WEATHER_NONE
# 46 "data/maps/NavelRock_Top/scripts.pory"
	doweather
# 47 "data/maps/NavelRock_Top/scripts.pory"
	waitse
# 48 "data/maps/NavelRock_Top/scripts.pory"
	playmoncry SPECIES_HO_OH, CRY_MODE_ENCOUNTER
# 49 "data/maps/NavelRock_Top/scripts.pory"
	delay 30
# 50 "data/maps/NavelRock_Top/scripts.pory"
	waitmoncry
# 51 "data/maps/NavelRock_Top/scripts.pory"
	delay 60
# 52 "data/maps/NavelRock_Top/scripts.pory"
	setvar VAR_0x8004, 3  @ num loops
# 53 "data/maps/NavelRock_Top/scripts.pory"
	setvar VAR_0x8005, 35 @ delay
# 54 "data/maps/NavelRock_Top/scripts.pory"
	special LoopWingFlapSE
# 55 "data/maps/NavelRock_Top/scripts.pory"
	applymovement LOCALID_CAMERA, NavelRock_Top_Movement_CameraPanDown
# 56 "data/maps/NavelRock_Top/scripts.pory"
	applymovement LOCALID_NAVEL_ROCK_HO_OH, NavelRock_Top_Movement_HoOhApproach
# 57 "data/maps/NavelRock_Top/scripts.pory"
	waitmovement 0
# 58 "data/maps/NavelRock_Top/scripts.pory"
	special RemoveCameraObject
# 59 "data/maps/NavelRock_Top/scripts.pory"
	seteventmon SPECIES_HO_OH, 70
# 60 "data/maps/NavelRock_Top/scripts.pory"
	setflag FLAG_SYS_CTRL_OBJ_DELETE
# 61 "data/maps/NavelRock_Top/scripts.pory"
	special BattleSetup_StartLegendaryBattle
# 62 "data/maps/NavelRock_Top/scripts.pory"
	waitstate
# 63 "data/maps/NavelRock_Top/scripts.pory"
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
# 64 "data/maps/NavelRock_Top/scripts.pory"
	setvar VAR_LAST_TALKED, LOCALID_NAVEL_ROCK_HO_OH
# 65 "data/maps/NavelRock_Top/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 66 "data/maps/NavelRock_Top/scripts.pory"
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, NavelRock_Top_EventScript_DefeatedHoOh
# 67 "data/maps/NavelRock_Top/scripts.pory"
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, NavelRock_Top_EventScript_RanFromHoOh
# 68 "data/maps/NavelRock_Top/scripts.pory"
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, NavelRock_Top_EventScript_RanFromHoOh
# 69 "data/maps/NavelRock_Top/scripts.pory"
	setflag FLAG_CAUGHT_HO_OH
# 70 "data/maps/NavelRock_Top/scripts.pory"
	releaseall
# 71 "data/maps/NavelRock_Top/scripts.pory"
	end
# 72 "data/maps/NavelRock_Top/scripts.pory"

# 73 "data/maps/NavelRock_Top/scripts.pory"
NavelRock_Top_EventScript_DefeatedHoOh::
# 74 "data/maps/NavelRock_Top/scripts.pory"
	setflag FLAG_DEFEATED_HO_OH
# 75 "data/maps/NavelRock_Top/scripts.pory"
	setvar VAR_0x8004, SPECIES_HO_OH
# 76 "data/maps/NavelRock_Top/scripts.pory"
	goto Common_EventScript_LegendaryFlewAway
# 77 "data/maps/NavelRock_Top/scripts.pory"
	end
# 78 "data/maps/NavelRock_Top/scripts.pory"

# 79 "data/maps/NavelRock_Top/scripts.pory"
NavelRock_Top_EventScript_RanFromHoOh::
# 80 "data/maps/NavelRock_Top/scripts.pory"
	setvar VAR_0x8004, SPECIES_HO_OH
# 81 "data/maps/NavelRock_Top/scripts.pory"
	goto Common_EventScript_LegendaryFlewAway
# 82 "data/maps/NavelRock_Top/scripts.pory"
	end
# 83 "data/maps/NavelRock_Top/scripts.pory"

# 84 "data/maps/NavelRock_Top/scripts.pory"
NavelRock_Top_Movement_CameraPanUp:
# 85 "data/maps/NavelRock_Top/scripts.pory"
	walk_up
# 86 "data/maps/NavelRock_Top/scripts.pory"
	walk_up
# 87 "data/maps/NavelRock_Top/scripts.pory"
	walk_up
# 88 "data/maps/NavelRock_Top/scripts.pory"
	step_end
# 89 "data/maps/NavelRock_Top/scripts.pory"

# 90 "data/maps/NavelRock_Top/scripts.pory"
NavelRock_Top_Movement_CameraPanDown:
# 91 "data/maps/NavelRock_Top/scripts.pory"
	delay_16
# 92 "data/maps/NavelRock_Top/scripts.pory"
	delay_16
# 93 "data/maps/NavelRock_Top/scripts.pory"
	walk_down
# 94 "data/maps/NavelRock_Top/scripts.pory"
	walk_down
# 95 "data/maps/NavelRock_Top/scripts.pory"
	walk_down
# 96 "data/maps/NavelRock_Top/scripts.pory"
	step_end
# 97 "data/maps/NavelRock_Top/scripts.pory"

# 98 "data/maps/NavelRock_Top/scripts.pory"
NavelRock_Top_Movement_HoOhApproach:
# 99 "data/maps/NavelRock_Top/scripts.pory"
	walk_down
# 100 "data/maps/NavelRock_Top/scripts.pory"
	walk_down
# 101 "data/maps/NavelRock_Top/scripts.pory"
	walk_down
# 102 "data/maps/NavelRock_Top/scripts.pory"
	walk_down
# 103 "data/maps/NavelRock_Top/scripts.pory"
	walk_down
# 104 "data/maps/NavelRock_Top/scripts.pory"
	walk_in_place_down
# 105 "data/maps/NavelRock_Top/scripts.pory"
	delay_16
# 106 "data/maps/NavelRock_Top/scripts.pory"
	delay_16
# 107 "data/maps/NavelRock_Top/scripts.pory"
	step_end
# 108 "data/maps/NavelRock_Top/scripts.pory"

# 109 "data/maps/NavelRock_Top/scripts.pory"
NavelRock_Top_Movement_HoOhAppear:
# 110 "data/maps/NavelRock_Top/scripts.pory"
	delay_16
# 111 "data/maps/NavelRock_Top/scripts.pory"
	delay_16
# 112 "data/maps/NavelRock_Top/scripts.pory"
	walk_in_place_down
# 113 "data/maps/NavelRock_Top/scripts.pory"
	walk_in_place_down
# 114 "data/maps/NavelRock_Top/scripts.pory"
	walk_in_place_down
# 115 "data/maps/NavelRock_Top/scripts.pory"
	walk_in_place_down
# 116 "data/maps/NavelRock_Top/scripts.pory"
	step_end
