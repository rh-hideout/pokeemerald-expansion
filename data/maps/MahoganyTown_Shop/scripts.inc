.set LOCALID_MAHOGANYSHOP_LANCE, 3
.set LOCALID_MAHOGANYSHOP_DRAGONITE,4
.set LOCALID_MAHOGANYSHOP_ROCKET, 2

MahoganyTown_Shop_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, MahoganyTown_Shop_OnLoad
	map_script MAP_SCRIPT_ON_FRAME_TABLE, MahoganyTown_Shop_OnFrame
	.byte 0

MahoganyTown_Shop_OnLoad:
	goto_if_ge VAR_MAHOGANY_TOWN_STATE, 5, MahoganyTown_Shop_SetStairs
	end

MahoganyTown_Shop_SetStairs::
	setmetatile 8, 4, 0x28D, FALSE
	end

MahoganyTown_Shop_OnFrame::
	map_script_2 VAR_MAHOGANY_TOWN_STATE, 4, MahoganyTown_Shop_EventScript_Raid
	.2byte 0

MahoganyTown_Shop_EventScript_Raid::
	playbgm MUS_HG_TEAM_ROCKET_HQ, TRUE
	lock
	playse SE_PIN
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
	delay 60
	msgbox MahoganyMart1F_Text_Lance_HyperBeam, MSGBOX_DEFAULT
	closemessage
	playse SE_M_HYPER_BEAM
	applymovement LOCALID_MAHOGANYSHOP_DRAGONITE, MahoganyTown_Shop_Movement_Dragonite1
	delay 10
	applymovement LOCALID_MAHOGANYSHOP_ROCKET, MahoganyTown_Shop_Movement_Rocket1
	waitmovement LOCALID_MAHOGANYSHOP_ROCKET
	waitse
	setvar VAR_0x8004, 1  @ vertical pan
	setvar VAR_0x8005, 1  @ horizontal pan
	setvar VAR_0x8006, 5  @ num shakes
	setvar VAR_0x8007, 6  @ shake delay
	special ShakeCamera
	waitmovement LOCALID_MAHOGANYSHOP_DRAGONITE
	waitse
	delay 10
	turnobject LOCALID_MAHOGANYSHOP_LANCE, DIR_SOUTH
	delay 50
	applymovement LOCALID_MAHOGANYSHOP_LANCE, MahoganyTown_Shop_Movement_LanceGreetPlayer
	waitmovement 0
	msgbox MahoganyMart1F_Text_Lance_Radio, MSGBOX_DEFAULT
	closemessage
	playse SE_PIN
	applymovement LOCALID_MAHOGANYSHOP_DRAGONITE, Common_Movement_QuestionMark
	delay 10
	applymovement LOCALID_MAHOGANYSHOP_DRAGONITE, MahoganyTown_Shop_Movement_DragoniteGotoBox
	waitmovement 0
	playmoncry SPECIES_DRAGONITE, CRY_MODE_NORMAL
	waitmovement 0
	applymovement LOCALID_MAHOGANYSHOP_LANCE, MahoganyTown_Shop_Movement_LanceGotoBox
	applymovement OBJ_EVENT_ID_PLAYER, MahoganyTown_Shop_Movement_PlayerGotoBox
	waitmovement LOCALID_MAHOGANYSHOP_LANCE
	waitmovement OBJ_EVENT_ID_PLAYER

	playse SE_M_HYPER_BEAM
	applymovement LOCALID_MAHOGANYSHOP_DRAGONITE, MahoganyTown_Shop_Movement_Dragonite2
	delay 20
	waitse
	setvar VAR_0x8004, 1  @ vertical pan
	setvar VAR_0x8005, 1  @ horizontal pan
	setvar VAR_0x8006, 5  @ num shakes
	setvar VAR_0x8007, 6  @ shake delay
	special ShakeCamera

	waitmovement 0
	
	setmetatile 8, 4, 0x28D, FALSE
	special DrawWholeMapView
	delay 40
	msgbox MahoganyMart1F_Text_Lance_Stairs, MSGBOX_DEFAULT
	turnobject LOCALID_MAHOGANYSHOP_DRAGONITE, DIR_WEST
	playmoncry SPECIES_DRAGONITE, CRY_MODE_NORMAL
	waitmoncry
	turnobject LOCALID_MAHOGANYSHOP_DRAGONITE, DIR_EAST

	turnobject LOCALID_MAHOGANYSHOP_LANCE, DIR_SOUTH
	msgbox MahoganyMart1F_Text_Lance_SplitUp, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_MAHOGANYSHOP_DRAGONITE, Common_Movement_WalkRight1
	waitmovement 0
	removeobject LOCALID_MAHOGANYSHOP_DRAGONITE
	playse SE_EXIT
	applymovement LOCALID_MAHOGANYSHOP_LANCE, Common_Movement_WalkRight1
	waitmovement 0
	applymovement LOCALID_MAHOGANYSHOP_LANCE, Common_Movement_WalkRight1
	waitmovement 0
	removeobject LOCALID_MAHOGANYSHOP_LANCE
	playse SE_EXIT
	delay 50

	playse SE_PIN
	applymovement LOCALID_MAHOGANYSHOP_ROCKET Common_Movement_ExclamationMark
	delay 20
	applymovement LOCALID_MAHOGANYSHOP_ROCKET MahoganyTown_Shop_Movement_RocketLeave
	waitmovement 0
	removeobject LOCALID_MAHOGANYSHOP_ROCKET
	playse SE_EXIT
	setflag FLAG_HIDE_MAHOGANY_TOWN_SHOP_NPCS


	setvar VAR_MAHOGANY_TOWN_STATE, 5
	release
	end

MahoganyTown_Shop_Movement_RocketLeave:
	walk_faster_left
	walk_faster_left
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_right
	walk_faster_right
	step_end

MahoganyTown_Shop_Movement_Dragonite1:
	lock_facing_direction
	walk_fast_right
	walk_fast_right
	walk_fast_left
	walk_fast_left
	unlock_facing_direction
	step_end

MahoganyTown_Shop_Movement_Dragonite2:
	lock_facing_direction
	walk_fast_right
	walk_fast_left
	unlock_facing_direction
	step_end

MahoganyTown_Shop_Movement_Rocket1:
	lock_facing_direction
	slide_right
	slide_right
	unlock_facing_direction
	step_end

MahoganyTown_Shop_Movement_LanceGreetPlayer:
	walk_down
	walk_right
	walk_right
	face_down
	step_end

MahoganyTown_Shop_Movement_DragoniteGotoBox:
	face_up
	delay_2
	face_right
	walk_right
	walk_up
	walk_up
	walk_up
	walk_up
	walk_right
	step_end

MahoganyTown_Shop_Movement_LanceGotoBox:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	face_right
	step_end

MahoganyTown_Shop_Movement_PlayerGotoBox:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

MahoganyTown_Shop_EventScript_Granny::
	lock
	faceplayer
	goto_if_eq VAR_MAHOGANY_TOWN_STATE, 5, MahoganyTown_Shop_EventScript_GrannyDuring
	goto_if_ge VAR_MAHOGANY_TOWN_STATE, 14, MahoganyTown_Shop_EventScript_GrannyShop
	msgbox MahoganyTown_Shop_Text_Granny, MSGBOX_NPC
	release
	end

MahoganyTown_Shop_EventScript_GrannyDuring::
	msgbox MahoganyMart1F_Text_Pharmacist_Lance, MSGBOX_DEFAULT
	closemessage
	release
	end


MahoganyTown_Shop_EventScript_GrannyShop::
	message gText_HowMayIServeYou
	waitmessage
	pokemart MahoganyTown_Pokemart
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
MahoganyTown_Pokemart:
	.2byte ITEM_METAL_COAT
	.2byte ITEM_DRAGON_SCALE
	.2byte ITEM_KINGS_ROCK
	.2byte ITEM_UP_GRADE
	.2byte ITEM_SPELL_TAG
	.2byte ITEM_NEVER_MELT_ICE
	.2byte ITEM_NONE
	release
	end

MahoganyTown_Shop_Text_Granny:
	.string "Please come back another time.\n"
	.string "The store is... closed\l"
	.string "right now.$"

MahoganyMart1F_Text_Pharmacist_Lance:
    .string "ROCKETS have hijacked my basement!$"

MahoganyMart1F_Text_BlackBelt:
    .string "Heheh! The experi- ment worked like\n"
    .string "a charm.\p"
    .string "MAGIKARP are just worthless, but\n"
    .string "GYARADOS are big moneymakers.$"

MahoganyMart1F_Text_BlackBelt_Lance:
    .string "Urrgh…\p"
    .string "That guy's POKéMON are tough…$"

MahoganyMart1F_Text_Lance_HyperBeam:
    .string "LANCE: DRAGONITE, HYPER BEAM.$"

MahoganyMart1F_Text_Lance_Radio:
    .string "What took you, {PLAYER}?\p"
    .string "Just as we thought, that strange\n"
    .string "radio signal is coming from here.$"

MahoganyMart1F_Text_Lance_Stairs:
    .string "Excellent work finding the stairs,\n"
	.string "DRAGONITE!$"

MahoganyMart1F_Text_Lance_SplitUp:
    .string "LANCE: {PLAYER}, we should split up\n"
    .string "to check this place.\p"
    .string "I'll go first.$"
