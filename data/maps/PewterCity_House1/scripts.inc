PewterCity_House1_MapScripts::
	.byte 0

PewterCity_House1_EventScript_Nerd::
	msgbox PewterCity_House1_Text_SuperNerd, MSGBOX_NPC
	end

PewterCity_House1_EventScript_Nidorian::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_NIDORAN_M, CRY_MODE_NORMAL
	msgbox PewterCity_House1_Text_Nidoran, MSGBOX_DEFAULT
	waitmoncry
	release
	end

PewterCity_House1_Text_SuperNerd:
	.string "NIDORAN, shake!$"

PewterCity_House1_Text_Nidoran:
	.string "NIDORAN: Gau gau!$"
