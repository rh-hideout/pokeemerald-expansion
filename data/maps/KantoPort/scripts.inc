KantoPort_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, KantoPort_OnTransition
	.byte 0

KantoPort_OnTransition:
	special Special_ExecuteTruckSequence
	end