BattleFrontier_Lounge6_hns_MapScripts::
	.byte 0

BattleFrontier_Lounge6_EventScript_Trader_hns::
	lock
	faceplayer
	goto_if_set FLAG_BATTLE_FRONTIER_TRADE_DONE, BattleFrontier_Lounge6_EventScript_TradeCompleted_hns
	ingame_trade INGAME_TRADE_MEOWTH, BattleFrontier_Lounge6_Text_WouldYouLikeToTrade_hns, BattleFrontier_Lounge6_EventScript_DeclineTrade_hns, BattleFrontier_Lounge6_EventScript_NotRequestedMon_hns, BattleFrontier_Lounge6_Text_PromiseIllBeGoodToIt_hns
	setflag FLAG_BATTLE_FRONTIER_TRADE_DONE
	release
	end

BattleFrontier_Lounge6_EventScript_DeclineTrade_hns::
	msgbox BattleFrontier_Lounge6_Text_WellThatsFineToo_hns, MSGBOX_DEFAULT
	release
	end

BattleFrontier_Lounge6_EventScript_NotRequestedMon_hns::
	bufferspeciesname STR_VAR_1, VAR_0x8009
	msgbox BattleFrontier_Lounge6_Text_DontTradeForAnythingButMon_hns, MSGBOX_DEFAULT
	release
	end

BattleFrontier_Lounge6_EventScript_TradeCompleted_hns::
	msgbox BattleFrontier_Lounge6_Text_SkittySoMuchCuterThanImagined_hns, MSGBOX_DEFAULT
	release
	end

BattleFrontier_Lounge6_Text_WouldYouLikeToTrade_hns:
	.string "My POKéMON is a {STR_VAR_2}.\n"
	.string "Do you know it?\l"
	.string "It's quite cute and rather nice.\p"
	.string "This little one, I could trade with\n"
	.string "pride!\p"
	.string "Would you like to trade me a {STR_VAR_1}\n"
	.string "for my {STR_VAR_2}?$"

BattleFrontier_Lounge6_Text_PromiseIllBeGoodToIt_hns:
	.string "Oh, it's adorable!\n"
	.string "Thank you!\l"
	.string "I promise I'll be good to it!\p"
	.string "Oh! I hope you'll be good to\n"
	.string "my {STR_VAR_2}, too!$"

BattleFrontier_Lounge6_Text_DontTradeForAnythingButMon_hns:
	.string "Oh, I'm sorry!\n"
	.string "I don't intend to trade for anything\l"
	.string "but a {STR_VAR_1}.$"

BattleFrontier_Lounge6_Text_WellThatsFineToo_hns:
	.string "Oh, you won't?\n"
	.string "Well, that's fine, too.\l"
	.string "Please come visit us again.$"

BattleFrontier_Lounge6_Text_SkittySoMuchCuterThanImagined_hns:
	.string "Giggle!\n"
	.string "A SKITTY is so much cuter than I had\l"
	.string "imagined. I'm delighted!$"
