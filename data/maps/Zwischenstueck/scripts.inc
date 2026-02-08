Zwischenstueck_MapScripts::
	.byte 0


Zwischenstueck_EventScript_Sign::
	msgbox Zwischenstueck_Text_TownSign, MSGBOX_SIGN
	end

Zwischenstueck_EventScript_Lagerhaus::
	msgbox Zwischenstueck_Text_Lagerhaus, MSGBOX_SIGN
	end

Zwischenstueck_Text_TownSign::
	.string " Left: DHBW\n"
	.string "Right: JUNGBUSCH$"

Zwischenstueck_Text_Lagerhaus::
	.string " Old BLACKHANSA warehouse.$"

