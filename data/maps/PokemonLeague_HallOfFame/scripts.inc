.set LOCALID_HALLOFFAME_LANCE, 1

PokemonLeague_HallOfFame_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, PokemonLeague_HallOfFame_OnFrame
	.byte 0

PokemonLeague_HallOfFame_OnFrame::
	map_script_2 VAR_LEAGUE_STATE, 6, PokemonLeague_HallOfFame_EventScript_Cutscene
	.2byte 0

PokemonLeague_HallOfFame_EventScript_Cutscene::
	lock
	goto_if_set FLAG_IS_CHAMPION, PokemonLeague_HallOfFame_EventScript_CutsceneKantoChamp
	applymovement LOCALID_HALLOFFAME_LANCE, PokemonLeague_HallOfFame_Movement_LanceEnter
	applymovement OBJ_EVENT_ID_PLAYER, PokemonLeague_HallOfFame_Movement_PlayerEnter
	waitmovement OBJ_EVENT_ID_PLAYER
	waitmovement LOCALID_HALLOFFAME_LANCE
	msgbox PokemonLeague_HallOfFame_LanceText, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	delay 20
	dofieldeffect FLDEFF_HALL_OF_FAME_RECORD
	waitfieldeffect FLDEFF_HALL_OF_FAME_RECORD
	delay 40
	setvar VAR_TEMP_1, 1
	call PokemonLeague_HallOfFame_EventScript_SetFirstGameClearFlags
	setrespawn HEAL_LOCATION_NEW_BARK_TOWN
	fadescreenspeed FADE_TO_BLACK, 24
	special GameClear
	waitstate
	releaseall
	end

PokemonLeague_HallOfFame_EventScript_CutsceneKantoChamp::
	applymovement LOCALID_HALLOFFAME_LANCE, PokemonLeague_HallOfFame_Movement_LanceEnter
	applymovement OBJ_EVENT_ID_PLAYER, PokemonLeague_HallOfFame_Movement_PlayerEnter
	waitmovement OBJ_EVENT_ID_PLAYER
	waitmovement LOCALID_HALLOFFAME_LANCE
	msgbox PokemonLeague_HallOfFame_Rematch_LanceText, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	delay 20
	dofieldeffect FLDEFF_HALL_OF_FAME_RECORD
	waitfieldeffect FLDEFF_HALL_OF_FAME_RECORD
	delay 40
	setvar VAR_TEMP_1, 1
	call PokemonLeague_HallOfFame_EventScript_SetGameClearFlags
	setrespawn HEAL_LOCATION_NEW_BARK_TOWN
	fadescreenspeed FADE_TO_BLACK, 24
	special GameClear
	waitstate
	releaseall
	end

PokemonLeague_HallOfFame_EventScript_SetFirstGameClearFlags::
	clearflag FLAG_HIDE_LEAGUE_BLACKBELT
	setflag FLAG_IS_CHAMPION
	setflag FLAG_HIDE_BATTLEFRONTIER_ENGINEER
	setvar VAR_LEAGUE_STATE, 1
	setvar VAR_NEWBARK_TOWN_STATE, 6
	setvar VAR_SSAQUA_STATE, 0
	return

PokemonLeague_HallOfFame_EventScript_SetGameClearFlags::
	clearflag FLAG_HIDE_LATIOS
	clearflag FLAG_HIDE_LATIAS
	clearflag FLAG_HIDE_RAYQUAZA
	clearflag FLAG_HIDE_GROUDON
	clearflag FLAG_HIDE_KYOGRE
	clearflag FLAG_HIDE_MEWTWO
	clearflag FLAG_HIDE_VERMILION_SNORLAX
	clearflag FLAG_HIDE_UNION_CAVE_LAPRAS
	clearflag FLAG_HIDE_SUDOWOODO
	clearflag FLAG_HIDE_ZAPDOS
	clearflag FLAG_HIDE_ARTICUNO
	clearflag FLAG_HIDE_MOLTRES
	clearflag FLAG_ITEM_GS_BALL
	setflag FLAG_HIDE_BATTLEFRONTIER_ENGINEER
	setflag FLAG_IS_KANTO_CHAMPION
	setvar VAR_COMPLETED_LUGIA, 4
	clearflag FLAG_HIDE_LUGIA
	setvar VAR_COMPLETED_HO_OH, 4
	clearflag FLAG_HIDE_HO_OH
	call PokemonLeague_HallOfFame_EventScript_SpawnRoamers
	call_if_ge VAR_SUICUNE_ENCOUNTERS, 8, PokemonLeague_HallOfFame_EventScript_SpawnSuicune
	call_if_set FLAG_CAUGHT_CELEBI, PokemonLeague_HallOfFame_EventScript_SpawnSecondCelebi
	clearflag FLAG_DEFEATED_MEW
	clearflag FLAG_CAUGHT_MEW
	clearflag FLAG_BATTLED_DEOXYS
	clearflag FLAG_DEFEATED_DEOXYS
	clearflag FLAG_SUMMONED_MTMOON_JIRACHI
	setvar VAR_LEAGUE_STATE, 1
	return

PokemonLeague_HallOfFame_EventScript_SpawnRoamers::
	clearflag FLAG_CAUGHT_ENTEI
	clearflag FLAG_CAUGHT_RAIKOU
	setvar VAR_0x8004, 1
	special InitRoamer
	return

PokemonLeague_HallOfFame_EventScript_SpawnSuicune::
	clearflag FLAG_HIDE_ROUTE25_SUICUNE
	return

PokemonLeague_HallOfFame_EventScript_SpawnSecondCelebi::
	clearflag FLAG_HIDE_ILEX_FOREST_SECOND_CELEBI
	return

PokemonLeague_HallOfFame_Movement_LanceEnter:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_right
	face_left
	step_end

PokemonLeague_HallOfFame_Movement_PlayerEnter:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	face_right
	step_end

PokemonLeague_HallOfFame_LanceText:
    .string "LANCE: It's been a long time since I\n"
    .string "last came here.\p"
    .string "This is where we honor the LEAGUE\n"
    .string "CHAMPIONS for all eternity.\p"
    .string "Their courageous POKéMON are also\n"
    .string "inducted.\p"
    .string "Here today, we witnessed the rise\n"
    .string "of a new LEAGUE CHAMPION--a\p"
    .string "trainer who feels compassion for,\n"
    .string "and trust toward, all POKéMON.\p"
    .string "A trainer who succeeded through\n"
    .string "perseverance and determination.\p"
    .string "The new LEAGUE CHAMPION who has\n"
    .string "all the makings of greatness!\p"
    .string "{PLAYER}, allow me to register you\n"
    .string "and your partners as CHAMPIONS!$"

PokemonLeague_HallOfFame_Rematch_LanceText:
    .string "LANCE: I remember, it wasn't long ago\n"
    .string "I stood here, welcoming you as\p"
    .string "the CHAMPION of JOHTO.\p"
    .string "And now, here we are again, in this\n"
    .string "sacred place where we honor the very\p"
    .string "best trainers and their POKéMON.\p"
    .string "Today, you've proven yourself not\n"
    .string "just in JOHTO, but in KANTO as well,\l"
    .string "besting even my strongest team.\p"
    .string "You've shown remarkable compassion\n"
    .string "and trust in your POKéMON,\l"
    .string "a bond that has carried you to\l"
    .string "victory time and again.\p"
    .string "Your journey, marked by\n"
    .string "perseverance and unwavering\l"
    .string "determination,\l"
    .string "speaks to your true spirit as a\l"
    .string "trainer.\p"
    .string "You have all the makings of a true\n"
    .string "great, perhaps even the greatest.\p"
    .string "{PLAYER}, it is my honor to register\n"
    .string "you, and your trusted partners,\l"
    .string "as champions once again.$"

