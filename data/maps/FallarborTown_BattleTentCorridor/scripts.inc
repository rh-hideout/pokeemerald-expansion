# 1 "data/maps/FallarborTown_BattleTentCorridor/scripts.pory"

# 2 "data/maps/FallarborTown_BattleTentCorridor/scripts.pory"
.set LOCALID_ATTENDANT, 1
# 3 "data/maps/FallarborTown_BattleTentCorridor/scripts.pory"

# 4 "data/maps/FallarborTown_BattleTentCorridor/scripts.pory"
FallarborTown_BattleTentCorridor_MapScripts::
# 5 "data/maps/FallarborTown_BattleTentCorridor/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, FallarborTown_BattleTentCorridor_OnFrame
# 6 "data/maps/FallarborTown_BattleTentCorridor/scripts.pory"
	.byte 0
# 7 "data/maps/FallarborTown_BattleTentCorridor/scripts.pory"

# 8 "data/maps/FallarborTown_BattleTentCorridor/scripts.pory"
FallarborTown_BattleTentCorridor_OnFrame:
# 9 "data/maps/FallarborTown_BattleTentCorridor/scripts.pory"
	map_script_2 VAR_TEMP_0, 0, FallarborTown_BattleTentCorridor_EventScript_EnterCorridor
# 10 "data/maps/FallarborTown_BattleTentCorridor/scripts.pory"
	.2byte 0
# 11 "data/maps/FallarborTown_BattleTentCorridor/scripts.pory"

# 12 "data/maps/FallarborTown_BattleTentCorridor/scripts.pory"
FallarborTown_BattleTentCorridor_EventScript_EnterCorridor::
# 13 "data/maps/FallarborTown_BattleTentCorridor/scripts.pory"
	lockall
# 14 "data/maps/FallarborTown_BattleTentCorridor/scripts.pory"
	setvar VAR_TEMP_0, 1
# 15 "data/maps/FallarborTown_BattleTentCorridor/scripts.pory"
	applymovement LOCALID_ATTENDANT, FallarborTown_BattleTentCorridor_Movement_WalkToDoor
# 16 "data/maps/FallarborTown_BattleTentCorridor/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, FallarborTown_BattleTentCorridor_Movement_WalkToDoor
# 17 "data/maps/FallarborTown_BattleTentCorridor/scripts.pory"
	waitmovement 0
# 18 "data/maps/FallarborTown_BattleTentCorridor/scripts.pory"
	opendoor 2, 1
# 19 "data/maps/FallarborTown_BattleTentCorridor/scripts.pory"
	waitdooranim
# 20 "data/maps/FallarborTown_BattleTentCorridor/scripts.pory"
	applymovement LOCALID_ATTENDANT, FallarborTown_BattleTentCorridor_Movement_AttendantEnterDoor
# 21 "data/maps/FallarborTown_BattleTentCorridor/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, FallarborTown_BattleTentCorridor_Movement_PlayerEnterDoor
# 22 "data/maps/FallarborTown_BattleTentCorridor/scripts.pory"
	waitmovement 0
# 23 "data/maps/FallarborTown_BattleTentCorridor/scripts.pory"
	closedoor 2, 1
# 24 "data/maps/FallarborTown_BattleTentCorridor/scripts.pory"
	waitdooranim
# 25 "data/maps/FallarborTown_BattleTentCorridor/scripts.pory"
	setvar VAR_0x8006, 0
# 26 "data/maps/FallarborTown_BattleTentCorridor/scripts.pory"
	warp MAP_FALLARBOR_TOWN_BATTLE_TENT_BATTLE_ROOM, 4, 4
# 27 "data/maps/FallarborTown_BattleTentCorridor/scripts.pory"
	waitstate
# 28 "data/maps/FallarborTown_BattleTentCorridor/scripts.pory"
	releaseall
# 29 "data/maps/FallarborTown_BattleTentCorridor/scripts.pory"
	end
# 30 "data/maps/FallarborTown_BattleTentCorridor/scripts.pory"

# 31 "data/maps/FallarborTown_BattleTentCorridor/scripts.pory"
FallarborTown_BattleTentCorridor_Movement_WalkToDoor:
# 32 "data/maps/FallarborTown_BattleTentCorridor/scripts.pory"
	walk_up
# 33 "data/maps/FallarborTown_BattleTentCorridor/scripts.pory"
	walk_up
# 34 "data/maps/FallarborTown_BattleTentCorridor/scripts.pory"
	walk_up
# 35 "data/maps/FallarborTown_BattleTentCorridor/scripts.pory"
	walk_up
# 36 "data/maps/FallarborTown_BattleTentCorridor/scripts.pory"
	step_end
# 37 "data/maps/FallarborTown_BattleTentCorridor/scripts.pory"

# 38 "data/maps/FallarborTown_BattleTentCorridor/scripts.pory"
FallarborTown_BattleTentCorridor_Movement_PlayerEnterDoor:
# 39 "data/maps/FallarborTown_BattleTentCorridor/scripts.pory"
	walk_up
# 40 "data/maps/FallarborTown_BattleTentCorridor/scripts.pory"
FallarborTown_BattleTentCorridor_Movement_AttendantEnterDoor:
# 41 "data/maps/FallarborTown_BattleTentCorridor/scripts.pory"
	walk_up
# 42 "data/maps/FallarborTown_BattleTentCorridor/scripts.pory"
	set_invisible
# 43 "data/maps/FallarborTown_BattleTentCorridor/scripts.pory"
	step_end
# 44 "data/maps/FallarborTown_BattleTentCorridor/scripts.pory"

# 45 "data/maps/FallarborTown_BattleTentCorridor/scripts.pory"
@ Leftover text from when this was a Contest Hall in R/S
# 46 "data/maps/FallarborTown_BattleTentCorridor/scripts.pory"
@ Unused
# 47 "data/maps/FallarborTown_BattleTentCorridor/scripts.pory"
FallarborTown_ContestHall_Text_DoAllRightInPreliminary:
# 48 "data/maps/FallarborTown_BattleTentCorridor/scripts.pory"
	.string "We do all right in the preliminary round,\n"
# 49 "data/maps/FallarborTown_BattleTentCorridor/scripts.pory"
	.string "but we can never win the appeals…\p"
# 50 "data/maps/FallarborTown_BattleTentCorridor/scripts.pory"
	.string "Maybe it means I have to watch what\n"
# 51 "data/maps/FallarborTown_BattleTentCorridor/scripts.pory"
	.string "other contestants are doing…$"
# 52 "data/maps/FallarborTown_BattleTentCorridor/scripts.pory"

# 53 "data/maps/FallarborTown_BattleTentCorridor/scripts.pory"
@ Unused
# 54 "data/maps/FallarborTown_BattleTentCorridor/scripts.pory"
FallarborTown_ContestHall_Text_MonAllTheseRibbons:
# 55 "data/maps/FallarborTown_BattleTentCorridor/scripts.pory"
	.string "See!\n"
# 56 "data/maps/FallarborTown_BattleTentCorridor/scripts.pory"
	.string "My POKéMON won all these RIBBONS!\p"
# 57 "data/maps/FallarborTown_BattleTentCorridor/scripts.pory"
	.string "Have your POKéMON earned any RIBBONS?\n"
# 58 "data/maps/FallarborTown_BattleTentCorridor/scripts.pory"
	.string "You can check them on your POKéNAV.$"
# 59 "data/maps/FallarborTown_BattleTentCorridor/scripts.pory"

# 60 "data/maps/FallarborTown_BattleTentCorridor/scripts.pory"
@ Unused
# 61 "data/maps/FallarborTown_BattleTentCorridor/scripts.pory"
FallarborTown_ContestHall_Text_CantWinEverywhere:
# 62 "data/maps/FallarborTown_BattleTentCorridor/scripts.pory"
	.string "I can't beat GYM LEADERS…\p"
# 63 "data/maps/FallarborTown_BattleTentCorridor/scripts.pory"
	.string "I can't win any CONTESTS…\p"
# 64 "data/maps/FallarborTown_BattleTentCorridor/scripts.pory"
	.string "I've been here, there, and everywhere,\n"
# 65 "data/maps/FallarborTown_BattleTentCorridor/scripts.pory"
	.string "and it's all for naught…$"
# 66 "data/maps/FallarborTown_BattleTentCorridor/scripts.pory"

# 67 "data/maps/FallarborTown_BattleTentCorridor/scripts.pory"
@ Unused
# 68 "data/maps/FallarborTown_BattleTentCorridor/scripts.pory"
FallarborTown_ContestHall_Text_SuperRankStage:
# 69 "data/maps/FallarborTown_BattleTentCorridor/scripts.pory"
	.string "POKéMON CONTESTS\n"
# 70 "data/maps/FallarborTown_BattleTentCorridor/scripts.pory"
	.string "SUPER RANK STAGE!$"
