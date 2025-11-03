# 1 "data/maps/DewfordTown_House2/scripts.pory"

# 2 "data/maps/DewfordTown_House2/scripts.pory"
DewfordTown_House2_MapScripts::
# 3 "data/maps/DewfordTown_House2/scripts.pory"
	.byte 0
# 4 "data/maps/DewfordTown_House2/scripts.pory"

# 5 "data/maps/DewfordTown_House2/scripts.pory"
DewfordTown_House2_EventScript_Man::
# 6 "data/maps/DewfordTown_House2/scripts.pory"
	lock
# 7 "data/maps/DewfordTown_House2/scripts.pory"
	faceplayer
# 8 "data/maps/DewfordTown_House2/scripts.pory"
	goto_if_set FLAG_RECEIVED_SILK_SCARF, DewfordTown_House2_EventScript_ExplainSilkScarf
# 9 "data/maps/DewfordTown_House2/scripts.pory"
	msgbox DewfordTown_House2_Text_WantYouToHaveSilkScarf, MSGBOX_DEFAULT
# 10 "data/maps/DewfordTown_House2/scripts.pory"
	giveitem ITEM_SILK_SCARF
# 11 "data/maps/DewfordTown_House2/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, DewfordTown_House2_EventScript_NoRoomForScarf
# 12 "data/maps/DewfordTown_House2/scripts.pory"
	setflag FLAG_RECEIVED_SILK_SCARF
# 13 "data/maps/DewfordTown_House2/scripts.pory"
	release
# 14 "data/maps/DewfordTown_House2/scripts.pory"
	end
# 15 "data/maps/DewfordTown_House2/scripts.pory"

# 16 "data/maps/DewfordTown_House2/scripts.pory"
DewfordTown_House2_EventScript_NoRoomForScarf::
# 17 "data/maps/DewfordTown_House2/scripts.pory"
	msgbox DewfordTown_House2_Text_NoRoom, MSGBOX_DEFAULT
# 18 "data/maps/DewfordTown_House2/scripts.pory"
	release
# 19 "data/maps/DewfordTown_House2/scripts.pory"
	end
# 20 "data/maps/DewfordTown_House2/scripts.pory"

# 21 "data/maps/DewfordTown_House2/scripts.pory"
DewfordTown_House2_EventScript_ExplainSilkScarf::
# 22 "data/maps/DewfordTown_House2/scripts.pory"
	msgbox DewfordTown_House2_Text_ExplainSilkScarf, MSGBOX_DEFAULT
# 23 "data/maps/DewfordTown_House2/scripts.pory"
	release
# 24 "data/maps/DewfordTown_House2/scripts.pory"
	end
# 25 "data/maps/DewfordTown_House2/scripts.pory"

# 26 "data/maps/DewfordTown_House2/scripts.pory"
DewfordTown_House2_EventScript_Boy::
# 27 "data/maps/DewfordTown_House2/scripts.pory"
	msgbox DewfordTown_House2_Text_BrawlySoCool, MSGBOX_NPC
# 28 "data/maps/DewfordTown_House2/scripts.pory"
	end
# 29 "data/maps/DewfordTown_House2/scripts.pory"

# 30 "data/maps/DewfordTown_House2/scripts.pory"
DewfordTown_House2_Text_WantYouToHaveSilkScarf:
# 31 "data/maps/DewfordTown_House2/scripts.pory"
	.string "Gorge your eyes on this!\p"
# 32 "data/maps/DewfordTown_House2/scripts.pory"
	.string "It's a SILK SCARF. It's right at the\n"
# 33 "data/maps/DewfordTown_House2/scripts.pory"
	.string "cutting edge of fashion, yeah!\p"
# 34 "data/maps/DewfordTown_House2/scripts.pory"
	.string "Oh, I can see your eyes twinkling!\n"
# 35 "data/maps/DewfordTown_House2/scripts.pory"
	.string "You appreciate my dazzling style!\p"
# 36 "data/maps/DewfordTown_House2/scripts.pory"
	.string "Oh, you're a delight!\n"
# 37 "data/maps/DewfordTown_House2/scripts.pory"
	.string "Here you go. I want you to have it!$"
# 38 "data/maps/DewfordTown_House2/scripts.pory"

# 39 "data/maps/DewfordTown_House2/scripts.pory"
DewfordTown_House2_Text_NoRoom:
# 40 "data/maps/DewfordTown_House2/scripts.pory"
	.string "Oh, you don't have room?\p"
# 41 "data/maps/DewfordTown_House2/scripts.pory"
	.string "Now, listen tight, this SCARF is a must-\n"
# 42 "data/maps/DewfordTown_House2/scripts.pory"
	.string "have! Why, I would sell all my items\l"
# 43 "data/maps/DewfordTown_House2/scripts.pory"
	.string "in order to get it!$"
# 44 "data/maps/DewfordTown_House2/scripts.pory"

# 45 "data/maps/DewfordTown_House2/scripts.pory"
DewfordTown_House2_Text_ExplainSilkScarf:
# 46 "data/maps/DewfordTown_House2/scripts.pory"
	.string "The SILK SCARF raises the power of\n"
# 47 "data/maps/DewfordTown_House2/scripts.pory"
	.string "NORMAL-type moves.\p"
# 48 "data/maps/DewfordTown_House2/scripts.pory"
	.string "It's a marvelous SCARF that will go\n"
# 49 "data/maps/DewfordTown_House2/scripts.pory"
	.string "with almost all POKéMON!$"
# 50 "data/maps/DewfordTown_House2/scripts.pory"

# 51 "data/maps/DewfordTown_House2/scripts.pory"
DewfordTown_House2_Text_BrawlySoCool:
# 52 "data/maps/DewfordTown_House2/scripts.pory"
	.string "Wow, you bothered to cross the sea\n"
# 53 "data/maps/DewfordTown_House2/scripts.pory"
	.string "to visit DEWFORD?\p"
# 54 "data/maps/DewfordTown_House2/scripts.pory"
	.string "Did you maybe come here because you\n"
# 55 "data/maps/DewfordTown_House2/scripts.pory"
	.string "heard about BRAWLY?\p"
# 56 "data/maps/DewfordTown_House2/scripts.pory"
	.string "He's so cool…\n"
# 57 "data/maps/DewfordTown_House2/scripts.pory"
	.string "Everyone idolizes him.$"
