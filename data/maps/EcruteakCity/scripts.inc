.set LOCALID_ECRUTEAK_GRAMPS, 4
.set LOCALID_ECRUTEK_SILVER, 33

EcruteakCity_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, EcruteakCity_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

EcruteakCity_OnTransition::
	callnative SetTimeBasedEncounters
	end

EcruteakCity_Test_Lugia::
	setvar VAR_LUGIA_OR_HOOH, 1
	end
EcruteakCity_Test_League::
	setvar VAR_COMPLETED_HO_OH, 4
	setvar VAR_COMPLETED_LUGIA, 4
	end


EcruteakCity_EventScript_Trigger::
	@flagheap
	clearflag FLAG_RELEASED_BEASTS
	clearflag FLAG_AMPHAROS_HEALED
	clearflag FLAG_HIDE_ECRUTEAK_BILL
	clearflag FLAG_DEFEATED_HO_OH
	clearflag FLAG_CAUGHT_HO_OH
	clearflag FLAG_DEFEATED_LUGIA
	clearflag FLAG_CAUGHT_LUGIA
	clearflag FLAG_HIDE_ECRUTEAK_ROCKET
	clearflag FLAG_HIDE_BURNED_TOWER_NPCS  
	clearflag FLAG_HIDE_BURNED_TOWER_BEASTS
	clearflag FLAG_HIDE_BURNED_TOWER_B1F_EUSINE
	clearflag FLAG_HIDE_ECRUTEAK_CITY_SAGE
	clearflag FLAG_CAUGHT_ENTEI
	clearflag FLAG_CAUGHT_RAIKOU
	clearflag FLAG_GOT_TM_SNATCH
	clearflag FLAG_HIDE_ROUTE42_SUICUNE
	clearflag FLAG_GOT_TYROGUE
	clearflag FLAG_BEAT_KIYO
	clearflag FLAG_ENABLE_BAOBA_MATCH_CALL
	clearflag FLAG_HIDE_ECRUTEAK_CITY_THEATER_NPCS
	clearflag FLAG_HIDE_ECRUTEAK_CITY_THEATER_ZUKI
	clearflag FLAG_HIDE_TINTOWER_GUARD
	clearflag FLAG_HIDE_WHIRL_ISLANDS_TENTACRUEL
	clearflag FLAG_HIDE_LUGIA
	clearflag FLAG_HIDE_HO_OH

	setflag FLAG_VISITED_ECRUTEAK_CITY
	setflag FLAG_HIDE_ROUTE42_EUSINE

	setflag FLAG_HIDE_TIN_TOWER_KIMONO_GIRLS
	setflag FLAG_HIDE_WHIRL_ISLANDS_KIMONO_GIRLS
	setflag FLAG_HIDE_ECRUTEAK_CITY_THEATER_KIMONOS
	setflag FLAG_HIDE_ROUTE39_SHADOW
	setflag FLAG_HIDE_ECRUTEAK_SILVER
	setvar VAR_COMPLETED_HO_OH, 0
	setvar VAR_COMPLETED_LUGIA, 0
	setvar VAR_ECRUTEAK_CITY_THEATER, 0 
	setvar VAR_ECRUTEAK_CITY_STATE, 1
	end

EcruteakCity_Trigger_Silver::
	lockall
	opendoor 39, 40
	waitdooranim
	delay 10
	clearflag FLAG_HIDE_ECRUTEAK_SILVER
	addobject LOCALID_ECRUTEK_SILVER
	playbgm MUS_HG_ENCOUNTER_RIVAL, TRUE
	playse SE_BANG
	applymovement LOCALID_ECRUTEK_SILVER, EcruteakCity_Movement_Silver1
	applymovement OBJ_EVENT_ID_PLAYER, EcruteakCity_Movement_Silver1
	message EcruteakCity_Text_Silver1
	
	waitmovement OBJ_EVENT_ID_PLAYER
	waitmovement LOCALID_ECRUTEK_SILVER
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	closedoor 39, 40
	waitdooranim
	msgbox EcruteakCity_Text_Silver2, MSGBOX_DEFAULT
	closemessage
	playse SE_PIN
	applymovement LOCALID_ECRUTEK_SILVER, Common_Movement_ExclamationMark
	delay 60
	turnobject LOCALID_ECRUTEK_SILVER, DIR_SOUTH
	msgbox EcruteakCity_Text_Silver3, MSGBOX_DEFAULT
	closemessage

	applymovement LOCALID_ECRUTEK_SILVER, EcruteakCity_Movement_Silver2
	waitmovement LOCALID_ECRUTEK_SILVER


	setflag FLAG_HIDE_ECRUTEAK_SILVER
	removeobject LOCALID_ECRUTEK_SILVER
	fadedefaultbgm

	setvar VAR_ECRUTEAK_CITY_THEATER, 5
	releaseall
	end

EcruteakCity_Movement_Silver1:
	delay_16
	lock_facing_direction
	walk_down
	unlock_facing_direction
	step_end

EcruteakCity_Movement_Silver2:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

EcruteakCity_Text_Silver1:
	.string "THUD!!$"

EcruteakCity_Text_Silver2:
	.string "{RIVAL}: How...? How is this\n"
	.string "possible? How can I lose to mere\l"
	.string "KIMONO GIRLS...?$"

EcruteakCity_Text_Silver3:
	.string "{RIVAL}: You were watching me,\n"
	.string "{PLAYER}...\p"
	.string "Yeah, that's right!\p"
	.string "I never thought defeating five\n"
	.string "KIMONO GIRLS would be so hard...\p"
	.string "I got beaten to a pulp...\p"
	.string "...\p"
	.string "You must have come here for the\n"
	.string "same reason, right?\p"
	.string "Don't get cocky just because you\n"
	.string "defeated TEAM ROCKET!\p"
	.string "These KIMONO GIRLS are insanely\n"
	.string "strong.\p"
	.string "See if you can defeat them.\p"
	.string "But I'm not going back, I don't\n"
	.string "want to see you win.$"

EcruteakCity_EventScript_Gramps::
	lock
	faceplayer
	msgbox EcruteakCity_Text_Gramps1, MSGBOX_DEFAULT
	closemessage
	release
	end
		
EcruteakCity_EventScript_Lass::
	lock
	faceplayer
	msgbox EcruteakCity_Text_Lass1, MSGBOX_DEFAULT
	closemessage
	release
	end

EcruteakCity_EventScript_Girl::
	lock
	faceplayer
	goto_if_set FLAG_RELEASED_BEASTS, EcruteakCity_EventScript_Girl2
	msgbox EcruteakCity_Text_Lass2, MSGBOX_DEFAULT
	closemessage
	release
	end

EcruteakCity_EventScript_Girl2::
	msgbox EcruteakCity_Text_Lass2_ReleasedBeasts, MSGBOX_DEFAULT
	closemessage
	release
	end

EcruteakCity_EventScrip_Man::
	lock
	faceplayer
	goto_if_set FLAG_AMPHAROS_HEALED, EcruteakCity_EventScrip_Man2
	msgbox EcruteakCity_Text_Fisher, MSGBOX_DEFAULT
	closemessage
	release
	end

EcruteakCity_EventScrip_Man2::
	msgbox EcruteakCity_Text_Fisher_JasmineReturned, MSGBOX_DEFAULT
	closemessage
	release
	end

EcruteakCity_EventScript_Youngster::
	lock
	faceplayer
	msgbox EcruteakCity_Text_Youngster, MSGBOX_DEFAULT
	closemessage
	release
	end

EcruteakCity_EventScript_SageRight::
	lock
	faceplayer
	msgbox EcruteakCity_Text_Gramps2, MSGBOX_DEFAULT
	closemessage
	release
	end

EcruteakCity_EventScript_SageTower::
	lock
	faceplayer
	msgbox EcruteakCity_Text_Gramps3, MSGBOX_DEFAULT
	closemessage
	release
	end

EcruteakCity_EventScript_SageGym::
	lock
	faceplayer
	msgbox EcruteakCity_Text_SageGym, MSGBOX_DEFAULT
	closemessage
	release
	end

EcruteakCity_EventScript_TheaterSign::
	lock
	msgbox EcruteakCity_Text_DanceTheaterSign, MSGBOX_SIGN
	closemessage
	release
	end	

EcruteakCity_EventScript_OfficeSign::
	lock
	msgbox EcruteakCity_Text_OfficeSign, MSGBOX_SIGN
	closemessage
	release
	end	

EcruteakCity_EventScript_BurnedSign::
	lock
	msgbox EcruteakCity_Text_BurnedTowerSign, MSGBOX_SIGN
	closemessage
	release
	end	

EcruteakCity_EventScript_CitySign::
	lock
	msgbox EcruteakCity_Text_Sign, MSGBOX_SIGN
	closemessage
	release
	end	

EcruteakCity_EventScript_GymSign::
	lock
	msgbox EcruteakCity_Text_GymSign, MSGBOX_SIGN
	closemessage
	release
	end

EcruteakCity_EventScript_Eevee::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_EEVEE, CRY_MODE_NORMAL
	msgbox EcruteakCity_Text_Eevee, MSGBOX_DEFAULT
	waitmoncry
	release
	end

EcruteakCity_EventScript_Vulpix::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_VULPIX, CRY_MODE_NORMAL
	msgbox EcruteakCity_Text_Vulpix, MSGBOX_DEFAULT
	waitmoncry
	release
	end

EcruteakCity_EventScript_Item_RareCandy::
	finditem ITEM_RARE_CANDY
	end

EcruteakCity_Text_Eevee:
	.string "EEVEE: Veee!$"

EcruteakCity_Text_Vulpix:
	.string "VULPIX: Vullll Pix!$"


EcruteakCity_Text_UnusedMissingDaughter:
	.string "Oh, no. Oh, no…\p"
	.string "My daughter is missing.\p"
	.string "No… She couldn't have gone to the\n"
	.string "BURNED TOWER.\p"
	.string "I told her not to go near it…\p"
	.string "People seem to disappear there…\p"
	.string "Oh, what should I do…?$"

EcruteakCity_Text_Gramps1:
	.string "ECRUTEAK used to have two towers:\n"
	.string "one each in the east and west.$"

EcruteakCity_Text_Gramps2:
	.string "Ah, child. Have you learned to\n"
	.string "dance like the KIMONO GIRLS?\p"
	.string "If you go to their DANCE THEATER,\n"
	.string "an odd old man will give you\l"
	.string "something nice, I hear.$"

EcruteakCity_Text_Lass1:
	.string "I'm going to practice at the DANCE\n"
	.string "THEATER. Care to join me?$"

EcruteakCity_Text_Lass2:
	.string "The tower that used to be here…\p"
	.string "My grandma told me it used to be\n"
	.string "much taller.\p"
	.string "I hear there are ghosts in it now.$"

EcruteakCity_Text_Lass2_ReleasedBeasts:
	.string "Three big POKéMON ran off in different\n"
	.string "directions. What were they?$"

EcruteakCity_Text_Fisher:
	.string "I heard a rumor about OLIVINE\n"
	.string "LIGHTHOUSE.\p"
	.string "The POKéMON that serves as the\n"
	.string "beacon fell ill. Sounds like they\l"
	.string "are in trouble.$"

EcruteakCity_Text_Fisher_JasmineReturned:
	.string "The POKéMON at OLIVINE LIGHTHOUSE\n"
	.string "has been cured.\p"
	.string "Boats can safely sail out to sea at\n"
	.string "night again.$"

EcruteakCity_Text_Youngster:
	.string "I hear POKéMON are rampaging at the\n"
	.string "LAKE OF RAGE. I'd like to see that.$"

EcruteakCity_Text_Gramps3:
	.string "In the distant past…\p"
	.string "This tower burned in a fire. Three\n"
	.string "nameless POKéMON perished in it.\p"
	.string "A rainbow-colored POKéMON descended\n"
	.string "from the sky and resurrected them…\p"
	.string "It's a legend that has been passed\n"
	.string "down by ECRUTEAK GYM LEADERS.\p"
	.string "Me?\p"
	.string "I was a trainer way back when.\n"
	.string "Hohoho!$"

EcruteakCity_Text_SageGym:
	.string "Gym Leader MORTY is not here right\n"
	.string "now. You may find him at the\l"
	.string "BURNED TOWER.$"

EcruteakCity_Text_Sign:
	.string "ECRUTEAK CITY\n"
	.string "A Historical City\p"
	.string "Where the Past Meets the Present$"

EcruteakCity_Text_TinTowerSign:
	.string "TIN TOWER\p"
	.string "A legendary POKéMON is said to\n"
	.string "roost here.$"

EcruteakCity_Text_OfficeSign:
	.string "Barrier Station to TIN TOWER\p"
	.string "No Trespassing by the Unworthy.$"

EcruteakCity_Text_GymSign:
	.string "ECRUTEAK CITY POKéMON GYM\n"
	.string "LEADER: MORTY\p"
	.string "The Mystic Seer of the Future$"

EcruteakCity_Text_DanceTheaterSign:
	.string "ECRUTEAK DANCE THEATER$"

EcruteakCity_Text_BurnedTowerSign:
	.string "BURNED TOWER\p"
	.string "It was destroyed by a mysterious\n"
	.string "fire.\p"
	.string "Please stay away, as it is unsafe.$"
