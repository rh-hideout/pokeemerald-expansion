#include "global.inc"
#include "constants/items.h"
#include "constants/flags.h"

EntryMapFlag3_MapScripts::
	.byte 0

@ A-Button / Sign / Background-Event
EntryMapFlag3_EventScript_DebugCheatStart::
	lock

	@ 100.000 Pokédollar (wird addiert)
	addmoney 100000, 0

	@ 20x JEDE Art Pokéball (große Auswahl; wenn ein ITEM_* bei dir nicht existiert -> Zeile löschen)
	additem ITEM_POKE_BALL, 20
	additem ITEM_GREAT_BALL, 20
	additem ITEM_ULTRA_BALL, 20
	additem ITEM_MASTER_BALL, 20
	additem ITEM_PREMIER_BALL, 20
	additem ITEM_SAFARI_BALL, 20
	additem ITEM_NET_BALL, 20
	additem ITEM_DIVE_BALL, 20
	additem ITEM_NEST_BALL, 20
	additem ITEM_REPEAT_BALL, 20
	additem ITEM_TIMER_BALL, 20
	additem ITEM_LUXURY_BALL, 20
	additem ITEM_HEAL_BALL, 20
	additem ITEM_QUICK_BALL, 20
	additem ITEM_DUSK_BALL, 20
	additem ITEM_CHERISH_BALL, 20

	@ Apricorn/weitere Bälle (in der Expansion i. d. R. vorhanden)
	additem ITEM_FAST_BALL, 20
	additem ITEM_LEVEL_BALL, 20
	additem ITEM_LURE_BALL, 20
	additem ITEM_HEAVY_BALL, 20
	additem ITEM_LOVE_BALL, 20
	additem ITEM_FRIEND_BALL, 20
	additem ITEM_MOON_BALL, 20
	additem ITEM_SPORT_BALL, 20
	additem ITEM_DREAM_BALL, 20
	additem ITEM_BEAST_BALL, 20

	@ 20x Tränke / Heilitems (klassische Auswahl)
	additem ITEM_POTION, 20
	additem ITEM_SUPER_POTION, 20
	additem ITEM_HYPER_POTION, 20
	additem ITEM_MAX_POTION, 20
	additem ITEM_FULL_RESTORE, 20

	additem ITEM_ANTIDOTE, 20
	additem ITEM_BURN_HEAL, 20
	additem ITEM_ICE_HEAL, 20
	additem ITEM_AWAKENING, 20
	additem ITEM_PARALYZE_HEAL, 20
	additem ITEM_FULL_HEAL, 20

	additem ITEM_REVIVE, 20
	additem ITEM_MAX_REVIVE, 20

	@ 100x Sonderbonbons
	additem ITEM_RARE_CANDY, 100

	@ Story-relevante Key Items (Emerald-typisch; falls eins fehlt -> Zeile löschen)
	additem ITEM_MACH_BIKE, 1
	additem ITEM_ACRO_BIKE, 1
	additem ITEM_OLD_ROD, 1
	additem ITEM_GOOD_ROD, 1
	additem ITEM_SUPER_ROD, 1
	additem ITEM_WAILMER_PAIL, 1
	additem ITEM_DEVON_GOODS, 1
	additem ITEM_LETTER, 1
	additem ITEM_ITEMFINDER, 1
	additem ITEM_POKENAV, 1
	additem ITEM_TOWN_MAP, 1
	additem ITEM_POKEBLOCK_CASE, 1
	additem ITEM_COIN_CASE, 1
	additem ITEM_SS_TICKET, 1
	additem ITEM_GO_GOGGLES, 1
	additem ITEM_DEVON_SCOPE, 1
	additem ITEM_BASEMENT_KEY, 1
	additem ITEM_STORAGE_KEY, 1
	additem ITEM_SCANNER, 1
	additem ITEM_MAGMA_EMBLEM, 1
	additem ITEM_METEORITE, 1
	additem ITEM_CONTEST_PASS, 1
	additem ITEM_SOOT_SACK, 1

	@ Abandoned Ship Keys (falls du sie nutzt)
	additem ITEM_ROOM_1_KEY, 1
	additem ITEM_ROOM_2_KEY, 1
	additem ITEM_ROOM_4_KEY, 1
	additem ITEM_ROOM_6_KEY, 1

	@ Event-/Story-Tickets (optional, aber oft praktisch fürs Testen)
	additem ITEM_EON_TICKET, 1
	additem ITEM_AURORA_TICKET, 1
	additem ITEM_MYSTIC_TICKET, 1
	additem ITEM_OLD_SEA_MAP, 1

	@ Deine neuen Items
	additem ITEM_RASPBERRY_PI, 1
	additem ITEM_LOCKPICK_SET, 1
	additem ITEM_PHONE_CORP_ID, 1

	@ Oft storyrelevant sind Flags (Running Shoes / Dex etc.) – optional fürs Debuggen:
	setflag FLAG_SYS_RUNNING_SHOES
	setflag FLAG_SYS_POKEDEX_GET
	setflag FLAG_SYS_POKENAV_GET
	setflag FLAG_SYS_POKEMON_GET

	msgbox EntryMapFlag3_Text_DebugCheatDone, MSGBOX_DEFAULT
	release
	end

EntryMapFlag3_Text_DebugCheatDone:
	.string "Debug loot granted.$"
