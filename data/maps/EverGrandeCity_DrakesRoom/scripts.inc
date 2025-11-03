# 1 "data/maps/EverGrandeCity_DrakesRoom/scripts.pory"

# 2 "data/maps/EverGrandeCity_DrakesRoom/scripts.pory"
EverGrandeCity_DrakesRoom_MapScripts::
# 3 "data/maps/EverGrandeCity_DrakesRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, EverGrandeCity_DrakesRoom_OnFrame
# 4 "data/maps/EverGrandeCity_DrakesRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, EverGrandeCity_DrakesRoom_OnLoad
# 5 "data/maps/EverGrandeCity_DrakesRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, EverGrandeCity_SidneysRoom_OnWarp
# 6 "data/maps/EverGrandeCity_DrakesRoom/scripts.pory"
	.byte 0
# 7 "data/maps/EverGrandeCity_DrakesRoom/scripts.pory"

# 8 "data/maps/EverGrandeCity_DrakesRoom/scripts.pory"
@ Unused, Drake uses Sidneys identical OnWarp for some reason
# 9 "data/maps/EverGrandeCity_DrakesRoom/scripts.pory"
EverGrandeCity_DrakesRoom_OnWarp:
# 10 "data/maps/EverGrandeCity_DrakesRoom/scripts.pory"
	map_script_2 VAR_TEMP_1, 0, EverGrandeCity_DrakesRoom_EventScript_PlayerTurnNorth
# 11 "data/maps/EverGrandeCity_DrakesRoom/scripts.pory"
	.2byte 0
# 12 "data/maps/EverGrandeCity_DrakesRoom/scripts.pory"

# 13 "data/maps/EverGrandeCity_DrakesRoom/scripts.pory"
EverGrandeCity_DrakesRoom_EventScript_PlayerTurnNorth::
# 14 "data/maps/EverGrandeCity_DrakesRoom/scripts.pory"
	turnobject LOCALID_PLAYER, DIR_NORTH
# 15 "data/maps/EverGrandeCity_DrakesRoom/scripts.pory"
	end
# 16 "data/maps/EverGrandeCity_DrakesRoom/scripts.pory"

# 17 "data/maps/EverGrandeCity_DrakesRoom/scripts.pory"
EverGrandeCity_DrakesRoom_OnFrame:
# 18 "data/maps/EverGrandeCity_DrakesRoom/scripts.pory"
	map_script_2 VAR_ELITE_4_STATE, 3, EverGrandeCity_DrakesRoom_EventScript_WalkInCloseDoor
# 19 "data/maps/EverGrandeCity_DrakesRoom/scripts.pory"
	.2byte 0
# 20 "data/maps/EverGrandeCity_DrakesRoom/scripts.pory"

# 21 "data/maps/EverGrandeCity_DrakesRoom/scripts.pory"
EverGrandeCity_DrakesRoom_EventScript_WalkInCloseDoor::
# 22 "data/maps/EverGrandeCity_DrakesRoom/scripts.pory"
	lockall
# 23 "data/maps/EverGrandeCity_DrakesRoom/scripts.pory"
	call PokemonLeague_EliteFour_EventScript_WalkInCloseDoor
# 24 "data/maps/EverGrandeCity_DrakesRoom/scripts.pory"
	setvar VAR_ELITE_4_STATE, 4
# 25 "data/maps/EverGrandeCity_DrakesRoom/scripts.pory"
	releaseall
# 26 "data/maps/EverGrandeCity_DrakesRoom/scripts.pory"
	end
# 27 "data/maps/EverGrandeCity_DrakesRoom/scripts.pory"

# 28 "data/maps/EverGrandeCity_DrakesRoom/scripts.pory"
EverGrandeCity_DrakesRoom_OnLoad:
# 29 "data/maps/EverGrandeCity_DrakesRoom/scripts.pory"
	call_if_set FLAG_DEFEATED_ELITE_4_DRAKE, EverGrandeCity_DrakesRoom_EventScript_ResetAdvanceToNextRoom
# 30 "data/maps/EverGrandeCity_DrakesRoom/scripts.pory"
	call_if_eq VAR_ELITE_4_STATE, 4, EverGrandeCity_DrakesRoom_EventScript_CloseDoor
# 31 "data/maps/EverGrandeCity_DrakesRoom/scripts.pory"
	end
# 32 "data/maps/EverGrandeCity_DrakesRoom/scripts.pory"

# 33 "data/maps/EverGrandeCity_DrakesRoom/scripts.pory"
EverGrandeCity_DrakesRoom_EventScript_ResetAdvanceToNextRoom::
# 34 "data/maps/EverGrandeCity_DrakesRoom/scripts.pory"
	call PokemonLeague_EliteFour_EventScript_ResetAdvanceToNextRoom
# 35 "data/maps/EverGrandeCity_DrakesRoom/scripts.pory"
	return
# 36 "data/maps/EverGrandeCity_DrakesRoom/scripts.pory"

# 37 "data/maps/EverGrandeCity_DrakesRoom/scripts.pory"
EverGrandeCity_DrakesRoom_EventScript_CloseDoor::
# 38 "data/maps/EverGrandeCity_DrakesRoom/scripts.pory"
	call PokemonLeague_EliteFour_EventScript_CloseDoor
# 39 "data/maps/EverGrandeCity_DrakesRoom/scripts.pory"
	return
# 40 "data/maps/EverGrandeCity_DrakesRoom/scripts.pory"

# 41 "data/maps/EverGrandeCity_DrakesRoom/scripts.pory"
EverGrandeCity_DrakesRoom_EventScript_Drake::
# 42 "data/maps/EverGrandeCity_DrakesRoom/scripts.pory"
	lock
# 43 "data/maps/EverGrandeCity_DrakesRoom/scripts.pory"
	faceplayer
# 44 "data/maps/EverGrandeCity_DrakesRoom/scripts.pory"
	goto_if_set FLAG_DEFEATED_ELITE_4_DRAKE, EverGrandeCity_DrakesRoom_EventScript_PostBattleSpeech
# 45 "data/maps/EverGrandeCity_DrakesRoom/scripts.pory"
	playbgm MUS_ENCOUNTER_ELITE_FOUR, FALSE
# 46 "data/maps/EverGrandeCity_DrakesRoom/scripts.pory"
	msgbox EverGrandeCity_DrakesRoom_Text_IntroSpeech, MSGBOX_DEFAULT
# 47 "data/maps/EverGrandeCity_DrakesRoom/scripts.pory"
	trainerbattle_no_intro TRAINER_DRAKE, EverGrandeCity_DrakesRoom_Text_Defeat
# 48 "data/maps/EverGrandeCity_DrakesRoom/scripts.pory"
	goto EverGrandeCity_DrakesRoom_EventScript_Defeated
# 49 "data/maps/EverGrandeCity_DrakesRoom/scripts.pory"
	end
# 50 "data/maps/EverGrandeCity_DrakesRoom/scripts.pory"

# 51 "data/maps/EverGrandeCity_DrakesRoom/scripts.pory"
EverGrandeCity_DrakesRoom_EventScript_PostBattleSpeech::
# 52 "data/maps/EverGrandeCity_DrakesRoom/scripts.pory"
	msgbox EverGrandeCity_DrakesRoom_Text_PostBattleSpeech, MSGBOX_DEFAULT
# 53 "data/maps/EverGrandeCity_DrakesRoom/scripts.pory"
	release
# 54 "data/maps/EverGrandeCity_DrakesRoom/scripts.pory"
	end
# 55 "data/maps/EverGrandeCity_DrakesRoom/scripts.pory"

# 56 "data/maps/EverGrandeCity_DrakesRoom/scripts.pory"
EverGrandeCity_DrakesRoom_EventScript_Defeated::
# 57 "data/maps/EverGrandeCity_DrakesRoom/scripts.pory"
	setvar VAR_0x8004, FANCOUNTER_DEFEATED_DRAKE
# 58 "data/maps/EverGrandeCity_DrakesRoom/scripts.pory"
	special Script_TryGainNewFanFromCounter
# 59 "data/maps/EverGrandeCity_DrakesRoom/scripts.pory"
	setflag FLAG_DEFEATED_ELITE_4_DRAKE
# 60 "data/maps/EverGrandeCity_DrakesRoom/scripts.pory"
	call PokemonLeague_EliteFour_SetAdvanceToNextRoomMetatiles
# 61 "data/maps/EverGrandeCity_DrakesRoom/scripts.pory"
	msgbox EverGrandeCity_DrakesRoom_Text_PostBattleSpeech, MSGBOX_DEFAULT
# 62 "data/maps/EverGrandeCity_DrakesRoom/scripts.pory"
	release
# 63 "data/maps/EverGrandeCity_DrakesRoom/scripts.pory"
	end
# 64 "data/maps/EverGrandeCity_DrakesRoom/scripts.pory"

# 65 "data/maps/EverGrandeCity_DrakesRoom/scripts.pory"
EverGrandeCity_DrakesRoom_Text_IntroSpeech:
# 66 "data/maps/EverGrandeCity_DrakesRoom/scripts.pory"
	.string "I am the last of the POKéMON LEAGUE\n"
# 67 "data/maps/EverGrandeCity_DrakesRoom/scripts.pory"
	.string "ELITE FOUR, DRAKE the DRAGON master!\p"
# 68 "data/maps/EverGrandeCity_DrakesRoom/scripts.pory"
	.string "In their natural state, POKéMON are\n"
# 69 "data/maps/EverGrandeCity_DrakesRoom/scripts.pory"
	.string "wild living things. They are free.\p"
# 70 "data/maps/EverGrandeCity_DrakesRoom/scripts.pory"
	.string "At times, they hinder us.\n"
# 71 "data/maps/EverGrandeCity_DrakesRoom/scripts.pory"
	.string "At times, they help us.\p"
# 72 "data/maps/EverGrandeCity_DrakesRoom/scripts.pory"
	.string "For us to battle with POKéMON as\n"
# 73 "data/maps/EverGrandeCity_DrakesRoom/scripts.pory"
	.string "partners, do you know what it takes?\p"
# 74 "data/maps/EverGrandeCity_DrakesRoom/scripts.pory"
	.string "Do you know what is needed?\p"
# 75 "data/maps/EverGrandeCity_DrakesRoom/scripts.pory"
	.string "If you don't, then you will never\n"
# 76 "data/maps/EverGrandeCity_DrakesRoom/scripts.pory"
	.string "prevail over me!$"
# 77 "data/maps/EverGrandeCity_DrakesRoom/scripts.pory"

# 78 "data/maps/EverGrandeCity_DrakesRoom/scripts.pory"
EverGrandeCity_DrakesRoom_Text_Defeat:
# 79 "data/maps/EverGrandeCity_DrakesRoom/scripts.pory"
	.string "Superb, it should be said.$"
# 80 "data/maps/EverGrandeCity_DrakesRoom/scripts.pory"

# 81 "data/maps/EverGrandeCity_DrakesRoom/scripts.pory"
EverGrandeCity_DrakesRoom_Text_PostBattleSpeech:
# 82 "data/maps/EverGrandeCity_DrakesRoom/scripts.pory"
	.string "You deserve every credit for coming\n"
# 83 "data/maps/EverGrandeCity_DrakesRoom/scripts.pory"
	.string "this far as a TRAINER of POKéMON.\p"
# 84 "data/maps/EverGrandeCity_DrakesRoom/scripts.pory"
	.string "You do seem to know what is needed.\p"
# 85 "data/maps/EverGrandeCity_DrakesRoom/scripts.pory"
	.string "Yes, what a TRAINER needs is a\n"
# 86 "data/maps/EverGrandeCity_DrakesRoom/scripts.pory"
	.string "virtuous heart.\p"
# 87 "data/maps/EverGrandeCity_DrakesRoom/scripts.pory"
	.string "POKéMON touch the good hearts of\n"
# 88 "data/maps/EverGrandeCity_DrakesRoom/scripts.pory"
	.string "TRAINERS and learn good from wrong.\p"
# 89 "data/maps/EverGrandeCity_DrakesRoom/scripts.pory"
	.string "They touch the good hearts of\n"
# 90 "data/maps/EverGrandeCity_DrakesRoom/scripts.pory"
	.string "TRAINERS and grow strong.\p"
# 91 "data/maps/EverGrandeCity_DrakesRoom/scripts.pory"
	.string "Go! Go onwards!\n"
# 92 "data/maps/EverGrandeCity_DrakesRoom/scripts.pory"
	.string "The CHAMPION is waiting!$"
