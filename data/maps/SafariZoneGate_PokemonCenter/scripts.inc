.set LOCALID_NURSE, 1

SafariZoneGate_PokemonCenter_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, SafariZoneGate_PokemonCenter_OnTransition
	.byte 0

SafariZoneGate_PokemonCenter_OnTransition::
	setrespawn HEAL_LOCATION_SAFARI_ZONE_GATE
	end

SafariZoneGate_PokemonCenter_EventScript_NPC1::
	lock
	faceplayer
	msgbox SafariZoneGate_PokemonCenter_Text_NPC1, MSGBOX_DEFAULT
	closemessage
	release
	end

SafariZoneGate_PokemonCenter_EventScript_NPC2::
	lock
	faceplayer
	msgbox SafariZoneGate_PokemonCenter_Text_NPC2, MSGBOX_DEFAULT
	closemessage
	release
	end

SafariZoneGate_PokemonCenter_Text_Boy::
	lock
	faceplayer
	msgbox SafariZoneGate_PokemonCenter_Text_SafariSong, MSGBOX_DEFAULT
	closemessage
	release
	end

SafariZoneGate_PokemonCenter_Text_NPC1:
	.string "Those who come to a POKéMON CENTER\n"
	.string "often take good care of their POKéMON.\p"
	.string "Wouldn't you agree?$"

SafariZoneGate_PokemonCenter_Text_NPC2:
	.string "After a long walk in the mountains to\n"
	.string "find a POKéMON CENTER, when you're\l"
	.string "just about to fall flat...\p"
	.string "Then it feels like you are in paradise!$"

SafariZoneGate_PokemonCenter_Text_SafariSong:
	.string "Safari, safari, it is so much fun.\n"
	.string "Safari, safari, so interesting, huh!\p"
	.string "So many POKéMON are waiting for us!\p"
	.string "...That's a song I made up.\n"
	.string "I sing it when I am in the SAFARI ZONE.$"
