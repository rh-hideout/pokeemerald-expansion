# 1 "data/maps/Route110_TrickHouseEnd/scripts.pory"

# 2 "data/maps/Route110_TrickHouseEnd/scripts.pory"
.set LOCALID_TRICK_MASTER, 1
# 3 "data/maps/Route110_TrickHouseEnd/scripts.pory"

# 4 "data/maps/Route110_TrickHouseEnd/scripts.pory"
Route110_TrickHouseEnd_MapScripts::
# 5 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	map_script MAP_SCRIPT_ON_RESUME, Route110_TrickHouseEnd_OnResume
# 6 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, Route110_TrickHouseEnd_OnTransition
# 7 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Route110_TrickHouseEnd_OnFrame
# 8 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, Route110_TrickHouseEnd_OnWarp
# 9 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	.byte 0
# 10 "data/maps/Route110_TrickHouseEnd/scripts.pory"

# 11 "data/maps/Route110_TrickHouseEnd/scripts.pory"
Route110_TrickHouseEnd_OnResume:
# 12 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	call_if_eq VAR_TEMP_1, 1, Route110_TrickHouseEnd_EventScript_SetDoorClosedMetatile
# 13 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	end
# 14 "data/maps/Route110_TrickHouseEnd/scripts.pory"

# 15 "data/maps/Route110_TrickHouseEnd/scripts.pory"
Route110_TrickHouseEnd_OnTransition:
# 16 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	setvar VAR_TEMP_1, 0
# 17 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	setvar VAR_TEMP_2, 0
# 18 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	special SetTrickHouseNuggetFlag
# 19 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	end
# 20 "data/maps/Route110_TrickHouseEnd/scripts.pory"

# 21 "data/maps/Route110_TrickHouseEnd/scripts.pory"
Route110_TrickHouseEnd_OnWarp:
# 22 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	map_script_2 VAR_TEMP_2, 0, Route110_TrickHouseEnd_EventScript_SetTrickMasterPos
# 23 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	.2byte 0
# 24 "data/maps/Route110_TrickHouseEnd/scripts.pory"

# 25 "data/maps/Route110_TrickHouseEnd/scripts.pory"
Route110_TrickHouseEnd_EventScript_SetTrickMasterPos::
# 26 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	addobject LOCALID_TRICK_MASTER
# 27 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	showobjectat LOCALID_TRICK_MASTER, MAP_ROUTE110_TRICK_HOUSE_END
# 28 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	turnobject LOCALID_TRICK_MASTER, DIR_EAST
# 29 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	end
# 30 "data/maps/Route110_TrickHouseEnd/scripts.pory"

# 31 "data/maps/Route110_TrickHouseEnd/scripts.pory"
Route110_TrickHouseEnd_OnFrame:
# 32 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	map_script_2 VAR_TEMP_1, 0, Route110_TrickHouseEnd_EventScript_CloseDoor
# 33 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	.2byte 0
# 34 "data/maps/Route110_TrickHouseEnd/scripts.pory"

# 35 "data/maps/Route110_TrickHouseEnd/scripts.pory"
Route110_TrickHouseEnd_EventScript_CloseDoor::
# 36 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	setvar VAR_TEMP_1, 1
# 37 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	call Route110_TrickHouseEnd_EventScript_SetDoorClosedMetatile
# 38 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	special DrawWholeMapView
# 39 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	end
# 40 "data/maps/Route110_TrickHouseEnd/scripts.pory"

# 41 "data/maps/Route110_TrickHouseEnd/scripts.pory"
Route110_TrickHouseEnd_EventScript_SetDoorClosedMetatile::
# 42 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	setmetatile 10, 1, METATILE_GenericBuilding_TrickHouse_Door_Closed, TRUE
# 43 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	return
# 44 "data/maps/Route110_TrickHouseEnd/scripts.pory"

# 45 "data/maps/Route110_TrickHouseEnd/scripts.pory"
Route110_TrickHouseEnd_EventScript_TrickMaster::
# 46 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	lock
# 47 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	faceplayer
# 48 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	msgbox Route110_TrickHouseEnd_Text_YouveMadeItToMe, MSGBOX_DEFAULT
# 49 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	setvar VAR_TEMP_2, 1
# 50 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	switch VAR_TRICK_HOUSE_LEVEL
# 51 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	case 0, Route110_TrickHouseEnd_EventScript_CompletedPuzzle1
# 52 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	case 1, Route110_TrickHouseEnd_EventScript_CompletedPuzzle2
# 53 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	case 2, Route110_TrickHouseEnd_EventScript_CompletedPuzzle3
# 54 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	case 3, Route110_TrickHouseEnd_EventScript_CompletedPuzzle4
# 55 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	case 4, Route110_TrickHouseEnd_EventScript_CompletedPuzzle5
# 56 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	case 5, Route110_TrickHouseEnd_EventScript_CompletedPuzzle6
# 57 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	case 6, Route110_TrickHouseEnd_EventScript_CompletedPuzzle7
# 58 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	case 7, Route110_TrickHouseEnd_EventScript_CompletedPuzzle8
# 59 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	end
# 60 "data/maps/Route110_TrickHouseEnd/scripts.pory"

# 61 "data/maps/Route110_TrickHouseEnd/scripts.pory"
Route110_TrickHouseEnd_EventScript_CompletedPuzzle1::
# 62 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	msgbox Route110_TrickHouseEnd_Text_AllNightToPlantTrees, MSGBOX_DEFAULT
# 63 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	msgbox Route110_TrickHouseEnd_Text_YouHaveEarnedThisReward, MSGBOX_DEFAULT
# 64 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	setvar VAR_TRICK_HOUSE_PRIZE_PICKUP, 0
# 65 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	giveitem ITEM_RARE_CANDY
# 66 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	call_if_eq VAR_RESULT, FALSE, Route110_TrickHouseEnd_EventScript_BagFull
# 67 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	msgbox Route110_TrickHouseEnd_Text_MakeNewTricksToStumpYou, MSGBOX_DEFAULT
# 68 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	closemessage
# 69 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	call Route110_TrickHouseEnd_EventScript_TrickMasterExit
# 70 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	release
# 71 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	end
# 72 "data/maps/Route110_TrickHouseEnd/scripts.pory"

# 73 "data/maps/Route110_TrickHouseEnd/scripts.pory"
Route110_TrickHouseEnd_EventScript_CompletedPuzzle2::
# 74 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	msgbox Route110_TrickHouseEnd_Text_AllNightToMakeMaze, MSGBOX_DEFAULT
# 75 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	msgbox Route110_TrickHouseEnd_Text_YouHaveEarnedThisReward, MSGBOX_DEFAULT
# 76 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	setvar VAR_TRICK_HOUSE_PRIZE_PICKUP, 0
# 77 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	giveitem ITEM_TIMER_BALL
# 78 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	call_if_eq VAR_RESULT, FALSE, Route110_TrickHouseEnd_EventScript_BagFull
# 79 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	msgbox Route110_TrickHouseEnd_Text_MakeNewTricksToStumpYou, MSGBOX_DEFAULT
# 80 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	closemessage
# 81 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	call Route110_TrickHouseEnd_EventScript_TrickMasterExit
# 82 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	release
# 83 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	end
# 84 "data/maps/Route110_TrickHouseEnd/scripts.pory"

# 85 "data/maps/Route110_TrickHouseEnd/scripts.pory"
Route110_TrickHouseEnd_EventScript_CompletedPuzzle3::
# 86 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	msgbox Route110_TrickHouseEnd_Text_AllNightToPreparePanels, MSGBOX_DEFAULT
# 87 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	msgbox Route110_TrickHouseEnd_Text_YouHaveEarnedThisReward, MSGBOX_DEFAULT
# 88 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	setvar VAR_TRICK_HOUSE_PRIZE_PICKUP, 0
# 89 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	giveitem ITEM_HARD_STONE
# 90 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	call_if_eq VAR_RESULT, FALSE, Route110_TrickHouseEnd_EventScript_BagFull
# 91 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	msgbox Route110_TrickHouseEnd_Text_MakeNewTricksToStumpYou, MSGBOX_DEFAULT
# 92 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	closemessage
# 93 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	call Route110_TrickHouseEnd_EventScript_TrickMasterExit
# 94 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	release
# 95 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	end
# 96 "data/maps/Route110_TrickHouseEnd/scripts.pory"

# 97 "data/maps/Route110_TrickHouseEnd/scripts.pory"
Route110_TrickHouseEnd_EventScript_CompletedPuzzle4::
# 98 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	msgbox Route110_TrickHouseEnd_Text_AllNightToShoveBoulders, MSGBOX_DEFAULT
# 99 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	msgbox Route110_TrickHouseEnd_Text_YouHaveEarnedThisReward, MSGBOX_DEFAULT
# 100 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	setvar VAR_TRICK_HOUSE_PRIZE_PICKUP, 0
# 101 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	giveitem ITEM_SMOKE_BALL
# 102 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	call_if_eq VAR_RESULT, FALSE, Route110_TrickHouseEnd_EventScript_BagFull
# 103 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	msgbox Route110_TrickHouseEnd_Text_MakeNewTricksToStumpYou, MSGBOX_DEFAULT
# 104 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	closemessage
# 105 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	call Route110_TrickHouseEnd_EventScript_TrickMasterExit
# 106 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	release
# 107 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	end
# 108 "data/maps/Route110_TrickHouseEnd/scripts.pory"

# 109 "data/maps/Route110_TrickHouseEnd/scripts.pory"
Route110_TrickHouseEnd_EventScript_CompletedPuzzle5::
# 110 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	msgbox Route110_TrickHouseEnd_Text_AllNightToMakeMechadolls, MSGBOX_DEFAULT
# 111 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	msgbox Route110_TrickHouseEnd_Text_YouHaveEarnedThisReward, MSGBOX_DEFAULT
# 112 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	setvar VAR_TRICK_HOUSE_PRIZE_PICKUP, 0
# 113 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	giveitem ITEM_TM_TAUNT
# 114 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	call_if_eq VAR_RESULT, FALSE, Route110_TrickHouseEnd_EventScript_BagFull
# 115 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	msgbox Route110_TrickHouseEnd_Text_MakeNewTricksToStumpYou, MSGBOX_DEFAULT
# 116 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	closemessage
# 117 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	call Route110_TrickHouseEnd_EventScript_TrickMasterExit
# 118 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	release
# 119 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	end
# 120 "data/maps/Route110_TrickHouseEnd/scripts.pory"

# 121 "data/maps/Route110_TrickHouseEnd/scripts.pory"
Route110_TrickHouseEnd_EventScript_CompletedPuzzle6::
# 122 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	msgbox Route110_TrickHouseEnd_Text_AllNightToInstallDoors, MSGBOX_DEFAULT
# 123 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	msgbox Route110_TrickHouseEnd_Text_YouHaveEarnedThisReward, MSGBOX_DEFAULT
# 124 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	setvar VAR_TRICK_HOUSE_PRIZE_PICKUP, 0
# 125 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	giveitem ITEM_MAGNET
# 126 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	call_if_eq VAR_RESULT, FALSE, Route110_TrickHouseEnd_EventScript_BagFull
# 127 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	msgbox Route110_TrickHouseEnd_Text_MakeNewTricksToStumpYou, MSGBOX_DEFAULT
# 128 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	closemessage
# 129 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	call Route110_TrickHouseEnd_EventScript_TrickMasterExit
# 130 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	release
# 131 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	end
# 132 "data/maps/Route110_TrickHouseEnd/scripts.pory"

# 133 "data/maps/Route110_TrickHouseEnd/scripts.pory"
Route110_TrickHouseEnd_EventScript_CompletedPuzzle7::
# 134 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	msgbox Route110_TrickHouseEnd_Text_AllNightSettingUpArrows, MSGBOX_DEFAULT
# 135 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	msgbox Route110_TrickHouseEnd_Text_YouHaveEarnedThisReward, MSGBOX_DEFAULT
# 136 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	setvar VAR_TRICK_HOUSE_PRIZE_PICKUP, 0
# 137 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	giveitem ITEM_PP_MAX
# 138 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	call_if_eq VAR_RESULT, FALSE, Route110_TrickHouseEnd_EventScript_BagFull
# 139 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	msgbox Route110_TrickHouseEnd_Text_MakeNewTricksToStumpYou, MSGBOX_DEFAULT
# 140 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	closemessage
# 141 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	call Route110_TrickHouseEnd_EventScript_TrickMasterExit
# 142 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	release
# 143 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	end
# 144 "data/maps/Route110_TrickHouseEnd/scripts.pory"

# 145 "data/maps/Route110_TrickHouseEnd/scripts.pory"
Route110_TrickHouseEnd_EventScript_CompletedPuzzle8::
# 146 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	msgbox Route110_TrickHouseEnd_Text_AllNightPolishingFloors, MSGBOX_DEFAULT
# 147 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	closemessage
# 148 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	call_if_eq VAR_FACING, DIR_SOUTH, Route110_TrickHouseEnd_EventScript_TrickMasterFaceAwaySouth
# 149 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	call_if_eq VAR_FACING, DIR_NORTH, Route110_TrickHouseEnd_EventScript_TrickMasterFaceAwayNorth
# 150 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	call_if_eq VAR_FACING, DIR_WEST, Route110_TrickHouseEnd_EventScript_TrickMasterFaceAwayWest
# 151 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	call_if_eq VAR_FACING, DIR_EAST, Route110_TrickHouseEnd_EventScript_TrickMasterFaceAwayEast
# 152 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	delay 30
# 153 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	msgbox Route110_TrickHouseEnd_Text_FountainOfIdeasRunDry, MSGBOX_DEFAULT
# 154 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	closemessage
# 155 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	applymovement LOCALID_TRICK_MASTER, Common_Movement_FacePlayer
# 156 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	waitmovement 0
# 157 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	delay 30
# 158 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	msgbox Route110_TrickHouseEnd_Text_DefeatedMePreferWhichTent, MSGBOX_DEFAULT
# 159 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	setvar VAR_TRICK_HOUSE_PRIZE_PICKUP, 0
# 160 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	call Route110_TrickHouseEnd_EventScript_ChooseTent
# 161 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	call_if_eq VAR_RESULT, FALSE, Route110_TrickHouseEnd_EventScript_NoRoomForTent
# 162 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	msgbox Route110_TrickHouseEnd_Text_LeavingOnJourney, MSGBOX_DEFAULT
# 163 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	call Route110_TrickHouseEnd_EventScript_TrickMasterExit
# 164 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	special ResetTrickHouseNuggetFlag
# 165 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	release
# 166 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	end
# 167 "data/maps/Route110_TrickHouseEnd/scripts.pory"

# 168 "data/maps/Route110_TrickHouseEnd/scripts.pory"
Route110_TrickHouseEnd_EventScript_ChooseTent::
# 169 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	multichoice 0, 0, MULTI_TENT, TRUE
# 170 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	switch VAR_RESULT
# 171 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	case 0, Route110_TrickHouseEnd_EventScript_GiveRedTent
# 172 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	goto Route110_TrickHouseEnd_EventScript_GiveBlueTent
# 173 "data/maps/Route110_TrickHouseEnd/scripts.pory"

# 174 "data/maps/Route110_TrickHouseEnd/scripts.pory"
Route110_TrickHouseEnd_EventScript_GiveRedTent::
# 175 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	givedecoration DECOR_RED_TENT
# 176 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	return
# 177 "data/maps/Route110_TrickHouseEnd/scripts.pory"

# 178 "data/maps/Route110_TrickHouseEnd/scripts.pory"
Route110_TrickHouseEnd_EventScript_GiveBlueTent::
# 179 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	givedecoration DECOR_BLUE_TENT
# 180 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	return
# 181 "data/maps/Route110_TrickHouseEnd/scripts.pory"

# 182 "data/maps/Route110_TrickHouseEnd/scripts.pory"
Route110_TrickHouseEnd_EventScript_TrickMasterExit::
# 183 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	applymovement LOCALID_TRICK_MASTER, Route110_TrickHouse_Movement_TrickMasterSpin
# 184 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	waitmovement 0
# 185 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	playse SE_M_EXPLOSION
# 186 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	applymovement LOCALID_TRICK_MASTER, Route110_TrickHouse_Movement_TrickMasterJumpAway
# 187 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	waitmovement 0
# 188 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	removeobject LOCALID_TRICK_MASTER
# 189 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	addvar VAR_TRICK_HOUSE_LEVEL, 1
# 190 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	return
# 191 "data/maps/Route110_TrickHouseEnd/scripts.pory"

# 192 "data/maps/Route110_TrickHouseEnd/scripts.pory"
Route110_TrickHouseEnd_EventScript_BagFull::
# 193 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	call Common_EventScript_BagIsFull
# 194 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	msgbox Route110_TrickHouseEnd_Text_NoRoomForThis, MSGBOX_DEFAULT
# 195 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	setvar VAR_TRICK_HOUSE_PRIZE_PICKUP, 1
# 196 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	return
# 197 "data/maps/Route110_TrickHouseEnd/scripts.pory"

# 198 "data/maps/Route110_TrickHouseEnd/scripts.pory"
Route110_TrickHouseEnd_EventScript_NoRoomForTent::
# 199 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	call Common_EventScript_NoRoomForDecor
# 200 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	msgbox Route110_TrickHouseEnd_Text_NoRoomInPC, MSGBOX_DEFAULT
# 201 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	setvar VAR_TRICK_HOUSE_PRIZE_PICKUP, 1
# 202 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	return
# 203 "data/maps/Route110_TrickHouseEnd/scripts.pory"

# 204 "data/maps/Route110_TrickHouseEnd/scripts.pory"
Route110_TrickHouseEnd_EventScript_TrickMasterFaceAwaySouth::
# 205 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	applymovement LOCALID_TRICK_MASTER, Common_Movement_WalkInPlaceFasterDown
# 206 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	waitmovement 0
# 207 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	return
# 208 "data/maps/Route110_TrickHouseEnd/scripts.pory"

# 209 "data/maps/Route110_TrickHouseEnd/scripts.pory"
Route110_TrickHouseEnd_EventScript_TrickMasterFaceAwayNorth::
# 210 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	applymovement LOCALID_TRICK_MASTER, Common_Movement_WalkInPlaceFasterUp
# 211 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	waitmovement 0
# 212 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	return
# 213 "data/maps/Route110_TrickHouseEnd/scripts.pory"

# 214 "data/maps/Route110_TrickHouseEnd/scripts.pory"
Route110_TrickHouseEnd_EventScript_TrickMasterFaceAwayWest::
# 215 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	applymovement LOCALID_TRICK_MASTER, Common_Movement_WalkInPlaceFasterLeft
# 216 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	waitmovement 0
# 217 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	return
# 218 "data/maps/Route110_TrickHouseEnd/scripts.pory"

# 219 "data/maps/Route110_TrickHouseEnd/scripts.pory"
Route110_TrickHouseEnd_EventScript_TrickMasterFaceAwayEast::
# 220 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	applymovement LOCALID_TRICK_MASTER, Common_Movement_WalkInPlaceFasterRight
# 221 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	waitmovement 0
# 222 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	return
# 223 "data/maps/Route110_TrickHouseEnd/scripts.pory"

# 224 "data/maps/Route110_TrickHouseEnd/scripts.pory"
Route110_TrickHouseEnd_EventScript_TrickMasterExitTrigger::
# 225 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	lockall
# 226 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	turnobject LOCALID_TRICK_MASTER, DIR_WEST
# 227 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	playse SE_PIN
# 228 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	applymovement LOCALID_TRICK_MASTER, Common_Movement_ExclamationMark
# 229 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	waitmovement 0
# 230 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	delay 20
# 231 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	applymovement LOCALID_TRICK_MASTER, Route110_TrickHouseEnd_Movement_TrickMasterSurprise
# 232 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	waitmovement 0
# 233 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	playse SE_M_EXPLOSION
# 234 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterDown
# 235 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	waitmovement 0
# 236 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	msgbox Route110_TrickHouseEnd_Text_YoureIgnoringMe, MSGBOX_DEFAULT
# 237 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	closemessage
# 238 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Route110_TrickHouseEnd_Movement_KeepPlayerInRoom
# 239 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	waitmovement 0
# 240 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	delay 4
# 241 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	turnobject LOCALID_TRICK_MASTER, DIR_EAST
# 242 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	releaseall
# 243 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	end
# 244 "data/maps/Route110_TrickHouseEnd/scripts.pory"

# 245 "data/maps/Route110_TrickHouseEnd/scripts.pory"
Route110_TrickHouseEnd_Movement_KeepPlayerInRoom:
# 246 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	walk_down
# 247 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	step_end
# 248 "data/maps/Route110_TrickHouseEnd/scripts.pory"

# 249 "data/maps/Route110_TrickHouseEnd/scripts.pory"
Route110_TrickHouseEnd_Movement_TrickMasterSurprise:
# 250 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	jump_in_place_left
# 251 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	step_end
# 252 "data/maps/Route110_TrickHouseEnd/scripts.pory"

# 253 "data/maps/Route110_TrickHouseEnd/scripts.pory"
Route110_TrickHouseEnd_Text_YouveMadeItToMe:
# 254 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	.string "Aak!\n"
# 255 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	.string "You've made it to me?\l"
# 256 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	.string "Hmmm… You're sharp!$"
# 257 "data/maps/Route110_TrickHouseEnd/scripts.pory"

# 258 "data/maps/Route110_TrickHouseEnd/scripts.pory"
Route110_TrickHouseEnd_Text_AllNightToPlantTrees:
# 259 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	.string "It took me all night to plant all those\n"
# 260 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	.string "trees…\p"
# 261 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	.string "You're almost my equal in greatness by\n"
# 262 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	.string "one, two, three, four, five, six places!$"
# 263 "data/maps/Route110_TrickHouseEnd/scripts.pory"

# 264 "data/maps/Route110_TrickHouseEnd/scripts.pory"
Route110_TrickHouseEnd_Text_AllNightToMakeMaze:
# 265 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	.string "It took me all night to make the maze…\p"
# 266 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	.string "You're almost my equal in greatness by\n"
# 267 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	.string "one, two, three, four, five places!$"
# 268 "data/maps/Route110_TrickHouseEnd/scripts.pory"

# 269 "data/maps/Route110_TrickHouseEnd/scripts.pory"
Route110_TrickHouseEnd_Text_AllNightToPreparePanels:
# 270 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	.string "It took me all night to prepare\n"
# 271 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	.string "the wall panels…\p"
# 272 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	.string "You're almost my equal in greatness by\n"
# 273 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	.string "one, two, three, four places!$"
# 274 "data/maps/Route110_TrickHouseEnd/scripts.pory"

# 275 "data/maps/Route110_TrickHouseEnd/scripts.pory"
Route110_TrickHouseEnd_Text_AllNightToShoveBoulders:
# 276 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	.string "It took me all night to shove in those\n"
# 277 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	.string "boulders…\p"
# 278 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	.string "You're almost my equal in greatness by\n"
# 279 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	.string "one, two, three places!$"
# 280 "data/maps/Route110_TrickHouseEnd/scripts.pory"

# 281 "data/maps/Route110_TrickHouseEnd/scripts.pory"
Route110_TrickHouseEnd_Text_AllNightToMakeMechadolls:
# 282 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	.string "It took me all night to make MECHADOLLS\n"
# 283 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	.string "and another to think up the quiz…\p"
# 284 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	.string "You're almost my equal in greatness by\n"
# 285 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	.string "one, two places!$"
# 286 "data/maps/Route110_TrickHouseEnd/scripts.pory"

# 287 "data/maps/Route110_TrickHouseEnd/scripts.pory"
Route110_TrickHouseEnd_Text_AllNightToInstallDoors:
# 288 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	.string "It took me all night to install\n"
# 289 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	.string "the doors…\p"
# 290 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	.string "You're almost my equal in greatness!$"
# 291 "data/maps/Route110_TrickHouseEnd/scripts.pory"

# 292 "data/maps/Route110_TrickHouseEnd/scripts.pory"
Route110_TrickHouseEnd_Text_AllNightSettingUpArrows:
# 293 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	.string "It took me all night setting up arrows…\p"
# 294 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	.string "You're my equal in greatness!$"
# 295 "data/maps/Route110_TrickHouseEnd/scripts.pory"

# 296 "data/maps/Route110_TrickHouseEnd/scripts.pory"
Route110_TrickHouseEnd_Text_AllNightPolishingFloors:
# 297 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	.string "It took me all night polishing floors…\p"
# 298 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	.string "You're above me in greatness!\n"
# 299 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	.string "Possibly…$"
# 300 "data/maps/Route110_TrickHouseEnd/scripts.pory"

# 301 "data/maps/Route110_TrickHouseEnd/scripts.pory"
Route110_TrickHouseEnd_Text_FountainOfIdeasRunDry:
# 302 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	.string "Wh-what should I do?\n"
# 303 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	.string "My fountain of ideas for tricks has\l"
# 304 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	.string "run dry…\p"
# 305 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	.string "Perhaps it is time I toured the country\n"
# 306 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	.string "on a quest to devise new tricks…$"
# 307 "data/maps/Route110_TrickHouseEnd/scripts.pory"

# 308 "data/maps/Route110_TrickHouseEnd/scripts.pory"
Route110_TrickHouseEnd_Text_DefeatedMePreferWhichTent:
# 309 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	.string "I hate to admit defeat, but you have\n"
# 310 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	.string "bested me!\p"
# 311 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	.string "Still, you must have been reeled in by\n"
# 312 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	.string "my charisma for you to visit me again\l"
# 313 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	.string "and again. Yes, you must have!\p"
# 314 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	.string "But that has nothing to do with my\n"
# 315 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	.string "losing!\p"
# 316 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	.string "In recognition of the friendship\n"
# 317 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	.string "between you, the driven, and the genius\l"
# 318 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	.string "that is myself, I demand that you take\l"
# 319 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	.string "this keepsake!\p"
# 320 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	.string "Actually there are two--\n"
# 321 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	.string "a RED TENT and a BLUE TENT.\l"
# 322 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	.string "Which do you prefer?$"
# 323 "data/maps/Route110_TrickHouseEnd/scripts.pory"

# 324 "data/maps/Route110_TrickHouseEnd/scripts.pory"
Route110_TrickHouseEnd_Text_NoRoomInPC:
# 325 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	.string "What? No room in your PC?\n"
# 326 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	.string "What am I to make of that?\p"
# 327 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	.string "I wish I could say that, but I am much\n"
# 328 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	.string "too kind and caring, so come back later!$"
# 329 "data/maps/Route110_TrickHouseEnd/scripts.pory"

# 330 "data/maps/Route110_TrickHouseEnd/scripts.pory"
Route110_TrickHouseEnd_Text_LeavingOnJourney:
# 331 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	.string "… … … … … …\p"
# 332 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	.string "I am leaving on a journey of discovery.\n"
# 333 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	.string "A quest in search of new tricks.\p"
# 334 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	.string "I wish that you will one day visit and\n"
# 335 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	.string "entertain me again.\p"
# 336 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	.string "And now, farewell!$"
# 337 "data/maps/Route110_TrickHouseEnd/scripts.pory"

# 338 "data/maps/Route110_TrickHouseEnd/scripts.pory"
Route110_TrickHouseEnd_Text_YouHaveEarnedThisReward:
# 339 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	.string "Fine!\n"
# 340 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	.string "You have earned this reward!$"
# 341 "data/maps/Route110_TrickHouseEnd/scripts.pory"

# 342 "data/maps/Route110_TrickHouseEnd/scripts.pory"
Route110_TrickHouseEnd_Text_NoRoomForThis:
# 343 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	.string "What? Have you no room for this?\n"
# 344 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	.string "What manner of items do you carry?\p"
# 345 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	.string "But fine, since you've reached me,\n"
# 346 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	.string "your reward will be with me till later.$"
# 347 "data/maps/Route110_TrickHouseEnd/scripts.pory"

# 348 "data/maps/Route110_TrickHouseEnd/scripts.pory"
Route110_TrickHouseEnd_Text_MakeNewTricksToStumpYou:
# 349 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	.string "Scrub that smug smirk from your face!\n"
# 350 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	.string "It's much too early to think you've won!\p"
# 351 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	.string "I'll make new tricks to stump you, I will.\n"
# 352 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	.string "You may mock me only when you're done.\p"
# 353 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	.string "Come back for the next exciting\n"
# 354 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	.string "installment!$"
# 355 "data/maps/Route110_TrickHouseEnd/scripts.pory"

# 356 "data/maps/Route110_TrickHouseEnd/scripts.pory"
Route110_TrickHouseEnd_Text_YoureIgnoringMe:
# 357 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	.string "Now, now! You're ignoring me now?\n"
# 358 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	.string "Now that, I consider heartbreaking!$"
