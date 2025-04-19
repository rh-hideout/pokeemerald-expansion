# 1 "data/maps/SlateportCity_Harbor/scripts.pory"

# 2 "data/maps/SlateportCity_Harbor/scripts.pory"
.set LOCALID_CAPT_STERN, 4
# 3 "data/maps/SlateportCity_Harbor/scripts.pory"
.set LOCALID_SS_TIDAL, 5
# 4 "data/maps/SlateportCity_Harbor/scripts.pory"
.set LOCALID_GRUNT, 6
# 5 "data/maps/SlateportCity_Harbor/scripts.pory"
.set LOCALID_ARCHIE, 7
# 6 "data/maps/SlateportCity_Harbor/scripts.pory"
.set LOCALID_SUBMARINE, 8
# 7 "data/maps/SlateportCity_Harbor/scripts.pory"

# 8 "data/maps/SlateportCity_Harbor/scripts.pory"
SlateportCity_Harbor_MapScripts::
# 9 "data/maps/SlateportCity_Harbor/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, SlateportCity_Harbor_OnTransition
# 10 "data/maps/SlateportCity_Harbor/scripts.pory"
	.byte 0
# 11 "data/maps/SlateportCity_Harbor/scripts.pory"

# 12 "data/maps/SlateportCity_Harbor/scripts.pory"
SlateportCity_Harbor_OnTransition:
# 13 "data/maps/SlateportCity_Harbor/scripts.pory"
	setescapewarp MAP_SLATEPORT_CITY, 28, 13
# 14 "data/maps/SlateportCity_Harbor/scripts.pory"
	setvar VAR_TEMP_1, 0
# 15 "data/maps/SlateportCity_Harbor/scripts.pory"
	call_if_eq VAR_SLATEPORT_HARBOR_STATE, 1, SlateportCity_Harbor_EventScript_ReadyAquaEscapeScene
# 16 "data/maps/SlateportCity_Harbor/scripts.pory"
	call_if_set FLAG_SYS_GAME_CLEAR, SlateportCity_Harbor_EventScript_ShowSSTidal
# 17 "data/maps/SlateportCity_Harbor/scripts.pory"
	end
# 18 "data/maps/SlateportCity_Harbor/scripts.pory"

# 19 "data/maps/SlateportCity_Harbor/scripts.pory"
SlateportCity_Harbor_EventScript_ShowSSTidal::
# 20 "data/maps/SlateportCity_Harbor/scripts.pory"
	clearflag FLAG_HIDE_SLATEPORT_CITY_HARBOR_SS_TIDAL
# 21 "data/maps/SlateportCity_Harbor/scripts.pory"
	return
# 22 "data/maps/SlateportCity_Harbor/scripts.pory"

# 23 "data/maps/SlateportCity_Harbor/scripts.pory"
SlateportCity_Harbor_EventScript_ReadyAquaEscapeScene::
# 24 "data/maps/SlateportCity_Harbor/scripts.pory"
	savebgm MUS_ENCOUNTER_AQUA
# 25 "data/maps/SlateportCity_Harbor/scripts.pory"
	setobjectxyperm LOCALID_CAPT_STERN, 12, 13
# 26 "data/maps/SlateportCity_Harbor/scripts.pory"
	setobjectmovementtype LOCALID_CAPT_STERN, MOVEMENT_TYPE_FACE_LEFT
# 27 "data/maps/SlateportCity_Harbor/scripts.pory"
	setflag FLAG_HIDE_SLATEPORT_CITY_HARBOR_PATRONS
# 28 "data/maps/SlateportCity_Harbor/scripts.pory"
	return
# 29 "data/maps/SlateportCity_Harbor/scripts.pory"

# 30 "data/maps/SlateportCity_Harbor/scripts.pory"
SlateportCity_Harbor_EventScript_AquaEscapeTrigger0::
# 31 "data/maps/SlateportCity_Harbor/scripts.pory"
	lockall
# 32 "data/maps/SlateportCity_Harbor/scripts.pory"
	setvar VAR_0x8008, 0
# 33 "data/maps/SlateportCity_Harbor/scripts.pory"
	goto SlateportCity_Harbor_EventScript_AquaEscapeScene
# 34 "data/maps/SlateportCity_Harbor/scripts.pory"
	end
# 35 "data/maps/SlateportCity_Harbor/scripts.pory"

# 36 "data/maps/SlateportCity_Harbor/scripts.pory"
SlateportCity_Harbor_EventScript_AquaEscapeTrigger1::
# 37 "data/maps/SlateportCity_Harbor/scripts.pory"
	lockall
# 38 "data/maps/SlateportCity_Harbor/scripts.pory"
	setvar VAR_0x8008, 1
# 39 "data/maps/SlateportCity_Harbor/scripts.pory"
	goto SlateportCity_Harbor_EventScript_AquaEscapeScene
# 40 "data/maps/SlateportCity_Harbor/scripts.pory"
	end
# 41 "data/maps/SlateportCity_Harbor/scripts.pory"

# 42 "data/maps/SlateportCity_Harbor/scripts.pory"
SlateportCity_Harbor_EventScript_AquaEscapeTrigger2::
# 43 "data/maps/SlateportCity_Harbor/scripts.pory"
	lockall
# 44 "data/maps/SlateportCity_Harbor/scripts.pory"
	setvar VAR_0x8008, 2
# 45 "data/maps/SlateportCity_Harbor/scripts.pory"
	goto SlateportCity_Harbor_EventScript_AquaEscapeScene
# 46 "data/maps/SlateportCity_Harbor/scripts.pory"
	end
# 47 "data/maps/SlateportCity_Harbor/scripts.pory"

# 48 "data/maps/SlateportCity_Harbor/scripts.pory"
SlateportCity_Harbor_EventScript_AquaEscapeTrigger3::
# 49 "data/maps/SlateportCity_Harbor/scripts.pory"
	lockall
# 50 "data/maps/SlateportCity_Harbor/scripts.pory"
	setvar VAR_0x8008, 3
# 51 "data/maps/SlateportCity_Harbor/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, SlateportCity_Harbor_Movement_PlayerWalkUp
# 52 "data/maps/SlateportCity_Harbor/scripts.pory"
	waitmovement 0
# 53 "data/maps/SlateportCity_Harbor/scripts.pory"
	goto SlateportCity_Harbor_EventScript_AquaEscapeScene
# 54 "data/maps/SlateportCity_Harbor/scripts.pory"
	end
# 55 "data/maps/SlateportCity_Harbor/scripts.pory"

# 56 "data/maps/SlateportCity_Harbor/scripts.pory"
SlateportCity_Harbor_EventScript_AquaEscapeScene::
# 57 "data/maps/SlateportCity_Harbor/scripts.pory"
	applymovement LOCALID_ARCHIE, Common_Movement_WalkInPlaceFasterDown
# 58 "data/maps/SlateportCity_Harbor/scripts.pory"
	waitmovement 0
# 59 "data/maps/SlateportCity_Harbor/scripts.pory"
	applymovement LOCALID_GRUNT, Common_Movement_WalkInPlaceFasterDown
# 60 "data/maps/SlateportCity_Harbor/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
# 61 "data/maps/SlateportCity_Harbor/scripts.pory"
	waitmovement 0
# 62 "data/maps/SlateportCity_Harbor/scripts.pory"
	msgbox SlateportCity_Harbor_Text_ArchieYouAgainHideoutInLilycove, MSGBOX_DEFAULT
# 63 "data/maps/SlateportCity_Harbor/scripts.pory"
	closemessage
# 64 "data/maps/SlateportCity_Harbor/scripts.pory"
	applymovement LOCALID_GRUNT, SlateportCity_Harbor_Movement_AquaBoardSub
# 65 "data/maps/SlateportCity_Harbor/scripts.pory"
	applymovement LOCALID_ARCHIE, SlateportCity_Harbor_Movement_AquaBoardSub
# 66 "data/maps/SlateportCity_Harbor/scripts.pory"
	applymovement LOCALID_SUBMARINE, SlateportCity_Harbor_Movement_SubmarineExit
# 67 "data/maps/SlateportCity_Harbor/scripts.pory"
	waitmovement 0
# 68 "data/maps/SlateportCity_Harbor/scripts.pory"
	removeobject LOCALID_GRUNT
# 69 "data/maps/SlateportCity_Harbor/scripts.pory"
	removeobject LOCALID_ARCHIE
# 70 "data/maps/SlateportCity_Harbor/scripts.pory"
	removeobject LOCALID_SUBMARINE
# 71 "data/maps/SlateportCity_Harbor/scripts.pory"
	setvar VAR_SLATEPORT_HARBOR_STATE, 2
# 72 "data/maps/SlateportCity_Harbor/scripts.pory"
	setflag FLAG_MET_TEAM_AQUA_HARBOR
# 73 "data/maps/SlateportCity_Harbor/scripts.pory"
	setflag FLAG_HIDE_LILYCOVE_MOTEL_SCOTT
# 74 "data/maps/SlateportCity_Harbor/scripts.pory"
	call_if_eq VAR_0x8008, 0, SlateportCity_Harbor_EventScript_SternApproachPlayer0
# 75 "data/maps/SlateportCity_Harbor/scripts.pory"
	call_if_eq VAR_0x8008, 1, SlateportCity_Harbor_EventScript_SternApproachPlayer1
# 76 "data/maps/SlateportCity_Harbor/scripts.pory"
	call_if_eq VAR_0x8008, 2, SlateportCity_Harbor_EventScript_SternApproachPlayer
# 77 "data/maps/SlateportCity_Harbor/scripts.pory"
	call_if_eq VAR_0x8008, 3, SlateportCity_Harbor_EventScript_SternApproachPlayer
# 78 "data/maps/SlateportCity_Harbor/scripts.pory"
	msgbox SlateportCity_Harbor_Text_CaptSternWhyStealMySubmarine, MSGBOX_DEFAULT
# 79 "data/maps/SlateportCity_Harbor/scripts.pory"
	closemessage
# 80 "data/maps/SlateportCity_Harbor/scripts.pory"
	setflag FLAG_HIDE_AQUA_HIDEOUT_1F_GRUNT_1_BLOCKING_ENTRANCE
# 81 "data/maps/SlateportCity_Harbor/scripts.pory"
	setflag FLAG_HIDE_AQUA_HIDEOUT_1F_GRUNT_2_BLOCKING_ENTRANCE
# 82 "data/maps/SlateportCity_Harbor/scripts.pory"
	copyobjectxytoperm LOCALID_CAPT_STERN
# 83 "data/maps/SlateportCity_Harbor/scripts.pory"
	setobjectmovementtype LOCALID_CAPT_STERN, MOVEMENT_TYPE_FACE_RIGHT
# 84 "data/maps/SlateportCity_Harbor/scripts.pory"
	releaseall
# 85 "data/maps/SlateportCity_Harbor/scripts.pory"
	end
# 86 "data/maps/SlateportCity_Harbor/scripts.pory"

# 87 "data/maps/SlateportCity_Harbor/scripts.pory"
SlateportCity_Harbor_EventScript_SternApproachPlayer0::
# 88 "data/maps/SlateportCity_Harbor/scripts.pory"
	applymovement LOCALID_CAPT_STERN, SlateportCity_Harbor_Movement_SternApproachPlayer0
# 89 "data/maps/SlateportCity_Harbor/scripts.pory"
	waitmovement 0
# 90 "data/maps/SlateportCity_Harbor/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterDown
# 91 "data/maps/SlateportCity_Harbor/scripts.pory"
	waitmovement 0
# 92 "data/maps/SlateportCity_Harbor/scripts.pory"
	return
# 93 "data/maps/SlateportCity_Harbor/scripts.pory"

# 94 "data/maps/SlateportCity_Harbor/scripts.pory"
SlateportCity_Harbor_EventScript_SternApproachPlayer1::
# 95 "data/maps/SlateportCity_Harbor/scripts.pory"
	applymovement LOCALID_CAPT_STERN, SlateportCity_Harbor_Movement_SternApproachPlayer1
# 96 "data/maps/SlateportCity_Harbor/scripts.pory"
	waitmovement 0
# 97 "data/maps/SlateportCity_Harbor/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterRight
# 98 "data/maps/SlateportCity_Harbor/scripts.pory"
	waitmovement 0
# 99 "data/maps/SlateportCity_Harbor/scripts.pory"
	return
# 100 "data/maps/SlateportCity_Harbor/scripts.pory"

# 101 "data/maps/SlateportCity_Harbor/scripts.pory"
SlateportCity_Harbor_EventScript_SternApproachPlayer::
# 102 "data/maps/SlateportCity_Harbor/scripts.pory"
	applymovement LOCALID_CAPT_STERN, SlateportCity_Harbor_Movement_SternApproachPlayer
# 103 "data/maps/SlateportCity_Harbor/scripts.pory"
	waitmovement 0
# 104 "data/maps/SlateportCity_Harbor/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterRight
# 105 "data/maps/SlateportCity_Harbor/scripts.pory"
	waitmovement 0
# 106 "data/maps/SlateportCity_Harbor/scripts.pory"
	return
# 107 "data/maps/SlateportCity_Harbor/scripts.pory"

# 108 "data/maps/SlateportCity_Harbor/scripts.pory"
SlateportCity_Harbor_Movement_AquaBoardSub:
# 109 "data/maps/SlateportCity_Harbor/scripts.pory"
	delay_16
# 110 "data/maps/SlateportCity_Harbor/scripts.pory"
	delay_16
# 111 "data/maps/SlateportCity_Harbor/scripts.pory"
	jump_up
# 112 "data/maps/SlateportCity_Harbor/scripts.pory"
	set_invisible
# 113 "data/maps/SlateportCity_Harbor/scripts.pory"
	step_end
# 114 "data/maps/SlateportCity_Harbor/scripts.pory"

# 115 "data/maps/SlateportCity_Harbor/scripts.pory"
@ Unused, Archie instead shares above identical movement script with Grunt
# 116 "data/maps/SlateportCity_Harbor/scripts.pory"
SlateportCity_Harbor_Movement_ArchieBoardSub:
# 117 "data/maps/SlateportCity_Harbor/scripts.pory"
	delay_16
# 118 "data/maps/SlateportCity_Harbor/scripts.pory"
	delay_16
# 119 "data/maps/SlateportCity_Harbor/scripts.pory"
	jump_up
# 120 "data/maps/SlateportCity_Harbor/scripts.pory"
	set_invisible
# 121 "data/maps/SlateportCity_Harbor/scripts.pory"
	step_end
# 122 "data/maps/SlateportCity_Harbor/scripts.pory"

# 123 "data/maps/SlateportCity_Harbor/scripts.pory"
SlateportCity_Harbor_Movement_SubmarineExit:
# 124 "data/maps/SlateportCity_Harbor/scripts.pory"
	delay_16
# 125 "data/maps/SlateportCity_Harbor/scripts.pory"
	delay_16
# 126 "data/maps/SlateportCity_Harbor/scripts.pory"
	delay_16
# 127 "data/maps/SlateportCity_Harbor/scripts.pory"
	delay_16
# 128 "data/maps/SlateportCity_Harbor/scripts.pory"
	walk_right
# 129 "data/maps/SlateportCity_Harbor/scripts.pory"
	walk_right
# 130 "data/maps/SlateportCity_Harbor/scripts.pory"
	walk_right
# 131 "data/maps/SlateportCity_Harbor/scripts.pory"
	walk_fast_right
# 132 "data/maps/SlateportCity_Harbor/scripts.pory"
	walk_fast_right
# 133 "data/maps/SlateportCity_Harbor/scripts.pory"
	walk_fast_right
# 134 "data/maps/SlateportCity_Harbor/scripts.pory"
	walk_fast_right
# 135 "data/maps/SlateportCity_Harbor/scripts.pory"
	walk_fast_right
# 136 "data/maps/SlateportCity_Harbor/scripts.pory"
	walk_fast_right
# 137 "data/maps/SlateportCity_Harbor/scripts.pory"
	step_end
# 138 "data/maps/SlateportCity_Harbor/scripts.pory"

# 139 "data/maps/SlateportCity_Harbor/scripts.pory"
SlateportCity_Harbor_Movement_SternApproachPlayer0:
# 140 "data/maps/SlateportCity_Harbor/scripts.pory"
	walk_left
# 141 "data/maps/SlateportCity_Harbor/scripts.pory"
	walk_left
# 142 "data/maps/SlateportCity_Harbor/scripts.pory"
	walk_left
# 143 "data/maps/SlateportCity_Harbor/scripts.pory"
	walk_left
# 144 "data/maps/SlateportCity_Harbor/scripts.pory"
	walk_up
# 145 "data/maps/SlateportCity_Harbor/scripts.pory"
	step_end
# 146 "data/maps/SlateportCity_Harbor/scripts.pory"

# 147 "data/maps/SlateportCity_Harbor/scripts.pory"
SlateportCity_Harbor_Movement_SternApproachPlayer1:
# 148 "data/maps/SlateportCity_Harbor/scripts.pory"
	walk_left
# 149 "data/maps/SlateportCity_Harbor/scripts.pory"
	walk_left
# 150 "data/maps/SlateportCity_Harbor/scripts.pory"
	walk_up
# 151 "data/maps/SlateportCity_Harbor/scripts.pory"
	walk_left
# 152 "data/maps/SlateportCity_Harbor/scripts.pory"
	step_end
# 153 "data/maps/SlateportCity_Harbor/scripts.pory"

# 154 "data/maps/SlateportCity_Harbor/scripts.pory"
SlateportCity_Harbor_Movement_SternApproachPlayer:
# 155 "data/maps/SlateportCity_Harbor/scripts.pory"
	walk_left
# 156 "data/maps/SlateportCity_Harbor/scripts.pory"
	walk_left
# 157 "data/maps/SlateportCity_Harbor/scripts.pory"
	walk_left
# 158 "data/maps/SlateportCity_Harbor/scripts.pory"
	step_end
# 159 "data/maps/SlateportCity_Harbor/scripts.pory"

# 160 "data/maps/SlateportCity_Harbor/scripts.pory"
SlateportCity_Harbor_Movement_PlayerWalkUp:
# 161 "data/maps/SlateportCity_Harbor/scripts.pory"
	walk_up
# 162 "data/maps/SlateportCity_Harbor/scripts.pory"
	step_end
# 163 "data/maps/SlateportCity_Harbor/scripts.pory"

# 164 "data/maps/SlateportCity_Harbor/scripts.pory"
SlateportCity_Harbor_EventScript_FerryAttendant::
# 165 "data/maps/SlateportCity_Harbor/scripts.pory"
	lock
# 166 "data/maps/SlateportCity_Harbor/scripts.pory"
	faceplayer
# 167 "data/maps/SlateportCity_Harbor/scripts.pory"
	goto_if_set FLAG_SYS_GAME_CLEAR, SlateportCity_Harbor_EventScript_AskForTicket
# 168 "data/maps/SlateportCity_Harbor/scripts.pory"
	msgbox SlateportCity_Harbor_Text_FerryServiceUnavailable, MSGBOX_DEFAULT
# 169 "data/maps/SlateportCity_Harbor/scripts.pory"
	release
# 170 "data/maps/SlateportCity_Harbor/scripts.pory"
	end
# 171 "data/maps/SlateportCity_Harbor/scripts.pory"

# 172 "data/maps/SlateportCity_Harbor/scripts.pory"
SlateportCity_Harbor_EventScript_AskForTicket::
# 173 "data/maps/SlateportCity_Harbor/scripts.pory"
	msgbox SlateportCity_Harbor_Text_MayISeeYourTicket, MSGBOX_DEFAULT
# 174 "data/maps/SlateportCity_Harbor/scripts.pory"
	message SlateportCity_Harbor_Text_FlashedTicketWhereTo
# 175 "data/maps/SlateportCity_Harbor/scripts.pory"
	waitmessage
# 176 "data/maps/SlateportCity_Harbor/scripts.pory"
	goto SlateportCity_Harbor_EventScript_ChooseDestination
# 177 "data/maps/SlateportCity_Harbor/scripts.pory"
	end
# 178 "data/maps/SlateportCity_Harbor/scripts.pory"

# 179 "data/maps/SlateportCity_Harbor/scripts.pory"
SlateportCity_Harbor_EventScript_ChooseDestination::
# 180 "data/maps/SlateportCity_Harbor/scripts.pory"
	goto_if_set FLAG_MET_SCOTT_ON_SS_TIDAL, SlateportCity_Harbor_EventScript_ChooseDestinationWithBattleFrontier
# 181 "data/maps/SlateportCity_Harbor/scripts.pory"
	multichoicedefault 18, 8, MULTI_SSTIDAL_SLATEPORT_NO_BF, 2, FALSE
# 182 "data/maps/SlateportCity_Harbor/scripts.pory"
	switch VAR_RESULT
# 183 "data/maps/SlateportCity_Harbor/scripts.pory"
	case 0, SlateportCity_Harbor_EventScript_Lilycove
# 184 "data/maps/SlateportCity_Harbor/scripts.pory"
	case 1, SlateportCity_Harbor_EventScript_CancelDestinationSelect
# 185 "data/maps/SlateportCity_Harbor/scripts.pory"
	case MULTI_B_PRESSED, SlateportCity_Harbor_EventScript_CancelDestinationSelect
# 186 "data/maps/SlateportCity_Harbor/scripts.pory"
	end
# 187 "data/maps/SlateportCity_Harbor/scripts.pory"

# 188 "data/maps/SlateportCity_Harbor/scripts.pory"
SlateportCity_Harbor_EventScript_ChooseDestinationWithBattleFrontier::
# 189 "data/maps/SlateportCity_Harbor/scripts.pory"
	multichoicedefault 17, 6, MULTI_SSTIDAL_SLATEPORT_WITH_BF, 2, FALSE
# 190 "data/maps/SlateportCity_Harbor/scripts.pory"
	switch VAR_RESULT
# 191 "data/maps/SlateportCity_Harbor/scripts.pory"
	case 0, SlateportCity_Harbor_EventScript_Lilycove
# 192 "data/maps/SlateportCity_Harbor/scripts.pory"
	case 1, SlateportCity_Harbor_EventScript_BattleFrontier
# 193 "data/maps/SlateportCity_Harbor/scripts.pory"
	case 2, SlateportCity_Harbor_EventScript_CancelDestinationSelect
# 194 "data/maps/SlateportCity_Harbor/scripts.pory"
	case MULTI_B_PRESSED, SlateportCity_Harbor_EventScript_CancelDestinationSelect
# 195 "data/maps/SlateportCity_Harbor/scripts.pory"
	end
# 196 "data/maps/SlateportCity_Harbor/scripts.pory"

# 197 "data/maps/SlateportCity_Harbor/scripts.pory"
@ Unused. Should be impossible for player to reach Ferry without having received SS Tidal ticket
# 198 "data/maps/SlateportCity_Harbor/scripts.pory"
SlateportCity_Harbor_EventScript_NoTicket::
# 199 "data/maps/SlateportCity_Harbor/scripts.pory"
	msgbox SlateportCity_Harbor_Text_YouMustHaveTicket, MSGBOX_DEFAULT
# 200 "data/maps/SlateportCity_Harbor/scripts.pory"
	release
# 201 "data/maps/SlateportCity_Harbor/scripts.pory"
	end
# 202 "data/maps/SlateportCity_Harbor/scripts.pory"

# 203 "data/maps/SlateportCity_Harbor/scripts.pory"
SlateportCity_Harbor_EventScript_Lilycove::
# 204 "data/maps/SlateportCity_Harbor/scripts.pory"
	msgbox SlateportCity_Harbor_Text_LilycoveItIs, MSGBOX_YESNO
# 205 "data/maps/SlateportCity_Harbor/scripts.pory"
	goto_if_eq VAR_RESULT, NO, SlateportCity_Harbor_EventScript_ChooseNewDestination
# 206 "data/maps/SlateportCity_Harbor/scripts.pory"
	setvar VAR_SS_TIDAL_STATE, SS_TIDAL_BOARD_SLATEPORT
# 207 "data/maps/SlateportCity_Harbor/scripts.pory"
	call SlateportCity_Harbor_EventScript_BoardFerry
# 208 "data/maps/SlateportCity_Harbor/scripts.pory"
	warp MAP_SS_TIDAL_CORRIDOR, 1, 10
# 209 "data/maps/SlateportCity_Harbor/scripts.pory"
	waitstate
# 210 "data/maps/SlateportCity_Harbor/scripts.pory"
	release
# 211 "data/maps/SlateportCity_Harbor/scripts.pory"
	end
# 212 "data/maps/SlateportCity_Harbor/scripts.pory"

# 213 "data/maps/SlateportCity_Harbor/scripts.pory"
SlateportCity_Harbor_EventScript_BattleFrontier::
# 214 "data/maps/SlateportCity_Harbor/scripts.pory"
	msgbox SlateportCity_Harbor_Text_BattleFrontierItIs, MSGBOX_YESNO
# 215 "data/maps/SlateportCity_Harbor/scripts.pory"
	goto_if_eq VAR_RESULT, NO, SlateportCity_Harbor_EventScript_ChooseNewDestination
# 216 "data/maps/SlateportCity_Harbor/scripts.pory"
	call SlateportCity_Harbor_EventScript_BoardFerry
# 217 "data/maps/SlateportCity_Harbor/scripts.pory"
	warp MAP_BATTLE_FRONTIER_OUTSIDE_WEST, 19, 67
# 218 "data/maps/SlateportCity_Harbor/scripts.pory"
	waitstate
# 219 "data/maps/SlateportCity_Harbor/scripts.pory"
	release
# 220 "data/maps/SlateportCity_Harbor/scripts.pory"
	end
# 221 "data/maps/SlateportCity_Harbor/scripts.pory"

# 222 "data/maps/SlateportCity_Harbor/scripts.pory"
SlateportCity_Harbor_EventScript_ChooseNewDestination::
# 223 "data/maps/SlateportCity_Harbor/scripts.pory"
	message SlateportCity_Harbor_Text_WhereWouldYouLikeToGo
# 224 "data/maps/SlateportCity_Harbor/scripts.pory"
	waitmessage
# 225 "data/maps/SlateportCity_Harbor/scripts.pory"
	goto SlateportCity_Harbor_EventScript_ChooseDestination
# 226 "data/maps/SlateportCity_Harbor/scripts.pory"
	end
# 227 "data/maps/SlateportCity_Harbor/scripts.pory"

# 228 "data/maps/SlateportCity_Harbor/scripts.pory"
SlateportCity_Harbor_EventScript_BoardFerry::
# 229 "data/maps/SlateportCity_Harbor/scripts.pory"
	msgbox SlateportCity_Harbor_Text_PleaseBoardFerry, MSGBOX_DEFAULT
# 230 "data/maps/SlateportCity_Harbor/scripts.pory"
	closemessage
# 231 "data/maps/SlateportCity_Harbor/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceFasterUp
# 232 "data/maps/SlateportCity_Harbor/scripts.pory"
	waitmovement 0
# 233 "data/maps/SlateportCity_Harbor/scripts.pory"
	delay 30
# 234 "data/maps/SlateportCity_Harbor/scripts.pory"
	hideobjectat VAR_LAST_TALKED, MAP_SLATEPORT_CITY_HARBOR
# 235 "data/maps/SlateportCity_Harbor/scripts.pory"
	call_if_eq VAR_FACING, DIR_NORTH, SlateportCity_Harbor_EventScript_BoardFerryNorth
# 236 "data/maps/SlateportCity_Harbor/scripts.pory"
	call_if_eq VAR_FACING, DIR_EAST, SlateportCity_Harbor_EventScript_BoardFerryEast
# 237 "data/maps/SlateportCity_Harbor/scripts.pory"
	delay 30
# 238 "data/maps/SlateportCity_Harbor/scripts.pory"
	hideobjectat OBJ_EVENT_ID_PLAYER, 0
# 239 "data/maps/SlateportCity_Harbor/scripts.pory"
	setvar VAR_0x8004, LOCALID_SS_TIDAL
# 240 "data/maps/SlateportCity_Harbor/scripts.pory"
	call Common_EventScript_FerryDepart
# 241 "data/maps/SlateportCity_Harbor/scripts.pory"
	return
# 242 "data/maps/SlateportCity_Harbor/scripts.pory"

# 243 "data/maps/SlateportCity_Harbor/scripts.pory"
SlateportCity_Harbor_EventScript_CancelDestinationSelect::
# 244 "data/maps/SlateportCity_Harbor/scripts.pory"
	msgbox SlateportCity_Harbor_Text_SailAnotherTime, MSGBOX_DEFAULT
# 245 "data/maps/SlateportCity_Harbor/scripts.pory"
	release
# 246 "data/maps/SlateportCity_Harbor/scripts.pory"
	end
# 247 "data/maps/SlateportCity_Harbor/scripts.pory"

# 248 "data/maps/SlateportCity_Harbor/scripts.pory"
SlateportCity_Harbor_EventScript_BoardFerryEast::
# 249 "data/maps/SlateportCity_Harbor/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, SlateportCity_Harbor_Movement_BoardFerryEast
# 250 "data/maps/SlateportCity_Harbor/scripts.pory"
	waitmovement 0
# 251 "data/maps/SlateportCity_Harbor/scripts.pory"
	return
# 252 "data/maps/SlateportCity_Harbor/scripts.pory"

# 253 "data/maps/SlateportCity_Harbor/scripts.pory"
SlateportCity_Harbor_EventScript_BoardFerryNorth::
# 254 "data/maps/SlateportCity_Harbor/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, SlateportCity_Harbor_Movement_BoardFerryNorth
# 255 "data/maps/SlateportCity_Harbor/scripts.pory"
	waitmovement 0
# 256 "data/maps/SlateportCity_Harbor/scripts.pory"
	return
# 257 "data/maps/SlateportCity_Harbor/scripts.pory"

# 258 "data/maps/SlateportCity_Harbor/scripts.pory"
SlateportCity_Harbor_Movement_BoardFerryEast:
# 259 "data/maps/SlateportCity_Harbor/scripts.pory"
	walk_right
# 260 "data/maps/SlateportCity_Harbor/scripts.pory"
	walk_in_place_faster_up
# 261 "data/maps/SlateportCity_Harbor/scripts.pory"
	step_end
# 262 "data/maps/SlateportCity_Harbor/scripts.pory"

# 263 "data/maps/SlateportCity_Harbor/scripts.pory"
SlateportCity_Harbor_Movement_BoardFerryNorth:
# 264 "data/maps/SlateportCity_Harbor/scripts.pory"
	walk_up
# 265 "data/maps/SlateportCity_Harbor/scripts.pory"
	step_end
# 266 "data/maps/SlateportCity_Harbor/scripts.pory"

# 267 "data/maps/SlateportCity_Harbor/scripts.pory"
SlateportCity_Harbor_EventScript_Sailor::
# 268 "data/maps/SlateportCity_Harbor/scripts.pory"
	lock
# 269 "data/maps/SlateportCity_Harbor/scripts.pory"
	faceplayer
# 270 "data/maps/SlateportCity_Harbor/scripts.pory"
	goto_if_unset FLAG_SYS_GAME_CLEAR, SlateportCity_Harbor_EventScript_SailorNoAbnormalWeather
# 271 "data/maps/SlateportCity_Harbor/scripts.pory"
	setvar VAR_0x8004, 0
# 272 "data/maps/SlateportCity_Harbor/scripts.pory"
	call_if_set FLAG_DEFEATED_KYOGRE, SlateportCity_Harbor_EventScript_CountDefeatedLegendary
# 273 "data/maps/SlateportCity_Harbor/scripts.pory"
	call_if_set FLAG_DEFEATED_GROUDON, SlateportCity_Harbor_EventScript_CountDefeatedLegendary
# 274 "data/maps/SlateportCity_Harbor/scripts.pory"
	goto_if_eq VAR_0x8004, 2, SlateportCity_Harbor_EventScript_SailorNoAbnormalWeather  @ Defeated both
# 275 "data/maps/SlateportCity_Harbor/scripts.pory"
	msgbox SlateportCity_Harbor_Text_AbnormalWeather, MSGBOX_DEFAULT
# 276 "data/maps/SlateportCity_Harbor/scripts.pory"
	release
# 277 "data/maps/SlateportCity_Harbor/scripts.pory"
	end
# 278 "data/maps/SlateportCity_Harbor/scripts.pory"

# 279 "data/maps/SlateportCity_Harbor/scripts.pory"
SlateportCity_Harbor_EventScript_SailorNoAbnormalWeather::
# 280 "data/maps/SlateportCity_Harbor/scripts.pory"
	msgbox SlateportCity_Harbor_Text_LoveToGoDeepUnderwaterSomeday, MSGBOX_DEFAULT
# 281 "data/maps/SlateportCity_Harbor/scripts.pory"
	release
# 282 "data/maps/SlateportCity_Harbor/scripts.pory"
	end
# 283 "data/maps/SlateportCity_Harbor/scripts.pory"

# 284 "data/maps/SlateportCity_Harbor/scripts.pory"
SlateportCity_Harbor_EventScript_CountDefeatedLegendary::
# 285 "data/maps/SlateportCity_Harbor/scripts.pory"
	addvar VAR_0x8004, 1
# 286 "data/maps/SlateportCity_Harbor/scripts.pory"
	return
# 287 "data/maps/SlateportCity_Harbor/scripts.pory"

# 288 "data/maps/SlateportCity_Harbor/scripts.pory"
SlateportCity_Harbor_EventScript_FatMan::
# 289 "data/maps/SlateportCity_Harbor/scripts.pory"
	msgbox SlateportCity_Harbor_Text_SubTooSmallForMe, MSGBOX_NPC
# 290 "data/maps/SlateportCity_Harbor/scripts.pory"
	end
# 291 "data/maps/SlateportCity_Harbor/scripts.pory"

# 292 "data/maps/SlateportCity_Harbor/scripts.pory"
SlateportCity_Harbor_EventScript_CaptStern::
# 293 "data/maps/SlateportCity_Harbor/scripts.pory"
	lock
# 294 "data/maps/SlateportCity_Harbor/scripts.pory"
	faceplayer
# 295 "data/maps/SlateportCity_Harbor/scripts.pory"
	goto_if_set FLAG_BADGE07_GET, SlateportCity_Harbor_EventScript_CaptSternFerryOrScannerComment
# 296 "data/maps/SlateportCity_Harbor/scripts.pory"
	goto_if_set FLAG_EVIL_TEAM_ESCAPED_STERN_SPOKE, SlateportCity_Harbor_EventScript_NeedDive
# 297 "data/maps/SlateportCity_Harbor/scripts.pory"
	goto_if_set FLAG_TEAM_AQUA_ESCAPED_IN_SUBMARINE, SlateportCity_Harbor_EventScript_TeamAquaLeftNeedDive
# 298 "data/maps/SlateportCity_Harbor/scripts.pory"
	goto_if_eq VAR_SLATEPORT_HARBOR_STATE, 2, SlateportCity_Harbor_EventScript_WhyStealSubmarine
# 299 "data/maps/SlateportCity_Harbor/scripts.pory"
	msgbox SlateportCity_Harbor_Text_SameThugsTriedToRobAtMuseum, MSGBOX_DEFAULT
# 300 "data/maps/SlateportCity_Harbor/scripts.pory"
	closemessage
# 301 "data/maps/SlateportCity_Harbor/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
# 302 "data/maps/SlateportCity_Harbor/scripts.pory"
	waitmovement 0
# 303 "data/maps/SlateportCity_Harbor/scripts.pory"
	release
# 304 "data/maps/SlateportCity_Harbor/scripts.pory"
	end
# 305 "data/maps/SlateportCity_Harbor/scripts.pory"

# 306 "data/maps/SlateportCity_Harbor/scripts.pory"
SlateportCity_Harbor_EventScript_WhyStealSubmarine::
# 307 "data/maps/SlateportCity_Harbor/scripts.pory"
	msgbox SlateportCity_Harbor_Text_CaptSternWhyStealMySubmarine, MSGBOX_DEFAULT
# 308 "data/maps/SlateportCity_Harbor/scripts.pory"
	release
# 309 "data/maps/SlateportCity_Harbor/scripts.pory"
	end
# 310 "data/maps/SlateportCity_Harbor/scripts.pory"

# 311 "data/maps/SlateportCity_Harbor/scripts.pory"
SlateportCity_Harbor_EventScript_TeamAquaLeftNeedDive::
# 312 "data/maps/SlateportCity_Harbor/scripts.pory"
	setflag FLAG_EVIL_TEAM_ESCAPED_STERN_SPOKE
# 313 "data/maps/SlateportCity_Harbor/scripts.pory"
	msgbox SlateportCity_Harbor_Text_TeamAquaLeftNeedDive, MSGBOX_DEFAULT
# 314 "data/maps/SlateportCity_Harbor/scripts.pory"
	release
# 315 "data/maps/SlateportCity_Harbor/scripts.pory"
	end
# 316 "data/maps/SlateportCity_Harbor/scripts.pory"

# 317 "data/maps/SlateportCity_Harbor/scripts.pory"
SlateportCity_Harbor_EventScript_NeedDive::
# 318 "data/maps/SlateportCity_Harbor/scripts.pory"
	msgbox SlateportCity_Harbor_Text_NeedDiveToCatchSub, MSGBOX_DEFAULT
# 319 "data/maps/SlateportCity_Harbor/scripts.pory"
	release
# 320 "data/maps/SlateportCity_Harbor/scripts.pory"
	end
# 321 "data/maps/SlateportCity_Harbor/scripts.pory"

# 322 "data/maps/SlateportCity_Harbor/scripts.pory"
SlateportCity_Harbor_EventScript_CaptSternFerryOrScannerComment::
# 323 "data/maps/SlateportCity_Harbor/scripts.pory"
	goto_if_eq VAR_TEMP_1, 1, SlateportCity_Harbor_EventScript_TradedScanner
# 324 "data/maps/SlateportCity_Harbor/scripts.pory"
	checkitem ITEM_SCANNER
# 325 "data/maps/SlateportCity_Harbor/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, SlateportCity_Harbor_EventScript_AskToTradeScanner
# 326 "data/maps/SlateportCity_Harbor/scripts.pory"
	goto_if_set FLAG_SYS_GAME_CLEAR, SlateportCity_Harbor_EventScript_FerryFinished
# 327 "data/maps/SlateportCity_Harbor/scripts.pory"
	msgbox SlateportCity_Harbor_Text_WontBeLongBeforeWeFinishFerry, MSGBOX_DEFAULT
# 328 "data/maps/SlateportCity_Harbor/scripts.pory"
	release
# 329 "data/maps/SlateportCity_Harbor/scripts.pory"
	end
# 330 "data/maps/SlateportCity_Harbor/scripts.pory"

# 331 "data/maps/SlateportCity_Harbor/scripts.pory"
SlateportCity_Harbor_EventScript_FerryFinished::
# 332 "data/maps/SlateportCity_Harbor/scripts.pory"
	msgbox SlateportCity_Harbor_Text_FinishedMakingFerry, MSGBOX_DEFAULT
# 333 "data/maps/SlateportCity_Harbor/scripts.pory"
	release
# 334 "data/maps/SlateportCity_Harbor/scripts.pory"
	end
# 335 "data/maps/SlateportCity_Harbor/scripts.pory"

# 336 "data/maps/SlateportCity_Harbor/scripts.pory"
SlateportCity_Harbor_EventScript_AskToTradeScanner::
# 337 "data/maps/SlateportCity_Harbor/scripts.pory"
	message SlateportCity_Harbor_Text_WouldYouTradeScanner
# 338 "data/maps/SlateportCity_Harbor/scripts.pory"
	waitmessage
# 339 "data/maps/SlateportCity_Harbor/scripts.pory"
	goto SlateportCity_Harbor_EventScript_ChooseScannerTrade
# 340 "data/maps/SlateportCity_Harbor/scripts.pory"
	end
# 341 "data/maps/SlateportCity_Harbor/scripts.pory"

# 342 "data/maps/SlateportCity_Harbor/scripts.pory"
SlateportCity_Harbor_EventScript_ChooseScannerTrade::
# 343 "data/maps/SlateportCity_Harbor/scripts.pory"
	multichoice 0, 0, MULTI_STERN_DEEPSEA, FALSE
# 344 "data/maps/SlateportCity_Harbor/scripts.pory"
	switch VAR_RESULT
# 345 "data/maps/SlateportCity_Harbor/scripts.pory"
	case 0, SlateportCity_Harbor_EventScript_DeepSeaTooth
# 346 "data/maps/SlateportCity_Harbor/scripts.pory"
	case 1, SlateportCity_Harbor_EventScript_DeepSeaScale
# 347 "data/maps/SlateportCity_Harbor/scripts.pory"
	case 2, SlateportCity_Harbor_EventScript_DeclineTrade
# 348 "data/maps/SlateportCity_Harbor/scripts.pory"
	case MULTI_B_PRESSED, SlateportCity_Harbor_EventScript_DeclineTrade
# 349 "data/maps/SlateportCity_Harbor/scripts.pory"
	end
# 350 "data/maps/SlateportCity_Harbor/scripts.pory"

# 351 "data/maps/SlateportCity_Harbor/scripts.pory"
SlateportCity_Harbor_EventScript_DeepSeaTooth::
# 352 "data/maps/SlateportCity_Harbor/scripts.pory"
	msgbox SlateportCity_Harbor_Text_TradeForDeepSeaTooth, MSGBOX_YESNO
# 353 "data/maps/SlateportCity_Harbor/scripts.pory"
	goto_if_eq VAR_RESULT, NO, SlateportCity_Harbor_EventScript_ChooseDifferentTrade
# 354 "data/maps/SlateportCity_Harbor/scripts.pory"
	giveitem ITEM_DEEP_SEA_TOOTH
# 355 "data/maps/SlateportCity_Harbor/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
# 356 "data/maps/SlateportCity_Harbor/scripts.pory"
	removeitem ITEM_SCANNER
# 357 "data/maps/SlateportCity_Harbor/scripts.pory"
	msgbox SlateportCity_Harbor_Text_HandedScannerToStern, MSGBOX_DEFAULT
# 358 "data/maps/SlateportCity_Harbor/scripts.pory"
	setflag FLAG_EXCHANGED_SCANNER
# 359 "data/maps/SlateportCity_Harbor/scripts.pory"
	goto SlateportCity_Harbor_EventScript_TradedScanner
# 360 "data/maps/SlateportCity_Harbor/scripts.pory"
	end
# 361 "data/maps/SlateportCity_Harbor/scripts.pory"

# 362 "data/maps/SlateportCity_Harbor/scripts.pory"
SlateportCity_Harbor_EventScript_DeepSeaScale::
# 363 "data/maps/SlateportCity_Harbor/scripts.pory"
	msgbox SlateportCity_Harbor_Text_TradeForDeepSeaScale, MSGBOX_YESNO
# 364 "data/maps/SlateportCity_Harbor/scripts.pory"
	goto_if_eq VAR_RESULT, NO, SlateportCity_Harbor_EventScript_ChooseDifferentTrade
# 365 "data/maps/SlateportCity_Harbor/scripts.pory"
	giveitem ITEM_DEEP_SEA_SCALE
# 366 "data/maps/SlateportCity_Harbor/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
# 367 "data/maps/SlateportCity_Harbor/scripts.pory"
	removeitem ITEM_SCANNER
# 368 "data/maps/SlateportCity_Harbor/scripts.pory"
	msgbox SlateportCity_Harbor_Text_HandedScannerToStern, MSGBOX_DEFAULT
# 369 "data/maps/SlateportCity_Harbor/scripts.pory"
	setflag FLAG_EXCHANGED_SCANNER
# 370 "data/maps/SlateportCity_Harbor/scripts.pory"
	goto SlateportCity_Harbor_EventScript_TradedScanner
# 371 "data/maps/SlateportCity_Harbor/scripts.pory"
	end
# 372 "data/maps/SlateportCity_Harbor/scripts.pory"

# 373 "data/maps/SlateportCity_Harbor/scripts.pory"
SlateportCity_Harbor_EventScript_DeclineTrade::
# 374 "data/maps/SlateportCity_Harbor/scripts.pory"
	msgbox SlateportCity_Harbor_Text_IfYouWantToTradeLetMeKnow, MSGBOX_DEFAULT
# 375 "data/maps/SlateportCity_Harbor/scripts.pory"
	release
# 376 "data/maps/SlateportCity_Harbor/scripts.pory"
	end
# 377 "data/maps/SlateportCity_Harbor/scripts.pory"

# 378 "data/maps/SlateportCity_Harbor/scripts.pory"
SlateportCity_Harbor_EventScript_ChooseDifferentTrade::
# 379 "data/maps/SlateportCity_Harbor/scripts.pory"
	message SlateportCity_Harbor_Text_WhichOneDoYouWant
# 380 "data/maps/SlateportCity_Harbor/scripts.pory"
	waitmessage
# 381 "data/maps/SlateportCity_Harbor/scripts.pory"
	goto SlateportCity_Harbor_EventScript_ChooseScannerTrade
# 382 "data/maps/SlateportCity_Harbor/scripts.pory"
	end
# 383 "data/maps/SlateportCity_Harbor/scripts.pory"

# 384 "data/maps/SlateportCity_Harbor/scripts.pory"
SlateportCity_Harbor_EventScript_TradedScanner::
# 385 "data/maps/SlateportCity_Harbor/scripts.pory"
	setvar VAR_TEMP_1, 1
# 386 "data/maps/SlateportCity_Harbor/scripts.pory"
	msgbox SlateportCity_Harbor_Text_ThisWillHelpResearch, MSGBOX_DEFAULT
# 387 "data/maps/SlateportCity_Harbor/scripts.pory"
	release
# 388 "data/maps/SlateportCity_Harbor/scripts.pory"
	end
# 389 "data/maps/SlateportCity_Harbor/scripts.pory"

# 390 "data/maps/SlateportCity_Harbor/scripts.pory"
SlateportCity_Harbor_Text_FerryServiceUnavailable:
# 391 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "I beg your pardon?\n"
# 392 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "You're looking for a ship?\p"
# 393 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "I'm sorry, the ferry service isn't\n"
# 394 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "available at present…$"
# 395 "data/maps/SlateportCity_Harbor/scripts.pory"

# 396 "data/maps/SlateportCity_Harbor/scripts.pory"
SlateportCity_Harbor_Text_MayISeeYourTicket:
# 397 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "Hello, are you here for the ferry?\n"
# 398 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "May I see your TICKET?$"
# 399 "data/maps/SlateportCity_Harbor/scripts.pory"

# 400 "data/maps/SlateportCity_Harbor/scripts.pory"
SlateportCity_Harbor_Text_YouMustHaveTicket:
# 401 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "{PLAYER} doesn't have the TICKET…\p"
# 402 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "I'm terribly sorry.\p"
# 403 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "You must have a TICKET to board\n"
# 404 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "the ferry.$"
# 405 "data/maps/SlateportCity_Harbor/scripts.pory"

# 406 "data/maps/SlateportCity_Harbor/scripts.pory"
SlateportCity_Harbor_Text_FlashedTicketWhereTo:
# 407 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "{PLAYER} flashed the TICKET.\p"
# 408 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "Perfect! That's all you need!\p"
# 409 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "And where would you like to go?$"
# 410 "data/maps/SlateportCity_Harbor/scripts.pory"

# 411 "data/maps/SlateportCity_Harbor/scripts.pory"
SlateportCity_Harbor_Text_SailAnotherTime:
# 412 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "Please sail with us another time!$"
# 413 "data/maps/SlateportCity_Harbor/scripts.pory"

# 414 "data/maps/SlateportCity_Harbor/scripts.pory"
SlateportCity_Harbor_Text_LilycoveItIs:
# 415 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "LILYCOVE CITY it is, then!$"
# 416 "data/maps/SlateportCity_Harbor/scripts.pory"

# 417 "data/maps/SlateportCity_Harbor/scripts.pory"
SlateportCity_Harbor_Text_BattleFrontierItIs:
# 418 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "BATTLE FRONTIER it is, then!$"
# 419 "data/maps/SlateportCity_Harbor/scripts.pory"

# 420 "data/maps/SlateportCity_Harbor/scripts.pory"
SlateportCity_Harbor_Text_PleaseBoardFerry:
# 421 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "Please board the ferry and wait for\n"
# 422 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "departure.$"
# 423 "data/maps/SlateportCity_Harbor/scripts.pory"

# 424 "data/maps/SlateportCity_Harbor/scripts.pory"
SlateportCity_Harbor_Text_WhereWouldYouLikeToGo:
# 425 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "Then, where would you like to go?$"
# 426 "data/maps/SlateportCity_Harbor/scripts.pory"

# 427 "data/maps/SlateportCity_Harbor/scripts.pory"
SlateportCity_Harbor_Text_LoveToGoDeepUnderwaterSomeday:
# 428 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "A journey to the bottom of the sea…\n"
# 429 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "I wonder what it'd be like?\p"
# 430 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "I'd love to go deep underwater like\n"
# 431 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "that someday.$"
# 432 "data/maps/SlateportCity_Harbor/scripts.pory"

# 433 "data/maps/SlateportCity_Harbor/scripts.pory"
SlateportCity_Harbor_Text_AbnormalWeather:
# 434 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "For a ship to sail safely, we need to\n"
# 435 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "know about the weather!\p"
# 436 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "Speaking of weather, I heard something\n"
# 437 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "from a guy at the WEATHER INSTITUTE.\p"
# 438 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "He was saying abnormal weather has\n"
# 439 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "been reported all over the place!\p"
# 440 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "You should visit the WEATHER INSTITUTE\n"
# 441 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "and ask around!$"
# 442 "data/maps/SlateportCity_Harbor/scripts.pory"

# 443 "data/maps/SlateportCity_Harbor/scripts.pory"
SlateportCity_Harbor_Text_SubTooSmallForMe:
# 444 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "I wanted to go with CAPT. STERN on\n"
# 445 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "the ocean floor exploration.\p"
# 446 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "But the sub's too small for me.\p"
# 447 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "If I squeezed in, there wouldn't be\n"
# 448 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "any room for the CAPTAIN…$"
# 449 "data/maps/SlateportCity_Harbor/scripts.pory"

# 450 "data/maps/SlateportCity_Harbor/scripts.pory"
SlateportCity_Harbor_Text_SameThugsTriedToRobAtMuseum:
# 451 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "CAPT. STERN: Those thugs…\p"
# 452 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "They're the same lot who tried to rob\n"
# 453 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "the DEVON GOODS at the MUSEUM.$"
# 454 "data/maps/SlateportCity_Harbor/scripts.pory"

# 455 "data/maps/SlateportCity_Harbor/scripts.pory"
SlateportCity_Harbor_Text_ArchieYouAgainHideoutInLilycove:
# 456 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "ARCHIE: Oh?\n"
# 457 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "Not you again…\p"
# 458 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "You are tenacious to track us here,\n"
# 459 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "that much I will give you.\p"
# 460 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "But now…\n"
# 461 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "No one can stop us! No one!\p"
# 462 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "Or, will you follow us back to our\n"
# 463 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "HIDEOUT in LILYCOVE CITY?\p"
# 464 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "Fwahahahaha…$"
# 465 "data/maps/SlateportCity_Harbor/scripts.pory"

# 466 "data/maps/SlateportCity_Harbor/scripts.pory"
SlateportCity_Harbor_Text_CaptSternWhyStealMySubmarine:
# 467 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "CAPT. STERN: Why…\p"
# 468 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "Why would TEAM AQUA steal my\n"
# 469 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "SUBMARINE EXPLORER 1?\p"
# 470 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "They can't be after the slumbering\n"
# 471 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "POKéMON at the bottom of the sea…\p"
# 472 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "But even if I were to chase them,\n"
# 473 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "I don't stand a chance against them…$"
# 474 "data/maps/SlateportCity_Harbor/scripts.pory"

# 475 "data/maps/SlateportCity_Harbor/scripts.pory"
SlateportCity_Harbor_Text_TeamAquaLeftNeedDive:
# 476 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "CAPT. STERN: Oh, {PLAYER}{KUN}…\p"
# 477 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "Okay… So TEAM AQUA left before you\n"
# 478 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "could stop them…\p"
# 479 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "Oh, no, don't blame yourself.\n"
# 480 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "You're not responsible for this.\p"
# 481 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "Trying to catch a submarine…\n"
# 482 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "It's impossible for most people.\p"
# 483 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "You would need a POKéMON that knows\n"
# 484 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "how to DIVE…\p"
# 485 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "Perhaps if you went out to\n"
# 486 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "MOSSDEEP CITY…\p"
# 487 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "A lot of divers live out there, so\n"
# 488 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "someone might teach you…$"
# 489 "data/maps/SlateportCity_Harbor/scripts.pory"

# 490 "data/maps/SlateportCity_Harbor/scripts.pory"
SlateportCity_Harbor_Text_NeedDiveToCatchSub:
# 491 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "CAPT. STERN: Trying to catch a\n"
# 492 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "submarine… It's impossible.\p"
# 493 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "You would need a POKéMON that knows\n"
# 494 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "how to DIVE…\p"
# 495 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "Perhaps if you went out to\n"
# 496 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "MOSSDEEP CITY…\p"
# 497 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "A lot of divers live out there, so\n"
# 498 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "someone might teach you…$"
# 499 "data/maps/SlateportCity_Harbor/scripts.pory"

# 500 "data/maps/SlateportCity_Harbor/scripts.pory"
SlateportCity_Harbor_Text_WontBeLongBeforeWeFinishFerry:
# 501 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "CAPT. STERN: Oh, yes.\n"
# 502 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "MR. BRINEY came to our SHIPYARD.\p"
# 503 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "It won't be long now before we finish\n"
# 504 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "making the ferry!$"
# 505 "data/maps/SlateportCity_Harbor/scripts.pory"

# 506 "data/maps/SlateportCity_Harbor/scripts.pory"
SlateportCity_Harbor_Text_FinishedMakingFerry:
# 507 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "CAPT. STERN: {PLAYER}{KUN}!\p"
# 508 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "We finally finished making the ferry\n"
# 509 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "S.S. TIDAL!\p"
# 510 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "We couldn't have done it without\n"
# 511 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "your friend MR. BRINEY.\p"
# 512 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "Please go for a short cruise on it!$"
# 513 "data/maps/SlateportCity_Harbor/scripts.pory"

# 514 "data/maps/SlateportCity_Harbor/scripts.pory"
SlateportCity_Harbor_Text_WouldYouTradeScanner:
# 515 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "CAPT. STERN: Oh?\n"
# 516 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "{PLAYER}{KUN}, that item you have…\p"
# 517 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "That's a SCANNER! That would sure\n"
# 518 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "help us on our explorations.\p"
# 519 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "{PLAYER}{KUN}, would you trade your\n"
# 520 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "SCANNER for something?\p"
# 521 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "Like, say, a DEEPSEATOOTH or\n"
# 522 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "a DEEPSEASCALE that I have?$"
# 523 "data/maps/SlateportCity_Harbor/scripts.pory"

# 524 "data/maps/SlateportCity_Harbor/scripts.pory"
SlateportCity_Harbor_Text_IfYouWantToTradeLetMeKnow:
# 525 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "CAPT. STERN: Are you certain?\n"
# 526 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "It's useless to you, {PLAYER}{KUN}…\p"
# 527 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "Well, okay, then. If you want to trade\n"
# 528 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "your SCANNER, let me know.$"
# 529 "data/maps/SlateportCity_Harbor/scripts.pory"

# 530 "data/maps/SlateportCity_Harbor/scripts.pory"
SlateportCity_Harbor_Text_TradeForDeepSeaTooth:
# 531 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "CAPT. STERN: So you'll trade it for\n"
# 532 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "my DEEPSEATOOTH?$"
# 533 "data/maps/SlateportCity_Harbor/scripts.pory"

# 534 "data/maps/SlateportCity_Harbor/scripts.pory"
SlateportCity_Harbor_Text_TradeForDeepSeaScale:
# 535 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "CAPT. STERN: So you'll trade it for\n"
# 536 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "my DEEPSEASCALE?$"
# 537 "data/maps/SlateportCity_Harbor/scripts.pory"

# 538 "data/maps/SlateportCity_Harbor/scripts.pory"
SlateportCity_Harbor_Text_WhichOneDoYouWant:
# 539 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "CAPT. STERN: Which one do you want?$"
# 540 "data/maps/SlateportCity_Harbor/scripts.pory"

# 541 "data/maps/SlateportCity_Harbor/scripts.pory"
SlateportCity_Harbor_Text_HandedScannerToStern:
# 542 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "{PLAYER} handed the SCANNER to\n"
# 543 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "CAPT. STERN.$"
# 544 "data/maps/SlateportCity_Harbor/scripts.pory"

# 545 "data/maps/SlateportCity_Harbor/scripts.pory"
SlateportCity_Harbor_Text_ThisWillHelpResearch:
# 546 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "CAPT. STERN: Thanks, {PLAYER}{KUN}!\n"
# 547 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "This will help our research a lot!$"
