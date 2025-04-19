# 1 "data/maps/FarawayIsland_Interior/scripts.pory"

# 2 "data/maps/FarawayIsland_Interior/scripts.pory"
@ Note: LOCALID_FARAWAY_ISLAND_MEW is a local id for this map used elsewhere. It's defined in event_objects.h
# 3 "data/maps/FarawayIsland_Interior/scripts.pory"

# 4 "data/maps/FarawayIsland_Interior/scripts.pory"
FarawayIsland_Interior_MapScripts::
# 5 "data/maps/FarawayIsland_Interior/scripts.pory"
	map_script MAP_SCRIPT_ON_RESUME, FarawayIsland_Interior_OnResume
# 6 "data/maps/FarawayIsland_Interior/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, FarawayIsland_Interior_OnTransition
# 7 "data/maps/FarawayIsland_Interior/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, FarawayIsland_Interior_OnFrame
# 8 "data/maps/FarawayIsland_Interior/scripts.pory"
	map_script MAP_SCRIPT_ON_RETURN_TO_FIELD, FarawayIsland_Interior_OnReturnToField
# 9 "data/maps/FarawayIsland_Interior/scripts.pory"
	.byte 0
# 10 "data/maps/FarawayIsland_Interior/scripts.pory"

# 11 "data/maps/FarawayIsland_Interior/scripts.pory"
FarawayIsland_Interior_OnReturnToField:
# 12 "data/maps/FarawayIsland_Interior/scripts.pory"
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, FarawayIsland_Interior_EventScript_TrySetMewAboveGrass
# 13 "data/maps/FarawayIsland_Interior/scripts.pory"
	end
# 14 "data/maps/FarawayIsland_Interior/scripts.pory"

# 15 "data/maps/FarawayIsland_Interior/scripts.pory"
FarawayIsland_Interior_EventScript_TrySetMewAboveGrass::
# 16 "data/maps/FarawayIsland_Interior/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 17 "data/maps/FarawayIsland_Interior/scripts.pory"
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, FarawayIsland_Interior_EventScript_SetMewAboveGrass
# 18 "data/maps/FarawayIsland_Interior/scripts.pory"
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, FarawayIsland_Interior_EventScript_SetMewAboveGrass
# 19 "data/maps/FarawayIsland_Interior/scripts.pory"
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, FarawayIsland_Interior_EventScript_SetMewAboveGrass
# 20 "data/maps/FarawayIsland_Interior/scripts.pory"
	goto_if_eq VAR_RESULT, B_OUTCOME_MON_TELEPORTED, FarawayIsland_Interior_EventScript_SetMewAboveGrass
# 21 "data/maps/FarawayIsland_Interior/scripts.pory"
	return
# 22 "data/maps/FarawayIsland_Interior/scripts.pory"

# 23 "data/maps/FarawayIsland_Interior/scripts.pory"
FarawayIsland_Interior_EventScript_SetMewAboveGrass::
# 24 "data/maps/FarawayIsland_Interior/scripts.pory"
	setvar VAR_0x8004, 1
# 25 "data/maps/FarawayIsland_Interior/scripts.pory"
	special SetMewAboveGrass
# 26 "data/maps/FarawayIsland_Interior/scripts.pory"
	return
# 27 "data/maps/FarawayIsland_Interior/scripts.pory"

# 28 "data/maps/FarawayIsland_Interior/scripts.pory"
FarawayIsland_Interior_OnResume:
# 29 "data/maps/FarawayIsland_Interior/scripts.pory"
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, FarawayIsland_Interior_EventScript_TryRemoveMew
# 30 "data/maps/FarawayIsland_Interior/scripts.pory"
	end
# 31 "data/maps/FarawayIsland_Interior/scripts.pory"

# 32 "data/maps/FarawayIsland_Interior/scripts.pory"
FarawayIsland_Interior_EventScript_TryRemoveMew::
# 33 "data/maps/FarawayIsland_Interior/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 34 "data/maps/FarawayIsland_Interior/scripts.pory"
	goto_if_ne VAR_RESULT, B_OUTCOME_CAUGHT, Common_EventScript_NopReturn
# 35 "data/maps/FarawayIsland_Interior/scripts.pory"
	removeobject VAR_LAST_TALKED
# 36 "data/maps/FarawayIsland_Interior/scripts.pory"
	return
# 37 "data/maps/FarawayIsland_Interior/scripts.pory"

# 38 "data/maps/FarawayIsland_Interior/scripts.pory"
FarawayIsland_Interior_OnTransition:
# 39 "data/maps/FarawayIsland_Interior/scripts.pory"
	setvar VAR_FARAWAY_ISLAND_STEP_COUNTER, 0
# 40 "data/maps/FarawayIsland_Interior/scripts.pory"
	setvar VAR_TEMP_1, 1
# 41 "data/maps/FarawayIsland_Interior/scripts.pory"
	call_if_unset FLAG_CAUGHT_MEW, FarawayIsland_Interior_EventScript_TryShowMew
# 42 "data/maps/FarawayIsland_Interior/scripts.pory"
	end
# 43 "data/maps/FarawayIsland_Interior/scripts.pory"

# 44 "data/maps/FarawayIsland_Interior/scripts.pory"
FarawayIsland_Interior_EventScript_TryShowMew::
# 45 "data/maps/FarawayIsland_Interior/scripts.pory"
	goto_if_set FLAG_DEFEATED_MEW, Common_EventScript_NopReturn
# 46 "data/maps/FarawayIsland_Interior/scripts.pory"
	clearflag FLAG_HIDE_MEW
# 47 "data/maps/FarawayIsland_Interior/scripts.pory"
	setvar VAR_TEMP_1, 0
# 48 "data/maps/FarawayIsland_Interior/scripts.pory"
	return
# 49 "data/maps/FarawayIsland_Interior/scripts.pory"

# 50 "data/maps/FarawayIsland_Interior/scripts.pory"
FarawayIsland_Interior_OnFrame:
# 51 "data/maps/FarawayIsland_Interior/scripts.pory"
	map_script_2 VAR_TEMP_1, 0, FarawayIsland_Interior_EventScript_FindMew
# 52 "data/maps/FarawayIsland_Interior/scripts.pory"
	.2byte 0
# 53 "data/maps/FarawayIsland_Interior/scripts.pory"

# 54 "data/maps/FarawayIsland_Interior/scripts.pory"
FarawayIsland_Interior_EventScript_FindMew::
# 55 "data/maps/FarawayIsland_Interior/scripts.pory"
	lockall
# 56 "data/maps/FarawayIsland_Interior/scripts.pory"
	playse SE_PIN
# 57 "data/maps/FarawayIsland_Interior/scripts.pory"
	applymovement LOCALID_FARAWAY_ISLAND_MEW, Common_Movement_ExclamationMark
# 58 "data/maps/FarawayIsland_Interior/scripts.pory"
	waitmovement 0
# 59 "data/maps/FarawayIsland_Interior/scripts.pory"
	applymovement LOCALID_FARAWAY_ISLAND_MEW, Common_Movement_Delay48
# 60 "data/maps/FarawayIsland_Interior/scripts.pory"
	waitmovement 0
# 61 "data/maps/FarawayIsland_Interior/scripts.pory"
	applymovement LOCALID_FARAWAY_ISLAND_MEW, FarawayIsland_Interior_Movement_MewMoveAndHide
# 62 "data/maps/FarawayIsland_Interior/scripts.pory"
	waitmovement 0
# 63 "data/maps/FarawayIsland_Interior/scripts.pory"
	copyobjectxytoperm LOCALID_FARAWAY_ISLAND_MEW
# 64 "data/maps/FarawayIsland_Interior/scripts.pory"
	setvar VAR_TEMP_1, 1
# 65 "data/maps/FarawayIsland_Interior/scripts.pory"
	releaseall
# 66 "data/maps/FarawayIsland_Interior/scripts.pory"
	end
# 67 "data/maps/FarawayIsland_Interior/scripts.pory"

# 68 "data/maps/FarawayIsland_Interior/scripts.pory"
FarawayIsland_Interior_Movement_MewMoveAndHide:
# 69 "data/maps/FarawayIsland_Interior/scripts.pory"
	walk_up
# 70 "data/maps/FarawayIsland_Interior/scripts.pory"
	walk_up
# 71 "data/maps/FarawayIsland_Interior/scripts.pory"
	walk_up
# 72 "data/maps/FarawayIsland_Interior/scripts.pory"
	walk_in_place_faster_down
# 73 "data/maps/FarawayIsland_Interior/scripts.pory"
	set_invisible
# 74 "data/maps/FarawayIsland_Interior/scripts.pory"
	step_end
# 75 "data/maps/FarawayIsland_Interior/scripts.pory"

# 76 "data/maps/FarawayIsland_Interior/scripts.pory"
FarawayIsland_Interior_Movement_MewAppear:
# 77 "data/maps/FarawayIsland_Interior/scripts.pory"
	set_visible
# 78 "data/maps/FarawayIsland_Interior/scripts.pory"
	step_end
# 79 "data/maps/FarawayIsland_Interior/scripts.pory"

# 80 "data/maps/FarawayIsland_Interior/scripts.pory"
FarawayIsland_Interior_Movement_MewFloatUpNorth:
# 81 "data/maps/FarawayIsland_Interior/scripts.pory"
	lock_facing_direction
# 82 "data/maps/FarawayIsland_Interior/scripts.pory"
	walk_fast_up
# 83 "data/maps/FarawayIsland_Interior/scripts.pory"
	walk_fast_up
# 84 "data/maps/FarawayIsland_Interior/scripts.pory"
	unlock_facing_direction
# 85 "data/maps/FarawayIsland_Interior/scripts.pory"
	walk_in_place_down
# 86 "data/maps/FarawayIsland_Interior/scripts.pory"
	walk_in_place_down
# 87 "data/maps/FarawayIsland_Interior/scripts.pory"
	step_end
# 88 "data/maps/FarawayIsland_Interior/scripts.pory"

# 89 "data/maps/FarawayIsland_Interior/scripts.pory"
FarawayIsland_Interior_Movement_MewFloatUpSouth:
# 90 "data/maps/FarawayIsland_Interior/scripts.pory"
	lock_facing_direction
# 91 "data/maps/FarawayIsland_Interior/scripts.pory"
	walk_fast_up
# 92 "data/maps/FarawayIsland_Interior/scripts.pory"
	walk_fast_up
# 93 "data/maps/FarawayIsland_Interior/scripts.pory"
	unlock_facing_direction
# 94 "data/maps/FarawayIsland_Interior/scripts.pory"
	walk_in_place_up
# 95 "data/maps/FarawayIsland_Interior/scripts.pory"
	walk_in_place_up
# 96 "data/maps/FarawayIsland_Interior/scripts.pory"
	step_end
# 97 "data/maps/FarawayIsland_Interior/scripts.pory"

# 98 "data/maps/FarawayIsland_Interior/scripts.pory"
FarawayIsland_Interior_Movement_MewFloatUpWest:
# 99 "data/maps/FarawayIsland_Interior/scripts.pory"
	lock_facing_direction
# 100 "data/maps/FarawayIsland_Interior/scripts.pory"
	walk_fast_up
# 101 "data/maps/FarawayIsland_Interior/scripts.pory"
	walk_fast_up
# 102 "data/maps/FarawayIsland_Interior/scripts.pory"
	unlock_facing_direction
# 103 "data/maps/FarawayIsland_Interior/scripts.pory"
	walk_in_place_right
# 104 "data/maps/FarawayIsland_Interior/scripts.pory"
	walk_in_place_right
# 105 "data/maps/FarawayIsland_Interior/scripts.pory"
	step_end
# 106 "data/maps/FarawayIsland_Interior/scripts.pory"

# 107 "data/maps/FarawayIsland_Interior/scripts.pory"
FarawayIsland_Interior_Movement_MewFloatUpEast:
# 108 "data/maps/FarawayIsland_Interior/scripts.pory"
	lock_facing_direction
# 109 "data/maps/FarawayIsland_Interior/scripts.pory"
	walk_fast_up
# 110 "data/maps/FarawayIsland_Interior/scripts.pory"
	walk_fast_up
# 111 "data/maps/FarawayIsland_Interior/scripts.pory"
	unlock_facing_direction
# 112 "data/maps/FarawayIsland_Interior/scripts.pory"
	walk_in_place_left
# 113 "data/maps/FarawayIsland_Interior/scripts.pory"
	walk_in_place_left
# 114 "data/maps/FarawayIsland_Interior/scripts.pory"
	step_end
# 115 "data/maps/FarawayIsland_Interior/scripts.pory"

# 116 "data/maps/FarawayIsland_Interior/scripts.pory"
FarawayIsland_Interior_EventScript_Mew::
# 117 "data/maps/FarawayIsland_Interior/scripts.pory"
	lock
# 118 "data/maps/FarawayIsland_Interior/scripts.pory"
	faceplayer
# 119 "data/maps/FarawayIsland_Interior/scripts.pory"
	applymovement LOCALID_FARAWAY_ISLAND_MEW, FarawayIsland_Interior_Movement_MewAppear
# 120 "data/maps/FarawayIsland_Interior/scripts.pory"
	waitmovement 0
# 121 "data/maps/FarawayIsland_Interior/scripts.pory"
	setvar VAR_0x8004, 0
# 122 "data/maps/FarawayIsland_Interior/scripts.pory"
	special SetMewAboveGrass
# 123 "data/maps/FarawayIsland_Interior/scripts.pory"
	message FarawayIsland_Interior_Text_Mew
# 124 "data/maps/FarawayIsland_Interior/scripts.pory"
	waitse
# 125 "data/maps/FarawayIsland_Interior/scripts.pory"
	playmoncry SPECIES_MEW, CRY_MODE_ENCOUNTER
# 126 "data/maps/FarawayIsland_Interior/scripts.pory"
	call_if_eq VAR_FACING, DIR_NORTH, FarawayIsland_Interior_EventScript_FoundMewNorth
# 127 "data/maps/FarawayIsland_Interior/scripts.pory"
	call_if_eq VAR_FACING, DIR_SOUTH, FarawayIsland_Interior_EventScript_FoundMewSouth
# 128 "data/maps/FarawayIsland_Interior/scripts.pory"
	call_if_eq VAR_FACING, DIR_WEST, FarawayIsland_Interior_EventScript_FoundMewWest
# 129 "data/maps/FarawayIsland_Interior/scripts.pory"
	call_if_eq VAR_FACING, DIR_EAST, FarawayIsland_Interior_EventScript_FoundMewEast
# 130 "data/maps/FarawayIsland_Interior/scripts.pory"
	special DestroyMewEmergingGrassSprite
# 131 "data/maps/FarawayIsland_Interior/scripts.pory"
	delay 40
# 132 "data/maps/FarawayIsland_Interior/scripts.pory"
	waitmoncry
# 133 "data/maps/FarawayIsland_Interior/scripts.pory"
	seteventmon SPECIES_MEW, 30
# 134 "data/maps/FarawayIsland_Interior/scripts.pory"
	setflag FLAG_SYS_CTRL_OBJ_DELETE
# 135 "data/maps/FarawayIsland_Interior/scripts.pory"
	special BattleSetup_StartLegendaryBattle
# 136 "data/maps/FarawayIsland_Interior/scripts.pory"
	waitstate
# 137 "data/maps/FarawayIsland_Interior/scripts.pory"
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
# 138 "data/maps/FarawayIsland_Interior/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 139 "data/maps/FarawayIsland_Interior/scripts.pory"
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, FarawayIsland_Interior_EventScript_MewDefeated
# 140 "data/maps/FarawayIsland_Interior/scripts.pory"
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, FarawayIsland_Interior_EventScript_PlayerOrMewRan
# 141 "data/maps/FarawayIsland_Interior/scripts.pory"
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, FarawayIsland_Interior_EventScript_PlayerOrMewRan
# 142 "data/maps/FarawayIsland_Interior/scripts.pory"
	goto_if_eq VAR_RESULT, B_OUTCOME_MON_TELEPORTED, FarawayIsland_Interior_EventScript_PlayerOrMewRan
# 143 "data/maps/FarawayIsland_Interior/scripts.pory"
	setflag FLAG_CAUGHT_MEW
# 144 "data/maps/FarawayIsland_Interior/scripts.pory"
	release
# 145 "data/maps/FarawayIsland_Interior/scripts.pory"
	end
# 146 "data/maps/FarawayIsland_Interior/scripts.pory"

# 147 "data/maps/FarawayIsland_Interior/scripts.pory"
FarawayIsland_Interior_EventScript_MewDefeated::
# 148 "data/maps/FarawayIsland_Interior/scripts.pory"
	setflag FLAG_DEFEATED_MEW
# 149 "data/maps/FarawayIsland_Interior/scripts.pory"
	setvar VAR_0x8004, SPECIES_MEW
# 150 "data/maps/FarawayIsland_Interior/scripts.pory"
	goto Common_EventScript_LegendaryFlewAway
# 151 "data/maps/FarawayIsland_Interior/scripts.pory"
	end
# 152 "data/maps/FarawayIsland_Interior/scripts.pory"

# 153 "data/maps/FarawayIsland_Interior/scripts.pory"
FarawayIsland_Interior_EventScript_PlayerOrMewRan::
# 154 "data/maps/FarawayIsland_Interior/scripts.pory"
	setvar VAR_0x8004, SPECIES_MEW
# 155 "data/maps/FarawayIsland_Interior/scripts.pory"
	goto Common_EventScript_LegendaryFlewAway
# 156 "data/maps/FarawayIsland_Interior/scripts.pory"
	end
# 157 "data/maps/FarawayIsland_Interior/scripts.pory"

# 158 "data/maps/FarawayIsland_Interior/scripts.pory"
FarawayIsland_Interior_EventScript_FoundMewNorth::
# 159 "data/maps/FarawayIsland_Interior/scripts.pory"
	applymovement LOCALID_FARAWAY_ISLAND_MEW, FarawayIsland_Interior_Movement_MewFloatUpNorth
# 160 "data/maps/FarawayIsland_Interior/scripts.pory"
	waitmovement 0
# 161 "data/maps/FarawayIsland_Interior/scripts.pory"
	return
# 162 "data/maps/FarawayIsland_Interior/scripts.pory"

# 163 "data/maps/FarawayIsland_Interior/scripts.pory"
FarawayIsland_Interior_EventScript_FoundMewSouth::
# 164 "data/maps/FarawayIsland_Interior/scripts.pory"
	applymovement LOCALID_FARAWAY_ISLAND_MEW, FarawayIsland_Interior_Movement_MewFloatUpSouth
# 165 "data/maps/FarawayIsland_Interior/scripts.pory"
	waitmovement 0
# 166 "data/maps/FarawayIsland_Interior/scripts.pory"
	return
# 167 "data/maps/FarawayIsland_Interior/scripts.pory"

# 168 "data/maps/FarawayIsland_Interior/scripts.pory"
FarawayIsland_Interior_EventScript_FoundMewWest::
# 169 "data/maps/FarawayIsland_Interior/scripts.pory"
	applymovement LOCALID_FARAWAY_ISLAND_MEW, FarawayIsland_Interior_Movement_MewFloatUpWest
# 170 "data/maps/FarawayIsland_Interior/scripts.pory"
	waitmovement 0
# 171 "data/maps/FarawayIsland_Interior/scripts.pory"
	return
# 172 "data/maps/FarawayIsland_Interior/scripts.pory"

# 173 "data/maps/FarawayIsland_Interior/scripts.pory"
FarawayIsland_Interior_EventScript_FoundMewEast::
# 174 "data/maps/FarawayIsland_Interior/scripts.pory"
	applymovement LOCALID_FARAWAY_ISLAND_MEW, FarawayIsland_Interior_Movement_MewFloatUpEast
# 175 "data/maps/FarawayIsland_Interior/scripts.pory"
	waitmovement 0
# 176 "data/maps/FarawayIsland_Interior/scripts.pory"
	return
# 177 "data/maps/FarawayIsland_Interior/scripts.pory"

# 178 "data/maps/FarawayIsland_Interior/scripts.pory"
FarawayIsland_Interior_EventScript_HideMewWhenGrassCut::
# 179 "data/maps/FarawayIsland_Interior/scripts.pory"
	lockall
# 180 "data/maps/FarawayIsland_Interior/scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 181 "data/maps/FarawayIsland_Interior/scripts.pory"
	setflag FLAG_HIDE_MEW
# 182 "data/maps/FarawayIsland_Interior/scripts.pory"
	removeobject LOCALID_FARAWAY_ISLAND_MEW
# 183 "data/maps/FarawayIsland_Interior/scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 184 "data/maps/FarawayIsland_Interior/scripts.pory"
	msgbox FarawayIsland_Interior_Text_TheFeelingOfBeingWatchedFaded, MSGBOX_DEFAULT
# 185 "data/maps/FarawayIsland_Interior/scripts.pory"
	closemessage
# 186 "data/maps/FarawayIsland_Interior/scripts.pory"
	releaseall
# 187 "data/maps/FarawayIsland_Interior/scripts.pory"
	end
# 188 "data/maps/FarawayIsland_Interior/scripts.pory"

# 189 "data/maps/FarawayIsland_Interior/scripts.pory"
FarawayIsland_Interior_Text_TheFeelingOfBeingWatchedFaded:
# 190 "data/maps/FarawayIsland_Interior/scripts.pory"
	.string "The feeling of being watched faded…$"
