.set LOCALID_CINNABAR_BLUE, 1
.set LOCALID_CINNABAR_BLAINE, 12

CinnabarIsland_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, CinnabarIsland_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0
	
CinnabarIsland_OnTransition:
	setflag FLAG_VISITED_CINNABAR_ISLAND
	callnative SetTimeBasedEncounters
	end

CinnabarIsland_EventScript_Blaine::
    lock
    faceplayer
    msgbox CinnabarIsland_Text_Blaine, MSGBOX_DEFAULT
    closemessage
    fadescreenswapbuffers FADE_TO_BLACK
    setflag FLAG_HIDE_CINNABAR_BLAINE
    removeobject LOCALID_CINNABAR_BLAINE
    fadescreenswapbuffers FADE_FROM_BLACK
    clearflag FLAG_HIDE_DOJO_BLAINE
    release
    end

CinnabarIsland_Text_Blaine:
    .string "BLAINE: I'll never give up\n"
	.string "until the day I've rebuilt\l"
	.string "CINNABAR GYM!\p"
	.string "I'll be at the FIGHTING DOJO\n"
	.string "until then.$"



CinnabarIsland_EventScript_Blue::
	lock
	faceplayer
	goto_if_eq VAR_NUM_BADGES, 15, CinnabarIsland_EventScript_BlueActive
	msgbox CinnabarIsland_Text_BlueBefore, MSGBOX_NPC
	release
	end

CinnabarIsland_EventScript_BlueActive::
	msgbox CinnabarIsland_Text_Blue, MSGBOX_NPC
	fadescreenswapbuffers FADE_TO_BLACK
	setflag FLAG_HIDE_CINNABAR_BLUE
	removeobject LOCALID_CINNABAR_BLUE
	clearflag FLAG_HIDE_VIRIDIAN_BLUE
	fadescreenswapbuffers FADE_FROM_BLACK
	release
	end


CinnabarIsland_Text_BlueBefore:
	.string "Who are you?\p"
	.string "Well, it's plain to see that you're\n"
	.string "a trainer…\p"
	.string "My name's BLUE.\p"
	.string "I was once the CHAMPION, although\n"
	.string "it was for only a short time…\p"
	.string "That meddling RED did me in…\p"
	.string "Anyway, what do you want? You want\n"
	.string "to challenge me or something?\p"
	.string "…I hate to say it, but I'm not in\n"
	.string "the mood for a battle now.\p"
	.string "Take a good look around you…\p"
	.string "A volcano erupts, and just like\n"
	.string "that, a whole town disappears.\p"
	.string "We can go on winning and losing in\n"
	.string "POKéMON. But if nature so much as\l"
	.string "twitches, we can lose in a second.\p"
	.string "…\p"
	.string "That's the way it is…\p"
	.string "But, anyway, I'm still a trainer.\p"
	.string "If I see a strong opponent, it\n"
	.string "makes me want to battle.\p"
	.string "If you want to battle me, you'll\n"
	.string "need 15 badges first.\p"
	.string "I'll take you on then.$"

CinnabarIsland_Text_Blue:
	.string "Who are you?\p"
	.string "Well, it's plain to see that you're\n"
	.string "a trainer…\p"
	.string "My name's BLUE.\p"
	.string "I was once the CHAMPION, although\n"
	.string "it was for only a short time…\p"
	.string "That meddling RED did me in…\p"
	.string "Anyway, what do you want? You want\n"
	.string "to challenge me or something?\p"
	.string "…I hate to say it, but I'm not in\n"
	.string "the mood for a battle now.\p"
	.string "Take a good look around you…\p"
	.string "A volcano erupts, and just like\n"
	.string "that, a whole town disappears.\p"
	.string "We can go on winning and losing in\n"
	.string "POKéMON. But if nature so much as\l"
	.string "twitches, we can lose in a second.\p"
	.string "…\p"
	.string "That's the way it is…\p"
	.string "But, anyway, I'm still a trainer.\p"
	.string "If I see a strong opponent, it\n"
	.string "makes me want to battle.\p"
	.string "If you want to battle me, come to\n"
	.string "the VIRIDIAN GYM.\p"
	.string "I'll take you on then.$"

CinnabarIsland_EventScript_Sign::
	msgbox CinnabarIsland_Text_Sign, MSGBOX_SIGN
	end

CinnabarIsland_EventScript_GymSign::
	msgbox CinnabarIsland_Text_GymSign, MSGBOX_SIGN
	end

CinnabarIsland_Text_GymSign:
	.string "There's a notice here…\p"
	.string "CINNABAR GYM has relocated to\n"
	.string "SEAFOAM ISLANDS.\p"
	.string "BLAINE$"

CinnabarIsland_Text_Sign:
	.string "CINNABAR ISLAND\p"
	.string "The Fiery Town of Burning Desire$"

