# 1 "data/maps/SkyPillar_Top/scripts.pory"

# 2 "data/maps/SkyPillar_Top/scripts.pory"
.set LOCALID_RAYQUAZA_SLEEPING, 1
# 3 "data/maps/SkyPillar_Top/scripts.pory"

# 4 "data/maps/SkyPillar_Top/scripts.pory"
SkyPillar_Top_MapScripts::
# 5 "data/maps/SkyPillar_Top/scripts.pory"
	map_script MAP_SCRIPT_ON_RESUME, SkyPillar_Top_OnResume
# 6 "data/maps/SkyPillar_Top/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, SkyPillar_Top_OnTransition
# 7 "data/maps/SkyPillar_Top/scripts.pory"
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, SkyPillar_Top_OnWarp
# 8 "data/maps/SkyPillar_Top/scripts.pory"
	.byte 0
# 9 "data/maps/SkyPillar_Top/scripts.pory"

# 10 "data/maps/SkyPillar_Top/scripts.pory"
SkyPillar_Top_OnResume:
# 11 "data/maps/SkyPillar_Top/scripts.pory"
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, SkyPillar_Top_EventScript_TryRemoveRayquaza
# 12 "data/maps/SkyPillar_Top/scripts.pory"
	end
# 13 "data/maps/SkyPillar_Top/scripts.pory"

# 14 "data/maps/SkyPillar_Top/scripts.pory"
SkyPillar_Top_EventScript_TryRemoveRayquaza::
# 15 "data/maps/SkyPillar_Top/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 16 "data/maps/SkyPillar_Top/scripts.pory"
	goto_if_ne VAR_RESULT, B_OUTCOME_CAUGHT, Common_EventScript_NopReturn
# 17 "data/maps/SkyPillar_Top/scripts.pory"
	removeobject VAR_LAST_TALKED
# 18 "data/maps/SkyPillar_Top/scripts.pory"
	return
# 19 "data/maps/SkyPillar_Top/scripts.pory"

# 20 "data/maps/SkyPillar_Top/scripts.pory"
SkyPillar_Top_OnTransition:
# 21 "data/maps/SkyPillar_Top/scripts.pory"
	call_if_lt VAR_SKY_PILLAR_STATE, 2, SkyPillar_Top_EventScript_SetCleanLayout
# 22 "data/maps/SkyPillar_Top/scripts.pory"
	call_if_ge VAR_SKY_PILLAR_STATE, 2, SkyPillar_Top_EventScript_TryShowRayquaza
# 23 "data/maps/SkyPillar_Top/scripts.pory"
	end
# 24 "data/maps/SkyPillar_Top/scripts.pory"

# 25 "data/maps/SkyPillar_Top/scripts.pory"
SkyPillar_Top_EventScript_SetCleanLayout::
# 26 "data/maps/SkyPillar_Top/scripts.pory"
	setmaplayoutindex LAYOUT_SKY_PILLAR_TOP_CLEAN
# 27 "data/maps/SkyPillar_Top/scripts.pory"
	setobjectmovementtype LOCALID_RAYQUAZA_SLEEPING, MOVEMENT_TYPE_FACE_DOWN
# 28 "data/maps/SkyPillar_Top/scripts.pory"
	return
# 29 "data/maps/SkyPillar_Top/scripts.pory"

# 30 "data/maps/SkyPillar_Top/scripts.pory"
SkyPillar_Top_EventScript_TryShowRayquaza::
# 31 "data/maps/SkyPillar_Top/scripts.pory"
	call_if_unset FLAG_DEFEATED_RAYQUAZA, SkyPillar_Top_EventScript_ShowRayquaza
# 32 "data/maps/SkyPillar_Top/scripts.pory"
	return
# 33 "data/maps/SkyPillar_Top/scripts.pory"

# 34 "data/maps/SkyPillar_Top/scripts.pory"
SkyPillar_Top_EventScript_ShowRayquaza::
# 35 "data/maps/SkyPillar_Top/scripts.pory"
	clearflag FLAG_HIDE_SKY_PILLAR_TOP_RAYQUAZA_STILL
# 36 "data/maps/SkyPillar_Top/scripts.pory"
	return
# 37 "data/maps/SkyPillar_Top/scripts.pory"

# 38 "data/maps/SkyPillar_Top/scripts.pory"
SkyPillar_Top_OnWarp:
# 39 "data/maps/SkyPillar_Top/scripts.pory"
	map_script_2 VAR_SKY_PILLAR_STATE, 0, SkyPillar_Top_EventScript_RayquazaFaceDown
# 40 "data/maps/SkyPillar_Top/scripts.pory"
	.2byte 0
# 41 "data/maps/SkyPillar_Top/scripts.pory"

# 42 "data/maps/SkyPillar_Top/scripts.pory"
SkyPillar_Top_EventScript_RayquazaFaceDown::
# 43 "data/maps/SkyPillar_Top/scripts.pory"
	turnobject LOCALID_RAYQUAZA_SLEEPING, DIR_SOUTH
# 44 "data/maps/SkyPillar_Top/scripts.pory"
	end
# 45 "data/maps/SkyPillar_Top/scripts.pory"

# 46 "data/maps/SkyPillar_Top/scripts.pory"
SkyPillar_Top_EventScript_Rayquaza::
# 47 "data/maps/SkyPillar_Top/scripts.pory"
	lockall
# 48 "data/maps/SkyPillar_Top/scripts.pory"
	waitse
# 49 "data/maps/SkyPillar_Top/scripts.pory"
	playmoncry SPECIES_RAYQUAZA, CRY_MODE_ENCOUNTER
# 50 "data/maps/SkyPillar_Top/scripts.pory"
	delay 40
# 51 "data/maps/SkyPillar_Top/scripts.pory"
	waitmoncry
# 52 "data/maps/SkyPillar_Top/scripts.pory"
	setwildbattle SPECIES_RAYQUAZA, 70
# 53 "data/maps/SkyPillar_Top/scripts.pory"
	setflag FLAG_SYS_CTRL_OBJ_DELETE
# 54 "data/maps/SkyPillar_Top/scripts.pory"
	special BattleSetup_StartLegendaryBattle
# 55 "data/maps/SkyPillar_Top/scripts.pory"
	waitstate
# 56 "data/maps/SkyPillar_Top/scripts.pory"
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
# 57 "data/maps/SkyPillar_Top/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 58 "data/maps/SkyPillar_Top/scripts.pory"
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, SkyPillar_Top_EventScript_DefeatedRayquaza
# 59 "data/maps/SkyPillar_Top/scripts.pory"
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, SkyPillar_Top_EventScript_RanFromRayquaza
# 60 "data/maps/SkyPillar_Top/scripts.pory"
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, SkyPillar_Top_EventScript_RanFromRayquaza
# 61 "data/maps/SkyPillar_Top/scripts.pory"
	setflag FLAG_DEFEATED_RAYQUAZA
# 62 "data/maps/SkyPillar_Top/scripts.pory"
	releaseall
# 63 "data/maps/SkyPillar_Top/scripts.pory"
	end
# 64 "data/maps/SkyPillar_Top/scripts.pory"

# 65 "data/maps/SkyPillar_Top/scripts.pory"
SkyPillar_Top_EventScript_DefeatedRayquaza::
# 66 "data/maps/SkyPillar_Top/scripts.pory"
	setflag FLAG_DEFEATED_RAYQUAZA
# 67 "data/maps/SkyPillar_Top/scripts.pory"
	goto SkyPillar_Top_EventScript_DefeatedRayquaza2
# 68 "data/maps/SkyPillar_Top/scripts.pory"
	end
# 69 "data/maps/SkyPillar_Top/scripts.pory"

# 70 "data/maps/SkyPillar_Top/scripts.pory"
SkyPillar_Top_EventScript_RanFromRayquaza::
# 71 "data/maps/SkyPillar_Top/scripts.pory"
	setvar VAR_0x8004, SPECIES_RAYQUAZA
# 72 "data/maps/SkyPillar_Top/scripts.pory"
	goto SkyPillar_Top_EventScript_RanFromRayquaza2
# 73 "data/maps/SkyPillar_Top/scripts.pory"
	end
# 74 "data/maps/SkyPillar_Top/scripts.pory"

# 75 "data/maps/SkyPillar_Top/scripts.pory"
SkyPillar_Top_EventScript_DefeatedRayquaza2::
# 76 "data/maps/SkyPillar_Top/scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 77 "data/maps/SkyPillar_Top/scripts.pory"
	removeobject VAR_LAST_TALKED
# 78 "data/maps/SkyPillar_Top/scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 79 "data/maps/SkyPillar_Top/scripts.pory"
	releaseall
# 80 "data/maps/SkyPillar_Top/scripts.pory"
	end
# 81 "data/maps/SkyPillar_Top/scripts.pory"

# 82 "data/maps/SkyPillar_Top/scripts.pory"
SkyPillar_Top_EventScript_RanFromRayquaza2::
# 83 "data/maps/SkyPillar_Top/scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 84 "data/maps/SkyPillar_Top/scripts.pory"
	removeobject VAR_LAST_TALKED
# 85 "data/maps/SkyPillar_Top/scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 86 "data/maps/SkyPillar_Top/scripts.pory"
	bufferspeciesname STR_VAR_1, VAR_0x8004
# 87 "data/maps/SkyPillar_Top/scripts.pory"
	msgbox gText_LegendaryFlewAway, MSGBOX_DEFAULT
# 88 "data/maps/SkyPillar_Top/scripts.pory"
	releaseall
# 89 "data/maps/SkyPillar_Top/scripts.pory"
	end
# 90 "data/maps/SkyPillar_Top/scripts.pory"

# 91 "data/maps/SkyPillar_Top/scripts.pory"
SkyPillar_Top_EventScript_AwakenRayquaza::
# 92 "data/maps/SkyPillar_Top/scripts.pory"
	lockall
# 93 "data/maps/SkyPillar_Top/scripts.pory"
	fadeoutbgm 1
# 94 "data/maps/SkyPillar_Top/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
# 95 "data/maps/SkyPillar_Top/scripts.pory"
	waitmovement 0
# 96 "data/maps/SkyPillar_Top/scripts.pory"
	special SpawnCameraObject
# 97 "data/maps/SkyPillar_Top/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, SkyPillar_Top_Movement_CameraPanUp
# 98 "data/maps/SkyPillar_Top/scripts.pory"
	waitmovement 0
# 99 "data/maps/SkyPillar_Top/scripts.pory"
	special RemoveCameraObject
# 100 "data/maps/SkyPillar_Top/scripts.pory"
	applymovement LOCALID_RAYQUAZA_SLEEPING, SkyPillar_Top_Movement_RayquazaStir
# 101 "data/maps/SkyPillar_Top/scripts.pory"
	waitmovement 0
# 102 "data/maps/SkyPillar_Top/scripts.pory"
	waitse
# 103 "data/maps/SkyPillar_Top/scripts.pory"
	playmoncry SPECIES_RAYQUAZA, CRY_MODE_ENCOUNTER
# 104 "data/maps/SkyPillar_Top/scripts.pory"
	setvar VAR_0x8004, 1  @ vertical pan
# 105 "data/maps/SkyPillar_Top/scripts.pory"
	setvar VAR_0x8005, 1  @ horizontal pan
# 106 "data/maps/SkyPillar_Top/scripts.pory"
	setvar VAR_0x8006, 8  @ num shakes
# 107 "data/maps/SkyPillar_Top/scripts.pory"
	setvar VAR_0x8007, 3  @ shake delay
# 108 "data/maps/SkyPillar_Top/scripts.pory"
	special ShakeCamera
# 109 "data/maps/SkyPillar_Top/scripts.pory"
	waitstate
# 110 "data/maps/SkyPillar_Top/scripts.pory"
	waitse
# 111 "data/maps/SkyPillar_Top/scripts.pory"
	playmoncry SPECIES_RAYQUAZA, CRY_MODE_ENCOUNTER
# 112 "data/maps/SkyPillar_Top/scripts.pory"
	setvar VAR_0x8004, 1  @ vertical pan
# 113 "data/maps/SkyPillar_Top/scripts.pory"
	setvar VAR_0x8005, 2  @ horizontal pan
# 114 "data/maps/SkyPillar_Top/scripts.pory"
	setvar VAR_0x8006, 8  @ num shakes
# 115 "data/maps/SkyPillar_Top/scripts.pory"
	setvar VAR_0x8007, 5  @ shake delay
# 116 "data/maps/SkyPillar_Top/scripts.pory"
	special ShakeCamera
# 117 "data/maps/SkyPillar_Top/scripts.pory"
	waitstate
# 118 "data/maps/SkyPillar_Top/scripts.pory"
	waitmoncry
# 119 "data/maps/SkyPillar_Top/scripts.pory"
	applymovement LOCALID_RAYQUAZA_SLEEPING, SkyPillar_Top_Movement_RayquazaFlyOff
# 120 "data/maps/SkyPillar_Top/scripts.pory"
	waitmovement 0
# 121 "data/maps/SkyPillar_Top/scripts.pory"
	removeobject LOCALID_RAYQUAZA_SLEEPING
# 122 "data/maps/SkyPillar_Top/scripts.pory"
	msgbox SkyPillar_Top_Text_RayquazaFlewOff, MSGBOX_DEFAULT
# 123 "data/maps/SkyPillar_Top/scripts.pory"
	closemessage
# 124 "data/maps/SkyPillar_Top/scripts.pory"
	delay 20
# 125 "data/maps/SkyPillar_Top/scripts.pory"
	fadeinbgm 1
# 126 "data/maps/SkyPillar_Top/scripts.pory"
	special SpawnCameraObject
# 127 "data/maps/SkyPillar_Top/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, SkyPillar_Top_Movement_CameraPanDown
# 128 "data/maps/SkyPillar_Top/scripts.pory"
	waitmovement 0
# 129 "data/maps/SkyPillar_Top/scripts.pory"
	special RemoveCameraObject
# 130 "data/maps/SkyPillar_Top/scripts.pory"
	setvar VAR_SOOTOPOLIS_CITY_STATE, 5
# 131 "data/maps/SkyPillar_Top/scripts.pory"
	setvar VAR_SKY_PILLAR_STATE, 1
# 132 "data/maps/SkyPillar_Top/scripts.pory"
	setvar VAR_SKY_PILLAR_RAYQUAZA_CRY_DONE, 1
# 133 "data/maps/SkyPillar_Top/scripts.pory"
	releaseall
# 134 "data/maps/SkyPillar_Top/scripts.pory"
	end
# 135 "data/maps/SkyPillar_Top/scripts.pory"

# 136 "data/maps/SkyPillar_Top/scripts.pory"
@ Rayquaza has unusual movement frames
# 137 "data/maps/SkyPillar_Top/scripts.pory"
@ See comments, or sAnimTable_Rayquaza
# 138 "data/maps/SkyPillar_Top/scripts.pory"
SkyPillar_Top_Movement_RayquazaStir:
# 139 "data/maps/SkyPillar_Top/scripts.pory"
	delay_16
# 140 "data/maps/SkyPillar_Top/scripts.pory"
	walk_in_place_fast_left  @ Coiled, awake
# 141 "data/maps/SkyPillar_Top/scripts.pory"
	delay_16
# 142 "data/maps/SkyPillar_Top/scripts.pory"
	delay_16
# 143 "data/maps/SkyPillar_Top/scripts.pory"
	delay_16
# 144 "data/maps/SkyPillar_Top/scripts.pory"
	delay_16
# 145 "data/maps/SkyPillar_Top/scripts.pory"
	delay_16
# 146 "data/maps/SkyPillar_Top/scripts.pory"
	walk_in_place_left  @ Coiled, mouth open
# 147 "data/maps/SkyPillar_Top/scripts.pory"
	delay_16
# 148 "data/maps/SkyPillar_Top/scripts.pory"
	walk_in_place_right  @ Normal, awake
# 149 "data/maps/SkyPillar_Top/scripts.pory"
	delay_16
# 150 "data/maps/SkyPillar_Top/scripts.pory"
	delay_16
# 151 "data/maps/SkyPillar_Top/scripts.pory"
	delay_16
# 152 "data/maps/SkyPillar_Top/scripts.pory"
	delay_16
# 153 "data/maps/SkyPillar_Top/scripts.pory"
	delay_16
# 154 "data/maps/SkyPillar_Top/scripts.pory"
	delay_16
# 155 "data/maps/SkyPillar_Top/scripts.pory"
	step_end
# 156 "data/maps/SkyPillar_Top/scripts.pory"

# 157 "data/maps/SkyPillar_Top/scripts.pory"
SkyPillar_Top_Movement_RayquazaFlyOff:
# 158 "data/maps/SkyPillar_Top/scripts.pory"
	delay_16
# 159 "data/maps/SkyPillar_Top/scripts.pory"
	walk_in_place_down  @ Coiled, asleep
# 160 "data/maps/SkyPillar_Top/scripts.pory"
	delay_8
# 161 "data/maps/SkyPillar_Top/scripts.pory"
	walk_in_place_right  @ Normal, awake
# 162 "data/maps/SkyPillar_Top/scripts.pory"
	delay_8
# 163 "data/maps/SkyPillar_Top/scripts.pory"
	walk_faster_up  @ Fly up
# 164 "data/maps/SkyPillar_Top/scripts.pory"
	slide_up
# 165 "data/maps/SkyPillar_Top/scripts.pory"
	slide_up
# 166 "data/maps/SkyPillar_Top/scripts.pory"
	slide_up
# 167 "data/maps/SkyPillar_Top/scripts.pory"
	slide_up
# 168 "data/maps/SkyPillar_Top/scripts.pory"
	slide_up
# 169 "data/maps/SkyPillar_Top/scripts.pory"
	slide_up
# 170 "data/maps/SkyPillar_Top/scripts.pory"
	step_end
# 171 "data/maps/SkyPillar_Top/scripts.pory"

# 172 "data/maps/SkyPillar_Top/scripts.pory"
SkyPillar_Top_Movement_CameraPanUp:
# 173 "data/maps/SkyPillar_Top/scripts.pory"
	walk_slow_up
# 174 "data/maps/SkyPillar_Top/scripts.pory"
	walk_slow_up
# 175 "data/maps/SkyPillar_Top/scripts.pory"
	walk_slow_up
# 176 "data/maps/SkyPillar_Top/scripts.pory"
	step_end
# 177 "data/maps/SkyPillar_Top/scripts.pory"

# 178 "data/maps/SkyPillar_Top/scripts.pory"
SkyPillar_Top_Movement_CameraPanDown:
# 179 "data/maps/SkyPillar_Top/scripts.pory"
	walk_slow_down
# 180 "data/maps/SkyPillar_Top/scripts.pory"
	walk_slow_down
# 181 "data/maps/SkyPillar_Top/scripts.pory"
	walk_slow_down
# 182 "data/maps/SkyPillar_Top/scripts.pory"
	step_end
# 183 "data/maps/SkyPillar_Top/scripts.pory"

# 184 "data/maps/SkyPillar_Top/scripts.pory"
SkyPillar_Top_Text_RayquazaFlewOff:
# 185 "data/maps/SkyPillar_Top/scripts.pory"
	.string "The awakened RAYQUAZA flew off…$"
