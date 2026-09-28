SproutHollow_Lab_MapScripts::
	.byte 0

SproutHollow_Lab_EventScript_Aide::
	msgbox SproutHollow_Lab_Text_1, MSGBOX_NPC
	end

SproutHollow_Lab_EventScript_Kai::
	lock
	faceplayer
	setspeaker Pentara_Name_Kai
	msgbox SproutHollow_Lab_Text_2, MSGBOX_DEFAULT
	setspeaker SP_NAME_NONE
	release
	end

SproutHollow_Lab_EventScript_Linden::
	lock
	faceplayer
	goto_if_ge VAR_P_ALD_STORY, 2, SproutHollow_Lab_EventScript_LindenAfter
	setspeaker Pentara_Name_Linden
	msgbox SproutHollow_Lab_Text_3, MSGBOX_DEFAULT
	setspeaker SP_NAME_NONE
	goto SproutHollow_Lab_EventScript_ChooseStarter

SproutHollow_Lab_EventScript_ChooseStarter::
	dynmultipush SproutHollow_Lab_Text_Bulbasaur, SPECIES_BULBASAUR
	dynmultipush SproutHollow_Lab_Text_Charmander, SPECIES_CHARMANDER
	dynmultipush SproutHollow_Lab_Text_Squirtle, SPECIES_SQUIRTLE
	dynmultipush SproutHollow_Lab_Text_Chikorita, SPECIES_CHIKORITA
	dynmultipush SproutHollow_Lab_Text_Cyndaquil, SPECIES_CYNDAQUIL
	dynmultipush SproutHollow_Lab_Text_Totodile, SPECIES_TOTODILE
	dynmultistack 1, 1, TRUE, 6, FALSE, 0, DYN_MULTICHOICE_CB_SHOW_PKMN
	copyvar VAR_P_STARTER, VAR_RESULT
	bufferspeciesname STR_VAR_1, VAR_RESULT
	setspeaker Pentara_Name_Linden
	msgbox SproutHollow_Lab_Text_4, MSGBOX_YESNO
	setspeaker SP_NAME_NONE
	goto_if_eq VAR_RESULT, NO, SproutHollow_Lab_EventScript_ChooseStarter
	givemon VAR_P_STARTER, 5
	playfanfare MUS_RG_OBTAIN_KEY_ITEM
	setspeaker SP_NAME_NONE
	msgbox SproutHollow_Lab_Text_5, MSGBOX_DEFAULT
	waitfanfare
	setflag FLAG_SYS_POKEMON_GET
	setvar VAR_P_ALD_STORY, 2
	call SproutHollow_Lab_EventScript_KaiPicks
	goto SproutHollow_Lab_EventScript_KaiBattle

SproutHollow_Lab_EventScript_KaiPicks::
	goto_if_eq VAR_P_STARTER, SPECIES_BULBASAUR, SproutHollow_Lab_EventScript_KaiPicks0
	goto_if_eq VAR_P_STARTER, SPECIES_CHARMANDER, SproutHollow_Lab_EventScript_KaiPicks1
	goto_if_eq VAR_P_STARTER, SPECIES_SQUIRTLE, SproutHollow_Lab_EventScript_KaiPicks2
	goto_if_eq VAR_P_STARTER, SPECIES_CHIKORITA, SproutHollow_Lab_EventScript_KaiPicks3
	goto_if_eq VAR_P_STARTER, SPECIES_CYNDAQUIL, SproutHollow_Lab_EventScript_KaiPicks4
	goto_if_eq VAR_P_STARTER, SPECIES_TOTODILE, SproutHollow_Lab_EventScript_KaiPicks5
	return

SproutHollow_Lab_EventScript_KaiPicks0::
	setvar VAR_P_KAI_STARTER, 0
	bufferspeciesname STR_VAR_2, SPECIES_CHARMANDER
	return

SproutHollow_Lab_EventScript_KaiPicks1::
	setvar VAR_P_KAI_STARTER, 1
	bufferspeciesname STR_VAR_2, SPECIES_SQUIRTLE
	return

SproutHollow_Lab_EventScript_KaiPicks2::
	setvar VAR_P_KAI_STARTER, 2
	bufferspeciesname STR_VAR_2, SPECIES_BULBASAUR
	return

SproutHollow_Lab_EventScript_KaiPicks3::
	setvar VAR_P_KAI_STARTER, 3
	bufferspeciesname STR_VAR_2, SPECIES_CYNDAQUIL
	return

SproutHollow_Lab_EventScript_KaiPicks4::
	setvar VAR_P_KAI_STARTER, 4
	bufferspeciesname STR_VAR_2, SPECIES_TOTODILE
	return

SproutHollow_Lab_EventScript_KaiPicks5::
	setvar VAR_P_KAI_STARTER, 5
	bufferspeciesname STR_VAR_2, SPECIES_CHIKORITA
	return

SproutHollow_Lab_EventScript_KaiBattle::
	clearflag FLAG_P_HIDE_LAB_KAI
	addobject LOCALID_LAB_KAI
	setspeaker Pentara_Name_Kai
	msgbox SproutHollow_Lab_Text_6, MSGBOX_DEFAULT
	setspeaker SP_NAME_NONE
	goto_if_eq VAR_P_KAI_STARTER, 0, SproutHollow_Lab_EventScript_KaiBattle0
	goto_if_eq VAR_P_KAI_STARTER, 1, SproutHollow_Lab_EventScript_KaiBattle1
	goto_if_eq VAR_P_KAI_STARTER, 2, SproutHollow_Lab_EventScript_KaiBattle2
	goto_if_eq VAR_P_KAI_STARTER, 3, SproutHollow_Lab_EventScript_KaiBattle3
	goto_if_eq VAR_P_KAI_STARTER, 4, SproutHollow_Lab_EventScript_KaiBattle4
	goto_if_eq VAR_P_KAI_STARTER, 5, SproutHollow_Lab_EventScript_KaiBattle5
	end

SproutHollow_Lab_EventScript_KaiBattle0::
	trainerbattle_no_intro TRAINER_P_KAI_LAB_0, SproutHollow_Lab_Text_KaiLose
	goto_if_set FLAG_P_BATTLE_LOST, SproutHollow_Lab_EventScript_KaiWon
	goto SproutHollow_Lab_EventScript_AfterKai

SproutHollow_Lab_EventScript_KaiBattle1::
	trainerbattle_no_intro TRAINER_P_KAI_LAB_1, SproutHollow_Lab_Text_KaiLose
	goto_if_set FLAG_P_BATTLE_LOST, SproutHollow_Lab_EventScript_KaiWon
	goto SproutHollow_Lab_EventScript_AfterKai

SproutHollow_Lab_EventScript_KaiBattle2::
	trainerbattle_no_intro TRAINER_P_KAI_LAB_2, SproutHollow_Lab_Text_KaiLose
	goto_if_set FLAG_P_BATTLE_LOST, SproutHollow_Lab_EventScript_KaiWon
	goto SproutHollow_Lab_EventScript_AfterKai

SproutHollow_Lab_EventScript_KaiBattle3::
	trainerbattle_no_intro TRAINER_P_KAI_LAB_3, SproutHollow_Lab_Text_KaiLose
	goto_if_set FLAG_P_BATTLE_LOST, SproutHollow_Lab_EventScript_KaiWon
	goto SproutHollow_Lab_EventScript_AfterKai

SproutHollow_Lab_EventScript_KaiBattle4::
	trainerbattle_no_intro TRAINER_P_KAI_LAB_4, SproutHollow_Lab_Text_KaiLose
	goto_if_set FLAG_P_BATTLE_LOST, SproutHollow_Lab_EventScript_KaiWon
	goto SproutHollow_Lab_EventScript_AfterKai

SproutHollow_Lab_EventScript_KaiBattle5::
	trainerbattle_no_intro TRAINER_P_KAI_LAB_5, SproutHollow_Lab_Text_KaiLose
	goto_if_set FLAG_P_BATTLE_LOST, SproutHollow_Lab_EventScript_KaiWon
	goto SproutHollow_Lab_EventScript_AfterKai

SproutHollow_Lab_EventScript_KaiWon::
	setspeaker Pentara_Name_Kai
	msgbox SproutHollow_Lab_Text_7, MSGBOX_DEFAULT
	setspeaker SP_NAME_NONE
	goto SproutHollow_Lab_EventScript_KaiLeaves

SproutHollow_Lab_EventScript_AfterKai::
	setspeaker Pentara_Name_Kai
	msgbox SproutHollow_Lab_Text_8, MSGBOX_DEFAULT
	setspeaker SP_NAME_NONE
	goto SproutHollow_Lab_EventScript_KaiLeaves

SproutHollow_Lab_EventScript_KaiLeaves::
	setspeaker Pentara_Name_Kai
	msgbox SproutHollow_Lab_Text_9, MSGBOX_DEFAULT
	setspeaker SP_NAME_NONE
	closemessage
	removeobject LOCALID_LAB_KAI
	setflag FLAG_P_HIDE_LAB_KAI
	setspeaker Pentara_Name_Linden
	msgbox SproutHollow_Lab_Text_10, MSGBOX_DEFAULT
	setspeaker SP_NAME_NONE
	setflag FLAG_SYS_POKEDEX_GET
	special SetUnlockedPokedexFlags
	special EnableNationalPokedex
	setflag FLAG_RECEIVED_POKEDEX_FROM_BIRCH
	playfanfare MUS_RG_OBTAIN_KEY_ITEM
	setspeaker SP_NAME_NONE
	msgbox SproutHollow_Lab_Text_11, MSGBOX_DEFAULT
	waitfanfare
	giveitem ITEM_POKE_BALL, 10
	giveitem ITEM_TOWN_MAP
	setspeaker Pentara_Name_Linden
	msgbox SproutHollow_Lab_Text_12, MSGBOX_DEFAULT
	setspeaker SP_NAME_NONE
	release
	end

SproutHollow_Lab_EventScript_LindenAfter::
	setspeaker Pentara_Name_Linden
	msgbox SproutHollow_Lab_Text_13, MSGBOX_DEFAULT
	setspeaker SP_NAME_NONE
	release
	end

SproutHollow_Lab_Text_1::
	.string "Pokémon in Pentara learn new moves\n"
	.string "every few levels, and the moves\l"
	.string "they learn depend on their types.\p"
	.string "So a Fire-type grows into more and\n"
	.string "more powerful flames!$"

SproutHollow_Lab_Text_2::
	.string "Next time, I'm winning. Just\n"
	.string "watch!$"

SproutHollow_Lab_Text_3::
	.string "Ah, {PLAYER}! Right on time.\p"
	.string "Welcome to my lab. I study how\n"
	.string "Pentara's five regions shape the\l"
	.string "Pokémon that live in them.\p"
	.string "Here in Aldermoor you'll only meet\n"
	.string "Pokémon native to this land. To\l"
	.string "meet others, you must travel on.\p"
	.string "Each region has eight Gyms and a\n"
	.string "League. Beat the League, and the\l"
	.string "ferry to the next region is yours.\p"
	.string "Now then. I have six Pokémon here,\n"
	.string "the classic partners of Aldermoor.\l"
	.string "Choose one to be your partner!$"

SproutHollow_Lab_Text_4::
	.string "{STR_VAR_1}! An excellent choice.\n"
	.string "Will you take {STR_VAR_1} as your\l"
	.string "partner?$"

SproutHollow_Lab_Text_5::
	.string "{PLAYER} received {STR_VAR_1}!$"

SproutHollow_Lab_Text_6::
	.string "Wait up! Professor, that's not\n"
	.string "fair, {PLAYER} got to pick first!\p"
	.string "Then I'll take {STR_VAR_2}. It's\n"
	.string "strong against yours!\p"
	.string "{PLAYER}! Let's see which of us\n"
	.string "picked better. Battle me!$"

SproutHollow_Lab_Text_7::
	.string "Yes! I won! Did you see that,\n"
	.string "Professor?\p"
	.string "Don't feel bad, {PLAYER}. Your\n"
	.string "Pokémon are all healed up. We'll\l"
	.string "have a rematch someday!$"

SproutHollow_Lab_Text_8::
	.string "Argh! Fine, you win this one.$"

SproutHollow_Lab_Text_9::
	.string "I'm heading out to train on Meadow\n"
	.string "Lane. See you in Brambleton,\l"
	.string "{PLAYER}!$"

SproutHollow_Lab_Text_10::
	.string "What a battle! You two will push\n"
	.string "each other far.\p"
	.string "Take these. The Pokédex records\n"
	.string "every Pokémon you meet.$"

SproutHollow_Lab_Text_11::
	.string "{PLAYER} received the Pokédex!$"

SproutHollow_Lab_Text_12::
	.string "And one more gift: the Pentara\n"
	.string "Guide.\p"
	.string "Open it any time from your Bag. It\n"
	.string "shows which Pokémon live on every\l"
	.string "route, where TMs are sold, and\n"
	.string "where the legendary Pokémon wait.\p"
	.string "Your first Gym is in Brambleton,\n"
	.string "north along Meadow Lane. Good\l"
	.string "luck, {PLAYER}!$"

SproutHollow_Lab_Text_13::
	.string "Pokémon in Pentara stop gaining\n"
	.string "experience at the level cap for\l"
	.string "your current badges.\p"
	.string "Earn the next badge and the cap\n"
	.string "rises. No need to grind: the road\l"
	.string "will keep you strong!$"

SproutHollow_Lab_Text_Bulbasaur::
	.string "Bulbasaur$"

SproutHollow_Lab_Text_Charmander::
	.string "Charmander$"

SproutHollow_Lab_Text_Squirtle::
	.string "Squirtle$"

SproutHollow_Lab_Text_Chikorita::
	.string "Chikorita$"

SproutHollow_Lab_Text_Cyndaquil::
	.string "Cyndaquil$"

SproutHollow_Lab_Text_Totodile::
	.string "Totodile$"

SproutHollow_Lab_Text_KaiLose::
	.string "Kai: Seriously?! My Pokémon and I\n"
	.string "will get you next time!$"

