RuinsOfAlph_Outside_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, RuinsOfAlph_Outside_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

RuinsOfAlph_Outside_OnTransition: 
	callnative SetTimeBasedEncounters
	end	

RuinsOfAlph_Outside_EventScript_Quagsire::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_QUAGSIRE, CRY_MODE_NORMAL
	msgbox RuinsOfAlph_Outside_Text_Quagsire, MSGBOX_DEFAULT
	waitmoncry
	release
	end

RuinsOfAlph_Outside_Text_Quagsire:
	.string "QUAGSIRE: Quag Quag$"

RuinsOfAlph_Outside_EventScript_Stan::
	trainerbattle_single TRAINER_STAN, RuinsOfAlph_Outside_Text_SuperNerdStan_Seen, RuinsOfAlph_Outside_Text_SuperNerdStan_Beaten
	msgbox RuinsOfAlph_Outside_Text_SuperNerdStan_After, MSGBOX_AUTOCLOSE
	end

RuinsOfAlph_Outside_EventScript_Nathan::
	trainerbattle_single TRAINER_NATHAN, RuinsOfAlph_Outside_Text_PsychicNathan_Seen, RuinsOfAlph_Outside_Text_PsychicNathan_Beaten
	msgbox RuinsOfAlph_Outside_Text_PsychicNathan_After, MSGBOX_AUTOCLOSE
	end

RuinsOfAlph_Outside_EventScript_Youngster1::
	lock
	faceplayer
	msgbox RuinsOfAlph_Outside_Text_Youngster1, MSGBOX_DEFAULT
	closemessage
	release
	end

RuinsOfAlph_Outside_EventScript_Youngster2::
	lock
	faceplayer
	msgbox RuinsOfAlph_Outside_Text_Youngster2, MSGBOX_DEFAULT
	closemessage
	release
	end

RuinsOfAlph_Outside_EventScript_Fisher1::
	lock
	faceplayer
	msgbox RuinsOfAlph_Outside_Text_Fisher1, MSGBOX_DEFAULT
	closemessage
	release
	end

RuinsOfAlph_Outside_EventScript_Fisher2::
	lock
	faceplayer
	msgbox RuinsOfAlph_Outside_Text_Fisher2, MSGBOX_DEFAULT
	closemessage
	release
	end

RuinsOfAlph_Outside_EventScript_Sign1::
	lock
	msgbox RuinsOfAlph_Outside_Text_MainSign, MSGBOX_SIGN
	closemessage
	release
	end

RuinsOfAlph_Outside_EventScript_Sign2::
	lock
	msgbox RuinsOfAlph_Outside_Text_ResearchSign, MSGBOX_SIGN
	closemessage
	release
	end

RuinsOfAlph_Outside_EventScript_Sign3::
	lock
	msgbox RuinsOfAlph_Outside_Text_MysteryChamberSign, MSGBOX_SIGN
	closemessage
	release
	end

RuinsOfAlph_Outside_Text_Scientist:
	.string "Hm? That's a POKéDEX, isn't it?\n"
	.string "May I see it?\p"
	.string "There are so many kinds of\n"
	.string "POKéMON.\p"
	.string "Hm? What's this?\p"
	.string "What is this POKéMON?\p"
	.string "It looks like the strange\n"
	.string "writing on the walls of the\p"
	.string "RUINS.\p"
	.string "If those drawings are really\n"
	.string "POKéMON, there should be many\n"
	.string "more.\p"
	.string "I know! Let me upgrade your\n"
	.string "POKéDEX. Follow me.$"

RuinsOfAlph_Outside_Text_SuperNerdStan_Seen:
	.string "What do you want? I'm studying--\n"
	.string "don't disturb me!$"

RuinsOfAlph_Outside_Text_SuperNerdStan_Beaten:
	.string "Sorry…\n"
	.string "I'm frustrated by our lack of\p"
	.string "real understanding…$"

RuinsOfAlph_Outside_Text_SuperNerdStan_After:
	.string "The RUINS are from about 1500\n"
	.string "years ago.\p"
	.string "Nobody knows who built them.\p"
	.string "It's also not known if the POKéMON\n"
	.string "statues have any meaning.\p"
	.string "It's all one big mystery…$"

RuinsOfAlph_Outside_Text_PsychicNathan_Seen:
	.string "Hmmm… This is a strange place.$"

RuinsOfAlph_Outside_Text_PsychicNathan_Beaten:
	.string "…$"

RuinsOfAlph_Outside_Text_PsychicNathan_After:
	.string "I like thinking here.$"

RuinsOfAlph_Outside_Text_MysteryChamberSign:
	.string "MYSTERY STONE PANEL CHAMBER$"

RuinsOfAlph_Outside_Text_MainSign:
	.string "RUINS OF ALPH\n"
	.string "VISITORS WELCOME$"

RuinsOfAlph_Outside_Text_ResearchSign:
	.string "RUINS OF ALPH RESEARCH CENTER\p"
	.string "THE AUTHORITY ON THE\n"
	.string "RUINS OF ALPH$"

RuinsOfAlph_Outside_Text_Fisher1:
	.string "While exploring the RUINS, we\n"
	.string "suddenly noticed an odd presence.\p"
	.string "We all got scared and ran away.\n"
	.string "You should be careful too.$"

RuinsOfAlph_Outside_Text_Fisher2:
	.string "The RUINS hide a huge secret!\p"
	.string "…I think…$"

RuinsOfAlph_Outside_Text_Youngster1:
	.string "There are many kinds of UNOWN, so\n"
	.string "we use them for our secret codes.$"

RuinsOfAlph_Outside_Text_Youngster2:
	.string "A… H… E… A… D… Hmm…\p"
	.string "What?\p"
	.string "I'm decoding this message!$"
