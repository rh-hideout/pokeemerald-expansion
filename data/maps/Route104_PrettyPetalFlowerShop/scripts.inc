# 1 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"

# 2 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"
Route104_PrettyPetalFlowerShop_MapScripts::
# 3 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, Route104_PrettyPetalFlowerShop_OnTransition
# 4 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"
	.byte 0
# 5 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"

# 6 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"
Route104_PrettyPetalFlowerShop_OnTransition:
# 7 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"
	setflag FLAG_LANDMARK_FLOWER_SHOP
# 8 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"
	goto_if_unset FLAG_MET_PRETTY_PETAL_SHOP_OWNER, Route104_PrettyPetalFlowerShop_EventScript_MoveShopOwner
# 9 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"
	goto_if_unset FLAG_BADGE03_GET, Route104_PrettyPetalFlowerShop_EventScript_MoveShopOwner
# 10 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"
	setflag FLAG_TEMP_1
# 11 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"
	end
# 12 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"

# 13 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"
Route104_PrettyPetalFlowerShop_EventScript_MoveShopOwner::
# 14 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"
	setobjectxyperm LOCALID_FLOWER_SHOP_OWNER, 4, 6
# 15 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"
	end
# 16 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"

# 17 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"
Route104_PrettyPetalFlowerShop_EventScript_ShopOwner::
# 18 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"
	lock
# 19 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"
	faceplayer
# 20 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"
	goto_if_set FLAG_TEMP_1, Route104_PrettyPetalFlowerShop_EventScript_SellDecorations
# 21 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"
	msgbox Route104_PrettyPetalFlowerShop_Text_ThisIsPrettyPetalFlowerShop, MSGBOX_DEFAULT
# 22 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"
	goto_if_set FLAG_MET_PRETTY_PETAL_SHOP_OWNER, Route104_PrettyPetalFlowerShop_EventScript_AlreadyMet
# 23 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"
	setflag FLAG_MET_PRETTY_PETAL_SHOP_OWNER
# 24 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"
	msgbox Route104_PrettyPetalFlowerShop_Text_IntroLearnAboutBerries, MSGBOX_YESNO
# 25 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"
	call_if_eq VAR_RESULT, YES, Route104_PrettyPetalFlowerShop_EventScript_ExplainBerries
# 26 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"
	call_if_eq VAR_RESULT, NO, Route104_PrettyPetalFlowerShop_EventScript_DontExplainBerries
# 27 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"
	release
# 28 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"
	end
# 29 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"

# 30 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"
Route104_PrettyPetalFlowerShop_EventScript_AlreadyMet::
# 31 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"
	msgbox Route104_PrettyPetalFlowerShop_Text_LearnAboutBerries, MSGBOX_YESNO
# 32 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"
	call_if_eq VAR_RESULT, YES, Route104_PrettyPetalFlowerShop_EventScript_ExplainBerries
# 33 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"
	call_if_eq VAR_RESULT, NO, Route104_PrettyPetalFlowerShop_EventScript_DontExplainBerries
# 34 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"
	release
# 35 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"
	end
# 36 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"

# 37 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"
Route104_PrettyPetalFlowerShop_EventScript_ExplainBerries::
# 38 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"
	msgbox Route104_PrettyPetalFlowerShop_Text_BerriesExplanation, MSGBOX_DEFAULT
# 39 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"
	return
# 40 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"

# 41 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"
Route104_PrettyPetalFlowerShop_EventScript_DontExplainBerries::
# 42 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"
	msgbox Route104_PrettyPetalFlowerShop_Text_FlowersBringHappiness, MSGBOX_DEFAULT
# 43 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"
	return
# 44 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"

# 45 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"
Route104_PrettyPetalFlowerShop_EventScript_SellDecorations::
# 46 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"
	message gText_PlayerWhatCanIDoForYou
# 47 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"
	waitmessage
# 48 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"
	pokemartdecoration2 Route104_PrettyPetalFlowerShop_Pokemart_Plants
# 49 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
# 50 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"
	release
# 51 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"
	end
# 52 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"

# 53 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"
	.align 2
# 54 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"
Route104_PrettyPetalFlowerShop_Pokemart_Plants:
# 55 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"
	.2byte DECOR_RED_PLANT
# 56 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"
	.2byte DECOR_TROPICAL_PLANT
# 57 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"
	.2byte DECOR_PRETTY_FLOWERS
# 58 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"
	.2byte DECOR_COLORFUL_PLANT
# 59 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"
	.2byte DECOR_BIG_PLANT
# 60 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"
	.2byte DECOR_GORGEOUS_PLANT
# 61 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"
	pokemartlistend
# 62 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"

# 63 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"
Route104_PrettyPetalFlowerShop_EventScript_WailmerPailGirl::
# 64 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"
	lock
# 65 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"
	faceplayer
# 66 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"
	goto_if_unset FLAG_RECEIVED_WAILMER_PAIL, Route104_PrettyPetalFlowerShop_EventScript_GiveWailmerPail
# 67 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"
	msgbox Route104_PrettyPetalFlowerShop_Text_WailmerPailExplanation, MSGBOX_DEFAULT
# 68 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"
	release
# 69 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"
	end
# 70 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"

# 71 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"
Route104_PrettyPetalFlowerShop_EventScript_GiveWailmerPail::
# 72 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"
	msgbox Route104_PrettyPetalFlowerShop_Text_YouCanHaveThis, MSGBOX_DEFAULT
# 73 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"
	giveitem ITEM_WAILMER_PAIL
# 74 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
# 75 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"
	msgbox Route104_PrettyPetalFlowerShop_Text_WailmerPailExplanation, MSGBOX_DEFAULT
# 76 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"
	setflag FLAG_RECEIVED_WAILMER_PAIL
# 77 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"
	release
# 78 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"
	end
# 79 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"

# 80 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"
Route104_PrettyPetalFlowerShop_EventScript_RandomBerryGirl::
# 81 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"
	lock
# 82 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"
	faceplayer
# 83 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"
	dotimebasedevents
# 84 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"
	goto_if_set FLAG_DAILY_FLOWER_SHOP_RECEIVED_BERRY, Route104_PrettyPetalFlowerShop_EventScript_AlreadyReceivedBerry
# 85 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"
	msgbox Route104_PrettyPetalFlowerShop_Text_ImGrowingFlowers, MSGBOX_DEFAULT
# 86 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"
	random 8
# 87 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"
	addvar VAR_RESULT, FIRST_BERRY_INDEX
# 88 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"
	giveitem VAR_RESULT
# 89 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"
	goto_if_eq VAR_RESULT, 0, Common_EventScript_ShowBagIsFull
# 90 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"
	setflag FLAG_DAILY_FLOWER_SHOP_RECEIVED_BERRY
# 91 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"
	msgbox Route104_PrettyPetalFlowerShop_Text_MachineMixesBerries, MSGBOX_DEFAULT
# 92 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"
	release
# 93 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"
	end
# 94 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"

# 95 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"
Route104_PrettyPetalFlowerShop_EventScript_AlreadyReceivedBerry::
# 96 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"
	msgbox Route104_PrettyPetalFlowerShop_Text_MachineMixesBerries, MSGBOX_DEFAULT
# 97 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"
	release
# 98 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"
	end
