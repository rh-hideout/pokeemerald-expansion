# 1 "data/maps/PacifidlogTown_House3/scripts.pory"

# 2 "data/maps/PacifidlogTown_House3/scripts.pory"
PacifidlogTown_House3_MapScripts::
# 3 "data/maps/PacifidlogTown_House3/scripts.pory"
	.byte 0
# 4 "data/maps/PacifidlogTown_House3/scripts.pory"

# 5 "data/maps/PacifidlogTown_House3/scripts.pory"
PacifidlogTown_House3_EventScript_Trader::
# 6 "data/maps/PacifidlogTown_House3/scripts.pory"
	lock
# 7 "data/maps/PacifidlogTown_House3/scripts.pory"
	faceplayer
# 8 "data/maps/PacifidlogTown_House3/scripts.pory"
	goto_if_set FLAG_PACIFIDLOG_NPC_TRADE_COMPLETED, PacifidlogTown_House3_EventScript_TradeCompleted
# 9 "data/maps/PacifidlogTown_House3/scripts.pory"
	setvar VAR_0x8008, INGAME_TRADE_HORSEA
# 10 "data/maps/PacifidlogTown_House3/scripts.pory"
	copyvar VAR_0x8004, VAR_0x8008
# 11 "data/maps/PacifidlogTown_House3/scripts.pory"
	specialvar VAR_RESULT, GetInGameTradeSpeciesInfo
# 12 "data/maps/PacifidlogTown_House3/scripts.pory"
	copyvar VAR_0x8009, VAR_RESULT
# 13 "data/maps/PacifidlogTown_House3/scripts.pory"
	msgbox PacifidlogTown_House3_Text_WillingToTradeIt, MSGBOX_YESNO
# 14 "data/maps/PacifidlogTown_House3/scripts.pory"
	goto_if_eq VAR_RESULT, NO, PacifidlogTown_House3_EventScript_DeclineTrade
# 15 "data/maps/PacifidlogTown_House3/scripts.pory"
	special ChoosePartyMon
# 16 "data/maps/PacifidlogTown_House3/scripts.pory"
	waitstate
# 17 "data/maps/PacifidlogTown_House3/scripts.pory"
	copyvar VAR_0x800A, VAR_0x8004
# 18 "data/maps/PacifidlogTown_House3/scripts.pory"
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, PacifidlogTown_House3_EventScript_DeclineTrade
# 19 "data/maps/PacifidlogTown_House3/scripts.pory"
	copyvar VAR_0x8005, VAR_0x800A
# 20 "data/maps/PacifidlogTown_House3/scripts.pory"
	specialvar VAR_RESULT, GetTradeSpecies
# 21 "data/maps/PacifidlogTown_House3/scripts.pory"
	copyvar VAR_0x800B, VAR_RESULT
# 22 "data/maps/PacifidlogTown_House3/scripts.pory"
	goto_if_ne VAR_RESULT, VAR_0x8009, PacifidlogTown_House3_EventScript_NotRequestedMon
# 23 "data/maps/PacifidlogTown_House3/scripts.pory"
	copyvar VAR_0x8004, VAR_0x8008
# 24 "data/maps/PacifidlogTown_House3/scripts.pory"
	copyvar VAR_0x8005, VAR_0x800A
# 25 "data/maps/PacifidlogTown_House3/scripts.pory"
	special CreateInGameTradePokemon
# 26 "data/maps/PacifidlogTown_House3/scripts.pory"
	special DoInGameTradeScene
# 27 "data/maps/PacifidlogTown_House3/scripts.pory"
	waitstate
# 28 "data/maps/PacifidlogTown_House3/scripts.pory"
	bufferspeciesname STR_VAR_1, VAR_0x8009
# 29 "data/maps/PacifidlogTown_House3/scripts.pory"
	msgbox PacifidlogTown_House3_Text_ItsSubtlyDifferentThankYou, MSGBOX_DEFAULT
# 30 "data/maps/PacifidlogTown_House3/scripts.pory"
	setflag FLAG_PACIFIDLOG_NPC_TRADE_COMPLETED
# 31 "data/maps/PacifidlogTown_House3/scripts.pory"
	release
# 32 "data/maps/PacifidlogTown_House3/scripts.pory"
	end
# 33 "data/maps/PacifidlogTown_House3/scripts.pory"

# 34 "data/maps/PacifidlogTown_House3/scripts.pory"
PacifidlogTown_House3_EventScript_DeclineTrade::
# 35 "data/maps/PacifidlogTown_House3/scripts.pory"
	msgbox PacifidlogTown_House3_Text_NotDesperateOrAnything, MSGBOX_DEFAULT
# 36 "data/maps/PacifidlogTown_House3/scripts.pory"
	release
# 37 "data/maps/PacifidlogTown_House3/scripts.pory"
	end
# 38 "data/maps/PacifidlogTown_House3/scripts.pory"

# 39 "data/maps/PacifidlogTown_House3/scripts.pory"
PacifidlogTown_House3_EventScript_NotRequestedMon::
# 40 "data/maps/PacifidlogTown_House3/scripts.pory"
	bufferspeciesname STR_VAR_1, VAR_0x8009
# 41 "data/maps/PacifidlogTown_House3/scripts.pory"
	msgbox PacifidlogTown_House3_Text_WontAcceptAnyLessThanRealMon, MSGBOX_DEFAULT
# 42 "data/maps/PacifidlogTown_House3/scripts.pory"
	release
# 43 "data/maps/PacifidlogTown_House3/scripts.pory"
	end
# 44 "data/maps/PacifidlogTown_House3/scripts.pory"

# 45 "data/maps/PacifidlogTown_House3/scripts.pory"
PacifidlogTown_House3_EventScript_TradeCompleted::
# 46 "data/maps/PacifidlogTown_House3/scripts.pory"
	msgbox PacifidlogTown_House3_Text_ReallyWantedToGetBagon, MSGBOX_DEFAULT
# 47 "data/maps/PacifidlogTown_House3/scripts.pory"
	release
# 48 "data/maps/PacifidlogTown_House3/scripts.pory"
	end
# 49 "data/maps/PacifidlogTown_House3/scripts.pory"

# 50 "data/maps/PacifidlogTown_House3/scripts.pory"
PacifidlogTown_House3_EventScript_Girl::
# 51 "data/maps/PacifidlogTown_House3/scripts.pory"
	msgbox PacifidlogTown_House3_Text_IsThatAPokedex, MSGBOX_NPC
# 52 "data/maps/PacifidlogTown_House3/scripts.pory"
	end
# 53 "data/maps/PacifidlogTown_House3/scripts.pory"

# 54 "data/maps/PacifidlogTown_House3/scripts.pory"
PacifidlogTown_House3_Text_WillingToTradeIt:
# 55 "data/maps/PacifidlogTown_House3/scripts.pory"
	.string "Check out this {STR_VAR_2}!\p"
# 56 "data/maps/PacifidlogTown_House3/scripts.pory"
	.string "It's the {STR_VAR_2} that I caught\n"
# 57 "data/maps/PacifidlogTown_House3/scripts.pory"
	.string "yesterday to celebrate my birthday!\p"
# 58 "data/maps/PacifidlogTown_House3/scripts.pory"
	.string "Oh, I can see that you want it!\n"
# 59 "data/maps/PacifidlogTown_House3/scripts.pory"
	.string "After all, it's priceless!\p"
# 60 "data/maps/PacifidlogTown_House3/scripts.pory"
	.string "I'll tell you what. I might be willing\n"
# 61 "data/maps/PacifidlogTown_House3/scripts.pory"
	.string "to trade it for a {STR_VAR_1}.$"
# 62 "data/maps/PacifidlogTown_House3/scripts.pory"

# 63 "data/maps/PacifidlogTown_House3/scripts.pory"
PacifidlogTown_House3_Text_ItsSubtlyDifferentThankYou:
# 64 "data/maps/PacifidlogTown_House3/scripts.pory"
	.string "Oh, so this is a {STR_VAR_1}?\p"
# 65 "data/maps/PacifidlogTown_House3/scripts.pory"
	.string "It's sort of like a {STR_VAR_2},\n"
# 66 "data/maps/PacifidlogTown_House3/scripts.pory"
	.string "and yet it's subtly different.\p"
# 67 "data/maps/PacifidlogTown_House3/scripts.pory"
	.string "Thank you!$"
# 68 "data/maps/PacifidlogTown_House3/scripts.pory"

# 69 "data/maps/PacifidlogTown_House3/scripts.pory"
PacifidlogTown_House3_Text_WontAcceptAnyLessThanRealMon:
# 70 "data/maps/PacifidlogTown_House3/scripts.pory"
	.string "No, no, no! I won't accept any\n"
# 71 "data/maps/PacifidlogTown_House3/scripts.pory"
	.string "less than a real {STR_VAR_1}!$"
# 72 "data/maps/PacifidlogTown_House3/scripts.pory"

# 73 "data/maps/PacifidlogTown_House3/scripts.pory"
PacifidlogTown_House3_Text_NotDesperateOrAnything:
# 74 "data/maps/PacifidlogTown_House3/scripts.pory"
	.string "Oh, so you're not going to go through\n"
# 75 "data/maps/PacifidlogTown_House3/scripts.pory"
	.string "with this?\p"
# 76 "data/maps/PacifidlogTown_House3/scripts.pory"
	.string "That's cool. I'm not desperate to make\n"
# 77 "data/maps/PacifidlogTown_House3/scripts.pory"
	.string "a trade or anything.$"
# 78 "data/maps/PacifidlogTown_House3/scripts.pory"

# 79 "data/maps/PacifidlogTown_House3/scripts.pory"
PacifidlogTown_House3_Text_ReallyWantedToGetBagon:
# 80 "data/maps/PacifidlogTown_House3/scripts.pory"
	.string "I know I could go looking for one\n"
# 81 "data/maps/PacifidlogTown_House3/scripts.pory"
	.string "on my own, but…\p"
# 82 "data/maps/PacifidlogTown_House3/scripts.pory"
	.string "But I really wanted to get a BAGON\n"
# 83 "data/maps/PacifidlogTown_House3/scripts.pory"
	.string "that another TRAINER caught…$"
# 84 "data/maps/PacifidlogTown_House3/scripts.pory"

# 85 "data/maps/PacifidlogTown_House3/scripts.pory"
PacifidlogTown_House3_Text_IsThatAPokedex:
# 86 "data/maps/PacifidlogTown_House3/scripts.pory"
	.string "Is that a POKéDEX?\p"
# 87 "data/maps/PacifidlogTown_House3/scripts.pory"
	.string "Did you get to meet a lot of different\n"
# 88 "data/maps/PacifidlogTown_House3/scripts.pory"
	.string "POKéMON?\p"
# 89 "data/maps/PacifidlogTown_House3/scripts.pory"
	.string "I wish I was like you.$"
