# 1 "data/maps/MtChimney/scripts.pory"

# 2 "data/maps/MtChimney/scripts.pory"
MtChimney_MapScripts::
# 3 "data/maps/MtChimney/scripts.pory"
	map_script MAP_SCRIPT_ON_RESUME, MtChimney_OnResume
# 4 "data/maps/MtChimney/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, MtChimney_OnTransition
# 5 "data/maps/MtChimney/scripts.pory"
	.byte 0
# 6 "data/maps/MtChimney/scripts.pory"

# 7 "data/maps/MtChimney/scripts.pory"
MtChimney_OnTransition:
# 8 "data/maps/MtChimney/scripts.pory"
	setvar VAR_JAGGED_PASS_ASH_WEATHER, 1
# 9 "data/maps/MtChimney/scripts.pory"
	end
# 10 "data/maps/MtChimney/scripts.pory"

# 11 "data/maps/MtChimney/scripts.pory"
MtChimney_OnResume:
# 12 "data/maps/MtChimney/scripts.pory"
	setstepcallback STEP_CB_ASH
# 13 "data/maps/MtChimney/scripts.pory"
	end
# 14 "data/maps/MtChimney/scripts.pory"

# 15 "data/maps/MtChimney/scripts.pory"
MtChimney_EventScript_Archie::
# 16 "data/maps/MtChimney/scripts.pory"
	lock
# 17 "data/maps/MtChimney/scripts.pory"
	faceplayer
# 18 "data/maps/MtChimney/scripts.pory"
	call_if_unset FLAG_EVIL_LEADER_PLEASE_STOP, MtChimney_EventScript_ArchieGoStopTeamMagma
# 19 "data/maps/MtChimney/scripts.pory"
	call_if_set FLAG_EVIL_LEADER_PLEASE_STOP, MtChimney_EventScript_ArchieBusyFighting
# 20 "data/maps/MtChimney/scripts.pory"
	closemessage
# 21 "data/maps/MtChimney/scripts.pory"
	applymovement LOCALID_MT_CHIMNEY_ARCHIE, Common_Movement_FaceOriginalDirection
# 22 "data/maps/MtChimney/scripts.pory"
	waitmovement 0
# 23 "data/maps/MtChimney/scripts.pory"
	setflag FLAG_EVIL_LEADER_PLEASE_STOP
# 24 "data/maps/MtChimney/scripts.pory"
	release
# 25 "data/maps/MtChimney/scripts.pory"
	end
# 26 "data/maps/MtChimney/scripts.pory"

# 27 "data/maps/MtChimney/scripts.pory"
MtChimney_EventScript_ArchieGoStopTeamMagma::
# 28 "data/maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_ArchieGoStopTeamMagma, MSGBOX_DEFAULT
# 29 "data/maps/MtChimney/scripts.pory"
	return
# 30 "data/maps/MtChimney/scripts.pory"

# 31 "data/maps/MtChimney/scripts.pory"
MtChimney_EventScript_ArchieBusyFighting::
# 32 "data/maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_ArchieIHaveMyHandsFull, MSGBOX_DEFAULT
# 33 "data/maps/MtChimney/scripts.pory"
	return
# 34 "data/maps/MtChimney/scripts.pory"

# 35 "data/maps/MtChimney/scripts.pory"
MtChimney_EventScript_Maxie::
# 36 "data/maps/MtChimney/scripts.pory"
	lockall
# 37 "data/maps/MtChimney/scripts.pory"
	playbgm MUS_ENCOUNTER_MAGMA, FALSE
# 38 "data/maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_MeteoriteWillActivateVolcano, MSGBOX_DEFAULT
# 39 "data/maps/MtChimney/scripts.pory"
	applymovement LOCALID_MT_CHIMNEY_MAXIE, Common_Movement_FacePlayer
# 40 "data/maps/MtChimney/scripts.pory"
	waitmovement 0
# 41 "data/maps/MtChimney/scripts.pory"
	playse SE_PIN
# 42 "data/maps/MtChimney/scripts.pory"
	applymovement LOCALID_MT_CHIMNEY_MAXIE, Common_Movement_ExclamationMark
# 43 "data/maps/MtChimney/scripts.pory"
	waitmovement 0
# 44 "data/maps/MtChimney/scripts.pory"
	applymovement LOCALID_MT_CHIMNEY_MAXIE, Common_Movement_Delay48
# 45 "data/maps/MtChimney/scripts.pory"
	waitmovement 0
# 46 "data/maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_MaxieIntro, MSGBOX_DEFAULT
# 47 "data/maps/MtChimney/scripts.pory"
	trainerbattle_no_intro TRAINER_MAXIE_MT_CHIMNEY, MtChimney_Text_MaxieDefeat
# 48 "data/maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_MaxieYouHaventSeenLastOfMagma, MSGBOX_DEFAULT
# 49 "data/maps/MtChimney/scripts.pory"
	closemessage
# 50 "data/maps/MtChimney/scripts.pory"
	delay 30
# 51 "data/maps/MtChimney/scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 52 "data/maps/MtChimney/scripts.pory"
	removeobject LOCALID_MT_CHIMNEY_MAXIE
# 53 "data/maps/MtChimney/scripts.pory"
	removeobject LOCALID_MT_CHIMNEY_MAGMA_GRUNT_1
# 54 "data/maps/MtChimney/scripts.pory"
	removeobject LOCALID_MT_CHIMNEY_TABITHA
# 55 "data/maps/MtChimney/scripts.pory"
	removeobject LOCALID_MT_CHIMNEY_MAGMA_GRUNT_2
# 56 "data/maps/MtChimney/scripts.pory"
	setflag FLAG_HIDE_MT_CHIMNEY_TEAM_MAGMA
# 57 "data/maps/MtChimney/scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 58 "data/maps/MtChimney/scripts.pory"
	setobjectxyperm LOCALID_MT_CHIMNEY_ARCHIE, 10, 12
# 59 "data/maps/MtChimney/scripts.pory"
	addobject LOCALID_MT_CHIMNEY_ARCHIE
# 60 "data/maps/MtChimney/scripts.pory"
	call_if_eq VAR_FACING, DIR_EAST, MtChimney_EventScript_ArchieApproachPlayerEast
# 61 "data/maps/MtChimney/scripts.pory"
	call_if_eq VAR_FACING, DIR_NORTH, MtChimney_EventScript_ArchieApproachPlayerNorth
# 62 "data/maps/MtChimney/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
# 63 "data/maps/MtChimney/scripts.pory"
	waitmovement 0
# 64 "data/maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_ArchieThankYou, MSGBOX_DEFAULT
# 65 "data/maps/MtChimney/scripts.pory"
	closemessage
# 66 "data/maps/MtChimney/scripts.pory"
	call_if_eq VAR_FACING, DIR_EAST, MtChimney_EventScript_ArchieExitEast
# 67 "data/maps/MtChimney/scripts.pory"
	call_if_eq VAR_FACING, DIR_NORTH, MtChimney_EventScript_ArchieExitNorth
# 68 "data/maps/MtChimney/scripts.pory"
	removeobject LOCALID_MT_CHIMNEY_ARCHIE
# 69 "data/maps/MtChimney/scripts.pory"
	setflag FLAG_HIDE_MT_CHIMNEY_TEAM_AQUA
# 70 "data/maps/MtChimney/scripts.pory"
	setflag FLAG_DEFEATED_EVIL_TEAM_MT_CHIMNEY
# 71 "data/maps/MtChimney/scripts.pory"
	clearflag FLAG_HIDE_FALLARBOR_HOUSE_PROF_COZMO
# 72 "data/maps/MtChimney/scripts.pory"
	setflag FLAG_HIDE_METEOR_FALLS_1F_1R_COZMO
# 73 "data/maps/MtChimney/scripts.pory"
	clearflag FLAG_HIDE_MT_CHIMNEY_LAVA_COOKIE_LADY
# 74 "data/maps/MtChimney/scripts.pory"
	releaseall
# 75 "data/maps/MtChimney/scripts.pory"
	end
# 76 "data/maps/MtChimney/scripts.pory"

# 77 "data/maps/MtChimney/scripts.pory"
MtChimney_EventScript_ArchieApproachPlayerEast::
# 78 "data/maps/MtChimney/scripts.pory"
	applymovement LOCALID_MT_CHIMNEY_ARCHIE, MtChimney_Movement_ArchieApproachPlayerEast
# 79 "data/maps/MtChimney/scripts.pory"
	waitmovement 0
# 80 "data/maps/MtChimney/scripts.pory"
	return
# 81 "data/maps/MtChimney/scripts.pory"

# 82 "data/maps/MtChimney/scripts.pory"
MtChimney_EventScript_ArchieApproachPlayerNorth::
# 83 "data/maps/MtChimney/scripts.pory"
	applymovement LOCALID_MT_CHIMNEY_ARCHIE, MtChimney_Movement_ArchieApproachPlayerNorth
# 84 "data/maps/MtChimney/scripts.pory"
	waitmovement 0
# 85 "data/maps/MtChimney/scripts.pory"
	return
# 86 "data/maps/MtChimney/scripts.pory"

# 87 "data/maps/MtChimney/scripts.pory"
MtChimney_EventScript_ArchieExitEast::
# 88 "data/maps/MtChimney/scripts.pory"
	applymovement LOCALID_MT_CHIMNEY_ARCHIE, MtChimney_Movement_ArchieExitEast
# 89 "data/maps/MtChimney/scripts.pory"
	waitmovement 0
# 90 "data/maps/MtChimney/scripts.pory"
	return
# 91 "data/maps/MtChimney/scripts.pory"

# 92 "data/maps/MtChimney/scripts.pory"
MtChimney_EventScript_ArchieExitNorth::
# 93 "data/maps/MtChimney/scripts.pory"
	applymovement LOCALID_MT_CHIMNEY_ARCHIE, MtChimney_Movement_ArchieExitNorth
# 94 "data/maps/MtChimney/scripts.pory"
	waitmovement 0
# 95 "data/maps/MtChimney/scripts.pory"
	return
# 96 "data/maps/MtChimney/scripts.pory"

# 97 "data/maps/MtChimney/scripts.pory"
MtChimney_EventScript_LavaCookieLady::
# 98 "data/maps/MtChimney/scripts.pory"
	lock
# 99 "data/maps/MtChimney/scripts.pory"
	faceplayer
# 100 "data/maps/MtChimney/scripts.pory"
	showmoneybox 0, 0
# 101 "data/maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_LavaCookiesJust200, MSGBOX_YESNO
# 102 "data/maps/MtChimney/scripts.pory"
	goto_if_eq VAR_RESULT, NO, MtChimney_EventScript_DeclineLavaCookie
# 103 "data/maps/MtChimney/scripts.pory"
	checkmoney 200
# 104 "data/maps/MtChimney/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, MtChimney_EventScript_NotEnoughMoney
# 105 "data/maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_ThankYouDear, MSGBOX_DEFAULT
# 106 "data/maps/MtChimney/scripts.pory"
	checkitemspace ITEM_LAVA_COOKIE
# 107 "data/maps/MtChimney/scripts.pory"
	call_if_eq VAR_RESULT, TRUE, MtChimney_EventScript_RemoveMoney
# 108 "data/maps/MtChimney/scripts.pory"
.if OW_SHOW_ITEM_DESCRIPTIONS == OW_ITEM_DESCRIPTIONS_OFF
# 109 "data/maps/MtChimney/scripts.pory"
	giveitem ITEM_LAVA_COOKIE
# 110 "data/maps/MtChimney/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, MtChimney_EventScript_BagIsFull
# 111 "data/maps/MtChimney/scripts.pory"
	hidemoneybox
# 112 "data/maps/MtChimney/scripts.pory"
	release
# 113 "data/maps/MtChimney/scripts.pory"
	end
# 114 "data/maps/MtChimney/scripts.pory"

# 115 "data/maps/MtChimney/scripts.pory"
MtChimney_EventScript_BagIsFull::
# 116 "data/maps/MtChimney/scripts.pory"
	msgbox gText_TooBadBagIsFull, MSGBOX_DEFAULT
# 117 "data/maps/MtChimney/scripts.pory"
	hidemoneybox
# 118 "data/maps/MtChimney/scripts.pory"
	release
# 119 "data/maps/MtChimney/scripts.pory"
	end
# 120 "data/maps/MtChimney/scripts.pory"
.else
# 121 "data/maps/MtChimney/scripts.pory"
	hidemoneybox
# 122 "data/maps/MtChimney/scripts.pory"
	giveitem ITEM_LAVA_COOKIE
# 123 "data/maps/MtChimney/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, MtChimney_EventScript_BagIsFull
# 124 "data/maps/MtChimney/scripts.pory"
	release
# 125 "data/maps/MtChimney/scripts.pory"
	end
# 126 "data/maps/MtChimney/scripts.pory"

# 127 "data/maps/MtChimney/scripts.pory"
MtChimney_EventScript_BagIsFull::
# 128 "data/maps/MtChimney/scripts.pory"
	msgbox gText_TooBadBagIsFull, MSGBOX_DEFAULT
# 129 "data/maps/MtChimney/scripts.pory"
	release
# 130 "data/maps/MtChimney/scripts.pory"
	end
# 131 "data/maps/MtChimney/scripts.pory"
.endif @ OW_SHOW_ITEM_DESCRIPTIONS
# 132 "data/maps/MtChimney/scripts.pory"

# 133 "data/maps/MtChimney/scripts.pory"

# 134 "data/maps/MtChimney/scripts.pory"
MtChimney_EventScript_RemoveMoney::
# 135 "data/maps/MtChimney/scripts.pory"
	removemoney 200
# 136 "data/maps/MtChimney/scripts.pory"
	updatemoneybox
# 137 "data/maps/MtChimney/scripts.pory"
	return
# 138 "data/maps/MtChimney/scripts.pory"

# 139 "data/maps/MtChimney/scripts.pory"
MtChimney_EventScript_DeclineLavaCookie::
# 140 "data/maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_OhFineThen, MSGBOX_DEFAULT
# 141 "data/maps/MtChimney/scripts.pory"
	hidemoneybox
# 142 "data/maps/MtChimney/scripts.pory"
	release
# 143 "data/maps/MtChimney/scripts.pory"
	end
# 144 "data/maps/MtChimney/scripts.pory"

# 145 "data/maps/MtChimney/scripts.pory"
MtChimney_EventScript_NotEnoughMoney::
# 146 "data/maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_YouveNotGotTheMoney, MSGBOX_DEFAULT
# 147 "data/maps/MtChimney/scripts.pory"
	hidemoneybox
# 148 "data/maps/MtChimney/scripts.pory"
	release
# 149 "data/maps/MtChimney/scripts.pory"
	end
# 150 "data/maps/MtChimney/scripts.pory"

# 151 "data/maps/MtChimney/scripts.pory"
MtChimney_Movement_ArchieApproachPlayerEast:
# 152 "data/maps/MtChimney/scripts.pory"
	walk_up
# 153 "data/maps/MtChimney/scripts.pory"
	walk_up
# 154 "data/maps/MtChimney/scripts.pory"
	walk_up
# 155 "data/maps/MtChimney/scripts.pory"
	walk_up
# 156 "data/maps/MtChimney/scripts.pory"
	walk_up
# 157 "data/maps/MtChimney/scripts.pory"
	walk_up
# 158 "data/maps/MtChimney/scripts.pory"
	walk_right
# 159 "data/maps/MtChimney/scripts.pory"
	step_end
# 160 "data/maps/MtChimney/scripts.pory"

# 161 "data/maps/MtChimney/scripts.pory"
MtChimney_Movement_ArchieExitEast:
# 162 "data/maps/MtChimney/scripts.pory"
	walk_left
# 163 "data/maps/MtChimney/scripts.pory"
	walk_down
# 164 "data/maps/MtChimney/scripts.pory"
	walk_down
# 165 "data/maps/MtChimney/scripts.pory"
	walk_down
# 166 "data/maps/MtChimney/scripts.pory"
	walk_down
# 167 "data/maps/MtChimney/scripts.pory"
	walk_down
# 168 "data/maps/MtChimney/scripts.pory"
	walk_down
# 169 "data/maps/MtChimney/scripts.pory"
	walk_down
# 170 "data/maps/MtChimney/scripts.pory"
	step_end
# 171 "data/maps/MtChimney/scripts.pory"

# 172 "data/maps/MtChimney/scripts.pory"
MtChimney_Movement_ArchieApproachPlayerNorth:
# 173 "data/maps/MtChimney/scripts.pory"
	walk_up
# 174 "data/maps/MtChimney/scripts.pory"
	walk_up
# 175 "data/maps/MtChimney/scripts.pory"
	walk_up
# 176 "data/maps/MtChimney/scripts.pory"
	walk_up
# 177 "data/maps/MtChimney/scripts.pory"
	walk_up
# 178 "data/maps/MtChimney/scripts.pory"
	walk_right
# 179 "data/maps/MtChimney/scripts.pory"
	walk_right
# 180 "data/maps/MtChimney/scripts.pory"
	step_end
# 181 "data/maps/MtChimney/scripts.pory"

# 182 "data/maps/MtChimney/scripts.pory"
MtChimney_Movement_ArchieExitNorth:
# 183 "data/maps/MtChimney/scripts.pory"
	walk_left
# 184 "data/maps/MtChimney/scripts.pory"
	walk_left
# 185 "data/maps/MtChimney/scripts.pory"
	walk_down
# 186 "data/maps/MtChimney/scripts.pory"
	walk_down
# 187 "data/maps/MtChimney/scripts.pory"
	walk_down
# 188 "data/maps/MtChimney/scripts.pory"
	walk_down
# 189 "data/maps/MtChimney/scripts.pory"
	walk_down
# 190 "data/maps/MtChimney/scripts.pory"
	walk_down
# 191 "data/maps/MtChimney/scripts.pory"
	walk_down
# 192 "data/maps/MtChimney/scripts.pory"
	step_end
# 193 "data/maps/MtChimney/scripts.pory"

# 194 "data/maps/MtChimney/scripts.pory"
MtChimney_Movement_Unused1:
# 195 "data/maps/MtChimney/scripts.pory"
	walk_down
# 196 "data/maps/MtChimney/scripts.pory"
	walk_down
# 197 "data/maps/MtChimney/scripts.pory"
	walk_down
# 198 "data/maps/MtChimney/scripts.pory"
	walk_down
# 199 "data/maps/MtChimney/scripts.pory"
	walk_down
# 200 "data/maps/MtChimney/scripts.pory"
	walk_left
# 201 "data/maps/MtChimney/scripts.pory"
	walk_left
# 202 "data/maps/MtChimney/scripts.pory"
	walk_down
# 203 "data/maps/MtChimney/scripts.pory"
	walk_down
# 204 "data/maps/MtChimney/scripts.pory"
	walk_down
# 205 "data/maps/MtChimney/scripts.pory"
	walk_down
# 206 "data/maps/MtChimney/scripts.pory"
	walk_left
# 207 "data/maps/MtChimney/scripts.pory"
	walk_left
# 208 "data/maps/MtChimney/scripts.pory"
	walk_left
# 209 "data/maps/MtChimney/scripts.pory"
	walk_left
# 210 "data/maps/MtChimney/scripts.pory"
	walk_left
# 211 "data/maps/MtChimney/scripts.pory"
	walk_down
# 212 "data/maps/MtChimney/scripts.pory"
	step_end
# 213 "data/maps/MtChimney/scripts.pory"

# 214 "data/maps/MtChimney/scripts.pory"
MtChimney_Movement_Unused2:
# 215 "data/maps/MtChimney/scripts.pory"
	walk_down
# 216 "data/maps/MtChimney/scripts.pory"
	walk_down
# 217 "data/maps/MtChimney/scripts.pory"
	walk_down
# 218 "data/maps/MtChimney/scripts.pory"
	walk_down
# 219 "data/maps/MtChimney/scripts.pory"
	walk_left
# 220 "data/maps/MtChimney/scripts.pory"
	walk_left
# 221 "data/maps/MtChimney/scripts.pory"
	walk_left
# 222 "data/maps/MtChimney/scripts.pory"
	walk_down
# 223 "data/maps/MtChimney/scripts.pory"
	step_end
# 224 "data/maps/MtChimney/scripts.pory"

# 225 "data/maps/MtChimney/scripts.pory"
MtChimney_Movement_Unused3:
# 226 "data/maps/MtChimney/scripts.pory"
	walk_right
# 227 "data/maps/MtChimney/scripts.pory"
	walk_down
# 228 "data/maps/MtChimney/scripts.pory"
	walk_down
# 229 "data/maps/MtChimney/scripts.pory"
	walk_down
# 230 "data/maps/MtChimney/scripts.pory"
	walk_down
# 231 "data/maps/MtChimney/scripts.pory"
	walk_left
# 232 "data/maps/MtChimney/scripts.pory"
	walk_left
# 233 "data/maps/MtChimney/scripts.pory"
	walk_left
# 234 "data/maps/MtChimney/scripts.pory"
	walk_left
# 235 "data/maps/MtChimney/scripts.pory"
	walk_left
# 236 "data/maps/MtChimney/scripts.pory"
	walk_down
# 237 "data/maps/MtChimney/scripts.pory"
	walk_down
# 238 "data/maps/MtChimney/scripts.pory"
	walk_down
# 239 "data/maps/MtChimney/scripts.pory"
	walk_down
# 240 "data/maps/MtChimney/scripts.pory"
	step_end
# 241 "data/maps/MtChimney/scripts.pory"

# 242 "data/maps/MtChimney/scripts.pory"
MtChimney_Movement_Unused4:
# 243 "data/maps/MtChimney/scripts.pory"
	walk_fast_down
# 244 "data/maps/MtChimney/scripts.pory"
	walk_fast_down
# 245 "data/maps/MtChimney/scripts.pory"
	walk_fast_down
# 246 "data/maps/MtChimney/scripts.pory"
	walk_fast_down
# 247 "data/maps/MtChimney/scripts.pory"
	walk_fast_down
# 248 "data/maps/MtChimney/scripts.pory"
	walk_fast_down
# 249 "data/maps/MtChimney/scripts.pory"
	walk_fast_down
# 250 "data/maps/MtChimney/scripts.pory"
	walk_fast_down
# 251 "data/maps/MtChimney/scripts.pory"
	walk_fast_down
# 252 "data/maps/MtChimney/scripts.pory"
	walk_left
# 253 "data/maps/MtChimney/scripts.pory"
	walk_left
# 254 "data/maps/MtChimney/scripts.pory"
	walk_down
# 255 "data/maps/MtChimney/scripts.pory"
	walk_down
# 256 "data/maps/MtChimney/scripts.pory"
	walk_down
# 257 "data/maps/MtChimney/scripts.pory"
	walk_left
# 258 "data/maps/MtChimney/scripts.pory"
	walk_left
# 259 "data/maps/MtChimney/scripts.pory"
	walk_down
# 260 "data/maps/MtChimney/scripts.pory"
	walk_down
# 261 "data/maps/MtChimney/scripts.pory"
	walk_left
# 262 "data/maps/MtChimney/scripts.pory"
	walk_left
# 263 "data/maps/MtChimney/scripts.pory"
	walk_left
# 264 "data/maps/MtChimney/scripts.pory"
	walk_left
# 265 "data/maps/MtChimney/scripts.pory"
	walk_left
# 266 "data/maps/MtChimney/scripts.pory"
	walk_down
# 267 "data/maps/MtChimney/scripts.pory"
	step_end
# 268 "data/maps/MtChimney/scripts.pory"

# 269 "data/maps/MtChimney/scripts.pory"
MtChimney_Movement_Unused5:
# 270 "data/maps/MtChimney/scripts.pory"
	delay_16
# 271 "data/maps/MtChimney/scripts.pory"
	delay_16
# 272 "data/maps/MtChimney/scripts.pory"
	delay_16
# 273 "data/maps/MtChimney/scripts.pory"
	walk_down
# 274 "data/maps/MtChimney/scripts.pory"
	walk_down
# 275 "data/maps/MtChimney/scripts.pory"
	walk_down
# 276 "data/maps/MtChimney/scripts.pory"
	walk_left
# 277 "data/maps/MtChimney/scripts.pory"
	walk_left
# 278 "data/maps/MtChimney/scripts.pory"
	walk_left
# 279 "data/maps/MtChimney/scripts.pory"
	walk_down
# 280 "data/maps/MtChimney/scripts.pory"
	step_end
# 281 "data/maps/MtChimney/scripts.pory"

# 282 "data/maps/MtChimney/scripts.pory"
MtChimney_Movement_Unused6:
# 283 "data/maps/MtChimney/scripts.pory"
	delay_16
# 284 "data/maps/MtChimney/scripts.pory"
	walk_left
# 285 "data/maps/MtChimney/scripts.pory"
	walk_down
# 286 "data/maps/MtChimney/scripts.pory"
	walk_down
# 287 "data/maps/MtChimney/scripts.pory"
	walk_down
# 288 "data/maps/MtChimney/scripts.pory"
	walk_down
# 289 "data/maps/MtChimney/scripts.pory"
	walk_left
# 290 "data/maps/MtChimney/scripts.pory"
	walk_left
# 291 "data/maps/MtChimney/scripts.pory"
	walk_left
# 292 "data/maps/MtChimney/scripts.pory"
	walk_left
# 293 "data/maps/MtChimney/scripts.pory"
	walk_left
# 294 "data/maps/MtChimney/scripts.pory"
	walk_down
# 295 "data/maps/MtChimney/scripts.pory"
	walk_down
# 296 "data/maps/MtChimney/scripts.pory"
	walk_down
# 297 "data/maps/MtChimney/scripts.pory"
	walk_down
# 298 "data/maps/MtChimney/scripts.pory"
	step_end
# 299 "data/maps/MtChimney/scripts.pory"

# 300 "data/maps/MtChimney/scripts.pory"
MtChimney_Movement_Unused7:
# 301 "data/maps/MtChimney/scripts.pory"
	delay_16
# 302 "data/maps/MtChimney/scripts.pory"
	walk_left
# 303 "data/maps/MtChimney/scripts.pory"
	walk_left
# 304 "data/maps/MtChimney/scripts.pory"
	walk_down
# 305 "data/maps/MtChimney/scripts.pory"
	walk_down
# 306 "data/maps/MtChimney/scripts.pory"
	walk_down
# 307 "data/maps/MtChimney/scripts.pory"
	walk_left
# 308 "data/maps/MtChimney/scripts.pory"
	walk_left
# 309 "data/maps/MtChimney/scripts.pory"
	walk_down
# 310 "data/maps/MtChimney/scripts.pory"
	walk_down
# 311 "data/maps/MtChimney/scripts.pory"
	walk_left
# 312 "data/maps/MtChimney/scripts.pory"
	walk_left
# 313 "data/maps/MtChimney/scripts.pory"
	walk_left
# 314 "data/maps/MtChimney/scripts.pory"
	walk_left
# 315 "data/maps/MtChimney/scripts.pory"
	walk_left
# 316 "data/maps/MtChimney/scripts.pory"
	walk_down
# 317 "data/maps/MtChimney/scripts.pory"
	step_end
# 318 "data/maps/MtChimney/scripts.pory"

# 319 "data/maps/MtChimney/scripts.pory"
MtChimney_Movement_Unused8:
# 320 "data/maps/MtChimney/scripts.pory"
	delay_16
# 321 "data/maps/MtChimney/scripts.pory"
	walk_down
# 322 "data/maps/MtChimney/scripts.pory"
	walk_left
# 323 "data/maps/MtChimney/scripts.pory"
	walk_left
# 324 "data/maps/MtChimney/scripts.pory"
	walk_left
# 325 "data/maps/MtChimney/scripts.pory"
	walk_left
# 326 "data/maps/MtChimney/scripts.pory"
	walk_in_place_faster_down
# 327 "data/maps/MtChimney/scripts.pory"
	step_end
# 328 "data/maps/MtChimney/scripts.pory"

# 329 "data/maps/MtChimney/scripts.pory"
MtChimney_Movement_Unused9:
# 330 "data/maps/MtChimney/scripts.pory"
	walk_down
# 331 "data/maps/MtChimney/scripts.pory"
	walk_down
# 332 "data/maps/MtChimney/scripts.pory"
	walk_down
# 333 "data/maps/MtChimney/scripts.pory"
	walk_down
# 334 "data/maps/MtChimney/scripts.pory"
	walk_left
# 335 "data/maps/MtChimney/scripts.pory"
	walk_left
# 336 "data/maps/MtChimney/scripts.pory"
	walk_left
# 337 "data/maps/MtChimney/scripts.pory"
	walk_left
# 338 "data/maps/MtChimney/scripts.pory"
	walk_left
# 339 "data/maps/MtChimney/scripts.pory"
	walk_down
# 340 "data/maps/MtChimney/scripts.pory"
	walk_down
# 341 "data/maps/MtChimney/scripts.pory"
	walk_down
# 342 "data/maps/MtChimney/scripts.pory"
	walk_down
# 343 "data/maps/MtChimney/scripts.pory"
	step_end
# 344 "data/maps/MtChimney/scripts.pory"

# 345 "data/maps/MtChimney/scripts.pory"
MtChimney_Movement_Unused10:
# 346 "data/maps/MtChimney/scripts.pory"
	walk_down
# 347 "data/maps/MtChimney/scripts.pory"
	step_end
# 348 "data/maps/MtChimney/scripts.pory"

# 349 "data/maps/MtChimney/scripts.pory"
MtChimney_Movement_Unused11:
# 350 "data/maps/MtChimney/scripts.pory"
	walk_down
# 351 "data/maps/MtChimney/scripts.pory"
	walk_down
# 352 "data/maps/MtChimney/scripts.pory"
	walk_down
# 353 "data/maps/MtChimney/scripts.pory"
	walk_down
# 354 "data/maps/MtChimney/scripts.pory"
	walk_down
# 355 "data/maps/MtChimney/scripts.pory"
	walk_down
# 356 "data/maps/MtChimney/scripts.pory"
	walk_down
# 357 "data/maps/MtChimney/scripts.pory"
	step_end
# 358 "data/maps/MtChimney/scripts.pory"

# 359 "data/maps/MtChimney/scripts.pory"
MtChimney_Movement_Unused12:
# 360 "data/maps/MtChimney/scripts.pory"
	delay_16
# 361 "data/maps/MtChimney/scripts.pory"
	delay_16
# 362 "data/maps/MtChimney/scripts.pory"
	walk_in_place_faster_left
# 363 "data/maps/MtChimney/scripts.pory"
	delay_16
# 364 "data/maps/MtChimney/scripts.pory"
	walk_down
# 365 "data/maps/MtChimney/scripts.pory"
	walk_down
# 366 "data/maps/MtChimney/scripts.pory"
	walk_down
# 367 "data/maps/MtChimney/scripts.pory"
	walk_down
# 368 "data/maps/MtChimney/scripts.pory"
	walk_down
# 369 "data/maps/MtChimney/scripts.pory"
	step_end
# 370 "data/maps/MtChimney/scripts.pory"

# 371 "data/maps/MtChimney/scripts.pory"
MtChimney_Movement_Unused13:
# 372 "data/maps/MtChimney/scripts.pory"
	delay_16
# 373 "data/maps/MtChimney/scripts.pory"
	delay_16
# 374 "data/maps/MtChimney/scripts.pory"
	delay_16
# 375 "data/maps/MtChimney/scripts.pory"
	delay_16
# 376 "data/maps/MtChimney/scripts.pory"
	delay_16
# 377 "data/maps/MtChimney/scripts.pory"
	delay_16
# 378 "data/maps/MtChimney/scripts.pory"
	walk_in_place_faster_left
# 379 "data/maps/MtChimney/scripts.pory"
	delay_16
# 380 "data/maps/MtChimney/scripts.pory"
	walk_down
# 381 "data/maps/MtChimney/scripts.pory"
	walk_down
# 382 "data/maps/MtChimney/scripts.pory"
	step_end
# 383 "data/maps/MtChimney/scripts.pory"

# 384 "data/maps/MtChimney/scripts.pory"
MtChimney_Movement_Unused14:
# 385 "data/maps/MtChimney/scripts.pory"
	lock_facing_direction
# 386 "data/maps/MtChimney/scripts.pory"
	walk_fast_left
# 387 "data/maps/MtChimney/scripts.pory"
	unlock_facing_direction
# 388 "data/maps/MtChimney/scripts.pory"
	face_right
# 389 "data/maps/MtChimney/scripts.pory"
	step_end
# 390 "data/maps/MtChimney/scripts.pory"

# 391 "data/maps/MtChimney/scripts.pory"
MtChimney_Movement_Unused15:
# 392 "data/maps/MtChimney/scripts.pory"
	walk_left
# 393 "data/maps/MtChimney/scripts.pory"
	walk_in_place_faster_right
# 394 "data/maps/MtChimney/scripts.pory"
	delay_16
# 395 "data/maps/MtChimney/scripts.pory"
	step_end
# 396 "data/maps/MtChimney/scripts.pory"

# 397 "data/maps/MtChimney/scripts.pory"
MtChimney_EventScript_BusyAquaGrunt1::
# 398 "data/maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_MagmaOutnumbersUs, MSGBOX_SIGN
# 399 "data/maps/MtChimney/scripts.pory"
	end
# 400 "data/maps/MtChimney/scripts.pory"

# 401 "data/maps/MtChimney/scripts.pory"
MtChimney_EventScript_BusyAquaGrunt2::
# 402 "data/maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_LessHabitatForWaterPokemon, MSGBOX_SIGN
# 403 "data/maps/MtChimney/scripts.pory"
	end
# 404 "data/maps/MtChimney/scripts.pory"

# 405 "data/maps/MtChimney/scripts.pory"
MtChimney_EventScript_BusyAquaGrunt3::
# 406 "data/maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_MagmasNameSimilar, MSGBOX_SIGN
# 407 "data/maps/MtChimney/scripts.pory"
	end
# 408 "data/maps/MtChimney/scripts.pory"

# 409 "data/maps/MtChimney/scripts.pory"
MtChimney_EventScript_Tabitha::
# 410 "data/maps/MtChimney/scripts.pory"
	trainerbattle_single TRAINER_TABITHA_MT_CHIMNEY, MtChimney_Text_TabithaIntro, MtChimney_Text_TabithaDefeat
# 411 "data/maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_TabithaPostBattle, MSGBOX_AUTOCLOSE
# 412 "data/maps/MtChimney/scripts.pory"
	end
# 413 "data/maps/MtChimney/scripts.pory"

# 414 "data/maps/MtChimney/scripts.pory"
MtChimney_EventScript_Grunt2::
# 415 "data/maps/MtChimney/scripts.pory"
	trainerbattle_single TRAINER_GRUNT_MT_CHIMNEY_2, MtChimney_Text_Grunt2Intro, MtChimney_Text_Grunt2Defeat
# 416 "data/maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_Grunt2PostBattle, MSGBOX_AUTOCLOSE
# 417 "data/maps/MtChimney/scripts.pory"
	end
# 418 "data/maps/MtChimney/scripts.pory"

# 419 "data/maps/MtChimney/scripts.pory"
MtChimney_EventScript_BusyMagmaGrunt1::
# 420 "data/maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_TeamAquaAlwaysMessingWithPlans, MSGBOX_SIGN
# 421 "data/maps/MtChimney/scripts.pory"
	end
# 422 "data/maps/MtChimney/scripts.pory"

# 423 "data/maps/MtChimney/scripts.pory"
MtChimney_EventScript_BusyMagmaGrunt2::
# 424 "data/maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_MeteoritesPackAmazingPower, MSGBOX_SIGN
# 425 "data/maps/MtChimney/scripts.pory"
	end
# 426 "data/maps/MtChimney/scripts.pory"

# 427 "data/maps/MtChimney/scripts.pory"
MtChimney_EventScript_BusyMagmaGrunt3::
# 428 "data/maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_YouBetterNotMessWithUs, MSGBOX_SIGN
# 429 "data/maps/MtChimney/scripts.pory"
	end
# 430 "data/maps/MtChimney/scripts.pory"

# 431 "data/maps/MtChimney/scripts.pory"
MtChimney_EventScript_BusyMagmaGrunt4::
# 432 "data/maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_AquasNameSimilar, MSGBOX_SIGN
# 433 "data/maps/MtChimney/scripts.pory"
	end
# 434 "data/maps/MtChimney/scripts.pory"

# 435 "data/maps/MtChimney/scripts.pory"
MtChimney_EventScript_BusyMagmaGrunt5::
# 436 "data/maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_DouseThemInFire, MSGBOX_SIGN
# 437 "data/maps/MtChimney/scripts.pory"
	end
# 438 "data/maps/MtChimney/scripts.pory"

# 439 "data/maps/MtChimney/scripts.pory"
MtChimney_EventScript_BusyMagmaGrunt6::
# 440 "data/maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_KeepMakingMoreLand, MSGBOX_SIGN
# 441 "data/maps/MtChimney/scripts.pory"
	end
# 442 "data/maps/MtChimney/scripts.pory"

# 443 "data/maps/MtChimney/scripts.pory"
MtChimney_EventScript_MagmaPoochyena::
# 444 "data/maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_Bufoh, MSGBOX_SIGN
# 445 "data/maps/MtChimney/scripts.pory"
	end
# 446 "data/maps/MtChimney/scripts.pory"

# 447 "data/maps/MtChimney/scripts.pory"
MtChimney_EventScript_AquaPoochyena::
# 448 "data/maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_Bushaa, MSGBOX_SIGN
# 449 "data/maps/MtChimney/scripts.pory"
	end
# 450 "data/maps/MtChimney/scripts.pory"

# 451 "data/maps/MtChimney/scripts.pory"
MtChimney_EventScript_MeteoriteMachine::
# 452 "data/maps/MtChimney/scripts.pory"
	lockall
# 453 "data/maps/MtChimney/scripts.pory"
	goto_if_unset FLAG_DEFEATED_EVIL_TEAM_MT_CHIMNEY, MtChimney_EventScript_MachineOn
# 454 "data/maps/MtChimney/scripts.pory"
	goto_if_set FLAG_RECEIVED_METEORITE, MtChimney_EventScript_MachineOff
# 455 "data/maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_RemoveTheMeteorite, MSGBOX_YESNO
# 456 "data/maps/MtChimney/scripts.pory"
	goto_if_eq VAR_RESULT, NO, MtChimney_EventScript_LeaveMeteoriteAlone
# 457 "data/maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_PlayerRemovedMeteorite, MSGBOX_DEFAULT
# 458 "data/maps/MtChimney/scripts.pory"
	giveitem ITEM_METEORITE
# 459 "data/maps/MtChimney/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
# 460 "data/maps/MtChimney/scripts.pory"
	setflag FLAG_RECEIVED_METEORITE
# 461 "data/maps/MtChimney/scripts.pory"
	releaseall
# 462 "data/maps/MtChimney/scripts.pory"
	end
# 463 "data/maps/MtChimney/scripts.pory"

# 464 "data/maps/MtChimney/scripts.pory"
MtChimney_EventScript_LeaveMeteoriteAlone::
# 465 "data/maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_PlayerLeftMeteorite, MSGBOX_DEFAULT
# 466 "data/maps/MtChimney/scripts.pory"
	releaseall
# 467 "data/maps/MtChimney/scripts.pory"
	end
# 468 "data/maps/MtChimney/scripts.pory"

# 469 "data/maps/MtChimney/scripts.pory"
MtChimney_EventScript_MachineOff::
# 470 "data/maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_MachineMakesNoResponse, MSGBOX_DEFAULT
# 471 "data/maps/MtChimney/scripts.pory"
	releaseall
# 472 "data/maps/MtChimney/scripts.pory"
	end
# 473 "data/maps/MtChimney/scripts.pory"

# 474 "data/maps/MtChimney/scripts.pory"
MtChimney_EventScript_MachineOn::
# 475 "data/maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_MetoriteFittedOnMachine, MSGBOX_DEFAULT
# 476 "data/maps/MtChimney/scripts.pory"
	releaseall
# 477 "data/maps/MtChimney/scripts.pory"
	end
# 478 "data/maps/MtChimney/scripts.pory"

# 479 "data/maps/MtChimney/scripts.pory"
MtChimney_EventScript_RouteSign::
# 480 "data/maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_RouteSign, MSGBOX_SIGN
# 481 "data/maps/MtChimney/scripts.pory"
	end
# 482 "data/maps/MtChimney/scripts.pory"

# 483 "data/maps/MtChimney/scripts.pory"
MtChimney_EventScript_Shelby::
# 484 "data/maps/MtChimney/scripts.pory"
	trainerbattle_single TRAINER_SHELBY_1, MtChimney_Text_ShelbyIntro, MtChimney_Text_ShelbyDefeat, MtChimney_EventScript_DefeatedShelby
# 485 "data/maps/MtChimney/scripts.pory"
	specialvar VAR_RESULT, ShouldTryRematchBattle
# 486 "data/maps/MtChimney/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, MtChimney_EventScript_RematchShelby
# 487 "data/maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_ShelbyPostBattle, MSGBOX_DEFAULT
# 488 "data/maps/MtChimney/scripts.pory"
	release
# 489 "data/maps/MtChimney/scripts.pory"
	end
# 490 "data/maps/MtChimney/scripts.pory"

# 491 "data/maps/MtChimney/scripts.pory"
MtChimney_EventScript_DefeatedShelby::
# 492 "data/maps/MtChimney/scripts.pory"
	special PlayerFaceTrainerAfterBattle
# 493 "data/maps/MtChimney/scripts.pory"
	waitmovement 0
# 494 "data/maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_ShelbyRegister, MSGBOX_DEFAULT
# 495 "data/maps/MtChimney/scripts.pory"
	register_matchcall TRAINER_SHELBY_1
# 496 "data/maps/MtChimney/scripts.pory"
	release
# 497 "data/maps/MtChimney/scripts.pory"
	end
# 498 "data/maps/MtChimney/scripts.pory"

# 499 "data/maps/MtChimney/scripts.pory"
MtChimney_EventScript_RematchShelby::
# 500 "data/maps/MtChimney/scripts.pory"
	trainerbattle_rematch TRAINER_SHELBY_1, MtChimney_Text_ShelbyRematchIntro, MtChimney_Text_ShelbyRematchDefeat
# 501 "data/maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_ShelbyPostRematch, MSGBOX_AUTOCLOSE
# 502 "data/maps/MtChimney/scripts.pory"
	end
# 503 "data/maps/MtChimney/scripts.pory"

# 504 "data/maps/MtChimney/scripts.pory"
MtChimney_EventScript_Melissa::
# 505 "data/maps/MtChimney/scripts.pory"
	trainerbattle_single TRAINER_MELISSA, MtChimney_Text_MelissaIntro, MtChimney_Text_MelissaDefeat
# 506 "data/maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_MelissaPostBattle, MSGBOX_AUTOCLOSE
# 507 "data/maps/MtChimney/scripts.pory"
	end
# 508 "data/maps/MtChimney/scripts.pory"

# 509 "data/maps/MtChimney/scripts.pory"
MtChimney_EventScript_Sheila::
# 510 "data/maps/MtChimney/scripts.pory"
	trainerbattle_single TRAINER_SHEILA, MtChimney_Text_SheilaIntro, MtChimney_Text_SheilaDefeat
# 511 "data/maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_SheilaPostBattle, MSGBOX_AUTOCLOSE
# 512 "data/maps/MtChimney/scripts.pory"
	end
# 513 "data/maps/MtChimney/scripts.pory"

# 514 "data/maps/MtChimney/scripts.pory"
MtChimney_EventScript_Shirley::
# 515 "data/maps/MtChimney/scripts.pory"
	trainerbattle_single TRAINER_SHIRLEY, MtChimney_Text_ShirleyIntro, MtChimney_Text_ShirleyDefeat
# 516 "data/maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_ShirleyPostBattle, MSGBOX_AUTOCLOSE
# 517 "data/maps/MtChimney/scripts.pory"
	end
# 518 "data/maps/MtChimney/scripts.pory"

# 519 "data/maps/MtChimney/scripts.pory"
MtChimney_EventScript_Grunt1::
# 520 "data/maps/MtChimney/scripts.pory"
	trainerbattle_single TRAINER_GRUNT_MT_CHIMNEY_1, MtChimney_Text_Grunt1Intro, MtChimney_Text_Grunt1Defeat
# 521 "data/maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_Grunt1PostBattle, MSGBOX_AUTOCLOSE
# 522 "data/maps/MtChimney/scripts.pory"
	end
# 523 "data/maps/MtChimney/scripts.pory"

# 524 "data/maps/MtChimney/scripts.pory"
MtChimney_EventScript_Sawyer::
# 525 "data/maps/MtChimney/scripts.pory"
	trainerbattle_single TRAINER_SAWYER_1, MtChimney_Text_SawyerIntro, MtChimney_Text_SawyerDefeat, MtChimney_EventScript_SawyerDefeated
# 526 "data/maps/MtChimney/scripts.pory"
	specialvar VAR_RESULT, ShouldTryRematchBattle
# 527 "data/maps/MtChimney/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, MtChimney_EventScript_SawyerRematch
# 528 "data/maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_SawyerPostBattle, MSGBOX_DEFAULT
# 529 "data/maps/MtChimney/scripts.pory"
	release
# 530 "data/maps/MtChimney/scripts.pory"
	end
# 531 "data/maps/MtChimney/scripts.pory"

# 532 "data/maps/MtChimney/scripts.pory"
MtChimney_EventScript_SawyerDefeated::
# 533 "data/maps/MtChimney/scripts.pory"
	special PlayerFaceTrainerAfterBattle
# 534 "data/maps/MtChimney/scripts.pory"
	waitmovement 0
# 535 "data/maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_SawyerRegister, MSGBOX_DEFAULT
# 536 "data/maps/MtChimney/scripts.pory"
	register_matchcall TRAINER_SAWYER_1
# 537 "data/maps/MtChimney/scripts.pory"
	release
# 538 "data/maps/MtChimney/scripts.pory"
	end
# 539 "data/maps/MtChimney/scripts.pory"

# 540 "data/maps/MtChimney/scripts.pory"
MtChimney_EventScript_SawyerRematch::
# 541 "data/maps/MtChimney/scripts.pory"
	trainerbattle_rematch TRAINER_SAWYER_1, MtChimney_Text_SawyerRematchIntro, MtChimney_Text_SawyerRematchDefeat
# 542 "data/maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_SawyerPostRematch, MSGBOX_AUTOCLOSE
# 543 "data/maps/MtChimney/scripts.pory"
	end
# 544 "data/maps/MtChimney/scripts.pory"

# 545 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_MeteoriteWillActivateVolcano:
# 546 "data/maps/MtChimney/scripts.pory"
	.string "The power contained in the METEORITE…\p"
# 547 "data/maps/MtChimney/scripts.pory"
	.string "By amplifying its power with this\n"
# 548 "data/maps/MtChimney/scripts.pory"
	.string "machine, MT. CHIMNEY's volcanic\l"
# 549 "data/maps/MtChimney/scripts.pory"
	.string "activity will instantly intensify…\p"
# 550 "data/maps/MtChimney/scripts.pory"
	.string "Its energy will grow deep inside\n"
# 551 "data/maps/MtChimney/scripts.pory"
	.string "the crater and…\l"
# 552 "data/maps/MtChimney/scripts.pory"
	.string "Fufufu…$"
# 553 "data/maps/MtChimney/scripts.pory"

# 554 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_MaxieIntro:
# 555 "data/maps/MtChimney/scripts.pory"
	.string "MAXIE: Hm?\n"
# 556 "data/maps/MtChimney/scripts.pory"
	.string "Who are you?\p"
# 557 "data/maps/MtChimney/scripts.pory"
	.string "… … … … … …\n"
# 558 "data/maps/MtChimney/scripts.pory"
	.string "… … … … … …\p"
# 559 "data/maps/MtChimney/scripts.pory"
	.string "I'd heard ARCHIE bemoaning a child\n"
# 560 "data/maps/MtChimney/scripts.pory"
	.string "who's been meddling in TEAM AQUA's\l"
# 561 "data/maps/MtChimney/scripts.pory"
	.string "affairs.\p"
# 562 "data/maps/MtChimney/scripts.pory"
	.string "It must be you he meant.\p"
# 563 "data/maps/MtChimney/scripts.pory"
	.string "Humph! So you're thinking of\n"
# 564 "data/maps/MtChimney/scripts.pory"
	.string "interfering with us, TEAM MAGMA?\p"
# 565 "data/maps/MtChimney/scripts.pory"
	.string "Now you listen.\n"
# 566 "data/maps/MtChimney/scripts.pory"
	.string "Long ago, living things used the\l"
# 567 "data/maps/MtChimney/scripts.pory"
	.string "land to live and grow.\p"
# 568 "data/maps/MtChimney/scripts.pory"
	.string "That is why land is all important!\n"
# 569 "data/maps/MtChimney/scripts.pory"
	.string "It is the cradle of all!\p"
# 570 "data/maps/MtChimney/scripts.pory"
	.string "That is why TEAM MAGMA is dedicated\n"
# 571 "data/maps/MtChimney/scripts.pory"
	.string "to the expansion of the land mass.\p"
# 572 "data/maps/MtChimney/scripts.pory"
	.string "It is for further advancement of\n"
# 573 "data/maps/MtChimney/scripts.pory"
	.string "humankind and POKéMON!\p"
# 574 "data/maps/MtChimney/scripts.pory"
	.string "And for that, we need the power of\n"
# 575 "data/maps/MtChimney/scripts.pory"
	.string "what sleeps within this mountain…\p"
# 576 "data/maps/MtChimney/scripts.pory"
	.string "Oh! There was no need for you to\n"
# 577 "data/maps/MtChimney/scripts.pory"
	.string "learn that much.\p"
# 578 "data/maps/MtChimney/scripts.pory"
	.string "But, no matter!\n"
# 579 "data/maps/MtChimney/scripts.pory"
	.string "I'll teach you the consequences of\l"
# 580 "data/maps/MtChimney/scripts.pory"
	.string "meddling in our grand design!$"
# 581 "data/maps/MtChimney/scripts.pory"

# 582 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_MaxieDefeat:
# 583 "data/maps/MtChimney/scripts.pory"
	.string "What?!\p"
# 584 "data/maps/MtChimney/scripts.pory"
	.string "I, MAXIE, was caught off guard?!$"
# 585 "data/maps/MtChimney/scripts.pory"

# 586 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_MaxieYouHaventSeenLastOfMagma:
# 587 "data/maps/MtChimney/scripts.pory"
	.string "MAXIE: But, enough.\n"
# 588 "data/maps/MtChimney/scripts.pory"
	.string "I will back off this time.\p"
# 589 "data/maps/MtChimney/scripts.pory"
	.string "But don't think that this is the last\n"
# 590 "data/maps/MtChimney/scripts.pory"
	.string "you've seen of TEAM MAGMA.\p"
# 591 "data/maps/MtChimney/scripts.pory"
	.string "Fufufu…\p"
# 592 "data/maps/MtChimney/scripts.pory"
	.string "Even without the METEORITE, if we\n"
# 593 "data/maps/MtChimney/scripts.pory"
	.string "obtain that ORB… Fufufu…$"
# 594 "data/maps/MtChimney/scripts.pory"

# 595 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_TabithaIntro:
# 596 "data/maps/MtChimney/scripts.pory"
	.string "Hehehe!\p"
# 597 "data/maps/MtChimney/scripts.pory"
	.string "So you've come all the way here!\p"
# 598 "data/maps/MtChimney/scripts.pory"
	.string "But you're too late!\n"
# 599 "data/maps/MtChimney/scripts.pory"
	.string "I've already delivered the METEORITE\l"
# 600 "data/maps/MtChimney/scripts.pory"
	.string "from METEOR FALLS to the BOSS!$"
# 601 "data/maps/MtChimney/scripts.pory"

# 602 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_TabithaDefeat:
# 603 "data/maps/MtChimney/scripts.pory"
	.string "Hehehe…\p"
# 604 "data/maps/MtChimney/scripts.pory"
	.string "Even though I've lost, if our leader\n"
# 605 "data/maps/MtChimney/scripts.pory"
	.string "awakens that thing…$"
# 606 "data/maps/MtChimney/scripts.pory"

# 607 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_TabithaPostBattle:
# 608 "data/maps/MtChimney/scripts.pory"
	.string "BOSS, hurry!\n"
# 609 "data/maps/MtChimney/scripts.pory"
	.string "Give it the METEORITE's energy!\p"
# 610 "data/maps/MtChimney/scripts.pory"
	.string "Hehehe…$"
# 611 "data/maps/MtChimney/scripts.pory"

# 612 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_Grunt2Intro:
# 613 "data/maps/MtChimney/scripts.pory"
	.string "We of TEAM MAGMA are working hard for\n"
# 614 "data/maps/MtChimney/scripts.pory"
	.string "everyone's sake.\p"
# 615 "data/maps/MtChimney/scripts.pory"
	.string "Like, if that thing's power made more\n"
# 616 "data/maps/MtChimney/scripts.pory"
	.string "land, there'd be more places to live.\p"
# 617 "data/maps/MtChimney/scripts.pory"
	.string "Everyone'd be happy!$"
# 618 "data/maps/MtChimney/scripts.pory"

# 619 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_Grunt2Defeat:
# 620 "data/maps/MtChimney/scripts.pory"
	.string "Hunh?\n"
# 621 "data/maps/MtChimney/scripts.pory"
	.string "What do you mean I lost?$"
# 622 "data/maps/MtChimney/scripts.pory"

# 623 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_Grunt2PostBattle:
# 624 "data/maps/MtChimney/scripts.pory"
	.string "Our BOSS says, “It will make everyone\n"
# 625 "data/maps/MtChimney/scripts.pory"
	.string "happy.”\p"
# 626 "data/maps/MtChimney/scripts.pory"
	.string "But why does everyone keep getting\n"
# 627 "data/maps/MtChimney/scripts.pory"
	.string "in our way?$"
# 628 "data/maps/MtChimney/scripts.pory"

# 629 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_Grunt1Intro:
# 630 "data/maps/MtChimney/scripts.pory"
	.string "If there were more land, I'd be able\n"
# 631 "data/maps/MtChimney/scripts.pory"
	.string "to get a big house of my own!\p"
# 632 "data/maps/MtChimney/scripts.pory"
	.string "I'm going to build it on hardened lava!$"
# 633 "data/maps/MtChimney/scripts.pory"

# 634 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_Grunt1Defeat:
# 635 "data/maps/MtChimney/scripts.pory"
	.string "My dream of a big house…$"
# 636 "data/maps/MtChimney/scripts.pory"

# 637 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_Grunt1PostBattle:
# 638 "data/maps/MtChimney/scripts.pory"
	.string "A kid like you, you ought to be\n"
# 639 "data/maps/MtChimney/scripts.pory"
	.string "splashing about in the waves!$"
# 640 "data/maps/MtChimney/scripts.pory"

# 641 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_TeamAquaAlwaysMessingWithPlans:
# 642 "data/maps/MtChimney/scripts.pory"
	.string "That annoying TEAM AQUA…\n"
# 643 "data/maps/MtChimney/scripts.pory"
	.string "They always mess with our plans!$"
# 644 "data/maps/MtChimney/scripts.pory"

# 645 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_MeteoritesPackAmazingPower:
# 646 "data/maps/MtChimney/scripts.pory"
	.string "METEORITES pack amazing power!$"
# 647 "data/maps/MtChimney/scripts.pory"

# 648 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_YouBetterNotMessWithUs:
# 649 "data/maps/MtChimney/scripts.pory"
	.string "You'd better not mess with us!\p"
# 650 "data/maps/MtChimney/scripts.pory"
	.string "We're trying to awaken that thing\n"
# 651 "data/maps/MtChimney/scripts.pory"
	.string "for the benefit of everyone!$"
# 652 "data/maps/MtChimney/scripts.pory"

# 653 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_AquasNameSimilar:
# 654 "data/maps/MtChimney/scripts.pory"
	.string "We're TEAM MAGMA!\p"
# 655 "data/maps/MtChimney/scripts.pory"
	.string "They're TEAM AQUA!\p"
# 656 "data/maps/MtChimney/scripts.pory"
	.string "It totally annoys me that they'd\n"
# 657 "data/maps/MtChimney/scripts.pory"
	.string "use a name like ours!$"
# 658 "data/maps/MtChimney/scripts.pory"

# 659 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_DouseThemInFire:
# 660 "data/maps/MtChimney/scripts.pory"
	.string "Yeah!\n"
# 661 "data/maps/MtChimney/scripts.pory"
	.string "Douse them in fire!$"
# 662 "data/maps/MtChimney/scripts.pory"

# 663 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_KeepMakingMoreLand:
# 664 "data/maps/MtChimney/scripts.pory"
	.string "We're going to keep making more land!$"
# 665 "data/maps/MtChimney/scripts.pory"

# 666 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_Bufoh:
# 667 "data/maps/MtChimney/scripts.pory"
	.string "Bufoh!$"
# 668 "data/maps/MtChimney/scripts.pory"

# 669 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_ArchieGoStopTeamMagma:
# 670 "data/maps/MtChimney/scripts.pory"
	.string "ARCHIE: Grr, {PLAYER}!\n"
# 671 "data/maps/MtChimney/scripts.pory"
	.string "I should've guessed you'd show up!\p"
# 672 "data/maps/MtChimney/scripts.pory"
	.string "See for yourself what the fanatics\n"
# 673 "data/maps/MtChimney/scripts.pory"
	.string "of TEAM MAGMA are up to!\p"
# 674 "data/maps/MtChimney/scripts.pory"
	.string "They're trying to inject the stolen\n"
# 675 "data/maps/MtChimney/scripts.pory"
	.string "METEORITE's power into the volcano!\p"
# 676 "data/maps/MtChimney/scripts.pory"
	.string "Doing something like that will cause\n"
# 677 "data/maps/MtChimney/scripts.pory"
	.string "the volcano's eruption!$"
# 678 "data/maps/MtChimney/scripts.pory"

# 679 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_ArchieIHaveMyHandsFull:
# 680 "data/maps/MtChimney/scripts.pory"
	.string "ARCHIE: Grrr…\p"
# 681 "data/maps/MtChimney/scripts.pory"
	.string "I want to stop that MAXIE,\n"
# 682 "data/maps/MtChimney/scripts.pory"
	.string "but I can't!\p"
# 683 "data/maps/MtChimney/scripts.pory"
	.string "Not when I have my hands full battling\n"
# 684 "data/maps/MtChimney/scripts.pory"
	.string "three opponents at once!$"
# 685 "data/maps/MtChimney/scripts.pory"

# 686 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_ArchieThankYou:
# 687 "data/maps/MtChimney/scripts.pory"
	.string "ARCHIE: {PLAYER}!\n"
# 688 "data/maps/MtChimney/scripts.pory"
	.string "Thank you!\p"
# 689 "data/maps/MtChimney/scripts.pory"
	.string "With your help, we thwarted TEAM\n"
# 690 "data/maps/MtChimney/scripts.pory"
	.string "MAGMA's destructive plan!\p"
# 691 "data/maps/MtChimney/scripts.pory"
	.string "But… You…\n"
# 692 "data/maps/MtChimney/scripts.pory"
	.string "Whose side are you on?\p"
# 693 "data/maps/MtChimney/scripts.pory"
	.string "Ah, it doesn't matter.\p"
# 694 "data/maps/MtChimney/scripts.pory"
	.string "We will remain vigilant and keep up\n"
# 695 "data/maps/MtChimney/scripts.pory"
	.string "our pursuit of TEAM MAGMA.\p"
# 696 "data/maps/MtChimney/scripts.pory"
	.string "{PLAYER}, we shall meet again!$"
# 697 "data/maps/MtChimney/scripts.pory"

# 698 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_MagmaOutnumbersUs:
# 699 "data/maps/MtChimney/scripts.pory"
	.string "Darn… TEAM MAGMA outnumbers us!\n"
# 700 "data/maps/MtChimney/scripts.pory"
	.string "We can't keep up with them!$"
# 701 "data/maps/MtChimney/scripts.pory"

# 702 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_LessHabitatForWaterPokemon:
# 703 "data/maps/MtChimney/scripts.pory"
	.string "If they expand the land, there'll be\n"
# 704 "data/maps/MtChimney/scripts.pory"
	.string "less habitats for WATER POKéMON!$"
# 705 "data/maps/MtChimney/scripts.pory"

# 706 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_MagmasNameSimilar:
# 707 "data/maps/MtChimney/scripts.pory"
	.string "We're TEAM AQUA!\p"
# 708 "data/maps/MtChimney/scripts.pory"
	.string "They're TEAM MAGMA!\p"
# 709 "data/maps/MtChimney/scripts.pory"
	.string "It burns me up that they'd use such\n"
# 710 "data/maps/MtChimney/scripts.pory"
	.string "a confusing name!$"
# 711 "data/maps/MtChimney/scripts.pory"

# 712 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_Bushaa:
# 713 "data/maps/MtChimney/scripts.pory"
	.string "Bushaa!$"
# 714 "data/maps/MtChimney/scripts.pory"

# 715 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_LavaCookiesJust200:
# 716 "data/maps/MtChimney/scripts.pory"
	.string "LAVA COOKIES are MT. CHIMNEY's local\n"
# 717 "data/maps/MtChimney/scripts.pory"
	.string "specialty.\p"
# 718 "data/maps/MtChimney/scripts.pory"
	.string "Try one. It's just ¥200.$"
# 719 "data/maps/MtChimney/scripts.pory"

# 720 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_ThankYouDear:
# 721 "data/maps/MtChimney/scripts.pory"
	.string "Thank you, dear!$"
# 722 "data/maps/MtChimney/scripts.pory"

# 723 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_YouveNotGotTheMoney:
# 724 "data/maps/MtChimney/scripts.pory"
	.string "Oh, dear. You can't buy a thing if\n"
# 725 "data/maps/MtChimney/scripts.pory"
	.string "you've not got the money.$"
# 726 "data/maps/MtChimney/scripts.pory"

# 727 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_OhFineThen:
# 728 "data/maps/MtChimney/scripts.pory"
	.string "Oh, fine then.$"
# 729 "data/maps/MtChimney/scripts.pory"

# 730 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_MetoriteFittedOnMachine:
# 731 "data/maps/MtChimney/scripts.pory"
	.string "A METEORITE is fitted on a mysterious\n"
# 732 "data/maps/MtChimney/scripts.pory"
	.string "machine…\p"
# 733 "data/maps/MtChimney/scripts.pory"
	.string "The machine seems to be storing\n"
# 734 "data/maps/MtChimney/scripts.pory"
	.string "energy in the METEORITE.$"
# 735 "data/maps/MtChimney/scripts.pory"

# 736 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_RemoveTheMeteorite:
# 737 "data/maps/MtChimney/scripts.pory"
	.string "A METEORITE is fitted on a mysterious\n"
# 738 "data/maps/MtChimney/scripts.pory"
	.string "machine…\p"
# 739 "data/maps/MtChimney/scripts.pory"
	.string "Do you want to remove the METEORITE?$"
# 740 "data/maps/MtChimney/scripts.pory"

# 741 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_PlayerRemovedMeteorite:
# 742 "data/maps/MtChimney/scripts.pory"
	.string "{PLAYER} removed the METEORITE from\n"
# 743 "data/maps/MtChimney/scripts.pory"
	.string "the mysterious machine.$"
# 744 "data/maps/MtChimney/scripts.pory"

# 745 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_PlayerLeftMeteorite:
# 746 "data/maps/MtChimney/scripts.pory"
	.string "{PLAYER} left the METEORITE where\n"
# 747 "data/maps/MtChimney/scripts.pory"
	.string "it was.$"
# 748 "data/maps/MtChimney/scripts.pory"

# 749 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_MachineMakesNoResponse:
# 750 "data/maps/MtChimney/scripts.pory"
	.string "This mysterious machine…\n"
# 751 "data/maps/MtChimney/scripts.pory"
	.string "It makes no response whatsoever.$"
# 752 "data/maps/MtChimney/scripts.pory"

# 753 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_RouteSign:
# 754 "data/maps/MtChimney/scripts.pory"
	.string "{DOWN_ARROW} JAGGED PATH\n"
# 755 "data/maps/MtChimney/scripts.pory"
	.string "LAVARIDGE TOWN AHEAD$"
# 756 "data/maps/MtChimney/scripts.pory"

# 757 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_ShelbyIntro:
# 758 "data/maps/MtChimney/scripts.pory"
	.string "I've been to the hot springs and\n"
# 759 "data/maps/MtChimney/scripts.pory"
	.string "refreshed my tired bones.\l"
# 760 "data/maps/MtChimney/scripts.pory"
	.string "Right now I'm feeling strong!$"
# 761 "data/maps/MtChimney/scripts.pory"

# 762 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_ShelbyDefeat:
# 763 "data/maps/MtChimney/scripts.pory"
	.string "Oh, my goodness.\n"
# 764 "data/maps/MtChimney/scripts.pory"
	.string "Now, aren't you something!$"
# 765 "data/maps/MtChimney/scripts.pory"

# 766 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_ShelbyPostBattle:
# 767 "data/maps/MtChimney/scripts.pory"
	.string "Well, well, I've lost. I can't call\n"
# 768 "data/maps/MtChimney/scripts.pory"
	.string "myself an EXPERT now, can I?$"
# 769 "data/maps/MtChimney/scripts.pory"

# 770 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_ShelbyRegister:
# 771 "data/maps/MtChimney/scripts.pory"
	.string "Thank you, child. It was fun, as if\n"
# 772 "data/maps/MtChimney/scripts.pory"
	.string "I were battling my own grandchild.\p"
# 773 "data/maps/MtChimney/scripts.pory"
	.string "Please, come see me again for\n"
# 774 "data/maps/MtChimney/scripts.pory"
	.string "a rematch.$"
# 775 "data/maps/MtChimney/scripts.pory"

# 776 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_ShelbyRematchIntro:
# 777 "data/maps/MtChimney/scripts.pory"
	.string "If you can mesh your heart with those\n"
# 778 "data/maps/MtChimney/scripts.pory"
	.string "of your POKéMON, why, you should be\l"
# 779 "data/maps/MtChimney/scripts.pory"
	.string "able to achieve great things.$"
# 780 "data/maps/MtChimney/scripts.pory"

# 781 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_ShelbyRematchDefeat:
# 782 "data/maps/MtChimney/scripts.pory"
	.string "Oh, my goodness.\n"
# 783 "data/maps/MtChimney/scripts.pory"
	.string "Now, aren't you something!$"
# 784 "data/maps/MtChimney/scripts.pory"

# 785 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_ShelbyPostRematch:
# 786 "data/maps/MtChimney/scripts.pory"
	.string "Perhaps your heart has become one\n"
# 787 "data/maps/MtChimney/scripts.pory"
	.string "with the hearts of your POKéMON.$"
# 788 "data/maps/MtChimney/scripts.pory"

# 789 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_MelissaIntro:
# 790 "data/maps/MtChimney/scripts.pory"
	.string "I've got the fire in me, baby.\n"
# 791 "data/maps/MtChimney/scripts.pory"
	.string "I can't stand it! I have to battle!$"
# 792 "data/maps/MtChimney/scripts.pory"

# 793 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_MelissaDefeat:
# 794 "data/maps/MtChimney/scripts.pory"
	.string "Ooh, that was a scorching-hot match!$"
# 795 "data/maps/MtChimney/scripts.pory"

# 796 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_MelissaPostBattle:
# 797 "data/maps/MtChimney/scripts.pory"
	.string "The heat of MT. CHIMNEY warms\n"
# 798 "data/maps/MtChimney/scripts.pory"
	.string "me up, baby!$"
# 799 "data/maps/MtChimney/scripts.pory"

# 800 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_SheilaIntro:
# 801 "data/maps/MtChimney/scripts.pory"
	.string "I've finally made it to MT. CHIMNEY.\n"
# 802 "data/maps/MtChimney/scripts.pory"
	.string "I want to make my POKéMON battle!$"
# 803 "data/maps/MtChimney/scripts.pory"

# 804 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_SheilaDefeat:
# 805 "data/maps/MtChimney/scripts.pory"
	.string "The way you battle…\n"
# 806 "data/maps/MtChimney/scripts.pory"
	.string "It's like a MT. CHIMNEY eruption!$"
# 807 "data/maps/MtChimney/scripts.pory"

# 808 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_SheilaPostBattle:
# 809 "data/maps/MtChimney/scripts.pory"
	.string "Like I said, I've finally made it to\n"
# 810 "data/maps/MtChimney/scripts.pory"
	.string "MT. CHIMNEY. It would be a shame if\l"
# 811 "data/maps/MtChimney/scripts.pory"
	.string "I only do a little sightseeing…\p"
# 812 "data/maps/MtChimney/scripts.pory"
	.string "I want to get in some battles and buy\n"
# 813 "data/maps/MtChimney/scripts.pory"
	.string "COOKIES as souvenirs.$"
# 814 "data/maps/MtChimney/scripts.pory"

# 815 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_ShirleyIntro:
# 816 "data/maps/MtChimney/scripts.pory"
	.string "Since I bathed in the hot springs,\n"
# 817 "data/maps/MtChimney/scripts.pory"
	.string "I've been feeling great!\l"
# 818 "data/maps/MtChimney/scripts.pory"
	.string "I'm sure I'm going to win!$"
# 819 "data/maps/MtChimney/scripts.pory"

# 820 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_ShirleyDefeat:
# 821 "data/maps/MtChimney/scripts.pory"
	.string "Yowch!\n"
# 822 "data/maps/MtChimney/scripts.pory"
	.string "I'm getting a chill out of the water.$"
# 823 "data/maps/MtChimney/scripts.pory"

# 824 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_ShirleyPostBattle:
# 825 "data/maps/MtChimney/scripts.pory"
	.string "I'll have to take another dip in the\n"
# 826 "data/maps/MtChimney/scripts.pory"
	.string "hot springs. Want to join me?\p"
# 827 "data/maps/MtChimney/scripts.pory"
	.string "Just joking!$"
# 828 "data/maps/MtChimney/scripts.pory"

# 829 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_SawyerIntro:
# 830 "data/maps/MtChimney/scripts.pory"
	.string "This is one fine mountain! Plenty of\n"
# 831 "data/maps/MtChimney/scripts.pory"
	.string "hot people around for company!$"
# 832 "data/maps/MtChimney/scripts.pory"

# 833 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_SawyerDefeat:
# 834 "data/maps/MtChimney/scripts.pory"
	.string "Oh, you're a real firebrand, too!$"
# 835 "data/maps/MtChimney/scripts.pory"

# 836 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_SawyerPostBattle:
# 837 "data/maps/MtChimney/scripts.pory"
	.string "I think I need a dip in LAVARIDGE\n"
# 838 "data/maps/MtChimney/scripts.pory"
	.string "HOT SPRING with the locals!$"
# 839 "data/maps/MtChimney/scripts.pory"

# 840 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_SawyerRegister:
# 841 "data/maps/MtChimney/scripts.pory"
	.string "I like little fireballs like you.\n"
# 842 "data/maps/MtChimney/scripts.pory"
	.string "Let me register you in my POKéNAV.$"
# 843 "data/maps/MtChimney/scripts.pory"

# 844 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_SawyerRematchIntro:
# 845 "data/maps/MtChimney/scripts.pory"
	.string "I'm happily surrounded by hot people\n"
# 846 "data/maps/MtChimney/scripts.pory"
	.string "around these parts. I won't lose!$"
# 847 "data/maps/MtChimney/scripts.pory"

# 848 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_SawyerRematchDefeat:
# 849 "data/maps/MtChimney/scripts.pory"
	.string "Gosh, you're still the same\n"
# 850 "data/maps/MtChimney/scripts.pory"
	.string "firebrand as before!$"
# 851 "data/maps/MtChimney/scripts.pory"

# 852 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_SawyerPostRematch:
# 853 "data/maps/MtChimney/scripts.pory"
	.string "Actually, it really is hot here.\n"
# 854 "data/maps/MtChimney/scripts.pory"
	.string "I'm overdressed for these parts.$"
