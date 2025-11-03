# 1 "data/maps/SouthernIsland_Interior/scripts.pory"

# 2 "data/maps/SouthernIsland_Interior/scripts.pory"
SouthernIsland_Interior_MapScripts::
# 3 "data/maps/SouthernIsland_Interior/scripts.pory"
	map_script MAP_SCRIPT_ON_RESUME, SouthernIsland_Interior_OnResume
# 4 "data/maps/SouthernIsland_Interior/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, SouthernIsland_Interior_OnTransition
# 5 "data/maps/SouthernIsland_Interior/scripts.pory"
	.byte 0
# 6 "data/maps/SouthernIsland_Interior/scripts.pory"

# 7 "data/maps/SouthernIsland_Interior/scripts.pory"
SouthernIsland_Interior_OnResume:
# 8 "data/maps/SouthernIsland_Interior/scripts.pory"
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, SouthernIsland_Interior_EventScript_TryRemoveLati
# 9 "data/maps/SouthernIsland_Interior/scripts.pory"
	end
# 10 "data/maps/SouthernIsland_Interior/scripts.pory"

# 11 "data/maps/SouthernIsland_Interior/scripts.pory"
SouthernIsland_Interior_EventScript_TryRemoveLati::
# 12 "data/maps/SouthernIsland_Interior/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 13 "data/maps/SouthernIsland_Interior/scripts.pory"
	goto_if_ne VAR_RESULT, B_OUTCOME_CAUGHT, Common_EventScript_NopReturn
# 14 "data/maps/SouthernIsland_Interior/scripts.pory"
	removeobject LOCALID_SOUTHERN_ISLAND_LATI
# 15 "data/maps/SouthernIsland_Interior/scripts.pory"
	return
# 16 "data/maps/SouthernIsland_Interior/scripts.pory"

# 17 "data/maps/SouthernIsland_Interior/scripts.pory"
SouthernIsland_Interior_OnTransition:
# 18 "data/maps/SouthernIsland_Interior/scripts.pory"
	call_if_eq VAR_ROAMER_POKEMON, 0, SouthernIsland_Interior_EventScript_SetUpLatios
# 19 "data/maps/SouthernIsland_Interior/scripts.pory"
	call_if_ne VAR_ROAMER_POKEMON, 0, SouthernIsland_Interior_EventScript_SetUpLatias
# 20 "data/maps/SouthernIsland_Interior/scripts.pory"
	call SouthernIsland_Interior_EventScript_SetUpPlayerGfx
# 21 "data/maps/SouthernIsland_Interior/scripts.pory"
	end
# 22 "data/maps/SouthernIsland_Interior/scripts.pory"

# 23 "data/maps/SouthernIsland_Interior/scripts.pory"
SouthernIsland_Interior_EventScript_SetUpLatios::
# 24 "data/maps/SouthernIsland_Interior/scripts.pory"
	setvar VAR_OBJ_GFX_ID_1, OBJ_EVENT_GFX_LATIOS
# 25 "data/maps/SouthernIsland_Interior/scripts.pory"
	setvar VAR_TEMP_4, SPECIES_LATIOS
# 26 "data/maps/SouthernIsland_Interior/scripts.pory"
	return
# 27 "data/maps/SouthernIsland_Interior/scripts.pory"

# 28 "data/maps/SouthernIsland_Interior/scripts.pory"
SouthernIsland_Interior_EventScript_SetUpLatias::
# 29 "data/maps/SouthernIsland_Interior/scripts.pory"
	setvar VAR_OBJ_GFX_ID_1, OBJ_EVENT_GFX_LATIAS
# 30 "data/maps/SouthernIsland_Interior/scripts.pory"
	setvar VAR_TEMP_4, SPECIES_LATIAS
# 31 "data/maps/SouthernIsland_Interior/scripts.pory"
	return
# 32 "data/maps/SouthernIsland_Interior/scripts.pory"

# 33 "data/maps/SouthernIsland_Interior/scripts.pory"
SouthernIsland_Interior_EventScript_SetUpPlayerGfx::
# 34 "data/maps/SouthernIsland_Interior/scripts.pory"
	checkplayergender
# 35 "data/maps/SouthernIsland_Interior/scripts.pory"
	goto_if_eq VAR_RESULT, MALE, SouthernIsland_Interior_EventScript_SetBrendanGfx
# 36 "data/maps/SouthernIsland_Interior/scripts.pory"
	goto_if_eq VAR_RESULT, FEMALE, SouthernIsland_Interior_EventScript_SetMayGfx
# 37 "data/maps/SouthernIsland_Interior/scripts.pory"
	end
# 38 "data/maps/SouthernIsland_Interior/scripts.pory"

# 39 "data/maps/SouthernIsland_Interior/scripts.pory"
SouthernIsland_Interior_EventScript_SetBrendanGfx::
# 40 "data/maps/SouthernIsland_Interior/scripts.pory"
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_RIVAL_BRENDAN_NORMAL
# 41 "data/maps/SouthernIsland_Interior/scripts.pory"
	return
# 42 "data/maps/SouthernIsland_Interior/scripts.pory"

# 43 "data/maps/SouthernIsland_Interior/scripts.pory"
SouthernIsland_Interior_EventScript_SetMayGfx::
# 44 "data/maps/SouthernIsland_Interior/scripts.pory"
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_RIVAL_MAY_NORMAL
# 45 "data/maps/SouthernIsland_Interior/scripts.pory"
	return
# 46 "data/maps/SouthernIsland_Interior/scripts.pory"

# 47 "data/maps/SouthernIsland_Interior/scripts.pory"
SouthernIsland_Interior_EventScript_TryLatiEncounter::
# 48 "data/maps/SouthernIsland_Interior/scripts.pory"
	lockall
# 49 "data/maps/SouthernIsland_Interior/scripts.pory"
	setvar VAR_0x8008, 12  @ Player's Y coordinate. Not read
# 50 "data/maps/SouthernIsland_Interior/scripts.pory"
	goto SouthernIsland_Interior_EventScript_Lati
# 51 "data/maps/SouthernIsland_Interior/scripts.pory"
	end
# 52 "data/maps/SouthernIsland_Interior/scripts.pory"

# 53 "data/maps/SouthernIsland_Interior/scripts.pory"
SouthernIsland_Interior_EventScript_Lati::
# 54 "data/maps/SouthernIsland_Interior/scripts.pory"
	goto_if_set FLAG_TEMP_2, SouthernIsland_Interior_EventScript_Sign
# 55 "data/maps/SouthernIsland_Interior/scripts.pory"
	goto_if_set FLAG_DEFEATED_LATIAS_OR_LATIOS, SouthernIsland_Interior_EventScript_Sign
# 56 "data/maps/SouthernIsland_Interior/scripts.pory"
	goto_if_set FLAG_CAUGHT_LATIAS_OR_LATIOS, SouthernIsland_Interior_EventScript_Sign
# 57 "data/maps/SouthernIsland_Interior/scripts.pory"
	goto_if_unset FLAG_ENABLE_SHIP_SOUTHERN_ISLAND, SouthernIsland_Interior_EventScript_Sign
# 58 "data/maps/SouthernIsland_Interior/scripts.pory"
	setflag FLAG_ENCOUNTERED_LATIAS_OR_LATIOS
# 59 "data/maps/SouthernIsland_Interior/scripts.pory"
	setflag FLAG_TEMP_2
# 60 "data/maps/SouthernIsland_Interior/scripts.pory"
	special SpawnCameraObject
# 61 "data/maps/SouthernIsland_Interior/scripts.pory"
	applymovement LOCALID_CAMERA, SouthernIsland_Interior_Movement_CameraPanUp
# 62 "data/maps/SouthernIsland_Interior/scripts.pory"
	waitmovement 0
# 63 "data/maps/SouthernIsland_Interior/scripts.pory"
	delay 50
# 64 "data/maps/SouthernIsland_Interior/scripts.pory"
	waitse
# 65 "data/maps/SouthernIsland_Interior/scripts.pory"
	playmoncry VAR_TEMP_4, CRY_MODE_NORMAL
# 66 "data/maps/SouthernIsland_Interior/scripts.pory"
	delay 30
# 67 "data/maps/SouthernIsland_Interior/scripts.pory"
	waitmoncry
# 68 "data/maps/SouthernIsland_Interior/scripts.pory"
	addobject LOCALID_SOUTHERN_ISLAND_LATI
# 69 "data/maps/SouthernIsland_Interior/scripts.pory"
	delay 30
# 70 "data/maps/SouthernIsland_Interior/scripts.pory"
	applymovement LOCALID_CAMERA, SouthernIsland_Interior_Movement_CameraPanDown
# 71 "data/maps/SouthernIsland_Interior/scripts.pory"
	applymovement LOCALID_SOUTHERN_ISLAND_LATI, SouthernIsland_Interior_Movement_LatiApproach
# 72 "data/maps/SouthernIsland_Interior/scripts.pory"
	waitmovement 0
# 73 "data/maps/SouthernIsland_Interior/scripts.pory"
	delay 50
# 74 "data/maps/SouthernIsland_Interior/scripts.pory"
	special RemoveCameraObject
# 75 "data/maps/SouthernIsland_Interior/scripts.pory"
	setvar VAR_LAST_TALKED, LOCALID_SOUTHERN_ISLAND_LATI
# 76 "data/maps/SouthernIsland_Interior/scripts.pory"
	call_if_eq VAR_ROAMER_POKEMON, 0, SouthernIsland_Interior_EventScript_SetLatiosBattleVars
# 77 "data/maps/SouthernIsland_Interior/scripts.pory"
	call_if_ne VAR_ROAMER_POKEMON, 0, SouthernIsland_Interior_EventScript_SetLatiasBattleVars
# 78 "data/maps/SouthernIsland_Interior/scripts.pory"
	setflag FLAG_SYS_CTRL_OBJ_DELETE
# 79 "data/maps/SouthernIsland_Interior/scripts.pory"
	special BattleSetup_StartLatiBattle
# 80 "data/maps/SouthernIsland_Interior/scripts.pory"
	waitstate
# 81 "data/maps/SouthernIsland_Interior/scripts.pory"
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
# 82 "data/maps/SouthernIsland_Interior/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 83 "data/maps/SouthernIsland_Interior/scripts.pory"
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, SouthernIsland_Interior_EventScript_LatiDefeated
# 84 "data/maps/SouthernIsland_Interior/scripts.pory"
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, SouthernIsland_Interior_EventScript_RanFromLati
# 85 "data/maps/SouthernIsland_Interior/scripts.pory"
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, SouthernIsland_Interior_EventScript_RanFromLati
# 86 "data/maps/SouthernIsland_Interior/scripts.pory"
	setflag FLAG_CAUGHT_LATIAS_OR_LATIOS
# 87 "data/maps/SouthernIsland_Interior/scripts.pory"
	releaseall
# 88 "data/maps/SouthernIsland_Interior/scripts.pory"
	end
# 89 "data/maps/SouthernIsland_Interior/scripts.pory"

# 90 "data/maps/SouthernIsland_Interior/scripts.pory"
SouthernIsland_Interior_EventScript_LatiDefeated::
# 91 "data/maps/SouthernIsland_Interior/scripts.pory"
	setflag FLAG_DEFEATED_LATIAS_OR_LATIOS
# 92 "data/maps/SouthernIsland_Interior/scripts.pory"
	copyvar VAR_0x8004, VAR_TEMP_4
# 93 "data/maps/SouthernIsland_Interior/scripts.pory"
	goto Common_EventScript_LegendaryFlewAway
# 94 "data/maps/SouthernIsland_Interior/scripts.pory"
	end
# 95 "data/maps/SouthernIsland_Interior/scripts.pory"

# 96 "data/maps/SouthernIsland_Interior/scripts.pory"
SouthernIsland_Interior_EventScript_RanFromLati::
# 97 "data/maps/SouthernIsland_Interior/scripts.pory"
	copyvar VAR_0x8004, VAR_TEMP_4
# 98 "data/maps/SouthernIsland_Interior/scripts.pory"
	goto Common_EventScript_LegendaryFlewAway
# 99 "data/maps/SouthernIsland_Interior/scripts.pory"
	end
# 100 "data/maps/SouthernIsland_Interior/scripts.pory"

# 101 "data/maps/SouthernIsland_Interior/scripts.pory"
SouthernIsland_Interior_EventScript_Sign::
# 102 "data/maps/SouthernIsland_Interior/scripts.pory"
	msgbox SouthernIsland_Interior_Text_Sign, MSGBOX_DEFAULT
# 103 "data/maps/SouthernIsland_Interior/scripts.pory"
	releaseall
# 104 "data/maps/SouthernIsland_Interior/scripts.pory"
	end
# 105 "data/maps/SouthernIsland_Interior/scripts.pory"

# 106 "data/maps/SouthernIsland_Interior/scripts.pory"
SouthernIsland_Interior_EventScript_SetLatiosBattleVars::
# 107 "data/maps/SouthernIsland_Interior/scripts.pory"
	seteventmon SPECIES_LATIOS, 50, ITEM_SOUL_DEW
# 108 "data/maps/SouthernIsland_Interior/scripts.pory"
	return
# 109 "data/maps/SouthernIsland_Interior/scripts.pory"

# 110 "data/maps/SouthernIsland_Interior/scripts.pory"
SouthernIsland_Interior_EventScript_SetLatiasBattleVars::
# 111 "data/maps/SouthernIsland_Interior/scripts.pory"
	seteventmon SPECIES_LATIAS, 50, ITEM_SOUL_DEW
# 112 "data/maps/SouthernIsland_Interior/scripts.pory"
	return
# 113 "data/maps/SouthernIsland_Interior/scripts.pory"

# 114 "data/maps/SouthernIsland_Interior/scripts.pory"
SouthernIsland_Interior_Movement_CameraPanUp:
# 115 "data/maps/SouthernIsland_Interior/scripts.pory"
	walk_up
# 116 "data/maps/SouthernIsland_Interior/scripts.pory"
	walk_up
# 117 "data/maps/SouthernIsland_Interior/scripts.pory"
	walk_up
# 118 "data/maps/SouthernIsland_Interior/scripts.pory"
	step_end
# 119 "data/maps/SouthernIsland_Interior/scripts.pory"

# 120 "data/maps/SouthernIsland_Interior/scripts.pory"
SouthernIsland_Interior_Movement_CameraPanDown:
# 121 "data/maps/SouthernIsland_Interior/scripts.pory"
	delay_16
# 122 "data/maps/SouthernIsland_Interior/scripts.pory"
	delay_16
# 123 "data/maps/SouthernIsland_Interior/scripts.pory"
	delay_16
# 124 "data/maps/SouthernIsland_Interior/scripts.pory"
	delay_16
# 125 "data/maps/SouthernIsland_Interior/scripts.pory"
	delay_16
# 126 "data/maps/SouthernIsland_Interior/scripts.pory"
	delay_16
# 127 "data/maps/SouthernIsland_Interior/scripts.pory"
	delay_16
# 128 "data/maps/SouthernIsland_Interior/scripts.pory"
	walk_down
# 129 "data/maps/SouthernIsland_Interior/scripts.pory"
	walk_down
# 130 "data/maps/SouthernIsland_Interior/scripts.pory"
	walk_down
# 131 "data/maps/SouthernIsland_Interior/scripts.pory"
	walk_in_place_faster_up
# 132 "data/maps/SouthernIsland_Interior/scripts.pory"
	step_end
# 133 "data/maps/SouthernIsland_Interior/scripts.pory"

# 134 "data/maps/SouthernIsland_Interior/scripts.pory"
SouthernIsland_Interior_Movement_LatiApproach:
# 135 "data/maps/SouthernIsland_Interior/scripts.pory"
	walk_down
# 136 "data/maps/SouthernIsland_Interior/scripts.pory"
	walk_down
# 137 "data/maps/SouthernIsland_Interior/scripts.pory"
	walk_down
# 138 "data/maps/SouthernIsland_Interior/scripts.pory"
	walk_down
# 139 "data/maps/SouthernIsland_Interior/scripts.pory"
	walk_down
# 140 "data/maps/SouthernIsland_Interior/scripts.pory"
	delay_16
# 141 "data/maps/SouthernIsland_Interior/scripts.pory"
	delay_16
# 142 "data/maps/SouthernIsland_Interior/scripts.pory"
	walk_down
# 143 "data/maps/SouthernIsland_Interior/scripts.pory"
	walk_down
# 144 "data/maps/SouthernIsland_Interior/scripts.pory"
	walk_down
# 145 "data/maps/SouthernIsland_Interior/scripts.pory"
	walk_down
# 146 "data/maps/SouthernIsland_Interior/scripts.pory"
	step_end
