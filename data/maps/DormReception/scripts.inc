DormReception_MapScripts::
	.byte 0


DormReception_Trash::
# 4 "data/maps/DormReception/scripts.pory"
	lock
# 5 "data/maps/DormReception/scripts.pory"
	msgbox DormReception_Trash_Text_0
# 6 "data/maps/DormReception/scripts.pory"
	release
	end


DormReception_Trash_Found::
# 11 "data/maps/DormReception/scripts.pory"
	lock
# 12 "data/maps/DormReception/scripts.pory"
	goto_if_unset FLAG_DORM_TRASH, DormReception_Trash_Found_2
# 22 "data/maps/DormReception/scripts.pory"
	msgbox DormReception_Trash_Text_0
DormReception_Trash_Found_1:
# 24 "data/maps/DormReception/scripts.pory"
	release
	end

DormReception_Trash_Found_2:
# 14 "data/maps/DormReception/scripts.pory"
	msgbox DormReception_Trash_Found_Text_0
# 15 "data/maps/DormReception/scripts.pory"
	closemessage
# 16 "data/maps/DormReception/scripts.pory"
	giveitem ITEM_ORAN_BERRY
# 17 "data/maps/DormReception/scripts.pory"
	waitfanfare
# 18 "data/maps/DormReception/scripts.pory"
	setflag FLAG_DORM_TRASH
	goto DormReception_Trash_Found_1


DormReception_TelevisionShow::
# 29 "data/maps/DormReception/scripts.pory"
	lock
# 30 "data/maps/DormReception/scripts.pory"
	msgbox DormReception_TelevisionShow_Text_0
# 31 "data/maps/DormReception/scripts.pory"
	release
	end


DormReception_Fridge::
# 36 "data/maps/DormReception/scripts.pory"
	lock
# 37 "data/maps/DormReception/scripts.pory"
	msgbox DormReception_Fridge_Text_0
# 38 "data/maps/DormReception/scripts.pory"
	release
	end


DormReception_Stove::
# 43 "data/maps/DormReception/scripts.pory"
	lock
# 44 "data/maps/DormReception/scripts.pory"
	msgbox DormReception_Stove_Text_0
# 45 "data/maps/DormReception/scripts.pory"
	release
	end


DormReception_Sink::
# 50 "data/maps/DormReception/scripts.pory"
	lock
# 51 "data/maps/DormReception/scripts.pory"
	msgbox DormReception_Sink_Text_0
# 52 "data/maps/DormReception/scripts.pory"
	release
	end


DormReception_Bookcase::
# 57 "data/maps/DormReception/scripts.pory"
	lock
# 58 "data/maps/DormReception/scripts.pory"
	msgbox DormReception_Bookcase_Text_0
# 59 "data/maps/DormReception/scripts.pory"
	release
	end


DormReception_Trash_Text_0:
# 5 "data/maps/DormReception/scripts.pory"
	.string "Nothing but trash inside…$"

DormReception_Trash_Found_Text_0:
# 14 "data/maps/DormReception/scripts.pory"
	.string "Nothing but trash inside…\p…\pOh wait! There's something here!$"

DormReception_TelevisionShow_Text_0:
# 30 "data/maps/DormReception/scripts.pory"
	.string "There are people dancing like chickens\n"
	.string "on this TV show.\p"
	.string "Have they ever even seen a chicken…?$"

DormReception_Fridge_Text_0:
# 37 "data/maps/DormReception/scripts.pory"
	.string "It's filled with lots of beer\n"
	.string "and frozen meals.$"

DormReception_Stove_Text_0:
# 44 "data/maps/DormReception/scripts.pory"
	.string "There's half eaten ramen still\n"
	.string "sitting in the pot.$"

DormReception_Sink_Text_0:
# 51 "data/maps/DormReception/scripts.pory"
	.string "Piled up high with used dishes.$"

DormReception_Bookcase_Text_0:
# 58 "data/maps/DormReception/scripts.pory"
	.string "Very dusty, clearly not used.$"
