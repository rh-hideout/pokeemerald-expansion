Route104_PrettyPetalFlowerShop_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route104_PrettyPetalFlowerShop_OnTransition
	.byte 0

Route104_PrettyPetalFlowerShop_OnTransition:
	setflag FLAG_LANDMARK_FLOWER_SHOP
	goto_if_unset FLAG_MET_PRETTY_PETAL_SHOP_OWNER, Route104_PrettyPetalFlowerShop_EventScript_MoveShopOwner
	goto_if_unset FLAG_BADGE03_GET, Route104_PrettyPetalFlowerShop_EventScript_MoveShopOwner
	setflag FLAG_TEMP_1
	end

Route104_PrettyPetalFlowerShop_EventScript_MoveShopOwner::
	setobjectxyperm LOCALID_FLOWER_SHOP_OWNER, 4, 6
	end

Route104_PrettyPetalFlowerShop_EventScript_ShopOwner::
	lock
	faceplayer
	goto_if_set FLAG_TEMP_1, Route104_PrettyPetalFlowerShop_EventScript_SellDecorations
	msgbox Route104_PrettyPetalFlowerShop_Text_ThisIsPrettyPetalFlowerShop, MSGBOX_DEFAULT
	goto_if_set FLAG_MET_PRETTY_PETAL_SHOP_OWNER, Route104_PrettyPetalFlowerShop_EventScript_AlreadyMet
	setflag FLAG_MET_PRETTY_PETAL_SHOP_OWNER
	msgbox Route104_PrettyPetalFlowerShop_Text_IntroLearnAboutBerries, MSGBOX_YESNO
	call_if_eq VAR_RESULT, YES, Route104_PrettyPetalFlowerShop_EventScript_ExplainBerries
	call_if_eq VAR_RESULT, NO, Route104_PrettyPetalFlowerShop_EventScript_DontExplainBerries
	release
	end

Route104_PrettyPetalFlowerShop_EventScript_AlreadyMet::
	msgbox Route104_PrettyPetalFlowerShop_Text_LearnAboutBerries, MSGBOX_YESNO
	call_if_eq VAR_RESULT, YES, Route104_PrettyPetalFlowerShop_EventScript_ExplainBerries
	call_if_eq VAR_RESULT, NO, Route104_PrettyPetalFlowerShop_EventScript_DontExplainBerries
	release
	end

Route104_PrettyPetalFlowerShop_EventScript_ExplainBerries::
	msgbox Route104_PrettyPetalFlowerShop_Text_BerriesExplanation, MSGBOX_DEFAULT
	return

Route104_PrettyPetalFlowerShop_EventScript_DontExplainBerries::
	msgbox Route104_PrettyPetalFlowerShop_Text_FlowersBringHappiness, MSGBOX_DEFAULT
	return

Route104_PrettyPetalFlowerShop_EventScript_SellDecorations::
	message gText_PlayerWhatCanIDoForYou
	waitmessage
	pokemartdecoration2 Route104_PrettyPetalFlowerShop_Pokemart_Plants
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
Route104_PrettyPetalFlowerShop_Pokemart_Plants:
	.2byte DECOR_RED_PLANT
	.2byte DECOR_TROPICAL_PLANT
	.2byte DECOR_PRETTY_FLOWERS
	.2byte DECOR_COLORFUL_PLANT
	.2byte DECOR_BIG_PLANT
	.2byte DECOR_GORGEOUS_PLANT
	pokemartlistend

Route104_PrettyPetalFlowerShop_EventScript_WailmerPailGirl::
	lock
	faceplayer
	goto_if_unset FLAG_RECEIVED_WAILMER_PAIL, Route104_PrettyPetalFlowerShop_EventScript_GiveWailmerPail
	msgbox Route104_PrettyPetalFlowerShop_Text_WailmerPailExplanation, MSGBOX_DEFAULT
	release
	end

Route104_PrettyPetalFlowerShop_EventScript_GiveWailmerPail::
	msgbox Route104_PrettyPetalFlowerShop_Text_YouCanHaveThis, MSGBOX_DEFAULT
	giveitem ITEM_WAILMER_PAIL
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	msgbox Route104_PrettyPetalFlowerShop_Text_WailmerPailExplanation, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_WAILMER_PAIL
	release
	end

Route104_PrettyPetalFlowerShop_EventScript_RandomBerryGirl::
	lock
	faceplayer
	dotimebasedevents
	goto_if_set FLAG_DAILY_FLOWER_SHOP_RECEIVED_BERRY, Route104_PrettyPetalFlowerShop_EventScript_AlreadyReceivedBerry
	msgbox Route104_PrettyPetalFlowerShop_Text_ImGrowingFlowers, MSGBOX_DEFAULT
	giverandomberry BERRY_ID_CHERI, BERRY_ID_PERSIM
	goto_if_eq VAR_RESULT, 0, Common_EventScript_ShowBagIsFull
	setflag FLAG_DAILY_FLOWER_SHOP_RECEIVED_BERRY
	msgbox Route104_PrettyPetalFlowerShop_Text_MachineMixesBerries, MSGBOX_DEFAULT
	release
	end

Route104_PrettyPetalFlowerShop_EventScript_AlreadyReceivedBerry::
	msgbox Route104_PrettyPetalFlowerShop_Text_MachineMixesBerries, MSGBOX_DEFAULT
	release
	end

Route104_PrettyPetalFlowerShop_EventScript_Xie::
	lock
	faceplayer
	setvar VAR_0x8004, LOCALID_XIE
	goto Route104_PrettyPetalFlowerShop_EventScript_TwinEncounter
	end


Route104_PrettyPetalFlowerShop_EventScript_Sol::
	lock
	faceplayer
	setvar VAR_0x8004, LOCALID_SOL
	goto Route104_PrettyPetalFlowerShop_EventScript_TwinEncounter
	end


Route104_PrettyPetalFlowerShop_EventScript_TwinEncounter::
	goto_if_set FLAG_MET_TWIN_FLOWER_SHOP, Route104_PrettyPetalFlowerShop_EventScript_TwinAlreadyMet

	msgbox Route104_PrettyPetalFlowerShop_Text_TwinQuestion, MSGBOX_DEFAULT

	multichoice 0, 0, MULTICHOICE_TWIN_FIRST_ENCOUNTER, FALSE

	switch VAR_RESULT
	case 0, Route104_PrettyPetalFlowerShop_EventScript_TwinChoiceKnowYou
	case 1, Route104_PrettyPetalFlowerShop_EventScript_TwinChoiceHelpYou
	case 2, Route104_PrettyPetalFlowerShop_EventScript_TwinChoiceQuestionMarks

	goto Route104_PrettyPetalFlowerShop_EventScript_TwinChoiceQuestionMarks
	end

Route104_PrettyPetalFlowerShop_EventScript_TwinChoiceKnowYou::
	addvar VAR_CURIOSITY, 1
	msgbox Route104_PrettyPetalFlowerShop_Text_TwinResponseKnowYou, MSGBOX_DEFAULT
	goto Route104_PrettyPetalFlowerShop_EventScript_TwinLeave
	end


Route104_PrettyPetalFlowerShop_EventScript_TwinChoiceHelpYou::
	addvar VAR_COMPASSION, 1
	msgbox Route104_PrettyPetalFlowerShop_Text_TwinResponseHelpYou, MSGBOX_DEFAULT
	goto Route104_PrettyPetalFlowerShop_EventScript_TwinLeave
	end


Route104_PrettyPetalFlowerShop_EventScript_TwinChoiceQuestionMarks::
	addvar VAR_PERSPECTIVE, 1
	msgbox Route104_PrettyPetalFlowerShop_Text_TwinResponseQuestionMarks, MSGBOX_DEFAULT
	goto Route104_PrettyPetalFlowerShop_EventScript_TwinLeave
	end

Route104_PrettyPetalFlowerShop_EventScript_TwinLeave::
	setflag FLAG_MET_TWIN_FLOWER_SHOP
	closemessage

	applymovement VAR_0x8004, Route104_PrettyPetalFlowerShop_Movement_TwinLeave
	waitmovement 0
	removeobject VAR_0x8004

	msgbox Route104_PrettyPetalFlowerShop_Text_PlayerHairThought, MSGBOX_DEFAULT

	release
	end


Route104_PrettyPetalFlowerShop_EventScript_TwinAlreadyMet::
	removeobject VAR_0x8004
	release
	end

Route104_PrettyPetalFlowerShop_Text_TwinQuestion:
	.string "...?$"


Route104_PrettyPetalFlowerShop_Text_TwinResponseKnowYou:
	.string "...I was about to ask you\n"
	.string "the same thing.$"


Route104_PrettyPetalFlowerShop_Text_TwinResponseHelpYou:
	.string "No...\n"
	.string "I don't think so, anyway.$"


Route104_PrettyPetalFlowerShop_Text_TwinResponseQuestionMarks:
	.string "...\p"
	.string "Yeah.\n"
	.string "That's about where I'm at too.$"


Route104_PrettyPetalFlowerShop_Text_PlayerHairThought:
	.string "...\p"
	.string "I kinda like their hair?\p"
	.string "Weird.\n"
	.string "Okay..?$"

Route104_PrettyPetalFlowerShop_Movement_TwinLeave:
	walk_right
	walk_down
	walk_down
	walk_down
	step_end