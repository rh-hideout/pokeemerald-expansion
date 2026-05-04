BlackthornCity_House1_MapScripts::
	.byte 0

BlackthornCity_House1EventScript_Granny::
	msgbox BlackthornCity_House1_Text_Granny, MSGBOX_NPC
	end

BlackthornCity_House1EventScript_Dratini::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_DRATINI, CRY_MODE_NORMAL
	msgbox BlackthornCity_House1_Text_Dratini, MSGBOX_DEFAULT
	waitmoncry
	release
	end

BlackthornCity_House1_Text_Granny:
	.string "A clan of trainers who can freely\n"
	.string "command dragons live right here in\l"
	.string "BLACKTHORN.\p"
	.string "As a result, there are many legends\n"
	.string "about dragons in this town.$"

BlackthornCity_House1_Text_Dratini:
	.string "DRATINI: Draa!$"
