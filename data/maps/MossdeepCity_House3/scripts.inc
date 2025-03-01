MossdeepCity_House3_MapScripts::
	.byte 0

MossdeepCity_House3_EventScript_SuperRodFisherman::
	lock
	faceplayer
	msgbox MossdeepCity_House3_Text_SuperRodIsSuper, MSGBOX_DEFAULT
	release
	end

MossdeepCity_House3_Text_SuperRodIsSuper:
	.string "A SUPER ROD really is super!\p"
	.string "Unfortunately I gave it to\n"
	.string "someone else.\p"
	.string "Good luck beating the game!$"
