PokemonLeague_BrunosRoom_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, EliteFourRoom_OnFrame
	map_script MAP_SCRIPT_ON_RESUME, PokemonLeague_BrunosRoom_OnResume
	map_script MAP_SCRIPT_ON_LOAD, EliteFourRoom_OnLoad
	.byte 0

PokemonLeague_BrunosRoom_OnResume::
	setvar VAR_0x8004, 2
	special DoPokemonLeagueLightingEffect
	end

PokemonLeague_BrunosRoom_EventScript_Bruno::
	lock 
	faceplayer
	goto_if_ge VAR_LEAGUE_STATE, 4, PokemonLeague_BrunosRoom_EventScript_BrunoDefeated
	goto_if_set FLAG_IS_CHAMPION, PokemonLeague_BrunosRoom_EventScript_BrunoRematch
	msgbox PokemonLeague_BrunosRoom_Text_Before, MSGBOX_DEFAULT
	setflag FLAG_TEMP_3
	setflag FLAG_TEMP_5
	trainerbattle_no_intro TRAINER_BRUNO_1, PokemonLeague_BrunosRoom_Text_Beaten
	goto PokemonLeague_BrunosRoom_EventScript_BrunoOnDefeat

PokemonLeague_BrunosRoom_EventScript_BrunoRematch::
	msgbox PokemonLeague_BrunosRoom_Text_RematchBefore, MSGBOX_DEFAULT
	setflag FLAG_TEMP_3
	setflag FLAG_TEMP_5
	trainerbattle_no_intro TRAINER_BRUNO_2, PokemonLeague_BrunosRoom_Text_Beaten
	goto PokemonLeague_BrunosRoom_EventScript_BrunoOnDefeat

PokemonLeague_BrunosRoom_EventScript_BrunoOnDefeat::
	clearflag FLAG_TEMP_5	
	msgbox PokemonLeague_BrunosRoom_Text_Defeat, MSGBOX_DEFAULT
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
	setvar VAR_LEAGUE_STATE, 4
	release
	end

PokemonLeague_BrunosRoom_EventScript_BrunoDefeated::
	msgbox PokemonLeague_BrunosRoom_Text_Defeat, MSGBOX_DEFAULT
	closemessage
	release
	end

PokemonLeague_BrunosRoom_Text_RematchBefore:
    .string "BRUNO: Welcome back, young\n"
    .string "warrior.\p"
    .string "Through rigorous training, we have\n"
    .string "grown stronger.\p"
    .string "My rock-hard will is even more firm\n"
    .string "and unyielding.\p"
    .string "Are you prepared to face an even\n"
    .string "greater challenge?\p"
    .string "Show me the results of your\n"
    .string "training.\p"
    .string "Hoo hah!$"

PokemonLeague_BrunosRoom_Text_Before:
    .string "I am BRUNO of the ELITE FOUR.\p"
    .string "I always train to the extreme be-\n"
    .string "cause I believe in our potential.\p"
    .string "That is how we became strong.\p"
    .string "Can you withstand our power?\p"
    .string "Hm? I see no fear in you. You look\n"
    .string "determined. Perfect for battle!\p"
    .string "Ready, {PLAYER}? You will bow down\n"
    .string "to our overwhelming power!\p"
    .string "Hoo hah!$"

PokemonLeague_BrunosRoom_Text_Beaten:
    .string "Why? How could we lose?$"

PokemonLeague_BrunosRoom_Text_Defeat:
    .string "Having lost, I have no right to\n"
    .string "say anything…\p"
    .string "Go face your next challenge!$"
