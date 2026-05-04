.set LOCALID_MAHOGANY_MERCHANT, 3

Mahoganytown_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, Mahoganytown_OnLoad
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Mahoganytown_OnFrame
	.byte 0

Mahoganytown_OnLoad::
	call_if_ge VAR_MAHOGANY_TOWN_STATE, 13, MahoganyTown_EventScript_FixTree
	end

MahoganyTown_EventScript_FixTree::
	setmetatile 18, 8, 0x378, FALSE
	setmetatile 19, 8, 0x379, FALSE
	end

Mahoganytown_OnFrame::
	map_script_2 VAR_MAHOGANY_TOWN_STATE, 15, Mahoganytown_EventScript_RocketTrigger
	.2byte 0

Mahoganytown_EventScript_RocketTrigger::
	lock
	pokenavcall ElmPhoneRadioTowerRocketTakeoverText
	waitmessage
	setvar VAR_GOLDENROD_CITY_STATE, 6
	clearflag FLAG_HIDE_GOLDENROD_ROCKETS
	setflag FLAG_HIDE_GOLDENROD_ROCKET_SCOUT
	setflag FLAG_HIDE_GOLDENROD_NPCS
	clearflag FLAG_HIDE_ROCKET_GOLDENROD_RADIOTOWER_1
	setvar VAR_MAHOGANY_TOWN_STATE, 16
	delay 10
	release
	end

MahoganyTown_EventScript_TownTrigger::
	clearflag FLAG_HIDE_LAKE_OF_RAGE_GYARADOS
	clearflag FLAG_HIDE_MAHOGANY_TOWN_FATMAN
	clearflag FLAG_HIDE_MAHOGANY_ROCKETS
	clearflag FLAG_GOT_TM_FROM_MAHOGANY_COP
	clearflag FLAG_GOT_BLACK_BELT
	clearflag FLAG_ROCKETHIDEOUT_SWITCH
	clearflag FLAG_HIDE_ROCKETHIDEOUT2_LANCE_DRAGONITE
	clearflag FLAG_HIDE_ROCKETHIDEOUT2_GATE
	clearflag FLAG_HIDE_ROCKETHIDEOUT3_GATE
	clearflag FLAG_GOT_PASSWORD_FROM_ETO
	clearflag FLAG_GOT_PASSWORD_FROM_GRUNTF 
	clearflag FLAG_HIDE_ROCKETHIDEOUT3_MURKROW
	clearflag FLAG_HIDE_ROCKETHIDEOUT3_GIOVANNI
	clearflag FLAG_HIDE_ROCKETHIDEOUT_ELECTRODE1 
	clearflag FLAG_HIDE_ROCKETHIDEOUT_ELECTRODE2
	clearflag FLAG_HIDE_ROCKETHIDEOUT_ELECTRODE3 
	clearflag FLAG_GOT_HIDDEN_POWER
	clearflag FLAG_HIDE_ICE_PATH_KIMONO

	setflag FLAG_VISITED_MAHOGANY_TOWN
	setflag FLAG_HIDE_LAKE_OF_RAGE_LANCE
	setflag FLAG_HIDE_MAHOGANY_TOWN_SHOP_NPCS
	setflag FLAG_HIDE_MAHOGANY_COP
	setflag FLAG_HIDE_ROCKETHIDEOUT_ROCKETS
	setflag FLAG_HIDE_ROCKETHIDEOUT3_SILVER
	setflag FLAG_HIDE_ROCKETHIDEOUT3_PETREL
	setflag FLAG_HIDE_ROCKETHIDEOUT2_MURKROWSTAIRS
	setflag FLAG_HIDE_ROCKETHIDEOUT2_MURKROWGATE
	setflag FLAG_HIDE_ROCKETHIDEOUT3_MURKROWSTAIRS
	setflag FLAG_HIDE_ROCKETHIDEOUT2_ARIANA_AND_GRUNT

	setvar VAR_ROCKET_HIDEOUT_STATUE_1, 0
	setvar VAR_ROCKET_HIDEOUT_STATUE_2, 0
	setvar VAR_ROCKET_HIDEOUT_STATUE_3, 0
	setvar VAR_ROCKET_HIDEOUT_STATUE_4, 0
	setvar VAR_ROCKET_HIDEOUT_STATUE_5, 0
	setvar VAR_ROCKET_PASSWORD, 0
	setvar VAR_ELECTRODES_FAINTED, 0
	setvar VAR_LAKE_OF_RAGE_FISHERMAN, 0
	setvar VAR_ICE_PATH_STATE, 0
	setvar VAR_ROUTE27_BAOBA_CALL, 0

	setvar VAR_MAHOGANY_TOWN_STATE, 1

	@blackthorn flagheap
	setvar VAR_BLACKTHORN_CITY_STATE, 1
    setflag FLAG_HIDE_DRAGONS_DEN_CAVERN_SILVER
	setflag FLAG_HIDE_DRAGONS_DEN_CAVERN_CLAIR
	setflag FLAG_HIDE_DRAGONS_DEN_CAVERN_LANCE
	setflag FLAG_HIDE_DRAGONS_DEN_SHRINE_CLAIR
	clearflag FLAG_GOT_SPELL_TAG
	clearflag FLAG_GOT_DRATINI
	setvar VAR_BLACKTHORN_GYM_STATE, 0
	setvar VAR_DRAGONS_DEN_QUIZ, 0
	end

MahoganyTown_EventScript_MerchantTrigger::
	lock
	turnobject LOCALID_MAHOGANY_MERCHANT, DIR_SOUTH
	playse SE_PIN
	applymovement LOCALID_MAHOGANY_MERCHANT, Common_Movement_ExclamationMark
	delay 60
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	getplayerxy VAR_TEMP_0, VAR_TEMP_1
	call_if_eq VAR_TEMP_1, 14, MahoganyTown_EventScript_WalkUp2
	call_if_eq VAR_TEMP_1, 13, MahoganyTown_EventScript_WalkUp1
	showmoneybox 0, 0
	msgbox MahoganyTown_Text_RageCandyBarMerchantTryOne, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, MahoganyTown_EventScript_MerchantRefused
	checkmoney 300, 0
	goto_if_eq VAR_RESULT, FALSE, MahoganyTown_EventScript_MerchantBroke
	removemoney 300
	updatemoneybox 0
	playse SE_SHOP
	msgbox MahoganyTown_Text_RageCandyBarMerchantSavorIt, MSGBOX_DEFAULT
	giveitem ITEM_RAGE_CANDY_BAR
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_BagIsFull
	hidemoneybox
	closemessage
	getplayerxy VAR_TEMP_0, VAR_TEMP_1
	call_if_eq VAR_TEMP_0, 30, MahoganyTown_EventScript_PushPlayer
	release
	end

MahoganyTown_EventScript_WalkUp1::
	applymovement OBJ_EVENT_ID_PLAYER, MahoganyTown_Movement_PlayerMerchant1
	waitmovement 0
	return

MahoganyTown_EventScript_WalkUp2::
	applymovement OBJ_EVENT_ID_PLAYER, MahoganyTown_Movement_PlayerMerchant2
	waitmovement 0
	return

MahoganyTown_EventScript_Merchant::
	lock
	faceplayer
	goto_if_eq VAR_MAHOGANY_TOWN_STATE, 17, MahoganyTown_EventScript_MerchantAfter
	showmoneybox 0, 0
	msgbox MahoganyTown_Text_RageCandyBarMerchantTryOne, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, MahoganyTown_EventScript_MerchantRefused
	checkmoney 300, 0
	goto_if_eq VAR_RESULT, FALSE, MahoganyTown_EventScript_MerchantBroke
	removemoney 300
	updatemoneybox 0
	msgbox MahoganyTown_Text_RageCandyBarMerchantSavorIt, MSGBOX_DEFAULT
	giveitem ITEM_RAGE_CANDY_BAR
	hidemoneybox
	closemessage
	release
	end

MahoganyTown_EventScript_MerchantRefused::
	msgbox MahoganyTown_Text_RageCandyBarMerchantRefused, MSGBOX_DEFAULT
	closemessage
	hidemoneybox
	closemessage
	getplayerxy VAR_TEMP_0, VAR_TEMP_1
	call_if_eq VAR_TEMP_0, 30, MahoganyTown_EventScript_PushPlayer
	release
	end

MahoganyTown_EventScript_MerchantBroke::
	msgbox MahoganyTown_Text_RageCandyBarMerchantNotEnoughMoney, MSGBOX_DEFAULT
	closemessage
	hidemoneybox
	closemessage
	getplayerxy VAR_TEMP_0, VAR_TEMP_1
	call_if_eq VAR_TEMP_0, 30, MahoganyTown_EventScript_PushPlayer
	release
	end

MahoganyTown_EventScript_NotEnoughSpace:
	msgbox MahoganyTown_Text_RageCandyBarMerchantRefused, MSGBOX_DEFAULT
	closemessage
	hidemoneybox
	closemessage
	getplayerxy VAR_TEMP_0, VAR_TEMP_1
	call_if_eq VAR_TEMP_0, 30, MahoganyTown_EventScript_PushPlayer
	release
	return

MahoganyTown_EventScript_MerchantAfter::
	msgbox MahoganyTown_Text_RageCandyBarMerchantSoldOut, MSGBOX_DEFAULT
	closemessage
	release
	end

MahoganyTown_EventScript_PushPlayer::
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkLeft1
	waitmovement 0
	return

MahoganyTown_EventScript_Gramps::
	lock
	faceplayer
	goto_if_eq VAR_MAHOGANY_TOWN_STATE, 6, MahoganyTown_EventScript_GrampsAfter
	msgbox MahoganyTown_Text_Gramps, MSGBOX_DEFAULT
	closemessage
	release
	end

MahoganyTown_EventScript_GrampsAfter::
	msgbox MahoganyTown_Text_GrampsClearedRocketHideout, MSGBOX_DEFAULT
	closemessage
	release
	end

MahoganyTown_EventScript_Fisher::
	lock
	faceplayer
	msgbox MahoganyTown_Text_Fisher, MSGBOX_DEFAULT
	closemessage
	release
	end

MahoganyTown_EventScript_Lass::
	lock
	faceplayer
	msgbox MahoganyTown_Text_Lass, MSGBOX_DEFAULT
	closemessage
	release
	end

MahoganyTown_EventScript_Sign::
	lock
	msgbox MahoganyTown_Text_Sign, MSGBOX_SIGN
	closemessage
	release
	end

MahoganyTown_EventScript_CandybarSign::
	lock
	msgbox MahoganyTown_Text_RagecandybarSign, MSGBOX_SIGN
	closemessage
	release
	end

MahoganyTown_EventScript_GymSign::
	lock
	msgbox MahoganyTown_Text_GymSign, MSGBOX_SIGN
	closemessage
	release
	end

MahoganyTown_Movement_PlayerMerchant1:
	walk_up
	step_end

MahoganyTown_Movement_PlayerMerchant2:
	walk_up
	walk_up
	step_end

MahoganyTown_Text_RageCandyBarMerchantTryOne:
	.string "Hiya, kid!\p"
	.string "I see you're new in MAHOGANY TOWN.\p"
	.string "Since you're new, you should try a\n"
	.string "yummy RAGECANDYBAR!\p"
	.string "Right now, it can be yours for just\n"
	.string "¥300! Want one?$"

MahoganyTown_Text_RageCandyBarMerchantSavorIt:
    .string "Good! Savor it!$"

MahoganyTown_Text_RageCandyBarMerchantNotEnoughMoney:
    .string "You don't have enough money.$"

MahoganyTown_Text_RageCandyBarMerchantRefused:
    .string "Oh, fine then…$"

MahoganyTown_Text_RageCandyBarMerchantSoldOut:
    .string "RAGECANDYBAR's sold out.\p"
    .string "I'm packing up. Don't bother me,\n"
    .string "kiddo.$"

MahoganyTown_Text_Gramps:
    .string "Are you off to see the GYARADOS\n"
    .string "rampage at the LAKE?$"

MahoganyTown_Text_GrampsClearedRocketHideout:
    .string "MAGIKARP have returned to LAKE\n"
    .string "OF RAGE.\p"
    .string "That should be good news for the\n"
    .string "anglers there.$"

MahoganyTown_Text_Fisher:
    .string "Since you came this far, take the\n"
    .string "time to do some sightseeing.\p"
    .string "You should head north and check\n"
    .string "out LAKE OF RAGE right now.$"

MahoganyTown_Text_Lass:
    .string "Visit Grandma's shop. She sells\n"
    .string "stuff that nobody else has.$"

MahoganyTown_Text_Sign:
    .string "MAHOGANY TOWN\p"
    .string "Welcome to the Home of the Ninja$"

MahoganyTown_Text_RagecandybarSign:
    .string "While visiting MAHOGANY TOWN, try\n"
    .string "a RAGECANDYBAR!$"

MahoganyTown_Text_GymSign:
    .string "MAHOGANY TOWN POKéMON GYM\p"
    .string "LEADER: PRYCE\p"
    .string "The Teacher of Winter's Harshness$"

ElmPhoneRadioTowerRocketTakeoverText:
	.string "PROF.ELM: {PLAYER}, how are\n"
	.string "things going?\p"
	.string "I called because something weird\n"
	.string "is happening with the radio\l"
	.string "broadcasts.\p"
	.string "They were talking about TEAM\n"
	.string "ROCKET.\p"
	.string "{PLAYER}, do you know anything\n"
	.string "about it?\p"
	.string "Maybe TEAM ROCKET has returned.\n"
	.string "No, that just can't be true.\p"
	.string "Sorry to bug you.\n"
	.string "Take care!$"

