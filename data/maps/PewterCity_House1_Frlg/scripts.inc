PewterCity_House1_Frlg_MapScripts::
	.byte 0

PewterCity_House1_EventScript_BaldingMan::
	msgbox PewterCity_House1_Text_TradeMonsAreFinicky, MSGBOX_NPC
	end

PewterCity_House1_EventScript_LittleBoy::
	lock
	msgbox PewterCity_House1_Text_NidoranSit
	call PewterCity_House1_EventScript_DoNidoranCry
	release
	end

PewterCity_House1_EventScript_Nidoran::
	lock
	faceplayer
	call PewterCity_House1_EventScript_DoNidoranCry
	applymovement LOCALID_PEWTER_HOUSE_NIDORAN, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

PewterCity_House1_EventScript_DoNidoranCry::
	textcolor NPC_TEXT_COLOR_NEUTRAL
	waitse
	playmoncry SPECIES_NIDORAN_M, CRY_MODE_NORMAL
	msgbox PewterCity_House1_Text_Nidoran
	waitmoncry
	call EventScript_RestorePrevTextColor
	return

PewterCity_House1_Text_Nidoran::
	.string "[Nidoran]♂: Bowbow!$"

PewterCity_House1_Text_NidoranSit::
	.string "[Nidoran], sit!$"

PewterCity_House1_Text_TradeMonsAreFinicky::
	.string "Our [Pokémon]'s an outsider, so it's\n"
	.string "finicky and hard to handle.\p"
	.string "An outsider is a [Pokémon] that you\n"
	.string "get in a trade.\p"
	.string "It grows fast, but it may ignore an\n"
	.string "unskilled [Trainer] in battle.\p"
	.string "If only we had some [Badges]…$"
