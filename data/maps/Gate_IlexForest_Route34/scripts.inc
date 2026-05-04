Gate_IlexForest_Route34_MapScripts::
	.byte 0

Route34IlexForestGate_EventScript_Lass::
	lock
	faceplayer
	msgbox Route34IlexForestGate_Text_Lass, MSGBOX_DEFAULT
	closemessage
	release
	end

Route34IlexForestGate_EventScript_Butterfree::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_BUTTERFREE, CRY_MODE_NORMAL
	msgbox Route34IlexForestGate_Text_Butterfree, MSGBOX_DEFAULT
	waitmoncry
	release
	end

Route34IlexForestGate_Text_Lass:
	.string "Did you see the shrine honoring\n"
	.string "the protector?\p"
	.string "It watches over the FOREST from\n"
	.string "across time.\p"
	.string "I think that it must be a\n"
	.string "GRASS-type POKéMON.$"

Route34IlexForestGate_Text_Butterfree:
	.string "BUTTERFREE: Freeh!$"
