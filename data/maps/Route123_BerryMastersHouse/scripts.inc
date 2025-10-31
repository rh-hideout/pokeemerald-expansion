# 1 "data/maps/Route123_BerryMastersHouse/scripts.pory"

# 2 "data/maps/Route123_BerryMastersHouse/scripts.pory"
Route123_BerryMastersHouse_MapScripts::
# 3 "data/maps/Route123_BerryMastersHouse/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, Route123_BerryMastersHouse_OnTransition
# 4 "data/maps/Route123_BerryMastersHouse/scripts.pory"
	.byte 0
# 5 "data/maps/Route123_BerryMastersHouse/scripts.pory"

# 6 "data/maps/Route123_BerryMastersHouse/scripts.pory"
Route123_BerryMastersHouse_OnTransition:
# 7 "data/maps/Route123_BerryMastersHouse/scripts.pory"
	setflag FLAG_LANDMARK_BERRY_MASTERS_HOUSE
# 8 "data/maps/Route123_BerryMastersHouse/scripts.pory"
	end
# 9 "data/maps/Route123_BerryMastersHouse/scripts.pory"

# 10 "data/maps/Route123_BerryMastersHouse/scripts.pory"
Route123_BerryMastersHouse_EventScript_BerryMaster::
# 11 "data/maps/Route123_BerryMastersHouse/scripts.pory"
	lock
# 12 "data/maps/Route123_BerryMastersHouse/scripts.pory"
	faceplayer
# 13 "data/maps/Route123_BerryMastersHouse/scripts.pory"
	dotimebasedevents
# 14 "data/maps/Route123_BerryMastersHouse/scripts.pory"
	goto_if_set FLAG_DAILY_BERRY_MASTER_RECEIVED_BERRY, Route123_BerryMastersHouse_EventScript_ReceivedBerryToday
# 15 "data/maps/Route123_BerryMastersHouse/scripts.pory"
	msgbox Route123_BerryMastersHouse_Text_YoureDeservingOfBerry, MSGBOX_DEFAULT
# 16 "data/maps/Route123_BerryMastersHouse/scripts.pory"
	random NUM_BERRY_MASTER_BERRIES
# 17 "data/maps/Route123_BerryMastersHouse/scripts.pory"
	addvar VAR_RESULT, NUM_BERRY_MASTER_BERRIES_SKIPPED
# 18 "data/maps/Route123_BerryMastersHouse/scripts.pory"
	addvar VAR_RESULT, FIRST_BERRY_INDEX
# 19 "data/maps/Route123_BerryMastersHouse/scripts.pory"
	giveitem VAR_RESULT
# 20 "data/maps/Route123_BerryMastersHouse/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
# 21 "data/maps/Route123_BerryMastersHouse/scripts.pory"
	setflag FLAG_DAILY_BERRY_MASTER_RECEIVED_BERRY
# 22 "data/maps/Route123_BerryMastersHouse/scripts.pory"
	msgbox Route123_BerryMastersHouse_Text_WhyBeStingyTakeAnother, MSGBOX_DEFAULT
# 23 "data/maps/Route123_BerryMastersHouse/scripts.pory"
	random NUM_BERRY_MASTER_BERRIES
# 24 "data/maps/Route123_BerryMastersHouse/scripts.pory"
	addvar VAR_RESULT, NUM_BERRY_MASTER_BERRIES_SKIPPED
# 25 "data/maps/Route123_BerryMastersHouse/scripts.pory"
	addvar VAR_RESULT, FIRST_BERRY_INDEX
# 26 "data/maps/Route123_BerryMastersHouse/scripts.pory"
	giveitem VAR_RESULT
# 27 "data/maps/Route123_BerryMastersHouse/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
# 28 "data/maps/Route123_BerryMastersHouse/scripts.pory"
	msgbox Route123_BerryMastersHouse_Text_VisitPrettyPetalFlowerShop, MSGBOX_DEFAULT
# 29 "data/maps/Route123_BerryMastersHouse/scripts.pory"
	release
# 30 "data/maps/Route123_BerryMastersHouse/scripts.pory"
	end
# 31 "data/maps/Route123_BerryMastersHouse/scripts.pory"

# 32 "data/maps/Route123_BerryMastersHouse/scripts.pory"
Route123_BerryMastersHouse_EventScript_ReceivedBerryToday::
# 33 "data/maps/Route123_BerryMastersHouse/scripts.pory"
	msgbox Route123_BerryMastersHouse_Text_DoneForToday, MSGBOX_DEFAULT
# 34 "data/maps/Route123_BerryMastersHouse/scripts.pory"
	release
# 35 "data/maps/Route123_BerryMastersHouse/scripts.pory"
	end
# 36 "data/maps/Route123_BerryMastersHouse/scripts.pory"

# 37 "data/maps/Route123_BerryMastersHouse/scripts.pory"
Route123_BerryMastersHouse_EventScript_BerryMastersWife::
# 38 "data/maps/Route123_BerryMastersHouse/scripts.pory"
	lock
# 39 "data/maps/Route123_BerryMastersHouse/scripts.pory"
	faceplayer
# 40 "data/maps/Route123_BerryMastersHouse/scripts.pory"
	dotimebasedevents
# 41 "data/maps/Route123_BerryMastersHouse/scripts.pory"
	goto_if_set FLAG_DAILY_BERRY_MASTERS_WIFE, Route123_BerryMastersHouse_EventScript_ReceivedWifeBerryToday
# 42 "data/maps/Route123_BerryMastersHouse/scripts.pory"
	msgbox Route123_BerryMastersHouse_Text_HeardAGoodSayingLately, MSGBOX_DEFAULT
# 43 "data/maps/Route123_BerryMastersHouse/scripts.pory"
	setvar VAR_0x8004, EASY_CHAT_TYPE_GOOD_SAYING
# 44 "data/maps/Route123_BerryMastersHouse/scripts.pory"
	call Common_ShowEasyChatScreen
# 45 "data/maps/Route123_BerryMastersHouse/scripts.pory"
	lock
# 46 "data/maps/Route123_BerryMastersHouse/scripts.pory"
	faceplayer
# 47 "data/maps/Route123_BerryMastersHouse/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, Route123_BerryMastersHouse_EventScript_GavePhrase
# 48 "data/maps/Route123_BerryMastersHouse/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, Route123_BerryMastersHouse_EventScript_CancelPhrase
# 49 "data/maps/Route123_BerryMastersHouse/scripts.pory"
	end
# 50 "data/maps/Route123_BerryMastersHouse/scripts.pory"

# 51 "data/maps/Route123_BerryMastersHouse/scripts.pory"
Route123_BerryMastersHouse_EventScript_CancelPhrase::
# 52 "data/maps/Route123_BerryMastersHouse/scripts.pory"
	msgbox Route123_BerryMastersHouse_Text_Ah, MSGBOX_DEFAULT
# 53 "data/maps/Route123_BerryMastersHouse/scripts.pory"
	msgbox Route123_BerryMastersHouse_Text_JoyNeverGoesOutOfMyLife, MSGBOX_DEFAULT
# 54 "data/maps/Route123_BerryMastersHouse/scripts.pory"
	release
# 55 "data/maps/Route123_BerryMastersHouse/scripts.pory"
	end
# 56 "data/maps/Route123_BerryMastersHouse/scripts.pory"

# 57 "data/maps/Route123_BerryMastersHouse/scripts.pory"
Route123_BerryMastersHouse_EventScript_GavePhrase::
# 58 "data/maps/Route123_BerryMastersHouse/scripts.pory"
	goto_if_eq VAR_0x8004, NOT_SPECIAL_PHRASE, Route123_BerryMastersHouse_EventScript_GiveNormalBerry
# 59 "data/maps/Route123_BerryMastersHouse/scripts.pory"
	goto_if_eq VAR_0x8004, PHRASE_GREAT_BATTLE, Route123_BerryMastersHouse_EventScript_GiveSpelonBerry
# 60 "data/maps/Route123_BerryMastersHouse/scripts.pory"
	goto_if_eq VAR_0x8004, PHRASE_CHALLENGE_CONTEST, Route123_BerryMastersHouse_EventScript_GivePamtreBerry
# 61 "data/maps/Route123_BerryMastersHouse/scripts.pory"
	goto_if_eq VAR_0x8004, PHRASE_OVERWHELMING_LATIAS, Route123_BerryMastersHouse_EventScript_GiveWatmelBerry
# 62 "data/maps/Route123_BerryMastersHouse/scripts.pory"
	goto_if_eq VAR_0x8004, PHRASE_COOL_LATIOS, Route123_BerryMastersHouse_EventScript_GiveDurinBerry
# 63 "data/maps/Route123_BerryMastersHouse/scripts.pory"
	goto_if_eq VAR_0x8004, PHRASE_SUPER_HUSTLE, Route123_BerryMastersHouse_EventScript_GiveBelueBerry
# 64 "data/maps/Route123_BerryMastersHouse/scripts.pory"
	end
# 65 "data/maps/Route123_BerryMastersHouse/scripts.pory"

# 66 "data/maps/Route123_BerryMastersHouse/scripts.pory"
Route123_BerryMastersHouse_EventScript_GiveNormalBerry::
# 67 "data/maps/Route123_BerryMastersHouse/scripts.pory"
	msgbox Route123_BerryMastersHouse_Text_GoodSayingTakeThis, MSGBOX_DEFAULT
# 68 "data/maps/Route123_BerryMastersHouse/scripts.pory"
	random NUM_BERRY_MASTER_WIFE_BERRIES
# 69 "data/maps/Route123_BerryMastersHouse/scripts.pory"
	addvar VAR_RESULT, FIRST_BERRY_INDEX
# 70 "data/maps/Route123_BerryMastersHouse/scripts.pory"
	giveitem VAR_RESULT
# 71 "data/maps/Route123_BerryMastersHouse/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
# 72 "data/maps/Route123_BerryMastersHouse/scripts.pory"
	goto Route123_BerryMastersHouse_EventScript_GaveBerry
# 73 "data/maps/Route123_BerryMastersHouse/scripts.pory"
	release
# 74 "data/maps/Route123_BerryMastersHouse/scripts.pory"
	end
# 75 "data/maps/Route123_BerryMastersHouse/scripts.pory"

# 76 "data/maps/Route123_BerryMastersHouse/scripts.pory"
Route123_BerryMastersHouse_EventScript_GiveSpelonBerry::
# 77 "data/maps/Route123_BerryMastersHouse/scripts.pory"
	goto_if_set FLAG_RECEIVED_SPELON_BERRY, Route123_BerryMastersHouse_EventScript_GiveNormalBerry
# 78 "data/maps/Route123_BerryMastersHouse/scripts.pory"
	msgbox Route123_BerryMastersHouse_Text_InspirationalTakeThis, MSGBOX_DEFAULT
# 79 "data/maps/Route123_BerryMastersHouse/scripts.pory"
	giveitem ITEM_SPELON_BERRY
# 80 "data/maps/Route123_BerryMastersHouse/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
# 81 "data/maps/Route123_BerryMastersHouse/scripts.pory"
	setflag FLAG_RECEIVED_SPELON_BERRY
# 82 "data/maps/Route123_BerryMastersHouse/scripts.pory"
	goto Route123_BerryMastersHouse_EventScript_GaveBerry
# 83 "data/maps/Route123_BerryMastersHouse/scripts.pory"
	end
# 84 "data/maps/Route123_BerryMastersHouse/scripts.pory"

# 85 "data/maps/Route123_BerryMastersHouse/scripts.pory"
Route123_BerryMastersHouse_EventScript_GivePamtreBerry::
# 86 "data/maps/Route123_BerryMastersHouse/scripts.pory"
	goto_if_set FLAG_RECEIVED_PAMTRE_BERRY, Route123_BerryMastersHouse_EventScript_GiveNormalBerry
# 87 "data/maps/Route123_BerryMastersHouse/scripts.pory"
	msgbox Route123_BerryMastersHouse_Text_InspirationalTakeThis, MSGBOX_DEFAULT
# 88 "data/maps/Route123_BerryMastersHouse/scripts.pory"
	giveitem ITEM_PAMTRE_BERRY
# 89 "data/maps/Route123_BerryMastersHouse/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
# 90 "data/maps/Route123_BerryMastersHouse/scripts.pory"
	setflag FLAG_RECEIVED_PAMTRE_BERRY
# 91 "data/maps/Route123_BerryMastersHouse/scripts.pory"
	goto Route123_BerryMastersHouse_EventScript_GaveBerry
# 92 "data/maps/Route123_BerryMastersHouse/scripts.pory"
	end
# 93 "data/maps/Route123_BerryMastersHouse/scripts.pory"

# 94 "data/maps/Route123_BerryMastersHouse/scripts.pory"
Route123_BerryMastersHouse_EventScript_GiveWatmelBerry::
# 95 "data/maps/Route123_BerryMastersHouse/scripts.pory"
	goto_if_set FLAG_RECEIVED_WATMEL_BERRY, Route123_BerryMastersHouse_EventScript_GiveNormalBerry
# 96 "data/maps/Route123_BerryMastersHouse/scripts.pory"
	msgbox Route123_BerryMastersHouse_Text_InspirationalTakeThis, MSGBOX_DEFAULT
# 97 "data/maps/Route123_BerryMastersHouse/scripts.pory"
	giveitem ITEM_WATMEL_BERRY
# 98 "data/maps/Route123_BerryMastersHouse/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
# 99 "data/maps/Route123_BerryMastersHouse/scripts.pory"
	setflag FLAG_RECEIVED_WATMEL_BERRY
# 100 "data/maps/Route123_BerryMastersHouse/scripts.pory"
	goto Route123_BerryMastersHouse_EventScript_GaveBerry
# 101 "data/maps/Route123_BerryMastersHouse/scripts.pory"
	end
# 102 "data/maps/Route123_BerryMastersHouse/scripts.pory"

# 103 "data/maps/Route123_BerryMastersHouse/scripts.pory"
Route123_BerryMastersHouse_EventScript_GiveDurinBerry::
# 104 "data/maps/Route123_BerryMastersHouse/scripts.pory"
	goto_if_set FLAG_RECEIVED_DURIN_BERRY, Route123_BerryMastersHouse_EventScript_GiveNormalBerry
# 105 "data/maps/Route123_BerryMastersHouse/scripts.pory"
	msgbox Route123_BerryMastersHouse_Text_InspirationalTakeThis, MSGBOX_DEFAULT
# 106 "data/maps/Route123_BerryMastersHouse/scripts.pory"
	giveitem ITEM_DURIN_BERRY
# 107 "data/maps/Route123_BerryMastersHouse/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
# 108 "data/maps/Route123_BerryMastersHouse/scripts.pory"
	setflag FLAG_RECEIVED_DURIN_BERRY
# 109 "data/maps/Route123_BerryMastersHouse/scripts.pory"
	goto Route123_BerryMastersHouse_EventScript_GaveBerry
# 110 "data/maps/Route123_BerryMastersHouse/scripts.pory"
	end
# 111 "data/maps/Route123_BerryMastersHouse/scripts.pory"

# 112 "data/maps/Route123_BerryMastersHouse/scripts.pory"
Route123_BerryMastersHouse_EventScript_GiveBelueBerry::
# 113 "data/maps/Route123_BerryMastersHouse/scripts.pory"
	goto_if_set FLAG_RECEIVED_BELUE_BERRY, Route123_BerryMastersHouse_EventScript_GiveNormalBerry
# 114 "data/maps/Route123_BerryMastersHouse/scripts.pory"
	msgbox Route123_BerryMastersHouse_Text_InspirationalTakeThis, MSGBOX_DEFAULT
# 115 "data/maps/Route123_BerryMastersHouse/scripts.pory"
	giveitem ITEM_BELUE_BERRY
# 116 "data/maps/Route123_BerryMastersHouse/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
# 117 "data/maps/Route123_BerryMastersHouse/scripts.pory"
	setflag FLAG_RECEIVED_BELUE_BERRY
# 118 "data/maps/Route123_BerryMastersHouse/scripts.pory"
	goto Route123_BerryMastersHouse_EventScript_GaveBerry
# 119 "data/maps/Route123_BerryMastersHouse/scripts.pory"
	end
# 120 "data/maps/Route123_BerryMastersHouse/scripts.pory"

# 121 "data/maps/Route123_BerryMastersHouse/scripts.pory"
Route123_BerryMastersHouse_EventScript_ReceivedWifeBerryToday::
# 122 "data/maps/Route123_BerryMastersHouse/scripts.pory"
	msgbox Route123_BerryMastersHouse_Text_JoyNeverGoesOutOfMyLife, MSGBOX_DEFAULT
# 123 "data/maps/Route123_BerryMastersHouse/scripts.pory"
	release
# 124 "data/maps/Route123_BerryMastersHouse/scripts.pory"
	end
# 125 "data/maps/Route123_BerryMastersHouse/scripts.pory"

# 126 "data/maps/Route123_BerryMastersHouse/scripts.pory"
Route123_BerryMastersHouse_EventScript_GaveBerry::
# 127 "data/maps/Route123_BerryMastersHouse/scripts.pory"
	setflag FLAG_DAILY_BERRY_MASTERS_WIFE
# 128 "data/maps/Route123_BerryMastersHouse/scripts.pory"
	msgbox Route123_BerryMastersHouse_Text_JoyNeverGoesOutOfMyLife, MSGBOX_DEFAULT
# 129 "data/maps/Route123_BerryMastersHouse/scripts.pory"
	release
# 130 "data/maps/Route123_BerryMastersHouse/scripts.pory"
	end
