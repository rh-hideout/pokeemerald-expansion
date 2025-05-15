# 1 "data/maps/OldaleTown/scripts.pory"

# 2 "data/maps/OldaleTown/scripts.pory"
.set LOCALID_MART_EMPLOYEE, 2
# 3 "data/maps/OldaleTown/scripts.pory"
.set LOCALID_FOOTPRINTS_MAN, 3
# 4 "data/maps/OldaleTown/scripts.pory"
.set LOCALID_RIVAL, 4
# 5 "data/maps/OldaleTown/scripts.pory"

# 6 "data/maps/OldaleTown/scripts.pory"
OldaleTown_MapScripts::
# 7 "data/maps/OldaleTown/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, OldaleTown_OnTransition
# 8 "data/maps/OldaleTown/scripts.pory"
	.byte 0
# 9 "data/maps/OldaleTown/scripts.pory"

# 10 "data/maps/OldaleTown/scripts.pory"
OldaleTown_OnTransition:
# 11 "data/maps/OldaleTown/scripts.pory"
	call Common_EventScript_SetupRivalGfxId
# 12 "data/maps/OldaleTown/scripts.pory"
	setflag FLAG_VISITED_OLDALE_TOWN
# 13 "data/maps/OldaleTown/scripts.pory"
	call_if_unset FLAG_BLOCKOLDALE, OldaleTown_EventScript_BlockWestEntrance
# 14 "data/maps/OldaleTown/scripts.pory"
	call_if_unset FLAG_RECEIVED_POTION_OLDALE, OldaleTown_EventScript_MoveMartEmployee
# 15 "data/maps/OldaleTown/scripts.pory"
	call_if_set FLAG_ADVENTURE_STARTED, OldaleTown_EventScript_SetOldaleState
# 16 "data/maps/OldaleTown/scripts.pory"
	call_if_set FLAG_BLOCKOLDALE, OldaleTown_EventScript_SetOldaleState2
# 17 "data/maps/OldaleTown/scripts.pory"
	end
# 18 "data/maps/OldaleTown/scripts.pory"

# 19 "data/maps/OldaleTown/scripts.pory"
@ This script seems pointless because nothing uses VAR_OLDALE_TOWN_STATE
# 20 "data/maps/OldaleTown/scripts.pory"
OldaleTown_EventScript_SetOldaleState::
# 21 "data/maps/OldaleTown/scripts.pory"
	setvar VAR_OLDALE_TOWN_STATE, 0
# 22 "data/maps/OldaleTown/scripts.pory"
	return
# 23 "data/maps/OldaleTown/scripts.pory"
	
# 24 "data/maps/OldaleTown/scripts.pory"
OldaleTown_EventScript_SetOldaleState2::
# 25 "data/maps/OldaleTown/scripts.pory"
	setvar VAR_OLDALE_TOWN_STATE, 1
# 26 "data/maps/OldaleTown/scripts.pory"
	return
# 27 "data/maps/OldaleTown/scripts.pory"

# 28 "data/maps/OldaleTown/scripts.pory"
OldaleTown_EventScript_BlockWestEntrance::
# 29 "data/maps/OldaleTown/scripts.pory"
	setobjectxyperm LOCALID_FOOTPRINTS_MAN, 1, 11
# 30 "data/maps/OldaleTown/scripts.pory"
	setobjectmovementtype LOCALID_FOOTPRINTS_MAN, MOVEMENT_TYPE_FACE_LEFT
# 31 "data/maps/OldaleTown/scripts.pory"
	return
# 32 "data/maps/OldaleTown/scripts.pory"

# 33 "data/maps/OldaleTown/scripts.pory"
OldaleTown_EventScript_MoveMartEmployee::
# 34 "data/maps/OldaleTown/scripts.pory"
	setobjectxyperm LOCALID_MART_EMPLOYEE, 13, 14
# 35 "data/maps/OldaleTown/scripts.pory"
	setobjectmovementtype LOCALID_MART_EMPLOYEE, MOVEMENT_TYPE_FACE_DOWN
# 36 "data/maps/OldaleTown/scripts.pory"
	return
# 37 "data/maps/OldaleTown/scripts.pory"

# 38 "data/maps/OldaleTown/scripts.pory"
OldaleTown_EventScript_TownSign::
# 39 "data/maps/OldaleTown/scripts.pory"
	msgbox OldaleTown_Text_TownSign, MSGBOX_SIGN
# 40 "data/maps/OldaleTown/scripts.pory"
	end
# 41 "data/maps/OldaleTown/scripts.pory"

# 42 "data/maps/OldaleTown/scripts.pory"
OldaleTown_EventScript_Girl::
# 43 "data/maps/OldaleTown/scripts.pory"
	msgbox OldaleTown_Text_SavingMyProgress, MSGBOX_NPC
# 44 "data/maps/OldaleTown/scripts.pory"
	end
# 45 "data/maps/OldaleTown/scripts.pory"

# 46 "data/maps/OldaleTown/scripts.pory"
OldaleTown_EventScript_MartEmployee::
# 47 "data/maps/OldaleTown/scripts.pory"
	lock
# 48 "data/maps/OldaleTown/scripts.pory"
	faceplayer
# 49 "data/maps/OldaleTown/scripts.pory"
	goto_if_set FLAG_RECEIVED_POTION_OLDALE, OldaleTown_EventScript_ExplainPotion
# 50 "data/maps/OldaleTown/scripts.pory"
	goto_if_set FLAG_TEMP_1, OldaleTown_EventScript_ExplainPotion
# 51 "data/maps/OldaleTown/scripts.pory"
	setflag FLAG_TEMP_1
# 52 "data/maps/OldaleTown/scripts.pory"
	playbgm MUS_FOLLOW_ME, FALSE
# 53 "data/maps/OldaleTown/scripts.pory"
	msgbox OldaleTown_Text_IWorkAtPokemonMart, MSGBOX_DEFAULT
# 54 "data/maps/OldaleTown/scripts.pory"
	closemessage
# 55 "data/maps/OldaleTown/scripts.pory"
	switch VAR_FACING
# 56 "data/maps/OldaleTown/scripts.pory"
	case DIR_SOUTH, OldaleTown_EventScript_GoToMartSouth
# 57 "data/maps/OldaleTown/scripts.pory"
	case DIR_NORTH, OldaleTown_EventScript_GoToMartNorth
# 58 "data/maps/OldaleTown/scripts.pory"
	case DIR_EAST, OldaleTown_EventScript_GoToMartEast
# 59 "data/maps/OldaleTown/scripts.pory"
	end
# 60 "data/maps/OldaleTown/scripts.pory"

# 61 "data/maps/OldaleTown/scripts.pory"
OldaleTown_EventScript_GoToMartSouth::
# 62 "data/maps/OldaleTown/scripts.pory"
	applymovement LOCALID_MART_EMPLOYEE, OldaleTown_Movement_EmployeeSouth
# 63 "data/maps/OldaleTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, OldaleTown_Movement_PlayerSouth
# 64 "data/maps/OldaleTown/scripts.pory"
	waitmovement 0
# 65 "data/maps/OldaleTown/scripts.pory"
	goto OldaleTown_EventScript_ExplainPokemonMart
# 66 "data/maps/OldaleTown/scripts.pory"
	end
# 67 "data/maps/OldaleTown/scripts.pory"

# 68 "data/maps/OldaleTown/scripts.pory"
OldaleTown_EventScript_GoToMartNorth::
# 69 "data/maps/OldaleTown/scripts.pory"
	applymovement LOCALID_MART_EMPLOYEE, OldaleTown_Movement_EmployeeNorth
# 70 "data/maps/OldaleTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, OldaleTown_Movement_PlayerNorth
# 71 "data/maps/OldaleTown/scripts.pory"
	waitmovement 0
# 72 "data/maps/OldaleTown/scripts.pory"
	goto OldaleTown_EventScript_ExplainPokemonMart
# 73 "data/maps/OldaleTown/scripts.pory"
	end
# 74 "data/maps/OldaleTown/scripts.pory"

# 75 "data/maps/OldaleTown/scripts.pory"
OldaleTown_EventScript_GoToMartEast::
# 76 "data/maps/OldaleTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, OldaleTown_Movement_PlayerEast
# 77 "data/maps/OldaleTown/scripts.pory"
	applymovement LOCALID_MART_EMPLOYEE, OldaleTown_Movement_EmployeeEast
# 78 "data/maps/OldaleTown/scripts.pory"
	waitmovement 0
# 79 "data/maps/OldaleTown/scripts.pory"
	goto OldaleTown_EventScript_ExplainPokemonMart
# 80 "data/maps/OldaleTown/scripts.pory"
	end
# 81 "data/maps/OldaleTown/scripts.pory"

# 82 "data/maps/OldaleTown/scripts.pory"
OldaleTown_EventScript_ExplainPokemonMart::
# 83 "data/maps/OldaleTown/scripts.pory"
	msgbox OldaleTown_Text_ThisIsAPokemonMart, MSGBOX_DEFAULT
# 84 "data/maps/OldaleTown/scripts.pory"
	giveitem ITEM_POTION
# 85 "data/maps/OldaleTown/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, OldaleTown_EventScript_BagIsFull
# 86 "data/maps/OldaleTown/scripts.pory"
	msgbox OldaleTown_Text_PotionExplanation, MSGBOX_DEFAULT
# 87 "data/maps/OldaleTown/scripts.pory"
	setflag FLAG_RECEIVED_POTION_OLDALE
# 88 "data/maps/OldaleTown/scripts.pory"
	fadedefaultbgm
# 89 "data/maps/OldaleTown/scripts.pory"
	release
# 90 "data/maps/OldaleTown/scripts.pory"
	end
# 91 "data/maps/OldaleTown/scripts.pory"

# 92 "data/maps/OldaleTown/scripts.pory"
OldaleTown_EventScript_ExplainPotion::
# 93 "data/maps/OldaleTown/scripts.pory"
	msgbox OldaleTown_Text_PotionExplanation, MSGBOX_DEFAULT
# 94 "data/maps/OldaleTown/scripts.pory"
	release
# 95 "data/maps/OldaleTown/scripts.pory"
	end
# 96 "data/maps/OldaleTown/scripts.pory"

# 97 "data/maps/OldaleTown/scripts.pory"
OldaleTown_EventScript_BagIsFull::
# 98 "data/maps/OldaleTown/scripts.pory"
	msgbox gText_TooBadBagIsFull, MSGBOX_DEFAULT
# 99 "data/maps/OldaleTown/scripts.pory"
	fadedefaultbgm
# 100 "data/maps/OldaleTown/scripts.pory"
	release
# 101 "data/maps/OldaleTown/scripts.pory"
	end
# 102 "data/maps/OldaleTown/scripts.pory"

# 103 "data/maps/OldaleTown/scripts.pory"
OldaleTown_Movement_EmployeeEast:
# 104 "data/maps/OldaleTown/scripts.pory"
	walk_up
# 105 "data/maps/OldaleTown/scripts.pory"
	walk_up
# 106 "data/maps/OldaleTown/scripts.pory"
	walk_up
# 107 "data/maps/OldaleTown/scripts.pory"
	walk_up
# 108 "data/maps/OldaleTown/scripts.pory"
	walk_up
# 109 "data/maps/OldaleTown/scripts.pory"
	walk_up
# 110 "data/maps/OldaleTown/scripts.pory"
	walk_up
# 111 "data/maps/OldaleTown/scripts.pory"
	walk_in_place_faster_down
# 112 "data/maps/OldaleTown/scripts.pory"
	step_end
# 113 "data/maps/OldaleTown/scripts.pory"

# 114 "data/maps/OldaleTown/scripts.pory"
OldaleTown_Movement_EmployeeSouth:
# 115 "data/maps/OldaleTown/scripts.pory"
	walk_left
# 116 "data/maps/OldaleTown/scripts.pory"
	walk_up
# 117 "data/maps/OldaleTown/scripts.pory"
	walk_up
# 118 "data/maps/OldaleTown/scripts.pory"
	walk_right
# 119 "data/maps/OldaleTown/scripts.pory"
	walk_up
# 120 "data/maps/OldaleTown/scripts.pory"
	walk_up
# 121 "data/maps/OldaleTown/scripts.pory"
	walk_up
# 122 "data/maps/OldaleTown/scripts.pory"
	walk_up
# 123 "data/maps/OldaleTown/scripts.pory"
	walk_up
# 124 "data/maps/OldaleTown/scripts.pory"
	walk_in_place_faster_down
# 125 "data/maps/OldaleTown/scripts.pory"
	step_end
# 126 "data/maps/OldaleTown/scripts.pory"

# 127 "data/maps/OldaleTown/scripts.pory"
OldaleTown_Movement_EmployeeNorth:
# 128 "data/maps/OldaleTown/scripts.pory"
	walk_up
# 129 "data/maps/OldaleTown/scripts.pory"
	walk_up
# 130 "data/maps/OldaleTown/scripts.pory"
	walk_up
# 131 "data/maps/OldaleTown/scripts.pory"
	walk_up
# 132 "data/maps/OldaleTown/scripts.pory"
	walk_up
# 133 "data/maps/OldaleTown/scripts.pory"
	walk_up
# 134 "data/maps/OldaleTown/scripts.pory"
	walk_up
# 135 "data/maps/OldaleTown/scripts.pory"
	walk_in_place_faster_down
# 136 "data/maps/OldaleTown/scripts.pory"
	step_end
# 137 "data/maps/OldaleTown/scripts.pory"

# 138 "data/maps/OldaleTown/scripts.pory"
OldaleTown_Movement_Unknown1:
# 139 "data/maps/OldaleTown/scripts.pory"
	walk_up
# 140 "data/maps/OldaleTown/scripts.pory"
	walk_up
# 141 "data/maps/OldaleTown/scripts.pory"
	walk_right
# 142 "data/maps/OldaleTown/scripts.pory"
	walk_right
# 143 "data/maps/OldaleTown/scripts.pory"
	walk_right
# 144 "data/maps/OldaleTown/scripts.pory"
	walk_right
# 145 "data/maps/OldaleTown/scripts.pory"
	walk_up
# 146 "data/maps/OldaleTown/scripts.pory"
	walk_up
# 147 "data/maps/OldaleTown/scripts.pory"
	walk_up
# 148 "data/maps/OldaleTown/scripts.pory"
	walk_up
# 149 "data/maps/OldaleTown/scripts.pory"
	walk_up
# 150 "data/maps/OldaleTown/scripts.pory"
	delay_8
# 151 "data/maps/OldaleTown/scripts.pory"
	walk_in_place_faster_down
# 152 "data/maps/OldaleTown/scripts.pory"
	step_end
# 153 "data/maps/OldaleTown/scripts.pory"

# 154 "data/maps/OldaleTown/scripts.pory"
OldaleTown_Movement_PlayerEast:
# 155 "data/maps/OldaleTown/scripts.pory"
	walk_right
# 156 "data/maps/OldaleTown/scripts.pory"
	walk_up
# 157 "data/maps/OldaleTown/scripts.pory"
	walk_up
# 158 "data/maps/OldaleTown/scripts.pory"
	walk_up
# 159 "data/maps/OldaleTown/scripts.pory"
	walk_up
# 160 "data/maps/OldaleTown/scripts.pory"
	walk_up
# 161 "data/maps/OldaleTown/scripts.pory"
	walk_up
# 162 "data/maps/OldaleTown/scripts.pory"
	step_end
# 163 "data/maps/OldaleTown/scripts.pory"

# 164 "data/maps/OldaleTown/scripts.pory"
OldaleTown_Movement_PlayerSouth:
# 165 "data/maps/OldaleTown/scripts.pory"
	delay_16
# 166 "data/maps/OldaleTown/scripts.pory"
	delay_16
# 167 "data/maps/OldaleTown/scripts.pory"
	delay_16
# 168 "data/maps/OldaleTown/scripts.pory"
	delay_16
# 169 "data/maps/OldaleTown/scripts.pory"
	walk_up
# 170 "data/maps/OldaleTown/scripts.pory"
	walk_up
# 171 "data/maps/OldaleTown/scripts.pory"
	walk_up
# 172 "data/maps/OldaleTown/scripts.pory"
	walk_up
# 173 "data/maps/OldaleTown/scripts.pory"
	walk_up
# 174 "data/maps/OldaleTown/scripts.pory"
	step_end
# 175 "data/maps/OldaleTown/scripts.pory"

# 176 "data/maps/OldaleTown/scripts.pory"
OldaleTown_Movement_PlayerNorth:
# 177 "data/maps/OldaleTown/scripts.pory"
	walk_up
# 178 "data/maps/OldaleTown/scripts.pory"
	walk_up
# 179 "data/maps/OldaleTown/scripts.pory"
	walk_up
# 180 "data/maps/OldaleTown/scripts.pory"
	walk_up
# 181 "data/maps/OldaleTown/scripts.pory"
	walk_up
# 182 "data/maps/OldaleTown/scripts.pory"
	walk_up
# 183 "data/maps/OldaleTown/scripts.pory"
	walk_up
# 184 "data/maps/OldaleTown/scripts.pory"
	step_end
# 185 "data/maps/OldaleTown/scripts.pory"

# 186 "data/maps/OldaleTown/scripts.pory"
OldaleTown_Movement_Unknown2:
# 187 "data/maps/OldaleTown/scripts.pory"
	walk_left
# 188 "data/maps/OldaleTown/scripts.pory"
	walk_up
# 189 "data/maps/OldaleTown/scripts.pory"
	walk_up
# 190 "data/maps/OldaleTown/scripts.pory"
	walk_right
# 191 "data/maps/OldaleTown/scripts.pory"
	walk_right
# 192 "data/maps/OldaleTown/scripts.pory"
	walk_right
# 193 "data/maps/OldaleTown/scripts.pory"
	walk_right
# 194 "data/maps/OldaleTown/scripts.pory"
	walk_up
# 195 "data/maps/OldaleTown/scripts.pory"
	walk_up
# 196 "data/maps/OldaleTown/scripts.pory"
	walk_up
# 197 "data/maps/OldaleTown/scripts.pory"
	walk_up
# 198 "data/maps/OldaleTown/scripts.pory"
	step_end
# 199 "data/maps/OldaleTown/scripts.pory"

# 200 "data/maps/OldaleTown/scripts.pory"
OldaleTown_EventScript_FootprintsMan::
# 201 "data/maps/OldaleTown/scripts.pory"
	lock
# 202 "data/maps/OldaleTown/scripts.pory"
	faceplayer
# 203 "data/maps/OldaleTown/scripts.pory"
	goto_if_set FLAG_ADVENTURE_STARTED, OldaleTown_EventScript_NotBlockingPath
# 204 "data/maps/OldaleTown/scripts.pory"
	msgbox OldaleTown_Text_DiscoveredFootprints, MSGBOX_DEFAULT
# 205 "data/maps/OldaleTown/scripts.pory"
	closemessage
# 206 "data/maps/OldaleTown/scripts.pory"
	applymovement LOCALID_FOOTPRINTS_MAN, Common_Movement_FaceOriginalDirection
# 207 "data/maps/OldaleTown/scripts.pory"
	waitmovement 0
# 208 "data/maps/OldaleTown/scripts.pory"
	release
# 209 "data/maps/OldaleTown/scripts.pory"
	end
# 210 "data/maps/OldaleTown/scripts.pory"

# 211 "data/maps/OldaleTown/scripts.pory"
OldaleTown_EventScript_BlockedPath::
# 212 "data/maps/OldaleTown/scripts.pory"
	lockall
# 213 "data/maps/OldaleTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, OldaleTown_Movement_PlayerStepBack
# 214 "data/maps/OldaleTown/scripts.pory"
	applymovement LOCALID_FOOTPRINTS_MAN, OldaleTown_Movement_BackUp
# 215 "data/maps/OldaleTown/scripts.pory"
	waitmovement 0
# 216 "data/maps/OldaleTown/scripts.pory"
	msgbox OldaleTown_Text_WaitDontComeInHere, MSGBOX_DEFAULT
# 217 "data/maps/OldaleTown/scripts.pory"
	closemessage
# 218 "data/maps/OldaleTown/scripts.pory"
	applymovement LOCALID_FOOTPRINTS_MAN, OldaleTown_Movement_ReturnToOriginalPosition
# 219 "data/maps/OldaleTown/scripts.pory"
	waitmovement 0
# 220 "data/maps/OldaleTown/scripts.pory"
	releaseall
# 221 "data/maps/OldaleTown/scripts.pory"
	end
# 222 "data/maps/OldaleTown/scripts.pory"

# 223 "data/maps/OldaleTown/scripts.pory"
OldaleTown_EventScript_NotBlockingPath::
# 224 "data/maps/OldaleTown/scripts.pory"
	msgbox OldaleTown_Text_FinishedSketchingFootprints, MSGBOX_DEFAULT
# 225 "data/maps/OldaleTown/scripts.pory"
	release
# 226 "data/maps/OldaleTown/scripts.pory"
	end
# 227 "data/maps/OldaleTown/scripts.pory"

# 228 "data/maps/OldaleTown/scripts.pory"
OldaleTown_EventScript_Rival::
# 229 "data/maps/OldaleTown/scripts.pory"
	lockall
# 230 "data/maps/OldaleTown/scripts.pory"
	applymovement LOCALID_RIVAL, Common_Movement_FacePlayer
# 231 "data/maps/OldaleTown/scripts.pory"
	waitmovement 0
# 232 "data/maps/OldaleTown/scripts.pory"
	setvar VAR_0x8009, 0
# 233 "data/maps/OldaleTown/scripts.pory"
	goto OldaleTown_EventScript_ShowRivalMessage
# 234 "data/maps/OldaleTown/scripts.pory"
	end
# 235 "data/maps/OldaleTown/scripts.pory"

# 236 "data/maps/OldaleTown/scripts.pory"
OldaleTown_EventScript_RivalTrigger1::
# 237 "data/maps/OldaleTown/scripts.pory"
	lockall
# 238 "data/maps/OldaleTown/scripts.pory"
	applymovement LOCALID_RIVAL, OldaleTown_Movement_RivalApproachPlayer1
# 239 "data/maps/OldaleTown/scripts.pory"
	waitmovement 0
# 240 "data/maps/OldaleTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterRight
# 241 "data/maps/OldaleTown/scripts.pory"
	waitmovement 0
# 242 "data/maps/OldaleTown/scripts.pory"
	setvar VAR_0x8009, 1
# 243 "data/maps/OldaleTown/scripts.pory"
	goto OldaleTown_EventScript_ShowRivalMessage
# 244 "data/maps/OldaleTown/scripts.pory"
	end
# 245 "data/maps/OldaleTown/scripts.pory"

# 246 "data/maps/OldaleTown/scripts.pory"
OldaleTown_EventScript_RivalTrigger2::
# 247 "data/maps/OldaleTown/scripts.pory"
	lockall
# 248 "data/maps/OldaleTown/scripts.pory"
	applymovement LOCALID_RIVAL, OldaleTown_Movement_RivalApproachPlayer2
# 249 "data/maps/OldaleTown/scripts.pory"
	waitmovement 0
# 250 "data/maps/OldaleTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterRight
# 251 "data/maps/OldaleTown/scripts.pory"
	waitmovement 0
# 252 "data/maps/OldaleTown/scripts.pory"
	setvar VAR_0x8009, 1
# 253 "data/maps/OldaleTown/scripts.pory"
	goto OldaleTown_EventScript_ShowRivalMessage
# 254 "data/maps/OldaleTown/scripts.pory"
	end
# 255 "data/maps/OldaleTown/scripts.pory"

# 256 "data/maps/OldaleTown/scripts.pory"
OldaleTown_EventScript_RivalTrigger3::
# 257 "data/maps/OldaleTown/scripts.pory"
	lockall
# 258 "data/maps/OldaleTown/scripts.pory"
	applymovement LOCALID_RIVAL, OldaleTown_Movement_RivalApproachPlayer3
# 259 "data/maps/OldaleTown/scripts.pory"
	waitmovement 0
# 260 "data/maps/OldaleTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterRight
# 261 "data/maps/OldaleTown/scripts.pory"
	waitmovement 0
# 262 "data/maps/OldaleTown/scripts.pory"
	setvar VAR_0x8009, 1
# 263 "data/maps/OldaleTown/scripts.pory"
	goto OldaleTown_EventScript_ShowRivalMessage
# 264 "data/maps/OldaleTown/scripts.pory"
	end
# 265 "data/maps/OldaleTown/scripts.pory"

# 266 "data/maps/OldaleTown/scripts.pory"
OldaleTown_EventScript_ShowRivalMessage::
# 267 "data/maps/OldaleTown/scripts.pory"
	checkplayergender
# 268 "data/maps/OldaleTown/scripts.pory"
	goto_if_eq VAR_RESULT, MALE, OldaleTown_EventScript_ShowMayMessage
# 269 "data/maps/OldaleTown/scripts.pory"
	goto_if_eq VAR_RESULT, FEMALE, OldaleTown_EventScript_ShowBrendanMessage
# 270 "data/maps/OldaleTown/scripts.pory"
	end
# 271 "data/maps/OldaleTown/scripts.pory"

# 272 "data/maps/OldaleTown/scripts.pory"
OldaleTown_EventScript_ShowMayMessage::
# 273 "data/maps/OldaleTown/scripts.pory"
	msgbox OldaleTown_Text_MayLetsGoBack, MSGBOX_DEFAULT
# 274 "data/maps/OldaleTown/scripts.pory"
	goto OldaleTown_EventScript_RivalFinish
# 275 "data/maps/OldaleTown/scripts.pory"
	end
# 276 "data/maps/OldaleTown/scripts.pory"

# 277 "data/maps/OldaleTown/scripts.pory"
OldaleTown_EventScript_ShowBrendanMessage::
# 278 "data/maps/OldaleTown/scripts.pory"
	msgbox OldaleTown_Text_BrendanLetsGoBack, MSGBOX_DEFAULT
# 279 "data/maps/OldaleTown/scripts.pory"
	goto OldaleTown_EventScript_RivalFinish
# 280 "data/maps/OldaleTown/scripts.pory"
	end
# 281 "data/maps/OldaleTown/scripts.pory"

# 282 "data/maps/OldaleTown/scripts.pory"
OldaleTown_EventScript_RivalFinish::
# 283 "data/maps/OldaleTown/scripts.pory"
	closemessage
# 284 "data/maps/OldaleTown/scripts.pory"
	call_if_eq VAR_0x8009, 0, OldaleTown_EventScript_DoExitMovement1
# 285 "data/maps/OldaleTown/scripts.pory"
	call_if_eq VAR_0x8009, 1, OldaleTown_EventScript_DoExitMovement2
# 286 "data/maps/OldaleTown/scripts.pory"
	applymovement LOCALID_RIVAL, OldaleTown_Movement_RivalExit
# 287 "data/maps/OldaleTown/scripts.pory"
	waitmovement 0
# 288 "data/maps/OldaleTown/scripts.pory"
	removeobject LOCALID_RIVAL
# 289 "data/maps/OldaleTown/scripts.pory"
	setvar VAR_OLDALE_RIVAL_STATE, 2
# 290 "data/maps/OldaleTown/scripts.pory"
	setflag FLAG_HIDE_OLDALE_TOWN_RIVAL
# 291 "data/maps/OldaleTown/scripts.pory"
	releaseall
# 292 "data/maps/OldaleTown/scripts.pory"
	end
# 293 "data/maps/OldaleTown/scripts.pory"

# 294 "data/maps/OldaleTown/scripts.pory"
OldaleTown_EventScript_DoExitMovement1::
# 295 "data/maps/OldaleTown/scripts.pory"
	goto_if_ne VAR_FACING, DIR_SOUTH, OldaleTown_EventScript_DoExitMovement2
# 296 "data/maps/OldaleTown/scripts.pory"
	applymovement LOCALID_RIVAL, OldaleTown_Movement_RivalExit
# 297 "data/maps/OldaleTown/scripts.pory"
	waitmovement 0
# 298 "data/maps/OldaleTown/scripts.pory"
	return
# 299 "data/maps/OldaleTown/scripts.pory"

# 300 "data/maps/OldaleTown/scripts.pory"
OldaleTown_EventScript_DoExitMovement2::
# 301 "data/maps/OldaleTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, OldaleTown_Movement_WatchRivalExit
# 302 "data/maps/OldaleTown/scripts.pory"
	applymovement LOCALID_RIVAL, OldaleTown_Movement_RivalExit
# 303 "data/maps/OldaleTown/scripts.pory"
	waitmovement 0
# 304 "data/maps/OldaleTown/scripts.pory"
	return
# 305 "data/maps/OldaleTown/scripts.pory"

# 306 "data/maps/OldaleTown/scripts.pory"
OldaleTown_Movement_RivalApproachPlayer1:
# 307 "data/maps/OldaleTown/scripts.pory"
	walk_left
# 308 "data/maps/OldaleTown/scripts.pory"
	walk_left
# 309 "data/maps/OldaleTown/scripts.pory"
	step_end
# 310 "data/maps/OldaleTown/scripts.pory"

# 311 "data/maps/OldaleTown/scripts.pory"
OldaleTown_Movement_RivalApproachPlayer2:
# 312 "data/maps/OldaleTown/scripts.pory"
	walk_left
# 313 "data/maps/OldaleTown/scripts.pory"
	step_end
# 314 "data/maps/OldaleTown/scripts.pory"

# 315 "data/maps/OldaleTown/scripts.pory"
OldaleTown_Movement_RivalApproachPlayer3:
# 316 "data/maps/OldaleTown/scripts.pory"
	face_left
# 317 "data/maps/OldaleTown/scripts.pory"
	step_end
# 318 "data/maps/OldaleTown/scripts.pory"

# 319 "data/maps/OldaleTown/scripts.pory"
OldaleTown_Movement_RivalExit:
# 320 "data/maps/OldaleTown/scripts.pory"
	walk_down
# 321 "data/maps/OldaleTown/scripts.pory"
	walk_down
# 322 "data/maps/OldaleTown/scripts.pory"
	walk_down
# 323 "data/maps/OldaleTown/scripts.pory"
	walk_down
# 324 "data/maps/OldaleTown/scripts.pory"
	walk_down
# 325 "data/maps/OldaleTown/scripts.pory"
	walk_down
# 326 "data/maps/OldaleTown/scripts.pory"
	step_end
# 327 "data/maps/OldaleTown/scripts.pory"

# 328 "data/maps/OldaleTown/scripts.pory"
OldaleTown_Movement_WatchRivalExit:
# 329 "data/maps/OldaleTown/scripts.pory"
	delay_8
# 330 "data/maps/OldaleTown/scripts.pory"
	delay_4
# 331 "data/maps/OldaleTown/scripts.pory"
	walk_in_place_faster_down
# 332 "data/maps/OldaleTown/scripts.pory"
	step_end
# 333 "data/maps/OldaleTown/scripts.pory"

# 334 "data/maps/OldaleTown/scripts.pory"
OldaleTown_Movement_PlayerStepBack:
# 335 "data/maps/OldaleTown/scripts.pory"
	delay_8
# 336 "data/maps/OldaleTown/scripts.pory"
	walk_right
# 337 "data/maps/OldaleTown/scripts.pory"
	step_end
# 338 "data/maps/OldaleTown/scripts.pory"

# 339 "data/maps/OldaleTown/scripts.pory"
OldaleTown_Movement_BackUp:
# 340 "data/maps/OldaleTown/scripts.pory"
	walk_fast_up
# 341 "data/maps/OldaleTown/scripts.pory"
	walk_in_place_faster_left
# 342 "data/maps/OldaleTown/scripts.pory"
	lock_facing_direction
# 343 "data/maps/OldaleTown/scripts.pory"
	walk_right
# 344 "data/maps/OldaleTown/scripts.pory"
	unlock_facing_direction
# 345 "data/maps/OldaleTown/scripts.pory"
	step_end
# 346 "data/maps/OldaleTown/scripts.pory"

# 347 "data/maps/OldaleTown/scripts.pory"
OldaleTown_Movement_ReturnToOriginalPosition:
# 348 "data/maps/OldaleTown/scripts.pory"
	walk_down
# 349 "data/maps/OldaleTown/scripts.pory"
	walk_left
# 350 "data/maps/OldaleTown/scripts.pory"
	step_end
# 351 "data/maps/OldaleTown/scripts.pory"

# 352 "data/maps/OldaleTown/scripts.pory"
OldaleTown_Text_SavingMyProgress:
# 353 "data/maps/OldaleTown/scripts.pory"
	.string "I want to take a rest, so I'm saving my\n"
# 354 "data/maps/OldaleTown/scripts.pory"
	.string "progress.$"
# 355 "data/maps/OldaleTown/scripts.pory"

# 356 "data/maps/OldaleTown/scripts.pory"
OldaleTown_Text_IWorkAtPokemonMart:
# 357 "data/maps/OldaleTown/scripts.pory"
	.string "Hi!\n"
# 358 "data/maps/OldaleTown/scripts.pory"
	.string "I work at a POKéMON MART.\p"
# 359 "data/maps/OldaleTown/scripts.pory"
	.string "Can I get you to come with me?$"
# 360 "data/maps/OldaleTown/scripts.pory"

# 361 "data/maps/OldaleTown/scripts.pory"
OldaleTown_Text_ThisIsAPokemonMart:
# 362 "data/maps/OldaleTown/scripts.pory"
	.string "This is a POKéMON MART.\n"
# 363 "data/maps/OldaleTown/scripts.pory"
	.string "Just look for our blue roof.\p"
# 364 "data/maps/OldaleTown/scripts.pory"
	.string "We sell a variety of goods including\n"
# 365 "data/maps/OldaleTown/scripts.pory"
	.string "POKé BALLS for catching POKéMON.\p"
# 366 "data/maps/OldaleTown/scripts.pory"
	.string "Here, I'd like you to have this as\n"
# 367 "data/maps/OldaleTown/scripts.pory"
	.string "a promotional item.$"
# 368 "data/maps/OldaleTown/scripts.pory"

# 369 "data/maps/OldaleTown/scripts.pory"
OldaleTown_Text_PotionExplanation:
# 370 "data/maps/OldaleTown/scripts.pory"
	.string "A POTION can be used anytime, so it's\n"
# 371 "data/maps/OldaleTown/scripts.pory"
	.string "even more useful than a POKéMON CENTER\l"
# 372 "data/maps/OldaleTown/scripts.pory"
	.string "in certain situations.$"
# 373 "data/maps/OldaleTown/scripts.pory"

# 374 "data/maps/OldaleTown/scripts.pory"
OldaleTown_Text_WaitDontComeInHere:
# 375 "data/maps/OldaleTown/scripts.pory"
	.string "Aaaaah! Wait!\n"
# 376 "data/maps/OldaleTown/scripts.pory"
	.string "Please don't come in here.\p"
# 377 "data/maps/OldaleTown/scripts.pory"
	.string "I just discovered the footprints of\n"
# 378 "data/maps/OldaleTown/scripts.pory"
	.string "a rare POKéMON!\p"
# 379 "data/maps/OldaleTown/scripts.pory"
	.string "Wait until I finish sketching\n"
# 380 "data/maps/OldaleTown/scripts.pory"
	.string "them, okay?$"
# 381 "data/maps/OldaleTown/scripts.pory"

# 382 "data/maps/OldaleTown/scripts.pory"
OldaleTown_Text_DiscoveredFootprints:
# 383 "data/maps/OldaleTown/scripts.pory"
	.string "I just discovered the footprints of\n"
# 384 "data/maps/OldaleTown/scripts.pory"
	.string "a rare POKéMON!\p"
# 385 "data/maps/OldaleTown/scripts.pory"
	.string "Wait until I finish sketching\n"
# 386 "data/maps/OldaleTown/scripts.pory"
	.string "them, okay?$"
# 387 "data/maps/OldaleTown/scripts.pory"

# 388 "data/maps/OldaleTown/scripts.pory"
OldaleTown_Text_FinishedSketchingFootprints:
# 389 "data/maps/OldaleTown/scripts.pory"
	.string "I finished sketching the footprints of\n"
# 390 "data/maps/OldaleTown/scripts.pory"
	.string "a rare POKéMON.\p"
# 391 "data/maps/OldaleTown/scripts.pory"
	.string "But it turns out they were only my\n"
# 392 "data/maps/OldaleTown/scripts.pory"
	.string "own footprints…$"
# 393 "data/maps/OldaleTown/scripts.pory"

# 394 "data/maps/OldaleTown/scripts.pory"
OldaleTown_Text_MayLetsGoBack:
# 395 "data/maps/OldaleTown/scripts.pory"
	.string "MAY: {PLAYER}{KUN}!\n"
# 396 "data/maps/OldaleTown/scripts.pory"
	.string "Over here!\l"
# 397 "data/maps/OldaleTown/scripts.pory"
	.string "Let's hurry home!$"
# 398 "data/maps/OldaleTown/scripts.pory"

# 399 "data/maps/OldaleTown/scripts.pory"
OldaleTown_Text_BrendanLetsGoBack:
# 400 "data/maps/OldaleTown/scripts.pory"
	.string "BRENDAN: I'm heading back to my dad's\n"
# 401 "data/maps/OldaleTown/scripts.pory"
	.string "LAB now.\l"
# 402 "data/maps/OldaleTown/scripts.pory"
	.string "{PLAYER}, you should hustle back, too.$"
# 403 "data/maps/OldaleTown/scripts.pory"

# 404 "data/maps/OldaleTown/scripts.pory"
OldaleTown_Text_TownSign:
# 405 "data/maps/OldaleTown/scripts.pory"
	.string "OLDALE TOWN\n"
# 406 "data/maps/OldaleTown/scripts.pory"
	.string "“Where things start off scarce.”$"

OldaleTown_EventScript_Block::
# 411 "data/maps/OldaleTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, BlockedPathMovement
# 412 "data/maps/OldaleTown/scripts.pory"
	waitmovement OBJ_EVENT_ID_PLAYER
# 413 "data/maps/OldaleTown/scripts.pory"
	msgbox OldaleTown_EventScript_Block_Text_0, MSGBOX_SIGN
	return


# 416 "data/maps/OldaleTown/scripts.pory"
BlockedPathMovement:
# 417 "data/maps/OldaleTown/scripts.pory"
	walk_right
	step_end

OldaleTown_EventScript_Block_Text_0:
# 413 "data/maps/OldaleTown/scripts.pory"
	.string "I have to battle MAY...$"
