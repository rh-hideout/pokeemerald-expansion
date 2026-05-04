CherrygroveCity_House3_MapScripts::
	.byte 0

CherrygroveCity_House3_EventScript_Boy::
	lock
	faceplayer
	msgbox CherrygroveCity_EvolutionHouse_Text_Youngster, MSGBOX_DEFAULT
	closemessage
	release
	end

CherrygroveCity_House3_EventScript_Girl::
	lock
	faceplayer
	msgbox CherrygroveCity_EvolutionHouse_Text_Lass, MSGBOX_DEFAULT
	closemessage
	release
	end

CherrygroveCity_EvolutionHouse_Text_Youngster:
	.string "POKéMON gain experience in\n"
	.string "battle and change their form.$"

CherrygroveCity_EvolutionHouse_Text_Lass:
	.string "POKéMON change?\p"
	.string "I would be shocked if one did\n"
	.string "that!$"
