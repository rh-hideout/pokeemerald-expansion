.set LOCALID_NURSE, 1

OldaleTown_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, OldaleTown_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

OldaleTown_PokemonCenter_1F_OnTransition:
	setrespawn HEAL_LOCATION_OLDALE_TOWN
	call Common_EventScript_UpdateBrineyLocation
	end

OldaleTown_PokemonCenter_1F_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

OldaleTown_PokemonCenter_1F_EventScript_Gentleman::
	msgbox OldaleTown_PokemonCenter_1F_Text_TrainersCanUsePC, MSGBOX_NPC
	end

OldaleTown_PokemonCenter_1F_EventScript_Boy::
	msgbox OldaleTown_PokemonCenter_1F_Text_PokemonCentersAreGreat, MSGBOX_NPC
	end

OldaleTown_PokemonCenter_1F_EventScript_Girl::
	lock
	faceplayer
	goto_if_set FLAG_SYS_POKEDEX_GET, OldaleTown_PokemonCenter_1F_EventScript_WirelessClubAvailable
	msgbox OldaleTown_PokemonCenter_1F_Text_WirelessClubNotAvailable, MSGBOX_DEFAULT
	release
	end

OldaleTown_PokemonCenter_1F_EventScript_WirelessClubAvailable::
	msgbox OldaleTown_PokemonCenter_1F_Text_TradedInWirelessClub, MSGBOX_DEFAULT
	release
	end

OldaleTown_PokemonCenter_1F_Text_TrainersCanUsePC:
	.string "That PC in the corner there is\n"
	.string "for any POKéMON TRAINER to use.\p"
	.string "Naturally, that means you're welcome\n"
	.string "to use it, too.$"

OldaleTown_PokemonCenter_1F_Text_PokemonCentersAreGreat:
	.string "POKéMON CENTERS are great!\p"
	.string "You can use their services as much\n"
	.string "as you like, and it's all for free.\l"
	.string "You never have to worry!$"

OldaleTown_PokemonCenter_1F_Text_WirelessClubNotAvailable:
	.string "The POKéMON WIRELESS CLUB on\n"
	.string "the second floor was built recently.\p"
	.string "But they say they're still making\n"
	.string "adjustments.$"

OldaleTown_PokemonCenter_1F_Text_TradedInWirelessClub:
	.string "The POKéMON WIRELESS CLUB on\n"
	.string "the second floor was built recently.\p"
	.string "I traded POKéMON right away.$"

GifterofallMons::
	msgbox Illgiveyouallmon_text, MSGBOX_DEFAULT
givemon SPECIES_KOROMON, 10
givemon SPECIES_YOKOMON, 10
givemon SPECIES_BUKAMON, 10
givemon SPECIES_TSUNOMON, 10
givemon SPECIES_TANEMON, 10
givemon SPECIES_MOTIMON, 10
givemon SPECIES_KODOKUGUMON2, 10
givemon SPECIES_DEMIMERAMON, 10
givemon SPECIES_KAPURIMON, 10
givemon SPECIES_DEMIVEEMON, 10
givemon SPECIES_POROMON, 10
givemon SPECIES_UPAMON, 10
givemon SPECIES_MINOMON, 10
givemon SPECIES_TOKOMON, 10
givemon SPECIES_NIYAROMON, 10
givemon SPECIES_PAGUMON, 10
givemon SPECIES_TSUMEMON, 10
givemon SPECIES_GIGIMON, 10
givemon SPECIES_GUMMYMON, 10
givemon SPECIES_KOKOMON, 10
givemon SPECIES_VIXIMON, 10
givemon SPECIES_YAAMON, 10
givemon SPECIES_CALUMON, 10
givemon SPECIES_GURIMON, 10
givemon SPECIES_PUYOYOMON, 10
givemon SPECIES_BOSAMON, 10
givemon SPECIES_BIBIMON, 10
givemon SPECIES_PUROROMON, 10
givemon SPECIES_FLUFFYMON, 10
givemon SPECIES_GOROMON, 10
givemon SPECIES_HIYARIMON, 10
givemon SPECIES_MISSIMON, 10
givemon SPECIES_ONIBIMON, 10
givemon SPECIES_AGUMON, 10
givemon SPECIES_GOMAMON , 10
givemon SPECIES_BIYOMON, 10
givemon SPECIES_TENTOMON, 10
givemon SPECIES_PATAMON, 10
givemon SPECIES_SALAMON, 10
givemon SPECIES_GABUMON, 10
givemon SPECIES_ELECMON, 10
givemon SPECIES_PALMON, 10
givemon SPECIES_FLORAMON, 10
givemon SPECIES_CRABMON, 10
givemon SPECIES_CANDLEMON, 10
givemon SPECIES_MUSHROOMON, 10
givemon SPECIES_BETAMON, 10
givemon SPECIES_OTAMAMON, 10
givemon SPECIES_DEMIDEVIMON, 10
givemon SPECIES_GAZIMON, 10
givemon SPECIES_GOBLIMON, 10
givemon SPECIES_BLACKAGUMON, 10
givemon SPECIES_BLACKGABUMON, 10
givemon SPECIES_ELECMONV, 10
givemon SPECIES_SNOWAGUMON, 10
givemon SPECIES_SNOWGOBLIMON, 10
givemon SPECIES_TAPIRMON, 10
givemon SPECIES_GOTSUMON, 10
givemon SPECIES_SYAKOMON, 10
givemon SPECIES_GIZAMON, 10
givemon SPECIES_CHUUMON, 10
givemon SPECIES_KUNEMON, 10
givemon SPECIES_HAGURUMON, 10
givemon SPECIES_SOLARMON, 10
givemon SPECIES_VEEMON, 10
givemon SPECIES_WORMMON, 10
givemon SPECIES_HAWKMON, 10
givemon SPECIES_ARMADILLOMON, 10
givemon SPECIES_KERAMON, 10
givemon SPECIES_TERRIERMON, 10
givemon SPECIES_LOPMON, 10
givemon SPECIES_GUILMON, 10
givemon SPECIES_RENAMON, 10
givemon SPECIES_MONODRAMON, 10
givemon SPECIES_IMPMON, 10
givemon SPECIES_BLACKGUILMON, 10
givemon SPECIES_FLAMEMON, 10
givemon SPECIES_STRABIMON, 10
givemon SPECIES_TINKERMON, 10
givemon SPECIES_KOKUWAMON, 10
givemon SPECIES_PENGUINMON, 10
givemon SPECIES_LUCEMON, 10
givemon SPECIES_MONMON, 10
givemon SPECIES_BEARMON, 10
givemon SPECIES_KOTEMON, 10
givemon SPECIES_RYUDAMON, 10
givemon SPECIES_SWIMMON, 10
givemon SPECIES_LUXMON, 10
givemon SPECIES_DORUMON, 10
givemon SPECIES_FANBEEMON, 10
givemon SPECIES_KODOKUGUMON3, 10
givemon SPECIES_COMMANDRAMON, 10
givemon SPECIES_SOUNDBIRDMON, 10
givemon SPECIES_GAOMON, 10
givemon SPECIES_LALAMON, 10
givemon SPECIES_CORONAMON, 10
givemon SPECIES_LUNAMON, 10
givemon SPECIES_JUNKMON, 10
givemon SPECIES_PHASCOMON, 10
givemon SPECIES_KKABUTERIMON, 10
givemon SPECIES_HACKMON, 10
givemon SPECIES_SISTERMONB, 10
givemon SPECIES_SISTERMONBA, 10
givemon SPECIES_PULSEMON, 10
givemon SPECIES_RURIMON, 10
givemon SPECIES_SANGOMON, 10
givemon SPECIES_POMUMON, 10
givemon SPECIES_VORVOMON, 10
givemon SPECIES_BULUCOMON, 10
givemon SPECIES_SUNARIZAMON, 10
givemon SPECIES_GHOSTMON, 10
givemon SPECIES_GAMMAMON, 10
givemon SPECIES_ANGORAMON, 10
givemon SPECIES_JELLYMON, 10
givemon SPECIES_ESPIMON, 10
givemon SPECIES_SHOEMON, 10
givemon SPECIES_PTEROMON, 10
givemon SPECIES_ELIZAMON, 10
givemon SPECIES_BATTERIMON, 10
givemon SPECIES_CHIKURIMON, 10
givemon SPECIES_HUBMON, 10
givemon SPECIES_MORPHOMON, 10
givemon SPECIES_UKKOMON, 10
givemon SPECIES_FLAMEDRAMON, 10
givemon SPECIES_LIGHDRAMON, 10
givemon SPECIES_DEPTHMON, 10
givemon SPECIES_YAKSAMON, 10
givemon SPECIES_SETHMON, 10
givemon SPECIES_GARGOYLEMON , 10
givemon SPECIES_HONEYBEEMON, 10
givemon SPECIES_MAGNAMON, 10
givemon SPECIES_GVEEDRAMON, 10
givemon SPECIES_KANGARUMON, 10
givemon SPECIES_SHADRAMON, 10
givemon SPECIES_TOGEMOGUMON, 10
givemon SPECIES_AURUMON, 10
givemon SPECIES_NOHEMON, 10
givemon SPECIES_SEARCHMON, 10
givemon SPECIES_BULLMON, 10
givemon SPECIES_ARCHELOMON, 10
givemon SPECIES_QUETZALMON, 10
givemon SPECIES_BUCCHIEMON, 10
givemon SPECIES_KONGOUMON, 10
givemon SPECIES_ALLOMON, 10
givemon SPECIES_RINKMON, 10
givemon SPECIES_HALSEMON, 10
givemon SPECIES_SHURIMON, 10
givemon SPECIES_FLYBEEMON, 10
givemon SPECIES_ORCAMON, 10
givemon SPECIES_MOOSEMON, 10
givemon SPECIES_HARPYMON, 10
givemon SPECIES_TOUCANMON, 10
givemon SPECIES_PEACOCKMON, 10
givemon SPECIES_LYNXMON, 10
givemon SPECIES_RABBITMON, 10
givemon SPECIES_SWANMON, 10
givemon SPECIES_KABUKIMON, 10
givemon SPECIES_BUTTERFLYMON, 10
givemon SPECIES_TYLOMON, 10
givemon SPECIES_ORYXMON, 10
givemon SPECIES_NEFERTIMON, 10
givemon SPECIES_OPOSSUMMON, 10
givemon SPECIES_MAILDRAMON, 10
givemon SPECIES_MAILDRAMONB, 10
givemon SPECIES_BOARMON, 10
givemon SPECIES_SEPIKMON, 10
givemon SPECIES_KENKIMON, 10
givemon SPECIES_PTERAMON, 10
givemon SPECIES_FROGMON, 10
givemon SPECIES_DIGMON, 10
givemon SPECIES_SUBMARIMON, 10
givemon SPECIES_SHEEPMON, 10
givemon SPECIES_SEAHOMON, 10
givemon SPECIES_CHAMELEMON, 10
givemon SPECIES_ELEPHANTMON, 10
givemon SPECIES_BAROMON, 10
givemon SPECIES_STEGOMON, 10
givemon SPECIES_PIPISMON, 10
givemon SPECIES_PONCHOMON, 10
givemon SPECIES_MOTHMON, 10
givemon SPECIES_MANTARAYMON, 10
givemon SPECIES_PEGASUSMON, 10
givemon SPECIES_MANBOMON, 10
givemon SPECIES_PRAIRIEMON, 10
givemon SPECIES_RHINOMON, 10
givemon SPECIES_TNDRBIRDMON, 10
givemon SPECIES_SALAMANDRMON, 10
givemon SPECIES_RAPIDMONG, 10
releaseall
end
	
	
	
Illgiveyouallmon_text:
	.string "here's all digimon.$"