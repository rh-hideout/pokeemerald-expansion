# 1 "data/maps/VerdanturfTown_BattleTentCorridor/scripts.pory"

# 2 "data/maps/VerdanturfTown_BattleTentCorridor/scripts.pory"
VerdanturfTown_BattleTentCorridor_MapScripts::
# 3 "data/maps/VerdanturfTown_BattleTentCorridor/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, VerdanturfTown_BattleTentCorridor_OnFrame
# 4 "data/maps/VerdanturfTown_BattleTentCorridor/scripts.pory"
	.byte 0
# 5 "data/maps/VerdanturfTown_BattleTentCorridor/scripts.pory"

# 6 "data/maps/VerdanturfTown_BattleTentCorridor/scripts.pory"
VerdanturfTown_BattleTentCorridor_OnFrame:
# 7 "data/maps/VerdanturfTown_BattleTentCorridor/scripts.pory"
	map_script_2 VAR_TEMP_0, 0, VerdanturfTown_BattleTentCorridor_EventScript_EnterCorridor
# 8 "data/maps/VerdanturfTown_BattleTentCorridor/scripts.pory"
	.2byte 0
# 9 "data/maps/VerdanturfTown_BattleTentCorridor/scripts.pory"

# 10 "data/maps/VerdanturfTown_BattleTentCorridor/scripts.pory"
VerdanturfTown_BattleTentCorridor_EventScript_EnterCorridor::
# 11 "data/maps/VerdanturfTown_BattleTentCorridor/scripts.pory"
	lockall
# 12 "data/maps/VerdanturfTown_BattleTentCorridor/scripts.pory"
	setvar VAR_TEMP_0, 1
# 13 "data/maps/VerdanturfTown_BattleTentCorridor/scripts.pory"
	applymovement LOCALID_VERDANTURF_TENT_CORRIDOR_ATTENDANT, VerdanturfTown_BattleTentCorridor_Movement_WalkToDoor
# 14 "data/maps/VerdanturfTown_BattleTentCorridor/scripts.pory"
	applymovement LOCALID_PLAYER, VerdanturfTown_BattleTentCorridor_Movement_WalkToDoor
# 15 "data/maps/VerdanturfTown_BattleTentCorridor/scripts.pory"
	waitmovement 0
# 16 "data/maps/VerdanturfTown_BattleTentCorridor/scripts.pory"
	opendoor 2, 1
# 17 "data/maps/VerdanturfTown_BattleTentCorridor/scripts.pory"
	waitdooranim
# 18 "data/maps/VerdanturfTown_BattleTentCorridor/scripts.pory"
	applymovement LOCALID_VERDANTURF_TENT_CORRIDOR_ATTENDANT, VerdanturfTown_BattleTentCorridor_Movement_AttendantEnterDoor
# 19 "data/maps/VerdanturfTown_BattleTentCorridor/scripts.pory"
	applymovement LOCALID_PLAYER, VerdanturfTown_BattleTentCorridor_Movement_PlayerEnterDoor
# 20 "data/maps/VerdanturfTown_BattleTentCorridor/scripts.pory"
	waitmovement 0
# 21 "data/maps/VerdanturfTown_BattleTentCorridor/scripts.pory"
	closedoor 2, 1
# 22 "data/maps/VerdanturfTown_BattleTentCorridor/scripts.pory"
	waitdooranim
# 23 "data/maps/VerdanturfTown_BattleTentCorridor/scripts.pory"
	setvar VAR_0x8006, 0
# 24 "data/maps/VerdanturfTown_BattleTentCorridor/scripts.pory"
	warp MAP_VERDANTURF_TOWN_BATTLE_TENT_BATTLE_ROOM, 6, 5
# 25 "data/maps/VerdanturfTown_BattleTentCorridor/scripts.pory"
	waitstate
# 26 "data/maps/VerdanturfTown_BattleTentCorridor/scripts.pory"
	releaseall
# 27 "data/maps/VerdanturfTown_BattleTentCorridor/scripts.pory"
	end
# 28 "data/maps/VerdanturfTown_BattleTentCorridor/scripts.pory"

# 29 "data/maps/VerdanturfTown_BattleTentCorridor/scripts.pory"
VerdanturfTown_BattleTentCorridor_Movement_WalkToDoor:
# 30 "data/maps/VerdanturfTown_BattleTentCorridor/scripts.pory"
	walk_up
# 31 "data/maps/VerdanturfTown_BattleTentCorridor/scripts.pory"
	walk_up
# 32 "data/maps/VerdanturfTown_BattleTentCorridor/scripts.pory"
	walk_up
# 33 "data/maps/VerdanturfTown_BattleTentCorridor/scripts.pory"
	walk_up
# 34 "data/maps/VerdanturfTown_BattleTentCorridor/scripts.pory"
	step_end
# 35 "data/maps/VerdanturfTown_BattleTentCorridor/scripts.pory"

# 36 "data/maps/VerdanturfTown_BattleTentCorridor/scripts.pory"
VerdanturfTown_BattleTentCorridor_Movement_PlayerEnterDoor:
# 37 "data/maps/VerdanturfTown_BattleTentCorridor/scripts.pory"
	walk_up
# 38 "data/maps/VerdanturfTown_BattleTentCorridor/scripts.pory"
VerdanturfTown_BattleTentCorridor_Movement_AttendantEnterDoor:
# 39 "data/maps/VerdanturfTown_BattleTentCorridor/scripts.pory"
	walk_up
# 40 "data/maps/VerdanturfTown_BattleTentCorridor/scripts.pory"
	set_invisible
# 41 "data/maps/VerdanturfTown_BattleTentCorridor/scripts.pory"
	step_end
# 42 "data/maps/VerdanturfTown_BattleTentCorridor/scripts.pory"

# 43 "data/maps/VerdanturfTown_BattleTentCorridor/scripts.pory"

# 44 "data/maps/VerdanturfTown_BattleTentCorridor/scripts.pory"
@ Leftover text from when this was a Contest Hall in R/S
# 45 "data/maps/VerdanturfTown_BattleTentCorridor/scripts.pory"
@ Unused
# 46 "data/maps/VerdanturfTown_BattleTentCorridor/scripts.pory"
VerdanturfTown_ContestHall_Text_WhichContestYouEntering:
# 47 "data/maps/VerdanturfTown_BattleTentCorridor/scripts.pory"
	.string "Which CONTEST are you entering?\n"
# 48 "data/maps/VerdanturfTown_BattleTentCorridor/scripts.pory"
	.string "Want a piece of advice?\p"
# 49 "data/maps/VerdanturfTown_BattleTentCorridor/scripts.pory"
	.string "In any CONTEST, for example, a CUTE\n"
# 50 "data/maps/VerdanturfTown_BattleTentCorridor/scripts.pory"
	.string "CONTEST, I don't think they judge you\l"
# 51 "data/maps/VerdanturfTown_BattleTentCorridor/scripts.pory"
	.string "only on cuteness in the first round.\p"
# 52 "data/maps/VerdanturfTown_BattleTentCorridor/scripts.pory"
	.string "You need to work out ways for raising\n"
# 53 "data/maps/VerdanturfTown_BattleTentCorridor/scripts.pory"
	.string "POKéMON better.$"
# 54 "data/maps/VerdanturfTown_BattleTentCorridor/scripts.pory"

# 55 "data/maps/VerdanturfTown_BattleTentCorridor/scripts.pory"
@ Unused
# 56 "data/maps/VerdanturfTown_BattleTentCorridor/scripts.pory"
VerdanturfTown_ContestHall_Text_RaisedMonToBeCute:
# 57 "data/maps/VerdanturfTown_BattleTentCorridor/scripts.pory"
	.string "I raised my POKéMON to be cute.\p"
# 58 "data/maps/VerdanturfTown_BattleTentCorridor/scripts.pory"
	.string "I found out you can put POKéMON in\n"
# 59 "data/maps/VerdanturfTown_BattleTentCorridor/scripts.pory"
	.string "a CONTEST for cuteness!\p"
# 60 "data/maps/VerdanturfTown_BattleTentCorridor/scripts.pory"
	.string "I'm so glad I raised my POKéMON with\n"
# 61 "data/maps/VerdanturfTown_BattleTentCorridor/scripts.pory"
	.string "loving care…$"
# 62 "data/maps/VerdanturfTown_BattleTentCorridor/scripts.pory"

# 63 "data/maps/VerdanturfTown_BattleTentCorridor/scripts.pory"
@ Unused
# 64 "data/maps/VerdanturfTown_BattleTentCorridor/scripts.pory"
VerdanturfTown_ContestHall_Text_MyMonRules:
# 65 "data/maps/VerdanturfTown_BattleTentCorridor/scripts.pory"
	.string "My POKéMON rules!\p"
# 66 "data/maps/VerdanturfTown_BattleTentCorridor/scripts.pory"
	.string "It's cool, tough yet beautiful, cute,\n"
# 67 "data/maps/VerdanturfTown_BattleTentCorridor/scripts.pory"
	.string "and smart. It's complete!\p"
# 68 "data/maps/VerdanturfTown_BattleTentCorridor/scripts.pory"
	.string "I may as well go for wins in every\n"
# 69 "data/maps/VerdanturfTown_BattleTentCorridor/scripts.pory"
	.string "single CONTEST.$"
# 70 "data/maps/VerdanturfTown_BattleTentCorridor/scripts.pory"

# 71 "data/maps/VerdanturfTown_BattleTentCorridor/scripts.pory"
@ Unused
# 72 "data/maps/VerdanturfTown_BattleTentCorridor/scripts.pory"
VerdanturfTown_ContestHall_Text_NormalRankStage:
# 73 "data/maps/VerdanturfTown_BattleTentCorridor/scripts.pory"
	.string "POKéMON CONTESTS\n"
# 74 "data/maps/VerdanturfTown_BattleTentCorridor/scripts.pory"
	.string "NORMAL RANK STAGE!$"
