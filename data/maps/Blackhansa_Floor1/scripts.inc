Blackhansa_Floor1_MapScripts::
	.byte 0


Blackhansa_Floor1_EventScript_ReturnToPetalburg::
	lockall

	warpteleport MAP_PETALBURG_CITY, 24, 7
	waitstate

	@ nach dem Port: Blick nach rechts
	applymovement LOCALID_PLAYER, Blackhansa_Floor1_Movement_PlayerFaceRight
	waitmovement 0

	releaseall
	end

Blackhansa_Floor1_Movement_PlayerFaceRight::
	face_right
	step_end
