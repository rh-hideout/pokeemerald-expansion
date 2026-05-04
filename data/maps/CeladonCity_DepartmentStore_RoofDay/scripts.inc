CeladonCity_DepartmentStore_RoofDay_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, CeladonCity_DepartmentStore_RoofDay_OnTransition
	.byte 0

CeladonCity_DepartmentStore_RoofDay_OnTransition:
	call_if_set FLAG_DAY_POKEMON, CeladonCity_DepartmentStore_RoofDay_EventScript_SetNight
	call_if_unset FLAG_DAY_POKEMON, CeladonCity_DepartmentStore_RoofDay_EventScript_SetDay
	end

CeladonCity_DepartmentStore_RoofDay_EventScript_SetNight::
	setmaplayoutindex LAYOUT_CELADON_CITY_DEPARTMENT_STORE_ROOF_NIGHT
	return

CeladonCity_DepartmentStore_RoofDay_EventScript_SetDay::
	setmaplayoutindex LAYOUT_CELADON_CITY_DEPARTMENT_STORE_ROOF_DAY
	return

CeladonDept6_EventScript_Nerd::
	msgbox CeladonDeptStore6F_Text_SuperNerd, MSGBOX_NPC
	end
CeladonDept6_EventScript_Youngster::
	msgbox CeladonDeptStore6F_Text_Youngster, MSGBOX_NPC
	end
CeladonDept6_EventScript_Directory::
	msgbox CeladonDeptStore6F_Text_Directory, MSGBOX_SIGN
	end


CeladonDeptStore6F_Text_Vending:
	.string "A vending machine! Here's the menu.$"

CeladonDeptStore6F_Text_Clang:
	.string "Clang!\p"
	.string "{STRING} popped out.$"

CeladonDeptStore6F_Text_VendingNoMoney:
	.string "Oops, not enough money…$"

CeladonDeptStore6F_Text_VendingNoSpace:
	.string "There's no more room for stuff…$"

CeladonDeptStore6F_Text_SuperNerd:
	.string "A vending machine with a prize\n"
	.string "roulette…\p"
	.string "You never see those anymore.$"

CeladonDeptStore6F_Text_Youngster:
	.string "Aww! There's no games here!\p"
	.string "I wanted to play…$"

CeladonDeptStore6F_Text_Directory:
	.string "6F: ROOFTOP SQUARE VENDING\n"
	.string "MACHINES$"
