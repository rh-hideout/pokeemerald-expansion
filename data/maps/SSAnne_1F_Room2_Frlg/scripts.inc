SSAnne_1F_Room2_Frlg_MapScripts::
	.byte 0

SSAnne_1F_Room2_EventScript_Woman::
	msgbox SSAnne_1F_Room2_Text_CruisingAroundWorld, MSGBOX_NPC
	end

SSAnne_1F_Room2_EventScript_Ann::
	trainerbattle_single TRAINER_LASS_ANN, SSAnne_1F_Room2_Text_AnnIntro, SSAnne_1F_Room2_Text_AnnDefeat
	msgbox SSAnne_1F_Room2_Text_AnnPostBattle, MSGBOX_AUTOCLOSE
	end

SSAnne_1F_Room2_EventScript_Tyler::
	trainerbattle_single TRAINER_YOUNGSTER_TYLER, SSAnne_1F_Room2_Text_TylerIntro, SSAnne_1F_Room2_Text_TylerDefeat
	msgbox SSAnne_1F_Room2_Text_TylerPostBattle, MSGBOX_AUTOCLOSE
	end

SSAnne_1F_Room2_Text_TylerIntro::
	.string "I love [Pokémon]!\n"
	.string "Do you?$"

SSAnne_1F_Room2_Text_TylerDefeat::
	.string "Wow! \n"
	.string "You're great!$"

SSAnne_1F_Room2_Text_TylerPostBattle::
	.string "Listen, listen!\n"
	.string "Let me be your friend, okay?\p"
	.string "Then we can trade [Pokémon] and\n"
	.string "do stuff.$"

SSAnne_1F_Room2_Text_AnnIntro::
	.string "I collected these [Pokémon]\n"
	.string "from all around the world!$"

SSAnne_1F_Room2_Text_AnnDefeat::
	.string "Oh, no!\n"
	.string "I went around the world for these!$"

SSAnne_1F_Room2_Text_AnnPostBattle::
	.string "You hurt my poor [Pokémon]!\p"
	.string "I demand that you heal them at a\n"
	.string "[Pokémon Center]!$"

SSAnne_1F_Room2_Text_CruisingAroundWorld::
	.string "We are cruising around the world,\n"
	.string "my children and I.$"
