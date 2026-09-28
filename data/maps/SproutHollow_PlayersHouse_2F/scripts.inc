SproutHollow_PlayersHouse_2F_MapScripts::
	.byte 0

SproutHollow_PlayersHouse_2F_EventScript_PC::
	lockall
	setspeaker SP_NAME_NONE
	msgbox SproutHollow_PlayersHouse_2F_Text_1, MSGBOX_DEFAULT
	releaseall
	end

SproutHollow_PlayersHouse_2F_Text_1::
	.string "It's your PC. Your Pokémon\n"
	.string "journey's notes will be stored\l"
	.string "here.$"

