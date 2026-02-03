Blackhansa_Floor1_MapScripts::
    map_script MAP_SCRIPT_ON_TRANSITION, Blackhansa_Floor1_OnTransition
    .byte 0

Blackhansa_Floor1_OnTransition:
	setflag FLAG_BLACKHANSA_F2_IT_MANAGER_HIDDEN
	end


Blackhansa_Floor1_EventScript_ReturnToPetalburg::
	lockall
	playse SE_DOOR
	waitse

	warpsilent MAP_PETALBURG_CITY, 24, 7
	waitstate

	turnobject LOCALID_PLAYER, DIR_EAST

	waitstate
	releaseall
	end
