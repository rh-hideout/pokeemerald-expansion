# 1 "data/maps/SkyPillar_Top/scripts.pory"

# 2 "data/maps/SkyPillar_Top/scripts.pory"
SkyPillar_Top_MapScripts::
# 3 "data/maps/SkyPillar_Top/scripts.pory"
	map_script MAP_SCRIPT_ON_RESUME, SkyPillar_Top_OnResume
# 4 "data/maps/SkyPillar_Top/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, SkyPillar_Top_OnTransition
# 5 "data/maps/SkyPillar_Top/scripts.pory"
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, SkyPillar_Top_OnWarp
# 6 "data/maps/SkyPillar_Top/scripts.pory"
	.byte 0
# 7 "data/maps/SkyPillar_Top/scripts.pory"

# 8 "data/maps/SkyPillar_Top/scripts.pory"
SkyPillar_Top_OnResume:
# 9 "data/maps/SkyPillar_Top/scripts.pory"
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, SkyPillar_Top_EventScript_TryRemoveRayquaza
# 10 "data/maps/SkyPillar_Top/scripts.pory"
	end
# 11 "data/maps/SkyPillar_Top/scripts.pory"

# 12 "data/maps/SkyPillar_Top/scripts.pory"
SkyPillar_Top_EventScript_TryRemoveRayquaza::
# 13 "data/maps/SkyPillar_Top/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 14 "data/maps/SkyPillar_Top/scripts.pory"
	goto_if_ne VAR_RESULT, B_OUTCOME_CAUGHT, Common_EventScript_NopReturn
# 15 "data/maps/SkyPillar_Top/scripts.pory"
	removeobject VAR_LAST_TALKED
# 16 "data/maps/SkyPillar_Top/scripts.pory"
	return
# 17 "data/maps/SkyPillar_Top/scripts.pory"

# 18 "data/maps/SkyPillar_Top/scripts.pory"
SkyPillar_Top_OnTransition:
# 19 "data/maps/SkyPillar_Top/scripts.pory"
	call_if_lt VAR_SKY_PILLAR_STATE, 2, SkyPillar_Top_EventScript_SetCleanLayout
# 20 "data/maps/SkyPillar_Top/scripts.pory"
	call_if_ge VAR_SKY_PILLAR_STATE, 2, SkyPillar_Top_EventScript_TryShowRayquaza
# 21 "data/maps/SkyPillar_Top/scripts.pory"
	end
# 22 "data/maps/SkyPillar_Top/scripts.pory"

# 23 "data/maps/SkyPillar_Top/scripts.pory"
SkyPillar_Top_EventScript_SetCleanLayout::
# 24 "data/maps/SkyPillar_Top/scripts.pory"
	setmaplayoutindex LAYOUT_SKY_PILLAR_TOP_CLEAN
# 25 "data/maps/SkyPillar_Top/scripts.pory"
	setobjectmovementtype LOCALID_RAYQUAZA_SLEEPING, MOVEMENT_TYPE_FACE_DOWN
# 26 "data/maps/SkyPillar_Top/scripts.pory"
	return
# 27 "data/maps/SkyPillar_Top/scripts.pory"

# 28 "data/maps/SkyPillar_Top/scripts.pory"
SkyPillar_Top_EventScript_TryShowRayquaza::
# 29 "data/maps/SkyPillar_Top/scripts.pory"
	call_if_unset FLAG_DEFEATED_RAYQUAZA, SkyPillar_Top_EventScript_ShowRayquaza
# 30 "data/maps/SkyPillar_Top/scripts.pory"
	return
# 31 "data/maps/SkyPillar_Top/scripts.pory"

# 32 "data/maps/SkyPillar_Top/scripts.pory"
SkyPillar_Top_EventScript_ShowRayquaza::
# 33 "data/maps/SkyPillar_Top/scripts.pory"
	clearflag FLAG_HIDE_SKY_PILLAR_TOP_RAYQUAZA_STILL
# 34 "data/maps/SkyPillar_Top/scripts.pory"
	return
# 35 "data/maps/SkyPillar_Top/scripts.pory"

# 36 "data/maps/SkyPillar_Top/scripts.pory"
SkyPillar_Top_OnWarp:
# 37 "data/maps/SkyPillar_Top/scripts.pory"
	map_script_2 VAR_SKY_PILLAR_STATE, 0, SkyPillar_Top_EventScript_RayquazaFaceDown
# 38 "data/maps/SkyPillar_Top/scripts.pory"
	.2byte 0
# 39 "data/maps/SkyPillar_Top/scripts.pory"

# 40 "data/maps/SkyPillar_Top/scripts.pory"
SkyPillar_Top_EventScript_RayquazaFaceDown::
# 41 "data/maps/SkyPillar_Top/scripts.pory"
	turnobject LOCALID_RAYQUAZA_SLEEPING, DIR_SOUTH
# 42 "data/maps/SkyPillar_Top/scripts.pory"
	end
# 43 "data/maps/SkyPillar_Top/scripts.pory"

# 44 "data/maps/SkyPillar_Top/scripts.pory"
SkyPillar_Top_EventScript_Rayquaza::
# 45 "data/maps/SkyPillar_Top/scripts.pory"
	lockall
# 46 "data/maps/SkyPillar_Top/scripts.pory"
	waitse
# 47 "data/maps/SkyPillar_Top/scripts.pory"
	playmoncry SPECIES_RAYQUAZA, CRY_MODE_ENCOUNTER
# 48 "data/maps/SkyPillar_Top/scripts.pory"
	delay 40
# 49 "data/maps/SkyPillar_Top/scripts.pory"
	waitmoncry
# 50 "data/maps/SkyPillar_Top/scripts.pory"
	setwildbattle SPECIES_RAYQUAZA, 70
# 51 "data/maps/SkyPillar_Top/scripts.pory"
	setflag FLAG_SYS_CTRL_OBJ_DELETE
# 52 "data/maps/SkyPillar_Top/scripts.pory"
	special BattleSetup_StartLegendaryBattle
# 53 "data/maps/SkyPillar_Top/scripts.pory"
	waitstate
# 54 "data/maps/SkyPillar_Top/scripts.pory"
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
# 55 "data/maps/SkyPillar_Top/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 56 "data/maps/SkyPillar_Top/scripts.pory"
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, SkyPillar_Top_EventScript_DefeatedRayquaza
# 57 "data/maps/SkyPillar_Top/scripts.pory"
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, SkyPillar_Top_EventScript_RanFromRayquaza
# 58 "data/maps/SkyPillar_Top/scripts.pory"
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, SkyPillar_Top_EventScript_RanFromRayquaza
# 59 "data/maps/SkyPillar_Top/scripts.pory"
	setflag FLAG_DEFEATED_RAYQUAZA
# 60 "data/maps/SkyPillar_Top/scripts.pory"
	releaseall
# 61 "data/maps/SkyPillar_Top/scripts.pory"
	end
# 62 "data/maps/SkyPillar_Top/scripts.pory"

# 63 "data/maps/SkyPillar_Top/scripts.pory"
SkyPillar_Top_EventScript_DefeatedRayquaza::
# 64 "data/maps/SkyPillar_Top/scripts.pory"
	setflag FLAG_DEFEATED_RAYQUAZA
# 65 "data/maps/SkyPillar_Top/scripts.pory"
	goto SkyPillar_Top_EventScript_DefeatedRayquaza2
# 66 "data/maps/SkyPillar_Top/scripts.pory"
	end
# 67 "data/maps/SkyPillar_Top/scripts.pory"

# 68 "data/maps/SkyPillar_Top/scripts.pory"
SkyPillar_Top_EventScript_RanFromRayquaza::
# 69 "data/maps/SkyPillar_Top/scripts.pory"
	setvar VAR_0x8004, SPECIES_RAYQUAZA
# 70 "data/maps/SkyPillar_Top/scripts.pory"
	goto SkyPillar_Top_EventScript_RanFromRayquaza2
# 71 "data/maps/SkyPillar_Top/scripts.pory"
	end
# 72 "data/maps/SkyPillar_Top/scripts.pory"

# 73 "data/maps/SkyPillar_Top/scripts.pory"
SkyPillar_Top_EventScript_DefeatedRayquaza2::
# 74 "data/maps/SkyPillar_Top/scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 75 "data/maps/SkyPillar_Top/scripts.pory"
	removeobject VAR_LAST_TALKED
# 76 "data/maps/SkyPillar_Top/scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 77 "data/maps/SkyPillar_Top/scripts.pory"
	releaseall
# 78 "data/maps/SkyPillar_Top/scripts.pory"
	end
# 79 "data/maps/SkyPillar_Top/scripts.pory"

# 80 "data/maps/SkyPillar_Top/scripts.pory"
SkyPillar_Top_EventScript_RanFromRayquaza2::
# 81 "data/maps/SkyPillar_Top/scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 82 "data/maps/SkyPillar_Top/scripts.pory"
	removeobject VAR_LAST_TALKED
# 83 "data/maps/SkyPillar_Top/scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 84 "data/maps/SkyPillar_Top/scripts.pory"
	bufferspeciesname STR_VAR_1, VAR_0x8004
# 85 "data/maps/SkyPillar_Top/scripts.pory"
	msgbox gText_LegendaryFlewAway, MSGBOX_DEFAULT
# 86 "data/maps/SkyPillar_Top/scripts.pory"
	releaseall
# 87 "data/maps/SkyPillar_Top/scripts.pory"
	end
# 88 "data/maps/SkyPillar_Top/scripts.pory"

# 89 "data/maps/SkyPillar_Top/scripts.pory"
SkyPillar_Top_EventScript_AwakenRayquaza::
# 90 "data/maps/SkyPillar_Top/scripts.pory"
	lockall
# 91 "data/maps/SkyPillar_Top/scripts.pory"
	fadeoutbgm 1
# 92 "data/maps/SkyPillar_Top/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_FaceUp
# 93 "data/maps/SkyPillar_Top/scripts.pory"
	waitmovement 0
# 94 "data/maps/SkyPillar_Top/scripts.pory"
	special SpawnCameraObject
# 95 "data/maps/SkyPillar_Top/scripts.pory"
	applymovement LOCALID_CAMERA, SkyPillar_Top_Movement_CameraPanUp
# 96 "data/maps/SkyPillar_Top/scripts.pory"
	waitmovement 0
# 97 "data/maps/SkyPillar_Top/scripts.pory"
	special RemoveCameraObject
# 98 "data/maps/SkyPillar_Top/scripts.pory"
	applymovement LOCALID_RAYQUAZA_SLEEPING, SkyPillar_Top_Movement_RayquazaStir
# 99 "data/maps/SkyPillar_Top/scripts.pory"
	waitmovement 0
# 100 "data/maps/SkyPillar_Top/scripts.pory"
	waitse
# 101 "data/maps/SkyPillar_Top/scripts.pory"
	playmoncry SPECIES_RAYQUAZA, CRY_MODE_ENCOUNTER
# 102 "data/maps/SkyPillar_Top/scripts.pory"
	setvar VAR_0x8004, 1  @ vertical pan
# 103 "data/maps/SkyPillar_Top/scripts.pory"
	setvar VAR_0x8005, 1  @ horizontal pan
# 104 "data/maps/SkyPillar_Top/scripts.pory"
	setvar VAR_0x8006, 8  @ num shakes
# 105 "data/maps/SkyPillar_Top/scripts.pory"
	setvar VAR_0x8007, 3  @ shake delay
# 106 "data/maps/SkyPillar_Top/scripts.pory"
	special ShakeCamera
# 107 "data/maps/SkyPillar_Top/scripts.pory"
	waitstate
# 108 "data/maps/SkyPillar_Top/scripts.pory"
	waitse
# 109 "data/maps/SkyPillar_Top/scripts.pory"
	playmoncry SPECIES_RAYQUAZA, CRY_MODE_ENCOUNTER
# 110 "data/maps/SkyPillar_Top/scripts.pory"
	setvar VAR_0x8004, 1  @ vertical pan
# 111 "data/maps/SkyPillar_Top/scripts.pory"
	setvar VAR_0x8005, 2  @ horizontal pan
# 112 "data/maps/SkyPillar_Top/scripts.pory"
	setvar VAR_0x8006, 8  @ num shakes
# 113 "data/maps/SkyPillar_Top/scripts.pory"
	setvar VAR_0x8007, 5  @ shake delay
# 114 "data/maps/SkyPillar_Top/scripts.pory"
	special ShakeCamera
# 115 "data/maps/SkyPillar_Top/scripts.pory"
	waitstate
# 116 "data/maps/SkyPillar_Top/scripts.pory"
	waitmoncry
# 117 "data/maps/SkyPillar_Top/scripts.pory"
	applymovement LOCALID_RAYQUAZA_SLEEPING, SkyPillar_Top_Movement_RayquazaFlyOff
# 118 "data/maps/SkyPillar_Top/scripts.pory"
	waitmovement 0
# 119 "data/maps/SkyPillar_Top/scripts.pory"
	removeobject LOCALID_RAYQUAZA_SLEEPING
# 120 "data/maps/SkyPillar_Top/scripts.pory"
	msgbox SkyPillar_Top_Text_RayquazaFlewOff, MSGBOX_DEFAULT
# 121 "data/maps/SkyPillar_Top/scripts.pory"
	closemessage
# 122 "data/maps/SkyPillar_Top/scripts.pory"
	delay 20
# 123 "data/maps/SkyPillar_Top/scripts.pory"
	fadeinbgm 1
# 124 "data/maps/SkyPillar_Top/scripts.pory"
	special SpawnCameraObject
# 125 "data/maps/SkyPillar_Top/scripts.pory"
	applymovement LOCALID_CAMERA, SkyPillar_Top_Movement_CameraPanDown
# 126 "data/maps/SkyPillar_Top/scripts.pory"
	waitmovement 0
# 127 "data/maps/SkyPillar_Top/scripts.pory"
	special RemoveCameraObject
# 128 "data/maps/SkyPillar_Top/scripts.pory"
	setvar VAR_SOOTOPOLIS_CITY_STATE, 5
# 129 "data/maps/SkyPillar_Top/scripts.pory"
	setvar VAR_SKY_PILLAR_STATE, 1
# 130 "data/maps/SkyPillar_Top/scripts.pory"
	setvar VAR_SKY_PILLAR_RAYQUAZA_CRY_DONE, 1
# 131 "data/maps/SkyPillar_Top/scripts.pory"
	releaseall
# 132 "data/maps/SkyPillar_Top/scripts.pory"
	end
# 133 "data/maps/SkyPillar_Top/scripts.pory"

# 134 "data/maps/SkyPillar_Top/scripts.pory"
@ Rayquaza has unusual movement frames
# 135 "data/maps/SkyPillar_Top/scripts.pory"
@ See comments, or sAnimTable_Rayquaza
# 136 "data/maps/SkyPillar_Top/scripts.pory"
SkyPillar_Top_Movement_RayquazaStir:
# 137 "data/maps/SkyPillar_Top/scripts.pory"
	delay_16
# 138 "data/maps/SkyPillar_Top/scripts.pory"
	walk_in_place_fast_left  @ Coiled, awake
# 139 "data/maps/SkyPillar_Top/scripts.pory"
	delay_16
# 140 "data/maps/SkyPillar_Top/scripts.pory"
	delay_16
# 141 "data/maps/SkyPillar_Top/scripts.pory"
	delay_16
# 142 "data/maps/SkyPillar_Top/scripts.pory"
	delay_16
# 143 "data/maps/SkyPillar_Top/scripts.pory"
	delay_16
# 144 "data/maps/SkyPillar_Top/scripts.pory"
	walk_in_place_left  @ Coiled, mouth open
# 145 "data/maps/SkyPillar_Top/scripts.pory"
	delay_16
# 146 "data/maps/SkyPillar_Top/scripts.pory"
	walk_in_place_right  @ Normal, awake
# 147 "data/maps/SkyPillar_Top/scripts.pory"
	delay_16
# 148 "data/maps/SkyPillar_Top/scripts.pory"
	delay_16
# 149 "data/maps/SkyPillar_Top/scripts.pory"
	delay_16
# 150 "data/maps/SkyPillar_Top/scripts.pory"
	delay_16
# 151 "data/maps/SkyPillar_Top/scripts.pory"
	delay_16
# 152 "data/maps/SkyPillar_Top/scripts.pory"
	delay_16
# 153 "data/maps/SkyPillar_Top/scripts.pory"
	step_end
# 154 "data/maps/SkyPillar_Top/scripts.pory"

# 155 "data/maps/SkyPillar_Top/scripts.pory"
SkyPillar_Top_Movement_RayquazaFlyOff:
# 156 "data/maps/SkyPillar_Top/scripts.pory"
	delay_16
# 157 "data/maps/SkyPillar_Top/scripts.pory"
	walk_in_place_down  @ Coiled, asleep
# 158 "data/maps/SkyPillar_Top/scripts.pory"
	delay_8
# 159 "data/maps/SkyPillar_Top/scripts.pory"
	walk_in_place_right  @ Normal, awake
# 160 "data/maps/SkyPillar_Top/scripts.pory"
	delay_8
# 161 "data/maps/SkyPillar_Top/scripts.pory"
	walk_faster_up  @ Fly up
# 162 "data/maps/SkyPillar_Top/scripts.pory"
	slide_up
# 163 "data/maps/SkyPillar_Top/scripts.pory"
	slide_up
# 164 "data/maps/SkyPillar_Top/scripts.pory"
	slide_up
# 165 "data/maps/SkyPillar_Top/scripts.pory"
	slide_up
# 166 "data/maps/SkyPillar_Top/scripts.pory"
	slide_up
# 167 "data/maps/SkyPillar_Top/scripts.pory"
	slide_up
# 168 "data/maps/SkyPillar_Top/scripts.pory"
	step_end
# 169 "data/maps/SkyPillar_Top/scripts.pory"

# 170 "data/maps/SkyPillar_Top/scripts.pory"
SkyPillar_Top_Movement_CameraPanUp:
# 171 "data/maps/SkyPillar_Top/scripts.pory"
	walk_slow_up
# 172 "data/maps/SkyPillar_Top/scripts.pory"
	walk_slow_up
# 173 "data/maps/SkyPillar_Top/scripts.pory"
	walk_slow_up
# 174 "data/maps/SkyPillar_Top/scripts.pory"
	step_end
# 175 "data/maps/SkyPillar_Top/scripts.pory"

# 176 "data/maps/SkyPillar_Top/scripts.pory"
SkyPillar_Top_Movement_CameraPanDown:
# 177 "data/maps/SkyPillar_Top/scripts.pory"
	walk_slow_down
# 178 "data/maps/SkyPillar_Top/scripts.pory"
	walk_slow_down
# 179 "data/maps/SkyPillar_Top/scripts.pory"
	walk_slow_down
# 180 "data/maps/SkyPillar_Top/scripts.pory"
	step_end
# 181 "data/maps/SkyPillar_Top/scripts.pory"

# 182 "data/maps/SkyPillar_Top/scripts.pory"
SkyPillar_Top_Text_RayquazaFlewOff:
# 183 "data/maps/SkyPillar_Top/scripts.pory"
	.string "The awakened RAYQUAZA flew off…$"
