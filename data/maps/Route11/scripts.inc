Route11_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route11_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

Route11_OnTransition:
	callnative SetTimeBasedEncounters
	end

Route11_EventScript_Owen::
	trainerbattle_single TRAINER_OWEN Route11_Text_YoungsterOwenSeen, Route11_Text_YoungsterOwenBeaten
	msgbox Route11_Text_YoungsterOwenAfterBattle, MSGBOX_AUTOCLOSE
	end

Route11_EventScript_Jason::
	trainerbattle_single TRAINER_JASON Route11_Text_YoungsterJasonSeen, Route11_Text_YoungsterJasonBeaten
	msgbox Route11_Text_YoungsterJasonAfterBattle, MSGBOX_AUTOCLOSE
	end

Route11_EventScript_Herman::
	trainerbattle_single TRAINER_HERMAN Route11_Text_PsychicHermanSeen, Route11_Text_PsychicHermanBeaten
	msgbox Route11_Text_PsychicHermanAfterBattle, MSGBOX_AUTOCLOSE
	end

Route11_EventScript_Fidel::
	trainerbattle_single TRAINER_FIDEL Route11_Text_PsychicFidelSeen, Route11_Text_PsychicFidelBeaten
	msgbox Route11_Text_PsychicFidelAfterBattle, MSGBOX_AUTOCLOSE
	end


Route11_EventScript_Engineer::
	msgbox Route11_Text_Engineer, MSGBOX_NPC
	end

Route11_Text_Engineer:
	.string "I saw a strange POKéMON climbing\n"
	.string "in the trees, but it didn't\l"
	.string "look like MANKEY...$"

Route11_Text_YoungsterOwenSeen:
	.string "There's no cheating in POKéMON.\p"
	.string "Let's keep it fair and square!$"

Route11_Text_YoungsterOwenBeaten:
	.string "Huh? How did this happen?$"

Route11_Text_YoungsterOwenAfterBattle:
	.string "I fought fair and square with\n"
	.string "honor.\p"
	.string "I don't regret this at all.$"

Route11_Text_YoungsterJasonSeen:
	.string "It itches and tickles a bit when\n"
	.string "I wear shorts in the grass.$"

Route11_Text_YoungsterJasonBeaten:
	.string "Aiyaaah! I got stomped!$"

Route11_Text_YoungsterJasonAfterBattle:
	.string "I'm going to catch more POKéMON in\n"
	.string "the grass.$"

Route11_Text_PsychicHermanSeen:
	.string "…$"

Route11_Text_PsychicHermanBeaten:
	.string "…$"

Route11_Text_PsychicHermanAfterBattle:
	.string "…\p"
	.string "I lost while I had my eyes closed…$"

Route11_Text_PsychicFidelSeen:
	.string "I can see it…\p"
	.string "Everything to see about you…$"

Route11_Text_PsychicFidelBeaten:
	.string "I couldn't foresee your power…$"

Route11_Text_PsychicFidelAfterBattle:
	.string "Strength in conviction…\p"
	.string "You're strong because you believe\n"
	.string "in your POKéMON.$"

Route11_Text_Sign:
	.string "ROUTE 11$"

