.set LOCALID_NURSE, 1

Route9_PokemonCenter_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

Route9_PokemonCenter_EventScript_Engineer1::
	msgbox Route9_PokemonCenter_Text_Engineer1, MSGBOX_NPC
	end

Route9_PokemonCenter_EventScript_Engineer2::
	msgbox Route9_PokemonCenter_Text_Engineer2, MSGBOX_NPC
	end

Route9_PokemonCenter_Text_Engineer1:
	.string "Sometimes us engineers come here\n"
	.string "for our break. Or just to get away\l"
	.string "from our MANAGER.\p"
	.string "That guy is crazy.$"

Route9_PokemonCenter_Text_Engineer2:
	.string "The POWER PLANT is very remote, so\n"
	.string "I travel far for work.$"
