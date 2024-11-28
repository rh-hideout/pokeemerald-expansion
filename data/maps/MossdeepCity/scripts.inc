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
	map_script MAP_SCRIPT_ON_RESUME, Mossdeep_OnResume
# 13 "data/maps/MossdeepCity/scripts.pory"
	.byte 0
# 14 "data/maps/MossdeepCity/scripts.pory"

# 15 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_OnTransition:
# 16 "data/maps/MossdeepCity/scripts.pory"
	clearflag FLAG_MOSSDEEP_GYM_SWITCH_1
# 17 "data/maps/MossdeepCity/scripts.pory"
	clearflag FLAG_MOSSDEEP_GYM_SWITCH_2
# 18 "data/maps/MossdeepCity/scripts.pory"
	clearflag FLAG_MOSSDEEP_GYM_SWITCH_3
# 19 "data/maps/MossdeepCity/scripts.pory"
	clearflag FLAG_MOSSDEEP_GYM_SWITCH_4
# 20 "data/maps/MossdeepCity/scripts.pory"
	call_if_set FLAG_SYS_WEATHER_CTRL, Common_EventScript_SetAbnormalWeather
# 21 "data/maps/MossdeepCity/scripts.pory"
	end
# 22 "data/maps/MossdeepCity/scripts.pory"

# 23 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_EventScript_PokefanF::
# 24 "data/maps/MossdeepCity/scripts.pory"
	lock
# 25 "data/maps/MossdeepCity/scripts.pory"
	faceplayer
# 26 "data/maps/MossdeepCity/scripts.pory"
	goto_if_set FLAG_RECEIVED_HM_DIVE, MossdeepCity_EventScript_PokefanFMagmaGone
# 27 "data/maps/MossdeepCity/scripts.pory"
	msgbox MossdeepCity_Text_SpaceCenterReceivedLetter, MSGBOX_DEFAULT
# 28 "data/maps/MossdeepCity/scripts.pory"
	release
# 29 "data/maps/MossdeepCity/scripts.pory"
	end
# 30 "data/maps/MossdeepCity/scripts.pory"

# 31 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_EventScript_PokefanFMagmaGone::
# 32 "data/maps/MossdeepCity/scripts.pory"
	msgbox MossdeepCity_Text_SpaceCenterLaunchingRockets, MSGBOX_DEFAULT
# 33 "data/maps/MossdeepCity/scripts.pory"
	release
# 34 "data/maps/MossdeepCity/scripts.pory"
	end
# 35 "data/maps/MossdeepCity/scripts.pory"

# 36 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_EventScript_Sailor::
# 37 "data/maps/MossdeepCity/scripts.pory"
	lock
# 38 "data/maps/MossdeepCity/scripts.pory"
	faceplayer
# 39 "data/maps/MossdeepCity/scripts.pory"
	goto_if_set FLAG_RECEIVED_HM_DIVE, MossdeepCity_EventScript_SailorMagmaGone
# 40 "data/maps/MossdeepCity/scripts.pory"
	msgbox MossdeepCity_Text_MossdeepTargetedByMagma, MSGBOX_DEFAULT
# 41 "data/maps/MossdeepCity/scripts.pory"
	release
# 42 "data/maps/MossdeepCity/scripts.pory"
	end
# 43 "data/maps/MossdeepCity/scripts.pory"

# 44 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_EventScript_SailorMagmaGone::
# 45 "data/maps/MossdeepCity/scripts.pory"
	msgbox MossdeepCity_Text_FeelReliefOnLand, MSGBOX_DEFAULT
# 46 "data/maps/MossdeepCity/scripts.pory"
	release
# 47 "data/maps/MossdeepCity/scripts.pory"
	end
# 48 "data/maps/MossdeepCity/scripts.pory"

# 49 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_EventScript_NinjaBoy::
# 50 "data/maps/MossdeepCity/scripts.pory"
	msgbox MossdeepCity_Text_WailmerWatching, MSGBOX_NPC
# 51 "data/maps/MossdeepCity/scripts.pory"
	end
# 52 "data/maps/MossdeepCity/scripts.pory"

# 53 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_EventScript_ExpertM::
# 54 "data/maps/MossdeepCity/scripts.pory"
	msgbox MossdeepCity_Text_LifeNeedsSeaToLive, MSGBOX_NPC
# 55 "data/maps/MossdeepCity/scripts.pory"
	end
# 56 "data/maps/MossdeepCity/scripts.pory"

# 57 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_EventScript_Girl::
# 58 "data/maps/MossdeepCity/scripts.pory"
	msgbox MossdeepCity_Text_NiceIfWorldCoveredByFlowers, MSGBOX_NPC
# 59 "data/maps/MossdeepCity/scripts.pory"
	end
# 60 "data/maps/MossdeepCity/scripts.pory"

# 61 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_EventScript_Woman::
# 62 "data/maps/MossdeepCity/scripts.pory"
	msgbox MossdeepCity_Text_SpecialSpaceCenterRock, MSGBOX_NPC
# 63 "data/maps/MossdeepCity/scripts.pory"
	end
# 64 "data/maps/MossdeepCity/scripts.pory"

# 65 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_EventScript_WhiteRock::
# 66 "data/maps/MossdeepCity/scripts.pory"
	msgbox MossdeepCity_Text_ItsAWhiteRock, MSGBOX_SIGN
# 67 "data/maps/MossdeepCity/scripts.pory"
	end
# 68 "data/maps/MossdeepCity/scripts.pory"

# 69 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_EventScript_GymSign::
# 70 "data/maps/MossdeepCity/scripts.pory"
	msgbox MossdeepCity_Text_GymSign, MSGBOX_SIGN
# 71 "data/maps/MossdeepCity/scripts.pory"
	end
# 72 "data/maps/MossdeepCity/scripts.pory"

# 73 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_EventScript_CitySign::
# 74 "data/maps/MossdeepCity/scripts.pory"
	msgbox MossdeepCity_Text_CitySign, MSGBOX_SIGN
# 75 "data/maps/MossdeepCity/scripts.pory"
	end
# 76 "data/maps/MossdeepCity/scripts.pory"

# 77 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_EventScript_SpaceCenterSign::
# 78 "data/maps/MossdeepCity/scripts.pory"
	msgbox MossdeepCity_Text_SpaceCenterSign, MSGBOX_SIGN
# 79 "data/maps/MossdeepCity/scripts.pory"
	end
# 80 "data/maps/MossdeepCity/scripts.pory"

# 81 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_EventScript_VisitedMossdeep::
# 82 "data/maps/MossdeepCity/scripts.pory"
	setflag FLAG_VISITED_MOSSDEEP_CITY
# 83 "data/maps/MossdeepCity/scripts.pory"
	setvar VAR_TEMP_1, 1
# 84 "data/maps/MossdeepCity/scripts.pory"
	end
# 85 "data/maps/MossdeepCity/scripts.pory"

# 86 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_EventScript_TeamMagmaEnterSpaceCenter::
# 87 "data/maps/MossdeepCity/scripts.pory"
	lockall
# 88 "data/maps/MossdeepCity/scripts.pory"
	applymovement LOCALID_MAXIE, MossdeepCity_Movement_MaxieGestureToSpaceCenter
# 89 "data/maps/MossdeepCity/scripts.pory"
	waitmovement 0
# 90 "data/maps/MossdeepCity/scripts.pory"
	applymovement LOCALID_GRUNT_1, MossdeepCity_Movement_GruntFaceSpaceCenter
# 91 "data/maps/MossdeepCity/scripts.pory"
	applymovement LOCALID_GRUNT_2, MossdeepCity_Movement_GruntFaceSpaceCenter
# 92 "data/maps/MossdeepCity/scripts.pory"
	applymovement LOCALID_GRUNT_3, MossdeepCity_Movement_GruntFaceSpaceCenter
# 93 "data/maps/MossdeepCity/scripts.pory"
	applymovement LOCALID_GRUNT_4, MossdeepCity_Movement_GruntFaceSpaceCenter
# 94 "data/maps/MossdeepCity/scripts.pory"
	waitmovement 0
# 95 "data/maps/MossdeepCity/scripts.pory"
	applymovement LOCALID_MAXIE, MossdeepCity_Movement_MaxieEnterSpaceCenter
# 96 "data/maps/MossdeepCity/scripts.pory"
	applymovement LOCALID_GRUNT_1, MossdeepCity_Movement_Grunt1EnterSpaceCenter
# 97 "data/maps/MossdeepCity/scripts.pory"
	applymovement LOCALID_GRUNT_2, MossdeepCity_Movement_Grunt2EnterSpaceCenter
# 98 "data/maps/MossdeepCity/scripts.pory"
	applymovement LOCALID_GRUNT_3, MossdeepCity_Movement_Grunt3EnterSpaceCenter
# 99 "data/maps/MossdeepCity/scripts.pory"
	applymovement LOCALID_GRUNT_4, MossdeepCity_Movement_Grunt4EnterSpaceCenter
# 100 "data/maps/MossdeepCity/scripts.pory"
	waitmovement 0
# 101 "data/maps/MossdeepCity/scripts.pory"
	removeobject LOCALID_MAXIE
# 102 "data/maps/MossdeepCity/scripts.pory"
	removeobject LOCALID_GRUNT_1
# 103 "data/maps/MossdeepCity/scripts.pory"
	removeobject LOCALID_GRUNT_2
# 104 "data/maps/MossdeepCity/scripts.pory"
	removeobject LOCALID_GRUNT_3
# 105 "data/maps/MossdeepCity/scripts.pory"
	removeobject LOCALID_GRUNT_4
# 106 "data/maps/MossdeepCity/scripts.pory"
	delay 30
# 107 "data/maps/MossdeepCity/scripts.pory"
	setvar VAR_MOSSDEEP_CITY_STATE, 2
# 108 "data/maps/MossdeepCity/scripts.pory"
	setflag FLAG_HIDE_MOSSDEEP_CITY_TEAM_MAGMA
# 109 "data/maps/MossdeepCity/scripts.pory"
	releaseall
# 110 "data/maps/MossdeepCity/scripts.pory"
	end
# 111 "data/maps/MossdeepCity/scripts.pory"

# 112 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_Movement_MaxieGestureToSpaceCenter:
# 113 "data/maps/MossdeepCity/scripts.pory"
	delay_16
# 114 "data/maps/MossdeepCity/scripts.pory"
	face_right
# 115 "data/maps/MossdeepCity/scripts.pory"
	delay_16
# 116 "data/maps/MossdeepCity/scripts.pory"
	delay_16
# 117 "data/maps/MossdeepCity/scripts.pory"
	delay_16
# 118 "data/maps/MossdeepCity/scripts.pory"
	delay_16
# 119 "data/maps/MossdeepCity/scripts.pory"
	face_left
# 120 "data/maps/MossdeepCity/scripts.pory"
	delay_16
# 121 "data/maps/MossdeepCity/scripts.pory"
	delay_16
# 122 "data/maps/MossdeepCity/scripts.pory"
	step_end
# 123 "data/maps/MossdeepCity/scripts.pory"

# 124 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_Movement_GruntFaceSpaceCenter:
# 125 "data/maps/MossdeepCity/scripts.pory"
	face_right
# 126 "data/maps/MossdeepCity/scripts.pory"
	delay_16
# 127 "data/maps/MossdeepCity/scripts.pory"
	delay_16
# 128 "data/maps/MossdeepCity/scripts.pory"
	delay_16
# 129 "data/maps/MossdeepCity/scripts.pory"
	step_end
# 130 "data/maps/MossdeepCity/scripts.pory"

# 131 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_Movement_MaxieEnterSpaceCenter:
# 132 "data/maps/MossdeepCity/scripts.pory"
	walk_down
# 133 "data/maps/MossdeepCity/scripts.pory"
	walk_right
# 134 "data/maps/MossdeepCity/scripts.pory"
	walk_right
# 135 "data/maps/MossdeepCity/scripts.pory"
	walk_down
# 136 "data/maps/MossdeepCity/scripts.pory"
	walk_down
# 137 "data/maps/MossdeepCity/scripts.pory"
	walk_down
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
	walk_right
# 145 "data/maps/MossdeepCity/scripts.pory"
	step_end
# 146 "data/maps/MossdeepCity/scripts.pory"

# 147 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_Movement_Grunt1EnterSpaceCenter:
# 148 "data/maps/MossdeepCity/scripts.pory"
	delay_16
# 149 "data/maps/MossdeepCity/scripts.pory"
	delay_8
# 150 "data/maps/MossdeepCity/scripts.pory"
	walk_down
# 151 "data/maps/MossdeepCity/scripts.pory"
	walk_down
# 152 "data/maps/MossdeepCity/scripts.pory"
	walk_down
# 153 "data/maps/MossdeepCity/scripts.pory"
	walk_right
# 154 "data/maps/MossdeepCity/scripts.pory"
	walk_right
# 155 "data/maps/MossdeepCity/scripts.pory"
	walk_right
# 156 "data/maps/MossdeepCity/scripts.pory"
	walk_down
# 157 "data/maps/MossdeepCity/scripts.pory"
	walk_down
# 158 "data/maps/MossdeepCity/scripts.pory"
	walk_down
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
	walk_right
# 166 "data/maps/MossdeepCity/scripts.pory"
	step_end
# 167 "data/maps/MossdeepCity/scripts.pory"

# 168 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_Movement_Grunt2EnterSpaceCenter:
# 169 "data/maps/MossdeepCity/scripts.pory"
	delay_16
# 170 "data/maps/MossdeepCity/scripts.pory"
	delay_8
# 171 "data/maps/MossdeepCity/scripts.pory"
	walk_down
# 172 "data/maps/MossdeepCity/scripts.pory"
	walk_down
# 173 "data/maps/MossdeepCity/scripts.pory"
	walk_right
# 174 "data/maps/MossdeepCity/scripts.pory"
	walk_right
# 175 "data/maps/MossdeepCity/scripts.pory"
	walk_right
# 176 "data/maps/MossdeepCity/scripts.pory"
	walk_down
# 177 "data/maps/MossdeepCity/scripts.pory"
	walk_down
# 178 "data/maps/MossdeepCity/scripts.pory"
	walk_down
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
	walk_right
# 186 "data/maps/MossdeepCity/scripts.pory"
	step_end
# 187 "data/maps/MossdeepCity/scripts.pory"

# 188 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_Movement_Grunt3EnterSpaceCenter:
# 189 "data/maps/MossdeepCity/scripts.pory"
	delay_16
# 190 "data/maps/MossdeepCity/scripts.pory"
	delay_8
# 191 "data/maps/MossdeepCity/scripts.pory"
	walk_down
# 192 "data/maps/MossdeepCity/scripts.pory"
	walk_right
# 193 "data/maps/MossdeepCity/scripts.pory"
	walk_right
# 194 "data/maps/MossdeepCity/scripts.pory"
	walk_right
# 195 "data/maps/MossdeepCity/scripts.pory"
	walk_down
# 196 "data/maps/MossdeepCity/scripts.pory"
	walk_down
# 197 "data/maps/MossdeepCity/scripts.pory"
	walk_down
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
	walk_right
# 205 "data/maps/MossdeepCity/scripts.pory"
	step_end
# 206 "data/maps/MossdeepCity/scripts.pory"

# 207 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_Movement_Grunt4EnterSpaceCenter:
# 208 "data/maps/MossdeepCity/scripts.pory"
	delay_16
# 209 "data/maps/MossdeepCity/scripts.pory"
	delay_8
# 210 "data/maps/MossdeepCity/scripts.pory"
	walk_right
# 211 "data/maps/MossdeepCity/scripts.pory"
	walk_right
# 212 "data/maps/MossdeepCity/scripts.pory"
	walk_right
# 213 "data/maps/MossdeepCity/scripts.pory"
	walk_down
# 214 "data/maps/MossdeepCity/scripts.pory"
	walk_down
# 215 "data/maps/MossdeepCity/scripts.pory"
	walk_down
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
	walk_right
# 223 "data/maps/MossdeepCity/scripts.pory"
	step_end
# 224 "data/maps/MossdeepCity/scripts.pory"

# 225 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_EventScript_Man::
# 226 "data/maps/MossdeepCity/scripts.pory"
	lock
# 227 "data/maps/MossdeepCity/scripts.pory"
	faceplayer
# 228 "data/maps/MossdeepCity/scripts.pory"
	msgbox MossdeepCity_Text_SurfExhilarating, MSGBOX_DEFAULT
# 229 "data/maps/MossdeepCity/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
# 230 "data/maps/MossdeepCity/scripts.pory"
	waitmovement 0
# 231 "data/maps/MossdeepCity/scripts.pory"
	release
# 232 "data/maps/MossdeepCity/scripts.pory"
	end
# 233 "data/maps/MossdeepCity/scripts.pory"

# 234 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_EventScript_KingsRockBoy::
# 235 "data/maps/MossdeepCity/scripts.pory"
	lock
# 236 "data/maps/MossdeepCity/scripts.pory"
	faceplayer
# 237 "data/maps/MossdeepCity/scripts.pory"
	goto_if_set FLAG_RECEIVED_KINGS_ROCK, MossdeepCity_EventScript_ReceivedKingsRock
# 238 "data/maps/MossdeepCity/scripts.pory"
	msgbox MossdeepCity_Text_WantKingsRockStevenGaveMe, MSGBOX_YESNO
# 239 "data/maps/MossdeepCity/scripts.pory"
	goto_if_eq VAR_RESULT, NO, MossdeepCity_EventScript_DeclineKingsRock
# 240 "data/maps/MossdeepCity/scripts.pory"
	msgbox MossdeepCity_Text_YouCanKeepIt, MSGBOX_DEFAULT
# 241 "data/maps/MossdeepCity/scripts.pory"
	giveitem ITEM_KINGS_ROCK
# 242 "data/maps/MossdeepCity/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
# 243 "data/maps/MossdeepCity/scripts.pory"
	setflag FLAG_RECEIVED_KINGS_ROCK
# 244 "data/maps/MossdeepCity/scripts.pory"
	release
# 245 "data/maps/MossdeepCity/scripts.pory"
	end
# 246 "data/maps/MossdeepCity/scripts.pory"

# 247 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_EventScript_ReceivedKingsRock::
# 248 "data/maps/MossdeepCity/scripts.pory"
	msgbox MossdeepCity_Text_StevensHouseOverThere, MSGBOX_DEFAULT
# 249 "data/maps/MossdeepCity/scripts.pory"
	release
# 250 "data/maps/MossdeepCity/scripts.pory"
	end
# 251 "data/maps/MossdeepCity/scripts.pory"

# 252 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_EventScript_DeclineKingsRock::
# 253 "data/maps/MossdeepCity/scripts.pory"
	msgbox MossdeepCity_Text_WhatToDoWithWeirdRock, MSGBOX_DEFAULT
# 254 "data/maps/MossdeepCity/scripts.pory"
	release
# 255 "data/maps/MossdeepCity/scripts.pory"
	end
# 256 "data/maps/MossdeepCity/scripts.pory"

# 257 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_EventScript_BlackBelt::
# 258 "data/maps/MossdeepCity/scripts.pory"
	msgbox MossdeepCity_Text_SootopolisNewGymLeader, MSGBOX_NPC
# 259 "data/maps/MossdeepCity/scripts.pory"
	end
# 260 "data/maps/MossdeepCity/scripts.pory"

# 261 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_EventScript_Scott::
# 262 "data/maps/MossdeepCity/scripts.pory"
	lock
# 263 "data/maps/MossdeepCity/scripts.pory"
	faceplayer
# 264 "data/maps/MossdeepCity/scripts.pory"
	msgbox MossdeepCity_Text_ScottSomethingWrongWithTown, MSGBOX_DEFAULT
# 265 "data/maps/MossdeepCity/scripts.pory"
	closemessage
# 266 "data/maps/MossdeepCity/scripts.pory"
	call_if_eq VAR_FACING, DIR_NORTH, MossdeepCity_EventScript_ScottExitNorth
# 267 "data/maps/MossdeepCity/scripts.pory"
	call_if_eq VAR_FACING, DIR_EAST, MossdeepCity_EventScript_ScottExitEast
# 268 "data/maps/MossdeepCity/scripts.pory"
	addvar VAR_SCOTT_STATE, 1
# 269 "data/maps/MossdeepCity/scripts.pory"
	removeobject LOCALID_SCOTT
# 270 "data/maps/MossdeepCity/scripts.pory"
	release
# 271 "data/maps/MossdeepCity/scripts.pory"
	end
# 272 "data/maps/MossdeepCity/scripts.pory"

# 273 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_EventScript_ScottExitNorth::
# 274 "data/maps/MossdeepCity/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, MossdeepCity_Movement_PlayerWatchScottExit
# 275 "data/maps/MossdeepCity/scripts.pory"
	applymovement LOCALID_SCOTT, MossdeepCity_Movement_ScottExitNorth
# 276 "data/maps/MossdeepCity/scripts.pory"
	waitmovement 0
# 277 "data/maps/MossdeepCity/scripts.pory"
	return
# 278 "data/maps/MossdeepCity/scripts.pory"

# 279 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_EventScript_ScottExitEast::
# 280 "data/maps/MossdeepCity/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, MossdeepCity_Movement_PlayerWatchScottExit
# 281 "data/maps/MossdeepCity/scripts.pory"
	applymovement LOCALID_SCOTT, MossdeepCity_Movement_ScottExitEast
# 282 "data/maps/MossdeepCity/scripts.pory"
	waitmovement 0
# 283 "data/maps/MossdeepCity/scripts.pory"
	return
# 284 "data/maps/MossdeepCity/scripts.pory"

# 285 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_Movement_PlayerWatchScottExit:
# 286 "data/maps/MossdeepCity/scripts.pory"
	delay_16
# 287 "data/maps/MossdeepCity/scripts.pory"
	delay_16
# 288 "data/maps/MossdeepCity/scripts.pory"
	walk_in_place_faster_left
# 289 "data/maps/MossdeepCity/scripts.pory"
	step_end
# 290 "data/maps/MossdeepCity/scripts.pory"

# 291 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_Movement_ScottExitNorth:
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
	walk_left
# 301 "data/maps/MossdeepCity/scripts.pory"
	step_end
# 302 "data/maps/MossdeepCity/scripts.pory"

# 303 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_Movement_ScottExitEast:
# 304 "data/maps/MossdeepCity/scripts.pory"
	walk_down
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
	walk_left
# 314 "data/maps/MossdeepCity/scripts.pory"
	step_end
# 315 "data/maps/MossdeepCity/scripts.pory"

# 316 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_Text_WantKingsRockStevenGaveMe:
# 317 "data/maps/MossdeepCity/scripts.pory"
	.string "I got this from STEVEN, but I don't\n"
# 318 "data/maps/MossdeepCity/scripts.pory"
	.string "know what it's good for.\p"
# 319 "data/maps/MossdeepCity/scripts.pory"
	.string "I think it's called KING'S ROCK.\n"
# 320 "data/maps/MossdeepCity/scripts.pory"
	.string "Do you want it?$"
# 321 "data/maps/MossdeepCity/scripts.pory"

# 322 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_Text_YouCanKeepIt:
# 323 "data/maps/MossdeepCity/scripts.pory"
	.string "Why would you want it?\n"
# 324 "data/maps/MossdeepCity/scripts.pory"
	.string "You're weird.\p"
# 325 "data/maps/MossdeepCity/scripts.pory"
	.string "You can keep it, but keep it a secret\n"
# 326 "data/maps/MossdeepCity/scripts.pory"
	.string "from STEVEN.$"
# 327 "data/maps/MossdeepCity/scripts.pory"

# 328 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_Text_StevensHouseOverThere:
# 329 "data/maps/MossdeepCity/scripts.pory"
	.string "STEVEN's house is right over there!$"
# 330 "data/maps/MossdeepCity/scripts.pory"

# 331 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_Text_WhatToDoWithWeirdRock:
# 332 "data/maps/MossdeepCity/scripts.pory"
	.string "Yeah, you think so, too! What are you\n"
# 333 "data/maps/MossdeepCity/scripts.pory"
	.string "supposed to do with some weird rock?$"
# 334 "data/maps/MossdeepCity/scripts.pory"

# 335 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_Text_WailmerWatching:
# 336 "data/maps/MossdeepCity/scripts.pory"
	.string "Around MOSSDEEP, you can see wild\n"
# 337 "data/maps/MossdeepCity/scripts.pory"
	.string "WAILMER.\p"
# 338 "data/maps/MossdeepCity/scripts.pory"
	.string "It's called, uh…\n"
# 339 "data/maps/MossdeepCity/scripts.pory"
	.string "What was it now…\p"
# 340 "data/maps/MossdeepCity/scripts.pory"
	.string "WAI, WAI, WAI…\p"
# 341 "data/maps/MossdeepCity/scripts.pory"
	.string "WAILMER watching!$"
# 342 "data/maps/MossdeepCity/scripts.pory"

# 343 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_Text_SpaceCenterReceivedLetter:
# 344 "data/maps/MossdeepCity/scripts.pory"
	.string "The island's SPACE CENTER has been\n"
# 345 "data/maps/MossdeepCity/scripts.pory"
	.string "launching huge rockets.\p"
# 346 "data/maps/MossdeepCity/scripts.pory"
	.string "There's been some kind of an uproar\n"
# 347 "data/maps/MossdeepCity/scripts.pory"
	.string "over a letter they received recently.$"
# 348 "data/maps/MossdeepCity/scripts.pory"

# 349 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_Text_SpaceCenterLaunchingRockets:
# 350 "data/maps/MossdeepCity/scripts.pory"
	.string "The island's SPACE CENTER has been\n"
# 351 "data/maps/MossdeepCity/scripts.pory"
	.string "launching huge rockets.$"
# 352 "data/maps/MossdeepCity/scripts.pory"

# 353 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_Text_MossdeepTargetedByMagma:
# 354 "data/maps/MossdeepCity/scripts.pory"
	.string "I heard from a SAILOR buddy that\n"
# 355 "data/maps/MossdeepCity/scripts.pory"
	.string "TEAM AQUA set up shop in LILYCOVE.\p"
# 356 "data/maps/MossdeepCity/scripts.pory"
	.string "I also heard that someone came along\n"
# 357 "data/maps/MossdeepCity/scripts.pory"
	.string "and wiped the floor with them!\p"
# 358 "data/maps/MossdeepCity/scripts.pory"
	.string "But MOSSDEEP here's been targeted\n"
# 359 "data/maps/MossdeepCity/scripts.pory"
	.string "by that TEAM MAGMA.\p"
# 360 "data/maps/MossdeepCity/scripts.pory"
	.string "If you want to know what they're up to,\n"
# 361 "data/maps/MossdeepCity/scripts.pory"
	.string "go visit the SPACE CENTER.$"
# 362 "data/maps/MossdeepCity/scripts.pory"

# 363 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_Text_FeelReliefOnLand:
# 364 "data/maps/MossdeepCity/scripts.pory"
	.string "I'm a SAILOR, so the sea's obviously\n"
# 365 "data/maps/MossdeepCity/scripts.pory"
	.string "more important to me.\p"
# 366 "data/maps/MossdeepCity/scripts.pory"
	.string "But you know? When I get back on land\n"
# 367 "data/maps/MossdeepCity/scripts.pory"
	.string "after a long voyage, I do feel relief!$"
# 368 "data/maps/MossdeepCity/scripts.pory"

# 369 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_Text_NiceIfWorldCoveredByFlowers:
# 370 "data/maps/MossdeepCity/scripts.pory"
	.string "Wouldn't it be nice?\p"
# 371 "data/maps/MossdeepCity/scripts.pory"
	.string "If the whole world was covered in\n"
# 372 "data/maps/MossdeepCity/scripts.pory"
	.string "plants and flowers like this island?$"
# 373 "data/maps/MossdeepCity/scripts.pory"

# 374 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_Text_LifeNeedsSeaToLive:
# 375 "data/maps/MossdeepCity/scripts.pory"
	.string "All life needs the sea to live, even\n"
# 376 "data/maps/MossdeepCity/scripts.pory"
	.string "though it makes its home on the land.\p"
# 377 "data/maps/MossdeepCity/scripts.pory"
	.string "Life, having run its course, becomes\n"
# 378 "data/maps/MossdeepCity/scripts.pory"
	.string "soil and returns to the land.\p"
# 379 "data/maps/MossdeepCity/scripts.pory"
	.string "And the sea is always connected to\n"
# 380 "data/maps/MossdeepCity/scripts.pory"
	.string "the land.\p"
# 381 "data/maps/MossdeepCity/scripts.pory"
	.string "Yes, like the very shoreline here.$"
# 382 "data/maps/MossdeepCity/scripts.pory"

# 383 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_Text_SurfExhilarating:
# 384 "data/maps/MossdeepCity/scripts.pory"
	.string "A voyage on a ship is fine.\p"
# 385 "data/maps/MossdeepCity/scripts.pory"
	.string "But crossing the sea with POKéMON\n"
# 386 "data/maps/MossdeepCity/scripts.pory"
	.string "using SURF…\p"
# 387 "data/maps/MossdeepCity/scripts.pory"
	.string "Now that's an exhilarating trip!\n"
# 388 "data/maps/MossdeepCity/scripts.pory"
	.string "Wouldn't you agree, youngster?$"
# 389 "data/maps/MossdeepCity/scripts.pory"

# 390 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_Text_SpecialSpaceCenterRock:
# 391 "data/maps/MossdeepCity/scripts.pory"
	.string "This rock has a special meaning to\n"
# 392 "data/maps/MossdeepCity/scripts.pory"
	.string "the people at the SPACE CENTER.\p"
# 393 "data/maps/MossdeepCity/scripts.pory"
	.string "They put it here as their wish for\n"
# 394 "data/maps/MossdeepCity/scripts.pory"
	.string "their rockets to fly safely.\p"
# 395 "data/maps/MossdeepCity/scripts.pory"
	.string "When you make a wish, what do you use?\n"
# 396 "data/maps/MossdeepCity/scripts.pory"
	.string "Do you wish upon a star?\p"
# 397 "data/maps/MossdeepCity/scripts.pory"
	.string "I use a wish tag to make it happen.\n"
# 398 "data/maps/MossdeepCity/scripts.pory"
	.string "That's what I do.$"
# 399 "data/maps/MossdeepCity/scripts.pory"

# 400 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_Text_ItsAWhiteRock:
# 401 "data/maps/MossdeepCity/scripts.pory"
	.string "It's a white rock.$"
# 402 "data/maps/MossdeepCity/scripts.pory"

# 403 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_Text_GymSign:
# 404 "data/maps/MossdeepCity/scripts.pory"
	.string "MOSSDEEP CITY POKéMON GYM\n"
# 405 "data/maps/MossdeepCity/scripts.pory"
	.string "LEADERS: LIZA & TATE\p"
# 406 "data/maps/MossdeepCity/scripts.pory"
	.string "“The mystic combination!”$"
# 407 "data/maps/MossdeepCity/scripts.pory"

# 408 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_Text_CitySign:
# 409 "data/maps/MossdeepCity/scripts.pory"
	.string "MOSSDEEP CITY\n"
# 410 "data/maps/MossdeepCity/scripts.pory"
	.string "“Our slogan: Cherish POKéMON!”$"
# 411 "data/maps/MossdeepCity/scripts.pory"

# 412 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_Text_SpaceCenterSign:
# 413 "data/maps/MossdeepCity/scripts.pory"
	.string "MOSSDEEP SPACE CENTER\n"
# 414 "data/maps/MossdeepCity/scripts.pory"
	.string "“The closest place to space.”$"
# 415 "data/maps/MossdeepCity/scripts.pory"

# 416 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_Text_ScottSomethingWrongWithTown:
# 417 "data/maps/MossdeepCity/scripts.pory"
	.string "SCOTT: {PLAYER}{KUN}, feeling good?\n"
# 418 "data/maps/MossdeepCity/scripts.pory"
	.string "I'm doing great!\p"
# 419 "data/maps/MossdeepCity/scripts.pory"
	.string "I'd heard MOSSDEEP's GYM LEADER is\n"
# 420 "data/maps/MossdeepCity/scripts.pory"
	.string "pretty strong, so I decided to come\l"
# 421 "data/maps/MossdeepCity/scripts.pory"
	.string "take a look-see for myself.\p"
# 422 "data/maps/MossdeepCity/scripts.pory"
	.string "But there's something wrong about\n"
# 423 "data/maps/MossdeepCity/scripts.pory"
	.string "this town.\p"
# 424 "data/maps/MossdeepCity/scripts.pory"
	.string "People are going on about a warning\n"
# 425 "data/maps/MossdeepCity/scripts.pory"
	.string "letter and the SPACE CENTER…\p"
# 426 "data/maps/MossdeepCity/scripts.pory"
	.string "I don't think it concerns me in any\n"
# 427 "data/maps/MossdeepCity/scripts.pory"
	.string "way, though.$"
# 428 "data/maps/MossdeepCity/scripts.pory"

# 429 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_Text_SootopolisNewGymLeader:
# 430 "data/maps/MossdeepCity/scripts.pory"
	.string "Ahh… It feels great letting the waves\n"
# 431 "data/maps/MossdeepCity/scripts.pory"
	.string "wash over my feet…\p"
# 432 "data/maps/MossdeepCity/scripts.pory"
	.string "Speaking of the waves, you know that\n"
# 433 "data/maps/MossdeepCity/scripts.pory"
	.string "island city SOOTOPOLIS?\p"
# 434 "data/maps/MossdeepCity/scripts.pory"
	.string "I think the GYM there had a new\n"
# 435 "data/maps/MossdeepCity/scripts.pory"
	.string "LEADER come in.\p"
# 436 "data/maps/MossdeepCity/scripts.pory"
	.string "People tell me the new LEADER once\n"
# 437 "data/maps/MossdeepCity/scripts.pory"
	.string "mentored WALLACE.$"
# 438 "data/maps/MossdeepCity/scripts.pory"

# 439 "data/maps/MossdeepCity/scripts.pory"
EventScript_MeteorGift::
# 440 "data/maps/MossdeepCity/scripts.pory"
    lock
# 441 "data/maps/MossdeepCity/scripts.pory"
    faceplayer
# 442 "data/maps/MossdeepCity/scripts.pory"
    message gText_CharmMeteortext
# 443 "data/maps/MossdeepCity/scripts.pory"
    waitmessage
# 444 "data/maps/MossdeepCity/scripts.pory"
    checkitem ITEM_METEORITE, 1
# 445 "data/maps/MossdeepCity/scripts.pory"
    compare VAR_RESULT, 1
# 446 "data/maps/MossdeepCity/scripts.pory"
    goto_if_eq Script_havemeteorite
# 447 "data/maps/MossdeepCity/scripts.pory"
    waitmessage
# 448 "data/maps/MossdeepCity/scripts.pory"
    message gText_HereisMeteor
# 449 "data/maps/MossdeepCity/scripts.pory"
    giveitem ITEM_METEORITE
# 450 "data/maps/MossdeepCity/scripts.pory"
    release
# 451 "data/maps/MossdeepCity/scripts.pory"
    end
# 452 "data/maps/MossdeepCity/scripts.pory"

# 453 "data/maps/MossdeepCity/scripts.pory"
gText_CharmMeteortext::
# 454 "data/maps/MossdeepCity/scripts.pory"
    .string "Do I have an amazing gift for you!\p $"
# 455 "data/maps/MossdeepCity/scripts.pory"

# 456 "data/maps/MossdeepCity/scripts.pory"
gText_HereisMeteor::
# 457 "data/maps/MossdeepCity/scripts.pory"
    .string "Enjoy your special item!\p $"
# 458 "data/maps/MossdeepCity/scripts.pory"

# 459 "data/maps/MossdeepCity/scripts.pory"
Script_havemeteorite::
# 460 "data/maps/MossdeepCity/scripts.pory"
    msgbox gText_havemeteorite
# 461 "data/maps/MossdeepCity/scripts.pory"
    release
# 462 "data/maps/MossdeepCity/scripts.pory"
    end
# 463 "data/maps/MossdeepCity/scripts.pory"

# 464 "data/maps/MossdeepCity/scripts.pory"
gText_havemeteorite::
# 465 "data/maps/MossdeepCity/scripts.pory"
    .string "You have already recieved this item!\p $"
# 466 "data/maps/MossdeepCity/scripts.pory"

# 467 "data/maps/MossdeepCity/scripts.pory"
Mossdeep_OnResume:
# 468 "data/maps/MossdeepCity/scripts.pory"
    call_if_set FLAG_SYS_CTRL_OBJ_DELETE, Mossdeep_EventScript_TryRemoveJirachi
# 469 "data/maps/MossdeepCity/scripts.pory"
    end
# 470 "data/maps/MossdeepCity/scripts.pory"

# 471 "data/maps/MossdeepCity/scripts.pory"
Mossdeep_EventScript_TryRemoveJirachi::
# 472 "data/maps/MossdeepCity/scripts.pory"
    specialvar VAR_RESULT, GetBattleOutcome
# 473 "data/maps/MossdeepCity/scripts.pory"
    goto_if_ne VAR_RESULT, B_OUTCOME_CAUGHT, Common_EventScript_NopReturn
# 474 "data/maps/MossdeepCity/scripts.pory"
    removeobject VAR_LAST_TALKED
# 475 "data/maps/MossdeepCity/scripts.pory"
    return
# 476 "data/maps/MossdeepCity/scripts.pory"

# 477 "data/maps/MossdeepCity/scripts.pory"
Mossdeep_EventScript_Jirachi::
# 478 "data/maps/MossdeepCity/scripts.pory"
    lock
# 479 "data/maps/MossdeepCity/scripts.pory"
    faceplayer
# 480 "data/maps/MossdeepCity/scripts.pory"
    waitse
# 481 "data/maps/MossdeepCity/scripts.pory"
    playmoncry SPECIES_JIRACHI, CRY_MODE_ENCOUNTER
# 482 "data/maps/MossdeepCity/scripts.pory"
    delay 40
# 483 "data/maps/MossdeepCity/scripts.pory"
    waitmoncry
# 484 "data/maps/MossdeepCity/scripts.pory"
    setwildbattle SPECIES_JIRACHI, 35
# 485 "data/maps/MossdeepCity/scripts.pory"
    setflag FLAG_SYS_CTRL_OBJ_DELETE
# 486 "data/maps/MossdeepCity/scripts.pory"
    special BattleSetup_StartLegendaryBattle
# 487 "data/maps/MossdeepCity/scripts.pory"
    waitstate
# 488 "data/maps/MossdeepCity/scripts.pory"
    clearflag FLAG_SYS_CTRL_OBJ_DELETE
# 489 "data/maps/MossdeepCity/scripts.pory"
    specialvar VAR_RESULT, GetBattleOutcome
# 490 "data/maps/MossdeepCity/scripts.pory"
    goto_if_eq VAR_RESULT, B_OUTCOME_WON, Mossdeep_EventScript_DefeatedJirachi
# 491 "data/maps/MossdeepCity/scripts.pory"
    goto_if_eq VAR_RESULT, B_OUTCOME_RAN, Mossdeep_EventScript_RanFromJirachi
# 492 "data/maps/MossdeepCity/scripts.pory"
    goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, Mossdeep_EventScript_RanFromJirachi
# 493 "data/maps/MossdeepCity/scripts.pory"
    setflag FLAG_DEFEATED_JIRACHI
# 494 "data/maps/MossdeepCity/scripts.pory"
    release
# 495 "data/maps/MossdeepCity/scripts.pory"
    end
# 496 "data/maps/MossdeepCity/scripts.pory"

# 497 "data/maps/MossdeepCity/scripts.pory"
Mossdeep_EventScript_DefeatedJirachi::
# 498 "data/maps/MossdeepCity/scripts.pory"
    setflag FLAG_DEFEATED_JIRACHI
# 499 "data/maps/MossdeepCity/scripts.pory"
    goto Common_EventScript_RemoveStaticPokemon
# 500 "data/maps/MossdeepCity/scripts.pory"
    end
# 501 "data/maps/MossdeepCity/scripts.pory"

# 502 "data/maps/MossdeepCity/scripts.pory"
Mossdeep_EventScript_RanFromJirachi::
# 503 "data/maps/MossdeepCity/scripts.pory"
    setvar VAR_0x8004, SPECIES_JIRACHI
# 504 "data/maps/MossdeepCity/scripts.pory"
    goto Common_EventScript_LegendaryFlewAway
# 505 "data/maps/MossdeepCity/scripts.pory"
    end
