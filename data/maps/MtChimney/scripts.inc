# 1 "data/maps/MtChimney/scripts.pory"

# 2 "data/maps/MtChimney/scripts.pory"
.set LOCALID_ARCHIE, 1
# 3 "data/maps/MtChimney/scripts.pory"
.set LOCALID_MAXIE, 2
# 4 "data/maps/MtChimney/scripts.pory"
.set LOCALID_TABITHA, 3
# 5 "data/maps/MtChimney/scripts.pory"
.set LOCALID_MAGMA_GRUNT_2, 22
# 6 "data/maps/MtChimney/scripts.pory"
.set LOCALID_MAGMA_GRUNT_1, 29
# 7 "data/maps/MtChimney/scripts.pory"

# 8 "data/maps/MtChimney/scripts.pory"

# 9 "data/maps/MtChimney/scripts.pory"
MtChimney_MapScripts::
# 10 "data/maps/MtChimney/scripts.pory"
	map_script MAP_SCRIPT_ON_RESUME, MtChimney_OnResume
# 11 "data/maps/MtChimney/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, MtChimney_OnTransition
# 12 "data/maps/MtChimney/scripts.pory"
	.byte 0
# 13 "data/maps/MtChimney/scripts.pory"

# 14 "data/maps/MtChimney/scripts.pory"
MtChimney_OnTransition:
# 15 "data/maps/MtChimney/scripts.pory"
	setvar VAR_JAGGED_PASS_ASH_WEATHER, 1
# 16 "data/maps/MtChimney/scripts.pory"
	end
# 17 "data/maps/MtChimney/scripts.pory"

# 18 "data/maps/MtChimney/scripts.pory"
MtChimney_OnResume:
# 19 "data/maps/MtChimney/scripts.pory"
	setstepcallback STEP_CB_ASH
# 20 "data/maps/MtChimney/scripts.pory"
	end
# 21 "data/maps/MtChimney/scripts.pory"

# 22 "data/maps/MtChimney/scripts.pory"
MtChimney_EventScript_Archie::
# 23 "data/maps/MtChimney/scripts.pory"
	lock
# 24 "data/maps/MtChimney/scripts.pory"
	faceplayer
# 25 "data/maps/MtChimney/scripts.pory"
	call_if_unset FLAG_EVIL_LEADER_PLEASE_STOP, MtChimney_EventScript_ArchieGoStopTeamMagma
# 26 "data/maps/MtChimney/scripts.pory"
	call_if_set FLAG_EVIL_LEADER_PLEASE_STOP, MtChimney_EventScript_ArchieBusyFighting
# 27 "data/maps/MtChimney/scripts.pory"
	closemessage
# 28 "data/maps/MtChimney/scripts.pory"
	applymovement LOCALID_ARCHIE, Common_Movement_FaceOriginalDirection
# 29 "data/maps/MtChimney/scripts.pory"
	waitmovement 0
# 30 "data/maps/MtChimney/scripts.pory"
	setflag FLAG_EVIL_LEADER_PLEASE_STOP
# 31 "data/maps/MtChimney/scripts.pory"
	release
# 32 "data/maps/MtChimney/scripts.pory"
	end
# 33 "data/maps/MtChimney/scripts.pory"

# 34 "data/maps/MtChimney/scripts.pory"
MtChimney_EventScript_ArchieGoStopTeamMagma::
# 35 "data/maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_ArchieGoStopTeamMagma, MSGBOX_DEFAULT
# 36 "data/maps/MtChimney/scripts.pory"
	return
# 37 "data/maps/MtChimney/scripts.pory"

# 38 "data/maps/MtChimney/scripts.pory"
MtChimney_EventScript_ArchieBusyFighting::
# 39 "data/maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_ArchieIHaveMyHandsFull, MSGBOX_DEFAULT
# 40 "data/maps/MtChimney/scripts.pory"
	return
# 41 "data/maps/MtChimney/scripts.pory"

# 42 "data/maps/MtChimney/scripts.pory"
MtChimney_EventScript_Maxie::
# 43 "data/maps/MtChimney/scripts.pory"
	lockall
# 44 "data/maps/MtChimney/scripts.pory"
	playbgm MUS_ENCOUNTER_MAGMA, FALSE
# 45 "data/maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_MeteoriteWillActivateVolcano, MSGBOX_DEFAULT
# 46 "data/maps/MtChimney/scripts.pory"
	applymovement LOCALID_MAXIE, Common_Movement_FacePlayer
# 47 "data/maps/MtChimney/scripts.pory"
	waitmovement 0
# 48 "data/maps/MtChimney/scripts.pory"
	playse SE_PIN
# 49 "data/maps/MtChimney/scripts.pory"
	applymovement LOCALID_MAXIE, Common_Movement_ExclamationMark
# 50 "data/maps/MtChimney/scripts.pory"
	waitmovement 0
# 51 "data/maps/MtChimney/scripts.pory"
	applymovement LOCALID_MAXIE, Common_Movement_Delay48
# 52 "data/maps/MtChimney/scripts.pory"
	waitmovement 0
# 53 "data/maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_MaxieIntro, MSGBOX_DEFAULT
# 54 "data/maps/MtChimney/scripts.pory"
	trainerbattle_no_intro TRAINER_MAXIE_MT_CHIMNEY, MtChimney_Text_MaxieDefeat
# 55 "data/maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_MaxieYouHaventSeenLastOfMagma, MSGBOX_DEFAULT
# 56 "data/maps/MtChimney/scripts.pory"
	closemessage
# 57 "data/maps/MtChimney/scripts.pory"
	delay 30
# 58 "data/maps/MtChimney/scripts.pory"
	fadescreen FADE_TO_BLACK
# 59 "data/maps/MtChimney/scripts.pory"
	removeobject LOCALID_MAXIE
# 60 "data/maps/MtChimney/scripts.pory"
	removeobject LOCALID_MAGMA_GRUNT_1
# 61 "data/maps/MtChimney/scripts.pory"
	removeobject LOCALID_TABITHA
# 62 "data/maps/MtChimney/scripts.pory"
	removeobject LOCALID_MAGMA_GRUNT_2
# 63 "data/maps/MtChimney/scripts.pory"
	setflag FLAG_HIDE_MT_CHIMNEY_TEAM_MAGMA
# 64 "data/maps/MtChimney/scripts.pory"
	fadescreen FADE_FROM_BLACK
# 65 "data/maps/MtChimney/scripts.pory"
	setobjectxyperm LOCALID_ARCHIE, 10, 12
# 66 "data/maps/MtChimney/scripts.pory"
	addobject LOCALID_ARCHIE
# 67 "data/maps/MtChimney/scripts.pory"
	call_if_eq VAR_FACING, DIR_EAST, MtChimney_EventScript_ArchieApproachPlayerEast
# 68 "data/maps/MtChimney/scripts.pory"
	call_if_eq VAR_FACING, DIR_NORTH, MtChimney_EventScript_ArchieApproachPlayerNorth
# 69 "data/maps/MtChimney/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
# 70 "data/maps/MtChimney/scripts.pory"
	waitmovement 0
# 71 "data/maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_ArchieThankYou, MSGBOX_DEFAULT
# 72 "data/maps/MtChimney/scripts.pory"
	closemessage
# 73 "data/maps/MtChimney/scripts.pory"
	call_if_eq VAR_FACING, DIR_EAST, MtChimney_EventScript_ArchieExitEast
# 74 "data/maps/MtChimney/scripts.pory"
	call_if_eq VAR_FACING, DIR_NORTH, MtChimney_EventScript_ArchieExitNorth
# 75 "data/maps/MtChimney/scripts.pory"
	removeobject LOCALID_ARCHIE
# 76 "data/maps/MtChimney/scripts.pory"
	setflag FLAG_HIDE_MT_CHIMNEY_TEAM_AQUA
# 77 "data/maps/MtChimney/scripts.pory"
	setflag FLAG_DEFEATED_EVIL_TEAM_MT_CHIMNEY
# 78 "data/maps/MtChimney/scripts.pory"
	clearflag FLAG_HIDE_FALLARBOR_HOUSE_PROF_COZMO
# 79 "data/maps/MtChimney/scripts.pory"
	setflag FLAG_HIDE_METEOR_FALLS_1F_1R_COZMO
# 80 "data/maps/MtChimney/scripts.pory"
	clearflag FLAG_HIDE_MT_CHIMNEY_LAVA_COOKIE_LADY
# 81 "data/maps/MtChimney/scripts.pory"
	releaseall
# 82 "data/maps/MtChimney/scripts.pory"
	end
# 83 "data/maps/MtChimney/scripts.pory"

# 84 "data/maps/MtChimney/scripts.pory"
MtChimney_EventScript_ArchieApproachPlayerEast::
# 85 "data/maps/MtChimney/scripts.pory"
	applymovement LOCALID_ARCHIE, MtChimney_Movement_ArchieApproachPlayerEast
# 86 "data/maps/MtChimney/scripts.pory"
	waitmovement 0
# 87 "data/maps/MtChimney/scripts.pory"
	return
# 88 "data/maps/MtChimney/scripts.pory"

# 89 "data/maps/MtChimney/scripts.pory"
MtChimney_EventScript_ArchieApproachPlayerNorth::
# 90 "data/maps/MtChimney/scripts.pory"
	applymovement LOCALID_ARCHIE, MtChimney_Movement_ArchieApproachPlayerNorth
# 91 "data/maps/MtChimney/scripts.pory"
	waitmovement 0
# 92 "data/maps/MtChimney/scripts.pory"
	return
# 93 "data/maps/MtChimney/scripts.pory"

# 94 "data/maps/MtChimney/scripts.pory"
MtChimney_EventScript_ArchieExitEast::
# 95 "data/maps/MtChimney/scripts.pory"
	applymovement LOCALID_ARCHIE, MtChimney_Movement_ArchieExitEast
# 96 "data/maps/MtChimney/scripts.pory"
	waitmovement 0
# 97 "data/maps/MtChimney/scripts.pory"
	return
# 98 "data/maps/MtChimney/scripts.pory"

# 99 "data/maps/MtChimney/scripts.pory"
MtChimney_EventScript_ArchieExitNorth::
# 100 "data/maps/MtChimney/scripts.pory"
	applymovement LOCALID_ARCHIE, MtChimney_Movement_ArchieExitNorth
# 101 "data/maps/MtChimney/scripts.pory"
	waitmovement 0
# 102 "data/maps/MtChimney/scripts.pory"
	return
# 103 "data/maps/MtChimney/scripts.pory"

# 104 "data/maps/MtChimney/scripts.pory"
MtChimney_EventScript_LavaCookieLady::
# 105 "data/maps/MtChimney/scripts.pory"
	lock
# 106 "data/maps/MtChimney/scripts.pory"
	faceplayer
# 107 "data/maps/MtChimney/scripts.pory"
	showmoneybox 0, 0
# 108 "data/maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_LavaCookiesJust200, MSGBOX_YESNO
# 109 "data/maps/MtChimney/scripts.pory"
	goto_if_eq VAR_RESULT, NO, MtChimney_EventScript_DeclineLavaCookie
# 110 "data/maps/MtChimney/scripts.pory"
	checkmoney 200
# 111 "data/maps/MtChimney/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, MtChimney_EventScript_NotEnoughMoney
# 112 "data/maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_ThankYouDear, MSGBOX_DEFAULT
# 113 "data/maps/MtChimney/scripts.pory"
	checkitemspace ITEM_LAVA_COOKIE
# 114 "data/maps/MtChimney/scripts.pory"
	call_if_eq VAR_RESULT, TRUE, MtChimney_EventScript_RemoveMoney
# 115 "data/maps/MtChimney/scripts.pory"
.if OW_SHOW_ITEM_DESCRIPTIONS == OW_ITEM_DESCRIPTIONS_OFF
# 116 "data/maps/MtChimney/scripts.pory"
	giveitem ITEM_LAVA_COOKIE
# 117 "data/maps/MtChimney/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, MtChimney_EventScript_BagIsFull
# 118 "data/maps/MtChimney/scripts.pory"
	hidemoneybox
# 119 "data/maps/MtChimney/scripts.pory"
	release
# 120 "data/maps/MtChimney/scripts.pory"
	end
# 121 "data/maps/MtChimney/scripts.pory"

# 122 "data/maps/MtChimney/scripts.pory"
MtChimney_EventScript_BagIsFull::
# 123 "data/maps/MtChimney/scripts.pory"
	msgbox gText_TooBadBagIsFull, MSGBOX_DEFAULT
# 124 "data/maps/MtChimney/scripts.pory"
	hidemoneybox
# 125 "data/maps/MtChimney/scripts.pory"
	release
# 126 "data/maps/MtChimney/scripts.pory"
	end
# 127 "data/maps/MtChimney/scripts.pory"
.else
# 128 "data/maps/MtChimney/scripts.pory"
	hidemoneybox
# 129 "data/maps/MtChimney/scripts.pory"
	giveitem ITEM_LAVA_COOKIE
# 130 "data/maps/MtChimney/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, MtChimney_EventScript_BagIsFull
# 131 "data/maps/MtChimney/scripts.pory"
	release
# 132 "data/maps/MtChimney/scripts.pory"
	end
# 133 "data/maps/MtChimney/scripts.pory"

# 134 "data/maps/MtChimney/scripts.pory"
MtChimney_EventScript_BagIsFull::
# 135 "data/maps/MtChimney/scripts.pory"
	msgbox gText_TooBadBagIsFull, MSGBOX_DEFAULT
# 136 "data/maps/MtChimney/scripts.pory"
	release
# 137 "data/maps/MtChimney/scripts.pory"
	end
# 138 "data/maps/MtChimney/scripts.pory"
.endif @ OW_SHOW_ITEM_DESCRIPTIONS
# 139 "data/maps/MtChimney/scripts.pory"

# 140 "data/maps/MtChimney/scripts.pory"

# 141 "data/maps/MtChimney/scripts.pory"
MtChimney_EventScript_RemoveMoney::
# 142 "data/maps/MtChimney/scripts.pory"
	removemoney 200
# 143 "data/maps/MtChimney/scripts.pory"
	updatemoneybox
# 144 "data/maps/MtChimney/scripts.pory"
	return
# 145 "data/maps/MtChimney/scripts.pory"

# 146 "data/maps/MtChimney/scripts.pory"
MtChimney_EventScript_DeclineLavaCookie::
# 147 "data/maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_OhFineThen, MSGBOX_DEFAULT
# 148 "data/maps/MtChimney/scripts.pory"
	hidemoneybox
# 149 "data/maps/MtChimney/scripts.pory"
	release
# 150 "data/maps/MtChimney/scripts.pory"
	end
# 151 "data/maps/MtChimney/scripts.pory"

# 152 "data/maps/MtChimney/scripts.pory"
MtChimney_EventScript_NotEnoughMoney::
# 153 "data/maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_YouveNotGotTheMoney, MSGBOX_DEFAULT
# 154 "data/maps/MtChimney/scripts.pory"
	hidemoneybox
# 155 "data/maps/MtChimney/scripts.pory"
	release
# 156 "data/maps/MtChimney/scripts.pory"
	end
# 157 "data/maps/MtChimney/scripts.pory"

# 158 "data/maps/MtChimney/scripts.pory"
MtChimney_Movement_ArchieApproachPlayerEast:
# 159 "data/maps/MtChimney/scripts.pory"
	walk_up
# 160 "data/maps/MtChimney/scripts.pory"
	walk_up
# 161 "data/maps/MtChimney/scripts.pory"
	walk_up
# 162 "data/maps/MtChimney/scripts.pory"
	walk_up
# 163 "data/maps/MtChimney/scripts.pory"
	walk_up
# 164 "data/maps/MtChimney/scripts.pory"
	walk_up
# 165 "data/maps/MtChimney/scripts.pory"
	walk_right
# 166 "data/maps/MtChimney/scripts.pory"
	step_end
# 167 "data/maps/MtChimney/scripts.pory"

# 168 "data/maps/MtChimney/scripts.pory"
MtChimney_Movement_ArchieExitEast:
# 169 "data/maps/MtChimney/scripts.pory"
	walk_left
# 170 "data/maps/MtChimney/scripts.pory"
	walk_down
# 171 "data/maps/MtChimney/scripts.pory"
	walk_down
# 172 "data/maps/MtChimney/scripts.pory"
	walk_down
# 173 "data/maps/MtChimney/scripts.pory"
	walk_down
# 174 "data/maps/MtChimney/scripts.pory"
	walk_down
# 175 "data/maps/MtChimney/scripts.pory"
	walk_down
# 176 "data/maps/MtChimney/scripts.pory"
	walk_down
# 177 "data/maps/MtChimney/scripts.pory"
	step_end
# 178 "data/maps/MtChimney/scripts.pory"

# 179 "data/maps/MtChimney/scripts.pory"
MtChimney_Movement_ArchieApproachPlayerNorth:
# 180 "data/maps/MtChimney/scripts.pory"
	walk_up
# 181 "data/maps/MtChimney/scripts.pory"
	walk_up
# 182 "data/maps/MtChimney/scripts.pory"
	walk_up
# 183 "data/maps/MtChimney/scripts.pory"
	walk_up
# 184 "data/maps/MtChimney/scripts.pory"
	walk_up
# 185 "data/maps/MtChimney/scripts.pory"
	walk_right
# 186 "data/maps/MtChimney/scripts.pory"
	walk_right
# 187 "data/maps/MtChimney/scripts.pory"
	step_end
# 188 "data/maps/MtChimney/scripts.pory"

# 189 "data/maps/MtChimney/scripts.pory"
MtChimney_Movement_ArchieExitNorth:
# 190 "data/maps/MtChimney/scripts.pory"
	walk_left
# 191 "data/maps/MtChimney/scripts.pory"
	walk_left
# 192 "data/maps/MtChimney/scripts.pory"
	walk_down
# 193 "data/maps/MtChimney/scripts.pory"
	walk_down
# 194 "data/maps/MtChimney/scripts.pory"
	walk_down
# 195 "data/maps/MtChimney/scripts.pory"
	walk_down
# 196 "data/maps/MtChimney/scripts.pory"
	walk_down
# 197 "data/maps/MtChimney/scripts.pory"
	walk_down
# 198 "data/maps/MtChimney/scripts.pory"
	walk_down
# 199 "data/maps/MtChimney/scripts.pory"
	step_end
# 200 "data/maps/MtChimney/scripts.pory"

# 201 "data/maps/MtChimney/scripts.pory"
MtChimney_Movement_Unused1:
# 202 "data/maps/MtChimney/scripts.pory"
	walk_down
# 203 "data/maps/MtChimney/scripts.pory"
	walk_down
# 204 "data/maps/MtChimney/scripts.pory"
	walk_down
# 205 "data/maps/MtChimney/scripts.pory"
	walk_down
# 206 "data/maps/MtChimney/scripts.pory"
	walk_down
# 207 "data/maps/MtChimney/scripts.pory"
	walk_left
# 208 "data/maps/MtChimney/scripts.pory"
	walk_left
# 209 "data/maps/MtChimney/scripts.pory"
	walk_down
# 210 "data/maps/MtChimney/scripts.pory"
	walk_down
# 211 "data/maps/MtChimney/scripts.pory"
	walk_down
# 212 "data/maps/MtChimney/scripts.pory"
	walk_down
# 213 "data/maps/MtChimney/scripts.pory"
	walk_left
# 214 "data/maps/MtChimney/scripts.pory"
	walk_left
# 215 "data/maps/MtChimney/scripts.pory"
	walk_left
# 216 "data/maps/MtChimney/scripts.pory"
	walk_left
# 217 "data/maps/MtChimney/scripts.pory"
	walk_left
# 218 "data/maps/MtChimney/scripts.pory"
	walk_down
# 219 "data/maps/MtChimney/scripts.pory"
	step_end
# 220 "data/maps/MtChimney/scripts.pory"

# 221 "data/maps/MtChimney/scripts.pory"
MtChimney_Movement_Unused2:
# 222 "data/maps/MtChimney/scripts.pory"
	walk_down
# 223 "data/maps/MtChimney/scripts.pory"
	walk_down
# 224 "data/maps/MtChimney/scripts.pory"
	walk_down
# 225 "data/maps/MtChimney/scripts.pory"
	walk_down
# 226 "data/maps/MtChimney/scripts.pory"
	walk_left
# 227 "data/maps/MtChimney/scripts.pory"
	walk_left
# 228 "data/maps/MtChimney/scripts.pory"
	walk_left
# 229 "data/maps/MtChimney/scripts.pory"
	walk_down
# 230 "data/maps/MtChimney/scripts.pory"
	step_end
# 231 "data/maps/MtChimney/scripts.pory"

# 232 "data/maps/MtChimney/scripts.pory"
MtChimney_Movement_Unused3:
# 233 "data/maps/MtChimney/scripts.pory"
	walk_right
# 234 "data/maps/MtChimney/scripts.pory"
	walk_down
# 235 "data/maps/MtChimney/scripts.pory"
	walk_down
# 236 "data/maps/MtChimney/scripts.pory"
	walk_down
# 237 "data/maps/MtChimney/scripts.pory"
	walk_down
# 238 "data/maps/MtChimney/scripts.pory"
	walk_left
# 239 "data/maps/MtChimney/scripts.pory"
	walk_left
# 240 "data/maps/MtChimney/scripts.pory"
	walk_left
# 241 "data/maps/MtChimney/scripts.pory"
	walk_left
# 242 "data/maps/MtChimney/scripts.pory"
	walk_left
# 243 "data/maps/MtChimney/scripts.pory"
	walk_down
# 244 "data/maps/MtChimney/scripts.pory"
	walk_down
# 245 "data/maps/MtChimney/scripts.pory"
	walk_down
# 246 "data/maps/MtChimney/scripts.pory"
	walk_down
# 247 "data/maps/MtChimney/scripts.pory"
	step_end
# 248 "data/maps/MtChimney/scripts.pory"

# 249 "data/maps/MtChimney/scripts.pory"
MtChimney_Movement_Unused4:
# 250 "data/maps/MtChimney/scripts.pory"
	walk_fast_down
# 251 "data/maps/MtChimney/scripts.pory"
	walk_fast_down
# 252 "data/maps/MtChimney/scripts.pory"
	walk_fast_down
# 253 "data/maps/MtChimney/scripts.pory"
	walk_fast_down
# 254 "data/maps/MtChimney/scripts.pory"
	walk_fast_down
# 255 "data/maps/MtChimney/scripts.pory"
	walk_fast_down
# 256 "data/maps/MtChimney/scripts.pory"
	walk_fast_down
# 257 "data/maps/MtChimney/scripts.pory"
	walk_fast_down
# 258 "data/maps/MtChimney/scripts.pory"
	walk_fast_down
# 259 "data/maps/MtChimney/scripts.pory"
	walk_left
# 260 "data/maps/MtChimney/scripts.pory"
	walk_left
# 261 "data/maps/MtChimney/scripts.pory"
	walk_down
# 262 "data/maps/MtChimney/scripts.pory"
	walk_down
# 263 "data/maps/MtChimney/scripts.pory"
	walk_down
# 264 "data/maps/MtChimney/scripts.pory"
	walk_left
# 265 "data/maps/MtChimney/scripts.pory"
	walk_left
# 266 "data/maps/MtChimney/scripts.pory"
	walk_down
# 267 "data/maps/MtChimney/scripts.pory"
	walk_down
# 268 "data/maps/MtChimney/scripts.pory"
	walk_left
# 269 "data/maps/MtChimney/scripts.pory"
	walk_left
# 270 "data/maps/MtChimney/scripts.pory"
	walk_left
# 271 "data/maps/MtChimney/scripts.pory"
	walk_left
# 272 "data/maps/MtChimney/scripts.pory"
	walk_left
# 273 "data/maps/MtChimney/scripts.pory"
	walk_down
# 274 "data/maps/MtChimney/scripts.pory"
	step_end
# 275 "data/maps/MtChimney/scripts.pory"

# 276 "data/maps/MtChimney/scripts.pory"
MtChimney_Movement_Unused5:
# 277 "data/maps/MtChimney/scripts.pory"
	delay_16
# 278 "data/maps/MtChimney/scripts.pory"
	delay_16
# 279 "data/maps/MtChimney/scripts.pory"
	delay_16
# 280 "data/maps/MtChimney/scripts.pory"
	walk_down
# 281 "data/maps/MtChimney/scripts.pory"
	walk_down
# 282 "data/maps/MtChimney/scripts.pory"
	walk_down
# 283 "data/maps/MtChimney/scripts.pory"
	walk_left
# 284 "data/maps/MtChimney/scripts.pory"
	walk_left
# 285 "data/maps/MtChimney/scripts.pory"
	walk_left
# 286 "data/maps/MtChimney/scripts.pory"
	walk_down
# 287 "data/maps/MtChimney/scripts.pory"
	step_end
# 288 "data/maps/MtChimney/scripts.pory"

# 289 "data/maps/MtChimney/scripts.pory"
MtChimney_Movement_Unused6:
# 290 "data/maps/MtChimney/scripts.pory"
	delay_16
# 291 "data/maps/MtChimney/scripts.pory"
	walk_left
# 292 "data/maps/MtChimney/scripts.pory"
	walk_down
# 293 "data/maps/MtChimney/scripts.pory"
	walk_down
# 294 "data/maps/MtChimney/scripts.pory"
	walk_down
# 295 "data/maps/MtChimney/scripts.pory"
	walk_down
# 296 "data/maps/MtChimney/scripts.pory"
	walk_left
# 297 "data/maps/MtChimney/scripts.pory"
	walk_left
# 298 "data/maps/MtChimney/scripts.pory"
	walk_left
# 299 "data/maps/MtChimney/scripts.pory"
	walk_left
# 300 "data/maps/MtChimney/scripts.pory"
	walk_left
# 301 "data/maps/MtChimney/scripts.pory"
	walk_down
# 302 "data/maps/MtChimney/scripts.pory"
	walk_down
# 303 "data/maps/MtChimney/scripts.pory"
	walk_down
# 304 "data/maps/MtChimney/scripts.pory"
	walk_down
# 305 "data/maps/MtChimney/scripts.pory"
	step_end
# 306 "data/maps/MtChimney/scripts.pory"

# 307 "data/maps/MtChimney/scripts.pory"
MtChimney_Movement_Unused7:
# 308 "data/maps/MtChimney/scripts.pory"
	delay_16
# 309 "data/maps/MtChimney/scripts.pory"
	walk_left
# 310 "data/maps/MtChimney/scripts.pory"
	walk_left
# 311 "data/maps/MtChimney/scripts.pory"
	walk_down
# 312 "data/maps/MtChimney/scripts.pory"
	walk_down
# 313 "data/maps/MtChimney/scripts.pory"
	walk_down
# 314 "data/maps/MtChimney/scripts.pory"
	walk_left
# 315 "data/maps/MtChimney/scripts.pory"
	walk_left
# 316 "data/maps/MtChimney/scripts.pory"
	walk_down
# 317 "data/maps/MtChimney/scripts.pory"
	walk_down
# 318 "data/maps/MtChimney/scripts.pory"
	walk_left
# 319 "data/maps/MtChimney/scripts.pory"
	walk_left
# 320 "data/maps/MtChimney/scripts.pory"
	walk_left
# 321 "data/maps/MtChimney/scripts.pory"
	walk_left
# 322 "data/maps/MtChimney/scripts.pory"
	walk_left
# 323 "data/maps/MtChimney/scripts.pory"
	walk_down
# 324 "data/maps/MtChimney/scripts.pory"
	step_end
# 325 "data/maps/MtChimney/scripts.pory"

# 326 "data/maps/MtChimney/scripts.pory"
MtChimney_Movement_Unused8:
# 327 "data/maps/MtChimney/scripts.pory"
	delay_16
# 328 "data/maps/MtChimney/scripts.pory"
	walk_down
# 329 "data/maps/MtChimney/scripts.pory"
	walk_left
# 330 "data/maps/MtChimney/scripts.pory"
	walk_left
# 331 "data/maps/MtChimney/scripts.pory"
	walk_left
# 332 "data/maps/MtChimney/scripts.pory"
	walk_left
# 333 "data/maps/MtChimney/scripts.pory"
	walk_in_place_faster_down
# 334 "data/maps/MtChimney/scripts.pory"
	step_end
# 335 "data/maps/MtChimney/scripts.pory"

# 336 "data/maps/MtChimney/scripts.pory"
MtChimney_Movement_Unused9:
# 337 "data/maps/MtChimney/scripts.pory"
	walk_down
# 338 "data/maps/MtChimney/scripts.pory"
	walk_down
# 339 "data/maps/MtChimney/scripts.pory"
	walk_down
# 340 "data/maps/MtChimney/scripts.pory"
	walk_down
# 341 "data/maps/MtChimney/scripts.pory"
	walk_left
# 342 "data/maps/MtChimney/scripts.pory"
	walk_left
# 343 "data/maps/MtChimney/scripts.pory"
	walk_left
# 344 "data/maps/MtChimney/scripts.pory"
	walk_left
# 345 "data/maps/MtChimney/scripts.pory"
	walk_left
# 346 "data/maps/MtChimney/scripts.pory"
	walk_down
# 347 "data/maps/MtChimney/scripts.pory"
	walk_down
# 348 "data/maps/MtChimney/scripts.pory"
	walk_down
# 349 "data/maps/MtChimney/scripts.pory"
	walk_down
# 350 "data/maps/MtChimney/scripts.pory"
	step_end
# 351 "data/maps/MtChimney/scripts.pory"

# 352 "data/maps/MtChimney/scripts.pory"
MtChimney_Movement_Unused10:
# 353 "data/maps/MtChimney/scripts.pory"
	walk_down
# 354 "data/maps/MtChimney/scripts.pory"
	step_end
# 355 "data/maps/MtChimney/scripts.pory"

# 356 "data/maps/MtChimney/scripts.pory"
MtChimney_Movement_Unused11:
# 357 "data/maps/MtChimney/scripts.pory"
	walk_down
# 358 "data/maps/MtChimney/scripts.pory"
	walk_down
# 359 "data/maps/MtChimney/scripts.pory"
	walk_down
# 360 "data/maps/MtChimney/scripts.pory"
	walk_down
# 361 "data/maps/MtChimney/scripts.pory"
	walk_down
# 362 "data/maps/MtChimney/scripts.pory"
	walk_down
# 363 "data/maps/MtChimney/scripts.pory"
	walk_down
# 364 "data/maps/MtChimney/scripts.pory"
	step_end
# 365 "data/maps/MtChimney/scripts.pory"

# 366 "data/maps/MtChimney/scripts.pory"
MtChimney_Movement_Unused12:
# 367 "data/maps/MtChimney/scripts.pory"
	delay_16
# 368 "data/maps/MtChimney/scripts.pory"
	delay_16
# 369 "data/maps/MtChimney/scripts.pory"
	walk_in_place_faster_left
# 370 "data/maps/MtChimney/scripts.pory"
	delay_16
# 371 "data/maps/MtChimney/scripts.pory"
	walk_down
# 372 "data/maps/MtChimney/scripts.pory"
	walk_down
# 373 "data/maps/MtChimney/scripts.pory"
	walk_down
# 374 "data/maps/MtChimney/scripts.pory"
	walk_down
# 375 "data/maps/MtChimney/scripts.pory"
	walk_down
# 376 "data/maps/MtChimney/scripts.pory"
	step_end
# 377 "data/maps/MtChimney/scripts.pory"

# 378 "data/maps/MtChimney/scripts.pory"
MtChimney_Movement_Unused13:
# 379 "data/maps/MtChimney/scripts.pory"
	delay_16
# 380 "data/maps/MtChimney/scripts.pory"
	delay_16
# 381 "data/maps/MtChimney/scripts.pory"
	delay_16
# 382 "data/maps/MtChimney/scripts.pory"
	delay_16
# 383 "data/maps/MtChimney/scripts.pory"
	delay_16
# 384 "data/maps/MtChimney/scripts.pory"
	delay_16
# 385 "data/maps/MtChimney/scripts.pory"
	walk_in_place_faster_left
# 386 "data/maps/MtChimney/scripts.pory"
	delay_16
# 387 "data/maps/MtChimney/scripts.pory"
	walk_down
# 388 "data/maps/MtChimney/scripts.pory"
	walk_down
# 389 "data/maps/MtChimney/scripts.pory"
	step_end
# 390 "data/maps/MtChimney/scripts.pory"

# 391 "data/maps/MtChimney/scripts.pory"
MtChimney_Movement_Unused14:
# 392 "data/maps/MtChimney/scripts.pory"
	lock_facing_direction
# 393 "data/maps/MtChimney/scripts.pory"
	walk_fast_left
# 394 "data/maps/MtChimney/scripts.pory"
	unlock_facing_direction
# 395 "data/maps/MtChimney/scripts.pory"
	face_right
# 396 "data/maps/MtChimney/scripts.pory"
	step_end
# 397 "data/maps/MtChimney/scripts.pory"

# 398 "data/maps/MtChimney/scripts.pory"
MtChimney_Movement_Unused15:
# 399 "data/maps/MtChimney/scripts.pory"
	walk_left
# 400 "data/maps/MtChimney/scripts.pory"
	walk_in_place_faster_right
# 401 "data/maps/MtChimney/scripts.pory"
	delay_16
# 402 "data/maps/MtChimney/scripts.pory"
	step_end
# 403 "data/maps/MtChimney/scripts.pory"

# 404 "data/maps/MtChimney/scripts.pory"
MtChimney_EventScript_BusyAquaGrunt1::
# 405 "data/maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_MagmaOutnumbersUs, MSGBOX_SIGN
# 406 "data/maps/MtChimney/scripts.pory"
	end
# 407 "data/maps/MtChimney/scripts.pory"

# 408 "data/maps/MtChimney/scripts.pory"
MtChimney_EventScript_BusyAquaGrunt2::
# 409 "data/maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_LessHabitatForWaterPokemon, MSGBOX_SIGN
# 410 "data/maps/MtChimney/scripts.pory"
	end
# 411 "data/maps/MtChimney/scripts.pory"

# 412 "data/maps/MtChimney/scripts.pory"
MtChimney_EventScript_BusyAquaGrunt3::
# 413 "data/maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_MagmasNameSimilar, MSGBOX_SIGN
# 414 "data/maps/MtChimney/scripts.pory"
	end
# 415 "data/maps/MtChimney/scripts.pory"

# 416 "data/maps/MtChimney/scripts.pory"
MtChimney_EventScript_Tabitha::
# 417 "data/maps/MtChimney/scripts.pory"
	trainerbattle_single TRAINER_TABITHA_MT_CHIMNEY, MtChimney_Text_TabithaIntro, MtChimney_Text_TabithaDefeat
# 418 "data/maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_TabithaPostBattle, MSGBOX_AUTOCLOSE
# 419 "data/maps/MtChimney/scripts.pory"
	end
# 420 "data/maps/MtChimney/scripts.pory"

# 421 "data/maps/MtChimney/scripts.pory"
MtChimney_EventScript_Grunt2::
# 422 "data/maps/MtChimney/scripts.pory"
	trainerbattle_single TRAINER_GRUNT_MT_CHIMNEY_2, MtChimney_Text_Grunt2Intro, MtChimney_Text_Grunt2Defeat
# 423 "data/maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_Grunt2PostBattle, MSGBOX_AUTOCLOSE
# 424 "data/maps/MtChimney/scripts.pory"
	end
# 425 "data/maps/MtChimney/scripts.pory"

# 426 "data/maps/MtChimney/scripts.pory"
MtChimney_EventScript_BusyMagmaGrunt1::
# 427 "data/maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_TeamAquaAlwaysMessingWithPlans, MSGBOX_SIGN
# 428 "data/maps/MtChimney/scripts.pory"
	end
# 429 "data/maps/MtChimney/scripts.pory"

# 430 "data/maps/MtChimney/scripts.pory"
MtChimney_EventScript_BusyMagmaGrunt2::
# 431 "data/maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_MeteoritesPackAmazingPower, MSGBOX_SIGN
# 432 "data/maps/MtChimney/scripts.pory"
	end
# 433 "data/maps/MtChimney/scripts.pory"

# 434 "data/maps/MtChimney/scripts.pory"
MtChimney_EventScript_BusyMagmaGrunt3::
# 435 "data/maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_YouBetterNotMessWithUs, MSGBOX_SIGN
# 436 "data/maps/MtChimney/scripts.pory"
	end
# 437 "data/maps/MtChimney/scripts.pory"

# 438 "data/maps/MtChimney/scripts.pory"
MtChimney_EventScript_BusyMagmaGrunt4::
# 439 "data/maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_AquasNameSimilar, MSGBOX_SIGN
# 440 "data/maps/MtChimney/scripts.pory"
	end
# 441 "data/maps/MtChimney/scripts.pory"

# 442 "data/maps/MtChimney/scripts.pory"
MtChimney_EventScript_BusyMagmaGrunt5::
# 443 "data/maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_DouseThemInFire, MSGBOX_SIGN
# 444 "data/maps/MtChimney/scripts.pory"
	end
# 445 "data/maps/MtChimney/scripts.pory"

# 446 "data/maps/MtChimney/scripts.pory"
MtChimney_EventScript_BusyMagmaGrunt6::
# 447 "data/maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_KeepMakingMoreLand, MSGBOX_SIGN
# 448 "data/maps/MtChimney/scripts.pory"
	end
# 449 "data/maps/MtChimney/scripts.pory"

# 450 "data/maps/MtChimney/scripts.pory"
MtChimney_EventScript_MagmaPoochyena::
# 451 "data/maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_Bufoh, MSGBOX_SIGN
# 452 "data/maps/MtChimney/scripts.pory"
	end
# 453 "data/maps/MtChimney/scripts.pory"

# 454 "data/maps/MtChimney/scripts.pory"
MtChimney_EventScript_AquaPoochyena::
# 455 "data/maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_Bushaa, MSGBOX_SIGN
# 456 "data/maps/MtChimney/scripts.pory"
	end
# 457 "data/maps/MtChimney/scripts.pory"

# 458 "data/maps/MtChimney/scripts.pory"
MtChimney_EventScript_MeteoriteMachine::
# 459 "data/maps/MtChimney/scripts.pory"
	lockall
# 460 "data/maps/MtChimney/scripts.pory"
	goto_if_unset FLAG_DEFEATED_EVIL_TEAM_MT_CHIMNEY, MtChimney_EventScript_MachineOn
# 461 "data/maps/MtChimney/scripts.pory"
	goto_if_set FLAG_RECEIVED_METEORITE, MtChimney_EventScript_MachineOff
# 462 "data/maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_RemoveTheMeteorite, MSGBOX_YESNO
# 463 "data/maps/MtChimney/scripts.pory"
	goto_if_eq VAR_RESULT, NO, MtChimney_EventScript_LeaveMeteoriteAlone
# 464 "data/maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_PlayerRemovedMeteorite, MSGBOX_DEFAULT
# 465 "data/maps/MtChimney/scripts.pory"
	giveitem ITEM_METEORITE
# 466 "data/maps/MtChimney/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
# 467 "data/maps/MtChimney/scripts.pory"
	setflag FLAG_RECEIVED_METEORITE
# 468 "data/maps/MtChimney/scripts.pory"
	releaseall
# 469 "data/maps/MtChimney/scripts.pory"
	end
# 470 "data/maps/MtChimney/scripts.pory"

# 471 "data/maps/MtChimney/scripts.pory"
MtChimney_EventScript_LeaveMeteoriteAlone::
# 472 "data/maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_PlayerLeftMeteorite, MSGBOX_DEFAULT
# 473 "data/maps/MtChimney/scripts.pory"
	releaseall
# 474 "data/maps/MtChimney/scripts.pory"
	end
# 475 "data/maps/MtChimney/scripts.pory"

# 476 "data/maps/MtChimney/scripts.pory"
MtChimney_EventScript_MachineOff::
# 477 "data/maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_MachineMakesNoResponse, MSGBOX_DEFAULT
# 478 "data/maps/MtChimney/scripts.pory"
	releaseall
# 479 "data/maps/MtChimney/scripts.pory"
	end
# 480 "data/maps/MtChimney/scripts.pory"

# 481 "data/maps/MtChimney/scripts.pory"
MtChimney_EventScript_MachineOn::
# 482 "data/maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_MetoriteFittedOnMachine, MSGBOX_DEFAULT
# 483 "data/maps/MtChimney/scripts.pory"
	releaseall
# 484 "data/maps/MtChimney/scripts.pory"
	end
# 485 "data/maps/MtChimney/scripts.pory"

# 486 "data/maps/MtChimney/scripts.pory"
MtChimney_EventScript_RouteSign::
# 487 "data/maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_RouteSign, MSGBOX_SIGN
# 488 "data/maps/MtChimney/scripts.pory"
	end
# 489 "data/maps/MtChimney/scripts.pory"

# 490 "data/maps/MtChimney/scripts.pory"
MtChimney_EventScript_Shelby::
# 491 "data/maps/MtChimney/scripts.pory"
	trainerbattle_single TRAINER_SHELBY_1, MtChimney_Text_ShelbyIntro, MtChimney_Text_ShelbyDefeat, MtChimney_EventScript_DefeatedShelby
# 492 "data/maps/MtChimney/scripts.pory"
	specialvar VAR_RESULT, ShouldTryRematchBattle
# 493 "data/maps/MtChimney/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, MtChimney_EventScript_RematchShelby
# 494 "data/maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_ShelbyPostBattle, MSGBOX_DEFAULT
# 495 "data/maps/MtChimney/scripts.pory"
	release
# 496 "data/maps/MtChimney/scripts.pory"
	end
# 497 "data/maps/MtChimney/scripts.pory"

# 498 "data/maps/MtChimney/scripts.pory"
MtChimney_EventScript_DefeatedShelby::
# 499 "data/maps/MtChimney/scripts.pory"
	special PlayerFaceTrainerAfterBattle
# 500 "data/maps/MtChimney/scripts.pory"
	waitmovement 0
# 501 "data/maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_ShelbyRegister, MSGBOX_DEFAULT
# 502 "data/maps/MtChimney/scripts.pory"
	register_matchcall TRAINER_SHELBY_1
# 503 "data/maps/MtChimney/scripts.pory"
	release
# 504 "data/maps/MtChimney/scripts.pory"
	end
# 505 "data/maps/MtChimney/scripts.pory"

# 506 "data/maps/MtChimney/scripts.pory"
MtChimney_EventScript_RematchShelby::
# 507 "data/maps/MtChimney/scripts.pory"
	trainerbattle_rematch TRAINER_SHELBY_1, MtChimney_Text_ShelbyRematchIntro, MtChimney_Text_ShelbyRematchDefeat
# 508 "data/maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_ShelbyPostRematch, MSGBOX_AUTOCLOSE
# 509 "data/maps/MtChimney/scripts.pory"
	end
# 510 "data/maps/MtChimney/scripts.pory"

# 511 "data/maps/MtChimney/scripts.pory"
MtChimney_EventScript_Melissa::
# 512 "data/maps/MtChimney/scripts.pory"
	trainerbattle_single TRAINER_MELISSA, MtChimney_Text_MelissaIntro, MtChimney_Text_MelissaDefeat
# 513 "data/maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_MelissaPostBattle, MSGBOX_AUTOCLOSE
# 514 "data/maps/MtChimney/scripts.pory"
	end
# 515 "data/maps/MtChimney/scripts.pory"

# 516 "data/maps/MtChimney/scripts.pory"
MtChimney_EventScript_Sheila::
# 517 "data/maps/MtChimney/scripts.pory"
	trainerbattle_single TRAINER_SHEILA, MtChimney_Text_SheilaIntro, MtChimney_Text_SheilaDefeat
# 518 "data/maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_SheilaPostBattle, MSGBOX_AUTOCLOSE
# 519 "data/maps/MtChimney/scripts.pory"
	end
# 520 "data/maps/MtChimney/scripts.pory"

# 521 "data/maps/MtChimney/scripts.pory"
MtChimney_EventScript_Shirley::
# 522 "data/maps/MtChimney/scripts.pory"
	trainerbattle_single TRAINER_SHIRLEY, MtChimney_Text_ShirleyIntro, MtChimney_Text_ShirleyDefeat
# 523 "data/maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_ShirleyPostBattle, MSGBOX_AUTOCLOSE
# 524 "data/maps/MtChimney/scripts.pory"
	end
# 525 "data/maps/MtChimney/scripts.pory"

# 526 "data/maps/MtChimney/scripts.pory"
MtChimney_EventScript_Grunt1::
# 527 "data/maps/MtChimney/scripts.pory"
	trainerbattle_single TRAINER_GRUNT_MT_CHIMNEY_1, MtChimney_Text_Grunt1Intro, MtChimney_Text_Grunt1Defeat
# 528 "data/maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_Grunt1PostBattle, MSGBOX_AUTOCLOSE
# 529 "data/maps/MtChimney/scripts.pory"
	end
# 530 "data/maps/MtChimney/scripts.pory"

# 531 "data/maps/MtChimney/scripts.pory"
MtChimney_EventScript_Sawyer::
# 532 "data/maps/MtChimney/scripts.pory"
	trainerbattle_single TRAINER_SAWYER_1, MtChimney_Text_SawyerIntro, MtChimney_Text_SawyerDefeat, MtChimney_EventScript_SawyerDefeated
# 533 "data/maps/MtChimney/scripts.pory"
	specialvar VAR_RESULT, ShouldTryRematchBattle
# 534 "data/maps/MtChimney/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, MtChimney_EventScript_SawyerRematch
# 535 "data/maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_SawyerPostBattle, MSGBOX_DEFAULT
# 536 "data/maps/MtChimney/scripts.pory"
	release
# 537 "data/maps/MtChimney/scripts.pory"
	end
# 538 "data/maps/MtChimney/scripts.pory"

# 539 "data/maps/MtChimney/scripts.pory"
MtChimney_EventScript_SawyerDefeated::
# 540 "data/maps/MtChimney/scripts.pory"
	special PlayerFaceTrainerAfterBattle
# 541 "data/maps/MtChimney/scripts.pory"
	waitmovement 0
# 542 "data/maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_SawyerRegister, MSGBOX_DEFAULT
# 543 "data/maps/MtChimney/scripts.pory"
	register_matchcall TRAINER_SAWYER_1
# 544 "data/maps/MtChimney/scripts.pory"
	release
# 545 "data/maps/MtChimney/scripts.pory"
	end
# 546 "data/maps/MtChimney/scripts.pory"

# 547 "data/maps/MtChimney/scripts.pory"
MtChimney_EventScript_SawyerRematch::
# 548 "data/maps/MtChimney/scripts.pory"
	trainerbattle_rematch TRAINER_SAWYER_1, MtChimney_Text_SawyerRematchIntro, MtChimney_Text_SawyerRematchDefeat
# 549 "data/maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_SawyerPostRematch, MSGBOX_AUTOCLOSE
# 550 "data/maps/MtChimney/scripts.pory"
	end
# 551 "data/maps/MtChimney/scripts.pory"

# 552 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_MeteoriteWillActivateVolcano:
# 553 "data/maps/MtChimney/scripts.pory"
	.string "The power contained in the METEORITE…\p"
# 554 "data/maps/MtChimney/scripts.pory"
	.string "By amplifying its power with this\n"
# 555 "data/maps/MtChimney/scripts.pory"
	.string "machine, MT. CHIMNEY's volcanic\l"
# 556 "data/maps/MtChimney/scripts.pory"
	.string "activity will instantly intensify…\p"
# 557 "data/maps/MtChimney/scripts.pory"
	.string "Its energy will grow deep inside\n"
# 558 "data/maps/MtChimney/scripts.pory"
	.string "the crater and…\l"
# 559 "data/maps/MtChimney/scripts.pory"
	.string "Fufufu…$"
# 560 "data/maps/MtChimney/scripts.pory"

# 561 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_MaxieIntro:
# 562 "data/maps/MtChimney/scripts.pory"
	.string "MAXIE: Hm?\n"
# 563 "data/maps/MtChimney/scripts.pory"
	.string "Who are you?\p"
# 564 "data/maps/MtChimney/scripts.pory"
	.string "… … … … … …\n"
# 565 "data/maps/MtChimney/scripts.pory"
	.string "… … … … … …\p"
# 566 "data/maps/MtChimney/scripts.pory"
	.string "I'd heard ARCHIE bemoaning a child\n"
# 567 "data/maps/MtChimney/scripts.pory"
	.string "who's been meddling in TEAM AQUA's\l"
# 568 "data/maps/MtChimney/scripts.pory"
	.string "affairs.\p"
# 569 "data/maps/MtChimney/scripts.pory"
	.string "It must be you he meant.\p"
# 570 "data/maps/MtChimney/scripts.pory"
	.string "Humph! So you're thinking of\n"
# 571 "data/maps/MtChimney/scripts.pory"
	.string "interfering with us, TEAM MAGMA?\p"
# 572 "data/maps/MtChimney/scripts.pory"
	.string "Now you listen.\n"
# 573 "data/maps/MtChimney/scripts.pory"
	.string "Long ago, living things used the\l"
# 574 "data/maps/MtChimney/scripts.pory"
	.string "land to live and grow.\p"
# 575 "data/maps/MtChimney/scripts.pory"
	.string "That is why land is all important!\n"
# 576 "data/maps/MtChimney/scripts.pory"
	.string "It is the cradle of all!\p"
# 577 "data/maps/MtChimney/scripts.pory"
	.string "That is why TEAM MAGMA is dedicated\n"
# 578 "data/maps/MtChimney/scripts.pory"
	.string "to the expansion of the land mass.\p"
# 579 "data/maps/MtChimney/scripts.pory"
	.string "It is for further advancement of\n"
# 580 "data/maps/MtChimney/scripts.pory"
	.string "humankind and POKéMON!\p"
# 581 "data/maps/MtChimney/scripts.pory"
	.string "And for that, we need the power of\n"
# 582 "data/maps/MtChimney/scripts.pory"
	.string "what sleeps within this mountain…\p"
# 583 "data/maps/MtChimney/scripts.pory"
	.string "Oh! There was no need for you to\n"
# 584 "data/maps/MtChimney/scripts.pory"
	.string "learn that much.\p"
# 585 "data/maps/MtChimney/scripts.pory"
	.string "But, no matter!\n"
# 586 "data/maps/MtChimney/scripts.pory"
	.string "I'll teach you the consequences of\l"
# 587 "data/maps/MtChimney/scripts.pory"
	.string "meddling in our grand design!$"
# 588 "data/maps/MtChimney/scripts.pory"

# 589 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_MaxieDefeat:
# 590 "data/maps/MtChimney/scripts.pory"
	.string "What?!\p"
# 591 "data/maps/MtChimney/scripts.pory"
	.string "I, MAXIE, was caught off guard?!$"
# 592 "data/maps/MtChimney/scripts.pory"

# 593 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_MaxieYouHaventSeenLastOfMagma:
# 594 "data/maps/MtChimney/scripts.pory"
	.string "MAXIE: But, enough.\n"
# 595 "data/maps/MtChimney/scripts.pory"
	.string "I will back off this time.\p"
# 596 "data/maps/MtChimney/scripts.pory"
	.string "But don't think that this is the last\n"
# 597 "data/maps/MtChimney/scripts.pory"
	.string "you've seen of TEAM MAGMA.\p"
# 598 "data/maps/MtChimney/scripts.pory"
	.string "Fufufu…\p"
# 599 "data/maps/MtChimney/scripts.pory"
	.string "Even without the METEORITE, if we\n"
# 600 "data/maps/MtChimney/scripts.pory"
	.string "obtain that ORB… Fufufu…$"
# 601 "data/maps/MtChimney/scripts.pory"

# 602 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_TabithaIntro:
# 603 "data/maps/MtChimney/scripts.pory"
	.string "Hehehe!\p"
# 604 "data/maps/MtChimney/scripts.pory"
	.string "So you've come all the way here!\p"
# 605 "data/maps/MtChimney/scripts.pory"
	.string "But you're too late!\n"
# 606 "data/maps/MtChimney/scripts.pory"
	.string "I've already delivered the METEORITE\l"
# 607 "data/maps/MtChimney/scripts.pory"
	.string "from METEOR FALLS to the BOSS!$"
# 608 "data/maps/MtChimney/scripts.pory"

# 609 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_TabithaDefeat:
# 610 "data/maps/MtChimney/scripts.pory"
	.string "Hehehe…\p"
# 611 "data/maps/MtChimney/scripts.pory"
	.string "Even though I've lost, if our leader\n"
# 612 "data/maps/MtChimney/scripts.pory"
	.string "awakens that thing…$"
# 613 "data/maps/MtChimney/scripts.pory"

# 614 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_TabithaPostBattle:
# 615 "data/maps/MtChimney/scripts.pory"
	.string "BOSS, hurry!\n"
# 616 "data/maps/MtChimney/scripts.pory"
	.string "Give it the METEORITE's energy!\p"
# 617 "data/maps/MtChimney/scripts.pory"
	.string "Hehehe…$"
# 618 "data/maps/MtChimney/scripts.pory"

# 619 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_Grunt2Intro:
# 620 "data/maps/MtChimney/scripts.pory"
	.string "We of TEAM MAGMA are working hard for\n"
# 621 "data/maps/MtChimney/scripts.pory"
	.string "everyone's sake.\p"
# 622 "data/maps/MtChimney/scripts.pory"
	.string "Like, if that thing's power made more\n"
# 623 "data/maps/MtChimney/scripts.pory"
	.string "land, there'd be more places to live.\p"
# 624 "data/maps/MtChimney/scripts.pory"
	.string "Everyone'd be happy!$"
# 625 "data/maps/MtChimney/scripts.pory"

# 626 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_Grunt2Defeat:
# 627 "data/maps/MtChimney/scripts.pory"
	.string "Hunh?\n"
# 628 "data/maps/MtChimney/scripts.pory"
	.string "What do you mean I lost?$"
# 629 "data/maps/MtChimney/scripts.pory"

# 630 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_Grunt2PostBattle:
# 631 "data/maps/MtChimney/scripts.pory"
	.string "Our BOSS says, “It will make everyone\n"
# 632 "data/maps/MtChimney/scripts.pory"
	.string "happy.”\p"
# 633 "data/maps/MtChimney/scripts.pory"
	.string "But why does everyone keep getting\n"
# 634 "data/maps/MtChimney/scripts.pory"
	.string "in our way?$"
# 635 "data/maps/MtChimney/scripts.pory"

# 636 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_Grunt1Intro:
# 637 "data/maps/MtChimney/scripts.pory"
	.string "If there were more land, I'd be able\n"
# 638 "data/maps/MtChimney/scripts.pory"
	.string "to get a big house of my own!\p"
# 639 "data/maps/MtChimney/scripts.pory"
	.string "I'm going to build it on hardened lava!$"
# 640 "data/maps/MtChimney/scripts.pory"

# 641 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_Grunt1Defeat:
# 642 "data/maps/MtChimney/scripts.pory"
	.string "My dream of a big house…$"
# 643 "data/maps/MtChimney/scripts.pory"

# 644 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_Grunt1PostBattle:
# 645 "data/maps/MtChimney/scripts.pory"
	.string "A kid like you, you ought to be\n"
# 646 "data/maps/MtChimney/scripts.pory"
	.string "splashing about in the waves!$"
# 647 "data/maps/MtChimney/scripts.pory"

# 648 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_TeamAquaAlwaysMessingWithPlans:
# 649 "data/maps/MtChimney/scripts.pory"
	.string "That annoying TEAM AQUA…\n"
# 650 "data/maps/MtChimney/scripts.pory"
	.string "They always mess with our plans!$"
# 651 "data/maps/MtChimney/scripts.pory"

# 652 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_MeteoritesPackAmazingPower:
# 653 "data/maps/MtChimney/scripts.pory"
	.string "METEORITES pack amazing power!$"
# 654 "data/maps/MtChimney/scripts.pory"

# 655 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_YouBetterNotMessWithUs:
# 656 "data/maps/MtChimney/scripts.pory"
	.string "You'd better not mess with us!\p"
# 657 "data/maps/MtChimney/scripts.pory"
	.string "We're trying to awaken that thing\n"
# 658 "data/maps/MtChimney/scripts.pory"
	.string "for the benefit of everyone!$"
# 659 "data/maps/MtChimney/scripts.pory"

# 660 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_AquasNameSimilar:
# 661 "data/maps/MtChimney/scripts.pory"
	.string "We're TEAM MAGMA!\p"
# 662 "data/maps/MtChimney/scripts.pory"
	.string "They're TEAM AQUA!\p"
# 663 "data/maps/MtChimney/scripts.pory"
	.string "It totally annoys me that they'd\n"
# 664 "data/maps/MtChimney/scripts.pory"
	.string "use a name like ours!$"
# 665 "data/maps/MtChimney/scripts.pory"

# 666 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_DouseThemInFire:
# 667 "data/maps/MtChimney/scripts.pory"
	.string "Yeah!\n"
# 668 "data/maps/MtChimney/scripts.pory"
	.string "Douse them in fire!$"
# 669 "data/maps/MtChimney/scripts.pory"

# 670 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_KeepMakingMoreLand:
# 671 "data/maps/MtChimney/scripts.pory"
	.string "We're going to keep making more land!$"
# 672 "data/maps/MtChimney/scripts.pory"

# 673 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_Bufoh:
# 674 "data/maps/MtChimney/scripts.pory"
	.string "Bufoh!$"
# 675 "data/maps/MtChimney/scripts.pory"

# 676 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_ArchieGoStopTeamMagma:
# 677 "data/maps/MtChimney/scripts.pory"
	.string "ARCHIE: Grr, {PLAYER}!\n"
# 678 "data/maps/MtChimney/scripts.pory"
	.string "I should've guessed you'd show up!\p"
# 679 "data/maps/MtChimney/scripts.pory"
	.string "See for yourself what the fanatics\n"
# 680 "data/maps/MtChimney/scripts.pory"
	.string "of TEAM MAGMA are up to!\p"
# 681 "data/maps/MtChimney/scripts.pory"
	.string "They're trying to inject the stolen\n"
# 682 "data/maps/MtChimney/scripts.pory"
	.string "METEORITE's power into the volcano!\p"
# 683 "data/maps/MtChimney/scripts.pory"
	.string "Doing something like that will cause\n"
# 684 "data/maps/MtChimney/scripts.pory"
	.string "the volcano's eruption!$"
# 685 "data/maps/MtChimney/scripts.pory"

# 686 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_ArchieIHaveMyHandsFull:
# 687 "data/maps/MtChimney/scripts.pory"
	.string "ARCHIE: Grrr…\p"
# 688 "data/maps/MtChimney/scripts.pory"
	.string "I want to stop that MAXIE,\n"
# 689 "data/maps/MtChimney/scripts.pory"
	.string "but I can't!\p"
# 690 "data/maps/MtChimney/scripts.pory"
	.string "Not when I have my hands full battling\n"
# 691 "data/maps/MtChimney/scripts.pory"
	.string "three opponents at once!$"
# 692 "data/maps/MtChimney/scripts.pory"

# 693 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_ArchieThankYou:
# 694 "data/maps/MtChimney/scripts.pory"
	.string "ARCHIE: {PLAYER}!\n"
# 695 "data/maps/MtChimney/scripts.pory"
	.string "Thank you!\p"
# 696 "data/maps/MtChimney/scripts.pory"
	.string "With your help, we thwarted TEAM\n"
# 697 "data/maps/MtChimney/scripts.pory"
	.string "MAGMA's destructive plan!\p"
# 698 "data/maps/MtChimney/scripts.pory"
	.string "But… You…\n"
# 699 "data/maps/MtChimney/scripts.pory"
	.string "Whose side are you on?\p"
# 700 "data/maps/MtChimney/scripts.pory"
	.string "Ah, it doesn't matter.\p"
# 701 "data/maps/MtChimney/scripts.pory"
	.string "We will remain vigilant and keep up\n"
# 702 "data/maps/MtChimney/scripts.pory"
	.string "our pursuit of TEAM MAGMA.\p"
# 703 "data/maps/MtChimney/scripts.pory"
	.string "{PLAYER}, we shall meet again!$"
# 704 "data/maps/MtChimney/scripts.pory"

# 705 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_MagmaOutnumbersUs:
# 706 "data/maps/MtChimney/scripts.pory"
	.string "Darn… TEAM MAGMA outnumbers us!\n"
# 707 "data/maps/MtChimney/scripts.pory"
	.string "We can't keep up with them!$"
# 708 "data/maps/MtChimney/scripts.pory"

# 709 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_LessHabitatForWaterPokemon:
# 710 "data/maps/MtChimney/scripts.pory"
	.string "If they expand the land, there'll be\n"
# 711 "data/maps/MtChimney/scripts.pory"
	.string "less habitats for WATER POKéMON!$"
# 712 "data/maps/MtChimney/scripts.pory"

# 713 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_MagmasNameSimilar:
# 714 "data/maps/MtChimney/scripts.pory"
	.string "We're TEAM AQUA!\p"
# 715 "data/maps/MtChimney/scripts.pory"
	.string "They're TEAM MAGMA!\p"
# 716 "data/maps/MtChimney/scripts.pory"
	.string "It burns me up that they'd use such\n"
# 717 "data/maps/MtChimney/scripts.pory"
	.string "a confusing name!$"
# 718 "data/maps/MtChimney/scripts.pory"

# 719 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_Bushaa:
# 720 "data/maps/MtChimney/scripts.pory"
	.string "Bushaa!$"
# 721 "data/maps/MtChimney/scripts.pory"

# 722 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_LavaCookiesJust200:
# 723 "data/maps/MtChimney/scripts.pory"
	.string "LAVA COOKIES are MT. CHIMNEY's local\n"
# 724 "data/maps/MtChimney/scripts.pory"
	.string "specialty.\p"
# 725 "data/maps/MtChimney/scripts.pory"
	.string "Try one. It's just ¥200.$"
# 726 "data/maps/MtChimney/scripts.pory"

# 727 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_ThankYouDear:
# 728 "data/maps/MtChimney/scripts.pory"
	.string "Thank you, dear!$"
# 729 "data/maps/MtChimney/scripts.pory"

# 730 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_YouveNotGotTheMoney:
# 731 "data/maps/MtChimney/scripts.pory"
	.string "Oh, dear. You can't buy a thing if\n"
# 732 "data/maps/MtChimney/scripts.pory"
	.string "you've not got the money.$"
# 733 "data/maps/MtChimney/scripts.pory"

# 734 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_OhFineThen:
# 735 "data/maps/MtChimney/scripts.pory"
	.string "Oh, fine then.$"
# 736 "data/maps/MtChimney/scripts.pory"

# 737 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_MetoriteFittedOnMachine:
# 738 "data/maps/MtChimney/scripts.pory"
	.string "A METEORITE is fitted on a mysterious\n"
# 739 "data/maps/MtChimney/scripts.pory"
	.string "machine…\p"
# 740 "data/maps/MtChimney/scripts.pory"
	.string "The machine seems to be storing\n"
# 741 "data/maps/MtChimney/scripts.pory"
	.string "energy in the METEORITE.$"
# 742 "data/maps/MtChimney/scripts.pory"

# 743 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_RemoveTheMeteorite:
# 744 "data/maps/MtChimney/scripts.pory"
	.string "A METEORITE is fitted on a mysterious\n"
# 745 "data/maps/MtChimney/scripts.pory"
	.string "machine…\p"
# 746 "data/maps/MtChimney/scripts.pory"
	.string "Do you want to remove the METEORITE?$"
# 747 "data/maps/MtChimney/scripts.pory"

# 748 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_PlayerRemovedMeteorite:
# 749 "data/maps/MtChimney/scripts.pory"
	.string "{PLAYER} removed the METEORITE from\n"
# 750 "data/maps/MtChimney/scripts.pory"
	.string "the mysterious machine.$"
# 751 "data/maps/MtChimney/scripts.pory"

# 752 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_PlayerLeftMeteorite:
# 753 "data/maps/MtChimney/scripts.pory"
	.string "{PLAYER} left the METEORITE where\n"
# 754 "data/maps/MtChimney/scripts.pory"
	.string "it was.$"
# 755 "data/maps/MtChimney/scripts.pory"

# 756 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_MachineMakesNoResponse:
# 757 "data/maps/MtChimney/scripts.pory"
	.string "This mysterious machine…\n"
# 758 "data/maps/MtChimney/scripts.pory"
	.string "It makes no response whatsoever.$"
# 759 "data/maps/MtChimney/scripts.pory"

# 760 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_RouteSign:
# 761 "data/maps/MtChimney/scripts.pory"
	.string "{DOWN_ARROW} JAGGED PATH\n"
# 762 "data/maps/MtChimney/scripts.pory"
	.string "LAVARIDGE TOWN AHEAD$"
# 763 "data/maps/MtChimney/scripts.pory"

# 764 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_ShelbyIntro:
# 765 "data/maps/MtChimney/scripts.pory"
	.string "I've been to the hot springs and\n"
# 766 "data/maps/MtChimney/scripts.pory"
	.string "refreshed my tired bones.\l"
# 767 "data/maps/MtChimney/scripts.pory"
	.string "Right now I'm feeling strong!$"
# 768 "data/maps/MtChimney/scripts.pory"

# 769 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_ShelbyDefeat:
# 770 "data/maps/MtChimney/scripts.pory"
	.string "Oh, my goodness.\n"
# 771 "data/maps/MtChimney/scripts.pory"
	.string "Now, aren't you something!$"
# 772 "data/maps/MtChimney/scripts.pory"

# 773 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_ShelbyPostBattle:
# 774 "data/maps/MtChimney/scripts.pory"
	.string "Well, well, I've lost. I can't call\n"
# 775 "data/maps/MtChimney/scripts.pory"
	.string "myself an EXPERT now, can I?$"
# 776 "data/maps/MtChimney/scripts.pory"

# 777 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_ShelbyRegister:
# 778 "data/maps/MtChimney/scripts.pory"
	.string "Thank you, child. It was fun, as if\n"
# 779 "data/maps/MtChimney/scripts.pory"
	.string "I were battling my own grandchild.\p"
# 780 "data/maps/MtChimney/scripts.pory"
	.string "Please, come see me again for\n"
# 781 "data/maps/MtChimney/scripts.pory"
	.string "a rematch.$"
# 782 "data/maps/MtChimney/scripts.pory"

# 783 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_ShelbyRematchIntro:
# 784 "data/maps/MtChimney/scripts.pory"
	.string "If you can mesh your heart with those\n"
# 785 "data/maps/MtChimney/scripts.pory"
	.string "of your POKéMON, why, you should be\l"
# 786 "data/maps/MtChimney/scripts.pory"
	.string "able to achieve great things.$"
# 787 "data/maps/MtChimney/scripts.pory"

# 788 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_ShelbyRematchDefeat:
# 789 "data/maps/MtChimney/scripts.pory"
	.string "Oh, my goodness.\n"
# 790 "data/maps/MtChimney/scripts.pory"
	.string "Now, aren't you something!$"
# 791 "data/maps/MtChimney/scripts.pory"

# 792 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_ShelbyPostRematch:
# 793 "data/maps/MtChimney/scripts.pory"
	.string "Perhaps your heart has become one\n"
# 794 "data/maps/MtChimney/scripts.pory"
	.string "with the hearts of your POKéMON.$"
# 795 "data/maps/MtChimney/scripts.pory"

# 796 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_MelissaIntro:
# 797 "data/maps/MtChimney/scripts.pory"
	.string "I've got the fire in me, baby.\n"
# 798 "data/maps/MtChimney/scripts.pory"
	.string "I can't stand it! I have to battle!$"
# 799 "data/maps/MtChimney/scripts.pory"

# 800 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_MelissaDefeat:
# 801 "data/maps/MtChimney/scripts.pory"
	.string "Ooh, that was a scorching-hot match!$"
# 802 "data/maps/MtChimney/scripts.pory"

# 803 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_MelissaPostBattle:
# 804 "data/maps/MtChimney/scripts.pory"
	.string "The heat of MT. CHIMNEY warms\n"
# 805 "data/maps/MtChimney/scripts.pory"
	.string "me up, baby!$"
# 806 "data/maps/MtChimney/scripts.pory"

# 807 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_SheilaIntro:
# 808 "data/maps/MtChimney/scripts.pory"
	.string "I've finally made it to MT. CHIMNEY.\n"
# 809 "data/maps/MtChimney/scripts.pory"
	.string "I want to make my POKéMON battle!$"
# 810 "data/maps/MtChimney/scripts.pory"

# 811 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_SheilaDefeat:
# 812 "data/maps/MtChimney/scripts.pory"
	.string "The way you battle…\n"
# 813 "data/maps/MtChimney/scripts.pory"
	.string "It's like a MT. CHIMNEY eruption!$"
# 814 "data/maps/MtChimney/scripts.pory"

# 815 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_SheilaPostBattle:
# 816 "data/maps/MtChimney/scripts.pory"
	.string "Like I said, I've finally made it to\n"
# 817 "data/maps/MtChimney/scripts.pory"
	.string "MT. CHIMNEY. It would be a shame if\l"
# 818 "data/maps/MtChimney/scripts.pory"
	.string "I only do a little sightseeing…\p"
# 819 "data/maps/MtChimney/scripts.pory"
	.string "I want to get in some battles and buy\n"
# 820 "data/maps/MtChimney/scripts.pory"
	.string "COOKIES as souvenirs.$"
# 821 "data/maps/MtChimney/scripts.pory"

# 822 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_ShirleyIntro:
# 823 "data/maps/MtChimney/scripts.pory"
	.string "Since I bathed in the hot springs,\n"
# 824 "data/maps/MtChimney/scripts.pory"
	.string "I've been feeling great!\l"
# 825 "data/maps/MtChimney/scripts.pory"
	.string "I'm sure I'm going to win!$"
# 826 "data/maps/MtChimney/scripts.pory"

# 827 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_ShirleyDefeat:
# 828 "data/maps/MtChimney/scripts.pory"
	.string "Yowch!\n"
# 829 "data/maps/MtChimney/scripts.pory"
	.string "I'm getting a chill out of the water.$"
# 830 "data/maps/MtChimney/scripts.pory"

# 831 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_ShirleyPostBattle:
# 832 "data/maps/MtChimney/scripts.pory"
	.string "I'll have to take another dip in the\n"
# 833 "data/maps/MtChimney/scripts.pory"
	.string "hot springs. Want to join me?\p"
# 834 "data/maps/MtChimney/scripts.pory"
	.string "Just joking!$"
# 835 "data/maps/MtChimney/scripts.pory"

# 836 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_SawyerIntro:
# 837 "data/maps/MtChimney/scripts.pory"
	.string "This is one fine mountain! Plenty of\n"
# 838 "data/maps/MtChimney/scripts.pory"
	.string "hot people around for company!$"
# 839 "data/maps/MtChimney/scripts.pory"

# 840 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_SawyerDefeat:
# 841 "data/maps/MtChimney/scripts.pory"
	.string "Oh, you're a real firebrand, too!$"
# 842 "data/maps/MtChimney/scripts.pory"

# 843 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_SawyerPostBattle:
# 844 "data/maps/MtChimney/scripts.pory"
	.string "I think I need a dip in LAVARIDGE\n"
# 845 "data/maps/MtChimney/scripts.pory"
	.string "HOT SPRING with the locals!$"
# 846 "data/maps/MtChimney/scripts.pory"

# 847 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_SawyerRegister:
# 848 "data/maps/MtChimney/scripts.pory"
	.string "I like little fireballs like you.\n"
# 849 "data/maps/MtChimney/scripts.pory"
	.string "Let me register you in my POKéNAV.$"
# 850 "data/maps/MtChimney/scripts.pory"

# 851 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_SawyerRematchIntro:
# 852 "data/maps/MtChimney/scripts.pory"
	.string "I'm happily surrounded by hot people\n"
# 853 "data/maps/MtChimney/scripts.pory"
	.string "around these parts. I won't lose!$"
# 854 "data/maps/MtChimney/scripts.pory"

# 855 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_SawyerRematchDefeat:
# 856 "data/maps/MtChimney/scripts.pory"
	.string "Gosh, you're still the same\n"
# 857 "data/maps/MtChimney/scripts.pory"
	.string "firebrand as before!$"
# 858 "data/maps/MtChimney/scripts.pory"

# 859 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_SawyerPostRematch:
# 860 "data/maps/MtChimney/scripts.pory"
	.string "Actually, it really is hot here.\n"
# 861 "data/maps/MtChimney/scripts.pory"
	.string "I'm overdressed for these parts.$"
