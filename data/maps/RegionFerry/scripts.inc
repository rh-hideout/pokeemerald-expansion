RegionFerry_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, RegionFerry_OnTransition
	.byte 0

RegionFerry_OnTransition:
	switch VAR_TEMP_0
	case 0, RegionFerry_EventScript_ChooseKanto
	case 1, RegionFerry_EventScript_ChooseJohto
	case 2, RegionFerry_EventScript_ChooseHoenn
	end

RegionFerry_EventScript_ChooseKanto:
	msgbox RegionFerry_Text_GoToKanto, MSGBOX_DEFAULT
	closemessage
	warp MAP_KANTO_PORT, 0, 0
	end

RegionFerry_EventScript_ChooseJohto:
	msgbox RegionFerry_Text_GoToJohto, MSGBOX_DEFAULT
	closemessage
	warp MAP_JOHTO_PORT, 0, 0
	end

RegionFerry_EventScript_ChooseHoenn:
	msgbox RegionFerry_Text_GoToHoenn, MSGBOX_DEFAULT
	closemessage
	warp MAP_HOENN_PORT, 0, 0
	end

RegionFerry_Text_GoToKanto:
	.string "Vamos a Kanto.\nDonde empezó esta historia Pokémon.$"

RegionFerry_Text_GoToJohto:
	.string "Vamos a Johto.\nLa región de los nuevos desafíos.$"

RegionFerry_Text_GoToHoenn:
	.string "Vamos a Hoenn.\nLa región de la aventura.$"