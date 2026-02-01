Blackhansa_Floor1_MapScripts::
	.byte 0


Blackhansa_Floor1_EventScript_ReturnToPetalburg::
	lockall
	playse SE_DOOR
	fadescreen FADE_TO_BLACK
	waitfadescreen

	warpsilent MAP_PETALBURG_CITY, 24, 7
	waitstate

	turnobject LOCALID_PLAYER, DIR_EAST

	fadescreen FADE_FROM_BLACK
	waitfadescreen
	releaseall
	end
