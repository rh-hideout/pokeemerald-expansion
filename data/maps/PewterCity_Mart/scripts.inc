PewterCity_Mart_MapScripts::
	.byte 0

PewterCity_Mart_EventScript_Youngster::
	msgbox PewterCity_Mart_Text_Youngster, MSGBOX_NPC
	end

PewterCity_Mart_EventScript_Nerd::
	msgbox PewterCity_Mart_Text_SuperNerd, MSGBOX_NPC
	end

PewterCity_Mart_Text_Youngster:
	.string "Hi! Check out my GYARADOS!\p"
	.string "I raised it from a MAGIKARP. I can't\n"
	.string "believe how strong it has become.$"

PewterCity_Mart_Text_SuperNerd:
	.string "There once was a weird old man who sold\n"
	.string "MAGIKARP.\p"
	.string "He was saying the MAGIKARP from the\n"
	.string "LAKE OF RAGE were excellent.$"

