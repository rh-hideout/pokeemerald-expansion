# 1 "data/maps/Route104/scripts.pory"

# 2 "data/maps/Route104/scripts.pory"
Route104_MapScripts::
# 3 "data/maps/Route104/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Route104_OnFrame
# 4 "data/maps/Route104/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, Route104_OnTransition
# 5 "data/maps/Route104/scripts.pory"
	.byte 0
# 6 "data/maps/Route104/scripts.pory"

# 7 "data/maps/Route104/scripts.pory"
Route104_OnFrame:
# 8 "data/maps/Route104/scripts.pory"
	map_script_2 VAR_BOARD_BRINEY_BOAT_STATE, 1, Route104_EventScript_StartSailToDewford
# 9 "data/maps/Route104/scripts.pory"
	.2byte 0
# 10 "data/maps/Route104/scripts.pory"

# 11 "data/maps/Route104/scripts.pory"
Route104_EventScript_StartSailToDewford::
# 12 "data/maps/Route104/scripts.pory"
	lockall
# 13 "data/maps/Route104/scripts.pory"
	goto Route104_EventScript_SailToDewford
# 14 "data/maps/Route104/scripts.pory"
	end
# 15 "data/maps/Route104/scripts.pory"

# 16 "data/maps/Route104/scripts.pory"
Route104_OnTransition:
# 17 "data/maps/Route104/scripts.pory"
	call Common_EventScript_SetupRivalGfxId
# 18 "data/maps/Route104/scripts.pory"
	call Route104_EventScript_TrySetRivalPos
# 19 "data/maps/Route104/scripts.pory"
	call Route104_EventScript_ShowOrHideWhiteHerbFlorist
# 20 "data/maps/Route104/scripts.pory"
	end
# 21 "data/maps/Route104/scripts.pory"

# 22 "data/maps/Route104/scripts.pory"
Route104_EventScript_ShowOrHideWhiteHerbFlorist::
# 23 "data/maps/Route104/scripts.pory"
	goto_if_unset FLAG_MET_PRETTY_PETAL_SHOP_OWNER, Route104_EventScript_HideWhiteHerbFlorist
# 24 "data/maps/Route104/scripts.pory"
	goto_if_unset FLAG_BADGE03_GET, Route104_EventScript_HideWhiteHerbFlorist
# 25 "data/maps/Route104/scripts.pory"
	clearflag FLAG_HIDE_ROUTE_104_WHITE_HERB_FLORIST
# 26 "data/maps/Route104/scripts.pory"
	return
# 27 "data/maps/Route104/scripts.pory"

# 28 "data/maps/Route104/scripts.pory"
Route104_EventScript_HideWhiteHerbFlorist::
# 29 "data/maps/Route104/scripts.pory"
	setflag FLAG_HIDE_ROUTE_104_WHITE_HERB_FLORIST
# 30 "data/maps/Route104/scripts.pory"
	return
# 31 "data/maps/Route104/scripts.pory"

# 32 "data/maps/Route104/scripts.pory"
Route104_EventScript_TrySetRivalPos::
# 33 "data/maps/Route104/scripts.pory"
	goto_if_ge VAR_BOARD_BRINEY_BOAT_STATE, 1, Route104_EventScript_DontSetRivalPos
# 34 "data/maps/Route104/scripts.pory"
	goto_if_set FLAG_MET_RIVAL_RUSTBORO, Route104_EventScript_DontSetRivalPos
# 35 "data/maps/Route104/scripts.pory"
	goto_if_unset FLAG_REGISTER_RIVAL_POKENAV, Route104_EventScript_DontSetRivalPos
# 36 "data/maps/Route104/scripts.pory"
	setobjectxyperm LOCALID_ROUTE104_RIVAL, 17, 52
# 37 "data/maps/Route104/scripts.pory"
	return
# 38 "data/maps/Route104/scripts.pory"

# 39 "data/maps/Route104/scripts.pory"
Route104_EventScript_DontSetRivalPos::
# 40 "data/maps/Route104/scripts.pory"
	return
# 41 "data/maps/Route104/scripts.pory"

# 42 "data/maps/Route104/scripts.pory"
Route104_EventScript_Rival::
# 43 "data/maps/Route104/scripts.pory"
	lockall
# 44 "data/maps/Route104/scripts.pory"
	setvar VAR_0x8008, 1
# 45 "data/maps/Route104/scripts.pory"
	applymovement LOCALID_ROUTE104_RIVAL, Common_Movement_FacePlayer
# 46 "data/maps/Route104/scripts.pory"
	waitmovement 0
# 47 "data/maps/Route104/scripts.pory"
	goto Route104_EventScript_RivalEncounter
# 48 "data/maps/Route104/scripts.pory"

# 49 "data/maps/Route104/scripts.pory"
Route104_EventScript_RivalTrigger::
# 50 "data/maps/Route104/scripts.pory"
	lockall
# 51 "data/maps/Route104/scripts.pory"
	setflag FLAG_HIDE_RUSTBORO_CITY_RIVAL
# 52 "data/maps/Route104/scripts.pory"
	setvar VAR_RUSTBORO_CITY_STATE, 8
# 53 "data/maps/Route104/scripts.pory"
	setvar VAR_ROUTE104_STATE, 2
# 54 "data/maps/Route104/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
# 55 "data/maps/Route104/scripts.pory"
	waitmovement 0
# 56 "data/maps/Route104/scripts.pory"
	delay 10
# 57 "data/maps/Route104/scripts.pory"
	addobject LOCALID_ROUTE104_RIVAL
# 58 "data/maps/Route104/scripts.pory"
	clearflag FLAG_HIDE_ROUTE_104_RIVAL
# 59 "data/maps/Route104/scripts.pory"
	applymovement LOCALID_PLAYER, Route104_Movement_PlayerBackUp
# 60 "data/maps/Route104/scripts.pory"
	waitmovement 0
# 61 "data/maps/Route104/scripts.pory"
	applymovement LOCALID_ROUTE104_RIVAL, Route104_Movement_RivalExitBrineysCottage
# 62 "data/maps/Route104/scripts.pory"
	waitmovement 0
# 63 "data/maps/Route104/scripts.pory"
	delay 20
# 64 "data/maps/Route104/scripts.pory"
	setvar VAR_0x8008, 0
# 65 "data/maps/Route104/scripts.pory"
	call RustboroCity_EventScript_PlayRivalMusic
# 66 "data/maps/Route104/scripts.pory"
	playse SE_PIN
# 67 "data/maps/Route104/scripts.pory"
	applymovement LOCALID_ROUTE104_RIVAL, Common_Movement_ExclamationMark
# 68 "data/maps/Route104/scripts.pory"
	waitmovement 0
# 69 "data/maps/Route104/scripts.pory"
	applymovement LOCALID_ROUTE104_RIVAL, Common_Movement_Delay48
# 70 "data/maps/Route104/scripts.pory"
	waitmovement 0
# 71 "data/maps/Route104/scripts.pory"
	goto Route104_EventScript_RivalEncounter
# 72 "data/maps/Route104/scripts.pory"

# 73 "data/maps/Route104/scripts.pory"
@ Unused, shares script with Rustboro encounter instead
# 74 "data/maps/Route104/scripts.pory"
Route104_EventScript_PlayRivalMusic::
# 75 "data/maps/Route104/scripts.pory"
	checkplayergender
# 76 "data/maps/Route104/scripts.pory"
	goto_if_eq VAR_RESULT, MALE, Route104_EventScript_PlayMayMusic
# 77 "data/maps/Route104/scripts.pory"
	goto_if_eq VAR_RESULT, FEMALE, Route104_EventScript_PlayBrendanMusic
# 78 "data/maps/Route104/scripts.pory"
	return
# 79 "data/maps/Route104/scripts.pory"

# 80 "data/maps/Route104/scripts.pory"
Route104_EventScript_PlayMayMusic::
# 81 "data/maps/Route104/scripts.pory"
	playbgm MUS_ENCOUNTER_MAY, TRUE
# 82 "data/maps/Route104/scripts.pory"
	return
# 83 "data/maps/Route104/scripts.pory"

# 84 "data/maps/Route104/scripts.pory"
Route104_EventScript_PlayBrendanMusic::
# 85 "data/maps/Route104/scripts.pory"
	playbgm MUS_ENCOUNTER_BRENDAN, TRUE
# 86 "data/maps/Route104/scripts.pory"
	return
# 87 "data/maps/Route104/scripts.pory"

# 88 "data/maps/Route104/scripts.pory"
Route104_EventScript_RivalEncounter::
# 89 "data/maps/Route104/scripts.pory"
	checkplayergender
# 90 "data/maps/Route104/scripts.pory"
	goto_if_eq VAR_RESULT, MALE, Route104_EventScript_MayEncounter
# 91 "data/maps/Route104/scripts.pory"
	goto_if_eq VAR_RESULT, FEMALE, Route104_EventScript_BrendanEncounter
# 92 "data/maps/Route104/scripts.pory"
	end
# 93 "data/maps/Route104/scripts.pory"

# 94 "data/maps/Route104/scripts.pory"
Route104_EventScript_MayEncounter::
# 95 "data/maps/Route104/scripts.pory"
	goto_if_set FLAG_DEFEATED_RIVAL_ROUTE_104, Route104_EventScript_MayDefeated
# 96 "data/maps/Route104/scripts.pory"
	goto_if_set FLAG_REGISTER_RIVAL_POKENAV, Route104_EventScript_MayAskToBattle
# 97 "data/maps/Route104/scripts.pory"
	setflag FLAG_REGISTER_RIVAL_POKENAV
# 98 "data/maps/Route104/scripts.pory"
	msgbox Route104_Text_MayWeShouldRegister, MSGBOX_DEFAULT
# 99 "data/maps/Route104/scripts.pory"
	closemessage
# 100 "data/maps/Route104/scripts.pory"
	delay 30
# 101 "data/maps/Route104/scripts.pory"
	playfanfare MUS_REGISTER_MATCH_CALL
# 102 "data/maps/Route104/scripts.pory"
	msgbox Route104_Text_RegisteredMay, MSGBOX_DEFAULT
# 103 "data/maps/Route104/scripts.pory"
	waitfanfare
# 104 "data/maps/Route104/scripts.pory"
	closemessage
# 105 "data/maps/Route104/scripts.pory"
	delay 30
# 106 "data/maps/Route104/scripts.pory"
	setflag FLAG_ENABLE_RIVAL_MATCH_CALL
# 107 "data/maps/Route104/scripts.pory"
	applymovement LOCALID_PLAYER, Route104_Movement_PlayerFaceRival
# 108 "data/maps/Route104/scripts.pory"
	applymovement LOCALID_ROUTE104_RIVAL, Route104_Movement_RivalWalkSlowLeft
# 109 "data/maps/Route104/scripts.pory"
	msgbox Route104_Text_MayHowsYourPokedex, MSGBOX_DEFAULT
# 110 "data/maps/Route104/scripts.pory"
	closemessage
# 111 "data/maps/Route104/scripts.pory"
	waitmovement 0
# 112 "data/maps/Route104/scripts.pory"
	applymovement LOCALID_ROUTE104_RIVAL, Route104_Movement_RivalApproachPlayer
# 113 "data/maps/Route104/scripts.pory"
	waitmovement 0
# 114 "data/maps/Route104/scripts.pory"
	copyobjectxytoperm LOCALID_ROUTE104_RIVAL
# 115 "data/maps/Route104/scripts.pory"
	msgbox Route104_Text_MayMinesDecentLetsBattle, MSGBOX_YESNO
# 116 "data/maps/Route104/scripts.pory"
	goto_if_eq VAR_RESULT, YES, Route104_EventScript_BattleMay
# 117 "data/maps/Route104/scripts.pory"
	msgbox Route104_Text_MayHaventRaisedPokemon, MSGBOX_DEFAULT
# 118 "data/maps/Route104/scripts.pory"
	call Route104_EventScript_RestoreMusic
# 119 "data/maps/Route104/scripts.pory"
	releaseall
# 120 "data/maps/Route104/scripts.pory"
	end
# 121 "data/maps/Route104/scripts.pory"

# 122 "data/maps/Route104/scripts.pory"
Route104_Movement_RivalWalkSlowLeft:
# 123 "data/maps/Route104/scripts.pory"
	walk_slow_left
# 124 "data/maps/Route104/scripts.pory"
	step_end
# 125 "data/maps/Route104/scripts.pory"

# 126 "data/maps/Route104/scripts.pory"
Route104_Movement_RivalApproachPlayer:
# 127 "data/maps/Route104/scripts.pory"
	walk_down
# 128 "data/maps/Route104/scripts.pory"
	face_right
# 129 "data/maps/Route104/scripts.pory"
	step_end
# 130 "data/maps/Route104/scripts.pory"

# 131 "data/maps/Route104/scripts.pory"
Route104_Movement_PlayerFaceRival:
# 132 "data/maps/Route104/scripts.pory"
	delay_4
# 133 "data/maps/Route104/scripts.pory"
	walk_in_place_faster_left
# 134 "data/maps/Route104/scripts.pory"
	step_end
# 135 "data/maps/Route104/scripts.pory"

# 136 "data/maps/Route104/scripts.pory"
Route104_EventScript_MayAskToBattle::
# 137 "data/maps/Route104/scripts.pory"
	msgbox Route104_Text_MayLetsBattle, MSGBOX_YESNO
# 138 "data/maps/Route104/scripts.pory"
	goto_if_eq VAR_RESULT, YES, Route104_EventScript_BattleMay
# 139 "data/maps/Route104/scripts.pory"
	msgbox Route104_Text_MayHaventRaisedPokemon, MSGBOX_DEFAULT
# 140 "data/maps/Route104/scripts.pory"
	releaseall
# 141 "data/maps/Route104/scripts.pory"
	end
# 142 "data/maps/Route104/scripts.pory"

# 143 "data/maps/Route104/scripts.pory"
Route104_EventScript_BattleMay::
# 144 "data/maps/Route104/scripts.pory"
	msgbox Route104_Text_MayIntro, MSGBOX_DEFAULT
# 145 "data/maps/Route104/scripts.pory"
	switch VAR_STARTER_MON
# 146 "data/maps/Route104/scripts.pory"
	case 0, Route104_EventScript_BattleMayTreecko
# 147 "data/maps/Route104/scripts.pory"
	case 1, Route104_EventScript_BattleMayTorchic
# 148 "data/maps/Route104/scripts.pory"
	case 2, Route104_EventScript_BattleMayMudkip
# 149 "data/maps/Route104/scripts.pory"
	end
# 150 "data/maps/Route104/scripts.pory"

# 151 "data/maps/Route104/scripts.pory"
Route104_EventScript_MayDefeated::
# 152 "data/maps/Route104/scripts.pory"
	msgbox Route104_Text_MayPostBattle, MSGBOX_DEFAULT
# 153 "data/maps/Route104/scripts.pory"
	call_if_eq VAR_0x8008, 0, Route104_EventScript_RestoreMusic
# 154 "data/maps/Route104/scripts.pory"
	releaseall
# 155 "data/maps/Route104/scripts.pory"
	end
# 156 "data/maps/Route104/scripts.pory"

# 157 "data/maps/Route104/scripts.pory"
Route104_EventScript_RestoreMusic::
# 158 "data/maps/Route104/scripts.pory"
	savebgm MUS_DUMMY
# 159 "data/maps/Route104/scripts.pory"
	fadedefaultbgm
# 160 "data/maps/Route104/scripts.pory"
	return
# 161 "data/maps/Route104/scripts.pory"

# 162 "data/maps/Route104/scripts.pory"
Route104_EventScript_BattleMayTreecko::
# 163 "data/maps/Route104/scripts.pory"
	trainerbattle_no_intro TRAINER_MAY_RUSTBORO_TREECKO, Route104_Text_MayDefeat
# 164 "data/maps/Route104/scripts.pory"
	setflag FLAG_DEFEATED_RIVAL_ROUTE_104
# 165 "data/maps/Route104/scripts.pory"
	goto Route104_EventScript_MayDefeated
# 166 "data/maps/Route104/scripts.pory"
	end
# 167 "data/maps/Route104/scripts.pory"

# 168 "data/maps/Route104/scripts.pory"
Route104_EventScript_BattleMayTorchic::
# 169 "data/maps/Route104/scripts.pory"
	trainerbattle_no_intro TRAINER_MAY_RUSTBORO_TORCHIC, Route104_Text_MayDefeat
# 170 "data/maps/Route104/scripts.pory"
	setflag FLAG_DEFEATED_RIVAL_ROUTE_104
# 171 "data/maps/Route104/scripts.pory"
	goto Route104_EventScript_MayDefeated
# 172 "data/maps/Route104/scripts.pory"
	end
# 173 "data/maps/Route104/scripts.pory"

# 174 "data/maps/Route104/scripts.pory"
Route104_EventScript_BattleMayMudkip::
# 175 "data/maps/Route104/scripts.pory"
	trainerbattle_no_intro TRAINER_MAY_RUSTBORO_MUDKIP, Route104_Text_MayDefeat
# 176 "data/maps/Route104/scripts.pory"
	setflag FLAG_DEFEATED_RIVAL_ROUTE_104
# 177 "data/maps/Route104/scripts.pory"
	goto Route104_EventScript_MayDefeated
# 178 "data/maps/Route104/scripts.pory"
	end
# 179 "data/maps/Route104/scripts.pory"

# 180 "data/maps/Route104/scripts.pory"
Route104_EventScript_BrendanEncounter::
# 181 "data/maps/Route104/scripts.pory"
	goto_if_set FLAG_DEFEATED_RIVAL_ROUTE_104, Route104_EventScript_BrendanDefeated
# 182 "data/maps/Route104/scripts.pory"
	goto_if_set FLAG_REGISTER_RIVAL_POKENAV, Route104_EventScript_BrendanAskToBattle
# 183 "data/maps/Route104/scripts.pory"
	setflag FLAG_REGISTER_RIVAL_POKENAV
# 184 "data/maps/Route104/scripts.pory"
	msgbox Route104_Text_BrendanWeShouldRegister, MSGBOX_DEFAULT
# 185 "data/maps/Route104/scripts.pory"
	closemessage
# 186 "data/maps/Route104/scripts.pory"
	delay 30
# 187 "data/maps/Route104/scripts.pory"
	playfanfare MUS_REGISTER_MATCH_CALL
# 188 "data/maps/Route104/scripts.pory"
	msgbox Route104_Text_RegisteredBrendan, MSGBOX_DEFAULT
# 189 "data/maps/Route104/scripts.pory"
	waitfanfare
# 190 "data/maps/Route104/scripts.pory"
	closemessage
# 191 "data/maps/Route104/scripts.pory"
	delay 30
# 192 "data/maps/Route104/scripts.pory"
	setflag FLAG_ENABLE_RIVAL_MATCH_CALL
# 193 "data/maps/Route104/scripts.pory"
	applymovement LOCALID_PLAYER, Route104_Movement_PlayerFaceRival
# 194 "data/maps/Route104/scripts.pory"
	applymovement LOCALID_ROUTE104_RIVAL, Route104_Movement_RivalWalkSlowLeft
# 195 "data/maps/Route104/scripts.pory"
	msgbox Route104_Text_BrendanHowsYourPokedex, MSGBOX_DEFAULT
# 196 "data/maps/Route104/scripts.pory"
	closemessage
# 197 "data/maps/Route104/scripts.pory"
	waitmovement 0
# 198 "data/maps/Route104/scripts.pory"
	applymovement LOCALID_ROUTE104_RIVAL, Route104_Movement_RivalApproachPlayer
# 199 "data/maps/Route104/scripts.pory"
	waitmovement 0
# 200 "data/maps/Route104/scripts.pory"
	copyobjectxytoperm LOCALID_ROUTE104_RIVAL
# 201 "data/maps/Route104/scripts.pory"
	msgbox Route104_Text_BrendanDoingGreatLetsBattle, MSGBOX_YESNO
# 202 "data/maps/Route104/scripts.pory"
	goto_if_eq VAR_RESULT, YES, Route104_EventScript_BattleBrendan
# 203 "data/maps/Route104/scripts.pory"
	msgbox Route104_Text_BrendanNoConfidence, MSGBOX_DEFAULT
# 204 "data/maps/Route104/scripts.pory"
	call Route104_EventScript_RestoreMusic
# 205 "data/maps/Route104/scripts.pory"
	releaseall
# 206 "data/maps/Route104/scripts.pory"
	end
# 207 "data/maps/Route104/scripts.pory"

# 208 "data/maps/Route104/scripts.pory"
Route104_EventScript_BrendanAskToBattle::
# 209 "data/maps/Route104/scripts.pory"
	msgbox Route104_Text_BrendanLetsBattle, MSGBOX_YESNO
# 210 "data/maps/Route104/scripts.pory"
	goto_if_eq VAR_RESULT, YES, Route104_EventScript_BattleBrendan
# 211 "data/maps/Route104/scripts.pory"
	msgbox Route104_Text_BrendanNoConfidence, MSGBOX_DEFAULT
# 212 "data/maps/Route104/scripts.pory"
	releaseall
# 213 "data/maps/Route104/scripts.pory"
	end
# 214 "data/maps/Route104/scripts.pory"

# 215 "data/maps/Route104/scripts.pory"
Route104_EventScript_BattleBrendan::
# 216 "data/maps/Route104/scripts.pory"
	msgbox Route104_Text_BrendanIntro, MSGBOX_DEFAULT
# 217 "data/maps/Route104/scripts.pory"
	switch VAR_STARTER_MON
# 218 "data/maps/Route104/scripts.pory"
	case 0, Route104_EventScript_BattleBrendanTreecko
# 219 "data/maps/Route104/scripts.pory"
	case 1, Route104_EventScript_BattleBrendanTorchic
# 220 "data/maps/Route104/scripts.pory"
	case 2, Route104_EventScript_BattleBrendanMudkip
# 221 "data/maps/Route104/scripts.pory"
	end
# 222 "data/maps/Route104/scripts.pory"

# 223 "data/maps/Route104/scripts.pory"
Route104_EventScript_BrendanDefeated::
# 224 "data/maps/Route104/scripts.pory"
	msgbox Route104_Text_BrendanPostBattle, MSGBOX_DEFAULT
# 225 "data/maps/Route104/scripts.pory"
	call_if_eq VAR_0x8008, 0, Route104_EventScript_RestoreMusic
# 226 "data/maps/Route104/scripts.pory"
	releaseall
# 227 "data/maps/Route104/scripts.pory"
	end
# 228 "data/maps/Route104/scripts.pory"

# 229 "data/maps/Route104/scripts.pory"
Route104_EventScript_BattleBrendanTreecko::
# 230 "data/maps/Route104/scripts.pory"
	trainerbattle_no_intro TRAINER_BRENDAN_RUSTBORO_TREECKO, Route104_Text_BrendanDefeat
# 231 "data/maps/Route104/scripts.pory"
	setflag FLAG_DEFEATED_RIVAL_ROUTE_104
# 232 "data/maps/Route104/scripts.pory"
	goto Route104_EventScript_BrendanDefeated
# 233 "data/maps/Route104/scripts.pory"
	end
# 234 "data/maps/Route104/scripts.pory"

# 235 "data/maps/Route104/scripts.pory"
Route104_EventScript_BattleBrendanTorchic::
# 236 "data/maps/Route104/scripts.pory"
	trainerbattle_no_intro TRAINER_BRENDAN_RUSTBORO_TORCHIC, Route104_Text_BrendanDefeat
# 237 "data/maps/Route104/scripts.pory"
	setflag FLAG_DEFEATED_RIVAL_ROUTE_104
# 238 "data/maps/Route104/scripts.pory"
	goto Route104_EventScript_BrendanDefeated
# 239 "data/maps/Route104/scripts.pory"
	end
# 240 "data/maps/Route104/scripts.pory"

# 241 "data/maps/Route104/scripts.pory"
Route104_EventScript_BattleBrendanMudkip::
# 242 "data/maps/Route104/scripts.pory"
	trainerbattle_no_intro TRAINER_BRENDAN_RUSTBORO_MUDKIP, Route104_Text_BrendanDefeat
# 243 "data/maps/Route104/scripts.pory"
	setflag FLAG_DEFEATED_RIVAL_ROUTE_104
# 244 "data/maps/Route104/scripts.pory"
	goto Route104_EventScript_BrendanDefeated
# 245 "data/maps/Route104/scripts.pory"
	end
# 246 "data/maps/Route104/scripts.pory"

# 247 "data/maps/Route104/scripts.pory"
Route104_Movement_PlayerBackUp:
# 248 "data/maps/Route104/scripts.pory"
	lock_facing_direction
# 249 "data/maps/Route104/scripts.pory"
	walk_down
# 250 "data/maps/Route104/scripts.pory"
	unlock_facing_direction
# 251 "data/maps/Route104/scripts.pory"
	step_end
# 252 "data/maps/Route104/scripts.pory"

# 253 "data/maps/Route104/scripts.pory"
Route104_Movement_RivalExitBrineysCottage:
# 254 "data/maps/Route104/scripts.pory"
	walk_down
# 255 "data/maps/Route104/scripts.pory"
	step_end
# 256 "data/maps/Route104/scripts.pory"

# 257 "data/maps/Route104/scripts.pory"
Route104_EventScript_ExpertF::
# 258 "data/maps/Route104/scripts.pory"
	lock
# 259 "data/maps/Route104/scripts.pory"
	faceplayer
# 260 "data/maps/Route104/scripts.pory"
	goto_if_set FLAG_RECEIVED_CHESTO_BERRY_ROUTE_104, Route104_EventScript_ReceivedBerry
# 261 "data/maps/Route104/scripts.pory"
	msgbox Route104_Text_PlantBerriesInSoilTakeThis, MSGBOX_DEFAULT
# 262 "data/maps/Route104/scripts.pory"
	giveitem ITEM_CHESTO_BERRY
# 263 "data/maps/Route104/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
# 264 "data/maps/Route104/scripts.pory"
	setflag FLAG_RECEIVED_CHESTO_BERRY_ROUTE_104
# 265 "data/maps/Route104/scripts.pory"
	msgbox Route104_Text_TrainersOftenMakeMonHoldBerries, MSGBOX_DEFAULT
# 266 "data/maps/Route104/scripts.pory"
	release
# 267 "data/maps/Route104/scripts.pory"
	end
# 268 "data/maps/Route104/scripts.pory"

# 269 "data/maps/Route104/scripts.pory"
Route104_EventScript_ReceivedBerry::
# 270 "data/maps/Route104/scripts.pory"
	msgbox Route104_Text_TrainersOftenMakeMonHoldBerries, MSGBOX_DEFAULT
# 271 "data/maps/Route104/scripts.pory"
	release
# 272 "data/maps/Route104/scripts.pory"
	end
# 273 "data/maps/Route104/scripts.pory"

# 274 "data/maps/Route104/scripts.pory"
Route104_EventScript_WhiteHerbFlorist::
# 275 "data/maps/Route104/scripts.pory"
	lock
# 276 "data/maps/Route104/scripts.pory"
	faceplayer
# 277 "data/maps/Route104/scripts.pory"
	goto_if_set FLAG_RECEIVED_WHITE_HERB, Route104_EventScript_ReceivedWhiteHerb
# 278 "data/maps/Route104/scripts.pory"
	msgbox Route104_Text_DontNeedThisTakeIt, MSGBOX_DEFAULT
# 279 "data/maps/Route104/scripts.pory"
	giveitem ITEM_WHITE_HERB
# 280 "data/maps/Route104/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
# 281 "data/maps/Route104/scripts.pory"
	setflag FLAG_RECEIVED_WHITE_HERB
# 282 "data/maps/Route104/scripts.pory"
	release
# 283 "data/maps/Route104/scripts.pory"
	end
# 284 "data/maps/Route104/scripts.pory"

# 285 "data/maps/Route104/scripts.pory"
Route104_EventScript_ReceivedWhiteHerb::
# 286 "data/maps/Route104/scripts.pory"
	msgbox Route104_Text_FlowerShopSellingSaplings, MSGBOX_DEFAULT
# 287 "data/maps/Route104/scripts.pory"
	release
# 288 "data/maps/Route104/scripts.pory"
	end
# 289 "data/maps/Route104/scripts.pory"

# 290 "data/maps/Route104/scripts.pory"

# 291 "data/maps/Route104/scripts.pory"

# 292 "data/maps/Route104/scripts.pory"

# 293 "data/maps/Route104/scripts.pory"

# 294 "data/maps/Route104/scripts.pory"
Route104_EventScript_BrineysCottageSign::
# 295 "data/maps/Route104/scripts.pory"
	msgbox Route104_Text_MrBrineysCottage, MSGBOX_SIGN
# 296 "data/maps/Route104/scripts.pory"
	end
# 297 "data/maps/Route104/scripts.pory"

# 298 "data/maps/Route104/scripts.pory"
Route104_EventScript_RouteSignPetalburg::
# 299 "data/maps/Route104/scripts.pory"
	msgbox Route104_Text_RouteSignPetalburg, MSGBOX_SIGN
# 300 "data/maps/Route104/scripts.pory"
	end
# 301 "data/maps/Route104/scripts.pory"

# 302 "data/maps/Route104/scripts.pory"
Route104_EventScript_RouteSignRustboro::
# 303 "data/maps/Route104/scripts.pory"
	msgbox Route104_Text_RouteSignRustboro, MSGBOX_SIGN
# 304 "data/maps/Route104/scripts.pory"
	end
# 305 "data/maps/Route104/scripts.pory"

# 306 "data/maps/Route104/scripts.pory"
Route104_EventScript_FlowerShopSign::
# 307 "data/maps/Route104/scripts.pory"
	msgbox Route104_Text_PrettyPetalFlowShop, MSGBOX_SIGN
# 308 "data/maps/Route104/scripts.pory"
	end
# 309 "data/maps/Route104/scripts.pory"

# 310 "data/maps/Route104/scripts.pory"
Route104_EventScript_TrainerTipsDoubleBattles::
# 311 "data/maps/Route104/scripts.pory"
	msgbox Route104_Text_TrainerTipsDoubleBattles, MSGBOX_SIGN
# 312 "data/maps/Route104/scripts.pory"
	end
# 313 "data/maps/Route104/scripts.pory"

# 314 "data/maps/Route104/scripts.pory"

# 315 "data/maps/Route104/scripts.pory"
Route104_EventScript_Woman::
# 316 "data/maps/Route104/scripts.pory"
	msgbox Route104_Text_OnlyThrowBallAtWildPokemon, MSGBOX_NPC
# 317 "data/maps/Route104/scripts.pory"
	end
# 318 "data/maps/Route104/scripts.pory"

# 319 "data/maps/Route104/scripts.pory"
Route104_EventScript_Boy2::
# 320 "data/maps/Route104/scripts.pory"
	lock
# 321 "data/maps/Route104/scripts.pory"
	faceplayer
# 322 "data/maps/Route104/scripts.pory"
	goto_if_set FLAG_RECEIVED_TM_BULLET_SEED, Route104_EventScript_ReceivedBulletSeed
# 323 "data/maps/Route104/scripts.pory"
	msgbox Route104_Text_LikeFillingMouthWithSeedsTakeThis, MSGBOX_DEFAULT
# 324 "data/maps/Route104/scripts.pory"
	giveitem ITEM_TM_BULLET_SEED
# 325 "data/maps/Route104/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
# 326 "data/maps/Route104/scripts.pory"
	setflag FLAG_RECEIVED_TM_BULLET_SEED
# 327 "data/maps/Route104/scripts.pory"
	release
# 328 "data/maps/Route104/scripts.pory"
	end
# 329 "data/maps/Route104/scripts.pory"

# 330 "data/maps/Route104/scripts.pory"
Route104_EventScript_ReceivedBulletSeed::
# 331 "data/maps/Route104/scripts.pory"
	msgbox Route104_Text_TMsAreOneTimeUse, MSGBOX_DEFAULT
# 332 "data/maps/Route104/scripts.pory"
	release
# 333 "data/maps/Route104/scripts.pory"
	end
# 334 "data/maps/Route104/scripts.pory"

# 335 "data/maps/Route104/scripts.pory"
Route104_EventScript_Girl2::
# 336 "data/maps/Route104/scripts.pory"
	msgbox Route104_Text_ImNotATrainer, MSGBOX_NPC
# 337 "data/maps/Route104/scripts.pory"
	end
# 338 "data/maps/Route104/scripts.pory"

# 339 "data/maps/Route104/scripts.pory"
Route104_EventScript_SailToDewford::
# 340 "data/maps/Route104/scripts.pory"
	setobjectsubpriority LOCALID_ROUTE104_BRINEY, MAP_ROUTE104, 0
# 341 "data/maps/Route104/scripts.pory"
	setobjectsubpriority LOCALID_PLAYER, MAP_ROUTE104, 0
# 342 "data/maps/Route104/scripts.pory"
	applymovement LOCALID_ROUTE104_BRINEY, Route104_Movement_BrineyBoardBoat
# 343 "data/maps/Route104/scripts.pory"
	waitmovement 0
# 344 "data/maps/Route104/scripts.pory"
	removeobject LOCALID_ROUTE104_BRINEY
# 345 "data/maps/Route104/scripts.pory"
	applymovement LOCALID_PLAYER, Route104_Movement_PlayerBoardBoat
# 346 "data/maps/Route104/scripts.pory"
	waitmovement 0
# 347 "data/maps/Route104/scripts.pory"
	hideobjectat LOCALID_PLAYER, MAP_ROUTE104
# 348 "data/maps/Route104/scripts.pory"
	call Common_EventScript_PlayBrineysBoatMusic
# 349 "data/maps/Route104/scripts.pory"
	goto_if_set FLAG_ENABLE_NORMAN_MATCH_CALL, Route104_EventScript_SailToDewfordNoCall
# 350 "data/maps/Route104/scripts.pory"
	goto_if_unset FLAG_ENABLE_NORMAN_MATCH_CALL, Route104_EventScript_SailToDewfordDadCalls
# 351 "data/maps/Route104/scripts.pory"
	end
# 352 "data/maps/Route104/scripts.pory"

# 353 "data/maps/Route104/scripts.pory"
Route104_EventScript_SailToDewfordNoCall::
# 354 "data/maps/Route104/scripts.pory"
	applymovement LOCALID_ROUTE104_BOAT, Route104_Movement_SailToDewford
# 355 "data/maps/Route104/scripts.pory"
	applymovement LOCALID_PLAYER, Route104_Movement_SailToDewford
# 356 "data/maps/Route104/scripts.pory"
	waitmovement 0
# 357 "data/maps/Route104/scripts.pory"
	goto Route104_EventScript_ArriveInDewford
# 358 "data/maps/Route104/scripts.pory"

# 359 "data/maps/Route104/scripts.pory"
Route104_EventScript_SailToDewfordDadCalls::
# 360 "data/maps/Route104/scripts.pory"
	applymovement LOCALID_ROUTE104_BOAT, Route104_Movement_SailToDewfordBeforeDadCalls
# 361 "data/maps/Route104/scripts.pory"
	applymovement LOCALID_PLAYER, Route104_Movement_SailToDewfordBeforeDadCalls
# 362 "data/maps/Route104/scripts.pory"
	waitmovement 0
# 363 "data/maps/Route104/scripts.pory"
	pokenavcall Route104_Text_DadPokenavCall
# 364 "data/maps/Route104/scripts.pory"
	waitmessage
# 365 "data/maps/Route104/scripts.pory"
	delay 30
# 366 "data/maps/Route104/scripts.pory"
	playfanfare MUS_REGISTER_MATCH_CALL
# 367 "data/maps/Route104/scripts.pory"
	msgbox Route104_Text_RegisteredDadInPokenav, MSGBOX_DEFAULT
# 368 "data/maps/Route104/scripts.pory"
	waitfanfare
# 369 "data/maps/Route104/scripts.pory"
	closemessage
# 370 "data/maps/Route104/scripts.pory"
	delay 30
# 371 "data/maps/Route104/scripts.pory"
	setflag FLAG_ENABLE_NORMAN_MATCH_CALL
# 372 "data/maps/Route104/scripts.pory"
	applymovement LOCALID_PLAYER, Route104_Movement_SailToDewfordAfterDadCalls
# 373 "data/maps/Route104/scripts.pory"
	applymovement LOCALID_ROUTE104_BOAT, Route104_Movement_SailToDewfordAfterDadCalls, MAP_ROUTE104
# 374 "data/maps/Route104/scripts.pory"
	waitmovement LOCALID_ROUTE104_BOAT, MAP_ROUTE104
# 375 "data/maps/Route104/scripts.pory"
	waitmovement 0
# 376 "data/maps/Route104/scripts.pory"
	goto Route104_EventScript_ArriveInDewford
# 377 "data/maps/Route104/scripts.pory"

# 378 "data/maps/Route104/scripts.pory"
Route104_EventScript_ArriveInDewford::
# 379 "data/maps/Route104/scripts.pory"
	delay 50
# 380 "data/maps/Route104/scripts.pory"
	applymovement LOCALID_PLAYER, Route104_Movement_PlayerExitBoat
# 381 "data/maps/Route104/scripts.pory"
	waitmovement 0
# 382 "data/maps/Route104/scripts.pory"
	call Common_EventScript_StopBrineysBoatMusic
# 383 "data/maps/Route104/scripts.pory"
	showobjectat LOCALID_PLAYER, MAP_DEWFORD_TOWN
# 384 "data/maps/Route104/scripts.pory"
	applymovement LOCALID_PLAYER, Route104_Movement_PlayerMoveForBriney
# 385 "data/maps/Route104/scripts.pory"
	waitmovement 0
# 386 "data/maps/Route104/scripts.pory"
	setobjectxyperm LOCALID_DEWFORD_BRINEY, 12, 8
# 387 "data/maps/Route104/scripts.pory"
	addobject LOCALID_DEWFORD_BRINEY
# 388 "data/maps/Route104/scripts.pory"
	setobjectsubpriority LOCALID_DEWFORD_BRINEY, MAP_DEWFORD_TOWN, 0
# 389 "data/maps/Route104/scripts.pory"
	clearflag FLAG_HIDE_MR_BRINEY_DEWFORD_TOWN
# 390 "data/maps/Route104/scripts.pory"
	applymovement LOCALID_DEWFORD_BRINEY, Route104_Movement_BrineyExitBoat
# 391 "data/maps/Route104/scripts.pory"
	waitmovement 0
# 392 "data/maps/Route104/scripts.pory"
	addobject LOCALID_DEWFORD_BOAT
# 393 "data/maps/Route104/scripts.pory"
	clearflag FLAG_HIDE_MR_BRINEY_BOAT_DEWFORD_TOWN
# 394 "data/maps/Route104/scripts.pory"
	call Common_EventScript_StopBrineysBoatMusic
# 395 "data/maps/Route104/scripts.pory"
	setflag FLAG_HIDE_ROUTE_104_MR_BRINEY_BOAT
# 396 "data/maps/Route104/scripts.pory"
	hideobjectat LOCALID_ROUTE104_BOAT, MAP_ROUTE104
# 397 "data/maps/Route104/scripts.pory"
	copyvar VAR_BRINEY_LOCATION, VAR_0x8008
# 398 "data/maps/Route104/scripts.pory"
	resetobjectsubpriority LOCALID_PLAYER, MAP_ROUTE104
# 399 "data/maps/Route104/scripts.pory"
	resetobjectsubpriority LOCALID_DEWFORD_BRINEY, MAP_DEWFORD_TOWN
# 400 "data/maps/Route104/scripts.pory"
	copyobjectxytoperm LOCALID_DEWFORD_BRINEY
# 401 "data/maps/Route104/scripts.pory"
	setvar VAR_BOARD_BRINEY_BOAT_STATE, 0
# 402 "data/maps/Route104/scripts.pory"
	goto_if_unset FLAG_DELIVERED_STEVEN_LETTER, Route104_EventScript_DeliverLetterReminder
# 403 "data/maps/Route104/scripts.pory"
	goto_if_set FLAG_DELIVERED_STEVEN_LETTER, Route104_EventScript_LandedInDewford
# 404 "data/maps/Route104/scripts.pory"
	end
# 405 "data/maps/Route104/scripts.pory"

# 406 "data/maps/Route104/scripts.pory"
Route104_EventScript_DeliverLetterReminder::
# 407 "data/maps/Route104/scripts.pory"
	msgbox Route104_Text_LandedInDewfordDeliverLetter, MSGBOX_DEFAULT
# 408 "data/maps/Route104/scripts.pory"
	releaseall
# 409 "data/maps/Route104/scripts.pory"
	end
# 410 "data/maps/Route104/scripts.pory"

# 411 "data/maps/Route104/scripts.pory"
Route104_EventScript_LandedInDewford::
# 412 "data/maps/Route104/scripts.pory"
	msgbox DewfordTown_Text_BrineyLandedInDewford, MSGBOX_DEFAULT
# 413 "data/maps/Route104/scripts.pory"
	releaseall
# 414 "data/maps/Route104/scripts.pory"
	end
# 415 "data/maps/Route104/scripts.pory"

# 416 "data/maps/Route104/scripts.pory"
Route104_Movement_SailToDewfordBeforeDadCalls:
# 417 "data/maps/Route104/scripts.pory"
	walk_down
# 418 "data/maps/Route104/scripts.pory"
	walk_down
# 419 "data/maps/Route104/scripts.pory"
	walk_down
# 420 "data/maps/Route104/scripts.pory"
	walk_down
# 421 "data/maps/Route104/scripts.pory"
	walk_fast_down
# 422 "data/maps/Route104/scripts.pory"
	walk_fast_down
# 423 "data/maps/Route104/scripts.pory"
	walk_fast_down
# 424 "data/maps/Route104/scripts.pory"
	walk_fast_down
# 425 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 426 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 427 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 428 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 429 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 430 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 431 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 432 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 433 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 434 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 435 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 436 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 437 "data/maps/Route104/scripts.pory"
	walk_fast_down
# 438 "data/maps/Route104/scripts.pory"
	walk_fast_down
# 439 "data/maps/Route104/scripts.pory"
	walk_fast_down
# 440 "data/maps/Route104/scripts.pory"
	walk_fast_down
# 441 "data/maps/Route104/scripts.pory"
	walk_fast_right
# 442 "data/maps/Route104/scripts.pory"
	walk_fast_right
# 443 "data/maps/Route104/scripts.pory"
	walk_faster_right
# 444 "data/maps/Route104/scripts.pory"
	walk_faster_right
# 445 "data/maps/Route104/scripts.pory"
	walk_faster_right
# 446 "data/maps/Route104/scripts.pory"
	walk_faster_right
# 447 "data/maps/Route104/scripts.pory"
	walk_faster_right
# 448 "data/maps/Route104/scripts.pory"
	walk_faster_right
# 449 "data/maps/Route104/scripts.pory"
	walk_fast_right
# 450 "data/maps/Route104/scripts.pory"
	walk_fast_right
# 451 "data/maps/Route104/scripts.pory"
	walk_fast_down
# 452 "data/maps/Route104/scripts.pory"
	walk_fast_down
# 453 "data/maps/Route104/scripts.pory"
	walk_fast_down
# 454 "data/maps/Route104/scripts.pory"
	walk_fast_down
# 455 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 456 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 457 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 458 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 459 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 460 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 461 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 462 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 463 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 464 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 465 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 466 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 467 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 468 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 469 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 470 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 471 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 472 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 473 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 474 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 475 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 476 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 477 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 478 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 479 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 480 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 481 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 482 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 483 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 484 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 485 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 486 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 487 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 488 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 489 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 490 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 491 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 492 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 493 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 494 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 495 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 496 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 497 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 498 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 499 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 500 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 501 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 502 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 503 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 504 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 505 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 506 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 507 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 508 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 509 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 510 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 511 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 512 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 513 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 514 "data/maps/Route104/scripts.pory"
	step_end
# 515 "data/maps/Route104/scripts.pory"

# 516 "data/maps/Route104/scripts.pory"
Route104_Movement_SailToDewfordAfterDadCalls:
# 517 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 518 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 519 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 520 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 521 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 522 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 523 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 524 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 525 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 526 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 527 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 528 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 529 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 530 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 531 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 532 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 533 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 534 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 535 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 536 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 537 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 538 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 539 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 540 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 541 "data/maps/Route104/scripts.pory"
	walk_fast_down
# 542 "data/maps/Route104/scripts.pory"
	walk_fast_down
# 543 "data/maps/Route104/scripts.pory"
	walk_fast_down
# 544 "data/maps/Route104/scripts.pory"
	walk_fast_down
# 545 "data/maps/Route104/scripts.pory"
	walk_fast_right
# 546 "data/maps/Route104/scripts.pory"
	walk_fast_right
# 547 "data/maps/Route104/scripts.pory"
	walk_fast_right
# 548 "data/maps/Route104/scripts.pory"
	walk_fast_right
# 549 "data/maps/Route104/scripts.pory"
	walk_faster_right
# 550 "data/maps/Route104/scripts.pory"
	walk_faster_right
# 551 "data/maps/Route104/scripts.pory"
	walk_faster_right
# 552 "data/maps/Route104/scripts.pory"
	walk_faster_right
# 553 "data/maps/Route104/scripts.pory"
	walk_faster_right
# 554 "data/maps/Route104/scripts.pory"
	walk_faster_right
# 555 "data/maps/Route104/scripts.pory"
	walk_faster_right
# 556 "data/maps/Route104/scripts.pory"
	walk_faster_right
# 557 "data/maps/Route104/scripts.pory"
	walk_faster_right
# 558 "data/maps/Route104/scripts.pory"
	walk_faster_right
# 559 "data/maps/Route104/scripts.pory"
	walk_faster_right
# 560 "data/maps/Route104/scripts.pory"
	walk_faster_right
# 561 "data/maps/Route104/scripts.pory"
	walk_faster_right
# 562 "data/maps/Route104/scripts.pory"
	walk_faster_right
# 563 "data/maps/Route104/scripts.pory"
	walk_faster_right
# 564 "data/maps/Route104/scripts.pory"
	walk_faster_right
# 565 "data/maps/Route104/scripts.pory"
	walk_faster_right
# 566 "data/maps/Route104/scripts.pory"
	walk_faster_right
# 567 "data/maps/Route104/scripts.pory"
	walk_faster_right
# 568 "data/maps/Route104/scripts.pory"
	walk_faster_right
# 569 "data/maps/Route104/scripts.pory"
	walk_faster_right
# 570 "data/maps/Route104/scripts.pory"
	walk_faster_right
# 571 "data/maps/Route104/scripts.pory"
	walk_faster_right
# 572 "data/maps/Route104/scripts.pory"
	walk_faster_right
# 573 "data/maps/Route104/scripts.pory"
	walk_faster_right
# 574 "data/maps/Route104/scripts.pory"
	walk_faster_right
# 575 "data/maps/Route104/scripts.pory"
	walk_faster_right
# 576 "data/maps/Route104/scripts.pory"
	walk_faster_right
# 577 "data/maps/Route104/scripts.pory"
	walk_faster_right
# 578 "data/maps/Route104/scripts.pory"
	walk_faster_right
# 579 "data/maps/Route104/scripts.pory"
	walk_faster_right
# 580 "data/maps/Route104/scripts.pory"
	walk_faster_right
# 581 "data/maps/Route104/scripts.pory"
	walk_faster_right
# 582 "data/maps/Route104/scripts.pory"
	walk_faster_right
# 583 "data/maps/Route104/scripts.pory"
	walk_faster_right
# 584 "data/maps/Route104/scripts.pory"
	walk_faster_right
# 585 "data/maps/Route104/scripts.pory"
	walk_faster_right
# 586 "data/maps/Route104/scripts.pory"
	walk_faster_right
# 587 "data/maps/Route104/scripts.pory"
	walk_faster_right
# 588 "data/maps/Route104/scripts.pory"
	walk_faster_right
# 589 "data/maps/Route104/scripts.pory"
	walk_fast_right
# 590 "data/maps/Route104/scripts.pory"
	walk_fast_right
# 591 "data/maps/Route104/scripts.pory"
	walk_fast_right
# 592 "data/maps/Route104/scripts.pory"
	walk_fast_right
# 593 "data/maps/Route104/scripts.pory"
	walk_right
# 594 "data/maps/Route104/scripts.pory"
	walk_right
# 595 "data/maps/Route104/scripts.pory"
	walk_down
# 596 "data/maps/Route104/scripts.pory"
	walk_down
# 597 "data/maps/Route104/scripts.pory"
	walk_fast_down
# 598 "data/maps/Route104/scripts.pory"
	walk_fast_down
# 599 "data/maps/Route104/scripts.pory"
	walk_fast_down
# 600 "data/maps/Route104/scripts.pory"
	walk_fast_down
# 601 "data/maps/Route104/scripts.pory"
	walk_fast_down
# 602 "data/maps/Route104/scripts.pory"
	walk_fast_down
# 603 "data/maps/Route104/scripts.pory"
	walk_fast_down
# 604 "data/maps/Route104/scripts.pory"
	walk_fast_down
# 605 "data/maps/Route104/scripts.pory"
	walk_fast_down
# 606 "data/maps/Route104/scripts.pory"
	walk_fast_down
# 607 "data/maps/Route104/scripts.pory"
	walk_fast_down
# 608 "data/maps/Route104/scripts.pory"
	walk_fast_down
# 609 "data/maps/Route104/scripts.pory"
	walk_fast_down
# 610 "data/maps/Route104/scripts.pory"
	walk_fast_down
# 611 "data/maps/Route104/scripts.pory"
	walk_fast_down
# 612 "data/maps/Route104/scripts.pory"
	walk_down
# 613 "data/maps/Route104/scripts.pory"
	walk_down
# 614 "data/maps/Route104/scripts.pory"
	step_end
# 615 "data/maps/Route104/scripts.pory"

# 616 "data/maps/Route104/scripts.pory"
Route104_Movement_SailToDewford:
# 617 "data/maps/Route104/scripts.pory"
	walk_down
# 618 "data/maps/Route104/scripts.pory"
	walk_down
# 619 "data/maps/Route104/scripts.pory"
	walk_down
# 620 "data/maps/Route104/scripts.pory"
	walk_down
# 621 "data/maps/Route104/scripts.pory"
	walk_fast_down
# 622 "data/maps/Route104/scripts.pory"
	walk_fast_down
# 623 "data/maps/Route104/scripts.pory"
	walk_fast_down
# 624 "data/maps/Route104/scripts.pory"
	walk_fast_down
# 625 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 626 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 627 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 628 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 629 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 630 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 631 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 632 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 633 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 634 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 635 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 636 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 637 "data/maps/Route104/scripts.pory"
	walk_fast_down
# 638 "data/maps/Route104/scripts.pory"
	walk_fast_down
# 639 "data/maps/Route104/scripts.pory"
	walk_fast_down
# 640 "data/maps/Route104/scripts.pory"
	walk_fast_down
# 641 "data/maps/Route104/scripts.pory"
	walk_fast_right
# 642 "data/maps/Route104/scripts.pory"
	walk_fast_right
# 643 "data/maps/Route104/scripts.pory"
	walk_faster_right
# 644 "data/maps/Route104/scripts.pory"
	walk_faster_right
# 645 "data/maps/Route104/scripts.pory"
	walk_faster_right
# 646 "data/maps/Route104/scripts.pory"
	walk_faster_right
# 647 "data/maps/Route104/scripts.pory"
	walk_faster_right
# 648 "data/maps/Route104/scripts.pory"
	walk_faster_right
# 649 "data/maps/Route104/scripts.pory"
	walk_fast_right
# 650 "data/maps/Route104/scripts.pory"
	walk_fast_right
# 651 "data/maps/Route104/scripts.pory"
	walk_fast_down
# 652 "data/maps/Route104/scripts.pory"
	walk_fast_down
# 653 "data/maps/Route104/scripts.pory"
	walk_fast_down
# 654 "data/maps/Route104/scripts.pory"
	walk_fast_down
# 655 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 656 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 657 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 658 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 659 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 660 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 661 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 662 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 663 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 664 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 665 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 666 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 667 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 668 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 669 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 670 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 671 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 672 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 673 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 674 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 675 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 676 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 677 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 678 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 679 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 680 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 681 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 682 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 683 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 684 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 685 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 686 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 687 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 688 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 689 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 690 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 691 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 692 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 693 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 694 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 695 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 696 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 697 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 698 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 699 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 700 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 701 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 702 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 703 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 704 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 705 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 706 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 707 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 708 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 709 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 710 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 711 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 712 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 713 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 714 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 715 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 716 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 717 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 718 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 719 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 720 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 721 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 722 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 723 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 724 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 725 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 726 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 727 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 728 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 729 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 730 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 731 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 732 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 733 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 734 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 735 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 736 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 737 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 738 "data/maps/Route104/scripts.pory"
	walk_fast_down
# 739 "data/maps/Route104/scripts.pory"
	walk_fast_down
# 740 "data/maps/Route104/scripts.pory"
	walk_fast_down
# 741 "data/maps/Route104/scripts.pory"
	walk_fast_down
# 742 "data/maps/Route104/scripts.pory"
	walk_fast_right
# 743 "data/maps/Route104/scripts.pory"
	walk_fast_right
# 744 "data/maps/Route104/scripts.pory"
	walk_fast_right
# 745 "data/maps/Route104/scripts.pory"
	walk_fast_right
# 746 "data/maps/Route104/scripts.pory"
	walk_faster_right
# 747 "data/maps/Route104/scripts.pory"
	walk_faster_right
# 748 "data/maps/Route104/scripts.pory"
	walk_faster_right
# 749 "data/maps/Route104/scripts.pory"
	walk_faster_right
# 750 "data/maps/Route104/scripts.pory"
	walk_faster_right
# 751 "data/maps/Route104/scripts.pory"
	walk_faster_right
# 752 "data/maps/Route104/scripts.pory"
	walk_faster_right
# 753 "data/maps/Route104/scripts.pory"
	walk_faster_right
# 754 "data/maps/Route104/scripts.pory"
	walk_faster_right
# 755 "data/maps/Route104/scripts.pory"
	walk_faster_right
# 756 "data/maps/Route104/scripts.pory"
	walk_faster_right
# 757 "data/maps/Route104/scripts.pory"
	walk_faster_right
# 758 "data/maps/Route104/scripts.pory"
	walk_faster_right
# 759 "data/maps/Route104/scripts.pory"
	walk_faster_right
# 760 "data/maps/Route104/scripts.pory"
	walk_faster_right
# 761 "data/maps/Route104/scripts.pory"
	walk_faster_right
# 762 "data/maps/Route104/scripts.pory"
	walk_faster_right
# 763 "data/maps/Route104/scripts.pory"
	walk_faster_right
# 764 "data/maps/Route104/scripts.pory"
	walk_faster_right
# 765 "data/maps/Route104/scripts.pory"
	walk_faster_right
# 766 "data/maps/Route104/scripts.pory"
	walk_faster_right
# 767 "data/maps/Route104/scripts.pory"
	walk_faster_right
# 768 "data/maps/Route104/scripts.pory"
	walk_faster_right
# 769 "data/maps/Route104/scripts.pory"
	walk_faster_right
# 770 "data/maps/Route104/scripts.pory"
	walk_faster_right
# 771 "data/maps/Route104/scripts.pory"
	walk_faster_right
# 772 "data/maps/Route104/scripts.pory"
	walk_faster_right
# 773 "data/maps/Route104/scripts.pory"
	walk_faster_right
# 774 "data/maps/Route104/scripts.pory"
	walk_faster_right
# 775 "data/maps/Route104/scripts.pory"
	walk_faster_right
# 776 "data/maps/Route104/scripts.pory"
	walk_faster_right
# 777 "data/maps/Route104/scripts.pory"
	walk_faster_right
# 778 "data/maps/Route104/scripts.pory"
	walk_faster_right
# 779 "data/maps/Route104/scripts.pory"
	walk_faster_right
# 780 "data/maps/Route104/scripts.pory"
	walk_faster_right
# 781 "data/maps/Route104/scripts.pory"
	walk_faster_right
# 782 "data/maps/Route104/scripts.pory"
	walk_faster_right
# 783 "data/maps/Route104/scripts.pory"
	walk_faster_right
# 784 "data/maps/Route104/scripts.pory"
	walk_faster_right
# 785 "data/maps/Route104/scripts.pory"
	walk_faster_right
# 786 "data/maps/Route104/scripts.pory"
	walk_fast_right
# 787 "data/maps/Route104/scripts.pory"
	walk_fast_right
# 788 "data/maps/Route104/scripts.pory"
	walk_fast_right
# 789 "data/maps/Route104/scripts.pory"
	walk_fast_right
# 790 "data/maps/Route104/scripts.pory"
	walk_right
# 791 "data/maps/Route104/scripts.pory"
	walk_right
# 792 "data/maps/Route104/scripts.pory"
	walk_down
# 793 "data/maps/Route104/scripts.pory"
	walk_down
# 794 "data/maps/Route104/scripts.pory"
	walk_fast_down
# 795 "data/maps/Route104/scripts.pory"
	walk_fast_down
# 796 "data/maps/Route104/scripts.pory"
	walk_fast_down
# 797 "data/maps/Route104/scripts.pory"
	walk_fast_down
# 798 "data/maps/Route104/scripts.pory"
	walk_fast_down
# 799 "data/maps/Route104/scripts.pory"
	walk_fast_down
# 800 "data/maps/Route104/scripts.pory"
	walk_fast_down
# 801 "data/maps/Route104/scripts.pory"
	walk_fast_down
# 802 "data/maps/Route104/scripts.pory"
	walk_fast_down
# 803 "data/maps/Route104/scripts.pory"
	walk_fast_down
# 804 "data/maps/Route104/scripts.pory"
	walk_fast_down
# 805 "data/maps/Route104/scripts.pory"
	walk_fast_down
# 806 "data/maps/Route104/scripts.pory"
	walk_fast_down
# 807 "data/maps/Route104/scripts.pory"
	walk_fast_down
# 808 "data/maps/Route104/scripts.pory"
	walk_fast_down
# 809 "data/maps/Route104/scripts.pory"
	walk_down
# 810 "data/maps/Route104/scripts.pory"
	walk_down
# 811 "data/maps/Route104/scripts.pory"
	step_end
# 812 "data/maps/Route104/scripts.pory"

# 813 "data/maps/Route104/scripts.pory"
Route104_Movement_PlayerBoardBoat:
# 814 "data/maps/Route104/scripts.pory"
	walk_left
# 815 "data/maps/Route104/scripts.pory"
	walk_down
# 816 "data/maps/Route104/scripts.pory"
	walk_down
# 817 "data/maps/Route104/scripts.pory"
	step_end
# 818 "data/maps/Route104/scripts.pory"

# 819 "data/maps/Route104/scripts.pory"
Route104_Movement_PlayerExitBoat:
# 820 "data/maps/Route104/scripts.pory"
	walk_down
# 821 "data/maps/Route104/scripts.pory"
	step_end
# 822 "data/maps/Route104/scripts.pory"

# 823 "data/maps/Route104/scripts.pory"
Route104_Movement_PlayerMoveForBriney:
# 824 "data/maps/Route104/scripts.pory"
	walk_down
# 825 "data/maps/Route104/scripts.pory"
	walk_left
# 826 "data/maps/Route104/scripts.pory"
	walk_in_place_faster_right
# 827 "data/maps/Route104/scripts.pory"
	step_end
# 828 "data/maps/Route104/scripts.pory"

# 829 "data/maps/Route104/scripts.pory"
Route104_Movement_BrineyBoardBoat:
# 830 "data/maps/Route104/scripts.pory"
	walk_down
# 831 "data/maps/Route104/scripts.pory"
	walk_down
# 832 "data/maps/Route104/scripts.pory"
	step_end
# 833 "data/maps/Route104/scripts.pory"

# 834 "data/maps/Route104/scripts.pory"
Route104_Movement_BrineyExitBoat:
# 835 "data/maps/Route104/scripts.pory"
	walk_down
# 836 "data/maps/Route104/scripts.pory"
	walk_in_place_faster_left
# 837 "data/maps/Route104/scripts.pory"
	step_end
# 838 "data/maps/Route104/scripts.pory"

# 839 "data/maps/Route104/scripts.pory"
Route104_EventScript_Ivan::
# 840 "data/maps/Route104/scripts.pory"
	trainerbattle_single TRAINER_IVAN, Route104_Text_IvanIntro, Route104_Text_IvanDefeat
# 841 "data/maps/Route104/scripts.pory"
	msgbox Route104_Text_IvanPostBattle, MSGBOX_AUTOCLOSE
# 842 "data/maps/Route104/scripts.pory"
	end
# 843 "data/maps/Route104/scripts.pory"

# 844 "data/maps/Route104/scripts.pory"
Route104_EventScript_Billy::
# 845 "data/maps/Route104/scripts.pory"
	trainerbattle_single TRAINER_BILLY, Route104_Text_BillyIntro, Route104_Text_BillyDefeat
# 846 "data/maps/Route104/scripts.pory"
	msgbox Route104_Text_BillyPostBattle, MSGBOX_AUTOCLOSE
# 847 "data/maps/Route104/scripts.pory"
	end
# 848 "data/maps/Route104/scripts.pory"

# 849 "data/maps/Route104/scripts.pory"
Route104_EventScript_Haley::
# 850 "data/maps/Route104/scripts.pory"
	trainerbattle_single TRAINER_HALEY_1, Route104_Text_HaleyIntro, Route104_Text_HaleyDefeat, Route104_EventScript_TryRegisterHaleyAfterBattle
# 851 "data/maps/Route104/scripts.pory"
	specialvar VAR_RESULT, ShouldTryRematchBattle
# 852 "data/maps/Route104/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, Route104_EventScript_RematchHaley
# 853 "data/maps/Route104/scripts.pory"
	setvar VAR_0x8004, TRAINER_HALEY_1
# 854 "data/maps/Route104/scripts.pory"
	specialvar VAR_RESULT, IsTrainerRegistered
# 855 "data/maps/Route104/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, Route104_EventScript_TryRegisterHaley
# 856 "data/maps/Route104/scripts.pory"
	msgbox Route104_Text_HaleyPostBattle, MSGBOX_DEFAULT
# 857 "data/maps/Route104/scripts.pory"
	release
# 858 "data/maps/Route104/scripts.pory"
	end
# 859 "data/maps/Route104/scripts.pory"

# 860 "data/maps/Route104/scripts.pory"
Route104_EventScript_TryRegisterHaleyAfterBattle::
# 861 "data/maps/Route104/scripts.pory"
	special PlayerFaceTrainerAfterBattle
# 862 "data/maps/Route104/scripts.pory"
	waitmovement 0
# 863 "data/maps/Route104/scripts.pory"
	goto_if_set FLAG_HAS_MATCH_CALL, Route104_EventScript_RegisterHaleyAfterBattle
# 864 "data/maps/Route104/scripts.pory"
	release
# 865 "data/maps/Route104/scripts.pory"
	end
# 866 "data/maps/Route104/scripts.pory"

# 867 "data/maps/Route104/scripts.pory"
Route104_EventScript_RegisterHaleyAfterBattle::
# 868 "data/maps/Route104/scripts.pory"
	msgbox Route104_Text_HaleyRegister2, MSGBOX_DEFAULT
# 869 "data/maps/Route104/scripts.pory"
	register_matchcall TRAINER_HALEY_1
# 870 "data/maps/Route104/scripts.pory"
	release
# 871 "data/maps/Route104/scripts.pory"
	end
# 872 "data/maps/Route104/scripts.pory"

# 873 "data/maps/Route104/scripts.pory"
Route104_EventScript_TryRegisterHaley::
# 874 "data/maps/Route104/scripts.pory"
	goto_if_set FLAG_HAS_MATCH_CALL, Route104_EventScript_RegisterHaley
# 875 "data/maps/Route104/scripts.pory"
	msgbox Route104_Text_HaleyPostBattle, MSGBOX_DEFAULT
# 876 "data/maps/Route104/scripts.pory"
	release
# 877 "data/maps/Route104/scripts.pory"
	end
# 878 "data/maps/Route104/scripts.pory"

# 879 "data/maps/Route104/scripts.pory"
Route104_EventScript_RegisterHaley::
# 880 "data/maps/Route104/scripts.pory"
	msgbox Route104_Text_HaleyRegister1, MSGBOX_DEFAULT
# 881 "data/maps/Route104/scripts.pory"
	register_matchcall TRAINER_HALEY_1
# 882 "data/maps/Route104/scripts.pory"
	release
# 883 "data/maps/Route104/scripts.pory"
	end
# 884 "data/maps/Route104/scripts.pory"

# 885 "data/maps/Route104/scripts.pory"
Route104_EventScript_RematchHaley::
# 886 "data/maps/Route104/scripts.pory"
	trainerbattle_rematch TRAINER_HALEY_1, Route104_Text_HaleyRematchIntro, Route104_Text_HaleyRematchDefeat
# 887 "data/maps/Route104/scripts.pory"
	msgbox Route104_Text_HaleyPostRematch, MSGBOX_AUTOCLOSE
# 888 "data/maps/Route104/scripts.pory"
	end
# 889 "data/maps/Route104/scripts.pory"

# 890 "data/maps/Route104/scripts.pory"
Route104_EventScript_Winston::
# 891 "data/maps/Route104/scripts.pory"
	trainerbattle_single TRAINER_WINSTON_1, Route104_Text_WinstonIntro, Route104_Text_WinstonDefeat, Route104_EventScript_TryRegisterWinstonAfterBattle
# 892 "data/maps/Route104/scripts.pory"
	specialvar VAR_RESULT, ShouldTryRematchBattle
# 893 "data/maps/Route104/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, Route104_EventScript_RematchWinston
# 894 "data/maps/Route104/scripts.pory"
	setvar VAR_0x8004, TRAINER_WINSTON_1
# 895 "data/maps/Route104/scripts.pory"
	specialvar VAR_RESULT, IsTrainerRegistered
# 896 "data/maps/Route104/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, Route104_EventScript_TryRegisterWinston
# 897 "data/maps/Route104/scripts.pory"
	msgbox Route104_Text_WinstonPostBattle, MSGBOX_DEFAULT
# 898 "data/maps/Route104/scripts.pory"
	release
# 899 "data/maps/Route104/scripts.pory"
	end
# 900 "data/maps/Route104/scripts.pory"

# 901 "data/maps/Route104/scripts.pory"
Route104_EventScript_TryRegisterWinstonAfterBattle::
# 902 "data/maps/Route104/scripts.pory"
	special PlayerFaceTrainerAfterBattle
# 903 "data/maps/Route104/scripts.pory"
	waitmovement 0
# 904 "data/maps/Route104/scripts.pory"
	goto_if_set FLAG_HAS_MATCH_CALL, Route104_EventScript_RegisterWinstonAfterBattle
# 905 "data/maps/Route104/scripts.pory"
	release
# 906 "data/maps/Route104/scripts.pory"
	end
# 907 "data/maps/Route104/scripts.pory"

# 908 "data/maps/Route104/scripts.pory"
Route104_EventScript_RegisterWinstonAfterBattle::
# 909 "data/maps/Route104/scripts.pory"
	msgbox Route104_Text_WinstonRegister2, MSGBOX_DEFAULT
# 910 "data/maps/Route104/scripts.pory"
	register_matchcall TRAINER_WINSTON_1
# 911 "data/maps/Route104/scripts.pory"
	release
# 912 "data/maps/Route104/scripts.pory"
	end
# 913 "data/maps/Route104/scripts.pory"

# 914 "data/maps/Route104/scripts.pory"
Route104_EventScript_TryRegisterWinston::
# 915 "data/maps/Route104/scripts.pory"
	goto_if_set FLAG_HAS_MATCH_CALL, Route104_EventScript_RegisterWinston
# 916 "data/maps/Route104/scripts.pory"
	msgbox Route104_Text_WinstonPostBattle, MSGBOX_DEFAULT
# 917 "data/maps/Route104/scripts.pory"
	release
# 918 "data/maps/Route104/scripts.pory"
	end
# 919 "data/maps/Route104/scripts.pory"

# 920 "data/maps/Route104/scripts.pory"
Route104_EventScript_RegisterWinston::
# 921 "data/maps/Route104/scripts.pory"
	msgbox Route104_Text_WinstonRegister1, MSGBOX_DEFAULT
# 922 "data/maps/Route104/scripts.pory"
	register_matchcall TRAINER_WINSTON_1
# 923 "data/maps/Route104/scripts.pory"
	release
# 924 "data/maps/Route104/scripts.pory"
	end
# 925 "data/maps/Route104/scripts.pory"

# 926 "data/maps/Route104/scripts.pory"
Route104_EventScript_RematchWinston::
# 927 "data/maps/Route104/scripts.pory"
	trainerbattle_rematch TRAINER_WINSTON_1, Route104_Text_WinstonRematchIntro, Route104_Text_WinstonRematchDefeat
# 928 "data/maps/Route104/scripts.pory"
	msgbox Route104_Text_WinstonPostRematch, MSGBOX_AUTOCLOSE
# 929 "data/maps/Route104/scripts.pory"
	end
# 930 "data/maps/Route104/scripts.pory"

# 931 "data/maps/Route104/scripts.pory"
Route104_EventScript_Cindy::
# 932 "data/maps/Route104/scripts.pory"
	trainerbattle_single TRAINER_CINDY_1, Route104_Text_CindyIntro, Route104_Text_CindyDefeat, Route104_Pt1_EventScript_RouteClear
# 933 "data/maps/Route104/scripts.pory"
	specialvar VAR_RESULT, ShouldTryRematchBattle
# 934 "data/maps/Route104/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, Route104_EventScript_RematchCindy
# 935 "data/maps/Route104/scripts.pory"
	setvar VAR_0x8004, TRAINER_CINDY_1
# 936 "data/maps/Route104/scripts.pory"
	specialvar VAR_RESULT, IsTrainerRegistered
# 937 "data/maps/Route104/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, Route104_EventScript_TryRegisterCindy
# 938 "data/maps/Route104/scripts.pory"
	msgbox Route104_Text_CindyPostBattle, MSGBOX_DEFAULT
# 939 "data/maps/Route104/scripts.pory"
	release
# 940 "data/maps/Route104/scripts.pory"
	end
# 941 "data/maps/Route104/scripts.pory"

# 942 "data/maps/Route104/scripts.pory"
Route104_EventScript_TryRegisterCindyAfterBattle::
# 943 "data/maps/Route104/scripts.pory"
	special PlayerFaceTrainerAfterBattle
# 944 "data/maps/Route104/scripts.pory"
	waitmovement 0
# 945 "data/maps/Route104/scripts.pory"
	goto_if_set FLAG_HAS_MATCH_CALL, Route104_EventScript_RegisterCindyAfterBattle
# 946 "data/maps/Route104/scripts.pory"
	release
# 947 "data/maps/Route104/scripts.pory"
	end
# 948 "data/maps/Route104/scripts.pory"

# 949 "data/maps/Route104/scripts.pory"
Route104_EventScript_RegisterCindyAfterBattle::
# 950 "data/maps/Route104/scripts.pory"
	msgbox Route104_Text_CindyRegister2, MSGBOX_DEFAULT
# 951 "data/maps/Route104/scripts.pory"
	register_matchcall TRAINER_CINDY_1
# 952 "data/maps/Route104/scripts.pory"
	release
# 953 "data/maps/Route104/scripts.pory"
	end
# 954 "data/maps/Route104/scripts.pory"

# 955 "data/maps/Route104/scripts.pory"
Route104_EventScript_TryRegisterCindy::
# 956 "data/maps/Route104/scripts.pory"
	goto_if_set FLAG_HAS_MATCH_CALL, Route104_EventScript_RegisterCindy
# 957 "data/maps/Route104/scripts.pory"
	msgbox Route104_Text_CindyPostBattle, MSGBOX_DEFAULT
# 958 "data/maps/Route104/scripts.pory"
	release
# 959 "data/maps/Route104/scripts.pory"
	end
# 960 "data/maps/Route104/scripts.pory"

# 961 "data/maps/Route104/scripts.pory"
Route104_EventScript_RegisterCindy::
# 962 "data/maps/Route104/scripts.pory"
	msgbox Route104_Text_CindyRegister1, MSGBOX_DEFAULT
# 963 "data/maps/Route104/scripts.pory"
	register_matchcall TRAINER_CINDY_1
# 964 "data/maps/Route104/scripts.pory"
	release
# 965 "data/maps/Route104/scripts.pory"
	end
# 966 "data/maps/Route104/scripts.pory"

# 967 "data/maps/Route104/scripts.pory"
Route104_EventScript_RematchCindy::
# 968 "data/maps/Route104/scripts.pory"
	trainerbattle_rematch TRAINER_CINDY_1, Route104_Text_CindyRematchIntro, Route104_Text_CindyRematchDefeat
# 969 "data/maps/Route104/scripts.pory"
	msgbox Route104_Text_CindyPostRematch, MSGBOX_AUTOCLOSE
# 970 "data/maps/Route104/scripts.pory"
	end
# 971 "data/maps/Route104/scripts.pory"

# 972 "data/maps/Route104/scripts.pory"
Route104_EventScript_Gina::
# 973 "data/maps/Route104/scripts.pory"
	trainerbattle_double TRAINER_GINA_AND_MIA_1, Route104_Text_GinaIntro, Route104_Text_GinaDefeat, Route104_Text_GinaNotEnoughMons
# 974 "data/maps/Route104/scripts.pory"
	special GetPlayerBigGuyGirlString
# 975 "data/maps/Route104/scripts.pory"
	msgbox Route104_Text_GinaPostBattle, MSGBOX_DEFAULT
# 976 "data/maps/Route104/scripts.pory"
	release
# 977 "data/maps/Route104/scripts.pory"
	end
# 978 "data/maps/Route104/scripts.pory"

# 979 "data/maps/Route104/scripts.pory"
Route104_EventScript_Mia::
# 980 "data/maps/Route104/scripts.pory"
	trainerbattle_double TRAINER_GINA_AND_MIA_1, Route104_Text_MiaIntro, Route104_Text_MiaDefeat, Route104_Text_MiaNotEnoughMons
# 981 "data/maps/Route104/scripts.pory"
	special GetPlayerBigGuyGirlString
# 982 "data/maps/Route104/scripts.pory"
	msgbox Route104_Text_MiaPostBattle, MSGBOX_DEFAULT
# 983 "data/maps/Route104/scripts.pory"
	release
# 984 "data/maps/Route104/scripts.pory"
	end
# 985 "data/maps/Route104/scripts.pory"

# 986 "data/maps/Route104/scripts.pory"
Route104_EventScript_Darian::
# 987 "data/maps/Route104/scripts.pory"
	trainerbattle_single TRAINER_DARIAN, Route104_Text_DarianIntro, Route104_Text_DarianDefeat
# 988 "data/maps/Route104/scripts.pory"
	msgbox Route104_Text_DarianPostBattle, MSGBOX_AUTOCLOSE
# 989 "data/maps/Route104/scripts.pory"
	end
# 990 "data/maps/Route104/scripts.pory"

# 991 "data/maps/Route104/scripts.pory"
Route104_Text_OnlyThrowBallAtWildPokemon:
# 992 "data/maps/Route104/scripts.pory"
	.string "You're a thief if you try to steal\n"
# 993 "data/maps/Route104/scripts.pory"
	.string "someone else's POKéMON.\p"
# 994 "data/maps/Route104/scripts.pory"
	.string "You should throw POKé BALLS only at\n"
# 995 "data/maps/Route104/scripts.pory"
	.string "wild POKéMON.$"
# 996 "data/maps/Route104/scripts.pory"

# 997 "data/maps/Route104/scripts.pory"
Route104_Text_ImNotATrainer:
# 998 "data/maps/Route104/scripts.pory"
	.string "Oh, no, I'm not a TRAINER.\p"
# 999 "data/maps/Route104/scripts.pory"
	.string "But that's right, if TRAINERS lock eyes,\n"
# 1000 "data/maps/Route104/scripts.pory"
	.string "it's a challenge to battle.\p"
# 1001 "data/maps/Route104/scripts.pory"
	.string "If you don't want to battle, stay out\n"
# 1002 "data/maps/Route104/scripts.pory"
	.string "of their sight.$"
# 1003 "data/maps/Route104/scripts.pory"

# 1004 "data/maps/Route104/scripts.pory"
Route104_Text_LikeFillingMouthWithSeedsTakeThis:
# 1005 "data/maps/Route104/scripts.pory"
	.string "I like filling my mouth with seeds,\n"
# 1006 "data/maps/Route104/scripts.pory"
	.string "then spitting them out fast!\p"
# 1007 "data/maps/Route104/scripts.pory"
	.string "You can have this, so you try it out!\p"
# 1008 "data/maps/Route104/scripts.pory"
	.string "Use it on a POKéMON, and it will learn\n"
# 1009 "data/maps/Route104/scripts.pory"
	.string "a move for firing seeds rapidly.$"
# 1010 "data/maps/Route104/scripts.pory"

# 1011 "data/maps/Route104/scripts.pory"
Route104_Text_TMsAreOneTimeUse:
# 1012 "data/maps/Route104/scripts.pory"
	.string "A word of advice!\p"
# 1013 "data/maps/Route104/scripts.pory"
	.string "A TM, TECHNICAL MACHINE, is good only\n"
# 1014 "data/maps/Route104/scripts.pory"
	.string "for one-time use.\p"
# 1015 "data/maps/Route104/scripts.pory"
	.string "Once you use it, it's gone.\n"
# 1016 "data/maps/Route104/scripts.pory"
	.string "Think twice before using it!$"
# 1017 "data/maps/Route104/scripts.pory"

# 1018 "data/maps/Route104/scripts.pory"
Route104_Text_DontNeedThisTakeIt:
# 1019 "data/maps/Route104/scripts.pory"
	.string "This FLOWER SHOP started selling\n"
# 1020 "data/maps/Route104/scripts.pory"
	.string "saplings recently.\p"
# 1021 "data/maps/Route104/scripts.pory"
	.string "It made me so happy, I went overboard\n"
# 1022 "data/maps/Route104/scripts.pory"
	.string "shopping.\p"
# 1023 "data/maps/Route104/scripts.pory"
	.string "I don't need this WHITE HERB anymore.\n"
# 1024 "data/maps/Route104/scripts.pory"
	.string "Would you take it, please?$"
# 1025 "data/maps/Route104/scripts.pory"

# 1026 "data/maps/Route104/scripts.pory"
Route104_Text_FlowerShopSellingSaplings:
# 1027 "data/maps/Route104/scripts.pory"
	.string "This FLOWER SHOP started selling\n"
# 1028 "data/maps/Route104/scripts.pory"
	.string "saplings recently.\p"
# 1029 "data/maps/Route104/scripts.pory"
	.string "It made me so happy, I went overboard\n"
# 1030 "data/maps/Route104/scripts.pory"
	.string "shopping. Where should I put them?$"
# 1031 "data/maps/Route104/scripts.pory"

# 1032 "data/maps/Route104/scripts.pory"
Route104_Text_MrBrineysCottage:
# 1033 "data/maps/Route104/scripts.pory"
	.string "MR. BRINEY'S COTTAGE$"
# 1034 "data/maps/Route104/scripts.pory"

# 1035 "data/maps/Route104/scripts.pory"
Route104_Text_RouteSignPetalburg:
# 1036 "data/maps/Route104/scripts.pory"
	.string "ROUTE 1O4\n"
# 1037 "data/maps/Route104/scripts.pory"
	.string "{RIGHT_ARROW} PETALBURG CITY$"
# 1038 "data/maps/Route104/scripts.pory"

# 1039 "data/maps/Route104/scripts.pory"
Route104_Text_RouteSignRustboro:
# 1040 "data/maps/Route104/scripts.pory"
	.string "ROUTE 1O4\n"
# 1041 "data/maps/Route104/scripts.pory"
	.string "{UP_ARROW} RUSTBORO CITY$"
# 1042 "data/maps/Route104/scripts.pory"

# 1043 "data/maps/Route104/scripts.pory"
Route104_Text_PrettyPetalFlowShop:
# 1044 "data/maps/Route104/scripts.pory"
	.string "PRETTY PETAL FLOWER SHOP$"
# 1045 "data/maps/Route104/scripts.pory"

# 1046 "data/maps/Route104/scripts.pory"
Route104_Text_TrainerTipsDoubleBattles:
# 1047 "data/maps/Route104/scripts.pory"
	.string "TRAINER TIPS\p"
# 1048 "data/maps/Route104/scripts.pory"
	.string "In the HOENN region there are pairs\n"
# 1049 "data/maps/Route104/scripts.pory"
	.string "of TRAINERS who challenge others\l"
# 1050 "data/maps/Route104/scripts.pory"
	.string "for 2-on-2 POKéMON battles called\l"
# 1051 "data/maps/Route104/scripts.pory"
	.string "DOUBLE BATTLES.\p"
# 1052 "data/maps/Route104/scripts.pory"
	.string "In a DOUBLE BATTLE, the TRAINER must\n"
# 1053 "data/maps/Route104/scripts.pory"
	.string "send out two POKéMON, the one at the\l"
# 1054 "data/maps/Route104/scripts.pory"
	.string "left of the list and the top one.\l"
# 1055 "data/maps/Route104/scripts.pory"
	.string "Watch how POKéMON are lined up.$"
# 1056 "data/maps/Route104/scripts.pory"

# 1057 "data/maps/Route104/scripts.pory"
Route104_Text_MayWeShouldRegister:
# 1058 "data/maps/Route104/scripts.pory"
	.string "MAY: Oh, hi, {PLAYER}{KUN}!\p"
# 1059 "data/maps/Route104/scripts.pory"
	.string "DEVON upgraded your POKéNAV with\n"
# 1060 "data/maps/Route104/scripts.pory"
	.string "the MATCH CALL system, huh?\p"
# 1061 "data/maps/Route104/scripts.pory"
	.string "We should register each other so we\n"
# 1062 "data/maps/Route104/scripts.pory"
	.string "can get in contact anytime.$"
# 1063 "data/maps/Route104/scripts.pory"

# 1064 "data/maps/Route104/scripts.pory"
Route104_Text_RegisteredMay:
# 1065 "data/maps/Route104/scripts.pory"
	.string "{PLAYER} registered MAY\n"
# 1066 "data/maps/Route104/scripts.pory"
	.string "in the POKéNAV.$"
# 1067 "data/maps/Route104/scripts.pory"

# 1068 "data/maps/Route104/scripts.pory"
Route104_Text_MayHowsYourPokedex:
# 1069 "data/maps/Route104/scripts.pory"
	.string "MAY: Oh, by the way, {PLAYER}{KUN},\n"
# 1070 "data/maps/Route104/scripts.pory"
	.string "how's your POKéDEX coming along?$"
# 1071 "data/maps/Route104/scripts.pory"

# 1072 "data/maps/Route104/scripts.pory"
Route104_Text_MayMinesDecentLetsBattle:
# 1073 "data/maps/Route104/scripts.pory"
	.string "Mine's looking pretty decent.\n"
# 1074 "data/maps/Route104/scripts.pory"
	.string "So…\l"
# 1075 "data/maps/Route104/scripts.pory"
	.string "How about a little battle?$"
# 1076 "data/maps/Route104/scripts.pory"

# 1077 "data/maps/Route104/scripts.pory"
Route104_Text_MayHaventRaisedPokemon:
# 1078 "data/maps/Route104/scripts.pory"
	.string "MAY: Oh, what's the matter?\p"
# 1079 "data/maps/Route104/scripts.pory"
	.string "Haven't you caught or raised your\n"
# 1080 "data/maps/Route104/scripts.pory"
	.string "POKéMON very much?\p"
# 1081 "data/maps/Route104/scripts.pory"
	.string "That's not very good for a TRAINER!$"
# 1082 "data/maps/Route104/scripts.pory"

# 1083 "data/maps/Route104/scripts.pory"
Route104_Text_MayLetsBattle:
# 1084 "data/maps/Route104/scripts.pory"
	.string "MAY: So, what do you think?\n"
# 1085 "data/maps/Route104/scripts.pory"
	.string "How about a little battle here?$"
# 1086 "data/maps/Route104/scripts.pory"

# 1087 "data/maps/Route104/scripts.pory"
Route104_Text_MayIntro:
# 1088 "data/maps/Route104/scripts.pory"
	.string "MAY: You just became a TRAINER,\n"
# 1089 "data/maps/Route104/scripts.pory"
	.string "{PLAYER}{KUN}. I'm not going to lose!$"
# 1090 "data/maps/Route104/scripts.pory"

# 1091 "data/maps/Route104/scripts.pory"
Route104_Text_MayDefeat:
# 1092 "data/maps/Route104/scripts.pory"
	.string "Yikes!\n"
# 1093 "data/maps/Route104/scripts.pory"
	.string "You're better than I expected!$"
# 1094 "data/maps/Route104/scripts.pory"

# 1095 "data/maps/Route104/scripts.pory"
Route104_Text_MayPostBattle:
# 1096 "data/maps/Route104/scripts.pory"
	.string "MAY: I can tell you've gotten pretty\n"
# 1097 "data/maps/Route104/scripts.pory"
	.string "good with the way you handle POKéMON.\p"
# 1098 "data/maps/Route104/scripts.pory"
	.string "But instead of only making them\n"
# 1099 "data/maps/Route104/scripts.pory"
	.string "battle, you should be like MR. BRINEY.\p"
# 1100 "data/maps/Route104/scripts.pory"
	.string "It's important to become friends with\n"
# 1101 "data/maps/Route104/scripts.pory"
	.string "POKéMON, too.$"
# 1102 "data/maps/Route104/scripts.pory"

# 1103 "data/maps/Route104/scripts.pory"
Route104_Text_BrendanWeShouldRegister:
# 1104 "data/maps/Route104/scripts.pory"
	.string "BRENDAN: Oh, hey, {PLAYER}!\p"
# 1105 "data/maps/Route104/scripts.pory"
	.string "Cool, you had DEVON install the MATCH\n"
# 1106 "data/maps/Route104/scripts.pory"
	.string "CALL system on your POKéNAV!\p"
# 1107 "data/maps/Route104/scripts.pory"
	.string "Let's register each other in our\n"
# 1108 "data/maps/Route104/scripts.pory"
	.string "POKéNAVS so we can keep in touch.$"
# 1109 "data/maps/Route104/scripts.pory"

# 1110 "data/maps/Route104/scripts.pory"
Route104_Text_RegisteredBrendan:
# 1111 "data/maps/Route104/scripts.pory"
	.string "{PLAYER} registered BRENDAN\n"
# 1112 "data/maps/Route104/scripts.pory"
	.string "in the POKéNAV.$"
# 1113 "data/maps/Route104/scripts.pory"

# 1114 "data/maps/Route104/scripts.pory"
Route104_Text_BrendanHowsYourPokedex:
# 1115 "data/maps/Route104/scripts.pory"
	.string "BRENDAN: {PLAYER}, how's your POKéDEX?\n"
# 1116 "data/maps/Route104/scripts.pory"
	.string "Have you filled in any pages yet?$"
# 1117 "data/maps/Route104/scripts.pory"

# 1118 "data/maps/Route104/scripts.pory"
Route104_Text_BrendanDoingGreatLetsBattle:
# 1119 "data/maps/Route104/scripts.pory"
	.string "Me, I'm doing great!\p"
# 1120 "data/maps/Route104/scripts.pory"
	.string "Want to check out how good I am with\n"
# 1121 "data/maps/Route104/scripts.pory"
	.string "a battle?$"
# 1122 "data/maps/Route104/scripts.pory"

# 1123 "data/maps/Route104/scripts.pory"
Route104_Text_BrendanNoConfidence:
# 1124 "data/maps/Route104/scripts.pory"
	.string "BRENDAN: What's the matter? Don't have\n"
# 1125 "data/maps/Route104/scripts.pory"
	.string "any confidence in your POKéMON?$"
# 1126 "data/maps/Route104/scripts.pory"

# 1127 "data/maps/Route104/scripts.pory"
Route104_Text_BrendanLetsBattle:
# 1128 "data/maps/Route104/scripts.pory"
	.string "BRENDAN: What's up?\n"
# 1129 "data/maps/Route104/scripts.pory"
	.string "Want to have a battle with me?$"
# 1130 "data/maps/Route104/scripts.pory"

# 1131 "data/maps/Route104/scripts.pory"
Route104_Text_BrendanIntro:
# 1132 "data/maps/Route104/scripts.pory"
	.string "BRENDAN: I know you just became\n"
# 1133 "data/maps/Route104/scripts.pory"
	.string "a TRAINER, but I won't go easy!$"
# 1134 "data/maps/Route104/scripts.pory"

# 1135 "data/maps/Route104/scripts.pory"
Route104_Text_BrendanDefeat:
# 1136 "data/maps/Route104/scripts.pory"
	.string "Hmm…\n"
# 1137 "data/maps/Route104/scripts.pory"
	.string "You're pretty good.$"
# 1138 "data/maps/Route104/scripts.pory"

# 1139 "data/maps/Route104/scripts.pory"
Route104_Text_BrendanPostBattle:
# 1140 "data/maps/Route104/scripts.pory"
	.string "BRENDAN: You've gotten pretty decent\n"
# 1141 "data/maps/Route104/scripts.pory"
	.string "at handling POKéMON.\p"
# 1142 "data/maps/Route104/scripts.pory"
	.string "But, you know, you shouldn't just be\n"
# 1143 "data/maps/Route104/scripts.pory"
	.string "making POKéMON battle.\p"
# 1144 "data/maps/Route104/scripts.pory"
	.string "Like MR. BRINEY, it's important to\n"
# 1145 "data/maps/Route104/scripts.pory"
	.string "become friends with your POKéMON.$"

Route104_Pt1_EventScript_RouteClear::
# 1151 "data/maps/Route104/scripts.pory"
	lockall
# 1152 "data/maps/Route104/scripts.pory"
	fadescreen FADE_TO_BLACK
# 1153 "data/maps/Route104/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 1154 "data/maps/Route104/scripts.pory"
	setflag FLAG_ROUTE104_PART1_CLEAR
# 1155 "data/maps/Route104/scripts.pory"
	removeobject 35
# 1156 "data/maps/Route104/scripts.pory"
	removeobject 36
# 1157 "data/maps/Route104/scripts.pory"
	removeobject 37
# 1158 "data/maps/Route104/scripts.pory"
	removeobject 38
# 1159 "data/maps/Route104/scripts.pory"
	msgbox Route104_Pt1_EventScript_RouteClear_Text_0, MSGBOX_DEFAULT
# 1160 "data/maps/Route104/scripts.pory"
	waitmessage
# 1161 "data/maps/Route104/scripts.pory"
	waitfanfare
# 1162 "data/maps/Route104/scripts.pory"
	fadescreen FADE_FROM_BLACK
# 1163 "data/maps/Route104/scripts.pory"
	releaseall
	end


Route104_Pt1_EventScript_Wingull_1_Msg::
# 1167 "data/maps/Route104/scripts.pory"
	applymovement 37, Route104_Pt1_EventScript_Wingull_1_Msg_Movement_0
# 1168 "data/maps/Route104/scripts.pory"
	lock
# 1169 "data/maps/Route104/scripts.pory"
	playmoncry SPECIES_WINGULL, CRY_MODE_ENCOUNTER
# 1170 "data/maps/Route104/scripts.pory"
	waitmoncry
# 1171 "data/maps/Route104/scripts.pory"
	msgbox Route104_Pt1_EventScript_Wingull_1_Msg_Text_0, MSGBOX_DEFAULT
# 1172 "data/maps/Route104/scripts.pory"
	turnobject 37, DIR_SOUTH
# 1173 "data/maps/Route104/scripts.pory"
	applymovement 37, Route104_Pt1_EventScript_Wingull_1_Msg_Movement_1
# 1174 "data/maps/Route104/scripts.pory"
	release
	end


Route104_Pt1_EventScript_Wingull_2_Msg::
# 1178 "data/maps/Route104/scripts.pory"
	applymovement 38, Route104_Pt1_EventScript_Wingull_1_Msg_Movement_0
# 1179 "data/maps/Route104/scripts.pory"
	lock
# 1180 "data/maps/Route104/scripts.pory"
	playmoncry SPECIES_WINGULL, CRY_MODE_ENCOUNTER
# 1181 "data/maps/Route104/scripts.pory"
	waitmoncry
# 1182 "data/maps/Route104/scripts.pory"
	msgbox Route104_Pt1_EventScript_Wingull_1_Msg_Text_0, MSGBOX_DEFAULT
# 1183 "data/maps/Route104/scripts.pory"
	turnobject 38, DIR_SOUTH
# 1184 "data/maps/Route104/scripts.pory"
	applymovement 38, Route104_Pt1_EventScript_Wingull_1_Msg_Movement_1
# 1185 "data/maps/Route104/scripts.pory"
	release
	end


Route104_Pt1_EventScript_Corvisquire_Msg::
# 1190 "data/maps/Route104/scripts.pory"
	applymovement 35, Route104_Pt1_EventScript_Wingull_1_Msg_Movement_0
# 1191 "data/maps/Route104/scripts.pory"
	lock
# 1192 "data/maps/Route104/scripts.pory"
	playmoncry SPECIES_CORVISQUIRE, CRY_MODE_ENCOUNTER
# 1193 "data/maps/Route104/scripts.pory"
	waitmoncry
# 1194 "data/maps/Route104/scripts.pory"
	msgbox Route104_Pt1_EventScript_Corvisquire_Msg_Text_0, MSGBOX_DEFAULT
# 1195 "data/maps/Route104/scripts.pory"
	turnobject 35, DIR_SOUTH
# 1196 "data/maps/Route104/scripts.pory"
	applymovement 35, Route104_Pt1_EventScript_Wingull_1_Msg_Movement_1
# 1197 "data/maps/Route104/scripts.pory"
	release
	end


Route104_Pt1_EventScript_Clobbopus_Msg::
# 1202 "data/maps/Route104/scripts.pory"
	applymovement 36, Route104_Pt1_EventScript_Wingull_1_Msg_Movement_0
# 1203 "data/maps/Route104/scripts.pory"
	lock
# 1204 "data/maps/Route104/scripts.pory"
	playmoncry SPECIES_CLOBBOPUS, CRY_MODE_ENCOUNTER
# 1205 "data/maps/Route104/scripts.pory"
	waitmoncry
# 1206 "data/maps/Route104/scripts.pory"
	msgbox Route104_Pt1_EventScript_Clobbopus_Msg_Text_0, MSGBOX_DEFAULT
# 1207 "data/maps/Route104/scripts.pory"
	turnobject 36, DIR_SOUTH
# 1208 "data/maps/Route104/scripts.pory"
	applymovement 36, Route104_Pt1_EventScript_Wingull_1_Msg_Movement_1
# 1209 "data/maps/Route104/scripts.pory"
	release
	end


Route104_EventScript_Boy1::
# 1216 "data/maps/Route104/scripts.pory"
	faceplayer
# 1217 "data/maps/Route104/scripts.pory"
	lock
# 1218 "data/maps/Route104/scripts.pory"
	goto_if_unset FLAG_ROUTE104_PART1_CLEAR, Route104_EventScript_Boy1_2
# 1226 "data/maps/Route104/scripts.pory"
	msgbox Route104_EventScript_Boy1_Text_1, MSGBOX_DEFAULT
# 1227 "data/maps/Route104/scripts.pory"
	release
	end

# 1230 "data/maps/Route104/scripts.pory"
	release
	end

Route104_EventScript_Boy1_2:
# 1220 "data/maps/Route104/scripts.pory"
	msgbox Route104_EventScript_Boy1_Text_0, MSGBOX_DEFAULT
# 1221 "data/maps/Route104/scripts.pory"
	release
	end


Route104_EventScript_BugCatcher::
# 1235 "data/maps/Route104/scripts.pory"
	faceplayer
# 1236 "data/maps/Route104/scripts.pory"
	lock
# 1237 "data/maps/Route104/scripts.pory"
	msgbox Route104_EventScript_BugCatcher_Text_0, MSGBOX_DEFAULT
# 1241 "data/maps/Route104/scripts.pory"
	release
	end


Route104_Pt1_EventScript_RouteRewards::
# 1245 "data/maps/Route104/scripts.pory"
	lock
# 1246 "data/maps/Route104/scripts.pory"
	faceplayer
# 1247 "data/maps/Route104/scripts.pory"
	goto_if_unset FLAG_ROUTE104_PT1_REWARD, Route104_Pt1_EventScript_RouteRewards_1
# 1268 "data/maps/Route104/scripts.pory"
	msgbox Route104_Pt1_EventScript_RouteRewards_Text_2, MSGBOX_DEFAULT
# 1269 "data/maps/Route104/scripts.pory"
	release
	end

Route104_Pt1_EventScript_RouteRewards_1:
# 1249 "data/maps/Route104/scripts.pory"
	msgbox Route104_Pt1_EventScript_RouteRewards_Text_0, MSGBOX_YESNO
# 1250 "data/maps/Route104/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq Route104_Pt1_EventScript_RouteRewards_4
# 1261 "data/maps/Route104/scripts.pory"
	msgbox Route104_Pt1_EventScript_RouteRewards_Text_1, MSGBOX_DEFAULT
# 1262 "data/maps/Route104/scripts.pory"
	release
	end

Route104_Pt1_EventScript_RouteRewards_4:
# 1252 "data/maps/Route104/scripts.pory"
	giveitem ITEM_CHARCOAL, 1
# 1253 "data/maps/Route104/scripts.pory"
	giveitem ITEM_MIRACLE_SEED, 1
# 1254 "data/maps/Route104/scripts.pory"
	giveitem ITEM_MYSTIC_WATER, 1
# 1255 "data/maps/Route104/scripts.pory"
	setflag FLAG_ROUTE104_PT1_REWARD
# 1256 "data/maps/Route104/scripts.pory"
	release
	end


# 1167 "data/maps/Route104/scripts.pory"
Route104_Pt1_EventScript_Wingull_1_Msg_Movement_0:
# 1167 "data/maps/Route104/scripts.pory"
	face_player
	step_end

# 1173 "data/maps/Route104/scripts.pory"
Route104_Pt1_EventScript_Wingull_1_Msg_Movement_1:
# 1173 "data/maps/Route104/scripts.pory"
	walk_in_place_down
	step_end

Route104_Pt1_EventScript_RouteClear_Text_0:
# 1159 "data/maps/Route104/scripts.pory"
	.string "This route has been cleared!\n"
	.string "The level cap is now 10.$"

Route104_Pt1_EventScript_Wingull_1_Msg_Text_0:
# 1171 "data/maps/Route104/scripts.pory"
	.string "The Wingull looks unsettled.$"

Route104_Pt1_EventScript_Corvisquire_Msg_Text_0:
# 1194 "data/maps/Route104/scripts.pory"
	.string "Corvisquire pecks at you - ow!$"

Route104_Pt1_EventScript_Clobbopus_Msg_Text_0:
# 1206 "data/maps/Route104/scripts.pory"
	.string "Clobbopus is swinging his arm around\n"
	.string "like Popeye!$"

Route104_EventScript_Boy1_Text_0:
# 1220 "data/maps/Route104/scripts.pory"
	.string "I saw these trainers had some strong\n"
	.string "teams. Be prepared!$"

Route104_EventScript_Boy1_Text_1:
# 1226 "data/maps/Route104/scripts.pory"
	.string "Thank you for clearing the route!!$"

Route104_EventScript_BugCatcher_Text_0:
# 1237 "data/maps/Route104/scripts.pory"
	.string "The sea, huh?\p"
	.string "I wonder what it's like at the bottom\n"
	.string "of the sea?\p"
	.string "Is it infinitely deep, filled with cosmic\n"
	.string "horrors shaded from our vision simply\l"
	.string "due to the absence of light, a space so\l"
	.string "overwhelming horrifying that our brains\l"
	.string "could not comprehend, or just a bunch\l"
	.string "of Binacle?\p"
	.string ".......\p"
	.string "Sorry, it's been a rough week.$"

Route104_Pt1_EventScript_RouteRewards_Text_0:
# 1249 "data/maps/Route104/scripts.pory"
	.string "Thanks for dealing with those nasty\n"
	.string "trainers! Would you like a reward?$"

Route104_Pt1_EventScript_RouteRewards_Text_1:
# 1261 "data/maps/Route104/scripts.pory"
	.string "OK! Come see me if you ever want them!$"

Route104_Pt1_EventScript_RouteRewards_Text_2:
# 1268 "data/maps/Route104/scripts.pory"
	.string "I think Mr. Briney is a nice man. His\n"
	.string "Wingull is so cute!!$"
