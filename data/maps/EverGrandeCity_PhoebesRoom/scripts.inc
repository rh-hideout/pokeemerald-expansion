# 1 "data/maps/EverGrandeCity_PhoebesRoom/scripts.pory"

# 2 "data/maps/EverGrandeCity_PhoebesRoom/scripts.pory"
EverGrandeCity_PhoebesRoom_MapScripts::
# 3 "data/maps/EverGrandeCity_PhoebesRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, EverGrandeCity_PhoebesRoom_OnLoad
# 4 "data/maps/EverGrandeCity_PhoebesRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, EverGrandeCity_PhoebesRoom_OnWarp
# 5 "data/maps/EverGrandeCity_PhoebesRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, EverGrandeCity_PhoebesRoom_OnFrame
# 6 "data/maps/EverGrandeCity_PhoebesRoom/scripts.pory"
	.byte 0
# 7 "data/maps/EverGrandeCity_PhoebesRoom/scripts.pory"

# 8 "data/maps/EverGrandeCity_PhoebesRoom/scripts.pory"
EverGrandeCity_PhoebesRoom_OnWarp:
# 9 "data/maps/EverGrandeCity_PhoebesRoom/scripts.pory"
	map_script_2 VAR_TEMP_1, 0, EverGrandeCity_PhoebesRoom_EventScript_PlayerTurnNorth
# 10 "data/maps/EverGrandeCity_PhoebesRoom/scripts.pory"
	.2byte 0
# 11 "data/maps/EverGrandeCity_PhoebesRoom/scripts.pory"

# 12 "data/maps/EverGrandeCity_PhoebesRoom/scripts.pory"
EverGrandeCity_PhoebesRoom_EventScript_PlayerTurnNorth::
# 13 "data/maps/EverGrandeCity_PhoebesRoom/scripts.pory"
	turnobject LOCALID_PLAYER, DIR_NORTH
# 14 "data/maps/EverGrandeCity_PhoebesRoom/scripts.pory"
	end
# 15 "data/maps/EverGrandeCity_PhoebesRoom/scripts.pory"

# 16 "data/maps/EverGrandeCity_PhoebesRoom/scripts.pory"
EverGrandeCity_PhoebesRoom_OnFrame:
# 17 "data/maps/EverGrandeCity_PhoebesRoom/scripts.pory"
	map_script_2 VAR_ELITE_4_STATE, 1, EverGrandeCity_PhoebesRoom_EventScript_WalkInCloseDoor
# 18 "data/maps/EverGrandeCity_PhoebesRoom/scripts.pory"
	.2byte 0
# 19 "data/maps/EverGrandeCity_PhoebesRoom/scripts.pory"

# 20 "data/maps/EverGrandeCity_PhoebesRoom/scripts.pory"
EverGrandeCity_PhoebesRoom_EventScript_WalkInCloseDoor::
# 21 "data/maps/EverGrandeCity_PhoebesRoom/scripts.pory"
	lockall
# 22 "data/maps/EverGrandeCity_PhoebesRoom/scripts.pory"
	call PokemonLeague_EliteFour_EventScript_WalkInCloseDoor
# 23 "data/maps/EverGrandeCity_PhoebesRoom/scripts.pory"
	setvar VAR_ELITE_4_STATE, 2
# 24 "data/maps/EverGrandeCity_PhoebesRoom/scripts.pory"
	releaseall
# 25 "data/maps/EverGrandeCity_PhoebesRoom/scripts.pory"
	end
# 26 "data/maps/EverGrandeCity_PhoebesRoom/scripts.pory"

# 27 "data/maps/EverGrandeCity_PhoebesRoom/scripts.pory"
EverGrandeCity_PhoebesRoom_OnLoad:
# 28 "data/maps/EverGrandeCity_PhoebesRoom/scripts.pory"
	call_if_set FLAG_DEFEATED_ELITE_4_PHOEBE, EverGrandeCity_PhoebesRoom_EventScript_ResetAdvanceToNextRoom
# 29 "data/maps/EverGrandeCity_PhoebesRoom/scripts.pory"
	call_if_eq VAR_ELITE_4_STATE, 2, EverGrandeCity_PhoebesRoom_EventScript_CloseDoor
# 30 "data/maps/EverGrandeCity_PhoebesRoom/scripts.pory"
	end
# 31 "data/maps/EverGrandeCity_PhoebesRoom/scripts.pory"

# 32 "data/maps/EverGrandeCity_PhoebesRoom/scripts.pory"
EverGrandeCity_PhoebesRoom_EventScript_ResetAdvanceToNextRoom::
# 33 "data/maps/EverGrandeCity_PhoebesRoom/scripts.pory"
	call PokemonLeague_EliteFour_EventScript_ResetAdvanceToNextRoom
# 34 "data/maps/EverGrandeCity_PhoebesRoom/scripts.pory"
	return
# 35 "data/maps/EverGrandeCity_PhoebesRoom/scripts.pory"

# 36 "data/maps/EverGrandeCity_PhoebesRoom/scripts.pory"
EverGrandeCity_PhoebesRoom_EventScript_CloseDoor::
# 37 "data/maps/EverGrandeCity_PhoebesRoom/scripts.pory"
	call PokemonLeague_EliteFour_EventScript_CloseDoor
# 38 "data/maps/EverGrandeCity_PhoebesRoom/scripts.pory"
	return
# 39 "data/maps/EverGrandeCity_PhoebesRoom/scripts.pory"

# 40 "data/maps/EverGrandeCity_PhoebesRoom/scripts.pory"
EverGrandeCity_PhoebesRoom_EventScript_Phoebe::
# 41 "data/maps/EverGrandeCity_PhoebesRoom/scripts.pory"
	lock
# 42 "data/maps/EverGrandeCity_PhoebesRoom/scripts.pory"
	faceplayer
# 43 "data/maps/EverGrandeCity_PhoebesRoom/scripts.pory"
	goto_if_set FLAG_DEFEATED_ELITE_4_PHOEBE, EverGrandeCity_PhoebesRoom_EventScript_PostBattleSpeech
# 44 "data/maps/EverGrandeCity_PhoebesRoom/scripts.pory"
	playbgm MUS_ENCOUNTER_ELITE_FOUR, FALSE
# 45 "data/maps/EverGrandeCity_PhoebesRoom/scripts.pory"
	msgbox EverGrandeCity_PhoebesRoom_Text_IntroSpeech, MSGBOX_DEFAULT
# 46 "data/maps/EverGrandeCity_PhoebesRoom/scripts.pory"
	trainerbattle_no_intro TRAINER_PHOEBE, EverGrandeCity_PhoebesRoom_Text_Defeat
# 47 "data/maps/EverGrandeCity_PhoebesRoom/scripts.pory"
	goto EverGrandeCity_PhoebesRoom_EventScript_Defeated
# 48 "data/maps/EverGrandeCity_PhoebesRoom/scripts.pory"
	end
# 49 "data/maps/EverGrandeCity_PhoebesRoom/scripts.pory"

# 50 "data/maps/EverGrandeCity_PhoebesRoom/scripts.pory"
EverGrandeCity_PhoebesRoom_EventScript_PostBattleSpeech::
# 51 "data/maps/EverGrandeCity_PhoebesRoom/scripts.pory"
	msgbox EverGrandeCity_PhoebesRoom_Text_PostBattleSpeech, MSGBOX_DEFAULT
# 52 "data/maps/EverGrandeCity_PhoebesRoom/scripts.pory"
	release
# 53 "data/maps/EverGrandeCity_PhoebesRoom/scripts.pory"
	end
# 54 "data/maps/EverGrandeCity_PhoebesRoom/scripts.pory"

# 55 "data/maps/EverGrandeCity_PhoebesRoom/scripts.pory"
EverGrandeCity_PhoebesRoom_EventScript_Defeated::
# 56 "data/maps/EverGrandeCity_PhoebesRoom/scripts.pory"
	setflag FLAG_DEFEATED_ELITE_4_PHOEBE
# 57 "data/maps/EverGrandeCity_PhoebesRoom/scripts.pory"
	call PokemonLeague_EliteFour_SetAdvanceToNextRoomMetatiles
# 58 "data/maps/EverGrandeCity_PhoebesRoom/scripts.pory"
	msgbox EverGrandeCity_PhoebesRoom_Text_PostBattleSpeech, MSGBOX_DEFAULT
# 59 "data/maps/EverGrandeCity_PhoebesRoom/scripts.pory"
	release
# 60 "data/maps/EverGrandeCity_PhoebesRoom/scripts.pory"
	end
# 61 "data/maps/EverGrandeCity_PhoebesRoom/scripts.pory"

# 62 "data/maps/EverGrandeCity_PhoebesRoom/scripts.pory"
EverGrandeCity_PhoebesRoom_Text_IntroSpeech:
# 63 "data/maps/EverGrandeCity_PhoebesRoom/scripts.pory"
	.string "Ahahaha!\p"
# 64 "data/maps/EverGrandeCity_PhoebesRoom/scripts.pory"
	.string "I'm PHOEBE of the ELITE FOUR.\n"
# 65 "data/maps/EverGrandeCity_PhoebesRoom/scripts.pory"
	.string "I did my training on MT. PYRE.\p"
# 66 "data/maps/EverGrandeCity_PhoebesRoom/scripts.pory"
	.string "While I trained, I gained the ability\n"
# 67 "data/maps/EverGrandeCity_PhoebesRoom/scripts.pory"
	.string "to commune with GHOST-type POKéMON.\p"
# 68 "data/maps/EverGrandeCity_PhoebesRoom/scripts.pory"
	.string "Yes, the bond I developed with POKéMON\n"
# 69 "data/maps/EverGrandeCity_PhoebesRoom/scripts.pory"
	.string "is extremely tight.\p"
# 70 "data/maps/EverGrandeCity_PhoebesRoom/scripts.pory"
	.string "So, come on, just try and see if you can\n"
# 71 "data/maps/EverGrandeCity_PhoebesRoom/scripts.pory"
	.string "even inflict damage on my POKéMON!$"
# 72 "data/maps/EverGrandeCity_PhoebesRoom/scripts.pory"

# 73 "data/maps/EverGrandeCity_PhoebesRoom/scripts.pory"
EverGrandeCity_PhoebesRoom_Text_Defeat:
# 74 "data/maps/EverGrandeCity_PhoebesRoom/scripts.pory"
	.string "Oh, darn.\n"
# 75 "data/maps/EverGrandeCity_PhoebesRoom/scripts.pory"
	.string "I've gone and lost.$"
# 76 "data/maps/EverGrandeCity_PhoebesRoom/scripts.pory"

# 77 "data/maps/EverGrandeCity_PhoebesRoom/scripts.pory"
EverGrandeCity_PhoebesRoom_Text_PostBattleSpeech:
# 78 "data/maps/EverGrandeCity_PhoebesRoom/scripts.pory"
	.string "There's a definite bond between you\n"
# 79 "data/maps/EverGrandeCity_PhoebesRoom/scripts.pory"
	.string "and your POKéMON, too.\p"
# 80 "data/maps/EverGrandeCity_PhoebesRoom/scripts.pory"
	.string "I didn't recognize it, so it's only\n"
# 81 "data/maps/EverGrandeCity_PhoebesRoom/scripts.pory"
	.string "natural that I lost.\p"
# 82 "data/maps/EverGrandeCity_PhoebesRoom/scripts.pory"
	.string "Yup, I'd like to see how far your bond\n"
# 83 "data/maps/EverGrandeCity_PhoebesRoom/scripts.pory"
	.string "will carry you.\p"
# 84 "data/maps/EverGrandeCity_PhoebesRoom/scripts.pory"
	.string "Go ahead, move on to the next room.$"
