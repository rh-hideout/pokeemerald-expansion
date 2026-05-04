PokemonLeague_KogasRoom_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, EliteFourRoom_OnFrame
	map_script MAP_SCRIPT_ON_RESUME, PokemonLeague_KogasRoom_OnResume
	map_script MAP_SCRIPT_ON_LOAD, EliteFourRoom_OnLoad
	.byte 0

PokemonLeague_KogasRoom_OnResume::
	setvar VAR_0x8004, 1
	special DoPokemonLeagueLightingEffect
	end

PokemonLeague_KogasRoom_EventScript_Koga::
	lock 
	faceplayer
	goto_if_ge VAR_LEAGUE_STATE, 3, PokemonLeague_KogasRoom_EventScript_KogaDefeated
	goto_if_set FLAG_IS_CHAMPION, PokemonLeague_KogasRoom_EventScript_KogaRematch
	msgbox PokemonLeague_KogasRoom_Text_Before, MSGBOX_DEFAULT
	setflag FLAG_TEMP_3
	setflag FLAG_TEMP_5
	trainerbattle_no_intro TRAINER_KOGA_1, PokemonLeague_KogasRoom_Text_Beaten
	goto PokemonLeague_KogasRoom_EventScript_KogaOnDefeat

PokemonLeague_KogasRoom_EventScript_KogaRematch::
	msgbox PokemonLeague_KogasRoom_Text_RematchBefore, MSGBOX_DEFAULT
	setflag FLAG_TEMP_3
	setflag FLAG_TEMP_5
	trainerbattle_no_intro TRAINER_KOGA_2, PokemonLeague_KogasRoom_Text_Beaten
	goto PokemonLeague_KogasRoom_EventScript_KogaOnDefeat

PokemonLeague_KogasRoom_EventScript_KogaOnDefeat::
	clearflag FLAG_TEMP_5
	msgbox PokemonLeague_KogasRoom_Text_Defeat, MSGBOX_DEFAULT
	closemessage
	setmetatile 6, 1, 0x28E, FALSE
	setmetatile 6, 2, 0x296, FALSE	
	playse SE_BANG
	setvar VAR_0x8004, 1  @ vertical pan
	setvar VAR_0x8005, 1  @ horizontal pan
	setvar VAR_0x8006, 4  @ num shakes
	setvar VAR_0x8007, 4  @ shake delay
	special ShakeCamera
	waitstate
	special DrawWholeMapView
	setvar VAR_LEAGUE_STATE, 3
	release
	end

PokemonLeague_KogasRoom_EventScript_KogaDefeated::
	msgbox PokemonLeague_KogasRoom_Text_Defeat, MSGBOX_DEFAULT
	closemessage
	release
	end

PokemonLeague_KogasRoom_Text_RematchBefore:
    .string "KOGA: Fwahahahaha!\p"
    .string "You return, brave challenger.\p"
    .string "My ninja skills have sharpened.\p"
    .string "New sinister traps await you.\p"
    .string "Poison, sleep, and more...\n"
    .string "Be ready!\p"
    .string "Fwahahahaha!\p"
    .string "Show me how you've grown!$"

PokemonLeague_KogasRoom_Text_Before:
    .string "Fwahahahaha!\p"
    .string "I am KOGA of the ELITE FOUR.\p"
    .string "I live in shadows, a ninja!\p"
    .string "My intricate style will confound\n"
    .string "and destroy you!\p"
    .string "Confusion, sleep, poison…\p"
    .string "Prepare to be the victim of my\n"
    .string "sinister technique!\p"
    .string "Fwahahahaha!\p"
    .string "POKéMON is not merely about brute\n"
    .string "force--you shall see soon enough!$"

PokemonLeague_KogasRoom_Text_Beaten:
    .string "Ah!\n"
    .string "You have proven your worth!$"

PokemonLeague_KogasRoom_Text_Defeat:
    .string "I subjected you to everything I\n"
    .string "could muster.\p"
    .string "But my efforts failed. I must hone\n"
    .string "my skills.\p"
    .string "Go on to the next room, and put\n"
    .string "your abilities to test!$"
