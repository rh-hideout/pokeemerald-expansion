# 1 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"

# 2 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"
EverGrandeCity_GlaciasRoom_MapScripts::
# 3 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, EverGrandeCity_GlaciasRoom_OnFrame
# 4 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, EverGrandeCity_GlaciasRoom_OnLoad
# 5 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, EverGrandeCity_GlaciasRoom_OnWarp
# 6 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"
	.byte 0
# 7 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"

# 8 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"
EverGrandeCity_GlaciasRoom_OnWarp:
# 9 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"
	map_script_2 VAR_TEMP_1, 0, EverGrandeCity_GlaciasRoom_EventScript_PlayerTurnNorth
# 10 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"
	.2byte 0
# 11 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"

# 12 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"
EverGrandeCity_GlaciasRoom_EventScript_PlayerTurnNorth::
# 13 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"
	turnobject LOCALID_PLAYER, DIR_NORTH
# 14 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"
	end
# 15 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"

# 16 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"
EverGrandeCity_GlaciasRoom_OnFrame:
# 17 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"
	map_script_2 VAR_ELITE_4_STATE, 2, EverGrandeCity_GlaciasRoom_EventScript_WalkInCloseDoor
# 18 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"
	.2byte 0
# 19 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"

# 20 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"
EverGrandeCity_GlaciasRoom_EventScript_WalkInCloseDoor::
# 21 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"
	lockall
# 22 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"
	call PokemonLeague_EliteFour_EventScript_WalkInCloseDoor
# 23 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"
	setvar VAR_ELITE_4_STATE, 3
# 24 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"
	releaseall
# 25 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"
	end
# 26 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"

# 27 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"
EverGrandeCity_GlaciasRoom_OnLoad:
# 28 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"
	call_if_set FLAG_DEFEATED_ELITE_4_GLACIA, EverGrandeCity_GlaciasRoom_EventScript_ResetAdvanceToNextRoom
# 29 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"
	call_if_eq VAR_ELITE_4_STATE, 3, EverGrandeCity_GlaciasRoom_EventScript_CloseDoor
# 30 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"
	end
# 31 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"

# 32 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"
EverGrandeCity_GlaciasRoom_EventScript_ResetAdvanceToNextRoom::
# 33 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"
	call PokemonLeague_EliteFour_EventScript_ResetAdvanceToNextRoom
# 34 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"
	return
# 35 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"

# 36 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"
EverGrandeCity_GlaciasRoom_EventScript_CloseDoor::
# 37 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"
	call PokemonLeague_EliteFour_EventScript_CloseDoor
# 38 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"
	return
# 39 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"

# 40 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"
EverGrandeCity_GlaciasRoom_EventScript_Glacia::
# 41 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"
	lock
# 42 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"
	faceplayer
# 43 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"
	goto_if_set FLAG_DEFEATED_ELITE_4_GLACIA, EverGrandeCity_GlaciasRoom_EventScript_PostBattleSpeech
# 44 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"
	playbgm MUS_ENCOUNTER_ELITE_FOUR, FALSE
# 45 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"
	msgbox EverGrandeCity_GlaciasRoom_Text_IntroSpeech, MSGBOX_DEFAULT
# 46 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"
	trainerbattle_no_intro TRAINER_GLACIA, EverGrandeCity_GlaciasRoom_Text_Defeat
# 47 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"
	goto EverGrandeCity_GlaciasRoom_EventScript_Defeated
# 48 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"
	end
# 49 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"

# 50 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"
EverGrandeCity_GlaciasRoom_EventScript_PostBattleSpeech::
# 51 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"
	msgbox EverGrandeCity_GlaciasRoom_Text_PostBattleSpeech, MSGBOX_DEFAULT
# 52 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"
	release
# 53 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"
	end
# 54 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"

# 55 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"
EverGrandeCity_GlaciasRoom_EventScript_Defeated::
# 56 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"
	setflag FLAG_DEFEATED_ELITE_4_GLACIA
# 57 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"
	call PokemonLeague_EliteFour_SetAdvanceToNextRoomMetatiles
# 58 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"
	msgbox EverGrandeCity_GlaciasRoom_Text_PostBattleSpeech, MSGBOX_DEFAULT
# 59 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"
	release
# 60 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"
	end
# 61 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"

# 62 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"
EverGrandeCity_GlaciasRoom_Text_IntroSpeech:
# 63 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"
	.string "Welcome, my name is GLACIA\n"
# 64 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"
	.string "of the ELITE FOUR.\p"
# 65 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"
	.string "I've traveled from afar to HOENN\n"
# 66 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"
	.string "so that I may hone my ice skills.\p"
# 67 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"
	.string "But all I have seen are challenges by\n"
# 68 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"
	.string "weak TRAINERS and their POKéMON.\p"
# 69 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"
	.string "What about you?\p"
# 70 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"
	.string "It would please me to no end if I could\n"
# 71 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"
	.string "go all out against you!$"
# 72 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"

# 73 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"
EverGrandeCity_GlaciasRoom_Text_Defeat:
# 74 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"
	.string "You and your POKéMON…\n"
# 75 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"
	.string "How hot your spirits burn!\p"
# 76 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"
	.string "The all-consuming heat overwhelms.\p"
# 77 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"
	.string "It's no surprise that my icy skills\n"
# 78 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"
	.string "failed to harm you.$"
# 79 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"

# 80 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"
EverGrandeCity_GlaciasRoom_Text_PostBattleSpeech:
# 81 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"
	.string "Advance to the next room.\p"
# 82 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"
	.string "And there, confirm the truly fearsome\n"
# 83 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"
	.string "side of the POKéMON LEAGUE.$"
