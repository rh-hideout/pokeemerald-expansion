# 1 "data/maps/RustboroCity_House1/scripts.pory"

# 2 "data/maps/RustboroCity_House1/scripts.pory"
RustboroCity_House1_MapScripts::
# 3 "data/maps/RustboroCity_House1/scripts.pory"
	.byte 0
# 4 "data/maps/RustboroCity_House1/scripts.pory"

# 5 "data/maps/RustboroCity_House1/scripts.pory"
RustboroCity_House1_EventScript_Trader::
# 6 "data/maps/RustboroCity_House1/scripts.pory"
	lock
# 7 "data/maps/RustboroCity_House1/scripts.pory"
	faceplayer
# 8 "data/maps/RustboroCity_House1/scripts.pory"
	goto_if_set FLAG_RUSTBORO_NPC_TRADE_COMPLETED, RustboroCity_House1_EventScript_TradeCompleted
# 9 "data/maps/RustboroCity_House1/scripts.pory"
	setvar VAR_0x8008, INGAME_TRADE_SEEDOT
# 10 "data/maps/RustboroCity_House1/scripts.pory"
	copyvar VAR_0x8004, VAR_0x8008
# 11 "data/maps/RustboroCity_House1/scripts.pory"
	specialvar VAR_RESULT, GetInGameTradeSpeciesInfo
# 12 "data/maps/RustboroCity_House1/scripts.pory"
	copyvar VAR_0x8009, VAR_RESULT
# 13 "data/maps/RustboroCity_House1/scripts.pory"
	msgbox RustboroCity_House1_Text_IllTradeIfYouWant, MSGBOX_YESNO
# 14 "data/maps/RustboroCity_House1/scripts.pory"
	goto_if_eq VAR_RESULT, NO, RustboroCity_House1_EventScript_DeclineTrade
# 15 "data/maps/RustboroCity_House1/scripts.pory"
	special ChoosePartyMon
# 16 "data/maps/RustboroCity_House1/scripts.pory"
	waitstate
# 17 "data/maps/RustboroCity_House1/scripts.pory"
	copyvar VAR_0x800A, VAR_0x8004
# 18 "data/maps/RustboroCity_House1/scripts.pory"
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, RustboroCity_House1_EventScript_DeclineTrade
# 19 "data/maps/RustboroCity_House1/scripts.pory"
	copyvar VAR_0x8005, VAR_0x800A
# 20 "data/maps/RustboroCity_House1/scripts.pory"
	specialvar VAR_RESULT, GetTradeSpecies
# 21 "data/maps/RustboroCity_House1/scripts.pory"
	copyvar VAR_0x800B, VAR_RESULT
# 22 "data/maps/RustboroCity_House1/scripts.pory"
	goto_if_ne VAR_RESULT, VAR_0x8009, RustboroCity_House1_EventScript_NotRequestedMon
# 23 "data/maps/RustboroCity_House1/scripts.pory"
	copyvar VAR_0x8004, VAR_0x8008
# 24 "data/maps/RustboroCity_House1/scripts.pory"
	copyvar VAR_0x8005, VAR_0x800A
# 25 "data/maps/RustboroCity_House1/scripts.pory"
	special CreateInGameTradePokemon
# 26 "data/maps/RustboroCity_House1/scripts.pory"
	special DoInGameTradeScene
# 27 "data/maps/RustboroCity_House1/scripts.pory"
	waitstate
# 28 "data/maps/RustboroCity_House1/scripts.pory"
	msgbox RustboroCity_House1_Text_PleaseBeGoodToMyPokemon, MSGBOX_DEFAULT
# 29 "data/maps/RustboroCity_House1/scripts.pory"
	setflag FLAG_RUSTBORO_NPC_TRADE_COMPLETED
# 30 "data/maps/RustboroCity_House1/scripts.pory"
	release
# 31 "data/maps/RustboroCity_House1/scripts.pory"
	end
# 32 "data/maps/RustboroCity_House1/scripts.pory"

# 33 "data/maps/RustboroCity_House1/scripts.pory"
RustboroCity_House1_EventScript_DeclineTrade::
# 34 "data/maps/RustboroCity_House1/scripts.pory"
	msgbox RustboroCity_House1_Text_YouDontWantToThatsOkay, MSGBOX_DEFAULT
# 35 "data/maps/RustboroCity_House1/scripts.pory"
	release
# 36 "data/maps/RustboroCity_House1/scripts.pory"
	end
# 37 "data/maps/RustboroCity_House1/scripts.pory"

# 38 "data/maps/RustboroCity_House1/scripts.pory"
RustboroCity_House1_EventScript_NotRequestedMon::
# 39 "data/maps/RustboroCity_House1/scripts.pory"
	bufferspeciesname STR_VAR_1, VAR_0x8009
# 40 "data/maps/RustboroCity_House1/scripts.pory"
	msgbox RustboroCity_House1_Text_DoesntLookLikeMonToMe, MSGBOX_DEFAULT
# 41 "data/maps/RustboroCity_House1/scripts.pory"
	release
# 42 "data/maps/RustboroCity_House1/scripts.pory"
	end
# 43 "data/maps/RustboroCity_House1/scripts.pory"

# 44 "data/maps/RustboroCity_House1/scripts.pory"
RustboroCity_House1_EventScript_TradeCompleted::
# 45 "data/maps/RustboroCity_House1/scripts.pory"
	msgbox RustboroCity_House1_Text_AnyPokemonCanBeCute, MSGBOX_DEFAULT
# 46 "data/maps/RustboroCity_House1/scripts.pory"
	release
# 47 "data/maps/RustboroCity_House1/scripts.pory"
	end
# 48 "data/maps/RustboroCity_House1/scripts.pory"

# 49 "data/maps/RustboroCity_House1/scripts.pory"
RustboroCity_House1_EventScript_Hiker::
# 50 "data/maps/RustboroCity_House1/scripts.pory"
	msgbox RustboroCity_House1_Text_AllSortsOfPlaces, MSGBOX_NPC
# 51 "data/maps/RustboroCity_House1/scripts.pory"
	end
# 52 "data/maps/RustboroCity_House1/scripts.pory"

# 53 "data/maps/RustboroCity_House1/scripts.pory"
RustboroCity_House1_Text_IllTradeIfYouWant:
# 54 "data/maps/RustboroCity_House1/scripts.pory"
	.string "Huh? My POKéMON is cute?\n"
# 55 "data/maps/RustboroCity_House1/scripts.pory"
	.string "Sure, I knew that.\p"
# 56 "data/maps/RustboroCity_House1/scripts.pory"
	.string "But if you really want, I'm willing\n"
# 57 "data/maps/RustboroCity_House1/scripts.pory"
	.string "to trade it to you.\p"
# 58 "data/maps/RustboroCity_House1/scripts.pory"
	.string "I'll trade you my {STR_VAR_2} for\n"
# 59 "data/maps/RustboroCity_House1/scripts.pory"
	.string "a {STR_VAR_1} if you want.$"
# 60 "data/maps/RustboroCity_House1/scripts.pory"

# 61 "data/maps/RustboroCity_House1/scripts.pory"
RustboroCity_House1_Text_PleaseBeGoodToMyPokemon:
# 62 "data/maps/RustboroCity_House1/scripts.pory"
	.string "Eheheh…\n"
# 63 "data/maps/RustboroCity_House1/scripts.pory"
	.string "Please be good to my POKéMON.$"
# 64 "data/maps/RustboroCity_House1/scripts.pory"

# 65 "data/maps/RustboroCity_House1/scripts.pory"
RustboroCity_House1_Text_DoesntLookLikeMonToMe:
# 66 "data/maps/RustboroCity_House1/scripts.pory"
	.string "Huh? That doesn't look anything like\n"
# 67 "data/maps/RustboroCity_House1/scripts.pory"
	.string "a {STR_VAR_1} to me.$"
# 68 "data/maps/RustboroCity_House1/scripts.pory"

# 69 "data/maps/RustboroCity_House1/scripts.pory"
RustboroCity_House1_Text_YouDontWantToThatsOkay:
# 70 "data/maps/RustboroCity_House1/scripts.pory"
	.string "Oh, if you don't want to, that's okay.\n"
# 71 "data/maps/RustboroCity_House1/scripts.pory"
	.string "But my POKéMON is cute, you know…$"
# 72 "data/maps/RustboroCity_House1/scripts.pory"

# 73 "data/maps/RustboroCity_House1/scripts.pory"
RustboroCity_House1_Text_AnyPokemonCanBeCute:
# 74 "data/maps/RustboroCity_House1/scripts.pory"
	.string "Any POKéMON can be cute if you raise\n"
# 75 "data/maps/RustboroCity_House1/scripts.pory"
	.string "it with care and kindness.$"
# 76 "data/maps/RustboroCity_House1/scripts.pory"

# 77 "data/maps/RustboroCity_House1/scripts.pory"
RustboroCity_House1_Text_AllSortsOfPlaces:
# 78 "data/maps/RustboroCity_House1/scripts.pory"
	.string "In all sorts of places, there are all\n"
# 79 "data/maps/RustboroCity_House1/scripts.pory"
	.string "sorts of POKéMON and people.\p"
# 80 "data/maps/RustboroCity_House1/scripts.pory"
	.string "I find that fascinating, so I go to all\n"
# 81 "data/maps/RustboroCity_House1/scripts.pory"
	.string "sorts of places.$"
