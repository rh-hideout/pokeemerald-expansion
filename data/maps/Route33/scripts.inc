Route33_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route33_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

Route33_OnTransition: 
	callnative SetTimeBasedEncounters
	end

Route33_EventScript_HikerAnthony::
	trainerbattle_single TRAINER_ANTHONY, Route33_Text_HikerAnthony2Seen, Route33_Text_HikerAnthony2Beaten
	msgbox Route33_Text_HikerAnthony2After, MSGBOX_AUTOCLOSE
	end

Route33_EventScript_Lass::
	lock
	faceplayer
	msgbox Route33_Text_Lass, MSGBOX_DEFAULT
	closemessage
	release
	end

Route33_Text_HikerAnthony2Seen:
	.string "I came through the tunnel,\n"
	.string "but I still have plenty\l"
	.string "of energy left.$"

Route33_Text_HikerAnthony2Beaten:
	.string "Whoa! You've got more zip\n"
	.string "than me!$"

Route33_Text_HikerAnthony2After:
	.string "We HIKERS are at our best\n"
	.string "in the mountains.$"

Route33_Text_HikerAnthonyDunsparce:
	.string "Hey, did you get a DUNSPARCE?\p"
	.string "I caught one too.\p"
	.string "Take a look at it in the light.\n"
	.string "It's got a funny face!$"

Route33_Text_Lass:
	.string "Pant, pant…\p"
	.string "That cave was bigger than\n"
	.string "I'd expected.\p"
	.string "I got too tired exploring\n"
	.string "for MARILL, so I came outside.$"
