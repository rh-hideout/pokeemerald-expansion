PalletTown_RedsHouse_1F_MapScripts::
	.byte 0

PalletTown_RedsHouse_1F_EventScript_Mom::
	lock
	faceplayer
	goto_if_ge VAR_TEMP_0, 1, PalletTown_RedsHouse_1F_EventScript_MomAfter
	msgbox RedsHouse_Text_Mom1, MSGBOX_DEFAULT
	closemessage
	setvar VAR_TEMP_0, 1
	release
	end

PalletTown_RedsHouse_1F_EventScript_MomAfter::
	msgbox RedsHouse_Text_Mom2, MSGBOX_DEFAULT
	closemessage
	release
	end

PalletTown_RedsHouse_1F_EventScript_TV::
	msgbox RedsHouse_Text_TV, MSGBOX_SIGN
	end

RedsHouse_Text_Mom1:
	.string "Hi!\p"
	.string "RED's been away for a long time.\p"
	.string "He hasn't called either, so I have\n"
	.string "no idea where he is or what he's\l"
	.string "been doing.\p"
	.string "They say that no word is proof that\n"
	.string "he's doing fine, but I do worry\l"
	.string "about him.$"

RedsHouse_Text_Mom2:
	.string "I worry about RED getting hurt or\n"
	.string "sick, but he's a boy.\p"
	.string "I'm proud that he is doing what he\n"
	.string "wants to do.$"

RedsHouse_Text_TV:
	.string "They have programs that aren't\n"
	.string "shown in JOHTO…$"
