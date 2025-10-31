# 1 "data/maps/MossdeepCity/scripts.pory"

# 2 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_MapScripts::
# 3 "data/maps/MossdeepCity/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, MossdeepCity_OnTransition
# 4 "data/maps/MossdeepCity/scripts.pory"
	.byte 0
# 5 "data/maps/MossdeepCity/scripts.pory"

# 6 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_OnTransition:
# 7 "data/maps/MossdeepCity/scripts.pory"
	clearflag FLAG_MOSSDEEP_GYM_SWITCH_1
# 8 "data/maps/MossdeepCity/scripts.pory"
	clearflag FLAG_MOSSDEEP_GYM_SWITCH_2
# 9 "data/maps/MossdeepCity/scripts.pory"
	clearflag FLAG_MOSSDEEP_GYM_SWITCH_3
# 10 "data/maps/MossdeepCity/scripts.pory"
	clearflag FLAG_MOSSDEEP_GYM_SWITCH_4
# 11 "data/maps/MossdeepCity/scripts.pory"
	call_if_set FLAG_SYS_WEATHER_CTRL, Common_EventScript_SetAbnormalWeather
# 12 "data/maps/MossdeepCity/scripts.pory"
	end
# 13 "data/maps/MossdeepCity/scripts.pory"

# 14 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_EventScript_PokefanF::
# 15 "data/maps/MossdeepCity/scripts.pory"
	lock
# 16 "data/maps/MossdeepCity/scripts.pory"
	faceplayer
# 17 "data/maps/MossdeepCity/scripts.pory"
	goto_if_set FLAG_RECEIVED_HM_DIVE, MossdeepCity_EventScript_PokefanFMagmaGone
# 18 "data/maps/MossdeepCity/scripts.pory"
	msgbox MossdeepCity_Text_SpaceCenterReceivedLetter, MSGBOX_DEFAULT
# 19 "data/maps/MossdeepCity/scripts.pory"
	release
# 20 "data/maps/MossdeepCity/scripts.pory"
	end
# 21 "data/maps/MossdeepCity/scripts.pory"

# 22 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_EventScript_PokefanFMagmaGone::
# 23 "data/maps/MossdeepCity/scripts.pory"
	msgbox MossdeepCity_Text_SpaceCenterLaunchingRockets, MSGBOX_DEFAULT
# 24 "data/maps/MossdeepCity/scripts.pory"
	release
# 25 "data/maps/MossdeepCity/scripts.pory"
	end
# 26 "data/maps/MossdeepCity/scripts.pory"

# 27 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_EventScript_Sailor::
# 28 "data/maps/MossdeepCity/scripts.pory"
	lock
# 29 "data/maps/MossdeepCity/scripts.pory"
	faceplayer
# 30 "data/maps/MossdeepCity/scripts.pory"
	goto_if_set FLAG_RECEIVED_HM_DIVE, MossdeepCity_EventScript_SailorMagmaGone
# 31 "data/maps/MossdeepCity/scripts.pory"
	msgbox MossdeepCity_Text_MossdeepTargetedByMagma, MSGBOX_DEFAULT
# 32 "data/maps/MossdeepCity/scripts.pory"
	release
# 33 "data/maps/MossdeepCity/scripts.pory"
	end
# 34 "data/maps/MossdeepCity/scripts.pory"

# 35 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_EventScript_SailorMagmaGone::
# 36 "data/maps/MossdeepCity/scripts.pory"
	msgbox MossdeepCity_Text_FeelReliefOnLand, MSGBOX_DEFAULT
# 37 "data/maps/MossdeepCity/scripts.pory"
	release
# 38 "data/maps/MossdeepCity/scripts.pory"
	end
# 39 "data/maps/MossdeepCity/scripts.pory"

# 40 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_EventScript_NinjaBoy::
# 41 "data/maps/MossdeepCity/scripts.pory"
	msgbox MossdeepCity_Text_WailmerWatching, MSGBOX_NPC
# 42 "data/maps/MossdeepCity/scripts.pory"
	end
# 43 "data/maps/MossdeepCity/scripts.pory"

# 44 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_EventScript_ExpertM::
# 45 "data/maps/MossdeepCity/scripts.pory"
	msgbox MossdeepCity_Text_LifeNeedsSeaToLive, MSGBOX_NPC
# 46 "data/maps/MossdeepCity/scripts.pory"
	end
# 47 "data/maps/MossdeepCity/scripts.pory"

# 48 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_EventScript_Girl::
# 49 "data/maps/MossdeepCity/scripts.pory"
	msgbox MossdeepCity_Text_NiceIfWorldCoveredByFlowers, MSGBOX_NPC
# 50 "data/maps/MossdeepCity/scripts.pory"
	end
# 51 "data/maps/MossdeepCity/scripts.pory"

# 52 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_EventScript_Woman::
# 53 "data/maps/MossdeepCity/scripts.pory"
	msgbox MossdeepCity_Text_SpecialSpaceCenterRock, MSGBOX_NPC
# 54 "data/maps/MossdeepCity/scripts.pory"
	end
# 55 "data/maps/MossdeepCity/scripts.pory"

# 56 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_EventScript_WhiteRock::
# 57 "data/maps/MossdeepCity/scripts.pory"
	msgbox MossdeepCity_Text_ItsAWhiteRock, MSGBOX_SIGN
# 58 "data/maps/MossdeepCity/scripts.pory"
	end
# 59 "data/maps/MossdeepCity/scripts.pory"

# 60 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_EventScript_GymSign::
# 61 "data/maps/MossdeepCity/scripts.pory"
	msgbox MossdeepCity_Text_GymSign, MSGBOX_SIGN
# 62 "data/maps/MossdeepCity/scripts.pory"
	end
# 63 "data/maps/MossdeepCity/scripts.pory"

# 64 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_EventScript_CitySign::
# 65 "data/maps/MossdeepCity/scripts.pory"
	msgbox MossdeepCity_Text_CitySign, MSGBOX_SIGN
# 66 "data/maps/MossdeepCity/scripts.pory"
	end
# 67 "data/maps/MossdeepCity/scripts.pory"

# 68 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_EventScript_SpaceCenterSign::
# 69 "data/maps/MossdeepCity/scripts.pory"
	msgbox MossdeepCity_Text_SpaceCenterSign, MSGBOX_SIGN
# 70 "data/maps/MossdeepCity/scripts.pory"
	end
# 71 "data/maps/MossdeepCity/scripts.pory"

# 72 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_EventScript_VisitedMossdeep::
# 73 "data/maps/MossdeepCity/scripts.pory"
	setflag FLAG_VISITED_MOSSDEEP_CITY
# 74 "data/maps/MossdeepCity/scripts.pory"
	setvar VAR_TEMP_1, 1
# 75 "data/maps/MossdeepCity/scripts.pory"
	end
# 76 "data/maps/MossdeepCity/scripts.pory"

# 77 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_EventScript_TeamMagmaEnterSpaceCenter::
# 78 "data/maps/MossdeepCity/scripts.pory"
	lockall
# 79 "data/maps/MossdeepCity/scripts.pory"
	applymovement LOCALID_MOSSDEEP_MAXIE, MossdeepCity_Movement_MaxieGestureToSpaceCenter
# 80 "data/maps/MossdeepCity/scripts.pory"
	waitmovement 0
# 81 "data/maps/MossdeepCity/scripts.pory"
	applymovement LOCALID_MOSSDEEP_GRUNT_1, MossdeepCity_Movement_GruntFaceSpaceCenter
# 82 "data/maps/MossdeepCity/scripts.pory"
	applymovement LOCALID_MOSSDEEP_GRUNT_2, MossdeepCity_Movement_GruntFaceSpaceCenter
# 83 "data/maps/MossdeepCity/scripts.pory"
	applymovement LOCALID_MOSSDEEP_GRUNT_3, MossdeepCity_Movement_GruntFaceSpaceCenter
# 84 "data/maps/MossdeepCity/scripts.pory"
	applymovement LOCALID_MOSSDEEP_GRUNT_4, MossdeepCity_Movement_GruntFaceSpaceCenter
# 85 "data/maps/MossdeepCity/scripts.pory"
	waitmovement 0
# 86 "data/maps/MossdeepCity/scripts.pory"
	applymovement LOCALID_MOSSDEEP_MAXIE, MossdeepCity_Movement_MaxieEnterSpaceCenter
# 87 "data/maps/MossdeepCity/scripts.pory"
	applymovement LOCALID_MOSSDEEP_GRUNT_1, MossdeepCity_Movement_Grunt1EnterSpaceCenter
# 88 "data/maps/MossdeepCity/scripts.pory"
	applymovement LOCALID_MOSSDEEP_GRUNT_2, MossdeepCity_Movement_Grunt2EnterSpaceCenter
# 89 "data/maps/MossdeepCity/scripts.pory"
	applymovement LOCALID_MOSSDEEP_GRUNT_3, MossdeepCity_Movement_Grunt3EnterSpaceCenter
# 90 "data/maps/MossdeepCity/scripts.pory"
	applymovement LOCALID_MOSSDEEP_GRUNT_4, MossdeepCity_Movement_Grunt4EnterSpaceCenter
# 91 "data/maps/MossdeepCity/scripts.pory"
	waitmovement 0
# 92 "data/maps/MossdeepCity/scripts.pory"
	removeobject LOCALID_MOSSDEEP_MAXIE
# 93 "data/maps/MossdeepCity/scripts.pory"
	removeobject LOCALID_MOSSDEEP_GRUNT_1
# 94 "data/maps/MossdeepCity/scripts.pory"
	removeobject LOCALID_MOSSDEEP_GRUNT_2
# 95 "data/maps/MossdeepCity/scripts.pory"
	removeobject LOCALID_MOSSDEEP_GRUNT_3
# 96 "data/maps/MossdeepCity/scripts.pory"
	removeobject LOCALID_MOSSDEEP_GRUNT_4
# 97 "data/maps/MossdeepCity/scripts.pory"
	delay 30
# 98 "data/maps/MossdeepCity/scripts.pory"
	setvar VAR_MOSSDEEP_CITY_STATE, 2
# 99 "data/maps/MossdeepCity/scripts.pory"
	setflag FLAG_HIDE_MOSSDEEP_CITY_TEAM_MAGMA
# 100 "data/maps/MossdeepCity/scripts.pory"
	releaseall
# 101 "data/maps/MossdeepCity/scripts.pory"
	end
# 102 "data/maps/MossdeepCity/scripts.pory"

# 103 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_Movement_MaxieGestureToSpaceCenter:
# 104 "data/maps/MossdeepCity/scripts.pory"
	delay_16
# 105 "data/maps/MossdeepCity/scripts.pory"
	face_right
# 106 "data/maps/MossdeepCity/scripts.pory"
	delay_16
# 107 "data/maps/MossdeepCity/scripts.pory"
	delay_16
# 108 "data/maps/MossdeepCity/scripts.pory"
	delay_16
# 109 "data/maps/MossdeepCity/scripts.pory"
	delay_16
# 110 "data/maps/MossdeepCity/scripts.pory"
	face_left
# 111 "data/maps/MossdeepCity/scripts.pory"
	delay_16
# 112 "data/maps/MossdeepCity/scripts.pory"
	delay_16
# 113 "data/maps/MossdeepCity/scripts.pory"
	step_end
# 114 "data/maps/MossdeepCity/scripts.pory"

# 115 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_Movement_GruntFaceSpaceCenter:
# 116 "data/maps/MossdeepCity/scripts.pory"
	face_right
# 117 "data/maps/MossdeepCity/scripts.pory"
	delay_16
# 118 "data/maps/MossdeepCity/scripts.pory"
	delay_16
# 119 "data/maps/MossdeepCity/scripts.pory"
	delay_16
# 120 "data/maps/MossdeepCity/scripts.pory"
	step_end
# 121 "data/maps/MossdeepCity/scripts.pory"

# 122 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_Movement_MaxieEnterSpaceCenter:
# 123 "data/maps/MossdeepCity/scripts.pory"
	walk_down
# 124 "data/maps/MossdeepCity/scripts.pory"
	walk_right
# 125 "data/maps/MossdeepCity/scripts.pory"
	walk_right
# 126 "data/maps/MossdeepCity/scripts.pory"
	walk_down
# 127 "data/maps/MossdeepCity/scripts.pory"
	walk_down
# 128 "data/maps/MossdeepCity/scripts.pory"
	walk_down
# 129 "data/maps/MossdeepCity/scripts.pory"
	walk_right
# 130 "data/maps/MossdeepCity/scripts.pory"
	walk_right
# 131 "data/maps/MossdeepCity/scripts.pory"
	walk_right
# 132 "data/maps/MossdeepCity/scripts.pory"
	walk_right
# 133 "data/maps/MossdeepCity/scripts.pory"
	walk_right
# 134 "data/maps/MossdeepCity/scripts.pory"
	walk_right
# 135 "data/maps/MossdeepCity/scripts.pory"
	walk_right
# 136 "data/maps/MossdeepCity/scripts.pory"
	step_end
# 137 "data/maps/MossdeepCity/scripts.pory"

# 138 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_Movement_Grunt1EnterSpaceCenter:
# 139 "data/maps/MossdeepCity/scripts.pory"
	delay_16
# 140 "data/maps/MossdeepCity/scripts.pory"
	delay_8
# 141 "data/maps/MossdeepCity/scripts.pory"
	walk_down
# 142 "data/maps/MossdeepCity/scripts.pory"
	walk_down
# 143 "data/maps/MossdeepCity/scripts.pory"
	walk_down
# 144 "data/maps/MossdeepCity/scripts.pory"
	walk_right
# 145 "data/maps/MossdeepCity/scripts.pory"
	walk_right
# 146 "data/maps/MossdeepCity/scripts.pory"
	walk_right
# 147 "data/maps/MossdeepCity/scripts.pory"
	walk_down
# 148 "data/maps/MossdeepCity/scripts.pory"
	walk_down
# 149 "data/maps/MossdeepCity/scripts.pory"
	walk_down
# 150 "data/maps/MossdeepCity/scripts.pory"
	walk_right
# 151 "data/maps/MossdeepCity/scripts.pory"
	walk_right
# 152 "data/maps/MossdeepCity/scripts.pory"
	walk_right
# 153 "data/maps/MossdeepCity/scripts.pory"
	walk_right
# 154 "data/maps/MossdeepCity/scripts.pory"
	walk_right
# 155 "data/maps/MossdeepCity/scripts.pory"
	walk_right
# 156 "data/maps/MossdeepCity/scripts.pory"
	walk_right
# 157 "data/maps/MossdeepCity/scripts.pory"
	step_end
# 158 "data/maps/MossdeepCity/scripts.pory"

# 159 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_Movement_Grunt2EnterSpaceCenter:
# 160 "data/maps/MossdeepCity/scripts.pory"
	delay_16
# 161 "data/maps/MossdeepCity/scripts.pory"
	delay_8
# 162 "data/maps/MossdeepCity/scripts.pory"
	walk_down
# 163 "data/maps/MossdeepCity/scripts.pory"
	walk_down
# 164 "data/maps/MossdeepCity/scripts.pory"
	walk_right
# 165 "data/maps/MossdeepCity/scripts.pory"
	walk_right
# 166 "data/maps/MossdeepCity/scripts.pory"
	walk_right
# 167 "data/maps/MossdeepCity/scripts.pory"
	walk_down
# 168 "data/maps/MossdeepCity/scripts.pory"
	walk_down
# 169 "data/maps/MossdeepCity/scripts.pory"
	walk_down
# 170 "data/maps/MossdeepCity/scripts.pory"
	walk_right
# 171 "data/maps/MossdeepCity/scripts.pory"
	walk_right
# 172 "data/maps/MossdeepCity/scripts.pory"
	walk_right
# 173 "data/maps/MossdeepCity/scripts.pory"
	walk_right
# 174 "data/maps/MossdeepCity/scripts.pory"
	walk_right
# 175 "data/maps/MossdeepCity/scripts.pory"
	walk_right
# 176 "data/maps/MossdeepCity/scripts.pory"
	walk_right
# 177 "data/maps/MossdeepCity/scripts.pory"
	step_end
# 178 "data/maps/MossdeepCity/scripts.pory"

# 179 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_Movement_Grunt3EnterSpaceCenter:
# 180 "data/maps/MossdeepCity/scripts.pory"
	delay_16
# 181 "data/maps/MossdeepCity/scripts.pory"
	delay_8
# 182 "data/maps/MossdeepCity/scripts.pory"
	walk_down
# 183 "data/maps/MossdeepCity/scripts.pory"
	walk_right
# 184 "data/maps/MossdeepCity/scripts.pory"
	walk_right
# 185 "data/maps/MossdeepCity/scripts.pory"
	walk_right
# 186 "data/maps/MossdeepCity/scripts.pory"
	walk_down
# 187 "data/maps/MossdeepCity/scripts.pory"
	walk_down
# 188 "data/maps/MossdeepCity/scripts.pory"
	walk_down
# 189 "data/maps/MossdeepCity/scripts.pory"
	walk_right
# 190 "data/maps/MossdeepCity/scripts.pory"
	walk_right
# 191 "data/maps/MossdeepCity/scripts.pory"
	walk_right
# 192 "data/maps/MossdeepCity/scripts.pory"
	walk_right
# 193 "data/maps/MossdeepCity/scripts.pory"
	walk_right
# 194 "data/maps/MossdeepCity/scripts.pory"
	walk_right
# 195 "data/maps/MossdeepCity/scripts.pory"
	walk_right
# 196 "data/maps/MossdeepCity/scripts.pory"
	step_end
# 197 "data/maps/MossdeepCity/scripts.pory"

# 198 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_Movement_Grunt4EnterSpaceCenter:
# 199 "data/maps/MossdeepCity/scripts.pory"
	delay_16
# 200 "data/maps/MossdeepCity/scripts.pory"
	delay_8
# 201 "data/maps/MossdeepCity/scripts.pory"
	walk_right
# 202 "data/maps/MossdeepCity/scripts.pory"
	walk_right
# 203 "data/maps/MossdeepCity/scripts.pory"
	walk_right
# 204 "data/maps/MossdeepCity/scripts.pory"
	walk_down
# 205 "data/maps/MossdeepCity/scripts.pory"
	walk_down
# 206 "data/maps/MossdeepCity/scripts.pory"
	walk_down
# 207 "data/maps/MossdeepCity/scripts.pory"
	walk_right
# 208 "data/maps/MossdeepCity/scripts.pory"
	walk_right
# 209 "data/maps/MossdeepCity/scripts.pory"
	walk_right
# 210 "data/maps/MossdeepCity/scripts.pory"
	walk_right
# 211 "data/maps/MossdeepCity/scripts.pory"
	walk_right
# 212 "data/maps/MossdeepCity/scripts.pory"
	walk_right
# 213 "data/maps/MossdeepCity/scripts.pory"
	walk_right
# 214 "data/maps/MossdeepCity/scripts.pory"
	step_end
# 215 "data/maps/MossdeepCity/scripts.pory"

# 216 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_EventScript_Man::
# 217 "data/maps/MossdeepCity/scripts.pory"
	lock
# 218 "data/maps/MossdeepCity/scripts.pory"
	faceplayer
# 219 "data/maps/MossdeepCity/scripts.pory"
	msgbox MossdeepCity_Text_SurfExhilarating, MSGBOX_DEFAULT
# 220 "data/maps/MossdeepCity/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
# 221 "data/maps/MossdeepCity/scripts.pory"
	waitmovement 0
# 222 "data/maps/MossdeepCity/scripts.pory"
	release
# 223 "data/maps/MossdeepCity/scripts.pory"
	end
# 224 "data/maps/MossdeepCity/scripts.pory"

# 225 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_EventScript_KingsRockBoy::
# 226 "data/maps/MossdeepCity/scripts.pory"
	lock
# 227 "data/maps/MossdeepCity/scripts.pory"
	faceplayer
# 228 "data/maps/MossdeepCity/scripts.pory"
	goto_if_set FLAG_RECEIVED_KINGS_ROCK, MossdeepCity_EventScript_ReceivedKingsRock
# 229 "data/maps/MossdeepCity/scripts.pory"
	msgbox MossdeepCity_Text_WantKingsRockStevenGaveMe, MSGBOX_YESNO
# 230 "data/maps/MossdeepCity/scripts.pory"
	goto_if_eq VAR_RESULT, NO, MossdeepCity_EventScript_DeclineKingsRock
# 231 "data/maps/MossdeepCity/scripts.pory"
	msgbox MossdeepCity_Text_YouCanKeepIt, MSGBOX_DEFAULT
# 232 "data/maps/MossdeepCity/scripts.pory"
	giveitem ITEM_KINGS_ROCK
# 233 "data/maps/MossdeepCity/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
# 234 "data/maps/MossdeepCity/scripts.pory"
	setflag FLAG_RECEIVED_KINGS_ROCK
# 235 "data/maps/MossdeepCity/scripts.pory"
	release
# 236 "data/maps/MossdeepCity/scripts.pory"
	end
# 237 "data/maps/MossdeepCity/scripts.pory"

# 238 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_EventScript_ReceivedKingsRock::
# 239 "data/maps/MossdeepCity/scripts.pory"
	msgbox MossdeepCity_Text_StevensHouseOverThere, MSGBOX_DEFAULT
# 240 "data/maps/MossdeepCity/scripts.pory"
	release
# 241 "data/maps/MossdeepCity/scripts.pory"
	end
# 242 "data/maps/MossdeepCity/scripts.pory"

# 243 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_EventScript_DeclineKingsRock::
# 244 "data/maps/MossdeepCity/scripts.pory"
	msgbox MossdeepCity_Text_WhatToDoWithWeirdRock, MSGBOX_DEFAULT
# 245 "data/maps/MossdeepCity/scripts.pory"
	release
# 246 "data/maps/MossdeepCity/scripts.pory"
	end
# 247 "data/maps/MossdeepCity/scripts.pory"

# 248 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_EventScript_BlackBelt::
# 249 "data/maps/MossdeepCity/scripts.pory"
	msgbox MossdeepCity_Text_SootopolisNewGymLeader, MSGBOX_NPC
# 250 "data/maps/MossdeepCity/scripts.pory"
	end
# 251 "data/maps/MossdeepCity/scripts.pory"

# 252 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_EventScript_Scott::
# 253 "data/maps/MossdeepCity/scripts.pory"
	lock
# 254 "data/maps/MossdeepCity/scripts.pory"
	faceplayer
# 255 "data/maps/MossdeepCity/scripts.pory"
	msgbox MossdeepCity_Text_ScottSomethingWrongWithTown, MSGBOX_DEFAULT
# 256 "data/maps/MossdeepCity/scripts.pory"
	closemessage
# 257 "data/maps/MossdeepCity/scripts.pory"
	call_if_eq VAR_FACING, DIR_NORTH, MossdeepCity_EventScript_ScottExitNorth
# 258 "data/maps/MossdeepCity/scripts.pory"
	call_if_eq VAR_FACING, DIR_EAST, MossdeepCity_EventScript_ScottExitEast
# 259 "data/maps/MossdeepCity/scripts.pory"
	addvar VAR_SCOTT_STATE, 1
# 260 "data/maps/MossdeepCity/scripts.pory"
	removeobject LOCALID_MOSSDEEP_SCOTT
# 261 "data/maps/MossdeepCity/scripts.pory"
	release
# 262 "data/maps/MossdeepCity/scripts.pory"
	end
# 263 "data/maps/MossdeepCity/scripts.pory"

# 264 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_EventScript_ScottExitNorth::
# 265 "data/maps/MossdeepCity/scripts.pory"
	applymovement LOCALID_PLAYER, MossdeepCity_Movement_PlayerWatchScottExit
# 266 "data/maps/MossdeepCity/scripts.pory"
	applymovement LOCALID_MOSSDEEP_SCOTT, MossdeepCity_Movement_ScottExitNorth
# 267 "data/maps/MossdeepCity/scripts.pory"
	waitmovement 0
# 268 "data/maps/MossdeepCity/scripts.pory"
	return
# 269 "data/maps/MossdeepCity/scripts.pory"

# 270 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_EventScript_ScottExitEast::
# 271 "data/maps/MossdeepCity/scripts.pory"
	applymovement LOCALID_PLAYER, MossdeepCity_Movement_PlayerWatchScottExit
# 272 "data/maps/MossdeepCity/scripts.pory"
	applymovement LOCALID_MOSSDEEP_SCOTT, MossdeepCity_Movement_ScottExitEast
# 273 "data/maps/MossdeepCity/scripts.pory"
	waitmovement 0
# 274 "data/maps/MossdeepCity/scripts.pory"
	return
# 275 "data/maps/MossdeepCity/scripts.pory"

# 276 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_Movement_PlayerWatchScottExit:
# 277 "data/maps/MossdeepCity/scripts.pory"
	delay_16
# 278 "data/maps/MossdeepCity/scripts.pory"
	delay_16
# 279 "data/maps/MossdeepCity/scripts.pory"
	walk_in_place_faster_left
# 280 "data/maps/MossdeepCity/scripts.pory"
	step_end
# 281 "data/maps/MossdeepCity/scripts.pory"

# 282 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_Movement_ScottExitNorth:
# 283 "data/maps/MossdeepCity/scripts.pory"
	walk_left
# 284 "data/maps/MossdeepCity/scripts.pory"
	walk_left
# 285 "data/maps/MossdeepCity/scripts.pory"
	walk_left
# 286 "data/maps/MossdeepCity/scripts.pory"
	walk_left
# 287 "data/maps/MossdeepCity/scripts.pory"
	walk_left
# 288 "data/maps/MossdeepCity/scripts.pory"
	walk_left
# 289 "data/maps/MossdeepCity/scripts.pory"
	walk_left
# 290 "data/maps/MossdeepCity/scripts.pory"
	walk_left
# 291 "data/maps/MossdeepCity/scripts.pory"
	walk_left
# 292 "data/maps/MossdeepCity/scripts.pory"
	step_end
# 293 "data/maps/MossdeepCity/scripts.pory"

# 294 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_Movement_ScottExitEast:
# 295 "data/maps/MossdeepCity/scripts.pory"
	walk_down
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
	walk_left
# 302 "data/maps/MossdeepCity/scripts.pory"
	walk_left
# 303 "data/maps/MossdeepCity/scripts.pory"
	walk_left
# 304 "data/maps/MossdeepCity/scripts.pory"
	walk_left
# 305 "data/maps/MossdeepCity/scripts.pory"
	step_end
# 306 "data/maps/MossdeepCity/scripts.pory"

# 307 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_Text_WantKingsRockStevenGaveMe:
# 308 "data/maps/MossdeepCity/scripts.pory"
	.string "I got this from STEVEN, but I don't\n"
# 309 "data/maps/MossdeepCity/scripts.pory"
	.string "know what it's good for.\p"
# 310 "data/maps/MossdeepCity/scripts.pory"
	.string "I think it's called KING'S ROCK.\n"
# 311 "data/maps/MossdeepCity/scripts.pory"
	.string "Do you want it?$"
# 312 "data/maps/MossdeepCity/scripts.pory"

# 313 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_Text_YouCanKeepIt:
# 314 "data/maps/MossdeepCity/scripts.pory"
	.string "Why would you want it?\n"
# 315 "data/maps/MossdeepCity/scripts.pory"
	.string "You're weird.\p"
# 316 "data/maps/MossdeepCity/scripts.pory"
	.string "You can keep it, but keep it a secret\n"
# 317 "data/maps/MossdeepCity/scripts.pory"
	.string "from STEVEN.$"
# 318 "data/maps/MossdeepCity/scripts.pory"

# 319 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_Text_StevensHouseOverThere:
# 320 "data/maps/MossdeepCity/scripts.pory"
	.string "STEVEN's house is right over there!$"
# 321 "data/maps/MossdeepCity/scripts.pory"

# 322 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_Text_WhatToDoWithWeirdRock:
# 323 "data/maps/MossdeepCity/scripts.pory"
	.string "Yeah, you think so, too! What are you\n"
# 324 "data/maps/MossdeepCity/scripts.pory"
	.string "supposed to do with some weird rock?$"
# 325 "data/maps/MossdeepCity/scripts.pory"

# 326 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_Text_WailmerWatching:
# 327 "data/maps/MossdeepCity/scripts.pory"
	.string "Around MOSSDEEP, you can see wild\n"
# 328 "data/maps/MossdeepCity/scripts.pory"
	.string "WAILMER.\p"
# 329 "data/maps/MossdeepCity/scripts.pory"
	.string "It's called, uh…\n"
# 330 "data/maps/MossdeepCity/scripts.pory"
	.string "What was it now…\p"
# 331 "data/maps/MossdeepCity/scripts.pory"
	.string "WAI, WAI, WAI…\p"
# 332 "data/maps/MossdeepCity/scripts.pory"
	.string "WAILMER watching!$"
# 333 "data/maps/MossdeepCity/scripts.pory"

# 334 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_Text_SpaceCenterReceivedLetter:
# 335 "data/maps/MossdeepCity/scripts.pory"
	.string "The island's SPACE CENTER has been\n"
# 336 "data/maps/MossdeepCity/scripts.pory"
	.string "launching huge rockets.\p"
# 337 "data/maps/MossdeepCity/scripts.pory"
	.string "There's been some kind of an uproar\n"
# 338 "data/maps/MossdeepCity/scripts.pory"
	.string "over a letter they received recently.$"
# 339 "data/maps/MossdeepCity/scripts.pory"

# 340 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_Text_SpaceCenterLaunchingRockets:
# 341 "data/maps/MossdeepCity/scripts.pory"
	.string "The island's SPACE CENTER has been\n"
# 342 "data/maps/MossdeepCity/scripts.pory"
	.string "launching huge rockets.$"
# 343 "data/maps/MossdeepCity/scripts.pory"

# 344 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_Text_MossdeepTargetedByMagma:
# 345 "data/maps/MossdeepCity/scripts.pory"
	.string "I heard from a SAILOR buddy that\n"
# 346 "data/maps/MossdeepCity/scripts.pory"
	.string "TEAM AQUA set up shop in LILYCOVE.\p"
# 347 "data/maps/MossdeepCity/scripts.pory"
	.string "I also heard that someone came along\n"
# 348 "data/maps/MossdeepCity/scripts.pory"
	.string "and wiped the floor with them!\p"
# 349 "data/maps/MossdeepCity/scripts.pory"
	.string "But MOSSDEEP here's been targeted\n"
# 350 "data/maps/MossdeepCity/scripts.pory"
	.string "by that TEAM MAGMA.\p"
# 351 "data/maps/MossdeepCity/scripts.pory"
	.string "If you want to know what they're up to,\n"
# 352 "data/maps/MossdeepCity/scripts.pory"
	.string "go visit the SPACE CENTER.$"
# 353 "data/maps/MossdeepCity/scripts.pory"

# 354 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_Text_FeelReliefOnLand:
# 355 "data/maps/MossdeepCity/scripts.pory"
	.string "I'm a SAILOR, so the sea's obviously\n"
# 356 "data/maps/MossdeepCity/scripts.pory"
	.string "more important to me.\p"
# 357 "data/maps/MossdeepCity/scripts.pory"
	.string "But you know? When I get back on land\n"
# 358 "data/maps/MossdeepCity/scripts.pory"
	.string "after a long voyage, I do feel relief!$"
# 359 "data/maps/MossdeepCity/scripts.pory"

# 360 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_Text_NiceIfWorldCoveredByFlowers:
# 361 "data/maps/MossdeepCity/scripts.pory"
	.string "Wouldn't it be nice?\p"
# 362 "data/maps/MossdeepCity/scripts.pory"
	.string "If the whole world was covered in\n"
# 363 "data/maps/MossdeepCity/scripts.pory"
	.string "plants and flowers like this island?$"
# 364 "data/maps/MossdeepCity/scripts.pory"

# 365 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_Text_LifeNeedsSeaToLive:
# 366 "data/maps/MossdeepCity/scripts.pory"
	.string "All life needs the sea to live, even\n"
# 367 "data/maps/MossdeepCity/scripts.pory"
	.string "though it makes its home on the land.\p"
# 368 "data/maps/MossdeepCity/scripts.pory"
	.string "Life, having run its course, becomes\n"
# 369 "data/maps/MossdeepCity/scripts.pory"
	.string "soil and returns to the land.\p"
# 370 "data/maps/MossdeepCity/scripts.pory"
	.string "And the sea is always connected to\n"
# 371 "data/maps/MossdeepCity/scripts.pory"
	.string "the land.\p"
# 372 "data/maps/MossdeepCity/scripts.pory"
	.string "Yes, like the very shoreline here.$"
# 373 "data/maps/MossdeepCity/scripts.pory"

# 374 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_Text_SurfExhilarating:
# 375 "data/maps/MossdeepCity/scripts.pory"
	.string "A voyage on a ship is fine.\p"
# 376 "data/maps/MossdeepCity/scripts.pory"
	.string "But crossing the sea with POKéMON\n"
# 377 "data/maps/MossdeepCity/scripts.pory"
	.string "using SURF…\p"
# 378 "data/maps/MossdeepCity/scripts.pory"
	.string "Now that's an exhilarating trip!\n"
# 379 "data/maps/MossdeepCity/scripts.pory"
	.string "Wouldn't you agree, youngster?$"
# 380 "data/maps/MossdeepCity/scripts.pory"

# 381 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_Text_SpecialSpaceCenterRock:
# 382 "data/maps/MossdeepCity/scripts.pory"
	.string "This rock has a special meaning to\n"
# 383 "data/maps/MossdeepCity/scripts.pory"
	.string "the people at the SPACE CENTER.\p"
# 384 "data/maps/MossdeepCity/scripts.pory"
	.string "They put it here as their wish for\n"
# 385 "data/maps/MossdeepCity/scripts.pory"
	.string "their rockets to fly safely.\p"
# 386 "data/maps/MossdeepCity/scripts.pory"
	.string "When you make a wish, what do you use?\n"
# 387 "data/maps/MossdeepCity/scripts.pory"
	.string "Do you wish upon a star?\p"
# 388 "data/maps/MossdeepCity/scripts.pory"
	.string "I use a wish tag to make it happen.\n"
# 389 "data/maps/MossdeepCity/scripts.pory"
	.string "That's what I do.$"
# 390 "data/maps/MossdeepCity/scripts.pory"

# 391 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_Text_ItsAWhiteRock:
# 392 "data/maps/MossdeepCity/scripts.pory"
	.string "It's a white rock.$"
# 393 "data/maps/MossdeepCity/scripts.pory"

# 394 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_Text_GymSign:
# 395 "data/maps/MossdeepCity/scripts.pory"
	.string "MOSSDEEP CITY POKéMON GYM\n"
# 396 "data/maps/MossdeepCity/scripts.pory"
	.string "LEADERS: LIZA & TATE\p"
# 397 "data/maps/MossdeepCity/scripts.pory"
	.string "“The mystic combination!”$"
# 398 "data/maps/MossdeepCity/scripts.pory"

# 399 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_Text_CitySign:
# 400 "data/maps/MossdeepCity/scripts.pory"
	.string "MOSSDEEP CITY\n"
# 401 "data/maps/MossdeepCity/scripts.pory"
	.string "“Our slogan: Cherish POKéMON!”$"
# 402 "data/maps/MossdeepCity/scripts.pory"

# 403 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_Text_SpaceCenterSign:
# 404 "data/maps/MossdeepCity/scripts.pory"
	.string "MOSSDEEP SPACE CENTER\n"
# 405 "data/maps/MossdeepCity/scripts.pory"
	.string "“The closest place to space.”$"
# 406 "data/maps/MossdeepCity/scripts.pory"

# 407 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_Text_ScottSomethingWrongWithTown:
# 408 "data/maps/MossdeepCity/scripts.pory"
	.string "SCOTT: {PLAYER}{KUN}, feeling good?\n"
# 409 "data/maps/MossdeepCity/scripts.pory"
	.string "I'm doing great!\p"
# 410 "data/maps/MossdeepCity/scripts.pory"
	.string "I'd heard MOSSDEEP's GYM LEADER is\n"
# 411 "data/maps/MossdeepCity/scripts.pory"
	.string "pretty strong, so I decided to come\l"
# 412 "data/maps/MossdeepCity/scripts.pory"
	.string "take a look-see for myself.\p"
# 413 "data/maps/MossdeepCity/scripts.pory"
	.string "But there's something wrong about\n"
# 414 "data/maps/MossdeepCity/scripts.pory"
	.string "this town.\p"
# 415 "data/maps/MossdeepCity/scripts.pory"
	.string "People are going on about a warning\n"
# 416 "data/maps/MossdeepCity/scripts.pory"
	.string "letter and the SPACE CENTER…\p"
# 417 "data/maps/MossdeepCity/scripts.pory"
	.string "I don't think it concerns me in any\n"
# 418 "data/maps/MossdeepCity/scripts.pory"
	.string "way, though.$"
# 419 "data/maps/MossdeepCity/scripts.pory"

# 420 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_Text_SootopolisNewGymLeader:
# 421 "data/maps/MossdeepCity/scripts.pory"
	.string "Ahh… It feels great letting the waves\n"
# 422 "data/maps/MossdeepCity/scripts.pory"
	.string "wash over my feet…\p"
# 423 "data/maps/MossdeepCity/scripts.pory"
	.string "Speaking of the waves, you know that\n"
# 424 "data/maps/MossdeepCity/scripts.pory"
	.string "island city SOOTOPOLIS?\p"
# 425 "data/maps/MossdeepCity/scripts.pory"
	.string "I think the GYM there had a new\n"
# 426 "data/maps/MossdeepCity/scripts.pory"
	.string "LEADER come in.\p"
# 427 "data/maps/MossdeepCity/scripts.pory"
	.string "People tell me the new LEADER once\n"
# 428 "data/maps/MossdeepCity/scripts.pory"
	.string "mentored WALLACE.$"
