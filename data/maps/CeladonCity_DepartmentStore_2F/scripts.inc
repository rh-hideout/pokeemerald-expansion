CeladonCity_DepartmentStore_2F_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, CeladonDeptElevator_OnFrame
	.byte 0

CeladonDept2_EventScript_Pokefan::
	msgbox CeladonDeptStore2F_Text_PokefanM, MSGBOX_NPC
	end

CeladonDept2_EventScript_Youngster::
	msgbox CeladonDeptStore2F_Text_Youngster, MSGBOX_NPC
	end

CeladonDept2_EventScript_Directory::
	msgbox CeladonDeptStore2F_Text_Directory, MSGBOX_SIGN
	end

CeladonDeptStore2F_Text_PokefanM:
	.string "I just recently became a trainer.\p"
	.string "My son encouraged me to do it.\p"
	.string "I'm impressed by the selection of\n"
	.string "convenient items.$"

CeladonDeptStore2F_Text_Youngster:
	.string "My dad's having a hard time\n"
	.string "learning the names of items and\l"
	.string "how they are supposed to be used…$"

CeladonDeptStore2F_Text_Directory:
	.string "Top Grade Items for Trainers!\p"
	.string "2F: TRAINER'S MARKET$"

