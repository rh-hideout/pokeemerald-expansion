CeladonCity_DepartmentStore_1F_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, CeladonDeptElevator_OnFrame
	.byte 0

CeladonDept1_EventScript_Receptionsit::
    msgbox CeladonDeptStore_Text_1FReceptionist, MSGBOX_NPC
    end

CeladonDept1_EventScript_Gent::
    msgbox CeladonDeptStore_Text_1FGentleman, MSGBOX_NPC
    end

CeladonDept1_EventScript_Teacher::
    msgbox CeladonDeptStore_Text_1FTeacher, MSGBOX_NPC
    end

CeladonDept1_EventScript_Directory::
    msgbox CeladonDeptStore_Text_1FDirectory, MSGBOX_SIGN
    end

CeladonDeptStore_Text_1FReceptionist:
    .string "Hello! Welcome to CELADON DEPT.\n"
    .string "STORE!\p"
    .string "The directory is on the wall.$"

CeladonDeptStore_Text_1FGentleman:
    .string "This DEPT.STORE is part of the same\n"
    .string "chain as the one in GOLDENROD CITY.\p"
    .string "They were both renovated at the same\n"
    .string "time.$"

CeladonDeptStore_Text_1FTeacher:
    .string "This is my first time here.\p"
    .string "It's so big…\p"
    .string "I'm afraid I'll get lost.$"

CeladonDeptStore_Text_1FDirectory:
    .string "1F: SERVICE COUNTER\p"
    .string "2F: TRAINER'S MARKET\p"
    .string "3F: TM SHOP\p"
    .string "4F: WISEMAN GIFTS\p"
    .string "5F: DRUG STORE\p"
    .string "6F: ROOFTOP SQUARE$"
