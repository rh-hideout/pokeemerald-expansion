# 1 "data/maps/Route103/scripts.pory"

# 2 "data/maps/Route103/scripts.pory"
Route103_MapScripts::
# 3 "data/maps/Route103/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, Route103_OnTransition
# 4 "data/maps/Route103/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, Route103_OnLoad
# 5 "data/maps/Route103/scripts.pory"
	.byte 0
# 6 "data/maps/Route103/scripts.pory"

# 7 "data/maps/Route103/scripts.pory"
Route103_OnTransition:
# 8 "data/maps/Route103/scripts.pory"
	call Common_EventScript_SetupRivalGfxId
# 9 "data/maps/Route103/scripts.pory"
	call ProfBirch_EventScript_UpdateLocation
# 10 "data/maps/Route103/scripts.pory"
	end
# 11 "data/maps/Route103/scripts.pory"

# 12 "data/maps/Route103/scripts.pory"
Route103_OnLoad:
# 13 "data/maps/Route103/scripts.pory"
	call_if_set FLAG_SYS_GAME_CLEAR, Route103_EventScript_OpenAlteringCave
# 14 "data/maps/Route103/scripts.pory"
	end
# 15 "data/maps/Route103/scripts.pory"

# 16 "data/maps/Route103/scripts.pory"
Route103_EventScript_OpenAlteringCave::
# 17 "data/maps/Route103/scripts.pory"
	setmetatile 45, 5, METATILE_General_CaveEntrance_Top, TRUE
# 18 "data/maps/Route103/scripts.pory"
	setmetatile 45, 6, METATILE_General_CaveEntrance_Bottom, FALSE
# 19 "data/maps/Route103/scripts.pory"
	return
# 20 "data/maps/Route103/scripts.pory"

# 21 "data/maps/Route103/scripts.pory"
Route103_EventScript_Rival::
# 22 "data/maps/Route103/scripts.pory"
	lockall
# 23 "data/maps/Route103/scripts.pory"
	checkplayergender
# 24 "data/maps/Route103/scripts.pory"
	goto_if_eq VAR_RESULT, MALE, Route103_EventScript_RivalMay
# 25 "data/maps/Route103/scripts.pory"
	goto_if_eq VAR_RESULT, FEMALE, Route103_EventScript_RivalBrendan
# 26 "data/maps/Route103/scripts.pory"
	end
# 27 "data/maps/Route103/scripts.pory"

# 28 "data/maps/Route103/scripts.pory"
Route103_EventScript_RivalMay::
# 29 "data/maps/Route103/scripts.pory"
	msgbox Route103_Text_MayRoute103Pokemon, MSGBOX_DEFAULT
# 30 "data/maps/Route103/scripts.pory"
	closemessage
# 31 "data/maps/Route103/scripts.pory"
	playbgm MUS_ENCOUNTER_MAY, TRUE
# 32 "data/maps/Route103/scripts.pory"
	applymovement LOCALID_ROUTE103_RIVAL, Common_Movement_FacePlayer
# 33 "data/maps/Route103/scripts.pory"
	waitmovement 0
# 34 "data/maps/Route103/scripts.pory"
	applymovement LOCALID_ROUTE103_RIVAL, Common_Movement_ExclamationMark
# 35 "data/maps/Route103/scripts.pory"
	waitmovement 0
# 36 "data/maps/Route103/scripts.pory"
	applymovement LOCALID_ROUTE103_RIVAL, Common_Movement_Delay48
# 37 "data/maps/Route103/scripts.pory"
	waitmovement 0
# 38 "data/maps/Route103/scripts.pory"
	msgbox Route103_Text_MayLetsBattle, MSGBOX_DEFAULT
# 39 "data/maps/Route103/scripts.pory"
	switch VAR_STARTER_MON
# 40 "data/maps/Route103/scripts.pory"
	case 0, Route103_EventScript_StartMayBattleTreecko
# 41 "data/maps/Route103/scripts.pory"
	case 1, Route103_EventScript_StartMayBattleTorchic
# 42 "data/maps/Route103/scripts.pory"
	case 2, Route103_EventScript_StartMayBattleMudkip
# 43 "data/maps/Route103/scripts.pory"
	end
# 44 "data/maps/Route103/scripts.pory"

# 45 "data/maps/Route103/scripts.pory"
Route103_EventScript_RivalBrendan::
# 46 "data/maps/Route103/scripts.pory"
	msgbox Route103_Text_BrendanRoute103Pokemon, MSGBOX_DEFAULT
# 47 "data/maps/Route103/scripts.pory"
	closemessage
# 48 "data/maps/Route103/scripts.pory"
	playbgm MUS_ENCOUNTER_BRENDAN, TRUE
# 49 "data/maps/Route103/scripts.pory"
	applymovement LOCALID_ROUTE103_RIVAL, Common_Movement_FacePlayer
# 50 "data/maps/Route103/scripts.pory"
	waitmovement 0
# 51 "data/maps/Route103/scripts.pory"
	applymovement LOCALID_ROUTE103_RIVAL, Common_Movement_ExclamationMark
# 52 "data/maps/Route103/scripts.pory"
	waitmovement 0
# 53 "data/maps/Route103/scripts.pory"
	applymovement LOCALID_ROUTE103_RIVAL, Common_Movement_Delay48
# 54 "data/maps/Route103/scripts.pory"
	waitmovement 0
# 55 "data/maps/Route103/scripts.pory"
	msgbox Route103_Text_BrendanLetsBattle, MSGBOX_DEFAULT
# 56 "data/maps/Route103/scripts.pory"
	switch VAR_STARTER_MON
# 57 "data/maps/Route103/scripts.pory"
	case 0, Route103_EventScript_StartBrendanBattleTreecko
# 58 "data/maps/Route103/scripts.pory"
	case 1, Route103_EventScript_StartBrendanBattleTorchic
# 59 "data/maps/Route103/scripts.pory"
	case 2, Route103_EventScript_StartBrendanBattleMudkip
# 60 "data/maps/Route103/scripts.pory"
	end
# 61 "data/maps/Route103/scripts.pory"

# 62 "data/maps/Route103/scripts.pory"
Route103_EventScript_StartMayBattleTreecko::
# 63 "data/maps/Route103/scripts.pory"
	trainerbattle_no_intro TRAINER_MAY_ROUTE_103_TREECKO, Route103_Text_MayDefeated
# 64 "data/maps/Route103/scripts.pory"
	goto Route103_EventScript_AfterMayBattle
# 65 "data/maps/Route103/scripts.pory"
	end
# 66 "data/maps/Route103/scripts.pory"

# 67 "data/maps/Route103/scripts.pory"
Route103_EventScript_StartMayBattleTorchic::
# 68 "data/maps/Route103/scripts.pory"
	trainerbattle_no_intro TRAINER_MAY_ROUTE_103_TORCHIC, Route103_Text_MayDefeated
# 69 "data/maps/Route103/scripts.pory"
	goto Route103_EventScript_AfterMayBattle
# 70 "data/maps/Route103/scripts.pory"
	end
# 71 "data/maps/Route103/scripts.pory"

# 72 "data/maps/Route103/scripts.pory"
Route103_EventScript_StartMayBattleMudkip::
# 73 "data/maps/Route103/scripts.pory"
	trainerbattle_no_intro TRAINER_MAY_ROUTE_103_MUDKIP, Route103_Text_MayDefeated
# 74 "data/maps/Route103/scripts.pory"
	goto Route103_EventScript_AfterMayBattle
# 75 "data/maps/Route103/scripts.pory"
	end
# 76 "data/maps/Route103/scripts.pory"

# 77 "data/maps/Route103/scripts.pory"
Route103_EventScript_StartBrendanBattleTreecko::
# 78 "data/maps/Route103/scripts.pory"
	trainerbattle_no_intro TRAINER_BRENDAN_ROUTE_103_TREECKO, Route103_Text_BrendanDefeated
# 79 "data/maps/Route103/scripts.pory"
	goto Route103_EventScript_AfterBrendanBattle
# 80 "data/maps/Route103/scripts.pory"
	end
# 81 "data/maps/Route103/scripts.pory"

# 82 "data/maps/Route103/scripts.pory"
Route103_EventScript_StartBrendanBattleTorchic::
# 83 "data/maps/Route103/scripts.pory"
	trainerbattle_no_intro TRAINER_BRENDAN_ROUTE_103_TORCHIC, Route103_Text_BrendanDefeated
# 84 "data/maps/Route103/scripts.pory"
	goto Route103_EventScript_AfterBrendanBattle
# 85 "data/maps/Route103/scripts.pory"
	end
# 86 "data/maps/Route103/scripts.pory"

# 87 "data/maps/Route103/scripts.pory"
Route103_EventScript_StartBrendanBattleMudkip::
# 88 "data/maps/Route103/scripts.pory"
	trainerbattle_no_intro TRAINER_BRENDAN_ROUTE_103_MUDKIP, Route103_Text_BrendanDefeated
# 89 "data/maps/Route103/scripts.pory"
	goto Route103_EventScript_AfterBrendanBattle
# 90 "data/maps/Route103/scripts.pory"
	end
# 91 "data/maps/Route103/scripts.pory"

# 92 "data/maps/Route103/scripts.pory"
Route103_EventScript_AfterMayBattle::
# 93 "data/maps/Route103/scripts.pory"
	msgbox Route103_Text_MayTimeToHeadBack, MSGBOX_DEFAULT
# 94 "data/maps/Route103/scripts.pory"
	goto Route103_EventScript_RivalExit
# 95 "data/maps/Route103/scripts.pory"
	end
# 96 "data/maps/Route103/scripts.pory"

# 97 "data/maps/Route103/scripts.pory"
Route103_EventScript_AfterBrendanBattle::
# 98 "data/maps/Route103/scripts.pory"
	msgbox Route103_Text_BrendanTimeToHeadBack, MSGBOX_DEFAULT
# 99 "data/maps/Route103/scripts.pory"
	goto Route103_EventScript_RivalExit
# 100 "data/maps/Route103/scripts.pory"
	end
# 101 "data/maps/Route103/scripts.pory"

# 102 "data/maps/Route103/scripts.pory"
Route103_EventScript_RivalExit::
# 103 "data/maps/Route103/scripts.pory"
	closemessage
# 104 "data/maps/Route103/scripts.pory"
	switch VAR_FACING
# 105 "data/maps/Route103/scripts.pory"
	case DIR_SOUTH, Route103_EventScript_RivalExitFacingSouth
# 106 "data/maps/Route103/scripts.pory"
	case DIR_NORTH, Route103_EventScript_RivalExitFacingNorth
# 107 "data/maps/Route103/scripts.pory"
	case DIR_WEST, Route103_EventScript_RivalExitFacingEastOrWest
# 108 "data/maps/Route103/scripts.pory"
	case DIR_EAST, Route103_EventScript_RivalExitFacingEastOrWest
# 109 "data/maps/Route103/scripts.pory"
	end
# 110 "data/maps/Route103/scripts.pory"

# 111 "data/maps/Route103/scripts.pory"
Route103_EventScript_RivalExitFacingNorth::
# 112 "data/maps/Route103/scripts.pory"
	applymovement LOCALID_PLAYER, Route103_Movement_WatchRivalExitFacingNorth
# 113 "data/maps/Route103/scripts.pory"
	applymovement LOCALID_ROUTE103_RIVAL, Route103_Movement_RivalExitFacingNorth1
# 114 "data/maps/Route103/scripts.pory"
	waitmovement 0
# 115 "data/maps/Route103/scripts.pory"
	playse SE_LEDGE
# 116 "data/maps/Route103/scripts.pory"
	applymovement LOCALID_ROUTE103_RIVAL, Route103_Movement_RivalExitFacingNorth2
# 117 "data/maps/Route103/scripts.pory"
	waitmovement 0
# 118 "data/maps/Route103/scripts.pory"
	goto Route103_EventScript_RivalEnd
# 119 "data/maps/Route103/scripts.pory"
	end
# 120 "data/maps/Route103/scripts.pory"

# 121 "data/maps/Route103/scripts.pory"
Route103_EventScript_RivalExitFacingEastOrWest::
# 122 "data/maps/Route103/scripts.pory"
	applymovement LOCALID_PLAYER, Route103_Movement_WatchRivalExitFacingEastOrWest
# 123 "data/maps/Route103/scripts.pory"
	applymovement LOCALID_ROUTE103_RIVAL, Route103_Movement_RivalExit1
# 124 "data/maps/Route103/scripts.pory"
	waitmovement 0
# 125 "data/maps/Route103/scripts.pory"
	playse SE_LEDGE
# 126 "data/maps/Route103/scripts.pory"
	applymovement LOCALID_ROUTE103_RIVAL, Route103_Movement_RivalExit2
# 127 "data/maps/Route103/scripts.pory"
	waitmovement 0
# 128 "data/maps/Route103/scripts.pory"
	goto Route103_EventScript_RivalEnd
# 129 "data/maps/Route103/scripts.pory"
	end
# 130 "data/maps/Route103/scripts.pory"

# 131 "data/maps/Route103/scripts.pory"
Route103_EventScript_RivalExitFacingSouth::
# 132 "data/maps/Route103/scripts.pory"
	applymovement LOCALID_ROUTE103_RIVAL, Route103_Movement_RivalExit1
# 133 "data/maps/Route103/scripts.pory"
	waitmovement 0
# 134 "data/maps/Route103/scripts.pory"
	playse SE_LEDGE
# 135 "data/maps/Route103/scripts.pory"
	applymovement LOCALID_ROUTE103_RIVAL, Route103_Movement_RivalExit2
# 136 "data/maps/Route103/scripts.pory"
	waitmovement 0
# 137 "data/maps/Route103/scripts.pory"
	goto Route103_EventScript_RivalEnd
# 138 "data/maps/Route103/scripts.pory"
	end
# 139 "data/maps/Route103/scripts.pory"

# 140 "data/maps/Route103/scripts.pory"
Route103_EventScript_RivalEnd::
# 141 "data/maps/Route103/scripts.pory"
	removeobject LOCALID_ROUTE103_RIVAL
# 142 "data/maps/Route103/scripts.pory"
	setvar VAR_BIRCH_LAB_STATE, 4
# 143 "data/maps/Route103/scripts.pory"
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_BIRCHS_LAB_RIVAL
# 144 "data/maps/Route103/scripts.pory"
	setflag FLAG_DEFEATED_RIVAL_ROUTE103
# 145 "data/maps/Route103/scripts.pory"
	setvar VAR_OLDALE_RIVAL_STATE, 1
# 146 "data/maps/Route103/scripts.pory"
	clearflag FLAG_HIDE_OLDALE_TOWN_RIVAL
# 147 "data/maps/Route103/scripts.pory"
	savebgm MUS_DUMMY
# 148 "data/maps/Route103/scripts.pory"
	fadedefaultbgm
# 149 "data/maps/Route103/scripts.pory"
	releaseall
# 150 "data/maps/Route103/scripts.pory"
	end
# 151 "data/maps/Route103/scripts.pory"

# 152 "data/maps/Route103/scripts.pory"
Route103_Movement_RivalExitFacingNorth1:
# 153 "data/maps/Route103/scripts.pory"
	walk_left
# 154 "data/maps/Route103/scripts.pory"
	walk_down
# 155 "data/maps/Route103/scripts.pory"
	step_end
# 156 "data/maps/Route103/scripts.pory"

# 157 "data/maps/Route103/scripts.pory"
Route103_Movement_RivalExitFacingNorth2:
# 158 "data/maps/Route103/scripts.pory"
	jump_2_down
# 159 "data/maps/Route103/scripts.pory"
	delay_16
# 160 "data/maps/Route103/scripts.pory"
	walk_down
# 161 "data/maps/Route103/scripts.pory"
	walk_down
# 162 "data/maps/Route103/scripts.pory"
	walk_down
# 163 "data/maps/Route103/scripts.pory"
	walk_down
# 164 "data/maps/Route103/scripts.pory"
	step_end
# 165 "data/maps/Route103/scripts.pory"

# 166 "data/maps/Route103/scripts.pory"
Route103_Movement_WatchRivalExitFacingNorth:
# 167 "data/maps/Route103/scripts.pory"
	delay_16
# 168 "data/maps/Route103/scripts.pory"
	delay_4
# 169 "data/maps/Route103/scripts.pory"
	walk_in_place_faster_left
# 170 "data/maps/Route103/scripts.pory"
	delay_16
# 171 "data/maps/Route103/scripts.pory"
	walk_in_place_faster_down
# 172 "data/maps/Route103/scripts.pory"
	step_end
# 173 "data/maps/Route103/scripts.pory"

# 174 "data/maps/Route103/scripts.pory"
Route103_Movement_RivalExit1:
# 175 "data/maps/Route103/scripts.pory"
	walk_down
# 176 "data/maps/Route103/scripts.pory"
	step_end
# 177 "data/maps/Route103/scripts.pory"

# 178 "data/maps/Route103/scripts.pory"
Route103_Movement_RivalExit2:
# 179 "data/maps/Route103/scripts.pory"
	jump_2_down
# 180 "data/maps/Route103/scripts.pory"
	delay_16
# 181 "data/maps/Route103/scripts.pory"
	walk_down
# 182 "data/maps/Route103/scripts.pory"
	walk_down
# 183 "data/maps/Route103/scripts.pory"
	walk_down
# 184 "data/maps/Route103/scripts.pory"
	step_end
# 185 "data/maps/Route103/scripts.pory"

# 186 "data/maps/Route103/scripts.pory"
Route103_Movement_WatchRivalExitFacingEastOrWest:
# 187 "data/maps/Route103/scripts.pory"
	delay_16
# 188 "data/maps/Route103/scripts.pory"
	walk_in_place_faster_down
# 189 "data/maps/Route103/scripts.pory"
	step_end
# 190 "data/maps/Route103/scripts.pory"

# 191 "data/maps/Route103/scripts.pory"
Route103_EventScript_Boy::
# 192 "data/maps/Route103/scripts.pory"
	msgbox Route103_Text_ShouldHaveBroughtPotion, MSGBOX_NPC
# 193 "data/maps/Route103/scripts.pory"
	end
# 194 "data/maps/Route103/scripts.pory"

# 195 "data/maps/Route103/scripts.pory"
Route103_EventScript_Man::
# 196 "data/maps/Route103/scripts.pory"
	msgbox Route103_Text_ShortcutToOldale, MSGBOX_NPC
# 197 "data/maps/Route103/scripts.pory"
	end
# 198 "data/maps/Route103/scripts.pory"

# 199 "data/maps/Route103/scripts.pory"
Route103_EventScript_RouteSign::
# 200 "data/maps/Route103/scripts.pory"
	msgbox Route103_Text_RouteSign, MSGBOX_SIGN
# 201 "data/maps/Route103/scripts.pory"
	end
# 202 "data/maps/Route103/scripts.pory"

# 203 "data/maps/Route103/scripts.pory"
Route103_EventScript_Daisy::
# 204 "data/maps/Route103/scripts.pory"
	trainerbattle_single TRAINER_DAISY, Route103_Text_DaisyIntro, Route103_Text_DaisyDefeated
# 205 "data/maps/Route103/scripts.pory"
	msgbox Route103_Text_DaisyPostBattle, MSGBOX_AUTOCLOSE
# 206 "data/maps/Route103/scripts.pory"
	end
# 207 "data/maps/Route103/scripts.pory"

# 208 "data/maps/Route103/scripts.pory"
Route103_EventScript_Amy::
# 209 "data/maps/Route103/scripts.pory"
	trainerbattle_double TRAINER_AMY_AND_LIV_1, Route103_Text_AmyIntro, Route103_Text_AmyDefeated, Route103_Text_AmyNotEnoughPokemon, Route102_EventScript_AmyRegisterMatchCallAfterBattle
# 210 "data/maps/Route103/scripts.pory"
	specialvar VAR_RESULT, ShouldTryRematchBattle
# 211 "data/maps/Route103/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, Route102_EventScript_AmyRematch
# 212 "data/maps/Route103/scripts.pory"
	msgbox Route103_Text_AmyPostBattle, MSGBOX_AUTOCLOSE
# 213 "data/maps/Route103/scripts.pory"
	end
# 214 "data/maps/Route103/scripts.pory"

# 215 "data/maps/Route103/scripts.pory"
Route102_EventScript_AmyRegisterMatchCallAfterBattle::
# 216 "data/maps/Route103/scripts.pory"
	msgbox Route103_Text_AmyLivRegister, MSGBOX_DEFAULT
# 217 "data/maps/Route103/scripts.pory"
	register_matchcall TRAINER_AMY_AND_LIV_1
# 218 "data/maps/Route103/scripts.pory"
	release
# 219 "data/maps/Route103/scripts.pory"
	end
# 220 "data/maps/Route103/scripts.pory"

# 221 "data/maps/Route103/scripts.pory"
Route102_EventScript_AmyRematch::
# 222 "data/maps/Route103/scripts.pory"
	trainerbattle_rematch_double TRAINER_AMY_AND_LIV_1, Route103_Text_AmyRematchIntro, Route103_Text_AmyRematchDefeated, Route103_Text_AmyRematchNotEnoughPokemon
# 223 "data/maps/Route103/scripts.pory"
	msgbox Route103_Text_AmyRematchPostBattle, MSGBOX_AUTOCLOSE
# 224 "data/maps/Route103/scripts.pory"
	end
# 225 "data/maps/Route103/scripts.pory"

# 226 "data/maps/Route103/scripts.pory"
Route103_EventScript_Liv::
# 227 "data/maps/Route103/scripts.pory"
	trainerbattle_double TRAINER_AMY_AND_LIV_1, Route103_Text_LivIntro, Route103_Text_LivDefeated, Route103_Text_LivNotEnoughPokemon, Route102_EventScript_LivRegisterMatchCallAfterBattle
# 228 "data/maps/Route103/scripts.pory"
	specialvar VAR_RESULT, ShouldTryRematchBattle
# 229 "data/maps/Route103/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, Route102_EventScript_LivRematch
# 230 "data/maps/Route103/scripts.pory"
	msgbox Route103_Text_LivPostBattle, MSGBOX_AUTOCLOSE
# 231 "data/maps/Route103/scripts.pory"
	end
# 232 "data/maps/Route103/scripts.pory"

# 233 "data/maps/Route103/scripts.pory"
Route102_EventScript_LivRegisterMatchCallAfterBattle::
# 234 "data/maps/Route103/scripts.pory"
	msgbox Route103_Text_AmyLivRegister, MSGBOX_DEFAULT
# 235 "data/maps/Route103/scripts.pory"
	register_matchcall TRAINER_AMY_AND_LIV_1
# 236 "data/maps/Route103/scripts.pory"
	release
# 237 "data/maps/Route103/scripts.pory"
	end
# 238 "data/maps/Route103/scripts.pory"

# 239 "data/maps/Route103/scripts.pory"
Route102_EventScript_LivRematch::
# 240 "data/maps/Route103/scripts.pory"
	trainerbattle_rematch_double TRAINER_AMY_AND_LIV_1, Route103_Text_LivRematchIntro, Route103_Text_LivRematchDefeated, Route103_Text_LivRematchNotEnoughPokemon
# 241 "data/maps/Route103/scripts.pory"
	msgbox Route103_Text_LivRematchPostBattle, MSGBOX_AUTOCLOSE
# 242 "data/maps/Route103/scripts.pory"
	end
# 243 "data/maps/Route103/scripts.pory"

# 244 "data/maps/Route103/scripts.pory"
Route103_EventScript_Andrew::
# 245 "data/maps/Route103/scripts.pory"
	trainerbattle_single TRAINER_ANDREW, Route103_Text_AndrewIntro, Route103_Text_AndrewDefeated
# 246 "data/maps/Route103/scripts.pory"
	msgbox Route103_Text_AndrewPostBattle, MSGBOX_AUTOCLOSE
# 247 "data/maps/Route103/scripts.pory"
	end
# 248 "data/maps/Route103/scripts.pory"

# 249 "data/maps/Route103/scripts.pory"
Route103_EventScript_Miguel::
# 250 "data/maps/Route103/scripts.pory"
	trainerbattle_single TRAINER_MIGUEL_1, Route103_Text_MiguelIntro, Route103_Text_MiguelDefeated, Route102_EventScript_MiguelRegisterMatchCallAfterBattle
# 251 "data/maps/Route103/scripts.pory"
	specialvar VAR_RESULT, ShouldTryRematchBattle
# 252 "data/maps/Route103/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, Route103_EventScript_MiguelRematch
# 253 "data/maps/Route103/scripts.pory"
	msgbox Route103_Text_MiguelPostBattle, MSGBOX_DEFAULT
# 254 "data/maps/Route103/scripts.pory"
	release
# 255 "data/maps/Route103/scripts.pory"
	end
# 256 "data/maps/Route103/scripts.pory"

# 257 "data/maps/Route103/scripts.pory"
Route102_EventScript_MiguelRegisterMatchCallAfterBattle::
# 258 "data/maps/Route103/scripts.pory"
	special PlayerFaceTrainerAfterBattle
# 259 "data/maps/Route103/scripts.pory"
	waitmovement 0
# 260 "data/maps/Route103/scripts.pory"
	msgbox Route103_Text_MiguelRegister, MSGBOX_DEFAULT
# 261 "data/maps/Route103/scripts.pory"
	register_matchcall TRAINER_MIGUEL_1
# 262 "data/maps/Route103/scripts.pory"
	release
# 263 "data/maps/Route103/scripts.pory"
	end
# 264 "data/maps/Route103/scripts.pory"

# 265 "data/maps/Route103/scripts.pory"
Route103_EventScript_MiguelRematch::
# 266 "data/maps/Route103/scripts.pory"
	trainerbattle_rematch TRAINER_MIGUEL_1, Route103_Text_MiguelRematchIntro, Route103_Text_MiguelRematchDefeated
# 267 "data/maps/Route103/scripts.pory"
	msgbox Route103_Text_MiguelRematchPostBattle, MSGBOX_AUTOCLOSE
# 268 "data/maps/Route103/scripts.pory"
	end
# 269 "data/maps/Route103/scripts.pory"

# 270 "data/maps/Route103/scripts.pory"
Route103_EventScript_Marcos::
# 271 "data/maps/Route103/scripts.pory"
	trainerbattle_single TRAINER_MARCOS, Route103_Text_MarcosIntro, Route103_Text_MarcosDefeated
# 272 "data/maps/Route103/scripts.pory"
	msgbox Route103_Text_MarcosPostBattle, MSGBOX_AUTOCLOSE
# 273 "data/maps/Route103/scripts.pory"
	end
# 274 "data/maps/Route103/scripts.pory"

# 275 "data/maps/Route103/scripts.pory"
Route103_EventScript_Rhett::
# 276 "data/maps/Route103/scripts.pory"
	trainerbattle_single TRAINER_RHETT, Route103_Text_RhettIntro, Route103_Text_RhettDefeated
# 277 "data/maps/Route103/scripts.pory"
	msgbox Route103_Text_RhettPostBattle, MSGBOX_AUTOCLOSE
# 278 "data/maps/Route103/scripts.pory"
	end
# 279 "data/maps/Route103/scripts.pory"

# 280 "data/maps/Route103/scripts.pory"
Route103_EventScript_Pete::
# 281 "data/maps/Route103/scripts.pory"
	trainerbattle_single TRAINER_PETE, Route103_Text_PeteIntro, Route103_Text_PeteDefeated
# 282 "data/maps/Route103/scripts.pory"
	msgbox Route103_Text_PetePostBattle, MSGBOX_AUTOCLOSE
# 283 "data/maps/Route103/scripts.pory"
	end
# 284 "data/maps/Route103/scripts.pory"

# 285 "data/maps/Route103/scripts.pory"
Route103_EventScript_Isabelle::
# 286 "data/maps/Route103/scripts.pory"
	trainerbattle_single TRAINER_ISABELLE, Route103_Text_IsabelleIntro, Route103_Text_IsabelleDefeated
# 287 "data/maps/Route103/scripts.pory"
	msgbox Route103_Text_IsabellePostBattle, MSGBOX_AUTOCLOSE
# 288 "data/maps/Route103/scripts.pory"
	end
# 289 "data/maps/Route103/scripts.pory"

# 290 "data/maps/Route103/scripts.pory"
Route103_Text_MayRoute103Pokemon:
# 291 "data/maps/Route103/scripts.pory"
	.string "MAY: Let's see… The POKéMON found\n"
# 292 "data/maps/Route103/scripts.pory"
	.string "on ROUTE 103 include…$"
# 293 "data/maps/Route103/scripts.pory"

# 294 "data/maps/Route103/scripts.pory"
Route103_Text_MayLetsBattle:
# 295 "data/maps/Route103/scripts.pory"
	.string "Oh, hi, {PLAYER}{KUN}!\p"
# 296 "data/maps/Route103/scripts.pory"
	.string "…Oh, I see, my dad gave you\n"
# 297 "data/maps/Route103/scripts.pory"
	.string "a POKéMON as a gift.\p"
# 298 "data/maps/Route103/scripts.pory"
	.string "Since we're here, let's have a quick\n"
# 299 "data/maps/Route103/scripts.pory"
	.string "battle!\p"
# 300 "data/maps/Route103/scripts.pory"
	.string "I'll give you a taste of what being\n"
# 301 "data/maps/Route103/scripts.pory"
	.string "a TRAINER is like.$"
# 302 "data/maps/Route103/scripts.pory"

# 303 "data/maps/Route103/scripts.pory"
Route103_Text_MayDefeated:
# 304 "data/maps/Route103/scripts.pory"
	.string "Wow! That's great!\n"
# 305 "data/maps/Route103/scripts.pory"
	.string "{PLAYER}{KUN}, you're pretty good!$"
# 306 "data/maps/Route103/scripts.pory"

# 307 "data/maps/Route103/scripts.pory"
Route103_Text_MayTimeToHeadBack:
# 308 "data/maps/Route103/scripts.pory"
	.string "MAY: I think I know why my dad has\n"
# 309 "data/maps/Route103/scripts.pory"
	.string "an eye out for you now.\p"
# 310 "data/maps/Route103/scripts.pory"
	.string "I mean, you just got that POKéMON,\n"
# 311 "data/maps/Route103/scripts.pory"
	.string "but it already likes you.\p"
# 312 "data/maps/Route103/scripts.pory"
	.string "You might be able to befriend any\n"
# 313 "data/maps/Route103/scripts.pory"
	.string "kind of POKéMON easily.\p"
# 314 "data/maps/Route103/scripts.pory"
	.string "Well, it's time to head back to\n"
# 315 "data/maps/Route103/scripts.pory"
	.string "the LAB.$"
# 316 "data/maps/Route103/scripts.pory"

# 317 "data/maps/Route103/scripts.pory"
Route103_Text_BrendanRoute103Pokemon:
# 318 "data/maps/Route103/scripts.pory"
	.string "BRENDAN: Okay, so it's this one and\n"
# 319 "data/maps/Route103/scripts.pory"
	.string "that one that live on ROUTE 103…$"
# 320 "data/maps/Route103/scripts.pory"

# 321 "data/maps/Route103/scripts.pory"
Route103_Text_BrendanLetsBattle:
# 322 "data/maps/Route103/scripts.pory"
	.string "Hey, it's {PLAYER}!\p"
# 323 "data/maps/Route103/scripts.pory"
	.string "…Oh, yeah, Dad gave you a POKéMON.\p"
# 324 "data/maps/Route103/scripts.pory"
	.string "Since we're here, how about a little\n"
# 325 "data/maps/Route103/scripts.pory"
	.string "battle?\p"
# 326 "data/maps/Route103/scripts.pory"
	.string "I'll teach you what being a TRAINER's\n"
# 327 "data/maps/Route103/scripts.pory"
	.string "about!$"
# 328 "data/maps/Route103/scripts.pory"

# 329 "data/maps/Route103/scripts.pory"
Route103_Text_BrendanDefeated:
# 330 "data/maps/Route103/scripts.pory"
	.string "Huh, {PLAYER}, you're not too shabby.$"
# 331 "data/maps/Route103/scripts.pory"

# 332 "data/maps/Route103/scripts.pory"
Route103_Text_BrendanTimeToHeadBack:
# 333 "data/maps/Route103/scripts.pory"
	.string "BRENDAN: I think I get it.\n"
# 334 "data/maps/Route103/scripts.pory"
	.string "I think I know why my dad has his eye\l"
# 335 "data/maps/Route103/scripts.pory"
	.string "out for you now.\p"
# 336 "data/maps/Route103/scripts.pory"
	.string "Look, your POKéMON already likes you,\n"
# 337 "data/maps/Route103/scripts.pory"
	.string "even though you just got it.\p"
# 338 "data/maps/Route103/scripts.pory"
	.string "{PLAYER}, I get the feeling that you\n"
# 339 "data/maps/Route103/scripts.pory"
	.string "could befriend any POKéMON with ease.\p"
# 340 "data/maps/Route103/scripts.pory"
	.string "We should head back to the LAB.$"
# 341 "data/maps/Route103/scripts.pory"

# 342 "data/maps/Route103/scripts.pory"
Route103_Text_ShouldHaveBroughtPotion:
# 343 "data/maps/Route103/scripts.pory"
	.string "My POKéMON is staggeringly tired…\n"
# 344 "data/maps/Route103/scripts.pory"
	.string "I should have brought a POTION…$"
# 345 "data/maps/Route103/scripts.pory"

# 346 "data/maps/Route103/scripts.pory"
Route103_Text_ShortcutToOldale:
# 347 "data/maps/Route103/scripts.pory"
	.string "If you cross the sea from here,\n"
# 348 "data/maps/Route103/scripts.pory"
	.string "it'll be a shortcut to OLDALE TOWN.\p"
# 349 "data/maps/Route103/scripts.pory"
	.string "Fufufu, that's useful, isn't it?$"
# 350 "data/maps/Route103/scripts.pory"

# 351 "data/maps/Route103/scripts.pory"
Route103_Text_RouteSign:
# 352 "data/maps/Route103/scripts.pory"
	.string "ROUTE 103\n"
# 353 "data/maps/Route103/scripts.pory"
	.string "{DOWN_ARROW} OLDALE TOWN$"
