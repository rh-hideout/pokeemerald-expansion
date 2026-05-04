MtMortar_1F_North_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, MtMortar_1F_North_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

MtMortar_1F_North_OnTransition: 
	callnative SetTimeBasedEncounters
	end

MtMortar_1F_North_EventScript_Item_MaxRepel::
    finditem ITEM_MAX_REPEL
    end

MtMortar_1F_North_EventScript_Item_EscapeRope::
    finditem ITEM_ESCAPE_ROPE
    end

MtMortar_1F_North_EventScript_Item_MaxPotion::
    finditem ITEM_MAX_POTION
    end

MtMortar_1F_North_EventScript_Item_Nugget::
    finditem ITEM_NUGGET
    end

MtMortar_1F_North_EventScript_Item_UltraBall::
    finditem ITEM_ULTRA_BALL
    end

MtMortar_1F_North_EventScript_Item_FullIncense::
    finditem ITEM_REVIVE
    end

MtMortar_1F_North_EventScript_Item_KingsRock::
    finditem ITEM_KINGS_ROCK
    end

MtMortar_1F_North_EventScript_Miller::
	trainerbattle_single TRAINER_MILLER MountMortar2_Text_PokemaniacMillerSeen, MountMortar2_Text_PokemaniacMillerBeaten
	msgbox MountMortar2_Text_PokemaniacMillerAfter, MSGBOX_AUTOCLOSE
	end

MtMortar_1F_North_EventScript_Markus::
	trainerbattle_single TRAINER_MARKUS MountMortar2_Text_SupernerdMarkusSeen, MountMortar2_Text_SupernerdMarkusBeaten
	msgbox MountMortar2_Text_SupernerdMarkusAfter, MSGBOX_AUTOCLOSE
	end

MountMortar2_Text_PokemaniacMillerSeen:
	.string "I'm not losing this time!$"

MountMortar2_Text_PokemaniacMillerBeaten:
	.string "I lost to some kid...?$"

MountMortar2_Text_PokemaniacMillerAfter:
	.string "A while back, this karate dude\n"
	.string "wanted to battle.\p"
	.string "He was ridiculously good.\n"
	.string "He just thrashed us silly.\p"
	.string "He went in deeper saying it\n"
	.string "was for his training.\p"
	.string "I wonder how he is?$"

MountMortar2_Text_SupernerdMarkusSeen:
	.string "Hey! HUGH!$"

MountMortar2_Text_SupernerdMarkusBeaten:
	.string "I mistook you for someone\n"
	.string "else…$"

MountMortar2_Text_SupernerdMarkusAfter:
	.string "I came to explore MT.MORTAR,\n"
	.string "but I got separated from my\l"
	.string "partner…\p"
	.string "Did you run into a trainer\n"
	.string "who uses a SEADRA that knows\l"
	.string "WATERFALL?$"
