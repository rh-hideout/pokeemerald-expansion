.set LOCALID_GOLDENROD_MACHOKE1, 11
.set LOCALID_GOLDENROD_MACHOKE2, 12
.set LOCALID_GOLDENROD_MACHOKE3, 13

.set LOCALID_GOLDENROD_BOULDER1, 1
.set LOCALID_GOLDENROD_BOULDER2, 2
.set LOCALID_GOLDENROD_BOULDER3, 3

GoldenrodCity_DepartmentStoreBasement_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, GoldenrodDeptElevator_OnFrame
	map_script MAP_SCRIPT_ON_LOAD, GoldenrodCity_DepartmentStoreBasement_OnLoad
	.byte 0

GoldenrodCity_DepartmentStoreBasement_OnLoad::
	call_if_set FLAG_GOLDENROD_MACHOKE_1, GoldenrodCity_DepartmentStoreBasement_TryMachoke1
	call_if_set FLAG_GOLDENROD_MACHOKE_2, GoldenrodCity_DepartmentStoreBasement_TryMachoke2
	call_if_set FLAG_GOLDENROD_MACHOKE_3, GoldenrodCity_DepartmentStoreBasement_TryMachoke3

	end

GoldenrodCity_DepartmentStoreBasement_TryMachoke1::
	setobjectxyperm LOCALID_GOLDENROD_MACHOKE1, 1, 12
	setobjectxyperm LOCALID_GOLDENROD_BOULDER1, 1, 11
	setobjectmovementtype LOCALID_GOLDENROD_MACHOKE1, MOVEMENT_TYPE_FACE_RIGHT
	return

GoldenrodCity_DepartmentStoreBasement_TryMachoke2::
	setobjectxyperm LOCALID_GOLDENROD_MACHOKE2, 10, 11
	setobjectxyperm LOCALID_GOLDENROD_BOULDER2, 9, 11	
	setobjectmovementtype LOCALID_GOLDENROD_MACHOKE2, MOVEMENT_TYPE_FACE_DOWN
	return

GoldenrodCity_DepartmentStoreBasement_TryMachoke3::
	setobjectxyperm LOCALID_GOLDENROD_MACHOKE3, 17, 16
	setobjectxyperm LOCALID_GOLDENROD_BOULDER3, 18, 16
	setobjectmovementtype LOCALID_GOLDENROD_MACHOKE3, MOVEMENT_TYPE_FACE_LEFT
	return



GoldenrodCity_DepartmentStoreBasement_EventScript_BlackBelt1::
	lock
	goto_if_unset FLAG_GOLDENROD_MACHOKE_1, GoldenrodCity_DepartmentStoreBasement_EventScript_MachokeMoveBoulder1
	faceplayer
	msgbox GoldenrodDeptStore_Text_B1FBlackBelt1, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_DepartmentStoreBasement_EventScript_BlackBelt2::
	lock
	goto_if_unset FLAG_GOLDENROD_MACHOKE_2, GoldenrodCity_DepartmentStoreBasement_EventScript_BlackBelt2_Mid
	faceplayer
	msgbox GoldenrodDeptStore_Text_B1FBlackBelt2, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_DepartmentStoreBasement_EventScript_BlackBelt2_Mid::
	checkitem ITEM_CARD_KEY
	goto_if_eq VAR_RESULT, TRUE, GoldenrodCity_DepartmentStoreBasement_EventScript_MachokeMoveBoulder2
	msgbox GoldenrodDeptStore_Text_B1FBlackBelt2, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_DepartmentStoreBasement_EventScript_BlackBelt3::
	lock
	goto_if_unset FLAG_GOLDENROD_MACHOKE_3, GoldenrodCity_DepartmentStoreBasement_EventScript_MachokeMoveBoulder3
	faceplayer
	msgbox GoldenrodDeptStore_Text_B1FBlackBelt3After, MSGBOX_DEFAULT
	closemessage
	release
	end
	
GoldenrodCity_DepartmentStoreBasement_EventScript_Machoke::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_MACHOKE, CRY_MODE_NORMAL
	msgbox GoldenrodDeptStore_Text_B1FMachoke, MSGBOX_DEFAULT
	waitmoncry
	release
	end

GoldenrodCity_DepartmentStoreBasement_EventScript_MachokeMoveBoulder1::
	msgbox GoldenrodDeptStore_Text_BlackBeltMove, MSGBOX_DEFAULT
	closemessage
	playse SE_M_STRENGTH
	applymovement LOCALID_GOLDENROD_BOULDER1, GoldenrodCity_DepartmentStoreBasement_Movement_Boulder1
	applymovement LOCALID_GOLDENROD_MACHOKE1, GoldenrodCity_DepartmentStoreBasement_Movement_Machoke1
	waitmovement 0
	waitmovement 0
	setobjectxyperm LOCALID_GOLDENROD_MACHOKE1, 1, 12
	setobjectxyperm LOCALID_GOLDENROD_BOULDER1, 1, 11
	setflag FLAG_GOLDENROD_MACHOKE_1
	release
	end

GoldenrodCity_DepartmentStoreBasement_EventScript_MachokeMoveBoulder2::
	msgbox GoldenrodDeptStore_Text_BlackBeltMove, MSGBOX_DEFAULT
	closemessage
	playse SE_M_STRENGTH
	applymovement LOCALID_GOLDENROD_BOULDER2, GoldenrodCity_DepartmentStoreBasement_Movement_Boulder2
	applymovement LOCALID_GOLDENROD_MACHOKE2, GoldenrodCity_DepartmentStoreBasement_Movement_Machoke2
	waitmovement 0
	waitmovement 0
	setobjectxyperm LOCALID_GOLDENROD_MACHOKE2, 10, 11
	setobjectxyperm LOCALID_GOLDENROD_BOULDER2, 9, 11
	setflag FLAG_GOLDENROD_MACHOKE_2
	release
	end

GoldenrodCity_DepartmentStoreBasement_EventScript_MachokeMoveBoulder3::
	msgbox GoldenrodDeptStore_Text_BlackBeltMove, MSGBOX_DEFAULT
	closemessage
	playse SE_M_STRENGTH
	applymovement LOCALID_GOLDENROD_BOULDER3, GoldenrodCity_DepartmentStoreBasement_Movement_Boulder3
	applymovement LOCALID_GOLDENROD_MACHOKE3, GoldenrodCity_DepartmentStoreBasement_Movement_Machoke3
	waitmovement 0
	waitmovement 0
	setobjectxyperm LOCALID_GOLDENROD_MACHOKE3, 17, 16
	setobjectxyperm LOCALID_GOLDENROD_BOULDER3, 18, 16
	setflag FLAG_GOLDENROD_MACHOKE_3
	release
	end

GoldenrodCity_DepartmentStoreBasement_EventScript_Item_AmuletCoin::
	finditem ITEM_AMULET_COIN
	end

GoldenrodCity_DepartmentStoreBasement_EventScript_Item_Ether::
	finditem ITEM_ETHER
	end

GoldenrodCity_DepartmentStoreBasement_EventScript_Item_UltraBall::
	finditem ITEM_ULTRA_BALL
	end

GoldenrodCity_DepartmentStoreBasement_EventScript_Item_ExpShare::
	finditem ITEM_EXP_SHARE_SMALL
	end

GoldenrodCity_DepartmentStoreBasement_Movement_Machoke1:
	walk_left
	walk_left
	walk_left
	walk_down
	walk_left
	face_up
	step_end
	
GoldenrodCity_DepartmentStoreBasement_Movement_Boulder1:
	slide_left
	delay_8
	slide_left
	delay_8
	slide_left
	step_end

GoldenrodCity_DepartmentStoreBasement_Movement_Machoke2:
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

GoldenrodCity_DepartmentStoreBasement_Movement_Boulder2:
	slide_left
	slide_left
	slide_left
	slide_left
	step_end

GoldenrodCity_DepartmentStoreBasement_Movement_Machoke3:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

GoldenrodCity_DepartmentStoreBasement_Movement_Boulder3:
	slide_right
	slide_right
	slide_right
	slide_right
	slide_right
	step_end


GoldenrodDeptStore_Text_BlackBeltMove:
	.string "MACHOKE, help us move that boulder!$"

GoldenrodDeptStore_Text_B1FBlackBelt1:
    .string "Hey, kid! You're holding us up!\p"
    .string "Our policy is to work behind the\n"
    .string "scenes where no one can see us!$"

GoldenrodDeptStore_Text_B1FBlackBelt2:
    .string "I lose my passion for work if\n"
    .string "someone's watching.\p"
    .string "Come on, kid, scoot!$"

GoldenrodDeptStore_Text_B1FBlackBelt3:
    .string "Oohah! Oohah!\p"
    .string "What do you need kid?\l"
    .string "I'm working here!$"

GoldenrodDeptStore_Text_B1FBlackBelt3After:
    .string "Oohah! Oohah!\p"
    .string "The stuff on the ground's junk.\p"
    .string "Take it if you want it!$"

GoldenrodDeptStore_Text_B1FMachoke:
    .string "MACHOKE: Maaacho!$"
