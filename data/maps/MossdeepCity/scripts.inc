# 2 "data/maps/MossdeepCity/scripts.pory"

# 3 "data/maps/MossdeepCity/scripts.pory"
.set LOCALID_GRUNT_1, 10
# 4 "data/maps/MossdeepCity/scripts.pory"
.set LOCALID_GRUNT_2, 11
# 5 "data/maps/MossdeepCity/scripts.pory"
.set LOCALID_GRUNT_3, 12
# 6 "data/maps/MossdeepCity/scripts.pory"
.set LOCALID_GRUNT_4, 13
# 7 "data/maps/MossdeepCity/scripts.pory"
.set LOCALID_MAXIE, 14
# 8 "data/maps/MossdeepCity/scripts.pory"
.set LOCALID_SCOTT, 16
# 9 "data/maps/MossdeepCity/scripts.pory"

# 10 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_MapScripts::
# 11 "data/maps/MossdeepCity/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, MossdeepCity_OnTransition
# 12 "data/maps/MossdeepCity/scripts.pory"
	.byte 0
# 13 "data/maps/MossdeepCity/scripts.pory"

# 14 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_OnTransition:
# 15 "data/maps/MossdeepCity/scripts.pory"
	clearflag FLAG_MOSSDEEP_GYM_SWITCH_1
# 16 "data/maps/MossdeepCity/scripts.pory"
	clearflag FLAG_MOSSDEEP_GYM_SWITCH_2
# 17 "data/maps/MossdeepCity/scripts.pory"
	clearflag FLAG_MOSSDEEP_GYM_SWITCH_3
# 18 "data/maps/MossdeepCity/scripts.pory"
	clearflag FLAG_MOSSDEEP_GYM_SWITCH_4
# 19 "data/maps/MossdeepCity/scripts.pory"
	call_if_set FLAG_SYS_WEATHER_CTRL, Common_EventScript_SetAbnormalWeather
# 20 "data/maps/MossdeepCity/scripts.pory"
	end
# 21 "data/maps/MossdeepCity/scripts.pory"

# 22 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_EventScript_PokefanF::
# 23 "data/maps/MossdeepCity/scripts.pory"
	lock
# 24 "data/maps/MossdeepCity/scripts.pory"
	faceplayer
# 25 "data/maps/MossdeepCity/scripts.pory"
	goto_if_set FLAG_RECEIVED_HM_DIVE, MossdeepCity_EventScript_PokefanFMagmaGone
# 26 "data/maps/MossdeepCity/scripts.pory"
	msgbox MossdeepCity_Text_SpaceCenterReceivedLetter, MSGBOX_DEFAULT
# 27 "data/maps/MossdeepCity/scripts.pory"
	release
# 28 "data/maps/MossdeepCity/scripts.pory"
	end
# 29 "data/maps/MossdeepCity/scripts.pory"

# 30 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_EventScript_PokefanFMagmaGone::
# 31 "data/maps/MossdeepCity/scripts.pory"
	msgbox MossdeepCity_Text_SpaceCenterLaunchingRockets, MSGBOX_DEFAULT
# 32 "data/maps/MossdeepCity/scripts.pory"
	release
# 33 "data/maps/MossdeepCity/scripts.pory"
	end
# 34 "data/maps/MossdeepCity/scripts.pory"

# 35 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_EventScript_Sailor::
# 36 "data/maps/MossdeepCity/scripts.pory"
	lock
# 37 "data/maps/MossdeepCity/scripts.pory"
	faceplayer
# 38 "data/maps/MossdeepCity/scripts.pory"
	goto_if_set FLAG_RECEIVED_HM_DIVE, MossdeepCity_EventScript_SailorMagmaGone
# 39 "data/maps/MossdeepCity/scripts.pory"
	msgbox MossdeepCity_Text_MossdeepTargetedByMagma, MSGBOX_DEFAULT
# 40 "data/maps/MossdeepCity/scripts.pory"
	release
# 41 "data/maps/MossdeepCity/scripts.pory"
	end
# 42 "data/maps/MossdeepCity/scripts.pory"

# 43 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_EventScript_SailorMagmaGone::
# 44 "data/maps/MossdeepCity/scripts.pory"
	msgbox MossdeepCity_Text_FeelReliefOnLand, MSGBOX_DEFAULT
# 45 "data/maps/MossdeepCity/scripts.pory"
	release
# 46 "data/maps/MossdeepCity/scripts.pory"
	end
# 47 "data/maps/MossdeepCity/scripts.pory"

# 48 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_EventScript_NinjaBoy::
# 49 "data/maps/MossdeepCity/scripts.pory"
	msgbox MossdeepCity_Text_WailmerWatching, MSGBOX_NPC
# 50 "data/maps/MossdeepCity/scripts.pory"
	end
# 51 "data/maps/MossdeepCity/scripts.pory"

# 52 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_EventScript_ExpertM::
# 53 "data/maps/MossdeepCity/scripts.pory"
	msgbox MossdeepCity_Text_LifeNeedsSeaToLive, MSGBOX_NPC
# 54 "data/maps/MossdeepCity/scripts.pory"
	end
# 55 "data/maps/MossdeepCity/scripts.pory"

# 56 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_EventScript_Girl::
# 57 "data/maps/MossdeepCity/scripts.pory"
	msgbox MossdeepCity_Text_NiceIfWorldCoveredByFlowers, MSGBOX_NPC
# 58 "data/maps/MossdeepCity/scripts.pory"
	end
# 59 "data/maps/MossdeepCity/scripts.pory"

# 60 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_EventScript_Woman::
# 61 "data/maps/MossdeepCity/scripts.pory"
	msgbox MossdeepCity_Text_SpecialSpaceCenterRock, MSGBOX_NPC
# 62 "data/maps/MossdeepCity/scripts.pory"
	end
# 63 "data/maps/MossdeepCity/scripts.pory"

# 64 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_EventScript_WhiteRock::
# 65 "data/maps/MossdeepCity/scripts.pory"
	msgbox MossdeepCity_Text_ItsAWhiteRock, MSGBOX_SIGN
# 66 "data/maps/MossdeepCity/scripts.pory"
	end
# 67 "data/maps/MossdeepCity/scripts.pory"

# 68 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_EventScript_GymSign::
# 69 "data/maps/MossdeepCity/scripts.pory"
	msgbox MossdeepCity_Text_GymSign, MSGBOX_SIGN
# 70 "data/maps/MossdeepCity/scripts.pory"
	end
# 71 "data/maps/MossdeepCity/scripts.pory"

# 72 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_EventScript_CitySign::
# 73 "data/maps/MossdeepCity/scripts.pory"
	msgbox MossdeepCity_Text_CitySign, MSGBOX_SIGN
# 74 "data/maps/MossdeepCity/scripts.pory"
	end
# 75 "data/maps/MossdeepCity/scripts.pory"

# 76 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_EventScript_SpaceCenterSign::
# 77 "data/maps/MossdeepCity/scripts.pory"
	msgbox MossdeepCity_Text_SpaceCenterSign, MSGBOX_SIGN
# 78 "data/maps/MossdeepCity/scripts.pory"
	end
# 79 "data/maps/MossdeepCity/scripts.pory"

# 80 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_EventScript_VisitedMossdeep::
# 81 "data/maps/MossdeepCity/scripts.pory"
	setflag FLAG_VISITED_MOSSDEEP_CITY
# 82 "data/maps/MossdeepCity/scripts.pory"
	setvar VAR_TEMP_1, 1
# 83 "data/maps/MossdeepCity/scripts.pory"
	end
# 84 "data/maps/MossdeepCity/scripts.pory"

# 85 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_EventScript_TeamMagmaEnterSpaceCenter::
# 86 "data/maps/MossdeepCity/scripts.pory"
	lockall
# 87 "data/maps/MossdeepCity/scripts.pory"
	applymovement LOCALID_MAXIE, MossdeepCity_Movement_MaxieGestureToSpaceCenter
# 88 "data/maps/MossdeepCity/scripts.pory"
	waitmovement 0
# 89 "data/maps/MossdeepCity/scripts.pory"
	applymovement LOCALID_GRUNT_1, MossdeepCity_Movement_GruntFaceSpaceCenter
# 90 "data/maps/MossdeepCity/scripts.pory"
	applymovement LOCALID_GRUNT_2, MossdeepCity_Movement_GruntFaceSpaceCenter
# 91 "data/maps/MossdeepCity/scripts.pory"
	applymovement LOCALID_GRUNT_3, MossdeepCity_Movement_GruntFaceSpaceCenter
# 92 "data/maps/MossdeepCity/scripts.pory"
	applymovement LOCALID_GRUNT_4, MossdeepCity_Movement_GruntFaceSpaceCenter
# 93 "data/maps/MossdeepCity/scripts.pory"
	waitmovement 0
# 94 "data/maps/MossdeepCity/scripts.pory"
	applymovement LOCALID_MAXIE, MossdeepCity_Movement_MaxieEnterSpaceCenter
# 95 "data/maps/MossdeepCity/scripts.pory"
	applymovement LOCALID_GRUNT_1, MossdeepCity_Movement_Grunt1EnterSpaceCenter
# 96 "data/maps/MossdeepCity/scripts.pory"
	applymovement LOCALID_GRUNT_2, MossdeepCity_Movement_Grunt2EnterSpaceCenter
# 97 "data/maps/MossdeepCity/scripts.pory"
	applymovement LOCALID_GRUNT_3, MossdeepCity_Movement_Grunt3EnterSpaceCenter
# 98 "data/maps/MossdeepCity/scripts.pory"
	applymovement LOCALID_GRUNT_4, MossdeepCity_Movement_Grunt4EnterSpaceCenter
# 99 "data/maps/MossdeepCity/scripts.pory"
	waitmovement 0
# 100 "data/maps/MossdeepCity/scripts.pory"
	removeobject LOCALID_MAXIE
# 101 "data/maps/MossdeepCity/scripts.pory"
	removeobject LOCALID_GRUNT_1
# 102 "data/maps/MossdeepCity/scripts.pory"
	removeobject LOCALID_GRUNT_2
# 103 "data/maps/MossdeepCity/scripts.pory"
	removeobject LOCALID_GRUNT_3
# 104 "data/maps/MossdeepCity/scripts.pory"
	removeobject LOCALID_GRUNT_4
# 105 "data/maps/MossdeepCity/scripts.pory"
	delay 30
# 106 "data/maps/MossdeepCity/scripts.pory"
	setvar VAR_MOSSDEEP_CITY_STATE, 2
# 107 "data/maps/MossdeepCity/scripts.pory"
	setflag FLAG_HIDE_MOSSDEEP_CITY_TEAM_MAGMA
# 108 "data/maps/MossdeepCity/scripts.pory"
	releaseall
# 109 "data/maps/MossdeepCity/scripts.pory"
	end
# 110 "data/maps/MossdeepCity/scripts.pory"

# 111 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_Movement_MaxieGestureToSpaceCenter:
# 112 "data/maps/MossdeepCity/scripts.pory"
	delay_16
# 113 "data/maps/MossdeepCity/scripts.pory"
	face_right
# 114 "data/maps/MossdeepCity/scripts.pory"
	delay_16
# 115 "data/maps/MossdeepCity/scripts.pory"
	delay_16
# 116 "data/maps/MossdeepCity/scripts.pory"
	delay_16
# 117 "data/maps/MossdeepCity/scripts.pory"
	delay_16
# 118 "data/maps/MossdeepCity/scripts.pory"
	face_left
# 119 "data/maps/MossdeepCity/scripts.pory"
	delay_16
# 120 "data/maps/MossdeepCity/scripts.pory"
	delay_16
# 121 "data/maps/MossdeepCity/scripts.pory"
	step_end
# 122 "data/maps/MossdeepCity/scripts.pory"

# 123 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_Movement_GruntFaceSpaceCenter:
# 124 "data/maps/MossdeepCity/scripts.pory"
	face_right
# 125 "data/maps/MossdeepCity/scripts.pory"
	delay_16
# 126 "data/maps/MossdeepCity/scripts.pory"
	delay_16
# 127 "data/maps/MossdeepCity/scripts.pory"
	delay_16
# 128 "data/maps/MossdeepCity/scripts.pory"
	step_end
# 129 "data/maps/MossdeepCity/scripts.pory"

# 130 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_Movement_MaxieEnterSpaceCenter:
# 131 "data/maps/MossdeepCity/scripts.pory"
	walk_down
# 132 "data/maps/MossdeepCity/scripts.pory"
	walk_right
# 133 "data/maps/MossdeepCity/scripts.pory"
	walk_right
# 134 "data/maps/MossdeepCity/scripts.pory"
	walk_down
# 135 "data/maps/MossdeepCity/scripts.pory"
	walk_down
# 136 "data/maps/MossdeepCity/scripts.pory"
	walk_down
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
	walk_right
# 144 "data/maps/MossdeepCity/scripts.pory"
	step_end
# 145 "data/maps/MossdeepCity/scripts.pory"

# 146 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_Movement_Grunt1EnterSpaceCenter:
# 147 "data/maps/MossdeepCity/scripts.pory"
	delay_16
# 148 "data/maps/MossdeepCity/scripts.pory"
	delay_8
# 149 "data/maps/MossdeepCity/scripts.pory"
	walk_down
# 150 "data/maps/MossdeepCity/scripts.pory"
	walk_down
# 151 "data/maps/MossdeepCity/scripts.pory"
	walk_down
# 152 "data/maps/MossdeepCity/scripts.pory"
	walk_right
# 153 "data/maps/MossdeepCity/scripts.pory"
	walk_right
# 154 "data/maps/MossdeepCity/scripts.pory"
	walk_right
# 155 "data/maps/MossdeepCity/scripts.pory"
	walk_down
# 156 "data/maps/MossdeepCity/scripts.pory"
	walk_down
# 157 "data/maps/MossdeepCity/scripts.pory"
	walk_down
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
	walk_right
# 165 "data/maps/MossdeepCity/scripts.pory"
	step_end
# 166 "data/maps/MossdeepCity/scripts.pory"

# 167 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_Movement_Grunt2EnterSpaceCenter:
# 168 "data/maps/MossdeepCity/scripts.pory"
	delay_16
# 169 "data/maps/MossdeepCity/scripts.pory"
	delay_8
# 170 "data/maps/MossdeepCity/scripts.pory"
	walk_down
# 171 "data/maps/MossdeepCity/scripts.pory"
	walk_down
# 172 "data/maps/MossdeepCity/scripts.pory"
	walk_right
# 173 "data/maps/MossdeepCity/scripts.pory"
	walk_right
# 174 "data/maps/MossdeepCity/scripts.pory"
	walk_right
# 175 "data/maps/MossdeepCity/scripts.pory"
	walk_down
# 176 "data/maps/MossdeepCity/scripts.pory"
	walk_down
# 177 "data/maps/MossdeepCity/scripts.pory"
	walk_down
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
	walk_right
# 185 "data/maps/MossdeepCity/scripts.pory"
	step_end
# 186 "data/maps/MossdeepCity/scripts.pory"

# 187 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_Movement_Grunt3EnterSpaceCenter:
# 188 "data/maps/MossdeepCity/scripts.pory"
	delay_16
# 189 "data/maps/MossdeepCity/scripts.pory"
	delay_8
# 190 "data/maps/MossdeepCity/scripts.pory"
	walk_down
# 191 "data/maps/MossdeepCity/scripts.pory"
	walk_right
# 192 "data/maps/MossdeepCity/scripts.pory"
	walk_right
# 193 "data/maps/MossdeepCity/scripts.pory"
	walk_right
# 194 "data/maps/MossdeepCity/scripts.pory"
	walk_down
# 195 "data/maps/MossdeepCity/scripts.pory"
	walk_down
# 196 "data/maps/MossdeepCity/scripts.pory"
	walk_down
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
	walk_right
# 204 "data/maps/MossdeepCity/scripts.pory"
	step_end
# 205 "data/maps/MossdeepCity/scripts.pory"

# 206 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_Movement_Grunt4EnterSpaceCenter:
# 207 "data/maps/MossdeepCity/scripts.pory"
	delay_16
# 208 "data/maps/MossdeepCity/scripts.pory"
	delay_8
# 209 "data/maps/MossdeepCity/scripts.pory"
	walk_right
# 210 "data/maps/MossdeepCity/scripts.pory"
	walk_right
# 211 "data/maps/MossdeepCity/scripts.pory"
	walk_right
# 212 "data/maps/MossdeepCity/scripts.pory"
	walk_down
# 213 "data/maps/MossdeepCity/scripts.pory"
	walk_down
# 214 "data/maps/MossdeepCity/scripts.pory"
	walk_down
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
	walk_right
# 222 "data/maps/MossdeepCity/scripts.pory"
	step_end
# 223 "data/maps/MossdeepCity/scripts.pory"

# 224 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_EventScript_Man::
# 225 "data/maps/MossdeepCity/scripts.pory"
	lock
# 226 "data/maps/MossdeepCity/scripts.pory"
	faceplayer
# 227 "data/maps/MossdeepCity/scripts.pory"
	msgbox MossdeepCity_Text_SurfExhilarating, MSGBOX_DEFAULT
# 228 "data/maps/MossdeepCity/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
# 229 "data/maps/MossdeepCity/scripts.pory"
	waitmovement 0
# 230 "data/maps/MossdeepCity/scripts.pory"
	release
# 231 "data/maps/MossdeepCity/scripts.pory"
	end
# 232 "data/maps/MossdeepCity/scripts.pory"

# 233 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_EventScript_KingsRockBoy::
# 234 "data/maps/MossdeepCity/scripts.pory"
	lock
# 235 "data/maps/MossdeepCity/scripts.pory"
	faceplayer
# 236 "data/maps/MossdeepCity/scripts.pory"
	goto_if_set FLAG_RECEIVED_KINGS_ROCK, MossdeepCity_EventScript_ReceivedKingsRock
# 237 "data/maps/MossdeepCity/scripts.pory"
	msgbox MossdeepCity_Text_WantKingsRockStevenGaveMe, MSGBOX_YESNO
# 238 "data/maps/MossdeepCity/scripts.pory"
	goto_if_eq VAR_RESULT, NO, MossdeepCity_EventScript_DeclineKingsRock
# 239 "data/maps/MossdeepCity/scripts.pory"
	msgbox MossdeepCity_Text_YouCanKeepIt, MSGBOX_DEFAULT
# 240 "data/maps/MossdeepCity/scripts.pory"
	giveitem ITEM_KINGS_ROCK
# 241 "data/maps/MossdeepCity/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
# 242 "data/maps/MossdeepCity/scripts.pory"
	setflag FLAG_RECEIVED_KINGS_ROCK
# 243 "data/maps/MossdeepCity/scripts.pory"
	release
# 244 "data/maps/MossdeepCity/scripts.pory"
	end
# 245 "data/maps/MossdeepCity/scripts.pory"

# 246 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_EventScript_ReceivedKingsRock::
# 247 "data/maps/MossdeepCity/scripts.pory"
	msgbox MossdeepCity_Text_StevensHouseOverThere, MSGBOX_DEFAULT
# 248 "data/maps/MossdeepCity/scripts.pory"
	release
# 249 "data/maps/MossdeepCity/scripts.pory"
	end
# 250 "data/maps/MossdeepCity/scripts.pory"

# 251 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_EventScript_DeclineKingsRock::
# 252 "data/maps/MossdeepCity/scripts.pory"
	msgbox MossdeepCity_Text_WhatToDoWithWeirdRock, MSGBOX_DEFAULT
# 253 "data/maps/MossdeepCity/scripts.pory"
	release
# 254 "data/maps/MossdeepCity/scripts.pory"
	end
# 255 "data/maps/MossdeepCity/scripts.pory"

# 256 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_EventScript_BlackBelt::
# 257 "data/maps/MossdeepCity/scripts.pory"
	msgbox MossdeepCity_Text_SootopolisNewGymLeader, MSGBOX_NPC
# 258 "data/maps/MossdeepCity/scripts.pory"
	end
# 259 "data/maps/MossdeepCity/scripts.pory"

# 260 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_EventScript_Scott::
# 261 "data/maps/MossdeepCity/scripts.pory"
	lock
# 262 "data/maps/MossdeepCity/scripts.pory"
	faceplayer
# 263 "data/maps/MossdeepCity/scripts.pory"
	msgbox MossdeepCity_Text_ScottSomethingWrongWithTown, MSGBOX_DEFAULT
# 264 "data/maps/MossdeepCity/scripts.pory"
	closemessage
# 265 "data/maps/MossdeepCity/scripts.pory"
	call_if_eq VAR_FACING, DIR_NORTH, MossdeepCity_EventScript_ScottExitNorth
# 266 "data/maps/MossdeepCity/scripts.pory"
	call_if_eq VAR_FACING, DIR_EAST, MossdeepCity_EventScript_ScottExitEast
# 267 "data/maps/MossdeepCity/scripts.pory"
	addvar VAR_SCOTT_STATE, 1
# 268 "data/maps/MossdeepCity/scripts.pory"
	removeobject LOCALID_SCOTT
# 269 "data/maps/MossdeepCity/scripts.pory"
	release
# 270 "data/maps/MossdeepCity/scripts.pory"
	end
# 271 "data/maps/MossdeepCity/scripts.pory"

# 272 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_EventScript_ScottExitNorth::
# 273 "data/maps/MossdeepCity/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, MossdeepCity_Movement_PlayerWatchScottExit
# 274 "data/maps/MossdeepCity/scripts.pory"
	applymovement LOCALID_SCOTT, MossdeepCity_Movement_ScottExitNorth
# 275 "data/maps/MossdeepCity/scripts.pory"
	waitmovement 0
# 276 "data/maps/MossdeepCity/scripts.pory"
	return
# 277 "data/maps/MossdeepCity/scripts.pory"

# 278 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_EventScript_ScottExitEast::
# 279 "data/maps/MossdeepCity/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, MossdeepCity_Movement_PlayerWatchScottExit
# 280 "data/maps/MossdeepCity/scripts.pory"
	applymovement LOCALID_SCOTT, MossdeepCity_Movement_ScottExitEast
# 281 "data/maps/MossdeepCity/scripts.pory"
	waitmovement 0
# 282 "data/maps/MossdeepCity/scripts.pory"
	return
# 283 "data/maps/MossdeepCity/scripts.pory"

# 284 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_Movement_PlayerWatchScottExit:
# 285 "data/maps/MossdeepCity/scripts.pory"
	delay_16
# 286 "data/maps/MossdeepCity/scripts.pory"
	delay_16
# 287 "data/maps/MossdeepCity/scripts.pory"
	walk_in_place_faster_left
# 288 "data/maps/MossdeepCity/scripts.pory"
	step_end
# 289 "data/maps/MossdeepCity/scripts.pory"

# 290 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_Movement_ScottExitNorth:
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
	walk_left
# 300 "data/maps/MossdeepCity/scripts.pory"
	step_end
# 301 "data/maps/MossdeepCity/scripts.pory"

# 302 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_Movement_ScottExitEast:
# 303 "data/maps/MossdeepCity/scripts.pory"
	walk_down
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
	walk_left
# 313 "data/maps/MossdeepCity/scripts.pory"
	step_end
# 314 "data/maps/MossdeepCity/scripts.pory"

# 315 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_Text_WantKingsRockStevenGaveMe:
# 316 "data/maps/MossdeepCity/scripts.pory"
	.string "I got this from STEVEN, but I don't\n"
# 317 "data/maps/MossdeepCity/scripts.pory"
	.string "know what it's good for.\p"
# 318 "data/maps/MossdeepCity/scripts.pory"
	.string "I think it's called KING'S ROCK.\n"
# 319 "data/maps/MossdeepCity/scripts.pory"
	.string "Do you want it?$"
# 320 "data/maps/MossdeepCity/scripts.pory"

# 321 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_Text_YouCanKeepIt:
# 322 "data/maps/MossdeepCity/scripts.pory"
	.string "Why would you want it?\n"
# 323 "data/maps/MossdeepCity/scripts.pory"
	.string "You're weird.\p"
# 324 "data/maps/MossdeepCity/scripts.pory"
	.string "You can keep it, but keep it a secret\n"
# 325 "data/maps/MossdeepCity/scripts.pory"
	.string "from STEVEN.$"
# 326 "data/maps/MossdeepCity/scripts.pory"

# 327 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_Text_StevensHouseOverThere:
# 328 "data/maps/MossdeepCity/scripts.pory"
	.string "STEVEN's house is right over there!$"
# 329 "data/maps/MossdeepCity/scripts.pory"

# 330 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_Text_WhatToDoWithWeirdRock:
# 331 "data/maps/MossdeepCity/scripts.pory"
	.string "Yeah, you think so, too! What are you\n"
# 332 "data/maps/MossdeepCity/scripts.pory"
	.string "supposed to do with some weird rock?$"
# 333 "data/maps/MossdeepCity/scripts.pory"

# 334 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_Text_WailmerWatching:
# 335 "data/maps/MossdeepCity/scripts.pory"
	.string "Around MOSSDEEP, you can see wild\n"
# 336 "data/maps/MossdeepCity/scripts.pory"
	.string "WAILMER.\p"
# 337 "data/maps/MossdeepCity/scripts.pory"
	.string "It's called, uh…\n"
# 338 "data/maps/MossdeepCity/scripts.pory"
	.string "What was it now…\p"
# 339 "data/maps/MossdeepCity/scripts.pory"
	.string "WAI, WAI, WAI…\p"
# 340 "data/maps/MossdeepCity/scripts.pory"
	.string "WAILMER watching!$"
# 341 "data/maps/MossdeepCity/scripts.pory"

# 342 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_Text_SpaceCenterReceivedLetter:
# 343 "data/maps/MossdeepCity/scripts.pory"
	.string "The island's SPACE CENTER has been\n"
# 344 "data/maps/MossdeepCity/scripts.pory"
	.string "launching huge rockets.\p"
# 345 "data/maps/MossdeepCity/scripts.pory"
	.string "There's been some kind of an uproar\n"
# 346 "data/maps/MossdeepCity/scripts.pory"
	.string "over a letter they received recently.$"
# 347 "data/maps/MossdeepCity/scripts.pory"

# 348 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_Text_SpaceCenterLaunchingRockets:
# 349 "data/maps/MossdeepCity/scripts.pory"
	.string "The island's SPACE CENTER has been\n"
# 350 "data/maps/MossdeepCity/scripts.pory"
	.string "launching huge rockets.$"
# 351 "data/maps/MossdeepCity/scripts.pory"

# 352 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_Text_MossdeepTargetedByMagma:
# 353 "data/maps/MossdeepCity/scripts.pory"
	.string "I heard from a SAILOR buddy that\n"
# 354 "data/maps/MossdeepCity/scripts.pory"
	.string "TEAM AQUA set up shop in LILYCOVE.\p"
# 355 "data/maps/MossdeepCity/scripts.pory"
	.string "I also heard that someone came along\n"
# 356 "data/maps/MossdeepCity/scripts.pory"
	.string "and wiped the floor with them!\p"
# 357 "data/maps/MossdeepCity/scripts.pory"
	.string "But MOSSDEEP here's been targeted\n"
# 358 "data/maps/MossdeepCity/scripts.pory"
	.string "by that TEAM MAGMA.\p"
# 359 "data/maps/MossdeepCity/scripts.pory"
	.string "If you want to know what they're up to,\n"
# 360 "data/maps/MossdeepCity/scripts.pory"
	.string "go visit the SPACE CENTER.$"
# 361 "data/maps/MossdeepCity/scripts.pory"

# 362 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_Text_FeelReliefOnLand:
# 363 "data/maps/MossdeepCity/scripts.pory"
	.string "I'm a SAILOR, so the sea's obviously\n"
# 364 "data/maps/MossdeepCity/scripts.pory"
	.string "more important to me.\p"
# 365 "data/maps/MossdeepCity/scripts.pory"
	.string "But you know? When I get back on land\n"
# 366 "data/maps/MossdeepCity/scripts.pory"
	.string "after a long voyage, I do feel relief!$"
# 367 "data/maps/MossdeepCity/scripts.pory"

# 368 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_Text_NiceIfWorldCoveredByFlowers:
# 369 "data/maps/MossdeepCity/scripts.pory"
	.string "Wouldn't it be nice?\p"
# 370 "data/maps/MossdeepCity/scripts.pory"
	.string "If the whole world was covered in\n"
# 371 "data/maps/MossdeepCity/scripts.pory"
	.string "plants and flowers like this island?$"
# 372 "data/maps/MossdeepCity/scripts.pory"

# 373 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_Text_LifeNeedsSeaToLive:
# 374 "data/maps/MossdeepCity/scripts.pory"
	.string "All life needs the sea to live, even\n"
# 375 "data/maps/MossdeepCity/scripts.pory"
	.string "though it makes its home on the land.\p"
# 376 "data/maps/MossdeepCity/scripts.pory"
	.string "Life, having run its course, becomes\n"
# 377 "data/maps/MossdeepCity/scripts.pory"
	.string "soil and returns to the land.\p"
# 378 "data/maps/MossdeepCity/scripts.pory"
	.string "And the sea is always connected to\n"
# 379 "data/maps/MossdeepCity/scripts.pory"
	.string "the land.\p"
# 380 "data/maps/MossdeepCity/scripts.pory"
	.string "Yes, like the very shoreline here.$"
# 381 "data/maps/MossdeepCity/scripts.pory"

# 382 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_Text_SurfExhilarating:
# 383 "data/maps/MossdeepCity/scripts.pory"
	.string "A voyage on a ship is fine.\p"
# 384 "data/maps/MossdeepCity/scripts.pory"
	.string "But crossing the sea with POKéMON\n"
# 385 "data/maps/MossdeepCity/scripts.pory"
	.string "using SURF…\p"
# 386 "data/maps/MossdeepCity/scripts.pory"
	.string "Now that's an exhilarating trip!\n"
# 387 "data/maps/MossdeepCity/scripts.pory"
	.string "Wouldn't you agree, youngster?$"
# 388 "data/maps/MossdeepCity/scripts.pory"

# 389 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_Text_SpecialSpaceCenterRock:
# 390 "data/maps/MossdeepCity/scripts.pory"
	.string "This rock has a special meaning to\n"
# 391 "data/maps/MossdeepCity/scripts.pory"
	.string "the people at the SPACE CENTER.\p"
# 392 "data/maps/MossdeepCity/scripts.pory"
	.string "They put it here as their wish for\n"
# 393 "data/maps/MossdeepCity/scripts.pory"
	.string "their rockets to fly safely.\p"
# 394 "data/maps/MossdeepCity/scripts.pory"
	.string "When you make a wish, what do you use?\n"
# 395 "data/maps/MossdeepCity/scripts.pory"
	.string "Do you wish upon a star?\p"
# 396 "data/maps/MossdeepCity/scripts.pory"
	.string "I use a wish tag to make it happen.\n"
# 397 "data/maps/MossdeepCity/scripts.pory"
	.string "That's what I do.$"
# 398 "data/maps/MossdeepCity/scripts.pory"

# 399 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_Text_ItsAWhiteRock:
# 400 "data/maps/MossdeepCity/scripts.pory"
	.string "It's a white rock.$"
# 401 "data/maps/MossdeepCity/scripts.pory"

# 402 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_Text_GymSign:
# 403 "data/maps/MossdeepCity/scripts.pory"
	.string "MOSSDEEP CITY POKéMON GYM\n"
# 404 "data/maps/MossdeepCity/scripts.pory"
	.string "LEADERS: LIZA & TATE\p"
# 405 "data/maps/MossdeepCity/scripts.pory"
	.string "“The mystic combination!”$"
# 406 "data/maps/MossdeepCity/scripts.pory"

# 407 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_Text_CitySign:
# 408 "data/maps/MossdeepCity/scripts.pory"
	.string "MOSSDEEP CITY\n"
# 409 "data/maps/MossdeepCity/scripts.pory"
	.string "“Our slogan: Cherish POKéMON!”$"
# 410 "data/maps/MossdeepCity/scripts.pory"

# 411 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_Text_SpaceCenterSign:
# 412 "data/maps/MossdeepCity/scripts.pory"
	.string "MOSSDEEP SPACE CENTER\n"
# 413 "data/maps/MossdeepCity/scripts.pory"
	.string "“The closest place to space.”$"
# 414 "data/maps/MossdeepCity/scripts.pory"

# 415 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_Text_ScottSomethingWrongWithTown:
# 416 "data/maps/MossdeepCity/scripts.pory"
	.string "SCOTT: {PLAYER}{KUN}, feeling good?\n"
# 417 "data/maps/MossdeepCity/scripts.pory"
	.string "I'm doing great!\p"
# 418 "data/maps/MossdeepCity/scripts.pory"
	.string "I'd heard MOSSDEEP's GYM LEADER is\n"
# 419 "data/maps/MossdeepCity/scripts.pory"
	.string "pretty strong, so I decided to come\l"
# 420 "data/maps/MossdeepCity/scripts.pory"
	.string "take a look-see for myself.\p"
# 421 "data/maps/MossdeepCity/scripts.pory"
	.string "But there's something wrong about\n"
# 422 "data/maps/MossdeepCity/scripts.pory"
	.string "this town.\p"
# 423 "data/maps/MossdeepCity/scripts.pory"
	.string "People are going on about a warning\n"
# 424 "data/maps/MossdeepCity/scripts.pory"
	.string "letter and the SPACE CENTER…\p"
# 425 "data/maps/MossdeepCity/scripts.pory"
	.string "I don't think it concerns me in any\n"
# 426 "data/maps/MossdeepCity/scripts.pory"
	.string "way, though.$"
# 427 "data/maps/MossdeepCity/scripts.pory"

# 428 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_Text_SootopolisNewGymLeader:
# 429 "data/maps/MossdeepCity/scripts.pory"
	.string "Ahh… It feels great letting the waves\n"
# 430 "data/maps/MossdeepCity/scripts.pory"
	.string "wash over my feet…\p"
# 431 "data/maps/MossdeepCity/scripts.pory"
	.string "Speaking of the waves, you know that\n"
# 432 "data/maps/MossdeepCity/scripts.pory"
	.string "island city SOOTOPOLIS?\p"
# 433 "data/maps/MossdeepCity/scripts.pory"
	.string "I think the GYM there had a new\n"
# 434 "data/maps/MossdeepCity/scripts.pory"
	.string "LEADER come in.\p"
# 435 "data/maps/MossdeepCity/scripts.pory"
	.string "People tell me the new LEADER once\n"
# 436 "data/maps/MossdeepCity/scripts.pory"
	.string "mentored WALLACE.$"
# 437 "data/maps/MossdeepCity/scripts.pory"

# 438 "data/maps/MossdeepCity/scripts.pory"
EventScript_MeteorGift::
# 439 "data/maps/MossdeepCity/scripts.pory"
    lock
# 440 "data/maps/MossdeepCity/scripts.pory"
    faceplayer
# 441 "data/maps/MossdeepCity/scripts.pory"
    message gText_CharmMeteortext
# 442 "data/maps/MossdeepCity/scripts.pory"
    waitmessage
# 443 "data/maps/MossdeepCity/scripts.pory"
    checkitem ITEM_METEORITE, 1
# 444 "data/maps/MossdeepCity/scripts.pory"
    compare VAR_RESULT, 1
# 445 "data/maps/MossdeepCity/scripts.pory"
    goto_if_eq Script_havemeteorite
# 446 "data/maps/MossdeepCity/scripts.pory"
    waitmessage
# 447 "data/maps/MossdeepCity/scripts.pory"
    message gText_HereisMeteor
# 448 "data/maps/MossdeepCity/scripts.pory"
    giveitem ITEM_METEORITE
# 449 "data/maps/MossdeepCity/scripts.pory"
    release
# 450 "data/maps/MossdeepCity/scripts.pory"
    end
# 451 "data/maps/MossdeepCity/scripts.pory"

# 452 "data/maps/MossdeepCity/scripts.pory"
gText_CharmMeteortext::
# 453 "data/maps/MossdeepCity/scripts.pory"
    .string "Do I have an amazing gift for you!\p $"
# 454 "data/maps/MossdeepCity/scripts.pory"

# 455 "data/maps/MossdeepCity/scripts.pory"
gText_HereisMeteor::
# 456 "data/maps/MossdeepCity/scripts.pory"
    .string "Enjoy your special item!\p $"
# 457 "data/maps/MossdeepCity/scripts.pory"

# 458 "data/maps/MossdeepCity/scripts.pory"
Script_havemeteorite::
# 459 "data/maps/MossdeepCity/scripts.pory"
    msgbox gText_havemeteorite
# 460 "data/maps/MossdeepCity/scripts.pory"
    release
# 461 "data/maps/MossdeepCity/scripts.pory"
    end
# 462 "data/maps/MossdeepCity/scripts.pory"

# 463 "data/maps/MossdeepCity/scripts.pory"
gText_havemeteorite::
# 464 "data/maps/MossdeepCity/scripts.pory"
    .string "You have already recieved this item!\p $"
