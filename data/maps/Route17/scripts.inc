Route17_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route17_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

Route17_OnTransition:
	callnative SetTimeBasedEncounters
	end

Route17_EventScript_Riley::
	trainerbattle_single TRAINER_RILEY Route17_Text_BikerRileySeen, Route17_Text_BikerRileyBeaten
	msgbox Route17_Text_BikerRileyAfterBattle, MSGBOX_AUTOCLOSE
	end

Route17_EventScript_Joel::
	trainerbattle_single TRAINER_JOEL Route17_Text_BikerJoelSeen, Route17_Text_BikerJoelBeaten
	msgbox Route17_Text_BikerJoelAfterBattle, MSGBOX_AUTOCLOSE
	end

Route17_EventScript_Glenn::
	trainerbattle_single TRAINER_GLENN Route17_Text_BikerGlennSeen, Route17_Text_BikerGlennBeaten
	msgbox Route17_Text_BikerGlennAfterBattle, MSGBOX_AUTOCLOSE
	end

Route17_EventScript_Charles::
	trainerbattle_single TRAINER_CHARLES Route17_Text_BikerCharlesSeen, Route17_Text_BikerCharlesBeaten
	msgbox Route17_Text_BikerCharlesAfterBattle, MSGBOX_AUTOCLOSE
	end

Route17_Text_BikerRileySeen:
	.string "Hey, you! You're from JOHTO, huh?$"

Route17_Text_BikerRileyBeaten:
	.string "Whoa, you kick!$"

Route17_Text_BikerRileyAfterBattle:
	.string "Don't get cocky, you JOHTO punk!$"

Route17_Text_BikerJoelSeen:
	.string "Wow. That's a cool BICYCLE!$"

Route17_Text_BikerJoelBeaten:
	.string "But you don't just look cool…$"

Route17_Text_BikerJoelAfterBattle:
	.string "I look cool, but I'm weak, so I'm\n"
	.string "not really cool.\p"
	.string "I have to train harder…$"

Route17_Text_BikerGlennSeen:
	.string "Hey! Want to have a speed battle?$"

Route17_Text_BikerGlennBeaten:
	.string "Yikes! You've got awesome torque!$"

Route17_Text_BikerGlennAfterBattle:
	.string "Hands-free riding is considered\n"
	.string "cool on CYCLING ROAD.$"

Route17_Text_BikerCharlesSeen:
	.string "We're fearless highway stars!$"

Route17_Text_BikerCharlesBeaten:
	.string "Arrrgh! Crash and burn!$"

Route17_Text_BikerCharlesAfterBattle:
	.string "Reckless driving causes accidents!\n"
	.string "Take it easy!$"

