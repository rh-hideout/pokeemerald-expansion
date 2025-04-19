# 1 "data/maps/MossdeepCity/scripts.pory"

# 2 "data/maps/MossdeepCity/scripts.pory"
.set LOCALID_GRUNT_1, 10
# 3 "data/maps/MossdeepCity/scripts.pory"
.set LOCALID_GRUNT_2, 11
# 4 "data/maps/MossdeepCity/scripts.pory"
.set LOCALID_GRUNT_3, 12
# 5 "data/maps/MossdeepCity/scripts.pory"
.set LOCALID_GRUNT_4, 13
# 6 "data/maps/MossdeepCity/scripts.pory"
.set LOCALID_MAXIE, 14
# 7 "data/maps/MossdeepCity/scripts.pory"
.set LOCALID_SCOTT, 16
# 8 "data/maps/MossdeepCity/scripts.pory"

# 9 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_MapScripts::
# 10 "data/maps/MossdeepCity/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, MossdeepCity_OnTransition
# 11 "data/maps/MossdeepCity/scripts.pory"
	.byte 0
# 12 "data/maps/MossdeepCity/scripts.pory"

# 13 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_OnTransition:
# 14 "data/maps/MossdeepCity/scripts.pory"
	clearflag FLAG_MOSSDEEP_GYM_SWITCH_1
# 15 "data/maps/MossdeepCity/scripts.pory"
	clearflag FLAG_MOSSDEEP_GYM_SWITCH_2
# 16 "data/maps/MossdeepCity/scripts.pory"
	clearflag FLAG_MOSSDEEP_GYM_SWITCH_3
# 17 "data/maps/MossdeepCity/scripts.pory"
	clearflag FLAG_MOSSDEEP_GYM_SWITCH_4
# 18 "data/maps/MossdeepCity/scripts.pory"
	call_if_set FLAG_SYS_WEATHER_CTRL, Common_EventScript_SetAbnormalWeather
# 19 "data/maps/MossdeepCity/scripts.pory"
	end
# 20 "data/maps/MossdeepCity/scripts.pory"

# 21 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_EventScript_PokefanF::
# 22 "data/maps/MossdeepCity/scripts.pory"
	lock
# 23 "data/maps/MossdeepCity/scripts.pory"
	faceplayer
# 24 "data/maps/MossdeepCity/scripts.pory"
	goto_if_set FLAG_RECEIVED_HM_DIVE, MossdeepCity_EventScript_PokefanFMagmaGone
# 25 "data/maps/MossdeepCity/scripts.pory"
	msgbox MossdeepCity_Text_SpaceCenterReceivedLetter, MSGBOX_DEFAULT
# 26 "data/maps/MossdeepCity/scripts.pory"
	release
# 27 "data/maps/MossdeepCity/scripts.pory"
	end
# 28 "data/maps/MossdeepCity/scripts.pory"

# 29 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_EventScript_PokefanFMagmaGone::
# 30 "data/maps/MossdeepCity/scripts.pory"
	msgbox MossdeepCity_Text_SpaceCenterLaunchingRockets, MSGBOX_DEFAULT
# 31 "data/maps/MossdeepCity/scripts.pory"
	release
# 32 "data/maps/MossdeepCity/scripts.pory"
	end
# 33 "data/maps/MossdeepCity/scripts.pory"

# 34 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_EventScript_Sailor::
# 35 "data/maps/MossdeepCity/scripts.pory"
	lock
# 36 "data/maps/MossdeepCity/scripts.pory"
	faceplayer
# 37 "data/maps/MossdeepCity/scripts.pory"
	goto_if_set FLAG_RECEIVED_HM_DIVE, MossdeepCity_EventScript_SailorMagmaGone
# 38 "data/maps/MossdeepCity/scripts.pory"
	msgbox MossdeepCity_Text_MossdeepTargetedByMagma, MSGBOX_DEFAULT
# 39 "data/maps/MossdeepCity/scripts.pory"
	release
# 40 "data/maps/MossdeepCity/scripts.pory"
	end
# 41 "data/maps/MossdeepCity/scripts.pory"

# 42 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_EventScript_SailorMagmaGone::
# 43 "data/maps/MossdeepCity/scripts.pory"
	msgbox MossdeepCity_Text_FeelReliefOnLand, MSGBOX_DEFAULT
# 44 "data/maps/MossdeepCity/scripts.pory"
	release
# 45 "data/maps/MossdeepCity/scripts.pory"
	end
# 46 "data/maps/MossdeepCity/scripts.pory"

# 47 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_EventScript_NinjaBoy::
# 48 "data/maps/MossdeepCity/scripts.pory"
	msgbox MossdeepCity_Text_WailmerWatching, MSGBOX_NPC
# 49 "data/maps/MossdeepCity/scripts.pory"
	end
# 50 "data/maps/MossdeepCity/scripts.pory"

# 51 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_EventScript_ExpertM::
# 52 "data/maps/MossdeepCity/scripts.pory"
	msgbox MossdeepCity_Text_LifeNeedsSeaToLive, MSGBOX_NPC
# 53 "data/maps/MossdeepCity/scripts.pory"
	end
# 54 "data/maps/MossdeepCity/scripts.pory"

# 55 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_EventScript_Girl::
# 56 "data/maps/MossdeepCity/scripts.pory"
	msgbox MossdeepCity_Text_NiceIfWorldCoveredByFlowers, MSGBOX_NPC
# 57 "data/maps/MossdeepCity/scripts.pory"
	end
# 58 "data/maps/MossdeepCity/scripts.pory"

# 59 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_EventScript_Woman::
# 60 "data/maps/MossdeepCity/scripts.pory"
	msgbox MossdeepCity_Text_SpecialSpaceCenterRock, MSGBOX_NPC
# 61 "data/maps/MossdeepCity/scripts.pory"
	end
# 62 "data/maps/MossdeepCity/scripts.pory"

# 63 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_EventScript_WhiteRock::
# 64 "data/maps/MossdeepCity/scripts.pory"
	msgbox MossdeepCity_Text_ItsAWhiteRock, MSGBOX_SIGN
# 65 "data/maps/MossdeepCity/scripts.pory"
	end
# 66 "data/maps/MossdeepCity/scripts.pory"

# 67 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_EventScript_GymSign::
# 68 "data/maps/MossdeepCity/scripts.pory"
	msgbox MossdeepCity_Text_GymSign, MSGBOX_SIGN
# 69 "data/maps/MossdeepCity/scripts.pory"
	end
# 70 "data/maps/MossdeepCity/scripts.pory"

# 71 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_EventScript_CitySign::
# 72 "data/maps/MossdeepCity/scripts.pory"
	msgbox MossdeepCity_Text_CitySign, MSGBOX_SIGN
# 73 "data/maps/MossdeepCity/scripts.pory"
	end
# 74 "data/maps/MossdeepCity/scripts.pory"

# 75 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_EventScript_SpaceCenterSign::
# 76 "data/maps/MossdeepCity/scripts.pory"
	msgbox MossdeepCity_Text_SpaceCenterSign, MSGBOX_SIGN
# 77 "data/maps/MossdeepCity/scripts.pory"
	end
# 78 "data/maps/MossdeepCity/scripts.pory"

# 79 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_EventScript_VisitedMossdeep::
# 80 "data/maps/MossdeepCity/scripts.pory"
	setflag FLAG_VISITED_MOSSDEEP_CITY
# 81 "data/maps/MossdeepCity/scripts.pory"
	setvar VAR_TEMP_1, 1
# 82 "data/maps/MossdeepCity/scripts.pory"
	end
# 83 "data/maps/MossdeepCity/scripts.pory"

# 84 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_EventScript_TeamMagmaEnterSpaceCenter::
# 85 "data/maps/MossdeepCity/scripts.pory"
	lockall
# 86 "data/maps/MossdeepCity/scripts.pory"
	applymovement LOCALID_MAXIE, MossdeepCity_Movement_MaxieGestureToSpaceCenter
# 87 "data/maps/MossdeepCity/scripts.pory"
	waitmovement 0
# 88 "data/maps/MossdeepCity/scripts.pory"
	applymovement LOCALID_GRUNT_1, MossdeepCity_Movement_GruntFaceSpaceCenter
# 89 "data/maps/MossdeepCity/scripts.pory"
	applymovement LOCALID_GRUNT_2, MossdeepCity_Movement_GruntFaceSpaceCenter
# 90 "data/maps/MossdeepCity/scripts.pory"
	applymovement LOCALID_GRUNT_3, MossdeepCity_Movement_GruntFaceSpaceCenter
# 91 "data/maps/MossdeepCity/scripts.pory"
	applymovement LOCALID_GRUNT_4, MossdeepCity_Movement_GruntFaceSpaceCenter
# 92 "data/maps/MossdeepCity/scripts.pory"
	waitmovement 0
# 93 "data/maps/MossdeepCity/scripts.pory"
	applymovement LOCALID_MAXIE, MossdeepCity_Movement_MaxieEnterSpaceCenter
# 94 "data/maps/MossdeepCity/scripts.pory"
	applymovement LOCALID_GRUNT_1, MossdeepCity_Movement_Grunt1EnterSpaceCenter
# 95 "data/maps/MossdeepCity/scripts.pory"
	applymovement LOCALID_GRUNT_2, MossdeepCity_Movement_Grunt2EnterSpaceCenter
# 96 "data/maps/MossdeepCity/scripts.pory"
	applymovement LOCALID_GRUNT_3, MossdeepCity_Movement_Grunt3EnterSpaceCenter
# 97 "data/maps/MossdeepCity/scripts.pory"
	applymovement LOCALID_GRUNT_4, MossdeepCity_Movement_Grunt4EnterSpaceCenter
# 98 "data/maps/MossdeepCity/scripts.pory"
	waitmovement 0
# 99 "data/maps/MossdeepCity/scripts.pory"
	removeobject LOCALID_MAXIE
# 100 "data/maps/MossdeepCity/scripts.pory"
	removeobject LOCALID_GRUNT_1
# 101 "data/maps/MossdeepCity/scripts.pory"
	removeobject LOCALID_GRUNT_2
# 102 "data/maps/MossdeepCity/scripts.pory"
	removeobject LOCALID_GRUNT_3
# 103 "data/maps/MossdeepCity/scripts.pory"
	removeobject LOCALID_GRUNT_4
# 104 "data/maps/MossdeepCity/scripts.pory"
	delay 30
# 105 "data/maps/MossdeepCity/scripts.pory"
	setvar VAR_MOSSDEEP_CITY_STATE, 2
# 106 "data/maps/MossdeepCity/scripts.pory"
	setflag FLAG_HIDE_MOSSDEEP_CITY_TEAM_MAGMA
# 107 "data/maps/MossdeepCity/scripts.pory"
	releaseall
# 108 "data/maps/MossdeepCity/scripts.pory"
	end
# 109 "data/maps/MossdeepCity/scripts.pory"

# 110 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_Movement_MaxieGestureToSpaceCenter:
# 111 "data/maps/MossdeepCity/scripts.pory"
	delay_16
# 112 "data/maps/MossdeepCity/scripts.pory"
	face_right
# 113 "data/maps/MossdeepCity/scripts.pory"
	delay_16
# 114 "data/maps/MossdeepCity/scripts.pory"
	delay_16
# 115 "data/maps/MossdeepCity/scripts.pory"
	delay_16
# 116 "data/maps/MossdeepCity/scripts.pory"
	delay_16
# 117 "data/maps/MossdeepCity/scripts.pory"
	face_left
# 118 "data/maps/MossdeepCity/scripts.pory"
	delay_16
# 119 "data/maps/MossdeepCity/scripts.pory"
	delay_16
# 120 "data/maps/MossdeepCity/scripts.pory"
	step_end
# 121 "data/maps/MossdeepCity/scripts.pory"

# 122 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_Movement_GruntFaceSpaceCenter:
# 123 "data/maps/MossdeepCity/scripts.pory"
	face_right
# 124 "data/maps/MossdeepCity/scripts.pory"
	delay_16
# 125 "data/maps/MossdeepCity/scripts.pory"
	delay_16
# 126 "data/maps/MossdeepCity/scripts.pory"
	delay_16
# 127 "data/maps/MossdeepCity/scripts.pory"
	step_end
# 128 "data/maps/MossdeepCity/scripts.pory"

# 129 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_Movement_MaxieEnterSpaceCenter:
# 130 "data/maps/MossdeepCity/scripts.pory"
	walk_down
# 131 "data/maps/MossdeepCity/scripts.pory"
	walk_right
# 132 "data/maps/MossdeepCity/scripts.pory"
	walk_right
# 133 "data/maps/MossdeepCity/scripts.pory"
	walk_down
# 134 "data/maps/MossdeepCity/scripts.pory"
	walk_down
# 135 "data/maps/MossdeepCity/scripts.pory"
	walk_down
# 136 "data/maps/MossdeepCity/scripts.pory"
	walk_right
# 137 "data/maps/MossdeepCity/scripts.pory"
	walk_right
# 138 "data/maps/MossdeepCity/scripts.pory"
	walk_right
# 139 "data/maps/MossdeepCity/scripts.pory"
	walk_right
# 140 "data/maps/MossdeepCity/scripts.pory"
	walk_right
# 141 "data/maps/MossdeepCity/scripts.pory"
	walk_right
# 142 "data/maps/MossdeepCity/scripts.pory"
	walk_right
# 143 "data/maps/MossdeepCity/scripts.pory"
	step_end
# 144 "data/maps/MossdeepCity/scripts.pory"

# 145 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_Movement_Grunt1EnterSpaceCenter:
# 146 "data/maps/MossdeepCity/scripts.pory"
	delay_16
# 147 "data/maps/MossdeepCity/scripts.pory"
	delay_8
# 148 "data/maps/MossdeepCity/scripts.pory"
	walk_down
# 149 "data/maps/MossdeepCity/scripts.pory"
	walk_down
# 150 "data/maps/MossdeepCity/scripts.pory"
	walk_down
# 151 "data/maps/MossdeepCity/scripts.pory"
	walk_right
# 152 "data/maps/MossdeepCity/scripts.pory"
	walk_right
# 153 "data/maps/MossdeepCity/scripts.pory"
	walk_right
# 154 "data/maps/MossdeepCity/scripts.pory"
	walk_down
# 155 "data/maps/MossdeepCity/scripts.pory"
	walk_down
# 156 "data/maps/MossdeepCity/scripts.pory"
	walk_down
# 157 "data/maps/MossdeepCity/scripts.pory"
	walk_right
# 158 "data/maps/MossdeepCity/scripts.pory"
	walk_right
# 159 "data/maps/MossdeepCity/scripts.pory"
	walk_right
# 160 "data/maps/MossdeepCity/scripts.pory"
	walk_right
# 161 "data/maps/MossdeepCity/scripts.pory"
	walk_right
# 162 "data/maps/MossdeepCity/scripts.pory"
	walk_right
# 163 "data/maps/MossdeepCity/scripts.pory"
	walk_right
# 164 "data/maps/MossdeepCity/scripts.pory"
	step_end
# 165 "data/maps/MossdeepCity/scripts.pory"

# 166 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_Movement_Grunt2EnterSpaceCenter:
# 167 "data/maps/MossdeepCity/scripts.pory"
	delay_16
# 168 "data/maps/MossdeepCity/scripts.pory"
	delay_8
# 169 "data/maps/MossdeepCity/scripts.pory"
	walk_down
# 170 "data/maps/MossdeepCity/scripts.pory"
	walk_down
# 171 "data/maps/MossdeepCity/scripts.pory"
	walk_right
# 172 "data/maps/MossdeepCity/scripts.pory"
	walk_right
# 173 "data/maps/MossdeepCity/scripts.pory"
	walk_right
# 174 "data/maps/MossdeepCity/scripts.pory"
	walk_down
# 175 "data/maps/MossdeepCity/scripts.pory"
	walk_down
# 176 "data/maps/MossdeepCity/scripts.pory"
	walk_down
# 177 "data/maps/MossdeepCity/scripts.pory"
	walk_right
# 178 "data/maps/MossdeepCity/scripts.pory"
	walk_right
# 179 "data/maps/MossdeepCity/scripts.pory"
	walk_right
# 180 "data/maps/MossdeepCity/scripts.pory"
	walk_right
# 181 "data/maps/MossdeepCity/scripts.pory"
	walk_right
# 182 "data/maps/MossdeepCity/scripts.pory"
	walk_right
# 183 "data/maps/MossdeepCity/scripts.pory"
	walk_right
# 184 "data/maps/MossdeepCity/scripts.pory"
	step_end
# 185 "data/maps/MossdeepCity/scripts.pory"

# 186 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_Movement_Grunt3EnterSpaceCenter:
# 187 "data/maps/MossdeepCity/scripts.pory"
	delay_16
# 188 "data/maps/MossdeepCity/scripts.pory"
	delay_8
# 189 "data/maps/MossdeepCity/scripts.pory"
	walk_down
# 190 "data/maps/MossdeepCity/scripts.pory"
	walk_right
# 191 "data/maps/MossdeepCity/scripts.pory"
	walk_right
# 192 "data/maps/MossdeepCity/scripts.pory"
	walk_right
# 193 "data/maps/MossdeepCity/scripts.pory"
	walk_down
# 194 "data/maps/MossdeepCity/scripts.pory"
	walk_down
# 195 "data/maps/MossdeepCity/scripts.pory"
	walk_down
# 196 "data/maps/MossdeepCity/scripts.pory"
	walk_right
# 197 "data/maps/MossdeepCity/scripts.pory"
	walk_right
# 198 "data/maps/MossdeepCity/scripts.pory"
	walk_right
# 199 "data/maps/MossdeepCity/scripts.pory"
	walk_right
# 200 "data/maps/MossdeepCity/scripts.pory"
	walk_right
# 201 "data/maps/MossdeepCity/scripts.pory"
	walk_right
# 202 "data/maps/MossdeepCity/scripts.pory"
	walk_right
# 203 "data/maps/MossdeepCity/scripts.pory"
	step_end
# 204 "data/maps/MossdeepCity/scripts.pory"

# 205 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_Movement_Grunt4EnterSpaceCenter:
# 206 "data/maps/MossdeepCity/scripts.pory"
	delay_16
# 207 "data/maps/MossdeepCity/scripts.pory"
	delay_8
# 208 "data/maps/MossdeepCity/scripts.pory"
	walk_right
# 209 "data/maps/MossdeepCity/scripts.pory"
	walk_right
# 210 "data/maps/MossdeepCity/scripts.pory"
	walk_right
# 211 "data/maps/MossdeepCity/scripts.pory"
	walk_down
# 212 "data/maps/MossdeepCity/scripts.pory"
	walk_down
# 213 "data/maps/MossdeepCity/scripts.pory"
	walk_down
# 214 "data/maps/MossdeepCity/scripts.pory"
	walk_right
# 215 "data/maps/MossdeepCity/scripts.pory"
	walk_right
# 216 "data/maps/MossdeepCity/scripts.pory"
	walk_right
# 217 "data/maps/MossdeepCity/scripts.pory"
	walk_right
# 218 "data/maps/MossdeepCity/scripts.pory"
	walk_right
# 219 "data/maps/MossdeepCity/scripts.pory"
	walk_right
# 220 "data/maps/MossdeepCity/scripts.pory"
	walk_right
# 221 "data/maps/MossdeepCity/scripts.pory"
	step_end
# 222 "data/maps/MossdeepCity/scripts.pory"

# 223 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_EventScript_Man::
# 224 "data/maps/MossdeepCity/scripts.pory"
	lock
# 225 "data/maps/MossdeepCity/scripts.pory"
	faceplayer
# 226 "data/maps/MossdeepCity/scripts.pory"
	msgbox MossdeepCity_Text_SurfExhilarating, MSGBOX_DEFAULT
# 227 "data/maps/MossdeepCity/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
# 228 "data/maps/MossdeepCity/scripts.pory"
	waitmovement 0
# 229 "data/maps/MossdeepCity/scripts.pory"
	release
# 230 "data/maps/MossdeepCity/scripts.pory"
	end
# 231 "data/maps/MossdeepCity/scripts.pory"

# 232 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_EventScript_KingsRockBoy::
# 233 "data/maps/MossdeepCity/scripts.pory"
	lock
# 234 "data/maps/MossdeepCity/scripts.pory"
	faceplayer
# 235 "data/maps/MossdeepCity/scripts.pory"
	goto_if_set FLAG_RECEIVED_KINGS_ROCK, MossdeepCity_EventScript_ReceivedKingsRock
# 236 "data/maps/MossdeepCity/scripts.pory"
	msgbox MossdeepCity_Text_WantKingsRockStevenGaveMe, MSGBOX_YESNO
# 237 "data/maps/MossdeepCity/scripts.pory"
	goto_if_eq VAR_RESULT, NO, MossdeepCity_EventScript_DeclineKingsRock
# 238 "data/maps/MossdeepCity/scripts.pory"
	msgbox MossdeepCity_Text_YouCanKeepIt, MSGBOX_DEFAULT
# 239 "data/maps/MossdeepCity/scripts.pory"
	giveitem ITEM_KINGS_ROCK
# 240 "data/maps/MossdeepCity/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
# 241 "data/maps/MossdeepCity/scripts.pory"
	setflag FLAG_RECEIVED_KINGS_ROCK
# 242 "data/maps/MossdeepCity/scripts.pory"
	release
# 243 "data/maps/MossdeepCity/scripts.pory"
	end
# 244 "data/maps/MossdeepCity/scripts.pory"

# 245 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_EventScript_ReceivedKingsRock::
# 246 "data/maps/MossdeepCity/scripts.pory"
	msgbox MossdeepCity_Text_StevensHouseOverThere, MSGBOX_DEFAULT
# 247 "data/maps/MossdeepCity/scripts.pory"
	release
# 248 "data/maps/MossdeepCity/scripts.pory"
	end
# 249 "data/maps/MossdeepCity/scripts.pory"

# 250 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_EventScript_DeclineKingsRock::
# 251 "data/maps/MossdeepCity/scripts.pory"
	msgbox MossdeepCity_Text_WhatToDoWithWeirdRock, MSGBOX_DEFAULT
# 252 "data/maps/MossdeepCity/scripts.pory"
	release
# 253 "data/maps/MossdeepCity/scripts.pory"
	end
# 254 "data/maps/MossdeepCity/scripts.pory"

# 255 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_EventScript_BlackBelt::
# 256 "data/maps/MossdeepCity/scripts.pory"
	msgbox MossdeepCity_Text_SootopolisNewGymLeader, MSGBOX_NPC
# 257 "data/maps/MossdeepCity/scripts.pory"
	end
# 258 "data/maps/MossdeepCity/scripts.pory"

# 259 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_EventScript_Scott::
# 260 "data/maps/MossdeepCity/scripts.pory"
	lock
# 261 "data/maps/MossdeepCity/scripts.pory"
	faceplayer
# 262 "data/maps/MossdeepCity/scripts.pory"
	msgbox MossdeepCity_Text_ScottSomethingWrongWithTown, MSGBOX_DEFAULT
# 263 "data/maps/MossdeepCity/scripts.pory"
	closemessage
# 264 "data/maps/MossdeepCity/scripts.pory"
	call_if_eq VAR_FACING, DIR_NORTH, MossdeepCity_EventScript_ScottExitNorth
# 265 "data/maps/MossdeepCity/scripts.pory"
	call_if_eq VAR_FACING, DIR_EAST, MossdeepCity_EventScript_ScottExitEast
# 266 "data/maps/MossdeepCity/scripts.pory"
	addvar VAR_SCOTT_STATE, 1
# 267 "data/maps/MossdeepCity/scripts.pory"
	removeobject LOCALID_SCOTT
# 268 "data/maps/MossdeepCity/scripts.pory"
	release
# 269 "data/maps/MossdeepCity/scripts.pory"
	end
# 270 "data/maps/MossdeepCity/scripts.pory"

# 271 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_EventScript_ScottExitNorth::
# 272 "data/maps/MossdeepCity/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, MossdeepCity_Movement_PlayerWatchScottExit
# 273 "data/maps/MossdeepCity/scripts.pory"
	applymovement LOCALID_SCOTT, MossdeepCity_Movement_ScottExitNorth
# 274 "data/maps/MossdeepCity/scripts.pory"
	waitmovement 0
# 275 "data/maps/MossdeepCity/scripts.pory"
	return
# 276 "data/maps/MossdeepCity/scripts.pory"

# 277 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_EventScript_ScottExitEast::
# 278 "data/maps/MossdeepCity/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, MossdeepCity_Movement_PlayerWatchScottExit
# 279 "data/maps/MossdeepCity/scripts.pory"
	applymovement LOCALID_SCOTT, MossdeepCity_Movement_ScottExitEast
# 280 "data/maps/MossdeepCity/scripts.pory"
	waitmovement 0
# 281 "data/maps/MossdeepCity/scripts.pory"
	return
# 282 "data/maps/MossdeepCity/scripts.pory"

# 283 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_Movement_PlayerWatchScottExit:
# 284 "data/maps/MossdeepCity/scripts.pory"
	delay_16
# 285 "data/maps/MossdeepCity/scripts.pory"
	delay_16
# 286 "data/maps/MossdeepCity/scripts.pory"
	walk_in_place_faster_left
# 287 "data/maps/MossdeepCity/scripts.pory"
	step_end
# 288 "data/maps/MossdeepCity/scripts.pory"

# 289 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_Movement_ScottExitNorth:
# 290 "data/maps/MossdeepCity/scripts.pory"
	walk_left
# 291 "data/maps/MossdeepCity/scripts.pory"
	walk_left
# 292 "data/maps/MossdeepCity/scripts.pory"
	walk_left
# 293 "data/maps/MossdeepCity/scripts.pory"
	walk_left
# 294 "data/maps/MossdeepCity/scripts.pory"
	walk_left
# 295 "data/maps/MossdeepCity/scripts.pory"
	walk_left
# 296 "data/maps/MossdeepCity/scripts.pory"
	walk_left
# 297 "data/maps/MossdeepCity/scripts.pory"
	walk_left
# 298 "data/maps/MossdeepCity/scripts.pory"
	walk_left
# 299 "data/maps/MossdeepCity/scripts.pory"
	step_end
# 300 "data/maps/MossdeepCity/scripts.pory"

# 301 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_Movement_ScottExitEast:
# 302 "data/maps/MossdeepCity/scripts.pory"
	walk_down
# 303 "data/maps/MossdeepCity/scripts.pory"
	walk_left
# 304 "data/maps/MossdeepCity/scripts.pory"
	walk_left
# 305 "data/maps/MossdeepCity/scripts.pory"
	walk_left
# 306 "data/maps/MossdeepCity/scripts.pory"
	walk_left
# 307 "data/maps/MossdeepCity/scripts.pory"
	walk_left
# 308 "data/maps/MossdeepCity/scripts.pory"
	walk_left
# 309 "data/maps/MossdeepCity/scripts.pory"
	walk_left
# 310 "data/maps/MossdeepCity/scripts.pory"
	walk_left
# 311 "data/maps/MossdeepCity/scripts.pory"
	walk_left
# 312 "data/maps/MossdeepCity/scripts.pory"
	step_end
# 313 "data/maps/MossdeepCity/scripts.pory"

# 314 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_Text_WantKingsRockStevenGaveMe:
# 315 "data/maps/MossdeepCity/scripts.pory"
	.string "I got this from STEVEN, but I don't\n"
# 316 "data/maps/MossdeepCity/scripts.pory"
	.string "know what it's good for.\p"
# 317 "data/maps/MossdeepCity/scripts.pory"
	.string "I think it's called KING'S ROCK.\n"
# 318 "data/maps/MossdeepCity/scripts.pory"
	.string "Do you want it?$"
# 319 "data/maps/MossdeepCity/scripts.pory"

# 320 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_Text_YouCanKeepIt:
# 321 "data/maps/MossdeepCity/scripts.pory"
	.string "Why would you want it?\n"
# 322 "data/maps/MossdeepCity/scripts.pory"
	.string "You're weird.\p"
# 323 "data/maps/MossdeepCity/scripts.pory"
	.string "You can keep it, but keep it a secret\n"
# 324 "data/maps/MossdeepCity/scripts.pory"
	.string "from STEVEN.$"
# 325 "data/maps/MossdeepCity/scripts.pory"

# 326 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_Text_StevensHouseOverThere:
# 327 "data/maps/MossdeepCity/scripts.pory"
	.string "STEVEN's house is right over there!$"
# 328 "data/maps/MossdeepCity/scripts.pory"

# 329 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_Text_WhatToDoWithWeirdRock:
# 330 "data/maps/MossdeepCity/scripts.pory"
	.string "Yeah, you think so, too! What are you\n"
# 331 "data/maps/MossdeepCity/scripts.pory"
	.string "supposed to do with some weird rock?$"
# 332 "data/maps/MossdeepCity/scripts.pory"

# 333 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_Text_WailmerWatching:
# 334 "data/maps/MossdeepCity/scripts.pory"
	.string "Around MOSSDEEP, you can see wild\n"
# 335 "data/maps/MossdeepCity/scripts.pory"
	.string "WAILMER.\p"
# 336 "data/maps/MossdeepCity/scripts.pory"
	.string "It's called, uh…\n"
# 337 "data/maps/MossdeepCity/scripts.pory"
	.string "What was it now…\p"
# 338 "data/maps/MossdeepCity/scripts.pory"
	.string "WAI, WAI, WAI…\p"
# 339 "data/maps/MossdeepCity/scripts.pory"
	.string "WAILMER watching!$"
# 340 "data/maps/MossdeepCity/scripts.pory"

# 341 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_Text_SpaceCenterReceivedLetter:
# 342 "data/maps/MossdeepCity/scripts.pory"
	.string "The island's SPACE CENTER has been\n"
# 343 "data/maps/MossdeepCity/scripts.pory"
	.string "launching huge rockets.\p"
# 344 "data/maps/MossdeepCity/scripts.pory"
	.string "There's been some kind of an uproar\n"
# 345 "data/maps/MossdeepCity/scripts.pory"
	.string "over a letter they received recently.$"
# 346 "data/maps/MossdeepCity/scripts.pory"

# 347 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_Text_SpaceCenterLaunchingRockets:
# 348 "data/maps/MossdeepCity/scripts.pory"
	.string "The island's SPACE CENTER has been\n"
# 349 "data/maps/MossdeepCity/scripts.pory"
	.string "launching huge rockets.$"
# 350 "data/maps/MossdeepCity/scripts.pory"

# 351 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_Text_MossdeepTargetedByMagma:
# 352 "data/maps/MossdeepCity/scripts.pory"
	.string "I heard from a SAILOR buddy that\n"
# 353 "data/maps/MossdeepCity/scripts.pory"
	.string "TEAM AQUA set up shop in LILYCOVE.\p"
# 354 "data/maps/MossdeepCity/scripts.pory"
	.string "I also heard that someone came along\n"
# 355 "data/maps/MossdeepCity/scripts.pory"
	.string "and wiped the floor with them!\p"
# 356 "data/maps/MossdeepCity/scripts.pory"
	.string "But MOSSDEEP here's been targeted\n"
# 357 "data/maps/MossdeepCity/scripts.pory"
	.string "by that TEAM MAGMA.\p"
# 358 "data/maps/MossdeepCity/scripts.pory"
	.string "If you want to know what they're up to,\n"
# 359 "data/maps/MossdeepCity/scripts.pory"
	.string "go visit the SPACE CENTER.$"
# 360 "data/maps/MossdeepCity/scripts.pory"

# 361 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_Text_FeelReliefOnLand:
# 362 "data/maps/MossdeepCity/scripts.pory"
	.string "I'm a SAILOR, so the sea's obviously\n"
# 363 "data/maps/MossdeepCity/scripts.pory"
	.string "more important to me.\p"
# 364 "data/maps/MossdeepCity/scripts.pory"
	.string "But you know? When I get back on land\n"
# 365 "data/maps/MossdeepCity/scripts.pory"
	.string "after a long voyage, I do feel relief!$"
# 366 "data/maps/MossdeepCity/scripts.pory"

# 367 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_Text_NiceIfWorldCoveredByFlowers:
# 368 "data/maps/MossdeepCity/scripts.pory"
	.string "Wouldn't it be nice?\p"
# 369 "data/maps/MossdeepCity/scripts.pory"
	.string "If the whole world was covered in\n"
# 370 "data/maps/MossdeepCity/scripts.pory"
	.string "plants and flowers like this island?$"
# 371 "data/maps/MossdeepCity/scripts.pory"

# 372 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_Text_LifeNeedsSeaToLive:
# 373 "data/maps/MossdeepCity/scripts.pory"
	.string "All life needs the sea to live, even\n"
# 374 "data/maps/MossdeepCity/scripts.pory"
	.string "though it makes its home on the land.\p"
# 375 "data/maps/MossdeepCity/scripts.pory"
	.string "Life, having run its course, becomes\n"
# 376 "data/maps/MossdeepCity/scripts.pory"
	.string "soil and returns to the land.\p"
# 377 "data/maps/MossdeepCity/scripts.pory"
	.string "And the sea is always connected to\n"
# 378 "data/maps/MossdeepCity/scripts.pory"
	.string "the land.\p"
# 379 "data/maps/MossdeepCity/scripts.pory"
	.string "Yes, like the very shoreline here.$"
# 380 "data/maps/MossdeepCity/scripts.pory"

# 381 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_Text_SurfExhilarating:
# 382 "data/maps/MossdeepCity/scripts.pory"
	.string "A voyage on a ship is fine.\p"
# 383 "data/maps/MossdeepCity/scripts.pory"
	.string "But crossing the sea with POKéMON\n"
# 384 "data/maps/MossdeepCity/scripts.pory"
	.string "using SURF…\p"
# 385 "data/maps/MossdeepCity/scripts.pory"
	.string "Now that's an exhilarating trip!\n"
# 386 "data/maps/MossdeepCity/scripts.pory"
	.string "Wouldn't you agree, youngster?$"
# 387 "data/maps/MossdeepCity/scripts.pory"

# 388 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_Text_SpecialSpaceCenterRock:
# 389 "data/maps/MossdeepCity/scripts.pory"
	.string "This rock has a special meaning to\n"
# 390 "data/maps/MossdeepCity/scripts.pory"
	.string "the people at the SPACE CENTER.\p"
# 391 "data/maps/MossdeepCity/scripts.pory"
	.string "They put it here as their wish for\n"
# 392 "data/maps/MossdeepCity/scripts.pory"
	.string "their rockets to fly safely.\p"
# 393 "data/maps/MossdeepCity/scripts.pory"
	.string "When you make a wish, what do you use?\n"
# 394 "data/maps/MossdeepCity/scripts.pory"
	.string "Do you wish upon a star?\p"
# 395 "data/maps/MossdeepCity/scripts.pory"
	.string "I use a wish tag to make it happen.\n"
# 396 "data/maps/MossdeepCity/scripts.pory"
	.string "That's what I do.$"
# 397 "data/maps/MossdeepCity/scripts.pory"

# 398 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_Text_ItsAWhiteRock:
# 399 "data/maps/MossdeepCity/scripts.pory"
	.string "It's a white rock.$"
# 400 "data/maps/MossdeepCity/scripts.pory"

# 401 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_Text_GymSign:
# 402 "data/maps/MossdeepCity/scripts.pory"
	.string "MOSSDEEP CITY POKéMON GYM\n"
# 403 "data/maps/MossdeepCity/scripts.pory"
	.string "LEADERS: LIZA & TATE\p"
# 404 "data/maps/MossdeepCity/scripts.pory"
	.string "“The mystic combination!”$"
# 405 "data/maps/MossdeepCity/scripts.pory"

# 406 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_Text_CitySign:
# 407 "data/maps/MossdeepCity/scripts.pory"
	.string "MOSSDEEP CITY\n"
# 408 "data/maps/MossdeepCity/scripts.pory"
	.string "“Our slogan: Cherish POKéMON!”$"
# 409 "data/maps/MossdeepCity/scripts.pory"

# 410 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_Text_SpaceCenterSign:
# 411 "data/maps/MossdeepCity/scripts.pory"
	.string "MOSSDEEP SPACE CENTER\n"
# 412 "data/maps/MossdeepCity/scripts.pory"
	.string "“The closest place to space.”$"
# 413 "data/maps/MossdeepCity/scripts.pory"

# 414 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_Text_ScottSomethingWrongWithTown:
# 415 "data/maps/MossdeepCity/scripts.pory"
	.string "SCOTT: {PLAYER}{KUN}, feeling good?\n"
# 416 "data/maps/MossdeepCity/scripts.pory"
	.string "I'm doing great!\p"
# 417 "data/maps/MossdeepCity/scripts.pory"
	.string "I'd heard MOSSDEEP's GYM LEADER is\n"
# 418 "data/maps/MossdeepCity/scripts.pory"
	.string "pretty strong, so I decided to come\l"
# 419 "data/maps/MossdeepCity/scripts.pory"
	.string "take a look-see for myself.\p"
# 420 "data/maps/MossdeepCity/scripts.pory"
	.string "But there's something wrong about\n"
# 421 "data/maps/MossdeepCity/scripts.pory"
	.string "this town.\p"
# 422 "data/maps/MossdeepCity/scripts.pory"
	.string "People are going on about a warning\n"
# 423 "data/maps/MossdeepCity/scripts.pory"
	.string "letter and the SPACE CENTER…\p"
# 424 "data/maps/MossdeepCity/scripts.pory"
	.string "I don't think it concerns me in any\n"
# 425 "data/maps/MossdeepCity/scripts.pory"
	.string "way, though.$"
# 426 "data/maps/MossdeepCity/scripts.pory"

# 427 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_Text_SootopolisNewGymLeader:
# 428 "data/maps/MossdeepCity/scripts.pory"
	.string "Ahh… It feels great letting the waves\n"
# 429 "data/maps/MossdeepCity/scripts.pory"
	.string "wash over my feet…\p"
# 430 "data/maps/MossdeepCity/scripts.pory"
	.string "Speaking of the waves, you know that\n"
# 431 "data/maps/MossdeepCity/scripts.pory"
	.string "island city SOOTOPOLIS?\p"
# 432 "data/maps/MossdeepCity/scripts.pory"
	.string "I think the GYM there had a new\n"
# 433 "data/maps/MossdeepCity/scripts.pory"
	.string "LEADER come in.\p"
# 434 "data/maps/MossdeepCity/scripts.pory"
	.string "People tell me the new LEADER once\n"
# 435 "data/maps/MossdeepCity/scripts.pory"
	.string "mentored WALLACE.$"
