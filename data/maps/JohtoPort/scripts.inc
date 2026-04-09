JohtoPort_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, JohtoPort_OnTransition
	.byte 0

JohtoPort_OnTransition:
	special Special_ExecuteTruckSequence
	end