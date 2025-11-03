# 1 "data/maps/RustboroCity/scripts.pory"

# 2 "data/maps/RustboroCity/scripts.pory"
RustboroCity_MapScripts::
# 3 "data/maps/RustboroCity/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, RustboroCity_OnTransition
# 4 "data/maps/RustboroCity/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, RustboroCity_OnFrame
# 5 "data/maps/RustboroCity/scripts.pory"
	.byte 0
# 6 "data/maps/RustboroCity/scripts.pory"

# 7 "data/maps/RustboroCity/scripts.pory"
RustboroCity_OnTransition:
# 8 "data/maps/RustboroCity/scripts.pory"
	setflag FLAG_VISITED_RUSTBORO_CITY
# 9 "data/maps/RustboroCity/scripts.pory"
	call Common_EventScript_SetupRivalGfxId
# 10 "data/maps/RustboroCity/scripts.pory"
	call_if_eq VAR_RUSTBORO_CITY_STATE, 6, RustboroCity_EventScript_HideMapNamePopup
# 11 "data/maps/RustboroCity/scripts.pory"
	getplayerxy VAR_TEMP_0, VAR_TEMP_1
# 12 "data/maps/RustboroCity/scripts.pory"
	goto_if_eq VAR_RUSTBORO_CITY_STATE, 6, RustboroCity_EventScript_PositionScientistForExit
# 13 "data/maps/RustboroCity/scripts.pory"
	end
# 14 "data/maps/RustboroCity/scripts.pory"

# 15 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_PositionScientistForExit::
# 16 "data/maps/RustboroCity/scripts.pory"
	goto_if_eq VAR_TEMP_0, 11, RustboroCity_EventScript_PositionScientistLeftExit
# 17 "data/maps/RustboroCity/scripts.pory"
	setobjectxyperm LOCALID_RUSTBORO_SCIENTIST, 12, 15
# 18 "data/maps/RustboroCity/scripts.pory"
	end
# 19 "data/maps/RustboroCity/scripts.pory"

# 20 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_PositionScientistLeftExit::
# 21 "data/maps/RustboroCity/scripts.pory"
	setobjectxyperm LOCALID_RUSTBORO_SCIENTIST, 11, 15
# 22 "data/maps/RustboroCity/scripts.pory"
	end
# 23 "data/maps/RustboroCity/scripts.pory"

# 24 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_HideMapNamePopup::
# 25 "data/maps/RustboroCity/scripts.pory"
	setflag FLAG_HIDE_MAP_NAME_POPUP
# 26 "data/maps/RustboroCity/scripts.pory"
	return
# 27 "data/maps/RustboroCity/scripts.pory"

# 28 "data/maps/RustboroCity/scripts.pory"
RustboroCity_OnFrame:
# 29 "data/maps/RustboroCity/scripts.pory"
	map_script_2 VAR_RUSTBORO_CITY_STATE, 6, RustboroCity_EventScript_ScientistAddMatchCall
# 30 "data/maps/RustboroCity/scripts.pory"
	.2byte 0
# 31 "data/maps/RustboroCity/scripts.pory"

# 32 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_ScientistAddMatchCall::
# 33 "data/maps/RustboroCity/scripts.pory"
	lockall
# 34 "data/maps/RustboroCity/scripts.pory"
	setvar VAR_ROUTE104_STATE, 1
# 35 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_PLAYER, RustboroCity_Movement_PlayerWalkDown
# 36 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 37 "data/maps/RustboroCity/scripts.pory"
	playse SE_EXIT
# 38 "data/maps/RustboroCity/scripts.pory"
	delay 10
# 39 "data/maps/RustboroCity/scripts.pory"
	addobject LOCALID_RUSTBORO_SCIENTIST
# 40 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_SCIENTIST, RustboroCity_Movement_ScientistApproachPlayer
# 41 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 42 "data/maps/RustboroCity/scripts.pory"
	playse SE_PIN
# 43 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_SCIENTIST, Common_Movement_ExclamationMark
# 44 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 45 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_SCIENTIST, Common_Movement_Delay48
# 46 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 47 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
# 48 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 49 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_SCIENTIST, RustboroCity_Movement_ScientistWalkInPlaceDown
# 50 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 51 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_DevelopedNewPokenavFeature, MSGBOX_DEFAULT
# 52 "data/maps/RustboroCity/scripts.pory"
	closemessage
# 53 "data/maps/RustboroCity/scripts.pory"
	setflag FLAG_HAS_MATCH_CALL
# 54 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_SCIENTIST, Common_Movement_WalkInPlaceFasterLeft
# 55 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 56 "data/maps/RustboroCity/scripts.pory"
	playse SE_CLICK
# 57 "data/maps/RustboroCity/scripts.pory"
	delay 10
# 58 "data/maps/RustboroCity/scripts.pory"
	playse SE_CLICK
# 59 "data/maps/RustboroCity/scripts.pory"
	delay 10
# 60 "data/maps/RustboroCity/scripts.pory"
	playse SE_CLICK
# 61 "data/maps/RustboroCity/scripts.pory"
	delay 10
# 62 "data/maps/RustboroCity/scripts.pory"
	playse SE_CLICK
# 63 "data/maps/RustboroCity/scripts.pory"
	delay 20
# 64 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_SCIENTIST, Common_Movement_WalkInPlaceFasterDown
# 65 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 66 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_AddedMatchCallPleaseCallMrStone, MSGBOX_DEFAULT
# 67 "data/maps/RustboroCity/scripts.pory"
	closemessage
# 68 "data/maps/RustboroCity/scripts.pory"
	delay 20
# 69 "data/maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_MatchCallTutorial
# 70 "data/maps/RustboroCity/scripts.pory"

# 71 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_PleaseSelectPokenav::
# 72 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_PleaseSelectPokenav, MSGBOX_DEFAULT
# 73 "data/maps/RustboroCity/scripts.pory"
	closemessage
# 74 "data/maps/RustboroCity/scripts.pory"
	delay 10
# 75 "data/maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_MatchCallTutorial
# 76 "data/maps/RustboroCity/scripts.pory"

# 77 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_MatchCallTutorial::
# 78 "data/maps/RustboroCity/scripts.pory"
	setflag FLAG_ADDED_MATCH_CALL_TO_POKENAV
# 79 "data/maps/RustboroCity/scripts.pory"
	special ScriptMenu_CreateStartMenuForPokenavTutorial
# 80 "data/maps/RustboroCity/scripts.pory"
	waitstate
# 81 "data/maps/RustboroCity/scripts.pory"
	switch VAR_RESULT
# 82 "data/maps/RustboroCity/scripts.pory"
	case 0, RustboroCity_EventScript_PleaseSelectPokenav
# 83 "data/maps/RustboroCity/scripts.pory"
	case 1, RustboroCity_EventScript_PleaseSelectPokenav
# 84 "data/maps/RustboroCity/scripts.pory"
	case 2, RustboroCity_EventScript_PleaseSelectPokenav
# 85 "data/maps/RustboroCity/scripts.pory"
	case 4, RustboroCity_EventScript_PleaseSelectPokenav
# 86 "data/maps/RustboroCity/scripts.pory"
	case 5, RustboroCity_EventScript_PleaseSelectPokenav
# 87 "data/maps/RustboroCity/scripts.pory"
	case 6, RustboroCity_EventScript_PleaseSelectPokenav
# 88 "data/maps/RustboroCity/scripts.pory"
	case 7, RustboroCity_EventScript_PleaseSelectPokenav
# 89 "data/maps/RustboroCity/scripts.pory"
	case MULTI_B_PRESSED, RustboroCity_EventScript_PleaseSelectPokenav
# 90 "data/maps/RustboroCity/scripts.pory"
	special OpenPokenavForTutorial
# 91 "data/maps/RustboroCity/scripts.pory"
	waitstate
# 92 "data/maps/RustboroCity/scripts.pory"
	delay 20
# 93 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_IdBetterGetBackToWork, MSGBOX_DEFAULT
# 94 "data/maps/RustboroCity/scripts.pory"
	closemessage
# 95 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_SCIENTIST, RustboroCity_Movement_ScientistLeave
# 96 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 97 "data/maps/RustboroCity/scripts.pory"
	playse SE_EXIT
# 98 "data/maps/RustboroCity/scripts.pory"
	removeobject LOCALID_RUSTBORO_SCIENTIST
# 99 "data/maps/RustboroCity/scripts.pory"
	setflag FLAG_HIDE_RUSTBORO_CITY_SCIENTIST
# 100 "data/maps/RustboroCity/scripts.pory"
	setvar VAR_RUSTBORO_CITY_STATE, 7
# 101 "data/maps/RustboroCity/scripts.pory"
	clearflag FLAG_HIDE_MAP_NAME_POPUP
# 102 "data/maps/RustboroCity/scripts.pory"
	releaseall
# 103 "data/maps/RustboroCity/scripts.pory"
	end
# 104 "data/maps/RustboroCity/scripts.pory"

# 105 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Movement_ScientistWalkInPlaceDown:
# 106 "data/maps/RustboroCity/scripts.pory"
	walk_in_place_down
# 107 "data/maps/RustboroCity/scripts.pory"
	step_end
# 108 "data/maps/RustboroCity/scripts.pory"

# 109 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Movement_PlayerWalkDown:
# 110 "data/maps/RustboroCity/scripts.pory"
	walk_down
# 111 "data/maps/RustboroCity/scripts.pory"
	step_end
# 112 "data/maps/RustboroCity/scripts.pory"

# 113 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Movement_ScientistApproachPlayer:
# 114 "data/maps/RustboroCity/scripts.pory"
	walk_down
# 115 "data/maps/RustboroCity/scripts.pory"
	delay_16
# 116 "data/maps/RustboroCity/scripts.pory"
	step_end
# 117 "data/maps/RustboroCity/scripts.pory"

# 118 "data/maps/RustboroCity/scripts.pory"
@ Unused
# 119 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Movement_ScientistWalkAroundPlayer:
# 120 "data/maps/RustboroCity/scripts.pory"
	delay_16
# 121 "data/maps/RustboroCity/scripts.pory"
	walk_left
# 122 "data/maps/RustboroCity/scripts.pory"
	walk_down
# 123 "data/maps/RustboroCity/scripts.pory"
	walk_down
# 124 "data/maps/RustboroCity/scripts.pory"
	walk_right
# 125 "data/maps/RustboroCity/scripts.pory"
	walk_in_place_faster_up
# 126 "data/maps/RustboroCity/scripts.pory"
	delay_16
# 127 "data/maps/RustboroCity/scripts.pory"
	step_end
# 128 "data/maps/RustboroCity/scripts.pory"

# 129 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Movement_ScientistLeave:
# 130 "data/maps/RustboroCity/scripts.pory"
	walk_up
# 131 "data/maps/RustboroCity/scripts.pory"
	step_end
# 132 "data/maps/RustboroCity/scripts.pory"

# 133 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_FatMan::
# 134 "data/maps/RustboroCity/scripts.pory"
	lock
# 135 "data/maps/RustboroCity/scripts.pory"
	faceplayer
# 136 "data/maps/RustboroCity/scripts.pory"
	goto_if_set FLAG_DEVON_GOODS_STOLEN, RustboroCity_EventScript_FatManSawGrunt
# 137 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_WeShortenItToDevon, MSGBOX_DEFAULT
# 138 "data/maps/RustboroCity/scripts.pory"
	release
# 139 "data/maps/RustboroCity/scripts.pory"
	end
# 140 "data/maps/RustboroCity/scripts.pory"

# 141 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_FatManSawGrunt::
# 142 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_SneakyLookingManWentAroundCorner, MSGBOX_DEFAULT
# 143 "data/maps/RustboroCity/scripts.pory"
	release
# 144 "data/maps/RustboroCity/scripts.pory"
	end
# 145 "data/maps/RustboroCity/scripts.pory"

# 146 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_DevonEmployee2::
# 147 "data/maps/RustboroCity/scripts.pory"
	lock
# 148 "data/maps/RustboroCity/scripts.pory"
	faceplayer
# 149 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_YoureNewAroundHere, MSGBOX_DEFAULT
# 150 "data/maps/RustboroCity/scripts.pory"
	release
# 151 "data/maps/RustboroCity/scripts.pory"
	end
# 152 "data/maps/RustboroCity/scripts.pory"

# 153 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_Woman::
# 154 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_GymLeaderIsntEasyWithFire, MSGBOX_NPC
# 155 "data/maps/RustboroCity/scripts.pory"
	end
# 156 "data/maps/RustboroCity/scripts.pory"

# 157 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_Man1::
# 158 "data/maps/RustboroCity/scripts.pory"
	lock
# 159 "data/maps/RustboroCity/scripts.pory"
	faceplayer
# 160 "data/maps/RustboroCity/scripts.pory"
	goto_if_set FLAG_BADGE01_GET, RustboroCity_EventScript_Man1HaveBadge
# 161 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_HaveYouChallengedGym, MSGBOX_DEFAULT
# 162 "data/maps/RustboroCity/scripts.pory"
	release
# 163 "data/maps/RustboroCity/scripts.pory"
	end
# 164 "data/maps/RustboroCity/scripts.pory"

# 165 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_Man1HaveBadge::
# 166 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_HeyThatsRustborosGymBadge, MSGBOX_DEFAULT
# 167 "data/maps/RustboroCity/scripts.pory"
	release
# 168 "data/maps/RustboroCity/scripts.pory"
	end
# 169 "data/maps/RustboroCity/scripts.pory"

# 170 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_Boy2::
# 171 "data/maps/RustboroCity/scripts.pory"
	lock
# 172 "data/maps/RustboroCity/scripts.pory"
	faceplayer
# 173 "data/maps/RustboroCity/scripts.pory"
	goto_if_set FLAG_RECEIVED_POKENAV, RustboroCity_EventScript_Boy2BrineyLeftTunnel
# 174 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_MrBrineyWalksInTheTunnel, MSGBOX_DEFAULT
# 175 "data/maps/RustboroCity/scripts.pory"
	release
# 176 "data/maps/RustboroCity/scripts.pory"
	end
# 177 "data/maps/RustboroCity/scripts.pory"

# 178 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_Boy2BrineyLeftTunnel::
# 179 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_MrBrineyLovesPeeko, MSGBOX_DEFAULT
# 180 "data/maps/RustboroCity/scripts.pory"
	release
# 181 "data/maps/RustboroCity/scripts.pory"
	end
# 182 "data/maps/RustboroCity/scripts.pory"

# 183 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_Twin::
# 184 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_WowYouHavePokemon, MSGBOX_NPC
# 185 "data/maps/RustboroCity/scripts.pory"
	end
# 186 "data/maps/RustboroCity/scripts.pory"

# 187 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_NinjaBoy::
# 188 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_CatchRarePokemonIfIGoToSchool, MSGBOX_SIGN
# 189 "data/maps/RustboroCity/scripts.pory"
	end
# 190 "data/maps/RustboroCity/scripts.pory"

# 191 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_TunnelSign::
# 192 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_TunnelNearingCompletion, MSGBOX_SIGN
# 193 "data/maps/RustboroCity/scripts.pory"
	end
# 194 "data/maps/RustboroCity/scripts.pory"

# 195 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_DevonCorpSign::
# 196 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_DevonCorpSign, MSGBOX_SIGN
# 197 "data/maps/RustboroCity/scripts.pory"
	end
# 198 "data/maps/RustboroCity/scripts.pory"

# 199 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_GymSign::
# 200 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_GymSign, MSGBOX_SIGN
# 201 "data/maps/RustboroCity/scripts.pory"
	end
# 202 "data/maps/RustboroCity/scripts.pory"

# 203 "data/maps/RustboroCity/scripts.pory"
@ Unused
# 204 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_DevonCorpBranchOfficeSign::
# 205 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_DevonCorpBranchOfficeSign, MSGBOX_SIGN
# 206 "data/maps/RustboroCity/scripts.pory"
	end
# 207 "data/maps/RustboroCity/scripts.pory"

# 208 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_CitySign::
# 209 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_CitySign, MSGBOX_SIGN
# 210 "data/maps/RustboroCity/scripts.pory"
	end
# 211 "data/maps/RustboroCity/scripts.pory"

# 212 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_TrainersSchoolSign::
# 213 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_TrainersSchoolSign, MSGBOX_SIGN
# 214 "data/maps/RustboroCity/scripts.pory"
	end
# 215 "data/maps/RustboroCity/scripts.pory"

# 216 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_CuttersHouseSign::
# 217 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_CuttersHouse, MSGBOX_SIGN
# 218 "data/maps/RustboroCity/scripts.pory"
	end
# 219 "data/maps/RustboroCity/scripts.pory"

# 220 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_LittleBoy::
# 221 "data/maps/RustboroCity/scripts.pory"
	lock
# 222 "data/maps/RustboroCity/scripts.pory"
	faceplayer
# 223 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_PokemonCanChangeLookFromExp, MSGBOX_DEFAULT
# 224 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_LITTLE_BOY, Common_Movement_FaceOriginalDirection
# 225 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 226 "data/maps/RustboroCity/scripts.pory"
	release
# 227 "data/maps/RustboroCity/scripts.pory"
	end
# 228 "data/maps/RustboroCity/scripts.pory"

# 229 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_LittleGirl::
# 230 "data/maps/RustboroCity/scripts.pory"
	lock
# 231 "data/maps/RustboroCity/scripts.pory"
	faceplayer
# 232 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_PokemonChangeShape, MSGBOX_DEFAULT
# 233 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_LITTLE_GIRL, Common_Movement_FaceOriginalDirection
# 234 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 235 "data/maps/RustboroCity/scripts.pory"
	release
# 236 "data/maps/RustboroCity/scripts.pory"
	end
# 237 "data/maps/RustboroCity/scripts.pory"

# 238 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_Man2::
# 239 "data/maps/RustboroCity/scripts.pory"
	lock
# 240 "data/maps/RustboroCity/scripts.pory"
	faceplayer
# 241 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_TradePokemonGrowFast, MSGBOX_DEFAULT
# 242 "data/maps/RustboroCity/scripts.pory"
	release
# 243 "data/maps/RustboroCity/scripts.pory"
	end
# 244 "data/maps/RustboroCity/scripts.pory"

# 245 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_StolenGoodsTrigger0::
# 246 "data/maps/RustboroCity/scripts.pory"
	lockall
# 247 "data/maps/RustboroCity/scripts.pory"
	setobjectxyperm LOCALID_RUSTBORO_DEVON_EMPLOYEE, 14, 21
# 248 "data/maps/RustboroCity/scripts.pory"
	setobjectmovementtype LOCALID_RUSTBORO_DEVON_EMPLOYEE, MOVEMENT_TYPE_FACE_RIGHT
# 249 "data/maps/RustboroCity/scripts.pory"
	setvar VAR_0x8004, 0
# 250 "data/maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_StolenGoodsScene
# 251 "data/maps/RustboroCity/scripts.pory"
	end
# 252 "data/maps/RustboroCity/scripts.pory"

# 253 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_StolenGoodsTrigger1::
# 254 "data/maps/RustboroCity/scripts.pory"
	lockall
# 255 "data/maps/RustboroCity/scripts.pory"
	setobjectxyperm LOCALID_RUSTBORO_DEVON_EMPLOYEE, 14, 21
# 256 "data/maps/RustboroCity/scripts.pory"
	setobjectmovementtype LOCALID_RUSTBORO_DEVON_EMPLOYEE, MOVEMENT_TYPE_FACE_RIGHT
# 257 "data/maps/RustboroCity/scripts.pory"
	setvar VAR_0x8004, 1
# 258 "data/maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_StolenGoodsScene
# 259 "data/maps/RustboroCity/scripts.pory"
	end
# 260 "data/maps/RustboroCity/scripts.pory"

# 261 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_StolenGoodsTrigger2::
# 262 "data/maps/RustboroCity/scripts.pory"
	lockall
# 263 "data/maps/RustboroCity/scripts.pory"
	setobjectxyperm LOCALID_RUSTBORO_DEVON_EMPLOYEE, 14, 21
# 264 "data/maps/RustboroCity/scripts.pory"
	setobjectmovementtype LOCALID_RUSTBORO_DEVON_EMPLOYEE, MOVEMENT_TYPE_FACE_RIGHT
# 265 "data/maps/RustboroCity/scripts.pory"
	setvar VAR_0x8004, 2
# 266 "data/maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_StolenGoodsScene
# 267 "data/maps/RustboroCity/scripts.pory"
	end
# 268 "data/maps/RustboroCity/scripts.pory"

# 269 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_StolenGoodsTrigger3::
# 270 "data/maps/RustboroCity/scripts.pory"
	lockall
# 271 "data/maps/RustboroCity/scripts.pory"
	setobjectxyperm LOCALID_RUSTBORO_DEVON_EMPLOYEE, 14, 21
# 272 "data/maps/RustboroCity/scripts.pory"
	setobjectmovementtype LOCALID_RUSTBORO_DEVON_EMPLOYEE, MOVEMENT_TYPE_FACE_RIGHT
# 273 "data/maps/RustboroCity/scripts.pory"
	setvar VAR_0x8004, 3
# 274 "data/maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_StolenGoodsScene
# 275 "data/maps/RustboroCity/scripts.pory"
	end
# 276 "data/maps/RustboroCity/scripts.pory"

# 277 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_StolenGoodsTrigger4::
# 278 "data/maps/RustboroCity/scripts.pory"
	lockall
# 279 "data/maps/RustboroCity/scripts.pory"
	setobjectxyperm LOCALID_RUSTBORO_DEVON_EMPLOYEE, 14, 21
# 280 "data/maps/RustboroCity/scripts.pory"
	setobjectmovementtype LOCALID_RUSTBORO_DEVON_EMPLOYEE, MOVEMENT_TYPE_FACE_RIGHT
# 281 "data/maps/RustboroCity/scripts.pory"
	setvar VAR_0x8004, 4
# 282 "data/maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_StolenGoodsScene
# 283 "data/maps/RustboroCity/scripts.pory"
	end
# 284 "data/maps/RustboroCity/scripts.pory"

# 285 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_StolenGoodsScene::
# 286 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_OutOfTheWay, MSGBOX_DEFAULT
# 287 "data/maps/RustboroCity/scripts.pory"
	closemessage
# 288 "data/maps/RustboroCity/scripts.pory"
	playbgm MUS_ENCOUNTER_AQUA, FALSE
# 289 "data/maps/RustboroCity/scripts.pory"
	addobject LOCALID_RUSTBORO_GRUNT
# 290 "data/maps/RustboroCity/scripts.pory"
	addobject LOCALID_RUSTBORO_DEVON_EMPLOYEE
# 291 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_GRUNT, RustboroCity_Movement_GruntEscape
# 292 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 293 "data/maps/RustboroCity/scripts.pory"
	removeobject LOCALID_RUSTBORO_GRUNT
# 294 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_DEVON_EMPLOYEE, RustboroCity_Movement_EmployeeChaseGrunt1
# 295 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 296 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_WaitDontTakeMyGoods, MSGBOX_DEFAULT
# 297 "data/maps/RustboroCity/scripts.pory"
	closemessage
# 298 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_DEVON_EMPLOYEE, RustboroCity_Movement_EmployeeChaseGrunt2
# 299 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 300 "data/maps/RustboroCity/scripts.pory"
	fadedefaultbgm
# 301 "data/maps/RustboroCity/scripts.pory"
	removeobject LOCALID_RUSTBORO_DEVON_EMPLOYEE
# 302 "data/maps/RustboroCity/scripts.pory"
	setobjectxyperm LOCALID_RUSTBORO_DEVON_EMPLOYEE, 30, 10
# 303 "data/maps/RustboroCity/scripts.pory"
	clearflag FLAG_HIDE_RUSTBORO_CITY_DEVON_EMPLOYEE_1
# 304 "data/maps/RustboroCity/scripts.pory"
	setflag FLAG_DEVON_GOODS_STOLEN
# 305 "data/maps/RustboroCity/scripts.pory"
	setvar VAR_RUSTBORO_CITY_STATE, 2
# 306 "data/maps/RustboroCity/scripts.pory"
	setvar VAR_RUSTURF_TUNNEL_STATE, 2
# 307 "data/maps/RustboroCity/scripts.pory"
	setvar VAR_ROUTE116_STATE, 1
# 308 "data/maps/RustboroCity/scripts.pory"
	clearflag FLAG_HIDE_ROUTE_116_MR_BRINEY
# 309 "data/maps/RustboroCity/scripts.pory"
	clearflag FLAG_HIDE_RUSTURF_TUNNEL_PEEKO
# 310 "data/maps/RustboroCity/scripts.pory"
	clearflag FLAG_HIDE_RUSTURF_TUNNEL_AQUA_GRUNT
# 311 "data/maps/RustboroCity/scripts.pory"
	setflag FLAG_HIDE_BRINEYS_HOUSE_MR_BRINEY
# 312 "data/maps/RustboroCity/scripts.pory"
	setflag FLAG_HIDE_BRINEYS_HOUSE_PEEKO
# 313 "data/maps/RustboroCity/scripts.pory"
	releaseall
# 314 "data/maps/RustboroCity/scripts.pory"
	end
# 315 "data/maps/RustboroCity/scripts.pory"

# 316 "data/maps/RustboroCity/scripts.pory"
@ Unused
# 317 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_ShadyCharacterTookOff::
# 318 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_ShadyCharacterTookOffTowardsTunnel, MSGBOX_DEFAULT
# 319 "data/maps/RustboroCity/scripts.pory"
	return
# 320 "data/maps/RustboroCity/scripts.pory"

# 321 "data/maps/RustboroCity/scripts.pory"
@ Unused
# 322 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_YouGotItThankYou::
# 323 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_YouGotItThankYou, MSGBOX_DEFAULT
# 324 "data/maps/RustboroCity/scripts.pory"
	return
# 325 "data/maps/RustboroCity/scripts.pory"

# 326 "data/maps/RustboroCity/scripts.pory"
@ Unknown, unused employee movements. Based on the differences in movement theyre for approaching an object (probably the player) in different positions
# 327 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_EmployeeApproachUp::
# 328 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_DEVON_EMPLOYEE, RustboroCity_Movement_EmployeeApproachUp
# 329 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 330 "data/maps/RustboroCity/scripts.pory"
	return
# 331 "data/maps/RustboroCity/scripts.pory"

# 332 "data/maps/RustboroCity/scripts.pory"
@ Unused, see above
# 333 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_EmployeeApproachLeft::
# 334 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_DEVON_EMPLOYEE, RustboroCity_Movement_EmployeeApproachLeft
# 335 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 336 "data/maps/RustboroCity/scripts.pory"
	return
# 337 "data/maps/RustboroCity/scripts.pory"

# 338 "data/maps/RustboroCity/scripts.pory"
@ Unused, see above
# 339 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_EmployeeApproachRight::
# 340 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_DEVON_EMPLOYEE, RustboroCity_Movement_EmployeeApproachRight
# 341 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 342 "data/maps/RustboroCity/scripts.pory"
	return
# 343 "data/maps/RustboroCity/scripts.pory"

# 344 "data/maps/RustboroCity/scripts.pory"
@ Unused, see above
# 345 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_EmployeeApproachDown::
# 346 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_DEVON_EMPLOYEE, RustboroCity_Movement_EmployeeApproachDown
# 347 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 348 "data/maps/RustboroCity/scripts.pory"
	return
# 349 "data/maps/RustboroCity/scripts.pory"

# 350 "data/maps/RustboroCity/scripts.pory"
@ Unused, similar movement to the above scripts
# 351 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_EmployeeApproachPlayerFar::
# 352 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_DEVON_EMPLOYEE, RustboroCity_Movement_EmployeeApproachPlayerFar
# 353 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 354 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
# 355 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 356 "data/maps/RustboroCity/scripts.pory"
	return
# 357 "data/maps/RustboroCity/scripts.pory"

# 358 "data/maps/RustboroCity/scripts.pory"
@ Unused
# 359 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Movement_GruntEscapeExtended:
# 360 "data/maps/RustboroCity/scripts.pory"
	walk_faster_right
# 361 "data/maps/RustboroCity/scripts.pory"
	walk_faster_right
# 362 "data/maps/RustboroCity/scripts.pory"
	walk_fast_right
# 363 "data/maps/RustboroCity/scripts.pory"
	walk_fast_right
# 364 "data/maps/RustboroCity/scripts.pory"
	walk_fast_right
# 365 "data/maps/RustboroCity/scripts.pory"
	walk_fast_right
# 366 "data/maps/RustboroCity/scripts.pory"
	walk_fast_up
# 367 "data/maps/RustboroCity/scripts.pory"
	walk_fast_up
# 368 "data/maps/RustboroCity/scripts.pory"
	walk_fast_up
# 369 "data/maps/RustboroCity/scripts.pory"
	walk_fast_up
# 370 "data/maps/RustboroCity/scripts.pory"
	walk_fast_up
# 371 "data/maps/RustboroCity/scripts.pory"
	walk_fast_up
# 372 "data/maps/RustboroCity/scripts.pory"
	walk_fast_up
# 373 "data/maps/RustboroCity/scripts.pory"
	walk_fast_up
# 374 "data/maps/RustboroCity/scripts.pory"
	walk_fast_up
# 375 "data/maps/RustboroCity/scripts.pory"
	walk_fast_up
# 376 "data/maps/RustboroCity/scripts.pory"
	walk_fast_up
# 377 "data/maps/RustboroCity/scripts.pory"
	step_end
# 378 "data/maps/RustboroCity/scripts.pory"

# 379 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Movement_GruntEscape:
# 380 "data/maps/RustboroCity/scripts.pory"
	walk_faster_right
# 381 "data/maps/RustboroCity/scripts.pory"
	walk_faster_right
# 382 "data/maps/RustboroCity/scripts.pory"
	walk_fast_right
# 383 "data/maps/RustboroCity/scripts.pory"
	walk_fast_right
# 384 "data/maps/RustboroCity/scripts.pory"
	walk_fast_right
# 385 "data/maps/RustboroCity/scripts.pory"
	walk_fast_right
# 386 "data/maps/RustboroCity/scripts.pory"
	walk_fast_right
# 387 "data/maps/RustboroCity/scripts.pory"
	walk_fast_up
# 388 "data/maps/RustboroCity/scripts.pory"
	walk_fast_up
# 389 "data/maps/RustboroCity/scripts.pory"
	walk_fast_up
# 390 "data/maps/RustboroCity/scripts.pory"
	walk_fast_up
# 391 "data/maps/RustboroCity/scripts.pory"
	walk_fast_up
# 392 "data/maps/RustboroCity/scripts.pory"
	walk_fast_up
# 393 "data/maps/RustboroCity/scripts.pory"
	walk_fast_up
# 394 "data/maps/RustboroCity/scripts.pory"
	walk_fast_up
# 395 "data/maps/RustboroCity/scripts.pory"
	walk_fast_up
# 396 "data/maps/RustboroCity/scripts.pory"
	step_end
# 397 "data/maps/RustboroCity/scripts.pory"

# 398 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Movement_EmployeeChaseGrunt1:
# 399 "data/maps/RustboroCity/scripts.pory"
	walk_right
# 400 "data/maps/RustboroCity/scripts.pory"
	walk_right
# 401 "data/maps/RustboroCity/scripts.pory"
	walk_right
# 402 "data/maps/RustboroCity/scripts.pory"
	walk_right
# 403 "data/maps/RustboroCity/scripts.pory"
	walk_right
# 404 "data/maps/RustboroCity/scripts.pory"
	walk_right
# 405 "data/maps/RustboroCity/scripts.pory"
	walk_in_place_faster_up
# 406 "data/maps/RustboroCity/scripts.pory"
	step_end
# 407 "data/maps/RustboroCity/scripts.pory"

# 408 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Movement_EmployeeChaseGrunt2:
# 409 "data/maps/RustboroCity/scripts.pory"
	walk_up
# 410 "data/maps/RustboroCity/scripts.pory"
	walk_up
# 411 "data/maps/RustboroCity/scripts.pory"
	walk_up
# 412 "data/maps/RustboroCity/scripts.pory"
	walk_up
# 413 "data/maps/RustboroCity/scripts.pory"
	walk_up
# 414 "data/maps/RustboroCity/scripts.pory"
	walk_up
# 415 "data/maps/RustboroCity/scripts.pory"
	walk_up
# 416 "data/maps/RustboroCity/scripts.pory"
	step_end
# 417 "data/maps/RustboroCity/scripts.pory"

# 418 "data/maps/RustboroCity/scripts.pory"
@ Functionally unused
# 419 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Movement_EmployeeApproachUp:
# 420 "data/maps/RustboroCity/scripts.pory"
	walk_down
# 421 "data/maps/RustboroCity/scripts.pory"
	walk_right
# 422 "data/maps/RustboroCity/scripts.pory"
	walk_right
# 423 "data/maps/RustboroCity/scripts.pory"
	step_end
# 424 "data/maps/RustboroCity/scripts.pory"

# 425 "data/maps/RustboroCity/scripts.pory"
@ Functionally unused
# 426 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Movement_EmployeeApproachLeft:
# 427 "data/maps/RustboroCity/scripts.pory"
	walk_down
# 428 "data/maps/RustboroCity/scripts.pory"
	walk_down
# 429 "data/maps/RustboroCity/scripts.pory"
	walk_right
# 430 "data/maps/RustboroCity/scripts.pory"
	walk_right
# 431 "data/maps/RustboroCity/scripts.pory"
	step_end
# 432 "data/maps/RustboroCity/scripts.pory"

# 433 "data/maps/RustboroCity/scripts.pory"
@ Functionally unused
# 434 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Movement_EmployeeApproachRight:
# 435 "data/maps/RustboroCity/scripts.pory"
	walk_down
# 436 "data/maps/RustboroCity/scripts.pory"
	walk_down
# 437 "data/maps/RustboroCity/scripts.pory"
	walk_right
# 438 "data/maps/RustboroCity/scripts.pory"
	walk_right
# 439 "data/maps/RustboroCity/scripts.pory"
	step_end
# 440 "data/maps/RustboroCity/scripts.pory"

# 441 "data/maps/RustboroCity/scripts.pory"
@ Functionally unused
# 442 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Movement_EmployeeApproachDown:
# 443 "data/maps/RustboroCity/scripts.pory"
	walk_down
# 444 "data/maps/RustboroCity/scripts.pory"
	walk_down
# 445 "data/maps/RustboroCity/scripts.pory"
	walk_down
# 446 "data/maps/RustboroCity/scripts.pory"
	walk_right
# 447 "data/maps/RustboroCity/scripts.pory"
	walk_right
# 448 "data/maps/RustboroCity/scripts.pory"
	step_end
# 449 "data/maps/RustboroCity/scripts.pory"

# 450 "data/maps/RustboroCity/scripts.pory"
@ Functionally unused
# 451 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Movement_EmployeeApproachPlayerFar:
# 452 "data/maps/RustboroCity/scripts.pory"
	walk_down
# 453 "data/maps/RustboroCity/scripts.pory"
	walk_down
# 454 "data/maps/RustboroCity/scripts.pory"
	walk_down
# 455 "data/maps/RustboroCity/scripts.pory"
	walk_right
# 456 "data/maps/RustboroCity/scripts.pory"
	walk_right
# 457 "data/maps/RustboroCity/scripts.pory"
	walk_right
# 458 "data/maps/RustboroCity/scripts.pory"
	walk_in_place_faster_down
# 459 "data/maps/RustboroCity/scripts.pory"
	step_end
# 460 "data/maps/RustboroCity/scripts.pory"

# 461 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_DevonEmployee1::
# 462 "data/maps/RustboroCity/scripts.pory"
	lock
# 463 "data/maps/RustboroCity/scripts.pory"
	faceplayer
# 464 "data/maps/RustboroCity/scripts.pory"
	goto_if_set FLAG_RECOVERED_DEVON_GOODS, RustboroCity_EventScript_ReturnGoodsSpokeToEmployee
# 465 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_ShadyCharacterTookOffTowardsTunnel, MSGBOX_DEFAULT
# 466 "data/maps/RustboroCity/scripts.pory"
	release
# 467 "data/maps/RustboroCity/scripts.pory"
	end
# 468 "data/maps/RustboroCity/scripts.pory"

# 469 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_ReturnGoodsSpokeToEmployee::
# 470 "data/maps/RustboroCity/scripts.pory"
	waitse
# 471 "data/maps/RustboroCity/scripts.pory"
	setvar VAR_TEMP_1, 4
# 472 "data/maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_ReturnGoods
# 473 "data/maps/RustboroCity/scripts.pory"
	end
# 474 "data/maps/RustboroCity/scripts.pory"

# 475 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_HelpGetGoodsTrigger0::
# 476 "data/maps/RustboroCity/scripts.pory"
	lockall
# 477 "data/maps/RustboroCity/scripts.pory"
	setvar VAR_TEMP_1, 0
# 478 "data/maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_EmployeeAskToGetGoods
# 479 "data/maps/RustboroCity/scripts.pory"
	end
# 480 "data/maps/RustboroCity/scripts.pory"

# 481 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_HelpGetGoodsTrigger1::
# 482 "data/maps/RustboroCity/scripts.pory"
	lockall
# 483 "data/maps/RustboroCity/scripts.pory"
	setvar VAR_TEMP_1, 1
# 484 "data/maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_EmployeeAskToGetGoods
# 485 "data/maps/RustboroCity/scripts.pory"
	end
# 486 "data/maps/RustboroCity/scripts.pory"

# 487 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_HelpGetGoodsTrigger2::
# 488 "data/maps/RustboroCity/scripts.pory"
	lockall
# 489 "data/maps/RustboroCity/scripts.pory"
	setvar VAR_TEMP_1, 2
# 490 "data/maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_EmployeeAskToGetGoods
# 491 "data/maps/RustboroCity/scripts.pory"
	end
# 492 "data/maps/RustboroCity/scripts.pory"

# 493 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_HelpGetGoodsTrigger3::
# 494 "data/maps/RustboroCity/scripts.pory"
	lockall
# 495 "data/maps/RustboroCity/scripts.pory"
	setvar VAR_TEMP_1, 3
# 496 "data/maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_EmployeeAskToGetGoods
# 497 "data/maps/RustboroCity/scripts.pory"
	end
# 498 "data/maps/RustboroCity/scripts.pory"

# 499 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_EmployeeAskToGetGoods::
# 500 "data/maps/RustboroCity/scripts.pory"
	call_if_eq VAR_TEMP_1, 0, RustboroCity_EventScript_EmployeeFacePlayerUp1
# 501 "data/maps/RustboroCity/scripts.pory"
	call_if_eq VAR_TEMP_1, 1, RustboroCity_EventScript_EmployeeFacePlayerLeft1
# 502 "data/maps/RustboroCity/scripts.pory"
	call_if_eq VAR_TEMP_1, 2, RustboroCity_EventScript_EmployeeFacePlayerDown1
# 503 "data/maps/RustboroCity/scripts.pory"
	call_if_eq VAR_TEMP_1, 3, RustboroCity_EventScript_EmployeeApproachPlayerDown1
# 504 "data/maps/RustboroCity/scripts.pory"
	setflag FLAG_INTERACTED_WITH_DEVON_EMPLOYEE_GOODS_STOLEN
# 505 "data/maps/RustboroCity/scripts.pory"
	setvar VAR_RUSTBORO_CITY_STATE, 3
# 506 "data/maps/RustboroCity/scripts.pory"
	copyobjectxytoperm LOCALID_RUSTBORO_DEVON_EMPLOYEE
# 507 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_HelpMeIWasRobbed, MSGBOX_DEFAULT
# 508 "data/maps/RustboroCity/scripts.pory"
	releaseall
# 509 "data/maps/RustboroCity/scripts.pory"
	end
# 510 "data/maps/RustboroCity/scripts.pory"

# 511 "data/maps/RustboroCity/scripts.pory"
@ The below movement scripts are either partially or fully duplicated by the movement scripts when the player returns the goods
# 512 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_EmployeeFacePlayerUp1::
# 513 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_DEVON_EMPLOYEE, Common_Movement_WalkInPlaceFasterUp
# 514 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 515 "data/maps/RustboroCity/scripts.pory"
	playse SE_PIN
# 516 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_DEVON_EMPLOYEE, Common_Movement_ExclamationMark
# 517 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 518 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_DEVON_EMPLOYEE, Common_Movement_Delay48
# 519 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 520 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterDown
# 521 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 522 "data/maps/RustboroCity/scripts.pory"
	return
# 523 "data/maps/RustboroCity/scripts.pory"

# 524 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_EmployeeFacePlayerLeft1::
# 525 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_DEVON_EMPLOYEE, Common_Movement_WalkInPlaceFasterLeft
# 526 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 527 "data/maps/RustboroCity/scripts.pory"
	playse SE_PIN
# 528 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_DEVON_EMPLOYEE, Common_Movement_ExclamationMark
# 529 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 530 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_DEVON_EMPLOYEE, Common_Movement_Delay48
# 531 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 532 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_FaceRight
# 533 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 534 "data/maps/RustboroCity/scripts.pory"
	return
# 535 "data/maps/RustboroCity/scripts.pory"

# 536 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_EmployeeFacePlayerDown1::
# 537 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_DEVON_EMPLOYEE, Common_Movement_WalkInPlaceFasterDown
# 538 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 539 "data/maps/RustboroCity/scripts.pory"
	playse SE_PIN
# 540 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_DEVON_EMPLOYEE, Common_Movement_ExclamationMark
# 541 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 542 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_DEVON_EMPLOYEE, Common_Movement_Delay48
# 543 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 544 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
# 545 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 546 "data/maps/RustboroCity/scripts.pory"
	return
# 547 "data/maps/RustboroCity/scripts.pory"

# 548 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_EmployeeApproachPlayerDown1::
# 549 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_DEVON_EMPLOYEE, Common_Movement_WalkInPlaceFasterDown
# 550 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 551 "data/maps/RustboroCity/scripts.pory"
	playse SE_PIN
# 552 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_DEVON_EMPLOYEE, Common_Movement_ExclamationMark
# 553 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 554 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_DEVON_EMPLOYEE, Common_Movement_Delay48
# 555 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 556 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_DEVON_EMPLOYEE, RustboroCity_Movement_EmployeeApproachPlayerDown
# 557 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 558 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
# 559 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 560 "data/maps/RustboroCity/scripts.pory"
	return
# 561 "data/maps/RustboroCity/scripts.pory"

# 562 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Movement_EmployeeApproachPlayerDown:
# 563 "data/maps/RustboroCity/scripts.pory"
	walk_down
# 564 "data/maps/RustboroCity/scripts.pory"
	step_end
# 565 "data/maps/RustboroCity/scripts.pory"

# 566 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_ReturnGoodsTrigger0::
# 567 "data/maps/RustboroCity/scripts.pory"
	lockall
# 568 "data/maps/RustboroCity/scripts.pory"
	setvar VAR_TEMP_1, 0
# 569 "data/maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_ReturnGoods
# 570 "data/maps/RustboroCity/scripts.pory"
	end
# 571 "data/maps/RustboroCity/scripts.pory"

# 572 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_ReturnGoodsTrigger1::
# 573 "data/maps/RustboroCity/scripts.pory"
	lockall
# 574 "data/maps/RustboroCity/scripts.pory"
	setvar VAR_TEMP_1, 1
# 575 "data/maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_ReturnGoods
# 576 "data/maps/RustboroCity/scripts.pory"
	end
# 577 "data/maps/RustboroCity/scripts.pory"

# 578 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_ReturnGoodsTrigger2::
# 579 "data/maps/RustboroCity/scripts.pory"
	lockall
# 580 "data/maps/RustboroCity/scripts.pory"
	setvar VAR_TEMP_1, 2
# 581 "data/maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_ReturnGoods
# 582 "data/maps/RustboroCity/scripts.pory"
	end
# 583 "data/maps/RustboroCity/scripts.pory"

# 584 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_ReturnGoodsTrigger3::
# 585 "data/maps/RustboroCity/scripts.pory"
	lockall
# 586 "data/maps/RustboroCity/scripts.pory"
	setvar VAR_TEMP_1, 3
# 587 "data/maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_ReturnGoods
# 588 "data/maps/RustboroCity/scripts.pory"
	end
# 589 "data/maps/RustboroCity/scripts.pory"

# 590 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_ReturnGoods::
# 591 "data/maps/RustboroCity/scripts.pory"
	call_if_eq VAR_TEMP_1, 0, RustboroCity_EventScript_EmployeeFacePlayerUp2
# 592 "data/maps/RustboroCity/scripts.pory"
	call_if_eq VAR_TEMP_1, 1, RustboroCity_EventScript_EmployeeFacePlayerLeft2
# 593 "data/maps/RustboroCity/scripts.pory"
	call_if_eq VAR_TEMP_1, 2, RustboroCity_EventScript_EmployeeFacePlayerDown2
# 594 "data/maps/RustboroCity/scripts.pory"
	call_if_eq VAR_TEMP_1, 3, RustboroCity_EventScript_EmployeeApproachPlayerDown2
# 595 "data/maps/RustboroCity/scripts.pory"
	call_if_eq VAR_TEMP_1, 4, RustboroCity_EventScript_EmployeeFacePlayerRight
# 596 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_YouGotItThankYou, MSGBOX_DEFAULT
# 597 "data/maps/RustboroCity/scripts.pory"
	giveitem ITEM_GREAT_BALL
# 598 "data/maps/RustboroCity/scripts.pory"
	call_if_eq VAR_RESULT, FALSE, RustboroCity_EventScript_BagFull
# 599 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_PleaseComeWithMe, MSGBOX_DEFAULT
# 600 "data/maps/RustboroCity/scripts.pory"
	closemessage
# 601 "data/maps/RustboroCity/scripts.pory"
	setflag FLAG_RETURNED_DEVON_GOODS
# 602 "data/maps/RustboroCity/scripts.pory"
	setflag FLAG_HIDE_RUSTBORO_CITY_DEVON_EMPLOYEE_1
# 603 "data/maps/RustboroCity/scripts.pory"
	setvar VAR_RUSTBORO_CITY_STATE, 5
# 604 "data/maps/RustboroCity/scripts.pory"
	delay 30
# 605 "data/maps/RustboroCity/scripts.pory"
	warp MAP_RUSTBORO_CITY_DEVON_CORP_3F, 2, 2
# 606 "data/maps/RustboroCity/scripts.pory"
	waitstate
# 607 "data/maps/RustboroCity/scripts.pory"
	releaseall
# 608 "data/maps/RustboroCity/scripts.pory"
	end
# 609 "data/maps/RustboroCity/scripts.pory"

# 610 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_BagFull::
# 611 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_YoureLoadedWithItems, MSGBOX_DEFAULT
# 612 "data/maps/RustboroCity/scripts.pory"
	return
# 613 "data/maps/RustboroCity/scripts.pory"

# 614 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_EmployeeFacePlayerUp2::
# 615 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_DEVON_EMPLOYEE, Common_Movement_WalkInPlaceFasterUp
# 616 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 617 "data/maps/RustboroCity/scripts.pory"
	playse SE_PIN
# 618 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_DEVON_EMPLOYEE, Common_Movement_ExclamationMark
# 619 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 620 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_DEVON_EMPLOYEE, Common_Movement_Delay48
# 621 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 622 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterDown
# 623 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 624 "data/maps/RustboroCity/scripts.pory"
	return
# 625 "data/maps/RustboroCity/scripts.pory"

# 626 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_EmployeeFacePlayerLeft2::
# 627 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_DEVON_EMPLOYEE, Common_Movement_WalkInPlaceFasterRight
# 628 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 629 "data/maps/RustboroCity/scripts.pory"
	playse SE_PIN
# 630 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_DEVON_EMPLOYEE, Common_Movement_ExclamationMark
# 631 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 632 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_DEVON_EMPLOYEE, Common_Movement_Delay48
# 633 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 634 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_FaceLeft
# 635 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 636 "data/maps/RustboroCity/scripts.pory"
	return
# 637 "data/maps/RustboroCity/scripts.pory"

# 638 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_EmployeeFacePlayerDown2::
# 639 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_DEVON_EMPLOYEE, Common_Movement_WalkInPlaceFasterDown
# 640 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 641 "data/maps/RustboroCity/scripts.pory"
	playse SE_PIN
# 642 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_DEVON_EMPLOYEE, Common_Movement_ExclamationMark
# 643 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 644 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_DEVON_EMPLOYEE, Common_Movement_Delay48
# 645 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 646 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
# 647 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 648 "data/maps/RustboroCity/scripts.pory"
	return
# 649 "data/maps/RustboroCity/scripts.pory"

# 650 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_EmployeeApproachPlayerDown2::
# 651 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_DEVON_EMPLOYEE, Common_Movement_WalkInPlaceFasterDown
# 652 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 653 "data/maps/RustboroCity/scripts.pory"
	playse SE_PIN
# 654 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_DEVON_EMPLOYEE, Common_Movement_ExclamationMark
# 655 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 656 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_DEVON_EMPLOYEE, Common_Movement_Delay48
# 657 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 658 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_DEVON_EMPLOYEE, RustboroCity_Movement_EmployeeApproachPlayerDown
# 659 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 660 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
# 661 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 662 "data/maps/RustboroCity/scripts.pory"
	return
# 663 "data/maps/RustboroCity/scripts.pory"

# 664 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_EmployeeFacePlayerRight::
# 665 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_DEVON_EMPLOYEE, Common_Movement_WalkInPlaceFasterLeft
# 666 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 667 "data/maps/RustboroCity/scripts.pory"
	playse SE_PIN
# 668 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_DEVON_EMPLOYEE, Common_Movement_ExclamationMark
# 669 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 670 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_DEVON_EMPLOYEE, Common_Movement_Delay48
# 671 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 672 "data/maps/RustboroCity/scripts.pory"
	return
# 673 "data/maps/RustboroCity/scripts.pory"

# 674 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_Rival::
# 675 "data/maps/RustboroCity/scripts.pory"
	lockall
# 676 "data/maps/RustboroCity/scripts.pory"
	call_if_unset FLAG_MET_RIVAL_RUSTBORO, RustboroCity_EventScript_PlayRivalMusic
# 677 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_RIVAL, Common_Movement_FacePlayer
# 678 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 679 "data/maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_RivalEncounter
# 680 "data/maps/RustboroCity/scripts.pory"

# 681 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_PlayRivalMusic::
# 682 "data/maps/RustboroCity/scripts.pory"
	checkplayergender
# 683 "data/maps/RustboroCity/scripts.pory"
	goto_if_eq VAR_RESULT, MALE, RustboroCity_EventScript_PlayMayMusic
# 684 "data/maps/RustboroCity/scripts.pory"
	goto_if_eq VAR_RESULT, FEMALE, RustboroCity_EventScript_PlayBrendanMusic
# 685 "data/maps/RustboroCity/scripts.pory"
	return
# 686 "data/maps/RustboroCity/scripts.pory"

# 687 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_PlayMayMusic::
# 688 "data/maps/RustboroCity/scripts.pory"
	playbgm MUS_ENCOUNTER_MAY, TRUE
# 689 "data/maps/RustboroCity/scripts.pory"
	return
# 690 "data/maps/RustboroCity/scripts.pory"

# 691 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_PlayBrendanMusic::
# 692 "data/maps/RustboroCity/scripts.pory"
	playbgm MUS_ENCOUNTER_BRENDAN, TRUE
# 693 "data/maps/RustboroCity/scripts.pory"
	return
# 694 "data/maps/RustboroCity/scripts.pory"

# 695 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_RivalTrigger0::
# 696 "data/maps/RustboroCity/scripts.pory"
	lockall
# 697 "data/maps/RustboroCity/scripts.pory"
	call RustboroCity_EventScript_PlayRivalMusic
# 698 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_RIVAL, Common_Movement_WalkInPlaceFasterDown
# 699 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 700 "data/maps/RustboroCity/scripts.pory"
	playse SE_PIN
# 701 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_RIVAL, Common_Movement_ExclamationMark
# 702 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 703 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_RIVAL, Common_Movement_Delay48
# 704 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 705 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_RIVAL, RustboroCity_Movement_RivalApproachPlayer0
# 706 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 707 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
# 708 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 709 "data/maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_RivalEncounter
# 710 "data/maps/RustboroCity/scripts.pory"

# 711 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_RivalTrigger1::
# 712 "data/maps/RustboroCity/scripts.pory"
	lockall
# 713 "data/maps/RustboroCity/scripts.pory"
	call RustboroCity_EventScript_PlayRivalMusic
# 714 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_RIVAL, Common_Movement_WalkInPlaceFasterDown
# 715 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 716 "data/maps/RustboroCity/scripts.pory"
	playse SE_PIN
# 717 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_RIVAL, Common_Movement_ExclamationMark
# 718 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 719 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_RIVAL, Common_Movement_Delay48
# 720 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 721 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_RIVAL, RustboroCity_Movement_RivalApproachPlayer1
# 722 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 723 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
# 724 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 725 "data/maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_RivalEncounter
# 726 "data/maps/RustboroCity/scripts.pory"

# 727 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_RivalTrigger2::
# 728 "data/maps/RustboroCity/scripts.pory"
	lockall
# 729 "data/maps/RustboroCity/scripts.pory"
	call RustboroCity_EventScript_PlayRivalMusic
# 730 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_RIVAL, Common_Movement_WalkInPlaceFasterDown
# 731 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 732 "data/maps/RustboroCity/scripts.pory"
	playse SE_PIN
# 733 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_RIVAL, Common_Movement_ExclamationMark
# 734 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 735 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_RIVAL, Common_Movement_Delay48
# 736 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 737 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_RIVAL, RustboroCity_Movement_RivalApproachPlayer2
# 738 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 739 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
# 740 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 741 "data/maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_RivalEncounter
# 742 "data/maps/RustboroCity/scripts.pory"

# 743 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_RivalTrigger3::
# 744 "data/maps/RustboroCity/scripts.pory"
	lockall
# 745 "data/maps/RustboroCity/scripts.pory"
	call RustboroCity_EventScript_PlayRivalMusic
# 746 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_RIVAL, Common_Movement_WalkInPlaceFasterDown
# 747 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 748 "data/maps/RustboroCity/scripts.pory"
	playse SE_PIN
# 749 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_RIVAL, Common_Movement_ExclamationMark
# 750 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 751 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_RIVAL, Common_Movement_Delay48
# 752 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 753 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_RIVAL, RustboroCity_Movement_RivalApproachPlayer3
# 754 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 755 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
# 756 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 757 "data/maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_RivalEncounter
# 758 "data/maps/RustboroCity/scripts.pory"

# 759 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_RivalTrigger4::
# 760 "data/maps/RustboroCity/scripts.pory"
	lockall
# 761 "data/maps/RustboroCity/scripts.pory"
	call RustboroCity_EventScript_PlayRivalMusic
# 762 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_RIVAL, Common_Movement_WalkInPlaceFasterDown
# 763 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 764 "data/maps/RustboroCity/scripts.pory"
	playse SE_PIN
# 765 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_RIVAL, Common_Movement_ExclamationMark
# 766 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 767 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_RIVAL, Common_Movement_Delay48
# 768 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 769 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_RIVAL, RustboroCity_Movement_RivalApproachPlayer4
# 770 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 771 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
# 772 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 773 "data/maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_RivalEncounter
# 774 "data/maps/RustboroCity/scripts.pory"

# 775 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_RivalTrigger5::
# 776 "data/maps/RustboroCity/scripts.pory"
	lockall
# 777 "data/maps/RustboroCity/scripts.pory"
	call RustboroCity_EventScript_PlayRivalMusic
# 778 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_RIVAL, Common_Movement_WalkInPlaceFasterDown
# 779 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 780 "data/maps/RustboroCity/scripts.pory"
	playse SE_PIN
# 781 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_RIVAL, Common_Movement_ExclamationMark
# 782 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 783 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_RIVAL, Common_Movement_Delay48
# 784 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 785 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_RIVAL, RustboroCity_Movement_RivalApproachPlayer5
# 786 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 787 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
# 788 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 789 "data/maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_RivalEncounter
# 790 "data/maps/RustboroCity/scripts.pory"

# 791 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_RivalTrigger6::
# 792 "data/maps/RustboroCity/scripts.pory"
	lockall
# 793 "data/maps/RustboroCity/scripts.pory"
	call RustboroCity_EventScript_PlayRivalMusic
# 794 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_RIVAL, Common_Movement_WalkInPlaceFasterDown
# 795 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 796 "data/maps/RustboroCity/scripts.pory"
	playse SE_PIN
# 797 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_RIVAL, Common_Movement_ExclamationMark
# 798 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 799 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_RIVAL, Common_Movement_Delay48
# 800 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 801 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_RIVAL, RustboroCity_Movement_RivalApproachPlayer6
# 802 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 803 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
# 804 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 805 "data/maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_RivalEncounter
# 806 "data/maps/RustboroCity/scripts.pory"

# 807 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_RivalTrigger7::
# 808 "data/maps/RustboroCity/scripts.pory"
	lockall
# 809 "data/maps/RustboroCity/scripts.pory"
	call RustboroCity_EventScript_PlayRivalMusic
# 810 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_RIVAL, Common_Movement_WalkInPlaceFasterDown
# 811 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 812 "data/maps/RustboroCity/scripts.pory"
	playse SE_PIN
# 813 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_RIVAL, Common_Movement_ExclamationMark
# 814 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 815 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_RIVAL, Common_Movement_Delay48
# 816 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 817 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_RIVAL, RustboroCity_Movement_RivalApproachPlayer7
# 818 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 819 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
# 820 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 821 "data/maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_RivalEncounter
# 822 "data/maps/RustboroCity/scripts.pory"

# 823 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_RivalEncounter::
# 824 "data/maps/RustboroCity/scripts.pory"
	checkplayergender
# 825 "data/maps/RustboroCity/scripts.pory"
	goto_if_eq VAR_RESULT, MALE, RustboroCity_EventScript_MayEncounter
# 826 "data/maps/RustboroCity/scripts.pory"
	goto_if_eq VAR_RESULT, FEMALE, RustboroCity_EventScript_BrendanEncounter
# 827 "data/maps/RustboroCity/scripts.pory"
	end
# 828 "data/maps/RustboroCity/scripts.pory"

# 829 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_MayEncounter::
# 830 "data/maps/RustboroCity/scripts.pory"
	goto_if_set FLAG_DEFEATED_RIVAL_RUSTBORO, RustboroCity_EventScript_MayBrineyHint
# 831 "data/maps/RustboroCity/scripts.pory"
	goto_if_set FLAG_MET_RIVAL_RUSTBORO, RustboroCity_EventScript_MayAskToBattle
# 832 "data/maps/RustboroCity/scripts.pory"
	setflag FLAG_MET_RIVAL_RUSTBORO
# 833 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_MayHiLetsRegister, MSGBOX_DEFAULT
# 834 "data/maps/RustboroCity/scripts.pory"
	closemessage
# 835 "data/maps/RustboroCity/scripts.pory"
	delay 30
# 836 "data/maps/RustboroCity/scripts.pory"
	playfanfare MUS_REGISTER_MATCH_CALL
# 837 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_RegisteredMay, MSGBOX_DEFAULT
# 838 "data/maps/RustboroCity/scripts.pory"
	waitfanfare
# 839 "data/maps/RustboroCity/scripts.pory"
	closemessage
# 840 "data/maps/RustboroCity/scripts.pory"
	delay 30
# 841 "data/maps/RustboroCity/scripts.pory"
	setflag FLAG_ENABLE_RIVAL_MATCH_CALL
# 842 "data/maps/RustboroCity/scripts.pory"
	setvar VAR_RUSTBORO_CITY_STATE, 8
# 843 "data/maps/RustboroCity/scripts.pory"
	setvar VAR_ROUTE104_STATE, 2
# 844 "data/maps/RustboroCity/scripts.pory"
	setvar VAR_0x8008, 0
# 845 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_MayPassedBrineyWantToBattle, MSGBOX_YESNO
# 846 "data/maps/RustboroCity/scripts.pory"
	goto_if_eq VAR_RESULT, YES, RustboroCity_EventScript_BattleMay
# 847 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_MayOhHaventRaisedPokemonEnough, MSGBOX_DEFAULT
# 848 "data/maps/RustboroCity/scripts.pory"
	call RustboroCity_EventScript_RestoreBgm
# 849 "data/maps/RustboroCity/scripts.pory"
	releaseall
# 850 "data/maps/RustboroCity/scripts.pory"
	end
# 851 "data/maps/RustboroCity/scripts.pory"

# 852 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_MayAskToBattle::
# 853 "data/maps/RustboroCity/scripts.pory"
	setvar VAR_0x8008, 1
# 854 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_MayWantToBattle, MSGBOX_YESNO
# 855 "data/maps/RustboroCity/scripts.pory"
	goto_if_eq VAR_RESULT, YES, RustboroCity_EventScript_BattleMay
# 856 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_MayOhHaventRaisedPokemonEnough, MSGBOX_DEFAULT
# 857 "data/maps/RustboroCity/scripts.pory"
	releaseall
# 858 "data/maps/RustboroCity/scripts.pory"
	end
# 859 "data/maps/RustboroCity/scripts.pory"

# 860 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_BattleMay::
# 861 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_MayImNotGoingToLose, MSGBOX_DEFAULT
# 862 "data/maps/RustboroCity/scripts.pory"
	switch VAR_STARTER_MON
# 863 "data/maps/RustboroCity/scripts.pory"
	case 0, RustboroCity_EventScript_BattleMayTreecko
# 864 "data/maps/RustboroCity/scripts.pory"
	case 1, RustboroCity_EventScript_BattleMayTorchic
# 865 "data/maps/RustboroCity/scripts.pory"
	case 2, RustboroCity_EventScript_BattleMayMudkip
# 866 "data/maps/RustboroCity/scripts.pory"
	end
# 867 "data/maps/RustboroCity/scripts.pory"

# 868 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_MayBrineyHint::
# 869 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_MayMrBrineyHint, MSGBOX_DEFAULT
# 870 "data/maps/RustboroCity/scripts.pory"
	call_if_eq VAR_0x8008, 0, RustboroCity_EventScript_RestoreBgm
# 871 "data/maps/RustboroCity/scripts.pory"
	releaseall
# 872 "data/maps/RustboroCity/scripts.pory"
	end
# 873 "data/maps/RustboroCity/scripts.pory"

# 874 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_RestoreBgm::
# 875 "data/maps/RustboroCity/scripts.pory"
	savebgm MUS_DUMMY
# 876 "data/maps/RustboroCity/scripts.pory"
	fadedefaultbgm
# 877 "data/maps/RustboroCity/scripts.pory"
	return
# 878 "data/maps/RustboroCity/scripts.pory"

# 879 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_BattleMayTreecko::
# 880 "data/maps/RustboroCity/scripts.pory"
	trainerbattle_no_intro TRAINER_MAY_RUSTBORO_TREECKO, RustboroCity_Text_MayDefeat
# 881 "data/maps/RustboroCity/scripts.pory"
	setflag FLAG_DEFEATED_RIVAL_RUSTBORO
# 882 "data/maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_MayBrineyHint
# 883 "data/maps/RustboroCity/scripts.pory"
	end
# 884 "data/maps/RustboroCity/scripts.pory"

# 885 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_BattleMayTorchic::
# 886 "data/maps/RustboroCity/scripts.pory"
	trainerbattle_no_intro TRAINER_MAY_RUSTBORO_TORCHIC, RustboroCity_Text_MayDefeat
# 887 "data/maps/RustboroCity/scripts.pory"
	setflag FLAG_DEFEATED_RIVAL_RUSTBORO
# 888 "data/maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_MayBrineyHint
# 889 "data/maps/RustboroCity/scripts.pory"
	end
# 890 "data/maps/RustboroCity/scripts.pory"

# 891 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_BattleMayMudkip::
# 892 "data/maps/RustboroCity/scripts.pory"
	trainerbattle_no_intro TRAINER_MAY_RUSTBORO_MUDKIP, RustboroCity_Text_MayDefeat
# 893 "data/maps/RustboroCity/scripts.pory"
	setflag FLAG_DEFEATED_RIVAL_RUSTBORO
# 894 "data/maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_MayBrineyHint
# 895 "data/maps/RustboroCity/scripts.pory"
	end
# 896 "data/maps/RustboroCity/scripts.pory"

# 897 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_BrendanEncounter::
# 898 "data/maps/RustboroCity/scripts.pory"
	goto_if_set FLAG_DEFEATED_RIVAL_RUSTBORO, RustboroCity_EventScript_BrendanBrineyHint
# 899 "data/maps/RustboroCity/scripts.pory"
	goto_if_set FLAG_MET_RIVAL_RUSTBORO, RustboroCity_EventScript_BrendanAskToBattle
# 900 "data/maps/RustboroCity/scripts.pory"
	setflag FLAG_MET_RIVAL_RUSTBORO
# 901 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_BrendanHiLetsRegister, MSGBOX_DEFAULT
# 902 "data/maps/RustboroCity/scripts.pory"
	closemessage
# 903 "data/maps/RustboroCity/scripts.pory"
	delay 30
# 904 "data/maps/RustboroCity/scripts.pory"
	playfanfare MUS_REGISTER_MATCH_CALL
# 905 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_RegisteredBrendan, MSGBOX_DEFAULT
# 906 "data/maps/RustboroCity/scripts.pory"
	waitfanfare
# 907 "data/maps/RustboroCity/scripts.pory"
	closemessage
# 908 "data/maps/RustboroCity/scripts.pory"
	delay 30
# 909 "data/maps/RustboroCity/scripts.pory"
	setflag FLAG_ENABLE_RIVAL_MATCH_CALL
# 910 "data/maps/RustboroCity/scripts.pory"
	setvar VAR_RUSTBORO_CITY_STATE, 8
# 911 "data/maps/RustboroCity/scripts.pory"
	setvar VAR_ROUTE104_STATE, 2
# 912 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_BrendanPassedBrineyWantToBattle, MSGBOX_YESNO
# 913 "data/maps/RustboroCity/scripts.pory"
	goto_if_eq VAR_RESULT, YES, RustboroCity_EventScript_BattleBrendan
# 914 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_BrendanNoConfidenceInPokemon, MSGBOX_DEFAULT
# 915 "data/maps/RustboroCity/scripts.pory"
	call RustboroCity_EventScript_RestoreBgm
# 916 "data/maps/RustboroCity/scripts.pory"
	releaseall
# 917 "data/maps/RustboroCity/scripts.pory"
	end
# 918 "data/maps/RustboroCity/scripts.pory"

# 919 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_BrendanAskToBattle::
# 920 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_BrendanWantToBattle, MSGBOX_YESNO
# 921 "data/maps/RustboroCity/scripts.pory"
	goto_if_eq VAR_RESULT, YES, RustboroCity_EventScript_BattleBrendan
# 922 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_BrendanNoConfidenceInPokemon, MSGBOX_DEFAULT
# 923 "data/maps/RustboroCity/scripts.pory"
	releaseall
# 924 "data/maps/RustboroCity/scripts.pory"
	end
# 925 "data/maps/RustboroCity/scripts.pory"

# 926 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_BattleBrendan::
# 927 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_BrendanIWontGoEasy, MSGBOX_DEFAULT
# 928 "data/maps/RustboroCity/scripts.pory"
	switch VAR_STARTER_MON
# 929 "data/maps/RustboroCity/scripts.pory"
	case 0, RustboroCity_EventScript_BattleBrendanTreecko
# 930 "data/maps/RustboroCity/scripts.pory"
	case 1, RustboroCity_EventScript_BattleBrendanTorchic
# 931 "data/maps/RustboroCity/scripts.pory"
	case 2, RustboroCity_EventScript_BattleBrendanMudkip
# 932 "data/maps/RustboroCity/scripts.pory"
	end
# 933 "data/maps/RustboroCity/scripts.pory"

# 934 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_BrendanBrineyHint::
# 935 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_BrendanMrBrineyHint, MSGBOX_DEFAULT
# 936 "data/maps/RustboroCity/scripts.pory"
	call_if_eq VAR_0x8008, 0, RustboroCity_EventScript_RestoreBgm
# 937 "data/maps/RustboroCity/scripts.pory"
	releaseall
# 938 "data/maps/RustboroCity/scripts.pory"
	end
# 939 "data/maps/RustboroCity/scripts.pory"

# 940 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_BattleBrendanTreecko::
# 941 "data/maps/RustboroCity/scripts.pory"
	trainerbattle_no_intro TRAINER_BRENDAN_RUSTBORO_TREECKO, RustboroCity_Text_BrendanDefeat
# 942 "data/maps/RustboroCity/scripts.pory"
	setflag FLAG_DEFEATED_RIVAL_RUSTBORO
# 943 "data/maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_BrendanBrineyHint
# 944 "data/maps/RustboroCity/scripts.pory"
	end
# 945 "data/maps/RustboroCity/scripts.pory"

# 946 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_BattleBrendanTorchic::
# 947 "data/maps/RustboroCity/scripts.pory"
	trainerbattle_no_intro TRAINER_BRENDAN_RUSTBORO_TORCHIC, RustboroCity_Text_BrendanDefeat
# 948 "data/maps/RustboroCity/scripts.pory"
	setflag FLAG_DEFEATED_RIVAL_RUSTBORO
# 949 "data/maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_BrendanBrineyHint
# 950 "data/maps/RustboroCity/scripts.pory"
	end
# 951 "data/maps/RustboroCity/scripts.pory"

# 952 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_BattleBrendanMudkip::
# 953 "data/maps/RustboroCity/scripts.pory"
	trainerbattle_no_intro TRAINER_BRENDAN_RUSTBORO_MUDKIP, RustboroCity_Text_BrendanDefeat
# 954 "data/maps/RustboroCity/scripts.pory"
	setflag FLAG_DEFEATED_RIVAL_RUSTBORO
# 955 "data/maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_BrendanBrineyHint
# 956 "data/maps/RustboroCity/scripts.pory"
	end
# 957 "data/maps/RustboroCity/scripts.pory"

# 958 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Movement_RivalApproachPlayer0:
# 959 "data/maps/RustboroCity/scripts.pory"
	walk_down
# 960 "data/maps/RustboroCity/scripts.pory"
	walk_left
# 961 "data/maps/RustboroCity/scripts.pory"
	walk_left
# 962 "data/maps/RustboroCity/scripts.pory"
	walk_left
# 963 "data/maps/RustboroCity/scripts.pory"
	walk_left
# 964 "data/maps/RustboroCity/scripts.pory"
	walk_down
# 965 "data/maps/RustboroCity/scripts.pory"
	step_end
# 966 "data/maps/RustboroCity/scripts.pory"

# 967 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Movement_RivalApproachPlayer1:
# 968 "data/maps/RustboroCity/scripts.pory"
	walk_down
# 969 "data/maps/RustboroCity/scripts.pory"
	walk_left
# 970 "data/maps/RustboroCity/scripts.pory"
	walk_left
# 971 "data/maps/RustboroCity/scripts.pory"
	walk_left
# 972 "data/maps/RustboroCity/scripts.pory"
	walk_down
# 973 "data/maps/RustboroCity/scripts.pory"
	step_end
# 974 "data/maps/RustboroCity/scripts.pory"

# 975 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Movement_RivalApproachPlayer2:
# 976 "data/maps/RustboroCity/scripts.pory"
	walk_down
# 977 "data/maps/RustboroCity/scripts.pory"
	walk_left
# 978 "data/maps/RustboroCity/scripts.pory"
	walk_left
# 979 "data/maps/RustboroCity/scripts.pory"
	walk_down
# 980 "data/maps/RustboroCity/scripts.pory"
	step_end
# 981 "data/maps/RustboroCity/scripts.pory"

# 982 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Movement_RivalApproachPlayer3:
# 983 "data/maps/RustboroCity/scripts.pory"
	walk_down
# 984 "data/maps/RustboroCity/scripts.pory"
	walk_left
# 985 "data/maps/RustboroCity/scripts.pory"
	walk_down
# 986 "data/maps/RustboroCity/scripts.pory"
	step_end
# 987 "data/maps/RustboroCity/scripts.pory"

# 988 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Movement_RivalApproachPlayer4:
# 989 "data/maps/RustboroCity/scripts.pory"
	walk_down
# 990 "data/maps/RustboroCity/scripts.pory"
	walk_down
# 991 "data/maps/RustboroCity/scripts.pory"
	step_end
# 992 "data/maps/RustboroCity/scripts.pory"

# 993 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Movement_RivalApproachPlayer5:
# 994 "data/maps/RustboroCity/scripts.pory"
	walk_down
# 995 "data/maps/RustboroCity/scripts.pory"
	walk_right
# 996 "data/maps/RustboroCity/scripts.pory"
	walk_down
# 997 "data/maps/RustboroCity/scripts.pory"
	step_end
# 998 "data/maps/RustboroCity/scripts.pory"

# 999 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Movement_RivalApproachPlayer6:
# 1000 "data/maps/RustboroCity/scripts.pory"
	walk_down
# 1001 "data/maps/RustboroCity/scripts.pory"
	walk_right
# 1002 "data/maps/RustboroCity/scripts.pory"
	walk_right
# 1003 "data/maps/RustboroCity/scripts.pory"
	walk_down
# 1004 "data/maps/RustboroCity/scripts.pory"
	step_end
# 1005 "data/maps/RustboroCity/scripts.pory"

# 1006 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Movement_RivalApproachPlayer7:
# 1007 "data/maps/RustboroCity/scripts.pory"
	walk_down
# 1008 "data/maps/RustboroCity/scripts.pory"
	walk_right
# 1009 "data/maps/RustboroCity/scripts.pory"
	walk_right
# 1010 "data/maps/RustboroCity/scripts.pory"
	walk_right
# 1011 "data/maps/RustboroCity/scripts.pory"
	walk_down
# 1012 "data/maps/RustboroCity/scripts.pory"
	step_end
# 1013 "data/maps/RustboroCity/scripts.pory"

# 1014 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_Boy1::
# 1015 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_YouCanHave2On2Battle, MSGBOX_NPC
# 1016 "data/maps/RustboroCity/scripts.pory"
	end
# 1017 "data/maps/RustboroCity/scripts.pory"

# 1018 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_WeShortenItToDevon:
# 1019 "data/maps/RustboroCity/scripts.pory"
	.string "The DEVON CORPORATION…\n"
# 1020 "data/maps/RustboroCity/scripts.pory"
	.string "We all just shorten it to DEVON.\p"
# 1021 "data/maps/RustboroCity/scripts.pory"
	.string "That company makes all sorts of\n"
# 1022 "data/maps/RustboroCity/scripts.pory"
	.string "convenient products.$"
# 1023 "data/maps/RustboroCity/scripts.pory"

# 1024 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_SneakyLookingManWentAroundCorner:
# 1025 "data/maps/RustboroCity/scripts.pory"
	.string "Hm? A sneaky-looking man?\p"
# 1026 "data/maps/RustboroCity/scripts.pory"
	.string "Come to think of it, yes, a shady-\n"
# 1027 "data/maps/RustboroCity/scripts.pory"
	.string "looking guy went around the corner.$"
# 1028 "data/maps/RustboroCity/scripts.pory"

# 1029 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_HaveYouChallengedGym:
# 1030 "data/maps/RustboroCity/scripts.pory"
	.string "Have you taken the POKéMON GYM\n"
# 1031 "data/maps/RustboroCity/scripts.pory"
	.string "challenge?\p"
# 1032 "data/maps/RustboroCity/scripts.pory"
	.string "When you get that shiny GYM BADGE\n"
# 1033 "data/maps/RustboroCity/scripts.pory"
	.string "in hand, I guess TRAINERS begin to\l"
# 1034 "data/maps/RustboroCity/scripts.pory"
	.string "realize what is required of them.$"
# 1035 "data/maps/RustboroCity/scripts.pory"

# 1036 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_HeyThatsRustborosGymBadge:
# 1037 "data/maps/RustboroCity/scripts.pory"
	.string "Hey, that's RUSTBORO's GYM BADGE!\p"
# 1038 "data/maps/RustboroCity/scripts.pory"
	.string "Out of all the POKéMON GYM BADGES,\n"
# 1039 "data/maps/RustboroCity/scripts.pory"
	.string "RUSTBORO's is the coolest, I'd say.$"
# 1040 "data/maps/RustboroCity/scripts.pory"

# 1041 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_YoureNewAroundHere:
# 1042 "data/maps/RustboroCity/scripts.pory"
	.string "Oh? Who might you be?\n"
# 1043 "data/maps/RustboroCity/scripts.pory"
	.string "You're a new face around these parts.\p"
# 1044 "data/maps/RustboroCity/scripts.pory"
	.string "Have you just transferred into the\n"
# 1045 "data/maps/RustboroCity/scripts.pory"
	.string "POKéMON TRAINER'S SCHOOL?$"
# 1046 "data/maps/RustboroCity/scripts.pory"

# 1047 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_GymLeaderIsntEasyWithFire:
# 1048 "data/maps/RustboroCity/scripts.pory"
	.string "I challenged the GYM LEADER, but…\p"
# 1049 "data/maps/RustboroCity/scripts.pory"
	.string "It's not going to be easy winning with\n"
# 1050 "data/maps/RustboroCity/scripts.pory"
	.string "my FIRE-type POKéMON…\p"
# 1051 "data/maps/RustboroCity/scripts.pory"
	.string "FIRE-type POKéMON don't match up\n"
# 1052 "data/maps/RustboroCity/scripts.pory"
	.string "well against ROCK-type POKéMON…$"
# 1053 "data/maps/RustboroCity/scripts.pory"

# 1054 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_MrBrineyWalksInTheTunnel:
# 1055 "data/maps/RustboroCity/scripts.pory"
	.string "The old sailor MR. BRINEY lives in\n"
# 1056 "data/maps/RustboroCity/scripts.pory"
	.string "a cottage by the sea.\p"
# 1057 "data/maps/RustboroCity/scripts.pory"
	.string "He goes for walks in the tunnel every\n"
# 1058 "data/maps/RustboroCity/scripts.pory"
	.string "so often.$"
# 1059 "data/maps/RustboroCity/scripts.pory"

# 1060 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_MrBrineyLovesPeeko:
# 1061 "data/maps/RustboroCity/scripts.pory"
	.string "The old sailor MR. BRINEY lives in\n"
# 1062 "data/maps/RustboroCity/scripts.pory"
	.string "a cottage by the sea.\p"
# 1063 "data/maps/RustboroCity/scripts.pory"
	.string "He said he was going shopping in\n"
# 1064 "data/maps/RustboroCity/scripts.pory"
	.string "SLATEPORT for his pet, PEEKO.\p"
# 1065 "data/maps/RustboroCity/scripts.pory"
	.string "That old sea dog, he must really love\n"
# 1066 "data/maps/RustboroCity/scripts.pory"
	.string "that PEEKO.$"
# 1067 "data/maps/RustboroCity/scripts.pory"

# 1068 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_WowYouHavePokemon:
# 1069 "data/maps/RustboroCity/scripts.pory"
	.string "Wow, you have POKéMON with you, too.\p"
# 1070 "data/maps/RustboroCity/scripts.pory"
	.string "When I get bigger, I'm going to go\n"
# 1071 "data/maps/RustboroCity/scripts.pory"
	.string "places with POKéMON, too.$"
# 1072 "data/maps/RustboroCity/scripts.pory"

# 1073 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_CatchRarePokemonIfIGoToSchool:
# 1074 "data/maps/RustboroCity/scripts.pory"
	.string "POKéMON TRAINER'S SCHOOL!\p"
# 1075 "data/maps/RustboroCity/scripts.pory"
	.string "If I go to this school, will I be able\n"
# 1076 "data/maps/RustboroCity/scripts.pory"
	.string "to catch rare POKéMON easily?$"
# 1077 "data/maps/RustboroCity/scripts.pory"

# 1078 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_PokemonCanChangeLookFromExp:
# 1079 "data/maps/RustboroCity/scripts.pory"
	.string "If a POKéMON gains experience in\n"
# 1080 "data/maps/RustboroCity/scripts.pory"
	.string "battles, it can sometimes change in\l"
# 1081 "data/maps/RustboroCity/scripts.pory"
	.string "the way it looks.$"
# 1082 "data/maps/RustboroCity/scripts.pory"

# 1083 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_PokemonChangeShape:
# 1084 "data/maps/RustboroCity/scripts.pory"
	.string "A POKéMON changes shape?\n"
# 1085 "data/maps/RustboroCity/scripts.pory"
	.string "If one did that, I would be shocked!$"
# 1086 "data/maps/RustboroCity/scripts.pory"

# 1087 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_TradePokemonGrowFast:
# 1088 "data/maps/RustboroCity/scripts.pory"
	.string "A POKéMON you get in a trade from\n"
# 1089 "data/maps/RustboroCity/scripts.pory"
	.string "someone grows fast.\p"
# 1090 "data/maps/RustboroCity/scripts.pory"
	.string "But if you don't have certain GYM\n"
# 1091 "data/maps/RustboroCity/scripts.pory"
	.string "BADGES, it may not obey you…$"
# 1092 "data/maps/RustboroCity/scripts.pory"

# 1093 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_OutOfTheWay:
# 1094 "data/maps/RustboroCity/scripts.pory"
	.string "Get out!\n"
# 1095 "data/maps/RustboroCity/scripts.pory"
	.string "Out of the way!$"
# 1096 "data/maps/RustboroCity/scripts.pory"

# 1097 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_WaitDontTakeMyGoods:
# 1098 "data/maps/RustboroCity/scripts.pory"
	.string "Wait! Pleeeaaase!\p"
# 1099 "data/maps/RustboroCity/scripts.pory"
	.string "Don't take my GOODS!$"
# 1100 "data/maps/RustboroCity/scripts.pory"

# 1101 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_HelpMeIWasRobbed:
# 1102 "data/maps/RustboroCity/scripts.pory"
	.string "Oh, it's you!\p"
# 1103 "data/maps/RustboroCity/scripts.pory"
	.string "You're that fantastic TRAINER who\n"
# 1104 "data/maps/RustboroCity/scripts.pory"
	.string "helped me in PETALBURG WOODS!\p"
# 1105 "data/maps/RustboroCity/scripts.pory"
	.string "Help me! I was robbed by TEAM AQUA!\n"
# 1106 "data/maps/RustboroCity/scripts.pory"
	.string "I have to get the DEVON GOODS back!\p"
# 1107 "data/maps/RustboroCity/scripts.pory"
	.string "If I don't…\n"
# 1108 "data/maps/RustboroCity/scripts.pory"
	.string "I'm going to be in serious trouble.$"
# 1109 "data/maps/RustboroCity/scripts.pory"

# 1110 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_ShadyCharacterTookOffTowardsTunnel:
# 1111 "data/maps/RustboroCity/scripts.pory"
	.string "That shady character, I think he took\n"
# 1112 "data/maps/RustboroCity/scripts.pory"
	.string "off towards the tunnel over there.$"
# 1113 "data/maps/RustboroCity/scripts.pory"

# 1114 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_YouGotItThankYou:
# 1115 "data/maps/RustboroCity/scripts.pory"
	.string "Oh! How did it go?\n"
# 1116 "data/maps/RustboroCity/scripts.pory"
	.string "The DEVON GOODS?\p"
# 1117 "data/maps/RustboroCity/scripts.pory"
	.string "You did!\n"
# 1118 "data/maps/RustboroCity/scripts.pory"
	.string "You got them back!\p"
# 1119 "data/maps/RustboroCity/scripts.pory"
	.string "You really are a great TRAINER!\p"
# 1120 "data/maps/RustboroCity/scripts.pory"
	.string "I know! As my thanks, I'll give you\n"
# 1121 "data/maps/RustboroCity/scripts.pory"
	.string "another GREAT BALL!$"
# 1122 "data/maps/RustboroCity/scripts.pory"

# 1123 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_YoureLoadedWithItems:
# 1124 "data/maps/RustboroCity/scripts.pory"
	.string "You're loaded with items.\n"
# 1125 "data/maps/RustboroCity/scripts.pory"
	.string "I can't give you this GREAT BALL.$"
# 1126 "data/maps/RustboroCity/scripts.pory"

# 1127 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_PleaseComeWithMe:
# 1128 "data/maps/RustboroCity/scripts.pory"
	.string "Excuse me, please!\n"
# 1129 "data/maps/RustboroCity/scripts.pory"
	.string "Please come with me!$"
# 1130 "data/maps/RustboroCity/scripts.pory"

# 1131 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_MayHiLetsRegister:
# 1132 "data/maps/RustboroCity/scripts.pory"
	.string "MAY: Oh, hi, {PLAYER}{KUN}!\p"
# 1133 "data/maps/RustboroCity/scripts.pory"
	.string "You had a MATCH CALL feature put\n"
# 1134 "data/maps/RustboroCity/scripts.pory"
	.string "on your POKéNAV!\p"
# 1135 "data/maps/RustboroCity/scripts.pory"
	.string "Let's register each other so we can\n"
# 1136 "data/maps/RustboroCity/scripts.pory"
	.string "contact one another anytime!\p"
# 1137 "data/maps/RustboroCity/scripts.pory"
	.string "… … … … … …$"
# 1138 "data/maps/RustboroCity/scripts.pory"

# 1139 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_RegisteredMay:
# 1140 "data/maps/RustboroCity/scripts.pory"
	.string "Registered MAY\n"
# 1141 "data/maps/RustboroCity/scripts.pory"
	.string "in the POKéNAV.$"
# 1142 "data/maps/RustboroCity/scripts.pory"

# 1143 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_MayPassedBrineyWantToBattle:
# 1144 "data/maps/RustboroCity/scripts.pory"
	.string "MAY: Oh, by the way, I passed\n"
# 1145 "data/maps/RustboroCity/scripts.pory"
	.string "MR. BRINEY in PETALBURG WOODS.\p"
# 1146 "data/maps/RustboroCity/scripts.pory"
	.string "I guess he's on his way home to his\n"
# 1147 "data/maps/RustboroCity/scripts.pory"
	.string "cottage by the sea.\p"
# 1148 "data/maps/RustboroCity/scripts.pory"
	.string "How's your POKéDEX coming along,\n"
# 1149 "data/maps/RustboroCity/scripts.pory"
	.string "{PLAYER}{KUN}? Mine's looking pretty decent!\p"
# 1150 "data/maps/RustboroCity/scripts.pory"
	.string "So…\n"
# 1151 "data/maps/RustboroCity/scripts.pory"
	.string "How about a little battle?$"
# 1152 "data/maps/RustboroCity/scripts.pory"

# 1153 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_MayOhHaventRaisedPokemonEnough:
# 1154 "data/maps/RustboroCity/scripts.pory"
	.string "MAY: Oh, what's the matter?\p"
# 1155 "data/maps/RustboroCity/scripts.pory"
	.string "Haven't you caught or raised your\n"
# 1156 "data/maps/RustboroCity/scripts.pory"
	.string "POKéMON very much?\p"
# 1157 "data/maps/RustboroCity/scripts.pory"
	.string "That's not very good for a TRAINER!$"
# 1158 "data/maps/RustboroCity/scripts.pory"

# 1159 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_MayWantToBattle:
# 1160 "data/maps/RustboroCity/scripts.pory"
	.string "MAY: So, what do you think?\n"
# 1161 "data/maps/RustboroCity/scripts.pory"
	.string "How about a little battle here?$"
# 1162 "data/maps/RustboroCity/scripts.pory"

# 1163 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_MayImNotGoingToLose:
# 1164 "data/maps/RustboroCity/scripts.pory"
	.string "MAY: You just became a TRAINER,\n"
# 1165 "data/maps/RustboroCity/scripts.pory"
	.string "{PLAYER}{KUN}. I'm not going to lose!$"
# 1166 "data/maps/RustboroCity/scripts.pory"

# 1167 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_MayDefeat:
# 1168 "data/maps/RustboroCity/scripts.pory"
	.string "Yikes!\n"
# 1169 "data/maps/RustboroCity/scripts.pory"
	.string "You're better than I expected!$"
# 1170 "data/maps/RustboroCity/scripts.pory"

# 1171 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_MayMrBrineyHint:
# 1172 "data/maps/RustboroCity/scripts.pory"
	.string "MAY: Oh, by the way, MR. BRINEY, who\n"
# 1173 "data/maps/RustboroCity/scripts.pory"
	.string "I just passed…\p"
# 1174 "data/maps/RustboroCity/scripts.pory"
	.string "{PLAYER}{KUN}, you just moved here so you\n"
# 1175 "data/maps/RustboroCity/scripts.pory"
	.string "might not know this, but MR. BRINEY\l"
# 1176 "data/maps/RustboroCity/scripts.pory"
	.string "was once a revered seafarer.$"
# 1177 "data/maps/RustboroCity/scripts.pory"

# 1178 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_BrendanHiLetsRegister:
# 1179 "data/maps/RustboroCity/scripts.pory"
	.string "BRENDAN: Oh, hey, {PLAYER}!\p"
# 1180 "data/maps/RustboroCity/scripts.pory"
	.string "You had a MATCH CALL feature put\n"
# 1181 "data/maps/RustboroCity/scripts.pory"
	.string "on your POKéNAV! Cool!\p"
# 1182 "data/maps/RustboroCity/scripts.pory"
	.string "Let's register each other so we can\n"
# 1183 "data/maps/RustboroCity/scripts.pory"
	.string "get in touch anytime!\p"
# 1184 "data/maps/RustboroCity/scripts.pory"
	.string "… … … … … …$"
# 1185 "data/maps/RustboroCity/scripts.pory"

# 1186 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_RegisteredBrendan:
# 1187 "data/maps/RustboroCity/scripts.pory"
	.string "Registered BRENDAN\n"
# 1188 "data/maps/RustboroCity/scripts.pory"
	.string "in the POKéNAV.$"
# 1189 "data/maps/RustboroCity/scripts.pory"

# 1190 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_BrendanPassedBrineyWantToBattle:
# 1191 "data/maps/RustboroCity/scripts.pory"
	.string "BRENDAN: By the way, {PLAYER}, I walked\n"
# 1192 "data/maps/RustboroCity/scripts.pory"
	.string "by MR. BRINEY in PETALBURG WOODS.\p"
# 1193 "data/maps/RustboroCity/scripts.pory"
	.string "I bet he was on his way home to his\n"
# 1194 "data/maps/RustboroCity/scripts.pory"
	.string "cottage by the sea.\p"
# 1195 "data/maps/RustboroCity/scripts.pory"
	.string "{PLAYER}, how's your POKéDEX?\n"
# 1196 "data/maps/RustboroCity/scripts.pory"
	.string "Have you filled in any pages yet?\p"
# 1197 "data/maps/RustboroCity/scripts.pory"
	.string "Mine rules.\p"
# 1198 "data/maps/RustboroCity/scripts.pory"
	.string "Want to have a battle to test how\n"
# 1199 "data/maps/RustboroCity/scripts.pory"
	.string "far you've progressed?$"
# 1200 "data/maps/RustboroCity/scripts.pory"

# 1201 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_BrendanNoConfidenceInPokemon:
# 1202 "data/maps/RustboroCity/scripts.pory"
	.string "BRENDAN: What's the matter? Don't have\n"
# 1203 "data/maps/RustboroCity/scripts.pory"
	.string "any confidence in your POKéMON?$"
# 1204 "data/maps/RustboroCity/scripts.pory"

# 1205 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_BrendanWantToBattle:
# 1206 "data/maps/RustboroCity/scripts.pory"
	.string "BRENDAN: What's up?\n"
# 1207 "data/maps/RustboroCity/scripts.pory"
	.string "Want to have a battle with me?$"
# 1208 "data/maps/RustboroCity/scripts.pory"

# 1209 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_BrendanIWontGoEasy:
# 1210 "data/maps/RustboroCity/scripts.pory"
	.string "BRENDAN: I know you just became\n"
# 1211 "data/maps/RustboroCity/scripts.pory"
	.string "a TRAINER, but I won't go easy!$"
# 1212 "data/maps/RustboroCity/scripts.pory"

# 1213 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_BrendanDefeat:
# 1214 "data/maps/RustboroCity/scripts.pory"
	.string "Hmm…\n"
# 1215 "data/maps/RustboroCity/scripts.pory"
	.string "You're pretty good.$"
# 1216 "data/maps/RustboroCity/scripts.pory"

# 1217 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_BrendanMrBrineyHint:
# 1218 "data/maps/RustboroCity/scripts.pory"
	.string "BRENDAN: By the way, you know\n"
# 1219 "data/maps/RustboroCity/scripts.pory"
	.string "MR. BRINEY? The guy I just passed?\p"
# 1220 "data/maps/RustboroCity/scripts.pory"
	.string "I bet you didn't know this, since you\n"
# 1221 "data/maps/RustboroCity/scripts.pory"
	.string "just moved here, {PLAYER}, but\l"
# 1222 "data/maps/RustboroCity/scripts.pory"
	.string "MR. BRINEY was once a great sailor.$"
# 1223 "data/maps/RustboroCity/scripts.pory"

# 1224 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_TunnelNearingCompletion:
# 1225 "data/maps/RustboroCity/scripts.pory"
	.string "“Timesaving tunnel nearing\n"
# 1226 "data/maps/RustboroCity/scripts.pory"
	.string "completion!”\p"
# 1227 "data/maps/RustboroCity/scripts.pory"
	.string "…Is what it says on the sign, but\n"
# 1228 "data/maps/RustboroCity/scripts.pory"
	.string "there's also a big “X” splashed\l"
# 1229 "data/maps/RustboroCity/scripts.pory"
	.string "across it in red paint…$"
# 1230 "data/maps/RustboroCity/scripts.pory"

# 1231 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_DevonCorpSign:
# 1232 "data/maps/RustboroCity/scripts.pory"
	.string "DEVON CORPORATION\p"
# 1233 "data/maps/RustboroCity/scripts.pory"
	.string "“For all your living needs, we make\n"
# 1234 "data/maps/RustboroCity/scripts.pory"
	.string "it all.”$"
# 1235 "data/maps/RustboroCity/scripts.pory"

# 1236 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_GymSign:
# 1237 "data/maps/RustboroCity/scripts.pory"
	.string "RUSTBORO CITY POKéMON GYM\n"
# 1238 "data/maps/RustboroCity/scripts.pory"
	.string "LEADER: ROXANNE\p"
# 1239 "data/maps/RustboroCity/scripts.pory"
	.string "“The ROCK-loving honors student!”$"
# 1240 "data/maps/RustboroCity/scripts.pory"

# 1241 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_DevonCorpBranchOfficeSign:
# 1242 "data/maps/RustboroCity/scripts.pory"
	.string "DEVON CORP. BRANCH OFFICE\p"
# 1243 "data/maps/RustboroCity/scripts.pory"
	.string "“Access limited to DEVON employees\n"
# 1244 "data/maps/RustboroCity/scripts.pory"
	.string "and authorized personnel.”$"
# 1245 "data/maps/RustboroCity/scripts.pory"

# 1246 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_CitySign:
# 1247 "data/maps/RustboroCity/scripts.pory"
	.string "RUSTBORO CITY\p"
# 1248 "data/maps/RustboroCity/scripts.pory"
	.string "“The city probing the integration of\n"
# 1249 "data/maps/RustboroCity/scripts.pory"
	.string "nature and science.”$"
# 1250 "data/maps/RustboroCity/scripts.pory"

# 1251 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_TrainersSchoolSign:
# 1252 "data/maps/RustboroCity/scripts.pory"
	.string "POKéMON TRAINER'S SCHOOL\p"
# 1253 "data/maps/RustboroCity/scripts.pory"
	.string "“We'll teach you anything about\n"
# 1254 "data/maps/RustboroCity/scripts.pory"
	.string "POKéMON!”$"
# 1255 "data/maps/RustboroCity/scripts.pory"

# 1256 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_CuttersHouse:
# 1257 "data/maps/RustboroCity/scripts.pory"
	.string "CUTTER'S HOUSE$"
# 1258 "data/maps/RustboroCity/scripts.pory"

# 1259 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_DevelopedNewPokenavFeature:
# 1260 "data/maps/RustboroCity/scripts.pory"
	.string "I've been developing an added feature\n"
# 1261 "data/maps/RustboroCity/scripts.pory"
	.string "for the POKéNAV…\p"
# 1262 "data/maps/RustboroCity/scripts.pory"
	.string "And it turned out great!\p"
# 1263 "data/maps/RustboroCity/scripts.pory"
	.string "{PLAYER}, may I see that POKéNAV?\n"
# 1264 "data/maps/RustboroCity/scripts.pory"
	.string "The one our PRESIDENT gave you?$"
# 1265 "data/maps/RustboroCity/scripts.pory"

# 1266 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_AddedMatchCallPleaseCallMrStone:
# 1267 "data/maps/RustboroCity/scripts.pory"
	.string "There you go, {PLAYER}!\p"
# 1268 "data/maps/RustboroCity/scripts.pory"
	.string "I added a new feature named\n"
# 1269 "data/maps/RustboroCity/scripts.pory"
	.string "MATCH CALL to your POKéNAV.\p"
# 1270 "data/maps/RustboroCity/scripts.pory"
	.string "Using the MATCH CALL feature,\n"
# 1271 "data/maps/RustboroCity/scripts.pory"
	.string "you can chat with people who have\l"
# 1272 "data/maps/RustboroCity/scripts.pory"
	.string "been registered in your POKéNAV.\p"
# 1273 "data/maps/RustboroCity/scripts.pory"
	.string "{PLAYER}, our PRESIDENT STONE should\n"
# 1274 "data/maps/RustboroCity/scripts.pory"
	.string "be registered in your POKéNAV.\p"
# 1275 "data/maps/RustboroCity/scripts.pory"
	.string "Test it out.\n"
# 1276 "data/maps/RustboroCity/scripts.pory"
	.string "Please give our PRESIDENT a call.$"
# 1277 "data/maps/RustboroCity/scripts.pory"

# 1278 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_PleaseSelectPokenav:
# 1279 "data/maps/RustboroCity/scripts.pory"
	.string "Please select the POKéNAV.$"
# 1280 "data/maps/RustboroCity/scripts.pory"

# 1281 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_IdBetterGetBackToWork:
# 1282 "data/maps/RustboroCity/scripts.pory"
	.string "Okay, I'd better get back to work.\n"
# 1283 "data/maps/RustboroCity/scripts.pory"
	.string "Please take care, {PLAYER}!$"
# 1284 "data/maps/RustboroCity/scripts.pory"

# 1285 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_YouCanHave2On2Battle:
# 1286 "data/maps/RustboroCity/scripts.pory"
	.string "Did you know this?\p"
# 1287 "data/maps/RustboroCity/scripts.pory"
	.string "You can have a 2-on-2 battle even\n"
# 1288 "data/maps/RustboroCity/scripts.pory"
	.string "if you're not with another TRAINER.\p"
# 1289 "data/maps/RustboroCity/scripts.pory"
	.string "If you catch the eyes of two TRAINERS\n"
# 1290 "data/maps/RustboroCity/scripts.pory"
	.string "when you have two or more POKéMON,\l"
# 1291 "data/maps/RustboroCity/scripts.pory"
	.string "they'll both challenge you.\p"
# 1292 "data/maps/RustboroCity/scripts.pory"
	.string "Don't you think it'd be cool if you\n"
# 1293 "data/maps/RustboroCity/scripts.pory"
	.string "could beat two TRAINERS by yourself?$"
