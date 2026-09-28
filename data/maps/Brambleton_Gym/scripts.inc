Brambleton_Gym_MapScripts::
	.byte 0

Brambleton_Gym_EventScript_Guide::
	msgbox Brambleton_Gym_Text_1, MSGBOX_NPC
	end

Brambleton_Gym_EventScript_Nettle::
	lock
	faceplayer
	goto_if_set FLAG_BADGE01_GET, Brambleton_Gym_EventScript_NettleAfter
	setspeaker Pentara_Name_Nettle
	msgbox Brambleton_Gym_Text_2, MSGBOX_DEFAULT
	setspeaker SP_NAME_NONE
	trainerbattle_no_intro TRAINER_P_NETTLE, Brambleton_Gym_Text_NettleLose
	goto_if_set FLAG_P_BATTLE_LOST, Pentara_EventScript_BattleLost
	setspeaker Pentara_Name_Nettle
	msgbox Brambleton_Gym_Text_3, MSGBOX_DEFAULT
	setspeaker SP_NAME_NONE
	playfanfare MUS_OBTAIN_BADGE
	setspeaker SP_NAME_NONE
	msgbox Brambleton_Gym_Text_4, MSGBOX_DEFAULT
	waitfanfare
	setflag FLAG_BADGE01_GET
	setvar VAR_P_LEVEL_CAP, 10
	setvar VAR_P_ALD_STORY, 4
	setvar VAR_P_ALD_WEST_GATE, 1
	giveitem ITEM_TM_BUG_BITE
	setspeaker Pentara_Name_Nettle
	msgbox Brambleton_Gym_Text_5, MSGBOX_DEFAULT
	setspeaker SP_NAME_NONE
	release
	end

Brambleton_Gym_EventScript_NettleAfter::
	setspeaker Pentara_Name_Nettle
	msgbox Brambleton_Gym_Text_6, MSGBOX_DEFAULT
	setspeaker SP_NAME_NONE
	release
	end

Brambleton_Gym_Text_1::
	.string "Hey, challenger! This Gym has no\n"
	.string "trainers to wear you down, just\l"
	.string "the Leader herself.\p"
	.string "Nettle covers the field in Sticky\n"
	.string "Web. Anything you switch in gets\l"
	.string "slowed!$"

Brambleton_Gym_Text_2::
	.string "So you made it through the\n"
	.string "thicket.\p"
	.string "I'm Nettle, Brambleton's Gym\n"
	.string "Leader. My Bug Pokémon weave,\l"
	.string "sting and swarm.\p"
	.string "Let's see if you can cut your way\n"
	.string "free!$"

Brambleton_Gym_Text_3::
	.string "You tore right through my web...\p"
	.string "The Hive Badge is yours. With it,\n"
	.string "your Pokémon can grow up to level\l"
	.string "10.$"

Brambleton_Gym_Text_4::
	.string "{PLAYER} received the Hive Badge\n"
	.string "from Nettle!$"

Brambleton_Gym_Text_5::
	.string "Take this too. Bug Bite lets your\n"
	.string "Pokémon munch the foe's berry.\p"
	.string "The road west through Whisperwood\n"
	.string "is open now. Team Rust has been\l"
	.string "seen in the forest. Be careful.$"

Brambleton_Gym_Text_6::
	.string "Whisperwood lies west. The\n"
	.string "poachers there... please stop\l"
	.string "them.$"

Brambleton_Gym_Text_NettleLose::
	.string "Nettle: Stung by a rookie! You've\n"
	.string "earned this.$"

