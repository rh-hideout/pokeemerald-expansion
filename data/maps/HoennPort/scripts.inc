HoennPort_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, HoennPort_OnTransition
	.byte 0

HoennPort_OnTransition:
	special Special_ExecuteTruckSequence
	end