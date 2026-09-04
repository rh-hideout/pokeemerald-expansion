CeladonCity_DepartmentStore_1F_Frlg_MapScripts::
	.byte 0

CeladonCity_DepartmentStore_1F_EventScript_Receptionist::
	msgbox CeladonCity_DepartmentStore_1F_Text_WelcomeToDeptStore, MSGBOX_NPC
	end

CeladonCity_DepartmentStore_1F_EventScript_LayoutSign::
	msgbox CeladonCity_DepartmentStore_1F_Text_FloorDescriptions, MSGBOX_SIGN
	end

CeladonCity_DepartmentStore_1F_EventScript_FloorSign::
	msgbox CeladonCity_DepartmentStore_1F_Text_ServiceCounter, MSGBOX_SIGN
	end

CeladonCity_DepartmentStore_1F_Text_WelcomeToDeptStore::
	.string "Hello!\n"
	.string "Welcome to [Celadon Dept. Store].\p"
	.string "The board on the right describes\n"
	.string "the store layout.$"

CeladonCity_DepartmentStore_1F_Text_FloorDescriptions::
	.string "1F: [Service Counter]\p"
	.string "2F: [Trainer's Market]\p"
	.string "3F: [TV Game Shop]\p"
	.string "4F: [Wise Man Gifts]\p"
	.string "5F: [Drugstore]\p"
	.string "[Rooftop Square]: [Vending Machines]$"

CeladonCity_DepartmentStore_1F_Text_ServiceCounter::
	.string "1F: [Service Counter]$"
