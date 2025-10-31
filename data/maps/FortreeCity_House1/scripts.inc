# 1 "data/maps/FortreeCity_House1/scripts.pory"

# 2 "data/maps/FortreeCity_House1/scripts.pory"
FortreeCity_House1_MapScripts::
# 3 "data/maps/FortreeCity_House1/scripts.pory"
	.byte 0
# 4 "data/maps/FortreeCity_House1/scripts.pory"

# 5 "data/maps/FortreeCity_House1/scripts.pory"
FortreeCity_House1_EventScript_Trader::
# 6 "data/maps/FortreeCity_House1/scripts.pory"
	lock
# 7 "data/maps/FortreeCity_House1/scripts.pory"
	faceplayer
# 8 "data/maps/FortreeCity_House1/scripts.pory"
	goto_if_set FLAG_FORTREE_NPC_TRADE_COMPLETED, FortreeCity_House1_EventScript_TradeCompleted
# 9 "data/maps/FortreeCity_House1/scripts.pory"
	setvar VAR_0x8008, INGAME_TRADE_PLUSLE
# 10 "data/maps/FortreeCity_House1/scripts.pory"
	copyvar VAR_0x8004, VAR_0x8008
# 11 "data/maps/FortreeCity_House1/scripts.pory"
	specialvar VAR_RESULT, GetInGameTradeSpeciesInfo
# 12 "data/maps/FortreeCity_House1/scripts.pory"
	copyvar VAR_0x8009, VAR_RESULT
# 13 "data/maps/FortreeCity_House1/scripts.pory"
	msgbox FortreeCity_House1_Text_YouWillTradeWontYou, MSGBOX_YESNO
# 14 "data/maps/FortreeCity_House1/scripts.pory"
	goto_if_eq VAR_RESULT, NO, FortreeCity_House1_EventScript_DeclineTrade
# 15 "data/maps/FortreeCity_House1/scripts.pory"
	special ChoosePartyMon
# 16 "data/maps/FortreeCity_House1/scripts.pory"
	waitstate
# 17 "data/maps/FortreeCity_House1/scripts.pory"
	copyvar VAR_0x800A, VAR_0x8004
# 18 "data/maps/FortreeCity_House1/scripts.pory"
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, FortreeCity_House1_EventScript_DeclineTrade
# 19 "data/maps/FortreeCity_House1/scripts.pory"
	copyvar VAR_0x8005, VAR_0x800A
# 20 "data/maps/FortreeCity_House1/scripts.pory"
	specialvar VAR_RESULT, GetTradeSpecies
# 21 "data/maps/FortreeCity_House1/scripts.pory"
	copyvar VAR_0x800B, VAR_RESULT
# 22 "data/maps/FortreeCity_House1/scripts.pory"
	goto_if_ne VAR_RESULT, VAR_0x8009, FortreeCity_House1_EventScript_NotRequestedMon
# 23 "data/maps/FortreeCity_House1/scripts.pory"
	copyvar VAR_0x8004, VAR_0x8008
# 24 "data/maps/FortreeCity_House1/scripts.pory"
	copyvar VAR_0x8005, VAR_0x800A
# 25 "data/maps/FortreeCity_House1/scripts.pory"
	special CreateInGameTradePokemon
# 26 "data/maps/FortreeCity_House1/scripts.pory"
	special DoInGameTradeScene
# 27 "data/maps/FortreeCity_House1/scripts.pory"
	waitstate
# 28 "data/maps/FortreeCity_House1/scripts.pory"
	bufferspeciesname STR_VAR_1, VAR_0x8009
# 29 "data/maps/FortreeCity_House1/scripts.pory"
	msgbox FortreeCity_House1_Text_MonYouTakeCare, MSGBOX_DEFAULT
# 30 "data/maps/FortreeCity_House1/scripts.pory"
	setflag FLAG_FORTREE_NPC_TRADE_COMPLETED
# 31 "data/maps/FortreeCity_House1/scripts.pory"
	release
# 32 "data/maps/FortreeCity_House1/scripts.pory"
	end
# 33 "data/maps/FortreeCity_House1/scripts.pory"

# 34 "data/maps/FortreeCity_House1/scripts.pory"
FortreeCity_House1_EventScript_DeclineTrade::
# 35 "data/maps/FortreeCity_House1/scripts.pory"
	msgbox FortreeCity_House1_Text_YouWontTradeMe, MSGBOX_DEFAULT
# 36 "data/maps/FortreeCity_House1/scripts.pory"
	release
# 37 "data/maps/FortreeCity_House1/scripts.pory"
	end
# 38 "data/maps/FortreeCity_House1/scripts.pory"

# 39 "data/maps/FortreeCity_House1/scripts.pory"
FortreeCity_House1_EventScript_NotRequestedMon::
# 40 "data/maps/FortreeCity_House1/scripts.pory"
	bufferspeciesname STR_VAR_1, VAR_0x8009
# 41 "data/maps/FortreeCity_House1/scripts.pory"
	msgbox FortreeCity_House1_Text_ThisIsntAMon, MSGBOX_DEFAULT
# 42 "data/maps/FortreeCity_House1/scripts.pory"
	release
# 43 "data/maps/FortreeCity_House1/scripts.pory"
	end
# 44 "data/maps/FortreeCity_House1/scripts.pory"

# 45 "data/maps/FortreeCity_House1/scripts.pory"
FortreeCity_House1_EventScript_TradeCompleted::
# 46 "data/maps/FortreeCity_House1/scripts.pory"
	msgbox FortreeCity_House1_Text_GoingToMakeVolbeatStrong, MSGBOX_DEFAULT
# 47 "data/maps/FortreeCity_House1/scripts.pory"
	release
# 48 "data/maps/FortreeCity_House1/scripts.pory"
	end
# 49 "data/maps/FortreeCity_House1/scripts.pory"

# 50 "data/maps/FortreeCity_House1/scripts.pory"
FortreeCity_House1_EventScript_ExpertF::
# 51 "data/maps/FortreeCity_House1/scripts.pory"
	msgbox FortreeCity_House1_Text_TradingMemoriesWithOthers, MSGBOX_NPC
# 52 "data/maps/FortreeCity_House1/scripts.pory"
	end
# 53 "data/maps/FortreeCity_House1/scripts.pory"

# 54 "data/maps/FortreeCity_House1/scripts.pory"
FortreeCity_House1_EventScript_Zigzagoon::
# 55 "data/maps/FortreeCity_House1/scripts.pory"
	lock
# 56 "data/maps/FortreeCity_House1/scripts.pory"
	faceplayer
# 57 "data/maps/FortreeCity_House1/scripts.pory"
	waitse
# 58 "data/maps/FortreeCity_House1/scripts.pory"
	playmoncry SPECIES_ZIGZAGOON, CRY_MODE_NORMAL
# 59 "data/maps/FortreeCity_House1/scripts.pory"
	msgbox FortreeCity_House1_Text_Zigzagoon, MSGBOX_DEFAULT
# 60 "data/maps/FortreeCity_House1/scripts.pory"
	waitmoncry
# 61 "data/maps/FortreeCity_House1/scripts.pory"
	release
# 62 "data/maps/FortreeCity_House1/scripts.pory"
	end
# 63 "data/maps/FortreeCity_House1/scripts.pory"

# 64 "data/maps/FortreeCity_House1/scripts.pory"
FortreeCity_House1_Text_YouWillTradeWontYou:
# 65 "data/maps/FortreeCity_House1/scripts.pory"
	.string "Wrooooaaar! I need it!\n"
# 66 "data/maps/FortreeCity_House1/scripts.pory"
	.string "I have to get me a {STR_VAR_1}!\l"
# 67 "data/maps/FortreeCity_House1/scripts.pory"
	.string "I'll do anything for it!\p"
# 68 "data/maps/FortreeCity_House1/scripts.pory"
	.string "…Uh… Did you hear that?\n"
# 69 "data/maps/FortreeCity_House1/scripts.pory"
	.string "My shout from the bottom of my heart?\p"
# 70 "data/maps/FortreeCity_House1/scripts.pory"
	.string "Having heard that, you will trade\n"
# 71 "data/maps/FortreeCity_House1/scripts.pory"
	.string "your {STR_VAR_1} for my {STR_VAR_2},\l"
# 72 "data/maps/FortreeCity_House1/scripts.pory"
	.string "won't you?$"
# 73 "data/maps/FortreeCity_House1/scripts.pory"

# 74 "data/maps/FortreeCity_House1/scripts.pory"
FortreeCity_House1_Text_MonYouTakeCare:
# 75 "data/maps/FortreeCity_House1/scripts.pory"
	.string "Oh, yeah, right on!\p"
# 76 "data/maps/FortreeCity_House1/scripts.pory"
	.string "{STR_VAR_1}, welcome!\n"
# 77 "data/maps/FortreeCity_House1/scripts.pory"
	.string "{STR_VAR_2}, you take care!$"
# 78 "data/maps/FortreeCity_House1/scripts.pory"

# 79 "data/maps/FortreeCity_House1/scripts.pory"
FortreeCity_House1_Text_ThisIsntAMon:
# 80 "data/maps/FortreeCity_House1/scripts.pory"
	.string "Uh, no, I don't think so.\n"
# 81 "data/maps/FortreeCity_House1/scripts.pory"
	.string "That isn't a {STR_VAR_1}.$"
# 82 "data/maps/FortreeCity_House1/scripts.pory"

# 83 "data/maps/FortreeCity_House1/scripts.pory"
FortreeCity_House1_Text_YouWontTradeMe:
# 84 "data/maps/FortreeCity_House1/scripts.pory"
	.string "No? You won't trade me?\n"
# 85 "data/maps/FortreeCity_House1/scripts.pory"
	.string "Even after I bared my heart to you?$"
# 86 "data/maps/FortreeCity_House1/scripts.pory"

# 87 "data/maps/FortreeCity_House1/scripts.pory"
FortreeCity_House1_Text_GoingToMakeVolbeatStrong:
# 88 "data/maps/FortreeCity_House1/scripts.pory"
	.string "I'm going to make VOLBEAT super\n"
# 89 "data/maps/FortreeCity_House1/scripts.pory"
	.string "strong from this moment on!\p"
# 90 "data/maps/FortreeCity_House1/scripts.pory"
	.string "I hope you do the same with PLUSLE!$"
# 91 "data/maps/FortreeCity_House1/scripts.pory"

# 92 "data/maps/FortreeCity_House1/scripts.pory"
FortreeCity_House1_Text_TradingMemoriesWithOthers:
# 93 "data/maps/FortreeCity_House1/scripts.pory"
	.string "Trading POKéMON with others…\p"
# 94 "data/maps/FortreeCity_House1/scripts.pory"
	.string "It's as if you're trading your own\n"
# 95 "data/maps/FortreeCity_House1/scripts.pory"
	.string "memories with other people.$"
# 96 "data/maps/FortreeCity_House1/scripts.pory"

# 97 "data/maps/FortreeCity_House1/scripts.pory"
FortreeCity_House1_Text_Zigzagoon:
# 98 "data/maps/FortreeCity_House1/scripts.pory"
	.string "ZIGZAGOON: Gumomoh?$"
