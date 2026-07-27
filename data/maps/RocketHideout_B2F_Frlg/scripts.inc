RocketHideout_B2F_Frlg_MapScripts::
	.byte 0

RocketHideout_B2F_EventScript_Grunt::
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_13, RocketHideout_B2F_Text_GruntIntro, RocketHideout_B2F_Text_GruntDefeat
	msgbox RocketHideout_B2F_Text_GruntPostBattle, MSGBOX_AUTOCLOSE
	end

RocketHideout_B2F_Text_GruntIntro::
	.string "[Boss] said you can see ghosts with\n"
	.string "the [Silph Scope].$"

RocketHideout_B2F_Text_GruntDefeat::
	.string "I surrender!$"

RocketHideout_B2F_Text_GruntPostBattle::
	.string "The [Team Rocket] HQ has four\n"
	.string "underground floors.\p"
	.string "Think you can reach the [Boss]?$"
