.set LOCALID_GOLDENROD_UNDERGROUND_SILVER, 7

GoldenrodCity_UndergroundSwitches_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, GoldenrodUnderground1_OnLoad
	.byte 0

GoldenrodUnderground1_OnLoad::
	call_if_set FLAG_COMPLETED_SWITCHES, GoldenrodUnderground1_ClearTheWay
	clearflag FLAG_GOLDENROD_SWITCH_1
	clearflag FLAG_GOLDENROD_SWITCH_2
	clearflag FLAG_GOLDENROD_SWITCH_3
	clearflag FLAG_GOLDENROD_SWITCH_ORDER
	end

GoldenrodUnderground1_ClearTheWay::
	call GoldenrodCity_UndergroundSwitches_EventScript_CreateWall1
	call GoldenrodCity_UndergroundSwitches_EventScript_RemoveWall2
	call GoldenrodCity_UndergroundSwitches_EventScript_RemoveWall3
	call GoldenrodCity_UndergroundSwitches_EventScript_CreateWall4
	call GoldenrodCity_UndergroundSwitches_EventScript_RemoveWall5
	call GoldenrodCity_UndergroundSwitches_EventScript_CreateWall6
	return


@ 3->2->1

@==============================================================================================================================================
GoldenrodCity_UndergroundSwitches_EventScript_Panel1::
	lock
	goto_if_unset FLAG_GOLDENROD_SWITCH_1, GoldenrodCity_UndergroundSwitches_EventScript_Panel1Activate @lock all
	clearflag FLAG_GOLDENROD_SWITCH_1
	playse SE_BANG
	msgbox GoldenrodUnderground_Text_Switch1Off, MSGBOX_DEFAULT
	closemessage
	call GoldenrodCity_UndergroundSwitches_EventScript_CreateWall1
	call GoldenrodCity_UndergroundSwitches_EventScript_CreateWall2
	call GoldenrodCity_UndergroundSwitches_EventScript_CreateWall3
	call GoldenrodCity_UndergroundSwitches_EventScript_CreateWall4
	call GoldenrodCity_UndergroundSwitches_EventScript_CreateWall5
	call GoldenrodCity_UndergroundSwitches_EventScript_CreateWall6
	special DrawWholeMapView
	waitse
	release
	end

GoldenrodCity_UndergroundSwitches_EventScript_Panel1Activate:: @unlock basic
	setflag FLAG_GOLDENROD_SWITCH_1
	goto_if_set FLAG_GOLDENROD_SWITCH_ORDER, GoldenrodCity_UndergroundSwitches_EventScript_Panel1ActivateCorrect
	clearflag FLAG_GOLDENROD_SWITCH_ORDER
	playse SE_BANG
	msgbox GoldenrodUnderground_Text_Switch1, MSGBOX_DEFAULT
	closemessage
	call GoldenrodCity_UndergroundSwitches_EventScript_RemoveWall1
	call GoldenrodCity_UndergroundSwitches_EventScript_RemoveWall2
	call GoldenrodCity_UndergroundSwitches_EventScript_RemoveWall3
	call GoldenrodCity_UndergroundSwitches_EventScript_CreateWall4	
	call GoldenrodCity_UndergroundSwitches_EventScript_CreateWall5
	call GoldenrodCity_UndergroundSwitches_EventScript_CreateWall6	
	special DrawWholeMapView
	waitse
	release
	end


GoldenrodCity_UndergroundSwitches_EventScript_Panel1ActivateCorrect:: @unlock the right path
	playse SE_CLICK
	setflag FLAG_COMPLETED_SWITCHES
	msgbox GoldenrodUnderground_Text_Switch1, MSGBOX_DEFAULT
	closemessage
	call GoldenrodCity_UndergroundSwitches_EventScript_CreateWall1
	call GoldenrodCity_UndergroundSwitches_EventScript_RemoveWall2
	call GoldenrodCity_UndergroundSwitches_EventScript_RemoveWall3
	call GoldenrodCity_UndergroundSwitches_EventScript_CreateWall4
	call GoldenrodCity_UndergroundSwitches_EventScript_RemoveWall5
	call GoldenrodCity_UndergroundSwitches_EventScript_CreateWall6
	special DrawWholeMapView
	waitse
	release
	end
@==============================================================================================================================================
GoldenrodCity_UndergroundSwitches_EventScript_Panel2:: @lock all
	lock
	goto_if_unset FLAG_GOLDENROD_SWITCH_2, GoldenrodCity_UndergroundSwitches_EventScript_Panel2Activate
	clearflag FLAG_GOLDENROD_SWITCH_2
	clearflag FLAG_GOLDENROD_SWITCH_ORDER
	playse SE_BANG
	msgbox GoldenrodUnderground_Text_Switch2Off, MSGBOX_DEFAULT
	closemessage
	call GoldenrodCity_UndergroundSwitches_EventScript_CreateWall1
	call GoldenrodCity_UndergroundSwitches_EventScript_CreateWall2
	call GoldenrodCity_UndergroundSwitches_EventScript_CreateWall3
	call GoldenrodCity_UndergroundSwitches_EventScript_CreateWall4
	call GoldenrodCity_UndergroundSwitches_EventScript_CreateWall5
	call GoldenrodCity_UndergroundSwitches_EventScript_CreateWall6
	special DrawWholeMapView
	waitse
	release
	end

GoldenrodCity_UndergroundSwitches_EventScript_Panel2Activate:: @unlock basic
	setflag FLAG_GOLDENROD_SWITCH_2
	goto_if_set FLAG_GOLDENROD_SWITCH_1, GoldenrodCity_UndergroundSwitches_EventScript_Panel2ActivateWrong
	goto_if_set FLAG_GOLDENROD_SWITCH_3, GoldenrodCity_UndergroundSwitches_EventScript_Panel2ActivateCorrect
	playse SE_BANG
	msgbox GoldenrodUnderground_Text_Switch2, MSGBOX_DEFAULT
	closemessage
	call GoldenrodCity_UndergroundSwitches_EventScript_RemoveWall1
	call GoldenrodCity_UndergroundSwitches_EventScript_RemoveWall2
	call GoldenrodCity_UndergroundSwitches_EventScript_RemoveWall3
	call GoldenrodCity_UndergroundSwitches_EventScript_CreateWall4	
	call GoldenrodCity_UndergroundSwitches_EventScript_CreateWall5
	call GoldenrodCity_UndergroundSwitches_EventScript_CreateWall6	
	special DrawWholeMapView
	waitse
	release
	end

GoldenrodCity_UndergroundSwitches_EventScript_Panel2ActivateWrong:: @unlock basic
	clearflag FLAG_GOLDENROD_SWITCH_ORDER
	playse SE_BANG
	msgbox GoldenrodUnderground_Text_Switch2, MSGBOX_DEFAULT
	closemessage
	call GoldenrodCity_UndergroundSwitches_EventScript_RemoveWall1
	call GoldenrodCity_UndergroundSwitches_EventScript_RemoveWall2
	call GoldenrodCity_UndergroundSwitches_EventScript_RemoveWall3
	call GoldenrodCity_UndergroundSwitches_EventScript_CreateWall4	
	call GoldenrodCity_UndergroundSwitches_EventScript_CreateWall5
	call GoldenrodCity_UndergroundSwitches_EventScript_CreateWall6	
	special DrawWholeMapView
	waitse
	release
	end


GoldenrodCity_UndergroundSwitches_EventScript_Panel2ActivateCorrect:: @unlock item2
	setflag FLAG_GOLDENROD_SWITCH_ORDER
	playse SE_CLICK
	msgbox GoldenrodUnderground_Text_Switch2, MSGBOX_DEFAULT
	closemessage
	call GoldenrodCity_UndergroundSwitches_EventScript_CreateWall1
	call GoldenrodCity_UndergroundSwitches_EventScript_RemoveWall2
	call GoldenrodCity_UndergroundSwitches_EventScript_RemoveWall3
	call GoldenrodCity_UndergroundSwitches_EventScript_CreateWall4	
	call GoldenrodCity_UndergroundSwitches_EventScript_CreateWall5
	call GoldenrodCity_UndergroundSwitches_EventScript_CreateWall6	
	special DrawWholeMapView
	waitse
	release
	end


@==============================================================================================================================================
GoldenrodCity_UndergroundSwitches_EventScript_Panel3:: @lock all
	lock
	goto_if_unset FLAG_GOLDENROD_SWITCH_3, GoldenrodCity_UndergroundSwitches_EventScript_Panel3Activate
	clearflag FLAG_GOLDENROD_SWITCH_3
	clearflag FLAG_GOLDENROD_SWITCH_ORDER
	playse SE_BANG
	msgbox GoldenrodUnderground_Text_Switch3Off, MSGBOX_DEFAULT
	closemessage
	call GoldenrodCity_UndergroundSwitches_EventScript_CreateWall1
	call GoldenrodCity_UndergroundSwitches_EventScript_CreateWall2
	call GoldenrodCity_UndergroundSwitches_EventScript_CreateWall3
	call GoldenrodCity_UndergroundSwitches_EventScript_CreateWall4
	call GoldenrodCity_UndergroundSwitches_EventScript_CreateWall5
	call GoldenrodCity_UndergroundSwitches_EventScript_CreateWall6
	special DrawWholeMapView
	waitse
	release
	end

GoldenrodCity_UndergroundSwitches_EventScript_Panel3Activate:: @unlock item 1
	setflag FLAG_GOLDENROD_SWITCH_3
	clearflag FLAG_GOLDENROD_SWITCH_ORDER
	playse SE_CLICK
	msgbox GoldenrodUnderground_Text_Switch3, MSGBOX_DEFAULT
	closemessage
	call GoldenrodCity_UndergroundSwitches_EventScript_RemoveWall1
	call GoldenrodCity_UndergroundSwitches_EventScript_RemoveWall4
	call GoldenrodCity_UndergroundSwitches_EventScript_CreateWall2
	call GoldenrodCity_UndergroundSwitches_EventScript_CreateWall3
	call GoldenrodCity_UndergroundSwitches_EventScript_CreateWall5
	call GoldenrodCity_UndergroundSwitches_EventScript_CreateWall6
	special DrawWholeMapView
	waitse
	release
	end

@==============================================================================================================================================

GoldenrodCity_UndergroundSwitches_EventScript_CreateWall1::
	setmetatile 5, 7, 0x399, FALSE
	setmetatile 6, 7, 0x39A, FALSE
	setmetatile 7, 7, 0x39B, FALSE

	setmetatile 5, 8, 0x3A1, FALSE
	setmetatile 6, 8, 0x3A2, FALSE
	setmetatile 7, 8, 0x3A3, FALSE
	return

GoldenrodCity_UndergroundSwitches_EventScript_CreateWall2::
	setmetatile 14, 7, 0x399, FALSE
	setmetatile 15, 7, 0x39A, FALSE
	setmetatile 16, 7, 0x39B, FALSE

	setmetatile 14, 8, 0x3A1, FALSE
	setmetatile 15, 8, 0x3A2, FALSE
	setmetatile 16, 8, 0x3A3, FALSE
	return

GoldenrodCity_UndergroundSwitches_EventScript_CreateWall3::
	setmetatile 23, 7, 0x399, FALSE
	setmetatile 24, 7, 0x39A, FALSE
	setmetatile 25, 7, 0x39B, FALSE

	setmetatile 23, 8, 0x3A1, FALSE
	setmetatile 24, 8, 0x3A2, FALSE
	setmetatile 25, 8, 0x3A3, FALSE
	return

GoldenrodCity_UndergroundSwitches_EventScript_CreateWall4::
	setmetatile 5, 11, 0x399, FALSE
	setmetatile 6, 11, 0x39A, FALSE
	setmetatile 7, 11, 0x39B, FALSE

	setmetatile 5, 12, 0x3A1, FALSE
	setmetatile 6, 12, 0x3A2, FALSE
	setmetatile 7, 12, 0x3A3, FALSE
	return

GoldenrodCity_UndergroundSwitches_EventScript_CreateWall5::
	setmetatile 14, 11, 0x399, FALSE
	setmetatile 15, 11, 0x39A, FALSE
	setmetatile 16, 11, 0x39B, FALSE

	setmetatile 14, 12, 0x3A1, FALSE
	setmetatile 15, 12, 0x3A2, FALSE
	setmetatile 16, 12, 0x3A3, FALSE
	return

GoldenrodCity_UndergroundSwitches_EventScript_CreateWall6::
	setmetatile 23, 11, 0x399, FALSE
	setmetatile 24, 11, 0x39A, FALSE
	setmetatile 25, 11, 0x39B, FALSE

	setmetatile 23, 12, 0x3A1, FALSE
	setmetatile 24, 12, 0x3A2, FALSE
	setmetatile 25, 12, 0x3A3, FALSE
	return
@======================================================================================================================

GoldenrodCity_UndergroundSwitches_EventScript_RemoveWall1::
	setmetatile 5, 7, 0x378, FALSE
	setmetatile 6, 7, 0x379, FALSE
	setmetatile 7, 7, 0x37A, FALSE
	
	setmetatile 5, 8, 0x380, FALSE
	setmetatile 6, 8, 0x381, FALSE
	setmetatile 7, 8, 0x382, FALSE
	return

GoldenrodCity_UndergroundSwitches_EventScript_RemoveWall2::
	setmetatile 14, 7, 0x378, FALSE
	setmetatile 15, 7, 0x379, FALSE
	setmetatile 16, 7, 0x37A, FALSE
	
	setmetatile 14, 8, 0x380, FALSE
	setmetatile 15, 8, 0x381, FALSE
	setmetatile 16, 8, 0x382, FALSE
	return

GoldenrodCity_UndergroundSwitches_EventScript_RemoveWall3::
	setmetatile 23, 7, 0x378, FALSE
	setmetatile 24, 7, 0x379, FALSE
	setmetatile 25, 7, 0x37A, FALSE
	
	setmetatile 23, 8, 0x380, FALSE
	setmetatile 24, 8, 0x381, FALSE
	setmetatile 25, 8, 0x382, FALSE
	return

GoldenrodCity_UndergroundSwitches_EventScript_RemoveWall4::
	setmetatile 5, 11, 0x378, FALSE
	setmetatile 6, 11, 0x379, FALSE
	setmetatile 7, 11, 0x37A, FALSE
	
	setmetatile 5, 12, 0x380, FALSE
	setmetatile 6, 12, 0x381, FALSE
	setmetatile 7, 12, 0x382, FALSE
	return

GoldenrodCity_UndergroundSwitches_EventScript_RemoveWall5::
	setmetatile 14, 11, 0x378, FALSE
	setmetatile 15, 11, 0x379, FALSE
	setmetatile 16, 11, 0x37A, FALSE
	
	setmetatile 14, 12, 0x380, FALSE
	setmetatile 15, 12, 0x381, FALSE
	setmetatile 16, 12, 0x382, FALSE
	return

GoldenrodCity_UndergroundSwitches_EventScript_RemoveWall6::
	setmetatile 23, 11, 0x378, FALSE
	setmetatile 24, 11, 0x379, FALSE
	setmetatile 25, 11, 0x37A, FALSE
	
	setmetatile 23, 12, 0x380, FALSE
	setmetatile 24, 12, 0x381, FALSE
	setmetatile 25, 12, 0x382, FALSE
	return

GoldenrodCity_UndergroundSwitches_EventScript_SilverTriggerTop::
	lock
	playse SE_EXIT
	waitse
	playse SE_PIN
	playbgm MUS_HG_ENCOUNTER_RIVAL, TRUE
	@clearflag FLAG_HIDE_GOLDENROD_UNDERGROUND_SILVER
	addobject LOCALID_GOLDENROD_UNDERGROUND_SILVER
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
	applymovement LOCALID_GOLDENROD_UNDERGROUND_SILVER, GoldenrodCity_UndergroundSwitches_Movement_SilverEnterTop
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkRight1
	waitmovement 0
	waitmovement 0
	msgbox GoldenrodUnderground_Text_SilverBefore, MSGBOX_DEFAULT
	closemessage
	call_if_eq VAR_STARTER_MON, 0, GoldenrodCity_UndergroundSwitches_EventScript_Cyndaquil
	call_if_eq VAR_STARTER_MON, 1, GoldenrodCity_UndergroundSwitches_EventScript_Totodile
	call_if_eq VAR_STARTER_MON, 2, GoldenrodCity_UndergroundSwitches_EventScript_Chikorita
	playbgm MUS_HG_RIVAL_EXIT, TRUE
	msgbox GoldenrodUnderground_Text_SilverAfter, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_GOLDENROD_UNDERGROUND_SILVER, GoldenrodCity_UndergroundSwitches_Movement_SilverLeaveTop
	waitmovement 0
	playse SE_EXIT
	setflag FLAG_HIDE_GOLDENROD_UNDERGROUND_SILVER
	removeobject LOCALID_GOLDENROD_UNDERGROUND_SILVER
	fadedefaultbgm
	setvar VAR_GOLDENROD_CITY_STATE, 9
	release
	end


GoldenrodCity_UndergroundSwitches_EventScript_SilverTriggerBot::
	lock
	playse SE_EXIT
	waitse
	playse SE_PIN
	playbgm MUS_HG_ENCOUNTER_RIVAL, TRUE
	clearflag FLAG_HIDE_GOLDENROD_UNDERGROUND_SILVER
	addobject LOCALID_GOLDENROD_UNDERGROUND_SILVER
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
	applymovement LOCALID_GOLDENROD_UNDERGROUND_SILVER, GoldenrodCity_UndergroundSwitches_Movement_SilverEnterBot
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkRight1
	waitmovement 0
	waitmovement 0
	msgbox GoldenrodUnderground_Text_SilverBefore, MSGBOX_DEFAULT
	closemessage
	call_if_eq VAR_STARTER_MON, 0, GoldenrodCity_UndergroundSwitches_EventScript_Cyndaquil
	call_if_eq VAR_STARTER_MON, 1, GoldenrodCity_UndergroundSwitches_EventScript_Totodile
	call_if_eq VAR_STARTER_MON, 2, GoldenrodCity_UndergroundSwitches_EventScript_Chikorita
	playbgm MUS_HG_RIVAL_EXIT, TRUE
	msgbox GoldenrodUnderground_Text_SilverAfter, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_GOLDENROD_UNDERGROUND_SILVER, GoldenrodCity_UndergroundSwitches_Movement_SilverLeaveBot
	waitmovement 0
	playse SE_EXIT
	setflag FLAG_HIDE_GOLDENROD_UNDERGROUND_SILVER
	removeobject LOCALID_GOLDENROD_UNDERGROUND_SILVER
	fadedefaultbgm
	setvar VAR_GOLDENROD_CITY_STATE, 9
	release
	end

GoldenrodCity_UndergroundSwitches_EventScript_Cyndaquil::
	trainerbattle_no_intro TRAINER_RIVAL_CYNDAQUIL_4, GoldenrodUnderground_Text_SilverWin
	return

GoldenrodCity_UndergroundSwitches_EventScript_Totodile::
	trainerbattle_no_intro TRAINER_RIVAL_TOTODILE_4, GoldenrodUnderground_Text_SilverWin
	return

GoldenrodCity_UndergroundSwitches_EventScript_Chikorita::
	trainerbattle_no_intro TRAINER_RIVAL_CHIKORITA_4, GoldenrodUnderground_Text_SilverWin
	return



GoldenrodCity_UndergroundSwitches_Movement_SilverEnterTop:
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

GoldenrodCity_UndergroundSwitches_Movement_SilverLeaveTop:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_up
	walk_up
	walk_up
	face_right
	step_end


GoldenrodCity_UndergroundSwitches_Movement_SilverEnterBot:
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

GoldenrodCity_UndergroundSwitches_Movement_SilverLeaveBot:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_up
	walk_up
	walk_up
	walk_up
	face_right
	step_end	

GoldenrodCity_UndergroundSwitches_EventScript_Grunt10::
    trainerbattle_single TRAINER_GRUNT_10, GoldenrodUnderground_Text_GruntM11Seen, GoldenrodUnderground_Text_GruntM11Beaten
	msgbox GoldenrodUnderground_Text_GruntM11After, MSGBOX_AUTOCLOSE
	end

GoldenrodCity_UndergroundSwitches_EventScript_Grunt20::
    trainerbattle_single TRAINER_GRUNT_20, GoldenrodUnderground_Text_GruntM25Seen, GoldenrodUnderground_Text_GruntM25Beaten
	msgbox GoldenrodUnderground_Text_GruntM25After, MSGBOX_AUTOCLOSE
	end

GoldenrodCity_UndergroundSwitches_EventScript_Duncan::
    trainerbattle_single TRAINER_DUNCAN, GoldenrodUnderground_Text_BurglarDuncanSeen, GoldenrodUnderground_Text_BurglarDuncanBeaten
	msgbox GoldenrodUnderground_Text_BurglarDuncanAfter, MSGBOX_AUTOCLOSE
	end

GoldenrodCity_UndergroundSwitches_EventScript_Eddie::
    trainerbattle_single TRAINER_EDDIE, GoldenrodUnderground_Text_BurglarEddieSeen, GoldenrodUnderground_Text_BurglarEddieBeaten
	msgbox GoldenrodUnderground_Text_BurglarEddieAfter, MSGBOX_AUTOCLOSE
	end

GoldenrodCity_UndergroundSwitches_EventScript_Grunt11::
    trainerbattle_single TRAINER_GRUNT_11, GoldenrodUnderground_Text_GruntM13Seen, GoldenrodUnderground_Text_GruntM13Beaten
	msgbox GoldenrodUnderground_Text_GruntM13After, MSGBOX_AUTOCLOSE
	end

GoldenrodCity_UndergroundSwitches_EventScript_Grunt27::
    trainerbattle_single TRAINER_GRUNT_27, GoldenrodUnderground_Text_GruntF3Seen, GoldenrodUnderground_Text_GruntF3Beaten
	msgbox GoldenrodUnderground_Text_GruntF3After, MSGBOX_AUTOCLOSE
	end

GoldenrodCity_UndergroundSwitches_EventScript_Item_Revive::
	finditem ITEM_MAX_REVIVE
	end

GoldenrodCity_UndergroundSwitches_EventScript_Item_MaxPotion::
	finditem ITEM_MAX_POTION
	end

GoldenrodCity_UndergroundSwitches_EventScript_Item_SmokeBall::
	finditem ITEM_SMOKE_BALL
	end

GoldenrodUnderground_Text_SilverBefore:
    .string "Hold it!\p"
    .string "I saw you, so I tailed you.\p"
    .string "I don't need you underfoot while I\n"
    .string "take care of TEAM ROCKET.\p"
    .string "…Wait a second. You beat me before,\n"
    .string "didn't you?\p"
    .string "That was just a fluke.\p"
    .string "I've been training my team and now\n"
    .string "I will repay my debts!$"

GoldenrodUnderground_Text_SilverWin:
    .string "…Why… Why do I lose?\p"
    .string "I've assembled the toughest POKéMON.\p"
    .string "I didn't ease up on the gas.\p"
    .string "So why do I lose?$"

GoldenrodUnderground_Text_SilverAfter:
    .string "…I don't understand…\p"
    .string "Is what that LANCE guy said true?\p"
    .string "That I don't treat POKéMON properly?\p"
    .string "Love…\p"
    .string "Trust…\p"
    .string "Are they really what I lack?\p"
    .string "Are they keeping me from winning?\p"
    .string "I… I just don't understand.\p"
    .string "But it's not going to end here.\p"
    .string "Not now. Not because of this.\p"
    .string "I won't give up my dream of becoming\n"
    .string "the world's best POKéMON trainer!$"

GoldenrodUnderground_Text_SilverLoss:
    .string "Humph. This is my real power, wimp.\p"
    .string "I'll make TEAM ROCKET history.\p"
    .string "And I'm going to grind that LANCE\n"
    .string "under my heels.$"

GoldenrodUnderground_Text_GruntM11Seen:
    .string "Open one shutter, another closes.\p"
    .string "Bet you can't get where you want!$"

GoldenrodUnderground_Text_GruntM11Beaten:
    .string "Drat! I was sunk by indecision!$"

GoldenrodUnderground_Text_GruntM11After:
    .string "I'm confused too… The switch on the\n"
    .string "end is the one to press first, but…$"

GoldenrodUnderground_Text_GruntM25Seen:
    .string "Kwahaha!\p"
    .string "Confounded by the shutters, are we?\p"
    .string "I'll let you in on a secret if you\n"
    .string "can beat me!$"

GoldenrodUnderground_Text_GruntM25Beaten:
    .string "Uwww… I blew it.$"

GoldenrodUnderground_Text_GruntM25After:
    .string "All right. A hint!\p"
    .string "Change the order of switching.\p"
    .string "That'll change the ways the shutters\n"
    .string "open and close.$"

GoldenrodUnderground_Text_BurglarDuncanSeen:
    .string "Fork over your goodies!$"

GoldenrodUnderground_Text_BurglarDuncanBeaten:
    .string "Mercy!$"

GoldenrodUnderground_Text_BurglarDuncanAfter:
    .string "Steal and sell! That's basic in\n"
    .string "crime, kid!$"

GoldenrodUnderground_Text_BurglarEddieSeen:
    .string "They ditched this project before they\n"
    .string "finished.\p"
    .string "I'm searching for leftover loot.$"

GoldenrodUnderground_Text_BurglarEddieBeaten:
    .string "Over the top!$"

GoldenrodUnderground_Text_BurglarEddieAfter:
    .string "UNDERGROUND WAREHOUSE?\p"
    .string "What do you want to go there for?\p"
    .string "There's nothing down there.$"

GoldenrodUnderground_Text_GruntM13Seen:
    .string "I don't care if you're lost.\p"
    .string "You show up here, you're nothing but\n"
    .string "a victim!$"

GoldenrodUnderground_Text_GruntM13Beaten:
    .string "Urk! Yeah, think you're cool, huh?$"

GoldenrodUnderground_Text_GruntM13After:
    .string "You must have ice in your veins to\n"
    .string "dis TEAM ROCKET.$"

GoldenrodUnderground_Text_GruntF3Seen:
    .string "Are you lost? No, you can't be.\p"
    .string "You don't have that scared look.\p"
    .string "I'll give you something to be\n"
    .string "scared about!$"

GoldenrodUnderground_Text_GruntF3Beaten:
    .string "How could you?$"

GoldenrodUnderground_Text_GruntF3After:
    .string "Go wherever you'd like! Get lost!\n"
    .string "See if I care!$"

GoldenrodUnderground_Text_Switch1:
    .string "SWITCH 1 activated.$"

GoldenrodUnderground_Text_Switch2:
    .string "SWITCH 2 activated.$"

GoldenrodUnderground_Text_Switch3:
    .string "SWITCH 3 activated.$"

GoldenrodUnderground_Text_Switch1Off:
    .string "SWITCH 1 deactivated.$"

GoldenrodUnderground_Text_Switch2Off:
    .string "SWITCH 2 deactivated.$"

GoldenrodUnderground_Text_Switch3Off:
    .string "SWITCH 3 deactivated.$"
