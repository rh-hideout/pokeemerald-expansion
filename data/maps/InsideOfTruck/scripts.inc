	.align 2

CtfTruck_Terminal::
	lock
	faceplayer
	msgbox CtfTruck_Text_Prompt, MSGBOX_DEFAULT

	setvar VAR_0x8000, 1
	callnative Ctf_FlagTerminal
	waitstate

	goto_if_eq VAR_RESULT, 1, CtfTruck_Terminal_Ok

	msgbox CtfTruck_Text_Wrong, MSGBOX_DEFAULT
	release
	end

CtfTruck_Terminal_Ok::
	setflag FLAG_CTF_TRUCK_TELEPORT
	msgbox CtfTruck_Text_Ok, MSGBOX_DEFAULT
	release
	end


CtfTruck_Teleporter::
	lock
	faceplayer
	msgbox CtfTruck_Text_Teleport, MSGBOX_DEFAULT

	checkplayergender
	goto_if_eq VAR_RESULT, FEMALE, CtfTruck_Teleporter_May

	warp MAP_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F, 0
	end

CtfTruck_Teleporter_May::
	warp MAP_LITTLEROOT_TOWN_MAYS_HOUSE_1F, 0
	end


CtfTruck_Text_Prompt::
	.string "CTF-Terminal: Gib die erste Flag ein.$"

CtfTruck_Text_Wrong::
	.string "Falsch.$"

CtfTruck_Text_Ok::
	.string "Korrekt! Ein Teleporter ist erschienen.$"

CtfTruck_Text_Teleport::
	.string "Teleport!$"
