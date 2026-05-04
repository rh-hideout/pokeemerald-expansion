GoldenrodCity_RadioTower_2F_MapScripts::
	.byte 0

GoldenrodRaidoTower2_EventScript_Grunt3::
	trainerbattle_single TRAINER_GRUNT_3 GoldenrodCity_RadioTower_2F_Text_GruntM4Seen, GoldenrodCity_RadioTower_2F_Text_GruntM4Beaten
	msgbox GoldenrodCity_RadioTower_2F_Text_GruntM4After, MSGBOX_AUTOCLOSE
	end
GoldenrodRaidoTower2_EventScript_Grunt4::
	trainerbattle_single TRAINER_GRUNT_4 GoldenrodCity_RadioTower_2F_Text_GruntM5Seen, GoldenrodCity_RadioTower_2F_Text_GruntM5Beaten
	msgbox GoldenrodCity_RadioTower_2F_Text_GruntM5After, MSGBOX_AUTOCLOSE
	end
GoldenrodRaidoTower2_EventScript_Grunt5::
	trainerbattle_single TRAINER_GRUNT_5 GoldenrodCity_RadioTower_2F_Text_GruntM6Seen, GoldenrodCity_RadioTower_2F_Text_GruntM6Beaten
	msgbox GoldenrodCity_RadioTower_2F_Text_GruntM6After, MSGBOX_AUTOCLOSE
	end
GoldenrodRaidoTower2_EventScript_GruntF2::
	trainerbattle_single TRAINER_GRUNT_26 GoldenrodCity_RadioTower_2F_Text_GruntF2Seen, GoldenrodCity_RadioTower_2F_Text_GruntF2Beaten
	msgbox GoldenrodCity_RadioTower_2F_Text_GruntF2After, MSGBOX_AUTOCLOSE
	end

GoldenrodCity_RadioTower_2F_EventScript_Sign1::
	lock
	msgbox GoldenrodCity_RadioTower_2F_Text_SalesSign, MSGBOX_SIGN
	closemessage
	release
	end

GoldenrodCity_RadioTower_2F_EventScript_Sign2::
	lock
	msgbox GoldenrodCity_RadioTower_2F_Text_OakTalkSign, MSGBOX_SIGN
	closemessage
	release
	end

GoldenrodCity_RadioTower_2F_EventScript_Boy::
	lock
	faceplayer
	msgbox GoldenrodCity_RadioTower_2F_Text_SuperNerd, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_RadioTower_2F_EventScript_Policeman::
	lock
	faceplayer
	msgbox GoldenrodCity_RadioTower_2F_Text_Policeman, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_RadioTower_2F_EventScript_Buena::
	lock
	faceplayer
	goto_if_eq VAR_GOLDENROD_CITY_STATE, 6, GoldenrodCity_RadioTower_2F_EventScript_Buena2
	goto_if_eq VAR_GOLDENROD_CITY_STATE, 7, GoldenrodCity_RadioTower_2F_EventScript_Buena2
	goto_if_eq VAR_GOLDENROD_CITY_STATE, 8, GoldenrodCity_RadioTower_2F_EventScript_Buena2
	goto_if_eq VAR_GOLDENROD_CITY_STATE, 9, GoldenrodCity_RadioTower_2F_EventScript_Buena2
	msgbox GoldenrodCity_RadioTower_2F_Text_BuenaShowPromo, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_RadioTower_2F_EventScript_Buena2::
	msgbox RadioTower2FBuenaPasswordIsHelpText, MSGBOX_DEFAULT
	closemessage
	release
	end


GoldenrodCity_RadioTower_2F_EventScript_Teacher::
	lock
	faceplayer
	goto_if_eq VAR_GOLDENROD_CITY_STATE, 6, GoldenrodCity_RadioTower_2F_EventScript_Teacher2
	goto_if_eq VAR_GOLDENROD_CITY_STATE, 7, GoldenrodCity_RadioTower_2F_EventScript_Teacher2 
	goto_if_eq VAR_GOLDENROD_CITY_STATE, 8, GoldenrodCity_RadioTower_2F_EventScript_Teacher2 
	goto_if_eq VAR_GOLDENROD_CITY_STATE, 9, GoldenrodCity_RadioTower_2F_EventScript_Teacher2 
	msgbox GoldenrodCity_RadioTower_2F_Text_Teacher, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_RadioTower_2F_EventScript_Teacher2::
	msgbox GoldenrodCity_RadioTower_2F_Text_TeacherRockets, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_RadioTower_2F_EventScript_Jigglypuff::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_JIGGLYPUFF, CRY_MODE_NORMAL
	msgbox GoldenrodCity_RadioTower_2F_Text_Jigglypuff, MSGBOX_DEFAULT
	waitmoncry
	release
	end

RadioTower2FBuenaPasswordIsHelpText:
	.string "BUENA: Huh? Today's password?\n"
	.string "HELP, of course!$"

GoldenrodCity_RadioTower_2F_Text_SuperNerd:
	.string "You can listen to the radio\n"
	.string "anywhere. Tune in!$"

GoldenrodCity_RadioTower_2F_Text_Policeman:
	.string "Restricted access beyond this\n"
	.string "point.$"

GoldenrodCity_RadioTower_2F_Text_Teacher:
	.string "Lullabies on the radio may make\n"
	.string "POKéMON sleep.$"

GoldenrodCity_RadioTower_2F_Text_TeacherRockets:
	.string "Why would they want to take over\n"
	.string "the RADIO TOWER?$"

GoldenrodCity_RadioTower_2F_Text_Jigglypuff:
	.string "JIGGLYPUFF: Jiggly…$"

GoldenrodCity_RadioTower_2F_Text_BlackBelt1:
	.string "Sorry. Authorized personnel only\n"
	.string "beyond this point.\p"
	.string "It wasn't that way before.\p"
	.string "There's something wrong with the\n"
	.string "DIRECTOR…$"

GoldenrodCity_RadioTower_2F_Text_BlackBelt2:
	.string "Feel free to look around anywhere.\p"
	.string "The DIRECTOR is nice again, just\n"
	.string "as he was before.$"

GoldenrodCity_RadioTower_2F_Text_GruntM4Seen:
	.string "Three years ago, TEAM ROCKET was\n"
	.string "forced to disband.\p"
	.string "But we're making a comeback here!$"

GoldenrodCity_RadioTower_2F_Text_GruntM4Beaten:
	.string "Gwah! Don't get cute!$"

GoldenrodCity_RadioTower_2F_Text_GruntM4After:
	.string "We won't let you ruin our plans\n"
	.string "for our comeback!$"

GoldenrodCity_RadioTower_2F_Text_GruntM5Seen:
	.string "We're TEAM ROCKET, the exploiters\n"
	.string "of POKéMON!\p"
	.string "We love being evil! Scared?$"

GoldenrodCity_RadioTower_2F_Text_GruntM5Beaten:
	.string "You think you're a hero?$"

GoldenrodCity_RadioTower_2F_Text_GruntM5After:
	.string "We're not always evil. We just do\n"
	.string "whatever we like.$"

GoldenrodCity_RadioTower_2F_Text_GruntM6Seen:
	.string "Hey, hey! Keep out of our way!$"

GoldenrodCity_RadioTower_2F_Text_GruntM6Beaten:
	.string "Arggh. I give up.$"

GoldenrodCity_RadioTower_2F_Text_GruntM6After:
	.string "Our EXECUTIVES are trying to take\n"
	.string "this place over.\p"
	.string "They have some big plan. I wonder\n"
	.string "what that is?$"

GoldenrodCity_RadioTower_2F_Text_GruntF2Seen:
	.string "Hahaha!\p"
	.string "How boring. It was far too easy\n"
	.string "to take over this place!\p"
	.string "Come on, keep me amused!$"

GoldenrodCity_RadioTower_2F_Text_GruntF2Beaten:
	.string "Wh-who are you?$"

GoldenrodCity_RadioTower_2F_Text_GruntF2After:
	.string "You beat me, and I won't forget\n"
	.string "it!$"

GoldenrodCity_RadioTower_2F_Text_BuenaShowPromo:
	.string "BUENA: Tune in to my PASSWORD\n"
	.string "SHOW!$"

GoldenrodCity_RadioTower_2F_Text_SalesSign:
	.string "2F SALES$"

GoldenrodCity_RadioTower_2F_Text_OakTalkSign:
	.string "PROF.OAK'S POKéMON TALK\p"
	.string "The Hottest Show on the Air!$"

GoldenrodCity_RadioTower_2F_Text_PokemonRadioSign:
	.string "Anywhere, Anytime POKéMON Radio$"
