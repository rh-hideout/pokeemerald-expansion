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
	call_if_unset FLAG_ADVENTURE_STARTED, OldaleTown_EventScript_BlockWestEntrance
# 14 "data/maps/OldaleTown/scripts.pory"
	call_if_unset FLAG_RECEIVED_POTION_OLDALE, OldaleTown_EventScript_MoveMartEmployee
# 15 "data/maps/OldaleTown/scripts.pory"
	call_if_set FLAG_ADVENTURE_STARTED, OldaleTown_EventScript_SetOldaleState
# 16 "data/maps/OldaleTown/scripts.pory"
	end
# 17 "data/maps/OldaleTown/scripts.pory"

# 18 "data/maps/OldaleTown/scripts.pory"
@ This script seems pointless because nothing uses VAR_OLDALE_TOWN_STATE
# 19 "data/maps/OldaleTown/scripts.pory"
OldaleTown_EventScript_SetOldaleState::
# 20 "data/maps/OldaleTown/scripts.pory"
	setvar VAR_OLDALE_TOWN_STATE, 1
# 21 "data/maps/OldaleTown/scripts.pory"
	return
# 22 "data/maps/OldaleTown/scripts.pory"

# 23 "data/maps/OldaleTown/scripts.pory"
OldaleTown_EventScript_BlockWestEntrance::
# 24 "data/maps/OldaleTown/scripts.pory"
	setobjectxyperm LOCALID_FOOTPRINTS_MAN, 1, 11
# 25 "data/maps/OldaleTown/scripts.pory"
	setobjectmovementtype LOCALID_FOOTPRINTS_MAN, MOVEMENT_TYPE_FACE_LEFT
# 26 "data/maps/OldaleTown/scripts.pory"
	return
# 27 "data/maps/OldaleTown/scripts.pory"

# 28 "data/maps/OldaleTown/scripts.pory"
OldaleTown_EventScript_MoveMartEmployee::
# 29 "data/maps/OldaleTown/scripts.pory"
	setobjectxyperm LOCALID_MART_EMPLOYEE, 13, 14
# 30 "data/maps/OldaleTown/scripts.pory"
	setobjectmovementtype LOCALID_MART_EMPLOYEE, MOVEMENT_TYPE_FACE_DOWN
# 31 "data/maps/OldaleTown/scripts.pory"
	return
# 32 "data/maps/OldaleTown/scripts.pory"

# 33 "data/maps/OldaleTown/scripts.pory"
OldaleTown_EventScript_TownSign::
# 34 "data/maps/OldaleTown/scripts.pory"
	msgbox OldaleTown_Text_TownSign, MSGBOX_SIGN
# 35 "data/maps/OldaleTown/scripts.pory"
	end
# 36 "data/maps/OldaleTown/scripts.pory"

# 37 "data/maps/OldaleTown/scripts.pory"
OldaleTown_EventScript_Girl::
# 38 "data/maps/OldaleTown/scripts.pory"
	msgbox OldaleTown_Text_SavingMyProgress, MSGBOX_NPC
# 39 "data/maps/OldaleTown/scripts.pory"
	end
# 40 "data/maps/OldaleTown/scripts.pory"

# 41 "data/maps/OldaleTown/scripts.pory"
OldaleTown_EventScript_MartEmployee::
# 42 "data/maps/OldaleTown/scripts.pory"
	lock
# 43 "data/maps/OldaleTown/scripts.pory"
	faceplayer
# 44 "data/maps/OldaleTown/scripts.pory"
	goto_if_set FLAG_RECEIVED_POTION_OLDALE, OldaleTown_EventScript_ExplainPotion
# 45 "data/maps/OldaleTown/scripts.pory"
	goto_if_set FLAG_TEMP_1, OldaleTown_EventScript_ExplainPotion
# 46 "data/maps/OldaleTown/scripts.pory"
	setflag FLAG_TEMP_1
# 47 "data/maps/OldaleTown/scripts.pory"
	playbgm MUS_FOLLOW_ME, FALSE
# 48 "data/maps/OldaleTown/scripts.pory"
	msgbox OldaleTown_Text_IWorkAtPokemonMart, MSGBOX_DEFAULT
# 49 "data/maps/OldaleTown/scripts.pory"
	closemessage
# 50 "data/maps/OldaleTown/scripts.pory"
	switch VAR_FACING
# 51 "data/maps/OldaleTown/scripts.pory"
	case DIR_SOUTH, OldaleTown_EventScript_GoToMartSouth
# 52 "data/maps/OldaleTown/scripts.pory"
	case DIR_NORTH, OldaleTown_EventScript_GoToMartNorth
# 53 "data/maps/OldaleTown/scripts.pory"
	case DIR_EAST, OldaleTown_EventScript_GoToMartEast
# 54 "data/maps/OldaleTown/scripts.pory"
	end
# 55 "data/maps/OldaleTown/scripts.pory"

# 56 "data/maps/OldaleTown/scripts.pory"
OldaleTown_EventScript_GoToMartSouth::
# 57 "data/maps/OldaleTown/scripts.pory"
	applymovement LOCALID_MART_EMPLOYEE, OldaleTown_Movement_EmployeeSouth
# 58 "data/maps/OldaleTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, OldaleTown_Movement_PlayerSouth
# 59 "data/maps/OldaleTown/scripts.pory"
	waitmovement 0
# 60 "data/maps/OldaleTown/scripts.pory"
	goto OldaleTown_EventScript_ExplainPokemonMart
# 61 "data/maps/OldaleTown/scripts.pory"
	end
# 62 "data/maps/OldaleTown/scripts.pory"

# 63 "data/maps/OldaleTown/scripts.pory"
OldaleTown_EventScript_GoToMartNorth::
# 64 "data/maps/OldaleTown/scripts.pory"
	applymovement LOCALID_MART_EMPLOYEE, OldaleTown_Movement_EmployeeNorth
# 65 "data/maps/OldaleTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, OldaleTown_Movement_PlayerNorth
# 66 "data/maps/OldaleTown/scripts.pory"
	waitmovement 0
# 67 "data/maps/OldaleTown/scripts.pory"
	goto OldaleTown_EventScript_ExplainPokemonMart
# 68 "data/maps/OldaleTown/scripts.pory"
	end
# 69 "data/maps/OldaleTown/scripts.pory"

# 70 "data/maps/OldaleTown/scripts.pory"
OldaleTown_EventScript_GoToMartEast::
# 71 "data/maps/OldaleTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, OldaleTown_Movement_PlayerEast
# 72 "data/maps/OldaleTown/scripts.pory"
	applymovement LOCALID_MART_EMPLOYEE, OldaleTown_Movement_EmployeeEast
# 73 "data/maps/OldaleTown/scripts.pory"
	waitmovement 0
# 74 "data/maps/OldaleTown/scripts.pory"
	goto OldaleTown_EventScript_ExplainPokemonMart
# 75 "data/maps/OldaleTown/scripts.pory"
	end
# 76 "data/maps/OldaleTown/scripts.pory"

# 77 "data/maps/OldaleTown/scripts.pory"
OldaleTown_EventScript_ExplainPokemonMart::
# 78 "data/maps/OldaleTown/scripts.pory"
	msgbox OldaleTown_Text_ThisIsAPokemonMart, MSGBOX_DEFAULT
# 79 "data/maps/OldaleTown/scripts.pory"
	giveitem ITEM_POTION
# 80 "data/maps/OldaleTown/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, OldaleTown_EventScript_BagIsFull
# 81 "data/maps/OldaleTown/scripts.pory"
	msgbox OldaleTown_Text_PotionExplanation, MSGBOX_DEFAULT
# 82 "data/maps/OldaleTown/scripts.pory"
	setflag FLAG_RECEIVED_POTION_OLDALE
# 83 "data/maps/OldaleTown/scripts.pory"
	fadedefaultbgm
# 84 "data/maps/OldaleTown/scripts.pory"
	release
# 85 "data/maps/OldaleTown/scripts.pory"
	end
# 86 "data/maps/OldaleTown/scripts.pory"

# 87 "data/maps/OldaleTown/scripts.pory"
OldaleTown_EventScript_ExplainPotion::
# 88 "data/maps/OldaleTown/scripts.pory"
	msgbox OldaleTown_Text_PotionExplanation, MSGBOX_DEFAULT
# 89 "data/maps/OldaleTown/scripts.pory"
	release
# 90 "data/maps/OldaleTown/scripts.pory"
	end
# 91 "data/maps/OldaleTown/scripts.pory"

# 92 "data/maps/OldaleTown/scripts.pory"
OldaleTown_EventScript_BagIsFull::
# 93 "data/maps/OldaleTown/scripts.pory"
	msgbox gText_TooBadBagIsFull, MSGBOX_DEFAULT
# 94 "data/maps/OldaleTown/scripts.pory"
	fadedefaultbgm
# 95 "data/maps/OldaleTown/scripts.pory"
	release
# 96 "data/maps/OldaleTown/scripts.pory"
	end
# 97 "data/maps/OldaleTown/scripts.pory"

# 98 "data/maps/OldaleTown/scripts.pory"
OldaleTown_Movement_EmployeeEast:
# 99 "data/maps/OldaleTown/scripts.pory"
	walk_up
# 100 "data/maps/OldaleTown/scripts.pory"
	walk_up
# 101 "data/maps/OldaleTown/scripts.pory"
	walk_up
# 102 "data/maps/OldaleTown/scripts.pory"
	walk_up
# 103 "data/maps/OldaleTown/scripts.pory"
	walk_up
# 104 "data/maps/OldaleTown/scripts.pory"
	walk_up
# 105 "data/maps/OldaleTown/scripts.pory"
	walk_up
# 106 "data/maps/OldaleTown/scripts.pory"
	walk_in_place_faster_down
# 107 "data/maps/OldaleTown/scripts.pory"
	step_end
# 108 "data/maps/OldaleTown/scripts.pory"

# 109 "data/maps/OldaleTown/scripts.pory"
OldaleTown_Movement_EmployeeSouth:
# 110 "data/maps/OldaleTown/scripts.pory"
	walk_left
# 111 "data/maps/OldaleTown/scripts.pory"
	walk_up
# 112 "data/maps/OldaleTown/scripts.pory"
	walk_up
# 113 "data/maps/OldaleTown/scripts.pory"
	walk_right
# 114 "data/maps/OldaleTown/scripts.pory"
	walk_up
# 115 "data/maps/OldaleTown/scripts.pory"
	walk_up
# 116 "data/maps/OldaleTown/scripts.pory"
	walk_up
# 117 "data/maps/OldaleTown/scripts.pory"
	walk_up
# 118 "data/maps/OldaleTown/scripts.pory"
	walk_up
# 119 "data/maps/OldaleTown/scripts.pory"
	walk_in_place_faster_down
# 120 "data/maps/OldaleTown/scripts.pory"
	step_end
# 121 "data/maps/OldaleTown/scripts.pory"

# 122 "data/maps/OldaleTown/scripts.pory"
OldaleTown_Movement_EmployeeNorth:
# 123 "data/maps/OldaleTown/scripts.pory"
	walk_up
# 124 "data/maps/OldaleTown/scripts.pory"
	walk_up
# 125 "data/maps/OldaleTown/scripts.pory"
	walk_up
# 126 "data/maps/OldaleTown/scripts.pory"
	walk_up
# 127 "data/maps/OldaleTown/scripts.pory"
	walk_up
# 128 "data/maps/OldaleTown/scripts.pory"
	walk_up
# 129 "data/maps/OldaleTown/scripts.pory"
	walk_up
# 130 "data/maps/OldaleTown/scripts.pory"
	walk_in_place_faster_down
# 131 "data/maps/OldaleTown/scripts.pory"
	step_end
# 132 "data/maps/OldaleTown/scripts.pory"

# 133 "data/maps/OldaleTown/scripts.pory"
OldaleTown_Movement_Unknown1:
# 134 "data/maps/OldaleTown/scripts.pory"
	walk_up
# 135 "data/maps/OldaleTown/scripts.pory"
	walk_up
# 136 "data/maps/OldaleTown/scripts.pory"
	walk_right
# 137 "data/maps/OldaleTown/scripts.pory"
	walk_right
# 138 "data/maps/OldaleTown/scripts.pory"
	walk_right
# 139 "data/maps/OldaleTown/scripts.pory"
	walk_right
# 140 "data/maps/OldaleTown/scripts.pory"
	walk_up
# 141 "data/maps/OldaleTown/scripts.pory"
	walk_up
# 142 "data/maps/OldaleTown/scripts.pory"
	walk_up
# 143 "data/maps/OldaleTown/scripts.pory"
	walk_up
# 144 "data/maps/OldaleTown/scripts.pory"
	walk_up
# 145 "data/maps/OldaleTown/scripts.pory"
	delay_8
# 146 "data/maps/OldaleTown/scripts.pory"
	walk_in_place_faster_down
# 147 "data/maps/OldaleTown/scripts.pory"
	step_end
# 148 "data/maps/OldaleTown/scripts.pory"

# 149 "data/maps/OldaleTown/scripts.pory"
OldaleTown_Movement_PlayerEast:
# 150 "data/maps/OldaleTown/scripts.pory"
	walk_right
# 151 "data/maps/OldaleTown/scripts.pory"
	walk_up
# 152 "data/maps/OldaleTown/scripts.pory"
	walk_up
# 153 "data/maps/OldaleTown/scripts.pory"
	walk_up
# 154 "data/maps/OldaleTown/scripts.pory"
	walk_up
# 155 "data/maps/OldaleTown/scripts.pory"
	walk_up
# 156 "data/maps/OldaleTown/scripts.pory"
	walk_up
# 157 "data/maps/OldaleTown/scripts.pory"
	step_end
# 158 "data/maps/OldaleTown/scripts.pory"

# 159 "data/maps/OldaleTown/scripts.pory"
OldaleTown_Movement_PlayerSouth:
# 160 "data/maps/OldaleTown/scripts.pory"
	delay_16
# 161 "data/maps/OldaleTown/scripts.pory"
	delay_16
# 162 "data/maps/OldaleTown/scripts.pory"
	delay_16
# 163 "data/maps/OldaleTown/scripts.pory"
	delay_16
# 164 "data/maps/OldaleTown/scripts.pory"
	walk_up
# 165 "data/maps/OldaleTown/scripts.pory"
	walk_up
# 166 "data/maps/OldaleTown/scripts.pory"
	walk_up
# 167 "data/maps/OldaleTown/scripts.pory"
	walk_up
# 168 "data/maps/OldaleTown/scripts.pory"
	walk_up
# 169 "data/maps/OldaleTown/scripts.pory"
	step_end
# 170 "data/maps/OldaleTown/scripts.pory"

# 171 "data/maps/OldaleTown/scripts.pory"
OldaleTown_Movement_PlayerNorth:
# 172 "data/maps/OldaleTown/scripts.pory"
	walk_up
# 173 "data/maps/OldaleTown/scripts.pory"
	walk_up
# 174 "data/maps/OldaleTown/scripts.pory"
	walk_up
# 175 "data/maps/OldaleTown/scripts.pory"
	walk_up
# 176 "data/maps/OldaleTown/scripts.pory"
	walk_up
# 177 "data/maps/OldaleTown/scripts.pory"
	walk_up
# 178 "data/maps/OldaleTown/scripts.pory"
	walk_up
# 179 "data/maps/OldaleTown/scripts.pory"
	step_end
# 180 "data/maps/OldaleTown/scripts.pory"

# 181 "data/maps/OldaleTown/scripts.pory"
OldaleTown_Movement_Unknown2:
# 182 "data/maps/OldaleTown/scripts.pory"
	walk_left
# 183 "data/maps/OldaleTown/scripts.pory"
	walk_up
# 184 "data/maps/OldaleTown/scripts.pory"
	walk_up
# 185 "data/maps/OldaleTown/scripts.pory"
	walk_right
# 186 "data/maps/OldaleTown/scripts.pory"
	walk_right
# 187 "data/maps/OldaleTown/scripts.pory"
	walk_right
# 188 "data/maps/OldaleTown/scripts.pory"
	walk_right
# 189 "data/maps/OldaleTown/scripts.pory"
	walk_up
# 190 "data/maps/OldaleTown/scripts.pory"
	walk_up
# 191 "data/maps/OldaleTown/scripts.pory"
	walk_up
# 192 "data/maps/OldaleTown/scripts.pory"
	walk_up
# 193 "data/maps/OldaleTown/scripts.pory"
	step_end
# 194 "data/maps/OldaleTown/scripts.pory"

# 195 "data/maps/OldaleTown/scripts.pory"
OldaleTown_EventScript_FootprintsMan::
# 196 "data/maps/OldaleTown/scripts.pory"
	lock
# 197 "data/maps/OldaleTown/scripts.pory"
	faceplayer
# 198 "data/maps/OldaleTown/scripts.pory"
	goto_if_set FLAG_ADVENTURE_STARTED, OldaleTown_EventScript_NotBlockingPath
# 199 "data/maps/OldaleTown/scripts.pory"
	msgbox OldaleTown_Text_DiscoveredFootprints, MSGBOX_DEFAULT
# 200 "data/maps/OldaleTown/scripts.pory"
	closemessage
# 201 "data/maps/OldaleTown/scripts.pory"
	applymovement LOCALID_FOOTPRINTS_MAN, Common_Movement_FaceOriginalDirection
# 202 "data/maps/OldaleTown/scripts.pory"
	waitmovement 0
# 203 "data/maps/OldaleTown/scripts.pory"
	release
# 204 "data/maps/OldaleTown/scripts.pory"
	end
# 205 "data/maps/OldaleTown/scripts.pory"

# 206 "data/maps/OldaleTown/scripts.pory"
OldaleTown_EventScript_BlockedPath::
# 207 "data/maps/OldaleTown/scripts.pory"
	lockall
# 208 "data/maps/OldaleTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, OldaleTown_Movement_PlayerStepBack
# 209 "data/maps/OldaleTown/scripts.pory"
	applymovement LOCALID_FOOTPRINTS_MAN, OldaleTown_Movement_BackUp
# 210 "data/maps/OldaleTown/scripts.pory"
	waitmovement 0
# 211 "data/maps/OldaleTown/scripts.pory"
	msgbox OldaleTown_Text_WaitDontComeInHere, MSGBOX_DEFAULT
# 212 "data/maps/OldaleTown/scripts.pory"
	closemessage
# 213 "data/maps/OldaleTown/scripts.pory"
	applymovement LOCALID_FOOTPRINTS_MAN, OldaleTown_Movement_ReturnToOriginalPosition
# 214 "data/maps/OldaleTown/scripts.pory"
	waitmovement 0
# 215 "data/maps/OldaleTown/scripts.pory"
	releaseall
# 216 "data/maps/OldaleTown/scripts.pory"
	end
# 217 "data/maps/OldaleTown/scripts.pory"

# 218 "data/maps/OldaleTown/scripts.pory"
OldaleTown_EventScript_NotBlockingPath::
# 219 "data/maps/OldaleTown/scripts.pory"
	msgbox OldaleTown_Text_FinishedSketchingFootprints, MSGBOX_DEFAULT
# 220 "data/maps/OldaleTown/scripts.pory"
	release
# 221 "data/maps/OldaleTown/scripts.pory"
	end
# 222 "data/maps/OldaleTown/scripts.pory"

# 223 "data/maps/OldaleTown/scripts.pory"
OldaleTown_EventScript_Rival::
# 224 "data/maps/OldaleTown/scripts.pory"
	lockall
# 225 "data/maps/OldaleTown/scripts.pory"
	applymovement LOCALID_RIVAL, Common_Movement_FacePlayer
# 226 "data/maps/OldaleTown/scripts.pory"
	waitmovement 0
# 227 "data/maps/OldaleTown/scripts.pory"
	setvar VAR_0x8009, 0
# 228 "data/maps/OldaleTown/scripts.pory"
	goto OldaleTown_EventScript_ShowRivalMessage
# 229 "data/maps/OldaleTown/scripts.pory"
	end
# 230 "data/maps/OldaleTown/scripts.pory"

# 231 "data/maps/OldaleTown/scripts.pory"
OldaleTown_EventScript_RivalTrigger1::
# 232 "data/maps/OldaleTown/scripts.pory"
	lockall
# 233 "data/maps/OldaleTown/scripts.pory"
	applymovement LOCALID_RIVAL, OldaleTown_Movement_RivalApproachPlayer1
# 234 "data/maps/OldaleTown/scripts.pory"
	waitmovement 0
# 235 "data/maps/OldaleTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterRight
# 236 "data/maps/OldaleTown/scripts.pory"
	waitmovement 0
# 237 "data/maps/OldaleTown/scripts.pory"
	setvar VAR_0x8009, 1
# 238 "data/maps/OldaleTown/scripts.pory"
	goto OldaleTown_EventScript_ShowRivalMessage
# 239 "data/maps/OldaleTown/scripts.pory"
	end
# 240 "data/maps/OldaleTown/scripts.pory"

# 241 "data/maps/OldaleTown/scripts.pory"
OldaleTown_EventScript_RivalTrigger2::
# 242 "data/maps/OldaleTown/scripts.pory"
	lockall
# 243 "data/maps/OldaleTown/scripts.pory"
	applymovement LOCALID_RIVAL, OldaleTown_Movement_RivalApproachPlayer2
# 244 "data/maps/OldaleTown/scripts.pory"
	waitmovement 0
# 245 "data/maps/OldaleTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterRight
# 246 "data/maps/OldaleTown/scripts.pory"
	waitmovement 0
# 247 "data/maps/OldaleTown/scripts.pory"
	setvar VAR_0x8009, 1
# 248 "data/maps/OldaleTown/scripts.pory"
	goto OldaleTown_EventScript_ShowRivalMessage
# 249 "data/maps/OldaleTown/scripts.pory"
	end
# 250 "data/maps/OldaleTown/scripts.pory"

# 251 "data/maps/OldaleTown/scripts.pory"
OldaleTown_EventScript_RivalTrigger3::
# 252 "data/maps/OldaleTown/scripts.pory"
	lockall
# 253 "data/maps/OldaleTown/scripts.pory"
	applymovement LOCALID_RIVAL, OldaleTown_Movement_RivalApproachPlayer3
# 254 "data/maps/OldaleTown/scripts.pory"
	waitmovement 0
# 255 "data/maps/OldaleTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterRight
# 256 "data/maps/OldaleTown/scripts.pory"
	waitmovement 0
# 257 "data/maps/OldaleTown/scripts.pory"
	setvar VAR_0x8009, 1
# 258 "data/maps/OldaleTown/scripts.pory"
	goto OldaleTown_EventScript_ShowRivalMessage
# 259 "data/maps/OldaleTown/scripts.pory"
	end
# 260 "data/maps/OldaleTown/scripts.pory"

# 261 "data/maps/OldaleTown/scripts.pory"
OldaleTown_EventScript_ShowRivalMessage::
# 262 "data/maps/OldaleTown/scripts.pory"
	checkplayergender
# 263 "data/maps/OldaleTown/scripts.pory"
	goto_if_eq VAR_RESULT, MALE, OldaleTown_EventScript_ShowMayMessage
# 264 "data/maps/OldaleTown/scripts.pory"
	goto_if_eq VAR_RESULT, FEMALE, OldaleTown_EventScript_ShowBrendanMessage
# 265 "data/maps/OldaleTown/scripts.pory"
	end
# 266 "data/maps/OldaleTown/scripts.pory"

# 267 "data/maps/OldaleTown/scripts.pory"
OldaleTown_EventScript_ShowMayMessage::
# 268 "data/maps/OldaleTown/scripts.pory"
	msgbox OldaleTown_Text_MayLetsGoBack, MSGBOX_DEFAULT
# 269 "data/maps/OldaleTown/scripts.pory"
	goto OldaleTown_EventScript_RivalFinish
# 270 "data/maps/OldaleTown/scripts.pory"
	end
# 271 "data/maps/OldaleTown/scripts.pory"

# 272 "data/maps/OldaleTown/scripts.pory"
OldaleTown_EventScript_ShowBrendanMessage::
# 273 "data/maps/OldaleTown/scripts.pory"
	msgbox OldaleTown_Text_BrendanLetsGoBack, MSGBOX_DEFAULT
# 274 "data/maps/OldaleTown/scripts.pory"
	goto OldaleTown_EventScript_RivalFinish
# 275 "data/maps/OldaleTown/scripts.pory"
	end
# 276 "data/maps/OldaleTown/scripts.pory"

# 277 "data/maps/OldaleTown/scripts.pory"
OldaleTown_EventScript_RivalFinish::
# 278 "data/maps/OldaleTown/scripts.pory"
	closemessage
# 279 "data/maps/OldaleTown/scripts.pory"
	call_if_eq VAR_0x8009, 0, OldaleTown_EventScript_DoExitMovement1
# 280 "data/maps/OldaleTown/scripts.pory"
	call_if_eq VAR_0x8009, 1, OldaleTown_EventScript_DoExitMovement2
# 281 "data/maps/OldaleTown/scripts.pory"
	applymovement LOCALID_RIVAL, OldaleTown_Movement_RivalExit
# 282 "data/maps/OldaleTown/scripts.pory"
	waitmovement 0
# 283 "data/maps/OldaleTown/scripts.pory"
	removeobject LOCALID_RIVAL
# 284 "data/maps/OldaleTown/scripts.pory"
	setvar VAR_OLDALE_RIVAL_STATE, 2
# 285 "data/maps/OldaleTown/scripts.pory"
	setflag FLAG_HIDE_OLDALE_TOWN_RIVAL
# 286 "data/maps/OldaleTown/scripts.pory"
	releaseall
# 287 "data/maps/OldaleTown/scripts.pory"
	end
# 288 "data/maps/OldaleTown/scripts.pory"

# 289 "data/maps/OldaleTown/scripts.pory"
OldaleTown_EventScript_DoExitMovement1::
# 290 "data/maps/OldaleTown/scripts.pory"
	goto_if_ne VAR_FACING, DIR_SOUTH, OldaleTown_EventScript_DoExitMovement2
# 291 "data/maps/OldaleTown/scripts.pory"
	applymovement LOCALID_RIVAL, OldaleTown_Movement_RivalExit
# 292 "data/maps/OldaleTown/scripts.pory"
	waitmovement 0
# 293 "data/maps/OldaleTown/scripts.pory"
	return
# 294 "data/maps/OldaleTown/scripts.pory"

# 295 "data/maps/OldaleTown/scripts.pory"
OldaleTown_EventScript_DoExitMovement2::
# 296 "data/maps/OldaleTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, OldaleTown_Movement_WatchRivalExit
# 297 "data/maps/OldaleTown/scripts.pory"
	applymovement LOCALID_RIVAL, OldaleTown_Movement_RivalExit
# 298 "data/maps/OldaleTown/scripts.pory"
	waitmovement 0
# 299 "data/maps/OldaleTown/scripts.pory"
	return
# 300 "data/maps/OldaleTown/scripts.pory"

# 301 "data/maps/OldaleTown/scripts.pory"
OldaleTown_Movement_RivalApproachPlayer1:
# 302 "data/maps/OldaleTown/scripts.pory"
	walk_left
# 303 "data/maps/OldaleTown/scripts.pory"
	walk_left
# 304 "data/maps/OldaleTown/scripts.pory"
	step_end
# 305 "data/maps/OldaleTown/scripts.pory"

# 306 "data/maps/OldaleTown/scripts.pory"
OldaleTown_Movement_RivalApproachPlayer2:
# 307 "data/maps/OldaleTown/scripts.pory"
	walk_left
# 308 "data/maps/OldaleTown/scripts.pory"
	step_end
# 309 "data/maps/OldaleTown/scripts.pory"

# 310 "data/maps/OldaleTown/scripts.pory"
OldaleTown_Movement_RivalApproachPlayer3:
# 311 "data/maps/OldaleTown/scripts.pory"
	face_left
# 312 "data/maps/OldaleTown/scripts.pory"
	step_end
# 313 "data/maps/OldaleTown/scripts.pory"

# 314 "data/maps/OldaleTown/scripts.pory"
OldaleTown_Movement_RivalExit:
# 315 "data/maps/OldaleTown/scripts.pory"
	walk_down
# 316 "data/maps/OldaleTown/scripts.pory"
	walk_down
# 317 "data/maps/OldaleTown/scripts.pory"
	walk_down
# 318 "data/maps/OldaleTown/scripts.pory"
	walk_down
# 319 "data/maps/OldaleTown/scripts.pory"
	walk_down
# 320 "data/maps/OldaleTown/scripts.pory"
	walk_down
# 321 "data/maps/OldaleTown/scripts.pory"
	step_end
# 322 "data/maps/OldaleTown/scripts.pory"

# 323 "data/maps/OldaleTown/scripts.pory"
OldaleTown_Movement_WatchRivalExit:
# 324 "data/maps/OldaleTown/scripts.pory"
	delay_8
# 325 "data/maps/OldaleTown/scripts.pory"
	delay_4
# 326 "data/maps/OldaleTown/scripts.pory"
	walk_in_place_faster_down
# 327 "data/maps/OldaleTown/scripts.pory"
	step_end
# 328 "data/maps/OldaleTown/scripts.pory"

# 329 "data/maps/OldaleTown/scripts.pory"
OldaleTown_Movement_PlayerStepBack:
# 330 "data/maps/OldaleTown/scripts.pory"
	delay_8
# 331 "data/maps/OldaleTown/scripts.pory"
	walk_right
# 332 "data/maps/OldaleTown/scripts.pory"
	step_end
# 333 "data/maps/OldaleTown/scripts.pory"

# 334 "data/maps/OldaleTown/scripts.pory"
OldaleTown_Movement_BackUp:
# 335 "data/maps/OldaleTown/scripts.pory"
	walk_fast_up
# 336 "data/maps/OldaleTown/scripts.pory"
	walk_in_place_faster_left
# 337 "data/maps/OldaleTown/scripts.pory"
	lock_facing_direction
# 338 "data/maps/OldaleTown/scripts.pory"
	walk_right
# 339 "data/maps/OldaleTown/scripts.pory"
	unlock_facing_direction
# 340 "data/maps/OldaleTown/scripts.pory"
	step_end
# 341 "data/maps/OldaleTown/scripts.pory"

# 342 "data/maps/OldaleTown/scripts.pory"
OldaleTown_Movement_ReturnToOriginalPosition:
# 343 "data/maps/OldaleTown/scripts.pory"
	walk_down
# 344 "data/maps/OldaleTown/scripts.pory"
	walk_left
# 345 "data/maps/OldaleTown/scripts.pory"
	step_end
# 346 "data/maps/OldaleTown/scripts.pory"

# 347 "data/maps/OldaleTown/scripts.pory"
OldaleTown_Text_SavingMyProgress:
# 348 "data/maps/OldaleTown/scripts.pory"
	.string "I want to take a rest, so I'm saving my\n"
# 349 "data/maps/OldaleTown/scripts.pory"
	.string "progress.$"
# 350 "data/maps/OldaleTown/scripts.pory"

# 351 "data/maps/OldaleTown/scripts.pory"
OldaleTown_Text_IWorkAtPokemonMart:
# 352 "data/maps/OldaleTown/scripts.pory"
	.string "Hi!\n"
# 353 "data/maps/OldaleTown/scripts.pory"
	.string "I work at a POKéMON MART.\p"
# 354 "data/maps/OldaleTown/scripts.pory"
	.string "Can I get you to come with me?$"
# 355 "data/maps/OldaleTown/scripts.pory"

# 356 "data/maps/OldaleTown/scripts.pory"
OldaleTown_Text_ThisIsAPokemonMart:
# 357 "data/maps/OldaleTown/scripts.pory"
	.string "This is a POKéMON MART.\n"
# 358 "data/maps/OldaleTown/scripts.pory"
	.string "Just look for our blue roof.\p"
# 359 "data/maps/OldaleTown/scripts.pory"
	.string "We sell a variety of goods including\n"
# 360 "data/maps/OldaleTown/scripts.pory"
	.string "POKé BALLS for catching POKéMON.\p"
# 361 "data/maps/OldaleTown/scripts.pory"
	.string "Here, I'd like you to have this as\n"
# 362 "data/maps/OldaleTown/scripts.pory"
	.string "a promotional item.$"
# 363 "data/maps/OldaleTown/scripts.pory"

# 364 "data/maps/OldaleTown/scripts.pory"
OldaleTown_Text_PotionExplanation:
# 365 "data/maps/OldaleTown/scripts.pory"
	.string "A POTION can be used anytime, so it's\n"
# 366 "data/maps/OldaleTown/scripts.pory"
	.string "even more useful than a POKéMON CENTER\l"
# 367 "data/maps/OldaleTown/scripts.pory"
	.string "in certain situations.$"
# 368 "data/maps/OldaleTown/scripts.pory"

# 369 "data/maps/OldaleTown/scripts.pory"
OldaleTown_Text_WaitDontComeInHere:
# 370 "data/maps/OldaleTown/scripts.pory"
	.string "Aaaaah! Wait!\n"
# 371 "data/maps/OldaleTown/scripts.pory"
	.string "Please don't come in here.\p"
# 372 "data/maps/OldaleTown/scripts.pory"
	.string "I just discovered the footprints of\n"
# 373 "data/maps/OldaleTown/scripts.pory"
	.string "a rare POKéMON!\p"
# 374 "data/maps/OldaleTown/scripts.pory"
	.string "Wait until I finish sketching\n"
# 375 "data/maps/OldaleTown/scripts.pory"
	.string "them, okay?$"
# 376 "data/maps/OldaleTown/scripts.pory"

# 377 "data/maps/OldaleTown/scripts.pory"
OldaleTown_Text_DiscoveredFootprints:
# 378 "data/maps/OldaleTown/scripts.pory"
	.string "I just discovered the footprints of\n"
# 379 "data/maps/OldaleTown/scripts.pory"
	.string "a rare POKéMON!\p"
# 380 "data/maps/OldaleTown/scripts.pory"
	.string "Wait until I finish sketching\n"
# 381 "data/maps/OldaleTown/scripts.pory"
	.string "them, okay?$"
# 382 "data/maps/OldaleTown/scripts.pory"

# 383 "data/maps/OldaleTown/scripts.pory"
OldaleTown_Text_FinishedSketchingFootprints:
# 384 "data/maps/OldaleTown/scripts.pory"
	.string "I finished sketching the footprints of\n"
# 385 "data/maps/OldaleTown/scripts.pory"
	.string "a rare POKéMON.\p"
# 386 "data/maps/OldaleTown/scripts.pory"
	.string "But it turns out they were only my\n"
# 387 "data/maps/OldaleTown/scripts.pory"
	.string "own footprints…$"
# 388 "data/maps/OldaleTown/scripts.pory"

# 389 "data/maps/OldaleTown/scripts.pory"
OldaleTown_Text_MayLetsGoBack:
# 390 "data/maps/OldaleTown/scripts.pory"
	.string "MAY: {PLAYER}{KUN}!\n"
# 391 "data/maps/OldaleTown/scripts.pory"
	.string "Over here!\l"
# 392 "data/maps/OldaleTown/scripts.pory"
	.string "Let's hurry home!$"
# 393 "data/maps/OldaleTown/scripts.pory"

# 394 "data/maps/OldaleTown/scripts.pory"
OldaleTown_Text_BrendanLetsGoBack:
# 395 "data/maps/OldaleTown/scripts.pory"
	.string "BRENDAN: I'm heading back to my dad's\n"
# 396 "data/maps/OldaleTown/scripts.pory"
	.string "LAB now.\l"
# 397 "data/maps/OldaleTown/scripts.pory"
	.string "{PLAYER}, you should hustle back, too.$"
# 398 "data/maps/OldaleTown/scripts.pory"

# 399 "data/maps/OldaleTown/scripts.pory"
OldaleTown_Text_TownSign:
# 400 "data/maps/OldaleTown/scripts.pory"
	.string "OLDALE TOWN\n"
# 401 "data/maps/OldaleTown/scripts.pory"
	.string "“Where things start off scarce.”$"
