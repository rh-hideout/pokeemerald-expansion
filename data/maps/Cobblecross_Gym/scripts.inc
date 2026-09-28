Cobblecross_Gym_MapScripts::
	.byte 0

Cobblecross_Gym_EventScript_Garnet::
	lock
	faceplayer
	goto_if_set FLAG_BADGE02_GET, Cobblecross_Gym_EventScript_GarnetAfter
	setspeaker Pentara_Name_Garnet
	msgbox Cobblecross_Gym_Text_1, MSGBOX_DEFAULT
	setspeaker SP_NAME_NONE
	trainerbattle_no_intro TRAINER_P_GARNET, Cobblecross_Gym_Text_GarnetLose
	goto_if_set FLAG_P_BATTLE_LOST, Pentara_EventScript_BattleLost
	setspeaker Pentara_Name_Garnet
	msgbox Cobblecross_Gym_Text_2, MSGBOX_DEFAULT
	setspeaker SP_NAME_NONE
	playfanfare MUS_OBTAIN_BADGE
	setspeaker SP_NAME_NONE
	msgbox Cobblecross_Gym_Text_3, MSGBOX_DEFAULT
	waitfanfare
	setflag FLAG_BADGE02_GET
	setvar VAR_P_LEVEL_CAP, 11
	setvar VAR_P_ALD_NORTH_GATE, 1
	giveitem ITEM_TM_ROCK_TOMB
	setspeaker Pentara_Name_Garnet
	msgbox Cobblecross_Gym_Text_4, MSGBOX_DEFAULT
	setspeaker SP_NAME_NONE
	release
	end

Cobblecross_Gym_EventScript_GarnetAfter::
	setspeaker Pentara_Name_Garnet
	msgbox Cobblecross_Gym_Text_5, MSGBOX_DEFAULT
	setspeaker SP_NAME_NONE
	release
	end

Cobblecross_Gym_Text_1::
	.string "Welcome to Cobblecross Gym. I'm\n"
	.string "Garnet.\p"
	.string "Stone doesn't rush. Stone doesn't\n"
	.string "break. Stone waits for you to wear\l"
	.string "yourself out.\p"
	.string "Let's see how long you last in my\n"
	.string "sandstorm!$"

Cobblecross_Gym_Text_2::
	.string "You cracked the stonewall.\n"
	.string "Impressive.\p"
	.string "Here is the Boulder Crest Badge.\n"
	.string "Your Pokémon can now grow up to\l"
	.string "level 11.$"

Cobblecross_Gym_Text_3::
	.string "{PLAYER} received the Boulder Crest\n"
	.string "Badge from Garnet!$"

Cobblecross_Gym_Text_4::
	.string "I'll clear the Cliffside Path\n"
	.string "north of town for you. It leads to\l"
	.string "Mistral Harbor.\p"
	.string "And someone blasted those rocks\n"
	.string "loose on purpose. If it was Team\l"
	.string "Rust... stay sharp.$"

Cobblecross_Gym_Text_5::
	.string "Mistral Harbor's Gym Leader,\n"
	.string "Maren, fights with the tide\l"
	.string "itself. Be ready.$"

Cobblecross_Gym_Text_GarnetLose::
	.string "Garnet: The stone... cracks.$"

