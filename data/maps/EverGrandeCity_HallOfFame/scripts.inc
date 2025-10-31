# 1 "data/maps/EverGrandeCity_HallOfFame/scripts.pory"

# 2 "data/maps/EverGrandeCity_HallOfFame/scripts.pory"
EverGrandeCity_HallOfFame_MapScripts::
# 3 "data/maps/EverGrandeCity_HallOfFame/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, EverGrandeCity_HallOfFame_OnFrame
# 4 "data/maps/EverGrandeCity_HallOfFame/scripts.pory"
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, EverGrandeCity_HallOfFame_OnWarp
# 5 "data/maps/EverGrandeCity_HallOfFame/scripts.pory"
	.byte 0
# 6 "data/maps/EverGrandeCity_HallOfFame/scripts.pory"

# 7 "data/maps/EverGrandeCity_HallOfFame/scripts.pory"
EverGrandeCity_HallOfFame_OnWarp:
# 8 "data/maps/EverGrandeCity_HallOfFame/scripts.pory"
	map_script_2 VAR_TEMP_1, 0, EverGrandeCity_HallOfFame_EventScript_TurnPlayerNorth
# 9 "data/maps/EverGrandeCity_HallOfFame/scripts.pory"
	.2byte 0
# 10 "data/maps/EverGrandeCity_HallOfFame/scripts.pory"

# 11 "data/maps/EverGrandeCity_HallOfFame/scripts.pory"
EverGrandeCity_HallOfFame_EventScript_TurnPlayerNorth::
# 12 "data/maps/EverGrandeCity_HallOfFame/scripts.pory"
	turnobject LOCALID_PLAYER, DIR_NORTH
# 13 "data/maps/EverGrandeCity_HallOfFame/scripts.pory"
	end
# 14 "data/maps/EverGrandeCity_HallOfFame/scripts.pory"

# 15 "data/maps/EverGrandeCity_HallOfFame/scripts.pory"
EverGrandeCity_HallOfFame_OnFrame:
# 16 "data/maps/EverGrandeCity_HallOfFame/scripts.pory"
	map_script_2 VAR_TEMP_1, 0, EverGrandeCity_HallOfFame_EventScript_EnterHallOfFame
# 17 "data/maps/EverGrandeCity_HallOfFame/scripts.pory"
	.2byte 0
# 18 "data/maps/EverGrandeCity_HallOfFame/scripts.pory"

# 19 "data/maps/EverGrandeCity_HallOfFame/scripts.pory"
EverGrandeCity_HallOfFame_EventScript_EnterHallOfFame::
# 20 "data/maps/EverGrandeCity_HallOfFame/scripts.pory"
	lockall
# 21 "data/maps/EverGrandeCity_HallOfFame/scripts.pory"
	applymovement LOCALID_HALL_OF_FAME_WALLACE, EverGrandeCity_HallOfFame_Movement_WalkIntoHallOfFame1
# 22 "data/maps/EverGrandeCity_HallOfFame/scripts.pory"
	applymovement LOCALID_PLAYER, EverGrandeCity_HallOfFame_Movement_WalkIntoHallOfFame1
# 23 "data/maps/EverGrandeCity_HallOfFame/scripts.pory"
	waitmovement 0
# 24 "data/maps/EverGrandeCity_HallOfFame/scripts.pory"
	applymovement LOCALID_HALL_OF_FAME_WALLACE, Common_Movement_WalkInPlaceFasterRight
# 25 "data/maps/EverGrandeCity_HallOfFame/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
# 26 "data/maps/EverGrandeCity_HallOfFame/scripts.pory"
	waitmovement 0
# 27 "data/maps/EverGrandeCity_HallOfFame/scripts.pory"
	msgbox EverGrandeCity_HallOfFame_Text_HereWeHonorLeagueChampions, MSGBOX_DEFAULT
# 28 "data/maps/EverGrandeCity_HallOfFame/scripts.pory"
	closemessage
# 29 "data/maps/EverGrandeCity_HallOfFame/scripts.pory"
	applymovement LOCALID_HALL_OF_FAME_WALLACE, EverGrandeCity_HallOfFame_Movement_WalkIntoHallOfFame2
# 30 "data/maps/EverGrandeCity_HallOfFame/scripts.pory"
	applymovement LOCALID_PLAYER, EverGrandeCity_HallOfFame_Movement_WalkIntoHallOfFame2
# 31 "data/maps/EverGrandeCity_HallOfFame/scripts.pory"
	waitmovement 0
# 32 "data/maps/EverGrandeCity_HallOfFame/scripts.pory"
	delay 20
# 33 "data/maps/EverGrandeCity_HallOfFame/scripts.pory"
	applymovement LOCALID_HALL_OF_FAME_WALLACE, Common_Movement_WalkInPlaceFasterRight
# 34 "data/maps/EverGrandeCity_HallOfFame/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
# 35 "data/maps/EverGrandeCity_HallOfFame/scripts.pory"
	waitmovement 0
# 36 "data/maps/EverGrandeCity_HallOfFame/scripts.pory"
	msgbox EverGrandeCity_HallOfFame_Text_LetsRecordYouAndYourPartnersNames, MSGBOX_DEFAULT
# 37 "data/maps/EverGrandeCity_HallOfFame/scripts.pory"
	closemessage
# 38 "data/maps/EverGrandeCity_HallOfFame/scripts.pory"
	applymovement LOCALID_HALL_OF_FAME_WALLACE, Common_Movement_WalkInPlaceFasterUp
# 39 "data/maps/EverGrandeCity_HallOfFame/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
# 40 "data/maps/EverGrandeCity_HallOfFame/scripts.pory"
	waitmovement 0
# 41 "data/maps/EverGrandeCity_HallOfFame/scripts.pory"
	delay 20
# 42 "data/maps/EverGrandeCity_HallOfFame/scripts.pory"
	dofieldeffect FLDEFF_HALL_OF_FAME_RECORD
# 43 "data/maps/EverGrandeCity_HallOfFame/scripts.pory"
	waitfieldeffect FLDEFF_HALL_OF_FAME_RECORD
# 44 "data/maps/EverGrandeCity_HallOfFame/scripts.pory"
	delay 40
# 45 "data/maps/EverGrandeCity_HallOfFame/scripts.pory"
	setvar VAR_TEMP_1, 1
# 46 "data/maps/EverGrandeCity_HallOfFame/scripts.pory"
	call EverGrandeCity_HallOfFame_EventScript_SetGameClearFlags
# 47 "data/maps/EverGrandeCity_HallOfFame/scripts.pory"
	checkplayergender
# 48 "data/maps/EverGrandeCity_HallOfFame/scripts.pory"
	goto_if_eq VAR_RESULT, MALE, EverGrandeCity_HallOfFame_EventScript_GameClearMale
# 49 "data/maps/EverGrandeCity_HallOfFame/scripts.pory"
	goto_if_eq VAR_RESULT, FEMALE, EverGrandeCity_HallOfFame_EventScript_GameClearFemale
# 50 "data/maps/EverGrandeCity_HallOfFame/scripts.pory"
	end
# 51 "data/maps/EverGrandeCity_HallOfFame/scripts.pory"

# 52 "data/maps/EverGrandeCity_HallOfFame/scripts.pory"
EverGrandeCity_HallOfFame_EventScript_GameClearMale::
# 53 "data/maps/EverGrandeCity_HallOfFame/scripts.pory"
	setrespawn HEAL_LOCATION_LITTLEROOT_TOWN_BRENDANS_HOUSE_2F
# 54 "data/maps/EverGrandeCity_HallOfFame/scripts.pory"
	fadescreenspeed FADE_TO_BLACK, 24
# 55 "data/maps/EverGrandeCity_HallOfFame/scripts.pory"
	special GameClear
# 56 "data/maps/EverGrandeCity_HallOfFame/scripts.pory"
	waitstate
# 57 "data/maps/EverGrandeCity_HallOfFame/scripts.pory"
	releaseall
# 58 "data/maps/EverGrandeCity_HallOfFame/scripts.pory"
	end
# 59 "data/maps/EverGrandeCity_HallOfFame/scripts.pory"

# 60 "data/maps/EverGrandeCity_HallOfFame/scripts.pory"
EverGrandeCity_HallOfFame_EventScript_GameClearFemale::
# 61 "data/maps/EverGrandeCity_HallOfFame/scripts.pory"
	setrespawn HEAL_LOCATION_LITTLEROOT_TOWN_MAYS_HOUSE_2F
# 62 "data/maps/EverGrandeCity_HallOfFame/scripts.pory"
	fadescreenspeed FADE_TO_BLACK, 24
# 63 "data/maps/EverGrandeCity_HallOfFame/scripts.pory"
	special GameClear
# 64 "data/maps/EverGrandeCity_HallOfFame/scripts.pory"
	waitstate
# 65 "data/maps/EverGrandeCity_HallOfFame/scripts.pory"
	releaseall
# 66 "data/maps/EverGrandeCity_HallOfFame/scripts.pory"
	end
# 67 "data/maps/EverGrandeCity_HallOfFame/scripts.pory"

# 68 "data/maps/EverGrandeCity_HallOfFame/scripts.pory"
EverGrandeCity_HallOfFame_Movement_WalkIntoHallOfFame1:
# 69 "data/maps/EverGrandeCity_HallOfFame/scripts.pory"
	walk_up
# 70 "data/maps/EverGrandeCity_HallOfFame/scripts.pory"
	walk_up
# 71 "data/maps/EverGrandeCity_HallOfFame/scripts.pory"
	walk_up
# 72 "data/maps/EverGrandeCity_HallOfFame/scripts.pory"
	walk_up
# 73 "data/maps/EverGrandeCity_HallOfFame/scripts.pory"
	walk_up
# 74 "data/maps/EverGrandeCity_HallOfFame/scripts.pory"
	walk_up
# 75 "data/maps/EverGrandeCity_HallOfFame/scripts.pory"
	step_end
# 76 "data/maps/EverGrandeCity_HallOfFame/scripts.pory"

# 77 "data/maps/EverGrandeCity_HallOfFame/scripts.pory"
EverGrandeCity_HallOfFame_Movement_WalkIntoHallOfFame2:
# 78 "data/maps/EverGrandeCity_HallOfFame/scripts.pory"
	walk_up
# 79 "data/maps/EverGrandeCity_HallOfFame/scripts.pory"
	walk_up
# 80 "data/maps/EverGrandeCity_HallOfFame/scripts.pory"
	walk_up
# 81 "data/maps/EverGrandeCity_HallOfFame/scripts.pory"
	walk_up
# 82 "data/maps/EverGrandeCity_HallOfFame/scripts.pory"
	walk_up
# 83 "data/maps/EverGrandeCity_HallOfFame/scripts.pory"
	step_end
# 84 "data/maps/EverGrandeCity_HallOfFame/scripts.pory"

# 85 "data/maps/EverGrandeCity_HallOfFame/scripts.pory"
EverGrandeCity_HallOfFame_Text_HereWeHonorLeagueChampions:
# 86 "data/maps/EverGrandeCity_HallOfFame/scripts.pory"
	.string "WALLACE: This room…\p"
# 87 "data/maps/EverGrandeCity_HallOfFame/scripts.pory"
	.string "This is where we keep records of\n"
# 88 "data/maps/EverGrandeCity_HallOfFame/scripts.pory"
	.string "POKéMON that prevailed through\l"
# 89 "data/maps/EverGrandeCity_HallOfFame/scripts.pory"
	.string "harsh battles.\p"
# 90 "data/maps/EverGrandeCity_HallOfFame/scripts.pory"
	.string "It is here that the LEAGUE CHAMPIONS\n"
# 91 "data/maps/EverGrandeCity_HallOfFame/scripts.pory"
	.string "are honored.$"
# 92 "data/maps/EverGrandeCity_HallOfFame/scripts.pory"

# 93 "data/maps/EverGrandeCity_HallOfFame/scripts.pory"
EverGrandeCity_HallOfFame_Text_LetsRecordYouAndYourPartnersNames:
# 94 "data/maps/EverGrandeCity_HallOfFame/scripts.pory"
	.string "WALLACE: Come on, let's record your\n"
# 95 "data/maps/EverGrandeCity_HallOfFame/scripts.pory"
	.string "name as a TRAINER who triumphed over\l"
# 96 "data/maps/EverGrandeCity_HallOfFame/scripts.pory"
	.string "the POKéMON LEAGUE, and the names of\l"
# 97 "data/maps/EverGrandeCity_HallOfFame/scripts.pory"
	.string "the partners who battled with you.$"
