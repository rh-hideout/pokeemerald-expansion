Route17_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route17_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

Route17_OnTransition:
	callnative SetTimeBasedEncounters
	end

Route17_EventScript_Riley::
	trainerbattle_single TRAINER_RILEY_HNS, Route17_Text_BikerRileySeen, Route17_Text_BikerRileyBeaten, Route17_EventScript_RegisterRiley
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route17_EventScript_RematchRiley
	msgbox Route17_Text_BikerRileyAfterBattle, MSGBOX_AUTOCLOSE
	end

Route17_EventScript_RegisterRiley::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route17_Text_RileyRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_RILEY_HNS
	release
	end

Route17_EventScript_RematchRiley::
	trainerbattle_rematch TRAINER_RILEY_HNS, Route17_Text_RileyRematchIntro, Route17_Text_RileyRematchDefeat
	msgbox Route17_Text_RileyPostRematch, MSGBOX_AUTOCLOSE
	end

Route17_EventScript_Joel::
	trainerbattle_single TRAINER_JOEL_HNS, Route17_Text_BikerJoelSeen, Route17_Text_BikerJoelBeaten, Route17_EventScript_RegisterJoel
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route17_EventScript_RematchJoel
	msgbox Route17_Text_BikerJoelAfterBattle, MSGBOX_AUTOCLOSE
	end

Route17_EventScript_RegisterJoel::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route17_Text_JoelRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_JOEL_HNS
	release
	end

Route17_EventScript_RematchJoel::
	trainerbattle_rematch TRAINER_JOEL_HNS, Route17_Text_JoelRematchIntro, Route17_Text_JoelRematchDefeat
	msgbox Route17_Text_JoelPostRematch, MSGBOX_AUTOCLOSE
	end

Route17_EventScript_Glenn::
	trainerbattle_single TRAINER_GLENN_HNS, Route17_Text_BikerGlennSeen, Route17_Text_BikerGlennBeaten
	msgbox Route17_Text_BikerGlennAfterBattle, MSGBOX_AUTOCLOSE
	end

Route17_EventScript_Charles::
	trainerbattle_single TRAINER_CHARLES_HNS, Route17_Text_BikerCharlesSeen, Route17_Text_BikerCharlesBeaten, Route17_EventScript_RegisterCharles
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route17_EventScript_RematchCharles
	msgbox Route17_Text_BikerCharlesAfterBattle, MSGBOX_AUTOCLOSE
	end

Route17_EventScript_RegisterCharles::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route17_Text_CharlesRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_CHARLES_HNS
	release
	end

Route17_EventScript_RematchCharles::
	trainerbattle_rematch TRAINER_CHARLES_HNS, Route17_Text_CharlesRematchIntro, Route17_Text_CharlesRematchDefeat
	msgbox Route17_Text_CharlesPostRematch, MSGBOX_AUTOCLOSE
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

Route17_Text_RileyRegister:
	.string "Not bad for a JOHTO kid!$"

Route17_Text_RileyRematchIntro:
	.string "JOHTO punks can only win once!$"

Route17_Text_RileyRematchDefeat:
	.string "I got kicked...$"

Route17_Text_RileyPostRematch:
	.string "Maybe I should train in JOHTO\n"
	.string "after all.$"

Route17_Text_JoelRegister:
	.string "You're pretty cool after all!\n"
	.string "Let's trade numbers!$"

Route17_Text_JoelRematchIntro:
	.string "Let's see who's cooler now!$"

Route17_Text_JoelRematchDefeat:
	.string "Still not cool enough…$"

Route17_Text_JoelPostRematch:
	.string "I'll keep training to be as cool\n"
	.string "as you, kid!$"

Route17_Text_CharlesRegister:
	.string "You're a heartbreaker like me, kid!\n"
	.string "Give me your number!$"

Route17_Text_CharlesRematchIntro:
	.string "I'm not just a highway star,\n"
	.string "I'm a heartbreaker!$"

Route17_Text_CharlesRematchDefeat:
	.string "Crashed and burned again!$"

Route17_Text_CharlesPostRematch:
	.string "I met a trainer like you in UNOVA.\n"
	.string "Don't crash out!$"

