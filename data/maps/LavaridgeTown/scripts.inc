# 1 "data/maps/LavaridgeTown/scripts.pory"

# 2 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_MapScripts::
# 3 "data/maps/LavaridgeTown/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, LavaridgeTown_OnTransition
# 4 "data/maps/LavaridgeTown/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, LavaridgeTown_OnFrame
# 5 "data/maps/LavaridgeTown/scripts.pory"
	.byte 0
# 6 "data/maps/LavaridgeTown/scripts.pory"

# 7 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_OnTransition:
# 8 "data/maps/LavaridgeTown/scripts.pory"
	setflag FLAG_VISITED_LAVARIDGE_TOWN
# 9 "data/maps/LavaridgeTown/scripts.pory"
	call_if_set FLAG_WHITEOUT_TO_LAVARIDGE, LavaridgeTown_EventScript_ClearLavaridgeWhiteOut
# 10 "data/maps/LavaridgeTown/scripts.pory"
	call_if_set FLAG_DEFEATED_EVIL_TEAM_MT_CHIMNEY, LavaridgeTown_EventScript_ShowMtChimneyTrainers
# 11 "data/maps/LavaridgeTown/scripts.pory"
	call Common_EventScript_SetupRivalGfxId
# 12 "data/maps/LavaridgeTown/scripts.pory"
	call Common_EventScript_SetupRivalOnBikeGfxId
# 13 "data/maps/LavaridgeTown/scripts.pory"
	call_if_eq VAR_LAVARIDGE_TOWN_STATE, 1, LavaridgeTown_EventScript_CheckSetRivalPos
# 14 "data/maps/LavaridgeTown/scripts.pory"
	call_if_eq VAR_LAVARIDGE_TOWN_STATE, 1, LavaridgeTown_EventScript_HideMapNamePopup
# 15 "data/maps/LavaridgeTown/scripts.pory"
	end
# 16 "data/maps/LavaridgeTown/scripts.pory"

# 17 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_EventScript_ClearLavaridgeWhiteOut::
# 18 "data/maps/LavaridgeTown/scripts.pory"
	clearflag FLAG_WHITEOUT_TO_LAVARIDGE
# 19 "data/maps/LavaridgeTown/scripts.pory"
	return
# 20 "data/maps/LavaridgeTown/scripts.pory"

# 21 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_EventScript_CheckSetRivalPos::
# 22 "data/maps/LavaridgeTown/scripts.pory"
	getplayerxy VAR_0x8004, VAR_0x8005
# 23 "data/maps/LavaridgeTown/scripts.pory"
	goto_if_eq VAR_0x8004, 9, LavaridgeTown_EventScript_SetRivalPos
# 24 "data/maps/LavaridgeTown/scripts.pory"
	return
# 25 "data/maps/LavaridgeTown/scripts.pory"

# 26 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_EventScript_SetRivalPos::
# 27 "data/maps/LavaridgeTown/scripts.pory"
	setobjectxyperm LOCALID_LAVARIDGE_RIVAL, 11, 9
# 28 "data/maps/LavaridgeTown/scripts.pory"
	setobjectxyperm LOCALID_LAVARIDGE_RIVAL_ON_BIKE, 9, 8
# 29 "data/maps/LavaridgeTown/scripts.pory"
	setobjectmovementtype LOCALID_LAVARIDGE_RIVAL_ON_BIKE, MOVEMENT_TYPE_FACE_UP
# 30 "data/maps/LavaridgeTown/scripts.pory"
	clearflag FLAG_HIDE_LAVARIDGE_TOWN_RIVAL
# 31 "data/maps/LavaridgeTown/scripts.pory"
	return
# 32 "data/maps/LavaridgeTown/scripts.pory"

# 33 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_EventScript_ShowMtChimneyTrainers::
# 34 "data/maps/LavaridgeTown/scripts.pory"
	clearflag FLAG_HIDE_MT_CHIMNEY_TRAINERS
# 35 "data/maps/LavaridgeTown/scripts.pory"
	return
# 36 "data/maps/LavaridgeTown/scripts.pory"

# 37 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_EventScript_HideMapNamePopup::
# 38 "data/maps/LavaridgeTown/scripts.pory"
	setflag FLAG_HIDE_MAP_NAME_POPUP
# 39 "data/maps/LavaridgeTown/scripts.pory"
	return
# 40 "data/maps/LavaridgeTown/scripts.pory"

# 41 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_OnFrame:
# 42 "data/maps/LavaridgeTown/scripts.pory"
	map_script_2 VAR_LAVARIDGE_TOWN_STATE, 1, LavaridgeTown_EventScript_RivalGiveGoGoggles
# 43 "data/maps/LavaridgeTown/scripts.pory"
	.2byte 0
# 44 "data/maps/LavaridgeTown/scripts.pory"

# 45 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_EventScript_RivalGiveGoGoggles::
# 46 "data/maps/LavaridgeTown/scripts.pory"
	lockall
# 47 "data/maps/LavaridgeTown/scripts.pory"
	getplayerxy VAR_0x8008, VAR_0x8009
# 48 "data/maps/LavaridgeTown/scripts.pory"
	call_if_eq VAR_0x8008, 9, LavaridgeTown_EventScript_RivalNoticePlayer
# 49 "data/maps/LavaridgeTown/scripts.pory"
	call_if_ne VAR_0x8008, 9, LavaridgeTown_EventScript_RivalExitHerbShop
# 50 "data/maps/LavaridgeTown/scripts.pory"
	delay 20
# 51 "data/maps/LavaridgeTown/scripts.pory"
	checkplayergender
# 52 "data/maps/LavaridgeTown/scripts.pory"
	call_if_eq VAR_RESULT, MALE, LavaridgeTown_EventScript_PlayMayMusic
# 53 "data/maps/LavaridgeTown/scripts.pory"
	call_if_eq VAR_RESULT, FEMALE, LavaridgeTown_EventScript_PlayBrendanMusic
# 54 "data/maps/LavaridgeTown/scripts.pory"
	call_if_eq VAR_0x8008, 9, LavaridgeTown_EventScript_RivalApproachPlayer1
# 55 "data/maps/LavaridgeTown/scripts.pory"
	call_if_ne VAR_0x8008, 9, LavaridgeTown_EventScript_RivalApproachPlayer2
# 56 "data/maps/LavaridgeTown/scripts.pory"
	checkplayergender
# 57 "data/maps/LavaridgeTown/scripts.pory"
	goto_if_eq VAR_RESULT, MALE, LavaridgeTown_EventScript_MayGiveGoGoggles
# 58 "data/maps/LavaridgeTown/scripts.pory"
	goto_if_eq VAR_RESULT, FEMALE, LavaridgeTown_EventScript_BrendanGiveGoGoggles
# 59 "data/maps/LavaridgeTown/scripts.pory"
	end
# 60 "data/maps/LavaridgeTown/scripts.pory"

# 61 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_EventScript_MayGiveGoGoggles::
# 62 "data/maps/LavaridgeTown/scripts.pory"
	msgbox LavaridgeTown_Text_MayNiceBadgesTakeThis, MSGBOX_DEFAULT
# 63 "data/maps/LavaridgeTown/scripts.pory"
	giveitem ITEM_GO_GOGGLES
# 64 "data/maps/LavaridgeTown/scripts.pory"
	setflag FLAG_RECEIVED_GO_GOGGLES
# 65 "data/maps/LavaridgeTown/scripts.pory"
	msgbox LavaridgeTown_Text_MayExplainGoGogglesChallengeDad, MSGBOX_DEFAULT
# 66 "data/maps/LavaridgeTown/scripts.pory"
	goto LavaridgeTown_EventScript_RivalExit
# 67 "data/maps/LavaridgeTown/scripts.pory"
	end
# 68 "data/maps/LavaridgeTown/scripts.pory"

# 69 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_EventScript_BrendanGiveGoGoggles::
# 70 "data/maps/LavaridgeTown/scripts.pory"
	msgbox LavaridgeTown_Text_BrendanNiceBadgesTakeThis, MSGBOX_DEFAULT
# 71 "data/maps/LavaridgeTown/scripts.pory"
	giveitem ITEM_GO_GOGGLES
# 72 "data/maps/LavaridgeTown/scripts.pory"
	setflag FLAG_RECEIVED_GO_GOGGLES
# 73 "data/maps/LavaridgeTown/scripts.pory"
	msgbox LavaridgeTown_Text_BrendanExplainGoGogglesChallengeDad, MSGBOX_DEFAULT
# 74 "data/maps/LavaridgeTown/scripts.pory"
	goto LavaridgeTown_EventScript_RivalExit
# 75 "data/maps/LavaridgeTown/scripts.pory"
	end
# 76 "data/maps/LavaridgeTown/scripts.pory"

# 77 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_EventScript_RivalExit::
# 78 "data/maps/LavaridgeTown/scripts.pory"
	closemessage
# 79 "data/maps/LavaridgeTown/scripts.pory"
	removeobject LOCALID_LAVARIDGE_RIVAL
# 80 "data/maps/LavaridgeTown/scripts.pory"
	addobject LOCALID_LAVARIDGE_RIVAL_ON_BIKE
# 81 "data/maps/LavaridgeTown/scripts.pory"
	delay 30
# 82 "data/maps/LavaridgeTown/scripts.pory"
	call_if_eq VAR_0x8008, 9, LavaridgeTown_EventScript_RivalExit1
# 83 "data/maps/LavaridgeTown/scripts.pory"
	call_if_ne VAR_0x8008, 9, LavaridgeTown_EventScript_RivalExit2
# 84 "data/maps/LavaridgeTown/scripts.pory"
	removeobject LOCALID_LAVARIDGE_RIVAL_ON_BIKE
# 85 "data/maps/LavaridgeTown/scripts.pory"
	setvar VAR_LAVARIDGE_TOWN_STATE, 2
# 86 "data/maps/LavaridgeTown/scripts.pory"
	clearflag FLAG_HIDE_MAP_NAME_POPUP
# 87 "data/maps/LavaridgeTown/scripts.pory"
	savebgm MUS_DUMMY
# 88 "data/maps/LavaridgeTown/scripts.pory"
	fadedefaultbgm
# 89 "data/maps/LavaridgeTown/scripts.pory"
	releaseall
# 90 "data/maps/LavaridgeTown/scripts.pory"
	end
# 91 "data/maps/LavaridgeTown/scripts.pory"

# 92 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_EventScript_PlayMayMusic::
# 93 "data/maps/LavaridgeTown/scripts.pory"
	playbgm MUS_ENCOUNTER_MAY, TRUE
# 94 "data/maps/LavaridgeTown/scripts.pory"
	return
# 95 "data/maps/LavaridgeTown/scripts.pory"

# 96 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_EventScript_PlayBrendanMusic::
# 97 "data/maps/LavaridgeTown/scripts.pory"
	playbgm MUS_ENCOUNTER_BRENDAN, TRUE
# 98 "data/maps/LavaridgeTown/scripts.pory"
	return
# 99 "data/maps/LavaridgeTown/scripts.pory"

# 100 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_EventScript_RivalNoticePlayer::
# 101 "data/maps/LavaridgeTown/scripts.pory"
	applymovement LOCALID_LAVARIDGE_RIVAL, Common_Movement_WalkInPlaceFasterUp
# 102 "data/maps/LavaridgeTown/scripts.pory"
	waitmovement 0
# 103 "data/maps/LavaridgeTown/scripts.pory"
	playse SE_PIN
# 104 "data/maps/LavaridgeTown/scripts.pory"
	applymovement LOCALID_LAVARIDGE_RIVAL, Common_Movement_ExclamationMark
# 105 "data/maps/LavaridgeTown/scripts.pory"
	waitmovement 0
# 106 "data/maps/LavaridgeTown/scripts.pory"
	applymovement LOCALID_LAVARIDGE_RIVAL, Common_Movement_Delay48
# 107 "data/maps/LavaridgeTown/scripts.pory"
	waitmovement 0
# 108 "data/maps/LavaridgeTown/scripts.pory"
	return
# 109 "data/maps/LavaridgeTown/scripts.pory"

# 110 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_EventScript_RivalExitHerbShop::
# 111 "data/maps/LavaridgeTown/scripts.pory"
	opendoor 12, 15
# 112 "data/maps/LavaridgeTown/scripts.pory"
	waitdooranim
# 113 "data/maps/LavaridgeTown/scripts.pory"
	addobject LOCALID_LAVARIDGE_RIVAL
# 114 "data/maps/LavaridgeTown/scripts.pory"
	applymovement LOCALID_LAVARIDGE_RIVAL, LavaridgeTown_Movement_RivalExitHerbShop
# 115 "data/maps/LavaridgeTown/scripts.pory"
	waitmovement 0
# 116 "data/maps/LavaridgeTown/scripts.pory"
	closedoor 12, 15
# 117 "data/maps/LavaridgeTown/scripts.pory"
	waitdooranim
# 118 "data/maps/LavaridgeTown/scripts.pory"
	applymovement LOCALID_LAVARIDGE_RIVAL, Common_Movement_WalkInPlaceFasterLeft
# 119 "data/maps/LavaridgeTown/scripts.pory"
	waitmovement 0
# 120 "data/maps/LavaridgeTown/scripts.pory"
	playse SE_PIN
# 121 "data/maps/LavaridgeTown/scripts.pory"
	applymovement LOCALID_LAVARIDGE_RIVAL, Common_Movement_ExclamationMark
# 122 "data/maps/LavaridgeTown/scripts.pory"
	waitmovement 0
# 123 "data/maps/LavaridgeTown/scripts.pory"
	applymovement LOCALID_LAVARIDGE_RIVAL, Common_Movement_Delay48
# 124 "data/maps/LavaridgeTown/scripts.pory"
	waitmovement 0
# 125 "data/maps/LavaridgeTown/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterRight
# 126 "data/maps/LavaridgeTown/scripts.pory"
	waitmovement 0
# 127 "data/maps/LavaridgeTown/scripts.pory"
	return
# 128 "data/maps/LavaridgeTown/scripts.pory"

# 129 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_EventScript_RivalApproachPlayer1::
# 130 "data/maps/LavaridgeTown/scripts.pory"
	applymovement LOCALID_LAVARIDGE_RIVAL, LavaridgeTown_Movement_RivalApproachPlayer1
# 131 "data/maps/LavaridgeTown/scripts.pory"
	waitmovement 0
# 132 "data/maps/LavaridgeTown/scripts.pory"
	return
# 133 "data/maps/LavaridgeTown/scripts.pory"

# 134 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_EventScript_RivalApproachPlayer2::
# 135 "data/maps/LavaridgeTown/scripts.pory"
	applymovement LOCALID_LAVARIDGE_RIVAL, LavaridgeTown_Movement_RivalApproachPlayer2
# 136 "data/maps/LavaridgeTown/scripts.pory"
	waitmovement 0
# 137 "data/maps/LavaridgeTown/scripts.pory"
	return
# 138 "data/maps/LavaridgeTown/scripts.pory"

# 139 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_EventScript_RivalExit1::
# 140 "data/maps/LavaridgeTown/scripts.pory"
	applymovement LOCALID_PLAYER, LavaridgeTown_Movement_PlayerWatchRivalExit
# 141 "data/maps/LavaridgeTown/scripts.pory"
	applymovement LOCALID_LAVARIDGE_RIVAL_ON_BIKE, LavaridgeTown_Movement_RivalExit1
# 142 "data/maps/LavaridgeTown/scripts.pory"
	waitmovement 0
# 143 "data/maps/LavaridgeTown/scripts.pory"
	return
# 144 "data/maps/LavaridgeTown/scripts.pory"

# 145 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_EventScript_RivalExit2::
# 146 "data/maps/LavaridgeTown/scripts.pory"
	applymovement LOCALID_LAVARIDGE_RIVAL_ON_BIKE, LavaridgeTown_Movement_RivalExit2
# 147 "data/maps/LavaridgeTown/scripts.pory"
	waitmovement 0
# 148 "data/maps/LavaridgeTown/scripts.pory"
	return
# 149 "data/maps/LavaridgeTown/scripts.pory"

# 150 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_Movement_RivalExit2:
# 151 "data/maps/LavaridgeTown/scripts.pory"
	walk_fast_right
# 152 "data/maps/LavaridgeTown/scripts.pory"
	walk_fast_right
# 153 "data/maps/LavaridgeTown/scripts.pory"
	walk_fast_right
# 154 "data/maps/LavaridgeTown/scripts.pory"
	walk_fast_up
# 155 "data/maps/LavaridgeTown/scripts.pory"
	walk_fast_up
# 156 "data/maps/LavaridgeTown/scripts.pory"
	walk_fast_up
# 157 "data/maps/LavaridgeTown/scripts.pory"
	walk_fast_up
# 158 "data/maps/LavaridgeTown/scripts.pory"
	walk_fast_up
# 159 "data/maps/LavaridgeTown/scripts.pory"
	walk_fast_up
# 160 "data/maps/LavaridgeTown/scripts.pory"
	walk_fast_up
# 161 "data/maps/LavaridgeTown/scripts.pory"
	step_end
# 162 "data/maps/LavaridgeTown/scripts.pory"

# 163 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_Movement_PlayerWatchRivalExit:
# 164 "data/maps/LavaridgeTown/scripts.pory"
	delay_16
# 165 "data/maps/LavaridgeTown/scripts.pory"
	delay_8
# 166 "data/maps/LavaridgeTown/scripts.pory"
	walk_in_place_faster_right
# 167 "data/maps/LavaridgeTown/scripts.pory"
	step_end
# 168 "data/maps/LavaridgeTown/scripts.pory"

# 169 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_Movement_RivalExit1:
# 170 "data/maps/LavaridgeTown/scripts.pory"
	walk_fast_down
# 171 "data/maps/LavaridgeTown/scripts.pory"
	walk_fast_right
# 172 "data/maps/LavaridgeTown/scripts.pory"
	walk_fast_right
# 173 "data/maps/LavaridgeTown/scripts.pory"
	walk_fast_right
# 174 "data/maps/LavaridgeTown/scripts.pory"
	walk_fast_right
# 175 "data/maps/LavaridgeTown/scripts.pory"
	walk_fast_right
# 176 "data/maps/LavaridgeTown/scripts.pory"
	walk_fast_right
# 177 "data/maps/LavaridgeTown/scripts.pory"
	walk_fast_right
# 178 "data/maps/LavaridgeTown/scripts.pory"
	walk_fast_right
# 179 "data/maps/LavaridgeTown/scripts.pory"
	step_end
# 180 "data/maps/LavaridgeTown/scripts.pory"

# 181 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_Movement_RivalApproachPlayer2:
# 182 "data/maps/LavaridgeTown/scripts.pory"
	walk_left
# 183 "data/maps/LavaridgeTown/scripts.pory"
	walk_left
# 184 "data/maps/LavaridgeTown/scripts.pory"
	walk_left
# 185 "data/maps/LavaridgeTown/scripts.pory"
	walk_left
# 186 "data/maps/LavaridgeTown/scripts.pory"
	walk_left
# 187 "data/maps/LavaridgeTown/scripts.pory"
	walk_left
# 188 "data/maps/LavaridgeTown/scripts.pory"
	step_end
# 189 "data/maps/LavaridgeTown/scripts.pory"

# 190 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_Movement_RivalApproachPlayer1:
# 191 "data/maps/LavaridgeTown/scripts.pory"
	walk_left
# 192 "data/maps/LavaridgeTown/scripts.pory"
	walk_left
# 193 "data/maps/LavaridgeTown/scripts.pory"
	walk_up
# 194 "data/maps/LavaridgeTown/scripts.pory"
	step_end
# 195 "data/maps/LavaridgeTown/scripts.pory"

# 196 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_Movement_RivalExitHerbShop:
# 197 "data/maps/LavaridgeTown/scripts.pory"
	walk_down
# 198 "data/maps/LavaridgeTown/scripts.pory"
	step_end
# 199 "data/maps/LavaridgeTown/scripts.pory"

# 200 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_EventScript_HotSpringsTrigger::
# 201 "data/maps/LavaridgeTown/scripts.pory"
	specialvar VAR_RESULT, GetPlayerFacingDirection
# 202 "data/maps/LavaridgeTown/scripts.pory"
	goto_if_eq VAR_RESULT, DIR_SOUTH, LavaridgeTown_EventScript_EnteredHotSprings
# 203 "data/maps/LavaridgeTown/scripts.pory"
	end
# 204 "data/maps/LavaridgeTown/scripts.pory"

# 205 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_EventScript_EnteredHotSprings::
# 206 "data/maps/LavaridgeTown/scripts.pory"
	incrementgamestat GAME_STAT_ENTERED_HOT_SPRINGS
# 207 "data/maps/LavaridgeTown/scripts.pory"
	end
# 208 "data/maps/LavaridgeTown/scripts.pory"

# 209 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_EventScript_ExpertM::
# 210 "data/maps/LavaridgeTown/scripts.pory"
	msgbox LavaridgeTown_Text_HotSpringsNeverRunDry, MSGBOX_NPC
# 211 "data/maps/LavaridgeTown/scripts.pory"
	end
# 212 "data/maps/LavaridgeTown/scripts.pory"

# 213 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_EventScript_OldMan::
# 214 "data/maps/LavaridgeTown/scripts.pory"
	msgbox LavaridgeTown_Text_PokemonNippedBackside, MSGBOX_SIGN
# 215 "data/maps/LavaridgeTown/scripts.pory"
	end
# 216 "data/maps/LavaridgeTown/scripts.pory"

# 217 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_EventScript_Twin::
# 218 "data/maps/LavaridgeTown/scripts.pory"
	msgbox LavaridgeTown_Text_BatheInHotSpringsEveryDay, MSGBOX_NPC
# 219 "data/maps/LavaridgeTown/scripts.pory"
	end
# 220 "data/maps/LavaridgeTown/scripts.pory"

# 221 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_EventScript_HotSpringsOldWoman1::
# 222 "data/maps/LavaridgeTown/scripts.pory"
	msgbox LavaridgeTown_Text_IfPokemonInHotSprings, MSGBOX_NPC
# 223 "data/maps/LavaridgeTown/scripts.pory"
	end
# 224 "data/maps/LavaridgeTown/scripts.pory"

# 225 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_EventScript_HotSpringsOldWoman2::
# 226 "data/maps/LavaridgeTown/scripts.pory"
	msgbox LavaridgeTown_Text_HotSpringsClaims, MSGBOX_NPC
# 227 "data/maps/LavaridgeTown/scripts.pory"
	end
# 228 "data/maps/LavaridgeTown/scripts.pory"

# 229 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_EventScript_ExpertF::
# 230 "data/maps/LavaridgeTown/scripts.pory"
	msgbox LavaridgeTown_Text_OhYouLikeHotSprings, MSGBOX_NPC
# 231 "data/maps/LavaridgeTown/scripts.pory"
	end
# 232 "data/maps/LavaridgeTown/scripts.pory"

# 233 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_EventScript_EggWoman::
# 234 "data/maps/LavaridgeTown/scripts.pory"
	lock
# 235 "data/maps/LavaridgeTown/scripts.pory"
	faceplayer
# 236 "data/maps/LavaridgeTown/scripts.pory"
	goto_if_set FLAG_RECEIVED_LAVARIDGE_EGG, LavaridgeTown_EventScript_ReceivedEgg
# 237 "data/maps/LavaridgeTown/scripts.pory"
	msgbox LavaridgeTown_Text_HaveEggWillYouTakeIt, MSGBOX_YESNO
# 238 "data/maps/LavaridgeTown/scripts.pory"
	goto_if_eq VAR_RESULT, NO, LavaridgeTown_EventScript_DeclineEgg
# 239 "data/maps/LavaridgeTown/scripts.pory"
	getpartysize
# 240 "data/maps/LavaridgeTown/scripts.pory"
	goto_if_eq VAR_RESULT, PARTY_SIZE, LavaridgeTown_EventScript_NoRoomForEgg
# 241 "data/maps/LavaridgeTown/scripts.pory"
	msgbox LavaridgeTown_Text_HopeYoullWalkPlentyWithEgg, MSGBOX_DEFAULT
# 242 "data/maps/LavaridgeTown/scripts.pory"
	setflag FLAG_RECEIVED_LAVARIDGE_EGG
# 243 "data/maps/LavaridgeTown/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 244 "data/maps/LavaridgeTown/scripts.pory"
	message LavaridgeTown_Text_ReceivedTheEgg
# 245 "data/maps/LavaridgeTown/scripts.pory"
	waitfanfare
# 246 "data/maps/LavaridgeTown/scripts.pory"
	giveegg SPECIES_WYNAUT
# 247 "data/maps/LavaridgeTown/scripts.pory"
	release
# 248 "data/maps/LavaridgeTown/scripts.pory"
	end
# 249 "data/maps/LavaridgeTown/scripts.pory"

# 250 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_EventScript_ReceivedEgg::
# 251 "data/maps/LavaridgeTown/scripts.pory"
	msgbox LavaridgeTown_Text_EverySoOftenEggFoundAtDayCare, MSGBOX_DEFAULT
# 252 "data/maps/LavaridgeTown/scripts.pory"
	release
# 253 "data/maps/LavaridgeTown/scripts.pory"
	end
# 254 "data/maps/LavaridgeTown/scripts.pory"

# 255 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_EventScript_NoRoomForEgg::
# 256 "data/maps/LavaridgeTown/scripts.pory"
	msgbox LavaridgeTown_Text_NoRoomForThisEgg, MSGBOX_DEFAULT
# 257 "data/maps/LavaridgeTown/scripts.pory"
	release
# 258 "data/maps/LavaridgeTown/scripts.pory"
	end
# 259 "data/maps/LavaridgeTown/scripts.pory"

# 260 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_EventScript_DeclineEgg::
# 261 "data/maps/LavaridgeTown/scripts.pory"
	msgbox LavaridgeTown_Text_AsYouWishThen, MSGBOX_DEFAULT
# 262 "data/maps/LavaridgeTown/scripts.pory"
	release
# 263 "data/maps/LavaridgeTown/scripts.pory"
	end
# 264 "data/maps/LavaridgeTown/scripts.pory"

# 265 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_EventScript_TownSign::
# 266 "data/maps/LavaridgeTown/scripts.pory"
	msgbox LavaridgeTown_Text_TownSign, MSGBOX_SIGN
# 267 "data/maps/LavaridgeTown/scripts.pory"
	end
# 268 "data/maps/LavaridgeTown/scripts.pory"

# 269 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_EventScript_GymSign::
# 270 "data/maps/LavaridgeTown/scripts.pory"
	msgbox LavaridgeTown_Text_GymSign, MSGBOX_SIGN
# 271 "data/maps/LavaridgeTown/scripts.pory"
	end
# 272 "data/maps/LavaridgeTown/scripts.pory"

# 273 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_EventScript_HerbShopSign::
# 274 "data/maps/LavaridgeTown/scripts.pory"
	msgbox LavaridgeTown_Text_HerbShopSign, MSGBOX_SIGN
# 275 "data/maps/LavaridgeTown/scripts.pory"
	end
# 276 "data/maps/LavaridgeTown/scripts.pory"

# 277 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_Text_MayNiceBadgesTakeThis:
# 278 "data/maps/LavaridgeTown/scripts.pory"
	.string "MAY: {PLAYER}{KUN}! Long time no see!\p"
# 279 "data/maps/LavaridgeTown/scripts.pory"
	.string "Oh? While I visited the hot springs,\n"
# 280 "data/maps/LavaridgeTown/scripts.pory"
	.string "you got the LAVARIDGE GYM BADGE.\p"
# 281 "data/maps/LavaridgeTown/scripts.pory"
	.string "You must have collected\n"
# 282 "data/maps/LavaridgeTown/scripts.pory"
	.string "good POKéMON…\l"
# 283 "data/maps/LavaridgeTown/scripts.pory"
	.string "No, I believe you raised some.\p"
# 284 "data/maps/LavaridgeTown/scripts.pory"
	.string "I guess it would be okay for you to\n"
# 285 "data/maps/LavaridgeTown/scripts.pory"
	.string "have this.$"
# 286 "data/maps/LavaridgeTown/scripts.pory"

# 287 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_Text_MayExplainGoGogglesChallengeDad:
# 288 "data/maps/LavaridgeTown/scripts.pory"
	.string "MAY: With those GO-GOGGLES, you'll\n"
# 289 "data/maps/LavaridgeTown/scripts.pory"
	.string "have no trouble getting through the\l"
# 290 "data/maps/LavaridgeTown/scripts.pory"
	.string "desert near ROUTE 111.\p"
# 291 "data/maps/LavaridgeTown/scripts.pory"
	.string "But, wow, {PLAYER}{KUN}…\n"
# 292 "data/maps/LavaridgeTown/scripts.pory"
	.string "Challenging GYMS…\p"
# 293 "data/maps/LavaridgeTown/scripts.pory"
	.string "You're trying hard because you don't\n"
# 294 "data/maps/LavaridgeTown/scripts.pory"
	.string "want to lose to me, I bet!\p"
# 295 "data/maps/LavaridgeTown/scripts.pory"
	.string "{PLAYER}{KUN}, I think I should challenge\n"
# 296 "data/maps/LavaridgeTown/scripts.pory"
	.string "your dad in PETALBURG GYM.\p"
# 297 "data/maps/LavaridgeTown/scripts.pory"
	.string "See you again!$"
# 298 "data/maps/LavaridgeTown/scripts.pory"

# 299 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_Text_BrendanNiceBadgesTakeThis:
# 300 "data/maps/LavaridgeTown/scripts.pory"
	.string "BRENDAN: {PLAYER}, hey, it's been a while.\n"
# 301 "data/maps/LavaridgeTown/scripts.pory"
	.string "How's it going?\p"
# 302 "data/maps/LavaridgeTown/scripts.pory"
	.string "Hmm…\n"
# 303 "data/maps/LavaridgeTown/scripts.pory"
	.string "That's a decent collection of BADGES.\p"
# 304 "data/maps/LavaridgeTown/scripts.pory"
	.string "All right, then.\n"
# 305 "data/maps/LavaridgeTown/scripts.pory"
	.string "You may as well have this.$"
# 306 "data/maps/LavaridgeTown/scripts.pory"

# 307 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_Text_BrendanExplainGoGogglesChallengeDad:
# 308 "data/maps/LavaridgeTown/scripts.pory"
	.string "BRENDAN: Keep those with you if you're\n"
# 309 "data/maps/LavaridgeTown/scripts.pory"
	.string "planning on going into that desert near\l"
# 310 "data/maps/LavaridgeTown/scripts.pory"
	.string "ROUTE 111.\p"
# 311 "data/maps/LavaridgeTown/scripts.pory"
	.string "There should be some POKéMON that\n"
# 312 "data/maps/LavaridgeTown/scripts.pory"
	.string "are exclusively desert-dwellers.\l"
# 313 "data/maps/LavaridgeTown/scripts.pory"
	.string "You might look around for those.\p"
# 314 "data/maps/LavaridgeTown/scripts.pory"
	.string "As for me…\n"
# 315 "data/maps/LavaridgeTown/scripts.pory"
	.string "I'm considering challenging NORMAN,\l"
# 316 "data/maps/LavaridgeTown/scripts.pory"
	.string "the GYM LEADER of PETALBURG.\p"
# 317 "data/maps/LavaridgeTown/scripts.pory"
	.string "Unlike you, {PLAYER}, your dad looks like\n"
# 318 "data/maps/LavaridgeTown/scripts.pory"
	.string "he really is tough.\p"
# 319 "data/maps/LavaridgeTown/scripts.pory"
	.string "See you around!$"
# 320 "data/maps/LavaridgeTown/scripts.pory"

# 321 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_Text_HaveEggWillYouTakeIt:
# 322 "data/maps/LavaridgeTown/scripts.pory"
	.string "I have here an EGG.\p"
# 323 "data/maps/LavaridgeTown/scripts.pory"
	.string "I'd hoped to hatch it by covering it in\n"
# 324 "data/maps/LavaridgeTown/scripts.pory"
	.string "hot sand by the hot springs.\l"
# 325 "data/maps/LavaridgeTown/scripts.pory"
	.string "But that doesn't seem to be enough…\p"
# 326 "data/maps/LavaridgeTown/scripts.pory"
	.string "I've heard it would be best if it were\n"
# 327 "data/maps/LavaridgeTown/scripts.pory"
	.string "kept together with POKéMON and\l"
# 328 "data/maps/LavaridgeTown/scripts.pory"
	.string "carried about.\p"
# 329 "data/maps/LavaridgeTown/scripts.pory"
	.string "You are a TRAINER, yes?\n"
# 330 "data/maps/LavaridgeTown/scripts.pory"
	.string "And your POKéMON radiate vitality.\p"
# 331 "data/maps/LavaridgeTown/scripts.pory"
	.string "So, what say you?\n"
# 332 "data/maps/LavaridgeTown/scripts.pory"
	.string "Will you take this EGG to hatch?$"
# 333 "data/maps/LavaridgeTown/scripts.pory"

# 334 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_Text_HopeYoullWalkPlentyWithEgg:
# 335 "data/maps/LavaridgeTown/scripts.pory"
	.string "Good! I hope you'll walk plenty with\n"
# 336 "data/maps/LavaridgeTown/scripts.pory"
	.string "this here EGG!$"
# 337 "data/maps/LavaridgeTown/scripts.pory"

# 338 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_Text_ReceivedTheEgg:
# 339 "data/maps/LavaridgeTown/scripts.pory"
	.string "{PLAYER} received the EGG.$"
# 340 "data/maps/LavaridgeTown/scripts.pory"

# 341 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_Text_NoRoomForThisEgg:
# 342 "data/maps/LavaridgeTown/scripts.pory"
	.string "Oh? You've too many POKéMON.\n"
# 343 "data/maps/LavaridgeTown/scripts.pory"
	.string "There's no room for this EGG…$"
# 344 "data/maps/LavaridgeTown/scripts.pory"

# 345 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_Text_AsYouWishThen:
# 346 "data/maps/LavaridgeTown/scripts.pory"
	.string "As you wish, then…\p"
# 347 "data/maps/LavaridgeTown/scripts.pory"
	.string "If you have a change of heart about\n"
# 348 "data/maps/LavaridgeTown/scripts.pory"
	.string "hatching this EGG, I will be here.$"
# 349 "data/maps/LavaridgeTown/scripts.pory"

# 350 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_Text_EverySoOftenEggFoundAtDayCare:
# 351 "data/maps/LavaridgeTown/scripts.pory"
	.string "Every so often, an EGG will be found at\n"
# 352 "data/maps/LavaridgeTown/scripts.pory"
	.string "the POKéMON DAY CARE.\p"
# 353 "data/maps/LavaridgeTown/scripts.pory"
	.string "Or at least that's how the rumor goes.$"
# 354 "data/maps/LavaridgeTown/scripts.pory"

# 355 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_Text_HotSpringsNeverRunDry:
# 356 "data/maps/LavaridgeTown/scripts.pory"
	.string "We draw as much hot water as we need,\n"
# 357 "data/maps/LavaridgeTown/scripts.pory"
	.string "and yet the hot springs never run dry.\p"
# 358 "data/maps/LavaridgeTown/scripts.pory"
	.string "Isn't it magical?\p"
# 359 "data/maps/LavaridgeTown/scripts.pory"
	.string "These hot springs appear near active\n"
# 360 "data/maps/LavaridgeTown/scripts.pory"
	.string "volcanoes. Veins of water under the\l"
# 361 "data/maps/LavaridgeTown/scripts.pory"
	.string "ground are heated by magma to well up\l"
# 362 "data/maps/LavaridgeTown/scripts.pory"
	.string "as hot springs.$"
# 363 "data/maps/LavaridgeTown/scripts.pory"

# 364 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_Text_PokemonNippedBackside:
# 365 "data/maps/LavaridgeTown/scripts.pory"
	.string "Being buried in this hot sand is…\n"
# 366 "data/maps/LavaridgeTown/scripts.pory"
	.string "Sigh…\p"
# 367 "data/maps/LavaridgeTown/scripts.pory"
	.string "So warm and heavenly…\p"
# 368 "data/maps/LavaridgeTown/scripts.pory"
	.string "Eh? Gyaah! Ouch!\p"
# 369 "data/maps/LavaridgeTown/scripts.pory"
	.string "A POKéMON nipped my backside!$"
# 370 "data/maps/LavaridgeTown/scripts.pory"

# 371 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_Text_OhYouLikeHotSprings:
# 372 "data/maps/LavaridgeTown/scripts.pory"
	.string "Oh, you like hot springs, do you?\p"
# 373 "data/maps/LavaridgeTown/scripts.pory"
	.string "That's surprising for one as young\n"
# 374 "data/maps/LavaridgeTown/scripts.pory"
	.string "as you.$"
# 375 "data/maps/LavaridgeTown/scripts.pory"

# 376 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_Text_BatheInHotSpringsEveryDay:
# 377 "data/maps/LavaridgeTown/scripts.pory"
	.string "I bathe in the hot springs every day.\p"
# 378 "data/maps/LavaridgeTown/scripts.pory"
	.string "I want to become a beautiful and strong\n"
# 379 "data/maps/LavaridgeTown/scripts.pory"
	.string "GYM LEADER like FLANNERY.$"
# 380 "data/maps/LavaridgeTown/scripts.pory"

# 381 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_Text_IfPokemonInHotSprings:
# 382 "data/maps/LavaridgeTown/scripts.pory"
	.string "If people put POKéMON in hot springs,\n"
# 383 "data/maps/LavaridgeTown/scripts.pory"
	.string "it might be seriously strange.\p"
# 384 "data/maps/LavaridgeTown/scripts.pory"
	.string "Why, it might be an electric bath, or\n"
# 385 "data/maps/LavaridgeTown/scripts.pory"
	.string "a bubble bath, or even a lava bath…$"
# 386 "data/maps/LavaridgeTown/scripts.pory"

# 387 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_Text_HotSpringsClaims:
# 388 "data/maps/LavaridgeTown/scripts.pory"
	.string "They're claiming that these hot springs\n"
# 389 "data/maps/LavaridgeTown/scripts.pory"
	.string "are good for calming nervous tension,\l"
# 390 "data/maps/LavaridgeTown/scripts.pory"
	.string "relieving aching muscles, solving\l"
# 391 "data/maps/LavaridgeTown/scripts.pory"
	.string "romantic problems, and attracting\l"
# 392 "data/maps/LavaridgeTown/scripts.pory"
	.string "money…$"
# 393 "data/maps/LavaridgeTown/scripts.pory"

# 394 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_Text_TownSign:
# 395 "data/maps/LavaridgeTown/scripts.pory"
	.string "LAVARIDGE TOWN\p"
# 396 "data/maps/LavaridgeTown/scripts.pory"
	.string "“POKéMON CENTER HOT SPRINGS\n"
# 397 "data/maps/LavaridgeTown/scripts.pory"
	.string "An excellent place for relaxing!”$"
# 398 "data/maps/LavaridgeTown/scripts.pory"

# 399 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_Text_GymSign:
# 400 "data/maps/LavaridgeTown/scripts.pory"
	.string "LAVARIDGE TOWN POKéMON GYM\n"
# 401 "data/maps/LavaridgeTown/scripts.pory"
	.string "LEADER: FLANNERY\l"
# 402 "data/maps/LavaridgeTown/scripts.pory"
	.string "“One with a fiery passion that burns!”$"
# 403 "data/maps/LavaridgeTown/scripts.pory"

# 404 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_Text_HerbShopSign:
# 405 "data/maps/LavaridgeTown/scripts.pory"
	.string "POKéMON HERB SHOP\n"
# 406 "data/maps/LavaridgeTown/scripts.pory"
	.string "“Bitter taste--better cure!”$"
