# 1 "data/maps/SlateportCity_Harbor/scripts.pory"

# 2 "data/maps/SlateportCity_Harbor/scripts.pory"
SlateportCity_Harbor_MapScripts::
# 3 "data/maps/SlateportCity_Harbor/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, SlateportCity_Harbor_OnTransition
# 4 "data/maps/SlateportCity_Harbor/scripts.pory"
	.byte 0
# 5 "data/maps/SlateportCity_Harbor/scripts.pory"

# 6 "data/maps/SlateportCity_Harbor/scripts.pory"
SlateportCity_Harbor_OnTransition:
# 7 "data/maps/SlateportCity_Harbor/scripts.pory"
	setescapewarp MAP_SLATEPORT_CITY, 28, 13
# 8 "data/maps/SlateportCity_Harbor/scripts.pory"
	setvar VAR_TEMP_1, 0
# 9 "data/maps/SlateportCity_Harbor/scripts.pory"
	call_if_eq VAR_SLATEPORT_HARBOR_STATE, 1, SlateportCity_Harbor_EventScript_ReadyAquaEscapeScene
# 10 "data/maps/SlateportCity_Harbor/scripts.pory"
	call_if_set FLAG_SYS_GAME_CLEAR, SlateportCity_Harbor_EventScript_ShowSSTidal
# 11 "data/maps/SlateportCity_Harbor/scripts.pory"
	end
# 12 "data/maps/SlateportCity_Harbor/scripts.pory"

# 13 "data/maps/SlateportCity_Harbor/scripts.pory"
SlateportCity_Harbor_EventScript_ShowSSTidal::
# 14 "data/maps/SlateportCity_Harbor/scripts.pory"
	clearflag FLAG_HIDE_SLATEPORT_CITY_HARBOR_SS_TIDAL
# 15 "data/maps/SlateportCity_Harbor/scripts.pory"
	return
# 16 "data/maps/SlateportCity_Harbor/scripts.pory"

# 17 "data/maps/SlateportCity_Harbor/scripts.pory"
SlateportCity_Harbor_EventScript_ReadyAquaEscapeScene::
# 18 "data/maps/SlateportCity_Harbor/scripts.pory"
	savebgm MUS_ENCOUNTER_AQUA
# 19 "data/maps/SlateportCity_Harbor/scripts.pory"
	setobjectxyperm LOCALID_SLATEPORT_HARBOR_CAPT_STERN, 12, 13
# 20 "data/maps/SlateportCity_Harbor/scripts.pory"
	setobjectmovementtype LOCALID_SLATEPORT_HARBOR_CAPT_STERN, MOVEMENT_TYPE_FACE_LEFT
# 21 "data/maps/SlateportCity_Harbor/scripts.pory"
	setflag FLAG_HIDE_SLATEPORT_CITY_HARBOR_PATRONS
# 22 "data/maps/SlateportCity_Harbor/scripts.pory"
	return
# 23 "data/maps/SlateportCity_Harbor/scripts.pory"

# 24 "data/maps/SlateportCity_Harbor/scripts.pory"
SlateportCity_Harbor_EventScript_AquaEscapeTrigger0::
# 25 "data/maps/SlateportCity_Harbor/scripts.pory"
	lockall
# 26 "data/maps/SlateportCity_Harbor/scripts.pory"
	setvar VAR_0x8008, 0
# 27 "data/maps/SlateportCity_Harbor/scripts.pory"
	goto SlateportCity_Harbor_EventScript_AquaEscapeScene
# 28 "data/maps/SlateportCity_Harbor/scripts.pory"
	end
# 29 "data/maps/SlateportCity_Harbor/scripts.pory"

# 30 "data/maps/SlateportCity_Harbor/scripts.pory"
SlateportCity_Harbor_EventScript_AquaEscapeTrigger1::
# 31 "data/maps/SlateportCity_Harbor/scripts.pory"
	lockall
# 32 "data/maps/SlateportCity_Harbor/scripts.pory"
	setvar VAR_0x8008, 1
# 33 "data/maps/SlateportCity_Harbor/scripts.pory"
	goto SlateportCity_Harbor_EventScript_AquaEscapeScene
# 34 "data/maps/SlateportCity_Harbor/scripts.pory"
	end
# 35 "data/maps/SlateportCity_Harbor/scripts.pory"

# 36 "data/maps/SlateportCity_Harbor/scripts.pory"
SlateportCity_Harbor_EventScript_AquaEscapeTrigger2::
# 37 "data/maps/SlateportCity_Harbor/scripts.pory"
	lockall
# 38 "data/maps/SlateportCity_Harbor/scripts.pory"
	setvar VAR_0x8008, 2
# 39 "data/maps/SlateportCity_Harbor/scripts.pory"
	goto SlateportCity_Harbor_EventScript_AquaEscapeScene
# 40 "data/maps/SlateportCity_Harbor/scripts.pory"
	end
# 41 "data/maps/SlateportCity_Harbor/scripts.pory"

# 42 "data/maps/SlateportCity_Harbor/scripts.pory"
SlateportCity_Harbor_EventScript_AquaEscapeTrigger3::
# 43 "data/maps/SlateportCity_Harbor/scripts.pory"
	lockall
# 44 "data/maps/SlateportCity_Harbor/scripts.pory"
	setvar VAR_0x8008, 3
# 45 "data/maps/SlateportCity_Harbor/scripts.pory"
	applymovement LOCALID_PLAYER, SlateportCity_Harbor_Movement_PlayerWalkUp
# 46 "data/maps/SlateportCity_Harbor/scripts.pory"
	waitmovement 0
# 47 "data/maps/SlateportCity_Harbor/scripts.pory"
	goto SlateportCity_Harbor_EventScript_AquaEscapeScene
# 48 "data/maps/SlateportCity_Harbor/scripts.pory"
	end
# 49 "data/maps/SlateportCity_Harbor/scripts.pory"

# 50 "data/maps/SlateportCity_Harbor/scripts.pory"
SlateportCity_Harbor_EventScript_AquaEscapeScene::
# 51 "data/maps/SlateportCity_Harbor/scripts.pory"
	applymovement LOCALID_SLATEPORT_HARBOR_ARCHIE, Common_Movement_WalkInPlaceFasterDown
# 52 "data/maps/SlateportCity_Harbor/scripts.pory"
	waitmovement 0
# 53 "data/maps/SlateportCity_Harbor/scripts.pory"
	applymovement LOCALID_SLATEPORT_HARBOR_GRUNT, Common_Movement_WalkInPlaceFasterDown
# 54 "data/maps/SlateportCity_Harbor/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
# 55 "data/maps/SlateportCity_Harbor/scripts.pory"
	waitmovement 0
# 56 "data/maps/SlateportCity_Harbor/scripts.pory"
	msgbox SlateportCity_Harbor_Text_ArchieYouAgainHideoutInLilycove, MSGBOX_DEFAULT
# 57 "data/maps/SlateportCity_Harbor/scripts.pory"
	closemessage
# 58 "data/maps/SlateportCity_Harbor/scripts.pory"
	applymovement LOCALID_SLATEPORT_HARBOR_GRUNT, SlateportCity_Harbor_Movement_AquaBoardSub
# 59 "data/maps/SlateportCity_Harbor/scripts.pory"
	applymovement LOCALID_SLATEPORT_HARBOR_ARCHIE, SlateportCity_Harbor_Movement_AquaBoardSub
# 60 "data/maps/SlateportCity_Harbor/scripts.pory"
	applymovement LOCALID_SLATEPORT_HARBOR_SUBMARINE, SlateportCity_Harbor_Movement_SubmarineExit
# 61 "data/maps/SlateportCity_Harbor/scripts.pory"
	waitmovement 0
# 62 "data/maps/SlateportCity_Harbor/scripts.pory"
	removeobject LOCALID_SLATEPORT_HARBOR_GRUNT
# 63 "data/maps/SlateportCity_Harbor/scripts.pory"
	removeobject LOCALID_SLATEPORT_HARBOR_ARCHIE
# 64 "data/maps/SlateportCity_Harbor/scripts.pory"
	removeobject LOCALID_SLATEPORT_HARBOR_SUBMARINE
# 65 "data/maps/SlateportCity_Harbor/scripts.pory"
	setvar VAR_SLATEPORT_HARBOR_STATE, 2
# 66 "data/maps/SlateportCity_Harbor/scripts.pory"
	setflag FLAG_MET_TEAM_AQUA_HARBOR
# 67 "data/maps/SlateportCity_Harbor/scripts.pory"
	setflag FLAG_HIDE_LILYCOVE_MOTEL_SCOTT
# 68 "data/maps/SlateportCity_Harbor/scripts.pory"
	call_if_eq VAR_0x8008, 0, SlateportCity_Harbor_EventScript_SternApproachPlayer0
# 69 "data/maps/SlateportCity_Harbor/scripts.pory"
	call_if_eq VAR_0x8008, 1, SlateportCity_Harbor_EventScript_SternApproachPlayer1
# 70 "data/maps/SlateportCity_Harbor/scripts.pory"
	call_if_eq VAR_0x8008, 2, SlateportCity_Harbor_EventScript_SternApproachPlayer
# 71 "data/maps/SlateportCity_Harbor/scripts.pory"
	call_if_eq VAR_0x8008, 3, SlateportCity_Harbor_EventScript_SternApproachPlayer
# 72 "data/maps/SlateportCity_Harbor/scripts.pory"
	msgbox SlateportCity_Harbor_Text_CaptSternWhyStealMySubmarine, MSGBOX_DEFAULT
# 73 "data/maps/SlateportCity_Harbor/scripts.pory"
	closemessage
# 74 "data/maps/SlateportCity_Harbor/scripts.pory"
	setflag FLAG_HIDE_AQUA_HIDEOUT_1F_GRUNT_1_BLOCKING_ENTRANCE
# 75 "data/maps/SlateportCity_Harbor/scripts.pory"
	setflag FLAG_HIDE_AQUA_HIDEOUT_1F_GRUNT_2_BLOCKING_ENTRANCE
# 76 "data/maps/SlateportCity_Harbor/scripts.pory"
	copyobjectxytoperm LOCALID_SLATEPORT_HARBOR_CAPT_STERN
# 77 "data/maps/SlateportCity_Harbor/scripts.pory"
	setobjectmovementtype LOCALID_SLATEPORT_HARBOR_CAPT_STERN, MOVEMENT_TYPE_FACE_RIGHT
# 78 "data/maps/SlateportCity_Harbor/scripts.pory"
	releaseall
# 79 "data/maps/SlateportCity_Harbor/scripts.pory"
	end
# 80 "data/maps/SlateportCity_Harbor/scripts.pory"

# 81 "data/maps/SlateportCity_Harbor/scripts.pory"
SlateportCity_Harbor_EventScript_SternApproachPlayer0::
# 82 "data/maps/SlateportCity_Harbor/scripts.pory"
	applymovement LOCALID_SLATEPORT_HARBOR_CAPT_STERN, SlateportCity_Harbor_Movement_SternApproachPlayer0
# 83 "data/maps/SlateportCity_Harbor/scripts.pory"
	waitmovement 0
# 84 "data/maps/SlateportCity_Harbor/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterDown
# 85 "data/maps/SlateportCity_Harbor/scripts.pory"
	waitmovement 0
# 86 "data/maps/SlateportCity_Harbor/scripts.pory"
	return
# 87 "data/maps/SlateportCity_Harbor/scripts.pory"

# 88 "data/maps/SlateportCity_Harbor/scripts.pory"
SlateportCity_Harbor_EventScript_SternApproachPlayer1::
# 89 "data/maps/SlateportCity_Harbor/scripts.pory"
	applymovement LOCALID_SLATEPORT_HARBOR_CAPT_STERN, SlateportCity_Harbor_Movement_SternApproachPlayer1
# 90 "data/maps/SlateportCity_Harbor/scripts.pory"
	waitmovement 0
# 91 "data/maps/SlateportCity_Harbor/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterRight
# 92 "data/maps/SlateportCity_Harbor/scripts.pory"
	waitmovement 0
# 93 "data/maps/SlateportCity_Harbor/scripts.pory"
	return
# 94 "data/maps/SlateportCity_Harbor/scripts.pory"

# 95 "data/maps/SlateportCity_Harbor/scripts.pory"
SlateportCity_Harbor_EventScript_SternApproachPlayer::
# 96 "data/maps/SlateportCity_Harbor/scripts.pory"
	applymovement LOCALID_SLATEPORT_HARBOR_CAPT_STERN, SlateportCity_Harbor_Movement_SternApproachPlayer
# 97 "data/maps/SlateportCity_Harbor/scripts.pory"
	waitmovement 0
# 98 "data/maps/SlateportCity_Harbor/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterRight
# 99 "data/maps/SlateportCity_Harbor/scripts.pory"
	waitmovement 0
# 100 "data/maps/SlateportCity_Harbor/scripts.pory"
	return
# 101 "data/maps/SlateportCity_Harbor/scripts.pory"

# 102 "data/maps/SlateportCity_Harbor/scripts.pory"
SlateportCity_Harbor_Movement_AquaBoardSub:
# 103 "data/maps/SlateportCity_Harbor/scripts.pory"
	delay_16
# 104 "data/maps/SlateportCity_Harbor/scripts.pory"
	delay_16
# 105 "data/maps/SlateportCity_Harbor/scripts.pory"
	jump_up
# 106 "data/maps/SlateportCity_Harbor/scripts.pory"
	set_invisible
# 107 "data/maps/SlateportCity_Harbor/scripts.pory"
	step_end
# 108 "data/maps/SlateportCity_Harbor/scripts.pory"

# 109 "data/maps/SlateportCity_Harbor/scripts.pory"
@ Unused, Archie instead shares above identical movement script with Grunt
# 110 "data/maps/SlateportCity_Harbor/scripts.pory"
SlateportCity_Harbor_Movement_ArchieBoardSub:
# 111 "data/maps/SlateportCity_Harbor/scripts.pory"
	delay_16
# 112 "data/maps/SlateportCity_Harbor/scripts.pory"
	delay_16
# 113 "data/maps/SlateportCity_Harbor/scripts.pory"
	jump_up
# 114 "data/maps/SlateportCity_Harbor/scripts.pory"
	set_invisible
# 115 "data/maps/SlateportCity_Harbor/scripts.pory"
	step_end
# 116 "data/maps/SlateportCity_Harbor/scripts.pory"

# 117 "data/maps/SlateportCity_Harbor/scripts.pory"
SlateportCity_Harbor_Movement_SubmarineExit:
# 118 "data/maps/SlateportCity_Harbor/scripts.pory"
	delay_16
# 119 "data/maps/SlateportCity_Harbor/scripts.pory"
	delay_16
# 120 "data/maps/SlateportCity_Harbor/scripts.pory"
	delay_16
# 121 "data/maps/SlateportCity_Harbor/scripts.pory"
	delay_16
# 122 "data/maps/SlateportCity_Harbor/scripts.pory"
	walk_right
# 123 "data/maps/SlateportCity_Harbor/scripts.pory"
	walk_right
# 124 "data/maps/SlateportCity_Harbor/scripts.pory"
	walk_right
# 125 "data/maps/SlateportCity_Harbor/scripts.pory"
	walk_fast_right
# 126 "data/maps/SlateportCity_Harbor/scripts.pory"
	walk_fast_right
# 127 "data/maps/SlateportCity_Harbor/scripts.pory"
	walk_fast_right
# 128 "data/maps/SlateportCity_Harbor/scripts.pory"
	walk_fast_right
# 129 "data/maps/SlateportCity_Harbor/scripts.pory"
	walk_fast_right
# 130 "data/maps/SlateportCity_Harbor/scripts.pory"
	walk_fast_right
# 131 "data/maps/SlateportCity_Harbor/scripts.pory"
	step_end
# 132 "data/maps/SlateportCity_Harbor/scripts.pory"

# 133 "data/maps/SlateportCity_Harbor/scripts.pory"
SlateportCity_Harbor_Movement_SternApproachPlayer0:
# 134 "data/maps/SlateportCity_Harbor/scripts.pory"
	walk_left
# 135 "data/maps/SlateportCity_Harbor/scripts.pory"
	walk_left
# 136 "data/maps/SlateportCity_Harbor/scripts.pory"
	walk_left
# 137 "data/maps/SlateportCity_Harbor/scripts.pory"
	walk_left
# 138 "data/maps/SlateportCity_Harbor/scripts.pory"
	walk_up
# 139 "data/maps/SlateportCity_Harbor/scripts.pory"
	step_end
# 140 "data/maps/SlateportCity_Harbor/scripts.pory"

# 141 "data/maps/SlateportCity_Harbor/scripts.pory"
SlateportCity_Harbor_Movement_SternApproachPlayer1:
# 142 "data/maps/SlateportCity_Harbor/scripts.pory"
	walk_left
# 143 "data/maps/SlateportCity_Harbor/scripts.pory"
	walk_left
# 144 "data/maps/SlateportCity_Harbor/scripts.pory"
	walk_up
# 145 "data/maps/SlateportCity_Harbor/scripts.pory"
	walk_left
# 146 "data/maps/SlateportCity_Harbor/scripts.pory"
	step_end
# 147 "data/maps/SlateportCity_Harbor/scripts.pory"

# 148 "data/maps/SlateportCity_Harbor/scripts.pory"
SlateportCity_Harbor_Movement_SternApproachPlayer:
# 149 "data/maps/SlateportCity_Harbor/scripts.pory"
	walk_left
# 150 "data/maps/SlateportCity_Harbor/scripts.pory"
	walk_left
# 151 "data/maps/SlateportCity_Harbor/scripts.pory"
	walk_left
# 152 "data/maps/SlateportCity_Harbor/scripts.pory"
	step_end
# 153 "data/maps/SlateportCity_Harbor/scripts.pory"

# 154 "data/maps/SlateportCity_Harbor/scripts.pory"
SlateportCity_Harbor_Movement_PlayerWalkUp:
# 155 "data/maps/SlateportCity_Harbor/scripts.pory"
	walk_up
# 156 "data/maps/SlateportCity_Harbor/scripts.pory"
	step_end
# 157 "data/maps/SlateportCity_Harbor/scripts.pory"

# 158 "data/maps/SlateportCity_Harbor/scripts.pory"
SlateportCity_Harbor_EventScript_FerryAttendant::
# 159 "data/maps/SlateportCity_Harbor/scripts.pory"
	lock
# 160 "data/maps/SlateportCity_Harbor/scripts.pory"
	faceplayer
# 161 "data/maps/SlateportCity_Harbor/scripts.pory"
	goto_if_set FLAG_SYS_GAME_CLEAR, SlateportCity_Harbor_EventScript_AskForTicket
# 162 "data/maps/SlateportCity_Harbor/scripts.pory"
	msgbox SlateportCity_Harbor_Text_FerryServiceUnavailable, MSGBOX_DEFAULT
# 163 "data/maps/SlateportCity_Harbor/scripts.pory"
	release
# 164 "data/maps/SlateportCity_Harbor/scripts.pory"
	end
# 165 "data/maps/SlateportCity_Harbor/scripts.pory"

# 166 "data/maps/SlateportCity_Harbor/scripts.pory"
SlateportCity_Harbor_EventScript_AskForTicket::
# 167 "data/maps/SlateportCity_Harbor/scripts.pory"
	msgbox SlateportCity_Harbor_Text_MayISeeYourTicket, MSGBOX_DEFAULT
# 168 "data/maps/SlateportCity_Harbor/scripts.pory"
	message SlateportCity_Harbor_Text_FlashedTicketWhereTo
# 169 "data/maps/SlateportCity_Harbor/scripts.pory"
	waitmessage
# 170 "data/maps/SlateportCity_Harbor/scripts.pory"
	goto SlateportCity_Harbor_EventScript_ChooseDestination
# 171 "data/maps/SlateportCity_Harbor/scripts.pory"
	end
# 172 "data/maps/SlateportCity_Harbor/scripts.pory"

# 173 "data/maps/SlateportCity_Harbor/scripts.pory"
SlateportCity_Harbor_EventScript_ChooseDestination::
# 174 "data/maps/SlateportCity_Harbor/scripts.pory"
	goto_if_set FLAG_MET_SCOTT_ON_SS_TIDAL, SlateportCity_Harbor_EventScript_ChooseDestinationWithBattleFrontier
# 175 "data/maps/SlateportCity_Harbor/scripts.pory"
	multichoicedefault 18, 8, MULTI_SSTIDAL_SLATEPORT_NO_BF, 2, FALSE
# 176 "data/maps/SlateportCity_Harbor/scripts.pory"
	switch VAR_RESULT
# 177 "data/maps/SlateportCity_Harbor/scripts.pory"
	case 0, SlateportCity_Harbor_EventScript_Lilycove
# 178 "data/maps/SlateportCity_Harbor/scripts.pory"
	case 1, SlateportCity_Harbor_EventScript_CancelDestinationSelect
# 179 "data/maps/SlateportCity_Harbor/scripts.pory"
	case MULTI_B_PRESSED, SlateportCity_Harbor_EventScript_CancelDestinationSelect
# 180 "data/maps/SlateportCity_Harbor/scripts.pory"
	end
# 181 "data/maps/SlateportCity_Harbor/scripts.pory"

# 182 "data/maps/SlateportCity_Harbor/scripts.pory"
SlateportCity_Harbor_EventScript_ChooseDestinationWithBattleFrontier::
# 183 "data/maps/SlateportCity_Harbor/scripts.pory"
	multichoicedefault 17, 6, MULTI_SSTIDAL_SLATEPORT_WITH_BF, 2, FALSE
# 184 "data/maps/SlateportCity_Harbor/scripts.pory"
	switch VAR_RESULT
# 185 "data/maps/SlateportCity_Harbor/scripts.pory"
	case 0, SlateportCity_Harbor_EventScript_Lilycove
# 186 "data/maps/SlateportCity_Harbor/scripts.pory"
	case 1, SlateportCity_Harbor_EventScript_BattleFrontier
# 187 "data/maps/SlateportCity_Harbor/scripts.pory"
	case 2, SlateportCity_Harbor_EventScript_CancelDestinationSelect
# 188 "data/maps/SlateportCity_Harbor/scripts.pory"
	case MULTI_B_PRESSED, SlateportCity_Harbor_EventScript_CancelDestinationSelect
# 189 "data/maps/SlateportCity_Harbor/scripts.pory"
	end
# 190 "data/maps/SlateportCity_Harbor/scripts.pory"

# 191 "data/maps/SlateportCity_Harbor/scripts.pory"
@ Unused. Should be impossible for player to reach Ferry without having received SS Tidal ticket
# 192 "data/maps/SlateportCity_Harbor/scripts.pory"
SlateportCity_Harbor_EventScript_NoTicket::
# 193 "data/maps/SlateportCity_Harbor/scripts.pory"
	msgbox SlateportCity_Harbor_Text_YouMustHaveTicket, MSGBOX_DEFAULT
# 194 "data/maps/SlateportCity_Harbor/scripts.pory"
	release
# 195 "data/maps/SlateportCity_Harbor/scripts.pory"
	end
# 196 "data/maps/SlateportCity_Harbor/scripts.pory"

# 197 "data/maps/SlateportCity_Harbor/scripts.pory"
SlateportCity_Harbor_EventScript_Lilycove::
# 198 "data/maps/SlateportCity_Harbor/scripts.pory"
	msgbox SlateportCity_Harbor_Text_LilycoveItIs, MSGBOX_YESNO
# 199 "data/maps/SlateportCity_Harbor/scripts.pory"
	goto_if_eq VAR_RESULT, NO, SlateportCity_Harbor_EventScript_ChooseNewDestination
# 200 "data/maps/SlateportCity_Harbor/scripts.pory"
	setvar VAR_SS_TIDAL_STATE, SS_TIDAL_BOARD_SLATEPORT
# 201 "data/maps/SlateportCity_Harbor/scripts.pory"
	call SlateportCity_Harbor_EventScript_BoardFerry
# 202 "data/maps/SlateportCity_Harbor/scripts.pory"
	warp MAP_SS_TIDAL_CORRIDOR, 1, 10
# 203 "data/maps/SlateportCity_Harbor/scripts.pory"
	waitstate
# 204 "data/maps/SlateportCity_Harbor/scripts.pory"
	release
# 205 "data/maps/SlateportCity_Harbor/scripts.pory"
	end
# 206 "data/maps/SlateportCity_Harbor/scripts.pory"

# 207 "data/maps/SlateportCity_Harbor/scripts.pory"
SlateportCity_Harbor_EventScript_BattleFrontier::
# 208 "data/maps/SlateportCity_Harbor/scripts.pory"
	msgbox SlateportCity_Harbor_Text_BattleFrontierItIs, MSGBOX_YESNO
# 209 "data/maps/SlateportCity_Harbor/scripts.pory"
	goto_if_eq VAR_RESULT, NO, SlateportCity_Harbor_EventScript_ChooseNewDestination
# 210 "data/maps/SlateportCity_Harbor/scripts.pory"
	call SlateportCity_Harbor_EventScript_BoardFerry
# 211 "data/maps/SlateportCity_Harbor/scripts.pory"
	warp MAP_BATTLE_FRONTIER_OUTSIDE_WEST, 19, 67
# 212 "data/maps/SlateportCity_Harbor/scripts.pory"
	waitstate
# 213 "data/maps/SlateportCity_Harbor/scripts.pory"
	release
# 214 "data/maps/SlateportCity_Harbor/scripts.pory"
	end
# 215 "data/maps/SlateportCity_Harbor/scripts.pory"

# 216 "data/maps/SlateportCity_Harbor/scripts.pory"
SlateportCity_Harbor_EventScript_ChooseNewDestination::
# 217 "data/maps/SlateportCity_Harbor/scripts.pory"
	message SlateportCity_Harbor_Text_WhereWouldYouLikeToGo
# 218 "data/maps/SlateportCity_Harbor/scripts.pory"
	waitmessage
# 219 "data/maps/SlateportCity_Harbor/scripts.pory"
	goto SlateportCity_Harbor_EventScript_ChooseDestination
# 220 "data/maps/SlateportCity_Harbor/scripts.pory"
	end
# 221 "data/maps/SlateportCity_Harbor/scripts.pory"

# 222 "data/maps/SlateportCity_Harbor/scripts.pory"
SlateportCity_Harbor_EventScript_BoardFerry::
# 223 "data/maps/SlateportCity_Harbor/scripts.pory"
	msgbox SlateportCity_Harbor_Text_PleaseBoardFerry, MSGBOX_DEFAULT
# 224 "data/maps/SlateportCity_Harbor/scripts.pory"
	closemessage
# 225 "data/maps/SlateportCity_Harbor/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceFasterUp
# 226 "data/maps/SlateportCity_Harbor/scripts.pory"
	waitmovement 0
# 227 "data/maps/SlateportCity_Harbor/scripts.pory"
	delay 30
# 228 "data/maps/SlateportCity_Harbor/scripts.pory"
	hideobjectat VAR_LAST_TALKED, MAP_SLATEPORT_CITY_HARBOR
# 229 "data/maps/SlateportCity_Harbor/scripts.pory"
	call_if_eq VAR_FACING, DIR_NORTH, SlateportCity_Harbor_EventScript_BoardFerryNorth
# 230 "data/maps/SlateportCity_Harbor/scripts.pory"
	call_if_eq VAR_FACING, DIR_EAST, SlateportCity_Harbor_EventScript_BoardFerryEast
# 231 "data/maps/SlateportCity_Harbor/scripts.pory"
	delay 30
# 232 "data/maps/SlateportCity_Harbor/scripts.pory"
	hideobjectat LOCALID_PLAYER, 0
# 233 "data/maps/SlateportCity_Harbor/scripts.pory"
	setvar VAR_0x8004, LOCALID_SLATEPORT_HARBOR_SS_TIDAL
# 234 "data/maps/SlateportCity_Harbor/scripts.pory"
	call Common_EventScript_FerryDepart
# 235 "data/maps/SlateportCity_Harbor/scripts.pory"
	return
# 236 "data/maps/SlateportCity_Harbor/scripts.pory"

# 237 "data/maps/SlateportCity_Harbor/scripts.pory"
SlateportCity_Harbor_EventScript_CancelDestinationSelect::
# 238 "data/maps/SlateportCity_Harbor/scripts.pory"
	msgbox SlateportCity_Harbor_Text_SailAnotherTime, MSGBOX_DEFAULT
# 239 "data/maps/SlateportCity_Harbor/scripts.pory"
	release
# 240 "data/maps/SlateportCity_Harbor/scripts.pory"
	end
# 241 "data/maps/SlateportCity_Harbor/scripts.pory"

# 242 "data/maps/SlateportCity_Harbor/scripts.pory"
SlateportCity_Harbor_EventScript_BoardFerryEast::
# 243 "data/maps/SlateportCity_Harbor/scripts.pory"
	applymovement LOCALID_PLAYER, SlateportCity_Harbor_Movement_BoardFerryEast
# 244 "data/maps/SlateportCity_Harbor/scripts.pory"
	waitmovement 0
# 245 "data/maps/SlateportCity_Harbor/scripts.pory"
	return
# 246 "data/maps/SlateportCity_Harbor/scripts.pory"

# 247 "data/maps/SlateportCity_Harbor/scripts.pory"
SlateportCity_Harbor_EventScript_BoardFerryNorth::
# 248 "data/maps/SlateportCity_Harbor/scripts.pory"
	applymovement LOCALID_PLAYER, SlateportCity_Harbor_Movement_BoardFerryNorth
# 249 "data/maps/SlateportCity_Harbor/scripts.pory"
	waitmovement 0
# 250 "data/maps/SlateportCity_Harbor/scripts.pory"
	return
# 251 "data/maps/SlateportCity_Harbor/scripts.pory"

# 252 "data/maps/SlateportCity_Harbor/scripts.pory"
SlateportCity_Harbor_Movement_BoardFerryEast:
# 253 "data/maps/SlateportCity_Harbor/scripts.pory"
	walk_right
# 254 "data/maps/SlateportCity_Harbor/scripts.pory"
	walk_in_place_faster_up
# 255 "data/maps/SlateportCity_Harbor/scripts.pory"
	step_end
# 256 "data/maps/SlateportCity_Harbor/scripts.pory"

# 257 "data/maps/SlateportCity_Harbor/scripts.pory"
SlateportCity_Harbor_Movement_BoardFerryNorth:
# 258 "data/maps/SlateportCity_Harbor/scripts.pory"
	walk_up
# 259 "data/maps/SlateportCity_Harbor/scripts.pory"
	step_end
# 260 "data/maps/SlateportCity_Harbor/scripts.pory"

# 261 "data/maps/SlateportCity_Harbor/scripts.pory"
SlateportCity_Harbor_EventScript_Sailor::
# 262 "data/maps/SlateportCity_Harbor/scripts.pory"
	lock
# 263 "data/maps/SlateportCity_Harbor/scripts.pory"
	faceplayer
# 264 "data/maps/SlateportCity_Harbor/scripts.pory"
	goto_if_unset FLAG_SYS_GAME_CLEAR, SlateportCity_Harbor_EventScript_SailorNoAbnormalWeather
# 265 "data/maps/SlateportCity_Harbor/scripts.pory"
	setvar VAR_0x8004, 0
# 266 "data/maps/SlateportCity_Harbor/scripts.pory"
	call_if_set FLAG_DEFEATED_KYOGRE, SlateportCity_Harbor_EventScript_CountDefeatedLegendary
# 267 "data/maps/SlateportCity_Harbor/scripts.pory"
	call_if_set FLAG_DEFEATED_GROUDON, SlateportCity_Harbor_EventScript_CountDefeatedLegendary
# 268 "data/maps/SlateportCity_Harbor/scripts.pory"
	goto_if_eq VAR_0x8004, 2, SlateportCity_Harbor_EventScript_SailorNoAbnormalWeather  @ Defeated both
# 269 "data/maps/SlateportCity_Harbor/scripts.pory"
	msgbox SlateportCity_Harbor_Text_AbnormalWeather, MSGBOX_DEFAULT
# 270 "data/maps/SlateportCity_Harbor/scripts.pory"
	release
# 271 "data/maps/SlateportCity_Harbor/scripts.pory"
	end
# 272 "data/maps/SlateportCity_Harbor/scripts.pory"

# 273 "data/maps/SlateportCity_Harbor/scripts.pory"
SlateportCity_Harbor_EventScript_SailorNoAbnormalWeather::
# 274 "data/maps/SlateportCity_Harbor/scripts.pory"
	msgbox SlateportCity_Harbor_Text_LoveToGoDeepUnderwaterSomeday, MSGBOX_DEFAULT
# 275 "data/maps/SlateportCity_Harbor/scripts.pory"
	release
# 276 "data/maps/SlateportCity_Harbor/scripts.pory"
	end
# 277 "data/maps/SlateportCity_Harbor/scripts.pory"

# 278 "data/maps/SlateportCity_Harbor/scripts.pory"
SlateportCity_Harbor_EventScript_CountDefeatedLegendary::
# 279 "data/maps/SlateportCity_Harbor/scripts.pory"
	addvar VAR_0x8004, 1
# 280 "data/maps/SlateportCity_Harbor/scripts.pory"
	return
# 281 "data/maps/SlateportCity_Harbor/scripts.pory"

# 282 "data/maps/SlateportCity_Harbor/scripts.pory"
SlateportCity_Harbor_EventScript_FatMan::
# 283 "data/maps/SlateportCity_Harbor/scripts.pory"
	msgbox SlateportCity_Harbor_Text_SubTooSmallForMe, MSGBOX_NPC
# 284 "data/maps/SlateportCity_Harbor/scripts.pory"
	end
# 285 "data/maps/SlateportCity_Harbor/scripts.pory"

# 286 "data/maps/SlateportCity_Harbor/scripts.pory"
SlateportCity_Harbor_EventScript_CaptStern::
# 287 "data/maps/SlateportCity_Harbor/scripts.pory"
	lock
# 288 "data/maps/SlateportCity_Harbor/scripts.pory"
	faceplayer
# 289 "data/maps/SlateportCity_Harbor/scripts.pory"
	goto_if_set FLAG_BADGE07_GET, SlateportCity_Harbor_EventScript_CaptSternFerryOrScannerComment
# 290 "data/maps/SlateportCity_Harbor/scripts.pory"
	goto_if_set FLAG_EVIL_TEAM_ESCAPED_STERN_SPOKE, SlateportCity_Harbor_EventScript_NeedDive
# 291 "data/maps/SlateportCity_Harbor/scripts.pory"
	goto_if_set FLAG_TEAM_AQUA_ESCAPED_IN_SUBMARINE, SlateportCity_Harbor_EventScript_TeamAquaLeftNeedDive
# 292 "data/maps/SlateportCity_Harbor/scripts.pory"
	goto_if_eq VAR_SLATEPORT_HARBOR_STATE, 2, SlateportCity_Harbor_EventScript_WhyStealSubmarine
# 293 "data/maps/SlateportCity_Harbor/scripts.pory"
	msgbox SlateportCity_Harbor_Text_SameThugsTriedToRobAtMuseum, MSGBOX_DEFAULT
# 294 "data/maps/SlateportCity_Harbor/scripts.pory"
	closemessage
# 295 "data/maps/SlateportCity_Harbor/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
# 296 "data/maps/SlateportCity_Harbor/scripts.pory"
	waitmovement 0
# 297 "data/maps/SlateportCity_Harbor/scripts.pory"
	release
# 298 "data/maps/SlateportCity_Harbor/scripts.pory"
	end
# 299 "data/maps/SlateportCity_Harbor/scripts.pory"

# 300 "data/maps/SlateportCity_Harbor/scripts.pory"
SlateportCity_Harbor_EventScript_WhyStealSubmarine::
# 301 "data/maps/SlateportCity_Harbor/scripts.pory"
	msgbox SlateportCity_Harbor_Text_CaptSternWhyStealMySubmarine, MSGBOX_DEFAULT
# 302 "data/maps/SlateportCity_Harbor/scripts.pory"
	release
# 303 "data/maps/SlateportCity_Harbor/scripts.pory"
	end
# 304 "data/maps/SlateportCity_Harbor/scripts.pory"

# 305 "data/maps/SlateportCity_Harbor/scripts.pory"
SlateportCity_Harbor_EventScript_TeamAquaLeftNeedDive::
# 306 "data/maps/SlateportCity_Harbor/scripts.pory"
	setflag FLAG_EVIL_TEAM_ESCAPED_STERN_SPOKE
# 307 "data/maps/SlateportCity_Harbor/scripts.pory"
	msgbox SlateportCity_Harbor_Text_TeamAquaLeftNeedDive, MSGBOX_DEFAULT
# 308 "data/maps/SlateportCity_Harbor/scripts.pory"
	release
# 309 "data/maps/SlateportCity_Harbor/scripts.pory"
	end
# 310 "data/maps/SlateportCity_Harbor/scripts.pory"

# 311 "data/maps/SlateportCity_Harbor/scripts.pory"
SlateportCity_Harbor_EventScript_NeedDive::
# 312 "data/maps/SlateportCity_Harbor/scripts.pory"
	msgbox SlateportCity_Harbor_Text_NeedDiveToCatchSub, MSGBOX_DEFAULT
# 313 "data/maps/SlateportCity_Harbor/scripts.pory"
	release
# 314 "data/maps/SlateportCity_Harbor/scripts.pory"
	end
# 315 "data/maps/SlateportCity_Harbor/scripts.pory"

# 316 "data/maps/SlateportCity_Harbor/scripts.pory"
SlateportCity_Harbor_EventScript_CaptSternFerryOrScannerComment::
# 317 "data/maps/SlateportCity_Harbor/scripts.pory"
	goto_if_eq VAR_TEMP_1, 1, SlateportCity_Harbor_EventScript_TradedScanner
# 318 "data/maps/SlateportCity_Harbor/scripts.pory"
	checkitem ITEM_SCANNER
# 319 "data/maps/SlateportCity_Harbor/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, SlateportCity_Harbor_EventScript_AskToTradeScanner
# 320 "data/maps/SlateportCity_Harbor/scripts.pory"
	goto_if_set FLAG_SYS_GAME_CLEAR, SlateportCity_Harbor_EventScript_FerryFinished
# 321 "data/maps/SlateportCity_Harbor/scripts.pory"
	msgbox SlateportCity_Harbor_Text_WontBeLongBeforeWeFinishFerry, MSGBOX_DEFAULT
# 322 "data/maps/SlateportCity_Harbor/scripts.pory"
	release
# 323 "data/maps/SlateportCity_Harbor/scripts.pory"
	end
# 324 "data/maps/SlateportCity_Harbor/scripts.pory"

# 325 "data/maps/SlateportCity_Harbor/scripts.pory"
SlateportCity_Harbor_EventScript_FerryFinished::
# 326 "data/maps/SlateportCity_Harbor/scripts.pory"
	msgbox SlateportCity_Harbor_Text_FinishedMakingFerry, MSGBOX_DEFAULT
# 327 "data/maps/SlateportCity_Harbor/scripts.pory"
	release
# 328 "data/maps/SlateportCity_Harbor/scripts.pory"
	end
# 329 "data/maps/SlateportCity_Harbor/scripts.pory"

# 330 "data/maps/SlateportCity_Harbor/scripts.pory"
SlateportCity_Harbor_EventScript_AskToTradeScanner::
# 331 "data/maps/SlateportCity_Harbor/scripts.pory"
	message SlateportCity_Harbor_Text_WouldYouTradeScanner
# 332 "data/maps/SlateportCity_Harbor/scripts.pory"
	waitmessage
# 333 "data/maps/SlateportCity_Harbor/scripts.pory"
	goto SlateportCity_Harbor_EventScript_ChooseScannerTrade
# 334 "data/maps/SlateportCity_Harbor/scripts.pory"
	end
# 335 "data/maps/SlateportCity_Harbor/scripts.pory"

# 336 "data/maps/SlateportCity_Harbor/scripts.pory"
SlateportCity_Harbor_EventScript_ChooseScannerTrade::
# 337 "data/maps/SlateportCity_Harbor/scripts.pory"
	multichoice 0, 0, MULTI_STERN_DEEPSEA, FALSE
# 338 "data/maps/SlateportCity_Harbor/scripts.pory"
	switch VAR_RESULT
# 339 "data/maps/SlateportCity_Harbor/scripts.pory"
	case 0, SlateportCity_Harbor_EventScript_DeepSeaTooth
# 340 "data/maps/SlateportCity_Harbor/scripts.pory"
	case 1, SlateportCity_Harbor_EventScript_DeepSeaScale
# 341 "data/maps/SlateportCity_Harbor/scripts.pory"
	case 2, SlateportCity_Harbor_EventScript_DeclineTrade
# 342 "data/maps/SlateportCity_Harbor/scripts.pory"
	case MULTI_B_PRESSED, SlateportCity_Harbor_EventScript_DeclineTrade
# 343 "data/maps/SlateportCity_Harbor/scripts.pory"
	end
# 344 "data/maps/SlateportCity_Harbor/scripts.pory"

# 345 "data/maps/SlateportCity_Harbor/scripts.pory"
SlateportCity_Harbor_EventScript_DeepSeaTooth::
# 346 "data/maps/SlateportCity_Harbor/scripts.pory"
	msgbox SlateportCity_Harbor_Text_TradeForDeepSeaTooth, MSGBOX_YESNO
# 347 "data/maps/SlateportCity_Harbor/scripts.pory"
	goto_if_eq VAR_RESULT, NO, SlateportCity_Harbor_EventScript_ChooseDifferentTrade
# 348 "data/maps/SlateportCity_Harbor/scripts.pory"
	giveitem ITEM_DEEP_SEA_TOOTH
# 349 "data/maps/SlateportCity_Harbor/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
# 350 "data/maps/SlateportCity_Harbor/scripts.pory"
	removeitem ITEM_SCANNER
# 351 "data/maps/SlateportCity_Harbor/scripts.pory"
	msgbox SlateportCity_Harbor_Text_HandedScannerToStern, MSGBOX_DEFAULT
# 352 "data/maps/SlateportCity_Harbor/scripts.pory"
	setflag FLAG_EXCHANGED_SCANNER
# 353 "data/maps/SlateportCity_Harbor/scripts.pory"
	goto SlateportCity_Harbor_EventScript_TradedScanner
# 354 "data/maps/SlateportCity_Harbor/scripts.pory"
	end
# 355 "data/maps/SlateportCity_Harbor/scripts.pory"

# 356 "data/maps/SlateportCity_Harbor/scripts.pory"
SlateportCity_Harbor_EventScript_DeepSeaScale::
# 357 "data/maps/SlateportCity_Harbor/scripts.pory"
	msgbox SlateportCity_Harbor_Text_TradeForDeepSeaScale, MSGBOX_YESNO
# 358 "data/maps/SlateportCity_Harbor/scripts.pory"
	goto_if_eq VAR_RESULT, NO, SlateportCity_Harbor_EventScript_ChooseDifferentTrade
# 359 "data/maps/SlateportCity_Harbor/scripts.pory"
	giveitem ITEM_DEEP_SEA_SCALE
# 360 "data/maps/SlateportCity_Harbor/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
# 361 "data/maps/SlateportCity_Harbor/scripts.pory"
	removeitem ITEM_SCANNER
# 362 "data/maps/SlateportCity_Harbor/scripts.pory"
	msgbox SlateportCity_Harbor_Text_HandedScannerToStern, MSGBOX_DEFAULT
# 363 "data/maps/SlateportCity_Harbor/scripts.pory"
	setflag FLAG_EXCHANGED_SCANNER
# 364 "data/maps/SlateportCity_Harbor/scripts.pory"
	goto SlateportCity_Harbor_EventScript_TradedScanner
# 365 "data/maps/SlateportCity_Harbor/scripts.pory"
	end
# 366 "data/maps/SlateportCity_Harbor/scripts.pory"

# 367 "data/maps/SlateportCity_Harbor/scripts.pory"
SlateportCity_Harbor_EventScript_DeclineTrade::
# 368 "data/maps/SlateportCity_Harbor/scripts.pory"
	msgbox SlateportCity_Harbor_Text_IfYouWantToTradeLetMeKnow, MSGBOX_DEFAULT
# 369 "data/maps/SlateportCity_Harbor/scripts.pory"
	release
# 370 "data/maps/SlateportCity_Harbor/scripts.pory"
	end
# 371 "data/maps/SlateportCity_Harbor/scripts.pory"

# 372 "data/maps/SlateportCity_Harbor/scripts.pory"
SlateportCity_Harbor_EventScript_ChooseDifferentTrade::
# 373 "data/maps/SlateportCity_Harbor/scripts.pory"
	message SlateportCity_Harbor_Text_WhichOneDoYouWant
# 374 "data/maps/SlateportCity_Harbor/scripts.pory"
	waitmessage
# 375 "data/maps/SlateportCity_Harbor/scripts.pory"
	goto SlateportCity_Harbor_EventScript_ChooseScannerTrade
# 376 "data/maps/SlateportCity_Harbor/scripts.pory"
	end
# 377 "data/maps/SlateportCity_Harbor/scripts.pory"

# 378 "data/maps/SlateportCity_Harbor/scripts.pory"
SlateportCity_Harbor_EventScript_TradedScanner::
# 379 "data/maps/SlateportCity_Harbor/scripts.pory"
	setvar VAR_TEMP_1, 1
# 380 "data/maps/SlateportCity_Harbor/scripts.pory"
	msgbox SlateportCity_Harbor_Text_ThisWillHelpResearch, MSGBOX_DEFAULT
# 381 "data/maps/SlateportCity_Harbor/scripts.pory"
	release
# 382 "data/maps/SlateportCity_Harbor/scripts.pory"
	end
# 383 "data/maps/SlateportCity_Harbor/scripts.pory"

# 384 "data/maps/SlateportCity_Harbor/scripts.pory"
SlateportCity_Harbor_Text_FerryServiceUnavailable:
# 385 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "I beg your pardon?\n"
# 386 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "You're looking for a ship?\p"
# 387 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "I'm sorry, the ferry service isn't\n"
# 388 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "available at present…$"
# 389 "data/maps/SlateportCity_Harbor/scripts.pory"

# 390 "data/maps/SlateportCity_Harbor/scripts.pory"
SlateportCity_Harbor_Text_MayISeeYourTicket:
# 391 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "Hello, are you here for the ferry?\n"
# 392 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "May I see your TICKET?$"
# 393 "data/maps/SlateportCity_Harbor/scripts.pory"

# 394 "data/maps/SlateportCity_Harbor/scripts.pory"
SlateportCity_Harbor_Text_YouMustHaveTicket:
# 395 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "{PLAYER} doesn't have the TICKET…\p"
# 396 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "I'm terribly sorry.\p"
# 397 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "You must have a TICKET to board\n"
# 398 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "the ferry.$"
# 399 "data/maps/SlateportCity_Harbor/scripts.pory"

# 400 "data/maps/SlateportCity_Harbor/scripts.pory"
SlateportCity_Harbor_Text_FlashedTicketWhereTo:
# 401 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "{PLAYER} flashed the TICKET.\p"
# 402 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "Perfect! That's all you need!\p"
# 403 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "And where would you like to go?$"
# 404 "data/maps/SlateportCity_Harbor/scripts.pory"

# 405 "data/maps/SlateportCity_Harbor/scripts.pory"
SlateportCity_Harbor_Text_SailAnotherTime:
# 406 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "Please sail with us another time!$"
# 407 "data/maps/SlateportCity_Harbor/scripts.pory"

# 408 "data/maps/SlateportCity_Harbor/scripts.pory"
SlateportCity_Harbor_Text_LilycoveItIs:
# 409 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "LILYCOVE CITY it is, then!$"
# 410 "data/maps/SlateportCity_Harbor/scripts.pory"

# 411 "data/maps/SlateportCity_Harbor/scripts.pory"
SlateportCity_Harbor_Text_BattleFrontierItIs:
# 412 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "BATTLE FRONTIER it is, then!$"
# 413 "data/maps/SlateportCity_Harbor/scripts.pory"

# 414 "data/maps/SlateportCity_Harbor/scripts.pory"
SlateportCity_Harbor_Text_PleaseBoardFerry:
# 415 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "Please board the ferry and wait for\n"
# 416 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "departure.$"
# 417 "data/maps/SlateportCity_Harbor/scripts.pory"

# 418 "data/maps/SlateportCity_Harbor/scripts.pory"
SlateportCity_Harbor_Text_WhereWouldYouLikeToGo:
# 419 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "Then, where would you like to go?$"
# 420 "data/maps/SlateportCity_Harbor/scripts.pory"

# 421 "data/maps/SlateportCity_Harbor/scripts.pory"
SlateportCity_Harbor_Text_LoveToGoDeepUnderwaterSomeday:
# 422 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "A journey to the bottom of the sea…\n"
# 423 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "I wonder what it'd be like?\p"
# 424 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "I'd love to go deep underwater like\n"
# 425 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "that someday.$"
# 426 "data/maps/SlateportCity_Harbor/scripts.pory"

# 427 "data/maps/SlateportCity_Harbor/scripts.pory"
SlateportCity_Harbor_Text_AbnormalWeather:
# 428 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "For a ship to sail safely, we need to\n"
# 429 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "know about the weather!\p"
# 430 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "Speaking of weather, I heard something\n"
# 431 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "from a guy at the WEATHER INSTITUTE.\p"
# 432 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "He was saying abnormal weather has\n"
# 433 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "been reported all over the place!\p"
# 434 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "You should visit the WEATHER INSTITUTE\n"
# 435 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "and ask around!$"
# 436 "data/maps/SlateportCity_Harbor/scripts.pory"

# 437 "data/maps/SlateportCity_Harbor/scripts.pory"
SlateportCity_Harbor_Text_SubTooSmallForMe:
# 438 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "I wanted to go with CAPT. STERN on\n"
# 439 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "the ocean floor exploration.\p"
# 440 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "But the sub's too small for me.\p"
# 441 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "If I squeezed in, there wouldn't be\n"
# 442 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "any room for the CAPTAIN…$"
# 443 "data/maps/SlateportCity_Harbor/scripts.pory"

# 444 "data/maps/SlateportCity_Harbor/scripts.pory"
SlateportCity_Harbor_Text_SameThugsTriedToRobAtMuseum:
# 445 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "CAPT. STERN: Those thugs…\p"
# 446 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "They're the same lot who tried to rob\n"
# 447 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "the DEVON GOODS at the MUSEUM.$"
# 448 "data/maps/SlateportCity_Harbor/scripts.pory"

# 449 "data/maps/SlateportCity_Harbor/scripts.pory"
SlateportCity_Harbor_Text_ArchieYouAgainHideoutInLilycove:
# 450 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "ARCHIE: Oh?\n"
# 451 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "Not you again…\p"
# 452 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "You are tenacious to track us here,\n"
# 453 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "that much I will give you.\p"
# 454 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "But now…\n"
# 455 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "No one can stop us! No one!\p"
# 456 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "Or, will you follow us back to our\n"
# 457 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "HIDEOUT in LILYCOVE CITY?\p"
# 458 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "Fwahahahaha…$"
# 459 "data/maps/SlateportCity_Harbor/scripts.pory"

# 460 "data/maps/SlateportCity_Harbor/scripts.pory"
SlateportCity_Harbor_Text_CaptSternWhyStealMySubmarine:
# 461 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "CAPT. STERN: Why…\p"
# 462 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "Why would TEAM AQUA steal my\n"
# 463 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "SUBMARINE EXPLORER 1?\p"
# 464 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "They can't be after the slumbering\n"
# 465 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "POKéMON at the bottom of the sea…\p"
# 466 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "But even if I were to chase them,\n"
# 467 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "I don't stand a chance against them…$"
# 468 "data/maps/SlateportCity_Harbor/scripts.pory"

# 469 "data/maps/SlateportCity_Harbor/scripts.pory"
SlateportCity_Harbor_Text_TeamAquaLeftNeedDive:
# 470 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "CAPT. STERN: Oh, {PLAYER}{KUN}…\p"
# 471 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "Okay… So TEAM AQUA left before you\n"
# 472 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "could stop them…\p"
# 473 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "Oh, no, don't blame yourself.\n"
# 474 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "You're not responsible for this.\p"
# 475 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "Trying to catch a submarine…\n"
# 476 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "It's impossible for most people.\p"
# 477 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "You would need a POKéMON that knows\n"
# 478 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "how to DIVE…\p"
# 479 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "Perhaps if you went out to\n"
# 480 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "MOSSDEEP CITY…\p"
# 481 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "A lot of divers live out there, so\n"
# 482 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "someone might teach you…$"
# 483 "data/maps/SlateportCity_Harbor/scripts.pory"

# 484 "data/maps/SlateportCity_Harbor/scripts.pory"
SlateportCity_Harbor_Text_NeedDiveToCatchSub:
# 485 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "CAPT. STERN: Trying to catch a\n"
# 486 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "submarine… It's impossible.\p"
# 487 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "You would need a POKéMON that knows\n"
# 488 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "how to DIVE…\p"
# 489 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "Perhaps if you went out to\n"
# 490 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "MOSSDEEP CITY…\p"
# 491 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "A lot of divers live out there, so\n"
# 492 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "someone might teach you…$"
# 493 "data/maps/SlateportCity_Harbor/scripts.pory"

# 494 "data/maps/SlateportCity_Harbor/scripts.pory"
SlateportCity_Harbor_Text_WontBeLongBeforeWeFinishFerry:
# 495 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "CAPT. STERN: Oh, yes.\n"
# 496 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "MR. BRINEY came to our SHIPYARD.\p"
# 497 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "It won't be long now before we finish\n"
# 498 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "making the ferry!$"
# 499 "data/maps/SlateportCity_Harbor/scripts.pory"

# 500 "data/maps/SlateportCity_Harbor/scripts.pory"
SlateportCity_Harbor_Text_FinishedMakingFerry:
# 501 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "CAPT. STERN: {PLAYER}{KUN}!\p"
# 502 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "We finally finished making the ferry\n"
# 503 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "S.S. TIDAL!\p"
# 504 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "We couldn't have done it without\n"
# 505 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "your friend MR. BRINEY.\p"
# 506 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "Please go for a short cruise on it!$"
# 507 "data/maps/SlateportCity_Harbor/scripts.pory"

# 508 "data/maps/SlateportCity_Harbor/scripts.pory"
SlateportCity_Harbor_Text_WouldYouTradeScanner:
# 509 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "CAPT. STERN: Oh?\n"
# 510 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "{PLAYER}{KUN}, that item you have…\p"
# 511 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "That's a SCANNER! That would sure\n"
# 512 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "help us on our explorations.\p"
# 513 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "{PLAYER}{KUN}, would you trade your\n"
# 514 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "SCANNER for something?\p"
# 515 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "Like, say, a DEEPSEATOOTH or\n"
# 516 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "a DEEPSEASCALE that I have?$"
# 517 "data/maps/SlateportCity_Harbor/scripts.pory"

# 518 "data/maps/SlateportCity_Harbor/scripts.pory"
SlateportCity_Harbor_Text_IfYouWantToTradeLetMeKnow:
# 519 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "CAPT. STERN: Are you certain?\n"
# 520 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "It's useless to you, {PLAYER}{KUN}…\p"
# 521 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "Well, okay, then. If you want to trade\n"
# 522 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "your SCANNER, let me know.$"
# 523 "data/maps/SlateportCity_Harbor/scripts.pory"

# 524 "data/maps/SlateportCity_Harbor/scripts.pory"
SlateportCity_Harbor_Text_TradeForDeepSeaTooth:
# 525 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "CAPT. STERN: So you'll trade it for\n"
# 526 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "my DEEPSEATOOTH?$"
# 527 "data/maps/SlateportCity_Harbor/scripts.pory"

# 528 "data/maps/SlateportCity_Harbor/scripts.pory"
SlateportCity_Harbor_Text_TradeForDeepSeaScale:
# 529 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "CAPT. STERN: So you'll trade it for\n"
# 530 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "my DEEPSEASCALE?$"
# 531 "data/maps/SlateportCity_Harbor/scripts.pory"

# 532 "data/maps/SlateportCity_Harbor/scripts.pory"
SlateportCity_Harbor_Text_WhichOneDoYouWant:
# 533 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "CAPT. STERN: Which one do you want?$"
# 534 "data/maps/SlateportCity_Harbor/scripts.pory"

# 535 "data/maps/SlateportCity_Harbor/scripts.pory"
SlateportCity_Harbor_Text_HandedScannerToStern:
# 536 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "{PLAYER} handed the SCANNER to\n"
# 537 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "CAPT. STERN.$"
# 538 "data/maps/SlateportCity_Harbor/scripts.pory"

# 539 "data/maps/SlateportCity_Harbor/scripts.pory"
SlateportCity_Harbor_Text_ThisWillHelpResearch:
# 540 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "CAPT. STERN: Thanks, {PLAYER}{KUN}!\n"
# 541 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "This will help our research a lot!$"
