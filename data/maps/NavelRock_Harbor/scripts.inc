# 1 "data/maps/NavelRock_Harbor/scripts.pory"

# 2 "data/maps/NavelRock_Harbor/scripts.pory"
NavelRock_Harbor_MapScripts::
# 3 "data/maps/NavelRock_Harbor/scripts.pory"
	.byte 0
# 4 "data/maps/NavelRock_Harbor/scripts.pory"

# 5 "data/maps/NavelRock_Harbor/scripts.pory"
NavelRock_Harbor_EventScript_Sailor::
# 6 "data/maps/NavelRock_Harbor/scripts.pory"
	lock
# 7 "data/maps/NavelRock_Harbor/scripts.pory"
	faceplayer
# 8 "data/maps/NavelRock_Harbor/scripts.pory"
	msgbox NavelRock_Harbor_Text_SailorReturn, MSGBOX_YESNO
# 9 "data/maps/NavelRock_Harbor/scripts.pory"
	goto_if_eq VAR_RESULT, NO, NavelRock_Harbor_EventScript_AsYouLike
# 10 "data/maps/NavelRock_Harbor/scripts.pory"
	msgbox EventTicket_Text_SailHome, MSGBOX_DEFAULT
# 11 "data/maps/NavelRock_Harbor/scripts.pory"
	closemessage
# 12 "data/maps/NavelRock_Harbor/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceFasterDown
# 13 "data/maps/NavelRock_Harbor/scripts.pory"
	waitmovement 0
# 14 "data/maps/NavelRock_Harbor/scripts.pory"
	delay 30
# 15 "data/maps/NavelRock_Harbor/scripts.pory"
	hideobjectat LOCALID_NAVEL_ROCK_SAILOR, MAP_NAVEL_ROCK_HARBOR
# 16 "data/maps/NavelRock_Harbor/scripts.pory"
	setvar VAR_0x8004, LOCALID_NAVEL_ROCK_SS_TIDAL
# 17 "data/maps/NavelRock_Harbor/scripts.pory"
	call Common_EventScript_FerryDepartIsland
# 18 "data/maps/NavelRock_Harbor/scripts.pory"
	warp MAP_LILYCOVE_CITY_HARBOR, 8, 11
# 19 "data/maps/NavelRock_Harbor/scripts.pory"
	waitstate
# 20 "data/maps/NavelRock_Harbor/scripts.pory"
	release
# 21 "data/maps/NavelRock_Harbor/scripts.pory"
	end
# 22 "data/maps/NavelRock_Harbor/scripts.pory"

# 23 "data/maps/NavelRock_Harbor/scripts.pory"
NavelRock_Harbor_EventScript_AsYouLike::
# 24 "data/maps/NavelRock_Harbor/scripts.pory"
	msgbox EventTicket_Text_AsYouLike, MSGBOX_DEFAULT
# 25 "data/maps/NavelRock_Harbor/scripts.pory"
	release
# 26 "data/maps/NavelRock_Harbor/scripts.pory"
	end
