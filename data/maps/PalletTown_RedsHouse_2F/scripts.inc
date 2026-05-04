PalletTown_RedsHouse_2F_MapScripts::
	.byte 0

PalletTown_RedsHouse_2F_EventScript_NES::
	msgbox RedsHouse_Text_NES, MSGBOX_SIGN
	end

PalletTown_RedsHouse_2F_EventScript_PC::
	msgbox RedsHouse_Text_PC, MSGBOX_SIGN
	end

RedsHouse_Text_NES:
	.string "{PLAYER} played the NES.\p"
	.string "Better get going--no time to lose!$"

RedsHouse_Text_PC:
	.string "It looks like it hasn't been used\n"
	.string "in a long time…$"
