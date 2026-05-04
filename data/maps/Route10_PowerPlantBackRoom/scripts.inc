Route10_PowerPlantBackRoom_MapScripts::
	.byte 0


Route10_PowerPlantBackRoom_EventScript_Manager::
	lock
	faceplayer
	goto_if_eq VAR_KANTO_ROCKET_STORY_STATE, 0, Route10_PowerPlantBackRoom_EventScript_ManagerInitial
	goto_if_eq VAR_KANTO_ROCKET_STORY_STATE, 1, Route10_PowerPlantBackRoom_EventScript_ManagerDuringRocket
	goto_if_eq VAR_KANTO_ROCKET_STORY_STATE, 2, Route10_PowerPlantBackRoom_EventScript_ManagerDuringRocket
	goto_if_eq VAR_KANTO_ROCKET_STORY_STATE, 3, Route10_PowerPlantBackRoom_EventScript_ManagerDuringRocket
	goto_if_eq VAR_KANTO_ROCKET_STORY_STATE, 4, Route10_PowerPlantBackRoom_EventScript_ManagerDuringRocket
	goto_if_eq VAR_KANTO_ROCKET_STORY_STATE, 5, Route10_PowerPlantBackRoom_EventScript_ManagerDuringRocket
	goto_if_eq VAR_KANTO_ROCKET_STORY_STATE, 6, Route10_PowerPlantBackRoom_EventScript_ManagerCheckPart
	goto_if_ge VAR_KANTO_ROCKET_STORY_STATE, 7, Route10_PowerPlantBackRoom_EventScript_ManagerDone
	msgbox Route10_PowerPlantBackRoom_Text_ManagerMyBelovedGenerator, MSGBOX_DEFAULT
	closemessage
	release
	end

Route10_PowerPlantBackRoom_EventScript_ManagerInitial::
	msgbox Route10_PowerPlantBackRoom_Text_ManagerWhoWouldRuinMyGenerator, MSGBOX_DEFAULT
	closemessage
	setvar VAR_KANTO_ROCKET_STORY_STATE, 1
	release
	end

Route10_PowerPlantBackRoom_EventScript_ManagerDuringRocket::
	msgbox Route10_PowerPlantBackRoom_Text_ManagerIWontForgiveCulprit, MSGBOX_DEFAULT
	closemessage
	release
	end

Route10_PowerPlantBackRoom_EventScript_ManagerCheckPart::
	checkitem ITEM_MACHINE_PART
	goto_if_eq VAR_RESULT, FALSE, Route10_PowerPlantBackRoom_EventScript_ManagerDuringRocket
	removeitem ITEM_MACHINE_PART
	msgbox Route10_PowerPlantBackRoom_Text_ManagerThatsThePart, MSGBOX_DEFAULT
	msgbox Route10_PowerPlantBackRoom_Text_ManagerTakeThisTM, MSGBOX_DEFAULT
	giveitem ITEM_TM_THUNDER
	msgbox Route10_PowerPlantBackRoom_Text_ManagerTM07IsZapCannon, MSGBOX_DEFAULT
	closemessage
	setvar VAR_KANTO_ROCKET_STORY_STATE, 7
	clearflag FLAG_HIDE_ROUTE25_MISTY
	setvar VAR_CERULEAN_CITY_STATE, 2
	setflag FLAG_HIDE_POWER_PLANT_ENGINEER
	setflag FLAG_RETURNED_MACHINE_PART
	release
	end

Route10_PowerPlantBackRoom_EventScript_ManagerDone::
	msgbox Route10_PowerPlantBackRoom_Text_ManagerMyBelovedGenerator, MSGBOX_DEFAULT
	closemessage
	release
	end

Route10_PowerPlantBackRoom_EventScript_Engineer::
	msgbox Route10_PowerPlantBackRoom_Text_Engineer, MSGBOX_NPC
	end

Route10_PowerPlantBackRoom_Text_ManagerWhoWouldRuinMyGenerator:
	.string "MANAGER: I, I, I'm ready to blast\n"
	.string "someone!\p"
	.string "Who would dare ruin my\n"
	.string "generator?\p"
	.string "I spent so much time on it!\p"
	.string "If I catch him, he's going to\n"
	.string "get a taste of my ZAP CANNON!$"

Route10_PowerPlantBackRoom_Text_ManagerIWontForgiveCulprit:
	.string "MANAGER: I won't forgive him!\p"
	.string "The culprit can cry and\n"
	.string "apologize,\p"
	.string "but I'll still hammer him!\p"
	.string "Gahahahah!$"

Route10_PowerPlantBackRoom_Text_ManagerThatsThePart:
	.string "MANAGER: Ah! Yeah!\p"
	.string "That's the missing PART from my\n"
	.string "beloved generator! You found it?$"

Route10_PowerPlantBackRoom_Text_ManagerTakeThisTM:
	.string "Wahah! Thanks!\p"
	.string "Here! Take this TM as a reward!$"

Route10_PowerPlantBackRoom_Text_ManagerTM07IsZapCannon:
	.string "MANAGER: That TM is THUNDER.\p"
	.string "It's a powerful technique!\p"
	.string "It's not what anyone would\n"
	.string "consider accurate, but it packs a\l"
	.string "wallop!$"

Route10_PowerPlantBackRoom_Text_ManagerMyBelovedGenerator:
	.string "MANAGER: My beloved generator!\p"
	.string "Keep pumping the electricity out!$"

Route10_PowerPlantBackRoom_Text_Engineer:
	.string "This door is unsafe without power.$"

