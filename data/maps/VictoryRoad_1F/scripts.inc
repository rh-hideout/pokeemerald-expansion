# 1 "data/maps/VictoryRoad_1F/scripts.pory"

# 2 "data/maps/VictoryRoad_1F/scripts.pory"
.set LOCALID_WALLY_ENTRANCE, 4
# 3 "data/maps/VictoryRoad_1F/scripts.pory"

# 4 "data/maps/VictoryRoad_1F/scripts.pory"
VictoryRoad_1F_MapScripts::
# 5 "data/maps/VictoryRoad_1F/scripts.pory"
	map_script MAP_SCRIPT_ON_RESUME, VictoryRoad_1F_OnResume
# 6 "data/maps/VictoryRoad_1F/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, VictoryRoad_1F_OnTransition
# 7 "data/maps/VictoryRoad_1F/scripts.pory"
	.byte 0
# 8 "data/maps/VictoryRoad_1F/scripts.pory"

# 9 "data/maps/VictoryRoad_1F/scripts.pory"
VictoryRoad_1F_OnResume:
# 10 "data/maps/VictoryRoad_1F/scripts.pory"
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, VictoryRoad_1F_EventScript_TryRemoveMoltres
# 11 "data/maps/VictoryRoad_1F/scripts.pory"
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, VictoryRoad_1F_EventScript_TryRemoveMoltres_Galarian
# 12 "data/maps/VictoryRoad_1F/scripts.pory"
	end
# 13 "data/maps/VictoryRoad_1F/scripts.pory"

# 14 "data/maps/VictoryRoad_1F/scripts.pory"
VictoryRoad_1F_EventScript_TryRemoveMoltres::
# 15 "data/maps/VictoryRoad_1F/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 16 "data/maps/VictoryRoad_1F/scripts.pory"
	goto_if_ne VAR_RESULT, B_OUTCOME_CAUGHT, Common_EventScript_NopReturn
# 17 "data/maps/VictoryRoad_1F/scripts.pory"
	removeobject VAR_LAST_TALKED
# 18 "data/maps/VictoryRoad_1F/scripts.pory"
	return
# 19 "data/maps/VictoryRoad_1F/scripts.pory"

# 20 "data/maps/VictoryRoad_1F/scripts.pory"
VictoryRoad_1F_EventScript_TryRemoveMoltres_Galarian::
# 21 "data/maps/VictoryRoad_1F/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 22 "data/maps/VictoryRoad_1F/scripts.pory"
	goto_if_ne VAR_RESULT, B_OUTCOME_CAUGHT, Common_EventScript_NopReturn
# 23 "data/maps/VictoryRoad_1F/scripts.pory"
	removeobject VAR_LAST_TALKED
# 24 "data/maps/VictoryRoad_1F/scripts.pory"
	return
# 25 "data/maps/VictoryRoad_1F/scripts.pory"

# 26 "data/maps/VictoryRoad_1F/scripts.pory"
VictoryRoad_1F_OnTransition:
# 27 "data/maps/VictoryRoad_1F/scripts.pory"
	call_if_eq VAR_VICTORY_ROAD_1F_STATE, 1, VictoryRoad_1F_EventScript_SetEntranceWallyPos1
# 28 "data/maps/VictoryRoad_1F/scripts.pory"
	call_if_eq VAR_VICTORY_ROAD_1F_STATE, 2, VictoryRoad_1F_EventScript_SetEntranceWallyPos2
# 29 "data/maps/VictoryRoad_1F/scripts.pory"
	end
# 30 "data/maps/VictoryRoad_1F/scripts.pory"

# 31 "data/maps/VictoryRoad_1F/scripts.pory"
VictoryRoad_1F_EventScript_SetEntranceWallyPos1::
# 32 "data/maps/VictoryRoad_1F/scripts.pory"
	setobjectxyperm LOCALID_WALLY_ENTRANCE, 2, 24
# 33 "data/maps/VictoryRoad_1F/scripts.pory"
	setobjectmovementtype LOCALID_WALLY_ENTRANCE, MOVEMENT_TYPE_FACE_DOWN
# 34 "data/maps/VictoryRoad_1F/scripts.pory"
	return
# 35 "data/maps/VictoryRoad_1F/scripts.pory"

# 36 "data/maps/VictoryRoad_1F/scripts.pory"
VictoryRoad_1F_EventScript_SetEntranceWallyPos2::
# 37 "data/maps/VictoryRoad_1F/scripts.pory"
	setobjectxyperm LOCALID_WALLY_ENTRANCE, 3, 24
# 38 "data/maps/VictoryRoad_1F/scripts.pory"
	setobjectmovementtype LOCALID_WALLY_ENTRANCE, MOVEMENT_TYPE_FACE_DOWN
# 39 "data/maps/VictoryRoad_1F/scripts.pory"
	return
# 40 "data/maps/VictoryRoad_1F/scripts.pory"

# 41 "data/maps/VictoryRoad_1F/scripts.pory"
VictoryRoad_1F_EventScript_WallyBattleTrigger1::
# 42 "data/maps/VictoryRoad_1F/scripts.pory"
	lockall
# 43 "data/maps/VictoryRoad_1F/scripts.pory"
	setvar VAR_0x8008, 1
# 44 "data/maps/VictoryRoad_1F/scripts.pory"
	addobject LOCALID_WALLY_ENTRANCE
# 45 "data/maps/VictoryRoad_1F/scripts.pory"
	applymovement LOCALID_WALLY_ENTRANCE, VictoryRoad_1F_Movement_WallyApproachPlayer1
# 46 "data/maps/VictoryRoad_1F/scripts.pory"
	waitmovement 0
# 47 "data/maps/VictoryRoad_1F/scripts.pory"
	goto VictoryRoad_1F_EventScript_WallyEntranceBattle
# 48 "data/maps/VictoryRoad_1F/scripts.pory"
	end
# 49 "data/maps/VictoryRoad_1F/scripts.pory"

# 50 "data/maps/VictoryRoad_1F/scripts.pory"
VictoryRoad_1F_EventScript_WallyBattleTrigger2::
# 51 "data/maps/VictoryRoad_1F/scripts.pory"
	lockall
# 52 "data/maps/VictoryRoad_1F/scripts.pory"
	setvar VAR_0x8008, 2
# 53 "data/maps/VictoryRoad_1F/scripts.pory"
	addobject LOCALID_WALLY_ENTRANCE
# 54 "data/maps/VictoryRoad_1F/scripts.pory"
	applymovement LOCALID_WALLY_ENTRANCE, VictoryRoad_1F_Movement_WallyApproachPlayer2
# 55 "data/maps/VictoryRoad_1F/scripts.pory"
	waitmovement 0
# 56 "data/maps/VictoryRoad_1F/scripts.pory"
	goto VictoryRoad_1F_EventScript_WallyEntranceBattle
# 57 "data/maps/VictoryRoad_1F/scripts.pory"
	end
# 58 "data/maps/VictoryRoad_1F/scripts.pory"

# 59 "data/maps/VictoryRoad_1F/scripts.pory"
VictoryRoad_1F_EventScript_WallyEntranceBattle::
# 60 "data/maps/VictoryRoad_1F/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterDown
# 61 "data/maps/VictoryRoad_1F/scripts.pory"
	waitmovement 0
# 62 "data/maps/VictoryRoad_1F/scripts.pory"
	msgbox VictoryRoad_1F_Text_WallyNotGoingToLoseAnymore, MSGBOX_DEFAULT
# 63 "data/maps/VictoryRoad_1F/scripts.pory"
	trainerbattle_no_intro TRAINER_WALLY_VR_1, VictoryRoad_1F_Text_WallyEntranceDefeat
# 64 "data/maps/VictoryRoad_1F/scripts.pory"
	msgbox VictoryRoad_1F_Text_WallyPostEntranceBattle, MSGBOX_DEFAULT
# 65 "data/maps/VictoryRoad_1F/scripts.pory"
	clearflag FLAG_HIDE_VICTORY_ROAD_ENTRANCE_WALLY
# 66 "data/maps/VictoryRoad_1F/scripts.pory"
	copyobjectxytoperm LOCALID_WALLY_ENTRANCE
# 67 "data/maps/VictoryRoad_1F/scripts.pory"
	setflag FLAG_DEFEATED_WALLY_VICTORY_ROAD
# 68 "data/maps/VictoryRoad_1F/scripts.pory"
	copyvar VAR_VICTORY_ROAD_1F_STATE, VAR_0x8008
# 69 "data/maps/VictoryRoad_1F/scripts.pory"
	releaseall
# 70 "data/maps/VictoryRoad_1F/scripts.pory"
	end
# 71 "data/maps/VictoryRoad_1F/scripts.pory"

# 72 "data/maps/VictoryRoad_1F/scripts.pory"
VictoryRoad_1F_Movement_WallyApproachPlayer1:
# 73 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_left
# 74 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_left
# 75 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_left
# 76 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_left
# 77 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_left
# 78 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_left
# 79 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_left
# 80 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_left
# 81 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_left
# 82 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_left
# 83 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_up
# 84 "data/maps/VictoryRoad_1F/scripts.pory"
	step_end
# 85 "data/maps/VictoryRoad_1F/scripts.pory"

# 86 "data/maps/VictoryRoad_1F/scripts.pory"
VictoryRoad_1F_Movement_WallyApproachPlayer2:
# 87 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_left
# 88 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_left
# 89 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_left
# 90 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_left
# 91 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_left
# 92 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_left
# 93 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_left
# 94 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_left
# 95 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_left
# 96 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_up
# 97 "data/maps/VictoryRoad_1F/scripts.pory"
	step_end
# 98 "data/maps/VictoryRoad_1F/scripts.pory"

# 99 "data/maps/VictoryRoad_1F/scripts.pory"
@ This Wally appears near the entrance once his battle is triggered and remains there until the Hall of Fame is entered
# 100 "data/maps/VictoryRoad_1F/scripts.pory"
VictoryRoad_1F_EventScript_EntranceWally::
# 101 "data/maps/VictoryRoad_1F/scripts.pory"
	msgbox VictoryRoad_1F_Text_WallyPostEntranceBattle, MSGBOX_NPC
# 102 "data/maps/VictoryRoad_1F/scripts.pory"
	end
# 103 "data/maps/VictoryRoad_1F/scripts.pory"

# 104 "data/maps/VictoryRoad_1F/scripts.pory"
@ This Wally appears and remains at the exit after the Hall of Fame is entered
# 105 "data/maps/VictoryRoad_1F/scripts.pory"
VictoryRoad_1F_EventScript_ExitWally::
# 106 "data/maps/VictoryRoad_1F/scripts.pory"
	trainerbattle_single TRAINER_WALLY_VR_2, VictoryRoad_1F_Text_WallyIntro, VictoryRoad_1F_Text_WallyDefeat
# 107 "data/maps/VictoryRoad_1F/scripts.pory"
	specialvar VAR_RESULT, ShouldTryRematchBattle
# 108 "data/maps/VictoryRoad_1F/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, VictoryRoad_1F_EventScript_RematchWally
# 109 "data/maps/VictoryRoad_1F/scripts.pory"
	msgbox VictoryRoad_1F_Text_WallyPostBattle, MSGBOX_AUTOCLOSE
# 110 "data/maps/VictoryRoad_1F/scripts.pory"
	end
# 111 "data/maps/VictoryRoad_1F/scripts.pory"

# 112 "data/maps/VictoryRoad_1F/scripts.pory"
VictoryRoad_1F_EventScript_RematchWally::
# 113 "data/maps/VictoryRoad_1F/scripts.pory"
	trainerbattle_rematch TRAINER_WALLY_VR_2, VictoryRoad_1F_Text_WallyIntro, VictoryRoad_1F_Text_WallyDefeat
# 114 "data/maps/VictoryRoad_1F/scripts.pory"
	msgbox VictoryRoad_1F_Text_WallyPostBattle, MSGBOX_AUTOCLOSE
# 115 "data/maps/VictoryRoad_1F/scripts.pory"
	end
# 116 "data/maps/VictoryRoad_1F/scripts.pory"

# 117 "data/maps/VictoryRoad_1F/scripts.pory"
VictoryRoad_1F_EventScript_Edgar::
# 118 "data/maps/VictoryRoad_1F/scripts.pory"
	trainerbattle_single TRAINER_EDGAR, VictoryRoad_1F_Text_EdgarIntro, VictoryRoad_1F_Text_EdgarDefeat
# 119 "data/maps/VictoryRoad_1F/scripts.pory"
	msgbox VictoryRoad_1F_Text_EdgarPostBattle, MSGBOX_AUTOCLOSE
# 120 "data/maps/VictoryRoad_1F/scripts.pory"
	end
# 121 "data/maps/VictoryRoad_1F/scripts.pory"

# 122 "data/maps/VictoryRoad_1F/scripts.pory"
VictoryRoad_1F_EventScript_Albert::
# 123 "data/maps/VictoryRoad_1F/scripts.pory"
	trainerbattle_single TRAINER_ALBERT, VictoryRoad_1F_Text_AlbertIntro, VictoryRoad_1F_Text_AlbertDefeat
# 124 "data/maps/VictoryRoad_1F/scripts.pory"
	msgbox VictoryRoad_1F_Text_AlbertPostBattle, MSGBOX_AUTOCLOSE
# 125 "data/maps/VictoryRoad_1F/scripts.pory"
	end
# 126 "data/maps/VictoryRoad_1F/scripts.pory"

# 127 "data/maps/VictoryRoad_1F/scripts.pory"
VictoryRoad_1F_EventScript_Hope::
# 128 "data/maps/VictoryRoad_1F/scripts.pory"
	trainerbattle_single TRAINER_HOPE, VictoryRoad_1F_Text_HopeIntro, VictoryRoad_1F_Text_HopeDefeat
# 129 "data/maps/VictoryRoad_1F/scripts.pory"
	msgbox VictoryRoad_1F_Text_HopePostBattle, MSGBOX_AUTOCLOSE
# 130 "data/maps/VictoryRoad_1F/scripts.pory"
	end
# 131 "data/maps/VictoryRoad_1F/scripts.pory"

# 132 "data/maps/VictoryRoad_1F/scripts.pory"
VictoryRoad_1F_EventScript_Quincy::
# 133 "data/maps/VictoryRoad_1F/scripts.pory"
	trainerbattle_single TRAINER_QUINCY, VictoryRoad_1F_Text_QuincyIntro, VictoryRoad_1F_Text_QuincyDefeat
# 134 "data/maps/VictoryRoad_1F/scripts.pory"
	msgbox VictoryRoad_1F_Text_QuincyPostBattle, MSGBOX_AUTOCLOSE
# 135 "data/maps/VictoryRoad_1F/scripts.pory"
	end
# 136 "data/maps/VictoryRoad_1F/scripts.pory"

# 137 "data/maps/VictoryRoad_1F/scripts.pory"
VictoryRoad_1F_EventScript_Katelynn::
# 138 "data/maps/VictoryRoad_1F/scripts.pory"
	trainerbattle_single TRAINER_KATELYNN, VictoryRoad_1F_Text_KatelynnIntro, VictoryRoad_1F_Text_KatelynnDefeat
# 139 "data/maps/VictoryRoad_1F/scripts.pory"
	msgbox VictoryRoad_1F_Text_KatelynnPostBattle, MSGBOX_AUTOCLOSE
# 140 "data/maps/VictoryRoad_1F/scripts.pory"
	end
# 141 "data/maps/VictoryRoad_1F/scripts.pory"

# 142 "data/maps/VictoryRoad_1F/scripts.pory"
VictoryRoad_1F_Text_WallyNotGoingToLoseAnymore:
# 143 "data/maps/VictoryRoad_1F/scripts.pory"
	.string "WALLY: Hi! {PLAYER}!\p"
# 144 "data/maps/VictoryRoad_1F/scripts.pory"
	.string "I bet you're surprised to see me here!\p"
# 145 "data/maps/VictoryRoad_1F/scripts.pory"
	.string "I made it all the way here, and it's\n"
# 146 "data/maps/VictoryRoad_1F/scripts.pory"
	.string "all thanks to you!\p"
# 147 "data/maps/VictoryRoad_1F/scripts.pory"
	.string "{PLAYER}, losing to you that time\n"
# 148 "data/maps/VictoryRoad_1F/scripts.pory"
	.string "made me stronger!\p"
# 149 "data/maps/VictoryRoad_1F/scripts.pory"
	.string "But I'm not going to lose anymore!\p"
# 150 "data/maps/VictoryRoad_1F/scripts.pory"
	.string "I'm going to win! For the POKéMON who\n"
# 151 "data/maps/VictoryRoad_1F/scripts.pory"
	.string "gave me courage and strength!\p"
# 152 "data/maps/VictoryRoad_1F/scripts.pory"
	.string "Okay… Here I come!$"
# 153 "data/maps/VictoryRoad_1F/scripts.pory"

# 154 "data/maps/VictoryRoad_1F/scripts.pory"
VictoryRoad_1F_Text_WallyEntranceDefeat:
# 155 "data/maps/VictoryRoad_1F/scripts.pory"
	.string "Wow!\n"
# 156 "data/maps/VictoryRoad_1F/scripts.pory"
	.string "{PLAYER}, you are strong, after all!$"
# 157 "data/maps/VictoryRoad_1F/scripts.pory"

# 158 "data/maps/VictoryRoad_1F/scripts.pory"
VictoryRoad_1F_Text_WallyPostEntranceBattle:
# 159 "data/maps/VictoryRoad_1F/scripts.pory"
	.string "WALLY: I couldn't beat you today,\n"
# 160 "data/maps/VictoryRoad_1F/scripts.pory"
	.string "{PLAYER}, but one of these days, I'll\l"
# 161 "data/maps/VictoryRoad_1F/scripts.pory"
	.string "catch up to you!$"
# 162 "data/maps/VictoryRoad_1F/scripts.pory"

# 163 "data/maps/VictoryRoad_1F/scripts.pory"
VictoryRoad_1F_Text_WallyIntro:
# 164 "data/maps/VictoryRoad_1F/scripts.pory"
	.string "WALLY: Hi! {PLAYER}!\p"
# 165 "data/maps/VictoryRoad_1F/scripts.pory"
	.string "I've gotten stronger since that last\n"
# 166 "data/maps/VictoryRoad_1F/scripts.pory"
	.string "time! I wanted to show you, {PLAYER}!\p"
# 167 "data/maps/VictoryRoad_1F/scripts.pory"
	.string "Okay… Here I come!$"
# 168 "data/maps/VictoryRoad_1F/scripts.pory"

# 169 "data/maps/VictoryRoad_1F/scripts.pory"
VictoryRoad_1F_Text_WallyDefeat:
# 170 "data/maps/VictoryRoad_1F/scripts.pory"
	.string "Wow!\n"
# 171 "data/maps/VictoryRoad_1F/scripts.pory"
	.string "{PLAYER}, you are strong, after all!$"
# 172 "data/maps/VictoryRoad_1F/scripts.pory"

# 173 "data/maps/VictoryRoad_1F/scripts.pory"
VictoryRoad_1F_Text_WallyPostBattle:
# 174 "data/maps/VictoryRoad_1F/scripts.pory"
	.string "WALLY: I couldn't beat you this time,\n"
# 175 "data/maps/VictoryRoad_1F/scripts.pory"
	.string "too… But one of these days, {PLAYER},\l"
# 176 "data/maps/VictoryRoad_1F/scripts.pory"
	.string "I'm going to catch up to you…\p"
# 177 "data/maps/VictoryRoad_1F/scripts.pory"
	.string "And challenge the POKéMON LEAGUE!$"
# 178 "data/maps/VictoryRoad_1F/scripts.pory"

# 179 "data/maps/VictoryRoad_1F/scripts.pory"
VictoryRoad_1F_Text_EdgarIntro:
# 180 "data/maps/VictoryRoad_1F/scripts.pory"
	.string "I've made it this far a couple times,\n"
# 181 "data/maps/VictoryRoad_1F/scripts.pory"
	.string "but the last stretch is so long…$"
# 182 "data/maps/VictoryRoad_1F/scripts.pory"

# 183 "data/maps/VictoryRoad_1F/scripts.pory"
VictoryRoad_1F_Text_EdgarDefeat:
# 184 "data/maps/VictoryRoad_1F/scripts.pory"
	.string "My dream ends here again…$"
# 185 "data/maps/VictoryRoad_1F/scripts.pory"

# 186 "data/maps/VictoryRoad_1F/scripts.pory"
VictoryRoad_1F_Text_EdgarPostBattle:
# 187 "data/maps/VictoryRoad_1F/scripts.pory"
	.string "You've made it this far. Keep the\n"
# 188 "data/maps/VictoryRoad_1F/scripts.pory"
	.string "momentum going and become the\l"
# 189 "data/maps/VictoryRoad_1F/scripts.pory"
	.string "CHAMPION! If anyone can, it's you!$"
# 190 "data/maps/VictoryRoad_1F/scripts.pory"

# 191 "data/maps/VictoryRoad_1F/scripts.pory"
VictoryRoad_1F_Text_AlbertIntro:
# 192 "data/maps/VictoryRoad_1F/scripts.pory"
	.string "I didn't come all this way to lose now.\n"
# 193 "data/maps/VictoryRoad_1F/scripts.pory"
	.string "That possibility doesn't exist!$"
# 194 "data/maps/VictoryRoad_1F/scripts.pory"

# 195 "data/maps/VictoryRoad_1F/scripts.pory"
VictoryRoad_1F_Text_AlbertDefeat:
# 196 "data/maps/VictoryRoad_1F/scripts.pory"
	.string "Impossible…\n"
# 197 "data/maps/VictoryRoad_1F/scripts.pory"
	.string "I lost?$"
# 198 "data/maps/VictoryRoad_1F/scripts.pory"

# 199 "data/maps/VictoryRoad_1F/scripts.pory"
VictoryRoad_1F_Text_AlbertPostBattle:
# 200 "data/maps/VictoryRoad_1F/scripts.pory"
	.string "I lost here…\p"
# 201 "data/maps/VictoryRoad_1F/scripts.pory"
	.string "That means I lack the qualifications\n"
# 202 "data/maps/VictoryRoad_1F/scripts.pory"
	.string "to become the CHAMPION…$"
# 203 "data/maps/VictoryRoad_1F/scripts.pory"

# 204 "data/maps/VictoryRoad_1F/scripts.pory"
VictoryRoad_1F_Text_HopeIntro:
# 205 "data/maps/VictoryRoad_1F/scripts.pory"
	.string "This seemingly infinite and harsh road\n"
# 206 "data/maps/VictoryRoad_1F/scripts.pory"
	.string "lives up to its name of VICTORY.$"
# 207 "data/maps/VictoryRoad_1F/scripts.pory"

# 208 "data/maps/VictoryRoad_1F/scripts.pory"
VictoryRoad_1F_Text_HopeDefeat:
# 209 "data/maps/VictoryRoad_1F/scripts.pory"
	.string "Your battle style is fantastic…$"
# 210 "data/maps/VictoryRoad_1F/scripts.pory"

# 211 "data/maps/VictoryRoad_1F/scripts.pory"
VictoryRoad_1F_Text_HopePostBattle:
# 212 "data/maps/VictoryRoad_1F/scripts.pory"
	.string "You seem to have the potential for\n"
# 213 "data/maps/VictoryRoad_1F/scripts.pory"
	.string "becoming the CHAMPION.$"
# 214 "data/maps/VictoryRoad_1F/scripts.pory"

# 215 "data/maps/VictoryRoad_1F/scripts.pory"
VictoryRoad_1F_Text_QuincyIntro:
# 216 "data/maps/VictoryRoad_1F/scripts.pory"
	.string "What is the VICTORY ROAD?\n"
# 217 "data/maps/VictoryRoad_1F/scripts.pory"
	.string "I'll tell you if you win!$"
# 218 "data/maps/VictoryRoad_1F/scripts.pory"

# 219 "data/maps/VictoryRoad_1F/scripts.pory"
VictoryRoad_1F_Text_QuincyDefeat:
# 220 "data/maps/VictoryRoad_1F/scripts.pory"
	.string "Okay!\n"
# 221 "data/maps/VictoryRoad_1F/scripts.pory"
	.string "Well done!$"
# 222 "data/maps/VictoryRoad_1F/scripts.pory"

# 223 "data/maps/VictoryRoad_1F/scripts.pory"
VictoryRoad_1F_Text_QuincyPostBattle:
# 224 "data/maps/VictoryRoad_1F/scripts.pory"
	.string "Getting through here safely--that's\n"
# 225 "data/maps/VictoryRoad_1F/scripts.pory"
	.string "the final test for any TRAINER aiming\l"
# 226 "data/maps/VictoryRoad_1F/scripts.pory"
	.string "to become the POKéMON CHAMPION.\p"
# 227 "data/maps/VictoryRoad_1F/scripts.pory"
	.string "That's why it's called the VICTORY\n"
# 228 "data/maps/VictoryRoad_1F/scripts.pory"
	.string "ROAD.$"
# 229 "data/maps/VictoryRoad_1F/scripts.pory"

# 230 "data/maps/VictoryRoad_1F/scripts.pory"
VictoryRoad_1F_Text_KatelynnIntro:
# 231 "data/maps/VictoryRoad_1F/scripts.pory"
	.string "I have nothing to say to anyone\n"
# 232 "data/maps/VictoryRoad_1F/scripts.pory"
	.string "that's come this far. Come on!$"
# 233 "data/maps/VictoryRoad_1F/scripts.pory"

# 234 "data/maps/VictoryRoad_1F/scripts.pory"
VictoryRoad_1F_Text_KatelynnDefeat:
# 235 "data/maps/VictoryRoad_1F/scripts.pory"
	.string "This is a disgrace…$"
# 236 "data/maps/VictoryRoad_1F/scripts.pory"

# 237 "data/maps/VictoryRoad_1F/scripts.pory"
VictoryRoad_1F_Text_KatelynnPostBattle:
# 238 "data/maps/VictoryRoad_1F/scripts.pory"
	.string "Humph, go right on ahead.\n"
# 239 "data/maps/VictoryRoad_1F/scripts.pory"
	.string "See if I care.$"
# 240 "data/maps/VictoryRoad_1F/scripts.pory"

# 241 "data/maps/VictoryRoad_1F/scripts.pory"
VictoryRoad_1F_EventScript_Moltres::
# 242 "data/maps/VictoryRoad_1F/scripts.pory"
    lock
# 243 "data/maps/VictoryRoad_1F/scripts.pory"
    faceplayer
# 244 "data/maps/VictoryRoad_1F/scripts.pory"
    waitse
# 245 "data/maps/VictoryRoad_1F/scripts.pory"
    playmoncry SPECIES_MOLTRES, CRY_MODE_ENCOUNTER
# 246 "data/maps/VictoryRoad_1F/scripts.pory"
    delay 40
# 247 "data/maps/VictoryRoad_1F/scripts.pory"
    waitmoncry
# 248 "data/maps/VictoryRoad_1F/scripts.pory"
    setwildbattle SPECIES_MOLTRES, 40
# 249 "data/maps/VictoryRoad_1F/scripts.pory"
    setflag FLAG_SYS_CTRL_OBJ_DELETE
# 250 "data/maps/VictoryRoad_1F/scripts.pory"
    special BattleSetup_StartLegendaryBattle
# 251 "data/maps/VictoryRoad_1F/scripts.pory"
    waitstate
# 252 "data/maps/VictoryRoad_1F/scripts.pory"
    clearflag FLAG_SYS_CTRL_OBJ_DELETE
# 253 "data/maps/VictoryRoad_1F/scripts.pory"
    specialvar VAR_RESULT, GetBattleOutcome
# 254 "data/maps/VictoryRoad_1F/scripts.pory"
    goto_if_eq VAR_RESULT, B_OUTCOME_WON, VictoryRoad_1F_EventScript_DefeatedMoltres
# 255 "data/maps/VictoryRoad_1F/scripts.pory"
    goto_if_eq VAR_RESULT, B_OUTCOME_RAN, VictoryRoad_1F_EventScript_RanFromMoltres
# 256 "data/maps/VictoryRoad_1F/scripts.pory"
    goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, VictoryRoad_1F_EventScript_RanFromMoltres
# 257 "data/maps/VictoryRoad_1F/scripts.pory"
    setflag FLAG_DEFEATED_MOLTRES
# 258 "data/maps/VictoryRoad_1F/scripts.pory"
    release
# 259 "data/maps/VictoryRoad_1F/scripts.pory"
    end
# 260 "data/maps/VictoryRoad_1F/scripts.pory"

# 261 "data/maps/VictoryRoad_1F/scripts.pory"

# 262 "data/maps/VictoryRoad_1F/scripts.pory"
VictoryRoad_1F_EventScript_DefeatedMoltres::
# 263 "data/maps/VictoryRoad_1F/scripts.pory"
    setflag FLAG_DEFEATED_MOLTRES
# 264 "data/maps/VictoryRoad_1F/scripts.pory"
    goto Common_EventScript_RemoveStaticPokemon
# 265 "data/maps/VictoryRoad_1F/scripts.pory"
    end
# 266 "data/maps/VictoryRoad_1F/scripts.pory"

# 267 "data/maps/VictoryRoad_1F/scripts.pory"

# 268 "data/maps/VictoryRoad_1F/scripts.pory"
VictoryRoad_1F_EventScript_RanFromMoltres::
# 269 "data/maps/VictoryRoad_1F/scripts.pory"
    setvar VAR_0x8004, SPECIES_MOLTRES
# 270 "data/maps/VictoryRoad_1F/scripts.pory"
    goto Common_EventScript_LegendaryFlewAway
# 271 "data/maps/VictoryRoad_1F/scripts.pory"
    end
# 272 "data/maps/VictoryRoad_1F/scripts.pory"

# 273 "data/maps/VictoryRoad_1F/scripts.pory"
VictoryRoad_1F_EventScript_Moltres_Galarian::
# 274 "data/maps/VictoryRoad_1F/scripts.pory"
    lock
# 275 "data/maps/VictoryRoad_1F/scripts.pory"
    faceplayer
# 276 "data/maps/VictoryRoad_1F/scripts.pory"
    waitse
# 277 "data/maps/VictoryRoad_1F/scripts.pory"
    playmoncry SPECIES_MOLTRES_GALARIAN, CRY_MODE_ENCOUNTER
# 278 "data/maps/VictoryRoad_1F/scripts.pory"
    delay 40
# 279 "data/maps/VictoryRoad_1F/scripts.pory"
    waitmoncry
# 280 "data/maps/VictoryRoad_1F/scripts.pory"
    setwildbattle SPECIES_MOLTRES_GALARIAN, 40
# 281 "data/maps/VictoryRoad_1F/scripts.pory"
    setflag FLAG_SYS_CTRL_OBJ_DELETE
# 282 "data/maps/VictoryRoad_1F/scripts.pory"
    special BattleSetup_StartLegendaryBattle
# 283 "data/maps/VictoryRoad_1F/scripts.pory"
    waitstate
# 284 "data/maps/VictoryRoad_1F/scripts.pory"
    clearflag FLAG_SYS_CTRL_OBJ_DELETE
# 285 "data/maps/VictoryRoad_1F/scripts.pory"
    specialvar VAR_RESULT, GetBattleOutcome
# 286 "data/maps/VictoryRoad_1F/scripts.pory"
    goto_if_eq VAR_RESULT, B_OUTCOME_WON, VictoryRoad_1F_EventScript_DefeatedMoltresG
# 287 "data/maps/VictoryRoad_1F/scripts.pory"
    goto_if_eq VAR_RESULT, B_OUTCOME_RAN, VictoryRoad_1F_EventScript_RanFromMoltresG
# 288 "data/maps/VictoryRoad_1F/scripts.pory"
    goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, VictoryRoad_1F_EventScript_RanFromMoltresG
# 289 "data/maps/VictoryRoad_1F/scripts.pory"
    setflag FLAG_DEFEATED_MOLTRES_GALARIAN
# 290 "data/maps/VictoryRoad_1F/scripts.pory"
    release
# 291 "data/maps/VictoryRoad_1F/scripts.pory"
    end
# 292 "data/maps/VictoryRoad_1F/scripts.pory"

# 293 "data/maps/VictoryRoad_1F/scripts.pory"

# 294 "data/maps/VictoryRoad_1F/scripts.pory"
VictoryRoad_1F_EventScript_DefeatedMoltresG::
# 295 "data/maps/VictoryRoad_1F/scripts.pory"
    setflag FLAG_DEFEATED_MOLTRES_GALARIAN
# 296 "data/maps/VictoryRoad_1F/scripts.pory"
    goto Common_EventScript_RemoveStaticPokemon
# 297 "data/maps/VictoryRoad_1F/scripts.pory"
    end
# 298 "data/maps/VictoryRoad_1F/scripts.pory"

# 299 "data/maps/VictoryRoad_1F/scripts.pory"

# 300 "data/maps/VictoryRoad_1F/scripts.pory"
VictoryRoad_1F_EventScript_RanFromMoltresG::
# 301 "data/maps/VictoryRoad_1F/scripts.pory"
    setvar VAR_0x8004, SPECIES_MOLTRES_GALARIAN
# 302 "data/maps/VictoryRoad_1F/scripts.pory"
    goto Common_EventScript_LegendaryFlewAway
# 303 "data/maps/VictoryRoad_1F/scripts.pory"
    end
