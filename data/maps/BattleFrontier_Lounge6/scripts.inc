# 1 "data/maps/BattleFrontier_Lounge6/scripts.pory"

# 2 "data/maps/BattleFrontier_Lounge6/scripts.pory"
BattleFrontier_Lounge6_MapScripts::
# 3 "data/maps/BattleFrontier_Lounge6/scripts.pory"
	.byte 0
# 4 "data/maps/BattleFrontier_Lounge6/scripts.pory"

# 5 "data/maps/BattleFrontier_Lounge6/scripts.pory"
BattleFrontier_Lounge6_EventScript_Trader::
# 6 "data/maps/BattleFrontier_Lounge6/scripts.pory"
	lock
# 7 "data/maps/BattleFrontier_Lounge6/scripts.pory"
	faceplayer
# 8 "data/maps/BattleFrontier_Lounge6/scripts.pory"
	goto_if_set FLAG_BATTLE_FRONTIER_TRADE_DONE, BattleFrontier_Lounge6_EventScript_TradeCompleted
# 9 "data/maps/BattleFrontier_Lounge6/scripts.pory"
	setvar VAR_0x8008, INGAME_TRADE_MEOWTH
# 10 "data/maps/BattleFrontier_Lounge6/scripts.pory"
	copyvar VAR_0x8004, VAR_0x8008
# 11 "data/maps/BattleFrontier_Lounge6/scripts.pory"
	specialvar VAR_RESULT, GetInGameTradeSpeciesInfo
# 12 "data/maps/BattleFrontier_Lounge6/scripts.pory"
	copyvar VAR_0x8009, VAR_RESULT
# 13 "data/maps/BattleFrontier_Lounge6/scripts.pory"
	msgbox BattleFrontier_Lounge6_Text_WouldYouLikeToTrade, MSGBOX_YESNO
# 14 "data/maps/BattleFrontier_Lounge6/scripts.pory"
	goto_if_eq VAR_RESULT, NO, BattleFrontier_Lounge6_EventScript_DeclineTrade
# 15 "data/maps/BattleFrontier_Lounge6/scripts.pory"
	special ChoosePartyMon
# 16 "data/maps/BattleFrontier_Lounge6/scripts.pory"
	waitstate
# 17 "data/maps/BattleFrontier_Lounge6/scripts.pory"
	copyvar VAR_0x800A, VAR_0x8004
# 18 "data/maps/BattleFrontier_Lounge6/scripts.pory"
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, BattleFrontier_Lounge6_EventScript_DeclineTrade
# 19 "data/maps/BattleFrontier_Lounge6/scripts.pory"
	copyvar VAR_0x8005, VAR_0x800A
# 20 "data/maps/BattleFrontier_Lounge6/scripts.pory"
	specialvar VAR_RESULT, GetTradeSpecies
# 21 "data/maps/BattleFrontier_Lounge6/scripts.pory"
	copyvar VAR_0x800B, VAR_RESULT
# 22 "data/maps/BattleFrontier_Lounge6/scripts.pory"
	goto_if_ne VAR_RESULT, VAR_0x8009, BattleFrontier_Lounge6_EventScript_NotRequestedMon
# 23 "data/maps/BattleFrontier_Lounge6/scripts.pory"
	copyvar VAR_0x8004, VAR_0x8008
# 24 "data/maps/BattleFrontier_Lounge6/scripts.pory"
	copyvar VAR_0x8005, VAR_0x800A
# 25 "data/maps/BattleFrontier_Lounge6/scripts.pory"
	special CreateInGameTradePokemon
# 26 "data/maps/BattleFrontier_Lounge6/scripts.pory"
	special DoInGameTradeScene
# 27 "data/maps/BattleFrontier_Lounge6/scripts.pory"
	waitstate
# 28 "data/maps/BattleFrontier_Lounge6/scripts.pory"
	msgbox BattleFrontier_Lounge6_Text_PromiseIllBeGoodToIt, MSGBOX_DEFAULT
# 29 "data/maps/BattleFrontier_Lounge6/scripts.pory"
	setflag FLAG_BATTLE_FRONTIER_TRADE_DONE
# 30 "data/maps/BattleFrontier_Lounge6/scripts.pory"
	release
# 31 "data/maps/BattleFrontier_Lounge6/scripts.pory"
	end
# 32 "data/maps/BattleFrontier_Lounge6/scripts.pory"

# 33 "data/maps/BattleFrontier_Lounge6/scripts.pory"
BattleFrontier_Lounge6_EventScript_DeclineTrade::
# 34 "data/maps/BattleFrontier_Lounge6/scripts.pory"
	msgbox BattleFrontier_Lounge6_Text_WellThatsFineToo, MSGBOX_DEFAULT
# 35 "data/maps/BattleFrontier_Lounge6/scripts.pory"
	release
# 36 "data/maps/BattleFrontier_Lounge6/scripts.pory"
	end
# 37 "data/maps/BattleFrontier_Lounge6/scripts.pory"

# 38 "data/maps/BattleFrontier_Lounge6/scripts.pory"
BattleFrontier_Lounge6_EventScript_NotRequestedMon::
# 39 "data/maps/BattleFrontier_Lounge6/scripts.pory"
	bufferspeciesname STR_VAR_1, VAR_0x8009
# 40 "data/maps/BattleFrontier_Lounge6/scripts.pory"
	msgbox BattleFrontier_Lounge6_Text_DontTradeForAnythingButMon, MSGBOX_DEFAULT
# 41 "data/maps/BattleFrontier_Lounge6/scripts.pory"
	release
# 42 "data/maps/BattleFrontier_Lounge6/scripts.pory"
	end
# 43 "data/maps/BattleFrontier_Lounge6/scripts.pory"

# 44 "data/maps/BattleFrontier_Lounge6/scripts.pory"
BattleFrontier_Lounge6_EventScript_TradeCompleted::
# 45 "data/maps/BattleFrontier_Lounge6/scripts.pory"
	msgbox BattleFrontier_Lounge6_Text_SkittySoMuchCuterThanImagined, MSGBOX_DEFAULT
# 46 "data/maps/BattleFrontier_Lounge6/scripts.pory"
	release
# 47 "data/maps/BattleFrontier_Lounge6/scripts.pory"
	end
# 48 "data/maps/BattleFrontier_Lounge6/scripts.pory"

# 49 "data/maps/BattleFrontier_Lounge6/scripts.pory"
BattleFrontier_Lounge6_Text_WouldYouLikeToTrade:
# 50 "data/maps/BattleFrontier_Lounge6/scripts.pory"
	.string "My POKéMON is a {STR_VAR_2}.\n"
# 51 "data/maps/BattleFrontier_Lounge6/scripts.pory"
	.string "Do you know it?\l"
# 52 "data/maps/BattleFrontier_Lounge6/scripts.pory"
	.string "It's quite cute and rather nice.\p"
# 53 "data/maps/BattleFrontier_Lounge6/scripts.pory"
	.string "This little one, I could trade with\n"
# 54 "data/maps/BattleFrontier_Lounge6/scripts.pory"
	.string "pride!\p"
# 55 "data/maps/BattleFrontier_Lounge6/scripts.pory"
	.string "Would you like to trade me a {STR_VAR_1}\n"
# 56 "data/maps/BattleFrontier_Lounge6/scripts.pory"
	.string "for my {STR_VAR_2}?$"
# 57 "data/maps/BattleFrontier_Lounge6/scripts.pory"

# 58 "data/maps/BattleFrontier_Lounge6/scripts.pory"
BattleFrontier_Lounge6_Text_PromiseIllBeGoodToIt:
# 59 "data/maps/BattleFrontier_Lounge6/scripts.pory"
	.string "Oh, it's adorable!\n"
# 60 "data/maps/BattleFrontier_Lounge6/scripts.pory"
	.string "Thank you!\l"
# 61 "data/maps/BattleFrontier_Lounge6/scripts.pory"
	.string "I promise I'll be good to it!\p"
# 62 "data/maps/BattleFrontier_Lounge6/scripts.pory"
	.string "Oh! I hope you'll be good to\n"
# 63 "data/maps/BattleFrontier_Lounge6/scripts.pory"
	.string "my {STR_VAR_2}, too!$"
# 64 "data/maps/BattleFrontier_Lounge6/scripts.pory"

# 65 "data/maps/BattleFrontier_Lounge6/scripts.pory"
BattleFrontier_Lounge6_Text_DontTradeForAnythingButMon:
# 66 "data/maps/BattleFrontier_Lounge6/scripts.pory"
	.string "Oh, I'm sorry!\n"
# 67 "data/maps/BattleFrontier_Lounge6/scripts.pory"
	.string "I don't intend to trade for anything\l"
# 68 "data/maps/BattleFrontier_Lounge6/scripts.pory"
	.string "but a {STR_VAR_1}.$"
# 69 "data/maps/BattleFrontier_Lounge6/scripts.pory"

# 70 "data/maps/BattleFrontier_Lounge6/scripts.pory"
BattleFrontier_Lounge6_Text_WellThatsFineToo:
# 71 "data/maps/BattleFrontier_Lounge6/scripts.pory"
	.string "Oh, you won't?\n"
# 72 "data/maps/BattleFrontier_Lounge6/scripts.pory"
	.string "Well, that's fine, too.\l"
# 73 "data/maps/BattleFrontier_Lounge6/scripts.pory"
	.string "Please come visit us again.$"
# 74 "data/maps/BattleFrontier_Lounge6/scripts.pory"

# 75 "data/maps/BattleFrontier_Lounge6/scripts.pory"
BattleFrontier_Lounge6_Text_SkittySoMuchCuterThanImagined:
# 76 "data/maps/BattleFrontier_Lounge6/scripts.pory"
	.string "Giggle!\n"
# 77 "data/maps/BattleFrontier_Lounge6/scripts.pory"
	.string "A SKITTY is so much cuter than I had\l"
# 78 "data/maps/BattleFrontier_Lounge6/scripts.pory"
	.string "imagined. I'm delighted!$"
