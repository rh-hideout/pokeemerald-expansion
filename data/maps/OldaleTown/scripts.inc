# 1 "data/maps/OldaleTown/scripts.pory"

# 2 "data/maps/OldaleTown/scripts.pory"
OldaleTown_MapScripts::
# 3 "data/maps/OldaleTown/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, OldaleTown_OnTransition
# 4 "data/maps/OldaleTown/scripts.pory"
	.byte 0
# 5 "data/maps/OldaleTown/scripts.pory"

# 6 "data/maps/OldaleTown/scripts.pory"
OldaleTown_OnTransition:
# 7 "data/maps/OldaleTown/scripts.pory"
	call Common_EventScript_SetupRivalGfxId
# 8 "data/maps/OldaleTown/scripts.pory"
	setflag FLAG_VISITED_OLDALE_TOWN
# 9 "data/maps/OldaleTown/scripts.pory"
	call_if_unset FLAG_ADVENTURE_STARTED, OldaleTown_EventScript_BlockWestEntrance
# 10 "data/maps/OldaleTown/scripts.pory"
	call_if_unset FLAG_RECEIVED_POTION_OLDALE, OldaleTown_EventScript_MoveMartEmployee
# 11 "data/maps/OldaleTown/scripts.pory"
	call_if_set FLAG_ADVENTURE_STARTED, OldaleTown_EventScript_SetOldaleState
# 12 "data/maps/OldaleTown/scripts.pory"
	end
# 13 "data/maps/OldaleTown/scripts.pory"

# 14 "data/maps/OldaleTown/scripts.pory"
@ This script seems pointless because nothing uses VAR_OLDALE_TOWN_STATE
# 15 "data/maps/OldaleTown/scripts.pory"
OldaleTown_EventScript_SetOldaleState::
# 16 "data/maps/OldaleTown/scripts.pory"
	setvar VAR_OLDALE_TOWN_STATE, 1
# 17 "data/maps/OldaleTown/scripts.pory"
	return
# 18 "data/maps/OldaleTown/scripts.pory"

# 19 "data/maps/OldaleTown/scripts.pory"
OldaleTown_EventScript_BlockWestEntrance::
# 20 "data/maps/OldaleTown/scripts.pory"
	setobjectxyperm LOCALID_FOOTPRINTS_MAN, 1, 11
# 21 "data/maps/OldaleTown/scripts.pory"
	setobjectmovementtype LOCALID_FOOTPRINTS_MAN, MOVEMENT_TYPE_FACE_LEFT
# 22 "data/maps/OldaleTown/scripts.pory"
	return
# 23 "data/maps/OldaleTown/scripts.pory"

# 24 "data/maps/OldaleTown/scripts.pory"
OldaleTown_EventScript_MoveMartEmployee::
# 25 "data/maps/OldaleTown/scripts.pory"
	setobjectxyperm LOCALID_OLDALE_MART_EMPLOYEE, 13, 14
# 26 "data/maps/OldaleTown/scripts.pory"
	setobjectmovementtype LOCALID_OLDALE_MART_EMPLOYEE, MOVEMENT_TYPE_FACE_DOWN
# 27 "data/maps/OldaleTown/scripts.pory"
	return
# 28 "data/maps/OldaleTown/scripts.pory"

# 29 "data/maps/OldaleTown/scripts.pory"
OldaleTown_EventScript_TownSign::
# 30 "data/maps/OldaleTown/scripts.pory"
	msgbox OldaleTown_Text_TownSign, MSGBOX_SIGN
# 31 "data/maps/OldaleTown/scripts.pory"
	end
# 32 "data/maps/OldaleTown/scripts.pory"

# 33 "data/maps/OldaleTown/scripts.pory"

# 34 "data/maps/OldaleTown/scripts.pory"

# 35 "data/maps/OldaleTown/scripts.pory"
OldaleTown_EventScript_MartEmployee::
# 36 "data/maps/OldaleTown/scripts.pory"
	lock
# 37 "data/maps/OldaleTown/scripts.pory"
	faceplayer
# 38 "data/maps/OldaleTown/scripts.pory"
	goto_if_set FLAG_RECEIVED_POTION_OLDALE, OldaleTown_EventScript_ExplainPotion
# 39 "data/maps/OldaleTown/scripts.pory"
	goto_if_set FLAG_TEMP_1, OldaleTown_EventScript_ExplainPotion
# 40 "data/maps/OldaleTown/scripts.pory"
	setflag FLAG_TEMP_1
# 41 "data/maps/OldaleTown/scripts.pory"
	playbgm MUS_FOLLOW_ME, FALSE
# 42 "data/maps/OldaleTown/scripts.pory"
	msgbox OldaleTown_Text_IWorkAtPokemonMart, MSGBOX_DEFAULT
# 43 "data/maps/OldaleTown/scripts.pory"
	closemessage
# 44 "data/maps/OldaleTown/scripts.pory"
	switch VAR_FACING
# 45 "data/maps/OldaleTown/scripts.pory"
	case DIR_SOUTH, OldaleTown_EventScript_GoToMartSouth
# 46 "data/maps/OldaleTown/scripts.pory"
	case DIR_NORTH, OldaleTown_EventScript_GoToMartNorth
# 47 "data/maps/OldaleTown/scripts.pory"
	case DIR_EAST, OldaleTown_EventScript_GoToMartEast
# 48 "data/maps/OldaleTown/scripts.pory"
	end
# 49 "data/maps/OldaleTown/scripts.pory"

# 50 "data/maps/OldaleTown/scripts.pory"
OldaleTown_EventScript_GoToMartSouth::
# 51 "data/maps/OldaleTown/scripts.pory"
	applymovement LOCALID_OLDALE_MART_EMPLOYEE, OldaleTown_Movement_EmployeeSouth
# 52 "data/maps/OldaleTown/scripts.pory"
	applymovement LOCALID_PLAYER, OldaleTown_Movement_PlayerSouth
# 53 "data/maps/OldaleTown/scripts.pory"
	waitmovement 0
# 54 "data/maps/OldaleTown/scripts.pory"
	goto OldaleTown_EventScript_ExplainPokemonMart
# 55 "data/maps/OldaleTown/scripts.pory"
	end
# 56 "data/maps/OldaleTown/scripts.pory"

# 57 "data/maps/OldaleTown/scripts.pory"
OldaleTown_EventScript_GoToMartNorth::
# 58 "data/maps/OldaleTown/scripts.pory"
	applymovement LOCALID_OLDALE_MART_EMPLOYEE, OldaleTown_Movement_EmployeeNorth
# 59 "data/maps/OldaleTown/scripts.pory"
	applymovement LOCALID_PLAYER, OldaleTown_Movement_PlayerNorth
# 60 "data/maps/OldaleTown/scripts.pory"
	waitmovement 0
# 61 "data/maps/OldaleTown/scripts.pory"
	goto OldaleTown_EventScript_ExplainPokemonMart
# 62 "data/maps/OldaleTown/scripts.pory"
	end
# 63 "data/maps/OldaleTown/scripts.pory"

# 64 "data/maps/OldaleTown/scripts.pory"
OldaleTown_EventScript_GoToMartEast::
# 65 "data/maps/OldaleTown/scripts.pory"
	applymovement LOCALID_PLAYER, OldaleTown_Movement_PlayerEast
# 66 "data/maps/OldaleTown/scripts.pory"
	applymovement LOCALID_OLDALE_MART_EMPLOYEE, OldaleTown_Movement_EmployeeEast
# 67 "data/maps/OldaleTown/scripts.pory"
	waitmovement 0
# 68 "data/maps/OldaleTown/scripts.pory"
	goto OldaleTown_EventScript_ExplainPokemonMart
# 69 "data/maps/OldaleTown/scripts.pory"
	end
# 70 "data/maps/OldaleTown/scripts.pory"

# 71 "data/maps/OldaleTown/scripts.pory"
OldaleTown_EventScript_ExplainPokemonMart::
# 72 "data/maps/OldaleTown/scripts.pory"
	msgbox OldaleTown_Text_ThisIsAPokemonMart, MSGBOX_DEFAULT
# 73 "data/maps/OldaleTown/scripts.pory"
	giveitem ITEM_POTION
# 74 "data/maps/OldaleTown/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, OldaleTown_EventScript_BagIsFull
# 75 "data/maps/OldaleTown/scripts.pory"
	msgbox OldaleTown_Text_PotionExplanation, MSGBOX_DEFAULT
# 76 "data/maps/OldaleTown/scripts.pory"
	setflag FLAG_RECEIVED_POTION_OLDALE
# 77 "data/maps/OldaleTown/scripts.pory"
	fadedefaultbgm
# 78 "data/maps/OldaleTown/scripts.pory"
	release
# 79 "data/maps/OldaleTown/scripts.pory"
	end
# 80 "data/maps/OldaleTown/scripts.pory"

# 81 "data/maps/OldaleTown/scripts.pory"
OldaleTown_EventScript_ExplainPotion::
# 82 "data/maps/OldaleTown/scripts.pory"
	msgbox OldaleTown_Text_PotionExplanation, MSGBOX_DEFAULT
# 83 "data/maps/OldaleTown/scripts.pory"
	release
# 84 "data/maps/OldaleTown/scripts.pory"
	end
# 85 "data/maps/OldaleTown/scripts.pory"

# 86 "data/maps/OldaleTown/scripts.pory"
OldaleTown_EventScript_BagIsFull::
# 87 "data/maps/OldaleTown/scripts.pory"
	msgbox gText_TooBadBagIsFull, MSGBOX_DEFAULT
# 88 "data/maps/OldaleTown/scripts.pory"
	fadedefaultbgm
# 89 "data/maps/OldaleTown/scripts.pory"
	release
# 90 "data/maps/OldaleTown/scripts.pory"
	end
# 91 "data/maps/OldaleTown/scripts.pory"

# 92 "data/maps/OldaleTown/scripts.pory"
OldaleTown_Movement_EmployeeEast:
# 93 "data/maps/OldaleTown/scripts.pory"
	walk_up
# 94 "data/maps/OldaleTown/scripts.pory"
	walk_up
# 95 "data/maps/OldaleTown/scripts.pory"
	walk_up
# 96 "data/maps/OldaleTown/scripts.pory"
	walk_up
# 97 "data/maps/OldaleTown/scripts.pory"
	walk_up
# 98 "data/maps/OldaleTown/scripts.pory"
	walk_up
# 99 "data/maps/OldaleTown/scripts.pory"
	walk_up
# 100 "data/maps/OldaleTown/scripts.pory"
	walk_in_place_faster_down
# 101 "data/maps/OldaleTown/scripts.pory"
	step_end
# 102 "data/maps/OldaleTown/scripts.pory"

# 103 "data/maps/OldaleTown/scripts.pory"
OldaleTown_Movement_EmployeeSouth:
# 104 "data/maps/OldaleTown/scripts.pory"
	walk_left
# 105 "data/maps/OldaleTown/scripts.pory"
	walk_up
# 106 "data/maps/OldaleTown/scripts.pory"
	walk_up
# 107 "data/maps/OldaleTown/scripts.pory"
	walk_right
# 108 "data/maps/OldaleTown/scripts.pory"
	walk_up
# 109 "data/maps/OldaleTown/scripts.pory"
	walk_up
# 110 "data/maps/OldaleTown/scripts.pory"
	walk_up
# 111 "data/maps/OldaleTown/scripts.pory"
	walk_up
# 112 "data/maps/OldaleTown/scripts.pory"
	walk_up
# 113 "data/maps/OldaleTown/scripts.pory"
	walk_in_place_faster_down
# 114 "data/maps/OldaleTown/scripts.pory"
	step_end
# 115 "data/maps/OldaleTown/scripts.pory"

# 116 "data/maps/OldaleTown/scripts.pory"
OldaleTown_Movement_EmployeeNorth:
# 117 "data/maps/OldaleTown/scripts.pory"
	walk_up
# 118 "data/maps/OldaleTown/scripts.pory"
	walk_up
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
OldaleTown_Movement_Unknown1:
# 128 "data/maps/OldaleTown/scripts.pory"
	walk_up
# 129 "data/maps/OldaleTown/scripts.pory"
	walk_up
# 130 "data/maps/OldaleTown/scripts.pory"
	walk_right
# 131 "data/maps/OldaleTown/scripts.pory"
	walk_right
# 132 "data/maps/OldaleTown/scripts.pory"
	walk_right
# 133 "data/maps/OldaleTown/scripts.pory"
	walk_right
# 134 "data/maps/OldaleTown/scripts.pory"
	walk_up
# 135 "data/maps/OldaleTown/scripts.pory"
	walk_up
# 136 "data/maps/OldaleTown/scripts.pory"
	walk_up
# 137 "data/maps/OldaleTown/scripts.pory"
	walk_up
# 138 "data/maps/OldaleTown/scripts.pory"
	walk_up
# 139 "data/maps/OldaleTown/scripts.pory"
	delay_8
# 140 "data/maps/OldaleTown/scripts.pory"
	walk_in_place_faster_down
# 141 "data/maps/OldaleTown/scripts.pory"
	step_end
# 142 "data/maps/OldaleTown/scripts.pory"

# 143 "data/maps/OldaleTown/scripts.pory"
OldaleTown_Movement_PlayerEast:
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
	walk_up
# 151 "data/maps/OldaleTown/scripts.pory"
	step_end
# 152 "data/maps/OldaleTown/scripts.pory"

# 153 "data/maps/OldaleTown/scripts.pory"
OldaleTown_Movement_PlayerSouth:
# 154 "data/maps/OldaleTown/scripts.pory"
	delay_16
# 155 "data/maps/OldaleTown/scripts.pory"
	delay_16
# 156 "data/maps/OldaleTown/scripts.pory"
	delay_16
# 157 "data/maps/OldaleTown/scripts.pory"
	delay_16
# 158 "data/maps/OldaleTown/scripts.pory"
	walk_up
# 159 "data/maps/OldaleTown/scripts.pory"
	walk_up
# 160 "data/maps/OldaleTown/scripts.pory"
	walk_up
# 161 "data/maps/OldaleTown/scripts.pory"
	walk_up
# 162 "data/maps/OldaleTown/scripts.pory"
	walk_up
# 163 "data/maps/OldaleTown/scripts.pory"
	step_end
# 164 "data/maps/OldaleTown/scripts.pory"

# 165 "data/maps/OldaleTown/scripts.pory"
OldaleTown_Movement_PlayerNorth:
# 166 "data/maps/OldaleTown/scripts.pory"
	walk_up
# 167 "data/maps/OldaleTown/scripts.pory"
	walk_up
# 168 "data/maps/OldaleTown/scripts.pory"
	walk_up
# 169 "data/maps/OldaleTown/scripts.pory"
	walk_up
# 170 "data/maps/OldaleTown/scripts.pory"
	walk_up
# 171 "data/maps/OldaleTown/scripts.pory"
	walk_up
# 172 "data/maps/OldaleTown/scripts.pory"
	walk_up
# 173 "data/maps/OldaleTown/scripts.pory"
	step_end
# 174 "data/maps/OldaleTown/scripts.pory"

# 175 "data/maps/OldaleTown/scripts.pory"
OldaleTown_Movement_Unknown2:
# 176 "data/maps/OldaleTown/scripts.pory"
	walk_left
# 177 "data/maps/OldaleTown/scripts.pory"
	walk_up
# 178 "data/maps/OldaleTown/scripts.pory"
	walk_up
# 179 "data/maps/OldaleTown/scripts.pory"
	walk_right
# 180 "data/maps/OldaleTown/scripts.pory"
	walk_right
# 181 "data/maps/OldaleTown/scripts.pory"
	walk_right
# 182 "data/maps/OldaleTown/scripts.pory"
	walk_right
# 183 "data/maps/OldaleTown/scripts.pory"
	walk_up
# 184 "data/maps/OldaleTown/scripts.pory"
	walk_up
# 185 "data/maps/OldaleTown/scripts.pory"
	walk_up
# 186 "data/maps/OldaleTown/scripts.pory"
	walk_up
# 187 "data/maps/OldaleTown/scripts.pory"
	step_end
# 188 "data/maps/OldaleTown/scripts.pory"

# 189 "data/maps/OldaleTown/scripts.pory"
OldaleTown_EventScript_FootprintsMan::
# 190 "data/maps/OldaleTown/scripts.pory"
	lock
# 191 "data/maps/OldaleTown/scripts.pory"
	faceplayer
# 192 "data/maps/OldaleTown/scripts.pory"
	goto_if_set FLAG_ADVENTURE_STARTED, OldaleTown_EventScript_NotBlockingPath
# 193 "data/maps/OldaleTown/scripts.pory"
	msgbox OldaleTown_Text_DiscoveredFootprints, MSGBOX_DEFAULT
# 194 "data/maps/OldaleTown/scripts.pory"
	closemessage
# 195 "data/maps/OldaleTown/scripts.pory"
	applymovement LOCALID_FOOTPRINTS_MAN, Common_Movement_FaceOriginalDirection
# 196 "data/maps/OldaleTown/scripts.pory"
	waitmovement 0
# 197 "data/maps/OldaleTown/scripts.pory"
	release
# 198 "data/maps/OldaleTown/scripts.pory"
	end
# 199 "data/maps/OldaleTown/scripts.pory"

# 200 "data/maps/OldaleTown/scripts.pory"
OldaleTown_EventScript_BlockedPath::
# 201 "data/maps/OldaleTown/scripts.pory"
	lockall
# 202 "data/maps/OldaleTown/scripts.pory"
	applymovement LOCALID_PLAYER, OldaleTown_Movement_PlayerStepBack
# 203 "data/maps/OldaleTown/scripts.pory"
	applymovement LOCALID_FOOTPRINTS_MAN, OldaleTown_Movement_BackUp
# 204 "data/maps/OldaleTown/scripts.pory"
	waitmovement 0
# 205 "data/maps/OldaleTown/scripts.pory"
	msgbox OldaleTown_Text_WaitDontComeInHere, MSGBOX_DEFAULT
# 206 "data/maps/OldaleTown/scripts.pory"
	closemessage
# 207 "data/maps/OldaleTown/scripts.pory"
	applymovement LOCALID_FOOTPRINTS_MAN, OldaleTown_Movement_ReturnToOriginalPosition
# 208 "data/maps/OldaleTown/scripts.pory"
	waitmovement 0
# 209 "data/maps/OldaleTown/scripts.pory"
	releaseall
# 210 "data/maps/OldaleTown/scripts.pory"
	end
# 211 "data/maps/OldaleTown/scripts.pory"

# 212 "data/maps/OldaleTown/scripts.pory"
OldaleTown_EventScript_NotBlockingPath::
# 213 "data/maps/OldaleTown/scripts.pory"
	msgbox OldaleTown_Text_FinishedSketchingFootprints, MSGBOX_DEFAULT
# 214 "data/maps/OldaleTown/scripts.pory"
	release
# 215 "data/maps/OldaleTown/scripts.pory"
	end
# 216 "data/maps/OldaleTown/scripts.pory"

# 217 "data/maps/OldaleTown/scripts.pory"
OldaleTown_EventScript_Rival::
# 218 "data/maps/OldaleTown/scripts.pory"
	lockall
# 219 "data/maps/OldaleTown/scripts.pory"
	applymovement LOCALID_OLDALE_RIVAL, Common_Movement_FacePlayer
# 220 "data/maps/OldaleTown/scripts.pory"
	waitmovement 0
# 221 "data/maps/OldaleTown/scripts.pory"
	setvar VAR_0x8009, 0
# 222 "data/maps/OldaleTown/scripts.pory"
	goto OldaleTown_EventScript_ShowRivalMessage
# 223 "data/maps/OldaleTown/scripts.pory"
	end
# 224 "data/maps/OldaleTown/scripts.pory"

# 225 "data/maps/OldaleTown/scripts.pory"
OldaleTown_EventScript_RivalTrigger1::
# 226 "data/maps/OldaleTown/scripts.pory"
	lockall
# 227 "data/maps/OldaleTown/scripts.pory"
	applymovement LOCALID_OLDALE_RIVAL, OldaleTown_Movement_RivalApproachPlayer1
# 228 "data/maps/OldaleTown/scripts.pory"
	waitmovement 0
# 229 "data/maps/OldaleTown/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterRight
# 230 "data/maps/OldaleTown/scripts.pory"
	waitmovement 0
# 231 "data/maps/OldaleTown/scripts.pory"
	setvar VAR_0x8009, 1
# 232 "data/maps/OldaleTown/scripts.pory"
	goto OldaleTown_EventScript_ShowRivalMessage
# 233 "data/maps/OldaleTown/scripts.pory"
	end
# 234 "data/maps/OldaleTown/scripts.pory"

# 235 "data/maps/OldaleTown/scripts.pory"
OldaleTown_EventScript_RivalTrigger2::
# 236 "data/maps/OldaleTown/scripts.pory"
	lockall
# 237 "data/maps/OldaleTown/scripts.pory"
	applymovement LOCALID_OLDALE_RIVAL, OldaleTown_Movement_RivalApproachPlayer2
# 238 "data/maps/OldaleTown/scripts.pory"
	waitmovement 0
# 239 "data/maps/OldaleTown/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterRight
# 240 "data/maps/OldaleTown/scripts.pory"
	waitmovement 0
# 241 "data/maps/OldaleTown/scripts.pory"
	setvar VAR_0x8009, 1
# 242 "data/maps/OldaleTown/scripts.pory"
	goto OldaleTown_EventScript_ShowRivalMessage
# 243 "data/maps/OldaleTown/scripts.pory"
	end
# 244 "data/maps/OldaleTown/scripts.pory"

# 245 "data/maps/OldaleTown/scripts.pory"
OldaleTown_EventScript_RivalTrigger3::
# 246 "data/maps/OldaleTown/scripts.pory"
	lockall
# 247 "data/maps/OldaleTown/scripts.pory"
	applymovement LOCALID_OLDALE_RIVAL, OldaleTown_Movement_RivalApproachPlayer3
# 248 "data/maps/OldaleTown/scripts.pory"
	waitmovement 0
# 249 "data/maps/OldaleTown/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterRight
# 250 "data/maps/OldaleTown/scripts.pory"
	waitmovement 0
# 251 "data/maps/OldaleTown/scripts.pory"
	setvar VAR_0x8009, 1
# 252 "data/maps/OldaleTown/scripts.pory"
	goto OldaleTown_EventScript_ShowRivalMessage
# 253 "data/maps/OldaleTown/scripts.pory"
	end
# 254 "data/maps/OldaleTown/scripts.pory"

# 255 "data/maps/OldaleTown/scripts.pory"
OldaleTown_EventScript_ShowRivalMessage::
# 256 "data/maps/OldaleTown/scripts.pory"
	checkplayergender
# 257 "data/maps/OldaleTown/scripts.pory"
	goto_if_eq VAR_RESULT, MALE, OldaleTown_EventScript_ShowMayMessage
# 258 "data/maps/OldaleTown/scripts.pory"
	goto_if_eq VAR_RESULT, FEMALE, OldaleTown_EventScript_ShowBrendanMessage
# 259 "data/maps/OldaleTown/scripts.pory"
	end
# 260 "data/maps/OldaleTown/scripts.pory"

# 261 "data/maps/OldaleTown/scripts.pory"
OldaleTown_EventScript_ShowMayMessage::
# 262 "data/maps/OldaleTown/scripts.pory"
	msgbox OldaleTown_Text_MayLetsGoBack, MSGBOX_DEFAULT
# 263 "data/maps/OldaleTown/scripts.pory"
	goto OldaleTown_EventScript_RivalFinish
# 264 "data/maps/OldaleTown/scripts.pory"
	end
# 265 "data/maps/OldaleTown/scripts.pory"

# 266 "data/maps/OldaleTown/scripts.pory"
OldaleTown_EventScript_ShowBrendanMessage::
# 267 "data/maps/OldaleTown/scripts.pory"
	msgbox OldaleTown_Text_BrendanLetsGoBack, MSGBOX_DEFAULT
# 268 "data/maps/OldaleTown/scripts.pory"
	goto OldaleTown_EventScript_RivalFinish
# 269 "data/maps/OldaleTown/scripts.pory"
	end
# 270 "data/maps/OldaleTown/scripts.pory"

# 271 "data/maps/OldaleTown/scripts.pory"
OldaleTown_EventScript_RivalFinish::
# 272 "data/maps/OldaleTown/scripts.pory"
	closemessage
# 273 "data/maps/OldaleTown/scripts.pory"
	call_if_eq VAR_0x8009, 0, OldaleTown_EventScript_DoExitMovement1
# 274 "data/maps/OldaleTown/scripts.pory"
	call_if_eq VAR_0x8009, 1, OldaleTown_EventScript_DoExitMovement2
# 275 "data/maps/OldaleTown/scripts.pory"
	applymovement LOCALID_OLDALE_RIVAL, OldaleTown_Movement_RivalExit
# 276 "data/maps/OldaleTown/scripts.pory"
	waitmovement 0
# 277 "data/maps/OldaleTown/scripts.pory"
	removeobject LOCALID_OLDALE_RIVAL
# 278 "data/maps/OldaleTown/scripts.pory"
	setvar VAR_OLDALE_RIVAL_STATE, 2
# 279 "data/maps/OldaleTown/scripts.pory"
	setflag FLAG_HIDE_OLDALE_TOWN_RIVAL
# 280 "data/maps/OldaleTown/scripts.pory"
	releaseall
# 281 "data/maps/OldaleTown/scripts.pory"
	end
# 282 "data/maps/OldaleTown/scripts.pory"

# 283 "data/maps/OldaleTown/scripts.pory"
OldaleTown_EventScript_DoExitMovement1::
# 284 "data/maps/OldaleTown/scripts.pory"
	goto_if_ne VAR_FACING, DIR_SOUTH, OldaleTown_EventScript_DoExitMovement2
# 285 "data/maps/OldaleTown/scripts.pory"
	applymovement LOCALID_OLDALE_RIVAL, OldaleTown_Movement_RivalExit
# 286 "data/maps/OldaleTown/scripts.pory"
	waitmovement 0
# 287 "data/maps/OldaleTown/scripts.pory"
	return
# 288 "data/maps/OldaleTown/scripts.pory"

# 289 "data/maps/OldaleTown/scripts.pory"
OldaleTown_EventScript_DoExitMovement2::
# 290 "data/maps/OldaleTown/scripts.pory"
	applymovement LOCALID_PLAYER, OldaleTown_Movement_WatchRivalExit
# 291 "data/maps/OldaleTown/scripts.pory"
	applymovement LOCALID_OLDALE_RIVAL, OldaleTown_Movement_RivalExit
# 292 "data/maps/OldaleTown/scripts.pory"
	waitmovement 0
# 293 "data/maps/OldaleTown/scripts.pory"
	return
# 294 "data/maps/OldaleTown/scripts.pory"

# 295 "data/maps/OldaleTown/scripts.pory"
OldaleTown_Movement_RivalApproachPlayer1:
# 296 "data/maps/OldaleTown/scripts.pory"
	walk_left
# 297 "data/maps/OldaleTown/scripts.pory"
	walk_left
# 298 "data/maps/OldaleTown/scripts.pory"
	step_end
# 299 "data/maps/OldaleTown/scripts.pory"

# 300 "data/maps/OldaleTown/scripts.pory"
OldaleTown_Movement_RivalApproachPlayer2:
# 301 "data/maps/OldaleTown/scripts.pory"
	walk_left
# 302 "data/maps/OldaleTown/scripts.pory"
	step_end
# 303 "data/maps/OldaleTown/scripts.pory"

# 304 "data/maps/OldaleTown/scripts.pory"
OldaleTown_Movement_RivalApproachPlayer3:
# 305 "data/maps/OldaleTown/scripts.pory"
	face_left
# 306 "data/maps/OldaleTown/scripts.pory"
	step_end
# 307 "data/maps/OldaleTown/scripts.pory"

# 308 "data/maps/OldaleTown/scripts.pory"
OldaleTown_Movement_RivalExit:
# 309 "data/maps/OldaleTown/scripts.pory"
	walk_down
# 310 "data/maps/OldaleTown/scripts.pory"
	walk_down
# 311 "data/maps/OldaleTown/scripts.pory"
	walk_down
# 312 "data/maps/OldaleTown/scripts.pory"
	walk_down
# 313 "data/maps/OldaleTown/scripts.pory"
	walk_down
# 314 "data/maps/OldaleTown/scripts.pory"
	walk_down
# 315 "data/maps/OldaleTown/scripts.pory"
	step_end
# 316 "data/maps/OldaleTown/scripts.pory"

# 317 "data/maps/OldaleTown/scripts.pory"
OldaleTown_Movement_WatchRivalExit:
# 318 "data/maps/OldaleTown/scripts.pory"
	delay_8
# 319 "data/maps/OldaleTown/scripts.pory"
	delay_4
# 320 "data/maps/OldaleTown/scripts.pory"
	walk_in_place_faster_down
# 321 "data/maps/OldaleTown/scripts.pory"
	step_end
# 322 "data/maps/OldaleTown/scripts.pory"

# 323 "data/maps/OldaleTown/scripts.pory"
OldaleTown_Movement_PlayerStepBack:
# 324 "data/maps/OldaleTown/scripts.pory"
	delay_8
# 325 "data/maps/OldaleTown/scripts.pory"
	walk_right
# 326 "data/maps/OldaleTown/scripts.pory"
	step_end
# 327 "data/maps/OldaleTown/scripts.pory"

# 328 "data/maps/OldaleTown/scripts.pory"
OldaleTown_Movement_BackUp:
# 329 "data/maps/OldaleTown/scripts.pory"
	walk_fast_up
# 330 "data/maps/OldaleTown/scripts.pory"
	walk_in_place_faster_left
# 331 "data/maps/OldaleTown/scripts.pory"
	lock_facing_direction
# 332 "data/maps/OldaleTown/scripts.pory"
	walk_right
# 333 "data/maps/OldaleTown/scripts.pory"
	unlock_facing_direction
# 334 "data/maps/OldaleTown/scripts.pory"
	step_end
# 335 "data/maps/OldaleTown/scripts.pory"

# 336 "data/maps/OldaleTown/scripts.pory"
OldaleTown_Movement_ReturnToOriginalPosition:
# 337 "data/maps/OldaleTown/scripts.pory"
	walk_down
# 338 "data/maps/OldaleTown/scripts.pory"
	walk_left
# 339 "data/maps/OldaleTown/scripts.pory"
	step_end
# 340 "data/maps/OldaleTown/scripts.pory"

# 341 "data/maps/OldaleTown/scripts.pory"
OldaleTown_Text_IWorkAtPokemonMart:
# 342 "data/maps/OldaleTown/scripts.pory"
	.string "Hi!\n"
# 343 "data/maps/OldaleTown/scripts.pory"
	.string "I work at a POKéMON MART.\p"
# 344 "data/maps/OldaleTown/scripts.pory"
	.string "Can I get you to come with me?$"
# 345 "data/maps/OldaleTown/scripts.pory"

# 346 "data/maps/OldaleTown/scripts.pory"
OldaleTown_Text_ThisIsAPokemonMart:
# 347 "data/maps/OldaleTown/scripts.pory"
	.string "This is a POKéMON MART.\n"
# 348 "data/maps/OldaleTown/scripts.pory"
	.string "Just look for our blue roof.\p"
# 349 "data/maps/OldaleTown/scripts.pory"
	.string "We sell a variety of goods including\n"
# 350 "data/maps/OldaleTown/scripts.pory"
	.string "POKé BALLS for catching POKéMON.\p"
# 351 "data/maps/OldaleTown/scripts.pory"
	.string "Here, I'd like you to have this as\n"
# 352 "data/maps/OldaleTown/scripts.pory"
	.string "a promotional item.$"
# 353 "data/maps/OldaleTown/scripts.pory"

# 354 "data/maps/OldaleTown/scripts.pory"
OldaleTown_Text_PotionExplanation:
# 355 "data/maps/OldaleTown/scripts.pory"
	.string "A POTION can be used anytime, so it's\n"
# 356 "data/maps/OldaleTown/scripts.pory"
	.string "even more useful than a POKéMON CENTER\l"
# 357 "data/maps/OldaleTown/scripts.pory"
	.string "in certain situations.$"
# 358 "data/maps/OldaleTown/scripts.pory"

# 359 "data/maps/OldaleTown/scripts.pory"
OldaleTown_Text_WaitDontComeInHere:
# 360 "data/maps/OldaleTown/scripts.pory"
	.string "Aaaaah! Wait!\n"
# 361 "data/maps/OldaleTown/scripts.pory"
	.string "Please don't come in here.\p"
# 362 "data/maps/OldaleTown/scripts.pory"
	.string "I just discovered the footprints of\n"
# 363 "data/maps/OldaleTown/scripts.pory"
	.string "a rare POKéMON!\p"
# 364 "data/maps/OldaleTown/scripts.pory"
	.string "Wait until I finish sketching\n"
# 365 "data/maps/OldaleTown/scripts.pory"
	.string "them, okay?$"
# 366 "data/maps/OldaleTown/scripts.pory"

# 367 "data/maps/OldaleTown/scripts.pory"
OldaleTown_Text_DiscoveredFootprints:
# 368 "data/maps/OldaleTown/scripts.pory"
	.string "I just discovered the footprints of\n"
# 369 "data/maps/OldaleTown/scripts.pory"
	.string "a rare POKéMON!\p"
# 370 "data/maps/OldaleTown/scripts.pory"
	.string "Wait until I finish sketching\n"
# 371 "data/maps/OldaleTown/scripts.pory"
	.string "them, okay?$"
# 372 "data/maps/OldaleTown/scripts.pory"

# 373 "data/maps/OldaleTown/scripts.pory"
OldaleTown_Text_FinishedSketchingFootprints:
# 374 "data/maps/OldaleTown/scripts.pory"
	.string "I finished sketching the footprints of\n"
# 375 "data/maps/OldaleTown/scripts.pory"
	.string "a rare POKéMON.\p"
# 376 "data/maps/OldaleTown/scripts.pory"
	.string "But it turns out they were only my\n"
# 377 "data/maps/OldaleTown/scripts.pory"
	.string "own footprints…$"
# 378 "data/maps/OldaleTown/scripts.pory"

# 379 "data/maps/OldaleTown/scripts.pory"
OldaleTown_Text_MayLetsGoBack:
# 380 "data/maps/OldaleTown/scripts.pory"
	.string "MAY: {PLAYER}{KUN}!\n"
# 381 "data/maps/OldaleTown/scripts.pory"
	.string "Over here!\l"
# 382 "data/maps/OldaleTown/scripts.pory"
	.string "Let's hurry home!$"
# 383 "data/maps/OldaleTown/scripts.pory"

# 384 "data/maps/OldaleTown/scripts.pory"
OldaleTown_Text_BrendanLetsGoBack:
# 385 "data/maps/OldaleTown/scripts.pory"
	.string "BRENDAN: I'm heading back to my dad's\n"
# 386 "data/maps/OldaleTown/scripts.pory"
	.string "LAB now.\l"
# 387 "data/maps/OldaleTown/scripts.pory"
	.string "{PLAYER}, you should hustle back, too.$"
# 388 "data/maps/OldaleTown/scripts.pory"

# 389 "data/maps/OldaleTown/scripts.pory"
OldaleTown_Text_TownSign:
# 390 "data/maps/OldaleTown/scripts.pory"
	.string "OLDALE TOWN\n"
# 391 "data/maps/OldaleTown/scripts.pory"
	.string "“Where things start off scarce.”$"

OldaleTown_EventScript_MeowthCarePackage::
# 396 "data/maps/OldaleTown/scripts.pory"
	faceplayer
# 397 "data/maps/OldaleTown/scripts.pory"
	lock
# 398 "data/maps/OldaleTown/scripts.pory"
	msgbox OldaleTown_EventScript_MeowthCarePackage_Text_0, MSGBOX_YESNO
# 399 "data/maps/OldaleTown/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq OldaleTown_EventScript_MeowthCarePackage_1
# 414 "data/maps/OldaleTown/scripts.pory"
	msgbox OldaleTown_EventScript_MeowthCarePackage_Text_1, MSGBOX_AUTOCLOSE
# 415 "data/maps/OldaleTown/scripts.pory"
	waitmessage
# 416 "data/maps/OldaleTown/scripts.pory"
	release
	end

OldaleTown_EventScript_MeowthCarePackage_1:
# 401 "data/maps/OldaleTown/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 402 "data/maps/OldaleTown/scripts.pory"
	giveitem ITEM_RARE_CANDY, 999
# 403 "data/maps/OldaleTown/scripts.pory"
	waitfanfare
# 404 "data/maps/OldaleTown/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 405 "data/maps/OldaleTown/scripts.pory"
	giveitem ITEM_QUICK_BALL, 500
# 406 "data/maps/OldaleTown/scripts.pory"
	waitfanfare
# 407 "data/maps/OldaleTown/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 408 "data/maps/OldaleTown/scripts.pory"
	giveitem ITEM_TIMER_BALL, 500
# 409 "data/maps/OldaleTown/scripts.pory"
	waitfanfare
# 410 "data/maps/OldaleTown/scripts.pory"
	release
	end


OldaleTown_EventScript_OldRodFisherman::
# 422 "data/maps/OldaleTown/scripts.pory"
	faceplayer
# 423 "data/maps/OldaleTown/scripts.pory"
	lock
# 424 "data/maps/OldaleTown/scripts.pory"
	goto_if_set FLAG_RECEIVED_OLD_ROD, OldaleTown_EventScript_OldRodFisherman_1
# 433 "data/maps/OldaleTown/scripts.pory"
	msgbox OldaleTown_EventScript_OldRodFisherman_Text_1, MSGBOX_YESNO
# 434 "data/maps/OldaleTown/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq OldaleTown_EventScript_OldRodFisherman_5
# 438 "data/maps/OldaleTown/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq OldaleTown_EventScript_OldRodFisherman_6
OldaleTown_EventScript_OldRodFisherman_4:
# 446 "data/maps/OldaleTown/scripts.pory"
	release
	end

OldaleTown_EventScript_OldRodFisherman_1:
# 426 "data/maps/OldaleTown/scripts.pory"
	msgbox OldaleTown_EventScript_OldRodFisherman_Text_0, MSGBOX_AUTOCLOSE
# 427 "data/maps/OldaleTown/scripts.pory"
	waitmessage
# 428 "data/maps/OldaleTown/scripts.pory"
	releaseall
	end

OldaleTown_EventScript_OldRodFisherman_5:
# 436 "data/maps/OldaleTown/scripts.pory"
	msgbox OldaleTown_EventScript_OldRodFisherman_Text_2, MSGBOX_AUTOCLOSE
	goto OldaleTown_EventScript_OldRodFisherman_4

OldaleTown_EventScript_OldRodFisherman_6:
# 439 "data/maps/OldaleTown/scripts.pory"
	msgbox OldaleTown_EventScript_OldRodFisherman_Text_3, MSGBOX_AUTOCLOSE
# 440 "data/maps/OldaleTown/scripts.pory"
	lock
# 441 "data/maps/OldaleTown/scripts.pory"
	setflag FLAG_RECEIVED_OLD_ROD
# 442 "data/maps/OldaleTown/scripts.pory"
	giveitem ITEM_OLD_ROD, 1
# 443 "data/maps/OldaleTown/scripts.pory"
	playfanfare MUS_RG_OBTAIN_KEY_ITEM
# 444 "data/maps/OldaleTown/scripts.pory"
	waitfanfare
	goto OldaleTown_EventScript_OldRodFisherman_4


OldaleTown_EventScript_MeowthCarePackage_Text_0:
# 398 "data/maps/OldaleTown/scripts.pory"
	.string "Looks like Meowth wants to give you\n"
	.string "items! Do you accept?$"

OldaleTown_EventScript_MeowthCarePackage_Text_1:
# 414 "data/maps/OldaleTown/scripts.pory"
	.string "Meowth smirks at you.$"

OldaleTown_EventScript_OldRodFisherman_Text_0:
# 426 "data/maps/OldaleTown/scripts.pory"
	.string "Howdy. How are the fish biting?$"

OldaleTown_EventScript_OldRodFisherman_Text_1:
# 433 "data/maps/OldaleTown/scripts.pory"
	.string "Howdy! Tell me- do you like fishing?$"

OldaleTown_EventScript_OldRodFisherman_Text_2:
# 436 "data/maps/OldaleTown/scripts.pory"
	.string "Alright. If you ever change your mind,\n"
	.string "come back and talk to me.$"

OldaleTown_EventScript_OldRodFisherman_Text_3:
# 439 "data/maps/OldaleTown/scripts.pory"
	.string "Well, I think I'll have an item you'll\n"
	.string "want to have!$"
