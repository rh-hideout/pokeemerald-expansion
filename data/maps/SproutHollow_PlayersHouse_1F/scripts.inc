SproutHollow_PlayersHouse_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, SproutHollow_PlayersHouse_1F_OnTransition_Fly
	.byte 0

SproutHollow_PlayersHouse_1F_EventScript_Mom::
	lock
	faceplayer
	goto_if_ge VAR_P_ALD_STORY, 2, SproutHollow_PlayersHouse_1F_EventScript_MomHeal
	setspeaker Pentara_Name_Mom
	msgbox SproutHollow_PlayersHouse_1F_Text_1, MSGBOX_DEFAULT
	setspeaker SP_NAME_NONE
	setvar VAR_P_ALD_STORY, 1
	release
	end

SproutHollow_PlayersHouse_1F_EventScript_MomHeal::
	setspeaker Pentara_Name_Mom
	msgbox SproutHollow_PlayersHouse_1F_Text_2, MSGBOX_DEFAULT
	setspeaker SP_NAME_NONE
	closemessage
	call Common_EventScript_OutOfCenterPartyHeal
	setspeaker Pentara_Name_Mom
	msgbox SproutHollow_PlayersHouse_1F_Text_3, MSGBOX_DEFAULT
	setspeaker SP_NAME_NONE
	release
	end

SproutHollow_PlayersHouse_1F_EventScript_TV::
	lockall
	setspeaker SP_NAME_NONE
	msgbox SproutHollow_PlayersHouse_1F_Text_4, MSGBOX_DEFAULT
	releaseall
	end

SproutHollow_PlayersHouse_1F_OnTransition_Fly::
	setflag FLAG_P_FLY_SPROUT_HOLLOW
	end

SproutHollow_PlayersHouse_1F_Text_1::
	.string "Good morning, sleepyhead!\p"
	.string "Professor Linden came by at dawn.\n"
	.string "He said today is the day you and\l"
	.string "Kai get your first Pokémon!\p"
	.string "He's waiting at his lab, just past\n"
	.string "the pond. Go on, don't keep him\l"
	.string "waiting!$"

SproutHollow_PlayersHouse_1F_Text_2::
	.string "Oh, {PLAYER}! You look worn out.\n"
	.string "Take a rest!$"

SproutHollow_PlayersHouse_1F_Text_3::
	.string "There. All better! Remember, you\n"
	.string "can always come home.$"

SproutHollow_PlayersHouse_1F_Text_4::
	.string "The news is on: 'Pokémon poaching\n"
	.string "reported near Whisperwood.\l"
	.string "Trainers are asked to stay alert.'$"

