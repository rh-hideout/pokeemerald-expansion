# 1 "data/maps/RustboroCity_House3/scripts.pory"

# 2 "data/maps/RustboroCity_House3/scripts.pory"
RustboroCity_House3_MapScripts::
# 3 "data/maps/RustboroCity_House3/scripts.pory"
	.byte 0
# 4 "data/maps/RustboroCity_House3/scripts.pory"

# 5 "data/maps/RustboroCity_House3/scripts.pory"
RustboroCity_House3_EventScript_OldMan::
# 6 "data/maps/RustboroCity_House3/scripts.pory"
	msgbox RustboroCity_House3_Text_IGivePerfectlySuitedNicknames, MSGBOX_NPC
# 7 "data/maps/RustboroCity_House3/scripts.pory"
	end
# 8 "data/maps/RustboroCity_House3/scripts.pory"

# 9 "data/maps/RustboroCity_House3/scripts.pory"
RustboroCity_House3_EventScript_OldWoman::
# 10 "data/maps/RustboroCity_House3/scripts.pory"
	msgbox RustboroCity_House3_Text_NamingPikachuPekachu, MSGBOX_NPC
# 11 "data/maps/RustboroCity_House3/scripts.pory"
	end
# 12 "data/maps/RustboroCity_House3/scripts.pory"

# 13 "data/maps/RustboroCity_House3/scripts.pory"
@ Misspelling on purpose, see nickname
# 14 "data/maps/RustboroCity_House3/scripts.pory"
RustboroCity_House3_EventScript_Pekachu::
# 15 "data/maps/RustboroCity_House3/scripts.pory"
	lock
# 16 "data/maps/RustboroCity_House3/scripts.pory"
	faceplayer
# 17 "data/maps/RustboroCity_House3/scripts.pory"
	waitse
# 18 "data/maps/RustboroCity_House3/scripts.pory"
	playmoncry SPECIES_PIKACHU, CRY_MODE_NORMAL
# 19 "data/maps/RustboroCity_House3/scripts.pory"
	msgbox RustboroCity_House3_Text_Pekachu, MSGBOX_DEFAULT
# 20 "data/maps/RustboroCity_House3/scripts.pory"
	waitmoncry
# 21 "data/maps/RustboroCity_House3/scripts.pory"
	release
# 22 "data/maps/RustboroCity_House3/scripts.pory"
	end
# 23 "data/maps/RustboroCity_House3/scripts.pory"

# 24 "data/maps/RustboroCity_House3/scripts.pory"
RustboroCity_House3_Text_IGivePerfectlySuitedNicknames:
# 25 "data/maps/RustboroCity_House3/scripts.pory"
	.string "For my own POKéMON, I give them\n"
# 26 "data/maps/RustboroCity_House3/scripts.pory"
	.string "perfectly suited nicknames!\p"
# 27 "data/maps/RustboroCity_House3/scripts.pory"
	.string "It's my expression of, uh…\n"
# 28 "data/maps/RustboroCity_House3/scripts.pory"
	.string "originality, yes, that's it!$"
# 29 "data/maps/RustboroCity_House3/scripts.pory"

# 30 "data/maps/RustboroCity_House3/scripts.pory"
RustboroCity_House3_Text_NamingPikachuPekachu:
# 31 "data/maps/RustboroCity_House3/scripts.pory"
	.string "But giving the name PEKACHU to\n"
# 32 "data/maps/RustboroCity_House3/scripts.pory"
	.string "a PIKACHU? It seems pointless.\p"
# 33 "data/maps/RustboroCity_House3/scripts.pory"
	.string "I suppose it is good to use a name\n"
# 34 "data/maps/RustboroCity_House3/scripts.pory"
	.string "that's easy to understand, but…$"
# 35 "data/maps/RustboroCity_House3/scripts.pory"

# 36 "data/maps/RustboroCity_House3/scripts.pory"
RustboroCity_House3_Text_Pekachu:
# 37 "data/maps/RustboroCity_House3/scripts.pory"
	.string "PEKACHU: Peka!$"
