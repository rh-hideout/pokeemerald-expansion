.set LOCALID_GOLDENROD_UNDERGROUND_KIMONO, 12

GoldenrodCity_UndergroundTunnel_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, GoldenrodCity_UndergroundTunnel_OnLoad
	.byte 0

GoldenrodCity_UndergroundTunnel_OnLoad::
	goto GoldenrodCity_UndergroundTunnel_MapScript_TryOpenDoor
	end
	
GoldenrodCity_UndergroundTunnel_EventScript_KimonoTriggerBot::
	lock
	playbgm MUS_HG_KIMONO_GIRL, TRUE
	applymovement LOCALID_GOLDENROD_UNDERGROUND_KIMONO, GoldenrodCity_UndergroundTunnel_Movement_Kimono_WalkToPlayerBot
	waitmovement 0
	msgbox GoldenrodCity_UndergroundTunnel_Text_Kimono1, MSGBOX_DEFAULT
	closemessage
	playse SE_PIN
	applymovement LOCALID_GOLDENROD_UNDERGROUND_KIMONO, Common_Movement_ExclamationMark
	delay 60
	msgbox GoldenrodCity_UndergroundTunnel_Text_Kimono2, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_GOLDENROD_UNDERGROUND_KIMONO, Common_Movement_WalkUp1
	waitmovement 0
	applymovement LOCALID_GOLDENROD_UNDERGROUND_KIMONO, GoldenrodCity_UndergroundTunnel_Movement_Kimono_Leave1
	waitmovement 0
	playse SE_M_PETAL_DANCE
	applymovement LOCALID_GOLDENROD_UNDERGROUND_KIMONO, GoldenrodCity_UndergroundTunnel_Movement_Kimono_Spin
	waitmovement 0
	applymovement LOCALID_GOLDENROD_UNDERGROUND_KIMONO, GoldenrodCity_UndergroundTunnel_Movement_Kimono_Leave2
	waitmovement 0
	setflag FLAG_HIDE_GOLDENROD_UNDERGROUND_KIMONO
	removeobject LOCALID_GOLDENROD_UNDERGROUND_KIMONO
	fadedefaultbgm
	setvar VAR_GOLDENROD_CITY_STATE, 8
	releaseall
	end

GoldenrodCity_UndergroundTunnel_EventScript_KimonoTriggerTop::
	lock
	playbgm MUS_HG_KIMONO_GIRL, TRUE
	applymovement LOCALID_GOLDENROD_UNDERGROUND_KIMONO, GoldenrodCity_UndergroundTunnel_Movement_Kimono_WalkToPlayerTop
	waitmovement 0
	msgbox GoldenrodCity_UndergroundTunnel_Text_Kimono1, MSGBOX_DEFAULT
	closemessage
	playse SE_PIN
	applymovement LOCALID_GOLDENROD_UNDERGROUND_KIMONO, Common_Movement_ExclamationMark
	delay 60
	msgbox GoldenrodCity_UndergroundTunnel_Text_Kimono2, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_GOLDENROD_UNDERGROUND_KIMONO, Common_Movement_WalkDown1
	waitmovement 0
	applymovement LOCALID_GOLDENROD_UNDERGROUND_KIMONO, GoldenrodCity_UndergroundTunnel_Movement_Kimono_Leave1
	waitmovement 0
	playse SE_M_PETAL_DANCE
	applymovement LOCALID_GOLDENROD_UNDERGROUND_KIMONO, GoldenrodCity_UndergroundTunnel_Movement_Kimono_Spin
	waitmovement 0
	applymovement LOCALID_GOLDENROD_UNDERGROUND_KIMONO, GoldenrodCity_UndergroundTunnel_Movement_Kimono_Leave2
	waitmovement 0
	setflag FLAG_HIDE_GOLDENROD_UNDERGROUND_KIMONO
	removeobject LOCALID_GOLDENROD_UNDERGROUND_KIMONO
	fadedefaultbgm
	setvar VAR_GOLDENROD_CITY_STATE, 8
	releaseall
	end


GoldenrodCity_UndergroundTunnel_Movement_Kimono_WalkToPlayerBot:
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

GoldenrodCity_UndergroundTunnel_Movement_Kimono_WalkToPlayerTop:
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

GoldenrodCity_UndergroundTunnel_Movement_Kimono_Leave1:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

GoldenrodCity_UndergroundTunnel_Movement_Kimono_Spin:
	face_down
	face_right
	face_up
	face_left
	face_down
	face_right
	face_up
	step_end

GoldenrodCity_UndergroundTunnel_Movement_Kimono_Leave2:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end


GoldenrodCity_UndergroundTunnel_Text_Kimono1:
	.string "Team Rocket members in black suits\n"
	.string "have been running around...\p"
	.string "I was wondering what was going on.\n"
	.string "So, you took on Team Rocket?\l"
	.string "You are impressive!\p"
	.string "You may be able to face the\n"
	.string "legendary POKé...$"

GoldenrodCity_UndergroundTunnel_Text_Kimono2:
	.string "Hahaha! Never mind.\n"
	.string "I must go now.$"

GoldenrodUnderground_EventScript_Eric::
	trainerbattle_single TRAINER_ERIC GoldenrodUnderground_Text_SupernerdEricSeen, GoldenrodUnderground_Text_SupernerdEricBeaten
	msgbox GoldenrodUnderground_Text_SupernerdEricAfterBattle, MSGBOX_AUTOCLOSE
	end

GoldenrodUnderground_EventScript_Teru::
	trainerbattle_single TRAINER_TERU GoldenrodUnderground_Text_SupernerdTeruSeen, GoldenrodUnderground_Text_SupernerdTeruBeaten
	msgbox GoldenrodUnderground_Text_SupernerdTeruAfterBattle, MSGBOX_AUTOCLOSE
	end

GoldenrodUnderground_EventScript_Issac::
	trainerbattle_single TRAINER_ISSAC GoldenrodUnderground_Text_PokemaniacIssacSeen, GoldenrodUnderground_Text_PokemaniacIssacBeaten
	msgbox GoldenrodUnderground_Text_PokemaniacIssacAfterBattle, MSGBOX_AUTOCLOSE
	end

GoldenrodUnderground_EventScript_Donald::
	trainerbattle_single TRAINER_DONALD GoldenrodUnderground_Text_PokemaniacDonaldSeen, GoldenrodUnderground_Text_PokemaniacDonaldBeaten
	msgbox GoldenrodUnderground_Text_PokemaniacDonaldAfterBattle, MSGBOX_AUTOCLOSE
	end

GoldenrodUnderground_EventScript_Brother_Haircut1::
	lock
	faceplayer
	goto_if_set FLAG_DAILY_HAIRCUT1_RECEIVED, GoldenrodUnderground_EventScript_Already_Got_Haircut1
	showmoneybox 0, 0
	msgbox GoldenrodUnderground_Text_OlderBrotherOffer, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, TRUE, GoldenrodUnderground_EventScript_Haircut1
	msgbox GoldenrodUnderground_Text_OlderBrotherThatsAShame, MSGBOX_DEFAULT
	hidemoneybox
	closemessage
	end

GoldenrodUnderground_EventScript_Haircut1::
	msgbox GoldenrodUnderground_Text_OlderBrotherAskWhich
	special ChoosePartyMon
	waitstate
	showmoneybox 0, 0
	lock
	faceplayer
	goto_if_ge VAR_0x8004, PARTY_SIZE, GoldenrodUnderground_EventScript_Declined_Haircut1
	specialvar VAR_RESULT, ScriptGetPartyMonSpecies
	goto_if_eq VAR_RESULT, SPECIES_EGG, GoldenrodUnderground_EventScript_Declined_Haircut1
	checkmoney 500, 0
	goto_if_eq VAR_RESULT, FALSE, GoldenrodUnderground_EventScript_NotEnough_Haircut1
	removemoney 500
	updatemoneybox 0
	playse SE_SHOP
	msgbox GoldenrodUnderground_Text_OlderBrotherWatchItBeautiful
	closemessage
	fadescreen FADE_TO_BLACK
	playfanfare MUS_HEAL
	waitfanfare
	special HaircutBrother1
	fadescreen FADE_FROM_BLACK
	special BufferMonNickname
	msgbox GoldenrodUnderground_Text_OlderBrotherAllDone
	hidemoneybox
	setflag FLAG_DAILY_HAIRCUT1_RECEIVED
	release
	end

GoldenrodUnderground_EventScript_Declined_Haircut1::
	msgbox GoldenrodUnderground_Text_OlderBrotherThatsAShame, MSGBOX_DEFAULT
	hidemoneybox
	closemessage
	release
	end

GoldenrodUnderground_EventScript_Already_Got_Haircut1::
	msgbox GoldenrodUnderground_Text_OlderBrotherOnePerDay, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodUnderground_EventScript_NotEnough_Haircut1::
	msgbox GoldenrodUnderground_Text_OlderBrotherNeedMoreMoney, MSGBOX_DEFAULT
	closemessage
	hidemoneybox
	release
	end


GoldenrodUnderground_EventScript_Brother_Haircut2::
	lock
	faceplayer
	goto_if_set FLAG_DAILY_HAIRCUT2_RECEIVED, GoldenrodUnderground_EventScript_Already_Got_Haircut2
	showmoneybox 0, 0
	msgbox GoldenrodUnderground_Text_YoungerBrotherOffer, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, TRUE, GoldenrodUnderground_EventScript_Haircut2
	msgbox GoldenrodUnderground_Text_YoungerBrotherDisappointed, MSGBOX_DEFAULT
	hidemoneybox
	closemessage
	end

GoldenrodUnderground_EventScript_Haircut2::
	msgbox GoldenrodUnderground_Text_YoungerBrotherAskWhich
	special ChoosePartyMon
	waitstate
	showmoneybox 0, 0
	lock
	faceplayer
	goto_if_ge VAR_0x8004, PARTY_SIZE, GoldenrodUnderground_EventScript_Declined_Haircut2
	specialvar VAR_RESULT, ScriptGetPartyMonSpecies
	goto_if_eq VAR_RESULT, SPECIES_EGG, GoldenrodUnderground_EventScript_Declined_Haircut2
	checkmoney 300, 0
	goto_if_eq VAR_RESULT, FALSE, GoldenrodUnderground_EventScript_NotEnough_Haircut2
	removemoney 300
	updatemoneybox 0
	playse SE_SHOP
	msgbox GoldenrodUnderground_Text_YoungerBrotherLookCool
	closemessage
	fadescreen FADE_TO_BLACK
	playfanfare MUS_HEAL
	waitfanfare
	special HaircutBrother1
	fadescreen FADE_FROM_BLACK
	special BufferMonNickname
	msgbox GoldenrodUnderground_Text_YoungerBrotherAllDone
	hidemoneybox
	setflag FLAG_DAILY_HAIRCUT2_RECEIVED
	release
	end

GoldenrodUnderground_EventScript_Declined_Haircut2::
	msgbox GoldenrodUnderground_Text_YoungerBrotherDisappointed, MSGBOX_DEFAULT
	hidemoneybox
	closemessage
	release
	end

GoldenrodUnderground_EventScript_Already_Got_Haircut2::
	msgbox GoldenrodUnderground_Text_YoungerBrotherOnePerDay, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodUnderground_EventScript_NotEnough_Haircut2::
	msgbox GoldenrodUnderground_Text_YoungerBrotherShortOnFunds, MSGBOX_DEFAULT
	closemessage
	hidemoneybox
	release
	end


GoldenrodCity_UndergroundTunnel_MapScript_TryOpenDoor::
	goto_if_set FLAG_UNLOCKED_GOLDENROD_UNDERGROUND_DOOR, GoldenrodCity_UndergroundTunnel_MapScript_OpenDoor
	end

GoldenrodCity_UndergroundTunnel_MapScript_OpenDoor::
	setmetatile 12, 10, 0x2DD, FALSE
	end

GoldenrodCity_UndergroundTunnel_EventScript_Door::
	lock
	goto_if_set FLAG_UNLOCKED_GOLDENROD_UNDERGROUND_DOOR, GoldenrodCity_UndergroundTunnel_EventScript_DoorAlreadyOpened
	checkitem ITEM_BASEMENT_KEY
	goto_if_eq VAR_RESULT, TRUE, GoldenrodCity_UndergroundTunnel_EventScript_OpenDoor
	msgbox GoldenrodUnderground_Text_DoorsLocked, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_UndergroundTunnel_EventScript_OpenDoor::
	msgbox GoldenrodUnderground_Text_KeyOpenedDoor, MSGBOX_DEFAULT
	closemessage
	setflag FLAG_UNLOCKED_GOLDENROD_UNDERGROUND_DOOR
	setmetatile 12, 10, 0x2DD, FALSE
	playse SE_BANG
	special DrawWholeMapView
	waitse
	release
	end

GoldenrodCity_UndergroundTunnel_EventScript_DoorAlreadyOpened::
	msgbox GoldenrodUnderground_Text_DoorIsOpen, MSGBOX_DEFAULT
	closemessage
	release
	end


GoldenrodCity_UndergroundTunnel_EventScript_Item_CoinCase::
	finditem ITEM_COIN_CASE
	end

GoldenrodCity_UndergroundTunnel_EventScript_Item_SuperPotion::
	finditem ITEM_SUPER_POTION
	end

GoldenrodCity_UndergroundTunnel_EventScript_Item_ParalyzeHeal::
	finditem ITEM_PARALYZE_HEAL
	end

GoldenrodCity_UndergroundTunnel_EventScript_Item_Antidote::
	finditem ITEM_ANTIDOTE
	end


GoldenrodUnderground_Text_YoungerBrotherOffer:
    .string "Welcome to the POKéMON SALON!\p"
    .string "I'm the younger and less expensive\n"
    .string "of the two HAIRCUT BROTHERS.\p"
    .string "I'll spiff up your POKéMON for just\n"
    .string "¥300.\p"
    .string "So? How about it?$"

GoldenrodUnderground_Text_YoungerBrotherAskWhich:
    .string "OK, which POKéMON should I do?$"

GoldenrodUnderground_Text_YoungerBrotherLookCool:
    .string "OK! I'll make it look cool!$"

GoldenrodUnderground_Text_YoungerBrotherAllDone:
    .string "There we go! All done!$"

GoldenrodUnderground_Text_YoungerBrotherDisappointed:
    .string "No? How disappointing!$"

GoldenrodUnderground_Text_YoungerBrotherShortOnFunds:
    .string "You're a little short on funds.$"

GoldenrodUnderground_Text_YoungerBrotherOnePerDay:
    .string "I can do only one haircut a day.\p"
    .string "Sorry, but I'm all done for today.$"



GoldenrodUnderground_Text_OlderBrotherOffer:
    .string "Welcome!\p"
    .string "I run the POKéMON SALON!\p"
    .string "I'm the older and better of the two\n"
    .string "HAIRCUT BROTHERS.\p"
    .string "I can make your POKéMON beautiful\n"
    .string "for just ¥500.\p"
    .string "Would you like me to do that?$"

GoldenrodUnderground_Text_OlderBrotherAskWhich:
    .string "Which POKéMON should I work on?$"

GoldenrodUnderground_Text_OlderBrotherWatchItBeautiful:
    .string "OK! Watch it become beautiful!$"

GoldenrodUnderground_Text_OlderBrotherAllDone:
    .string "There! All done!$"

GoldenrodUnderground_Text_OlderBrotherThatsAShame:
    .string "Is that right? That's a shame!$"

GoldenrodUnderground_Text_OlderBrotherNeedMoreMoney:
    .string "You'll need more money than that.$"

GoldenrodUnderground_Text_OlderBrotherOnePerDay:
    .string "I do only one haircut a day.\n"
    .string "I'm done for today.$"

GoldenrodUnderground_Text_SupernerdEricSeen:
    .string "I got booted out of the GAME CORNER.\p"
    .string "I was trying to cheat using my\n"
    .string "POKéMON…$"

GoldenrodUnderground_Text_SupernerdEricBeaten:
    .string "…Grumble…$"

GoldenrodUnderground_Text_SupernerdEricAfterBattle:
    .string "I guess I have to do things fair and\n"
    .string "square…$"

GoldenrodUnderground_Text_SupernerdTeruSeen:
    .string "Do you consider type alignments in\n"
    .string "battle?\p"
    .string "If you know your type advantages,\n"
    .string "you'll do better in battle.$"

GoldenrodUnderground_Text_SupernerdTeruBeaten:
    .string "Ow, ow, ow!$"

GoldenrodUnderground_Text_SupernerdTeruAfterBattle:
    .string "I know my POKéMON type alignments.\p"
    .string "But I only use one type of POKéMON.$"

GoldenrodUnderground_Text_PokemaniacIssacSeen:
    .string "My POKéMON just got a haircut!\p"
    .string "I'll show you how strong it is!$"

GoldenrodUnderground_Text_PokemaniacIssacBeaten:
    .string "Aiyeeee!$"

GoldenrodUnderground_Text_PokemaniacIssacAfterBattle:
    .string "Your POKéMON will like you more if\n"
    .string "you give them haircuts.$"

GoldenrodUnderground_Text_PokemaniacDonaldSeen:
    .string "I think you have some rare POKéMON\n"
    .string "with you.\p"
    .string "Let me see them!$"

GoldenrodUnderground_Text_PokemaniacDonaldBeaten:
    .string "Gaah! I lost! That makes me mad!$"

GoldenrodUnderground_Text_PokemaniacDonaldAfterBattle:
	.string "When I was walking near the BIKE\n"
	.string "SHOP last night, I felt like I was\l"
	.string "being watched from the rooftops...$"

GoldenrodUnderground_Text_PokemaniacDonaldAfterBattleOld:
    .string "Are you making a POKéDEX? Here's a\n"
    .string "hot tip.\p"
    .string "The HIKER on ROUTE 33, ANTHONY, is a\n"
    .string "good guy.\p"
    .string "He'll phone you if he sees any rare\n"
    .string "POKéMON.$"

GoldenrodUnderground_Text_DoorsLocked:
    .string "The door's locked…$"

GoldenrodUnderground_Text_DoorIsOpen:
    .string "The door is open.$"

GoldenrodUnderground_Text_KeyOpenedDoor:
    .string "The BASEMENT KEY opened the door.$"

GoldenrodUnderground_Text_NoEntry:
    .string "NO ENTRY BEYOND THIS POINT$"
