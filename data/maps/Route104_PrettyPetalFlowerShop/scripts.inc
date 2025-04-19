# 1 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"

# 2 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"
.set LOCALID_OWNER, 1
# 3 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"

# 4 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"
Route104_PrettyPetalFlowerShop_MapScripts::
# 5 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, Route104_PrettyPetalFlowerShop_OnTransition
# 6 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"
	.byte 0
# 7 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"

# 8 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"
Route104_PrettyPetalFlowerShop_OnTransition:
# 9 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"
	setflag FLAG_LANDMARK_FLOWER_SHOP
# 10 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"
	goto_if_unset FLAG_MET_PRETTY_PETAL_SHOP_OWNER, Route104_PrettyPetalFlowerShop_EventScript_MoveShopOwner
# 11 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"
	goto_if_unset FLAG_BADGE03_GET, Route104_PrettyPetalFlowerShop_EventScript_MoveShopOwner
# 12 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"
	setflag FLAG_TEMP_1
# 13 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"
	end
# 14 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"

# 15 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"
Route104_PrettyPetalFlowerShop_EventScript_MoveShopOwner::
# 16 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"
	setobjectxyperm LOCALID_OWNER, 4, 6
# 17 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"
	end
# 18 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"

# 19 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"
Route104_PrettyPetalFlowerShop_EventScript_ShopOwner::
# 20 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"
	lock
# 21 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"
	faceplayer
# 22 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"
	goto_if_set FLAG_TEMP_1, Route104_PrettyPetalFlowerShop_EventScript_SellDecorations
# 23 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"
	msgbox Route104_PrettyPetalFlowerShop_Text_ThisIsPrettyPetalFlowerShop, MSGBOX_DEFAULT
# 24 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"
	goto_if_set FLAG_MET_PRETTY_PETAL_SHOP_OWNER, Route104_PrettyPetalFlowerShop_EventScript_AlreadyMet
# 25 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"
	setflag FLAG_MET_PRETTY_PETAL_SHOP_OWNER
# 26 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"
	msgbox Route104_PrettyPetalFlowerShop_Text_IntroLearnAboutBerries, MSGBOX_YESNO
# 27 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"
	call_if_eq VAR_RESULT, YES, Route104_PrettyPetalFlowerShop_EventScript_ExplainBerries
# 28 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"
	call_if_eq VAR_RESULT, NO, Route104_PrettyPetalFlowerShop_EventScript_DontExplainBerries
# 29 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"
	release
# 30 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"
	end
# 31 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"

# 32 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"
Route104_PrettyPetalFlowerShop_EventScript_AlreadyMet::
# 33 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"
	msgbox Route104_PrettyPetalFlowerShop_Text_LearnAboutBerries, MSGBOX_YESNO
# 34 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"
	call_if_eq VAR_RESULT, YES, Route104_PrettyPetalFlowerShop_EventScript_ExplainBerries
# 35 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"
	call_if_eq VAR_RESULT, NO, Route104_PrettyPetalFlowerShop_EventScript_DontExplainBerries
# 36 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"
	release
# 37 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"
	end
# 38 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"

# 39 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"
Route104_PrettyPetalFlowerShop_EventScript_ExplainBerries::
# 40 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"
	msgbox Route104_PrettyPetalFlowerShop_Text_BerriesExplanation, MSGBOX_DEFAULT
# 41 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"
	return
# 42 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"

# 43 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"
Route104_PrettyPetalFlowerShop_EventScript_DontExplainBerries::
# 44 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"
	msgbox Route104_PrettyPetalFlowerShop_Text_FlowersBringHappiness, MSGBOX_DEFAULT
# 45 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"
	return
# 46 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"

# 47 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"
Route104_PrettyPetalFlowerShop_EventScript_SellDecorations::
# 48 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"
	message gText_PlayerWhatCanIDoForYou
# 49 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"
	waitmessage
# 50 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"
	pokemartdecoration2 Route104_PrettyPetalFlowerShop_Pokemart_Plants
# 51 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
# 52 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"
	release
# 53 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"
	end
# 54 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"

# 55 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"
	.align 2
# 56 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"
Route104_PrettyPetalFlowerShop_Pokemart_Plants:
# 57 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"
	.2byte DECOR_RED_PLANT
# 58 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"
	.2byte DECOR_TROPICAL_PLANT
# 59 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"
	.2byte DECOR_PRETTY_FLOWERS
# 60 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"
	.2byte DECOR_COLORFUL_PLANT
# 61 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"
	.2byte DECOR_BIG_PLANT
# 62 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"
	.2byte DECOR_GORGEOUS_PLANT
# 63 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"
	pokemartlistend
# 64 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"

# 65 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"
Route104_PrettyPetalFlowerShop_EventScript_WailmerPailGirl::
# 66 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"
	lock
# 67 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"
	faceplayer
# 68 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"
	goto_if_unset FLAG_RECEIVED_WAILMER_PAIL, Route104_PrettyPetalFlowerShop_EventScript_GiveWailmerPail
# 69 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"
	msgbox Route104_PrettyPetalFlowerShop_Text_WailmerPailExplanation, MSGBOX_DEFAULT
# 70 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"
	release
# 71 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"
	end
# 72 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"

# 73 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"
Route104_PrettyPetalFlowerShop_EventScript_GiveWailmerPail::
# 74 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"
	msgbox Route104_PrettyPetalFlowerShop_Text_YouCanHaveThis, MSGBOX_DEFAULT
# 75 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"
	giveitem ITEM_WAILMER_PAIL
# 76 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
# 77 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"
	msgbox Route104_PrettyPetalFlowerShop_Text_WailmerPailExplanation, MSGBOX_DEFAULT
# 78 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"
	setflag FLAG_RECEIVED_WAILMER_PAIL
# 79 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"
	release
# 80 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"
	end
# 81 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"

# 82 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"
Route104_PrettyPetalFlowerShop_EventScript_RandomBerryGirl::
# 83 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"
	lock
# 84 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"
	faceplayer
# 85 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"
	dotimebasedevents
# 86 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"
	goto_if_set FLAG_DAILY_FLOWER_SHOP_RECEIVED_BERRY, Route104_PrettyPetalFlowerShop_EventScript_AlreadyReceivedBerry
# 87 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"
	msgbox Route104_PrettyPetalFlowerShop_Text_ImGrowingFlowers, MSGBOX_DEFAULT
# 88 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"
	random 8
# 89 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"
	addvar VAR_RESULT, FIRST_BERRY_INDEX
# 90 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"
	giveitem VAR_RESULT
# 91 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"
	goto_if_eq VAR_RESULT, 0, Common_EventScript_ShowBagIsFull
# 92 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"
	setflag FLAG_DAILY_FLOWER_SHOP_RECEIVED_BERRY
# 93 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"
	msgbox Route104_PrettyPetalFlowerShop_Text_MachineMixesBerries, MSGBOX_DEFAULT
# 94 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"
	release
# 95 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"
	end
# 96 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"

# 97 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"
Route104_PrettyPetalFlowerShop_EventScript_AlreadyReceivedBerry::
# 98 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"
	msgbox Route104_PrettyPetalFlowerShop_Text_MachineMixesBerries, MSGBOX_DEFAULT
# 99 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"
	release
# 100 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"
	end
