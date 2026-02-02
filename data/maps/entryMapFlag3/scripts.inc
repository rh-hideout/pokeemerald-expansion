entryMapFlag3_MapScripts::
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
	additem ITEM_ITEMFINDER, 1
	additem ITEM_TOWN_MAP, 1

	@ Deine neuen Items
	additem ITEM_RASPBERRY_PI, 1
	additem ITEM_LOCKPICK_SET, 1
	additem ITEM_PHONE_CORP_ID, 1


	msgbox EntryMapFlag3_Text_DebugCheatDone, MSGBOX_DEFAULT
	release
	end

EntryMapFlag3_Text_DebugCheatDone:
	.string "Debug loot granted.$"



EntryMapFlag3_EventScript_GiveSuneon::
	lock
	givemon SPECIES_SUNEON, 15, ITEM_NONE
	msgbox EntryMapFlag3_Text_GiveSuneon, MSGBOX_DEFAULT
	release
	end

EntryMapFlag3_Text_GiveSuneon:
	.string "Received Suneon.$"


EntryMapFlag3_EventScript_GiveCelebi::
	lock
	givemon SPECIES_CELEBI, 50, item=ITEM_LEFTOVERS, ball=ITEM_GS_BALL, nature=NATURE_MODEST, abilityNum=2, gender=MON_MALE, hpEv=1, atkEv=0, defEv=3, speedEv=50, spAtkEv=50, spDefEv=6, hpIv=7, atkIv=8, defIv=9, speedIv=15, spAtkIv=11, spDefIv=12, move1=MOVE_GIGA_DRAIN, move2=MOVE_PSYCHIC, move3=MOVE_DAZZLING_GLEAM, move4=MOVE_LEAF_STORM, shinyMode=SHINY_MODE_ALWAYS
	msgbox EntryMapFlag3_Text_GiveCelebi, MSGBOX_DEFAULT
	release
	end

EntryMapFlag3_Text_GiveCelebi:
	.string "Received Celebi.$"
