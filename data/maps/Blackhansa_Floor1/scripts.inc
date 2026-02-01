Blackhansa_Floor1_MapScripts::
	.byte 0


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
