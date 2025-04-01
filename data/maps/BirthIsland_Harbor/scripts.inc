.set LOCALID_SAILOR, 1
.set LOCALID_SS_TIDAL, 2

BirthIsland_Harbour_MapScripts::
	.byte 0

BirthIsland_Harbour_EventScript_Sailor::
	lock
	faceplayer
	msgbox BirthIsland_Harbour_Text_SailorReturn, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BirthIsland_Harbour_EventScript_AsYouLike
	msgbox EventTicket_Text_SailHome, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	delay 30
	hideobjectat LOCALID_SAILOR, MAP_BIRTH_ISLAND_HARBOUR
	setvar VAR_0x8004, LOCALID_SS_TIDAL
	call Common_EventScript_FerryDepartIsland
	warp MAP_LILYCOVE_CITY_HARBOUR, 8, 11
	waitstate
	release
	end

BirthIsland_Harbour_EventScript_AsYouLike::
	msgbox EventTicket_Text_AsYouLike, MSGBOX_DEFAULT
	release
	end

