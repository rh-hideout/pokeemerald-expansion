Common_EventScript_WonderTrader::
    lockall
    faceplayer
    msgbox WonderTrade_Text_WonderTradeIntro, MSGBOX_YESNO
    goto_if_eq VAR_RESULT, NO, Common_Eventscript_WonderTraderDecline
    msgbox WonderTrade_Text_WhichPokemonSend, MSGBOX_DEFAULT
    special ChoosePartyMon
    waitstate
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, Common_Eventscript_WonderTraderDecline
    msgbox WonderTrade_Text_AreYouSure, MSGBOX_YESNO
    goto_if_eq VAR_RESULT, NO, Common_Eventscript_WonderTraderDecline
    msgbox WonderTrade_Text_Wonderful, MSGBOX_DEFAULT
    copyvar VAR_0x8005, VAR_0x8004
	callnative CreateWonderTradePokemon
	callnative DoSurpriseTrade
    waitstate
    msgbox WonderTrade_Text_Complete, MSGBOX_DEFAULT
	release
	end

Common_Eventscript_WonderTraderDecline::
    msgbox WonderTrade_Text_Decline, MSGBOX_DEFAULT
    releaseall
    end
