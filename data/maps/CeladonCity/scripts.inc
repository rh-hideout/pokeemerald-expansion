.set LOCALID_CELADON_ERIKA, 15

CeladonCity_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, CeladonCity_EventScript_CityEnter
	.byte 0

CeladonCity_EventScript_CityEnter::
	setflag FLAG_VISITED_CELADON_CITY
	end

CeladonCity_EventScript_Erika::
    lock
    faceplayer
    msgbox CeladonCity_Text_Erika, MSGBOX_DEFAULT
    closemessage
    fadescreenswapbuffers FADE_TO_BLACK
    setflag FLAG_HIDE_FOUNTAIN_ERIKA
    removeobject LOCALID_CELADON_ERIKA
    fadescreenswapbuffers FADE_FROM_BLACK
    clearflag FLAG_HIDE_DOJO_ERIKA
    release
    end

CeladonCity_Text_Erika:
    .string "Oh, {PLAYER}.\n"
	.string "Isn't the fountain lovely today?\p"
	.string "If you wish for another battle,\n"
	.string "I'll be at the FIGHTING DOJO.$"

CeladonCity_EventScript_Fatman::
	msgbox CeladonCity_Text_Fisher, MSGBOX_NPC
	end
CeladonCity_EventScript_Poliwrath::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_POLIWRATH, CRY_MODE_NORMAL
	msgbox CeladonCity_Text_Poliwrath, MSGBOX_DEFAULT
	waitmoncry
	release
	end

CeladonCity_EventScript_Teacher1::
	msgbox CeladonCity_Text_Teacher1, MSGBOX_NPC
	end

CeladonCity_EventScript_GrimerGramps::
	msgbox CeladonCity_Text_Gramps1, MSGBOX_NPC
	end

CeladonCity_EventScript_CreepGramps::
	msgbox CeladonCity_Text_Gramps2, MSGBOX_NPC
	end

CeladonCity_EventScript_Youngster::
	msgbox CeladonCity_Text_Youngster1, MSGBOX_NPC
	end

CeladonCity_EventScript_Youngster2::
	msgbox CeladonCity_Text_Youngster2, MSGBOX_NPC
	end

CeladonCity_EventScript_Teacher2::
	msgbox CeladonCity_Text_Teacher2, MSGBOX_NPC
	end

CeladonCity_EventScript_Lass::
	msgbox CeladonCity_Text_Lass, MSGBOX_NPC
	end

CeladonCity_Text_Fisher:
	.string "This POLIWRATH is my partner.\p"
	.string "I wonder if it'll ever evolve\n"
	.string "into a frog POKéMON.$"

CeladonCity_Text_Poliwrath:
	.string "POLIWRATH: Croak!$"

CeladonCity_Text_Teacher1:
	.string "I lost at the slot machines again…\p"
	.string "We girls also play the slots now.\p"
	.string "You should check them out too.$"

CeladonCity_Text_Gramps1:
	.string "GRIMER have been appearing lately.\p"
	.string "See that pond out in front of the\n"
	.string "house? GRIMER live there now.\p"
	.string "Where did they come from? This is\n"
	.string "a serious problem…$"

CeladonCity_Text_Gramps2:
	.string "Nihihi! This GYM is great! Only\n"
	.string "girls are allowed here!$"

CeladonCity_Text_Youngster1:
	.string "Want to know a secret?\p"
	.string "CELADON MANSION has a hidden back\n"
	.string "door.$"

CeladonCity_Text_Youngster2:
	.string "They're holding an eating contest\n"
	.string "at the restaurant.\p"
	.string "Just watching them go at it makes\n"
	.string "me feel bloated…$"

CeladonCity_Text_Teacher2:
	.string "CELADON DEPT.STORE has the biggest\n"
	.string "and best selection of merchandise.\p"
	.string "If you can't get it there, you\n"
	.string "can't get it anywhere.\p"
	.string "Gee… I sound like a sales clerk.$"

CeladonCity_Text_Lass:
	.string "Looking at the ground while I was\n"
	.string "walking made me dizzy.$"

CeladonCity_EventScript_CitySign::
	msgbox CeladonCity_Text_Sign, MSGBOX_SIGN
	end

CeladonCity_EventScript_GymSign::
	msgbox CeladonGym_Text_Sign, MSGBOX_SIGN
	end

CeladonCity_EventScript_StoreSign::
	msgbox CeladonCity_Text_DeptStoreSign, MSGBOX_SIGN
	end

CeladonCity_EventScript_MansionSign::
	msgbox CeladonCity_Text_MansionSign, MSGBOX_SIGN
	end

CeladonCity_EventScript_GameCornerSign::
	msgbox CeladonCity_Text_GameCornerSign, MSGBOX_SIGN
	end

CeladonCity_EventScript_TrainerTips::
	msgbox CeladonCity_Text_TrainerTips, MSGBOX_SIGN
	end

CeladonCity_Text_Sign:
	.string "CELADON CITY\p"
	.string "The City of Rainbow Dreams$"

CeladonGym_Text_Sign:
	.string "CELADON CITY POKéMON GYM LEADER:\n"
	.string "ERIKA\p"
	.string "The Nature-Loving Princess$"

CeladonCity_Text_DeptStoreSign:
	.string "Find What You Need at CELADON\n"
	.string "DEPT.STORE!$"

CeladonCity_Text_MansionSign:
	.string "CELADON MANSION$"

CeladonCity_Text_GameCornerSign:
	.string "The Playground for Everybody--\n"
	.string "CELADON GAME CORNER$"

CeladonCity_Text_TrainerTips:
	.string "TRAINER TIPS\p"
	.string "GUARD SPEC. protects POKéMON\n"
	.string "against SPECIAL attacks such as\n"
	.string "fire and water.\p"
	.string "Get your items at CELADON DEPT.\n"
	.string "STORE!$"
