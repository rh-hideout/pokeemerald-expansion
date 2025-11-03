# 1 "data/maps/Route110_TrickHouseEnd/scripts.pory"

# 2 "data/maps/Route110_TrickHouseEnd/scripts.pory"
Route110_TrickHouseEnd_MapScripts::
# 3 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	map_script MAP_SCRIPT_ON_RESUME, Route110_TrickHouseEnd_OnResume
# 4 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, Route110_TrickHouseEnd_OnTransition
# 5 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Route110_TrickHouseEnd_OnFrame
# 6 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, Route110_TrickHouseEnd_OnWarp
# 7 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	.byte 0
# 8 "data/maps/Route110_TrickHouseEnd/scripts.pory"

# 9 "data/maps/Route110_TrickHouseEnd/scripts.pory"
Route110_TrickHouseEnd_OnResume:
# 10 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	call_if_eq VAR_TEMP_1, 1, Route110_TrickHouseEnd_EventScript_SetDoorClosedMetatile
# 11 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	end
# 12 "data/maps/Route110_TrickHouseEnd/scripts.pory"

# 13 "data/maps/Route110_TrickHouseEnd/scripts.pory"
Route110_TrickHouseEnd_OnTransition:
# 14 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	setvar VAR_TEMP_1, 0
# 15 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	setvar VAR_TEMP_2, 0
# 16 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	special SetTrickHouseNuggetFlag
# 17 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	end
# 18 "data/maps/Route110_TrickHouseEnd/scripts.pory"

# 19 "data/maps/Route110_TrickHouseEnd/scripts.pory"
Route110_TrickHouseEnd_OnWarp:
# 20 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	map_script_2 VAR_TEMP_2, 0, Route110_TrickHouseEnd_EventScript_SetTrickMasterPos
# 21 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	.2byte 0
# 22 "data/maps/Route110_TrickHouseEnd/scripts.pory"

# 23 "data/maps/Route110_TrickHouseEnd/scripts.pory"
Route110_TrickHouseEnd_EventScript_SetTrickMasterPos::
# 24 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	addobject LOCALID_TRICK_MASTER_END
# 25 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	showobjectat LOCALID_TRICK_MASTER_END, MAP_ROUTE110_TRICK_HOUSE_END
# 26 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	turnobject LOCALID_TRICK_MASTER_END, DIR_EAST
# 27 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	end
# 28 "data/maps/Route110_TrickHouseEnd/scripts.pory"

# 29 "data/maps/Route110_TrickHouseEnd/scripts.pory"
Route110_TrickHouseEnd_OnFrame:
# 30 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	map_script_2 VAR_TEMP_1, 0, Route110_TrickHouseEnd_EventScript_CloseDoor
# 31 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	.2byte 0
# 32 "data/maps/Route110_TrickHouseEnd/scripts.pory"

# 33 "data/maps/Route110_TrickHouseEnd/scripts.pory"
Route110_TrickHouseEnd_EventScript_CloseDoor::
# 34 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	setvar VAR_TEMP_1, 1
# 35 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	call Route110_TrickHouseEnd_EventScript_SetDoorClosedMetatile
# 36 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	special DrawWholeMapView
# 37 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	end
# 38 "data/maps/Route110_TrickHouseEnd/scripts.pory"

# 39 "data/maps/Route110_TrickHouseEnd/scripts.pory"
Route110_TrickHouseEnd_EventScript_SetDoorClosedMetatile::
# 40 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	setmetatile 10, 1, METATILE_GenericBuilding_TrickHouse_Door_Closed, TRUE
# 41 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	return
# 42 "data/maps/Route110_TrickHouseEnd/scripts.pory"

# 43 "data/maps/Route110_TrickHouseEnd/scripts.pory"
Route110_TrickHouseEnd_EventScript_TrickMaster::
# 44 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	lock
# 45 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	faceplayer
# 46 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	msgbox Route110_TrickHouseEnd_Text_YouveMadeItToMe, MSGBOX_DEFAULT
# 47 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	setvar VAR_TEMP_2, 1
# 48 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	switch VAR_TRICK_HOUSE_LEVEL
# 49 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	case 0, Route110_TrickHouseEnd_EventScript_CompletedPuzzle1
# 50 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	case 1, Route110_TrickHouseEnd_EventScript_CompletedPuzzle2
# 51 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	case 2, Route110_TrickHouseEnd_EventScript_CompletedPuzzle3
# 52 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	case 3, Route110_TrickHouseEnd_EventScript_CompletedPuzzle4
# 53 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	case 4, Route110_TrickHouseEnd_EventScript_CompletedPuzzle5
# 54 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	case 5, Route110_TrickHouseEnd_EventScript_CompletedPuzzle6
# 55 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	case 6, Route110_TrickHouseEnd_EventScript_CompletedPuzzle7
# 56 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	case 7, Route110_TrickHouseEnd_EventScript_CompletedPuzzle8
# 57 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	end
# 58 "data/maps/Route110_TrickHouseEnd/scripts.pory"

# 59 "data/maps/Route110_TrickHouseEnd/scripts.pory"
Route110_TrickHouseEnd_EventScript_CompletedPuzzle1::
# 60 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	msgbox Route110_TrickHouseEnd_Text_AllNightToPlantTrees, MSGBOX_DEFAULT
# 61 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	msgbox Route110_TrickHouseEnd_Text_YouHaveEarnedThisReward, MSGBOX_DEFAULT
# 62 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	setvar VAR_TRICK_HOUSE_PRIZE_PICKUP, 0
# 63 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	giveitem ITEM_RARE_CANDY
# 64 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	call_if_eq VAR_RESULT, FALSE, Route110_TrickHouseEnd_EventScript_BagFull
# 65 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	msgbox Route110_TrickHouseEnd_Text_MakeNewTricksToStumpYou, MSGBOX_DEFAULT
# 66 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	closemessage
# 67 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	call Route110_TrickHouseEnd_EventScript_TrickMasterExit
# 68 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	release
# 69 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	end
# 70 "data/maps/Route110_TrickHouseEnd/scripts.pory"

# 71 "data/maps/Route110_TrickHouseEnd/scripts.pory"
Route110_TrickHouseEnd_EventScript_CompletedPuzzle2::
# 72 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	msgbox Route110_TrickHouseEnd_Text_AllNightToMakeMaze, MSGBOX_DEFAULT
# 73 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	msgbox Route110_TrickHouseEnd_Text_YouHaveEarnedThisReward, MSGBOX_DEFAULT
# 74 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	setvar VAR_TRICK_HOUSE_PRIZE_PICKUP, 0
# 75 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	giveitem ITEM_TIMER_BALL
# 76 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	call_if_eq VAR_RESULT, FALSE, Route110_TrickHouseEnd_EventScript_BagFull
# 77 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	msgbox Route110_TrickHouseEnd_Text_MakeNewTricksToStumpYou, MSGBOX_DEFAULT
# 78 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	closemessage
# 79 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	call Route110_TrickHouseEnd_EventScript_TrickMasterExit
# 80 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	release
# 81 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	end
# 82 "data/maps/Route110_TrickHouseEnd/scripts.pory"

# 83 "data/maps/Route110_TrickHouseEnd/scripts.pory"
Route110_TrickHouseEnd_EventScript_CompletedPuzzle3::
# 84 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	msgbox Route110_TrickHouseEnd_Text_AllNightToPreparePanels, MSGBOX_DEFAULT
# 85 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	msgbox Route110_TrickHouseEnd_Text_YouHaveEarnedThisReward, MSGBOX_DEFAULT
# 86 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	setvar VAR_TRICK_HOUSE_PRIZE_PICKUP, 0
# 87 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	giveitem ITEM_HARD_STONE
# 88 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	call_if_eq VAR_RESULT, FALSE, Route110_TrickHouseEnd_EventScript_BagFull
# 89 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	msgbox Route110_TrickHouseEnd_Text_MakeNewTricksToStumpYou, MSGBOX_DEFAULT
# 90 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	closemessage
# 91 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	call Route110_TrickHouseEnd_EventScript_TrickMasterExit
# 92 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	release
# 93 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	end
# 94 "data/maps/Route110_TrickHouseEnd/scripts.pory"

# 95 "data/maps/Route110_TrickHouseEnd/scripts.pory"
Route110_TrickHouseEnd_EventScript_CompletedPuzzle4::
# 96 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	msgbox Route110_TrickHouseEnd_Text_AllNightToShoveBoulders, MSGBOX_DEFAULT
# 97 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	msgbox Route110_TrickHouseEnd_Text_YouHaveEarnedThisReward, MSGBOX_DEFAULT
# 98 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	setvar VAR_TRICK_HOUSE_PRIZE_PICKUP, 0
# 99 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	giveitem ITEM_SMOKE_BALL
# 100 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	call_if_eq VAR_RESULT, FALSE, Route110_TrickHouseEnd_EventScript_BagFull
# 101 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	msgbox Route110_TrickHouseEnd_Text_MakeNewTricksToStumpYou, MSGBOX_DEFAULT
# 102 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	closemessage
# 103 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	call Route110_TrickHouseEnd_EventScript_TrickMasterExit
# 104 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	release
# 105 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	end
# 106 "data/maps/Route110_TrickHouseEnd/scripts.pory"

# 107 "data/maps/Route110_TrickHouseEnd/scripts.pory"
Route110_TrickHouseEnd_EventScript_CompletedPuzzle5::
# 108 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	msgbox Route110_TrickHouseEnd_Text_AllNightToMakeMechadolls, MSGBOX_DEFAULT
# 109 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	msgbox Route110_TrickHouseEnd_Text_YouHaveEarnedThisReward, MSGBOX_DEFAULT
# 110 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	setvar VAR_TRICK_HOUSE_PRIZE_PICKUP, 0
# 111 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	giveitem ITEM_TM_TAUNT
# 112 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	call_if_eq VAR_RESULT, FALSE, Route110_TrickHouseEnd_EventScript_BagFull
# 113 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	msgbox Route110_TrickHouseEnd_Text_MakeNewTricksToStumpYou, MSGBOX_DEFAULT
# 114 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	closemessage
# 115 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	call Route110_TrickHouseEnd_EventScript_TrickMasterExit
# 116 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	release
# 117 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	end
# 118 "data/maps/Route110_TrickHouseEnd/scripts.pory"

# 119 "data/maps/Route110_TrickHouseEnd/scripts.pory"
Route110_TrickHouseEnd_EventScript_CompletedPuzzle6::
# 120 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	msgbox Route110_TrickHouseEnd_Text_AllNightToInstallDoors, MSGBOX_DEFAULT
# 121 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	msgbox Route110_TrickHouseEnd_Text_YouHaveEarnedThisReward, MSGBOX_DEFAULT
# 122 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	setvar VAR_TRICK_HOUSE_PRIZE_PICKUP, 0
# 123 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	giveitem ITEM_MAGNET
# 124 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	call_if_eq VAR_RESULT, FALSE, Route110_TrickHouseEnd_EventScript_BagFull
# 125 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	msgbox Route110_TrickHouseEnd_Text_MakeNewTricksToStumpYou, MSGBOX_DEFAULT
# 126 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	closemessage
# 127 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	call Route110_TrickHouseEnd_EventScript_TrickMasterExit
# 128 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	release
# 129 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	end
# 130 "data/maps/Route110_TrickHouseEnd/scripts.pory"

# 131 "data/maps/Route110_TrickHouseEnd/scripts.pory"
Route110_TrickHouseEnd_EventScript_CompletedPuzzle7::
# 132 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	msgbox Route110_TrickHouseEnd_Text_AllNightSettingUpArrows, MSGBOX_DEFAULT
# 133 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	msgbox Route110_TrickHouseEnd_Text_YouHaveEarnedThisReward, MSGBOX_DEFAULT
# 134 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	setvar VAR_TRICK_HOUSE_PRIZE_PICKUP, 0
# 135 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	giveitem ITEM_PP_MAX
# 136 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	call_if_eq VAR_RESULT, FALSE, Route110_TrickHouseEnd_EventScript_BagFull
# 137 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	msgbox Route110_TrickHouseEnd_Text_MakeNewTricksToStumpYou, MSGBOX_DEFAULT
# 138 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	closemessage
# 139 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	call Route110_TrickHouseEnd_EventScript_TrickMasterExit
# 140 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	release
# 141 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	end
# 142 "data/maps/Route110_TrickHouseEnd/scripts.pory"

# 143 "data/maps/Route110_TrickHouseEnd/scripts.pory"
Route110_TrickHouseEnd_EventScript_CompletedPuzzle8::
# 144 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	msgbox Route110_TrickHouseEnd_Text_AllNightPolishingFloors, MSGBOX_DEFAULT
# 145 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	closemessage
# 146 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	call_if_eq VAR_FACING, DIR_SOUTH, Route110_TrickHouseEnd_EventScript_TrickMasterFaceAwaySouth
# 147 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	call_if_eq VAR_FACING, DIR_NORTH, Route110_TrickHouseEnd_EventScript_TrickMasterFaceAwayNorth
# 148 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	call_if_eq VAR_FACING, DIR_WEST, Route110_TrickHouseEnd_EventScript_TrickMasterFaceAwayWest
# 149 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	call_if_eq VAR_FACING, DIR_EAST, Route110_TrickHouseEnd_EventScript_TrickMasterFaceAwayEast
# 150 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	delay 30
# 151 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	msgbox Route110_TrickHouseEnd_Text_FountainOfIdeasRunDry, MSGBOX_DEFAULT
# 152 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	closemessage
# 153 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	applymovement LOCALID_TRICK_MASTER_END, Common_Movement_FacePlayer
# 154 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	waitmovement 0
# 155 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	delay 30
# 156 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	msgbox Route110_TrickHouseEnd_Text_DefeatedMePreferWhichTent, MSGBOX_DEFAULT
# 157 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	setvar VAR_TRICK_HOUSE_PRIZE_PICKUP, 0
# 158 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	call Route110_TrickHouseEnd_EventScript_ChooseTent
# 159 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	call_if_eq VAR_RESULT, FALSE, Route110_TrickHouseEnd_EventScript_NoRoomForTent
# 160 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	msgbox Route110_TrickHouseEnd_Text_LeavingOnJourney, MSGBOX_DEFAULT
# 161 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	call Route110_TrickHouseEnd_EventScript_TrickMasterExit
# 162 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	special ResetTrickHouseNuggetFlag
# 163 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	release
# 164 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	end
# 165 "data/maps/Route110_TrickHouseEnd/scripts.pory"

# 166 "data/maps/Route110_TrickHouseEnd/scripts.pory"
Route110_TrickHouseEnd_EventScript_ChooseTent::
# 167 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	multichoice 0, 0, MULTI_TENT, TRUE
# 168 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	switch VAR_RESULT
# 169 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	case 0, Route110_TrickHouseEnd_EventScript_GiveRedTent
# 170 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	goto Route110_TrickHouseEnd_EventScript_GiveBlueTent
# 171 "data/maps/Route110_TrickHouseEnd/scripts.pory"

# 172 "data/maps/Route110_TrickHouseEnd/scripts.pory"
Route110_TrickHouseEnd_EventScript_GiveRedTent::
# 173 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	givedecoration DECOR_RED_TENT
# 174 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	return
# 175 "data/maps/Route110_TrickHouseEnd/scripts.pory"

# 176 "data/maps/Route110_TrickHouseEnd/scripts.pory"
Route110_TrickHouseEnd_EventScript_GiveBlueTent::
# 177 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	givedecoration DECOR_BLUE_TENT
# 178 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	return
# 179 "data/maps/Route110_TrickHouseEnd/scripts.pory"

# 180 "data/maps/Route110_TrickHouseEnd/scripts.pory"
Route110_TrickHouseEnd_EventScript_TrickMasterExit::
# 181 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	applymovement LOCALID_TRICK_MASTER_END, Route110_TrickHouse_Movement_TrickMasterSpin
# 182 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	waitmovement 0
# 183 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	playse SE_M_EXPLOSION
# 184 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	applymovement LOCALID_TRICK_MASTER_END, Route110_TrickHouse_Movement_TrickMasterJumpAway
# 185 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	waitmovement 0
# 186 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	removeobject LOCALID_TRICK_MASTER_END
# 187 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	addvar VAR_TRICK_HOUSE_LEVEL, 1
# 188 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	return
# 189 "data/maps/Route110_TrickHouseEnd/scripts.pory"

# 190 "data/maps/Route110_TrickHouseEnd/scripts.pory"
Route110_TrickHouseEnd_EventScript_BagFull::
# 191 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	call Common_EventScript_BagIsFull
# 192 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	msgbox Route110_TrickHouseEnd_Text_NoRoomForThis, MSGBOX_DEFAULT
# 193 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	setvar VAR_TRICK_HOUSE_PRIZE_PICKUP, 1
# 194 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	return
# 195 "data/maps/Route110_TrickHouseEnd/scripts.pory"

# 196 "data/maps/Route110_TrickHouseEnd/scripts.pory"
Route110_TrickHouseEnd_EventScript_NoRoomForTent::
# 197 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	call Common_EventScript_NoRoomForDecor
# 198 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	msgbox Route110_TrickHouseEnd_Text_NoRoomInPC, MSGBOX_DEFAULT
# 199 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	setvar VAR_TRICK_HOUSE_PRIZE_PICKUP, 1
# 200 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	return
# 201 "data/maps/Route110_TrickHouseEnd/scripts.pory"

# 202 "data/maps/Route110_TrickHouseEnd/scripts.pory"
Route110_TrickHouseEnd_EventScript_TrickMasterFaceAwaySouth::
# 203 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	applymovement LOCALID_TRICK_MASTER_END, Common_Movement_WalkInPlaceFasterDown
# 204 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	waitmovement 0
# 205 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	return
# 206 "data/maps/Route110_TrickHouseEnd/scripts.pory"

# 207 "data/maps/Route110_TrickHouseEnd/scripts.pory"
Route110_TrickHouseEnd_EventScript_TrickMasterFaceAwayNorth::
# 208 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	applymovement LOCALID_TRICK_MASTER_END, Common_Movement_WalkInPlaceFasterUp
# 209 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	waitmovement 0
# 210 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	return
# 211 "data/maps/Route110_TrickHouseEnd/scripts.pory"

# 212 "data/maps/Route110_TrickHouseEnd/scripts.pory"
Route110_TrickHouseEnd_EventScript_TrickMasterFaceAwayWest::
# 213 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	applymovement LOCALID_TRICK_MASTER_END, Common_Movement_WalkInPlaceFasterLeft
# 214 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	waitmovement 0
# 215 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	return
# 216 "data/maps/Route110_TrickHouseEnd/scripts.pory"

# 217 "data/maps/Route110_TrickHouseEnd/scripts.pory"
Route110_TrickHouseEnd_EventScript_TrickMasterFaceAwayEast::
# 218 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	applymovement LOCALID_TRICK_MASTER_END, Common_Movement_WalkInPlaceFasterRight
# 219 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	waitmovement 0
# 220 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	return
# 221 "data/maps/Route110_TrickHouseEnd/scripts.pory"

# 222 "data/maps/Route110_TrickHouseEnd/scripts.pory"
Route110_TrickHouseEnd_EventScript_TrickMasterExitTrigger::
# 223 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	lockall
# 224 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	turnobject LOCALID_TRICK_MASTER_END, DIR_WEST
# 225 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	playse SE_PIN
# 226 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	applymovement LOCALID_TRICK_MASTER_END, Common_Movement_ExclamationMark
# 227 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	waitmovement 0
# 228 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	delay 20
# 229 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	applymovement LOCALID_TRICK_MASTER_END, Route110_TrickHouseEnd_Movement_TrickMasterSurprise
# 230 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	waitmovement 0
# 231 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	playse SE_M_EXPLOSION
# 232 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterDown
# 233 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	waitmovement 0
# 234 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	msgbox Route110_TrickHouseEnd_Text_YoureIgnoringMe, MSGBOX_DEFAULT
# 235 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	closemessage
# 236 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	applymovement LOCALID_PLAYER, Route110_TrickHouseEnd_Movement_KeepPlayerInRoom
# 237 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	waitmovement 0
# 238 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	delay 4
# 239 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	turnobject LOCALID_TRICK_MASTER_END, DIR_EAST
# 240 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	releaseall
# 241 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	end
# 242 "data/maps/Route110_TrickHouseEnd/scripts.pory"

# 243 "data/maps/Route110_TrickHouseEnd/scripts.pory"
Route110_TrickHouseEnd_Movement_KeepPlayerInRoom:
# 244 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	walk_down
# 245 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	step_end
# 246 "data/maps/Route110_TrickHouseEnd/scripts.pory"

# 247 "data/maps/Route110_TrickHouseEnd/scripts.pory"
Route110_TrickHouseEnd_Movement_TrickMasterSurprise:
# 248 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	jump_in_place_left
# 249 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	step_end
# 250 "data/maps/Route110_TrickHouseEnd/scripts.pory"

# 251 "data/maps/Route110_TrickHouseEnd/scripts.pory"
Route110_TrickHouseEnd_Text_YouveMadeItToMe:
# 252 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	.string "Aak!\n"
# 253 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	.string "You've made it to me?\l"
# 254 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	.string "Hmmm… You're sharp!$"
# 255 "data/maps/Route110_TrickHouseEnd/scripts.pory"

# 256 "data/maps/Route110_TrickHouseEnd/scripts.pory"
Route110_TrickHouseEnd_Text_AllNightToPlantTrees:
# 257 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	.string "It took me all night to plant all those\n"
# 258 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	.string "trees…\p"
# 259 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	.string "You're almost my equal in greatness by\n"
# 260 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	.string "one, two, three, four, five, six places!$"
# 261 "data/maps/Route110_TrickHouseEnd/scripts.pory"

# 262 "data/maps/Route110_TrickHouseEnd/scripts.pory"
Route110_TrickHouseEnd_Text_AllNightToMakeMaze:
# 263 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	.string "It took me all night to make the maze…\p"
# 264 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	.string "You're almost my equal in greatness by\n"
# 265 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	.string "one, two, three, four, five places!$"
# 266 "data/maps/Route110_TrickHouseEnd/scripts.pory"

# 267 "data/maps/Route110_TrickHouseEnd/scripts.pory"
Route110_TrickHouseEnd_Text_AllNightToPreparePanels:
# 268 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	.string "It took me all night to prepare\n"
# 269 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	.string "the wall panels…\p"
# 270 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	.string "You're almost my equal in greatness by\n"
# 271 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	.string "one, two, three, four places!$"
# 272 "data/maps/Route110_TrickHouseEnd/scripts.pory"

# 273 "data/maps/Route110_TrickHouseEnd/scripts.pory"
Route110_TrickHouseEnd_Text_AllNightToShoveBoulders:
# 274 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	.string "It took me all night to shove in those\n"
# 275 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	.string "boulders…\p"
# 276 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	.string "You're almost my equal in greatness by\n"
# 277 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	.string "one, two, three places!$"
# 278 "data/maps/Route110_TrickHouseEnd/scripts.pory"

# 279 "data/maps/Route110_TrickHouseEnd/scripts.pory"
Route110_TrickHouseEnd_Text_AllNightToMakeMechadolls:
# 280 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	.string "It took me all night to make MECHADOLLS\n"
# 281 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	.string "and another to think up the quiz…\p"
# 282 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	.string "You're almost my equal in greatness by\n"
# 283 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	.string "one, two places!$"
# 284 "data/maps/Route110_TrickHouseEnd/scripts.pory"

# 285 "data/maps/Route110_TrickHouseEnd/scripts.pory"
Route110_TrickHouseEnd_Text_AllNightToInstallDoors:
# 286 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	.string "It took me all night to install\n"
# 287 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	.string "the doors…\p"
# 288 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	.string "You're almost my equal in greatness!$"
# 289 "data/maps/Route110_TrickHouseEnd/scripts.pory"

# 290 "data/maps/Route110_TrickHouseEnd/scripts.pory"
Route110_TrickHouseEnd_Text_AllNightSettingUpArrows:
# 291 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	.string "It took me all night setting up arrows…\p"
# 292 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	.string "You're my equal in greatness!$"
# 293 "data/maps/Route110_TrickHouseEnd/scripts.pory"

# 294 "data/maps/Route110_TrickHouseEnd/scripts.pory"
Route110_TrickHouseEnd_Text_AllNightPolishingFloors:
# 295 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	.string "It took me all night polishing floors…\p"
# 296 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	.string "You're above me in greatness!\n"
# 297 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	.string "Possibly…$"
# 298 "data/maps/Route110_TrickHouseEnd/scripts.pory"

# 299 "data/maps/Route110_TrickHouseEnd/scripts.pory"
Route110_TrickHouseEnd_Text_FountainOfIdeasRunDry:
# 300 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	.string "Wh-what should I do?\n"
# 301 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	.string "My fountain of ideas for tricks has\l"
# 302 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	.string "run dry…\p"
# 303 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	.string "Perhaps it is time I toured the country\n"
# 304 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	.string "on a quest to devise new tricks…$"
# 305 "data/maps/Route110_TrickHouseEnd/scripts.pory"

# 306 "data/maps/Route110_TrickHouseEnd/scripts.pory"
Route110_TrickHouseEnd_Text_DefeatedMePreferWhichTent:
# 307 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	.string "I hate to admit defeat, but you have\n"
# 308 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	.string "bested me!\p"
# 309 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	.string "Still, you must have been reeled in by\n"
# 310 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	.string "my charisma for you to visit me again\l"
# 311 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	.string "and again. Yes, you must have!\p"
# 312 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	.string "But that has nothing to do with my\n"
# 313 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	.string "losing!\p"
# 314 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	.string "In recognition of the friendship\n"
# 315 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	.string "between you, the driven, and the genius\l"
# 316 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	.string "that is myself, I demand that you take\l"
# 317 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	.string "this keepsake!\p"
# 318 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	.string "Actually there are two--\n"
# 319 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	.string "a RED TENT and a BLUE TENT.\l"
# 320 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	.string "Which do you prefer?$"
# 321 "data/maps/Route110_TrickHouseEnd/scripts.pory"

# 322 "data/maps/Route110_TrickHouseEnd/scripts.pory"
Route110_TrickHouseEnd_Text_NoRoomInPC:
# 323 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	.string "What? No room in your PC?\n"
# 324 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	.string "What am I to make of that?\p"
# 325 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	.string "I wish I could say that, but I am much\n"
# 326 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	.string "too kind and caring, so come back later!$"
# 327 "data/maps/Route110_TrickHouseEnd/scripts.pory"

# 328 "data/maps/Route110_TrickHouseEnd/scripts.pory"
Route110_TrickHouseEnd_Text_LeavingOnJourney:
# 329 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	.string "… … … … … …\p"
# 330 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	.string "I am leaving on a journey of discovery.\n"
# 331 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	.string "A quest in search of new tricks.\p"
# 332 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	.string "I wish that you will one day visit and\n"
# 333 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	.string "entertain me again.\p"
# 334 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	.string "And now, farewell!$"
# 335 "data/maps/Route110_TrickHouseEnd/scripts.pory"

# 336 "data/maps/Route110_TrickHouseEnd/scripts.pory"
Route110_TrickHouseEnd_Text_YouHaveEarnedThisReward:
# 337 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	.string "Fine!\n"
# 338 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	.string "You have earned this reward!$"
# 339 "data/maps/Route110_TrickHouseEnd/scripts.pory"

# 340 "data/maps/Route110_TrickHouseEnd/scripts.pory"
Route110_TrickHouseEnd_Text_NoRoomForThis:
# 341 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	.string "What? Have you no room for this?\n"
# 342 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	.string "What manner of items do you carry?\p"
# 343 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	.string "But fine, since you've reached me,\n"
# 344 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	.string "your reward will be with me till later.$"
# 345 "data/maps/Route110_TrickHouseEnd/scripts.pory"

# 346 "data/maps/Route110_TrickHouseEnd/scripts.pory"
Route110_TrickHouseEnd_Text_MakeNewTricksToStumpYou:
# 347 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	.string "Scrub that smug smirk from your face!\n"
# 348 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	.string "It's much too early to think you've won!\p"
# 349 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	.string "I'll make new tricks to stump you, I will.\n"
# 350 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	.string "You may mock me only when you're done.\p"
# 351 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	.string "Come back for the next exciting\n"
# 352 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	.string "installment!$"
# 353 "data/maps/Route110_TrickHouseEnd/scripts.pory"

# 354 "data/maps/Route110_TrickHouseEnd/scripts.pory"
Route110_TrickHouseEnd_Text_YoureIgnoringMe:
# 355 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	.string "Now, now! You're ignoring me now?\n"
# 356 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	.string "Now that, I consider heartbreaking!$"
