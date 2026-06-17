# 1 "data/maps/PalletTown_Frlg/scripts.pory"

# 2 "data/maps/PalletTown_Frlg/scripts.pory"
.equ SIGN_LADY_READY, VAR_TEMP_2
# 3 "data/maps/PalletTown_Frlg/scripts.pory"

# 4 "data/maps/PalletTown_Frlg/scripts.pory"
PalletTown_Frlg_MapScripts::
# 5 "data/maps/PalletTown_Frlg/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, PalletTown_OnTransition
# 6 "data/maps/PalletTown_Frlg/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, PalletTown_OnFrame
# 7 "data/maps/PalletTown_Frlg/scripts.pory"
	.byte 0
# 8 "data/maps/PalletTown_Frlg/scripts.pory"

# 9 "data/maps/PalletTown_Frlg/scripts.pory"
PalletTown_OnTransition::
# 10 "data/maps/PalletTown_Frlg/scripts.pory"
	setworldmapflag FLAG_WORLD_MAP_PALLET_TOWN
# 11 "data/maps/PalletTown_Frlg/scripts.pory"
	call_if_set FLAG_PALLET_LADY_NOT_BLOCKING_SIGN, PalletTown_EventScript_TryReadySignLady
# 12 "data/maps/PalletTown_Frlg/scripts.pory"
	call_if_eq VAR_MAP_SCENE_PALLET_TOWN_SIGN_LADY, 0, PalletTown_EventScript_SetSignLadyPos
# 13 "data/maps/PalletTown_Frlg/scripts.pory"
	call_if_eq VAR_MAP_SCENE_PALLET_TOWN_SIGN_LADY, 1, PalletTown_EventScript_SetSignLadyDone
# 14 "data/maps/PalletTown_Frlg/scripts.pory"
	end
# 15 "data/maps/PalletTown_Frlg/scripts.pory"

# 16 "data/maps/PalletTown_Frlg/scripts.pory"
PalletTown_EventScript_TryReadySignLady::
# 17 "data/maps/PalletTown_Frlg/scripts.pory"
	goto_if_unset FLAG_OPENED_START_MENU, Common_EventScript_NopReturn
# 18 "data/maps/PalletTown_Frlg/scripts.pory"
	goto_if_ge VAR_MAP_SCENE_PALLET_TOWN_SIGN_LADY, 1, Common_EventScript_NopReturn
# 19 "data/maps/PalletTown_Frlg/scripts.pory"
	setvar VAR_MAP_SCENE_PALLET_TOWN_SIGN_LADY, 1
# 20 "data/maps/PalletTown_Frlg/scripts.pory"
	return
# 21 "data/maps/PalletTown_Frlg/scripts.pory"

# 22 "data/maps/PalletTown_Frlg/scripts.pory"
PalletTown_EventScript_SetSignLadyDone::
# 23 "data/maps/PalletTown_Frlg/scripts.pory"
	setvar VAR_MAP_SCENE_PALLET_TOWN_SIGN_LADY, 2
# 24 "data/maps/PalletTown_Frlg/scripts.pory"
	return
# 25 "data/maps/PalletTown_Frlg/scripts.pory"

# 26 "data/maps/PalletTown_Frlg/scripts.pory"
PalletTown_EventScript_SetSignLadyPos::
# 27 "data/maps/PalletTown_Frlg/scripts.pory"
	goto_if_set FLAG_PALLET_LADY_NOT_BLOCKING_SIGN, PalletTown_EventScript_MoveSignLadyToRouteEntrance
# 28 "data/maps/PalletTown_Frlg/scripts.pory"
	setobjectxyperm LOCALID_PALLET_SIGN_LADY, 5, 15
# 29 "data/maps/PalletTown_Frlg/scripts.pory"
	setobjectmovementtype LOCALID_PALLET_SIGN_LADY, MOVEMENT_TYPE_FACE_UP
# 30 "data/maps/PalletTown_Frlg/scripts.pory"
	return
# 31 "data/maps/PalletTown_Frlg/scripts.pory"

# 32 "data/maps/PalletTown_Frlg/scripts.pory"
PalletTown_EventScript_MoveSignLadyToRouteEntrance::
# 33 "data/maps/PalletTown_Frlg/scripts.pory"
	setobjectxyperm LOCALID_PALLET_SIGN_LADY, 12, 2
# 34 "data/maps/PalletTown_Frlg/scripts.pory"
	setobjectmovementtype LOCALID_PALLET_SIGN_LADY, MOVEMENT_TYPE_FACE_DOWN
# 35 "data/maps/PalletTown_Frlg/scripts.pory"
	setvar SIGN_LADY_READY, TRUE
# 36 "data/maps/PalletTown_Frlg/scripts.pory"
	return
# 37 "data/maps/PalletTown_Frlg/scripts.pory"

# 38 "data/maps/PalletTown_Frlg/scripts.pory"
PalletTown_OnFrame::
# 39 "data/maps/PalletTown_Frlg/scripts.pory"
	map_script_2 VAR_MAP_SCENE_PALLET_TOWN_OAK, 2, PalletTown_EventScript_OakRatingScene
# 40 "data/maps/PalletTown_Frlg/scripts.pory"
	.2byte 0
# 41 "data/maps/PalletTown_Frlg/scripts.pory"

# 42 "data/maps/PalletTown_Frlg/scripts.pory"
@ Oak approaches player after exiting their house post Elite Four to check if they should receieve the National Dex
# 43 "data/maps/PalletTown_Frlg/scripts.pory"
PalletTown_EventScript_OakRatingScene::
# 44 "data/maps/PalletTown_Frlg/scripts.pory"
	lockall
# 45 "data/maps/PalletTown_Frlg/scripts.pory"
	textcolor NPC_TEXT_COLOR_MALE
# 46 "data/maps/PalletTown_Frlg/scripts.pory"
	setobjectxyperm LOCALID_PALLET_PROF_OAK, 14, 14
# 47 "data/maps/PalletTown_Frlg/scripts.pory"
	setobjectmovementtype LOCALID_PALLET_PROF_OAK, MOVEMENT_TYPE_FACE_LEFT
# 48 "data/maps/PalletTown_Frlg/scripts.pory"
	addobject LOCALID_PALLET_PROF_OAK
# 49 "data/maps/PalletTown_Frlg/scripts.pory"
	applymovement LOCALID_PALLET_PROF_OAK, PalletTown_Movement_OakWalkToPlayersDoor
# 50 "data/maps/PalletTown_Frlg/scripts.pory"
	waitmovement 0
# 51 "data/maps/PalletTown_Frlg/scripts.pory"
	goto_if_unset FLAG_WORLD_MAP_ONE_ISLAND, PalletTown_EventScript_NotBeenToOneIslandYet
# 52 "data/maps/PalletTown_Frlg/scripts.pory"
	msgbox PalletTown_Text_OakLetMeSeePokedex
# 53 "data/maps/PalletTown_Frlg/scripts.pory"
	setvar VAR_0x8004, 0
# 54 "data/maps/PalletTown_Frlg/scripts.pory"
	specialvar VAR_RESULT, GetFrlgPokedexCount
# 55 "data/maps/PalletTown_Frlg/scripts.pory"
	copyvar VAR_0x8008, VAR_0x8005
# 56 "data/maps/PalletTown_Frlg/scripts.pory"
	copyvar VAR_0x8009, VAR_0x8006
# 57 "data/maps/PalletTown_Frlg/scripts.pory"
	buffernumberstring STR_VAR_1, VAR_0x8008
# 58 "data/maps/PalletTown_Frlg/scripts.pory"
	buffernumberstring STR_VAR_2, VAR_0x8009
# 59 "data/maps/PalletTown_Frlg/scripts.pory"
	goto_if_lt VAR_0x8009, 60, PalletTown_EventScript_NotEnoughMonsForNationalDex
# 60 "data/maps/PalletTown_Frlg/scripts.pory"
	msgbox PalletTown_Text_CaughtXImpressiveFollowMe
# 61 "data/maps/PalletTown_Frlg/scripts.pory"
	closemessage
# 62 "data/maps/PalletTown_Frlg/scripts.pory"
	playbgm MUS_FOLLOW_ME, 0
# 63 "data/maps/PalletTown_Frlg/scripts.pory"
	applymovement LOCALID_PLAYER, PalletTown_Movement_PlayerWalkToLabFromHouse
# 64 "data/maps/PalletTown_Frlg/scripts.pory"
	applymovement LOCALID_PALLET_PROF_OAK, PalletTown_Movement_OakWalkToLabFromHouse
# 65 "data/maps/PalletTown_Frlg/scripts.pory"
	waitmovement 0
# 66 "data/maps/PalletTown_Frlg/scripts.pory"
	opendoor 16, 13
# 67 "data/maps/PalletTown_Frlg/scripts.pory"
	waitdooranim
# 68 "data/maps/PalletTown_Frlg/scripts.pory"
	applymovement LOCALID_PALLET_PROF_OAK, PalletTown_Movement_OakEnterLab
# 69 "data/maps/PalletTown_Frlg/scripts.pory"
	applymovement LOCALID_PLAYER, PalletTown_Movement_PlayerEnterLab
# 70 "data/maps/PalletTown_Frlg/scripts.pory"
	waitmovement 0
# 71 "data/maps/PalletTown_Frlg/scripts.pory"
	closedoor 16, 13
# 72 "data/maps/PalletTown_Frlg/scripts.pory"
	waitdooranim
# 73 "data/maps/PalletTown_Frlg/scripts.pory"
	setvar VAR_MAP_SCENE_PALLET_TOWN_PROFESSOR_OAKS_LAB, 7
# 74 "data/maps/PalletTown_Frlg/scripts.pory"
	setvar VAR_MAP_SCENE_PALLET_TOWN_OAK, 3
# 75 "data/maps/PalletTown_Frlg/scripts.pory"
	setflag FLAG_HIDE_OAK_IN_PALLET_TOWN
# 76 "data/maps/PalletTown_Frlg/scripts.pory"
	warp MAP_PALLET_TOWN_PROFESSOR_OAKS_LAB, 6, 12
# 77 "data/maps/PalletTown_Frlg/scripts.pory"
	waitstate
# 78 "data/maps/PalletTown_Frlg/scripts.pory"
	releaseall
# 79 "data/maps/PalletTown_Frlg/scripts.pory"
	end
# 80 "data/maps/PalletTown_Frlg/scripts.pory"

# 81 "data/maps/PalletTown_Frlg/scripts.pory"
PalletTown_EventScript_EndOakRatingScene::
# 82 "data/maps/PalletTown_Frlg/scripts.pory"
	closemessage
# 83 "data/maps/PalletTown_Frlg/scripts.pory"
	applymovement LOCALID_PALLET_PROF_OAK, PalletTown_Movement_OakExit
# 84 "data/maps/PalletTown_Frlg/scripts.pory"
	waitmovement 0
# 85 "data/maps/PalletTown_Frlg/scripts.pory"
	removeobject LOCALID_PALLET_PROF_OAK
# 86 "data/maps/PalletTown_Frlg/scripts.pory"
	setvar VAR_MAP_SCENE_PALLET_TOWN_OAK, 3
# 87 "data/maps/PalletTown_Frlg/scripts.pory"
	releaseall
# 88 "data/maps/PalletTown_Frlg/scripts.pory"
	end
# 89 "data/maps/PalletTown_Frlg/scripts.pory"

# 90 "data/maps/PalletTown_Frlg/scripts.pory"
PalletTown_EventScript_NotEnoughMonsForNationalDex::
# 91 "data/maps/PalletTown_Frlg/scripts.pory"
	msgbox PalletTown_Text_CaughtXPuttingInHonestEffort
# 92 "data/maps/PalletTown_Frlg/scripts.pory"
	goto PalletTown_EventScript_EndOakRatingScene
# 93 "data/maps/PalletTown_Frlg/scripts.pory"
	end
# 94 "data/maps/PalletTown_Frlg/scripts.pory"

# 95 "data/maps/PalletTown_Frlg/scripts.pory"
PalletTown_EventScript_NotBeenToOneIslandYet::
# 96 "data/maps/PalletTown_Frlg/scripts.pory"
	msgbox PalletTown_Text_OakYouEnjoyingTraveling
# 97 "data/maps/PalletTown_Frlg/scripts.pory"
	goto PalletTown_EventScript_EndOakRatingScene
# 98 "data/maps/PalletTown_Frlg/scripts.pory"
	end
# 99 "data/maps/PalletTown_Frlg/scripts.pory"

# 100 "data/maps/PalletTown_Frlg/scripts.pory"
PalletTown_Movement_OakWalkToPlayersDoor::
# 101 "data/maps/PalletTown_Frlg/scripts.pory"
	walk_left
# 102 "data/maps/PalletTown_Frlg/scripts.pory"
	walk_left
# 103 "data/maps/PalletTown_Frlg/scripts.pory"
	walk_left
# 104 "data/maps/PalletTown_Frlg/scripts.pory"
	walk_up
# 105 "data/maps/PalletTown_Frlg/scripts.pory"
	walk_up
# 106 "data/maps/PalletTown_Frlg/scripts.pory"
	walk_up
# 107 "data/maps/PalletTown_Frlg/scripts.pory"
	walk_up
# 108 "data/maps/PalletTown_Frlg/scripts.pory"
	walk_up
# 109 "data/maps/PalletTown_Frlg/scripts.pory"
	walk_left
# 110 "data/maps/PalletTown_Frlg/scripts.pory"
	walk_left
# 111 "data/maps/PalletTown_Frlg/scripts.pory"
	walk_left
# 112 "data/maps/PalletTown_Frlg/scripts.pory"
	walk_left
# 113 "data/maps/PalletTown_Frlg/scripts.pory"
	walk_left
# 114 "data/maps/PalletTown_Frlg/scripts.pory"
	walk_in_place_faster_up
# 115 "data/maps/PalletTown_Frlg/scripts.pory"
	step_end
# 116 "data/maps/PalletTown_Frlg/scripts.pory"

# 117 "data/maps/PalletTown_Frlg/scripts.pory"
PalletTown_Movement_OakExit::
# 118 "data/maps/PalletTown_Frlg/scripts.pory"
	walk_right
# 119 "data/maps/PalletTown_Frlg/scripts.pory"
	walk_right
# 120 "data/maps/PalletTown_Frlg/scripts.pory"
	walk_right
# 121 "data/maps/PalletTown_Frlg/scripts.pory"
	walk_right
# 122 "data/maps/PalletTown_Frlg/scripts.pory"
	walk_right
# 123 "data/maps/PalletTown_Frlg/scripts.pory"
	walk_down
# 124 "data/maps/PalletTown_Frlg/scripts.pory"
	walk_down
# 125 "data/maps/PalletTown_Frlg/scripts.pory"
	walk_down
# 126 "data/maps/PalletTown_Frlg/scripts.pory"
	walk_down
# 127 "data/maps/PalletTown_Frlg/scripts.pory"
	walk_down
# 128 "data/maps/PalletTown_Frlg/scripts.pory"
	walk_right
# 129 "data/maps/PalletTown_Frlg/scripts.pory"
	walk_right
# 130 "data/maps/PalletTown_Frlg/scripts.pory"
	walk_right
# 131 "data/maps/PalletTown_Frlg/scripts.pory"
	step_end
# 132 "data/maps/PalletTown_Frlg/scripts.pory"

# 133 "data/maps/PalletTown_Frlg/scripts.pory"
PalletTown_Movement_OakWalkToLabFromHouse::
# 134 "data/maps/PalletTown_Frlg/scripts.pory"
	walk_right
# 135 "data/maps/PalletTown_Frlg/scripts.pory"
	walk_right
# 136 "data/maps/PalletTown_Frlg/scripts.pory"
	walk_right
# 137 "data/maps/PalletTown_Frlg/scripts.pory"
	walk_right
# 138 "data/maps/PalletTown_Frlg/scripts.pory"
	walk_right
# 139 "data/maps/PalletTown_Frlg/scripts.pory"
	walk_down
# 140 "data/maps/PalletTown_Frlg/scripts.pory"
	walk_down
# 141 "data/maps/PalletTown_Frlg/scripts.pory"
	walk_down
# 142 "data/maps/PalletTown_Frlg/scripts.pory"
	walk_down
# 143 "data/maps/PalletTown_Frlg/scripts.pory"
	walk_down
# 144 "data/maps/PalletTown_Frlg/scripts.pory"
	walk_right
# 145 "data/maps/PalletTown_Frlg/scripts.pory"
	walk_right
# 146 "data/maps/PalletTown_Frlg/scripts.pory"
	walk_right
# 147 "data/maps/PalletTown_Frlg/scripts.pory"
	walk_right
# 148 "data/maps/PalletTown_Frlg/scripts.pory"
	walk_right
# 149 "data/maps/PalletTown_Frlg/scripts.pory"
	walk_in_place_faster_up
# 150 "data/maps/PalletTown_Frlg/scripts.pory"
	step_end
# 151 "data/maps/PalletTown_Frlg/scripts.pory"

# 152 "data/maps/PalletTown_Frlg/scripts.pory"
PalletTown_Movement_PlayerWalkToLabFromHouse::
# 153 "data/maps/PalletTown_Frlg/scripts.pory"
	walk_down
# 154 "data/maps/PalletTown_Frlg/scripts.pory"
	walk_right
# 155 "data/maps/PalletTown_Frlg/scripts.pory"
	walk_right
# 156 "data/maps/PalletTown_Frlg/scripts.pory"
	walk_right
# 157 "data/maps/PalletTown_Frlg/scripts.pory"
	walk_right
# 158 "data/maps/PalletTown_Frlg/scripts.pory"
	walk_right
# 159 "data/maps/PalletTown_Frlg/scripts.pory"
	walk_down
# 160 "data/maps/PalletTown_Frlg/scripts.pory"
	walk_down
# 161 "data/maps/PalletTown_Frlg/scripts.pory"
	walk_down
# 162 "data/maps/PalletTown_Frlg/scripts.pory"
	walk_down
# 163 "data/maps/PalletTown_Frlg/scripts.pory"
	walk_down
# 164 "data/maps/PalletTown_Frlg/scripts.pory"
	walk_right
# 165 "data/maps/PalletTown_Frlg/scripts.pory"
	walk_right
# 166 "data/maps/PalletTown_Frlg/scripts.pory"
	walk_right
# 167 "data/maps/PalletTown_Frlg/scripts.pory"
	walk_right
# 168 "data/maps/PalletTown_Frlg/scripts.pory"
	step_end
# 169 "data/maps/PalletTown_Frlg/scripts.pory"

# 170 "data/maps/PalletTown_Frlg/scripts.pory"
PalletTown_EventScript_OakTriggerLeft::
# 171 "data/maps/PalletTown_Frlg/scripts.pory"
	lockall
# 172 "data/maps/PalletTown_Frlg/scripts.pory"
	setvar VAR_TEMP_1, 0
# 173 "data/maps/PalletTown_Frlg/scripts.pory"
	goto PalletTown_EventScript_OakTrigger
# 174 "data/maps/PalletTown_Frlg/scripts.pory"
	end
# 175 "data/maps/PalletTown_Frlg/scripts.pory"

# 176 "data/maps/PalletTown_Frlg/scripts.pory"
PalletTown_EventScript_OakTriggerRight::
# 177 "data/maps/PalletTown_Frlg/scripts.pory"
	lockall
# 178 "data/maps/PalletTown_Frlg/scripts.pory"
	setvar VAR_TEMP_1, 1
# 179 "data/maps/PalletTown_Frlg/scripts.pory"
	goto PalletTown_EventScript_OakTrigger
# 180 "data/maps/PalletTown_Frlg/scripts.pory"
	end
# 181 "data/maps/PalletTown_Frlg/scripts.pory"

# 182 "data/maps/PalletTown_Frlg/scripts.pory"
PalletTown_EventScript_OakTrigger::
# 183 "data/maps/PalletTown_Frlg/scripts.pory"
	famechecker FAMECHECKER_OAK, FCPICKSTATE_COLORED, UpdatePickStateFromSpecialVar8005
# 184 "data/maps/PalletTown_Frlg/scripts.pory"
	textcolor NPC_TEXT_COLOR_MALE
# 185 "data/maps/PalletTown_Frlg/scripts.pory"
	delay 30
# 186 "data/maps/PalletTown_Frlg/scripts.pory"
	playbgm MUS_RG_OAK, 0
# 187 "data/maps/PalletTown_Frlg/scripts.pory"
	message PalletTown_Text_OakDontGoOut
# 188 "data/maps/PalletTown_Frlg/scripts.pory"
	waitmessage
# 189 "data/maps/PalletTown_Frlg/scripts.pory"
	delay 85
# 190 "data/maps/PalletTown_Frlg/scripts.pory"
	closemessage
# 191 "data/maps/PalletTown_Frlg/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterDown
# 192 "data/maps/PalletTown_Frlg/scripts.pory"
	waitmovement 0
# 193 "data/maps/PalletTown_Frlg/scripts.pory"
	playse SE_PIN
# 194 "data/maps/PalletTown_Frlg/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_ExclamationMark
# 195 "data/maps/PalletTown_Frlg/scripts.pory"
	waitmovement 0
# 196 "data/maps/PalletTown_Frlg/scripts.pory"
	delay 30
# 197 "data/maps/PalletTown_Frlg/scripts.pory"
	addobject LOCALID_PALLET_PROF_OAK
# 198 "data/maps/PalletTown_Frlg/scripts.pory"
	call_if_eq VAR_TEMP_1, 0, PalletTown_EventScript_OakEnterLeft
# 199 "data/maps/PalletTown_Frlg/scripts.pory"
	call_if_eq VAR_TEMP_1, 1, PalletTown_EventScript_OakEnterRight
# 200 "data/maps/PalletTown_Frlg/scripts.pory"
	delay 30
# 201 "data/maps/PalletTown_Frlg/scripts.pory"
	msgbox PalletTown_Text_OakGrassUnsafeNeedMon
# 202 "data/maps/PalletTown_Frlg/scripts.pory"
	closemessage
# 203 "data/maps/PalletTown_Frlg/scripts.pory"
	delay 30
# 204 "data/maps/PalletTown_Frlg/scripts.pory"
	call_if_eq VAR_TEMP_1, 0, PalletTown_EventScript_OakLeadPlayerToLabLeft
# 205 "data/maps/PalletTown_Frlg/scripts.pory"
	call_if_eq VAR_TEMP_1, 1, PalletTown_EventScript_OakLeadPlayerToLabRight
# 206 "data/maps/PalletTown_Frlg/scripts.pory"
	opendoor 16, 13
# 207 "data/maps/PalletTown_Frlg/scripts.pory"
	waitdooranim
# 208 "data/maps/PalletTown_Frlg/scripts.pory"
	applymovement LOCALID_PALLET_PROF_OAK, PalletTown_Movement_OakEnterLab
# 209 "data/maps/PalletTown_Frlg/scripts.pory"
	applymovement LOCALID_PLAYER, PalletTown_Movement_PlayerEnterLab
# 210 "data/maps/PalletTown_Frlg/scripts.pory"
	waitmovement 0
# 211 "data/maps/PalletTown_Frlg/scripts.pory"
	closedoor 16, 13
# 212 "data/maps/PalletTown_Frlg/scripts.pory"
	waitdooranim
# 213 "data/maps/PalletTown_Frlg/scripts.pory"
	setvar VAR_MAP_SCENE_PALLET_TOWN_PROFESSOR_OAKS_LAB, 1
# 214 "data/maps/PalletTown_Frlg/scripts.pory"
	clearflag FLAG_HIDE_OAK_IN_HIS_LAB
# 215 "data/maps/PalletTown_Frlg/scripts.pory"
	setvar VAR_MAP_SCENE_PALLET_TOWN_OAK, 1
# 216 "data/maps/PalletTown_Frlg/scripts.pory"
	setflag FLAG_HIDE_OAK_IN_PALLET_TOWN
# 217 "data/maps/PalletTown_Frlg/scripts.pory"
	setflag FLAG_DONT_TRANSITION_MUSIC
# 218 "data/maps/PalletTown_Frlg/scripts.pory"
	warp MAP_PALLET_TOWN_PROFESSOR_OAKS_LAB, 6, 12
# 219 "data/maps/PalletTown_Frlg/scripts.pory"
	waitstate
# 220 "data/maps/PalletTown_Frlg/scripts.pory"
	releaseall
# 221 "data/maps/PalletTown_Frlg/scripts.pory"
	end
# 222 "data/maps/PalletTown_Frlg/scripts.pory"

# 223 "data/maps/PalletTown_Frlg/scripts.pory"
PalletTown_EventScript_OakEnterLeft::
# 224 "data/maps/PalletTown_Frlg/scripts.pory"
	applymovement LOCALID_PALLET_PROF_OAK, PalletTown_Movement_OakEnterLeft
# 225 "data/maps/PalletTown_Frlg/scripts.pory"
	waitmovement 0
# 226 "data/maps/PalletTown_Frlg/scripts.pory"
	return
# 227 "data/maps/PalletTown_Frlg/scripts.pory"

# 228 "data/maps/PalletTown_Frlg/scripts.pory"
PalletTown_EventScript_OakEnterRight::
# 229 "data/maps/PalletTown_Frlg/scripts.pory"
	applymovement LOCALID_PALLET_PROF_OAK, PalletTown_Movement_OakEnterRight
# 230 "data/maps/PalletTown_Frlg/scripts.pory"
	waitmovement 0
# 231 "data/maps/PalletTown_Frlg/scripts.pory"
	return
# 232 "data/maps/PalletTown_Frlg/scripts.pory"

# 233 "data/maps/PalletTown_Frlg/scripts.pory"
PalletTown_EventScript_OakLeadPlayerToLabLeft::
# 234 "data/maps/PalletTown_Frlg/scripts.pory"
	applymovement LOCALID_PALLET_PROF_OAK, PalletTown_Movement_OakWalkToLabLeft
# 235 "data/maps/PalletTown_Frlg/scripts.pory"
	applymovement LOCALID_PLAYER, PalletTown_Movement_PlayerWalkToLabLeft
# 236 "data/maps/PalletTown_Frlg/scripts.pory"
	waitmovement 0
# 237 "data/maps/PalletTown_Frlg/scripts.pory"
	return
# 238 "data/maps/PalletTown_Frlg/scripts.pory"

# 239 "data/maps/PalletTown_Frlg/scripts.pory"
PalletTown_EventScript_OakLeadPlayerToLabRight::
# 240 "data/maps/PalletTown_Frlg/scripts.pory"
	applymovement LOCALID_PALLET_PROF_OAK, PalletTown_Movement_OakWalkToLabRight
# 241 "data/maps/PalletTown_Frlg/scripts.pory"
	applymovement LOCALID_PLAYER, PalletTown_Movement_PlayerWalkToLabRight
# 242 "data/maps/PalletTown_Frlg/scripts.pory"
	waitmovement 0
# 243 "data/maps/PalletTown_Frlg/scripts.pory"
	return
# 244 "data/maps/PalletTown_Frlg/scripts.pory"

# 245 "data/maps/PalletTown_Frlg/scripts.pory"
PalletTown_Movement_OakEnterLeft::
# 246 "data/maps/PalletTown_Frlg/scripts.pory"
	walk_up
# 247 "data/maps/PalletTown_Frlg/scripts.pory"
	walk_up
# 248 "data/maps/PalletTown_Frlg/scripts.pory"
	walk_right
# 249 "data/maps/PalletTown_Frlg/scripts.pory"
	walk_up
# 250 "data/maps/PalletTown_Frlg/scripts.pory"
	walk_up
# 251 "data/maps/PalletTown_Frlg/scripts.pory"
	walk_right
# 252 "data/maps/PalletTown_Frlg/scripts.pory"
	walk_up
# 253 "data/maps/PalletTown_Frlg/scripts.pory"
	walk_up
# 254 "data/maps/PalletTown_Frlg/scripts.pory"
	step_end
# 255 "data/maps/PalletTown_Frlg/scripts.pory"

# 256 "data/maps/PalletTown_Frlg/scripts.pory"
PalletTown_Movement_OakEnterRight::
# 257 "data/maps/PalletTown_Frlg/scripts.pory"
	walk_right
# 258 "data/maps/PalletTown_Frlg/scripts.pory"
	walk_up
# 259 "data/maps/PalletTown_Frlg/scripts.pory"
	walk_up
# 260 "data/maps/PalletTown_Frlg/scripts.pory"
	walk_right
# 261 "data/maps/PalletTown_Frlg/scripts.pory"
	walk_up
# 262 "data/maps/PalletTown_Frlg/scripts.pory"
	walk_up
# 263 "data/maps/PalletTown_Frlg/scripts.pory"
	walk_right
# 264 "data/maps/PalletTown_Frlg/scripts.pory"
	walk_up
# 265 "data/maps/PalletTown_Frlg/scripts.pory"
	walk_up
# 266 "data/maps/PalletTown_Frlg/scripts.pory"
	step_end
# 267 "data/maps/PalletTown_Frlg/scripts.pory"

# 268 "data/maps/PalletTown_Frlg/scripts.pory"
	.macro walk_to_lab
# 269 "data/maps/PalletTown_Frlg/scripts.pory"
	walk_left
# 270 "data/maps/PalletTown_Frlg/scripts.pory"
	walk_down
# 271 "data/maps/PalletTown_Frlg/scripts.pory"
	walk_down
# 272 "data/maps/PalletTown_Frlg/scripts.pory"
	walk_down
# 273 "data/maps/PalletTown_Frlg/scripts.pory"
	walk_down
# 274 "data/maps/PalletTown_Frlg/scripts.pory"
	walk_down
# 275 "data/maps/PalletTown_Frlg/scripts.pory"
	walk_down
# 276 "data/maps/PalletTown_Frlg/scripts.pory"
	walk_down
# 277 "data/maps/PalletTown_Frlg/scripts.pory"
	walk_down
# 278 "data/maps/PalletTown_Frlg/scripts.pory"
	walk_down
# 279 "data/maps/PalletTown_Frlg/scripts.pory"
	walk_down
# 280 "data/maps/PalletTown_Frlg/scripts.pory"
	walk_down
# 281 "data/maps/PalletTown_Frlg/scripts.pory"
	walk_right
# 282 "data/maps/PalletTown_Frlg/scripts.pory"
	walk_right
# 283 "data/maps/PalletTown_Frlg/scripts.pory"
	walk_right
# 284 "data/maps/PalletTown_Frlg/scripts.pory"
	walk_right
# 285 "data/maps/PalletTown_Frlg/scripts.pory"
	.endm
# 286 "data/maps/PalletTown_Frlg/scripts.pory"

# 287 "data/maps/PalletTown_Frlg/scripts.pory"
PalletTown_Movement_OakWalkToLabLeft::
# 288 "data/maps/PalletTown_Frlg/scripts.pory"
	walk_down
# 289 "data/maps/PalletTown_Frlg/scripts.pory"
	walk_to_lab
# 290 "data/maps/PalletTown_Frlg/scripts.pory"
	walk_right
# 291 "data/maps/PalletTown_Frlg/scripts.pory"
	walk_in_place_faster_up
# 292 "data/maps/PalletTown_Frlg/scripts.pory"
	step_end
# 293 "data/maps/PalletTown_Frlg/scripts.pory"

# 294 "data/maps/PalletTown_Frlg/scripts.pory"
PalletTown_Movement_OakWalkToLabRight::
# 295 "data/maps/PalletTown_Frlg/scripts.pory"
	walk_down
# 296 "data/maps/PalletTown_Frlg/scripts.pory"
	walk_left
# 297 "data/maps/PalletTown_Frlg/scripts.pory"
	walk_to_lab
# 298 "data/maps/PalletTown_Frlg/scripts.pory"
	walk_right
# 299 "data/maps/PalletTown_Frlg/scripts.pory"
	walk_in_place_faster_up
# 300 "data/maps/PalletTown_Frlg/scripts.pory"
	step_end
# 301 "data/maps/PalletTown_Frlg/scripts.pory"

# 302 "data/maps/PalletTown_Frlg/scripts.pory"
PalletTown_Movement_OakEnterLab::
# 303 "data/maps/PalletTown_Frlg/scripts.pory"
	walk_up
# 304 "data/maps/PalletTown_Frlg/scripts.pory"
	set_invisible
# 305 "data/maps/PalletTown_Frlg/scripts.pory"
	step_end
# 306 "data/maps/PalletTown_Frlg/scripts.pory"

# 307 "data/maps/PalletTown_Frlg/scripts.pory"
PalletTown_Movement_PlayerWalkToLabLeft::
# 308 "data/maps/PalletTown_Frlg/scripts.pory"
	walk_down
# 309 "data/maps/PalletTown_Frlg/scripts.pory"
	walk_down
# 310 "data/maps/PalletTown_Frlg/scripts.pory"
	walk_to_lab
# 311 "data/maps/PalletTown_Frlg/scripts.pory"
	step_end
# 312 "data/maps/PalletTown_Frlg/scripts.pory"

# 313 "data/maps/PalletTown_Frlg/scripts.pory"
PalletTown_Movement_PlayerWalkToLabRight::
# 314 "data/maps/PalletTown_Frlg/scripts.pory"
	walk_down
# 315 "data/maps/PalletTown_Frlg/scripts.pory"
	walk_down
# 316 "data/maps/PalletTown_Frlg/scripts.pory"
	walk_left
# 317 "data/maps/PalletTown_Frlg/scripts.pory"
	walk_to_lab
# 318 "data/maps/PalletTown_Frlg/scripts.pory"
	step_end
# 319 "data/maps/PalletTown_Frlg/scripts.pory"

# 320 "data/maps/PalletTown_Frlg/scripts.pory"
PalletTown_Movement_PlayerEnterLab::
# 321 "data/maps/PalletTown_Frlg/scripts.pory"
	walk_right
# 322 "data/maps/PalletTown_Frlg/scripts.pory"
	walk_up
# 323 "data/maps/PalletTown_Frlg/scripts.pory"
	set_invisible
# 324 "data/maps/PalletTown_Frlg/scripts.pory"
	step_end
# 325 "data/maps/PalletTown_Frlg/scripts.pory"

# 326 "data/maps/PalletTown_Frlg/scripts.pory"
PalletTown_EventScript_SignLady::
# 327 "data/maps/PalletTown_Frlg/scripts.pory"
	lock
# 328 "data/maps/PalletTown_Frlg/scripts.pory"
	goto_if_eq VAR_MAP_SCENE_PALLET_TOWN_SIGN_LADY, 2, PalletTown_EventScript_SignLadyDone
# 329 "data/maps/PalletTown_Frlg/scripts.pory"
	goto_if_eq VAR_MAP_SCENE_PALLET_TOWN_SIGN_LADY, 1, PalletTown_EventScript_SignLadyJustShowedSign
# 330 "data/maps/PalletTown_Frlg/scripts.pory"
	goto_if_eq SIGN_LADY_READY, TRUE, PalletTown_EventScript_SignLadyStartShowSign
# 331 "data/maps/PalletTown_Frlg/scripts.pory"
	goto_if_set FLAG_TEMP_2, PalletTown_EventScript_SignLadyGoReadSign
# 332 "data/maps/PalletTown_Frlg/scripts.pory"
	msgbox PalletTown_Text_HmmIsThatRight
# 333 "data/maps/PalletTown_Frlg/scripts.pory"
	applymovement LOCALID_PALLET_SIGN_LADY, Common_Movement_FacePlayer
# 334 "data/maps/PalletTown_Frlg/scripts.pory"
	waitmovement 0
# 335 "data/maps/PalletTown_Frlg/scripts.pory"
	playse SE_PIN
# 336 "data/maps/PalletTown_Frlg/scripts.pory"
	applymovement LOCALID_PALLET_SIGN_LADY, Common_Movement_ExclamationMark
# 337 "data/maps/PalletTown_Frlg/scripts.pory"
	waitmovement 0
# 338 "data/maps/PalletTown_Frlg/scripts.pory"
	applymovement LOCALID_PALLET_SIGN_LADY, Common_Movement_Delay48
# 339 "data/maps/PalletTown_Frlg/scripts.pory"
	waitmovement 0
# 340 "data/maps/PalletTown_Frlg/scripts.pory"
	msgbox PalletTown_Text_OhLookLook
# 341 "data/maps/PalletTown_Frlg/scripts.pory"
	closemessage
# 342 "data/maps/PalletTown_Frlg/scripts.pory"
	call_if_eq VAR_FACING, DIR_EAST, PalletTown_EventScript_SignLadyMoveOutOfWayRight
# 343 "data/maps/PalletTown_Frlg/scripts.pory"
	call_if_ne VAR_FACING, DIR_EAST, PalletTown_EventScript_SignLadyMoveOutOfWayLeft
# 344 "data/maps/PalletTown_Frlg/scripts.pory"
	copyobjectxytoperm LOCALID_PALLET_SIGN_LADY
# 345 "data/maps/PalletTown_Frlg/scripts.pory"
	setflag FLAG_TEMP_2
# 346 "data/maps/PalletTown_Frlg/scripts.pory"
	release
# 347 "data/maps/PalletTown_Frlg/scripts.pory"
	end
# 348 "data/maps/PalletTown_Frlg/scripts.pory"

# 349 "data/maps/PalletTown_Frlg/scripts.pory"
PalletTown_EventScript_SignLadyMoveOutOfWayRight::
# 350 "data/maps/PalletTown_Frlg/scripts.pory"
	applymovement LOCALID_PALLET_SIGN_LADY, PalletTown_Movement_SignLadyMoveOutOfWayRight
# 351 "data/maps/PalletTown_Frlg/scripts.pory"
	waitmovement 0
# 352 "data/maps/PalletTown_Frlg/scripts.pory"
	return
# 353 "data/maps/PalletTown_Frlg/scripts.pory"

# 354 "data/maps/PalletTown_Frlg/scripts.pory"
PalletTown_EventScript_SignLadyMoveOutOfWayLeft::
# 355 "data/maps/PalletTown_Frlg/scripts.pory"
	applymovement LOCALID_PALLET_SIGN_LADY, PalletTown_Movement_SignLadyMoveOutOfWayLeft
# 356 "data/maps/PalletTown_Frlg/scripts.pory"
	waitmovement 0
# 357 "data/maps/PalletTown_Frlg/scripts.pory"
	return
# 358 "data/maps/PalletTown_Frlg/scripts.pory"

# 359 "data/maps/PalletTown_Frlg/scripts.pory"
PalletTown_EventScript_SignLadyDone::
# 360 "data/maps/PalletTown_Frlg/scripts.pory"
	applymovement LOCALID_PALLET_SIGN_LADY, Common_Movement_FacePlayer
# 361 "data/maps/PalletTown_Frlg/scripts.pory"
	waitmovement 0
# 362 "data/maps/PalletTown_Frlg/scripts.pory"
	msgbox PalletTown_Text_RaisingMonsToo
# 363 "data/maps/PalletTown_Frlg/scripts.pory"
	release
# 364 "data/maps/PalletTown_Frlg/scripts.pory"
	end
# 365 "data/maps/PalletTown_Frlg/scripts.pory"

# 366 "data/maps/PalletTown_Frlg/scripts.pory"
PalletTown_EventScript_SignLadyGoReadSign::
# 367 "data/maps/PalletTown_Frlg/scripts.pory"
	applymovement LOCALID_PALLET_SIGN_LADY, Common_Movement_FacePlayer
# 368 "data/maps/PalletTown_Frlg/scripts.pory"
	waitmovement 0
# 369 "data/maps/PalletTown_Frlg/scripts.pory"
	msgbox PalletTown_Text_ReadItReadIt
# 370 "data/maps/PalletTown_Frlg/scripts.pory"
	release
# 371 "data/maps/PalletTown_Frlg/scripts.pory"
	end
# 372 "data/maps/PalletTown_Frlg/scripts.pory"

# 373 "data/maps/PalletTown_Frlg/scripts.pory"
PalletTown_EventScript_SignLadyJustShowedSign::
# 374 "data/maps/PalletTown_Frlg/scripts.pory"
	applymovement LOCALID_PALLET_SIGN_LADY, Common_Movement_FacePlayer
# 375 "data/maps/PalletTown_Frlg/scripts.pory"
	waitmovement 0
# 376 "data/maps/PalletTown_Frlg/scripts.pory"
	msgbox PalletTown_Text_SignsAreUsefulArentThey
# 377 "data/maps/PalletTown_Frlg/scripts.pory"
	release
# 378 "data/maps/PalletTown_Frlg/scripts.pory"
	end
# 379 "data/maps/PalletTown_Frlg/scripts.pory"

# 380 "data/maps/PalletTown_Frlg/scripts.pory"
PalletTown_Movement_SignLadyMoveOutOfWayRight::
# 381 "data/maps/PalletTown_Frlg/scripts.pory"
	walk_right
# 382 "data/maps/PalletTown_Frlg/scripts.pory"
	walk_in_place_faster_left
# 383 "data/maps/PalletTown_Frlg/scripts.pory"
	step_end
# 384 "data/maps/PalletTown_Frlg/scripts.pory"

# 385 "data/maps/PalletTown_Frlg/scripts.pory"
PalletTown_Movement_SignLadyMoveOutOfWayLeft::
# 386 "data/maps/PalletTown_Frlg/scripts.pory"
	walk_left
# 387 "data/maps/PalletTown_Frlg/scripts.pory"
	walk_in_place_faster_right
# 388 "data/maps/PalletTown_Frlg/scripts.pory"
	step_end
# 389 "data/maps/PalletTown_Frlg/scripts.pory"

# 390 "data/maps/PalletTown_Frlg/scripts.pory"
PalletTown_EventScript_FatMan::
# 391 "data/maps/PalletTown_Frlg/scripts.pory"
	msgbox PalletTown_Text_CanStoreItemsAndMonsInPC, MSGBOX_NPC
# 392 "data/maps/PalletTown_Frlg/scripts.pory"
	end
# 393 "data/maps/PalletTown_Frlg/scripts.pory"

# 394 "data/maps/PalletTown_Frlg/scripts.pory"
PalletTown_EventScript_OaksLabSign::
# 395 "data/maps/PalletTown_Frlg/scripts.pory"
	lockall
# 396 "data/maps/PalletTown_Frlg/scripts.pory"
	famechecker FAMECHECKER_OAK, 0
# 397 "data/maps/PalletTown_Frlg/scripts.pory"
	msgbox PalletTown_Text_OakPokemonResearchLab
# 398 "data/maps/PalletTown_Frlg/scripts.pory"
	releaseall
# 399 "data/maps/PalletTown_Frlg/scripts.pory"
	end
# 400 "data/maps/PalletTown_Frlg/scripts.pory"

# 401 "data/maps/PalletTown_Frlg/scripts.pory"
PalletTown_EventScript_PlayersHouseSign::
# 402 "data/maps/PalletTown_Frlg/scripts.pory"
	msgbox PalletTown_Text_PlayersHouse, MSGBOX_SIGN
# 403 "data/maps/PalletTown_Frlg/scripts.pory"
	end
# 404 "data/maps/PalletTown_Frlg/scripts.pory"

# 405 "data/maps/PalletTown_Frlg/scripts.pory"
PalletTown_EventScript_RivalsHouseSign::
# 406 "data/maps/PalletTown_Frlg/scripts.pory"
	msgbox PalletTown_Text_RivalsHouse, MSGBOX_SIGN
# 407 "data/maps/PalletTown_Frlg/scripts.pory"
	end
# 408 "data/maps/PalletTown_Frlg/scripts.pory"

# 409 "data/maps/PalletTown_Frlg/scripts.pory"
PalletTown_EventScript_TownSign::
# 410 "data/maps/PalletTown_Frlg/scripts.pory"
	msgbox PalletTown_Text_TownSign, MSGBOX_SIGN
# 411 "data/maps/PalletTown_Frlg/scripts.pory"
	end
# 412 "data/maps/PalletTown_Frlg/scripts.pory"

# 413 "data/maps/PalletTown_Frlg/scripts.pory"
PalletTown_EventScript_TrainerTips::
# 414 "data/maps/PalletTown_Frlg/scripts.pory"
	lockall
# 415 "data/maps/PalletTown_Frlg/scripts.pory"
	msgbox PalletTown_Text_PressStartToOpenMenu
# 416 "data/maps/PalletTown_Frlg/scripts.pory"
	setvar VAR_MAP_SCENE_PALLET_TOWN_SIGN_LADY, 1
# 417 "data/maps/PalletTown_Frlg/scripts.pory"
	releaseall
# 418 "data/maps/PalletTown_Frlg/scripts.pory"
	end
# 419 "data/maps/PalletTown_Frlg/scripts.pory"

# 420 "data/maps/PalletTown_Frlg/scripts.pory"
PalletTown_EventScript_SignLadyTrigger::
# 421 "data/maps/PalletTown_Frlg/scripts.pory"
	lockall
# 422 "data/maps/PalletTown_Frlg/scripts.pory"
	applymovement LOCALID_PALLET_SIGN_LADY, Common_Movement_WalkInPlaceFasterRight
# 423 "data/maps/PalletTown_Frlg/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
# 424 "data/maps/PalletTown_Frlg/scripts.pory"
	waitmovement 0
# 425 "data/maps/PalletTown_Frlg/scripts.pory"
	call PalletTown_EventScript_SignLadyShowSign
# 426 "data/maps/PalletTown_Frlg/scripts.pory"
	releaseall
# 427 "data/maps/PalletTown_Frlg/scripts.pory"
	end
# 428 "data/maps/PalletTown_Frlg/scripts.pory"

# 429 "data/maps/PalletTown_Frlg/scripts.pory"
PalletTown_EventScript_SignLadyShowSign::
# 430 "data/maps/PalletTown_Frlg/scripts.pory"
	textcolor NPC_TEXT_COLOR_FEMALE
# 431 "data/maps/PalletTown_Frlg/scripts.pory"
	msgbox PalletTown_Text_LookCopiedTrainerTipsSign
# 432 "data/maps/PalletTown_Frlg/scripts.pory"
	closemessage
# 433 "data/maps/PalletTown_Frlg/scripts.pory"
	delay 20
# 434 "data/maps/PalletTown_Frlg/scripts.pory"
	textcolor NPC_TEXT_COLOR_NEUTRAL
# 435 "data/maps/PalletTown_Frlg/scripts.pory"
	setflag FLAG_OPENED_START_MENU
# 436 "data/maps/PalletTown_Frlg/scripts.pory"
	setvar VAR_MAP_SCENE_PALLET_TOWN_SIGN_LADY, 1
# 437 "data/maps/PalletTown_Frlg/scripts.pory"
	setvar SIGN_LADY_READY, FALSE
# 438 "data/maps/PalletTown_Frlg/scripts.pory"
	special SetWalkingIntoSignVars
# 439 "data/maps/PalletTown_Frlg/scripts.pory"
	special DisableMsgBoxWalkaway
# 440 "data/maps/PalletTown_Frlg/scripts.pory"
	signmsg
# 441 "data/maps/PalletTown_Frlg/scripts.pory"
	msgbox PalletTown_Text_PressStartToOpenMenuCopy
# 442 "data/maps/PalletTown_Frlg/scripts.pory"
	normalmsg
# 443 "data/maps/PalletTown_Frlg/scripts.pory"
	return
# 444 "data/maps/PalletTown_Frlg/scripts.pory"

# 445 "data/maps/PalletTown_Frlg/scripts.pory"
PalletTown_EventScript_SignLadyStartShowSign::
# 446 "data/maps/PalletTown_Frlg/scripts.pory"
	applymovement LOCALID_PALLET_SIGN_LADY, Common_Movement_FacePlayer
# 447 "data/maps/PalletTown_Frlg/scripts.pory"
	waitmovement 0
# 448 "data/maps/PalletTown_Frlg/scripts.pory"
	call PalletTown_EventScript_SignLadyShowSign
# 449 "data/maps/PalletTown_Frlg/scripts.pory"
	release
# 450 "data/maps/PalletTown_Frlg/scripts.pory"
	end
# 451 "data/maps/PalletTown_Frlg/scripts.pory"

# 452 "data/maps/PalletTown_Frlg/scripts.pory"
PalletTown_Text_OakDontGoOut::
# 453 "data/maps/PalletTown_Frlg/scripts.pory"
	.string "OAK: Hey! Wait!\n"
# 454 "data/maps/PalletTown_Frlg/scripts.pory"
	.string "Don't go out!$"
# 455 "data/maps/PalletTown_Frlg/scripts.pory"

# 456 "data/maps/PalletTown_Frlg/scripts.pory"
PalletTown_Text_OakGrassUnsafeNeedMon::
# 457 "data/maps/PalletTown_Frlg/scripts.pory"
	.string "OAK: It's unsafe!\n"
# 458 "data/maps/PalletTown_Frlg/scripts.pory"
	.string "Wild POKéMON live in tall grass!\p"
# 459 "data/maps/PalletTown_Frlg/scripts.pory"
	.string "You need your own POKéMON for\n"
# 460 "data/maps/PalletTown_Frlg/scripts.pory"
	.string "your protection.\p"
# 461 "data/maps/PalletTown_Frlg/scripts.pory"
	.string "I know!\n"
# 462 "data/maps/PalletTown_Frlg/scripts.pory"
	.string "Here, come with me!$"
# 463 "data/maps/PalletTown_Frlg/scripts.pory"

# 464 "data/maps/PalletTown_Frlg/scripts.pory"
PalletTown_Text_RaisingMonsToo::
# 465 "data/maps/PalletTown_Frlg/scripts.pory"
	.string "I'm raising POKéMON, too.\p"
# 466 "data/maps/PalletTown_Frlg/scripts.pory"
	.string "When they get strong, they can\n"
# 467 "data/maps/PalletTown_Frlg/scripts.pory"
	.string "protect me.$"
# 468 "data/maps/PalletTown_Frlg/scripts.pory"

# 469 "data/maps/PalletTown_Frlg/scripts.pory"
PalletTown_Text_CanStoreItemsAndMonsInPC::
# 470 "data/maps/PalletTown_Frlg/scripts.pory"
	.string "Technology is incredible!\p"
# 471 "data/maps/PalletTown_Frlg/scripts.pory"
	.string "You can now store and recall items\n"
# 472 "data/maps/PalletTown_Frlg/scripts.pory"
	.string "and POKéMON as data via PC.$"
# 473 "data/maps/PalletTown_Frlg/scripts.pory"

# 474 "data/maps/PalletTown_Frlg/scripts.pory"
PalletTown_Text_OakPokemonResearchLab::
# 475 "data/maps/PalletTown_Frlg/scripts.pory"
	.string "OAK POKéMON RESEARCH LAB$"
# 476 "data/maps/PalletTown_Frlg/scripts.pory"

# 477 "data/maps/PalletTown_Frlg/scripts.pory"
PalletTown_Text_PlayersHouse::
# 478 "data/maps/PalletTown_Frlg/scripts.pory"
	.string "{PLAYER}'s house$"
# 479 "data/maps/PalletTown_Frlg/scripts.pory"

# 480 "data/maps/PalletTown_Frlg/scripts.pory"
PalletTown_Text_RivalsHouse::
# 481 "data/maps/PalletTown_Frlg/scripts.pory"
	.string "{RIVAL}'s house$"
# 482 "data/maps/PalletTown_Frlg/scripts.pory"

# 483 "data/maps/PalletTown_Frlg/scripts.pory"
PalletTown_Text_TownSign::
# 484 "data/maps/PalletTown_Frlg/scripts.pory"
	.string "PALLET TOWN\n"
# 485 "data/maps/PalletTown_Frlg/scripts.pory"
	.string "Shades of your journey await!$"
# 486 "data/maps/PalletTown_Frlg/scripts.pory"

# 487 "data/maps/PalletTown_Frlg/scripts.pory"
PalletTown_Text_OakLetMeSeePokedex::
# 488 "data/maps/PalletTown_Frlg/scripts.pory"
	.string "OAK: Ah, {PLAYER}!\n"
# 489 "data/maps/PalletTown_Frlg/scripts.pory"
	.string "You're back, are you?\p"
# 490 "data/maps/PalletTown_Frlg/scripts.pory"
	.string "How much have you filled in your\n"
# 491 "data/maps/PalletTown_Frlg/scripts.pory"
	.string "POKéDEX?\p"
# 492 "data/maps/PalletTown_Frlg/scripts.pory"
	.string "May I see it?\p"
# 493 "data/maps/PalletTown_Frlg/scripts.pory"
	.string "Let's see…$"
# 494 "data/maps/PalletTown_Frlg/scripts.pory"

# 495 "data/maps/PalletTown_Frlg/scripts.pory"
PalletTown_Text_CaughtXPuttingInHonestEffort::
# 496 "data/maps/PalletTown_Frlg/scripts.pory"
	.string "You've caught {STR_VAR_2}…\p"
# 497 "data/maps/PalletTown_Frlg/scripts.pory"
	.string "Hm, it looks as if you're putting\n"
# 498 "data/maps/PalletTown_Frlg/scripts.pory"
	.string "in an honest effort.\p"
# 499 "data/maps/PalletTown_Frlg/scripts.pory"
	.string "When you manage to fill it some\n"
# 500 "data/maps/PalletTown_Frlg/scripts.pory"
	.string "more, come show me, please.$"
# 501 "data/maps/PalletTown_Frlg/scripts.pory"

# 502 "data/maps/PalletTown_Frlg/scripts.pory"
PalletTown_Text_CaughtXImpressiveFollowMe::
# 503 "data/maps/PalletTown_Frlg/scripts.pory"
	.string "You've caught… {STR_VAR_2}!?\n"
# 504 "data/maps/PalletTown_Frlg/scripts.pory"
	.string "Now, this is impressive!\p"
# 505 "data/maps/PalletTown_Frlg/scripts.pory"
	.string "There's something I wanted to ask\n"
# 506 "data/maps/PalletTown_Frlg/scripts.pory"
	.string "of you, {PLAYER}.\p"
# 507 "data/maps/PalletTown_Frlg/scripts.pory"
	.string "Come.\n"
# 508 "data/maps/PalletTown_Frlg/scripts.pory"
	.string "Follow me.$"
# 509 "data/maps/PalletTown_Frlg/scripts.pory"

# 510 "data/maps/PalletTown_Frlg/scripts.pory"
PalletTown_Text_OakYouEnjoyingTraveling::
# 511 "data/maps/PalletTown_Frlg/scripts.pory"
	.string "OAK: Ah, {PLAYER}!\n"
# 512 "data/maps/PalletTown_Frlg/scripts.pory"
	.string "You seem to be enjoying traveling.\p"
# 513 "data/maps/PalletTown_Frlg/scripts.pory"
	.string "Knowing you, {PLAYER}, I can easily\n"
# 514 "data/maps/PalletTown_Frlg/scripts.pory"
	.string "imagine you going out to even more\l"
# 515 "data/maps/PalletTown_Frlg/scripts.pory"
	.string "exotic locales.\p"
# 516 "data/maps/PalletTown_Frlg/scripts.pory"
	.string "Good for you, good for you.\n"
# 517 "data/maps/PalletTown_Frlg/scripts.pory"
	.string "Hohoho.$"
# 518 "data/maps/PalletTown_Frlg/scripts.pory"

# 519 "data/maps/PalletTown_Frlg/scripts.pory"
@ For the NPC in Pallet Town that talks about the Trainer Tips sign
# 520 "data/maps/PalletTown_Frlg/scripts.pory"
PalletTown_Text_HmmIsThatRight::
# 521 "data/maps/PalletTown_Frlg/scripts.pory"
	.string "Hmm…\n"
# 522 "data/maps/PalletTown_Frlg/scripts.pory"
	.string "Is that right…$"
# 523 "data/maps/PalletTown_Frlg/scripts.pory"

# 524 "data/maps/PalletTown_Frlg/scripts.pory"
PalletTown_Text_OhLookLook::
# 525 "data/maps/PalletTown_Frlg/scripts.pory"
	.string "Oh!\n"
# 526 "data/maps/PalletTown_Frlg/scripts.pory"
	.string "Look, look!$"
# 527 "data/maps/PalletTown_Frlg/scripts.pory"

# 528 "data/maps/PalletTown_Frlg/scripts.pory"
PalletTown_Text_ReadItReadIt::
# 529 "data/maps/PalletTown_Frlg/scripts.pory"
	.string "Read it, read it!$"
# 530 "data/maps/PalletTown_Frlg/scripts.pory"

# 531 "data/maps/PalletTown_Frlg/scripts.pory"
@ Used by sign
# 532 "data/maps/PalletTown_Frlg/scripts.pory"
PalletTown_Text_PressStartToOpenMenu::
# 533 "data/maps/PalletTown_Frlg/scripts.pory"
	.string "TRAINER TIPS\p"
# 534 "data/maps/PalletTown_Frlg/scripts.pory"
	.string "Press START to open the MENU!$"
# 535 "data/maps/PalletTown_Frlg/scripts.pory"

# 536 "data/maps/PalletTown_Frlg/scripts.pory"
PalletTown_Text_SignsAreUsefulArentThey::
# 537 "data/maps/PalletTown_Frlg/scripts.pory"
	.string "Signs are useful, aren't they?$"
# 538 "data/maps/PalletTown_Frlg/scripts.pory"

# 539 "data/maps/PalletTown_Frlg/scripts.pory"
PalletTown_Text_LookCopiedTrainerTipsSign::
# 540 "data/maps/PalletTown_Frlg/scripts.pory"
	.string "Look, look!\p"
# 541 "data/maps/PalletTown_Frlg/scripts.pory"
	.string "I copied what it said on one of\n"
# 542 "data/maps/PalletTown_Frlg/scripts.pory"
	.string "those TRAINER TIPS signs!$"
# 543 "data/maps/PalletTown_Frlg/scripts.pory"

# 544 "data/maps/PalletTown_Frlg/scripts.pory"
@ Used by NPC
# 545 "data/maps/PalletTown_Frlg/scripts.pory"
PalletTown_Text_PressStartToOpenMenuCopy::
# 546 "data/maps/PalletTown_Frlg/scripts.pory"
	.string "TRAINER TIPS!\p"
# 547 "data/maps/PalletTown_Frlg/scripts.pory"
	.string "Press START to open the MENU!$"

Pallet_Town_EventScript_Sign1::
# 552 "data/maps/PalletTown_Frlg/scripts.pory"
	lockall
# 553 "data/maps/PalletTown_Frlg/scripts.pory"
	msgbox Pallet_Town_EventScript_Sign1_Text_0
# 554 "data/maps/PalletTown_Frlg/scripts.pory"
	releaseall
	return


Pallet_Town_EventScript_Sign1_Text_0:
# 553 "data/maps/PalletTown_Frlg/scripts.pory"
	.string "This is a test message$"
